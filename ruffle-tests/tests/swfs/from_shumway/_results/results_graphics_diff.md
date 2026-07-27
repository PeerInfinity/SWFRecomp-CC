# Ruffle Test Results Diff

**Previous:** `dfef7a9d6945` (2026-07-27T05:37:49.282074+00:00)
**Current:** `5a7162e20401` (2026-07-27T18:12:25.969780+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 163 | 165 | +2 |
| Total | 229 | 229 | 0 |
| Pass rate | 71.2% | 72.1% | +0.9% |
| Mismatched lines | 881 | 866 | -15 |
|   Decreased | | | -15 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3-interfaces` | output_mismatch | 1/6 | 6/6 |
| `as3-loader/bug1093712/loader` | output_mismatch | 0/1 | 1/1 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `as3-loader/LoaderTest` | output_mismatch | ruffle_matched | 5/9 | 7/9 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `as3-loader/LoaderTest2` | output_mismatch | 2/7 | 6/7 | -4 |
| `localconnection` | output_mismatch | 0/12 | 3/12 | -3 |
| `as3-loader/events/loader-events` | output_mismatch | 5/36 | 5/36 | 0 |
