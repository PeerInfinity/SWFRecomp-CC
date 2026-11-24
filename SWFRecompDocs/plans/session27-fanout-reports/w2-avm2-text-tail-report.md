# s27 wave 2: `w2-avm2-text-tail` report

**New files**
- `SWFRecompDocs/plans/session27-fanout-reports/w2-avm2-text-tail-report.md` (this report)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-avm2-text-tail.patch`: `git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/regression/avm2_definetext_matrix`. Checked with `git apply --check -R` on the branch tip.
- **Landed fixture** `ruffle-tests/tests/swfs/regression/avm2_definetext_matrix/` (`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`, `output.expected.png`). This is the w1 fixture as delivered; I only added docstring and toml provenance notes. Its generator reads `../avm1_definetext_matrix`, which is already on master.
- `SWFRecompDocs/plans/session27-fanout-reports/w2-avm2-text-tail-fixtures/avm2_edittext_selection_cxform/` (`Test.as`, `TestFont.ttf`, `build_swf.sh`, `test.toml`, `output.txt`). This is a **Flash oracle request**, not a landed fixture: it has no SWF and no golden yet (item 3).
- `SWFRecompDocs/plans/session27-fanout-reports/w2-avm2-text-tail-fixtures/definefont4_glyph_check/` (`cff4_render.py`, `ours_top_vs_golden_bottom.png`). This is the evidence for item 2.

**Box.** Cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Base is `origin/master` = `53540ff0`. Upstream corpus is Ruffle master `1e604fa87`, downloaded the same minute as my blobless clone (`avm2 visual from_shumway text fonts timeline swf mixed_avm`). The baseline is **wave-0's published results `da51f878`** (newer than `df7729df2`); I read it from `origin/ruffle-test-results`. **Fidelity:** my clean-master renders of `visual/definefont4` (8edbd5a1), `visual/fonts/font_lookup_as3` (04874d9f) and `from_shumway/acid/acid-textfield` (7da090c3) are byte-identical to CI's actual PNGs on `origin/ruffle-image-results`. Local grading is therefore CI-grade for these rows.

## Verdicts (lead)

| # | item | verdict | flips | price |
|---|---|---|---|---|
| 1 | AVM2 DefineText TextMatrix linear part | **GO, LANDED** | **+1 fixture `regression/avm2_definetext_matrix` fail → pass (pixel axis, 0 px, max 0)**. 0 corpus rows on either axis, by construction and by measurement (29-row A/B) | S (recompiler 1 fn + emitter; runtime 2 fns + 1 struct tail) |
| 2 | `definefont4` glyph half | **GO, LANDED (data only)**: DefineFont4 CFF outlines are decoded and emitted (40 glyphs for Exo 2) and hang off a trailing `Avm2Cff4FontData.outlines`. Nothing reads them yet. TextLine draw stays **NO-GO / arc**; measured plan in §2 | 0 rows (the md5 of `definefont4` = CI 8edbd5a1; all 8 DefineFont4 SWFs status-identical) | done: S. Remaining arc: M–L (§2c) |
| 3 | AVM2 selection rect tint | **HOLD (needs Flash)**. Ruffle source confirms it: the rect is untinted and selected glyphs get IDENTITY cx under the stack. I wrote an AS3 fixture for the FLASH capture; **no code change** | 0 corpus rows (no corpus row tints a selected field) | the change itself is XS (§3) |
| 4 | re-check `definefont4`, `font_lookup_as3` | **md5 = CI** on both: 8edbd5a1 and 04874d9f, before and after | — | — |

## 1. AVM2 DefineText TextMatrix (landed)

**Mechanism.** Ruffle `text.rs render_self` pushes the DefineText MATRIX `T`, then each glyph's `{height/em, pen}` matrix, so a glyph's transform is `world · T · G`. Ours (`abc_timeline.cpp parseDefineText`) baked `T.t + pen` into every `Avm2StaticGlyph` and dropped `T.a/b/c/d`.

**Patch (self-localized; touched functions only):**
- `SWFRecomp/src/abc/abc_timeline.cpp`:
  - `StaticTextDef` gains trailing `has_matrix` and `m_a..m_ty`.
  - `parseDefineText`: when the linear part is non-identity, the pen stays in TEXT space (`base_tx/ty = 0`) and the full T is stored.
  - Static-text table emitter: appends `, 1u, a, b, c, d, tx, ty` **only for such records**. Translation-only records emit exactly the old initializer, so their generated C is byte-identical.
- `SWFModernRuntime/include/avm2/avm2_abc.h`: `Avm2StaticTextData` gains trailing `has_matrix; m_a, m_b, m_c, m_d; m_tx, m_ty`. Zero-initialised means the legacy contract, so older generated tables still work.
- `SWFModernRuntime/src/avm2/avm2_display.c` `avm2_render_statictext`: when `has_matrix` is set, the glyph slot is `mat_mul(world, T)`. `mat_mul` rounds the translation to whole twips in f32, ties-even (Ruffle `Matrix * Matrix`).
- `SWFModernRuntime/src/avm2/avm2_bitmap.c` `avm2_cpu_raster_statictext` (the CPU twin; the change stays **inside** this function, per the sibling map): it composes the same `world · T` with the same f32 ties-even twip rounding before calling `glyph_raster_core`.
- `avm2_statictext_collect_glyphs`, `statictext_get_text` and the bounds/hit paths are untouched. Bounds come from the DefineText RECT, which already includes T.

**Per-test before/after (same box, clean `origin/master` vs patch, `--mode=graphics --recompile`):**

| test | before | after |
|---|---|---|
| `regression/avm2_definetext_matrix` (GPU) | FAIL 10 200 channel outliers > 0, max 255 (3 400 px), md5 0c9de369 | **PASS 0 outliers, max 0**, md5 d545f08c |
| same, CPU twin (`AVM2_CPU_DUMP` frame 0, no-graphics build) | 3 400 px off the golden | **pixel-identical to the golden** (diff bbox None) |
| same, no-graphics trace | PASS | PASS |

The golden is the w1 analytic `output.expected.png`. It is **RGBA pixel-identical to the FLASH Player 32 `draw()` capture** (`w1-local-oracles/w1-text-glyph-fidelity/avm2_definetext_matrix/flash.png`; diff bbox None). So the pass is graded against Flash.

**Corpus footprint.** I ran a tag walk over every downloaded SWF (AS3 bit + DefineText/DefineText2). The only AVM2 DefineText with a non-identity linear part is the new fixture, so no corpus generated code changes. The runtime hunks are gated on `has_matrix`, which no corpus row sets. (w1's 6-SWF census covered all suites: the 4 rotated bevel/glow ones have zero text records, so `statictexts` stays empty and nothing is emitted.)

## 2. `definefont4` glyph half (landed as data) and the TextLine plan

### 2a. What landed
- **`SWFRecomp/src/abc/abc_devicefont.cpp`**:
  - `loadFace` is split into `loadFace` (reads the file) and a new `loadFaceData` (the unchanged body, on an in-memory blob).
  - The new public `emitCff4OutlineFont(out, blob, sym, font_id, name, bold, italic)` runs the DefineFont4 FontData (an `OTTO` OpenType/CFF file) through `stbtt_InitFont`, then the existing `appendGlyphOutline` (`STBTT_vcubic` → `cubicTo` → Levien flattener). It emits a `static const Avm2FontData <sym>` in the standard outline layout: codes, advances, f32 points, contour tables, font units, y down.
  - The face is a **standalone static that no font lookup can reach**: it is not a row of `avm2_generated_fonts` or `_device_fonts`. So no layout, metric, `Font.enumerateFonts` or `hasGlyphs` result can change.
- **`SWFRecomp/include/abc/abc_devicefont.hpp`**: the declaration.
- **`SWFRecomp/src/abc/abc_timeline.cpp`**:
  - The `TAG_DEFINE_FONT4` scan keeps the FontID and the FontData blob (trailing `Cff4Def` fields).
  - The cff4 emitter calls `emitCff4OutlineFont` per face and appends `&avm2_cff4_outline_N` to the row.
- **`avm2_abc.h`**: `Avm2Cff4FontData` gains trailing `const Avm2FontData* outlines` (NULL when there is no FontData or no ink). The browser host reads this table out of the guest (`setAvm2Cff4Fonts`). It is the same header and an appended pointer, so the layout stays shared.

**Measured.**
- `visual/definefont4` emits `avm2_cff4_outline_0 = { 1, "Exo 2", 0, 0, 1, 1000, 999, 201, 0, 40, … }`: 40 glyphs, including all of `This is a TLF using DefineFont4.`.
- `definefont4_glyph_check/cff4_render.py` rasterizes those emitted outlines with PIL at the measured layout (size 46, x 21, baselines 65 and 120). They are recognisable Exo 2 glyphs at the golden's positions: 1 547 px off the aliased golden at a >128 threshold (PIL polygon fill, no AA). See `ours_top_vs_golden_bottom.png`.
- Per-row: the `definefont4` md5 is 8edbd5a1 (= CI), unchanged. All 7 other DefineFont4 SWFs (`textline_metrics`, `textline_splitting_basic`, `textline_validity`, `textblock_recreate_text_line_width`, `textline_atom_index_at_char_index`, `font_enumeratefonts` (no FontData), and `definefont4` itself) keep their CI status (§4 table).

### 2b. Measured state of the TextLine path (temporary stderr probes, reverted)
In `visual/definefont4` the linked TLF library reaches FTE:
- `TextBlock.createTextLine(null, 406)` is called **once**. The content is `"This is a TLF using DefineFont4. "` (33 UTF-16 units).
- `tl_block_face` **resolves the face** (`embeddedCFF`, "Exo 2") at **size 46**. That size matches the independent golden fit (§2a), and `outlines` is live.
- We return **one** TextLine covering all 33 units. `tb_do_create_text_line` splits only on line separators (`next_line_break`) and ignores `width`. The golden has **two** lines: "This is a TLF using" / "DefineFont4.". At size 46 line 1's advances are 8 214 units = 377.8 px; adding "DefineFont4." (5 860 units = 269.6 px) exceeds 406, so the break falls after "using ".
- The golden's line pitch is 55.2 px = 1.2 × 46, TLF's default 120% leading. Baselines are ≈ 65.2 and ≈ 120.4, at x ≈ 21.

### 2c. Plan for the TextLine draw (NO-GO this session; priced)
1. **Width breaking in `tb_do_create_text_line`** (M; trace risk). Break at the last break opportunity whose cumulative advance (`tl_face_advance` × size / upem) fits `width`. Keep the separator rule, and update `raw_text_length`/`end_index`/`tl_layout_box`.
   - Must re-grade every FTE trace row: `textline_splitting_basic`, `textline_validity`, `textblock_*`, `textline_metrics`, `textline_atom_index_at_char_index`, `textblock_line_changes`, `textblock_releaselines`.
   - Ruffle `text_block.rs` is the reference for the break rule. Note that Ruffle itself passes `definefont4`, so it wraps.
2. **TextLine glyph draw** (S–M, display walk). Add a TextLine arm in the AVM2 render walk next to `avm2_render_statictext`: for a TextLine whose `tl_block_face(...)` hits and has `outlines != NULL`, build `Avm2GlyphPlacement[]` from the line's substring:
   - glyph = index of the codepoint in `outlines->codes`;
   - `x` advances by `advance·size·20/upem` twips, `y = 0` (baseline-local; `box_asc` already exists);
   - `scale = size·20/upem`;
   - colour = `ElementFormat.color`.

   Then reuse `avm2_text_slots` + `avm2_render_glyphs` (GPU), and `glyph_raster_core` for the CPU twin. A new `avm2_cpu_raster_textline` belongs in `avm2_bitmap.c`, which is `w2-draw-cx-text` territory this session.
3. **TLF positioning**: the composer sets `TextLine.x/y` from our ascent/descent/leading. This needs measuring after (1): if the y-advance is right, the lines land at the 65.2/120.4 baselines.
4. **Quality LOW**: the golden is aliased (`quality = "low"`, tolerance 1, 0 outliers), so the glyph edges must be bit-exact. Our cubic → quadratic split is not lyon's cubic flattener (the `cubicTo` comment says so), which is an exactness risk. Budget a Ruffle `GlyphToDrawing` cubic-parity pass (S) or accept a non-zero outlier budget.

Total remaining: **M–L**. The flip is `visual/definefont4` (pixel axis), plus game-visible FTE/TLF text everywhere.

## 3. AVM2 selection-rect tint (HOLD for Flash; fixture written)

**Ruffle (read at `1e604fa87`):**
- `edit_text.rs render_selection_background_for_line` (`:1163-1212`) calls `context.commands.draw_rect(color, selection_box)` with `color` = BLACK when focused, `Color::GRAY` (0x555555) otherwise. `draw_rect` carries **no colour transform** (`render/src/commands.rs:144`), so the rect is neither tinted nor alpha'd.
- `render_layout_box` (`:1295-1304`) pushes selected glyphs with `ColorTransform::IDENTITY`. The glyph's text-colour cx is replaced, so the glyph is white, but the field's own and its parents' stacked cx still apply.

**Ours:**
- `avm2_display.c avm2_render_text` draws the selection rects with `renderer_draw_rect(…, xid, cxid)`, the field's full concatenated cx.
- Selected glyphs are white (`avm2_edittext_collect_glyphs` sets 0xFFFFFF) under the same `cxid`. **This already matches Ruffle.**

So the only disagreement is the rect tint (and alpha). If Flash agrees with Ruffle, the change is **XS**: pass cx slot `0` instead of `cxid` in that one `renderer_draw_rect` loop. One open question to read off the same capture is whether group alpha should still reach the rect.

**Fixture** (`w2-avm2-text-tail-fixtures/avm2_edittext_selection_cxform/Test.as`): embedded TestFont 20 px, `"ababa"`, `setSelection(1,4)` on each of 5 rows:

| row | setup | rect if untinted | rect if tinted |
|---|---|---|---|
| 0 | control | gray 0x555555 | gray 0x555555 |
| 1 | field cx (0,0,0,1, +255,0,0) | 0x555555 | 0xFF0000 |
| 2 | field cx +blue | 0x555555 | 0x5555FF |
| 3 | parent Sprite cx (0,0,0,1, +255,0,+255) | 0x555555 | 0xFF00FF |
| 4 | focused, field cx (0,0,0,1, 0,+200,0) | 0x000000 | 0x00C800 |

The rect colour is read in the inter-glyph gaps. No change without the Flash verdict (rule 3; the brief).

## 4. Regression suite, re-checks and argued canary A/B

The standing canary cannot see these change classes: no corpus row has an AVM2 non-identity TextMatrix with glyphs, and the runtime never reads `outlines`. I appended a covering member at EOF of `render_canary_tests.txt`: **`regression/avm2_definetext_matrix`** (tier 1).

**Full render canary** (`render_canary.py capture --recompile`, before = clean `origin/master` source and recompiler, after = patch; all suites downloaded; 153 tests / 218 comparisons):

- **217 IDENTICAL, 1 DIFFERS**: `regression/avm2_definetext_matrix`, image fail → pass, trace pass → pass.
- Trace status changes: none.

I also ran an **argued 29-row A/B** first (graphics, `--recompile`, before = clean `origin/master` binaries, after = patch, md5 of every `*.actual.png` plus status):
- every canary member that is AS3 and carries DefineText/DefineText2/DefineEditText/DefineFont2/3/4 (16 rows; 13 canary rows are in suites I did not download, all AVM1 or misc, and the recompiler change is ABC-only);
- all 8 DefineFont4 SWFs;
- `avm2/static_text` (translation-only DefineText; the generated C is unchanged);
- `avm2/edittext_always_show_selection`;
- regression `avm2_timeline_text`, `avm2_bitmapdata_draw_textfield`, `avm2_edittext_placed_cxform` and `avm2_definetext_matrix`.

**28/29 are md5- and status-identical. Only `regression/avm2_definetext_matrix` moves (fail → pass).**

| row | before = after (status, md5) |
|---|---|
| `visual/definefont4` | FAIL 16 086 > 0, 8edbd5a1 (= CI) |
| `visual/fonts/font_lookup_as3` | FAIL 11 592 > 72, 04874d9f (= CI) |
| `from_shumway/acid/acid-textfield` | FAIL 15 754, 7da090c3 (= CI) |
| `avm2/textline_metrics`, `textline_splitting_basic`, `textline_validity`, `textblock_recreate_text_line_width`, `font_enumeratefonts`, `static_text` | PASS (trace) |
| `avm2/textline_atom_index_at_char_index` | RUFFLE_MATCHED (= CI) |
| `avm2/edittext_always_show_selection`, `edittext_autosize_height_dynamic`, `fonts/device_font_kerning`, `fonts/embed_matching/fallback_preferences`, `acid-color-0`, `acid-text`, `acid-text-6`, `acid-text-escape`, `text/auto_size/width`, `visual/edittext/{caret_multiline, device_transform_basic, device_transform_negative, gutter, selection_font_size}`, `visual/layout/line_vertical_align` | PASS, md5-identical |
| regression `avm2_timeline_text`, `avm2_bitmapdata_draw_textfield`, `avm2_edittext_placed_cxform` (19/19) | PASS, identical |

**No-graphics** (shared `avm2_bitmap.c`/`avm2_display.c`/recompiler; no `#ifdef NO_GRAPHICS` arm touched): `avm2_definetext_matrix`, `avm2/textline_metrics`, `avm2/static_text` and `visual/definefont4` all PASS.

