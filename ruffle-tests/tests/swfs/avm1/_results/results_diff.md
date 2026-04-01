# Ruffle Test Results Diff

**Previous:** `7a13fd77e2a9` (2026-04-01T05:43:30.942392+00:00)
**Current:** `8d0f9c63c087` (2026-04-01T20:15:46.236423+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 569 | 560 | -9 |
| Total | 620 | 620 | 0 |
| Pass rate | 91.8% | 90.3% | -1.5% |
| Mismatched lines | 10736 | 11311 | +575 |
|   Increased | | | +575 |

## Newly Failing (9)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `array_sort` | output_mismatch | 161/161 | 155/161 |
| `error` | output_mismatch | 58/58 | 43/58 |
| `focusrect_property_swf5` | output_mismatch | 1237/1237 | 992/1237 |
| `focusrect_property_swf6` | output_mismatch | 1237/1237 | 1043/1237 |
| `get_variable_in_scope` | output_mismatch | 29/29 | 26/29 |
| `object_string_coerce_swf5` | output_mismatch | 62/62 | 39/62 |
| `register_class_swf6` | output_mismatch | 37/37 | 35/37 |
| `removed_target_clip_scope` | output_mismatch | 35/35 | 33/35 |
| `set_variable_scope` | output_mismatch | 58/58 | 53/58 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls` | output_mismatch | 276/4497 | 276/4497 | 0 |
| `native_objects_swf6` | output_mismatch | 83/84 | 81/84 | +2 |
| `bitmap_filters` | output_mismatch | 544/548 | 466/548 | +78 |
