# Next-session prompt: Function-Dispatch Consolidation — pass (b) remainder

> **Resumption note (2026-07-17):** state re-verified after the AVM2 detour.
> Zero commits have touched `SWFModernRuntime/src/actionmodern/` or
> `include/actionmodern/` since this work parked on 2026-07-11 (the AVM2 work
> lives in `src/avm2/`) — no drift. `check_dispatch_funnel.py` re-run:
> GATE-GREEN. Local toolchain smoke-tested: `regression/onunload_type1_args`
> passes via `verify_output.py --tests-dir=ruffle-tests/tests/swfs/regression`.
> The plan header now reflects Stages 0–5 core COMPLETE; everything below is
> current.

`SWFRecompDocs/prompts/dispatch-consolidation-stage4.md` — read it and follow it
end-to-end; the plan it references
(`SWFRecompDocs/plans/function-dispatch-consolidation-plan.md`) is the source of
truth for the survey, the staged design, ALL landing notes (Stages 1–5 + the
pass-(b) fourth-session note at the end of §4), the verification protocol, and
the risks.

Session start, in order:

1. Read `CLAUDE.md` (build commands, the "never run full suites locally" rule, the
   autonomous git/CI authorization, the accepted-diffs doc policy).
2. Read `ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md` and
   `ruffle-tests/tests/swfs/avm1/_investigation/CURRENT_STATUS.md`.
3. Read the plan §4's Stage-4 landing notes AND the "Normalization pass (b) +
   Stage 5 landing notes (2026-07-11)" block — the most recent corrections.
