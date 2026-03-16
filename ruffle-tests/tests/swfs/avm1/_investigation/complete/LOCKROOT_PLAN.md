# _lockroot / _root Resolution Plan
<!-- TESTS: movieclip_lockroot -->

Last updated: 2026-03-06

## Status: COMPLETE — movieclip_lockroot 29/29 PASS

### Overview

The `_lockroot` property controls `_root` resolution. When `mc._lockroot == true`, that MC acts as its own root — `_root` returns the nearest lockroot ancestor instead of the global root.

**Test**: `movieclip_lockroot` — **29/29 PASS**

### What was fixed

Three sites needed updating:

1. **Recompiler `preload_root`** (action.cpp:1483): DefineFunction2 `preload_root` flag emitted `&root_movieclip` directly. Changed to call `actionGetLockRoot()` which walks the parent chain at runtime.

2. **`actionGetMember` `_root` getter** (action.c:29476): Unconditionally returned `&root_movieclip`. Now walks `mc->parent` chain, stopping at first MC with `lockroot == true`.

3. **`actionGetVariable` `_root` handler** (action.c:21733): Same unconditional `&root_movieclip`. Now uses `g_current_context` as starting point and walks parent chain.

Runtime helper `actionGetLockRoot()` added for the recompiler preload path.

### Phase 2: Path resolution — NOT NEEDED for this test

Path resolution functions (`resolveFlashPathToMC`, `getMovieClipByTarget`, `resolveSlashPath`) still hardcode `_root` → `&root_movieclip`. The `movieclip_lockroot` test only exercises the property getter, not path strings. If future tests need lockroot-aware path resolution, these sites would need updating.

### Regression testing

19 tests verified passing after the fix: path_string, string_paths_basic, string_paths_hidden, tell_target, tell_target_invalid, tell_target_invalid_swf6, root_global_parent, root_onload, goto_frame, goto_frame2, goto_label, this_scoping, execution_order4, define_function2_preload, define_function2_preload_order, function_base_clip_removed, swf5_no_closure, stage_object_children, slash_syntax.
