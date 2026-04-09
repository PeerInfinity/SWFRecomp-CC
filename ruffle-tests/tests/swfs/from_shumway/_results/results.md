# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-09 00:00 UTC

**Git SHA**: `2a4adfc3fd`

**Run Duration**: 14m 57s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **17** (36.2%) |
| Failing | 30 |
| Total expected lines | 256 |
| Matching lines | 35 (13.7%) |
| Mismatched lines | 221 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 30 | 100.0% |

## Passing Tests

**17 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `MaskTest` | 0 | 19.1s |  |
| 2 | `MaskTest-2` | 0 | 19.1s |  |
| 3 | `add` | 11 | 17.0s |  |
| 4 | `avm1timeline1` | 3 | 18.6s |  |
| 5 | `avm1timeline2` | 6 | 18.6s |  |
| 6 | `bitmapbuttons` | 0 | 19.5s |  |
| 7 | `button3` | 1 | 21.3s |  |
| 8 | `clipping` | 0 | 19.2s |  |
| 9 | `doubleAndRegister` | 2 | 19.1s |  |
| 10 | `flash_geom_ColorTransform` | 0 | 19.7s |  |
| 11 | `flash_text_TextField` | 0 | 19.5s |  |
| 12 | `fscommand1` | 1 | 18.6s |  |
| 13 | `gradient` | 0 | 19.0s |  |
| 14 | `gradientTransform` | 0 | 19.0s |  |
| 15 | `invalidClipDepth` | 0 | 20.7s |  |
| 16 | `movieinfo1` | 3 | 18.3s |  |
| 17 | `targetPath1` | 8 | 18.7s |  |

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

**30 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `3_joystick` | 0.0% | 0/4 | 0 | 4 |  |
| 2 | `MaskTest-3` | 0.0% | 0/4 | 0 | 4 |  |
| 3 | `ZeroClipboardTest` | 0.0% | 0/3 | 0 | 3 |  |
| 4 | `as3-interfaces` | 0.0% | 0/6 | 0 | 6 |  |
| 5 | `avm1movie` | 0.0% | 0/13 | 0 | 13 |  |
| 6 | `button1` | 0.0% | 0/1 | 0 | 1 |  |
| 7 | `button2` | 0.0% | 0/2 | 2 | 1 |  |
| 8 | `captions` | 0.0% | 0/8 | 0 | 8 |  |
| 9 | `encoding1` | 0.0% | 0/31 | 0 | 31 |  |
| 10 | `esc` | 0.0% | 0/2 | 0 | 2 |  |
| 11 | `flash_events_Event` | 0.0% | 0/3 | 0 | 3 |  |
| 12 | `flash_net_SharedObject` | 0.0% | 0/4 | 0 | 4 |  |
| 13 | `flash_net_URLLoader` | 0.0% | 0/7 | 0 | 7 |  |
| 14 | `flash_net_URLRequest` | 0.0% | 0/6 | 0 | 6 |  |
| 15 | `flash_net_classes` | 0.0% | 0/22 | 0 | 22 |  |
| 16 | `flash_text_TextField2` | 0.0% | 0/18 | 0 | 18 |  |
| 17 | `flash_utils_Timer` | 0.0% | 0/2 | 0 | 2 |  |
| 18 | `getobjectsunderpoint` | 0.0% | 0/34 | 0 | 34 |  |
| 19 | `hardwrap` | 0.0% | 0/1 | 0 | 1 |  |
| 20 | `hitTestStyleChange` | 0.0% | 0/1 | 0 | 1 |  |
| 21 | `image-loading` | 0.0% | 0/4 | 0 | 4 |  |
| 22 | `local2global` | 0.0% | 0/1 | 0 | 1 |  |
| 23 | `localconnection` | 0.0% | 0/12 | 0 | 12 |  |
| 24 | `lzma` | 0.0% | 0/5 | 0 | 5 |  |
| 25 | `lzma_bytes` | 0.0% | 0/2 | 0 | 2 |  |
| 26 | `movieclip` | 0.0% | 0/9 | 0 | 9 |  |
| 27 | `slider_component` | 0.0% | 0/4 | 0 | 4 |  |
| 28 | `stream1` | 0.0% | 0/9 | 0 | 9 |  |
| 29 | `stroke1` | 0.0% | 0/1 | 0 | 1 |  |
| 30 | `stylesheet` | 0.0% | 0/3 | 0 | 3 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_AVM1_PLAN.md) | 0 | 0 | 0 |
| | *(tests not in any document)* | 47 | 17 | 30 |
