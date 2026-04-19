# Implicit Coercion (valueOf / toString Dispatch) Plan
<!-- TESTS: Matrix-v6, Rectangle-v8, toString_valueOf-v5, toString_valueOf-v6, toString_valueOf-v7, toString_valueOf-v8 -->

Last updated: 2026-04-19 (v5 research — 14 blockers grouped into Phases 6-9)
Status: IN PROGRESS — Phases 1, 2a, 2b, 3, 5 complete; Phases 6-9 queued for v5

---

## Overview

Several tests share a common root cause: places in the runtime that read
object properties and coerce them to number/string use the naïve
`varToDoubleSimple` / `convertString` helpers, which do **not** dispatch
user-defined `valueOf` / `toString`. These tests exercise custom
valueOf/toString on objects passed through builtin methods, abstract
equality, the `+` operator, and geometry class methods.

The 2026-04-17 fix (objectCallValueOf type 1 `this` setup) addressed one
sub-cluster of these failures but didn't cover the rest.

## Current Line Match

| Test | Match | Expected | Diffs | Status |
|------|-------|----------|-------|--------|
| Matrix-v6 | 160/168 (95.2%) | — | 8 | **ruffle_matched** |
| Rectangle-v8 | 160/166 (96.4%) | — | 6 | **ruffle_matched** |
| toString_valueOf-v5 | 95/137 (69.3%) | — | 39 | output_mismatch |
| toString_valueOf-v6 | 152/155 (98.1%) | — | 3 | **ruffle_matched** |
| toString_valueOf-v7 | 146/155 (94.2%) | — | 3 | **ruffle_matched** |
| toString_valueOf-v8 | 146/155 (94.2%) | — | 3 | **ruffle_matched** |

## Sub-clusters

### Cluster A — Geometry builtin arg coercion (Matrix, Rectangle)
Matrix/Rectangle builtin methods (equals, contains, containsPoint,
intersects, inflate, offset, union) read `x`, `y`, `width`, `height` and
method args via `varToDoubleSimple`. When the caller stores an OBJECT with
custom valueOf as a property, the builtin gets `NaN` instead of dispatching
valueOf.

**Fix:** switch those methods to `varToDoubleSWF(app_context, v, g_swf_version)`,
which already has the OBJECT → valueOf dispatch path. Similar fix was
applied to Point builtins in the 2026-04-14 session and resolved Point-v8.

**Tests improved:** Matrix-v6 (~15 lines), Rectangle-v8 (~20 lines).

### Cluster B — `+` operator with object operand → implicit toString
toString_valueOf-v6/v7/v8 has diffs like:
```
y == _level0.mc1  (expected "_level0.mc1", got "")
typeof(y) == 'movieclip'  (expected 'movieclip', got undefined)
```

These come from `y = "" + mc1` where `mc1` is a MovieClip. Flash's `+`
operator invokes toString on the MC (returns its target path), then
concatenates. Our abstract-add path either doesn't dispatch toString on
MovieClips or does so but into the wrong context.

**Fix:** audit `avAdditionEcma` / `actionAdd2` for MOVIECLIP + STRING path
and ensure it calls `objectCallToString` on the MC with the MC as `this`.
MovieClip.prototype.toString already returns the path string — confirm
the chain hits it.

**Tests improved:** toString_valueOf-v6/v7/v8 (~4 lines each).

### Cluster C — `==` operator on objects with same valueOf
toString_valueOf-v6/v7 lines:
```
x == "TO_STRING"  FAILED (expected PASSED)
y == "TO_VALUE"   FAILED (expected PASSED)
```

These are `String + Object` concatenations. Our impl coerces object via
valueOf but calls `simple_func` in a context where the user function can't
read `this`. The 2026-04-17 fix addressed this for objectCallValueOf's
primary FUNCTION branch but there's a secondary `convertString`-style path
that still has the bug.

**Fix:** find remaining uses of user-defined toString where
`simple_func` is called without pushing `this` onto `g_this_stack`. Apply
the same pattern as `objectCallToString` (check lines ~11331-11351).

**Tests improved:** toString_valueOf-v5/v6/v7/v8 (~3-5 lines each).

### Cluster D — MovieClip valueOf returns non-primitive, equality against MC
toString_valueOf-v6 lines 77, 78 expect `y == _level0.mc1` (MC equality).
Flash's abstract equality for MOVIECLIP on both sides is reference
equality; when one side is string and other is MC, coerces MC via
toString. Our impl may be short-circuiting to false.

