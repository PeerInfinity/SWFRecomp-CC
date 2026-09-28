# w1-filters-snap — session 21, wave 1 (prototype in a throwaway worktree)

Agent `w1-filters-snap`. HEAD `263427d08`. **No main-tree source edits, no commits.**
Throwaway worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w1-filters-snap`
(branch `s21-filters-snap-proto`). Scratch:
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/95edbfc6-8c64-421c-a520-00c101a9b3ea/scratchpad/w1-filters-snap/`.

**Files delivered** (no new source files; the patch touches two existing files):
- `SWFRecompDocs/plans/session21-fanout-reports/w1-filters-snap-report.md` (this file)
- `SWFRecompDocs/plans/session21-fanout-reports/w1-filters-snap-prototype.patch`
  (`SWFModernRuntime/src/libswf/tag.c`, `SWFModernRuntime/src/avm2/avm2_display.c`)

---

## 0. Verdict first

**GO for productionizing: +2 pixel flips, 0 pass→fail across 21 at-risk passing rows,
and a 85–95 % band move on all nine of the brief's glow/drop-shadow/bevel/displacement
rows. The flips are NOT among the brief's ten rows.** The brief's ten still flip 0,
but the reason is no longer the snap. What is left in them is owned by three other
mechanisms (§4).

| comparison | tol / max_outliers | CI @d6bcfa56c | local BASE | **proto NEW** | verdict |
|---|---|---:|---:|---:|---|
| `visual/filters/blur_scales_with_screen` | 2 / 0 | 30 440 | 30 440 | **0** (max diff 2) | **FLIP** |
| `visual/filters/drop_shadow_scales_with_screen` | 0 (default) / 0 | 400 | 400 | **0** (max diff 0) | **FLIP** |
| `visual/filters/glow` | 2 / 0 | 24 992 | 24 992 | 2 719 | −89 %, no flip |
| `visual/filters/glow_without_composite_source` | 3 / 0 | 24 919 | 24 919 | 2 977 | −88 % |
| `visual/filters/drop_shadow` | 2 / 0 | 46 032 | 46 032 | 3 935 (snap only: 34 367) | −91 % |
| `visual/filters/drop_shadow_angles` | 2 / 0 | 55 899 | 55 899 | 7 054 | −87 % |
| `visual/filters/bevel` | 3 / 6 | 69 229 | 69 229 | 3 613 (snap only: 4 760) | −95 % |
| `visual/filters/bevel_inner` | 4 / 18 | 48 134 | 48 134 | 5 650 | −88 % |
| `visual/filters/bevel_outer` | 3 / 18 | 78 376 | 78 376 | 6 082 | −92 % |
| `visual/filters/bevel_full` | 4 / 18 | 66 782 | 66 782 | 5 790 | −91 % |
| `visual/filters/glow_with_alpha_strength` (not in brief) | 4 / 18 | 42 782 | 42 782 | 5 755 | −87 % |
| `visual/filters/displacement_map` check tol 32 | 32 / 160 | 20 749 | 20 749 | 1 215 | −94 % |
| `visual/filters/displacement_map` check tol 20 | 20 / 72 | 25 712 | 25 712 | 1 436 | −94 % |
| `from_shumway/acid/acid-filter` (not in brief) | 4 / 0 | 482 | 482 | **30** (max diff 6) | −94 %; now 30 from a flip (§5 lead 3) |
| `visual/cache_as_bitmap/cab_mask_filters` | 4 / 0 | 612 | 612 | 612 | unchanged: **a separate mechanism, confirmed** |
| `visual/filters/blur_size_grows` | 3 / 0 | 6 386 | 6 386 | **12 668** | **band WORSENS**. The snap is right, and it exposes a pre-existing vertical halo offset (§3.4) |
| `visual/filters/any_blur_scales_with_screen` | 2 / 0 | 4 884 | 4 884 | 4 884 | unchanged (gradient-filter disposition) |
| `visual/filters/color_matrix` | 0 / 0 | 6 | 6 | 6 | unchanged (integer bounds, so no snap) |
| `from_shumway/acid/acid-filter-2` | — / 0 | — | 2 986 | 2 986 | unchanged |

