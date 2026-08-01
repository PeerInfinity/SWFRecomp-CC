# wave-1 "gfx-masks" — mask / clip-not-applied diagnosis

Session 10, wave 1, READ-ONLY. **Nothing in the repo was modified** (`git status`
identical before/after: only the three pre-existing untracked dirs). All renders were
produced with `verify_output.py --mode=graphics --images --image-out-dir=<scratch>`,
which writes only into the gitignored `_results/` + the scratch dir.

Local repros done (4 tests, ≤2 concurrent compiles):
`visual/simple_shapes/masks`, `visual/simple_shapes/scroll_rect_mask`,
`visual/simple_shapes/text_field_mask`, `visual/cache_as_bitmap/masks` (7 frames),
`avm2/displayobject_mask`. PNGs in `<scratch>/imgout/`.

---

## 0. Headline — the board's framing needs one correction

The board called this slice "a *gating* bug, not a missing feature — good wave-2 shape."
That is **true for exactly 2 of the 15 core comparisons** and false for the other 13.

The slice is **four independent defects**, not one:

| # | defect | input path | core cmps | nature |
|---|---|---|---|---|
| **A** | stencil buffer is one global `ref=1` region, never cleared between masks | timeline `clipDepth` (AVM1 + shared runtime) | 2 | **gating bug** — real, cheap, confirmed |
| **B** | AVM1 `setMask` never reaches the display-list renderer (Drawing-API only) | `MovieClip.setMask` | 2 | missing feature, small |
| **C** | AVM1 `scrollRect` is a bare dyn-prop stub | `MovieClip.scrollRect` | 3 (2 shared with B) | missing feature, small |
| **D** | `avm2_render_node` has **no mask code at all** | AVM2 `clipDepth`, `DisplayObject.mask`, `scrollRect` | 10 | the explicitly-deferred **T7** tranche |

D is the majority of the slice and is *scoped-out work*, not a gating fix:
`SWFRecompDocs/plans/avm2-vector-rendering-plan.md:198` — *"Masks/`clip_depth` (T7) —
not wired (no stencil this tranche)"*, and `avm2_cpu_raster.h:24` repeats it.

AVM classification of the core 15 (verified with `swf_is_avm2.py`, not inferred from the
suite directory — `visual/cache_as_bitmap/scroll_rect` and `scroll_rect_scaled` are
**AVM1** despite living next to AVM2 tests):

```
AVM1 (5): simple_shapes/{masks, masks_equal_clipdepth}          -> A
          simple_shapes/text_field_mask                          -> B
          simple_shapes/scroll_rect_mask                          -> B + C
          cache_as_bitmap/scroll_rect                             -> C
AVM2 (10): acid-clip-3 [output, frame3], cache_as_bitmap/masks[.07],
           cab_mask_{triangle,filters,alpha,transform},
           avm2/{displayobject_mask, mouse_pick_dobj_mask,
                 mouse_pick_non_interactive_dobj_mask}            -> D
```

---

## 1. Defect A — the stencil gating bug (AVM1 / shared runtime). CONFIRMED

### The mechanism, from code

Three facts in `SWFModernRuntime/src/rendering/render_webgpu.c` compose into "masks
stop working as soon as there is more than one of them in a frame":

1. **`render_webgpu.c:1917-1923`** — the stencil attachment is cleared **once per render
   pass** (`stencilLoadOp = Clear`, `stencilClearValue = 0`). There is no per-mask reset.
2. **`render_webgpu.c:1422-1440`** — `stencil_write_pipeline` is
   `compare = Always, passOp = Replace, stencilWriteMask = 0xFF`.
   `Always` means a mask write **ignores any enclosing mask** → nesting cannot intersect.
3. **`render_webgpu.c:2510-2532`** — `begin_clip_mask` / `end_clip_mask` both call
   `wgpuRenderPassEncoderSetStencilReference(pass, 1)`. The reference is **hard-coded to
   1**; `end_clip` just restores `render_pipeline` and touches nothing in the buffer.

Consequence: after N masks have been drawn in one frame the stencil holds `1` over
**mask₁ ∪ mask₂ ∪ … ∪ maskₙ**, and every `stencil_test(ref == 1)` draw passes over that
whole union. Effectively: **the first mask in a frame works; every later one is a no-op,
and it also widens the earlier masks.**

That is why `from_shumway/clipping` and `from_shumway/invalidClipDepth` *pass* today
(one mask each) while `simple_shapes/masks` fails totally.

