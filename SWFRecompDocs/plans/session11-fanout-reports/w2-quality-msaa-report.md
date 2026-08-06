# w2-quality-msaa — quality-aware MSAA sample count

Session 11, wave 2. **Anchor pixel patch.** Implements wave-1's
`wave1-gfx-blend.md` §6 Steps A+B (corroborated independently by
`wave1-gfx-masks.md` §3.7 and `wave1-gfx-clipping.md` §2.4).

Worktree: `.claude/worktrees/agent-ab6d981ba47314d39`, base `b4c983ea4`
(`bed9d894b` is docs-only — `render_webgpu.c` is byte-identical between them, so
every line pin in the spec was verified verbatim before editing).

## Headline

| | |
|---|---|
| **Comparisons graded (2-leg A/B)** | **142** across 104 test directories |
| **FLIPS (fail → pass)** | **24** |
| **REGRESSIONS (pass → fail)** | **0** |
| **CI-predictive rate** | **101/101** failing comparisons: local BEFORE render is **md5-identical** to the CI lavapipe actual |
| **Canary (no-quality / `quality != low`)** | **byte-identical everywhere**, 0 violations |
| **12 passing low-quality probes** | **all 12 still pass** |
| Projected pixel axis | 217/566 → **241/566** (38.3 % → **42.6 %**) |

The 17 comparisons wave-1 predicted flipped — **all 17, exactly**, with the
exact predicted before/after outlier counts. The extended sweep added **7 more**
that wave-1 never sampled.

---

## 1. What was implemented

### Step A — `SWFModernRuntime/src/rendering/render_webgpu.c`

A compile-time knob, defaulting to the historical 4, placed **outside** the
`OFFSCREEN_RENDER / __EMSCRIPTEN__` include block (the spec warned that putting
it inside is a silent `undeclared` break):

```c
#ifndef MSAA_SAMPLES
#define MSAA_SAMPLES 4
#endif
```

All eight hard-coded sample counts now read `MSAA_SAMPLES` — verified at the
spec's exact pins:

| pin (at `b4c983ea4`) | site |
|---|---|
| `:1248` | `msaa_texture.sampleCount` |
| `:1266` | `depth_stencil_texture.sampleCount` (clip-mask stencil) |
| `:1422` | main `rp_desc.multisample.count` (also feeds `stencil_write`/`stencil_test`/5 blend pipelines, which reuse the same descriptor) |
| `:3108` | `filter_msaa_texture.sampleCount` |
| `:3258` | `composite_pipeline.multisample.count` |
| `:3403` | `filter_ds_texture.sampleCount` (offscreen stencil) |
| `:3461` | blend-layer pipeline loop |
| `:3561` | blend-shader pipeline loop |

`:3186` (`multisample.count = 1`, the non-MSAA filter blit) is deliberately
untouched, as the spec required.

Three attachment pairs are guarded, so at count 1 the passes render **straight
into the single-sample destination with no resolve target**:

| pin | at `MSAA_SAMPLES == 1` |
|---|---|
| `:1929-1930` `begin_pass` | `view = surface_view`, `resolveTarget = NULL` |
| `:3677-3678` `resume_pass` | `view = surface_view`, `resolveTarget = NULL` |
| `:3715-3716` `begin_offscreen_pass` | `view = filter_view_a`, `resolveTarget = NULL` |

Both destinations already carry `WGPUTextureUsage_RenderAttachment`
(`offscreen_target` at `:884`, `filter_tex_a` at `:3088`), so no usage-flag
change was needed. `flashbang.c` (legacy SDL_GPU backend, `sample_count =
SDL_GPU_SAMPLECOUNT_8`) is **not** on the graphics-native or browser path and
was left alone.

### Step B — `ruffle-tests/verify_output.py`

`get_msaa_samples(test_dir)` parses `[player_options].with_renderer.quality` and
maps it per `~/CC/ruffle/render/src/quality.rs:66-76`: **`low` → 1, everything
else → 4** (medium/8/16 clamped to 4 per spec — the corpus has exactly one
`medium` comparison and it already passes). Absent / unparseable → 4.

A survey of every `test.toml` in the corpus shows the inline-table spelling is
the *only* one actually used (180 + 100 + 81 + 23 + 21 + 5 + 2 + 1 = 413
declarations, all `with_renderer = { … quality = "…" }`); a flat
`quality = "…"` fallback regex is included for robustness. The two
`# FIXME … quality …` comment lines in the corpus match neither pattern.

The `-D` is appended to `mode_defines` inside the `mode == "graphics"` branch
and **only when the value differs from 4**, so:

