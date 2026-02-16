# Ruffle Test Results Diff

**Previous:** `6c9b9420a890` (2026-02-15T23:34:36.628968+00:00)
**Current:** `9a27fcd10360` (2026-02-16T00:33:55.134395+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 203 | 209 | +6 |
| Total | 619 | 619 | 0 |
| Pass rate | 32.8% | 33.8% | +1.0% |
| Mismatched lines | 45881 | 45849 | -32 |
|   Decreased | | | -59 |
|   Increased | | | +27 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_length` | output_mismatch | 39/42 | 42/42 |
| `conflicting_instance_names` | output_mismatch | 22/23 | 23/23 |
| `define_function2_preload_order` | output_mismatch | 0/4 | 4/4 |
| `execution_order1` | output_mismatch | 3/5 | 5/5 |
| `execution_order2` | output_mismatch | 4/7 | 7/7 |
| `textfield_variable` | output_mismatch | 70/81 | 81/81 |
| `variable_args` | output_mismatch | 0/5 | 5/5 |
| `xml_attributes_read` | output_mismatch | 2/4 | 4/4 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `stage_object_enumerate` | output_mismatch | 4/4 | 1/4 |
| `xml_namespaces` | output_mismatch | 203/203 | 197/203 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_object_properties` | output_mismatch | 164/241 | 173/241 | -9 |
| `stage_object_properties_swf6` | output_mismatch | 157/231 | 166/231 | -9 |
| `default_names` | output_mismatch | 5/52 | 11/52 | -6 |
| `target_clip_removed` | output_mismatch | 0/5 | 4/5 | -4 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `placeobject_occupied_depth` | output_mismatch | 0/6 | 0/6 | 0 |
| `execution_order4` | output_mismatch | 3/12 | 2/12 | +1 |
| `register_and_init_order` | segfault | 44/231 | 27/231 | +17 |
