# wave1-gfx-blend — mechanism diagnosis of the blend-mode slice

Session 10, wave 1 (read-only). Board regenerated this session:
`scripts/image_triage.py --images-dir <scratch>/image-results` against
`origin/ruffle-image-results` + the merged `_results/image_results_graphics.json`
stems, **provenance: run `30701749687` at `feb8882b0`** (session-9 closeout,
390 failing comparisons, 172/566 unique passing). Board JSON:
`<scratch>/board.json`, markdown `<scratch>/board.md`.

**Headline:** the slice is not a set of near-misses around a working blend
engine. It is three separable gaps: (1) **10 of 14 SWF blend modes are not
implemented at all** — `render_webgpu_set_blend_mode`'s `default:` arm silently
falls back to the normal pipeline; (2) the 4 that *are* implemented are applied
**per draw call against the live backdrop** instead of Flash's
**render-the-object-to-a-layer-then-composite-once** model, so an object's own
overlapping sub-shapes compound; (3) **AVM2 `blendMode` never reaches the
renderer at all** (it is stored as a dynamic string property only), and AVM1
`mc.blendMode` never syncs from `MovieClip.blend_mode` to
`DisplayObject.blend_mode`. Only PlaceObject3-authored blend modes reach pixels.

Two additional *bugs* (not gaps) in the 4 implemented modes destroy the
destination alpha channel: `subtract` and `darken` produce non-opaque output
where Flash/Ruffle produce alpha 255 (measured, §3.2).

Local Dawn reproduced CI lavapipe **byte-identically** for
`visual/blend_modes/subtract` (`maxdiff 0` over the full 550×400 RGBA), so the
render canary will be a high-fidelity A/B instrument for this whole slice.

---

## (a) Exact slice membership

23 failing comparisons across 6 tests carry `family == "Blend modes"`
(19 in `same_geometry_wrong_fill`, 4 adjacent in `halo_penumbra`/`diffuse_mixed`
— this is exactly the "19 + 4 adjacent" the playbook named). Plus 3 shader-blend
comparisons that belong to the Stage3D/PixelBender arc, listed separately.

### Core slice — `visual/blend_modes` (15 comparisons, one per test)

| test (suite `visual`) | cmp | band | excess ch. | %chan | mode id | status |
|---|---|---|---|---|---|---|
| `blend_modes/add` | output | d_moderate | 13 405 | 1.52% | 8 | implemented, per-draw |
| `blend_modes/subtract` | output | d_moderate | 65 601 | 7.45% | 9 | implemented, **alpha bug** |
| `blend_modes/lighten` | output | d_moderate | 18 823 | 2.14% | 5 | implemented, wrong model |
| `blend_modes/darken` | output | d_moderate | 42 847 | 4.87% | 6 | implemented, **alpha bug** |
| `blend_modes/multiply` | output | d_moderate | 66 608 | 7.57% | 3 | **not implemented** |
| `blend_modes/screen` | output | e_large | 94 731 | 10.76% | 4 | **not implemented** |
| `blend_modes/difference` | output | e_large | 132 923 | 15.10% | 7 | **not implemented** |
| `blend_modes/invert` | output | e_large | 141 037 | 16.03% | 10 | **not implemented** |
| `blend_modes/overlay` | output | d_moderate | 84 068 | 9.55% | 13 | **not implemented** |
| `blend_modes/overlay_onto_stage` | output | d_moderate | 41 293 | 4.69% | 13 | **not implemented** |
| `blend_modes/hardlight` | output | d_moderate | 30 408 | 3.46% | 14 | **not implemented** |
| `blend_modes/alpha_no_layer` | output | e_large | 172 259 | 19.57% | 11 | **must be SKIPPED** |
| `blend_modes/erase_no_layer` | output | e_large | 169 082 | 19.21% | 12 | **must be SKIPPED** |
| `blend_modes/layer_alpha` | output | e_large | 172 648 | 19.62% | 2+11 | needs layer groups |
| `blend_modes/layer_erase` | output | e_large | 169 556 | 19.27% | 2+12 | needs layer groups |

All 15 are `same_geometry_wrong_fill`. `test.toml` for every one: `num_frames = 1`,
`tolerance = 2` (no `max_outliers` → 0), `quality = "low"`, 550×400.
`visual/blend_modes/shader_without_shader` **passes** — the only passing member
of the directory; `shader_as_mask` fails under the Stage3D family.

