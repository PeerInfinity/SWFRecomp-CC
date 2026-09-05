# Image triage board

`scripts/image_triage.py --stem graphics` over 205 failing comparisons from the image run at `65915386558b4edff5a2f21932534de280d53114` (2026-09-04T09:55:01.949766+00:00).

Ranked by **mechanism** first. Near-pass ranking alone aims at `hairline_edge_drift`, which is mostly the lavapipe-vs-Flash antialiasing gap — the least fixable cluster in the corpus.

## Clusters

| cluster | cmps | tests | near-pass | prior | example tests |
|---|---:|---:|---:|---:|---|
| `hairline_edge_drift` | 68 | 58 | 52 | 0.25 | `avm1/edittext_stylesheet`, `text/auto_size/height`, `text/auto_size/return`, `visual/cache_as_bitmap/edittext_hscroll` |
| `blank_render` | 35 | 35 | 0 | 0.30 | `avm2/stage3d_bitmap`, `avm2/stage3d_blend`, `avm2/stage3d_multistage_triangle`, `avm2/stage3d_program_constants_bytearray_be` |
| `diffuse_mixed` | 33 | 33 | 12 | 0.40 | `visual/blend_modes/add`, `visual/blend_modes/alpha_no_layer`, `visual/blend_modes/difference`, `visual/blend_modes/erase_no_layer` |
| `same_geometry_wrong_fill` | 25 | 25 | 2 | 0.80 | `visual/filters/color_matrix`, `avm2/bitmapdata_copypixels`, `avm2/bitmapdata_draw_self_via_graphic`, `visual/drawing_api/drawing_order` |
| `unrelated_content` | 11 | 3 | 0 | 0.15 | `visual/video/h264`, `avm2/bitmapdata_draw_masks`, `avm2/away3d_advanced_shallow_water_demo` |
| `missing_element` | 10 | 10 | 1 | 0.60 | `from_shumway/flash_text_TextField`, `from_shumway/hardwrap`, `from_shumway/stylesheet`, `visual/edittext/edittext_bounds_vs_position` |
| `content_displaced` | 8 | 7 | 0 | 0.50 | `from_shumway/avm1/text-bind`, `text/br_at_start`, `text/style_changes_in_html`, `visual/cache_as_bitmap/edittext_scroll` |
| `halo_penumbra` | 6 | 6 | 0 | 0.90 | `visual/edittext/edittext_device_transform_negative`, `visual/cache_as_bitmap/edittext_selection`, `visual/simple_shapes/heavy_tesselation`, `visual/filters/any_blur_scales_with_screen` |
| `row_banded` | 5 | 5 | 1 | 0.55 | `from_shumway/acid/acid-text-4`, `from_shumway/acid/acid-textfield`, `visual/simple_shapes/layers`, `avm2/bitmap_pixelsnapping` |
| `global_color_shift` | 1 | 1 | 0 | 1.00 | `avm2/bitmapdata_draw_filters` |
| `localized_region` | 1 | 1 | 0 | 0.55 | `from_shumway/captions` |
| `offset_translation` | 1 | 1 | 0 | 1.00 | `visual/cache_as_bitmap/edittext_hscroll` |
| `extra_element` | 1 | 1 | 0 | 0.60 | `visual/simple_shapes/strokes/scale` |
| **total** | **205** | | **68** | | |

## Cluster x band

```
cluster                    a_epsilon b_tiny c_small d_moderate e_large f_catastrophic no_render size_mismatch
hairline_edge_drift            31     21     10      6      0      0      0      0
blank_render                    0      0      0      4     12     19      0      0
diffuse_mixed                  10      2      4     16      1      0      0      0
same_geometry_wrong_fill        0      2      6     13      4      0      0      0
unrelated_content               0      0      0      1      1      9      0      0
missing_element                 0      1      3      3      0      3      0      0
content_displaced               0      0      2      3      2      1      0      0
halo_penumbra                   0      0      2      2      2      0      0      0
row_banded                      0      1      1      3      0      0      0      0
global_color_shift              0      0      0      0      1      0      0      0
localized_region                0      0      1      0      0      0      0      0
offset_translation              0      0      0      0      1      0      0      0
extra_element                   0      0      0      1      0      0      0      0
```

