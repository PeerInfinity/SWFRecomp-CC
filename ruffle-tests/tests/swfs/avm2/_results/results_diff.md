# Ruffle Test Results Diff

**Previous:** `161ecf124012` (2026-11-21T23:52:47.738002+00:00)
**Current:** `10b5dff69c36` (2026-11-22T04:05:39.638491+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1273 | 1281 | +8 |
| Total | 1335 | 1336 | +1 |
| Pass rate | 95.4% | 95.9% | +0.5% |
| Mismatched lines | 2705 | 2426 | -279 |
|   Decreased | | | -279 |

## Newly Passing (7)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmapdata_encode` | output_mismatch | 26/147 | 147/147 |
| `netstream_play_flv` | output_mismatch | 0/16 | 16/16 |
| `netstream_play_stop_replay` | output_mismatch | 1/11 | 11/11 |
| `netstream_seek_flv` | output_mismatch | 0/49 | 49/49 |
| `textline_metrics` | output_mismatch | 0/20 | 20/20 |
| `weird_number_bound_methods` | output_mismatch | 9/12 | 12/12 |
| `worker_terminate` | output_mismatch | 1/56 | 56/56 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `primitive_bound_methods` | output_mismatch | ruffle_matched | 5/11 | 10/11 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `soundchannel_position_after_end` | pass | 6/6 |
