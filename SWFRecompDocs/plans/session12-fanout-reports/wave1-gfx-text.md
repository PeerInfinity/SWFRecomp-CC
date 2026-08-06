# wave1-gfx-text — the text/auto_size + fonts near-pass head (session 12, wave 1)

Agent `w1-gfx-text`, read-only. Base HEAD `f166e424e`. Board provenance: image
run `31075033086` at `6de65043250d` (2026-08-06T06:23), extracted from
`origin/ruffle-image-results` into a scratch dir (never checked out over the
tree); `scripts/image_triage.py --jobs 2` re-run against it.

---

## 0. Headline — the brief's inventory is a unit error, and the family is AA noise

**The brief's "auto_size height (12 comparisons), match_style (12), glyph (6),
duplicate_font (3)" are `excess_outliers` in CHANNELS, not comparison counts.**
The four named targets are **4 comparisons total**, carrying **1–5 differing
pixels each**:

| comparison | suite | size | diff px | channels | limit | band |
|---|---|---|---:|---:|---:|---|
| `text/auto_size/height [output]` | text | 300×250 | 5 | 15 | 3 | a_epsilon |
| `fonts/embed_matching/match_style [output]` | fonts | 550×400 | 4 | 12 | 0 | a_epsilon |
| `visual/fonts/glyph [output]` | visual | 550×400 | 2 | 6 | 0 | a_epsilon |
| `visual/fonts/duplicate_font [output]` | visual | 550×400 | 1 | 3 | 0 | a_epsilon |

**Verdict: PREMISE REFUTED. This is the blend_modes case again — cap it, do not
scope it** (§1). The productive work in the neighbourhood is two *other*
`text/auto_size` comparisons that the brief's arithmetic hid, and they are
genuinely single-mechanism (§2, §3).

Revised board for this brief:

| family | cmps | verdict | wave-2 scope |
|---|---:|---|---|
| A. height / match_style / glyph / duplicate_font | 4 | **CAP — 1-sample coverage ties** | none |
| B. `text/auto_size/width` | 1 | **FIXABLE, +1 flip** | quality-aware EditText box snapping + border corner rule (`avm2_display.c`) |
| C. `text/auto_size/return` | 1 | fixable mechanism, **no flip** (budget) | AVM2 EditText glyph clip is collected and thrown away |
| D. fonts device-glyph outlines | 5 | arc-sized (T3), not a sweep | ~24k px, one shared cause |
| E. fonts small residuals | 3 | unowned singles | leading_define_font / advance_u16 / glyph_table_order |

Dispositions: **none** of the 4+2 targets appears in any suite's
`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, the global `ruffle-tests/ignored_tests.txt`, or a
suite-local ignore list. All six have `trace_status = pass` and
`known_failure = false`.

---

## 1. Family A — 4 comparisons of 1-sample coverage ties (CAP)

All four are `quality = "low"` (`[player_options] with_renderer`), i.e.
`MSAA_SAMPLES = 1`: coverage is a single sample at the pixel centre, so a
sub-sample geometry difference is a **binary 0↔255 flip of one pixel**, which is
why `max_diff = 255` on a 1-pixel diff. `image_triage.py` clusters all four as
`hairline_edge_drift` with the strongest possible signature:
`100% on edges, 0% survives erosion, ink IoU 1.00`.

Every differing pixel is a **stair-step corner on a diagonal glyph edge**, and
the polarity is mixed *within a single test* — 4 of 5 in `auto_size/height` are
ours-extra, 3 of 4 in `match_style` are ours-missing. A systematic sub-pixel
offset would flip one way along one edge orientation; this does not.
Representative (actual | expected, `#` = ink, marked row is the differing one):

```
text/auto_size/height  (53,191)          fonts/embed_matching/match_style (294,330)
  .....##...#   |   ......#...#  <         ......####.   |   .....#####.  <
  .....##...#   |   .....##...#             ......#####   |   ......#####

visual/fonts/glyph (446,108)             visual/fonts/duplicate_font (161,42)
  ......#####   |   .....######  <         ...........   |   .....#.....  <
  ......#####   |   ......#####             #######.###   |   #######.###
```