* no-graphics builds are untouched (the macro's only consumer isn't compiled there);
* every `quality != "low"` graphics test keeps a **byte-identical gcc command
  line** and therefore its warm ccache entry;
* no emscripten/browser build script gains a `-D` — browser stays 4×.

## 2. Instrument validation — local Dawn is CI-exact for this entire population

Standing rule: never grade a local render against a golden unless the local
render provably reproduces CI. Extracted every CI `*.actual.png` blob directly
from `origin/ruffle-image-results` (`git show`, **branch never checked out**) and
md5-compared against the local BEFORE leg:

| leg | failing comparisons | md5-identical to CI actual |
|---|---:|---:|
| tier-1 | 21 | **21** |
| sweep batch 1 | 63 | **63** |
| sweep batch 2 | 17 | **17** |
| **total** | **101** | **101 (100 %)** |

Every local BEFORE outlier count also equals the CI outlier count exactly. So
every AFTER number below is a CI prediction, not a local artefact. (This does
not generalise beyond the tests A-legged here — `bitmapdata_copypixels` remains
the standing counter-example.)

Per `wave1-gfx-cab-watchlist.md`: all grading is off the exported `<cmp>.png`
actuals harvested by `render_canary.py` under `SWF_KEEP_BUILD_DIR`, **never**
off a regenerated `image_results_graphics.json` (single-test `--images` runs
re-serialise stale rows). No shared results file was written at any point.

Method: `render_canary.py capture` two-phase, `-P 2` (shared machine, 7 sibling
agents), one build dir per (test, label). The BEFORE leg was produced with a
temporary env-gated toggle in `verify_output.py`; **the toggle is removed from
the delivered patch** (verified: `grep AB_LEG_ENABLE` → nothing, `ast.parse` OK).

---

## 3. Ledger A — the 17 predicted flips: 17/17 reproduced

Every row: `ci-pred = YES` (local BEFORE md5 == CI actual).

| suite / test | cmp | CI now | AFTER | limit | verdict |
|---|---|---:|---:|---:|---|
| `visual/focus_highlight/focus_highlight_render` | output.01 | 2 123 | **0** | 4 | **FLIP** |
| " | output.02 | 2 111 | **0** | 4 | **FLIP** |
| " | output.03 | 4 367 | **0** | 4 | **FLIP** |
| " | output.04 | 2 123 | **0** | 4 | **FLIP** |
| " | output.05 | 2 078 | **0** | 100 | **FLIP** |
| " | output.06 | 2 491 | **0** | 4 | **FLIP** |
| `visual/simple_shapes/gradients/gradients` | output | 4 270 | **0** | 0 | **FLIP** |
| `visual/simple_shapes/gradients/radial` | output | 5 280 | **0** | 0 | **FLIP** |
| `visual/simple_shapes/gradients/reflect` | output | 8 847 | **0** | 0 | **FLIP** |
| `visual/simple_shapes/gradients/repeat` | output | 8 847 | **0** | 0 | **FLIP** |
| `visual/simple_shapes/gradients/focal_radial` | output | 10 016 | **0** | 0 | **FLIP** |
| `from_shumway/acid/acid-child` | output | 1 344 | **0** | 0 | **FLIP** |
| `from_shumway/acid/acid-child` | frame5 | 1 317 | **0** | 0 | **FLIP** |
| `from_shumway/acid/acid-gradient-1` | output | 384 | **0** | 0 | **FLIP** |
| `avm1/mouse_events_visible_enabled` | output | 3 614 | **0** | 0 | **FLIP** |
| `avm2/pixelbender_effect_BlurredFocus` | output | 4 022 | **0** | 1 003 | **FLIP** |
| `avm2/symbol_class_conflict` | output | 5 040 | **0** | 0 | **FLIP** |

Note `focus_highlight_render/output.05` lands at **0**, not the 51 wave-1
reported — it clears its limit of 100 either way.

`visual/blend_modes` behaves exactly as predicted — huge band move, **no flip**:
`multiply` 8 414 → **37** (−99.6 %), the same 37 wave-1 measured. Sub-pixel
rasterisation ties, `max_outliers = 0`. Not fixable by this change (wave-1 §4).

---

## 4. Ledger B — the extended sweep (69 comparisons wave-1 never sampled)

Wave-1 flagged ~135 unsampled failing `low` comparisons. Swept **69** of them in
two batches (52 + 17 test dirs), chosen by ascending CI excess-outliers plus a
targeted high-tolerance batch. All CI-predictive.

