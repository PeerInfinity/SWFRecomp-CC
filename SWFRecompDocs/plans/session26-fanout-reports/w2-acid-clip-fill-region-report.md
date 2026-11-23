# w2-acid-clip-fill-region: shape layer order, DefineText glyph twip rounding (session 26, wave 2, cloud)

**New files (this branch):**
- `SWFRecompDocs/plans/session26-fanout-reports/w2-acid-clip-fill-region-report.md` (this report)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-acid-clip-fill-region.patch` (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`, 3 hunks in 4 files; `git apply --check -R` clean on the branch head)

No new source files and no new fixtures. Both mechanisms are covered by corpus rows.

Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Corpus: `download_tests.sh` from upstream Ruffle master **`3e98d9ba6`**, which is also my
blobless Ruffle clone for source reads. Base: origin/master `91267237`.

**Fidelity proven (CI-grade).** My BEFORE renders are md5-identical to CI's actual PNGs on `origin/ruffle-image-results`:
`acid-clip` `8b9be2da…`, `3_joystick` `71d9d129…`, `acid-text-6` output `b8ffc699…` and frame5 `e51e282a…`, `away3d_advanced_shallow_water_demo`
`0f317a9c…`. So every verdict below is absolute, not only A/B.

---

## 1. Verdicts

### GO: 3 flips (4 image checks), 0 pass→fail, 0 trace moves

| test (check) | CI baseline | after (lavapipe, CI-grade) | hunk |
|---|---|---|---|
| `from_shumway/acid/acid-clip` (output: tol 150/0, tol 64/140, tol 0/7000) | **FAIL**: 0 / **409** / **7041** channels, max 144 | **PASS**: 0 / **120** / **6750**, max 144 | L (recompiler) |
| `from_shumway/3_joystick` (output: tol 128/0, tol 32/2500) | **FAIL**: **4** / 2452, max 187 | **PASS**: **0** / 2365, max **127** | L (recompiler) |
| `from_shumway/acid/acid-text-6` output (tol 0/0) | **FAIL** 198 channels (66 px), max 255 | **PASS 0, max 0** | G (runtime) |
| `from_shumway/acid/acid-text-6` frame5 (tol 0/0) | **FAIL** 12 channels (4 px), max 255 | **PASS 0, max 0** | G (runtime) |

**Headroom watch:** `3_joystick` passes at **max 127 against tol 128**, one level of headroom on the tol-128 check. That check is now 0 outliers,
and its remaining field is the s25 sub-pixel knob offset (HOLD below). Add it to the zero-headroom watch list. `acid-clip` has 20 channels of
headroom at tol 64 and 250 at tol 0. `acid-text-6` is exact (max 0).

The w1 pricing of acid-clip ("≤ 50 %: the ~74 px AA field may keep it over budget") is **refuted**: the AA field after the fix is 120 channels,
under the 140 budget, and the tol-0 check (7041 > 7000, a second failing check that w1 did not list) also clears.

### HOLD

| item | verdict | completion mechanism |
|---|---|---|
| `visual/filters/bevel` "Out" `O`, 2 px (passing at 6/6, zero headroom) | **HOLD: not found, and one hypothesis refuted** | Ruffle's EditText glyph chain is `place * layout_to_local * translate(lbox origin) * glyph(a=d=height/em, tx=x)`, and `Matrix * Matrix` rounds the composed translation (render/src/matrix.rs). For these unscaled fields (place a = d = 1, tx = 321) every factor is whole twips, so the rounding that explains acid-text-6 **cannot** move them: `layout_to_local` = `bounds.x_min + GUTTER` = 0, device advances are `round_to_pixel`, the stage is 1:1 (550×650 = 11000×13000 twips) and the viewport matrix is identity. Only the `O` *demands* the shift (w1: `O` dx ∈ [+0.025, +0.055] px). The other glyphs merely tolerate it, so a glyph-local cause (the `O`'s curve flattening or midpoint quantization in Ruffle's ttf-parser → `Twips(x as i32)` path) fits equally well as a field shift. Completion: rebuild w1's label model (§2.2 of the w1 report; it was not committed) and test the per-glyph hypotheses on `O` alone. Headroom only, no flip at stake. |
| `from_shumway/3_joystick` residual field | HOLD (unchanged s25 mechanism) | The tol-128 pixels are gone. The tol-32 field (2365 / 2500) is the sub-pixel knob offset; s25's LOCAL ORACLE REQUEST 2 (knob world matrix at tick 21) still pins it. |

