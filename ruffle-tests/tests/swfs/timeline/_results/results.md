# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 22:24 UTC

**Git SHA**: `0224aaf256`

**Run Duration**: 4m 58s

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
| 1 | `clip_action_no_key_code` | 1 | 24.8s |  |
| 2 | `frame_label_count_oom` | 1 | 24.3s |  |
| 3 | `frame_script_cleanup` | 30 | 8.7s |  |
| 4 | `frame_script_cleanup2` | 32 | 5.8s |  |
| 5 | `frame_script_cleanup3` | 30 | 9.2s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 6.3s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 6.4s |  |
| 8 | `frame_script_construct` | 25 | 22.7s |  |
| 9 | `missing_frame_scripts` | 22 | 31.5s |  |
| 10 | `scene_count_oom` | 1 | 1.0s |  |
| 11 | `swf_9_event_goto_frame_script` | 5 | 26.0s |  |
| 12 | `swf_9_frame_script_button_order` | 15 | 23.7s |  |
| 13 | `swf_9_frame_script_cleanup_goto` | 30 | 7.6s |  |
| 14 | `swf_9_frame_script_cleanup_goto2` | 34 | 24.6s |  |
| 15 | `swf_9_frame_script_dynamic_goto` | 34 | 24.8s |  |
| 16 | `swf_9_frame_script_dynamic_goto_2` | 33 | 25.0s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 25.2s |  |

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
