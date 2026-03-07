# _lockroot / _root Resolution Plan
<!-- TESTS: movieclip_lockroot -->

Last updated: 2026-03-06

## Status: ACTIONABLE — not blocked

### Overview

The `_lockroot` property is already stored on MovieClips (`mc->lockroot` in action.h) and the getter/setter work correctly (lines 1-17 of the test pass). However, `_root` resolution completely ignores `lockroot` — it always returns `&root_movieclip`.

**Test**: `movieclip_lockroot` — 19/29 (66%). All 10 failing lines show the same pattern: `root is _level0` when it should be `root is _level0.childX`.

### Root Cause

In `action.c` line 29468, the `_root` getter unconditionally returns the global root:

```c
if (strcasecmp(prop_name, "_root") == 0) {
    PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)&root_movieclip);
    return;
}
```

### Flash Semantics

When `mc._lockroot == true`:
- `mc._root` returns `mc` itself (the locked MC acts as its own root)
- Children of `mc` also see `mc` as `_root` (walk up parent chain to find nearest lockroot ancestor)
- `mc._root._root._root...` chains through lockroot boundaries

When `mc._lockroot == false` (default):
- `mc._root` returns the nearest ancestor with `lockroot == true`, or the global root if none

### Fix

**Phase 1: _root getter** (~10 lines)

Replace the unconditional `&root_movieclip` return with a parent-chain walk:

```c
if (strcasecmp(prop_name, "_root") == 0) {
    // Walk up parent chain to find nearest lockroot ancestor
    MovieClip* root = mc;
    while (root->parent != NULL) {
        if (root->lockroot) break;  // This MC is its own root
        root = root->parent;
    }
    // If we reached the global root (parent==NULL), use root_movieclip
    if (root->parent == NULL && !root->lockroot)
        root = &root_movieclip;
    PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)root);
    return;
}
```

**Phase 2: Path resolution** (may not be needed for this test)

The `resolveFlashPathToMC` and similar path-resolution functions also hardcode `_root` → `&root_movieclip`. If tests require `_root` in path strings (like `_root.child`) to respect lockroot, these would need updating too. Check whether `movieclip_lockroot` exercises path resolution or only the property getter.

Sites to check:
- `action.c:11473` — `getMovieClipByTarget` `_root` check
- `action.c:11661` — `resolveSlashPath` `_root`/`_level0` check
- `action.c:11871` — `resolveFlashPathToMC` `_root` check
- `action.c:11885` — same function, non-first-element branch

### Expected Outcome

| Phase | Lines Gained | Test Result |
|-------|-------------|-------------|
| Phase 1 | +10 | 29/29 (if only getter is needed) |
| Phase 2 | +0 (safety) | Ensures path strings also work |

### Dependencies

None — this is fully actionable. The `lockroot` field already exists on MovieClip, getter/setter already work. Only the _root resolution logic needs updating.

### Risks

- loadMovie tests that use `_lockroot` with cross-movie isolation may need per-movie root tracking, but that's already blocked by LOADMOVIE_PLAN and won't regress from this fix.
- Need to verify `_root` in GetVariable (not just GetMember) also goes through the right path. Currently `actionGetVariable("_root")` likely returns `&root_movieclip` directly — may need the same fix.
