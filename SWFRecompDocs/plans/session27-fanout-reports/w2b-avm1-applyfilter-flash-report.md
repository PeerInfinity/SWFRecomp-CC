# s27 wave 2b: `w2b-avm1-applyfilter-flash` (AVM1 applyFilter kinds and live-CM rules against Flash Player 32)

**NEW FILES**
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-avm1-applyfilter-flash-report.md` (this report)
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-avm1-applyfilter-flash.patch` (`git diff --binary origin/master` over
  `SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`, the 4 new fixture dirs,
  the two replaced `avm1_po3_color_matrix_live*` goldens + generator docstring, and the RvF doc entry;
  `git apply --check -R` verified on the branch)
- `ruffle-tests/tests/swfs/regression/avm1_applyfilter_blur/` (`create_test_swf.py` = generator of all four, `test.swf`,
  `test.toml`, `output.txt` = **FP32 trace**, `output.expected.png` = **FP32 capture**)
- `ruffle-tests/tests/swfs/regression/avm1_applyfilter_glow/`, `…_bevel/`, `…_convolution/` (same layout, FP32 trace + PNG)

Modified (non-source): `regression/avm1_po3_color_matrix_live/output.expected.png` and `…_live_nested/output.expected.png`
(Ruffle-exporter golden → **FP32 capture**), `…_live/create_test_swf.py` (docstring only; the generator still reproduces
the SWFs), `render_canary_tests.txt` (4 members appended at EOF, one comment fixed), `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`
(one new section).

**Box:** cloud, `SETUP_STATUS` all OK (Dawn on lavapipe). Base `origin/master` `2d189a8ad`.
`download_tests.sh avm1 avm2 visual from_shumway from_gnash text fonts`, upstream Ruffle master **`1e604fa87`**.

## Verdicts and priced flips

| # | Item | Verdict | Graded moves |
|---|---|---|---|
| 1 | Brief premise: "the other six differ heavily" | **REFUTED in part.** The archived `ours.*` predate the kernel landing (they were rendered on `53540ff0`, before `w2-flash-filter-kernels` merged). On current master the **transparent half already matches Flash** for blur, glow, dropshadow (±1 level) and bevel, and the blur image is byte-exact. The heavy diffs were the **opaque target** and the **gradient kinds**. | — |
| 2 | Opaque target, Glow/DropShadow/Bevel/GradientGlow/GradientBevel | **GO, landed.** Flash returns **-6** and leaves the target untouched. | glow, bevel → PASS |
| 3 | Opaque target, Blur | **GO, landed.** Flash stores the premultiplied word WITH alpha; display ignores it. | blur trace → PASS |
| 4 | `avm1_applyfilter_{blur,glow,bevel,convolution}` | **GO, landed with Flash goldens** (trace + image, max diff 0) | +4 regression rows (trace) +4 (pixel) |
| 5 | `avm1_applyfilter_dropshadow` | **HOLD**: 1 trace line (`dt 50,50` alpha 0x98 vs Flash 0x99), 15 px max 2. Kernel arithmetic, same class as the AVM2 `dropshadow default y=6` residual. | — |
| 6 | `avm1_applyfilter_gradient{glow,bevel}` | **HOLD on the sibling.** Opaque half now matches (-6). The transparent half needs the gradient kernels (`w2b-filter-kernels-residual`). | — |
| 7 | HOLD 2 (no-snap for every live CM-only entry) | **GO, Flash shows it.** Quadrant 4 is unsnapped. | `_live`, `_nested` golden → Flash, pass |
| 8 | HOLD 3 (bias over empty texels) | **GO, Flash TINTS them** within the cache rect `floor(xmin)..floor(xmax)`. Implemented as a scissored second CM pass. | same |

**Priced yield: +0 corpus flips** (no corpus AVM1 row applies a non-CM filter, and none has a live CM placement; see
w2-applyfilter-cm §4.4). There are **+4 new regression rows on both axes**, and 2 regression rows keep their pass on a
**Flash** golden instead of a Ruffle one. The canary shows **0 unintended moves** (281/285 md5-identical; the 4 that
differ are exactly the ledger).

