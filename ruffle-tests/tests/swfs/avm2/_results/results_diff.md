# Ruffle Test Results Diff

**Previous:** `f0e6fb25d672` (2026-07-24T19:31:35.254726+00:00)
**Current:** `b615844ac341` (2026-07-26T09:20:04.936583+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 829 | 843 | +14 |
| Total | 1217 | 1219 | +2 |
| Pass rate | 68.1% | 69.2% | +1.1% |
| Mismatched lines | 47483 | 47163 | -320 |
|   Decreased | | | -384 |

## Newly Passing (14)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bytearray_oom` | timeout | - | 3/3 |
| `capabilities_resolution` | output_mismatch | 1/8 | 8/8 |
| `date` | output_mismatch | 15/30 | 30/30 |
| `date_parse` | output_mismatch | 2/36 | 36/36 |
| `decode_uri` | output_mismatch | 0/71 | 71/71 |
| `domain_memory` | runtime_error | 1/133 | 133/133 |
| `encode_uri_surrogate_pair_swf11` | output_mismatch | 0/15 | 15/15 |
| `escape` | output_mismatch | 20/71 | 71/71 |
| `indexing_delete` | output_mismatch | 60/75 | 75/75 |
| `parse_float` | output_mismatch | 80/81 | 81/81 |
| `string_concat_fromcharcode` | output_mismatch | 36/37 | 37/37 |
| `string_slice_substr_substring` | output_mismatch | 169/170 | 170/170 |
| `unescape` | output_mismatch | 25/28 | 28/28 |
| `xml_basic` | output_mismatch | 32/33 | 33/33 |

## Added Tests (2)

| Test | Status | Lines |
|------|--------|-------|
| `displayobject_getrect` | output_mismatch | 2/16 |
| `proxy_not_overridden` | output_mismatch | 4/54 |

## Line Count Changed (9)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `primitive_valueOf` | output_mismatch | 12/285 | 25/285 | -13 |
| `invalid_utf8` | output_mismatch | 3/12 | 11/12 | -8 |
| `static_length` | output_mismatch | 3/24 | 11/24 | -8 |
| `primitive_toString` | output_mismatch | 14/277 | 20/277 | -6 |
| `parse_float_swf10` | output_mismatch | 78/81 | 79/81 | -1 |
| `parse_int` | output_mismatch | 132/135 | 133/135 | -1 |
| `encode_uri_surrogate_pair_swf10` | ruffle_matched | 0/15 | 0/15 | 0 |
| `external_interface` | output_mismatch | 3/105 | 3/105 | 0 |
| `filefilter_properties` | output_mismatch | 0/4 | 0/4 | 0 |