## Top 40 (of 157 live test x cluster rows, 174 comparisons)

| # | score | cmps | fan(tests) | suite/test | cluster | band | excess |
|---:|---:|---:|---:|---|---|---|---:|
| 1 | 1.88 | 1 | 5 | `visual/filters/color_matrix` | same_geometry_wrong_fill | b_tiny | 237 |
| 2 | 1.57 | 1 | 5 | `visual/drawing_api/drawing_order` | same_geometry_wrong_fill | c_small | 6664 |
| 3 | 1.57 | 1 | 5 | `avm2/bitmapdata_draw_self_via_graphic` | same_geometry_wrong_fill | c_small | 7500 |
| 4 | 1.57 | 1 | 5 | `avm2/bitmapdata_copypixels` | same_geometry_wrong_fill | c_small | 25200 |
| 5 | 1.27 | 1 | 8 | `visual/blend_modes/add` | diffuse_mixed | a_epsilon | 8 |
| 6 | 1.27 | 1 | 8 | `visual/blend_modes/lighten` | diffuse_mixed | a_epsilon | 8 |
| 7 | 1.27 | 1 | 8 | `visual/blend_modes/screen` | diffuse_mixed | a_epsilon | 8 |
| 8 | 1.27 | 1 | 8 | `visual/blend_modes/difference` | diffuse_mixed | a_epsilon | 10 |
| 9 | 1.27 | 1 | 8 | `visual/blend_modes/alpha_no_layer` | diffuse_mixed | a_epsilon | 21 |
| 10 | 1.27 | 1 | 8 | `visual/blend_modes/erase_no_layer` | diffuse_mixed | a_epsilon | 21 |
| 11 | 1.27 | 1 | 8 | `visual/blend_modes/overlay` | diffuse_mixed | a_epsilon | 22 |
| 12 | 1.27 | 1 | 8 | `visual/blend_modes/hardlight` | diffuse_mixed | a_epsilon | 24 |
| 13 | 1.26 | 1 | 5 | `avm2/graphics_draw_path` | same_geometry_wrong_fill | d_moderate | 204 *[trace-ign]* |
| 14 | 1.26 | 1 | 5 | `from_shumway/acid/acid-filter-2` | same_geometry_wrong_fill | d_moderate | 16764 |
| 15 | 1.26 | 1 | 5 | `visual/cache_as_bitmap/nested_rotation` | same_geometry_wrong_fill | d_moderate | 25665 |
| 16 | 1.26 | 1 | 5 | `visual/filters/blur_scales_with_screen` | same_geometry_wrong_fill | d_moderate | 30810 |
| 17 | 1.22 | 1 | 3 | `avm2/blend_shader_luma_lighten` | same_geometry_wrong_fill | c_small | 1237 **[BACKEND]** |
| 18 | 1.22 | 1 | 3 | `avm2/edittext_get_char_index_at_point` | same_geometry_wrong_fill | c_small | 22849 |
| 19 | 1.12 | 2 | 9 | `visual/edittext/edittext_border_transform` | hairline_edge_drift | a_epsilon | 24 |
| 20 | 1.08 | 1 | 2 | `visual/edittext/edittext_device_transform_negative` | halo_penumbra | c_small | 2619 |
| 21 | 1.05 | 6 | 1 | `from_gnash/misc-ming.all/morph_test1` | hairline_edge_drift | b_tiny | 186 |
| 22 | 0.98 | 1 | 4 | `text/br_at_start` | content_displaced | c_small | 3683 |
| 23 | 0.98 | 1 | 3 | `avm2/edittext_always_show_selection` | same_geometry_wrong_fill | d_moderate | 432 |
| 24 | 0.98 | 1 | 3 | `avm2/edittext_get_line_index_at_point` | same_geometry_wrong_fill | d_moderate | 18403 |
| 25 | 0.98 | 1 | 3 | `visual/blend_modes/layer_alpha` | same_geometry_wrong_fill | d_moderate | 66762 |
| 26 | 0.98 | 1 | 3 | `visual/blend_modes/layer_erase` | same_geometry_wrong_fill | d_moderate | 66967 |
| 27 | 0.90 | 1 | 9 | `avm1/edittext_stylesheet` | hairline_edge_drift | a_epsilon | 6 |
| 28 | 0.90 | 1 | 9 | `text/auto_size/height` | hairline_edge_drift | a_epsilon | 12 |
| 29 | 0.90 | 1 | 9 | `text/auto_size/return` | hairline_edge_drift | a_epsilon | 18 |
| 30 | 0.90 | 1 | 9 | `visual/edittext/edittext_device_transform_small_shear` | hairline_edge_drift | a_epsilon | 38 |
| 31 | 0.90 | 1 | 9 | `visual/cache_as_bitmap/edittext_hscroll` | hairline_edge_drift | a_epsilon | 96 |
| 32 | 0.88 | 2 | 5 | `from_shumway/acid/acid-text-6` | hairline_edge_drift | b_tiny | 12 |
| 33 | 0.88 | 1 | 11 | `visual/cache_as_bitmap/cab_mask_filters` | diffuse_mixed | d_moderate | 612 |
| 34 | 0.88 | 1 | 11 | `visual/filters/displacement_map` | diffuse_mixed | d_moderate | 20589 |
| 35 | 0.88 | 1 | 11 | `visual/filters/glow_without_composite_source` | diffuse_mixed | d_moderate | 24919 |
| 36 | 0.88 | 1 | 11 | `visual/filters/glow` | diffuse_mixed | d_moderate | 24992 |
| 37 | 0.88 | 1 | 11 | `visual/filters/drop_shadow` | diffuse_mixed | d_moderate | 46032 |
| 38 | 0.88 | 1 | 11 | `visual/filters/bevel_inner` | diffuse_mixed | d_moderate | 48116 |
| 39 | 0.88 | 1 | 11 | `visual/filters/drop_shadow_angles` | diffuse_mixed | d_moderate | 55899 |
| 40 | 0.88 | 1 | 11 | `visual/filters/bevel_full` | diffuse_mixed | d_moderate | 66764 |

