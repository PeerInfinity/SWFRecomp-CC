# s27 wave 2: `w2-layer-alpha-group` (blendMode LAYER alpha as a transparency group)

**NEW FILES**
- `SWFRecompDocs/plans/session27-fanout-reports/w2-layer-alpha-group-report.md` (this report)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-layer-alpha-group.patch` (the deliverable; `git apply --check -R` verified on the branch)
- `ruffle-tests/tests/swfs/regression/layer_group_alpha_transparency/` (`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`, `output.expected.png` = the **Flash** PNG)
- `ruffle-tests/tests/swfs/regression/avm2_layer_group_alpha_transparency/` (the same five files; AVM2 twin, same Flash golden)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-layer-alpha-group-fixtures/`
  - `mkprobes_groups.py` and `probes/n3g_*.swf`: 6 Flash-oracle probes for the other grouping triggers (see LOCAL ORACLE REQUESTS)
  - `probes/*.{before,after}.png`: our renders of those probes and of `n3_layer_alpha`, before and after the patch

**Box:** cloud, Dawn on lavapipe, `SETUP_STATUS` all OK. Code base `origin/master` `53540ff0` (wave-2 briefs; it includes
`d70f2c0aa`). Baseline results: wave-0 had published (`da51f878`, "Update Ruffle test results (mode=graphics)").
Tests: `download_tests.sh visual avm1 avm2 from_shumway from_gnash timeline swf mixed_avm` at session start, against upstream
Ruffle master `1e604fa87`.

**Fidelity:** 10 rows are in both my BEFORE capture and `origin/ruffle-image-results`. All 10 are md5-IDENTICAL to CI's
actual PNG, so local absolute verdicts are CI-grade. The rows: `away3d_advanced_shallow_water_demo`, `bitmapdata_opaque`,
`graphics_draw_path`, `graphics_gradients`, `graphics_simple_shapes`, `acid-textfield`, `bitmapbuttons`, `stylesheet`,
`visual/definefont4` and `strokes/scale`.

## Verdict

| Item | Verdict | Graded corpus flips | Evidence |
|---|---|---|---|
| LAYER alpha as a transparency group, AVM1 + AVM2 | **GO, landed in the patch** | **0** (no corpus row has LAYER + alpha; scan below) | 2 new fixtures: FAIL 3200 outliers / max 65 → **PASS 0 outliers / max 1** against the Flash PNG |
| Ancestor alpha above a LAYER (normal 50% parent → LAYER child) | **Grouped by the patch** (the whole concatenated alpha moves to the composite) | 0 | probe `n3g_layer_inner`: overlap (127,63,191) → (127,127,255). **Flash confirmation requested** |
| Filters / cacheAsBitmap / non-LAYER blends (MULTIPLY) with alpha | **HOLD: no oracle, left per-child (unchanged)** | 0 | probes `n3g_filter_cm`, `n3g_cab`, `n3g_multiply` are byte-identical before/after. Flash captures are requested |
| LAYER with an alpha **offset** (`alphaOffset`, `cx_aa`) | **HOLD (unchanged, per-child)** | 0 | probe `n3g_layer_aadd` is identical before/after |
| s26 fixtures `layer_group_filtered_child`, `avm2_layer_group_filtered_child`, `avm2_layer_group_alpha` | **Stay green, md5-identical** | — | canary + regression run below |

**Priced yield:** +0 graded corpus flips, which is expected: no corpus row combines LAYER with alpha. There are +2 new
regression rows, both PASS against a real Flash oracle, and no Ruffle-golden row moves, so nothing needs an RvF disposition.

## Mechanism and patch scope

**Flash's model.** The oracle is Flash Player 32: `flash-oracle-captures/n3_layer_alpha/flash.{high,low}.png`, and the two
captures are identical. A LAYER clip's children composite **opaquely** into the group, and the clip's alpha then applies
**once** to the group. At the overlap (80,50) Flash shows (128,128,255), the blue child alone at 50%.

**Ours before the patch, and Ruffle's model.** The alpha was applied per child: `compose_children` bakes every
ancestor's cxform into each leaf's GPU slot. Ruffle does the same: `render_base` pushes the cxform before it captures the
blend's commands. Both give (127,63,191) at the overlap, red showing under blue.

**The fix.** The patch moves only the **alpha multiplier** to the composite. An affine RGB map commutes with normal-over,
so the RGB rows stay per child.

**Every function touched** (all edits are self-localized: file statics plus one new renderer entry point):

