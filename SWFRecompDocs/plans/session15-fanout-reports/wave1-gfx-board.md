# Session 15 — wave 1 — PIXEL-AXIS BOARD (w1-gfx-board)

**Agent:** w1-gfx-board · read-only diagnosis · no source edits, no commits.
**Method:** `graphics-fanout-playbook.md` §2 (board), §3 (dispositions), §4 (accounting),
§7 (provenance).

## PROVENANCE (read this before using any number below)

| | |
|---|---|
| Grading run | `31647430265` at `bf585e4486b64a263abbd336a51f3baf3cd00a03` (graphics / categories=full / images=true) |
| Per-suite stems | all 12 `_results/image_results_graphics.json` carry `run_id=31647430265`, `git_sha=bf585e448` — **consistent, no mixed-run stems** |
| `ruffle-image-results` | `01e9f2321` "Ruffle image comparison failures", 2026-08-12T23:11:24Z, 251 `*.actual.png` — same run |
| Board command | `python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 3` (19.4 s) |
| Raw board | copied next to this file as `wave1-gfx-board.rawboard.md` (full cluster table, cluster×band, top-40, disposition audit) |

**Baseline CONFIRMED: 310 / 569 unique comparisons = 54.48 %.**
Arithmetic: index.json totals = 570 comparisons / 310 pass / 257 fail / 3 skip
(5 of the 257 fails are `no_render`); minus the one `from_shumway/avm1/*` nested
double-count → denominator 569 (playbook standing fact #2, restated 566→567→569 by
upstream drift). Per-suite: avm1 62/69 · avm2 52/123 · fonts 1/4 · gnash-ming 7/18 ·
gnash-swfmill 2/2 · from_shumway 79/123 · from_shumway/avm1 0/1 · import_assets 0/1 ·
regression 4/7 (3 skip) · stage3d 0/3 · text 1/5 · visual 102/214.

Board decomposition of the 256 deduped failing comparisons:
**219 live** (202 test×cluster rows) · 37 excluded = 8 hard-dispositioned +
23 Ruffle `known_failure` + 5 `no_render` + 1 `png_unavailable`.

---

# PART 1 — RANKED, PRICED PIXEL LEADS FOR WAVE 2

