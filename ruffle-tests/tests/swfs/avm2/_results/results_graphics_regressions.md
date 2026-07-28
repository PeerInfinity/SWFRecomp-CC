# Graphics vs Trace Mode Differences

Trace: 843/1221 passing | Graphics: 876/1221 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (33 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `cross_api_version_call_older` | Output Mismatch | 0/12 lines match |
| 2 | `displayobject_set_name_loaded` | Output Mismatch | 1/3 lines match |
| 3 | `error_geterrormessage` | Output Mismatch | 0/779 lines match |
| 4 | `jpeg_loader_context` | Output Mismatch | 0/6 lines match |
| 5 | `loader_bitmap_transparency` | Output Mismatch | 1/14 lines match |
| 6 | `loader_bytes_unknown_content` | Output Mismatch | 1/14 lines match |
| 7 | `loader_child_getdefinition` | Output Mismatch | 2/5 lines match |
| 8 | `loader_duplicate_coerce` | Output Mismatch | 1/3 lines match |
| 9 | `loader_duplicate_coerce_new_domain` | Output Mismatch | 1/4 lines match |
| 10 | `loader_error_in_root_ctor` | Output Mismatch | 0/4 lines match |
| 11 | `loader_events` | Output Mismatch | 8/92 lines match |
| 12 | `loader_image` | Output Mismatch | 0/8 lines match |
| 13 | `loader_jpegxr` | Output Mismatch | 0/2 lines match |
| 14 | `loader_jpegxr_alpha` | Output Mismatch | 0/1 lines match |
| 15 | `loader_loadbytes_events` | Output Mismatch | 2/30 lines match |
| 16 | `loader_loadbytes_invalid_png` | Output Mismatch | 0/4 lines match |
| 17 | `loader_loadbytes_url` | Output Mismatch | 1/12 lines match |
| 18 | `loader_loaderurl` | Output Mismatch | 2/6 lines match |
| 19 | `loader_noninteractive_try_click_root` | Output Mismatch | 0/5 lines match |
| 20 | `loader_reuse` | Output Mismatch | 7/38 lines match |
| 21 | `loader_unknown_content` | Output Mismatch | 0/24 lines match |
| 22 | `loader_visibility_interactive` | Output Mismatch | 0/1 lines match |
| 23 | `loaderinfo_events` | Output Mismatch | 4/7 lines match |
| 24 | `loaderinfo_loadurl` | Output Mismatch | 8/12 lines match |
| 25 | `loaderinfo_more` | Output Mismatch | 0/6 lines match |
| 26 | `loaderinfo_properties_not_loaded` | Output Mismatch | 15/23 lines match |
| 27 | `mouse_children` | Output Mismatch | 114/192 lines match |
| 28 | `navigateToURL_target_normalize` | Output Mismatch | 6/107 lines match |
| 29 | `net_navigateToURL` | Output Mismatch | 4/57 lines match |
| 30 | `sandbox_type_inherited` | Output Mismatch | 1/2 lines match |
| 31 | `stage_loaderinfo_properties` | Output Mismatch | 22/24 lines match |
| 32 | `url_loader` | Output Mismatch | 0/25 lines match |
| 33 | `wrong_arg_count` | Output Mismatch | 1/7 lines match |
