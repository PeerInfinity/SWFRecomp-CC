# Ruffle Test Results Diff

**Previous:** `b030ed745d4f` (2026-11-26T00:30:59.151015+00:00)
**Current:** `4a25debc987e` (2026-11-26T04:57:43.324357+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1305 | 1306 | +1 |
| Total | 1348 | 1351 | +3 |
| Pass rate | 96.8% | 96.7% | -0.1% |
| Mismatched lines | 1669 | 1664 | -5 |
|   Decreased | | | -8 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `mouse_pick_avm1_root` | output_mismatch | 1/2 | 2/2 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `timer_checks_per_frame` | timeout | - |
| `timer_tie_order` | timeout | - |
| `timer_timeout_ids` | output_mismatch | 8/11 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `avm1_root` | output_mismatch | 5/58 | 12/58 | -7 |
