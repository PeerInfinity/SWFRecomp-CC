# w2-stage3d — Stage3D A′ + B, productionized. READY TO MERGE.

**Patch:** `SWFRecompDocs/plans/session20-fanout-reports/w2-stage3d.patch`
(1 072 lines, **two files, both pre-existing and tracked**).

## NEW FILES: NONE — confirmed after the rebase

| file | change |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_stage3d.c` | +696 / −43 — the whole A′/B backend |
| `ruffle-tests/render_canary_tests.txt` | +29 — two new canary members (append at EOF) |

Nothing to add to `verify_output.py`'s explicit source list, `CMakeLists.txt` or the
Emscripten build. The coordinator stages exactly those two paths by name; `git add -u`
suffices, there is no new file to drop.

**Rebased twice, and the second rebase mattered.** Branched at `574207007`; rebased onto
`edf5d1e1d`, re-verified, and then — because `556844c30`…`8bf2d42ab` landed while I worked —
rebased again onto **`8bf2d42ab`** and re-verified *everything* from scratch. The source hunk
applied clean both times (`avm2_stage3d.c` has had **zero** commits from anyone else since
`3ba0f1ac9`). `render_canary_tests.txt` **conflicted on the second rebase**, exactly as the
brief warned — `w2-gfx-text-smalls` appends at EOF too. Resolved with `--3way`, keeping **both**
blocks; both sibling members (`avm2/edittext_autosize_height_dynamic`,
`fonts/device_font_kerning`) and both of mine are present in the delivered file.

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w1-stage3d`, branch
`w1-stage3d-proto`, HEAD `8bf2d42ab`, working tree = the patch and nothing else.
Scratch/logs: `<scratchpad>/w1-stage3d/` (`w2.log`, `w3.log`, `w4.log`, `w5.log`).

---

## 1. Verdict

**READY TO MERGE. 8 pixel flips, 0 regressions on any axis.**

**`away3d` is CLEAN, not a watch item** — §4 has the four numbers the coordinator asked for,
measured back-to-back on a quiet box at the delivered base: **master 15.95 s vs this patch
14.60 s**, both PASS. The scare in my wave-1 report was two things stacked, and I fixed one
and disproved the other. I still name the CI check in §4.4, because that row has the least
headroom of any test in the corpus — but it is a belt-and-braces check, not a blocker.

### The ledger, re-measured at `8bf2d42ab` (run `w5`)

| comparison | CI baseline | **this patch** | budget | |
|---|---|---|---|---|
| `avm2/stage3d_stencil` | 651 150 | **0 outliers, max diff 0** | 0 / 0 | **FLIP** |
| `avm2/stage3d_blend` | 692 565 | **35 576, max 32** | 3 / 37 000 | **FLIP** |
| `avm2/stage3d_sampler` | 34 279 | **50** | 1 / 850 | **FLIP** |
| `avm2/stage3d_sampler_partial_upload` | 5 010 | **0, max 1** | 1 / 782 | **FLIP** |
| `avm2/stage3d_ignore_sampler_override` | 191 769 | **6** | 8 / 1 935 | **FLIP** |
| `stage3d/unbound_texture` *(misc)* | 118 800 | **0, max 0** | 1 / 0 | **FLIP** |
| `stage3d/unbound_texture_multiple` *(misc)* | 49 500 | **0, max 0** | 1 / 0 | **FLIP** |
| `stage3d/sampler_odd_size` *(misc)* | 7 854 | **0, max 1** | 1 / 782 | **FLIP** |
| `avm2/stage3d_triangle` | 0 PASS | **0, max 1 PASS** | 1 / 0 | no move |
| `avm2/stage3d_multistage_triangle` | 0 PASS | **0, max 1 PASS** | 1 / 0 | no move |
| `avm2/stage3d_agal_cross_product` | 0 PASS | **0, max 1 PASS** | 2 / 10 | no move |
| `avm2/stage3d_rotating_cube` | 2 144 PASS | **2 148 PASS** | 3 / 2 160 | still passes, margin 12 |
| `stage3d/scissor_rectangle` *(misc)* | 0 PASS | **0, max 1 PASS** | 1 / 0 | no move |
| `avm2/stage3d_texture_bytearray` | 140 625 | 35 747 | 4 / 0 | −75 %, still fails (B′ / ATF only) |
| `avm2/stage3d_texture` | 206 851 | 206 968 | 8 / 117 | RTT + device font |
| `avm2/stage3d_bitmap` | 85 764 | 136 586 | 4 / 24 | renders now, mis-placed (§6) |
| `avm2/stage3d_fractal` | 1 101 100 | 1 101 100 | 2 / 100 | budget + device font (§6) |

