# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-22 03:14 UTC

**Git SHA**: `6f1508984c`

**Run Duration**: 7m 35s

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
| 1 | `array_element_type1_args` | 7 | 0.1s |  |
| 2 | `array_method_type1_args` | 7 | 0.1s |  |
| 3 | `avm2_bitmapdata_draw_textfield` | 5 | 4.0s |  |
| 4 | `avm2_contextmenu_stub` | 4 | 4.2s |  |
| 5 | `avm2_embed_bytearray` | 2 | 4.1s |  |
| 6 | `avm2_external_interface_unavailable` | 8 | 4.2s |  |
| 7 | `avm2_findprop_this_resolution` | 13 | 4.9s |  |
| 8 | `avm2_gc_dynprop_tombstone_purge` | 8 | 4.6s |  |
| 9 | `avm2_gc_string_concat_reclaim` | 10 | 4.9s |  |
| 10 | `avm2_gc_string_survives_collect` | 9 | 4.4s |  |
| 11 | `avm2_localconnection_domain` | 4 | 4.9s |  |
| 12 | `avm2_sharedobject_flushstatus` | 4 | 4.5s |  |
| 13 | `avm2_slot_default_template` | 34 | 3.9s |  |
| 14 | `avm2_static_and_store_slots` | 14 | 3.6s |  |
| 15 | `avm2_timeline_gradients` | 7 | 24.0s |  |
| 16 | `avm2_timeline_solid` | 6 | 5.3s |  |
| 17 | `avm2_timeline_stroke_gradient` | 9 | 24.1s |  |
| 18 | `avm2_tolerant_verify_quarantine` | 2 | 4.3s |  |
| 19 | `avm2_typed_value_ops` | 30 | 4.5s |  |
| 20 | `broadcast_cross_swf_version` | 4 | 20.4s |  |
| 21 | `broadcast_type1_args` | 14 | 1.2s |  |
| 22 | `coerce_cross_swf_version` | 7 | 19.4s |  |
| 23 | `coerce_recursion_guard` | 1 | 1.1s |  |
| 24 | `coerce_type1_args` | 9 | 1.1s |  |
| 25 | `convertfloat_type1_this` | 3 | 1.1s |  |
| 26 | `ei_closure_scope_order` | 7 | 1.3s |  |
| 27 | `ei_cross_swf_version` | 2 | 1.2s |  |
| 28 | `ei_type1_args` | 7 | 1.2s |  |
| 29 | `enterframe_type1_args` | 8 | 18.9s |  |
| 30 | `fn_call_builtin_type1_args` | 10 | 1.1s |  |
| 31 | `fn_call_type1_args` | 7 | 1.2s |  |
| 32 | `fn_empty_method_type1_args` | 10 | 1.2s |  |
| 33 | `lc_method_type1_args` | 7 | 1.1s |  |
| 34 | `lc_onstatus_type1_args` | 3 | 1.1s |  |
| 35 | `lv_cross_swf_version` | 5 | 19.8s |  |
| 36 | `lv_ondata_type1_args` | 3 | 19.4s |  |
| 37 | `mc_event_cross_swf_version` | 4 | 15.2s |  |
| 38 | `mc_event_type1_args` | 3 | 0.9s |  |
| 39 | `mc_method_v5_caller_gate` | 4 | 20.1s |  |
| 40 | `mc_resolve_type1_args` | 6 | 1.2s |  |
| 41 | `method_type1_args` | 10 | 1.2s |  |
| 42 | `nc_onstatus_closure` | 2 | 19.8s |  |
| 43 | `nc_onstatus_type1_args` | 3 | 1.2s |  |
| 44 | `onconstruct_cross_swf_version` | 4 | 20.1s |  |
| 45 | `onconstruct_type1_args` | 6 | 1.1s |  |
| 46 | `onload_type1_args` | 7 | 19.0s |  |
| 47 | `onunload_type1_args` | 6 | 0.5s |  |
| 48 | `onunload_type1_local_frame` | 2 | 1.1s |  |
| 49 | `resolve_type1_args` | 13 | 1.1s |  |
| 50 | `root_enterframe_cross_swf_version` | 3 | 19.1s |  |
| 51 | `sort_comparator_captured_scope` | 2 | 19.6s |  |
| 52 | `sort_comparator_type1_args` | 5 | 1.2s |  |
| 53 | `string_prim_method_type1_args` | 19 | 1.1s |  |
| 54 | `timer_cross_swf_version` | 3 | 19.1s |  |
| 55 | `timer_type1_args` | 14 | 19.1s |  |
| 56 | `watch_cross_swf_version` | 6 | 19.5s |  |
| 57 | `watch_mc_reentrant_setmember` | 3 | 0.5s |  |
| 58 | `watch_mc_type1_args` | 7 | 0.7s |  |
| 59 | `watch_setmember_type1_args` | 7 | 1.2s |  |
| 60 | `watch_timeline_named_params` | 4 | 1.2s |  |
| 61 | `watch_timeline_reentrant` | 3 | 0.7s |  |
| 62 | `xml_onload_type1_args` | 3 | 19.3s |  |

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
