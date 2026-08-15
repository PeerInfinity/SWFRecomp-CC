# w1-gfx-filters — AVM2 filters "Route 2", diagnosed, designed, and PROTOTYPED

Session 16, wave 1 (read-only diagnosis; **nothing committed, no main-tree source
edits**). Baseline `cd04f80b9`, grading run `31748059158` at `3db858cbc`.
Working prototype lives in the throwaway worktree
**`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w1-gfx-filters`**
(1 file, `SWFModernRuntime/src/avm2/avm2_display.c`, +148 incl. 8 lines of
env-gated debug; diff also at
`<scratchpad>/proto.diff`). Per the brief **no patch is delivered** — wave 2
should re-derive from the design below or lift the worktree.

---

## 0. Headline

| item | verdict | measured |
|---|---|---|
| **Cut 1 — stage-sized filter arm in `avm2_render_node`** | **GO, and it is much cheaper than briefed (~140 lines, ONE file, no new pipeline, no new texture, `MSAA_SAMPLES` invariant not engaged)** | **+1 flip byte-exact, +1 near-flip (−99.7 %), +1 large band move** |
| **"Route 2 owns much of the filters family"** | **REFUTED.** Of the board's 27 live filter comparisons, Route 2 owns **7**. **17 are AVM1-tag-path rows that already have a filter renderer**, 3 are CPU `applyFilter` rows | itemised in §2 |
| **"five known traps incl. object-sized FilterSource vs our stage-sized textures"** | **Trap 1 REFUTED for blur/glow/dropShadow/bevel** — the stage-sized machinery reproduces Ruffle **byte-exactly**, because Ruffle scales filters by the **stage view matrix only** and its cache texture is already in stage-pixel space. Object-sized only binds for **displacement's wrap/clamp modes**. Trap 3 was already corrected in s15. Traps 2/4/5 stand for cut 2 only | §5 |
| **NEW: AVM1 `render_display_list` has no filter arm** | **A separate, cheap defect worth its own wave-2 leg.** Filters authored inside a `DefineSprite` are silently dropped | owns `contains_grown_filter` (10 784) and `blur_scales_with_screen` (69 254), confirmed from the emitted code |

### Measured flip ledger (local Dawn, prototype applied)

| comparison | before (CI `31748059158`) | after (prototype) | budget | verdict |
|---|---:|---:|---|---|
| `visual/filters/glow_pass_scaling [output]` | 17 680, max 255 | **0 outliers, max diff 0** | tol 100 / 0 | **FLIP — byte-identical to the golden** |
| `from_shumway/acid/acid-filter [output]` | 152 866, max 255 | **482 (236 px), max 255** | tol 4 / 0 | **−99.7 %**; residual = rotated-diamond edge AA. Flip *possible*, not claimable locally (§7) |
| `visual/filters/blur_pass_scaling [output]` | 105 534, max 242 | **18 582, max 6** — rows 3–4 exactly **0 outliers, max 3** | tol 3 / 0 | band move only; the 18 582 is the s15 **CPU** `applyFilter` residual in rows 1–2 |
| `visual/cache_as_bitmap/masks [output.01…07]` | pass ×7 | **pass ×7** (2 520–3 094 of 3 200) | — | no regression (closest AVM2 neighbour) |
| displacement trio, `cab_mask_filters`, all 17 AVM1 rows | — | **unchanged by construction** | — | see §2/§4 |

**Net priced for cut 1: +1 comparison certain, +1 plausible, one −82 % band move.**
That is a smaller flip count than "owns much of the 15-row family" implies, but
the *mechanism* is fully solved and the code is 1/2 the briefed size.

---

## 1. What routes where (the classification the family actually needs)

`ruffle-tests/swf_is_avm2.py` is **not** the routing oracle: it returns AVM2 for
any SWF whose `FileAttributes` sets the AS3 bit, including movies with **no
`DoABC`**. Our runtime routes those through `tag.c`'s AVM1 display list. The
correct oracle is **`DoABC` (tag 72) or `DoABCDefine` (tag 82) present**.

