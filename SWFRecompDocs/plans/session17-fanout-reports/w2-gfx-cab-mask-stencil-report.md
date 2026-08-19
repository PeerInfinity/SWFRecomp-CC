# w2-gfx-cab-mask-stencil — session 17, wave 2 follow-up (PIXEL axis)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a2131d09969d10175`
Base `6d2b64fa2` (master + the 14 merged s17 patches). Grading baseline of
record: CI run `31877239992` at `aeebf9ede`.
Brief of record: `wave1-gfx-board.md` §P3 + `wave1-gfx-board.leads.json` P3,
plus the two sibling reports it names (`w2-gfx-cab-pixelsnap-report.md` §1/§8,
`w2-gfx-filters-cut2-report.md` §1).
No commits, no pushes, no main-tree source edits.

---

## 0. NEW FILES CREATED BY THIS PATCH — **NONE**

`w2-gfx-cab-mask-stencil.patch` touches four **tracked** files, creates none,
deletes none. The coordinator can stage by name:

| file | +/- | what |
|---|---|---|
| `SWFModernRuntime/include/rendering/render_webgpu.h` | +16 | two **trailing** `WebGPURenderContext` pipeline fields (`blend_premul_stencil_pipeline`, `alpha_mask_pipeline`) |
| `SWFModernRuntime/include/rendering/renderer.h` | +3 | `renderer_composite_alpha_mask` (WebGPU arm + `((void)0)` twin) |
| `SWFModernRuntime/src/rendering/render_webgpu.c` | +189/-6 | premul stencil pipeline; `bind_premul_pipeline`; mask-capture arm in `restore_draw_pipeline`; `alpha_mask_pipeline` + its WGSL + `render_webgpu_composite_alpha_mask`; the bitmap cxform alpha guard in `fs_main` |
| `SWFModernRuntime/src/avm2/avm2_display.c` | +127/-2 | `avm2_is_bitmap_cached`, `avm2_render_alpha_masked`, three hooks in `avm2_render_node` |

**329 inserted, 6 deleted. Runtime-only** — no `SWFRecomp/` change, so no
recompiler rebuild and no `--recompile` needed on merge. `render_stub.c` needs
no twin (the one new public symbol is macro-stubbed in `renderer.h`'s no-GPU
arm). All new file-scope symbols are `static` except
`render_webgpu_composite_alpha_mask`.

