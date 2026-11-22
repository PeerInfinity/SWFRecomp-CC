# w1-pixel-text: pixel axis, text rendering (session 24, wave 1)

**New files:** `w1-pixel-text-report.md` (this file) and `w1-pixel-text-prototype.patch` (`git diff origin/master --
SWFModernRuntime SWFRecomp` at `df126b80`; sources reverted on the branch). The prototype map is at the end.

**Environment:** cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn). Tests downloaded from upstream Ruffle master
**`bcac30c19`** (categories `avm1 avm2 text fonts visual from_shumway from_gnash`; `from_shumway` and `from_gnash`
were added for `acid-color-0`, `text-bind` and the rider sweeps). Ruffle source: blobless clone at `bcac30c19`.

**CI fidelity, proven first.** Before-renders of `text/br_at_start` (`80ac920d…`) and `text/style_changes_in_html`
(`1dfafdb6…`) are md5-identical to the CI actual PNGs on `origin/ruffle-image-results` (baseline images run
`44965247383`). Every other before-number below reproduces the baseline JSON exactly (`acid-color-0` 17326,
`static_text_offstage` 16016, `text-bind` 85/587). Local grading is therefore CI-grade.

---

## Verdicts (lead)

| # | Row | Verdict | Measured (CI-grade, before → after) | Flips |
|---|---|---|---|---|
| 2 | `text/br_at_start` | **GO: land the prototype hunk.** The premise is **refuted**: the cause is fractional tag leading truncated to whole pixels, not the per-line max | 1672 → **4** (limit 8) | **+1** |
| 2 | `text/style_changes_in_html` | **GO: land the prototype hunks.** The premise is **refuted** here too: the cause is a per-run embedded face (`<b>`/`<i>`) plus Ruffle's Fixed8 glyph colour | 24998 (max 103) → **0 (max 0)** | **+1** |
| 1 | `from_shumway/acid/acid-color-0` | **NO-GO for a flip (band confirmed).** The s23 "gradient residual" premise is **refuted**: the residual is DefineBitsJPEG3 alpha edges, plus a ring edge and centring | 17326 → 688 (s23 cx) → 325 (+JPEG3 premultiply) → 127 (+edge dilation experiment) → 121 (+integer-twip centring); limit 3 | 0 |
| 1b | AVM2 twin (`avm2_render_textbox` cxform slot 0) | **Not latent in any graded row** | sole candidate `from_shumway/acid/acid` (18 cmps, 198/360 pass): its outliers are glyph edges and the colours match | 0 |
| 3 | `visual/static_text_offstage` | **HOLD.** (a) and (b) are cheap and prototyped; (c) is a general AVM1 `BitmapData.draw` gap | 16016 → **9600** (the remaining 9600 is exactly the two squares of (c)) | 0 until (c) |
| 4 | `text-bind` 587/600, `fallback_preferences`, `edittext_border_filters` | **NO-GO.** Nothing cheap buys headroom without moving away from Ruffle | unchanged (85/100 and 587/600; the others md5-identical) | 0 |
| 5 | `visual/definefont4` | **NO-GO (price unchanged from s23)** | blank render (16086) | 0 |

**Priced flips for wave 2: +2 certain** (`br_at_start`, `style_changes_in_html`), both measured CI-grade with a clean
rider sweep. Nothing else on this brief flips this session.

**Rider sweeps (md5, render_canary A/B):**
- Sweep 1, for the leading, per-run face and Fixed8 colour hunks: **45 tests / 75 comparisons**. These are every
  image-graded non-ABC test with a DefineEditText or a `createTextField`/`htmlText`/`TextFormat`/`textColor` string,
  plus `acid-textfield`. **72 IDENTICAL.** 3 DIFFER: the two flips and `from_shumway/avm1/text-bind`. In `text-bind`,
  2984 channels change at max diff 1 (the Fixed8 colour); its outliers are unchanged (t128 85/100, t64 587/600).
  No trace status moved.
- Sweep 2, for the root-text per-instance slots, the bounds cull and the JPEG3 hunk (`--recompile`): **17 tests / 18
  comparisons**. These are every image-graded non-ABC test with DefineText/DefineText2, every graded test with a
  DefineBitsJPEG3/4, the `bevel*` rows and the headline rows. **13 IDENTICAL.** The 5 that differ are all on the
  ledger: `acid-color-0` (band), `text-bind` (max 1), `br_at_start`, `style_changes_in_html` and
  `static_text_offstage` (band). The three ABC JPEG3 rows (`pixelbender_dithering`, `bitmapdata-clone`,
  `bitmapbuttons`) are md5-identical.
