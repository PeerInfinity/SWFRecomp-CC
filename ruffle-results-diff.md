# Ruffle Test Results Diff

**Previous:** `291ec494a7b9` (2026-02-28T00:46:49.821377+00:00)
**Current:** `5e876a36fdb8` (2026-02-28T02:14:59.106804+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 398 | 393 | -5 |
| Total | 619 | 619 | 0 |
| Pass rate | 64.3% | 63.5% | -0.8% |
| Mismatched lines | 31497 | 31420 | -77 |
|   Decreased | | | -121 |
|   Increased | | | +44 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `click_block` | output_mismatch | 5/5 | 1/5 |
| `movieclip_depth_methods` | output_mismatch | 98/98 | 86/98 |
| `remove_movie_clip` | output_mismatch | 29/29 | 22/29 |
| `transform` | output_mismatch | 70/70 | 66/70 |
| `with` | output_mismatch | 49/49 | 48/49 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_and_init_order` | output_mismatch | 31/231 | 127/231 | -96 |
| `movieclip_hittest_shapeflag` | output_mismatch | 266/338 | 278/338 | -12 |
| `file_reference_browse_cancel` | output_mismatch | 0/21 | 10/21 | -10 |
| `do_init_action_child` | output_mismatch | 3/12 | 6/12 | -3 |
| `focus_mouse_rollout` | output_mismatch | 0/4 | 0/4 | 0 |
| `unload` | output_mismatch | 36/52 | 32/52 | +4 |
| `focus_mouse` | output_mismatch | 20/45 | 8/45 | +12 |