**Sibling overlap:** `render_webgpu.c` is also named by `w2-gfx-filters-cut2`
(landed) and by any later filter work; every hunk here is in a *different*
function (`restore_draw_pipeline`, the premul-pipeline creation block, the
compose-pipeline creation block's tail, a new function after
`render_webgpu_compose_filter`, and `fs_main`'s last line).
`avm2_display.c` hunks are all in the render-walk region (`avm2_render_node`
and one new function above it) — not the gfx / filters / transform / hit-test
regions the file map assigns to siblings.

---

## 1. Verdicts

| item | verdict | measured |
|---|---|---|
| **P3's four rows, "one mechanism"** | **REFUTED — it is TWO**, and both are now implemented | see §2 |
| **`visual/cache_as_bitmap/cab_mask_alpha`** | **GO, FLIPS** | 4 644 -> **PASS, 0 outliers** (max diff 2 vs tolerance 2) |
| **`visual/cache_as_bitmap/cab_mask_transform`** | **GO, FLIPS** | 2 340 -> **PASS, 0 outliers** (max diff 2) |
| **`visual/cache_as_bitmap/cab_mask_triangle`** | **GO, FLIPS** | 5 280 -> **PASS, 0 outliers** (max diff 32 vs the `tolerance 35 / max_outliers 0` check) |
| **`visual/cache_as_bitmap/oversize/swf_9_masks`** (adjacent, s16 P7, **unpriced**) | **GO, FLIPS** | 119 943 -> **PASS, 132 outliers** (limit 200) |
| **`visual/cache_as_bitmap/oversize/swf_10_masks`** (adjacent, s16 P7, **unpriced**) | **GO, FLIPS** | 119 943 -> **PASS, 132 outliers** (limit 200) |
| **`visual/cache_as_bitmap/cab_mask_filters`** | **NO-GO as a flip** (band move) | 4 968 -> **612** (-87.7 %); residual is one named, measured mechanism (§5) |
| **Canary / collateral** | **ZERO regressions, both axes** | 43 tests / 93 comparisons: **87 IDENTICAL, 6 DIFFERS — all six are the target rows**; 0 APPEARED / 0 VANISHED / 0 NO_RENDER; **no trace status changes** (§6) |
| **CI-grade proof (s13 rule)** | **STRONGEST FORM** | all six before-leg PNGs are **md5-identical to the CI actual PNGs** in `origin/ruffle-image-results` (§4.1) |

**Net priced for the merge batch: +5 image comparisons, 0 regressions.**
The board priced P3 at **0-4 flips + 2 adjacent**; delivered **+5** — 3 of the 4
priced rows, plus **both** adjacent rows the board left unpriced.

### Refutations (attacking my own brief, as rule 1 requires)

1. **"these maskers never rasterise into the stencil" is only half right, and
   the half it names is the wrong half.** The maskers are fine when they are
   shapes. The defect is on **both** sides of a *bitmap* draw, and it lives in
   the RENDERER, not in the AVM2 mask walk: `blend_premul_pipeline` (bound by
   every `Bitmap` / `attachBitmap` / `beginBitmapFill` draw) was created with
   `ds_normal`, i.e. **stencil compare Always**. So (a) a bitmap MASKER wrote no
   stencil at all — worse, it clobbered the stencil-write pipeline mid-capture
   and painted itself as colour — and (b) a bitmap MASKEE ignored whatever
   stencil was there. Since all four rows' maskee is an embedded-PNG `Bitmap`,
   *every* sub-case failed, including the six of eight that never needed the
   alpha path. **The AVM2 mask walk needed no change whatsoever.**
2. **The four rows are not one mechanism.** After the stencil fix, three rows
   had **exactly one** residual cell family left — the `{maskeeCab, maskCab} =
   {true, true}` cells — and `cab_mask_alpha`'s other six cells were
   **byte-exact**. That is Ruffle's *second* masking mechanism
   (`RenderMask::Alpha`), which the cab-pixelsnap sibling had already named.
   Both mechanisms had to ship for any row to flip.
3. **The board's `ink_frac_actual = 0.9000` "identical number" is stronger
   evidence than it claimed.** `cab_mask_alpha`, `cab_mask_filters` and
   `cab_mask_triangle`'s CI actual PNGs are **byte-identical to each other**
   (md5 `0d637f88...`): three different tests rendered the *same* image, because
   in all three we drew the same unmasked 80x40 maskee grid and nothing else.
4. **`cab_mask_filters` "is filters on a masker, cut 3(b) owns it"
   (filters-cut2 §1) is confirmed but was under-scoped**: even with the mask
   working, its residual is *only* in the two `maskeeCab = true` columns, i.e.
   the alpha arm, i.e. the masker's blur/dropShadow that this port cannot run
   inside the alpha layer (§5). Its `maskeeCab = false` columns are now
   **byte-exact** with a *filtered* masker — which independently confirms that
   filters cut 1's "a filtered masker contributes its raw silhouette" rule is
   exactly what Ruffle's stencil arm does (`m.render_self`, not `m.render`).
5. **A third, unrelated defect was in the way and is fixed**: our bitmap
   fragment path applied the colour transform to fully transparent texels.
   Ruffle's `bitmap.wgsl` guards the whole cxform with `if (color.a > 0.0)`.
   Without that guard `cab_mask_transform` kept 9 pixels (its masker's alpha-0
   column, under a `ColorTransform(...,0.25,...,64)`, masked at 25 % instead of
   0 %) and could not flip.

---

## 2. Mechanism (verified against Ruffle source, not the brief's summary)

### 2.1 Ruffle has TWO mask mechanisms

`~/CC/ruffle/core/src/display_object.rs:1979`:

```rust
fn get_render_mask(self) -> RenderMask<'gc> {
    match self.masker() {
        None => RenderMask::None,
        Some(mask) if self.is_bitmap_cached() && mask.is_bitmap_cached()
             => RenderMask::Alpha(mask),
        Some(mask) => RenderMask::Stencil(mask),
    }
}
```

and `apply_standard_mask_and_scroll` (:1166) branches on it. `Stencil(m)` does
`push_mask / m.render_self / activate_mask / draw / deactivate_mask /
m.render_self / pop_mask`. `Alpha(m)` instead renders the maskee and the masker
into **two separate command lists** and calls
`commands.render_alpha_mask(maskee_commands, mask_commands)`, which multiplies
the maskee by the mask's **alpha**. A semi-transparent or antialiased masker
therefore produces a semi-transparent result — something a binary stencil cannot
express, and exactly what these four tests probe: each is a grid of 20x20 cells,
one per `{maskeeCab, maskCab}` combination, so **one cell in four takes the
alpha arm and three take the stencil arm**.

`is_bitmap_cached()` is the *effective* value, not the stored preference: a
non-empty filter list forces it true (`recheck_cache_as_bitmap`). That is why
`cab_mask_filters` — whose masker carries filters but whose `mask.cacheAsBitmap`
is false in half its cells — takes the alpha arm in **both** of its
`maskeeCab = true` columns.

### 2.2 Why every sub-case failed before: the premul pipeline has no stencil

`render_webgpu.c` builds `blend_premul_pipeline` from `ds_normal`
(`stencilFront.compare = Always`, `stencilWriteMask = 0`). Every bitmap draw
bound it:

```c
wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->blend_premul_pipeline);
render_webgpu_draw_shape(...);
restore_draw_pipeline(ctx);
```

Two consequences, both fatal here and both wider than this lead:

* **As a masker.** `avm2_push_clip_mask` binds `stencil_write_pipeline` and then
  renders the masker. If the masker is a `Bitmap`, its very first draw replaces
  that pipeline with `blend_premul_pipeline` — colour writes back **on**,
  stencil write **off**. The masker painted itself into the frame and raised
  **zero** stencil texels. `restore_draw_pipeline` then made it worse by binding
  `stencil_test_pipeline` at the level being written, so the rest of the
  masker's subtree was tested against a level nothing had reached.
* **As content.** A masked `Bitmap` bound the same Always-compare pipeline and
  ignored the clip entirely.

Ruffle has no such hole: its bitmap draw is
`pipelines.bitmap.pipeline_for(mask_state)` (`render/wgpu/src/pipelines.rs`) —
the mask state selects the stencil variant of the *same* blend for bitmaps
exactly as it does for shapes. This patch reproduces that: one extra pipeline
(`blend_premul_stencil_pipeline`, identical except `ds_test`), one chooser
(`bind_premul_pipeline`) with the three cases Ruffle's `mask_state` has, and a
mask-capture arm in `restore_draw_pipeline` so a clobber inside a capture comes
back to the **write** pipeline at level-1 rather than to the test pipeline.

### 2.3 The alpha arm, mapped onto machinery that already existed

`avm2_render_alpha_masked` needs no new renderer concept — filters cut 1 already
built the suspend / offscreen / snapshot / resume sandwich:

```
renderer_suspend_pass
  renderer_begin_offscreen_pass   -> render the MASKER   -> end   (filter_tex_a)
  renderer_snapshot_filter_source                              (-> filter_src_tex)
  renderer_begin_offscreen_pass   -> render the MASKEE   -> end   (filter_tex_a)
renderer_resume_pass
renderer_composite_alpha_mask                     // maskee * mask.a, over-blended
```

`begin_offscreen_pass` already parks `mask_ref` / `mask_capture_depth` and gives
the layer its own cleared stencil, so an enclosing clip survives and a mask
*inside* either layer works normally. The composite is a full-screen quad on
`compose_pipeline_layout` (binding 0 = maskee layer, 3 = mask layer, 2 = an
unused uniform the shared layout still demands), stencil-tested at `mask_ref`,
blended `One / OneMinusSrcAlpha`. Both layers are premultiplied, so `c * m.a`
stays premultiplied — three lines of WGSL.

Two globals keep the recursion honest: `g_avm2_alpha_maskee` (the node whose
mask arms are already being executed — suppresses both the alpha and the stencil
push on re-entry) and `g_avm2_alpha_masker` (the masker being drawn as its own
layer — exempts it from Ruffle's `options.skip_masks && this.maskee().is_some()`
suppression). Both are *object pointers*, not booleans, so a descendant with its
own mask inside either layer is unaffected.

### 2.4 The cxform guard

`~/CC/ruffle/render/wgpu/shaders/bitmap.wgsl` wraps the whole colour-transform
step in `if (color.a > 0.0) { unmultiply; transform; remultiply }`. A fully
transparent texel is left alone, so an additive alpha term cannot conjure ink
out of nothing. `color.wgsl` (solid fills, gradients) has **no** such guard —
hence the bitmap-only test in our `fs_main`. `cab_mask_transform`'s masker is a
10x10 PNG whose last column is alpha 0, under
`ColorTransform(0,0,0,0.25, 0,0,0,64)`: without the guard that column masked at
`64/255 = 25 %` and the row kept 9 pixels (max diff 64) it could not lose.

**Blast radius of the guard is narrow by construction**: it only changes a
bitmap draw whose cxform has a non-zero *additive* term AND whose texels are
fully transparent. An `aMult`-only transform (the `_alpha` property, by far the
common case) multiplies 0 by anything and is unaffected. Measured:
`cache_as_bitmap/color_transform` 0 -> **0**, `nested_color_transform` 0 -> **0**,
`acid-bitmap-fill` / `-fill-2` / `avm1/bitmap_data_fillrect` /
`bitmapdata_applyfilter_colormatrix` **md5-identical** (§6).

*(This port does NOT add the unmultiply/remultiply half of Ruffle's block — that
would change every bitmap draw with a non-identity cxform and is a separate,
much wider change. The guard alone is what these rows need; the missing
unmultiply is recorded in §8 as a standing divergence.)*

---

## 3. What actually shipped, hunk by hunk

| # | file / site | change |
|---|---|---|
| 1 | `render_webgpu.c`, premul pipeline creation | `blend_premul_stencil_pipeline` — same blend, `ds_test` (Equal) instead of `ds_normal` |
| 2 | `render_webgpu.c`, `restore_draw_pipeline` | new first arm: `mask_capture_depth > 0` => rebind `stencil_write_pipeline` at `mask_ref - 1` |
| 3 | `render_webgpu.c`, new `bind_premul_pipeline` | three cases (capture / masked / plain), replacing the two raw `SetPipeline(blend_premul_pipeline)` calls in `draw_bitmap_quad_scaled` and `draw_bitmap_tris` |
| 4 | `render_webgpu.c`, compose-pipeline block | `alpha_mask_wgsl` + `alpha_mask_pipeline` (reuses `compose_bgl` / `compose_pipeline_layout`) |
| 5 | `render_webgpu.c`, after `render_webgpu_compose_filter` | `render_webgpu_composite_alpha_mask` |
| 6 | `render_webgpu.c`, `fs_main` last line | `if ((v_style_type & 0xF0u) == 0x40u && color.a <= 0.0) { return color; }` |
| 7 | `render_webgpu.c`, release | `alpha_mask_pipeline` released next to `compose_pipeline` |
| 8 | `render_webgpu.h` | two trailing struct fields |
| 9 | `renderer.h` | `renderer_composite_alpha_mask` in both arms |
| 10 | `avm2_display.c`, above `avm2_render_node` | `avm2_is_bitmap_cached` (reads `ext->filter_count`, then the `__cacheAsBitmap` dyn prop), the two globals, `avm2_render_alpha_masked` |
| 11 | `avm2_display.c`, `avm2_render_node` maskee-skip | `&& obj != g_avm2_alpha_masker` |
| 12 | `avm2_display.c`, `avm2_render_node` | the alpha-arm branch (before the stencil push) |
| 13 | `avm2_display.c`, stencil push | `&& obj != g_avm2_alpha_maskee` |

`MSAA_SAMPLES` invariant respected: every new pipeline inherits
`rpd.multisample.count` from the shared descriptor (`MSAA_SAMPLES`); **no literal
4 anywhere in the patch**. Verified by grep.

**One reuse worth naming.** `avm2_is_bitmap_cached` is the first consumer, in
either VM's render walk, of the `__cacheAsBitmap` dynamic property that
`do_cab_set` (the AS3 setter) and `set_cache_as_bitmap` (PlaceObject3's
BitmapCache byte) have both been writing for sessions. The cab-pixelsnap
sibling's §8 called script-set `cacheAsBitmap` "not plumbed"; it is now plumbed
**for the mask decision only** — deliberately not for pixel snapping, which is
that patch's gated concern and would need its own A/B.

---

## 4. Per-comparison ledger

All numbers are local `--mode=graphics --images --verbose` runs in this
worktree, each check evaluated against that test's own `test.toml`.

### 4.1 Local grading is CI-grade — the strongest available check

The **before**-leg PNG of every one of the six moved rows is **md5-identical to
the CI actual PNG** published by run `31877239992` on
`origin/ruffle-image-results`:

| comparison | md5 (CI actual == local before) |
|---|---|
| `cab_mask_alpha:output` | `0d637f88139d7ea91d3db9a0180ffbdb` |
| `cab_mask_filters:output` | `0d637f88139d7ea91d3db9a0180ffbdb` |
| `cab_mask_triangle:output` | `0d637f88139d7ea91d3db9a0180ffbdb` |
| `cab_mask_transform:output` | `23179e62c7ec87fc7297a8ab589a561a` |
| `oversize/swf_9_masks:output` | `148c2d99298c0b5a810ff3e86deb14d4` |
| `oversize/swf_10_masks:output` | `148c2d99298c0b5a810ff3e86deb14d4` |

(The first three sharing one md5 is refutation 3 above.) The outlier counts
agree too: 4 644 / 4 968 / 5 280 / 2 340 / 119 943 / 119 943 — every one the
board's number.

### 4.2 Flips (5)

| comparison | before | after (stencil only) | after (shipped) | check that passes |
|---|---|---|---|---|
| `visual/cache_as_bitmap/cab_mask_alpha:output` | **fail** 4 644 (tol 2, limit 0) | 324 | **pass 0**, max diff 2 | tol 2 |
| `visual/cache_as_bitmap/cab_mask_transform:output` | **fail** 2 340 (tol 4, limit 0) | 180 | **pass 0**, max diff 2 | tol 4 |
| `visual/cache_as_bitmap/cab_mask_triangle:output` | **fail** 5 280 | 320 @tol 0 / 200 @tol 35 | **pass 0**, max diff 32 | check 2 (tol 35, limit 0) |
| `visual/cache_as_bitmap/oversize/swf_9_masks:output` | **fail** 119 943 | — | **pass 132** (limit 200) | check 1 (tol 64) |
| `visual/cache_as_bitmap/oversize/swf_10_masks:output` | **fail** 119 943 | — | **pass 132** (limit 200) | check 1 (tol 64) |

The oversize pair is the board's **unpriced** adjacent item (s16's P7). Their
`*_too_big` siblings — which the board noted "pass for the wrong reason, because
the mask is dropped by the SWF-9 size limit" — are **unchanged and still pass**
(md5-identical; they are `known_failure` rows either way).