Cause: our glyph outlines are flattened + tessellated with libtess2, Ruffle's
with lyon. On a curve segment the two flattenings differ by far less than a
twip, but at 1 sample/pixel a centre that sits within that epsilon of the edge
flips wholesale. There is no *behavioural* bug to fix here; matching would mean
matching lyon's flattening tolerance and vertex ordering exactly — unbounded
blast radius across every shape in the corpus, for 4 comparisons.

**Recommendation: add these four to the a_epsilon cap alongside `blend_modes`.**
`match_style` (`tolerance = 3`, `max_outliers = 0`) and `glyph` /
`duplicate_font` (`tolerance = 0`, `max_outliers = 0`) have literally zero
budget, so they cannot absorb even one tie. `auto_size/height` needs 4 of its 5
pixels gone (`max_outliers = 3` channels = 1 pixel).

---

## 2. Family B — `text/auto_size/width`: ONE mechanism, +1 flip (recommended wave-2 target)

`text/auto_size/width [output]`, suite `text`, 500×350, **7560 channels /
2520 px, limit 18, band d_moderate**. `diffuse_mixed` on the board — a
misleading cluster: the diff is not diffuse at all.

### 2.1 Residual: 2514 of 2520 px are one border row, ×6 fields

The SWF is **AVM2** (DoABC + SymbolClass; 6 `DefineEditText` at 100×40 px,
placed 2 columns × 3 rows, autoSize+wordWrap driven from AS3, each field
resolving to 210 px wide — matching the six `210` trace lines). Every glyph in
the field interior is **pixel-identical**. The entire diff is the field's
**bottom border row**:

| edge | ours | Ruffle golden |
|---|---|---|
| top row | 30, x 30..240 | 30, x 30..240 |
| left col | 30, y 30..**107** | 30, y 30..**108** |
| right col | 240, y 30..107 | 240, y 30..107 |
| **bottom row** | **107**, x 30..**240** | **108**, x 30..**239** |

Per field: 210 px wrongly inked at row 107 + 210 px missing at row 108 = 420;
×6 fields = **2520**, exactly the reported count. The only other diffs are 6
one-pixel AA ties at `(117,46) (347,46) (117,146) (347,146) (117,246) (347,246)`
— the Family-A class, 18 channels.

### 2.2 Mechanism (pinned)

The field's autosized height is **77.75 px** (1555 twips = `text_h` 1475 +
`GUTTER*2` 80) — both renderers agree, confirmed independently from the glyph
baselines (last line box `y0 = 82.5`, `y1 = 105.75`; observed ink rows 86–105).
The divergence is *pixel snapping of the box*, not the height.

Ruffle `core/src/display_object/edit_text.rs:3603-3632`,
`EditTextPixelSnapping::apply`, has **two arms**:

```rust
StageQuality::Low => {                       // snap tx/ty only
    matrix.tx = matrix.tx.round_to_pixel_ties_even();
    matrix.ty = matrix.ty.round_to_pixel_ties_even();
    // "we do not need to snap scale, because at low quality
    //  antialiasing is disabled anyway"
}
_ => {                                        // medium/high/best
    matrix.tx = (matrix.tx + Twips::new(2)).trunc_to_pixel();
    matrix.ty = (matrix.ty + Twips::new(2)).trunc_to_pixel();
    if x_snap { matrix.a = (matrix.a - 0.35).round_ties_even(); ... }
    if y_snap { matrix.c = ...; matrix.d = (matrix.d - 0.35).round_ties_even(); }
}
```

**`SWFModernRuntime/src/avm2/avm2_display.c:14868-14876`
(`avm2_render_textbox`, `draw_text_box` branch) implements only the `_` arm, and
applies it unconditionally:**

