# w1-gfx-text — wave 1 diagnosis: pixel failures in the text family (EditText / fonts / device fonts / acid-text)

Read `BRIEFS_COMMON.md` first. Read-only: no source edits. Deliverable:
`SWFRecompDocs/plans/session18-fanout-reports/w1-gfx-text-report.md`. Scratch dir: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-gfx-text/`.

Board: `wave0-image-board.md` + `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/image_triage.json` (PNG paths under
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/image-results/`). Method: `graphics-fanout-playbook.md` §2–§7, §16. Prior text
diagnosis of record: `session17-fanout-reports/w2-gfx-edittext-bg-report.md` (per-depth
interleave, background/border), s16 `w2-gfx-*text*` reports, memory notes in
`SWFRecompDocs/status/child-static-text-and-morphs.md` (text tables, 2026-09-04).

## Your comparisons (grouped by suspected mechanism — verify)
**Structural (a flip is plausible):**
- `visual/edittext/edittext_bounds_vs_position` 519 (50x50, missing_element) — §16: sprite-nested `DefineEditText` reaches neither pass; parent-scoped window in `render_display_list`'s sprite walk (+1)
- `fonts/device_font_kerning` 1680 (100x50, missing_element)
- `visual/fonts/font_lookup_as3` 34632 (missing_element, max_out 72)
- `visual/cache_as_bitmap/edittext_scroll` 566/570 (70x20, content_displaced, max_out 5) and `edittext_hscroll` 96 / 960 (40x24)
- `text/br_at_start` 3691 (max_out 8), `text/style_changes_in_html` 25102 (max_diff 103)
- `visual/edittext/edittext_gutter` 1032, `visual/edittext/edittext_underline` 1974, `edittext_underline_scale2` 27672 (max_out 16)
- `visual/cache_as_bitmap/edittext_selection` 366/373/6783 (100x50, max_out 8)
- `avm2/edittext_always_show_selection` 432 (max_diff 43), `avm2/edittext_get_line_index_at_point` 18403, `edittext_get_char_index_at_point` 22849 — shared with w1-gfx-fill (they own the fill-colour reading; you own the text-layout reading — report both views)
- `visual/edittext/edittext_border_filters` 827 (max_out 17) — w1-gfx-filters owns the filter half
**Near-passes (a_epsilon, glyph-raster drift; §16 says device fonts have NO outline source — `abc_devicefont.cpp` emits metrics only — an ARC; confirm which of these are embedded vs device fonts):**
- `visual/fonts/duplicate_font` 3, `avm1/edittext_stylesheet` 6, `from_shumway/acid/acid-text-x` 6, `visual/fonts/glyph` 6, `fonts/embed_matching/match_style` 12, `text/auto_size/height` 15 (max_out 3), `text/auto_size/return` 36 (max_out 18), `visual/edittext/edittext_border_transform` 44/51 (max_out 20), `edittext_device_transform_small_shear` 88 (max_out 50), `visual/simple_shapes/text_field_mask` 56, `fonts/embed_matching/fallback_preferences` 156, `from_shumway/acid/acid-text-escape` 184, `acid-text-6` 12 (frame5) / 198
**Device-font family (blank/missing glyphs):** `visual/fonts/device-font` 8205 (max_out 3), `visual/definefont4` 16086, `visual/fonts/leading_device_font` 12978, `visual/edittext/edittext_device_transform_negative` 2649 (max_out 30)
**known_failure (Ruffle fails too; price only):** `from_shumway/flash_text_TextField` 966, `stylesheet` 2089, `hardwrap` 3099, `captions` 6867, `acid-text-4` 51672, `acid-text-5` 422232, `acid-textfield` 15754

Trace context: `fonts/embed_name_lookup` (trace 86/242, new 2026-08-21) is w1-trace-new's, but
its mechanism (font name lookup) may be the same as `font_lookup_as3`'s pixel gap — read their
report if it lands first, or note the overlap.

## Method
Open expected/actual/diff PNGs; for each, say WHICH glyphs/elements differ and whether it is
layout (position/advance/leading/wrap), raster (outline vs device font), colour, or clipping.
Cluster by mechanism, price flips (outliers <= max_out), check the text entries in the
playbook's image-axis dispositions, verdict GO/HOLD/NO-GO with files (`ng_shared.c`, `tag.c`,
edittext layout/render code, `abc_devicefont.cpp`, `render_webgpu.c` glyph path) + LOC +
canaries (`render_canary_tests.txt` text members). Local renders: one test at a time,
`--mode=graphics --images --image-out-dir`; A/B only. Attack the brief. Siblings: w1-gfx-fill,
w1-gfx-filters, w1-gfx-smalls.