### 4.3 Moved, no status change (1)

| comparison | before | after | note |
|---|---|---|---|
| `visual/cache_as_bitmap/cab_mask_filters:output` | fail 4 968 (tol 4, limit 0) | fail **612** | -87.7 %. Residual is confined to the two `maskeeCab = true` columns; the two `maskeeCab = false` columns are **byte-exact**. §5. |

### 4.4 The three parts, separated (the A/B that priced them)

Measured as three legs so the merge ledger can attribute each:

| comparison | before | + stencil fix | + alpha arm | + cxform guard |
|---|---|---:|---:|---:|
| `cab_mask_alpha` | 4 644 | 324 | **0 (pass)** | 0 (pass) |
| `cab_mask_transform` | 2 340 | 180 | 18 | **0 (pass)** |
| `cab_mask_triangle` | 5 280 | 320 @tol 0 | **0 (pass)** | 0 (pass) |
| `cab_mask_filters` | 4 968 | 836 | 612 | 612 |

**The stencil fix alone flips nothing** (-87 % to -96 %, and `max_outliers = 0`
on three of the four rows — precisely the s16 P2/P3/P4 trap). **The alpha arm
alone would flip nothing either** without the stencil fix, since 6 of 8 cells
would still be unmasked. The three parts are only worth anything together, which
is why they ship as one patch — and why splitting this lead across two agents
would have produced two 0-flip reports.

