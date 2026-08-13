# Image triage board

`scripts/image_triage.py --stem graphics` over 256 failing comparisons from the image run at `bf585e4486b64a263abbd336a51f3baf3cd00a03` (2026-08-12T23:11:23.031032+00:00).

Ranked by **mechanism** first. Near-pass ranking alone aims at `hairline_edge_drift`, which is mostly the lavapipe-vs-Flash antialiasing gap — the least fixable cluster in the corpus.

## Clusters

| cluster | cmps | tests | near-pass | prior | example tests |
|---|---:|---:|---:|---:|---|
| `hairline_edge_drift` | 67 | 57 | 47 | 0.25 | `avm1/edittext_stylesheet`, `text/auto_size/height`, `text/auto_size/return`, `visual/cache_as_bitmap/edittext_hscroll` |
| `blank_render` | 45 | 45 | 0 | 0.30 | `avm2/stage3d_bitmap`, `avm2/stage3d_blend`, `avm2/stage3d_multistage_triangle`, `avm2/stage3d_program_constants_bytearray_be` |
| `same_geometry_wrong_fill` | 33 | 33 | 4 | 0.80 | `from_shumway/acid/acid-blend-2`, `visual/filters/color_matrix`, `avm2/bitmapdata_copypixels`, `avm2/bitmapdata_draw_self_via_graphic` |
| `diffuse_mixed` | 31 | 31 | 11 | 0.40 | `visual/blend_modes/add`, `visual/blend_modes/alpha_no_layer`, `visual/blend_modes/difference`, `visual/blend_modes/erase_no_layer` |
| `unrelated_content` | 14 | 6 | 0 | 0.15 | `visual/video/h264`, `avm2/bitmapdata_draw_masks`, `visual/cache_as_bitmap/cab_mask_triangle`, `from_shumway/timeline/timeline_loop` |
| `missing_element` | 13 | 13 | 1 | 0.60 | `from_shumway/flash_text_TextField`, `from_shumway/hardwrap`, `from_shumway/stylesheet`, `visual/edittext/edittext_border_basic` |
| `halo_penumbra` | 13 | 13 | 0 | 0.90 | `visual/edittext/edittext_device_transform_negative`, `visual/edittext/edittext_background_basic`, `visual/edittext/edittext_background_basic_scale2`, `visual/edittext/edittext_border_basic_scale2` |
| `content_displaced` | 13 | 12 | 0 | 0.50 | `from_shumway/avm1/text-bind`, `visual/edittext/edittext_negative_bounds`, `text/style_changes_in_html`, `visual/cache_as_bitmap/edittext_scroll` |
| `extra_element` | 7 | 7 | 0 | 0.60 | `visual/cache_as_bitmap/cab_mask_filters`, `visual/filters/blur_fractional`, `visual/filters/blur_quality`, `visual/cache_as_bitmap/cab_mask_alpha` |
| `row_banded` | 5 | 5 | 1 | 0.55 | `from_shumway/acid/acid-text-4`, `from_shumway/acid/acid-textfield`, `visual/simple_shapes/layers`, `avm2/bitmap_pixelsnapping` |
| `no_render` | 5 | 3 | 0 | 0.00 | `from_shumway/acid/acid`, `from_shumway/acid/acid-large`, `from_shumway/acid/acid-video` |
| `whole_frame_wrong` | 3 | 3 | 0 | 0.35 | `avm2/bitmapdata_applyfilter_blur`, `visual/gradient_nonsequential_ratios`, `visual/blend_modes/shader_as_mask` |
| `offset_translation` | 3 | 3 | 0 | 1.00 | `visual/cache_as_bitmap/text`, `text/br_at_start`, `visual/cache_as_bitmap/edittext_hscroll` |
| `localized_region` | 2 | 2 | 0 | 0.55 | `avm2/graphics_bad_direct_commands`, `from_shumway/captions` |
| `global_color_shift` | 1 | 1 | 0 | 1.00 | `avm2/bitmapdata_draw_filters` |
| `png_unavailable` | 1 | 1 | 0 | 0.00 | `visual/define_bits_lossless2_rgb15` |
| **total** | **256** | | **64** | | |

## Cluster x band

