# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.748225+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.578571+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 72 | 0 | -72 |
| Total | 72 | 72 | 0 |
| Pass rate | 100.0% | 0.0% | -100.0% |
| Mismatched lines | 0 | 0 | 0 |

## Newly Failing (72)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `array_element_type1_args` | compile_fail | 7/7 | - |
| `array_method_type1_args` | compile_fail | 7/7 | - |
| `avm2_agi_shell` | compile_fail | 6/6 | - |
| `avm2_bitmapdata_draw_textfield` | compile_fail | 5/5 | - |
| `avm2_contextmenu_stub` | compile_fail | 4/4 | - |
| `avm2_embed_bytearray` | compile_fail | 2/2 | - |
| `avm2_external_interface_unavailable` | compile_fail | 8/8 | - |
| `avm2_findprop_this_resolution` | compile_fail | 13/13 | - |
| `avm2_gc_dynprop_tombstone_purge` | compile_fail | 8/8 | - |
| `avm2_gc_string_concat_reclaim` | compile_fail | 10/10 | - |
| `avm2_gc_string_survives_collect` | compile_fail | 9/9 | - |
| `avm2_goto_catchup_scale` | compile_fail | 4/4 | - |
| `avm2_graphics_runtime` | compile_fail | 7/7 | - |
| `avm2_loader_stub` | compile_fail | 5/5 | - |
| `avm2_localconnection_domain` | compile_fail | 4/4 | - |
| `avm2_morph` | compile_fail | 8/8 | - |
| `avm2_sharedobject_flushstatus` | compile_fail | 4/4 | - |
| `avm2_simplebutton_click` | compile_fail | 2/2 | - |
| `avm2_slot_default_template` | compile_fail | 34/34 | - |
| `avm2_static_and_store_slots` | compile_fail | 14/14 | - |
| `avm2_static_text` | compile_fail | 6/6 | - |
| `avm2_timeline_gradients` | compile_fail | 7/7 | - |
| `avm2_timeline_solid` | compile_fail | 6/6 | - |
| `avm2_timeline_stroke_gradient` | compile_fail | 9/9 | - |
| `avm2_timeline_text` | compile_fail | 4/4 | - |
| `avm2_tolerant_verify_quarantine` | compile_fail | 2/2 | - |
| `avm2_typed_value_ops` | compile_fail | 30/30 | - |
| `broadcast_cross_swf_version` | compile_fail | 4/4 | - |
| `broadcast_type1_args` | compile_fail | 14/14 | - |
| `coerce_cross_swf_version` | compile_fail | 7/7 | - |
| `coerce_recursion_guard` | compile_fail | 1/1 | - |
| `coerce_type1_args` | compile_fail | 9/9 | - |
| `convertfloat_type1_this` | compile_fail | 3/3 | - |
| `ei_closure_scope_order` | compile_fail | 7/7 | - |
| `ei_cross_swf_version` | compile_fail | 2/2 | - |
| `ei_type1_args` | compile_fail | 7/7 | - |
| `enterframe_type1_args` | compile_fail | 8/8 | - |
| `fn_call_builtin_type1_args` | compile_fail | 10/10 | - |
| `fn_call_type1_args` | compile_fail | 7/7 | - |
| `fn_empty_method_type1_args` | compile_fail | 10/10 | - |
| `lc_method_type1_args` | compile_fail | 7/7 | - |
| `lc_onstatus_type1_args` | compile_fail | 3/3 | - |
| `lv_cross_swf_version` | compile_fail | 5/5 | - |
| `lv_ondata_type1_args` | compile_fail | 3/3 | - |
| `mask_nested_intersect` | compile_fail | 1/1 | - |
| `mask_sibling_union` | compile_fail | 1/1 | - |
| `mc_event_cross_swf_version` | compile_fail | 4/4 | - |
| `mc_event_type1_args` | compile_fail | 3/3 | - |
| `mc_method_v5_caller_gate` | compile_fail | 4/4 | - |
| `mc_resolve_type1_args` | compile_fail | 6/6 | - |
| `method_type1_args` | compile_fail | 10/10 | - |
| `nc_onstatus_closure` | compile_fail | 2/2 | - |
| `nc_onstatus_type1_args` | compile_fail | 3/3 | - |
| `onconstruct_cross_swf_version` | compile_fail | 4/4 | - |
| `onconstruct_type1_args` | compile_fail | 6/6 | - |
| `onload_type1_args` | compile_fail | 7/7 | - |
| `onunload_type1_args` | compile_fail | 6/6 | - |
| `onunload_type1_local_frame` | compile_fail | 2/2 | - |
| `resolve_type1_args` | compile_fail | 13/13 | - |
| `root_enterframe_cross_swf_version` | compile_fail | 3/3 | - |
| `sort_comparator_captured_scope` | compile_fail | 2/2 | - |
| `sort_comparator_type1_args` | compile_fail | 5/5 | - |
| `string_prim_method_type1_args` | compile_fail | 19/19 | - |
| `timer_cross_swf_version` | compile_fail | 3/3 | - |
| `timer_type1_args` | compile_fail | 14/14 | - |
| `watch_cross_swf_version` | compile_fail | 6/6 | - |
| `watch_mc_reentrant_setmember` | compile_fail | 3/3 | - |
| `watch_mc_type1_args` | compile_fail | 7/7 | - |
| `watch_setmember_type1_args` | compile_fail | 7/7 | - |
| `watch_timeline_named_params` | compile_fail | 4/4 | - |
| `watch_timeline_reentrant` | compile_fail | 3/3 | - |
| `xml_onload_type1_args` | compile_fail | 3/3 | - |
