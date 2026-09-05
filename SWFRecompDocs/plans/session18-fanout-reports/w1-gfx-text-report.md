# w1-gfx-text — wave 1 diagnosis: pixel failures in the text family

Read-only session. No source edits, no commits. Evidence is a mix of PNG forensics on the
baseline image run (`65915386558b`, run `33857494837`) and **live gdb instrumentation of a
locally built `--mode=graphics` binary at HEAD `8f68a5fea`** (`SWF_KEEP_BUILD_DIR`).
Scratch: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-gfx-text/`.

---

## 0. Verdict board (lead with this)

| # | verdict | flips | comparison(s) | owner file(s) | LOC |
|---|---|---:|---|---|---|
| **G1** | **GO** | **+1** | `visual/edittext/edittext_bounds_vs_position` | `SWFModernRuntime/src/libswf/shape_hit_test.c` (or `action.c` `getLocalMatrixForMC_render`) | **1–8** |
| **G2** | **GO** | **+1** | `visual/edittext/edittext_underline` | `action.h` + `action.c` (`TextFieldGlyphRun`), `avm2_display.c`, `tag.c` glyph cb | ~80–150 |
| **H1** | HOLD (needs G2) | +1 with G2 | `visual/edittext/edittext_underline_scale2` | `SWFModernRuntime/src/avm2/avm2_display.c:17264-17472` | ~20 |
| **H2** | HOLD | +1 | `text/br_at_start` | HTML line layout (`action.c` `tf_parse_html` / line builder) | unknown |
| **A1** | ARC (real, tooling already vendored) | up to +3 pixel rows | `visual/fonts/device-font`, `visual/fonts/leading_device_font`, `fonts/device_font_kerning` | `SWFRecomp/src/abc/abc_devicefont.cpp` + glyph tables | large |
| **A1b** | GO-ish sub-lead of A1 | +1 (cheapest of A1) | `fonts/device_font_kerning` only | device-font→embedded-font name fallback | small |
| **N1** | NO-GO (as framed) | 0 | the whole `a_epsilon` near-pass cluster (8 tests) | glyph raster tie | — |
| **N2** | NO-GO | 0 | `text/style_changes_in_html`, `avm2/edittext_get_{line,char}_index_at_point` | text layout metrics | — |
| **P** | price-only (`known_failure`) | 0 | `flash_text_TextField`, `stylesheet`, `hardwrap`, `captions`, `acid-text-4/5`, `acid-textfield`, `edittext_device_transform_negative` | — | — |

**Brief premises attacked and REFUTED: 2** (§1.4, §3.2). **Confirmed: 1** (§3.1).

---

## 1. G1 — `edittext_bounds_vs_position` (+1). The s17 completion mechanism is REFUTED; the real cause is a stale `transform_id`.

### 1.1 The failure
50×50, `tolerance 0` (all-or-nothing). CI 519 outlier channels = 173 px; reproduced locally at
HEAD as **522 / 174 px** (lavapipe-vs-Dawn ±1 px, not drift). The fixture is 3 `DefineEditText`
chars placed at root depths 1–6 **and the same six again inside `DefineSprite` char 4**, which is
placed at root depth 7 with a translate of `(0, +500)` twips = **25 px down**. Our render is
byte-exact for rows 0–20 (the root half) and **completely blank for rows 25–45** (the sprite half).

*(The single stray pixel at (25,0) in the CI PNG is a lavapipe artefact — the local Dawn render has
no ink at all below row 20.)*

### 1.2 s17's proposed completion is refuted
`session17-fanout-reports/w2-gfx-edittext-bg-report.md` §7.1 and `graphics-fanout-playbook.md` §16
both say the residual is *"a sprite-nested `DefineEditText` never reaches the box/glyph passes"*,
completion mechanism *"extend the render_self treatment into `render_display_list`'s sprite walk
with a **parent-scoped window**… and confirm a wrapper MovieClip is created for sprite-nested fields
that no script ever names."*

Every clause of that is false. gdb dump of `child_mc_cache` at the first `tagShowFrame`
(`gdb11.txt`, 13 entries — 6 root fields + 1 sprite + 6 nested fields):

```
[6]  mc=0x…00e0 par=root       depth=-16377 tfidx=-1 vis=1 x=0  y=25 w=0  h=0   name=instance7   <- the sprite
[7]  mc=0x…0860 par=0x…00e0    depth=-16383 tfidx=0  vis=1 x=0  y=0  w=5  h=5   name=instance8
[8]  mc=0x…2100 par=0x…00e0    depth=-16382 tfidx=1  vis=1 x=0  y=0  w=10 h=10  name=instance9
...
[12] mc=0x…ad80 par=0x…00e0    depth=-16378 tfidx=2  vis=1 x=25 y=0  w=5  h=10  name=instance13
```

* The wrappers **already exist**, with the **sprite MC as `parent`** and correct sprite-local
  depths, `ng_textfield_idx`, `visible`, `dynamic_props`, and local `x/y/w/h`.
* `tf_window_skip` in `TF_WINDOW_REST` therefore returns 0 for them (`rooted` needs
  `mc->parent == &root_movieclip`) — **the existing REST window already covers them**; no new
  window mode is needed.
* `actionIterateTextFields` **is** called with `g_tf_window_mode == 2` once per render
  (breakpoint on the mode, `gdb16.txt`), and **emits zero boxes**.
* `actionIterateOrphanTextFields` → `otf_walk_dl` **does** recurse into the sprite with the correct
  parent translation (`ptx=0 pty=25`) and calls `otf_find_child_mc` for all six nested entries; it
  emits nothing only because the wrappers exist (which is correct behaviour).
* All twelve `textfield_render_cb` hits in the whole run come from `tf_draw_at_root_depth`
  (6 in `tagShowFrame`, 6 in `tagRerenderFrame`) — i.e. only the root six, twice.

### 1.3 The real mechanism (proven)
Inside the REST loop the nested fields reach **every** property read
(`background`, `backgroundColor`, `border`, `borderColor`, `_tf_visualOffX/Y`, `embedFonts` —
observed with a conditional breakpoint on `getProperty`, `gdb19.txt`), and their values are
identical to the root fields' (`border` = BOOLEAN true, `embedFonts` = BOOLEAN false).
The **only** gate after `embedFonts` is Ruffle's device-font cull
(`action.c:27832` `tf_transform_positive_scale_only`, `a > 0 && d > 0`).

Calling `getLocalMatrixForMC_render` from gdb at two different moments (`gdb15.txt` vs `gdb20.txt`):

```
at tagShowFrame entry :  mc7(nested) a=1.000000 b=0 c=0 d=1.000000 tx=0 ty=0
during the REST pass  :  mc7(nested) a=40082358665216.0 b=0 c=16175299821568.0 d=0.0 tx=-2147483648 ty=0
                         mc6(sprite) a=1.000000 b=0 c=0 d=1.000000 tx=0 ty=500     <- root entry, still fine
                         mc0(root TF) a=1.000000 b=0 c=0 d=1.000000 tx=0 ty=0      <- root entry, still fine
