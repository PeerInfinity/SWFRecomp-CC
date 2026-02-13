# Ruffle Test Results Diff

**Previous:** `4f02643feca2` (2026-02-13T20:11:30.390221+00:00)
**Current:** `51824ed311df` (2026-02-13T20:32:04.814914+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 137 | 137 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 22.1% | 22.1% | 0% |
| Mismatched lines | 57783 | 57706 | -77 |
|   Decreased | | | -77 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `define_local` | segfault | output_mismatch | 2/27 | 2/27 |

## Line Count Changed (17)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_newline_stripping` | output_mismatch | 15/64 | 32/64 | -17 |
| `textfield_variable` | output_mismatch | 44/81 | 54/81 | -10 |
| `edittext_html_swf6` | output_mismatch | 2006/5377 | 2014/5377 | -8 |
| `edittext_html_swf7` | output_mismatch | 1370/5377 | 1378/5377 | -8 |
| `edittext_html_swf8` | output_mismatch | 1355/5377 | 1363/5377 | -8 |
| `textfield_properties` | output_mismatch | 26/44 | 32/44 | -6 |
| `edittext_tag_indent` | output_mismatch | 0/31 | 5/31 | -5 |
| `clone_sprite_types` | output_mismatch | 9/24 | 12/24 | -3 |
| `clone_sprite_edittext` | output_mismatch | 0/94 | 2/94 | -2 |
| `edittext_autosize_setter` | output_mismatch | 0/20 | 2/20 | -2 |
| `edittext_scroll` | output_mismatch | 31/54 | 33/54 | -2 |
| `device_font_spacing` | segfault | 0/91 | 1/91 | -1 |
| `edittext_html_condensewhite_swf7` | output_mismatch | 92/311 | 93/311 | -1 |
| `edittext_html_condensewhite_swf8` | output_mismatch | 89/311 | 90/311 | -1 |
| `textfield_background_color` | output_mismatch | 7/11 | 8/11 | -1 |
| `textfield_border_color` | output_mismatch | 7/11 | 8/11 | -1 |
| `textfield_text` | output_mismatch | 5/7 | 6/7 | -1 |
