# w2-gfx-blur — BlurFilter plumbing + dynamic-bitmap capacity + displacement rider

Session 15, wave 2 (implementation). Worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-af6bf853db68a2f68`,
baseline `42a324cef`, nothing committed. Briefs: `wave1-gfx-blur-morphratio.md`
§A (GO), plus the coordinator's rider from `wave1-gfx-displace-blend.md` §1.5 A1.

---

## 0. Headline

**Three flips, all measured end-to-end locally, all in families whose local
render reproduces CI exactly** (every before-leg number below is byte-identical
to `image_results_graphics.json` @ `bf585e448`, including 774 090 / 821 415 /
520 441 / 173 904 / 237 / 46 468 / 27 565).

| patch | file(s) | verdict |
|---|---|---|
| `w2-gfx-blur-plumb.patch` | `avm2_bitmap.c` | **GO — 2 flips** (needs the capacity patch for one of them) |
| `w2-gfx-blur-capacity.patch` | `render_webgpu.c` | **GO, but the briefed change is REFUTED and replaced** |
| `w2-gfx-displace-cpu.patch` (rider) | `avm2_bitmap.c`, `avm2_filters.{c,h}` | **GO — 1 flip, 0 outliers, half the tolerance** |
| stretch: AVM2 `.filters` render path | — | **NO-GO, scoped (§6)** |

### Expected-flip ledger for the merged CI run

| comparison | before | after | budget |
|---|---:|---:|---|
| `visual/filters/blur_fractional [output]` | fail 774 090, max 255 | **pass — 0 outliers, max 5** | tol 5 / 0 |
| `avm2/bitmapdata_filter_sourcerect [output]` | fail 20 252, max 255 | **pass — 1 603, max 255** | tol 5 / **1 700** |
| `visual/filters/displacement_map_through_applyFilter [output]` | fail 27 565, max 255 | **pass — 0 outliers, max 2** | tol 4 / 0 |
| `visual/filters/blur_quality [output]` | fail 821 415, max 255 | fail 166 986, **max 9** | tol 6 / 0 |
| `avm2/bitmapdata_applyfilter_blur [output]` | fail 520 441, mean 30.3 | fail **30 844**, mean 1.21 | tol 12 / 0 |
| `visual/filters/blur_pass_scaling [output]` | fail 173 904 | fail 105 534 | tol 3 / 0 |
| everything else in the canary set (39 of 43 comparisons) | — | **byte-identical** | — |

Net: **+3 comparisons**, −92 % outliers across the six touched rows
(2 337 116 → 304 967), zero trace-status changes, zero unexplained pixel moves.

**Watch on the merge run:** `avm2/bitmapdata_filter_sourcerect` passes with
1 603 of its 1 700 outlier budget (94 %). Its residual is a hard-edged
`fillRect` blur with no AA, so lavapipe-vs-Dawn drift should be nil — but it is
the one row here without headroom.

---

## 1. Item 1 — BlurFilter, and a kernel correction the wave-1 model missed

### 1.1 What shipped, and why CPU rather than the briefed GPU route

`avm2_bitmap.c::bd_apply_filter` gains an `AVM2_FILTER_BLUR` arm backed by a CPU
port of `render/wgpu/src/filters/blur.rs` + `shaders/filter/blur.wgsl`.

The wave-1 report preferred the GPU route (§2.4). I took the CPU one:

1. **Mode parity.** `applyFilter`'s result is script-observable through
   `getPixel`/`getPixels`/`compare`, so a GPU-only implementation makes
   `NO_GRAPHICS` and `graphics` disagree on *trace* output. Mode parity is
   complete across all suites today and is not worth spending on a pixel row.
2. `render_webgpu_run_blur` blurs the whole **stage-sized** offscreen at
   `texel = 1/ctx->width` into `filter_tex_a/b`. A BitmapData needs its own size
   and its own target, so the existing entry point cannot be reused unchanged —
   the "plumbing" would be a new pipeline path, an upload and a readback.
3. That stage-vs-object mismatch is trap 1 of the displacement report (§1.4).
   Both briefs land on it; §6 folds them into one board note.

### 1.2 The kernel — and two measured departures from `blur.wgsl`

The kernel is a symmetric fractional box: unit weights on taps `-m..+m`, the
quantized fraction `alpha` on taps `±(m+1)`, with `radius = (full_size-1)/2`,
`m = ceil(radius)-1`, `alpha = floor((radius-m)*255)/255`. That is algebraically
identical to blur.wgsl's three-bilinear-sample form and to the wave-1 model.

Graded against `blur_fractional`'s golden (100 tiles, tol 5, `max_outliers 0`)
over the whole variant space — python model, then re-verified with the actual C:

| alpha quantization | divide by | output rounding | outlier channels | max diff |
|---|---|---|---:|---:|
| floor(·255)/255 | `full_size` | floor | 48 | 6 |
| floor(·255)/255 | `full_size` | nearest | 27 | 6 |
| floor(·255)/255 | weight sum | floor | 48 | 6 |
| **floor(·255)/255** | **weight sum** | **nearest** | **0** | **5** |
| exact (no 1/255) | weight sum | nearest | 27 | 6 |

Row 1 is the literal `blur.wgsl` port — i.e. the wave-1 model, reproduced to the
channel (48, on tiles `blurX` 8.2 and 9.2). Row 4 is what shipped, and it is a
**pass** at the test's own tolerance. The C implementation reproduces the model
exactly on both tests (`scratchpad/w2gfxblur/ctest.c` grades the shipped kernel
standalone: 0 / max 5 and 166 986 / max 9), and the rendered test then
reproduces the C exactly (166 986 in the graded run) — model, kernel and render
agree to the channel.

**The departure is principled, not fitted.** Quantizing `alpha` down to 1/255
(which ruffle does deliberately, imitating FP's fixed-point weights) makes the
weights sum to slightly *less* than `full_size`, so dividing by `full_size`
shrinks a uniform field ~0.2 % per pass; dividing by the weights' own sum is
exactly energy-preserving. Flooring costs a further 0.5 level per pass. Both
biases **compound with the pass count** — which is precisely the shape of the
wave-1 §2.6 residual (`blur_quality`'s `quality ≥ 7` tiles fitted at
`0.9951·v + 1.02` per pass against the model's `0.9980·v − 0.5`). Note that
alpha's own 1/255 quantization must be **kept**: dropping it (row 5) is worse,
so the fixed-point imitation is real and only the normalization was wrong.

`blur_quality` is a **large band move, not a flip**, exactly as wave-1 priced it:
821 415 → 166 986, and max diff 255 → **9** against tolerance 6. None of the 12
variants closes the last 3 levels; §2.6's "build the ruffle exporter and dump an
intermediate pass" is still the way to settle it.

**The GPU path is untouched.** `render_webgpu.c::blur_box_kernel` stays a
faithful `blur.rs` port; it serves a different (SWF-authored PlaceObject) family
and nothing measured here says it is wrong there. The divergence is deliberate
and documented in the code comment.

### 1.3 Semantics taken from ruffle, not invented

- The blur target is the **source rect's own size** — `blur.rs` allocates its
  ping-pong at `source.size`; no filter grows the rect.
- A pass with `full_size <= 1` is **skipped**, not run as identity
  (`blur.rs:212 continue`).
- If **no** pass runs at all (quality 0, or both axes ≤ 1 texel), `apply()`
  returns `None` and `apply_filter` **leaves the destination untouched** — not
  the same as copying the source across. Implemented that way. (This is what
  makes `blur_quality`'s `quality = 0` column and `blur_fractional`'s row 0
  correct for free.)
- The **first** executed pass binds the whole **source texture**, not the
  rect-sized ping-pong, so its taps reach the real pixels around `sourceRect`,
  clamped at the bitmap's own edges; later passes clamp at the rect. This only
  bites when `sourceRect` is a strict sub-rect — i.e. exactly the two tests that
  pass one, and one of them (`bitmapdata_filter_sourcerect`) is a flip.
- Channels are blurred **premultiplied**, matching our storage *and* ruffle's
  (`bitmap_data.rs:734` stores premultiplied; the texture upload is those bytes).

### 1.4 Blast radius — enumerated, not estimated

`bd_apply_filter` is AVM2-only. Every corpus test that reaches it
(`grep -rl applyFilter --include=*.as`), with the measured outcome:

| test | filter kinds | outcome |
|---|---|---|
| `visual/filters/blur_fractional` | Blur | **flip** |
| `avm2/bitmapdata_filter_sourcerect` | Blur + ColorMatrix | **flip** |
| `visual/filters/displacement_map_through_applyFilter` | Displacement | **flip** (item 3) |
| `visual/filters/blur_quality` | Blur | band −80 % |
| `avm2/bitmapdata_applyfilter_blur` | Blur | band −94 % |
| `visual/filters/blur_pass_scaling` | Blur (rows 1–2 of 4) | band −39 % |
| `avm2/bitmapdata_applyfilter_colormatrix` | ColorMatrix | untouched arm — **verified byte-identical** |
| `avm2/bitmapdata_applyfilter_destpoint` | ColorMatrix | **verified byte-identical** (0 outliers both legs) |
| `visual/cache_as_bitmap/bitmap_changed`, `avm2/filters_array_holes`, `avm2/bitmapdata_applyfilter_destpoint_edges` | ColorMatrix / gradient | untouched arm |
| `avm2/pixelbender_effect_glassDisplace_shaderfilter` | Shader | untouched arm |

### 1.5 Where `avm2/bitmapdata_applyfilter_blur`'s residual actually lives

Not the blur. Its `createSource()` does `src.draw(text, mat)` with a
`TextField` at `y = SOURCE_HEIGHT/2 - 20`, and the test.toml already says
*"TODO Fix this test. It shouldn't depend on the default font"* /
`with_default_font = true`. In the **unfiltered source copy** (cell 0, which no
filter ever touches) all 534 residual outlier pixels sit in `y ∈ [96, 104]` —
the text band, and nowhere else. The five filtered copies are blurred versions
of that same source, so the font mismatch smears into each of them. The
remaining 30 844 outliers are owned by device-font rasterization, and no amount
of blur work will move them.

---

## 2. Item 2 — capacity: the briefed change is refuted, and replaced

### 2.1 Refutation

Wave-1 §2.8 priced "lift `MAX_DYNAMIC_BITMAPS` to 128, one constant", with the
blast radius argued from `maxTextureArrayLayers`. **That constant is not one
constant.** It is the layer count of the *shared static+dynamic* bitmap texture
array, every layer of which is a full `max(bitmap_highest, dynamic_bitmap_max)+1`
square:

```
VRAM = bw · bh · 4 · (bitmap_count + capacity)
```

so a flat 64 → 128 **doubles the bitmap VRAM of every graphics test**, not just
the two that truncate:

| movie | layer dim | at cap 64 | at a flat cap 128 |
|---|---|---:|---:|
| `visual/filters/blur_*` (stage 800², one 80² image) | 801² | 167 MB | 331 MB |
| `from_shumway/acid/acid-color` (1840² embedded) | 1841² | **881 MB — passes today** | **1.73 GB** |
| `from_shumway/acid/acid-large` (3612×2680) | 3613×2681 | 2.52 GB — already OOM | 5.03 GB |

Board P3 measured the practical lavapipe ceiling as "between 0.9 GB and 2.5 GB"
(acid-color passes, acid-large OOMs). A flat raise puts a **currently-passing**
test inside that unknown window. That is the "a past capacity raise un-truncated
our own excess ink" concern in a worse form: not wrong ink, a lost render.

### 2.2 What shipped

64 stays the **floor**; growth to 128 happens only while the array stays under a
byte budget (`plan_dynamic_bitmaps()`, shared by `create_buffers_and_upload` and
`create_textures` — they are different functions and must agree):

```c
#define MAX_DYNAMIC_BITMAPS        64                        /* unchanged floor */
#define MAX_DYNAMIC_BITMAPS_GROWN  128                       /* ceiling         */
#define DYNAMIC_BITMAP_VRAM_BUDGET ((size_t)384*1024*1024)
#define MAX_BITMAP_TEXTURE_LAYERS  256
```

`capacity = clamp(BUDGET/layer_bytes − bitmap_count, 64, 128)`, further clamped
so `bitmap_count + capacity ≤ 256`, never below 64.

**Why the bit-identical argument survives.** The constant is consulted only
through `dynamic_bitmap_used >= dynamic_bitmap_capacity`, and slot indices stay
`base + used`. Capacity never *decreases*, so every test issuing ≤ 64 dynamic
bitmap draws per frame is bit-identical, and every test that already truncated
can only gain slots. Under the budget the big-atlas movies keep exactly 64 —
bit-identical **including their allocation size**. Arithmetic: `acid-color`
gets `384 MB / 13.55 MB = 29 < 64` → stays 64; `acid-large` gets
`384 MB / 38.7 MB = 10 < 64` → stays 64; the blur grids get 128 for 331 MB.

**VRAM tripwire, measured:** `from_shumway/acid/acid-color` (the 881 MB movie)
**passes both comparisons with the patch applied** — `[output]` 0 outliers max
3, `[frame1]` 0 outliers max 2. `acid-large` is unchanged by construction (its
capacity is provably still 64, so the allocation is byte-for-byte the one it
already OOMs on — this patch neither helps nor hurts it; board P3's decoupling
redesign is still the item that unblocks it).

### 2.3 Who actually truncates — three independent methods

**(a) The shipped one-shot warning.** Both capacity returns
(`render_webgpu.c` `draw_bitmap_quad_scaled` / `draw_bitmap_tris`) now call
`dynamic_bitmap_capacity_hit()`, env-gated on `SWF_WARN_BITMAP_CAP` so it can
never pollute captured output. Demonstrated by forcing the budget to 0 (capacity
pinned at the 64 floor) and running the built binaries directly:

```
visual/filters/blur_fractional   -> [render] dynamic bitmap capacity 64 exhausted (layer 801x801);
                                    further bitmap draws this frame are dropped
