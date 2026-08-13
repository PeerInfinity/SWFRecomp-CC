# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.701461+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.541967+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 10 | 0 | -10 |
| Total | 11 | 11 | 0 |
| Pass rate | 90.9% | 0.0% | -90.9% |
| Mismatched lines | 1 | 0 | -1 |
|   Decreased | | | -1 |

## Newly Failing (10)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `auto_size/height` | compile_fail | 1/1 | - |
| `auto_size/return` | compile_fail | 12/12 | - |
| `auto_size/width` | compile_fail | 6/6 | - |
| `br_at_start` | compile_fail | 0/0 | - |
| `html_entity_parsing` | compile_fail | 213/213 | - |
| `style_changes_in_html` | compile_fail | 0/0 | - |
| `text_caret_placement_align` | compile_fail | 248/248 | - |
| `text_caret_placement_leading` | compile_fail | 244/244 | - |
| `text_caret_placement_scroll` | compile_fail | 108/108 | - |
| `text_caret_placement_translated_bounds` | compile_fail | 140/140 | - |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `links_in_scrolled_text` | output_mismatch | compile_fail | 0/1 | - |