### 4.1 NEW FLIPS — 7 comparisons

| suite / test | cmp | CI now | AFTER | verdict |
|---|---|---:|---:|---|
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame1 | 242 | **0** | **FLIP** |
| " | frame2 | 483 | **0** | **FLIP** |
| " | frame3 | 724 | **0** | **FLIP** |
| " | frame5 | 242 | **0** | **FLIP** |
| " | frame6 | 483 | **0** | **FLIP** |
| " | frame7 | 724 | **0** | **FLIP** |
| `from_shumway/acid/acid-chars` | output | 2 100 | **0** | **FLIP** |

(`simple_loop_test/frame4` already passed and still passes.)

### 4.2 Large band moves — new near-pass leads

These do **not** flip but land in the winnable band and are now the cheapest
remaining pixel targets:

| test | cmp | before | after | limit |
|---|---|---:|---:|---:|
| `visual/fonts/duplicate_font` | output | 3 999 | **3** | 0 |
| `visual/drawing_api/fills_and_lines` | output | 4 966 | **104** | 0 |
| `fonts/embed_matching/fallback_preferences` | output | 62 241 | **156** | 0 |
| `visual/simple_shapes/layers` | output | 271 | **177** | 0 |
| `from_gnash/misc-ming.all/morph_test1` | frame1 | 776 | **212** | 0 |
| `avm2/graphics_simple_shapes` | output | 402 | **252** | 0 |
| `from_shumway/acid/acid-scale` | output | 4 516 | **302** | 0 |
| `visual/cache_as_bitmap/edittext_scroll` | output.01 / .02 | 820 / 816 | **585 / 589** | 5 |
| `avm2/graphics_draw_path` | output | 1 460 | **764** | 0 |
| `from_gnash/misc-ming.all/morph_test1` | frame2-5 | 1 575-2 511 | **789** | 0 |
| `avm2/sprite_with_frames` | output | 5 686 | **920** | 0 |
| `visual/text/String_path_variable_button` | output | 1 491 | **984** | 12 |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | output | 975 | **189** | 0 |
| `from_gnash/misc-ming.all/BeginBitmapFill` | output | 1 346 | **794** | 100 |
| `visual/cache_as_bitmap/drawing_api` | output | 8 334 | **2 295** | 0 |
| `text/auto_size/return` | output | 17 025 | **2 526** | 18 |
| `visual/drawing_api/drawing_order` | output | 15 693 | **6 664** | 0 |
| `from_shumway/acid/acid-text` | output | 12 573 | **8 178** | 0 |
| `from_shumway/acid/acid-shapes-testing` | output | 69 480 | **48 555** | 0 |
| `from_shumway/acid/acid-stroke-0` | output | 68 406 | **52 786** | 0 |
| `visual/fonts/font_lookup_as3` | output | 40 512 | **34 560** | 72 |
| `from_gnash/misc-ming.all/place_object_test` | output | 61 404 | **42 819** | 0 |

`visual/fonts/duplicate_font` at **3 outlier channels against a limit of 0** is
the single closest un-flipped comparison in the corpus after this patch.

