# s26 wave 1: `w1-pixel-layer-colour` (layer groups N1/N3, AVM1 ColorMatrix, draw() of filtered sources, colour on placed Drawing-API content)

**NEW FILES** (all under `SWFRecompDocs/plans/session26-fanout-reports/`):
- this report
- `w1-pixel-layer-colour-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`; 7 runtime files, +211/−7, no recompiler change)
- `w1-pixel-layer-colour-fixtures/`
  - `create_fixtures.py` + `mkprobes.py` (generators; no compiler needed)
  - 3 proposed `regression/` fixture dirs (`test.swf`, `test.toml`, `output.txt`, analytic `output.expected.png`):
    `layer_group_filtered_child`, `avm2_layer_group_filtered_child` and `avm1_placed_drawing_color`
  - `probes/`: 4 probe SWFs with before/after PNGs

Box: cloud, Dawn on lavapipe, `SETUP_STATUS` all OK. Code base `origin/master` `ec07cc9e` (docs-only since the s26
baseline `697669e5f` code). Tests: `download_tests.sh visual avm1 avm2 from_shumway from_gnash fonts text` at session
start. Upstream master was `3e98d9ba6` (my blobless Ruffle clone, taken minutes later).

**Fidelity:** I compared 9 rows that are in both my BEFORE capture and `origin/ruffle-image-results`. All 9 are
md5-identical to CI's actual PNG, among them `cache_as_bitmap/avm1_color` and `bitmapdata_applyfilter_destpoint_edges`.
So local absolute numbers on those rows are CI-grade.

## Verdicts and priced flips

| # | Item | Verdict | Graded flips | Evidence |
|---|---|---|---|---|
| 1 | **N1**: a filtered object inside a layered offscreen | **GO (real bug, reproduced on AVM1 AND AVM2; prototype fixes both)** | **0 corpus** (no graded row has it; scan below) | new fixtures `layer_group_filtered_child` and `avm2_…`: FAIL 7200 → **PASS 0 / max 0** |
| 2 | Colour of Drawing-API content in PLACED/attached clips (w2-dynclip leads 1+2) | **GO (real bug; prototype)** | 0 corpus | fixture `avm1_placed_drawing_color`: FAIL 48000 → **PASS 0 / max 0** |
| 2b | Dynamic-under-placed **matrix** inheritance | **REFUTED as open**: already landed (s25 `actionGetPlacedAncestorWorldMatrix` in `apply_dynamic_mc_transforms`) | — | probe case E: the child is drawn at the placed parent's 2× scale and position on clean master |
| 2c | Dynamic-under-placed **colour** | **GO (prototype)** | 0 | fixture case D: red → blue |
| 3 | AVM1/timeline off-diagonal ColorMatrix "needs `renderer_run_color_matrix`" | **Premise REFUTED for RGB.** The recompile-time fold is a full 4×5 affine (`swf.cpp PlaceCmCompose`), so off-diagonal RGB already renders exactly (probe: R↔B swap = pure blue). **One real XS bug found and fixed:** a CM whose alpha row reads colour (`a→a = 0`) was culled as invisible | 0 | fixture case G: invisible → (255,127,127) |
| 3b | CM residuals that need the GPU pass: alpha bias filling the filter bounds; clamping between chained CMs / cx; edges of an alpha-from-colour matrix | **HOLD (M)**, no corpus row | 0 | probe `cm_offdiag`: gap stays white (Flash/Ruffle: blue at a = 128); grey ×2 then ×0.5 renders 200 (Flash/Ruffle: 127) |
| 4 | **N3**: group cxform applied to the LAYER composite | **NO-GO for an exporter golden: Ruffle does NOT do it.** Ruffle pushes the object's cxform onto the transform stack before capturing the blend's sub-commands (`core/src/display_object.rs` `render_base` ~978-987), so its LAYER alpha is per-child, the same as ours. Flash's documented LAYER = transparency group. | 0 | probe `n3_layer_alpha` == `n3_normal_alpha` byte-for-byte, as Ruffle would render it |
| 5 | `BitmapData.draw()` of a source with blur/glow/drop-shadow | **NO-GO in the cloud: the oracle is invalid.** Ruffle's `draw` renders with `use_bitmap_cache: false` (`core/src/bitmap/operations.rs` ~1480), so it NEVER applies the source's filters. Flash does: the `avm2/bitmapdata_draw_filters` golden shows the source's own CM in the drawn bitmap, and its `known_failure` is exactly this | 0 | — |
| 6 | Named corpus rows | **None is in this family** (by mechanism, below) | 0 | — |

