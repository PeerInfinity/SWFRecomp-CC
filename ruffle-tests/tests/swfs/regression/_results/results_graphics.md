# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-31 01:35 UTC

**Git SHA**: `b3d9eda9f3`

**Run Duration**: 10m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 70 |
| Passing | **70** (100.0%) |
| Failing | 0 |
| Total expected lines | 481 |
| Matching lines | 481 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**70 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 2.0s |  |
| 2 | `array_method_type1_args` | 7 | 1.9s |  |
| 3 | `avm2_agi_shell` | 6 | 6.7s |  |
| 4 | `avm2_bitmapdata_draw_textfield` | 5 | 11.1s |  |
| 5 | `avm2_contextmenu_stub` | 4 | 7.2s |  |
| 6 | `avm2_embed_bytearray` | 2 | 7.1s |  |
| 7 | `avm2_external_interface_unavailable` | 8 | 10.8s |  |
| 8 | `avm2_findprop_this_resolution` | 13 | 3.4s |  |
| 9 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.7s |  |
| 10 | `avm2_gc_string_concat_reclaim` | 10 | 10.6s |  |
| 11 | `avm2_gc_string_survives_collect` | 9 | 7.3s |  |
| 12 | `avm2_goto_catchup_scale` | 4 | 7.2s |  |
| 13 | `avm2_graphics_runtime` | 7 | 23.0s |  |
| 14 | `avm2_loader_stub` | 5 | 5.7s |  |
| 15 | `avm2_localconnection_domain` | 4 | 5.7s |  |
| 16 | `avm2_morph` | 8 | 27.1s |  |
| 17 | `avm2_sharedobject_flushstatus` | 4 | 7.4s |  |
| 18 | `avm2_simplebutton_click` | 2 | 7.3s |  |
| 19 | `avm2_slot_default_template` | 34 | 10.6s |  |
| 20 | `avm2_static_and_store_slots` | 14 | 7.2s |  |
| 21 | `avm2_static_text` | 6 | 25.7s |  |
| 22 | `avm2_timeline_gradients` | 7 | 31.1s |  |
| 23 | `avm2_timeline_solid` | 6 | 8.2s |  |
| 24 | `avm2_timeline_stroke_gradient` | 9 | 8.5s |  |
| 25 | `avm2_timeline_text` | 4 | 10.2s |  |
| 26 | `avm2_tolerant_verify_quarantine` | 2 | 6.6s |  |
| 27 | `avm2_typed_value_ops` | 30 | 6.8s |  |
| 28 | `broadcast_cross_swf_version` | 4 | 20.9s |  |
| 29 | `broadcast_type1_args` | 14 | 1.9s |  |
| 30 | `coerce_cross_swf_version` | 7 | 2.1s |  |
| 31 | `coerce_recursion_guard` | 1 | 1.9s |  |
| 32 | `coerce_type1_args` | 9 | 1.9s |  |
| 33 | `convertfloat_type1_this` | 3 | 1.8s |  |
| 34 | `ei_closure_scope_order` | 7 | 2.0s |  |
| 35 | `ei_cross_swf_version` | 2 | 2.1s |  |
| 36 | `ei_type1_args` | 7 | 2.0s |  |
| 37 | `enterframe_type1_args` | 8 | 17.9s |  |
| 38 | `fn_call_builtin_type1_args` | 10 | 1.4s |  |
| 39 | `fn_call_type1_args` | 7 | 1.7s |  |
| 40 | `fn_empty_method_type1_args` | 10 | 1.7s |  |
| 41 | `lc_method_type1_args` | 7 | 1.9s |  |
| 42 | `lc_onstatus_type1_args` | 3 | 1.8s |  |
| 43 | `lv_cross_swf_version` | 5 | 22.8s |  |
| 44 | `lv_ondata_type1_args` | 3 | 22.7s |  |
| 45 | `mc_event_cross_swf_version` | 4 | 22.5s |  |
| 46 | `mc_event_type1_args` | 3 | 2.1s |  |
| 47 | `mc_method_v5_caller_gate` | 4 | 19.4s |  |
| 48 | `mc_resolve_type1_args` | 6 | 1.8s |  |
| 49 | `method_type1_args` | 10 | 1.9s |  |
| 50 | `nc_onstatus_closure` | 2 | 21.1s |  |
| 51 | `nc_onstatus_type1_args` | 3 | 2.0s |  |
| 52 | `onconstruct_cross_swf_version` | 4 | 21.0s |  |
| 53 | `onconstruct_type1_args` | 6 | 1.6s |  |
| 54 | `onload_type1_args` | 7 | 16.3s |  |
| 55 | `onunload_type1_args` | 6 | 0.9s |  |
| 56 | `onunload_type1_local_frame` | 2 | 1.9s |  |
| 57 | `resolve_type1_args` | 13 | 2.0s |  |
| 58 | `root_enterframe_cross_swf_version` | 3 | 21.2s |  |
| 59 | `sort_comparator_captured_scope` | 2 | 21.0s |  |
| 60 | `sort_comparator_type1_args` | 5 | 1.7s |  |
| 61 | `string_prim_method_type1_args` | 19 | 1.5s |  |
| 62 | `timer_cross_swf_version` | 3 | 16.2s |  |
| 63 | `timer_type1_args` | 14 | 21.1s |  |
| 64 | `watch_cross_swf_version` | 6 | 20.8s |  |
| 65 | `watch_mc_reentrant_setmember` | 3 | 0.7s |  |
| 66 | `watch_mc_type1_args` | 7 | 0.7s |  |
| 67 | `watch_setmember_type1_args` | 7 | 2.0s |  |
| 68 | `watch_timeline_named_params` | 4 | 1.9s |  |
| 69 | `watch_timeline_reentrant` | 3 | 1.6s |  |
| 70 | `xml_onload_type1_args` | 3 | 19.5s |  |

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
