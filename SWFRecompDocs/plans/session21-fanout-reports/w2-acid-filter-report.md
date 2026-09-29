# w2-acid-filter — session 21, wave 2

Agent `w2-acid-filter`. Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w2-acid-filter`
(branch `s21-w2-acid-filter`, based on master `b57ecb2f3`). No commits.

**Files delivered:**
- `SWFRecompDocs/plans/session21-fanout-reports/w2-acid-filter.patch`. It modifies
  existing files only: `SWFModernRuntime/include/rendering/{render_webgpu.h,renderer.h}`,
  `SWFModernRuntime/src/rendering/render_webgpu.c`, `SWFModernRuntime/src/libswf/tag.c`
  and `SWFModernRuntime/src/avm2/avm2_display.c`. **No new files.**
- this report.

The patch applies cleanly to current master `b445cba9d` (checked with
`git apply --check` on a `git archive` export).

---

## 0. Verdict: GO. +1 pixel flip, 0 regressions, plus the stretch lead closed as a band move

| comparison | checks (tol / max) | before | after |
|---|---|---:|---:|
| **`from_shumway/acid/acid-filter`** | **one check**: 4 / 0 | 30 (max diff 6) | **0 (max diff 3) → PASS** |
| `visual/filters/blur_size_grows` | one check: 3 / 0 | 12 668 | **546** (−96 %) |
| `visual/filters/drop_shadow_angles` | one check: 2 / 0 | 7 054 | 6 934 |

Under the c61f6ebe5 all-checks rule, acid-filter's `test.toml` has exactly one
`[image_comparisons.output]` check (tolerance 4, max_outliers 0). The flip clears it
with max diff 3.

---

## 1. Mechanism: a premise refuted, a different one found

**The brief's suspect is wrong: acid-filter is not a chain-folding problem.** The
row's residual comes from depth 23, which is a **single DropShadow** (blur 30×30,
3 passes, angle π, distance 32) on a 32 px square at x 495–527. Its shadow is thrown
32 px left, and a shadow at x reads the blurred layer at x + 32.

Our filter layer is **stage-sized** (550 px). The blur's right tail past x = 550 was
never stored, so every shadow pixel at x ≥ 550 − 32 = **518** read nothing. That is
exactly the cut-off at x = 518, in both halo bands (rows 104–110 and 144–150).
Ruffle's cache texture is object-sized, grown by `calculate_dest_rect`, so its tail
exists.

**The fix folds the shadow's whole-pixel offset INTO the blur.** A new one-shot
`renderer_set_blur_shift(ctx, sx, sy)` makes the next `run_blur` compute
`blur(x + shift)`: the first H pass shifts in x and the first V pass shifts in y. A
shift commutes with box passes, and a whole-texel move keeps the paired linear taps
on texel boundaries, so the arithmetic is otherwise untouched. The shift reads the
**capture**, whose content is all on-stage. The compose pass then samples at offset 0.

It applies to single (unchained) drop shadows, in both `tag.c render_filtered_object`
and `avm2_render_filtered` (n == 1). Bevels are excluded because they sample at both
+offset and −offset. The shift equals the nearest-rounded offset that the compose
pass used before (`floor(-off + 0.5)`), so wherever nothing crosses the stage edge,
the output is byte-identical (canary below).

**Edge guard.** A shifted read deliberately reaches past the layer edge, and the
sampler is ClampToEdge. The first cut therefore smeared an off-stage object's edge
row inward: `drop_shadow_angles` went 7 054 → 7 588, visible as vertical streaks.
The shifted run now uses a `tap()` helper that treats texels outside the layer as
transparent. When exactly one of a linear tap's two texels is outside, the clamped
sample equals the in-range texel, and the true value is that texel times its own
bilinear weight. This is exact. It is enabled **only** for a shifted run
(`params.border`); `select(s, …, false)` returns `s` unchanged, so every unshifted
blur is bit-identical. With the guard, `drop_shadow_angles` improves (7 054 → 6 934).

### Stretch lead closed: the "~0.9 px vertical halo offset" is a snap tie rule

The offset is not in the blur. Ruffle rounds the BLIT position
`bounds.min + draw_offset`, where `draw_offset = floor(filter-grown cache rect
corner)` is an integer ≤ 0. We rounded `bounds.min` alone. These differ only on an
exact `.5` tie whose sum is negative, because `f64::round` rounds half away from zero.

`blur_size_grows`: y_min = 40.5 px, `[Blur 30, Glow 30]` gives d = −60. So
−19.5 → −20, and Ruffle snaps **up** by 0.5 where `round(40.5)` snapped down. In x,
105.5 − 60 = 45.5 → 46 is the same either way, which is why x already matched.

`filter_draw_offset_px` (tag.c) and `avm2_filter_draw_offset_px` (avm2) port
`calculate_dest_rect`: PASS_SCALES, `Twips::from_pixels` truncation, drop-shadow
one-sided and bevel two-sided distance growth, stage-view scaling, and impotent-blur
skip. `cab_snap_delta` and the AVM2 snap now use `round(b + d) − d`, which is
identical to before except on those ties. Unfiltered cacheAsBitmap entries use d = 0.

The residual of 546 is the crisp cacheAsBitmap circle's 50 edge-tie pixels (|diff|
≥ 128) plus small halo diffs, so it is still not a flip (max_outliers 0).

---

## 2. Canary rigour (md5 A/B, before = the same worktree with `git apply -R`)

The fix is in shared blur and snap code, so both sets were A/B'd.

**Standing set** (`render_canary_tests.txt` as of `b57ecb2f3`): 58 tests,
**99 comparisons: 99 IDENTICAL.** No trace or image status change.

**Extra set:** the whole filter family, my 21 wave-1 at-risk passing rows, the other
failing filter rows, and all 13 image-bearing `regression/` rows. 54 tests, 58
comparisons: **55 IDENTICAL, 3 DIFFERS, all explained:**
- `acid-filter`: fail → **pass**, confined to bbox (506,87)–(528,169), the cut halo.
- `blur_size_grows`: the tie-rule fix (§1).
- `drop_shadow_angles`: bbox (388,13)–(439,17). A shadow of a partly off-stage
  object at the top edge now gets transparent-border reads; it improves.

Every other drop-shadow row is **byte-identical**: `drop_shadow`,
`drop_shadow_scales_with_screen`, the `cache_as_bitmap/edittext_*` rows,
`edittext_border_filters` and `glow*`. That confirms the shift is exact when nothing
reaches the edge.

Local Dawn, `--mode=graphics`, `-P 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `--recompile`
on the first leg.