## EXPECTED-FLIP LEDGER (CI check)

| axis | test | expected |
|---|---|---|
| pixel | `regression/avm2_definetext_matrix` | **new row, PASS** (0 outliers, max 0). It fails if the patch is not applied |
| trace | `regression/avm2_definetext_matrix` | new row, PASS (empty `output.txt`) |
| both | every other row | **no movement**. In particular `visual/definefont4` stays FAIL 16 086 (md5 8edbd5a1), `visual/fonts/font_lookup_as3` stays FAIL 11 592 (04874d9f), and all FTE/TextLine trace rows are unchanged |

The recompiler changed (`abc_timeline.cpp`, `abc_devicefont.cpp`), so CI must recompile. The generated C changes only for DefineFont4 movies (new static outline arrays plus one trailing pointer) and for non-identity DefineText (fixture only). The `categories=full` AVM2 policy applies.

## Could not finish / completion mechanisms
- **TextLine draw (`definefont4` flip):** M–L. Width breaking first (trace re-grade), then the glyph arm and its CPU twin (§2c).
- **Selection-rect tint:** waits on LOCAL ORACLE REQUEST 1. Then XS (cx slot 0 in the `avm2_render_text` selection loop), plus a landed fixture with the Flash golden.
- **`font_lookup_as3`:** the RVF docs entry drafted in s26 (w1 report §5) is still not landed. Docs-only, coordinator.

