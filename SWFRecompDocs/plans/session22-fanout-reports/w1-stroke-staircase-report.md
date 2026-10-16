# w1-stroke-staircase — session 22, wave 1 (cloud)

**New files (all under `session22-fanout-reports/`):**
- `w1-stroke-staircase-report.md` (this file)
- `w1-stroke-staircase-prototype.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime`
  (recompiler only: `SWFRecomp/include/swf.hpp`, `SWFRecomp/src/swf.cpp`; the runtime is untouched)
- `w1-stroke-staircase-tools/`: `swfparse.py` (a minimal DefineShape/PlaceObject parser),
  `strokemodel.py` (replicas of our stroke geometry and of lyon's, plus a pixel-centre rasteriser),
  `decomp.py` and `fitglow.py` (the attack below), `grade.py` (grades canary captures with
  `verify_output.compare_images`, so the numbers are CI's own), and the two raw grade tables.

Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn). Corpus: `download_tests.sh visual from_shumway avm1
avm2 text fonts from_gnash` from upstream master on 2026-10-16; the `/root/ruffle` clone made in the
same minute is at `45366370e`. Base: origin/master `be8f4b62`.

**Fidelity proof.** For **all 39 ledger rows** (the filter family, the hairline rows, the masks
pair, blend rows, the acid rows), my cloud *before* render is byte-identical (RGBA) to the CI actual
PNG on `origin/ruffle-image-results`. Every absolute verdict below is therefore CI-grade.

---

## 0. Verdicts

| claim / item | verdict |
|---|---|
| "The filter family's residual is 1-px stroke staircase parity" | **CONFIRMED, and the mechanism is narrower and cheaper than the brief assumed.** It is not lyon vs our join/cap geometry, not MSAA, not the stroke-centre half-pixel, not the filter phase. It is **integer-twip quantization of computed vertices in the recompiler**: (1) Levien curve points truncated to integer twips, (2) stroke offset corners rounded to integer twips. A float model of the same geometry reproduces Ruffle's golden stroke mask **exactly (0 px)**. |
| Same mechanism on fills | **YES.** libtess2 fill output is `lround`ed and fed from the truncated curve points. This is the whole **s18 §3-E "45° 1-sample rasteriser tie" NO-GO** family (the 12 blend_modes rows, scrollRect rows, `avm2_button_scroll_rect`, ...) and the **hard-dispositioned `simple_shapes/masks` pair**. Both are **REFUTED as ties**: they flip. |
| Round join/cap arc count | Separate mechanism (s18 "mechanism A"): a fixed 5-segment fan instead of lyon's tolerance-driven count. Removing the rounding exposed it on `color_matrix`; porting lyon's rule flips `color_matrix` and `simple_shapes/layers`. |
| `blur_size_grows`: s21's "[Blur, Blur] halo / possible +1" | **REFUTED.** It flips with the stroke fix alone (546 → 0); the blur is not involved. |
| **Prototype (ABC)** | **GO for wave 2: +22 CI-grade flips, −1 regression (`acid-small .05`, explained, with a named completion mechanism), 0 trace moves across 120 tests, hit-test traces unchanged.** |

### Priced flips (prototype ABC, graded locally against goldens; CI-grade per the fidelity proof)

| # | comparison | tol / max | before (= CI) | after |
|---:|---|---|---:|---:|
| 1 | `visual/filters/blur_size_grows` | 3 / 0 | 546 | **0** |
| 2 | `visual/filters/color_matrix` | 0 / 0 | 6 | **0** |
| 3 | `visual/simple_shapes/masks` ¹ | 0 / 0 | 181 | **0** |
| 4 | `visual/simple_shapes/masks_equal_clipdepth` ¹ | 0 / 0 | 181 | **0** |
| 5 | `visual/simple_shapes/overlaps` | 0 / 0 | 12 | **0** |
| 6 | `visual/simple_shapes/scroll_rect_mask` | 0 / 0 | 20 | **0** |
| 7 | `visual/simple_shapes/heavy_tesselation` | 0 / 3 | 2439 | **3** |
| 8 | `visual/simple_shapes/layers` | 0 / 0 | 23 | **0** |
| 9 | `visual/avm2_button_scroll_rect` | 0 / 0 | 6 | **0** |
| 10 | `visual/cache_as_bitmap/avm2_button` | 1 / 0 | 6 | **0** |
| 11-22 | `visual/blend_modes/{multiply, add, hardlight, alpha_no_layer, darken, difference, erase_no_layer, invert, lighten, overlay, screen, subtract}` | 2-4 / 0 | 16, 5, 21, 18, 16, 7, 18, 24, 5, 19, 5, 7 | **0 (all 12)** |
| **−1** | `from_shumway/acid/acid-small output.05` | 80 / 3000 (3-check) | PASS 2997 | **FAIL 3027** |

¹ These carry the hard `<!-- image-axis -->` ACCEPTED_DIFFS entry ("curve flattening / AA, 359
interior channels"). The entry should be **retired** when the patch lands (playbook §3 table too).
They count on CI's pass total either way; on the board they move from "hard-excluded" to passing.

### Band moves on rows that still fail (ledger, before → after)

| comparison | budget | before | after | residual owner |
|---|---|---:|---:|---|
| `filters/glow` | 2/0 | 2659 | **3** | one EditText label glyph pixel (the comma of "K,I" at (514,248)) |
| `filters/glow_without_composite_source` | 3/0 | 2917 | **3** | same pixel |
| `filters/drop_shadow` | 2/0 | 3875 | **3** | same pixel |
| `filters/bevel_inner` / `bevel_outer` / `bevel_full` | 4·3·4 / 18 | 1018 / 1450 / 1158 | **42 / 42 / 42** | 14 scattered label-glyph pixels ("0%/50%…" text, depth-0 text path) |
| `filters/glow_with_alpha_strength` | 4/18 | 1123 | **42** | same label pixels |
| `filters/bevel` | 3/6 | 3091 | 750 | one horizontal row at y=305 across every tile (bevel filter edge row, not geometry) |
| `filters/drop_shadow_angles` | 2/0 | 6934 | 549 | off-stage source (sibling `w1-offstage-filter`) |
| `filters/displacement_map` | 20/72 | 1436 | 408 | bands at the filter-layer edges (y≈334-336, 678): sibling scope |
| `from_shumway/doubleAndRegister` | 0/0 | 26 | 2 | 1 px |
| `from_shumway/acid/acid-gradient-2` | 1/0 | 38 | 3 | 1 px |
| `from_shumway/acid/acid-scale` | 0/0 | 106 | 8 | 4 single-pixel ties on SCALED shapes (lead L2) |
| `from_gnash/.../morph_test1` frames 2-6 | 5/0 | 15 each | 12 each | s18: status-text overlay, not geometry |
| `from_gnash/.../Video-EmbedSquareTest` | 5/0 | 15 | 12 | |
| `acid-small output.01` | 80/3000 | 3657 | 3624 | wrong stroke width (L1) |
| `acid-color-0`, `acid-morph`, `acid-stroke-0`, `acid-text-escape`, `BeginBitmapFill` (KF), `morph_test1 frame1` | | | ±0-0.7 % | not this mechanism |

Unmoved (byte-identical before/after): `any_blur_scales_with_screen`, `text_field_mask`,
`cache_as_bitmap/drawing_api`, `fonts/glyph`, `definefont4`, `movieclip_begin_gradient_fill`,
`movieclip_line_gradient_style`, `MaskTest`, `acid-gc`, `acid-text-6` ×2, `acid-shapes`,
`3_joystick`, `sprite_with_frames`, `bitmapdata_draw_rotation`, `displayobject_opaque_background`,
`avm2/graphics_simple_shapes`, `edittext_scroll .02`. The drawing-API rows are expected not to
move: runtime strokes (`action.c` ~30355+, `avm2_display.c`) are already built in float.

---

## 1. The attack (step 1): it IS stroke stepping, and only the stroke

`filters/glow` (`quality = "low"`, so both sides sample each pixel centre once, with no AA).
Row-by-row dump of the blue channel at x=34..43, y=58..73 (ours/expected):
the glow ring differs by exactly 10 levels **only on rows 63-71**, and on rows 65 and 69 we have an
extra stroke-core pixel (153) one column left of Ruffle's. The glow is a blur of the source, so an
extra source pixel raises the glow around it. That is the stroke stepping, then blurred.

To separate stroke geometry from the blur kernel, filter bounds and quality, I extracted the
**unfiltered stroke core mask** (pixels exactly equal to the line colour (255,255,153)) from the TL
copy of both PNGs. Then I rasterised two geometric models of shape 1's 1 px strokes, at pixel
centres, over a grid of sub-pixel device offsets (±1 px in steps of 0.05):

| model | best match vs OUR actual | best match vs Ruffle's golden |
|---|---|---|
| "ours" (replica of `swf.cpp`: Levien in twips with truncation, rounded offset corners, 5-segment round joins) | **2 px** xor @ (+0.45, −0.45) | 29 px |
| "float" (the same Levien schedule and joins, no quantization; lyon strokes an f32 path) | 30 px | **0 px** xor @ (+0.45, −0.45) |

Both best fits sit at the **same** device offset (the placement at (37.05, 8.95) px snapped to
(37.5, 8.5) by the s21 filter snap), so **the phase is right**. Only the vertex quantization
differs. Decomposition at that phase (`decomp.py`, xor vs golden):

| flatten points | offset corners | xor vs golden |
|---|---|---:|
| truncated (ours) | rounded (ours) | 30 |
| truncated | float | 24 |
| float | rounded | 13 |
| float | float | **0** |

Both quantizations contribute, and only removing both reaches 0. Also excluded: a stroke-width,
min-width or join difference (width 20 twips = exactly 1 px; the round-join fan resolution is
irrelevant at r = 0.5 px), MSAA (both sides have 1 sample), and the half-pixel stroke centre (that
would have shown as a phase offset between the two fits).

The prototype then confirmed it in the real pipeline: after variant A, the stroke-core mask equals
Ruffle's **in all four quadrants** (0 px xor in each). The remaining 527 glow outliers were green
leaf-fill edge pixels, and variant B (fills) removes those (→ 3).

**Board-wide signature.** I priced by rendering, not by a classifier. I took 60 failing rows plus
the 61-test standing canary (121 tests, 162 comparisons) and argued for the selection: every failing
row with recompiled curved or stroked geometry, at `quality = "low"` or near-pass, plus the
hairline/acid/gnash rows the brief named. Rows outside it (video ×13, Stage3D, PixelBender,
BitmapData, EditText/text, loaders) contain no recompiled curve geometry, so this mechanism cannot
move them. Result: **this one mechanism (A + B) owns 20 failing rows outright, and C adds 2**. It
also owns most of the residual on 9 more filter rows.

---

## 2. Mechanism, `file:line` on both sides

**Ruffle** (`45366370e`):
- `render/src/tessellator.rs:385-388` `ruffle_path_to_lyon_path`: every point becomes
  `Twips::to_pixels() as f32`, so the path is float from here on.
- `render/src/tessellator.rs:177-221`: stroke = lyon `StrokeTessellator` with
  `line_width = max(width_px, 1/scale)` and `tolerance = DEFAULT_TOLERANCE(0.1)/scale`. All
  flattened points and offset corners stay `f32` (`RuffleVertexCtor`, :465).
- `render/src/tessellator.rs:166-175`: fill = lyon `FillTessellator`, f32 in and out.
- lyon_tessellation 1.0.x `stroke.rs` `tessellate_round_join` / `tessellate_round_cap` →
  `num_arc_subdivisions` (`2^round(log2(ceil(angle/step)))`, `step = 2·acos(1 − tol/r)`). Ruffle's
  Cargo.lock pins 1.0.15. I read lyon HEAD `da19a62` (that tag is not fetchable shallow); the
  arc-count rule there is the one ported.

**Ours** (origin/master `be8f4b62`):
- `SWFRecomp/include/swf.hpp:53-58`: `struct Vertex { s32 x, y; s32 morph_index; }`. Every
  computed position is forced onto the integer twip grid.
- `SWFRecomp/src/swf.cpp:8547-8563` `addCurvedEdgeLevien`: `v.x = (s32)(…)`, which **truncates**
  each flattened curve point. In the y-up internal frame (`last_y = FRAME_HEIGHT - y`, :8859) that
  means x floors and SWF-y ceils, a systematic bias of up to 0.05 px.
- `swf.cpp:11458-11785` `drawLineJoin` / `drawLineCap` / `drawLines`: every offset corner is
  `(s32) std::round(...)`, `u16 halfwidth = width/2` (integer division), and the join/cap fan is a
  fixed `num_midpoints = 5`.
- `swf.cpp:202-270` `tessellateContours` (libtess2): input is the truncated ints, output is
  `std::lround`.
- Emission `swf.cpp:~10735` (fills) and `~10822` (strokes): `(float) t.verts[j].x`. The
  `shape_data` table already stores floats, so nothing downstream needs integers.

## 3. The prototype (`w1-stroke-staircase-prototype.patch`, recompiler only)

- **`Vertex` gets two trailing `s16` fields**, `fx_frac` / `fy_frac`: the sub-twip remainder in
  units of 1/16384 twip. x/y stay the integer copy that the fill path-graph keys on, so linking,
  Johnson cycles and earcut are unchanged. Nothing outside the computed-vertex sites ever sets them.
- **A — strokes:** `addCurvedEdgeLevien` records the remainder. `drawLines` / `drawLineJoin` /
  `drawLineCap` compute from `strokeX/strokeY` (exact = x + frac) in double with `halfwidth =
  width/2.0`. They return `strokeVertex(...)` (integer + remainder), and the stroke emission writes
  the exact value.
- **B — fills:** `tessellateContours(..., keep_float=true)` for shape fill groups only. It feeds
  libtess2 the exact positions and records the remainders of its output; the fill emission writes
  the exact value. Glyph outlines (`keep_float=false`) and the morph earcut path are unchanged.
- **C — round joins/caps:** `strokeArcSegments(r, angle)` ports lyon's rule with tolerance
  2 twips (= 0.1 px at scale 1, the `LEVIEN_TOL_TWIPS` convention). The fan loops are now
  integer-stepped (the old `current_angle < end_angle` float loop could gain or lose a point).

**Memory trap found and fixed in the prototype.** My first cut stored `bool + 2×float` (Vertex
12 → 24 B). `heavy_tesselation`'s recompile then hit `std::bad_alloc` under `verify_output.py`'s
`ulimit -v 4194304` and silently dropped the shape (2439 → 1 379 656 outliers, a blank render).
Peak RSS: master 2.55 GB, 24-B Vertex 3.61 GB (OOM), **16-B Vertex 3.05 GB (OK, and it flips the
row)**. Wave 2 must keep `sizeof(Vertex) == 16` or move the remainder to a side table. The headroom
is now about 1 GB of address space on that SWF, so log RSS for it in the wave-2 report.

### Canary (standing `render_canary_tests.txt`, 61 tests / ~100 comparisons, before vs ABC)

- **No canary comparison flips pass → fail except `acid-small output.05`.** Its own canary comment
  calls it the "cap/join tripwire [that] PASSES while being drawn with the wrong … styles".
- MOVED but still PASS at the same counts: `cache_as_bitmap/masks` .01-.07,
  `regression/avm2_timeline_stroke_gradient`, `regression/avm2_timeline_gradients`,
  `acid-blend-2` .10/.15/.20/.26/.40, `filters/blur_scales_with_screen`. These are geometry moves,
  and every one stays at 0 outliers.
- MOVED and improved: `simple_shapes/masks`, `filters/drop_shadow`, `filters/color_matrix`,
  `blend_modes/multiply` (now passing), `doubleAndRegister`, `acid-small .01`, `simple_shapes/layers`.
- Every other canary comparison is **md5-identical**, including all text, EditText, bitmap,
  Stage3D and regression mask rows.
- **Trace axis:** 0 of 120 captured tests moved (status and line counts). No-graphics hit-test
  sweep, before vs ABC: `avm1/{hittest_morph, hittest_morph_input, hittest_winding_rule,
  movieclip_hittest, hitarea_sweep}` and `avm2/{displayobject_hittestpoint(_boundary),
  hittest_morph, button_hittest, mouse_pick_avm1_root}` all PASS → PASS.
  `movieclip_hittest_shapeflag` mismatches identically before and after (md5 of the diff is equal;
  it is an ACCEPTED_DIFFS entry).

### The −1: `acid-small output.05` (refutes nothing, but prices the trade)

The shape (20-twip strokes) is drawn under a sprite scale of 0.43 × root scale 0.73/0.50, so its
strokes are 0.2-0.4 **device** px wide. Ruffle clamps them to `max(width, 1/scale)` = 1 device px
(`tessellator.rs:178-186`); we never clamp a timeline stroke by device scale (`drawLines` clamps to
20 **twips**, i.e. stage px). That is the test's own `# FIXME The output differs wrt. stroke
widths`. Our strokes are the wrong width both before and after. The prototype moves single
4×MSAA samples on that wrong geometry: 16 pixels improve, 27 worsen, net +30 channels against a
row that passed by 3. **Completion mechanism:** lead L1 (device-scale minimum stroke width). It
should re-flip `.05`, and it is the real fix for `.01` (3624/3000) and `acid-scale`. Without L1,
wave 2 lands +22/−1 and books the −1 as the price of a correct change on a row that passes by luck.

---

## 4. Wave-2 slots I would fund

1. **`w2-float-verts` (GO, recompiler only, ~1 slot):** productionize ABC as-is.
   - Keep `sizeof(Vertex) == 16`; assert it with a `static_assert`.
   - Re-measure `heavy_tesselation` RSS under `ulimit -v 4194304`.
   - Retire the `simple_shapes/masks` image-axis ACCEPTED_DIFFS entry (ACCEPTED_DIFFS.md and the
     playbook §3 table), and mark s18 §3-E NO-GO as refuted in the playbook.
   - Ledger = the 22 flips above, −1 `acid-small .05`.
   - Canary additions: `visual/simple_shapes/overlaps` (tier 1 once graded: tol 0, a curve-fill
     witness), `visual/blend_modes/add` (tier 1), `visual/filters/glow` (tier 2, the stroke witness).
   - Needs `--recompile` on every leg. Add `--mode` no-graphics hit-test checks as above.
   - Before landing, run a broader argued sweep over the remaining CI-passing rows with curved
     timeline geometry outside the canary. A geometry change can move passing near-budget rows
     (`acid-small .05` was one), and I did not render the whole passing corpus.
2. **`w2-hairline-device-width` (diagnose + prototype, unpriced but strong):** Ruffle re-tessellates
   a shape per draw scale (`core/src/display_object/graphic.rs` `TessellationCache`, then
   `tessellate_shape_with_scale`). The scale feeds both the 1-device-px minimum width and the
   flattening tolerance `0.1/scale`. Our strokes are frozen at compile time in twips.
   - Candidate rows: `acid-small .01/.05`, `acid-scale` (8 → 0?), `acid-stroke-0` (KF, so beware),
     gnash `simple_loop_test` (its ACCEPTED_DIFFS says "hairline-stroke pixel-snapping"),
     `strokes/scale` (KF).
   - Cheapest prototype: emit stroke CENTRELINES (plus width and caps) alongside the triangles,
     then re-expand thin strokes at runtime when `width·scale < 1 px`.
3. **Text label residual (fold into whichever slot owns EditText default-font outlines):**
   - `glow`, `glow_wcs` and `drop_shadow` are each **one pixel** from passing (3/0): the comma tail
     of "K,I" at (514,248).
   - `bevel_*` ×3 and `glow_with_alpha_strength` are at 42/18, all label pixels. That is 7 rows
     within reach of a text-only fix once w2-float-verts lands.

## 5. Refutations / corrections of record

- **s18 `w1-gfx-smalls` §3-E "45° 1-sample rasteriser ties, NO-GO"**: refuted. They were vertex
  quantization (Levien truncation + libtess2 `lround`), and all 12 blend rows plus the scrollRect,
  button, mask and overlaps rows flip.
- **ACCEPTED_DIFFS `simple_shapes/masks` + `masks_equal_clipdepth` (image-axis, "359 interior
  channels, curve flattening / AA")**: refuted as permanent. Both reach 0.
- **s21 "`blur_size_grows` vertical large-blur halo offset, [Blur, Blur] folding, possible +1"**:
  refuted. It is stroke stepping, and it flips with A alone.
- **s21 "(B) lyon flattening / stroke edge rule"**: the flattening SCHEDULE was already right (the
  Levien port). What was wrong is that its output was truncated to integers. The "stroke edge
  rule" is not involved.
- **`w2-curve-subdiv-report` "lroundf refuted"** (the comment in `addCurvedEdge`): it is consistent
  with this report. Rounding to integers is still quantization; keeping the remainder is the fix.
  That note should be amended when the patch lands.

## 6. New unclaimed leads

- **L1 device-scale stroke minimum width / tolerance** (above). Owner: `drawLines` (swf.cpp) vs
  `tessellator.rs:178-189`.
- **L2 scale-aware flattening tolerance**: Ruffle uses `0.1/scale` for fills too
  (`tessellator.rs:168`), while we fix 2 twips at compile time. `acid-scale` keeps 4 single-pixel
  ties on scaled shapes. Likely the same slot as L1.
- **Morph shapes keep the integer path.** `addCurvedEdge` (equal-parameter steps, truncation)
  and earcut `fillShape` are both used by morphs. `morph_test1` frame1, `acid-morph` and
  `cache_as_bitmap/morph` may want the same remainder treatment (the `morph_end_shape_data` emission
  already takes float deltas).
- **Device-font glyph contours** (`swf.cpp:2662+`, a fixed 6/8-step subdivision, `Coord` ints) and
  `keep_float=false` glyphs: an untested candidate for the label residuals.
- **lyon `flatten_quad` splits** some quadratics before flattening (stroke.rs `flatten_quad`). It
  made no difference on the glow witness, but it is unverified on sharp curves.
- `bevel`'s y=305 full-width row and `displacement_map`'s edge bands belong to the filter layer
  (sibling `w1-offstage-filter`), not to geometry.

## LOCAL ORACLE REQUESTS

None. The float geometry model reproduced Ruffle's golden stroke mask exactly, and every verdict
above was graded against goldens on CI-identical renders.
