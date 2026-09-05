# w1-gfx-filters — session 18, wave 1 (PIXEL axis, read-only diagnosis)

Agent `w1-gfx-filters`. Main tree, HEAD `8f68a5fea`. **No source edits, no commits.**
Scratch: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-gfx-filters/`
Board of record: `wave0-image-board.md` + `<scratch>/image_triage.json`, images run
`33857494837` at `659153865`. Prior diagnosis read first (and not re-derived):
`session16-fanout-reports/w2-gfx-filters-report.md`,
`session17-fanout-reports/w2-gfx-filters-cut2-report.md`,
`session17-fanout-reports/w2-gfx-cab-mask-stencil-report.md`,
`session17-fanout-reports/w2-gfx-cab-pixelsnap-report.md`.

---

## 0. Verdicts first

| # | comparison | excess / budget | verdict | mechanism |
|---|---|---:|---|---|
| 1 | `visual/filters/any_blur_scales_with_screen` | 4884 / **0** | **GO — +1 flip, and it is the ONLY flip in this family** | Ruffle renders **nothing** for `GradientGlowFilter` / `GradientBevelFilter` on a display object; we render an approximation. 4 of 13 cells. The other 9 cells (incl. 8 *filtered* ones) are **byte-exact**. Flip requires a deliberate Ruffle-compat tweak — see §2, incl. the argument against |
| 2 | `visual/filters/blur_size_grows` | 86708 / **0** | **NO-GO as a flip; GO as a −99.8 % band move** | **The recompiler renders only the FIRST filter of a PlaceObject3 filter list** (`SWFRecomp/src/swf.cpp`, `if (parsed_filter_type == 0)` ×7 + a single `tagSetFilter` emission). This SWF is `[Blur(30,30), Glow(blue,30,30)]`; the blue glow is dropped. 41 062 of 42 596 significant pixels are exactly that. Residual floor ≈ 50 px of crisp-circle drift at `max_outliers = 0` |
| 3 | `visual/filters/{glow, glow_without_composite_source, drop_shadow, drop_shadow_angles, bevel, bevel_inner, bevel_full, bevel_outer}` (8 cmps) | 24 919 … 78 358 / 0–18 | **NO-GO — and the brief's premise is REFUTED** | **Our blur / glow / bevel / drop-shadow filter math is already byte-exact against Ruffle's goldens** (§3.1: 8 filtered comparisons at 0–1 LSB). 100 % of this family's residual is the **source silhouette** rasterised on a different pixel grid, amplified by the kernel area. Leading cause: the **filter-implied `cacheAsBitmap` pixel snap** we do not do (§3.3). Band-move lead only — the floor is another owner's row |
| 4 | `visual/filters/displacement_map` | 20 589 / 160 | **NO-GO — s17's finding VERIFIED to the digit** | Per-tile floor is `TestImage` content, not displacement: the **no-map control tile is 2956** and every displaced tile is 2131–3989 (§4). Owner = whoever fixes `TestImage`'s edge placement |
| 5 | `visual/cache_as_bitmap/cab_mask_filters` | 612 / **0** | **NO-GO — s17's finding VERIFIED exactly** | 612 = 153 × 4, entirely in the four `maskeeCab = true` cells; the other four cells are **byte-exact** (§5). Completion mechanism unchanged: a compose-into-offscreen pipeline |
| 6 | `visual/edittext/edittext_border_filters` (filter half) | 810 / 17 | **HOLD — new named mechanism, flip uncertain** | **An EditText is never drawn by `render_single_object`**, so `render_filtered_object` captures an EMPTY layer and the textfield pass then draws the field crisp: PlaceObject3 filters on a `DefineEditText` are structurally a no-op (§6) |

**Net priced for wave 2: +1 flip (`any_blur_scales_with_screen`), and it is a
Ruffle-compat tweak I recommend the coordinator think twice about.** Everything
else in this family is band moves against `max_outliers` budgets of 0–18.

### Refutations (rule 1 — attacking my own brief)

1. **The brief's shared-mechanism hypothesis list for the glow/drop-shadow/bevel
   family is wrong on every entry.** "kernel shape? colour/alpha premultiply?
   `strength` semantics? `knockout`/`inner` compositing? blur pass count =
   `quality`?" — all five are already **byte-exact**, proved in §3.1 by eight
   filtered comparisons inside `any_blur_scales_with_screen` that match the
   golden to 0–1 LSB, across Blur, Glow, Bevel and DropShadow, at two blur radii,
   under a 2× stage view scale. There is no filter-math bug in this family.
2. **This family cannot flip at all.** Not "hard" — arithmetically out of reach:
   `glow` 2156 px, `drop_shadow` 2447, `drop_shadow_angles` 3922, `bevel` 2025,
   `bevel_inner` 8091 pixels sit at |diff| ≥ 65 (a whole-pixel colour flip)
   against `max_outliers` of 0–18. A perfect filter would still fail every row.
   Diff-line yield here is ~380 k channels and **flip yield is zero**.
3. **`blur_size_grows` is not a filter-accuracy row, it is a *recompiler
   coverage* row** — 86 708 of its outliers are one missing filter. That is the
   biggest single mechanism I found, and it still cannot flip the row.
4. **s17's "the filter gate measurably hurts" is not evidence against the snap
   lead for THIS family.** `cab_snap_delta` bails on `!obj->cache_as_bitmap`
   *before* it reaches the filter gate, and `glow` / `drop_shadow` / `bevel*`
   carry **no** PlaceObject3 BitmapCache flag. s17's ungated A/B therefore never
   touched a single row of this family; the two rows it did move
   (`blur_scales_with_screen`, `blur_size_grows`) have a different residual
   mechanism (§3.4). The snap has never been tested here.
5. **`any_blur_scales_with_screen` is not a "halo_penumbra" row.** The board's
   cluster label is a symptom of four missing objects; there is no penumbra
   problem. (`label-trap` again: rows name symptoms, not owners.)

---

## 1. Method / evidence base

All numbers are computed from the published CI artefacts — `output.actual.png`
from `origin/ruffle-image-results` (extract at `<scratch>/image-results/`) against
the in-tree `output.expected.png`, using each test's own `test.toml` tolerance.
No local renders were needed to reach any verdict: every mechanism below is
decided by structure in the published PNGs plus source reading. Tools written
for this (all in my scratch dir, throwaway):

* `swffilt.py` — SWF tag walker that dumps PlaceObject2/3 **filter lists** with
  fully decoded parameters (fixed-16/fixed-8, flag bits). *Correct SWF filter
  IDs are `0 DropShadow, 1 Blur, 2 Glow, 3 Bevel, 4 GradientGlow, 5 Convolution,
  6 ColorMatrix, 7 GradientBevel`* — note 5/6/7 are **not** the order a naive
  reading of the AS3 class list suggests.
* `bounds.py` — placement matrices + world-pixel bounds of a placed shape.
* `scan.py` — corpus-wide scan for multi-filter and gradient-filter placements
  (recurses into `DefineSprite`).
* `an.py` / `hist.py` / `prof.py` / `shift.py` / `crop.py` — diff statistics,
  |diff| histograms, scanline dumps, per-region integer-shift search, side-by-side
  magnified crops.

---

## 2. `any_blur_scales_with_screen` — the family's only flip

**Test**: 13 copies of one 10×10 square on an 80×80 stage rendered into a
160×160 viewport (`viewport_dimensions` 160×160 ⇒ stage scale 2). One copy is
unfiltered; the other twelve carry one filter each, in six kinds × two blur
radii. `tolerance = 2`, `max_outliers = 0`, `quality = "high"`.

### 2.1 Per-cell exact-mismatch (channels differing by ≥ 1, whole image = 4895)

| cell | filter | mismatching channels | max |
|---|---|---:|---:|
| d1 | **unfiltered** | **0** | 0 |
| d2 | Blur(1) | **0** | 0 |
| d3 | Blur(2) | 6 | **1** |
| d6 | Glow(1) | **0** | 0 |
| d7 | Glow(2) | 2 | **1** |
| d10 | Bevel(1) | **0** | 0 |
| d11 | Bevel(2) | 2 | **1** |
| d12 | DropShadow(1) | **0** | 0 |
| d13 | DropShadow(2) | 1 | **1** |
| d4 | **GradientBevel(1)** | **1200** | 255 |
| d5 | **GradientBevel(2)** | **1200** | 255 |
| d8 | **GradientGlow(1)** | **1200** | 255 |
| d9 | **GradientGlow(2)** | **1284** | 255 |

`4884 excess = 4800 + 84`, i.e. **the entire failure is the four gradient
cells**. In each of them the golden is **blank white** and we draw the square.

### 2.2 Mechanism

Ruffle's wgpu `Filters::apply` (`render/wgpu/src/filters.rs:278-299`) has no
implementation for `GradientGlowFilter` / `GradientBevelFilter` / `Convolution`
— it `warn!`s and returns `None`. Its own code then falls back to an identity
colour-matrix blit, so on paper the object should render *unfiltered*; the
golden says otherwise (blank). I could not reconcile that from the source in
`~/CC/ruffle` (single-commit clone, no history to bisect). **The golden is the
oracle and the golden is blank** — that is what grades us, and it is stable
(`from_shumway/avm1/filters`, `avm1/bitmap_filters`, `avm2/gradient_*_filter`
all carry gradient filters and none of them has an image comparison, so this is
the corpus's only witness).

Our side (`SWFRecomp/src/swf.cpp`): a `GradientGlowFilter` is mapped to
`parsed_filter_type = 3` (glow) using the **last** gradient stop's colour, and
`GradientBevel` likewise to a bevel — an approximation that renders something
Flash-plausible. The AVM2 arm (`avm2_filter_renderable`) does not know the
gradient kinds at all and renders the object unfiltered.

### 2.3 Pricing, and the argument against taking it

* **Flip cost**: make a `GradientGlow`/`GradientBevel`-filtered display object
  render **nothing**. Everything else in the row is already exact, so the row
  goes 4884 → **0** and passes at `tolerance 2 / max_outliers 0`.
* **Blast radius**: exactly **one** graded image comparison corpus-wide. Scanned
  every `test.swf` (`scan.py`): the only other SWFs with gradient filters are
  `avm2/gradient_glow_filter`, `avm2/gradient_bevel_filter`, `avm1/bitmap_filters`,
  `from_shumway/avm1/filters` — **none of the four has an `image_comparisons`
  block**, and all four are `.filters` *reflection* tests, which must keep
  reading the gradient data back (the recompiler's separate `all_filters[]`
  array already owns that and would not be touched).
* **Against**: this is deliberately hiding content Flash draws, to match a
  Ruffle rendering gap, in a project whose stated purpose is running real games.
  A game using `GradientGlowFilter` would lose the object.
* **My recommendation**: **do not implement it as a render change.** Instead
  **disposition the row** as a Ruffle-vs-Flash image-axis divergence (the
  measured facts are complete enough for a docs-only entry), and leave the
  approximation in place. If the coordinator wants the point, the change is
  small and self-contained (one clause in `render_filtered_object` plus a
  `filter_type` sentinel from the recompiler) — but it belongs in
  `RUFFLE_COMPAT_TWEAKS.md`, not in the runtime's correctness story.

---

## 3. The glow / drop-shadow / bevel family (8 comparisons) — refuted as a filter bug

### 3.1 The filter math is already exact

§2.1 is the proof: Blur, Glow, Bevel and DropShadow each land at **0 or 1 LSB**
against the golden — at blur 1 and blur 2, under a 2× stage view matrix (so
`filter.scale(stage.a, stage.d)` and the `(blur−1)·scale+1` kernel rule are
covered too), through the same `renderer_run_blur` / `renderer_compose_filter`
code path these eight rows use. Independent corroboration from the failing rows
themselves: in `glow` (blurX = blurY = 5, 1 pass) **both** images quantise the
glow alpha to exact multiples of **1/25** — the 5×5 box kernel's own step — and
our step values (0.04, 0.08, …, 0.20) are Ruffle's values. Nothing about kernel
shape, premultiplication, `strength`, `knockout`/`inner` compositing or the pass
count is wrong.

### 3.2 What the residual actually is

The diffs sit **on the source silhouette and its blur halo**, and are the
signature of the *source* being rasterised one pixel differently, not of the
filter:

* `glow`: 6.3 % of source-ink pixels differ (1415 of 22 345). Scanline dumps
  show the classic pattern — the knockout quadrant's "hole" (= the silhouette)
  is at x = 327 in the golden and x = 326 in ours, with the surrounding glow ramp
  correct on both sides of it.
* `missing_ink ≈ extra_ink` on every row (glow .063/.063, drop_shadow .056/.055,
  bevel .007/.007) — jitter, not a translation. Whole-image integer-shift search
  gains ≤ 15 % at (0, +1) and never resolves it: a **sub-pixel re-phase is
  invisible to an integer-shift probe** (s17's standing lesson, confirmed again).
* The |diff| histograms fall out of the same model exactly. `glow` (blur 5,
  kernel area 25): **94.5 % of pixels are byte-exact, nothing at all in the 2–8
  band, and the mass starts at 9–16** — because one flipped source sample is
  worth 255/25 ≈ 10.2 levels. `bevel` (blur 10, kernel area 100): the mass moves
  to **1–4** (27 866 + 18 410 + 13 120 + 7386 pixels) because one flipped source
  sample is now worth 2.55 levels, and 1035 saturated pixels × ~100 kernel cells
  ≈ 66 k small-diff pixels — measured 66 782. The two histograms are the same
  phenomenon at two kernel areas.
* Alpha is byte-identical everywhere on all four bevel rows (but every one of
  these images is fully opaque, so that is not independent evidence).

### 3.3 Why the silhouette drifts — the filter-implied pixel snap

Ruffle forces `is_bitmap_cached()` for any object with a non-empty filter list,
renders it into a bounds-sized cache texture, and blits it back with
**`PixelSnapping::Always`** (`core/src/display_object.rs:1113`, comment
"cacheAsBitmap forces pixel snapping"). Working the algebra through
`display_object.rs:1055-1115`: the content is drawn into the cache with
`matrix.tx` replaced by `-offset_x` where `offset_x = bounds.x_min − tx +
draw_offset.x` and `draw_offset` is an integer, then blitted at an integer
position. So **Ruffle's rasterisation phase for a filtered object is
`frac(u − local_min)` — independent of where the object is placed** — while ours
is `frac(tx + u)`. The two agree **iff the object's world bounds minimum is an
integer device pixel**.

That prediction is confirmed on three independent tests with no free parameters:

| test | world bounds min | filter route | result |
|---|---|---|---|
| `any_blur_scales_with_screen` | 20.0 / 20.0 px → device 40.0 (**integer**) | full offscreen blur/glow/bevel/shadow | **byte-exact ×8** |
| `visual/filters/color_matrix` | placement (110.0, 90.0) px (**integer**) — *same artwork as `glow`* | ColorMatrix | 79 px / 237 channels |
| `visual/filters/glow` | placement (37.05, 8.95) / (298.0, 13.95) / (32.0, 204.5) / (285.0, 209.5) px (**fractional**) — same artwork | glow | **12 030 px / 24 992 channels** |

Same drawing, same renderer, ×150 more diff when the bounds minimum is
fractional.

**The machinery to fix it already exists and is gated off twice.**
`tag.c::cab_snap_delta` (s17) computes exactly `round(bounds_min_px) −
bounds_min_px` and the three `cab_snap_*` helpers already rewrite a root leaf's,
a container's and a composed child's matrix. Two lines block this family:
`if (obj == NULL || !obj->cache_as_bitmap) return 0;` (Ruffle's implied cache
means `|| obj->filter_type != 0` belongs there) and the explicit
`if (obj->filter_type != 0) return 0;` scoped divergence.

### 3.4 …and why I still do not price it as a wave-2 patch

* **No flip is reachable.** Even a perfect phase match leaves the artwork's own
  floor, which the integer-placement control (`color_matrix`, same artwork)
  measures at **237 channels / 79 px** — already over every one of these rows'
  `max_outliers` (0, 0, 0, 0, 6, 18, 18, 18). The band move could be large
  (`glow` 24 992 → order 500) and scores nothing.
* **The route has no canary.** Not one `visual/filters/*` image comparison on the
  AVM1 PlaceObject3-tag route currently PASSES (`blur_fractional`,
  `blur_pass_scaling`, `blur_quality` are the CPU `applyFilter` route;
  `glow_pass_scaling` and the two displacement rows are the AVM2 `.filters`
  route). A snap patch on this route would ship with **zero passing witnesses**.
* **It can go the wrong way on a row that is not mine.**
  `visual/filters/blur_scales_with_screen` (30 810, max |diff| **40** — a smooth
  blur-profile residual, not silhouette drift; w1-gfx-fill's row) got **+125 %
  worse** in s17's ungated A/B. Any snap patch must A/B that row explicitly.
* Correct board wording: **"filter-implied cacheAsBitmap pixel snap — band move
  only, ~7 rows, 0 flips, no canary, must A/B `blur_scales_with_screen`."**

---

## 4. `displacement_map` — s17 verified, to the digit

Per-tile outliers on the current CI actual (tile grid 2 × 4 of 250 × 250,
tolerance 32 = the row's own aarch64 check, `max_outliers` 160):

| tile | content | > 32 | > 20 |
|---|---|---:|---:|
| r0c0 | the unfiltered 200×200 gradient (= the map itself) | **0** (max |diff| **1**) | 0 |
| r0c1 | `new DisplacementMapFilter()` — **no map, no pass: the control** | **2956** | 2968 |
| r1c0 | CLAMP | 3989 | 6039 |
| r1c1 | WRAP | 2702 | 3092 |
| r2c0 | COLOR + mapPoint | 3074 | 4064 |
| r2c1 | IGNORE + negative mapPoint | 2131 | 2365 |
| r3c0 | componentX = 0 | 3391 | 4372 |
| r3c1 | componentY = 0 | 2506 | 2812 |
| | **total** | **20 749** | 25 712 |

s17 reported the control tile at **2956 before and after** its patch — it is
still exactly 2956, and every displaced tile is on that same floor (2131–3989).
**The brief's "verify" is discharged: the residual is `TestImage` content, not
displacement.** Needs a 130× reduction against `max_outliers = 160`; no
displacement work can reach it. Owner: `TestImage` edge placement
(`hairline_edge_drift` / fill-edge rule).

---

## 5. `cab_mask_filters` — s17 verified exactly

80×40, eight 20×20 cells, `tolerance 4`, `max_outliers 0`:

```
        maskeeCab=F   maskeeCab=T
 blur       0            153        (max |diff| 179)
 shadow     0            153        (max |diff| 255)
 blur       0            153
 shadow     0            153        ->  612 total
```

Byte-exact in the four `maskeeCab = false` cells; the entire 612 is the alpha-mask
arm rendering the masker's **raw silhouette** instead of its filtered self.
Completion mechanism is unchanged from `w2-gfx-cab-mask-stencil-report.md` §5 and
§8: **a compose-into-offscreen pipeline** (a `compose_pipeline` variant whose
colour target is `filter_tex_b`). That primitive is now named by three separate
parked items (this row, filters cut 2 §8, cab-pixelsnap §8) and remains the
highest-leverage renderer work left in the family — but it buys **0 flips** here
(`max_outliers = 0`, best partial depth ≈ 350).

---

## 6. `edittext_border_filters` — new mechanism (my half)

**An EditText is structurally unreachable from the filter arm.** `tag.c`'s
`render_single_object` has, in `case CHAR_TYPE_TEXT`:

```c
if (ng_getCharTextfieldIdx(obj->char_id) >= 0) break;   // ~tag.c:3795
```

— a `DefineEditText` is drawn by the *separate* textfield pass
(`actionIterateTextFields` + `actionIterateTextFieldGlyphs`, `tag.c:6265`,
`:6632`, `:7681`) that runs **after** the display loop. So
`render_filtered_object` opens the offscreen layer, calls `render_single_object`,
gets **nothing**, blurs nothing, composites nothing, and the field is then drawn
crisp and unfiltered by the textfield pass. Confirmed visually: all six boxes in
our output are plain crisp black borders; the golden shows a blurred grey box,
a magenta drop shadow and a magenta glow.

Per-box outliers (`tolerance 32`, `max_outliers 17`, total 827):

| box | filter | row 1 | row 2 |
|---|---|---:|---:|
| 1 | DropShadow(1,1, angle π, dist 2, magenta) | 22 | 25 |
| 2 | **Blur(2,2)** | **342** | **348** |
| 3 | Glow(2,2, magenta) | 43 | 47 |

**HOLD, not GO**: the fix (route the textfield pass — or at least the field's
border/background/glyph draws — through the filter capture for that entry) is
real runtime work, and the row needs **all three** filters right to get under 17.
The border-rasterisation half of this row is w1-gfx-text's; the two halves have
to land together to flip it. Completion mechanism: a per-entry textfield render
hook callable from inside `render_filtered_object`'s offscreen pass.

---

## 7. `blur_size_grows` and the multi-filter chain (biggest single mechanism)

`SWFRecomp/src/swf.cpp` parses a PlaceObject3 FILTERLIST into **two** places: a
16-entry `all_filters[]` array (used only for the `mc.filters` *reflection*) and
a single set of `parsed_filter_*` scalars for rendering. Every kind's arm is
guarded by `if (parsed_filter_type == 0)` (seven sites: :4064, :4100, :4127,
:4169, :4226, :4301, :4424) and exactly one `tagSetFilter` is emitted per
placement (:4823 root, :6243 sprite). The runtime side matches — `DisplayObject`
has scalar `filter_type` / `filter_blur_x` / … and `render_filtered_object`
renders one filter. **The first filter in the list wins; the rest are silently
dropped.**

`blur_size_grows` is `[Blur(30,30,1 pass), Glow(0x0000FF, 30,30, strength 1,
compositeSource, 1 pass)]` on depth 1, plus an unfiltered copy of the same
circle on depth 3. We render the blur and drop the blue glow — which is exactly
what the images show (the golden's halo is purple, ours is pink):

* 42 596 pixels are significant at `tolerance 3`; **41 062 of them differ only
  in R and G with |ΔB| ≤ 3** — the precise signature of a missing blue glow over
  white. Mean ΔR = +18.0, ΔG = +17.9, ΔB = −0.1.
* The crisp red circle (depth 3, unfiltered, snapped by s17's cab patch) is
  almost exact: 4486 vs 4472 saturated-red pixels, **XOR = 50 px**.

So fixing the chain takes this row from 86 708 to roughly the crisp-circle floor
(~100–200 channels) — a −99.8 % band move that **still cannot flip**
(`max_outliers = 0`).

**Corpus reach of the chain limitation** (`scan.py` over every `test.swf`;
124 filtered placements found, 64 files unparsed — LZMA `ZWS` and a few odd
headers — so this is a lower bound):

| SWF | filter list | image-graded? |
|---|---|---|
| `visual/filters/blur_size_grows` | Blur, Glow | **yes**, 86 708 |
| `from_shumway/acid/acid-filter-2` | Glow, Blur | **yes**, 16 764 (unclaimed, §8) |
| `from_shumway/acid/acid-filter` | Blur, Blur | **yes**, 482 (unclaimed, §8) |
| `from_shumway/avm1/filters` | DropShadow, Blur, Glow, Bevel, GradientGlow, GradientBevel, ColorMatrix | no image comparison |
| `avm2/{bevel,glow,drop_shadow,blur,color_matrix,gradient_glow,gradient_bevel}_filter` | 2–3 of one kind | no image comparison |

Three graded rows, none of which can flip on this alone. The change is cheap and
correctness-positive for real content (a chained blur+glow is common in games),
so it is worth doing on its own merits — but it must be priced as **0 flips**.

---

## 8. New unclaimed leads

1. **`visual/filters/drop_shadow_scales_with_screen` — 400 channels / 200 px,
   `max_outliers = 0`, the closest near-pass in the whole filters family, and it
   is NOT a filter bug.** The entire diff is two 100-px diagonal hairlines where
   our fill is exactly one pixel wider than Ruffle's (`act (255,0,0)` /
   `exp (255,255,255)`, with both neighbours identical on both sides). This is
   the fill-edge inclusion rule at 1 sample — the same half-open/closed question
   `w2-gfx-cab-pixelsnap-report.md` §8 names for `scroll_rect`'s single pixel and
   `avm2/displayobject_opaque_background`'s ten circle-edge pixels. **Owner:
   whoever owns the tessellator's edge rule (w1-gfx-fill), not filters.** Three
   rows now converge on it; it is the cheapest remaining "one rule, several
   flips" candidate I saw.
2. **`from_shumway/acid/acid-filter-2` — 16 764, `max_outliers = 0`, max |diff|
   only 122, unassigned in this fan-out.** It is a `[Glow, Blur]` **chain**, so
   §7 reaches it directly; worth re-measuring after any chain fix.
3. **`from_shumway/acid/acid-filter` — 482, `max_outliers = 0`**, s16's
   "coin-flip watch". It is a `[Blur, Blur]` chain (we apply one). 236 pixels;
   the closest thing to a flip in the shumway acid filter pair.
4. **`visual/filters/glow_with_alpha_strength` — 42 764, `max_outliers = 18`,
   unassigned.** Not diagnosed here; same 900×800 canvas and same authoring
   shape as `bevel_inner`/`bevel_outer`, so §3 almost certainly applies, but I
   did not measure it.
5. **`avm2/bitmapdata_draw_filters` — 14 400, the board's entire
   `global_color_shift` cluster (prior 1.00), unassigned.** `BitmapData.draw`
   with a filter list; a uniform colour shift is a very different (and usually
   cheap) signature from everything in this report.
6. **Canary blind spot, for whoever takes a wave-2 patch on the AVM1
   PlaceObject3-tag filter route: there is no passing image comparison on that
   route anywhere in the corpus.** `render_canary_tests.txt`'s filter members
   (`glow_pass_scaling`, `displacement_map_through_applyFilter`,
   `bitmapdata_applyfilter_colormatrix`) are all on the AVM2 `.filters` or CPU
   `applyFilter` routes. The nearest thing to a witness is
   `any_blur_scales_with_screen`'s nine byte-exact cells — **if §2 is ever taken,
   that row becomes the route's first tier-1 canary member and should be added.**
7. **SWF filter-ID trap for the next agent**: `5 = Convolution`, `6 = ColorMatrix`,
   `7 = GradientBevel`. Reading them in AS3 class order (GradientBevel = 5)
   silently mis-parses `visual/filters/any_blur_scales_with_screen` and
   `from_shumway/avm1/filters`.

---

## 9. Board corrections requested

1. `wave0-image-board.md` top-40 rows 33–40 (`cab_mask_filters`,
   `displacement_map`, `glow_without_composite_source`, `glow`, `drop_shadow`,
   `bevel_inner`, `drop_shadow_angles`, `bevel_full`) plus `bevel`, `bevel_outer`,
   `blur_size_grows`: mark **NO-FLIP, band-move only** — each is 2 000–8 000
   saturated pixels against `max_outliers` 0–18.
2. `any_blur_scales_with_screen`'s cluster label `halo_penumbra` → **"Ruffle
   renders nothing for gradient filters"**; it is the family's only flip and it
   is a disposition candidate, not a rendering bug.
3. `graphics-fanout-playbook.md`: add the standing fact **"our Blur / Glow /
   Bevel / DropShadow filter shaders are byte-exact against Ruffle's goldens
   (`any_blur_scales_with_screen`, 8 comparisons, 0–1 LSB)"** so no future
   session re-opens filter *math* for this family.
4. Add the standing mechanism **"filter-implied cacheAsBitmap pixel snap"**
   (§3.3) with its two gate lines, its confirming triple
   (`any_blur_scales_with_screen` integer/exact, `color_matrix` integer/79 px,
   `glow` fractional/12 030 px), and its honest price: band move, 0 flips, no
   canary, must A/B `blur_scales_with_screen`.
5. Add the standing mechanism **"only the FIRST filter of a PlaceObject3 filter
   list is rendered"** (§7) with its three graded rows.
6. Add the standing mechanism **"PlaceObject3 filters on a `DefineEditText` are a
   no-op"** (§6).
7. `w2-gfx-cab-pixelsnap-report.md` §8's "the filter gate … measured, do not":
   annotate that the measurement covered only the two rows carrying an explicit
   BitmapCache flag, and that the eight-row glow/drop-shadow/bevel family was
   never in that A/B because `cab_snap_delta` bails on `!cache_as_bitmap` first.
