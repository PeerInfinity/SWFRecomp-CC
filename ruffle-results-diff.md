# Ruffle Test Results Diff

**Previous:** `077886357d3a` (2026-02-14T23:41:30.829664+00:00)
**Current:** `711e25ad1e38` (2026-02-15T01:31:32.330879+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 190 | 196 | +6 |
| Total | 619 | 619 | 0 |
| Pass rate | 30.7% | 31.7% | +1.0% |
| Mismatched lines | 51117 | 50592 | -525 |
|   Decreased | | | -525 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_antialiastype` | output_mismatch | 275/296 | 296/296 |
| `edittext_default_format` | output_mismatch | 150/221 | 221/221 |
| `edittext_default_format_font_style` | output_mismatch | 327/335 | 335/335 |
| `mouse_wheel_enabled` | output_mismatch | 0/2 | 2/2 |
| `textfield_maxchars` | output_mismatch | 1/3 | 3/3 |
| `textfield_properties` | output_mismatch | 38/44 | 44/44 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `device_font_spacing` | segfault | timeout | 1/91 | - |
| `tab_ordering_tabbable` | output_mismatch | segfault | 0/47 | - |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_align_trailing_spaces_swf8` | output_mismatch | 144/576 | 288/576 | -144 |
| `edittext_align_trailing_spaces_swf7` | output_mismatch | 144/576 | 264/576 | -120 |
| `frame_size_translated_negative` | output_mismatch | 10/21 | 14/21 | -4 |
| `frame_size_translated_positive` | output_mismatch | 10/21 | 14/21 | -4 |
| `clone_sprite_edittext_dynamic` | output_mismatch | 0/86 | 2/86 | -2 |
| `edittext_hscroll` | output_mismatch | 15/27 | 17/27 | -2 |
| `clone_sprite_types` | output_mismatch | 12/24 | 13/24 | -1 |
| `edittext_html_entity` | output_mismatch | 2/4 | 3/4 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `issue_9327` | output_mismatch | 0/2 | 0/2 | 0 |
