# Ruffle Test Results Diff

**Previous:** `e05a8fe0d131` (2026-07-15T03:48:09.945510+00:00)
**Current:** `8cc2f5440fc6` (2026-07-15T20:31:20.352151+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 829 | 821 | -8 |
| Total | 1205 | 1206 | +1 |
| Pass rate | 68.8% | 68.1% | -0.7% |
| Mismatched lines | 47323 | 47373 | +50 |
|   Increased | | | +48 |

## Newly Failing (8)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `bitmapdata_zero_size` | output_mismatch | 5/5 | 5/8 |
| `coerce_property` | ruffle_matched | 33/33 | 33/36 |
| `event_handler_exception` | output_mismatch | 4/4 | 1/11 |
| `parse_float` | output_mismatch | 80/80 | 80/81 |
| `string_concat_fromcharcode` | output_mismatch | 36/36 | 36/37 |
| `string_slice_substr_substring` | output_mismatch | 169/169 | 169/170 |
| `uncaught_errors_stringified` | output_mismatch | 3/3 | 1/18 |
| `xml_basic` | output_mismatch | 32/32 | 32/33 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `uncaught_error_basic` | output_mismatch | 0/2 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `applicationdomain_getqualifieddefinitionnames` | output_mismatch | 0/8 | 0/9 | +1 |
| `external_interface` | output_mismatch | 1/104 | 1/105 | +1 |
| `filefilter_properties` | output_mismatch | 0/3 | 0/4 | +1 |
| `parse_float_swf10` | output_mismatch | 78/80 | 78/81 | +1 |
| `parse_int` | output_mismatch | 132/134 | 132/135 | +1 |
| `loader_error_in_root_ctor` | output_mismatch | 0/2 | 0/4 | +2 |
| `loader_load` | output_mismatch | 3/126 | 3/128 | +2 |
| `loader_method` | output_mismatch | 4/83 | 4/85 | +2 |
