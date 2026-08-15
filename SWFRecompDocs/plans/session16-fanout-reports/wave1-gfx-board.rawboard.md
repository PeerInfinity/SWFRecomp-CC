# Image triage board

`scripts/image_triage.py --stem graphics` over 242 failing comparisons from the image run at `3db858cbc157a97402c8e9a956b123871fc73405` (2026-08-13T22:38:39.796481+00:00).

Ranked by **mechanism** first. Near-pass ranking alone aims at `hairline_edge_drift`, which is mostly the lavapipe-vs-Flash antialiasing gap — the least fixable cluster in the corpus.

## Clusters

| cluster | cmps | tests | near-pass | prior | example tests |
|---|---:|---:|---:|---:|---|
| `hairline_edge_drift` | 65 | 55 | 45 | 0.25 | `avm1/edittext_stylesheet`, `text/auto_size/height`, `text/auto_size/return`, `visual/cache_as_bitmap/edittext_hscroll` |
| `blank_render` | 45 | 45 | 0 | 0.30 | `avm2/stage3d_bitmap`, `avm2/stage3d_blend`, `avm2/stage3d_multistage_triangle`, `avm2/stage3d_program_constants_bytearray_be` |
| `same_geometry_wrong_fill` | 31 | 31 | 3 | 0.80 | `visual/filters/color_matrix`, `avm2/bitmapdata_copypixels`, `avm2/bitmapdata_draw_self_via_graphic`, `visual/drawing_api/drawing_order` |
| `diffuse_mixed` | 29 | 29 | 10 | 0.40 | `visual/blend_modes/add`, `visual/blend_modes/alpha_no_layer`, `visual/blend_modes/difference`, `visual/blend_modes/erase_no_layer` |
| `unrelated_content` | 14 | 6 | 0 | 0.15 | `visual/video/h264`, `avm2/bitmapdata_draw_masks`, `visual/cache_as_bitmap/cab_mask_triangle`, `from_shumway/timeline/timeline_loop` |
| `halo_penumbra` | 13 | 13 | 0 | 0.90 | `visual/edittext/edittext_device_transform_negative`, `visual/edittext/edittext_background_basic`, `visual/edittext/edittext_background_basic_scale2`, `visual/edittext/edittext_border_basic_scale2` |
| `missing_element` | 12 | 12 | 1 | 0.60 | `from_shumway/flash_text_TextField`, `from_shumway/hardwrap`, `from_shumway/stylesheet`, `visual/edittext/edittext_border_basic` |
| `content_displaced` | 12 | 11 | 0 | 0.50 | `from_shumway/avm1/text-bind`, `visual/edittext/edittext_negative_bounds`, `text/style_changes_in_html`, `visual/cache_as_bitmap/edittext_scroll` |
| `row_banded` | 6 | 6 | 1 | 0.55 | `from_shumway/acid/acid-text-4`, `from_shumway/acid/acid-textfield`, `visual/edittext/edittext_border_filters`, `visual/filters/blur_pass_scaling` |
| `extra_element` | 5 | 5 | 0 | 0.60 | `visual/cache_as_bitmap/cab_mask_alpha`, `visual/cache_as_bitmap/cab_mask_transform`, `import_assets/avm1_imports_avm1`, `visual/simple_shapes/strokes/scale` |
| `offset_translation` | 3 | 3 | 0 | 1.00 | `visual/cache_as_bitmap/text`, `text/br_at_start`, `visual/cache_as_bitmap/edittext_hscroll` |
| `global_color_shift` | 2 | 2 | 0 | 1.00 | `visual/filters/blur_quality`, `avm2/bitmapdata_draw_filters` |
| `localized_region` | 2 | 2 | 0 | 0.55 | `avm2/graphics_bad_direct_commands`, `from_shumway/captions` |
| `whole_frame_wrong` | 2 | 2 | 0 | 0.35 | `visual/gradient_nonsequential_ratios`, `visual/blend_modes/shader_as_mask` |
| `no_render` | 1 | 1 | 0 | 0.00 | `from_shumway/acid/acid-large` |
| **total** | **242** | | **60** | | |

## Cluster x band