### 4.5 Unchanged — every number identical before and after

`cache_as_bitmap/masks` x7 (3103 / 3014 / 3010 / 3105 / 2985 / 2625 / 2520,
limit 3200 — **the tier-1 canary the board flagged as the risk**),
`cache_as_bitmap/shape_changed` 0, `color_transform` 0,
`nested_color_transform` 0, plus the 87 md5-identical canary comparisons in §6.

---

## 5. `cab_mask_filters` — the one residual, named and measured

Per-cell (20x20) outlier map after the patch:

```
   blur group                          drop-shadow group
                maskeeCab=F  =T                     maskeeCab=F  =T
        y= 0        0/0    249/179          y= 0        0/0    172/255
        y=20        0/0    249/179          y=20        0/0    172/255
```

Both surviving columns are `maskeeCab = true`, i.e. **exactly the alpha arm**,
and the masker in this test carries `[BlurFilter(5,5)]` (left group) or two
`DropShadowFilter`s (right group). Ruffle's alpha arm renders the masker with
`m.render_with_options(.., skip_masks: false)` = `render_base`, which **does**
apply its filters; our alpha arm renders it with `g_avm2_filter_active = 1`, so
the alpha layer is the masker's **raw silhouette**.

**Why not just run the blur.** `avm2_render_filtered` drives the *same*
suspend / offscreen / resume ping-pong that `avm2_render_alpha_masked` is
already holding; re-entering it would end the layer pass mid-flight. The blur
half could be done inline (`renderer_run_blur` between `end_offscreen_pass` and
`snapshot_filter_source`), but the drop-shadow half cannot: composition
(`render_webgpu_compose_filter`) writes to the **main** target, not into an
offscreen layer. So the best inline blur could do is take 612 to roughly 350,
and the row's check is `max_outliers = 0` — **no flip is available at any
partial depth**, which is why the patch stays minimal rather than buying a band
move at the cost of more surface area.

