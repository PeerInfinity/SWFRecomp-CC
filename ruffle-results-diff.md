# Ruffle Test Results Diff

**Previous:** `e6286c92264c` (2026-02-27T20:31:29.089501+00:00)
**Current:** `fe29e8144528` (2026-02-27T21:24:14.008890+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 390 | 395 | +5 |
| Total | 619 | 619 | 0 |
| Pass rate | 63.0% | 63.8% | +0.8% |
| Mismatched lines | 31595 | 31555 | -40 |
|   Decreased | | | -42 |
|   Increased | | | +2 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `path_string` | output_mismatch | 308/322 | 322/322 |
| `string_paths_hidden` | output_mismatch | 45/54 | 54/54 |
| `tab_ordering_children` | output_mismatch | 204/208 | 208/208 |
| `tab_ordering_custom_duplicate_index` | output_mismatch | 11/22 | 22/22 |
| `tell_target` | output_mismatch | 34/37 | 37/37 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `resolve_different_root` | segfault | output_mismatch | - | 0/2 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `tab_ordering_automatic_order_same_position` | output_mismatch | 8/12 | 9/12 | -1 |
