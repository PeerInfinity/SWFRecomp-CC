# Ruffle Test Results Diff

**Previous:** `7d19cf5299a5` (2026-03-06T18:24:27.933442+00:00)
**Current:** `ea1732c5c720` (2026-03-06T22:26:29.093400+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 480 | 488 | +8 |
| Total | 619 | 619 | 0 |
| Pass rate | 77.5% | 78.8% | +1.3% |
| Mismatched lines | 20054 | 20012 | -42 |
|   Decreased | | | -50 |
|   Increased | | | +8 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `duplicate_movie_clip_drawing` | output_mismatch | 1/2 | 2/2 |
| `edittext_focus_selection` | output_mismatch | 1/2 | 2/2 |
| `edittext_html_condensewhite_swf7` | output_mismatch | 308/311 | 311/311 |
| `edittext_html_condensewhite_swf8` | output_mismatch | 288/311 | 311/311 |
| `edittext_input_newlines` | output_mismatch | 4/9 | 9/9 |
| `edittext_place_caret` | output_mismatch | 1/2 | 2/2 |
| `edittext_tab_focus` | output_mismatch | 10/13 | 13/13 |
| `movieclip_default_state` | output_mismatch | 68/69 | 69/69 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `edittext_ime_focus_lost` | segfault | output_mismatch | - | 0/7 |
| `string_paths_timer` | segfault | output_mismatch | - | 0/0 |
| `timer_run_actions` | segfault | output_mismatch | 1/18 | 3/18 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `selection_handlers` | output_mismatch | 15/27 | 21/27 | -6 |
| `mcl_events_swf_version` | output_mismatch | 33/232 | 37/232 | -4 |
| `movieclip_library_state_values` | output_mismatch | 77/78 | 76/78 | +1 |
