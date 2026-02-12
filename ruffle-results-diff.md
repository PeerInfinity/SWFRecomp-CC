# Ruffle Test Results Diff

**Previous:** `2d0fc53dda29` (2026-02-12T19:17:43.741117+00:00)
**Current:** `10cb155c9d8f` (2026-02-12T19:58:38.976815+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 86 | 87 | +1 |
| Total | 616 | 616 | 0 |
| Pass rate | 14.0% | 14.1% | +0.1% |
| Mismatched lines | 57217 | 57187 | -30 |
|   Decreased | | | -31 |
|   Increased | | | +1 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_properties` | output_mismatch | 33/36 | 36/36 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `array_length` | segfault | output_mismatch | 13/42 | 35/42 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `arguments` | output_mismatch | 78/127 | 80/127 | -2 |
| `array_constructor` | output_mismatch | 28/30 | 29/30 | -1 |
| `as_broadcaster_undef` | output_mismatch | 34/89 | 35/89 | -1 |
| `define_function2` | output_mismatch | 6/8 | 7/8 | -1 |
| `localconnection_properties` | output_mismatch | 3/8 | 4/8 | -1 |
| `array_enumerate` | output_mismatch | 1/4 | 0/4 | +1 |
