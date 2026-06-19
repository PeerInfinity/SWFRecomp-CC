# Ruffle Test Results Diff

**Previous:** `87465d1130f2` (2026-06-18T23:41:35.960871+00:00)
**Current:** `c00efd4d8f0b` (2026-06-19T00:55:52.211120+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 624 | 625 | +1 |
| Total | 701 | 701 | 0 |
| Pass rate | 89.0% | 89.2% | +0.2% |
| Mismatched lines | 16422 | 16306 | -116 |
|   Decreased | | | -116 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_shift` | output_mismatch | 149/216 | 216/216 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `array_reverse` | output_mismatch | 122/226 | 150/226 | -28 |
| `array_unshift` | output_mismatch | 95/146 | 116/146 | -21 |
| `watch_special_recursion_swf7` | segfault | 195/1042 | 195/1042 | 0 |
