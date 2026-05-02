# Ruffle Test Results Diff

**Previous:** `7e96b41a4398` (2026-05-02T18:32:54.516133+00:00)
**Current:** `802674fd5caa` (2026-05-02T19:29:16.609001+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 600 | 568 | -32 |
| Total | 647 | 647 | 0 |
| Pass rate | 92.7% | 87.8% | -4.9% |
| Mismatched lines | 8966 | 10309 | +1343 |
|   Increased | | | +1343 |

## Newly Failing (32)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `clone_sprite_edittext` | output_mismatch | 94/94 | 70/94 |
| `clone_sprite_edittext_dynamic` | output_mismatch | 86/86 | 54/86 |
| `edittext_align` | output_mismatch | 60/60 | 36/60 |
| `edittext_align_trailing_spaces_swf7` | output_mismatch | 576/576 | 279/576 |
| `edittext_align_trailing_spaces_swf8` | output_mismatch | 576/576 | 315/576 |
| `edittext_autosize` | output_mismatch | 71/71 | 53/71 |
| `edittext_bullet` | output_mismatch | 30/30 | 18/30 |
| `edittext_default_format` | output_mismatch | 221/221 | 114/221 |
| `edittext_default_format_empty` | output_mismatch | 100/100 | 5/100 |
| `edittext_default_format_font_style` | output_mismatch | 335/335 | 192/335 |
| `edittext_drag_select` | output_mismatch | 9/9 | 6/9 |
| `edittext_focus_selection` | output_mismatch | 2/2 | 0/2 |
| `edittext_font_size` | output_mismatch | 45/45 | 15/45 |
| `edittext_html_align_swf7` | output_mismatch | 52/52 | 12/52 |
| `edittext_html_align_swf8` | output_mismatch | 52/52 | 12/52 |
| `edittext_html_color` | output_mismatch | 114/114 | 38/114 |
| `edittext_html_roundtrip` | output_mismatch | 17/17 | 13/17 |
| `edittext_ime_focus_lost` | output_mismatch | 7/7 | 2/7 |
| `edittext_leading` | output_mismatch | 9/9 | 3/9 |
| `edittext_letter_spacing` | output_mismatch | 15/15 | 9/15 |
| `edittext_margins` | output_mismatch | 25/25 | 15/25 |
| `edittext_newlines` | output_mismatch | 30/30 | 19/30 |
| `edittext_programmatic_focus` | output_mismatch | 12/12 | 6/12 |
| `edittext_stylesheet` | output_mismatch | 325/325 | 324/325 |
| `edittext_tab_focus` | output_mismatch | 13/13 | 9/13 |
| `edittext_tab_stops` | output_mismatch | 60/60 | 36/60 |
| `edittext_tag_indent` | output_mismatch | 31/31 | 5/31 |
| `edittext_text_height_leading` | output_mismatch | 20/20 | 10/20 |
| `edittext_underline` | output_mismatch | 40/40 | 24/40 |
| `movieclip_get_instance_at_depth` | output_mismatch | 28/28 | 27/28 |
| `selection` | output_mismatch | 454/454 | 452/454 |
| `textfield_properties` | output_mismatch | 44/44 | 37/44 |
