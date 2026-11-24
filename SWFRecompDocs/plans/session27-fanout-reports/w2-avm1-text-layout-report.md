# s27 w2-avm1-text-layout: AVM1 EditText layout in the native painter (soft wrap, then scale/rotation)

**New files**
- `session27-fanout-reports/w2-avm1-text-layout-report.md` (this report)
- `session27-fanout-reports/w2-avm1-text-layout.patch` (`git diff --binary origin/master -- SWFRecomp SWFModernRuntime
  ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <2 fixture dirs>`; `git apply --check -R` verified)
- `ruffle-tests/tests/swfs/regression/avm1_edittext_scaled_glyphs/` (`create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt` (empty), `output.expected.png` = **FLASH** capture)
- `ruffle-tests/tests/swfs/regression/avm1_edittext_wordwrap_render/` (`create_test_swf.py` with the **rebuilt
  font**, `test.swf`, `test.toml`, `output.txt` + `output.expected.png` = Ruffle exporter, INTERIM)
- `session27-fanout-reports/w2-avm1-text-layout-fixtures/avm1_edittext_rotated_glyphs/` (HELD: generator, `test.swf`,
  `test.toml`, `output.txt`, `ours-before.png`, `ours-after.png`). Its generator resolves `../avm1_edittext_placed_cxform`,
  so it runs only once landed in `regression/`.

**Setup.** Branch `fanout/w2-avm1-text-layout` from `origin/master` `53540ff0`. Dawn/apt OK (lavapipe). Corpus:
`download_tests.sh avm1 text visual from_gnash from_shumway fonts avm2` (upstream master, 2026-11-24). Ruffle source:
blobless clone at `1e604fa87`. Baseline: wave-0 HAS published (`origin/ruffle-test-results` = `a0e485e5`, two graphics
commits after `df7729df2`); my before leg is clean `origin/master` on this box either way.
**Fidelity:** my clean-master renders of `Video-EmbedSquareTest`, `shape_test` and `BeginBitmapFill` are byte-identical
to CI's actual PNGs on `origin/ruffle-image-results` (`fb80304c`, `a5cb2877`, `642e53c8`), so local grading is CI-grade.

## Verdicts

| # | item | verdict | flips |
|---|---|---|---|
| 1 | Soft wrap (land `w1-text-wordwrap-prototype.patch`) | **LANDED** as-is (comment labels only). Corpus: 0 movement (all 11 AVM1 wordWrap rows md5-identical) | +1 fixture fail → pass |
| 1b | "Its fixture is Flash-invalid" | **ROOT-CAUSED and REBUILT.** The w1 font's CodeTable was `'A', ' ', '-'` (65, 32, 45), **not ascending**. Flash binary-searches the code table, so `'A'` is never found (mid = 32 < 65, then 45 < 65) while `' '` and `'-'` are: no glyph drawn AND zero advance for every `A`, which is exactly the Flash capture (nothing drawn, one line per field; `h` 2 lines from its hard `\r`). Ruffle and we look codes up by map, so both drew it. Also fixed: the square was filled with FillStyle0 on a clockwise contour (the OUTSIDE side; Flash glyphs use FillStyle1), and LanguageCode 0 → 1 (as the Flash-valid `scaled_glyphs` font). | — |
| 2 | AVM1 EditText glyphs ignore scale/rotation | **GO, implemented.** Glyphs, mask, selection and caret now go through the field's world matrix with Ruffle's three-step whole-twip compose; device fields get `device_font_scale_x` and the rotate/shear cull. Fixture vs **FLASH golden: 20 907 → 9 channels** (the 3 bottom-right border corners), PASS | +1 fixture fail → pass |
| 2b | (found) the embedded-font **box** of a scaled field is not pixel-snapped | **GO, implemented** (Ruffle `EditTextPixelSnapping`, axis-aligned non-unit scale only). Without it the 0.5× box's bottom border straddled rows 37/38 at half coverage, 70 px off Flash. | part of the fixture flip |
| 3 | Sweep | 49 argued rows + full canary (153) = 180 tests / 258 PNGs: **255 md5-identical**; only the 3 new fixtures move; 0 trace-status changes | — |

**No graded corpus row moves on either axis** (as both w1 reports priced: no corpus AVM1 row has a scaled EditText
with drawn glyphs, and no AVM1 wordWrap row breaks visibly). The yield is correctness for games (zoomed / tweened HUD
text, dialogue boxes) plus two new Flash-anchored regression rows.

## Mechanism and patch scope

All edits are self-localized: trailing struct fields, new `static` helpers, guarded hooks. Every new path is gated on
`has_matrix` (a non-identity linear part) or `sb_n > 0` (a soft break exists), so identity / unwrapped fields execute the
old expressions verbatim (confirmed: 255/255 md5-identical).

