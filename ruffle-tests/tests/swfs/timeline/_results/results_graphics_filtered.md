# Ruffle Test Results (Filtered)

**Date**: 2026-11-22 20:56 UTC

**Git SHA**: `9e24c763ca`

**Run Duration**: 5m 24s

**Filtered**: 0 tests ignored out of 17 available

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
| 1 | `clip_action_no_key_code` | 1 | 18.5s |  |
| 2 | `frame_label_count_oom` | 1 | 17.6s |  |
| 3 | `frame_script_cleanup` | 30 | 23.9s |  |
| 4 | `frame_script_cleanup2` | 32 | 23.1s |  |
| 5 | `frame_script_cleanup3` | 30 | 24.8s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 23.9s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 6.7s |  |
| 8 | `frame_script_construct` | 25 | 24.5s |  |
| 9 | `missing_frame_scripts` | 22 | 23.8s |  |
| 10 | `scene_count_oom` | 1 | 2.4s |  |
| 11 | `swf_9_frame_script_button_order` | 15 | 8.6s |  |
| 12 | `swf_9_frame_script_cleanup_goto` | 30 | 7.0s |  |
| 13 | `swf_9_frame_script_cleanup_goto2` | 34 | 21.2s |  |
| 14 | `swf_9_frame_script_dynamic_goto_2` | 33 | 24.7s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 23.5s |  |
| 2 | `swf_9_event_goto_frame_script` | 2 | 2 | 25.5s |  |
| 3 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 23.6s |  |

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
