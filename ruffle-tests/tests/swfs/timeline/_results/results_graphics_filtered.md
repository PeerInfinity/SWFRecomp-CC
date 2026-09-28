# Ruffle Test Results (Filtered)

**Date**: 2026-09-28 21:10 UTC

**Git SHA**: `1b7a987cf4`

**Run Duration**: 5m 33s

**Filtered**: 0 tests ignored out of 17 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 17 |
| Passing | **13** (76.5%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **16** (94.1%) |
| Failing | 1 |
| Total expected lines | 371 |
| Matching lines | 355 (95.7%) |
| Mismatched lines | 16 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**13 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `clip_action_no_key_code` | 1 | 21.7s |  |
| 2 | `frame_label_count_oom` | 1 | 1.5s |  |
| 3 | `frame_script_cleanup` | 30 | 29.7s |  |
| 4 | `frame_script_cleanup2` | 32 | 29.5s |  |
| 5 | `frame_script_cleanup3` | 30 | 32.4s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 9.5s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 7.0s |  |
| 8 | `frame_script_construct` | 25 | 24.8s |  |
| 9 | `scene_count_oom` | 1 | 3.2s |  |
| 10 | `swf_9_frame_script_button_order` | 15 | 7.7s |  |
| 11 | `swf_9_frame_script_cleanup_goto` | 30 | 8.0s |  |
| 12 | `swf_9_frame_script_cleanup_goto2` | 34 | 21.9s |  |
| 13 | `swf_9_frame_script_dynamic_goto_2` | 33 | 30.8s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 23.2s |  |
| 2 | `swf_9_event_goto_frame_script` | 2 | 2 | 22.7s |  |
| 3 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 29.6s |  |

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

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `missing_frame_scripts` | 44.4% | 12/27 | 27 | 22 |  |
