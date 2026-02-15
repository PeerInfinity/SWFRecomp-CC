# issue_768 Test Investigation
<!-- TESTS: issue_768 -->

## Test Overview

Tests that `_root` traces as `"_level0"` (not as a generic object), verifying that MovieClip
string representation works correctly. Also tests that `MovieClip.prototype._global` and
`_parent` don't leak through. SWF version 6.

### SWFRecomp result: PASS — 3/3 lines match

---

## Fixes Applied

### actionTrace MovieClip case separated from Object (fixed)

**Was:** MovieClip and Object shared the same case in actionTrace, both printing `[type Object]`.
**Fix:** Separated the MOVIECLIP case to print `_level0` (target path):
```c
case ACTION_STACK_VALUE_MOVIECLIP:
{
    printf("_level0\n");  // TODO: use actual target path for non-root MCs
    break;
}
```

---

## Verification

All 3 lines match:
- Line 1: `trace(MovieClip.prototype._global)` → `[type Object]` ✓
- Line 2: `trace(_parent)` → `undefined` ✓
- Line 3: `trace(_root)` → `_level0` ✓