Two masks/clipping rows from the sibling wave-1 reports, for the record:
`visual/simple_shapes/masks` and `masks_equal_clipdepth` both move
248 261 → **242 782** (no flip — confirms `wave1-gfx-masks.md`'s ruling), and
`visual/avm2_button_scroll_rect` 34 590 → **34 083** with
`avm2/displayobject_scrollrect` 203 367 → **202 388** (confirms
`wave1-gfx-clipping.md` §2.4: the scrollRect defect, not AA, is their owner).

### 4.3 Unchanged — byte-identical PNG, i.e. NOT AA-sample owners (24)

`avm1/bitmap_data_copypixels`, `avm2/bitmapdata_colortransform`,
`avm2/bitmapdata_draw_alpha_erase`, `avm2/bitmapdata_draw_self_via_graphic`,
`avm2/bitmapdata_draw_rotation`, `avm2/edittext_always_show_selection`,
`avm2/mouse_pick_non_interactive_bitmap_mask`, `avm2/graphics_gradients_nulls`,
`from_shumway/flash_text_TextField`, `from_shumway/gradientTransform`,
`from_shumway/hardwrap`, `from_shumway/stylesheet`,
`from_shumway/acid/acid-gradient-2`, `from_shumway/acid/acid-image`,
`visual/cache_as_bitmap/morph`, `visual/cache_as_bitmap/nested_rotation`,
`visual/cache_as_bitmap/contains_grown_filter`, `visual/definefont4`,
`visual/fonts/device-font`, `visual/drawing_api/gradient_focal_point`,
`visual/edittext/edittext_bounds_vs_position`,
`visual/edittext/edittext_underline_scale2`, `visual/filters/glow_pass_scaling`,
`from_shumway/captions` (pixels moved, outlier count identical).

These are CPU-raster / bitmap-readback / text-raster owners. Confirms wave-1's
"different owner" bucket and bounds the blast radius: the knob touches only
GPU-tessellated edge coverage.

### 4.4 Corpus census remainder

210 failing comparisons declare `quality = "low"` (of 347 CI failures; the other
135 are `high`, 2 `best`). After this patch's 24 flips, the ~117 still-unsampled
low rows are dominated by families this knob provably cannot reach —
`visual/video/*` (h264, vp6, colorconversion), `avm2/stage3d_*`,
`visual/filters/*` proper, `avm2/pixelbender_*` — each carrying 10⁵–10⁶ residual
channels from a missing feature, not an AA fringe. **24 is close to the
practical ceiling of this lever**, not a floor as wave-1 hoped.

---

## 5. Canaries

### 5.1 Standing render canary (`render_canary_tests.txt`, all 20 tests, both tiers)

Run in both legs; partitioned by the test's own declared quality. Contract:
`quality != low` ⇒ **md5-identical**; `quality == low` ⇒ pixels may move, verdict
must not regress.

```
CANARY CLEAN: no non-low test moved a pixel; no verdict regressed.
```

* `quality = "high"` (4 tests, 10 PNGs) — `avm1/edittext_tag_indent`,
  `avm1/mask_with_drawing`, `from_shumway/timeline/timeline_as2_5` (7 cmps),
  `visual/blend_modes/{overlay_onto_stage,shader_without_shader}` —
  **all IDENTICAL**. This discharges wave-1 risk-register item 2: a `DIFFERS`
  here would have meant Step B mis-parses the toml. None occurred.
* no `quality` key (3 `regression/` tests) — **all IDENTICAL**
  (`avm2_morph` `skip`→`skip`, as it has no expected PNG).
* `quality = "low"` and AA-insensitive (axis-aligned / bitmap art) —
  `avm1/{color, bitmap_data_fillrect, bitmapdata_applyfilter_colormatrix,
  focusrect_swf5 (12 cmps), movieclip_setmask}`, `avm2/blend_multiply_alpha`,
  `from_shumway/{button1 (4 cmps), acid/acid-text-3}`,
  `visual/{cache_as_bitmap/shape_changed, simple_shapes/winding_rule}` —
  **IDENTICAL**, exactly the mechanism wave-1 predicted (1× and 4× coincide on
  axis-aligned edges).
* `quality = "low"` and AA-sensitive — pixels moved, **zero verdict regressions**.

Risk-register item 4 (stencil / clip masks share the sample count) is
discharged: `avm1/movieclip_setmask` is IDENTICAL and `visual/simple_shapes/masks`
moved 248 261 → 242 782 with no pipeline-creation failure. Pipeline creation is
loud, not silent, and the offscreen/filter paths ran clean in every one of the
104 AFTER-leg tests.

Wave-1's canary false-negative warning (item 1: "md5 A/B at the default 4 will
report IDENTICAL everywhere and prove nothing") is answered — the low-quality
rows in this canary set *do* carry the forced sample count, because the harness
derives it from each test's own toml rather than from a global flag.

### 5.2 The 12 currently-passing low-quality comparisons from wave-1 §5

**All 12 still pass.**

| comparison | before | after | PNG |
|---|---|---|---|
| `from_shumway/button1` output.1–.4 | pass | **pass** | identical |
| `avm1/color` output | pass | **pass** | identical |
| `from_shumway/gradient` output | pass | **pass** | moved |
| `from_shumway/acid/acid-gradient-0` output | pass | **pass** | moved |
| `from_shumway/acid/acid-text-3` output | pass | **pass** | identical |
| `visual/cache_as_bitmap/shape_changed` output | pass | **pass** | identical |
| `visual/blend_modes/shader_without_shader` output | pass | **pass** | identical |
| `visual/blend_modes/overlay_onto_stage` output | pass | **pass** | identical |

**Correction to wave-1 §5 / §2.5:** `visual/blend_modes/shader_without_shader`
and `overlay_onto_stage` are `with_renderer = { quality = "high" }`, not `low`
— so they were unaffected by construction, not by luck. The blend directory is
**not** uniformly `quality = "low"` as `wave1-gfx-blend.md` §2.5 states;
`add`/`multiply`/etc. are low, these two are high. Ten of the twelve probes are
genuinely low, and all ten hold.

Bonus: `from_gnash/misc-ming.all/loop/simple_loop_test` frame4 was already
passing and stayed passing while its six siblings flipped.

---

## 6. Files touched

| file | change |
|---|---|
| `SWFModernRuntime/src/rendering/render_webgpu.c` | +44/−10 — one `#ifndef` block, 8 literal→macro, 3 `#if MSAA_SAMPLES == 1` attachment guards |
| `ruffle-tests/verify_output.py` | +34/−0 — `get_msaa_samples()` + 6 lines in `compile_native`'s graphics branch |

Patch: `SWFRecompDocs/plans/session11-fanout-reports/w2-quality-msaa.patch`
(214 lines, generated from base `b4c983ea4`).

## 7. Merge risks

**Verified: the patch applies cleanly to the already-merged master.** Dry-run
`patch -p1` against the current `/home/robert/CC/SWFRecomp-CC` copies of both
files (which already contain the masks sibling's `render_webgpu.c` work and the
two siblings' `verify_output.py` edits):

```
render_webgpu.c : 14 hunks, all succeed (offsets +87 / +92 / +110)
verify_output.py:  2 hunks, both succeed (offsets +50 / +63)
```

No fuzz required, no conflicts. All 11 edit anchors survive verbatim in the
merged file; only line numbers shifted (the masks patch added ~87 lines between
`:1266` and the filter-resource block).

Residual risks to watch, in priority order:

1. **A future pipeline added with a hard-coded `multisample.count = 4` will fail
   pipeline creation at `MSAA_SAMPLES = 1`.** The failure is loud (Dawn
   validation error at startup, not a silent mis-render), but it would blank
   every low-quality test at once. I re-checked the merged master: it still has
   exactly **four** MSAA pipeline sites plus the one deliberate `count = 1`
   blit — the masks sibling's `restore_draw_pipeline` helper reuses existing
   pipelines and adds none. **Anyone adding a pipeline to `render_webgpu.c` must
   use `MSAA_SAMPLES`, not `4`.**
2. **`render_webgpu.c` hunks 13/14 (`resume_pass`, `begin_offscreen_pass`) sit
   closest to the masks sibling's "offscreen-pass parking" work.** They apply
   cleanly today, but both functions are ones that patch also reasons about; a
   *semantic* interaction (e.g. parking logic that assumes a resolve target
   always exists) would not surface in a textual apply. Nothing in the 104-test
   AFTER leg hit it, and that set exercises the offscreen path via
   `cache_as_bitmap/*`, `filters/*`, `blend_modes/*` and `pixelbender_effect_*`
   — but the AFTER leg ran against `b4c983ea4`, **not** the merged master.
   The combined CI run should be the arbiter.
3. **`verify_output.py` edits are deliberately localized** — one new
   module-level function inserted between two existing getters, and six lines
   inside the `mode == "graphics"` branch. No shared data structure, no
   signature change, no argparse change.
4. **Browser / WASM untouched.** `MSAA_SAMPLES` unset ⇒ 4; no emscripten build
   script gains a `-D`. `flashbang.c` untouched.
5. **Trace axis: no change.** No trace status moved in any of the 104 AFTER-leg
   tests (`avm2/displayobject_scrollrect` was `output_mismatch` in both legs).
   CPU-readback paths (`bitmapdata_*`) were explicitly swept and render
   byte-identically.

## 8. CI dispatch recommendation

Per wave-1 §7.6, this is a pixel-axis deliverable and must close out with
`mode=graphics`, `categories=all`, **`images=true`** — otherwise the 24 flips
are invisible and `image_results_graphics.json` / the `ruffle-image-results`
branch keep the stale 217 baseline.

## 9. Follow-ups

* **F5** (layer groups) for `blend_modes/layer_alpha` / `layer_erase` — still
  needed; the 66.8 k residual is real missing content, not AA.
* **F7-AVM2** for `avm2/displayobject_blendmode` (62 400) — untouched.
* **Do not** attempt the sub-pixel tie pixels (wave-1 §4): a global
  `stage_to_ndc` nudge is neutral-or-worse in both directions.
* **New:** `visual/fonts/duplicate_font` (3 channels over a limit of 0),
  `visual/drawing_api/fills_and_lines` (104) and
  `fonts/embed_matching/fallback_preferences` (156) are now the cheapest
  un-flipped pixel targets in the corpus.
* **Optional, not scoped here:** a real `Stage.quality` / `_quality` property.
  No flip depends on it.
