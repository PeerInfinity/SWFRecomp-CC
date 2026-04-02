# Ruffle Test Results Diff

**Previous:** `8d0f9c63c087` (2026-04-01T20:15:46.236423+00:00)
**Current:** `33b4d52d1573` (2026-04-02T01:29:20.503968+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 560 | 561 | +1 |
| Total | 620 | 620 | 0 |
| Pass rate | 90.3% | 90.5% | +0.2% |
| Mismatched lines | 11311 | 13081 | +1770 |
|   Decreased | | | -1174 |
|   Increased | | | +2944 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_sort` | output_mismatch | 155/161 | 161/161 |
| `error` | output_mismatch | 43/58 | 58/58 |
| `focusrect_property_swf5` | output_mismatch | 992/1237 | 1237/1237 |
| `focusrect_property_swf6` | output_mismatch | 1043/1237 | 1237/1237 |
| `get_variable_in_scope` | output_mismatch | 26/29 | 29/29 |
| `object_string_coerce_swf5` | output_mismatch | 39/62 | 62/62 |
| `register_class_swf6` | output_mismatch | 35/37 | 37/37 |
| `removed_target_clip_scope` | output_mismatch | 33/35 | 35/35 |
| `set_variable_scope` | output_mismatch | 53/58 | 58/58 |

## Newly Failing (8)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `as_broadcaster_initialize` | output_mismatch | 10/10 | 9/10 |
| `bitmap_data` | output_mismatch | 1126/1126 | 83/1126 |
| `bitmap_data_compare` | output_mismatch | 40/40 | 31/40 |
| `bitmap_data_copypixels` | output_mismatch | 17/17 | 2/17 |
| `bitmap_data_noise` | output_mismatch | 631/631 | 1/631 |
| `bitmap_data_pixeldissolve` | output_mismatch | 1075/1075 | 5/1075 |
| `bitmap_data_threshold` | output_mismatch | 176/176 | 8/176 |
| `native_subclasses` | output_mismatch | 191/191 | 189/191 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls` | output_mismatch | 276/4497 | 836/4497 | -560 |
| `bitmap_filters` | output_mismatch | 466/548 | 542/548 | -76 |
| `global_proto_decls_delete` | output_mismatch | 255/4158 | 296/4158 | -41 |
| `native_objects_swf6` | output_mismatch | 81/84 | 83/84 | -2 |
| `global_instance_decls` | output_mismatch | 20/758 | 14/758 | +6 |