Every one of these 17 rows **passes on trace**, before and after. Image comparisons never gate
CI pass/fail.

**Three of the eight flips are `stage3d`-suite = CI `misc` group** and are invisible at
`categories=all`. (Coordinator confirms the grading run is `categories=full`.)

---

## 2. What changed since the wave-1 prototype

### 2.1 The `SWF_S3D_BUDGET` env knob is gone

Removed entirely (function and call site). In its place the constant now carries the
**measurement in both directions**, so the next session does not re-derive it:

```
//   * 12 M is close to the MINIMUM phases A'/B need. Swept down to 6 M,
//     avm2/stage3d_stencil FAILS at 710 400 outliers (it needs 0) and
//     avm2/stage3d_blend FAILS at 2 888 875 (limit 37 000) ...
//   * It is also close to the MAXIMUM avm2/away3d_advanced_shallow_water_demo
//     can afford ...
//   * avm2/stage3d_fractal would need ~200 M ... and avm2/stage3d_raytrace ~15 G.
```

### 2.2 A bit-identical performance hoist — the real fix for §4

The per-sample store re-read `be->blend_src`, `be->color_mask`, `be->depth_func`,
`be->st_*[face]`, `be->has_depth` and `be->w` **on every sample**. The compiler cannot hoist
them: `be->color` / `be->depth` / `be->stencil` are writable `float*` / `uint8_t*` that may
alias `*be`, so each one is a genuine reload. All of it is now lifted to per-draw locals, and
the full-open colour mask takes a `memcpy` instead of a four-way branch.

**Proven bit-identical, not argued**: a render-canary A/B between the pre-hoist and post-hoist
builds over 12 tests / 18 comparisons came back **18/18 IDENTICAL** at md5 (`w3.log`). The
effect on the clock is in §4.

### 2.3 Two canary members added, after an audit

**Audit result: the set could not see this change class.** It already had the two s19 Stage3D
members (`avm2/stage3d_triangle`, `avm2/stage3d_rotating_cube`) and they do cover the *shared
rasteriser* half — `rotating_cube` moved 53 channels under the subpixel snap, so it is a live
witness. But **nothing** in the set could see blend factors, the stencil plane, the colour mask
or any texture sampling: every other member renders through the 2D path, which this change does
not touch at all.

Added (tier 2 until the grading run confirms them):

* **`avm2/stage3d_stencil`** — stencil plane + `setStencilActions` + read/write masks +
  `setColorMask` + the top-left fill rule + the subpixel snap, **all in one tolerance-0 /
  max-outliers-0 comparison that now passes at max diff 0**. Promote to **tier 1** after the
  first `categories=full images=true` run: it is the strictest single guard the Stage3D backend
  can have.
* **`avm2/stage3d_sampler`** — `uploadFromBitmapData` + `tex` across all four wrap modes ×
  nearest/linear, plus the `setSamplerStateAt`-vs-`setProgram` precedence rule.

---

## 3. Verification at the delivered base (`8bf2d42ab`)

### 3.1 Render canary A/B — md5, 12 tests / 18 comparisons

```
RENDER CANARY  before=base2  after=w2   12 tests / 18 comparisons
  IDENTICAL    15
  DIFFERS       3
  APPEARED      0   VANISHED 0   NO_RENDER 0
  DIFFERS:
    avm2/stage3d_rotating_cube  output   diff 53/880000      max 64    pass -> pass
    avm2/stage3d_sampler        output   diff 34295/880000   max 255   fail -> pass
    avm2/stage3d_stencil        output   diff 651150/2560000 max 204   fail -> pass
  TRACE STATUS CHANGES: (none)
```

