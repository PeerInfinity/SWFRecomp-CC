# Ruffle Test Results Diff

**Previous:** `4c450f076e82` (2026-10-03T20:48:40.513653+00:00)
**Current:** `bdf127c35cca` (2026-10-17T00:59:01.854483+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 703 | 698 | -5 |
| Total | 743 | 744 | +1 |
| Pass rate | 94.6% | 93.8% | -0.8% |
| Mismatched lines | 12183 | 13718 | +1535 |
|   Decreased | | | -19 |
|   Increased | | | +1327 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `html_text_img_parsing_swf6` | output_mismatch | 85/102 | 517/517 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `as_broadcaster` | output_mismatch | 41/41 | 106/312 |
| `context_menu` | output_mismatch | 39/39 | 49/128 |
| `context_menu_item` | output_mismatch | 41/41 | 61/96 |
| `matrix` | output_mismatch | 171/171 | 57/810 |

## Added Tests (4)

| Test | Status | Lines |
|------|--------|-------|
| `as_setup_error` | output_mismatch | 11/52 |
| `context_menu_swf6` | output_mismatch | 11/14 |
| `edittext_html_duplicate_attributes` | output_mismatch | 176/247 |
| `html_text_img_parsing_swf8` | output_mismatch | 346/517 |

## Removed Tests (3)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `as_broadcaster_initialize` | pass | 10/10 |
| `as_broadcaster_undef` | pass | 89/89 |
| `html_text_img_parsing` | output_mismatch | 116/175 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `globals_monkeypatch` | output_mismatch | 39/246 | 41/246 | -2 |
| `array_constructor` | pass | 30/30 | 53/53 | 0 |
| `rectangle` | output_mismatch | 141/617 | 141/629 | +12 |
| `html_text_img_parsing_swf7` | output_mismatch | 116/175 | 346/517 | +112 |
| `html_text_img_parsing_swf5` | output_mismatch | 63/106 | 344/517 | +130 |
