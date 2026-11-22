# Ruffle Test Results Diff

**Previous:** `6b2054090f33` (2026-11-22T03:10:05.606441+00:00)
**Current:** `3f803679d02f` (2026-11-22T04:48:29.102441+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1273 | 1282 | +9 |
| Total | 1336 | 1336 | 0 |
| Pass rate | 95.3% | 96.0% | +0.7% |
| Mismatched lines | 2709 | 2308 | -401 |
|   Decreased | | | -401 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `audio_computespectrum` | output_mismatch | 0/118 | 118/118 |
| `bitmapdata_encode` | output_mismatch | 26/147 | 147/147 |
| `netstream_play_flv` | output_mismatch | 0/16 | 16/16 |
| `netstream_play_stop_replay` | output_mismatch | 1/11 | 11/11 |
| `netstream_seek_flv` | output_mismatch | 0/49 | 49/49 |
| `soundchannel_position_after_end` | output_mismatch | 2/6 | 6/6 |
| `textline_metrics` | output_mismatch | 0/20 | 20/20 |
| `weird_number_bound_methods` | output_mismatch | 9/12 | 12/12 |
| `worker_terminate` | output_mismatch | 1/56 | 56/56 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `primitive_bound_methods` | output_mismatch | ruffle_matched | 5/11 | 10/11 |
