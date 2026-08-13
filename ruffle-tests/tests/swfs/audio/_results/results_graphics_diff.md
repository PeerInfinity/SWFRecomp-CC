# Ruffle Test Results Diff

**Previous:** `16314e63feaa` (2026-08-13T21:54:57.554971+00:00)
**Current:** `3db858cbc157` (2026-08-13T22:38:36.708704+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 3 | +3 |
| Total | 5 | 5 | 0 |
| Pass rate | 0.0% | 60.0% | +60.0% |
| Mismatched lines | 0 | 19 | +19 |
|   Increased | | | +19 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `g711_event_alaw` | compile_fail | - | 0/0 |
| `g711_event_mulaw` | compile_fail | - | 0/0 |
| `stream_incomplete_loop` | compile_fail | - | 0/0 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `aac` | compile_fail | output_mismatch | - | 3/18 |
| `g711` | compile_fail | output_mismatch | - | 2/6 |