Exactly the shape a correct slice produces: **every non-Stage3D comparison byte-identical**
(`avm1/color`, `avm2/blend_multiply_alpha`, all **seven** `visual/cache_as_bitmap/masks`
comparisons, `regression/mask_nested_intersect`, `from_shumway/acid/acid-bitmap-fill`,
`avm2/graphics_bitmaps`, `avm2/graphics_simple_shapes`, `regression/avm2_graphics_runtime`),
the three that moved are all Stage3D, two of them `fail -> pass`, and no trace status moved.
`stage3d_triangle` is byte-identical — phase A's canonical row is untouched to the bit.

The members were chosen to cover the 2D paths a Stage3D change could plausibly reach: the AVM2
render walk, the dynamic bitmap-quad path the composite reuses, the CPU composite, and — via
the sweep — the GC ext-free hook the texture texels now hang off.

### 3.2 Regression suite — 11/11 PASS

`avm2_gc_dynprop_tombstone_purge`, `avm2_gc_string_concat_reclaim`,
`avm2_gc_string_survives_collect` (the new ext-free arm), `avm2_parent_child_render` (96/400),
`avm2_timeline_solid`, `avm2_timeline_gradients` (0 outliers), `avm2_static_text`,
`avm2_graphics_runtime`, `avm2_morph` (the AVM2 render walk), `mask_nested_intersect`
(**0 / max 0**), `bitmap_pool_layer_cap` (**0 / max 0**) — the bitmap-quad path the Stage3D
composite reuses. No status moved and no image comparison with a golden moved.

### 3.3 No local render was graded against a golden as a verdict

Every "flip" above is `verify_output.py`'s own image check with the test's own `test.toml`
budget — the same code CI runs — and the canary verdicts are md5 A/B only. The lavapipe-vs-
local-Dawn question does not arise for the A/B, and for the absolute grades the CI grading run
is the authority; these numbers are the prediction.

---

## 4. `away3d` — settled, with the four numbers

### 4.1 The four numbers (quiet box, back-to-back, at the delivered base `8bf2d42ab`, `w5.log`)

| leg | `away3d_advanced_shallow_water_demo` | `stage3d_raytrace` |
|---|---|---|
| **master, patch reverted** | **15.95 s — PASS (trace)** | **1.88 s — PASS** |
| **this patch (delivered)** | **14.60 s — PASS (trace)** | **1.83 s — PASS** |

Load average 2.5-4.5 during both legs, `git apply -R` / `git apply` between them (never
`git stash`). **The delivered build is not measurably slower than master on either row**, and
on this pair it is nominally faster — i.e. the delta is inside the noise.

### 4.2 The whole measurement history, because the shape of it is the lesson

| box load | leg | away3d | raytrace |
|---|---|---|---|
| ~9-10 (8-agent peak) | master | **TIMEOUT 30.20 s** | — |
| ~9-10 | patch, **pre-hoist** | **TIMEOUT 30.17 s** | — |
| ~8.6 → 5.6 | master | 26.19 s PASS | 2.85 s |
| ~8.6 → 5.6 | patch, **pre-hoist** | 29.32 s PASS | 2.94 s |
| ~6 | patch, **hoisted** | 23.06 / 20.60 s PASS | 2.59 s |
| ~4.8-7 | master | 19.92 / 15.21 s PASS | 1.93 s |
| ~4.8-7 | patch, hoisted | 19.66 / 18.41 s PASS | 2.49 s |
| **~2.5-4.5** | **master** | **15.95 s PASS** | **1.88 s** |
| **~2.5-4.5** | **patch, hoisted (delivered)** | **14.60 s PASS** | **1.83 s** |

Two independent facts fall out:

1. **The two TIMEOUTs were the box, not the patch** — master timed out too, at the same load,
   minutes apart. `away3d` runs anywhere from **15 s to 30 s at unchanged code** depending on
   what else is compiling. Any future session measuring this row under a fan-out will see the
   same thing; measure it idle or not at all.
2. **The pre-hoist patch really did cost ~+3 s (+12 %)** and the hoist gave it back. Both halves
   are measured: pre-hoist 26.19 → 29.32 at equal-ish load, post-hoist 15.95 → 14.60.

