# s23 wave 1: `w1-glyph-precision` report (AVM1 embedded-glyph precision + text-row watch)

**New files:** this report and `w1-glyph-precision-prototype.patch`
(`git diff origin/master -- SWFRecomp SWFModernRuntime`, one file, `SWFModernRuntime/src/libswf/tag.c`, +15/−4;
checked with `git apply -R --check`, then the source was reverted). Base: `origin/master` `ad99dc15`. Upstream Ruffle
tests: master **`0ddd12b6a`** (downloaded 2026-11-21; categories `visual avm1 avm2 from_gnash text fonts from_shumway
timeline swf import_assets mixed_avm audio stage3d`). Ruffle source: blobless clone at `0ddd12b6a`.

**Cloud fidelity: proven on 18 rows.** The `ruffle-image-results` branch is **still images run `38995363802`**
(s22 final, `38cf9b1a0`, commit `35f66723a`, 2026-10-17). Baseline run `44922638965` had **not** force-pushed when I
fetched it (re-fetched twice), so every fidelity check below is against `38995363802`. The code between `38cf9b1a0` and
my base is corpus-inert (BRIEFS_COMMON). My *before* renders are byte-identical (decoded RGBA md5) to CI's actual PNGs
for `morph_test1` frame1-6, `Video-EmbedSquareTest` (old toml, see drift), `edittext_scroll .02`, `text_field_mask`,
`acid-text-escape`, `acid-text`, `shape_test`, `place_object_test`, `br_at_start`, `bevel`,
`String_path_variable_button`, `style_changes_in_html` and `avm2/bitmapdata_draw`. **The verdicts below are CI-grade.**

## Verdicts

