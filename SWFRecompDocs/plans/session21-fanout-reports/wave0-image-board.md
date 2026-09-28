# Image triage board

`scripts/image_triage.py --stem graphics` over 171 failing comparisons from the image run at `d6bcfa56c4c0b310644b33a76e05f46b730fb99b` (2026-09-19T05:45:07.466842+00:00).

Ranked by **mechanism** first. Near-pass ranking alone aims at `hairline_edge_drift`, which is mostly the lavapipe-vs-Flash antialiasing gap — the least fixable cluster in the corpus.

## Clusters

| cluster | cmps | tests | near-pass | prior | example tests |
|---|---:|---:|---:|---:|---|
| `hairline_edge_drift` | 66 | 51 | 51 | 0.25 | `visual/cache_as_bitmap/edittext_hscroll`, `visual/edittext/edittext_border_transform`, `visual/edittext/edittext_caret_multiline`, `visual/edittext/edittext_device_transform_small_shear` |
| `diffuse_mixed` | 29 | 29 | 11 | 0.40 | `visual/blend_modes/add`, `visual/blend_modes/alpha_no_layer`, `visual/blend_modes/difference`, `visual/blend_modes/erase_no_layer` |
| `same_geometry_wrong_fill` | 14 | 14 | 0 | 0.80 | `avm2/bitmapdata_copypixels`, `avm2/blend_shader_luma_lighten`, `visual/drawing_api/drawing_order`, `avm2/bitmapdata_applyfilter_blur` |
| `blank_render` | 13 | 13 | 0 | 0.30 | `avm2/netstream_seek_flv`, `avm2/netstream_play_flv`, `visual/video/h264_multinalu`, `avm1/netstream_play_flv_screen` |
| `unrelated_content` | 12 | 4 | 0 | 0.15 | `visual/video/h264`, `avm2/bitmapdata_draw_masks`, `avm2/away3d_advanced_shallow_water_demo`, `avm2/stage3d_bitmap` |
| `missing_element` | 11 | 11 | 1 | 0.60 | `from_shumway/flash_text_TextField`, `from_shumway/hardwrap`, `from_shumway/stylesheet`, `avm2/stage3d_texture_bytearray_compressed_alpha` |
| `row_banded` | 7 | 7 | 1 | 0.55 | `avm2/graphics_gradients`, `avm1/movieclip_line_gradient_style`, `avm2/bitmap_pixelsnapping`, `avm2/bitmapdata_draw` |
| `halo_penumbra` | 7 | 7 | 1 | 0.90 | `visual/cache_as_bitmap/avm2_button`, `avm2/geom_transform`, `visual/simple_shapes/heavy_tesselation`, `visual/filters/any_blur_scales_with_screen` |
| `content_displaced` | 6 | 5 | 0 | 0.50 | `from_shumway/avm1/text-bind`, `text/br_at_start`, `text/style_changes_in_html`, `visual/cache_as_bitmap/edittext_scroll` |
| `localized_region` | 3 | 3 | 1 | 0.55 | `avm2/displayobject_opaque_background`, `from_shumway/captions`, `avm2/stage3d_texture_bytearray` |
| `global_color_shift` | 1 | 1 | 0 | 1.00 | `avm2/bitmapdata_draw_filters` |
| `offset_translation` | 1 | 1 | 0 | 1.00 | `visual/cache_as_bitmap/edittext_hscroll` |
| `extra_element` | 1 | 1 | 0 | 0.60 | `visual/simple_shapes/strokes/scale` |
| **total** | **171** | | **66** | | |

## Cluster x band

