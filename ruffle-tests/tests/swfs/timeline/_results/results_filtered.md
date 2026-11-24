# Ruffle Test Results (Filtered)

**Date**: 2026-11-24 00:12 UTC

**Git SHA**: `005bea42a2`

**Run Duration**: 4m 30s

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
| 1 | `clip_action_no_key_code` | 1 | 17.4s |  |
| 2 | `frame_label_count_oom` | 1 | 1.7s |  |
| 3 | `frame_script_cleanup` | 30 | 23.4s |  |
| 4 | `frame_script_cleanup2` | 32 | 24.2s |  |
| 5 | `frame_script_cleanup3` | 30 | 23.3s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 22.7s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 6.1s |  |
| 8 | `frame_script_construct` | 25 | 22.6s |  |
| 9 | `missing_frame_scripts` | 22 | 18.6s |  |
| 10 | `scene_count_oom` | 1 | 1.0s |  |
| 11 | `swf_9_frame_script_button_order` | 15 | 6.1s |  |
| 12 | `swf_9_frame_script_cleanup_goto` | 30 | 5.1s |  |
| 13 | `swf_9_frame_script_cleanup_goto2` | 34 | 23.2s |  |
| 14 | `swf_9_frame_script_dynamic_goto_2` | 33 | 6.0s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 23.0s |  |
| 2 | `swf_9_event_goto_frame_script` | 2 | 2 | 22.8s |  |
| 3 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 22.7s |  |

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
