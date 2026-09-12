# Ruffle Test Results Diff

**Previous:** `ea6960eacaf6` (2026-09-11T18:44:39.873259+00:00)
**Current:** `d8da5a18c354` (2026-09-12T03:19:52.765331+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 691 | 699 | +8 |
| Total | 733 | 734 | +1 |
| Pass rate | 94.3% | 95.2% | +0.9% |
| Mismatched lines | 11666 | 11252 | -414 |
|   Decreased | | | -420 |
|   Increased | | | +6 |

## Newly Passing (7)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `hitarea_sweep` | output_mismatch | 3/33 | 33/33 |
| `loadvariables_method` | output_mismatch | 0/7 | 7/7 |
| `new_class_prototype_getter` | output_mismatch | 1/6 | 6/6 |
| `set_property_values/swf5` | output_mismatch | 1620/1743 | 1743/1743 |
| `set_property_values/swf6` | output_mismatch | 1620/1743 | 1743/1743 |
| `set_property_values/swf7` | output_mismatch | 1620/1743 | 1743/1743 |
| `swf4_vars` | ruffle_matched | 22/25 | 25/25 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `edittext_onscroller` | output_mismatch | ruffle_matched | 0/14 | 6/14 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `bitmapdata_copypixels_self` | pass | 612/612 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `hitarea_remove_owner_drag` | output_mismatch | 5/10 | 2/10 | +3 |
| `set_property_values/swf4` | output_mismatch | 349/1571 | 346/1571 | +3 |