Three disjoint render routes reach a "filter" in this codebase:

| route | entry point | kinds | state at HEAD |
|---|---|---|---|
| **A — AVM1 / timeline tag path** | `tag.c:6122` + `:7111` → `render_filtered_object` (`tag.c:3484`) | blur, dropShadow, glow, bevel — **one filter per display object** (`DisplayObject.filter_type` is a scalar) | implemented, with full inner/knockout/compositeSource composition. **Not reachable from `render_display_list`** (nested sprites) |
| **B — CPU `BitmapData.applyFilter`** | `avm2_bitmap.c::bd_apply_filter` | colorMatrix, blur, displacementMap (s15) | implemented; residuals are rounding + device-font |
| **C — AVM2 `DisplayObject.filters` ("Route 2")** | none — `avm2_render_node` never reads `ext->filters` | — | **missing entirely** |

Route C's *inputs* are already complete: `Avm2FilterVal` (`avm2_filters.h`)
carries every field in `swf::Filter`'s own fixed-point units, `store_filters` /
`do_set_filters` / `avm2_display_apply_tag_filters` populate it from both AS and
PlaceObject3, and it is GC-marked. Only the renderer arm was missing.

---

## 2. The 27-row family, re-owned

Using the board's itemisation (`wave1-gfx-board.md` PART 2), re-keyed by route.
`excess_outliers` from run `31748059158`.

### Route C — AVM2 `.filters` (7 rows) — MINE

| comparison | excess | budget | filters used | object | cut |
|---|---:|---|---|---|---|
| `from_shumway/acid/acid-filter [output]` | 152 866 | 4 / 0 | 15 PlaceObject3 tag filters: blur ×3 (50 px one-axis), dropShadow ×12 (dist 32–64, several with **blurX=blurY=0**) | 15 shapes on a 550×400 stage | **1** → 482 |
| `visual/filters/displacement_map [output]` | 123 279 | 32 / 160 | DisplacementMapFilter ×5, all four modes, non-zero mapPoint | 5 `TestImage` sprites | **2** |
| `visual/filters/blur_pass_scaling [output]` | 105 534 | 3 / 0 | rows 3–4: BlurFilter via `.filters`, incl. an N-long stacked list | 10 × 80×80 `Bitmap` per row | **1** (rows 3–4 → 0) |
| `visual/filters/displacement_map_scales_with_screen [output]` | 99 353 | 4 / 0 | DisplacementMapFilter, 2× stage scale | 175×175 + 175×20 `Bitmap` | **2** |
| `visual/filters/displacement_map_through_filters [output]` | 27 565 | 4 / 0 | same, 1× | same | **2** |
| `visual/filters/glow_pass_scaling [output]` | 17 680 | 100 / 0 | row 1 GlowFilter(quality 0..9); row 2 N stacked identical glows | 10 × 40×40 `Shape` per row | **1** → **0** |
| `visual/cache_as_bitmap/cab_mask_filters [output]` | 4 968 | 4 / 0 | Blur / 2× DropShadow — **on the MASKER**, with `cacheAsBitmap` on either side | 16 × 20×20 cells | **3** |

### Route A — AVM1 tag path (17 rows) — NOT MINE, and mostly *not* "missing"

`blur_size_grows` 87 808 · `bevel_outer` 80 996 · `bevel` 71 451 ·
`blur_scales_with_screen` 69 254 · `bevel_full` 69 161 · `drop_shadow_angles` 57 994 ·
`bevel_inner` 48 427 · `drop_shadow` 46 468 · `glow_with_alpha_strength` 43 329 ·
`glow` 25 505 · `glow_without_composite_source` 25 445 · `acid-filter-2` 16 759 ·
`cache_as_bitmap/contains_grown_filter` 10 784 · `any_blur_scales_with_screen` 4 884 ·
`edittext_border_filters` 810 · `drop_shadow_scales_with_screen` 400 ·
`filters/color_matrix` 237.