### `from_shumway/acid` (6 comparisons, 2 tests) — COMPOUND, see §3.4

| test | cmp | cluster | band | excess |
|---|---|---|---|---|
| `acid/acid-blend` | output | same_geometry_wrong_fill | d_moderate | 77 416 |
| `acid/acid-blend-2` | output.10 | same_geometry_wrong_fill | d_moderate | 14 912 |
| `acid/acid-blend-2` | output.15 | diffuse_mixed | d_moderate | 27 200 |
| `acid/acid-blend-2` | output.20 | halo_penumbra | d_moderate | 42 028 |
| `acid/acid-blend-2` | output.26 | halo_penumbra | d_moderate | 55 886 |
| `acid/acid-blend-2` | output.40 | diffuse_mixed | d_moderate | 27 599 |

AVM1 (no `RecompiledABC`), SWF v21, generous tolerances (20 / 130-160 tiers).

### `avm2` (2 comparisons)

| test | band | excess | mechanism |
|---|---|---|---|
| `avm2/displayobject_blendmode` | e_large | 62 400 (39.0% of a 200×200) | AVM2 blendMode is a no-op on pixels |
| `avm2/blend_transform` | d_moderate | 15 000 | `BitmapData.draw` CPU path missing DIFFERENCE + SUBTRACT |

Both carry the **soft** `[trace-ign]` flag (suite-local `avm2/ignored_tests.txt`
lines 156–157, the pre-implementation trace-axis worklist — not a pixel
disposition). `blend_transform/test.toml` also has `known_failure = true` and
`tolerance = 0`; its trace status is `ruffle_matched`, so per the
`ruffle-matched-trap` rule a trace flip there is a regression signal, not a win.

**Dispositions:** none of the 23 comparisons is hard-dispositioned. Nothing in
the global `ruffle-tests/ignored_tests.txt`, nothing in any `ACCEPTED_DIFFS.md`
/ `RUFFLE_VS_FLASH_DIFFERENCES.md` (grep for "blend" only hits MSAA prose). The
whole slice is live work.

### Adjacent, NOT this slice (PixelBender / Stage3D arc)

`avm2/blend_shader_luma_lighten` (same_geometry_wrong_fill, c_small),
`avm2/stage3d_blend` (blank_render, e_large),
`visual/blend_modes/shader_as_mask` (halo_penumbra, f_catastrophic).
These need `BlendType::Shader` (a PixelBender program as the blend op) — a
different backend. Do not scope them into wave 2.

### Currently-PASSING blend comparisons = regression risk

- `avm2/blend_multiply_alpha` — **passes**, `BitmapData.draw(..., "multiply")`,
  CPU path. Already tier-1 in `ruffle-tests/render_canary_tests.txt`. Any change
  to `blend_mode_apply()` must keep it green.
- `avm2/blend_scroll` — passes, does not use blend modes (name only).
- `visual/blend_modes/shader_without_shader` — passes (asserts the *absence* of
  a shader blend); must not start compositing.

---

## (b) Per-mode implementation status

Oracle: `~/CC/ruffle/render/wgpu/src/blend.rs` (mode → Trivial/Complex),
`~/CC/ruffle/render/wgpu/shaders/blend/*.wgsl` (the 9 complex formulas),
`~/CC/ruffle/render/wgpu/src/surface/commands.rs:679-790` (every non-normal mode
renders its subtree into a **fresh transparent Rgba8Unorm surface** first),
`~/CC/ruffle/render/wgpu/src/surface.rs:233-340` (complex pass samples
`parent_blend_buffer` + `current`, pipeline blend state `BlendState::REPLACE`).

### GPU renderer — `SWFModernRuntime/src/rendering/render_webgpu.c`

Dispatch: `render_webgpu_set_blend_mode()` — **`render_webgpu.c:2533-2546`**.
Call sites: `SWFModernRuntime/src/libswf/tag.c:5197/5245/5250` (stage display
list) and `tag.c:6152/6227/6236` (sprite display list), gated on
`obj->blend_mode > 1`.

