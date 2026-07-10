# Dispatch Stage 4 — per-dispatcher analysis dossiers

**Date:** July 10, 2026 (analysis fan-out, 8 parallel read-only agents)
**Parent plan:** [`function-dispatch-consolidation-plan.md`](function-dispatch-consolidation-plan.md)
**Session prompt:** [`../prompts/dispatch-consolidation-stage4.md`](../prompts/dispatch-consolidation-stage4.md)

Each dossier below was produced by a read-only analysis agent primed with the
core's flag semantics (`InvokeOpts` block ~line 2635, `invokeFunctionValue`
~line 15538), the plan's landing notes, and the standing proofs from Stages
0–4. They are **advisory**: the migrating session must re-verify the flag
mapping against the live code before each commit (line numbers drift with
every migration — grep the symbol). Analysis was done at master ≈ `ddbe4f878`
(post onStatus-family migration; some agents read `704a9cbbf`).

Migration order suggestion (dependencies noted inline): each dispatcher is an
independent behavior-preserving commit; normalization items are SEPARATE
commits with tests, collected in the final section of each dossier.

---

## mc_call_as2_handler_ng

All line numbers are for the current working tree (`SWFModernRuntime/src/actionmodern/action.c`, master @ `704a9cbbf`). They will drift with every migration — grep the symbol.

### 1. Site inventory

**Definition:** `action.c:71086–71215` (`static void`). Forward declaration at `action.c:26298`. **Single implementation** — grep across `SWFModernRuntime/src` + `include` finds no non-`_ng` variant and no graphics-mode duplicate in other files. Historically gated `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`; now un-gated (marker "`(was: #if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER) — also un-gated for AS2 mouse dispatch)`" just above 71086), so one shared copy compiles in all three build modes. The entry points that call it are pumped from all four front-ends: `swf_core.c` (NO_GRAPHICS), `swf_headless.c`, `swf.c` (browser-WASM), `input_events.c` — no per-mode ritual differences exist; migrating the one body covers everything.

**All 34 call sites (all in action.c, all inside these wrappers):**

| Caller | Line(s) | Event(s) | args |
|---|---|---|---|
| `actionFlushPendingOnChanged` | 36003 | onChanged (deferred) | 0 |
| `actionDispatchMCPress` | 71237 | onPress | 0 |
| `actionDispatchMCRelease` | 71264, 71266 | onRelease / onReleaseOutside | 0 |
| `actionFireButtonAS2Event` | 71302 | button-transition map: onRollOver/Out, onPress, onRelease, onDragOut/Over, onReleaseOutside | 0 |
| `actionDispatchMCMouseMove` | 71391–71402 | onDragOver/onRollOver/onDragOut/onRollOut | 0 |
| `actionDispatchMCMouseMoveGlobal` | 71419 | onMouseMove | 0 |
| `actionDispatchMCMouseDown` / `MouseUp` | 71433/71438, 71449/71454 | onMouseDown / onMouseUp (per-MC + root) | 0 |
| `aq_dispatch_deferred_roll` | 71649, 71654 | deferred onRollOut/onRollOver | 0 |
| `selection_do_focus_change` | 71720, 71729 | onKillFocus(newFocus) / onSetFocus(oldFocus) | **1** (MOVIECLIP or NULL) |
| `actionAdvanceTabFocus` | 72268, 72276 | onRollOut/onRollOver | 0 |
| `actionEndVirtualHoverOnMouse` | 72490 | onRollOut | 0 |
| `actionDispatchKey{Down,Press,Up}ToFocused` | 72507, 72524–72529, 72542 | onKeyDown, onPress/onRelease, onKeyUp | 0 |
| `actionWindowFocusLost` | 73102 | onRollOut | 0 |
| `actionTextControl{Backspace,Delete}`, `actionTextFieldInput` | 73381/73438, 73467/73522, 74073 | onChanged | 0 |

Only the two focus events ever pass an argument — this bounds the observable surface of the arg-marshalling path.

**Correction to the task premise / sibling dispatchers.** onEnterFrame, onLoad, onConstruct, onUnload do **NOT** route through this function. They have their own hand-rolled rituals (separate Stage-4 items): `actionDispatchEnterFrameHandlers` (35069, + root arm ~35201), `actionDispatchRootVarMapEnterFrame` (35277), `actionDispatchMCOnLoad` (35339), `actionDispatchRootOnLoad` (35746), `actionDispatchMCOnConstruct` (35496), and inline `onUnload` lookups (~23178, 23375, 23936, 33358, 34275). Critically, **the enterFrame dispatcher DOES `switchToFunctionVersion` (35119), DOES `actionSetCurrentContext(mc)` (35114), and DOES a base-clip switch gated on the CALLEE's version** (35137 reads `g_swf_version` after the switch — same accident-of-order as the pre-3d MC arms), and its type-1 arm pushes a local activation frame precisely to stop var/param leaks (comment 35151–35160). So the runtime today runs `onEnterFrame` with the callee's version and an activation frame, but `onPress` with the caller's version and no frame. That internal inconsistency is the strongest evidence for the normalization pass.

