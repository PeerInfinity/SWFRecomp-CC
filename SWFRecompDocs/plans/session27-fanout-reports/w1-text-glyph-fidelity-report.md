# s27 wave 1: `w1-text-glyph-fidelity` report

**New files** (all under `SWFRecompDocs/plans/session27-fanout-reports/`):
- `w1-text-glyph-fidelity-report.md` (this report)
- `w1-text-glyph-fidelity-prototype.patch`: `git diff origin/master -- SWFModernRuntime SWFRecomp`, 3 hunks (§3, §2). `git apply --check` verified on `origin/master`.
- `w1-text-glyph-fidelity-fixtures/`. Each directory is meant to land in `ruffle-tests/tests/swfs/regression/` under the same name. The generators resolve `../avm1_edittext_placed_cxform` from there.
  - `avm2_edittext_placed_cxform/` (generator, swf, toml, output.txt, output.expected.png): **ready to land with the prototype**. It fails today (14 145 > 19) and passes with the patch (19/19).
  - `avm1_definetext_matrix/` (generator, swf, toml, analytic `output.expected.png` + `make_expected_png.py`). Fails today (4 085 px) and passes with the patch's recompiler hunk (**0 px**).
  - `avm2_definetext_matrix/` (generator, swf, toml, analytic golden, `ours-before.png`). Fails (3 400 px). Its arm is not prototyped (§2).
  - `avm1_edittext_scaled_glyphs/` (generator, swf, toml, `ours-before.png`). Its golden is a LOCAL ORACLE REQUEST (§1).
  - `avm1_bitmapdata_draw_edittext/` (generator, swf, toml, output.txt). This is a trace fixture that fails today with all 3 lines wrong (§4).
  - `avm2_bitmapdata_draw_edittext_box/` (`Test.as` + by-construction expected trace). It needs mxmlc, so it is a LOCAL ORACLE REQUEST (§4).

