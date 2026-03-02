# MC Removal Lifecycle Plan

## Overview

When a MovieClip is removed from the display list (via `removeMovieClip()`, `unloadMovie()`, or timeline removal), closures that captured it as `base_clip` and code that references it via paths need well-defined fallback behavior. Currently the runtime marks removed MCs with `depth = INT_MIN` and property access returns undefined, but scope/path fallback logic is incomplete.

**Blocks these tests:**
| Test | Current | Missing |
|------|---------|---------|
| `function_base_clip_removed` | 21/26 (80.8%) | base_clip scope fallback after removal |
| `function_base_clip_readded` | 10/12 (83.3%) | _parent resolution after removal + re-add |
| `string_paths_other` | 31/36 (86.1%) | Removed MC in path resolution, re-creation |
| `removed_target_clip_scope` | unknown | SetTarget scope with removed target |
| `removed_base_clip_tell_target` | unknown | SetTarget via removed base_clip |

**Related plans:** TELLTARGET_PLAN (3 tests), CLONE_DUPLICATE_PLAN (partially)

---

## Current Architecture

### Removal Mechanism

`actionRemoveSprite()` (action.c ~line 27202):
1. Find MC by name in `child_mc_cache[]`
2. Check removable depth (0 to `AVM_MAX_REMOVE_DEPTH`)
3. Queue `onUnload` handler for deferred firing at next ShowFrame
4. Clear from parent's `dynamic_props`
5. Clear from root-level variable table
6. **Mark as removed:** `mc->depth = INT_MIN`
7. Nullify cache: `child_mc_cache[i] = NULL`

### Removal Detection Points

Three locations check `depth == INT_MIN`:
- `convertString()` (~line 11990): returns empty string for removed MCs
- `actionGetMember()` (~line 24417): all property access returns undefined
- `targetPath()` (~line 30514): returns empty string

### base_clip Context Switch (no removal check)

In `actionCallFunction()` and `actionCallMethod()` (~lines 3041-3044):
```c
if (g_swf_version >= 6 && func->base_clip != NULL)
    g_current_context = (MovieClip*)func->base_clip;
```

No check for `func->base_clip->depth == INT_MIN`. The context switches to a "dead" MC.

### Path Resolution After Removal

`child_mc_cache[i] = NULL` prevents name lookups from finding removed MCs. But closures holding direct `MovieClip*` pointers still reference the struct in memory (which is never freed in NO_GRAPHICS mode).

---

## Phase 1: base_clip Removal Detection (function_base_clip_removed)

**Goal:** When a closure's base_clip is removed, function calls fall back correctly. Test: 21/26 → 26/26.

### Expected Behavior (from test output)

Before removal of `functionDefiner` MC:
```
// clip1.f() — base_clip is functionDefiner
this: _level0.clip1
_parent: _level0
_root.functionDefiner: [object Object]  // Still exists
```

After removal of `functionDefiner`:
```
// clip2.obj.f() — base_clip was functionDefiner (now removed)
this: _level0.clip2        // 'this' is the receiver
_parent: _level0           // _parent of receiver, not removed MC
_root.functionDefiner: undefined  // Removed
```

### Key Insight

When `base_clip` is removed:
- The function should still execute (not error)
- `this` should be the call receiver (not the removed base_clip)
- Scope resolution should NOT use the removed MC as context
- The function's base_clip effectively becomes "detached" — scope falls back to the call site's context

### Implementation

In the closure context switch paths (`actionCallFunction`, `actionCallMethod`):

```c
if (g_swf_version >= 6 && func->base_clip != NULL) {
    MovieClip* bc = (MovieClip*)func->base_clip;
    if (bc->depth != INT_MIN) {
        // Normal case: base_clip is alive
        g_current_context = bc;
    }
    // else: base_clip removed, keep caller's context (don't switch)
}
```

This is the minimal change. The function executes in the caller's context instead of the removed base_clip's context, which matches Flash's behavior of "detached" closures.

### Files to Modify
- `action.c`: all closure context switch sites (actionCallFunction, actionCallMethod, both simple and advanced paths)

---

## Phase 2: _parent Resolution on Removed MCs (function_base_clip_readded)

**Goal:** After a MC is removed and a new one placed at the same name/depth, `_parent` resolves correctly. Test: 10/12 → 12/12.

### Expected Behavior

```
// Before removal
trace(this._parent);    // _level0 (parent of the MC)

// After removal + re-creation at same name
trace(this._parent);    // _level0 (parent of the NEW MC)
```

### Key Insight

