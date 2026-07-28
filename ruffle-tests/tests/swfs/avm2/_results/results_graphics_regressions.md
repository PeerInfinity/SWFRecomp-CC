# Graphics vs Trace Mode Differences

Trace: 843/1221 passing | Graphics: 900/1221 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (57 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `cross_api_version_call_older` | Output Mismatch | 0/12 lines match |
| 2 | `displayobject_set_name_loaded` | Output Mismatch | 1/3 lines match |
| 3 | `edittext_ime_focus_lost` | Output Mismatch | 0/9 lines match |
| 4 | `edittext_mouse_selection` | Output Mismatch | 334/363 lines match |
| 5 | `error_geterrormessage` | Output Mismatch | 0/779 lines match |
| 6 | `focus_events_key_basic` | Output Mismatch | 33/148 lines match |
| 7 | `focus_events_key_navigation` | Output Mismatch | 12/53 lines match |
| 8 | `focus_events_mouse_basic` | Output Mismatch | 30/260 lines match |
| 9 | `focus_events_mouse_focusable` | Output Mismatch | 110/112 lines match |
| 10 | `focusrect_focuslost` | Output Mismatch | 7/9 lines match |
| 11 | `focusrect_property` | Output Mismatch | 104/110 lines match |
| 12 | `ime_linux_dead_keys` | Output Mismatch | 0/13 lines match |
| 13 | `jpeg_loader_context` | Output Mismatch | 0/6 lines match |
| 14 | `loader_bitmap_transparency` | Output Mismatch | 1/14 lines match |
| 15 | `loader_bytes_unknown_content` | Output Mismatch | 1/14 lines match |
| 16 | `loader_child_getdefinition` | Output Mismatch | 2/5 lines match |
| 17 | `loader_duplicate_coerce` | Output Mismatch | 1/3 lines match |
| 18 | `loader_duplicate_coerce_new_domain` | Output Mismatch | 1/4 lines match |
| 19 | `loader_error_in_root_ctor` | Output Mismatch | 0/4 lines match |
| 20 | `loader_events` | Output Mismatch | 8/92 lines match |
| 21 | `loader_image` | Output Mismatch | 0/8 lines match |
| 22 | `loader_jpegxr` | Output Mismatch | 0/2 lines match |
| 23 | `loader_jpegxr_alpha` | Output Mismatch | 0/1 lines match |
| 24 | `loader_loadbytes_events` | Output Mismatch | 2/30 lines match |
| 25 | `loader_loadbytes_invalid_png` | Output Mismatch | 0/4 lines match |
| 26 | `loader_loadbytes_url` | Output Mismatch | 1/12 lines match |
| 27 | `loader_loaderurl` | Output Mismatch | 2/6 lines match |
| 28 | `loader_noninteractive_try_click_root` | Output Mismatch | 0/5 lines match |
| 29 | `loader_reuse` | Output Mismatch | 7/38 lines match |
| 30 | `loader_unknown_content` | Output Mismatch | 0/24 lines match |
| 31 | `loader_visibility_interactive` | Output Mismatch | 0/1 lines match |
| 32 | `loaderinfo_events` | Output Mismatch | 4/7 lines match |
| 33 | `loaderinfo_loadurl` | Output Mismatch | 8/12 lines match |
| 34 | `loaderinfo_more` | Output Mismatch | 0/6 lines match |
| 35 | `loaderinfo_properties_not_loaded` | Output Mismatch | 15/23 lines match |
| 36 | `mouse_children` | Output Mismatch | 114/192 lines match |
| 37 | `mouse_pick_dobj_mask` | Output Mismatch | 2/4 lines match |
| 38 | `mouse_pick_masking` | Output Mismatch | 0/7 lines match |
| 39 | `mouse_pick_non_interactive_bitmap_mask` | Output Mismatch | 2/4 lines match |
| 40 | `mouse_pick_non_interactive_dobj_mask` | Output Mismatch | 0/3 lines match |
| 41 | `mouse_pick_text` | Output Mismatch | 4/9 lines match |
| 42 | `mouse_wheel_events` | Output Mismatch | 29/36 lines match |
| 43 | `mouseevent_constr` | Output Mismatch | 62/66 lines match |
| 44 | `mouseevent_stagexy` | Output Mismatch | 1/35 lines match |
| 45 | `mouseevent_valueof_tostring` | Output Mismatch | 24/28 lines match |
| 46 | `navigateToURL_target_normalize` | Output Mismatch | 6/107 lines match |
| 47 | `net_navigateToURL` | Output Mismatch | 4/57 lines match |
| 48 | `sandbox_type_inherited` | Output Mismatch | 1/2 lines match |
| 49 | `selection` | Output Mismatch | 229/239 lines match |
| 50 | `stage_loaderinfo_properties` | Output Mismatch | 22/24 lines match |
| 51 | `tab_ordering_stage_tab_children` | Output Mismatch | 15/35 lines match |
| 52 | `tab_ordering_stage_tab_children_remove_root` | Output Mismatch | 3/5 lines match |
| 53 | `tab_ordering_tabbable` | Output Mismatch | 45/47 lines match |
| 54 | `textbox_click` | Output Mismatch | 1/37 lines match |
| 55 | `textfield_event` | Output Mismatch | 0/66 lines match |
| 56 | `url_loader` | Output Mismatch | 0/25 lines match |
| 57 | `wrong_arg_count` | Output Mismatch | 1/7 lines match |
