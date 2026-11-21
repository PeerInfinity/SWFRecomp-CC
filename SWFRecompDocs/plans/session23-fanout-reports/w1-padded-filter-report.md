# w1-padded-filter: session 23, wave 1 (cloud)

Slot `w1-padded-filter`, branch `fanout/w1-padded-filter`, base `origin/master` `ad99dc15`.
Corpus: `download_tests.sh visual avm1` (rows), plus `avm2 fonts from_shumway text` (canary members only),
from upstream master on 2026-11-21. Ruffle clone HEAD **`0ddd12b6a`**. Setup: `SETUP_STATUS` all OK
(apt, Pillow, Dawn); graphics runs are Dawn on lavapipe.

**New files (all under `session23-fanout-reports/`):**
- `w1-padded-filter-report.md` (this file)
- `w1-padded-filter-prototype.patch`: the measured prototype. It touches
  `SWFModernRuntime/src/rendering/render_webgpu.c`, `include/rendering/{render_webgpu.h,renderer.h}`,
  `src/libswf/tag.c` and `src/avm2/avm2_display.c`. No new source files. It applies to `origin/master` `ad99dc15`.
  The source files on the branch are reverted; the commit holds only the two files above.

**Fidelity (CI-grade).** The cloud before-renders of **all three rows** are byte-identical to CI's
actual PNGs on `origin/ruffle-image-results`:

| row | md5 |
|---|---|
| `drop_shadow_angles` | `4bbc9f48…` |
| `displacement_map` | `3e0b7c9f…` |
| `bevel` | `134c3e91…` |

They also grade to CI's numbers (549/0, 408/72, 750/6). The branch was still at run **`38995363802`** (s22 final,
`38cf9b1a0`, pushed 2026-10-17) when I re-fetched it at the end of the session. The baseline run `44922638965` had
not force-pushed it yet. No render code has changed since `38cf9b1a0` (BRIEFS_COMMON baseline list), so the
absolute grades below are CI-grade.

---

## 0. Verdicts and priced flips

| row | board | verdict | measured (cloud, CI-grade) | residue owner |
|---|---|---|---|---|
| `visual/filters/drop_shadow_angles` | 549 / 0 | **GO, +1 flip** | 549 → **0** (max diff 1 / tol 2) | none |
| `visual/filters/displacement_map` | 408 / 72 | **GO, +1 flip** | 408 → **20** / 72 (gated prototype; 12 ungated) | 20 scattered AA singles; headroom 52 |
| `visual/filters/bevel` | 750 / 6 | **NO-GO for the padded layer. Premise REFUTED**: y=305 is not a filter-edge row | 750 → 750 (pad hack AND prototype) | 729 ch = background checker tie (§1.3, needs oracle); 21 ch = labels (**sibling `w1-filter-label`**) |

**Prototype total: +2 pixel flips, 0 regressions** in a 118-test / 175-comparison md5 A/B. The A/B covers
the whole standing `render_canary_tests.txt` set (87), plus every `visual/filters/*` and
`visual/cache_as_bitmap/*` image test (§2). It does not touch the trace axis (`renderer_*` macros are
`((void)0)` under NO_GRAPHICS).

Upstream commit `68dcb8931` ("Keep the bounds of empty objects empty when applying filters") **does not
matter for these rows.** See §3.

---

## 1. Mechanisms

### 1.1 The off-stage capture (the owner of both flips)
- The filter textures are created at stage size (`render_webgpu.c:4661` `ftex_desc.size = {ctx->width,
  ctx->height}`; MSAA `:4690`; offscreen depth-stencil `:5116`). `render_webgpu_begin_offscreen_pass`
  (`:5432`) rasterises the filtered object with the normal `stage_to_ndc`. **Any part of the object
  that lies off-stage is clipped and never stored.** This is s22 §1.4's finding, re-confirmed on current master.
- Ruffle's model is object-sized instead. `core/src/display_object.rs:990-1056` sizes the cache from
  `render_bounds_with_transform(..)`, grown by each filter's `calculate_dest_rect`
  (`render/src/filters.rs:89`), at an integer `draw_offset`. The whole object, on-stage or not, feeds the blur,
  shadow and displacement.
- **`drop_shadow_angles` (549, all of it in one cluster, y 0–24 × x 375–450):** this is the top arc's shadow. Its
  source arc is above y=0, so its shadow tail never reaches the stage. Stroke parity (s22) took the rest of
  the row to zero, so the off-stage capture is now the row's *only* defect.
