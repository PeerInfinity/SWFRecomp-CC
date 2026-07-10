# Next-session prompt: Function-Dispatch Consolidation, Stage 4 → 5

`SWFRecompDocs/prompts/dispatch-consolidation-stage4.md` — read it and follow it
end-to-end; the plan it references
(`SWFRecompDocs/plans/function-dispatch-consolidation-plan.md`) is the source of
truth for the survey, the staged design, the Stage 1/2/3a/3b/3c/3d landing notes,
the verification protocol, and the risks.

Session start, in order:

1. Read `CLAUDE.md` (build commands, the "never run full suites locally" rule, the
   autonomous git/CI authorization, the accepted-diffs doc policy).
2. Read `ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md` and
   `ruffle-tests/tests/swfs/avm1/_investigation/CURRENT_STATUS.md`.
3. Read the plan. In it, read §3 ("today's inconsistencies are load-bearing"),
   §4's Stage 3c design note, and ALL the Stage 3c/3d landing notes — especially
   **step 5b** (`__resolve`), **step 5c** (string-primitive), and the **Stage 3d
   landing note**, whose "two modes, and the callee-version gate" finding is the
   most recent correction to the design.
4. Run: `bash ruffle-tests/download_tests.sh avm1 from_shumway from_gnash`

## Where things stand

**Stage 3 is COMPLETE.** All ~19 of `actionCallMethod`'s invocation arms and all of
`actionCallFunction` funnel through `invokeFunctionValue()`. Recent landings:

| Commit | What |
|---|---|
| `0f213e931` | the `__resolve` arm — **new `INV_LOCAL_SCOPE_UNDER_CAPTURED` bit**; instance 7 |
| `fee25fd79` | the string-primitive arm — **no new flag**; instance 8; a local-scope leak fixed |
| `c7d755871` | the MOVIECLIP `__resolve` hook's clamp/pad — instance 9 |
| `3593ca852` | **the MC arm** — no new `InvokeOpts` flag; two new `ClosureFrame` modes; two leaks fixed |

Each CI-green in **both** modes with zero pass→fail. **Nine** confirmed instances of
the TYPE1_ARG_ORDER clamp/pad class; each has a permanent hand-assembled test in
`regression/`, **13/13** in both modes.

Four results worth internalizing before you touch anything:

- **The `__resolve` inversion is real, but not for the reason the survey said.**
  `getCurrentLocalScope()` skips `is_with` frames, so parameter *binds* land on the
  local frame under either scope ordering. What inverts is *lookup*:
  `actionGetVariable` walks the whole chain top-down, so a captured scope shadows the
  callee's own params and locals. `regression/resolve_type1_args` pins it.
  `actionEI_callInternalInterface` has the same inversion and should use
  `INV_LOCAL_SCOPE_UNDER_CAPTURED` when you migrate it.
- **A divergence can be real in the code and inert in behavior.** The string-primitive
  arm bound `"this"`/`"super"` by name on a type-1 body's local frame. Both writes are
  **dead** (`GetVariable("this")` takes an early this-cell path; `GetVariable("super")`
  falls back to the live super context). Proved by A/B, not argued: the preserving flag
  was added, then removed, and the test was unchanged — so it was deleted rather than
  shipped. **A one-site flag that provably changes nothing is worse than the divergence
  it "preserves."**
- **The `INV_BASE_CLIP | INV_VERSION_SWITCH` hazard is LIVE, not latent.** The three
  MOVIECLIP arms have always gated their base-clip switch on the **callee's** SWF
  version, because they read `g_swf_version` after their own `switchToFunctionVersion`.
  Every other arm gates on the caller's. Stage 3d preserved this by computing
  `eff_ver` in the arm. Do not quietly normalize it — see below.
- **`INV_EXEC_FUNC` is not free.** It also writes `g_prev_executing_func`, which
  `swf_setup_arguments_props` reads from a generated `preload_arguments` prologue.
  Three arms deliberately keep the exec-func swap outside the core because of this.

The design is DONE — extend it, don't re-litigate it.

## Your task: Stage 4, and it is two passes per dispatcher

