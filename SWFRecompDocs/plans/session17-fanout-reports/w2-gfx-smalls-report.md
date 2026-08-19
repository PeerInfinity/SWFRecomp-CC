# Session 17 — wave 2 — `w2-gfx-smalls` (pixel axis)
## P1 `BitmapData.copyPixels` un-premultiply · P2 AVM2 gradient ramp TRUNC · P3 (bonus) the AVM1 ramp twin

**Agent:** `w2-gfx-smalls`, own worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a6edad2be4b494623`.
No commits, no pushes. Baseline: run `31877239992` @ `aeebf9ede`, pixels 338/569.

---

## NEW FILES CREATED BY THESE PATCHES

**NONE.** Every edit lands in a file that already exists and is already in
`verify_output.py`'s explicit source list (`verify_output.py:2154`):

* `SWFModernRuntime/src/actionmodern/action.c`   (P1 and P3)
* `SWFModernRuntime/src/avm2/avm2_display.c`     (P2)

The P1 helper is a `static inline` added *inside* `action.c` — deliberately not a
new header, per the s16 lesson that a new `.h` is invisible to the harness'
explicit copy list.

---

# VERDICTS

| lead | verdict | priced | measured | patch |
|---|---|---|---|---|
| **P1** — `copyPixels` alpha-source un-premultiply | **GO — flip landed, byte-exact** | +1 | **+1** (`avm1/bitmap_data_copypixels` 840 → **0**, max diff **0**) | `w2-gfx-smalls-copypixels.patch` |
| **P2** — AVM2 `gfx_gen_ramp` ROUND → TRUNC | **GO — flip landed** | +1 | **+1** (`avm2/graphics_gradients_nulls` 600 → **0**, max diff 5 / tol 5) | `w2-gfx-smalls-ramp-trunc.patch` |
| **P3** — AVM1 `drawingGenerateGradientRamp` ROUND → TRUNC (the board's "optional twin") | **GO (0 flips, net band gain, 0 regressions)** | *board: "may move either way, ship AVM2 alone if the A/B disagrees"* | 0 flips; **−51 / −2 / +2** band, the one PASSING AVM1 gradient row **improved** | `w2-gfx-smalls-ramp-trunc-avm1.patch` |

**Net for the merged CI run: +2 pixel comparisons (338 → 340), 0 regressions on
either axis, 3 band improvements and 1 band worsening of +2 channels.**

### Patch files and how to apply them

Delivered in `SWFRecompDocs/plans/session17-fanout-reports/` (worktree **and**
main tree):

| patch | file | diffstat | lead |
|---|---|---|---|
| `w2-gfx-smalls-copypixels.patch` | `SWFModernRuntime/src/actionmodern/action.c` | +23 / −1 | P1 |
| `w2-gfx-smalls-ramp-trunc.patch` | `SWFModernRuntime/src/avm2/avm2_display.c` | +4 / −1 | P2 |
| `w2-gfx-smalls-ramp-trunc-avm1.patch` | `SWFModernRuntime/src/actionmodern/action.c` | +5 / −1 | P3 |

Verified: `git apply` of all three, in the order above, on a clean `88ebde665`
tree reproduces **byte-for-byte** the tree the §4 numbers were measured on. Each
is also independently applicable (the two `action.c` hunks are ~15 900 lines
apart), so P3 can be dropped without disturbing P1.

Textual disjointness from `SIBLING_FILE_MAP.md`: P1/P3 sit in `action.c`'s
BitmapData (~:12 285) and drawing-ramp (~:28 280) regions — w2-sound-load owns the
Sound region, w2-crossvm-legE owns `actionTickAvm1ChildrenUnderAvm2`/`processTimers`,
w2-gfx-cab-pixelsnap owns `compose_children`. P2 is one argument inside
`gfx_gen_ramp` (~:7 973), well away from `gfx_draw_graphics_data` (~:8 819), the
AVM2 `.filters` render path, and `compose_children`.

Both flips are **CI-grade proven** by the s13 rule: my *before*-leg local PNG is
**byte-identical (md5)** to the CI `*.actual.png` published by run `31877239992`
for every flipped and every near-flipped row (table in §4).

---

# 1. P1 — `BitmapData.copyPixels` with an alpha source

## Mechanism (confirmed, and confirmed a second way the board did not use)

Ruffle's `copy_pixels_with_alpha_source`
(`~/CC/ruffle/core/src/bitmap/operations.rs:1200-1210`) un-premultiplies the
source with **`f64` division and `.round()`**, *not* with its own
`FLASH_PREMUL_FACTOR` table, and says so in a comment. We were calling
`unpremultiplyAlpha()` — which *is* the table.

**Independent corroboration the board missed:** the **AVM2 twin already does it
Ruffle's way.** `SWFModernRuntime/src/avm2/avm2_bitmap.c::bd_copy_pixels`
(~:1325) has, verbatim:

```c
double af = (double) CA(sc) / 255.0;
uint8_t r = af > 0 ? (uint8_t) round((double) CR(sc) / af) : 0;
```

So this was an AVM1/AVM2 divergence inside our own tree, not just a Ruffle
mismatch. The patch makes AVM1 agree with AVM2 and with Ruffle.

## Arithmetic, verified offline before building anything

For the test's source fill `0xAA2288DD` (α=170), stored premultiplied as
(23, 91, 147):

| | R | G | B |
|---|---:|---:|---:|
| table `unpremultiplyAlpha` (Flash-exact round trip) | 34 | 136 | 220 |
| Ruffle's `round(c·255/α)` | **35** | **137** | **221** |
| re-premultiplied at `final_alpha=158`, table | 21 | 84 | 136 |
| re-premultiplied at `final_alpha=158`, float | **22** | **85** | **137** |

i.e. exactly `+1` on R, G and B — precisely the sign and magnitude of the
board's measured residual (280 px all at `−1`). Scratch program:
`<scratch>/w2gfxsmalls/helper_check.c`.

## Scope discipline

`unpremultiplyAlpha()` and `premultiplyAlpha()` are **untouched** (18 other call
sites, graded by passing tests). The new helper is `static inline` and has
**exactly one caller**. `a == 0` returns 0 (Rust: `0.0/0.0 → NaN`, `NaN as u8 == 0`);
`a == 255` is the identity; results are clamped to 255 (C's `(uint8_t)` of an
out-of-range double is UB, Rust's `as u8` saturates).

## Result

`avm1/bitmap_data_copypixels [output]`: **840 outliers → 0, max difference 0** —
**byte-exact against the golden**, not merely inside a tolerance.

---

# 2. P2 — AVM2 runtime gradient ramp rounds where Ruffle truncates

## Mechanism re-verified independently of the board

I rebuilt both candidate ramps from the test's own stops
(`[0,0xFFFFFF,0,0xFFFFFF,0]`, null ratios → `(i·255)/(n−1)` = `0,63,127,191,255`)
and intersected them with the **golden's own value set** over the gradient band
(x 101–298, y 100–299):

* golden distinct greys: **114**
* greys absent from the **TRUNC** ramp: **0**
* greys absent from the **ROUND** ramp: **47**

Ruffle's oracle is `render/wgpu/src/mesh.rs::CommonGradient::new`, where all four
channels are `lerp(...) as u8` — truncation, alpha included.
`gradient_ramp.h`'s `rounding` argument is consulted by the `GRADIENT_RAMP_SRGB`
(default) colour branch *and* by the alpha channel, so one token moves both.

## Result

`avm2/graphics_gradients_nulls [output]`: **600 → 0** (max diff 5, tolerance 5).
The failing column at `x = 125` moved from `131` to `130` against an expected
`125`, i.e. diff 6 → diff 5, and `> tolerance` is strict, so it is inside.

## The refuted half stays refuted

`GRADIENT_RAMP_LINEAR_U8 → _LINEAR` was **not** touched and must not be bundled:
no image-bearing test passes `interpolationMethod = "linearRGB"` to a runtime
gradient. (Corollary worth recording: the `LINEAR_U8` branch **ignores the
`rounding` argument for the three colour channels** — it always truncates — so a
linearRGB gradient is unaffected by P2/P3 except in its alpha channel.)

---

# 3. REFUTATION — the board's P2 blast-radius audit was incomplete

> Board: *"I enumerated every image-bearing test in the corpus (384) and grepped
> for runtime gradients … Exactly 7 hit, and not one of them currently passes …
> Zero pixel-regression risk."*

The board grepped **`.as` sources**. Many corpus tests ship only `test.swf`. I
re-ran the enumeration by **decompressing every image-bearing `test.swf`**
(CWS/zlib and ZWS/LZMA; 415 SWFs across 412 image-bearing tests) and grepping the
decompressed bytes for `beginGradientFill` / `lineGradientStyle`, then classified
each hit AVM1-vs-AVM2 by tag scan (`DoABC`/`SymbolClass`).

**Three image-bearing runtime-gradient tests were missing from the board's list,
and one of them PASSES today:**

| test | VM | s17 baseline | board listed it? |
|---|---|---|---|
| `from_gnash/misc-ming.all/GradientFillTest` | **AVM1** | **PASS** (938 outliers / limit 1070 — only **12 %** slack) | **no** |
| `visual/drawing_api/fills_and_lines` | **AVM1** | fail 104 @ tol 2 | **no** |
| `visual/drawing_api/gradient_focal_point` | **AVM1** | fail 60 @ tol 13 | **no** |
| `avm2/away3d_advanced_shallow_water_demo` | AVM2 | fail 1 331 281 | no |

Corrected inventory:

* **AVM2 sites (what P2 touches):** `graphics_gradients_nulls`,
  `graphics_gradients`, `blend_shader_luma_lighten`, `visual/filters/displacement_map`,
  `regression/avm2_graphics_runtime` (skip, no golden),
  `avm2/away3d_advanced_shallow_water_demo`. **Six, none passing ⇒ the board's
  "zero regression risk" conclusion holds for P2** (for a partly different reason
  than it gave).
* **AVM1 sites (what P3 touches):** `movieclip_begin_gradient_fill`,
  `movieclip_line_gradient_style`, `drawing_api/fills_and_lines`,
  `drawing_api/gradient_focal_point`, **`misc-ming.all/GradientFillTest` (passing)**.
  **The "zero risk" claim was NOT true for the AVM1 twin** — there was one
  passing comparison at 12 % slack in the line of fire. It had to be measured,
  and it was.

**Second refutation — the two "extra" AVM1 near-passes are not ramp leads.**
Measured from the CI `*.actual.png` against the goldens:

* `fills_and_lines` (104 outliers): dominant signed deltas `(−255,−255,−255)`,
  `(255,0,255)`, `(0,−255,0)` — whole-pixel *geometry*, black where colour is
  expected. A ±1 ramp step cannot touch it.
* `gradient_focal_point` (60 outliers): two columns, `x=220` at `−39` and
  `x=236` at `+17`, red channel only, 30 rows each — the focal point is in the
  wrong *place*; the ramp values are fine.

Both were confirmed **unchanged (104 → 104, 60 → 60)** by the A/B.

**Third refutation — `avm2/bitmapdata_copypixels*` are not P1 controls.**
The brief asked for 4–5 `avm2/bitmapdata_copypixels*` rows as P1 guards. They are
structurally incapable of moving: AVM2 `copyPixels` lives in a different TU
(`avm2_bitmap.c`) and *already* used the float+round form. I graded
`avm2/bitmapdata_copypixels` (25 200, unchanged by construction) and
`avm2/bitmapdata_draw_alpha_erase` (a tol-0 PASS that exercises `avm2_display.c`,
which P2 edits), and substituted two *real* P1 guards the brief did not name:
* `visual/bitmapdata_copypixels_with_alpha_oob` — a `copyPixels`-**with-alpha-source**
  test passing at `tolerance 0` (AVM2 route ⇒ invariant; verified 0 → 0);
* `avm1/bitmap_data_thorough/copyPixels` — the **only other AVM1 test in the
  corpus that calls `copyPixels` with an alpha bitmap** (`Test.as:34`), a trace
  test whose expected output disagrees Flash-vs-Ruffle *in exactly this arm*.
  It was `RUFFLE_MATCHED` before and after (no trace movement).

---

# 4. PER-COMPARISON LEDGER (local `--mode=graphics`, same machine, both legs)

`before` = HEAD (`88ebde665`) unpatched. `after` = all three patches applied.
Attribution is unambiguous: P1 touches only AVM1 `copyPixels`-with-alpha, P2 only
the AVM2 ramp, P3 only the AVM1 ramp — three disjoint code paths and three
disjoint row sets.

| comparison | owner | before | after | Δ | verdict |
|---|---|---:|---:|---:|---|
| `avm1/bitmap_data_copypixels [output]` | **P1** | 840 fail | **0 (max 0)** | **−840** | **PASS — FLIP** |
| `avm1/bitmap_data_thorough/copyPixels` (trace) | P1 | RUFFLE_MATCHED | RUFFLE_MATCHED | — | unchanged |
| `visual/bitmapdata_copypixels_with_alpha_oob [output]` | P1 control (AVM2) | 0 pass | 0 pass | 0 | unchanged |
| `avm2/bitmapdata_copypixels [output]` | P1 control (AVM2) | 25 200 fail | 25 200 fail | 0 | unchanged |
| `avm2/graphics_gradients_nulls [output]` | **P2** | 600 fail | **0 (max 5, tol 5)** | **−600** | **PASS — FLIP** |
| `avm2/graphics_gradients [output]` | P2 | 3 338 fail | **3 199** fail | **−139** | band gain |
| `avm2/blend_shader_luma_lighten [output]` | P2 | 1 237 fail | 1 237 fail | 0 | unchanged |
| `visual/filters/displacement_map [output]` | P2 (row owned by cut 2) | 123 378 fail | 123 378 fail | 0 | unchanged |
| `avm2/bitmapdata_draw_alpha_erase [output]` | P2 control (tol 0) | 0 pass | 0 pass | 0 | unchanged |
| `avm1/movieclip_begin_gradient_fill [output]` | **P3** | 723 fail | **672** fail | **−51** | band gain |
| `avm1/movieclip_line_gradient_style [output]` | **P3** | 1 420 fail | **1 422** fail | **+2** | band loss (0.14 %) |
| `from_gnash/misc-ming.all/GradientFillTest [output]` | **P3 (the risk row)** | 938 pass / limit 1070 | **936** pass | **−2** | **still PASS, slack 132 → 134** |
| `visual/drawing_api/fills_and_lines [output]` | P3 | 104 fail | 104 fail | 0 | unchanged |
| `visual/drawing_api/gradient_focal_point [output]` | P3 | 60 fail | 60 fail | 0 | unchanged |
| `visual/gradient_issue_9892 [output]` | static-ramp control | 2 317 pass / 2 329 | 2 317 pass | 0 | **byte-identical** |
| `visual/gradient_nonsequential_ratios [output]` | static-ramp control | 1 280 pass / 1 300 | 1 280 pass | 0 | **byte-identical** |
| `visual/gradient_radial_same_ratios [output]` | static-ramp control | 3 762 pass / 3 860 | 3 762 pass | 0 | **byte-identical** |
| `visual/gradient_same_ratios [output]` | static-ramp control | 5 120 pass / 5 130 | 5 120 pass | 0 | **byte-identical** |

Every trace verdict in both legs was `PASS` (or `RUFFLE_MATCHED` /
`MISMATCH`-as-before for `bitmap_data_thorough/copyPixels` and `GradientFillTest`);
**no test changed trace status in either direction.**

## Local ≡ CI proof (s13 rule)

`before`-leg local PNG vs the CI `*.actual.png` force-pushed by run `31877239992`
to `ruffle-image-results`:

| comparison | md5 (local before) | md5 (CI actual) | identical |
|---|---|---|---|
| `avm1/bitmap_data_copypixels` | `d6c4e03f399f9098491fe56e200fcae3` | `d6c4e03f399f9098491fe56e200fcae3` | ✅ |
| `avm2/graphics_gradients_nulls` | `d3387ede7c471708e8a7eeccde836ed9` | `d3387ede7c471708e8a7eeccde836ed9` | ✅ |
| `avm2/graphics_gradients` | `715be0f70ccba01525ca55f74ff69f29` | `715be0f70ccba01525ca55f74ff69f29` | ✅ |
| `avm2/blend_shader_luma_lighten` | `4728712c3ce41a334c6e5d73b5e19f28` | `4728712c3ce41a334c6e5d73b5e19f28` | ✅ |

and the *numeric* baselines reproduced CI exactly on 16 of 17 graded rows
(840/723/1420/600/3338/1237/25200/104/60/938/0/0 …). The single exception is
`visual/filters/displacement_map`: **123 378 local vs 123 218 in CI (+0.13 %)** —
a pre-existing local-vs-CI delta on a row that fails by three orders of magnitude
either way, and it is unchanged by these patches. Flagged for
`w2-gfx-filters-cut2`, not caused here.

---

# 5. CANARY — 52 / 52 IDENTICAL

`ruffle-tests/render_canary.py capture --label before|after -P 2 --timeout 2400`
over the standing `render_canary_tests.txt` set (`--recompile` on the `before`
leg, per the s16 rule for `cp -r`'d dirs), then `compare before after`:

```
RENDER CANARY  before=before  after=after   25 tests / 52 comparisons

  IDENTICAL    52
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0

  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

