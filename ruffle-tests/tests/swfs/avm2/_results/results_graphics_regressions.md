# Graphics vs Trace Mode Differences

Trace: 1180/1261 passing | Graphics: 1198/1261 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (18 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `bitmapdata_applyfilter_identity` | Output Mismatch | 2/4 lines match |
| 2 | `bitmapdata_copypixels_alpha_combine` | Output Mismatch | 2/13 lines match |
| 3 | `flash_ui_mouse_cursor` | Output Mismatch | 1/35 lines match |
| 4 | `large_preload_from_bytes` | Output Mismatch | 41/51 lines match |
| 5 | `loader_try_click_root` | Output Mismatch | 0/26 lines match |
| 6 | `matrix3d_append_prepend_scale` | Output Mismatch | 0/86 lines match |
| 7 | `matrix3d_copy_from` | Output Mismatch | 15/19 lines match |
| 8 | `matrix3d_copy_to_matrix3d` | Output Mismatch | 15/19 lines match |
| 9 | `matrix3d_interpolate` | Output Mismatch | 0/21 lines match |
| 10 | `movieclip_addframescript_error` | Output Mismatch | 0/9 lines match |
| 11 | `orphan_removeobject` | Output Mismatch | 340/641 lines match |
| 12 | `primitive_keys` | Output Mismatch | 33/54 lines match |
| 13 | `simplebutton_soundtransform` | Output Mismatch | 829/887 lines match |
| 14 | `soundmixer_soundtransform` | Output Mismatch | 888/900 lines match |
| 15 | `stage_display_state` | Output Mismatch | 0/6 lines match |
| 16 | `stage_scale_factor` | Output Mismatch | 6/12 lines match |
| 17 | `vector3d_near_equals` | Output Mismatch | 67/80 lines match |
| 18 | `xml_duplicate_attribute` | Output Mismatch | 7/14 lines match |
