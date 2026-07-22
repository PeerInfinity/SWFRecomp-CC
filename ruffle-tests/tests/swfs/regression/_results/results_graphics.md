# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-22 21:00 UTC

**Git SHA**: `cc33c10bf9`

**Run Duration**: 9m 37s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 66 |
| Passing | **66** (100.0%) |
| Failing | 0 |
| Total expected lines | 464 |
| Matching lines | 464 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**66 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 0.8s |  |
| 2 | `array_method_type1_args` | 7 | 0.8s |  |
| 3 | `avm2_bitmapdata_draw_textfield` | 5 | 6.1s |  |
| 4 | `avm2_contextmenu_stub` | 4 | 16.4s |  |
| 5 | `avm2_embed_bytearray` | 2 | 4.7s |  |
| 6 | `avm2_external_interface_unavailable` | 8 | 5.4s |  |
| 7 | `avm2_findprop_this_resolution` | 13 | 17.0s |  |
| 8 | `avm2_gc_dynprop_tombstone_purge` | 8 | 5.7s |  |
| 9 | `avm2_gc_string_concat_reclaim` | 10 | 5.7s |  |
| 10 | `avm2_gc_string_survives_collect` | 9 | 5.6s |  |
| 11 | `avm2_graphics_runtime` | 7 | 23.6s |  |
| 12 | `avm2_localconnection_domain` | 4 | 5.3s |  |
| 13 | `avm2_morph` | 8 | 17.6s |  |
| 14 | `avm2_sharedobject_flushstatus` | 4 | 4.2s |  |
| 15 | `avm2_slot_default_template` | 34 | 4.3s |  |
| 16 | `avm2_static_and_store_slots` | 14 | 16.5s |  |
| 17 | `avm2_static_text` | 6 | 23.2s |  |
| 18 | `avm2_timeline_gradients` | 7 | 24.3s |  |
| 19 | `avm2_timeline_solid` | 6 | 26.8s |  |
| 20 | `avm2_timeline_stroke_gradient` | 9 | 7.2s |  |
| 21 | `avm2_timeline_text` | 4 | 17.1s |  |
| 22 | `avm2_tolerant_verify_quarantine` | 2 | 5.6s |  |
| 23 | `avm2_typed_value_ops` | 30 | 5.7s |  |
| 24 | `broadcast_cross_swf_version` | 4 | 20.4s |  |
| 25 | `broadcast_type1_args` | 14 | 1.5s |  |
| 26 | `coerce_cross_swf_version` | 7 | 15.9s |  |
| 27 | `coerce_recursion_guard` | 1 | 1.9s |  |
| 28 | `coerce_type1_args` | 9 | 1.9s |  |
| 29 | `convertfloat_type1_this` | 3 | 1.9s |  |
| 30 | `ei_closure_scope_order` | 7 | 2.0s |  |
| 31 | `ei_cross_swf_version` | 2 | 1.9s |  |
| 32 | `ei_type1_args` | 7 | 1.9s |  |
| 33 | `enterframe_type1_args` | 8 | 0.8s |  |
| 34 | `fn_call_builtin_type1_args` | 10 | 0.8s |  |
| 35 | `fn_call_type1_args` | 7 | 1.2s |  |
| 36 | `fn_empty_method_type1_args` | 10 | 1.2s |  |
| 37 | `lc_method_type1_args` | 7 | 1.2s |  |
| 38 | `lc_onstatus_type1_args` | 3 | 1.2s |  |
| 39 | `lv_cross_swf_version` | 5 | 20.3s |  |
| 40 | `lv_ondata_type1_args` | 3 | 20.4s |  |
| 41 | `mc_event_cross_swf_version` | 4 | 20.7s |  |
| 42 | `mc_event_type1_args` | 3 | 1.9s |  |
| 43 | `mc_method_v5_caller_gate` | 4 | 20.5s |  |
| 44 | `mc_resolve_type1_args` | 6 | 1.9s |  |
| 45 | `method_type1_args` | 10 | 1.2s |  |
| 46 | `nc_onstatus_closure` | 2 | 18.9s |  |
| 47 | `nc_onstatus_type1_args` | 3 | 1.6s |  |
| 48 | `onconstruct_cross_swf_version` | 4 | 19.8s |  |
| 49 | `onconstruct_type1_args` | 6 | 1.9s |  |
| 50 | `onload_type1_args` | 7 | 20.7s |  |
| 51 | `onunload_type1_args` | 6 | 1.1s |  |
| 52 | `onunload_type1_local_frame` | 2 | 1.9s |  |
| 53 | `resolve_type1_args` | 13 | 1.8s |  |
| 54 | `root_enterframe_cross_swf_version` | 3 | 19.5s |  |
| 55 | `sort_comparator_captured_scope` | 2 | 20.5s |  |
| 56 | `sort_comparator_type1_args` | 5 | 1.8s |  |
| 57 | `string_prim_method_type1_args` | 19 | 1.5s |  |
| 58 | `timer_cross_swf_version` | 3 | 19.2s |  |
| 59 | `timer_type1_args` | 14 | 2.0s |  |
| 60 | `watch_cross_swf_version` | 6 | 20.7s |  |
| 61 | `watch_mc_reentrant_setmember` | 3 | 0.9s |  |
| 62 | `watch_mc_type1_args` | 7 | 1.5s |  |
| 63 | `watch_setmember_type1_args` | 7 | 1.9s |  |
| 64 | `watch_timeline_named_params` | 4 | 1.8s |  |
| 65 | `watch_timeline_reentrant` | 3 | 1.6s |  |
| 66 | `xml_onload_type1_args` | 3 | 20.0s |  |

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
