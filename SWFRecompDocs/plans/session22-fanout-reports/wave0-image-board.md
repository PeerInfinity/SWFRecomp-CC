# Image triage board

`scripts/image_triage.py --stem graphics` over 151 failing comparisons from the image run at `02df69d28006ea9571a0a76bdb1d59f35368aa8c` (2026-09-29T03:41:02.361999+00:00).

Ranked by **mechanism** first. Near-pass ranking alone aims at `hairline_edge_drift`, which is mostly the lavapipe-vs-Flash antialiasing gap — the least fixable cluster in the corpus.

## Clusters

| cluster | cmps | tests | near-pass | prior | example tests |
|---|---:|---:|---:|---:|---|
| `hairline_edge_drift` | 60 | 52 | 47 | 0.25 | `from_shumway/MaskTest`, `from_shumway/acid/acid-shapes`, `from_shumway/acid/acid-text-6`, `visual/avm2_button_scroll_rect` |
| `diffuse_mixed` | 22 | 22 | 13 | 0.40 | `visual/blend_modes/add`, `visual/blend_modes/alpha_no_layer`, `visual/blend_modes/difference`, `visual/blend_modes/erase_no_layer` |
| `blank_render` | 12 | 12 | 0 | 0.30 | `avm2/netstream_seek_flv`, `avm2/netstream_play_flv`, `visual/video/h264_multinalu`, `avm1/netstream_play_flv_screen` |
| `unrelated_content` | 12 | 4 | 0 | 0.15 | `visual/video/h264`, `avm2/bitmapdata_draw_masks`, `avm2/away3d_advanced_shallow_water_demo`, `avm2/stage3d_bitmap` |
| `missing_element` | 11 | 11 | 1 | 0.60 | `from_shumway/flash_text_TextField`, `from_shumway/hardwrap`, `from_shumway/stylesheet`, `avm2/stage3d_texture_bytearray_compressed_alpha` |
| `same_geometry_wrong_fill` | 10 | 10 | 0 | 0.80 | `avm2/blend_shader_luma_lighten`, `avm2/pixelbender_effect_glassDisplace_shaderfilter`, `visual/blend_modes/shader_as_mask`, `visual/blend_modes/layer_alpha` |
| `row_banded` | 9 | 9 | 2 | 0.55 | `from_shumway/acid/acid-small`, `from_shumway/acid/acid-text`, `avm2/graphics_gradients`, `from_shumway/acid/acid-text-4` |
| `halo_penumbra` | 6 | 6 | 2 | 0.90 | `visual/filters/displacement_map`, `visual/cache_as_bitmap/avm2_button`, `visual/filters/any_blur_scales_with_screen`, `avm2/geom_transform` |
| `content_displaced` | 4 | 4 | 0 | 0.50 | `from_shumway/avm1/text-bind`, `text/br_at_start`, `text/style_changes_in_html`, `from_gnash/misc-ming.all/place_object_test` |
| `localized_region` | 3 | 3 | 1 | 0.55 | `avm2/displayobject_opaque_background`, `from_shumway/captions`, `avm2/stage3d_texture_bytearray` |
| `global_color_shift` | 1 | 1 | 0 | 1.00 | `avm2/bitmapdata_draw_filters` |
| `extra_element` | 1 | 1 | 0 | 0.60 | `visual/simple_shapes/strokes/scale` |
| **total** | **151** | | **66** | | |

## Cluster x band

```
cluster                    a_epsilon b_tiny c_small d_moderate e_large f_catastrophic no_render size_mismatch
hairline_edge_drift            31     16     10      3      0      0      0      0
diffuse_mixed                   9      4      2      6      1      0      0      0
blank_render                    0      0      1      2      3      6      0      0
unrelated_content               0      0      0      1      2      9      0      0
missing_element                 0      1      3      2      2      3      0      0
same_geometry_wrong_fill        0      0      3      4      3      0      0      0
row_banded                      0      2      3      4      0      0      0      0
halo_penumbra                   1      1      2      1      1      0      0      0
content_displaced               0      0      2      2      0      0      0      0
localized_region                1      0      1      1      0      0      0      0
global_color_shift              0      0      0      0      1      0      0      0
extra_element                   0      0      0      1      0      0      0      0
```

## Top 25 (of 107 live test x cluster rows, 121 comparisons)

