# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 20:03 UTC

**Git SHA**: `b4d4457f16`

**Run Duration**: 12m 40s

**Filtered**: 0 tests ignored out of 70 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 70 |
| Passing | **69** (98.6%) |
| Failing | 1 |
| Total expected lines | 481 |
| Matching lines | 480 (99.8%) |
| Mismatched lines | 1 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**69 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array_element_type1_args` | 7 | 1.9s |  |
| 2 | `array_method_type1_args` | 7 | 1.9s |  |
| 3 | `avm2_agi_shell` | 6 | 23.5s |  |
| 4 | `avm2_bitmapdata_draw_textfield` | 5 | 25.6s |  |
| 5 | `avm2_contextmenu_stub` | 4 | 7.8s |  |
| 6 | `avm2_embed_bytearray` | 2 | 7.8s |  |
| 7 | `avm2_external_interface_unavailable` | 8 | 23.9s |  |
| 8 | `avm2_gc_dynprop_tombstone_purge` | 8 | 7.7s |  |
| 9 | `avm2_gc_string_concat_reclaim` | 10 | 19.0s |  |
| 10 | `avm2_gc_string_survives_collect` | 9 | 6.0s |  |
| 11 | `avm2_goto_catchup_scale` | 4 | 6.1s |  |
| 12 | `avm2_graphics_runtime` | 7 | 42.5s |  |
| 13 | `avm2_loader_stub` | 5 | 7.5s |  |
| 14 | `avm2_localconnection_domain` | 4 | 7.4s |  |
| 15 | `avm2_morph` | 8 | 26.1s |  |
| 16 | `avm2_sharedobject_flushstatus` | 4 | 7.3s |  |
| 17 | `avm2_simplebutton_click` | 2 | 7.5s |  |
| 18 | `avm2_slot_default_template` | 34 | 23.5s |  |
| 19 | `avm2_static_and_store_slots` | 14 | 7.4s |  |
| 20 | `avm2_static_text` | 6 | 26.1s |  |
| 21 | `avm2_timeline_gradients` | 7 | 49.6s |  |
| 22 | `avm2_timeline_solid` | 6 | 9.3s |  |
| 23 | `avm2_timeline_stroke_gradient` | 9 | 9.1s |  |
| 24 | `avm2_timeline_text` | 4 | 23.8s |  |
| 25 | `avm2_tolerant_verify_quarantine` | 2 | 7.3s |  |
| 26 | `avm2_typed_value_ops` | 30 | 7.6s |  |
| 27 | `broadcast_cross_swf_version` | 4 | 15.6s |  |
| 28 | `broadcast_type1_args` | 14 | 1.3s |  |
| 29 | `coerce_cross_swf_version` | 7 | 1.5s |  |
| 30 | `coerce_recursion_guard` | 1 | 1.7s |  |
| 31 | `coerce_type1_args` | 9 | 1.7s |  |
| 32 | `convertfloat_type1_this` | 3 | 2.0s |  |
| 33 | `ei_closure_scope_order` | 7 | 2.1s |  |
| 34 | `ei_cross_swf_version` | 2 | 2.1s |  |
| 35 | `ei_type1_args` | 7 | 2.1s |  |
| 36 | `enterframe_type1_args` | 8 | 21.1s |  |
| 37 | `fn_call_builtin_type1_args` | 10 | 1.9s |  |
| 38 | `fn_call_type1_args` | 7 | 2.0s |  |
| 39 | `fn_empty_method_type1_args` | 10 | 2.0s |  |
| 40 | `lc_method_type1_args` | 7 | 2.0s |  |
| 41 | `lc_onstatus_type1_args` | 3 | 1.9s |  |
| 42 | `lv_cross_swf_version` | 5 | 20.9s |  |
| 43 | `lv_ondata_type1_args` | 3 | 20.9s |  |
| 44 | `mc_event_cross_swf_version` | 4 | 21.5s |  |
| 45 | `mc_event_type1_args` | 3 | 2.0s |  |
| 46 | `mc_method_v5_caller_gate` | 4 | 17.5s |  |
| 47 | `mc_resolve_type1_args` | 6 | 1.7s |  |
| 48 | `method_type1_args` | 10 | 2.1s |  |
| 49 | `nc_onstatus_closure` | 2 | 21.4s |  |
| 50 | `nc_onstatus_type1_args` | 3 | 1.9s |  |
| 51 | `onconstruct_cross_swf_version` | 4 | 21.4s |  |
| 52 | `onconstruct_type1_args` | 6 | 1.8s |  |
| 53 | `onload_type1_args` | 7 | 20.5s |  |
| 54 | `onunload_type1_args` | 6 | 0.9s |  |
| 55 | `onunload_type1_local_frame` | 2 | 2.0s |  |
| 56 | `resolve_type1_args` | 13 | 1.7s |  |
| 57 | `root_enterframe_cross_swf_version` | 3 | 17.4s |  |
| 58 | `sort_comparator_captured_scope` | 2 | 21.7s |  |
| 59 | `sort_comparator_type1_args` | 5 | 2.0s |  |
| 60 | `string_prim_method_type1_args` | 19 | 2.0s |  |
| 61 | `timer_cross_swf_version` | 3 | 20.7s |  |
| 62 | `timer_type1_args` | 14 | 20.9s |  |
| 63 | `watch_cross_swf_version` | 6 | 21.0s |  |
| 64 | `watch_mc_reentrant_setmember` | 3 | 0.9s |  |
| 65 | `watch_mc_type1_args` | 7 | 1.0s |  |
| 66 | `watch_setmember_type1_args` | 7 | 1.9s |  |
| 67 | `watch_timeline_named_params` | 4 | 1.9s |  |
| 68 | `watch_timeline_reentrant` | 3 | 2.1s |  |
| 69 | `xml_onload_type1_args` | 3 | 21.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `avm2_findprop_this_resolution` | 92.3% | 12 | 13 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `avm2_findprop_this_resolution` | 92.3% | 12/13 | 13 | 13 |  |