When a MC is removed and re-added:
- The old struct has `depth = INT_MIN`
- A new struct is created for the new MC
- Closures with `base_clip` pointing to the old struct still see `depth = INT_MIN`
- `_parent` on the old struct should return undefined (it's removed)
- But if the closure is called on the NEW MC (via `newMC.f()`), the `this` binding should resolve `_parent` through the receiver, not the base_clip

### Implementation

The Phase 1 fix (skip removed base_clip) should handle most of this. The remaining issue may be `_parent` resolution specifically:

In the MC builtin property handler for `_parent`:
```c
if (mc->depth == INT_MIN) {
    // Removed MC — _parent is undefined
    push_undefined();
    return;
}
```

This should already be handled by the general "removed MC returns undefined for all properties" check at `actionGetMember()` line 24417. Verify that `_parent` specifically goes through this path (it may be handled as a special builtin before the removal check).

### Files to Modify
- `action.c`: verify `_parent` goes through removal check; if not, add explicit check in MC builtin property handler

---

## Phase 3: Path Resolution with Removed MCs (string_paths_other)

**Goal:** Slash/dot path resolution correctly handles removed and re-created MCs. Test: 31/36 → 36/36.

### Expected Behavior

The 5 failing lines in `string_paths_other` likely involve:
1. Accessing a path where an intermediate MC was removed
2. Re-creating a MC at the same name and accessing it via path
3. Variable scoping through removed MC paths

### Scenarios

**Removed MC in path:**
```actionscript
_root.child.removeMovieClip();
trace(_root.child);          // undefined
trace(_root.child._name);    // undefined (can't traverse through removed)
```

**Re-created MC:**
```actionscript
_root.child.removeMovieClip();
_root.createEmptyMovieClip("child", 1);
trace(_root.child);          // [object Object] (new MC)
trace(_root.child._name);    // "child" (new MC's name)
```

### Implementation

The current cache-nullification approach (`child_mc_cache[i] = NULL`) already prevents name lookups from finding removed MCs. The re-created MC gets a fresh cache entry.

Potential issues:
1. **var_map references** — If a removed MC was stored in var_map via its name, the var_map entry may still point to the old struct. Need to clear var_map entries on removal.
2. **Root MC child enumeration** — `actionEnumerate2` var_map path may return stale entries for removed MCs.

### Investigation Needed
Run `string_paths_other` test and examine the specific 5 failing lines to determine exact root cause. The fix likely involves one of:
- Clearing var_map entries for removed MC names
- Checking `depth == INT_MIN` in var_map-based path resolution
- Updating `resolveSlashPathToMC` to handle removed intermediates

### Files to Modify
- `action.c`: `actionRemoveSprite()` — ensure var_map cleanup
- `action.c`: `resolveSlashPathToMC()` — verify removed MC handling

---

## Phase 4: SetTarget with Removed MCs (removed_target_clip_scope, removed_base_clip_tell_target)

**Goal:** SetTarget/SetTarget2 behaves correctly when target or base_clip is removed.

### Expected Behavior

**removed_target_clip_scope:**
- SetTarget to a removed MC → target_clip becomes None → `g_settarget_none = 1`
- Subsequent property access returns undefined
- SetTarget("") resets to base_clip (which may also be removed)

**removed_base_clip_tell_target:**
- When base_clip is removed and SetTarget("") tries to reset → falls to root
- Test expects: scope = "/" (root) after base_clip removal

### Implementation

SetTarget resolution already handles "target not found" via `g_settarget_invalid` and `g_settarget_none` flags. The issue is the interaction with removed base_clip:

1. **SetTarget("") with removed base_clip:**
   In the SetTarget handler, when resetting to base_clip:
   ```c
   if (base_clip->depth == INT_MIN) {
       // base_clip removed — reset to root
       g_current_context = &root_movieclip;
   } else {
       g_current_context = base_clip;
   }
   ```

2. **SetTarget2 with removed MC:**
   When `SetTarget2(mc_ref)` is called and the MC has been removed:
   - If the MC ref resolves to a removed MC, treat as "not found"
   - Set `g_settarget_invalid = 1`, `g_settarget_none = 1`

### Files to Modify
- `action.c`: SetTarget/SetTarget2 handlers — add removal checks

---

## Phase 5: Unload Handler Timing (string_paths_unload)

**Goal:** `onUnload` fires at the correct time relative to removal.

### Expected Behavior
- `onUnload` handler fires AFTER the MC is marked as removed but BEFORE the next frame
- Inside `onUnload`, the MC's properties are still accessible (not yet fully cleaned up)
- After `onUnload` completes, the MC is fully "dead"

### Current Implementation
`actionRemoveSprite()` queues onUnload for deferred firing at next ShowFrame. This may need adjustment:
- Verify the MC is still accessible during onUnload execution
- Verify `depth` is set to `INT_MIN` before or after onUnload (ordering matters)

### Investigation Needed
Examine the `string_paths_unload` test output and determine exact timing expectations. This may overlap with UNLOAD_PLAN.

---

## Implementation Priority

| Phase | Effort | Tests Affected | Lines Gained | Priority |
|-------|--------|---------------|-------------|----------|
| Phase 1: base_clip removal detect | Small (~10 lines) | function_base_clip_removed | ~5 | High |
| Phase 2: _parent on removed MCs | Small (~5 lines) | function_base_clip_readded | ~2 | High |
| Phase 3: Path resolution | Medium (~30 lines) | string_paths_other | ~5 | Medium |
| Phase 4: SetTarget + removed MCs | Small (~15 lines) | removed_target_clip_scope, removed_base_clip_tell_target | ~10+ | Medium |
| Phase 5: Unload timing | Unknown | string_paths_unload | ~5+ | Low |

**Recommended order:** Phase 1 → 2 → 4 → 3 → 5.

Phase 1 is the most impactful — it fixes the fundamental base_clip fallback and likely cascades to fix several lines across multiple tests.

---

## Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=function_base_clip_removed --diff --verbose
python3 ruffle-tests/verify_output.py --test=function_base_clip_readded --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_paths_other --diff --verbose
python3 ruffle-tests/verify_output.py --test=tell_target --diff --verbose
python3 ruffle-tests/verify_output.py --test=tell_target_invalid --diff --verbose
python3 ruffle-tests/verify_output.py --test=tell_target_invalid_swf6 --diff --verbose
python3 ruffle-tests/verify_output.py --test=target_clip_removed --diff --verbose
python3 ruffle-tests/verify_output.py --test=path_string --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_paths_basic --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_paths_hidden --diff --verbose
python3 ruffle-tests/verify_output.py --test=this_scoping --diff --verbose
python3 ruffle-tests/verify_output.py --test=unloadmovie --diff --verbose
```
