# Per-Movie `_global` Isolation Plan

## Status: PARTIALLY RESOLVED / BLOCKED

**Score**: `global_swf5_6_7_8_9` — 1073/1145 (72 diff lines remaining)

### What was resolved:
- **SWF5 `_global` restriction**: Direct `GetVariable("_global")` returns undefined for SWF5. (Implemented)
- **Object constructor display**: `[type Function]` now correctly displayed for function values in string concatenation. Fixed `objectCallValueOf` and `objectCallToString` to not look up inherited Object.prototype methods on function own_props. (Implemented)
- **Two-group `_global` model**: Confirmed CORRECT. `global_swf6_7_8` test expects `g7 === g8: true`, proving SWF7+ share `_global`. `g_global_legacy` (SWF ≤6) and `g_global_modern` (SWF 7+) is the right architecture.

### What remains (72 diffs — all per-movie Function.prototype identity):
All 72 remaining diffs are of the form:
```
expected: s1.aFunction.__proto__ == s2.aFunction.__proto__: false
  actual: s1.aFunction.__proto__ == s2.aFunction.__proto__: true
```
Affects: `aFunction.__proto__`, `aMovieClipClass.__proto__`, `aBooleanClass.__proto__` across ALL cross-movie pairs (including SWF5 vs SWF6 within the same version group).

### Root cause:
In Ruffle/Flash, each loaded SWF movie creates its own `Function.prototype`. User-defined functions (`function() {}`) get their `__proto__` set to the movie-local Function.prototype. Constructor references like `MovieClip` and `Boolean` from a movie's scope also have their `__proto__` pointing to that movie's Function.prototype.

Our implementation has no `Function.prototype` at all — all functions' `own_props.__proto__` points to the shared `Object.prototype`. So `func1.__proto__ === func2.__proto__` is always `true` regardless of which movie they came from.

### Why per-movie `_global` was WRONG:
The original plan proposed per-movie `_global` objects (one per loaded SWF). Implementation revealed this breaks `global_swf6_7_8` which expects `g7 === g8: true` — SWF7+ movies share the same `_global`. The two-group model (legacy/modern) is correct for `_global` itself.

### Blocked by: Per-movie Function.prototype
To fix the 72 remaining diffs, we need:
1. A `Function.prototype` object per loaded movie
2. Setting `fn->own_props.__proto__` to the movie-local Function.prototype when functions are defined
3. Tracking which movie context is active when `actionDefineFunction`/`actionDefineFunction2` is called

This is a moderate architectural change (not as large as per-movie `_global`) but still requires:
- A per-movie prototype registry (just Function.prototype, not full _global)
- Movie context tracking on ASFunction (the `movie_global_idx` field is already added but unused)
- Wiring up all 5 load sites + function definition sites

### Impact assessment:
- 72 lines out of 1145 (6.3%) — low priority
- No other tests are blocked by this
- The fix only affects `__proto__` identity comparisons on functions, which is an unusual pattern

---

## Correction Record

**Original plan**: Per-movie `_global` with `MovieGlobalEntry` registry, `createMovieGlobal()` factory, etc.

**Attempt**: Implementation began, `movie_global_idx` field added to ASFunction, `switchToFunctionVersion` updated with 3-param signature. Discovered `global_swf6_7_8` regression. REVERTED all per-movie `_global` infrastructure. Kept the two-group model.

**Key learning**: The `_global` object is shared within version groups (SWF ≤6, SWF 7+). But `Function.prototype` is per-movie. These are independent properties — per-movie `Function.prototype` doesn't require per-movie `_global`.

**Already implemented changes** (kept from the attempt):
- `movie_global_idx` field on ASFunction (reserved, unused)
- `switchToFunctionVersion` 3-param signature (3rd param reserved, unused)
- SWF5 `_global` restriction in `actionGetVariable`
- `objectCallValueOf` early return for FUNCTION type
- `objectCallToString` skip inherited toString for FUNCTION type (check for direct toString only)
