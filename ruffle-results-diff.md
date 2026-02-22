# Ruffle Test Results Diff

**Previous:** `acb5aaf09d73` (2026-02-22T20:31:47.321776+00:00)
**Current:** `ebdc0601bed5` (2026-02-22T21:02:54.246670+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 283 | 284 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 45.7% | 45.9% | +0.2% |
| Mismatched lines | 36599 | 36585 | -14 |
|   Decreased | | | -14 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `local_to_global` | output_mismatch | 47/49 | 49/49 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `slash_syntax` | output_mismatch | 0/14 | 9/14 | -9 |
| `tell_target` | output_mismatch | 0/37 | 3/37 | -3 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
