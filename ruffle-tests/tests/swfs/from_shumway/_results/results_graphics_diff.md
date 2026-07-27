# Ruffle Test Results Diff

**Previous:** `9f4be9647bf4` (2026-07-26T22:42:49.173796+00:00)
**Current:** `8213dd4d61dd` (2026-07-27T00:30:06.235646+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 161 | 162 | +1 |
| Total | 229 | 229 | 0 |
| Pass rate | 70.3% | 70.7% | +0.4% |
| Mismatched lines | 937 | 888 | -49 |
|   Decreased | | | -49 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `image-loading` | output_mismatch | 0/4 | 4/4 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `avm1movie` | output_mismatch | ruffle_matched | 0/13 | 4/13 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `as3-loader/loaderinfo/loaded-content-properties` | output_mismatch | 3/48 | 35/48 | -32 |
| `as3-loader/LoaderTest` | output_mismatch | 1/9 | 5/9 | -4 |
| `as3-loader/LoaderLoadBytesTest2` | output_mismatch | 0/3 | 2/3 | -2 |
| `as3-loader/LoaderLoadBytesTest` | output_mismatch | 0/4 | 1/4 | -1 |
| `as3-loader/LoaderTest2` | output_mismatch | 1/7 | 2/7 | -1 |
| `as3-loader/events/loader-events` | output_mismatch | 4/36 | 5/36 | -1 |
| `as3-interfaces` | output_mismatch | 1/6 | 1/6 | 0 |
| `localconnection` | output_mismatch | 0/12 | 0/12 | 0 |
