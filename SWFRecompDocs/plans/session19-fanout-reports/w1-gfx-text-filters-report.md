# w1-gfx-text-filters — wave-1 diagnosis: text, fonts, filters, colour (pixel axis)

Read-only. No source edits in the main tree, no commits. Evidence: PNG forensics on the
baseline CI images (`<scratchpad>/image-results/`, run `34645805030` @ `0ccafbc4e`), the Ruffle
exporter as a three-way oracle (`~/CC/ruffle` @ `0631814db`, built today), two local
`--mode=graphics --images` runs (`text/auto_size/{height,return}`), source reading in both
engines, and **one throwaway-worktree prototype** (device-font outline emission) run by a
sub-agent in `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-af491cbcaed487092`
(uncommitted; the main tree was never touched).
Scratch: `<scratchpad>/w1-gfx-text-filters/`.

---

## 0. Verdict board (lead with this)

| # | verdict | flips | comparison(s) | owner | LOC |
|---|---|---:|---|---|---|
| **G1** | **GO** | **+2** | `avm2/edittext_get_char_index_at_point` (22 849), `avm2/edittext_get_line_index_at_point` (18 403) | `avm2_text.c` `txt_get_{line,char}_index_at_point` | **~6** |
| **G2** | **GO** | **+1** | `avm1/define_font_glyph_table_order` (180, budget 4) | `SWFRecomp/src/abc/abc_timeline.cpp:1532-1536` | **~4** |
| **G3** | **GO (medium)** | **+2** | `text/auto_size/height` (6, budget 3), `text/auto_size/return` (21, budget 18) | `avm2_display.c` `avm2_render_textbox` `frac_bottom` block | ~10 |
| **A1** | **ARC — measured, and it does NOT flip anything at current budgets** | **0** | `visual/fonts/leading_device_font` 12 978 → **18**; `visual/fonts/device-font` 8205 → 13 065 (render correct, count up) | `abc_devicefont.cpp` (+110 new LOC) **+** A1s below | large |
| **A1s** | **GO (sub-lead of A1, independent)** | 0 alone | explains 100 % of `device-font`'s residual geometry | `avm2_text.c` `find_device_font_list` — device faces get no bold/italic ladder | ~15 |
| **H1** | HOLD | 0 (→ maybe +1) | `visual/edittext/edittext_border_filters` (827/17) | `tag.c` — EditText is structurally unrenderable inside a filter source | new surface |
| **N1** | **NO-GO, and the brief's premise is HALF WRONG** | 0 | `from_gnash/misc-ming.all/morph_test1` ×6 | frames 2-6 = run-edge ties; **frame 1 = a DEPTH-ORDER bug** | — |
| **N2** | **NO-GO — refutes the brief's pricing question** | 0 | AVM2 `.filters` chain defects | only carrier is `cab_mask_filters`, itself gated | — |
| **N3** | NO-GO (A-INHERENT, oracle-confirmed) | 0 | `from_shumway/{hardwrap,stylesheet,flash_text_TextField,captions}` (KF) | Ruffle is **farther** from Flash than we are on all four | — |
| **N4** | NO-GO | 0 | `from_shumway/acid/acid-text` (7683) | glyph **advance** drift, not fill or raster | — |
| **N5** | NO-GO | 0 | `acid-text-6` (198/12), `fonts/glyph` (3), `avm2/displayobject_opaque_background` (2) | 1-sample pixel-centre ties, tol 0-1 | — |

