# Ruffle Test Results Diff

**Previous:** `b7886f8ebfb8` (2026-03-06T00:32:31.305126+00:00)
**Current:** `3160601a4e07` (2026-03-06T00:52:57.509942+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 464 | 456 | -8 |
| Total | 619 | 619 | 0 |
| Pass rate | 75.0% | 73.7% | -1.3% |
| Mismatched lines | 21361 | 21403 | +42 |
|   Decreased | | | -436 |
|   Increased | | | +478 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `device_font_spacing` | output_mismatch | 46/91 | 91/91 |

## Newly Failing (9)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_align` | output_mismatch | 60/60 | 52/60 |
| `edittext_align_trailing_spaces_swf7` | output_mismatch | 576/576 | 360/576 |
| `edittext_align_trailing_spaces_swf8` | output_mismatch | 576/576 | 360/576 |
| `edittext_autosize` | output_mismatch | 71/71 | 56/71 |
| `edittext_font_size` | output_mismatch | 45/45 | 40/45 |
| `edittext_leading` | output_mismatch | 9/9 | 6/9 |
| `edittext_letter_spacing` | output_mismatch | 15/15 | 14/15 |
| `edittext_margins` | output_mismatch | 25/25 | 20/25 |
| `edittext_underline` | output_mismatch | 40/40 | 36/40 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `swf7_global_funcs` | output_mismatch | 76/232 | 211/232 | -135 |
| `swf6_global_funcs` | output_mismatch | 76/232 | 205/232 | -129 |
| `swf5_global_funcs` | output_mismatch | 73/232 | 199/232 | -126 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 1/4158 | -1 |
| `global_proto_decls` | output_mismatch | 13/4497 | 11/4497 | +2 |
| `edittext_newlines` | output_mismatch | 23/30 | 20/30 | +3 |