- **`displacement_map` (408):**
  - 271 channels are the left-edge tile (x 0–14, y 325–360). The displacement wrap reads the object's real
    off-stage pixels there.
  - ~100 are the y=678 run (x 49–205). That is the same mechanism: it moves to 0 under padding.
  - The remaining ~12–20 are scattered single AA pixels (max diff ≤101, but each is 1–4 channels).

### 1.2 Upper bound: s22 padhack re-applied on current master
`w1-offstage-filter-padhack.patch` still applies cleanly. With `SWF_PAD_HACK=64`:

| row | result |
|---|---|
| `drop_shadow_angles` | 549 → **0** (md5 `dea17f00…`) |
| `displacement_map` | 408 → **11** / 72 |
| `bevel` | 750 → 750 |

So the board's premise holds for the two rows, and fails for bevel.

### 1.3 `bevel` y=305: NOT a filter-edge row (refutes the board's description)
- 729 of 750 channels are **one row, y=305, x 28..549, every other checker column** (243 px × 3 ch). The
  other 21 channels are 7 pixels of the "Knockout" (y 21–28, x 379–456) and "Out" (y 294/299, x 19) labels.
  Those are **sibling `w1-filter-label`'s.**
- **The row is the stage-background checkerboard, not a filter.**
  - Sprite 5 is placed at depth 1 with matrix a=0.5555573, d=0.5554504 (Fixed16 36402).
  - It tiles 1000×1000-twip solid quads: shape 1 = gray 199, shape 3 = white 254, **no line styles** (parsed from the SWF).
  - The row-10/row-11 cell boundary is at 11000·d = 6109.95 twips = **305.4977 px**: 0.0023 px above the centre
    of pixel 305.
  - We put pixel 305 in the row-11 cell everywhere: white in even columns, gray in odd ones.
  - The golden has **all of row 305 white**. In every column the white cell is the one drawn LAST at this
    boundary (depths 305/307, 309/311, 313/315, …), so in the golden both cells cover row 305 and the last draw wins.
- **Ruffle's own geometry does not explain the golden.**
  - Integer-twips concat (`swf/src/types/matrix.rs:115`, `Fixed16::wrapping_mul_int` truncates): the row-10
    white cell's bottom = 5554 + 1000·d = 6109.45 twips = **305.47 px**. The row-11 top = 6109 twips = 305.45 px.
  - Neither reaches the 305.5 centre, and `quality="low"` is 1 sample (`render/src/quality.rs:67`;
    we compile with `-DMSAA_SAMPLES=1` too).
  - Only this boundary sits within 0.03 px of a pixel centre; every other checker edge matches.
- The row is unchanged by the pad hack (whole-scene NDC rescale) and by the prototype.
- **Completion mechanism:** a local Ruffle-exporter render of `visual/filters/bevel` (LOCAL ORACLE REQUESTS).
  - If current Ruffle renders pixel (305, 30..549) gray, as we do, the golden is stale or from another
    rasteriser, and the row is a disposition: ACCEPTED_DIFFS "rasteriser tie", or an image-axis disposition.
  - If Ruffle renders it white, diff the vertex path (world-matrix composition / view matrix) on that one boundary.
- Either way, **`bevel` is not a padded-filter flip.** After the label fix it is still 729/6.

---

## 2. The prototype (`w1-padded-filter-prototype.patch`)

### 2.1 Design
A **padded twin + window copy-back**. Every composite path stays untouched.
- `render_webgpu_set_filter_pad(ctx, P)` (`renderer_set_filter_pad`) requests a padded layer for the next
  **outermost** `begin_offscreen_pass`. `ensure_pad_resources` lazily creates `(W+2P)×(H+2P)` twins of
  `filter_tex_{a,b}`, `filter_src`, `filter_msaa` and `filter_ds`. It also creates `pad_stage_buf` and a
  `pad_vertex_uniform_bg` (the `vertex_uniform_bg` twin over that buffer).
- On begin, `pad_swap()` swaps every handle, the vertex-uniform bind group included. Every existing
  `SetBindGroup(…, 1, ctx->vertex_uniform_bg)` inside the capture then binds the padded stage matrix for
  free. Matrix = current stage matrix (`hairline_stage`, which tracks every `stage_to_ndc` upload including the
  `_root` AS transform), with rows scaled by W/(W+2P) and H/(H+2P). It uses a **separate buffer**, because
  queue writes are frame-ordered, not encoder-ordered (s22 design note).
