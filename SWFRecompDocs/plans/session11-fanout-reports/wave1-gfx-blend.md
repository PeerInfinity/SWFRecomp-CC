# wave1-gfx-blend — the blend residual is NOT an extra element; it is
# `quality = "low"` ⇒ Ruffle renders with NO antialiasing and we always render 4× MSAA

Session 11, wave 1 (read-only; diagnostic patch built and destroyed in a
throwaway worktree). Baseline: CI run `30713776612` at `c4496a4c8`
(trace 4188/4424, pixels 217/566).

**Headline verdict: the session-10 "one pre-existing extra element inside the
blend group" premise is REFUTED.** The residual on every `visual/blend_modes`
test is the **antialiasing fringe of the correct geometry**. All 15 tests set
`quality = "low"` in `test.toml`; Ruffle maps `StageQuality::Low → sample_count
= 1` (`~/CC/ruffle/render/src/quality.rs:66-76`), so every golden in that
directory is rendered with **zero AA and hard edges**. Our renderer hard-codes
**MSAA 4×** everywhere. On a shallow-slope edge a 4× fringe spreads 8–10 px
horizontally, and under an `add` blend over a bright backdrop even a 25 %
fringe saturates to full ink — which is exactly the "extra element" wave 2 saw
at `add` (167, 91).

**Measured, in a worktree, by forcing sample count to 1:**

| test | CI now | MSAA=1 | Δ |
|---|---:|---:|---|
| `blend_modes/add` | 3 578 | **20** | −99.4 % |
| `blend_modes/subtract` | 4 076 | **21** | −99.5 % |
| `blend_modes/screen` | 4 568 | **20** | −99.6 % |
| `blend_modes/lighten` | 4 194 | **20** | −99.5 % |
| `blend_modes/multiply` | 8 414 | **37** | −99.6 % |
| `blend_modes/darken` | 8 035 | **37** | −99.5 % |
| `blend_modes/difference` | 5 379 | **21** | −99.6 % |
| `blend_modes/invert` | 12 680 | **60** | −99.5 % |
| `blend_modes/overlay` | 9 650 | **54** | −99.4 % |
| `blend_modes/hardlight` | 11 238 | **54** | −99.5 % |
| `blend_modes/alpha_no_layer` | 12 645 | **50** | −99.6 % |
| `blend_modes/erase_no_layer` | 12 439 | **50** | −99.6 % |
| `blend_modes/layer_alpha` | 75 364 | 66 791 | −11 % (needs **F5**) |
| `blend_modes/layer_erase` | 75 300 | 66 996 | −11 % (needs **F5**) |
| `blend_modes/overlay_onto_stage` | pass (33 894/40 000) | pass (35 480/40 000) | still pass |
| `blend_modes/shader_without_shader` | pass (0) | pass (0) | still pass |

**None of these flips** — `max_outliers = 0` and 20–60 residual channels
survive (§4: sub-pixel edge ties, not fixable by a global nudge). But the same
one-line change **flips 17 image comparisons elsewhere in the corpus, measured
locally, with zero regressions in a 12-comparison probe** (§5). That is the
real lead this diagnosis unlocked, and it is bigger than the blend slice.

---

## 1. Instrument validation — local Dawn is CI-exact for this work

The playbook's standing rule is *never grade a local render against a golden*.
Validated the exception explicitly before relying on any number below:

- `visual/blend_modes/add` rendered locally at HEAD (`--mode=graphics --images`)
  is **byte-identical** to the CI lavapipe actual on `origin/ruffle-image-results`:
  both `md5 5d2418610246c1bb169472b7a5228b82`, and the harness reports the
  identical `3578 outliers, max difference 246`.
- A-leg re-run of six unrelated tests at the unmodified sample count reproduced
  the CI outlier counts **exactly**: `simple_shapes/gradients/gradients` 4270,
  `gradients/radial` 5280, `avm1/mouse_events_visible_enabled` 3614,
  `acid/acid-gradient-1` 384, `simple_shapes/overlaps` 3770, `fonts/glyph` 4401.

So every "MSAA=1" number in this report is a CI prediction, not a local
artefact. (This does **not** generalise — `bitmapdata_copypixels` is still the
counter-example; it holds for the tests A-legged above.)