## Top groups (cluster x family, live comparisons only)

| cmps | near-pass | cluster x family |
|---:|---:|---|
| 25 | 0 | `blank_render` x Stage3D / AGAL / shaders **[BACKEND]** |
| 8 | 8 | `diffuse_mixed` x Blend modes |
| 11 | 0 | `diffuse_mixed` x Filters (blur/glow/drop-shadow/…) |
| 11 | 9 | `hairline_edge_drift` x Text: EditText / layout / HTML |
| 5 | 3 | `same_geometry_wrong_fill` x BitmapData / drawing API |
| 3 | 1 | `same_geometry_wrong_fill` x Filters (blur/glow/drop-shadow/…) |
| 5 | 5 | `hairline_edge_drift` x Masks / clipping |
| 6 | 6 | `hairline_edge_drift` x Shumway acid render tests |
| 6 | 6 | `hairline_edge_drift` x Morph shapes / tweens |
| 5 | 5 | `hairline_edge_drift` x Blend modes |
| 3 | 1 | `same_geometry_wrong_fill` x Text: EditText / layout / HTML |
| 5 | 5 | `hairline_edge_drift` x BitmapData / drawing API |
| 5 | 5 | `hairline_edge_drift` x Gradients |
| 4 | 1 | `content_displaced` x Text: EditText / layout / HTML |
| 3 | 0 | `same_geometry_wrong_fill` x Blend modes |

## Dispositioned failing comparisons (8) — excluded from the board

