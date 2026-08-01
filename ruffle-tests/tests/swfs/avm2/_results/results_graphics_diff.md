# Ruffle Test Results Diff

**Previous:** `2ab0c01beab9` (2026-08-01T00:14:14.549662+00:00)
**Current:** `73c786e3fa45` (2026-08-01T02:48:45.537950+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1052 | 1068 | +16 |
| Total | 1224 | 1224 | 0 |
| Pass rate | 85.9% | 87.3% | +1.4% |
| Mismatched lines | 33574 | 33380 | -194 |
|   Decreased | | | -204 |
|   Increased | | | +10 |

## Newly Passing (16)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `activation_class` | output_mismatch | 3/6 | 6/6 |
| `bitmapdata_zero_size` | output_mismatch | 5/8 | 8/8 |
| `encode_uri_surrogate_pair_invalid` | output_mismatch | 0/8 | 8/8 |
| `flash_media_video_setter` | output_mismatch | 36/40 | 40/40 |
| `font_enumeratefonts_order` | output_mismatch | 0/9 | 9/9 |
| `font_registerfont` | output_mismatch | 8/129 | 129/129 |
| `getouterscope_two_classobjects` | output_mismatch | 8/13 | 13/13 |
| `instantiate_root_character` | output_mismatch | 3/4 | 4/4 |
| `invalid_utf8` | output_mismatch | 11/12 | 12/12 |
| `issue_8630_placeremoveplace` | output_mismatch | 13/15 | 15/15 |
| `loader_method` | output_mismatch | 83/85 | 85/85 |
| `parse_float_swf10` | output_mismatch | 79/81 | 81/81 |
| `stylesheet` | output_mismatch | 220/221 | 221/221 |
| `system_setclipboard_null` | output_mismatch | 0/1 | 1/1 |
| `uncaught_error_basic` | output_mismatch | 0/2 | 2/2 |
| `verify_illegal_opcode` | output_mismatch | 0/1 | 1/1 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `uncaught_errors_stringified` | output_mismatch | ruffle_matched | 1/18 | 3/18 |

## Line Count Changed (33)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `loader_duplicate_class` | output_mismatch | 3/48 | 23/48 | -20 |
| `event_handler_exception` | output_mismatch | 1/11 | 5/11 | -4 |
| `all_classes/events/swf10` | output_mismatch | 1/1638 | 3/1638 | -2 |
| `all_classes/events/swf11` | output_mismatch | 1/1750 | 3/1750 | -2 |
| `all_classes/events/swf12` | output_mismatch | 1/1814 | 3/1814 | -2 |
| `issue_8630_placeremoveplace_scriptremove` | output_mismatch | 13/16 | 15/16 | -2 |
| `loader_load` | output_mismatch | 124/128 | 126/128 | -2 |
| `all_classes/events/swf9` | output_mismatch | 1/1030 | 2/1030 | -1 |
| `freestanding_superclass` | ruffle_matched | 1/4 | 2/4 | -1 |
| `accessibilityimplementation` | output_mismatch | 0/18 | 0/18 | 0 |
| `appdomain_lookup_edge_cases` | output_mismatch | 7/32 | 7/32 | 0 |
| `array_access_oob_interpreter` | ruffle_matched | 0/1 | 0/1 | 0 |
| `audio_computespectrum` | output_mismatch | 0/118 | 0/118 | 0 |
| `avm1_root` | output_mismatch | 0/58 | 0/58 | 0 |
| `coerce_property` | ruffle_matched | 33/36 | 33/36 | 0 |
| `currency_parse_result` | output_mismatch | 0/7 | 0/7 | 0 |
| `describe_type_json` | output_mismatch | 1/301 | 1/301 | 0 |
| `displayobject_getrect` | output_mismatch | 2/16 | 2/16 | 0 |
| `escape_multi_byte` | output_mismatch | 1/45 | 1/45 | 0 |
| `external_interface` | output_mismatch | 3/105 | 3/105 | 0 |
| `geom_transform` | output_mismatch | 20/74 | 20/74 | 0 |
| `large_preload_from_bytes` | output_mismatch | 18/51 | 18/51 | 0 |
| `matrix` | output_mismatch | 282/338 | 282/338 | 0 |
| `native_menu_basic` | output_mismatch | 0/19 | 0/19 | 0 |
| `netfilterevent` | output_mismatch | 0/10 | 0/10 | 0 |
| `property_is_enumerable` | output_mismatch | 25/114 | 25/114 | 0 |
| `sound_load_multiple` | output_mismatch | 3/19 | 3/19 | 0 |
| `stage_display_state` | output_mismatch | 0/6 | 0/6 | 0 |
| `supercalls_weird` | output_mismatch | 0/2 | 0/2 | 0 |
| `superinterface_call` | output_mismatch | 15/20 | 15/20 | 0 |
| `url_vars` | output_mismatch | 3/27 | 3/27 | 0 |
| `all_classes/events/swf30` | output_mismatch | 2/2353 | 1/2353 | +1 |
| `sprite_dropTarget` | ruffle_matched | 15/19 | 6/19 | +9 |
