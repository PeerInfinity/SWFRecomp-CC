# s27 wave 2: `w2-applyfilter-cm` (AVM1 ColorMatrix leftovers + AVM1 `applyFilter` beyond ColorMatrix)

**NEW FILES**
- `SWFRecompDocs/plans/session27-fanout-reports/w2-applyfilter-cm-report.md` (this report)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-applyfilter-cm.patch` (`git diff origin/master` over every source
  file, build script and new fixture below; `git apply --check -R` verified on the branch)
- `SWFModernRuntime/src/actionmodern/avm1_filter_kernels.c` (new TU: AVM1 applyFilter → AVM2 CPU kernels)
- `SWFModernRuntime/include/actionmodern/avm1_filter_kernels.h`
- `ruffle-tests/tests/swfs/regression/avm1_po3_cm_folded_clear/` (`create_test_swf.py` = generator of all three
  `avm1_po3_cm_*`, `test.swf`, `test.toml`, `output.txt`, `output.expected.png` = **Flash Player 32** capture)
- `ruffle-tests/tests/swfs/regression/avm1_po3_cm_live_under_cxform/` (`test.swf`, `test.toml`, `output.txt`,
  `output.expected.png` = **FP32**)
- `ruffle-tests/tests/swfs/regression/avm1_po3_cm_alpha_bias_edge/` (same layout, `output.expected.png` = **FP32**)
- `ruffle-tests/tests/swfs/regression/avm1_applyfilter_kernels/` (`create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`; trace-only, analytic expectations)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-applyfilter-cm-fixtures/` (`create_fixtures.py` + 7 ×
  `avm1_applyfilter_<kind>/{test.swf,test.toml,ours.txt,ours.png}`: FLASH-oracle fixtures, **no golden yet**)

**Box:** cloud, `SETUP_STATUS` all OK (Dawn on lavapipe). Base `origin/master` `53540ff0`. `download_tests.sh avm1 avm2
visual from_shumway from_gnash text fonts` (upstream Ruffle master at run time; both A/B trees downloaded within the
same hour, and every canary-listed `test.swf` / golden is md5-identical between the two trees, see §4).

## Verdicts and priced flips

| # | Item | Verdict | Graded moves |
|---|---|---|---|
| 1 | `avm1_po3_cm_folded_clear` (folded CM survives `filters = []`) | **GO, landed with the FP32 golden.** FAIL (4800 outliers, max 255) → **PASS max 0** | +1 regression row (new fixture) |
| 2 | `avm1_po3_cm_live_under_cxform` (live CM under a placement cx) | **GO, landed with the FP32 golden.** FAIL (7200, max 37) → **PASS max 1 @1, 0 outliers** | +1 regression row |
| 3 | `avm1_po3_cm_alpha_bias_edge` (alpha-bias CM rim) | **GO, mechanism found and matched byte-exactly.** FAIL (392, max 48) → **PASS max 0** (whole image, not interior-only) | +1 regression row |
| 4 | AVM1 `BitmapData.applyFilter` for Blur / Glow / DropShadow / Bevel / Convolution / GradientGlow / GradientBevel | **GO (bridge landed), Flash goldens pending.** New analytic fixture `avm1_applyfilter_kernels` output_mismatch → PASS (no-graphics and graphics); 7 Flash-oracle image fixtures built, `ours` renders archived | +1 regression row; 0 corpus rows |
| 4a | Brief premise: "a wrapper in `avm2_bitmap.c`" (w1 §3 pricing) | **REFUTED as stated.** AVM1 builds never link `avm2_bitmap.c` (`verify_output.py` "AVM1 tests never compile src/avm2", `avm2_cpu_raster.c` excepted; same in `build_test.sh`, the wasm scripts, CMake), and the kernels are file-`static`. A wrapper there is unreachable from an AVM1 movie. Landed instead: a new TU that **re-compiles `avm2_bitmap.c`'s kernel block** under `AVM2_BITMAP_KERNELS_ONLY` (§2) | — |

**Priced yield: +0 corpus flips (none of the four is reachable from a corpus row; §4 scan), +4 new regression rows
(3 with Flash goldens), 0 status moves on the canary (§4).** Value: three Flash-confirmed AVM1 CM rules, and AVM1
games' `applyFilter` blur/glow/shadow/bevel/convolution now run the same Flash-model kernels as AVM2.