| # | score | cmps | fan(tests) | suite/test | cluster | band | excess |
|---:|---:|---:|---:|---|---|---|---:|
| 1 | 1.30 | 1 | 2 | `visual/filters/displacement_map` | halo_penumbra | b_tiny | 1364 |
| 2 | 1.27 | 1 | 8 | `visual/blend_modes/add` | diffuse_mixed | a_epsilon | 5 |
| 3 | 1.27 | 1 | 8 | `visual/blend_modes/lighten` | diffuse_mixed | a_epsilon | 5 |
| 4 | 1.27 | 1 | 8 | `visual/blend_modes/screen` | diffuse_mixed | a_epsilon | 5 |
| 5 | 1.27 | 1 | 8 | `visual/blend_modes/difference` | diffuse_mixed | a_epsilon | 7 |
| 6 | 1.27 | 1 | 8 | `visual/blend_modes/alpha_no_layer` | diffuse_mixed | a_epsilon | 18 |
| 7 | 1.27 | 1 | 8 | `visual/blend_modes/erase_no_layer` | diffuse_mixed | a_epsilon | 18 |
| 8 | 1.27 | 1 | 8 | `visual/blend_modes/overlay` | diffuse_mixed | a_epsilon | 19 |
| 9 | 1.27 | 1 | 8 | `visual/blend_modes/hardlight` | diffuse_mixed | a_epsilon | 21 |
| 10 | 1.16 | 1 | 4 | `from_shumway/acid/acid-small` | row_banded | b_tiny | 657 |
| 11 | 1.16 | 6 | 1 | `from_gnash/misc-ming.all/morph_test1` | hairline_edge_drift | b_tiny | 15 |
| 12 | 0.99 | 2 | 7 | `from_shumway/acid/acid-text-6` | hairline_edge_drift | b_tiny | 12 |
| 13 | 0.98 | 1 | 3 | `avm2/blend_shader_luma_lighten` | same_geometry_wrong_fill | d_moderate | 37023 **[BACKEND]** |
| 14 | 0.97 | 1 | 4 | `from_shumway/acid/acid-text` | row_banded | c_small | 5022 |
| 15 | 0.94 | 1 | 5 | `visual/filters/bevel_inner` | diffuse_mixed | b_tiny | 1000 |
| 16 | 0.94 | 1 | 5 | `visual/filters/bevel_full` | diffuse_mixed | b_tiny | 1140 |
| 17 | 0.94 | 1 | 5 | `visual/filters/bevel_outer` | diffuse_mixed | b_tiny | 1432 |
| 18 | 0.90 | 1 | 1 | `visual/cache_as_bitmap/avm2_button` | halo_penumbra | a_epsilon | 6 |
| 19 | 0.87 | 1 | 2 | `visual/filters/any_blur_scales_with_screen` | halo_penumbra | d_moderate | 4884 |
| 20 | 0.85 | 1 | 4 | `avm2/stage3d_texture_bytearray_compressed_raw_alpha` | missing_element | d_moderate | 55013 **[BACKEND]** |
| 21 | 0.85 | 1 | 4 | `avm2/stage3d_texture_bytearray_compressed_alpha` | missing_element | d_moderate | 58540 **[BACKEND]** |
| 22 | 0.79 | 1 | 2 | `avm2/graphics_gradients` | row_banded | b_tiny | 349 |
| 23 | 0.79 | 1 | 6 | `from_shumway/MaskTest` | hairline_edge_drift | a_epsilon | 1 |
| 24 | 0.79 | 1 | 6 | `visual/avm2_button_scroll_rect` | hairline_edge_drift | a_epsilon | 6 |
| 25 | 0.79 | 1 | 8 | `visual/filters/color_matrix` | hairline_edge_drift | a_epsilon | 6 |

## Top groups (cluster x family, live comparisons only)

| cmps | near-pass | cluster x family |
|---:|---:|---|
| 8 | 8 | `diffuse_mixed` x Blend modes |
| 8 | 8 | `hairline_edge_drift` x Shumway acid render tests |
| 8 | 8 | `hairline_edge_drift` x Filters (blur/glow/drop-shadow/…) |
| 5 | 4 | `diffuse_mixed` x Filters (blur/glow/drop-shadow/…) |
| 6 | 6 | `hairline_edge_drift` x Morph shapes / tweens |
| 5 | 5 | `hairline_edge_drift` x BitmapData / drawing API |
| 4 | 0 | `missing_element` x Stage3D / AGAL / shaders **[BACKEND]** |
| 3 | 3 | `hairline_edge_drift` x Masks / clipping |
| 4 | 4 | `hairline_edge_drift` x Gradients |
| 4 | 4 | `hairline_edge_drift` x Blend modes |
| 2 | 1 | `halo_penumbra` x Filters (blur/glow/drop-shadow/…) |
| 2 | 2 | `row_banded` x Shumway acid render tests |
| 9 | 0 | `unrelated_content` x Video / NetStream **[BACKEND]** |
| 2 | 0 | `same_geometry_wrong_fill` x Stage3D / AGAL / shaders **[BACKEND]** |
| 2 | 0 | `same_geometry_wrong_fill` x Blend modes |

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

## Trace-axis flags (3) — kept on the board

A suite-local `ignored_tests.txt` entry (or a trace-axis ACCEPTED_DIFFS entry) says nothing about the pixels: image comparisons never gate trace pass/fail. Marked `[trace-ign]` in the board above.

| suite | comparisons |
|---|---:|
| `avm2` | 3 |

## Dispositioned but not failing (2)

The entry is stale on the image axis — it passes, or it has no `[image_comparisons]` block at all.

**Already noted as stale in the doc (2)** — no action; do not re-raise.

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