### The repro, decomposed

`ruffle-tests/tests/swfs/visual/simple_shapes/masks/RecompiledTags/tagMain.c` — three
masks, two of them nested:

```
root      d1: char 1 (full-stage ellipse)  clip_depth 11   -> masks d2..d11
          d2: char 7 (sprite)                              <- masked
 sprite7  d1: char 2 (rect, black)
          d2: char 3 (squiggle) clip_depth 5               -> masks d3..d5
          d4: char 4                                       <- masked
          d6: char 5 (squiggle) clip_depth 8               -> masks d7..d8
          d7: char 6                                       <- masked
```

Rendered locally, pixel histograms (`<scratch>/imgout/.../masks/output.actual.png` vs the
golden):

```
expected: black 157043 | white 50165 | blue 5615 | red 4679 | yellow 2461
actual  : red 72650 | blue 70427 | white 48848 | yellow 18168 | black 5801
```

The **white count matches (48848 vs 50165)** — i.e. the *outer* ellipse mask IS enforced;
nothing paints outside it. Inside it, the two nested masks did nothing: the squiggle
silhouettes should have clipped chars 4 and 6 down to thin curves, and instead the full
triangles paint. Exactly the union-stencil prediction. `masks_equal_clipdepth` is the
byte-identical twin.

### The three secondary drops in the same defect

- **`tag.c:4472-4476` + `tag.c:4875-4877` — every EditText render pushes a clip mask.**
  `renderTextFieldGlyphs` does `begin_clip_mask → draw_rect(field bounds) →
  end_clip_mask`, and pops with a bare `renderer_end_clip`. With the union stencil this
  means **each text field permanently ORs its field rect into the frame's stencil**, and
  its `end_clip` drops any enclosing timeline mask back to `render_pipeline`. This is the
  widest blast radius in defect A and is invisible on the mask board — it lands on the
  66-comparison Text family.
- **Pipeline clobbers with no stencil awareness**: `render_webgpu.c:2355/2358`
  (`draw_bitmap_tris`), `2502/2504` (`draw_bitmap_quad*`), `2536-2546`
  (`set_blend_mode`), `3289/3329/3478` (resume / offscreen / composite) all
  unconditionally restore `ctx->render_pipeline` — a bitmap, a blend-mode object or a
  filtered object drawn inside a mask silently loses its clip. `3310-3318` additionally
  *clears* the stencil for the offscreen filter pass.
- **Ordering bug, `tag.c:5166-5172` (`tagRerenderFrame`)**: the `if (obj->char_id == 0)
  continue;` is placed **before** the `i > active_clip_depth` end-of-range check, so an
  empty depth immediately after a clip range leaves the clip active for the next
  non-empty depth. `render_display_list` (3169-3176) and `tagShowFrame` (6094-6101) have
  the correct order — `tagRerenderFrame` is the odd one out.

### Call sites that must be updated together (26 total, all in `tag.c`)

```
tag.c:3161-3332   render_display_list()        nested sprite clip loop
tag.c:4472-4476   EditText field clip push     (pop at 4875-4877)
tag.c:4949-4961   masked_drawing_render_cb()   AVM1 setMask, Drawing-API path
tag.c:5164-5254   tagRerenderFrame()           per-tick capture loop
tag.c:6091-6265   tagShowFrame()               main frame loop
```

---

## 2. Defect B — AVM1 `setMask` never reaches display-list content

`action.c:70498-70578` implements `setMask`: it sets `mc->mask_mc = mask_mc` and
`mask_mc->is_mask = 1`. Those two fields are consumed in exactly three places:

- `action.c:28409-28410` — `actionIterateDrawings` **skips** masked/masking MCs
- `action.c:28428-28450` — `actionIterateMaskedDrawings` pairs them, driving
  `tag.c:4949` `masked_drawing_render_cb` (the working path)
- `action.c:13791`, `69960` — `BitmapData.draw` rasterizer and hit-testing

**Nothing in the three `tag.c` display-list loops ever looks at `mask_mc` or `is_mask`.**
So `setMask` works only when *both* the masked and the masking clip carry Drawing-API
geometry (`drawing_state != NULL`). A timeline-placed sprite, a `DefineShape`, or an
EditText is neither clipped nor suppressed.

Confirmed by both AVM1 repros:

