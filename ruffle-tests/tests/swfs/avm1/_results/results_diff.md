# Ruffle Test Results Diff

**Previous:** `efddd2eaf784` (2026-06-15T19:58:51.027953+00:00)
**Current:** `22c8e672408c` (2026-06-16T18:19:46.629849+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 620 | 623 | +3 |
| Total | 690 | 700 | +10 |
| Pass rate | 89.9% | 89.0% | -0.9% |
| Mismatched lines | 12510 | 16413 | +3903 |

## Added Tests (10)

| Test | Status | Lines |
|------|--------|-------|
| `virtual_property_special_recursion_double_swf6` | output_mismatch | 3/11 |
| `virtual_property_special_recursion_double_swf7` | ruffle_matched | 129/523 |
| `virtual_property_special_recursion_swf6` | output_mismatch | 1/6 |
| `virtual_property_special_recursion_swf7` | pass | 262/262 |
| `watch_infinite_recursion` | pass | 1/1 |
| `watch_proto_recursion` | pass | 1/1 |
| `watch_special_recursion_double_swf6` | segfault | 9/46 |
| `watch_special_recursion_double_swf7` | segfault | 521/3118 |
| `watch_special_recursion_swf6` | segfault | 3/18 |
| `watch_special_recursion_swf7` | segfault | 195/1042 |
