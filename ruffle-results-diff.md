# Ruffle Test Results Diff

**Previous:** `75322310bcb8` (2026-02-14T05:43:07.865894+00:00)
**Current:** `bceacde4cc39` (2026-02-14T06:42:49.553796+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 163 | 164 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 26.3% | 26.5% | +0.2% |
| Mismatched lines | 53662 | 53294 | -368 |
|   Decreased | | | -369 |
|   Increased | | | +1 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_default_format_empty` | output_mismatch | 5/95 | 95/95 |

## Line Count Changed (13)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_default_format_font_style` | output_mismatch | 186/335 | 327/335 | -141 |
| `edittext_default_format` | output_mismatch | 114/221 | 150/221 | -36 |
| `edittext_html_align_swf8` | output_mismatch | 12/52 | 45/52 | -33 |
| `edittext_html_align_swf7` | output_mismatch | 12/52 | 42/52 | -30 |
| `external_interface_toxml_basic` | output_mismatch | 20/179 | 35/179 | -15 |
| `as_set_prop_flags` | output_mismatch | 45/79 | 54/79 | -9 |
| `textfield_variable` | output_mismatch | 54/81 | 63/81 | -9 |
| `textfield_properties` | output_mismatch | 35/44 | 38/44 | -3 |
| `edittext_tag_indent` | output_mismatch | 5/31 | 7/31 | -2 |
| `external_interface_toxml_array` | output_mismatch | 2/25 | 3/25 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `issue_3522` | output_mismatch | 1/2 | 1/2 | 0 |
| `swf5_no_closure` | output_mismatch | 2/19 | 1/19 | +1 |