visual/filters/blur_pass_scaling -> (silent — 40 bitmaps, no truncation)
```

This is the instrument the board wanted: the drop is otherwise **silent**, which
is why it read as "structural extra ink" for a whole session.

**(b) The canary A/B is itself the enumeration.** 39 of 43 comparisons are
byte-identical before→after with both patches applied. A test that had been
truncating would necessarily move. So over the 26-test canary set, the
truncating set is exactly `{blur_fractional, blur_quality}`.

**(c) Static scan** (`scratchpad/w2gfxblur/scan_bitmaps.py`) over all 124
bitmap-using tests carrying `[image_comparisons]`, ranking by the loop bounds
around each `new BitmapData` / `new Bitmap` / `attachBitmap` /
`beginBitmapFill`. Only two can plausibly exceed 64 runtime bitmaps per frame:
`blur_fractional` and `blur_quality` (10×10 = 100). Next down:
`blur_pass_scaling` 40, `avm2/bitmapdata_applyfilter_*` ≤ 24, the displacement
trio 11, `regression/avm2_graphics_runtime` 1,
`avm2/displayobject_hittestpoint_boundary` 1 — all far under. Independent
corroboration of wave-1's "the two grid tests are the only ones found so far".

Caveat, stated rather than hidden: the scan only sees tests that ship
ActionScript sources, so `.swf`-only tests (much of the AVM1 mirror) are
invisible to it, and `beginBitmapFill` shapes reach the same capacity through
`render_webgpu_draw_bitmap_tris`. Method (a) plus the merged CI run is the
backstop.

### 2.4 Attribution — the two patches are not independent

| leg | `blur_fractional` | `blur_quality` |
|---|---:|---:|
| baseline (= CI) | 774 090 | 821 415 |
| **item 1 only** (blur, capacity still 64) | 669 504 | 681 369 |
| **items 1 + 2** | **0 — PASS** | 166 986 |

The blur patch alone buys −13 % on `blur_fractional`, because 36 of its 100
tiles are still blank. **The flip requires both patches.** Merging one without
the other gets a band move and no comparison.

---

## 3. Item 3 — DisplacementMapFilter rider (accepted)

`w2-gfx-displace-cpu.patch`, applied on top of item 1. Route 1 of the
displacement report, ~130 lines in the same function plus a 7-line accessor.

**Result: `visual/filters/displacement_map_through_applyFilter [output]`
27 565 → 0 outliers, max diff 2 against tolerance 4 — a flip with half the
budget spare.** Its byte-identical twin `displacement_map_through_filters` goes
through route 2 (the missing AVM2 render-time filter stage) and is unchanged.

The pass follows `displacement_map.wgsl` exactly, at `viewscale = 1`:
`source_pos = uv · source_size` where `uv` interpolates across the source rect
inside the **whole** source texture (`FilterSource::vertices`), so `source_pos`
is the absolute source pixel + 0.5; the map is sampled NEAREST + ClampToEdge; a
`map_uv` outside 0..1 reads the neutral `vec4(0.5)` = **127.5**, a half level,
which at `scale = 200` is a real −0.39 px shift and not the same as 128; the
displaced coordinate is sampled BILINEAR with **Repeat** over the whole source
texture; and the bilinear result is rounded the way an `Rgba8Unorm` target
rounds. All four modes (wrap/clamp/ignore/color) and all four channel selectors
are implemented, though only wrap/RED/GREEN are graded.

**One correction to the displacement report.** Its trap 3 says "our BitmapData
store is premultiplied; the shader reads raw channel values as displacement
magnitudes, so a map with alpha < 255 will displace wrongly unless
unpremultiplied first." Ruffle's `BitmapData` pixels are premultiplied **too**
(`bitmap_data.rs:734`) and its texture upload is those same bytes, so the shader
also sees premultiplied values. Un-multiplying would *introduce* a divergence.
The shipped code reads the map as stored, and the test lands at 0 outliers.

The map bitmap needed a new accessor: `Avm2FilterVal` deliberately drops
`mapBitmap` (it round-trips to null, like ruffle), so
`avm2_filter_map_bitmap(ctx, obj)` reads it off the AS filter object.

---

## 4. Canary

`ruffle-tests/render_canary.py` over the full standing set plus the four blur
tests (26 tests / 43 comparisons), `-P 2`, both legs local Dawn:

```
IDENTICAL 39   DIFFERS 4   APPEARED 0   VANISHED 0   NO_RENDER 0
DIFFERS: avm2/bitmapdata_applyfilter_blur, visual/filters/blur_fractional,
         visual/filters/blur_pass_scaling, visual/filters/blur_quality
