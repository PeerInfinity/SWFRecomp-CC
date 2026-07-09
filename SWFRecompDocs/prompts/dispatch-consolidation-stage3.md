# Next-session prompt: Function-Dispatch Consolidation, Stage 3

## Goal

Migrate the **mega-dispatchers** onto the unified `invokeFunctionValue()` core:
`actionCallMethod`'s ~14 inline arms, then `actionCallFunction`, `actionNewObject`,
`actionNewMethod`, `invokeNativeSuperConstructor`. **Behavior-preserving by
default** — each arm passes the `InvokeOpts` flag subset that mirrors its *current*
ritual. Normalization (turning a skipped step on) is a separate, per-site, CI-gated
decision with its own test, and belongs to Stage 4, not here.

## Read first

1. **`SWFRecompDocs/plans/function-dispatch-consolidation-plan.md`** — authoritative.
   §2 (survey), §3 (**"today's inconsistencies are load-bearing"** — the critical
   constraint), §4 Stage 3 rules, §5 verification protocol, §6 risks. The Stage 1
   and Stage 2 landing notes in §4 document the core's flag semantics and the two
   normalizations it bakes in.
2. `CLAUDE.md` — build commands, the **"never run full suites locally"** rule, the
   autonomous git/CI authorization, and the accepted-diffs doc policy.
3. Memory `dispatch-stage1-core` (core + flags + baseline) and
   `dispatch-stage0-verdicts` (the bug class, and the Stage-4 leads).

## Where things stand

Stages 0–2 are landed and CI-green in both modes:

| Stage | Commit | What |
|---|---|---|
| 0 | `d8abc5c0a`, `9a8c6dce3`, `60070d96a` | 3 real bugs fixed; 4 permanent tests |
| 1 | `c23831e4b` | `invokeFunctionValue()` core + `InvokeOpts`; `invokeResolveFunction` wired |
| 2 | `7b47771ae` | `invokePropertyGetter` + `invokePropertySetter` wired (−181 lines) |

**The core** lives in `action.c`: forward-declared beside `invokePropertyGetter`,
**defined** just after the `actionRestoreFunctionVersion` wrappers (so
`switchToFunctionVersion` / `pushSuperContext` / `allocObject` / `pushVar` are in
scope). It holds the single type-1 cast, the single forward-order + pad-to-
`param_count` marshalling loop, type-2 register setup, NULL-stub handling, and
symmetric teardown.

```c
ActionVar invokeFunctionValue(SWFAppContext*, ASFunction* func, ActionVar* this_var,
                              ActionVar* args, u32 num_args, const InvokeOpts* opts);
```

Flags: `INV_DEPTH_GUARD / THIS_STACK / SUPER_CTX / CAPTURED_SCOPE / LOCAL_SCOPE /
BIND_THIS / BASE_CLIP / VERSION_SWITCH / EVENT_THIS_MC / EXEC_FUNC /
LOCAL_SCOPE_MC / RESET_THIS_DEPTH`, plus opt-in legacy-quirk flags
`INV_FORCE_CAPTURED_WITH` and `INV_MC_THIS_NULL_PTR`. `opts == NULL` = the
"everything reasonable on" superset. `super_depth` applies under `INV_SUPER_CTX`.

Roughly **127 raw invocation points remain** (~62 `simple_func` casts, ~65
`advanced_func` calls) across ~35 dispatchers — re-derive the counts, don't trust
these.

## Decide this first (it's a sequencing call, not a coding one)

The plan's §6 risk table says to **coordinate Stage 3 with the string-id-interning
plan's Stage 2**, because both touch `actionCallMethod`-adjacent paths. Confirm
with the user which goes first before editing `actionCallMethod`. Stages 0–2 were
deliberately disjoint from interning; Stage 3 is not.

## Stage 3 targets (line numbers @ `8413d6d2b`; they drift)

| Site | action.c | Note |
|---|---|---|
| `actionCallMethod` | 63486 | ~14 inline arms: object / MC / super / array-proxy / `__resolve` / user-dispatch. **Start here, one arm per commit.** |
| `actionCallFunction` | 57832 | |
| `actionNewObject` | 53031 | |
| `actionNewMethod` | 54586 | |
| `invokeNativeSuperConstructor` | 818 (decl), 57205 (def) | super arms carry `INV_SUPER_CTX` + explicit depth |