```

`d == 0` → the cull fires → `continue` → all six nested fields are dropped.

Root cause chain:

```
tf_world_matrix (action.c:27802)
  -> getLocalMatrixForMC_render (action.c:9245)
       -> ng_getMatrixFromObj_render (shape_hit_test.c:41)
            u32 tid = obj->transform_id;                  <-- LIVE id
            float (*td)[16] = ng_entryTransformData(obj); <-- right TABLE, wrong INDEX
```

`compose_children` rewrites a **child** display entry's `transform_id` to a dynamic GPU slot during
the render frame; that slot has no CPU-side row, so the read is out of range. The file already
knows this — `otf_walk_dl` (`action.c:28988-29000`) carries the comment *"Use the original
(pre-`compose_children`) `transform_id` — `compose_children` rewrites `obj->transform_id` to a
dynamic GPU slot during the render frame, which has no corresponding entry in the CPU-side
`transform_data` array"* and calls `ng_get_original_transform_id(obj)`. `ng_getMatrixFromObj_render`
does not. This is the memory-note family `[child-xform-table]` / `[render-tables]`, one call site
short.

Root display-list entries are unaffected (`mc0`, `mc6` above), which is exactly why the defect is
invisible except when an EditText lives inside a sprite.

### 1.4 Fix, pricing and blast radius
**Minimal fix:** `u32 tid = ng_get_original_transform_id(obj);` in `ng_getMatrixFromObj_render`
(1 line). **Blast radius warning:** that function is in `shape_hit_test.c` and is also used by
AVM1 shape hit-testing, which runs in `NO_GRAPHICS` too — so a wave-2 agent should either

* (a) take the 1-line change and grade the trace axis in **both** modes plus the `regression`
  hit-test tests, or
* (b) self-localize: resolve the original id inside `getLocalMatrixForMC_render` only (≈8 lines,
  zero effect on hit testing).

Prefer (b) for a first landing; (a) is the correct long-term shape but is a trace-axis change.

**Priced: +1** (`edittext_bounds_vs_position`, `tolerance 0`). Confidence high — the sprite half is a
pure 25-px translate of the root half, and the root half is already byte-exact.
**Unpredicted riders are plausible** wherever a bordered/background EditText sits inside a sprite:
`from_shumway/{flash_text_TextField,stylesheet,hardwrap}` all render *nothing at all* (ink IoU 0.00,
missing-ink 1.00) and should be re-measured after the patch — but all three are `known_failure`, so
they are band moves, not scored flips.

**Canaries:** `visual/edittext/edittext_border_transform` (6 cmps, tier 1) + the 20-test
`visual/edittext` sweep + the `regression` suite (mandatory: the change is inside the shared
matrix accessor).

---

## 2. G2 — underlines are never drawn anywhere (+1), and H1 — the AVM2 box border is in stage pixels

### 2.1 `visual/edittext/edittext_underline` — 682 differing px, 13 rows, all underline
Full-resolution row dump (`prof.py`, then a raw row print) — the differing pixels occupy exactly
13 rows and nothing else:

```
rows: 21:80  43:80  57:92  65:20  95:16  117:4  119:92  137:32  181:92  211:26  243:92  265:52  298:4
row 20 E ..###########....................###########..... (glyph, MATCHES)
row 21 E ..###########..#################################  <- the underline
row 21 A ..###########....................###########.....  <- we draw the glyph only
row 43 E ..###############################################  <- full-width underline
row 43 A ..###########....................###########.....
```

We draw **no underline at all**. Code proof, both VMs:

* AVM1: `SWFModernRuntime/include/actionmodern/action.h:826-838` — `TextFieldGlyphRun` carries
  `byte_start / byte_length / color / font_height / align / bullet` and **no `underline`**, so the
  flag the parser already tracks (`action.c:26498`, `r->underline`) never reaches the renderer.
* AVM2: `SWFModernRuntime/src/avm2/avm2_bitmap.c:1898-1900` states outright
  *"Border/background/underline and device-font text (no outlines) are not rendered"*.
* `grep -rl underline SWFModernRuntime/src/` matches only `action.c`, `avm2_text.c`,
  `avm2_bitmap.c` — **zero** hits in `tag.c`, `render_webgpu.c`, `avm2_display.c`.

`edittext_underline` and `edittext_underline_scale2` are the **same SWF**
(`md5 55f07c67…`, SWF v41 → AVM2), rendered at two viewports.

### 2.2 Ruffle's geometry (implement exactly this)
`~/CC/ruffle/core/src/display_object/edit_text.rs`:

```rust
// :1318-1329, per layout box
if let LayoutContent::Text { underline: true, .. } = lbox.content() {
    let underline_y     = ascent + (max_descent / 2);
    let underline_width = lbox.bounds().width();
    self.render_underline(context, underline_width, underline_y, color);
}
// :1365-1378
fn render_underline(...) {
    let mut underline = context.transform_stack.transform().matrix
        * Matrix::create_box_with_rotation(width.to_pixels() as f32, 1.0, 0.0, Twips::ZERO, y);
    EditTextPixelSnapping::new(context.stage.quality()).apply(&mut underline);
    context.commands.draw_line(color, underline);
}
```

Key points a wave-2 agent must not get wrong: the underline is a property of the **layout box**
(not of a character run), it spans the **layout box width** (not the ink width), its y is
`ascent + max_descent/2` in box-local space, its thickness is **1 pixel** (a `draw_line`, i.e.
`emulate_line_as_rect` — the same "thickness is not transformed" rule the AVM2 border painter
already implements at `avm2_display.c:17326`), and it is pixel-snapped by stage quality.

### 2.3 Pricing — and the honest caveat
`edittext_underline` checks are `tolerance 0 / max_outliers 16` **and** `tolerance 144 /
max_outliers 0`, i.e. near-exact. In its favour: the test fonts are rectangle test fonts on white,
and every differing pixel today is a hard 0-vs-255 run, so there is no antialiasing to match.
**Priced +1, medium confidence.**

`edittext_underline_scale2` is **NOT** a second flip from G2 alone — attack that pricing:
of its 9264 differing pixels only ~1400 are underline rows; ~7900 are the **field border drawn one
device pixel too thick** at the zoomed viewport:

```
viewport_dimensions = { width = 1800, height = 600, scale_factor = 1 }   (stage is 900x300)
row   3  E ..#.......      A ..##########   (top border: Ruffle 1 device px, ours 2)
row 597  E (blank)         A ..##########   (bottom border: we paint an extra device row)
col   2  E border          A cols 2 AND 3   (594 rows of a 2-px-wide left border)
```

`avm2_display.c:17264-17472` computes the whole EditText box in **stage twips** with literal `20.0`
thicknesses. At an 1800×600 viewport over a 900×300 stage, 20 twips = **2 device pixels**; Ruffle
seeds its `transform_stack` with the stage view matrix, so its 1px is 1 **device** pixel. This is
precisely s17's sub-mechanism (A3), which was applied to the AVM1 `textfield_render_cb` and never to
the AVM2 painter. Fix pattern is already written down in
`session17-fanout-reports/w2-gfx-edittext-bg-report.md` §3 (A3): derive `dscale =
context->stage_scale` and express thickness/snapping grid as `20/dscale` stage twips.
**`edittext_underline_scale2` flips only when G2 and H1 both land.**

Corpus scan for other carriers of H1: the only text tests with a stage-mismatched viewport are
`edittext_{background,border}_basic_scale2` (AVM1, already fixed by s17),
`edittext_underline_scale2`, and `avm2/edittext_get_char_index_at_point` (800×800 over a 400×400
SWF — but its residual is the index map, §5.3, not the border). So **H1 has exactly one pixel
carrier today**; its value is the one flip plus not re-introducing the bug in browser/zoom builds.

---

## 3. Device fonts — one brief premise CONFIRMED, one sub-lead that avoids the whole arc

### 3.1 CONFIRMED: there is no outline source (and the rasteriser is already vendored)
`SWFRecomp/src/abc/abc_devicefont.cpp` (398 lines) reads the `[fonts.*]` TTFs named in `test.toml`
and emits **`codes`, `advances`, kern pairs and vertical metrics only** — no contours. Our render of
`visual/fonts/device-font` is literally blank where the golden has two full lines of text
(`ink_frac_actual` 0.00, `missing_ink_frac` 1.00, 8205 outliers).

The useful new fact for pricing: `abc_devicefont.cpp` **already includes and links
`stb_truetype.h`** (it uses it for advances and cmap). `stbtt_GetGlyphShape` returns exactly the
contour data the arc needs, so the work is "emit glyph contours into the recompiled glyph path
table and route device-font text at them" — not "acquire a font rasteriser". That materially
lowers the arc's cost estimate versus §16's framing.

Rows in the arc, with their **distinct** sources (do not conflate them):

| comparison | outliers | source of outlines |
|---|---:|---|
| `visual/fonts/device-font` | 8205 (budget 3) | `[fonts.*]` TTF (Tinos regular + bold) |
| `visual/fonts/leading_device_font` | 12978 (tol 128) | `[fonts.*]` TTF (TestFontGap0/100) |
| `fonts/device_font_kerning` | 1680 (tol 0) | `[fonts.*]` TTF — **but see §3.3** |
| `visual/fonts/font_lookup_as3` | 34632 (max_out 72) | **Ruffle's built-in default font** (`with_default_font = true`) — a *different* source |
| `visual/definefont4` | 16086 (tol 1) | **DefineFont4 / CFF** — a *third* source, nothing to do with `[fonts.*]` |
| `visual/edittext/edittext_device_transform_negative` | 2649 | `[fonts.*]` TTF — **`known_failure = true`, price only** |
| `visual/cache_as_bitmap/edittext_scroll` .01/.02 | 566/570 | `with_default_font = true` (same source as `font_lookup_as3`) |

### 3.2 REFUTED (brief line): `edittext_device_transform_small_shear` is not a device-font row
The brief groups it with the near-passes and hints at device fonts. Its `test.toml` has **no
`[fonts.*]` block at all** — it is an embedded-font test. Its 88-outlier residual is 1-px glyph run
edges (§4), not a missing outline source. Its sibling
`edittext_device_transform_negative` **is** device-font, and is `known_failure`.

### 3.3 A1b — the cheapest device-font row needs no rasteriser
`fonts/device_font_kerning/Test.as` embeds the very same face it then requests as a device font:

```as3
[Embed(source="TestFont.ttf", fontName="TestFont", embedAsCFF="false", unicodeRange="U+0061-U+0064")]
...
var tf:TextFormat = new TextFormat("TestFont", 10);   // field.embedFonts stays false
```

so the SWF dictionary already carries `DefineFont` glyph outlines for `a`–`d`. A name-matched
fallback — *when a field requests a device font whose family matches an embedded font in this SWF,
use the embedded glyphs* — supplies outlines for this test with no TTF work at all. Budget is
`tolerance 0`, and the test's whole point is the kerning delta between its two fields, so the
`[fonts.*]`-derived kern pairs `abc_devicefont.cpp` already emits must be applied on top.
**Priced +1, low-medium confidence, small patch.** This is the recommended entry point into A1.

---

## 4. N1 — the `a_epsilon` near-pass cluster: measured, and NOT what the board calls it

The board files these under `hairline_edge_drift` = *"mostly the lavapipe-vs-Flash antialiasing
gap"*. Measured pixel-by-pixel (`edge.py` over 11 comparisons, 143 classifiable pixels):

| test | ndiff px | character |
|---|---:|---|
| `visual/fonts/duplicate_font` | **1** | pure binary run edge |
| `visual/fonts/glyph` | **2** | pure binary run edge |
| `from_shumway/acid/acid-text-x` | **2** | pure binary run edge |
| `fonts/embed_matching/match_style` | **4** | pure binary run edge |
| `text/auto_size/height` | **5** (budget 1 px) | pure binary run edge |
| `text/auto_size/return` | **12** (budget 6 px) | pure binary run edge |
| `fonts/embed_matching/fallback_preferences` | **52** | pure binary run edge |
| `from_shumway/acid/acid-text-6` `[output]`/`[frame5]` | 66 / 4 | pure binary run edge |
| `from_shumway/acid/acid-text-escape` | 92 | **antialiased** |
| `visual/simple_shapes/text_field_mask` | 28 | **antialiased** |
| `avm1/edittext_stylesheet` | **2** | **antialiased** (E=95 grey, A=0 black, at a run end) |

Aggregate classification of the binary sub-cluster: 65 pixels where the golden has a run-edge pixel
we omit, 78 where we add one the golden omits — **bidirectional and roughly balanced**, therefore
*not* a constant sub-pixel offset. These are pure 0/255 values, i.e. **1-sample (quality=low)
pixel-centre coverage**, so they are deterministic and in principle exactly matchable — this is
*not* an antialiasing-tolerance problem in the sub-cluster the board's example rows come from.

**Verdict NO-GO as an individual-test lead** (every budget is 0–6 pixels; nothing flips alone).
**Completion mechanism, stated as a testable probe rather than a fix:** per the standing
`[integer-twips]` lesson ("Ruffle geometry is integer twips — quantize first"), quantize glyph
outline vertices to integer twips before the device transform and re-measure this exact 11-test
board. If the ±1 tie collapses, **7 comparisons flip at once**
(`duplicate_font`, `glyph`, `acid-text-x`, `match_style`, `auto_size/height`, `auto_size/return`,
`fallback_preferences`; `acid-text-6` needs 66→0 and is marginal). That is the highest
flips-per-LOC lead left in this family and it is a single experiment, not a guess. The three
antialiased rows are a separate sub-cluster and would not move.

---

## 5. Characterisations of the remaining briefed rows

### 5.1 `text/br_at_start` — 2727 px, one line height, one field (H2)
`tolerance 128 / max_outliers 8`. Every differing pixel is in two bands, rows 154–174 and 177–197
(plus one stray pixel at row 388). Raw row dump over that window: our render carries the glyph runs
at rows 154–170 where the golden carries the **same glyph runs** at rows 178–194 — a uniform
**+24 px = one line height** vertical offset, with the golden's rows blank in ours and ours blank in
the golden. A leading `<br>` is not producing its blank line. Because the glyphs themselves match, a correct
line-count fix lands them exactly on the golden → **plausible +1**. Held, not GO, because the fix is
in shared HTML line layout and the blast radius covers every `htmlText` test in the corpus; a
wave-2 agent must grade `text/*`, `avm1/edittext_*`, `from_shumway` text and the `regression` suite.

### 5.2 `visual/edittext/edittext_gutter` — 1032 px, horizontal gutter clipping
`tolerance 128`, 100×110, a grid of `TextField`s of widths 0,1,…,8,40 each containing one embedded
glyph. Two sub-effects, both about the 2-px-per-side Flash gutter:
* for fields narrower than the gutter the golden shows **border only** while we let the glyph ink
  through (extra ink at x=6,13,18… on rows 4–19);
* the golden has faint sub-pixel rows immediately above the top border and below the bottom border
  (row 1 `....*:.**:.***:`, row 32/35) that we do not draw at all.

i.e. we clip the field content **vertically** where Flash does not, and fail to clip it
**horizontally** where Flash does. Not box geometry (the s17 work); a glyph-mask extent question.
No flip priced — the budget is 0 outliers at tolerance 128 and the residual is diffuse.

### 5.3 `avm2/edittext_get_{line,char}_index_at_point` — LAYOUT tests, not fill tests
The brief hands the "fill-colour reading" of these to w1-gfx-fill. **That framing is wrong and
should be relayed**: both `Test.as` files build a per-pixel colour **map** of
`getLineIndexAtPoint(x,y)` / `getCharIndexAtPoint(x,y)` results via `BitmapData`, using a 7-entry
palette purely as an index encoding. The ink totals are *identical* in expected and actual
(`101200 == 101200` for `get_line_index_at_point`), so nothing about fills differs — what differs is
which line/char index we compute at 8466 / 14721 sample points, under `<font size='30'>`,
`<textformat leading='-10'>` and nested `size='+1'` runs. This is the same text-metrics axis as §5.1
and the `[label-trap]` lesson applies (the cluster label `same_geometry_wrong_fill` names the
symptom, not the owner). `tolerance 0` on both → NO-GO until line/char metrics are exact.

### 5.4 `visual/cache_as_bitmap/edittext_{scroll,hscroll,selection}` — and a doc correction
All three ship an `input.json`, and `verify_output.py:4162-4170` **replays it**. So the caret,
selection highlight and scroll state *are* exercised in CI — which contradicts the standing comment
on `TextFieldGlyphInfo.caret_char` / `sel_begin` in
`SWFModernRuntime/include/actionmodern/action.h:874-881` ("the highlight, like the caret, is
browser-only / never in CI"). Worth a one-line correction there.

Measured:
* `edittext_hscroll [output.02]`: golden ink 152 px, ours 344 px — we render the **unscrolled**
  text; `scrollH` is not applied. `[output.01]` additionally misses a 2-column vertical stripe at
  x=18–19 (the caret).
* `edittext_selection [output.02]`: golden ink 965, ours 1296, 2261 px differ — the selection
  highlight block (inverted run) is not drawn; `.01`/`.03` differ only by ~130 px of caret/edge.
* `edittext_scroll [output.01/.02]`: `with_default_font = true`, so it also sits behind §3's default
  font source; residual 194/196 px in rows 6–15.

No flips priced; the owners are (a) `scrollH` in the glyph pass and (b) selection-highlight
rendering, both new surfaces.

### 5.5 `visual/edittext/edittext_border_transform [output.04]/[output.06]`
244 differing px each, rows 32–52 and 59–79, ink totals 895 vs 896 and 2195 vs 2196 — a 1-px border
geometry difference under a rotated/sheared placement. Budgets 20 channels vs current 51 and 44, so
each needs roughly a halving. Unchanged since s16/s17 characterised it as the embedded-font
`draw_text_box` corner rows. **This is also a tier-1 canary member — a wave-2 agent must expect it
to move if it touches the box painter, and must not read that movement as a regression without
comparing outlier counts.**

### 5.6 `visual/edittext/edittext_border_filters` — 827, filter half is w1-gfx-filters'
Golden ink 817 px vs ours 537 px, in two bands (rows 9–21, 29–41): we are missing **280 ink px** of
the filtered border, i.e. the filter is not expanding/blurring the border geometry. The text-layout
half is clean. Hand to w1-gfx-filters.

### 5.7 `text/style_changes_in_html` — NO-GO
12551 px across three text blocks, `tolerance 0`, `max_diff 103`. Ink IoU 0.26 — whole-block glyph
layout under mid-paragraph style changes. No cheap mechanism; not a near-pass.

### 5.8 Price-only (`known_failure = true` — Ruffle fails these too)
`from_shumway/flash_text_TextField` 966, `from_shumway/stylesheet` 2089, `from_shumway/hardwrap`
3099, `from_shumway/captions` 6867, `from_shumway/acid/acid-text-4` 51672,
`from_shumway/acid/acid-text-5` 422232, `from_shumway/acid/acid-textfield` 15754,
`visual/edittext/edittext_device_transform_negative` 2649.
Note the first three all have `ink_iou 0.00` with `missing_ink_frac 1.00` — the field renders
**nothing at all**, the same signature as §3's device-font blanks; they are useful *band* telemetry
for the A1 arc but must never be scored.

### 5.9 Disposition check (rule 2)
Grepped `ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md` and `ignored_tests.txt` for every test above. The only text-family hit is
`from_shumway/avm1/text-bind` (ACCEPTED_DIFFS: device-font file mismatch, ~14 px too low), already
excluded from the board. No briefed row is dispositioned. No upstream drift observed: every briefed
test is present on disk and in `_results/results_graphics.json`.

---

## 6. Reproduction recipe (for wave 2)

```bash
export SWFRECOMP_COMPILE_TIMEOUT=2400
export SWF_KEEP_BUILD_DIR=/path/to/scratch/bd1          # keeps ./test_run for gdb
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/visual \
  --test=edittext/edittext_bounds_vs_position --mode=graphics --verbose
cd "$SWF_KEEP_BUILD_DIR" && gdb -q -batch -x gdbNN.txt ./test_run
```

The binary has symbols but **no DWARF types**, so: read struct fields through byte offsets obtained
by compiling an `offsetof` probe against `SWFModernRuntime/include` with the same `-D` set
(`MovieClip`: `x=0 y=4 width=24 height=28 visible=32 name=48 parent=1624 dynamic_props=1632
depth=1644 ng_textfield_idx=1684`, `sizeof=1904`); `child_mc_cache` is an **array**
(`((char**)&child_mc_cache)[i]`, not a pointer deref); gdb convenience variables are not
addressable, so allocate a scratch buffer with `set $p = (char*)malloc(64)` before calling
`getLocalMatrixForMC_render`; and gdb's `printf "%s"` on a ternary aborts the whole script — print
`(char*)($mc+48)` directly. All scripts are in the scratch dir as `gdb*.txt`, with `an.py`,
`vis.py`, `vis2.py`, `prof.py`, `sum.py`, `px.py`, `edge.py` for the PNG forensics.

---

## 7. New unclaimed leads

1. **`avm1/define_font_glyph_table_order`** — 180 outliers / 80 px, rows 12–31, golden ink 80 vs our
   20 within the diff region: we draw a mostly-hollow glyph. Text/embedded-font family, **not in any
   agent's brief**, budget `max_outliers 4`.
2. **`from_shumway/acid/acid-text`** — 7683 outliers, `diffuse_mixed`, ink IoU 0.64, **not
   `known_failure`**. The only large non-KF Shumway text row and unclaimed.
3. **`ng_getMatrixFromObj_render` is one call site short of the `[child-xform-table]` rule** (§1.3).
   Beyond the EditText cull, any other CPU-side consumer of a *nested* entry's matrix during a
   render frame reads the same garbage — worth an audit of `getLocalMatrixForMC_render`'s callers
   and of `shape_hit_test.c` hit tests taken while a frame is composing.
4. **Doc correction**: `action.h:874-881` claims caret/selection are "never in CI"; three
   `cache_as_bitmap` tests replay `input.json` in CI and grade exactly those pixels (§5.4).
5. **`scrollH` is not applied to EditText glyph layout** (`edittext_hscroll [output.02]`, golden ink
   152 vs ours 344) — a self-contained new surface, no other row depends on it.
6. **Selection-highlight rendering** (`edittext_selection [output.02]`, 2261 px;
   `avm2/edittext_always_show_selection` 432 px at `max_diff 43` — the latter has *identical* ink
   and differs only in the highlight's shade, so it may be a one-constant fix once the highlight
   exists).
7. **Flash's EditText vertical non-clipping** (§5.2) — the golden shows glyph ink one pixel above
   and below the field box; our mask clips it. Small, and it recurs in any tight-bounds text test.