## 1. AVM1 applyFilter per kind (FP32 vs ours)

### 1.1 Diagnosis
Fixtures: the w2-applyfilter-cm set (40×40 source, red 20×20 + blue 8×8). Each fixture applies its filter into a
TRANSPARENT and into an OPAQUE-white 80×80 target at destPoint (20,20).

| kind | transparent half vs Flash (current master) | opaque half: Flash | opaque half: ours before |
|---|---|---|---|
| blur | **exact** (image + 7 probes) | ret 0; probes = raw premultiplied word with alpha (`0x6B640005`, `0` on the rim); draws black rim | alpha forced 0xFF (`0xFF640005`, `0xFF000000`); same image |
| glow | **exact** | **ret -6**, untouched (all `-1`) | ret 0, glow written, black background over the grown rect |
| dropshadow | 1 probe alpha −1 (`0x98` vs `0x99`), 15 px max 2 | **ret -6**, untouched | ret 0, written |
| bevel | **exact** | **ret -6**, untouched | ret 0, written |
| convolution | exact | exact (ret 0, applies) | exact |
| gradientglow | pass-through copy vs Flash's gradient glow (3 probes, 468 px) | **ret -6**, untouched | ret 0, copy |
| gradientbevel | pass-through vs gradient bevel (1 probe, 351 px) | **ret -6**, untouched | ret 0, copy |

The brief's other suspects are cleared by the exact transparent halves: AVM1 argument defaults/quantization, filter
bounds/growth and the destPoint/sourceRect handling. (Blur growth: Flash's black rect on the opaque side spans 54 px =
the `PASS_SCALES` growth 7/side that `cceb5133a` landed. It is exact now.)

### 1.2 What landed
- `action.c bitmapDataApplyFilter` (non-CM arm, before the bridge call): if `!dest_bmp->transparent` and the kind is
  2/3/4/7/8 (DropShadow, Glow, Bevel, GradientGlow, GradientBevel), return **-6** without touching the target. This is
  the AVM1 counterpart of the AVM2 `#2077` rule. The return stays 0 for blur, convolution and CM.
- `avm1_filter_kernels.c avm1_filter_kernels_apply`: for a Blur into an opaque target, the kernel wrapper is marked
  transparent, so `fb_write_grid` stores the premultiplied word unforced. AVM1 `getPixel32` already returns an opaque
  bitmap's raw word, so the probes match Flash. **AVM2 is unchanged** (its path still forces 0xFF; no AVM2 Flash data on this).
- Display: `action.c` new `g_bmp_opaque_raw_alpha` (set by the blur-into-opaque arm) and `bmpOpaqueAlphaForcedCopy`.
  `actionIterateAttachedBitmaps` uploads an alpha-forced copy of an opaque bitmap that holds non-0xFF words. While the
  flag is 0 it does nothing; no corpus row sets the flag.

### 1.3 Per-test before/after (graphics, same box; before = clean `origin/master` with the fixture dirs present)

| test | trace before | trace after | image before | image after |
|---|---|---|---|---|
| `regression/avm1_applyfilter_blur` | output_mismatch (6 `dop` lines) | **pass** | pass (md5-identical before/after) | pass, max 0 |
| `regression/avm1_applyfilter_glow` | output_mismatch (8 lines) | **pass** | fail (3136 px, max 255) | **pass**, max 0 |
| `regression/avm1_applyfilter_bevel` | output_mismatch (8 lines) | **pass** | fail (3136 px, max 255) | **pass**, max 0 |
| `regression/avm1_applyfilter_convolution` | pass | pass | pass | pass (md5-identical) |
| (held) dropshadow | 8 lines | 1 line | 2704 px | 15 px max 2 |
| (held) gradientglow / gradientbevel | 10 / 9 lines | 3 / 1 lines | 2068 / 1951 px | 468 / 351 px (transparent half only) |

No-graphics leg (action.c is shared code): all four new rows **PASS**, as do `avm1_applyfilter_kernels` and
`avm1_applyfilter_convolution_not_cm`.