TRACE STATUS CHANGES: (none)
IMAGE STATUS CHANGES: visual/filters/blur_fractional  fail -> pass
```

Partition, declared in advance and confirmed:

- **expected-changed (4):** the blur family, all of which call
  `applyFilter(BlurFilter)`.
- **must-be-identical (39):** everything else — including
  `avm1/bitmapdata_applyfilter_colormatrix` (the ColorMatrix arm),
  `visual/filters/color_matrix` and `drop_shadow` (still 237 / 46 468, unmoved),
  all four `regression/` tests, both mask tests, gradients, blend modes,
  cacheAsBitmap and the timeline suites. All byte-identical.

Plus, outside the standing set: `bitmapdata_applyfilter_destpoint` byte-identical
both legs; `acid-color` (VRAM tripwire) passing; `bitmapdata_filter_sourcerect`
and `displacement_map_through_applyFilter` captured before/after as their own
legs (§0 ledger).

Build hygiene: the first before-leg was **discarded and re-captured** because an
edit landed mid-capture (false-negative mode 3). The delivered before-leg was
captured on a clean tree, `--recompile`, and its numbers match CI to the channel.

---

## 5. Patches

| file | scope | lines |
|---|---|---:|
| `w2-gfx-blur-plumb.patch` | `SWFModernRuntime/src/avm2/avm2_bitmap.c` | +225 / −7 |
| `w2-gfx-blur-capacity.patch` | `SWFModernRuntime/src/rendering/render_webgpu.c` | +100 / −20 |
| `w2-gfx-displace-cpu.patch` | `avm2_bitmap.c`, `avm2_filters.c`, `avm2_filters.h` | +153 / −7 |

Apply in that order from `42a324cef`; verified by a full revert → re-apply →
md5 round-trip. Runtime-only, no recompiler change, no new renderer API, no new
pipeline (so the `MSAA_SAMPLES` invariant is not engaged), no `render_stub.c`
twin needed. Item 1 and item 3 are pure CPU and therefore identical in
`NO_GRAPHICS` and `graphics` builds; item 2 is graphics-only.

Sibling-collision check: no overlap with `w2-gfx-flatten` (`swf.cpp`),
`w2-gfx-smalls` (`capture.c` / `tag.c:12013` / `swf.cpp:1854`) or
`w2-morph-legb` (morph stream code). `avm2_filters.{c,h}` is a new file pair for
this session's edits; the additions are one function and one declaration,
appended at stable anchors.

---

## 6. Stretch — AVM2 `DisplayObject.filters` has no render path (merged scoping note)

**Verdict: NO-GO for a wave-2 leg.** This is the same arc the displacement
report adjudicated as Route 2 / A2, and scoping it from the blur side agrees.

Confirmed independently: `avm2_display.c` stores filters (`store_filters`,
`do_set_filters`, `avm2_display_apply_tag_filters`, GC-marks them, lets a
non-empty list force `cacheAsBitmap`) and **no renderer call ever reads
`ext->filters`**. Stronger than "no filter arm on `avm2_render_node`": the AVM2
render walk has **no offscreen/composite infrastructure at all** —
`renderer_suspend_pass`, `renderer_begin_offscreen_pass`,
`renderer_capture_backdrop`, `renderer_composite_blend`,
`renderer_composite_filtered` and `renderer_snapshot_filter_source` are called
*only* from `tag.c`. So the missing piece is the whole offscreen stage, plus a
"render this subtree alone" entry point, plus `tag.c::render_filtered_object`'s
~150 lines of composition-flag logic (inner / knockout / composite / on-top, per
filter kind), plus a per-kind pipeline for the kinds `tag.c` does not have
(displacement has no `filter_type` at all).

Five traps any implementer inherits — traps 1–4 are the displacement report's
§1.4, and they apply to blur/glow/bevel identically:

1. **Our filter textures are stage-sized; ruffle's `FilterSource` is
   object-sized.** `filter_tex_a/b` and `renderer_run_blur`'s
   `texel = 1/ctx->width` cover the whole stage. Displacement's wrap/clamp modes
   are defined *relative to the source rect*, so a naive stage-sized port
   **wraps around the stage**. Blur is gentler (ClampToEdge at the stage edge
   rather than the object edge) but is still wrong at object borders, and it is
   the reason item 1 above went to the CPU instead of reusing the GPU kernel.
2. **A map/source BitmapData has to reach the GPU** — today only the static
   array plus the dynamic slots exist, and item 2 is the thing gating how many.
3. **Premultiplication — but the report's trap 3 is inverted.** Ruffle's
   BitmapData textures are premultiplied like ours, so the correct move is to
   **match** and *not* un-multiply. Measured: 0 outliers with raw premultiplied
   channels (§3).
4. **A CPU shortcut does not cover `*_scales_with_screen`**: filtering at 1× and
   upscaling ≠ filtering in 2× screen space. `blur.rs::scale_blur` and our
   `stage_scale` already encode this for the AVM1 path.
5. `MSAA_SAMPLES`, never a literal 4, in any new `render_webgpu.c` pipeline.

Ownership: this stage is the shared prerequisite for the failing
`visual/filters/*` family, `blur_pass_scaling` rows 3–4, and
`displacement_map_through_filters` / `_scales_with_screen`. As of this session
the CPU `applyFilter` route has **three** implemented filters (ColorMatrix,
Blur, DisplacementMap) and three of its rows pass, which sharpens the earlier
observation that the family's only near-pass was the one CPU row: the split is
by *route*, not by filter kind.

---

## 7. Board corrections

1. **Playbook §13 / wave-1 §2.8 item 1** — strike "lift `MAX_DYNAMIC_BITMAPS` to
   128 (one constant)". It is the shared bitmap texture array's layer count;
   a flat raise doubles VRAM corpus-wide and puts the currently-passing
   `acid-color` at 1.73 GB. Replace with the budgeted floor-64/ceiling-128 form
   that shipped.
2. **Wave-1 §2.5 / §2.6** — the literal `blur.wgsl` port is not the best
   available kernel. Normalizing by the quantized weights' own sum and rounding
   to nearest (instead of `full_size` + floor) removes two per-pass biases and
   takes `blur_fractional` from 48 residual channels to **0**. `blur_quality`'s
   remaining 3 levels are still open and still want the ruffle-exporter dump.
3. **Wave-1 §2.7 / displacement §1.3** — `bd_apply_filter` now implements
   ColorMatrix, Blur and DisplacementMap. The remaining `applyFilter` no-ops are
   the shadow/glow/bevel/convolution/shader kinds.
4. **Displacement report trap 3** — inverted; see §3.
5. **New**: `avm2/bitmapdata_applyfilter_blur`'s residual is **device-font text
   rasterization**, not filtering (§1.5). It cannot pass until the default-font
   raster matches, which the test's own toml already flags.
6. **New**: `avm2/bitmapdata_filter_sourcerect` and
   `visual/filters/displacement_map_through_applyFilter` join
   `blur_fractional`/`blur_quality`/`blur_pass_scaling`/`bitmapdata_applyfilter_blur`
   as the CPU-`applyFilter` cluster on the pixel board; they move together and
   should be clustered together.