Eyeballed actual-vs-golden for the big ones: `glow`, `drop_shadow`, `bevel*`,
`drop_shadow_scales_with_screen` are **structurally correct** — these are
accuracy rows in a working renderer (blur profile / AA), which is why the board
clusters them `diffuse_mixed`. Two are structurally *broken*, see §3.
`filters/color_matrix` emits **no `tagSetFilter` at all** (kind 6 is not in the
tag path's 4-kind vocabulary) yet costs only 237 channels.

### Route B — CPU `applyFilter` (3 rows) — NOT MINE

`blur_quality` 166 986 (per-pass rounding; board sharpened it to "every offending
channel is 7–9 against tol 6") · `bitmapdata_applyfilter_blur` 30 844 (device
font, s15) · `bitmapdata_applyfilter_colormatrix` 7 419.

**`blur_pass_scaling` is the one row that spans two routes** (rows 1–2 = B,
rows 3–4 = C). Measured split: B contributes 9 291 per row at max diff 6, C
contributes 43 476 per row. After cut 1, C's contribution is **0** and the row
is blocked entirely on B's rounding — i.e. **`blur_quality`'s fix flips
`blur_pass_scaling` too**, which makes that CPU-rounding item worth one more
comparison than the board prices it at.

---

## 3. NEW defect (Route A): filters inside a `DefineSprite` are silently dropped

`render_filtered_object` is called from exactly two places — the two ROOT
display loops (`tag.c:6122`, `tag.c:7111`). **`render_display_list`, the
recursive renderer for a sprite's own display list, has no filter arm at all**
(it has a blend-layer arm at `:3684`, and its leaf `switch (ch->type)` at
`:3806` draws the character raw).

Confirmed against emitted code:

```
contains_grown_filter/RecompiledTags/tagMain.c
   void sprite_3_frame_0(...) {
       tagPlaceObject2(app_context, 1, 2, 2, 0, 0, 0);
       tagSetFilter(app_context, 1, /*glow*/3, 50, 50, 1, 1, r=1,g=0,b=0,a=1, 1, 0, 0);
   }
blur_scales_with_screen/RecompiledTags/tagMain.c:44  (inside sprite_3_frame_0)
       tagSetFilter(app_context, 1, /*blur*/1, 10, 10, 1, 0, ...);
```

Both render **completely unfiltered** today (`contains_grown_filter`: plain blue
square, golden has a red glow; `blur_scales_with_screen`: sharp red box, golden
is heavily blurred). Root-authored filters in the same suite (`drop_shadow`
4 × root, `glow_with_alpha_strength` 9 × root) render fine.

Shape of the fix: the same `else if (obj->filter_type != 0) render_filtered_object(...)`
arm the root loops have, added to `render_display_list`'s dispatch. **Caveat a
wave-2 agent must check first:** `tagSetFilter` writes `display_list[depth]`, the
*global* array — verify the sprite-frame execution actually rebinds
`display_list`/`max_depth` to the sprite's own list, or the write lands on the
wrong entry and the arm alone won't help.

Priced: **2 rows confirmed (10 784 + 69 254)**, plus an unknown share of the six
Route-A rows whose `RecompiledTags` are not present locally
(`any_blur_scales_with_screen`, `blur_size_grows`, `drop_shadow_scales_with_screen`,
`glow`, `glow_without_composite_source`, `bevel*`). Cheap to settle: recompile
each and `awk '/^void sprite_/,/^}/' tagMain.c | grep -c tagSetFilter`.

---

## 4. The design (cut 1) — what the prototype actually does

### 4.1 Why stage-sized is not a compromise

Ruffle's filter path *is* its `cacheAsBitmap` path (`core/src/display_object.rs::render_base`,
lines 968–1100): a non-empty `filters` forces `is_bitmap_cached()`, the object is
drawn into a cache texture sized to its **filter-grown render bounds under the
full world matrix (stage scale included)**, `descriptors.filters.apply(...)` runs
each filter over `FilterSource::for_entire_texture`, and the result is
composited back with a **translation-only** matrix. Two consequences decide our
design:

1. **Filters are scaled by the stage view matrix only** —
   `filter.scale(stage_matrix.a, stage_matrix.d)` — never by the object's own
   scale. Our `render_webgpu_run_blur` already does exactly this
   (`blur_box_kernel((blur - 1) * ctx->stage_scale + 1)`, `render_webgpu.c:4429`),
   which is a literal port of `blur_filter.rs::scale_blur`.
2. **The filter runs in stage-pixel space.** A stage-sized transparent layer,
   blurred with `texel = 1/ctx->width`, is therefore the *same computation* as
   Ruffle's object-sized cache texture — the only difference is where the
   ClampToEdge boundary sits (object border vs stage border), which matters only
   for a filter whose kernel is defined *relative to the source rect*.
   Blur/glow/dropShadow/bevel clamp at transparent black either way.

Measurement, not argument: `glow_pass_scaling` comes out **byte-identical to
Ruffle's golden** through the stage-sized path, and `blur_pass_scaling`'s
Route-C rows come out at **0 outliers, max 3**. Trap 1 does not bind here.

Where it *does* bind: **displacement** (wrap/clamp are defined on the source
rect — a stage-sized port wraps around the STAGE), and **two filtered objects
overlapping in one frame under a nested filter** (single ping-pong; see §6).

### 4.2 Hook point

`avm2_render_node` (`avm2_display.c:15548`), immediately after the
`ext == NULL` / visibility guards and **before** the mask / scrollRect pushes,
so the filter wraps the node's whole subtree exactly as `render_filtered_object`
wraps `render_single_object`:

```c
if (ext->filter_count > 0 && obj != g_avm2_filter_skip
    && g_avm2_filter_active == 0 && g_avm2_mask_capture == 0)
{
    avm2_render_filtered(ctx, obj, ext, parent_world, parent_alpha, parent_cx);
    return;
}
```

Re-entry is controlled by two file-static locals — `g_avm2_filter_skip` (the
object currently being captured) and `g_avm2_filter_active` (suppresses the arm
for the whole subtree, because the offscreen ping-pong does not nest). Both are
saved/restored, so the arm is re-entrant-safe without a stack.

`g_avm2_mask_capture == 0` deliberately makes a filtered *masker* render its raw
silhouette — that is why `cab_mask_filters` is untouched and is cut 3.

### 4.3 Body

Structurally a port of `tag.c::render_filtered_object` generalised from one
filter to a list:

```
select   list[] = filters with avm2_filter_supported()      (§4.4)
if none  -> plain avm2_render_node, return
last     = list[n-1]; derive is_shadow/is_glow/is_bevel, inner/knockout/
           composite/bevel_type/needs_source_tex/draw_source_{before,after}/
           shader_composite EXACTLY as tag.c:3486-3533 does
renderer_suspend_pass
renderer_begin_offscreen_pass          (clears filter_tex_a to 0,0,0,0)
avm2_render_node(...)                  (re-entry, arm suppressed)
renderer_end_offscreen_pass
if needs_source_tex: renderer_snapshot_filter_source
for i in 0..n-1:  renderer_run_blur(blur_x, blur_y, quality, strength,
                                    colour, colorize)      -> ping-pong in place
renderer_resume_pass
if last is plain blur: renderer_composite_filtered(0,0, 0,0,0,0)
else:                  [draw_source_before] renderer_compose_filter(...)
                       [draw_source_after]
restore statics
```

Unit conversions off `Avm2FilterVal` (all already in `swf::Filter` units):
`blur_x/blur_y/angle/distance` are Fixed16 (`/65536`), `strength` is Fixed8
(`/256`), `color`/`color2` are `0xRRGGBB` with separate `alpha`/`alpha2` bytes,
`quality` is the pass count. `composite_source = !hide_object`;
`bevel_type = on_top ? 2 : (inner ? 1 : 0)` and bevels hard-code
`composite_source = 1`, both straight from `tag.c`. The drop-shadow/bevel UV
offset is `du = cos(angle)*distance / context->width * app->stage_fit_x`
(and `dv` with `sin`/`height`/`stage_fit_y`) — identical to `tag.c:3559-3567`,
with `context->width/height` standing in for `app_context->width/height`.

