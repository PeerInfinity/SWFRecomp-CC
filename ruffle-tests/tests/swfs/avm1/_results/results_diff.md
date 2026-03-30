# Ruffle Test Results Diff

**Previous:** `06e503cb4426` (2026-03-30T17:28:52.313482+00:00)
**Current:** `5ec473ecb0f5` (2026-03-30T19:31:20.974943+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 563 | 564 | +1 |
| Total | 620 | 620 | 0 |
| Pass rate | 90.8% | 91.0% | +0.2% |
| Mismatched lines | 11422 | 11639 | +217 |
|   Decreased | | | -7 |
|   Increased | | | +224 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `native_objects_swf6` | output_mismatch | 83/84 | 84/84 |
| `native_subclasses` | output_mismatch | 190/191 | 191/191 |
| `string_relational_compare` | output_mismatch | 3/4 | 4/4 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `textfield_props_swf5` | output_mismatch | 175/175 | 84/175 |
| `textfield_props_swf6` | output_mismatch | 210/210 | 77/210 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmap_filters` | output_mismatch | 540/548 | 544/548 | -4 |