## 2. The refutation, with evidence

### 2.1 The residual follows glyph edges, not an element

Diff of the CI actual vs golden for `add`, 8×8-block map: the outliers trace
the *outline* of every letter in the "ruffle" wordmark across all five grid
rows — 2 808 pixels over a 322×318 bbox, ~5 per row on near-vertical edges and
54 on one near-horizontal row. No filled region, no rectangle, no duplicated
child.

### 2.2 The values are quarter-steps of the ink — i.e. 4-sample coverage

`add` row y=91 inside the **black** grid cell (backdrop red 0, so nothing
saturates):

```
golden  :  0 0 0 0 | 255 255 …        (hard edge)
ours    :  0 64 64 64 64 64 64 128 191 191 191 | 255 255 …
```

`64 / 128 / 191 / 255` = coverage `1/4, 2/4, 3/4, 4/4` — a 4× MSAA resolve.
Ten pixels wide because the glyph edge is nearly horizontal there. In the
neighbouring **magenta** cell (backdrop red 217) the same 25 % fringe computes
`217 + 64 → 281 → clamp 255`, i.e. it reads as *full ink 8 px early*. That is
precisely the `x=167 golden 217 / after 255` sample session 10 attributed to an
extra element.

### 2.3 The goldens have no AA at all

Red-channel ASCII dump of the golden over 60 rows of a diagonal glyph edge:
every transition is `0 → 255` with **no intermediate value anywhere**. Our
render has exactly one intermediate step at each of those transitions.

### 2.4 99 %+ of the residual is a value that already exists 1 px away

For each outlier channel, is the actual value inside `[min, max]` of the golden
over a 3×3 neighbourhood (tolerance-padded)? That is the signature of "the same
geometry, resampled" and the negation of "new content":

| test | outliers | explained r=1 | r=8 |
|---|---:|---:|---:|
| add | 3 578 | 99.2 % | 100 % |
| multiply | 8 414 | 99.2 % | 100 % |
| invert | 12 680 | 99.1 % | 100 % |
| darken | 8 035 | 99.3 % | 100 % |
| overlay | 9 650 | 99.3 % | 100 % |
| alpha_no_layer | 12 645 | 98.9 % | 100 % |
| difference | 5 379 | 95.3 % | 97.6 % |
| **layer_alpha** | 75 364 | **18.3 %** | 51.2 % |

`layer_alpha` / `layer_erase` are the only two members whose residual is real
new/missing content — they still need **F5** (layer groups), as session 10 said.

### 2.5 Oracle

`~/CC/ruffle/render/src/quality.rs:66-76` — `StageQuality::Low ⇒ 1`,
`Medium ⇒ 2`, `High/Best ⇒ 4`.
`~/CC/ruffle/render/wgpu/src/surface.rs:50-55` — the frame surface, and every
offscreen/layer buffer derived from it, is built at `quality.sample_count()`.
Every `visual/blend_modes/*/test.toml` carries
`[player_options] with_renderer = { optional = true, quality = "low" }`.

**CONFIRMED:** AA-sample-count mismatch is the residual mechanism.
**REFUTED:** "one pre-existing extra element inside the blend group".
**CONFIRMED (unchanged):** F5 is still required for `layer_alpha`/`layer_erase`.

## 3. Where it enters the render path — exact sites

All in `SWFModernRuntime/src/rendering/render_webgpu.c` (line numbers at
`b4c983ea4`). There is no quality/sample-count knob anywhere in the runtime and
`verify_output.py` never reads `player_options.quality`.

| site | what | line |
|---|---|---|
| `msaa_texture` | main colour MSAA target, `sampleCount = 4` | **1243-1255** |
| `depth_stencil_texture` | clip-mask stencil, `sampleCount = 4` | **1258-1273** |
| main render pipeline | `rp_desc.multisample.count = 4` | **1422** |
| main pass begin | `color_att.view = ctx->msaa_view; color_att.resolveTarget = ctx->surface_view;` | **1929-1930** |
| pass resume (filter/blend) | same pair | **3677-3678** |
| `filter_msaa_texture` | offscreen/layer MSAA target, `sampleCount = 4` | **3100-3111** |
| offscreen pass begin | `color_att.view = ctx->filter_msaa_view; resolveTarget = ctx->filter_view_a;` | **3715-3716** |
| `filter_ds_texture` | offscreen stencil, `sampleCount = 4` | **3403-3409** |
| composite / blend-layer / stencil pipelines | `multisample.count = 4` | **3258, 3461, 3561** |

