# Ruffle Test Results Diff

**Previous:** `1e2621bf53e3` (2026-02-24T23:00:57.500221+00:00)
**Current:** `c1f23adabbb1` (2026-02-24T23:34:38.258211+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 346 | 345 | -1 |
| Total | 619 | 619 | 0 |
| Pass rate | 55.9% | 55.7% | -0.2% |
| Mismatched lines | 33363 | 33550 | +187 |
|   Decreased | | | -14 |
|   Increased | | | +201 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `swf6_case_insensitive` | output_mismatch | 28/42 | 42/42 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `mcl_as_broadcaster` | output_mismatch | 12/12 | 8/12 |
| `textfield_variable` | output_mismatch | 81/81 | 78/81 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `focusrect_property_swf5` | output_mismatch | 298/1237 | 261/1237 | +37 |
| `focusrect_property_swf6` | output_mismatch | 717/1237 | 560/1237 | +157 |