**Completion mechanism:** a compose-into-offscreen pipeline (a `compose_pipeline`
variant whose colour target is `filter_tex_b` instead of the surface). That is
the *same* missing primitive filters cut 2 §8 names for a non-final
glow/dropShadow in a chain, and cab-pixelsnap §8 names for un-gating its filter
case. One primitive, three parked items — the highest-leverage renderer work
left in this family.

---

## 6. Canary

`ruffle-tests/render_canary.py capture before` (patch reverted with
`git apply -R`, never `git stash`) / `capture after`, `-P 2`,
`SWFRECOMP_COMPILE_TIMEOUT=2400`, `--timeout 5400`, `--recompile` on the before
leg (first use of every copied test dir).

Set = the **full standing `render_canary_tests.txt`** (25 tests) **plus 14 extra
A/B members** chosen for this change class, because the standing set has no
bitmap-inside-a-mask row anywhere:

```
visual/cache_as_bitmap/oversize/swf_{9,10}_masks   from_shumway/acid/acid-mask
from_shumway/acid/acid  (18 cmps)                  avm2/displayobject_mask
avm2/displayobject_mask_self_referential           avm2/mask_reapply
avm2/bitmapdata_draw_masks                         visual/cache_as_bitmap/cab_mask_*  (4)
visual/cache_as_bitmap/{color_transform,nested_color_transform}
```

