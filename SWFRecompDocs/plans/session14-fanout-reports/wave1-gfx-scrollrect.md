# wave1-gfx-scrollRect — the AVM1 `scrollRect` path (PIXEL axis)

Session 14, wave 1. **Read-only diagnosis. No source edits, no commits, no
stash, no full suites.** Baseline: CI run `31130292354` at `fb36ba110`
(graphics / full / images=true), results merged at `e62ab7471`. HEAD `0a99be1a9`
(one ungraded runtime-only commit, AVM2 Math.random state — cannot touch this).

Scratch (probe artefacts, PNGs, sims):
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/51dca5de-f4b8-4d85-ad88-d07fc0624450/scratchpad/gfx-scrollrect/`

---

## 1. Headline

| | |
|---|---|
| brief's premise | **CONFIRMED, with one correction** — the residual is a missing scrollRect **translate**, geometrically exact. It is NOT stencil intersection, so no refutation hand-off to `gfx-stencil`. |
| the correction | The brief says "s13's defect C landed the AVM2 crop side; AVM1 is missing the translate half." In fact **AVM1 `scrollRect` is entirely inert** — an undefined-valued stub property on `MovieClip.prototype` (`action.c:15725`), no storage, no getter, no setter, no render effect. Both halves are missing. |
| the second correction | For `scroll_rect_mask` specifically, the crop half must be **SUPPRESSED, not added** — Ruffle discards nested maskers, and the golden proves it (§3). Porting s13's AVM2 gate verbatim (`g_avm2_mask_capture == 0` → skips BOTH crop and translate) yields **zero movement** on this test. The translate is unconditional; only the crop is gated. |
| family | 3 failing pixel comparisons, all AVM1, all `DoAction`-driven, **all three go through the same code path** (`render_display_list`) |
| predicted, priced honestly | **+1 flip** (`cache_as_bitmap/scroll_rect_scaled`), **2 large band moves** (`scroll_rect_mask` 11310→**42**, `cache_as_bitmap/scroll_rect` 18378→**~1478**). Both band residuals are *other* mechanisms, measured and attributed. |
| CI-fidelity | **Local Dawn render is byte-identical (md5) to the CI actual PNG for all three tests.** Local grading is CI-grade for this whole family — wave 2 can read its flip off a local run. |
| verdict | **GO.** Runtime-only, ~110 lines across 2 files, blast radius = 3 pixel comparisons + 6 named trace canaries. |

---

## 2. The three comparisons (baseline numbers, run `31130292354`)

| comparison | excess | tol / max_out | quality | AVM |
|---|---:|---|---|---|
| `visual/simple_shapes/scroll_rect_mask [output]` | 11310 | 0 / 0 | low (MSAA 1) | AVM1 |
| `visual/cache_as_bitmap/scroll_rect [output]` | 18378 | 1 / 0 | low (MSAA 1) | AVM1 |
| `visual/cache_as_bitmap/scroll_rect_scaled [output]` | 40946 | two checks: 0/2800 **and** 64/900 | high (MSAA 4) | AVM1 |

Trace status of all three: **pass** (0–2 lines each). No image-axis or global
disposition covers any of them (`ignored_tests.txt`, ACCEPTED_DIFFS,
RUFFLE_VS_FLASH_DIFFERENCES all checked — the only scrollRect entries are
`avm2/displayobject_scrollrect` in the **avm2 suite-local** list (soft) and two
prose mentions in avm1 ACCEPTED_DIFFS that explicitly say defect C *cannot*
reach `simple_shapes/masks`).

Not in this family (checked and excluded): `cache_as_bitmap/edittext_{h,}scroll`
(TextField.scroll, not scrollRect), `avm2/displayobject_scrollrect` and
`visual/avm2_button_scroll_rect` (AVM2, s13's defect C — **canaries**, §7),
`from_shumway/acid/acid-textfield-scroll` (passing).

### 2.1 Corpus sweep for AVM1 scrollRect users

Decompressed every `test.swf` in the corpus and grepped for the literal
`scrollRect` (`scratchpad/gfx-scrollrect/scan.py`): **42 hits, of which 7 are
AVM1** — the 3 pixel tests above plus 4 trace tests that only *read* or probe
the property (`avm1/movieclip_default_state`,
`avm1/movieclip_library_state_values`, `avm1/movieclip_state_values`,
`from_gnash/actionscript.all/MovieClip-v5..v8`). Everything else is AVM2.
**Blast radius is fully enumerated.**

---

## 3. What the golden actually says (the oracle)

`visual/simple_shapes/scroll_rect_mask`, decompiled from `RecompiledScripts`:

```as
mask.circle.scrollRect = new flash.geom.Rectangle(10, 10, 100, 100);
clip.setMask(mask);          // ActionCallMethod: obj=clip, arg0=mask
```

Display list (`scratchpad/gfx-scrollrect/swfdump.py`):

```
shape 1 = 550x400 full-stage red/blue content
sprite 2 "clip"  <- shape 1 at (0,0)          placed depth 1 at (0,0)
shape 3 = 200x200 circle
sprite 4          <- shape 3 at (0,0)
sprite 5 "mask"   <- sprite 4 named "circle" at (0,0)   placed depth 3 at (200,100) px
```

Measured delta, CI actual vs golden:

| | actual | expected |
|---|---|---|
| visible disc bbox | `x[200,399] y[100,299]` | `x[190,389] y[90,289]` |
| disc area (px) | 31517 | 31506 |

A **complete** 200 px disc in both, displaced by exactly **(−10, −10)** — the
scrollRect origin. The crop (a 100×100 window on a 200 px disc) is **absent from
the golden**: the disc is whole (π·100² = 31416 ≈ 31506) and the crop-rect corner
region at stage (200,100) is white in the golden.

**Why**, from Ruffle (`~/CC/ruffle`, authoritative):

* `core/src/display_object.rs:1166` `apply_standard_mask_and_scroll` pushes the
  scroll **translate** onto `transform_stack` unconditionally (line 1189), then
  pushes the **crop** as `push_mask` + `draw_rect` + `activate_mask` (line 1225).
* `core/src/render/commands.rs:47`:
  ```rust
  /// The number of mask regions in the process of being drawn.
  /// This is used to discard drawing commands of nested maskers, which Flash does not support.
  maskers_in_progress: u32,
  ```
  `push_mask` emits `Command::PushMask` only at depth 0 (line 161-166), and every
  draw command is recorded only `if self.maskers_in_progress <= 1`.

So while the masker `mask` is being rasterised into the stencil
(`maskers_in_progress == 1`), the `circle` child's scrollRect **crop** push is a
no-op and its `draw_rect` is discarded, while the **translate** — a transform
stack push, not a command — still applies. Result: silhouette = whole disc,
shifted by (−10,−10). Exactly the golden. Ruffle's own comment says Flash does
not support nested maskers, so this is Flash behaviour, not a Ruffle quirk.

**Our equivalent already exists**: `tag.c:3135 g_clip_mask_capture`, incremented
by `draw_mc_mask_geometry` around the masker subtree walk (`tag.c:5523`), with
the precedent one line of code needs at `tag.c:4987`:
```c
int has_clip = (mask_w > 0.0f && mask_h > 0.0f) && !g_clip_mask_capture;
```
(the EditText field-bounds nested clip, suppressed inside a capture "which
Ruffle's renderer ignores inside a capture").

### 3.1 The other two, decompiled

```as
// visual/cache_as_bitmap/scroll_rect   (DoAction inside sprite 4, frame 2)
a.scrollRect = new flash.geom.Rectangle(100, 50, a._width, a._height);   // a = inner sprite 3
stop();
// visual/cache_as_bitmap/scroll_rect_scaled
outer.inner.scrollRect = new flash.geom.Rectangle(10, 10, 100, 100);
```

Both need **crop + translate** (no enclosing mask). Geometry, verified against
the goldens to the pixel:

* `scroll_rect`: `a` = 150×143.95 cyan box at stage (179,117); translate
  (−100,−50) px, crop 150×144 at (179,117) → visible **50×94 at (179,117)** =
  the golden's cyan bbox `x[179,228] y[117,210]` **exactly**.
* `scroll_rect_scaled`: `outer` at scale 2, tx=250 twips; `inner` at (209,209)
  twips inside it ⇒ inner's origin = **(668,668) twips = 33.4 px**; crop 100×100
  local = 200×200 stage; translate (−10,−10) local = (−20,−20) stage. Golden's
  content bbox is `(33,33)-(232,232)` = 200×200 — the crop window, fully filled.

---

## 4. Why AVM1 does nothing today (end-to-end trace)

1. **Property set site.** `mask.circle.scrollRect = rect` reaches
   `actionSetMember` (`action.c:48144`). Its MovieClip named-property dispatch
   (`blendMode` at `49868`, `filters` at `49915`) has **no `scrollRect` arm**, so
   the assignment falls through to a generic dynamic property store.
2. **The only `scrollRect` in the AVM1 runtime** is `action.c:15725`, the
   `extra_props[10]` block that installs `scrollRect` on `MovieClip.prototype`
   as an *undefined-valued own property* purely so `hasOwnProperty` probes and
   the `movieclip_*_state` enumerations behave. `grep -c scrollRect
   SWFModernRuntime/src/actionmodern/ = 1`.
3. **No storage.** `struct MovieClip` (`include/actionmodern/action.h:28`) and
   `struct DisplayObject` (`include/libswf/swf.h:125`) both have no scroll-rect
   fields.
4. **No renderer read.** The three AVM1 display-list walks
   (`render_display_list` `tag.c:3448`, the `tagRerenderFrame` loop `~5810`, the
   `tagShowFrame` loop `~6750`) and `compose_children` (`tag.c:2795`) contain
   zero scroll-rect logic.

### 4.1 The AVM2 path s13 landed, for comparison

`avm2_display.c`: storage `has_scroll_rect` + `sr_{x,y}{min,max}` on
`Avm2DisplayObjectExt` (`avm2_globals.h:517`), accessors `do_scrollrect_get/set`
(`10312`/`10323`, half-to-even pixel rounding at `10304`), crop helper
`avm2_push_scroll_rect_mask` (`15464`), and the render block at `15547`:

```c
if (ext->has_scroll_rect && g_avm2_mask_capture == 0)
{
        saved_sr_ref = renderer_clip_ref(context);
        avm2_push_scroll_rect_mask(&world, ext);   // crop, PRE-translate world
        pushed_scroll_rect = 1;
        Mat sr_tr = { 1,0,0,1, -(double) ext->sr_xmin, -(double) ext->sr_ymin };
        world = mat_mul(&world, &sr_tr);           // scroll, content + subtree
}
```

**Latent AVM2 divergence found while reading this** (out of scope, no test
covers it, but record it): the AVM2 gate suppresses the **translate** as well as
the crop inside a mask capture. Ruffle suppresses only the crop. An AVM2
scrollRect'd object *inside* a mask would render its silhouette unshifted. If
`gfx-stencil` or a later AVM2 mask agent touches `avm2_render_node`, the
one-line fix is to move `world = mat_mul(&world, &sr_tr)` outside the
`g_avm2_mask_capture == 0` guard.

The structural difference that stops a copy-paste: AVM2 is an immediate-mode
walk carrying a `Mat world`; the AVM1 walk draws from **pre-baked transform
slots** (`obj->transform_id`) computed by `compose_children` before the render
pass. So the AVM1 translate belongs in `compose_children`, and the crop needs a
matrix slot allocated there too.

---

## 5. Implementation plan (wave-2 ready)

Two files, runtime only. No recompiler change ⇒ no `--recompile` needed for a
worktree that copies `SWFRecomp/build` (but test-dir copies still need it on
first use per the s10 trap).

### 5.1 `SWFModernRuntime/src/actionmodern/action.c` — storage + accessors

**A. Storage.** `include/actionmodern/action.h:28` `struct MovieClip`, next to
`blend_mode`/`lockroot`:
```c
u8  has_scroll_rect;                       /* 0 = unset */
s32 sr_xmin, sr_ymin, sr_xmax, sr_ymax;    /* twips, whole-pixel-rounded */
```

**B. Setter** — new arm in `actionSetMember` (`48144`), immediately after the
`blendMode` arm at **`49868`** and before `filters` at `49915`. Mirror Ruffle
`core/src/avm1/globals/movie_clip.rs:181 set_scroll_rect` and s13's AVM2
`do_scrollrect_set` (`avm2_display.c:10323`) verbatim:

```
if value is an OBJECT:
    mc->has_scroll_rect = 1;
    read x,y,width,height via getPropertyWithPrototype (skip the write if any is missing,
      matching Ruffle's `if let Some(rect) = object_to_rectangle` — has_scroll_rect
      is still set to 1 in that case)
    sr_xmin = (s32) round_half_to_even(x)       * 20;
    sr_ymin = (s32) round_half_to_even(y)       * 20;
    sr_xmax = (s32) round_half_to_even(x + w)   * 20;
    sr_ymax = (s32) round_half_to_even(y + h)   * 20;
