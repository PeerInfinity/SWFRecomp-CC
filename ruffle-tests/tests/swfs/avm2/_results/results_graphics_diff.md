# Ruffle Test Results Diff

**Previous:** `2358a37b1cc0` (2026-07-30T18:36:08.275785+00:00)
**Current:** `ff7151c15004` (2026-07-30T22:08:16.368126+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1000 | 1009 | +9 |
| Total | 1222 | 1222 | 0 |
| Pass rate | 81.8% | 82.6% | +0.8% |
| Mismatched lines | 35129 | 34722 | -407 |
|   Decreased | | | -407 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `blend_mode_null` | output_mismatch | 0/1 | 1/1 |
| `button_bounds` | output_mismatch | 0/1 | 1/1 |
| `button_hittest` | output_mismatch | 1/2 | 2/2 |
| `displayobject_hittestpoint` | output_mismatch | 47/49 | 49/49 |
| `displayobject_hittestpoint_root` | output_mismatch | 11/13 | 13/13 |
| `displayobjectcontainer_getobjectsunderpoint` | output_mismatch | 13/15 | 15/15 |
| `flash_media_video_rotation_probe` | output_mismatch | 20/27 | 27/27 |
| `movieclip_hittest` | output_mismatch | 65/67 | 67/67 |
| `tab_ordering_arrows` | output_mismatch | 645/998 | 998/998 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bounds_mode` | output_mismatch | 233/269 | 253/269 | -20 |
| `displayobject_transform` | output_mismatch | 59/89 | 67/89 | -8 |
| `displayobject_scrollrect` | output_mismatch | 14/33 | 19/33 | -5 |
| `flash_media_video_setter` | output_mismatch | 33/40 | 36/40 | -3 |
