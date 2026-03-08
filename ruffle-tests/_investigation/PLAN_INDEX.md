# Image Comparison Test Plans — Index

## Overview

32 Ruffle AVM1 tests include image comparisons. These plans describe the work needed to pass all of them. Plans are ordered by priority (highest value per effort).

## Shared Dependency: `renderer_draw_rect()`

Plans 02 and 04 both need a `renderer_draw_rect()` function for drawing dynamic filled rectangles. This should be implemented first as shared infrastructure.

## Plan Summary

| Plan | Feature | Tests Unlocked | Complexity | Status |
|------|---------|---------------|------------|--------|
| [01](PLAN_01_RUNTIME_TRANSFORMS.md) | Runtime transform & cxform GPU updates | 2 | Medium | Not started |
| [02](PLAN_02_TEXTFIELD_RENDERING.md) | TextField background/border/text rendering | 5 | Large | Not started |
| [03](PLAN_03_DRAWING_API.md) | Drawing API (beginFill/lineTo/etc.) | 4 | Large | Not started |
| [04](PLAN_04_FOCUS_RECT.md) | Focus rect yellow outline | 6 (41 images) | Small-Medium | Not started |
| [05](PLAN_05_BITMAP_AND_MEDIA.md) | BitmapData rendering + external media | 13 | Very large | Not started |

## Recommended Implementation Order

### Sprint 1: Bug Fixes (Plan 01)
- Fix runtime transform GPU updates (`as_set_flags` → rebuild matrix)
- Fix runtime cxform GPU updates (`cx_overridden` → rebuild cxform)
- Expected result: `display_object_properties` passes (tolerance=90)

### Sprint 2: Dynamic Rect Infrastructure + TextField Phase 1 (Plans 02/04 shared)
- Implement `renderer_draw_rect()` for dynamic filled rectangles
- Add text field background/border rendering
- Expected result: `frame_size_translated_*` pass (max_outliers=1)

### Sprint 3: Focus Rect (Plan 04)
- Draw yellow focus outline using `renderer_draw_rect()`
- Add focus highlight visibility state tracking
- Expected result: All 6 focusrect tests pass (41 images)

### Sprint 4: Drawing API Phase 1 (Plan 03)
- Path recording + solid fill tessellation
- Expected result: `movieclip_setmask` passes

### Sprint 5+: Advanced Features (Plans 03/05)
- Gradient fills, text content rendering, BitmapData, external media
- These unlock remaining tests progressively

## Cross-References
- [IMAGE_COMPARISON_TESTS.md](IMAGE_COMPARISON_TESTS.md) — Full investigation report with per-test analysis
- [headless_rendering.md](/home/robert/.claude/projects/-home-robert-CC-SWFRecomp-CC/memory/headless_rendering.md) — Session memory for headless pipeline

## Already Fixed (This Session)
- Stage origin offset in `stage_to_ndc` matrix (SWFRecomp/src/swf.cpp)
- Dynamic transform slot allocation for sprite composition (tag.c)
- verify_output.py: actual/difference PNG saving, expected PNG copying