- `regression`: `avm1_parent_child_text` (graphics and no-graphics), `avm2_parent_child_static_text`,
  `avm2_static_text` and `avm2_timeline_text` all pass. No-graphics trace: `br_at_start` and `style_changes_in_html`
  pass.
- Canary members that see this change class: `from_shumway/avm1/text-bind` (moves by max 1, see above),
  `avm1/edittext_stylesheet`, `from_shumway/acid/acid-textfield`, `visual/simple_shapes/text_field_mask`,
  `from_shumway/acid/acid-text-escape`, `visual/cache_as_bitmap/text`, `avm1/edittext_tag_indent`, the
  `edittext_*` rows and `edittext_border_filters`. All are md5-identical except `text-bind`. **Wave 2 should append
  `text/style_changes_in_html` (tol 0: sees per-run faces AND glyph colour quantisation) and `text/br_at_start`
  (fractional leading) to `render_canary_tests.txt`.** No current member sees either mechanism.

---

## 2. The AVM1 render pitch: two separate mechanisms, neither of them the per-line max

The brief (and s23's lead) read both rows as "the per-line max ascent/descent". A run-table probe in
`textfield_glyph_render_cb` (`SWFModernRuntime/src/libswf/tag.c`) refutes that for both rows: **every run on every
line has the same `font_height`** (`br_at_start`: 8 runs, all fh=400; `style_changes_in_html`: all fh=600).

### 2a. `br_at_start`: fractional DefineEditText leading truncated to whole pixels

- The tag (`DefineEditText id=2`, HasLayout) has **Leading = 533 twips** (26.65 px). The renderer laid out with
  **520**.
- Owner: `tf_get_defaults` (`action.c:~27090`) stores `def->leading = leading_twips / 20` (an `s16` pixel count in
  `TFRun`). The htmlText sync sites then write `_tf_leading = first_run->leading * 20` (`action.c` `tfRebuildFromHtml`
  ~23060 and the `htmlText` setter ~55735).
- Ruffle keeps `TextFormat.leading` as f64 pixels from `layout.leading.to_pixels()` and lays out with
  `Twips::from_pixels(span.leading)` (`html/layout.rs:254-256 line_leading_adjustment`, `:450 newline`). So each line
  pitch is 544 + **533**, and our text sat 3 × 13 = 39 twips (2 px) high on line 4 (measured: golden red rows
  178..192, ours 176..190).
- **Prototype:** `tf_run_leading_twips(mc, px)`. When the run's pixel leading equals the tag default truncated, it
  returns the tag's exact twips; otherwise it returns `px*20` as before. 1672 → **4** (limit 8, max 160).
- Reach (scanned): across every downloaded non-ABC SWF, `br_at_start` is the **only** DefineEditText whose leading is
  not a whole pixel. The hunk also feeds `textHeight`, but no trace row can see it.
- Wave-2 cleanliness: the cleaner fix is to carry twips leading in `TFRun` (an `s16 leading_tw` trailing field) rather
  than re-deriving it at the two sync sites. The prototype's "equals the truncated default" test cannot tell an
  explicit `<textformat leading="26">` from the default, though that case gives the same value anyway.

### 2b. `style_changes_in_html`: per-run embedded face plus Fixed8 glyph colour

- The three fields embed four DefineFont3 faces (Regular/Bold/Italic/Both, each a **glyph subset**). Our AVM1 renderer
  draws every run with the **field's** `font_id` (`TextFieldGlyphRun` has no face), so bold and italic runs lose their
  glyphs. The CI render reads "Bold d I d Bo d I", "Italicatalaal" and so on.
- **Prototype, step 1 (geometry):** a trailing `u16 font_id` on `TextFieldGlyphRun` (`action.h`). It is filled in the
  run-table producer (`action.c` ~29860) via `ng_findEmbeddedFontId(r->font_name, r->bold, r->italic)`, only for
  **embedded** fields (flag 0x80) and only when the face differs. It is zeroed in every other producer, because
  `_tfg_runs` and `otf_html_runs` are shared statics. `textfield_glyph_render_cb` resolves the face per run in the
  measure pass and in the draw pass (`TF_RESOLVE_RUN_FONT`: font index, em, glyph base). Result: 24998 (max 103) →
  21516 at **max diff 1**. The geometry is pixel-exact.
- **Prototype, step 2 (colour):** every remaining channel was (255,**152,203**) golden vs (255,153,204) ours, for text
  colour `#FF99CC`. Ruffle colours glyphs through a colour transform, `set_mult_color` →
  `Fixed8::from_f32(c/255.0)`, which truncates to 1/256 (`core/src/font/font_like.rs:98`,
  `swf/src/types/color_transform.rs:61-66`). So 0x99 → 153/256 → 152 and 0xCC → 204/256 → 203; 0x00 and 0xFF are
  unchanged, which is why pure-colour rows never saw it. Quantising the glyph run colour the same way gives **0
  outliers, max diff 0**.
- **Flash-over-Ruffle check:** the golden itself carries the 152/203 values, so this matches the graded expectation.
  The face change is plain Flash behaviour.
- **Where the per-line max really matters:** with per-run faces landed, a line that mixes faces with different
  ascent/descent (or mixes sizes) still uses the field-default ascent for its baseline and pitch. **No graded corpus
  row was found that needs it.** It stays an unpriced correctness item (completion: per-line `max(ascent)`/`max(descent)`
  over the runs on each line, `layout.rs:495-508`, plus `current_line_span` leading).

---

## 1. `acid-color-0`: the residual is not a gradient

The baseline (17326) is the s23 text colour-transform bug. The s23 prototype still applies cleanly to `df126b80`, and
stacked with this patch it gives **688**. Per-128-px-tile census of what is left:

| tile | channels > tol | max | content |
|---|---:|---:|---|
| (0,3), (1,3) | 386 + 282 | 30 / 39 | **the two Firefox logos** (y 384–511), not the radial row (y 256–383, which is clean) |
| (4,2) | 11 | 255 | gradient ring edge (a shape, quality=low) |
| (6,1), (6,2) | 9 | 255 | "Hello" glyph edges, 1 px left |

**Logo mechanism (refutes "gradient residual"):** the logo is a **DefineBitsJPEG3** with an alpha plane. Flash and
Ruffle treat JPEG3 colour as **premultiplied**, clamped to alpha (`render/src/utils.rs:235-242`, "Flash Player clamps
color to the alpha value"). Our recompiler (`SWFRecomp/src/swf.cpp`, JPEG3/4 arm ~1819) emits the raw RGB as
**straight** alpha, so the renderer premultiplies a second time and the alpha edges come out dark grey. Measured, on
top of s23 cx:

1. Un-premultiply at emit (clamp to a, then ×255/a; a=0 → 0): 688 → **325**. Alone on master: 17326 → 16963.
2. The rest of the logo fringe is **straight-alpha bilinear sampling**: a=0 texels (now black) bleed into the edge. An
   env-gated experiment (`SWFRECOMP_JPEG3_DILATE=1`) gives a=0 texels their neighbours' mean colour: 325 → **127**
   (logo max diff 14/15). That is a diagnostic, not the fix. The exact fix is **premultiplied texture sampling for
   timeline bitmaps** in `render_webgpu.c`, which is renderer-wide and belongs to the bitmap slot.
3. Centring: Ruffle's centre offset is `Twips` integer `misalignment / 2` (`layout.rs` fixup_line); ours is float
   `remaining * 0.5f` (`tag.c` par_x_offset). An env-gated `TF_CENTER_TW=1` gives 127 → **121**.
4. Left over: ~107 logo channels (premultiplied sampling), 11 on the ring edge, ~3 glyph edges. Limit 3, so it stays a
   band.

**Completion mechanism:** premultiplied bitmap sampling (w1-pixel-bitmap) + the s23 text cx plumbing (wave 2 must
re-plumb `g_proto_tf_app`) + integer-twip centring + the ring edge (quality=low shape AA, unpriced). **The JPEG3
premultiply hunk is a Flash-correct rider to hand to w1-pixel-bitmap**: swept clean (all graded JPEG3/4 rows are
md5-identical except `acid-color-0`), −363 channels alone.

**1b. AVM2 twin.** Census of graded ABC SWFs (FWS/CWS; 3 ZWS skipped) that call `colorTransform` with a TextField, or
that hold DefineEditText or TextField under a cxform PlaceObject: the only hit is `from_shumway/acid/acid` (107 cx
placements, 18 comparisons all passing at 198/360). Its outliers (frame 1: 481 of 487 px > 64 sit at x 0–99 / y 450–549, the other 6 are scattered)
are on the white "Hello World" glyph and border edges over pink, and the **colours match**. The twin is **not latent**
in any graded row. It stays a correctness item (completion: compose the ancestor cxform into the box and glyph
colours in `avm2_render_textbox`).

---

## 3. `visual/static_text_offstage`: (a) and (b) are cheap, (c) is not

The current CI render (16016) has 3 defects. Cyan (drop shadow from below the stage) already matches.

| sub | defect | mechanism (owner) | price | measured |
|---|---|---|---|---|
| (b) | MAGENTA corner glyph at (0,0) missing | DefineText 2 is placed **twice at root** (depth 1 at (0,0), depth 2 at (396,296)). The root compose (`tag.c` ~7795, `renderer_compose_text_transforms`) writes the **character-shared** glyph slots `ch->transform_start+j` in place, so both instances draw at the last writer. The nested path got per-instance slots for Minesweeper (`tag.c:3719-3745`); the root path never did | **~20 LOC**: the same per-instance dynamic slot run + `text_glyph_overrides_push` | 16016 → 16000 |
| (a) | RED text drawn although its TextBounds are off stage | Flash culls static text on its **tag bounds** (generate.py docstring). We never cull | **~25 LOC**: in the root compose, transform the `ng_getCharBounds` box by the placement matrix; if it misses `[0,w*20]×[0,h*20]`, `render_single_object` skips the instance. **Filtered instances are exempt**, since the cyan shadow proves the cull uses filter-grown bounds; wave 2 should grow by the filter extent instead of skipping | 16000 → 9600 (the first attempt without the filter exemption also culled the cyan shadow, 12800) |
| (c) | YELLOW holder shows no text | AVM1 `BitmapData.draw` (`rasterizeMovieClipToBitmap`, `action.c:14533`) rasterizes **only drawing-API paths and child MCs**. A source MC's **timeline content** (DefineShape/DefineText in its display list) is never drawn, on or off stage | medium-large (~100–150 LOC CPU rasterizer of recompiled glyph/shape triangles + cxform + the sprite display list), or a GPU capture/readback | 9600 → 0 expected (the 9600 are exactly 2 × 40×40 blue × 3 ch) |

**Verdict:** HOLD for the flip (tol 2 / 0 outliers, so all three must land). (a)+(b) are real correctness fixes:
(b) is a game-visible bug, any reused root DefineText, the same class as the Minesweeper one. They could land with
the +2 at no flip; sweep 2 shows them md5-neutral on every other DefineText row. **Completion mechanism for (c):** an
AVM1 `draw()` timeline arm, which belongs to the bitmap slot (`w1-pixel-bitmap`) and probably affects more draw rows
than this one. Note that (a) is root-level only in the prototype. Nested static text, cacheAsBitmap and `draw()` need
their own viewport (Ruffle culls against the current render target).

---

## 4. `text-bind` and the zero-headroom text rows: NO-GO

- `text-bind` (t64 587/600, t128 85/100): the Fixed8 colour hunk moves 2984 channels by 1 and changes **no outlier**.
  The residual is device-font geometry (s23 §2: Ruffle's Levien chords from integer-truncated TTF points, which a
  finer flattening moves away from). Nothing in this family buys headroom without porting Ruffle's device-glyph build
  (`font_face.rs` `Twips::new(x as i32)` + lyon). s23 priced that at 0 flips, and it is still 0.
- `edittext_border_filters` (5 channels at exactly tol 32): md5-identical under this patch. Its tie channels are
  filter output, not glyph colour or layout.
- `fonts/embed_matching/fallback_preferences` (6/6, max 255): AVM2 text path, which this patch does not touch. The 6
  channels are glyph geometry at diff 255, not colour, so a Fixed8 port to AVM2 would not help it.
- Lead (unpriced): an **AVM2 twin of the Fixed8 glyph colour** (`avm2_text.c` / `avm2_display.c` glyph colour). It is
  invisible at today's tolerances. Only a tol-0 AVM2 row with a non-pure text colour would show it.

## 5. `definefont4`: NO-GO, s23 price stands

Re-checked at `df126b80`: the recompiler still has no tag-91 handler (no `DefineFont4` in `SWFRecomp/src`); the SWF has
two DefineFont4 tags plus the embedded TLF framework. No `avm2/textline_*` or `textblock_*` row has an
`[image_comparisons]` section, so the TextLine render path is still unchecked against any golden. One row at tol 1 /
0 outliers. **Completion mechanism:** a "DefineFont4 (CFF via the vendored `stb_truetype`) + TLF compose + TextLine
glyph render" mini-arc, funded only when a second FTE pixel row appears.
**Coordination with `w1-avm2-tail`:** the trace twin `avm2/textline_metrics` is theirs. Any TextLine metrics fix they
land (ascent/descent/textHeight) is a prerequisite for this row's layout but **not** sufficient (no CFF outlines). Nothing
in this patch touches AVM2/FTE, so there is no conflict.

---

## Wave-2 patch scope (GO items)

Files: `SWFModernRuntime/include/actionmodern/action.h` (trailing `TextFieldGlyphRun.font_id`),
`SWFModernRuntime/src/actionmodern/action.c` (`tf_run_leading_twips` + 2 call sites; per-run face in the run-table
producer; `font_id = 0` in the 5 other producers and the styled-run macro), `SWFModernRuntime/src/libswf/tag.c`
(`TF_RESOLVE_RUN_FONT` in `textfield_glyph_render_cb` measure and draw passes; Fixed8 glyph colour).
- Before/after: `br_at_start` 1672 → 4; `style_changes_in_html` 24998 → 0; `text-bind` unchanged outliers (max-1
  colour rider); every other swept row md5-identical.
- Optional same-slot riders (no flip): `static_text_offstage` (a)+(b) (`tag.c` root compose +
  `render_single_object`), 16016 → 9600.
- Hand to `w1-pixel-bitmap`: the JPEG3 premultiply hunk (`swf.cpp`, needs `--recompile`), plus premultiplied sampling.
- Strip the env-gated experiments (`SWFRECOMP_JPEG3_DILATE`, `TF_CENTER_TW`) before landing; they are diagnostics.
- Mode parity: the leading hunk is in shared `action.c` code (it feeds `_tf_leading`). Both headline rows pass
  no-graphics trace. No `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arm is touched (the cull check sits inside the
  existing `#ifndef NO_GRAPHICS` block).

## Prototype map (`w1-pixel-text-prototype.patch`)

| file | hunk | item |
|---|---|---|
| `action.h` | `TextFieldGlyphRun.font_id` (trailing) | 2b |
| `action.c` | `tf_run_leading_twips` + 2 sync sites | 2a |
| `action.c` | run-table producer face resolve; `font_id = 0` in other producers/macro | 2b |
| `tag.c` | `TF_RESOLVE_RUN_FONT` (measure + draw), `run_gbase`/`run_em`, Fixed8 glyph colour | 2b |
| `tag.c` | root-text per-instance glyph slots; `g_text_culled` bounds cull (filter-exempt) | 3 (a)(b) |
| `tag.c` | `TF_CENTER_TW` env-gated integer-twip centring (experiment) | 1 |
| `swf.cpp` | JPEG3/4 un-premultiply at emit; `SWFRECOMP_JPEG3_DILATE` env-gated dilation (experiment) | 1 |

## Refutations

1. **"Per-line max ascent/descent" owns `br_at_start` and `style_changes_in_html`:** refuted for both. All runs share
   one size. `br_at_start` is 533 → 520 leading truncation; `style_changes_in_html` is per-run embedded face + Fixed8
   glyph colour. "One mechanism?": no, two, and neither is the one named.
2. **"`acid-color-0` residual is a gradient":** refuted. The radial row is clean. The residual is JPEG3 alpha handling
   (premultiplied data emitted as straight), plus straight-alpha bilinear bleed, a ring edge and centre rounding.
3. **"AVM2 twin latent in `avm2_render_textbox`":** not latent in any graded row (census above).
4. **s23 "cyan text dropped" in `static_text_offstage`:** stale. Cyan matches today. The (b) defect is a shared-slot
   collision, not a corner-specific draw bug.

## New unclaimed leads

1. **AVM1 `BitmapData.draw` ignores timeline content** (DefineShape/DefineText in the source MC's display list):
   `static_text_offstage` (c). Likely other AVM1 draw rows too; grep for owners in the bitmap slot.
2. **Premultiplied sampling for timeline bitmaps** (JPEG3/lossless2 with alpha): `acid-color-0` logos; possibly other
   scaled/smoothed alpha bitmaps.
3. **JPEG3 premultiply at emit** (Flash-correct, swept clean): hand to the bitmap slot.
4. Per-line max metrics over mixed faces/sizes: correctness only, no graded row found.
5. AVM2 Fixed8 glyph colour twin: invisible at today's tolerances.
6. Root static-text culling for nested, cacheAsBitmap and `draw()` viewports; filter-grown cull bounds.
7. Integer-twip centre alignment (`misalignment / 2` on `Twips`) in the AVM1 renderer: 6 channels on `acid-color-0`.
   Check that it is md5-neutral elsewhere before landing.

## LOCAL ORACLE REQUESTS

None required.