```c
btx = tw_trunc_to_pixel(btx + 2.0);
bty = tw_trunc_to_pixel(bty + 2.0);
if (x_snap) { ba = nearbyint(ba - 0.35); bbm = nearbyint(bbm - 0.35); }
if (y_snap) { bcm = nearbyint(bcm - 0.35); bd  = nearbyint(bd  - 0.35); }
```

Its own comment already names the bug: *"then EditTextPixelSnapping for the
default (high) quality (edit_text.rs:3613-3630)"*. At `quality = "low"`,
`bd = nearbyint(77.75 - 0.35) = nearbyint(77.4) = 77` → the box height collapses
to 77 px and the bottom border lands on row 107. Ruffle keeps 77.75, and
`draw_line_rect` (`render/wgpu/src/surface/commands.rs:875-887`) adds
`HALF_PX` to `tx`/`ty` before rasterising the 1-px line strip, so the bottom
edge at 108.25 inks **row 108**. Everything else in the test has integral
geometry (x 30.0 / width 210.0 / top 30.0), which is why only the bottom row
moves.

Cross-check that this is snapping and not a height bug: `text/auto_size/return`
and `text/auto_size/height` have **integral** field heights (103/75 px) and
their borders match the golden exactly.

Second, smaller defect: even with the right row, Ruffle's `draw_line_rect`
closed strip leaves the **bottom-right corner pixel empty** — golden bottom row
is `x 30..239` and right column `y 30..107`, so `(240,108)` is white. Our
axis-aligned fast path (`avm2_display.c:14894-14897`) draws four rects that
include all four corners. Note the code comment there claims the opposite,
citing `avm2/edittext_autosize_height_dynamic` — that test's box is at the
origin with integral size, so it is not a counter-example for the fractional
case; wave 2 must A/B it.

### 2.3 Wave-2 patch scope and predicted flips

Scope: `SWFModernRuntime/src/avm2/avm2_display.c`, one function
(`avm2_render_textbox`, ~lines 14856-14900). Runtime-only, no recompiler change.

1. Gate the snapping on quality. `MSAA_SAMPLES` is already the per-test quality
   signal (`verify_output.py:2483-2488` emits `-DMSAA_SAMPLES=1` for
   `quality = "low"` on **every** gcc invocation, so `avm2_display.c` sees it);
   `MSAA_SAMPLES == 1 ⟺ StageQuality::Low` exactly, because Ruffle maps Low→1
   and everything else→4. Add the same `#ifndef MSAA_SAMPLES / #define 4` guard
   `render_webgpu.c:48-49` uses (the macro is only emitted when it differs from
   4). Low arm: `btx = tw_round_to_pixel_ties_even(btx); bty = ...;` and **no**
   `ba/bbm/bcm/bd` rounding.
   *(Standing s11 invariant respected: this adds no pipeline, so no literal `4`
   is at risk in `render_webgpu.c`.)*
2. Drop the bottom-right corner in the axis-aligned `draw_line_rect` fast path:
   bottom rect `bw` (not `bw + 20`), right rect `bh` (not `bh + 20`), keeping
   top and left full-length. That reproduces the golden's
   "full rect minus `(x0+w, y0+h)`".

**Predicted flip ledger:**

| comparison | with (1) only | with (1)+(2) |
|---|---|---|
| `text/auto_size/width [output]` | 7560 → 36 channels, band d_moderate → a_epsilon, **still FAIL** (limit 18) | 7560 → **18 channels = limit → PASS** |

The arithmetic is tight and deliberate: after (1) the only residual is the 6
corner pixels (18 ch) + the 6 AA ties (18 ch) = 36 > 18. After (2) only the AA
ties remain, and the harness passes on `outliers <= max_outliers`
(`verify_output.py:500`), so 18 ≤ 18 passes. **Ship (1) and (2) together or the
flip does not land.**

