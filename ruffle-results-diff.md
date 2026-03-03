# Ruffle Test Results Diff

**Previous:** `8dfb5c276a7e` (2026-03-02T22:04:13.820153+00:00)
**Current:** `b2e7ee8d460f` (2026-03-03T00:14:59.302242+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 426 | 431 | +5 |
| Total | 619 | 619 | 0 |
| Pass rate | 68.8% | 69.6% | +0.8% |
| Mismatched lines | 23326 | 23343 | +17 |
|   Decreased | | | -37 |
|   Increased | | | +54 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `button_keypress_vs_textinput` | output_mismatch | 3/4 | 4/4 |
| `edittext_input` | output_mismatch | 0/1 | 1/1 |
| `focus_mouse` | output_mismatch | 20/45 | 45/45 |
| `frame_size_translated_negative` | output_mismatch | 20/21 | 21/21 |
| `frame_size_translated_positive` | output_mismatch | 20/21 | 21/21 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | compile_fail | output_mismatch | - | 286/338 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_input_newlines` | output_mismatch | 0/9 | 4/9 | -4 |
| `focus_mouse_rollout` | output_mismatch | 0/4 | 3/4 | -3 |
| `input_dead_keys_windows` | output_mismatch | 5/15 | 6/15 | -1 |
| `edittext_restrict` | output_mismatch | 147/191 | 145/191 | +2 |
