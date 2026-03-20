# Ruffle Test Results Diff

**Previous:** `3b1506b047eb` (2026-03-20T04:14:59.632034+00:00)
**Current:** `97348d219df4` (2026-03-20T22:05:20.743756+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 48 | 51 | +3 |
| Total | 190 | 190 | 0 |
| Pass rate | 25.3% | 26.8% | +1.5% |
| Mismatched lines | 5724 | 5331 | -393 |
|   Decreased | | | -393 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `Selection-v5` | output_mismatch | 18/21 | 21/21 |
| `Stage-v5` | output_mismatch | 33/38 | 38/38 |
| `case-v5` | output_mismatch | 32/39 | 39/39 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `array-v5` | runtime_error | output_mismatch | 74/560 | 407/560 |

## Line Count Changed (26)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `ops-v8` | output_mismatch | 251/262 | 255/262 | -4 |
| `Error-v5` | output_mismatch | 21/28 | 24/28 | -3 |
| `Error-v6` | output_mismatch | 24/31 | 27/31 | -3 |
| `Error-v7` | output_mismatch | 24/31 | 27/31 | -3 |
| `Error-v8` | output_mismatch | 24/31 | 27/31 | -3 |
| `Global-v6` | output_mismatch | 146/210 | 149/210 | -3 |
| `Global-v7` | output_mismatch | 134/182 | 137/182 | -3 |
| `Global-v8` | output_mismatch | 128/169 | 131/169 | -3 |
| `Math-v7` | output_mismatch | 280/287 | 282/287 | -2 |
| `Math-v8` | output_mismatch | 280/287 | 282/287 | -2 |
| `Key-v5` | output_mismatch | 10/51 | 11/51 | -1 |
| `Key-v6` | output_mismatch | 15/55 | 16/55 | -1 |
| `Key-v7` | output_mismatch | 15/55 | 16/55 | -1 |
| `Key-v8` | output_mismatch | 15/55 | 16/55 | -1 |
| `Math-v5` | output_mismatch | 272/278 | 273/278 | -1 |
| `Math-v6` | output_mismatch | 272/278 | 273/278 | -1 |
| `Mouse-v8` | output_mismatch | 12/21 | 13/21 | -1 |
| `Selection-v6` | output_mismatch | 108/125 | 109/125 | -1 |
| `Selection-v7` | output_mismatch | 109/125 | 110/125 | -1 |
| `Selection-v8` | output_mismatch | 109/125 | 110/125 | -1 |
| `TextFormat-v5` | output_mismatch | 100/128 | 101/128 | -1 |
| `TextFormat-v6` | output_mismatch | 100/128 | 101/128 | -1 |
| `TextFormat-v7` | output_mismatch | 112/174 | 113/174 | -1 |
| `toString_valueOf-v6` | output_mismatch | 118/155 | 119/155 | -1 |
| `toString_valueOf-v7` | output_mismatch | 119/155 | 120/155 | -1 |
| `toString_valueOf-v8` | output_mismatch | 119/155 | 120/155 | -1 |