Blast radius: every AVM2 EditText that draws a background/border through
`draw_text_box`. 8 further failing comparisons are AVM2/EditText box-family
(`edittext_background_basic{,_scale2}`, `edittext_border_basic{,_scale2}`,
`edittext_gutter`, `avm2/edittext_tag_indent`, `edittext_border_filters`,
`cache_as_bitmap/edittext_selection`) — but **all of those run at the default
(high) quality**, so change (1) cannot touch them; only change (2) can, and only
where the box is axis-aligned with a border. That is the A/B to watch.

### 2.4 Canary notes

* **Local Dawn reproduces this test byte-for-byte against CI lavapipe** — I
  rendered it locally (`--mode=graphics --images --image-out-dir=<scratch>`) and
  the local `output.actual.png` is **0 differing pixels** vs the CI-published
  actual, with the same full-width rows `[30,107,130,207,230,307]`. So wave 2
  can iterate on this one locally with an absolute verdict, not just an A/B.
  (The trace side passed and the run did **not** touch
  `text/_results/image_results_graphics.json` — verified `git status` clean.)
* `text/auto_size/width` is **not** in `render_canary_tests.txt`. Recommend
  adding it as **tier 2** (CI-failing today) for the duration of this patch, plus
  keeping `avm1/edittext_tag_indent` (tier 1) as the AVM1-side no-move witness —
  the patch must leave every AVM1 EditText byte-identical, since `tag.c`'s box
  painter is a separate implementation (`tag.c:4520-4600`) that applies no
  `EditTextPixelSnapping` at all.
* Expected canary result for the merged patch: **IDENTICAL on all 37 standing
  comparisons**; only `text/auto_size/width` (if added) may DIFFER.

---

## 3. Family C — `text/auto_size/return`: AVM2 EditText glyphs are never clipped

`text/auto_size/return [output]`, 550×375, **2544 channels / 848 px, limit 18,
band c_small**, cluster `diffuse_mixed`.

### 3.1 Residual

837 of 848 px are **four contiguous text blobs that only we draw**:

| region | where | n |
|---|---|---:|
| `y[133,148] x[28,76]` | a whole text line **below** the field's bottom border (row 128) | 219 |
| `y[133,148] x[203,251]` | same, second column | 219 |
| `y[35,49] x[448,493]` | text continuing **past** the field's right border (col 450) | 202 |
| `y[30,45] x[502,547]` | same, further right | 197 |

Ruffle's golden has nothing in any of the four; interior glyphs match exactly.
The remaining 11 px are isolated single-pixel Family-A ties on border corners
(`(100,128) (275,128) (112,216) (287,216) (462,216) (33,236) (208,236)
(120,268) (295,268) (175,275) (350,275)`).

### 3.2 Mechanism (pinned)

`avm2_edittext_collect_glyphs` **computes** the field clip rect
(`SWFModernRuntime/src/avm2/avm2_text.c:3892-3895`):

```c
out_clip[0] = et->bounds_x + GUTTER;
out_clip[1] = et->bounds_y;
out_clip[2] = et->bounds_w - 2 * GUTTER;
out_clip[3] = et->bounds_h;
```

