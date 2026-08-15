# w2-gfx-filters — session 16, wave 2

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a6837b92f5e172108`
Base `cd04f80b9`. Grading baseline: CI run `31748059158` at `3db858cbc`.
Brief of record: `wave1-gfx-filters.md`. No commits, no pushes, no main-tree
source edits.

---

## 0. NEW FILES CREATED BY THESE PATCHES — **NONE**

All three patches touch tracked files only (the s15 `git add -u` poisoning mode
does not apply here):

| patch | files | lines |
|---|---|---|
| `w2-gfx-filters-cut1.patch` | `SWFModernRuntime/src/avm2/avm2_display.c`, `ruffle-tests/render_canary_tests.txt` | +240 / −4 |
| `w2-gfx-filters-sprite.patch` | `SWFModernRuntime/src/libswf/tag.c` | +31 |
| `w2-gfx-filters-blur-round.patch` | `SWFModernRuntime/src/avm2/avm2_bitmap.c` | +33 / −22 (2 substantive lines; the rest replaces s15's now-superseded comment table) |

All three are runtime-only — no `SWFRecomp/` change, so no recompiler rebuild
and no `--recompile` on merge. All three are independent and separately
mergeable; they touch three different files and three disjoint routes.

---

## 1. Verdicts

| item | verdict | measured |
|---|---|---|
| **Cut 1 — AVM2 `DisplayObject.filters` render arm** | **GO, ship** | **+1 flip byte-identical** (`glow_pass_scaling` 17 680 → **0**, max diff **0**); `acid-filter` 152 866 → **482** (−99.7 %); `blur_pass_scaling` 105 534 → **18 582** (max 242 → 6) |
| **Nested-sprite filter arm (`tag.c::render_display_list`)** | **GO, ship** | **+1 flip** (`contains_grown_filter` 10 784 → **0**); `blur_scales_with_screen` 69 254 → **30 810** (max 210 → 40) — does **not** flip |
| **Item 3 — CPU `applyFilter` blur rounding** | **GO, ship — the s15/shapes-morph NO-GO is REFUTED** | **+2 flips** (`blur_quality` 166 986 → **0**; `blur_pass_scaling` 18 582 → **0**) and the feared regression **does not happen** (`blur_fractional` passes in both legs) |
| **Canary / collateral** | **ZERO regressions** | 20 tests / 32 comparisons: **27 IDENTICAL**, 5 DIFFERS, all 5 the intended movers. 0 APPEARED / 0 VANISHED / 0 NO_RENDER. Trace status changes: **none** |

**Net priced for the merge batch: +4 comparisons, 0 regressions**
(`glow_pass_scaling`, `contains_grown_filter`, `blur_quality`,
`blur_pass_scaling`), plus `acid-filter` at 482/tol-4 as a coin-flip watch and
two large band moves.

### Refutations / corrections

1. **The blur-rounding item is not a trade — the s15 pricing that made it look
   like one is wrong.** `wave1-gfx-shapes-morph.md` §C ruled it NO-GO (max diff 9
   vs tol 6, completion mechanism "Ruffle intermediate-pass dump"), and s15's
   comment block in `blur_axis_pass` prices the literal port at "48 outlier
   channels, max diff 6" on `blur_fractional` (tol 5, i.e. a fail). **Measured
   directly on this tree, the literal port leaves `blur_fractional` at 0
   outliers / max 5 — a pass — while flipping `blur_quality` and
   `blur_pass_scaling`.** No dump was needed: the rule is in `blur.wgsl` line 68
   and `blur.rs:245`, and an exact numeric model of it reproduces the observed
   `max_diff = 9` to the level (§5).
2. **`blur_scales_with_screen` does NOT flip.** Wave-1 §3 priced the
   nested-sprite arm at "2 rows confirmed (10 784 + 69 254)". Only
   `contains_grown_filter` flips; `blur_scales_with_screen` goes 69 254 → 30 810
   (max 210 → 40) — the filter now renders, but the blurred result still misses.
   Correct pricing: **+1 flip, +1 band move**.
3. **Wave-1's "unknown share of the six other Route-A rows" is settled at ZERO.**
   I recompiled every remaining filters row and grepped for `tagSetFilter` inside
   a `sprite_N_frame_M` body (`awk '/^void sprite_/,/^}/' tagMain.c | grep -c
   tagSetFilter`): `any_blur_scales_with_screen` 16 total/**0** in-sprite,
   `blur_size_grows` 1/**0**, `drop_shadow_scales_with_screen` 1/**0**,
   `glow_without_composite_source` 4/**0**, `glow_with_alpha_strength` 9/**0**,
   `bevel` 12/**0**, `bevel_inner` 18/**0**, `bevel_outer` 18/**0**,
   `bevel_full` 18/**0**, `drop_shadow_angles` 5/**0**, `drop_shadow` 4/**0**,
   `glow` 4/**0**, `color_matrix` 0/0, `blur_fractional` 0/0. Every other row
   authors at the ROOT. The nested-sprite arm reaches **exactly two** comparisons
   corpus-wide; there is no upside left in it.
4. **Wave-1 §4.6's "VRAM is unchanged to the byte" is wrong in one direction.**
   `render_webgpu_ensure_filter_resources` is **lazy** (`filter_resources_created`
   guard at `render_webgpu.c:3568`), called from `begin_offscreen_pass`,
   `snapshot_filter_source` and `ensure_blend_resources`. An AVM2 movie that uses
   `.filters` and has no blend layer and no AVM1 filter now allocates that block
   where it previously allocated nothing: **3 stage-sized RGBA8 textures + 1
   `MSAA_SAMPLES`-sample colour texture + a uniform ring**, ≈ 3.5 MB at 550×400
   with `MSAA_SAMPLES=1`, ≈ 6 MB at 4. Bounded, stage-sized, one-shot — but not
   zero. (The s15 `MAX_DYNAMIC_BITMAPS` / 1.73 GB analysis is still not engaged.)
5. **The `quality == 0` skip is OURS, not Ruffle's** (wave-1 §5 trap 8 implies
   otherwise). `Filter::impotent()` matches only `BlurFilter`/`ColorMatrixFilter`;
   for a `GlowFilter` with `num_passes() == 0`, `blur.rs::apply` returns `None`
   and `glow.rs:176` feeds the **unblurred source** to the glow shader, so Ruffle
   still composites. Our skip is *visually* exact whenever `composite_source` is
   set and the distance offset is zero — the colorized copy lands exactly behind
   an opaque source — which is `glow_pass_scaling`'s case and is why that test
   comes out byte-identical. It is an approximation, and the shipped comment now
   says so. Everything else in wave-1's trap table held, including the two that
   cost real measurement: **BlurFilter strength must be forced to 1** (otherwise
   the object vanishes) and **impotence is blur-only** (34× on `acid-filter`).

---

## 2. Cut 1 — what shipped

`SWFModernRuntime/src/avm2/avm2_display.c`: one self-contained block immediately
above `avm2_render_node`, plus a 6-line hook inside it.

* `avm2_filter_renderable()` — kind vocabulary (blur / dropShadow / glow / bevel),
  the `quality == 0` skip, and `Filter::impotent()`'s **blur-only** `blur <= 1`
  rule (widening it to all kinds costs `acid-filter` 34×: 482 → 16 596).
* `avm2_render_filtered()` — stage-sized offscreen capture, N-long filter chain
  through the existing `filter_tex_a`/`filter_tex_b` ping-pong, then
  `renderer_composite_filtered` (plain blur) or `renderer_compose_filter`
  (glow/dropShadow/bevel). The flag derivations are `tag.c::render_filtered_object`'s,
  kept in the same order so the two stay diffable.
* `avm2_filter_fixed16()` / `avm2_filter_fixed8()` — `Avm2FilterVal` keeps
  `swf::Filter`'s own fixed-point bits, so one division is the whole conversion.
* One file-static, `g_avm2_filter_active`. The prototype's second static
  (`g_avm2_filter_skip`) was **removed**: it is provably dead — `skip` is only
  ever non-NULL while `active` is 1, so the `active == 0` term already subsumes
  the `obj != skip` term — and shipping an un-GC-marked `Avm2Object*` file-static
  is a trap not worth leaving in the tree.
* The 8 `SWFR_FILT_DUMP` debug lines are gone: the patch contains no `getenv`
  and no `fprintf`.

**Invariants confirmed, as the brief asked:**

* **No new pipeline.** Every call is an existing `renderer_*` macro; the patch
  creates no `WGPURenderPipeline`. `git diff | grep -c MSAA` = **0**, so the
  "never a literal 4" invariant is not engaged at all (the one MSAA texture in
  play is created by pre-existing code that already uses `MSAA_SAMPLES`).
* **No `render_stub.c` twin needed.** All eight renderer entry points used
  (`suspend_pass`, `begin`/`end_offscreen_pass`, `snapshot_filter_source`,
  `run_blur`, `composite_filtered`, `compose_filter`, `resume_pass`) already have
  `((void)0)` NO_GRAPHICS definitions in `include/rendering/renderer.h:107-114`,
  and the whole block sits inside the pre-existing
  `#if defined(OFFSCREEN_RENDER) || (__EMSCRIPTEN__ && !defined(NO_GRAPHICS))`
  gate at `avm2_display.c:14662`. **Mode parity cannot move** — render-only.