**Prototype sweep:**
- I captured 178 tests / 237 PNGs: the full standing `render_canary_tests.txt` plus 51 exposure rows, listed in §Sweep.
- **237/237 md5-IDENTICAL; 0 trace or image status changes.**
- The 3 new fixtures go FAIL → PASS at max diff 0 against analytic goldens.

**Priced yield:** +0 graded flips (expected for this family). +3 regression rows, all game-visible.

## 1. N1: a filtered object inside a layered offscreen (GO)

**Mechanism (confirmed by reading and by measurement).** Inside a blend group that `renderer_blend_mode_is_layered` admits
(LAYER, or ADD/MULTIPLY/… while `offscreen_depth == 0`), the group renders into `filter_tex_a`. A filtered child reaches
`tag.c::render_filtered_core` because the nested gate checks only `g_filter_capture_depth`, which a blend layer does not raise.

`render_filtered_core` then does three things:
1. `begin_offscreen_pass` clears `filter_tex_a`, so it **erases everything the group drew so far**.
2. `render_webgpu_resume_pass` resumes the **main surface**, so the filter composite and every later group child land
   outside the group.
3. For complex blends, the blur ping-pong overwrites `filter_tex_b`, which holds the group's backdrop
   (`render_webgpu_capture_backdrop`). Before the fix, the MULTIPLY probe showed a sharp blue box with a black border.

`avm2_display.c::avm2_render_filtered` has the identical hazard: `g_avm2_filter_active == 0` inside a blend wrapper.

**Prototype (`render_webgpu.c`, self-localized file statics):**
- **`render_webgpu_begin_nested_filter`**
  - Refuses unless `offscreen_depth == 1 + child_layer_open` and `filter_pad == 0`, so the root and unnested paths are unchanged.
  - Ends the group pass.
  - Parks the group's colour/MSAA/stencil set in the next s25 child-layer slot (`child_layer_swap`). It parks
    `filter_tex_b` in a lazily built twin (`nested_b_swap`) and reserves the slot (`child_layer_open++`).
- **While parked**, `render_webgpu_resume_pass` resumes the **parked group** (colour + stencil `Load`) instead of the main surface.
  - The rest of the filter pipeline is untouched: capture, blur/CM ping-pong and `composite_filtered`/`compose_filter`.
  - Those passes create their bind groups per call from `ctx->filter_view_a`, so they composite the fresh filter result into the group.
- **`render_webgpu_end_nested_filter`** swaps both sets back and resumes the group.
- Macros in both `renderer.h` arms, plus `render_stub.c` stubs.
- **Callers.** The `tag.c` call is inside `render_filtered_core`, after the chain build:
  - begin before `renderer_suspend_pass`;
  - end before each of the 3 `g_filter_capture_depth--` returns.

  The AVM2 call is inside `avm2_render_filtered`, same pattern (2 returns after the suspend).
  No other function is touched.

**Fixtures:**
- `layer_group_filtered_child` (AVM1, static).
  - Left group: LAYER. Right group: MULTIPLY.
  - Each group draws red rect, then blue rect with DropShadow (blur 0, distance 4, angle 0), then green rect.
  - The stage is white, so both blends reduce to normal-over. The golden is analytic: every edge is on a whole pixel.
- `avm2_layer_group_filtered_child`: the same SWF with FileAttributes.AS3 and the s25 minimal DoABC, so it renders
  through `avm2_display.c`. `RecompiledABC/` is produced, which confirms the path.

| test (graphics) | clean `origin/master` | prototype |
|---|---|---|
| fixture `layer_group_filtered_child` | **FAIL 7200 outliers, max 255** (red rects + shadows missing, both groups) | **PASS 0 / max 0** |
| fixture `avm2_layer_group_filtered_child` | **FAIL 7200, max 255** | **PASS 0 / max 0** |
| probe `n1_layer_blur` (BlurFilter 4×4 child) | `473773…` (red rect lost) | `65557c…` = **byte-identical to the normal-blend control** |
| probe `n1_multiply_blur` | `09ef02…` (red lost, blur lost, black rim: backdrop clobber) | `65557c…` = **control** |