- `ctx->width/height` are **not** swapped, so the hairline min-width restage (`render_webgpu.c:3127`) stays
  correct. Instead, `filter_tex_w/h()` (= W+2P while padded) replace `ctx->width/height` in:
  - the blur texel size;
  - the snapshot, compose-to-layer and displacement copy extents;
  - the displacement `texsize`.
- Displacement rect: **+P integer offset**, not a rescale. This designs out s22 artifact (i), the
  `ceilf(20.00001) → 21` that flipped `displacement_map_through_filters`. That row stays PASS and md5-identical here.
- Chained compose-to-layer: the caller's UV offset is rescaled by W/(W+2P).
- `render_webgpu_resume_pass` → `pad_finish()`:
  - copies the stage window `(P, P, W, H)` of the padded layer and the padded source snapshot into the
    stage-sized textures;
  - un-swaps.
  - `composite_filtered`, `compose_filter`, the alpha mask and the blend paths then run exactly as on master.
- Callers:
  - `tag.c render_filtered_object` (AVM1/timeline route): **always** requests P=64.
  - `avm2_render_filtered`: **gated**. It requests P=64 only when the filter-grown device rect
    (`avm2_filter_screen_rect` + `avm2_filter_draw_offset_px` growth + |distance| + 2) crosses the stage edge.
- `SWF_FILTER_PAD=N` env is a MEASUREMENT override of P. Drop it in wave 2.

### 2.2 Per-row before/after (cloud, CI-grade; tolerance as `test.toml`)

