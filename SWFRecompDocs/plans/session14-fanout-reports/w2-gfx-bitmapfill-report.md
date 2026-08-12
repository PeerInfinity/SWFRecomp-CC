# w2-gfx-bitmapfill — repeating bitmap fills tile on the bitmap, not the layer

**Session 14, wave 2, PIXEL axis. Implementation.**
Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a6c8a37f88974d645`
Base: `0a99be1a9`. Brief: `SWFRecompDocs/plans/session14-fanout-reports/wave1-gfx-bitmapfill.md`.
Patch: `wave2/w2-gfx-bitmapfill.patch` (runtime only; 2 files).

---

## 0. Headline

1. **Implemented the brief's §5.2 formulation as written.** `bitmap_sizes` went
   from 2 u32/layer (padded only) to 4 u32/layer
   (`{content_w, content_h, padded_w, padded_h}`, WGSL `array<vec4u>`); the
   repeating arm (`0x40`/`0x42`) now tiles on `content`, the clipped arm
   (`0x41`/`0x43`) keeps its old expression character-for-character.
2. **`from_shumway/acid/acid-bitmap-fill` FLIPS, measured at CI fidelity.**
   `100 361 excess → 0`. The BEFORE render is byte-identical to the published CI
   actual (md5 `aa61028d9af1dff2f78be9e1442eeb77`), independently re-confirmed in
   this worktree, so this is a CI-grade absolute number, not a local guess.
3. **Margins came in at or slightly better than the brief's emulation**: tol 12
   **67 908/70 000** (brief's emulation: 67 937) and tol 128 **297/300**
   (identical). Mean channel drift 14.69 → 1.87.
4. **The headroom lever was NOT needed and was NOT applied.** The brief said to
   reach for Ruffle's linear sampler only if the real patch landed short of the
   emulation; it landed marginally ahead, so the sampler is untouched and the
   blast radius stays at one comparison.
5. **Leg-1 bit-identity holds**: every non-repeating bitmap fill in the canary
   set is md5-IDENTICAL before/after, and so is every non-bitmap test.

---

## 1. What changed (files + regions — for the serial merge)

| file | region | change |
|---|---|---|
| `SWFModernRuntime/src/rendering/render_webgpu.c` | **~93-99** (WGSL binding decl) | `bitmap_sizes: array<vec2u>` → `array<vec4u>` + comment |
| " | **~144-157** (WGSL vertex, `0x40` arm) | read `content`=`sizes.xy`, `padded`=`sizes.zw`; branch repeating vs clipped |
| " | **~277-280** (WGSL fragment, `0x40`/`0x42` arm) | `fract(v_args.xy / bm_ratio) * bm_ratio` → `fract(v_args.xy) * bm_ratio` |
| " | **~823-827** (`render_webgpu_init`) | `HALLOC` 2 → 4 u32/layer |
| " | **~1113-1120** (`create_buffers_and_upload`) | `bitmap_sizes_buffer` 2 → 4 u32/slot |
| " | **~2417-2427** (`draw_bitmap_quad_scaled`) | write `{src_w, src_h, bw, bh}`, stride 4 |
| " | **~2558-2571** (`draw_bitmap_tris`) | write `{bw-1, bh-1, bw, bh}`, stride 4 |
| " | **~2953-2966** (`render_webgpu_upload_bitmap`) | write `{width, height, bw, bh}`, stride 4 |
| " | **~2974-2977** (`render_webgpu_finalize_bitmaps`) | upload size 2 → 4 u32/layer |
| `SWFModernRuntime/include/rendering/render_webgpu.h` | **32-41** (`u32* bitmap_sizes`) | comment only |

**No pipeline descriptor, no bind-group layout, no sampler, no `MSAA_SAMPLES`
was touched.** `bitmap_sizes` is still vertex-stage-only at
`@group(0) @binding(3)`; the bind-group entry sizes itself with
`wgpuBufferGetSize`, so nothing there needed editing.

**Sibling-overlap check.** `gfx-stencil` is rewriting the stencil/mask model
around line ~1450 and the pipeline-creation block; `gfx-scrollrect` is in
`action.c` / `tag.c`; `describetype` is in `avm2_globals.c` / `avm2_class.*`.
My regions above are disjoint from all of those. No reflow, no drive-by edits —
`git diff --stat` is 2 files / +54 / −20, and most of the + lines are comments.

---

## 2. Why this formulation

`render_webgpu.c` keeps ONE `texture_2d_array` whose layers are all padded to
the largest bitmap in the movie (+1 edge-clamp row/col). `bitmap_sizes` recorded
that padded size, and the shader derived the repeat period as `padded − 1`. That
is only the bitmap's own size when the bitmap *is* the largest thing in the
array. `acid-bitmap-fill`'s 512×512 Lena shares a layer sized 801×601 (the test's
own 800×600 golden gets bundled as a data file and inflates
`dynamic_bitmap_max`), so it tiled every 800×600 texels with transparent gaps.

Ruffle has no such coupling: `swf_bitmap_to_gl_matrix`
(`render/src/tessellator.rs:356-383`) divides the inverted fill matrix by
`bitmap_width`/`bitmap_height` — the bitmap's own size — and lets the hardware
`AddressMode::Repeat` do the wrap. The fix stores the bitmap's own size
alongside the padded size and uses it as the period.

The clipped arm is deliberately left as `inv_pos / padded` rather than the
algebraically-equal `(inv/content)·(content/padded)`: under a `Nearest` sampler a
1-ULP wobble can flip `floor()` on an exact texel boundary, so keeping the
expression character-for-character makes the patch a *provable* no-op for every
`0x41`/`0x43` fill. §4 measures that it is.

`draw_bitmap_tris` (the `beginBitmapFill` path) pre-tiles the source across the
whole padded layer and therefore genuinely has a `bw−1` period; it records
`content = {bw−1, bh−1}` so its output is unchanged. Uploading only `src_w×src_h`
and setting `content = {src_w, src_h}` is the better model (no wrap seam, far
smaller per-draw upload) but it also requires the clipped arm to clamp to
`content`, so it stays a separate patch — noted in the code comment.

---

## 3. `acid-bitmap-fill` — absolute before/after vs the test.toml budgets

CI-fidelity licence, re-established in this worktree:

```
aa61028d9af1dff2f78be9e1442eeb77  .render_canary/before/from_shumway/acid/acid-bitmap-fill/output.png
aa61028d9af1dff2f78be9e1442eeb77  <ruffle-image-results ff5502cb8>/…/acid-bitmap-fill/output.actual.png
```

The unpatched local build also reproduces CI's grading numbers digit for digit
(100 661 outliers / max_diff 253 / diff_channels 532 303 / mean 14.6931).

| rung | budget | BEFORE outliers | BEFORE excess | AFTER outliers | AFTER excess |
|---|---:|---:|---:|---:|---:|
| tol 12 | 70 000 | 277 023 | 207 023 | **67 908** | **0** ✅ |
| tol 32 | 20 000 | 222 017 | 202 017 | 21 428 | 1 428 |
| tol 64 | 6 000 | 169 625 | 163 625 | 6 263 | 263 |
| tol 128 | 300 | 100 661 | 100 361 | **297** | **0** ✅ |
| **verdict** | any-check-passes | **FAIL** | 100 361 | **PASS** | **0** |

`max_diff` 253 → 192, `diff_channels` 532 303 → 506 812, `mean_diff`
**14.6931 → 1.8674**. The deciding rung is tol 12 with 2 092 channels of
headroom (3.0 %); tol 128 also passes but with only 3 (1.0 %) — report the flip
with that named risk, exactly as the brief asked.

Verified twice: once through `verify_output.py --images` itself
(`"status": "pass"`) and once through a standalone `compare_images` harness that
re-grades each rung separately (`compare_images` only reports stats for the last
check in the ladder).

---

## 4. Leg-1 proof — non-repeating bitmap fills are bit-identical

`render_canary.py compare before after`, list `wave2/canary_bitmapfill.txt`
(18 tests / 21 comparisons):

```
  IDENTICAL    20
  DIFFERS       1
  APPEARED      0   VANISHED 0   NO_RENDER 0

  DIFFERS:
    from_shumway/acid/acid-bitmap-fill  output   [DIFFERS]
        diff_channels 281712/1920000  mean 13.9994  max 255   bbox (23,31)-(574,505)
        image status: fail -> pass    trace: pass -> pass

  TRACE STATUS CHANGES: (none)