---

## 2. Mechanisms and evidence

### 2.1 L: a layer's strokes were drawn over later layers' fills (`SWFRecomp/src/swf.cpp`, DefineShape emission)

**The w1 attribution is corrected.** The wrong disc is not in `char 6`. acid-clip's top strip is root depth 11 = sprite 10 = {shape 8 rect clip
(clip depth 5), **shape 9**}. Shape 9 is a DefineShape4 with **three StateNewStyles layers**, each a red-filled circle with a thick stroke:
layer 1 has a 923-twip blue-grey (102,102,153) stroke, layer 2 a 923-twip green stroke, and layer 3 a 560-twip green stroke. Circle 2 (layer 2)
overlaps circle 1's stroke ring. Ruffle's `ShapeConverter::flush_layer` (render/src/shape_utils.rs) emits, **per layer**, the fills in style-id order
and then that layer's strokes. Our emitter drew every layer's fills (sorted by `(fill_style_list, fill id)`) and **then every path's stroke**, so
layer 1's blue-grey ring was painted over layer 2's red fill. That is the "blue-grey disc over the red one".

Fix (one function body, no new symbols): the directed-edge fill groups (`FillGroup`) are hoisted out of the non-morph branch into
`layer_fill_groups`, and their emission becomes the lambda `emit_layer_fills(layer)`. The stroke loop calls it with `paths[i].line_style_list`
before each path, and once more with `UINT32_MAX` after the loop. Groups stay sorted by `(layer, fill id)`. `fill_style_list` and
`line_style_list` advance together on every StateNewStyles (`swf.cpp` ~9970/10014), so the line-style list index *is* the layer. Single-layer
shapes emit the same triangles in the same order (proved by the sweep below). Morph shapes never populate `layer_fill_groups`, so their path is
untouched. The `stroke_run_data` offsets (`current_tri + tris_size - tris.size()`) stay consistent because `tris_size` still counts every
emitted triangle in emission order.

Same mechanism, unpredicted: `3_joystick`'s two tol-128 pixels at (339,125)/(340,125), "the bottom of the knob highlight", were a stroke of an
earlier layer drawn over a later layer's fill. s25/w1 had filed them under the sub-pixel knob offset.

Not done (stated): Ruffle also orders strokes **by line-style id within a layer**; we keep path order within a layer. No row exercises the
difference (the sweep found nothing else moving). Lead 2 below.

### 2.2 G: static-text glyph translation is rounded to whole twips (`SWFModernRuntime/src/libswf/tag.c`, `render_webgpu.c`)

acid-text-6 is DefineText (`char 2`, 4 records × 6 glyphs, DefineFont3 "InputMono Bold", height 2000, EM 20480), placed at root depth 1 and
re-scaled every frame (frame 20: a = d = 0.23779296875, tx/ty = 9812/9501). The diffs are whole glyph-stem columns and rows that flip, i.e.
edges lying near pixel centres at quality LOW.

**Geometry model** (Python, exact f64 point-in-polygon at pixel centres over all 24 glyphs, quads flattened at 64 steps). The DefineFont3 shapes
and DefineText records were parsed from the SWF.
- Plain composition `place * glyph(a=d=2000/20480, tx=pen)`: **3 px vs our render, 67 px vs the golden** (frame 20).
- Ruffle's composition: `text.rs render_self` pushes `Matrix{a=d=scale, tx=pen_x, ty=pen_y}` per glyph onto the transform stack, and
  `Matrix * Matrix` gives `tx = round_to_i32(a*rhs.tx + c*rhs.ty) + self.tx` (f32, ties-even). That model gives **0 px vs the golden** on both
  `output` (frame 20) and `frame5` (= frame 1). Both checks are fully explained by this one quantization.

