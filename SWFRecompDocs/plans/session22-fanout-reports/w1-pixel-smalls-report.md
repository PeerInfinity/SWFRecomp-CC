# Session 22 · wave 1 · `w1-pixel-smalls`: pricing the pixel near-passes and unclaimed smalls

**New files from this slot (stage by name):**
- `SWFRecompDocs/plans/session22-fanout-reports/w1-pixel-smalls-report.md` (this file)
- `SWFRecompDocs/plans/session22-fanout-reports/w1-pixel-smalls-prototype.patch` (measured prototype, 7 files; reverted from the tree, NOT for landing as-is; see §5)

**Box and provenance.** Cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn). Corpus is `download_tests.sh visual from_shumway from_gnash avm2 text fonts`. The script does not print a SHA; my `/root/ruffle` blobless clone, taken minutes later, is at `45366370e`. **Golden drift: none on my rows.** I re-graded every CI actual PNG (`origin/ruffle-image-results`, run `36515003936` @ `02df69d28`) against today's goldens with `verify_output.compare_images`, and all 30 rows reproduce CI's count exactly.

**Cloud-vs-CI fidelity: PROVEN on 18 rows.** My *before* renders are byte-identical (decoded RGBA) to CI's actual PNGs for `overlaps`, `MaskTest`, `displayobject_opaque_background`, `avm2_button_scroll_rect`, `cache_as_bitmap/avm2_button`, `color_matrix`, `fonts/glyph`, `scroll_rect_mask`, `fills_and_lines`, `graphics_draw_path`, `match_style`, `edittext_scroll .02`, `3_joystick`, `gradientTransform`, `doubleAndRegister`, `fallback_preferences` and `acid-text-6` (both comparisons). **Every verdict below is CI-grade**, not A/B-only.

## 1. Verdicts (GO/NO-GO), ranked by flips per LOC

The headline: **11 of the 24 board rows flip under one measured prototype (5 mechanisms), with 0 pass→fail** across 19 + 96 + 42 + 5 swept tests (§4). The brief's premise, that most of these rows are "the lavapipe-AA gap, least fixable", is **refuted for the quality="low" rows**. At 1 sample per pixel there is no AA. Every one of these rows is decided by *geometry*, and in four of the five mechanisms our geometry is provably not lyon's.