and the sole caller **discards it**
(`SWFModernRuntime/src/avm2/avm2_display.c:15055-15069`): `int32_t clip[4];` is
passed in, then never read — there is no `renderer_begin_clip_mask` /
`renderer_draw_rect` / `renderer_end_clip` around `avm2_render_glyphs`. The AVM1
twin *does* clip (`tag.c:4733-4746`, "Field clipping mask (stencil):
gutter-inset horizontally, full height vertically. Matches Ruffle
EditText::render_self mask"). Only the per-box cull
`if (b->y + GUTTER - vscroll > et->bounds_h) continue;` (`avm2_text.c:3918`)
survives on the AVM2 path, which catches whole boxes below the field but nothing
horizontal and nothing partially below.

### 3.3 Wave-2 scope and predicted flips

Scope: `avm2_display.c::avm2_render_edittext` — wrap `avm2_render_glyphs` (and
the selection rects) in the stencil clip using the already-computed `clip[4]`,
mirroring `tag.c:4741-4746`.

**Predicted flips: ZERO.** 2544 → 33 channels (11 AA ties × 3) against a limit
of 18 → band c_small → a_epsilon, **still fails by 15 channels**. Do not scope
this for a flip.

It is still worth doing as a *shared-mechanism* patch — the same missing clip is
the plausible owner of `avm2/edittext_get_char_index_at_point` (59137,
`ink IoU 0.93, 4.2% repainted`), `avm2/edittext_get_line_index_at_point`
(22217), `from_shumway/hardwrap` and `from_shumway/stylesheet`
(`missing_element`) — but those were not in my brief and I did not verify them.
**Risk flag:** s11's mask work recorded defect B as "every EditText ORs its rect
into the stencil"; adding a second EditText stencil user must be A/B'd against
the mask family (`visual/cache_as_bitmap/masks`, `regression/mask_sibling_union`)
before it ships.

Also note `test.toml` carries Ruffle's own `# FIXME this test produces vastly
different results compared to FP (output.txt + render)` — the golden is Ruffle's
behaviour, not Flash's, though the test is *not* `known_failure`.

---

## 4. Family D — the `fonts` slice is one arc, not near-passes

The brief grouped "fonts near-passes" with auto_size. Measured, the failing
`fonts`-family comparisons split cleanly:

| comparison | diff px | ours-missing | ours-extra | reading |
|---|---:|---:|---:|---|
| `visual/definefont4` | 5362 | 5362 | 0 | we render **nothing** |
| `visual/fonts/font_lookup_as3` | 11544 | 11544 | 0 | 79% of expected ink absent |
| `visual/fonts/leading_device_font` | 4326 | 4320 | 6 | device text absent |
| `visual/fonts/device-font` | 2735 | 2735 | 0 | we render **nothing** |
| `fonts/device_font_kerning` | 560 | 560 | 0 | device text absent |

`extra = 0` everywhere: this is not a layout or metric error, it is **device
font glyph outlines never being painted**. w2-b9's own report says so
explicitly — "the generated device rows carry NULL outline pointers by design
(device glyph *outlines* are still T3), so device text still paints nothing and
only its measurement changed" — and it measured zero pixel movement from B9,
which matches this board exactly. **5 comparisons, ~24.5k px, one cause,
arc-sized (real TTF outline extraction + tessellation). Not a session-12 sweep
item.**

Three genuinely small fonts residuals are left over and are *unowned* (not in my
brief, not in the coordinator's owned list):

* `visual/fonts/leading_define_font` — 724 px, 288 missing / 288 extra, ink
  counts **equal** → a pure vertical shift of some lines. A leading bug,
  ~1 comparison, cheap.
* `visual/fonts/advance_u16` — 88 px, 72 missing, all inside `x[324,332]
  y[2,19]` → one glyph too narrow / absent. Plausibly the same unsigned-advance
  family as B9's `int16_t → int32_t` fix, one glyph short of done.
* `avm1/define_font_glyph_table_order` — 90 px, 40 missing, `row_banded`,
  50×50 image.

---

## 5. Summary of measurements (for the closeout ledger)

```
family                                cmps  channels  limit  verdict
A  auto_size/height                      1        15      3  CAP (1-sample tie)
   embed_matching/match_style            1        12      0  CAP
   visual/fonts/glyph                    1         6      0  CAP
   visual/fonts/duplicate_font           1         3      0  CAP
B  text/auto_size/width                  1      7560     18  FIX -> PASS (needs both sub-fixes)
C  text/auto_size/return                 1      2544     18  FIX -> 33 ch, no flip
D  device-glyph outlines                 5    ~73.6k      -  arc (T3)
E  leading_define_font/advance_u16/
   define_font_glyph_table_order         3      2034      -  unowned singles
```

Net predicted session-12 yield from this brief: **+1 comparison**
(`text/auto_size/width`), plus one large band move
(`text/auto_size/return` c_small → a_epsilon) if family C is also taken.