Fix: new `static inline tag_text_glyph_compose(out, parent, glyph)` at the top of `tag.c`: the plain mat4 product, then
`out.tx = rintf(parent.a*g.tx + parent.c*g.ty) + parent.tx` (and the same for ty), skipped for non-finite or out-of-range values. It is used at the
two DefineText compose sites, **`compose_children`** (the `CHAR_TYPE_TEXT` arm, nested static text) and **`compose_root_text_instance`**
(root). The shared-slot fallback `render_webgpu_compose_text_transforms` (`render_webgpu.c`) gets the same 7 lines inline. Approximation
(commented): the recompiler folds the DefineText matrix's own translation into the pen, so where Ruffle rounds twice (`place*text_matrix`, then
`*glyph`) we round once. That is exact when the text matrix translation is 0 (acid-text-6) or the parent scale is 1.

Sibling localization: `tag.c` functions touched are `compose_children` (one call in its text arm) and `compose_root_text_instance` (one call),
plus the new static helper. Not touched: `render_filtered_core` (`w2-cm-chain-cab-edge`), `render_attached_child` and the attached depth pass
(`w2-attached-holder-render`), `collect_attached_standalone` (`w2-loaded-shell-phase2`), and nothing in `action.c`, `ng_shared.c` or `swf.c`
(`n-pixel-pass`). The recompiler hunk is in the DefineShape fill/stroke emission only, not `PlaceCmCompose`. No `swf_core.c`, `tag_stubs.c`
or `NO_GRAPHICS` arm is touched.

---

## 3. Sweeps (exact, argued scope)

**L (recompiler).** I recompiled **every image row** with the old and new recompiler binaries: 420 test dirs across all suites incl.
`regression` (every test.toml with `image_comparisons`), plus the 8 child SWFs that image rows load. Then I diffed the generated
`RecompiledTags`/`RecompiledScripts` trees. Result: **415 SAME, 5 DIFF**, and all 8 child SWFs SAME. Only the 5 can move. I rendered all 5 on
both legs with `--recompile`:

| row | before md5 | after md5 | verdict |
|---|---|---|---|
| `from_shumway/acid/acid-clip` | `8b9be2da` | `905f2e50` | **fail → pass** |
| `from_shumway/3_joystick` | `71d9d129` | `da9e0aaa` | **fail → pass** |
| `avm2/away3d_advanced_shallow_water_demo` | `0f317a9c` | `0f317a9c` | IDENTICAL (fail, unchanged) |
| `from_shumway/acid/acid-morph` (canary) | `5cc0e5bd` | `5cc0e5bd` | IDENTICAL (pass 2517/2600) |
| `from_shumway/acid/acid-small` (canary, 2 cmp) | `63b683a3` / `e07fadba` | same | IDENTICAL (pass) |

**G (runtime, DefineText compose only).** A tag walk (incl. sprites, CWS/ZWS) over every image-row SWF finds DefineText/DefineText2 in **17 rows
(19 PNGs)**: 9 AVM1 and 8 with ABC. I rendered all 17 on both legs (runtime hunk reverted vs applied, same recompiler): **18 PNGs IDENTICAL,
1 test DIFFERS = `acid-text-6`** (both checks fail → pass). The IDENTICAL set includes the **zero-headroom rows `bevel_full`, `bevel_inner`,
`bevel_outer`, `glow_with_alpha_strength` (18/18 each)**, `static_text_offstage`, `acid-chars`, `acid-text-2/-3/-5`, `acid-clip-3` (2 cmp), the
four `cache_as_bitmap/oversize/*` and `regression/avm1_parent_child_text`.

**Render canary.** All 132 members of `render_canary_tests.txt` are image rows, so the two sweeps above cover the canary exactly. The
members either sweep can move are `acid-small` and `acid-morph` (generated code differs) and `bevel_inner` (contains DefineText). All three are
md5-identical. The other 129 members have byte-identical generated code and no DefineText, so they cannot move. I did not run the full
132-member `render_canary.py` capture: it could only re-confirm identities. **Appended at EOF (tier 1):** `from_shumway/acid/acid-clip`,
`from_shumway/3_joystick`, `from_shumway/acid/acid-text-6`. The standing set could not see either change class.

