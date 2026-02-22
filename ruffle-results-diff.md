# Ruffle Test Results Diff

**Previous:** `7b56f94b8a75` (2026-02-22T00:23:17.600104+00:00)
**Current:** `a61990a30d3f` (2026-02-22T02:42:13.840627+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 269 | 275 | +6 |
| Total | 619 | 619 | 0 |
| Pass rate | 43.5% | 44.4% | +0.9% |
| Mismatched lines | 38998 | 36823 | -2175 |
|   Decreased | | | -2175 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_html_entity` | output_mismatch | 3/4 | 4/4 |
| `issue_3522` | output_mismatch | 1/2 | 2/2 |
| `issue_9327` | output_mismatch | 0/2 | 2/2 |
| `root_onload` | output_mismatch | 0/1 | 1/1 |
| `sandbox_type_local_network` | output_mismatch | 0/1 | 1/1 |
| `target_path` | output_mismatch | 11/14 | 14/14 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_library_state_values` | output_mismatch | runtime_error | 15/78 | 16/78 |

## Line Count Changed (13)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_html_swf8` | output_mismatch | 2247/5377 | 3204/5377 | -957 |
| `edittext_html_swf7` | output_mismatch | 2262/5377 | 3042/5377 | -780 |
| `edittext_html_swf6` | output_mismatch | 2718/5377 | 3114/5377 | -396 |
| `edittext_html_condensewhite_swf7` | output_mismatch | 145/311 | 163/311 | -18 |
| `edittext_html_condensewhite_swf8` | output_mismatch | 142/311 | 152/311 | -10 |
| `localconnection` | output_mismatch | 0/579 | 2/579 | -2 |
| `netconnection_send_remote` | output_mismatch | 0/50 | 1/50 | -1 |
| `sandbox_type_remote` | output_mismatch | 0/3 | 1/3 | -1 |
| `button_order` | output_mismatch | 0/2 | 0/2 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `mouse_pos` | output_mismatch | 0/665 | 0/665 | 0 |
| `mouse_pos_with_scale_factor` | output_mismatch | 0/260 | 0/260 | 0 |
| `textfield_cache_as_bitmap` | output_mismatch | 0/1 | 0/1 | 0 |