**Brief premises attacked: 4 refuted (N1 frame 1, N2, G3's "shared mechanism" identity, the
`same_geometry_wrong_fill` framing of the at-point pair), 3 confirmed (A1's "no outline source",
H1's structural HOLD, the filters-family residual is unchanged).**
Net priced: **+5 flips for ~20 LOC** (G1+G2+G3), and the headline device-font arc is
**refuted as a flip lead** while confirmed as a correctness arc.

---

## 1. G1 (+2) — the at-point probes ignore the line's LEADING. s18 §5.3's NO-GO is REFUTED.

s18 (`w1-gfx-text-report.md` §5.3) filed both `edittext_get_*_index_at_point` rows as
**NO-GO "until line/char metrics are exact"**, reading the `same_geometry_wrong_fill` cluster
label as "text metrics". The metrics are **fine**; the *probe* is wrong.

Ruffle (`core/src/html/layout.rs:906-920`, `find_line_index_by_y`):

```rust
if bounds.extent_y() + probe.leading() <= y { Ordering::Less }
```

Ours (`avm2_text.c:8386` and `:8581`) — **no `+ leading`**, in both probes:

```c
if (ly < l->lines[i].y + l->lines[i].h) return avm2_integer((int32_t) i);
```

`LLine.leading` already exists and is already populated (`avm2_text.c:3128`,
`line->leading = lc->max_leading`), and the selection-highlight code at `:3926` already
adds it. Only the two probes forgot.

**Quantitative fit.** `t1` of both fixtures is
`"a\n<font size='30'>aa</font>\n<textformat leading='-10'>aaa</textformat>\naa"` with
`tf.leading = 2` (`Test.as:104`). Line boundaries read off the colour maps (column x=40):

| boundary | ours | ours + `leading` | golden |
|---|---:|---:|---:|
| line 0 / 1 | 32 | 32 + 2 = **34** | 34 |
| line 1 / 2 | 64 | 64 + 2 = **66** | 66 |
| line 2 / 3 | 86 | 86 + (−10) = **76** | 76 |
| field bottom | 109 | clamped | 109 |

4/4 exact, including the negative-leading line. Every one of the 11 fields in the maps has
diffs, and in the char map (800×800, resolution 2) **every** differing pixel lies in a
horizontal band — 4-row bands (= 2 px = `leading`) plus larger ones where `leading='-70'` /
`scrollV` apply. **No column-only diffs at all**, i.e. the x/advance side is already exact.

**Second, smaller defect in the same pair:** `txt_get_char_index_at_point` never applies
`scrollV` (`ly = py - GUTTER`, no `et->scroll` term), while the line probe does and Ruffle's
char probe *delegates* to the line probe (`edit_text.rs:2350`). `t9` sets `scrollV = 3`.

* **Fix:** add `+ l->lines[i].leading` to both loops and route the char probe through the
  line probe (or copy its scroll term). ~6 LOC, one file.
* **Trace canaries a wave-2 must run:** `avm2/edittext_at_point_methods_basic` (16 lines,
  passes; declares no leading, so the change should be inert there),
  `edittext_get_line_index_of_char`, `edittext_autosize_lazy_bounds_{props,vs_relayout}`,
  `visual/edittext/edittext_device_transform_metrics`. Both target tests pass on trace today
  (2 and 4 lines) — this is a pixel-only move.
* **Confidence:** high on the mechanism, medium-high on "both reach 0 outliers" (both are
  `tolerance 0`; any surviving pixel fails). The bands are the *only* observed error, so the
  expected landing is 0.

---

## 2. G2 (+1) — the AVM2 glyph-offset table is assumed MONOTONIC

`avm1/define_font_glyph_table_order` (a v41 **AVM2** SWF living in the avm1 dir) has a
DefineFont3 whose glyph offset table is deliberately out of order: **`[29, 10, 64, 48]`**,
code table at 79, codes `a b c d`. `abc_timeline.cpp:1532`:

```cpp
uint32_t g1 = i + 1 < nglyphs ? glyph_offsets[i + 1] : code_table_off;
if (g1 <= g0 || offtab + g1 > body.end) continue;      // <-- drops glyphs 0 and 2
```

so glyphs `a` and `c` are **skipped entirely**. The render is missing exactly two narrow
glyph bars (180 outlier channels = 60 px; budget 4 at tolerance 5); everything else is
byte-exact. `parseGlyphShape` stops at the EndShapeRecord (`abc_timeline.cpp:934`), so the
`end` pointer is only a safety bound — the AVM1 path (`swf.cpp:2525`) already seeks to each
offset with no end bound and handles this correctly.

* **Fix:** make `g1` the *smallest offset strictly greater than* `g0` (or simply
  `code_table_off` / tag end). For a monotonic table this is the identical expression, so
  the blast radius outside the two carriers is zero.
* **Corpus scan (all 2848 SWFs in avm1, avm2, visual, text, fonts, from_shumway, from_gnash,
  timeline, swf, mixed_avm): exactly two SWFs have non-monotonic tables** —
  `define_font_glyph_table_order` (fails, 180) and `define_font_glyph_table_overlap`
  (offsets `[10, 29, 29, 29]` — **passes today at 0/4**). The overlap test is the required
  A/B: the fix makes its glyphs 1 and 2 parse (as Ruffle does), which could add ink.
  Grade both.

---

## 3. G3 (+2) — `text/auto_size/{height,return}` are a BORDER-corner rule, not glyphs

Local `--mode=graphics --images` reproduced CI exactly (6 and 21 outlier channels). Dumped
per pixel:

| test | residual | composition |
|---|---:|---|
| `text/auto_size/height` | **2 px** (6 ch, budget 3 ch = 1 px) | 1 border corner + 1 glyph px |
| `text/auto_size/return` | **7 px** (21 ch, budget 18 ch = 6 px) | **5 border corners** + 2 glyph px |

Every border pixel is the **bottom-right corner** of an EditText border box, e.g. at (275,128):

```
E ......#.....      A ......#.....     <- right edge
E ######......      A #######.....     <- bottom edge: ours runs 1 px too far
```

…but at (450,54) the polarity is **reversed** (Flash inks the corner, we do not). So it is
not a constant rule: it is the sub-pixel extent case that the existing comment in
`avm2_display.c:18325-18343` explicitly leaves unmeasured —
*"The fractional-WIDTH case is unmeasured; it is left drawing the full corner"*. The current
`frac_bottom` test only looks at `(by + bh)`.

`return` needs **one** pixel fixed to pass (21 → 18 ch is not `> 18`); `height` needs the one
corner (6 → 3 ch is not `> 3`). Both therefore flip on the corner rule alone; the two glyph
pixels can stay.

* **Required A/B:** `text/auto_size/width` passes today at **exactly** its 18-outlier limit
  and is the row the current heuristic was tuned on; plus all 20 `visual/edittext`
  comparisons and `avm2/edittext_autosize_height_dynamic` (the other golden the comment cites).
* Ruffle's two painters are `draw_device_text_box` (4 lines, *bottom-right corner missing by
  design*) and `draw_text_box` (`draw_line_rect` + `EditTextPixelSnapping`,
  `edit_text.rs:2855` / `:2940`). These fixtures are embedded-font, so the second one.

