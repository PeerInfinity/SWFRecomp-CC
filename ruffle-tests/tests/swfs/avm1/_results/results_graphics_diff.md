# Ruffle Test Results Diff

**Previous:** `3ebcb54f10d2` (2026-08-01T06:45:19.596528+00:00)
**Current:** `07c119c505f9` (2026-08-01T07:44:04.159404+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 670 | 672 | +2 |
| Total | 718 | 718 | 0 |
| Pass rate | 93.3% | 93.6% | +0.3% |
| Mismatched lines | 14799 | 14547 | -252 |
|   Decreased | | | -253 |
|   Increased | | | +1 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `focusrect_property_swf6` | output_mismatch | 1236/1237 | 1237/1237 |
| `globals_swf6` | output_mismatch | 301/304 | 304/304 |
| `textfield_props_swf6` | output_mismatch | 53/210 | 210/210 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `native_objects_swf6` | output_mismatch | 115/115 | 114/115 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `textfield_props_swf5` | output_mismatch | ruffle_matched | 82/175 | 173/175 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `globals_swf5` | output_mismatch | 293/304 | 294/304 | -1 |
