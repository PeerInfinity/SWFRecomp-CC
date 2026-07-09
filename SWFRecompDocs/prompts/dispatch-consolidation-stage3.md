# Next-session prompt: Function-Dispatch Consolidation, Stage 3 (continued)

## Where things stand

Stages 0–2 landed earlier. **Stage 3 is in progress: 5 of `actionCallMethod`'s
~19 arms are migrated**, each CI-green in both modes with every suite's delta at 0.

| Stage | Commit | What |
|---|---|---|
| 0 | `d8abc5c0a`, `9a8c6dce3`, `60070d96a` | 3 real bugs fixed; 4 permanent tests |
| 1 | `c23831e4b` | `invokeFunctionValue()` core + `InvokeOpts`; `invokeResolveFunction` wired |
| 2 | `7b47771ae` | `invokePropertyGetter` + `invokePropertySetter` wired (−181 lines) |
| **3a** | `e4082f224` | `actionCallMethod`'s **four super arms** |
| **3b** | `65d442f09` | the `.call`/`.apply`-via-`GetMember` arm **+ a real TYPE1_ARG_ORDER bug fixed** |

Support commits: `c8447e024` (hand-written tests moved out of the downloaded
`avm1/` mirror into a new `regression/` suite), `4d58c45c6` (`--test=NAME` now
resolves across suites), `dddbda561` (plan progress note).

## Read first

1. **`SWFRecompDocs/plans/function-dispatch-consolidation-plan.md`** — authoritative.
   §3 (**"today's inconsistencies are load-bearing"**), §4's **Stage 3 progress
   note** (what landed, what the remaining arms need, the perf finding), §5, §6.
2. `CLAUDE.md` — build commands, the **"never run full suites locally"** rule, the
   autonomous git/CI authorization, the accepted-diffs doc policy.
3. Memory `dispatch-stage1-core`, `dispatch-stage0-verdicts`,
   `profile-game-native-n-is-noisy`, `custom-tests-live-in-regression-suite`.

## The next move is a DESIGN step, not another arm

The remaining ~14 arms do **not** need new flags — they need the core to learn
three capabilities it has no notion of. Grinding them one at a time without this
will calcify the wrong abstraction into 14 call sites.

1. **`arguments`-object construction** + `setupArgumentsProps`, honoring the
   DefineFunction2 preload/suppress flags. Needed by the `.call`/`.apply`
   handlers (`~65652`, `~66056`) and the object-method arm (`~64628`).
2. **The closure-context switch**: save/clear/restore the *whole* scope chain
   (`scope_depth = 0`), `reResolveDeadBaseClip` + `actionSetCurrentContext` +
   `g_current_sprite_obj`, gated on `caller_ver >= 6`.
3. **`pushCtorContext`/`popCtorContext`**, `g_override_this` /
   `g_override_this_set`, `g_c_function_this_obj`, and binding `"super"` as a
   named local on the local scope.

Capability 2+3 together are the **`actionCallFunction` shape**, and
`actionCallMethod`'s empty-method-name arm (`~64044`–`64199`) reproduces it
verbatim. Strong hint: **design against `actionCallFunction` first and let that
arm fall out**, rather than starting from `actionCallMethod` again.

## Rules (guardrails, not suggestions)

- **One arm (or one small coherent group) per commit.** Full CI **both modes**
  per batch. That granularity is what makes a bad migration bisectable.
- **Behavior-preserving by default.** Normalization is Stage 4.
- **Diff each arm's actual ritual against the core; don't assume it matches.**
  Stage 3a/3b needed no new flags only because three steps were deliberately
  left *outside* the core — copy that judgement:
  - `setVariableByName("this", ...)` — those arms bind `this` into the
    **enclosing** scope, not a fresh local frame.
  - the bare `g_call_depth++/--` — `INV_DEPTH_GUARD` also adds a
    `g_max_call_depth` halt check the arms never had.
  - `g_current_executing_func` / `g_call_this_type` — `INV_EXEC_FUNC` *also*
    writes `g_prev_executing_func`.
- **Preserve pointer-identity thunk checks before calling the core**
  (`builtin_stub_method`, `builtin_noop_func`, `builtin_array_method`) — they are
  dispatch decisions, not invocation steps.
