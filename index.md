# Ruffle image-comparison failures

Generated: 2026-10-17T04:05:14.008759+00:00  
Run: https://github.com/PeerInfinity/SWFRecomp-CC/actions/runs/38995363802  
Commit: `38cf9b1a0ab8`

Only FAILING comparisons are published here. Passing renders are not saved. Each run force-pushes a single commit — this branch has no history by design.

**94 failing** of 588 comparisons (491 pass, 3 skip, 0 produced no render).

## Magnitude bands

| band | failures |
|---|---:|
| a_epsilon (<=100 channels over) | 26 |
| b_tiny (<0.1% of channels) | 19 |
| c_small (0.1-1%) | 17 |
| d_moderate (1-10%) | 19 |
| e_large (10-50%) | 8 |
| f_catastrophic (>=50%) | 5 |

## Failures

| suite | test | cmp | outliers / budget | excess | max_diff | band | files |
|---|---|---|---:|---:|---:|---|---|
| avm2 | pixelbender_dithering | output | 2764800 / 19929 | 2744871 | 162 | f_catastrophic (>=50%) | [actual](images/avm2/pixelbender_dithering/output.actual.png) [difference](images/avm2/pixelbender_dithering/output.difference.png) |
| avm2 | away3d_advanced_shallow_water_demo | output | 1326849 / 400 | 1326449 | 255 | e_large (10-50%) | [actual](images/avm2/away3d_advanced_shallow_water_demo/output.actual.png) [difference](images/avm2/away3d_advanced_shallow_water_demo/output.difference.png) |
| avm2 | stage3d_fractal | output | 1099377 / 100 | 1099277 | 255 | f_catastrophic (>=50%) | [actual](images/avm2/stage3d_fractal/output.actual.png) [difference](images/avm2/stage3d_fractal/output.difference.png) |
| avm2 | pixelbender_effect_glassDisplace_shaderfilter | output | 879464 / 380 | 879084 | 255 | e_large (10-50%) | [actual](images/avm2/pixelbender_effect_glassDisplace_shaderfilter/output.actual.png) [difference](images/avm2/pixelbender_effect_glassDisplace_shaderfilter/output.difference.png) |
| avm2 | stage3d_raytrace | output | 660000 / 10 | 659990 | 255 | f_catastrophic (>=50%) | [actual](images/avm2/stage3d_raytrace/output.actual.png) [difference](images/avm2/stage3d_raytrace/output.difference.png) |
| from_shumway | bitmapbuttons | output | 618042 / 0 | 618042 | 248 | f_catastrophic (>=50%) | [actual](images/from_shumway/bitmapbuttons/output.actual.png) [difference](images/from_shumway/bitmapbuttons/output.difference.png) |
| from_shumway | acid/acid-text-5 | output | 422241 / 6 | 422235 | 255 | e_large (10-50%) | [actual](images/from_shumway/acid/acid-text-5/output.actual.png) [difference](images/from_shumway/acid/acid-text-5/output.difference.png) |
| avm2 | stage3d_texture | output | 204781 / 117 | 204664 | 255 | e_large (10-50%) | [actual](images/avm2/stage3d_texture/output.actual.png) [difference](images/avm2/stage3d_texture/output.difference.png) |
| avm2 | bitmapdata_applyfilter_destpoint_edges | output | 149477 / 35 | 149442 | 238 | e_large (10-50%) | [actual](images/avm2/bitmapdata_applyfilter_destpoint_edges/output.actual.png) [difference](images/avm2/bitmapdata_applyfilter_destpoint_edges/output.difference.png) |
| avm2 | stage3d_bitmap | output | 135407 / 24 | 135383 | 255 | e_large (10-50%) | [actual](images/avm2/stage3d_bitmap/output.actual.png) [difference](images/avm2/stage3d_bitmap/output.difference.png) |
| visual | blend_modes/layer_erase | output | 66949 / 0 | 66949 | 255 | d_moderate (1-10%) | [actual](images/visual/blend_modes/layer_erase/output.actual.png) [difference](images/visual/blend_modes/layer_erase/output.difference.png) |
| visual | blend_modes/layer_alpha | output | 66744 / 0 | 66744 | 254 | d_moderate (1-10%) | [actual](images/visual/blend_modes/layer_alpha/output.actual.png) [difference](images/visual/blend_modes/layer_alpha/output.difference.png) |
| from_shumway | acid/acid-stroke-0 | output | 52702 / 0 | 52702 | 255 | d_moderate (1-10%) | [actual](images/from_shumway/acid/acid-stroke-0/output.actual.png) [difference](images/from_shumway/acid/acid-stroke-0/output.difference.png) |
| from_shumway | acid/acid-text-4 | output | 51678 / 0 | 51678 | 255 | d_moderate (1-10%) | [actual](images/from_shumway/acid/acid-text-4/output.actual.png) [difference](images/from_shumway/acid/acid-text-4/output.difference.png) |
| avm1 | netstream_play_flv_screen | output | 44751 / 0 | 44751 | 235 | f_catastrophic (>=50%) | [actual](images/avm1/netstream_play_flv_screen/output.actual.png) [difference](images/avm1/netstream_play_flv_screen/output.difference.png) |
| from_gnash/misc-ming.all | place_object_test | output | 41874 / 0 | 41874 | 255 | d_moderate (1-10%) | [actual](images/from_gnash/misc-ming.all/place_object_test/output.actual.png) [difference](images/from_gnash/misc-ming.all/place_object_test/output.difference.png) |
| from_shumway | acid/acid-shapes-testing | output | 41339 / 0 | 41339 | 255 | d_moderate (1-10%) | [actual](images/from_shumway/acid/acid-shapes-testing/output.actual.png) [difference](images/from_shumway/acid/acid-shapes-testing/output.difference.png) |
| avm2 | blend_shader_luma_lighten | output | 40318 / 3300 | 37018 | 204 | d_moderate (1-10%) | [actual](images/avm2/blend_shader_luma_lighten/output.actual.png) [difference](images/avm2/blend_shader_luma_lighten/output.difference.png) |
| from_shumway | acid/acid-morph | output | 31977 / 5600 | 26377 | 255 | d_moderate (1-10%) | [actual](images/from_shumway/acid/acid-morph/output.actual.png) [difference](images/from_shumway/acid/acid-morph/output.difference.png) |
| text | style_changes_in_html | output | 25024 / 0 | 25024 | 103 | d_moderate (1-10%) | [actual](images/text/style_changes_in_html/output.actual.png) [difference](images/text/style_changes_in_html/output.difference.png) |
| visual | fonts/font_lookup_as3 | output | 19560 / 72 | 19488 | 255 | d_moderate (1-10%) | [actual](images/visual/fonts/font_lookup_as3/output.actual.png) [difference](images/visual/fonts/font_lookup_as3/output.difference.png) |
| visual | simple_shapes/strokes/scale | output | 19308 / 0 | 19308 | 255 | d_moderate (1-10%) | [actual](images/visual/simple_shapes/strokes/scale/output.actual.png) [difference](images/visual/simple_shapes/strokes/scale/output.difference.png) |
| from_gnash/misc-ming.all | shape_test | output | 17911 / 0 | 17911 | 255 | c_small (0.1-1%) | [actual](images/from_gnash/misc-ming.all/shape_test/output.actual.png) [difference](images/from_gnash/misc-ming.all/shape_test/output.difference.png) |
| from_shumway | acid/acid-color-0 | output | 17376 / 3 | 17373 | 255 | c_small (0.1-1%) | [actual](images/from_shumway/acid/acid-color-0/output.actual.png) [difference](images/from_shumway/acid/acid-color-0/output.difference.png) |
| visual | definefont4 | output | 16086 / 0 | 16086 | 255 | d_moderate (1-10%) | [actual](images/visual/definefont4/output.actual.png) [difference](images/visual/definefont4/output.difference.png) |
| from_shumway | acid/acid-textfield | output | 15754 / 0 | 15754 | 255 | d_moderate (1-10%) | [actual](images/from_shumway/acid/acid-textfield/output.actual.png) [difference](images/from_shumway/acid/acid-textfield/output.difference.png) |
| avm2 | bitmapdata_draw_filters | output | 14400 / 0 | 14400 | 255 | e_large (10-50%) | [actual](images/avm2/bitmapdata_draw_filters/output.actual.png) [difference](images/avm2/bitmapdata_draw_filters/output.difference.png) |
| from_shumway | acid/acid-mask | output.01 | 12018 / 16 | 12002 | 124 | d_moderate (1-10%) | [actual](images/from_shumway/acid/acid-mask/output.01.actual.png) [difference](images/from_shumway/acid/acid-mask/output.01.difference.png) |
| from_shumway | acid/acid-mask | output.05 | 10915 / 16 | 10899 | 124 | d_moderate (1-10%) | [actual](images/from_shumway/acid/acid-mask/output.05.actual.png) [difference](images/from_shumway/acid/acid-mask/output.05.difference.png) |
| visual | video/colorconversion/h263 | output | 10808 / 0 | 10808 | 2 | c_small (0.1-1%) | [actual](images/visual/video/colorconversion/h263/output.actual.png) [difference](images/visual/video/colorconversion/h263/output.difference.png) |
| from_shumway | acid/acid-mask | output.10 | 9447 / 16 | 9431 | 128 | d_moderate (1-10%) | [actual](images/from_shumway/acid/acid-mask/output.10.actual.png) [difference](images/from_shumway/acid/acid-mask/output.10.difference.png) |
| from_shumway | MaskTest-2 | output | 7162 / 0 | 7162 | 251 | c_small (0.1-1%) | [actual](images/from_shumway/MaskTest-2/output.actual.png) [difference](images/from_shumway/MaskTest-2/output.difference.png) |
| visual | drawing_api/drawing_order | output | 6658 / 0 | 6658 | 255 | c_small (0.1-1%) | [actual](images/visual/drawing_api/drawing_order/output.actual.png) [difference](images/visual/drawing_api/drawing_order/output.difference.png) |
| from_shumway | acid/acid-gradient | output | 6639 / 0 | 6639 | 189 | c_small (0.1-1%) | [actual](images/from_shumway/acid/acid-gradient/output.actual.png) [difference](images/from_shumway/acid/acid-gradient/output.difference.png) |
| from_shumway | captions | output | 6528 / 0 | 6528 | 255 | c_small (0.1-1%) | [actual](images/from_shumway/captions/output.actual.png) [difference](images/from_shumway/captions/output.difference.png) |
| from_shumway | acid/acid-text | output | 5019 / 0 | 5019 | 255 | c_small (0.1-1%) | [actual](images/from_shumway/acid/acid-text/output.actual.png) [difference](images/from_shumway/acid/acid-text/output.difference.png) |
| avm2 | bitmap_pixelsnapping | output | 3831 / 0 | 3831 | 255 | c_small (0.1-1%) | [actual](images/avm2/bitmap_pixelsnapping/output.actual.png) [difference](images/avm2/bitmap_pixelsnapping/output.difference.png) |
| text | br_at_start | output | 3681 / 8 | 3673 | 255 | c_small (0.1-1%) | [actual](images/text/br_at_start/output.actual.png) [difference](images/text/br_at_start/output.difference.png) |
| from_shumway | hardwrap | output | 3099 / 0 | 3099 | 255 | c_small (0.1-1%) | [actual](images/from_shumway/hardwrap/output.actual.png) [difference](images/from_shumway/hardwrap/output.difference.png) |
| avm2 | bitmapdata_draw_cab_quality | output | 2400 / 80 | 2320 | 255 | d_moderate (1-10%) | [actual](images/avm2/bitmapdata_draw_cab_quality/output.actual.png) [difference](images/avm2/bitmapdata_draw_cab_quality/output.difference.png) |
| visual | cache_as_bitmap/drawing_api | output | 2295 / 0 | 2295 | 255 | c_small (0.1-1%) | [actual](images/visual/cache_as_bitmap/drawing_api/output.actual.png) [difference](images/visual/cache_as_bitmap/drawing_api/output.difference.png) |
| visual | blend_modes/shader_as_mask | output | 2100 / 0 | 2100 | 128 | e_large (10-50%) | [actual](images/visual/blend_modes/shader_as_mask/output.actual.png) [difference](images/visual/blend_modes/shader_as_mask/output.difference.png) |
| from_shumway | stylesheet | output | 2089 / 0 | 2089 | 255 | c_small (0.1-1%) | [actual](images/from_shumway/stylesheet/output.actual.png) [difference](images/from_shumway/stylesheet/output.difference.png) |
| avm2 | graphics_draw_triangles | output | 1812 / 0 | 1812 | 255 | d_moderate (1-10%) | [actual](images/avm2/graphics_draw_triangles/output.actual.png) [difference](images/avm2/graphics_draw_triangles/output.difference.png) |
| avm1 | movieclip_line_gradient_style | output | 1023 / 0 | 1023 | 209 | c_small (0.1-1%) | [actual](images/avm1/movieclip_line_gradient_style/output.actual.png) [difference](images/avm1/movieclip_line_gradient_style/output.difference.png) |
| visual | edittext/edittext_gutter | output | 1014 / 0 | 1014 | 255 | d_moderate (1-10%) | [actual](images/visual/edittext/edittext_gutter/output.actual.png) [difference](images/visual/edittext/edittext_gutter/output.difference.png) |
| visual | edittext/edittext_device_transform_negative | output | 1032 / 30 | 1002 | 255 | c_small (0.1-1%) | [actual](images/visual/edittext/edittext_device_transform_negative/output.actual.png) [difference](images/visual/edittext/edittext_device_transform_negative/output.difference.png) |
| visual | text/String_path_variable_button | output | 999 / 12 | 987 | 153 | c_small (0.1-1%) | [actual](images/visual/text/String_path_variable_button/output.actual.png) [difference](images/visual/text/String_path_variable_button/output.difference.png) |
| from_shumway | flash_text_TextField | output | 966 / 0 | 966 | 253 | b_tiny (<0.1% of channels) | [actual](images/from_shumway/flash_text_TextField/output.actual.png) [difference](images/from_shumway/flash_text_TextField/output.difference.png) |
| avm2 | sprite_with_frames | output | 914 / 0 | 914 | 1 | c_small (0.1-1%) | [actual](images/avm2/sprite_with_frames/output.actual.png) [difference](images/avm2/sprite_with_frames/output.difference.png) |
| from_gnash/misc-ming.all | BeginBitmapFill | output | 939 / 100 | 839 | 255 | b_tiny (<0.1% of channels) | [actual](images/from_gnash/misc-ming.all/BeginBitmapFill/output.actual.png) [difference](images/from_gnash/misc-ming.all/BeginBitmapFill/output.difference.png) |
| visual | filters/bevel | output | 750 / 6 | 744 | 254 | b_tiny (<0.1% of channels) | [actual](images/visual/filters/bevel/output.actual.png) [difference](images/visual/filters/bevel/output.difference.png) |
| avm2 | bitmapdata_colortransform | output | 726 / 0 | 726 | 125 | b_tiny (<0.1% of channels) | [actual](images/avm2/bitmapdata_colortransform/output.actual.png) [difference](images/avm2/bitmapdata_colortransform/output.difference.png) |
| avm2 | graphics_direct_commands | output | 2503 / 1800 | 703 | 255 | b_tiny (<0.1% of channels) | [actual](images/avm2/graphics_direct_commands/output.actual.png) [difference](images/avm2/graphics_direct_commands/output.difference.png) |
| visual | filters/drop_shadow_angles | output | 549 / 0 | 549 | 51 | b_tiny (<0.1% of channels) | [actual](images/visual/filters/drop_shadow_angles/output.actual.png) [difference](images/visual/filters/drop_shadow_angles/output.difference.png) |
| avm2 | bitmapdata_draw_rotation | output | 348 / 0 | 348 | 255 | b_tiny (<0.1% of channels) | [actual](images/avm2/bitmapdata_draw_rotation/output.actual.png) [difference](images/avm2/bitmapdata_draw_rotation/output.difference.png) |
| visual | filters/displacement_map | output | 408 / 72 | 336 | 127 | b_tiny (<0.1% of channels) | [actual](images/visual/filters/displacement_map/output.actual.png) [difference](images/visual/filters/displacement_map/output.difference.png) |
| avm2 | blend_scroll | output | 296 / 0 | 296 | 128 | b_tiny (<0.1% of channels) | [actual](images/avm2/blend_scroll/output.actual.png) [difference](images/avm2/blend_scroll/output.difference.png) |
| from_shumway | acid/acid-clip | output | 409 / 140 | 269 | 144 | b_tiny (<0.1% of channels) | [actual](images/from_shumway/acid/acid-clip/output.actual.png) [difference](images/from_shumway/acid/acid-clip/output.difference.png) |
| from_shumway | acid/acid-gc | output | 234 / 0 | 234 | 255 | b_tiny (<0.1% of channels) | [actual](images/from_shumway/acid/acid-gc/output.actual.png) [difference](images/from_shumway/acid/acid-gc/output.difference.png) |
| from_gnash/misc-ming.all | morph_test1 | frame1 | 217 / 0 | 217 | 255 | b_tiny (<0.1% of channels) | [actual](images/from_gnash/misc-ming.all/morph_test1/frame1.actual.png) [difference](images/from_gnash/misc-ming.all/morph_test1/frame1.difference.png) |
| from_shumway | acid/acid-text-6 | output | 198 / 0 | 198 | 255 | b_tiny (<0.1% of channels) | [actual](images/from_shumway/acid/acid-text-6/output.actual.png) [difference](images/from_shumway/acid/acid-text-6/output.difference.png) |
| avm2 | netstream_play_flv | output | 179 / 0 | 179 | 4 | b_tiny (<0.1% of channels) | [actual](images/avm2/netstream_play_flv/output.actual.png) [difference](images/avm2/netstream_play_flv/output.difference.png) |
| avm2 | bitmapdata_draw | output | 753 / 600 | 153 | 255 | b_tiny (<0.1% of channels) | [actual](images/avm2/bitmapdata_draw/output.actual.png) [difference](images/avm2/bitmapdata_draw/output.difference.png) |
| avm2 | graphics_gradients | output | 148 / 0 | 148 | 73 | b_tiny (<0.1% of channels) | [actual](images/avm2/graphics_gradients/output.actual.png) [difference](images/avm2/graphics_gradients/output.difference.png) |
| avm1 | movieclip_begin_gradient_fill | output | 132 / 0 | 132 | 209 | b_tiny (<0.1% of channels) | [actual](images/avm1/movieclip_begin_gradient_fill/output.actual.png) [difference](images/avm1/movieclip_begin_gradient_fill/output.difference.png) |
| from_shumway | acid/acid-text-escape | output | 110 / 0 | 110 | 255 | b_tiny (<0.1% of channels) | [actual](images/from_shumway/acid/acid-text-escape/output.actual.png) [difference](images/from_shumway/acid/acid-text-escape/output.difference.png) |
| visual | video/deblocking | output | 104 / 0 | 104 | 4 | b_tiny (<0.1% of channels) | [actual](images/visual/video/deblocking/output.actual.png) [difference](images/visual/video/deblocking/output.difference.png) |
| from_shumway | acid/acid-shapes | output | 25688 / 25600 | 88 | 197 | a_epsilon (<=100 channels over) | [actual](images/from_shumway/acid/acid-shapes/output.actual.png) [difference](images/from_shumway/acid/acid-shapes/output.difference.png) |
| visual | drawing_api/gradient_focal_point | output | 60 / 0 | 60 | 39 | a_epsilon (<=100 channels over) | [actual](images/visual/drawing_api/gradient_focal_point/output.actual.png) [difference](images/visual/drawing_api/gradient_focal_point/output.difference.png) |
| visual | simple_shapes/text_field_mask | output | 56 / 0 | 56 | 255 | a_epsilon (<=100 channels over) | [actual](images/visual/simple_shapes/text_field_mask/output.actual.png) [difference](images/visual/simple_shapes/text_field_mask/output.difference.png) |
| avm1 | netstream_play_flv | output | 44 / 0 | 44 | 3 | a_epsilon (<=100 channels over) | [actual](images/avm1/netstream_play_flv/output.actual.png) [difference](images/avm1/netstream_play_flv/output.difference.png) |
| visual | filters/bevel_full | output | 42 / 18 | 24 | 254 | a_epsilon (<=100 channels over) | [actual](images/visual/filters/bevel_full/output.actual.png) [difference](images/visual/filters/bevel_full/output.difference.png) |
| visual | filters/bevel_inner | output | 42 / 18 | 24 | 254 | a_epsilon (<=100 channels over) | [actual](images/visual/filters/bevel_inner/output.actual.png) [difference](images/visual/filters/bevel_inner/output.difference.png) |
| visual | filters/bevel_outer | output | 42 / 18 | 24 | 254 | a_epsilon (<=100 channels over) | [actual](images/visual/filters/bevel_outer/output.actual.png) [difference](images/visual/filters/bevel_outer/output.difference.png) |
| visual | filters/glow_with_alpha_strength | output | 42 / 18 | 24 | 254 | a_epsilon (<=100 channels over) | [actual](images/visual/filters/glow_with_alpha_strength/output.actual.png) [difference](images/visual/filters/glow_with_alpha_strength/output.difference.png) |
| from_gnash/misc-ming.all | Video-EmbedSquareTest | output | 12 / 0 | 12 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_gnash/misc-ming.all/Video-EmbedSquareTest/output.actual.png) [difference](images/from_gnash/misc-ming.all/Video-EmbedSquareTest/output.difference.png) |
| from_gnash/misc-ming.all | morph_test1 | frame2 | 12 / 0 | 12 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_gnash/misc-ming.all/morph_test1/frame2.actual.png) [difference](images/from_gnash/misc-ming.all/morph_test1/frame2.difference.png) |
| from_gnash/misc-ming.all | morph_test1 | frame3 | 12 / 0 | 12 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_gnash/misc-ming.all/morph_test1/frame3.actual.png) [difference](images/from_gnash/misc-ming.all/morph_test1/frame3.difference.png) |
| from_gnash/misc-ming.all | morph_test1 | frame4 | 12 / 0 | 12 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_gnash/misc-ming.all/morph_test1/frame4.actual.png) [difference](images/from_gnash/misc-ming.all/morph_test1/frame4.difference.png) |
| from_gnash/misc-ming.all | morph_test1 | frame5 | 12 / 0 | 12 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_gnash/misc-ming.all/morph_test1/frame5.actual.png) [difference](images/from_gnash/misc-ming.all/morph_test1/frame5.difference.png) |
| from_gnash/misc-ming.all | morph_test1 | frame6 | 12 / 0 | 12 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_gnash/misc-ming.all/morph_test1/frame6.actual.png) [difference](images/from_gnash/misc-ming.all/morph_test1/frame6.difference.png) |
| from_shumway | acid/acid-text-6 | frame5 | 12 / 0 | 12 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_shumway/acid/acid-text-6/frame5.actual.png) [difference](images/from_shumway/acid/acid-text-6/frame5.difference.png) |
| from_shumway | gradientTransform | output | 9 / 0 | 9 | 11 | a_epsilon (<=100 channels over) | [actual](images/from_shumway/gradientTransform/output.actual.png) [difference](images/from_shumway/gradientTransform/output.difference.png) |
| from_shumway | acid/acid-scale | output | 8 / 0 | 8 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_shumway/acid/acid-scale/output.actual.png) [difference](images/from_shumway/acid/acid-scale/output.difference.png) |
| avm2 | bitmapdata_opaque | output | 4 / 0 | 4 | 127 | a_epsilon (<=100 channels over) | [actual](images/avm2/bitmapdata_opaque/output.actual.png) [difference](images/avm2/bitmapdata_opaque/output.difference.png) |
| from_shumway | 3_joystick | output | 4 / 0 | 4 | 187 | a_epsilon (<=100 channels over) | [actual](images/from_shumway/3_joystick/output.actual.png) [difference](images/from_shumway/3_joystick/output.difference.png) |
| from_shumway | acid/acid-gradient-2 | output | 3 / 0 | 3 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_shumway/acid/acid-gradient-2/output.actual.png) [difference](images/from_shumway/acid/acid-gradient-2/output.difference.png) |
| visual | filters/drop_shadow | output | 3 / 0 | 3 | 255 | a_epsilon (<=100 channels over) | [actual](images/visual/filters/drop_shadow/output.actual.png) [difference](images/visual/filters/drop_shadow/output.difference.png) |
| visual | filters/glow | output | 3 / 0 | 3 | 255 | a_epsilon (<=100 channels over) | [actual](images/visual/filters/glow/output.actual.png) [difference](images/visual/filters/glow/output.difference.png) |
| visual | filters/glow_without_composite_source | output | 3 / 0 | 3 | 255 | a_epsilon (<=100 channels over) | [actual](images/visual/filters/glow_without_composite_source/output.actual.png) [difference](images/visual/filters/glow_without_composite_source/output.difference.png) |
| avm2 | graphics_simple_shapes | output | 2 / 0 | 2 | 255 | a_epsilon (<=100 channels over) | [actual](images/avm2/graphics_simple_shapes/output.actual.png) [difference](images/avm2/graphics_simple_shapes/output.difference.png) |
| from_shumway | doubleAndRegister | output | 2 / 0 | 2 | 255 | a_epsilon (<=100 channels over) | [actual](images/from_shumway/doubleAndRegister/output.actual.png) [difference](images/from_shumway/doubleAndRegister/output.difference.png) |
| visual | cache_as_bitmap/edittext_scroll | output.02 | 6 / 5 | 1 | 255 | a_epsilon (<=100 channels over) | [actual](images/visual/cache_as_bitmap/edittext_scroll/output.02.actual.png) [difference](images/visual/cache_as_bitmap/edittext_scroll/output.02.difference.png) |