```
cluster                    a_epsilon b_tiny c_small d_moderate e_large f_catastrophic no_render size_mismatch
hairline_edge_drift            32     19      9      6      0      0      0      0
diffuse_mixed                   9      2      2     15      1      0      0      0
same_geometry_wrong_fill        0      0      6      5      3      0      0      0
blank_render                    0      0      0      3      3      7      0      0
unrelated_content               0      0      0      1      2      9      0      0
missing_element                 0      1      3      3      2      2      0      0
row_banded                      0      1      2      4      0      0      0      0
halo_penumbra                   1      0      2      2      2      0      0      0
content_displaced               0      0      2      2      2      0      0      0
localized_region                1      0      1      1      0      0      0      0
global_color_shift              0      0      0      0      1      0      0      0
offset_translation              0      0      0      0      1      0      0      0
extra_element                   0      0      0      1      0      0      0      0
```

## Top 40 (of 118 live test x cluster rows, 140 comparisons)

| # | score | cmps | fan(tests) | suite/test | cluster | band | excess |
|---:|---:|---:|---:|---|---|---|---:|
| 1 | 1.52 | 6 | 5 | `visual/edittext/edittext_caret_multiline` | hairline_edge_drift | a_epsilon | 60 |
| 2 | 1.27 | 1 | 8 | `visual/blend_modes/add` | diffuse_mixed | a_epsilon | 5 |
| 3 | 1.27 | 1 | 8 | `visual/blend_modes/lighten` | diffuse_mixed | a_epsilon | 5 |
| 4 | 1.27 | 1 | 8 | `visual/blend_modes/screen` | diffuse_mixed | a_epsilon | 5 |
| 5 | 1.27 | 1 | 8 | `visual/blend_modes/difference` | diffuse_mixed | a_epsilon | 7 |
| 6 | 1.27 | 1 | 8 | `visual/blend_modes/alpha_no_layer` | diffuse_mixed | a_epsilon | 18 |
| 7 | 1.27 | 1 | 8 | `visual/blend_modes/erase_no_layer` | diffuse_mixed | a_epsilon | 18 |
| 8 | 1.27 | 1 | 8 | `visual/blend_modes/overlay` | diffuse_mixed | a_epsilon | 19 |
| 9 | 1.27 | 1 | 8 | `visual/blend_modes/hardlight` | diffuse_mixed | a_epsilon | 21 |
| 10 | 1.22 | 1 | 3 | `avm2/blend_shader_luma_lighten` | same_geometry_wrong_fill | c_small | 1237 **[BACKEND]** |
| 11 | 1.22 | 1 | 3 | `visual/drawing_api/drawing_order` | same_geometry_wrong_fill | c_small | 6658 |
| 12 | 1.22 | 1 | 3 | `avm2/bitmapdata_copypixels` | same_geometry_wrong_fill | c_small | 20800 |
| 13 | 1.16 | 2 | 5 | `visual/edittext/edittext_border_transform` | hairline_edge_drift | a_epsilon | 23 |
| 14 | 1.05 | 6 | 1 | `from_gnash/misc-ming.all/morph_test1` | hairline_edge_drift | b_tiny | 186 |
| 15 | 0.98 | 1 | 4 | `text/br_at_start` | content_displaced | c_small | 3683 |
| 16 | 0.98 | 1 | 3 | `visual/cache_as_bitmap/nested_rotation` | same_geometry_wrong_fill | d_moderate | 25665 |
| 17 | 0.98 | 1 | 3 | `visual/filters/blur_scales_with_screen` | same_geometry_wrong_fill | d_moderate | 30440 |
| 18 | 0.93 | 1 | 5 | `visual/edittext/edittext_device_transform_small_shear` | hairline_edge_drift | a_epsilon | 38 |
| 19 | 0.93 | 1 | 5 | `visual/cache_as_bitmap/edittext_hscroll` | hairline_edge_drift | a_epsilon | 96 |
| 20 | 0.90 | 1 | 1 | `visual/cache_as_bitmap/avm2_button` | halo_penumbra | a_epsilon | 6 |
| 21 | 0.84 | 1 | 10 | `visual/cache_as_bitmap/cab_mask_filters` | diffuse_mixed | d_moderate | 612 |
| 22 | 0.84 | 1 | 10 | `visual/filters/displacement_map` | diffuse_mixed | d_moderate | 20589 |
| 23 | 0.84 | 1 | 10 | `visual/filters/glow_without_composite_source` | diffuse_mixed | d_moderate | 24919 |
| 24 | 0.84 | 1 | 10 | `visual/filters/glow` | diffuse_mixed | d_moderate | 24992 |
| 25 | 0.84 | 1 | 10 | `visual/filters/drop_shadow` | diffuse_mixed | d_moderate | 46032 |
| 26 | 0.84 | 1 | 10 | `visual/filters/bevel_inner` | diffuse_mixed | d_moderate | 48116 |
| 27 | 0.84 | 1 | 10 | `visual/filters/drop_shadow_angles` | diffuse_mixed | d_moderate | 55899 |
| 28 | 0.84 | 1 | 10 | `visual/filters/bevel_full` | diffuse_mixed | d_moderate | 66764 |
| 29 | 0.84 | 1 | 10 | `visual/filters/bevel` | diffuse_mixed | d_moderate | 69223 |
| 30 | 0.84 | 1 | 10 | `visual/filters/bevel_outer` | diffuse_mixed | d_moderate | 78358 |
| 31 | 0.81 | 2 | 4 | `from_shumway/acid/acid-text-6` | hairline_edge_drift | b_tiny | 12 |
| 32 | 0.79 | 1 | 2 | `avm2/graphics_gradients` | row_banded | b_tiny | 349 |
| 33 | 0.79 | 1 | 6 | `from_shumway/MaskTest` | hairline_edge_drift | a_epsilon | 1 |
| 34 | 0.79 | 1 | 6 | `visual/avm2_button_scroll_rect` | hairline_edge_drift | a_epsilon | 6 |
| 35 | 0.79 | 1 | 6 | `visual/simple_shapes/scroll_rect_mask` | hairline_edge_drift | a_epsilon | 20 |
| 36 | 0.79 | 2 | 4 | `visual/cache_as_bitmap/edittext_scroll` | content_displaced | e_large | 561 |
| 37 | 0.79 | 1 | 4 | `text/style_changes_in_html` | content_displaced | d_moderate | 25102 |
| 38 | 0.78 | 1 | 3 | `avm2/pixelbender_effect_glassDisplace_shaderfilter` | same_geometry_wrong_fill | e_large | 879084 **[BACKEND]** |
| 39 | 0.77 | 1 | 2 | `visual/blend_modes/layer_alpha` | same_geometry_wrong_fill | d_moderate | 66759 |
| 40 | 0.77 | 1 | 2 | `visual/blend_modes/layer_erase` | same_geometry_wrong_fill | d_moderate | 66964 |