```
RENDER CANARY  before=before  after=after   43 tests / 93 comparisons

  IDENTICAL    87
  DIFFERS       6
  APPEARED      0   VANISHED 0   NO_RENDER 0

  DIFFERS: cab_mask_alpha (fail->pass), cab_mask_transform (fail->pass),
           cab_mask_triangle (fail->pass), oversize/swf_9_masks (fail->pass),
           oversize/swf_10_masks (fail->pass), cab_mask_filters (fail->fail)

  TRACE STATUS CHANGES: (none)
```

**Every DIFFERS is a target row, and five of the six are the flips.** Nothing
else in 93 comparisons moved by a single byte.

The members that make this canary *mean* something for this change class:

| member | why it is load-bearing here |
|---|---|
| `visual/cache_as_bitmap/masks` x7 (tier 1) | the board's stated risk — passes with only 3-20 % slack; **md5-identical**, all seven |
| `regression/mask_nested_intersect`, `mask_sibling_union` | pin the Equal/IncrementClamp nesting model the new arms sit on; identical |
| `visual/simple_shapes/masks`, `avm1/mask_with_drawing`, `avm1/movieclip_setmask` | the AVM1 stencil routes go through the same `restore_draw_pipeline`; identical |
| `from_shumway/acid` (18 cmps) + `acid-mask` (3) | the corpus's densest clipDepth content; identical |
| `avm2/displayobject_mask`, `mask_reapply`, `bitmapdata_draw_masks`, `displayobject_mask_self_referential` | the AVM2 `.mask` rows that must *not* take the new alpha arm (neither side bitmap-cached); identical on both axes |
| `acid-bitmap-fill`, `acid-bitmap-fill-2`, `avm1/bitmap_data_fillrect`, `bitmapdata_applyfilter_colormatrix` | bitmap draws with **no** mask — prove `bind_premul_pipeline`'s third case is byte-for-byte the old behaviour; identical |
| `cache_as_bitmap/color_transform`, `nested_color_transform` | the cxform guard's blast radius; identical |
| `visual/filters/{glow_pass_scaling,drop_shadow,color_matrix,displacement_map_through_applyFilter}` | share the offscreen ping-pong the alpha arm now also uses; identical |