Stage 4 is the event/callback dispatchers **plus** the deliberate normalization pass.
Per the plan: **(a)** behavior-preserving migration, then **(b)** a normalization
review — "should this path get version-switch / captured-scope / this-stack?" Each
"yes" is its own commit with a targeted test.

Dispatchers in scope: `mc_call_as2_handler_ng`, `fireTimerCallback`,
`builtin_broadcaster_broadcastMessage`, `fireMCLEvent`, `fireLoadVarsCallback`,
`soundFireCallback`, the LC/NS/NC dispatchers, `actionEI_callInternalInterface`,
`call_function_with_this`, the watch arms in `actionSetVariable`/`actionSetMember`,
`_invoke_sort_comparator`, and the coercion paths (`objectCallValueOf`/`ToString`/
`toPrimitive`, `convertFloat`).

**Known normalizations waiting for this stage, each with a proven failure mode or a
pinning test:**

- `actionEI_callInternalInterface`'s scope inversion → use
  `INV_LOCAL_SCOPE_UNDER_CAPTURED`, then consider flipping it (guarded by
  `regression/resolve_type1_args` for the `__resolve` twin).
- The **`INV_LOCAL_SCOPE_UNDER_CAPTURED` flip itself**, with a test. The inversion is
  almost certainly wrong.
- The **callee-vs-caller version gate**. Stage 3d showed the MC arms gate on the
  callee's version and the other four on the caller's. "A SWF5 function has no
  closures" is a property of the function, not of who calls it — so the MC arms may be
  the *correct* ones. Normalizing means picking one and writing a cross-version test;
  `regression/timer_cross_swf_version` is the model.
- `mc_call_as2_handler_ng`, EI, and the coercion paths still **skip
  `switchToFunctionVersion`** entirely (Stage 0 proved this was a real bug on the timer
  path, `60070d96a`).
- The MC arms set `g_event_this_mc` only on their type-2 branch; the core would set it
  for both. Consider whether a type-1 MC method body should see it.

**The two remaining reverse-order type-1 pushes — reachability now MEASURED (don't
redo the experiment), and they are NOT the same case:**

- **`lc_dispatch_method` (LocalConnection method dispatch) — type-1 arm is LIVE.** The
  existing avm1 `localconnection` test reaches it with a real `simple_func`. The one
  observed call had `num_args = 0, param_count = 0`, so it does not itself misbind: the
  reverse order and the missing clamp/pad are **latent on a live path**. Write the repro
  with `num_args >= 1` or `param_count >= 1` (SWF6 + a plain `DefineFunction` receiver
  method — LocalConnection is Flash 6+ and Flash MX-era SWF6 emits `DefineFunction`).
  Expect **instance ten**.
- **`lc_dispatch_method` also has a NULL-call hazard, and it is the better reason to
  migrate it first.** Its `else` branch catches *everything* that is not
  `function_type == 2` and calls `func->simple_func` with **no NULL check**. A type-1
  both-pointers-NULL native — a `g_mc_method_funcs` stub (`MovieClip.prototype.getDepth`)
  or a `g_stub_ctors` entry — assigned as an LC receiver method is a NULL call. The
  core's strict dispatch fixes it for free. **Migrate; don't patch the push loop.**
- **`bdRectangleGetter` — type-1 branch is NOT reached by the suite.** Probed across
  gnash `BitmapData-v6/v7/v8` and the avm1 `bitmap_data*` cluster: zero hits. The only
  `flash.geom.Rectangle` override in the suite (gnash `BitmapData.as`, before tests
  324/329/334) compiles to a **DefineFunction2** and takes the type-2 branch. Fix the
  reverse push during migration, but **do not credit it as a found-in-the-wild
  instance** and don't spend a session hunting a natural repro.