### 4.3 Why lowering the budget was not the lever

Measured with the knob, before removing it: at `SWF_S3D_BUDGET=6000000`, **`stage3d_stencil`
fails at 710 400 outliers and `stage3d_blend` fails at 2 888 875**. 12 M is close to the minimum
A′ needs, so "buy away3d headroom by shrinking the budget" was never available. The hoist was.
That measurement is now a comment on the constant (§2.1).

### 4.4 What the grading run should still check

`away3d_advanced_shallow_water_demo` and `stage3d_raytrace` must read **`pass`** (not
`timeout`) in `results_graphics.json`. Not because this patch is suspect — it isn't, per §4.1 —
but because `away3d` is the single row in the corpus closest to `verify_output.py`'s hard 30 s
wall, and a CI runner having a bad day would surface there first, with or without this change.

---

## 5. The three refutations, stated for playbook §19

Quote-ready, each independently evidenced:

1. **`avm2/stage3d_blend` is not a texture row.** Its `Test.as` contains no `tex`, no
   `setTextureAt` and no texture of any kind — `m44` + per-vertex colours + `setBlendFactors`,
   nothing else. s19 filed it under "needs G2 *and* G4's textures"; it is a **pure A′ row**
   costing ~60 LOC, and it is the pixel board's largest Stage3D row (#17, 687 365 excess,
   1 300 × 810). It flips on blend factors alone.
2. **`avm2/stage3d_fractal` is not an A′ row.** Its only A′ call is
   `setColorMask(true,true,true,false)`, and masking alpha has **exactly zero** visual effect
   because the composite is opaque (`bitmap_opaque` / `ColorWrites::COLOR` — the 3D alpha never
   reaches the stage). It is a **cost-budget** row: ~197 M budget units against a 12 M cap, so
   it latches off before `present()` and composites a never-resolved black front buffer. So
   **A′ flips 2 — `stencil` and `blend`, not `stencil` and `fractal`.**
3. **RTT flips nothing; do not fund it.** `setRenderToTexture` is used by exactly two corpus
   rows: `avm2/stage3d_texture`, whose `max_outliers` is 117 while its golden carries eight
   device-font text runs we render as empty white boxes, and `away3d`, which is HOLD. A ~180-LOC
   render-target redirection buys **zero** flips until the device-font arc lands first.

---

## 6. The two follow-ups, captured (NOT implemented)

### 6.1 `stage3d_fractal` — and **which** device-font fix it needs

**It needs s19's unlanded A1 outline-emission prototype
(`session19-fanout-reports/UNLANDED-devicefont-prototype.patch`), pointed at the bundled
default font. It does NOT need the bold/italic ladder** that landed this session in
`6cf74920c`.

Evidence, measured after `6cf74920c` was already in my base: `stage3d_texture` grades
**206 968** outliers at `8bf2d42ab` — byte-for-byte the same number it had before the ladder
landed (§1). The ladder is A1s: it picks a *different face* when a family lacks an italic/bold
member. These rows fail one step earlier — the recompiler emits **no glyph outlines at all**
for device faces, so there is nothing for any ladder to choose between. `stage3d_texture`'s
actual shows the five white button backgrounds with **no glyphs inside them**; that is the A1
signature, not the A1s one.

The extra wrinkle: all three of these rows are `with_default_font = true`, i.e. Ruffle's bundled
Noto, not a `[fonts.*]` TTF. s19 §4.1 already scoped that as "the same emitter pointed at
`SWFRecomp/assets/NotoSans.ttf`", and recorded that this file is **byte-identical (md5
`994ff225…`) to Ruffle's bundled `notosans.subset.ttf.gz`** — so the oracle is already in the
repo.

**The completion mechanism, precisely:** raise the fragment budget to ~200 M *and* land A1 with
the default-font wiring. Measured at a 400 M budget (wave-1, with the knob): the Julia set
renders essentially perfectly in **11.2 s**, scoring **29 620 outlier channels of which 29 019
are the two device-font text bands**; outside the text rows entirely there are **2 pixels**
(≤ 8 channels) against a budget of **100**. That is the strongest single argument in the corpus
for funding A1, which was correctly priced at "flips nothing" *on its own*. It should be the
first line of session 21's Stage3D entry.