4. Read the remaining per-item dossier bullets in
   `SWFRecompDocs/plans/dispatch-stage4-dossiers.md` (grep "Normalization
   pass (b) master list", items 5–7 only — items 1–4 are DONE).
5. Run: `bash ruffle-tests/download_tests.sh avm1 from_shumway from_gnash`
6. Run: `python3 tools/divergence/gates/check_dispatch_funnel.py` (must be
   GATE-GREEN before and after every commit).

## Where things stand

**Stages 0–5 core work is COMPLETE.** Every surveyed dispatcher funnels through
`invokeFunctionValue`; pass (b)'s four high-value items landed 2026-07-11
(fourth session, 12 commits, CI green both modes per batch, zero unexplained
pass→fail; the one CI flip — `mcl_replace_root_swf7_to_swf5` — was diagnosed
and fixed same-session via the v5 no-closure gate):

1. **switchToFunctionVersion everywhere** (7 dispatcher families, 7 fail-before
   `*_cross_swf_version` repros). Handlers/listeners/callbacks/coercion
   methods run at their DEFINING movie's SWF version, with the caller-gated
   base-clip bracket replacing every `INV_BASE_CLIP` that would have paired
   with `INV_VERSION_SWITCH`. Plus the **v5 no-closure gate** in the core:
   a v5 CALLER runs the callee at the `this`-clip's CURRENT version, not the
   defining one (Ruffle function.rs `is_closure`); `switchToFunctionVersion`
   itself stays unconditional for the in-arm rituals (`swf5_to_6_cross_call`
   pins that).
2. **The scope-order flip**: `INV_LOCAL_SCOPE_UNDER_CAPTURED` is DELETED (all
   seven users normalized; locals are the innermost scope). Lock flips:
   `resolve_type1_args` "h a=one", `ei_closure_scope_order` "shadow a=ARG".
3. **Caller-gate unification**: the MC arms, timer function form, and
   enterFrame children arm gate on the CALLER's version; new
   `CF_VERSION_RECEIVER` ClosureFrame mode for v5 callers
   (`regression/mc_method_v5_caller_gate`).
4. **Depth guards**: coercion recursion (new core `INV_SPECIAL_GUARD`, cap 66,
   HALT — Ruffle Special semantics; `regression/coerce_recursion_guard`) and
   watch Site A/C re-fire (Site B's ritual; `regression/watch_timeline_reentrant`).
   Broadcaster re-broadcast: documented NO (already halts via g_max_call_depth).

**Stage 5's funnel gate is LIVE**: `tools/divergence/gates/check_dispatch_funnel.py`
(raw-dispatch allowlist / no `INV_BASE_CLIP|INV_VERSION_SWITCH` pairing / the
deleted flag stays deleted). Keep it green; extend the allowlist only with a
design justification in the same commit.

**41 standing regression guards** (`ruffle-tests/tests/swfs/regression/`,
README documents each). The two-SWF cross-version test pattern is established:
v7 host + v6 child, handoff via `_level0.cb` (NOT `_global` — per-version
groups), `loadMovie` into a host-created holder, fire on frame 4.

## Your task: the pass-(b) remainder, value-over-effort

Each "yes" is its own commit with a test that FLIPS; each "no" is documented in
the plan. All remaining items are LOWER value than what has landed — apply
judgement about whether each is worth its risk:

1. **Root-enterFrame + root-var-map arms' missing version switch** (session-4
   discovery, same proven class as item 1). Repro: v6 child publishes a
   handler; host assigns `_root.onEnterFrame`; needs a self-removing handler
   for determinism.
2. **The onUnload t1 local frame** (master-list item 5): the path pushes NO
   local frame, so a param'd handler's prologue binds leak ambiently
   (`onunload_type1_args`'s docstring documents it). Add `INV_LOCAL_SCOPE`
   for t1; test = an onUnload handler whose param name collides with a global.
3. **The sound family** (item 6): exec-func + arguments for t2 (XML handlers'
   `arguments` are broken today — dossier claim, verify with a probe first),
   this-stack; its scope-order already normalized.
4. **Smaller queue** (item 7): watch D1 (return fold) / D6 (userData) / D8
   (old-value source); `convertFloat`'s missing t1 this push; sort-comparator
   captured scopes for t2; LV grandparent-caller; `g_event_this_mc` for the
   MC arms' t1 branch.
5. **`lv_url_encode` migration** (would empty `invokeSpecialFunction` and
   shrink the funnel-gate allowlist by two entries).

## Hard-won test-building traps (do not rediscover these)

- **verify_output.py must run from the repo root** — running it from inside a
  test dir mangles the relative path. Watch for `cd` persisting across shell
  commands.
- **Local suite runs dirty the CI-owned `_results/` files** — `git checkout --`
  them before committing; never `git add` them.
- **Cross-movie identity bugs (pre-existing, documented, NOT yours to fix
  unless targeted)**: a loaded child's `this` MC ≠ the host's holder wrapper
  (dynamic_props invisible cross-side); a root TextField created BEFORE
  loadMovie becomes unresolvable by name after it; the host's
  `MovieClip.prototype` ≠ the prototype wired into new clips once a child
  movie is loaded (use `m0.__proto__`); hand-assembled DefineSprite
  attachMovie doesn't instantiate in the child-movie environment (onLoad has
  no buildable cross-version trigger).
- **A v5 host** has no `createEmptyMovieClip`, and a dot-path loadMovie target
  ("_level0.holder") silently falls back to ROOT REPLACEMENT — use
  `loadMovieNum`-style `_level1` targets.
- **ExternalInterface is version-hidden below SWF8** (ASSetPropFlags unhides
  `flash` but not EI's methods) — EI cross-version tests invert polarity
  (v8 movie + harness-injected older ambient).
- **The undefined-coercion discriminator is v6/v7**, not v5/v6 (`"" + u` is
  `""` at ≤6, `"undefined"` at ≥7).
- Mid-script dispatchers (coercion, watch, onConstruct, onUnload,
  broadcastMessage) are where marshalling repros live; between-frames
  dispatchers only yield locks. Settle reachability with a file-writing probe.

## Guardrails (unchanged, plus one)

- Behavior-preserving vs normalizing stays two commits; fail-before verified
  by running against the parent commit's `action.c` (copy aside + `git show
  HEAD:...`, run, restore).
- One dispatcher (or one coherent family) per commit; full CI in **both**
  modes per batch via `.claude/pipeline-handoff.md`; zero unexplained
  pass→fail; deliberate lock flips listed in the commit message.
- NEVER set `INV_BASE_CLIP` and `INV_VERSION_SWITCH` together (the gate
  enforces it). NEVER resurrect `INV_LOCAL_SCOPE_UNDER_CAPTURED` (ditto).
- `INV_ACT_THIS` requires `INV_LOCAL_SCOPE`; `INV_ACT_ARGUMENTS` requires
  core-owned `INV_EXEC_FUNC`.
- Line numbers in all docs go stale — grep the symbol.
- A concurrent AVM2 workstream lands on the same master: `git status` before
  committing, stage YOUR files by name, expect their uncommitted avm2/abc
  files in the tree (they block `git pull --rebase` — check
  `git rev-list origin/master..master` and plain-push when the remote hasn't
  moved).

## Reading CI

`results_diff.md` line metrics compare POSITIONALLY — reproduce and diff actual
outputs before concluding anything from them. `ruffle_matched` is byte-exact vs
`output.ruffle.txt`, so a preserved ruffle_matched status = output unchanged.
The graphics mode intermittently loses a shard to apt-get flakiness — infra,
re-dispatch.

## CI baseline to hold (raw `pass`, both modes, @ `a77fa3f42` batch, 2026-07-11)

| Suite | no-graphics | graphics |
|---|---|---|
| avm1 | 634/706 | 634/706 |
| **regression** | **41/41** | **41/41** |
| from_shumway | 73/92 | 73/92 |
| from_shumway/avm1 | 46/47 | 46/47 |
| from_gnash/actionscript.all | 135/243 | 135/243 |
| from_gnash/misc-ming.all | 69/111 | 68/111 |
| from_gnash/misc-swfmill.all | 19/20 | 19/20 |
| from_gnash/misc-mtasc.all | 7/9 | 7/9 |
| from_gnash/misc-swfc.all | 11/20 | 11/20 |

(Confirm the 41/41 row against the batch-4 CI run before relying on it — it
was dispatched at the end of the fourth session; earlier batches all held
these numbers.) `results.json`'s `effective_pass` includes `ruffle_matched`
and reads higher; compare like with like.

## Known reds — do NOT chase

`watch_virtual_property`, `string_relational_compare` (avm1);
`watch{,_special}_recursion{,_double}_swf7` (upstream, byte-diff-verified
untouched by the guards work — the swf7 recursion depths are unmatchable
recursively); `delete-v5..v8` / `delete2`; gnash `argstest-v6/v7/v8`;
`mixed-bytecode-as2` flips = check the AVM2 emitter first.

## Perf

Settled — see the previous prompt revision's Perf section and plan §5. Don't
re-litigate without a workload stressing a migrated branch.