* **VRAM**: lazy, bounded, stage-sized — see §1.4. Not "unchanged to the byte".

**Ruffle basis re-verified** in `~/CC/ruffle`: `core/src/display_object.rs:980`
`filters.retain(|f| !f.impotent())`; `:995` `filter.scale(stage_matrix.a,
stage_matrix.d)` with the comment "Scaling is done by *stage view matrix* only,
nothing in-between"; `swf/src/types/blur_filter.rs:47`
`scale_blur = (blur − 1)·factor + 1`, which is literally `render_webgpu.c`'s
`blur_box_kernel((blur − 1)·stage_scale + 1)`. Trap 1 (object-sized
`FilterSource`) therefore does not bind for blur/glow/dropShadow/bevel — settled
not by argument but by `glow_pass_scaling` landing at **max diff 0**.

---

## 3. Sprite arm — what shipped

`SWFModernRuntime/src/libswf/tag.c`, +31 lines:

* the nested filter arm in `render_display_list`, gated on `!g_clip_mask_capture`
  (a filtered masker contributes its raw silhouette to the stencil, exactly like
  the blend-layer arm 130 lines above it) and on a new `g_filter_capture_depth == 0`;
* `g_filter_capture_depth` is incremented/decremented **inside**
  `render_filtered_object`, not at the new call site, so it also covers the two
  ROOT display loops. The single stage-sized ping-pong does not nest, and this
  closes the pre-existing hazard of a filtered sprite inside a filtered root
  entry. No behaviour change at the root — nothing else reads the counter.

