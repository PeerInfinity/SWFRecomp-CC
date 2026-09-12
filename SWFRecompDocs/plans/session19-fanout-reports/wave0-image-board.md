# Image triage board

`scripts/image_triage.py --stem graphics` over 196 failing comparisons from the image run at `0ccafbc4eb896f2a1ee5fe7dd8a0bb31f0f7de3f` (2026-09-11T21:09:55.018024+00:00).

Ranked by **mechanism** first. Near-pass ranking alone aims at `hairline_edge_drift`, which is mostly the lavapipe-vs-Flash antialiasing gap — the least fixable cluster in the corpus.

## Clusters

| cluster | cmps | tests | near-pass | prior | example tests |
|---|---:|---:|---:|---:|---|
| `png_unavailable` | 90 | 76 | 35 | 0.00 | `fonts/embed_matching/fallback_preferences`, `fonts/embed_matching/match_style`, `stage3d/sampler_odd_size`, `stage3d/scissor_rectangle` |
| `hairline_edge_drift` | 32 | 24 | 24 | 0.25 | `from_shumway/acid/acid-gradient-2`, `from_shumway/acid/acid-text-6`, `from_shumway/gradientTransform`, `from_gnash/misc-ming.all/morph_test1` |
| `blank_render` | 30 | 30 | 0 | 0.30 | `avm2/stage3d_bitmap`, `avm2/stage3d_blend`, `avm2/stage3d_multistage_triangle`, `avm2/stage3d_program_constants_bytearray_be` |
| `same_geometry_wrong_fill` | 12 | 12 | 1 | 0.80 | `avm2/blend_shader_luma_lighten`, `avm2/edittext_get_char_index_at_point`, `from_shumway/acid/acid-color-0`, `avm2/bitmapdata_applyfilter_blur` |
| `diffuse_mixed` | 10 | 10 | 2 | 0.40 | `from_shumway/acid/acid-shapes`, `from_shumway/acid/acid-text`, `from_shumway/acid/acid-shapes-testing`, `from_shumway/acid/acid-stroke-0` |
| `missing_element` | 6 | 6 | 1 | 0.60 | `from_shumway/flash_text_TextField`, `from_shumway/hardwrap`, `from_shumway/stylesheet`, `from_shumway/MaskTest-2` |
| `row_banded` | 5 | 5 | 0 | 0.55 | `avm2/bitmap_pixelsnapping`, `avm2/bitmapdata_draw`, `from_shumway/acid/acid-text-4`, `from_shumway/acid/acid-textfield` |
| `content_displaced` | 4 | 4 | 0 | 0.50 | `from_gnash/misc-ming.all/place_object_test`, `from_shumway/avm1/text-bind`, `avm2/stage_scale_factor`, `avm2/displayobject_getbounds_shape` |
| `unrelated_content` | 2 | 2 | 0 | 0.15 | `avm2/bitmapdata_draw_masks`, `avm2/away3d_advanced_shallow_water_demo` |
| `localized_region` | 2 | 2 | 1 | 0.55 | `avm2/displayobject_opaque_background`, `from_shumway/captions` |
| `halo_penumbra` | 2 | 2 | 0 | 0.90 | `avm2/geom_transform`, `avm2/pixelbender_effect_glassDisplace` |
| `global_color_shift` | 1 | 1 | 0 | 1.00 | `avm2/bitmapdata_draw_filters` |
| **total** | **196** | | **64** | | |

## Cluster x band

```
cluster                    a_epsilon b_tiny c_small d_moderate e_large f_catastrophic no_render size_mismatch
png_unavailable                31      4      8     26      6     15      0      0
hairline_edge_drift             8     16      5      3      0      0      0      0
blank_render                    0      0      0      2     12     16      0      0
same_geometry_wrong_fill        0      1      5      4      2      0      0      0
diffuse_mixed                   0      2      3      4      1      0      0      0
missing_element                 0      1      3      0      0      2      0      0
row_banded                      0      0      2      3      0      0      0      0
content_displaced               0      0      1      2      0      1      0      0
unrelated_content               0      0      0      1      1      0      0      0
localized_region                1      0      1      0      0      0      0      0
halo_penumbra                   0      0      1      0      1      0      0      0
global_color_shift              0      0      0      0      1      0      0      0
```