(`3186` is already `count = 1` — the non-MSAA filter blit; leave it.)

## 4. The 18–60 channel remainder after MSAA=1 — sub-pixel edge ties

Every surviving outlier on `add` is a **single isolated pixel at a shape
corner**, all 18 of them "we ink, Ruffle does not", and all 18 sit at exactly
the same coordinates in **every** blend test (`(243,46) (365,72) (364,74)
(274,92) (156,132) (157,135) (383,138) (394,173) (258,197) (337,239) (365,289)
(364,291) (391,348) (156,349) (196,353) (349,353) (191,355) (405,363)`). Every
one has an ink boundary inside its own 3×3 — none is a stray element.

Direction is systematic: the extra pixel is always on the **top-left** side of
the boundary. That is the D3D/Vulkan top-left rule firing on a pixel centre
that lies *exactly* on our edge but not on Ruffle's — i.e. our tessellated
geometry differs from lyon's by a sub-ULP at those spots.

Probed a global sub-pixel nudge on `stage_to_ndc` (±1/1024 px, down-right and
up-left):

| nudge | add | fonts/glyph | overlaps |
|---|---:|---:|---:|
| 0 | 20 | 6 | 18 |
| +1/1024 px | 25 | 18 | 18 |
| −1/1024 px | 25 | 6 | — |

Both directions are neutral-or-worse. **A global offset does not fix it**;
closing it would mean matching Ruffle's tessellation + transform bit-for-bit.
**Do not scope it.** Practical consequence: curve-heavy art keeps a handful of
tie pixels; rectilinear / gradient / bitmap art goes to exactly 0 (§5).

## 5. Census — what the quality-aware sample count actually flips

**Screen:** of 546 graded comparisons, **332 are `quality = "low"`** (194 fail),
205 are `high` (133 fail), 2 `best`, 1 `medium`. Only the `low` set changes.
Ranked candidates = failing `low` comparisons where 100 % of the outliers are
explained by a 1-px neighbourhood of the golden (36 comparisons).

**Measured locally at MSAA=1 (A-leg verified CI-exact, §1):**

### FLIPS — 17 comparisons, fail → pass

| suite / test | cmp | CI now | MSAA=1 |
|---|---|---:|---:|
| `visual/focus_highlight/focus_highlight_render` | output.01 | 2 127 | **0 pass** |
| " | output.02 | 2 115 | **0 pass** |
| " | output.03 | 4 371 | **0 pass** |
| " | output.04 | 2 127 | **0 pass** |
| " | output.05 | 2 178 | **51/limit 100 pass** |
| " | output.06 | 2 495 | **0 pass** |
| `visual/simple_shapes/gradients/gradients` | output | 4 270 | **0 pass** |
| `visual/simple_shapes/gradients/radial` | output | 5 280 | **0 pass** |
| `visual/simple_shapes/gradients/reflect` | output | 8 847 | **0 pass** |
| `visual/simple_shapes/gradients/repeat` | output | 8 847 | **0 pass** |
| `visual/simple_shapes/gradients/focal_radial` | output | 10 016 | **0 pass** |
| `from_shumway/acid/acid-child` | output | 1 344 | **0 pass** |
| `from_shumway/acid/acid-child` | frame5 | 1 317 | **0 pass** |
| `from_shumway/acid/acid-gradient-1` | output | 384 | **0 pass** |
| `avm1/mouse_events_visible_enabled` | output | 3 614 | **0 pass** |
| `avm2/pixelbender_effect_BlurredFocus` | output | 5 025 | **0 pass** |
| `avm2/symbol_class_conflict` | output | 5 040 | **0 pass** |

### Near-miss band moves (tie pixels only; §4 blocks these)

