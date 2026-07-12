# Ruffle Test Results Diff

**Previous:** `b6fbe84479e3` (2026-07-12T01:06:28.529342+00:00)
**Current:** `f76422459ffa` (2026-07-12T05:29:38.685119+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 639 | 727 | +88 |
| Total | 1201 | 1201 | 0 |
| Pass rate | 53.2% | 60.5% | +7.3% |
| Mismatched lines | 78068 | 62108 | -15960 |
|   Decreased | | | -15960 |

## Newly Passing (88)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `all_classes/security/swf11` | output_mismatch | 0/3 | 3/3 |
| `button_nested_frame` | output_mismatch | 44/48 | 48/48 |
| `cryptscore` | output_mismatch | 0/11 | 11/11 |
| `displayobject_hittestobject` | output_mismatch | 1/32 | 32/32 |
| `edittext_align` | output_mismatch | 0/60 | 60/60 |
| `edittext_antialiastype` | output_mismatch | 5/296 | 296/296 |
| `edittext_autosize` | output_mismatch | 0/39 | 39/39 |
| `edittext_autosize_height_dynamic` | output_mismatch | 0/60 | 60/60 |
| `edittext_autosize_height_input` | output_mismatch | 0/60 | 60/60 |
| `edittext_autosize_lazy_bounds_events` | output_mismatch | 1/65 | 65/65 |
| `edittext_autosize_lazy_bounds_interactions` | output_mismatch | 2/19 | 19/19 |
| `edittext_autosize_lazy_bounds_props` | output_mismatch | 20/490 | 490/490 |
| `edittext_autosize_lazy_bounds_vs_relayout` | output_mismatch | 0/106 | 106/106 |
| `edittext_bottom_scroll_v_basic` | output_mismatch | 0/210 | 210/210 |
| `edittext_bounds_scale` | output_mismatch | 12/24 | 24/24 |
| `edittext_bullet` | output_mismatch | 0/30 | 30/30 |
| `edittext_default_format` | output_mismatch | 0/221 | 221/221 |
| `edittext_default_format_empty` | output_mismatch | 1/136 | 136/136 |
| `edittext_empty_text_format` | output_mismatch | 0/7 | 7/7 |
| `edittext_focus_selection` | output_mismatch | 0/5 | 5/5 |
| `edittext_font_size` | output_mismatch | 0/45 | 45/45 |
| `edittext_format_empty_font` | output_mismatch | 0/8 | 8/8 |
| `edittext_get_line_index_of_char` | output_mismatch | 0/76 | 76/76 |
| `edittext_getcharboundaries` | output_mismatch | 0/172 | 172/172 |
| `edittext_getcharboundaries_missing_glyphs` | output_mismatch | 1/63 | 63/63 |
| `edittext_getcharboundaries_scroll` | output_mismatch | 0/85 | 85/85 |
| `edittext_getlinemetrics` | output_mismatch | 0/146 | 146/146 |
| `edittext_html` | output_mismatch | 0/3101 | 3101/3101 |
| `edittext_html_condensewhite` | output_mismatch | 2/487 | 487/487 |
| `edittext_html_entity` | output_mismatch | 0/4 | 4/4 |
| `edittext_html_font_size_swf12` | output_mismatch | 2/267 | 267/267 |
| `edittext_html_font_size_swf13` | output_mismatch | 2/273 | 273/273 |
| `edittext_html_roundtrip` | output_mismatch | 4/17 | 17/17 |
| `edittext_leading` | output_mismatch | 0/9 | 9/9 |
| `edittext_letter_spacing` | output_mismatch | 0/15 | 15/15 |
| `edittext_line_methods` | output_mismatch | 0/294 | 294/294 |
| `edittext_line_metrics` | output_mismatch | 0/11 | 11/11 |
| `edittext_margins` | output_mismatch | 0/25 | 25/25 |
| `edittext_max_scroll_h_basic` | output_mismatch | 0/475 | 475/475 |
| `edittext_max_scroll_v_basic` | output_mismatch | 0/1000 | 1000/1000 |
| `edittext_newline_stripping` | output_mismatch | 11/64 | 64/64 |
| `edittext_newlines` | output_mismatch | 0/30 | 30/30 |
| `edittext_paragraph_methods` | output_mismatch | 1/257 | 257/257 |
| `edittext_scrollh` | output_mismatch | 3/10 | 10/10 |
| `edittext_set_html_same` | output_mismatch | 0/17 | 17/17 |
| `edittext_set_text_vs_html` | output_mismatch | 0/9 | 9/9 |
| `edittext_stylesheet` | output_mismatch | 0/536 | 536/536 |
| `edittext_stylesheet_custom_tag` | output_mismatch | 0/76 | 76/76 |
| `edittext_stylesheet_display` | output_mismatch | 0/272 | 272/272 |
| `edittext_underline` | output_mismatch | 0/40 | 40/40 |
| `edittext_width_height` | output_mismatch | 0/103 | 103/103 |
| `edittext_wordwrap_word` | output_mismatch | 0/150 | 150/150 |
| `edittext_wrap_breaks` | output_mismatch | 0/2375 | 2375/2375 |
| `empty_bounds` | output_mismatch | 0/1 | 1/1 |
| `focus_remove` | output_mismatch | 8/20 | 20/20 |
| `font_description_clone` | output_mismatch | 0/14 | 14/14 |
| `font_embedded` | output_mismatch | 0/24 | 24/24 |
| `font_enumeratefonts` | output_mismatch | 0/41 | 41/41 |
| `font_enumeratefonts_filter` | output_mismatch | 0/4 | 4/4 |
| `font_hasglyphs` | output_mismatch | 0/40 | 40/40 |
| `get_qualified_super_class_name` | output_mismatch | 0/18 | 18/18 |
| `goto_button_nested_framescript` | output_mismatch | 11/28 | 28/28 |
| `goto_nested_construct_sibling` | output_mismatch | 3/18 | 18/18 |
| `hittest_morph` | output_mismatch | 1/30 | 30/30 |
| `issue_5292` | output_mismatch | 4/5 | 5/5 |
| `movieclip_frameconstruct_skipped` | output_mismatch | 7/9 | 9/9 |
| `movieclip_next_scene` | output_mismatch | 4/6 | 6/6 |
| `movieclip_prev_scene` | output_mismatch | 2/7 | 7/7 |
| `place_object_replace_2` | output_mismatch | 22/24 | 24/24 |
| `register_script_refresh` | output_mismatch | 3/35 | 35/35 |
| `rootless` | output_mismatch | 20/42 | 42/42 |
| `shape_drawrect` | output_mismatch | 2/54 | 54/54 |
| `simplebutton_added_to_stage` | output_mismatch | 18/45 | 45/45 |
| `simplebutton_childevents` | output_mismatch | 2/86 | 86/86 |
| `simplebutton_childevents_nested` | output_mismatch | 5/54 | 54/54 |
| `simplebutton_childevents_sprite` | ruffle_matched | 3/13 | 13/13 |
| `simplebutton_childprops` | output_mismatch | 125/144 | 144/144 |
| `simplebutton_childshuffle` | output_mismatch | 21/23 | 23/23 |
| `simplebutton_constr_childevents` | output_mismatch | 13/48 | 48/48 |
| `simplebutton_symbolclass` | output_mismatch | 6/68 | 68/68 |
| `text_engine_fontdescription` | output_mismatch | 0/27 | 27/27 |
| `text_run` | output_mismatch | 0/7 | 7/7 |
| `textfield_unload` | output_mismatch | 37/39 | 39/39 |
| `textformat` | output_mismatch | 0/1134 | 1134/1134 |
| `textformat_display` | output_mismatch | 0/14 | 14/14 |
| `textformat_font_max_length` | output_mismatch | 0/4 | 4/4 |
| `trace` | output_mismatch | 5/12 | 12/12 |
| `uncaught_errors_stringified` | output_mismatch | 0/3 | 3/3 |

## Status Changed (4)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `edittext_getcharboundaries_culling` | output_mismatch | ruffle_matched | 0/305 | 5/305 |
| `edittext_getcharboundaries_missing_embedded_font` | output_mismatch | ruffle_matched | 1/7 | 4/7 |
| `edittext_tab_stops` | output_mismatch | ruffle_matched | 0/60 | 54/60 |
| `simplebutton_childevents_script_order` | output_mismatch | ruffle_matched | 2/87 | 83/87 |

## Line Count Changed (67)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stylesheet_transform` | output_mismatch | 0/307 | 304/307 | -304 |
| `bounds_mode` | output_mismatch | 2/269 | 233/269 | -231 |
| `stylesheet` | output_mismatch | 0/221 | 220/221 | -220 |
| `selection` | output_mismatch | 10/239 | 229/239 | -219 |
| `edittext_device_transform_layout` | output_mismatch | 1/288 | 160/288 | -159 |
| `stylesheet_parse_color` | output_mismatch | 1/69 | 65/69 | -64 |
| `movieclip_hittest` | output_mismatch | 2/67 | 65/67 | -63 |
| `displayobject_transform` | output_mismatch | 9/89 | 59/89 | -50 |
| `displayobject_hittestpoint_boundary` | output_mismatch | 0/65 | 47/65 | -47 |
| `displayobject_hittestpoint` | output_mismatch | 1/49 | 47/49 | -46 |
| `edittext_tag_indent` | output_mismatch | 1/49 | 38/49 | -37 |
| `simplebutton_childevents_multichild` | output_mismatch | 6/152 | 33/152 | -27 |
| `button_nested_frame_simple` | output_mismatch | 4/27 | 27/27 | -23 |
| `perspective_projection_basic` | output_mismatch | 12/40 | 35/40 | -23 |
| `property_is_enumerable_reset` | output_mismatch | 0/23 | 22/23 | -22 |
| `vector3d` | output_mismatch | 2/397 | 24/397 | -22 |
| `place_and_lookup/swf10` | output_mismatch | 5/33 | 24/33 | -19 |
| `place_and_lookup/swf9` | output_mismatch | 5/33 | 24/33 | -19 |
| `displayobjectcontainer_getobjectsunderpoint` | output_mismatch | 0/15 | 13/15 | -13 |
| `displayobject_scrollrect` | output_mismatch | 0/33 | 9/33 | -9 |
| `error_stack_trace` | output_mismatch | 13/45 | 21/45 | -8 |
| `geom_transform` | output_mismatch | 2/74 | 8/74 | -6 |
| `movieclip_drawrect` | output_mismatch | 2/54 | 8/54 | -6 |
| `font_registerfont` | output_mismatch | 1/129 | 5/129 | -4 |
| `pixelbender_input` | output_mismatch | 0/103 | 4/103 | -4 |
| `displayobject_hittestpoint_root` | output_mismatch | 1/13 | 4/13 | -3 |
| `perspective_projection` | output_mismatch | 1/1443 | 4/1443 | -3 |
| `all_classes/display/swf10` | output_mismatch | 0/2569 | 2/2569 | -2 |
| `all_classes/display/swf11` | output_mismatch | 0/2593 | 2/2593 | -2 |
| `all_classes/display/swf12` | output_mismatch | 0/2593 | 2/2593 | -2 |
| `all_classes/display/swf13` | output_mismatch | 0/2671 | 2/2671 | -2 |
| `all_classes/display/swf9` | output_mismatch | 0/1959 | 2/1959 | -2 |
| `mouse_pick_text` | output_mismatch | 2/8 | 4/8 | -2 |
| `stage_scale_factor` | output_mismatch | 3/12 | 5/12 | -2 |
| `all_classes/display3D/swf12` | output_mismatch | 0/61 | 1/61 | -1 |
| `all_classes/events/swf10` | output_mismatch | 0/1638 | 1/1638 | -1 |
| `all_classes/events/swf11` | output_mismatch | 0/1750 | 1/1750 | -1 |
| `all_classes/events/swf12` | output_mismatch | 0/1814 | 1/1814 | -1 |
| `all_classes/events/swf9` | output_mismatch | 0/1030 | 1/1030 | -1 |
| `bitmapdata_setpixels` | output_mismatch | 0/286 | 1/286 | -1 |
| `button_hittest` | output_mismatch | 0/2 | 1/2 | -1 |
| `matrix3d` | output_mismatch | 0/57 | 1/57 | -1 |
| `sound_load_multiple` | output_mismatch | 0/19 | 1/19 | -1 |
| `textline_validity` | output_mismatch | 0/162 | 1/162 | -1 |
| `timer_reset` | output_mismatch | 0/8 | 1/8 | -1 |
| `all_classes/accessibility/swf10` | output_mismatch | 0/88 | 0/88 | 0 |
| `all_classes/accessibility/swf30` | output_mismatch | 0/88 | 0/88 | 0 |
| `all_classes/accessibility/swf9` | output_mismatch | 0/73 | 0/73 | 0 |
| `all_classes/display/swf30` | output_mismatch | 0/2936 | 0/2936 | 0 |
| `all_classes/display3D/swf13` | output_mismatch | 0/326 | 0/326 | 0 |
| `all_classes/display3D/swf30` | output_mismatch | 0/412 | 0/412 | 0 |
| `all_classes/errors/swf10` | output_mismatch | 0/140 | 0/140 | 0 |
| `all_classes/errors/swf30` | output_mismatch | 0/140 | 0/140 | 0 |
| `all_classes/errors/swf9` | output_mismatch | 0/121 | 0/121 | 0 |
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 0/2353 | 0 |
| `all_classes/security/swf12` | output_mismatch | 0/19 | 0/19 | 0 |
| `all_classes/security/swf13` | output_mismatch | 0/53 | 0/53 | 0 |
| `all_classes/security/swf30` | output_mismatch | 0/53 | 0/53 | 0 |
| `all_classes/xml/swf30` | output_mismatch | 0/116 | 0/116 | 0 |
| `all_classes/xml/swf9` | output_mismatch | 0/116 | 0/116 | 0 |
| `button_bounds` | output_mismatch | 0/1 | 0/1 | 0 |
| `drop_shadow_filter` | output_mismatch | 4/172 | 4/172 | 0 |
| `edittext_ime_focus_lost` | output_mismatch | 0/9 | 0/9 | 0 |
| `filter_rewind` | output_mismatch | 0/8 | 0/8 | 0 |
| `pixelbender_padding_bytes` | output_mismatch | 0/22 | 0/22 | 0 |
| `pixelbender_param_qualifier` | output_mismatch | 0/512 | 0/512 | 0 |
| `pixelbender_select_kinds` | output_mismatch | 0/8 | 0/8 | 0 |
