# wave-1 "gfx-cab-misc" — cacheAsBitmap scoping + three cheap deterministic slices

Session 10, wave 1, READ-ONLY. **Nothing in the repo was modified.** Two tests
(`visual/cache_as_bitmap/{nested_color_transform, color_transform}` and
`visual/cache_as_bitmap/text`) were run locally in `--mode=graphics` purely to
materialise their `Recompiled*` caches so the generated tag/script C could be
read; no source edits, no canary, no CI.

Provenance: board + goldens from the same extract w1-gfx-triage used
(`origin/ruffle-image-results @ d7b5f40e6`, run `30701749687` @ `feb8882b0`),
plus the merged per-suite `_results/image_results_graphics.json` on `master`.

---

## HALF 1 — cacheAsBitmap verdict

### Verdict: **CARRIER, with a small genuine core (7 comparisons) that is an arc, not a sweep.**

Of the 32 live cache_as_bitmap comparisons, **25 fail for reasons that have
nothing to do with bitmap caching** and belong to slices other agents already
own; **7 need a real offscreen cache**, and all 7 need it for exactly one
reason — Ruffle's **alpha-mask** path, which only exists when the object is
cached. There is **no** pixel-snapping arc hiding in here: the CAB-specific
snapping Ruffle does is sub-pixel (≤1 px) and none of the 32 rows is a 1-px
near-pass caused by it.

### What cacheAsBitmap actually changes in Ruffle (the mechanism inventory)

Sourced from `~/CC/ruffle` (`core/src/display_object.rs::render_base` L947-1170
and friends). Only the items that can change a **static screenshot**:

| # | effect | site | can it explain a cab_* failure? |
|---|---|---|---|
| M1 | Mask becomes an **alpha mask** (soft/partial coverage) instead of a 1-bit stencil, when **both** maskee and masker are cached | `get_render_mask` L1979; `render_alpha_mask` `render/src/commands.rs:130` | **YES — this is the whole genuine core** |
| M2 | Cache disabled when the *device-pixel* surface is oversize → M1 silently degrades back to stencil. swf≤9: `w<2880 && h<2880`; swf>9: `w<8191 && h<8191 && w*h<16777215` | `BitmapCache::update` L163-186 | YES — the `oversize/` pair |
| M3 | Filters exist **only** via the cache (filters force the flag on); the cache texture is *grown* to the filter rect so a glow is not clipped | `recheck_cache_as_bitmap` L844; filter rect L988-1005 | YES — `contains_grown_filter` |
| M4 | Blit is translation-only with `PixelSnapping::Always` (tx/ty rounded to whole pixels) | L1094-1112, `render/src/bitmap.rs:86` | ≤1 px. Explains none of our rows |
| M5 | Color transform applied **once to the flattened group** instead of per-child | L1066 vs L1107 | Only visible with overlapping alpha children — not present in any cab_* test here |
| M6 | Scale/rotation/skew go **into** the cache and are re-rasterised on any change (`is_dirty` compares a/b/c/d exactly) — **never** a resampled/blurry rotate | L127, L1063-1073 | No. A correct direct render is pixel-identical |
| M7 | Culling disabled inside the cache; `opaqueBackground` becomes a texture clear | L1081, L1089 | Not exercised here |

The important negative result for planning: **M6 means a correct direct render
of a cached, rotated/scaled object is what Ruffle's own expected PNG shows.**
Caching is invisible in a screenshot except through M1/M2/M3. That is why the
feature is 78 % carrier.

### Per-comparison decomposition (all 32)

**A. Genuine CAB mechanism — 7 comparisons / 7 tests**

| test | cmp | excess | why it needs the cache |
|---|---|---|---|
| `cache_as_bitmap/cab_mask_alpha` | output | 4644 | M1 — golden shows *gradient-faded* tiles; a stencil mask cannot produce partial coverage |
| `cache_as_bitmap/cab_mask_filters` | output | 4968 | M1 + M3 |
| `cache_as_bitmap/cab_mask_transform` | output | 2340 | M1 |
| `cache_as_bitmap/cab_mask_triangle` | output | 5080 | M1 |
| `cache_as_bitmap/oversize/swf_9_masks` | output | 119943 | M1 gated by M2 (see below) |
| `cache_as_bitmap/oversize/swf_10_masks` | output | 119943 | M1 gated by M2 |
| `cache_as_bitmap/contains_grown_filter` | output | 10784 | M3 — 68 % of expected ink missing = the filter-grown region outside the object bounds |