`acid/acid-text-x` 2 250→6 · `fonts/glyph` 4 401→6 · `fonts/embed_matching/match_style` 7 389→12 ·
`acid/acid-text-6 [frame5]` →12 · `text/auto_size/height` 18 255→15 (limit 3) ·
`avm2/loader_events` 440→16 · `avm2/loader_loadbytes_events` 440→16 ·
`simple_shapes/overlaps` 3 770→18 · `from_shumway/doubleAndRegister` 574→54 ·
`acid/acid-text-escape` 2 314→192 · `acid/acid-text-6` 4 197→195 ·
`visual/drawing_api/cursor` 600→200 · `acid/acid-gc` 20 403→234.

### Large band moves, different owner

`acid/acid-gradient` 19 275→6 639 · `text/auto_size/width` 39 042→7 560 (limit 18) ·
`avm2/bitmap_pixelsnapping` 6 588→4 008 · `visual/simple_shapes/masks` 248 261→242 782.

### Unchanged (CPU raster / text raster — not an AA-sample owner)

`avm2/bitmapdata_draw_rotation` 348 · `visual/edittext/edittext_underline` 1 974 ·
`visual/cache_as_bitmap/avm1_color` 1 200→1 192 ·
`avm2/bitmapdata_applyfilter_colormatrix` 7 419.

### Regression probe — 12 currently-PASSING comparisons, all still pass at MSAA=1

`from_shumway/button1` output.1–.4 · `avm1/color` · `from_shumway/gradient` ·
`from_shumway/acid/acid-gradient-0` · `from_shumway/acid/acid-text-3` ·
`visual/cache_as_bitmap/shape_changed` · `visual/blend_modes/shader_without_shader` ·
`visual/blend_modes/overlay_onto_stage` (33 894→35 480, limit 40 000).
**Zero regressions observed.** Rationale: a currently-passing low-quality
comparison is by construction AA-insensitive (axis-aligned or bitmap art), and
axis-aligned edges land cleanly under both 1× and 4×.

**17 flips is a floor, not a ceiling** — only the 36-comparison strict
candidate list plus a handful of others was run. 135 further failing `low`
comparisons were never sampled.

## 6. Fix sketch for one wave-2 worktree agent

Runtime-only + one harness line. No `SWFRecomp/` change ⇒ the worktree may copy
`SWFRecomp/build` and skip `--recompile` (except for AVM2 test dirs copied
mid-write, which still need it once — playbook §5 / session-10 w2-button trap).

**Step A — make the sample count a knob (`render_webgpu.c`).**
```c
#ifndef MSAA_SAMPLES
#define MSAA_SAMPLES 4      /* default: unchanged for browser + quality=high */
#endif
```
Replace the four `sampleCount = 4` (1248, 1266, 3108, 3403) and the four
`multisample.count = 4` (1422, 3258, 3461, 3561) with `MSAA_SAMPLES`, and guard
the three attachment pairs:
```c
#if MSAA_SAMPLES == 1
    color_att.view = ctx->surface_view;   color_att.resolveTarget = NULL;   /* 1929, 3677 */
#else
    color_att.view = ctx->msaa_view;      color_att.resolveTarget = ctx->surface_view;
#endif
```
and the same shape for `filter_msaa_view → filter_view_a` at 3715.
(Verified: this exact edit compiles and runs clean in both legs. Put the
`#ifndef` **outside** the `#ifdef OFFSCREEN_RENDER / #elif / #else / #endif`
include block — dropping it inside the `__EMSCRIPTEN__` arm is a silent
`undeclared` build break.)

Prefer a real `ctx->sample_count` field over the macro **only if** it stays a
one-shot init value — all pipelines/textures are created once at init, so a
macro is sufficient and is the smaller diff.

**Step B — plumb stage quality from the harness (`ruffle-tests/verify_output.py`).**
Parse `[player_options].with_renderer.quality` (also accepts the flat
`player_options.quality` spelling used elsewhere in the file) and add
`-DMSAA_SAMPLES=N` to the gcc invocation in `--mode=graphics`, exactly the way
`MOCK_DATE_TIME` is defined today. Map `low→1, medium→2, high→4, best→4`
(mirror `quality.rs::sample_count`). **Clamp 2/8/16 to 4** unless Dawn+lavapipe
are confirmed to support them — the corpus has exactly one `medium` comparison
and it already passes, so clamping costs nothing and removes a portability
failure mode. Absent/unknown quality ⇒ 4.

