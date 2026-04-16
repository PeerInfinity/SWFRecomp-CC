# Ruffle Test Results Diff

**Previous:** `49c51d169ed1` (2026-04-15T19:28:28.927530+00:00)
**Current:** `6004ee88e451` (2026-04-16T01:25:14.619810+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 102 | 106 | +4 |
| Total | 190 | 190 | 0 |
| Pass rate | 53.7% | 55.8% | +2.1% |
| Mismatched lines | 3648 | 3407 | -241 |
|   Decreased | | | -243 |
|   Increased | | | +2 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `TextFormat-v5` | output_mismatch | 118/128 | 128/128 |
| `TextFormat-v6` | output_mismatch | 118/128 | 128/128 |
| `Transform-v6` | output_mismatch | 4/7 | 7/7 |
| `Transform-v7` | output_mismatch | 4/7 | 7/7 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `Matrix-v7` | output_mismatch | ruffle_matched | 35/168 | 140/168 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `Matrix-v6` | output_mismatch | 39/168 | 137/168 | -98 |
| `TextFormat-v7` | output_mismatch | 126/174 | 132/174 | -6 |
| `ExternalInterface-v6` | output_mismatch | 28/55 | 32/55 | -4 |
| `ExternalInterface-v7` | output_mismatch | 28/55 | 32/55 | -4 |
| `array-v5` | output_mismatch | 461/560 | 459/560 | +2 |
