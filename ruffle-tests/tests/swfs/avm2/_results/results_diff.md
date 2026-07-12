# Ruffle Test Results Diff

**Previous:** `f76422459ffa` (2026-07-12T05:29:38.685119+00:00)
**Current:** `2efd025eaf82` (2026-07-12T21:26:25.066771+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 727 | 754 | +27 |
| Total | 1201 | 1204 | +3 |
| Pass rate | 60.5% | 62.6% | +2.1% |
| Mismatched lines | 62108 | 59923 | -2185 |
|   Decreased | | | -3040 |
|   Increased | | | +508 |

## Newly Passing (28)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_constr` | output_mismatch | 0/17 | 17/17 |
| `bitmap_data` | output_mismatch | 0/1000 | 1000/1000 |
| `bitmap_properties` | output_mismatch | 0/23 | 23/23 |
| `bitmap_timeline` | output_mismatch | 0/9 | 9/9 |
| `bitmapdata_accuracy` | output_mismatch | 0/1 | 1/1 |
| `bitmapdata_clone` | output_mismatch | 0/13 | 13/13 |
| `bitmapdata_colortransform_oob` | output_mismatch | 0/2 | 2/2 |
| `bitmapdata_constr` | output_mismatch | 0/22 | 22/22 |
| `bitmapdata_constructor_from_timeline` | output_mismatch | 0/1 | 1/1 |
| `bitmapdata_copypixels` | output_mismatch | 0/23 | 23/23 |
| `bitmapdata_copypixels_blend_over` | output_mismatch | 0/1 | 1/1 |
| `bitmapdata_copypixelstobytearray` | output_mismatch | 0/39 | 39/39 |
| `bitmapdata_dispose` | output_mismatch | 0/7 | 7/7 |
| `bitmapdata_embedded` | output_mismatch | 0/9 | 9/9 |
| `bitmapdata_floodfill` | output_mismatch | 0/35 | 35/35 |
| `bitmapdata_getpixels` | output_mismatch | 0/39 | 39/39 |
| `bitmapdata_getvector` | output_mismatch | 0/27 | 27/27 |
| `bitmapdata_histogram` | output_mismatch | 0/59 | 59/59 |
| `bitmapdata_hittest` | output_mismatch | 0/112 | 112/112 |
| `bitmapdata_hittest_threshold` | output_mismatch | 0/18 | 18/18 |
| `bitmapdata_pixeldissolve` | output_mismatch | 3/1037 | 1037/1037 |
| `bitmapdata_rectangle_rounding` | output_mismatch | 0/16 | 16/16 |
| `bitmapdata_setpixels` | output_mismatch | 1/286 | 286/286 |
| `bitmapdata_setvector` | output_mismatch | 0/26 | 26/26 |
| `bitmapdata_threshold` | output_mismatch | 0/176 | 176/176 |
| `bitmapdata_zero_size` | output_mismatch | 0/5 | 5/5 |
| `edittext_get_char_index_at_point` | output_mismatch | 0/4 | 4/4 |
| `edittext_get_line_index_at_point` | output_mismatch | 0/2 | 2/2 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `stage_properties2` | output_mismatch | 8/8 | 18/213 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `accessibilityimplementation` | output_mismatch | 0/18 |
| `graphics_path` | output_mismatch | 0/56 |
| `primitive_valueOf` | output_mismatch | 12/285 |

## Line Count Changed (20)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmap_subclass` | output_mismatch | 0/7 | 6/7 | -6 |
| `bitmapdata_draw_alpha_erase` | output_mismatch | 0/8 | 6/8 | -6 |
| `filters_array_holes` | output_mismatch | 1/25 | 7/25 | -6 |
| `point` | output_mismatch | 12/132 | 16/132 | -4 |
| `bitmap_subclass_properties` | output_mismatch | 0/9 | 2/9 | -2 |
| `displayobject_scrollrect` | output_mismatch | 9/33 | 11/33 | -2 |
| `pixelbender_ceil` | output_mismatch | 1/77 | 3/77 | -2 |
| `pixelbender_sign` | output_mismatch | 1/60 | 3/60 | -2 |
| `place_and_lookup/swf10` | output_mismatch | 24/33 | 26/33 | -2 |
| `place_and_lookup/swf9` | output_mismatch | 24/33 | 26/33 | -2 |
| `stage_scale_factor` | output_mismatch | 5/12 | 6/12 | -1 |
| `all_classes/display/swf10` | output_mismatch | 2/2569 | 2/2569 | 0 |
| `all_classes/display/swf11` | output_mismatch | 2/2593 | 2/2593 | 0 |
| `all_classes/display/swf12` | output_mismatch | 2/2593 | 2/2593 | 0 |
| `all_classes/display/swf13` | output_mismatch | 2/2671 | 2/2671 | 0 |
| `all_classes/display/swf30` | output_mismatch | 0/2936 | 0/2936 | 0 |
| `pixelbender_outputs` | output_mismatch | 0/13 | 0/13 | 0 |
| `all_classes/display/swf9` | output_mismatch | 2/1959 | 1/1959 | +1 |
| `graphics_draw_path` | output_mismatch | 0/34 | 0/101 | +67 |
| `primitive_toString` | output_mismatch | 43/61 | 14/277 | +245 |
