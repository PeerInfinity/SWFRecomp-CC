# Next-session prompt: Function-Dispatch Consolidation, Stage 3 (continued)

## Where things stand

Stages 0–2 landed earlier. **Stage 3 is well past half: 8 of `actionCallMethod`'s
~19 arms are migrated, plus the whole of `actionCallFunction`.** Every step below
was CI-green in **both** modes with zero pass→fail.

| Stage | Commit | What |
|---|---|---|
| 0 | `d8abc5c0a`, `9a8c6dce3`, `60070d96a` | 3 real bugs fixed; 4 permanent tests |
| 1 | `c23831e4b` | `invokeFunctionValue()` core + `InvokeOpts`; `invokeResolveFunction` wired |
| 2 | `7b47771ae` | `invokePropertyGetter` + `invokePropertySetter` wired (−181 lines) |
| 3a | `e4082f224` | `actionCallMethod`'s **four super arms** |
| 3b | `65d442f09` | the `.call`/`.apply`-via-`GetMember` arm **+ a real TYPE1_ARG_ORDER bug** |
| **3c/1** | `ee9132778` | **design** + `actionCallFunction`, both branches |
| **3c/2** | `e31237992` | the **empty-method-name** arm **+ 2 real bugs** |
| **3c/3** | `a2cd5228b` | the **two object-method arms, merged into one** (−99 lines) **+ a real bug** |
| — | `7ff10e157` | why step 3's `argstest` line-count drop is the fix, not a regression |

## Read first

1. **`SWFRecompDocs/plans/function-dispatch-consolidation-plan.md`** — authoritative.
   §3 (**"today's inconsistencies are load-bearing"**), then §4's **Stage 3c design
   note** (the chosen shape + the per-type `act_flags` rule table) and the three
   **Stage 3c landing notes**.
2. `CLAUDE.md` — build commands, the **"never run full suites locally"** rule, the
   autonomous git/CI authorization, the accepted-diffs doc policy.
3. Memory `dispatch-stage3c-closureframe`, `dispatch-stage1-core`,
   `results-diff-line-metrics-mislead`, `profile-game-native-n-is-noisy`,
   `custom-tests-live-in-regression-suite`.

## The design (already made — don't re-litigate it, extend it)

Three capabilities live in three places, split by *what data each needs*:

1. **`arguments` / `this` / `super` named locals → INSIDE the core**, as
   `opts->act_flags` (`INV_ACT_THIS | INV_ACT_ARGUMENTS | INV_ACT_SUPER`). They
   need `local_scope`, which only the core owns. Each bit means something
   different per `function_type`; the rule table is beside `InvokeOpts`.
2. **The closure-context switch → BESIDE the core**, as `ClosureFrame` +
   `enterClosureFrame`/`leaveClosureFrame`, storage on the *dispatching arm's* C
   stack. Flags `CF_RESET_SCOPE | CF_VERSION | CF_CTX | CF_CTX_LIVE`. Arm-owned
   because the frame is ~544 B and `g_max_call_depth` is 256 — in the core it
   would add ~139 KB of C stack to every accessor call, against a 64 KB
   emscripten stack.
3. **Ctor context → SPLIT.** `pushCtorContext`/`g_override_this` straddle the
   callee body → in (`INV_CTOR_CTX`, `opts->override_this`).
   `g_c_function_this_obj` / `g_call_this_type` are read only from inside builtin
   bodies → out.

Two hazards the design routes around, both live traps for a new arm:

- `INV_BASE_CLIP` tests `g_swf_version` **after** `INV_VERSION_SWITCH` installs
  the callee's version. **Never set both.** Use a `ClosureFrame`: it does
  `CF_VERSION` before `CF_CTX` (required — `reResolveDeadBaseClip` →
  `resolveSlashPathToMC` reads `g_swf_version`/`global_object`) and takes the
  caller-version gate in the flags the arm computes before entering.
