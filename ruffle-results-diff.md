# Ruffle Test Results Diff

**Previous:** `b05c8cc5a0f0` (2026-02-23T23:31:15.300460+00:00)
**Current:** `a3b4b418e473` (2026-02-24T00:26:58.483514+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 316 | 319 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 51.1% | 51.5% | +0.4% |
| Mismatched lines | 34684 | 34646 | -38 |
|   Decreased | | | -39 |
|   Increased | | | +1 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `focus_root_movie` | output_mismatch | 0/2 | 2/2 |
| `focusrect_focuslost` | output_mismatch | 0/4 | 4/4 |
| `movieclip_focusenabled` | output_mismatch | 89/99 | 99/99 |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `button_keypress_vs_tab` | output_mismatch | 2/20 | 10/20 | -8 |
| `button_keypress_vs_press` | output_mismatch | 0/25 | 6/25 | -6 |
| `property_invalid_base_clip` | output_mismatch | 11/36 | 14/36 | -3 |
| `button_key_events` | output_mismatch | 0/14 | 2/14 | -2 |
| `tab_ordering_events_mouse` | output_mismatch | 3/65 | 5/65 | -2 |
| `button_key_events_special` | output_mismatch | 0/45 | 1/45 | -1 |
| `text_blocks_clicks` | output_mismatch | 0/4 | 1/4 | -1 |
| `focus_keyboard_press` | output_mismatch | 3/60 | 3/60 | 0 |
| `focus_mouse` | output_mismatch | 0/45 | 0/45 | 0 |
| `tab_ordering_events` | output_mismatch | 19/150 | 18/150 | +1 |