Per-PNG md5 (before → after; all 52 identical, first 12 hex digits):

| png | before | after | |
|---|---|---|---|
| `avm1/bitmap_data_fillrect/output.png` | `c2626aa5b2ec` | `c2626aa5b2ec` | = |
| `avm1/bitmapdata_applyfilter_colormatrix/output.png` | `c5c7ecd1f778` | `c5c7ecd1f778` | = |
| `avm1/color/output.png` | `44a2ebaca9c5` | `44a2ebaca9c5` | = |
| `avm1/edittext_tag_indent/output.png` | `93bfd4a5d040` | `93bfd4a5d040` | = |
| `avm1/focusrect_swf5/output.01a.png` | `d41402615a68` | `d41402615a68` | = |
| `avm1/focusrect_swf5/output.01b.png` | `dc64abcf73a6` | `dc64abcf73a6` | = |
| `avm1/focusrect_swf5/output.02a.png` | `e542ecbdc849` | `e542ecbdc849` | = |
| `avm1/focusrect_swf5/output.02b.png` | `e542ecbdc849` | `e542ecbdc849` | = |
| `avm1/focusrect_swf5/output.03a.png` | `e542ecbdc849` | `e542ecbdc849` | = |
| `avm1/focusrect_swf5/output.03b.png` | `e542ecbdc849` | `e542ecbdc849` | = |
| `avm1/focusrect_swf5/output.04a.png` | `d41402615a68` | `d41402615a68` | = |
| `avm1/focusrect_swf5/output.04b.png` | `dc64abcf73a6` | `dc64abcf73a6` | = |
| `avm1/focusrect_swf5/output.05a.png` | `d41402615a68` | `d41402615a68` | = |
| `avm1/focusrect_swf5/output.05b.png` | `dc64abcf73a6` | `dc64abcf73a6` | = |
| `avm1/focusrect_swf5/output.06a.png` | `e542ecbdc849` | `e542ecbdc849` | = |
| `avm1/focusrect_swf5/output.06b.png` | `e542ecbdc849` | `e542ecbdc849` | = |
| `avm1/mask_with_drawing/output.png` | `c19e92c79fe3` | `c19e92c79fe3` | = |
| `avm1/movieclip_setmask/output.png` | `0ca5d413f564` | `0ca5d413f564` | = |
| `avm2/blend_multiply_alpha/output.png` | `191f3bccbf61` | `191f3bccbf61` | = |
| `from_shumway/acid/acid-blend-2/output.10.png` | `af53d0f443c1` | `af53d0f443c1` | = |
| `from_shumway/acid/acid-blend-2/output.15.png` | `fbf93a8d80b9` | `fbf93a8d80b9` | = |
| `from_shumway/acid/acid-blend-2/output.20.png` | `1c5925f3bba8` | `1c5925f3bba8` | = |
| `from_shumway/acid/acid-blend-2/output.26.png` | `ba67137f3579` | `ba67137f3579` | = |
| `from_shumway/acid/acid-blend-2/output.40.png` | `4c199b0106ce` | `4c199b0106ce` | = |
| `from_shumway/acid/acid-gradient-0/output.png` | `e8d2dbfc5bec` | `e8d2dbfc5bec` | = |
| `from_shumway/timeline/timeline_as2_5/output.01.png` | `96adf09a2cf1` | `96adf09a2cf1` | = |
| `from_shumway/timeline/timeline_as2_5/output.02.png` | `5aae70f128ff` | `5aae70f128ff` | = |
| `from_shumway/timeline/timeline_as2_5/output.03.png` | `fc036618415d` | `fc036618415d` | = |
| `from_shumway/timeline/timeline_as2_5/output.04.png` | `b3daf897821a` | `b3daf897821a` | = |
| `from_shumway/timeline/timeline_as2_5/output.05.png` | `1d17c720355c` | `1d17c720355c` | = |
| `from_shumway/timeline/timeline_as2_5/output.06.png` | `8a8185f53917` | `8a8185f53917` | = |
| `from_shumway/timeline/timeline_as2_5/output.07.png` | `258a5150ae2e` | `258a5150ae2e` | = |
| `regression/avm2_morph/output.png` | `d2fe8a7b80ae` | `d2fe8a7b80ae` | = |
| `regression/avm2_timeline_gradients/output.png` | `b1621d75da17` | `b1621d75da17` | = |
| `regression/avm2_timeline_stroke_gradient/output.png` | `c8ade16d7b81` | `c8ade16d7b81` | = |
| `regression/mask_nested_intersect/output.png` | `8a4ca41f3b3c` | `8a4ca41f3b3c` | = |
| `regression/mask_sibling_union/output.png` | `26d214803656` | `26d214803656` | = |
| `visual/blend_modes/multiply/output.png` | `8c077f835d2b` | `8c077f835d2b` | = |
| `visual/cache_as_bitmap/masks/output.01.png` | `01f2fcb4c243` | `01f2fcb4c243` | = |
| `visual/cache_as_bitmap/masks/output.02.png` | `c9b919e87735` | `c9b919e87735` | = |
| `visual/cache_as_bitmap/masks/output.03.png` | `fd8eeb3e3bea` | `fd8eeb3e3bea` | = |
| `visual/cache_as_bitmap/masks/output.04.png` | `ea505b26d519` | `ea505b26d519` | = |
| `visual/cache_as_bitmap/masks/output.05.png` | `4e67c8a8c478` | `4e67c8a8c478` | = |
| `visual/cache_as_bitmap/masks/output.06.png` | `bf922fe6c52c` | `bf922fe6c52c` | = |
| `visual/cache_as_bitmap/masks/output.07.png` | `700b72c1c9e8` | `700b72c1c9e8` | = |
| `visual/cache_as_bitmap/shape_changed/output.png` | `f7b0c91b5b36` | `f7b0c91b5b36` | = |
| `visual/filters/color_matrix/output.png` | `de05533619dc` | `de05533619dc` | = |
| `visual/filters/drop_shadow/output.png` | `3b46c880ce08` | `3b46c880ce08` | = |
| `visual/filters/glow_pass_scaling/output.png` | `94dd9e231c4f` | `94dd9e231c4f` | = |
| `visual/simple_shapes/gradients/gradients/output.png` | `d6025108f067` | `d6025108f067` | = |
| `visual/simple_shapes/masks/output.png` | `4916fcb782ed` | `4916fcb782ed` | = |
| `visual/simple_shapes/winding_rule/output.png` | `c1cef7ca05c9` | `c1cef7ca05c9` | = |

