# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 22:36 UTC

**Git SHA**: `16033a1546`

**Run Duration**: 6m 20s

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
| 1 | `clip_action_no_key_code` | 1 | 19.2s |  |
| 2 | `frame_label_count_oom` | 1 | 21.6s |  |
| 3 | `frame_script_cleanup` | 30 | 25.9s |  |
| 4 | `frame_script_cleanup2` | 32 | 26.4s |  |
| 5 | `frame_script_cleanup3` | 30 | 30.5s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 21.9s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 9.1s |  |
| 8 | `frame_script_construct` | 25 | 25.0s |  |
| 9 | `missing_frame_scripts` | 22 | 25.1s |  |
| 10 | `scene_count_oom` | 1 | 1.7s |  |
| 11 | `swf_9_frame_script_button_order` | 15 | 26.8s |  |
| 12 | `swf_9_frame_script_cleanup_goto` | 30 | 7.8s |  |
| 13 | `swf_9_frame_script_cleanup_goto2` | 34 | 25.6s |  |
| 14 | `swf_9_frame_script_dynamic_goto_2` | 33 | 32.9s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 25.0s |  |
| 2 | `swf_9_event_goto_frame_script` | 2 | 2 | 27.1s |  |
| 3 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 27.7s |  |

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
