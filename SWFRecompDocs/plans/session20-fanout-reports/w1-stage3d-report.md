# w1-stage3d — Stage3D A′ (stencil / colorMask / blend) and B (textures), priced BY BUILDING

**Prototype patch (UNLANDED but complete and measured):**
`SWFRecompDocs/plans/session20-fanout-reports/w1-stage3d-ABprime-prototype.patch`
— 1 013 diff lines, **one file**: `SWFModernRuntime/src/avm2/avm2_stage3d.c` (+666 / −43).

**New files created by the prototype: NONE.** Everything lives inside the existing TU, so
there is nothing to add to `verify_output.py`'s explicit source list, `CMakeLists.txt` or the
Emscripten build, and nothing for the coordinator to stage by name beyond that one modified
file. Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w1-stage3d` (branch
`w1-stage3d-proto`, based on `574207007`). No commits, no pushes; no edits in the main tree.

Scratch: `<scratchpad>/w1-stage3d/` — run logs `run1..run7.log`, actual PNGs under
`p2_img/ … p7_img/`, `proto.patch` (the reverse-apply copy used for the A/B legs).

---

## 0. Verdicts, per comparison, MEASURED

Every "after" number is a local `--mode=graphics --images` run in the worktree with
`SWFRECOMP_COMPILE_TIMEOUT=2400`, sequential. "Before" is the CI image baseline
(run `34666689502` at `d8da5a18c`, i.e. already **post**-phase-A), re-read from
`<scratchpad>/image_triage.json`. Image comparisons never gate CI pass/fail; all of these
tests pass on trace before and after.

| # | comparison | phase | budget (tol / max_outliers) | before | **after (prototype)** | verdict |
|---|---|---|---|---|---|---|
| 1 | `avm2/stage3d_stencil` | **A′** stencil+colorMask | **0 / 0** | 651 150 | **0 outliers, max diff 0** | **GO — FLIP (exact match)** |
| 2 | `avm2/stage3d_blend` | **A′** blend only | 3 / 37 000 (alt 16 / 5 200) | 692 565 | **35 576, max 32** | **GO — FLIP** (margin 1 424 = 3.8 %) |
| 3 | `stage3d/unbound_texture` | **B** (binding rule only) | 1 / 0 | 118 800 | **0, max 0** | **GO — FLIP** *(misc group)* |
| 4 | `stage3d/unbound_texture_multiple` | **B** | 1 / 0 | 49 500 | **0, max 0** | **GO — FLIP** *(misc group)* |
| 5 | `stage3d/sampler_odd_size` | **B** | 1 / 782 | 7 854 | **0, max 1** | **GO — FLIP** *(misc group)* |
| 6 | `avm2/stage3d_sampler_partial_upload` | **B** | 1 / 782 | 5 010 | **0, max 1** | **GO — FLIP** |
| 7 | `avm2/stage3d_sampler` | **B** | 1 / 850 | 34 279 | **50** | **GO — FLIP** |
| 8 | `avm2/stage3d_ignore_sampler_override` | **B** | 8 / 1 935 | 191 769 | **6** | **GO — FLIP** |
| 9 | `avm2/stage3d_texture_bytearray` | **B′** ATF | 4 / **0** | 140 625 | 35 747 | **NO-GO for B. GO for B′** — everything but the ATF texture already matches (§5) |
| 10 | `avm2/stage3d_fractal` | **budget + device font**, NOT A′ | 2 / 100 | 1 101 100 | 1 101 100 @12 M; **29 620 @400 M**, of which **29 019 are the two device-font text bands and ≤ 8 channels are anything else** | **HOLD** — the Stage3D half is SOLVED; it needs (a) the cost budget raised and (b) s19's unlanded device-font arc |
| 11 | `avm2/stage3d_bitmap` | **B (done) + a timing/RNG mechanism + device font** | 4 / **24** | 85 764 | 136 587 | **NO-GO** — §4 |
| 12 | `avm2/stage3d_texture` | **RTT + device font** | 8 / 117 | 206 968 | 206 968 | **NO-GO** — §6 |
| 13 | `avm2/stage3d_raytrace` | C | 8 / 10 | 660 000 | 636 741 @400 M (17 s) | **NO-GO on the CPU route**, confirmed by measurement |
| 14 | `avm2/away3d_advanced_shallow_water_demo` | C | 30 / 400 | 1 331 566 | **TIMEOUT (30.17 s) — but ALSO 30.20 s with the patch REVERTED** on the same loaded box | **NO-GO**, and the local timeout is the box, not the patch: marginal cost measured at **+8 %** (§7.1-7.2) |

**Headline: 8 measured flips** (5 in `avm2` = visible to a normal `images=true` run at
`categories=all`; **3 in the `stage3d` suite = CI `misc` group, which only runs at
`categories=full`** — the grading run for this work MUST be `categories=full`).

**Phase-A no-regression, same runs** — every phase-A row re-graded at the delivered source:

| row | before this patch | after |
|---|---|---|
| `avm2/stage3d_triangle` | 0 / 0, max 1 PASS | **0 / 0, max 1 PASS** |
| `avm2/stage3d_multistage_triangle` | 0 / 0, max 1 PASS | **0 / 0, max 1 PASS** |
| `avm2/stage3d_agal_cross_product` | 0 / 10, max 1 PASS | **0 / 10, max 1 PASS** |
| `avm2/stage3d_rotating_cube` | 2 144 / 2 160 PASS | **2 148 / 2 160 PASS** (margin 12; see §7.3) |
| `stage3d/scissor_rectangle` | 0 / 0, max 1 PASS | **0 / 0, max 1 PASS** |

---

## 1. Premises attacked — three of the four inherited numbers are wrong

The playbook §18 ledger says: *"A′ stencil/colorMask (+2), B textures/RTT (up to 9), B′
ATF/DXT (2) … and `stage3d_bitmap` needs a SECOND mechanism."* Measured:

1. **REFUTED: "A′ = +2".** A′ flips **2**, but not the two that were named. `stage3d_stencil`
   is right; **`stage3d_fractal` is not an A′ row at all**. Its only A′ API call is
   `setColorMask(true,true,true,false)`, and since the composite is opaque
   (`bitmap_opaque`, `ColorWrites::COLOR` — the 3D alpha never reaches the stage) masking
   alpha has **exactly zero** visual effect. Fractal is a **cost-budget** row: its fragment
   program is 197 tokens over 800×600 for two frames ≈ 197 M budget units against the
   12 M cap, so it latches off before `present()` and composites the never-resolved
   all-black front buffer. Raise the budget and it renders (§3).
2. **REFUTED: `stage3d_blend` is "a B row, it needs G2 *and* G4's textures".**
   `avm2/stage3d_blend/Test.as` contains no `tex`, no `setTextureAt` and no texture of any
   kind — it is `m44` + per-vertex colours + `setBlendFactors`. It is a **pure A′ row**, it
   is the pixel board's largest Stage3D row (#17, 687 365 excess, 1 300 × 810), and it costs
   ~60 LOC. This is the single cheapest large row in the family and s19 mis-filed it.
3. **REFUTED: "B = up to 9, realistically 7".** B flips **6** (rows 3-8). Of the other three
   B candidates: `stage3d_texture_bytearray` is B′-only, `stage3d_texture` needs RTT **and**
   device fonts, and `stage3d_bitmap` needs neither (§4). **RTT flips nothing** — the only
   two rows that use `setRenderToTexture` are `stage3d_texture` (blocked by device fonts at
   `max_outliers` 117) and `away3d` (HOLD). Do not fund RTT for the corpus.
4. **CONFIRMED, and it is the strongest signal on the board:** the brief's reading of
   `same_geometry_wrong_fill` as "waiting on sampling alone" held for all five of its
   Stage3D rows. Every one of them flipped, four of them to ≤ 6 outliers.
5. **Bonus, not in any brief: two rasteriser defects that phase A's MSAA rows could not
   see.** Both are in §2.3 and both were found by `stage3d_stencil`'s tolerance-0 grading:
   the missing **top-left fill rule** (4 320 → 126 outliers) and the missing **subpixel
   snap** (126 → 0). They also improved two rows that were already passing
   (`ignore_sampler_override` 105 → 6, `sampler` 74 → 50).

---

## 2. What to build — the A′ plan, in wave-2-executable detail

All of it is inside `SWFModernRuntime/src/avm2/avm2_stage3d.c`; the prototype is the
reference implementation and can be applied verbatim. Ruffle line cites are against
`~/CC/ruffle` @ `f2aaf0703`.

### 2.1 Blend factors (~60 LOC) — flips `stage3d_blend`

* `S3dBackend` gains `uint8_t blend_src, blend_dst`, defaulting to
  `(S3D_BF_ONE, S3D_BF_ZERO)` = `BlendComponent::REPLACE` (`current_pipeline.rs:179`).
* `context3d_set_blend_factors` stops discarding its two validated strings and stores
  `s3d_enum_index(...)`.
* `s3d_blend_factor()` transliterates `mod.rs:1121-1162 convert_blend_factor`, whose one
  non-obvious rule is that each `Context3DBlendFactor` maps to a **pair**: the `*Color`
  factors degrade to the matching `*Alpha` factor **on the alpha channel only**. The
  operation is always `Add`.
* In the per-sample store: when the pair is not `(ONE, ZERO)`, read the destination, apply
  the two factors, `src*fs + dst*fd`, clamp.

### 2.2 The quantise-at-store change (~10 LOC) — a prerequisite for 2.1

The render target is `Rgba8Unorm` (`mod.rs:203`), so the destination a GPU blends against is
the stored **byte**, not a float. Phase A kept raw floats in the sample buffer and quantised
only at resolve. Add `s3d_quant(v) = round(clamp(v,0,1)*255)/255` and apply it to every
value written to the colour buffer. This is **idempotent with the existing resolve**
(`round(k/255 * 255) == k` in float32 for all k ≤ 255), which is why all five phase-A rows
are byte-identical after it — verified, not assumed.

### 2.3 The two rasteriser fixes (~25 LOC) — both required for `stage3d_stencil`

* **Top-left fill rule.** Phase A used a strict `e > 0` on all three edges. `stage3d_stencil`
  draws axis-aligned quads as two triangles sharing a diagonal that runs exactly through
  pixel centres, and with a strict test **neither** triangle owns those samples: a 1-px black
  diagonal through every quad, 1 920 px, at tolerance 0. With the winding normalised by
  `sign`, an edge is *top* when it is horizontal and runs leftwards (`dy == 0 && dx < 0`) and
  *left* when it runs downwards (`dy > 0`); a sample with `e == 0` is covered iff its edge is
  one of those. Because the two triangles compute the shared edge from bit-identical
  endpoints, their edge functions are exact negations, so exactly one of them owns each
  sample. **4 320 → 126 outliers.**
* **Subpixel snap.** A real rasteriser quantises vertex positions to a fixed-point grid
  before the edge functions (Vulkan requires ≥ 8 subpixel bits; D3D11 mandates exactly 8),
  and lavapipe — which produced the upstream goldens — is no exception. Without it an edge
  that should land on `x = 240.0` lands on `240.0000038`, the `e == 0` case never fires, and
  81 diagonal pixels stay wrong. `sx = round(sx*256)/256`, same for `sy`. **126 → 0.**

### 2.4 Stencil + colour mask (~120 LOC) — flips `stage3d_stencil`

* `S3dBackend` gains `uint8_t* stencil` (w·h·samples, allocated **only** when
  `configureBackBuffer(..., enableDepthAndStencil = true)` — it shares the
  `Depth24PlusStencil8` attachment's lifetime, `mod.rs:183`), `clear_stencil`, per-face
  `st_cmp/st_fail/st_dfail/st_pass[2]` (`[0]` = front) and the **shared**
  `st_ref/st_read/st_write`.
* `context3d_clear` must also read **argument 5** (the stencil value) — phase A skipped it —
  and the deferred clear must `memset` the plane under `S3D_CLEAR_STENCIL`.
* `setStencilActions` (`current_pipeline.rs:637-666`). Two traps: (a) the AS3 parameter names
  lie about the wgpu slots — `actionOnDepthPassStencilFail` is the **stencil-fail** op and
  `actionOnDepthFail` is the depth-fail op; (b) `triangleFace` selects which face(s) get the
  state and the *other* face is reset to `StencilFaceState::IGNORE` (Always/Keep), not left
  alone.
* `setStencilReferenceValue(ref, readMask = 255, writeMask = 255)` — the two masks live on
  the shared `wgpu::StencilState`, not per face.
* `setColorMask(r,g,b,a)` → a 4-bit write mask applied at the sample store.
* Sample order is wgpu's: **stencil test, then depth test**; the compare is
  `(ref & read) OP (buf & read)`; the selected op is written back under `write`; the colour
  is only written when both tests pass. `kil` fragments are discarded before any of this
  (late-Z, which is what a shader with `discard` gets).

---

## 3. What to build — the B plan

### 3.1 The binding rule alone flips two rows (~30 LOC)

`current_pipeline.rs:206-215 has_unbound_required_textures`: a fragment program that declares
a sampler config for register *i* — i.e. a `tex` **without** `ignoresampler` — makes texture
*i* **required**; if nothing is bound there, `mod.rs:862-907` **skips `draw_indexed`**.

The trap, and it cost me a run: Ruffle still **opens the render pass**, so the *deferred
clear still lands*. `stage3d/unbound_texture`'s expected PNG is a single colour — 220 000 px
of exactly `(0,102,204)` = its `clear(0, 0.4, 0.8, 1)` — and nothing else. Putting the skip
before `s3d_apply_pending_clear` renders the frame black and scores **440 000** outliers;
putting it after scores **0**.

Our `agal_validate` already computes `extract_sampler_configs` internally and throws it away.
Plumb it out (`agal_validate_cfg(..., out_have, out_wrap, out_filter)`) and store it on
`Avm2Program3DExt`. `out_have[i]` is Rust's `Option::is_some`, so an `ignoresampler` `tex`
leaves it 0 — which is what makes such a texture *not* required.

### 3.2 Texel storage and uploads (~120 LOC)

* `Avm2Texture3DExt` gains `uint32_t* texels` + `uint32_t layers` (6 for a cube, else 1),
  RGBA8 in byte order R,G,B,A, zero-initialised (wgpu zero-inits, and
  `sampler_partial_upload`'s expected PNG proves the untouched region reads as transparent
  black). Free it from `avm2_stage3d_gc_free_ext` under the `g_texturebase_class` arm.
* `uploadFromBitmapData(source[, side][, miplevel])` copies `source_width × source_height`
  texels **to origin (0,0)** and leaves the rest of the texture alone
  (`context3d_object.rs:350-375` + `mod.rs:982-1060`). That partial write is the whole point
  of `stage3d_sampler_partial_upload` (a 4×4 BitmapData into an 8×8 texture).
  `miplevel != 0` is a Ruffle stub that warns and drops.
* `uploadFromByteArray(data, offset[, side][, miplevel])` reads `4·w·h` bytes in **B,G,R,A**
  order (`texture.rs:38-53`) and only for `Context3DTextureFormat::Bgra`; every other format
  warns and drops.
* The argument positions differ per class — `Texture(source, mip)`,
  `CubeTexture(source, side, mip)`, `RectangleTexture(source)` — which is why the prototype
  has six one-line thunks over two shared helpers.

### 3.3 `setTextureAt`, sampler state and the `tex` opcode (~130 LOC)

* `setTextureAt(i, texture)` → `Avm2Context3DExt.tex_bound[8]`. It **must** live in the ext
  blob, not in `S3dBackend`: `avm2_gc.c`'s conservative scan walks the ext word by word and
  cannot follow into a side allocation.
* Live sampler state `samp_wrap[8] / samp_filter[8]` on `S3dBackend`, in **naga_agal**
  numbering (`types.rs:129-152`), default `Clamp/Nearest`. Both our spelling tables use
  different orders, so translate once (`S3D_WRAP_FROM_SPELLING`, `S3D_FILTER_FROM_SPELLING`).
* **The precedence rule** (`current_pipeline.rs:192-204`, which
  `avm2/stage3d_ignore_sampler_override` grades in all six orderings):
  `setSamplerStateAt` writes the state directly; **`setProgram` overwrites it from the
  fragment program's sampler configs, except where `ignoresampler` left the entry empty** —
  there the previous value survives. It is last-write-wins with that one exception, nothing
  more exotic.
* `tex` (`builder.rs:1269-1319`): 2D takes `.xy`; `SampleLevel::Auto` with a single uploaded
  mip level is always LOD 0, so **no derivatives are needed**. Nearest =
  `floor(u·W)` then address-mode; linear = the ordinary half-texel bilinear
  (`u·W − 0.5`), address mode applied to both taps. `ClampURepeatV` / `RepeatUClampV` are
  per-axis. Anisotropic degrades to linear. Textures are `Rgba8Unorm` for every
  `Context3DTextureFormat` the corpus uses (`mod.rs:1258-1278`), so there is **no gamma
  step** — the sample is the byte over 255.
* Cube sampling is **not implemented** in the prototype (`dim == 1` returns zero). No row in
  A′/B uses it; `away3d` does, and it is phase C.

---

## 4. `stage3d_bitmap` — the "second mechanism" question, answered

**Verdict: NO-GO on the pixel axis, and the second mechanism is NOT a Stage3D gap.**

1. **The uniformly-black actual was never the anomaly it looked like.** The *expected* PNG is
   also 86 % black: it is a space-shooter sprite demo on a black background, with only
   34 492 non-black pixels of 240 000. The old blank render was already ~91 % "correct" by
   channel count. The board's `blank_render` label is what made this look like a whole-frame
   defect.
2. **The sprites are pure phase B and the prototype draws them.** Its ABC calls exactly
   `createTexture` + `uploadFromBitmapData` + `setTextureAt` + `setBlendFactors` — no RTT, no
   ATF. With the prototype the sprite art renders and looks **pixel-correct**
   (`<scratchpad>/w1-stage3d/a3_bitmap.png`): the same ships, glows and alpha falloff as the
   golden.
3. **What is left is placement, not rendering.** Our sprites are clustered right-and-down
   relative to the golden's spread. The SWF draws 7 `Math.random` and 7 `getTimer` calls, so
   the residual is a **spawn-position RNG draw-sequence and/or a frame-clock phase**
   difference — the same class of thing as the corpus's other determinism rows, owned by
   nobody in this family. The count went 85 764 → 136 587 *because* we now draw sprites, in
   the wrong places, over a black background — a mis-placed sprite costs two error regions,
   a missing one costs one.
4. **`with_default_font` is a genuinely separate defect, and it is s19's.** The golden's
   top-left line, *"Simple Stage3D Sprite Demo v1 - 49 created 0 reused - FPS: 0"*, is an
   ordinary display-list `TextField` drawn **over** the Stage3D layer. We draw nothing there,
   for the reason `w1-gfx-text-filters-report.md` §4 established: the recompiler emits no
   outlines for device faces. The same defect is visible in `stage3d_texture`'s actual, which
   shows the five white button **backgrounds with no glyphs inside them**.
5. **Even with all three fixed this row cannot flip**: `tolerance 4 / max_outliers 24` over
   34 492 non-black pixels of alpha-blended glow sprites is not a budget a CPU rasteriser
   will meet. Completion mechanism, if anyone ever wants it: RNG/clock parity **and** device
   fonts **and** exact blend parity on additive glows — i.e. three arcs for one comparison.
   Don't.

---

## 5. `stage3d_texture_bytearray` — B′ is now a single, isolated mechanism

Before: 140 625 outliers. With the prototype: **35 747**, and the picture says exactly where
they are. The golden is two orange "ruffle" logos and one pale-blue circle; our render has
**both logos, correct**, and no circle
(`<scratchpad>/w1-stage3d/a3_texba.png` vs `e3_texba.png`). The logos come from
`uploadFromBitmapData` / `uploadFromByteArray`; the circle is the
`uploadCompressedTextureFromByteArray` (ATF) texture, which the prototype still drops.

So B′ is now a clean, self-contained slice: **ATF container + block decode** unblocks three
comparisons (`stage3d_texture_bytearray` at `tolerance 4 / max_outliers 0`,
`stage3d_texture_bytearray_compressed_alpha` and `_raw_alpha` at `4 / 66`). Note all three
carry `[required_features] jpegxr = true`, and the two `_compressed_*` ones were generated
with `png2atf -c d` (DXT), so a wave-2 agent must first establish which of DXT1/DXT5 and
JPEG-XR each actually contains — our ATF header parse from tranche S2 already exists in
`texture_upload_compressed`, so this is decode work, not container work.

---

## 6. RTT (`setRenderToTexture`) — scoped, and then declined

`stage3d_texture` is the only corpus row that exercises it (`away3d` also does, and is on
HOLD). Its actual renders as an all-black 3D area because the demo renders its scene into a
texture and then draws one full-screen quad sampling that texture; with `tex` returning zero
that quad is black, which also explains why the deferred clear's green never appears.

Design, if it is ever wanted (~180 LOC): a second set of float colour/depth buffers sized to
the target texture, a `render_target` pointer on `S3dBackend` that the rasteriser and the
deferred clear follow, and a resolve into the texture's texel array on
`setRenderToTexture(other)` / `setRenderToBackBuffer()` / `present()`.

**But it flips nothing.** `stage3d_texture`'s budget is `tolerance 8 / max_outliers 117`, and
its golden carries eight device-font text runs (three info lines and five button labels) that
we render as empty white boxes — far more than 117 channels on their own. **NO-GO; completion
mechanism = the device-font arc landing first, and only then re-price RTT.**

---

## 7. Risks — read this section before landing anything

### 7.1 `away3d` timed out, exactly as it did in s19

`avm2/away3d_advanced_shallow_water_demo` ran **30.17 s** with the prototype at the default
12 M budget on this box, i.e. it hit `verify_output.py`'s hard 30 s wall and graded
**TIMEOUT** — a `pass → timeout` on the **trace** axis, which is a real regression and is
invisible on the image axis. This is the same trap s19's §4.3 documented, re-armed by the
extra per-sample work this patch adds (the quantise, the top-left test, the stencil branch).

See §7.2 for the A/B that separates "my patch" from "this box is loaded".

### 7.2 The A/B, and the lever

**The local A/B is INCONCLUSIVE for `away3d`, and that is itself the finding.** With the
patch **reverted** (`git apply -R`, never `git stash`) and rebuilt, `away3d` on the same box
minutes later ran **30.20 s → TIMEOUT as well**. Dropping the budget from 12 M to 6 M with the
patch applied: **30.17 s, still TIMEOUT**. So on this shared box *today* `away3d` is over the
30 s wall at plain master HEAD, the budget is not the lever, and the local run cannot
attribute anything to this patch. (s19 measured the same test at 19.86 s baseline / 25.4 s
with phase A on a quieter box, and CI graded it as a pixel comparison — i.e. it *ran* — at
`d8da5a18c`, so CI is comfortably faster.)

**What IS measurable is the marginal cost, and it is small.** `avm2/stage3d_raytrace` spends
the entire 12 M budget every run, which makes it a clean proxy. Same box, back-to-back,
default budget, one rebuild each way:

| leg | `stage3d_raytrace` execution | `stage3d_multistage_triangle` |
|---|---|---|
| patch reverted | **3.39 s** | 0.88 s |
| patch applied | **3.66 s** | 0.92 s |

**+0.27 s, i.e. +8 %, for a FULL budget spend** — the cost of the quantise, the top-left test
and the stencil branch. `away3d` cannot pay more than that, because its Stage3D work is capped
by the same 12 M budget. So the patch's away3d exposure is ~0.3 s local / ~0.15 s at CI
speed, not the 10 s the raw TIMEOUT suggests.

**The budget must stay at 12 M.** Measured, with the patch applied at `SWF_S3D_BUDGET=6000000`:
`stage3d_stencil` **FAILS at 710 400** outliers and `stage3d_blend` **FAILS at 2 888 875** —
both latch off mid-frame. (`sampler`, `ignore_sampler_override` and `rotating_cube` are
unaffected at 6 M.) So "lower the budget to buy away3d headroom" is **not** available: 12 M is
close to the minimum A′ needs. If away3d ever does need headroom, the lever is §9's
fixed-point rasteriser, not the budget.

**Required of wave 2:** the grading run must explicitly check `away3d`'s and
`stage3d_raytrace`'s **trace** status (`pass`, not `timeout`) in `results_graphics.json`, and
a local pre-flight must be run on an idle box, not under an 8-agent fan-out.

### 7.3 `stage3d_rotating_cube` is the row to watch

2 144 → 2 148 outliers against a limit of 2 160 — it still passes with a **12-outlier**
margin, and it is the only phase-A row that moved at all. It is the one row in the family
whose verdict a further rasteriser change could flip the wrong way. Its `test.toml` does carry
two looser alternative checks (16/1 250 and 32/250) which we also satisfy, so the true risk is
lower than the headline margin suggests — but any wave-2 agent touching coverage or
interpolation must re-grade it.

### 7.4 `stage3d_blend`'s margin is 3.8 %

35 576 against 37 000 on the first check. It also has a second check (tolerance 16 /
max_outliers 5 200) which we do **not** satisfy, so there is no fallback. A blend-arithmetic
refinement (e.g. modelling lavapipe's exact rounding) would buy headroom if it is ever needed.

### 7.5 The prototype carries a debug knob that must not land as-is

`SWF_S3D_BUDGET` (an env override for the cost budget, read once in
`configureBackBuffer`) exists purely so the budget could be swept without a 6-minute runtime
rebuild per point. It makes the render configurable from the environment, which is at odds
with the project's determinism rules. **Drop it or gate it behind a debug build before
landing.**

### 7.6 CI visibility

Three of the eight flips (`stage3d/unbound_texture`, `unbound_texture_multiple`,
`sampler_odd_size`) are in the `stage3d` suite = the CI **`misc`** group, invisible at
`categories=all`. The grading run for this work must be
`-f categories=full -f images=true -f mode=graphics`.

---

## 8. Tests run

All in the worktree, `--mode=graphics --images`, `SWFRECOMP_COMPILE_TIMEOUT=2400`,
`DAWN_INSTALL=~/CC/dawn-install`, sequential, `--recompile` on first use of each copied dir.

| run | scope | result |
|---|---|---|
| 1 | `stage3d/unbound_texture` **before the patch** | image FAIL 118 800 / 0, max 255 — the CI baseline reproduced locally |
| 2 | `stage3d` × 4 (first prototype) | `sampler_odd_size` PASS, `scissor_rectangle` PASS, `unbound_texture_multiple` PASS, `unbound_texture` FAIL 440 000 → found the clear-ordering bug of §3.1 |
| 3 | `avm2` × 8 + `stage3d/unbound_texture` (clear fixed) | 7 flips; `stage3d_stencil` 4 320 residual → found the missing fill rule |
| 4 | `avm2` × 10 + `stage3d` × 4 (top-left rule) | stencil 4 320 → **126**; `bitmap`, `texture`, `texture_bytearray` characterised |
| 5 | `avm2` × 9 + `stage3d` × 4 (subpixel snap) — **the authoritative run; every number in §0 is this run** | stencil **0/0 max 0**; `ignore_sampler_override` 105 → 6; `sampler` 74 → 50; all five phase-A rows unchanged |
| 6 | `away3d`, `raytrace`, `fractal` at 12 M; `fractal` and `raytrace` at 400 M | away3d **TIMEOUT 30.17 s**; fractal 29 620 @400 M in 11.2 s; raytrace 636 741 @400 M in 17.1 s |
| 7 | the §7.2 A/B | `away3d` reverted = **TIMEOUT 30.20 s** (so the local A/B is inconclusive); `raytrace` reverted **3.39 s** vs applied **3.66 s** = the real +8 % marginal cost; `stencil`/`blend` FAIL at a 6 M budget, so 12 M must stay |

**Not run: the `regression` suite.** This is a wave-1 diagnosis and the patch is UNLANDED;
the change is confined to `avm2_stage3d.c`, which nothing outside Stage3D calls, so the
blast radius is the fourteen rows above. A wave-2 agent landing this **must** still run a
`regression`-suite slice (`avm2_parent_child_render`, `avm2_timeline_solid`,
`mask_nested_intersect`, `bitmap_pool_layer_cap`, the three `avm2_gc_*` rows) plus the
render canary, per the common brief.

**Render canary.** The standing set already has the two Stage3D members s19 added
(`avm2/stage3d_triangle`, `avm2/stage3d_rotating_cube`). Both re-graded identical/passing
here. A wave-2 agent should add **`avm2/stage3d_stencil`** as a tier-1 member: it is a
tolerance-0/max-outliers-0 exact-match row that now passes at **max diff 0**, which makes it
the strictest single guard the Stage3D backend can have.

---

## 9. New unclaimed leads

* **`avm2/stage3d_fractal` is one budget constant plus device fonts away from a flip.** At a
  400 M budget it renders the Julia set essentially perfectly: **601 of its 29 620 outlier
  channels are outside the two text bands, and only 2 pixels of those are outside the text
  rows entirely** — against a budget of 100. This is the strongest argument in the corpus for
  funding s19's device-font arc, which was correctly priced at "flips nothing" *on its own*.
  Somebody should check whether `leading_device_font`'s 18-outlier residual plus this row
  changes that calculus.
* **A fixed-point rasteriser would be both faster and more correct.** §2.3 shows the backend
  already needs 8-bit subpixel snapping for correctness; doing the edge functions in integers
  after that snap would remove the float-compare fragility *and* cut the per-sample cost,
  which is the same cost that puts `away3d` on the 30 s wall (§7.1). Nobody owns rasteriser
  performance.
* **`stage3d_bitmap`'s sprite placement is an AVM2 `Math.random` / `getTimer` determinism
  question** (§4.3), now cleanly separable because the rendering is correct. Our
  `avm2_number.c` RNG is the seeded avmplus LFSR and `getTimer` is a deterministic virtual
  clock, so a divergence means either a different seed or a different *draw count* — the
  latter is a bug-shaped thing worth one session's attention, and it would affect far more
  than this row.
* **Nothing in the corpus exercises `Stage3D.x`/`y` non-zero** (still true from s19), and
  nothing exercises **cube-map sampling** either — the prototype returns zero for
  `Dimension::Cube` and no graded row notices.
* **`avm2/stage3d_texture`'s white TextField boxes with no glyphs are a free, tiny
  reproduction of the device-font defect** — much cheaper to iterate on than
  `visual/fonts/device-font`.
