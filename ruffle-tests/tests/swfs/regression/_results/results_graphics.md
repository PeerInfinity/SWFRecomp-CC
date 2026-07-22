# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-22 00:51 UTC

**Git SHA**: `f490e4b247`

**Run Duration**: 9m 21s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 61 |
| Passing | **61** (100.0%) |
| Failing | 0 |
| Total expected lines | 419 |
| Matching lines | 419 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**61 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 0.8s |  |
| 2 | `array_method_type1_args` | 7 | 0.8s |  |
| 3 | `avm2_bitmapdata_draw_textfield` | 5 | 15.7s |  |
| 4 | `avm2_contextmenu_stub` | 4 | 16.1s |  |
| 5 | `avm2_embed_bytearray` | 2 | 4.3s |  |
| 6 | `avm2_external_interface_unavailable` | 8 | 12.5s |  |
| 7 | `avm2_findprop_this_resolution` | 13 | 3.9s |  |
| 8 | `avm2_gc_dynprop_tombstone_purge` | 8 | 11.2s |  |
| 9 | `avm2_gc_string_concat_reclaim` | 10 | 3.4s |  |
| 10 | `avm2_gc_string_survives_collect` | 9 | 16.2s |  |
| 11 | `avm2_localconnection_domain` | 4 | 5.1s |  |
| 12 | `avm2_sharedobject_flushstatus` | 4 | 15.2s |  |
| 13 | `avm2_slot_default_template` | 34 | 4.7s |  |
| 14 | `avm2_static_and_store_slots` | 14 | 12.9s |  |
| 15 | `avm2_timeline_gradients` | 1 | 19.9s |  |
| 16 | `avm2_timeline_stroke_gradient` | 1 | 35.7s |  |
| 17 | `avm2_tolerant_verify_quarantine` | 2 | 5.0s |  |
| 18 | `avm2_typed_value_ops` | 30 | 16.6s |  |
| 19 | `broadcast_cross_swf_version` | 4 | 21.0s |  |
| 20 | `broadcast_type1_args` | 14 | 2.0s |  |
| 21 | `coerce_cross_swf_version` | 7 | 22.4s |  |
| 22 | `coerce_recursion_guard` | 1 | 1.9s |  |
| 23 | `coerce_type1_args` | 9 | 1.9s |  |
| 24 | `convertfloat_type1_this` | 3 | 1.9s |  |
| 25 | `ei_closure_scope_order` | 7 | 2.0s |  |
| 26 | `ei_cross_swf_version` | 2 | 1.9s |  |
| 27 | `ei_type1_args` | 7 | 1.9s |  |
| 28 | `enterframe_type1_args` | 8 | 19.8s |  |
| 29 | `fn_call_builtin_type1_args` | 10 | 1.1s |  |
| 30 | `fn_call_type1_args` | 7 | 1.2s |  |
| 31 | `fn_empty_method_type1_args` | 10 | 1.2s |  |
| 32 | `lc_method_type1_args` | 7 | 1.2s |  |
| 33 | `lc_onstatus_type1_args` | 3 | 1.2s |  |
| 34 | `lv_cross_swf_version` | 5 | 20.2s |  |
| 35 | `lv_ondata_type1_args` | 3 | 20.0s |  |
| 36 | `mc_event_cross_swf_version` | 4 | 16.3s |  |
| 37 | `mc_event_type1_args` | 3 | 1.6s |  |
| 38 | `mc_method_v5_caller_gate` | 4 | 21.3s |  |
| 39 | `mc_resolve_type1_args` | 6 | 1.9s |  |
| 40 | `method_type1_args` | 10 | 1.1s |  |
| 41 | `nc_onstatus_closure` | 2 | 19.0s |  |
| 42 | `nc_onstatus_type1_args` | 3 | 1.6s |  |
| 43 | `onconstruct_cross_swf_version` | 4 | 16.1s |  |
| 44 | `onconstruct_type1_args` | 6 | 1.8s |  |
| 45 | `onload_type1_args` | 7 | 17.6s |  |
| 46 | `onunload_type1_args` | 6 | 1.1s |  |
| 47 | `onunload_type1_local_frame` | 2 | 1.8s |  |
| 48 | `resolve_type1_args` | 13 | 2.0s |  |
| 49 | `root_enterframe_cross_swf_version` | 3 | 21.3s |  |
| 50 | `sort_comparator_captured_scope` | 2 | 19.9s |  |
| 51 | `sort_comparator_type1_args` | 5 | 1.8s |  |
| 52 | `string_prim_method_type1_args` | 19 | 1.8s |  |
| 53 | `timer_cross_swf_version` | 3 | 20.0s |  |
| 54 | `timer_type1_args` | 14 | 20.1s |  |
| 55 | `watch_cross_swf_version` | 6 | 20.2s |  |
| 56 | `watch_mc_reentrant_setmember` | 3 | 1.1s |  |
| 57 | `watch_mc_type1_args` | 7 | 1.5s |  |
| 58 | `watch_setmember_type1_args` | 7 | 1.8s |  |
| 59 | `watch_timeline_named_params` | 4 | 1.8s |  |
| 60 | `watch_timeline_reentrant` | 3 | 1.4s |  |
| 61 | `xml_onload_type1_args` | 3 | 18.9s |  |

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