**Wave-1's caveat is discharged.** `tagSetFilter` does write the *global*
`display_list[depth]` (`tag.c:11508`), but sprite frame execution rebinds
`display_list`/`max_depth` to the sprite's own list before running its frame
functions (`tag.c:633`, `:1080`, `:1214`), so the write lands on the right entry.
Confirmed end to end: `contains_grown_filter` flips fail → pass.

---

## 4. Per-comparison ledger (local Dawn, `--mode=graphics --images`)

Every BEFORE number below **equals CI run `31748059158`'s `excess_outliers` to
the digit** — 152 866 / 10 784 / 105 534 / 69 254 / 237 / 46 468 / 25 505 /
17 680 / 166 986. For this family local == CI, so the AFTER column is a strong CI
prediction rather than a mere A/B. `acid-filter`'s residual is the one exception
(§4.1).

| comparison | BEFORE (CI + local) | AFTER | budget | owner | verdict |
|---|---|---|---|---|---|
| `visual/filters/glow_pass_scaling [output]` | fail 17 680, max 255 | **pass 0, max 0** | tol 100 / 0 | cut 1 | **FLIP — byte-identical to the golden** |
| `visual/cache_as_bitmap/contains_grown_filter [output]` | fail 10 784, max 99 | **pass 0, max 1** | 0 outliers | sprite | **FLIP** |
| `visual/filters/blur_quality [output]` | fail 166 986, max 9 | **pass 0, max 6** | tol 6 / 0 | blur-round | **FLIP** |
| `visual/filters/blur_pass_scaling [output]` | fail 105 534, max 242 | 18 582, max 6 → **pass 0, max 3** | tol 3 / 0 | cut 1 **then** blur-round | **FLIP (needs both)** |
| `from_shumway/acid/acid-filter [output]` | fail 152 866, max 255 | fail **482**, max 255 | tol 4 / 0 | cut 1 | −99.7 %, **watch** (§4.1) |
| `visual/filters/blur_scales_with_screen [output]` | fail 69 254, max 210 | fail **30 810**, max **40** | tol 2 / 0 | sprite | −56 %, no flip |
| `visual/filters/blur_fractional [output]` | pass 0, max 5 | **pass 0, max 5** | tol 5 / 0 | blur-round | **no regression** — the crux of §5 |
| `visual/filters/drop_shadow [output]` | fail 46 468, max 255 | fail 46 468, max 255 | — | — | **byte-identical** (AVM1 root filter) |
| `visual/filters/glow [output]` | fail 25 505, max 255 | fail 25 505, max 255 | — | — | **byte-identical** (AVM1 root filter) |
| `visual/filters/color_matrix [output]` | fail 237, max 255 | fail 237, max 255 | — | — | **byte-identical** |
| `visual/cache_as_bitmap/masks [output.01…07]` | pass ×7 | pass ×7, **md5 identical** | — | — | closest passing AVM2 neighbour |
| `from_shumway/timeline/timeline_as2_5 [output.01…07]` | pass ×7 | pass ×7, **md5 identical** | — | — | nested-sprite AVM1 timeline = the sprite arm's blast radius |
| `regression/{mask_sibling_union, mask_nested_intersect, avm2_timeline_gradients}` | pass ×3 | pass ×3, **md5 identical** | — | — | standing `regression/`×3 policy |
| `avm2/blend_multiply_alpha`, `visual/cache_as_bitmap/shape_changed`, `avm1/{color, bitmap_data_fillrect, mask_with_drawing, movieclip_setmask, edittext_tag_indent}` | pass ×7 | pass ×7, **md5 identical** | — | — | — |

