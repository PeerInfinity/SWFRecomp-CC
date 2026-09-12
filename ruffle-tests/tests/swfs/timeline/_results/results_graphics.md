# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-12 02:42 UTC

**Git SHA**: `d8da5a18c3`

**Run Duration**: 5m 37s

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
| 1 | `clip_action_no_key_code` | 1 | 21.8s |  |
| 2 | `frame_label_count_oom` | 1 | 2.0s |  |
| 3 | `frame_script_cleanup` | 30 | 30.5s |  |
| 4 | `frame_script_cleanup2` | 32 | 28.9s |  |
| 5 | `frame_script_cleanup3` | 30 | 29.0s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 7.6s |  |
| 7 | `frame_script_cleanup_goto2` | 34 | 9.7s |  |
| 8 | `frame_script_construct` | 25 | 29.3s |  |
| 9 | `scene_count_oom` | 1 | 1.4s |  |
| 10 | `swf_9_frame_script_button_order` | 15 | 8.4s |  |
| 11 | `swf_9_frame_script_cleanup_goto` | 30 | 27.9s |  |
| 12 | `swf_9_frame_script_cleanup_goto2` | 34 | 28.9s |  |
| 13 | `swf_9_frame_script_dynamic_goto_2` | 33 | 18.6s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 23.2s |  |
| 2 | `swf_9_event_goto_frame_script` | 2 | 2 | 22.4s |  |
| 3 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 17.1s |  |

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