```

Per-comparison md5 (first 8 hex):

| test | cmp | md5 before | before vs after | image | trace |
|---|---|---|---|---|---|
| `avm1/bitmap_data_copypixels` | output | `d6c4e03f` | **IDENTICAL** | fail → fail | pass → pass |
| `avm1/bitmap_data_fillrect` | output | `c2626aa5` | **IDENTICAL** | pass → pass | pass → pass |
| `avm1/color` | output | `44a2ebac` | **IDENTICAL** | pass → pass | pass → pass |
| `avm2/bitmap_pixelsnapping` | output | `9297176a` | **IDENTICAL** | fail → fail | pass → pass |
| `avm2/bitmapdata_draw` | output | `10da020a` | **IDENTICAL** | fail → fail | pass → pass |
| `avm2/graphics_bitmap_fill` | output | `e8699041` | **IDENTICAL** | fail → fail | pass → pass |
| `avm2/graphics_bitmaps` | output | `8d824305` | **IDENTICAL** | fail → fail | pass → pass |
| `from_gnash/misc-ming.all/BeginBitmapFill` | output | `45765d50` | **IDENTICAL** | fail → fail | pass → pass |
| `from_gnash/misc-swfmill.all/missing_bitmap` | output | `5eeeb504` | **IDENTICAL** | pass → pass | pass → pass |
| `from_shumway/acid/acid-bitmap-fill` | output | `aa61028d` | **DIFFERS** → `611f8c34` | **fail → pass** | pass → pass |
| `from_shumway/acid/acid-bitmap-fill-2` | output | `408052b5` | **IDENTICAL** | pass → pass | pass → pass |
| `from_shumway/acid/acid-bitmapData-copyPixels` | output | `e59bee63` | **IDENTICAL** | fail → fail | pass → pass |
| `from_shumway/acid/acid-blend-2` | output.10 | `a5bcde80` | **IDENTICAL** | pass → pass | pass → pass |
| `from_shumway/acid/acid-blend-2` | output.15 | `8d52f770` | **IDENTICAL** | pass → pass | pass → pass |
| `from_shumway/acid/acid-blend-2` | output.20 | `5141f14b` | **IDENTICAL** | pass → pass | pass → pass |
| `from_shumway/acid/acid-blend-2` | output.26 | `2ae3d818` | **IDENTICAL** | fail → fail | pass → pass |
| `from_shumway/acid/acid-blend-2` | output.40 | `d790f125` | **IDENTICAL** | pass → pass | pass → pass |
| `from_shumway/acid/acid-color-0` | output | `d2626209` | **IDENTICAL** | fail → fail | pass → pass |
| `from_shumway/acid/acid-gradient-0` | output | `e8d2dbfc` | **IDENTICAL** | pass → pass | pass → pass |
| `from_shumway/acid/acid-large` | — | *(no png)* | — | — | compile_fail → compile_fail |
| `from_shumway/bitmapbuttons` | output | `a8feff70` | **IDENTICAL** | fail → fail | pass → pass |
| `regression/mask_sibling_union` | output | `26d21480` | **IDENTICAL** | pass → pass | pass → pass |

Coverage of the paths the patch can physically reach:

* **`0x41`/`0x43` clipped static fills** (the brief's 16 "clipped-only" movies):
  `acid-bitmap-fill-2`, `acid-color-0`, `acid-blend-2` (×5), `bitmapbuttons`,
  `missing_bitmap`. All IDENTICAL. Note `acid-blend-2 output.15/26` — which
  wave1-board-audit hoped might get relief from this fix — is unmoved, exactly
  as the brief predicted (it uses `0x43` clipped fills, which this patch cannot
  touch).
* **`draw_bitmap_tris`** (`beginBitmapFill`, the `{bw-1, bh-1}` content trick):
  `avm2/graphics_bitmap_fill`, `avm2/graphics_bitmaps`,
  `from_gnash/misc-ming.all/BeginBitmapFill`. All IDENTICAL — the byte-identity
  caveat in the brief's §5.3 is confirmed empirically, not just argued.
* **`draw_bitmap_quad_scaled`** (dynamic `0x41` quad): `avm1/bitmap_data_fillrect`,
  `avm1/bitmap_data_copypixels`, `avm2/bitmapdata_draw`,
  `avm2/bitmap_pixelsnapping`, `acid-bitmapData-copyPixels`. All IDENTICAL.
* **Non-bitmap smoke** (a broken WGSL compile or bind-group layout would blank
  everything): `avm1/color`, `from_shumway/acid/acid-gradient-0`,
  `regression/mask_sibling_union`. All IDENTICAL.

**Trace axis: zero movement.** Every rendered test is `pass → pass`; the compare
reports `TRACE STATUS CHANGES: (none)`. The patch is WGSL + a GPU storage-buffer
stride and has no AVM reachability at all.

Two caveats, both benign:

* `from_shumway/acid/acid-large` reports `compile_fail` in **both** legs
  (compile phase 495 s before / 302 s after, machine at load ~19). It failed
  identically with **unpatched** sources, so it is the known long-compile
  false-positive mode, not a regression. It is a `0x41` clipped-only movie, so
  the character-identical clipped arm covers it by construction, and five other
  clipped movies carry the empirical proof.
* Seven of the brief's clipped-only movies (`avm1/click_block`,
  `avm2/click_block`, `avm1/issue_2084`, `from_gnash/misc-ming.all/{VarAndCharClashTest,loading/loadMovieTest}`,
  `from_shumway/avm1/mouse-transparency`, and the second repeating-fill movie
  `from_gnash/misc-ming.all/BitmapDataDraw`) declare **no** `[image_comparisons]`
  upstream, so they never render and are ungraded on CI — they cannot regress the
  pixel axis and were dropped from the canary to buy compile budget on a machine
  running five concurrent agents. `BitmapDataDraw` *will* change output (it is the
  only other repeating fill in the corpus), correctly and unobservably.
* `avm1/netstream_play_flv_screen`, `avm2/pixelbender_dithering` and
  `_swfbridge/livetest/n_loader/native_run` were likewise dropped for budget;
  all three are `0x41` clipped-only.

---

## 5. Stretch items

### 5.1 `acid-bitmap-draw_quality_{high,low}` — gate identified, NOT fixed

The brief named two candidate gates in `avm2_render_bitmap`
(`SWFModernRuntime/src/avm2/avm2_display.c:14713-14728`). A temporary `fprintf`
probe (added, run, **fully reverted** — the regenerated patch is byte-identical
to the one written before the probe) settles it:

```
[PROBE] avm2_render_bitmap ext=0x…a20 bd_obj=0x…020
[PROBE] bd=0x…160 disposed=0 pixels=0x…1a0 w=512 h=512  maxw=256 maxh=256
   (twice — once per render pass; "PASSED ALL GATES" never printed)