All four `cab_mask_*` are SWF v41 AVM2 and were authored by Ruffle *for* the
alpha-mask feature. Our render paints ~90 % ink where the golden has ~11-22 %
(`extra_ink .78-.90, missing_ink .11`): the mask is not applied at all, so they
also sit inside w1-gfx-triage's mask slice (#1) — but even a correct **stencil**
mask will not flip them, because the goldens contain soft edges.

**B. Carrier — 25 comparisons, already owned by other slices**

| owner slice | members | n |
|---|---|---|
| Mask/clip (#1) | `masks [output.01…07]` | 7 |
| scrollRect | `scroll_rect`, `scroll_rect_scaled` | 2 |
| AVM2 SimpleButton (#4) | `avm2_button`, `avm2_button_state` | 2 |
| EditText layout / selection / scroll | `edittext_selection [.01/.02/.03]`, `edittext_scroll [.01/.02]`, `edittext_hscroll [.01/.02]` | 7 |
| **this report, slice (a)** | `color_transform`, `nested_color_transform` | 2 |
| **this report, slice (b)** | `text` | 1 |
| nested matrix (NEW, see below) | `nested_rotation` | 1 |
| Drawing API | `drawing_api` | 1 |
| lavapipe AA near-pass (unfixable) | `avm1_color` (600 px at thr 8), `morph` (**0 px at thr 8** — pure AA) | 2 |

Proof for the two headline carriers (both AVM1, both flat-colour, both would be
pixel-identical cached or not):

* `nested_color_transform` — ours a flat `(0,0,0)` rect, golden a flat
  `(128,0,0)` rect, identical geometry. The SWF's only non-identity cxform is
  slot 1 = `mult 0.5 / add R=128`; applied **once** to the black shape it gives
  exactly `(128,0,0)`. Caching changes nothing about that arithmetic.
* `color_transform` — golden has two boxes at `(179,179,255)` and
  `(217,217,255)`; ours renders both at 179. `179 = 255·(1−0.30)`,
  `217 = 255·(1−0.30·0.50)`. Both numbers are the plain un-cached composition.

### The `oversize` question — is it its own small mechanism?

**No — it is M1 with a size gate, and it is only 2 comparisons.** But it is the
single cleanest piece of evidence in the whole scoping exercise, so it is worth
recording:

`swf_9_masks` / `swf_10_masks` set `test.width = 2879` / `8190` (both **just
under** their SWF version's cache limit) and then `bg.mask = test`.
Their siblings `swf_9_too_big` / `swf_10_too_big` set `2880` (**at** the swf-9
limit) — identical in every other byte.

```
swf_9_masks      expected: white + blue "CACHED"   ours: solid red   FAIL 119943
swf_10_masks     expected: white + blue "CACHED"   ours: solid red   FAIL 119943   (byte-identical to swf_9_masks on both sides)
swf_9_too_big    expected: solid red               ours: solid red   PASS max_diff 0   (Ruffle known_failure)
swf_10_too_big   expected: solid red               ours: solid red   PASS max_diff 0   (Ruffle known_failure)
```

Structure (from `RecompiledTags/tagMain.c`): depth 7 = DefineText "CACHED"
(blue), depth 9 = sprite `bg` (a 597×448 px red rect covering the 300×200
stage), depth 11 = sprite `test` (204×204 px, scaled to 2879×500 and centred).

So: **under** the limit → cache on → alpha mask → `bg` vanishes entirely and the
blue text underneath shows. **At/over** the limit → cache off → stencil mask →
`bg` fully visible = red. We never cache, so we produce the uncached answer in
all four — which is why we *pass* the two `too_big` tests **for the right
reason** and fail the two `_masks` tests.

Two consequences for planning:
1. `too_big` is a **regression risk** for any future CAB implementation: the
   size gate (`2880` for swf≤9, `8191`/`16777215` for swf>9, measured on the
   *post-filter, post-stage-scale* pixel size) must land in the same change as
   the cache, or those two flip pass→fail.
2. There is nothing "oversize-specific" to take on its own.

### Recommendation

**Do not open a cacheAsBitmap arc this session.** Take the 25 carriers through
their real owners. If a CAB arc is ever opened, its scope is *"offscreen group
rasterisation + alpha masks + filter-rect growth + the two size gates"*, its
realistic yield is **7 comparisons on the current board**, and it is an arc
(offscreen render target, per-object surface allocation, alpha-mask pipeline)
rather than a sweep. It also has a second-order payoff outside this board —
filters currently have no cache to live in — so the natural time to do it is
*with* the Filters arc (`SWFRecompDocs/plans/filters-arc.md`), not standalone.

---

## HALF 2 — the three cheap deterministic slices

### (a) Nested colorTransform — **two independent bugs, 5 comparisons, both fix sites found**

The board's "concatenation-order arithmetic bug" hypothesis is wrong in an
interesting way: the arithmetic helper is already correct. The bug is that the
parent's colour transform is **inherited (replaced) rather than composed** on
the AVM1 side, and **not propagated at all** on the AVM2 side.

#### (a1) AVM1 — `compose_children` inherits instead of composing — 2 cmps

**Fix site: `SWFModernRuntime/src/libswf/tag.c:2852-2890`** (inside
`compose_children`, declared at `tag.c:2754`).

```c
int eff_cx_override = parent_cx_override;
u32 eff_cxform_id   = parent_cxform_id;      // <- child's own obj->cxform_id is DROPPED
...
if (obj->cx_overridden) { build_cxform_from_obj(cx, obj); want_own_cx = 1; }
...
// "(When the parent ALSO carries an override, the child's own slot wins
//  un-composed — the parent slot lives GPU-side so its values can't be read
//  back here. Channel-true parent*child composition stays with the
//  cxform-composition TODO below.)"
```

The code says it: there are exactly two states, *inherit the parent slot* or
*use the child's own slot*, never *compose*. And note the first branch only
fires for `obj->cx_overridden` (an AS `_alpha`/`Color` write) — a **static
PlaceObject cxform on an intermediate sprite** (`obj->has_cxform`) is checked
only at the root call sites (`tag.c:5087, 5118, 5961, 6015`) and is silently
dropped one level down.

Both failures fall straight out:

* `nested_color_transform` — root sprite 3 has cxform 0, so
  `parent_cxform_id = 0`. Its child at depth 1 (sprite 2) is MOVEd on frame 1
  with **cxform slot 1** (`tagPlaceObject2(app_context, 1, 0, 0, 1, 0, 0)`),
  but that is a static cxform, not `cx_overridden`, so `eff_cxform_id` stays 0
  and the leaf shape draws with identity → `(0,0,0)` instead of `(128,0,0)`.
* `color_transform` — `box._alpha = 30` sets `cx_overridden` on the root entry,
  so `parent_cxform_id` = a fresh 0.30-alpha slot. Its child at depth 2 carries
  a static cxform slot 1 (`alpha 0.5`) and is **not** `cx_overridden`, so the
  0.30 slot *replaces* the 0.5 → we draw 0.30 where Flash draws 0.30·0.50 =
  0.15. That is exactly the observed uniform `[-38,-38,0]` (179 vs 217).

**Fix shape.** `compose_cxform20()` already exists at `tag.c:3144` and is
already Ruffle-correct (`out.mult = outer.mult × inner.mult`,
`out.add = outer.mult × inner.add + outer.add`) — it is currently used at only
one call site (DefineText placement-over-baked, `tag.c:3292`). Thread a
CPU-side `const float parent_cx[20]` down `compose_children` **alongside** the
existing `parent_composed[16]` (same shape, same recursion), compose it with
the child's own cxform (static `cxform_data[obj->cxform_id*20]` or
`build_cxform_from_obj` when `cx_overridden`), and write the result to a fresh
dynamic slot. Passing the values rather than the slot id removes the "lives
GPU-side, can't read back" blocker the comment cites. Root call sites at
`tag.c:5087/5118/5961/6015` seed it from `cxform_data[obj->cxform_id*20]`;
`tag.c:5285/5490` seed identity.

Predicted flips: **2** (`cache_as_bitmap/color_transform`,
`cache_as_bitmap/nested_color_transform`), both tolerance 0, both uniform-fill,
both should land exactly (our current values already round the way the golden
does: `255·0.7 = 178.5 → 179` matches).

#### (a2) AVM2 — RGB colour transform never reaches the renderer at all — 3 cmps

`avm2/displayobject_colortransform_nested [output.1/.2/.3]`: golden is a flat
`(255,0,0)`, we render a flat `(204,204,204)` (= `0xCCCCCC`, the untouched
shape). `Test.as` does `ct.color = 0xFF0000; outer.inner.transform.colorTransform = ct`
→ mult 0/0/0, add R 255; applied once to `0xCCCCCC` that is exactly
`(255,0,0)`. The SWF has a single identity cxform slot, so *nothing* about
parent/child ordering is involved — the transform is simply not rendered.

**Fix sites (all in `SWFModernRuntime/src/avm2/avm2_display.c`):**

* `transform_set_color_transform` (**9613**) correctly stores
  `ext->cx_rm/gm/bm`, `alpha_fixed8`, `cx_ra/ga/ba/aa`; PlaceObject also stores
  them at **1674-1678**.
* **Nothing reads `cx_rm/cx_gm/cx_bm/cx_ra/cx_ga/cx_ba` back on the render
  path.** `grep cx_rm` returns only the setter, the getter (9596) and the
  PlaceObject writer. The two render walks propagate alpha only:
  `avm2_render_node` (**14341**, alpha at **14350**, recursion **14371**, root
  **14404**) and its CPU twin `avm2_cpu_walk` (**13769**, alpha at **13779**).
* All five cxform-slot writers hard-code an alpha-only matrix —
  **13975-13982, 14016-14025, 14090-14097, 14158-14165, 14221-14228**:
  ```c
  cx[0] = 1.0f; cx[5] = 1.0f; cx[10] = 1.0f;  // r/g/b multiply = 1
  cx[15] = (float) alpha;                      // alpha multiply
  ```

**Fix shape.** Replace the `double parent_alpha` parameter of
`avm2_render_node` / `avm2_cpu_walk` with a 20-float concatenated cxform (or a
small `{float mult[4]; float add[4];}` struct), compose the node's own
`cx_*` into it with the same Ruffle rule, and have the five writers emit the
full matrix. Keep the `alpha < 0.999` fast-path condition but widen it to "is
the concatenated cxform non-identity". The GPU side already supports it —
`apply_cxform` in `render_webgpu.c:189-194` is a full `mat4 mult + vec4 add`.
The CPU twin (`avm2_cpu_raster_shape` / `avm2_cpu_composite_bitmap`) takes an
`alpha` scalar today and would need the same widening for headless/BitmapData.draw
parity; the graphics-mode image tests only need the GPU path.

Predicted flips: **3**, all tolerance 0, all uniform full-frame fills → exact.

**Slice (a) total predicted flip: 5** (board estimated 3-4).

Adjacent lead for the same owner, *not* counted above:
`cache_as_bitmap/nested_rotation` (1 cmp, `same_geometry_wrong_fill`, 25 665) is
the **matrix twin** of `nested_color_transform`: dark-ink bbox ours
`(75,83)-(266,208)` (axis-aligned, exactly the shape's natural 192×126) vs
golden `(53,83)-(263,239)` (a rotated bbox). Same test family, same "MOVE a
nested sprite placement on frame 1" shape. Worth a look once the cxform path is
threaded, since the matrix path is right next to it.

---

### (b) "Pure translation offsets" — the cluster is **three different bugs, and one of the four is a misclassification**

Re-measured each with a ±20 px, 1-px-granularity search plus ink-bbox
comparison (the board's probe is 2-px granularity capped at ±8, which saturated
on two of these). Sign convention: **+dy = our content sits dy px lower than
the golden.**

| test | board | measured | what it really is |
|---|---|---|---|
| `visual/cache_as_bitmap/text` | dy8 | **+8 y, 0 x, both text bands** | EditText baseline one *descent* too low |
| `from_shumway/acid/acid-text-x` | dy6 | **+6 y, 0 x** | static-text vertical origin; trace is `ruffle_matched` on a Ruffle `known_failure` |
| `text/br_at_start` | dy2 dx2 | **field box +2 y +2 x; text +101 y (3 line advances) too HIGH** | two bugs; not a translation |
| `visual/cache_as_bitmap/edittext_hscroll [.02]` | dy−8 dx8 | **not a shift at all** | hscroll not applied |

**b1 — `cache_as_bitmap/text` (+8 y). Best single candidate.**
Two EditTexts, both `Times New Roman` → Noto Sans, `size="29"` (font height 580
twips = 29 px), `tagDefineFontMetrics(1, ascent 21893, descent 6000, leading 0, em 20480)`.
Ink bands: ours `(64,85)` + `(183,211)`, golden `(56,77)` + `(175,203)` — band
*heights* identical (21 / 28; the 28 is "Updated text" with a `p` descender, so
both fields are the same size), inter-band gap identical (119), and **both
bands off by exactly 8**. `descent/em × size = 6000/20480 × 29 = 8.50 px`.
→ **we place the first baseline at `ascent + descent` instead of `ascent`.**
Budget: 8910 outliers vs `max_outliers 1500` at `tolerance 128`; removing an
8-px whole-field offset should take the residual to glyph-AA level. Predicted
flip: 1 (medium confidence — device-font rasterisation differences remain, and
the test's own toml warns about exactly that).

**b2 — `acid-text-x` (+6 y).** Static DefineText, three `X` glyphs, ink band
ours `36..108`, golden `30..102`, height 72 in both. Same *class* of bug
(vertical text origin) but **not the same quantity** — 6 px on a ~100 px cap
height is not a descent. Its trace is `known_failure = true` upstream
(golden trace `168`, Ruffle `167.95` — a text-`_width` metric) and our trace
status is `ruffle_matched`, i.e. this test is measuring text metrics that we
already know disagree. Image tolerance is 0 with 12 591 outliers. **Low
confidence, take last.**

**b3 — `text/br_at_start` — two real bugs, neither a translation.**
htmlText is `"<br/><br/><br/><font color='#FF0000'>red</font> and …"`.
Row profile: field border ours rows `10` / `390`, golden `8` / `388`; ink bbox
ours `(20,10)-(535,390)` vs golden `(18,8)-(533,388)` → **the whole field box is
+2 px in both axes**. Separately, the text band is ours `76..95`, golden
`177..197` → the golden puts the text **101 px lower**, i.e. exactly 3 more line
advances at ~33.7 px (`3L = 101`). So the leading `<br/>` runs are being
collapsed: we emit 3 fewer line breaks than Flash before the first glyph.
Budget `tolerance 128 / max_outliers 8`, currently 14 419 — both bugs must land.
Predicted flip: 1, but it is a *text-layout* task, not a translation task —
**re-file it under the text agent, not under this cluster.**

**b4 — `cache_as_bitmap/edittext_hscroll [output.02]` is a misclassification.**
The image is 40×24; the `offset_translation` verdict is a small-image artefact
(12 vs 80 differing pixels). Ink bbox ours `(2,2)-(39,21)`, golden
`(2,18)-(39,21)`: the golden shows the field **scrolled so the text is gone**
and only the bottom strip remains, we still draw the whole text block. That is
"`hscroll` not applied", i.e. the EditText scroll slice — same owner as
`edittext_scroll [.01/.02]`. `[output.01]` (96 outliers) is a different thing
again: the golden has a **magenta caret bar** at the right edge of the text
block that we do not draw.

**Slice (b) revised routing:** it is not a slice. `b1` (+8 descent) is the only
piece that stands alone; `b3` goes to the text/HTML-layout owner, `b4` goes to
the EditText-scroll owner, `b2` is a low-confidence single.

---

### (c) `visual/scale_rotation_cache [output.15/.25/.35]` — **root-caused, 3 flips, one-line-ish fix**

Test (`test.as`, AVM1, 320×320, 10 fps, 50 frames):
`img_mc` = `createEmptyMovieClip` + `MovieClipLoader.loadClip("dots.png")`, `_x=160`;
`bmd_mc` = `createEmptyMovieClip` + `attachBitmap(new BitmapData(128,128,…))`, `_x=160,_y=160`.
Then `_xscale = -100` on each at t = 1000/1100, 2000/2100, 3000/3100 ms.

Measured, and it is unusually clean:

```
expected output.5   ink bbox x 160..287     (unflipped)     -> WE PASS
expected output.15  ink bbox x  32..159     (flipped about x=160)
expected .15 == expected .25 == expected .35   (0 differing px)
our      .15 == our .25 == our .35 == expected output.5     (0 differing px)
```

So **`_xscale = -100` has literally no effect on our render**, for both clips,
for all three frames. The trace passes (the `_xscale` / `_rotation` /
`transform.matrix` getters all report the flip correctly) — it is purely a
render-path drop.

**Fix site: `SWFModernRuntime/src/libswf/tag.c:4965`**

```c
static void attached_bitmap_render_cb(const AttachedBitmapInfo* info, void* user_data)
{
    (void)user_data;
    renderer_draw_bitmap_quad(context, info->pixels, info->width, info->height,
        info->x_twips, info->y_twips, 0, 0);   /* transform_id = 0, cxform_id = 0 */
}
```

and its feeder **`SWFModernRuntime/src/actionmodern/action.c:28460-28481`**
(`actionIterateAttachedBitmaps`), which fills the info struct with

```c
info.x_twips = mc->x * 20.0f;
info.y_twips = mc->y * 20.0f;
```

`AttachedBitmapInfo` (`include/actionmodern/action.h:648-654`) carries **only**
pixels/width/height/x/y. So every attached or loaded bitmap on a dynamic MC is
drawn with a hard-coded identity transform and identity cxform, positioned by
baking `mc->x/mc->y` into the quad. `_xscale`, `_yscale`, `_rotation`,
`transform.matrix`, `_alpha` and any parent transform are all discarded. This
covers both clips in the test: `MovieClipLoader`-loaded images go through
`decodeAndAttachImageToMC` → `mc->attached_bitmap_pixels`
(`action.c:23711-23725`), i.e. the same callback.

**Fix shape.** The machinery already exists: `apply_dynamic_mc_transforms`
(`tag.c:2647-2683`) already walks `child_mc_cache`, allocates a per-tick GPU
slot, calls `apply_as_transform(xform, mc, 1|2|4|8|16)` (which handles negative
scale correctly — `slot[0] = sx*cos(r)`) and stashes it in
`mc->dynamic_xform_slot`. Add `dynamic_xform_slot` (and an alpha cxform slot) to
`AttachedBitmapInfo`, and have the callback call
`renderer_draw_bitmap_quad_scaled(..., 0.0f, 0.0f, info->xform_slot, info->cx_slot)`
— drawing at local origin instead of baking x/y into twips. Guard: when
`mc->as_set_flags == 0` no slot is allocated, so keep the existing
`x_twips/y_twips` path for that case so nothing that passes today moves.

Predicted flips: **3** (`output.15/.25/.35`, tolerance 0, 118 784 outliers each,
and our frame-5 render is already byte-exact so the geometry is right).

**Blast radius / canary note.** This callback is the render path for *every*
`attachBitmap` and `loadMovie`-of-an-image clip, so it is wider than three
comparisons. `render_canary.py` before/after is mandatory, and the trace-side
stash-diff sweep should include the `regression` suite plus any
`attachBitmap`/`loadClip` tests.

---

## Wave-2 briefs (implementation-ready)

### BRIEF W2-A — "cxform composition, both VMs" · predicted **+5** (stretch +6)
* **W2-A1 (AVM1, +2).** `tag.c` `compose_children` (decl 2754, bug 2852-2890):
  thread `const float parent_cx[20]` next to the existing `parent_composed[16]`;
  compose with the child's own cxform via the existing correct
  `compose_cxform20` (3144); write to a fresh dynamic slot. Seed from
  `cxform_data[obj->cxform_id*20]` at 5087 / 5118 / 5961 / 6015, identity at
  5285 / 5490. Delete the two TODO comments while you are there.
  Targets: `visual/cache_as_bitmap/{color_transform, nested_color_transform}`.
* **W2-A2 (AVM2, +3).** `avm2_display.c`: widen `avm2_render_node` (14341) and
  `avm2_cpu_walk` (13769) from `double parent_alpha` to a concatenated cxform;
  emit the full 20-float matrix at the five writers (13975, 14016, 14090,
  14158, 14221) instead of the hard-coded `mult = 1 / alpha` form. Consume
  `ext->cx_rm/gm/bm/ra/ga/ba/aa` (set at 1674 and 9635). Shader already
  supports it (`render_webgpu.c:189`).
  Target: `avm2/displayobject_colortransform_nested [.1/.2/.3]`.
* **Stretch (+1).** `cache_as_bitmap/nested_rotation` — the matrix twin; same
  "MOVE on a nested sprite placement" shape.
* Risk: cxform composition touches every nested clip with a tint/alpha. Full
  `render_canary.py` double leg + trace stash-diff sweep including `regression`.

### BRIEF W2-C — "dynamic-MC attached-bitmap transform" · predicted **+3**
* Extend `AttachedBitmapInfo` (`action.h:648`) with a transform slot and a
  cxform slot; fill from `mc->dynamic_xform_slot` in
  `actionIterateAttachedBitmaps` (`action.c:28460`); switch
  `attached_bitmap_render_cb` (`tag.c:4965`) to
  `renderer_draw_bitmap_quad_scaled(..., 0, 0, xform_slot, cx_slot)`.
  Keep the x/y-twips path when `mc->as_set_flags == 0`.
* Target: `visual/scale_rotation_cache [output.15/.25/.35]`.
* Wide blast radius (all `attachBitmap` / image-`loadMovie` rendering) — canary
  is not optional.

### BRIEF W2-B1 — "EditText first-baseline is one descent too low" · predicted **+1**
* `visual/cache_as_bitmap/text`: both fields exactly +8 px =
  `descent/em × size = 6000/20480 × 29`. Find the EditText first-line baseline
  computation and check whether it adds `descent` on top of `ascent`.
* Medium confidence (budget `max_outliers 1500 @ tolerance 128`, currently 8910;
  device-font raster differences remain).
* **Re-file, do not bundle:** `text/br_at_start` (leading `<br/>` runs collapsed
  — 3 missing line advances — *plus* a +2/+2 field-box origin offset) belongs to
  the text/HTML-layout owner; `cache_as_bitmap/edittext_hscroll [.02]` (hscroll
  not applied) and `[.01]` (missing magenta caret) belong to the EditText-scroll
  owner; `from_shumway/acid/acid-text-x` (+6 y, `ruffle_matched` trace on a
  Ruffle `known_failure`, tolerance 0) is a low-confidence single — take last or
  not at all.

### NOT RECOMMENDED THIS SESSION — cacheAsBitmap arc
7 comparisons, all requiring offscreen group rasterisation + an alpha-mask
pipeline + filter-rect growth + the two size gates. Natural pairing is the
Filters arc, not a standalone sweep. Any implementation **must** ship the size
gates in the same change or `oversize/swf_{9,10}_too_big` regress pass→fail.

---

## Board-hygiene notes for the coordinator

1. `offset_translation` is not a mechanism cluster here — 2 of its 4 members are
   not translations at all. The `best_shift` probe (2-px granularity, ±8 px cap,
   `image_triage.py:180`) saturates on ≥8-px offsets and produces junk verdicts
   on images smaller than ~60 px. Worth a note in the playbook.
2. `visual/cache_as_bitmap/morph` has **zero** differing pixels at threshold 8
   (2832 outliers at tolerance 0) — it is pure lavapipe AA and should be
   considered for the near-pass/unfixable list rather than left rankable.
3. `visual/cache_as_bitmap/oversize/swf_{9,10}_too_big` currently pass **for the
   right reason**, which makes them a useful standing canary for any future CAB
   work — record them as such.
