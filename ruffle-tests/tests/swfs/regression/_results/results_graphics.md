# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-22 02:06 UTC

**Git SHA**: `69369f32de`

**Run Duration**: 7m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 62 |
| Passing | **62** (100.0%) |
| Failing | 0 |
| Total expected lines | 439 |
| Matching lines | 439 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**62 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 0.8s |  |
| 2 | `array_method_type1_args` | 7 | 0.8s |  |
| 3 | `avm2_bitmapdata_draw_textfield` | 5 | 4.4s |  |
| 4 | `avm2_contextmenu_stub` | 4 | 5.9s |  |
| 5 | `avm2_embed_bytearray` | 2 | 4.3s |  |
| 6 | `avm2_external_interface_unavailable` | 8 | 5.0s |  |
| 7 | `avm2_findprop_this_resolution` | 13 | 5.6s |  |
| 8 | `avm2_gc_dynprop_tombstone_purge` | 8 | 4.7s |  |
| 9 | `avm2_gc_string_concat_reclaim` | 10 | 5.2s |  |
| 10 | `avm2_gc_string_survives_collect` | 9 | 5.1s |  |
| 11 | `avm2_localconnection_domain` | 4 | 4.9s |  |
| 12 | `avm2_sharedobject_flushstatus` | 4 | 4.8s |  |
| 13 | `avm2_slot_default_template` | 34 | 6.3s |  |
| 14 | `avm2_static_and_store_slots` | 14 | 5.3s |  |
| 15 | `avm2_timeline_gradients` | 7 | 24.9s |  |
| 16 | `avm2_timeline_solid` | 6 | 5.7s |  |
| 17 | `avm2_timeline_stroke_gradient` | 9 | 24.5s |  |
| 18 | `avm2_tolerant_verify_quarantine` | 2 | 4.8s |  |
| 19 | `avm2_typed_value_ops` | 30 | 4.3s |  |
| 20 | `broadcast_cross_swf_version` | 4 | 15.8s |  |
| 21 | `broadcast_type1_args` | 14 | 1.6s |  |
| 22 | `coerce_cross_swf_version` | 7 | 15.8s |  |
| 23 | `coerce_recursion_guard` | 1 | 1.8s |  |
| 24 | `coerce_type1_args` | 9 | 1.8s |  |
| 25 | `convertfloat_type1_this` | 3 | 2.0s |  |
| 26 | `ei_closure_scope_order` | 7 | 2.1s |  |
| 27 | `ei_cross_swf_version` | 2 | 1.9s |  |
| 28 | `ei_type1_args` | 7 | 1.8s |  |
| 29 | `enterframe_type1_args` | 8 | 20.3s |  |
| 30 | `fn_call_builtin_type1_args` | 10 | 1.1s |  |
| 31 | `fn_call_type1_args` | 7 | 1.1s |  |
| 32 | `fn_empty_method_type1_args` | 10 | 1.1s |  |
| 33 | `lc_method_type1_args` | 7 | 1.1s |  |
| 34 | `lc_onstatus_type1_args` | 3 | 1.1s |  |
| 35 | `lv_cross_swf_version` | 5 | 19.4s |  |
| 36 | `lv_ondata_type1_args` | 3 | 19.4s |  |
| 37 | `mc_event_cross_swf_version` | 4 | 20.2s |  |
| 38 | `mc_event_type1_args` | 3 | 1.9s |  |
| 39 | `mc_method_v5_caller_gate` | 4 | 16.5s |  |
| 40 | `mc_resolve_type1_args` | 6 | 1.5s |  |
| 41 | `method_type1_args` | 10 | 0.9s |  |
| 42 | `nc_onstatus_closure` | 2 | 17.0s |  |
| 43 | `nc_onstatus_type1_args` | 3 | 1.8s |  |
| 44 | `onconstruct_cross_swf_version` | 4 | 20.3s |  |
| 45 | `onconstruct_type1_args` | 6 | 1.8s |  |
| 46 | `onload_type1_args` | 7 | 19.7s |  |
| 47 | `onunload_type1_args` | 6 | 0.9s |  |
| 48 | `onunload_type1_local_frame` | 2 | 1.6s |  |
| 49 | `resolve_type1_args` | 13 | 1.8s |  |
| 50 | `root_enterframe_cross_swf_version` | 3 | 19.8s |  |
| 51 | `sort_comparator_captured_scope` | 2 | 20.0s |  |
| 52 | `sort_comparator_type1_args` | 5 | 1.8s |  |
| 53 | `string_prim_method_type1_args` | 19 | 1.9s |  |
| 54 | `timer_cross_swf_version` | 3 | 20.6s |  |
| 55 | `timer_type1_args` | 14 | 14.7s |  |
| 56 | `watch_cross_swf_version` | 6 | 14.9s |  |
| 57 | `watch_mc_reentrant_setmember` | 3 | 0.7s |  |
| 58 | `watch_mc_type1_args` | 7 | 1.0s |  |
| 59 | `watch_setmember_type1_args` | 7 | 1.8s |  |
| 60 | `watch_timeline_named_params` | 4 | 1.8s |  |
| 61 | `watch_timeline_reentrant` | 3 | 1.7s |  |
| 62 | `xml_onload_type1_args` | 3 | 20.0s |  |

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
