# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-03 22:09 UTC

**Git SHA**: `df9560ff61`

**Run Duration**: 14m 45s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 77 |
| Passing | **77** (100.0%) |
| Failing | 0 |
| Total expected lines | 509 |
| Matching lines | 509 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**77 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 16.1s |  |
| 2 | `array_method_type1_args` | 7 | 1.0s |  |
| 3 | `avm1_parent_as3_child_payload` | 2 | 16.3s |  |
| 4 | `avm1_parent_child_bitmap` | 5 | 20.2s |  |
| 5 | `avm1_parent_child_modify_place` | 5 | 20.0s |  |
| 6 | `avm1_parent_child_sprite_meta` | 8 | 1.6s |  |
| 7 | `avm2_agi_shell` | 6 | 8.7s |  |
| 8 | `avm2_bitmapdata_draw_textfield` | 5 | 7.2s |  |
| 9 | `avm2_contextmenu_stub` | 4 | 6.7s |  |
| 10 | `avm2_embed_bytearray` | 2 | 7.4s |  |
| 11 | `avm2_external_interface_unavailable` | 8 | 5.7s |  |
| 12 | `avm2_findprop_this_resolution` | 13 | 5.8s |  |
| 13 | `avm2_gc_dynprop_tombstone_purge` | 8 | 8.1s |  |
| 14 | `avm2_gc_string_concat_reclaim` | 10 | 6.2s |  |
| 15 | `avm2_gc_string_survives_collect` | 9 | 1.3s |  |
| 16 | `avm2_goto_catchup_scale` | 4 | 6.6s |  |
| 17 | `avm2_graphics_runtime` | 7 | 26.5s |  |
| 18 | `avm2_loader_stub` | 5 | 7.3s |  |
| 19 | `avm2_localconnection_domain` | 4 | 9.0s |  |
| 20 | `avm2_morph` | 8 | 26.4s |  |
| 21 | `avm2_parent_child_symbol_stride` | 6 | 27.7s |  |
| 22 | `avm2_sharedobject_flushstatus` | 4 | 9.2s |  |
| 23 | `avm2_simplebutton_click` | 2 | 7.2s |  |
| 24 | `avm2_slot_default_template` | 34 | 7.4s |  |
| 25 | `avm2_static_and_store_slots` | 14 | 4.5s |  |
| 26 | `avm2_static_text` | 6 | 26.6s |  |
| 27 | `avm2_timeline_gradients` | 7 | 27.7s |  |
| 28 | `avm2_timeline_solid` | 6 | 31.6s |  |
| 29 | `avm2_timeline_stroke_gradient` | 9 | 8.9s |  |
| 30 | `avm2_timeline_text` | 4 | 8.2s |  |
| 31 | `avm2_tolerant_verify_quarantine` | 2 | 9.4s |  |
| 32 | `avm2_typed_value_ops` | 30 | 7.7s |  |
| 33 | `broadcast_cross_swf_version` | 4 | 1.5s |  |
| 34 | `broadcast_type1_args` | 14 | 20.5s |  |
| 35 | `coerce_cross_swf_version` | 7 | 1.2s |  |
| 36 | `coerce_recursion_guard` | 1 | 1.1s |  |
| 37 | `coerce_type1_args` | 9 | 16.3s |  |
| 38 | `convertfloat_type1_this` | 3 | 0.4s |  |
| 39 | `ei_closure_scope_order` | 7 | 1.1s |  |
| 40 | `ei_cross_swf_version` | 2 | 20.4s |  |
| 41 | `ei_type1_args` | 7 | 1.3s |  |
| 42 | `enterframe_type1_args` | 8 | 1.3s |  |
| 43 | `fn_call_builtin_type1_args` | 10 | 12.2s |  |
| 44 | `fn_call_type1_args` | 7 | 0.8s |  |
| 45 | `fn_empty_method_type1_args` | 10 | 0.8s |  |
| 46 | `lc_method_type1_args` | 7 | 20.7s |  |
| 47 | `lc_onstatus_type1_args` | 3 | 1.3s |  |
| 48 | `lv_cross_swf_version` | 5 | 1.5s |  |
| 49 | `lv_ondata_type1_args` | 3 | 21.1s |  |
| 50 | `mask_nested_intersect` | 1 | 20.9s |  |
| 51 | `mask_sibling_union` | 1 | 1.4s |  |
| 52 | `mc_event_cross_swf_version` | 4 | 1.5s |  |
| 53 | `mc_event_type1_args` | 3 | 22.0s |  |
| 54 | `mc_method_v5_caller_gate` | 4 | 0.9s |  |
| 55 | `mc_resolve_type1_args` | 6 | 14.9s |  |
| 56 | `method_type1_args` | 10 | 20.4s |  |
| 57 | `nc_onstatus_closure` | 2 | 20.3s |  |
| 58 | `nc_onstatus_type1_args` | 3 | 20.1s |  |
| 59 | `onconstruct_cross_swf_version` | 4 | 1.4s |  |
| 60 | `onconstruct_type1_args` | 6 | 21.5s |  |
| 61 | `onload_type1_args` | 7 | 22.0s |  |
| 62 | `onunload_type1_args` | 6 | 14.7s |  |
| 63 | `onunload_type1_local_frame` | 2 | 0.8s |  |
| 64 | `resolve_type1_args` | 13 | 20.9s |  |
| 65 | `root_enterframe_cross_swf_version` | 3 | 20.6s |  |
| 66 | `sort_comparator_captured_scope` | 2 | 20.9s |  |
| 67 | `sort_comparator_type1_args` | 5 | 20.1s |  |
| 68 | `string_prim_method_type1_args` | 19 | 20.4s |  |
| 69 | `timer_cross_swf_version` | 3 | 1.4s |  |
| 70 | `timer_type1_args` | 14 | 0.1s |  |
| 71 | `watch_cross_swf_version` | 6 | 0.2s |  |
| 72 | `watch_mc_reentrant_setmember` | 3 | 20.3s |  |
| 73 | `watch_mc_type1_args` | 7 | 1.3s |  |
| 74 | `watch_setmember_type1_args` | 7 | 20.3s |  |
| 75 | `watch_timeline_named_params` | 4 | 1.2s |  |
| 76 | `watch_timeline_reentrant` | 3 | 21.6s |  |
| 77 | `xml_onload_type1_args` | 3 | 21.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.