| # | row (cmp) | CI over-budget (ch) | mechanism (owner `file:line`) | prototype → | flip price | verdict |
|---|---|---:|---|---|---|---|
| 1 | `from_shumway/MaskTest` | 1 / 0 | **drawCircle top anchor = 99.95 px, not 100.** `gfx_draw_circle` computes `x + r*cos(3π/2)` = `100 − 1.8e‑16`, and the twip truncation (`gfx_quantize_twips`, Ruffle `Twips::from_pixels` = `as i32`) drops it to 1999 tw. Ruffle's `UNIT_CIRCLE_POINTS[4].0` is `+6.1e‑17`, so it lands on 2000 tw. (`avm2_display.c:9737` `gfx_draw_circle`; Ruffle `core/src/avm2/globals/flash/display/graphics.rs:528,813`) | **0** | 3 LOC: route drawCircle/drawEllipse through the existing `gfx_emit_round_rect` port (already used by drawRoundRect) | **GO** |
| 2 | `avm2/displayobject_opaque_background` | 2 / 0 | same circle, same pixel (133,5) | **0** | same patch | **GO** |
| 3 | `visual/simple_shapes/overlaps` | 12 / 0 | **Recompiler truncates flattened curve vertices to integer twips, in the y‑FLIPPED frame** (`SWFRecomp::Vertex` is `s32`; `swf.cpp:8558` `addCurvedEdgeLevien`, `(s32)` cast on `FRAME_HEIGHT − y`). lyon keeps the f32 points. | **0** | `Vertex.x/y` → `float` + drop the cast (4 LOC as prototyped; see §5 for the wave-2 scope) | **GO** |
| 4 | `visual/avm2_button_scroll_rect` | 6 / 0 | same | **0** | same patch | **GO** |
| 5 | `visual/cache_as_bitmap/avm2_button` | 6 / 0 | same | **0** | same patch | **GO** |
| 6 | `visual/filters/color_matrix` | 6 / 0 | **Timeline round joins and caps use a fixed 5-midpoint fan with vertices `std::round`ed to twips** (`swf.cpp` `drawLineJoin`/`drawLineCap`, `num_midpoints = 5`). lyon uses `2^round(log2(⌈sweep/(2·acos((r−tol)/r))⌉))` = 8 for this r = 10 px quarter join. The 2 pixels are 0.113 px inside the true arc, and our chord sags 0.123 px. The runtime twin `action.c::drawing_arc_segments` already implements lyon's rule. | **0** | ~25 LOC (port the existing runtime segment count into the recompiler) | **GO** |
| 7 | `visual/drawing_api/fills_and_lines` | 4 / 0 | **Drawing-API miter limit uses the wrong lyon semantic.** `lineStyle(5,…, "round", "miter", 1)`: we keep a miter only while `1/cos½θ < limit`, so limit 1 is *always* bevel. lyon's test is \|m\| > **2**·limit (`stroke.rs:2320` `miter_limit_is_exceeded`), and past it lyon draws `MiterClip` at `limit·0.5·half_w` (`stroke.rs:2114-2121`), not a bevel. Both missing pixels are miter tips (the 90° apex, and the closing 45° corner). The recompiler's timeline join already uses the 2·limit rule. (`action.c:30511` and twin `avm2_display.c:~8660`) | **0** (max diff 2 vs tol 2) | ~30 LOC ×2 (AVM1 + AVM2), plus the extra-verts bound 6 → 9 | **GO** |
| 8 | `avm2/graphics_draw_path` | 4 / 0 | **Cubics are not lyon's.** `drawPath` CUBIC_CURVE_TO uses 16 equal-t lines with each point twip-quantized; `cubicCurveTo` uses 8 fixed quadratics, each re-quantized. lyon_geom 1.0.6 `for_each_flattened_with_t` splits the (twip-truncated) cubic into `⌈(err/(432·(0.4tol)²))^(1/6)⌉` equal-t sub-cubics, applies `to_quadratic()`, and flattens each at **0.8·tol**, unquantized. (`avm2_display.c` `gfx_decode_path` case 6, `gfx_cubic_curve_to`) | **0** (max diff 0) | ~60 LOC (one shared `gfx_add_cubic`, cmd type 3) | **GO** |
| 9 | `visual/fonts/glyph` | 3 / 0 | **AVM2 glyph outlines: flattened points are `lround`ed to font units** (`abc_timeline.cpp:929`, `abc_devicefont.cpp:126,169`). Ruffle flattens the (integer) glyph curve in f32 and never rounds. A 200 px glyph on a 20480 em face is 0.0098 px per unit, so a 0.5-unit rounding moves edges by about the lavapipe subpixel (1/256 px). | **0** | ~12 LOC (store ×8 sub-units, divide at the 2 consumers) | **GO** |
| 10 | `fonts/embed_matching/match_style` | 3 / 0 | same | **0** | same patch | **GO** |
| 11 | `fonts/embed_matching/fallback_preferences` | 24 / 6 | same | **6 / 6, passes AT the limit** | same patch | **GO, fragile** (zero headroom; watch it like `edittext_border_filters`) |
| 12 | `avm2/graphics_gradients` | 349 / 0 | the circle part of row 1 (ring ±1 rim, 201 ch), then **translucent self-overlap of a width-10 stroke on a 10×20 ellipse** (alpha 0.5 double-blends where triangles overlap; diffs up to 73 scattered *inside* the ellipse) | 148 | band only; the residual is lyon's exact stroke triangulation | NO-GO (flip); band GO with row 1. Residual → `w1-stroke-staircase` |
| 13 | `visual/simple_shapes/scroll_rect_mask` | 20 / 0 | rows 3-5 mechanism for 12 ch; 4 px remain on the circle's right/bottom arc, all "ours missing" | 8 | unknown: the model fit needs scroll-rect clipping (not built) | HOLD, band GO. Completion: rebuild the scroll-rect placement in the model (`fitmodel.py`, §6) and read margins |
| 14 | `from_gnash/…/morph_test1` frame2-6 ×5, `Video-EmbedSquareTest` | 15 each | **All 6 comparisons are the same 4 pixels, shifted 140 px**: the Ming "xtrace" EditText glyph run at y 4-8 (s19 said frame1's band too). Embedded AVM1 DefineFont glyphs | 12 each | the rows-3-5 patch removes 1 of 5 px; 4 px remain | HOLD, band GO. Completion: the AVM1 glyph analogue of row 9 (where AVM1 glyph shape_data gets quantized), measured with the model on the glyph run |
| 15 | `morph_test1` frame1 | 216 / 0 | xtrace band + frame-1 content (s19) | 217 | — | HOLD (as s19) |
| 16 | `visual/cache_as_bitmap/edittext_scroll` .02 | 6 / 5 (1 over) | ONE glyph-edge pixel (top-left of "3") plus its (+1,+1) shadow copy. AVM1 `with_default_font`, so the recompiler's Noto fallback at `swf.cpp:~2700` (fixed 6 equal-t chords, `Coord = s32`) | 6 | a naive Levien port there made it **worse (6 → 12)** (reverted) | HOLD. Completion: port Ruffle's device-font glyph build (font units read as twips, no `s32` truncation of flattened points) as a whole, not the schedule alone |
| 17 | `from_shumway/3_joystick` | 4 / 0 (tol 128) | 2 px at the bottom tip of a highlight blob (339-340,125): ours ~75 % occluded (G 64) and golden lit (G 251/236). An occluding edge sits about 1 px higher in ours (quality high) | 4; tol-32 check 2468 → 2449 | — | HOLD. Completion: identify the occluder (mask or shape) in the scene, then margin-check |
| 18 | `avm2/graphics_simple_shapes` | 2 / 0 | inner edge of a width-4 stroke on a 10×20 ellipse: pixel centre (76.5, 8.5) is **2.0003 px** from the flattened ellipse at half-width 2.0, a **0.0003 px tie** (below lavapipe's 1/256 px grid) | 2 | — | **NO-GO** (sub-subpixel tie; stroke owner) |
| 19 | `from_shumway/doubleAndRegister` | 26 / 0 | the visible green boundary is the **inner edge of a white 1-px (20 tw) stroke** round the ellipse, ±1 alternation on the steep sides | 30 (worse) | — | **NO-GO here → `w1-stroke-staircase`** (hairline stroke stepping) |
| 20 | `from_shumway/acid/acid-text-6` ×2 | 198 / 12 | unchanged by every probe; 0/255 run-edge ties at tol 0 (s19/s21) | 198 / 12 | — | NO-GO (confirmed s19/s21) |
| 21 | `from_shumway/gradientTransform` | 9 / 0 | **Ruffle `known_failure`** on this comparison; edge-pixel gradient values ±11 | 9 | — | NO-GO (Ruffle is not the oracle; Flash-vs-golden question only) |
| 22 | `text/br_at_start`, `visual/drawing_api/drawing_order` | 3683 / 6658 | s21 HOLDs stand (unchanged: 3681 / 6658) | — | — | HOLD (s21 §3 completion mechanisms) |
| 23 | `visual/edittext/edittext_border_filters` | PASS 0/17, **max diff 32 = tol 32** | still passes at tolerance under the prototype (byte-stable max diff) | PASS | — | WATCH (no action) |
| 24 | `visual/blend_modes/*` | — | **CAPPED, cap NOT refuted.** I reproduce s19's float-vertex numbers exactly (add 5 → **6**, multiply 16 → **13**), and with the join patch multiply goes → **10**. The pixels move rather than vanish | — | — | NO-GO (cap stands) |

**Wave-2 yield, measured: +11 pixel flips** (rows 1-11), every one on a CI-identical render. +12 if `fallback_preferences`' zero headroom holds on CI, which it will: renders are byte-deterministic and my before-render matched CI.

### Refutations (rule 1)

1. **"Most of these near-passes are the lavapipe-AA gap" is wrong for quality="low" rows.** With 1 sample per pixel, lavapipe is a deterministic point-in-triangle test. A **Ruffle model** (lyon Levien f32 flattening of the SWF edges, even-odd at pixel centres) reproduces the golden of `overlaps` with **0 differing pixels over the full 550×400 frame**. The same model with *our* flipped-frame `s32` truncation reproduces **our** render with 0 differing pixels. Mechanism proven both ways, no AA involved.
2. **s19's "NO-GO on any vertex-precision fix" (w1-gfx-geometry §5) was right about `blend_modes` and wrong as a generalization.** Float vertices flip `overlaps`, `avm2_button_scroll_rect` and `cache_as_bitmap/avm2_button` outright (24 channels → 0), and move `scroll_rect_mask` 20 → 8 and `morph_test1` 15 → 12. Its "a recompiler A/B is not worth funding" therefore mispriced at least 3 flips.
3. **`MaskTest` and `displayobject_opaque_background` are not "1-px AA noise".** They are one f64 sign error in the circle's top anchor (Ruffle hard-codes `6.123e‑17` where `cos(3π/2)` gives `−1.8e‑16`), proven by a Ruffle-order model that matches the golden at 0 differing pixels.
4. **`fills_and_lines` is not a sibling's stroke-stepping row.** It is a miter-limit semantic (factor 2, and clip vs bevel). The fix is two predicates.

## 2. Wave-2 slots I would fund

| slot | scope | flips | risk / sweep |
|---|---|---:|---|
| **W2-A `vertex-precision`** (recompiler) | `Vertex` float + no cast in `addCurvedEdgeLevien` (rows 3-5); timeline round join/cap segment count from lyon + unrounded fan vertices (row 6) | **+4** | Every timeline shape with curves or round joins re-tessellates. Needs the render canary, the `regression` suite, `--recompile` everywhere, and an **avm1** sweep (not downloadable in my slot; see §4). Also check `bitmap_pixelsnapping`, morph shapes (they still truncate via `addCurvedEdge`), and hit-test parity (`shape_hit_test.c` reads `path_data`, which is unaffected). |
| **W2-B `drawing-api-lyon`** (runtime) | drawCircle/drawEllipse via `gfx_emit_round_rect` and zero-length side skip (rows 1-2); miter predicate + MiterClip (row 7, AVM1 + AVM2); lyon cubic flattening (row 8) | **+4** | Runtime-only, no recompile. **Note the zero-length-side skip** (`gfx_add_side`): without it the round-rect circle path regressed `avm2/graphics_bitmaps` (CI pass, 525/600 → 648/600 FAIL) through degenerate LineTos in the stroker. With it: 526/600. AVM1 miter users exist only in `avm1/` (not in my categories), so sweep them. |
| **W2-C `glyph-subunit`** (recompiler + 2 runtime consumers) | store AVM2 glyph points ×8 (or as float); divide at `avm2_display.c:~19027` and `avm2_bitmap.c:~2032` | **+3** (one at zero headroom) | AVM2 text only; 42 passing text tests swept, 0 moved to fail. Pick a cleaner representation than ×8 (float arrays) for landing. |

Total **+11**, from about 140 LOC across three independent slots. Each one is self-contained (A: `swf.cpp`/`swf.hpp`; B: `action.c` + `avm2_display.c` drawing code; C: `abc_timeline.cpp`/`abc_devicefont.cpp` + 2 consumer lines), so they can run in parallel without conflicts. A and C both touch the recompiler, so whoever lands second rebuilds.

Not funded: rows 12-24. Each names its completion mechanism above. The two worth an s23 diagnosis slot are the **AVM1 glyph analogue of W2-C** (6 comparisons of 4 px each across `morph_test1` and `Video-EmbedSquareTest`, plus maybe `edittext_scroll .02`) and the `scroll_rect_mask` residual.

## 3. `ignore = true` (harness semantics, image side)

Upstream `45366370e` has **10** tests with top-level `ignore = true`: `avm2/bitmap_pixelsnapping`, `avm2/bytearray_oom`, `avm2/filereference_save_and_load`, `avm2/number_tostring`, `from_avmplus/as3/AMF/AMFSerializer`, `from_avmplus/as3/ByteArray/ByteArray_bug662851_{32,64}bit`, `from_avmplus/as3/Definitions/Classes/ClassDef/StatClassSameNamePackage`, `from_avmplus/ecma3/Exceptions/bug127913`, `swf/swf_length_zero`.

**Only one has image comparisons: `avm2/bitmap_pixelsnapping [output]`** (CI fail, 3831 channels, tol 0; Ruffle's own reason is "big differences across rendering backends"). Honouring `ignore` on the image axis changes the CI totals from `588 cmps / 433 pass / 152 fail / 3 skip` to **587 / 433 / 151 / 3**. That is **0 flips**, the pixel denominator down by 1 and the pass rate up by about 0.05 pp. `verify_output.py` has no `ignore` handling at all (it is not read from `test.toml`). Recommendation: a board flag (`[ruffle-ignore]`) rather than a skip, as s21 suggested. The trace side (9 tests) is `w1-drift-avm2`'s call.

## 4. Evidence

### 4.1 Method
- `pxdump.py` (actual vs expected, per-channel over tol, 3×3 neighbourhoods) located every outlier. All quality="low" rows are pure-colour renders, so outliers are whole pixels on one shape edge.
- **The Ruffle model** (`levien.py` + `circ2.py`/`swfmodel_lib.py`/`fullmodel.py`): a port of the lyon_geom 1.0.6 quadratic Levien flattener in numpy float32, fed with Ruffle's exact command sequence (draw_round_rect_internal for the circle; SWF edges from our emitted `path_data` for timeline shapes), rasterised at pixel centres. Validated **both ways** on `overlaps` (model = golden at 0 px; model-with-our-truncation = our render at 0 px) and on the circle (model = golden at 0 px over 200×200; model with our `cos()` anchors = our render at 0 px).
- **Tie margins**: the distance from each outlier's pixel centre to the nearest model edge. `overlaps`: 0.025, 0.003, 0.0008, 0.006 px (three are at the 1/256 px grid; all four are flipped by exact vertices). Circle (133,5): 0.009 px inside the Ruffle chord. `color_matrix`: 0.113 px inside the true r = 10 arc against our 0.123 px chord sag. `graphics_simple_shapes`: 0.0003 px (true tie).

### 4.2 Per-row A/B (local == CI before; after = full prototype `w1-pixel-smalls-prototype.patch`)
```
avm2/displayobject_opaque_background [output] (1,0)          2 -> 0     PASS
avm2/graphics_draw_path [output] (0,0)                       4 -> 0     PASS
fonts/embed_matching/fallback_preferences [output] (3,6)    24 -> 6     PASS (at limit)
fonts/embed_matching/match_style [output] (3,0)              3 -> 0     PASS
from_shumway/MaskTest [output] (0,0)                         1 -> 0     PASS
visual/avm2_button_scroll_rect [output] (0,0)                6 -> 0     PASS
visual/cache_as_bitmap/avm2_button [output] (1,0)            6 -> 0     PASS
visual/drawing_api/fills_and_lines [output] (2,0)            4 -> 0     PASS (max diff 2)
visual/filters/color_matrix [output] (0,0)                   6 -> 0     PASS
visual/fonts/glyph [output] (0,0)                            3 -> 0     PASS
visual/simple_shapes/overlaps [output] (0,0)                12 -> 0     PASS
avm2/graphics_gradients (1,0)                              349 -> 148
visual/simple_shapes/scroll_rect_mask (0,0)                 20 -> 8
morph_test1 frame2..6 (5,0)                                 15 -> 12 (x5); frame1 216 -> 217
Video-EmbedSquareTest (5,0)                                 15 -> 12
from_shumway/3_joystick (128,0)+(32,2500)            [4,2468] -> [4,2449]
from_shumway/doubleAndRegister (0,0)                        26 -> 30   (stroke owner)
text/br_at_start (128,8)                                  3683 -> 3681
visual/blend_modes/add (2,0) 5 -> 6 ; multiply (2,0) 16 -> 10   (CAPPED family; measured, not priced)
unchanged: graphics_simple_shapes 2, acid-text-6 198/12, gradientTransform 9,
           edittext_scroll .02 6, drawing_order 6658; edittext_border_filters PASS (max 32 = tol)
```
All trace verdicts are unchanged on every row (pass, or `ruffle_matched` where CI was already `ruffle_matched`).

### 4.3 Regression sweeps (all `--mode=graphics --images`, `--recompile`; argued scope = families the mechanisms touch, all within my downloaded categories)
- **drawCircle/drawEllipse/drawRoundRect users** (19 tests, every one in my categories): 0 pass→fail after the zero-length-side fix. Small band moves on already-failing rows: `acid-shapes` tol-3 112 717 → 112 728 (still under its 113 000 limit; its failing tol-16/32 checks move +11/+7), `bitmapdata_draw` +156 at tol 0 (5 200 limit, already 39 803).
- **cubic / drawPath / GraphicsPath users** (6): 0 pass→fail; `graphics_bitmap_fill` 56/60 unchanged; `graphics_direct_commands` −4/−6/0/+2 per check (still failing).
- **Timeline-shape families** (`visual/{simple_shapes,cache_as_bitmap,fonts,gradient*,opaque_background,scale_rotation_cache,…}`, `fonts/*`: 37 CI-passing tests; plus the canary members `acid-gradient-0`, `acid-bitmap-fill{,-2}`, `timeline_as2_5`; all 13 `regression/` image tests; and all 40 CI-passing `from_shumway`/`from_gnash` image tests). The float-vertex + join prototype gave **149/149 previously-passing comparisons still passing**. The re-run on the final prototype is in §4.4.
- **Text** (42 CI-passing AVM2/AVM1 text and EditText image tests) with the glyph patch: **76/76 passing comparisons still pass**; traces unchanged (`acid-text-x`, `flash_text_TextField2` were already `ruffle_matched`; `TextField2` stays at 250/250, identical to CI).
- `GradientFillTest`'s trace `output_mismatch` is pre-existing (CI: 155 lines differ), and its image is identical (936/1070).

### 4.4 Final full-prototype re-sweep (96 tests)
I re-ran the same 96 tests (the 56 timeline/canary/regression tests plus the 40 `from_shumway`/`from_gnash` passing tests) on the **final** prototype, including the runtime miter, cubic and glyph hunks:
**149/149 previously-passing comparisons still pass.** The only image FAILs are the two capped `blend_modes` rows (add 6, multiply 10), which already fail on CI. The non-`PASS` traces are exactly the CI-baseline set: `GradientFillTest` `output_mismatch` (pre-existing), and `MaskTest-3`, `acid-text-x`, `flash_text_TextField2`, which were already `ruffle_matched` on CI.

**Not covered (wave 2 must cover):** `avm1/` (not in my download set: AVM1 drawing-API miter users and the timeline shapes there), `swf/`, `timeline/`, `mixed_avm/`, `stage3d/`, and avm2 tests outside the families above. Run the standing render canary plus an `images=true` CI run.

## 5. The prototype patch (`w1-pixel-smalls-prototype.patch`)

This is `git diff origin/master -- SWFRecomp SWFModernRuntime`, reverted from the tree. It is a **pricing prototype**, not a landing patch:
- `swf.hpp`/`swf.cpp`: `Vertex.x/y` → `float`; `addCurvedEdgeLevien` cast `(s32)` → `(float)`; `lyonArcSegments()` replaces `num_midpoints = 5` in `drawLineJoin`/`drawLineCap` and drops the per-fan-vertex `std::round`. **Wave 2 must audit every `Vertex` consumer** (signed-area `s64` math, `CROSS`, `pointOrientation`, morph pairing, bounds, `std::round` in the join's `p_start`/`p_end`/miter points, which still round). The build is warning-free, but integer-equality assumptions may hide behaviour changes outside my sweep.
- `avm2_display.c`: drawCircle/drawEllipse → `gfx_emit_round_rect`; `gfx_add_side` (skip zero-length round-rect sides); `gfx_add_cubic` (lyon cubic, cmd type 3, flattened at 0.8·tol), used by `cubicCurveTo` and `drawPath` case 6; miter predicate + MiterClip; extra-verts 6 → 9; glyph consumer ÷8.
- `action.c`: miter predicate + MiterClip; extra-verts 6 → 9.
- `abc_timeline.cpp`/`abc_devicefont.cpp`: glyph points ×8 (prototype representation); `avm2_bitmap.c`: consumer ÷8.

Each wave-2 slot should take only its own hunks (§2) and write the comments properly. The `// PROBE` markers flag every prototype site.

## 6. Tools (in my scratchpad, not committed; reproducible from this description)
`pxdump.py` (outlier dump), `regrade.py` (CI actual vs today's golden), `ab.py` (per-check A/B: CI before vs local after), `levien.py` (f32 lyon port), `circ2.py` (Ruffle vs our drawCircle model), `swfmodel_lib.py`/`fullmodel.py` (timeline-shape model from `path_data`, with `trunc=2` = our flipped-frame truncation), `fitmodel.py` (fit one character's translation to the golden; fails on clipped content), `swfgrep.py` (string search in decompressed SWFs).

## 7. New unclaimed leads
1. **AVM1 embedded-glyph precision** (row 14): the same 4 xtrace pixels fail 6 comparisons (`morph_test1` frame2-6, `Video-EmbedSquareTest`). One mechanism, up to +6 flips. Diagnose with the model on the glyph run.
2. **Morph shapes still truncate** (`addCurvedEdge` with `morph_counter`, and the morph equal-parameter stepping). The float `Vertex` makes removing that cast trivial; price it on the morph rows.
3. **Timeline joins/caps still `std::round` their two outer corners and miter point** (`p_start`/`p_end`/`m_point`); only the fan midpoints were unrounded in the prototype.
4. **AVM1 device-font fallback in the recompiler** (`swf.cpp:~2700`): fixed 6/8 equal-t chords, `Coord = s32`, a cubic split that is not lyon's. A port of Ruffle's device glyph build is the completion mechanism for `edittext_scroll .02`.
5. **`fallback_preferences` and `edittext_border_filters` sit exactly at their limits.** Add both to the canary so a 1-px drift is caught locally.
6. **`verify_output.py` ignores upstream `ignore = true`**: 1 image comparison and 9 trace tests (§3).

## LOCAL ORACLE REQUESTS
none. Every verdict here is from CI-identical local renders plus Ruffle source (`45366370e`) and the lyon 1.0.15 / lyon_geom 1.0.6 crate sources.