```

**`ext->bitmap_data` is fine.** The killer is the size gate: the movie builds a
**512×512** `BitmapData` on a **256×256** stage, and
`context->dynamic_bitmap_max_{w,h}` is 256 because `avm2_display.c:15745-15751`
computes it as `max(stage_w, stage_h, 256, bitmap_highest_*)` — and this SWF has
**no embedded bitmap characters**, so `bitmap_highest` is 0. Every runtime
`BitmapData` bigger than the stage is silently dropped, which is exactly the
"honest failure" the comment there describes. Flat white follows.

**Why I did not ship a fix.** The obvious one-liner — raise the AVM2 floor from
256 to 512 — is a corpus-wide VRAM change, not a local one: the shared
static+dynamic array is `(bitmap_count + 64)` layers of `(max+1)²×4 B`, so a 256
→ 512 floor takes every embedded-bitmap-free AVM2 movie from ≈17 MB to ≈67 MB of
texture. A downscale-on-upload is wrong here (the `Bitmap` is drawn at 512×512
onto a 256×256 stage, i.e. deliberately cropped to its top-left quarter — the
golden shows exactly that), so the real fix is to grow the dynamic layer
on demand, which means recreating the texture, its view and the bind group and
re-uploading the static bitmaps. That is a standalone patch with its own A/B,
not a stretch item.

Priced as the brief did: **+1 max** (`_low` is upstream `known_failure`, and both
halves share one SWF), MED-HIGH effort, cluster `blank_render`, owner = AVM2
Bitmap display / dynamic-layer sizing. Handing it on with the gate now named
rather than guessed.

### 5.2 `acid-bitmapData-copyPixels` — not touched

Left where wave 1 put it: a `copyPixels` sourceRect/destPoint clipping defect
reached through the `0x41` quad path, worth +0 (refuted rider). The canary
confirms this patch leaves it bit-identical (`e59bee63`, fail → fail). No
further diagnosis attempted — the compile budget went to §5.1, which is the one
with a flip attached.

### 5.3 Deliberately not done

* **Ruffle's linear sampler for smoothed fills** (the brief's named headroom
  lever). Not needed — see §0.4. It would move every bitmap draw in the corpus
  and needs a second sampler + bind group; it stays available if CI's lavapipe
  lands short of local Dawn on the tol-12 rung.
* **Clipped-fill clamp beyond the +1 padding texel** — real divergence from
  Ruffle, no graded victim.
* **`draw_bitmap_tris` de-tiling** — the better model, but it needs the clipped
  arm to clamp to `content`; a second patch with its own A/B (comment left at
  the site).
* **Harness hygiene** (`verify_output.py::find_data_files` bundling
  `output.expected.png` as a runtime data file, which is what inflated this
  test's layer to 801×601 and inflates VRAM corpus-wide). Confirmed still true
  at `verify_output.py:1887-1889` — `.png` is in neither `skip_names` nor
  `skip_suffixes`. It is the *upstream* cause but not a substitute for the
  renderer fix, and shipping it alone would be fixing the harness to pass the
  test. Separate hygiene commit if wanted.

---

## 6. Expected-flip ledger at CI

| comparison | before (CI run `31130292354`) | expected after |
|---|---|---|
| `from_shumway/acid/acid-bitmap-fill [output]` | fail, 100 361 excess, `d_moderate` / `diffuse_mixed` | **PASS** — deciding rung tol 12, 67 908/70 000 (3.0 % headroom); tol 128 also passes at 297/300 (1.0 %) |

Everything else: **byte-identical**. `from_gnash/misc-ming.all/BitmapDataDraw`
changes correctly but has no `[image_comparisons]`, so it is invisible to the
grade. **Net predicted flips: +1 pixel comparison, 0 trace.** A DIFFERS anywhere
else on CI is a bug in this patch, not a rider.

Residual risk, stated plainly: the flip is measured on local Dawn, licensed by
md5 byte-identity between the local BEFORE render and the published CI actual
(`aa61028d…`), which is the strongest fidelity evidence available short of a CI
run. If lavapipe diverges from Dawn on this frame the tol-12 rung has 2 092
channels of slack and the tol-128 rung has 3; the tol-12 rung is the one to
watch, and §5.3's linear sampler is the lever if it lands short.

---

## 7. Reproduction

```bash
WT=/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a6c8a37f88974d645
export CCACHE_BASEDIR=/home/robert/CC CCACHE_NOHASHDIR=1 DAWN_INSTALL=$HOME/CC/dawn-install
python3 $WT/ruffle-tests/render_canary.py capture --label before \
    --tests $WT/wave2/canary_bitmapfill.txt --recompile -P 2 --timeout 1800
git apply $WT/wave2/w2-gfx-bitmapfill.patch
python3 $WT/ruffle-tests/render_canary.py capture --label after  … (same flags)
python3 $WT/ruffle-tests/render_canary.py compare before after
```

Notes for whoever repeats this:

* Test dirs were copied into the canonical in-worktree suite paths and run with
  `--recompile` on first use; `SWFRecomp/build` was copied from the main tree
  (runtime-only patch, no cmake rebuild needed). `--tests-dir` never pointed at
  the main tree.
* `CCACHE_BASEDIR=/home/robert/CC` + `CCACHE_NOHASHDIR=1` is what makes a second
  leg affordable: without them every `(test, label)` build dir produces a unique
  `-ffile-prefix-map=` and the whole runtime misses ccache. With them the two
  legs share every object except `render_webgpu.o`. The machine was at load ~19
  with five sibling agents compiling; a cold test cost ~3m45s.
* Seven clipped-only movies carry no upstream `[image_comparisons]` and so never
  render. Their `test.toml` was given a dummy comparison **in this worktree's
  gitignored test copies only** to force a render; they were ultimately dropped
  from the canary for compile budget (§4). That test.toml edit is not in the
  patch and must not be committed.
