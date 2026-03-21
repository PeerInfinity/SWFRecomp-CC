# Ruffle Test Results (Filtered)

**Date**: 2026-03-21 17:15 UTC

**Git SHA**: `d124620802`

**Run Duration**: 12m 27s

**Filtered**: 30 tests ignored out of 47 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 17 |
| Passing | **15** (88.2%) |
| Failing | 2 |
| Total expected lines | 35 |
| Matching lines | 31 (88.6%) |
| Mismatched lines | 4 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**15 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `MaskTest` | 0 | 15.6s |  |
| 2 | `MaskTest-2` | 0 | 15.8s |  |
| 3 | `add` | 11 | 15.9s |  |
| 4 | `avm1timeline1` | 3 | 15.4s |  |
| 5 | `avm1timeline2` | 6 | 15.4s |  |
| 6 | `bitmapbuttons` | 0 | 17.3s |  |
| 7 | `button3` | 1 | 16.9s |  |
| 8 | `clipping` | 0 | 16.0s |  |
| 9 | `flash_geom_ColorTransform` | 0 | 15.3s |  |
| 10 | `flash_text_TextField` | 0 | 15.5s |  |
| 11 | `fscommand1` | 1 | 15.5s |  |
| 12 | `gradient` | 0 | 15.9s |  |
| 13 | `gradientTransform` | 0 | 15.6s |  |
| 14 | `invalidClipDepth` | 0 | 16.8s |  |
| 15 | `movieinfo1` | 3 | 15.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `targetPath1` | 75.0% | 6 | 8 | 2 |  |

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
| 1 | `targetPath1` | 75.0% | 6/8 | 8 | 8 |  |
| 2 | `doubleAndRegister` | 0.0% | 0/2 | 0 | 2 |  |