## 1. ColorMatrix leftovers (all three against Flash Player 32)

Goldens are the coordinator's FP32 captures (`w1-local-oracles/w1-applyfilter-tail/<fixture>/flash.png`), copied to
`output.expected.png`, tolerance 1, `max_outliers = 0`. Before = clean `origin/master`, same box, `--mode=graphics`.

| fixture | Flash | Ruffle exporter | ours before | ours after |
|---|---|---|---|---|
| `avm1_po3_cm_folded_clear` | g red, h blue | identical to Flash | **g blue** (FAIL 4800, max 255) | PASS 0 / max 0 |
| `avm1_po3_cm_live_under_cxform` | left 63, right 128 | 64 / 128 | **100** / 128 (FAIL 7200, max 37) | PASS 0 / max 1 |
| `avm1_po3_cm_alpha_bias_edge` | interior (255,63,63); edges x=110/169, y=80/119 **(255,127,127)**; corners (255,159,159) | crisp (255,63,63) on 111..169 × 81..119 | interior ok, edges (255,159,159), corners (255,207,207) (FAIL 392, max 48) | **PASS 0 / max 0** |

### 1.1 `folded_clear`: `filters = []` drops a FOLDED CM (XS)
- Mechanism: `swf.cpp` folds an exact CM list into the placement cxform at recompile time
  (`PlaceCmCompose::emit`), so the entry's `cxform_id` carried the swap forever; `avm1ApplyRuntimeFiltersToEntry`
  cleared only `cm_live`.
- Fix: the recompiler now also emits `tagSetColorMatrixFolded(app_context, depth, <unfolded cxform id>)` after the
  filter list of a folded placement (root arm and sprite arm). `tag.c tagSetColorMatrixFolded` stores the rebased
  plain id in two **trailing** `DisplayObject` fields (`cm_folded`, `cm_plain_cxform_id`; cleared with `cm_live` in
  both placement arms). `action.c avm1ApplyRuntimeFiltersToEntry` restores `cxform_id = cm_plain_cxform_id` whenever AS
  replaces the list (Ruffle `set_filters` replaces the authored list; a runtime CM in the new list is still folded on
  top by `tag.c obj_runtime_cm`).

### 1.2 `live_under_cxform`: placement cx AFTER a live CM chain (S)
- Flash order (= Ruffle `render_base`): the object is drawn into its cache with an identity cx, the CM passes run
  (clamped per pass), and the colour transform is applied at the blit: 200 → ×2 clamp 255 → ×0.5 127.5 → cx 0.5 →
  Flash 63 (Ruffle 64). We kept the fold whenever the placement had a cx (100).
- Fix, recompiler: `PlaceCmCompose::live(mult, add, shape_leaf)`: a non-identity placement cx no longer blocks the
  live route **when the placed character is a DefineShape** (`context.shape_char_ids`). A sprite keeps the fold: its
  children carry its cx in their composed slots, so an identity draw of the sprite entry would not remove it.
- Fix, runtime (`tag.c render_filtered_core`): for a CM-only live chain on a SHAPE / MORPH entry with a CPU-readable,
  non-overridden placement cx (`!cx_overridden`), the source is drawn with `cxform_id = 0` and the cx runs as one more
  per-texel pass (`renderer_run_color_matrix` with the cx as a 4×5 matrix) after the CMs; the legacy blit-back
  composite is unchanged.

### 1.3 `alpha_bias_edge`: why Flash anti-aliases the rect edge (brief question answered)
- **Mechanism (measured, reproduced byte-exactly):** Flash renders the filtered clip into its cache at its **true
  sub-pixel position** (no blit snap) and runs the CM per cache texel on the **coverage alpha**. The rect spans
  110.5..169.5: column 110 has coverage 0.5, so A' = 0.5 × (0.5 × 255) + 64 = 127.75 → over white
  (255, 255 − 128, …) = **(255,127,127)**; a corner has coverage 0.25 → A' = 96 → **(255,159,159)**; the interior
  A' = 191.5 → (255,63,63). It is neither a half-pixel offset of the whole clip nor filter-bounds AA: it is the
  ordinary AA rim of an unsnapped shape, with the bias added per texel AFTER coverage (the fold adds it before
  coverage: cov × (0.5 × 255 + 64) → (255,159,159) on an edge, our old output). Ruffle differs only by its cache
  blit snap (round(110.5) = 111, so it covers whole pixels 111..169 crisp).