## 2. Live ColorMatrix: HOLD 2 and HOLD 3 decided by Flash

FP32 `avm1_po3_color_matrix_live/flash.png` vs the Ruffle golden: 1000 px, all in quadrants 2 and 4.
- **Quadrant 4** (AFROMR `A' = 0.5 R`, rect at 110.5..169.5): Flash covers **110..169 × 80..119** at a uniform
  `(255,127,127)`, rim included. The alpha comes from unpremultiplied red, so coverage drops out; the entry is simply
  **not snapped**. Ruffle snaps it to 111..169. → **HOLD 2: widen.** `tag.c obj_live_cm_abias_only` → **`obj_live_cm_only`**
  (any live CM-only list, no type 1–4 filter, no cacheAsBitmap); `cab_snaps` returns 0 for it.
- **Quadrant 2** (ABIAS `b+255, a+128` on two bars with a 20 px gap): Flash **tints the gap** `(127,127,255)`, and also
  column 170 and row 50, i.e. the cache rect is **floor(xmin)..floor(xmax) × floor(ymin)..floor(ymax)** of the
  110..170 × 10..50 px bounds. This is consistent with `avm1_po3_cm_alpha_bias_edge` (bounds 110.5..169.5 → 110..169;
  FP32 shows column 170 white). → **HOLD 3: Flash tints inside the cache rect, keeps outside empty.**
  - `render_webgpu.c`: new one-shot `render_webgpu_set_cm_bias_rect` (macro `renderer_set_cm_bias_rect`, no-op in
    the NO_GRAPHICS arm). When it is set together with keep-empty, `render_webgpu_run_color_matrix` runs the existing
    keep-empty pass, then a **second pass of the same pipeline without keep-empty, scissored to the rect** (+ filter
    pad), `LoadOp_Load` into the same target. Outside the rect the result is bit-identical to before. Pipeline and
    uniform layout are unchanged.
  - `tag.c`: new `cm_cache_rect_px` (world AABB of `opaque_bg_local_bounds` → device px, floor both ends), fed by a
    32-row note table `cm_world_note` that `compose_children` fills where it writes a live CM-only entry's slot.
    Root baked slots read `transform_data`, and the renderer's xform mirror is a fallback (it is NULL on lavapipe
    native). `render_filtered_core` sets the rect for every CM member with an alpha bias, and for the cx-after pass.
- Result: `avm1_po3_color_matrix_live` and `_nested` render **byte-identical to the Flash capture** (0 px over 1).
  Both goldens are replaced by the FP32 PNG. `_nested` reuses the root capture: it shared the root's golden before,
  and its sprite sits at the origin. A Flash capture of the nested SWF itself is requested below to confirm.
  `alpha_bias_edge`, `live_under_cxform`, `folded_clear` and `_live_clear` (FP32 / analytic goldens) are
  md5-identical before/after.

## 3. Measurements

### 3.1 Render canary (md5, runtime-only change so no `--recompile`; both legs on this box, before = patch reverse-applied)
List: the standing `render_canary_tests.txt` set ∪ every `regression/` image row (58 incl. the 4 new) ∪ every
`visual/filters/*` and `visual/cache_as_bitmap/*` image row ∪ AVM1 bitmap/filter/colour image rows = **218 tests / 285 PNGs**.
```
IDENTICAL 281   DIFFERS 4   APPEARED 0   VANISHED 0   NO_RENDER 0
DIFFERS: regression/avm1_applyfilter_bevel, _glow (fail -> pass), regression/avm1_po3_color_matrix_live, _nested (fail -> pass vs the new Flash golden)
TRACE STATUS CHANGES: avm1_applyfilter_{bevel,blur,glow} output_mismatch -> pass
```
Nothing else moved: the other `visual/filters/*`, `cache_as_bitmap/*`, `avm1_po3_*`, `avm1_runtime_filters*` rows and the
whole standing set are all md5-identical.

