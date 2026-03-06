# Ruffle Test Results Diff

**Previous:** `b7965a8fc0af` (2026-03-06T02:28:30.127611+00:00)
**Current:** `4eb4f907d64b` (2026-03-06T03:19:20.773294+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 461 | 466 | +5 |
| Total | 619 | 619 | 0 |
| Pass rate | 74.5% | 75.3% | +0.8% |
| Mismatched lines | 21318 | 21343 | +25 |
|   Decreased | | | -563 |
|   Increased | | | +588 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_align` | output_mismatch | 52/60 | 60/60 |
| `edittext_align_trailing_spaces_swf7` | output_mismatch | 360/576 | 576/576 |
| `edittext_align_trailing_spaces_swf8` | output_mismatch | 360/576 | 576/576 |
| `edittext_autosize` | output_mismatch | 56/71 | 71/71 |
| `edittext_font_size` | output_mismatch | 40/45 | 45/45 |
| `edittext_leading` | output_mismatch | 6/9 | 9/9 |
| `edittext_letter_spacing` | output_mismatch | 14/15 | 15/15 |
| `edittext_margins` | output_mismatch | 20/25 | 25/25 |
| `edittext_underline` | output_mismatch | 36/40 | 40/40 |
| `external_interface_escapexml` | output_mismatch | 0/26 | 26/26 |
| `external_interface_jsquotestring` | output_mismatch | 0/21 | 21/21 |
| `external_interface_unescapexml` | output_mismatch | 0/40 | 40/40 |

## Newly Failing (7)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `add2` | output_mismatch | 354/354 | 31/354 |
| `device_font_spacing` | output_mismatch | 91/91 | 47/91 |
| `duplicate_movie_clip` | output_mismatch | 20/20 | 14/20 |
| `mcl_getprogress` | output_mismatch | 30/30 | 4/30 |
| `mcl_loadclip` | output_mismatch | 149/149 | 12/149 |
| `path_string` | output_mismatch | 322/322 | 280/322 |
| `string_coercion` | output_mismatch | 117/117 | 107/117 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_newlines` | output_mismatch | 20/30 | 23/30 | -3 |
