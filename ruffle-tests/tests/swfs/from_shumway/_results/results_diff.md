# Ruffle Test Results Diff

**Previous:** `8df2d730c3f0` (2026-07-26T20:13:07.998361+00:00)
**Current:** `767a301d2bae` (2026-07-29T01:40:49.658708+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 160 | 168 | +8 |
| Total | 229 | 229 | 0 |
| Pass rate | 69.9% | 73.4% | +3.5% |
| Mismatched lines | 941 | 863 | -78 |
|   Decreased | | | -78 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3-interfaces` | output_mismatch | 1/6 | 6/6 |
| `as3-loader/LoaderLoadBytesTest2` | output_mismatch | 0/3 | 3/3 |
| `as3-loader/bug1093712/loader` | output_mismatch | 0/1 | 1/1 |
| `flash_net_URLRequest` | output_mismatch | 0/6 | 6/6 |
| `flash_net_classes` | ruffle_matched | 18/22 | 22/22 |
| `hittesting/mask-hit-test` | ruffle_matched | 0/1 | 1/1 |
| `image-loading` | output_mismatch | 0/4 | 4/4 |
| `mouse/start_drag_lock` | output_mismatch | 2/3 | 3/3 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `as3-loader/LoaderTest` | output_mismatch | ruffle_matched | 1/9 | 7/9 |
| `avm1movie` | output_mismatch | ruffle_matched | 0/13 | 4/13 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `as3-loader/loaderinfo/loaded-content-properties` | output_mismatch | 3/48 | 36/48 | -33 |
| `as3-loader/LoaderTest2` | output_mismatch | 1/7 | 6/7 | -5 |
| `localconnection` | output_mismatch | 0/12 | 3/12 | -3 |
| `as3-loader/LoaderLoadBytesTest` | output_mismatch | 0/4 | 1/4 | -1 |
| `as3-loader/events/loader-events` | output_mismatch | 4/36 | 5/36 | -1 |
| `flash_net_URLLoader` | output_mismatch | 0/7 | 0/7 | 0 |