**Sibling note:** `w2-edittext-filters` routes AVM1 EditText through
`render_filtered_object`. Its drop shadows will also take the pre-shift path. That is
exact away from the edges and only changes behaviour for shadows crossing the stage
edge. My tag.c hunks are self-localized:
- the new helpers `filter_draw_offset_px` and `filter_shadow_offset_px`
- the `cab_snap_delta` rounding lines
- one block before the blur loop and one line in the offset block of
  `render_filtered_object`

---

## 3. New unclaimed leads

1. **Stage-sized filter layer truncation, in general.** Any filter whose source
   object is partly OFF-stage loses the off-stage part. This affects blur, glow and
   bevel, not only shadows. The top-edge object in `drop_shadow_angles` shows it:
   Ruffle draws a continuous arc, we draw a gap. The completion mechanism is a padded
   (object-sized) FilterSource, s16's "trap". It now has a concrete witness.
2. **Unshifted blurs still use ClampToEdge replication at the layer edge.** `tap()`
   could be enabled for every blur (`params.border = 1`) to match Ruffle's
   transparent-padded cache. That is a separate A/B because it moves edge-touching
   rows.
3. **Pre-shift for chained shadows and bevels.** A bevel needs both ±offset, so the
   options are two blur copies or a padded layer (lead 1).
4. **`blur_size_grows` 546**: crisp cacheAsBitmap circle edge ties plus small halo
   diffs.
