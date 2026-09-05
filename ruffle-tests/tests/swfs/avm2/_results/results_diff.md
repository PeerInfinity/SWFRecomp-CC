# Ruffle Test Results Diff

**Previous:** `f0fd711c7126` (2026-09-04T21:08:44.203861+00:00)
**Current:** `7f7a6ba36937` (2026-09-05T04:40:58.146765+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1180 | 1198 | +18 |
| Total | 1261 | 1261 | 0 |
| Pass rate | 93.6% | 95.0% | +1.4% |
| Mismatched lines | 3649 | 2875 | -774 |
|   Decreased | | | -774 |

## Newly Passing (18)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmapdata_applyfilter_identity` | output_mismatch | 2/4 | 4/4 |
| `bitmapdata_copypixels_alpha_combine` | output_mismatch | 2/13 | 13/13 |
| `flash_ui_mouse_cursor` | output_mismatch | 1/35 | 35/35 |
| `large_preload_from_bytes` | output_mismatch | 41/51 | 51/51 |
| `loader_try_click_root` | output_mismatch | 0/16 | 16/16 |
| `matrix3d_append_prepend_scale` | output_mismatch | 0/86 | 86/86 |
| `matrix3d_copy_from` | output_mismatch | 15/19 | 19/19 |
| `matrix3d_copy_to_matrix3d` | output_mismatch | 15/19 | 19/19 |
| `matrix3d_interpolate` | output_mismatch | 0/21 | 21/21 |
| `movieclip_addframescript_error` | output_mismatch | 0/9 | 9/9 |
| `orphan_removeobject` | output_mismatch | 340/636 | 636/636 |
| `primitive_keys` | output_mismatch | 33/54 | 54/54 |
| `simplebutton_soundtransform` | output_mismatch | 829/887 | 887/887 |
| `soundmixer_soundtransform` | output_mismatch | 888/900 | 900/900 |
| `stage_display_state` | output_mismatch | 0/6 | 6/6 |
| `stage_scale_factor` | output_mismatch | 6/12 | 12/12 |
| `vector3d_near_equals` | output_mismatch | 67/80 | 80/80 |
| `xml_duplicate_attribute` | output_mismatch | 7/14 | 14/14 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmapdata_copypixels_alpha_merge` | output_mismatch | ruffle_matched | 3/9 | 5/9 |
| `event_handler_exception` | output_mismatch | ruffle_matched | 5/11 | 7/11 |
| `number_convert_errors` | output_mismatch | ruffle_matched | 40/871 | 165/871 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `loader_duplicate_class` | output_mismatch | 3/48 | 32/48 | -29 |
