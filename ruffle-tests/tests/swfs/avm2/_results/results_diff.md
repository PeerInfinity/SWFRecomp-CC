# Ruffle Test Results Diff

**Previous:** `bf907d0023cc` (2026-09-06T08:47:24.353795+00:00)
**Current:** `13dfc5b483e9` (2026-09-11T16:55:04.399174+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1199 | 1200 | +1 |
| Total | 1262 | 1270 | +8 |
| Pass rate | 95.0% | 94.5% | -0.5% |
| Mismatched lines | 2875 | 3119 | +244 |
|   Decreased | | | -16 |
|   Increased | | | +3 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loader_duplicate_class` | output_mismatch | 32/48 | 48/48 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `geom_transform` | output_mismatch | 74/74 | 71/74 |

## Added Tests (8)

| Test | Status | Lines |
|------|--------|-------|
| `bitmap_filter_abstract` | output_mismatch | 0/6 |
| `bytearray_bad_symbol_class` | output_mismatch | 1/3 |
| `bytearray_bad_symbol_class_other_movie` | output_mismatch | 4/6 |
| `displayobject_z` | output_mismatch | 6/38 |
| `edittext_scroll_event` | output_mismatch | 2/37 |
| `indexof_xml` | pass | 10/10 |
| `json_parse_errors` | output_mismatch | 4/84 |
| `json_parse_numbers` | output_mismatch | 31/131 |
