# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 02:31 UTC

**Git SHA**: `b8671fd2f5`

**Run Duration**: 6m 10s

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
| 1 | `clip_action_no_key_code` | 1 | 19.7s |  |
| 2 | `frame_label_count_oom` | 1 | 20.1s |  |
| 3 | `frame_script_cleanup` | 30 | 24.9s |  |
| 4 | `frame_script_cleanup2` | 32 | 24.8s |  |
| 5 | `frame_script_cleanup3` | 30 | 24.1s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 25.4s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 6.6s |  |
| 8 | `frame_script_construct` | 25 | 26.4s |  |
| 9 | `missing_frame_scripts` | 22 | 32.0s |  |
| 10 | `scene_count_oom` | 1 | 1.0s |  |
| 11 | `swf_9_event_goto_frame_script` | 5 | 24.5s |  |
| 12 | `swf_9_frame_script_button_order` | 15 | 33.9s |  |
| 13 | `swf_9_frame_script_cleanup_goto` | 30 | 6.5s |  |
| 14 | `swf_9_frame_script_cleanup_goto2` | 34 | 24.3s |  |
| 15 | `swf_9_frame_script_dynamic_goto` | 34 | 25.2s |  |
| 16 | `swf_9_frame_script_dynamic_goto_2` | 33 | 24.5s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 25.4s |  |

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
