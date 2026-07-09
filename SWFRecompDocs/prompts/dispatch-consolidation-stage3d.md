# Next-session prompt: Function-Dispatch Consolidation, Stage 3d → 4

`SWFRecompDocs/prompts/dispatch-consolidation-stage3d.md` — read it and follow it
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
   §4's Stage 3c design note, and ALL the Stage 3c landing notes — especially
   **step 5b** (`__resolve`), **step 5c** (string-primitive), and the
   **Stage 3d MC-arm survey**, which is where your work starts.
4. Run: `bash ruffle-tests/download_tests.sh avm1 from_shumway from_gnash`

## Where things stand

**14 of `actionCallMethod`'s ~19 arms are migrated onto `invokeFunctionValue()`,
plus the whole of `actionCallFunction`. Only the MC arm remains.** Last session
landed the two arms that the 3c survey called "NOT drop-ins", and they went
*opposite ways*:

| Commit | What |
|---|---|
| `0f213e931` | the `__resolve` arm — **new `INV_LOCAL_SCOPE_UNDER_CAPTURED` bit**; instance 7 |
| `fee25fd79` | the string-primitive arm — **no new flag**; instance 8; a local-scope leak fixed |
| `c7d755871` | the MOVIECLIP `__resolve` hook's clamp/pad — instance 9, found while surveying 3d |

Each CI-green in **both** modes with zero pass→fail. **Nine** confirmed instances
of the TYPE1_ARG_ORDER clamp/pad class; every prediction so far has been real.
Each has a permanent hand-assembled test in `regression/`, now **13/13** in both
modes.

Two results worth internalizing before you touch anything:

- **The `__resolve` inversion is real, but not for the reason the survey said.**
  `getCurrentLocalScope()` skips `is_with` frames, so parameter *binds* land on
  the local frame under either scope ordering. What inverts is *lookup*:
  `actionGetVariable` walks the whole chain top-down, so a captured scope shadows
  the callee's own params and locals. `regression/resolve_type1_args` pins it.
  `actionEI_callInternalInterface` has the same inversion and should use the same
  bit when Stage 4 migrates it.
- **A divergence can be real in the code and inert in behavior.** The
  string-primitive arm applied the type-2 activation to type-1 bodies, binding
  `"this"` and `"super"` by name on a `DefineFunction`'s local frame. Both writes
  are **dead**: `GetVariable("this")` takes an early this-cell path before any
  scope walk, and `GetVariable("super")` falls back to the live super context.
  This was *proved by A/B*, not argued: the arm was migrated with an
  `INV_ACT_T1_NAMED_LOCALS` bit, the bit was removed, and the test's `t=` / `ts=`
  lines were unchanged — so the bit was deleted rather than shipped. **A one-site
  flag that provably changes nothing is worse than the divergence it "preserves."**

The design is DONE — extend it, don't re-litigate it.

## YOUR TASK IS A DECISION BEFORE IT IS AN EDIT

**The MC arm is not a drop-in either.** It is surveyed (plan §4, "Stage 3d") but
deliberately not migrated: the survey ended in an open design question, and
finishing it on momentum at the end of a session was the wrong call. Read that
section first.

All user-defined MOVIECLIP-receiver dispatch sits behind `_mc_user_dispatch:`,
after the builtin-method wall. Name resolution is **unified**, so **registerClass
methods are not a separate arm** — there are three, not four:

- **A** — user method (dynamic_props / `__proto__` / MovieClip.prototype / root
  var_map / `lookupFunctionByName`)
- **B** — the `__resolve` hook
- **C** — the callable `__resolve` returned

The blocker: **the base-clip switch is neither `CF_CTX` nor `CF_CTX_LIVE`.** It
re-resolves, and on a **destroyed** clip (`depth == INT_MIN`) — or under SWF < 6 —
it falls back to `actionSetCurrentContext(mc)`, the *receiver*, rather than
entering the base clip (`CF_CTX`) or leaving the context alone (`CF_CTX_LIVE`). It
also forces `g_current_sprite_obj = NULL` like `CF_CTX`. Add a
`CF_CTX_MC_FALLBACK` mode taking the receiver, or argue for something better.
**Decide, say why, then edit.**

