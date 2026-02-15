# Geometry Classes Implementation: Point, Rectangle, Matrix

Last updated: 2026-02-15

## Status: COMPLETE

All three `flash.geom` classes fully implemented and passing at 100%.

**Results** (commit `cd84b0f`):
- **Point**: 175/175 (was 124/175)
- **Matrix**: 171/171 (was 123/171)
- **Rectangle**: 745/745 (was 516/745)
- **Total**: +3 newly passing tests, -407 mismatched lines

**Bonus improvements** from Function.prototype.apply support:
- `arguments`: +29 lines (77→106/127)
- `bitmap_data_pixeldissolve`: +28 lines (68→96/1075)
- `bitmap_data_hittest`: +21 lines (39→60/132)
- `global_instance_decls`: +1 line

No regressions.

---

## Implementation Summary

All code in `SWFModernRuntime/src/actionmodern/action.c` (~1480 lines added).

### Infrastructure

- **Static prototypes**: `g_point_prototype`, `g_matrix_prototype`, `g_rect_prototype`
- **Static function arrays**: `g_point_methods[7]`, `g_point_statics[3]`, `g_matrix_methods[12]`, `g_rect_methods[15]`
- **`initGeomPrototypes()`**: creates all three prototypes and registers all methods (called once from flash.geom init block)
- **`registerGeomMethod()`**: DRY helper to init ASFunction + register in function_registry + set on prototype
- **`varToStringBufFull()`**: like `varToStringBuf` but calls `objectCallToString` for objects and normalizes `-0` → `0`
- **`propToDouble()`**: reads a property as double, returning NAN if the property is missing (unlike `varToDoubleSimple(NULL)` which returns 0.0)
- **`createPointObj()`/`createPointObjF64()`**: allocate Point object with `__proto__` set
- **`createRectObj()`**: allocate Rectangle object with `__proto__` set
- **`makeF64()`**: create an F64 ActionVar

### Point Class

**Constructor**: 0 args → (0,0); 1 arg → (x, undefined); 2+ args → (x, y). No coercion.

**Instance methods** (on `g_point_prototype`):
- `toString()` → `(x=VALUE, y=VALUE)`
- `add(pt)` / `subtract(pt)` — duck-typed, non-object arg → NaN
- `equals(pt)` — numeric equality of x and y
- `clone()` — new Point with same values
- `offset(dx, dy)` — mutates in-place
- `normalize(thickness)` — scale to target length; zero-length → no change; undefined/null axes → no change

**`length` getter**: intercepted in `actionGetMember` for Point instances → `sqrt(x*x + y*y)`

**Static methods** (on `fc_Point.own_props`):
- `distance(pt1, pt2)` — requires both args to be Point instances (proto check), else undefined
- `interpolate(pt1, pt2, f)` — `pt2 + f*(pt1-pt2)`
- `polar(len, angle)` — `(len*cos(angle), len*sin(angle))`

### Matrix Class

**Constructor**: 0 args → identity (1,0,0,1,0,0); 1-6 args fill a,b,c,d,tx,ty (missing → undefined); 7+ args → ignore extras.

**Instance methods** (on `g_matrix_prototype`):
- `toString()` → `(a=V, b=V, c=V, d=V, tx=V, ty=V)`
- `clone()`, `identity()`
- `scale(sx, sy)` — `a*=sx, c*=sx, tx*=sx, b*=sy, d*=sy, ty*=sy`
- `rotate(angle)` — 2D rotation on a,b,c,d (tx,ty unchanged)
- `translate(dx, dy)` — `tx+=dx, ty+=dy`
- `concat(m)` — right-multiply: `this = this * m`
- `invert()` — 2x2 adjugate/determinant
- `createBox(sx, sy, rot, tx, ty)` — rot NOT optional (undefined → NaN)
- `createGradientBox(w, h, rot, tx, ty)` — scale by w/1638.4, rot defaults to 0 (not undefined)
- `transformPoint(pt)` — `(a*px+c*py+tx, b*px+d*py+ty)`
- `deltaTransformPoint(pt)` — same without translation

### Rectangle Class

**Constructor**: 0 args → (0,0,0,0); 1-4 args fill x,y,width,height (missing → undefined).

**toString**: `(x=V, y=V, w=W, h=H)`

**Computed property getters** (intercepted in `actionGetMember`):
- `left`=x, `top`=y, `right`=x+width, `bottom`=y+height
- `topLeft` → new Point(x, y)
- `bottomRight` → new Point(x+width, y+height)
- `size` → new Point(width, height)

**Computed property setters** (intercepted in `actionSetMember`):
- `left=v` → width = old_right - v; x = v
- `top=v` → height = old_bottom - v; y = v
- `right=v` → width = v - x
- `bottom=v` → height = v - y
- `topLeft=pt` → applies left+top setter logic (reads pt.x/pt.y; undefined value → NaN propagation)
- `bottomRight=pt` → applies right+bottom setter logic
- `size=pt` → width=pt.x, height=pt.y

**Instance methods** (on `g_rect_prototype`):
- `clone()`, `equals(r)`, `isEmpty()`, `setEmpty()`
- `contains(x, y)` / `containsPoint(pt)` / `containsRectangle(r)` — NaN in args → undefined
- `inflate(dx, dy)` / `inflatePoint(pt)` — mutates in-place
- `intersection(r)` / `intersects(r)` — returns new rect / boolean
- `offset(dx, dy)` / `offsetPoint(pt)` — mutates in-place
- `union(r)` — returns new rect covering both

### Function.prototype.apply

Added alongside existing `Function.call` support in `actionCallMethod`:
- Extracts `thisArg` (args[0]) and `argsArray` (args[1])
- Gets array elements via `getArrayElement()`
- Invokes function with proper `this` binding (both function_type 1 and 2)

This was required because the Rectangle test dispatches all method calls via `rect.methodName.apply(rect, argsArray)`.

---

## Key Bugs Fixed During Implementation

1. **`-0` in toString**: `sin(0) = 0`, but `-sx * sin(0) = -0`, which prints as `"-0"`. Flash prints `"0"`. Fixed by checking `signbit()` for zero values in `varToStringBufFull`.

2. **Missing property → 0.0 vs NaN**: `varToDoubleSimple(NULL)` returns `0.0`, but Flash treats missing properties as `undefined` → `NaN`. Created `propToDouble()` helper that returns `NAN` for NULL. Used in all geometry methods that read properties from argument objects.

3. **topLeft/bottomRight setters with non-object values**: Setting `rect.topLeft = undefined` should propagate NaN to width/height. Fixed by using `ptx ? varToDoubleSimple(ptx) : NAN` instead of `varToDoubleSimple(ptx)`.
