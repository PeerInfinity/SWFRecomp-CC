# Replicated Flash Bugs

Known Flash Player bugs that we deliberately replicate. These are documented quirks
in Flash's behavior — not spec-compliant, not arbitrary choices, and not Ruffle-specific
differences. Both Flash and Ruffle exhibit the same buggy behavior, and the Ruffle test
expected output reflects it.

This is distinct from:
- `ACCEPTED_DIFFS.md` — tests that can never match (UB, platform-specific, etc.)
- `RUFFLE_VS_FLASH_DIFFERENCES.md` — cases where we match Flash but Ruffle disagrees
- `RUFFLE_COMPAT_TWEAKS.md` — arbitrary choices where correct behavior is unclear

**Scope note (2026-07-24):** this file lives under `avm1/_investigation/` for
historical reasons, but the category is corpus-wide. Entries are tagged
**[AVM1]** or **[AVM2]**; AVM2/avmplus entries are indexed from
`from_avmplus/_investigation/CURRENT_STATUS.md`.

---

## [AVM2] `Function.length` on builtins deviates from ECMA-262

**Affected tests**: `from_avmplus/ecma3/String/concat`,
`ecma3/String/e15_5_4_6_2_rt`, and every Tamarin test whose opening
assertion is `X.prototype.<method>.length` (~35 tests across `ecma3/String`,
`Array`, `Number`, `Boolean`, `FunctionObjects`, `ObjectObjects`).

**The bug**: ECMA-262 3rd ed. specifies the `length` of several built-in
methods, and avmplus/Flash reports **different values** — because Flash
implements them with rest parameters or extra optional parameters, and
reports the resulting declared arity rather than the spec constant.

| Method | ECMA-262 says | Flash / Ruffle / us |
|---|---|---|
| `String.prototype.concat` | 1 (§15.5.4.6) | **0** (rest param) |
| `String.prototype.indexOf` | 1 (§15.5.4.7) | **2** |
| `String.prototype.lastIndexOf` | 1 (§15.5.4.8) | **2** |
| `Array.prototype.concat` | 1 (§15.4.4.4) | **0** (rest param) |

**Evidence**: the Flash-generated expected output asserts the Flash values,
not the spec ones. From `ecma3/String/concat/Test.as`:

```as3
Assert.expectEq( "String.prototype.concat.length", 0, String.prototype.concat.length );
```

and `ecma3/String/concat/output.txt` line 1 is
`String.prototype.concat.length PASSED!`. Ruffle matches, declaring
`prototype.concat = function(...args):String` in
`core/src/avm2/globals/String.as` (a rest param, so arity 0) and
`indexOf = function(str:String = "undefined", index:Number = 0)` (arity 2).

**What we did** (`d90353066`): carry a declared arity on native builtin
function objects — a `param_count` field on `Avm2MethodRef`, surfaced by
`fn_get_length` — and register each prototype function with the **Flash**
arity via `avm2_proto_add_function_n`.

**Do not "fix" these to the spec values.** The rule for this codebase is:

> Take builtin arities from the corpus's own assertions, never from
> ECMA-262. One command gives the ground truth:
> ```bash
> grep -rhoP '"\w+\.prototype\.\w+\.length",\s*\d+' \
>     ruffle-tests/tests/swfs/from_avmplus/ | sort -u
> ```

Global functions happen to agree with the spec (`parseInt` 2, `parseFloat`
1, `escape`/`unescape`/`isNaN`/`isFinite` 1), so the deviation is confined
to the `String`/`Array` prototype methods above — but check, don't assume.

**Files**: `SWFModernRuntime/src/avm2/avm2_string.c`, `avm2_array.c`,
`avm2_number.c`, `avm2_regexp.c`, `avm2_function.c`, `avm2_globals.c`;
`SWFModernRuntime/include/avm2/avm2_object.h` (`Avm2MethodRef.param_count`).

---

## [AVM2] `Vector3D.nearEquals(v, tol, true)` ASSIGNS `this.w = toCompare.w`

**Affected test**: `avm2/vector3d_near_equals`

**The bug**: Flash's `Vector3D.nearEquals` fourth arm is

```as3
&& (!allFour || Math.abs(this.w = toCompare.w) < tolerance); // FP BUG
```

An **assignment** was written where a subtraction belongs. Two consequences,
both observable:

1. The `w` comparison is `|toCompare.w| < tolerance` — `this.w` is never part
   of the comparison at all, so `nearEquals` can report `true` for two
   vectors whose `w` differ by any amount as long as the *argument's* `w` is
   small.
2. It is a **side effect on the receiver**: whenever `allFour` is true and the
   x/y/z arms all passed, `this.w` is silently overwritten with
   `toCompare.w`. The `&& (!allFour || ...)` short-circuit means the write
   does NOT happen when `allFour` is false, or when any of x/y/z already
   failed.

**Evidence**: `avm2/vector3d_near_equals` prints both vectors after every
`nearEquals` call, and 13 of its `v1 = ...` lines carry a `w` that came from
`v2`:

```
  19   v1 = 1,1,1,2       # after v1.nearEquals(v2, 2, true), v2.w == 2
  49   v1 = 2,2,2,3       # after v1.nearEquals(v3, 2, true), v3.w == 3
  79   v1 = -1,-1,-1,-2
```

Ruffle's `core/src/avm2/globals/flash/geom/Vector3D.as:96` carries the same
line with the same `// FP BUG` comment, so the expected output is Flash's.

**What we did**: `v3_near_equals` already replicated half the bug (comparing
`|toCompare.w|` instead of a difference) but not the assignment, which is why
those 13 lines diverged. Session 18 completed it: the x/y/z arms are
evaluated first, and only if they all pass *and* `allFour` is set do we write
`this.w` and then test `|w| < tolerance`.

**File**: `SWFModernRuntime/src/avm2/avm2_display.c` — `v3_near_equals()`

---

## colorTransform: aMult-Only > 1 Has No Effect

**Affected test**: `bitmap_data_colortransform`

**The bug**: When `BitmapData.colorTransform()` is called with a ColorTransform where
ONLY `alphaMultiplier` is greater than 1 and all other parameters are at their defaults
(rMult=1, gMult=1, bMult=1, all offsets=0), Flash silently ignores the transform — the
bitmap is not modified. If any other parameter is non-default (e.g., rMult=2 alongside
aMult=2), the transform applies normally, including the alpha multiplier.

**Evidence**: The test's own ActionScript source documents it:
```as
// Flash bug: Transform with only alpha multiplier > 1 has no effect!
addTestBitmap(4, 1, 1, 1, 2, 0, 0, 0, 0);

// But if any other property is non-default, it does have an effect.
addTestBitmap(5, 2, 1, 1, 2, 0, 0, 0, 0);
```

**What we did**: Added an early-return check in `bitmapDataColorTransform()`:
```c
// Flash bug: if ONLY aMult > 1 and everything else is default, no effect
if (aMult > 1.0 && rMult == 1.0 && gMult == 1.0 && bMult == 1.0 &&
    rOff == 0.0 && gOff == 0.0 && bOff == 0.0 && aOff == 0.0) {
    return r;
}
```

**Impact**: Without this fix, pixels in the aMult-only row had exactly 2x the expected
RGB values (726 outliers at tolerance 5, max diff 125). With the fix, 0 outliers.

**File**: `SWFModernRuntime/src/actionmodern/action.c` — `bitmapDataColorTransform()`

---

## duplicateMovieClip invalidates source for TextSnapshot (accidentally matched)

**Affected test**: `textsnapshot_available_text`

**The bug**: After `duplicateMovieClip(source, clone, depth)`, constructing a
new TextSnapshot from the **source** MC returns an object whose `getText`
yields `undefined` rather than the source's static text. The clone still
works normally. Each subsequent `duplicateMovieClip(X, Y, d)` call
invalidates X in the same way.

**Evidence**: The expected trace for the test shows:
```
child: ABCD                 # initial new TextSnapshot(child).getText(0, 100)
// duplicateMovieClip("child", "child_clone", d1)
child: undefined            # new TextSnapshot(child).getText(...) after duplicate
child_clone: ABCD           # the fresh clone still works
// duplicateMovieClip("child_clone", "child_clone2", d2)
child_clone: undefined      # child_clone is now ALSO invalidated
child_clone2: ABCD          # the newest clone still works
```

Ruffle replicates this by failing `as_movie_clip()` (or similar) on the
invalidated source during `new TextSnapshot(target)`, so the native
`NativeObject::TextSnapshot` is never attached and `get_text` bails to
`Value::Undefined` at the top of the function.

**What we did**: Nothing explicit. We match the expected output
*accidentally* via a different mechanism — after `duplicateMovieClip`, our
`child` variable no longer resolves as `ACTION_STACK_VALUE_MOVIECLIP` in
the `new TextSnapshot(...)` constructor path at action.c:41862, so
`native_type` is never set and `builtin_ts_getText` returns `ret`
(undefined) at the top of the function.

**Tripwire**: If our variable-resolution or duplicateMovieClip handling
ever changes such that `child` still resolves as a MOVIECLIP after a
duplicate call, `builtin_ts_getText` will fall through to
`textSnapshotCapture`, see a zero-count native snapshot, and return
`undefined` for a different reason — which happens to be the same answer,
so the test will still pass. However, a prior fix attempt (commit
d74b2825, reverted in 91378cce) made `builtin_ts_getText` fall through to
`""` for zero-count native snapshots, which **did** regress this test
from 20/20 to 14/20. Any future change that distinguishes "empty native"
from "no native" by returning an empty string in the former case must
preserve `undefined` for invalidated-source MCs — otherwise this test
regresses silently on the line that expects `child: undefined`.

**File**: `SWFModernRuntime/src/actionmodern/action.c` —
`builtin_ts_getText`, TextSnapshot constructor at ~line 41862.