Per-arm asymmetries to reproduce, not normalize (diff them yourself; don't trust
this table):

| | A | B | C |
|---|---|---|---|
| `retainObject` on local frame | **no** | yes | yes |
| `g_this_stack` push | type-1 half only | no | no |
| `g_current_executing_func` | save/set/restore | save/set/restore | **untracked** |
| args | caller's | synthetic name, 1 | caller's |

Common to all three: no super context, no ctor context, no override-`this`, no
`g_call_this_type` / `g_c_function_this_obj`, no `arguments`/`super` binding, no
DefineFunction2 flags gate, no `g_max_call_depth` pre-check. All pass **NULL** as
`advanced_func`'s receiver and bind the MC via `g_event_this_mc`
(= `INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR`); all bind `"this"` on the local
frame with `scope_mc = NULL` (`INV_BIND_THIS` **without** `INV_LOCAL_SCOPE_MC`);
all restore captured scopes with `is_with` **copied**, not forced.

Arms A and C already push type-1 args forward, clamped and padded — they are
clean. Arm B was instance nine and is already fixed in place. So this migration is
**not** expected to fix a tenth bug; if you find one, verify it with a repro
first, per Stage 0's method.

After the MC arm: **Stage 4** (event/callback dispatchers + the deliberate
normalization pass, including the `INV_LOCAL_SCOPE_UNDER_CAPTURED` flip with a
test) and **Stage 5** (delete the dead marshalling loops; add
`gates/check_dispatch_funnel.py`, which should also reject any site setting
`INV_BASE_CLIP | INV_VERSION_SWITCH` together).

## Guardrails

- Behavior-preserving by default; normalization is Stage 4. §3 of the plan
  explains why today's inconsistencies are load-bearing.
- One arm (or one small coherent group) per commit; full CI in **both**
  no-graphics and graphics modes per batch (shared runtime code). Autonomous
  commit/push/CI is authorized — follow `.claude/pipeline-handoff.md`. Report any
  pass→fail regressions by name. **Zero pass→fail is the bar.**
- **Diff each arm's actual ritual against the core rather than assuming it
  matches.** Four standing proofs: (a) the empty-method-name arm sets
  `g_override_this_set = 1` then clears it again BEFORE the call when
  `register_count == 0`, so `INV_OVERRIDE_THIS` (sets unconditionally, clears
  AFTER) does NOT reproduce it; (b) `.call`/`.apply` and the array arms pass
  `pushSuperContext` a receiver the core would NOT derive from `this_var`
  (`this_obj` / `arr->props`), so the super push stays outside, bracketing the
  core call; (c) the string-primitive arm's type-1 `flags` handling — real in the
  code, inert in behavior; (d) the `__resolve` arm's scope inversion — inert for
  binds, live for lookups.
- **But also diff the other way: before adding a flag to preserve a divergence,
  try deleting the divergence and see whether any test notices.** Add the flag
  only if something does.
- NEVER "fix" the core to source `pushSuperContext` from `pass_this` — the
  object-method arm depends on today's behavior, passing `this_ptr = obj` while
  its `this_var` falls back to `root_movieclip`.
- NEVER set `INV_BASE_CLIP` and `INV_VERSION_SWITCH` together — the base-clip gate
  reads `g_swf_version` after the switch installs the callee's version. Use a
  `ClosureFrame` instead.
- `INV_ACT_THIS` requires `INV_LOCAL_SCOPE` (`buildActivationLocals` returns early
  without a local frame). An arm wanting only the `g_this_stack` push and no local
  frame must use `INV_THIS_STACK` — the identical operation for a type-1 callee.
- An arm that wants `INV_ACT_ARGUMENTS` must let the core own `INV_EXEC_FUNC`, or
  `arguments.caller` becomes the callee itself.
- Preserve pointer-identity thunk checks (`builtin_stub_method`,
  `builtin_noop_func`, `builtin_array_method`, `builtin_prim_wrapper_toString`,
  `builtin_wrapper_valueOf`) before calling the core — dispatch decisions, not
  invocation steps.
- A new regression test must be verified to FAIL without the fix: run it before
  editing `action.c`, or copy the parent commit's `action.c` over the working
  copy, run it, restore. A test that passes both ways is worthless.