else:
    mc->has_scroll_rect = 0;
return;   // do NOT fall through to the dynamic-property store
```
`round_half_to_even` is `nearbyint` under the default `FE_TONEAREST`; copy the
6-line helper from `avm2_display.c:10304` rather than re-deriving it. **This
rounding is load-bearing** — `scroll_rect`'s height arrives as `143.95` and must
become 144 twip-pixels, and the golden's 94 px visible band depends on it.

**C. Getter** — new arm in `actionGetMember` (`52168`), beside `blendMode`
(`53749`) / `cacheAsBitmap` (`53766`) / `filters` (`53771`):
```
if (!mc->has_scroll_rect) -> fall through (yields the prototype's `undefined`)
else PUSH createRectObj(app_context, x, y, w, h)   /* decl at action.c:8353 */
```
Ruffle returns a **new** Rectangle each read from the *uncommitted* rect; ours
has one rect so this is trivially the same.

**D. Do NOT touch `extra_props[10]` at `action.c:15725`.** `scrollRect` must stay
an own property of `MovieClip.prototype` — `from_gnash/.../MovieClip-v5` asserts
`PASSED: MovieClip.prototype.hasOwnProperty("scrollRect")` (its `output.txt:27`),
and `movieclip_default_state`/`library_state_values` print
`scrollRect = undefined` from the enumeration. The `blendMode` arm is the exact
precedent: prototype stub **and** a real instance-level accessor pair.

**E. Do NOT wire `getBounds` / `localToGlobal` / `hitTest`.** Ruffle does
(`display_object.rs:1392` bounds override, `:1508` local_to_global) but *no AVM1
corpus test observes it*, and all three `movieclip_*_state` tests are at 100 %.
The AVM2 trace half (`displayobject_scrollrect`, 19/33 lines, needs Ruffle's
`pre_render` commit delay — `display_object.rs:2429`) is a separate, unowned
lead. **Leave it.**

### 5.2 `SWFModernRuntime/src/libswf/tag.c` — translate + crop

`compose_children` and `render_display_list` are both inside `#ifndef NO_GRAPHICS`
(`2489 … 3672`), so this half is graphics-only.

**F. Entry → MovieClip resolution.** The scrolled entries here are *nested*
sprites (`mask.circle`, `outer.inner`, `a`), whose `mc->display_obj` may be NULL
(the `edittext-wrapper-no-display-obj-invalidate` class). **Reuse s13 defect B's
registry pattern verbatim**: `action.c:28698 actionAvm1MaskPairCount()` /
`28703 actionAvm1GetMaskPairs()` + `tag.c:3164 avm1_mc_owns_entry()` (which
already falls back to instance-name matching). Add the twin pair
`actionAvm1ScrollRectCount()` / `actionAvm1GetScrollRects(void** mcs,
Avm1ScrollRect* rects, int max)` with the same liveness filter, declared beside
`action.h:665`. **The count check is the zero-cost early-out for every movie in
the corpus that never sets a scrollRect** — mandatory, `compose_children` is on
the hot per-frame path.

**G. The translate — `compose_children`, at `tag.c:2871`.** Immediately after
```c
hit_test_mat4_multiply(composed, parent_composed, local_xform);
```
and **before** the dynamic-slot allocation at `2874`:

```c
u32 crop_slot = 0;
if (scroll_registry_non_empty && entry_has_scroll_rect(obj, &sr))
{
    /* crop matrix = the PRE-translate world (Ruffle display_object.rs:1174-1186:
       "Note that we do *not* apply the translation yet") */
    if (g_next_dynamic_xform_slot < g_xform_slot_capacity) {
        crop_slot = g_next_dynamic_xform_slot++;
        renderer_write_transform(context, crop_slot, composed);
    }
    float tr[16] = IDENTITY; tr[12] = -(float) sr.xmin; tr[13] = -(float) sr.ymin;
    float scrolled[16];
    hit_test_mat4_multiply(scrolled, composed, tr);
    memcpy(composed, scrolled, sizeof scrolled);
}
record_crop_slot(obj, crop_slot);   /* per-frame side table, §H */
```

Translation units in this table are **twips** (`apply_as_transform` at
`tag.c:2626`: `slot[12] = rintf(mc->x * 20.0f)`), so `sr.xmin/ymin` go in
unscaled. Because the write happens before `2874`, the entry's own slot **and**
the `parent_composed` handed to the `CHAR_TYPE_SPRITE` recursion (`~3040`) and
the `CHAR_TYPE_BUTTON` recursion (`~3089`) both carry the scroll — content and
subtree, exactly Ruffle's `transform_stack.push` scope. **The translate is
unconditional** (no `g_clip_mask_capture` gate) — that is what makes
`scroll_rect_mask` move.

**H. Crop-slot side table.** A file-static in `tag.c`, rebuilt every frame:
```c
static struct { DisplayObject* obj; u32 slot; } g_scroll_crop[64];
static int g_scroll_crop_count;
```
cleared wherever `g_next_dynamic_xform_slot` is reset (`tag.c:5631` and `6500`).
Preferred over a new `DisplayObject` field: zero header churn, and the lifetime
is naturally per-frame so a recycled display-list slot can't carry a stale id.

**I. The crop — `render_display_list` (`tag.c:3448`).** Inside the per-entry
loop, push **after** the setMask push at `3587` (Ruffle's order: the
`DisplayObject.mask` stencil first, scrollRect "in addition to" it —
`display_object.rs:1214-1223`; with our flat Replace stencil the later push
wins, which is what Ruffle's command order produces) and restore **before**
`renderer_restore_clip(context, avm1_mask_saved_clip)` at `3667`:

```c
u32 sr_saved = 0; int pushed_sr = 0;
if (crop_slot_for(obj, &slot, &sr) && !g_clip_mask_capture)
{
        sr_saved = renderer_clip_ref(context);
        renderer_begin_clip_mask(context);
        renderer_draw_rect(context, 0.0f, 0.0f,
                (float)(sr.xmax - sr.xmin), (float)(sr.ymax - sr.ymin),
                1.0f, 1.0f, 1.0f, 1.0f, slot, 0);
        renderer_end_clip_mask(context);
        pushed_sr = 1;
}
...draw the entry / recurse...
if (pushed_sr) renderer_restore_clip(context, sr_saved);
```

* `renderer_draw_rect` takes twips and is already used this way at `tag.c:4847`;
  the `begin_clip_mask` + `draw_rect` + `end_clip_mask` shape is byte-for-byte
  s13's `avm2_push_scroll_rect_mask` (`avm2_display.c:15464`).
* **`renderer_restore_clip`, never `renderer_end_clip`** — `end_clip` zeroes
  `mask_ref` and would drop an enclosing clipDepth range (the comment at
  `tag.c:3456` records that exact bug).
* **`!g_clip_mask_capture` is the whole `scroll_rect_mask` fix.** Precedent:
  `tag.c:4987`.
* A degenerate rect (`w == 0 || h == 0`) writes no stencil and hides the
  subtree — Ruffle's and Flash's behaviour; keep it and comment it, as s13 did.
* **No new pipeline in `render_webgpu.c` ⇒ the `MSAA_SAMPLES`-never-literal-4
  invariant is honoured trivially.**

**J. Scope discipline.** All three target tests reach the scrolled entry through
`render_display_list`. The two root loops (`~5810` `tagRerenderFrame`, `~6750`
`tagShowFrame`), `render_attached_child` (`6085`) and `render_single_object`
(`3211`, the blend/filter branch) would only matter for a *root-placed* or
*attached* clip with a scrollRect — **no corpus test**. Mirroring them is
optional and pure risk; the ledger below assumes `render_display_list` only.

---

## 6. Predicted movement, priced honestly

All predictions are **calibrated**: the model reproduces CI's published channel
counts exactly (63333 / 41846, 18378, 11310) from the same PNGs, then applies
the geometrically-derived translate + crop.
(`scratchpad/gfx-scrollrect/` — `analyze.py`, `bbox.py`, plus the inline sims.)

| comparison | before | predicted after | budget | verdict |
|---|---:|---:|---|---|
| `visual/cache_as_bitmap/scroll_rect_scaled [output]` | 40946 (tol 64) / 63333 (tol 0) | **420–830 / 1100–2400** | 900 / 2800 | **FLIP** |
| `visual/simple_shapes/scroll_rect_mask [output]` | 11310 | **42** | 0 | band −99.6 %, **not a flip** |
| `visual/cache_as_bitmap/scroll_rect [output]` | 18378 | **~1478** | 0 | band −92 %, **not a flip** |

**`scroll_rect_scaled` — why it flips, and how robust that is.** The crop window
lands at inner's origin, stage 33.4 px, 200×200 (§3.1). Simulated across every
plausible edge treatment of that boundary — hard crop, MSAA 2/4, MSAA 3/4+2/4,
exact 0.6/0.4 coverage, and window-snapped-to-33 — **all five pass both checks**
(worst case 707/2322 vs budgets 900/2800). The only variant that fails is a
window misplaced by ≥ +0.6 px (34.0 → 1398 > 900), which cannot happen if the
crop slot is written from the same `composed` matrix as the content. The test's
own `# FIXME Object's size is wrong (stroke width?)` and its generous budgets
are exactly why the residual (our 1 px wider ink, `quality = "high"`) is
affordable.

**`scroll_rect_mask` — why 42 and not 0.** After a perfect (−10,−10) shift the
silhouette XOR against the golden is **21 isolated single pixels** scattered
around the 628 px circumference (`(259,94) (323,95) (224,114) …`), = 42 channels
at 2 channels/px. `quality = "low"` ⇒ `MSAA_SAMPLES = 1`; these are one-sample
rasteriser edge ties, the same class as `avm2_button_scroll_rect`'s residual 9
and the capped `blend_modes`/fonts families. **Do not scope work at them.** The
translate itself is exact — the shift is rigid and integer-pixel (200 twips), so
subpixel phase is preserved and nothing else can move.

**`scroll_rect` — why ~1478.** 739 px, and every one of them is the **red frame**
(`DefineShape4` id 1, bounds −0.5..150.5 px) rendering 1 px up-left of Ruffle's:
we draw it from (178,116), the golden from (179,117). The frame is a *sibling* of
the scrolled clip inside sprite 4, so it never scrolls — this is a
`cacheAsBitmap` / `PixelSnapping::Always` + one-sample edge-tie residual, a
**separate unowned mechanism**, not scrollRect's. The cyan content lands
byte-exactly where the golden has it.

**Trace axis: zero movement expected.** Nothing here can emit a trace line; the
new accessors only fire on `scrollRect` get/set, which only 7 AVM1 tests touch
and 4 of those only read `undefined`.

---

## 7. Canary set for wave 2 (md5 bar)

Run `ruffle-tests/render_canary.py capture --label before` **before** editing,
per §6 of the playbook. Only the three ledger rows in §6 may DIFFER.

**Mandatory:** the whole standing `ruffle-tests/render_canary_tests.txt`
(20 tests / 37 comparisons, includes `regression/` ×3 and the tier-1
`avm1/movieclip_setmask` + `avm1/mask_with_drawing`).

**scrollRect / mask traps to add for this patch** (must be md5-IDENTICAL):

| test | why |
|---|---|
| `avm2/displayobject_scrollrect` | s13 defect C's 202388→12382 band; an AVM1-only change must not touch it |
| `visual/avm2_button_scroll_rect` | s13 near-pass at **9** excess channels — one lavapipe corner from flipping; protect it |
| `visual/simple_shapes/text_field_mask` | s13 defect B beneficiary (−100 % to 56) |
| `visual/cache_as_bitmap/masks` | s13 defect C family (−75..−95 %) |
| `from_shumway/acid/acid-clip-2`, `from_shumway/invalidClipDepth` | s12/s13 clip traps, `pass 0` |
| `visual/simple_shapes/masks`, `masks_equal_clipdepth` | dispositioned tie pair — must stay at its dispositioned number |

**Trace canaries** (verify_output, must not change status *or* line counts):

| test | baseline | what it guards |
|---|---|---|
| `avm1/movieclip_default_state` | pass 69/69 | prints `scrollRect = undefined` (getter must fall through when unset) |
| `avm1/movieclip_library_state_values` | ruffle_matched 76/78 | same line |
| `avm1/movieclip_state_values` | pass 114/114 | property enumeration |
| `from_gnash/actionscript.all/MovieClip-v5` | ruffle_matched 339/350 | `MovieClip.prototype.hasOwnProperty("scrollRect")` — **do not remove the `extra_props` stub** |
| `from_gnash/actionscript.all/MovieClip-v6 / -v7 / -v8` | output_mismatch 901/921, 934/954, 1020/1072 | same probe at v6–v8 |
| `avm1/movieclip_setmask` | pass 14/14 | already tier-1 in the canary |

**Local grading is CI-grade for this family.** All three targets were rendered
locally against `~/CC/dawn-install` at HEAD and the PNGs are **md5-identical to
the CI actual PNGs** on `ruffle-image-results`:

```
c6fa397d…  simple_shapes/scroll_rect_mask/output.actual.png     (local == CI)
3ee6b5d8…  cache_as_bitmap/scroll_rect/output.actual.png        (local == CI)
367e9621…  cache_as_bitmap/scroll_rect_scaled/output.actual.png (local == CI)
```
So wave 2 may grade the flip locally with
`verify_output.py --tests-dir=<copy> --test=cache_as_bitmap/scroll_rect_scaled
--mode=graphics --images` and believe the number. (This is the documented
exception to "never grade a local render against a golden": the identity is
measured, per-test, at this SHA.)

---

## 8. Risks, and what would refute this

* **Suppression polarity is the one way to get zero yield.** Gate the crop on
  `!g_clip_mask_capture`; gate the translate on **nothing**. Inverting or
  over-gating turns `scroll_rect_mask` into a no-op (and over-cropping there
  makes it *worse* than baseline — the golden has no crop).
* **`compose_children` is on the hot path for every AVM1 test in the corpus.**
  The registry-count early-out must be the first thing the new block tests.
* **Semantic risk:** any AVM1 clip with a `scrollRect` now clips its subtree.
  The corpus scan (§2.1) says exactly three movies do. Games outside the corpus
  are unsampled — but a scrollRect that previously did nothing was already
  wrong, and Ruffle/Flash crop.
* **Shared-file dispatch:** the `action.c` accessors are shared runtime code
  (not `#ifdef NO_GRAPHICS`-only), so per CLAUDE.md "when in doubt run both" —
  dispatch `graphics` for the change and let the weekly canary cover
  no-graphics, or run both if the coordinator has budget.
* **Merge contention:** `tag.c` `compose_children` + `render_display_list` are
  the same regions any AVM1 mask/timeline agent touches. `avm2_display.c` is
  **not** touched, so `gfx-stencil`'s `Equal/IncrementClamp` work is disjoint.
* **Refutation that did NOT happen:** the residual is not stencil intersection.
  `scroll_rect_mask`'s delta is a rigid translate of a single silhouette with no
  second mask involved; no hand-off to `gfx-stencil` is needed. (`gfx-stencil`
  still owns `avm2/displayobject_scrollrect`'s 12382, which s13 measured as
  100 % nested-mask non-intersection.)

## 9. Follow-on leads this opens (not for wave 2)

1. **AVM2 translate-inside-mask-capture** (§4.1) — one line, no test, free
   correctness if an AVM2 mask agent is already in `avm2_render_node`.
2. **`cacheAsBitmap` `PixelSnapping::Always`** — owns 739 of the 739 residual px
   on `cache_as_bitmap/scroll_rect` and probably a slice of the wider
   `cache_as_bitmap` family. Newly isolated and measurable now.
3. **`displayobject_scrollrect`'s trace half** (19/33) — needs Ruffle's
   `pre_render` `next_scroll_rect → scroll_rect` commit delay
   (`display_object.rs:2429`) plus the bounds override (`:1392`) and
   `local_to_global` scroll (`:1508`). Unowned; AVM2-side; the storage this
   session adds on the AVM1 side is the mirror image of what it needs.
