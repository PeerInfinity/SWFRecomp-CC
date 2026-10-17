# Ruffle Test Results Diff

**Previous:** `4c450f076e82` (2026-10-03T20:48:40.536165+00:00)
**Current:** `bdf127c35cca` (2026-10-17T00:59:01.879549+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1222 | 1228 | +6 |
| Total | 1284 | 1291 | +7 |
| Pass rate | 95.2% | 95.1% | -0.1% |
| Mismatched lines | 2701 | 2851 | +150 |
|   Decreased | | | -105 |
|   Increased | | | +205 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `goto_queued_invalid/swf10` | output_mismatch | 2/34 | 34/34 |
| `goto_queued_invalid/swf11` | output_mismatch | 2/43 | 43/43 |
| `goto_queued_invalid/swf9` | output_mismatch | 2/32 | 32/32 |

## Added Tests (7)

| Test | Status | Lines |
|------|--------|-------|
| `collator_compare_basic` | pass | 93/93 |
| `collator_flags` | pass | 111/111 |
| `collator_locale_ids_windows` | pass | 120/120 |
| `mouse_pick_scroll_rect` | output_mismatch | 3/27 |
| `mouse_pick_scroll_rect_button` | output_mismatch | 3/5 |
| `mouse_pick_scroll_rect_loader` | output_mismatch | 1/5 |
| `textline_metrics` | output_mismatch | 0/20 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `textblock_recreateline` | ruffle_matched | 42/180 | 42/178 | -2 |
| `html_text_img_parsing` | output_mismatch | 118/175 | 338/600 | +205 |