- Two facts already audited, reuse them: `param_count` is accurate for every
  type-1 reachable from `actionCallMethod` (recompiled `DefineFunction` pops
  exactly `param_count`; the only 5 natives with a real `simple_func` are
  `toString`-shaped, `param_count = 0`). And a recompiled `DefineFunction2`
  **never reads** its `registers` parameter (its body declares a local `regs[]`),
  so `HCALLOC(register_count)`-or-NULL is safe.

## Validation

- **Prereq:** `bash ruffle-tests/download_tests.sh avm1 from_shumway from_gnash`.
- **Local, individual tests only.** `--test` is repeatable and now resolves across
  suites — pass the whole cluster in ONE invocation so it builds once. A serial
  loop recompiles (~45 s/test) and times out.
  ```bash
  python3 ruffle-tests/verify_output.py -v --test=as2_super_and_this_v8 --test=super_edge_cases ...
  ```
- Sensitive clusters: `as2_super_and_this_*`, `super_edge_cases`, `extends_chain`,
  `register_and_init_order`, `swf5_no_closure`, `swf5_to_6_cross_call`,
  `call`, `funky_function_calls`. Standing guards (now in the `regression` suite,
  still findable by bare name): `ei_type1_args`, `mc_event_type1_args`,
  `timer_cross_swf_version`, `nc_onstatus_closure`, `fn_call_type1_args`.
- **CI is the real coverage.** Autonomous commit/push/CI is authorized — follow
  `.claude/pipeline-handoff.md`, run **both** modes, merge `ruffle-test-results`,
  report pass→fail regressions **by name**. Zero pass→fail is the bar.
- **Perf: do NOT profile this on N.** N never executes `invokeFunctionValue`
  (100% type-1 functions, zero `DefineFunction2`, reaches none of the arms), and
  `profile_game_native.sh` swings ~13% run-to-run on N with the *identical
  binary*. Use **Minesweeper** and read the core's own `Ir` line from
  `callgrind_annotate --threshold=100 --auto=no callgrind.out` instead of
  comparing PROGRAM TOTALS. Baseline: 12,117 / 641,978,548 = 0.0019%.

## CI baseline to hold (both modes, 2026-07-09 @ `4d58c45c6`)

| Suite | no-graphics | graphics |
|---|---|---|
| avm1 | 634/706 | 634/706 |
| **regression** | **5/5** | **5/5** |
| from_shumway | 73/92 | 73/92 |
| from_shumway/avm1 | 46/47 | 46/47 |
| from_gnash/actionscript.all | 135/243 | 135/243 |
| from_gnash/misc-ming.all | 69/111 | 68/111 |
| from_gnash/misc-swfmill.all | 19/20 | 19/20 |
| from_gnash/misc-mtasc.all | 7/9 | 7/9 |
| from_gnash/misc-swfc.all | 11/20 | 11/20 |

## Known reds — do NOT chase, they are not yours

- `watch_virtual_property` (avm1) — pre-existing `output_mismatch`.
- `delete-v5..v8` / `delete2` — upstream fixture drift (a missing
  primitive-coercion warning line from an updated `delete.as`).

## Also open (independent of the above; Stage-4 scope)

Two more reverse-order type-1 arg pushes of the same bug class, found while
migrating 3b and **not yet verified as reachable**:
- `lc_dispatch_method` (`action.c:2908`) — LocalConnection method dispatch.
- `bdRectangleGetter` (`action.c:14365`) — pushes four fixed `Rectangle` ctor
  args in reverse. Check whether that constructor is ever type-1 before assuming
  it is live.

Both also skip the `param_count` clamp/pad. Verify reachability with a repro
first (Stage-0 method: hand-assembled SWF via `create_test_swf.py`, since MTASC
emits `DefineFunction2` for SWF6+); new tests go in
`ruffle-tests/tests/swfs/regression/`.

## Out of scope

Stage 4 (event/callback dispatchers + the deliberate normalization pass) and
Stage 5 (delete the dead marshalling loops, add `gates/check_dispatch_funnel.py`).
Stage-4 leads are recorded in the plan §4 and in memory `dispatch-stage0-verdicts`
— add to them, don't act on them.