### 4.4 Filter selection / impotence

```c
kind must be BLUR | DROP_SHADOW | GLOW | BEVEL      (cut 1 vocabulary)
quality == 0                                  -> skip   (all kinds)
kind == BLUR && blur_x <= 1 && blur_y <= 1    -> skip   (blur ONLY)
```

This mirrors `render/src/filters.rs::Filter::impotent()`, which matches **only**
`BlurFilter` and `ColorMatrixFilter`. The `quality == 0` skip is empirically
required for glow too — `glow_pass_scaling`'s quality-0 tile is unfiltered in
the golden, and keeping the skip is what makes that test byte-exact.

### 4.5 Chaining

`filter_tex_a` is the ping-pong's own input and output, so an N-long list of
plain blurs chains for free: `blur_pass_scaling` row 4 (N stacked BlurFilters)
lands at **0 outliers** with no extra machinery, and is bit-equal to row 3
(quality N) exactly as Flash requires.

A chain whose non-final members are glow/dropShadow/bevel is **not** exact —
there is no compose-into-offscreen pipeline, so the prototype approximates a
non-final composited filter as `run_blur(..., colorize=1, strength)`. That
approximation happens to be exact for `glow_pass_scaling` row 2 (identical
stacked glows over an opaque white square), but it is not general. Cut 3 item:
a `compose_pipeline` variant that renders into `filter_tex_a` instead of the
resumed main pass.

### 4.6 Budget / invariants

- **No new texture, no new pipeline, no new uniform block.** Cut 1 reuses
  `filter_tex_a`/`filter_tex_b`/`filter_msaa_view`/`filter_ds_view`, which are
  allocated unconditionally by `render_webgpu_ensure_filter_resources` today.
  So the s15 `MAX_DYNAMIC_BITMAPS` budgeting and the acid-color 1.73 GB
  refutation are **not engaged at all** — VRAM is unchanged to the byte.
- **`MSAA_SAMPLES`**: no pipeline is created, so the invariant is not engaged.
  It *will* be for cut 2's displacement pipeline.
- **`render_stub.c` twin**: not needed. Every call is an existing
  `renderer_*` macro that is already `((void)0)` under `NO_GRAPHICS`, and the
  whole arm sits inside `#if defined(OFFSCREEN_RENDER) || (__EMSCRIPTEN__ && !NO_GRAPHICS)`.
- **Mode parity**: render-only, so `NO_GRAPHICS` trace output cannot move.
  (Contrast s15's deliberate choice to put `applyFilter` on the CPU — that one
  IS script-observable. This one is not.)

---

## 5. The five briefed traps, adjudicated

