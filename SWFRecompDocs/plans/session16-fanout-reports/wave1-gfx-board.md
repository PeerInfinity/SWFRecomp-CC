# Session 16 — wave 1 — PIXEL-AXIS BOARD (w1-gfx-board)

**Agent:** w1-gfx-board · read-only diagnosis · no source edits in the main tree, no commits.
**Method:** `graphics-fanout-playbook.md` §2 (board), §3 (dispositions), §4 (accounting),
§7 (provenance). Deliverable shape mirrors `session15-fanout-reports/wave1-gfx-board.md`.

## PROVENANCE (read this before using any number below)

| | |
|---|---|
| Grading run | `31748059158` at `3db858cbc157a97402c8e9a956b123871fc73405` (graphics / categories=full / images=true) |
| Per-suite stems | all **12** `_results/image_results_graphics.json` carry `run_id=31748059158`, `git_sha=3db858cbc`, `incomplete=false` — **consistent, no mixed-run stems** |
| `ruffle-image-results` | `30b85f3e7` "Ruffle image comparison failures", 2026-08-13T22:38:41Z, `index.json` generated 22:38:40.86, **241** `*.actual.png` — same run (stems generated 22:38:39.8–22:38:40.2) |
| Board command | `python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 3` (16.2 s) |
| Raw board | copied next to this file as `wave1-gfx-board.rawboard.md` (cluster table, cluster×band, top-25, group table, full disposition audit) |
| Accounting | `python3 scripts/image_status_diff.py aa3402094 380c68c84` (s15 run `31647430265` → s16 run `31748059158`) |

**Baseline CONFIRMED: 324 / 569 unique comparisons = 56.94 %.**

