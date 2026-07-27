# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-27 20:41 UTC

**Git SHA**: `3c0d4817f8`

**Run Duration**: 17m 43s

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
| 1 | `array_element_type1_args` | 7 | 16.6s |  |
| 2 | `array_method_type1_args` | 7 | 1.3s |  |
| 3 | `avm2_agi_shell` | 6 | 14.7s |  |
| 4 | `avm2_bitmapdata_draw_textfield` | 5 | 18.0s |  |
| 5 | `avm2_contextmenu_stub` | 4 | 6.2s |  |
| 6 | `avm2_embed_bytearray` | 2 | 25.1s |  |
| 7 | `avm2_external_interface_unavailable` | 8 | 17.2s |  |
| 8 | `avm2_findprop_this_resolution` | 13 | 6.0s |  |
| 9 | `avm2_gc_dynprop_tombstone_purge` | 8 | 6.1s |  |
| 10 | `avm2_gc_string_concat_reclaim` | 10 | 17.4s |  |
| 11 | `avm2_gc_string_survives_collect` | 9 | 6.1s |  |
| 12 | `avm2_goto_catchup_scale` | 4 | 6.6s |  |
| 13 | `avm2_graphics_runtime` | 7 | 37.1s |  |
| 14 | `avm2_loader_stub` | 5 | 5.9s |  |
| 15 | `avm2_localconnection_domain` | 4 | 5.8s |  |
| 16 | `avm2_morph` | 8 | 20.0s |  |
| 17 | `avm2_sharedobject_flushstatus` | 4 | 4.9s |  |
| 18 | `avm2_simplebutton_click` | 2 | 4.9s |  |
| 19 | `avm2_slot_default_template` | 34 | 17.1s |  |
| 20 | `avm2_static_and_store_slots` | 14 | 5.8s |  |
| 21 | `avm2_static_text` | 6 | 24.2s |  |
| 22 | `avm2_timeline_gradients` | 7 | 38.5s |  |
| 23 | `avm2_timeline_solid` | 6 | 6.9s |  |
| 24 | `avm2_timeline_stroke_gradient` | 9 | 7.2s |  |
| 25 | `avm2_timeline_text` | 4 | 18.1s |  |
| 26 | `avm2_tolerant_verify_quarantine` | 2 | 6.2s |  |
| 27 | `avm2_typed_value_ops` | 30 | 6.4s |  |
| 28 | `broadcast_cross_swf_version` | 4 | 22.4s |  |
| 29 | `broadcast_type1_args` | 14 | 21.9s |  |
| 30 | `coerce_cross_swf_version` | 7 | 2.1s |  |
| 31 | `coerce_recursion_guard` | 1 | 20.1s |  |
| 32 | `coerce_type1_args` | 9 | 1.9s |  |
| 33 | `convertfloat_type1_this` | 3 | 20.3s |  |
| 34 | `ei_closure_scope_order` | 7 | 1.9s |  |
| 35 | `ei_cross_swf_version` | 2 | 20.4s |  |
| 36 | `ei_type1_args` | 7 | 1.9s |  |
| 37 | `enterframe_type1_args` | 8 | 22.0s |  |
| 38 | `fn_call_builtin_type1_args` | 10 | 21.6s |  |
| 39 | `fn_call_type1_args` | 7 | 20.1s |  |
| 40 | `fn_empty_method_type1_args` | 10 | 1.9s |  |
| 41 | `lc_method_type1_args` | 7 | 20.7s |  |
| 42 | `lc_onstatus_type1_args` | 3 | 1.9s |  |
| 43 | `lv_cross_swf_version` | 5 | 17.5s |  |
| 44 | `lv_ondata_type1_args` | 3 | 17.7s |  |
| 45 | `mc_event_cross_swf_version` | 4 | 22.4s |  |
| 46 | `mc_event_type1_args` | 3 | 22.1s |  |
| 47 | `mc_method_v5_caller_gate` | 4 | 20.8s |  |
| 48 | `mc_resolve_type1_args` | 6 | 20.5s |  |
| 49 | `method_type1_args` | 10 | 20.1s |  |
| 50 | `nc_onstatus_closure` | 2 | 20.1s |  |
| 51 | `nc_onstatus_type1_args` | 3 | 20.2s |  |
| 52 | `onconstruct_cross_swf_version` | 4 | 20.2s |  |
| 53 | `onconstruct_type1_args` | 6 | 16.9s |  |
| 54 | `onload_type1_args` | 7 | 16.6s |  |
| 55 | `onunload_type1_args` | 6 | 19.5s |  |
| 56 | `onunload_type1_local_frame` | 2 | 1.6s |  |
| 57 | `resolve_type1_args` | 13 | 20.1s |  |
| 58 | `root_enterframe_cross_swf_version` | 3 | 20.1s |  |
| 59 | `sort_comparator_captured_scope` | 2 | 20.8s |  |
| 60 | `sort_comparator_type1_args` | 5 | 20.7s |  |
| 61 | `string_prim_method_type1_args` | 19 | 21.7s |  |
| 62 | `timer_cross_swf_version` | 3 | 21.7s |  |
| 63 | `timer_type1_args` | 14 | 20.6s |  |
| 64 | `watch_cross_swf_version` | 6 | 20.8s |  |
| 65 | `watch_mc_reentrant_setmember` | 3 | 19.5s |  |
| 66 | `watch_mc_type1_args` | 7 | 1.6s |  |
| 67 | `watch_setmember_type1_args` | 7 | 21.1s |  |
| 68 | `watch_timeline_named_params` | 4 | 1.9s |  |
| 69 | `watch_timeline_reentrant` | 3 | 20.2s |  |
| 70 | `xml_onload_type1_args` | 3 | 20.8s |  |

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
