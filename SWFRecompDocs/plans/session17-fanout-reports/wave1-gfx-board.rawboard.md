<!-- Session 17 wave-1 pixel board — raw `scripts/image_triage.py` output.
     Command: python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 3
     Inputs:  ruffle-image-results @ bfecef0ad (2026-08-15T10:09:54Z, 228 *.actual.png)
              per-suite image_results_graphics.json, all 12 stems run_id=31877239992 @ aeebf9ede
     52.8 s. Copied verbatim; the analysis lives in wave1-gfx-board.md. -->

# Image triage board

`scripts/image_triage.py --stem graphics` over 228 failing comparisons from the image run at `aeebf9ede383da45c61df6c9e10f29c8425fee8b` (2026-08-15T10:09:52.696065+00:00).

Ranked by **mechanism** first. Near-pass ranking alone aims at `hairline_edge_drift`, which is mostly the lavapipe-vs-Flash antialiasing gap — the least fixable cluster in the corpus.

## Clusters

| cluster | cmps | tests | near-pass | prior | example tests |
|---|---:|---:|---:|---:|---|
| `hairline_edge_drift` | 68 | 58 | 51 | 0.25 | `avm1/edittext_stylesheet`, `text/auto_size/height`, `text/auto_size/return`, `visual/cache_as_bitmap/edittext_hscroll` |
| `blank_render` | 38 | 38 | 0 | 0.30 | `avm2/stage3d_bitmap`, `avm2/stage3d_blend`, `avm2/stage3d_multistage_triangle`, `avm2/stage3d_program_constants_bytearray_be` |
| `diffuse_mixed` | 31 | 31 | 11 | 0.40 | `visual/blend_modes/add`, `visual/blend_modes/alpha_no_layer`, `visual/blend_modes/difference`, `visual/blend_modes/erase_no_layer` |
| `same_geometry_wrong_fill` | 26 | 26 | 2 | 0.80 | `visual/filters/color_matrix`, `avm2/bitmapdata_copypixels`, `avm2/bitmapdata_draw_self_via_graphic`, `visual/drawing_api/drawing_order` |
| `unrelated_content` | 14 | 6 | 0 | 0.15 | `visual/video/h264`, `avm2/bitmapdata_draw_masks`, `visual/cache_as_bitmap/cab_mask_triangle`, `from_shumway/timeline/timeline_loop` |
| `content_displaced` | 12 | 11 | 0 | 0.50 | `from_shumway/avm1/text-bind`, `visual/edittext/edittext_negative_bounds`, `text/style_changes_in_html`, `visual/cache_as_bitmap/edittext_scroll` |
| `missing_element` | 11 | 11 | 1 | 0.60 | `from_shumway/flash_text_TextField`, `from_shumway/hardwrap`, `from_shumway/stylesheet`, `visual/edittext/edittext_border_basic` |
| `halo_penumbra` | 11 | 11 | 0 | 0.90 | `visual/edittext/edittext_device_transform_negative`, `visual/edittext/edittext_background_basic`, `visual/edittext/edittext_background_basic_scale2`, `visual/edittext/edittext_border_basic_scale2` |
| `row_banded` | 5 | 5 | 1 | 0.55 | `from_shumway/acid/acid-text-4`, `from_shumway/acid/acid-textfield`, `visual/simple_shapes/layers`, `avm2/bitmap_pixelsnapping` |
| `extra_element` | 5 | 5 | 0 | 0.60 | `visual/cache_as_bitmap/cab_mask_alpha`, `visual/cache_as_bitmap/cab_mask_transform`, `import_assets/avm1_imports_avm1`, `visual/simple_shapes/strokes/scale` |
| `offset_translation` | 3 | 3 | 0 | 1.00 | `visual/cache_as_bitmap/text`, `text/br_at_start`, `visual/cache_as_bitmap/edittext_hscroll` |
| `localized_region` | 2 | 2 | 0 | 0.55 | `avm2/graphics_bad_direct_commands`, `from_shumway/captions` |
| `global_color_shift` | 1 | 1 | 0 | 1.00 | `avm2/bitmapdata_draw_filters` |
| `whole_frame_wrong` | 1 | 1 | 0 | 0.35 | `visual/blend_modes/shader_as_mask` |
| **total** | **228** | | **66** | | |

