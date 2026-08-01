# Ruffle Test Results Diff

**Previous:** `375373786d2d` (2026-08-01T03:29:50.701390+00:00)
**Current:** `3ebcb54f10d2` (2026-08-01T06:45:19.596528+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 669 | 670 | +1 |
| Total | 718 | 718 | 0 |
| Pass rate | 93.2% | 93.3% | +0.1% |
| Mismatched lines | 14553 | 14799 | +246 |
|   Decreased | | | -7 |
|   Increased | | | +253 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `form_loader_encoding_2` | output_mismatch | 0/3 | 3/3 |
| `form_loader_encoding_3` | output_mismatch | 1/3 | 3/3 |
| `native_objects_swf6` | output_mismatch | 114/115 | 115/115 |
| `string_relational_compare` | output_mismatch | 3/4 | 4/4 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `focusrect_property_swf6` | output_mismatch | 1237/1237 | 1236/1237 |
| `globals_swf6` | output_mismatch | 304/304 | 301/304 |
| `textfield_props_swf6` | output_mismatch | 210/210 | 53/210 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `textfield_props_swf5` | ruffle_matched | output_mismatch | 173/175 | 82/175 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `globals_swf5` | output_mismatch | 294/304 | 293/304 | +1 |