| trap (s15) | status |
|---|---|
| **1. object-sized `FilterSource` vs our stage-sized textures** | **REFUTED for blur/glow/dropShadow/bevel** (§4.1, measured byte-exact). **STANDS for displacement** — wrap/clamp/ignore are defined on the source rect, so a stage-sized port wraps the stage. Cut 2 must pass the object's screen rect as uniforms and do the mode arithmetic inside it, sampling `filter_tex_a` at `(rect_origin + wrapped_local)/stage_size` |
| **2. map BitmapData must reach the GPU** | **STANDS**, cut 2 only. Cheapest route is still the dynamic-bitmap upload (`render_webgpu_draw_bitmap_quad_scaled`'s path, capped by `dynamic_bitmap_max_w/h`) plus a bound array layer |
| **3. premultiplication** | **ALREADY CORRECTED in s15** (`w2-gfx-blur-report.md` §3): Ruffle's BitmapData is premultiplied too; do **not** un-multiply |
| **4. a CPU shortcut cannot cover `*_scales_with_screen`** | **STANDS and is now moot** — cut 1 is on the GPU and `ctx->stage_scale` already carries the stage-matrix scaling Ruffle applies |
| **5. `MSAA_SAMPLES`, never a literal 4** | not engaged by cut 1 (no new pipeline); engaged by cut 2 |
| **NEW 6. `Avm2FilterVal.strength == 0` for `BlurFilter`** | AS3 `BlurFilter` has no `strength` property, so the field stays 0. Feeding it to `render_webgpu_run_blur` multiplies the final V pass by zero and **the whole object vanishes**. Plain blur must force `strength = 1`. Cost me one build cycle; it presents as "the filtered object disappeared", not as "the blur is wrong" |
| **NEW 7. impotence is blur-only** | Applying the `blur <= 1` impotence rule to every kind drops `acid-filter`'s four `blurX=blurY=0, distance=32` drop shadows and leaves it at 16 596 instead of **482** — a 34× difference from one predicate |
| **NEW 8. `quality == 0` skips for glow as well** | keeps `glow_pass_scaling` byte-exact |

---

## 6. Staged plan

### Cut 1 — wave-2 sized, ONE file, ~140 net lines
`SWFModernRuntime/src/avm2/avm2_display.c` only: `avm2_render_filtered()` +
`avm2_filter_supported()` + one fixed-point helper + the 5-line hook in
`avm2_render_node`. No header change, no new file, no recompiler change, no
`SWFRecomp/` rebuild needed (runtime-only ⇒ the main tree's `SWFRecomp/build`
may be copied into the worktree).

Ledger to declare: `glow_pass_scaling` fail→**pass**; `acid-filter`
152 866→~482 (**watch — may flip on lavapipe**); `blur_pass_scaling`
105 534→18 582 (band). Everything else byte-identical.

### Cut 2 — displacement (arc-sized, NOT a wave-2 leg on its own)
New WGSL pipeline (`MSAA_SAMPLES`!), object-rect uniforms, map-bitmap upload,
4 modes × 4 channel selectors. Owns `displacement_map_through_filters` (27 565,
tol 4/0), `_scales_with_screen` (99 353, tol 4/0) and `displacement_map`
(123 279, tol 32/**160** — the loosest budget in the family and therefore the
one to aim at first). The s15 CPU port in `bd_apply_filter` is a correct,
already-graded reference implementation of the exact same kernel — port it to
WGSL rather than re-deriving from `displacement_map.wgsl`.

### Cut 3 — the rest
(a) compose-into-offscreen pipeline → exact chained composited filters;
(b) filters on a **masker** → `cab_mask_filters` (4 968);
(c) colorMatrix / convolution / gradientGlow / gradientBevel kinds on Route C;
(d) `Filter::calculate_dest_rect` bounds growth — only needed once anything
    reads filtered bounds (`getBounds`, hit tests, `cacheAsBitmap` sizing);
    the stage-sized layer needs no growth to *render* correctly.

### Adjacent, separately dispatchable
- **Route A nested-sprite filter arm** (§3): 2 confirmed rows, ~10 lines +
  one verification. Different file (`tag.c`), no textual overlap with cut 1.
- **`blur_quality` CPU rounding**: now worth **2** comparisons, not 1 — it is
  the sole remaining blocker on `blur_pass_scaling` after cut 1.

---

## 7. Regression risk and the canary set

Two corpus scans (both over all 549 graded comparisons at run `31748059158`):

1. **`.filters =` set from ActionScript on a `DoABC` movie, on a currently
   PASSING comparison: ZERO.**
2. **PlaceObject3 with the FILTERLIST flag on a `DoABC` movie: exactly one
   graded movie in the entire corpus — `from_shumway/acid/acid-filter`, and it
   is already failing.** (Scanner: `<scratchpad>/scanf.py`, parses the tag
   stream and tests PlaceObject3 flag byte 2 bit 0.)

⇒ **Route C's pixel-axis regression surface is essentially empty**: every
comparison the arm can move is currently failing. The trace axis cannot move at
all (render-only).

**Canary set to run anyway** (nearest neighbours — AVM2 movies that use
PlaceObject3 and/or the string `filters`, all currently passing):

- `visual/cache_as_bitmap/masks` × 7 — **RAN with the prototype, all 7 still
  pass** (2 520–3 094 of a 3 200 budget; unchanged shape)
- `from_shumway/acid/acid` × 18 (AVM2 + PlaceObject3, no filter list)
- `visual/cache_as_bitmap/oversize/swf_{9,10}_too_big`
- `avm2/bitmapdata_filter_sourcerect`, `visual/cache_as_bitmap/bitmap_changed` ×3
- `regression/avm2_timeline_gradients`, `regression/avm2_timeline_stroke_gradient`
- `from_shumway/timeline/timeline_loop`, `from_shumway/MaskTest-3`

**Canary blind spot (per s15 lesson).** `ruffle-tests/render_canary_tests.txt`
has **no AVM2 `.filters` member at all**, and both of its "filters proper"
entries (`visual/filters/drop_shadow`, `visual/filters/color_matrix`) are
**Route A**, so the standing canary is structurally blind to this change class.
Recommend adding **`visual/filters/glow_pass_scaling`** (byte-exact against its
golden with cut 1 applied, so it can join tier 1) and
**`visual/cache_as_bitmap/masks`**.

**Why `acid-filter` is a "watch" and not a claimed flip.** Its residual is
236 pixels of antialiased edge on the two rotated diamonds — i.e. the
`hairline_edge_drift` mechanism, which is precisely where local Dawn and CI
lavapipe disagree (playbook §6: never grade a local render against a golden).
At tol 4 / `max_outliers` 0 it can land either side. Declare it in the ledger as
"152 866 → ~482, may flip".

---

## 8. Sibling boundaries

Nothing in cuts 1–3 touches the gradient builders (`swf.cpp` / `action.c` /
`avm2_display.c`'s gradient code), `opaqueBackground`, or `beginBitmapFill` —
cut 1's only edit is a self-contained block appended immediately above
`avm2_render_node` plus a 5-line hook inside it. The §3 Route-A item touches
`tag.c::render_display_list`, which no filters sibling owns; a wave-2 agent
holding both should still split them into two patches so the CI ledger can
attribute them.

## 9. Board corrections requested

1. Playbook §14 "AVM2 filters Route 2 offscreen/composite arc (owns much of the
   15-row filters family)" → **"owns 7 of the family's 27 rows; 17 are AVM1
   tag-path rows and 3 are CPU `applyFilter`"**.
2. §14's "five traps incl. object-sized FilterSource" → **trap 1 does not bind
   for blur/glow/dropShadow/bevel (measured byte-exact through the stage-sized
   path); it binds only for displacement**. Add traps 6–8 (§5).
3. `wave1-gfx-displace-blend.md` §1.5 pricing "A2: ~250–350 lines across
   `avm2_display.c` + `render_webgpu.c` (+`render_stub.c` twin), risk high" →
   **~140 lines, `avm2_display.c` only, no renderer change, no stub twin, risk
   low; the 250–350 estimate is the DISPLACEMENT pipeline (cut 2), not the
   filter stage**.
4. New board row: **"AVM1 filters authored inside a `DefineSprite` never
   render — `render_display_list` has no filter arm"** (owns
   `contains_grown_filter` 10 784 and `blur_scales_with_screen` 69 254).
5. `blur_quality`'s CPU rounding item is worth **2** comparisons, not 1
   (it is `blur_pass_scaling`'s sole remaining blocker after cut 1).

## 10. Artifacts

- Prototype worktree (kept): `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w1-gfx-filters`
  — `SWFModernRuntime/src/avm2/avm2_display.c` +148 (8 of them env-gated
  `SWFR_FILT_DUMP` `fprintf`s that must NOT ship), plus the five test dirs it
  recompiled locally.
- Diff copy: `<scratchpad>/proto.diff`.
- Corpus scanners (throwaway): `<scratchpad>/scanf.py` (PlaceObject3 FILTERLIST
  × DoABC over all graded tests), `<scratchpad>/scan.py`, `<scratchpad>/rows.py`
  (per-band excess attribution).