### 4.1 Why `acid-filter` is a "watch", not a claimed flip

Residual 482 channels over ~236 pixels, all antialiased edge on the two rotated
diamonds — the `hairline_edge_drift` mechanism, precisely where local Dawn and CI
lavapipe disagree (playbook §6: never grade a local render against a golden). At
tol 4 / `max_outliers` 0 it can land either side. Declare it in the merge ledger
as **152 866 → ~482, may flip**.

---

## 5. Item 3 — CPU `applyFilter` blur rounding: settled by reading, then GRADED

### 5.1 The rule, from the oracle

`render/wgpu/shaders/filter/blur.wgsl`, last line:

```wgsl
let result = total / filter_args.full_size;
return floor(result * 255.0) / 255.0;
```

and `render/wgpu/src/filters/blur.rs:236-249`:
`radius = (full_size − 1)/2`, `m = radius.ceil() − 1`,
`alpha = ((radius − m)·255).floor()/255`, with weights `alpha` on ±(m+1), `1` on
−m..m — a weight **sum** of `(2m+1) + 2·alpha`. Ruffle nevertheless divides by
`full_size`. Because `alpha` is quantized down to 1/255, the weight sum is up to
**2/255 smaller** than `full_size`, so a uniform field *decays* on every pass, and
the per-pass `floor` costs another half level on top. Our `blur_axis_pass`
deliberately departed on both counts (divide by the weight sum; round to nearest),
which is energy-preserving and therefore does **not** decay.