## Top groups (cluster x family, live comparisons only)

| cmps | near-pass | cluster x family |
|---:|---:|---|
| 12 | 10 | `hairline_edge_drift` x Text: EditText / layout / HTML |
| 8 | 8 | `diffuse_mixed` x Blend modes |
| 10 | 0 | `diffuse_mixed` x Filters (blur/glow/drop-shadow/…) |
| 7 | 6 | `hairline_edge_drift` x Filters (blur/glow/drop-shadow/…) |
| 6 | 6 | `hairline_edge_drift` x Morph shapes / tweens |
| 3 | 2 | `same_geometry_wrong_fill` x BitmapData / drawing API |
| 5 | 5 | `hairline_edge_drift` x BitmapData / drawing API |
| 4 | 1 | `content_displaced` x Text: EditText / layout / HTML |
| 5 | 5 | `hairline_edge_drift` x Shumway acid render tests |
| 3 | 3 | `hairline_edge_drift` x Masks / clipping |
| 4 | 4 | `hairline_edge_drift` x Gradients |
| 4 | 4 | `hairline_edge_drift` x Blend modes |
| 3 | 0 | `missing_element` x Stage3D / AGAL / shaders **[BACKEND]** |
| 2 | 1 | `same_geometry_wrong_fill` x Stage3D / AGAL / shaders **[BACKEND]** |
| 9 | 0 | `unrelated_content` x Video / NetStream **[BACKEND]** |

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
