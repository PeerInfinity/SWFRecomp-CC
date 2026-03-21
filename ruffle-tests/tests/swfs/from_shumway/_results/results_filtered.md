# Ruffle Test Results (Filtered)

**Date**: 2026-03-21 05:00 UTC

**Git SHA**: `76dbb8fbda`

**Run Duration**: 12m 23s

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
| 1 | `MaskTest` | 0 | 15.8s |  |
| 2 | `MaskTest-2` | 0 | 16.1s |  |
| 3 | `add` | 11 | 17.2s |  |
| 4 | `avm1timeline1` | 3 | 15.6s |  |
| 5 | `avm1timeline2` | 6 | 15.5s |  |
| 6 | `bitmapbuttons` | 0 | 15.9s |  |
| 7 | `button3` | 1 | 15.5s |  |
| 8 | `clipping` | 0 | 15.6s |  |
| 9 | `flash_geom_ColorTransform` | 0 | 15.7s |  |
| 10 | `flash_text_TextField` | 0 | 15.6s |  |
| 11 | `fscommand1` | 1 | 16.4s |  |
| 12 | `gradient` | 0 | 15.3s |  |
| 13 | `gradientTransform` | 0 | 15.3s |  |
| 14 | `invalidClipDepth` | 0 | 16.3s |  |
| 15 | `movieinfo1` | 3 | 15.9s |  |

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
