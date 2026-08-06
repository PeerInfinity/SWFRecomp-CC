# w2-gfx-filters — session 12 wave-2 pixel axis

**Agent:** `w2-gfx-filters` (isolated worktree `agent-aa5dc68150d9afd04`, base
`f166e424e`).
**Deliverable:** `w2-gfx-filters.patch` — one file,
`SWFModernRuntime/src/rendering/render_webgpu.c`, +105/−37.
Verified with `git apply --check --reverse`: the patch is exactly
`f166e424e → worktree`, nothing else in it.

**Mission:** port Ruffle's box-blur kernel into the filter region.
**Result:** done and verified live. **Predicted CI flips: 0.** The wave-1 board
estimate of "~11 comparisons" is **refuted** — see §4, which is the real finding
of this session.

---

## 1. What the patch changes

Everything is in the blur core: `blur_wgsl` (render_webgpu.c 3097–3180) and
`render_webgpu_run_blur` (3941–4030, plus the new `blur_box_kernel()` helper).
No pipeline objects, no bind-group layouts, no textures, no MSAA sites touched —
`multisample.count` on the blur pipeline stays `1` because `filter_tex_a/b` are
1-sample resolve targets, and the file still contains **zero** literal-4 MSAA
counts (audited).

| # | before | after | source |
|---|---|---|---|
| 1 | Gaussian, `sigma = radius/2`, `radius = blur*scale*0.5`, integer taps | Fractional **box** of width `full_size`, edge texels at fractional weight, interior sampled as linear-filtered pairs | `ruffle render/wgpu/shaders/filter/blur.wgsl` + `src/filters/blur.rs` |
| 2 | `radius` clamped to **31** (a 62px window ceiling) | `full_size` clamped to **255**, as FP does | `blur.rs: full_size = strength.min(255.0)` |
| 3 | `radius` clamped to a **minimum of 1** — so `blurX = 0` or `1` still ran a 3-tap blur | `full_size <= 1` is an exact identity pass (weight 1 on the centre texel, no fixed-point round) | `blur.rs: if full_size <= 1.0 { continue }` |
| 4 | stage scaling as `blur * scale` | `(blur - 1) * scale + 1` | `swf/src/types/blur_filter.rs::scale_blur` |
| 5 | no output quantisation | `floor(result * 255) / 255` per pass, imitating FP's fixed-point accumulator | `blur.wgsl` final line |
| 6 | `strength` and `colorize` written once per quality iteration and **left in place for the V pass too** — a glow came out at `strength²` and `color.a²` | applied exactly once, on the V half of the final pass | `ruffle glow.wgsl` composites them separately, once |

Item 3 is why we kept the pass instead of skipping it: the `filter_tex_a →
filter_tex_b → filter_tex_a` ping-pong needs both axes to run for the result to
land back in `filter_tex_a`, which is the texture `render_webgpu_composite_filtered`
reads. Ruffle can skip because it flip/flops `CommandTarget`s.

Kernel values confirmed at runtime with a temporary `getenv`-gated dump (removed
before the patch was cut; the post-cleanup render is md5-identical to the
measured `after` leg): for `visual/filters/glow` (blurX=blurY=5, quality=1,
stage_scale=1) the shader receives `full_size=5, m=1, m2=2, first_weight=1,
last_offset=0.5, last_weight=2` — an exact 5-texel box, weights
`[1,1,1,1,1]/5` against the old gaussian's `[.092,.240,.331,.240,.092]`.

---

## 2. Per-comparison ledger (local A/B, `render_canary.py`)

`before` = `f166e424e` pristine, `after` = patch applied. 13 tests, 12
comparisons, `--jobs 2`. Captures in
`<worktree>/.render_canary/{before,after}`; list file
`ruffle-tests/w2_gfx_filters_canary.txt` (untracked, deliberately not in the patch).

`compare before after`: **IDENTICAL 6 · DIFFERS 6 · APPEARED 0 · VANISHED 0 ·
NO_RENDER 0 · TRACE STATUS CHANGES: none · IMAGE STATUS CHANGES: none.**