**Globals touched, in order.** Shared preamble: `g_execution_halted` (read), handler lookup via `getPropertyWithPrototype` on `mc->dynamic_props` (walks `__proto__`, so registerClass prototypes are found; runs at the *caller's* `g_swf_version` for case folding), `g_call_depth` pre-check vs `g_max_call_depth - 1` → sets `g_execution_halted` (71096), `g_this_stack`/`g_this_depth` push of the MOVIECLIP this_var (both branches, 71110), `g_inside_event_handler++` (71120). Type-2: HCALLOC registers → captured scopes (`scope_chain/is_with/mc`, is_with **copied**) → local scope alloc + `"this"` bind + **`scope_mc = mc`** (71144) → `g_call_depth++` → **`g_prev_executing_func` + `g_current_executing_func`** (71148–71151) → `g_event_this_mc` save/set (71153) → `advanced_func(..., registers, NULL)` → restore event_this, exec func, depth → pop captured+1 → release/free. Type-1: captured scopes → forward+clamp+pad eval-stack pushes (71189–71200, the Stage-0 fix) → bare `g_call_depth++/--` around `simple_func` → pop captured. Shared teardown: `g_inside_event_handler--`, `g_this_depth = saved`.

**Never touched:** `g_swf_version`/`global_object` (**no `switchToFunctionVersion` — confirmed, zero reads or writes anywhere in the body**), `g_current_context` (deliberate — comment 71102–71105: unqualified vars in handlers must hit the root variable table so `left.onPress` sets `isDown` visible to `right.onDragOver`), `g_current_sprite_obj`, super context, ctor context, override-this, scope-chain reset, `arguments`/`super` binds.

### 2. Current ritual per arm

**Type-2** (`function_type == 2`, 71122–71167):
1. Registers HCALLOC'd if `register_count > 0`.
2. Captured scopes pushed, `is_with` copied (not forced).
3. Fresh local frame: `"this"` bound by `setProperty`, `is_with = 0`, **`scope_mc = mc`** — this IS `INV_LOCAL_SCOPE_MC` territory, the first Stage-4 site outside the accessor family/default that associates the receiver MC with the local frame. (The migrated MC arm binds with `scope_mc = NULL`.)
4. Bare `g_call_depth++` (no max check here; the max-1 check already happened at entry).
5. `g_prev_executing_func = prev; g_current_executing_func = func` — **exactly `INV_EXEC_FUNC` semantics including the `g_prev_executing_func` write** (restore is current-only, matching the core's 15481). Unlike the MC arm, the flag is an *exact* match here, and it is load-bearing: generated `preload_arguments` prologues read `g_prev_executing_func` for `arguments.caller`.
6. `g_event_this_mc` saved, set to `mc` (`INV_EVENT_THIS_MC`).
7. `advanced_func(app_context, handler_args, handler_arg_count, registers, NULL)` — ABI this is **NULL**, so generated `preload_this` consumes `g_event_this_mc` → `INV_MC_THIS_NULL_PTR`. **No NULL check on `advanced_func`** (only `function_type == 2` is tested).
8. Teardown: event_this → exec func → depth-- → pop captured+1 → `releaseObject(local_scope)` → `FREE(registers)`. Order differs from the core's (core: exec → version → event → super); inert, nothing executes between.
9. `this` for the body: g_this_stack entry (pushed in preamble) *and* the scope binding *and* `g_event_this_mc` — all three agree (= mc).

**Type-1** (`function_type == 1 && simple_func != NULL`, 71168–71211):
1. Captured scopes pushed, is_with copied.
2. **No local frame at all** — no `"this"` bind (dead anyway per the standing rule), but also no activation object: a handler's positional params and `DefineLocal`s land in the enclosing chain (topmost captured scope, else root var_map). Same preserved shape as `nc_dispatch_onStatus`'s type-1 arm; opposite of the sibling enterFrame dispatcher's type-1 arm.
3. `this` binding for type-1: **via the preamble's `g_this_stack` push only** — `GetVariable("this")` hits the this-cell before any scope walk. This is the type1-mc-method-this-binding pattern; the dispatcher already has it right (the MC arm added `INV_THIS_STACK` for exactly this).
4. **No `g_event_this_mc`** on this branch (matches the MC arms' type-2-only gating).
5. Forward + clamp + pad marshalling to `param_count` (Stage-0 fix `9a8c6dce3`), byte-for-byte the same loop as the core's 15455–15464.
6. Bare `g_call_depth++/--` around `simple_func`. No exec-func tracking on this branch.
7. Pop captured scopes.

**Both:** no base-clip switch, no context switch of any kind, no version switch, no scope reset, no super/ctor context, result discarded.

### 3. Proposed InvokeOpts mapping per branch

Per-branch flags computed before the call, same shape as the MC arm:

```
Type-2: flags = INV_THIS_STACK | INV_CAPTURED_SCOPE | INV_LOCAL_SCOPE | INV_BIND_THIS
              | INV_LOCAL_SCOPE_MC | INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR | INV_EXEC_FUNC
Type-1: flags = INV_THIS_STACK | INV_CAPTURED_SCOPE
act_flags = 0 both; this_var = MOVIECLIP(mc); args = handler_args, num_args = handler_arg_count
```

- `INV_THIS_STACK` on **both** branches (unlike the MC arm's type-1-only gate) — the dispatcher pushes in the shared preamble. Core push is a faithful copy (`*this_var` into `g_this_stack`, restore `g_this_depth = saved`).
- `INV_EXEC_FUNC` on type-2 **only** — and here it is safe and exact (see §2 step 5); this dispatcher is the counterexample to "the exec-func swap always stays outside."
- `INV_MC_THIS_NULL_PTR`: yes — the type-2 call passes literal NULL today; core with this flag + MOVIECLIP this_var reproduces it (15408–15410).
- `act_flags = 0`: no `arguments`/`super`/named-this activation was ever built. Handlers that use `arguments` are DefineFunction2 with preload bits; the generated prologue handles it, fed by `INV_EXEC_FUNC`'s `g_prev_executing_func` — consistent with the "INV_ACT_ARGUMENTS requires core-owned INV_EXEC_FUNC" rule (we take neither for type-1, both-halves for type-2 via the prologue).
- **Stays outside the core:** handler lookup + FUNCTION type check + `func != NULL` (dispatch decisions); the entry depth pre-check — it is **NOT** `INV_DEPTH_GUARD` (it tests `>= g_max_call_depth - 1` *without incrementing* and halts; the core flag increments then tests `> max`) — keep verbatim; a bare `g_call_depth++/--` bracket around the core call (no halt check, as today); the `g_inside_event_handler++/--` bracket (must enclose the core call — `actionNextFrame`'s inline catch-up at 31774 keys off it); discarding the return value. Note the bare `++` moves slightly earlier for type-2 (today it fires after the scope pushes) — inert, no user code runs between `allocObject`/`setProperty` and the call.
- **ClosureFrame: not needed for migration.** No version switch, no context switch, no scope reset exist today — nothing for a frame to carry, and none of the four CF_CTX modes corresponds to "switch nothing." The caller/callee version-gate controversy is **moot at this site**: there is no base-clip switch to gate. If normalization pass (b) adds `switchToFunctionVersion` *alone*, plain `INV_VERSION_SWITCH` is safe here — the forbidden `INV_BASE_CLIP | INV_VERSION_SWITCH` combination cannot arise because `INV_BASE_CLIP` is not proposed. Only if a context/base-clip switch is *also* normalized later (to match the enterFrame sibling or Ruffle) would this become a ClosureFrame arm with an arm-computed gate.

### 4. Divergences

Vs the mapped flags: none — the mapping above is exact, including loop bodies. Vs the full ritual (each a deliberate skip to record):

1. **No `switchToFunctionVersion` — observable, proven bug-class** (Stage 0 `60070d96a` on the timer path), the flagged normalization candidate. A v6-defined handler fired while v7 bytecode/context is current runs with v7 coercion semantics and the v7 `_global` group. Also inconsistent with the sibling enterFrame dispatcher, which switches. **Preserve in migration; normalize in a separate commit** (§7).
2. **No base-clip / receiver context switch — observable, deliberately preserved.** The 71102 comment and the cross-handler shared-variable behavior (`left.onPress` → `right.onDragOver`) are load-bearing; input-driven avm1 tests lock it. Do not normalize without Ruffle-verified evidence.
3. **No scope-chain reset** (caller's chain remains under the captured scopes). Mostly inert: every caller runs from the input pump / deferred queues after frame scripts return, so the chain is at its base. Preserve.
4. **Type-1 has no local activation frame** — handler params and `var` locals leak into the enclosing scope/root. Same divergence NC preserved; the enterFrame sibling *fixed* it for its own type-1 arm. Normalization candidate #2, needs a Ruffle-verified test.
5. **Type-2 pushes `g_this_stack`** where the MC arm gates that to type-1. Inert in practice (all three this-channels agree = mc) but preserved exactly by `INV_THIS_STACK` on both branches.
6. **`g_event_this_mc` only on type-2** — matches the MC arms; the core would set it for both, so the per-branch flag gate is required. (Stage-4 prompt's open question "should a type-1 body see it" = normalization, not migration; a type-1 body itself can't consume it, only natives it calls could.)
7. **Type-2 `advanced_func` called with no NULL check** — unchecked-call class. The runtime-wide audit guarantees no type-1 has a live `advanced_func`, but not that every `function_type == 2` has a non-NULL one; the core's strict dispatch fixes this for free. Almost certainly unreachable today; don't credit it as found-in-the-wild.
8. Teardown-order differences (event_this before exec-func; `g_this_depth` restored after `g_inside_event_handler--` today, before it under the core-bracket shape) — inert, no code executes between.

### 5. Type-1 clamp/pad + NULL-call status

Clean, post-Stage-0. `9a8c6dce3` made the type-1 arm push **forward order, clamp extras, pad with undefined to `param_count`** — textually the same loop as the core's canonical copy, so migration is a verbatim subsumption (instance already counted; expect **no new instance** here). `simple_func` is NULL-checked in the branch condition. The one remaining unchecked call is type-2 `advanced_func` (§4.7). `regression/mc_event_type1_args` guards the arm end-to-end (hand-assembled SWF8 `DefineFunction` onSetFocus handlers with 1 and 2 params, fired via `Selection.setFocus` — no input injection needed; validates arg delivery, padding, and stack hygiene).

### 6. Reachability

- **Type-2 branch: heavily covered.** Any `.as`-compiled test assigning these handlers is DefineFunction2. Input-driven avm1 tests (runner supports `input.json`, `verify_output.py:445`): `mouse_events`, `mouse_events_visible_enabled`, `mouse_hover_events_while_dragging`, `drag_over_from_outside`, `drag_over_without_startdrag`, `focus_mouse*`, `focus_keyboard_press`, `focus_remove`, `focus_visibility_change`, `tab_ordering_events*` (+ the rest of the tab_ordering cluster), `edittext_input` / `edittext_tab_focus` / `edittext_programmatic_focus` (onChanged/onSetFocus), `clip_event_propagation_order`, `button_keypress_vs_textinput`; gnash `misc-ming.all/ButtonEventsTest` (the named key test for `g_inside_event_handler`). Focus events also fire without input via `Selection.setFocus`.
- **Type-1 branch: `regression/mc_event_type1_args` only** (by design — MTASC can't emit it for SWF6+). Adequate as the lock.
- **Per-caller coverage gaps, mark "needs probe":** `actionFireButtonAS2Event` (button-mode sprite transitions — games exercise it; unclear whether any suite test does), `actionDispatchKey{Down,Up}ToFocused` (suite key tests may route via Key listeners/broadcaster instead), `actionFlushPendingOnChanged` (deferred-onChanged flush), `aq_dispatch_deferred_roll`, `actionWindowFocusLost`, `actionEndVirtualHoverOnMouse`. Probe method per the Stage-4 prompt: file-writing probe per branch, run the candidate cluster once.
- Of the Stage-4 prompt's sensitive clusters, `custom_clip_methods` and `function_base_clip*` exercise the *MC-method arm*, not this dispatcher; the relevant sensitive set here is the focus/mouse/tab/edittext cluster above.

### 7. Proposed repro/lock test design

- **Migration:** no new test needed. `mc_event_type1_args` locks the type-1 arm; the input-driven cluster locks type-2. Do the standard A/B: build old-vs-new `action.c`, byte-diff actual outputs across `mouse_events`, `focus_mouse`, `tab_ordering_events`, `edittext_input`, `ButtonEventsTest`, `mc_event_type1_args`. If unsure the type-1 no-local-frame shape survived, instrument rather than add a pass-both-ways test.
- **Normalization (a): missing `switchToFunctionVersion` — `regression/mc_event_cross_swf_version`, modeled on `timer_cross_swf_version`:** host `test.swf` (SWF7) does `createEmptyMovieClip("holder", 1)` + `loadMovie("child.swf", "_level0.holder")`. Child (SWF6) creates a target (e.g. `createTextField("t1", ...)`) and assigns `t1.onSetFocus = function(old) { trace("cb:[" + u + "]" ); }` (v6 movie → `func->swf_version = 6`). **The host** (v7 bytecode, so `g_swf_version == 7` at dispatch time) then calls `Selection.setFocus(_level0.holder.t1)` on a later frame. Expected (Flash/Ruffle: functions run at their defining movie's version): `cb:[]`; current runtime: `cb:[undefined]`. Firing from the *host* is essential — setFocus from child bytecode would already have v6 installed and mask the bug. onSetFocus is the right event: synchronous, argument-carrying, no `input.json`. Verify fail-before by running against the parent commit's `action.c`. Implementation is one flag (`INV_VERSION_SWITCH`), no ClosureFrame (no INV_BASE_CLIP present — hazard cannot arise).
- **Normalization (b), optional/later: type-1 activation frame.** Test that a type-1 handler's param name and a plain assignment inside the handler do not clobber/create root variables — but confirm intended behavior against Ruffle first; the enterFrame sibling's comment (35151) documents the leak as a real user-visible bug for that path.

### 8. Risks / open questions

- **Heat:** this dispatcher is per-input-event, not per-frame — the per-frame MC event path is the *sibling* enterFrame dispatcher. But `actionDispatchMCMouseMove`/`MouseMoveGlobal` iterate the whole `child_mc_cache` per mouse-move and call this function per MC; the dominant cost is the `getPropertyWithPrototype` miss (early return before any invoke), which migration does not touch. Added cost is one call frame + flag tests on the handler-present path only. Per plan §5: if any Stage-4 site warrants a fresh measurement it is this family — measure the core's own `Ir` on **Minesweeper** (onPress/onRollOver-heavy; see the minesweeper-radio-click memory), never N.
- **`g_inside_event_handler` invariants:** the bracket must enclose the core call, and the dispatcher must continue *not* setting `g_current_sprite_obj` — `actionNextFrame`'s inline catch-up (31766–31796) depends on both (`ng_isInsideSprite()` false; key test ButtonEventsTest). The core never touches `g_current_sprite_obj`, so the migration is safe; but if a later normalization adds a ClosureFrame here, note `leaveClosureFrame` restores `g_current_sprite_obj` and CF_CTX modes clear it — re-verify the goto-catch-up path.
- **Handler-name lookup version:** case folding in `getPropertyWithPrototype` runs at the caller's version and stays outside the core (dispatch decision). If version-switch is normalized, the lookup still happens pre-switch. Check what Ruffle does before declaring parity.
- **onChanged arity:** all onChanged callers pass 0 args; Flash/Ruffle pass the changed TextField. Separate parity question — out of scope, but the migration should not accidentally "fix" it.
- **Open question for pass (b):** whether normalizing the version switch should also bring `actionDispatchEnterFrameHandlers`/`OnLoad`/`OnConstruct` into the same adapter (they are near-clones of this ritual *plus* version/context switches, with the callee-version base-clip gate accident). Consolidating them onto `mc_call_as2_handler_ng` post-migration would delete ~200 lines and one gate inconsistency — but each is its own behavior-preserving commit, and the enterFrame dispatcher has extra eligibility machinery that must stay outside.
- **No blockers found.** This site is a cleaner fit for the core than the MC arm was: no version/context switching to route around, `INV_EXEC_FUNC` matches exactly, and the type-1 marshalling is already the canonical loop. The only novel flag use is `INV_LOCAL_SCOPE_MC`, already core-supported.

---

## Coercion paths (objectCallValueOf / objectCallToString / toPrimitive / convertFloat) + call_function_with_this

All line numbers are for `/home/robert/CC/SWFRecomp-CC/SWFModernRuntime/src/actionmodern/action.c` at `704a9cbbf` (they will drift; grep the symbol).

### 1. Site inventory

Exact names (the prompt's "toPrimitive" is **`objectToPrimitive`**):

| Function | Definition | Dispatch branches inside it |
|---|---|---|
| `objectCallValueOf(app_context, obj_var, found)` | 14309 | (a) virtual-getter `valueOf` (addProperty) at 14346–14379; (b) plain-property `valueOf` function at 14381–14449; (c) stored-primitive / non-callable short-circuits (no dispatch) |
| `objectCallToString(app_context, obj_var, found)` | 14481 | (a) NATIVE_ARRAY join fast path (no dispatch) 14533; (b) plain-property `toString` function at 14570–14647; (c) virtual-getter `toString` at 14651–14693; (d) found-but-not-callable → undefined 14702 |
| `objectToPrimitive(app_context, obj_var, out_success)` | 14712 | (a) `valueOf` function 14783–14834; (b) `toString` fallback function 14850–14889; stored-primitive short-circuits |
| `convertFloat(app_context)` — OBJECT/FUNCTION/ARRAY arm | 29665; object arm 29850–30009 | (a) plain `valueOf` function 29874–29921; (b) virtual-getter `valueOf` 29934–29981 |
| `call_function_with_this(app_context, func, this_obj, this_is_mc, args, arg_count)` | 72817 (static, void return) | type-2 arm 72844–72898; type-1 arm 72899–72926 |

**Callers.**
- `objectCallValueOf` (7 sites): `actionASSetPropFlags_func2` (4869/4875 — XML args, minor), `tfCoerceInteger/NonNegInt/Unsigned/Float` (17093/17146/17215/17260), `actionAdd2` (30242/30256), `varToDoubleSWF` (60594), `actionCallMethod` duplicateMovieClip-depth coercion (67098).
- `objectCallToString` (~35 sites): `varToStringBufFull` (8615), `colorGetMCName` (11003), `tfCoerceString/Align` (17287/17346), `convertString` (29324 array own-toString, 29405 object), `actionAdd2` (30240/30296/30321/30352/30377), `actionStringEquals` (31513/31526), `actionTrace` (32027/32216/32234/32301), `actionStringGreater/Less` (45735/45748, 46011/46024), `actionSetMember` (46917/48686/48945/49483), `uncaughtException` (56771), `varToStringBuf` (60416), `callArrayMethod` join/sort (61363/62104), `stringArgToU16` (62613), `actionCallMethod` string-method arg coercion (64302/64977/65246/67065/68392).
- `objectToPrimitive` (4 opcodes, 8 sites): `actionLess2` (30656/30668), `actionGreater` (30735/30746), `actionEquals2` (45457/45458, 45492/45506).
- `convertFloat` function-calling arm is reached from ~40 `convertFloat` call sites; the ones that can carry OBJECT/ARRAY/FUNCTION are `actionAdd2`'s numeric fallback (30410/30419 — deliberately calls valueOf a *second* time after `objectCallValueOf` returned non-primitive, comment 30214), `actionLess2`/`actionGreater` numeric legs (30697+/30774+), increments/arith opcodes, `coerceVarToNumber` (14945 — MC `_x/_y/...` setters), the `GET_F64_VIA_CONVERTFLOAT`-style macro at 13187, and `tfCoerce*` fallthroughs.
- `call_function_with_this`: **exactly one caller** — `handle_asfunction` (73023, asfunction: hyperlink click from `actionTextFieldDragEnd`). No callers outside action.c (it is static; verified repo-wide).

**Identity-thunk checks (all stay in the arms — dispatch decisions / result fixups, not invocation steps):**
1. `objectCallToString` 14639–14645: **post-call** `func->advanced_func == (Function2Ptr)builtin_array_method` → undefined result becomes `""` (Array.prototype.toString on non-array). Must run *after* the core returns.
2. `actionCallMethod` string-primitive arm 64716–64719: `builtin_stub_method` / `builtin_prim_wrapper_toString` / `builtin_wrapper_valueOf` compared by address → bypass builtins, dispatch only user overrides. Adjacent to, not inside, these paths — but it is what keeps the wrapper thunks out of the coercion sensitive tests.
3. `builtin_wrapper_valueOf` (7393) / `builtin_prim_wrapper_toString` (7412) themselves are type-2 natives reading `valueOf_value` off `this_obj`; when a coercion path finds them via the prototype walk they are invoked like any type-2 function (identity does not matter *inside* these five paths — only the post-call `builtin_array_method` fixup does).

**Globals touched, in order:**
- `objectCallValueOf`/`objectCallToString` main branches: `g_current_context` (save) → `switchToFunctionVersion` (`g_swf_version`, `global_object`) → `actionSetCurrentContext(func->base_clip)` **unconditionally when non-NULL, no SWF6 gate, no dead-clip re-resolve** → `scope_chain/scope_depth` (captured scopes, real `is_with`) → `g_current_executing_func` (save/set; **`g_prev_executing_func` NOT written**) → `g_this_stack/g_this_depth` (push OBJECT(obj), both type-2 AND type-1) → call → symmetric restores.
- `objectCallValueOf` getter branch: **nothing at all** — invokes the getter via `invokeVirtualGetter` (already core-backed since Stage 2), then calls the returned function bare: no scopes, no this, no version, no exec-func.
- `objectCallToString` getter branch: captured scopes only.
- `objectToPrimitive` both branches: `g_this_stack` push **for type-1 only** (comment 14799–14803); type-2 gets `obj` as the ABI `this_obj` and nothing else. No scopes, no version, no context, no exec-func.
- `convertFloat` both branches: captured scopes only. **No this push for either type** — a type-1 `valueOf` body reading `this` here sees the *caller's* `this` (the exact bug the 14799 comment fixed in `objectToPrimitive` but that fix was never propagated to `convertFloat`).
- `call_function_with_this` type-2: `g_this_stack` push → captured scopes → local scope with `"this"` bound and `scope_mc = receiver MC` → `g_current_context = func->base_clip` gated on **caller's** `g_swf_version >= 6` (raw pointer, no re-resolve) → `g_event_this_mc` → `g_call_depth++` → `g_prev_executing_func`/`g_current_executing_func` (both written — unlike the coercion paths) → call with `this_obj = NULL` for MC receivers → restores. Type-1: this push → `pushVar` each arg forward, **no clamp/pad** → captured scopes → `g_event_this_mc` → `g_call_depth++` → call → restores. Entry guard: `g_call_depth >= g_max_call_depth - 1` → `g_execution_halted = 1`, return.

### 2. Current ritual per arm

| Step | oCVO/oCTS main | oCVO getter | oCTS getter | objectToPrimitive | convertFloat (both branches) | c_f_w_t t2 | c_f_w_t t1 |
|---|---|---|---|---|---|---|---|
| depth guard | — | — | — | — | — | manual halt-check + bare `g_call_depth++` | same |
| this-stack push | YES (t1+t2, OBJECT(obj)) | — | — | t1 only | — | YES | YES |
| super ctx | — | — | — | — | — | — | — |
| captured scopes | YES (real is_with) | — | YES | — | YES | YES | YES |
| local scope / bind this | — | — | — | — | — | YES + bind + scope_mc | — |
| base clip | YES, **ungated**, raw ptr | — | — | — | — | YES, caller's ver ≥6, raw ptr | — |
| version switch | **YES** (`switchToFunctionVersion`) | — | — | **NO** | **NO** | **NO** | **NO** |
| event_this_mc | — | — | — | — | — | YES | YES |
| exec-func | current only (no `g_prev_`) | — | current only (toString main) / — | — | — | YES incl. `g_prev_` | — |
| t1 args | none pushed | none | none | none | none | n/a | forward, no clamp/pad |
| t1 return | `result = cast(simple_func)(ctx)` — **identical to core** | same | same | same | same | n/a | **discarded** (void) |
| ABI this to advanced_func | `obj` | `obj` | `obj` | `obj` | `obj` | NULL if MC else obj | n/a |
| NULL-check dispatch | strict both arms (type && ptr) | strict | strict | strict | strict | strict | strict |

Note the Stage-4 prompt's line "the coercion paths still skip `switchToFunctionVersion` entirely" is **stale/half-true**: `objectCallValueOf` and `objectCallToString` main branches DO switch (14394/14581); `objectToPrimitive`, `convertFloat`, `call_function_with_this`, and all getter sub-branches do NOT. Confirm-per-path result: the *skip* is real only for the latter group, and normalizing them is a separate commit (model: `regression/timer_cross_swf_version`).

Receiver unwrap quirks that stay in the arms (pre-dispatch policy, not ritual): FUNCTION receivers → `own_props` (valueOf: return function itself, no dispatch; toString: own-prop-only lookup); ARRAY receivers → `arr->props` with **own-property-only** lookup in oCVO/oCTS but **full proto walk** in `objectToPrimitive`/`convertFloat` (deliberate — gnash toString_valueOf-v5:469); `_global` → undefined in `objectToPrimitive`; `this_var` for an ARRAY receiver is OBJECT-typed wrapping `arr->props`, not the array.

### 3. Proposed InvokeOpts mapping per branch

All five sites keep: property lookup + found-semantics, receiver unwrap, stored-primitive/non-callable short-circuits, and the `builtin_array_method` post-fixup **outside/around** the core. Only the "found a callable ASFunction" tail migrates.

- **oCVO / oCTS main branch**: `flags = INV_THIS_STACK | INV_CAPTURED_SCOPE`, `act_flags = 0`, `this_var = OBJECT(obj)`. Kept in the arm: `switchToFunctionVersion` + the **ungated** `actionSetCurrentContext(func->base_clip)` bracket (INV_BASE_CLIP cannot reproduce "no SWF gate + no re-resolve", and combining INV_BASE_CLIP with INV_VERSION_SWITCH is forbidden — the gate question doesn't even arise since there is no gate); the exec-func swap **stays manual in the arm** because the core's INV_EXEC_FUNC also writes `g_prev_executing_func`, which this arm never did (same judgement as the three Stage-3 arms; `arguments.caller` hazard). oCTS additionally keeps the `builtin_array_method` → `""` fixup after the core returns.
- **oCVO getter branch**: `flags = 0`, `this_var = OBJECT(obj)` (core derives `this_ptr = obj` for the ABI; with all flags clear nothing else happens — exact match).
- **oCTS getter branch**: `flags = INV_CAPTURED_SCOPE`, `this_var = OBJECT(obj)`.
- **objectToPrimitive both branches**: gate in the arm like `lc_dispatch_method` gates INV_BASE_CLIP: `flags = (func->function_type == 1) ? INV_THIS_STACK : 0`, `this_var = OBJECT(obj)`. Do NOT pass INV_THIS_STACK unconditionally — pushing `g_this_stack` for a type-2 callee is new state visible to nested calls via actionGetVariable's early this-cell path (normalization, not migration).
- **convertFloat both branches**: `flags = INV_CAPTURED_SCOPE`, `this_var = OBJECT(obj)`. Do NOT add the missing type-1 this push during migration — it is the obvious first normalization commit (see §4/§7).
- **call_function_with_this**: **keep as a thin wrapper over the core** (recommendation), not dissolved: the name documents the asfunction contract, the entry halt-check and this_var construction are genuinely caller-side, and the plan lists it as its own Stage-4 dispatcher. Per-type flags, lc-style:
  - type-2: `INV_THIS_STACK | INV_CAPTURED_SCOPE | INV_LOCAL_SCOPE | INV_BIND_THIS | INV_LOCAL_SCOPE_MC | INV_BASE_CLIP | INV_EVENT_THIS_MC | INV_EXEC_FUNC | INV_MC_THIS_NULL_PTR` — INV_EXEC_FUNC is correct here (this arm already writes `g_prev_executing_func`, 72879); INV_BASE_CLIP's caller-version gate matches because no INV_VERSION_SWITCH is passed; INV_LOCAL_SCOPE_MC exists precisely for this site (plan §Stage-2 note: "only `call_function_with_this` associates the receiver MC").
  - type-1: `INV_THIS_STACK | INV_CAPTURED_SCOPE | INV_EVENT_THIS_MC` (event-this set in BOTH arms today, unlike the MC arms).
  - Keep the manual `g_call_depth++/--` bracket + entry halt-check outside (INV_DEPTH_GUARD's ++-then-check is not the same as the halt-at-depth-minus-one check). Return value stays discarded; wrapper stays void.
  - Also fixes for free: the type-2 local-scope leak pattern is absent here (this arm releases correctly), but the type-1 no-clamp/no-pad is the real fix (see §5).

### 4. Divergences

**Vs. mapped flags (per site):**
- oCVO/oCTS main: core INV_EXEC_FUNC would add the `g_prev_executing_func` write → *observable via `arguments.caller` in a type-2 valueOf with preload_arguments* → keep swap in arm (preserve). Core's this-push happens before version switch vs. arm's inside the type branch → inert (no reader in between). Scope restore by decrement vs. saved-value assignment → inert. Base-clip set before vs. after captured-scope push → inert.
- objectToPrimitive: INV_THIS_STACK for type-2 would be new → gated in arm (preserve).
- convertFloat: no divergence under the proposed minimal flags; the *absent* type-1 this push is bug-class (matches neither sibling path) — normalize separately.
- c_f_w_t: INV_DEPTH_GUARD vs. manual halt-check → keep manual (preserve; the halt flag side effect differs).
- All four coercion sites, type-1 with `param_count > 0`: core pads with undefined where today the DefineFunction prologue pops **the caller's live stack** (in `convertFloat`'s case, the operand being converted sits on the stack top — it would be consumed). This is the TYPE1 clamp/pad fix class: accept as the migration's known behavior change, with a repro test (§7).

**Between the coercion paths themselves (preserve all in migration; candidates for later normalization):**
1. Version switch + base clip: oCVO/oCTS main YES; objectToPrimitive/convertFloat NO. So `("" + obj)` runs valueOf in the callee's SWF version but `(obj < 1)` via Less2 does not.
2. this push: oCVO/oCTS both types; objectToPrimitive type-1 only; convertFloat never.
3. Captured scopes: oCVO/oCTS main + convertFloat YES; objectToPrimitive NO (a closure valueOf loses its scope chain under Equals2 but not under Add2).
4. Lookup order: oCVO checks the virtual getter **before** the plain property; oCTS checks the plain property **first**, getter second; convertFloat plain-first, getter second.
5. Array lookup: own-only in oCVO/oCTS vs. full proto walk in objectToPrimitive/convertFloat (load-bearing, gnash toString_valueOf-v5).
6. exec-func tracking: oCVO/oCTS main only.
7. Getter sub-branches: oCVO's is bare, oCTS's pushes captured scopes.

### 5. Type-1 clamp/pad + NULL-call status

| Site | Type-1 args today | NULL-call |
|---|---|---|
| objectCallValueOf (both branches) | pushes nothing; `param_count>0` pops caller's stack (garbage-bind/underflow) — **latent on a live path** (gnash ming-compiled type-1 valueOf/toString are DefineFunction, but always 0-param in the suite) | safe — strict `type==1 && simple_func != NULL` everywhere |
| objectCallToString (both branches) | same | safe |
| objectToPrimitive (both branches) | same | safe |
| convertFloat (both branches) | same, and the popped value would be **the operand under conversion** | safe |
| call_function_with_this type-1 | pushes `arg_count` forward, **no clamp to `param_count`, no pad**: 1 asfunction arg into a 0-param handler leaks a stack slot; a 2-param handler underflows | safe (strict both arms) |

None of these five sites has the `lc_dispatch_method`-style unchecked `else` NULL-call; the known NULL-call hazard class does not apply here.

### 6. Reachability — which tests lock each path

Strongest guards (all currently passing; names resolve in avm1 unless noted):
- **`coerce_to_primitive_resolve`** — locks oCVO/oCTS plain-function branch (obj1), BOTH virtual-getter branches via `addProperty` (obj2 — including getter-returns-function indirection), and throwing getters (obj3), through both Add2-numeric and trace-string entry points.
- **`coerce_to_object_monkeypatch`** — locks the primitive-wrapper world: `builtin_wrapper_valueOf` / `builtin_prim_wrapper_toString` installation and the identity-bypass at 64716, with `_global.__proto__` getter monkeypatching layered on top. The most sensitive single test for this stage.
- **`add2`** — locks Add2's valueOf-then-toString order, valueOf-returns-string re-dispatch, valueOf-returns-object → convertFloat second call (objValue3), valueOf-returns-undefined (objValue4). Plus `add`, `add_swf4`, `add_swf5` for version gates.
- **`equals2_swf5/6/7`, `equals`, `equals_swf5`** — lock `objectToPrimitive` via actionEquals2 (including the out_success=0 "still an object" contract at 14831).
- **`lessthan2_swf5/6/7`, `greater_swf6/7`, `greaterthan_swf5/swf8`** — lock objectToPrimitive + convertFloat via Less2/Greater.
- **`string_coercion`, `undefined_to_string_swf6` (regression)** — lock convertString/oCTS found-semantics (`[type Object]` vs `[object Object]`, 14696–14702).
- **gnash `toString_valueOf-v5/-v6/-v7/-v8`, `Number-v5..v8`, `String-v*`, `Boolean-v5`** (`--tests-dir=.../from_gnash`) — the only suite reaching the coercion paths with **type-1 (DefineFunction) callees** and the version-dependent NaN gates in convertFloat (29988–30005). These are the strongest guards for the type-1 branches.
- **`set_property_values`** — locks `coerceVarToNumber` → convertFloat object arm for MC numeric setters.
- **`boxed_primitives`, `primitive_type_globals`, `string_methods*`, `string_prim_method_type1_args` (regression)** — lock the identity-bypass and wrapper-thunk perimeter.
- **`call_function_with_this`: ZERO coverage.** No test anywhere references `asfunction` (grepped all suites). It requires a hyperlink click in a rendered text field; it is unreachable by the trace suites. This is the weakest-guarded site of the whole stage.

### 7. Proposed repro/lock test design

Existing coverage suffices for every branch's *current* behavior except two genuine gaps:

1. **Type-1 valueOf/toString with declared params** (the clamp/pad exposure common to all four coercion sites). Design: regression test `coerce_type1_args` — SWF6 via MTASC won't work (mtasc emits DefineFunction2); use the same tool that produced the other type-1 guards (see `regression/fn_call_type1_args` for the recipe — likely makeswf/ming or hand-assembled). Body: `obj.valueOf = function(a, b) { trace(a); trace(b); return 5; }; trace(obj + 1); trace(obj < 10); trace("" + obj);` with sentinel values parked on the stack (e.g. computed inside an expression) so a mis-pop is observable — expect `undefined/undefined/6/true/5` after the fix, garbage/corruption before. Verify it FAILS against the parent commit per the standing rule. One test covers oCVO, objectToPrimitive, and convertFloat (all three entry points in one script) plus oCTS via `"" + obj` with only a toString.
2. **`call_function_with_this` type-1 pad** — a repro needs a clickable asfunction link; if the harness cannot inject the click (no existing test does), document the fix in the migration commit as measured-unreachable-by-suite (bdRectangleGetter precedent: fix during migration, do not credit as found-in-the-wild, do not hunt a natural repro).

### 8. Risks / open questions

- **Perf: this is the hottest family in the stage — but the hot part does not move.** Every Add2/equality/string coercion runs the *lookup* (`getPropertyWithPrototype("valueOf")`), which stays in the arms; the core is entered only when an object operand actually has a callable valueOf/toString, which in games is rare (game string-building concatenates primitives and MOVIECLIPs — the MOVIECLIP convertFloat case never dispatches). Per plan §5: measure `invokeFunctionValue`'s own `Ir` on **Minesweeper** via `callgrind_annotate --threshold=100`, never PROGRAM TOTALS, never on N. Confirm Minesweeper even reaches these tails before treating any delta as signal (it may not — the `actionCallFunction` precedent).
- **No depth guard on any coercion path** (pre-existing): `valueOf = function(){ return this + 0; }` recurses convertFloat→valueOf with no `g_call_depth` increment → C-stack overflow (64 KB WASM stack). Migration must NOT add a guard (behavior-preserving); flag as a normalization question — but note the accessor recursion tests (`virtual_property_recursion_*`) recurse on purpose, so any guard choice needs those run.
- **`__resolve` re-entrancy**: the `getPropertyWithPrototype("valueOf")` lookup itself can fire `__resolve` (already core-backed via `invokeResolveFunction`) *before* the arm's ritual begins — `coerce_to_primitive_resolve` locks this ordering. Migration doesn't touch the lookup, so this should be inert; still run the full `coerce_*`/`object_resolve` cluster in one `verify_output.py` invocation.
- **Stale doc**: update the Stage-4 prompt's "coercion paths skip switchToFunctionVersion" line when landing — it's true only for objectToPrimitive/convertFloat/c_f_w_t; oCVO/oCTS main branches have switched for some time.
- **Normalization queue (each its own commit + test, NOT part of migration)**: (a) version-switch + captured scopes for objectToPrimitive, version-switch for convertFloat/c_f_w_t-type-1 (cross-version test modeled on `timer_cross_swf_version`); (b) convertFloat's missing type-1 this push (the un-propagated 14799 fix — test: type-1 valueOf using `this` reached via `obj < 1`'s numeric leg); (c) the getter-vs-plain lookup-order asymmetry between oCVO and oCTS — probably permanent (matches distinct Ruffle code paths), document rather than change; (d) whether oCVO/oCTS's ungated raw-pointer base-clip switch should adopt ClosureFrame-style dead-clip re-resolution (UAF-adjacent today if a function whose base clip was destroyed is used as valueOf).
- **Open question**: `objectCallValueOf`'s virtual-getter branch runs the *returned* function with literally no ritual (not even captured scopes), while oCTS's twin pushes them. A closure returned from a valueOf getter is the discriminating case; no test covers it. Cheap to lock during migration with flags=0 vs INV_CAPTURED_SCOPE exactly as today — do not silently equalize.

---

## actionEI_callInternalInterface

### 1. Site inventory

**Definition:** `SWFModernRuntime/src/actionmodern/action.c:6087-6232`. Declared in `SWFModernRuntime/include/actionmodern/action.h:497`.

**Supporting state:** `EICallback` registry (`action.c:5567-5576`, `MAX_EI_CALLBACKS=32`; each entry: `name[128]`, `this_obj` ActionVar copied verbatim from `addCallback`'s arg[1], `func` ASFunction*). Populated only by `actionEI_addCallback` (`action.c:5595-5652`), which requires `g_external_call_handler != NULL` and `args[2].type == FUNCTION`.

**Call sites (all of them):**
- `SWFRecomp/wasm_wrappers/main.c:72` — `swf_ei_call_internal(name, arg)` (EMSCRIPTEN-only host→AS bridge, `Module.ccall` from a JS timer in the ASYNCIFY quiescent window; ≤1 string arg). Production path (flashPanel / AP Rando bridge). Not CI-observable.
- `ruffle-tests/tests/swfs/avm1/external_interface/test_harness.c:263,326,392` — mock provider; calls `"parrot"` (1 arg), `"callWith"` (2 args), and re-entrantly from inside the mock `ExternalInterface.call` handler (`"reentry"` → line 263).
- `ruffle-tests/tests/swfs/regression/ei_type1_args/test_harness.c:56,63` — the Stage-0 guard; type-1 callee, 2-arg and 1-arg calls.
- Hits under `SWFRecomp/tests/*/build/` and `build_graphics_host/` are build artifacts of the wasm wrapper, not distinct sites.

**Globals touched, in order:** `g_ei_callbacks`/`g_ei_callback_count` (read) → `g_call_depth` (++/guard; `g_execution_halted` write on trip) → per arm: eval stack (type-1 only, PUSH/pushVar), `scope_chain`/`scope_is_with`/`scope_mc`/`scope_depth`, `g_current_context` (save/switch/restore), `g_swf_version` (read only, gates base clip), var write via `setVariableByName` (type-1 only) → `g_call_depth--`. **Never touched:** `g_this_stack`/`g_this_depth`, super context, version switch/`global_object`, `g_event_this_mc`, `g_current_executing_func`/`g_prev_executing_func`, `g_override_this`, ctor context, `g_special_depth`.

### 2. Current ritual per arm

**Shared prologue (6092-6119):** linear registry scan by `strcmp`; return undefined if no `in_use` entry or `cb->func == NULL`. Depth guard: `g_call_depth++`, `> g_max_call_depth` → `g_execution_halted = 1`, decrement, return undefined (this is exactly `INV_DEPTH_GUARD`'s shape, including the halt — unlike LC's bare bracket). `this_obj` = pointer from `cb->this_obj` iff its type is OBJECT **or** MOVIECLIP, else NULL. No `g_execution_halted` check at entry.

**Type-2 branch (6123-6160), gated `function_type == 2 && advanced_func != NULL`:**
1. `registers = HCALLOC(register_count)` if any.
2. Push fresh local frame **FIRST** (`is_with=0`, `scope_mc=NULL`) — 6130-6136.
3. Push captured scopes **ON TOP**, `scope_is_with` **forced to 1** unconditionally (6142), `scope_mc` from `func->captured_scope_mc`. → Both quirks: local-under-captured **and** forced-with.
4. Base-clip switch: `if (g_swf_version >= 6 && func->base_clip)` — gated on the **caller's** live version (no version switch exists on this path).
5. `advanced_func(app_context, args, (u32)arg_count, registers, this_obj)` — receiver is the raw `this_obj` pointer; **no** name bind of `this`, no this-stack push, no arguments object (a `preload_arguments` prologue reads a stale `g_prev_executing_func` here — current behavior).
6. Teardown: restore context → pop `captured_count` → pop local → `releaseObject(local_scope)` → `FREE(registers)`.

**Type-1 branch (6161-6224), gated `function_type == 1 && simple_func != NULL`:**
1. Marshal args **first** (before any scope push): forward order, clamp extras, pad to `param_count` with undefined (6171-6182) — the post-`d8abc5c0a` canonical loop, textually identical to the core's.
2. Local frame pushed first, captured on top with `is_with` forced 1 (6184-6198) — same double quirk.
3. Base-clip switch, same caller-version gate (6200-6202).
4. Build `this_var`: **`OBJECT`-typed** if `this_obj != NULL` (even when `cb->this_obj` was MOVIECLIP — the MC pointer gets an OBJECT tag), else UNDEFINED; `setVariableByName("this", &this_var)` (6205-6215). Because every captured frame is forced `is_with=1` and `getCurrentLocalScope()` skips with-frames, this bind lands on the **callee's local frame** (the plan §1's older claim that it lands in the topmost captured WITH scope is wrong; the step-5b landing note already corrected the mechanism).
5. The single type-1 cast call (6217).
6. Teardown: restore context → pop captured → pop local → release.

**Fallthrough `else` (6225-6228):** returns undefined. This is already strict dispatch — there is no unchecked `simple_func`/`advanced_func` call anywhere in this site.

**Version switch: absent** in both arms. **Depth guard: symmetric** (`g_call_depth--` at 6230 on all paths past the guard).

### 3. Proposed InvokeOpts mapping per branch

Stays **outside** the core: registry scan + early return; `this_obj` extraction and `this_var` construction (OBJECT tag or UNDEFINED, exactly as today — do **not** let the MOVIECLIP tag through, see divergence D2); the per-branch flag gate. No pointer-identity thunk checks exist at this site and none are needed.

Common flags, both branches:
```
INV_DEPTH_GUARD | INV_CAPTURED_SCOPE | INV_FORCE_CAPTURED_WITH |
INV_LOCAL_SCOPE | INV_LOCAL_SCOPE_UNDER_CAPTURED | INV_BASE_CLIP
```
- `INV_DEPTH_GUARD`: EI's guard is byte-equivalent to the core's (increment, max-check, halt, decrement, undefined) — unlike the LC family, the guard moves **into** the core here; no bare `g_call_depth++/--` bracket remains outside.
- `INV_FORCE_CAPTURED_WITH`: **verified — EI does force `is_with=1`** on captured scopes in both arms (6142, 6195), same as `invokeResolveFunction` and the `__resolve`/`.call`/`.apply` arms.
- `INV_LOCAL_SCOPE_UNDER_CAPTURED`: **verified — both arms push local first, captured on top.** EI becomes this flag's second user (today only the OBJECT `__resolve` arm at ~64441 sets it).
- `INV_BASE_CLIP` without `INV_VERSION_SWITCH`: the gate reads the caller's `g_swf_version`, which is what the core's `INV_BASE_CLIP` reads when no version switch is in force. No ClosureFrame needed; the Stage-3d hazard does not arise.

Per-branch delta (the lc_dispatch_method per-branch-gating shape):
- **Type-1 only: `+ INV_BIND_THIS`.** Reproduces `setVariableByName("this")` on the callee's local frame: `pushLocalScopeFrame` does the same `setProperty` on the same frame; forced-with makes the two write paths converge (see §4 D5 for the one edge). Do **not** add it for type-2 (today's type-2 arm never binds `this` by name, and a non-preload/non-suppress DefineFunction2 body could observe a new bind via the GetVariable fall-through).
- `act_flags = 0` both branches (no arguments object, no this-stack, no super — never done here). `this_var` = the constructed OBJECT/UNDEFINED var for **both** branches; the core derives `pass_this` = `this_obj` for OBJECT, NULL for UNDEFINED — matching today's ABI receiver exactly, so `has_this_ptr` is unnecessary.
- Not requested, deliberately: `INV_THIS_STACK`, `INV_SUPER_CTX`, `INV_VERSION_SWITCH`, `INV_EVENT_THIS_MC`, `INV_EXEC_FUNC`, `INV_LOCAL_SCOPE_MC`, `INV_CTOR_CTX`, `INV_OVERRIDE_THIS`, `INV_MC_THIS_NULL_PTR` — none are performed today.

**On the standing rule about type-1 `this` binds:** the rule's justification (doc block ~2676) is conditioned on the this-cell being populated — "dead **whenever INV_ACT_THIS / INV_SUPER_CTX are in force**." Neither is in force here, EI pushes no `g_this_stack` entry, and host-driven calls run at `g_this_depth == 0`, where `actionGetVariable("this")` (40855-40862) **falls through** the early this-cell path into the scope walk and finds the exact-match bind on the local frame (the case-insensitive skip at 40886-40892 only rejects *inexact* matches). So EI's type-1 `this` bind is **live**, not dead: with `thisObj = obj`, `trace(this.x)` reads `obj.x`; without the bind it falls to the root/current-context fallback. `INV_BIND_THIS` is an existing multi-user flag, not a new one-site flag, so the "provably-inert flag" precedent doesn't forbid it — but no current test reads `this` in an EI callback, so per the "diff the other way" guardrail the migration commit should add the lock test in §7 so the flag is justified by a test that notices. This is the biggest trap of this migration; do not drop the bind as "dead by rule."

### 4. Divergences (ritual vs mapped flags)

- **D1 — `g_execution_halted` entry check.** Core returns undefined immediately when halted; EI today would still dispatch. Observable only when the host calls EI after a script halt. Bug-class (running script post-halt is wrong); the LC/onStatus migrations already accepted this same delta silently. Accept.
- **D2 — `this_is_mc` derivation.** `cb->this_obj` may be MOVIECLIP; EI collapses it to an **OBJECT**-tagged `this_var` (type-1) and a raw pointer (type-2). If the arm instead passed `cb->this_obj` through as `this_var`, the core would derive `this_is_mc=1` — inert with this flag set (no `INV_EVENT_THIS_MC`/`INV_LOCAL_SCOPE_MC` requested) but the type-1 bind's tag would change OBJECT→MOVIECLIP, which is observable (e.g. `typeof this`, GetMember dispatch). **Preserve: construct `this_var` in the arm exactly as the current type-1 code does.** (The OBJECT-tag-on-MC-pointer is itself a latent type-confusion quirk — preserve, flag for normalization review.)
- **D3 — ARRAY/FUNCTION `thisObj`.** EI maps these to `this_obj = NULL`; the core's derivation from an ARRAY/FUNCTION-typed `this_var` would produce a non-NULL pointer. Same resolution as D2: the arm builds `this_var` from its own `this_obj` (OBJECT or UNDEFINED), never from `cb->this_obj` directly. With that, no divergence.
- **D4 — marshalling/scope-push interleaving.** EI type-1 marshals args before pushing scopes; the core marshals after. Eval stack and scope chain are independent structures and `pushVar` consults neither — inert.
- **D5 — `this`-bind write path at scope exhaustion.** EI: `setVariableByName` after the pushes; if the local push failed at `MAX_SCOPE_DEPTH`, it falls through to an outer non-with frame or `setGlobalVariableByName` (a leak). Core `INV_BIND_THIS`: `setProperty` directly on the (possibly unpushed) frame — no leak. Divergent only at scope-chain exhaustion; inert in practice, and the core's behavior is the safer one. Accept.
- **D6 — teardown order.** EI pops captured then local; core pops local then captured. Pure `scope_depth` decrements — inert.
- **D7 — bind timing vs base-clip switch.** EI binds `this` after switching `g_current_context`; core binds before. `setProperty` on the frame reads no context — inert.
- **D8 — depth-guard placement.** EI's guard runs after the registry scan; core's runs at its own entry. The arm's pre-core work is side-effect-free — inert.
- Everything else — registers alloc/free, strict two-way dispatch, `(u32)arg_count` cast, forward+clamp+pad loop, caller-version base-clip gate, captured-scope source arrays — is textually or semantically identical.

### 5. Type-1 clamp/pad + NULL-call status (post-Stage-0)

- **Forward order: confirmed** (`d8abc5c0a`; comment block 6163-6170 documents the old REVERSE push and the bcacc3f70 sweep miss).
- **Clamp: yes** — loop bounded by `param_count`; extras never pushed.
- **Pad: yes** — `PUSH(UNDEFINED)` for missing args; exactly `param_count` values pushed.
- **Unchecked calls: none** — already strict; no trailing dead code either. The core changes nothing here.
- Residual: `arg_count` is signed; a negative count from a buggy harness becomes a huge `u32`. Identical before/after migration; not a migration concern.

### 6. Reachability

| Path | Arm exercised | Status |
|---|---|---|
| avm1 `external_interface` (harness lines 263/326/392) | type-2, OBJECT `thisObj` (`thisTarget`/`thatTarget`), incl. re-entrant call from inside `ExternalInterface.call` | CI-covered, passing |
| regression `ei_type1_args` | type-1, `thisObj = null`, 2-arg + 1-arg (clamp/pad) | CI-covered, passing |
| gnash `ExternalInterface-v5..v8` | none — no `test_harness.c`, so no handler ⇒ `addCallback` returns false ⇒ dispatcher unreached | shape tests only |
| avm1 `external_interface_{escapexml,jsquotestring,toas_basic,toxml_*}`, `globals_swf8`, `native_objects_swf6/8` | none — mention EI but never call the internal dispatcher | n/a |
| `swf_ei_call_internal` (browser bridge) | either arm, production SWFs | not CI-observable |

**Unreached branches — needs probe** (file-write probe technique per the Stage-4 prompt): (a) `captured_scope_count > 0` in either arm — nothing in the suite registers a closure callback, so **both quirk flags (`INV_LOCAL_SCOPE_UNDER_CAPTURED`, `INV_FORCE_CAPTURED_WITH`) are currently unwitnessed on the EI path**; (b) MOVIECLIP `thisObj`; (c) type-1 callee that *reads* `this` (the live bind of §3 is unpinned — `ei_type1_args`'s callee reads only `a`/`b`); (d) whether the avm1 `external_interface` re-entrant call runs at `g_this_depth > 0` (it originates from top-level DoAction, likely depth 0).

### 7. Proposed repro/lock test design

**For the migration commit** (behavior locks — expected to pass before AND after; say so in the test comments, `nc_onstatus_closure` precedent):

- **`regression/ei_closure_scope_order`** — hand-assembled SWF (SWF6 or 8; DefineFunction emitted by hand, MTASC won't): `w = {a:"W_A"}; with(w) { h = function(a){...} }`-equivalent bytecode so `h` captures `w` as an is_with frame; register via `flash.external.ExternalInterface.addCallback("shadow", null, h)`; harness (mock handler + `g_after_tick_handler`, clone of `ei_type1_args`'s) calls `actionEI_callInternalInterface(ctx, "shadow", ["ARG"], 1)`. Callee body traces `a`. **Current/locked output: `W_A`** (captured scope shadows the param — pins `INV_LOCAL_SCOPE_UNDER_CAPTURED` for EI, the direct analog of `resolve_type1_args`'s `w.a` line). Add a second callback defined inside an outer type-1 function that *writes* a captured outer local and a post-call trace of it: forced-with makes the write skip the captured frame (lands on the callee's local frame), so the outer var stays unchanged — pins `INV_FORCE_CAPTURED_WITH` on this path.
- **`this` bind lock** (can live in the same SWF): a type-1 callback registered with `thisObj = {tag:"T"}` whose body traces `this.tag` (and one with `thisObj=null` tracing `typeof this` → `undefined`). Justifies `INV_BIND_THIS` by a test that notices, per the "diff the other way" guardrail. `ei_type1_args` itself needs no changes.

**For the later normalization commit (the inversion flip):** drop `INV_LOCAL_SCOPE_UNDER_CAPTURED` from the EI opts and flip `ei_closure_scope_order`'s expectation `W_A` → `ARG` in the same commit — exactly the `resolve_type1_args` model, which must get the identical treatment when the `__resolve` arm flips (ideally the same commit, since the flag then has zero users and the plan wants the flip CI-gated as one deliberate change). Decide separately whether `INV_FORCE_CAPTURED_WITH` flips too — it is a distinct quirk with a distinct observable (closure write-back through captured non-with frames) and its own expectation line in the lock test.

### 8. Risks / open questions

- **Is EI's inversion byte-identical to `__resolve`'s?** The scope mechanics are identical (same `pushInvokeScopes` shape: local under captured, is_with forced). The *surrounding ritual* is not: (1) `__resolve` binds the type-1 `this` in the **caller's** scope *before* the core via `setVariableByName` outside, with `this_var=NULL` + `has_this_ptr`; EI binds on the **callee's** frame *after* the pushes → must map to `INV_BIND_THIS` with a real `this_var`, gated to type-1. (2) `__resolve` brackets with `pushSuperContext(obj,1)`; EI has no super context. (3) `__resolve` keeps a bare `g_call_depth` bracket outside; EI's guard is the full `INV_DEPTH_GUARD` shape and moves inside. Copying the `__resolve` opts verbatim would be wrong in all three ways.
- **What breaks if the local frame goes on top?** Binds: nothing. Lookups: callee params/locals start winning over captured scopes — a callback defined inside `with(w)` whose param shares a name with a `w` property flips from `w`'s value to the argument. More correct, but content reliance is unknowable; CI both modes + the lock-test flip is the guard. Note the flip alone leaves EI still nonstandard via forced-with; a "fully normalized" EI is two separate deliberate changes.
- **Re-entrancy this-cell leak:** when EI is invoked with `g_this_depth > 0` (nested inside AVM1, e.g. via `ExternalInterface.call` → host → internal call), a callee reading `this` by name hits the *outer caller's* this-cell before any scope walk, bypassing both the type-1 bind and the fallback. Current behavior, preserved (no `INV_THIS_STACK`/`INV_RESET_THIS_DEPTH`); normalization-review candidate.
- **Normalization pass (b) backlog for this dispatcher** (each its own commit + test): missing `switchToFunctionVersion` (proven bug class; `regression/timer_cross_swf_version` is the model); missing `INV_EXEC_FUNC` (a `preload_arguments` callee gets stale `arguments.caller`); the D2 OBJECT-tag-on-MovieClip quirk; the inversion + forced-with flips.
- **Stale cross-reference to fix in passing:** `soundFireCallback`'s type-1 arm (`action.c:74185-74192`) says it "mirrors the type-1 path in actionEI_callInternalInterface" but still pushes args in **REVERSE** with no clamp/pad — EI stopped doing that at `d8abc5c0a`. Its type-1 arm also has the local-under-captured inversion (is_with **copied**, not forced — a third variant). That is its own Stage-4 dossier, but its comment should be corrected when EI lands so the "mirror" claim doesn't mislead the next migration.
- **Open question:** should the EI lock test also cover the type-2 arm's inversion (DefineFunction2 closure via hand-emitted bytecode)? The flag applies to both arms in one opts struct, so a type-1 pin guards the flip for both; a type-2 variant is nice-to-have, not blocking.

---

## fireTimerCallback

### 1. Site inventory

**Function:** `fireTimerCallback(SWFAppContext*, TimerEntry*)` — `static`, `SWFModernRuntime/src/actionmodern/timer.c:309-470`. Carved out of action.c by the math-first split; **it lives in a different TU than `invokeFunctionValue` (which is `static` in action.c)** — see §8, this is the one structural decision the migration cannot dodge.

**Sole call site:** `processTimers` (timer.c:511), itself called from the three frame loops: `swf_core.c:1429`, `swf_headless.c:1077`, `swf.c:1150` + the browser-WASM pump at `swf.c:1215`. After each fire, `processTimers` runs `actionFlushPendingOnChanged` (timer.c:515) and `actionFlushPendingOnLoads` (timer.c:518) — outside migration scope. Method-form timers whose MC receiver was removed (`depth == INT_MIN`) are deactivated *before* fire at timer.c:500-506 (matters for reachability, §6).

**Branch structure — four arms** (form × function_type):

| Arm | Lines | Dispatch |
|---|---|---|
| method-form type-2 | 358-386 | `advanced_func(ctx, extra_args, count, registers, this_obj)` |
| method-form type-1 | 387-402 | `simple_func(ctx)` after stack pushes |
| function-form type-2 | 416-449 | `advanced_func(ctx, extra_args, count, registers, NULL)` |
| function-form type-1 | 450-466 | `simple_func(ctx)` after stack pushes |

**Globals touched, in order:**

- *Method-form:* `g_execution_halted` (read, 311) → method lookup (`getPropertyWithPrototype` on the OBJECT receiver, or on `mc->dynamic_props` for a MOVIECLIP receiver — lookup happens **before** the version switch) → `actionSwitchToFunctionVersion` (351: `g_swf_version`, `global_object`) → type-2: `scope_chain`/`scope_is_with`/`scope_depth` (369-372), `g_call_depth` (374/379), heap (registers); type-1: AVM1 data stack (`pushVar`, 390-391), `g_event_this_mc` save/set/restore (394/395/401), `g_call_depth` (397/399) → `actionRestoreFunctionVersion` (404). **Never touches:** `g_current_context`, `g_this_stack`/`g_this_depth`, super context, `g_current_executing_func`, `g_special_depth`, local scope frames.
- *Function-form:* `g_execution_halted` (311) → `func` NULL check (410) → `actionSwitchToFunctionVersion` (414) → per arm: captured scopes (type-2 only, 424-429), data stack (type-1, 453-454), `g_current_context` save/switch/restore (432-434/443 and 457-459/465 — **both** arms), `g_call_depth` (bare bracket) → `actionRestoreFunctionVersion` (468). Never touches this-stack/super/exec-func/event-this/local scope.

**Stage-0 fix status (`60070d96a`):** implemented today as the exported `actionSwitchToFunctionVersion`/`actionRestoreFunctionVersion` pair (action.c:15187-15194, thin wrappers over the same `switchToFunctionVersion` the core's `INV_VERSION_SWITCH` uses). **Both forms get it**, wrapping all four arms symmetrically. `regression/timer_cross_swf_version` pins it — note that test's `cb` is a plain `DefineFunction` (0x9B), so it specifically locks the **function-form type-1** arm's version switch.

### 2. Current ritual per arm

**Method-form type-2** (358-386):
1. Registers: `HCALLOC(register_count)` if > 0.
2. Captured scopes: pushed with `scope_is_with = 1` **forced** (370), `scope_mc[depth]` **not written** (left stale), **no `MAX_SCOPE_DEPTH` bound check** (369-372).
3. No local scope frame; no `this` bind; no `arguments`; no super.
4. This: receiver (`obj` or `mc`) passed as the **ABI this pointer** to `advanced_func` (377). No `g_this_stack` push, no `g_override_this`, no `g_event_this_mc`.
5. **No base-clip switch** (`g_current_context` untouched).
6. Version switch: already installed at 351 (wraps the whole form).
7. No exec-func swap. `g_call_depth++` bare / `--` bare (374/379), no max check.
8. Args: `extra_args`/`extra_arg_count` passed by pointer (NULL if 0).
9. Teardown: `scope_depth -= captured_count` → FREE registers → version restore (404). Return value discarded.

**Method-form type-1** (387-402):
1. Args: `pushVar` each extra arg, **forward order** (args[0] deepest — correct), **no clamp to `param_count`, no pad** (390-391).
2. `g_event_this_mc` saved; set to `mc` **only when the receiver is a MOVIECLIP** (394-395); an OBJECT receiver's type-1 method gets **no `this` channel at all**.
3. No captured scopes, no local frame, no base clip, no this-stack.
4. `g_call_depth` bare bracket; **`simple_func` called with NO NULL check** (398) — and this `else` catches every `function_type != 2`.
5. Teardown: restore `g_event_this_mc` (401) → version restore (404).

**Function-form type-2** (416-449):
1. Registers as above.
2. Captured scopes: same forced-`is_with`, stale-`scope_mc`, unguarded push (424-429).
3. Base clip: `g_current_context = func->base_clip` gated `g_swf_version >= 6 && base_clip != NULL` (433) — **`g_swf_version` is read AFTER `actionSwitchToFunctionVersion` (414), so the gate reads the CALLEE's version.** This is a live instance of the `INV_BASE_CLIP|INV_VERSION_SWITCH` hazard class the Stage-3d note documents for the MC arms.
4. ABI this = `NULL` (439). No this-stack/event-this/super/exec-func/local frame.
5. `g_call_depth` bare; **`advanced_func` called without a NULL check** (as in all four arms' respective pointers).
6. Teardown: restore `g_current_context` (443) → pop captured (446) → FREE registers → version restore (468).

**Function-form type-1** (450-466):
1. Args: forward push, **no clamp/pad** (453-454).
2. Base clip: same callee-version-gated switch as the type-2 arm (457-459) — the only type-1 arm in this dispatcher that touches `g_current_context`.
3. **No captured scopes** (unlike this form's type-2 arm — a type-1 closure loses its chain here).
4. `g_call_depth` bare; **unchecked `simple_func`** (462); else-catches-everything shape.
5. Teardown: restore context (465) → version restore (468).

### 3. Proposed InvokeOpts mapping per branch

Adapter shape modeled on `lc_dispatch_method`/`lc_dispatch_onStatus` (per-branch flag computation off `func->function_type` before one core call). Bare `g_call_depth++/--` stays outside in all four (no `INV_DEPTH_GUARD` — the path never had the `g_max_call_depth` halt check). Return value discarded by the adapter. `act_flags = 0` everywhere (no this/arguments/super binds today; the type-1 "no this bind" cells are dead by the standing rule anyway).

**Method-form** — `this_var = &t->object` (OBJECT or MOVIECLIP tag; core derives the same `this_ptr` the arm passes today), `args = extra_arg_count ? extra_args : NULL`:

| | flags |
|---|---|
| type-2 | `INV_CAPTURED_SCOPE \| INV_FORCE_CAPTURED_WITH \| INV_VERSION_SWITCH` |
| type-1 | `INV_EVENT_THIS_MC \| INV_VERSION_SWITCH` |

- `INV_VERSION_SWITCH` is safe *in the core* for this form because **neither arm ever switches base clip** — no flag pairing, no gate to compute.
- `INV_EVENT_THIS_MC` gated to type-1 (mirror image of the MC arms, which gate it to type-2): the core's "set when receiver is MC" is exactly the arm's `if (mc != NULL)`; a no-op for OBJECT receivers either way. Do **not** set it on type-2 — the arm never did.
- No `INV_LOCAL_SCOPE` (this dispatcher never pushed a local frame), no `INV_THIS_STACK`, no `INV_BASE_CLIP`, no `INV_EXEC_FUNC`.
- Stays outside: halted check, the two-way receiver method lookup + silent skip on miss, depth bracket.

**Function-form** — `this_var = NULL` (core derives `pass_this = NULL`, matching line 439), same args:

| | flags |
|---|---|
| type-2 | `INV_CAPTURED_SCOPE \| INV_FORCE_CAPTURED_WITH \| INV_VERSION_SWITCH` |
| type-1 | `INV_VERSION_SWITCH` |

- **Base clip stays in the arm** (standing rule: never `INV_BASE_CLIP|INV_VERSION_SWITCH` together). Both arms, Stage-3d pattern: compute `eff_ver = func->swf_version ? func->swf_version : g_swf_version` — provably the value `switchToFunctionVersion` is about to install — then bracket the core call with `saved = g_current_context; if (eff_ver >= 6 && func->base_clip) g_current_context = func->base_clip; … invoke … g_current_context = saved;`. This preserves the **callee-version** gate as a named local instead of an accident of statement ordering. (Alternative — keep `actionSwitchToFunctionVersion` in the arm and give the core `INV_BASE_CLIP`, whose gate then reads the already-switched version — is behaviorally identical but hides the gate again and reads as the forbidden pairing; prefer the eff_ver form, which Stage 5's funnel gate will also not flag.)
- Ordering deltas vs today (arm's context switch now precedes the core's version switch; restores swap symmetrically): the two brackets write disjoint globals and nothing between them reads the other — inert, but say so in the migration comment.

### 4. Divergences (arm ritual vs mapped-core, line by line)

1. **Captured `scope_mc` left stale** (369-372, 424-429): the arms write `scope_chain` and `scope_is_with` but never `scope_mc[depth]`; the core's `pushCapturedScopes` writes `func->captured_scope_mc[ci]`. Observable in principle: `scope_mc` is read on `is_with` frames during GetVariable/SetVariable resolution (action.c:40898-40946, 42439, 58037) for MC builtin props / `_name` / with-target resolution — a stale non-NULL entry from a previously popped deeper frame could route a lookup to an unrelated MC. Old behavior is history-dependent (effectively nondeterministic), new behavior is the defining-time value — a fix of the stale-global class, not load-bearing. Accept silently; note in the migration comment.
2. **No `MAX_SCOPE_DEPTH` guard on the captured push**; core bounds it. Old = latent overflow, new = clamped. Inert fix, accept.
3. **Forced `is_with = 1` on captured scopes** — preserved via `INV_FORCE_CAPTURED_WITH` (the legacy resolve/EI quirk bit already exists). Normalization candidate (§8): most arms copy `captured_scope_is_with`.
4. **Type-1 no clamp/pad** (both forms) — the core's canonical loop **changes behavior**: this is the queued TYPE1 clamp/pad fix, claim it with the §7 repro, don't preserve it.
5. **Unchecked `simple_func`/`advanced_func` + else-catches-everything** (all four arms) — the core's strict NULL-checked dispatch replaces a crash with undefined. Audited-dead / bug-class fix (§5), not behavior to preserve.
6. **`INV_EVENT_THIS_MC` core placement**: core sets it before the version switch and restores after it; the arm sets it after the arg pushes and restores before version restore. Nothing between reads it; inert.
7. **Core's unconditional `g_this_depth = saved_this_depth`** at exit — a no-op here unless a callee leaks depth; property of every migrated arm already, not timer-specific.
8. **Core NULL-func/halted entry checks duplicate the arm's** (311, 410) — keep the arm's (the method-form one also gates the lookup); duplication inert.
9. **Skipped steps that must STAY skipped** (preserve-exactly): no local scope frame in any arm (so no named `arguments` — a non-preload type-2 callback reading `arguments` gets undefined today); no `g_this_stack` push (an OBJECT-receiver type-1 method cannot see `this` — matches today); no `INV_EXEC_FUNC` (would rewrite `g_prev_executing_func` and change `arguments.caller` for preload_arguments prologues); no super, no ctor context, no method-form base clip.

### 5. Type-1 clamp/pad + NULL-call status

- **Push direction:** forward (correct) in both forms — `bcacc3f70`-era fix present.
- **Clamp:** absent. `extra_arg_count > param_count` strands operands on the AVM1 stack across the callback (persists into subsequent frame code) *and* misbinds: 3 args into 2 params binds `a=args[1], b=args[2]` with `args[0]` stranded.
- **Pad:** absent. `extra_arg_count < param_count` makes the prologue pop the (usually empty) between-frames stack — garbage/undefined into the *first* params, real args shifted into the last.
- **NULL-call hazard: LIVE class, both forms.** No pointer NULL checks anywhere; both `else` branches catch every `function_type != 2`. Concrete vectors: method-form `setInterval(o, "getDepth", 1)` where `o`'s proto chain reaches `MovieClip.prototype` (its stubs are `function_type = 1`, both pointers NULL — action.c:15643-15645, except `meth`/`getSWFVersion`); function-form `o.gd = MovieClip.prototype.getDepth; setInterval(o.gd, 1)` (the stub is a FUNCTION-tagged value, so `timerIsCallable` admits it); `g_stub_ctors` entries likewise. Core's strict dispatch returns undefined instead of calling NULL.

### 6. Reachability (static; grep of test sources + recompiled scripts)

| Arm | Coverage |
|---|---|
| function-form type-2 | **LIVE, with extra args**: `avm1/set_interval` (`TICK: C test` etc.); also `avm1/string_paths_eval2` (`after_timer1` is a DefineFunction2 defined *inside* a type-1 anonymous — live captured-scope case for `INV_FORCE_CAPTURED_WITH`), `avm1/movieclip_lockroot`, `avm1/loadvariables2`, `avm1/edittext_ime_focus_lost` (MTASC → DF2, no extra args), `avm1/netstream_play_flv_screen` |
| function-form type-1 | **LIVE, but only 0-param/0-arg**: `avm1/timer_run_actions` (`fn` is a plain DefineFunction), gnash `misc-swfc.all/gotoFrameFromInterval{,2}` (type-1 anonymous, `setInterval(f, ~0.0001)`), `regression/timer_cross_swf_version` (type-1 `cb`; pins the version switch on exactly this arm). Clamp/pad is **latent on a live path** — same shape as LC instance ten |
| method-form type-2 | **LIVE, OBJECT receiver, with extra args**: `avm1/set_interval` (`OBJECT TICK: G (method)` / `E (method)`; `obj.tick` is DF2). MOVIECLIP-receiver type-2: no test found — **needs probe** |
| method-form type-1 | `avm1/string_paths_timer` registers `setInterval(clip, "foo", 1)` with a type-1 `foo` on an MC, but expected output is **empty** and the clip is removed — the removed-MC deactivation at timer.c:500-506 almost certainly prevents the fire. **Needs probe**; treat as uncovered |

gnash `actionscript.all/delete-v5..v8` also register an interval (function-form) but are known-red fixture drift — don't count them as coverage.

### 7. Proposed repro/lock test design

**`regression/timer_type1_args`** (model: `lc_method_type1_args/create_test_swf.py`) — hand-assembled **SWF6** (MTASC emits DF2 for SWF6+; `setInterval` is Flash 6+), one `DoAction` frame + 2-3 idle ShowFrames so `processTimers` fires (one-shot `setTimeout` avoids clearInterval plumbing; timers all become eligible on the first ~41.7 ms tick and fire in creation order).

- `DefineFunction f(a, b)` tracing `"f:a=" + a` and `"f:b=" + b` (0x9B, two params).
- Function-form, three shapes: `setTimeout(f, 1, "one", "two")` (order lock — passes today), `setTimeout(f, 1, "solo")` (**pad** — today `b="solo"`, `a=` pops the empty between-frames stack; expected `a=solo`, `b=` — v6 concats undefined as `""`, per `timer_cross_swf_version`), `setTimeout(f, 1, "x1", "x2", "x3")` (**clamp** — today `a=x2, b=x3` + `x1` stranded on the stack; expected `a=x1, b=x2`).
- Method-form, same three shapes against `o = new Object(); o.m = f; setTimeout(o, "m", 1, ...)` — the two forms are **separate arms**; both need pinning (distinct trace prefix).
- Trailing `trace("done")` in the last frame both as an ordering marker and to surface stranded-operand corruption.
- Verify FAIL-before by running against the parent commit's `timer.c`/`action.c`. Pad and clamp directions fail before; the 2-arg order rows are deliberate locks (say so in the README).

No new test needed for the version switch (`timer_cross_swf_version` already locks the function-form type-1 arm) — but note it does **not** cover the type-2 arms' version switch; the migration keeps the switch symmetric, so a probe-attribution note suffices.

### 8. Risks / open questions

1. **TU boundary — the blocking decision.** `invokeFunctionValue`, the flag macros, and `InvokeOpts` are all `static`/private to action.c; `fireTimerCallback` is in timer.c. Options: (a) move the flag block + struct + a non-static `actionInvokeFunctionValue` wrapper into `action_internal.h` (precedent: `actionSwitchToFunctionVersion` was exported exactly for timer.c); (b) move `fireTimerCallback` back into action.c (fights the split-action-c plan); (c) a purpose-built exported shim. (a) is cleanest and future-proofs other split-out subsystems; the migrating session must pick and keep Stage 5's funnel-gate script in mind (it greps for raw `simple_func`/`advanced_func` calls — timer.c must end up clean or allowlisted).
2. **Probe before migrating:** method-form type-1 and any MOVIECLIP-receiver method-form fire (file-writing instrument on the arms; run `set_interval`, `string_paths_timer`, `timer_run_actions`, `string_paths_eval2`, gnash `gotoFrameFromInterval{,2}`, `timer_cross_swf_version`). Determines whether the method-form mapping is exercised at all by CI.
3. **Try-delete candidates** (guardrail: attempt deleting a divergence before flagging it): `INV_FORCE_CAPTURED_WITH` — is the forced `is_with` load-bearing here or copied from the same legacy pattern the resolve/EI arms had? A/B with copied `is_with` across `set_interval` + `string_paths_eval2` before shipping the flag; if nothing notices, prefer dropping the force (but that's then a *normalization* commit, not the migration).
4. **Normalization-pass candidates (separate later commits, each with a test):** method-form base-clip switch (skipped entirely, both arms); type-1 captured scopes (skipped in both forms — a type-1 closure timer callback loses its defining scope chain; looks like a plain bug); callee-vs-caller version gate on the function-form base clip (this dispatcher joins the MC arms as a callee-gate instance — feeds the plan-wide unification question); named `arguments` for non-preload type-2 callbacks (needs `INV_LOCAL_SCOPE + INV_ACT_ARGUMENTS`, which then **requires** giving the core `INV_EXEC_FUNC` — the arguments.caller coupling makes this the most delicate candidate); `g_event_this_mc` for method-form type-2 MC receivers.
5. **Real-game exposure:** timers fire every frame in shipped games; the suites barely touch the method-form. After CI, a quick headless/browser smoke of a timer-heavy game is cheap insurance, and this is the one stage the plan says may warrant a fresh perf datapoint (Minesweeper/DJ, core `Ir` line only).
6. **Silent-fix inventory to record in the migration comment:** stale `scope_mc` → defining-time value; unbounded captured push → bounded; NULL-call → undefined; type-1 clamp/pad → fixed (credited via §7). Everything else is preserve-exactly.

---

## watch arms (actionSetVariable / actionSetMember)

Ground truth read: `invokeFunctionValue` (action.c:15314, forward decl 2714), the `InvokeOpts`/`act_flags` doc block (2635–2706), `pushInvokeScopes`/`pushLocalScopeFrame`/`buildActivationLocals` (15197–15309), the accessor family (7961–8298), `lc_dispatch_method` (2953), plan §3 + Stage 3c/3d/4 landing notes, stage-4 prompt. Ruffle reference: `~/CC/ruffle/core/src/avm1/object.rs:225-265`, `object/script_object.rs:35-54, 508-547`.

There are exactly **three firing sites** and **three registration sites**. Exhaustive grep confirms no other invocation: `actionSetProperty` (55490) never checks the table, no virtual-setter path checks it, `actionDefineLocal`/timer/dprops paths are clean.

### 1. Site inventory

**Machinery** (shared): `WatchEntry` table `g_watch_table[64]` (890–900) keyed by `(obj, mc, prop_name[64])`; `obj != NULL` = object watch, `obj == NULL && mc != NULL` = timeline/MC watch. Per-entry `user_data` (the 4th `watch()` arg). Re-entry guard stack `g_watch_firing[256]` + `watch_firing_depth/push/pop` (902–938), capped by `accessorReentryLimit()` (798: 1 for SWF≤6, 65 for SWF7+) and `MAX_SPECIAL_DEPTH` (680: 66). GC interplay: collector refuses to run while `g_watch_firing_count != 0` (74314); table is marked (74419–74422) and pointer-scrubbed (74521–74528).

**Registration** (not migration targets): `builtin_object_watch` (4227) / `builtin_object_unwatch` (4289, incl. the Flash "can't unwatch a getter-setter" refusal at 4313–4321), installed on `Object.prototype` + `ASnative(101,0/1)` (6888–6895, 7542–7567); the MOVIECLIP name-dispatch `watch`/`unwatch` arms inside `actionCallMethod` (70006–70083). `builtin_object_watch` with `this_obj == NULL` registers a timeline watch on `g_current_context`.

**Firing sites:**

| # | Site | Lines | Receiver match | Types fired | Guarded? |
|---|---|---|---|---|---|
| A | `actionSetVariable` (fn at 42152), global-var fallback path | 42703–42799 (call at 42753) | `obj==NULL && mc==g_current_context∥root` | **type-2 only** | **NO** |
| B | `actionSetMember` (fn at 46870), OBJECT-receiver arm | 47717–47896 (calls at 47839 t2, 47882 t1) | `obj==receiver` | type-2 + type-1 | YES (47752–47754) |
| C | `actionSetMember`, MOVIECLIP-receiver arm | 49713–49826 (calls at 49771 t2, 49812 t1) | `obj==NULL && mc==receiver` | type-2 + type-1 | **NO** |

Positioning matters: in `actionSetVariable`, all addProperty-setter checks (42382, 42504, 42673) **return before** the watch arm — a watched+addProperty timeline var never fires the watcher (this *is* the `watch_virtual_property` RED, see §6). In the SetMember OBJECT arm, watch fires **before** the setter walk (47897+) and its return value feeds the setter — Ruffle-correct ordering (`object.rs:236`). In the MC arm, the dprops addProperty-setter check (49667–49711) **returns before** the watch check — same gap as A, opposite arm.

**Globals touched, in order:**
- **A**: `scope_chain/scope_is_with/scope_mc/scope_depth` push (bare frame, no this bind) → `g_call_depth++` (raw, **no max check**) → call → `g_call_depth--` → scope pop → `releaseObject` → `free(_pname_u16)` → return fold → `var_map` hashmap re-sync (42763–42792). Never touches `g_this_stack`, `g_current_context`, `g_event_this_mc`, version, exec-func, `g_watch_firing`.
- **B t2**: `watch_firing_push` → `g_this_stack/g_this_depth` push (OBJECT=obj; restore-to-saved, not zero) → captured scopes (own `is_with`) → local scope `allocObject(8)` with `"this"` bound → `g_current_context = func->base_clip` (gated `g_swf_version>=6`, caller's version — no version switch exists here) → `g_call_depth++` → `advanced_func(..., 4, regs, obj)` → symmetric teardown → `watch_firing_pop`.
- **B t1**: `watch_firing_push` → captured scopes → `setVariableByName("this", obj)` (**into the enclosing scope — no local frame**) → this-stack push → base-clip switch (caller-gated) → 4× `pushVar` forward → `g_call_depth++` → `simple_func` → teardown → `watch_firing_pop`.
- **C t2**: local scope `allocObject(4)` with `"this"` (MOVIECLIP) bound via `setProperty` → `g_call_depth++` → `g_current_context = mc` (**receiver**, via `actionSetCurrentContext`, 28927 — plain assignment; NOT base_clip) → `advanced_func(..., 4, regs, mc)` → teardown → guarded `free` of pname. No captured scopes, no this-stack, no firing guard.
- **C t1**: 3× `pushVar` (name, old, new — **userData dropped**) → local scope with `"this"` bound → `g_call_depth++` → context=mc → `simple_func` → teardown. No captured scopes, no this-stack, no firing guard.

### 2. Current ritual per arm (line-by-line)

**Site A (type-2 only, 42703–42799):**
1. Match loop; `_sv_ctx = g_current_context ∥ &root_movieclip` recomputed per entry.
2. Gate: `_wf->function_type == 2 && _wf->advanced_func != NULL`; anything else `break`s and **falls through to a plain, watcher-less assignment**.
3. Old value: non-owning copy of `*var`; "never initialized" sentinel (STRING with NULL heap_ptr) → UNDEFINED (matches the avm1 `watch` test's `// variable = 5 … changed from undefined`).
4. New value peeked (not popped) from eval stack.
5. **"Clear first"**: var freed and set UNDEFINED *before* the call, so a throwing watcher leaves it undefined. This works because throw is setjmp/**longjmp** (line 384): the longjmp skips the post-call store *and all the arm's teardown* — pre-existing hazard class shared with every dispatcher; the catch site restores scope_depth (cf. 32203 comment).
6. Args: `{pname(owns=true), old(non-owning), new, user_data}` — 4 args, matching Ruffle's `[name, old_value, new_value, user_data]`.
7. Registers HCALLOC'd; bare local scope pushed (no this bind, `scope_mc=NULL`); `g_call_depth++` **without** a `g_max_call_depth` check; `advanced_func(app_context, _wargs, 4, _wregs, NULL)` — **ABI this = NULL**; teardown; `free(_pname_u16)` unconditionally.
8. Return: `_actual_new = (_wret.type != UNDEFINED) ? _wret : _new_val; *var = _actual_new` — **undefined return keeps the intended value** (see divergence D1).
9. `var_map` hashmap re-sync (SWF≤6 key folding), `POP_2`, return — the normal propagate-to-root/textfield-sync tail (42844–42864) is **skipped** on the watcher path.

**Site B (47717–47896):** prop name first copied off the **static `_sm_buf`** into a stack-local (47721–47728) because a recursive SetMember inside the watcher clobbers it — remember this for Site C. Firing guard 47752–47754 (`watch_firing_depth ≥ accessorReentryLimit() || g_watch_firing_count ≥ MAX_SPECIAL_DEPTH` → commit without firing). Old value via `getPropertyWithPrototype` (proto-inherited; Ruffle uses `get_stored` — own stored value only — a subtle old-value divergence, D8). 4 args with a three-way string-ownership dance (47775–47790):
- **t2** (47792–47850): `_wargs[0].owns_memory=false` so the callee prologue's pointer-sharing `setProperty` arg-bind can't free it on scope release — and it is then **never freed** (deliberate leak-over-dangle, documented at 47775–47781). this-stack push + `"this"` bound on the fresh local frame ("Mirrors invokePropertyGetter" per its own comment), captured scopes (own is_with), base-clip switch caller-gated, `advanced_func(..., 4, regs, obj)`. Return fold into `value_var`, which then flows into the setter walk / `setProperty` below.
- **t1** (47851–47890): captured scopes; `setVariableByName("this")` into the **enclosing** scope (no local frame — the nc_onstatus shape); this-stack push; base-clip switch (both branches have it here); **exactly 4 `pushVar`s, forward order, no clamp, no pad**; `simple_func`; return fold.

**Site C (49713–49826):** no prop-name copy, no firing guard. Old value **hardcoded UNDEFINED** (49739, justified only for TF virtual props).
- **t2** (49726–49781): 4 args (userData included), `_wargs[0]` marked non-owning + explicitly freed after; fresh local scope with MOVIECLIP `"this"` bound; **no captured scopes, no this-stack**; `g_current_context = mc` (receiver) around the call; `advanced_func(..., 4, regs, mc)`; return fold.
- **t1** (49782–49821): **3 args only** (name, old, new — userData dropped), pushed *before* the scope frame; fresh local scope with `"this"` bound; no captured scopes, no this-stack; context=mc; `simple_func`; return fold; pname freed.

### 3. Proposed InvokeOpts mapping per branch

All branches: `act_flags = 0` (no `arguments`, no `super`; the `"this"` binds are the arm's own → `INV_BIND_THIS`, not `INV_ACT_THIS` — and `INV_ACT_THIS` would be illegal on B-t1 anyway, which has no local scope). The raw `g_call_depth++/--` bracket stays **outside** at every site (no site ever had `INV_DEPTH_GUARD`'s halt — same judgement as `lc_dispatch_method`). Return value: the core returns the callee's result for both types — every site's `_wret` harvest maps directly; the `!= UNDEFINED` fold stays outside (it is site policy, and suspect — D1).

| Branch | flags | this_var | stays outside |
|---|---|---|---|
| A (t2 only) | `INV_LOCAL_SCOPE` | **NULL** (core derives `this_ptr=NULL`, passes NULL — exactly current) | type-2 gate (falls through to plain set!), clear-first, old-val snapshot, `free(_pname_u16)`, return fold, hashmap sync |
| B t2 | `INV_THIS_STACK \| INV_CAPTURED_SCOPE \| INV_LOCAL_SCOPE \| INV_BIND_THIS \| INV_BASE_CLIP` | OBJECT(obj) | firing guard push/pop, prop-name copy, ownership dance, return fold |
| B t1 | `INV_THIS_STACK \| INV_CAPTURED_SCOPE \| INV_BASE_CLIP` | OBJECT(obj) | ditto; the `setVariableByName("this")` enclosing-scope write has **no core equivalent — see D5b** |
| C t2 | `INV_LOCAL_SCOPE \| INV_BIND_THIS` | MOVIECLIP(mc) | receiver-context bracket `g_current_context=mc` (arm-owned), pname free, return fold |
| C t1 | `INV_LOCAL_SCOPE \| INV_BIND_THIS` | MOVIECLIP(mc) | ditto |

Notes:
- **B's base-clip gate**: the arm never version-switches, so the core's `g_swf_version>=6` read at `INV_BASE_CLIP` time is the caller's version — identical. `INV_VERSION_SWITCH` must NOT be added alongside; if normalization later adds a version switch, compute the gate in the arm Stage-3d style (`eff_ver`).
- **C's context switch is the receiver, not base_clip** — no `InvokeOpts` flag expresses that (deliberately). Keep the two-line `saved/actionSetCurrentContext(mc)` bracket in the arm, around the core call. Do not fake it with `INV_BASE_CLIP`.
- **Do NOT set** at C: `INV_MC_THIS_NULL_PTR` (site passes mc, not NULL), `INV_EVENT_THIS_MC` (never set here), `INV_LOCAL_SCOPE_MC` (site pushes `scope_mc=NULL`).
- **C t2/t1 `"this"` bind is LIVE, not dead**: no this-stack push means `GetVariable("this")`'s early this-cell path only wins when the *outer* script left `g_this_depth>0`; at timeline level it falls to the scope walk and finds the bind. The type-1-dead-bind rule applies only when `INV_THIS_STACK`/`INV_ACT_THIS` is in force (as at B-t1) — do not delete C's bind.
- **One adapter?** Yes for the payload: a single `invokeWatchCallback(app_context, WatchEntry*, this_var, prop, prop_len, old, intended, /*out*/ stored)` owning arg construction, the ownership dance, the firing guard, the core call, and the return fold — with per-site `flags` + an `enter_receiver_ctx` bool for C and the guard/type-gate switches for A. Behavior-preserving migration keeps the three flag sets distinct; collapsing them is the normalization pass.

### 4. Divergences

Between current rituals and the mapped flags: **none** — the mapping reproduces each branch's steps, except the two marshalling divergences the core fixes by construction (D7, the sanctioned bug class) and one dead-ish bind (D5b). The interesting divergences are **between the sites** and **versus Ruffle**:

- **D1 — return fold (all 3 sites, observable, Ruffle-divergent).** All sites do `if (_wret.type != UNDEFINED) value = _wret` — a watcher that returns nothing keeps the *intended* value. Ruffle stores the return unconditionally (`Ok(v) => *value = v`, script_object.rs:530) — property becomes undefined. No suite test pins either way (every suite watcher returns a value). Class: Ruffle-parity bug, probably ours. Normalization candidate with its own test; do NOT bake current behavior into the lock test (§7).
- **D2 — Site A fires type-2 only (observable).** A type-1 timeline watcher matches the entry, fails the `function_type==2` gate, `break`s, and the assignment proceeds silently watcher-less. Flash/Ruffle fire it. Migrating A through the core makes type-1 support one flag-set away — but turning it ON is a behavior change: separate normalization commit + test.
- **D3 — firing guard only at B (crash-class).** A and C re-fire unboundedly on self-set; A's raw `g_call_depth++` never checks `g_max_call_depth`, so nothing bounds it but the C stack. The `watch_recursion_*` tests only cover B. Normalize: `watch_firing_push/pop` at all three sites.
- **D4 — watch × addProperty ordering (observable, known).** B fires watcher→setter (Ruffle-correct); A and C return from their setter checks before the watch arm. This is `watch_virtual_property`'s RED (ignored_tests.txt:110): deep semantic gap, explicitly out of scope per the ignored-tests note — record, don't chase.
- **D5 — `this` handling differs three ways.** (a) B pushes this-stack = watched obj → correct, getter-model, **no `INV_RESET_THIS_DEPTH` needed**. (b) B-t1 additionally `setVariableByName("this")` **into the enclosing scope** — dead for lookup (this-cell wins) but a *side-effect write* that can mint a `this` variable in the caller's frame or timeline vars. String-primitive precedent: A/B-prove it inert, then drop; no preservation flag. (c) **A and C push nothing** → inside the watcher, `GetVariable("this")` returns the **outer caller's** `this` whenever `g_this_depth>0` (any set performed from inside a method). That is precisely the leak `INV_RESET_THIS_DEPTH` was built for. `watch_textfield` passes only because its set happens at timeline level. Ruffle passes this=watched-object always. Normalization: C should gain `INV_THIS_STACK` (MOVIECLIP); A should probe what Flash gives a timeline watcher — each its own commit + nested-set test.
- **D6 — C-t1 drops userData** (3 args vs 4 everywhere else, vs Ruffle's always-4). Observable with any type-1 MC watcher taking a 4th param.
- **D7 — type-1 clamp/pad missing at B and C** (see §5) — the TYPE1_ARG_ORDER pad/clamp class, candidate instances 13–14.
- **D8 — old-value source differs three ways.** A: real previous value (+unset→undefined sentinel). B: `getPropertyWithPrototype` (proto-inherited — Ruffle uses `get_stored`, own value only). C: hardcoded undefined (wrong on the *second* set of an MC prop; `watch_textfield` only sets once, so unpinned).
- **D9 — context switch: A none, B base_clip (caller-gated, both types), C receiver (both types).** C is a third context mode, kin to Stage-3d's `CF_CTX_RECEIVER`.
- **D10 — captured scopes: B both types, A and C none.** A closure watcher registered at A/C loses its captured chain. Normalization candidates.
- **D11 — no site version-switches.**
- **D12 — GC gate covers only B's firings** (74314 checks `g_watch_firing_count`); a collection can run mid-watcher at A/C. Mostly inert (table is marked), noteworthy for alloc-heavy watchers.
- **D13 — pname ownership dance differs three ways, one latent double-free.** B-t2: non-owning + never freed (deliberate leak, documented). C: non-owning + explicitly freed (clean). **A: passed owning + explicitly freed** — if a *named-param* (non-register-preloaded) type-2 watcher's prologue pointer-binds the arg into the local scope, scope release frees it and A's `free(_pname_u16)` double-frees. Latent only because every suite watcher is register-preloaded. Migration through the core does not change this by itself — the fix is adopting B's owns=false discipline; needs probe.

### 5. Type-1 clamp/pad + NULL-call status

| Site | Type-1 reachable? | Push order | Clamp | Pad | NULL-call |
|---|---|---|---|---|---|
| A | never fires (D2) | n/a | n/a | n/a | safe (strict t2 gate) |
| B | yes (plain-DefineFunction watcher on an object) | forward ✓ | **NO** — always 4 | **NO** | safe (both branches strict; no unchecked `else`) |
| C | yes (plain-DefineFunction watcher on an MC/TextField) | forward ✓ | **NO** — always 3 | **NO** | safe (same strict shape) |

Concrete misbind at **B**: the *canonical* 3-param watcher `function(prop, oldVal, newVal)` gets 4 pushed; the prologue pops the last declared param first, so it binds `p1=oldVal, p2=newVal, p3=userData` — every arg off by one — **and leaves the name string stranded on the caller's eval stack**. A ≥5-param watcher pops the caller's stack. At **C**: the canonical 3-param watcher binds correctly *by accident*; a 4-param watcher's `p4` pops a stale caller slot; a 2-param watcher strands a slot. No NULL-call hazard anywhere in the family — these arms were already strict; the silent no-fire fallback (commit value, skip watcher) is the failure mode instead.

### 6. Reachability

- **avm1 `watch` — PASS 117/117.** Covers Site A t2 heavily (timeline watcher, DefineFunction2 flags=42: 4-arg delivery, userData, return-becomes-value, throw→undefined, delete/rewatch, unwatch) and Site B t2 (`LoggingWatcher` class method: pins this=obj).
- **avm1 `watch_textfield` — PASS.** Site C t2 (TextField MC receiver), pins this=`_level0.text_field` (timeline-level set only — D5c untested) and oldVal=undefined on first set (D8 untested for second set).
- **avm1 `watch_infinite_recursion`, `watch_proto_recursion` — PASS.** Site B t2 + depth halt.
- **avm1 `watch_recursion_swf6` / `_double_swf6` — ruffle_matched;** `watch_recursion_swf7` / `_double_swf7` — **ignored RED** (ACCEPTED_DIFFS Category 10). All Site B.
- **avm1 `watch_virtual_property` — ignored KNOWN RED** (ignored_tests.txt:110): Flash/Ruffle fire the watcher on a watched+addProperty **timeline** variable and feed its return into the setter; our `actionSetVariable` addProperty paths return before the watch arm (9/60 lines). `watch_virtual_property_proto` — PASS.
- **gnash `Object-v6/v7/v8`** exercise registration, not the firing arms' marshalling.
- **Type-1 branches at B and C: ZERO suite coverage** — every suite watcher compiles to DefineFunction2. **Needs probe** (hand-assembled SWF, §7).
- Also "needs probe": Site A type-1 (no-fire), C re-entry (no guard), C static-buffer clobber, D1 undefined-return, D5c nested-set this, D8 second-set old value.

### 7. Proposed repro/lock test design

Model: `regression/lc_method_type1_args/create_test_swf.py` (hand-assembled SWF6, plain `DefineFunction`). Two tests, one per SetMember site:

**`regression/watch_setmember_type1_args`** (Site B t1): bytecode builds `o = {}` (InitObject), defines plain `DefineFunction w(prop, oldV, newV)` — the *canonical* 3-param signature, deliberately ≠ 4 — body: `trace("w: " + prop + "|" + oldV + "|" + newV); return newV + "!"`. Then `o.watch("p", w)` via CallMethod, `o.p = "x"` via SetMember, `trace("stored: " + o.p)`, and a trailing `trace("end")` sentinel. Expected (Flash semantics): `w: p|undefined|x`, `stored: x!`, `end`. Today: params shift by one, the return concatenates the misbound value, and the stranded name string corrupts the following expression — three independent fail signatures. The `stored: x!` line **pins return-value-becomes-new-value** through a defined return. Add a second 5-param watcher set to pin the pad (`e` must trace `undefined`, not a popped caller slot). Deliberately do **not** assert the undefined-return case — that is D1, normalization-gated.

**`regression/watch_mc_type1_args`** (Site C t1): `createEmptyMovieClip("m", 1)`; plain `DefineFunction w4(prop, oldV, newV, ud)`; `m.watch("p", w4, "UD")`; `m.p = "x"`; trace all four params + `trace("stored: " + m.p)`. Migration-preserving expectation: `ud` traces `undefined` (core pads; num_args stays 3) — locks the stale-pop fix; the follow-up normalization commit (deliver userData, D6) flips that line to `UD` with Ruffle as oracle. Also pins return-becomes-value on the MC arm.

Optional probes (not lock tests until verified against Ruffle/Flash): Site A type-1 no-fire (D2); C self-set recursion (D3 — today likely a crash); C's post-watcher static-buffer clobber (§8.1).

### 8. Risks / open questions

1. **Site C uses the static `_sm_buf` prop name across the watcher call** (no copy, unlike B's 47721–47728) and reads it *after* the call (tabIndex 49828, `setProperty` 49864, autoSize 49869, TF-binding notify 49888). Any SetMember inside the watcher clobbers it → the original assignment stores under the wrong name. Strong real-bug candidate; copy-first is a two-line fix but is behavior-affecting → probe + own commit.
2. **Site A latent double-free** on the pname arg with a named-param type-2 watcher (D13). Un-probed; every suite watcher is register-preloaded.
3. **longjmp throws skip arm teardown** (firing-guard pop at B included — a throwing guarded watcher leaves a stale `g_watch_firing` entry, which also *permanently blocks GC* via 74314 until popped… verify the catch-side restore covers `g_watch_firing_count`; nothing in the arm does). Pre-existing; the core has the same exposure — not a migration blocker, but worth an audit line.
4. **Does migration change B-t1's param-bind location?** Today (no local frame) a type-1 watcher's params bind into the enclosing scope (nc_onstatus shape). The proposed flags preserve that (no `INV_LOCAL_SCOPE`). Normalizing to a local frame is the same family question the NC landing note left open — keep them aligned.
5. **D1 (undefined return)** needs a Flash-behavior verdict before any test pins it; Ruffle stores undefined, our fold may be masking a real difference in a passing test only by luck (no suite watcher omits `return`).
6. **Order-of-fire vs. special properties**: Site A sits after the `_focusrect`/`_soundbuftime` `handled` block, so watching those names never fires — inert unless a probe says Flash differs.
7. Migration sequencing: B (guarded, both types, richest ritual) first with the two lock tests; then C (+ receiver-context bracket kept arm-side); then A (trivial flag set, but its type-2 gate must stay outside to remain behavior-preserving). All three touch shared runtime → CI in **both** modes; watch the `watch*`/`add_property`/`textfield` clusters plus gnash `Object-v*`.

---

## soundFireCallback

Despite the name, this is the **generic ASObject event-callback dispatcher for Sound AND XML**: `Sound.onID3/onLoad/onSoundComplete` and `XML.onLoad/onData`.

### 1. Site inventory

- **Definition:** `soundFireCallback(app_context, sound_obj, name, name_len, cb_args, cb_arg_count)` — line 74124 (forward decl 1904). Returns `void`; callee's return value is discarded.
- **Call sites (all in action.c; none elsewhere):**
  - 2266 `"onID3"` (1 arg, BOOLEAN) and 2287 `"onLoad"` (1 arg, BOOLEAN) — inside `builtin_sound_loadSound`, **guarded by `#ifdef HAS_DATA_FILES`**.
  - 19452 / 19471 `"onLoad"` (1 arg, BOOLEAN) — `builtin_xml_onData` (default XML.prototype.onData → parse → onLoad).
  - 19525 / 19530 `"onData"` (1 arg, STRING or UNDEFINED) — `aq_dispatch_xml_load` (deferred XML.load payload; the failure path at 19530 needs **no** data file).
  - 74254 `"onSoundComplete"` (**0 args**) — `soundFireOnComplete`, called from `processSoundPlayback` (74257).
- **Completion pump:** `processSoundPlayback` is driven by simulated elapsed time, pumped from `swf_core.c:1438` (NO_GRAPHICS) and `swf.c:1152` (graphics native **and** browser-WASM). The audio backends never dispatch AS callbacks; one dispatch site. Note: `swf_headless.c` does **not** pump `processSoundPlayback` — onSoundComplete never fires in the headless loop (pre-existing, out of scope).
- **Globals touched, in order.** Shared prefix: `getPropertyWithPrototype` lookup, FUNCTION-tag + `func != NULL` checks, `g_special_depth++` with `MAX_SPECIAL_DEPTH` (66) bail. Type-2 arm (74135–74182): HCALLOC `regs` → push captured scopes (own `is_with`, own `scope_mc`) → push fresh local frame **on top** → `g_current_context` switch if `g_swf_version>=6 && base_clip` → `setVariableByName("this", OBJECT receiver)` → bare `g_call_depth++` → `advanced_func(ctx, cb_args, cb_arg_count, regs, receiver)` → teardown. Type-1/else arm (74183–74227): push cb_args **in reverse** → push fresh local frame **first** → captured scopes **on top of it** (inverted order) → same context switch → same `"this"` bind → bare `g_call_depth++` → `simple_func(ctx)` → teardown. `g_special_depth--` last.

### 2. Current ritual per arm

| Step | Type-2 | Type-1 (`else`) |
|---|---|---|
| Depth guard | bare `g_call_depth++/--`, **no max check**; `g_special_depth` guard outside branch | same |
| Captured scopes | yes, `is_with` copied (no force) | yes, but pushed **above** the local frame |
| Local frame | yes, on top (normal order), `scope_mc=NULL` | yes, **beneath** captured (inverted) |
| `this` | `setVariableByName("this", OBJECT)` → topmost non-with frame = the fresh local frame; ABI `this` = receiver ptr | same bind; under inversion the topmost non-with frame can be a **captured** frame (see divergence d) |
| this-stack / super / event-this-mc | none | none |
| Base clip | `g_swf_version>=6 && base_clip` → context switch (caller's version) | **same — both arms switch** (unlike LC, where only type-2 did) |
| Version switch / exec-func / ctor / override | none | none |
| Args | via ABI `args/num_args`; `regs` HCALLOC'd | **REVERSE push, no clamp, no pad** (74191) |
| Return value | discarded | discarded |
| NULL safety | `advanced_func` **unchecked** | `else` catches everything non-type-2; `simple_func` **unchecked** |

### 3. Proposed InvokeOpts mapping

One adapter, per-branch flags computed off `func->function_type` (the `lc_dispatch_method` shape):

- `this_var` = OBJECT(receiver). `act_flags = 0`. Return value: `(void)`.
- **Type-2:** `INV_CAPTURED_SCOPE | INV_LOCAL_SCOPE | INV_BIND_THIS | INV_BASE_CLIP`
- **Type-1:** `INV_CAPTURED_SCOPE | INV_LOCAL_SCOPE | INV_BIND_THIS | INV_BASE_CLIP | INV_LOCAL_SCOPE_UNDER_CAPTURED`
- **Stays outside:** property lookup + FUNCTION check, `g_special_depth` guard, the bare `g_call_depth++/--` bracket, the `__completed__` write in `soundFireOnComplete`, all caller-side arg construction.
- Do **not** use `INV_ACT_THIS` (current code binds unconditionally and never touches the this-stack) and do **not** use `INV_THIS_STACK`.

### 4. Divergences

a. **Type-1 reverse push, no clamp/pad** — TYPE1_ARG_ORDER class. **Latent on live paths**: every caller passes 0 or 1 args, so the reversal itself never misbinds; the missing **pad** is observable with a ≥2-param type-1 handler (exactly the `lc_onstatus_type1_args` failure shape), the missing **clamp** with a 0-param handler + 1 arg. Core fixes; candidate **new instance** if the repro fails-before (§7).
b. **Unchecked `simple_func` in a catch-all `else`** — the known NULL-call hazard class. `snd.onSoundComplete = MovieClip.prototype.getDepth` is a NULL call today. Core's strict dispatch returns undefined.
c. **Unchecked `advanced_func`** on type-2 — dead-code cleanup, not behavior to preserve.
d. **`this` bind target under the type-1 inversion.** `setVariableByName` writes to the topmost **non-with** frame; with captured scopes on top, a non-with captured frame (an outer function's local frame) receives the bind — persisting after the call (scope pollution). `INV_BIND_THIS` writes to the fresh local frame instead. **Lookup result is identical** either way; only the pollution differs. Per the guardrail, try the flag-mapped version and see if any test notices; expected inert. Note the bind is **live**, not dead: with no this-stack push and dispatch from the frame loop, `g_this_depth==0`, so `GetVariable("this")` falls through to the scope chain — the standing dead-bind rule does **not** apply here.
e. Args pushed before scopes (type-1) vs core's after — independent structures; inert.
f. Core's entry `g_execution_halted` check and unconditional `g_this_depth` restore — extra safety, inert.
g. No version switch / exec-func / this-stack / arguments — normalization pass (b) items, same list as `lc_dispatch_method`'s landing note. The EI dossier notes this function's comment claims it "mirrors the type-1 path in actionEI_callInternalInterface" — stale since `d8abc5c0a`; fix the comment when either lands.

### 5. Type-1 clamp/pad + NULL-call status

- Clamp/pad: **absent, reverse order** (74191–74192). One site, one loop.
- NULL-call: **hazard present** in both branches (74174 unchecked `advanced_func`, 74219 unchecked `simple_func` in a catch-all else).

### 6. Reachability

- **Type-2 arm — green-locked:** avm1 `sound_duration_position_props` (pass; onSoundComplete DefineFunction2 fired 7× deterministically), `sound_id3`, `sound_multiple_load`, `sound_start_load`, `xml_load` and the xml cluster, all pass.
- **Type-1 arm — LIVE with a green lock:** avm1 `sound_load_start` (pass; handler compiled as **DefineFunction, 0 params**) — 0 args/0 params, so the marshalling bug is latent there. gnash `XML-v5/v6` (ruffle_matched) and `Sound-v5..v8` (ruffle_matched) hit type-1 handlers with 1 arg/1 param (reverse==forward at 1). avm1 `swf5_xml_event_handler_context` (pass).
- ≥2-param type-1 handler (pad), 0-param+1-arg (clamp), and the NULL-call: **no suite coverage — needs probe**; write the repro instead.

### 7. Proposed repro/lock test design

**Cheapest deterministic route: the XML onLoad failure path** — no data file, no timing: hand-assembled SWF6 (model: `regression/lc_method_type1_args`) that builds a plain `DefineFunction` 2-param handler `function(success, pad)`, assigns it to `xml.onLoad`, calls `xml.load("missing.xml")` → deferred `aq_dispatch_xml_load` → `onData(undefined)` → default onData → `soundFireCallback("onLoad", [false])`. Expected fail-before: `pad=false`, `success=<caller-stack garbage>`; pass-after: `success=false, pad=` (SWF6 undefined-concat). Verify the deferred-load failure path queues in the regression harness before committing to the design. onSoundComplete itself is deterministically reachable but delivers 0 args — prefer the onLoad route. (See also the MCL/LoadVars dossier's `xml_onload_type1_args` design — same test, coordinate to write it once.)

### 8. Risks / open questions

- Not perf-sensitive (fires once per event, not per element).
- The dispatcher is shared by Sound and XML: CI watch list must include the **xml cluster + gnash XML-v5..v8 + Sound-v5..v8 + shumway XML tests**. gnash reds there are `ruffle_matched` — diff actual outputs byte-for-byte old-vs-new.
- Divergence (d): decide bind-frame parity by A/B, not by adding a new flag.
- Normalization pass (b) backlog: version switch, this-stack, exec-func, and whether the type-1 inversion should be flipped together with `__resolve`/EI.

---

## _invoke_sort_comparator

### 1. Site inventory

- **Definition:** line 60678, `static ActionVar _invoke_sort_comparator(app_context, comparator, a, b)` — returns the comparator's **raw ActionVar**; conversion to a sign happens at call sites.
- **Call sites (4, all inside `callArrayMethod`'s `sort` branch; `sortOn` never takes a comparator):** 61816 + 61837 (UNIQUESORT/RETURNINDEXEDARRAY index-quicksort) and 61997 + 62017 (standard **in-place** quicksort). Each site follows with `if (g_execution_halted) break;` then `varToDoubleSWF` → `-1/0/1` by sign. Comparator derived at 61695 via `lookupFunctionFromVar` (bare FUNCTION-tag unwrap, no thunk identity checks — none needed).
- **Globals touched, in order.** Shared: `g_call_depth++` (no max check, no `g_special_depth`). Type-2 arm: **nothing else** — bare `advanced_func(ctx, args, 2, NULL /*registers*/, NULL /*this*/)`. Type-1 arm: fresh local frame pushed **first** → captured scopes **on top** (inverted order) → `g_current_context` switch if `g_swf_version>=6 && base_clip` (caller's version) → `setVariableByName("this", UNDEFINED)` → **forward** push `args[0]`, `args[1]` → `simple_func(ctx)` → teardown.

### 2. Current ritual per arm

The ritual is minimal **on purpose** (per-element hot path):

| Step | Type-2 | Type-1 |
|---|---|---|
| Depth | bare `g_call_depth++/--` only | same |
| Scopes | **none at all** (no captured, no local) | local frame beneath captured (inverted); captured `is_with` copied |
| `this` | ABI `this = NULL` | `"this"=undefined` bound by name; no this-stack |
| Base clip | **none** | caller-version-gated switch (**inverse of LC's gating**) |
| Version switch / exec-func / super / event-this-mc / arguments | none | none |
| Registers | **`NULL` passed** even when `register_count>0` — safe because generated func2 bodies ignore the parameter and declare their own `regs[]` (verified: `func2_mySort_0` in avm1/array_sort) | n/a |
| Args | ABI `(args, 2)` | forward push of **exactly 2, no clamp to `param_count`, no pad** |
| Return | raw ActionVar, returned — **identical to the core's retrieval** in both arms; numeric-sign semantics survive migration unchanged | same |
| NULL safety | **already strict** both branches; `comparator==NULL` → undefined | same |

### 3. Proposed InvokeOpts mapping

- **Type-2:** `flags = 0`, `act_flags = 0`, `this_var = NULL`, `args, num_args=2`. (Behavior-identical except the register alloc — see §4/§8.)
- **Type-1:** `flags = INV_CAPTURED_SCOPE | INV_LOCAL_SCOPE | INV_LOCAL_SCOPE_UNDER_CAPTURED | INV_BASE_CLIP | INV_BIND_THIS`, `this_var = &undef` (UNDEFINED-typed; `this_ptr` derives NULL — no side effects).
- **Stays outside:** the bare `g_call_depth++/--` bracket, `args[2]` copy, `varToDoubleSWF` sign conversion, and **all** sort machinery — including the mutating-comparator policy. **Correction to this task's premise:** the policy is the opposite of "snapshot before mutating comparators": per the `array-sort-snapshot-mutating-comparator` memory and the block comment at ~61946, the standard sort deliberately runs **in place on the live array** to match Flash over Ruffle, plus the `_qs_inner > n*4+100` convergence guard. None of that is inside the invoker; migration must not touch it, and must not "fix" the in-place semantics.

### 4. Divergences

a. **Type-1 clamp/pad absent** (forward order already correct). Always pushes exactly 2: a **1-param comparator binds `b` into its only param** **and leaks `args[0]` on the value stack every comparison** — misbind + O(n log n) stack imbalance per sort; a **3-param comparator pops the caller's stack**. Core fixes; bug-class TYPE1, repro-gated (§7).
b. **Registers: `NULL` today vs core's `HCALLOC(register_count)` per call.** Behaviorally inert, but it converts today's zero-allocation type-2 path into **one heap alloc+free per comparison** for any DefineFunction2 comparator with registers (MTASC output preloads params → `register_count>=2` is the common case). This is the site's headline perf divergence — see §8.
c. **Type-2 skips captured scopes entirely.** A func2 closure comparator reading an outer function's locals resolves them to global/undefined today. Real latent-bug candidate; **preserve** (flags=0) in pass (a), record as normalization pass (b) item with a probe + test.
d. **`this`:** type-2 NULL-ABI-this vs type-1 `"this"=undefined` name bind — a between-arm inconsistency the mapping preserves exactly. The type-1 bind is **live only for root-level sorts** and lands on the topmost non-with frame — with a non-with captured frame on top, the old code pollutes the closure's outer frame (same nuance as soundFireCallback (d)); `INV_BIND_THIS` targets the fresh local frame; lookup-identical. Do **not** substitute `INV_THIS_STACK`.
e. No `arguments` object in the comparator (Flash provides one) — normalization pass (b) question.
f. Core's entry `g_execution_halted` early-out — the qsort loops already check halted after every call; inert.

### 5. Type-1 clamp/pad + NULL-call status

- Clamp/pad: **absent** (forward order correct) — 60730–60731.
- NULL-call: **clean.** The rare dispatcher already strict and NULL-checked in both branches.

### 6. Reachability

- **Type-2 arm — green-locked, heavily:** avm1 `array_sort` (pass; plus flags/UNIQUESORT/RETURNINDEXEDARRAY permutations hitting all four call sites) and especially **`array_sort_random`** (pass; SWF7, 50 elements, xorshift comparator that **traces every single comparison** — this is the behavior lock for the migration). gnash `array-v7/v8` (func2) — both `output_mismatch` (accepted sort-UB diffs), so the bar there is **byte-identical actual output** old-vs-new build, not status.
- **Type-1 arm — live only on already-failing tests:** gnash `array-v5/v6` comparators compile to `DefineFunction`. Both `output_mismatch`. **No green test covers the type-1 branch** — the repro test below doubles as the missing lock.
- 1-param / 3-param comparators: no known suite coverage — needs the new test.

### 7. Proposed repro/lock test design

Hand-assembled **SWF6** regression test (model: `regression/lc_method_type1_args`), e.g. `regression/sort_comparator_type1_args`. A plain `DefineFunction` **1-param** comparator `function(x) { trace("cmp:" + x); return 1; }` over a small fixed array (`[20, 10]` → one comparison per scan, fully deterministic with a constant return): fail-before traces `x = <b>` and leaks a stack slot per call; pass-after traces `x = <a>`. Add a second frame with a **3-param** comparator tracing all three (`p3` pops the caller's stack before the fix; `undefined`-padded after). Verify fail-before by the copy-parent-`action.c` method. Keep expectations pinned to the exact quicksort visit order the existing implementation produces (derive `output.txt` from the fixed algorithm, not from Flash intuition).

### 8. Risks / open questions

- **Perf — yes, this is the site that warrants the §5 fresh measurement.** The migration adds, per comparison on the type-2 path: two helper calls + flag tests (cheap) and — the real item — the **per-call `HCALLOC/FREE` of the registers array** (divergence b) where today there is zero allocation. Neither Minesweeper nor DJ sorts heavily; measure on a synthetic large-sort native build or gnash `array-v8` under `callgrind_annotate --threshold=100`. If material, the candidate fix is a *core-level* change (generated func2 bodies provably ignore the `registers` parameter — it exists for the native-builtin ABI only, and builtins have `register_count==0`), which would benefit every migrated site; that is a separate, separately-CI-gated commit.
- **Return-value semantics: verified safe.** Both arms already retrieve the callee's ActionVar exactly as the core does; `varToDoubleSWF` + sign stays outside; NaN/undefined → `_qcmp = 0` unchanged.
- **The in-place/mutating-comparator policy machinery is untouched by construction** — the memory and the ~61946 comment forbid "helpfully" revisiting it.
- gnash `array-v5..v8` are already failing: validate by diffing **actual outputs** old-vs-new.
- Open normalization (pass b) questions: captured scopes for type-2 comparators, `arguments`, version switch, `this` unification across arms.

---

## builtin_broadcaster_broadcastMessage (+ listener-family siblings)

All line numbers are the current working tree (@ ~`704a9cbbf`; they will drift; grep the symbols).

### 1. Site inventory

**The dispatcher itself** — `builtin_broadcaster_broadcastMessage`, action.c:33639–33959. One listener loop (33682–33953) containing the raw invocation ritual:
- type-2 arm: 33765–33865 (`func->advanced_func(...)` at 33853)
- type-1 arm: 33866–33948 (`func->simple_func` at 33937)
- balancing `else`: 33949–33952 (pops the super context only; skips the listener)

Pre-loop machinery (stays outside any migration): receiver fallback to `g_c_function_this_obj` (33646), method-name `convertString` via the value stack (33650–33661 — can run user `toString`), `_listeners` fetch via `getPropertyWithPrototype` (33666), array/emptiness gates (33667–33675).

Per-listener, pre-ritual (stays outside): element type filter OBJECT/MOVIECLIP/FUNCTION (33689–33703), dead-MC skip (`depth == INT_MIN`, 33694), method resolution — **manual proto walk** using `findPropertyRaw` + `isPropertyHiddenAtVersion`, tracking `method_search_depth` for super (33723–33742, depth clamped to ≥1), falling back to **global `getVariable`** for MC listeners (33743–33746, clears the super-context eligibility), and the **empty-method-name direct-call** path (33713–33719: the FUNCTION listener itself is the callee). Conditional `pushSuperContext(listener_obj, method_search_depth)` at 33760–33763 — note it receives `listener_obj` (an MC listener's `dynamic_props`), **not** the MC pointer, so it can never be `INV_SUPER_CTX` (which derives from `this_var`); it stays in the arm, bracketing the core, exactly like the `.call`/`.apply` precedent.

**Loop mutation semantics**: live index walk, `i < arr->length` **re-read every iteration**, elements re-fetched by index; `arr` pointer captured once (a listener replacing `this._listeners` does not redirect the loop). Contrast Ruffle (`broadcast_internal`): length read **once** before the loop, elements read live. So: listener **appended during dispatch** → we call it this broadcast, Ruffle does not; listener **removed during dispatch** → both shift live. See §8 — the gnash "broadcast-via-add" test may pin this.

**Direct C callers of the builtin** (no ritual of their own; they *bypass* user overrides of `broadcastMessage`): Key 35769/35782 (1 arg), Mouse 35797/35810/35823 (1 arg), Stage onResize 47568 (1 arg) / onFullScreen 47611 (2 args), Selection `selection_do_focus_change` 71764 (**3 args**), `fireMCLEvent` fallback 34054.

**Sibling raw dispatch loop** — `fireMCLEvent` (34023–34055): looks up `broadcastMessage` on the MCL object so instance overrides are respected, then its own raw ritual (see the MCL/LoadVars dossier). Belongs in the same migration neighborhood.

**Not in this family**: focused-MC onKeyDown/onKeyUp/onPress (72498–72545) and TextField `onChanged` go through `mc_call_as2_handler_ng`. Nothing broadcasts `onChanged`/`onScroller` to TextField `_listeners` at all (see §8).

**Globals touched (per listener)** — super-context stack (conditional); scope chain; `g_this_stack`/`g_this_depth`; `g_override_this`/`g_override_this_set` (type-2 MC listeners only); `g_prev_executing_func`/`g_current_executing_func`; heap (registers, local frame, arguments array). **Never touched**: `g_call_depth`, `g_special_depth` (no depth guard of any kind), `g_current_context` (no base-clip switch in either arm), `g_swf_version`/`global_object` (no version switch), `g_event_this_mc`.

### 2. Current ritual per arm

**Type-2** (33765–33865), in order:
1. (arm, before split) conditional `pushSuperContext(listener_obj, method_search_depth)` when `found_method_for_super && listener_obj` (33760).
2. Registers alloc if `register_count > 0`.
3. Captured scopes restored **gated on `g_swf_version >= 6`** — the CALLER's version (33770–33777).
4. Reads DefineFunction2 preload/suppress bits (33788–33794).
5. Fresh local frame; **`this` bound on it AND pushed to `g_this_stack` only when `!preload_this && !suppress_this`** (33798–33814) — value: MOVIECLIP(mc) / OBJECT(listener_obj) / UNDEFINED when both NULL. Exactly `INV_ACT_THIS` type-2 semantics.
6. `arguments` built when `!preload_args && !suppress_args` (33817–33826): capacity `max(extra_count,1)`, `setupArgumentsProps` with the pre-swap `g_current_executing_func` as caller. (Core type-2 capacity is `num_args` exactly — inert, `allocArray` clamps capacity to ≥4.)
7. `super` bound **always** (33827–33836): SUPER(listener_obj, depth) only when `!preload_super && !suppress_super && g_swf_version >= 6 && super_pushed`, else UNDEFINED. This is the shadow that hides the *outer* invocation frame's `super` binding.
8. Frame pushed with `is_with=0`, **`scope_mc=NULL` even for MC listeners** (33837–33841) — binds-then-push vs core's push-then-bind: inert.
9. MC listeners only: `g_override_this = MOVIECLIP(mc)`, `_set=1` (33845–33850); cleared after the call only if still set and only in the MC case.
10. `g_prev_executing_func`/`g_current_executing_func` swap (33851–33852) — same pair of writes as `INV_EXEC_FUNC`.
11. Call: `advanced_func(app_context, extra_args, extra_count, regs, listener_obj)` — **ABI `this` is `listener_obj`** (an MC's `dynamic_props`), *not* the MC pointer. Args pass through unclamped/unpadded — correct for type-2.
12. Teardown: exec restore, frame pop + release, `g_this_depth` restore, captured pops, regs free, conditional `popSuperContext`.

**Type-1** (33866–33948):
1. Captured scopes, same `g_swf_version >= 6` gate.
2. `g_this_stack` push, **unconditional**: MOVIECLIP(mc) else **OBJECT(listener_obj) — even when `listener_obj` is NULL** (33876–33887). (The type-2 arm binds UNDEFINED in that corner; the two arms disagree. Reachable only via `broadcastMessage("")` on a FUNCTION listener with `own_props == NULL`.)
3. Fresh local frame with `arguments` (capacity `max(extra_count,1)`, matches core type-1) and the **`super` shadow** — SUPER(listener_obj, depth) when `g_swf_version >= 6 && super_pushed`, else UNDEFINED (33897–33917). **This type-1 super bind is NOT dead** — see §4(a).
4. Frame pushed (`is_with=0`, `scope_mc=NULL`).
5. Value-stack marshalling (33926–33933): forward order, **pads** to `param_count` with UNDEFINED, but **does NOT clamp** — when `extra_count > param_count` all extras are pushed, the callee pops only `param_count` (binding the LAST args to params) and the surplus is stranded on the stack. TYPE1 clamp-bug class, claimable (§5, §7).
6. exec swap, call `simple_func`, exec restore.
7. Teardown: frame pop + release, `g_this_depth` restore, captured pops, conditional `popSuperContext`.

**Balancing else** (33949–33952): non-dispatchable func → only `popSuperContext` if pushed. NOT dead code — the pop must survive migration; bracketing the core with the arm-level push/pop preserves it for free.

### 3. Proposed InvokeOpts mapping per branch

Migration replaces only 33765–33952 with a bracketed core call. The loop, element filtering, method resolution + `method_search_depth`, and the conditional `pushSuperContext`/`popSuperContext` bracket all stay in the arm.

**Both types (per-listener opts, computed off `func->function_type`):**
- `flags = (g_swf_version >= 6 ? INV_CAPTURED_SCOPE : 0) | INV_LOCAL_SCOPE | INV_EXEC_FUNC`, plus `INV_OVERRIDE_THIS` **only when `function_type == 2 && listener_mc != NULL`** (with `opts->override_this = &(MOVIECLIP mc var)`).
- `act_flags = INV_ACT_THIS | INV_ACT_ARGUMENTS | INV_ACT_SUPER` — THIS and ARGUMENTS match both arms; SUPER: **does not fully map — see §4(a/b), this is the one core gap**.
- `this_var`: MOVIECLIP(listener_mc) if MC; else OBJECT(listener_obj); both-NULL corner is arm-dependent today — construct per `function_type` for exact preservation, or A/B the corner away.
- `has_this_ptr = 1, this_ptr = listener_obj` — the ABI receiver is the dprops/own_props object, never the MC pointer, so the core's derivation from `this_var` must be overridden.
- `INV_EXEC_FUNC` is safe here: the site already writes **both** exec-func globals, and `INV_ACT_ARGUMENTS` requires the core to own the swap anyway.
- **Off**: `INV_DEPTH_GUARD` (site has no guard at all — do not add), `INV_THIS_STACK` (rides in act_flags), `INV_SUPER_CTX` (push stays in arm; receiver is `listener_obj`, and it must also happen when the core ends up skipping the call), `INV_BIND_THIS`, `INV_BASE_CLIP`, `INV_VERSION_SWITCH`, `INV_EVENT_THIS_MC`, `INV_LOCAL_SCOPE_MC`, `INV_RESET_THIS_DEPTH`, `INV_CTOR_CTX`, `INV_LOCAL_SCOPE_UNDER_CAPTURED`.

**fireMCLEvent:** `flags = 0`, `act_flags = 0`, `has_this_ptr = 1, this_ptr = mcl`, `this_var = OBJECT(mcl)`. The core reproduces the type-2 bare call and its canonical clamp+pad loop fixes the type-1 marshalling. The override lookup stays outside.

### 4. Divergences

a) **Type-1 `super` name-shadow — the core cannot express it, and it is LIVE and TEST-PINNED.** `INV_ACT_SUPER` is a type-2 no-op (15297: `&& is_t2`). The standing "type-1 super binds are dead" rule assumes the chain *misses* and falls to the live-context fallback. Here the chain does NOT miss: bytecode-invoked `broadcastMessage` runs inside its own actionCallMethod invocation frame, whose local scope binds `super = SUPER(broadcaster, …)` and stays on the chain for the whole loop. Without the shadow, a type-1 listener's `GetVariable("super")` hits the broadcaster's super — the exact bug the comment documents (gnash AsBroadcaster.as:312 `super.add(o)` → "B" instead of "AB"). Pinned: `from_gnash/actionscript.all/AsBroadcaster-v6` (11× DefineFunction; its `ruffle_matched` baseline output contains `PASSED: o.msg == "AB" [./AsBroadcaster.as:312]`). **Do NOT widen `INV_ACT_SUPER` to bind on type-1 globally.** Proposal: a new `InvokeOpts` field, e.g. `ActionVar* super_bind` — when non-NULL and `INV_LOCAL_SCOPE`, the core binds it as `"super"` on the local frame for **both** function types; the arm computes the value (incl. the preload gate for t2). Classification: **preserve; blocker until the core grows this**.

b) **Type-2 `INV_ACT_SUPER` value-source mismatch.** Core binds SUPER whenever `hasSuperContext()`; the site binds SUPER only when *this arm* pushed (`super_pushed`). When the method came from the MC `getVariable` fallback during a bytecode-invoked broadcast, an OUTER live super context exists → core would bind SUPER(broadcaster), site binds UNDEFINED. The `super_bind` field from (a) subsumes this exactly.

c) **SWF5 gating.** Site pushes the super *context* unconditionally on version but gates the *binding value* on `g_swf_version >= 6`. Subsumed by (a)'s arm-computed value. Near-inert.

d) **`arguments` capacity** `max(n,1)` vs core's `n` for type-2 — inert (`allocArray` clamps to ≥4).

e) **Both-NULL `this` corner**: type-2 binds/pushes UNDEFINED, type-1 pushes OBJECT(0). Construct `this_var` per `function_type` for exactness, or A/B — no test plausibly covers it.

f) **Bind-then-push frame ordering** — inert.

g) **Captured-scope version gate** uses the caller's `g_swf_version` — compute in the arm (`INV_CAPTURED_SCOPE` conditional). Do not "fix" toward the MC arms' callee gate in the migration commit.

h) **fireMCLEvent type-2 bare call**: mapping to `flags=0` is exact. The lack of scaffolding for user overrides is a normalization question.

i) **No depth guard / no `g_special_depth`** anywhere in the family: a listener that re-broadcasts recurses unguarded. Preserve; normalization candidate.

### 5. Type-1 clamp/pad + NULL-call status

| Site | Order | Pad | Clamp | NULL-call |
|---|---|---|---|---|
| broadcastMessage type-1 | forward ✓ | ✓ | **✗ — extras all pushed, last-N bind to params, surplus stranded** | safe — both arms strict; else only balances super pop |
| broadcastMessage type-2 | pass-through (correct) | n/a | n/a | safe |
| fireMCLEvent type-1 | forward ✓ | **✗** | **✗** | safe |
| fireMCLEvent type-2 | pass-through | n/a | n/a | safe |

**No NULL-call hazard in this family.** The claimable marshalling bug is the **missing clamp** in broadcastMessage's type-1 arm — genuinely reachable (multi-arg broadcasts exist in-tree: Selection passes 2 extras, Stage onFullScreen 1, MCL onLoadProgress 2/onLoadError 2). fireMCLEvent's type-1 arms are reachable only through a user-assigned type-1 `broadcastMessage` override — fix during migration; per the `bdRectangleGetter` precedent, don't credit without a probe.

### 6. Reachability

- **avm1** (all `pass`): `as_broadcaster` (4× DefineFunction2 + 1× DefineFunction), `as_broadcaster_initialize`, `as_broadcaster_undef`, `mcl_as_broadcaster`, `mouse_listeners` (SWF6 — defines **no functions**; exercises add/removeListener plumbing only), `key_isToggled`, `stage_display_state`, plus the `tab_ordering_*`/`focus_*` cluster (Selection onSetFocus, 3-arg path).
- **from_gnash/actionscript.all**: `AsBroadcaster-v6` (**11× DefineFunction → the type-1 arm incl. the super shadow; pins :306/:312**, status `ruffle_matched`), `AsBroadcaster-v7` (11× DefineFunction2 → type-2, `ruffle_matched`), `Key-v6/v7/v8` (`pass`), `Mouse-v7` (`pass`), `Stage-v8`, `MovieClipLoader-v8`, `Selection-v8` (`ruffle_matched`).
- **Needs probe**: MC-listener branch (`g_override_this` type-2 path), the MC `getVariable` global-fallback branch, the empty-method-name direct-call branch, FUNCTION-typed listener elements, both fireMCLEvent override arms, and the type-1 **clamp** case (extras > params) — almost certainly unreached, hence the repro.

### 7. Proposed repro/lock test design

`regression/broadcast_type1_args`, hand-assembled SWF6 (model: `lc_method_type1_args`):

1. `DefineFunction handler(a, b)` tracing `a=`/`b=`.
2. `o = {}` → `AsBroadcaster.initialize(o)` (available unversioned in our runtime, 39014–39041); `l = {}; l.onTest = handler; o.addListener(l)`.
3. Three broadcasts: `("onTest","one","two")` (order lock), `("onTest","solo")` (pad lock — currently correct, keep pinned), `("onTest","x1","x2","x3")` (**the clamp repro**: expected `a=x1, b=x2`; current code pushes all three and the callee pops two → `a=x2, b=x3` with `x1` stranded — end the frame with a sentinel trace after one extra push/trace pair so the imbalance surfaces).
4. SWF6 guarantees DefineFunction; invoking `broadcastMessage` via CallMethod from bytecode puts the outer local frame + live super context on the chain, so the ritual runs in its most demanding configuration.
5. Verify FAIL-before against the parent commit's `action.c`. Synchronous — no frame-boundary wait.

### 8. Risks / open questions

- **The type-1 super shadow is the migration blocker** (§4a). Decide the core extension (`super_bind` field vs. per-type act-flag) *before* touching the site; `AsBroadcaster-v6` is the tripwire, and its status is `ruffle_matched`, so a regression shows as output drift, not a pass→fail — diff actual outputs.
- **List-mutation semantics may be test-pinned** (the "broadcast-via-add" case). The migration doesn't touch the loop; any future "normalize to Ruffle's snapshot" idea must probe first. The stale-`arr`-after-`_listeners`-replacement behavior matches Ruffle; no action.
- **No depth guard**: unbounded re-broadcast recursion. Normalization candidate, own commit + test.
- **No version switch / no base-clip switch in either arm** — same normalization queue as `mc_call_as2_handler_ng`. Note this site is *unlike* LC: even its type-2 arm skips base-clip.
- **Key/Mouse/Stage/Selection C dispatchers bypass `broadcastMessage` overrides** while fireMCLEvent honors them — asymmetric but matches Ruffle; leave alone.
- **TextField listeners are wired but never fired**: `installAsBroadcaster` runs on TextFields (15985) yet nothing broadcasts `onChanged`/`onScroller` to `_listeners`. Possible missing feature, out of Stage-4 scope — worth a note in the suite investigation docs.
- Method-name `convertString` can execute user `toString` before the loop; return value (`true` vs Ruffle's false-on-empty) differs slightly — both outside the ritual; don't "clean up" in the same commit.
- fireMCLEvent's `args[8]` buffer silently truncates at 7 extras — preserved by any migration.

---

## Async-load callbacks: fireMCLEvent / fireLoadVarsCallback / XML (via soundFireCallback)

Line numbers @ `704a9cbbf` — grep symbols after any migration.

### 1. Site inventory

**`fireMCLEvent` (34023) — it delegates.** It does NOT loop listeners: it resolves `broadcastMessage` on the MCL object via `getPropertyWithPrototype` (normally `g_ab_broadcastMessage_func`, the type-2 native) and invokes *that one function* raw, args = `[event_name_string, extra_args...]` (built into `ActionVar args[8]`, extras clamped to 7). Listener iteration lives in `builtin_broadcaster_broadcastMessage` (separate dossier). Only a *user-scripted override of `broadcastMessage` itself* reaches fireMCLEvent's own arms; if `lookupFunctionFromVar` fails, it falls back to calling the builtin directly (34054) — a plain C call.

**Callers** — all five inside `actionFirePendingLoadInits` (34487), the `_this_tick` drain:
- Phase 1 (FIFO, per load): `onLoadStart(target)` 34581 → `onLoadProgress(target, bytesLoaded, bytesTotal)` 34610 (fired **twice** for root replacement) → `onLoadComplete(target, 0)` 34624. For root replacement the drain **swaps `g_swf_version`/`global_object` to the child's between onLoadStart and onLoadProgress** (34587–34598) and restores after onLoadComplete.
- Phase 2: child `init_func` + `frame_funcs[0]` under child context.
- Phase 3 (LIFO): `onLoadInit(target)` 34731 (under child version for root loads) | `onLoadError(target, "URLNotFound", 0)` 34742 | non-.swf `onLoadInit` 34746.

**Queue**: two-bucket `PendingMCLLoad` — `g_pending_mcl_loads_this_tick`/`_next_tick`. Enqueue: `builtin_mcl_loadClip` (34212). Promote: `actionPromotePendingMCLLoads` at top-of-tick and promote-on-stop in `tagShowFrame`. The drain **copies `loads[]` locally and zeroes the bucket before firing** (34493–34496) so handlers can chain-queue.

**Globals touched by fireMCLEvent itself: none** — no `g_call_depth`, no `g_special_depth`, no scopes, no this-stack, no exec-func, no base-clip. The version swap is done by the *drain*, outside the dispatcher.

**`fireLoadVarsCallback` (37102).** Resolves handler by name via `getPropertyWithPrototype` **at fire time** (queue stores the receiver, never the handler). Call sites: `processLoadVarsLoads` (37197) → `"onData"` with 1 arg (raw UTF-16 string / undefined) 37231 — called from the frame loops **immediately after `processTimers`**, `while(count>0 && guard++<16)` so chained `load()`s re-fire **same tick** (unlike MCL's two-bucket deferral); and `builtin_loadvars_default_onData` (37242, type-2 native default) → `"decode"` 37256 and `"onLoad"` (success bool) 37265 — re-entrant use of the same dispatcher from inside a callee it invoked.

**Queue**: `PendingLoadVarsLoad {lv (refcount held), content, success}`, `g_pending_lv_loads[32]`. Enqueue in `builtin_loadvars_load` with `retainObject(lv)`; drain releases per entry after onData. Before onData, drain writes final `_bytesLoaded`/`_bytesTotal`.

**Globals, in order** (`fireLoadVarsCallback`): `g_special_depth` guard (37110) → push `g_this_stack` (OBJECT lv) → `g_prev/g_current_executing_func` swap → push captured scopes (is_with copied) → push fresh local scope **on top** → build `arguments` array, **both types, unconditionally**, capacity `max(n,1)`, caller passed as **`prev_prev` (the grandparent!)** (37150–37159) → base-clip switch gated `g_swf_version >= 6` for **both** arms → type-dispatch with bare `g_call_depth++/--` → teardown restores context, scopes, **both** exec-func globals, `g_this_depth`, `g_special_depth`.

**XML onData/onLoad — dispatches through `soundFireCallback`** (see that dossier for the ritual). `XML.load` (19542) enqueues on the **general ActionQueue** (`AQ_KIND_SCRIPT`) — NOT the LoadVars queue; drains at **end of the current frame script / SHOW_FRAME**, earlier in the tick than LoadVars (post-timers) and MCL. `aq_dispatch_xml_load` (19489) resets DOM, then `soundFireCallback(doc,"onData", src|undefined, 1)`; default `builtin_xml_onData` parses then fires `"onLoad"`. Default `onLoad` = `builtin_noop_func` — a pointer-identity thunk, but soundFireCallback performs **no identity checks** (it runs the noop with full ritual; cost only).

**GC roots (commit `427f0abb1`)**: both MCL buckets' `.mcl`, `g_pending_lv_loads[].lv`, and XML payload docs via `actionQueueGcForEach(gcMarkXmlLoadPayload)` — which matches entries **by function pointer `fn == aq_dispatch_xml_load`** (74332). Renaming/splitting that function during migration silently un-roots every pending XML doc. GC runs only at tick boundaries — that is what makes the MCL drain's copy-and-zero safe.

### 2. Current ritual per arm

**`fireMCLEvent`** (both arms bare):

| Step | type 2 (34039–34044) | type 1 (34045–34048) |
|---|---|---|
| guards | none | none |
| scopes | **none** | none |
| this | `mcl` as ABI this_ptr only | **nothing** |
| base clip / version / exec-func | none | none |
| args | regs HCALLOC'd; args by pointer | pushes **all** `1+extra_count` args **FORWARD** (order correct), **no clamp/pad** |
| NULL safety | `advanced_func != NULL` checked | `simple_func != NULL` checked; other types silently no-op |

Per-event marshalling: onLoadStart/onLoadInit → 1 extra; onLoadProgress → 3; onLoadComplete → 2; onLoadError → 3. Uniform per event across both function types.

**`fireLoadVarsCallback`** (arms share one ritual; only the invoke step differs):
- type 2 (37166): regs alloc; `advanced_func(cb_args, n, regs, obj)`; **no `advanced_func` NULL check**.
- "type 1" (37174, actually an `else` catching *everything* ≠ 2): pushes args in **REVERSE** (misbinds order for ≥2 args), **no clamp/pad**; **no `simple_func` NULL check** → both-pointers-NULL natives assigned as `onData`/`onLoad` are a NULL call.

### 3. Proposed InvokeOpts mapping per branch

All keep outside the core: handler lookup at fire time, `g_special_depth` guard (LV), the bare `g_call_depth++/--` bracket (LV), the drain's root-replacement version bracket (MCL), the fallback direct builtin call (MCL).

**`fireMCLEvent`** — simplest adapter of the family, one unconditional opts for both arms:
```
this_var = OBJECT(mcl);  InvokeOpts opts = { .flags = 0 };
invokeFunctionValue(app_context, bm_func, &this_var, args, 1+extra_count, &opts);
```
flags=0 gives exactly the bare call: core derives `this_ptr = mcl` for the ABI slot, pushes nothing, and replaces the unclamped forward push with canonical forward+clamp+pad. Do **not** add `INV_DEPTH_GUARD`.

**`fireLoadVarsCallback`** — one opts for both arms:
```
flags = INV_THIS_STACK | INV_CAPTURED_SCOPE | INV_LOCAL_SCOPE | INV_BASE_CLIP | INV_EXEC_FUNC
act_flags = INV_ACT_ARGUMENTS       // requires core-owned INV_EXEC_FUNC — satisfied
this_var = OBJECT(lv)
```
Use `INV_THIS_STACK`, **not** `INV_ACT_THIS` — the current code pushes the this-stack once and never name-binds `this`; INV_ACT_THIS would add a type-2 name bind and (worse) double-push. `INV_BASE_CLIP` stays unconditional (both arms gate on ambient version, matching the core's gate). No `INV_VERSION_SWITCH`. Type-1 capacity `max(n,1)` matches the core's type-1 arguments capacity exactly; n is always 1 here so the type-2 capacity split is inert.

The three dispatchers **cannot share one adapter shape**: LV is {this-stack, exec-func, arguments, normal scope order}; XML/Sound is {name-bound this, no exec-func, no arguments, inverted scope order in type-1}; fireMCLEvent is bare.

### 4. Divergences (current code vs mapped flags)

| # | Site | Divergence | Class |
|---|---|---|---|
| 1 | LV+XML type-1 | args REVERSE, no clamp/pad → core forward+clamp+pad | **bug-class fixed by core**. Order component *unobservable at current call sites* (every call passes exactly 1 arg); pad/clamp component observable |
| 2 | MCL type-1 | forward (correct) but no clamp/pad | bug-class fixed by core |
| 3 | LV type-2 + `else` arms | no NULL checks | **NULL-call hazard class**; core fixes for free |
| 4 | LV | `setupArgumentsProps` caller = `prev_prev` (grandparent) vs core's true caller → `arguments.caller` differs | near-inert (fires from frame loop where both are typically NULL); A/B it — if no test notices, don't flag it |
| 5 | LV | `arguments` bound even for type-2 with suppress-args flags; core suppresses | near-inert; core behavior is the Flash-correct one |
| 6 | LV | teardown restores `g_prev_executing_func`; core doesn't | inert in practice; note in the migration comment |
| 7 | all three | no `switchToFunctionVersion` — for MCL the ambient version is *deliberately staged* by the drain's root-replacement brackets | **preserve**; adding INV_VERSION_SWITCH would fight the drain's child-version bracket (which keys on `entry->swf_version`, not `func->swf_version` — different semantics entirely) |

### 5. Type-1 clamp/pad + NULL-call status per site

| Site | order | clamp/pad | NULL-call | claimable? |
|---|---|---|---|---|
| fireMCLEvent 34045 | forward ✓ | **missing** | safe | via scripted override only — obscure; fix, don't credit without probe |
| fireLoadVarsCallback 37174 | **reverse** (inert @1 arg) | **missing** | **hazard** | **yes — expect a new numbered instance** |
| soundFireCallback 74191 | **reverse** (inert @1 arg) | **missing** | **hazard** | **yes — second new instance (XML side)** |

### 6. Reachability

- **fireMCLEvent type-2 (native bm)**: every MCL test — avm1 `mcl_loadclip*`, `mcl_unloadclip`, `mcl_getprogress`, `mcl_as_broadcaster`, `mcl_events_swf_version`, `mcl_loadclip_replace_root`, `mcl_replace_root_swf7_to_swf5/6`, `mcl_target_*`, `moviecliploader_flashvars`, `load_cancel_via_unloadclip`; shumway `avm1/moviecliploader`; gnash `MovieClipLoader-v5..v8`. All pass/ruffle_matched.
- **fireMCLEvent type-1 + builtin fallback**: no known test overrides `broadcastMessage` — **needs probe** (expect zero).
- **fireLoadVarsCallback type-2**: avm1 `load_vars` (output_mismatch — the accepted sync-model diff), gnash `LoadVars-v7/v8` (ruffle_matched).
- **fireLoadVarsCallback type-1**: gnash `LoadVars-v5` (pass) / `LoadVars-v6` (ruffle_matched) are makeswf-compiled → plain DefineFunction handlers — **likely live, latent** (handlers declare 1 param = delivered count). **Needs probe** before crediting.
- **soundFireCallback via XML**: avm1 `xml_load` (pass, SWF8 → type-2), `xml` (pass), `xml_getbytes` (accepted mismatch); gnash `XML-v5..v8` (ruffle_matched; v5/v6 type-1 likely live, latent — needs probe).
- **soundFireCallback via Sound**: avm1 sound tests + gnash `Sound-v5..v8` — migration blast radius, verify cluster.

### 7. Proposed repro / lock test design

**Data-file infrastructure works in `regression/`**: `verify_output.py` auto-embeds any non-{swf,fla,toml,json,c,h,py} file in the test dir via `find_data_files` → `data_registry.c` + `-DHAS_DATA_FILES` (model: `avm1/load_vars/testvars.txt`, `avm1/xml_load/whataload.xml`); extra `.swf` files become child movies. All repros are self-contained offline.

1. **`lv_ondata_type1_args`** (claims instance for fireLoadVarsCallback): SWF6; `_root.lv = new LoadVars()`; `lv.onData = DefineFunction(a, b)`; `lv.load("vars.txt")` (`vars.txt`: `x=1&y=2`); marker trace. `num_frames = 2`+ (fires post-timers). Expect after fix: `a=x=1&y=2`, `b=`. Before: `b` pops a stale end-of-frame stack.
2. **`xml_onload_type1_args`** (claims instance for soundFireCallback): SWF6; `doc = new XML()`; `doc.onLoad = DefineFunction(a, b)`; `doc.load("doc.xml")` (tiny XML file). Default onData parses and fires onLoad(true) through the type-1 arm → expect `a=true, b=`; misbind before. Fires at frame-script end (AQ drain).
3. **NULL-call locks**: `lv.onData = MovieClip.prototype.getDepth` then `load(...)`; same for `doc.onData`. Crash before, silent undefined after.
4. **`mcl_broadcast_type1_args`** (optional): only if a probe justifies it — order is already forward, so only pad/clamp is claimable; per the `bdRectangleGetter` precedent, fix but don't credit without a probe hit.

Byte-compare the already-failing `load_vars`/`xml_getbytes` actual outputs old-vs-new (accepted diffs — the bar is *unchanged*, not passing).

### 8. Risks / open questions

- **Tick-timing coupling**: none of the proposed flags change *when* anything fires. The load-bearing timing lives outside: two-bucket promote/defer (mcl_load_timing), the LoadVars post-timers drain with same-tick chaining (guard 16), XML's frame-script-end AQ drain. Migration must not move the handler lookup earlier than fire time (queues store receivers, not handlers — an early read-out would change which handler runs when scripts reassign `onData` between load and fire, and would create unrooted ActionVars the GC commit deliberately avoided).
- **GC ordering**: the MCL drain's local `loads[]` copy is outside the root set once the bucket is zeroed; safe *only because* GC runs at tick boundaries. Don't introduce anything that can collect mid-drain. `gcMarkXmlLoadPayload` matches by the `aq_dispatch_xml_load` function pointer — do not rename/split it.
- **MCL root-replacement version brackets** stay in the drain, exactly where they are — ambient-version staging keyed to the loaded child's version, orthogonal to (and incompatible with) `INV_VERSION_SWITCH`.
- **soundFireCallback blast radius**: one migration commit changes XML, Sound onID3/onLoad (synchronous, fired mid-user-script where `g_this_depth > 0` — the this-cell then shadows the name bind; keep the mapping identical and verify the sound cluster), and onSoundComplete.
- **Sync-model overhang**: `load_vars`, `xml_getbytes`, gnash `LoadVars-v6/7/8` are output_mismatch *by accepted design*. Regressions there show as changed actual output, not status flips.
- **Normalization pass (b) candidates**: exec-func + arguments for soundFireCallback (type-2 XML handlers' `arguments` are broken today); this-stack for soundFireCallback; scope-order flip for its type-1 arm (shared with the `__resolve`/EI flip decision); `switchToFunctionVersion` for all three (must compose with MCL's root-replacement brackets); captured scopes for fireMCLEvent's override arms.
- **Open questions**: (a) do gnash v5/v6 actually reach the LV/XML type-1 arms (probe before crediting); (b) does anything reach fireMCLEvent's own arms (expect no); (c) whether `form_loader_encoding_*` go through `g_pending_lv_loads` at all or the separate `loadVariables` flag path (46713) — check before claiming.

---

# Cross-cutting synthesis (all 8 dossiers)

**New TYPE1_ARG_ORDER instance candidates** (each needs its fail-before repro to be credited):
1. `fireTimerCallback` both forms — pad+clamp, latent on live paths → `regression/timer_type1_args` (function-form AND method-form rows).
2. `broadcastMessage` type-1 — **clamp only** (pads correctly!) → `regression/broadcast_type1_args`.
3. `fireLoadVarsCallback` type-1 — reverse+no clamp/pad + NULL-call hazard → `regression/lv_ondata_type1_args`.
4. `soundFireCallback` type-1 — reverse+no clamp/pad + NULL-call hazard → `regression/xml_onload_type1_args`.
5. Watch Site B type-1 — no clamp (always 4) → `regression/watch_setmember_type1_args`.
6. Watch Site C type-1 — no clamp/pad + drops userData → `regression/watch_mc_type1_args`.
7. `_invoke_sort_comparator` type-1 — no clamp/pad (forward) → `regression/sort_comparator_type1_args`.
8. Coercion paths type-1 (all four sites push NOTHING) → `regression/coerce_type1_args`.
9. `call_function_with_this` type-1 — no clamp/pad, but zero suite reachability (asfunction click) → fix, don't credit.

**Blockers / decisions needed before specific migrations:**
- **`fireTimerCallback` TU boundary**: it lives in timer.c; the core is static in action.c. Recommended: export a non-static `actionInvokeFunctionValue` wrapper + the flag block via `action_internal.h` (precedent: `actionSwitchToFunctionVersion`).
- **`broadcastMessage` type-1 super shadow**: the core cannot express a type-1 `super` name bind; needs a new `InvokeOpts` field (`ActionVar* super_bind`) — a small core extension, its own commit, before that migration. `AsBroadcaster-v6` (ruffle_matched) is the tripwire — diff actual outputs.
- **Watch family**: real-bug candidates beyond dispatch — Site C's static `_sm_buf` clobber across the watcher call, Site A's latent pname double-free, D1 return-fold vs Ruffle. Each needs a probe/own commit.

**Corrections to the Stage-4 prompt to fold in when next editing it:**
- "Coercion paths skip switchToFunctionVersion" is half-true: oCVO/oCTS main branches DO switch; objectToPrimitive/convertFloat/c_f_w_t and the getter sub-branches don't.
- `soundFireCallback`'s "mirrors EI" comment is stale (EI was fixed in Stage 0; sound still reverses).
- onEnterFrame/onLoad/onConstruct/onUnload do NOT go through `mc_call_as2_handler_ng` — `actionDispatchEnterFrameHandlers` + siblings are their own (unlisted!) Stage-4 family, with a callee-version base-clip gate and version switch the input-event dispatcher lacks.

**Suggested migration order** (independent commits, easiest→hardest, each CI-gated both modes):
1. `fireMCLEvent` (flags=0, trivial) — but coordinate the GC function-pointer constraint.
2. `soundFireCallback` + `fireLoadVarsCallback` (+ 2 repro tests, 2 instances, NULL-call fixes).
3. `mc_call_as2_handler_ng` (exact flag mapping exists; heavily covered; measure Ir on Minesweeper after).
4. `_invoke_sort_comparator` (+ repro; watch the per-call HCALLOC perf question — measure before/after on a sort-heavy workload).
5. Coercion paths (oCVO/oCTS/objectToPrimitive/convertFloat + c_f_w_t; + `coerce_type1_args` repro; hottest lookup path but the dispatch tail is cold).
6. `fireTimerCallback` (needs the TU export decision + probe + `timer_type1_args`).
7. EI (needs the `ei_closure_scope_order` lock test first; second user of INV_LOCAL_SCOPE_UNDER_CAPTURED).
8. Watch arms B → C → A (+ 2 repro tests; the `invokeWatchCallback` shared adapter).
9. `broadcastMessage` (LAST — needs the `super_bind` core extension first).

**Normalization pass (b) master list** (each its own commit + test, AFTER the family is migrated):
- `switchToFunctionVersion` for: mc_call_as2_handler_ng (test design ready: `mc_event_cross_swf_version`), EI, broadcaster, watch arms, objectToPrimitive/convertFloat/c_f_w_t, LV/XML/sound. NOT for MCL (drain brackets own the version).
- The `INV_LOCAL_SCOPE_UNDER_CAPTURED` flip: __resolve + EI + soundFireCallback + sort comparator together, one commit, flipping the lock tests.
- The callee-vs-caller version gate unification (MC arms + fireTimerCallback function-form are the callee-gate instances).
- The missing depth guards (coercion recursion, broadcaster re-broadcast, watch A/C re-fire).
- Watch D1 (return fold), D6 (userData), D8 (old-value source); convertFloat's missing type-1 this push; sort comparator captured scopes for type-2; LV grandparent-caller.
