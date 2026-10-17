# Ruffle Test Results Diff

**Previous:** `bdf127c35cca` (2026-10-17T00:59:01.879549+00:00)
**Current:** `9396522982a2` (2026-10-17T01:43:11.346667+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1228 | 1233 | +5 |
| Total | 1291 | 1292 | +1 |
| Pass rate | 95.1% | 95.4% | +0.3% |
| Mismatched lines | 2851 | 2530 | -321 |
|   Decreased | | | -337 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `external_interface` | output_mismatch | 3/105 | 105/105 |
| `mouse_pick_loader_avm1` | output_mismatch | 16/42 | 42/42 |
| `mouse_pick_scroll_rect` | output_mismatch | 3/27 | 27/27 |
| `mouse_pick_scroll_rect_button` | output_mismatch | 3/5 | 5/5 |
| `mouse_pick_scroll_rect_loader` | output_mismatch | 1/5 | 5/5 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `html_text_img_parsing` | output_mismatch | ruffle_matched | 338/600 | 505/600 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `dictionary_qname_keys` | output_mismatch | 29/45 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `focus_events_mixed_avm_edittext` | output_mismatch | 0/49 | 12/49 | -12 |
