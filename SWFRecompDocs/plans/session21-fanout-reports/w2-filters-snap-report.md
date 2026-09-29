# w2-filters-snap — session 21, wave 2 (productionize the filter-implied pixel snap)

Agent `w2-filters-snap` (was w1-filters-snap). Worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w2-filters-snap` (branch `s21-w2-filters-snap`,
based on master `43d0199c8`). No commits to master.

**Files delivered:**
- `SWFRecompDocs/plans/session21-fanout-reports/w2-filters-snap.patch`. It modifies
  existing files only: `SWFModernRuntime/src/libswf/tag.c`,
  `SWFModernRuntime/src/avm2/avm2_display.c` and `ruffle-tests/render_canary_tests.txt`.
  **No new files.**
- `SWFRecompDocs/plans/session21-fanout-reports/w2-filters-snap-report.md` (this file).
- A follow-up patch, `w2-filters-snap-2-depth0-text.patch`, is reported separately in
  §7 and has its own report file.

Applies to current master `cb31af254`: the source hunks apply cleanly (checked with
`git apply --check`, together with the depth-0 patch). The only conflict is the
expected EOF append in `render_canary_tests.txt`; take both blocks (`--3way`).

---

## 0. Verdict

**GO. +2 pixel flips, 0 regressions.**

| comparison | tol / max_outliers | before | after |
|---|---|---:|---:|
| **`visual/filters/blur_scales_with_screen`** | 2 / 0 | 30 440 | **0 → PASS** |
| **`visual/filters/drop_shadow_scales_with_screen`** | 2 / 0 | 400 | **0 → PASS** |
| `visual/filters/glow` | 2 / 0 | 24 992 | 2 719 |
| `visual/filters/glow_without_composite_source` | 3 / 0 | 24 919 | 2 977 |
| `visual/filters/drop_shadow` | 2 / 0 | 46 032 | 3 935 |
| `visual/filters/drop_shadow_angles` | 2 / 0 | 55 899 | 7 054 |
| `visual/filters/bevel` | 3 / 6 | 69 229 | 3 613 |
| `visual/filters/bevel_inner` | 4 / 18 | 48 134 | 5 650 |
| `visual/filters/bevel_outer` | 3 / 18 | 78 376 | 6 082 |
| `visual/filters/bevel_full` | 4 / 18 | 66 782 | 5 790 |
| `visual/filters/glow_with_alpha_strength` | 4 / 18 | 42 782 | 5 755 |
| `visual/filters/displacement_map` (two checks) | 20/72 · 32/160 | 25 712 · 20 749 | 1 436 · 1 215 |
| `from_shumway/acid/acid-filter` | 4 / 0 | 482 | 30 |
| `visual/filters/blur_size_grows` | 3 / 0 | 6 386 | **12 668 (band worsens; explained in §4)** |
| `visual/cache_as_bitmap/cab_mask_filters` | 4 / 0 | 612 | 612 (separate mechanism) |

The numbers were computed from the render-canary PNG captures against each test's
`test.toml` budgets. They reproduce the wave-1 prototype and the CI baseline
(`d6bcfa56c`) to the digit.

The graded run should re-check `blur_scales_with_screen`: it passes at max diff 2
against tolerance 2. The canary md5 A/B is the stable witness for it.

---

## 1. Patch scope (runtime only, self-localized)

**`tag.c`**
- New `static inline cab_snaps(obj)` returns `cache_as_bitmap || filter_type != 0`
  (Ruffle `recheck_cache_as_bitmap`).
- It is used at the five existing cab-snap gates: `cab_snap_delta`,
  `cab_snap_root_leaf`, the one-line `cab_snap_in_place` call in `compose_children`,
  and the root-leaf gate in each of `tagRerenderFrame` and `tagShowFrame`.
- The s17 "SCOPED DIVERGENCE" filter gate is removed. Its comment is rewritten to say
  why a source translation is exactly Ruffle's result: `draw_offset` is an integer, so
  the cache sits on the device grid. It also records that the s17 measurement snapped
  in stage pixels.
- `cab_snap_delta` now rounds on the **device** grid (`context->stage_scale`).
- `render_filtered_object`: the drop-shadow and bevel offsets are rounded the way
  Ruffle's NEAREST sampler rounds them, `floor(off + 0.5)` device px.

**`avm2_display.c` (`avm2_render_filtered` only)**
- The same device-grid snap for the `.filters` route. The bounds come from
  `bounds_with_transform(parent_world × own)`, and the snapped world feeds the capture,
  the displacement pass and the source redraws.
- The same nearest-offset rounding.

**`render_canary_tests.txt`** gets an EOF block, `tier=2` until a graded run confirms,
with two members: `visual/filters/drop_shadow_scales_with_screen` and
`visual/filters/blur_scales_with_screen`. They are the corpus's first passing image
rows on the AVM1 PlaceObject3 filter route, closing s18 §8.6's blind spot, and both
run under a 2× view, so they see the device-vs-stage grid.

The wave-1 A/B `getenv` switches are removed.

### Sibling overlap in `tag.c`
- **w2-px-a** (`compose_children`, ~l.3232, browser-only gate): my only
  `compose_children` hunk is a one-line change to the `cab_snap_in_place` call at
  master l.3311, about 80 lines away. No textual overlap. If their hunk grows past
  about l.3300, expect one trivial 3-way.
- **w2-px-b** (AVM1 EditText transformed-border branch plus clip-matrix storage): no
  overlap. My hunks are at l.3068–3120 (cab helpers), l.3160, l.3311, l.4151
  (`render_filtered_object`) and the two root-loop gate lines (~6642 / ~7574).

---

## 2. Canary rigour (md5 A/B; before = the same worktree with `git apply -R`)

**Standing set:** `render_canary.py` over `render_canary_tests.txt` — **51 tests, 89
comparisons: 86 IDENTICAL, 3 DIFFERS, all intended:**
- `visual/filters/blur_scales_with_screen`: fail → **pass**.
- `visual/filters/drop_shadow_scales_with_screen`: fail → **pass**.
- `visual/filters/drop_shadow`: fail → fail, 46 032 → 3 935. It is the standing set's
  PlaceObject3 filter member, so this move is the target mechanism.

No trace status changed, and nothing appeared, vanished or stopped rendering.

**Extra set:** 54 tests, 58 comparisons: my 21 wave-1 at-risk passing rows, the filter
family, and **every image-bearing `regression/` row** (13, including the
loaded-child `avm1_parent_child_*`, masks and `bitmap_pool_layer_cap`).
- **46 IDENTICAL, 12 DIFFERS.**
- The 12 are exactly the target rows: acid-filter, bevel, bevel_full, bevel_inner,
  bevel_outer, blur_size_grows, displacement_map, drop_shadow, drop_shadow_angles,
  glow, glow_with_alpha_strength, glow_without_composite_source.
- Every one of them fails in both arms (the moves are in §0). No image status change,
  no trace status change.

The at-risk rows are byte-identical. They were found by scanning every image-bearing
SWF for PlaceObject3 filters, an ABC `filters` string or an AVM1 `filters` string:
`glow_pass_scaling`, `blur_pass_scaling`,
`displacement_map_{scales_with_screen,through_filters,through_applyFilter}`,
`cab_mask_{alpha,transform,triangle}`, `contains_grown_filter`,
`avm2/{bitmap_subclass_properties, bitmapdata_copychannel, graphics_bitmap_fill,
pixelbender_effect_{BlurredFocus,smudge,tintype,twirl}, pixelbender_images}`,
`avm1/bitmapdata_applyfilter_colormatrix`, and the other failing filter rows
(`acid-filter-2`, `bitmapbuttons`, `cache_as_bitmap/edittext_*`,
`edittext_border_filters`, `bitmapdata_draw_filters`, `shader_as_mask`) plus all 13
regression rows.

Canary coverage of this change class: before this patch, the standing set's only
PlaceObject3-route filter member was `drop_shadow`, which could not show a pass. The
two new members pin both halves of the change (the device grid and the snap). Neither
half is visible to the old set's passing rows.

Local Dawn, `--mode=graphics`, sequential `-P 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`,
`--recompile` on the first leg. No-graphics mode was checked in wave 1: the change is
render-only and it compiles.

---

## 3. Mechanism (unchanged from `w1-filters-snap-report.md` §2)

Ruffle caches every filtered object (`should_cache = preference ||
!filters.is_empty()`) and blits the cache with `PixelSnapping::Always`. The net
effect is a translation of the subtree by `round(bmin_dev) − bmin_dev`, where `bmin`
is taken under the stage view matrix.

Ruffle's glow, shadow and bevel compose passes sample the blurred texture NEAREST at
a fractional offset (`glow.rs` / `bevel.rs` `get_sampler(false, false)`), which
rounds that offset.

---

## 4. Known band worsening: `blur_size_grows` 6 386 → 12 668 (0 flips either way)

The snap is right on this row. The halo's sub-pixel edge crossings match the golden
**exactly in x** after the snap; before, x was 0.25–0.9 px off. **In y, ours is about
+0.9 px low in both arms.** The row had been trading an x error against a y error.

Its owner is a pre-existing **vertical-only large-blur halo offset**. It is probably
even-width box-kernel centring or a y-flip in the vertical pass, and it is unclaimed
(§6 lead 2). The row was never flippable by this patch (max_outliers 0).

---

## 5. HOLD for the other brief rows — completion mechanisms

- **(A) Label text.** This is corrected by the coordinator and w2-noto-d1, and I
  diagnosed and fixed it (§7). The missing "50% / 100% / 200%" labels in
  bevel_inner/outer/full and glow_with_alpha_strength are **DefineText placed at
  DEPTH 0 inside a DefineSprite**. Every AVM1 render walk in `tag.c` starts at depth 1.
  It is not a default-font issue.
- **(B) Thin-stroke staircase ties.** 1 px circle strokes step on different rows than
  Ruffle's (lyon flattening / stroke edge rule), and the kernel area amplifies each
  tie. This owns glow, glow_wcs, drop_shadow, drop_shadow_angles, bevel, about 106 per
  displacement tile, and what remains on the four label rows after (A).
- **(C) `cab_mask_filters`.** Needs a compose-into-offscreen pipeline (the alpha-mask
  arm draws the masker's raw silhouette).

---

## 6. New unclaimed leads

1. **Promote** the two new canary members to tier 1 once the graded run confirms them.
2. **Vertical large-blur halo offset** (`blur_size_grows`, §4).
3. **`from_shumway/acid/acid-filter` is 30 outliers from a flip** (tol 4 / 0, max
   diff 6). Our halo is cut off at x = 518 (rows 104–110 and 144–150) where the golden
   keeps fading. It is a `[Blur, Blur]` chain, so suspect the "N blurs = one blur of
   quality N" folding when the radii differ. **Possible +1.**
4. **Stroke staircase parity (B)** is now the single owner of the filter family.
   Anyone pricing the stroke-tessellation arc has clean witnesses here.
5. **Nested AVM2 filtered objects** render unfiltered and unsnapped
   (`g_avm2_filter_active`). No known corpus row depends on this.

---

## 7. Follow-up: `w2-filters-snap-2-depth0-text.patch`

See `w2-filters-snap-2-depth0-text-report.md`. It is a separate patch in a separate
worktree (`.claude/worktrees/w2-filters-snap-2`, based on master `cb31af254`), with
its own canary A/B.