**Corpus exposure:**
- I scanned every image-compared SWF in visual, avm1, avm2, from_shumway, from_gnash, fonts, text and regression.
- I flagged a row when it has a PlaceObject3 blend or `blendMode` AND a PlaceObject3 filter or a filter class.
- That gives 25 rows. They are in the sweep (canary ∪ extras), apart from 2 slow Stage3D/away3d rows.
- None moved, so no graded row nests a filter inside a layered group.

**Limits (completion mechanism):**
- The nest refuses inside a **padded** filter capture (`filter_pad != 0`) and at > 4 levels, falling back to the old behaviour.
  Same limit and completion mechanism as s25 w2-layer-groups limit 2: give the padded set its own child sets.
- `g_nested_b_tex` is not released in `render_webgpu_free` (prototype). Wave 2 should free it there, or move it into the
  struct's trailing fields.

## 2. Colour of Drawing-API content in placed/attached clips, and dynamic-under-placed colour (GO)

**Mechanism.**
- `action.c::fillDrawingInfos` sets `info->cxform_id = mc->dynamic_cxform_slot`. That is 0 for any clip with a display
  entry, so script drawings in a placed clip ignore its PlaceObject CXFORM, `Color.setRGB/setTransform` and the
  ancestors' tint/alpha.
- Only the clip's own `_alpha` reached them, through the alpha fold.
- Separately, `tag.c::dyn_mc_world_cxform` stops at the first placed ancestor (`dyn_mc_dynamic_parent`).

**Prototype:**
- **`action.c`:**
  - New `actionRenderMCDrawingsInlineEntryCx(mc, cb, ud, entry_cx_slot)`, a wrapper that sets the file-static
    `g_fill_entry_cx_slot`.
  - `fillDrawingInfos` uses that slot when `mc->display_obj != NULL` (and the clip has no dynamic slot). It then skips
    the `_alpha` fold, because `mcSyncAlphaToDisplayObj` already put `_alpha` into the entry's `cx_aa`, so the fold
    would double it.
- **`tag.c`:**
  - The 2 inline Drawing-API call sites in `render_single_object` / `render_display_list` pass `obj->cxform_id`. That
    is the entry's composed world slot after `compose_children`, or the root runtime slot.
  - The 2 attached-clip passes (root capture pass ~8686 and the attached child renderer ~8916) pass `att_cx_slot`.
- **`tag.c`, colour inheritance:**
  - New `placed_anchor_world_cxform`, called at the end of `dyn_mc_world_cxform`.
  - It walks up from the top of the dynamic chain to the placed anchor. It composes each placed ancestor's own cx: the
    `cx_overridden` override, else the baked slot.
  - It runs from `apply_dynamic_mc_transforms`, before `compose_children` rewrites slots, so `cxform_id` is still the
    entry's own slot. It reads `app_context` through a static set at the top of `apply_dynamic_mc_transforms`.

**Fixture `avm1_placed_drawing_color`** (SWF 8, 400×180; each case draws a red 80×60 rect with the AVM1 Drawing API;
analytic golden, tolerance 1):

| case | setup | expected (Flash/Ruffle semantics) | origin/master | prototype |
|---|---|---|---|---|
| A | placed with CXFORM (0,0,0,1 / +0,0,255,0) | blue | red | blue |
| B | placed, `new Color(pb).setRGB(0x00FF00)` | green | red | green |
| C | placed, `_alpha = 50` (control) | (255,127,127) | ✔ | ✔ (no double alpha) |
| D | A's CXFORM; drawing in a `createEmptyMovieClip` child | blue | red | blue |
| F | placed with CXFORM alpha 128/256 | (255,127,127) | **opaque red** | ✔ |
| G | timeline rect, PlaceObject3 CM with alpha row (0.5,0,0,0,0) | (255,127,127) | **invisible** | ✔ (§3) |

Before: FAIL 48000 outliers, max 255. After: **PASS 0 / max 0**. No-graphics leg of the same fixture: trace PASS,
because `action.c` is shared and the change compiles there.

**Corpus exposure:** 4 image rows combine the AVM1 Drawing API with a colour API or CXFORM:
- `visual/filters/empty_child_filter_bounds`
- `avm1/netstream_play_flv_screen`
- `regression/avm1_dynclip_color_transform`
- `regression/avm1_runtime_filters`

They are in the sweep and all md5-identical.

**Open (completion mechanism):**
- `_root`'s own `Color` (`g_root_cx_*`) is still not folded into dynamic clips under `_root`. Seed
  `placed_anchor_world_cxform` with the root cx.
