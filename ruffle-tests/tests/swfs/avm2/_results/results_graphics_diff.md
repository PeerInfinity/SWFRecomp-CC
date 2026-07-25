# Ruffle Test Results Diff

**Previous:** `b46ac6ee92f2` (2026-07-25T04:33:02.503928+00:00)
**Current:** `e4d1e78f665e` (2026-07-25T19:28:36.541020+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 840 | 829 | -11 |
| Total | 1217 | 1218 | +1 |
| Pass rate | 69.0% | 68.1% | -0.9% |
| Mismatched lines | 47261 | 47957 | +696 |
|   Decreased | | | -15 |
|   Increased | | | +661 |

## Newly Failing (11)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `array_holes` | output_mismatch | 9/9 | 8/9 |
| `array_pop` | output_mismatch | 52/52 | 50/52 |
| `array_push` | output_mismatch | 24/24 | 21/24 |
| `array_reverse` | output_mismatch | 28/28 | 25/28 |
| `array_shift` | output_mismatch | 51/51 | 49/51 |
| `array_slice` | output_mismatch | 39/39 | 28/39 |
| `array_sort` | output_mismatch | 297/297 | 220/297 |
| `array_sorton` | output_mismatch | 545/545 | 28/545 |
| `array_splice` | output_mismatch | 133/133 | 92/133 |
| `array_unshift` | output_mismatch | 24/24 | 21/24 |
| `function_call_via_apply` | output_mismatch | 11/11 | 10/11 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `proxy_not_overridden` | output_mismatch | 4/54 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `primitive_valueOf` | output_mismatch | 14/285 | 25/285 | -11 |
| `primitive_toString` | output_mismatch | 16/277 | 20/277 | -4 |
