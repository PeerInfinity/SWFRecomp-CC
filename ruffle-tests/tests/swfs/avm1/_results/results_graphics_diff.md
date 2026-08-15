# Ruffle Test Results Diff

**Previous:** `3db858cbc157` (2026-08-13T22:38:36.623140+00:00)
**Current:** `86434112a759` (2026-08-15T09:18:14.383997+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 678 | 681 | +3 |
| Total | 718 | 725 | +7 |
| Pass rate | 94.4% | 93.9% | -0.5% |
| Mismatched lines | 11710 | 11731 | +21 |

## Added Tests (7)

| Test | Status | Lines |
|------|--------|-------|
| `sound_load_multiple_instances` | pass | 19/19 |
| `sound_load_multiple_remote` | output_mismatch | 2/6 |
| `sound_load_props` | output_mismatch | 96/111 |
| `sound_load_start_remote` | output_mismatch | 0/1 |
| `sound_load_stops_when_dereferenced` | pass | 0/0 |
| `sound_load_streaming_stop_remote` | output_mismatch | 2/3 |
| `sound_mixed_attach_load` | pass | 13/13 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `sound_load_start` | pass | 3/3 | 6/6 | 0 |