### 5.2 The model predicts the observed number exactly

`<scratch>/w2f_blursim.py` iterates the two rules over `blur_quality`'s grid
(`new BlurFilter(row, 1, col)`, blurX = row 0..9, quality = col 0..9, so a
horizontal-only blur since blurY = 1 is skipped):

```
 blur  q   ruffle uniform-255   ours   delta
    2  9                 246    255       9
    4  9                 246    255       9
    6  9                 246    255       9
    8  9                 246    255       9
    3/5/7/9, any q       255    255       0
worst decay over the grid: 9
```

The board's `blur_quality` row is `excess 166 986, **max_diff 9**`. The model
reproduces the maximum **to the level** and predicts (correctly) that it appears
only on EVEN blur sizes, where `radius` is fractional and `alpha255 = 127`; odd
sizes have `alpha255 = 255` and do not decay at all. The residual is 100 % the
s15 departure compounding over `quality` passes — not GPU precision, not
bilinear-weight quantization, not `sourceRect` handling.

### 5.3 Graded, not argued

`w2-gfx-filters-blur-round.patch` is two substantive lines
(`denom = 255.0 * k->full_size`, and `floor(x)` instead of `floor(x + 0.5)`),
graded on top of cut 1 + sprite:

| comparison | before the blur patch | with the blur patch | tolerance |
|---|---|---|---|
| `visual/filters/blur_quality [output]` | **fail** 166 986, max 9 | **pass** 0, max 6 | 6 |
| `visual/filters/blur_pass_scaling [output]` | **fail** 18 582, max 6 | **pass** 0, max 3 | 3 |
| `visual/filters/blur_fractional [output]` | pass 0, max 5 | **pass** 0, max 5 | 5 |

**+2 comparisons, zero regressions.** The one comparison s15's comment block
predicted would break (`blur_fractional`, "48 outlier channels, max diff 6")
does not move at all. That prediction is refuted on this tree; whatever s15
measured, it was not this rule (their table's "weight sum / floor" row scoring
identically to "full_size / floor" is itself a tell that the two variables were
not being varied independently).

The shipped comment block replaces s15's four-row table with the derivation and
the graded numbers, so the next agent does not re-litigate it.

**Residual risk:** all three comparisons are computed on the CPU, so local ==
CI for the filtered pixels; the only GPU-dependent part is the 1:1
`smoothing = false` Bitmap blit to the stage. `blur_quality` lands at max 6
against tol 6 and `blur_fractional` at max 5 against tol 5 — both exactly on the
budget, so a one-level lavapipe difference anywhere in the blit would flip them
back. Worth naming in the CI ledger as "on-budget".

---

## 6. Canary

`ruffle-tests/render_canary_tests.txt` gains two **tier-1** members in the cut-1
patch:

* `visual/filters/glow_pass_scaling` — the set's **first AVM2 `.filters` member**,
  byte-exact against its golden with cut 1 applied (so tier 1 is honest);
* `visual/cache_as_bitmap/masks` (7 comparisons) — the nearest passing AVM2
  neighbour of the new filter arm.

The header note is corrected: "filters proper" is no longer a family with *no*
CI-passing representative — the AVM1 *route* still is; the AVM2 `.filters` route
now has a tier-1 member.

**Blind-spot disclosure (s15 lesson).** Before this change the standing set was
structurally blind to the AVM2 `.filters` route: both "filters proper" entries
(`visual/filters/drop_shadow`, `visual/filters/color_matrix`) are AVM1-tag-path
and tier 2. Both are in my graded set and both came out **byte-identical**, which
is the positive control for the sprite patch. The blur-round patch's change class
(CPU `applyFilter`) is covered in the standing set only by
`avm1/bitmapdata_applyfilter_colormatrix` — which my subset dropped; I graded
`blur_quality`, `blur_fractional` and `blur_pass_scaling` directly instead, and
the patch cannot reach a colorMatrix (it is inside `blur_axis_pass`).