## Cluster x band

```
cluster                    a_epsilon b_tiny c_small d_moderate e_large f_catastrophic no_render size_mismatch
hairline_edge_drift            29     22     10      7      0      0      0      0
blank_render                    0      0      0      5     14     19      0      0
diffuse_mixed                  10      1      5     13      2      0      0      0
same_geometry_wrong_fill        0      2      8     13      3      0      0      0
unrelated_content               0      0      0      2      3      9      0      0
content_displaced               0      0      2      6      2      2      0      0
missing_element                 0      1      4      3      1      2      0      0
halo_penumbra                   0      0      2      7      2      0      0      0
row_banded                      0      1      1      3      0      0      0      0
extra_element                   0      0      0      2      3      0      0      0
offset_translation              0      0      1      1      1      0      0      0
localized_region                0      0      2      0      0      0      0      0
global_color_shift              0      0      0      0      1      0      0      0
whole_frame_wrong               0      0      0      0      0      1      0      0
```

## Top 30 (of 180 live test x cluster rows, 197 comparisons)

| # | score | cmps | fan(tests) | suite/test | cluster | band | excess |
|---:|---:|---:|---:|---|---|---|---:|
| 1 | 2.04 | 1 | 6 | `visual/filters/color_matrix` | same_geometry_wrong_fill | b_tiny | 237 |
| 2 | 1.92 | 1 | 6 | `visual/edittext/edittext_device_transform_negative` | halo_penumbra | c_small | 2619 |
| 3 | 1.57 | 1 | 5 | `visual/drawing_api/drawing_order` | same_geometry_wrong_fill | c_small | 6664 |
| 4 | 1.57 | 1 | 5 | `avm2/bitmapdata_draw_self_via_graphic` | same_geometry_wrong_fill | c_small | 7500 |
| 5 | 1.57 | 1 | 5 | `avm2/bitmapdata_copypixels` | same_geometry_wrong_fill | c_small | 25200 |
| 6 | 1.54 | 1 | 6 | `visual/edittext/edittext_background_basic` | halo_penumbra | d_moderate | 1902 |
| 7 | 1.54 | 1 | 6 | `visual/edittext/edittext_device_transform_basic` | halo_penumbra | d_moderate | 2386 |
| 8 | 1.54 | 1 | 6 | `visual/edittext/edittext_border_basic_scale2` | halo_penumbra | d_moderate | 6072 |
| 9 | 1.54 | 1 | 6 | `visual/edittext/edittext_background_basic_scale2` | halo_penumbra | d_moderate | 7741 |
| 10 | 1.52 | 1 | 3 | `visual/cache_as_bitmap/text` | offset_translation | c_small | 7410 |
| 11 | 1.37 | 1 | 6 | `from_shumway/acid/acid-filter-2` | same_geometry_wrong_fill | d_moderate | 16764 |
| 12 | 1.37 | 1 | 6 | `visual/filters/blur_scales_with_screen` | same_geometry_wrong_fill | d_moderate | 30810 |
| 13 | 1.37 | 1 | 6 | `visual/filters/displacement_map` | same_geometry_wrong_fill | d_moderate | 123218 |
| 14 | 1.27 | 1 | 8 | `visual/blend_modes/add` | diffuse_mixed | a_epsilon | 8 |
| 15 | 1.27 | 1 | 8 | `visual/blend_modes/lighten` | diffuse_mixed | a_epsilon | 8 |
| 16 | 1.27 | 1 | 8 | `visual/blend_modes/screen` | diffuse_mixed | a_epsilon | 8 |
| 17 | 1.27 | 1 | 8 | `visual/blend_modes/difference` | diffuse_mixed | a_epsilon | 10 |
| 18 | 1.27 | 1 | 8 | `visual/blend_modes/alpha_no_layer` | diffuse_mixed | a_epsilon | 21 |
| 19 | 1.27 | 1 | 8 | `visual/blend_modes/erase_no_layer` | diffuse_mixed | a_epsilon | 21 |
| 20 | 1.27 | 1 | 8 | `visual/blend_modes/overlay` | diffuse_mixed | a_epsilon | 22 |
| 21 | 1.27 | 1 | 8 | `visual/blend_modes/hardlight` | diffuse_mixed | a_epsilon | 24 |
| 22 | 1.26 | 1 | 5 | `visual/cache_as_bitmap/nested_rotation` | same_geometry_wrong_fill | d_moderate | 25665 |
| 23 | 1.26 | 1 | 5 | `avm2/graphics_bitmaps` | same_geometry_wrong_fill | d_moderate | 39988 |
| 24 | 1.24 | 1 | 6 | `visual/cache_as_bitmap/edittext_selection` | halo_penumbra | e_large | 6775 |
| 25 | 1.22 | 1 | 3 | `text/br_at_start` | offset_translation | d_moderate | 14411 |
| 26 | 1.22 | 1 | 3 | `avm2/edittext_get_char_index_at_point` | same_geometry_wrong_fill | c_small | 22849 |
| 27 | 1.12 | 2 | 9 | `visual/edittext/edittext_border_transform` | hairline_edge_drift | a_epsilon | 24 |
| 28 | 1.05 | 6 | 1 | `from_gnash/misc-ming.all/morph_test1` | hairline_edge_drift | b_tiny | 186 |
| 29 | 0.98 | 1 | 4 | `visual/edittext/edittext_negative_bounds` | content_displaced | c_small | 720 |
| 30 | 0.98 | 1 | 3 | `visual/cache_as_bitmap/edittext_hscroll` | offset_translation | e_large | 960 |