**`render_webgpu.c`** (group composite only):
- New `render_webgpu_set_group_alpha` plus statics `g_group_alpha_pending`, `take_group_alpha` and `group_alpha_params`.
  - The pending alpha is consumed (reset to 1) by the next composite call, whatever its mode.
  - When the alpha is below 1, the params come from their own `filter_uniform_ring` slot. A queue write to the shared
    `blend_params_buf` would land on every composite in the frame.
- `render_webgpu_composite_blend`: for mode 2 with group alpha, binds the ring slot. `composite_wgsl`'s existing
  `params.w` scales the premultiplied group (rgb and a).
- `render_webgpu_end_child_layer`:
  - For k == 2 with group alpha, it composites through `blend_layer_pipeline[2]`.
  - That pipeline has the same premultiplied-over blend, `composite_pipeline_layout` and stencil-Equal state as
    `child_layer_over`, and it reads `params.w`.
  - Every other case keeps the old pipeline, so it is byte-identical.

**Headers and stub:**
- `renderer.h`: a `renderer_set_group_alpha` macro in both arms (no-op in the non-WebGPU arm).
- `render_webgpu.h`: the prototype.
- `render_stub.c`: a stub.

**`tag.c` (AVM1 / timeline):**
- New statics `g_lga[]`, `lga_reset`, `lga_for_entry`, `lga_split_entry`, `lga_enter` and `lga_leave`, placed just above
  `compose_children`.
- **`lga_split_entry`.** It fires for a LAYER entry whose concatenated cxform alpha row is a pure multiplier
  m ∈ (0,1): `cx[3] = cx[7] = cx[11] = cx[19] = 0`.
  - It mints an alpha-stripped slot (no slot when the stripped cxform is identity) and hands it to the subtree.
  - It re-points the entry's own `cxform_id` at that slot, which covers the clip's own Drawing-API content.
    `cxform_overrides_restore` restores it.
  - It records m in the side table.
- **Guards**, so a split only happens where a group is certain to open:
  - not on a filtered LAYER entry (its filter offscreen is a separate composite);
  - nowhere under a filtered ancestor (a padded filter capture refuses child layers);
  - at most 2 blend-mode ancestors deep (`CHILD_LAYER_MAX` = 4).
- `cxform_overrides_reset` also calls `lga_reset`, so the side table rewinds with the dynamic cxform pool.
- `compose_children`: the SPRITE arm splits and recurses; the SPRITE and BUTTON arms wrap their recursion in
  `lga_enter`/`lga_leave`.
- `tagRerenderFrame` and `tagShowFrame` root compose loops: the root SPRITE arm splits, and the SPRITE and BUTTON arms
  are wrapped.
- The two attached-clip compose sites (the `offscreen_attached_pass_member` path and `render_attached_child`) are wrapped
  in `lga_enter(d)`/`lga_leave(d)`.
- **Render arms**: `renderer_set_group_alpha(context, lga_for_entry(obj))` runs just before the mode-2 composite at 4
  sites:
  - the `render_display_list` nested arms (`composite_blend` and `end_child_layer(2)`);
  - the `tagRerenderFrame` root arm;
  - the `tagShowFrame` root arm.

**`avm2_display.c` (AVM2):**
- New statics `g_avm2_lga_strip`, `avm2_lga_split` and `avm2_render_layer_group`.
- In `avm2_render_node`'s blend arm, both group-opening branches (root `blend_layered` and the nested child layer)
  re-enter LAYER nodes through `avm2_render_layer_group`:
  - it strips `parent_cx.mult[3]` and passes `parent_alpha = 1`;
  - the node's own `alpha_fixed8` is taken as 1 on re-entry;
  - it calls `renderer_set_group_alpha` before the composite.
- It requires `parent_cx->add[3] == 0` and `cx_aa == 0`.
- The per-draw fallback branch is unchanged.

**Not touched:** `swf_core.c`, `tag_stubs.c`, `#ifdef NO_GRAPHICS` arms, the recompiler, `verify_output.py`.
There are no new `.c`/`.h` files.

**Known limit, accepted.** At render time a LAYER can still fail to open a group after compose already split it. That
needs a nested arm where `is_layered` refuses and `begin_child_layer` refuses for a reason the compose guards do not
predict, for example inside an AVM1 alpha-mask capture. In that case the clip draws at alpha 1. The compose guards
exclude every case I could construct; nothing in the corpus reaches it (canary below).

