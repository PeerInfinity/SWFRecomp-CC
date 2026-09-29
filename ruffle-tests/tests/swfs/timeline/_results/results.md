# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-29 02:24 UTC

**Git SHA**: `7755698f83`

**Run Duration**: 5m 11s

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
| 1 | `clip_action_no_key_code` | 1 | 15.0s |  |
| 2 | `frame_label_count_oom` | 1 | 0.9s |  |
| 3 | `frame_script_cleanup` | 30 | 27.6s |  |
| 4 | `frame_script_cleanup2` | 32 | 21.2s |  |
| 5 | `frame_script_cleanup3` | 30 | 24.0s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 7.9s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 6.7s |  |
| 8 | `frame_script_construct` | 25 | 27.1s |  |
| 9 | `missing_frame_scripts` | 22 | 27.4s |  |
| 10 | `scene_count_oom` | 1 | 1.5s |  |
| 11 | `swf_9_frame_script_button_order` | 15 | 8.0s |  |
| 12 | `swf_9_frame_script_cleanup_goto` | 30 | 7.7s |  |
| 13 | `swf_9_frame_script_cleanup_goto2` | 34 | 28.2s |  |
| 14 | `swf_9_frame_script_dynamic_goto_2` | 33 | 28.3s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 27.6s |  |
| 2 | `swf_9_event_goto_frame_script` | 2 | 2 | 28.5s |  |
| 3 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 22.1s |  |

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
