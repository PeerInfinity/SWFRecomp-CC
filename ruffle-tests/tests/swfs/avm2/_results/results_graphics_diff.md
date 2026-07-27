# Ruffle Test Results Diff

**Previous:** `9f4be9647bf4` (2026-07-26T22:42:49.050508+00:00)
**Current:** `8213dd4d61dd` (2026-07-27T00:30:06.113751+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 845 | 855 | +10 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 69.2% | 70.0% | +0.8% |
| Mismatched lines | 46461 | 46312 | -149 |
|   Decreased | | | -149 |

## Newly Passing (10)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `jpeg_loader_context` | output_mismatch | 0/6 | 6/6 |
| `loader_bytes_unknown_content` | output_mismatch | 1/14 | 14/14 |
| `loader_jpegxr` | output_mismatch | 0/2 | 2/2 |
| `loader_jpegxr_alpha` | output_mismatch | 0/1 | 1/1 |
| `loader_unknown_content` | output_mismatch | 0/24 | 24/24 |
| `loaderinfo_events` | output_mismatch | 4/7 | 7/7 |
| `loaderinfo_loadurl` | output_mismatch | 8/12 | 12/12 |
| `loaderinfo_more` | output_mismatch | 0/6 | 6/6 |
| `loaderinfo_properties_not_loaded` | output_mismatch | 15/23 | 23/23 |
| `stage_loaderinfo_properties` | output_mismatch | 22/24 | 24/24 |

## Line Count Changed (12)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `large_preload_image_from_bytes` | output_mismatch | 4/25 | 19/25 | -15 |
| `large_preload_from_bytes` | output_mismatch | 4/51 | 18/51 | -14 |
| `delayed_symbolclass` | output_mismatch | 3/28 | 16/28 | -13 |
| `loader_events` | output_mismatch | 8/92 | 19/92 | -11 |
| `loader_loadbytes_events` | output_mismatch | 2/30 | 11/30 | -9 |
| `large_preload_from_url` | output_mismatch | 8/27 | 16/27 | -8 |
| `loader_reuse` | output_mismatch | 7/38 | 14/38 | -7 |
| `displayobject_hittestpoint_root` | output_mismatch | 4/13 | 5/13 | -1 |
| `loader_bitmap_transparency` | output_mismatch | 1/14 | 2/14 | -1 |
| `loader_loadbytes_invalid_png` | output_mismatch | 0/4 | 1/4 | -1 |
| `font_registerfont` | output_mismatch | 5/129 | 5/129 | 0 |
| `loaderinfo_quine` | output_mismatch | 1/1005 | 1/1005 | 0 |
