# Implicit Coercion (valueOf / toString Dispatch) Plan
<!-- TESTS: Matrix-v6, Rectangle-v8, toString_valueOf-v5, toString_valueOf-v6, toString_valueOf-v7, toString_valueOf-v8 -->

Last updated: 2026-04-17 (Phase 1 done — Rectangle/Matrix builtins dispatch valueOf)
Status: IN PROGRESS — Phase 1 complete, Phases 2-4 open

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

| Test | Match | Expected | Diffs |
|------|-------|----------|-------|
| Matrix-v6 | 137/168 (81.5%) | — | 29 |
| Rectangle-v8 | 140/166 (84.3%) | — | 24 |
| toString_valueOf-v5 | 90/137 (65.7%) | — | 44 |
| toString_valueOf-v6 | 141/155 (91.0%) | — | 11 |
| toString_valueOf-v7 | 140/155 (90.3%) | — | 13 |
| toString_valueOf-v8 | 140/155 (90.3%) | — | 13 |

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
