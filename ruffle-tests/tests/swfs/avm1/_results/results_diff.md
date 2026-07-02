# Ruffle Test Results Diff

**Previous:** `56970ac27a29` (2026-06-30T04:01:16.480357+00:00)
**Current:** `8d1e3adef576` (2026-07-02T19:28:39.915153+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 629 | 627 | -2 |
| Total | 704 | 705 | +1 |
| Pass rate | 89.3% | 88.9% | -0.4% |
| Mismatched lines | 15446 | 15457 | +11 |
|   Increased | | | +8 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `global_swf6_7_8` | output_mismatch | 15/15 | 9/15 |
| `string_paths_other` | output_mismatch | 36/36 | 34/36 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `string_paths_reference_launder` | output_mismatch | ruffle_matched | 1/2 | 1/2 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `localconnection_top_level` | output_mismatch | 4/7 |
