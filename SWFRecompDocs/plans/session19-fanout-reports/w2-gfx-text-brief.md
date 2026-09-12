# w2-gfx-text: at-point probes, glyph offset-table order, auto_size border corner (G1-G3)

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-gfx-text-filters-report.md` items
G1, G2, G3. That report is your diagnosis of record; re-verify its claims. Worktree agent: nothing
commits, you deliver patches. **Deliver three patch files** (`w2-gfx-text-1-atpoint.patch`,
`-2-glyphorder.patch`, `-3-autosize.patch`) — G2 is a recompiler change and must land separately.

## Scope (+5 pixel flips, ~20 LOC total)
**G1 (+2, ~6 LOC, `avm2_text.c:8386` and `:8581`).** Both at-point probes omit the line's `leading`;
Ruffle's `find_line_index_by_y` uses `extent_y() + leading`. The model fits all four of t1's
boundaries exactly, including `leading='-10'`, and every differing pixel in both maps is a
horizontal band with no x error. The char probe also ignores `scrollV` — fix that too. Flips
`avm2/edittext_get_char_index_at_point` (22 849) and `avm2/edittext_get_line_index_at_point` (18 403).

**G2 (+1, ~4 LOC, `abc_timeline.cpp:1532`).** The glyph offset table is assumed monotonic
(`g1 <= g0 → continue`), so `[29,10,64,48]` drops 2 of 4 glyphs. Flips
`avm1/define_font_glyph_table_order` (180/4). A corpus scan found exactly 2 affected SWFs; the other
(`define_font_glyph_table_order_overlap`) passes today and is your REQUIRED A/B — it must still pass.
This is a recompiler edit, so rebuild the recompiler in your worktree and pass `--recompile` on
first use of each copied test dir.

**G3 (+2, medium).** `visual/text/auto_size/height` and `auto_size/return` are the EditText
**border bottom-right corner** at fractional extents (5 of 7 and 1 of 2 residual pixels), not glyphs.
`return` needs ONE pixel to pass. `visual/text/auto_size/width` passes at exactly its limit and is
your A/B — it must not move.

## Explicitly OUT of scope (priced and refuted by your own diagnosis agent — do not revisit)
- Device-font outline emission: prototyped, +110 net LOC, flips nothing (`leading_device_font`
  12 978 → 18 but max_outliers is 0; `device-font` count rises on a 1-bit tol-0 golden). It is a
  band/correctness arc.
- AVM2 `.filters` chain defects: move no graded comparison.
- `morph_test1`: a depth-order bug, 0 flips either way.
- The KF Shumway text rows: A-INHERENT (Ruffle is farther from Flash than we are) — disposition
  candidates, not fixes.

## Required checks
- Headlines both ways with `--mode=graphics --images`, and read the CI PNGs under
  `<scratchpad>/image-results/` for absolute verdicts rather than grading a local render.
- G1: the EditText/TextField families on both axes (`avm2/edittext*`, `avm2/textline*`,
  `avm2/textblock*`) — trace diffs ride along in every capture.
- G2: the font/glyph families (`visual/fonts/*`, `avm1/*font*`, `avm2/*font*`), plus the mandatory
  `_overlap` A/B. A recompiler change also warrants a spot-check that unrelated suites still
  recompile (pick a handful across avm1/avm2).
- G3: the `visual/text/*` family, with `auto_size/width` as the A/B.
- The **render canary** (`render_canary.py`) for all three, plus the `regression` suite.

Siblings and their files: **w2-bitmapdata** edits `avm2_bitmap.c` + `action.c` blend paths (a
blend-formula change the pixel axis also sees — if a canary row moves for both of you, say so);
**w2-loaders** edits `avm2_display.c` and `swf_core.c`. You are the only agent in `avm2_text.c` and
`abc_timeline.cpp`.