- Fix (`render_webgpu.c` + `tag.c` + recompiler):
  - `PlaceCmCompose::live` now routes an alpha bias > 0 **live** (it was kept folded on purpose because the CM pass
    runs over the stage-sized layer and would paint the bias across the stage).
  - New one-shot `render_webgpu_set_cm_keep_empty` (`renderer_set_cm_keep_empty`, no-op in the NO_GRAPHICS arm of
    `renderer.h`): the next `run_color_matrix` leaves a = 0 texels (0,0,0,0) (signalled by lifting the uniform's alpha
    bias by 65536, so the pipeline / uniform layout are unchanged; the old shader arithmetic is untouched otherwise).
    `render_filtered_core` sets it for every CM member with `cm_matrix[19] > 0` (and for the cx-after pass when the cx
    adds alpha). This is Ruffle's observed behaviour for empty texels (its unguarded divide leaves them empty), so
    the bias can no longer leak outside the object.
  - `tag.c cab_snaps`: new `obj_live_cm_abias_only` (live, CM-only list with an alpha bias, no type 1-4 filter, no
    cacheAsBitmap) → **not snapped**, per the FP32 capture. Scoped deliberately: the other live CMs
    (`avm1_po3_color_matrix_live`, Ruffle-exporter golden, AFROMR quadrant at the same .5 offset) keep Ruffle's snap
    until a Flash capture decides them (LOCAL ORACLE REQUEST 3). Flash's rule is almost certainly "never snap a
    filter cache" (also `cache_as_bitmap/avm1_color`, s27 w1 §6), so request 3 is expected to widen this.
- Result: **max diff 0 over the whole image**, so no interior-only comparison was needed.

## 2. AVM1 `applyFilter` beyond ColorMatrix (bridge)

### 2.1 Linkage (the premise that changed the design)
`avm2_bitmap.c` is AVM2-only in every build list, and its kernels (`fb_apply_grown`, `bd_apply_convolution`, …) are
`static`. Options weighed: (a) link the AVM2 tree into AVM1 builds (no: whole VM); (b) extract the kernels into a
shared TU (no: `w2-flash-filter-kernels` is editing exactly those functions now); (c) **re-compile the kernel block in
a second TU** (chosen). The second TU sees only `static` copies, so a hybrid build links both without a clash, and the
AVM1 path runs the kernels byte-for-byte as AVM2 does, with no copy to drift.

### 2.2 What landed
- `avm2_bitmap.c`: **guards only, no code change** — 5 `#ifndef AVM2_BITMAP_KERNELS_ONLY` / `#endif` pairs at
  function-group boundaries (the zlib / stb includes, blend helpers … `check_valid`, arg/geometry helpers, rectangle
  construction … `bd_noop`, and `bd_apply_filter` … EOF), plus one comment above `bd_apply_filter` naming the kept
  block. Kept in the kernel build: colour helpers (`premul` / `unmul` / `with_alpha`), `bd_get_raw` / `bd_set_raw`,
  the `PixelRegion` helpers, and the whole "applyFilter / generateFilterRect" kernel block (`color_matrix_pixel` …
  `fb_apply_grown`). In a normal (AVM2) build every guard is a no-op.
- `src/actionmodern/avm1_filter_kernels.c` (new TU): `#define AVM2_BITMAP_KERNELS_ONLY`, `#define avm2_alloc
  avm1_fk_alloc` (the kernels' scratch allocations go through `heap_alloc(ctx->app, …)`; a private `Avm2Context`
  carries only `app`), then includes the kernel source (`avm2_bitmap_kernels.inc` in flat build dirs, else
  `../avm2/avm2_bitmap.c`). Exports `avm1_filter_kernels_apply(...)`: wraps the AVM1 buffers as `Avm2BitmapDataExt`
  (both are premultiplied 0xAARRGGBB; `setPixel32` stores `premultiplyAlpha`, `getPixel32` unpremultiplies),
  snapshots the source when it IS the target, and dispatches like `bd_apply_filter`: Blur or `fk_is_glowlike(kind)`
  → `fb_apply_grown`; Convolution with a matrix → `bd_apply_convolution`; GradientGlow / GradientBevel / empty
  Convolution → the kernels' pass-through copy. (Dispatch on `fk_is_glowlike`, so if `w2-flash-filter-kernels` makes
  the gradient kinds glow-like, AVM1 follows automatically.) `nm` of the AVM1 object: only `heap_alloc` /
  `heap_free` / libc undefined.
