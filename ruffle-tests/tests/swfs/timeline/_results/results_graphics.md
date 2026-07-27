# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-27 21:16 UTC

**Git SHA**: `1b63b2e6d9`

**Run Duration**: 1m 56s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 17 |
| Passing | **12** (70.6%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (88.2%) |
| Failing | 2 |
| Total expected lines | 371 |
| Matching lines | 333 (89.8%) |
| Mismatched lines | 38 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**12 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `clip_action_no_key_code` | 1 | 20.9s |  |
| 2 | `frame_label_count_oom` | 1 | 2.1s |  |
| 3 | `frame_script_cleanup` | 30 | 6.6s |  |
| 4 | `frame_script_cleanup2` | 32 | 6.5s |  |
| 5 | `frame_script_cleanup3` | 30 | 6.2s |  |
| 6 | `frame_script_cleanup_goto` | 30 | 6.4s |  |
| 7 | `frame_script_construct` | 25 | 6.3s |  |
| 8 | `scene_count_oom` | 1 | 2.0s |  |
| 9 | `swf_9_frame_script_button_order` | 15 | 6.7s |  |
| 10 | `swf_9_frame_script_cleanup_goto` | 30 | 6.5s |  |
| 11 | `swf_9_frame_script_cleanup_goto2` | 34 | 6.4s |  |
| 12 | `swf_9_frame_script_dynamic_goto_2` | 33 | 6.8s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `frame_script_button_order` | 2 | 4 | 6.2s |  |
| 2 | `swf_9_event_goto_frame_script` | 2 | 2 | 6.4s |  |
| 3 | `swf_9_frame_script_dynamic_goto` | 3 | 3 | 6.3s |  |

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

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `missing_frame_scripts` | 44.4% | 12/27 | 27 | 22 |  |
| 2 | `frame_script_cleanup_goto2` | 35.3% | 12/34 | 29 | 34 |  |