**Canary blind spot, stated (s15 rule).** The standing set contains **no member
that draws a bitmap inside a mask** — before this patch the entire mechanism was
invisible to it, which is a large part of why it survived to s17.
**Recommended additions to `render_canary_tests.txt`:**
`visual/cache_as_bitmap/cab_mask_alpha` (tier 1 after this patch — byte-exact at
tolerance 2, and the only corpus test that exercises all eight masker/maskee
cache combinations in one frame) and
`visual/cache_as_bitmap/oversize/swf_9_masks` (tier 1 after this patch; a
*scaled* bitmap masker, which nothing else covers).

---

## 7. Trace axis

The patch cannot move AS-visible state by construction: every hunk is inside a
render pass or a WGSL string, `avm2_is_bitmap_cached` only *reads* a dyn prop,
and the two new globals are cleared on the same call frame that sets them.
Measured anyway — the canary's 43 tests carry their trace verdicts along, and
**zero trace status changes** were reported, including on the four AVM2 mask
trace rows and `avm2/displayobject_mask_self_referential` (which renders 0 PNGs
and is therefore a pure trace member here).

---

## 8. Left on the board

* **`cab_mask_filters` (612, -87.7 %)** — one mechanism, §5. **Completion
  mechanism: a compose-into-offscreen pipeline.** Shared with filters cut 2 §8
  and cab-pixelsnap §8.