## Per-test before/after (clean `origin/master` vs patch, same box, `--mode=graphics`)

| Test | Before | After |
|---|---|---|
| `regression/layer_group_alpha_transparency` (NEW) | FAIL 3200 outliers, max 65 (overlap (127,63,191)) | **PASS 0 outliers, max 1** (overlap (127,127,255)) |
| `regression/avm2_layer_group_alpha_transparency` (NEW) | FAIL 3200 outliers, max 65 | **PASS 0 outliers, max 1** |
| `regression/layer_group_filtered_child` (s26) | PASS max 0 | PASS max 0, md5-identical |
| `regression/avm2_layer_group_filtered_child` (s26) | PASS max 0 | PASS max 0, md5-identical |
| `regression/avm2_layer_group_alpha` (s26) | PASS max 2 | PASS max 2, md5-identical |
| `regression/{layer_group_overlap_alpha, layer_group_overlap_erase, layer_group_in_add_alpha, avm2_layer_group_overlap_alpha, avm2_layer_group_erase, bitmap_pool_layer_cap}` | PASS | PASS, md5-identical |

**Tolerance = 1, quality high: measured and justified.**
- After the fix, every non-white pixel differs from the Flash PNG by exactly 1 in one or two channels, and white pixels
  match exactly. Examples: single red (255,127,127) vs Flash (255,128,128); overlap (127,127,255) vs (128,128,255).
- The 1 is Flash rounding 255 × 0.5 = 127.5 up while our unorm8 write gives 127. The single-rect pixels already showed it
  before the fix, so it is not an AA band.
- All edges are whole pixels, so there is no AA band either. That is why `flash.low.png` == `flash.high.png`.
- At tolerance 1 there are 0 outliers. The pre-fix overlap error is 64-65, so a tolerance of 1 cannot mask a regression of
  the group model.

**No-graphics parity:** both new fixtures, `layer_group_overlap_alpha` and `avm1/movieclip_blend_mode_property` (also run
in graphics mode) PASS. Only shared `tag.c` code changed.

## Render-canary sweep

- **The set:** the standing `render_canary_tests.txt`, with 2 covering members appended at EOF (the two new fixtures).
  On top of that come:
  - every `visual/blend_modes/*` row (13 not already in the set);
  - `visual/definefont4` and `avm2/away3d_advanced_shallow_water_demo`, the script-side blendMode/"layer" hits of the scan;
  - the remaining layer-group regression fixtures.
- **Size:** 173 tests and 232 PNGs. 5 font/text rows exit non-zero in both legs: `fonts/` and `text/` were not
  downloaded, so they are missing, not regressions.
- **Result: 230/232 md5-IDENTICAL.** The only 2 that differ are the 2 new fixtures (image fail → pass).
- **Trace status changes:** none.

## Corpus pricing (static scan)

- **Scanner:** a PlaceObject3 walker over every downloaded `test.swf`. It handles FWS/CWS/ZWS, recurses into
  DefineSprite, reads blend = 2 and the alpha in the cxform, and also flags script strings containing both `blendMode` and
  `layer`.
- **Categories scanned:** visual, avm1, avm2, from_shumway, from_gnash, timeline, swf and mixed_avm, plus whatever
  from_avmplus, text, fonts, audio, import_assets and stage3d held locally.
- **PlaceObject3 LAYER entries:** only `visual/blend_modes/layer_alpha` and `layer_erase`. **Neither carries an alpha
  cxform**: mult 256, add 0. Both are in the canary and identical.
- **Script hits:**
  - `visual/blend_modes/masked_layer_cached_children`, `visual/definefont4`, `avm2/away3d_advanced_shallow_water_demo` and
    `avm2/stage3d_texture`: all four image rows are in the sweep and md5-identical.
  - `avm1/movieclip_blend_mode_property` and `from_gnash/actionscript.all/MovieClip-v5..v8`: trace-only blendMode
    property tests. The patch has no trace-side effect.
- **Priced losses:** none. No Ruffle-golden row moves away from Ruffle, so no RvF / `<!-- image-axis -->` disposition is
  needed.
- **Note for the docs.** Ruffle's LAYER-alpha model (per child) is wrong against Flash. Any future Ruffle-exporter golden
  for a LAYER + alpha + overlap scene is invalid, which is exactly s26 N3. The new fixtures carry the Flash golden instead.

## EXPECTED-FLIP LEDGER (coordinator checks CI against this)

