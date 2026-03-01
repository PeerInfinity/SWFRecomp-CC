# Ruffle Test Results Diff

**Previous:** `8fb2a2d8470d` (2026-03-01T01:21:30.529446+00:00)
**Current:** `ed63c99c92ee` (2026-03-01T03:10:02.628367+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 408 | 412 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 65.9% | 66.6% | +0.7% |
| Mismatched lines | 30217 | 29714 | -503 |
|   Decreased | | | -503 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bad_placeobject_clipaction` | output_mismatch | 0/2 | 2/2 |
| `movieclip_create_text_field` | output_mismatch | 0/90 | 90/90 |
| `textfield_cache_as_bitmap` | output_mismatch | 0/1 | 1/1 |
| `watch_textfield` | output_mismatch | 2/12 | 12/12 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmap_filters` | output_mismatch | 0/548 | 254/548 | -254 |
| `edittext_stylesheet` | output_mismatch | 107/325 | 204/325 | -97 |
| `edittext_html_color` | output_mismatch | 38/114 | 76/114 | -38 |
| `edittext_text_height_leading` | output_mismatch | 0/20 | 10/20 | -10 |
| `register_class_with_sound` | output_mismatch | 5/11 | 6/11 | -1 |
| `focus_remove` | output_mismatch | 6/33 | 6/33 | 0 |
| `focus_visibility_change` | output_mismatch | 7/45 | 7/45 | 0 |