## Canary blind spot (s15 rule — stated explicitly)

**The standing canary cannot see either change class.** No canary test calls
`BitmapData.copyPixels` with an alpha source, and **all four of its gradient
members** — `from_shumway/acid/acid-gradient-0`,
`regression/avm2_timeline_gradients`, `regression/avm2_timeline_stroke_gradient`,
`visual/simple_shapes/gradients/gradients` — are **static (recompiler-emitted)
ramps**, which neither P2 nor P3 touches. So `52/52 IDENTICAL` is a genuine
*non-leakage* result (it proves the runtime ramp change did not reach the
recompiler path, and that nothing else in the frame loop moved) but it is **not**
coverage of the patched code.

The patched paths are covered instead by the 18 rows in §4, and specifically by:

* P1 → `avm1/bitmap_data_copypixels` (image, flipped),
  `avm1/bitmap_data_thorough/copyPixels` (trace, the only other AVM1 caller of the
  alpha arm), `visual/bitmapdata_copypixels_with_alpha_oob` (AVM2 twin, tol 0).
* P2 → `avm2/graphics_gradients_nulls` (flipped), `avm2/graphics_gradients`,
  `avm2/blend_shader_luma_lighten`, `visual/filters/displacement_map`.
* P3 → `avm1/movieclip_begin_gradient_fill`, `avm1/movieclip_line_gradient_style`,
  `from_gnash/misc-ming.all/GradientFillTest`, `visual/drawing_api/fills_and_lines`,
  `visual/drawing_api/gradient_focal_point`.
