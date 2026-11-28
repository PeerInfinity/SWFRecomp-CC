# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 07:02 UTC

**Git SHA**: `3dfab12779`

**Run Duration**: 5m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 17 |
| Passing | **16** (94.1%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **17** (100.0%) |
| Failing | 0 |
| Total expected lines | 371 |
| Matching lines | 370 (99.7%) |
| Mismatched lines | 1 |

## Passing Tests

**16 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `clip_action_no_key_code` | 1 | 20.9s |  |
| 2 | `frame_label_count_oom` | 1 | 20.4s |  |
| 3 | `frame_script_cleanup` | 30 | 7.8s |  |
| 4 | `frame_script_cleanup2` | 32 | 29.4s |  |
| 5 | `frame_script_cleanup3` | 30 | 26.7s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 7.9s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 7.9s |  |
| 8 | `frame_script_construct` | 25 | 7.6s |  |
| 9 | `missing_frame_scripts` | 22 | 25.2s |  |
| 10 | `scene_count_oom` | 1 | 2.6s |  |
| 11 | `swf_9_event_goto_frame_script` | 5 | 29.6s |  |
| 12 | `swf_9_frame_script_button_order` | 15 | 26.9s |  |
| 13 | `swf_9_frame_script_cleanup_goto` | 30 | 7.8s |  |
| 14 | `swf_9_frame_script_cleanup_goto2` | 34 | 22.6s |  |
| 15 | `swf_9_frame_script_dynamic_goto` | 34 | 29.7s |  |
| 16 | `swf_9_frame_script_dynamic_goto_2` | 33 | 25.7s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 26.0s |  |

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
