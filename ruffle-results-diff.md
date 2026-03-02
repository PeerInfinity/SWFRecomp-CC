# Ruffle Test Results Diff

**Previous:** `2416c88e2938` (2026-03-01T22:19:27.566824+00:00)
**Current:** `13d730ad09b9` (2026-03-02T04:16:01.590294+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 426 | 425 | -1 |
| Total | 619 | 619 | 0 |
| Pass rate | 68.8% | 68.7% | -0.1% |
| Mismatched lines | 28868 | 23572 | -5296 |
|   Decreased | | | -5346 |
|   Increased | | | +50 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_html_color` | output_mismatch | 76/114 | 114/114 |
| `edittext_html_roundtrip` | output_mismatch | 11/17 | 17/17 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_default_format_font_style` | output_mismatch | 335/335 | 331/335 |
| `edittext_newline_stripping` | output_mismatch | 64/64 | 19/64 |
| `textfield_properties` | output_mismatch | 44/44 | 43/44 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_html_swf7` | output_mismatch | 3042/5377 | 5350/5377 | -2308 |
| `edittext_html_swf8` | output_mismatch | 3204/5377 | 5306/5377 | -2102 |
| `edittext_html_swf6` | output_mismatch | 3114/5377 | 3900/5377 | -786 |
| `device_font_spacing` | output_mismatch | 1/91 | 46/91 | -45 |
| `edittext_html_condensewhite_swf7` | output_mismatch | 166/311 | 205/311 | -39 |
| `edittext_html_condensewhite_swf8` | output_mismatch | 155/311 | 177/311 | -22 |