Ranked by **mechanism × evidence strength × cost**, not by near-pass distance
(playbook standing fact #3). "PROVEN" = I reproduced the flip or the failure
locally this session.

---

## P1 — GO (PROVEN, +2 flips, one constant) — capture-trigger table is capped at 16

**Owner file:** `SWFModernRuntime/src/libswf/capture.c:22` —
`#define DEFAULT_MAX_CAPTURES 16`, and `parse_capture_triggers()` stops tokenising at
`g_capture_count < g_capture_cap`. `CAPTURE_MAX` overrides it but **nothing in
`verify_output.py` or the CI workflow ever sets it** (grep: the only `CAPTURE_MAX` hits
in `ruffle-tests/` are the unrelated `SWF_CORE_CAPTURE_MAX` core-dump limiter).

`from_shumway/acid/acid` declares **18** image comparisons (`output.01`…`output.18`).
Triggers 17 and 18 fall off the end of the table, are never registered, are never
captured, and grade as `no_render`.

**Measured, locally, this session:**

```
CAPTURE_MAX=32 python3 ruffle-tests/verify_output.py --tests-dir=<scratch>/from_shumway \
    --test=acid/acid --mode=graphics --images --recompile
  → output.01 … output.16 PASS   (unchanged)
  → output.17 PASS  "11987 outliers (limit 13000), max difference 204"
  → output.18 PASS  "12073 outliers (limit 13000), max difference 204"
```

**Predicted flips: +2** (`from_shumway/acid/acid [output.17]`, `[output.18]`) —
proven, not estimated.
**Predicted band moves:** none.
**Risk: zero.** Not a renderer change, not a trace change; it only widens a
parse table. Recommended fix: size the table from the token count (or raise the
default to 64) rather than hard-coding a new magic number — `acid` at 18 is the
current worst case but the cap will bite again.
**Cost:** ~5 lines, runtime-only, no cmake rebuild of the recompiler.

*Scope note:* `acid` is the ONLY test in the corpus with >16 comparisons, so this
is exactly +2 and nothing else moves.

---

## P2 — GO (highest fan-out on the board) — curve flattening is systematically FINER than Ruffle's, so every curved boundary sits one pixel outside

This is the mechanism that unifies the biggest live cluster
(`hairline_edge_drift`, 67 cmps / 57 tests / 47 near-passes) and it is *not* the
lavapipe-AA gap the cluster name implies.

### Mechanism (three concrete divergences, all in one function)

`SWFRecomp/src/swf.cpp:8653` flattens every SWF quadratic at **recompile time**:

```c
u32 num_passes = 6;                               // <-- HARD FLOOR
const float curve_flatten_tol_twips = 1.0f;       // 0.05 px at 1:1
float dev = 0.5f * hypot(ctrl - (from+to)/2);
if (dev > tol) num_passes = max(num_passes, min(64, ceil(sqrt(dev/tol))));
addCurvedEdge(..., num_passes, ...);              // UNIFORM parameter steps
```

Ruffle (`~/CC/ruffle/render/src/tessellator.rs:168`) does:

```rust
let tolerance = FillOptions::DEFAULT_TOLERANCE / scale;   // DEFAULT_TOLERANCE = 0.1
```

and lyon 1.0.6 flattens quadratics with Raph Levien's parabola-integral stepping
(`lyon_geom/src/quadratic_bezier.rs::FlatteningParameters::new` +
`t_at_iteration`), i.e.
`count = ceil(0.5 · |∫Δ| · sqrt(scale/tolerance))` with **non-uniform** `t`.

Three divergences, all pushing the same way:

1. **The 6-chord floor.** Lyon emits `count` segments, which for a shallow arc is
   1 or 2. We never emit fewer than 6. On shallow arcs our inscribed polygon is
   therefore far closer to the true curve — i.e. **strictly larger** — than
   Ruffle's. This is the dominant term and it is a pure bias, not noise.
2. **Tolerance 0.05 px vs 0.1 px** (2× finer) — same direction (s14 already
   recorded "our 0.05 px screen tolerance is half lyon's 0.1 px").
3. **Uniform `t` vs Levien `t`** — changes individual vertex positions even at
   equal chord counts.

SWF carries **only quadratics** (no cubics), so a faithful port of lyon's
quadratic flattener is a bounded job and can in principle be *vertex-identical*
to Ruffle for the unscaled case.

### Evidence (measured this session, direction census over every live comparison with excess ≤ 1000)

For each comparison I classified each differing pixel as "ours has ink where
Ruffle has background" (**ours bigger**) vs the reverse. A rasteriser *tie* would
be ~symmetric. These are not:

| comparison | excess | diff px | ours-bigger | ours-smaller | quality |
|---|---:|---:|---:|---:|---|
| `avm2/displayobject_mask [output]` | 8 | 4 | 4 | 0 | low |
| `visual/avm2_button_scroll_rect [output]` | 9 | 3 | 3 | 0 | low |
| `text/auto_size/height [output]` | 12 | 5 | 4 | 1 | low |
| `avm2/loader_events [output]` | 16 | 8 | 8 | 0 | low |
| `avm2/loader_loadbytes_events [output]` | 16 | 8 | 8 | 0 | low |
| `from_shumway/MaskTest [output]` | 17 | 17 | 15 | 2 | low |
| `avm2/mouse_pick_dobj_mask [output]` | 24 | 8 | 8 | 0 | low |
| `avm2/mouse_pick_non_interactive_dobj_mask [output]` | 24 | 8 | 8 | 0 | low |
| `from_shumway/doubleAndRegister [output]` | 32 | 16 | 16 | 0 | low |
| `visual/simple_shapes/scroll_rect_mask [output]` | 42 | 21 | 16 | 5 | low |
| `avm2/displayobject_hittestpoint_boundary [output]` | 76 | 488 | 368 | 120 | high |
| `visual/drawing_api/fills_and_lines [output]` | 104 | 45416 | 94 | 0 | low |
| `avm2/graphics_simple_shapes [output]` | 252 | 126 | 83 | 0 | low |

**13 of 14 are `quality = "low"` → `MSAA_SAMPLES = 1`**, which is exactly where a
sub-pixel polygon difference becomes a hard include/exclude instead of a coverage
blend. That co-occurrence is the fingerprint.

Geometric confirmation on `avm2/displayobject_mask`: the four differing pixels are
`(43,10) (56,10) (10,43) (10,56)` — four-fold symmetric about `(49.5, 49.5)` on a
circle of radius ≈39.5, i.e. the four points where the arc is *tangent* to an axis
and the chord sagitta is largest. That is the flattening signature, not an AA
signature.

Same signature at scale on the (currently dispositioned) pair — see §Hygiene-1:
`visual/simple_shapes/masks` is an **ellipse mask**; 482 of its 652 differing
pixels are ours-black-over-expected-white on the ellipse boundary, net **+499
black pixels**, mean edge offset **≈0.62 px**.

### Pricing

- **Predicted flips: 4–9.** The ≤42-excess members (`displayobject_mask`,
  `avm2_button_scroll_rect`, `auto_size/height`, `loader_events`,
  `loader_loadbytes_events`, `MaskTest`, `mouse_pick_dobj_mask`,
  `mouse_pick_non_interactive_dobj_mask`, `doubleAndRegister`,
  `scroll_rect_mask`) all need only a handful of boundary pixels to move.
  I price 4–9 rather than 10 because getting the *direction* right does not
  guarantee vertex identity.
- **Predicted band moves: ≥12**, incl. `simple_shapes/masks` ×2 (1738 each),
  `fills_and_lines` (104), `graphics_simple_shapes` (252),
  `displayobject_hittestpoint_boundary` (76), plus riders in the
  `Shumway acid` and `Text: embedded fonts / glyphs` slices (glyph outlines are
  quadratics too: `visual/fonts/glyph` 6, `duplicate_font` 3,
  `acid-text-x` 6, `acid-text-6[frame5]` 12).
- **Possible rider:** `from_shumway/acid/acid-blend-2 [output.26]` — see P9.

### Risk — read before scoping

- **Recompiler change** (`SWFRecomp/src/swf.cpp`) ⇒ worktree needs its own cmake
  build **and** `--recompile`; a stale binary reports IDENTICAL everywhere
  (playbook §6 false-negative #1).
- **Blast radius is every shape in the corpus.** Removing the 6-chord floor makes
  shallow curves *coarser* and can regress currently-passing comparisons. The
  floor's own comment says it "only ever REFINES a curve, never coarsens one" —
  that safety property is precisely the bias.
- **Our tolerance cannot be scale-aware.** Ruffle tessellates at runtime with the
  live `scale`; we flatten at recompile time in twips. For scale ≠ 1 we can only
  approximate. This is why s14's naive "raise tolerance to 0.1 px" leg made
  `acid-scale` *worse* (302→342): that test's diff is mixed-direction
  (46 extra / 105 missing) and lives on the scale axis, not the floor axis.
  **A wave-2 agent must A/B the FLOOR removal and the TOLERANCE change as two
  separate legs**, not as one patch.
- Morph shapes take `num_passes` from the index-pairing pre-pass (s14) — any
  change must keep both sides of a morph in agreement or the pairing desyncs.

### Suggested wave-2 protocol

1. Leg A: remove the `num_passes = 6` floor only (keep tol = 1 twip). Canary + the
   13 named comparisons.
2. Leg B: A + tolerance 2 twips (= 0.1 px at 1:1).
3. Leg C: A + B + port `FlatteningParameters` (≈40 lines of C, formulas quoted
   above; source `lyon_geom-1.0.6/src/quadratic_bezier.rs`).
4. Use `visual/simple_shapes/masks` as the **instrument** (tolerance 0, quality
   low, flat colours, no AA — the most sensitive row we have), not as a flip target.

---

## P3 — GO with a redesign, NO-GO as briefed — dynamic-bitmap VRAM (this is task 4)

### The briefed question

*"acid-bitmap-draw_quality: dynamic_bitmap_max size-gate (VRAM 17 → 67 MB per AVM2
movie) — gate or not?"*

**Verified facts** (ABC disassembly of `from_shumway/acid/acid-bitmap-draw_quality_high/test.swf`):

- Stage `256 × 256`; AVM2 (`DoABC`); **no `DefineBits*` characters at all** →
  `bitmap_count = 0`, `BITMAP_HIGHEST_{W,H} = 0`.
- `frame1` method body pushes `pushshort 512, pushshort 512` into the
  `BitmapData` construction → **`new BitmapData(512, 512)`**, then `draw`,
  then `new Bitmap(d)` + `addChild`.
- `avm2_display.c:15751-15758` sets
  `dynamic_bitmap_max = max(stage_w, stage_h, bitmap_highest_{w,h}) = 256`.
- `avm2_render_bitmap` (`avm2_display.c:14730`) then **skips the whole
  BitmapData** ("honest failure") → `blank_render`, 194 784 excess.
- Texture array today: `(256+1)² × 4 B × (0 + MAX_DYNAMIC_BITMAPS 64)` = **16.87 MB**.
  At cap 512: `(512+1)² × 4 × 64` = **67.36 MB**. The brief's 17→67 MB is exact.

### Verdict on the briefed change: **NO-GO**

1. **4× VRAM on every AVM2 movie to unblock one test**, and 512 is not a bound —
   the next oversized BitmapData needs 1024 and the cost goes to 269 MB.
2. **The same over-allocation is already a live failure.** `from_shumway/acid/acid-large`
   embeds a **3612 × 2680** JPEG (`DefineBits` id 1, SOF parsed from
   `JPEGTables`+`DefineBits`). Its array is
   `3613 × 2681 × 4 × (1 + 64)` = **2.52 GB**. I ran the built binary directly:

   ```
   Warning: ../src/gallium/frontends/lavapipe/lvp_device.c:2428: VK_ERROR_OUT_OF_DEVICE_MEMORY
   render_webgpu_save_png: buffer map failed (status 4)
   [capture] Failed to save .../output.png
   ```

   → `acid-large [output]` is `no_render` **because of `MAX_DYNAMIC_BITMAPS = 64`**,
   not because of anything in the timeline. Raising the cap makes this class worse.
   (`generated constants.h`: `BITMAP_HIGHEST_W 3612`, `BITMAP_HIGHEST_H 2680`.)
3. **It buys a band move, not a flip.** `acid-bitmap-draw_quality_high`'s tightest
   check is `tolerance = 64, max_outliers = 0` on a `BitmapData.draw()` of a
   MovieClip at `quality = "high"` — the same resampled-draw class s12 explicitly
   DEFERRED for `bitmapbuttons` as unwinnable at `max_out 0`.
   `acid-bitmap-draw_quality_low` is a Ruffle `known_failure`, so the ceiling is +1.

### Verdict on the redesign: **GO**

Decouple the dynamic layers from the static bitmap dimensions and put the array on
a byte budget:

- allocate dynamic layers sized to `dynamic_bitmap_max`, **not**
  `max(bitmap_highest, dynamic_bitmap_max)` (today one huge embedded JPEG
  multiplies its own size by 65); and/or
- `layers = clamp(VRAM_BUDGET / (bw·bh·4), 4, MAX_DYNAMIC_BITMAPS)` with
  `VRAM_BUDGET ≈ 64–128 MB`.

Under a 128 MB budget: `acid-large` drops 2.52 GB → ~128 MB and can render;
`acid-bitmap-draw_quality` can raise its cap to 512 for **67 MB on that movie
only**, leaving every other AVM2 movie at 17 MB.

**Whole-corpus VRAM audit** (largest embedded bitmap × current formula, over all
232 failing tests): `acid-large` 2518 MB is the ONLY outlier; next are
`avm2/pixelbender_dithering` 141 MB, `from_shumway/bitmapbuttons` 83 MB,
`avm2/stage3d_raytrace` / `away3d_advanced_shallow_water_demo` 74 MB, then ≤70 MB.
`from_shumway/acid/acid-color` (1840², ≈881 MB) currently **passes**, so the
practical ceiling on CI's lavapipe is between 0.9 GB and 2.5 GB.

**Pricing:** +1 flip candidate (`acid-large` leaves `no_render`; it then still has
to clear `tolerance = 11`, unproven — price it as "≥1 status change, flip
unproven") + 1 band move (`acid-bitmap-draw_quality_high`, 194 784 → resampling
residual). Runtime-only (`render_webgpu.c`, `avm2_display.c`). Medium risk: this
touches the allocation path every graphics test walks — canary is mandatory.

---

## P4 — GO (moderate confidence, HIGH blast radius) — `hasPlayingSprites()` does not recurse, so a movie whose only animation is a grandchild sprite exits after one tick

`SWFModernRuntime/src/libswf/tag.c:12013`:

```c
int hasPlayingSprites(void) {
    for (size_t i = 1; i <= max_depth; i++) {          // ROOT display list only
        Character* ch = &dictionary[display_list[i].char_id];
        if (ch->type == CHAR_TYPE_SPRITE && ch->sprite_frame_count > 1 && ...) return 1;
    }
    return 0;
}
```

Compare `hasClipEnterFrameHandlers_impl()` twenty lines below, which *does* recurse
through `sprite_display_list`.

`from_shumway/acid/acid-video` structure (parsed): root = **1 frame**, root places
only `DefineSprite id=7` which has **1 frame**; the 39-frame `DefineSprite id=6`
lives *inside* sprite 7. So `quit_swf` is set at the end of frame 0, the keep-alive
gate in `swf.c:504` sees no playing sprite, and the loop breaks after tick 1.

**Measured locally** (scratch copy with triggers added at 2–12):

```
output.01 PASS ; output.02..output.12, output.20 → "No actual image produced"
execution time 1.19 s for a nominal 20-frame movie
```

i.e. exactly one tick. (Contrast `from_shumway/acid/acid`, also a 1-frame root, which
places its 120/121-frame sprites *directly at root* and therefore does run all 18 ticks.)

**Predicted flips: +2** (`acid-video [output.10]`, `[output.20]`) at moderate
confidence — the loop will reach the triggers, but the frames then have to match.
`output.01` already passes with 14 192/20 000 outliers, so the content pipeline is
sound.
**Risk: HIGH on the TRACE axis.** Every 1-frame-root movie with nested animation
currently stops early and would now run to `MAX_FRAMES`, executing more enterFrame /
clip-action work. This needs a full dual-axis CI run, not just the render canary.
**Cost:** ~15 lines (mirror the `hasClipEnterFrameHandlers_impl` recursion).

---

## P5 — GO (+1 flip, small, recompiler) — `DefineBitsLossless2` format 4 (RGB15) is emitted as a fully transparent placeholder

`SWFRecomp/src/swf.cpp:1853-1856`:

```cpp
case 4:
    // Invalid for DefineBitsLossless2. Emit transparent placeholder.
    fprintf(stderr, "DefineBitsLossless2 format 4 is invalid per spec; emitting transparent bitmap ...");
    emit_transparent_placeholder = true;
```

The Lossless**1** path already has a correct RGB15 decoder at `swf.cpp:1727`
("big-endian u16, 1pad/5R/5G/5B, 5→8 = (c*255+15)/31"). Ruffle decodes format 4 in
Lossless2 as RGB15 with opaque alpha; the new upstream test
`visual/define_bits_lossless2_rgb15` exists specifically to pin that.

Grading run: `50 × 50`, `tolerance 2`, `max_outliers 0`, **5282 of 10 000 channels
differ, mean diff 119.4** — consistent with "we draw nothing, Ruffle draws an image".

**Predicted flips: +1.** **Cost:** ~20 lines (reuse the Lossless1 branch, force
`a = 255`). Recompiler change ⇒ cmake + `--recompile`.

⚠ **BLOCKER FOR THE WAVE-2 AGENT:** `ruffle-tests/tests/swfs/visual/define_bits_lossless2_rgb15/`
**does not exist in this checkout** and is not in `~/CC/ruffle` either — both mirrors
are stale relative to the CI run. Re-sync the corpus (`download_tests.sh`) or fetch
that directory before starting. This is also why the board classifies the row as
`png_unavailable` rather than by mechanism.

---

## P6 — GO (feature work) — `DisplacementMapFilter` is a no-op

Side-by-side of `visual/filters/displacement_map_through_filters` (ours left):
we render the source bars **undisplaced** (straight bars, horizontal rules);
Ruffle renders three skewed bars and slanted rules. The filter is simply not
applied.

| comparison | excess | budget | diff px |
|---|---:|---:|---:|
| `visual/filters/displacement_map [output]` | 123 279 | 160 | 92 047 |
| `visual/filters/displacement_map_scales_with_screen [output]` | 99 353 | 0 | 33 463 |
| `visual/filters/displacement_map_through_applyFilter [output]` | 27 565 | 0 | 9 705 |
| `visual/filters/displacement_map_through_filters [output]` | 27 565 | 0 | 9 705 |

The two `_through_*` rows are **byte-identical** (same excess, same diff-pixel
count, same bbox) → one implementation covers both.

**Predicted: 0–4 flips, 4 large band moves.** The displacement math is exact
integer arithmetic per the Flash spec, so exactness is achievable in principle,
but these are filter renders with resampling — price conservatively.
Runtime-only (`render_webgpu.c` + the filter compositor s12 built).

---

## P7 — DIAGNOSE FIRST — `blur_quality` / `blur_fractional` are TWO defects, and §13's label describes the wrong one

Side-by-sides show, identically in both tests:

- **(A) ~30 % of the 800 × 800 stage is never drawn.** Our black backdrop ends on a
  *staircase* boundary (same staircase in both tests); Ruffle covers the full square.
  This is the "extra_element / structural extra ink" the board and §13 report — but
  the extra ink is a *consequence* of the missing cells, not a filter defect.
  Signature matches a shared dynamic-vertex/rect capacity cap (cf. s11's
  `MAX_DYNAMIC_VERTICES` lesson on `place_object_test`).
- **(B) No blur is applied** in any of the cells we do draw — every column is crisp,
  where Ruffle's blur grows down and to the right.

Excess: `blur_quality` 821 415 (444 547 diff px, mean 128), `blur_fractional`
774 090 (259 287 diff px, mean 218).

**Recommendation:** cheap first step is an A/B on the dynamic-capacity constants
(defect A) — that alone will tell you whether B is a `quality`/fractional-radius
gap or a knock-on. Do **not** brief this as "structural extra ink"; that framing
sends the agent at the symptom. **Predicted: 0 flips this session, 2 large band
moves + one resolved diagnosis.**

---

## P8 — HYGIENE FIX, then triage — `avm2/netstream_play_flv` is hidden by a mis-scoped hard disposition

`image_triage.py` excludes it via a **basename** match to the *avm1*
`ACCEPTED_DIFFS` entry (the board even prints `(matched by basename — VERIFY)`).
The avm1 entry describes "Sorenson Spark pixel parity, **44 outliers, max diff 3**".
The avm2 row is `blank_render`, **229 724 outliers, max diff 255, e_large**.
Different mechanism entirely.

**Action:** add an explicit `<!-- image-axis: avm1/netstream_play_flv output -->`
scope marker to that `ACCEPTED_DIFFS` entry so the resolver stops matching by
basename, and put `avm2/netstream_play_flv` back on the live board as an untriaged
`blank_render`. **This does not change the pass count** — it changes what the board
shows you.

---

## P9 — WATCH (do not scope alone) — `acid-blend-2 [output.26]` is exactly ONE channel over threshold

Passes `tolerance 20 / max_outliers 6000`; fails `tolerance 120 / max_outliers 0`
with **`outliers = 1`**. The single offender is `px(153, 282)` channel 0:
ours `(229,235,242)`, Ruffle `(102,140,178)`. Column 153 is the antialiased edge
between white at x=152 and solid `(51,102,153)` at x=154 — our coverage there is
≈0.13 where Ruffle's is ≈0.75, i.e. a **sub-pixel edge-position difference of the
same ~0.6 px magnitude as P2**. The next-worst channels (117, 112, 107) sit on the
same column and on two other edges.

**Recommendation: re-measure after any P2 leg before spending a session on it.**
§13 called this "blend-layer alpha, one-dump bisect"; the pixel evidence says
edge geometry, not blend math. +1 flip if it rides P2; a standalone bisect is
poor value for one channel.

---

## Leads confirmed but correctly parked (arc-sized, do not brief for wave 2)

| bucket | live cmps | note |
|---|---:|---|
| Stage3D / AGAL | **25** stage3d-named (`avm2/stage3d_*` ×22 + `stage3d/scissor_rectangle`, `scissor_rectangle_invalid`, `sampler_odd_size`) | §13's "(25)" is exact. +5 more in the shader family: `pixelbender_dithering`, `pixelbender_effect_glassDisplace`, `_shaderfilter`, `blend_shader_luma_lighten`, `away3d_advanced_shallow_water_demo` → 30 total |
| H.264 / video codec | **12** (see Hygiene-2) | decoder absent |
| `from_shumway/bitmapbuttons` | 1 | s12 DEFER stands (tol 4 / max_out 0 on resampled JPEG) |
| blend_modes `a_epsilon` rows (add/lighten/screen/difference/subtract/darken/multiply/hardlight/overlay/alpha_no_layer/erase_no_layer/invert) | 12 | CAPPED since s11; still 20–60 excess. Do not scope. |
| fonts near-pass family (`glyph` 6, `duplicate_font` 3, `match_style` 12, `fallback_preferences` 156) | 4 | capped since s12 — **but** `glyph`/`duplicate_font` show the P2 direction signature; re-check after P2 |

---

# PART 2 — THE THREE BOARD-HYGIENE VERDICTS

## Hygiene-1 — `simple_shapes/masks` pair re-baseline: **KEEP EXCLUDED, but the entry's stated mechanism is REFUTED — amend it and re-purpose the pair as the flattening canary**

**Current state (run 31647430265):** both `visual/simple_shapes/masks [output]` and
`visual/simple_shapes/masks_equal_clipdepth [output]` sit at **1738 excess
channels**, `c_small`, `hairline_edge_drift`, resolving HARD through the
`ACCEPTED_DIFFS` entry with its `<!-- image-axis -->` scope marker. History:
1686 (s11) → 2624 (s13, adaptive subdivision) → **1738** (s14). The two rows are
pixel-for-pixel identical (same 652 pixels, same bbox, same magnitude histogram).

**What the pixels actually say** (measured this session):

| measurement | value |
|---|---|
| differing pixels | 652 (1738 channels) |
| magnitude histogram | 649 × 255, 3 × 204 — **no partial-coverage values at all** |
| horizontal run lengths | 531 × 1 px, 56 × 2 px, 3 × 3 px (vertical: 632 × 1 px) |
| colour-pair census | **482 = ours BLACK / expected WHITE**; 44 black/blue; 27 black/red; only **3** where ours is background |
| net colour census | black **+499**, white **−496** |
| mean edge offset (line fit, rows 20–180) | **−0.62 px**, and the two edges have *different slope* (−0.8314 vs −0.8404) |
| content | an **ellipse** mask over curved coloured strokes (rendered image inspected) |
| quality | `low` → `MSAA_SAMPLES = 1`, `tolerance = 0` |

**Why "1-sample rasteriser tie" is the wrong label.** A tie is symmetric: roughly
as many pixels flip in as flip out. Here the asymmetry is **~160 : 1** in one
direction, with a net +499 black. Our ellipse is *uniformly outside* Ruffle's, by a
sub-pixel amount, everywhere. That is a geometry difference, not a coin flip — and
it is the P2 signature at scale. It is corroborated by the entry's own history: the
pair moved 1686 → 2624 when **curve subdivision** changed in s13, which a
rasteriser tie could not do.

**Verdict.**
1. **Keep the comparisons excluded from flip leads** — 652 pixels at
   `max_outliers = 0` is not a session-sized target on its own, and nothing here
   is a "cheap 2 flips".
2. **Rewrite the `ACCEPTED_DIFFS` mechanism text.** Replace "1-sample rasteriser
   tie (1686 outlier channels each)" with: *curve-flattening amplitude mismatch —
   our recompile-time quadratic flattening (6-chord floor, 1-twip tolerance,
   uniform t) is finer than lyon's (Levien stepping at 0.1 px/scale), so the
   flattened ellipse sits ~0.6 px outside Ruffle's; 482/652 differing pixels are
   ours-black over expected-white, net +499 black px; 1738 outlier channels each
   at run 31647430265.* Keep the `<!-- image-axis: ... -->` scope marker.
3. **Re-purpose the pair as the designated instrument for P2.** Zero tolerance,
   1 sample, six flat colours, no AA, no filters, no text — every sub-pixel
   geometry change shows up here first and cleanly. Any wave-2 flattening leg
   should report this number before/after.
4. **Re-evaluate for un-dispositioning after P2 lands.** If a lyon-faithful
   flattener drops it below ~100, it stops being a disposition and becomes a lead.

**Not** "still dispositioned, nothing to see" and **not** "now an implementable
lead". It is a *mislabelled* disposition that is really the top mechanism's best
measuring stick.

---

## Hygiene-2 — the "remaining video (16)" bucket, rebuilt from an SWF-level scan

**Method:** parsed every failing test's `test.swf` tag stream for `DefineVideoStream`
(60) / `VideoFrame` (61) and scanned the decompressed body for `NetStream` /
`flash.media:Video`. 232 unique failing tests scanned; 9 have any video signal.

### CORRECTED BUCKET — true video-backend defects: **12 comparisons / 3 tests**

| test | comparisons | mechanism |
|---|---:|---|
| `visual/video/h264` | `frame2 … frame11` (10) | H.264/AVC payload in FLV via NetStream — no decoder. 9 rows `unrelated_content` + `frame5` `missing_element`, all f_catastrophic |
| `visual/video/h264_multinalu` | `output` (1) | same, `blank_render`, 172 800 |
| `avm2/netstream_seek_flv` | `output` (1) | FLV **seek**, `blank_render`, 40 672; `[trace-ign]` soft flag only |

So §13's "12" is right only if you count the FLV-seek row; **pure h264 is 11**.

### CORRECTLY DISPOSITIONED VIDEO — 4 comparisons

`avm1/netstream_play_flv` (44, max diff 3) · `avm1/netstream_play_flv_screen`
(RUFFLE_VS_FLASH) · `visual/video/colorconversion/h263` (10 808, max 2, Spark IDCT)
· `visual/video/deblocking` (104, max 4, s14 entry).

### MIS-DISPOSITIONED — 1 comparison, must come back on the board

`avm2/netstream_play_flv [output]` — 229 724 excess, `blank_render`, excluded only
by a **basename** match to the avm1 entry. See P8.

### NOT VIDEO AT ALL — 3 comparisons, move out of the bucket

| comparison | where it really belongs | evidence |
|---|---|---|
| `from_shumway/acid/acid-video [output.10]` | **frame-loop keep-alive (P4)** | the SWF has **no `DefineVideoStream`** — it is 41 ShowFrames / 198 PlaceObject2 of pure vector timeline; root is 1 frame placing a 1-frame sprite that contains the 39-frame sprite |
| `from_shumway/acid/acid-video [output.20]` | same | same |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest [output]` | **text/glyph + shape edge drift** | embedded Spark video *decodes correctly*; the 102 differing pixels (189 channels) are at rows 0–25, cols 22–249 — the "- xtrace enabled -" EditText glyphs and the red/yellow square corner. The video quad itself is byte-exact. `hairline_edge_drift`, c_small |

**Bucket arithmetic:** §13's 16 → **12 true video** + 1 recovered from a bad
disposition + 3 reassigned. §13's own hypothesis (both named cases) is
**CONFIRMED by SWF-level evidence**.

---

## Hygiene-3 — `acid-bitmap-draw_quality` size-gate priced

Fully answered in **P3**. Short form: **NO-GO on the briefed 256→512 cap raise**
(4× VRAM corpus-wide, buys a band move not a flip, and the same over-allocation
already OOMs `acid-large` at 2.52 GB); **GO on a budgeted / decoupled dynamic
layer allocation**, which unblocks `acid-large` *and* lets this movie have its
512 cap for 67 MB on that movie alone.

---

## Bonus hygiene — the `no_render` bucket is THREE mechanisms, not one

The board groups 5 comparisons under `no_render`. They share nothing:

| comparison | mechanism | lead |
|---|---|---|
| `from_shumway/acid/acid [output.17]`, `[output.18]` | harness capture-table cap of 16 | **P1 (proven +2)** |
| `from_shumway/acid/acid-large [output]` | `VK_ERROR_OUT_OF_DEVICE_MEMORY`, 2.52 GB bitmap texture array | **P3** |
| `from_shumway/acid/acid-video [output.10]`, `[output.20]` | frame loop exits after 1 tick | **P4** |

Anyone briefed on "the no_render bucket" as one item will mis-scope it.

---

# PART 3 — VERIFICATION OF EVERY §13 LEAD (stale-brief trap) + REFUTATIONS

`graphics-fanout-playbook.md` §13 "Top remaining leads" and its bullet claims,
checked against run `31647430265`:

| §13 claim | status | evidence |
|---|---|---|
| "simple_shapes/masks pair re-baseline (now 1738, entry amended)" | **NUMBER CONFIRMED, MECHANISM REFUTED** | 1738 each, still hard-dispositioned. But 482/652 pixels one-directional, net +499 black, ≈0.62 px offset ⇒ curve flattening, not a rasteriser tie (Hygiene-1) |
| "displacement-map trio (content_displaced, one mechanism, **3 rows**)" | **PARTIALLY REFUTED — it is a QUARTET** | `displacement_map` itself (123 279) is in `same_geometry_wrong_fill`, not `content_displaced`, and was left out of the trio. 4 rows, 1 mechanism (filter is a no-op). Two of them are byte-identical (P6) |
| "blur_fractional/blur_quality **structural extra ink** (774k/821k)" | **LABEL REFUTED** | numbers confirmed; the extra ink is a *consequence* of ~30 % of the stage never being drawn (identical staircase in both), plus blur being absent entirely. Two defects, and the named one is the symptom (P7) |
| "blend-layer alpha (output.26, one-dump bisect)" | **NUMBER CONFIRMED, MECHANISM DOUBTED** | exactly 1 outlier at `tolerance 120`; the single offending channel is an antialiased *edge* column at px(153,282) with coverage 0.13 vs 0.75 — edge geometry, likely a P2 rider, not blend math (P9) |
| "Stage3D (**25**)" | **CONFIRMED EXACT** | 25 `stage3d`-named live comparisons; +5 in the wider shader family |
| "h264 (**12**)" | **CONFIRMED ONLY IF `netstream_seek_flv` IS COUNTED** | 10 `h264` frames + 1 `h264_multinalu` = 11 pure h264; the 12th is the FLV seek (Hygiene-2) |
| "define_bits_lossless2_rgb15 **arrived passing** (new upstream)" | **REFUTED** | in the very run §13 describes it is **FAILING**: `5282 outliers exceed limit of 0, max difference 255`, 50×50, mean diff 119. Root cause identified (P5). It is also **absent from the local corpus**, which is why the board can only class it `png_unavailable` |
| "remaining video (16) is mis-scoped, rebuild from SWF-level scan" | **CONFIRMED, and now rebuilt** | Hygiene-2; both named cases verified at tag level |
| s14: "AVM1 scrollRect end-to-end; scroll_rect_scaled flipped" | CONFIRMED | `visual/simple_shapes/scroll_rect_mask` still fails at 42 (P2 candidate); `visual/cache_as_bitmap/scroll_rect` 2056; `avm2/displayobject_scrollrect` 10 |
| s14: "cache_as_bitmap/masks .01–.06 flipped" | CONFIRMED | none of `cache_as_bitmap/masks*` appears on the failing board; residual `cab_mask_*` rows are `extra_element` (filters/alpha/transform: 4968 / 4644 / 2340) |
| s13: "avm2_button_scroll_rect → a_epsilon 9 excess, one lavapipe corner pixel from flipping" | CONFIRMED UNCHANGED | still exactly 9; s14's stencil work did not move it. Its 3 diff pixels are all ours-bigger on a curve ⇒ P2, **not** a stencil item |
| s14: "bitmap fills tile on content size; acid-bitmap-fill flipped" | CONFIRMED | `acid-bitmap-fill` no longer on the failing board |
| s14: "deblocking now b_tiny 104, dispositioned" | CONFIRMED | 104 excess, max diff 4, resolves HARD |

### Disposition audit (playbook §3)

- **Hard exclusions: 8.** Seven resolve `exact`; one (`avm2/netstream_play_flv`)
  resolves by **basename** and is wrong — see P8.
- **Soft `[trace-ign]` flags kept on the board: 8**, all `avm2` suite-local
  ignore entries: `bitmapdata_draw_alpha_erase` (15 000),
  `displayobject_hittestpoint_boundary` (76), `displayobject_scrollrect` (10),
  `edittext_tag_indent` (7884), `geom_transform` (49 421), `graphics_draw_path` (764),
  `netstream_seek_flv` (40 672), `stage_scale_factor` (1 912 924). Correct — a
  trace-axis ignore says nothing about pixels.
- **STALE entries (dispositioned but now PASSING) — two doc edits owed:**
  - `avm1/display_object_properties` — ACCEPTED_DIFFS "MSAA edge/stroke
    antialiasing (~192 image px)" — **now passes**.
  - `from_gnash/misc-ming.all/loop/simple_loop_test` — ACCEPTED_DIFFS entry scoped
    to "FRAMES 1–2 ONLY" — **all 7 frames now pass**.
- **Frame-phase suspects: 0.** The channel §12 declared exhausted is still
  exhausted; no test's frames disagree about their mechanism this run.
- **Ruffle `known_failure`: 23** — Ruffle is not the oracle; matching those PNGs is
  not a goal. Notably `from_shumway/acid/acid-bitmap-draw_quality_low`, which caps
  P3's upside at +1.

### Board freshness note for the coordinator

The **local corpus is stale relative to CI**: exactly one failing test
(`visual/define_bits_lossless2_rgb15`) has no local directory, and `~/CC/ruffle`
does not have it either. Anything that reasons about "new upstream tests" from the
local tree will miss it. Re-sync before wave 2.

---

# APPENDIX — cluster totals at session-15 start (for the §14 playbook section)

```
cluster                     cmps tests near   live  note
hairline_edge_drift           67    57   47     58  ≥2 mechanisms; P2 owns the one-directional slice
blank_render                  45    45    0     41  25 Stage3D + P3 + h264_multinalu + jpegxr + fonts
same_geometry_wrong_fill      33    33    4     33  displacement_map, blend layer_*, acid-blend/-filter-2
diffuse_mixed                 31    31   11     25  filters bevel/glow/drop_shadow + capped blend rows
unrelated_content             14     6    0     14  h264 ×9, away3d, timeline_loop[.12]
missing_element               13    13    1      9  blur_pass_scaling, acid-filter, fonts
halo_penumbra                 13    13    0     13  EditText background/border, glassDisplace
content_displaced             13    12    0     11  displacement ×3, stage_scale_factor, edittext_scroll
extra_element                  7     7    0      6  blur_quality/blur_fractional (P7), cab_mask_*
row_banded                     5     5    1      3
no_render                      5     3    0      5  THREE mechanisms (P1/P3/P4)
whole_frame_wrong              3     3    0      2
offset_translation             3     3    0      3
localized_region               2     2    0      1
global_color_shift             1     1    0      0
png_unavailable                1     1    0      1  local corpus stale (P5)
TOTAL                        256                219 live
```

Cluster × band and the ranked top-40 are in `wave1-gfx-board.rawboard.md`.

---

## Scratch artifacts (this session, not committed)

`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/4887379b-7447-4810-a394-1c76f24b1248/scratchpad/`
— `board.json`, `board.md`, `image-results/` (extracted branch), `swfscan.py`
(SWF tag + ABC constant-pool scanner used for the video and BitmapData scans),
`corpus/from_shumway/acid/*` (scratch copies used for the P1/P4 measurements —
the main-tree acid test dirs were **not** touched), `bd-acidlarge/` (kept build
dir for the P3 OOM capture).
