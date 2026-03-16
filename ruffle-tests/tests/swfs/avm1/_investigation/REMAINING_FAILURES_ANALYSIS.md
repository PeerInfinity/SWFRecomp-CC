# Remaining Filtered Failures Analysis

Date: 2026-03-15 (evening)
CI run: de8b5c0b (559/619 total, 549/563 filtered = 97.5%)

13 filtered tests still failing. This document analyzes each one with local test output, root cause, and fix feasibility.

## Recently Fixed (this session)

| Test | Before | After | Fix |
|------|--------|-------|-----|
| text_blocks_clicks | 3/4 | PASS | DefineText bounds for `_droptarget` |
| issue_2030 | 2/4 | PASS | `MC.attachBitmap` stub |
| unload_nested_child | 0/5 | PASS | Nested MC click, recursive child unload, deferred UNLOAD |
| target_clip_removed | segfault | PASS | char_id guard in upgrade_sprite_initialized |
| issue_2084 | 4/16 | PASS | Nested attachMovie + registerClass ordering |
| coerce_to_object_monkeypatch | 71/129 | PASS | Primitive auto-boxing, addProperty getter, this fallback |
| clone_sprite_edittext_dynamic | 78/86 | PASS | TF clone property copy, rotated bounding box |
| bitmap_data_draw_cliprect | 9/13 | PASS | Implement `BitmapData.draw()` with matrix + clipRect |
| bitmap_data_copypixels | 15/17 | PASS | Alpha compositing in `copyPixels` mergeAlpha=true |

## Summary Table — Remaining Failures

| Test | Match | Total | Rate | Difficulty | Category |
|------|-------|-------|------|------------|----------|
| movieclip_hittest_shapeflag | ~312 | 339 | 92% | Hard | shape hit accuracy |
| edittext_drag_select | 6 | 9 | 67% | Not feasible | character-level selection (NO_GRAPHICS) |
| asfunction | 2 | 12 | 17% | Not feasible | character-level text link hit-testing |
| displacementmapfilter_mappoint_throw_error | 0 | 13 | 0% | Hard | filter setter validation + valueOf errors |
| edittext_ime_focus_lost | 0 | 7 | 0% | Not feasible | IME infrastructure |
| localconnection | 127 | 580 | 22% | Not feasible | full IPC system |
| global_proto_decls | ~82 | 4497 | 2% | Very Hard | property flags + stubs |
| global_instance_decls | ~4 | 758 | 1% | Very Hard | property flags + stubs |
| global_proto_decls_delete | ~47 | 4158 | 1% | Very Hard | property flags + stubs |
| swf5_xml_event_handler_context | 0 | 2 | 0% | Not feasible | XML.load() |
| movieclip_methods_with_loaded_image | 0 | 4 | 0% | Not feasible | external PNG loading |
| sandbox_type_remote | 0 | 3 | 0% | Not feasible | multi-SWF sandbox |

## Tier 1: Potentially Actionable (1 test)

### movieclip_hittest_shapeflag (~312/339 = 92%)

~27 lines wrong (improved from 32). Shape-flag hitTest (`hitTest(x, y, true)`) returns wrong results for various coordinates. Remaining categories: device-font text (11 lines — no font outline data in SWF), curve/stroke precision (10 lines), drawing API bounds (4 lines), stroke-only morphs (4 lines). Incremental improvements possible but full accuracy needs shape rasterization.

## Tier 2: Not Feasible in NO_GRAPHICS Mode (3 tests)

### edittext_drag_select (6/9 = 67%)

Requires character-level text layout to map mouse pixel positions to character indices for `<selection>` markers. Not feasible without a text layout engine.

### asfunction (2/12 = 17%)

Requires character-level text link hit-testing to determine which `<a href="asfunction:...">` link was clicked at a given pixel position. Same fundamental limitation as edittext_drag_select.

### edittext_ime_focus_lost (0/7)

Requires IME (Input Method Editor) infrastructure — text input via IME composing, focus changes, onChanged callbacks. IME doesn't exist.

## Tier 3: Major Infrastructure / Diminishing Returns (9 tests)

### displacementmapfilter_mappoint_throw_error (0/13)

`DisplacementMapFilter.mapPoint` setter needs to coerce input object's x/y to int32 (creating a proper Point), and handle valueOf errors via try/catch. Also needs integer overflow clamping. Complex setter validation.

### localconnection (127/580 = 22%)

Full `LocalConnection` IPC system not implemented. Requires connect/send/close methods, onStatus callbacks, receiver method dispatch. Massive standalone feature.

### global_proto_decls (~82/4497 = 2%)

`constructor` DONT_ENUM conflict, missing class stubs, output truncates early. Enormous surface area. See BLOCKER_SUMMARY.md Blocker 4.

### global_instance_decls (~4/758 = 1%)

Same class of problem as global_proto_decls.

### global_proto_decls_delete (~47/4158 = 1%)

Same root cause as global_proto_decls.

### swf5_xml_event_handler_context (0/2)

Requires `XML.load()` with onLoad callback in SWF5 context. XML loading not implemented.

### movieclip_methods_with_loaded_image (0/4)

Requires `loadMovie` to load an external PNG image. External asset loading not implemented.

### sandbox_type_remote (0/3)

Requires multi-SWF loading with different sandbox type configurations. Deep infrastructure.

## Completed Plans

Detailed planning docs for completed fixes are in `_investigation/complete/`:
- `UNLOAD_NESTED_CHILD.md` — deferred UNLOAD timing
- `ISSUE_2084.md` — nested attachMovie with registerClass
- `COERCE_TO_OBJECT_MONKEYPATCH.md` — primitive auto-boxing
- `CLONE_SPRITE_EDITTEXT_DYNAMIC.md` — TF clone property copy

## Recommended Priority Order

1. **movieclip_hittest_shapeflag** — incremental shape geometry improvements

Remaining 12 tests are blocked by missing infrastructure (IME, IPC, XML loading, multi-SWF) or NO_GRAPHICS limitations (character-level text layout), or have diminishing returns (global stubs) at 97.5% filtered pass rate.
