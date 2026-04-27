# Ruffle Test Results Diff

**Previous:** `df6df0c0057d` (2026-04-27T01:54:26.501728+00:00)
**Current:** `8fb3a99ec4dd` (2026-04-27T02:49:17.007852+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 588 | 593 | +5 |
| Total | 641 | 641 | 0 |
| Pass rate | 91.7% | 92.5% | +0.8% |
| Mismatched lines | 8964 | 8939 | -25 |
|   Decreased | | | -66 |
|   Increased | | | +41 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `execution_order2` | output_mismatch | 3/7 | 7/7 |
| `execution_order3` | output_mismatch | 2/4 | 4/4 |
| `goto_advance2` | output_mismatch | 1/2 | 2/2 |
| `goto_both_ways1` | output_mismatch | 1/3 | 3/3 |
| `goto_execution_order2` | output_mismatch | 0/2 | 2/2 |
| `goto_rewind2` | output_mismatch | 2/3 | 3/3 |
| `goto_rewind3` | output_mismatch | 1/2 | 2/2 |
| `register_and_init_order` | output_mismatch | 178/231 | 231/231 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `attach_movie` | output_mismatch | 59/59 | 55/59 |
| `default_names` | output_mismatch | 52/52 | 42/52 |
| `removed_target_clip_scope` | output_mismatch | 35/35 | 8/35 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `removed_base_clip_tell_target` | output_mismatch | 0/2 | 0/2 | 0 |