**Fix:** audit `actionEquals2` for (MOVIECLIP, STRING) and
(STRING, MOVIECLIP) cases. Expected behavior: coerce MC→string via
toString, then string comparison.

**Tests improved:** toString_valueOf-v6 (~2 lines).

## Phases

### Phase 1 — Geometry builtin arg coercion — DONE (2026-04-17)
- Added `propToDoubleSWF(app_context, obj, name, name_len)` helper which
  dispatches custom valueOf on OBJECT/ARRAY via `varToDoubleSWF`.
- Rewrote `rectEquals`, `rectContains`, `rectContainsPoint`,
  `rectContainsRectangle`, `rectIsEmpty`, `rectIntersects`,
  `rectIntersection`, `rectUnion`, `rectInflate`, `rectInflatePoint`,
  `rectOffset`, `rectOffsetPoint` and Matrix builtins (`matrixScale`,
  `matrixRotate`, `matrixTranslate`, `matrixConcat`, `matrixInvert`,
  `matrixCreateBox`, `matrixCreateGradientBox`, `matrixTransformPoint`,
  `matrixDeltaTransformPoint`) to use `propToDoubleSWF` / `varToDoubleSWF`.
- **Impact (local diff-line deltas):**
  - Rectangle-v8: 24 → 20 diffs (-4)
  - HitTest-v6/v7: 18 → 16 diffs each (-2)
  - HitTest-v8: 17 → 15 diffs (-2)
  - Matrix-v6 unchanged (remaining diffs are Flash native-state semantics,
    unrelated to arg coercion)
- No regressions on avm1 (`string_coercion`, `mutable_this`, `this_scoping`,
  `register_class_return_value`, `enumerate`, `add`, `unload`,
  `array_enumerate`, `text_format`, `textsnapshot_available_text`,
  `as2_super_and_this_v6`, `swf5_no_closure`, `goto_frame`, `set_interval`)
  or gnash (`Point-v5..v8`, `Color-v5..v8`, `ColorTransform-v5..v8`,
  `Error-v5..v8`, `Transform-v6/v7`, `Matrix-v5/v7/v8`).

### Phase 2 — `+` operator MOVIECLIP + STRING path
- Audit `actionAdd2` and `avAdditionEcma` for MOVIECLIP-operand handling.
- Ensure `objectCallToString` is invoked with proper context.
- Expected impact: toString_valueOf-v6/v7/v8 +3-5 lines each.

### Phase 2b — String/Boolean wrapper own-property shadowing — DONE (2026-04-18)
- `new String(x)` and `new Boolean(x)` were installing their own
  `valueOf` / `toString` as DontEnum own properties on the wrapper
  instance, which shadowed user overrides to `String.prototype.valueOf` /
  `.toString`. Removed the own-prop installs; wrappers now inherit
  valueOf/toString from their prototype (matches Number constructor).
- To preserve ToString short-circuit for String wrappers (Ruffle's
  `value.rs` Value::coerce_to_string bypasses user toString when
  `NativeObject::String`), added a `native_type == NATIVE_STRING` shortcut
  to both `convertString` (OBJECT case) and `varToStringBuf` (OBJECT case):
  when present, returns the stored `valueOf_value` primitive directly
  without invoking toString. Keeps `parseInt(str_wrapper)` / string
  concat with a String wrapper working after user overrides.
- **Impact:**
  - toString_valueOf-v6: 8 → 3 diffs → **ruffle_matched** (+1 test)
  - toString_valueOf-v7: 8 → 5 diffs
  - toString_valueOf-v8: 8 → 5 diffs
  - Remaining diffs on v7/v8: lines 57/58/59 (svo standalone on MC/func/bool
    receiver — Ruffle also fails 57/58, we differ on 59) and lines 147/148
    (user valueOf/toString on plain Object during `"" + o`: counters stay
    0 in v7/v8 but pass in v6 — SWF version-specific path not yet
    identified).
- No regressions on avm1 `add`, `array_enumerate`,
  `coerce_to_object_monkeypatch`, `enumerate`, `mutable_this`,
  `register_class_return_value`, `string_coercion`, `text_format`,
  `textsnapshot_available_text`, `this_scoping`, `unload`; nor on gnash
  `Boolean-v5..v8`, `Number-v6..v8`, `Matrix-v5/v7/v8`, `Point-v5..v8`,
  `Rectangle-v5..v7`, `ColorTransform-v8`.

