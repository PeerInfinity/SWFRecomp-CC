# Ruffle Test Results Diff

**Previous:** `8ec3f4779e37` (2026-04-26T20:52:13.108200+00:00)
**Current:** `1f111219fa91` (2026-04-26T22:53:16.449862+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 597 | 547 | -50 |
| Total | 641 | 641 | 0 |
| Pass rate | 93.1% | 85.3% | -7.8% |
| Mismatched lines | 8898 | 8887 | -11 |
|   Decreased | | | -11 |

## Newly Failing (50)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `cross_movie_root` | compile_fail | 10/10 | - |
| `depth_replacement_audio_unloading` | compile_fail | 3/3 | - |
| `do_init_action_child` | compile_fail | 12/12 | - |
| `focusrect_property_swf5` | compile_fail | 1237/1237 | - |
| `focusrect_property_swf6` | compile_fail | 1237/1237 | - |
| `focusrect_property_swf7` | compile_fail | 1237/1237 | - |
| `global_swf5_6_7_8_9` | compile_fail | 1145/1145 | - |
| `global_swf6_7_8` | compile_fail | 15/15 | - |
| `hittest_winding_rule` | compile_fail | 12/12 | - |
| `instanceof_coercions` | compile_fail | 88/88 | - |
| `interface_implements_op` | compile_fail | 47/47 | - |
| `issue_2870` | compile_fail | 3/3 | - |
| `loadmovie` | compile_fail | 2/2 | - |
| `loadmovie_flashvars` | compile_fail | 4/4 | - |
| `loadmovie_method` | compile_fail | 2/2 | - |
| `loadmovie_registerclass` | compile_fail | 30/30 | - |
| `loadmovie_replace_root` | compile_fail | 5/5 | - |
| `loadmovie_var_persistence` | compile_fail | 8/8 | - |
| `loadmovienum` | compile_fail | 3/3 | - |
| `loadmovienum_cross_version_prototype` | compile_fail | 9/9 | - |
| `lock_root` | compile_fail | 1/1 | - |
| `mcl_events_swf_version` | compile_fail | 232/232 | - |
| `mcl_getprogress` | compile_fail | 30/30 | - |
| `mcl_loadclip` | compile_fail | 149/149 | - |
| `mcl_loadclip_properties` | compile_fail | 6/6 | - |
| `mcl_loadclip_replace_root` | compile_fail | 1/1 | - |
| `mcl_unloadclip` | compile_fail | 5/5 | - |
| `movieclip_blend_mode_property` | compile_fail | 35/35 | - |
| `movieclip_invalid_get_bounds_1` | compile_fail | 75/75 | - |
| `movieclip_invalid_get_bounds_2` | compile_fail | 75/75 | - |
| `movieclip_invalid_get_bounds_3` | compile_fail | 13/13 | - |
| `movieclip_invalid_get_bounds_4` | compile_fail | 13/13 | - |
| `movieclip_invalid_get_bounds_5` | compile_fail | 11/11 | - |
| `movieclip_invalid_get_bounds_6` | compile_fail | 10/10 | - |
| `movieclip_invalid_get_bounds_7` | compile_fail | 10/10 | - |
| `movieclip_invalid_get_bounds_8` | compile_fail | 11/11 | - |
| `movieclip_lockroot` | compile_fail | 29/29 | - |
| `movieclip_state_values` | compile_fail | 114/114 | - |
| `moviecliploader_flashvars` | compile_fail | 4/4 | - |
| `register_class` | compile_fail | 66/66 | - |
| `register_class_swf6` | compile_fail | 37/37 | - |
| `register_class_with_sound` | compile_fail | 11/11 | - |
| `resolve_different_root` | compile_fail | 2/2 | - |
| `string_paths_eval2` | compile_fail | 7/7 | - |
| `swf5_to_6_cross_call` | compile_fail | 29/29 | - |
| `swf5_xml_event_handler_context` | compile_fail | 2/2 | - |
| `swf6_to_5_cross_call` | compile_fail | 29/29 | - |
| `unloadmovie` | compile_fail | 4/4 | - |
| `unloadmovie_method` | compile_fail | 3/3 | - |
| `unloadmovienum` | compile_fail | 13/13 | - |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_filters` | output_mismatch | compile_fail | 539/548 | - |
| `mcl_replace_root_swf7_to_swf5` | ruffle_matched | compile_fail | 56/57 | - |
| `mcl_replace_root_swf7_to_swf6` | ruffle_matched | compile_fail | 56/57 | - |
