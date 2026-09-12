# Ruffle Test Results Diff

**Previous:** `f48c532bf170` (2026-09-12T00:02:29.959925+00:00)
**Current:** `521a53782850` (2026-09-12T01:30:44.514971+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 691 | 697 | +6 |
| Total | 734 | 734 | 0 |
| Pass rate | 94.1% | 95.0% | +0.9% |
| Mismatched lines | 11678 | 11284 | -394 |
|   Decreased | | | -399 |
|   Increased | | | +5 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmapdata_copypixels_self` | output_mismatch | 600/612 | 612/612 |
| `loadvariables_method` | output_mismatch | 0/7 | 7/7 |
| `new_class_prototype_getter` | output_mismatch | 1/6 | 6/6 |
| `set_property_values/swf5` | output_mismatch | 1620/1743 | 1743/1743 |
| `set_property_values/swf6` | output_mismatch | 1620/1743 | 1743/1743 |
| `set_property_values/swf7` | output_mismatch | 1620/1743 | 1743/1743 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `edittext_onscroller` | output_mismatch | ruffle_matched | 0/14 | 6/14 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `swf4_vars` | ruffle_matched | 22/25 | 21/25 | +1 |
| `set_property_values/swf4` | output_mismatch | 349/1571 | 345/1571 | +4 |