```
cluster                    a_epsilon b_tiny c_small d_moderate e_large f_catastrophic no_render size_mismatch
hairline_edge_drift            29     18     13      7      0      0      0      0
blank_render                    0      0      0      7     18     20      0      0
same_geometry_wrong_fill        1      3     11     14      4      0      0      0
diffuse_mixed                  10      1      4     13      3      0      0      0
unrelated_content               0      0      0      2      3      9      0      0
missing_element                 0      1      4      5      2      1      0      0
halo_penumbra                   0      0      2      8      3      0      0      0
content_displaced               0      0      2      6      3      2      0      0
extra_element                   0      0      0      2      5      0      0      0
row_banded                      0      1      1      3      0      0      0      0
no_render                       0      0      0      0      0      0      5      0
whole_frame_wrong               0      0      0      0      2      1      0      0
offset_translation              0      0      1      1      1      0      0      0
localized_region                0      0      2      0      0      0      0      0
global_color_shift              0      0      0      0      1      0      0      0
png_unavailable                 0      0      0      0      0      1      0      0
```

## Top 25 (of 202 live test x cluster rows, 219 comparisons)

| # | score | cmps | fan(tests) | suite/test | cluster | band | excess |
|---:|---:|---:|---:|---|---|---|---:|
| 1 | 2.07 | 1 | 5 | `from_shumway/acid/acid-blend-2` | same_geometry_wrong_fill | a_epsilon | 1 |
| 2 | 2.05 | 1 | 7 | `visual/edittext/edittext_device_transform_negative` | halo_penumbra | c_small | 2619 |
| 3 | 1.88 | 1 | 5 | `visual/filters/color_matrix` | same_geometry_wrong_fill | b_tiny | 237 |
| 4 | 1.65 | 1 | 7 | `visual/edittext/edittext_background_basic` | halo_penumbra | d_moderate | 1902 |
| 5 | 1.65 | 1 | 7 | `visual/edittext/edittext_device_transform_basic` | halo_penumbra | d_moderate | 2386 |
| 6 | 1.65 | 1 | 7 | `visual/edittext/edittext_border_basic_scale2` | halo_penumbra | d_moderate | 6072 |
| 7 | 1.65 | 1 | 7 | `visual/edittext/edittext_background_basic_scale2` | halo_penumbra | d_moderate | 7741 |
| 8 | 1.57 | 1 | 5 | `visual/drawing_api/drawing_order` | same_geometry_wrong_fill | c_small | 6664 |
| 9 | 1.57 | 1 | 5 | `avm2/bitmapdata_draw_self_via_graphic` | same_geometry_wrong_fill | c_small | 7500 |
| 10 | 1.57 | 1 | 5 | `avm2/bitmapdata_copypixels` | same_geometry_wrong_fill | c_small | 25200 |
| 11 | 1.52 | 1 | 3 | `visual/cache_as_bitmap/text` | offset_translation | c_small | 7410 |
| 12 | 1.46 | 1 | 3 | `from_gnash/misc-ming.all/GradientFillTest` | same_geometry_wrong_fill | b_tiny | 858 |
| 13 | 1.32 | 1 | 7 | `visual/cache_as_bitmap/edittext_selection` | halo_penumbra | e_large | 6775 |
| 14 | 1.32 | 1 | 7 | `avm2/edittext_tag_indent` | halo_penumbra | e_large | 7884 *[trace-ign]* |
| 15 | 1.27 | 1 | 8 | `visual/blend_modes/add` | diffuse_mixed | a_epsilon | 20 |
| 16 | 1.27 | 1 | 8 | `visual/blend_modes/lighten` | diffuse_mixed | a_epsilon | 20 |
| 17 | 1.27 | 1 | 8 | `visual/blend_modes/screen` | diffuse_mixed | a_epsilon | 20 |
| 18 | 1.27 | 1 | 8 | `visual/blend_modes/difference` | diffuse_mixed | a_epsilon | 21 |
| 19 | 1.27 | 1 | 8 | `visual/blend_modes/alpha_no_layer` | diffuse_mixed | a_epsilon | 50 |
| 20 | 1.27 | 1 | 8 | `visual/blend_modes/erase_no_layer` | diffuse_mixed | a_epsilon | 50 |
| 21 | 1.27 | 1 | 8 | `visual/blend_modes/hardlight` | diffuse_mixed | a_epsilon | 54 |
| 22 | 1.27 | 1 | 8 | `visual/blend_modes/overlay` | diffuse_mixed | a_epsilon | 54 |
| 23 | 1.26 | 1 | 5 | `avm2/bitmapdata_draw_alpha_erase` | same_geometry_wrong_fill | d_moderate | 15000 *[trace-ign]* |
| 24 | 1.26 | 1 | 5 | `from_shumway/acid/acid-filter-2` | same_geometry_wrong_fill | d_moderate | 16759 |
| 25 | 1.26 | 1 | 5 | `avm2/bitmapdata_filter_sourcerect` | same_geometry_wrong_fill | d_moderate | 18552 |

## Top groups (cluster x family, live comparisons only)

