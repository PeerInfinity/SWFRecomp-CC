# w2-gfx-filters-inner — session 12 wave-2 pixel axis

**Agent:** `w2-gfx-filters-inner` (isolated worktree `agent-af67a17789b50d337`,
base `f166e424e` + the sibling patch `w2-gfx-filters.patch` committed locally as
`0e107d5a0`).
**Deliverable:** `w2-gfx-filters-inner.patch` — 5 files, +512/−141. Verified with
`git apply --check` against a tree holding **only** the sibling patch: it applies
clean on top of `w2-gfx-filters.patch` and contains nothing of it.

**Mission:** blocker A from the sibling report — inner / knockout /
compositeSource filter composition.
**Result:** implemented and verified. **Predicted CI flips: 0** (see §5 — the
family's `max_outliers` budgets are 0–18 and the best residual is ~25 k). But the
excess-outlier ledger moves by **−41 % to −93 % on 12 of the 13 live filter
comparisons, with zero worsened and zero canary moves** — the family went from
"wrong mechanism" to "right mechanism, residual elsewhere".

The headline finding is **not** the composition shader. It is §3: two
pre-existing renderer bugs that were silently corrupting every filter in the
corpus, one of which was making the sibling's brand-new box-blur kernel run on
**one axis only**.

---

## 1. What the patch changes

| # | file | what |
|---|---|---|
| 1 | `render_webgpu.c:3228` | new `compose_wgsl` — ruffle `filter/glow.wgsl` + `filter/bevel.wgsl` fused into one module with a `kind` selector; 4 bindings (blurred, sampler, uniform, **source snapshot**) |
| 2 | `render_webgpu.c:3600-3640` | `compose_pipeline` — same blend/stencil/`MSAA_SAMPLES` config as `composite_pipeline`, plus the 4th binding |
| 3 | `render_webgpu.c:3405`, `.h:146` | `filter_src_tex` / `filter_src_view`; `filter_tex_a` gains `CopySrc` |
| 4 | `render_webgpu.c:4350` | `render_webgpu_snapshot_filter_source()` — copies `filter_tex_a` into the snapshot between `end_offscreen_pass` and `run_blur` |
| 5 | `render_webgpu.c:4372` | `render_webgpu_compose_filter()` |
| 6 | **`render_webgpu.c:3338-3350`** | **filter uniform RING** — replaces `blur_params_buf`, `filter_quad_buffer` and the composition uniform with 256-byte slots off one buffer. §3A |
| 7 | `tag.c:3240` | `render_filtered_object()` — one helper replacing the two duplicated draw sites (`tag.c:5703`, `tag.c:6645`); decodes `filter_flags`, picks the composition mode, decides whether the source is sampled or drawn |
| 8 | **`tag.c:3319`** | **filter angle is radians, not degrees.** §3B |
| 9 | `swf.cpp:3985/4180/5595` | gradient-glow / gradient-bevel `parsed_filter_flags` re-encoded into the layout of the filter *type* they are mapped to, so the new reader cannot mistake `onTop` for `compositeSource` |

`filter_flags` was parsed but read by nothing. It now drives the render, decoded
**exactly** as the `mc.filters` reflection in `action.c:53829` decodes it
(glow/shadow: bit0 compositeSource, bit1 knockout, bit2 inner; bevel: bit0 onTop,
bit1 compositeSource, bit2 knockout, bit3 inner), so no AS-visible behaviour
changes. `all_filters` / `FilterListData` — the array reflection actually reads —
is untouched.

### The "crisp source" rule

Whenever Flash's formula ends in a bare `+ dest`, the patch renders the source
with a **real draw call** instead of sampling the snapshot, because
`filter_output` then `source` over it reproduces the compositeSource formula
exactly (over-compositing is associative) and keeps the source MSAA-sharp:

* outer, no knockout, compositeSource → shader with `composite_source = 0`, then `render_single_object`
* bevel outer → same
* bevel **full** → `render_single_object` **first**, then the filter over it
* everything with `inner` or `knockout` → snapshot path (the formula multiplies `dest`, so it cannot be decomposed)

`needs_source_tex` is gated on the same predicate, so the texture copy is skipped
for the common outer+compositeSource case.

---

## 2. Structural verification

`visual/filters/glow` places four copies of one object with flag bytes
1/3/5/7 = compositeSource + {none, knockout, inner, inner+knockout}, one per
quadrant. Before this patch **all four rendered as a plain outer glow**.

| quadrant | flags | excess outliers before → after | sum\|actual−golden\| |
|---|---|---:|---:|
| r0c0 | 1 outer + compositeSource | 11 470 → **9 091** (−20.7 %) | 431 580 → 351 814 |
| r0c1 | 3 outer + knockout | 39 355 → **8 302** (−78.9 %) | 2 323 344 → 245 990 |
| r1c0 | 5 **inner** | 13 677 → **4 221** (−69.1 %) | 736 868 → 321 600 |
| r1c1 | 7 **inner + knockout** | 40 020 → **3 611** (−91.0 %) | 2 522 025 → 257 253 |

`drop_shadow`, same decomposition: −8.7 % / −62.8 % / −65.8 % / −82.3 %. Every
quadrant improves — the sibling's §3 table (where the two unmodelled quadrants
got *worse*) is closed.