**Capture / compare** (`--recompile`, `-P 2`, local Dawn,
`SWFRECOMP_COMPILE_TIMEOUT=2400`, cut 1 + sprite applied):

```
RENDER CANARY  before=before  after=after   20 tests / 32 comparisons
  IDENTICAL    27
  DIFFERS       5
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES:
    visual/cache_as_bitmap/contains_grown_filter  output   fail -> pass
    visual/filters/glow_pass_scaling              output   fail -> pass
```

All five DIFFERS are the five intended movers of §4; nothing else moved by a byte.

**Set-size disclosure.** The machine is 8 cores under a load average of 28–43
from ~10 concurrent agents with ~2 GB free RAM; cold tests measured 420–500 s
each, so the full 30-test standing set × 2 legs would not have finished. I ran a
**20-test / 32-comparison risk-targeted subset**. It keeps all three
`regression/` members per standing policy, both AVM1-route filter entries, the
AVM2 cacheAsBitmap/mask cluster, a 7-comparison nested-sprite AVM1 timeline, and
the blend-layer arm adjacent to my `tag.c` edit. **Not covered:**
`avm1/focusrect_swf5` (12 cmps), `avm1/bitmapdata_applyfilter_colormatrix`,
`visual/simple_shapes/{winding_rule, masks, gradients}`,
`from_shumway/acid/{acid-gradient-0, acid-blend-2}`, `visual/blend_modes/multiply`,
`regression/{avm2_morph, avm2_timeline_stroke_gradient}`. None of them can reach
any of the three patches (no AVM2 `.filters`, no sprite-authored `tagSetFilter`,
no `BlurFilter` through `applyFilter`), and the AVM2 members among them are
covered in spirit by `masks` ×7 + `shape_changed` + `blend_multiply_alpha` +
`avm2_timeline_gradients`, all identical.

**Regression surface, independently of the canary.** Wave-1's two corpus scans
found ZERO currently-passing graded comparisons that set `.filters` from
ActionScript on a `DoABC` movie, and exactly one graded movie with a
PlaceObject3 FILTERLIST on a `DoABC` movie (`acid-filter`, already failing). My
own recompile scan (§1.3) found exactly two sprite-authored `tagSetFilter` movies
in the filters family, both already failing. The blur-round patch touches only
`bd_apply_filter`'s BlurFilter arm. All three surfaces are essentially empty by
construction, and the canary agrees.

---

## 7. Merge notes for the coordinator

* Stage by name: `SWFModernRuntime/src/avm2/avm2_display.c`,
  `SWFModernRuntime/src/libswf/tag.c`, `SWFModernRuntime/src/avm2/avm2_bitmap.c`,
  `ruffle-tests/render_canary_tests.txt`. **No new files.**
* Runtime-only ⇒ no `SWFRecomp/` rebuild, no `--recompile` needed.
* CI mode `graphics`, categories `all` (no AVM2 runtime/recompiler emission
  touched). `no-graphics` cannot move for cut 1 / sprite (both are inside the
  render gate or call only `((void)0)`-under-`NO_GRAPHICS` macros). The
  blur-round patch **is** script-observable — `applyFilter` is readable through
  `getPixel` — so it is the one of the three that belongs in a `no-graphics` run
  as well if the coordinator wants both axes; s15 put that code on the CPU
  precisely to keep the two modes in lockstep, and this patch keeps them there.
* An `images=true` run is what grades the four flips.
* Declare in the CI ledger: `glow_pass_scaling` fail→**pass**,
  `contains_grown_filter` fail→**pass**, `blur_quality` fail→**pass**
  (on-budget, max 6 vs tol 6), `blur_pass_scaling` fail→**pass** (needs cut 1
  AND blur-round), `acid-filter` 152 866→~482 (**watch**),
  `blur_scales_with_screen` 69 254→30 810, `blur_fractional` unchanged pass.

---

## 8. Board corrections requested

1. Playbook §14 "AVM2 filters Route 2 … owns much of the 15-row filters family"
   → **"owns 7 of the family's 27 rows"** (wave-1 §9.1 stands); cut 1 is now
   **shipped** and flips 1 of them, moving 2 more.