- The non-inline fallback `actionIterateDrawings` route (a placed clip not drawn inline) still uses slot 0. Use
  `dobj->cxform_id` there; no corpus or fixture case reaches it.

## 3. ColorMatrix on AVM1/timeline objects

- **Premise refuted.** The w2-cm-copyfrom lead ("off-diagonal terms a cxform cannot express") is wrong about our cxform.
  - `apply_cxform` is a full `mat4 * colour + add` on straight colour (`render_webgpu.c` ~271).
  - `swf.cpp::PlaceCmCompose::emit` writes the whole composed 4×5.
  - For RGB rows this is exact through AA and overlap, because an affine map on straight colour commutes with
    normal-over when the alpha row is identity.
  - Probe case 1: an R↔B swap renders pure blue (0,0,255).
- **Real bug (XS, fixed).** `tag.c::cxform_forces_invisible` tested only `a→a` (`cx[15]`) and the alpha add, so a
  folded CM with `A' = 0.5·R` was culled.
  - The fix tests the whole output-alpha row `cx[3],cx[7],cx[11],cx[15]` plus `cx[19]`. That is exact: alpha ≤ 0 for
    every input iff all are ≤ 0.
  - Used by `render_single_object` and the nested walk.
- **HOLD (M, no corpus row): cases only a real filter pass reproduces.** Measured on probe `cm_offdiag`:
  - **(a)** Alpha bias fills the filter bounds. Two bars with a gap and a CM with blue +255, alpha +128: Flash/Ruffle
    paint the gap blue at a = 128; we leave it white.
  - **(b)** Per-pass clamp. Grey 200 with CM ×2 then CM ×0.5: Flash/Ruffle give 127 (clamp at 255 first); the fold gives 200.
  - **(c)** Alpha-from-colour on AA edges. A half-covered edge pixel unpremultiplies to full red, so Flash keeps
    A' = 0.5 there. We give 0.25 (measured (255,191,191) on the x.5 edge).
  - **Completion:**
    - In the recompiler, keep the fold only when it is provably exact: one CM, alpha bias ≤ 0, and RGB gains that cannot leave [0,1] before a placement cx.
    - Otherwise emit the CM as a type-6 filter-list member.
    - Give `render_filtered_core` a type-6 chain arm that calls the existing `renderer_run_color_matrix` (the AVM2
      `avm2_render_filtered` loop already does this).
    - The Ruffle exporter is a valid oracle here: it runs the CM filter on the cached bitmap.
  - Game value is low (alpha-bias CMs and clamping chains are rare).

## 4. N3: group cxform on the LAYER composite (NO-GO; Flash oracle needed)

- Probe `n3_layer_alpha`: a LAYER sprite, alpha 50%, with two overlapping opaque rects. It is byte-identical to the
  no-LAYER control. The overlap shows red under blue, which is per-child alpha.
- That matches **Ruffle**:
  - In `render_base`, the object's `Transform` (including its colour transform) is pushed onto `transform_stack`
    BEFORE `std::mem::take(&mut context.commands)` captures the blend's sub-commands.
  - Every child is drawn pre-multiplied by the group alpha, and the blend composite then has no cxform.
  - A Ruffle-exporter golden would therefore bless today's output.
- **Flash** documents LAYER as "forces the creation of a transparency group … precomposed in a temporary buffer". The
  classic use is fading a container with overlapping children; Flash then shows the overlap as blue only.
- Per Standing rule 3 (Flash over Ruffle), the fix must be graded against a **Flash capture**, not the exporter.
- **Completion mechanism (M):**
  - Only the **alpha row** needs moving. RGB affine commutes with normal-over (§3).
  - `compose_children`: for a `blend_mode == 2` entry, mint an alpha-stripped slot for its subtree and the entry itself.
    Stash `(cx[15], cx[19])`.
  - Apply them at the composite. There are 4 composite sites:
    - the root/nested `composite_blend(…, 2)`;
    - `end_child_layer(…, 2)`;
    - the filtered-LAYER `render_filtered_core` group path;
    - the AVM2 twin in `avm2_render_node`.
  - `composite_wgsl` params already carry a group-alpha `w`.
- **Oracle request:** Flash projector capture of `w1-pixel-layer-colour-fixtures/probes/n3_layer_alpha.swf`.

## 5. `BitmapData.draw()` of a filtered source (NO-GO)