- `arguments.caller` comes from `setupArgumentsProps`' `caller_func`. **An arm
  that wants `INV_ACT_ARGUMENTS` must let the core own `INV_EXEC_FUNC`** — if the
  arm swaps `g_current_executing_func` itself (as 3b's `.call` arm does), every
  function becomes its own caller.

## What's next

4. **The `.call`/`.apply` builtin handlers** (`~65550`–`65740`). They force
   `is_with = 1` on captured scopes → `INV_FORCE_CAPTURED_WITH`. `INV_ACT_ARGUMENTS`
   on the **type-1 branch only** — the type-2 branch builds no `arguments` object
   today. Note 3b already migrated the *GetMember* shortcut arm; these are the
   builtin `Function.prototype.call`/`apply` bodies, a different site.
5. Then the `__resolve` arm, the array arm, the string-primitive arm, the MC arm.
6. Then Stage 4 (event/callback dispatchers + the deliberate normalization pass)
   and Stage 5 (`gates/check_dispatch_funnel.py`).

**One predicted bug left in Stage 3's scope**, unverified: the `.call`/`.apply`
type-1 handler (`~65659`) pads to `param_count` but never **clamps**, so extra
args leak onto the caller's eval stack. Three sibling predictions from the same
survey all turned out real (3b, step 2, step 3) — but verify with a repro before
fixing, per Stage 0's method.

## Rules (guardrails, not suggestions)

- **One arm (or one small coherent group) per commit.** Full CI **both modes** per
  batch. That granularity is what makes a bad migration bisectable.
- **Behavior-preserving by default.** Normalization is Stage 4.
- **Diff each arm's actual ritual against the core; don't assume it matches.** The
  empty-method-name arm's override-`this` protocol is the standing proof: it sets
  `g_override_this_set = 1` then clears it again *before* the call when
  `register_count == 0`, so `INV_OVERRIDE_THIS` (which sets unconditionally and
  clears *after*) does **not** reproduce it. Steps that stay outside the core:
  `setVariableByName("this",...)`, the bare `g_call_depth++/--`,
  `g_c_function_this_obj`, `g_call_this_type`, and dispatch decisions like
  `actionCallFunction`'s `simple_func == NULL` converter branch.
- **Preserve pointer-identity thunk checks before the core** (`builtin_stub_method`,
  `builtin_noop_func`, `builtin_array_method`) — dispatch decisions, not steps.
- Two audited facts, reuse them: `param_count` is accurate for every type-1
  reachable from these arms, and a recompiled `DefineFunction2` **never reads** its
  `registers` parameter, so `HCALLOC(register_count)`-or-NULL is safe.

## Validation

- **Prereq:** `bash ruffle-tests/download_tests.sh avm1 from_shumway from_gnash`.
- **Local, individual tests only.** `--test` is repeatable and resolves across
  suites, but **all names must resolve to ONE suite** — pass `--tests-dir` to
  disambiguate. Pass the whole cluster in ONE invocation so it builds once; a
  serial loop recompiles (~45 s/test) and times out.
- Sensitive clusters: `as2_super_and_this_*`, `super_edge_cases`, `extends_chain`,
  `register_and_init_order`, `swf5_no_closure`, `swf5_to_6_cross_call`, `call`,
  `funky_function_calls`, `arguments`, `register_class`, `extends_native_type`.
  Standing guards in `regression/` (findable by bare name): `ei_type1_args`,
  `mc_event_type1_args`, `timer_cross_swf_version`, `nc_onstatus_closure`,
  `fn_call_type1_args`, `fn_empty_method_type1_args`, `method_type1_args`.
- **A new regression test must be verified to FAIL without the fix.** Copy the
  parent commit's `action.c` over the working copy, run the test, restore. A test
  that passes both ways is worthless. All three type-1 tests above were checked
  this way.
- Don't `git add` `ruffle-tests/tests/swfs/*/_results/` — a local suite run dirties
  those CI-owned files.
- **CI is the real coverage.** Autonomous commit/push/CI is authorized — follow
  `.claude/pipeline-handoff.md`, run **both** modes, merge `ruffle-test-results`,
  report pass→fail regressions **by name**. Zero pass→fail is the bar.
- **`results_diff.md` line metrics can move the WRONG way** when a fix lands on an
  already-failing test (positional compare; a shrinking output breaks alignment).
  Step 3 showed `argstest-v7` at `67 → 50` matching lines while *deleting 1,630
  lines of corruption*. On a "Line Count Changed" row for a test that was already
  failing: reproduce both sides and diff the **actual outputs**. See memory
  `results-diff-line-metrics-mislead`.
- **Perf: neither N nor Minesweeper is an oracle for the new arms.** N never
  executes the core and swings ~13% run-to-run. Minesweeper never executes
  `actionCallFunction` at all. Doodle Jump reaches it (0.23% of Ir) but the core's
  self cost there is 239 Ir. Measured verdict: the core is free (≤0.0014% of total
  everywhere), no `static inline` warranted. Don't re-litigate without a workload
  that actually stresses the migrated branch.

## CI baseline to hold (both modes, 2026-07-09 @ `7ff10e157`)

| Suite | no-graphics | graphics |
|---|---|---|
| avm1 | 634/706 | 634/706 |
| **regression** | **7/7** | **7/7** |
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
- `argstest-v6/v7/v8` (gnash) — `output_mismatch` long before this work; step 3
  made them *less* wrong while lowering their positional `matching_lines`.

## Also open (Stage-4 scope; independent)

Two more reverse-order type-1 arg pushes of the same bug class, **not yet verified
as reachable**:
- `lc_dispatch_method` (`action.c:2908`) — LocalConnection method dispatch.
- `bdRectangleGetter` (`action.c:14365`) — pushes four fixed `Rectangle` ctor args
  in reverse. Check whether that constructor is ever type-1 before assuming it's live.

Both also skip the `param_count` clamp/pad. Verify reachability with a repro first
(Stage-0 method: hand-assembled SWF via `create_test_swf.py`, since MTASC emits
`DefineFunction2` for SWF6+); new tests go in `ruffle-tests/tests/swfs/regression/`.

## Out of scope

Stage 4 (event/callback dispatchers + the deliberate normalization pass) and
Stage 5 (delete the dead marshalling loops, add `gates/check_dispatch_funnel.py` —
which should also reject any site setting `INV_BASE_CLIP | INV_VERSION_SWITCH`
together). Stage-4 leads are in the plan §4 and memory `dispatch-stage0-verdicts`
— add to them, don't act on them.