**Step C (optional, later).** A real `_quality` / `Stage.quality` property. Not
needed for any flip; do not scope it into this patch.

**Step D — blend follow-ups that survive.** `F5` (layer groups, mode 2) for
`layer_alpha` / `layer_erase`, and `F7-AVM2` for `avm2/displayobject_blendmode`
(62 400, untouched by all of the above — the GPU half already exists per
session-10 w2-blend §6.8). Both unchanged in scope from session 10.

**Do not** attempt the §4 tie pixels.

## 7. Risk register + canary set

1. **Highest risk: a currently-passing `quality = "low"` comparison regresses.**
   138 of them. 12 probed, all green. Recommend the wave-2 agent run the full
   standing canary (`render_canary_tests.txt`) in **both** legs and additionally
   force `MSAA_SAMPLES=1` on the low-quality rows, since md5 A/B at the default
   4 will report IDENTICAL everywhere and prove nothing (canary false-negative:
   the knob defaults to no-op).
2. **`quality = "high"` must be bit-identical.** 205 comparisons. Guaranteed by
   the default, but assert it: any DIFFERS on a `high` row means Step B is
   mis-parsing the toml.
3. **Browser / wasm build must not change** — `MSAA_SAMPLES` unset ⇒ 4. Add no
   `-D` to any emscripten build script.
4. **Stencil / clip masks share the sample count.** `depth_stencil_texture` and
   `filter_ds_texture` move to 1 with the colour target; the stencil-Equal
   composite pipelines must move with them or pipeline creation fails at
   startup (loud, not silent). `visual/simple_shapes/masks` and
   `avm1/movieclip_setmask` are the canary rows for this.
5. **Trace axis: near-zero risk** (hit-test and bounds never read the MSAA
   target), but `avm2/bitmap_pixelsnapping` and `bitmapdata_*` show that
   CPU-readback paths do observe rendered pixels; keep the trace sweep on
   `avm1/bitmap_data_*`, `avm2/bitmapdata_*`, `from_shumway/acid/*`.
6. **CI dispatch:** `mode=graphics`, `categories=all`, and this one **must** be
   an `images=true` closeout run — the entire deliverable is on the pixel axis.

**Canary rows to add for this change (all low-quality, all currently passing):**
`from_shumway/button1`, `avm1/color`, `from_shumway/gradient`,
`from_shumway/acid/acid-gradient-0`, `from_shumway/acid/acid-text-3`,
`visual/cache_as_bitmap/shape_changed`, `visual/blend_modes/shader_without_shader`,
`visual/blend_modes/overlay_onto_stage`, `visual/simple_shapes/masks`,
`avm1/movieclip_setmask`, plus the standing `regression/*` three.

## 8. Verdicts and go/no-go

| claim | verdict |
|---|---|
| "one pre-existing extra element inside the blend group" | **REFUTED** — 4× MSAA fringe on shallow-slope edges, amplified by blend saturation |
| "if the extra-element diagnosis holds, most of `visual/blend_modes` flips" | **REFUTED** — sample count fixes 99.5 % of the residual and flips **0** of them (`max_outliers = 0` vs 18–60 tie pixels) |
| F5 (layer groups) still needed | **CONFIRMED** — `layer_alpha`/`layer_erase` keep a 66.8 k residual, only 18 % neighbourhood-explained |
| F7-AVM2 still needed | **CONFIRMED** — `avm2/displayobject_blendmode` untouched at 62 400 |
| local Dawn is CI-exact for this family | **CONFIRMED** — md5-identical actual + 7 exact outlier-count reproductions |

**GO** — but on the reframed item. Ship **quality-aware MSAA sample count**
(§6 Steps A+B): one runtime macro, eight mechanical line edits, three
attachment guards, one harness parse. **17 measured flips, 0 measured
regressions, 217 → ~234 (38.3 % → ~41.3 %)**, and it is a floor.

**NO-GO** on closing `visual/blend_modes` this session: the directory is capped
by sub-pixel rasterisation ties that no cheap change reaches. It becomes a
99 %-band-move slice, not a flip slice. The two remaining blend items worth
scheduling are F5 and F7-AVM2, unchanged.
