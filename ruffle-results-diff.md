# Ruffle Test Results Diff

**Previous:** `6395c5894863` (2026-02-15T05:15:32.698615+00:00)
**Current:** `12e36a9c0d74` (2026-02-15T17:34:40.811420+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 167 | 181 | +14 |
| Total | 619 | 619 | 0 |
| Pass rate | 27.0% | 29.2% | +2.2% |
| Mismatched lines | 49503 | 49395 | -108 |
|   Decreased | | | -108 |

## Newly Passing (14)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_antialiastype` | output_mismatch | 291/296 | 296/296 |
| `edittext_default_format` | output_mismatch | 209/221 | 221/221 |
| `edittext_default_format_empty` | output_mismatch | 91/95 | 95/95 |
| `edittext_default_format_font_style` | output_mismatch | 303/335 | 335/335 |
| `edittext_password` | output_mismatch | 4/5 | 5/5 |
| `error` | output_mismatch | 50/58 | 58/58 |
| `movieclip_default_state` | output_mismatch | 64/69 | 69/69 |
| `object_constructor` | output_mismatch | 32/33 | 33/33 |
| `sandbox_type_local_file` | output_mismatch | 0/1 | 1/1 |
| `string_coercion` | output_mismatch | 116/117 | 117/117 |
| `text_format_display` | output_mismatch | 10/21 | 21/21 |
| `textfield_properties` | output_mismatch | 43/44 | 44/44 |
| `textfield_text` | output_mismatch | 6/7 | 7/7 |
| `textfield_variable` | output_mismatch | 64/81 | 81/81 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_html_align_swf8` | output_mismatch | 40/52 | 45/52 | -5 |
| `edittext_html_align_swf7` | output_mismatch | 40/52 | 42/52 | -2 |
| `transform` | output_mismatch | 49/70 | 50/70 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