**Regression suite** (`--tests-dir=ruffle-tests/tests/swfs/regression`, graphics, `--recompile`): `avm1_parent_child_render`,
`avm1_parent_child_morph`, `avm1_placed_drawing_color` PASS 0/0 max 0. `avm1_parent_child_text` PASS md5-identical both legs.

**Trace axis / mode parity.** Every row rendered above keeps its trace status (all trace PASS both legs). No-graphics `--recompile` runs:
`acid-clip` PASS, `3_joystick` PASS, `acid-text-6` PASS (also a compile check that the new `tag.c` helper builds without graphics).

---

## 4. EXPECTED-FLIP LEDGER (coordinator: check CI against this)

| test | axis | expected move |
|---|---|---|
| `from_shumway/acid/acid-clip` | pixel `output` | fail → **pass** (409 → 120 @64; 7041 → 6750 @0) |
| `from_shumway/3_joystick` | pixel `output` | fail → **pass** (4 → 0 @128, max 187 → 127; 2452 → 2365 @32) |
| `from_shumway/acid/acid-text-6` | pixel `output` | fail → **pass** (198 → 0) |
| `from_shumway/acid/acid-text-6` | pixel `frame5` | fail → **pass** (12 → 0) |
| any | trace | **no moves** |

Anything else moving on CI (pixel or trace) is outside this patch's measured footprint. Pixel-row count: **+3 tests / +4 comparisons**.

---

## 5. Refutations

1. **"acid-clip's wrong disc is fill-style region order inside one DefineShape `char 6`" (w1):** `char 6` is a gradient circle in a different
   sprite. The disc is shape 9's layer-1 **stroke** drawn over layer-2 fill. It is cross-layer fill/stroke order, not region semantics.
2. **"acid-clip flip ≤ 50 %" (w1 pricing):** it flips with 20 channels of headroom. w1 also missed the second failing check (tol 0, 7041 > 7000),
   which clears too.
3. **"3_joystick's tol-128 pixels are the sub-pixel knob offset" (s25/w1 HOLD):** they were this layer-order bug. Only the tol-32 field is left
   for the knob hypothesis.
4. **"acid-text-6 needs the lyon f32 flattening + ttf-parser semantics model" (brief):** the glyphs are DefineFont3 straight stems. The whole
   residual is Ruffle's whole-twip glyph translation; an exact f64 rasterizer with that rounding reproduces the golden with 0 mismatches.
5. **"bevel `Out` is a +1-twip field shift from the same matrix rounding":** refuted for this row. Every factor of Ruffle's EditText chain is
   whole twips here (§1 HOLD).

## 6. New unclaimed leads

1. **EditText glyph compose rounding:** Ruffle's EditText glyphs go through the same rounding `Matrix * Matrix`. Our EditText glyph path
   (action.c text-field glyph iteration) does not round. It is invisible at scale 1 and visible for scaled, zoomed or tweened device- and
   embedded-font fields. No image row was tested; the S-sized twin is in action.c (`n-pixel-pass` territory, so coordinate first).
2. **Stroke order within a layer by line-style id** (Ruffle `flush_layer`); we keep path order. No row moves, so it is game-visible only. XS in
   the same `swf.cpp` loop.
3. **DefineText matrix fidelity in the recompiler:** `swf.cpp` DefineText emission overwrites the text matrix's scale with `height/em` and folds
   its translation into the pen. A DefineText with a scaled or rotated text matrix renders without it. Ruffle pushes `text_transform` then
   per-glyph. M, recompiler-only; it would also make the double rounding exact.
4. **AVM2 static-text twin** (`avm2_statictext_collect_glyphs` / the AVM2 glyph raster): it places glyphs from `x_twips` + `scale` without the
   whole-twip compose. No AVM2 image row moved here (the 8 ABC DefineText rows are md5-identical, so they render through paths this hunk does not
   reach). Measure on an AVM2 row with a scaled StaticText before porting.
5. **bevel `O`:** per-glyph hypotheses (§1 HOLD) with a rebuilt label model.

## LOCAL ORACLE REQUESTS

none (both mechanisms reproduce their goldens exactly in a model; the s25 3_joystick knob request stands as filed).