- **Flash applies the source's own filters in `draw()`.** `avm2/bitmapdata_draw_filters`' Flash golden has the CM in
  the drawn bitmap, and our s25 CM arm passes it at max 0.
- **Ruffle never does.** `operations.rs::draw` builds its `RenderContext` with `use_bitmap_cache: false`, and
  `render_base` applies filters only under `context.use_bitmap_cache && this.is_bitmap_cached()`.
- So **any exporter golden for this item encodes the wrong behaviour.**
- **Completion (M-L):**
  - Extend `avm2_bitmap.c::bd_draw_cm_filtered` (the CPU layer pattern) to the other kinds, with CPU kernels.
  - Today only blur, CM and displacement have CPU kernels.
  - `bd_apply_filter` drops DropShadow/Bevel/Glow entirely: see §6, `destpoint_edges` cells 4/5/12 are empty.
  - The AVM1 twin is `action.c::bitmapDataDraw`.
- **Oracle:** a Flash capture of a draw-of-blurred/glowing-sprite fixture.
- There is no corpus row beyond the CM one already passing.

## 6. Named corpus rows: verified by mechanism (none moves here)

- **`visual/cache_as_bitmap/avm1_color` (1200):** **not colour.**
  - Our render is md5-identical to CI and to `output.ruffle.png` (0 px differ), and the row is `known_failure`.
  - All 600 differing px are a 1-px edge on the TOP row and LEFT column of the two rects. Flash has a half-coverage
    tint there, (128,145,255) / (255,128,128); we and Ruffle have white or full colour.
  - That is a cacheAsBitmap bounds/edge-snap rule. Owner: the cAB pixel-snap family, not this slot.
  - Candidate for RUFFLE_VS_FLASH bookkeeping (Ruffle shares the diff).
- **`visual/blend_modes/shader_as_mask` (2100):** `BlendMode.SHADER` (the PixelBender `(a+b)/2` blend). The top band is
  ff9900 where Flash/Ruffle draw 804f06, and the shader-mask band adds the rest. Owner: `w1-pixel-tail` (pixelbender).
- **`avm2/bitmapdata_applyfilter_destpoint_edges` (149442):** CPU `applyFilter`, not layers/colour. Per-cell (100 px cells):
  - The blur/glow cells equal Ruffle's counts exactly (Flash-only edge semantics).
  - DropShadow, Bevel, Convolution and DropShadow(4,45) produce **empty cells** (23-26 k ch each; Ruffle ≈ 2 k).
  - `bd_apply_filter` returns early for every kind except CM, blur, displacement and gradient-passthrough. The Convolution
    cell is also empty, although it should take the passthrough copy, so `avm2_filter_from_object` likely rejects it.
  - Fixing those four cells to Ruffle level is about −90 k channels, still far over `max_outliers = 35`, so **no flip**.
    The row is KF.
- **`from_shumway/acid/acid-mask` ×3:** an AA model of record (s25 refutation). Nothing here touches masks; md5 unchanged in the sweep.
- **`from_shumway/MaskTest-2`:** device-font row (s25 refutation). Untouched.

## Sweep

- `render_canary.py capture`, `--jobs 3 --timeout 5400`.
- BEFORE is clean `origin/master` (patch reversed with `git apply -R`); AFTER is the prototype. Runtime-only change, so
  no `--recompile`.
- List = the standing `render_canary_tests.txt` (127 tests) plus 51 extras:
  - every `visual/blend_modes/*` and `visual/filters/*` image row;
  - every `regression/*` image row not already in the canary;
  - the exposure-scan rows (N1 25, DRAWCX 4, DYNPLACED 1), minus `stage3d_raytrace` and `away3d`.
- Result:

```
RENDER CANARY  before=before  after=after   178 tests / 237 comparisons
  IDENTICAL   237   DIFFERS 0   APPEARED 0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)   IMAGE STATUS CHANGES: (none)
```

- **Regression suite near the change:** all members are in the list, md5-identical, including
  `layer_group_{overlap_alpha,overlap_erase,in_add_alpha}`, `avm2_layer_group_*`, `avm1_dynclip_color_transform`,
  `avm1_runtime_filters{,_cm_bitmap}`, `avm1_nested_po3_filters` and `avm1_parent_child_*`.
- **Mode parity:**
  - No `swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` arm is touched.
  - `action.c` is shared, and the no-graphics leg of `avm1_placed_drawing_color` passes its trace.
  - The tag.c/render code is graphics-only.