## Top 25 (of 75 live test x cluster rows, 81 comparisons)

| # | score | cmps | fan(tests) | suite/test | cluster | band | excess |
|---:|---:|---:|---:|---|---|---|---:|
| 1 | 1.05 | 6 | 1 | `from_gnash/misc-ming.all/morph_test1` | hairline_edge_drift | b_tiny | 186 |
| 2 | 0.96 | 1 | 2 | `avm2/blend_shader_luma_lighten` | same_geometry_wrong_fill | c_small | 1237 **[BACKEND]** |
| 3 | 0.96 | 1 | 2 | `from_shumway/acid/acid-color-0` | same_geometry_wrong_fill | c_small | 17383 |
| 4 | 0.96 | 1 | 2 | `avm2/edittext_get_char_index_at_point` | same_geometry_wrong_fill | c_small | 22849 |
| 5 | 0.83 | 1 | 22 | `avm2/stage3d_bitmap` | blank_render | d_moderate | 85740 **[BACKEND]** |
| 6 | 0.81 | 2 | 4 | `from_shumway/acid/acid-text-6` | hairline_edge_drift | b_tiny | 12 |
| 7 | 0.79 | 1 | 5 | `from_shumway/acid/acid-text` | diffuse_mixed | c_small | 7683 |
| 8 | 0.79 | 1 | 5 | `from_shumway/acid/acid-shapes` | diffuse_mixed | c_small | 41577 |
| 9 | 0.77 | 1 | 2 | `avm2/edittext_get_line_index_at_point` | same_geometry_wrong_fill | d_moderate | 18403 |
| 10 | 0.77 | 1 | 2 | `from_shumway/acid/acid-bitmapData-copyPixels` | same_geometry_wrong_fill | d_moderate | 53760 |
| 11 | 0.73 | 1 | 1 | `avm2/graphics_simple_shapes` | same_geometry_wrong_fill | b_tiny | 230 |
| 12 | 0.68 | 1 | 1 | `avm2/geom_transform` | halo_penumbra | c_small | 8746 |
| 13 | 0.67 | 1 | 22 | `avm2/stage3d_triangle_float1` | blank_render | e_large | 144420 **[BACKEND]** |
| 14 | 0.67 | 1 | 22 | `avm2/stage3d_triangle` | blank_render | e_large | 191267 **[BACKEND]** |
| 15 | 0.67 | 1 | 22 | `avm2/stage3d_triangle_bytes4` | blank_render | e_large | 191267 **[BACKEND]** |
| 16 | 0.67 | 1 | 22 | `avm2/stage3d_triangle_index_upload` | blank_render | e_large | 191267 **[BACKEND]** |
| 17 | 0.67 | 1 | 22 | `avm2/stage3d_multistage_triangle` | blank_render | e_large | 191416 **[BACKEND]** |
| 18 | 0.67 | 1 | 22 | `avm2/stage3d_program_constants_bytearray_be` | blank_render | e_large | 323452 **[BACKEND]** |
| 19 | 0.67 | 1 | 22 | `avm2/stage3d_program_constants_bytearray_le` | blank_render | e_large | 323452 **[BACKEND]** |
| 20 | 0.67 | 1 | 22 | `avm2/stage3d_rotating_cube` | blank_render | e_large | 331894 **[BACKEND]** |
| 21 | 0.67 | 1 | 22 | `avm2/stage3d_blend` | blank_render | e_large | 1014756 **[BACKEND]** |
| 22 | 0.66 | 1 | 2 | `avm2/bitmap_pixelsnapping` | row_banded | c_small | 3831 |
| 23 | 0.65 | 1 | 5 | `from_shumway/acid/acid-gradient-2` | hairline_edge_drift | a_epsilon | 38 |
| 24 | 0.62 | 1 | 2 | `avm2/pixelbender_effect_glassDisplace_shaderfilter` | same_geometry_wrong_fill | e_large | 879084 **[BACKEND]** |
| 25 | 0.61 | 1 | 1 | `from_shumway/acid/acid-morph` | same_geometry_wrong_fill | c_small | 1711 |

## Top groups (cluster x family, live comparisons only)

