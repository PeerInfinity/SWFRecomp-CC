# Graphics vs Trace Mode Differences

Trace: 843/1221 passing | Graphics: 860/1221 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (17 tests)

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
| 9 | `loader_unknown_content` | Output Mismatch | 0/24 lines match |
| 10 | `loader_visibility_interactive` | Output Mismatch | 0/1 lines match |
| 11 | `loaderinfo_events` | Output Mismatch | 4/7 lines match |
| 12 | `loaderinfo_loadurl` | Output Mismatch | 8/12 lines match |
| 13 | `loaderinfo_more` | Output Mismatch | 0/6 lines match |
| 14 | `loaderinfo_properties_not_loaded` | Output Mismatch | 15/23 lines match |
| 15 | `stage_loaderinfo_properties` | Output Mismatch | 22/24 lines match |
| 16 | `url_loader` | Output Mismatch | 0/25 lines match |
| 17 | `wrong_arg_count` | Output Mismatch | 1/7 lines match |