**`action.h`** `TextFieldGlyphInfo`: trailing `word_wrap` (w1) and `has_matrix`, `device_xform`, `m_a..m_d`, `m_tx/m_ty`.

**`action.c`** (functions touched, for the N ladder and `w2-draw-cx-text`; nothing in `rasterizeMovieClipToBitmap`):
- new static `tf_glyph_set_matrix`: fills the matrix fields. Device field (`embedFonts` false / no UseOutlines) under a
  non-positive-scale-only transform → return 0, the producer skips the glyph callback (Ruffle `render_self` ~2720, the
  box iterator's existing `tf_transform_positive_scale_only` cull). Identity linear part → `has_matrix = 0`, nothing
  else changes. Otherwise x/y become field-local (the visual offset) and m_* the world matrix.
- `actionIterateTextFieldGlyphs`: `word_wrap` (w1) + `tf_world_matrix` → `tf_glyph_set_matrix` (same matrix the box uses).
- Orphan walk: new statics `g_otf_parent_m`, `g_otf_field_m`, `otf_compose_entry_m` (matrix compose with the
  `tf_world_matrix` rounding); `otf_walk_dl` carries the full world matrix through sprite recursion (save/restore,
  like the cx); `otf_emit_textfield` (`word_wrap` from flag 0x0001, w1) calls `tf_glyph_set_matrix`;
  `actionIterateOrphanTextFields` resets it; `actionEmitOrphanRootTextField` sets the root entry's matrix.

**`tag.c`**:
- `textfield_glyph_render_cb`: w1 soft wrap (new statics `tf_ww_sum`, `tf_ww_wrap_line`, `tf_soft_wrap_breaks`;
  `TfParagraph` gains `cont`/`soft_end`/`trail_w`; Flash whole-line culling for soft-wrapped fields). Matrix mode:
  - mask = `W * bounds` (local twips) through a written slot (new static `tf_glyph_xform_slot`);
  - device text: `sx = d/a`, layout width = local width / sx (Ruffle `local_width_to_layout_width`), layout matrix gains
    `scale(sx, 1)`;
  - glyph = `M2 * T(line origin) * G{a=d=height/em, tx=pen, ty=ascent}` with `M2 = W * T(L) * S(sx,1)`, L = bounds min +
    GUTTER − scroll; each of the three pushes rounds its translation with `rintf` (f32 ties-even), the
    `tag_text_glyph_compose` / Ruffle `Matrix * Matrix` rule. Composed on the CPU into stage twips on slot 0 (the same
    space the identity path draws in);
  - selection box and caret through a lazily written slot holding `M2`, relative to L (caret unsnapped under a matrix,
    1 device px wide).
- `textfield_render_cb` (box): new top block, Ruffle `EditTextPixelSnapping` (HIGH-quality arm) for an embedded-font box
  under an axis-aligned positive non-unit scale: `tx/ty = trunc_to_pixel(t + 2 twips)`, `w/h = round_ties_even(s − 0.35)`
  px, then drawn as an identity box. Rotated/sheared boxes keep `tf_border_skewed_line_rect`; device boxes keep
  `draw_device_text_box`; unit-scale boxes are untouched. Approximation: the LOW-quality arm (snap tx/ty only) is not
  modelled; the runtime has no stage-quality read in `tag.c`.

**Not done / approximations** (each with completion mechanism):
- Orphan-walk matrix arm is **compiled and identity-safe but not exercised**: every timeline field I ran gets an MC
  wrapper (instrumented: the scaled fixture and `avm1_edittext_placed_cxform` both take `actionIterateTextFieldGlyphs`).
  Completion: a fixture whose scaled field is provably wrapper-less (e.g. inside a button's up state, the Snake case in
  `otf_walk_dl`'s comment), graded against Flash.
- Lbox origin is per LINE (our paragraph record), Ruffle's per format span; identical for single-run lines. Multi-run
  scaled lines can differ by one twip rounding per span boundary. Completion: split `ox/gx` at run boundaries.
- Device-font glyphs are mostly the metrics-only builtin font (`ng_font_is_builtin` → not drawn), so `device_font_scale_x`
  is reachable only with a synthesized `_sans` outline set; no fixture. The rotate/shear cull IS reachable and matches
  the box (both `edittext_device_transform_small_*` rows md5-identical: their shear/rotation passes the 0.006 tolerance).

## Per-test before/after (same box; before = clean `origin/master`, after = this patch; `--mode=graphics`)

Headline rows:

| row | before | after |
|---|---|---|
| **regression/avm1_edittext_scaled_glyphs** (FLASH golden) | trace pass; image **FAIL 20 907** > 0, max 255 (glyphs at scale 1; 0.5× box border straddling) | trace pass; image **PASS 9/9**, max 49 (3 BR corners: Flash 15/111/111, ours 64) |
| **regression/avm1_edittext_wordwrap_render** (rebuilt font; interim Ruffle golden) | trace pass (metrics already wrapped); image **FAIL 3 831** (1 clipped line per paragraph) | trace pass; image **PASS 45/45**, max 64 (the 15 exporter TL/TR/BL corners, measured identically by w1) |
| held `avm1_edittext_rotated_glyphs` (90°, 30°, shear 0.5) | glyphs upright, unscaled (`ours-before.png`) | glyphs rotate/shear inside their boxes (`ours-after.png`); golden = LOCAL ORACLE REQUEST |

Sweep (every AVM1 EditText / createTextField image row in avm1, text, visual, fonts, from_gnash, from_shumway, regression,
incl. the 11 AVM1 wordWrap rows; plus trace rows). **All md5-identical, status-identical:**

| row | before = after (status, outliers) | PNG md5 |
|---|---|---|
| avm1/movieclip_create_text_field | pass 0 | `efdb1636` |
| avm1/edittext_stylesheet | pass 0 | `87a4467f` |
| avm1/frame_size_translated_negative / _positive | pass 1 / pass 1 | `92b139c4` / `421b5ddc` |
| avm1/edittext_tag_indent | pass 0 | `0779fdf4` |
| text/style_changes_in_html / br_at_start | pass 0 / pass 4 | `8b0209bc` / `361de04c` |
| visual/edittext/edittext_negative_bounds | pass 0 | `08c5d2f9` |
| visual/edittext/edittext_{background,border}_basic{,_scale2} | pass 0 ×4 | `37f459ec` `d029bd22` `a9697d0a` `97d1d0f9` |
| visual/edittext/edittext_bounds_vs_position | pass 0 | `8a69c176` |
| visual/edittext/edittext_border_transform (6 cmps) | pass 0/0/0/16/0/15 | 6/6 identical |
| visual/edittext/edittext_device_transform_small_rotation / _small_shear | pass 11 / pass 49 | `e61a9bfa` / `8498285f` |
| visual/edittext/edittext_border_filters | pass 0 | `f664b02e` |
| visual/edittext/edittext_caret_empty (12 cmps) | pass 0 ×12 | 12/12 identical |
| visual/text/String_path_variable_button | pass 3 | `d0a79328` |
| visual/simple_shapes/text_field_mask | pass 0 | `576b9320` |
| visual/filters/{bevel, bevel_inner, bevel_outer, bevel_full, glow, glow_with_alpha_strength, glow_without_composite_source, drop_shadow} | pass 6/18/18/18/0/18/0/0 | 8/8 identical |
| visual/cache_as_bitmap/{text, edittext_selection, edittext_scroll, edittext_hscroll} | pass 1257 / 0,0,0 / 0,0 / 0,0 | all identical |
| visual/fonts/advance_u16 / leading_define_font | pass 0 / pass 0 | `adcbac1b` / `70f1aeb6` |
| visual/focus_highlight/focus_highlight_render (6 cmps) | pass (0,0,0,0,51,0) | 6/6 identical |
| from_gnash/misc-ming.all/Video-EmbedSquareTest | fail 1782 | `fb80304c` (= CI) |
| from_gnash/misc-ming.all/{shape_test, place_object_test, BeginBitmapFill} | fail 15994 / fail 38238 (trace ruffle_matched) / fail 939 | identical (= CI for 2) |
| from_gnash/misc-ming.all/morph_test1 (6 cmps) | pass 0 ×6 | 6/6 identical |
| from_shumway/avm1/text-bind | pass 587 | `a34b4609` |
| regression/avm1_{long_text_layout, edittext_placed_cxform, set_new_text_format_render, parent_child_text, definetext_matrix} | pass 0 / 19 / 0 / 0 / 0 | all identical (last two: separate 2-test capture) |
| trace: regression/avm1_wrap_giveup_mixed_runs, avm1/edittext_scroll, avm1/edittext_margins | pass | — |

- **Render canary** (`render_canary.py capture/compare`, all 153 members ∪ the 27 sweep rows above = 180 tests, 258 PNGs,
  `-P 2`): **IDENTICAL 255, DIFFERS 3** (`avm1_edittext_scaled_glyphs`, `avm1_edittext_wordwrap_render`, the scratch rotated
  fixture), **TRACE STATUS CHANGES: none.** Two covering members appended at EOF of `render_canary_tests.txt`
  (`regression/avm1_edittext_scaled_glyphs`, `regression/avm1_edittext_wordwrap_render`): the standing set could not
  see either change class.
- **Regression suite:** every `regression/` image row with text (8) above; all trace-only regression text rows are
  unaffected by construction (the producers and the painter run only under `HEADLESS_RENDER_ENABLED`).
- **No-graphics** (`action.c` is shared): `avm1/edittext_scroll`, `avm1/edittext_margins`,
  `regression/avm1_edittext_wordwrap_render` PASS without `--mode`. No `NO_GRAPHICS` arm touched.
- **Trace rows reading `textHeight`/`numLines`/`bottomScroll`/`maxscroll`:** the metric code (`ng_shared.c`) is
  untouched, and the 180-test capture shows 0 trace-status changes (incl. `edittext_scroll`, `text-bind`,
  `edittext_tag_indent`, the wordwrap fixture).

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

| axis | test | expected |
|---|---|---|
| pixel | `regression/avm1_edittext_scaled_glyphs` | NEW row, **pass** (9/9, max 49) |
| pixel | `regression/avm1_edittext_wordwrap_render` | NEW row, **pass** (45/45, max 64) |
| trace | `regression/avm1_edittext_scaled_glyphs` | NEW row, pass (empty output) |
| trace | `regression/avm1_edittext_wordwrap_render` | NEW row, pass (5 lines; Ruffle exporter = ours) |
| both | every other row | **no movement** (255/255 md5 locally, CI-fidelity proven) |

Run mode: runtime-only change, no recompiler change; `graphics` + `categories=all` covers it. The no-graphics leg is
not needed per CLAUDE.md (no no-graphics-only code), but both new rows also pass there.

## Refutations / premise attacks

- **"Rebuild the fixture's font so that Flash renders it" — the cause is the code table order, not glyph geometry.**
  The diff against `scaled_glyphs`' generator found three differences (code order, fill side, language); only the
  unsorted code table explains BOTH Flash symptoms (no glyphs AND no wrap: a fill-side defect would still advance and
  wrap). Fill side and language were aligned anyway so the fixture is Flash-shaped on every axis; the next Flash capture
  is the proof (LOCAL ORACLE REQUEST 1). Predicted Flash result: `w/c` 2 lines, `i` 3, `l` 2, `h` 3, i.e. exactly
  `output.txt`, since layout metrics (advance 512, ascent 900, descent 200) are unchanged.
- **"Ship the code change regardless … the metrics side already wraps"**: confirmed; with the rebuilt font the metric
  trace already passes on master (before leg), and only the render moves.
- **"Then apply the three-step rounding"**: applied inside the same compose (no separate step needed); the fixture
  matches Flash at 0 px on every glyph edge, including the 1.5× x-scale field where single-step float compose would put
  stems at half-twips.
- **Box snapping was not in the brief** but is required by the Flash golden (70 px otherwise): the scaled fixture's
  boxes were already scaled before this patch (the box iterator has had the matrix since s20), only unsnapped.

## New unclaimed leads

1. **AVM2 twin of the scaled-box pixel snap**: `avm2_display.c avm2_render_textbox` draws scaled embedded boxes unsnapped
   too (code-read; same `draw_text_box` rule). XS; needs an AS3 twin of `avm1_edittext_scaled_glyphs`.
2. **Stage quality LOW arm** of `EditTextPixelSnapping` (tx/ty only, no scale snap) for both box painters; needs a
   stage-quality read in `tag.c`. XS once the quality is plumbed.
3. **Flash whole-line culling for ALL multi-line AVM1 fields** (w1 phase 2) remains open; this patch keeps it on
   soft-wrapped fields only.
4. **Scaled caret pixel snapping**: Ruffle snaps the caret matrix after the transform (`EditTextPixelSnapping.apply`);
   ours is unsnapped under a matrix. Browser-only in practice (focused input fields).

## LOCAL ORACLE REQUESTS

1. **FLASH: `regression/avm1_edittext_wordwrap_render`** (rebuilt font), trace (`run_trace.py --wrapped`, 1 frame) +
   image (`run_image.py`, 1 frame). Compare the trace with `output.txt` (expected identical) and replace
   `output.expected.png` with the Flash PNG (budget its border corners like `avm1_edittext_scaled_glyphs`). If Flash still
   draws nothing, the code-table hypothesis is refuted; report it and the fixture stays on the Ruffle golden.
2. **FLASH: `session27-fanout-reports/w2-avm1-text-layout-fixtures/avm1_edittext_rotated_glyphs/test.swf`**, image, 1
   frame (`--screen` not needed; no blend modes). It becomes `regression/avm1_edittext_rotated_glyphs` with that golden
   (corner budget measured on landing). Compare with `ours-after.png`.