| cmps | near-pass | cluster x family |
|---:|---:|---|
| 25 | 0 | `blank_render` x Stage3D / AGAL / shaders **[BACKEND]** |
| 7 | 1 | `halo_penumbra` x Text: EditText / layout / HTML |
| 8 | 8 | `diffuse_mixed` x Blend modes |
| 11 | 9 | `hairline_edge_drift` x Text: EditText / layout / HTML |
| 9 | 0 | `diffuse_mixed` x Filters (blur/glow/drop-shadow/…) |
| 5 | 3 | `same_geometry_wrong_fill` x BitmapData / drawing API |
| 5 | 1 | `same_geometry_wrong_fill` x Blend modes |
| 5 | 1 | `same_geometry_wrong_fill` x Filters (blur/glow/drop-shadow/…) |
| 7 | 7 | `hairline_edge_drift` x Morph shapes / tweens |
| 6 | 6 | `hairline_edge_drift` x Shumway acid render tests |
| 3 | 3 | `same_geometry_wrong_fill` x Gradients |
| 6 | 5 | `hairline_edge_drift` x BitmapData / drawing API |
| 3 | 1 | `offset_translation` x Text: EditText / layout / HTML |
| 3 | 1 | `same_geometry_wrong_fill` x Text: EditText / layout / HTML |
| 4 | 1 | `content_displaced` x Text: EditText / layout / HTML |

## Dispositioned failing comparisons (8) — excluded from the board

| comparison | cluster | disposition |
|---|---|---|
| `avm1/netstream_play_flv [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `netstream_play_flv` — Sorenson Spark pixel parity (44 outliers, max diff 3) |
| `avm1/netstream_play_flv_screen [output]` | blank_render | RUFFLE_VS_FLASH (avm1): Video Display Object Render Bounds: `netstream_play_flv_screen` Asset Stamp |
| `avm2/netstream_play_flv [output]` | blank_render | ACCEPTED_DIFFS (avm1): `netstream_play_flv` — Sorenson Spark pixel parity (44 outliers, max diff 3) (matched by basename — VERIFY) |
| `from_shumway/avm1/text-bind [output]` | content_displaced | ACCEPTED_DIFFS (avm1): `from_shumway/avm1/text-bind` — device-font file mismatch: text ~14px too low (~1900 outlier pixels, max diff 158) |
| `visual/simple_shapes/masks [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/simple_shapes/masks` + `visual/simple_shapes/masks_equal_clipdepth` — 1-sample rasteriser tie (1686 outlier channels each)  [image-axis SCOPE: both tests, the single `output` comparison of each — verify per comparison] |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/simple_shapes/masks` + `visual/simple_shapes/masks_equal_clipdepth` — 1-sample rasteriser tie (1686 outlier channels each)  [image-axis SCOPE: both tests, the single `output` comparison of each — verify per comparison] |
| `visual/video/colorconversion/h263 [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/video/colorconversion/h263` — Spark IDCT precision (10 808 outlier channels, max 2)  [image-axis SCOPE: visual/video/colorconversion/h263 output — verify per comparison] |
| `visual/video/deblocking [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `visual/video/deblocking` — Spark IDCT precision, one Cb level on one chroma row (104 outlier channels, max 4)  [image-axis SCOPE: visual/video/deblocking output — verify per comparison] |

## Trace-axis flags (8) — kept on the board

A suite-local `ignored_tests.txt` entry (or a trace-axis ACCEPTED_DIFFS entry) says nothing about the pixels: image comparisons never gate trace pass/fail. Marked `[trace-ign]` in the board above.

| suite | comparisons |
|---|---:|
| `avm2` | 8 |

## Dispositioned but not failing (2)

The entry is stale on the image axis — it passes, or it has no `[image_comparisons]` block at all. Worth a one-line note in its doc.

- `avm1/display_object_properties` — {'pass': 1} — ACCEPTED_DIFFS (avm1): `display_object_properties` — MSAA edge/stroke antialiasing (~192 image px) — **STALE: now PASSES**
- `from_gnash/misc-ming.all/loop/simple_loop_test` — {'pass': 7} — ACCEPTED_DIFFS (from_gnash): `simple_loop_test` (misc-ming.all/loop) — hairline-stroke pixel-snapping (121–724 image px/frame) — **FRAMES 1–2 ONLY** — **STALE: all 7 fram  [image-axis SCOPE: frames 1-2 only — verify per comparison]

## Ruffle `known_failure` (23)

Ruffle is not the oracle on these; matching its expected PNG is not a goal.

- `avm2/bitmapdata_applyfilter_destpoint_edges [output]` — diffuse_mixed
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
