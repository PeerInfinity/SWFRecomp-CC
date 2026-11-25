# Ruffle Test Results Diff

**Previous:** `78fee9e13f85` (2026-11-24T17:26:56.580312+00:00)
**Current:** `8f4f6e395305` (2026-11-25T03:46:34.697747+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 751 | 754 | +3 |
| Total | 788 | 788 | 0 |
| Pass rate | 95.3% | 95.7% | +0.4% |
| Mismatched lines | 12457 | 12439 | -18 |
|   Decreased | | | -18 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `malformed_actions/constant_pool_overlong` | output_mismatch | 1/2 | 2/2 |
| `malformed_actions/constant_pool_overspill` | output_mismatch | 1/11 | 11/11 |
| `malformed_actions/push_overspill` | output_mismatch | 2/4 | 4/4 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `globals_monkeypatch` | segfault | output_mismatch | 44/306 | 49/306 |