## Top groups (cluster x family, live comparisons only)

| cmps | near-pass | cluster x family |
|---:|---:|---|
| 25 | 0 | `blank_render` x Stage3D / AGAL / shaders **[BACKEND]** |
| 8 | 8 | `diffuse_mixed` x Blend modes |
| 6 | 1 | `halo_penumbra` x Text: EditText / layout / HTML |
| 11 | 9 | `hairline_edge_drift` x Text: EditText / layout / HTML |
| 9 | 0 | `diffuse_mixed` x Filters (blur/glow/drop-shadow/…) |
| 5 | 3 | `same_geometry_wrong_fill` x BitmapData / drawing API |
| 4 | 1 | `same_geometry_wrong_fill` x Filters (blur/glow/drop-shadow/…) |
| 6 | 6 | `hairline_edge_drift` x Shumway acid render tests |
| 6 | 6 | `hairline_edge_drift` x Morph shapes / tweens |
| 6 | 5 | `hairline_edge_drift` x BitmapData / drawing API |
| 3 | 1 | `offset_translation` x Text: EditText / layout / HTML |
| 4 | 4 | `hairline_edge_drift` x Masks / clipping |
| 3 | 1 | `same_geometry_wrong_fill` x Text: EditText / layout / HTML |
| 5 | 5 | `hairline_edge_drift` x Gradients |
| 4 | 1 | `content_displaced` x Text: EditText / layout / HTML |

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

## Trace-axis flags (6) — kept on the board

A suite-local `ignored_tests.txt` entry (or a trace-axis ACCEPTED_DIFFS entry) says nothing about the pixels: image comparisons never gate trace pass/fail. Marked `[trace-ign]` in the board above.

| suite | comparisons |
|---|---:|
| `avm2` | 6 |

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
- `visual/blend_modes/shader_as_mask [output]` — whole_frame_wrong
- `visual/simple_shapes/strokes/scale [output]` — extra_element
