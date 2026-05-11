# Ruffle Test Results Diff

**Previous:** `f8745996297b` (2026-05-11T00:07:44.422828+00:00)
**Current:** `f1b087ec6a6b` (2026-05-11T00:46:00.138405+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 524 | 565 | +41 |
| Total | 651 | 651 | 0 |
| Pass rate | 80.5% | 86.8% | +6.3% |
| Mismatched lines | 10586 | 9532 | -1054 |
|   Decreased | | | -1159 |
|   Increased | | | +105 |

## Newly Passing (42)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `cross_movie_root` | output_mismatch | 0/10 | 10/10 |
| `edittext_ime_focus_lost` | output_mismatch | 0/7 | 7/7 |
| `focusrect_property_swf5` | output_mismatch | 1236/1237 | 1237/1237 |
| `focusrect_property_swf7` | output_mismatch | 1236/1237 | 1237/1237 |
| `form_loader_encoding_1` | output_mismatch | 1/1 | 1/1 |
| `issue_2084` | output_mismatch | 16/16 | 16/16 |
| `issue_2870` | output_mismatch | 1/3 | 3/3 |
| `loadmovie` | output_mismatch | 1/2 | 2/2 |
| `loadmovie_flashvars` | output_mismatch | 1/4 | 4/4 |
| `loadmovie_method` | output_mismatch | 1/2 | 2/2 |
| `loadmovie_registerclass` | output_mismatch | 0/30 | 30/30 |
| `loadmovie_replace_root` | output_mismatch | 5/5 | 5/5 |
| `loadmovie_var_persistence` | output_mismatch | 2/8 | 8/8 |
| `loadmovienum` | output_mismatch | 1/3 | 3/3 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 1/9 | 9/9 |
| `loadvariables2` | output_mismatch | 2/8 | 8/8 |
| `lock_root` | output_mismatch | 0/1 | 1/1 |
| `mcl_getprogress` | output_mismatch | 0/30 | 30/30 |
| `movieclip_invalid_get_bounds_1` | output_mismatch | 9/75 | 75/75 |
| `movieclip_invalid_get_bounds_2` | output_mismatch | 9/75 | 75/75 |
| `movieclip_invalid_get_bounds_3` | output_mismatch | 4/13 | 13/13 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | 4/13 | 13/13 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | 4/11 | 11/11 |
| `movieclip_invalid_get_bounds_6` | output_mismatch | 2/10 | 10/10 |
| `movieclip_invalid_get_bounds_7` | output_mismatch | 2/10 | 10/10 |
| `movieclip_invalid_get_bounds_8` | output_mismatch | 4/11 | 11/11 |
| `movieclip_lockroot` | output_mismatch | 16/29 | 29/29 |
| `movieclip_methods_with_loaded_image` | output_mismatch | 0/4 | 4/4 |
| `movieclip_state_values` | output_mismatch | 11/114 | 114/114 |
| `netstream_play_flv` | output_mismatch | 2/21 | 21/21 |
| `register_class_swf6` | output_mismatch | 0/37 | 37/37 |
| `resolve_different_root` | output_mismatch | 0/2 | 2/2 |
| `set_interval` | output_mismatch | 17/27 | 27/27 |
| `sound_duration_position_props` | output_mismatch | 38/290 | 290/290 |
| `sound_load_start` | output_mismatch | 0/3 | 3/3 |
| `sound_multiple_load` | output_mismatch | 0/1 | 1/1 |
| `swf5_to_6_cross_call` | output_mismatch | 0/29 | 29/29 |
| `swf5_xml_event_handler_context` | output_mismatch | 0/2 | 2/2 |
| `swf6_to_5_cross_call` | output_mismatch | 0/29 | 29/29 |
| `textfield_cache_as_bitmap` | output_mismatch | 1/1 | 1/1 |
| `unloadmovie` | output_mismatch | 1/4 | 4/4 |
| `unloadmovie_method` | output_mismatch | 1/3 | 3/3 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `mcl_unloadclip` | output_mismatch | 5/5 | 5/5 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `form_loader_encoding_4` | output_mismatch | ruffle_matched | 1/3 | 1/3 |
| `movieclip_library_state_values` | output_mismatch | ruffle_matched | 70/78 | 76/78 |
| `native_objects_swf6` | output_mismatch | segfault | 114/115 | 9/115 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `localconnection` | output_mismatch | 111/579 | 433/579 | -322 |
| `netstream_seek_flv` | output_mismatch | 0/25 | 25/25 | -25 |
| `unloadmovienum` | output_mismatch | 6/13 | 13/13 | -7 |
| `focusrect_property_swf6` | output_mismatch | 1235/1237 | 1236/1237 | -1 |
| `form_loader_encoding_3` | output_mismatch | 1/3 | 1/3 | 0 |
| `load_cancel_via_removemovieclip` | output_mismatch | 2/4 | 2/4 | 0 |
| `load_cancel_via_unloadmovie` | ruffle_matched | 5/5 | 5/5 | 0 |
| `netconnection_send_remote` | output_mismatch | 2/50 | 2/50 | 0 |
