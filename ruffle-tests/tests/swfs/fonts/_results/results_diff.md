# Ruffle Test Results Diff

**Previous:** `f55511379655` (2026-10-18T08:49:49.736250+00:00)
**Current:** `344c85a166c3` (2026-10-25T08:41:41.683455+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 7 | 0 | -7 |
| Total | 9 | 9 | 0 |
| Pass rate | 77.8% | 0.0% | -77.8% |
| Mismatched lines | 26 | 0 | -26 |
|   Decreased | | | -26 |

## Newly Failing (7)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `device_font_glyph_fallback` | compile_fail | 36/36 | - |
| `device_font_kerning` | compile_fail | 4/4 | - |
| `device_font_list` | compile_fail | 64/64 | - |
| `embed_matching/fallback_preferences` | compile_fail | 0/0 | - |
| `embed_matching/match_style` | compile_fail | 0/0 | - |
| `embed_matching/no_font_found` | compile_fail | 0/0 | - |
| `embed_name_lookup` | compile_fail | 242/242 | - |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `device_font_name_case` | output_mismatch | compile_fail | 1/13 | - |
| `device_font_no_ink` | ruffle_matched | compile_fail | 4/18 | - |
