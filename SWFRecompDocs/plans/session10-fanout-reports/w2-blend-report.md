# w2-blend — wave-2 implementation report

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a2d49b872500a491b`
Base commit: `b007ee50d`. **No commits, no pushes.** Deliverable patch:
`<scratch>/w2-blend.patch` (`git diff -- SWFModernRuntime`, 6 files, +640/-40).

Spec: `<scratch>/wave1-gfx-blend.md`. Runtime-only, as wave 1 predicted — no
`SWFRecomp/` change, no `--recompile` needed. `SWFRecomp/build` was copied from
the main tree per the brief.

---

## 1. Per-step ledger F0–F7

| step | status | what landed |
|---|---|---|
| **F0** alpha-component fix | **DONE** | `blend_{add,lighten,darken,subtract}_pipeline` now use `BlendComponent::OVER` (`One / OneMinusSrcAlpha / Add`) for **alpha**. `render_webgpu.c` create_pipelines. These four are now only the *fallback* path (see F1/F3), but they still run for nested-layer and filter+blend objects. |
| **F1** layer-first add/subtract | **DONE** | New `render_webgpu_composite_blend()` + `blend_layer_pipeline[]`. suspend → offscreen layer → resume → one full-screen composite with Ruffle's trivial blend state. |
| **F2** screen | **DONE** | Third trivial variant, `One / OneMinusSrc / Add`. |
| **F3** complex-blend shader pass | **DONE** | Backdrop made sampleable (`+CopyDst` on `filter_tex_*`, `+CopySrc` on `surf_config`, `main_color_texture` tracked per frame, `wgpuCommandEncoderCopyTextureToTexture` into `filter_tex_b` while the pass is suspended). One WGSL module with **7 fragment entry points** generated from a template (multiply, lighten, darken, difference, invert, overlay, hardlight), 7 pipelines with `blend = NULL` (== `BlendState::REPLACE`) + stencil-Equal. Formulas ported verbatim from `~/CC/ruffle/render/wgpu/shaders/blend/*.wgsl`. |
| **F4** alpha/erase no-layer skip | **DONE** | `blend_mode == 11 \|\| 12` → the draw is dropped, in all **three** display loops. Written as a guarded block so F5 can turn it into a layer-stack query. |
| **F5** layer groups (mode 2) | **SKIPPED** (as recommended) | `layer_alpha` / `layer_erase` still fail, but their excess dropped 57% as a side effect of F4 (see ledger). |
| **F6** CPU `BitmapData.draw` | **DONE** | `avm2_bitmap.c`: enum extended to 11 modes; `blend_subtract` + `blend_screen` added (trivial, premultiplied, OVER alpha); `blend_complex` switch extended with lighten/darken/difference/invert/overlay; name table extended to every non-shader mode. |
| **F7** script-set blendMode | **AVM1 DONE / AVM2 NOT DONE** | AVM1 setter now mirrors `mc->blend_mode` onto `((DisplayObject*)mc->display_obj)->blend_mode`. The AVM2 half (numeric field on `Avm2DisplayObjectExt` + layer-capable `avm2_render_node`) was **not** attempted — `avm2/displayobject_blendmode` is unchanged. |

### Extra step not in the brief — **F1b, the nested-display-list route**

The brief's F1/F3/F4 targeted `tag.c:5197` (tagRerenderFrame) and `tag.c:6152`
(tagShowFrame). **Both of those are ROOT/stage loops.** The recursive
`render_display_list()` (`tag.c:3161`) had *no* blend handling at all — and the
`visual/blend_modes` suite authors most of its blend objects **inside a sprite**
(`alpha_no_layer` places char 20 with mode 11 in `sprite_23_frame_0`; only
`add`/`multiply`/etc. put theirs on the root timeline). Without this the F4 skip
was completely inert (measured: `alpha_no_layer` unchanged at 172 259).

Added the same three cases to `render_display_list`, plus a
`g_clip_mask_capture` counter so a blend object inside a **mask sprite** does not
suspend the pass mid-stencil-capture.

---

## 2. Per-test ledger — image axis

Local Dawn reproduces CI lavapipe **byte-identically**: every pre-patch local
number below equals the CI baseline from run `30701749687` exactly (verified for
all six tests in the canary base capture — 13405 / 65601 / 94731 / 66608 / 42847
/ 172259). So these deltas are directly comparable to CI.

| test | before (excess ch.) | after | Δ | verdict |
|---|---:|---:|---|---|
| `visual/blend_modes/add` | 13 405 | **3 578** | −73% | fail → fail (band move) |
| `visual/blend_modes/subtract` | 65 601 | **4 076** | −94% | fail → fail |
| `visual/blend_modes/screen` | 94 731 | **4 568** | −95% | fail → fail |
| `visual/blend_modes/lighten` | 18 823 | **4 194** | −78% | fail → fail |
| `visual/blend_modes/multiply` | 66 608 | **8 414** | −87% | fail → fail |
| `visual/blend_modes/darken` | 42 847 | **8 035** | −81% | fail → fail |
| `visual/blend_modes/difference` | 132 923 | **5 379** | −96% | fail → fail |
| `visual/blend_modes/invert` | 141 037 | **12 680** | −91% | fail → fail |
| `visual/blend_modes/overlay` | 84 068 | **9 650** | −89% | fail → fail |
| `visual/blend_modes/hardlight` | 30 408 | **11 238** | −63% | fail → fail |
| `visual/blend_modes/overlay_onto_stage` | 41 293 | **33 894** | −18% | **fail → PASS** (limit 40 000) |
| `visual/blend_modes/alpha_no_layer` | 172 259 | **12 645** | −93% | fail → fail |
| `visual/blend_modes/erase_no_layer` | 169 082 | **12 439** | −93% | fail → fail |
| `visual/blend_modes/layer_alpha` | 172 648 | **75 364** | −56% | fail → fail (needs F5) |
| `visual/blend_modes/layer_erase` | 169 556 | **75 300** | −56% | fail → fail (needs F5) |
| `avm2/blend_transform` | 15 000 | **0** | −100% | **fail → PASS** |
| `avm2/displayobject_blendmode` | 62 400 | 62 400 | 0 | unchanged (F7-AVM2 not done) |
| `visual/blend_modes/shader_without_shader` | 0 (pass) | **0 (pass)** | — | **no regression** |
| `avm2/blend_multiply_alpha` | 0 (pass) | **0 (pass)** | — | **no regression** (canary IDENTICAL) |
| `avm2/blend_scroll` | 0 (pass) | 0 (pass) | — | no regression |

**Flips delivered: 2 of the 23 comparisons** (`overlay_onto_stage`,
`blend_transform`). **Band moves on 15 more**, most of them 80–96% of the excess
removed. This is short of the brief's "~12 flips" estimate — see §4.

## 3. Per-test ledger — trace axis

Every changed test re-verified sequentially post-patch:

| test | before | after |
|---|---|---|
| all 15 `visual/blend_modes/*` | pass | **pass** |
| `visual/blend_modes/shader_without_shader` | pass | **pass** (a `fail` seen once under `-P` load was a false fail; passes sequentially, twice) |
| `avm2/blend_multiply_alpha` (named regression guard) | pass | **pass** |
| `avm2/blend_transform` | ruffle_matched | **ruffle_matched** |
| `avm2/displayobject_blendmode` | pass | pass |
| `avm2/blend_scroll` | pass | pass |
| `regression/avm2_timeline_gradients`, `…_stroke_gradient`, `avm2_morph` | pass | **pass** |
| `visual/cache_as_bitmap/shape_changed`, `visual/simple_shapes/masks` | pass | **pass** |
| `avm1/movieclip_setmask`, `avm1/bitmapdata_applyfilter_colormatrix`, `avm1/bitmap_data_fillrect` | pass | **pass** |
| `from_shumway/acid/acid-gradient-0` | pass | **pass** |

All of the above also re-checked on the **image** axis where they carry one:
`blend_scroll`, `blend_multiply_alpha` and `shader_without_shader` all still
report `0 outliers, max difference 0`.

`grep -li blend ruffle-tests/tests/swfs/regression/*/README.md` → **no matches**;
the regression suite has no blend-specific test. The three graphics regression
tests were run anyway (all pass).

**`blend_transform` note (ruffle-matched-trap check).** Its trace TEXT changed:
`f3a6a6` → `6ca6a6`, expected `6da6a6`. Status stays `ruffle_matched`, so **not**
a regression by the `ruffle-matched-trap` rule — and it moved *towards* expected
(1 LSB off in the red channel). The image now matches the golden with **max
difference 0**, i.e. the DIFFERENCE/SUBTRACT rasters are byte-exact; the
remaining 1 LSB is the pre-existing `getPixel` un-premultiply rounding that the
test's own `known_failure` comment names ("Broken after the inaccuracy in
getPixel/getPixel32 was fixed"). Fixing that is a separate, unrelated item.

## 4. Why 2 flips and not 12 — the residual

`tolerance = 2, max_outliers = 0` on 13 of the 15 `visual/blend_modes` tests, so
a test only flips at **zero** outliers. The residual after the patch is 3.5k–12k
channels, and it is **not** an AA epsilon floor: 2 496 of `add`'s 3 578 residual
channels differ by **more than 32** (max 246).

Traced it to a concrete, **pre-existing** defect, not something this patch
introduced. Sample (`add`, row y=91):

```
 x=167  golden=(217,3,104,255)   before=(227,3,104,255)   after=(255,3,104,255)
 x=175  golden=(255,3,104,255)   before=(246,3,104,255)   after=(255,3,104,255)
