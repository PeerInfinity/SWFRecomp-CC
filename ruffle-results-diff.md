# Ruffle Test Results Diff

**Previous:** `711e25ad1e38` (2026-02-15T01:31:32.330879+00:00)
**Current:** `c616aeb4c13b` (2026-02-15T02:29:13.233456+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 196 | 197 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 31.7% | 31.8% | +0.1% |
| Mismatched lines | 50592 | 46950 | -3642 |
|   Decreased | | | -3786 |
|   Increased | | | +144 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `movieclip_blend_mode_property` | output_mismatch | 24/35 | 35/35 |
| `movieclip_default_state` | output_mismatch | 13/69 | 69/69 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `target_path` | output_mismatch | 14/14 | 11/14 |

## Status Changed (5)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `device_font_spacing` | timeout | segfault | - | 1/91 |
| `init_object_order` | output_mismatch | segfault | 1/15 | 1/15 |
| `register_and_init_order` | output_mismatch | segfault | 30/231 | 27/231 |
| `register_class` | output_mismatch | segfault | 2/66 | - |
| `tab_ordering_tabbable` | segfault | output_mismatch | - | 0/47 |

## Line Count Changed (39)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_html_swf7` | output_mismatch | 1380/5377 | 2268/5377 | -888 |
| `edittext_html_swf8` | output_mismatch | 1365/5377 | 2118/5377 | -753 |
| `edittext_html_swf6` | output_mismatch | 2016/5377 | 2640/5377 | -624 |
| `focusrect_property_swf6` | output_mismatch | 211/1237 | 718/1237 | -507 |
| `focusrect_property_swf7` | output_mismatch | 210/1237 | 717/1237 | -507 |
| `edittext_html_condensewhite_swf7` | output_mismatch | 94/311 | 174/311 | -80 |
| `edittext_html_condensewhite_swf8` | output_mismatch | 91/311 | 171/311 | -80 |
| `edittext_width_height` | output_mismatch | 63/103 | 97/103 | -34 |
| `focusrect_property_swf5` | output_mismatch | 209/1237 | 239/1237 | -30 |
| `movieclip_getbounds` | output_mismatch | 25/191 | 45/191 | -20 |
| `movieclip_focusenabled` | output_mismatch | 53/99 | 71/99 | -18 |
| `string_methods` | output_mismatch | 172/285 | 188/285 | -16 |
| `edittext_stylesheet` | output_mismatch | 66/325 | 79/325 | -13 |
| `hittest_morph` | output_mismatch | 3/70 | 15/70 | -12 |
| `movieclip_depth_methods` | output_mismatch | 65/98 | 76/98 | -11 |
| `string_methods_swfv5` | output_mismatch | 171/275 | 181/275 | -10 |
| `stage_object_properties` | output_mismatch | 165/241 | 173/241 | -8 |
| `stage_object_properties_swf6` | output_mismatch | 158/231 | 166/231 | -8 |
| `edittext_autosize` | output_mismatch | 39/71 | 44/71 | -5 |
| `hittest_lockroot` | output_mismatch | 1/15 | 6/15 | -5 |
| `string_paths_other` | output_mismatch | 6/36 | 11/36 | -5 |
| `movieclip_gettextsnapshot` | output_mismatch | 1/112 | 4/112 | -3 |
| `named_shapes` | output_mismatch | 6/14 | 9/14 | -3 |
| `unload` | output_mismatch | 5/52 | 8/52 | -3 |
| `global_proto_decls` | output_mismatch | 2/4497 | 4/4497 | -2 |
| `remove_movie_clip` | output_mismatch | 17/29 | 19/29 | -2 |
| `transform` | output_mismatch | 48/70 | 50/70 | -2 |
| `clone_sprite_types` | output_mismatch | 13/24 | 14/24 | -1 |
| `create_empty_movie_clip` | output_mismatch | 1/3 | 2/3 | -1 |
| `focus_visibility_change` | output_mismatch | 2/45 | 3/45 | -1 |
| `movieclip_lockroot` | output_mismatch | 15/29 | 16/29 | -1 |
| `string_paths_basic` | output_mismatch | 1/4 | 2/4 | -1 |
| `string_paths_variable_alias` | output_mismatch | 1/4 | 2/4 | -1 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `native_objects_swf6` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf7` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf8` | output_mismatch | 0/84 | 0/84 | 0 |
| `string_paths_hidden` | output_mismatch | 35/54 | 34/54 | +1 |
