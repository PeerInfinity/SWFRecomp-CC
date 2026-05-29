# Ruffle Test Results Diff

**Previous:** `55d725fb0c25` (2026-05-29T23:01:08.818401+00:00)
**Current:** `99221dcfc682` (2026-05-29T23:57:57.964646+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 616 | 614 | -2 |
| Total | 673 | 673 | 0 |
| Pass rate | 91.5% | 91.2% | -0.3% |
| Mismatched lines | 9725 | 9622 | -103 |
|   Decreased | | | -105 |
|   Increased | | | +2 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `movieclip_invalid_get_bounds_6` | output_mismatch | 10/10 | 9/10 |
| `movieclip_invalid_get_bounds_7` | output_mismatch | 10/10 | 9/10 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `native_objects_swf6` | segfault | output_mismatch | 9/115 | 114/115 |
