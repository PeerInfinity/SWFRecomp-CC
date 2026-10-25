# Graphics vs Trace Mode Differences

Trace: 0/104 passing | Graphics: 104/104 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (104 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `array_element_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 2 | `array_method_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 3 | `avm1_attach_clipevent_enterframe` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 4 | `avm1_child_timeline_advance` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 5 | `avm1_child_timeline_frame1_stop` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 6 | `avm1_child_timeline_holder_stop` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 7 | `avm1_child_timeline_loop` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 8 | `avm1_closure_method_scope` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 9 | `avm1_display_prop_coercion` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 10 | `avm1_mcl_holder_totalframes` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 11 | `avm1_mcl_load_tick` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 12 | `avm1_parent_as3_child_payload` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 13 | `avm1_parent_child_bitmap` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 14 | `avm1_parent_child_bitmap_fill` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 15 | `avm1_parent_child_modify_place` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 16 | `avm1_parent_child_morph` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 17 | `avm1_parent_child_render` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 18 | `avm1_parent_child_sprite_meta` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 19 | `avm1_parent_child_text` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 20 | `avm1_root_identity_and_playhead` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 21 | `avm2_activation_vtable_bounded` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 22 | `avm2_agi_shell` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 23 | `avm2_array_growth_bounded` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 24 | `avm2_bitmapdata_draw_textfield` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 25 | `avm2_child_simplebutton` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 26 | `avm2_contextmenu_stub` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 27 | `avm2_e4x_parse_bounded` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 28 | `avm2_embed_bytearray` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 29 | `avm2_external_interface_unavailable` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 30 | `avm2_findprop_this_resolution` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 31 | `avm2_gc_dynprop_tombstone_purge` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 32 | `avm2_gc_string_concat_reclaim` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 33 | `avm2_gc_string_survives_collect` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 34 | `avm2_goto_catchup_scale` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 35 | `avm2_graphics_runtime` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 36 | `avm2_json_roundtrip_bounded` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 37 | `avm2_loader_stub` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 38 | `avm2_localconnection_domain` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 39 | `avm2_morph` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 40 | `avm2_parent_child_render` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 41 | `avm2_parent_child_static_text` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 42 | `avm2_parent_child_symbol_stride` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 43 | `avm2_parent_child_symbolclass_domain` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 44 | `avm2_reflect_trait_hooks` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 45 | `avm2_sharedobject_flushstatus` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 46 | `avm2_simplebutton_click` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 47 | `avm2_slot_default_template` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 48 | `avm2_sound_bytes_and_group_format` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 49 | `avm2_static_and_store_slots` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 50 | `avm2_static_text` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 51 | `avm2_strbuf_stale_prefix` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 52 | `avm2_timeline_gradients` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 53 | `avm2_timeline_solid` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 54 | `avm2_timeline_stroke_gradient` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 55 | `avm2_timeline_text` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 56 | `avm2_tolerant_verify_quarantine` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 57 | `avm2_typed_value_ops` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 58 | `bitmap_pool_layer_cap` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 59 | `broadcast_cross_swf_version` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 60 | `broadcast_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 61 | `coerce_cross_swf_version` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 62 | `coerce_recursion_guard` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 63 | `coerce_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 64 | `convertfloat_type1_this` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 65 | `ctor_before_first_call_locals` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 66 | `ei_closure_scope_order` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 67 | `ei_cross_swf_version` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 68 | `ei_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 69 | `enterframe_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 70 | `fn_call_builtin_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 71 | `fn_call_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 72 | `fn_empty_method_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 73 | `lc_method_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 74 | `lc_onstatus_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 75 | `lv_cross_swf_version` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 76 | `lv_ondata_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 77 | `mask_nested_intersect` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 78 | `mask_sibling_union` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 79 | `mc_event_cross_swf_version` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 80 | `mc_event_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 81 | `mc_method_v5_caller_gate` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 82 | `mc_resolve_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 83 | `method_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 84 | `nc_onstatus_closure` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 85 | `nc_onstatus_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 86 | `onconstruct_cross_swf_version` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 87 | `onconstruct_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 88 | `onload_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 89 | `onunload_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 90 | `onunload_type1_local_frame` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 91 | `resolve_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 92 | `root_enterframe_cross_swf_version` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 93 | `sort_comparator_captured_scope` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 94 | `sort_comparator_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 95 | `string_prim_method_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 96 | `timer_cross_swf_version` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 97 | `timer_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 98 | `watch_cross_swf_version` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 99 | `watch_mc_reentrant_setmember` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 100 | `watch_mc_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 101 | `watch_setmember_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 102 | `watch_timeline_named_params` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 103 | `watch_timeline_reentrant` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 104 | `xml_onload_type1_args` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
