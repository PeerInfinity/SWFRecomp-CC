# w1-gfx-vram — the dynamic-layer budgeting arc (`acid-large` OOM)

Session 16, wave 1 (read-only diagnosis). Baseline `cd04f80b9`; grading run
`31748059158` at `3db858cbc`. Nothing edited in the main tree; all experiments
ran in a scratch worktree
(`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w1-gfx-vram`, instrumentation
only, NOT a deliverable patch) against copied test dirs under the scratchpad.

---

## 0. Headline — verdicts and priced flips

| item | verdict | flips |
|---|---|---|
| **A. VRAM budgeting fix** (cap the bitmap texture array under the driver's 2 GiB per-allocation limit) | **GO — cheap, ~15 lines, `render_webgpu.c` only, provably zero pixel blast radius** | **0 by itself** (status change only: `no_render` → `fail`, 139 500 excess outliers) |
| **B. Per-fill bitmap smoothing** (honour the SWF fill-style smoothing bit → linear sampler) | **GO as a rider, and it is REQUIRED for the flip** | **+1: `from_shumway/acid/acid-large [output]` PASSES** (measured: 0 outliers, max diff 3, budget tol 11 / max_outliers 0) |
| A + B together | **GO** | **+1 comparison** (`acid-large [output]`), plus band headroom on `acid-bitmap-fill` |
| **Global** linear sampler (the naive form of B) | **REFUTED** | would REGRESS `acid/acid-blend [output]` pass → fail (101 → 1961 outliers, limit 348) |
| Decoupling static/dynamic texture arrays (board P3's redesign as written) | **GO but UNNECESSARY for the flip; defer** | 0 flips; 3.9 GB of corpus VRAM hygiene, needs a WGSL change |

**The briefed premise is half right and half wrong.** The 2.52 GB OOM is exactly
as described and is trivially fixable. But **fixing it does not flip the test** —
`acid-large` then renders and fails on pixels. The flip is owned by a *second,
unrelated* defect (the bitmap sampler is `Nearest` for a `0x41 clipped bitmap,
**smoothed**` fill). Both are measured below end to end.

**Other VRAM/capacity-exhaustion rows: there are none.** Over the 570 rows in
run `31748059158`'s merged `image_results_graphics.json` files (324 pass / 243
fail / 3 skip) the failure-reason histogram is
`pixel_mismatch 242 / no_expected_image 3 / no_render 1`. `acid-large [output]`
is the ONLY `no_render` in the corpus and there is no `blank_render` bucket.
**`acid-large` has exactly 1 comparison, so the whole arc's ceiling is +1.**

---

## 1. Reproduction and the exact allocation breakdown

`from_shumway/acid/acid-large` reproduces locally, byte-for-byte with CI:

```
Warning: ../src/gallium/frontends/lavapipe/lvp_device.c:2428: VK_ERROR_OUT_OF_DEVICE_MEMORY
render_webgpu_save_png: buffer map failed (status 4)
[capture] Failed to save .../output.png
```

The movie (parsed from `test.swf`): **AVM1** — 587 frames, stage 550×400, ZERO
`DoABC`, ZERO `DoAction`; one `DefineBits` (id 1) of **3612×2680** behind a
`DefineShape` whose fill is `0x41 = clipped bitmap, smoothed` with fill matrix
scale 3.076 twips/texel; 587 `PlaceObject2` matrices zoom the sprite from
1.230× to 6.774×.

Every GPU allocation the run makes (instrumented `create_buffer` /
`wgpuDeviceCreateTexture`, `SWF_VRAM_LOG=1`):

| allocation | dims | bytes | MB |
|---|---|---:|---:|
| `offscreen_target` | 550×400×1 | 880 000 | 0.84 |
| `readback_buffer` | 550×400 (256-aligned rows) | 921 600 | 0.88 |
| `dummy_tex` | 1×1×1 | 4 | 0.00 |
| `vertex_buffer` | — | 4 194 400 | 4.00 |
| `xform_buffer` | — | 299 840 | 0.29 |
| `color_buffer` | — | 65 552 | 0.06 |
| `uninv_mat_buffer` / `inv_mat_buffer` | — | 8 320 ×2 | 0.02 |
| `bitmap_sizes_buffer` | — | 1 040 | 0.00 |
| `cxform_buffer` | — | 20 560 | 0.02 |
| 6 × small uniforms | — | 400 | 0.00 |
| `gradient_tex` | 256×64×1 | 65 536 | 0.06 |
| **`bitmap_tex`** | **3613×2681×65** | **2 518 477 780** | **2401.81** |
| `msaa_texture` | 550×400×1, 1 sample (`quality="low"`) | 880 000 | 0.84 |
| `depth_stencil` | 550×400×1 | 1 100 000 | 1.05 |
| **total** | | **2 525 004 172** | **2409.86** |

**99.7 % of the run's VRAM is one texture, and 98.5 % of that texture is dead
weight.** `bitmap_tex` is a single `texture_2d_array` shared by static and
dynamic bitmaps, every layer padded to
`max(bitmap_highest, dynamic_bitmap_max)+1` square:

```
VRAM = bw · bh · 4 · (bitmap_count + dynamic_bitmap_capacity)
     = 3613 · 2681 · 4 · (1 + 64)          // 36.95 MB per layer
```

The 64 dynamic layers cost **2.36 GB**. **`acid-large` uses ZERO of them**:
instrumented `max(dynamic_bitmap_used)` over all 501 rendered frames is `0`
(it has no ActionScript at all — nothing can reach
`render_webgpu_draw_bitmap_quad_scaled` / `_tris`).

### 1.1 The ceiling is a fixed 2 GiB driver limit, not host RAM

Sweeping the dynamic capacity on the real binary (host had 6–9 GB free
throughout):

| cap | `bitmap_tex` bytes | GiB | result |
|---:|---:|---:|---|
| 0 | 38 745 812 | 0.036 | renders |
| 1 | 77 491 624 | 0.072 | renders |
| 10 | 426 203 932 | 0.397 | renders |
| 20 | 813 662 052 | 0.758 | renders |
| 30 | 1 201 120 172 | 1.119 | renders |
| 40 | 1 588 578 292 | 1.479 | renders |
| 50 | 1 976 036 412 | 1.840 | renders |
| **53** | 2 092 273 848 | 1.949 | renders |
| **54** | 2 131 019 660 | **1.985** | **renders** |
| **55** | 2 169 765 472 | **2.021** | **OOM** |
| 60 | 2 363 494 532 | 2.201 | OOM |
| 64 (today) | 2 518 477 780 | 2.346 | OOM |

The boundary sits exactly on **2 GiB = 2 147 483 648 B** — Mesa lavapipe's
`maxMemoryAllocationSize`. It is a driver constant, independent of how much RAM
the box has.

---

## 2. Which side can I prove? — local vs CI

**Both sides, and they are the same side.**

- `verify_output.py` forces `VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json`
  on every graphics run (`verify_output.py:4113-4114`), so a local
  `--mode=graphics` run uses **the same lavapipe software Vulkan as CI**. The
  usual "never grade a local render against a golden" caveat is about *local
  Dawn on a real adapter*; it does not apply to this configuration, and I
  verified that empirically:

  | test | CI (`31748059158`) | my local leg |
  |---|---|---|
  | `acid/acid-blend [output]` | pass, 101 outliers / limit 348 | pass, **101** / 348 |
  | `acid/acid-bitmap-fill [output]` | pass, 67 908 / 70 000 | pass, **67 908** / 70 000 |
  | `acid/acid-color [output]` | pass, 0 outliers, max 3 | pass, 0, max **3** |
  | `acid/acid-color [frame1]` | pass, 0 outliers, max 2 | pass, 0, max **2** |
  | `acid/acid-large [output]` | **no_render** | **no_render**, identical stderr |

- The 2 GiB ceiling is a lavapipe constant, so CI's runner memory is irrelevant
  to the verdict. Both sides fail for the same reason at the same threshold.

CI-side confirmation from the results branch:
`from_shumway/_results/image_results_graphics.json` →
`{"test": "acid/acid-large", "comparison": "output", "trace_status": "pass",
"status": "fail", "message": "No actual image produced for output",
"reason": "no_render"}` — and it is the only such row in the corpus.

---

## 3. The whole-corpus allocation audit (383 tests with image comparisons)

`bw·bh·4·(bitmap_count+64)` computed from each `test.swf` (embedded-bitmap
inventory + stage rect + AVM detection, reproducing
`avm2_display.c:15810-15816`'s `dynamic_bitmap_max` rule and `swf.c:1644-1676`'s
AVM1 rule):

| test | AVM | static bmps | highest | dyn max | layer MB | array MB |
|---|---|---:|---|---|---:|---:|
| `from_shumway/acid/acid-large` | AVM1 | 1 | 3612×2680 | 256 | 36.95 | **2401.8 — OOM** |
| `from_shumway/acid/acid-color` | AVM2 | 1 | 1840×1840 | 1840 | 12.93 | 840.4 (passes) |
| `from_shumway/acid/acid-blend` | AVM1 | 1 | 2048×1536 | 256 | 12.01 | 780.9 (passes) |
| `from_shumway/acid/acid-blend-2` | AVM1 | 1 | 2048×1536 | 256 | 12.01 | 780.9 (passes) |
| `from_shumway/acid/acid-big` | AVM2 | 1 | 2080×1100 | 2080 | 8.74 | 568.1 (passes) |
| `avm2/stage3d_blend` | AVM2 | 0 | — | 1300 | 6.46 | 413.2 |
| `avm2/pixelbender_dithering` | AVM2 | 1 | 900×600 | 1280 | 6.26 | 406.9 |
| `from_shumway/acid/acid-shapes(-testing)` | AVM2 | 0 | — | 1028 | 4.04 | 258.5 |
| …230 more | | | | | | ≤ 256 MB |

Corpus sum 22.68 GB of nominal array allocation; **one test breaches 2 GiB, and
the runner-up is 2.9× below it.** This is the number that makes option A safe.

---

## 4. Design

### 4.1 Option A — clamp the array under the driver limit (RECOMMENDED for s16)

`plan_dynamic_bitmaps()` (added s15, `render_webgpu.c:1026`) already computes
`capacity = clamp(BUDGET/layer_bytes − bitmap_count, 64, 128)` and refuses to go
below the 64 floor. Add a *hard* ceiling that only ever fires when the array
would otherwise breach the allocator:

```c
// A single texture allocation must fit the driver's maxMemoryAllocationSize.
// Mesa lavapipe (CI + local graphics runs) reports exactly 2 GiB; measured
// boundary: 2 131 019 660 B allocates, 2 169 765 472 B returns
// VK_ERROR_OUT_OF_DEVICE_MEMORY and Dawn then drops every command buffer that
// binds the texture (whole run reads back empty -> no_render).
#define BITMAP_ARRAY_HARD_LIMIT ((size_t)1536 * 1024 * 1024)   /* 1.5 GiB, 25% headroom */
...
size_t affordable_layers = BITMAP_ARRAY_HARD_LIMIT / layer_bytes;
if (affordable_layers > (size_t)ctx->bitmap_count) {
        size_t room = affordable_layers - (size_t)ctx->bitmap_count;
        if ((size_t)cap > room) cap = (u32)room;    /* may go BELOW the 64 floor */
} else {
        cap = 1;                                    /* pathological: static alone breaches */
}
```

- Placed **after** the existing floor clamp, so it is the only path that can
  lower capacity below 64.
- `acid-large`: `1.5 GiB / 36.95 MB = 41` → cap 40, array 1.48 GiB → renders.
  (A 384 MB budget instead gives cap 10 / 406 MB; both render. 1.5 GiB is the
  more conservative choice because it lowers capacity for *nothing else*.)
- Everything else in the corpus: `bitmap_count + 64` layers already fits under
  1.5 GiB (runner-up 840 MB), so **capacity is unchanged for 382 of 383 tests
  and every allocation is byte-identical**. The one test whose capacity changes
  provably issues 0 dynamic bitmap draws.
- Does **not** disturb s15's blur capacity behaviour: the blur grids have
  2.45 MB layers → `1.5 GiB / 2.45 MB = 626 ≫ 128`, so their grown cap of 128
  survives untouched.

**Cost:** ~15 lines in one function of `render_webgpu.c`. No shader change, no
new file, no recompiler change.

### 4.2 Option B (the rider that actually flips the test) — per-fill smoothing

`create_textures()` builds `bitmap_sampler` with
`magFilter = minFilter = WGPUFilterMode_Nearest` for **all** bitmap draws
(`render_webgpu.c:1325-1326`) — and `render_webgpu_draw_bitmap_tris()` takes a
`smooth` argument it discards (`render_webgpu.c:2657`, `(void)smooth; //
smoothing flag — sampler is currently fixed at linear` — the comment is also
factually stale: it is fixed at *nearest*). SWF fill styles carry the bit:
`0x40/0x41` smoothed, `0x42/0x43` non-smoothed (`SWFRecomp/include/swf.hpp:115-118`).

The recompiler currently **collapses all four** into one emitted value
(`SWFRecomp/src/swf.cpp:7625-7653`: `fill_styles[i].index = (uninv << 16) |
bitmap_id`), so the bit never reaches the runtime. Suggested plumbing (wave-2's
call): the low half of `style_id` is a bitmap id bounded by `bitmap_count`
(≤ 256 in practice), so **bit 15 of the low half is free** — emit smoothing
there, mask it off in the shader's layer index, and branch:

```wgsl
if ((style_id & 0x8000u) != 0u) { color = textureSampleLevel(bitmap_tex, bitmap_samp_linear, ...); }
else                            { color = textureSampleLevel(bitmap_tex, bitmap_samp_nearest, ...); }
```

(`textureSampleLevel` takes an explicit LOD, so no uniform-control-flow problem;
a second sampler is one extra binding in group 2.)

**Per-fill is mandatory — a global flip is refuted.** Measured A/B with the
sampler forced to Linear:

| test | fill style | base (= CI) | linear leg | verdict |
|---|---|---|---|---|
| `acid/acid-large [output]` | `0x41` **smoothed** | fail 139 500 outliers, max 80, mean 7.54 | **pass — 0 outliers, max 3, mean 0.226** | **flip** |
| `acid/acid-blend [output]` | `0x43` non-smoothed | pass 101 / 348 | **fail 1961 / 348** | **regression** |
| `acid/acid-bitmap-fill [output]` | `0x40`+`0x41` smoothed | pass 67 908 / 70 000 (97 % of budget) | pass **63 432** / 70 000 | band gain |
| `acid/acid-color-0 [output]` | `0x41` smoothed | fail 34 323 / limit 3 | fail **32 532** / 3 | band gain |
| `acid/acid-color [output]` / `[frame1]` | no bitmap fills | pass 0, max 3 / max 2 | pass 0, max **2** / max 2 | neutral |

Every "base" column above is byte-identical to run `31748059158`'s published
number, so these legs are CI's numbers, not a local dialect.
`acid/acid-bitmap-fill-2` (the other 96.5 %-of-budget row) was NOT graded — the
box was saturated by sibling agents; wave 2 must include it.

`acid-large`'s residual before B is not a geometry or timing error: the best
alignment is exactly `dx=dy=0` (shifting by ±1 px triples the mean error), alpha
is bit-identical, all three colour channels drift equally, and our render carries
**more** high-frequency energy than the golden (h-gradient 19.25 vs 14.40) — i.e.
point-sampling aliasing under a ~1.09× minification, precisely what a `Nearest`
sampler on a smoothed fill produces. With linear the h-gradient lands on
**14.42 vs the golden's 14.40**.

### 4.3 Option C — decouple static and dynamic arrays (board P3's redesign)

Two textures: static at `bitmap_highest+1`, dynamic at `dynamic_bitmap_max+1`;
shader branches on `layer >= dynamic_base`. Corpus effect **exactly 6 tests**
(the only ones where `bitmap_highest > dynamic_bitmap_max` — all AVM1):

| test | now | after C |
|---|---:|---:|
| `acid/acid-large` | 2401.8 MB | 53.1 MB |
| `acid/acid-blend` | 780.9 MB | 28.1 MB |
| `acid/acid-blend-2` | 780.9 MB | 28.1 MB |
| `acid/acid-bitmap-fill` | 65.3 MB | 17.1 MB |
| `acid/acid-bitmap-fill-2` | 65.3 MB | 17.1 MB |
| `acid/acid-color-0` | 62.2 MB | 17.1 MB |

Corpus total 22.68 GB → 18.78 GB. **It buys no flip that A does not**, it needs
a WGSL + bind-group change, and it changes the dynamic layers' *padded* dims,
which the shader divides UVs by (`bitmap_sizes[layer].zw`) — a real (if small)
pixel risk on exactly those 6 tests. It is also **worthless for AVM2**:
`avm2_display.c:15810-16` deliberately raises `dynamic_bitmap_max` to
`bitmap_highest`, so `acid-color` (840 MB) and `acid-big` (568 MB) do not shrink
by one byte. **Recommendation: defer**; revisit only if a browser title with a
huge atlas needs it.

### 4.4 Option D — lazy / evicting / tiered dynamic layers

Not motivated by any corpus row. Measured `max(dynamic_bitmap_used)` per frame,
instrumented over full runs:

| test | frames | max dynamic bitmap layers used | of capacity |
|---|---:|---:|---:|
| `acid/acid-large` | 501 | **0** | 64 |
| `acid/acid-blend` | 31 | **0** | 64 |
| `acid/acid-bitmap-fill` | 2 | **0** | 64 |
| `acid/acid-color-0` | 2 | **0** | 64 |
| `acid/acid-color` | 11 | **1** | 64 |

A capacity of 64 is ~64× the demand of every movie in this family. The only known ≥64 consumer is the s15 blur grid,
which option A leaves at 128. Park.

---

## 5. Pricing

| item | files / functions | lines | flips | risk |
|---|---|---:|---|---|
| **A** VRAM clamp | `SWFModernRuntime/src/rendering/render_webgpu.c` — `plan_dynamic_bitmaps()` only | ~15 | 0 (status `no_render`→`fail`) | **very low**: capacity changes for 1 of 383 tests, and that test uses 0 dynamic layers |
| **B** per-fill smoothing | `SWFRecomp/src/swf.cpp` (`parseFillStyles`, 2 sites ≈ 7237 / 7625), `render_webgpu.c` (`create_textures` + WGSL fragment + bind group 2), possibly `draw_bitmap_tris`'s dead `smooth` arg | ~60–90 | **+1** (`acid-large [output]`) + band gain on `acid-bitmap-fill` | **medium**: changes every *smoothed* bitmap fill in the corpus. Recompiler change ⇒ cmake rebuild + `--recompile`, and the canary's false-negative mode 1 (stale recompiler reports IDENTICAL everywhere) applies |
| C decouple arrays | `render_webgpu.c` + WGSL | ~80 | 0 | medium, deferred |

`acid-large` has **one** comparison (`[output]`, `tolerance = 11`,
`max_outliers = 0` by default — `test.toml` sets only the tolerance). A+B
delivers it with 0/0 outliers and max diff 3 against a tolerance of 11, i.e.
comfortable headroom, not a knife-edge pass.

**Ordering matters:** B alone cannot flip `acid-large` (it never renders), and A
alone cannot flip it either. Ship them together or the ledger reads as "+0 with
a new visible failure".

---

## 6. Canaries

- **Standing set:** `ruffle-tests/render_canary.py capture/compare` over
  `render_canary_tests.txt` (20 tests / 37 comparisons). For **A** the bar is
  **md5 IDENTICAL on all 37** — A cannot change any of them by construction
  (none has a >1.5 GiB array), so any DIFFERS is a bug in the patch.
- **Canary blind spot for B:** the standing set's bitmap members
  (`avm1/bitmap_data_fillrect`, `avm1/bitmapdata_applyfilter_colormatrix`) are
  *BitmapData* draws, not shape bitmap **fills**; the only bitmap-fill member is
  `from_shumway/acid/acid-blend-2`, and its fill is `0x43` **non**-smoothed. So
  **the canary cannot see a smoothed-fill regression.** Cover it explicitly with
  the acid bitmap-fill set below.
- **Acid-family md5 / band set to grade for B** (all currently CI-passing unless
  noted; local legs reproduce CI exactly for every one I ran):

  | test | comparisons | fill styles | current CI |
  |---|---|---|---|
  | `acid/acid-blend` | 1 | `0x43` | pass 101/348 — **must not move** |
  | `acid/acid-blend-2` | 5 | `0x43` | pass (canary member) — must not move |
  | `acid/acid-bitmap-fill` | 1 | `0x40`×7, `0x41`×2 | pass 67 908/70 000 — 97 % of budget, the most exposed row |
  | `acid/acid-bitmap-fill-2` | 1 | `0x41`×2 | pass 8 689/9 000 — 96.5 % of budget |
  | `acid/acid-color-0` | 1 | `0x41`×2 | fail 34 323 / limit 3 |
  | `acid/acid-large` | 1 | `0x41`×2 | no_render → target |
  | `acid/acid-image`, `acid/acid-big`, `acid/acid-bitmaps` | 1/1/2 | — | pass at 0 outliers; cheap tripwires |

---

## 7. Attacking the premise

1. **"acid-large OOM → the dynamic-layer budgeting arc" — the arc is real but
   one commit deep.** The fix is ~15 lines in a function s15 already wrote. It
   is not an arc; the *arc* is the smoothing defect it uncovers.
2. **"Is acid-large fixable at all under CI's memory?" — yes, and CI memory was
   never the constraint.** The wall is lavapipe's fixed 2 GiB
   `maxMemoryAllocationSize`, measured to the layer. Even the do-nothing
   allocation (`cap = 54`, 1.985 GiB) renders on the same box that fails at
   2.02 GiB with 6 GB of host RAM free.
3. **Disposition candidate? No.** It passes with the two fixes, measured, with
   8× tolerance headroom. There is nothing to disposition.
4. **The VRAM fix on its own is a trap for the ledger.** It converts the corpus's
   only `no_render` into a 139 500-outlier `pixel_mismatch`. On the pixel board
   that is a *new visible failure row* and 0 flips. If s16 ships A without B,
   say so in the closeout explicitly.
5. **Board P3's "decouple the arrays" redesign is over-scoped for the flip** and
   does nothing for the AVM2 half of the problem it was written about
   (`acid-color`/`acid-big` are unchanged by it). Refuted as the primary route,
   kept as hygiene.
6. **s15's "flat 64→128 raise is refuted because acid-color would hit 1.73 GB"
   holds, and now has an exact threshold**: 1.73 GB is *under* the 2 GiB wall,
   so the flat raise would probably not have OOMed acid-color — but it lands
   within 20 % of a hard driver limit on a movie that uses **1** dynamic layer.
   The budget was still the right call; the reasoning should cite the 2 GiB
   constant rather than an unknown "0.9–2.5 GB window".

## 8. NO-GO completion mechanisms

- **C (decoupled arrays) — HELD.** Flips to GO if a browser-target title (not a
  corpus test) needs >1.5 GiB of static bitmap atlas, or if the AVM2
  `dynamic_bitmap_max = bitmap_highest` rule is replaced by per-BitmapData
  sizing (which would also make C help AVM2).
- **D (lazy/tiered/evicting layers) — PARKED.** Flips to GO on evidence of any
  test needing >128 dynamic layers *and* layers >4 MB simultaneously; today the
  corpus max is 1 layer used out of 64.
- **Global linear sampler — DEAD**, refuted by `acid-blend` (pass → fail). Only
  the per-fill form is viable.

## 9. Reproduction recipe (for wave 2)

```bash
SP=<scratchpad>
cp -r ruffle-tests/tests/swfs/from_shumway/acid/acid-large $SP/tests/from_shumway/acid/
python3 ruffle-tests/verify_output.py --tests-dir=$SP/tests/from_shumway \
        --test=acid/acid-large --mode=graphics --images --recompile
# keep the build dir to run the binary directly:
SWF_KEEP_BUILD_DIR=$SP/bd python3 ruffle-tests/verify_output.py ... # then
cd $SP/bd && CAPTURE_TRIGGERS=output:last_frame CAPTURE_OUTPUT_DIR=$SP/bd \
  VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json \
  VK_DRIVER_FILES=/usr/share/vulkan/icd.d/lvp_icd.json ./test_run
```

Instrumentation used (scratch worktree only, not for merge): per-allocation
`vram_log()` on `create_buffer` + every `wgpuDeviceCreateTexture`; a
`SWF_DYNBMP_CAP` override inside `plan_dynamic_bitmaps()`; a per-frame
`max(dynamic_bitmap_used)` tracker reported at exit via `SWF_DYNBMP_REPORT`; and
a `SWF_BITMAP_LINEAR` switch on the `bitmap_sampler` filter mode. Worth
re-creating for wave 2 — the capacity override in particular turns a 7-minute
rebuild into a 20-second A/B.