2. The new board row wave-1 asked for ("AVM1 filters inside a `DefineSprite`
   never render") is **retired on arrival**: it owns exactly **two** comparisons
   corpus-wide (§1.3), one of which flips. No third row exists.
3. `blur_quality`'s CPU-rounding item: re-price from "NO-GO, completion mechanism
   = Ruffle intermediate-pass dump" to **CLOSED — 2 lines, +2 comparisons, no
   regression** (§5). `wave1-gfx-shapes-morph.md` §C and the s15 comment table in
   `blur_axis_pass` are both superseded.
4. Wave-1 §4.6 "VRAM unchanged to the byte" → **lazy allocation, ≈3.5–6 MB
   one-shot** for an AVM2 `.filters` movie with no other offscreen user (§1.4).
5. Wave-1 §5 trap 8 → the `quality == 0` skip is **ours, not Ruffle's**; Ruffle
   composites the unblurred source. Exact only when `composite_source` is set and
   distance is 0 (§1.5).
6. Remaining filters upside after this batch, for the s17 board: the
   **displacement trio** (123 279 + 99 353 + 27 565, wave-1 cut 2 — the only
   place trap 1 actually binds), `cab_mask_filters` (4 968, filters on a masker),
   `blur_scales_with_screen`'s 30 810 residual, `acid-filter`'s 482, and the
   fourteen AVM1-route accuracy rows (blur profile / AA) that no structural fix
   reaches.

---

## Appendix A — the graded canary list

```
avm1/color                                   avm1/bitmap_data_fillrect
avm1/mask_with_drawing                       avm1/movieclip_setmask
avm1/edittext_tag_indent                     avm2/blend_multiply_alpha
visual/filters/glow_pass_scaling             visual/cache_as_bitmap/masks
visual/cache_as_bitmap/shape_changed         from_shumway/timeline/timeline_as2_5
regression/mask_sibling_union                regression/mask_nested_intersect
regression/avm2_timeline_gradients           visual/filters/drop_shadow
visual/filters/color_matrix                  visual/filters/glow
visual/cache_as_bitmap/contains_grown_filter visual/filters/blur_scales_with_screen
visual/filters/blur_pass_scaling             from_shumway/acid/acid-filter
```
Plus, graded separately for item 3: `visual/filters/blur_quality`,
`visual/filters/blur_fractional`.

## Appendix B — incident of record

Trying to stop my own canary driver I ran
`pkill -f "render_canary.py capture --label before"`. Sibling agents run the
identical command line from their own worktrees, so that pattern almost certainly
killed **two other agents' `before` captures** (worktrees
`agent-a8203094041d8f7c8` and `agent-ace18009389126e2d`, whose orphaned
`verify_output.py` children were still running afterwards). Nothing was corrupted
— captures are per-worktree — but those agents' before-legs needed restarting,
and their orphans later `rmtree`d a build directory out from under my own
restarted run, costing a second false `compile_fail`.

The memory note `pkill-f-self-match` covers *self*-matching; it should be
widened: **in a fan-out, `pkill -f` on ANY shared tool name is a cross-agent
kill.** Kill by PID only, filtered on your own worktree id
(`ps -eo pid,cmd | grep <worktree-id>`). I subsequently ran my captures through a
renamed copy of `render_canary.py` so a sibling's `pkill` could not take them
down — that copy (`ruffle-tests/w2gfxf_canary_tmp.py`) is untracked scaffolding
and is **not** part of any patch; delete it if it survives.

Second harness note: the default `SWFRECOMP_COMPILE_TIMEOUT` of 300 s produces
**false `compile_fail`s** on this machine under fan-out load (measured
`c=302.68s` on `acid-filter`). Every run in this report used
`SWFRECOMP_COMPILE_TIMEOUT=2400`. Worth adding to `BRIEFS_COMMON.md`'s
wave-2 rules alongside the `-P 2` cap.