Arithmetic: `index.json` totals = **570** comparisons / 324 pass / 243 fail / 3 skip
(1 of the 243 fails is `no_render`; `no_render` is a *subset* of fail, so 324+243+3 = 570).
Minus the one `from_shumway/avm1/*` **nested double-count** → denominator **569**
(playbook standing fact #2; restated 566→567→569 by upstream drift, unchanged this run).
`image_status_diff.py` independently reports an intersection of **569**.

Per-suite pass/comparisons: avm1 62/69 · avm2 **56/123** · fonts 1/4 · gnash-ming 7/18 ·
gnash-swfmill 2/2 · from_shumway 85/123 · from_shumway/avm1 0/1 · import_assets 0/1 ·
regression 4/7 (3 skip) · stage3d 0/3 · text 1/5 · visual 106/214.

Board decomposition of the 242 deduped failing comparisons:
**212 live** (194 test×cluster rows / 211 cmps by the board's own count) ·
30 excluded = **7 hard-dispositioned** + **23** Ruffle `known_failure`.
(`png_unavailable` is gone — the local corpus is now in sync with CI.)

### s15 → s16 delta (verified, not quoted)

`+14 / −0`, exactly the s15 ledger. GAINS: `avm2/bitmapdata_filter_sourcerect`,
`avm2/displayobject_mask`, `avm2/loader_events`, `avm2/loader_loadbytes_events`,
`acid [output.17]`, `acid [output.18]`, `acid-blend`, `acid-blend-2 [output.26]`,
`acid-video [output.10]`, `acid-video [output.20]`, `cache_as_bitmap/avm2_button_state`,
`define_bits_lossless2_rgb15`, `filters/blur_fractional`,
`filters/displacement_map_through_applyFilter`. **REGRESSIONS: 0. NEW: 0. GONE: 0.**
Bands improved 13 / worsened 0.

---

# PART 1 — RANKED, PRICED PIXEL LEADS FOR WAVE 2

Ranked by **mechanism × evidence strength × cost**, not by near-pass distance
(playbook standing fact #3). "PROVEN" = I reproduced the failure locally this session
and/or modelled the fix well enough to reproduce CI's exact outlier count.

Owner-file conflicts with the siblings I was told about are called out per lead.
Siblings this session: `w1-gfx-filters` (AVM2 filters Route 2), `w1-gfx-shapes-morph`
(simple_shapes/masks + morph end-colour + cab/morph), `w1-gfx-vram` (acid-large VRAM),
and a solo worktree agent on **flattening leg C** (`SWFRecomp/src/swf.cpp:8653`).

---

## P1 — **GO, PROVEN, +3 flips (likely +4), zero measured regression risk** — the gradient ramp builder walks stop ratios wrongly, and on non-monotonic ratios it *overruns its own 256-row texture slot*

**This is the top unowned lead on the board.** It is a faithful-port job with a
whole-corpus blast-radius audit that came back at exactly the four tests it fixes.

### Owner files (three near-identical copies of the same wrong loop)

| file | function | path |
|---|---|---|
| `SWFRecomp/src/swf.cpp` | `parseFillStyles` ramp emitter, **lines 7110–7208** | static `DefineShape*` gradients |
| `SWFRecomp/src/swf.cpp` | `parseMorphFillStyles` ramp emitter, **~7515** | morph gradients (same shape of bug) |
| `SWFModernRuntime/src/actionmodern/action.c` | `drawingGenerateGradientRamp`, **28047–28110** | AVM1 `beginGradientFill` / `lineGradientStyle` |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `gfx_gen_ramp`, **7854–7889** | AVM2 `Graphics.beginGradientFill` |

### The oracle

`~/CC/ruffle/render/wgpu/src/mesh.rs:290-345` (`CommonGradient::new`) bakes a
256-entry ramp with a **single-step cursor**:

```rust
for t in 0..256 {
    if last + 1 < records.len() && t > records[last + 1].ratio as usize { last += 1; }
    let next = (last + 1).min(records.len() - 1);
    let a = if t <= records[last].ratio || records[last].ratio == records[next].ratio { 0.0 }
            else if t > records[next].ratio { 1.0 }
            else { (t - last.ratio) / (next.ratio - last.ratio) };
    colors[t] = lerp(convert(last.color), convert(next.color), a) as u8;   // truncating cast
}
```

Two consequences that we get wrong:

1. **Duplicate ratios each consume exactly ONE texel.** `last` advances at most once
   per `t`, and when `last.ratio == next.ratio` the alpha is pinned to 0 — so a run of
   *k* stops at the same ratio renders as *k* consecutive 1-pixel bands, and the
   following segment starts *k−1* texels later.
2. **Ratios are never sorted.** A decreasing ratio makes the cursor jump and pins
   `a = 1.0`, producing a plateau of the *next* record's colour.

### What ours does (all three copies)

The recompiler *appends* rows per segment (`for (u8 ratio = last.ratio; ratio < grad.ratio; ++ratio)`),
so a duplicate emits **zero** rows and a decreasing ratio emits **zero** rows.
The two runtime copies index-address (`out[i*4]` for `i` in `[r_s, r_e]`) with
`if (range <= 0) range = 1`, so a duplicate emits one texel of the *wrong* colour
and a decreasing ratio emits nothing.

**The recompiler copy additionally breaks the 256-row invariant.** For
`gradient_nonsequential_ratios` (ratios 31, 80, 50, 100, 200, 150) it emits
`31 + 49 + 0 + 50 + 100 + 0 + 106 = ` **336 rows** into `u8 gradient_data[256*N][4]`.
Every subsequent gradient in the same SWF would land on the wrong texture row
(here N = 1, so the excess initialisers are simply dropped by the compiler and the
ramp is truncated). Whatever the wave-2 fix is, it must restore the "exactly 256 rows
per gradient" invariant that the surrounding comments already claim.

### Evidence — the model reproduces CI's numbers exactly

I ported both algorithms to Python (`<scratch>/rampsim.py`), read the real stop lists
straight out of the SWF `FILLSTYLEARRAY`s, and validated against the published PNGs.

Column `x = 128` of `visual/gradient_same_ratios` (`output.expected.png`), rows 100–105:
`(0,203,203) (0,0,0) (254,254,0) (0,0,0) (49,254,0) (254,0,0)` — i.e. exactly the
simulated Ruffle ramp at `t = 156,155,154,153,152,151`, the six 1-pixel duplicate-stop
bands. Ours has **one** transition there. Same story at rows 247–249 (`t = 8,7,6`).

Predicted post-fix outliers (per-pixel remap of our actual PNG through
ours-ramp → Ruffle-ramp, then re-graded at the test's own tolerance):

| comparison | tol | budget | current outliers | model reproduces? | predicted after fix | verdict |
|---|---:|---:|---:|:--:|---:|---|
| `visual/gradient_nonsequential_ratios [output]` | 36 | 1300 | 61 440 | **yes, exactly** | **1 280** | **FLIP** |
| `visual/gradient_same_ratios [output]` | 37 | 5130 | 6 912 | **yes, exactly** | **5 120** | **FLIP** |
| `visual/gradient_radial_same_ratios [output]` | 35 | 3860 | 6 675 | (plateau-ambiguous) | ~430 | **FLIP** |
| `visual/gradient_issue_9892 [output]` | 24 | 2329 | 3 755 | not modelled | — | likely rider |

For the radial row the naive remap is ambiguous (our ramp has a 156-texel yellow
plateau), so I measured it spatially instead: our ramp and Ruffle's differ only at
`t = 100…104`, and **3 254 of the 3 396 currently-outlying pixels (95.8 %) have an
expected colour within tolerance of one of those five ring colours**. The residual
~142 px ≈ ≤430 channels sits far under the 3 860 budget.

`gradient_issue_9892` carries four duplicate-ratio gradients (`70,70,140,140` and
`0,0,255,255`, in both `rgb` and `linearRGB` interpolation) — the same defect, but its
per-gradient delta is only 1–2 rows plus a one-row phase shift, so I price it as a
**likely rider, unproven**.

### Blast-radius audit (this is why the risk is low)

Scanned **2 848** `test.swf` files across all ten graded suites for `DefineShape*`
gradients with duplicate or non-monotonic ratios (`<scratch>/gradcorpus.py`; 62
unreadable/LZMA files skipped). **Exactly 4 tests hit — all four are already failing:**
`gradient_issue_9892`, `gradient_nonsequential_ratios`, `gradient_radial_same_ratios`,
`gradient_same_ratios`. **No currently-passing test in the corpus contains a duplicate
or non-monotonic static gradient ratio.**

And for strictly-increasing ratios our static ramp is already **byte-identical** to
Ruffle's: 2 000 randomised monotone stop lists at `interpolation = rgb` gave a worst
channel delta of **0**.

### Refutation / caveat the wave-2 agent must respect (do NOT bundle)

At `interpolation = linearRGB` (mode 1) our static ramp differs from Ruffle's on
**every** row by up to **13 channels**, because Ruffle quantises to `u8` *in linear
space* and converts to sRGB per-pixel in `gradient.wgsl` (`common__linear_to_srgb`),
whereas `SWFRecomp/src/swf.cpp::linearRgbLerp` (6928) converts back to sRGB before
quantising. The two runtime copies already store linear (`"matching Ruffle"`), so the
static path is the odd one out. **13 < every tolerance in the affected tests (24–37),
so this is not what is failing** — but it is a real oracle divergence and belongs in a
separate leg with its own A/B, because it touches the shader's `v_args.w` bit-4 flag
plumbing and every static linearRGB gradient in the corpus.

**Cost:** one shared 25-line helper + three call sites. Recompiler change ⇒ worktree
cmake build **and** `--recompile` (playbook §6 false-negative #1). **Independent slot:
YES**, but it edits `SWFRecomp/src/swf.cpp` around lines 7110/7515, ~1500 lines away
from flattening leg C's `8653` — tell both agents so the coordinator's serial apply
does not surprise anyone.

---

## P2 — **GO (+2 flips, one unimplemented property)** — `DisplayObject.opaqueBackground` is not implemented on either VM

| comparison | cluster | excess | tol / max_out |
|---|---|---:|---|
| `visual/opaque_background [output]` | content_displaced | 231 232 | 1 / 0 |
| `avm2/displayobject_opaque_background [output]` | same_geometry_wrong_fill | 17 004 | 1 / 0 |

Side-by-side (reproduced locally, `--mode=graphics --images`, both hit CI's exact
numbers 231 232 / 17 004): Ruffle paints a solid rectangle over the object's bounds
before drawing it — two **green** blocks in `visual/opaque_background`, a **blue**
square behind the red circle in the AVM2 one. We paint nothing; in the AVM1 test all
that survives is the shape's thin red rules.

Board features corroborate one mechanism, two VMs: the AVM2 row is
`ink IoU 1.00, ncolors 2/2, 21.3 % of pixels repainted` (geometry right, background
missing); the AVM1 row is `99 % of expected ink missing`.

**Pricing: +2 flips.** Both are `tolerance 1 / max_outliers 0`, but the content is
flat-colour axis-aligned rectangles, so exactness is achievable — this is the same
class the s9 focus-rect rider cleared. **Risk: low-medium** — the fill must be
clipped/ordered exactly like Ruffle (`core/src/display_object.rs`, background painted
in the object's own space, under its children, and interacting with `scrollRect`).
**Cost:** small runtime feature; touches `tag.c`/`action.c` (AVM1) and
`avm2_display.c`'s render walk (AVM2). **Independent slot: YES.**

---

## P3 — **GO (+1 flip, ~10 lines, exact oracle in hand)** — AVM2 `beginGradientFill` ignores `null` `alphas` / `ratios`

`avm2/graphics_gradients_nulls [output]` — `blank_render`, **117 600** excess,
`tolerance 5 / max_outliers 0`, `ncolors actual/expected = 1/114`. Reproduced locally
(exact CI number). `Test.as` calls:

```as3
graphics.beginGradientFill("linear", [0,0xFFFFFF,0,0xFFFFFF,0], null, null, matrix);
```

Ruffle (`core/src/avm2/globals/flash/display/graphics.rs::build_gradient_records`):
`length = colors.length()` reduced only by the arrays that are **present**; a missing
`alphas` gives `alpha = 1.0`, and a missing `ratios` gives evenly-spaced stops —
`ratio = (i * 255) / (length - 1)`, i.e. `0, 63, 127, 191, 255` here. We produce no
gradient at all and the stage stays flat.

**Cost:** ~10 lines in `avm2_display.c` (`gfx_begin_gradient_fill`, ~8038–8078).
**Pricing: +1 flip, moderate confidence** — the toml comments the golden as
"expected png generated from FP" (Flash Player, not Ruffle), and `max_outliers = 0`
at `tolerance 5` against a Flash reference is the one uncertainty. Colour band content
is flat, so it should clear. **Independent slot: YES** (same file as P5 but a
different function; self-localise).

---

## P4 — **GO (+1 flip, structural)** — `LINESTYLE2` with `HasFillFlag` throws the fill away and keeps `{0,0,0,0}`

`from_shumway/acid/acid-gradient-2 [output]` — `blank_render`, **12 555** excess,
`tolerance 1 / max_outliers 0`. Ruffle renders a gradient-filled **ring**; we render
an empty stage. Reproduced locally (exact CI number).

Root cause, proven from the generated C: `SWFRecomp/src/swf.cpp:7332-7344`
(`parseLineStyles`) handles a fill-typed stroke by calling `parseFillStyles(1)` and
then keeping only `fill[0].r/g/b/a`. For a gradient fill style those RGBA fields are
never populated, so the stroke colour becomes fully transparent black. The recompiled
test proves it:

```
RecompiledTags/draws.h : extern u8 gradient_data[256][4];      // the gradient IS registered
RecompiledTags/draws.c : float color_data[1][4] = { { 0/255.0f, 0/255.0f, 0/255.0f, 0/255.0f } };
```

The renderer already has line-gradient plumbing (`action.c:28719`
`path->line_interpolation = ds->line_gradient_interp`, used by AVM1
`lineGradientStyle`), so this is a wiring job in the recompiler, not new GPU work.
The AVM2 analogue is also a stub: `avm2_display.c:8355 gfx_line_fill_style` clears the
style and returns.

**Pricing: +1 flip (`acid-gradient-2`)**, plus an unmeasured chance at
`from_shumway/acid/acid-stroke-0` (Ruffle `known_failure`, so not a flip target) and
`visual/simple_shapes/strokes/*`. **Cost:** medium; recompiler + a static line-gradient
style path. **Independent slot: YES**, but shares `SWFRecomp/src/swf.cpp` with P1 —
if the coordinator wants a single recompiler slot, **P1 + P4 combine cleanly** (both
are `parseFillStyles`-adjacent) and that is my recommended pairing.

---

## P5 — **DIAGNOSE-then-GO (2 comparisons, 321 KB of blank)** — AVM2 `Graphics.beginBitmapFill` is an explicit no-op

`avm2_display.c:8346` `gfx_begin_bitmap_fill` finalises the subpath, sets
`g->cur_fill = 0`, and returns — with a comment saying the command stream "has no
representation" for a bitmap fill. `beginShaderFill` is bound to the same stub
(`:13998`).

| comparison | excess | checks |
|---|---:|---|
| `avm2/graphics_bitmap_fill [output]` | 136 030 | tol 5 / 60 |
| `avm2/graphics_bitmaps [output]` | 185 430 | tol 8/4000, 16/800, 32/600 |

Both are `blank_render` with `ink_iou = 0.0` and `missing_ink = 1.0` (reproduced
locally: 136 090 and 185 430 outliers). Ruffle draws a tiled/stretched PNG-fill logo.
The AVM1 side already has a working bitmap-fill path (s14: "bitmap fills tile on
content size", `acid-bitmap-fill` flipped), so the work is extending the AVM2 command
stream with a bitmap-fill style rather than inventing a renderer feature.

**Pricing: 0–2 flips** (`graphics_bitmaps` has a generous 3-rung ladder;
`graphics_bitmap_fill` is `tol 5 / max_out 60` on a resampled bitmap, which is the
class s12 deferred for `bitmapbuttons` — price it as a large band move).
**Cost:** medium-large. **Independent slot: yes, but lower value than P1–P4.**

---

## P6 — **DIAGNOSE FIRST (largest unowned family: 31 live comparisons)** — the EditText `background` / `border` slice is a *missing element*, not a halo

`halo_penumbra` is the highest-scoring cluster on the board (rows #1, #3, #4, #5, #6)
and it is entirely EditText. Side-by-sides say the classifier's name is misleading:

- `visual/edittext/edittext_background_basic` (1 902) and `..._scale2` (7 741):
  Ruffle draws a **wide black background bar** and **two magenta squares** that we
  never draw at all; the fields we do draw match. `ink actual/expected = 0.0696/0.1597`,
  `missing_ink = 0.564`.
- `visual/edittext/edittext_border_basic` (1 227, `missing_element`) and
  `..._scale2` (6 072): same shape of defect, `missing_ink = 0.564 / 0.689`.
- `visual/edittext/edittext_device_transform_basic` (2 386) / `_negative` (2 619):
  the glyph block is drawn but positioned differently under the transform — this half
  is the **device-font** mechanism that s15 already named as the `applyfilter_blur`
  residual, and it is shared with `visual/fonts/leading_device_font` (12 978) and
  `fonts/device_font_kerning` (1 680).

So the family is at least **two** mechanisms: (A) certain EditText background/border
configurations are never emitted, (B) device-font glyph placement under a matrix.
**Do not brief this as one item.** Recommended wave-2 shape: one agent on (A) only,
scoped to the four `edittext_{background,border}_basic{,_scale2}` rows, with the
6 `device_transform` rows explicitly out of scope.
**Pricing: unpriced — 0 flips this session, 4 band moves + one resolved diagnosis.**

---

## P7 — **WATCH / NO-GO as a flip target** — `cache_as_bitmap/oversize/swf_{9,10}_masks`

Two comparisons, byte-identical numbers (**119 943** each, `tolerance 64 / max_out 200`
then `128 / 0`). Their siblings `swf_{9,10}_too_big` **pass**. `Test.as` differs by one
number: `test.width = 2879` (masked case, fails) vs `2880` (over the SWF9 limit, mask
dropped, passes). We render the unmasked red background in *both*, so we pass the
"limit exceeded" case for the wrong reason and fail the "limit respected" case.

Mechanism is therefore AVM2 `DisplayObject.mask` on a **scaled** masker, i.e. mask
work — and this session has no mask owner. **NO-GO for wave 2 unless a mask agent is
spawned**; it is 2 comparisons at `max_outliers = 0`, which is not worth a standalone
slot. Completion mechanism: an agent that already holds the AVM2 mask walk.

---

## Leads confirmed but correctly parked (arc-sized, do not brief for wave 2)

| bucket | live cmps | note |
|---|---:|---|
| Stage3D / AGAL / shaders | **29** family-wide (25 of them `blank_render × Stage3D`) | §14's "(25)" is exact for the `blank_render` slice; the family also carries `pixelbender_effect_glassDisplace` (783 192), `_shaderfilter` (879 084), `blend_shader_luma_lighten`, `stage3d_texture`, `pixelbender_dithering` |
| H.264 / video codec | **11 pure h264** (`h264 [frame2..11]` ×10 + `h264_multinalu`) **+ 1** `avm2/netstream_seek_flv` (FLV seek) = 12 | s15 Hygiene-2 **re-confirmed unchanged** |
| `avm2/netstream_play_flv` | 1 | s15's P8 hygiene **LANDED** — the ACCEPTED_DIFFS entry now carries `<!-- image-axis: avm1/netstream_play_flv output -->` and an explicit "NOT dispositioned" section for the avm2 row. It is live on the board at 229 724, `blank_render`, untriaged |
| `visual/definefont4` | 1 | 16 086 blank — DefineFont4 (embedded CFF/TLF) glyphs, real feature arc |
| `from_shumway/acid/acid-shapes` | 1 | 78 982, stage renders black where Ruffle draws thousands of tiny shapes — stress test, needs its own diagnosis |
| `avm2/loader_jpegxr`, `_alpha` | 2 | 136 033 + 10 074 — no JPEG XR decoder |
| `from_shumway/bitmapbuttons` | 1 | s12 DEFER stands |
| blend_modes `a_epsilon` rows | 9 (`add/lighten/screen/difference/alpha_no_layer/erase_no_layer/hardlight/overlay` + `subtract/darken/multiply/invert` in `hairline`) | CAPPED since s11; 18–60 excess. Do not scope |
| fonts near-pass family (`glyph` 6, `duplicate_font` 3, `match_style` 12, `fallback_preferences` 156) | 4 | capped since s12; still shows the flattening direction signature — re-check after leg C |

---

# PART 2 — VERIFICATION OF EVERY §14 LEAD (stale-brief trap) + REFUTATIONS

`graphics-fanout-playbook.md` §14 "Top remaining leads" and its bullets, checked against
run `31748059158`. Owned items are re-verified and handed off, not re-diagnosed.

| §14 claim | status | evidence / handoff |
|---|---|---|
| "AVM2 filters Route 2 offscreen/composite arc (**owns much of the 15-row filters family**)" | **NUMBER REFUTED — the family is 27 live comparisons, not 15** | Full itemised list below. → **w1-gfx-filters** |
| "flattening leg C solo run (masks 1738→1497 + 6 band moves)" | **BASELINE CONFIRMED** | `simple_shapes/masks` and `masks_equal_clipdepth` both still **1738**, `max diff 255`, `tolerance 0`, still hard-dispositioned. Excluded from my pricing per brief |
| "simple_shapes/masks = scale/transform defect (slope, not flattening)" | **CONFIRMED as still-open**; entry text still says "1-sample rasteriser tie" | The ACCEPTED_DIFFS heading (`avm1/_investigation/ACCEPTED_DIFFS.md:879`) was **never** rewritten per s15 Hygiene-1. → **w1-gfx-shapes-morph** owns both the diagnosis and the doc edit |
| "acid-large VRAM budgeting" | **CONFIRMED, and it is now the ONLY `no_render` on the board** | s15's P1 (capture cap) and P4 (`hasPlayingSprites` recursion) both landed; the bucket went **5 → 1**. → **w1-gfx-vram** |
| "blur_quality residual per-pass rounding (goldens disagree by 1 LSB — band ceiling)" | **CONFIRMED and sharpened** | `tolerance 6`, **max diff 9**, 166 986 of 1 092 120 channels over. Every offending channel is 7–9. The whole test hangs on moving ~167 k channels down by ≤3 LSB — a rounding port, and the band ceiling claim is exactly right. Cluster moved `extra_element → global_color_shift` (band `e_large → d_moderate`, −80 %) |
| "applyfilter_blur device-font residual" | **CONFIRMED** | `avm2/bitmapdata_applyfilter_blur` 520 441 → **30 844** (−94 %), now `same_geometry_wrong_fill`. Residual co-classifies with the P6(B) device-font slice |
| "Stage3D (25) + h264 (12 → really 11 + FLV seek) parked" | **CONFIRMED EXACT** | 25 `blank_render × Stage3D`; 10 `h264` frames + `h264_multinalu` = 11, twelfth is `netstream_seek_flv` |
| "displacement Route 2 merged into the filters arc" | **PARTIALLY OBSOLETE** | `displacement_map_through_applyFilter` **flipped** in s15. Three rows remain: `displacement_map` (123 279), `_scales_with_screen` (99 353), `_through_filters` (27 565). → **w1-gfx-filters** |
| s15: "morph OOB closed; morph_test1 −76 % ×5" | **CONFIRMED** | all six `morph_test1` frames now 189 (were 589–789), `b_tiny`. Per-character end-colour offset still open. → **w1-gfx-shapes-morph** |
| s15: "no_render bucket 5→1" | **CONFIRMED** | only `acid-large` |
| s15: "render_canary gained acid-blend-2" | **CONFIRMED and now fully green** | `acid-blend` and `acid-blend-2 [output.26]` both flipped; **no `acid-blend*` row survives on the failing board** |
| s15 P8: "avm2/netstream_play_flv hidden by a basename disposition" | **FIXED** | hard dispositions 8 → 7; the row is live and untriaged |
| s15 P5: "define_bits_lossless2_rgb15 absent from the local corpus" | **FIXED** | test flipped to pass; `png_unavailable` cluster gone; the corpus is in sync with CI (0 unresolvable comparisons this run) |

### The filters family, itemised for `w1-gfx-filters` (27 live comparisons)

166 986 `blur_quality` · 152 866 `acid-filter` · 123 279 `displacement_map` ·
105 534 `blur_pass_scaling` · 99 353 `displacement_map_scales_with_screen` ·
87 808 `blur_size_grows` · 80 996 `bevel_outer` · 71 451 `bevel` ·
69 254 `blur_scales_with_screen` · 69 161 `bevel_full` · 57 994 `drop_shadow_angles` ·
48 427 `bevel_inner` · 46 468 `drop_shadow` · 43 329 `glow_with_alpha_strength` ·
30 844 `bitmapdata_applyfilter_blur` · 27 565 `displacement_map_through_filters` ·
25 505 `glow` · 25 445 `glow_without_composite_source` · 17 680 `glow_pass_scaling` ·
16 759 `acid-filter-2` · 10 784 `cache_as_bitmap/contains_grown_filter` ·
7 419 `bitmapdata_applyfilter_colormatrix` · 4 968 `cab_mask_filters` ·
4 884 `any_blur_scales_with_screen` · 810 `edittext_border_filters` ·
400 `drop_shadow_scales_with_screen` · 237 `color_matrix`.
(The five `bevel*` rows remain struck from flip leads per §12/§13.)

---

# PART 3 — CLUSTERS, DISPOSITIONS, FRAME PHASE

## Cluster totals at session-16 start (for the §15 playbook section)

```
cluster                     cmps tests near   live  note
hairline_edge_drift           65    55   45     58  ≥2 mechanisms (s13); flattening leg C owns the one-directional slice
blank_render                  45    45    0     41  25 Stage3D + jpegxr ×2 + graphics_bitmap* ×2 + oversize masks ×2 + acid-gradient-2 (P4) + acid-shapes + definefont4 + device-font + netstream ×2 + h264_multinalu + acid-bitmap-draw_quality_high + graphics_gradients_nulls (P3)
same_geometry_wrong_fill      31    31    3     31  displacement_map, blend layer_*, acid-filter-2, opaque_background (P2)
diffuse_mixed                 29    29   10     25  filters bevel/glow/drop_shadow + capped blend rows
unrelated_content             14     6    0     14  h264 ×9, away3d, timeline_loop[.12], cab_mask_triangle
halo_penumbra                 13    13    0     13  EditText background/border (P6), glassDisplace
missing_element               12    12    1      9  edittext_border_basic, acid-filter, fonts, h264[frame5]
content_displaced             12    11    0     11  displacement ×2, opaque_background (P2), stage_scale_factor, edittext_scroll
row_banded                     6     6    1      4  blur_pass_scaling, bitmap_pixelsnapping, layers, edittext_border_filters
extra_element                  5     5    0      4  cab_mask_{alpha,transform,filters}, avm1_imports_avm1
offset_translation             3     3    0      3
global_color_shift             2     2    0      1  blur_quality (moved here from extra_element)
localized_region               2     2    0      1
whole_frame_wrong              2     2    0      1  gradient_nonsequential_ratios (P1)
no_render                      1     1    0      1  acid-large ONLY (was 3 mechanisms in s15)
TOTAL                        242                212 live
```

Cluster × band, the ranked top-25 and the cluster×family group table are in
`wave1-gfx-board.rawboard.md`.

## Disposition audit (playbook §3)

- **Hard exclusions: 7** (was 8). All seven resolve `exact` through an
  `<!-- image-axis: … -->` scope marker or an unambiguous test name. **No basename
  matches remain** — s15's P8 is fully discharged.
- **Soft `[trace-ign]` flags kept on the board: 9** (was 8), all `avm2` suite-local
  ignores: `bitmapdata_draw_alpha_erase` (15 000), `displayobject_hittestpoint_boundary`
  (76), `displayobject_scrollrect` (4), `edittext_tag_indent` (7 884),
  `geom_transform` (49 421), `graphics_draw_path` (764), `netstream_play_flv` (229 724,
  **new**), `netstream_seek_flv` (40 672), `stage_scale_factor` (1 912 924). Correct —
  a trace-axis ignore says nothing about pixels.
- **Ruffle `known_failure`: 23**, unchanged set. Notably
  `acid-bitmap-draw_quality_low`, which still caps the VRAM lead's upside at +1.
- **STALE entries (dispositioned but now PASSING): 2**, unchanged from s15 —
  `avm1/display_object_properties` and
  `from_gnash/misc-ming.all/loop/simple_loop_test`. Both docs already carry explicit
  `**STALE**` annotations and are deliberately kept for the mechanism, so this is
  **not** new doc debt; the board will keep printing them.
- **Frame-phase suspects: 0.** Three tests carry more than one cluster
  (`cache_as_bitmap/edittext_hscroll`, `cache_as_bitmap/edittext_selection`,
  `visual/video/h264`), but in each case the split is amplitude, not phase
  (hscroll: `offset_translation`+`hairline`; selection: `halo`+`hairline`; h264:
  `unrelated_content` ×9 + `missing_element` ×1 — all ten frames are the missing
  decoder). The channel §12 declared exhausted is still exhausted.

## Board-hygiene note for the coordinator

The board's **`no_render` bucket is no longer three mechanisms** (s15's bonus hygiene);
it is one row and it belongs to `w1-gfx-vram`. Conversely the **`blank_render` bucket
is now the multi-mechanism trap** — 41 live comparisons spanning five unrelated causes
(Stage3D backend 25, missing decoders 3, unimplemented AVM2 fill paths 3, a discarded
stroke fill 1, and a font/text arc 3). Anyone briefed on "blank_render" as one item
will mis-scope it exactly the way s15's "no_render" brief would have.

---

# APPENDIX — how to reproduce anything above

Scratch artifacts (this session, not committed):
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/b9a79013-0abe-4a85-a932-4fb7420dc877/scratchpad/`

- `image-results/` — extracted `origin/ruffle-image-results` at `30b85f3e7`
- `board.json` / `board.md` — the raw triage board
- `live_rows.txt` — all 212 live comparisons, sorted by cluster then excess
- `sbs.py` — side-by-side montage builder (ours left / Ruffle right) from `board.json`
- `gradscan2.py` — SWF `FILLSTYLEARRAY` / `GRADIENT` record dumper
- `rampsim.py` — exact ports of Ruffle's and our gradient ramp builders (P1's proof)
- `gradcorpus.py` — the 2 848-SWF duplicate/non-monotonic ratio audit
- `corpus/` — scratch copies of the 7 test directories I ran locally.
  **No main-tree test directory was written to except through the normal
  `--tests-dir=<scratch>` path**; the `Recompiled*` caches of
  `visual/gradient_same_ratios`, `visual/cache_as_bitmap/oversize/*`,
  `from_gnash/.../GradientFillTest` and `visual/edittext/*` in the main tree are
  pre-existing and untouched by me.

Local run recipe used (all seven reproduced CI's outlier counts exactly):

```bash
export DAWN_INSTALL=~/CC/dawn-install
python3 ruffle-tests/verify_output.py \
    --tests-dir=<scratch>/corpus/<suite> --test=<name> \
    --mode=graphics --images --verbose --recompile
```

(`--verbose` is mandatory: without it the run prints only the TRACE verdict and a
failing image comparison looks like a pass.)