"Outliers" is the number the image checker reports (channels). BASE = the same binary
with the prototype switched off by env (`SWF_NO_FILTER_SNAP=1 SWF_NO_NEAREST_OFFSET=1`).
It reproduces the CI numbers to the digit on every row that has one, so local Dawn
equals CI on these rows. All runs were `--mode=graphics --images`, sequential, with
`SWFRECOMP_COMPILE_TIMEOUT=2400`. The trace half passes in both arms on every row.

**Net priced flips: `visual/filters/blur_scales_with_screen` and
`visual/filters/drop_shadow_scales_with_screen` (+2).** Fragility: `blur_scales_with_screen`
passes with max diff 2 at tolerance 2, so it sits on the edge and the CI image run must
confirm it. `drop_shadow_scales_with_screen` is exact (max diff 0).

---

## 1. Refutations (attacking the brief and the verdict of record)

1. **"Arithmetically unflippable" rested on a floor that has since moved.** s18 set
   the floor of the whole family at `color_matrix`'s 237 channels / 79 px, calling it
   "same artwork, integer placement". s18's own round-join fix later took that row to
   **6 channels**. It is also not the same artwork: its shape bounds are −200 twips
   (10 px stroke), against −10 for glow/drop_shadow. So the floor argument was stale
   by the time it was written into the playbook. The verdict still holds for the ten
   rows, but only because of §4's owners, not because of the snap.
2. **s17's "translating the source alone is a third thing, not an approximation of
   Ruffle, and it measurably hurts" is refuted.** Our AVM1 and AVM2 filter paths blur
   in a stage-sized, device-pixel-aligned layer. Ruffle's cache texture is offset from
   the device grid by an integer (`draw_offset` is `floor`ed), so translating the
   source by `round(bmin_dev) − bmin_dev` is algebraically the same computation. s17
   measured `blur_scales_with_screen` as 30 810 → 69 375 because it snapped in
   **stage** pixels on a **2× viewport**. Snapping in **device** pixels (Ruffle's
   bounds are taken under the stage view matrix: `render_bounds_with_transform(..,
   &context.stage.view_matrix())`) takes that same row to **0**.
3. **s18's `drop_shadow_scales_with_screen` diagnosis is refuted.** s18 put it down to
   the "fill-edge inclusion rule at 1 sample, owner w1-gfx-fill". It is the
   filter-implied snap, and the row goes 400 → 0 with no fill-rule change.
4. **s17/s18's `displacement_map` "owner = TestImage edge placement" is refuted.** The
   "no-map control tile" is itself a filtered object (`filters = [new
   DisplacementMapFilter()]`), so Ruffle caches and snaps it. With the snap, the
   control tile goes 2 956 → 106, the unfiltered r0c0 tile stays 0, and the whole row
   goes 20 749 → 1 215.
5. **"100 % of the residual is silhouette drift" was ~90 % right, and drop_shadow has a
   second mechanism.** Ruffle composites glow, shadow and bevel by sampling the blurred
   texture with a **NEAREST** sampler at a fractional offset (`glow.rs` / `bevel.rs`
   `get_sampler(false, false)`, `vertices_with_blur_offset`). The effective offset is
   therefore `floor(off + 0.5)` device px. Ours uses a LINEAR `filter_sampler` at the
   raw fractional offset. Porting the rounding takes `drop_shadow` 34 367 → 3 935 and
   `bevel` 4 760 → 3 613, and changes nothing on rows whose offsets are already integers.
6. **`cab_mask_filters` does not share the mechanism.** It is 612 → 612 in both arms.
   s17/s18's alpha-mask-arm diagnosis stands (the masker draws its raw silhouette;
   completion = a compose-into-offscreen pipeline).