## New unclaimed leads
1. **FTE `createTextLine` ignores `width`** (§2b, measured): every TLF/FTE text that should wrap comes back as one line. This affects layout trace output in any FTE game, not only rendering.
2. **Ruffle-parity cubic flattening for CFF faces** (`OutlineSink::cubicTo` splits into 8 quads; lyon flattens cubics directly). It matters for quality-LOW exactness of any CFF device face or DefineFont4 text.

## LOCAL ORACLE REQUESTS
1. **FLASH (image, `--screen`; plus a `draw()` capture to compare):** `SWFRecompDocs/plans/session27-fanout-reports/w2-avm2-text-tail-fixtures/avm2_edittext_selection_cxform/`. Build it with `build_swf.sh` (mxmlc), 1 tick, and capture the 120×150 stage.
   - Needed: the colour of the selection rect in the inter-glyph gaps of rows 1–4 (table in §3), and the colour of the selected glyphs.
   - Also run the trace (`run_trace.py`; expected `focus=true` / `sel=1,4`).
   - If Flash leaves the rects untinted (0x555555 / 0x000000), the XS fix ships with this capture as the golden. If Flash tints them, ours is Flash-correct: add an `RUFFLE_VS_FLASH_DIFFERENCES` entry and land the fixture as-is.
   - A Ruffle exporter capture (`-f 1`) of the same SWF would confirm the source read.