- `include/actionmodern/avm1_filter_kernels.h` (new): `Avm1FilterKernelParams` (swf::Filter units, = `Avm2FilterVal`
  minus the AVM2 value fields), so `action.c` includes no AVM2 header.
- `action.c`: `bitmapDataApplyFilter`'s non-CM arm (was "return 0, untouched") builds the params with the new
  `avm1FilterKernelParams` (next to `avm1LowerFilterObject`, same property reads and clamps; Ruffle
  `avm1_to_filter` quantization: Fixed16 blur/angle/distance, Fixed8 strength, `(a*255) as u8`, quality 0..15,
  gradient `min(colors, ratios)` stops with alphas padded by 1.0, convolution matrix resized to matrixX × matrixY)
  and calls the bridge. Return value stays 0 (Ruffle). CM arm and the −1 non-filter rule unchanged.
- Build lists (new `.c` + the `.inc` copy where the build dir is flat): `verify_output.py` (`compile_native` and
  `compile_wasm` source lists, `.inc` copy next to both runtime copies), `SWFModernRuntime/CMakeLists.txt`,
  `SWFRecomp/scripts/build_test.sh` (both arms), `build_wasm_runtime_lib.sh`, `build_graphics_host.sh`,
  `profile_game_native.sh`, `SWFRecomp/wasm_wrappers/bundle/build.sh`. **The last one feeds the GitHub Pages
  in-browser recompiler**: per CLAUDE.md, dispatch `deploy-pages.yml` (a `dry_run=true` first is cheap) after landing.

### 2.3 Fixtures
- `regression/avm1_applyfilter_kernels` (trace, SWF 8, analytic probes only): blur interior of a uniform opaque
  source keeps 0xFF336699 and its edge loses alpha; outer glow keeps the red interior, leaves a far corner empty,
  puts alpha next to the square; DropShadow (blur 0) keeps the interior, shadows below-right, nothing above-left;
  1×1 convolution `[1]`, bias 16 → 0xFF4376A9; in-place blur keeps the interior.

| line | expected | origin/master | patch |
|---|---|---|---|
| `blur c` | −13408615 | **0** | −13408615 |
| `glow c` / `glow halo a>0` | −65536 / true | **0 / false** | −65536 / true |
| `shadow c` / `shadow br a>0` | −65536 / true | **0 / false** | −65536 / true |
| `conv c` | −12355927 | **0** | −12355927 |
| others (ret 0, empty corners, blur edge, self) | as shipped | same | same |

  FAIL (output_mismatch, 6 lines) → PASS in **no-graphics and graphics**. Flash trace confirmation: request 2.
- `w2-applyfilter-cm-fixtures/avm1_applyfilter_{blur,glow,dropshadow,bevel,convolution,gradientglow,gradientbevel}`:
  image fixtures (40×40 source: red square + blue inner square; each filter applied into a TRANSPARENT and an OPAQUE
  white 80×80 target at destPoint (20,20), attached at (10,10) / (100,10); 7 getPixel32 probes traced). `ours.png` /
  `ours.txt` are the patch's output. Notable, for the Flash comparison: on the OPAQUE target the kernels write the
  whole grown rect, so the white background inside it becomes black (the AVM2 kernel's `with_alpha(c, 0xFF)` of an
  empty texel), and the gradient kinds are Ruffle's pass-through copy (Flash certainly draws a gradient glow).
  These are the two places I expect Flash to disagree; both are kernel behaviour owned by `w2-flash-filter-kernels`.

### 2.4 Merge coupling with `w2-flash-filter-kernels` (read before applying either patch)
- My `avm2_bitmap.c` hunks are 11 guard / comment lines at group boundaries; none is inside a kernel body, so a
  textual conflict with the sibling is unlikely.
