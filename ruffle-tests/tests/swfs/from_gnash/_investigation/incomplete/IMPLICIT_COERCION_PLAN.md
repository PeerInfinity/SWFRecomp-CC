# Implicit Coercion (valueOf / toString Dispatch) Plan
<!-- TESTS: Matrix-v6, Rectangle-v8, toString_valueOf-v5, toString_valueOf-v6, toString_valueOf-v7, toString_valueOf-v8 -->

Last updated: 2026-04-18 (Phase 2b done — String wrapper shadow + convertString shortcut)
Status: IN PROGRESS — Phases 1, 2a, 2b complete; v6 → ruffle_matched; v7/v8 close

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
| Matrix-v6 | 137/168 (81.5%) | — | 31 | output_mismatch |
| Rectangle-v8 | 144/166 (86.7%) | — | 20 | output_mismatch |
| toString_valueOf-v5 | 95/137 (69.3%) | — | 39 | output_mismatch |
| toString_valueOf-v6 | 152/155 (98.1%) | — | 3 | **ruffle_matched** |
| toString_valueOf-v7 | 144/155 (92.9%) | — | 5 | output_mismatch |
| toString_valueOf-v8 | 144/155 (92.9%) | — | 5 | output_mismatch |

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

### Phase 3 — Remaining `simple_func` this-context sites
- Grep for `simple_func)(app_context)` in `action.c`; audit each site for
  `this_obj` argument / g_this_stack setup.
- Build a shared helper that wraps the invocation pattern so future sites
  don't regress.
- Expected impact: toString_valueOf-v5 +5-8 lines.

### Phase 4 — MOVIECLIP equality coercion
- `actionEquals2` (MOVIECLIP, STRING) case: coerce MC via toString, then
  compare as strings.
- Expected impact: toString_valueOf-v6 +2 lines.

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

## Success Criteria

- Rectangle-v8 and Matrix-v6 cross 95% line match (target: 158/166 and
  160/168).
- toString_valueOf-v5/v6/v7/v8 cross 95% line match (target: 130+ / 147+ /
  147+ / 147+).
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