| test | AS (decompiled from `RecompiledScripts/script_0.c` + `script_defs.c`) | our render |
|---|---|---|
| `simple_shapes/text_field_mask` | `clip.setMask(txt); txt.text = "WWW…"` | red/blue rects unmasked **+ the grey text painted on top** (mask drawn as content). Golden = red/blue `W` glyphs. |
| `simple_shapes/scroll_rect_mask` | `mask.circle.scrollRect = new flash.geom.Rectangle(100,100,10,10); clip.setMask(mask)` | red/blue rects unmasked **+ a green circle painted on top**. Golden = a red/blue circle. |

Two sub-drops, both needed:
1. the masker is still drawn as ordinary content (`is_mask` never consulted by the
   render loops), and
2. the maskee is never clipped.

There is no `DisplayObject → MovieClip` back-pointer (`swf.h:125-…`), but the forward
pointer `mc->display_obj` exists and is already used the same way for `as_hidden`
(`sync_attached_entry_hidden`). The natural fix mirrors that: add
`u8 as_is_mask` + `struct DisplayObject* as_masked_by` to `DisplayObject` and sync them
from `setMask`.

---

## 3. Defect C — `scrollRect` is not implemented in either VM's render path

**AVM1** (`action.c:15726`): `scrollRect` is one of ten names in `extra_props[10]`, all
installed on `MovieClip.prototype` as *enumerable-but-undefined own properties*. Writing
it stores a plain value. No bounds effect, no scroll offset, no clip. Affected:
`simple_shapes/scroll_rect_mask`, `cache_as_bitmap/scroll_rect`,
`cache_as_bitmap/scroll_rect_scaled`.

**AVM2** (`avm2_display.c:10016-10066`, getter/setter; storage `ext->has_scroll_rect`,
`ext->sr_xmin/ymin/xmax/ymax` in `avm2_globals.h:512-514`): the value is stored and it
**overrides the object's bounds** (`avm2_display.c:722-725`), which is why
`displayobject_scrollrect`'s *trace* half partly works. But `avm2_render_node` never
reads it, so there is neither the clip nor the `-x/-y` scroll translation. Affected:
`avm2/displayobject_scrollrect`, `visual/avm2_button_scroll_rect`.

---

## 4. Defect D — AVM2 has no mask rendering at all (tranche T7)

`avm2_render_node` (`avm2_display.c:14341-14372`) is 30 lines: visibility cull, matrix
compose, dispatch to `avm2_render_{bitmap,morph,shape,text,statictext,graphics}`, recurse
over `render_list`. It reads **none** of:

- `ext->clip_depth` (`avm2_globals.h:486`, written at `avm2_display.c:1761`)
- `ext->mask` / `ext->maskee` (`avm2_globals.h:516-519`, written by `do_set_mask`,
  `avm2_display.c:4137-4158`)
- `ext->has_scroll_rect` / `sr_*`

All three are stored faithfully and consumed **only by hit-testing**
(`avm2_display.c:11451-11641` — `hit_test_shape_obj`, the clip-layer walk, `HT_SKIP_MASK`).
That asymmetry is the whole defect: the pick walk knows about masks, the paint walk does
not. `renderer_begin_clip_mask` and friends are called from `tag.c` **only** — zero call
sites anywhere under `SWFModernRuntime/src/avm2/`.

Textbook confirmation, `avm2/displayobject_mask` (red circle, `.mask = greenSquare`):

- golden: a red **quarter-circle** (circle ∩ square), no green anywhere
- ours: the **full red circle plus the green square painted on top**

Both halves fail — masker not suppressed, maskee not clipped — exactly like defect B.

### Step 4: the "second tier" is not a separate transform bug

`visual/cache_as_bitmap/masks [output.01]` (AVM2) rendered locally:

- golden: a red circle + a yellow half-circle, repeated in three dashed-outline groups
- ours: **two solid blue rectangles** covering the two dashed groups, top group absent

The blue rectangles are the *mask* shapes painted as content; they occlude the red/yellow
circles that were drawn before them. The classifier scores that as high-`extra` **and**
high-`missing` (hence "mask applied to the wrong region"), but the mechanism is
identical to `[output.07]` — **the board's core/second-tier split inside this slice is a
classifier artifact, not two bugs.** Treat `cache_as_bitmap/masks [.01–.07]` as one
7-comparison block owned by defect D.

Same reasoning applies to `avm2/mask_reapply` and `avm2/bitmapdata_draw_masks` (the
latter additionally needs the masked path inside `BitmapData.draw`,
`action.c:13783-13817`, which today only handles `mask_mc` for the AVM1 rasterizer).
`cache_as_bitmap/oversize/swf_9_masks` + `swf_10_masks` are `blank_render` at 119 943 —
a *different* mechanism (oversize / bitmap-cache), do **not** fold them into this slice.

