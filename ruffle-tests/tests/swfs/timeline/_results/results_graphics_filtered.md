# Ruffle Test Results (Filtered)

**Date**: 2026-11-28 00:52 UTC

**Git SHA**: `9498e80c12`

**Run Duration**: 6m 31s

**Filtered**: 0 tests ignored out of 17 available

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
| 1 | `clip_action_no_key_code` | 1 | 17.5s |  |
| 2 | `frame_label_count_oom` | 1 | 19.3s |  |
| 3 | `frame_script_cleanup` | 30 | 27.6s |  |
| 4 | `frame_script_cleanup2` | 32 | 27.8s |  |
| 5 | `frame_script_cleanup3` | 30 | 26.3s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 26.7s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 7.8s |  |
| 8 | `frame_script_construct` | 25 | 25.9s |  |
| 9 | `missing_frame_scripts` | 22 | 29.0s |  |
| 10 | `scene_count_oom` | 1 | 2.1s |  |
| 11 | `swf_9_event_goto_frame_script` | 5 | 25.8s |  |
| 12 | `swf_9_frame_script_button_order` | 15 | 28.2s |  |
| 13 | `swf_9_frame_script_cleanup_goto` | 30 | 7.7s |  |
| 14 | `swf_9_frame_script_cleanup_goto2` | 34 | 34.0s |  |
| 15 | `swf_9_frame_script_dynamic_goto` | 34 | 23.5s |  |
| 16 | `swf_9_frame_script_dynamic_goto_2` | 33 | 33.7s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 26.9s |  |

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
