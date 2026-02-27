# Ruffle Test Results Diff

**Previous:** `b84cddf6ffd6` (2026-02-27T18:40:15.805628+00:00)
**Current:** `a5cee677e26a` (2026-02-27T19:49:47.492699+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 392 | 389 | -3 |
| Total | 619 | 619 | 0 |
| Pass rate | 63.3% | 62.8% | -0.5% |
| Mismatched lines | 31562 | 31529 | -33 |
|   Decreased | | | -75 |
|   Increased | | | +42 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `clip_constructors` | output_mismatch | 6/8 | 8/8 |
| `issue_768` | output_mismatch | 2/3 | 3/3 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `path_string` | output_mismatch | 322/322 | 308/322 |
| `string_paths_hidden` | output_mismatch | 54/54 | 45/54 |
| `tab_ordering_children` | output_mismatch | 208/208 | 204/208 |
| `tab_ordering_custom_duplicate_index` | output_mismatch | 22/22 | 11/22 |
| `tell_target` | output_mismatch | 37/37 | 34/37 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 266/338 | - |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `tab_ordering_automatic_order_same_position` | output_mismatch | 9/12 | 8/12 | +1 |