---

## 5. Corrected slice membership (from the merged `image_results_graphics.json`)

The board's 15+11 misses several members and, more importantly, misses the
**currently-PASSING** mask comparisons that a wave-2 patch can break.

**Failing, owned by this slice** (beyond the board's list):

```
from_shumway/MaskTest              3660    AVM2   -> D
from_shumway/acid/acid-clip       19356    AVM2   -> D
avm2/mouse_pick_non_interactive_bitmap_mask 2500  AVM2 -> D
avm2/displayobject_scrollrect    203367    AVM2   -> C(avm2)   [trace also fails]
visual/avm2_button_scroll_rect    28851    AVM2   -> C(avm2)
from_shumway/acid/acid-mask [.01/.05/.10]  AVM2, known_failure -> D
from_shumway/MaskTest-2                    AVM2, known_failure -> D
```

**PASSING today — the regression surface (this is the important list):**

```
avm1/movieclip_setmask                     pass   many setMask'd Drawing-API clips
avm1/mask_with_drawing                     pass   setMask + Drawing API
avm1/mask_reapply                          pass   setMask re-apply
from_shumway/invalidClipDepth              pass   AVM1, single timeline mask
from_shumway/clipping                      pass   AVM2 (degenerate)
from_shumway/MaskTest-3                    pass   AVM2, trace = ruffle_matched  (!)
from_shumway/acid/acid-clip-2              pass   2881 outliers vs limit 3000  (!!)
avm2/blend_scroll                          pass
visual/focus_highlight/focus_highlight_empty_clip  pass
```

Two traps in that list:
- **`acid/acid-clip-2` passes with 2881 of a 3000-outlier budget.** Any change that
  perturbs mask pixels by a few hundred px flips it to fail. It is the single most
  fragile comparison in the slice.
- **`MaskTest-3`'s trace is `ruffle_matched`** — per `ruffle-matched-hides-regression`,
  a pass→ruffle_matched move there would be a regression, not a win. Read its trace
  status, not just its pixel status.

Why does `avm1/movieclip_setmask` pass today despite defect A? Its masks are spatially
disjoint (one small mask per coloured square), so the stencil union never leaks onto a
neighbour. It is a *weak* canary for defect A and a *strong* one for defect B.

---

## 6. Implementation-ready fix plan (ordered)

### Fix A — proper mask stack in the stencil (do this first; everything else builds on it)

**Sites**
- `render_webgpu.c:1391-1453` — replace the two mask pipelines with three, all sharing
  `stencilReadMask/WriteMask = 0xFF` (only the *reference* is dynamic state in WebGPU,
  so read/write masks must stay constant):
  - `mask_write`: `compare = Equal`, `passOp = IncrementClamp`, `writeMask = 0xFF`,
    colour writeMask `None`
  - `mask_test`: `compare = Equal`, `passOp = Keep`, `writeMask = 0x00`, colour on
    (this is today's `stencil_test_pipeline`, unchanged)
  - `mask_clear`: `compare = Equal`, `passOp = DecrementClamp`, `writeMask = 0xFF`,
    colour writeMask `None`
- `render_webgpu.c:2510-2532` — add `uint32_t ctx->num_masks` (reset to 0 in
  `open_pass`, `render_webgpu.c:1917`) and re-shape the three entry points, Ruffle's
  `MaskState` model:
  - `begin_clip_mask`: `num_masks++`; bind `mask_write`; `SetStencilReference(num_masks-1)`
  - `end_clip_mask`: bind `mask_test`; `SetStencilReference(num_masks)`
  - **new** `pop_clip_mask`: bind `mask_clear`; `SetStencilReference(num_masks)`; the
    caller **re-draws the mask geometry**; then `num_masks--`; bind
    `mask_test`/`render_pipeline` with reference `num_masks`.
  `end_clip` must stop being "restore `render_pipeline`" — with nesting it has to restore
  the *enclosing* state.
- `tag.c` — factor the mask-geometry draw out of each of the three loops into one
  `static void draw_clip_mask_geometry(SWFAppContext*, DisplayObject*)` and call it twice
  (push and pop). Keep a small explicit stack of active `DisplayObject*` per loop instead
  of the single `active_clip_depth` scalar, so nested + sibling ranges pop in order.
  Loops: `3161-3332`, `5164-5254`, `6091-6265`.
- `tag.c:4472-4476` / `4875-4877` — make the EditText field clip a proper push/pop pair
  (it is the highest-blast-radius caller).
- `tag.c:4949-4961` — `masked_drawing_render_cb` likewise.
- `render_webgpu.c:2355/2358, 2502/2504, 2536-2546, 3289/3329/3478` — these must restore
  the *current mask state* (`num_masks > 0 ? mask_test@num_masks : render_pipeline`)
  rather than unconditionally `render_pipeline`. A one-line
  `render_webgpu_restore_draw_pipeline(ctx)` helper covers all of them.
- `tag.c:5166-5172` — move the `char_id == 0` skip **after** the end-of-range check, to
  match the other two loops.

**Alternative if geometry replay proves awkward**: one stencil *bit* per nesting level
(`writeMask = 1<<level`, pop = full-screen quad with `passOp = Zero` on that bit). No
replay, but read/write masks are pipeline-static, so it needs ~4 levels × 3 pipelines =
12 pipelines. Prefer increment/decrement.

**Effort** ~1 session. **Risk HIGH** (the EditText clip runs on *every* text field —
this touches the whole 66-comparison Text family). **Predicted flips: 2**
(`simple_shapes/masks`, `masks_equal_clipdepth`) plus unquantified band moves in Text.

### Fix B — AVM1 `setMask` on display-list content

**Sites**: `swf.h` `DisplayObject` (add `u8 as_is_mask; struct DisplayObject* as_masked_by;`) ·
`action.c:70569-70575` + `70510-70515` (sync/clear both fields through `mc->display_obj`,
exactly as `sync_attached_entry_hidden` does) · the three `tag.c` loops (skip
`as_is_mask` entries as content; wrap `as_masked_by` entries in push/pop) ·
`action.c:28409-28410` (the Drawing-API iterators must stop double-handling entries the
display loop now owns).
**Depends on A** for correctness with more than one mask per frame.
**Effort** ~0.5 session. **Risk medium** — `avm1/movieclip_setmask`, `mask_with_drawing`
and `mask_reapply` all pass today through the Drawing-API path and must not
double-render. **Predicted flips: 1** (`text_field_mask`), +1 more with C.

### Fix C — `scrollRect`

- AVM1 (`action.c:15726` stub → real getter/setter + render): translate children by
  `-rect.x/-rect.y` and clip to `rect` (a push/pop of a rect mask, so it rides fix A).
- AVM2 (`avm2_display.c:14341` walk): read `ext->has_scroll_rect` / `sr_*` and do the
  same. Storage and bounds semantics already exist (`10016-10066`, `722-725`).
**Effort** ~0.5-1 session. **Risk low.** **Predicted flips: 3-4**
(`simple_shapes/scroll_rect_mask` [with B], `cache_as_bitmap/scroll_rect`,
`scroll_rect_scaled`, possibly `avm2/displayobject_scrollrect` — note its *trace* also
fails, so it is a dual-axis test).

### Fix D — AVM2 masks (open tranche T7)

**Site**: `avm2_display.c:14341-14372` `avm2_render_node`, three additions:
1. `if (ext->maskee != NULL) return;` — a masker is never painted as content
   (Ruffle `DisplayObject::render`).
2. `if (ext->mask != NULL)` — push mask (render the masker subtree into stencil with the
   **masker's own** world matrix, not the maskee's), draw the node + subtree, pop.
3. In the `render_list` loop, honour `cext->clip_depth > 0`: the child masks the depth
   range `(depth, clip_depth]`, exactly as `tag.c:6122-6147` does. The hit-test walk at
   `avm2_display.c:11593-11645` already implements this range logic and can be mirrored
   verbatim.
Also `action.c:13783-13817` for `BitmapData.draw` masks (`avm2/bitmapdata_draw_masks`).
**Depends on A.** **Effort** 1-2 sessions (this is T7, scoped-out in
`avm2-vector-rendering-plan.md:718-720`). **Risk medium** (AVM2 paint walk = all AVM2
pixel tests). **Predicted flips: 8-14** of:
`avm2/{displayobject_mask, mask_reapply, mouse_pick_dobj_mask,
mouse_pick_non_interactive_dobj_mask, mouse_pick_non_interactive_bitmap_mask}` ·
`cache_as_bitmap/masks[.01–.07]` · `cab_mask_{triangle,alpha,transform}` ·
`from_shumway/{MaskTest, acid/acid-clip, acid/acid-clip-3 ×2}`.
Discount: `cab_mask_filters` also needs the filters slice; the `cache_as_bitmap/*` block
may also be gated by the missing bitmap-cache path (board §(d)2) — verify with one
render before committing to the full 7.

### Realistic totals

| plan | flips | sessions |
|---|---|---|
| A only | **2** (+ Text band moves) | 1 |
| A + B + C | **6-7** | 2 |
| A + B + C + D | **14-21** | 3-4 |

The board's "8-15" is only reachable **with D**, i.e. by opening T7. A wave-2 agent given
one session should take **A + B** (3 flips, both mechanisms retired for AVM1) and hand D
off as a named tranche.

---

## 7. Canary set for wave-2

Standing set (`ruffle-tests/render_canary_tests.txt`) already carries three of the right
tests — `avm1/mask_with_drawing`, `avm1/movieclip_setmask` (tier 1) and
`visual/simple_shapes/masks` (tier 2) — plus the three `regression/` entries. **It is not
sufficient for this slice.** Add, as `--tests-dir` additions or a slice-local list:

```
# must-not-break (all PASS today)
avm1/mask_reapply
from_shumway/invalidClipDepth                 AVM1 single timeline mask
from_shumway/clipping                         AVM2
from_shumway/MaskTest-3                       AVM2 — check TRACE stays `pass`, not `ruffle_matched`
from_shumway/acid/acid-clip-2                 2881/3000 outliers — most fragile in the slice
avm2/blend_scroll
visual/focus_highlight/focus_highlight_empty_clip

# EditText blast radius of fix A (the field clip at tag.c:4472)
avm1/edittext_tag_indent                      (already tier 1)
visual/cache_as_bitmap/edittext_scroll        AVM1
visual/cache_as_bitmap/edittext_hscroll       AVM1
from_shumway/acid/acid-textfield-scroll       AVM2

# expected-to-move ledger
visual/simple_shapes/{masks, masks_equal_clipdepth, text_field_mask, scroll_rect_mask}
avm2/displayobject_mask
visual/cache_as_bitmap/masks
```

**Regression-suite gap.** There is currently **no mask/clip/scrollRect test in
`ruffle-tests/tests/swfs/regression/`** (checked: zero name matches). The standing policy
"every canary includes the regression suite 3×" is satisfied only by unrelated gradient /
morph tests. A wave-2 agent that lands fix A should add one — an AVM1 SWF with **two
sibling top-level `clipDepth` masks whose regions overlap** (the exact shape the union
bug breaks and no existing test covers). Per playbook §7 the golden must come from an
oracle outside SWFRecomp (Ruffle export via `~/CC/ruffle`); if none is available, ship it
trace-only and let it record `skip/no_expected_image`.

**Local-repro note.** Every test in this slice reproduced byte-exactly on local Dawn
(the board's §(d)7 observation generalises to the whole slice — the diffs are structural,
no AA involved). Still A/B by md5 via `render_canary.py`; never grade a local render
against a golden.

## 8. Exact drop points, one line each

| path | where the flag is set | where it is dropped |
|---|---|---|
| timeline `clipDepth`, AVM1 | `tag.c:7549` `tagPlaceObject2` → `display_list[d].clip_depth` | **not dropped** — reaches `tag.c:6122`/`5173`/`3199`; dies in `render_webgpu.c:2510-2532` (global `ref=1`, no per-mask clear) |
| `MovieClip.setMask`, AVM1 | `action.c:70573-70574` `mc->mask_mc` / `is_mask` | never read by any `tag.c` display-list loop; only `action.c:28428` (Drawing API) and `13791` (BitmapData.draw) consume it |
| `MovieClip.scrollRect`, AVM1 | `action.c:15726` — plain undefined dyn-prop | never implemented |
| timeline `clipDepth`, AVM2 | `avm2_display.c:1761` `cext->clip_depth` | read only by hit-test (`11593-11645`); `avm2_render_node:14341` ignores it |
| `DisplayObject.mask`, AVM2 | `avm2_display.c:4146-4157` `ext->mask` / `maskee` | read only by hit-test (`11467-11539`); `avm2_render_node` ignores it |
| `DisplayObject.scrollRect`, AVM2 | `avm2_display.c:10054-10066` `has_scroll_rect` + `sr_*` | reaches bounds (`722-725`); `avm2_render_node` ignores it |
