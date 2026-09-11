# Ruffle Test Results Diff

**Previous:** `12d2ec06b7bf` (2026-09-05T05:20:58.540391+00:00)
**Current:** `c4a952960bca` (2026-09-11T15:53:45.613311+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1198 | 1200 | +2 |
| Total | 1261 | 1270 | +9 |
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

## Added Tests (9)

| Test | Status | Lines |
|------|--------|-------|
| `bitmap_filter_abstract` | output_mismatch | 0/6 |
| `bitmapdata_draw_cab_quality` | pass | 0/0 |
| `bytearray_bad_symbol_class` | output_mismatch | 1/3 |
| `bytearray_bad_symbol_class_other_movie` | output_mismatch | 4/6 |
| `displayobject_z` | output_mismatch | 6/38 |
| `edittext_scroll_event` | output_mismatch | 2/37 |
| `indexof_xml` | pass | 10/10 |
| `json_parse_errors` | output_mismatch | 4/84 |
| `json_parse_numbers` | output_mismatch | 31/131 |