### Phase 3 — `this` stack push for type 2 valueOf/toString dispatch — DONE (2026-04-18)
- `objectCallValueOf` and `objectCallToString` pushed `g_this_stack`
  only for type 1 (simple_func) user-defined functions. Type 2
  (advanced_func) dispatch relied solely on `preload_this` register
  loading, which silently failed for SWF7+ DefineFunction2 bodies that
  resolved `this` via `GetVariable("this")` rather than the preloaded
  register.
- Fix: push `{type=OBJECT, data=obj}` onto `g_this_stack` (with
  save/restore of `g_this_depth`) around the advanced_func invocation
  in both helpers. Safe — a preload_this body reads its register and
  ignores the `this` global; a GetVariable("this") body now finds
  `obj` at the top of the stack.
- **Impact:**
  - toString_valueOf-v7: 5 → 3 diffs → **ruffle_matched** (+1 test)
  - toString_valueOf-v8: 5 → 3 diffs → **ruffle_matched** (+1 test)
  - Lines fixed: `o.valueOfCalls == 1` and `o.toStringCalls == 1` —
    counters on a plain `new Object()` receiver are now incremented by
    the user's `v`/`s` functions during `a = "" + o`.
- No regressions on avm1 `as2_super_and_this_v6/v8`,
  `coerce_to_object_monkeypatch`, `enumerate`, `extends_chain`,
  `init_object_order`, `mutable_this`, `object_resolve`,
  `register_and_init_order`, `register_class_return_value`,
  `string_coercion`, `super_edge_cases`, `text_format`, `this_scoping`,
  `array_enumerate`; or on gnash `Color-v5..v8`, `ColorTransform-v8`,
  `Error-v5..v8`, `Matrix-v5/v7/v8`, `Point-v5..v8`, `Rectangle-v5..v7`.

### Phase 4 — MOVIECLIP equality coercion
- `actionEquals2` (MOVIECLIP, STRING) case: coerce MC via toString, then
  compare as strings.
- Expected impact: toString_valueOf-v6 +2 lines.

### Phase 5 — Geom toString undefined rendering — DONE (2026-04-18)
- `pointToString`, `rectToStringDynamic`, and `matrixToStringDynamic`
  rendered missing / UNDEFINED fields using `varToStringBufFull`,
  which unconditionally emits "undefined" for UNDEFINED. Flash's
  string-concat / toString emits "" under SWF<7 and "undefined" under
  SWF>=7 (matching `convertString`).
- Fix: short-circuit missing (NULL) / UNDEFINED fields with a
  version-gated format — `""` for SWF<7, `"undefined"` for SWF>=7 —
  before falling through to `varToStringBufFull`. Also matches ECMA
  "missing property reads as undefined" semantics (e.g. after
  `delete r0.x`).
- **Impact:**
  - Matrix-v6: 31 → 8 diffs → **ruffle_matched** (+1 test)
  - Rectangle-v8: 20 → 6 diffs → **ruffle_matched** (+1 test)
- No regressions on avm1 `matrix`, `point`, `rectangle`; or on gnash
  `Matrix-v5/v7/v8`, `Point-v5..v8`, `Rectangle-v5..v7`,
  `ColorTransform-v5..v8`, `Transform-v6/v7`, `HitTest-v6..v8`,
  `toString_valueOf-v6..v8`.