```
cluster                    a_epsilon b_tiny c_small d_moderate e_large f_catastrophic no_render size_mismatch
hairline_edge_drift            27     18     13      7      0      0      0      0
blank_render                    0      0      0      7     18     20      0      0
same_geometry_wrong_fill        0      3     10     13      5      0      0      0
diffuse_mixed                   9      1      4     13      2      0      0      0
unrelated_content               0      0      0      2      3      9      0      0
halo_penumbra                   0      0      2      8      3      0      0      0
missing_element                 0      1      4      5      1      1      0      0
content_displaced               0      0      2      5      3      2      0      0
row_banded                      0      1      1      4      0      0      0      0
extra_element                   0      0      0      2      3      0      0      0
offset_translation              0      0      1      1      1      0      0      0
global_color_shift              0      0      0      1      1      0      0      0
localized_region                0      0      2      0      0      0      0      0
whole_frame_wrong               0      0      0      0      1      1      0      0
no_render                       0      0      0      0      0      0      1      0
```

## Top 25 (of 194 live test x cluster rows, 211 comparisons)

| # | score | cmps | fan(tests) | suite/test | cluster | band | excess |
|---:|---:|---:|---:|---|---|---|---:|
| 1 | 2.05 | 1 | 7 | `visual/edittext/edittext_device_transform_negative` | halo_penumbra | c_small | 2619 |
| 2 | 2.04 | 1 | 6 | `visual/filters/color_matrix` | same_geometry_wrong_fill | b_tiny | 237 |
| 3 | 1.65 | 1 | 7 | `visual/edittext/edittext_background_basic` | halo_penumbra | d_moderate | 1902 |
| 4 | 1.65 | 1 | 7 | `visual/edittext/edittext_device_transform_basic` | halo_penumbra | d_moderate | 2386 |
| 5 | 1.65 | 1 | 7 | `visual/edittext/edittext_border_basic_scale2` | halo_penumbra | d_moderate | 6072 |
| 6 | 1.65 | 1 | 7 | `visual/edittext/edittext_background_basic_scale2` | halo_penumbra | d_moderate | 7741 |
| 7 | 1.57 | 1 | 5 | `visual/drawing_api/drawing_order` | same_geometry_wrong_fill | c_small | 6664 |
| 8 | 1.57 | 1 | 5 | `avm2/bitmapdata_draw_self_via_graphic` | same_geometry_wrong_fill | c_small | 7500 |
| 9 | 1.57 | 1 | 5 | `avm2/bitmapdata_copypixels` | same_geometry_wrong_fill | c_small | 25200 |
| 10 | 1.52 | 1 | 3 | `visual/cache_as_bitmap/text` | offset_translation | c_small | 7410 |
| 11 | 1.46 | 1 | 3 | `from_gnash/misc-ming.all/GradientFillTest` | same_geometry_wrong_fill | b_tiny | 858 |
| 12 | 1.37 | 1 | 6 | `from_shumway/acid/acid-filter-2` | same_geometry_wrong_fill | d_moderate | 16759 |
| 13 | 1.37 | 1 | 6 | `avm2/bitmapdata_applyfilter_blur` | same_geometry_wrong_fill | d_moderate | 30844 |
| 14 | 1.37 | 1 | 6 | `visual/filters/displacement_map` | same_geometry_wrong_fill | d_moderate | 123279 |
| 15 | 1.32 | 1 | 7 | `visual/cache_as_bitmap/edittext_selection` | halo_penumbra | e_large | 6775 |
| 16 | 1.32 | 1 | 7 | `avm2/edittext_tag_indent` | halo_penumbra | e_large | 7884 *[trace-ign]* |
| 17 | 1.27 | 1 | 8 | `visual/blend_modes/add` | diffuse_mixed | a_epsilon | 20 |
| 18 | 1.27 | 1 | 8 | `visual/blend_modes/lighten` | diffuse_mixed | a_epsilon | 20 |
| 19 | 1.27 | 1 | 8 | `visual/blend_modes/screen` | diffuse_mixed | a_epsilon | 20 |
| 20 | 1.27 | 1 | 8 | `visual/blend_modes/difference` | diffuse_mixed | a_epsilon | 21 |
| 21 | 1.27 | 1 | 8 | `visual/blend_modes/alpha_no_layer` | diffuse_mixed | a_epsilon | 50 |
| 22 | 1.27 | 1 | 8 | `visual/blend_modes/erase_no_layer` | diffuse_mixed | a_epsilon | 50 |
| 23 | 1.27 | 1 | 8 | `visual/blend_modes/hardlight` | diffuse_mixed | a_epsilon | 54 |
| 24 | 1.27 | 1 | 8 | `visual/blend_modes/overlay` | diffuse_mixed | a_epsilon | 54 |
| 25 | 1.26 | 1 | 5 | `avm2/bitmapdata_draw_alpha_erase` | same_geometry_wrong_fill | d_moderate | 15000 *[trace-ign]* |

