# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-28 23:17 UTC

**Git SHA**: `0341c033af`

**Run Duration**: 5m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 17 |
| Passing | **14** (82.4%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **17** (100.0%) |
| Failing | 0 |
| Total expected lines | 371 |
| Matching lines | 365 (98.4%) |
| Mismatched lines | 6 |

## Passing Tests

**14 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `clip_action_no_key_code` | 1 | 14.4s |  |
| 2 | `frame_label_count_oom` | 1 | 2.1s |  |
| 3 | `frame_script_cleanup` | 30 | 18.8s |  |
| 4 | `frame_script_cleanup2` | 32 | 23.3s |  |
| 5 | `frame_script_cleanup3` | 30 | 24.2s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 8.2s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 9.7s |  |
| 8 | `frame_script_construct` | 25 | 19.4s |  |
| 9 | `missing_frame_scripts` | 22 | 28.8s |  |
| 10 | `scene_count_oom` | 1 | 2.0s |  |
| 11 | `swf_9_frame_script_button_order` | 15 | 9.1s |  |
| 12 | `swf_9_frame_script_cleanup_goto` | 30 | 9.3s |  |
| 13 | `swf_9_frame_script_cleanup_goto2` | 34 | 28.9s |  |
| 14 | `swf_9_frame_script_dynamic_goto_2` | 33 | 28.9s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 29.6s |  |
| 2 | `swf_9_event_goto_frame_script` | 2 | 2 | 30.3s |  |
| 3 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 30.2s |  |

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
