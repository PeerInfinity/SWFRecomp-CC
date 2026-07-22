# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-22 03:36 UTC

**Git SHA**: `6c040c32fc`

**Run Duration**: 9m 58s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 63 |
| Passing | **63** (100.0%) |
| Failing | 0 |
| Total expected lines | 446 |
| Matching lines | 446 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**63 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 0.8s |  |
| 2 | `array_method_type1_args` | 7 | 0.8s |  |
| 3 | `avm2_bitmapdata_draw_textfield` | 5 | 16.0s |  |
| 4 | `avm2_contextmenu_stub` | 4 | 16.8s |  |
| 5 | `avm2_embed_bytearray` | 2 | 4.8s |  |
| 6 | `avm2_external_interface_unavailable` | 8 | 5.5s |  |
| 7 | `avm2_findprop_this_resolution` | 13 | 15.8s |  |
| 8 | `avm2_gc_dynprop_tombstone_purge` | 8 | 5.0s |  |
| 9 | `avm2_gc_string_concat_reclaim` | 10 | 5.0s |  |
| 10 | `avm2_gc_string_survives_collect` | 9 | 16.3s |  |
| 11 | `avm2_graphics_runtime` | 7 | 23.4s |  |
| 12 | `avm2_localconnection_domain` | 4 | 16.7s |  |
| 13 | `avm2_sharedobject_flushstatus` | 4 | 5.3s |  |
| 14 | `avm2_slot_default_template` | 34 | 16.3s |  |
| 15 | `avm2_static_and_store_slots` | 14 | 5.3s |  |
| 16 | `avm2_timeline_gradients` | 7 | 35.7s |  |
| 17 | `avm2_timeline_solid` | 6 | 6.2s |  |
| 18 | `avm2_timeline_stroke_gradient` | 9 | 26.3s |  |
| 19 | `avm2_tolerant_verify_quarantine` | 2 | 3.6s |  |
| 20 | `avm2_typed_value_ops` | 30 | 16.8s |  |
| 21 | `broadcast_cross_swf_version` | 4 | 20.4s |  |
| 22 | `broadcast_type1_args` | 14 | 2.0s |  |
| 23 | `coerce_cross_swf_version` | 7 | 21.2s |  |
| 24 | `coerce_recursion_guard` | 1 | 1.8s |  |
| 25 | `coerce_type1_args` | 9 | 1.9s |  |
| 26 | `convertfloat_type1_this` | 3 | 1.9s |  |
| 27 | `ei_closure_scope_order` | 7 | 2.0s |  |
| 28 | `ei_cross_swf_version` | 2 | 2.0s |  |
| 29 | `ei_type1_args` | 7 | 2.0s |  |
| 30 | `enterframe_type1_args` | 8 | 19.3s |  |
| 31 | `fn_call_builtin_type1_args` | 10 | 1.0s |  |
| 32 | `fn_call_type1_args` | 7 | 0.8s |  |
| 33 | `fn_empty_method_type1_args` | 10 | 0.8s |  |
| 34 | `lc_method_type1_args` | 7 | 0.9s |  |
| 35 | `lc_onstatus_type1_args` | 3 | 0.9s |  |
| 36 | `lv_cross_swf_version` | 5 | 20.2s |  |
| 37 | `lv_ondata_type1_args` | 3 | 20.6s |  |
| 38 | `mc_event_cross_swf_version` | 4 | 19.6s |  |
| 39 | `mc_event_type1_args` | 3 | 1.8s |  |
| 40 | `mc_method_v5_caller_gate` | 4 | 20.1s |  |
| 41 | `mc_resolve_type1_args` | 6 | 1.9s |  |
| 42 | `method_type1_args` | 10 | 1.0s |  |
| 43 | `nc_onstatus_closure` | 2 | 19.1s |  |
| 44 | `nc_onstatus_type1_args` | 3 | 1.8s |  |
| 45 | `onconstruct_cross_swf_version` | 4 | 20.1s |  |
| 46 | `onconstruct_type1_args` | 6 | 1.1s |  |
| 47 | `onload_type1_args` | 7 | 14.4s |  |
| 48 | `onunload_type1_args` | 6 | 0.8s |  |
| 49 | `onunload_type1_local_frame` | 2 | 1.4s |  |
| 50 | `resolve_type1_args` | 13 | 1.8s |  |
| 51 | `root_enterframe_cross_swf_version` | 3 | 19.7s |  |
| 52 | `sort_comparator_captured_scope` | 2 | 21.2s |  |
| 53 | `sort_comparator_type1_args` | 5 | 1.9s |  |
| 54 | `string_prim_method_type1_args` | 19 | 1.8s |  |
| 55 | `timer_cross_swf_version` | 3 | 19.5s |  |
| 56 | `timer_type1_args` | 14 | 16.9s |  |
| 57 | `watch_cross_swf_version` | 6 | 17.1s |  |
| 58 | `watch_mc_reentrant_setmember` | 3 | 1.1s |  |
| 59 | `watch_mc_type1_args` | 7 | 1.6s |  |
| 60 | `watch_setmember_type1_args` | 7 | 1.9s |  |
| 61 | `watch_timeline_named_params` | 4 | 1.8s |  |
| 62 | `watch_timeline_reentrant` | 3 | 1.8s |  |
| 63 | `xml_onload_type1_args` | 3 | 20.3s |  |

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