| comparison | role | md5 | excess outliers before → after | |
|---|---|---|---:|---|
| `avm1/color` | canary | SAME | 0 → 0 | ok |
| `avm1/mask_with_drawing` | canary | SAME | 0 → 0 | ok |
| `regression/mask_sibling_union` | canary | SAME | 0 → 0 | ok |
| `visual/simple_shapes/winding_rule` | canary | SAME | 0 → 0 | ok |
| `visual/filters/color_matrix` | control | SAME | 237 → 237 | ok — never reaches `run_blur` |
| `visual/filters/any_blur_scales_with_screen` | target | MOVED | 11776 → **8336** | **−29.2%** |
| `visual/filters/glow_with_alpha_strength` | target | MOVED | 340997 → **326511** | **−4.2%** |
| `visual/filters/blur_size_grows` | target | MOVED | 109963 → **108027** | **−1.8%** |
| `visual/filters/bevel` | target | MOVED | 385036 → 395016 | +2.6% |
| `visual/filters/glow` | target | MOVED | 95801 → 104522 | +9.1% |
| `visual/filters/drop_shadow` | target | MOVED | 117137 → 142245 | +21.4% |
| `visual/filters/blur_scales_with_screen` | target | **SAME** | 69254 → 69254 | **inert — §4B** |

`avm2/blend_multiply_alpha` produced no PNG in **either** leg
(`collect2: error: ld returned 1 exit status`, 5.9 s). It fails identically at
the pristine baseline, so it is a worktree-environment artifact (AVM2 tests need
build inputs I did not copy), not a regression. The same link error hits
`avm2/blur_filter` and `avm2/glow_filter`, so those AVM2 tests are unmeasured
locally.

**Trace axis:** every rendered test above is `pass → pass` in graphics mode.
Additional unrelated graphics-mode trace runs, both pass:
`avm1/edittext_tag_indent`, `visual/simple_shapes/gradients/gradients`.

---

## 3. Structural verification — the kernel is right

Ledger deltas alone read as "3 better, 3 worse". Per-object decomposition says
something much more specific. `visual/filters/glow` and
`visual/filters/drop_shadow` each place **four** copies of the same object with
filter flag bytes 1/3/5/7 = `composite_source` + {none, knockout, inner,
inner+knockout}, one per quadrant. Splitting `sum|actual − golden|` by quadrant:

| quadrant | `glow` | `drop_shadow` |
|---|---|---|
| flags=1 outer + composite_source | 539045 → 432820 (**−19.7%**) | 1261595 → 1221990 (**−3.1%**) |
| flags=3 outer + knockout | 2419710 → 2325950 (**−3.9%**) | 3139838 → 3130931 (**−0.3%**) |
| flags=5 **inner** | 548508 → 735628 (+34.1%) | 1305262 → 2107766 (+61.5%) |
| flags=7 **inner** + knockout | 2334777 → 2519419 (+7.9%) | 2948857 → 3753431 (+27.3%) |

**Every variant we actually model improves; every variant we do not model gets
worse.** We render all four as a plain outer glow/shadow, so a correct — wider,
flatter — box kernel makes the two *wrong-kind* quadrants more wrong. That is
the whole of the "3 worse" column.

Direct structural evidence on the one quadrant we model (`glow`, flags=1, region
rows 0–200 × cols 0–280), red-glow pixels only:

```
             glow px    alpha mass    glow bbox
before             0             0    (none — the old kernel produced no red glow here)
after           4598        171351    x[37,243] y[  4,197]
golden          4489        205638    x[35,245] y[  6,195]
```

Glow area now within **2.4%** of the golden, bounding box within **2 px** on
every side, alpha mass at **83%**. And on `blur_size_grows` (blurX=blurY=30,
quality=1) the rendered ink's **vertical extent becomes y[15,352] — exactly the
golden's** (it was y[19,348]).

So: kernel shape is now correct, and the residual in the filter family is
somewhere else.

---

## 4. Refutation — wave-1 §8's "~11 comparisons" does not hold

Board §8 reasoned that because `stage_scale` plumbing already existed, the
residual across blur/glow/drop-shadow/bevel was kernel shape, and one kernel port
would touch ~11 comparisons. Measured: the kernel port is worth **0 flips**, and
the four families do not share a residual at all. They decompose into three
*different* unowned mechanisms, none of which is the kernel.

### (A) inner / knockout / composite_source composition is not implemented — the dominant residual for glow, drop-shadow and bevel (~9 comparisons)

`tagSetFilter` parses the flag byte into `DisplayObject::filter_flags`
(`SWFRecomp/src/swf.cpp:3812, 3874, 3921`) and **nothing reads it**. The render
path (`SWFModernRuntime/src/libswf/tag.c:5578–5612` and the twin at `6569–6603`)
composites `filter_tex_a` and then unconditionally re-draws the source, i.e.
"outer glow, composite source" for every flag combination. Ruffle needs a
dedicated shader for this (`render/wgpu/shaders/filter/glow.wgsl`) that samples
**both** the blurred texture and the *unblurred source*:

```
inner:  alpha = color.a * saturate((1.0 - blur) * strength)
        knockout -> color*alpha*dest.a ; composite_source -> + dest*(1-alpha)
outer:  alpha = color.a * saturate(       blur  * strength)
        knockout -> color*alpha*(1-dest.a) ; composite_source -> + dest
```

We cannot express that today: the offscreen source lands in `filter_tex_a` and
the blur ping-pong destroys it. **Sized: one new filter texture (source
snapshot; `filter_tex_a` needs `CopySrc`), a 4th binding plus
inner/knockout/composite_source uniforms on the composite shader, and the flag
plumbing through the two `tag.c` call sites.** Not arc-sized, but it is its own
patch, and it is the item that actually carries the flips — the quadrant table
in §3 is the estimate of what it is worth. It should land **before or with**
this patch.

### (B) filters on objects inside a sprite are never rendered (>=2 comparisons, one of them a target)

`visual/filters/blur_scales_with_screen` is byte-identical before and after, and
its render contains **3 distinct colours** — no blur at all. Its `tagSetFilter`
is emitted inside `sprite_3_frame_0` (`RecompiledTags/tagMain.c:44`), and
`render_display_list()` (`SWFModernRuntime/src/libswf/tag.c:3285…`), the
nested-sprite renderer, has **no filter branch** — only the two top-level display
loops do. Adding one means suspending/resuming a pass from inside a nested walk,
the same offscreen-nesting constraint that blocks F5 layer groups (board §3,
`render_webgpu_blend_mode_is_layered()`'s `offscreen_depth > 0` guard).
**Arc-adjacent, skipped.**

### (C) `BitmapData.applyFilter` implements ColorMatrixFilter only (~4 comparisons)

`visual/filters/{blur_fractional, blur_quality}` and `blur_pass_scaling` rows 1–2
call `image.applyFilter(..., new BlurFilter(...))`. Both CPU implementations —
`SWFModernRuntime/src/avm2/avm2_bitmap.c:2538 bd_apply_filter` and
`SWFModernRuntime/src/actionmodern/action.c:13294 bitmapDataApplyFilter` — bail
out for every filter kind except ColorMatrix, so those tests render an
**unfiltered** bitmap. The board counted them in the "blur kernel / quality"
slice; they are not on the GPU path at all. A CPU box blur reusing exactly the
weights in `blur_box_kernel()` would close them. **Sized: one shared CPU kernel +
two call sites.** Independent of this patch.

### Re-cut of board §8

**kernel 0 · composition ~9 · sprite-nested ~2 · CPU applyFilter ~4 ·
displacement 4 (untouched, its own mechanism) · misc 5.**

---

## 5. Risks

- **Three worsened bands, zero flips, if this lands alone.** `drop_shadow`
  +21.4%, `glow` +9.1%, `bevel` +2.6% excess outliers, entirely in the
  inner-flag quadrants (§3). Bands are almost certainly unchanged (all three are
  already `e_large` and the moves are within-band), but s11 closed the
  worsened-band watchlist and this would open three rows on it.
  **Recommendation: land this together with (A).** If it lands alone, the
  closeout must state "0 flips, 3 band-internal worsenings, correct substrate"
  up front rather than claim yield.
- **Cost.** The window cap went 62 px → 255 px, so a pathological
  `blurX=255, quality=3` filter is now up to ~2x the samples per fragment, over a
  full-stage-sized filter texture (Ruffle's is only the filter region). No test
  in the corpus exceeds blur 30; a game with a huge blur could feel it.
- **`floor(x*255)/255` on the identity pass** is gated off (`full_size > 1.0`)
  precisely so an 8-bit round-trip cannot shave a level off an exact copy. If
  that guard is ever removed, `blurX<=1` filters will darken by 1/255 per pass.
- **Local-only grading.** Everything above is our-render-vs-our-render plus
  our-render-vs-golden on **local Dawn**, which is not CI's lavapipe. The
  excess-outlier deltas are directional evidence, not CI numbers. The md5 canary
  invariant (4 canaries + 1 control, all SAME, zero trace/image status changes)
  is the load-bearing claim.

## 6. Reproduce

```bash
DAWN_INSTALL=~/CC/dawn-install \
python3 ruffle-tests/render_canary.py capture --label before \
    --tests ruffle-tests/w2_gfx_filters_canary.txt --jobs 2
# apply w2-gfx-filters.patch
DAWN_INSTALL=~/CC/dawn-install \
python3 ruffle-tests/render_canary.py capture --label after  \
    --tests ruffle-tests/w2_gfx_filters_canary.txt --jobs 2
python3 ruffle-tests/render_canary.py compare before after
```