- **Trace axis:**
  - No moves on any existing row.
  - 2 NEW rows: `regression/layer_group_alpha_transparency` and `regression/avm2_layer_group_alpha_transparency`, both
    PASS in graphics and no-graphics. Their `output.txt` is empty: no scripts.
- **Pixel axis, graded corpus:** **no moves.** 230/230 non-fixture comparisons are md5-identical.
- **Pixel axis, new regression rows:** both new rows **PASS** at 0 outliers and max diff 1 (tolerance 1) against the
  Flash PNG. Before the patch they would FAIL with 3200 outliers at max 65.
- **Standing canary:** the 2 new rows are appended at EOF.

## Refutations / premise checks

- **"The fix may be 'apply group alpha at composite instead of per child'": confirmed.** `composite_wgsl` already carried a
  group-alpha `params.w`, but the blend composites bound a permanently-zero buffer. A per-composite ring slot was the
  missing piece, which s26 §4 predicted.
- **s26 §4 named 4 composite sites. The real count is 5:** root `composite_blend` in each of `tagShowFrame` and
  `tagRerenderFrame`, the nested `composite_blend`, the nested `end_child_layer(2)`, and the AVM2 arm, which has 2
  branches of its own.
- **The filtered-LAYER path deliberately stays per child.** Its filter offscreen is its own composite, and whether Flash
  groups filters is itself an open oracle question (below).
- **The AVM1 *dynamic*-clip filter path already groups** (`FilteredSource.group_alpha` → `renderer_composite_filtered_alpha`,
  tag.c ~5006). So "filters group" is already our model there, but not on the timeline filter path. That inconsistency is
  a lead, below.

## New unclaimed leads

1. **Timeline filtered clip + alpha (AVM1 `render_filtered_core`, AVM2 `avm2_render_filtered`).**
   - Flash caches a filtered clip as a bitmap, and our own dynamic-clip filter path already applies `_alpha` once.
   - The timeline path bakes the alpha into each leaf, which gives per-child overlap.
   - **Completion:** the same split (`lga_split_entry` without the filter guard) plus `renderer_composite_filtered_alpha`
     at the filter composite. Price S-M once Flash confirms `n3g_filter_cm`.
2. **cacheAsBitmap + alpha** (`n3g_cab`): same question and the same mechanism.
   - There is no offscreen today (AVM1 cacheAsBitmap only snaps). Grouping would need a LAYER-style offscreen for a cached
     clip with alpha < 1.
3. **Non-LAYER blend + alpha** (`n3g_multiply`).
   - Our ADD/MULTIPLY/... root offscreen already isolates the subtree. If Flash groups, the fix is to set the group alpha
     before the `composite_blend` of a complex mode too.
   - That needs a complex-blend shader input, because `blend_shader_wgsl` has no params binding.
4. **LAYER with an alpha offset** (`n3g_layer_aadd`). Group-level `a' = a·m + add` needs an unpremultiply in the composite
   shader. That is S, once Flash confirms the model.

## LOCAL ORACLE REQUESTS

FLASH, image, `num_ticks = 1`, quality high. Use `--screen` for `n3g_multiply`, because `draw()` mis-renders non-LAYER
blend modes. The probes are in `SWFRecompDocs/plans/session27-fanout-reports/w2-layer-alpha-group-fixtures/probes/`.
Compare pixel (80,50), the overlap: (128,128,255) means grouped, about (127,63,191) means per child. Our after-patch values:

| Probe | Question | Ours after the patch at (80,50) |
|---|---|---|
| `n3g_normal.swf` | control (expected per child) | (127,63,191) |
| `n3g_layer_inner.swf` | does a 50% NORMAL parent's alpha group at a LAYER child? | (127,127,255) (patch assumes yes) |
| `n3g_filter_cm.swf` | identity ColorMatrixFilter + 50% | (127,63,191) |
| `n3g_cab.swf` | cacheAsBitmap + 50% | (127,63,191) |
| `n3g_multiply.swf` | MULTIPLY + 50% on white | (127,63,191) |
| `n3g_layer_aadd.swf` | LAYER, alpha mult 1, alpha offset -128 | (128,64,191) |

- If `n3g_layer_inner` comes back per child, the fix is to restrict `lga_split_entry` to the entry's OWN alpha.
  `compose_children` would then strip `own_cx`, not `eff_cx`, and the AVM2 arm would strip only `alpha_fixed8`. That is XS.
