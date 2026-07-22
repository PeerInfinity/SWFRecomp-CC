# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-22 19:47 UTC

**Git SHA**: `9ab376ded1`

**Run Duration**: 8m 39s

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
| 1 | `array_element_type1_args` | 7 | 0.2s |  |
| 2 | `array_method_type1_args` | 7 | 0.2s |  |
| 3 | `avm2_bitmapdata_draw_textfield` | 5 | 4.3s |  |
| 4 | `avm2_contextmenu_stub` | 4 | 5.7s |  |
| 5 | `avm2_embed_bytearray` | 2 | 4.5s |  |
| 6 | `avm2_external_interface_unavailable` | 8 | 4.6s |  |
| 7 | `avm2_findprop_this_resolution` | 13 | 6.1s |  |
| 8 | `avm2_gc_dynprop_tombstone_purge` | 8 | 4.9s |  |
| 9 | `avm2_gc_string_concat_reclaim` | 10 | 4.9s |  |
| 10 | `avm2_gc_string_survives_collect` | 9 | 5.6s |  |
| 11 | `avm2_graphics_runtime` | 7 | 22.7s |  |
| 12 | `avm2_localconnection_domain` | 4 | 4.2s |  |
| 13 | `avm2_morph` | 8 | 23.1s |  |
| 14 | `avm2_sharedobject_flushstatus` | 4 | 4.6s |  |
| 15 | `avm2_slot_default_template` | 34 | 4.8s |  |
| 16 | `avm2_static_and_store_slots` | 14 | 5.1s |  |
| 17 | `avm2_timeline_gradients` | 7 | 25.3s |  |
| 18 | `avm2_timeline_solid` | 6 | 24.7s |  |
| 19 | `avm2_timeline_stroke_gradient` | 9 | 5.6s |  |
| 20 | `avm2_timeline_text` | 4 | 4.0s |  |
| 21 | `avm2_tolerant_verify_quarantine` | 2 | 3.8s |  |
| 22 | `avm2_typed_value_ops` | 30 | 4.8s |  |
| 23 | `broadcast_cross_swf_version` | 4 | 18.9s |  |
| 24 | `broadcast_type1_args` | 14 | 0.9s |  |
| 25 | `coerce_cross_swf_version` | 7 | 15.3s |  |
| 26 | `coerce_recursion_guard` | 1 | 1.2s |  |
| 27 | `coerce_type1_args` | 9 | 1.2s |  |
| 28 | `convertfloat_type1_this` | 3 | 1.1s |  |
| 29 | `ei_closure_scope_order` | 7 | 1.2s |  |
| 30 | `ei_cross_swf_version` | 2 | 1.0s |  |
| 31 | `ei_type1_args` | 7 | 1.0s |  |
| 32 | `enterframe_type1_args` | 8 | 19.7s |  |
| 33 | `fn_call_builtin_type1_args` | 10 | 1.0s |  |
| 34 | `fn_call_type1_args` | 7 | 1.1s |  |
| 35 | `fn_empty_method_type1_args` | 10 | 1.1s |  |
| 36 | `lc_method_type1_args` | 7 | 1.1s |  |
| 37 | `lc_onstatus_type1_args` | 3 | 1.1s |  |
| 38 | `lv_cross_swf_version` | 5 | 19.8s |  |
| 39 | `lv_ondata_type1_args` | 3 | 19.7s |  |
| 40 | `mc_event_cross_swf_version` | 4 | 20.6s |  |
| 41 | `mc_event_type1_args` | 3 | 1.2s |  |
| 42 | `mc_method_v5_caller_gate` | 4 | 19.7s |  |
| 43 | `mc_resolve_type1_args` | 6 | 1.2s |  |
| 44 | `method_type1_args` | 10 | 1.2s |  |
| 45 | `nc_onstatus_closure` | 2 | 19.7s |  |
| 46 | `nc_onstatus_type1_args` | 3 | 1.2s |  |
| 47 | `onconstruct_cross_swf_version` | 4 | 21.2s |  |
| 48 | `onconstruct_type1_args` | 6 | 0.9s |  |
| 49 | `onload_type1_args` | 7 | 17.6s |  |
| 50 | `onunload_type1_args` | 6 | 0.6s |  |
| 51 | `onunload_type1_local_frame` | 2 | 0.7s |  |
| 52 | `resolve_type1_args` | 13 | 1.2s |  |
| 53 | `root_enterframe_cross_swf_version` | 3 | 19.6s |  |
| 54 | `sort_comparator_captured_scope` | 2 | 19.6s |  |
| 55 | `sort_comparator_type1_args` | 5 | 1.1s |  |
| 56 | `string_prim_method_type1_args` | 19 | 1.2s |  |
| 57 | `timer_cross_swf_version` | 3 | 19.4s |  |
| 58 | `timer_type1_args` | 14 | 21.0s |  |
| 59 | `watch_cross_swf_version` | 6 | 21.1s |  |
| 60 | `watch_mc_reentrant_setmember` | 3 | 0.5s |  |
| 61 | `watch_mc_type1_args` | 7 | 0.8s |  |
| 62 | `watch_setmember_type1_args` | 7 | 1.2s |  |
| 63 | `watch_timeline_named_params` | 4 | 1.2s |  |
| 64 | `watch_timeline_reentrant` | 3 | 0.7s |  |
| 65 | `xml_onload_type1_args` | 3 | 20.6s |  |

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