- **Semantic coupling:** the AVM1 TU compiles only what lies inside the kept regions. If the sibling adds a helper
  that a kernel calls but places it in an excluded region (e.g. next to `blend_over`, or after `bd_apply_filter`),
  every AVM1 build fails to compile `avm1_filter_kernels.c` (an "implicit declaration" / undefined `static`). The
  fix is mechanical: move the helper into the kernel block (anywhere between the "applyFilter / generateFilterRect"
  banner and `fb_apply_grown`). Likewise a signature change of `fb_apply_grown`, `bd_apply_convolution` or
  `fk_is_glowlike` needs the one call site in `avm1_filter_kernels_apply` updated. **Check:** after applying both
  patches, build any one AVM1 test (`verify_output.py --test=avm1_applyfilter_kernels --tests-dir=…/regression`).
  It fails loudly, never silently.
- `bd_draw_cm_filtered` (sibling) and the `bd_draw_*` / text paths (`w2-draw-cx-text`) are in excluded regions and
  are not touched.

## 3. Files and functions touched (self-localized)
- `SWFRecomp/src/swf.cpp`: `PlaceCmCompose` (comment, `live(…, shape_leaf)`), the root PlaceObject arm (`cm_live`
  call, `po_plain_cxform_id`, `cm_folded`, emits `tagSetColorMatrixFolded`), the DefineSprite PlaceObject arm (same
  three, `sp_*`). Recompiler change: rebuilt, every test above run with `--recompile` (the canary passes it).
