# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-22 19:37 UTC

**Git SHA**: `9ab376ded1`

**Run Duration**: 8m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 65 |
| Passing | **65** (100.0%) |
| Failing | 0 |
| Total expected lines | 458 |
| Matching lines | 458 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 0.5s |  |
| 2 | `array_method_type1_args` | 7 | 0.5s |  |
| 3 | `avm2_bitmapdata_draw_textfield` | 5 | 4.5s |  |
| 4 | `avm2_contextmenu_stub` | 4 | 6.8s |  |
| 5 | `avm2_embed_bytearray` | 2 | 5.0s |  |
| 6 | `avm2_external_interface_unavailable` | 8 | 5.7s |  |
| 7 | `avm2_findprop_this_resolution` | 13 | 7.1s |  |
| 8 | `avm2_gc_dynprop_tombstone_purge` | 8 | 5.9s |  |
| 9 | `avm2_gc_string_concat_reclaim` | 10 | 5.8s |  |
| 10 | `avm2_gc_string_survives_collect` | 9 | 7.2s |  |
| 11 | `avm2_graphics_runtime` | 7 | 25.2s |  |
| 12 | `avm2_localconnection_domain` | 4 | 5.7s |  |
| 13 | `avm2_morph` | 8 | 25.8s |  |
| 14 | `avm2_sharedobject_flushstatus` | 4 | 5.7s |  |
| 15 | `avm2_slot_default_template` | 34 | 5.8s |  |
| 16 | `avm2_static_and_store_slots` | 14 | 6.7s |  |
| 17 | `avm2_timeline_gradients` | 7 | 24.5s |  |
| 18 | `avm2_timeline_solid` | 6 | 25.8s |  |
| 19 | `avm2_timeline_stroke_gradient` | 9 | 6.5s |  |
| 20 | `avm2_timeline_text` | 4 | 6.7s |  |
| 21 | `avm2_tolerant_verify_quarantine` | 2 | 5.3s |  |
| 22 | `avm2_typed_value_ops` | 30 | 6.8s |  |
| 23 | `broadcast_cross_swf_version` | 4 | 19.9s |  |
| 24 | `broadcast_type1_args` | 14 | 1.8s |  |
| 25 | `coerce_cross_swf_version` | 7 | 19.9s |  |
| 26 | `coerce_recursion_guard` | 1 | 1.9s |  |
| 27 | `coerce_type1_args` | 9 | 1.9s |  |
| 28 | `convertfloat_type1_this` | 3 | 1.9s |  |
| 29 | `ei_closure_scope_order` | 7 | 2.0s |  |
| 30 | `ei_cross_swf_version` | 2 | 1.5s |  |
| 31 | `ei_type1_args` | 7 | 1.5s |  |
| 32 | `enterframe_type1_args` | 8 | 0.7s |  |
| 33 | `fn_call_builtin_type1_args` | 10 | 0.7s |  |
| 34 | `fn_call_type1_args` | 7 | 1.1s |  |
| 35 | `fn_empty_method_type1_args` | 10 | 1.1s |  |
| 36 | `lc_method_type1_args` | 7 | 0.9s |  |
| 37 | `lc_onstatus_type1_args` | 3 | 0.9s |  |
| 38 | `lv_cross_swf_version` | 5 | 19.9s |  |
| 39 | `lv_ondata_type1_args` | 3 | 19.7s |  |
| 40 | `mc_event_cross_swf_version` | 4 | 19.9s |  |
| 41 | `mc_event_type1_args` | 3 | 1.9s |  |
| 42 | `mc_method_v5_caller_gate` | 4 | 20.8s |  |
| 43 | `mc_resolve_type1_args` | 6 | 1.9s |  |
| 44 | `method_type1_args` | 10 | 1.2s |  |
| 45 | `nc_onstatus_closure` | 2 | 20.2s |  |
| 46 | `nc_onstatus_type1_args` | 3 | 1.8s |  |
| 47 | `onconstruct_cross_swf_version` | 4 | 19.8s |  |
| 48 | `onconstruct_type1_args` | 6 | 1.8s |  |
| 49 | `onload_type1_args` | 7 | 19.5s |  |
| 50 | `onunload_type1_args` | 6 | 1.1s |  |
| 51 | `onunload_type1_local_frame` | 2 | 2.0s |  |
| 52 | `resolve_type1_args` | 13 | 1.7s |  |
| 53 | `root_enterframe_cross_swf_version` | 3 | 20.2s |  |
| 54 | `sort_comparator_captured_scope` | 2 | 20.7s |  |
| 55 | `sort_comparator_type1_args` | 5 | 1.9s |  |
| 56 | `string_prim_method_type1_args` | 19 | 1.6s |  |
| 57 | `timer_cross_swf_version` | 3 | 20.3s |  |
| 58 | `timer_type1_args` | 14 | 1.7s |  |
| 59 | `watch_cross_swf_version` | 6 | 16.6s |  |
| 60 | `watch_mc_reentrant_setmember` | 3 | 1.1s |  |
| 61 | `watch_mc_type1_args` | 7 | 1.8s |  |
| 62 | `watch_setmember_type1_args` | 7 | 2.0s |  |
| 63 | `watch_timeline_named_params` | 4 | 2.0s |  |
| 64 | `watch_timeline_reentrant` | 3 | 1.8s |  |
| 65 | `xml_onload_type1_args` | 3 | 20.4s |  |

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