**Box.** Cloud box with `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Base is `origin/master` = `ae7f50cb` (includes `d70f2c0aa`). Wave-0 had not published, so the baseline is `df7729df2`. Upstream corpus downloaded at Ruffle `1e604fa87` (my blobless clone, taken in the same minute). **Fidelity:** my clean-master renders of `acid-text-4`, `acid-text-5`, `font_lookup_as3` and `definefont4` are byte-identical to CI's actual PNGs on `origin/ruffle-image-results`, so local grading is CI-grade for these rows.

## Verdicts (lead)

| # | item | verdict | graded flips | price |
|---|---|---|---|---|
| 3 | AVM2 `avm2_render_textbox` cx twin, plus AVM2 DefineEditText `HAS_BACKGROUND ← BORDER` | **GO (correctness, prototyped and measured)** | **0 corpus rows** (25 bordered-AVM2-ET rows and 26 AVM2 text canary/failing rows md5-identical). +1 fixture `regression/avm2_edittext_placed_cxform` fail → pass | XS, 2 runtime hunks |
| 3b | AVM2 static-text cx twin | **REFUTED (no gap)**: `avm2_render_statictext` and the EditText glyphs already allocate the full concatenated cx slot (`avm2_text_slots` → `avm2_alloc_cx_slot`) | — | — |
| 2 | DefineText TextMatrix fidelity, AVM1 recompiler | **GO (correctness, prototyped)**: a scaled or rotated TextMatrix rendered wrong (scale dropped, rotation sheared). Fixed in `swf.cpp` | **0 corpus rows** (generated code byte-identical on all 6 rows with a non-identity TextMatrix; the 4 rotated bevel ones have zero text records). Fixture fail → pass, 0 px | XS |
| 2b | same, AVM2 arm (`abc_timeline.cpp` → `Avm2StaticGlyph`) | **HOLD (priced S–M, not prototyped)**: only the TextMatrix translation is kept | 0 corpus rows; fixture `avm2_definetext_matrix` 3 400 px | S–M |
| 1 | EditText glyph compose rounding for scaled fields | **PREMISE REFUTED for AVM1**: the AVM1 glyph run is **not scaled at all** (translation-only), so there is nothing to round yet. AVM2 rounds nowhere. **HOLD** | **0 graded rows** (no failing or passing image row has a scaled EditText with glyphs) | AVM1 scale/rotate: M; rounding afterwards: XS |
| 4 | `draw()` of a tinted EditText | **AVM1: bigger gap than briefed.** `draw()` of ANY TextField paints nothing (box and glyphs), and a descendant's cx is never composed. **AVM2:** `draw(tf)` paints glyphs only, never the box, and the CPU draw walk drops every descendant cx (shapes too). **HOLD** | 0 corpus rows (no AVM1 row draws a TextField; no AVM2 row draws a tinted or boxed one) | AVM1 M; AVM2 box S, walk cx S–M |
| 5 | `font_lookup_as3`, `definefont4` NO-GOs | **Re-confirmed NO-GO** (md5 = CI baseline). Mechanisms refined (§5); the `font_lookup_as3` RVF entry drafted in s26 **was never landed** | — | definefont4 L (CFF glyph decode now S–M via the existing stb path, plus the TextLine render arc) |

**No graded flip is claimed. The expected CI movement of the prototype is zero rows on both axes.** Everything in this brief is
game-visible correctness with no failing graded row behind it. The failing text rows on the board (`acid-text-4/-5`,
`acid-textfield`, `hardwrap`, `captions`, `stylesheet`, `flash_text_TextField`) are **all `known_failure`** and **none has a scaled
field or a non-translation TextMatrix** (§6).

---

## 1. EditText glyph compose rounding (item 1): premise refuted for AVM1, priced

**Ruffle/Flash model** (read at `1e604fa87`). The EditText glyph matrix is the product of three steps, `world * layout_to_local *
translate(lbox.origin) * glyph`:
- `layout_to_local` = translate(bounds.min + GUTTER − scroll), times `scale(d/a, 1)` for device text (`edit_text.rs:799`).
- The lbox translate is pushed in `render_layout_box` (`edit_text.rs:1250`).
- The glyph matrix is `{a=d=height/em, tx=x, ty=baseline}` (`font_like.rs:91` `evaluate`).

`Matrix * Matrix` (`render/src/matrix.rs:182`) rounds `a*rhs.tx + c*rhs.ty` to whole twips at **each** push, in f32 with ties-even. A glyph's
stage tx is therefore `W.tx + round(W.a·L.x) + round(W.a·O.x) + round(W.a·x)`: three independent twip roundings, never at device
pixels. Layout advances are truncated to twips per glyph before render (`(advance*scale) as i32`; device fonts round to whole pixels).
The maximum displacement against an unrounded product is 1.5 twips (0.075 px). That is visible only on aliased (quality LOW) edges.

**Ours.** There is no rounding question for AVM1 yet. **The AVM1 glyph run ignores the field's scale and rotation entirely:**
- `actionIterateTextFieldGlyphs` (`action.c:~31960`) composes only parent translations ("Translation-only — scale/rotation
  composition is deferred").
- `TextFieldGlyphInfo` (`action.h`) carries no matrix.
- `tag.c textfield_glyph_render_cb` places vertices at `vx*height/em + x_pos` on **transform slot 0**. Its clip mask is likewise unscaled.
- The box (`TextFieldRenderInfo.m_a..m_ty`, `tf_world_matrix`) *is* scaled.

Measured with the new fixture `avm1_edittext_scaled_glyphs` (bordered square-glyph field at scale 2, 0.5 and (1.5, 1)). All three
fields draw **scale-1 glyphs inside correctly scaled boxes**, and the 0.5× field's glyphs overflow its border (`ours-before.png`).
The orphan path (`otf_emit_textfield`) is translation-only too.

**AVM2** (`avm2_render_glyphs`) draws field-local glyph placements through the field's world xform slot. Scale is right, but nothing
rounds: there is no whole-twip compose like `tag.c tag_text_glyph_compose`.

**Pricing.** A static sweep of every image row found AVM1 timeline-scaled EditText only in `visual/edittext/edittext_{background,border}_basic(_scale2)`.
Their fields have **no text** (HasText = 0), and they pass. None of the 7 failing text rows has a scaled field (ABC string scan: no
`scaleX`/`scaleY`/`rotation`/`Matrix`, and all placements are identity-scale). So **0 graded rows** can move.
- Completion mechanism, AVM1 scale/rotation (M, `n-pixel-pass` / N-ladder territory: `action.c` + `tag.c`): add trailing
  `m_a..m_d` to `TextFieldGlyphInfo`, fill them from `tf_world_matrix` in both producers (`actionIterateTextFieldGlyphs`,
  `otf_emit_textfield`), and draw glyphs, mask, selection and caret in field-local twips through one written xform slot. Device-font
  fields need Ruffle's `device_font_scale_x` and the rotate/shear cull, which the box already has.
- Then apply the three-step rounding: XS in both runtimes (the `tag_text_glyph_compose` pattern).
- Golden: LOCAL ORACLE REQUEST 1.

## 2. DefineText TextMatrix fidelity (item 2): GO for AVM1 (prototyped), AVM2 priced

**Mechanism.** Ruffle `text.rs render_self` pushes `text_transform` (the DefineText MATRIX), then per glyph
`{a=d=height/em, tx/ty=pen}`. The glyph is therefore `T * G`: scale `T.lin·s`, translation `T.t + T.lin·pen`.
- **AVM1** (`swf.cpp` DefineText record loop) emitted `{a=d=s, b=T.b, c=T.c, tx=T.tx+pen}`. It overwrote T's scale with s, left T's
  rotation **unscaled**, and did not rotate or scale the pen.
- **AVM2** (`abc_timeline.cpp parseDefineText`, `pen_x = base_tx + …`) keeps only `T.t`. `Avm2StaticGlyph` has no linear part.

**Fixture** `avm1_definetext_matrix`: square glyphs, TextMatrix scale(2,1), TextMatrix rot+90°, and an identity control. Its
`output.expected.png` is **analytic**: exact pixel-aligned squares from the formula above.

| leg | AVM1 fixture | AVM2 twin (`avm2_definetext_matrix`) |
|---|---|---|
| origin/master | 4 085 px (scaled text at scale 1; rotated text a 45° shear) | 3 400 px |
| prototype (`swf.cpp` hunk) | **0 px, max 0** | 3 400 px (arm not touched) |

**Prototype (`swf.cpp`, DefineText record loop only).** At emission, the glyph matrix is composed as T·G, with the pen taken in
text space (`temp_matrix.translate − matrix.translate`). The rotated translation is rounded `lrintf`, ties-even, matching Ruffle's
`round_to_i32`. For a translation-only TextMatrix the output is unchanged by construction: b = c = 0 and tx = T.tx + pen exactly.

**Corpus footprint (exact).** A tag walk over every downloaded test (all suites incl. `regression`) finds **6** SWFs with a
non-identity TextMatrix:
- the four rotated ones are in `bevel_full`, `bevel_inner`, `bevel_outer` and `glow_with_alpha_strength`, all with **zero text
  records**, so no glyph matrix is emitted;
- the translation-only ones are `acid-text-5` (×3) and `avm2/static_text`.

I recompiled all 6 with the old and new binaries: **`RecompiledTags` and `RecompiledScripts` are byte-identical (`diff -rq` clean)**.
So the hunk moves no corpus row, and the canary cannot see it. The fixture is the only witness.

**Approximation left.** We still round once over the folded `T·G`, where Ruffle rounds `W·T` and then `·G` (the s26 note). It is
exact for an integer-translation T at world scale 1.

**AVM2 completion (S–M).** Emit the per-character TextMatrix linear part on the static-text record (a trailing field of
`Avm2StaticTextData`), keep pen in text space, and compose `world * T.lin` in `avm2_render_statictext` and
`avm2_cpu_raster_statictext`. The fixture `avm2_definetext_matrix` (analytic golden) grades it.

## 3. AVM2 colour-transform twins (item 3): EditText box GO (prototyped); static text refuted

**Static text (refuted).** `avm2_render_statictext` and the EditText glyph draw both take `cxid` from `avm2_text_slots` →
`avm2_alloc_cx_slot()`. That is the node's full concatenated `g_avm2_cur_cx` (mult and add, all 4 channels). The fixture below shows
the glyphs tinted exactly before any change.

**EditText box (gap, fixed).** Ruffle `draw_text_box` and `draw_device_text_box` paint `transform.color_transform * background` and
`* border` (`edit_text.rs:2887/2895/2970/2975`). `avm2_render_textbox` draws both through cxform **slot 0** (the geometry is stage
twips on the identity slot) with group alpha only. Prototype in `avm2_display.c`: new static `avm2_textbox_cx_rgb` (the AVM1
`tf_cx_rgb` twin: RGB `c·mult + add`, clamped, from `g_avm2_cur_cx`) applied to `bg` and `bc` at the top of `avm2_render_textbox`.
Alpha keeps riding `alpha`.

**Second gap found by the twin: AVM2 DefineEditText never had a background.** Ruffle `EditText::from_swf_tag` sets
`HAS_BACKGROUND` from the tag's `BORDER` bit (`edit_text.rs:306-309`; the tag has no background flag). `avm2_text.c` (the
DefineEditText init near `et->border = …`) set only `border`, so `avm2_text_box_info` reported no background. A bordered
timeline field drew a transparent box, and `tf.background` read `false`. The prototype adds `et->background = et->border;`.
The AVM1 orphan path already does this (`otf_emit_textfield`: `has_border = has_bg`).

**Fixture `avm2_edittext_placed_cxform`** is `avm1_edittext_placed_cxform`'s SWF with the AS3 bit and an empty DoABC (the
`avm2_layer_group_alpha` recipe). Golden: the AVM1 fixture's Ruffle golden (confirmation is LOCAL ORACLE REQUEST 2).

| leg | result |
|---|---|
| origin/master | 14 145 > 19, max 255. White box, black border, tinted glyphs |
| + box cx only | 13 399. Border tinted, background still absent |
| + `background = border` | **PASS 19/19, max 64.** These are exactly the 9 Dx12 corner pixels the AVM1 fixture budgets |

**Sweeps (A/B, graphics, before = clean runtime, after = patch; md5 of every actual PNG plus status lines):**
- **All 25 corpus tests that are AVM2 and contain a bordered DefineEditText**: 21 avm2 trace rows,
  `avm2/edittext_tag_indent`, `from_shumway/acid/acid-textfield-scroll`, `text/auto_size/{height,return,width}`. All are
  **md5-identical and status-identical** (the stages are white, so the new white background is invisible).
- **Render-canary subset** (argued scope): every `render_canary_tests.txt` member that is AVM2 and contains DefineEditText or a
  `TextField` ABC string (17), plus the failing AVM2 text rows (`hardwrap`, `captions`, `flash_text_TextField`, `acid-text-4/-5`,
  `font_lookup_as3`, `definefont4`, `bitmapdata_draw`) and `regression/avm2_timeline_text` and
  `avm2_bitmapdata_draw_textfield`. That is 26 rows: **26/26 md5- and status-identical**, and only the new fixture moves. The other
  canary members are AVM1, or AVM2 without any TextField, so neither runtime hunk is reachable there. The box hunk is the identity
  unless the cx is non-identity *and* the field has a box.
- No-graphics: `avm2/edittext_align`, `avm2/selection` and the fixture PASS. `avm2_text.c` is shared and compile-checked.

Trace side: `background` on a timeline-bordered AVM2 field now reads `true` (Ruffle). No corpus trace reads it (all 21 rows
unchanged). It is in the mxmlc fixture request (§4) for a Flash/Ruffle confirmation.

**Sibling localization.** The touched functions are `avm2_render_textbox` (+ new static `avm2_textbox_cx_rgb`) in
`avm2_display.c`, the DefineEditText init in `avm2_text.c` (one line), and the DefineText record loop in `swf.cpp`. There is nothing in
`tag.c`, `action.c`, `ng_shared.c`, `swf.c` or `avm2_bitmap.c`.

## 4. `draw()` of a tinted EditText (item 4): the gap is wider than briefed; HOLD

**AVM1 (measured).** `rasterizeMovieClipToBitmap` (`action.c:14824`) walks Drawing-API paths, timeline entries
(`bd1_draw_timeline_entry`, which **returns early for a DefineEditText character**, `ng_getCharTextfieldIdx >= 0`) and child clips. A
TextField MC contributes nothing, and the `cx` argument is passed to children unchanged: no child `Color` is ever composed.
- Fixture `avm1_bitmapdata_draw_edittext`: backgrounds read at the field centre on an opaque blue target.
- Expected `16711680 / 65280 / 65280`. We trace **`255 / 255 / 255`** on all three lines (`draw(tf)`, `draw(tf, m, ct)`,
  `draw(holder > Color'd clip > field)`).
- The expected values are Flash semantics by construction (solid background fill; draw ignores only the SOURCE's own transform). A
  Ruffle trace confirmation is LOCAL ORACLE REQUEST 3.

**AVM2 (code-read, not measurable in the cloud).**
- `BitmapData.draw(tf)` goes to `bd_draw_textfield` → `text_raster_core`. That draws **glyphs only**: no background and no border.
  The draw `colorTransform` does reach the glyphs (pinned by `avm2_bitmapdata_draw_textfield`).
- `draw(container)` goes to `bd_draw_shape_walk`, which threads only `alpha`. `avm2_cpu_raster_shape/morph/text/statictext` never
  see a descendant's colorTransform: `grep cx_rm avm2_bitmap.c avm2_cpu_raster.c` finds nothing. So a tinted child shape draws
  untinted too.
- `Test.as` in `avm2_bitmapdata_draw_edittext_box/` pins both. It is LOCAL ORACLE REQUEST 4.

**Pricing and completion.** 0 corpus rows: no AVM1 row draws a TextField (tag/string scan of every AVM1 SWF with `draw` +
`BitmapData`), and no AVM2 row draws a boxed or tinted field.
- **AVM1 (M):** a TextField arm in `rasterizeMovieClipToBitmap`. The box is S, from the same props `actionIterateTextFields` reads.
  Glyphs need a CPU glyph raster: AVM2's `glyph_raster_core` exists but is `static` in `avm2_bitmap.c`. Compose the child clip's cx
  in the child recursion (S; touches `action.c`, so coordinate with the N ladder).
- **AVM2:** box in `text_raster_core` (S). The walk needs a running `Avm2Cx` parameter applied per leaf (S–M; this is
  `w1-applyfilter-tail` / draw territory).

## 5. `font_lookup_as3` and `definefont4` re-test (item 5)

- **`visual/fonts/font_lookup_as3`**: 11 592 > 72, md5 `04874d9f` = CI. s26's mechanism stands: the 4 `embedFonts=true, font=""`
  cells, where Ruffle falls back to its default font and Flash draws nothing. **Completion:** the RVF entry drafted in
  `session26-fanout-reports/w1-pixel-tail-report.md` §4c **is not in `RUFFLE_VS_FLASH_DIFFERENCES.md`** (grep finds no
  `font_lookup_as3` in any `_investigation` doc or ignore list). Land it, with the image-axis marker. Docs only.
- **`visual/definefont4`** (TLF, `num_ticks = 5`, quality low): 16 086 > 0, md5 `8edbd5a1` = CI. We draw a blank stage where the
  golden has two lines of TLF text. The mechanism is refined against s26's "no DefineFont4 handler":
  - The recompiler **now parses DefineFont4** (`abc_timeline.cpp` `Cff4Def`: name, style, typo metrics, advances; "Glyphs are not
    decoded").
  - `abc_devicefont.cpp` already decodes **CFF outlines through stb_truetype** (`STBTT_vcubic` → `cubicTo`) and flattens them for
    device faces. So the glyph half is S–M: feed the DefineFont4 FontData blob through the same `appendGlyphOutline`.
  - The TextLine **render** half (TLF builds TextLines through FTE `TextBlock.createTextLine`; we have TextLine metrics and logical
    boxes in `avm2_display.c` / `avm2_text.c`, but no glyph draw) remains the arc.
  - Total still L. NO-GO stands.

## 6. Refutations and pricing attacks

1. **"EditText glyph compose rounding for scaled fields" (playbook §25):** there is no AVM1 scaling to round. The AVM1 glyph run is
   translation-only, a larger correctness gap (§1). No graded row has a scaled EditText with glyphs.
2. **"AVM2 static-text cx twin":** no gap. Static and EditText glyphs already use the full concatenated cx slot. Only the EditText
   *box* had the gap, plus the missing `HAS_BACKGROUND ← BORDER`.
3. **"draw() of a tinted EditText":** the AVM1 gap is "draw() of any EditText paints nothing". Tint is the smaller half.
4. **The failing text rows are not this family.** `acid-text-4` (KF #12121): fields unscaled; ours vs `output.ruffle.png` is
   145 px (per-glyph x offsets of 1 px in the first field, a kerning/advance difference). The Flash golden is anti-aliased text at
   quality LOW, which is the F/G FlashType NO-GO family. `acid-text-5` (KF #12122): **ours matches `output.ruffle.png` to max 1
   channel**; the Flash-only content (the "XXX" field, "ABCI" vs "XYZ") is a Ruffle gap too. `acid-textfield` (KF #12123),
   `hardwrap`, `captions`, `stylesheet`, `flash_text_TextField`: all KF, no scaling, and the wordwrap sibling owns them.
5. **`bevel_*` rotated TextMatrices** (the only rotated ones in the corpus) carry zero glyphs, so they never exercised item 2.

## Prototype patch scope (`w1-text-glyph-fidelity-prototype.patch`, 91 lines)

| file | function | change |
|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_display.c` | new static `avm2_textbox_cx_rgb`; `avm2_render_textbox` (2 lines) | box bg/border × concatenated cx |
| `SWFModernRuntime/src/avm2/avm2_text.c` | DefineEditText ext init (`et->border = …`) | `et->background = et->border` |
| `SWFRecomp/src/swf.cpp` | DefineText TEXTRECORD glyph loop (`recompileMatrix` call) | glyph matrix = TextMatrix · glyph |

**Expected-flip ledger for wave 2:** no corpus row moves on either axis. The fixtures move: `avm2_edittext_placed_cxform` fail → pass
(land it; golden in hand), and `avm1_definetext_matrix` fail → pass (analytic golden; land after ORACLE 5 or as-is). Recompiler
change: CI recompiles. Run the graphics leg with fresh recompilation.

## New unclaimed leads

1. **AVM1 EditText glyphs ignore scale and rotation** (§1). M; owner `action.c actionIterateTextFieldGlyphs` / `otf_emit_textfield`
   plus `tag.c textfield_glyph_render_cb`. Game-visible: any zoomed, tweened or scaled HUD text. Fixture ready.
2. **AVM2 DefineText TextMatrix linear part** (§2). S–M, `abc_timeline.cpp` plus `avm2_render_statictext` and the CPU twin. Fixture with
   analytic golden ready.
3. **AVM1 `BitmapData.draw` of a TextField paints nothing**, and the AVM1 draw walk never composes a child clip's `Color` (§4). M.
4. **AVM2 CPU `draw()` walk drops every descendant colorTransform** (shapes, bitmaps, text), and `draw(tf)` omits the box (§4). S–M.
   For `w1-applyfilter-tail` or a draw slot.
5. **AVM2 selection rect is tinted; Ruffle's is not.** `avm2_render_text` draws selection rects with `cxid`, but Ruffle
   `render_selection_background` does `draw_rect(color, …)` with no cx (`edit_text.rs:1212`). Ruffle also draws *selected* glyphs
   with an IDENTITY cx (`:1302-1307`). XS, Ruffle-sourced; needs a Flash check before changing.
6. **`definefont4` glyph half:** DefineFont4 CFF outlines through the existing stb_truetype + flattener path in `abc_devicefont.cpp`
   (S–M). It is a prerequisite of the TextLine render arc.
7. **Land the `font_lookup_as3` RVF entry** (docs only, drafted s26).

## LOCAL ORACLE REQUESTS

Ruffle exporter `0ddd12b6a` or later, default (HIGH) quality, `WGPU_BACKEND=vulkan` (border corners: playbook s26 note). The fixture
paths are under `SWFRecompDocs/plans/session27-fanout-reports/w1-text-glyph-fidelity-fixtures/`.

1. `avm1_edittext_scaled_glyphs/test.swf`, `exporter -s -f 1 --trace-log out.txt test.swf output.expected.png`. Need the PNG as the
   fixture golden. Expect glyphs scaled with their boxes.
2. `avm2_edittext_placed_cxform/test.swf`, `-f 1`. Need confirmation that the PNG equals the AVM1 fixture's golden
   (`regression/avm1_edittext_placed_cxform/output.expected.png`) up to the Dx12/vulkan corner pixels. If vulkan is used, the corner
   budget may drop to 3 channels × 3 boxes.
3. `avm1_bitmapdata_draw_edittext/test.swf`, `-f 1 --trace-log`. Need the trace; `output.txt` expects
   `draw(tf)=16711680`, `draw(tf,m,ct)=65280`, `draw(h)=65280`. If Ruffle differs on line 3 (Color on an entry-less
   `createEmptyMovieClip` clip), report it: that is also s26 lead "entry-less dynamic parents".
4. `avm2_bitmapdata_draw_edittext_box/Test.as`: build with mxmlc (the `regression/avm2_bitmapdata_draw_textfield/build_swf.sh`
   recipe), then `exporter -s -f 1 --trace-log`. Need the trace (expected by construction in `output.expected-by-construction.txt`).
5. `avm1_definetext_matrix/test.swf` and `avm2_definetext_matrix/test.swf`, `-f 1`. Need the PNG, to confirm the analytic golden
   (pixel-aligned squares, so it should match at tolerance 0 except for AA edges at HIGH).
