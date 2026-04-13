# Replicated Flash Bugs

Known Flash Player bugs that we deliberately replicate. These are documented quirks
in Flash's behavior — not spec-compliant, not arbitrary choices, and not Ruffle-specific
differences. Both Flash and Ruffle exhibit the same buggy behavior, and the Ruffle test
expected output reflects it.

This is distinct from:
- `ACCEPTED_DIFFS.md` — tests that can never match (UB, platform-specific, etc.)
- `RUFFLE_VS_FLASH_DIFFERENCES.md` — cases where we match Flash but Ruffle disagrees
- `RUFFLE_COMPAT_TWEAKS.md` — arbitrary choices where correct behavior is unclear

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