---

## 4. A1 — device fonts: the arc is REAL, CHEAP and FLIPS NOTHING at today's budgets

### 4.1 The inventory (every graded comparison whose pixels depend on a device/default font)

Scan of all 215+ graded comparisons for `[fonts.*]` / `with_default_font` / `[default_fonts]`
/ device EditTexts / zero-glyph named fonts:

| source of outlines | comparisons | status |
|---|---|---|
| `[fonts.*]` TTF, AVM2 | `visual/fonts/device-font` 8205 (tol 0, max 3), `visual/fonts/leading_device_font` 12 978 (tol 128, max 0), `visual/edittext/edittext_device_transform_negative` 1017 (**KF**) | the A1 prototype below |
| `with_default_font` (Ruffle's bundled Noto), AVM2 | `visual/fonts/font_lookup_as3` 34 632 (max 72), `avm2/bitmapdata_applyfilter_colormatrix` 7419 (tol 2, max 0), `avm2/bitmapdata_applyfilter_blur` 28 871 (**DISPOSITIONED**), `avm2/bitmapdata_draw` (text is a **rider**: 1203 of 24 578 at tol 128) | needs the same emitter pointed at `SWFRecomp/assets/NotoSans.ttf` |
| zero-glyph named `_sans` in an **AVM2** SWF (AVM1 already synthesises these) | `from_shumway/hardwrap` (KF), `from_shumway/MaskTest-2` (KF) | §5 says price 0 |
| `[fonts.*]`, **AVM1** (unimplemented — `emitDeviceFonts` is called only from `abc_timeline.cpp`) | `from_shumway/avm1/text-bind` (dispositioned), `visual/cache_as_bitmap/text` (passes at 10 233/12 000) | unclaimed |

**`SWFRecomp/assets/NotoSans.ttf` is byte-identical (md5 `994ff225…`) to Ruffle's bundled
`core/assets/notosans.subset.ttf.gz`** — verified by decompressing the raw-deflate blob. So the
default-font slice has an exact oracle already sitting in the repo. (Note the runtime's baked
`noto_device_font` in `avm2_text.c:2528` is an *approximation* — em 20480, ascent 21931 vs the
real 1069/1000 — and is metrics-only.)

**`avm2/bitmapdata_applyfilter_colormatrix`'s 7419 outliers are 100 % the missing default-font
text** (rows 91-104, 311-319, 531-539; every other channel is inside its tolerance of 2) — a
clean one-mechanism row and the best *flip* candidate in the default-font slice.
Note the consequence: landing default-font outlines would also invalidate the scope of the
`avm2/bitmapdata_applyfilter_blur` ACCEPTED_DIFFS entry (whose stated residual *is* that text).

### 4.2 The prototype (measured, worktree, local Dawn A/B)

`abc_devicefont.cpp` gained real `stbtt_GetGlyphShape` contours → `glyph_pts` /
`glyph_pt_start` / `glyph_contour_ends` / `glyph_contour_start`, y-negated, truncated to int
(Ruffle `font_face.rs` `GlyphToDrawing`), flattened with the same Levien schedule
`abc_timeline.cpp` uses, capped at codepoint 0x2FF. **The runtime needed no change at all**
(`avm2_text.c:4056` already prefers the face's own outlines; the s18 A1b borrow just stops firing).

| comparison | budget | before | after | verdict |
|---|---|---:|---:|---|
| `visual/fonts/leading_device_font` | tol 128, **max 0** | 12 978 | **18** (6 px) | −99.86 %, still FAIL |
| `visual/fonts/device-font` | tol 0, **max 3** | 8205 | **13 065** | render goes blank → correct, count RISES (see 4.3) |
| `fonts/device_font_kerning` | tol 0 | 0 PASS | **0 PASS** | no regression |
| `visual/edittext/edittext_device_transform_negative` (KF) | — | 1017 | 1017 | byte-identical (it was already on the A1b borrow) |

Cost: **+110 net new LOC** (plus ~110 copied from `abc_timeline.cpp`'s Levien block — hoist it
instead), **+0.14 s** recompile, and **+213 KB of generated C** for two 95-glyph Tinos faces
(~1.1 KB/glyph). The tolerance is scaled as `2.0 * em / 20480` (≈1e-4 em) which is far tighter
than needed at text sizes — loosening it is the size lever, and the 0x2FF cap is load-bearing
for any full BMP face.

**Pricing verdict: the count-based budgets do not move.** `device-font` is `tolerance 0 /
max_outliers 3` on a 1-bit (quality=low) golden, so *any* per-pixel glyph disagreement fails;
`leading_device_font` is `max_outliers 0` and lands 6 px away. **A1 is a correctness/band arc,
not a flip arc** — that is the direct answer to the brief's "size it / what is the smallest
slice" question, and it refutes the s18 framing that treated A1 as "up to +3 pixel rows".

### 4.3 A1s — one runtime bug explains 100 % of `device-font`'s remaining geometry

With outlines present, `device-font` renders Tinos at exactly the right x positions, advances,
kerning and glyph size — but **every line sits low** (line 1 +5 px, line 2 +8 px; line-to-line
33 px in the golden vs 36 px in ours) and the `<i>Abc</i>` run is **missing entirely**
(2607 of the 13 065 channels).

Both come from ONE place. `resolve_font` applies Ruffle's 4-step bold/italic ladder **only to
embedded faces**; `find_device_font_list` → `find_device_font` demands an exact
`(name, bold, italic)`. Ruffle uses the *same* `FontMap::find` ladder for device faces
(`library.rs:524` and `:591` both call `find`). `test.toml` declares only regular + bold Tinos,
so the italic run misses, lands on the metrics-only baked Noto, draws nothing — **and inflates
line 1's `max_ascent`/`max_descent`**:

* Tinos (em 2048, ascent 1825, descent 443 — exactly what the recompiler emits, and exactly
  ttf_parser's ladder) at size 30 px → ascent 534 tw = **26.7 px**, line box 663 tw = **33.15 px**
  = the golden's 33 px spacing.
* Baked Noto (em 20480, ascent 21931) at size 30 px → ascent 642 tw = **32.1 px**, i.e.
  **+5.4 px** — the measured "+5 px low" on line 1 — and a taller line box, i.e. the measured
  "+8 px" on line 2.

So the "device-face vertical metrics need reconciling with Ruffle" reading is **wrong**: the
emitted metrics are already Ruffle's. ~15 LOC (reuse the ladder already written 20 lines above
it) fixes the missing run *and* the line geometry. Worth doing on its own: it is a live
correctness bug for any content whose device family lacks an italic/bold face.

---

## 5. N3 — the KF Shumway text rows are A-INHERENT (exporter oracle)

Rendered each with `~/CC/ruffle/target/release/exporter` (which logs
`Unknown device font "Arial"/"Noto Sans"` and draws nothing) and compared three ways against
the **Flash** `output.expected.png`:

| test | us-vs-Flash | us-vs-Ruffle | Ruffle-vs-Flash |
|---|---:|---:|---:|
| `from_shumway/hardwrap` | 976 | 981 | **1524** |
| `from_shumway/captions` | 2116 | 1091 | **2469** |
| `from_shumway/flash_text_TextField` | 260 | 196 | **371** |
| `from_shumway/stylesheet` | 958 | 1075 | **1679** |

Ruffle is **farther from Flash than we are on all four** — the goldens are Flash's own system
font raster and no test datum contains those outlines. Price 0, permanently; they are
image-axis ACCEPTED_DIFFS candidates (a 4-row entry with an `<!-- image-axis: ... -->` marker),
not device-font-arc carriers. `acid-text-4` (51 678) and `acid-textfield` (15 754), also KF,
are the same family with a ~1-row vertical drift on top (best vertical shift −1 px reduces
`acid-textfield`'s ink XOR from 1910 to 1570).

---

## 6. N1 — `morph_test1` ×6: the text side priced, and frame 1 is NOT a tie

**100 % of the graded outliers in all six frames are in rows 2-10** — the Ming
`- xtrace enabled -` status bar. The morph geometry is entirely inside tolerance 5
(w1-gfx-geometry's claim confirmed on the pixels).

* **Frames 2-6: 62 px each** (186 ch), pure 0/255 values, 34 missing + 28 extra, and **no
  global shift improves the XOR** (dx=dy=0 is the minimum). This is the 1-sample
  pixel-centre coverage tie on an AVM1 embedded font (Bitstream Vera Sans, `tag.c` /
  `shape_data` pipeline) — s18's N1 class. Budget is 0 outliers → **NO-GO**.
* **Frame 1: 211 px, and it is a different bug.** The golden shows a solid 100×100 red square
  (the morph at depth 2) covering the status text: 12 black px in rows 0-15. We draw 223 —
  the text is painted **over** the shape. The SWF places the text's sprite at **depth 1** and
  the morph at **depth 2+**, so Flash/Ruffle are right. Cause, in code:
  `tag.c:6859-6866` paints "fields inside sprites, createTextField fields and orphans" in a
  **trailing `TF_WINDOW_REST` pass after the whole display-list walk**, i.e. above every
  root-depth object. **Fix flips nothing here** (frame 1 would fall back to the ~62 px tie),
  so this is a correctness lead — but it is the *same* missing capability as H1 (§7).

---

## 7. H1 — `edittext_border_filters`: the s18 HOLD is structurally confirmed, and priced

`render_single_object` (`tag.c:3746`) explicitly `break`s for `CHAR_TYPE_TEXT` whenever
`ng_getCharTextfieldIdx(obj->char_id) >= 0` (and `render_display_list` repeats the skip at
`:4442`), because EditTexts are painted by the later `actionIterateTextFieldGlyphs` pass. The
filter path snapshots its source by re-rendering a single object — so a PlaceObject3 filter on
a DefineEditText has **nothing to filter**: not the glyphs, not even the border (827 outliers,
budget 17 at tol 32; s18 measured 280 missing ink px of *filtered border*).

**Completion mechanism (shared with §6):** an entry point that paints ONE EditText (box +
border + glyphs) at an arbitrary point in the render walk, callable (a) from
`render_single_object` when the object is inside a filter/offscreen source, and (b) at the
field's own depth during the walk. That single surface closes the depth-order bug, unblocks
filtered EditTexts, and is a prerequisite for — but not sufficient for — a flip here (the blur
geometry must then also match). **Priced: 1 comparison, flip NOT guaranteed, new surface.**

---

## 8. N2 — the AVM2 `.filters` chain defects move NOTHING gradeable (refutation)

The brief asks which comparisons the two s18 defects
(`avm2_render_filtered` computes `draw_source_after` from the LAST filter; its `colorize`
shortcut drops a non-final composite source) move. Scanned every graded comparison's AS for
filter use:

* The corpus's AVM2 multi-filter DisplayObject rows are `visual/filters/blur_pass_scaling`
  and `visual/filters/glow_pass_scaling` — **both PASS today** (0 outliers), including the
  glow one whose entries all composite their source (tolerance 100 hides it).
* The only failing graded comparison with a multi-filter AVM2 list is
  `visual/cache_as_bitmap/cab_mask_filters` (612, budget 0 at tol 4) — two `DropShadowFilter`s
  **on a mask**, i.e. it needs the compose-into-offscreen pipeline that already HELD s18's
  `acid-filter-2`, on top of cacheAsBitmap-mask semantics.
* Everything else in the family is the AVM1 tag route (`visual/filters/*` bevel/glow/
  drop_shadow are AVM1 SWFs with `_sans` device text, `with_default_font`).

**So: 0 priced flips; the two defects are correctness-only.** The filters-family residual is
otherwise **unchanged** since s18 (`acid-filter` 482, `acid-filter-2` 2986, `blur_size_grows`
6386 — all exactly the s18 closing numbers), and the `visual/*` filter stems have not been
re-run since s18's `33945288707`, so no filters row could have moved.

Two colour rows characterised while here:
* `avm2/bitmapdata_draw_filters` (KF, "global_color_shift"): the whole 180×80 block is
  **expected `(255,255,0)` vs ours `(255,0,255)`** — a G↔B channel swap in the filtered
  `BitmapData.draw`, not a shift. Price 0 (KF) but a crisp, cheap-looking mechanism.
* `from_shumway/acid/acid-color-0` (17 386, budget 3): expected GREEN where we paint WHITE
  (2551 px) or RED (780 px) over 9172 px — colour *selection*, structural, not a near-pass.
* `avm2/displayobject_opaque_background` (2 channels!): **one pixel** at (133,5) on the
  diagonal edge of a red shape over a blue opaque background — a 1-sample edge tie at
  tolerance 1. NO-GO despite being the closest row on the board.
* `avm2/blend_shader_luma_lighten` (1237) is a Pixel Bender **shader** row — handing to
  w1-gfx-stage3d, not a text/colour lead.

---

## 9. N4/N5 — the remaining briefed text rows

* **`from_shumway/acid/acid-text` (7683, tol 0, non-KF).** Per-block ink XOR: 505 / 648
  (best at dx=−1) / 1302 px. Zoomed, "Hello World" is correct through `Hello W` and then
  drifts ~1 px left across `orld` — a **glyph advance accumulation** difference, not a fill
  or a raster tie. `tolerance 0` → NO-GO; same axis as `style_changes_in_html`.
* **`acid-text-6` `[output]` 66 px / `[frame5]` 4 px** — pure 0/255 run-edge ties confined to
  rows 476-565, cols 500-570. NO-GO at tol 0.
  **Refutation of a standing memory:** `acid-text-6` and `acid-text-escape` are **AS3-flagged
  SWFs with NO DoABC tag at all** (verified by tag dump), which is why s18's `parseGlyphShape`
  patch left them byte-identical. The `avm2-two-glyph-pipelines` memory's rule of thumb
  ("check `swf_is_avm2.py` first; AVM2 text = `glyph_pts`") mis-routes them — the real
  discriminator is *whether the SWF carries ABC*, not the FileAttributes flag.
* **`visual/fonts/glyph`** — 3 channels (1 px) at tol 0. Unchanged from s18; the completion
  mechanism is still the tessellator boundary rule (libtess2 CDT vs lyon) on a straight edge
  both engines agree about geometrically. **Refuting or paying for that is a tessellator
  swap, not a one-liner** — do not price it as a flip.
* **`from_shumway/{hardwrap,stylesheet,flash_text_TextField}`** — see §5.

---

## 10. Disposition check (standing rule 2)

Grepped `ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, the global `ruffle-tests/ignored_tests.txt` and every per-suite
list for all 40 comparisons above. Hits: `avm2/bitmapdata_applyfilter_blur` (image-axis,
scoped — see §4.1 for why the A1 arc would invalidate its scope), `from_shumway/avm1/text-bind`
(image-axis, "device-font file mismatch" — **the claim is re-testable**: its `test.toml` ships
its own 1024-em `NotoSans.ttf`, which our AVM1 path cannot read at all since `emitDeviceFonts`
is AVM2-only; an AVM1 `[fonts.*]` implementation is the completion mechanism, not a permanent
gap). No other briefed row is dispositioned. No upstream drift observed: every briefed test is
present on disk and in its suite's `image_results_graphics.json`.

---

## 11. Reproduction

```bash
S=<scratchpad>/w1-gfx-text-filters
python3 $S/swfinfo.py   <testdir> ...     # AVM1/AVM2, [fonts.*], device EditTexts, font table
python3 $S/fontorder.py <swf> ...         # non-monotonic glyph offset tables
python3 $S/devscan.py                     # every graded comparison that depends on a device font
python3 $S/sbs.py  expected actual out.png [x0 y0 x1 y1] [scale]   # side-by-side + diff mask
python3 $S/outl.py expected actual TOL    # outlier channels + differing row runs
export SWFRECOMP_COMPILE_TIMEOUT=2400
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/text \
    --test=auto_size/height --mode=graphics --images --image-out-dir=$S/imgs --verbose
```
Local `--mode=graphics` reproduced the CI outlier counts **exactly** on every row measured
(`auto_size/height` 6, `auto_size/return` 21, and all four A1 baselines), so local Dawn is not
a confound for this family.

---

## 12. New unclaimed leads

1. **`visual/text/String_path_variable_button` (996, budget 12)** — AVM1 v6, `with_default_font`
   + a zero-glyph `_typewriter`, i.e. our NotoSans synthesis vs Ruffle's bundled Noto (the same
   file). In nobody's brief; the font source is identical on both sides, so the residual is
   pure metrics/placement and should be cheap to chase.
2. **AVM1 has no `[fonts.*]` support at all** (`emitDeviceFonts` is called only from
   `abc_timeline.cpp:2263`). Carriers: `from_shumway/avm1/text-bind` (dispositioned),
   `visual/cache_as_bitmap/text` (passes with 10 233/12 000 head-room). The AVM2 emitter is
   reusable as-is once A1 lands.
3. **`avm2/bitmapdata_draw`'s text is a rider, its real blocker is the `clipRect`/ellipse**
   (37 196 of 39 803 outliers at tol 0 are the un-clipped red ellipse) — geometry sibling's row.
4. **`visual/edittext/edittext_gutter` (1032)** and **`text/br_at_start` (3691)** are still
   unclaimed (s18 §5.1/§5.2 characterised both; neither is in a session-19 brief).
5. **`avm2/bitmapdata_draw_filters`'s G↔B swap** (§8) — KF, so unscored, but it is a
   one-mechanism bug in the filtered `BitmapData.draw` path.
6. **The trailing `TF_WINDOW_REST` text pass** (§6) is a general depth-order defect for every
   sprite-nested or script-created TextField, not just `morph_test1` — a real-content
   correctness issue (browser/game rendering) with only one corpus witness.
7. **`avm2_text.c`'s baked `noto_device_font` is an approximation** (em 20480 / ascent 21931)
   of a font we ship byte-exactly at `SWFRecomp/assets/NotoSans.ttf` (em 1000 / ascent 1069).
   Every `with_default_font` layout number rides on it. Replacing it with generated metrics
   from the real file is trace-visible, so it needs its own A/B — but it is the correct
   oracle and it is already in the repo.