- Don't `git add` `ruffle-tests/tests/swfs/*/_results/` — a local suite run
  dirties those CI-owned files.
- **Line numbers in the plan and in these notes go stale** — every migration moves
  `action.c` by tens of lines. Grep for the symbol, don't trust the number.

## Reading CI

`results_diff.md`'s line metrics compare POSITIONALLY. On the SAME already-failing
gnash `argstest` tests, step 3's fix LOWERED `matching_lines` and step 4's RAISED
them — same fix class both times. The direction only tracks whether the shortened
output happens to re-align. It is not evidence either way. On any "Line Count
Changed" row for a test that was already failing, reproduce both sides and diff
the ACTUAL outputs before concluding anything.

## Testing

`verify_output.py --test` is repeatable but all names must resolve to ONE suite —
pass `--tests-dir` to disambiguate. Pass the whole cluster in ONE invocation (it
builds once); a serial loop recompiles ~45 s/test and times out. Watch out for
`cd` persisting between Bash calls — use absolute paths when creating test dirs.

Sensitive clusters: `as2_super_and_this_v6`/`_v8` (NOT `_swf6`), `super_edge_cases`,
`extends_chain`, `register_and_init_order`, `swf5_no_closure`,
`swf5_to_6_cross_call`, `call`, `funky_function_calls`, `arguments`,
`register_class`, `extends_native_type`, `custom_clip_methods`, `object_resolve`,
`resolve_different_root`, `coerce_to_primitive_resolve`,
`coerce_to_object_monkeypatch`, `string_methods*`, `string_coercion`, `closure_scope`,
`with`.

Standing guards in `regression/` (findable by bare name, 13 of them): `ei_type1_args`,
`mc_event_type1_args`, `timer_cross_swf_version`, `nc_onstatus_closure`,
`fn_call_type1_args`, `fn_empty_method_type1_args`, `method_type1_args`,
`fn_call_builtin_type1_args`, `array_method_type1_args`, `array_element_type1_args`,
`resolve_type1_args`, `string_prim_method_type1_args`, `mc_resolve_type1_args`.

Note `string_relational_compare` (avm1) is `output_mismatch` and on
`ignored_tests.txt` — it will show up in a local cluster run. Not yours.

## CI baseline to hold (both modes, @ `c7d755871`)

| Suite | no-graphics | graphics |
|---|---|---|
| avm1 | 634/706 | 634/706 |
| **regression** | **13/13** | **13/13** |
| from_shumway | 73/92 | 73/92 |
| from_shumway/avm1 | 46/47 | 46/47 |
| from_gnash/actionscript.all | 135/243 | 135/243 |
| from_gnash/misc-ming.all | 69/111 | 68/111 |
| from_gnash/misc-swfmill.all | 19/20 | 19/20 |
| from_gnash/misc-mtasc.all | 7/9 | 7/9 |
| from_gnash/misc-swfc.all | 11/20 | 11/20 |

## Known reds — do NOT chase, they are not yours

`watch_virtual_property` and `string_relational_compare` (avm1);
`delete-v5..v8` / `delete2` (upstream fixture drift); `argstest-v6/v7/v8` (gnash,
`output_mismatch` long before this work).

## Perf

Settled, don't redo it. The core is free (≤0.0019% of Ir everywhere measured). N
never executes the core and swings ~13% run-to-run; Minesweeper never executes
`actionCallFunction` at all; Doodle Jump reaches it but the core's self cost there
is 239 Ir. Don't re-litigate without a workload that actually stresses a migrated
branch.

## If the MC arm lands CI-green and time remains

The two unverified reverse-order type-1 pushes of the same bug class, both in
Stage-4 scope and independent: `lc_dispatch_method` (LocalConnection method
dispatch, ~`action.c:2908`) and `bdRectangleGetter` (~`action.c:14365`, pushes four
fixed `Rectangle` ctor args in reverse; check whether that constructor is ever
type-1 before assuming it's live). Both also skip the `param_count` clamp/pad.
**Verify reachability with a repro before fixing either** — nine for nine is a
reason to expect them, not a reason to skip the repro.