```

At x=167 Flash draws **nothing** (the pixel is the untouched backdrop 217) while
we contribute ink — *and we already did before the patch* (227 ≠ 217). So the
blend object's group contains geometry Flash doesn't render there. The patch
made that pre-existing extra element more visible (a correct `add` of an opaque
layer saturates where a per-draw `SrcAlpha` add only nudged), which is why some
residuals look worse per-pixel while the totals collapse.

**Owner: a separate "extra element inside the blend group" defect**, almost
certainly the same one wave 1 saw as the "large translucent white/grey gradient
rectangle" in `alpha_no_layer` — that art is shared across the suite. It is very
likely a single mechanism worth one focused follow-on session; it currently caps
the whole `visual/blend_modes` directory below a flip.

`layer_alpha` / `layer_erase` (75k residual) additionally need **F5** layer
groups, as the brief said.

## 5. Render canary (md5 A/B)

`render_canary.py capture --label base` (pre-patch) → patch → `--label after` →
`compare base after`. 12 rows (trimmed from the standing set + the brief's
extended set: the box was saturated by 7 sibling agents and a 37-row capture was
running at ~200 s/test; the trimmed set keeps one representative of every family
the patch could touch).

```
  IDENTICAL 5   DIFFERS 7   APPEARED 0  VANISHED 0  NO_RENDER 0