Caveat I must name: a 200 M budget on this rasteriser costs ~11 s locally for `fractal` alone,
and §4 shows `away3d` has no room for a global raise. A per-context or per-frame budget, or the
fixed-point rasteriser of §7, is the honest way in — not a bigger constant.

### 6.2 `stage3d_bitmap`

Re-confirmed at the delivered base: **136 586** outliers (limit 24). The sprites now render and
the art is pixel-correct; what remains is **placement** — the SWF drives spawn positions from
`Math.random` (7 call sites) and motion from `getTimer` (7 call sites), so the residual is an
AVM2 RNG-draw-sequence and/or frame-clock-phase divergence, plus the missing device-font title
line. Three arcs for one comparison at `tolerance 4 / max_outliers 24`. **NO-GO, permanently, on
the pixel axis** — but the RNG/clock question is worth a session on its own merits, because it
cannot be confined to this row.

---

## 7. New unclaimed leads

* **A fixed-point rasteriser is now over-determined.** §2.3 of the wave-1 report shows the
  backend already *needs* 8-bit subpixel snapping for correctness (it is what took
  `stage3d_stencil` from 81 wrong pixels to 0). Doing the edge functions in integers after that
  snap removes the float-compare fragility **and** cuts the per-sample cost — which is the same
  cost that governs `away3d`'s headroom (§4) and `fractal`'s budget (§6.1). One change, three
  payoffs. Nobody owns rasteriser performance.
* **`away3d` runs 15-30 s at unchanged code depending on box load** (§4.2). It is the corpus's
  nearest-to-the-wall row and it has now produced two false TIMEOUTs in two different sessions.
  Somebody should either raise `run_binary`'s 30 s wall for this one test or make it cheap;
  right now it is a tripwire that fires on load.
* **`avm2/stage3d_texture`'s glyph-less white boxes are a free, tiny reproduction of the
  device-font A1 defect** — far cheaper to iterate on than `visual/fonts/device-font`.
* **Nothing in the corpus exercises `Stage3D.x`/`y` non-zero, and nothing exercises cube-map
  sampling** — this patch returns zero for `Dimension::Cube` and no graded row notices.
* **B′ is now a single isolated mechanism.** `stage3d_texture_bytearray`'s entire residual is
  the one `uploadCompressedTextureFromByteArray` (ATF) texture; both logos already match. ATF
  decode unblocks three comparisons (`texture_bytearray` at 4/0, `texture_bytearray_compressed_
  alpha` and `_raw_alpha` at 4/66). A wave-2 agent must first establish which of DXT1/DXT5 and
  JPEG-XR each ATF actually carries — the container parse from tranche S2 already exists.

---

## 8. Tests run (all `--mode=graphics`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, sequential)

| log | scope | result |
|---|---|---|
| `w2.log` | at `edf5d1e1d`: canary A/B (12 tests), away3d+raytrace both legs, 14 Stage3D image rows, 11 regression | 15/18 canary identical; away3d 26.19 → 29.32 s PASS; all rows as §1; regression 11/11 |
| `w3.log` | the hoist: canary A/B **pre-hoist vs post-hoist** | **18/18 IDENTICAL**; away3d 23.06 / 20.60 s; 13 rows unchanged |
| `w4.log` | clean back-to-back away3d A/B at `edf5d1e1d` | master 19.92 / 15.21 s vs patch 19.66 / 18.41 s, all PASS |
| `w5.log` | **rebased to `8bf2d42ab`: the authoritative run.** canary A/B, away3d+raytrace both legs, 13 Stage3D image rows, 11 regression | canary 15/18 identical (same channel counts as `w2`); **away3d master 15.95 s vs patch 14.60 s, both PASS**; every §1 number reproduced; regression 11/11 |
| `w6` | `stage3d_texture`, `_bytearray`, `_fractal`, `_bitmap` at `8bf2d42ab` | 206 968 / 35 747 / 1 101 100 / 136 586 — all four unchanged by `6cf74920c`, which is the §6.1 evidence |

Not run: the full suites (forbidden locally), and `from_avmplus` (no Stage3D content).
