# Ruffle Test Results Diff

**Previous:** `d6808409a87a` (2026-04-27T00:35:33.062513+00:00)
**Current:** `df6df0c0057d` (2026-04-27T01:54:26.501728+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 595 | 588 | -7 |
| Total | 641 | 641 | 0 |
| Pass rate | 92.8% | 91.7% | -1.1% |
| Mismatched lines | 8898 | 8964 | +66 |
|   Increased | | | +66 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `issue_9885` | timeout | - | 2/2 |

## Newly Failing (8)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `execution_order2` | output_mismatch | 7/7 | 3/7 |
| `execution_order3` | output_mismatch | 4/4 | 2/4 |
| `goto_advance2` | output_mismatch | 2/2 | 1/2 |
| `goto_both_ways1` | output_mismatch | 3/3 | 1/3 |
| `goto_execution_order2` | output_mismatch | 2/2 | 0/2 |
| `goto_rewind2` | output_mismatch | 3/3 | 2/3 |
| `goto_rewind3` | output_mismatch | 2/2 | 1/2 |
| `register_and_init_order` | output_mismatch | 231/231 | 178/231 |
