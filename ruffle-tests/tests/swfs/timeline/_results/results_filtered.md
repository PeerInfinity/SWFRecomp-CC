# Ruffle Test Results (Filtered)

**Date**: 2026-10-18 08:49 UTC

**Git SHA**: `f555113796`

**Run Duration**: 2m 53s

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
| 1 | `clip_action_no_key_code` | 1 | 1.4s |  |
| 2 | `frame_label_count_oom` | 1 | 1.5s |  |
| 3 | `frame_script_cleanup` | 30 | 8.4s |  |
| 4 | `frame_script_cleanup2` | 32 | 8.2s |  |
| 5 | `frame_script_cleanup3` | 30 | 8.3s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 8.3s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 8.3s |  |
| 8 | `frame_script_construct` | 25 | 5.2s |  |
| 9 | `missing_frame_scripts` | 22 | 28.0s |  |
| 10 | `scene_count_oom` | 1 | 1.3s |  |
| 11 | `swf_9_frame_script_button_order` | 15 | 28.0s |  |
| 12 | `swf_9_frame_script_cleanup_goto` | 30 | 8.3s |  |
| 13 | `swf_9_frame_script_cleanup_goto2` | 34 | 8.3s |  |
| 14 | `swf_9_frame_script_dynamic_goto_2` | 33 | 8.2s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 27.8s |  |
| 2 | `swf_9_event_goto_frame_script` | 2 | 2 | 7.6s |  |
| 3 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 4.9s |  |

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
