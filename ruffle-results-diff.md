# Ruffle Test Results Diff

**Previous:** `89513b9d2880` (2026-02-12T18:43:05.339640+00:00)
**Current:** `2d0fc53dda29` (2026-02-12T19:17:43.741117+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 85 | 86 | +1 |
| Total | 616 | 616 | 0 |
| Pass rate | 13.8% | 14.0% | +0.2% |
| Mismatched lines | 57241 | 57217 | -24 |
|   Decreased | | | -24 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as1_constructor_v6` | output_mismatch | 30/35 | 35/35 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `array_constructor` | segfault | output_mismatch | 12/30 | 28/30 |
| `array_length` | runtime_error | segfault | 13/42 | 13/42 |
| `netstream_play_flv_screen` | compile_fail | segfault | - | - |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `array_properties` | output_mismatch | 30/36 | 33/36 | -3 |
