# Session 16 — wave 2 — w2-gfx-opaque (P2 `opaqueBackground` · P5 AVM2 `beginBitmapFill`)

**Agent:** w2-gfx-opaque · worktree `.claude/worktrees/agent-a6330478c3868aa5f` · no commits, no pushes.
**Brief of record:** `wave1-gfx-board.md` leads **P2** (GO, +2) and **P5** (DIAGNOSE-then-GO, 0–2).
**Deliverables:** `w2-gfx-opaque.patch` (P2), `w2-gfx-bitmapfill.patch` (P5), this report.

## NEW FILES CREATED BY THESE PATCHES

**None.** Both patches modify existing files only (8 files, 394 insertions, 1 deletion).
Nothing for the coordinator to `git add` beyond the tracked paths listed in §"Patch scope".

---

## VERDICTS

| lead | board price | delivered | verdict |
|---|---|---|---|
| **P2** `DisplayObject.opaqueBackground` | **+2 flips** | **0 flips**, −244 232 excess outliers (−99.2 %) | **IMPLEMENTED — pricing REFUTED.** Neither comparison flips; both residuals are a *different, precisely-named* defect (below). |
| **P5** AVM2 `Graphics.beginBitmapFill` | 0–2 flips | **0 flips**, −201 780 excess outliers (−63 %) | **IMPLEMENTED — the "0" arm of the board's own range.** Both blank rows named and graded; the residual is `lineBitmapStyle` + `drawGraphicsData` being no-ops, not the fill. |

**Net priced flips from this agent: 0.** Both patches are still worth merging — they
are large, monotone excess reductions with a byte-clean canary and zero trace movement
— but neither closes a comparison, and the board's `+2` for P2 does not survive contact.

---

## LEDGER (before → after, every test I touched)

### Pixel axis (`--mode=graphics --images`, local Dawn)

| comparison | checks | baseline outliers | after | Δ | flips? |
|---|---|---:|---:|---:|---|
| `visual/opaque_background [output]` | tol 1 / max_out 0 | **231 232** | **3 856** | −98.3 % | no |
| `avm2/displayobject_opaque_background [output]` | tol 1 / max_out 0 | **17 004** | **20** | −99.9 % | no |
| `avm2/graphics_bitmap_fill [output]` | tol 5 / max_out 60 | **136 030** | **76 870** | −43.5 % | no |
| `avm2/graphics_bitmaps [output]` | tol 8/4000, 16/800, 32/600 | **185 430** | **43 013** | −76.8 % | no |

