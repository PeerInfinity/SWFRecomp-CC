# Ruffle Test Results Diff

**Previous:** `817fdfb4dc79` (2026-03-01T03:35:55.068700+00:00)
**Current:** `fa0f23599ac9` (2026-03-01T04:39:45.856190+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 413 | 414 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 66.7% | 66.9% | +0.2% |
| Mismatched lines | 29692 | 29382 | -310 |
|   Decreased | | | -310 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_font_size` | output_mismatch | 15/45 | 45/45 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 266/338 | - |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_align_trailing_spaces_swf7` | output_mismatch | 264/576 | 396/576 | -132 |
| `edittext_align_trailing_spaces_swf8` | output_mismatch | 288/576 | 324/576 | -36 |
| `edittext_align` | output_mismatch | 36/60 | 52/60 | -16 |
| `edittext_tab_stops` | output_mismatch | 36/60 | 45/60 | -9 |
| `edittext_text_height_leading` | output_mismatch | 10/20 | 16/20 | -6 |
| `edittext_newlines` | output_mismatch | 18/30 | 23/30 | -5 |
| `edittext_autosize` | output_mismatch | 44/71 | 48/71 | -4 |