### 3.2 Regression suite / riders
- All `regression/` image rows: in the canary (no unintended status or md5 move).
- No-graphics: the 4 new rows, `avm1_applyfilter_kernels` and `avm1_applyfilter_convolution_not_cm` PASS.
- `avm1/bitmapdata_applyfilter_colormatrix` PASS (no-graphics; graphics md5-identical in the canary).
  `from_gnash/actionscript.all/BitmapData-v8` stays `ruffle_matched` in both modes (unchanged).

## 4. Files and functions touched (self-localized)
- `SWFModernRuntime/src/actionmodern/action.c`: `bitmapDataApplyFilter` (non-CM arm: the -6 gate and the flag set);
  new `static int g_bmp_opaque_raw_alpha` (next to `g_bitmap_native_count`); new `bmpOpaqueAlphaForcedCopy`;
  `actionIterateAttachedBitmaps` (3 lines around `cb`).
- `SWFModernRuntime/src/actionmodern/avm1_filter_kernels.c`: `avm1_filter_kernels_apply` (1 line + comment).
  **No `avm2_bitmap.c` change.**
- `SWFModernRuntime/src/libswf/tag.c`: `obj_live_cm_abias_only` → `obj_live_cm_only`; `cab_snaps`; new
  `cm_world_note` / `g_cm_world` / `cm_cache_rect_px`; `compose_children` (one `cm_world_note` call after the slot
  write); `render_filtered_core` (rect computed before the source draw, set before the biased CM and cx-after passes).
- `SWFModernRuntime/src/rendering/render_webgpu.c`: new `render_webgpu_set_cm_bias_rect`;
  `render_webgpu_run_color_matrix` (second scissored pass). Headers: `render_webgpu.h` (1 prototype), `renderer.h` (both arms).
- No `swf_core.c`, `tag_stubs.c`, `NO_GRAPHICS`-arm or recompiler change.

## 5. Merge coupling
- **`w2b-filter-kernels-residual`** (gradient kernels in `avm2_bitmap.c`): the bridge sends a kind to
  `fb_apply_grown` only when `fk_is_glowlike(kind)` is true; otherwise the gradient kinds take the bridge's
  pass-through copy. If the sibling implements gradients outside `fk_is_glowlike` (e.g. a new arm in
  `bd_apply_filter`), the AVM1 bridge must add the same dispatch in `avm1_filter_kernels_apply` (one `else if`), and
  any new helper must sit inside the kept kernel block (w2-applyfilter-cm §2.4). After both patches, run
  `avm1_applyfilter_gradientglow` / `_gradientbevel` from `w2-applyfilter-cm-fixtures/` with the `flash.{txt,png}` as
  goldens. If they pass, land them as regression rows exactly like the four here (copy the dir, `output.txt` =
  flash.txt, `output.expected.png` = flash.png; the generator in `avm1_applyfilter_blur/create_test_swf.py` already
  lists both kinds and writes any `../avm1_applyfilter_<kind>` dir that exists).
- **`w2b-group-alpha-triggers`**: no shared function. My `tag.c` hunks are in `render_filtered_core` (CM arm only)
  and `compose_children` (one line after the dynamic-slot write).

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

| row | axis | before (origin/master) | after | note |
|---|---|---|---|---|
| `regression/avm1_applyfilter_blur` | trace | n/a (new; master output_mismatch) | **pass** | FP32 trace |
| `regression/avm1_applyfilter_blur` | pixel | n/a (new; master pass) | **pass** max 0 | FP32 golden |
| `regression/avm1_applyfilter_glow` | trace | n/a (new; master output_mismatch) | **pass** | |
| `regression/avm1_applyfilter_glow` | pixel | n/a (new; master fail 3136 / 255) | **pass** max 0 | |
| `regression/avm1_applyfilter_bevel` | trace | n/a (new; master output_mismatch) | **pass** | |
| `regression/avm1_applyfilter_bevel` | pixel | n/a (new; master fail 3136 / 255) | **pass** max 0 | |
| `regression/avm1_applyfilter_convolution` | trace | n/a (new; master pass) | **pass** | |
| `regression/avm1_applyfilter_convolution` | pixel | n/a (new; master pass) | **pass** | |
| `regression/avm1_po3_color_matrix_live` | pixel | pass (Ruffle golden) | **pass** (Flash golden) | golden replaced; master vs the Flash golden = fail 1000 px |
| `regression/avm1_po3_color_matrix_live_nested` | pixel | pass (Ruffle golden) | **pass** (Flash golden) | same |
| every other row | both | — | unchanged | canary 281/281 md5-identical outside the ledger |

