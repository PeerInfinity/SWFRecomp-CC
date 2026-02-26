# Ruffle Test Results Diff

**Previous:** `d91382604512` (2026-02-26T05:38:28.103342+00:00)
**Current:** `8080efc08b44` (2026-02-26T06:34:31.415393+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 371 | 374 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 59.9% | 60.4% | +0.5% |
| Mismatched lines | 32211 | 32140 | -71 |
|   Decreased | | | -88 |
|   Increased | | | +17 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `button_key_events` | output_mismatch | 2/14 | 14/14 |
| `button_key_events_special` | output_mismatch | 1/45 | 45/45 |
| `button_keypress_vs_press` | output_mismatch | 5/25 | 25/25 |
| `movieclip_in_removed_button` | output_mismatch | 2/4 | 4/4 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `create_empty_movie_clip` | output_mismatch | 3/3 | 3/3 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `button_keypress_vs_tab` | output_mismatch | 10/20 | 18/20 | -8 |
| `button_keypress_vs_textinput` | output_mismatch | 1/4 | 3/4 | -2 |
| `textfield_cache_as_bitmap` | output_mismatch | 0/1 | 0/1 | 0 |
| `tab_ordering_events` | output_mismatch | 27/150 | 26/150 | +1 |
| `focus_keyboard_press` | output_mismatch | 17/60 | 1/60 | +16 |
