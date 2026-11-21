# Ruffle Test Results Diff

**Previous:** `344c85a166c3` (2026-11-15T08:31:27.889293+00:00)
**Current:** `08709f65842a` (2026-11-21T17:00:08.546386+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 7 | +7 |
| Total | 9 | 9 | 0 |
| Pass rate | 0.0% | 77.8% | +77.8% |
| Mismatched lines | 0 | 26 | +26 |
|   Increased | | | +26 |

## Newly Passing (7)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `device_font_glyph_fallback` | compile_fail | - | 36/36 |
| `device_font_kerning` | compile_fail | - | 4/4 |
| `device_font_list` | compile_fail | - | 64/64 |
| `embed_matching/fallback_preferences` | compile_fail | - | 0/0 |
| `embed_matching/match_style` | compile_fail | - | 0/0 |
| `embed_matching/no_font_found` | compile_fail | - | 0/0 |
| `embed_name_lookup` | compile_fail | - | 242/242 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `device_font_name_case` | compile_fail | output_mismatch | - | 1/13 |
| `device_font_no_ink` | compile_fail | ruffle_matched | - | 4/18 |
