# Ruffle Test Results (Filtered)

**Date**: 2026-09-02 18:22 UTC

**Git SHA**: `0a56091cfc`

**Run Duration**: 20m 27s

**Filtered**: 0 tests ignored out of 72 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 72 |
| Passing | **72** (100.0%) |
| Failing | 0 |
| Total expected lines | 483 |
| Matching lines | 483 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**72 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 16.9s |  |
| 2 | `array_method_type1_args` | 7 | 1.7s |  |
| 3 | `avm2_agi_shell` | 6 | 25.6s |  |
| 4 | `avm2_bitmapdata_draw_textfield` | 5 | 31.5s |  |
| 5 | `avm2_contextmenu_stub` | 4 | 7.8s |  |
| 6 | `avm2_embed_bytearray` | 2 | 27.1s |  |
| 7 | `avm2_external_interface_unavailable` | 8 | 33.0s |  |
| 8 | `avm2_findprop_this_resolution` | 13 | 8.8s |  |
| 9 | `avm2_gc_dynprop_tombstone_purge` | 8 | 9.0s |  |
| 10 | `avm2_gc_string_concat_reclaim` | 10 | 22.9s |  |
| 11 | `avm2_gc_string_survives_collect` | 9 | 5.7s |  |
| 12 | `avm2_goto_catchup_scale` | 4 | 6.3s |  |
| 13 | `avm2_graphics_runtime` | 7 | 35.4s |  |
| 14 | `avm2_loader_stub` | 5 | 29.0s |  |
| 15 | `avm2_localconnection_domain` | 4 | 8.8s |  |
| 16 | `avm2_morph` | 8 | 27.5s |  |
| 17 | `avm2_sharedobject_flushstatus` | 4 | 28.1s |  |
| 18 | `avm2_simplebutton_click` | 2 | 8.8s |  |
| 19 | `avm2_slot_default_template` | 34 | 35.8s |  |
| 20 | `avm2_static_and_store_slots` | 14 | 9.2s |  |
| 21 | `avm2_static_text` | 6 | 30.3s |  |
| 22 | `avm2_timeline_gradients` | 7 | 35.8s |  |
| 23 | `avm2_timeline_solid` | 6 | 9.5s |  |
| 24 | `avm2_timeline_stroke_gradient` | 9 | 9.7s |  |
| 25 | `avm2_timeline_text` | 4 | 31.3s |  |
| 26 | `avm2_tolerant_verify_quarantine` | 2 | 8.2s |  |
| 27 | `avm2_typed_value_ops` | 30 | 8.4s |  |
| 28 | `broadcast_cross_swf_version` | 4 | 23.2s |  |
| 29 | `broadcast_type1_args` | 14 | 22.5s |  |
| 30 | `coerce_cross_swf_version` | 7 | 2.1s |  |
| 31 | `coerce_recursion_guard` | 1 | 21.7s |  |
| 32 | `coerce_type1_args` | 9 | 2.0s |  |
| 33 | `convertfloat_type1_this` | 3 | 2.0s |  |
| 34 | `ei_closure_scope_order` | 7 | 22.5s |  |
| 35 | `ei_cross_swf_version` | 2 | 2.1s |  |
| 36 | `ei_type1_args` | 7 | 2.1s |  |
| 37 | `enterframe_type1_args` | 8 | 15.6s |  |
| 38 | `fn_call_builtin_type1_args` | 10 | 15.4s |  |
| 39 | `fn_call_type1_args` | 7 | 20.8s |  |
| 40 | `fn_empty_method_type1_args` | 10 | 1.9s |  |
| 41 | `lc_method_type1_args` | 7 | 20.8s |  |
| 42 | `lc_onstatus_type1_args` | 3 | 1.7s |  |
| 43 | `lv_cross_swf_version` | 5 | 21.3s |  |
| 44 | `lv_ondata_type1_args` | 3 | 21.1s |  |
| 45 | `mask_nested_intersect` | 1 | 21.2s |  |
| 46 | `mask_sibling_union` | 1 | 2.0s |  |
| 47 | `mc_event_cross_swf_version` | 4 | 16.7s |  |
| 48 | `mc_event_type1_args` | 3 | 16.6s |  |
| 49 | `mc_method_v5_caller_gate` | 4 | 21.1s |  |
| 50 | `mc_resolve_type1_args` | 6 | 21.0s |  |
| 51 | `method_type1_args` | 10 | 23.2s |  |
| 52 | `nc_onstatus_closure` | 2 | 23.1s |  |
| 53 | `nc_onstatus_type1_args` | 3 | 22.1s |  |
| 54 | `onconstruct_cross_swf_version` | 4 | 22.5s |  |
| 55 | `onconstruct_type1_args` | 6 | 18.1s |  |
| 56 | `onload_type1_args` | 7 | 18.1s |  |
| 57 | `onunload_type1_args` | 6 | 21.0s |  |
| 58 | `onunload_type1_local_frame` | 2 | 1.9s |  |
| 59 | `resolve_type1_args` | 13 | 20.5s |  |
| 60 | `root_enterframe_cross_swf_version` | 3 | 20.9s |  |
| 61 | `sort_comparator_captured_scope` | 2 | 15.7s |  |
| 62 | `sort_comparator_type1_args` | 5 | 15.6s |  |
| 63 | `string_prim_method_type1_args` | 19 | 18.5s |  |
| 64 | `timer_cross_swf_version` | 3 | 18.5s |  |
| 65 | `timer_type1_args` | 14 | 22.6s |  |
| 66 | `watch_cross_swf_version` | 6 | 22.4s |  |
| 67 | `watch_mc_reentrant_setmember` | 3 | 20.8s |  |
| 68 | `watch_mc_type1_args` | 7 | 1.7s |  |
| 69 | `watch_setmember_type1_args` | 7 | 21.3s |  |
| 70 | `watch_timeline_named_params` | 4 | 2.0s |  |
| 71 | `watch_timeline_reentrant` | 3 | 21.0s |  |
| 72 | `xml_onload_type1_args` | 3 | 21.1s |  |

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
