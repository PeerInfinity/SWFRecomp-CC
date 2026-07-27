# Ruffle Test Results Diff

**Previous:** `8213dd4d61dd` (2026-07-27T00:30:06.113751+00:00)
**Current:** `28577da2aa5c` (2026-07-27T02:18:25.306184+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 855 | 860 | +5 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 70.0% | 70.4% | +0.4% |
| Mismatched lines | 46312 | 46257 | -55 |
|   Decreased | | | -55 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loader_bitmap_transparency` | output_mismatch | 2/14 | 14/14 |
| `loader_image` | output_mismatch | 0/8 | 8/8 |
| `loader_loadbytes_invalid_png` | output_mismatch | 1/4 | 4/4 |
| `loader_visibility_interactive` | output_mismatch | 0/1 | 1/1 |
| `url_loader` | output_mismatch | 0/25 | 25/25 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `loader_noninteractive_try_click_root` | output_mismatch | 0/5 | 4/5 | -4 |
| `blend_shader_luma_lighten` | output_mismatch | 0/3 | 1/3 | -1 |
| `bom` | output_mismatch | 3/9 | 4/9 | -1 |
| `large_preload_image_from_bytes` | output_mismatch | 19/25 | 19/25 | 0 |