Visual checks, per the mission's structural bar:
* **inner glow is inside the shape** — the flags=5 quadrant is now
  indistinguishable from the golden at viewing scale (red rim hugging the strokes
  and the ellipse edge, source intact, no outer halo).
* **knockout hole present** — the flags=3 quadrant shows the source removed and
  only the outer rim remaining, matching the golden's structure.
* alpha channel: **0** excess outliers on `glow` after the patch (was non-zero).

---

## 3. The real finding — two pre-existing renderer bugs

Both were found by instrumenting the composition shader (per-branch colour
probes) when the first working build produced obviously wrong output, and both
predate this session.

### (A) A uniform buffer rewritten between draws of one frame serves them ALL with the LAST value

`wgpuQueueWriteBuffer` is ordered against `Submit`, **not** against the commands
already sitting on the pending encoder. Every write issued while a frame is being
built lands before *any* draw in that frame executes. The filter path had three
such buffers and rewrote each per draw.

Measured, decisively: with a shared buffer, all four `glow` composites took the
`inner + knockout` branch (= the last object's flags); with a per-call buffer,
they took `outer+cs`, `outer+ko`, `inner+cs`, `inner+ko` respectively.

Three wrong renders came out of this one mechanism:

1. **`blur_params_buf`** — `run_blur` writes the H kernel, draws, writes the V
   kernel, draws. Both passes ran with the **V** direction and the **V** kernel.
   *Every blur in the engine was single-axis.* The sibling's fractional-box port
   was therefore never actually exercised on the horizontal axis; fixing the
   aliasing moved `blur_size_grows` (which had been byte-identical through the
   sibling's whole patch) by −17.7 %.
2. **`filter_quad_buffer`** — a bevel's shadow composite ran with the
   highlight's tint.
3. the new composition uniform, as above.

**Fix:** one `filter_uniform_ring` buffer, 1024 × 256-byte slots (256 KB),
cursor bumped per write and reset in `open_pass`. Bind-group entries carry the
slot offset. 256 B ≥ `minUniformBufferOffsetAlignment`; a filtered object uses
`2 × quality + 1` slots, so the ring covers ~145 filtered objects per frame.

This is the single largest contributor in the ledger and it is **inside the
sibling's own region** — the kernel patch cannot be graded without it.

### (B) The filter angle is radians, and the renderer treated it as degrees

SWF stores `DROPSHADOWFILTER.Angle` / `BEVELFILTER.Angle` as FIXED **radians**
(spec text: "Radian angle of the drop shadow"); `swf.cpp` keeps that unit and
`action.c:53831` converts to degrees for `mc.filters`. Both render sites did
`angle * pi / 180`, i.e. treated 1.5708 rad as 1.5708°, collapsing every
non-zero-angle shadow and bevel onto ~0°.

`drop_shadow_angles` (angles 0, π/2, π, 3π/2, 2π) and all four bevels were
affected. Fixing it took `bevel` from −26.7 % to **−83.0 %** and `bevel_full`
from −45.9 % to **−91.0 %**.

### (C) WGSL uniformity (a self-inflicted one, recorded because it costs a full A/B leg)

`textureSample` must sit in uniform control flow. An early `return 0.0;` guard
for out-of-bounds blur UVs made `CreateShaderModule` fail → invalid pipeline →
invalid command buffer → **every filter test rendered a fully blank frame**
(md5-differing, `trace: pass → pass`, no Python-visible error). The Dawn error is
only visible by running the built `test_run` binary directly. Samples are now
taken unconditionally and masked by value (`in_bounds()`), which is also what
ruffle does.

---

## 4. Per-comparison ledger

`before` = sibling patch only, `after` = sibling patch + this patch. Both legs
captured with `--recompile` (this patch touches `SWFRecomp/`), `--jobs 4`,
local Dawn. List files `ruffle-tests/w2_gfx_filters_inner_{canary,extra}.txt`
(untracked, deliberately not in the patch).

`compare before after`: **IDENTICAL 25 · DIFFERS 11 · APPEARED 0 · VANISHED 0 ·
NO_RENDER 0 · TRACE STATUS CHANGES: none · IMAGE STATUS CHANGES: none.**

### Canaries — all md5-IDENTICAL

`avm1/color`, `avm1/bitmap_data_fillrect`, `avm1/mask_with_drawing`,
`avm1/movieclip_setmask`, `avm1/edittext_tag_indent`,
`avm1/bitmapdata_applyfilter_colormatrix`, `visual/simple_shapes/winding_rule`,
`visual/cache_as_bitmap/shape_changed`, `from_shumway/timeline/timeline_as2_5`
(7 cmps), `from_shumway/acid/acid-gradient-0`, `regression/mask_sibling_union`,
`regression/avm2_timeline_gradients`, `visual/simple_shapes/masks`,
`visual/simple_shapes/gradients/gradients`, `visual/blend_modes/multiply`.
25 comparisons, zero moves.

### Filter comparisons (excess outliers vs the golden, at the test's own tolerance)

| comparison | role | tol / max_out | before | after | Δ |
|---|---|---|---:|---:|---:|
| `visual/filters/color_matrix` | control | 0 / 0 | 237 | 237 | 0.0 % |
| `visual/filters/bevel_inner` | mine | 4 / 18 | 640 103 | **47 419** | **−92.6 %** |
| `visual/filters/bevel_full` | mine | 4 / 18 | 721 838 | **64 744** | **−91.0 %** |
| `visual/filters/bevel_outer` | mine | 3 / 18 | 666 766 | **76 580** | **−88.5 %** |
| `visual/filters/glow_without_composite_source` | mine | 3 / 0 | 159 795 | **25 245** | **−84.2 %** |
| `visual/filters/drop_shadow_angles` | mine | 2 / 0 | 172 704 | **55 901** | **−67.6 %** |
| `visual/filters/glow_with_alpha_strength` | sibling | 4 / 18 | 326 529 | **41 914** | **−87.2 %** |
| `visual/filters/bevel` | sibling | 3 / 6 | 395 022 | **67 057** | **−83.0 %** |
| `visual/filters/glow` | sibling | 2 / 0 | 104 522 | **25 225** | **−75.9 %** |
| `visual/filters/drop_shadow` | sibling | 2 / 0 | 142 245 | **45 883** | **−67.7 %** |
| `visual/filters/any_blur_scales_with_screen` | sibling | 2 / 0 | 8 336 | **4 884** | **−41.4 %** |
| `visual/filters/blur_size_grows` | sibling | 3 / 0 | 108 027 | **88 928** | **−17.7 %** |
| `from_shumway/acid/acid-filter-2` | extra | 0 / 0 | 188 388 | **39 753** | **−78.9 %** |
| `visual/filters/blur_scales_with_screen` | sibling | 2 / 0 | 69 254 | 69 254 | inert |
| `visual/filters/glow_pass_scaling` | mine | 100 / 0 | 17 680 | 17 680 | inert |
| `visual/filters/drop_shadow_scales_with_screen` | mine | 2 / 0 | 400 | 400 | inert |
| `from_shumway/acid/acid-filter` | extra | 4 / 0 | 152 866 | 152 866 | inert |
| `blur_quality`, `blur_fractional`, `blur_pass_scaling`, `displacement_map`, `displacement_map_through_filters` | extra | — | — | IDENTICAL | inert |

**Nothing got worse.** The four inert filter tests are the sibling's leftovers B
(sprite-nested filters — `blur_scales_with_screen`, `glow_pass_scaling`,
`drop_shadow_scales_with_screen`, `acid-filter`) and C (CPU `applyFilter`), both
explicitly out of scope.

### Trace axis

All 38 rendered tests are `pass → pass` in graphics mode, including the three
unrelated graphics-mode traces `avm1/edittext_tag_indent`,
`visual/simple_shapes/gradients/gradients`, `from_shumway/timeline/timeline_as2_5`.
Default (NO_GRAPHICS) trace runs, all pass: `visual/filters/glow`,
`visual/filters/bevel_inner`, `visual/filters/drop_shadow_angles`, `avm1/color`.

`avm2/blend_multiply_alpha` was dropped from the canary list: it fails to link in
this worktree at the pristine baseline too (the sibling's environment artifact),
so it carries no signal. `avm2/{blur,glow}_filter` remain unmeasured locally for
the same reason — they are the most likely place for an unmeasured CI move.

---

## 5. Predicted CI flips: 0 — and why the estimate was wrong

The wave-1 board and the sibling both sized composition at "~9 comparisons".
Measured: **0**. The reason is not the mechanism, it is the **budget**. Every
test in this family carries `max_outliers` between 0 and 18 against a
550×400 or 900×800 image. The best result after this patch is
`glow` / `glow_without_composite_source` at ~25 200 excess channels and
`bevel_inner` at 47 419. Closing 75–93 % of a gap that starts at 10⁵–10⁶ still
leaves four orders of magnitude of budget.

**Re-cut of the filter family's residual, from the ledger above:**

* composition (inner/knockout/compositeSource) — **implemented, 0 flips**
* uniform aliasing + angle unit — **implemented, 0 flips**, but they were
  gating the two items above *and* the sibling's kernel
* what is left in the 12 improved comparisons is a **broad, low-amplitude**
  residual: for `glow`, 12 148 of 220 000 pixels differ, alpha is exact, and the
  error is concentrated on the *source's own* edges and in the mid-band of the
  glow ramp. That reads as shape-rasterisation/AA and blur-quantisation, not as
  another filter feature. It is a *shared* residual with the rest of the render
  gap, so filters are no longer a family with its own owner.
* the 4 inert comparisons are sprite-nested (leftover B, arc-adjacent) and CPU
  `applyFilter` (leftover C).

**Recommendation:** the correct claim for the closeout is "filters: correct
mechanism, 0 flips, −41 %…−93 % on 12 comparisons, two engine-wide bugs fixed" —
and the filter *family* should be struck from the feature-priority map's
flip-bearing leads. The two engine bugs (§3A, §3B) are worth carrying forward on
their own merits: they affect every filter in every game, not just the corpus.

---

## 6. Risks

* **The uniform ring is the load-bearing change and it is engine-wide.** Any
  filtered or blurred draw in any content now reads its own uniform slot. The
  canary evidence (25 comparisons md5-identical, including the blend-mode and
  mask canaries that share `composite_bgl`) is the guard. `blend_params_buf` is
  a separate permanently-zero buffer and was deliberately left alone.
* **Ring wrap.** >145 filtered objects in one frame wraps the cursor and the
  aliasing silently returns. No corpus test is near it; a filter-heavy game
  could be. A wrap counter + assert would be cheap insurance later.
* **The angle fix changes existing renders in games**, not just tests — every
  drop shadow and bevel with a non-zero angle moves to its correct direction.
  This is a correction, but it is visible.
* **`swf.cpp` is in the patch**, so applying it requires a cmake rebuild of the
  recompiler and `--recompile` on affected tests. The change is confined to
  gradient-glow / gradient-bevel `parsed_filter_flags`, which nothing read
  before; `cf.flags` (the `mc.filters` reflection path) is untouched, so no
  trace output can move.
* **Local-only grading.** Everything is our-render-vs-our-render plus
  our-render-vs-golden on local Dawn, not CI's lavapipe. The md5 canary
  invariant is the load-bearing claim; the excess-outlier deltas are
  directional.
* **Bevel is now a single-pass difference-of-blurs** (ruffle's formulation)
  rather than two independently tinted composites. That is a bigger behavioural
  change than the composition flags alone, and it is what the −83 %…−91 % bevel
  numbers rest on.

## 7. Reproduce

```bash
# in a worktree at f166e424e with w2-gfx-filters.patch applied and committed
cd SWFRecomp/build && cmake .. && make -j8      # swf.cpp is in the patch
DAWN_INSTALL=~/CC/dawn-install \
python3 ruffle-tests/render_canary.py capture --label before \
    --tests ruffle-tests/w2_gfx_filters_inner_canary.txt --jobs 4 --recompile
# apply w2-gfx-filters-inner.patch, rebuild the recompiler
DAWN_INSTALL=~/CC/dawn-install \
python3 ruffle-tests/render_canary.py capture --label after \
    --tests ruffle-tests/w2_gfx_filters_inner_canary.txt --jobs 4 --recompile
python3 ruffle-tests/render_canary.py compare before after
```