CI mode: **graphics** (render path) **plus no-graphics** (shared `action.c` `bitmapDataApplyFilter`, which is in every AVM1
no-graphics build). `categories=all` suffices: no AVM2 runtime or recompiler change.

## HOLDs / NO-GOs and their completion mechanisms
1. **`avm1_applyfilter_dropshadow`**: off by one alpha level at one probe (`dt 50,50`: ours `0x98…`, Flash `0x99…`;
   15 px max 2 along x = 51 / y = 51 of the target, the far edge of the 3.54 px sub-pixel shadow offset). This is the
   same class as the AVM2 `glow_kernels` `dropshadow default y=6` residual (1 level), so it belongs to the kernel owner
   (`w2b-filter-kernels-residual`, `fb_glow_pixel` / the fractional-offset sampling). Completion: once that residual
   closes, re-run this fixture (`w2-applyfilter-cm-fixtures/avm1_applyfilter_dropshadow` + its flash.{txt,png}) and land
   it as above. No AVM1-side cause remains: the opaque half matches.
2. **Gradient kinds**: on the sibling's gradient kernels; see §5 for the landing recipe.
3. **Opaque-source / other consumers of an opaque bitmap holding non-0xFF alpha** (copyPixels / draw / beginBitmapFill
   FROM a blurred opaque bitmap): unmeasured in Flash. Only the attachBitmap display path forces alpha. Completion: a
   FLASH probe (request 3); priced XS once measured.
4. **`_nested` golden** reuses the root capture. Completion: request 2. If Flash differs, swap in its PNG.

## New unclaimed leads
1. **Flash's filter cache rect is `floor(min)..floor(max)` inclusive**, i.e. one column/row past an integer-aligned
   right/bottom edge. The display-filter paths (`render_filtered_core` blur/glow, `cacheAsBitmap` opaqueBackground)
   size nothing by this rule today. A glow/blur over an integer-aligned shape would show the extra texel in its grown
   band only through rounding, so it is probably invisible except for bias-like CMs. Low value; worth one Flash look
   before anyone sizes a cache.
2. AVM2 `applyFilter` Blur into an **opaque** target: does Flash keep the alpha word there too (`getPixel32` raw)?
   Our AVM2 path forces 0xFF. Cheap Flash trace probe (AVM2 twin of `avm1_applyfilter_blur`). If yes, it is a 1-line
   change in `fb_write_grid` (kernel owner).
3. `generateFilterRect` (AVM1 and AVM2) still returns the source rect. It is unchanged from w2-applyfilter-cm lead 2,
   and the growth numbers are now Flash-verified (54 px for blur 6/q2 on a 40 px source).

## LOCAL ORACLE REQUESTS
1. none needed for the landed rows (all FP32).
2. **FLASH, image, 1 frame:** `ruffle-tests/tests/swfs/regression/avm1_po3_color_matrix_live_nested/test.swf`. Compare
   with the root capture now used as its golden (`…/w2-local-oracles/w2-applyfilter-cm/avm1_po3_color_matrix_live/flash.png`).
   If it differs, replace `_nested/output.expected.png` with it and re-run that row.
3. **FLASH, trace, 1 frame (optional, priced XS):** a twin of `avm1_applyfilter_blur` that, after the blur into the
   opaque `dop`, does `t2.copyPixels(dop, dop.rectangle, new Point(0,0))` into a fresh TRANSPARENT bitmap and
   `getPixel32`s the rim (20,20) and (29,40). This decides whether an opaque bitmap's stored alpha leaks through
   copyPixels (HOLD 3).
