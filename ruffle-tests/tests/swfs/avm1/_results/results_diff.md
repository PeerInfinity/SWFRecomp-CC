# Ruffle Test Results Diff

**Previous:** `cceb5133a189` (2026-11-24T07:00:45.612486+00:00)
**Current:** `78fee9e13f85` (2026-11-24T16:56:52.963016+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 751 | 751 | 0 |
| Total | 785 | 788 | +3 |
| Pass rate | 95.7% | 95.3% | -0.4% |
| Mismatched lines | 12439 | 12457 | +18 |
|   Increased | | | +5 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `globals_monkeypatch` | output_mismatch | segfault | 49/306 | 44/306 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `malformed_actions/constant_pool_overlong` | output_mismatch | 1/2 |
| `malformed_actions/constant_pool_overspill` | output_mismatch | 1/11 |
| `malformed_actions/push_overspill` | output_mismatch | 2/4 |
