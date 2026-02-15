# Ruffle Test Results Diff

**Previous:** `c616aeb4c13b` (2026-02-15T02:29:13.233456+00:00)
**Current:** `3fb6a61297cd` (2026-02-15T03:10:50.478275+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 197 | 198 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 31.8% | 32.0% | +0.2% |
| Mismatched lines | 46950 | 46652 | -298 |
|   Decreased | | | -298 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `string_methods_negative_args` | output_mismatch | 127/240 | 240/240 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `string_methods_swfv5` | output_mismatch | 181/275 | 274/275 | -93 |
| `string_methods` | output_mismatch | 188/285 | 280/285 | -92 |
| `device_font_spacing` | segfault | 1/91 | 1/91 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
