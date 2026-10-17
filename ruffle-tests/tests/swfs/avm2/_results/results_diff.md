# Ruffle Test Results Diff

**Previous:** `8b69f982f7ab` (2026-10-11T08:51:58.495545+00:00)
**Current:** `9396522982a2` (2026-10-17T02:06:22.740039+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1222 | 1233 | +11 |
| Total | 1288 | 1292 | +4 |
| Pass rate | 94.9% | 95.4% | +0.5% |
| Mismatched lines | 3246 | 2530 | -716 |
|   Decreased | | | -732 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `collator_compare_basic` | output_mismatch | 1/93 | 93/93 |
| `collator_flags` | output_mismatch | 1/111 | 111/111 |
| `collator_locale_ids_windows` | output_mismatch | 0/120 | 120/120 |
| `external_interface` | output_mismatch | 3/105 | 105/105 |
| `goto_queued_invalid/swf10` | output_mismatch | 2/34 | 34/34 |
| `goto_queued_invalid/swf11` | output_mismatch | 2/43 | 43/43 |
| `goto_queued_invalid/swf9` | output_mismatch | 2/32 | 32/32 |
| `mouse_pick_loader_avm1` | output_mismatch | 16/42 | 42/42 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `html_text_img_parsing` | output_mismatch | ruffle_matched | 338/600 | 505/600 |

## Added Tests (4)

| Test | Status | Lines |
|------|--------|-------|
| `dictionary_qname_keys` | output_mismatch | 29/45 |
| `mouse_pick_scroll_rect` | pass | 27/27 |
| `mouse_pick_scroll_rect_button` | pass | 5/5 |
| `mouse_pick_scroll_rect_loader` | pass | 5/5 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `focus_events_mixed_avm_edittext` | output_mismatch | 0/49 | 12/49 | -12 |
