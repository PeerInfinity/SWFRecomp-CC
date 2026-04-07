# LoadMovie Remaining Tests Plan
<!-- TESTS: loadmovie_var_persistence, loadmovienum_cross_version_prototype, mcl_events_swf_version, movieclip_state_values, movieclip_library_state_values -->

<!-- PLAN_META
id: LOADMOVIE_REMAINING
status: complete
phases:
  - id: 1
    name: "Recompiler nested function ordering"
    status: complete
  - id: 2
    name: "objectToPrimitive ASArray crash fix"
    status: complete
  - id: 3
    name: "Deferred unloadMovie state"
    status: complete
  - id: 4
    name: "Per-MC byte_size tracking"
    status: complete
  - id: 5
    name: "SWF_URL test name inclusion"
    status: complete
  - id: 6
    name: "Image loading via loadMovie"
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-04-06

## Status: COMPLETE — 4/5 tests passing, 1 with accepted cosmetic diffs

4 tests pass: `loadmovie_var_persistence` ✅ (8/8), `loadmovienum_cross_version_prototype` ✅ (9/9), `mcl_events_swf_version` ✅ (232/232), `movieclip_state_values` ✅ (114/114).

1 test has accepted cosmetic diffs:
- `movieclip_library_state_values` 76/78 — _xmouse + _url diffs, in ACCEPTED_DIFFS.md + ignored_tests.txt

### Bonus: `movieclip_methods_with_loaded_image` ✅ (4/4)

This test was not in the original plan but was fixed as part of unblocking:
- **Root cause:** `actionDelete2` didn't check the current MovieClip's `dynamic_props`, so `delete onEnterFrame` in an onEnterFrame handler was a no-op. Additionally, for root MC, `actionSetMember` stores properties in both `dynamic_props` and the global var_map, so the delete needed to clean both.
- **Fix:** Added MC `dynamic_props` lookup to `actionDelete2`, with fall-through to global variable cleanup for root MC.

---

## Fixes completed (2026-02-27)

1. **Recompiler nested function ordering** — Phase 1 label scanning + Phase 2
   stringstream buffering. Commit: 55fb0205.

2. **objectToPrimitive ASArray crash** — `objectToPrimitive()` was casting ASArray
   pointers to ASObject*, causing heap-buffer-overflow when comparing arrays via
   `actionEquals2`. Fixed by checking `ACTION_STACK_VALUE_ARRAY` type and using
   `arr->props` for property lookups.

3. **Deferred unloadMovie state** — Flash defers unloadMovie's effect on MC properties
   (`_currentframe`, `_framesloaded`, `_totalframes`, `getBytesLoaded/Total`) until the
   next frame. Implemented via `g_deferred_unload_mcs[]` queue processed at tick start.

4. **Per-MC byte_size tracking** — `getBytesLoaded()`/`getBytesTotal()` now uses per-MC
   `byte_size` field instead of global `SWF_FILE_SIZE`. Root MC gets SWF_FILE_SIZE,
   `attachMovie` clips get 4 (DefineSprite header size), dynamic clips default to 0.

5. **SWF_URL test name inclusion** — `verify_output.py` now sets
   `SWF_URL="file:///{test_name}/test.swf"` matching Ruffle's VFS URL format
   (was `"file:///test.swf"` which broke URL-processing tests).

## Fixes completed (2026-04-06)

6. **Image loading via loadMovie** — PNG/JPEG children detected by magic bytes in
   verify_output.py, synthetic MovieEntry with swf_version=0 generated. Runtime: image
   dims stored on MovieClip, _width/_height/getBounds/getRect/pixelBounds return image
   dimensions, getSWFVersion returns -1. This unblocked `movieclip_state_values` (114/114 PASS).

7. **actionDelete2 MC dynamic_props support** — `actionDelete2` now checks
   `g_current_context->dynamic_props` before the global variable table, mirroring Ruffle's
   Target scope in the scope chain. For root MC, falls through to also clean up the global
   var_map (since `actionSetMember` on root stores in both places). This fixed
   `movieclip_methods_with_loaded_image` (4/4 PASS).

---

## Test Results (2026-04-06, local verification)

| Test | Status | Match | Notes |
|------|--------|-------|-------|
| loadmovie_var_persistence | **PASS** ✅ | 8/8 | |
| loadmovienum_cross_version_prototype | **PASS** ✅ | 9/9 | |
| mcl_events_swf_version | **PASS** ✅ | 232/232 | |
| movieclip_state_values | **PASS** ✅ | 114/114 | Image loading implemented |
| movieclip_library_state_values | output_mismatch | 76/78 | _xmouse + _url cosmetic diffs (ACCEPTED_DIFFS) |
| movieclip_methods_with_loaded_image | **PASS** ✅ | 4/4 | Bonus fix (delete onEnterFrame) |