| row | before | prototype (gated) | ungated (both drivers pad) | P sweep (ungated) |
|---|---|---|---|---|
| `drop_shadow_angles` | 549 / 0, max 51 | **0** / 0, max 1 (md5 = pad hack's `dea17f00…`) | 0 | P=16, 32, 64, 128: all 0 |
| `displacement_map` | 408 / 72, max 127 | **20** / 72, max 101 | 12 | P=16: 18 · P=32: 26 · P=64: 12 · P=128: 18 (all PASS) |
| `bevel` | 750 / 6 | 750 / 6 (66 ch moved ≤1 LSB) | 750 | n/a |

P=16 already saturates both flips, so a growth-sized P (Ruffle's `draw_offset`, which we already compute) is
enough. P need not be a big fixed pad.

### 2.3 md5 A/B (`render_canary.py`, before = clean `ad99dc15`, after = prototype; `-P 2`)
Set: all 87 `render_canary_tests.txt` members, plus all `visual/filters/*` and `visual/cache_as_bitmap/*`
image tests. That is 118 tests / 175 PNGs, including all 6 `regression/` members.

```
IDENTICAL 168   DIFFERS 7   APPEARED/VANISHED/NO_RENDER 0   TRACE STATUS CHANGES: none
fail -> pass : visual/filters/drop_shadow_angles, visual/filters/displacement_map
LSB-only, status AND outliers unchanged:
  visual/filters/bevel                    66 ch, max 1   (750/6 -> 750/6)
  visual/filters/bevel_inner              36 ch, max 2   (42/18 -> 42/18)
  visual/filters/bevel_full / _outer       8 ch, max 1   (42/18 -> 42/18)
  visual/filters/displacement_map_scales_with_screen  3 ch, max 1   (0/0, max_diff 1 -> 1, tol 4)
```
- Without the AVM2 gate (first leg): `displacement_map_through_filters` also moved (18 ch, max 1). The gate
  makes it identical again.
- The bevel ×4 moves come from the **ungated** AVM1 driver. They are the NDC-scale LSB artifact s22 predicted
  (§1.4 ii): float `ndc·k` plus linear blur taps at 1/(W+2P).
- Every other filtered row is md5-identical even though it goes through the padded path: `glow`,
  `drop_shadow`, `blur_*`, `glow_pass_scaling`, `cab_mask_filters`, `acid-filter-2`, `any_blur_scales_with_screen`,
  `edittext_border_filters`, `contains_grown_filter`, and others.

### 2.4 Wave-2 scope (exact)
1. Land the patch with `SWF_FILTER_PAD` removed.
2. **Gate the AVM1 driver** like the AVM2 one, which removes the bevel-family LSB churn:
   - Root entries: `opaque_bg_local_bounds` + `ng_entryTransformData(obj)[ng_get_original_transform_id(obj)]`,
     with the `filter_draw_offset_px` growth.
   - Pad unconditionally when the world is unknown: nested (via `compose_children`, `tag.c:4640`), or `_root`
     `as_set_flags`.
   - A root-loop flag in `render_filtered_root_entry` (`tag.c:~7146`) tells the two cases apart.
3. Size P from the growth (`-min(ox,oy) + |distance| + 2`, rounded up to 16 to limit reallocations, cap ~128)
   instead of the fixed 64. The pad textures reallocate on P change, so a bucketed P is the right cost/realloc
   trade.
4. Re-run this 118-test A/B plus the standing canary. Bar: md5 identity outside
   `{drop_shadow_angles, displacement_map, displacement_map_scales_with_screen}`.
   - The third row is gated-on (it crosses the edge under its 2x view) and moves 3 channels by 1 LSB. Tolerance is 4.
5. Canary membership: `drop_shadow_angles` / `displacement_map` become Tier-1 members of this change class once
   they pass in CI. Append at EOF.
- Cost: the blur area scales by (1+2P/W)(1+2P/H) **only for edge-crossing filtered objects**. On-stage objects
  keep the exact master path.

---

## 3. Refutations / premises attacked

- **"`bevel` 744 is one filter-edge row at y=305" (board §21): REFUTED.**
  - It is the background checker's cell boundary (§1.3). Padding does not move it.
  - Its 21 label channels are the sibling's.
  - Even with both fixed elsewhere, the row needs the oracle answer.
- **"These are now within reach of the padded-filter-layer model" (board §21): CONFIRMED for 2 of 3.**
  - `drop_shadow_angles` → 0 and `displacement_map` → 20/72, CI-grade.
  - s22's HOLD condition ("only after stroke parity") is met: the s22 cap of 6385 is gone and the row is 549 → 0.
- **s22 hack artifact (i), the displacement rect `ceilf`:** designed out with the integer +P offset;
  `displacement_map_through_filters` PASS and md5-identical.
- **s22 hack artifact (ii), the NDC-scale LSB:** still present, but sub-tolerance on every row measured. It is
  confined to padded objects, and the gate removes it for on-stage objects (§2.3).
- **Upstream `68dcb8931` (filter bounds of empty objects, after our `45366370e` sync): does NOT matter for these rows.**
  - We size layers by stage (master) or stage+fixed pad (prototype), never by a filter-grown bounds rect.
  - Our draw-offset growth (`tag.c filter_draw_offset_px`, `avm2_filter_draw_offset_px`) grows (0,0,w,h),
    which is always valid.
  - Its new test `visual/filters/empty_child_filter_bounds` (upstream `8b2447977`, drift) fails for us at
    **72840/0 before and after** (md5-identical). The cause is unrelated to bounds (lead N1).
- Drift on my rows: the three test dirs changed upstream only through `f0aa96e0c` (`num_frames`→`num_ticks`).
  No expected-PNG or tolerance change.

---

## 4. New unclaimed leads

- **N1 `visual/filters/empty_child_filter_bounds` (new upstream test, 72840/0).**
  - SWF 8 AVM1: two `createEmptyMovieClip` clips with drawing-API rects, `_x/_y`, `_xscale` 200, `_alpha` 40 and
    `filters=[BlurFilter]`.
  - We draw ONE unscaled, opaque, unblurred black shape at the origin. The second clip and every AS property are
    missing.
  - Owner: the AVM1 dynamic-clip render path for AS-assigned `filters` (not bounds).
  - Cheap triage: does the same SWF without `filters` render correctly?
- **N2 bevel y=305 tie.** Pending the oracle (§1.3); a disposition candidate.

## LOCAL ORACLE REQUESTS

1. **Ruffle exporter render of `ruffle-tests/tests/swfs/visual/filters/bevel/test.swf`**, 1 tick, `quality=low`
   (as `test.toml`), at current Ruffle (`0ddd12b6a`) and at the coordinator's `45366370e`.
   - Needed: the RGB of pixels (305, x) for x = 5, 30, 60, 540, and of rows 304/306 at x=30.
   - Question: does Ruffle paint row 305 white across the whole width (= the golden) or gray in odd checker
     columns (= us)?
2. (Optional, for N1) Ruffle exporter render of `visual/filters/empty_child_filter_bounds/test.swf`, 1 tick.
   This confirms the golden is current Ruffle's.
