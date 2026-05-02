# Test Suite Overview

Cross-suite summary of all Ruffle-derived test suites. Each suite has its own `_investigation/` directory with detailed status docs.

Last updated: 2026-05-02 (`registerClassTest2` (Gnash misc-ming.all) promoted to ruffle_matched via MC builtin gating on MovieClip.prototype membership, with TextField/Button exclusions. CI snapshot below from run 25260113699.)

## Suite Summary

"Effective pass" = raw pass + `ruffle_matched` (diffs ⊆ Ruffle's diffs against Flash; auto-promoted when upstream has `known_failure=true` + `output.ruffle.txt`).

| Suite | Tests | Pass | RM | Effective | Effective Rate | Filtered Rate | Notes |
|-------|-------|------|----|-----------| ---------------|---------------|-------|
| [avm1](../avm1/_investigation/CURRENT_STATUS.md) | 643 | 600 | 9 | 609 | 94.7% | **100.0%** (603/603) | 42 ignored. **Zero filtered failures.** loadvars_tostring + bitmap_filters PASS this session. |
| [from_gnash/actionscript.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 190 | 122 | 63 | 185 | **97.4%** | — | +7 effective since 2026-04-30 (Instance-v5/v6/v7/v8, Global-v6, GetMember/SetMember hidden own-prop walk). 5 raw failures remain (ContextMenu-v7/v8, MovieClip-v5, TextFormat-v7, array-v5). |
| [from_gnash/misc-mtasc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 9 | 7 | 2 | 9 | **100.0%** | — | All effective pass. |
| [from_gnash/misc-swfmill.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 18 | 16 | 1 | 17 | **94.4%** | — | 1 remaining (`jump_to_prev_block` — cross-DoAction backward jump; concrete fix plan in `incomplete/MISC_SWFMILL_PLAN.md`). tags_after_last_showframe PASS this session. |
| [from_gnash/misc-ming.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 102 | 62 | 16 | 78 | **76.5%** | — | +1 effective this session (registerClassTest2 → ruffle_matched via MC builtin gating). |
| [from_gnash/misc-swfc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 16 | 6 | 3 | 9 | 56.2% | — | +1 effective (movieclip_destruction_test2 PASS). |
| [from_shumway](../from_shumway/_investigation/CURRENT_STATUS.md) (flat) | 92 | 65 | 2 | 67 | 72.8% | — | +5 effective since 2026-04-30. |
| [from_shumway/avm1](../from_shumway/_investigation/CURRENT_STATUS.md) | 47 | 45 | 1 | 46 | **97.9%** | **100.0%** (45/45) | 2 ignored. Only `moviecliploader` remains (MCL one-tick deferral). |
| **SWFRecomp/tests** (old suite) | 158+59 | all trace pass | — | — | **100%** | — | Hand-written opcode tests. CI only. |

## Progress Since 2026-05-02

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