| comparison | cluster | disposition |
|---|---|---|
| `avm1/netstream_play_flv [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `avm1/netstream_play_flv` — Sorenson Spark pixel parity (44 outliers, max diff 3)  [image-axis SCOPE: avm1/netstream_play_flv output — verify per comparison] |
| `avm1/netstream_play_flv_screen [output]` | blank_render | RUFFLE_VS_FLASH (avm1): Video Display Object Render Bounds: `netstream_play_flv_screen` Asset Stamp |
| `avm2/bitmapdata_applyfilter_blur [output]` | same_geometry_wrong_fill | ACCEPTED_DIFFS (avm1): `avm2/bitmapdata_applyfilter_blur` — residual is the default-font text, not the blur (30 844 outlier channels, mean 1.21)  [image-axis SCOPE: avm2/bitmapdata_applyfilter_blur output — verify per comparison] |
| `from_shumway/avm1/text-bind [output]` | content_displaced | ACCEPTED_DIFFS (avm1): `from_shumway/avm1/text-bind` — device-font file mismatch: text ~14px too low (~1900 outlier pixels, max diff 158) |
| `visual/simple_shapes/masks [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/simple_shapes/masks` + `visual/simple_shapes/masks_equal_clipdepth` — 1-sample rasteriser tie (1686 outlier channels each)  [image-axis SCOPE: both tests, the single `output` comparison of each — verify per comparison] |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/simple_shapes/masks` + `visual/simple_shapes/masks_equal_clipdepth` — 1-sample rasteriser tie (1686 outlier channels each)  [image-axis SCOPE: both tests, the single `output` comparison of each — verify per comparison] |
| `visual/video/colorconversion/h263 [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/video/colorconversion/h263` — Spark IDCT precision (10 808 outlier channels, max 2)  [image-axis SCOPE: visual/video/colorconversion/h263 output — verify per comparison] |
| `visual/video/deblocking [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/video/deblocking` — Spark IDCT precision, one Cb level on one chroma row (104 outlier channels, max 4)  [image-axis SCOPE: visual/video/deblocking output — verify per comparison] |

## Trace-axis flags (5) — kept on the board

A suite-local `ignored_tests.txt` entry (or a trace-axis ACCEPTED_DIFFS entry) says nothing about the pixels: image comparisons never gate trace pass/fail. Marked `[trace-ign]` in the board above.

| suite | comparisons |
|---|---:|
| `avm2` | 5 |

## Dispositioned but not failing (2)

The entry is stale on the image axis — it passes, or it has no `[image_comparisons]` block at all. Worth a one-line note in its doc.

- `avm1/display_object_properties` — {'pass': 1} — ACCEPTED_DIFFS (avm1): `display_object_properties` — MSAA edge/stroke antialiasing (~192 image px) — **STALE: now PASSES**
- `from_gnash/misc-ming.all/loop/simple_loop_test` — {'pass': 7} — ACCEPTED_DIFFS (from_gnash): `simple_loop_test` (misc-ming.all/loop) — hairline-stroke pixel-snapping (121–724 image px/frame) — **FRAMES 1–2 ONLY** — **STALE: all 7 fram  [image-axis SCOPE: frames 1-2 only — verify per comparison]

## Ruffle `known_failure` (23)

Ruffle is not the oracle on these; matching its expected PNG is not a goal.

- `avm2/bitmapdata_applyfilter_destpoint_edges [output]` — same_geometry_wrong_fill
- `avm2/bitmapdata_draw_filters [output]` — global_color_shift
- `avm2/graphics_draw_triangles [output]` — diffuse_mixed
- `from_gnash/misc-ming.all/BeginBitmapFill [output]` — hairline_edge_drift
- `from_gnash/misc-ming.all/place_object_test [output]` — content_displaced
- `from_gnash/misc-ming.all/shape_test [output]` — diffuse_mixed
- `from_shumway/MaskTest-2 [output]` — missing_element
- `from_shumway/acid/acid-bitmap-draw_quality_low [output]` — blank_render
- `from_shumway/acid/acid-mask [output.01]` — hairline_edge_drift
- `from_shumway/acid/acid-mask [output.05]` — hairline_edge_drift
- `from_shumway/acid/acid-mask [output.10]` — hairline_edge_drift
- `from_shumway/acid/acid-shapes-testing [output]` — diffuse_mixed
- `from_shumway/acid/acid-stroke-0 [output]` — diffuse_mixed
- `from_shumway/acid/acid-text-4 [output]` — row_banded
- `from_shumway/acid/acid-text-5 [output]` — diffuse_mixed
- `from_shumway/acid/acid-textfield [output]` — row_banded
- `from_shumway/captions [output]` — localized_region
- `from_shumway/flash_text_TextField [output]` — missing_element
- `from_shumway/gradientTransform [output]` — hairline_edge_drift
- `from_shumway/hardwrap [output]` — missing_element
- `from_shumway/stylesheet [output]` — missing_element
- `visual/blend_modes/shader_as_mask [output]` — same_geometry_wrong_fill
- `visual/simple_shapes/strokes/scale [output]` — extra_element