- **Browser build:** `render_webgpu.c` uses only APIs already used in the file. It was not built here (no emsdk).

## Wave-2 patch scope (ranked)

1. **N1 (S, ranked first: a silent content-loss bug).**
   - `render_webgpu.c`: begin/end nested filter, the resume branch and `nested_b_swap`. Free `g_nested_b_*` in `render_webgpu_free`.
   - `render_webgpu.h` / `renderer.h` / `render_stub.c` (2 prototypes, 2×2 macros, 2 stubs).
   - `tag.c`: `render_filtered_core` only. `avm2_display.c`: `avm2_render_filtered` only.
   - Fixtures: `layer_group_filtered_child` and `avm2_layer_group_filtered_child`. Add both to the canary at EOF.
2. **Placed Drawing-API colour + dynamic-under-placed colour (S).**
   - `action.c`: `fillDrawingInfos` and the new `actionRenderMCDrawingsInlineEntryCx`.
   - `tag.c`: `render_single_object`, `render_display_list` (inline calls), the two attached passes, `dyn_mc_world_cxform`
     and the new `placed_anchor_world_cxform`.
   - Fixture: `avm1_placed_drawing_color`.
   - **`n-pixel-pass` overlap:** `tag.c`/`action.c` functions named above; nothing in button/mouse code.
3. **CM alpha-row invisibility (XS):** `tag.c::cxform_forces_invisible`. Covered by case G of fixture 2.
4. HOLDs: §3 (b)/(c)/(a) GPU CM routing (M); §4 N3 (M, Flash oracle); §5 draw() filters (M-L, Flash oracle).

## EXPECTED-FLIP LEDGER (if wave 2 lands 1-3)

- **Trace axis:** no moves. 3 new regression rows, all pass (`avm1_placed_drawing_color` traces `done`).
- **Pixel axis (graded corpus):** **no moves** (237/237 identical across canary + exposure set).
- **Pixel axis (new regression rows):** all three PASS 0 / max 0 against analytic goldens (before: 7200 / 7200 / 48000).

## New unclaimed leads

1. **AVM2 `applyFilter` drops DropShadow / Bevel / Glow** (returns early), and **Convolution** produces an empty cell
   although the code says passthrough.
   - Witness: the `destpoint_edges` cells, about −90 k channels, no flip (KF).
   - The same CPU kernels are the prerequisite for item 5. M.
2. **`cache_as_bitmap/avm1_color`:** the top/left half-coverage edge Flash shows on a cached AVM1 clip. Ruffle shares our
   render. A cAB snap / bounds rule; S to diagnose with the `.fla`.
3. **`_root` Color into dynamic clips**, and the `actionIterateDrawings` fallback slot (§2 Open). XS each.
4. **Padded-capture nesting** for N1 and the s25 child layers (one shared mechanism). S-M.

## LOCAL ORACLE REQUESTS

1. **Ruffle exporter, 1 frame, renders** of these fixtures. Each golden is analytic; replace it with the exporter PNG if
   they disagree beyond tolerance 1.
   - `SWFRecompDocs/plans/session26-fanout-reports/w1-pixel-layer-colour-fixtures/layer_group_filtered_child/test.swf`
     (240×120). Expected = `output.expected.png`, md5 prefix `f9046e3e`.
   - `…/avm2_layer_group_filtered_child/test.swf`: same golden. Confirms Ruffle renders the script-free AS3 twin identically.
   - `…/avm1_placed_drawing_color/test.swf` (400×180, 1 frame; trace `done`). Expected = `output.expected.png`
     (`bf392ee3`). Check that Ruffle's 50% alpha lands on 127 or 128 (tolerance 1 covers either).
2. **Flash capture (not the exporter; Ruffle is known to differ):**
   - `…/probes/n3_layer_alpha.swf`, for N3. Expected Flash: the overlap of the two rects at (80,50) is (127,127,255)
     (blue only), not (127,63,191), which is ours and Ruffle's per-child model.
   - A draw-of-filtered-source fixture for item 5. Not built here; it needs an AS3 compiler.
3. (Optional) Ruffle exporter on `…/probes/cm_offdiag.swf` to confirm the §3 HOLD numbers:
   - the gap between the bars at (140,30) should be ≈(127,127,255);
   - the grey rect ≈(127,127,127);
   - the alpha-from-red edge pixels should be (255,127,127).