| # | item | verdict | priced flips |
|---|---|---|---|
| 1 | `morph_test1` frame2-6 + `Video-EmbedSquareTest` | **GO. Premise REFUTED:** this is not glyph-outline precision. The AVM1 EditText **baseline is fractional**: Ruffle truncates `ascent` to whole twips, we do not. | **+5** (`morph_test1` frame2-6). EmbedSquare would flip too (12 → 0 on its old golden) but **upstream drift took the row away** (below) |
| 1b | same patch, sweep | GO, no extra cost | **+3 more**: `visual/cache_as_bitmap/edittext_scroll` `.02`, `visual/simple_shapes/text_field_mask`, `from_shumway/acid/acid-text-escape` |
| 2 | `edittext_scroll .02` | **Premise REFUTED.** It does not need a port of Ruffle's device glyph build. The same one-line baseline truncation flips it (6/5 → 0/5). Port price, if it is ever wanted: see §2 | included in 1b |
| 3 | `avm2/bitmapdata_draw` t128 753/600 | **NO-GO.** AVM2 already truncates the baseline (Ruffle's model). A pure 1-px Flash shift passes t128 (428/600) and t64 (1240/1500) but breaks t0 (5001 → **5528**, limit 5200). That trades a passing check, so there is no flip | 0 |
| 4a | `shape_test` 16074 → 17911 | **ATTRIBUTED to `e62daeb6f` (w2-hairline-device-width)**, the only one of the four candidates whose reversal restores exactly **16074**. A low-quality hairline tie-break, not a regression of a passing row (`known_failure = true`) | 0 (row 15k+ away; Ruffle KF) |
| 4b | zero-headroom rows | re-measured on master (§4b); my patch leaves all three **md5-identical** | — |

**Patch total: +8 pixel flips, 0 pass→fail, 0 trace-status changes** over a 44-test argued sweep (every AVM1 test
in 12 downloaded categories with an image comparison and an EditText or `TextField` reference). Wave-2 ready as-is.

### EXPECTED-FLIP LEDGER (prototype patch)

Fail → pass (CI-grade; each *before* md5 = CI actual):
- `from_gnash/misc-ming.all/morph_test1` `frame2`, `frame3`, `frame4`, `frame5`, `frame6`: t5 12/0 → **0/0**
- `visual/cache_as_bitmap/edittext_scroll` `output.02`: t0 6/5 → **0/5**
- `visual/simple_shapes/text_field_mask` `output`: t0 56/0 → **0/0**
- `from_shumway/acid/acid-text-escape` `output`: t0 110/0 → **0/0**

Pass → pass with headroom moves (expect these md5s to change on CI):
- `visual/cache_as_bitmap/edittext_scroll` `output.01`: t0 0/5 → **2/5**
- `from_shumway/avm1/text-bind`: t128 64/100 → **80/100**, t64 583/600 → **592/600** (8 left; device-font Noto row)
- `visual/cache_as_bitmap/text`: t0 11049/12000 → 11055/12000 (t128 unchanged)

Fail → fail moves:
- toward golden: `shape_test` t50 17911 → **15994** (now below s22's interim 16074), `place_object_test` 41874 → 38238,
  `text/br_at_start` t128 3681 → 1672, `acid-text` 5019 → 3429, `acid-color-0` 17376 → 17326,
  `style_changes_in_html` 25024 → 24998, `bevel` 750 → 744
- away (tiny, rows far off): `String_path_variable_button` 999 → 1002 (limit 12), `morph_test1 frame1` 217 → 217
  (4 channels moved inside the xtrace band; the 217 is frame-1 content, s19)

md5-identical: every other row in the sweep, including all `visual/edittext/*` rows, `edittext_border_filters`, all
`edittext_caret_empty`, `edittext_selection` and `edittext_hscroll` frames, and **all seven filter-label rows**
(`glow`, `glow_without_composite_source`, `drop_shadow`, `bevel_inner/outer/full`, `glow_with_alpha_strength`).

## 1. Mechanism (owner `SWFModernRuntime/src/libswf/tag.c` `textfield_glyph_render_cb`)

Ruffle (`core/src/font.rs:280` `FontMetrics::ascent`) computes the baseline as
`Twips::new((ascent as f32 * height / scale) as i32)`, which truncates to a whole twip. `font_like.rs::evaluate` puts
every `GlyphShape::Swf`/`Drawing` glyph at `ty = baseline`. Ours (`tag.c:6432`) adds
`(float)ascent * font_height / em` unrounded. For the Ming xtrace field (embedded Bitstream Vera Sans, DefineFont2
em 1024, ascent 950, height 240 twips) that is **222.656 vs Ruffle's 222**, so our glyphs sit 0.656 twip
(0.033 px) low. On `quality = "low"` rows (1-sample point-in-triangle, no AA) that moves exactly the 4 glyph-edge
pixels whose centres lie inside that sliver: `(64,4) (16,5) (56,5) (30,8)`, 3 colour channels each = the 12 outliers.
The pixel-smalls report's "AVM1 analogue of the AVM2 glyph `lround`" premise is wrong: AVM1 glyph shapes already go
through `tessellateContours(..., keep_float = true)` (`swf.cpp:10928`), and Ruffle tessellates glyphs at the same
tolerance we do (`glyph.rs:87` `register_shape`, scale 1, lyon 0.1 px = our `LEVIEN_TOL_TWIPS = 2`).

Our *metrics* paths already truncate (`ng_shared.c:1694,1782,1906,2010,2027,2046`), and so does AVM2
(`avm2_text.c` `font_ascent`). Only the AVM1 render path disagreed with them.

Second hunk, same function: the **line pitch**. Ruffle `html/layout.rs:448` advances by
`max_ascent + max_descent + leading` (each truncated). We advanced by `font_height + leading`. For Vera that is
278 vs 240 twips per line (1.9 px per line). Prototype `tf_line_pitch_twips` adopts Ruffle's formula, for the newline
advance and for the `scroll` hidden-line offset. This hunk flips nothing on its own. In the 40-test leg (`after` = baseline hunk
only, vs `after2` = both hunks) it moved exactly three rows, all failing, all toward golden: `shape_test` −1959,
`place_object_test` −3699, `br_at_start` −2012. It changed no md5 of any passing row. (The 4 `from_shumway` rows were
only measured with both hunks; `acid-text` −1590 is the combined effect.) It also keeps caret and selection
tops at the line top (`sel_top`, `caret_top` subtract the truncated ascent).

Patch-scope caveat for wave 2: the pitch uses the field's default `font_height`, not Ruffle's per-line
`max(ascent)`/`max(descent)` over spans. Mixed-size HTML lines (`br_at_start` residual: the 4th line still sits
1-2 px high) need the per-line max from `info->runs`. That is the next step, not funded here.

Mode parity: the function is render-only (no `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arm touched; the caret hunk
sits inside `#ifndef NO_GRAPHICS`). `regression/avm1_parent_child_text` passes in both modes with the patch. Trace
status: unchanged on all 44 sweep tests.

### Upstream drift: `Video-EmbedSquareTest` left the board

`74323048b` "tests: Fix from_gnash/misc-ming.all/Video-EmbedSquareTest" (2026-10-17, inside `45366370e..0ddd12b6a`)
replaced `output.expected.png` with a **Flash high-quality capture**, set `quality = "high"`, added
`known_failure = true` (Ruffle fails it) and added `output.ruffle.png`. Proof that the mechanism covered it: in a
scratch suite with the **old** toml and golden (from Ruffle git `45366370e`), before = 12 outliers (md5 = CI actual
`bd8a13db…`) and after = **0, PASS**. Against the new golden: 1794 → 1782 at t5/limit 0. It is a different row now
(video plus HQ text), not a flip. Book it as drift, not yield.

## 2. `edittext_scroll .02`: price of the device-glyph port vs the cheaper mechanism

The cheaper mechanism exists, and it is §1. The row is one glyph-edge pixel of "3" plus its (+1,+1) shadow, and the
truncated baseline flips it 6/5 → 0/5. `.01` takes +2 (0 → 2/5, still passing).

If a Ruffle-faithful device-glyph build is still wanted later (for `text-bind` headroom, for instance):
`core/src/font/font_face.rs` reads TTF outlines with `Twips::new(x as i32)`. That is **integer truncation of every
outline point to a font unit**. It keeps cubics (`curve_to`) and builds a `Drawing` that lyon flattens. Ours is the
recompiler's Noto synth near `swf.cpp:~2700-2900`: stb_truetype points, a fixed equal-t chord count, s32, libtess2
via `tessellateContours(glyph_contours, NONZERO, tris)` with `keep_float = false` (`swf.cpp:2900`). A port means a
truncating outline sink, Levien/lyon flattening of quads, cubic support and `keep_float`: ~150-250 recompiler lines
and a regenerate of every device-font table. **Priced: 0 flips today** (no failing row is left that names it).
s22's naive Levien attempt went 6 → 12 because the baseline error, not the outline, owned the pixel. Not funded.

## 3. `avm2/bitmapdata_draw`: NO-GO

- Current: t0 5001/5200 pass, t64 1443/1500 pass, **t128 753/600 fail** (md5 = CI actual). The outliers sit in two
  text bands (rows 2-14 and 32-41, x 3-85). Everything else matches.
- Glyph comparison (ours vs the golden): the cap top is the same row (3), but Flash's glyphs are **one pixel taller**.
  The baseline is row 11 (Flash) vs row 10 (ours), and the x-height is 7 vs 6 rows. That is Flash's hinted device
  rasterizer (vertical metrics snapped to the pixel grid) on top of the golden's AA, against our aliased CPU scanline
  (`avm2_bitmap.c:1957` `glyph_raster_core`, point-sampled crossings). It is not a baseline rule: AVM2 already places
  the baseline at Ruffle's truncated `font_ascent` (`avm2_text.c:4349`).
- Measured counterfactual: shifting our two text bands down 1 px gives t0 **5528**/5200 (fails), t64 1240/1500,
  t128 428/600. The best possible "baseline rule" therefore trades the t0 check for t128 and is still a fail.
  A Flash cap-height-hinting rule would also move every Ruffle-golden AVM2 text row (`text-bind`-class, `fonts/*`),
  all Ruffle-model today. Do not trade a passing row.
- **Completion mechanism:** coverage AA in `glyph_raster_core` (fewer t0/t64 channels) **plus** Flash-style vertical
  hinting gated to Flash-capture goldens. There is no way to gate that honestly. It stays a visible fail.

## 4a. `shape_test` 16074 → 17911: attribution

History (`from_gnash/misc-ming.all/_results/image_results_graphics.json`): interim images run (`57980e8dd`, code
`939652298`) **16074**; final run (`ebdb98624`, code `38cf9b1a0`) **17911**. Source commits in `939652298..38cf9b1a0`
that can reach an AVM1 Ming row are `e62daeb6f`, `1edcde2e1`, `9821a086a` and `edee471cd`. I reverse-applied each one
alone on clean master and rebuilt the recompiler with `--recompile` where the commit touches `SWFRecomp/`:

| reversed | shape_test t50 |
|---|---:|
| none (master) | 17911 (md5 = CI actual) |
| **`e62daeb6f` w2-hairline-device-width (stroke re-expansion)** | **16074** |
| `1edcde2e1` w2-filter-fixes (capture change) | 17911 |
| `9821a086a` w2-font-registry | 17911 |
| `edee471cd` w2-geom-port | 17911 |

(`w2-float-verts` landed before `939652298`, so it is in both numbers and cannot be the cause.)

What moved (945 px, bbox (99,139)-(280,280), the hairline-outlined shapes): before `e62daeb6f` the outlines were
**2 px** wide (rows 139-140 / cols 219-220). After it they are **1 px**, the correct device width, but on row 139 /
col 219. Flash's golden draws the 1-px line on row **140** / col **220**. The old 2-px stroke overlapped the golden
pixel by accident; the correct-width stroke lands on the other side of a pixel-centre tie. This is `quality = "low"`
(point sampling): a 1-px hairline centred on an integer pixel boundary covers both centres as a tie, and our
top-left fill rule keeps the upper/left one where Flash keeps the lower/right one. **`e62daeb6f` is not wrong on
width.** The worsening is the tie-break.
- Not a regression of a verdict: the test is `known_failure = true` (Ruffle fails it too) and is ~16k outliers from
  its limit of 0.
- Lead (stroke family, not mine): for aliased (quality=low) hairlines whose centreline lies on a pixel boundary,
  Flash picks the +0.5 px side. A +epsilon centreline bias in the low-quality hairline arm of `e62daeb6f`'s
  re-expansion would test it. Needs an A/B on `acid-small .01/.05` (the rows `e62daeb6f` flipped) before any claim.

## 4b. Zero-headroom rows (clean master; my patch leaves all three md5-identical)

| row | check | outliers | max_diff | margin |
|---|---|---:|---:|---|
| `fonts/embed_matching/fallback_preferences` | t3 / 6 | **6** | 255 | **0 outliers** of headroom (6 channels > tol; 0 at tol) |
| `visual/drawing_api/fills_and_lines` | t2 / 0 | 0 | **2** | 0 outliers allowed; **126 channels sit exactly at tol 2** (51806 at 1). Any +1 on one of those 126 fails it |
| `visual/edittext/edittext_border_filters` | t32 / 17 | 0 | **32** | 17 outliers of headroom; **5 channels sit exactly at tol 32** (0 at 31) |

All three are AVM2-text, drawing-API or border-only rows that my AVM1 text change does not reach (measured).

## Refutations

1. "AVM1 embedded-glyph outline precision" (playbook §21, s22 w1-pixel-smalls row 14): **refuted**. AVM1 glyph
   outlines are already float, at Ruffle's tolerance. The 4 px are a 0.656-twip baseline error.
2. "`edittext_scroll .02` needs a port of Ruffle's device glyph build": **refuted**. The same baseline truncation
   flips it.
3. "`Video-EmbedSquareTest` is the 6th comparison of the same mechanism": true at `45366370e`, **void at
   `0ddd12b6a`** (upstream re-goldened it to Flash HQ + `known_failure`).
4. "`shape_test` worsened from the stroke re-expansion or the filter capture change": the stroke re-expansion, yes
   (sole cause). The filter capture change is inert on this row.
5. Sibling boundary: `w1-filter-label`'s rows (`glow`, `drop_shadow`, `glow_without_composite_source` 3/0; `bevel_*`,
   `glow_with_alpha_strength` 42/18) are **md5-identical** under my patch. **My mechanism is not theirs.** (Their
   label baselines are evidently already whole-twip, or their pixels come from the filter pass.) `bevel` itself moves
   750 → 744, which is its filter-edge row, not the label.

## New unclaimed leads

1. **Per-line max metrics for the AVM1 render pitch** (`br_at_start` 1672/8, `style_changes_in_html`): Ruffle takes
   `max_ascent`/`max_descent` over spans on each line (`layout.rs:500-506`). The patch uses the field default.
2. **Low-quality hairline tie-break** (§4a): Flash's +0.5 px side. That could also be what keeps some other
   `quality=low` Ming rows off.
3. **`text-bind` headroom** after the patch: t64 592/600. The remaining diff is device-font geometry (the §2 port
   would be the mechanism); watch it.
4. `bitmapdata_draw`: coverage AA in `glyph_raster_core` alone would cut t0/t64 (it cannot flip t128). Price it with
   the AVM2 text owner.
5. Harness: `verify_output.py` grades `known_failure = true` image rows (`shape_test`, now `Video-EmbedSquareTest`)
   like any other fail. If Ruffle's runner treats an unexpected pass there as a failure, our board counts may differ.
   Check how the image board books KF rows.

## LOCAL ORACLE REQUESTS

none