Baselines reproduced locally at CI's exact numbers for the two P2 rows (231 232 / 17 004),
confirming the board's provenance. The two P5 baselines reproduced at 136 030 / 185 430
(the board quotes 136 090 for `graphics_bitmap_fill`; 136 030 is what both my baseline and
CI's `image_results_graphics.json` say — a typo in the board, not a discrepancy).

### Trace axis (`-P 2`, sequential re-run of anything suspicious)

| test | baseline (CI run `31748059158`) | after | verdict |
|---|---|---|---|
| `avm1/movieclip_default_state` | pass | **pass** | = |
| `avm1/movieclip_library_state_values` | ruffle_matched | **ruffle_matched** | = |
| `avm1/movieclip_state_values` | pass | **pass** | = |
| `avm1/global_proto_decls` | output_mismatch | **output_mismatch** | = (pre-existing) |
| `avm1/global_proto_decls_delete` | output_mismatch | **output_mismatch** | = (pre-existing) |
| `avm2/displayobject_opaque_background` | pass | **pass** | = (null/255 round trip preserved) |
| `avm2/stage_properties2` | pass | **pass** | = |
| `avm2/stage_overriden_setters` | pass | **pass** | = |
| `avm2/edittext_autosize_lazy_bounds_props` | pass | **pass** | = |
| `avm2/graphics_gradients` | pass | **pass** | = |
| `avm2/graphics_bitmaps` | pass | **pass** | = |
| `avm2/graphics_bitmap_fill` | pass | **pass** | = |
| `from_gnash/actionscript.all/MovieClip-v5` | ruffle_matched | **ruffle_matched** | = |
| `visual/opaque_background` | pass (no trace) | **pass** | = |

Those 14 are every test in the corpus that reads or writes `opaqueBackground`
(`grep -rl opaqueBackground` over `*.as` + `output.txt`) plus the AVM2 Graphics
neighbours of the bitmap-fill change. **Zero trace movement.**

### Render canary

`ruffle-tests/render_canary.py capture/compare`, 11 tests / 11 comparisons, `-P 2`,
`--recompile` (mandatory — this patch touches `SWFRecomp/`). A/B legs built by
`git diff` + `git apply -R` (never `git stash`).

```
IDENTICAL 8   DIFFERS 3   APPEARED 0  VANISHED 0  NO_RENDER 0
TRACE STATUS CHANGES: (none)
IMAGE STATUS CHANGES: (none)
```

The 3 DIFFERS are exactly my 3 in-set targets (`visual/opaque_background`,
`avm2/displayobject_opaque_background`, `avm2/graphics_bitmaps`); `graphics_bitmap_fill`
is the 4th target and was graded outside the canary. The 8 IDENTICAL are md5-identical:
`avm1/color`, `avm1/mask_with_drawing`, `avm2/blend_multiply_alpha`,
`visual/cache_as_bitmap/shape_changed`, `from_shumway/acid/acid-gradient-0`,
`regression/mask_sibling_union`, `regression/mask_nested_intersect`,
`regression/avm2_timeline_gradients` (regression suite represented 3×, per standing policy).

**Canary blind spot, stated per the s15 rule:** the standing set has no member that
carries a PlaceObject3 *BackgroundColor* field or an AVM2 bitmap fill — by construction,
since both were unimplemented. `visual/cache_as_bitmap/shape_changed` is the covering
member for the PlaceObject3 flags-2 parse path I edited in `swf.cpp` (it exercises the
same `is_po3` byte-skip chain) and it is IDENTICAL; `regression/avm2_timeline_gradients`
+ `from_shumway/acid/acid-gradient-0` cover the `Avm2GfxPath` / `gfx_finalize_path`
struct I extended, and both are IDENTICAL.

---

## P2 — mechanism, and why the +2 does not land

### What was missing, and what the patch does

`DisplayObject.opaqueBackground` had **no storage and no renderer** on either VM. The
AVM2 accessors were a dyn-prop echo (`avm2_display.c:10341`, `STUB_GETSET`-shaped); the
AVM1 name existed only as one of the ten "enumerable-but-undefined" prototype slots
(`action.c:15833`); and the recompiler *parsed and threw away* PlaceObject3's
BackgroundColor (`swf.cpp:4321`, `cur_pos += 4`).

Implemented per Ruffle, with the four semantics the brief asked me to pin down:

1. **Bounds source** — `render_bounds_with_transform(current transform, true, view_matrix)`:
   the object's own bounds *including children*, in world space.
2. **Ordering vs masks** — `display_object.rs::render_base` emits `draw_rect` **before**
   `apply_standard_mask_and_scroll`. The background is therefore **not** clipped by the
   object's own `mask` or `scrollRect`; an enclosing container clip still applies because
   that stencil is already live. Both patches place the call exactly there.
3. **Colour transform** — `commands.draw_rect(background, ...)` takes a `Color`, never a
   `ColorTransform`. Both call sites pass cxform slot 0 (identity).
4. **Alpha** — `set_opaque_background` forces `color.a = 255` ("Only solid backgrounds
   are supported"); the PlaceObject3 arm additionally *drops* a colour whose alpha is 0
   and is gated on `swf_version >= 11` (`display_object.rs:2543`). Both rules are applied
   in the recompiler, so `tagSetOpaqueBackground` only ever records what survived them.

Property round trip, also per Ruffle and confirmed by the tests:
* **AVM2** getter returns `color.to_rgb()` (a 24-bit uint) or **`null`** — never
  `undefined`, because the parameter is declared `Object`. The round trip is **lossy**:
  whatever you assign reads back as a uint. `displayobject_opaque_background`'s
  `null / 255 / null / 255 / null / 255` still passes.
* **AVM1** getter returns the uint or falls through to the prototype stub, which answers
  **`undefined`** — which is what `movieclip_default_state` and
  `movieclip_library_state_values` assert, and both still pass. The setter never falls
  through to the dynamic-property store (same discipline as `scrollRect`), so the
  enumeration tests are untouched.

### Documented divergence (deliberate)

Ruffle draws the **world-space AABB**; the AVM1 arm draws the object's **local** box
through the object's own already-composed transform slot. Identical for every unrotated
object; a rotated box rather than its AABB otherwise. Going through the object's own slot
is what makes the AVM1 arm correct inside nested sprites for free (the CPU-side
`transform_data` table is not indexable by a post-`compose_children` transform_id — see
`ng_get_original_transform_id`). No corpus test puts an opaque background on a rotated
object. The **AVM2** arm has no such divergence: it uses `bounds_with_transform(world)`,
i.e. Ruffle's rectangle exactly.

### Why `visual/opaque_background` still fails: **cacheAsBitmap pixel snapping**

Residual 3 856 outliers = **1 928 pixels**, and they are *not* background pixels. Runs
along a scanline through each block:

```
y=200   ACT  white 0-34   green 35-130  red 131  green 132-249  white 250-271  green 272-486
        EXP  white 0-35   green 36-131  red 132  green 133-250  white 251-271  green 272-486
x=150   ACT  white 0-58   red 59  green 60-327  red 328
        EXP  white 0-59   red 60  green 61-328  red 329
```

The **right** block (placed by PlaceObject2, `opaqueBackground` set from ActionScript) is
**pixel-exact in both axes**. The **left** block (PlaceObject3 with
`BitmapCache=1` *and* `BackgroundColor=00 FF 00 FF`) is uniformly **1 px right and 1 px
down in Ruffle** — the whole object, its red rules included, not just my rectangle.

That is Ruffle's `PixelSnapping::Always` on the bitmap-cache blit, and the arithmetic
closes exactly:

* `DefineShape4` bounds decode to `x_min = y_min = −10 twips` (`−0.5 px`); the tag's
  matrix is `tx = 720`, `ty = 1200` twips.
* World `x_min = 710 twips = 35.5 px`, `y_min = 1190 twips = 59.5 px`. Un-cached, that
  paints from column 35 / row 59 — which is what we do, and what the right block does.
* Cached: `offset_x = bounds.x_min − matrix.tx = −10 twips`; the offscreen pass draws at
  `tx = −offset_x`, so the content starts at texel 0; the blit goes back at
  `tx = 720 + (−10) = 710 twips = 35.5 px`, and **`PixelSnapping::Always` rounds 35.5 → 36**
  (`display_object.rs:1109`, "cacheAsBitmap forces pixel snapping"). Same for `59.5 → 60`.

**Completion mechanism for P2's AVM1 half (what would flip it):** capture PlaceObject3's
`BitmapCache` byte (currently `swf.cpp:4313`, `cur_pos += 1`) onto the display entry, and
for such an entry translate its world matrix by
`(round(x_min_px) − x_min_px, round(y_min_px) − y_min_px)` before drawing — a dynamic
transform slot plus an `xform_override` push, the machinery `compose_children` already
owns. This is **independent of opaqueBackground** and is almost certainly the owner of the
board's existing `offset_translation` cluster (`visual/cache_as_bitmap/text`,
`visual/cache_as_bitmap/edittext_hscroll`, `text/br_at_start` — 3 comparisons, cluster
yield 1.00) and part of `extra_element` (`cab_mask_alpha`, `cab_mask_transform`). **I did
not implement it**: it is a separate lead with its own A/B surface (the whole
`visual/cache_as_bitmap/*` family), and folding it into an opaqueBackground patch would
have made both unattributable.

### Why `avm2/displayobject_opaque_background` still fails: **10 circle-edge pixels**

Residual 20 outliers = **10 pixels**, every one of them on the *circle's* boundary, none
of them on the background rectangle:

```
(66,5) (133,5) (35,23) (23,35) (5,66) (194,66) (5,133) (66,194)   act blue, exp red
(175,165) (165,175)                                              act red,  exp blue
```

Geometry: the background is a perfect 200×200 blue box; only the red `drawCircle(100,100,100)`
silhouette disagrees, in both directions, at ~10/1250 boundary pixels. Our anchor and
control points are **identical to Ruffle's** — its `UNIT_CIRCLE_POINTS` control is
`(1, tan π/8)`, i.e. the same `r/cos(π/8)`-along-the-bisector point our `gfx_draw_circle`
uses, and both traverse the same eight 45° arcs — and the flattener is already lyon's own
(`curve_flatten.h`, s15). So the residual is sub-chord rasterisation phase, not curve
construction.

**Refutation recorded:** I tested the standing "quantize first" lesson
(`ruffle-geometry-is-integer-twips`) as the explanation — Ruffle's `DrawCommand` points
are integer Twips while ours are float pixels. Rounding every `gfx_add_cmd` coordinate to
integer twips made it **worse: 20 → 28 outliers**. Reverted; the experiment is not in the
patch. Whatever closes this is not path quantization.

**Completion mechanism:** a sub-pixel A/B of the AVM2 fill rasteriser against Ruffle's
lyon+wgpu output at `quality = "low"` (1 sample) — properly the curve/tessellation arc's
work (s15 leg C, HELD), not this brief's.

---

## P5 — the two blank rows, named and graded

`gfx_begin_bitmap_fill` was an explicit no-op that finalised the subpath and set
`cur_fill = 0`. Implemented as a third fill kind routed to the renderer's **existing**
bitmap machinery — `renderer_draw_bitmap_tris`, the same entry point AVM1's
`beginBitmapFill` uses (`tag.c:5762`) — with no new renderer code at all.

Matrix convention verified against Ruffle: `begin_bitmap_fill` stores
`FillStyle::Bitmap { matrix: user_matrix * scale(20,20) }`, i.e. the SWF fill matrix maps
a 20-twips-per-texel bitmap space to shape twips, which reduces to exactly
"bitmap pixel → shape pixel" for the user matrix — the contract
`render_webgpu_draw_bitmap_tris`'s header already documents and AVM1 already feeds.
`repeat` defaults to `true`, `smooth` to `false` (the AS3 declared defaults);
a `null` matrix means identity (Ruffle: "Users can explicitly pass in `null`").

**`smooth` handoff to w2-gfx-vram:** the flag is carried on the fill record
(`Avm2GfxPath.bmp_smooth`) and passed as the existing `smooth` parameter of
`renderer_draw_bitmap_tris`. I add **no** sampler logic and touch **no** line of
`render_webgpu.c`, so the sibling's
`render_webgpu_bitmap_fill_style_word(repeat, smooth)` → `0x40/0x41/0x42/0x43` change
lands entirely inside `render_webgpu_draw_bitmap_tris` (which today does
`(void)smooth;` and emits `0x40/0x41`) and picks my flag up with no merge conflict and no
edit on my side. The two patches touch disjoint files.

### Deliberate divergence: pixels are SNAPSHOT, not referenced

`Avm2GraphicsExt.paths` is a plain `realloc()` array — it is **outside** the region
`avm2_gc.c::conservative_scan` walks (that scans the `native_ext` blob only). An
`Avm2Object*` parked in a path record would be an unrooted, collectable edge, and
`graphics_bitmaps` drops its `BitmapData` locals the moment the constructor returns. So
`beginBitmapFill` copies the pixels. Consequence: a `setPixel` on the source `BitmapData`
*after* the fill is recorded is not reflected (Ruffle re-reads). No corpus test mutates a
bitmap after filling with it. The alternative — a GC root table inside the scanned blob —
is the correct long-term fix if a game ever needs live bitmap fills.

### Why neither row flips

| row | after | what is still missing |
|---|---:|---|
| `avm2/graphics_bitmap_fill` | 76 870 (tol 5 / max_out **60**) | The test draws **four** quadrants. `use_functions`' `beginBitmapFill + drawRect` now renders. `use_functions`' `lineBitmapStyle + drawRect` is still `gfx_line_fill_style`, a no-op stub. **Both** of `use_objects`' quadrants go through `drawGraphicsData`, which in our runtime is **validation-only** — `gfx_draw_graphics_data` (`avm2_display.c:8819`) walks the vector to raise #2004/#2008 and draws nothing at all. So 3 of 4 quadrants are still blank, and this is a `max_outliers 60` row. |
| `avm2/graphics_bitmaps` | 43 013 (best rung tol 32 / max_out **600**) | Three of the six shape groups are `lineBitmapStyle` **strokes**; the fill halves (`simple_shapes_fill`, `logo_fill`) now render. Bitmap strokes need the stroke tessellator to carry a bitmap style, which is a strictly larger change than the fill. |

Both residuals are therefore **owned by two named, separable follow-ons**:
`lineBitmapStyle` (bitmap strokes) and `drawGraphicsData` (an actual draw dispatcher for
`GraphicsBitmapFill` / `GraphicsSolidFill` / `GraphicsGradientFill` / `GraphicsStroke` /
`GraphicsPath`). The second is the bigger prize and is **not** bitmap-specific — it is
currently a no-op for *every* fill kind, so it is a blank-render owner well beyond these
two rows. Recommend it as its own s17 lead.

---

## Patch scope

### `w2-gfx-opaque.patch` — P2 (8 files)

| file | change |
|---|---|
| `SWFModernRuntime/include/libswf/swf.h` | `DisplayObject` **trailing** fields `opaque_bg_set` / `opaque_bg_rgb`. |
| `SWFModernRuntime/include/libswf/tag.h` | `tagSetOpaqueBackground(app_context, depth, set, rgb)` declaration. |
| `SWFModernRuntime/include/actionmodern/action.h` | `MovieClip` **trailing** fields `opaque_bg_set` / `opaque_bg_rgb`. |
| `SWFModernRuntime/include/avm2/avm2_globals.h` | `Avm2DisplayObjectExt` **trailing** fields, same pair. |
| `SWFModernRuntime/src/libswf/tag.c` | new `static opaque_bg_local_bounds()` + `static draw_entry_opaque_background()` (self-contained, inserted immediately above `render_single_object`); one call in each of the three display-list loops (`render_display_list`, `tagRerenderFrame`, `tagShowFrame`), placed before the setMask push; `tagSetOpaqueBackground()` next to `tagSetFilter`. |
| `SWFModernRuntime/src/actionmodern/action.c` | AVM1 `opaqueBackground` getter (next to `cacheAsBitmap` in `actionGetMember`) and setter (next to `scrollRect` in `actionSetMember`), mirroring onto the display entry via `mc->display_obj` with a `resolveMCDisplayEntry` fallback. |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `do_opaquebg_get/set` bodies (descriptor tables **untouched** — w2-all-classes-display owns those); new `static avm2_draw_opaque_background()` above `avm2_render_node`; one call in `avm2_render_node` before the mask push. |
| `SWFRecomp/src/swf.cpp` | PlaceObject3 BackgroundColor: read instead of skip (identical cursor advance), apply Ruffle's `version >= 11` + `alpha > 0` rules, emit `tagSetOpaqueBackground` next to the existing `tagSetFilter` emission. |

### `w2-gfx-bitmapfill.patch` — P5 (1 file, `avm2_display.c` only)

`Avm2GfxPath` + `Avm2GraphicsExt` trailing fields; `gfx_free_path` / `gfx_reset` frees;
a `cur_fill == 3` arm in `gfx_finalize_path`; a real `gfx_begin_bitmap_fill` plus a new
`static gfx_arg_bool`; a `fill_kind == 3` arm in `avm2_render_graphics`.

### Independence, verified

Both patches apply **cleanly and independently** to `cd04f80b9` (`git apply --check`),
compose to exactly the full diff when applied in sequence, and each was **compiled and
run standalone** (P2-only → `avm2/displayobject_opaque_background` PASS; P5-only →
`avm2/graphics_bitmaps` PASS). They may be landed together or separately, in either order.

### Sibling collision check

* `avm2_display.c` descriptor tables (**w2-all-classes-display**): I changed the two
  accessor **bodies**, never `add_getset` or `{ "opaqueBackground", do_opaquebg_get }`.
* `render_webgpu.c` (**w2-gfx-vram** / the filters agent): **not touched at all**.
* Gradient-fill builders in `swf.cpp` / `action.c` / `avm2_display.c`
  (**w2-gfx-gradient**): not touched. My `swf.cpp` hunks are the PlaceObject3
  BackgroundColor field and the post-placement emission block; my `Avm2GfxPath` hunk adds
  fields *above* `fill_verts` and leaves every `grad_*` line untouched.
* `point_transform_native` / geom (**w2-geom**), recompiler flattening: not touched.

---

## Reproduction

```bash
cd .claude/worktrees/agent-a6330478c3868aa5f
cmake -B SWFRecomp/build -DCMAKE_BUILD_TYPE=Release && cmake --build SWFRecomp/build -j4
export DAWN_INSTALL=$HOME/CC/dawn-install SWFRECOMP_COMPILE_TIMEOUT=2400
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/visual \
    --test=opaque_background --mode=graphics --images --verbose --recompile
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
    --test=displayobject_opaque_background --test=graphics_bitmaps --test=graphics_bitmap_fill \
    --mode=graphics --images --verbose --recompile
```

## Board updates recommended

* **P2: GO → IMPLEMENTED, price 0.** Move the two comparisons out of
  `content_displaced` / `same_geometry_wrong_fill`; `visual/opaque_background` now belongs
  in **`offset_translation`** (it is a 1 px cacheAsBitmap snap), and
  `avm2/displayobject_opaque_background` in a curve-edge band (10 px).
* **New lead — cacheAsBitmap `PixelSnapping::Always`.** Named mechanism, closed
  arithmetic, and it already has a cluster: `offset_translation` (yield 1.00, 3 rows) plus
  `visual/opaque_background` and part of `extra_element`. Estimated **+1 to +4**.
* **New lead — `drawGraphicsData` is validation-only.** A blank-render owner for every
  fill kind, not just bitmaps; blocks half of `avm2/graphics_bitmap_fill` today.
* **New lead — `lineBitmapStyle`** (bitmap strokes), blocking the other half of both P5 rows.
* **Refuted:** integer-twips quantization of AVM2 `Graphics` path points (20 → 28 outliers).

### Sibling patch disjointness — verified against the delivered patches

Checked hunk line ranges against the reports dir as of delivery:

* `w2-gfx-vram-smooth.patch` — `render_webgpu.h` + `render_webgpu.c` only. **Zero file
  overlap.** Its `render_webgpu_bitmap_fill_style_word(repeat, smooth)` lands inside
  `render_webgpu_draw_bitmap_tris`, which is the function my P5 patch calls; my
  `bmp_smooth` flag flows into it as the existing `smooth` argument with no edit on
  either side.
* `w2-all-classes-display.patch` — `avm2_globals.h` @894 (function declarations, not the
  `Avm2DisplayObjectExt` struct my hunk extends at @638) and `avm2_display.c`
  @8889–9037 / @13701 / @13854 / @14290 / @14327. My `avm2_display.c` hunks are at
  @7520 / @7540 / @7608 / @7615 / @7771 / @8343 / @10337 / @10348 / @14979 / @15542 /
  @15570. **Disjoint**, nearest gap ~480 lines.
* `w2-gfx-gradient.patch` — `avm2_display.c` @7831 / @8042 (nearest to my @7771 hunk,
  gap ~36 lines, no overlap), `action.c` @28016–28113 (mine: @50607 / @54469),
  `swf.cpp` @7108 / @10012 (mine: @4318 / @4583). **Disjoint.**

No merge order constraint from this agent.