```

| row | expected | actual |
|---|---|---|
| `avm2/blend_multiply_alpha` (tier 1, CI-passing) | IDENTICAL always | **IDENTICAL** ✔ F6 caused no regression |
| `avm1/mask_with_drawing` | IDENTICAL | **IDENTICAL** ✔ stencil not leaked by the new offscreen depth-stencil |
| `visual/filters/drop_shadow` | IDENTICAL | **IDENTICAL** ✔ filter path unaffected (H4) |
| `avm1/color`, `visual/simple_shapes/winding_rule` | IDENTICAL | **IDENTICAL** ✔ |
| the 7 targets (`add`, `subtract`, `screen`, `multiply`, `darken`, `alpha_no_layer`, `blend_transform`) | DIFFERS | **DIFFERS** ✔ exactly the expected set |

Only one IMAGE STATUS CHANGE: `avm2/blend_transform  fail → pass`. No trace
status changed.

**Canary coverage gap to note:** the trimmed list dropped
`avm1/edittext_tag_indent`, `avm1/focusrect_swf5`, `from_shumway/timeline/*`,
`from_shumway/acid/acid-gradient-0`, `visual/cache_as_bitmap/shape_changed`,
`visual/simple_shapes/gradients`, `regression/*`. Those were covered instead by
absolute pass/fail runs (§3) rather than md5 A/B. CI is the arbiter.

---

## 6. Design notes / risks for the merge coordinator

1. **Three loops, not two.** The blend route is duplicated in `tagShowFrame`,
   `tagRerenderFrame` and `render_display_list`. If any of these three is
   refactored, all three must keep the `blend_skip` / `blend_layered` /
   legacy triple.

2. **New `filter_depth_stencil` texture changes the FILTER path too.**
   `begin_offscreen_pass` now attaches its own MSAA depth-stencil instead of
   `depth_stencil_view`. This is strictly more correct — the offscreen pass
   *clears and discards* the stencil, which previously left the resumed main
   pass's clip mask undefined — but it is a behaviour change for filters.
   `visual/filters/drop_shadow` and `avm1/mask_with_drawing` are both IDENTICAL
   in the canary, and `avm1/bitmapdata_applyfilter_colormatrix` passes, so no
   observed effect. Watch the filter family on CI.

3. **`surf_config.usage |= CopySrc`** (browser only). If any target platform
   refuses `CopySrc` on the swapchain, surface configuration fails. The complex
   blends degrade gracefully if `main_color_texture` is NULL
   (`blend_mode_is_layered` returns 0 → legacy per-draw pipeline), but the
   surface-config change itself is unconditional. Not exercised by CI (headless).

4. **Nested blend falls back, it does not nest.** `offscreen_depth > 0` disables
   the layer route, so a blend object inside another blend object (or inside a
   filtered object) uses the legacy per-draw pipeline. Same for
   `filter_type != 0` on the same object (H4). Deliberate — nesting needs the
   texture pool that F5 also needs.

5. **`g_clip_mask_capture`** is a plain file-static counter in `tag.c`. It is
   incremented around the three `begin_clip_mask → render_display_list` sites.
   If a new mask-capture site is added, it must bump the counter or a blend
   object inside that mask will suspend the pass mid-capture.

6. **Stencil reference on the composite.** `composite_blend` takes an explicit
   `stencil_ref` (`active_clip_depth > 0 ? 1 : 0`) rather than hard-coding 0 the
   way `composite_filtered` does. That makes a blend object inside a clip mask
   clip correctly (hazard H2). `composite_filtered` was left alone.

7. **`blend_params_buf` is a separate 32-byte zero uniform**, deliberately not
   `filter_quad_buffer` — the filter path rewrites that buffer per composite
   call, which would race across multiple blend objects in one frame.

8. **F7-AVM2 is the cheapest remaining flip.** The GPU half it depends on now
   exists (`renderer_blend_mode_is_layered` / `capture_backdrop` /
   `composite_blend` are re-entrant and take an explicit stencil ref), so
   `avm2/displayobject_blendmode` needs only a numeric `blend_mode` on
   `Avm2DisplayObjectExt` and the same three-call route in `avm2_render_node`.

9. **Not in scope, unchanged:** `from_shumway/acid/acid-blend*` (compound,
   bitmap-texture-dominated), `blend_shader_luma_lighten`, `stage3d_blend`,
   `visual/blend_modes/shader_as_mask` (PixelBender `BlendType::Shader`).

10. **CI recommendation:** `mode=graphics`, `categories=all`, and a deliberate
    `images=true` run to grade the 15 band moves and confirm the 2 flips.
