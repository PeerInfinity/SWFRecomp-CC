# w2-gfx-glyph-twips — wave 2 PROBE: glyph vertex quantisation

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a5142341c03ed064f`, base
`cdafe1be9`. No commits, no pushes. Scratch:
`<scratchpad>/w2-gfx-glyph-twips/`.

**New files: none.** Patch touches ONE file: `SWFRecomp/src/abc/abc_timeline.cpp`
(`parseGlyphShape` + a self-localized `glyphLevien*` helper block). No sibling overlap —
w2-gfx-text owns `getLocalMatrixForMC_render`, underline emission, the AVM2 border box and
device-font fallback; w1-trace-display's pending w2 owns `abc_timeline.cpp`'s **EdgeBounds**,
a different function.

---

## 0. Verdict board

| # | verdict | flips | evidence |
|---|---|---:|---|
| **GO** | **ship the patch** | **+2 pixel comparisons** (`visual/fonts/duplicate_font`, `from_shumway/acid/acid-text-x`) plus large headroom gains on 4 more rows | §4 ledger |
| **REFUTED** | the brief's premise (and w1 §4's N1 completion mechanism) | 0 | §2 — glyph vertex quantisation is **raster-invisible**; three independent legs prove it |
| **REFUTED** | "the glyph raster path is `render_webgpu.c` / `ng_shared.c` text tables" | — | §3 — AVM2 text is painted from a **completely different** glyph pipeline the brief never names |
| **HOLD** | the last 1 px of `visual/fonts/glyph` + the 4 AVM1 rows | +0 | §5 |

Two brief premises attacked and **refuted**; one **new owner** found and fixed.

---

## 1. Baseline (reproduced, not quoted)

Local `--mode=graphics --images --recompile`, all 11 rows of w1 §4's N1 board, 12
comparisons. Outlier counts (channels; ≈3 per pixel) match w1's pixel counts exactly:

| row | budget | outliers |
|---|---|---:|
| `visual/fonts/duplicate_font` | tol 0 / 0 out | 3 |
| `visual/fonts/glyph` | tol 0 / 0 out | 6 |
| `fonts/embed_matching/match_style` | tol 3 / 0 out | 12 |
| `fonts/embed_matching/fallback_preferences` | tol 3 / 0 out | 156 |
| `text/auto_size/height` | 3 outliers | 15 |
| `text/auto_size/return` | 18 outliers | 36 |
| `from_shumway/acid/acid-text-x` (`known_failure`) | tol 0 | 6 |
| `from_shumway/acid/acid-text-6` `[output]` / `[frame5]` | tol 0 | 198 / 12 |
| `from_shumway/acid/acid-text-escape` | tol 0 | 184 |
| `visual/simple_shapes/text_field_mask` | tol 0 | 56 |
| `avm1/edittext_stylesheet` | tol 0 | 6 |

All rows are `quality = "low"` → `-DMSAA_SAMPLES=1`, i.e. pure pixel-centre coverage. The
two `visual/fonts/glyph` outliers are `(446,108)` (golden has ink, we don't) and `(189,112)`
(we have ink, golden doesn't) — both single staircase steps on long, near-diagonal glyph
edges.

---

## 2. The premise is REFUTED — glyph vertex quantisation is raster-invisible

The brief (and w1 §4) asked: *"quantize glyph outline vertices to integer twips … if the ±1
tie collapses, 7 comparisons flip at once."* Reading upstream first
(`~/CC/ruffle/render/src/tessellator.rs:385` `ruffle_path_to_lyon_path`) inverts the premise:
Ruffle converts every coordinate with `Twips::to_pixels()` into **f32** and lyon flattens in
floats — **Ruffle does not quantize at all**. We are the engine that quantizes. So the
testable claim is the opposite one: *remove* our quantisation and see whether the ties
collapse.

Three legs, all on the recompiler's plain-shape/font pipeline (`swf.cpp`
`interpretShape` → `addCurvedEdgeLevien` → earcut → `shape_data`):

| leg | change | glyph geometry effect | result on the 12 comparisons |
|---|---|---|---|
| **B** | `(s32)` → `lroundf` in `addCurvedEdgeLevien`, gated to `is_font` | **4547 of 7443** vertices moved by ±1 EM unit | **11 of 12 renders byte-IDENTICAL** (`acid-text-escape` moved, outliers unchanged at 184) |
| **C** | parse font coordinates at **32×** and divide the static-text glyph matrix by 32 | quantisation **and** chord error both ÷32 (`shape_data` 7443 → 36819 verts); geometry is Ruffle's exact real geometry to 4 s.f. | all 3 static rows byte-IDENTICAL |
| **control** | 32×/2×/4× **uncompensated** (glyphs literally 2–32× oversized) | catastrophic if used | byte-IDENTICAL |

The control is the load-bearing one. `bd_K4nocomp/draws.c` carries `0x4635E000` = 11640.0 =
2910 × 4, `draws.o` and the linked `test_run` each contain 14 hits of that pattern and **zero**
hits of the 1× value — and the freshly rendered `output.png` md5s identical to baseline
(`2103e89cd31c7f5894c1f8abb51695be`). Quadrupling every embedded glyph outline changes
nothing, so the pixels on screen were never drawn from those outlines.

Scale check, for the record: `visual/fonts/glyph` is a 20480-em `DefineFont3` at
`font_height = 1920`, so one glyph unit = 0.09375/20 px = **0.0047 device px**. Our
`LEVIEN_TOL_TWIPS = 2.0` in glyph units is exactly lyon's `DEFAULT_TOLERANCE` 0.1 px, and the
sibling `w2-gfx-blend-tie` already verified our Levien `t` schedule matches lyon's to ~1e-7 —
so in *that* pipeline quantisation really was the only residual, and it is below the raster's
resolution. **w1 §4's priced "+7 comparisons at once" is not available by that route.**

---

## 3. The real owner — a second, undocumented AVM2 glyph pipeline

`textfield_glyph_render_cb` (`tag.c:5554`), the static-text painter at `tag.c:3802` and the
one at `tag.c:4245` are the three places `shape_data` glyph outlines reach the screen. A
temporary `fprintf` in **all three** (compiled — the build dir's `tag.c` carries the three
probes) produced **zero** lines for `visual/fonts/glyph`. The painter is instead:

* `SWFModernRuntime/src/avm2/avm2_display.c:18275` — the AVM2 native text draw. It reads
  `Avm2FontData::glyph_pts` (already-flattened outline points in **font units**), maps them to
  field-local twips, and tessellates each glyph at runtime with **libtess2 CDT / NONZERO**.
  It never touches `shape_data`.
* Those `glyph_pts` are produced by **`SWFRecomp/src/abc/abc_timeline.cpp::parseGlyphShape`** —
  a *separate* glyph SHAPE parser with its own bit reader, which flattened every quadratic
  into a **fixed 8 equal-parameter chords**:

```cpp
for (int k = 1; k <= 8; k++) {          // "glyphs render at text sizes, where
    double t = k / 8.0, u = 1.0 - t;    //  that is well under half a pixel of error"
    ...
    cur.push_back((int32_t) lround(qx));
```

That comment is wrong at large text sizes. Equal-parameter subdivision into N leaves
`dev/N²`; at N = 8 and a chord deviation of ~1500 font units on a 20480-em face that is
~23 units = **0.11 device px** — roughly **25× the quantisation error §2 just proved
invisible**, and squarely in the range that flips a 1-sample run edge.

Ruffle flattens the same glyph with lyon's adaptive Levien schedule at
`FillOptions::DEFAULT_TOLERANCE / scale`, `scale = 1.0` for glyphs
(`core/src/font/glyph.rs:109` → `register_shape`), i.e. 0.1 px = **2.0 glyph units**.

Direction check before porting: forcing the fixed count 8 → 64 changed
`visual/fonts/glyph` from 6 to **18** outliers — more subdivision alone is *worse*, so the
answer is not "subdivide harder", it is "use Ruffle's schedule". That is the patch.

---

## 4. The patch and its ledger

`SWFRecomp/src/abc/abc_timeline.cpp` — port the lyon/Levien parabola-integral schedule
(`glyphParabolaIntegral`, `glyphParabolaInvIntegral`, `glyphLevienInit`, `glyphLevienT`,
`GLYPH_LEVIEN_TOL = 2.0f`, count clamped to 64) and drive `parseGlyphShape`'s curve arm from
it instead of the fixed 8. 92 inserted / 2 deleted lines, one file, one function. The helper
block is a deliberate local twin of `swf.cpp`'s (distinct `glyph*` names, no shared symbol) so
the AVM1 and AVM2 glyph pipelines stay independent.

A/B, same machine, same Dawn, `--recompile` on both legs:

| comparison | budget | BEFORE | AFTER | verdict |
|---|---|---:|---:|---|
| `visual/fonts/duplicate_font` | 0 out | 3 | **0** | **FLIP → PASS** |
| `from_shumway/acid/acid-text-x` | 0 out | 6 | **0** | **FLIP → PASS** |
| `fonts/embed_matching/fallback_preferences` | 0 out (tol 3) | 156 | **24** | −85%, still fails |
| `fonts/embed_matching/match_style` | 0 out (tol 3) | 12 | **3** | −75%, still fails |
| `text/auto_size/height` | 3 out | 15 | **6** | −60%, 3 outliers from passing |
| `text/auto_size/return` | 18 out | 36 | **21** | −42%, 3 outliers from passing |
| `visual/fonts/glyph` | 0 out | 6 | **3** | one of the two pixels fixed |
| `from_shumway/acid/acid-text-6` `[output]`/`[frame5]` | 0 out | 198 / 12 | 198 / 12 | unchanged (AVM1) |
| `from_shumway/acid/acid-text-escape` | 0 out | 184 | 184 | unchanged (AVM1) |
| `visual/simple_shapes/text_field_mask` | 0 out | 56 | 56 | unchanged (AVM1) |
| `avm1/edittext_stylesheet` | 0 out | 6 | 6 | unchanged (AVM1) |

**Nothing worsened.** The split is exactly the mechanism: every AVM2-text row improves, every
AVM1-text row is byte-identical — the patch cannot reach the AVM1 pipeline.

`from_shumway/acid/acid-text-x` carries `known_failure = true`, which is a statement about
**Ruffle's trace**; the image golden is the single `output.expected.png` reference and we now
match it exactly (0 outliers, max diff 0), so this is a real gain, not a drift-to-Ruffle.
Neither flip appears in `ruffle-tests/ignored_tests.txt`, any per-suite `ignored_tests.txt`,
`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md` or
`FLASH_BUGS_REPLICATED.md`.

### Blast radius

`parseGlyphShape` feeds `Avm2FontData::glyph_pts`, read only by the AVM2 text painters
(`avm2_display.c` GPU path and `avm2_cpu_raster_text`). Every AVM2 SWF with an embedded font
re-flattens; nothing else in the corpus can move. Vertex counts change per glyph (adaptive,
1–64 vs a flat 8), so `glyph_pt_start` / `glyph_contour_ends` shift — all three arrays are
emitted together from the same pass, so they stay consistent by construction.

### Blast radius, continued — who consumes `glyph_pts`

`avm2_display.c:18275` (GPU glyph draw), `avm2_bitmap.c:2000` (`BitmapData.draw` of a
TextField, CPU raster) and `avm2_text.c` (collection helpers; null-check only). Nothing in
`SWFModernRuntime/src/libswf/` reads it — the AVM1 path is `shape_data`, untouched. The one
**trace-visible** consumer is `BitmapData.draw` + `getPixel`, so the change is not purely a
pixel change; CI should run graphics (per-change default) and the `full` categories are not
required, but a no-graphics leg is cheap insurance for that one handle.

---

## 5. HOLD — what the patch does not reach

* **`visual/fonts/glyph`'s last pixel `(446,108)`.** It sits on a long near-diagonal edge
  whose endpoints are *straight-edge* vertices — exact integers in the file, therefore exact
  in both engines, and untouched by any flattening change. §2's legs already showed a ±1-unit
  perturbation does not move it. That leaves the same residual the shape-side sibling
  measured in `w2-gfx-blend-tie` §3.2: a sample point landing exactly on a polygon edge, where
  the verdict is decided by the fill/edge rule and by which tessellator (libtess2 CDT here,
  lyon there) owns the boundary. **Completion mechanism:** compare our libtess2 CDT output
  against lyon's for one glyph and check whether the constrained edge through that sample is
  split (a CDT Steiner point on a constrained edge is the one thing that can move a boundary
  that both engines agree on geometrically). Not a one-line fix; do not price it as one.
* **The four AVM1 rows** (`acid-text-6`, `acid-text-escape`, `text_field_mask`,
  `edittext_stylesheet`). They go through `tag.c::textfield_glyph_render_cb` +
  `shape_data`, which §2 proved is already flattened on Ruffle's own schedule and quantised
  below the raster's resolution. w1 §4 classed `acid-text-escape`, `text_field_mask` and
  `edittext_stylesheet` as the *antialiased* sub-cluster anyway. **Completion mechanism** for
  `acid-text-6` (198 outliers, by far the largest AVM1 residual): triage it as a layout/metrics
  row, not a geometry row — its budget is unreachable by any sub-pixel argument.

---

## 6. Canary and regression results

**Standing render canary — CLEAN.** `ruffle-tests/render_canary.py` capture/compare, both
legs `--recompile`, `--jobs 3`, `--timeout 5400`, worktree copies of the 29 canary tests:

```
RENDER CANARY  before=before  after=after   29 tests / 61 comparisons
  IDENTICAL    61
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**Caveat, stated rather than hidden (playbook false-negative mode 10): the standing canary
set has essentially NO AVM2 embedded-font text coverage.** Its only text members are
`avm1/edittext_tag_indent` and `visual/edittext/edittext_border_transform`, both AVM1-route.
So "61 IDENTICAL" is a *no-collateral-damage* statement, not a positive confirmation that the
canary would have seen this change at all. The positive evidence is §4's own 12-comparison
board.

**`regression` suite — CLEAN.** Same driver, the five text-adjacent members
(`avm2_static_text`, `avm2_timeline_text`, `avm2_parent_child_static_text`,
`avm2_bitmapdata_draw_textfield`, `avm1_parent_child_text`):

```
RENDER CANARY  before=rbefore  after=rafter   5 tests / 1 comparisons
  IDENTICAL     1
  DIFFERS       0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

All five `pass` on trace in both legs. Four of them declare no `[image_comparisons]`, so the
one PNG is `avm1_parent_child_text`'s — but the trace axis, which is what
`avm2_bitmapdata_draw_textfield` actually grades (`BitmapData.draw` + `getPixel`), is
unchanged. That is the check that mattered for the trace-visible consumer named above.

**Final-binary re-verification.** The A/B legs used the binary built before a comment-only
tidy-up; both flips were re-run against the exact delivered source and still pass:
`visual/fonts/duplicate_font` 0 outliers / max diff 0, `from_shumway/acid/acid-text-x`
0 outliers / max diff 0.

**New canary gap to file:** the set needs an AVM2 embedded-font text member. The cheapest
CI-passing candidate created by this patch is `visual/fonts/duplicate_font` (tol 0, 1 cmp,
now passing) or `from_shumway/acid/acid-text-x`.

---

## 7. New unclaimed leads

1. **`text/auto_size/return` and `text/auto_size/height` are now 3 outliers from passing**
   (21 vs 18, 6 vs 3). Two rows, one shared mechanism, and the remaining error is small enough
   that the §5 CDT/edge-rule question could close both. Highest-value follow-up in this family.
2. **`fonts/embed_matching/fallback_preferences` 156 → 24** — the residual 24 is now small
   enough to forensically classify per-pixel; it was previously written off as a 52-pixel
   "hairline drift" row.
3. **`parseGlyphShape` still `lround`s to integer font units and still ignores the
   `StateNewStyles` / line-style records.** The quantisation is provably below the raster
   resolution (§2), so this is documentation, not a lead — but the *fixed-8* comment now
   removed was wrong for four sessions, and the same "well under half a pixel" reasoning
   appears elsewhere in `abc_timeline.cpp`; worth a grep.
4. **Two independent glyph pipelines exist** (`swf.cpp interpretShape` → `shape_data` for
   AVM1; `abc_timeline.cpp parseGlyphShape` → `glyph_pts` for AVM2) and nothing in the
   `_investigation` docs says so. Any future "glyph geometry" lead must first ask which VM the
   test is — w1 §4 mixed both into one 11-row cluster, which is why its single completion
   mechanism could not have worked. Suggest a line in
   `ruffle-tests/tests/swfs/_investigation/` and in memory.
5. **The AVM2 glyph path tessellates with libtess2 CDT while Ruffle uses lyon.** Now that the
   flattening matches, the tessellator is the next-largest structural difference in AVM2 text
   rendering — and it is shared with the AVM2 shape path (`resolve_shape_geom`).
