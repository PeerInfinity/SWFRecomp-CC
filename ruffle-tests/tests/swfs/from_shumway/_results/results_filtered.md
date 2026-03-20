# Ruffle Test Results (Filtered)

**Date**: 2026-03-20 04:14 UTC

**Git SHA**: `3b1506b047`

**Run Duration**: 12m 27s

**Filtered**: 0 tests ignored out of 47 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **15** (31.9%) |
| Failing | 32 |
| Total expected lines | 256 |
| Matching lines | 31 (12.1%) |
| Mismatched lines | 225 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 32 | 100.0% |

## Passing Tests

**15 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `MaskTest` | 0 | 15.6s |  |
| 2 | `MaskTest-2` | 0 | 15.4s |  |
| 3 | `add` | 11 | 15.9s |  |
| 4 | `avm1timeline1` | 3 | 15.6s |  |
| 5 | `avm1timeline2` | 6 | 15.5s |  |
| 6 | `bitmapbuttons` | 0 | 15.9s |  |
| 7 | `button3` | 1 | 15.9s |  |
| 8 | `clipping` | 0 | 15.3s |  |
| 9 | `flash_geom_ColorTransform` | 0 | 15.5s |  |
| 10 | `flash_text_TextField` | 0 | 16.7s |  |
| 11 | `fscommand1` | 1 | 15.3s |  |
| 12 | `gradient` | 0 | 17.4s |  |
| 13 | `gradientTransform` | 0 | 17.2s |  |
| 14 | `invalidClipDepth` | 0 | 16.1s |  |
| 15 | `movieinfo1` | 3 | 15.8s |  |

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

**32 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `targetPath1` | 75.0% | 6/8 | 8 | 8 |  |
| 2 | `3_joystick` | 0.0% | 0/4 | 0 | 4 |  |
| 3 | `MaskTest-3` | 0.0% | 0/4 | 0 | 4 |  |
| 4 | `ZeroClipboardTest` | 0.0% | 0/3 | 0 | 3 |  |
| 5 | `as3-interfaces` | 0.0% | 0/6 | 0 | 6 |  |
| 6 | `avm1movie` | 0.0% | 0/13 | 0 | 13 |  |
| 7 | `button1` | 0.0% | 0/1 | 0 | 1 |  |
| 8 | `button2` | 0.0% | 0/2 | 2 | 1 |  |
| 9 | `captions` | 0.0% | 0/8 | 0 | 8 |  |
| 10 | `doubleAndRegister` | 0.0% | 0/2 | 0 | 2 |  |
| 11 | `encoding1` | 0.0% | 0/31 | 0 | 31 |  |
| 12 | `esc` | 0.0% | 0/2 | 0 | 2 |  |
| 13 | `flash_events_Event` | 0.0% | 0/3 | 0 | 3 |  |
| 14 | `flash_net_SharedObject` | 0.0% | 0/4 | 0 | 4 |  |
| 15 | `flash_net_URLLoader` | 0.0% | 0/7 | 0 | 7 |  |
| 16 | `flash_net_URLRequest` | 0.0% | 0/6 | 0 | 6 |  |
| 17 | `flash_net_classes` | 0.0% | 0/22 | 0 | 22 |  |
| 18 | `flash_text_TextField2` | 0.0% | 0/18 | 0 | 18 |  |
| 19 | `flash_utils_Timer` | 0.0% | 0/2 | 0 | 2 |  |
| 20 | `getobjectsunderpoint` | 0.0% | 0/34 | 0 | 34 |  |
| 21 | `hardwrap` | 0.0% | 0/1 | 0 | 1 |  |
| 22 | `hitTestStyleChange` | 0.0% | 0/1 | 0 | 1 |  |
| 23 | `image-loading` | 0.0% | 0/4 | 0 | 4 |  |
| 24 | `local2global` | 0.0% | 0/1 | 0 | 1 |  |
| 25 | `localconnection` | 0.0% | 0/12 | 0 | 12 |  |
| 26 | `lzma` | 0.0% | 0/5 | 0 | 5 |  |
| 27 | `lzma_bytes` | 0.0% | 0/2 | 0 | 2 |  |
| 28 | `movieclip` | 0.0% | 0/9 | 0 | 9 |  |
| 29 | `slider_component` | 0.0% | 0/4 | 0 | 4 |  |
| 30 | `stream1` | 0.0% | 0/9 | 0 | 9 |  |
| 31 | `stroke1` | 0.0% | 0/1 | 0 | 1 |  |
| 32 | `stylesheet` | 0.0% | 0/3 | 0 | 3 |  |
