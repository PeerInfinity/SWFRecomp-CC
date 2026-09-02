# Ruffle Test Results (Filtered)

**Date**: 2026-09-02 21:29 UTC

**Git SHA**: `c6681e7447`

**Run Duration**: 10m 17s

**Filtered**: 0 tests ignored out of 72 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 72 |
| Passing | **72** (100.0%) |
| Failing | 0 |
| Total expected lines | 483 |
| Matching lines | 483 (100.0%) |
| Mismatched lines | 0 |

## Passing Tests

**72 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 1.9s |  |
| 2 | `array_method_type1_args` | 7 | 1.9s |  |
| 3 | `avm2_agi_shell` | 6 | 8.3s |  |
| 4 | `avm2_bitmapdata_draw_textfield` | 5 | 8.1s |  |
| 5 | `avm2_contextmenu_stub` | 4 | 7.6s |  |
| 6 | `avm2_embed_bytearray` | 2 | 7.6s |  |
| 7 | `avm2_external_interface_unavailable` | 8 | 8.5s |  |
| 8 | `avm2_findprop_this_resolution` | 13 | 8.4s |  |
| 9 | `avm2_gc_dynprop_tombstone_purge` | 8 | 8.5s |  |
| 10 | `avm2_gc_string_concat_reclaim` | 10 | 7.1s |  |
| 11 | `avm2_gc_string_survives_collect` | 9 | 6.9s |  |
| 12 | `avm2_goto_catchup_scale` | 4 | 7.0s |  |
| 13 | `avm2_graphics_runtime` | 7 | 29.2s |  |
| 14 | `avm2_loader_stub` | 5 | 8.1s |  |
| 15 | `avm2_localconnection_domain` | 4 | 8.1s |  |
| 16 | `avm2_morph` | 8 | 20.4s |  |
| 17 | `avm2_sharedobject_flushstatus` | 4 | 5.9s |  |
| 18 | `avm2_simplebutton_click` | 2 | 6.3s |  |
| 19 | `avm2_slot_default_template` | 34 | 8.4s |  |
| 20 | `avm2_static_and_store_slots` | 14 | 8.3s |  |
| 21 | `avm2_static_text` | 6 | 26.9s |  |
| 22 | `avm2_timeline_gradients` | 7 | 31.3s |  |
| 23 | `avm2_timeline_solid` | 6 | 9.4s |  |
| 24 | `avm2_timeline_stroke_gradient` | 9 | 9.7s |  |
| 25 | `avm2_timeline_text` | 4 | 9.3s |  |
| 26 | `avm2_tolerant_verify_quarantine` | 2 | 8.8s |  |
| 27 | `avm2_typed_value_ops` | 30 | 9.3s |  |
| 28 | `broadcast_cross_swf_version` | 4 | 21.4s |  |
| 29 | `broadcast_type1_args` | 14 | 2.1s |  |
| 30 | `coerce_cross_swf_version` | 7 | 2.2s |  |
| 31 | `coerce_recursion_guard` | 1 | 1.7s |  |
| 32 | `coerce_type1_args` | 9 | 1.7s |  |
| 33 | `convertfloat_type1_this` | 3 | 1.2s |  |
| 34 | `ei_closure_scope_order` | 7 | 1.9s |  |
| 35 | `ei_cross_swf_version` | 2 | 1.8s |  |
| 36 | `ei_type1_args` | 7 | 2.0s |  |
| 37 | `enterframe_type1_args` | 8 | 1.0s |  |
| 38 | `fn_call_builtin_type1_args` | 10 | 1.0s |  |
| 39 | `fn_call_type1_args` | 7 | 1.7s |  |
| 40 | `fn_empty_method_type1_args` | 10 | 1.7s |  |
| 41 | `lc_method_type1_args` | 7 | 1.5s |  |
| 42 | `lc_onstatus_type1_args` | 3 | 1.5s |  |
| 43 | `lv_cross_swf_version` | 5 | 21.2s |  |
| 44 | `lv_ondata_type1_args` | 3 | 21.0s |  |
| 45 | `mask_nested_intersect` | 1 | 21.5s |  |
| 46 | `mask_sibling_union` | 1 | 2.1s |  |
| 47 | `mc_event_cross_swf_version` | 4 | 21.6s |  |
| 48 | `mc_event_type1_args` | 3 | 2.1s |  |
| 49 | `mc_method_v5_caller_gate` | 4 | 21.8s |  |
| 50 | `mc_resolve_type1_args` | 6 | 2.1s |  |
| 51 | `method_type1_args` | 10 | 2.2s |  |
| 52 | `nc_onstatus_closure` | 2 | 22.2s |  |
| 53 | `nc_onstatus_type1_args` | 3 | 1.7s |  |
| 54 | `onconstruct_cross_swf_version` | 4 | 17.7s |  |
| 55 | `onconstruct_type1_args` | 6 | 1.3s |  |
| 56 | `onload_type1_args` | 7 | 16.2s |  |
| 57 | `onunload_type1_args` | 6 | 1.7s |  |
| 58 | `onunload_type1_local_frame` | 2 | 1.4s |  |
| 59 | `resolve_type1_args` | 13 | 1.2s |  |
| 60 | `root_enterframe_cross_swf_version` | 3 | 15.6s |  |
| 61 | `sort_comparator_captured_scope` | 2 | 14.4s |  |
| 62 | `sort_comparator_type1_args` | 5 | 1.5s |  |
| 63 | `string_prim_method_type1_args` | 19 | 2.1s |  |
| 64 | `timer_cross_swf_version` | 3 | 23.8s |  |
| 65 | `timer_type1_args` | 14 | 1.7s |  |
| 66 | `watch_cross_swf_version` | 6 | 17.7s |  |
| 67 | `watch_mc_reentrant_setmember` | 3 | 1.8s |  |
| 68 | `watch_mc_type1_args` | 7 | 1.8s |  |
| 69 | `watch_setmember_type1_args` | 7 | 1.8s |  |
| 70 | `watch_timeline_named_params` | 4 | 1.7s |  |
| 71 | `watch_timeline_reentrant` | 3 | 2.2s |  |
| 72 | `xml_onload_type1_args` | 3 | 22.3s |  |

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
