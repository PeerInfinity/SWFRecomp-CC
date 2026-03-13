# Ruffle Test Results Diff

**Previous:** `468281bfa9a4` (2026-03-13T04:22:02.777199+00:00)
**Current:** `e5aadd667fc8` (2026-03-13T18:01:43.624698+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 532 | 531 | -1 |
| Total | 618 | 618 | 0 |
| Pass rate | 86.1% | 85.9% | -0.2% |
| Mismatched lines | 17285 | 15121 | -2164 |
|   Decreased | | | -2210 |
|   Increased | | | +46 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `focus_visibility_change` | output_mismatch | 7/45 | 45/45 |
| `focusrect_property_swf5` | output_mismatch | 261/1237 | 1237/1237 |
| `focusrect_property_swf6` | output_mismatch | 560/1237 | 1237/1237 |
| `focusrect_property_swf7` | output_mismatch | 718/1237 | 1237/1237 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `global_swf5_6_7_8_9` | output_mismatch | 1145/1145 | 1115/1145 |
| `globals_swf5` | output_mismatch | 304/304 | 296/304 |
| `globals_swf6` | output_mismatch | 304/304 | 301/304 |
| `target_clip_swf5` | output_mismatch | 2/2 | 0/2 |
| `textfield_props_swf5` | output_mismatch | 175/175 | 173/175 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `native_objects_swf6` | output_mismatch | 83/84 | 82/84 | +1 |
