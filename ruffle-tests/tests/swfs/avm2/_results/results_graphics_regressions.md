# Graphics vs Trace Mode Differences

Trace: 843/1221 passing | Graphics: 820/1221 passing

## Graphics Regressions (44 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `away3d_advanced_shallow_water_demo` | Output Mismatch | 0/8 lines match |
| 2 | `bitmapdata_applyfilter_blur` | Output Mismatch | 0/3 lines match |
| 3 | `bitmapdata_applyfilter_colormatrix` | Output Mismatch | 0/3 lines match |
| 4 | `bitmapdata_applyfilter_destpoint` | Output Mismatch | 0/2 lines match |
| 5 | `bitmapdata_applyfilter_destpoint_edges` | Output Mismatch | 0/2 lines match |
| 6 | `bitmapdata_colortransform` | Output Mismatch | 0/2 lines match |
| 7 | `bitmapdata_copychannel` | Output Mismatch | 0/2 lines match |
| 8 | `bitmapdata_draw_filters` | Output Mismatch | 0/2 lines match |
| 9 | `bitmapdata_filter_sourcerect` | Output Mismatch | 0/4 lines match |
| 10 | `displayobject_colortransform_nested` | Output Mismatch | 0/2 lines match |
| 11 | `font_enumeratefonts` | Output Mismatch | 41/46 lines match |
| 12 | `graphics_bitmap_fill` | Output Mismatch | 0/3 lines match |
| 13 | `graphics_bitmaps` | Output Mismatch | 0/3 lines match |
| 14 | `graphics_direct_commands` | Output Mismatch | 0/3 lines match |
| 15 | `graphics_gradients` | Output Mismatch | 0/3 lines match |
| 16 | `graphics_round_rects` | Output Mismatch | 0/2 lines match |
| 17 | `mouse_over_while_dragging` | Output Mismatch | 3/5 lines match |
| 18 | `pixelbender_effect_BlurredFocus` | Output Mismatch | 0/4 lines match |
| 19 | `pixelbender_effect_glassDisplace` | Output Mismatch | 0/4 lines match |
| 20 | `pixelbender_effect_smudge` | Output Mismatch | 0/4 lines match |
| 21 | `pixelbender_effect_tintype` | Output Mismatch | 0/4 lines match |
| 22 | `pixelbender_effect_twirl` | Output Mismatch | 0/4 lines match |
| 23 | `pixelbender_images` | Output Mismatch | 0/4 lines match |
| 24 | `remove_child_clear_field` | Output Mismatch | 23/92 lines match |
| 25 | `stage3d_agal_cross_product` | Output Mismatch | 0/2 lines match |
| 26 | `stage3d_bitmap` | Output Mismatch | 0/3 lines match |
| 27 | `stage3d_float1_index` | Output Mismatch | 0/2 lines match |
| 28 | `stage3d_fractal` | Output Mismatch | 0/4 lines match |
| 29 | `stage3d_ignore_sampler_override` | Output Mismatch | 0/2 lines match |
| 30 | `stage3d_program_constants_bytearray_be` | Output Mismatch | 0/2 lines match |
| 31 | `stage3d_program_constants_bytearray_le` | Output Mismatch | 0/2 lines match |
| 32 | `stage3d_raytrace` | Output Mismatch | 0/4 lines match |
| 33 | `stage3d_rotating_cube` | Output Mismatch | 0/2 lines match |
| 34 | `stage3d_sampler` | Output Mismatch | 0/2 lines match |
| 35 | `stage3d_sampler_partial_upload` | Output Mismatch | 0/2 lines match |
| 36 | `stage3d_stencil` | Output Mismatch | 0/2 lines match |
| 37 | `stage3d_texture` | Output Mismatch | 0/3 lines match |
| 38 | `stage3d_texture_bytearray` | Output Mismatch | 0/2 lines match |
| 39 | `stage3d_texture_bytearray_compressed_alpha` | Output Mismatch | 0/2 lines match |
| 40 | `stage3d_texture_bytearray_compressed_raw_alpha` | Output Mismatch | 0/2 lines match |
| 41 | `stage3d_triangle` | Output Mismatch | 0/3 lines match |
| 42 | `stage3d_triangle_bytes4` | Output Mismatch | 0/3 lines match |
| 43 | `stage3d_triangle_float1` | Output Mismatch | 0/3 lines match |
| 44 | `stage3d_triangle_index_upload` | Output Mismatch | 0/3 lines match |

## Graphics Improvements (21 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `error_geterrormessage` | Output Mismatch | 0/779 lines match |
| 2 | `jpeg_loader_context` | Output Mismatch | 0/6 lines match |
| 3 | `loader_bitmap_transparency` | Output Mismatch | 1/14 lines match |
| 4 | `loader_bytes_unknown_content` | Output Mismatch | 1/14 lines match |
| 5 | `loader_image` | Output Mismatch | 0/8 lines match |
| 6 | `loader_jpegxr` | Output Mismatch | 0/2 lines match |
| 7 | `loader_jpegxr_alpha` | Output Mismatch | 0/1 lines match |
| 8 | `loader_loadbytes_invalid_png` | Output Mismatch | 0/4 lines match |
| 9 | `loader_method` | Output Mismatch | 16/85 lines match |
| 10 | `loader_unknown_content` | Output Mismatch | 0/24 lines match |
| 11 | `loader_visibility_interactive` | Output Mismatch | 0/1 lines match |
| 12 | `loaderinfo_events` | Output Mismatch | 4/7 lines match |
| 13 | `loaderinfo_loadurl` | Output Mismatch | 8/12 lines match |
| 14 | `loaderinfo_more` | Output Mismatch | 0/6 lines match |
| 15 | `loaderinfo_properties_not_loaded` | Output Mismatch | 15/23 lines match |
| 16 | `navigateToURL_target_normalize` | Output Mismatch | 6/107 lines match |
| 17 | `net_navigateToURL` | Output Mismatch | 4/57 lines match |
| 18 | `stage_loaderinfo_properties` | Output Mismatch | 22/24 lines match |
| 19 | `uncaught_error_basic` | Output Mismatch | 0/2 lines match |
| 20 | `url_loader` | Output Mismatch | 0/25 lines match |
| 21 | `wrong_arg_count` | Output Mismatch | 1/7 lines match |