* **The alpha arm is suppressed for a maskee that has FILTERS.** Ruffle would
  take the alpha arm there (filters force `is_bitmap_cached`); we take the filter
  arm, which drops the mask inside the capture. Same missing primitive. No corpus
  row is currently blocked on it — every `maskee.filters` + `mask` combination in
  the corpus is inside `cab_mask_filters`, whose maskee has none.
* **Ruffle's bitmap cxform unmultiply/remultiply is still not ported** (§2.4).
  Our `apply_cxform` multiplies the *premultiplied* colour; Ruffle unmultiplies
  first. This is invisible for `aMult`-only transforms (the common case) and for
  fully opaque or fully transparent texels — and it now matches at both ends of
  the alpha range — but **semi-transparent bitmap texels under an RGB-add
  transform remain divergent.** Completion mechanism: port the full block, then
  re-grade every bitmap+cxform row. That is a wider A/B than this lead's slot and
  should be its own item.
* **`bind_premul_pipeline` fixed the bitmap arm; the legacy per-draw blend
  pipelines still have the identical hole.** `render_webgpu_set_blend_mode`'s own
  comment says so: "the legacy per-draw blend pipelines carry no stencil test, so
  a blend-mode object inside a clip mask is unclipped for the duration of its
  draw." Now that the pattern exists, closing it is four more pipelines and one
  more chooser case. No corpus row is currently known to be blocked on it —
  **named as the obvious next application of this fix, not as a priced lead.**
* **The alpha arm is AVM2-only.** AVM1's `setMask` route (`tag.c`) has no
  cacheAsBitmap concept at all, so it always takes the stencil arm — which is
  what Ruffle does for it too *unless* the SWF sets `cacheAsBitmap` via
  PlaceObject3, in which case Ruffle would switch arms and we would not. No
  corpus row exercises it.

---

## Appendix A — reproduce

```bash
export SWFRECOMP_COMPILE_TIMEOUT=2400 DAWN_INSTALL=$HOME/CC/dawn-install
cd <worktree>

# the five flips + the band move
python3 ruffle-tests/verify_output.py \
    --tests-dir=ruffle-tests/tests/swfs/visual \
    --test=cache_as_bitmap/cab_mask_alpha --test=cache_as_bitmap/cab_mask_filters \
    --test=cache_as_bitmap/cab_mask_transform --test=cache_as_bitmap/cab_mask_triangle \
    --test=cache_as_bitmap/oversize/swf_9_masks --test=cache_as_bitmap/oversize/swf_10_masks \
    --mode=graphics --images --verbose

# the canary A/B (43 tests; list = standing set + the 14 extras of section 6)
python3 ruffle-tests/render_canary.py capture --label before \
    --tests <list> -P 2 --recompile --timeout 5400      # with the patch reverted
git apply w2-gfx-cab-mask-stencil.patch
python3 ruffle-tests/render_canary.py capture --label after --tests <list> -P 2 --timeout 5400
python3 ruffle-tests/render_canary.py compare before after

# the CI-grade proof: extract origin/ruffle-image-results' images/visual/cache_as_bitmap
# tree and md5-compare each output.actual.png against the before-leg output.png in
# .render_canary/before/visual/cache_as_bitmap/<test>/
```

Scratch (not committed):
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/ab0a66b8-f5eb-4947-8b92-d32ad2d435e1/scratchpad/w2cabmask/`
— `grade.py` (per-tolerance + per-20x20-cell outlier map: the instrument that
separated the two mechanisms and is worth keeping for any grid-of-cells visual
test), `px.py` (differing-pixel dump), `cimatch.sh`, `canary_plus.txt`.