- `SWFModernRuntime/src/libswf/tag.c`: new `obj_live_cm_abias_only`; `cab_snaps` (one line); `render_filtered_core`
  (`cm_cx_after` block around the source draw, keep-empty before a biased CM pass, cx-after pass before
  `renderer_resume_pass`); new `tagSetColorMatrixFolded`; `cm_folded = 0` next to the two `cm_live = 0` placement
  resets (`tagPlaceObject2`'s two arms). No `#ifdef NO_GRAPHICS` arm changed beyond the copied script-only guard in
  `tagSetColorMatrixFolded` (same as `tagSetColorMatrixLive`).
- `SWFModernRuntime/src/actionmodern/action.c`: `bitmapDataApplyFilter` (non-CM arm), forward decl + include near
  it, new `avm1FkFixed16` / `avm1FkFixed8` / `avm1FkAlpha` / `avm1FkArray` / `avm1FkType` / `avm1FilterKernelParams`
  (all `static`, placed after `avm1LowerFilterObject`), `avm1ApplyRuntimeFiltersToEntry` (folded-cx restore).
- `SWFModernRuntime/src/rendering/render_webgpu.c`: `color_matrix_wgsl` (2 lines), new file-static
  `g_cm_keep_empty` + `render_webgpu_set_cm_keep_empty`, `render_webgpu_run_color_matrix` (reads/clears the flag, one
  uniform line). Header: `render_webgpu.h` (1 prototype), `renderer.h` (`renderer_set_cm_keep_empty`, both arms).
- `SWFModernRuntime/include/libswf/swf.h`: `DisplayObject` trailing `cm_folded`, `cm_plain_cxform_id`.
  `tag.h`: 1 prototype.
- `SWFModernRuntime/src/avm2/avm2_bitmap.c`: guards only (§2.2). New: `avm1_filter_kernels.{c,h}`.
- Build lists (§2.2) and `ruffle-tests/render_canary_tests.txt` (3 members appended at EOF, tier 1).
- No `swf_core.c`, `tag_stubs.c`, `rasterizeMovieClipToBitmap` or `bd_draw_*` change.

## 4. Measurements

### 4.1 Fidelity
My BEFORE renders are md5-identical to CI's actual PNGs on `origin/ruffle-image-results` for
`visual/cache_as_bitmap/avm1_color` (`74228586…`) and `visual/filters/blur_quality` (`26b97ac4…`), so local absolute
verdicts are CI-grade. Every canary-listed `test.swf` and `output.expected.png` (376 files) is byte-identical between
the BEFORE tree (a clean `origin/master` worktree) and the AFTER tree.

### 4.2 Render canary (md5, both legs `--recompile`)
List = the standing `render_canary_tests.txt` (153) ∪ every `regression/` image row (43) ∪ every
`visual/filters/*` and `visual/cache_as_bitmap/*` image row ∪ `avm1/bitmapdata_applyfilter_colormatrix` = **197
tests / 264 PNGs**; AFTER adds the 3 new fixtures.

```
IDENTICAL 264   DIFFERS 0   APPEARED 0   VANISHED 0   NO_RENDER 0
TRACE STATUS CHANGES: (none)   IMAGE STATUS CHANGES: (none)
MISSING 3 (the three new avm1_po3_cm_* fixtures, absent from BEFORE by construction)
```
Notably md5-identical: `regression/avm1_po3_color_matrix_live` and `_nested` (their ABIAS quadrant now takes the
live route with keep-empty instead of the fold: integer-aligned rects, so the result is the same), `_clear`,
`avm1_runtime_filters*`, `avm1_nested_po3_filters`, `avm1_placed_drawing_color`, `visual/filters/color_matrix`,
`avm2/bitmapdata_filter_sourcerect`, `avm2/bitmapdata_applyfilter_destpoint_edges`, `visual/filters/blur_fractional`
(the AVM2 kernels through the guarded `avm2_bitmap.c`).

### 4.3 Regression suite
- **no-graphics (trace), patch build:** every `regression/` row whose name matches filter / cm / bitmap / color /
  cxform / applyfilter — **27 / 27 PASS** (`avm1_applyfilter_convolution_not_cm`, `avm1_applyfilter_kernels`,
  `avm1_attached_clip_color`, `avm1_cxform_override_overflow`, `avm1_dynclip_color_transform`,
  `avm1_edittext_placed_cxform{,_script}`, `avm1_filter_list_overflow`, `avm1_jpeg3_alpha_bitmap`,
  `avm1_nested_po3_filters`, `avm1_parent_child_bitmap{,_fill}`, `avm1_placed_drawing_color`, the three
  `avm1_po3_cm_*`, `avm1_po3_color_matrix_live{,_clear,_nested}`, `avm1_runtime_filters{,_cm_bitmap}`,
  `avm1_set_new_text_format_color`, `avm2_bitmapdata_draw_textfield`, `avm2_edittext_placed_cxform`,
  `avm2_layer_group_filtered_child`, `bitmap_pool_layer_cap`, `layer_group_filtered_child`).
- **graphics:** all 43 + 3 `regression/` image rows are in the canary (§4.2): no status change, md5-identical, the
  3 new rows pass.
- Riders (both modes where trace): `avm1/bitmapdata_applyfilter_colormatrix` PASS (and md5-identical),
  `avm1/bitmap_data` PASS, `from_gnash/actionscript.all/BitmapData-v8` `ruffle_matched` (unchanged, w1 §4).

### 4.4 Corpus reach (why +0 corpus flips)
A PlaceObject3 scan of every downloaded SWF (avm1, avm2, visual, from_shumway, from_gnash, text, fonts,
regression; root and DefineSprite arms) for ColorMatrix filter lists: 61 placements, **none outside `regression/`
with an alpha bias or a placement cx on a shape** (the two recompiler routes this patch changes); the only ABIAS
placements are the s26 fixtures `avm1_po3_color_matrix_live{,_nested}` (canary: md5-identical). No corpus row assigns
`filters` on a folded CM placement, and (w1 §3) no corpus AVM1 row applies a non-CM filter.

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

| row | axis | before (origin/master) | after | note |
|---|---|---|---|---|
| `regression/avm1_po3_cm_folded_clear` | trace | n/a (new) | pass | trace = `done` |
| `regression/avm1_po3_cm_folded_clear` | pixel | n/a (new; fails on master: 4800 / max 255) | **pass** 0 / max 0 | FP32 golden |
| `regression/avm1_po3_cm_live_under_cxform` | trace | n/a (new) | pass | empty trace |
| `regression/avm1_po3_cm_live_under_cxform` | pixel | n/a (new; master 7200 / max 37) | **pass** 0 / max 1 @1 | FP32 golden |
| `regression/avm1_po3_cm_alpha_bias_edge` | trace | n/a (new) | pass | empty trace |
| `regression/avm1_po3_cm_alpha_bias_edge` | pixel | n/a (new; master 392 / max 48) | **pass** 0 / max 0 | FP32 golden |
| `regression/avm1_applyfilter_kernels` | trace | n/a (new; master output_mismatch, 6 lines) | **pass** (both modes) | no image |
| every other row | both | — | unchanged | canary 264/264 md5-identical |

CI mode: the change touches the recompiler, `tag.c` render path, `action.c` shared code and the build lists:
**graphics** (per-change default) plus **no-graphics** (the new TU is compiled into every AVM1 no-graphics build and
`verify_output.py`'s source lists changed). `categories=all` suffices (no AVM2 runtime / recompiler-AVM2 emission
change; the `avm2_bitmap.c` guards are no-ops in AVM2 builds), but a `full` run would also exercise every AVM2
BitmapData row through the guarded file.

## HOLDs / NO-GOs and their completion mechanisms
1. **AVM1 applyFilter Flash fidelity** (§2.3): the bridge reproduces the AVM2 kernels; whether they match Flash for
   AVM1 is open on two visible points (opaque target background, gradient pass-through). Completion: FLASH image +
   trace of the 7 fixtures (request 1); then either land them as regression rows or hand the deltas to the kernel
   owner (`w2-flash-filter-kernels` successor).
2. **No-snap for the other live CMs** (§1.3): HOLD, scoped to alpha-bias. Completion: FLASH image of
   `regression/avm1_po3_color_matrix_live` (request 3). If Flash shows the AFROMR quadrant (x 110.5) unsnapped, widen
   `obj_live_cm_abias_only` to every live CM-only entry (one condition) and replace that fixture's Ruffle golden with
   the Flash capture (and `_nested`'s).
3. **Bias over empty texels inside the cache bounds**: keep-empty is Ruffle's behaviour; Flash's is unmeasured (a
   shape with a hole under an alpha-bias CM). The same request 3 decides it (quadrant 2 of
   `avm1_po3_color_matrix_live` is an ABIAS CM over two rects with a 20 px gap). If Flash tints the gap, the fix is
   the CM pass bounded to the object's device-pixel rect (scissor) instead of keep-empty.
4. **cx-after on sprites**: a sprite with a placement cx and an inexact CM keeps the fold (children carry the cx).
   Completion: an identity-seeded compose of the sprite's children while its filter layer is captured
   (`compose_children` seed), priced S–M, no corpus row.

## New unclaimed leads
1. **Flash never snaps filter caches** (two FP32 data points now: `cache_as_bitmap/avm1_color` and
   `avm1_po3_cm_alpha_bias_edge`). The display-filter rows' goldens are mostly Ruffle-made, so the general Flash rule
   costs Ruffle-golden passes; a Flash capture of one display-filter row with a sub-pixel position (e.g.
   `visual/filters/drop_shadow`) would size the arc.
2. **AVM1 `generateFilterRect`** still returns the source rect for every kind (AVM2 has the same Ruffle stub); with
   applyFilter now growing the output rect, a game that sizes its target by `generateFilterRect` gets a cropped
   result. Flash returns the grown rect; the kernels' `fb_reach` already computes it (XS–S).
3. AVM1 `draw()` of a filtered source can now reuse `avm1_filter_kernels_apply` (w1 §3's other half), S.

## LOCAL ORACLE REQUESTS
1. **FLASH, image + trace, 1 frame each:**
   `SWFRecompDocs/plans/session27-fanout-reports/w2-applyfilter-cm-fixtures/avm1_applyfilter_{blur,glow,dropshadow,bevel,convolution,gradientglow,gradientbevel}/test.swf`.
   Compare with the archived `ours.png` / `ours.txt` next to each SWF. The traces (`ret` + 14 getPixel32 probes) are
   the cheap half; the images show the opaque-target background and the gradient kinds.
2. **FLASH, trace, 1 frame:** `ruffle-tests/tests/swfs/regression/avm1_applyfilter_kernels/test.swf` — expect the
   shipped `output.txt` (17 lines). If `ret` reads other than 0 in Flash, change only those lines.
3. **FLASH, image, 1 frame:** `ruffle-tests/tests/swfs/regression/avm1_po3_color_matrix_live/test.swf` (200×150).
   Decides HOLD 2 (is quadrant 4, the AFROMR rect at x 110.5 / y 80.5, unsnapped with a half-coverage rim?) and
   HOLD 3 (is quadrant 2's 20 px gap between the two ABIAS rects at x 130..149 white, or tinted?).