7. **Pricing attack on myself.** The glow residual after the snap is **identical, up to
   an integer translation, across copies of the same object** (the TL and TR copies'
   top components sit at offset exactly (+5, +261) px, which is the difference of their
   snapped origins). That proves the phase now matches Ruffle's and the leftover is a
   property of the source raster, not of placement. So no further snap refinement
   (for example matching Ruffle's twip-integer bounds arithmetic) can buy anything on
   these rows. The snap arithmetic was checked by hand against the SWF for all four
   glow copies (bounds −10 twips + placements 741/5960/640/5700, 179/279/4090/4190), and
   the `x.5` ties round half away from zero in both C `round` and Rust `f64::round`.

---

## 2. Mechanism (Ruffle source, `~/CC/ruffle` @ `0dacba55f`)

- `core/src/display_object.rs::recheck_cache_as_bitmap`:
  `should_cache = preference || !filters.is_empty()`. Any filtered object is bitmap-cached.
- `render_base` (≈ l.983–1130): the cache origin is `bounds.x_min` of
  `render_bounds_with_transform(base_matrix, false, view_matrix)` in world/device twips,
  plus an integer `draw_offset = floor(filter_rect.x_min)`. The blit is at
  `tx + offset_x` with **`PixelSnapping::Always`**, which is
  `Twips::from_pixels(tx.to_pixels().round())` (`render/src/bitmap.rs:96`). Net effect:
  the whole subtree moves by `round(bmin_dev) − bmin_dev`. Our `tag.c::cab_snap_delta`
  (s17) already computes exactly this for explicit cacheAsBitmap.
- Filters are scaled by the stage view matrix (`filter.scale(view.a, view.d)`,
  distance `*= y`). The offsets are therefore device pixels, sampled NEAREST (above).

### The prototype (143-line patch; runtime only; self-localized)

1. `tag.c::cab_snap_delta`, `cab_snap_root_leaf`, `compose_children`, and both root
   display loops (`tagRerenderFrame`, `tagShowFrame`): snap when
   `cache_as_bitmap || filter_type != 0`. The s17 "SCOPED DIVERGENCE" filter gate is
   removed.
2. `cab_snap_delta`: round on the **device** grid (`context->stage_scale`), converting
   back to stage twips. This also changes explicit-cacheAsBitmap snapping at viewport
   scale ≠ 1, but no `cache_as_bitmap/*` image test has a `viewport_dimensions`, so it
   has no corpus exposure. It is Ruffle-correct.
3. `avm2_display.c::avm2_render_filtered`: the same snap for the AVM2 `.filters` route
   (the world bounds come from `bounds_with_transform(parent_world × own)`). The snapped
   `parent_world` feeds the offscreen render, the displacement pass and the
   draw-source-before/after renders.
4. Both routes: nearest-sampling rounding of the shadow/bevel offset (§1.5).

A/B switches `SWF_NO_FILTER_SNAP` and `SWF_NO_NEAREST_OFFSET` are in the patch for
measurement only. **Remove them when productionizing.**

---

## 3. Evidence

### 3.1 Snap vs nearest-offset attribution (NEW / SNAP-only / BASE)

`glow` 2 719 / 2 719 / 24 992 · `drop_shadow` **3 935 / 34 367** / 46 032 ·
`drop_shadow_angles` 7 054 / 7 054 / 55 899 · `bevel` 3 613 / 4 760 / 69 229 ·
`bevel_inner` 5 650 / 5 676 / 48 134 · `bevel_outer` 6 082 / 6 334 / 78 376 ·
`bevel_full` 5 790 / 5 924 / 66 782 · `glow_with_alpha_strength` 5 755 / 5 755 / 42 782 ·
`blur_scales_with_screen` 0 / 0 / 30 440 · `drop_shadow_scales_with_screen` 0 / 0 / 400 ·
`displacement_map` 1 215 / 1 215 / 20 749.

A stage-pixel snap (first prototype iteration, before item 2 above) left
`blur_scales_with_screen` at 69 497 and took `drop_shadow_scales_with_screen` from
400 to 1 592. Both rows have a 2× viewport, and the device-pixel grid is what flips them.

### 3.2 Regression sweep: every at-risk PASSING image row, NEW vs BASE

The blast radius was found by walking every image-bearing `test.swf` (zlib + LZMA)
for PlaceObject3 filter lists (recursing into DefineSprite), an ABC `filters` string,
or an AVM1 `filters` string. **All unchanged, all PASS in both arms, with identical
outliers and max diff:**
`visual/filters/{glow_pass_scaling, blur_pass_scaling, displacement_map_scales_with_screen,
displacement_map_through_filters, displacement_map_through_applyFilter}`,
`visual/cache_as_bitmap/{cab_mask_alpha, cab_mask_transform, cab_mask_triangle (196/200),
contains_grown_filter}`, `avm2/{bitmap_subclass_properties, bitmapdata_copychannel,
graphics_bitmap_fill (56/60), pixelbender_effect_{BlurredFocus,smudge,tintype,twirl},
pixelbender_images}`, `avm1/bitmapdata_applyfilter_colormatrix`, and the **regression
suite**: `regression/{avm2_parent_child_render (96/400), avm2_timeline_gradients,
avm2_timeline_stroke_gradient}` (`avm2_timeline_solid` SKIP, it has no expected image).
The first `BlurredFocus` NEW run returned no line (a transient under load average ~15).
A sequential re-run was PASS 0/1003, max diff 1, identical to BASE.

**Failing rows that did not move** (both arms): `acid-filter-2` 2 986,
`from_shumway/bitmapbuttons` 618 042, `cache_as_bitmap/edittext_{hscroll 96+960, scroll
566+570, selection 366+6783+373}`, `edittext/edittext_border_filters` 821,
`avm2/bitmapdata_draw_filters` 14 400, `blend_modes/shader_as_mask` 2 100.

Grading is by outlier count and max diff, not md5. For a prototype A/B these are
"identical on both sides". The production patch must still run `render_canary.py`.
No-graphics mode compiles and passes (`drop_shadow_scales_with_screen` trace). The
change is render-only.

### 3.3 Residual structure after the patch (§4 owners)

A component scan of NEW vs golden:
- `glow`: 112 small components, max |diff| 51. The biggest (114 channels) is the thin
  yellow circle stroke whose **staircase steps sit on different rows** from Ruffle's,
  with the pink glow following it. It is the same pattern in every copy (§1.7).
- `displacement_map` control tile: 39 components of about 1 px each (106 channels).
  These are the same stroke/edge ties.
- `bevel_inner/outer/full`, `glow_with_alpha_strength`: about **1 410 px of dark ink
  are missing** in ours (golden dark, ours light). That is **≈ 4 230 channels ≈ 74 %
  of each row's residual**. They are the "0% / 50% / …" label text (`with_default_font
  = true`), which we do not draw at all (see the crop at
  `<scratch>/crop_bevel_outer.png`).

### 3.4 `blur_size_grows` gets worse, and the snap is right anyway

The row is `[Blur 30, Glow blue 30]` on a sprite with bounds at (105.5, 40.5) px, which
is an exact tie. Ruffle's blit moves it by +0.5 in x and y. Sub-pixel halo edge
crossings at G = 230 along row 184 show **NEW matches the golden exactly in x**
(91.75 / 407.25 against 91.75 / 407.25; BASE is at 91.5 / 406.33). **In y, ours is
≈ +0.9 px low in both arms** (column 249: golden 25.71 / 341.29, NEW 26.63 / 342.38,
BASE 26.5 / 341.5). Rounding the tie down instead gives 12 176, so it is not a
tie-rule issue. So the row was passing its x error off against a y error, and a
pre-existing **vertical-only offset of the large-blur halo** owns the worsening.
The row is at max_outliers 0 and was never flippable by this change. It needs the
vertical-offset fix (§5 lead 2).

---

## 4. Why the brief's ten rows still flip 0 — completion mechanisms

| owner | rows | size of the owner |
|---|---|---|
| **A. Device-font label text is not drawn** (the `with_default_font` label TextFields render nothing) | bevel_inner, bevel_outer, bevel_full, glow_with_alpha_strength | ≈ 4 230 channels per row, ≈ 74 % of each residual. **Owner: this session's `w2-devicefont-a1`** (device-font outline arc). After A, these rows are about 1 400–1 850 channels against a budget of 18 |
| **B. Thin-stroke raster / flattening ties** (1 px-wide yellow/black circle strokes step on different rows or columns; each tie is amplified by the kernel area) | every row: glow 2 719, glow_wcs 2 977, drop_shadow 3 935, drop_shadow_angles 7 054, bevel 3 613, displacement_map ≈ 106 per tile × 7 | `hairline_edge_drift` / stroke-tessellation parity (lyon flattening + stroke edge rule). The only mechanism that can take these rows under budgets of 0–18 |
| **C. `cab_mask_filters`**: alpha-mask arm draws the masker's raw silhouette | cab_mask_filters | Compose-into-offscreen pipeline (unchanged from s17/s18) |

**HOLD for the ten rows: completion = A + B** (and C for `cab_mask_filters`). Band
moves are still worth taking with this patch because every other owner is now visible
without the snap noise.

---

## 5. New unclaimed leads

1. **Canary blind spot closes.** `drop_shadow_scales_with_screen` (AVM1 PlaceObject3
   DropShadow under a 2× view) and `blur_scales_with_screen` (nested
   cacheAsBitmap+Blur under 2×) become the **first passing AVM1 PlaceObject3-tag
   filter-route image rows**, which s18 §8.6 said had no witness. The productionizing
   agent should add both to `render_canary_tests.txt` as tier 1.
2. **Vertical-only large-blur halo offset** (≈ +0.9 px in y, exact in x) on
   `blur_size_grows`. It is probably even-width box-kernel centring or a y-flip in
   the vertical pass. It is cheap to probe with the crossings script
   (`<scratch>/ana.py` plus the inline crossing dump in §3.4) and owns that row's
   whole regression here.
3. **`from_shumway/acid/acid-filter` is 30 channels from a flip** (tol 4 / 0, max diff 6).
   The residual is two 15-channel runs where **our blur halo is cut off at x = 518**
   (rows 104–110 and 144–150; the golden keeps fading to 255 by x ≈ 526). It is a
   `[Blur, Blur]` chain, so suspect our "N blurs = one blur of quality N" folding when
   the two radii differ (support too short). This one is a possible +1.
4. **Stroke staircase parity (owner B)** now owns about 2.7 k–7 k channels on six
   filter rows, plus about 106 per displacement tile. Anyone briefing the
   hairline/stroke-tessellation arc should re-price it against these rows: they are
   clean witnesses now that the phase matches.
5. **Nested filtered objects in AVM2** render unfiltered and unsnapped
   (`g_avm2_filter_active`). Ruffle nests caches. No corpus row is known to depend on
   it.

---

## 6. Productionizing scope (for the wave-2 / coordinator)

- Apply `w1-filters-snap-prototype.patch`, **delete the two `getenv` A/B switches**,
  and rewrite the stale "SCOPED DIVERGENCE" comment in `cab_snap_delta`. It is
  refuted (§1.2) and should say why the device-grid snap is equivalent.
- `render_canary.py` capture/compare over `render_canary_tests.txt` (`--timeout 5400`),
  and add the two new tier-1 members (§5.1).
- CI: `images=true` graphics run to confirm the +2 (watch `blur_scales_with_screen`'s
  max diff 2 at tolerance 2) and the `blur_size_grows` band worsening (6 386 → ~12 668,
  expected and explained).
- Files: `SWFModernRuntime/src/libswf/tag.c` (cab_snap_* helpers, compose_children, two
  root loops, render_filtered_object offset) and
  `SWFModernRuntime/src/avm2/avm2_display.c` (`avm2_render_filtered` only). Sibling
  overlap: `w2-caret-multiline` edits `avm2_display.c` near the selection highlight,
  which is a different region and should not conflict.
