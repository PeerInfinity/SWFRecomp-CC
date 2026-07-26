# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-25 23:58 UTC

**Git SHA**: `5da28a6a5b`

**Run Duration**: 7m 37s

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
| 1 | `array_element_type1_args` | 7 | 0.7s |  |
| 2 | `array_method_type1_args` | 7 | 0.7s |  |
| 3 | `avm2_agi_shell` | 6 | 16.5s |  |
| 4 | `avm2_bitmapdata_draw_textfield` | 5 | 17.4s |  |
| 5 | `avm2_contextmenu_stub` | 4 | 5.5s |  |
| 6 | `avm2_embed_bytearray` | 2 | 5.6s |  |
| 7 | `avm2_external_interface_unavailable` | 8 | 17.4s |  |
| 8 | `avm2_findprop_this_resolution` | 13 | 5.7s |  |
| 9 | `avm2_gc_dynprop_tombstone_purge` | 8 | 5.7s |  |
| 10 | `avm2_gc_string_concat_reclaim` | 10 | 17.3s |  |
| 11 | `avm2_gc_string_survives_collect` | 9 | 5.9s |  |
| 12 | `avm2_goto_catchup_scale` | 4 | 5.8s |  |
| 13 | `avm2_graphics_runtime` | 7 | 17.8s |  |
| 14 | `avm2_loader_stub` | 5 | 5.8s |  |
| 15 | `avm2_localconnection_domain` | 4 | 5.8s |  |
| 16 | `avm2_morph` | 8 | 26.2s |  |
| 17 | `avm2_sharedobject_flushstatus` | 4 | 6.1s |  |
| 18 | `avm2_simplebutton_click` | 2 | 6.3s |  |
| 19 | `avm2_slot_default_template` | 34 | 13.4s |  |
| 20 | `avm2_static_and_store_slots` | 14 | 4.7s |  |
| 21 | `avm2_static_text` | 6 | 4.2s |  |
| 22 | `avm2_timeline_gradients` | 7 | 39.4s |  |
| 23 | `avm2_timeline_solid` | 6 | 7.0s |  |
| 24 | `avm2_timeline_stroke_gradient` | 9 | 7.2s |  |
| 25 | `avm2_timeline_text` | 4 | 17.4s |  |
| 26 | `avm2_tolerant_verify_quarantine` | 2 | 5.5s |  |
| 27 | `avm2_typed_value_ops` | 30 | 5.8s |  |
| 28 | `broadcast_cross_swf_version` | 4 | 1.8s |  |
| 29 | `broadcast_type1_args` | 14 | 1.7s |  |
| 30 | `coerce_cross_swf_version` | 7 | 1.8s |  |
| 31 | `coerce_recursion_guard` | 1 | 1.6s |  |
| 32 | `coerce_type1_args` | 9 | 1.6s |  |
| 33 | `convertfloat_type1_this` | 3 | 1.8s |  |
| 34 | `ei_closure_scope_order` | 7 | 1.9s |  |
| 35 | `ei_cross_swf_version` | 2 | 1.9s |  |
| 36 | `ei_type1_args` | 7 | 1.9s |  |
| 37 | `enterframe_type1_args` | 8 | 20.4s |  |
| 38 | `fn_call_builtin_type1_args` | 10 | 1.8s |  |
| 39 | `fn_call_type1_args` | 7 | 1.5s |  |
| 40 | `fn_empty_method_type1_args` | 10 | 1.5s |  |
| 41 | `lc_method_type1_args` | 7 | 2.0s |  |
| 42 | `lc_onstatus_type1_args` | 3 | 1.9s |  |
| 43 | `lv_cross_swf_version` | 5 | 16.3s |  |
| 44 | `lv_ondata_type1_args` | 3 | 1.5s |  |
| 45 | `mc_event_cross_swf_version` | 4 | 2.1s |  |
| 46 | `mc_event_type1_args` | 3 | 1.9s |  |
| 47 | `mc_method_v5_caller_gate` | 4 | 2.0s |  |
| 48 | `mc_resolve_type1_args` | 6 | 1.9s |  |
| 49 | `method_type1_args` | 10 | 2.0s |  |
| 50 | `nc_onstatus_closure` | 2 | 22.6s |  |
| 51 | `nc_onstatus_type1_args` | 3 | 1.8s |  |
| 52 | `onconstruct_cross_swf_version` | 4 | 1.9s |  |
| 53 | `onconstruct_type1_args` | 6 | 1.6s |  |
| 54 | `onload_type1_args` | 7 | 17.0s |  |
| 55 | `onunload_type1_args` | 6 | 0.8s |  |
| 56 | `onunload_type1_local_frame` | 2 | 1.6s |  |
| 57 | `resolve_type1_args` | 13 | 1.8s |  |
| 58 | `root_enterframe_cross_swf_version` | 3 | 20.5s |  |
| 59 | `sort_comparator_captured_scope` | 2 | 2.0s |  |
| 60 | `sort_comparator_type1_args` | 5 | 1.9s |  |
| 61 | `string_prim_method_type1_args` | 19 | 1.9s |  |
| 62 | `timer_cross_swf_version` | 3 | 2.1s |  |
| 63 | `timer_type1_args` | 14 | 20.9s |  |
| 64 | `watch_cross_swf_version` | 6 | 0.8s |  |
| 65 | `watch_mc_reentrant_setmember` | 3 | 0.7s |  |
| 66 | `watch_mc_type1_args` | 7 | 0.7s |  |
| 67 | `watch_setmember_type1_args` | 7 | 0.7s |  |
| 68 | `watch_timeline_named_params` | 4 | 0.7s |  |
| 69 | `watch_timeline_reentrant` | 3 | 0.6s |  |
| 70 | `xml_onload_type1_args` | 3 | 0.6s |  |

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