## Top groups (cluster x family, live comparisons only)

| cmps | near-pass | cluster x family |
|---:|---:|---|
| 25 | 0 | `blank_render` x Stage3D / AGAL / shaders **[BACKEND]** |
| 7 | 1 | `halo_penumbra` x Text: EditText / layout / HTML |
| 8 | 8 | `diffuse_mixed` x Blend modes |
| 11 | 9 | `hairline_edge_drift` x Text: EditText / layout / HTML |
| 9 | 0 | `diffuse_mixed` x Filters (blur/glow/drop-shadow/…) |
| 5 | 1 | `same_geometry_wrong_fill` x Filters (blur/glow/drop-shadow/…) |
| 5 | 3 | `same_geometry_wrong_fill` x BitmapData / drawing API |
| 7 | 7 | `hairline_edge_drift` x Morph shapes / tweens |
| 6 | 6 | `hairline_edge_drift` x Shumway acid render tests |
| 3 | 3 | `same_geometry_wrong_fill` x Gradients |
| 6 | 5 | `hairline_edge_drift` x BitmapData / drawing API |
| 3 | 1 | `offset_translation` x Text: EditText / layout / HTML |
| 4 | 4 | `hairline_edge_drift` x Masks / clipping |
| 3 | 1 | `same_geometry_wrong_fill` x Text: EditText / layout / HTML |
| 4 | 1 | `content_displaced` x Text: EditText / layout / HTML |

## Dispositioned failing comparisons (7) — excluded from the board

| comparison | cluster | disposition |
|---|---|---|
| `avm1/netstream_play_flv [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `avm1/netstream_play_flv` — Sorenson Spark pixel parity (44 outliers, max diff 3)  [image-axis SCOPE: avm1/netstream_play_flv output — verify per comparison] |
| `avm1/netstream_play_flv_screen [output]` | blank_render | RUFFLE_VS_FLASH (avm1): Video Display Object Render Bounds: `netstream_play_flv_screen` Asset Stamp |
| `from_shumway/avm1/text-bind [output]` | content_displaced | ACCEPTED_DIFFS (avm1): `from_shumway/avm1/text-bind` — device-font file mismatch: text ~14px too low (~1900 outlier pixels, max diff 158) |
| `visual/simple_shapes/masks [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/simple_shapes/masks` + `visual/simple_shapes/masks_equal_clipdepth` — 1-sample rasteriser tie (1686 outlier channels each)  [image-axis SCOPE: both tests, the single `output` comparison of each — verify per comparison] |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/simple_shapes/masks` + `visual/simple_shapes/masks_equal_clipdepth` — 1-sample rasteriser tie (1686 outlier channels each)  [image-axis SCOPE: both tests, the single `output` comparison of each — verify per comparison] |
| `visual/video/colorconversion/h263 [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/video/colorconversion/h263` — Spark IDCT precision (10 808 outlier channels, max 2)  [image-axis SCOPE: visual/video/colorconversion/h263 output — verify per comparison] |
| `visual/video/deblocking [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/video/deblocking` — Spark IDCT precision, one Cb level on one chroma row (104 outlier channels, max 4)  [image-axis SCOPE: visual/video/deblocking output — verify per comparison] |

## Trace-axis flags (9) — kept on the board

A suite-local `ignored_tests.txt` entry (or a trace-axis ACCEPTED_DIFFS entry) says nothing about the pixels: image comparisons never gate trace pass/fail. Marked `[trace-ign]` in the board above.

| suite | comparisons |
|---|---:|
| `avm2` | 9 |

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
- `from_shumway/gradientTransform [output]` — blank_render
- `from_shumway/hardwrap [output]` — missing_element
- `from_shumway/stylesheet [output]` — missing_element
- `visual/blend_modes/shader_as_mask [output]` — whole_frame_wrong
- `visual/simple_shapes/strokes/scale [output]` — extra_element
