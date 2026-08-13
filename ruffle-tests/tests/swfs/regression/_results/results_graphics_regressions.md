# Graphics vs Trace Mode Differences

Trace: 71/71 passing | Graphics: 0/72 passing

## Graphics Regressions (71 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `array_element_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 2 | `array_method_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 3 | `avm2_agi_shell` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 4 | `avm2_bitmapdata_draw_textfield` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 5 | `avm2_contextmenu_stub` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 6 | `avm2_embed_bytearray` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 7 | `avm2_external_interface_unavailable` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 8 | `avm2_findprop_this_resolution` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 9 | `avm2_gc_dynprop_tombstone_purge` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 10 | `avm2_gc_string_concat_reclaim` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 11 | `avm2_gc_string_survives_collect` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 12 | `avm2_goto_catchup_scale` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 13 | `avm2_graphics_runtime` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 14 | `avm2_loader_stub` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 15 | `avm2_localconnection_domain` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 16 | `avm2_morph` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 17 | `avm2_sharedobject_flushstatus` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 18 | `avm2_simplebutton_click` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 19 | `avm2_slot_default_template` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 20 | `avm2_static_and_store_slots` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 21 | `avm2_static_text` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 22 | `avm2_timeline_gradients` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 23 | `avm2_timeline_solid` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 24 | `avm2_timeline_stroke_gradient` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 25 | `avm2_timeline_text` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 26 | `avm2_tolerant_verify_quarantine` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 27 | `avm2_typed_value_ops` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 28 | `broadcast_cross_swf_version` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 29 | `broadcast_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 30 | `coerce_cross_swf_version` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 31 | `coerce_recursion_guard` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 32 | `coerce_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 33 | `convertfloat_type1_this` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 34 | `ei_closure_scope_order` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 35 | `ei_cross_swf_version` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 36 | `ei_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 37 | `enterframe_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 38 | `fn_call_builtin_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 39 | `fn_call_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 40 | `fn_empty_method_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 41 | `lc_method_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 42 | `lc_onstatus_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 43 | `lv_cross_swf_version` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 44 | `lv_ondata_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 45 | `mask_sibling_union` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 46 | `mc_event_cross_swf_version` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 47 | `mc_event_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 48 | `mc_method_v5_caller_gate` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 49 | `mc_resolve_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 50 | `method_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 51 | `nc_onstatus_closure` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 52 | `nc_onstatus_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 53 | `onconstruct_cross_swf_version` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 54 | `onconstruct_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 55 | `onload_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 56 | `onunload_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 57 | `onunload_type1_local_frame` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 58 | `resolve_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 59 | `root_enterframe_cross_swf_version` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 60 | `sort_comparator_captured_scope` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 61 | `sort_comparator_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 62 | `string_prim_method_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 63 | `timer_cross_swf_version` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 64 | `timer_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 65 | `watch_cross_swf_version` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 66 | `watch_mc_reentrant_setmember` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 67 | `watch_mc_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 68 | `watch_setmember_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 69 | `watch_timeline_named_params` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 70 | `watch_timeline_reentrant` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 71 | `xml_onload_type1_args` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
