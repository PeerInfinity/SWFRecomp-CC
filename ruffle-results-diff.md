# Ruffle Test Results Diff

**Previous:** `360cd1250a3d` (2026-02-13T06:42:45.265241+00:00)
**Current:** `ced90dd8593b` (2026-02-13T07:04:31.534125+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 128 | 129 | +1 |
| Total | 616 | 616 | 0 |
| Pass rate | 20.8% | 20.9% | +0.1% |
| Mismatched lines | 56369 | 56130 | -239 |
|   Decreased | | | -257 |
|   Increased | | | +18 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `issue_1906` | output_mismatch | 2/4 | 4/4 |
| `o` | output_mismatch | 2/3 | 3/3 |
| `swf7_case_sensitive` | output_mismatch | 41/44 | 44/44 |
| `waitforframe` | output_mismatch | 1/7 | 7/7 |
| `waitforframe2` | output_mismatch | 11/16 | 16/16 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `goto_both_ways1` | output_mismatch | 3/3 | 3/3 |
| `goto_both_ways2` | output_mismatch | 3/3 | 3/3 |
| `goto_rewind1` | output_mismatch | 1/1 | 1/1 |
| `goto_rewind3` | output_mismatch | 2/2 | 2/2 |

## Line Count Changed (52)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `textfield_props_swf6` | output_mismatch | 2/210 | 37/210 | -35 |
| `textfield_props_swf7` | output_mismatch | 2/210 | 36/210 | -34 |
| `textfield_props_swf8` | output_mismatch | 2/210 | 36/210 | -34 |
| `edittext_newline_stripping` | output_mismatch | 15/64 | 32/64 | -17 |
| `textfield_props_swf5` | output_mismatch | 21/175 | 37/175 | -16 |
| `textfield_variable` | output_mismatch | 43/81 | 54/81 | -11 |
| `sound_props_swf5` | output_mismatch | 27/68 | 36/68 | -9 |
| `edittext_html_swf6` | output_mismatch | 2006/5377 | 2014/5377 | -8 |
| `edittext_html_swf7` | output_mismatch | 1370/5377 | 1378/5377 | -8 |
| `edittext_html_swf8` | output_mismatch | 1355/5377 | 1363/5377 | -8 |
| `textsnapshot_props_swf5` | output_mismatch | 0/56 | 8/56 | -8 |
| `textfield_properties` | output_mismatch | 26/44 | 32/44 | -6 |
| `edittext_tag_indent` | output_mismatch | 0/31 | 5/31 | -5 |
| `clone_sprite_types` | output_mismatch | 8/24 | 12/24 | -4 |
| `as_set_prop_flags_version` | output_mismatch | 18/31 | 21/31 | -3 |
| `define_function2_preload` | output_mismatch | 9/13 | 12/13 | -3 |
| `sound_props_swf6` | output_mismatch | 28/68 | 31/68 | -3 |
| `swf6_case_insensitive` | output_mismatch | 25/42 | 28/42 | -3 |
| `clone_sprite_edittext` | output_mismatch | 0/94 | 2/94 | -2 |
| `define_function2_preload_order` | output_mismatch | 0/4 | 2/4 | -2 |
| `edittext_autosize_setter` | output_mismatch | 0/20 | 2/20 | -2 |
| `edittext_scroll` | output_mismatch | 31/54 | 33/54 | -2 |
| `remove_movie_clip` | output_mismatch | 7/29 | 9/29 | -2 |
| `conflicting_instance_names` | output_mismatch | 17/23 | 18/23 | -1 |
| `device_font_spacing` | segfault | 0/91 | 1/91 | -1 |
| `edittext_html_condensewhite_swf7` | output_mismatch | 92/311 | 93/311 | -1 |
| `edittext_html_condensewhite_swf8` | output_mismatch | 89/311 | 90/311 | -1 |
| `frame_size_translated_negative` | output_mismatch | 6/21 | 7/21 | -1 |
| `movieclip_name_from_timeline` | output_mismatch | 10/13 | 11/13 | -1 |
| `path_string` | segfault | 43/322 | 44/322 | -1 |
| `stage_object_children` | output_mismatch | 66/83 | 67/83 | -1 |
| `stage_object_properties` | output_mismatch | 53/241 | 54/241 | -1 |
| `stage_object_properties_swf6` | output_mismatch | 53/231 | 54/231 | -1 |
| `swf5_no_closure` | output_mismatch | 1/19 | 2/19 | -1 |
| `tab_ordering_events` | output_mismatch | 1/150 | 2/150 | -1 |
| `textfield_background_color` | output_mismatch | 7/11 | 8/11 | -1 |
| `textfield_border_color` | output_mismatch | 7/11 | 8/11 | -1 |
| `textfield_text` | output_mismatch | 5/7 | 6/7 | -1 |
| `closure_scope` | output_mismatch | 0/7 | 0/7 | 0 |
| `custom_clip_methods` | output_mismatch | 0/4 | 0/4 | 0 |
| `execution_order1` | output_mismatch | 0/5 | 0/5 | 0 |
| `root_global_parent` | output_mismatch | 1/6 | 1/6 | 0 |
| `variable_args` | output_mismatch | 0/5 | 0/5 | 0 |
| `execution_order2` | output_mismatch | 3/7 | 2/7 | +1 |
| `execution_order4` | output_mismatch | 2/12 | 1/12 | +1 |
| `global_proto_decls_delete` | output_mismatch | 1/4158 | 0/4158 | +1 |
| `target_clip_removed` | output_mismatch | 1/5 | 0/5 | +1 |
| `textsnapshot_props_swf6` | output_mismatch | 3/56 | 2/56 | +1 |
| `printjob_props_swf5` | output_mismatch | 3/45 | 0/45 | +3 |
| `printjob_props_swf6` | output_mismatch | 6/45 | 3/45 | +3 |
| `printjob_props_swf7` | output_mismatch | 5/45 | 2/45 | +3 |
| `tell_target` | output_mismatch | 4/37 | 0/37 | +4 |
