# Ruffle Test Results Diff

**Previous:** `0612bc78e68a` (2026-07-30T15:55:17.699460+00:00)
**Current:** `1ca0ab117c5a` (2026-07-30T17:36:27.606080+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 993 | 997 | +4 |
| Total | 1221 | 1222 | +1 |
| Pass rate | 81.3% | 81.6% | +0.3% |
| Mismatched lines | 38235 | 35751 | -2484 |
|   Decreased | | | -2498 |
|   Increased | | | +9 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `flash_media_video_constructor` | output_mismatch | 25/156 | 156/156 |
| `loader_method` | output_mismatch | 83/85 | 85/85 |
| `matrix3d` | output_mismatch | 19/57 | 57/57 |
| `matrix3d_compose` | output_mismatch | 0/34 | 34/34 |
| `perspective_projection_basic` | output_mismatch | 35/40 | 40/40 |
| `uncaught_error_basic` | output_mismatch | 0/2 | 2/2 |
| `utils3d` | output_mismatch | 0/7 | 7/7 |
| `vector3d` | output_mismatch | 24/397 | 397/397 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `away3d_advanced_shallow_water_demo` | output_mismatch | 0/0 | 0/0 |
| `font_enumeratefonts` | output_mismatch | 41/41 | 41/41 |
| `stage3d_raytrace` | output_mismatch | 0/0 | 0/0 |
| `stage3d_texture` | output_mismatch | 0/0 | 0/0 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `xml_list_delete_clear_parent` | output_mismatch | 1/6 |

## Line Count Changed (79)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `perspective_projection` | output_mismatch | 4/1443 | 1368/1443 | -1364 |
| `rectangle` | output_mismatch | 1/1094 | 447/1094 | -446 |
| `flash_media_video_setter` | output_mismatch | 1/40 | 33/40 | -32 |
| `loader_duplicate_class` | output_mismatch | 3/48 | 23/48 | -20 |
| `flash_media_video_rotation_probe` | output_mismatch | 1/27 | 20/27 | -19 |
| `textline_validity` | output_mismatch | 1/162 | 7/162 | -6 |
| `event_handler_exception` | output_mismatch | 1/11 | 5/11 | -4 |
| `bitmapdata_zero_size` | output_mismatch | 5/8 | 7/8 | -2 |
| `loader_load` | output_mismatch | 124/128 | 126/128 | -2 |
| `all_classes/display/swf10` | output_mismatch | 1/2569 | 2/2569 | -1 |
| `all_classes/display/swf11` | output_mismatch | 1/2593 | 2/2593 | -1 |
| `all_classes/display/swf12` | output_mismatch | 1/2593 | 2/2593 | -1 |
| `all_classes/display/swf13` | output_mismatch | 1/2671 | 2/2671 | -1 |
| `all_classes/events/swf30` | output_mismatch | 1/2353 | 2/2353 | -1 |
| `matrix` | output_mismatch | 281/338 | 282/338 | -1 |
| `netstream_flv_date` | output_mismatch | 1/4 | 2/4 | -1 |
| `place_and_lookup/swf10` | output_mismatch | 29/33 | 30/33 | -1 |
| `place_and_lookup/swf9` | output_mismatch | 29/33 | 30/33 | -1 |
| `uncaught_errors_stringified` | output_mismatch | 1/18 | 2/18 | -1 |
| `verify_illegal_opcode` | output_mismatch | 0/1 | 1/1 | -1 |
| `abstract_classes` | output_mismatch | 0/132 | 0/132 | 0 |
| `accessibility` | output_mismatch | 0/1 | 0/1 | 0 |
| `accessibilityimplementation` | output_mismatch | 0/18 | 0/18 | 0 |
| `air_ifilepromise` | output_mismatch | 0/1 | 0/1 | 0 |
| `all_classes/display/swf30` | output_mismatch | 0/2936 | 0/2936 | 0 |
| `all_classes/display/swf9` | output_mismatch | 2/1959 | 2/1959 | 0 |
| `all_classes/events/swf10` | output_mismatch | 1/1638 | 1/1638 | 0 |
| `all_classes/events/swf11` | output_mismatch | 1/1750 | 1/1750 | 0 |
| `all_classes/events/swf12` | output_mismatch | 1/1814 | 1/1814 | 0 |
| `all_classes/events/swf9` | output_mismatch | 1/1030 | 1/1030 | 0 |
| `appdomain_lookup_edge_cases` | output_mismatch | 7/32 | 7/32 | 0 |
| `applicationdomain_getqualifieddefinitionnames` | output_mismatch | 0/9 | 0/9 | 0 |
| `array_access_oob_interpreter` | ruffle_matched | 0/1 | 0/1 | 0 |
| `audio_computespectrum` | output_mismatch | 0/118 | 0/118 | 0 |
| `av_tag_data` | output_mismatch | 0/2 | 0/2 | 0 |
| `avm1_root` | output_mismatch | 0/58 | 0/58 | 0 |
| `coerce_property` | ruffle_matched | 33/36 | 33/36 | 0 |
| `content_element_basic` | output_mismatch | 0/50 | 0/50 | 0 |
| `currency_parse_result` | output_mismatch | 0/7 | 0/7 | 0 |
| `describe_type_json` | output_mismatch | 1/301 | 1/301 | 0 |
| `displayobject_getrect` | output_mismatch | 2/16 | 2/16 | 0 |
| `displayobjectcontainer_getobjectsunderpoint` | output_mismatch | 13/15 | 13/15 | 0 |
| `east_asian_justifier_clone` | output_mismatch | 0/8 | 0/8 | 0 |
| `element_format_clone` | output_mismatch | 0/44 | 0/44 | 0 |
| `element_format_properties` | output_mismatch | 0/235 | 0/235 | 0 |
| `escape_multi_byte` | output_mismatch | 1/45 | 1/45 | 0 |
| `external_interface` | output_mismatch | 3/105 | 3/105 | 0 |
| `font_enumeratefonts_order` | output_mismatch | 0/9 | 0/9 | 0 |
| `game_input` | output_mismatch | 0/4 | 0/4 | 0 |
| `generate_random_bytes` | output_mismatch | 0/3 | 0/3 | 0 |
| `geom_transform` | output_mismatch | 20/74 | 20/74 | 0 |
| `getouterscope_two_classobjects` | output_mismatch | 8/13 | 8/13 | 0 |
| `large_preload_from_bytes` | output_mismatch | 18/51 | 18/51 | 0 |
| `native_menu_basic` | output_mismatch | 0/19 | 0/19 | 0 |
| `netfilterevent` | output_mismatch | 0/10 | 0/10 | 0 |
| `print_job_options` | output_mismatch | 0/3 | 0/3 | 0 |
| `property_is_enumerable` | output_mismatch | 25/114 | 25/114 | 0 |
| `property_priority_definition_names_order` | output_mismatch | 0/2 | 0/2 | 0 |
| `scopes_dont_cache/order-1` | output_mismatch | 0/1 | 0/1 | 0 |
| `scopes_dont_cache/order-2` | output_mismatch | 0/1 | 0/1 | 0 |
| `security_domain_current` | output_mismatch | 0/2 | 0/2 | 0 |
| `sound_load_multiple` | output_mismatch | 3/19 | 3/19 | 0 |
| `space_justifier_clone` | output_mismatch | 0/12 | 0/12 | 0 |
| `stage_display_state` | output_mismatch | 0/6 | 0/6 | 0 |
| `stage_domain_getQualifiedDefinitionNames` | output_mismatch | 1/5 | 1/5 | 0 |
| `supercalls_weird` | output_mismatch | 0/2 | 0/2 | 0 |
| `superinterface_call` | output_mismatch | 15/20 | 15/20 | 0 |
| `tabstop_properties` | output_mismatch | 0/105 | 0/105 | 0 |
| `text_element_basic` | output_mismatch | 0/34 | 0/34 | 0 |
| `text_engine_groupelement` | output_mismatch | 1/64 | 1/64 | 0 |
| `textblock_createline_errors` | output_mismatch | 0/23 | 0/23 | 0 |
| `textblock_createline_fte` | output_mismatch | 0/9 | 0/9 | 0 |
| `textblock_properties` | output_mismatch | 0/118 | 0/118 | 0 |
| `textline_inapplicable_properties` | output_mismatch | 0/10 | 0/10 | 0 |
| `textline_name` | output_mismatch | 0/1 | 0/1 | 0 |
| `textline_splitting_basic` | output_mismatch | 0/76 | 0/76 | 0 |
| `textline_throwerror` | output_mismatch | 0/30 | 0/30 | 0 |
| `url_vars` | output_mismatch | 3/27 | 3/27 | 0 |
| `sprite_dropTarget` | ruffle_matched | 15/19 | 6/19 | +9 |