| cmps | near-pass | cluster x family |
|---:|---:|---|
| 22 | 0 | `blank_render` x Stage3D / AGAL / shaders **[BACKEND]** |
| 6 | 6 | `hairline_edge_drift` x Morph shapes / tweens |
| 5 | 5 | `hairline_edge_drift` x Shumway acid render tests |
| 4 | 4 | `hairline_edge_drift` x Gradients |
| 2 | 1 | `same_geometry_wrong_fill` x Text: EditText / layout / HTML |
| 2 | 1 | `same_geometry_wrong_fill` x Shumway acid render tests |
| 3 | 3 | `hairline_edge_drift` x BitmapData / drawing API |
| 2 | 1 | `same_geometry_wrong_fill` x Stage3D / AGAL / shaders **[BACKEND]** |
| 2 | 2 | `diffuse_mixed` x Shumway acid render tests |
| 3 | 3 | `hairline_edge_drift` x Filters (blur/glow/drop-shadow/…) |
| 2 | 1 | `row_banded` x BitmapData / drawing API |
| 2 | 2 | `diffuse_mixed` x (unclassified) |
| 1 | 1 | `same_geometry_wrong_fill` x Shapes / fills / tessellation |
| 1 | 1 | `halo_penumbra` x Scale-9 / transforms / matrices |
| 2 | 0 | `blank_render` x Video / NetStream **[BACKEND]** |

## Dispositioned failing comparisons (8) — excluded from the board

| comparison | cluster | disposition |
|---|---|---|
| `avm1/netstream_play_flv [output]` | hairline_edge_drift | ACCEPTED_DIFFS (avm1): `avm1/netstream_play_flv` — Sorenson Spark pixel parity (44 outliers, max diff 3)  [image-axis SCOPE: avm1/netstream_play_flv output — verify per comparison] |
| `avm1/netstream_play_flv_screen [output]` | blank_render | RUFFLE_VS_FLASH (avm1): Video Display Object Render Bounds: `netstream_play_flv_screen` Asset Stamp |
| `avm2/bitmapdata_applyfilter_blur [output]` | same_geometry_wrong_fill | ACCEPTED_DIFFS (avm1): `avm2/bitmapdata_applyfilter_blur` — residual is the default-font text, not the blur (30 844 outlier channels, mean 1.21)  [image-axis SCOPE: avm2/bitmapdata_applyfilter_blur output — verify per comparison] |
| `from_shumway/avm1/text-bind [output]` | content_displaced | ACCEPTED_DIFFS (avm1): `from_shumway/avm1/text-bind` — device-font file mismatch: text ~14px too low (~1900 outlier pixels, max diff 158) |
| `visual/simple_shapes/masks [output]` | png_unavailable | ACCEPTED_DIFFS (avm1): `visual/simple_shapes/masks` + `visual/simple_shapes/masks_equal_clipdepth` — 1-sample rasteriser tie (1686 outlier channels each)  [image-axis SCOPE: both tests, the single `output` comparison of each — verify per comparison] |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | png_unavailable | ACCEPTED_DIFFS (avm1): `visual/simple_shapes/masks` + `visual/simple_shapes/masks_equal_clipdepth` — 1-sample rasteriser tie (1686 outlier channels each)  [image-axis SCOPE: both tests, the single `output` comparison of each — verify per comparison] |
| `visual/video/colorconversion/h263 [output]` | png_unavailable | ACCEPTED_DIFFS (avm1): `visual/video/colorconversion/h263` — Spark IDCT precision (10 808 outlier channels, max 2)  [image-axis SCOPE: visual/video/colorconversion/h263 output — verify per comparison] |
| `visual/video/deblocking [output]` | png_unavailable | ACCEPTED_DIFFS (avm1): `visual/video/deblocking` — Spark IDCT precision, one Cb level on one chroma row (104 outlier channels, max 4)  [image-axis SCOPE: visual/video/deblocking output — verify per comparison] |

## Trace-axis flags (3) — kept on the board

A suite-local `ignored_tests.txt` entry (or a trace-axis ACCEPTED_DIFFS entry) says nothing about the pixels: image comparisons never gate trace pass/fail. Marked `[trace-ign]` in the board above.

| suite | comparisons |
|---|---:|
| `avm2` | 3 |

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
- `visual/blend_modes/shader_as_mask [output]` — png_unavailable
- `visual/simple_shapes/strokes/scale [output]` — png_unavailable
