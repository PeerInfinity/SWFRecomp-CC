# Ruffle Test Results Diff

**Previous:** `876e6670414e` (2026-11-23T02:55:02.163562+00:00)
**Current:** `1396f1e10b65` (2026-11-23T19:23:24.412120+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 69 | 70 | +1 |
| Total | 111 | 111 | 0 |
| Pass rate | 62.2% | 63.1% | +0.9% |
| Mismatched lines | 985 | 953 | -32 |
|   Decreased | | | -33 |
|   Increased | | | +1 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `BitmapDataDraw` | ruffle_matched | 31/56 | 56/56 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `callFunction_test` | ruffle_matched | segfault | 5/11 | - |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `action_order/ActionOrderTest3` | output_mismatch | 4/62 | 5/62 | -1 |
| `action_order/ActionOrderTest4` | output_mismatch | 10/64 | 11/64 | -1 |
| `action_order/ActionOrderTest5` | output_mismatch | 6/51 | 5/51 | +1 |
