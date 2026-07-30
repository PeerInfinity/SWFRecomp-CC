# Ruffle Test Results Diff

**Previous:** `1ca0ab117c5a` (2026-07-30T17:36:27.606080+00:00)
**Current:** `2358a37b1cc0` (2026-07-30T18:36:08.275785+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 997 | 1000 | +3 |
| Total | 1222 | 1222 | 0 |
| Pass rate | 81.6% | 81.8% | +0.2% |
| Mismatched lines | 35751 | 35129 | -622 |
|   Decreased | | | -656 |
|   Increased | | | +34 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `away3d_advanced_shallow_water_demo` | output_mismatch | 0/0 | 0/0 |
| `font_enumeratefonts` | output_mismatch | 41/41 | 41/41 |
| `rectangle` | output_mismatch | 447/1094 | 1094/1094 |
| `stage3d_raytrace` | output_mismatch | 0/0 | 0/0 |
| `stage3d_texture` | output_mismatch | 0/0 | 0/0 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `loader_method` | output_mismatch | 85/85 | 83/85 |
| `uncaught_error_basic` | output_mismatch | 2/2 | 0/2 |

## Line Count Changed (61)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `sprite_dropTarget` | ruffle_matched | 6/19 | 15/19 | -9 |
| `abstract_classes` | output_mismatch | 0/132 | 0/132 | 0 |
| `accessibility` | output_mismatch | 0/1 | 0/1 | 0 |
| `accessibilityimplementation` | output_mismatch | 0/18 | 0/18 | 0 |
| `air_ifilepromise` | output_mismatch | 0/1 | 0/1 | 0 |
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
| `matrix` | output_mismatch | 282/338 | 282/338 | 0 |
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
| `textline_validity` | output_mismatch | 7/162 | 7/162 | 0 |
| `url_vars` | output_mismatch | 3/27 | 3/27 | 0 |
| `uncaught_errors_stringified` | output_mismatch | 2/18 | 1/18 | +1 |
| `verify_illegal_opcode` | output_mismatch | 1/1 | 0/1 | +1 |
| `bitmapdata_zero_size` | output_mismatch | 7/8 | 5/8 | +2 |
| `loader_load` | output_mismatch | 126/128 | 124/128 | +2 |
| `event_handler_exception` | output_mismatch | 5/11 | 1/11 | +4 |
| `loader_duplicate_class` | output_mismatch | 23/48 | 3/48 | +20 |
