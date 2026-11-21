# Ruffle Test Results (Filtered)

**Date**: 2026-11-21 19:30 UTC

**Git SHA**: `bc91565cea`

**Run Duration**: 3m 15s

**Filtered**: 0 tests ignored out of 17 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **14** (87.5%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **16** (100.0%) |
| Failing | 0 |
| Total expected lines | 366 |
| Matching lines | 362 (98.9%) |
| Mismatched lines | 4 |

## Passing Tests

**14 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `clip_action_no_key_code` | 1 | 17.1s |  |
| 2 | `frame_label_count_oom` | 1 | 0.9s |  |
| 3 | `frame_script_cleanup` | 30 | 6.0s |  |
| 4 | `frame_script_cleanup2` | 32 | 21.8s |  |
| 5 | `frame_script_cleanup3` | 30 | 6.0s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 5.9s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 6.1s |  |
| 8 | `frame_script_construct` | 25 | 6.0s |  |
| 9 | `missing_frame_scripts` | 22 | 5.8s |  |
| 10 | `scene_count_oom` | 1 | 1.4s |  |
| 11 | `swf_9_frame_script_button_order` | 15 | 5.9s |  |
| 12 | `swf_9_frame_script_cleanup_goto` | 30 | 6.0s |  |
| 13 | `swf_9_frame_script_cleanup_goto2` | 34 | 29.8s |  |
| 14 | `swf_9_frame_script_dynamic_goto_2` | 33 | 23.4s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 23.3s |  |
| 2 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 28.7s |  |

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
