# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:35:22.718740+00:00)
**Current:** `2d40d37996b8` (2026-11-27T06:45:05.539363+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1316 | 1274 | -42 |
| Total | 1352 | 1307 | -45 |
| Pass rate | 97.3% | 97.5% | +0.2% |
| Mismatched lines | 1435 | 1380 | -55 |
|   Decreased | | | -1 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `swz` | output_mismatch | 2/3 | 3/3 |

## Missing Tests — Shard Failure (45)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 43 were previously passing
- 2 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `edittext_getcharboundaries_missing_embedded_font` | pass | 7/7 |
| `edittext_getcharboundaries_missing_glyphs` | pass | 63/63 |
| `edittext_getcharboundaries_scroll` | pass | 85/85 |
| `edittext_getlinemetrics` | pass | 146/146 |
| `edittext_html` | pass | 3101/3101 |
| `edittext_html_condensewhite` | pass | 487/487 |
| `edittext_html_entity` | pass | 4/4 |
| `edittext_html_font_size_swf12` | pass | 267/267 |
| `edittext_html_font_size_swf13` | pass | 273/273 |
| `edittext_html_roundtrip` | pass | 17/17 |
| `edittext_ime_focus_lost` | pass | 9/9 |
| `edittext_input_control` | pass | 12/12 |
| `edittext_leading` | pass | 9/9 |
| `edittext_letter_spacing` | pass | 15/15 |
| `edittext_line_methods` | pass | 294/294 |
| `edittext_line_metrics` | pass | 11/11 |
| `edittext_margins` | pass | 25/25 |
| `edittext_max_scroll_h_basic` | pass | 475/475 |
| `edittext_max_scroll_v_basic` | pass | 1000/1000 |
| `edittext_mouse_selection` | pass | 363/363 |
| `edittext_mousedown` | pass | 3/3 |
| `edittext_mouseenabled` | pass | 26/26 |
| `edittext_newline_character` | pass | 22/22 |
| `edittext_newline_stripping` | pass | 64/64 |
| `edittext_newlines` | pass | 30/30 |
| `edittext_paragraph_methods` | pass | 257/257 |
| `edittext_paste_events` | pass | 8/8 |
| `edittext_paste_maxchars` | pass | 4/4 |
| `edittext_paste_restrict` | pass | 16/16 |
| `edittext_restrict` | pass | 191/191 |
| `edittext_restrict_events` | pass | 22/22 |
| `edittext_scroll_event` | pass | 37/37 |
| `edittext_scrollh` | pass | 10/10 |
| `edittext_selected_text` | pass | 9/9 |
| `edittext_set_html_same` | pass | 17/17 |
| `edittext_set_text_same` | pass | 115/115 |
| `edittext_set_text_same_after_edits` | ruffle_matched | 90/138 |
| `edittext_set_text_vs_html` | pass | 9/9 |
| `edittext_stylesheet` | pass | 536/536 |
| `edittext_stylesheet_custom_tag` | pass | 76/76 |
| `edittext_stylesheet_display` | pass | 272/272 |
| `edittext_tab_stops` | ruffle_matched | 54/60 |
| `edittext_tag_indent` | pass | 49/49 |
| `edittext_underline` | pass | 40/40 |
| `edittext_width_height` | pass | 103/103 |

</details>
