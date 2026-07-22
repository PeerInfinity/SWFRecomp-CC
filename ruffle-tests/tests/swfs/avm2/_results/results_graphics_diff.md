# Ruffle Test Results Diff

**Previous:** `69369f32dece` (2026-07-22T02:06:25.854794+00:00)
**Current:** `6f1508984cfb` (2026-07-22T03:06:56.317788+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 823 | 826 | +3 |
| Total | 1215 | 1215 | 0 |
| Pass rate | 67.7% | 68.0% | +0.3% |
| Mismatched lines | 47961 | 47709 | -252 |
|   Decreased | | | -252 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `graphics_bad_direct_commands` | output_mismatch | 0/5 | 5/5 |
| `graphics_draw_triangles` | output_mismatch | 0/98 | 98/98 |
| `graphics_path` | output_mismatch | 0/56 | 56/56 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `graphics_draw_path` | output_mismatch | ruffle_matched | 0/101 | 51/101 |

## Line Count Changed (14)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `error_stack_trace` | output_mismatch | 24/45 | 38/45 | -14 |
| `number_convert_errors` | output_mismatch | 27/871 | 40/871 | -13 |
| `stage_properties2` | output_mismatch | 18/213 | 23/213 | -5 |
| `error_throwerror` | output_mismatch | 3/103 | 6/103 | -3 |
| `pixelbender_ceil` | output_mismatch | 3/77 | 5/77 | -2 |
| `pixelbender_sign` | output_mismatch | 3/60 | 5/60 | -2 |
| `all_classes/display/swf9` | output_mismatch | 1/1959 | 2/1959 | -1 |
| `element_format_constructor_order` | output_mismatch | 3/64 | 4/64 | -1 |
| `xml_list_ctor_errors` | output_mismatch | 4/34 | 5/34 | -1 |
| `all_classes/display/swf10` | output_mismatch | 1/2569 | 1/2569 | 0 |
| `all_classes/display/swf11` | output_mismatch | 1/2593 | 1/2593 | 0 |
| `all_classes/display/swf12` | output_mismatch | 1/2593 | 1/2593 | 0 |
| `all_classes/display/swf13` | output_mismatch | 1/2671 | 1/2671 | 0 |
| `all_classes/display/swf30` | output_mismatch | 0/2936 | 0/2936 | 0 |
