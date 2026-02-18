# Ruffle Test Results Diff

**Previous:** `961ebf322759` (2026-02-17T01:20:28.670292+00:00)
**Current:** `57a202fae32d` (2026-02-18T02:39:41.160579+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 213 | 214 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 34.4% | 34.6% | +0.2% |
| Mismatched lines | 43029 | 43021 | -8 |
|   Decreased | | | -25 |
|   Increased | | | +17 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `divide_swf4` | output_mismatch | 95/107 | 107/107 |
| `swf4_function_calls` | output_mismatch | 6/7 | 7/7 |
| `try_catch_finally` | output_mismatch | 113/118 | 118/118 |
| `xml_child_nodes_edge_cases` | output_mismatch | 3/4 | 4/4 |
| `xml_to_string` | output_mismatch | 11/13 | 13/13 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `equals2_swf5` | output_mismatch | 926/926 | 921/926 |
| `equals2_swf6` | output_mismatch | 926/926 | 921/926 |
| `equals2_swf7` | output_mismatch | 926/926 | 921/926 |
| `global_is_bare` | output_mismatch | 7/7 | 6/7 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `external_interface_toxml_array` | output_mismatch | 3/25 | 5/25 | -2 |
| `bitmap_data` | output_mismatch | 68/1126 | 69/1126 | -1 |
| `boxed_primitives` | output_mismatch | 14/24 | 15/24 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `array_sort` | output_mismatch | 119/161 | 118/161 | +1 |
