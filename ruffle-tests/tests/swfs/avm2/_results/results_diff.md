# Ruffle Test Results Diff

**Previous:** `6841590f69b9` (2026-07-11T20:21:10.232204+00:00)
**Current:** `b6fbe84479e3` (2026-07-12T01:06:28.529342+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 476 | 639 | +163 |
| Total | 1201 | 1201 | 0 |
| Pass rate | 39.6% | 53.2% | +13.6% |
| Mismatched lines | 97599 | 78068 | -19531 |
|   Decreased | | | -19552 |
|   Increased | | | +21 |

## Newly Passing (163)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmapdata_copychannel` | runtime_error | 0/0 | 0/0 |
| `broadcast_event` | output_mismatch | 0/7 | 7/7 |
| `construct_frame_list` | output_mismatch | 2/22 | 22/22 |
| `constructors_vs_timeline` | output_mismatch | 1/5 | 5/5 |
| `displayobject_alpha` | output_mismatch | 276/277 | 277/277 |
| `displayobject_from_enterframe` | output_mismatch | 0/1 | 1/1 |
| `displayobject_height` | output_mismatch | 2/6052 | 6052/6052 |
| `displayobject_invalid_floats` | output_mismatch | 0/60 | 60/60 |
| `displayobject_invalid_props` | output_mismatch | 0/3 | 3/3 |
| `displayobject_mask` | output_mismatch | 0/3 | 3/3 |
| `displayobject_metaData` | output_mismatch | 0/3 | 3/3 |
| `displayobject_name` | output_mismatch | 1/22 | 22/22 |
| `displayobject_name_from_timeline` | output_mismatch | 3/24 | 24/24 |
| `displayobject_parent` | output_mismatch | 0/12 | 12/12 |
| `displayobject_root` | output_mismatch | 2/24 | 24/24 |
| `displayobject_rotation` | output_mismatch | 1271/1275 | 1275/1275 |
| `displayobject_subclass` | output_mismatch | 0/2 | 2/2 |
| `displayobject_visible` | output_mismatch | 1/23 | 23/23 |
| `displayobject_width` | output_mismatch | 2/4852 | 4852/4852 |
| `displayobject_x` | output_mismatch | 36/614 | 614/614 |
| `displayobject_y` | output_mismatch | 39/617 | 617/617 |
| `displayobjectcontainer_addchild` | output_mismatch | 1/32 | 32/32 |
| `displayobjectcontainer_addchild_lazy_sprite` | output_mismatch | 0/1 | 1/1 |
| `displayobjectcontainer_addchild_timelinepull0` | output_mismatch | 1/58 | 58/58 |
| `displayobjectcontainer_addchild_timelinepull1` | output_mismatch | 1/60 | 60/60 |
| `displayobjectcontainer_addchild_timelinepull2` | output_mismatch | 1/62 | 62/62 |
| `displayobjectcontainer_addchildat` | output_mismatch | 1/42 | 42/42 |
| `displayobjectcontainer_addchildat_timelinelock0` | output_mismatch | 1/34 | 34/34 |
| `displayobjectcontainer_addchildat_timelinelock1` | output_mismatch | 1/34 | 34/34 |
| `displayobjectcontainer_addchildat_timelinelock2` | output_mismatch | 1/34 | 34/34 |
| `displayobjectcontainer_contains` | output_mismatch | 1/66 | 66/66 |
| `displayobjectcontainer_getchildat` | output_mismatch | 1/4 | 4/4 |
| `displayobjectcontainer_getchildbyname` | output_mismatch | 1/9 | 9/9 |
| `displayobjectcontainer_getchildbyname_wrongcase` | output_mismatch | 1/5 | 5/5 |
| `displayobjectcontainer_getchildindex` | output_mismatch | 1/28 | 28/28 |
| `displayobjectcontainer_removechild` | output_mismatch | 1/10 | 10/10 |
| `displayobjectcontainer_removechild_errors` | output_mismatch | 2/4 | 4/4 |
| `displayobjectcontainer_removechild_timelinemanip_remove1` | output_mismatch | 1/38 | 38/38 |
| `displayobjectcontainer_removechildat` | output_mismatch | 1/18 | 18/18 |
| `displayobjectcontainer_removechildren` | output_mismatch | 1/51 | 51/51 |
| `displayobjectcontainer_setchildindex` | output_mismatch | 1/42 | 42/42 |
| `displayobjectcontainer_stopallmovieclips` | output_mismatch | 0/2 | 2/2 |
| `displayobjectcontainer_swapchildren` | output_mismatch | 1/42 | 42/42 |
| `displayobjectcontainer_swapchildrenat` | output_mismatch | 1/42 | 42/42 |
| `displayobjectcontainer_timelineinstance` | output_mismatch | 5/48 | 48/48 |
| `documentclass` | output_mismatch | 0/9 | 9/9 |
| `edit_text_linkage` | output_mismatch | 0/7 | 7/7 |
| `edittext_mouseenabled` | output_mismatch | 1/26 | 26/26 |
| `event_clone` | output_mismatch | 6/20 | 20/20 |
| `event_clone_error_redispatch` | output_mismatch | 1/3 | 3/3 |
| `event_clone_on_redispatch` | output_mismatch | 2/10 | 10/10 |
| `event_formattostring` | output_mismatch | 3/31 | 31/31 |
| `event_handler_exception` | output_mismatch | 0/4 | 4/4 |
| `event_isdefaultprevented` | output_mismatch | 2/12 | 12/12 |
| `event_target_getter` | output_mismatch | 1/5 | 5/5 |
| `event_target_set` | output_mismatch | 1/9 | 9/9 |
| `event_valueof_tostring` | output_mismatch | 14/18 | 18/18 |
| `eventdispatcher_dispatchevent` | output_mismatch | 9/12 | 12/12 |
| `eventdispatcher_dispatchevent_cancel` | output_mismatch | 9/20 | 20/20 |
| `eventdispatcher_dispatchevent_handlerorder` | output_mismatch | 15/22 | 22/22 |
| `eventdispatcher_dispatchevent_indirect` | output_mismatch | 1/9 | 9/9 |
| `eventdispatcher_interface_invoke` | output_mismatch | 0/1 | 1/1 |
| `eventdispatcher_tostring` | output_mismatch | 8/10 | 10/10 |
| `eventdispatcher_willtrigger` | output_mismatch | 3/25 | 25/25 |
| `framelabel_constr` | output_mismatch | 1/5 | 5/5 |
| `goto_in_constructframe` | output_mismatch | 1/12 | 12/12 |
| `goto_in_scene_last_frame` | output_mismatch | 1/2 | 2/2 |
| `goto_methods` | output_mismatch | 1/56 | 56/56 |
| `goto_methods_swfver10` | output_mismatch | 1/8 | 8/8 |
| `goto_nested_framescript` | output_mismatch | 0/9 | 9/9 |
| `goto_on_orphan` | output_mismatch | 0/15 | 15/15 |
| `graphics_bitmap_fill` | runtime_error | 0/0 | 0/0 |
| `instantiation_on_enter_frame` | output_mismatch | 0/7 | 7/7 |
| `instantiation_on_enterframe_gotoandstop` | output_mismatch | 0/8 | 8/8 |
| `interactiveobject_enabled` | output_mismatch | 22/25 | 25/25 |
| `issue_8630` | output_mismatch | 1/2 | 2/2 |
| `issue_8630_scriptremove` | output_mismatch | 0/11 | 11/11 |
| `mask_reapply` | output_mismatch | 0/1 | 1/1 |
| `movieclip_addframescript` | output_mismatch | 1/3 | 3/3 |
| `movieclip_child_property` | output_mismatch | 2/16 | 16/16 |
| `movieclip_constr` | output_mismatch | 6/21 | 21/21 |
| `movieclip_currentlabels` | output_mismatch | 1/17 | 17/17 |
| `movieclip_currentlabels_dupes1` | output_mismatch | 1/46 | 46/46 |
| `movieclip_currentlabels_dupes2` | output_mismatch | 1/30 | 30/30 |
| `movieclip_currentlabels_dupes3` | output_mismatch | 1/67 | 67/67 |
| `movieclip_currentscene` | output_mismatch | 1/12 | 12/12 |
| `movieclip_dispatchevent` | output_mismatch | 2/430 | 430/430 |
| `movieclip_dispatchevent_cancel` | output_mismatch | 2/102 | 102/102 |
| `movieclip_dispatchevent_handlerorder` | output_mismatch | 2/251 | 251/251 |
| `movieclip_dispatchevent_selfadd` | output_mismatch | 2/80 | 80/80 |
| `movieclip_dispatchevent_target` | output_mismatch | 2/899 | 899/899 |
| `movieclip_displayevents` | output_mismatch | 2/96 | 96/96 |
| `movieclip_displayevents_constructframegoto` | output_mismatch | 0/140 | 140/140 |
| `movieclip_displayevents_constructframeplay` | output_mismatch | 0/50 | 50/50 |
| `movieclip_displayevents_constructframesymbol` | output_mismatch | 0/144 | 144/144 |
| `movieclip_displayevents_dblhandler` | output_mismatch | 0/21 | 21/21 |
| `movieclip_displayevents_enterframegoto` | output_mismatch | 0/149 | 149/149 |
| `movieclip_displayevents_enterframeplay` | output_mismatch | 0/48 | 48/48 |
| `movieclip_displayevents_enterframesymbol` | output_mismatch | 0/149 | 149/149 |
| `movieclip_displayevents_exitframegoto` | output_mismatch | 0/106 | 106/106 |
| `movieclip_displayevents_exitframeplay` | output_mismatch | 0/44 | 44/44 |
| `movieclip_displayevents_exitframesymbol` | output_mismatch | 0/135 | 135/135 |
| `movieclip_displayevents_looping` | output_mismatch | 0/63 | 63/63 |
| `movieclip_displayevents_stopped` | output_mismatch | 1/113 | 113/113 |
| `movieclip_displayevents_swap` | output_mismatch | 2/96 | 96/96 |
| `movieclip_displayevents_timeline` | output_mismatch | 0/128 | 128/128 |
| `movieclip_goto_during_frame_script` | output_mismatch | 2/15 | 15/15 |
| `movieclip_goto_overwrite` | output_mismatch | 2/14 | 14/14 |
| `movieclip_goto_scene_last_frame_int` | output_mismatch | 0/1 | 1/1 |
| `movieclip_goto_scene_last_frame_label` | output_mismatch | 0/1 | 1/1 |
| `movieclip_gotoandplay` | output_mismatch | 2/15 | 15/15 |
| `movieclip_gotoandstop` | output_mismatch | 2/13 | 13/13 |
| `movieclip_gotoandstop_children` | output_mismatch | 1/4 | 4/4 |
| `movieclip_gotoandstop_framescripts1` | output_mismatch | 1/4 | 4/4 |
| `movieclip_gotoandstop_framescripts2` | output_mismatch | 1/4 | 4/4 |
| `movieclip_gotoandstop_framescripts_self` | output_mismatch | 1/7 | 7/7 |
| `movieclip_gotoandstop_queueing` | output_mismatch | 2/12 | 12/12 |
| `movieclip_next_frame` | output_mismatch | 1/2 | 2/2 |
| `movieclip_play` | output_mismatch | 1/3 | 3/3 |
| `movieclip_prev_frame` | output_mismatch | 1/3 | 3/3 |
| `movieclip_properties` | output_mismatch | 10/79 | 79/79 |
| `movieclip_queued_noop_goto_swf10` | output_mismatch | 0/9 | 9/9 |
| `movieclip_queued_noop_goto_swf9` | output_mismatch | 0/7 | 7/7 |
| `movieclip_scenes` | output_mismatch | 1/11 | 11/11 |
| `movieclip_super_is_symbol` | output_mismatch | 14/20 | 20/20 |
| `movieclip_symbol_constr` | output_mismatch | 3/8 | 8/8 |
| `movieclip_willtrigger` | output_mismatch | 0/5 | 5/5 |
| `nan_scale` | output_mismatch | 2/9 | 9/9 |
| `orphan_movie_complex` | output_mismatch | 0/80 | 80/80 |
| `orphan_movie_reorder` | output_mismatch | 2/111 | 111/111 |
| `parent_early_access_child` | output_mismatch | 0/16 | 16/16 |
| `place_multiple` | output_mismatch | 0/17 | 17/17 |
| `place_object_replace` | output_mismatch | 1/9 | 9/9 |
| `place_object_same_depth_frame` | output_mismatch | 1/1 | 1/1 |
| `remove_child_clear_field` | output_mismatch | 0/88 | 88/88 |
| `remove_dobj` | output_mismatch | 1/3 | 3/3 |
| `scene_constr` | output_mismatch | 1/8 | 8/8 |
| `simplebutton_constr` | output_mismatch | 1/36 | 36/36 |
| `simplebutton_constr_params` | output_mismatch | 1/42 | 42/42 |
| `simplebutton_mouseenabled` | output_mismatch | 1/26 | 26/26 |
| `simplebutton_multi_children` | output_mismatch | 0/19 | 19/19 |
| `simplebutton_structure` | output_mismatch | 0/27 | 27/27 |
| `stage3d_rotating_cube` | runtime_error | 0/0 | 0/0 |
| `stage_access` | output_mismatch | 3/10 | 10/10 |
| `stage_displayobject_properties` | output_mismatch | 1/24 | 24/24 |
| `stage_framerate_nan` | output_mismatch | 1/7 | 7/7 |
| `stage_framerate_negative` | output_mismatch | 1/6 | 6/6 |
| `stage_framerate_zero` | output_mismatch | 1/6 | 6/6 |
| `stage_invalidate` | output_mismatch | 0/38 | 38/38 |
| `stage_mouseenabled` | output_mismatch | 2/15 | 15/15 |
| `stage_overriden_setters` | output_mismatch | 0/31 | 31/31 |
| `stage_properties` | output_mismatch | 1/30 | 30/30 |
| `stage_properties2` | output_mismatch | 0/8 | 8/8 |
| `swf_10_queued_goto_scripts_construct` | output_mismatch | 0/52 | 52/52 |
| `swf_9_goto_in_enter_frame` | output_mismatch | 1/17 | 17/17 |
| `swf_9_goto_in_enter_frame_simple` | output_mismatch | 1/15 | 15/15 |
| `swf_9_queued_goto_scripts` | output_mismatch | 0/6 | 6/6 |
| `swf_9_queued_goto_scripts_construct` | output_mismatch | 0/28 | 28/28 |
| `swf_wrong_frame_count` | output_mismatch | 2/38 | 38/38 |
| `swf_wrong_frame_count_isplaying` | output_mismatch | 0/22 | 22/22 |
| `symbol_class_conflict` | output_mismatch | 0/4 | 4/4 |
| `timeline_scripts` | output_mismatch | 1/3 | 3/3 |
| `zero_frame_clip` | output_mismatch | 0/3 | 3/3 |

## Status Changed (11)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `array_access_oob_interpreter` | runtime_error | ruffle_matched | 0/1 | 0/1 |
| `bitmap_subclass` | runtime_error | output_mismatch | 0/7 | 0/7 |
| `bitmap_subclass_properties` | runtime_error | output_mismatch | 0/9 | 0/9 |
| `content_element_basic` | runtime_error | output_mismatch | 0/50 | 0/50 |
| `dictionary_weak_keys` | output_mismatch | ruffle_matched | 0/2 | 1/2 |
| `error_1034_debug_string` | output_mismatch | ruffle_matched | 0/30 | 11/30 |
| `goto_framescript_queued` | output_mismatch | ruffle_matched | 0/6 | 1/6 |
| `goto_nested_construct_sibling` | runtime_error | output_mismatch | 1/18 | 3/18 |
| `simplebutton_childevents_sprite` | output_mismatch | ruffle_matched | 0/13 | 3/13 |
| `supercalls_weird` | runtime_error | output_mismatch | 0/2 | 0/2 |
| `swf_9_goto_in_construct_frame` | output_mismatch | ruffle_matched | 1/20 | 8/20 |

## Line Count Changed (110)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `tab_ordering_properties` | output_mismatch | 0/732 | 559/732 | -559 |
| `orphan_removeobject` | output_mismatch | 0/636 | 340/636 | -340 |
| `simplebutton_childprops` | output_mismatch | 0/144 | 125/144 | -125 |
| `focusrect_property` | output_mismatch | 0/110 | 104/110 | -104 |
| `movieclip_displayevents_clickgoto2` | output_mismatch | 0/2001 | 65/2001 | -65 |
| `movieclip_displayevents_clicksymbol` | output_mismatch | 0/562 | 59/562 | -59 |
| `movieclip_displayevents_clickgoto` | output_mismatch | 0/676 | 54/676 | -54 |
| `button_nested_frame` | output_mismatch | 2/48 | 44/48 | -42 |
| `textfield_unload` | output_mismatch | 1/39 | 37/39 | -36 |
| `movieclip_displayevents_clickplay` | output_mismatch | 0/575 | 24/575 | -24 |
| `place_object_replace_2` | output_mismatch | 1/24 | 22/24 | -21 |
| `edittext_autosize_lazy_bounds_props` | output_mismatch | 0/490 | 20/490 | -20 |
| `rootless` | output_mismatch | 0/42 | 20/42 | -20 |
| `simplebutton_childshuffle` | output_mismatch | 2/23 | 21/23 | -19 |
| `simplebutton_added_to_stage` | output_mismatch | 0/45 | 18/45 | -18 |
| `issue_8630_placeremoveplace` | output_mismatch | 0/15 | 13/15 | -13 |
| `issue_8630_placeremoveplace_scriptremove` | output_mismatch | 0/16 | 13/16 | -13 |
| `simplebutton_constr_childevents` | output_mismatch | 1/48 | 13/48 | -12 |
| `edittext_bounds_scale` | output_mismatch | 1/24 | 12/24 | -11 |
| `goto_button_nested_framescript` | output_mismatch | 0/28 | 11/28 | -11 |
| `perspective_projection_basic` | output_mismatch | 1/40 | 12/40 | -11 |
| `edittext_newline_stripping` | output_mismatch | 1/64 | 11/64 | -10 |
| `selection` | output_mismatch | 0/239 | 10/239 | -10 |
| `displayobject_transform` | output_mismatch | 0/89 | 9/89 | -9 |
| `matrix` | output_mismatch | 0/338 | 9/338 | -9 |
| `focus_remove` | output_mismatch | 1/20 | 8/20 | -7 |
| `graphic_linkage` | output_mismatch | 0/9 | 7/9 | -7 |
| `convolution_filter` | output_mismatch | 1/89 | 7/89 | -6 |
| `displacement_map_filter` | output_mismatch | 1/61 | 7/61 | -6 |
| `movieclip_frameconstruct_skipped` | output_mismatch | 1/9 | 7/9 | -6 |
| `simplebutton_childevents_multichild` | output_mismatch | 0/152 | 6/152 | -6 |
| `displayobject_opaque_background` | output_mismatch | 0/6 | 5/6 | -5 |
| `place_and_lookup/swf10` | output_mismatch | 0/33 | 5/33 | -5 |
| `place_and_lookup/swf9` | output_mismatch | 0/33 | 5/33 | -5 |
| `simplebutton_childevents_nested` | output_mismatch | 0/54 | 5/54 | -5 |
| `tab_ordering_stage_tab_children` | output_mismatch | 0/32 | 5/32 | -5 |
| `displayobject_filters` | output_mismatch | 1/17 | 5/17 | -4 |
| `edittext_antialiastype` | output_mismatch | 1/296 | 5/296 | -4 |
| `simplebutton_soundtransform` | output_mismatch | 1/887 | 5/887 | -4 |
| `bevel_filter` | output_mismatch | 1/187 | 4/187 | -3 |
| `blur_filter` | output_mismatch | 1/43 | 4/43 | -3 |
| `color_matrix_filter` | output_mismatch | 1/19 | 4/19 | -3 |
| `drop_shadow_filter` | output_mismatch | 1/172 | 4/172 | -3 |
| `edittext_html_roundtrip` | output_mismatch | 1/17 | 4/17 | -3 |
| `edittext_scrollh` | output_mismatch | 0/10 | 3/10 | -3 |
| `glow_filter` | output_mismatch | 1/127 | 4/127 | -3 |
| `gradient_bevel_filter` | output_mismatch | 1/206 | 4/206 | -3 |
| `gradient_glow_filter` | output_mismatch | 1/206 | 4/206 | -3 |
| `loaderinfo_root` | output_mismatch | 0/10 | 3/10 | -3 |
| `movieclip_next_scene` | output_mismatch | 1/6 | 4/6 | -3 |
| `simplebutton_symbolclass` | output_mismatch | 3/68 | 6/68 | -3 |
| `stage_scale_factor` | output_mismatch | 0/12 | 3/12 | -3 |
| `tab_ordering_stage_tab_children_remove_root` | output_mismatch | 0/5 | 3/5 | -3 |
| `button_nested_frame_simple` | output_mismatch | 2/27 | 4/27 | -2 |
| `edittext_autosize_lazy_bounds_interactions` | output_mismatch | 0/19 | 2/19 | -2 |
| `edittext_html_condensewhite` | output_mismatch | 0/487 | 2/487 | -2 |
| `edittext_html_font_size_swf12` | output_mismatch | 0/267 | 2/267 | -2 |
| `edittext_html_font_size_swf13` | output_mismatch | 0/273 | 2/273 | -2 |
| `mouse_pick_text` | output_mismatch | 0/8 | 2/8 | -2 |
| `movieclip_soundtransform` | output_mismatch | 1/831 | 3/831 | -2 |
| `register_script_refresh` | output_mismatch | 1/35 | 3/35 | -2 |
| `sound_rootless` | output_mismatch | 0/7 | 2/7 | -2 |
| `soundmixer_soundtransform` | output_mismatch | 1/900 | 3/900 | -2 |
| `displayobject_hittestpoint_root` | output_mismatch | 0/13 | 1/13 | -1 |
| `displayobject_set_name_loaded` | output_mismatch | 0/3 | 1/3 | -1 |
| `edittext_autosize_lazy_bounds_events` | output_mismatch | 0/65 | 1/65 | -1 |
| `edittext_device_transform_layout` | output_mismatch | 0/288 | 1/288 | -1 |
| `edittext_getcharboundaries_missing_embedded_font` | output_mismatch | 0/7 | 1/7 | -1 |
| `edittext_getcharboundaries_missing_glyphs` | output_mismatch | 0/63 | 1/63 | -1 |
| `edittext_paragraph_methods` | output_mismatch | 0/257 | 1/257 | -1 |
| `edittext_tag_indent` | output_mismatch | 0/49 | 1/49 | -1 |
| `geom_transform` | output_mismatch | 1/74 | 2/74 | -1 |
| `movieclip_prev_scene` | output_mismatch | 1/7 | 2/7 | -1 |
| `shape_drawrect` | output_mismatch | 1/54 | 2/54 | -1 |
| `simplebutton_childevents` | output_mismatch | 1/86 | 2/86 | -1 |
| `simplebutton_childevents_script_order` | output_mismatch | 1/87 | 2/87 | -1 |
| `tab_ordering_arrows` | output_mismatch | 0/998 | 1/998 | -1 |
| `tab_ordering_automatic_advanced` | output_mismatch | 0/184 | 1/184 | -1 |
| `verification` | output_mismatch | 4/8 | 5/8 | -1 |
| `delayed_symbolclass` | output_mismatch | 0/28 | 0/28 | 0 |
| `displayobject_early_init` | output_mismatch | 0/54 | 0/54 | 0 |
| `displayobject_hittestpoint` | output_mismatch | 1/49 | 1/49 | 0 |
| `doabc_and_symbolclass_script_init_goto` | output_mismatch | 1/7 | 1/7 | 0 |
| `doabc_and_symbolclass_script_init_normal` | output_mismatch | 1/6 | 1/6 | 0 |
| `edittext_focus_selection` | output_mismatch | 0/5 | 0/5 | 0 |
| `loaderinfo_properties` | output_mismatch | 1/18 | 1/18 | 0 |
| `morph_shape` | output_mismatch | 0/2 | 0/2 | 0 |
| `netstream_seek_flv` | output_mismatch | 0/49 | 0/49 | 0 |
| `stage_loaderinfo_properties` | output_mismatch | 1/24 | 1/24 | 0 |
| `static_text` | output_mismatch | 0/3 | 0/3 | 0 |
| `statictext_text` | output_mismatch | 0/8 | 0/8 | 0 |
| `bitmap_constr` | output_mismatch | 1/17 | 0/17 | +1 |
| `bitmap_properties` | output_mismatch | 1/23 | 0/23 | +1 |
| `bitmap_timeline` | output_mismatch | 1/9 | 0/9 | +1 |
| `bitmapdata_clone` | output_mismatch | 1/13 | 0/13 | +1 |
| `bitmapdata_constr` | output_mismatch | 1/22 | 0/22 | +1 |
| `bitmapdata_embedded` | output_mismatch | 1/9 | 0/9 | +1 |
| `bitmapdata_zero_size` | output_mismatch | 1/5 | 0/5 | +1 |
| `font_embedded` | output_mismatch | 1/24 | 0/24 | +1 |
| `font_enumeratefonts` | output_mismatch | 1/41 | 0/41 | +1 |
| `font_hasglyphs` | output_mismatch | 1/40 | 0/40 | +1 |
| `sound_embeddedprops` | output_mismatch | 1/26 | 0/26 | +1 |
| `sound_play` | output_mismatch | 1/19 | 0/19 | +1 |
| `sound_valueof` | output_mismatch | 1/33 | 0/33 | +1 |
| `soundchannel_soundcomplete` | output_mismatch | 1/16 | 0/16 | +1 |
| `soundchannel_soundtransform` | output_mismatch | 1/835 | 0/835 | +1 |
| `soundchannel_stop` | output_mismatch | 1/8 | 0/8 | +1 |
| `soundmixer_buffertime` | output_mismatch | 1/5 | 0/5 | +1 |
| `soundmixer_stopall` | output_mismatch | 1/6 | 0/6 | +1 |
| `subclass_superclass_linked_symbol` | output_mismatch | 3/4 | 0/4 | +3 |