* Anti-leak into static ramps → the four `visual/gradient_*` rows (which pass
  with **0.2 %–2.5 % slack**, the tightest controls in the corpus) plus the four
  canary gradient members. All eight byte-identical.

**Suggested addition to `render_canary_tests.txt`** (for the tooling agent, not
done here): `avm2/graphics_gradients_nulls` and `avm1/bitmap_data_copypixels` —
after these patches both are tier-1 (CI-passing) and they are the only canary
candidates that exercise a *runtime* gradient ramp and the copyPixels alpha arm.

## Trace-side sweep beyond the canary

The AVM1 ramp (P3) is read only at render time, but `GradientFillTest` *traces*
`getPixel` values, so a ramp change is trace-visible there. Corpus scan for AVM1
`beginGradientFill`/`lineGradientStyle` in trace-only tests found four more:
`from_gnash/actionscript.all/MovieClip-v5 … -v8`. **All four are already failing
in the s17 baseline** (`MovieClip-v6` 96.3 %, `-v7` 96.4 %, `-v8` 93.8 %, `-v5`
in the error table), so no pass→fail transition is available to them.
`GradientFillTest` is likewise already a trace `fail` (119/278 lines) and stayed
`fail`. No AVM1 trace test that currently passes touches a runtime gradient.

---

# 6. What would flip P3 to NO-GO

P3 is the only judgement call. It ships because (a) it makes AVM1 agree with
Ruffle, with the AVM2 twin, and with the recompiler's static emitter — all three
already truncate; (b) measured net band movement is **−51 −2 +2 = −51 channels**;
(c) the one passing comparison in its blast radius *gained* slack. It would flip
to NO-GO if a full CI run showed `from_gnash/misc-ming.all/GradientFillTest`
regressing (it is the only pass→fail candidate anywhere in the AVM1 gradient
family) — that is the completion mechanism to watch. Dropping
`w2-gfx-smalls-ramp-trunc-avm1.patch` costs nothing but the band gain; P1 and P2
are independent of it.
