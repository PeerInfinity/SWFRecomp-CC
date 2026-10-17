# Ruffle Test Results Diff

**Previous:** `8b69f982f7ab` (2026-10-11T08:51:58.482742+00:00)
**Current:** `9396522982a2` (2026-10-17T02:06:22.716170+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 701 | 707 | +6 |
| Total | 746 | 744 | -2 |
| Pass rate | 94.0% | 95.0% | +1.0% |
| Mismatched lines | 13514 | 12772 | -742 |
|   Decreased | | | -742 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_setup_error` | output_mismatch | 11/52 | 52/52 |
| `context_menu` | output_mismatch | 49/128 | 128/128 |
| `context_menu_item` | output_mismatch | 61/96 | 96/96 |
| `context_menu_swf6` | output_mismatch | 11/14 | 14/14 |
| `html_text_img_numeric_attributes` | output_mismatch | 1/3 | 3/3 |
| `html_text_img_parsing_swf5` | output_mismatch | 344/517 | 517/517 |
| `html_text_img_parsing_swf7` | output_mismatch | 346/517 | 517/517 |
| `html_text_img_parsing_swf8` | output_mismatch | 346/517 | 517/517 |

## Removed Tests (2)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `as_broadcaster_initialize` | pass | 10/10 |
| `as_broadcaster_undef` | pass | 89/89 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_html_duplicate_attributes` | output_mismatch | 176/247 | 241/247 | -65 |
| `globals_monkeypatch` | output_mismatch | 39/246 | 41/246 | -2 |
| `array_constructor` | pass | 30/30 | 53/53 | 0 |
| `as_broadcaster` | pass | 41/41 | 312/312 | 0 |
