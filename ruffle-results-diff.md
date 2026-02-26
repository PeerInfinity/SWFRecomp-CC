# Ruffle Test Results Diff

**Previous:** `ba59d4099326` (2026-02-26T02:57:35.075703+00:00)
**Current:** `3503b6f502f3` (2026-02-26T04:12:07.567450+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 367 | 370 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 59.3% | 59.8% | +0.5% |
| Mismatched lines | 32842 | 32230 | -612 |
|   Decreased | | | -624 |
|   Increased | | | +12 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `click_block` | output_mismatch | 0/5 | 5/5 |
| `mouse_events_visible_enabled` | output_mismatch | 3/12 | 12/12 |
| `mouse_pos` | output_mismatch | 291/665 | 665/665 |
| `mouse_pos_with_scale_factor` | output_mismatch | 111/260 | 260/260 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `button_properties_special_cases` | output_mismatch | 22/22 | 10/22 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `resolve_different_root` | output_mismatch | segfault | 0/2 | - |

## Line Count Changed (11)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `localconnection` | output_mismatch | 2/579 | 74/579 | -72 |
| `focus_mouse` | output_mismatch | 10/45 | 14/45 | -4 |
| `string_paths_eval` | output_mismatch | 0/4 | 3/4 | -3 |
| `movieclip_invalid_get_bounds_1` | output_mismatch | 2/75 | 4/75 | -2 |
| `movieclip_invalid_get_bounds_2` | output_mismatch | 3/75 | 5/75 | -2 |
| `text_blocks_clicks` | output_mismatch | 1/4 | 3/4 | -2 |
| `focus_mouse_rollout` | output_mismatch | 0/4 | 0/4 | 0 |
| `movieclip_invalid_get_bounds_3` | output_mismatch | 2/13 | 2/13 | 0 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | 2/13 | 2/13 | 0 |
| `netconnection_send_remote` | output_mismatch | 1/50 | 1/50 | 0 |
| `tab_ordering_events_mouse` | output_mismatch | 5/65 | 5/65 | 0 |