| id | mode | Ruffle class | ours | file:line | verdict |
|---|---|---|---|---|---|
| 0/1 | normal | Trivial Normal | `render_pipeline` (SrcAlpha/1-SrcA colour, One/1-SrcA alpha) | `render_webgpu.c:1366-1419` | OK — equivalent to premultiplied OVER for straight-alpha src |
| 2 | layer | Trivial Normal **+ establishes a layer** | `default:` → normal, no layer | `render_webgpu.c:2543` | **missing layer group** |
| 3 | multiply | Complex | `default:` → normal | `render_webgpu.c:2543` | **NOT IMPLEMENTED** |
| 4 | screen | **Trivial** (One / OneMinusSrc) | `default:` → normal | `render_webgpu.c:2543` | **NOT IMPLEMENTED (cheapest)** |
| 5 | lighten | Complex (Ruffle: *"might be trivial but I can't reproduce the right colors"*) | `blend_lighten_pipeline` One/One/**Max**, alpha One/One/Max | `render_webgpu.c:1481-1499` | wrong model — hardware max on premultiplied data ≠ Flash `max` on un-premultiplied inside the layer formula |
| 6 | darken | Complex | `blend_darken_pipeline` One/One/**Min**, alpha One/One/Min | `render_webgpu.c:1502-1520` | wrong model **+ alpha bug**: `Min` on alpha punches holes at AA edges |
| 7 | difference | Complex (`abs(dst-src)`) | `default:` → normal | `render_webgpu.c:2543` | **NOT IMPLEMENTED** |
| 8 | add | **Trivial** (One/One Add colour, **OVER alpha**) | `blend_add_pipeline` SrcAlpha/One Add colour (== Ruffle for straight src), alpha **One/One Add** | `render_webgpu.c:1460-1478` | colour OK; alpha saturates instead of OVER; **applied per draw, not per layer** |
| 9 | subtract | **Trivial** (One/One ReverseSubtract colour, **OVER alpha**) | `blend_subtract_pipeline` SrcAlpha/One RevSub colour (== Ruffle), alpha **SrcAlpha/One ReverseSubtract** | `render_webgpu.c:1523-1541` | colour OK; **alpha bug: `dst.a − src.a` → 0 over an opaque backdrop** |
| 10 | invert | Complex (`1-dst`) | `default:` → normal | `render_webgpu.c:2543` | **NOT IMPLEMENTED** |
| 11 | alpha | Complex, **needs a Layer above it; with none the draw is DISCARDED** (`surface.rs:241-244` `continue`) | `default:` → normal, object drawn | `render_webgpu.c:2543` | **NOT IMPLEMENTED; wrong even in the trivial no-layer case** |
| 12 | erase | Complex, same layer rule | `default:` → normal, object drawn | `render_webgpu.c:2543` | same |
| 13 | overlay | Complex (branch on **dst**) | `default:` → normal | `render_webgpu.c:2543` | **NOT IMPLEMENTED** |
| 14 | hardlight | Complex (branch on **src**) | `default:` → normal | `render_webgpu.c:2543` | **NOT IMPLEMENTED** |

**Compositing stage — the structural gap.** Flash/Ruffle blend a display
object's *whole rendered subtree* against the backdrop **once**. We set a
pipeline and then issue every one of the object's draws against the live target,
so the object's own overlapping geometry blends with itself. Confirmed visually
on `add` (§3.1). There is **no backdrop-sampling path** anywhere in the
renderer today.

**But the scaffold for one already exists** (built for filters):
- `render_webgpu_suspend_pass` / `resume_pass` — `render_webgpu.c:3251-3293`
  (suspend resolves MSAA into `surface_view`/`offscreen_view`; resume reloads
  with `loadOp=Load` and preserves the stencil)
- `render_webgpu_begin_offscreen_pass` / `end_offscreen_pass` —
  `render_webgpu.c:3295-3344`: renders into `filter_msaa_view` resolving to
  `filter_view_a`, cleared to `(0,0,0,0)`. **Because the main pipeline is
  SrcAlpha/OneMinusSrcAlpha over a transparent clear, `filter_tex_a` comes out
  correctly PREMULTIPLIED** — exactly Ruffle's layer texture.
- `render_webgpu_composite_filtered` + `composite_pipeline` —
  `render_webgpu.c:3446-3484`, shader at `:3018-3049`, pipeline at `:3196-3237`:
  a full-screen quad, premultiplied OVER, **MSAA 4×, stencil-test-equal**
  (`ds.stencilFront.compare = Equal`, write mask 0). This is the exact shape a
  blend composite needs.
- `filter_tex_b` / `filter_view_b` (`render_webgpu.c:3067-3074`) exists as a
  blur ping-pong buffer and is free for use as the **parent blend buffer**.
- The consumer, `tag.c:5199-5246`, already does
  suspend → offscreen → render_single_object → end → resume → composite for
  filters, including sprites and Drawing-API content.

**Backdrop-sampling plumbing gap (must be fixed before any complex blend):**
the main colour target is **not sampleable**. Headless: `offscreen_texture`
usage is `RenderAttachment | CopySrc` (`render_webgpu.c:884`) — no
`TextureBinding`. Browser: `surf_config.usage = RenderAttachment` only
(`render_webgpu.c:908`) — no `CopySrc` either. Cheapest fix: add
`WGPUTextureUsage_CopyDst` to the `filter_tex_*` descriptor
(`render_webgpu.c:3065`), add `CopySrc` to `surf_config.usage`, and
`wgpuCommandEncoderCopyTextureToTexture(main → filter_tex_b)` while the pass is
suspended (formats already match: both `ctx->surface_format`).

### AVM1 script path

- `MovieClip.blend_mode` field — `SWFModernRuntime/include/actionmodern/action.h:53`
- setter — `action.c:49477-49517` (string table + numeric, correct 0..14 mapping)
- getter — `action.c:53355-53361`
- **Never propagated to `DisplayObject.blend_mode`.** `display_list[d].blend_mode`
  is written only by `tagPlaceObject3` (`tag.c:10568-10571`) and reset to 0 at
  `tag.c:8217` / `tag.c:8800`. `mc->display_obj` exists (`action.h:65`) but is
  not used for blend. So `mc.blendMode = "multiply"` is a pixel no-op.

### AVM2 path

- Property is stored as a **dynamic string** `__blendMode`:
  `avm2_display.c:10080-10121` (`do_blendmode_get`/`do_blendmode_set`); the
  AVM2 timeline PlaceObject3 op writes the same string via
  `set_blend_mode_name` (`avm2_display.c:1646`, called at `:1685` from the
  `op->blend_mode` numeric id parsed by `SWFRecomp/src/abc/abc_timeline.cpp:1024-1027`).
- The AVM2 draw walk is `avm2_render_walk` → `avm2_render_node`
  (`avm2_display.c:14341-14406`). It calls `renderer_draw_shape` /
  `renderer_draw_tris` / `renderer_draw_bitmap_quad_scaled` / `renderer_draw_rect`
  and **never `renderer_set_blend_mode`**. There is no numeric blend field on
  `Avm2DisplayObjectExt`. AVM2 blendMode has zero pixel effect.

### CPU raster path (`BitmapData.draw` / `copyPixels`)

`SWFModernRuntime/src/avm2/avm2_bitmap.c`:
- `enum { BM_NORMAL, BM_MULTIPLY, BM_HARDLIGHT, BM_ADD }` — `:124`
- `blend_add` `:128-135`, `blend_complex` (multiply/hardlight) `:146-177`,
  `blend_mode_apply` `:181-185` — the formulas are already **exact ports of
  Ruffle's wgsl**, including the `src.a==0 → discard`, `dst.a==0 → src`
  special cases.
- Mode-name parse — `:2187-2197`: only `multiply`, `hardlight`, `add`. Every
  other name silently degrades to `BM_NORMAL`.
- Consumers `:1951`, `:2334`, `:2398`.

Missing: `difference`, `subtract`, `screen`, `lighten`, `darken`, `invert`,
`overlay`, `alpha`, `erase`, `layer`. Each is 1–3 lines of `blend_func` in the
existing `blend_complex` skeleton (Ruffle's `subtract`/`screen`/`add` are
"trivial" only because they map to hardware — as CPU code they are one-liners on
premultiplied values).

---

## (c) Per-representative-test diagnosis

Method note: renders below are the **CI actual PNGs** from
`origin/ruffle-image-results` compared against the goldens in the gitignored
test dirs; no local render was graded against a golden. One local run
(`visual/blend_modes/subtract --mode=graphics --images`) was made only to
establish local↔CI determinism.

### 3.1 `visual/blend_modes/add` — the layer-model proof (13 405 ch., 1.52%)

Structurally near-correct: the whole "ruffle" wordmark over the 5×5 colour grid
is additively blended and most cells match. The failure is a **larger blown-out
white region in the lower middle** than expected. The wordmark is a multi-shape
group; Flash composites the group into a layer (normal-over within the group)
and adds the result once, so an overlap inside the wordmark contributes its
colour **once**. We add every sub-shape separately, so overlaps add twice and
clip to white. Diff profile confirms it is not AA: 8 366 pixels over tolerance,
**5 464 of them differ by >32 and 1 654 by >128** (max 255).

**Owner: gap (2), per-draw instead of per-layer.** Same signature on
`lighten` (12 457 px over tol, 8 722 > 32) and `subtract` (8 768 / 6 346).

### 3.2 `visual/blend_modes/subtract` + `darken` — alpha-channel destruction

Measured on the CI actual vs golden:

| test | actual alpha min | actual distinct alphas | expected alpha |
|---|---|---|---|
| subtract | **0** | 217 | 255 (single value) |
| darken | **0** | 186 | 255 (single value) |
| add / lighten / all others | 255 | 1 | 255 |

Cause is exactly the blend state:
- subtract (`render_webgpu.c:1529-1531`) sets the **alpha** component to
  `SrcAlpha / One / ReverseSubtract` → `a = dst.a·1 − src.a·src.a`; over an
  opaque backdrop with an opaque source that is `1 − 1 = 0`. The wordmark
  renders as a fully transparent hole (it reads as white in a viewer).
  Ruffle uses `BlendComponent::OVER` for alpha on Subtract.
- darken (`:1508-1510`) sets alpha to `One/One/**Min**` → `min(src.a, dst.a)`;
  fine in the interior, but AA edge fragments (`src.a < 1`) punch partial
  transparency into an opaque backdrop.

**Owner: bug, 4-line fix** — alpha component must be `One / OneMinusSrcAlpha /
Add` (OVER) on every blend pipeline. Independent of everything else and the
single cheapest correctness win in the slice.

### 3.3 `visual/blend_modes/multiply` — clean fallback-to-normal (66 608 ch.)

Golden: the wordmark multiplied into the grid (dark, tinted per cell).
Ours: the wordmark drawn opaque red/green/blue exactly as `normal` would.
Geometry identical, ink IoU high, fill wrong — textbook `same_geometry_wrong_fill`.
`screen`, `difference`, `invert`, `overlay`, `overlay_onto_stage`, `hardlight`
are the same picture (their mean |Δ| ranges 1.9–29.3; `hardlight`'s low 1.88
mean is content luck, its outlier count is still 30 408).

**Owner: gap (1), `render_webgpu.c:2543` `default:` arm.**

### 3.4 `visual/blend_modes/alpha_no_layer` (172 259 ch.) — an *extra* element

Golden: the grid + wordmark, and **no sign of the alpha-mode object at all**.
Ours: a large translucent white/grey gradient rectangle painted over the middle
of the stage. Ruffle: `ComplexBlend::Alpha | Erase` with `LayerRef::None`
`continue`s — *"An Alpha or Erase with no Layer above it should be ignored"*
(`~/CC/ruffle/render/wgpu/src/surface.rs:239-244`). We draw it normally.
`erase_no_layer` is the identical picture (169 082 ch.).

`layer_alpha` / `layer_erase` are the same source art wrapped in a
`blendMode="layer"` parent; their goldens show the rectangle acting as an
alpha/erase stencil that *removes* part of the wordmark. **Our actual for
`layer_alpha` is byte-identical in structure to `alpha_no_layer`'s** — we
neither skip nor composite.

**Owner: split.** The two `*_no_layer` tests are a **3-line skip**; the two
`layer_*` tests need real layer groups.

### 3.5 `avm2/displayobject_blendmode` (62 400 ch., 39% of a 200×200)

Golden: bright magenta/purple quadrants with a yellow and a pink inset.
Ours: same geometry, uniformly much darker. Nothing in `avm2_render_node`
consults `__blendMode`, so the intended lighten/screen-ish results collapse to
plain alpha-over stacking.

**Owner: gap (3), AVM2 blend never reaches the renderer.** Blocked on the GPU
work; the AVM2 side additionally needs a numeric blend field on
`Avm2DisplayObjectExt` and a layer-capable `avm2_render_node`.

### 3.6 `avm2/blend_transform` (15 000 ch.) — CPU path, independent

`ruffle-tests/tests/swfs/avm2/blend_transform/Test.as` does exactly two things:
`data.draw(secondData, null, null, BlendMode.DIFFERENCE)` and
`data.draw(secondData, null, null, BlendMode.SUBTRACT)`. Both names fall through
`avm2_bitmap.c:2195-2197` to `BM_NORMAL`. `tolerance = 0`.

**Owner: CPU `blend_mode_apply` coverage.** Self-contained; no GPU work needed.

### 3.7 `from_shumway/acid/acid-blend*` (6 cmps) — COMPOUND, do not price as blend

`acid-blend-2 output.10`: the golden shows two textured blue ellipses plus a red
circle pair with a yellow overlap lens. Ours renders **grey horizontal scanline
stripes in a mispositioned rectangle** where the noise texture belongs, and the
circles come out flat cyan. The cyan→red delta *is* a blend gap (`difference` of
cyan over white = red, and the yellow lens is the layer semantics), but the
dominant excess is a **bitmap-texture decode/placement failure** unrelated to
blending. `acid-blend` (single frame) is the same story: flat blue ellipses
where the golden is textured.

**Expectation: band moves, not flips.** Wave 2 should not put these in an
expected-flip ledger. Their real owner belongs in the Shumway-acid slice.

---

## (d) Wave-2 implementation brief

All work is in `SWFModernRuntime/` (runtime-only) except nothing — **no
`SWFRecomp/` change is needed**; the recompiler already parses and emits
PlaceObject3 blend modes (`SWFRecomp/src/swf.cpp:4195-4397` stage,
`:5571-5725` sprite; `SWFRecomp/src/abc/abc_timeline.cpp:1024-1027` AVM2). That
means the worktree can copy `SWFRecomp/build` from the main tree and skip
`--recompile` (playbook §5), and the canary's false-negative mode 11 (stale
recompiler) does not apply.

Ordered so each step is independently shippable and canary-checkable.

### F0 — Alpha-component fix on the existing blend pipelines · **XS** · yield 0–2

Set `blend.alpha = {One, OneMinusSrcAlpha, Add}` (Ruffle's `BlendComponent::OVER`)
on `blend_add_pipeline`, `blend_lighten_pipeline`, `blend_darken_pipeline`,
`blend_subtract_pipeline` (`render_webgpu.c:1466-1468, 1487-1489, 1508-1510,
1529-1531`).
Yield: removes the alpha holes in `subtract` and `darken` (their 217/186
distinct alpha values collapse to 1). Probably **not enough to flip either**
(both also carry the F1 layer error), but it is a prerequisite and a clean
band move. Do it first so its canary signature is unambiguous.
Canary: `visual/blend_modes/multiply` (tier 2) must stay IDENTICAL (multiply is
not one of the four); every tier-1 row must stay IDENTICAL.

### F1 — Layer-first compositing for add / subtract · **M** · yield 2

Reuse the filter scaffold in `tag.c:5197-5251`: for `blend_mode ∈ {8,9}`,
`suspend_pass` → `begin_offscreen_pass` → `render_single_object` →
`end_offscreen_pass` → `resume_pass` → new
`render_webgpu_composite_blend(ctx, mode)` that draws the `composite_pipeline`
full-screen quad sampling `filter_view_a` with the trivial blend state for that
mode (needs 2 extra pipeline variants of `composite_pipeline`, differing only in
`WGPUBlendState`; keep its MSAA-4×/stencil-Equal depth-stencil).
Because the layer texture is premultiplied, use Ruffle's states verbatim:
Add `{One, One, Add}` colour + OVER alpha; Subtract `{One, One, ReverseSubtract}`
colour + OVER alpha (`~/CC/ruffle/render/wgpu/src/blend.rs:76-105`).
Expected flips: `visual/blend_modes/add`, `visual/blend_modes/subtract`.
This also incidentally fixes the "bitmap child resets the blend pipeline" hazard
(H1 below) for these modes.

### F2 — Screen as a trivial layer composite · **XS on top of F1** · yield 1

One more composite variant: `{One, OneMinusSrc, Add}` colour + OVER alpha
(`blend.rs:87-93`). Expected flip: `visual/blend_modes/screen` (94 731 ch.,
e_large → pass). Highest yield-per-line in the slice.

### F3 — The complex-blend shader pass · **L** · yield 5–7

The one real build. Steps:
1. Make the backdrop sampleable: `+WGPUTextureUsage_CopyDst` on the
   `filter_tex_*` descriptor (`render_webgpu.c:3065`), `+WGPUTextureUsage_CopySrc`
   on `surf_config.usage` (`:908`), and a
   `wgpuCommandEncoderCopyTextureToTexture(main colour → filter_tex_b)` issued
   while the pass is suspended (the resolve has already happened at that point —
   this is exactly why the filter path works).
2. One WGSL module with 7 fragment entry points, ported **verbatim** from
   `~/CC/ruffle/render/wgpu/shaders/blend/{multiply,lighten,darken,difference,invert,overlay,hardlight}.wgsl`.
   All share the body
   `src.rgb*(1-dst.a) + dst.rgb*(1-src.a) + src.a*dst.a*B(src.rgb/src.a, dst.rgb/dst.a)`,
   alpha `src.a + dst.a*(1-src.a)`, and **`discard` when `src.a == 0`**.
   Multiply alone adds the `dst.a == 0 → return src` special case.
   `blend_complex()` in `avm2_bitmap.c:146-177` is an already-validated C port of
   the same formula — use it to cross-check the WGSL.
3. 7 pipelines with `BlendState::REPLACE` (Ruffle `pipelines.rs:145`) plus the
   existing stencil-Equal depth-stencil, bind group `{parent_tex, current_tex,
   sampler}`. `discard` is what keeps REPLACE from erasing the frame outside the
   object.
4. Route ids 3, 5, 6, 7, 10, 13, 14 through it from `tag.c`.
Expected flips: `multiply`, `difference`, `invert`, `overlay`,
`overlay_onto_stage`, `hardlight`, and **`lighten` + `darken` move off the
hardware Max/Min onto the correct model** (Ruffle explicitly rejected the
hardware form). Call it **5 confident + 2 likely**.
Risk: `tolerance = 2` with `max_outliers = 0` is unforgiving — a correct formula
can still leave AA-edge outliers. If a test lands in `a_epsilon`/`b_tiny`
afterwards, that is the lavapipe-AA floor, not a failed fix; record the band
move and move on.

### F4 — Alpha/Erase with no layer: skip the draw · **XS** · yield 2

In `tag.c`'s two display-list loops, before rendering: if
`obj->blend_mode == 11 || obj->blend_mode == 12` **and no layer is active**,
`continue` (Ruffle `surface.rs:241-244`). With no layer support at all, "no
layer active" is unconditionally true — so this is literally a 3-line guard in
each of `tag.c:5197` and `tag.c:6152`. Expected flips:
`visual/blend_modes/alpha_no_layer`, `visual/blend_modes/erase_no_layer`
(172 259 + 169 082 excess channels — the two biggest single wins available).
**Must be written so F5 can turn the condition into a real layer-stack query.**

### F5 — Layer groups (mode 2) + alpha/erase against a layer · **L** · yield 2

Needs a layer stack: `blend_mode == 2` opens a nested layer surface that
subsequent siblings' alpha/erase composite against (Ruffle: `target_layer =
LayerRef::Current`, `commands.rs:688-691`; the alpha/erase pass then picks
`LayerRef::Parent(layer)` rather than the frame target). With only one spare
offscreen texture today this needs a small texture pool. Expected flips:
`layer_alpha`, `layer_erase`. **Recommend deferring to a follow-on session** —
it is the only item here that is arc-shaped rather than sweep-shaped.

### F6 — CPU `BitmapData.draw` blend coverage · **S**, fully independent · yield 1

In `avm2_bitmap.c`: extend the enum at `:124`, add the missing `blend_func`
branches to `blend_complex` (`:146-177`), and extend the name table at
`:2195-2197` to all 14 names. Port the formulas from the same Ruffle wgsl files;
`subtract`/`screen`/`add` are one-liners on premultiplied values
(`sub: max(dst−src,0)`, `screen: src + dst·(1−src)`), the rest reuse the
existing `blend_complex` skeleton.
Expected flip: `avm2/blend_transform` (needs DIFFERENCE + SUBTRACT; note
`tolerance = 0` and `known_failure = true` — a trace flip there is a
`ruffle_matched` regression signal, watch it).
**Regression guard: `avm2/blend_multiply_alpha` currently PASSES** through this
exact code and is tier-1 in the canary.

### F7 — Plumb script-set blendMode into the renderer · **S (AVM1) / M (AVM2)** · yield 1

- AVM1: mirror `mc->blend_mode` into `((DisplayObject*)mc->display_obj)->blend_mode`
  in the setter at `action.c:49485/49498/49511`. No failing test in this slice
  needs it, but every script-driven blend in real content is currently dead.
- AVM2: add a numeric `blend_mode` to `Avm2DisplayObjectExt`, set it in
  `do_blendmode_set` (`avm2_display.c:10088`) and `set_blend_mode_name`
  (`:1646`), and honour it in `avm2_render_node` (`avm2_display.c:14341`) via the
  same layer route F1/F3 build. Expected flip: `avm2/displayobject_blendmode`.
  Do this **after** F3 — the AVM2 walk has no suspend/resume discipline of its
  own and will need the composite helper to be re-entrant.

### Not in scope

`acid-blend`, `acid-blend-2` ×5 (compound, bitmap-texture-dominated — expect
band moves only, no ledger entries); `blend_shader_luma_lighten`,
`stage3d_blend`, `shader_as_mask` (PixelBender `BlendType::Shader`).

### Hazards to carry into the patch

- **H1 — bitmap draws clobber the active blend pipeline.**
  `render_webgpu.c:2355/2358` and `:2502` set `blend_premul_pipeline` and then
  unconditionally restore `render_pipeline`. Any bitmap inside a blend-mode
  object silently resets the mode mid-object. F1/F3's layer route makes this
  moot for the layer's *outer* composite, but the inner offscreen pass still
  needs the restore to be to whatever was active.
- **H2 — blend pipelines ignore clip masks.** All four are built with
  `ds_normal` (`render_webgpu.c:1457`, stencil `Always`, read mask 0xFF but
  compare-always), so a blend-mode object inside a mask escapes the stencil.
  The `composite_pipeline` already uses stencil `Equal` (`:3219`) — keep that on
  every new composite variant and the problem disappears with F1/F3.
- **H3 — `renderer_set_blend_mode(ctx, 0)` resets to `render_pipeline`**
  (`tag.c:5250`, `:6236`), discarding an active `stencil_test_pipeline`.
  Pre-existing; do not make it worse.
- **H4 — filter + blend on the same object** both want `filter_tex_a`.
  `tag.c:5199-5246` already interleaves them; F1/F3 must nest correctly or
  explicitly bail to the current behaviour when `filter_type != 0`.
- **H5 — worktree rules** (playbook §5): copy the whole test dirs
  `ruffle-tests/tests/swfs/visual/blend_modes/*` and
  `ruffle-tests/tests/swfs/avm2/{blend_transform,displayobject_blendmode,blend_multiply_alpha}`
  into the worktree at their canonical suite paths, copy `SWFRecomp/build` from
  the main tree (runtime-only patch → no cmake rebuild, no `--recompile`), and
  export `DAWN_INSTALL=~/CC/dawn-install` for raw `verify_output.py` runs.

### What the render canary must show

`ruffle-tests/render_canary.py capture --label before` → patch →
`capture --label after` → `compare before after`. Bar is **md5 equality**
(playbook §6).

| canary row | expected |
|---|---|
| all 14 tier-1 rows **except** `avm2/blend_multiply_alpha` | **IDENTICAL** for F0–F5, F7-AVM1 |
| `avm2/blend_multiply_alpha` (tier 1) | **IDENTICAL** always — it passes today; a DIFFERS on F6 is a regression, full stop |
| `visual/blend_modes/multiply` (tier 2) | IDENTICAL for F0/F1/F2/F4/F6; **DIFFERS for F3** (that DIFFERS is the fix working — canary false-positive mode 9) |
| `visual/simple_shapes/masks`, `visual/filters/*` (tier 2) | IDENTICAL — if H2/H4 are handled. A DIFFERS here means the blend patch leaked into the stencil or filter paths and must be explained before merge |

Wave 2 should additionally capture an **extended local set** (not in the
standing file) of all 15 `visual/blend_modes/*` + the 3 avm2 blend tests, and
assert that exactly the tests named in that step's ledger DIFFER. Every one of
those 15 fails on CI today, so a local DIFFERS carries no absolute verdict —
only CI's `images=true` closeout run grades them.

### Expected-flip ledger to hand the coordinator

| step | expected flips (fail→pass) | expected band moves only |
|---|---|---|
| F0 | — | subtract, darken (alpha channel clean) |
| F1 | add, subtract | — |
| F2 | screen | — |
| F3 | multiply, difference, invert, overlay, overlay_onto_stage, hardlight (+ lighten, darken likely) | acid-blend, acid-blend-2 ×5 |
| F4 | alpha_no_layer, erase_no_layer | — |
| F5 (defer) | layer_alpha, layer_erase | — |
| F6 | blend_transform | — |
| F7 | displayobject_blendmode | — |

**Realistic single-session target (F0+F1+F2+F3+F4+F6): 12 comparisons of the 23,
including both e_large `*_no_layer` wins.** F5 + F7 add 3 more in a follow-on.
