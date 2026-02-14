# Ruffle Test Results Diff

**Previous:** `03e795d08e7a` (2026-02-14T01:20:26.847876+00:00)
**Current:** `2a39d1c32901` (2026-02-14T01:29:43.731335+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 145 | 149 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 23.4% | 24.1% | +0.7% |
| Mismatched lines | 57227 | 57210 | -17 |
|   Decreased | | | -30 |
|   Increased | | | +13 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `capabilities_resolution` | output_mismatch | 4/8 | 8/8 |
| `textfield_background_color` | output_mismatch | 8/11 | 11/11 |
| `textfield_border_color` | output_mismatch | 8/11 | 11/11 |
| `textfield_text` | output_mismatch | 6/7 | 7/7 |

## Line Count Changed (16)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_default_format_font_style` | output_mismatch | 176/335 | 186/335 | -10 |
| `textfield_properties` | output_mismatch | 32/44 | 35/44 | -3 |
| `edittext_html_condensewhite_swf7` | output_mismatch | 93/311 | 94/311 | -1 |
| `edittext_html_condensewhite_swf8` | output_mismatch | 90/311 | 91/311 | -1 |
| `globals_swf5` | output_mismatch | 206/304 | 207/304 | -1 |
| `globals_swf6` | output_mismatch | 213/304 | 214/304 | -1 |
| `globals_swf7` | output_mismatch | 210/304 | 211/304 | -1 |
| `globals_swf8` | output_mismatch | 136/304 | 137/304 | -1 |
| `device_font_spacing` | segfault | 1/91 | 1/91 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `issue_3522` | output_mismatch | 1/2 | 1/2 | 0 |
| `edittext_html_swf6` | output_mismatch | 2014/5377 | 2013/5377 | +1 |
| `edittext_html_swf7` | output_mismatch | 1378/5377 | 1377/5377 | +1 |
| `edittext_html_swf8` | output_mismatch | 1363/5377 | 1362/5377 | +1 |
| `textfield_variable` | output_mismatch | 54/81 | 53/81 | +1 |
| `edittext_newline_stripping` | output_mismatch | 32/64 | 23/64 | +9 |