## Rules (from the plan — these are the guardrails, not suggestions)

- **One arm (or one small coherent group) per commit.** Full CI **both modes** per
  batch. That granularity is what makes a bad migration bisectable.
- **Preserve pointer-identity special cases by checking BEFORE calling the core.**
  They are *dispatch decisions*, not invocation steps. The by-address thunk
  comparisons (`builtin_stub_method`, `builtin_noop_func`, `builtin_array_method`)
  live at `action.c:14848, 64539, 65170, 65462, 65803` — leave them in front.
- **Super arms** pass `INV_SUPER_CTX` + an explicit `super_depth`. This centralizes
  the depth formulas' *application*, not their computation — don't move the
  formulas.
- **Diff each arm's actual ritual against the core; don't assume it matches.** That
  diffing is exactly what surfaced the two flags Stage 2 needed
  (`INV_RESET_THIS_DEPTH`, `INV_LOCAL_SCOPE_MC`). Expect Stage 3 to need more.
- The core normalizes two details that are inert **only** where the local scope
  holds just `"this"` and no captured WITH-scope can shadow a bound name:
  (1) captured-before-local scope order, (2) type-1 arg pad to `param_count`. For
  an arm where either could matter, add a flag and reproduce the exact behavior.

## Validation

- **Prereq:** `bash ruffle-tests/download_tests.sh avm1 from_shumway from_gnash` so
  local matches CI (CI re-downloads upstream fixtures every run; a stale local tree
  produces phantom regressions).
- **Local, individual tests only.** `verify_output.py --test` is **repeatable** —
  pass the whole cluster in ONE invocation so it builds once. A serial `for` loop
  recompiles (~45 s/test) and will time out:
  ```bash
  python3 ruffle-tests/verify_output.py -v --test=as2_super_and_this --test=super_edge_cases ...
  ```
- Stage 3's sensitive clusters (per the plan): `as2_super_and_this_*`,
  `super_edge_cases`, `extends_chain`, `register_and_init_order`, `swf5_no_closure`,
  `swf5_to_6_cross_call`. Add the four Stage-0 permanent tests as a standing guard:
  `ei_type1_args`, `mc_event_type1_args`, `timer_cross_swf_version`,
  `nc_onstatus_closure`.
- **CI is the real coverage.** Autonomous commit/push/CI is authorized — follow
  `.claude/pipeline-handoff.md`, run **both** `no-graphics` and `graphics` (shared
  runtime code), merge `ruffle-test-results`, and report pass→fail regressions **by
  name**. Zero pass→fail is the bar for a behavior-preserving stage.
- **Perf sanity:** the core adds a call frame + flag checks on hot call paths. Run
  `SWFRecomp/scripts/profile_game_native.sh` on N before/after Stage 3. Expect
  noise-level; if not, make the core `static inline` / `always_inline`.

## CI baseline to hold (both modes, 2026-07-08 @ `7b47771ae`)

| Suite | no-graphics | graphics |
|---|---|---|
| avm1 | 638/710 | 638/710 |
| from_shumway | 73/92 | 73/92 |
| from_shumway/avm1 | 46/47 | 46/47 |
| from_gnash/actionscript.all | 135/243 | 135/243 |
| from_gnash/misc-ming.all | 69/111 | 68/111 |
| from_gnash/misc-swfmill.all | 19/20 | 19/20 |
| from_gnash/misc-mtasc.all | 7/9 | 7/9 |
| from_gnash/misc-swfc.all | 11/20 | 11/20 |

## Known reds — do NOT chase, they are not yours

- `watch_virtual_property` (avm1) — pre-existing `output_mismatch`, red since
  before Stage 1.
- `delete-v5..v8` / `delete2` — a missing primitive-coercion warning line from an
  upstream `delete.as` update. Separate `delete`-opcode fix; tracked in the
  bounds-engine plan's baseline note.

## Out of scope

- Stage 4 (event/callback dispatchers + the deliberate normalization pass) and
  Stage 5 (delete the dead marshalling loops, add the `gates/check_dispatch_funnel.py`
  gate). Stage 3's known Stage-4 leads are already recorded in the plan §4 and in
  memory `dispatch-stage0-verdicts` — add to them, don't act on them.
