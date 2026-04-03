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
