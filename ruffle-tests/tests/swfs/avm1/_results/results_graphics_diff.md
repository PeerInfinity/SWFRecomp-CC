# Ruffle Test Results Diff

**Previous:** `6b73e232d72c` (2026-06-16T04:10:07.230724+00:00)
**Current:** `9c922628c884` (2026-06-16T16:35:10.678156+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 620 | 623 | +3 |
| Total | 690 | 700 | +10 |
| Pass rate | 89.9% | 89.0% | -0.9% |
| Mismatched lines | 12546 | 16449 | +3903 |

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