Method note: both were settled by instrumenting the type-1 branch with a probe that
writes to a **file** (the runner swallows the test binary's stderr) and running the
candidate tests. Cheap, decisive, and it is the same technique that proved the Stage-3d
`ClosureFrame` modes were already covered.

Also queued: the type-1 arms of `fireTimerCallback` (both forms) push forward
(correct) but do **not** clamp/pad. (The `lc/ns/nc_dispatch_onStatus` +
`ns_dispatch_onMetaData` family is DONE — five dispatchers, instances eleven
and twelve, `regression/{lc,nc}_onstatus_type1_args`; note NC's type-1 arms
push no local frame and `nc_dispatch_onStatus_undefined`'s pushes nothing —
preserved via per-branch flags.)

After Stage 4: **Stage 5** (delete the dead marshalling loops; add
`gates/check_dispatch_funnel.py`, which should also reject any site setting
`INV_BASE_CLIP | INV_VERSION_SWITCH` together).

## Guardrails

- Behavior-preserving first; normalization is a **separate commit with a test**.
  §3 of the plan explains why today's inconsistencies are load-bearing.
- One dispatcher (or one small coherent group) per commit; full CI in **both**
  no-graphics and graphics modes per batch (shared runtime code). Autonomous
  commit/push/CI is authorized — follow `.claude/pipeline-handoff.md`. Report any
  pass→fail regressions by name. **Zero pass→fail is the bar.**
- **Diff each site's actual ritual against the core rather than assuming it matches.**
  Five standing proofs: (a) the empty-method-name arm sets `g_override_this_set = 1`
  then clears it again BEFORE the call when `register_count == 0`, so
  `INV_OVERRIDE_THIS` (sets unconditionally, clears AFTER) does NOT reproduce it;
  (b) `.call`/`.apply` and the array arms pass `pushSuperContext` a receiver the core
  would NOT derive from `this_var` (`this_obj` / `arr->props`), so the super push stays
  outside, bracketing the core call; (c) the string-primitive arm's type-1 `flags`
  handling — real in the code, inert in behavior; (d) the `__resolve` arm's scope
  inversion — inert for binds, live for lookups; (e) the MC arms' version gate reads
  the callee's version, and `INV_EXEC_FUNC` would change `arguments.caller`.
- **But also diff the other way: before adding a flag to preserve a divergence, try
  deleting the divergence and see whether any test notices.** Add the flag only if
  something does. Conversely, before assuming a path is untested, *instrument it* and
  attribute each branch to a test — that is how Stage 3d established that
  `function_base_clip_removed` and `swf5_no_closure` already cover the two new
  `ClosureFrame` modes, and therefore that no new lock test was warranted.
- NEVER "fix" the core to source `pushSuperContext` from `pass_this` — the
  object-method arm depends on today's behavior, passing `this_ptr = obj` while its
  `this_var` falls back to `root_movieclip`.
- NEVER set `INV_BASE_CLIP` and `INV_VERSION_SWITCH` together. Use a `ClosureFrame`,
  and compute the version gate in the arm.
- `INV_ACT_THIS` requires `INV_LOCAL_SCOPE` (`buildActivationLocals` returns early
  without a local frame). An arm wanting only the `g_this_stack` push and no local
  frame must use `INV_THIS_STACK`.
- An arm that wants `INV_ACT_ARGUMENTS` must let the core own `INV_EXEC_FUNC`, or
  `arguments.caller` becomes the callee itself.
- Preserve pointer-identity thunk checks (`builtin_stub_method`, `builtin_noop_func`,
  `builtin_array_method`, `builtin_prim_wrapper_toString`, `builtin_wrapper_valueOf`)
  before calling the core — dispatch decisions, not invocation steps.
- The core's dispatch is **strict**: it requires `function_type == 2` for
  `advanced_func` and `== 1` for `simple_func`. Audited across the whole runtime and
  safe (no type-1 has a live `advanced_func`; all 121 `advanced_func` sites pair with
  `function_type = 2`). A trailing `else if (advanced_func != NULL)` at a migration
  site is dead code, not a behavior you must preserve.
- A new regression test must be verified to FAIL without the fix: run it before editing
  `action.c`, or copy the parent commit's `action.c` over the working copy, run it,
  restore. A test that passes both ways is worthless **as a bug repro** — but a
  deliberate *behavior lock* (Stage 0's `nc_onstatus_closure`) is a different artifact;
  say which one you are writing.
- Don't `git add` `ruffle-tests/tests/swfs/*/_results/` — a local suite run dirties
  those CI-owned files.
- **Line numbers in the plan and in these notes go stale** — every migration moves
  `action.c` by tens of lines. Grep for the symbol, don't trust the number.

## Reading CI

`results_diff.md`'s line metrics compare POSITIONALLY. On the SAME already-failing
gnash `argstest` tests, step 3's fix LOWERED `matching_lines` and step 4's RAISED
them — same fix class both times. The direction only tracks whether the shortened
output happens to re-align. It is not evidence either way. On any "Line Count
Changed" row for a test that was already failing, reproduce both sides and diff the
ACTUAL outputs before concluding anything.

## Testing

`verify_output.py --test` is repeatable but all names must resolve to ONE suite —
pass `--tests-dir` to disambiguate. Pass the whole cluster in ONE invocation (it
builds once); a serial loop recompiles ~45 s/test and times out. The runner swallows
the test binary's stderr, so a temporary probe must write to a file, not `stderr`.
Watch out for `cd` persisting between Bash calls — use absolute paths when creating
test dirs.

Sensitive clusters: `as2_super_and_this_v6`/`_v8` (NOT `_swf6`), `super_edge_cases`,
`extends_chain`, `register_and_init_order`, `swf5_no_closure`,
`swf5_to_6_cross_call`, `call`, `funky_function_calls`, `arguments`,
`register_class`, `extends_native_type`, `custom_clip_methods`, `object_resolve`,
`resolve_different_root`, `coerce_to_primitive_resolve`,
`coerce_to_object_monkeypatch`, `string_methods*`, `string_coercion`, `closure_scope`,
`with`, `function_base_clip{,_removed,_readded}`, `this_swf5`/`_swf6`/`_swf7`.

Standing guards in `regression/` (findable by bare name, 13 of them): `ei_type1_args`,
`mc_event_type1_args`, `timer_cross_swf_version`, `nc_onstatus_closure`,
`fn_call_type1_args`, `fn_empty_method_type1_args`, `method_type1_args`,
`fn_call_builtin_type1_args`, `array_method_type1_args`, `array_element_type1_args`,
`resolve_type1_args`, `string_prim_method_type1_args`, `mc_resolve_type1_args`.

Note `string_relational_compare` (avm1) is `output_mismatch` and on
`ignored_tests.txt` — it will show up in a local cluster run. Not yours.

## CI baseline to hold (raw `pass`, both modes, @ `ddbe4f878`)

| Suite | no-graphics | graphics |
|---|---|---|
| avm1 | 634/706 | 634/706 |
| **regression** | **16/16** | **16/16** |
| from_shumway | 73/92 | 73/92 |
| from_shumway/avm1 | 46/47 | 46/47 |
| from_gnash/actionscript.all | 135/243 | 135/243 |
| from_gnash/misc-ming.all | 69/111 | 68/111 |
| from_gnash/misc-swfmill.all | 19/20 | 19/20 |
| from_gnash/misc-mtasc.all | 7/9 | 7/9 |
| from_gnash/misc-swfc.all | 11/20 | 11/20 |

`results.json`'s `effective_pass` field includes `ruffle_matched` and is higher than
these numbers; the table is raw `pass`. Compare like with like.

## Known reds — do NOT chase, they are not yours

`watch_virtual_property` and `string_relational_compare` (avm1);
`delete-v5..v8` / `delete2` (upstream fixture drift); `argstest-v6/v7/v8` (gnash,
`output_mismatch` long before this work).

## Perf

Settled, don't redo it. The core is free (≤0.0019% of Ir everywhere measured). N
never executes the core and swings ~13% run-to-run; Minesweeper never executes
`actionCallFunction` at all; Doodle Jump reaches it but the core's self cost there
is 239 Ir. Don't re-litigate without a workload that actually stresses a migrated
branch. Note Stage 4's dispatchers (events, timers) run every frame in real games —
if any stage warrants a fresh measurement, it is this one, on Minesweeper or DJ.
