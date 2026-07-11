# Next-session prompt: Function-Dispatch Consolidation, Stage 4 pass (b) → Stage 5

`SWFRecompDocs/prompts/dispatch-consolidation-stage4.md` — read it and follow it
end-to-end; the plan it references
(`SWFRecompDocs/plans/function-dispatch-consolidation-plan.md`) is the source of
truth for the survey, the staged design, the Stage 1/2/3a/3b/3c/3d/4 landing notes,
the verification protocol, and the risks.

Session start, in order:

1. Read `CLAUDE.md` (build commands, the "never run full suites locally" rule, the
   autonomous git/CI authorization, the accepted-diffs doc policy).
2. Read `ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md` and
   `ruffle-tests/tests/swfs/avm1/_investigation/CURRENT_STATUS.md`.
3. Read the plan. In it, read §3 ("today's inconsistencies are load-bearing" —
   NOW BEING DELIBERATELY REVISITED, which is exactly why each flip needs its
   own commit + test) and ALL the Stage 3c/3d/4 landing notes — the three
   Stage-4 third-session notes (instances 19/20/21) are the most recent
   corrections to the design.
4. Read the normalization master list in
   `SWFRecompDocs/plans/dispatch-stage4-dossiers.md` (grep "Normalization
   pass (b) master list") and the per-item dossier bullets it references.
5. Run: `bash ruffle-tests/download_tests.sh avm1 from_shumway from_gnash`

## Where things stand

**Stages 0–3 and Stage 4's migration pass (a) are COMPLETE.** Every surveyed
dispatcher funnels through `invokeFunctionValue()`. Stage-4 landings:

| Commit | What |
|---|---|
| `0f213e931` | the `__resolve` arm — **new `INV_LOCAL_SCOPE_UNDER_CAPTURED` bit**; instance 7 |
| `fee25fd79` | the string-primitive arm — **no new flag**; instance 8; a local-scope leak fixed |
| `c7d755871` | the MOVIECLIP `__resolve` hook's clamp/pad — instance 9 |
| `3593ca852` | **the MC arm** — no new `InvokeOpts` flag; two new `ClosureFrame` modes; two leaks fixed |
| `704a9cbbf` | **Stage 4 opens**: `lc_dispatch_method` — instance ten + a NULL-call fix; `InvokeOpts` block relocated above the LC section |
| `ddbe4f878` | **the onStatus/onMetaData family** (5 dispatchers) — instances eleven+twelve; three distinct type-1 rituals preserved per-branch |
| `66e15789a` | `fireMCLEvent` — flags=0, the simplest adapter; clamp/pad fixed-not-credited |
| `ea3647e8d` | **`soundFireCallback` + `fireLoadVarsCallback`** — instances thirteen+fourteen; INV_LOCAL_SCOPE_UNDER_CAPTURED's second user; LV's INV_EXEC_FUNC+INV_ACT_ARGUMENTS pair |
| `ab3b7a77f` | **`mc_call_as2_handler_ng`** — first event-family INV_LOCAL_SCOPE_MC user; exec-func swap moved INTO the core (exact match) |
| `8c576d3e5` | `_invoke_sort_comparator` — instance fifteen; per-comparison registers HCALLOC perf delta flagged |
| `1f68e0043` | **the coercion paths + `call_function_with_this`** (5 sites, 8 branches) — instance sixteen (one for the family); version-switch/base-clip brackets kept in the oCVO/oCTS arms |
| `8a8ff17c7` | **`fireTimerCallback`** — instance seventeen; TU boundary resolved: `INV_*` flags + `InvokeOpts` now in `action_internal.h`, exported `actionInvokeFunctionValue` wrapper |
| `23b8ab41a` | **`actionEI_callInternalInterface`** — depth guard moves INTO the core; `INV_LOCAL_SCOPE_UNDER_CAPTURED`'s second user; type-1 `INV_BIND_THIS` is LIVE there; `regression/ei_closure_scope_order` lock landed first |
| `73a50cf5f` | **the watch arms B → C → A** — instance eighteen; shared `invokeWatchCallback()` adapter; B-t1's enclosing-scope this-write dropped (string-primitive precedent) |
| `3d7788391` + `ecb5aeedb` | **two watch real-bug fixes** (probes confirmed): Site C's `_sm_buf` clobber across the watcher call; Site A's pname double-free with named-param watchers (suite's first hand-emitted DefineFunction2) |
| `a2ded85b7` | **the enterFrame trio** (children/root/var-map arms) — no credited instance (pad inert at frame-loop level, A/B-proved); `regression/enterframe_type1_args` is a lock; children arm = third variant of the local-under-captured inversion (is_with COPIED) |
| (this session) | **onLoad + onConstruct** (`actionDispatchMCOnLoad`/`MCOnConstruct`; `RootOnLoad` is a thin wrapper) — **instance nineteen** (`regression/onconstruct_type1_args`: onConstruct fires MID-SCRIPT from createEmptyMovieClip, the missing t1 pad swallowed the caller's in-flight `"X: "` operand); `regression/onload_type1_args` is a lock (queue-drain only; pins the t1 `this` channel). Live-code correction: these arms have NO version switch — INV_BASE_CLIP's ambient gate is exact, no ClosureFrame; t1 = FOURTH local-under-captured variant (is_with FORCED); t2 = INV_ACT_THIS + INV_MC_THIS_NULL_PTR; INV_BIND_THIS preserves the dead name-bind at zero cost |
| (this session) | **the EIGHT onUnload firing sites** (the prompt's "5" undercounted: + actionGetURL's `_level`/named-clip empty-URL branches + MCL.unloadClip) → shared `invokeUnloadHandler()` adapter — **instance twenty** (`regression/onunload_type1_args`: 6 of 8 sites fire MID-SCRIPT; signature differs from onConstruct's — no local frame on the t1 path means the stolen operands bind ambiently and the param rows read undefined either way; the discriminator is the OUTER expression, `0` → `X: `). Ritual = invokeSpecialFunction's: g_special_depth bracket outside the core; t2 = bare INV_LOCAL_SCOPE, NO captured scopes (preserved divergence); t1 = no local frame (preserved; bind-leak is a normalization candidate). invokeSpecialFunction is down to ONE caller (lv_url_encode's escape override) |
| (this session) | **`super_bind` core extension** (own commit) + **`builtin_broadcaster_broadcastMessage`** — **instance twenty-one** (`regression/broadcast_type1_args`: the t1 arm padded but did NOT clamp — 3 extras to a 2-param listener bound the LAST two and stranded `x1`, surfacing as `x1true`). Both AsBroadcaster tripwires (v6 t1 super shadow, v7 t2) **byte-diffed identical** old-vs-new. Loop/method-resolution/`pushSuperContext(listener_obj, depth)` bracket stay in the arm; per-branch this_var preserves the both-NULL corner disagreement; `has_this_ptr = listener_obj` for both. **Stage 4 migration pass (a) is COMPLETE** |

Each CI-green in **both** modes with zero pass→fail. **Eighteen** confirmed instances of
the TYPE1_ARG_ORDER clamp/pad class; each has a permanent hand-assembled test in
`regression/`, **27/27** locally.

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

## Per-dispatcher analysis dossiers — READ FIRST

`SWFRecompDocs/plans/dispatch-stage4-dossiers.md` (2026-07-10) has a full
analysis dossier for every remaining Stage-4 dispatcher: exact ritual per arm,
proposed flag mapping, divergences, clamp/pad + NULL-call status, reachability,
repro designs, and a cross-cutting synthesis with a suggested migration order
and the two known blockers (fireTimerCallback's TU boundary; broadcastMessage's
type-1 super shadow needing a `super_bind` core extension). The dossiers are
advisory — re-verify the flag mapping against live code before each commit —
but they replace the first hour of every migration session.

## Your task: normalization pass (b), then Stage 5

**Migration pass (a) is COMPLETE** (2026-07-10, third session — see the
table above; 21 credited TYPE1_ARG_ORDER instances, 31 regression guards).
Every surveyed dispatcher funnels through `invokeFunctionValue`;
`invokeSpecialFunction` is down to one caller (`lv_url_encode`'s
`_global.escape` override). What remains of Stage 4 is the deliberate
**normalization pass (b)**: for each preserved divergence, decide "should
this path get version-switch / captured-scope / this-stack / depth-guard?"
— each "yes" is its **own commit with a targeted test that flips** (a new
repro, or a deliberate edit to an existing lock — flipping a lock is a
feature here, it proves the change is observable). Each "no" is a
documented decision, not silence.

**The master list** (dossiers doc, "Normalization pass (b) master list"
near the end — grep it; plus session-3 additions). In rough
value-over-effort order:

1. **`switchToFunctionVersion` adds** — the proven-bug class (Stage 0's
   timer bug `60070d96a`; `regression/timer_cross_swf_version` is the model
   and the test template). Missing on: `mc_call_as2_handler_ng` (**test
   design READY** — `mc_event_cross_swf_version`, spelled out in the
   mc_call_as2_handler_ng dossier's "Normalization (a)" bullet: SWF7 host
   loadMovies a SWF6 child whose v6 handler must see v6 undefined-coercion;
   requires a host+child two-SWF regression test — check how
   `HAS_CHILD_MOVIES` tests are laid out before building), EI, the
   broadcaster, the watch arms, `objectToPrimitive`/`convertFloat`/
   `call_function_with_this`, LV/XML/sound, and (session-3 discovery)
   **onLoad/onConstruct**. NOT MCL (its drain stages the ambient version
   itself — adding the flag would double-switch); NOT the
   `objectCallValueOf`/`objectCallToString` main branches (they already
   switch).
2. **The `INV_LOCAL_SCOPE_UNDER_CAPTURED` flip** — the inversion is almost
   certainly wrong. Now FOUR variants share it: `__resolve`, EI (forced
   with), the enterFrame children arm (copied with), onLoad/onConstruct
   (forced with). One commit flipping all users together, deliberately
   flipping the lock tests (`resolve_type1_args`, `ei_closure_scope_order`)
   — a captured scope shadowing the callee's own params is the observable.
3. **The callee-vs-caller version gate unification.** Callee-gate
   instances: the MC arms, fireTimerCallback's function form, the
   enterFrame children arm. "A SWF5 function has no closures" is a property
   of the function → the callee gate is probably the correct one. Pick,
   write the cross-version test, convert the others.
4. **Missing depth guards**: coercion recursion, broadcaster re-broadcast,
   watch A/C re-fire. Each needs a recursion repro that today segfaults or
   silently wedges — check what Flash/Ruffle actually do (Ruffle's 66-deep
   special limit vs ScriptLimits) before picking the guard type.
5. **The onUnload t1 local frame** (session-3): the path pushes NO local
   frame, so a param'd handler's prologue binds leak ambiently
   (`onunload_type1_args`'s docstring documents it). Adding
   `INV_LOCAL_SCOPE` for t1 is the normalization; the test is an
   onUnload handler whose param name collides with a global.
6. **soundFireCallback family**: exec-func + arguments for t2 (XML
   handlers' `arguments` are broken today — dossier claim, verify with a
   probe first), this-stack, and its scope-order (rides item 2).
7. Smaller queue: watch D1 (return fold) / D6 (userData) / D8 (old-value
   source); `convertFloat`'s missing t1 this push; sort-comparator captured
   scopes for t2; LV grandparent-caller; `g_event_this_mc` for the MC arms'
   t1 branch.

Method notes that carry over: settle reachability questions with a
**file-writing probe** (the runner swallows stderr), never by argument. EI's
forced-with is NOT observable via SetVariable write-back — the discriminator
is a `var`/DefineLocal in the callee. A dispatcher that only runs between
frames (empty stack) yields **locks, not repros**, for marshalling changes —
mid-script dispatchers (coercion, watch, onConstruct, onUnload,
broadcastMessage) are where repros live.

**Then Stage 5** (can start same session once (b)'s high-value items land):
- Audit for now-dead marshalling helpers (most raw loops were replaced
  in-place by the migrations; what's left is whatever became unreachable).
- Add `gates/check_dispatch_funnel.py` (follow the existing `gates/`
  pattern): grep for raw `simple_func`/`advanced_func` calls outside
  `invokeFunctionValue` + an allowlist (generated-code callers,
  `lv_url_encode` until someone migrates it), and reject any site setting
  `INV_BASE_CLIP | INV_VERSION_SWITCH` together.
- The perf note below: Stage 4's dispatchers run every frame in real games —
  if a fresh measurement is ever warranted it is now, on Minesweeper or DJ
  (callgrind harness per `wasm-game-performance-profiling` memory; N is
  noisy, never A/B on it).

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

Standing guards in `regression/` (findable by bare name, 31 of them): `ei_type1_args`,
`mc_event_type1_args`, `timer_cross_swf_version`, `nc_onstatus_closure`,
`fn_call_type1_args`, `fn_empty_method_type1_args`, `method_type1_args`,
`fn_call_builtin_type1_args`, `array_method_type1_args`, `array_element_type1_args`,
`resolve_type1_args`, `string_prim_method_type1_args`, `mc_resolve_type1_args`,
`lc_method_type1_args`, `lc_onstatus_type1_args`, `nc_onstatus_type1_args`,
`lv_ondata_type1_args`, `xml_onload_type1_args`, `sort_comparator_type1_args`,
`coerce_type1_args`, `timer_type1_args`, `ei_closure_scope_order`,
`watch_setmember_type1_args`, `watch_mc_type1_args`,
`watch_mc_reentrant_setmember`, `watch_timeline_named_params`,
`enterframe_type1_args`, `onconstruct_type1_args`, `onload_type1_args`,
`onunload_type1_args`, `broadcast_type1_args`.

Note `string_relational_compare` (avm1) is `output_mismatch` and on
`ignored_tests.txt` — it will show up in a local cluster run. Not yours.

## CI baseline to hold (raw `pass`, both modes, @ `83bef14d7` — the Stage-4-complete batch, 2026-07-11)

| Suite | no-graphics | graphics |
|---|---|---|
| avm1 | 634/706 | 634/706 |
| **regression** | **31/31** | **31/31** |
| from_shumway | 73/92 | 73/92 |
| from_shumway/avm1 | 46/47 | 46/47 |
| from_gnash/actionscript.all | 135/243 | 135/243 |
| from_gnash/misc-ming.all | 69/111 | 68/111 |
| from_gnash/misc-swfmill.all | 19/20 † | 19/20 † |
| from_gnash/misc-mtasc.all | 7/9 | 7/9 |
| from_gnash/misc-swfc.all | 11/20 | 11/20 |

† `mixed-bytecode-as2` showed 19→18 at `83bef14d7` in BOTH modes — that was
the concurrent **AVM2 Stage 2** emitter (unimplemented GetGlobalScope on a
mixed AVM1+AVM2 SWF), not dispatch work, and was fixed same-day by
`03c86381d` (DoABC gated on the FileAttributes AS3 bit). If it flips again,
check the AVM2 emitter first.

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
