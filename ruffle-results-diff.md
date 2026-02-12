# Ruffle Test Results Diff

**Previous:** `10cb155c9d8f` (2026-02-12T19:58:38.976815+00:00)
**Current:** `0f4ca778db49` (2026-02-12T20:38:27.041874+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 87 | 72 | -15 |
| Total | 616 | 616 | 0 |
| Pass rate | 14.1% | 11.7% | -2.4% |
| Mismatched lines | 57187 | 56847 | -340 |
|   Decreased | | | -340 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `delete` | output_mismatch | 2/3 | 3/3 |
| `global_array` | output_mismatch | 1/4 | 3/3 |

## Newly Failing (17)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `bad_swf_tag_past_eof` | output_mismatch | 1/1 | 0/0 |
| `bitmap_data_colortransform` | output_mismatch | 1/1 | 0/0 |
| `bitmap_data_fillrect` | output_mismatch | 1/1 | 0/0 |
| `bitmap_data_perlinnoise` | output_mismatch | 1/1 | 0/0 |
| `bitmap_data_pixeldissolve_image` | output_mismatch | 1/1 | 0/0 |
| `bitmapdata_applyfilter_colormatrix` | output_mismatch | 1/1 | 0/0 |
| `focusrect_mouse_swf8` | output_mismatch | 1/1 | 0/0 |
| `focusrect_mouse_swf9` | output_mismatch | 1/1 | 0/0 |
| `issue_1671` | output_mismatch | 1/1 | 0/0 |
| `mask_reapply` | output_mismatch | 1/1 | 0/0 |
| `mask_with_drawing` | output_mismatch | 1/1 | 0/0 |
| `movieclip_begin_gradient_fill` | output_mismatch | 1/1 | 0/0 |
| `movieclip_line_gradient_style` | output_mismatch | 1/1 | 0/0 |
| `nested_textfields_in_buttons` | output_mismatch | 1/1 | 0/0 |
| `sound_start_load` | output_mismatch | 1/1 | 0/0 |
| `string_paths_keyevents` | output_mismatch | 1/1 | 0/0 |
| `string_paths_timer` | output_mismatch | 1/1 | 0/0 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 10/338 | - |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `object_constructor` | output_mismatch | 24/33 | 29/33 | -5 |
| `edittext_default_format_font_style` | output_mismatch | 176/336 | 176/335 | -1 |
| `recursive_prototypes` | output_mismatch | 0/1 | 0/0 | -1 |
| `xml_attributes_read` | output_mismatch | 1/5 | 1/4 | -1 |
| `array_enumerate` | output_mismatch | 0/4 | 0/4 | 0 |
| `localconnection` | output_mismatch | 1/580 | 0/579 | 0 |
