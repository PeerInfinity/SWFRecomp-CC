# Ruffle Test Results Diff

**Previous:** `bce37d63c446` (2026-02-14T05:21:39.257714+00:00)
**Current:** `75322310bcb8` (2026-02-14T05:43:07.865894+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 159 | 163 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 25.7% | 26.3% | +0.6% |
| Mismatched lines | 54059 | 53662 | -397 |
|   Decreased | | | -397 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `text_format_display` | output_mismatch | 10/21 | 21/21 |
| `text_format_font_max_length` | output_mismatch | 0/2 | 2/2 |
| `text_format_rounding_swf7` | output_mismatch | 609/840 | 840/840 |
| `text_format_rounding_swf8` | output_mismatch | 687/840 | 840/840 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