### Phase 2a — MC CallMethod dispatch order — DONE (2026-04-17)
- `actionCallMethod` for MOVIECLIP receiver previously fell back to
  `lookupFunctionByName(method_name)` **before** walking
  `MovieClip.prototype → Object.prototype`. Because `lookupFunctionByName`
  searches in reverse registration order, "valueOf" resolved to
  `g_wrapper_valueOf_func` (the primitive wrapper helper) instead of
  `g_object_valueOf_func` (the MC's inherited `Object.prototype.valueOf`).
  That made `mc.valueOf()` and `mc.toString()` return UNDEFINED/empty.
- Fix: reorder — check `MovieClip.prototype` chain **before**
  `lookupFunctionByName`, so MC method calls hit the inherited
  Object.prototype.{valueOf, toString} first.
- Also updated `builtin_object_valueOf` to return the receiver with the
  correct type tag: MOVIECLIP (from `g_event_this_mc`) when the caller
  passed `this_obj=NULL`, or the matching type from `g_this_stack` for
  OBJECT/ARRAY/FUNCTION receivers. Previously it always returned OBJECT.
- **Impact:**
  - toString_valueOf-v6: 14 → 8 diffs (-6)
  - toString_valueOf-v7: 15 → 10 diffs (-5)
  - toString_valueOf-v8: 15 → 10 diffs (-5)
- No regressions on avm1 (MC-heavy tests: `duplicate_movie_clip`,
  `clone_sprite_edittext`, `clone_sprite_types`,
  `empty_movieclip_can_attach_movies`, `on_construct`, `this_scoping`,
  `swf5_to_6_cross_call`, `swf5_no_closure`, `object_resolve`,
  `init_object_order`, `register_and_init_order`, `extends_chain`,
  `as2_super_and_this_v8`, `super_edge_cases`, `global_is_bare`,
  `loadvariables`) or on gnash (`Point-v5..v8`, `Color-v5..v8`,
  `ColorTransform-v8`, `Error-v5..v8`, `Matrix-v5/v7/v8`,
  `Transform-v6/v7`, `System-v5..v8`).
- Remaining toString_valueOf diffs correspond to String-wrapper-vs-MC
  confusion (lines 188/192/196 — also failed in Ruffle), and custom
  toString/valueOf on plain objects via `+` (lines 206, 215/216, 262/263)
  which fall into Phase 2b / Phase 3 territory below.

## Remaining work — toString_valueOf-v5 (2026-04-19 research)

v6/v7/v8 plus Matrix-v6 and Rectangle-v8 are all now `ruffle_matched`.
Only `toString_valueOf-v5` remains at output_mismatch (95/137 = 69.3%).

### Diff breakdown

Our 41 failing output indices vs Ruffle's 34. Of those:

- **27 are both-fail** (our diff ⊆ Ruffle's on these lines) — rooted in
  Flash's SWF5 "any function is equal to undefined in equality context"
  rule. Tests like `Object.prototype.toString == undefined`,
  `obj.toString == obj.valueOf`, `Array.prototype.toString == undefined`.
  Ruffle's `abstract_eq` (core/src/avm1/value.rs:505) does call
  `to_primitive_num` on both sides under SWFv5, but that ends up
  returning the function itself (non-primitive), so the Object-Object
  branch compares by pointer and these fail in Ruffle too. No fix
  needed on our side — these are identically failing on Ruffle.

- **14 are our-fail-ruffle-passes** — where our implementation diverges
  from Ruffle's behavior. These are the blockers for ruffle_matched.

### Category breakdown of the 14 blockers

| # | Lines | Source | Root cause |
|---|-------|--------|------------|
| 1 | 9 | 243,244,245,246,265,266,278,279,280 | `_root.createEmptyMovieClip("mc1", 1)` succeeds in our impl under SWF5 — it's a SWF6+ method. Ruffle gates it off, returning undefined for `mc1`/`mc2` and `createEmptyMovieClip` itself. |
| 2 | 2 | 297,298 | `TextField.prototype` exists in our impl under SWF5 — should be undefined (introduced SWF6+). With `TextField.prototype == undefined`, `TextField.prototype.toString` reads as undefined, so `undefined == Object.prototype.toString` trips the SWF5 function-equality rule (same fail as other-categorized-Ruffle-also-fails lines). Today we instead compare two distinct function refs. |
| 3 | 2 | 328,331 | `y = text1.valueOf()` / `text1 != "A STRING"`. TextField wrapper's coercion through valueOf/toString. Our impl returns empty for `y`, failing MC-like string path. Likely related to TextField prototype gating above. |
| 4 | 1 | 469 | `a3 = 1/a1` where `a1 = new Array(...)`. Expected `isNaN(a3)` (because Array.valueOf returns non-primitive, falls through to toString "1,2,3,4", which is NaN as number). Our `convertFloat` path for ARRAY in SWF5 returns 0, giving `a3 = Infinity` (not NaN). |

## Phases

### Phase 6 — SWF5 `createEmptyMovieClip` version gate
- `MovieClip.prototype.createEmptyMovieClip` was introduced in SWF6
  (per Flash docs and Ruffle source).
- Currently accessible in SWF5 via our MC prototype method stub table.
- Fix: gate the method with `flash_flags=0x0080` (hidden in SWF5) like
  the pattern in `CURRENT_STATUS.md` "SWF5 version hiding via
  flash_flags" for Key/AsBroadcaster/LocalConnection. Also ensure
  failed `createEmptyMovieClip` returns undefined so `mc1 = _root.x(..)`
  leaves `mc1` undefined.
- **Expected impact:** toString_valueOf-v5 -9 diffs (243,244,245,246,
  265,266,278,279,280). Dependent tests: any v5 test that touches
  `createEmptyMovieClip` should verify no regression (grep for hits in
  the actionscript.all v5 tests).

### Phase 7 — SWF5 `TextField.prototype` hidden
- `TextField.prototype` was introduced in SWF6 (gnash test comment:
  "TextField in swf5 does not have a prototype by default").
- Currently we always expose it.
- Fix: gate `prototype` access on TextField with `flash_flags=0x0080`
  under SWF5. `TextField.prototype` → undefined. Then SWF5 code
  `TextField.prototype.toString` reads as undefined, and
  `undefined == Object.prototype.toString` will fail the same way
  Ruffle's does (lines become both-fail, subset-match).
- **Expected impact:** toString_valueOf-v5 -2 diffs (297, 298).
  Need to check: tests that explicitly access TextField.prototype
  in SWF5 (grep output.txt for patterns).

### Phase 8 — SWF5 TextField coerce-to-primitive
- Lines 328, 331: TextField wrapper equality with a string, and
  passing a TextField through valueOf. Our output for line 328 is
  empty (TextField path in `convertString`/`valueOf` returns empty in
  SWF5). Ruffle returns the textfield itself (as a reference, compared
  pointer-wise in the Object-Object branch).
- Fix: audit `objectCallValueOf` and convertString OBJECT case for
  TextField native_type — should return `this` (the wrapper) in SWF5,
  not empty. Similar to MovieClip coerce behavior.
- **Expected impact:** toString_valueOf-v5 -2 diffs (328, 331).
  May be gated by Phase 7 since the test probably depends on
  TextField.prototype being absent.

### Phase 9 — Array ToNumber in SWF5
- `1/a1` where a1 is an Array should produce NaN in SWF5 (Array.valueOf
  returns non-primitive, toString returns "1,2,3,4", Number("1,2,3,4")
  = NaN). Our impl returns 0 for array-to-number, giving Infinity.
- Fix: locate the SWF5 branch in `convertFloat` / `varToDoubleSWF` that
  handles ARRAY and make it follow the valueOf → toString → Number
  chain instead of defaulting to 0.
- **Expected impact:** toString_valueOf-v5 -1 diff (469). Other v5
  arithmetic-on-array tests may benefit.

### Dependencies

Phases 6 and 7 are independent. Phases 8 and 9 may be unblocked (or
partially resolved) after Phase 7 lands — the expected output for
lines 328/331/469 depends on earlier TextField/Array prototype access
paths.

## Success Criteria

- Rectangle-v8 and Matrix-v6 cross 95% line match (target: 158/166 and
  160/168). **DONE — both ruffle_matched.**
- toString_valueOf-v5/v6/v7/v8 cross 95% line match (target: 130+ / 147+ /
  147+ / 147+). **DONE for v6/v7/v8 (ruffle_matched); v5 → pending
  Phases 6-9, target is ruffle_matched (our diffs ⊆ Ruffle's 34).**
- No regression on avm1 `string_coercion`, `mutable_this`, `this_scoping`,
  nor on Point-v5..v8, Color-v5..v8, ColorTransform-v5..v8, Error-v5..v8.

## Risk / Effort Estimate

- Low risk — each phase is a small targeted change with existing helpers.
- Phase 1: ~1 day.
- Phase 2-4: ~1 day each.
- Total: ~3-5 days.

## Related

- `GNASH_FEATURE_PLAN.md` sections 15 (toString/valueOf) and 18 (Matrix,
  Rectangle) — this plan supersedes those rows
- `MEMORY.md` "Point method string-+ semantics" (2026-04-14) — analogous
  Point fix; Cluster A follows same pattern
- 2026-04-17 objectCallValueOf fix (committed f7ed2ce3) — Phase 3 builds
  on that work
