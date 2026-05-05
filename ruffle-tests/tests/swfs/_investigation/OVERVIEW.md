# Test Suite Overview

Cross-suite summary of all Ruffle-derived test suites. Each suite has its own `_investigation/` directory with detailed status docs.

Last updated: 2026-05-04 (Shumway fuzz `this._currentframe` fix: 5+ fuzz tests → PASS via syncing `mc->currentframe` to `obj->sprite_current_frame+1` during natural advance in `advance_sprite_frames`).

## Suite Summary

"Effective pass" = raw pass + `ruffle_matched` (diffs ⊆ Ruffle's diffs against Flash; auto-promoted when upstream has `known_failure=true` + `output.ruffle.txt`).

| Suite | Tests | Pass | RM | Effective | Effective Rate | Filtered Rate | Notes |
|-------|-------|------|----|-----------| ---------------|---------------|-------|
| [avm1](../avm1/_investigation/CURRENT_STATUS.md) | 647 | 600 | 9 | 609 | 94.1% | **100.0%** (603/603) | 42 ignored. **Zero filtered failures.** loadvars_tostring + bitmap_filters PASS. Total bumped 643→647 by upstream sync (4 new tests; classification pending). |
| [from_gnash/actionscript.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 190 | 124 | 61 | 185 | **97.4%** | — | +3 effective post-2026-05-02 via ASSetNative implementation (Global-v7/v8 → PASS, Global-v6 → ruffle_matched). 2 raw failures remain (array-v5 sort/Array-method-on-Object semantics; TextFormat-v7 font metric precision). |
| [from_gnash/misc-mtasc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 9 | 7 | 2 | 9 | **100.0%** | — | All effective pass. |
| [from_gnash/misc-swfmill.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 18 | 17 | 1 | 18 | **100.0%** | — | All effective pass. `jump_to_prev_block` (cross-DoAction backward jump) and `tags_after_last_showframe` both landed; plan moved to `complete/MISC_SWFMILL_PLAN.md`. |
| [from_gnash/misc-ming.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 102 | 62 | 16 | 78 | **76.5%** | — | +1 effective this session (registerClassTest2 → ruffle_matched via MC builtin gating). |
| [from_gnash/misc-swfc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 16 | 7 | 5 | 12 | 75.0% | — | +3 effective since prior snapshot (mouse_drag_test PASS via startDrag→transformed_by_script; swf4opcode → ruffle_matched via SWF<5 MovieClip→f64 coercion; soft_reference_test1 → ruffle_matched via _name setter syncing parent.dynamic_props + var_map). |
| [from_shumway](../from_shumway/_investigation/CURRENT_STATUS.md) (flat) | 92 | 65 | 2 | 67 | 72.8% | — | +5 effective since 2026-04-30. |
| [from_shumway/avm1](../from_shumway/_investigation/CURRENT_STATUS.md) | 47 | 45 | 1 | 46 | **97.9%** | **100.0%** (45/45) | 2 ignored. Only `moviecliploader` remains (MCL one-tick deferral). |
| **SWFRecomp/tests** (old suite) | 158+59 | all trace pass | — | — | **100%** | — | Hand-written opcode tests. CI only. |

## Progress Since 2026-05-04

- **Shumway fuzz timeline tests `this._currentframe` (+5 effective).** `c8b8069c…`, `ac93c8c9…`, `07580c34…`, `2f4f46bf…`, `81004241…` (all `from_shumway/fuzz/`) → PASS. Root cause: `mc->currentframe` was never updated during natural sprite advance in `advance_sprite_frames`. The C runtime tracks two parallel frame counters: `obj->sprite_current_frame` (DisplayObject, 0-indexed, advances each tick) and `mc->currentframe` (MovieClip, 1-indexed, exposed to ActionScript via `_currentframe`). Only `obj->sprite_current_frame` was incremented per frame; `mc->currentframe` was set to 1 at MC creation and only updated by `ng_setSpriteFrame`/`ng_gotoFrameByMC` (goto paths) and by the recompiler-emitted root-frame updates. So `this._currentframe` from inside any sprite frame script returned 1 always (initial value) instead of the executing frame number. Fix in `SWFModernRuntime/src/libswf/tag.c` `advance_sprite_frames`: just before `CALL_FRAME(...)` at line ~941 (natural advance), look up the sprite's MC by `obj->instance_name` and set `smc->currentframe = (int)frame + 1`. Mirrors `swf_core.c`'s update of `root_movieclip.currentframe` before each root frame func. Manual nav (gotoAndPlay/gotoAndStop catch-up) intentionally not affected — those paths already set `mc->currentframe` to the target value before the catch-up loop. Bumps Shumway flat from 67/92 → 72/92 (+5 effective). Verified: 22-test AVM1 lifecycle (22/22), 17-test AVM1 lifecycle/scope (17/17), 6-test sprite state (6/6), 14-test misc-ming goto/loop/timeline (14/14), 14-test AVM1 timeline (14/14), 5-test gnash actionscript.all spot-check (5/5 effective). The 27 numeric-output fuzz tests in `from_shumway/fuzz/*` likely all use this pattern; expect more flips on next CI run.

- **`frame_label_test` (Gnash misc-ming.all) → PASS (+1, was 12/17 + 153 lines of timeline-loop noise).** `actionCall`'s
  `CALL_FRAME_FUNC` was invoking the called frame's recompiler-emitted `actionDrainOnloadAndScript` while the outer
  frame's drain was in progress, so the inner drain consumed the parent's pending queue entries — running
  `script_31`/`32`/`33` (`_root.x1==0` checks) **before** the called frame's `script_0` (`x1=0; ...`), and running
  `script_34` (`_root.totals(); stop()`) inside the call's `is_playing` save/restore window so the `stop()` was
  overwritten on call return. The assertions then read the pre-call values and `is_playing` stayed true, looping the
  timeline ~9× and emitting the assertion set on each cycle. Fix: snapshot `g_aq_count` at `CALL_FRAME_FUNC` entry,
  bracket the frame call with `actionDrainSuppressEnter`/`Leave`, then drain only entries with index ≥ snapshot via a
  new `actionDrainOnloadScriptAbove(floor)` helper — outer pending entries stay in the queue for the outer drain to
  process in FIFO order. Mirrors Ruffle's per-call action stack: each `call()` runs its own private action layer.
  Files: `SWFModernRuntime/include/actionmodern/action_queue.h`, `src/actionmodern/action_queue.c`,
  `src/actionmodern/action.c`. Bumps Gnash misc-ming.all from 78/102 → 79/102 effective. No regressions on a 25-test
  AVM1 call/scope/super battery or a 14-test misc-ming goto/loop/action-order battery (`ActionOrderTest3/4` already
  failing in CI baseline, unchanged).

- **`soft_reference_test1` (Gnash misc-swfc.all) → ruffle_matched (+1).** The `_name` setter (`actionSetMember` MOVIECLIP path in `action.c`) now syncs the rename to `parent.dynamic_props` (new key → MC, old key → undefined) and, when `mc->parent == &root_movieclip`, to `var_map` (with SWF<=6 lowercase folding via `setGlobalVariableByName`). Without this propagation, after `mc._name = "changed"` the stale `var_map["mc"]` and `parent.dynamic_props["mc"]` entries still resolved to the MC, breaking the test's "soft reference" semantics: `typeof(mc) == 'undefined'` returned false on the very first assertion (line 50), cascading into 20 follow-on failures. Mirrors Ruffle's `MovieClip::set_name`, which removes the old name binding on the parent's stage-object scope and installs the new one. The sync only fires when the existing binding is authoritative (entry references THIS MC under a key matching the MC's old name) to preserve case-collision entries from `case-v6` (`_root.clip` / `_root.CLIP`). Final residual diff is line 164 (`mcRef == _level0.mc1` after `removeMovieClip` + recreate at a different depth — Ruffle also fails this), so the test promotes via subset-match to ruffle_matched. Brings misc-swfc.all from 11/16 → 12/16 effective (68.8% → 75.0%).

- **ASSetNative implementation → Global-v6/v7/v8 (Gnash actionscript.all) effective pass + assetnative + assetnative_ids (AVM1) PASS.** `ASSetNative` was previously a noop (`builtin_noop_func`); now `builtin_assetnative` parses the comma-separated `props` argument (after `toString` coercion via `convertString`), strips an optional leading version-flag digit (`'1'`, `'6'`, `'7'`, `'8'`, `'9'`, or `"10"`), and for each non-empty name binds the result of `ASnative(major, minor + i)` on the target object (via `setProperty`). Position counter `i` increments per comma — matching gnash's `Global_as.cpp::global_assetnative` (which only handles `6/7/8/9`) plus the Flash-specific `1`/`10` prefixes exercised by `avm1/assetnative` and `avm1/assetnativeaccessor` under SWF 7. `minor` (4th arg, default 0) and `major` (2nd arg) are coerced via `convertFloat` so a `valueOf` exception unwinds through the bytecode-level try/catch. Empty names are skipped but still consume an index slot. Version-gating: when the prefix indicates SWF >= N and current player < N, the install behaviour depends on existing property state — own exists → overwrite with function; own absent + inherited present → install with the *inherited* value (which keeps `versions.X == proto.X` semantics in `for (i in o)` while still adding the name to `o`'s own properties); own absent + nothing inherited → install undefined. This three-way split is the exact rule observed in Flash for the `1a,2b,...,8h,...,10j` permutation in `avm1/assetnative` under SWF 7. Cross-cutting fix on the side: `convertString` for `ACTION_STACK_VALUE_ARRAY` now consults `objectCallToString` first (own-prop-only lookup on `arr->props`) before falling back to the existing `Array.prototype.join(",")` behaviour — required by Gnash's `ASSetNative(o, 200, a, 10)` with `a.toString = function() { return "o, j"; }`. Both `assetnative` (was 27-line diff) and `assetnative_ids` (was 6-line diff) AVM1 tests now PASS; the two `assetnativeaccessor*` tests still fail (need `ASSetNativeAccessor` impl + class 1109 ConvolutionFilter ASnative dispatch). Regression battery: 20-test AVM1 array/watch/execution-order suite (20/20 PASS), 22-test Gnash actionscript.all Global/Inheritance/Math/Number/Color/ASnative battery (22/22 effective pass).

## Progress Since 2026-05-02

- **mouse_drag_test (Gnash misc-swfc.all) → PASS.** `startDrag` on a MovieClip now sets `display_obj->transformed_by_script = 1` on the dragged clip directly, mirroring Ruffle where `update_drag` calls `set_x`/`set_y` per tick (which set the flag) even when the mouse hasn't moved. We don't run a `update_drag` analog in headless mode, so the flag must be set at startDrag time. Once set, subsequent timeline `PlaceObject` MOVE tags no-op on the dragged clip's matrix (per `apply_place_object`'s `if !transformed_by_script` guard in `tag.c`), and the flag persists past `stopDrag` — matching Flash semantics where a dragged clip stays "transform-locked." Applied to both the function-form `actionStartDrag` (resolves target name → MC) and the method-form `mc.startDrag()`. Fixes lines 5-8 of `mouse_drag_test.sc` (`check(mc1._x != 200/300)` and `check(mc1._y != 200/300)` after `.jump mc1 x=N y=N` during/after drag). Regression: 5/5 AVM1 drag tests + 18/18 transform/timeline tests + DragDropTest unchanged.

- **registerClassTest2 (Gnash misc-ming.all) → ruffle_matched** (commits 802674fd + 3c67568f). When `Object.registerClass` replaces an MC's `__proto__` chain to a class whose prototype does NOT extend MovieClip (e.g. `theClass2.prototype = {}` instead of `new MovieClip()`), MC-specific builtins like `getDepth()` should resolve to undefined — they're inherited from `MovieClip.prototype` which is no longer in the chain. Fix: at the top of the MOVIECLIP arm of `actionCallMethod`, walk `dynamic_props.__proto__` looking for any `MovieClip.prototype` variant (legacy/modern/default); if not found AND mc is not a TextField/Button, `goto _mc_user_dispatch` past the entire builtin chain. Object.prototype-inherited names (`addProperty`, `hasOwnProperty`, etc.) are explicitly preserved through the existing path. The TextField/Button exclusion is load-bearing — without it, 32 EditText + 3 TextFieldHTML + 1 DefineEditTextTest regress because TextField/Button MCs share the MOVIECLIP dispatch path but their `__proto__` chain ends at `Object.prototype`, not `MovieClip.prototype`. Reproduced in CI run 25259793074, fixed in 25260113699. Line 153 (`clip2.getDepth() == undefined`) now PASSES; residual 8-line diff (clipevs/clip3 onLoad ordering) is a subset of Ruffle's diff against Flash. See `from_gnash/_investigation/incomplete/REGISTERCLASS_LIFECYCLE_PLAN.md` "2026-05-02 session" section.
- **swf4opcode (Gnash misc-swfc.all) → ruffle_matched.** SWF4 `Equals` (action 0x0e) coerces both operands to f64 via `convertFloat`. Our `convertFloat` for `ACTION_STACK_VALUE_MOVIECLIP` returned NaN unconditionally; should return 0.0 in SWF<5 (matching Ruffle's `coerce_to_f64` for `Value::MovieClip`, which goes through `Value::Object(...) → primitive_as_number`, gating Object→0.0 on `swf_version < 5`). Group B (lines 363/365: bare `mc1` and `/:mc1` compared with undefined) now passes — both MC and undefined coerce to 0.0 → equal. Group A (lines 74/82/90/98: `/mc1:_PROPNAME` colon-path) still fails but is a subset of Ruffle's diff against Flash, so the test promotes to ruffle_matched (full PASS would require fixing SWF4 colon-var-vs-property semantics).

## Progress Since 2026-05-01

- **loadvars_tostring (AVM1) → PASS** (commit 48a97e0b). `builtin_loadvars_toString` iterated own_props and serialized `p->value` directly, ignoring addProperty-defined virtual properties; entries registered via `lv.addProperty(name, getter, setter)` serialized as `name=undefined`. Fix: when `p->getter` is non-NULL, call `invokePropertyGetter(lv)` and serialize the returned value. Throws inside the getter still longjmp through to the bytecode-level try/catch via `g_exception_state`, matching the test's `Caught: some error` path. Brings filtered AVM1 to 603/603 (100%).
- **bitmap_filters (AVM1) → PASS** (commit 900ae800). Timeline filter reconstruction reorders `BevelFilter` / `DropShadowFilter` / `GlowFilter` / `GradientGlow/GradientBevel` properties to match Flash's enumeration order. `verify_output.py` now honors `[approximations.number_patterns]` in test.toml — each regex's capture groups compared as floats with the configured `epsilon`, then matched substring stripped and the remainder compared exactly.
- **tags_after_last_showframe (Gnash misc-swfmill) → PASS** (commit 9020f664). Recompiler `swf.cpp` END_TAG handler: when the SWF has tags after the last `ShowFrame`, the recompiler opens a new dangling frame whose `ShowFrame` never lands (`another_frame == false` at END_TAG); previously this frame was treated as a normal frame and looped back to `frame_0`, re-executing the trailing DoActions on every iteration. Fix: emit `quit_swf = 1` in the dangling frame instead of `next_frame = 0; manual_next_frame = 1`. Mirrors Flash/Ruffle (trailing tags only on initial play).
- **Instance-v5/v6/v7/v8 (Gnash actionscript.all) → effective +4** (commit faf492a5). Three changes: (a) `new` on native non-constructor C functions (e.g. `new Math()`, `new Date.UTC()`) creates an empty object with `__proto__ = ctor.prototype` instead of crashing; (b) `Object.prototype` mutation protection — `Object.prototype.x = y` writes are silently dropped in SWF<=5 (matches Flash); (c) non-object prototype propagation: when `Foo.prototype` is set to a non-object value, `new Foo()` falls back to `Object.prototype`.
- **Global-v6 (Gnash actionscript.all) → effective +1** (commit 600dc2c1). `actionGetVariable` now folds the lookup name to lowercase before hitting the built-in registry in SWF<=6, so `Math.max` / `MATH.MAX` / `mAtH.mAx` all resolve to the same builtin (matches SWF<=6 case-insensitive variable resolution).
- **GetMember/SetMember own-prop walk (cross-cutting)** (commit fac77e42). `actionGetMember` and `actionSetMember` now walk past ASSetPropFlags-hidden own properties (where `isPropertyHiddenAtVersion(p->flash_flags)` returns true) instead of stopping at them — restores prototype-chain visibility when a hidden own-prop shadows a visible inherited property at the same name.
- **ecmaToInt32 / ASSetPropFlags array / convertFloat strict mode** (commit 7a1f04a0). `ecmaToInt32` now uses `trunc` semantics (rounds toward zero) instead of `floor`. `ASSetPropFlags` accepts an array of names. `convertFloat` strict mode for SWF6+ rejects strings with leading/trailing whitespace.

## Progress Since 2026-04-30

- **movieclip_destruction_test2 (Gnash misc-swfc) → PASS** (in CI at 25231855425). New `setGlobalVariableByName` helper bypasses the local-scope short-circuit in `setVariableByName` for the var_map sync inside `actionSetMember` on the root MC. Previously, `_root.foo = X` from inside any function dispatched through `actionCallMethod`'s MOVIECLIP user-method path created a stale local-scope shadow instead of updating `var_map`, so subsequent bare `foo` reads returned the pre-call value. Auto-fired unloads were unaffected because their dispatcher (`invokeSpecialFunction`) does not push a local scope for type-1 functions; manually-invoked `mc.onUnload()` did, exposing the bug.
- **case-v6 (Gnash actionscript.all) → PASS** (commits 6476ad2f, c42eb4d6, d2647520). Two SWF6-specific fixes: (a) slash-path `SetProperty`/`GetProperty` now route through `resolveSlashPathToMC` (with `swf_name_match` for `_root`/`_level0`) so `/_ROOT/MC0/` resolves case-insensitively in SWF<=6; (b) method-form `createEmptyMovieClip` skips rebinding `parent.dynamic_props[name]` and (root-only) `var_map[name]` when an existing entry references a LIVE MovieClip whose current `name` still matches the key (case-insensitive) — covers both `clip`/`CLIP` (case-collision) and `mc1`/`mc1` at different depths (same-name collision), while leaving renamed-MC stale entries available for rebinding (soft_reference_test1.sc:107-147 line 147 also flips PASSED).
- **ExternalInterface-v6 / ExternalInterface-v7 (Gnash actionscript.all) → PASS** (commit f62d59c4). All EI internal methods (`_argumentsToAS`, `_arrayToAS`, `_callIn`, `_escapeXML`, `_initJS`, `_jsQuoteString`, `_objectToAS`, `_toAS`, `_toJS`, `_toXML`, `_unescapeXML`, etc.) plus `addCallback` and `available` now marked with `flash_flags = 0x1000` — visible to `hasOwnProperty` but hidden from `getProperty` in SWF<=7 (SWF6 mask 0x7500 / SWF7 mask 0x7000 both include 0x1000; SWF8 mask 0x6000 does NOT). Only `EI.call` keeps `flash_flags=0` (visible in all versions, matching `Function.prototype.call` inheritance).
- **DepthLimitsTest (Gnash misc-ming) → PASS** (commit 61229899). `duplicateMovieClip` rejects out-of-range AS-depths (valid range [-16384, 2130690044]). Two checks: method-form rejects unbiased depth outside that range directly; function-form `actionCloneSprite` rejects `depth_int < -16384` (the recompiler bias-strip heuristic leaves small AS-depths unbiased while large positive depths arrive biased — biased depths are always ≥ 0 so the lower-bound check fires only on the unbiased path). Upper bound was already enforced by `ng_cloneSprite`'s biased-form guard.

## Progress Since 2026-04-18

- **ACTION_QUEUE_PLAN** — multi-phase architectural rework landing a Ruffle-style unified ActionQueue (Phases 0–8 all landed, plan marked complete at commit fe74d7aa). Motivated by `from_shumway/avm1/doactionorder` and timeline execution-order parity; enabled subsequent gnash and shumway fixes.
- **String wrapper dispatch + ruffle-match** (Gnash) — d05bbd56, f70ecdb0, 41f62c81. String-vN tests auto-promoted to `ruffle_matched` via stubbed call/apply, DontDelete, constructor, override, direct method dispatch, and enumerate fallback.
- **with-v6/v7/v8 → `ruffle_matched`** (Gnash) — 73983b0e + 7155a774 (latest CI delta). Two fixes: (a) `actionASSetPropFlags_func2` MOVIECLIP handling + WRITABLE check in WITH-scope assignment, (b) `resolveObjectPathToMC` walks dotted/colon paths via property lookup with `__proto__` fallback. Eliminated ~14 stray `Target not found`/`FAILED _target==` lines per test.
- **`depth_replacement_audio_unloading` PASS** (AVM1) — `verify_output.py` extracts all 14 raw-data arrays from a child SWF's `draws.c` and prefixes them; `actionFirePendingLoadInits` Phase 2 saves/restores `is_playing` so a child's `stop()` doesn't terminate the parent's frame loop.
- **`function_as_function` PASS** (AVM1) — `Function()` without `new` returns a bare object with no `__proto__`.
- **`bitmap_data_thorough/*` final cleanup** (AVM1) — suite now 16 PASS + 3 ruffle_matched + 1 accepted (pixelDissolve). All plan work complete.

## Progress Since 2026-03-19

### Shumway flat suite: Complete — 15/17 → 17/17 (100% AVM1)

Two fixes (commit 3b075cff):
1. **targetPath1** — MC `toString()` fallback to `MovieClip.prototype` → `Object.prototype` chain
2. **doubleAndRegister** — `registerClass` char_id-based lookup for multi-export sprites

Ignore list created for 30 AVM2/AS3 tests. Suite is complete.

### Gnash: Phase 1b complete, ignore list created

Phase 1b fixes (Math, ops, Error edge cases) applied. 9 tests with all-accepted diffs (Gnash bugs) added to ignore list. Line-level match improved from 65.0% → 69.1% (unfiltered) / 66.3% (filtered).

### Gnash: Phase 2 in progress (2026-03-23)

Phase 2 fixes applied (commit 15ce3f06):
- **Built-in prototype own toString/valueOf** — DONE. Number/String/Boolean prototypes now have own valueOf/toString distinct from Object.prototype. Line-level improvements across 15 tests: toString_valueOf +12 lines each, Number +2, String +1-3.
- **Function.prototype.apply/call** — DONE. Registered as own properties on Function.prototype.
- **Object.prototype.constructor** — DONE. Set constructor → Object on Object.prototype.

Note: Boolean-v5/v6/v7/v8, Video-v6/v7/v8, Selection-v5, Stage-v5 were already passing from Phase 1 fixes (CURRENT_STATUS.md was stale).

### Gnash: Phase 2 continued (2026-03-25)

- **Color valueOf + constructor target** — DONE. Color.setTransform/setRGB use `varToDoubleSWF` for valueOf on Number objects. Color constructor stores raw target argument as own property. Color-v5: 14→4 failures (-10), Color-v7/v8: 18→8 each (-10).
- **Stage/Selection non-constructable** — Stage-v5 already passes. Selection-v6/v7/v8 have deeper issues beyond non-constructable.

### AVM1: tab_ordering_properties_tab_index_edge_case (2026-03-25)

- **tabIndex string storage** — DONE. tabIndex setter now stores string values as-is (Flash behavior) instead of discarding non-numeric values. New PASS: tab_ordering_properties_tab_index_edge_case.

### AVM1 + Gnash fixes (2026-03-26)

- **Array.join HOLE→"undefined"** — DONE. Array.join/toString now correctly converts HOLE (unset) elements to "undefined" instead of empty string. Fixes 4 AVM1 tests: array_constructor, array_properties, external_interface_toxml_basic, global_array.
- **verify_output.py UTF-8 error handling** — DONE. Added `errors="replace"` to output.txt reads. Fixes string_relational_compare runtime_error → output_mismatch.
- **XMLSocket.connect returns false** — DONE. Fixes 4 Gnash tests: XMLSocket-v5/v6/v7/v8.

### Gnash: Color fixes (2026-03-27)

- **Color target toString() resolution** — DONE. Color methods now call toString() on object targets at each invocation. Fixes Color-v5.
- **Dynamic MC color transform** — DONE. Added cx_* fields to MovieClip struct for createEmptyMovieClip MCs. Fixes Color-v5/v7/v8.
- **_alpha / Color transform dual quantization** — DONE. _alpha getter uses roundf; cx_aa uses integer truncation (setTransform path). Fixes Color-v7/v8. Color-v6 improved to 97.6% (4 remaining: typeof(c)=='undefined').

### AVM1: Image test progress (2026-04-01)

- **Alpha blend fix** — Porter-Duff alpha blend factor corrected (SrcAlpha → One). Fixes `color` image test (30000 outlier channels → 0, max diff 48 → 1).
- **Stage.width/height init** — Was 0, now FRAME_WIDTH/FRAME_HEIGHT. Fixes Drawing API layout in `movieclip_setmask` (202K → 10K outliers).
- **Headless image test status**: 3 strict pass, 6 tolerance pass (was 12/31 strict + 10/31 tolerance before recompile; many tests had stale generated files).
- **RUNTIME_TRANSFORM_GPU and RUNTIME_CXFORM_GPU plans completed** (both already working, moved to complete/).
- **_global plain property resolution** — GetVariable now finds plain properties on _global in root context. Enables Gnash misc-mtasc AS2 class resolution.

## Per-Suite Docs

### avm1 (Ruffle)
- `avm1/_investigation/CURRENT_STATUS.md` — Current pass rates, plan status, remaining work
- `avm1/_investigation/SESSION_NOTES.md` — Historical session-by-session fix notes
- `avm1/_investigation/FAILING_TESTS_BY_FEATURE.md` — Failures by feature category
- `avm1/_investigation/REMAINING_FAILURES_ANALYSIS.md` — Detailed remaining failure analysis
- `avm1/_investigation/BLOCKER_SUMMARY.md` — Active and resolved blockers
- `avm1/_investigation/ACCEPTED_DIFFS.md` — Tests with permanently unfixable diffs
- `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` — Where we match Flash but not Ruffle

### from_gnash
- `from_gnash/_investigation/CURRENT_STATUS.md` — Pass rates, Phase 1/2/3 work order
- `from_gnash/_investigation/FAILING_TESTS_BY_FEATURE.md` — All 152 failures by root cause / feature
- `from_gnash/_investigation/REMAINING_FAILURES_ANALYSIS.md` — Tiered analysis with effort estimates
- `from_gnash/_investigation/BLOCKER_SUMMARY.md` — Active and resolved blockers

### from_shumway
- `from_shumway/_investigation/CURRENT_STATUS.md` — Flat suite complete (17/17 AVM1), avm1/ at 20/23 (87.0%)
- `from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md` — All actionable items done (9 tests fixed)

## Where to Focus

AVM1 filtered suite is at 100%; remaining actionable work is in the Gnash and Shumway suites.

1. **Gnash actionscript.all near-passing** — 22+ tests with <=18 line diffs. `global_proto_decls*` enumeration/ordering, `Number-v5..v8` float-to-string rounding, `Selection-v6/7/8`, `ExternalInterface-v8`. See `from_gnash/_investigation/incomplete/GNASH_NEAR_PASSING_PLAN.md`.
2. **Gnash `misc-mtasc/levels`** — only 1 failure in that sub-suite; needs multi-level SWF loading (`_level5`, `_level87`, `_level99`). See `LEVELS_PLAN.md`.
3. **Gnash `misc-swfmill`** — 1 remaining failure (`jump_to_prev_block`, cross-DoAction backward jump). `tags_after_last_showframe` was fixed this session. See `incomplete/MISC_SWFMILL_PLAN.md` for the consecutive-DoAction concatenation fix plan.
4. **Shumway `avm1/moviecliploader`** — sole remaining filtered failure. One-tick MCL deferral exposes latent getBounds / chained setInterval bugs. See `from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` Part B.
5. **Shumway `fuzz/*`** — 27 fuzzer-generated SWFs failing in the flat suite. Useful as an edge-case discovery source for runtime/recompiler.
6. **AVM1 image tests** — 14/31 strict pass, 10/31 tolerance. Remaining need Drawing API anti-aliasing, text layout, dynamic masks, or external media loading. Tracked in `IMAGE_COMPARISON_TESTS.md`.
7. **Gnash `misc-ming.all` / `misc-swfc.all`** — ~76 of ~83 failing tests are actionable via Phase 1 (near-passing) + Phase 2 (mid-rate cluster fixes); only ~7 zero-output tests are blocked on the inlined-Dejagnu DoInitAction architectural issue (Phase 3). See `incomplete/MISC_MING_SWFC_PLAN.md`.
