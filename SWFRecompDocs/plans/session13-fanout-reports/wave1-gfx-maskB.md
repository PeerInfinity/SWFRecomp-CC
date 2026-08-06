# wave-1 `gfx-maskB` — mask defect B: re-verification, the s10 UAF, and a UAF-free redesign

Session 13, wave 1, **READ-ONLY**. No source, doc or test file in the repo was
modified (the only file written is this report). Two local single-test runs
(`--mode=graphics --images`, sequential, local Dawn at `~/CC/dawn-install`);
all PNG output went to the scratchpad. Baseline: run `31090651530` at
`1f8396f57`, pixels 286/567; HEAD `10931d62e`.

---

## 0. Headline — three results, one of them a refutation

1. **Defect B is real, unchanged at HEAD, and owns exactly two failing
   comparisons** (`visual/simple_shapes/text_field_mask` 431740,
   `visual/simple_shapes/scroll_rect_mask` 434284). Both reproduce locally at
   **byte-exactly the CI number**, so the diagnosis and any A/B are CI-credible.
   The s12 AVM2 clipDepth work did not touch them (neither SWF carries `DoABC`).
2. **The s10 fix design is not merely UAF-prone, it is *insufficient*.** Its
   proposed `DisplayObject* as_masked_by` field cannot be populated for the
   headline test at all: the masker there is an **EditText wrapper, and root
   placed EditText wrappers have `display_obj == NULL`**
   (`edittext-wrapper-no-display-obj-invalidate`) — and EditTexts do not render
   through the display-list loop in the first place. §2 gives the UAF precisely;
   §2.4 gives the insufficiency.
3. **REFUTATION — defect B is not a flip lead.** I measured the residual a
   correct fix would leave. `text_field_mask`'s glyph silhouette already agrees
   with Ruffle's to **10 mismatching pixels out of 3010** inside the field
   bounds — i.e. after the fix the comparison lands at roughly **30 px / ~90
   excess channels at `tolerance = 0, max_outliers = 0`: a near-pass, not a
   pass** (§5). `scroll_rect_mask` additionally needs the **AVM1** `scrollRect`
   translate (defect C's AVM1 half, which the session-12 design and this
   session's sibling do *not* cover — they own the AVM2 half) and even then
   lands on a circle-edge tie. **Book defect B as 0–1 flips and two band moves
   of −96 % / −99.98 %, not as the "2 flips" the s10 report priced.**

The fix is still worth shipping — it is a whole missing mechanism that every
AVM1 title using `setMask` on timeline content hits (a substrate/game-facing
win) — but it must be scoped as *mechanism + band moves*, and paired with the
AVM1 `scrollRect` translate if the session wants a flip out of it.

---

## 1. What defect B is, re-verified at HEAD

### 1.1 The mechanism

`action.c:70653` (`setMask`) sets `mc->mask_mc = mask_mc` and
`mask_mc->is_mask = 1`. Those two fields are read in exactly four places, all
outside the display-list renderer:

| reader | file:line | what it does |
|---|---|---|
| `actionIterateDrawings` | `action.c:28529-28541` | skips MCs that are a mask or are masked |
| `actionIterateMaskedDrawings` | `action.c:28556-28577` | pairs them, drives `tag.c:5397 masked_drawing_render_cb` |
| `BitmapData.draw` rasteriser | `action.c:13783-13817` | CPU stencil |
| hit-testing | `action.c:70108` | pick |

`grep -n 'mask_mc\|is_mask' SWFModernRuntime/src/libswf/tag.c` still returns
**zero hits** at HEAD. So `setMask` works **only when both clips carry
Drawing-API geometry** (`drawing_state != NULL`). A timeline-placed sprite, a
`DefineShape`, or an EditText is neither clipped (maskee) nor suppressed
(masker) — both halves fail.

### 1.2 The two comparisons, measured locally at HEAD

Local numbers are byte-identical to the merged CI results — no staleness, no
local/lavapipe divergence to argue about.

**`visual/simple_shapes/text_field_mask`** — `clip.setMask(txt); txt.text =
"WWWWWWWWWWW"`. Root `d1 = char 2` (sprite "clip", red-left/blue-right
full-stage rects), root `d3 = char 4` (`DefineEditText` "txt").
`num_frames = 1`, `tolerance = 0`, `quality = "low"` → `MSAA_SAMPLES = 1`.

```
CI  431740 excess outliers      local 431740   (exact match)
actual   : blue 110000 | red 106990 | grey(51,51,51) 3010      [3 colours]
expected : white 211361 | blue 4334 | red 4305                 [3 colours]
```

Both halves visible: the rects are unmasked (full stage) and the masker is
painted as ordinary grey text on top. Golden = red/blue `W` glyphs on white.

**`visual/simple_shapes/scroll_rect_mask`** —
`mask.circle.scrollRect = new flash.geom.Rectangle(10,10,100,100);
clip.setMask(mask)` (AVM1 pushes args reversed — it is `x=10,y=10,w=100,h=100`,
not the `100,100,10,10` a naive read of the bytecode suggests).

```
CI  434284      local 434284   (exact match)
actual  : red 99223 | blue 89335 | green 31442     green circle bbox (200,100)-(399,299)
expected: white 188494 | blue 18746 | red 12760    content  bbox (190, 90)-(389,289)
```

Same two halves. The golden's masked region is the **same 200 px circle shifted
by exactly `(-10,-10)`** = the scrollRect origin — i.e. Ruffle applied the
scroll **translate** and **not** the 100×100 crop. That is not a Ruffle quirk we
have to special-case: a mask push nested inside a mask capture is a no-op in our
renderer too (`render_webgpu.c:2630` `mask_capture_depth`), so a faithful
implementation reproduces it for free (§3.6).

### 1.3 Slice membership — the corpus-wide scan

I scanned **all 4949 corpus SWFs, decompressing the 3909 CWS/ZWS ones** (the
naive `grep` over `.swf` misses every compressed movie — a trap worth keeping).
Sixteen SWFs reference `setMask`; only **five are pixel-graded**:

| test | status at HEAD | role |
|---|---|---|
| `visual/simple_shapes/text_field_mask` | fail 431740 | **target** |
| `visual/simple_shapes/scroll_rect_mask` | fail 434284 | **target** (needs AVM1 scrollRect too) |
| `avm1/mask_reapply` | **pass** (tol 1, 152 diff ch, 0 outliers) | **highest-risk canary** (§3.5) |
| `avm1/movieclip_setmask` | pass 0 | Drawing-API only (`createEmptyMovieClip`+`beginFill`) |
| `avm1/netstream_play_flv_screen` | fail 44751 | video backend, `setMask` incidental — not this slice |

`avm1/mask_with_drawing` (pass 0) is Drawing-API only as well.
The gnash `masks_test` / `MovieClip-v5..v8` / `RollOverOutTest` /
`DrawingApiTest` / `BitmapData-v8` `setMask` users carry **no
`[image_comparisons]`** — trace-only, no pixel exposure.

**So defect B's entire pixel surface is 2 failing + 3 passing comparisons.**
There are no hidden riders. Anyone pricing this slice above two comparisons is
double-counting.

---

## 2. The s10 design's use-after-free, precisely

s10 `wave1-gfx-masks.md` §6 "Fix B" proposed:

> `swf.h` `DisplayObject` (add `u8 as_is_mask; struct DisplayObject* as_masked_by;`)
> … sync/clear both fields through `mc->display_obj`, exactly as
> `sync_attached_entry_hidden` does.

`as_masked_by` is a **pointer to a display-list entry stored inside another
display-list entry**. Both of the codebase's two pointer-safety funnels reject
it, and it has a third, non-memory failure mode.

### 2.1 Realloc: the pointer dangles when the *masker's* list grows

`DisplayObject.sprite_display_list`'s ALIASING RULE (`swf.h:138-155`) and
`tag.c:9633-9658` name two holder classes:

* **Class A** — pointers *into* the buffer (`&dl[i]`): `MovieClip.display_obj`,
  `g_current_sprite_obj`, queued `PendingRegisterCtor` / `PendingClipLoad`
  payloads, pending sprite-frame-script captures, `g_clip_ef_rebase_head`
  frames.
* **Class B** — copies of the buffer *base*.

`ng_spriteDLRealloc` (`tag.c:9714-9793`) `HCALLOC`s a new buffer, `memcpy`s,
repoints exactly the holders enumerated at `9743-9790`, then **`FREE(old_base)`
at `9792`**. `as_masked_by` is a Class-A holder that appears **nowhere** in that
walk, so the next `ng_ensureDisplayListSize` / attachMovie registration at
`swf_depth >= 16384` / placement past capacity turns every stored
`as_masked_by` into a pointer into freed heap. The very next paint dereferences
it. This is the same shape as the already-fixed `aq_dispatch_register_ctor`
ASAN UAF (`sprite-dl-realloc-rebase`).

Worse: the field lives *inside* the entries, so the `memcpy` at `9732`
faithfully copies the stale pointers into the new buffer — the corruption
survives the operation that was supposed to fix it.

### 2.2 Free: the pointer dangles when the masker's sprite is removed

`ng_freeSpriteDL` (`tag.c:9876-9904`) is the only legal free path and is the
free-side twin of the rebase walk: it NULLs `MovieClip.display_obj` in range
(`scrub_mc_display_obj_in_range`, `9812`), queue payloads, `g_current_sprite_obj`,
clip-EF frames, `PendingFinalizeEntry.queued_dl_array`. Again `as_masked_by`
is not scrubbed. Call sites that free a sprite DL — `tag.c:1269, 1507, 1997,
2281, 8406, 9151, 10124, 11731` — include `clear_display_entry`,
`tagRemoveObject2`, and the backward-goto rewind paths, i.e. exactly the events
a mask pairing is most likely to outlive (`backward-goto-dynamic-children-survive-uaf`
is the same class of bug, already fixed once).

### 2.3 Depth reuse: a *logical* UAF even when the memory is fine

Display-list entries are **slots indexed by depth**, reclaimed and re-placed in
the same frame (`tagRemoveObject2` + same-depth `tagPlaceObject2`, the
`pending_remove` reclaim path). A surviving `as_masked_by` then points at a
live, correctly-typed `DisplayObject` that is a **different character** —
the mask silently transfers to an unrelated object. The runtime already fights
this class (`invalidate_mc_for_dl_entry`, `PendingFinalizeEntry.orig_char_id` /
`orig_instance_name` snapshots); duplicating mask state into entries re-opens
it. Same for `u8 as_is_mask`: it is duplicated state needing clearing on
`setMask(null)`, on removal, on rewind and on clone-replace — four invalidation
points that do not exist if the flag stays on the MovieClip.

### 2.4 The design is also *insufficient* — the masker often has no entry

This is the more damning problem, and it is specific to defect B's own headline
test.

* `mc->display_obj` is set **only for sprites**, via `exec_sprite_frame`.
  **Root-placed `DefineEditText` wrappers have `display_obj == NULL`**
  (`edittext-wrapper-no-display-obj-invalidate`) — the memory note exists
  because a whole invalidation path missed them for this reason.
* EditTexts are *not painted by the display-list loop at all*:
  `render_display_list` skips `CHAR_TYPE_TEXT` whenever
  `ng_getCharTextfieldIdx(char_id) >= 0` (`tag.c:3506-3511`); they render in a
  **separate later pass**, `actionIterateTextFieldGlyphs` →
  `textfield_glyph_render_cb` (`tag.c:6731`, after the display loop ends at
  `6689`).

In `text_field_mask` the masker **is** such an EditText. An
entry-to-entry pointer therefore cannot express the pairing (there is no
masker entry), and even if it could, the mask geometry lives in a pass that runs
*after* the maskee has already been painted. Any design that keys on
`DisplayObject*` is structurally unable to fix the test it was written for.

---

## 3. The redesign

### 3.1 Ownership rule (one sentence)

> **All mask pairing state lives on `MovieClip`, which is immortal; the only
> `DisplayObject*` the mask code ever handles is `mc->display_obj`, read fresh
> at the point of use, never stored.**

`MovieClip` structs are allocated at `action.c:21068` (`calloc`) and `21185`
(`HCALLOC`) and are **never freed** anywhere in the runtime (verified: no
`FREE(mc)` / `free(mc)` / `HFREE(mc)` site exists). Dead clips are *tombstoned*
(`depth = INT_MIN`) and their cache slot NULLed —
`actionReclaimDeadChildMCSlots` (`action.c:23242-23267`) says so explicitly:
*"MC structs are deliberately NOT freed (AS variables may still hold dead
MOVIECLIP refs, which read as INT_MIN-dead — freeing would dangle them)"*. A
stored `MovieClip*` can therefore go **stale but never invalid**, and staleness
is a one-line read-time predicate.

`mc->display_obj`, by contrast, is the *one* entry pointer the runtime already
maintains for us: rebased by `ng_spriteDLRealloc` (`tag.c:9744-9750`) and NULLed
by `scrub_mc_display_obj_in_range` (`tag.c:9812`). Reading it at the moment of
use is always safe; caching it across anything is not. So we never cache it.

### 3.2 State (three fields, all on `MovieClip`, two already exist)

| field | exists? | meaning |
|---|---|---|
| `void* mask_mc` | yes | maskee → masker |
| `u8 is_mask` | yes | this clip is somebody's masker |
| `void* maskee_mc` | **new** | masker → maskee (needed to validate `is_mask` at read time and to clear the old pairing on re-`setMask`) |

Plus **one global counter**, `g_avm1_mask_pair_count` (int), incremented/
decremented by `setMask`. Zero new pointers into any relocatable buffer, zero
new fields on `DisplayObject`.

`maskee_mc` mirrors Ruffle's `masker`/`maskee` pair (`display_object.rs`
`set_mask`) and is exactly what s12 relied on for AVM2 (`ext->mask` /
`ext->maskee`, `avm2_display.c:4209`).

### 3.3 Lifetime / invalidation points — deliberately almost empty

| event | what has to happen | why nothing more |
|---|---|---|
| `setMask(m)` | clear any previous pair (both directions), set `mask_mc`/`maskee_mc`/`is_mask`, retire `clip_depth` on both entries (§3.5), bump the counter | — |
| `setMask(null)` | clear both directions, decrement counter | — |
| masker or maskee removed / rewound / re-cloned | **nothing** | read-time predicate `is_mc_live(mc)` = `mc != NULL && mc->depth != INT_MIN && !mc->avm1_removed`; a dead partner makes the pair inert, and the MC memory is still valid |
| sprite DL grows or is freed | **nothing** | we store no entry pointers; `mc->display_obj` is maintained by the existing funnel and re-read every frame |
| depth slot reused by a different character | **nothing** | we never key on depth; the pairing is MC-identity based |
| frame boundary / goto catch-up | **nothing** | no per-frame cache survives the pass (§3.4) |

That table *is* the safety argument: the only way to reintroduce a UAF is to
cache a `DisplayObject*`, and the design never does.

### 3.4 The paint-time algorithm

Painting runs after the last script drain, so no DL can grow or be freed inside
it — but the design does not depend on that, it merely benefits from it.

At the top of each paint loop (cost = one branch when no `setMask` is live):

```c
if (g_avm1_mask_pair_count == 0) { /* every hook below compiles out to a no-op */ }
```

Per display-list entry `obj` in the three loops:

```
masker = avm1_masker_for_entry(obj)     /* NULL unless a live pair names obj */
if (entry_is_live_masker(obj))          /* obj's MC has is_mask + live maskee */
        continue;                       /* Ruffle: a masker is never painted as content */
if (masker != NULL) {
        saved = renderer_clip_ref(context);          /* s12 primitive */
        renderer_begin_clip_mask(context);
        draw_mc_mask_geometry(app_context, masker);  /* §3.6 */
        renderer_end_clip_mask(context);
}
... existing per-entry paint ...
if (masker != NULL) renderer_restore_clip(context, saved);   /* NOT end_clip */
```

`avm1_masker_for_entry(obj)` resolves **MC-first**: walk the (tiny) set of live
pairs; for each maskee MC, `mc->display_obj == obj` is the primary key; when
`display_obj == NULL`, fall back to `obj->instance_name` vs `mc->name` (the same
name-keyed fallback `tag.c:6611` already uses for sprite-mask drawing paths).
No pointer is retained beyond the comparison.

Symmetrically in the two non-display-list passes:

* **glyph pass** (`actionIterateTextFieldGlyphs`, `action.c:26772`): skip fields
  whose MC is a live masker (mirrors `actionIterateDrawings`'
  `if (mc->is_mask) continue;` at `action.c:28536`), and — optional phase 3 —
  push/restore the masker's stencil around a field that *is* a maskee.
* **attached-bitmap pass** (`actionIterateAttachedBitmaps`): same masker skip.
* **root-attached clip pass** (`tag.c:6702+`, `render_attached_child`): same
  masker skip + same push/restore, for dynamic maskees with DL content.

### 3.5 Composition constraint (load-bearing): masker suppression and
`clip_depth` retirement must travel together

Ruffle's `DisplayObject::set_mask` clears `clip_depth` on **both** objects; s12
landed this for AVM2 (`avm2_display.c:4209-4232`) and its v2 report §1 records
*why*: masker suppression without the retirement loses a whole patch on
`mask_reapply`'s deliberately-backwards second pair.

`avm1/mask_reapply` is the AVM1 twin of that movie and it **passes today**
(tol 1). Its timeline is `d1 char1 clipDepth 5 "mask1"; d3 char3 "maskee1";
d2 char6 clipDepth 7 "mask2"; d4 char7 "maskee2"` (`RecompiledTags/tagMain.c:16-23`)
and its script calls `setMask` twice, the second one backwards. Adding masker
suppression alone would suppress `maskee2` (now a masker) while `mask2` still
carries `clip_depth = 7` → one patch disappears → **regression on a passing
test**. Adding the `clip_depth = 0` retirement on both entries (through
`mc->display_obj`, no-op when NULL) makes the second pair an ordinary
mask/maskee whose intersection is the same rectangle — the route s12 measured
to be pixel-identical on the AVM2 side.

Corollary for the DL loop: masker suppression applies to the **content** branch
only. An entry with `clip_depth > 0` keeps its existing stencil behaviour.

### 3.6 `draw_mc_mask_geometry(masker)` — three sources, one function

| masker kind | source | code to reuse |
|---|---|---|
| timeline sprite / shape (`mc->display_obj != NULL`) | that entry's geometry, with `g_clip_mask_capture++` around a `render_display_list` of its subtree + its Drawing-API paths by name | verbatim from `tag.c:6602-6619` (the sprite clipDepth branch) |
| Drawing-API clip (`drawing_state != NULL`) | fill-only paths | `render_drawing_mc_paths_fill_only` (`tag.c:5384`) + `actionGetMCDrawingPathsByName` |
| EditText wrapper (`ng_textfield_idx >= 0`) | its glyph fills | `textfield_glyph_render_cb` via a **filtered** `actionIterateTextFieldGlyphs` (one MC), with the field-bounds clip push at `tag.c:4873-4878` **suppressed while `g_clip_mask_capture > 0`** |

A masker can be more than one of these; draw all that apply. All three draw
through `renderer_draw_shape` / `renderer_draw_tris`, neither of which rebinds a
pipeline (`render_webgpu.c:2177-2218`), so everything lands in the stencil.

**The EditText field-clip suppression is not an optimisation — the golden proves
it.** Our current grey text stops at `x = 192` (the field is ~182 px wide); the
golden's masked `W`s run to `x = 549`. Ruffle's `EditText::render_self` bounds
mask is a *nested* mask inside a mask capture and is therefore ignored. Our
renderer already no-ops nested `begin/end_clip_mask` pairs
(`render_webgpu.c:2630`, `2640`) and `end_clip` (`2654`) inside a capture, so
only the *rect draw itself* has to be gated on `g_clip_mask_capture`.

The same mechanism explains `scroll_rect_mask`'s golden: the crop rect that
AVM1 `scrollRect` would push inside the mask capture is ignored, while the
`(-10,-10)` translate still applies. A future AVM1 `scrollRect` therefore needs
*no* special case for the mask path.

### 3.7 One pre-existing bug the same change should fix

`render_display_list` closes its clip ranges with `renderer_end_clip`
(`tag.c:3387`, `3571`), which **zeroes** `mask_ref`. Called from inside a
maskee's subtree (or from inside any enclosing clip), it drops the outer clip
for everything drawn afterwards. This is exactly the defect s12 fixed on the
AVM2 side by switching to `renderer_restore_clip(pre_clip_ref)`
(`avm2_display.c:15548, 15559, 15572, 15576`). Capture `pre_clip_ref =
renderer_clip_ref(context)` at function entry and restore to it. Small,
precedented, and required for a `setMask`ed sprite whose subtree has its own
clip range.

### 3.8 Why this cannot collide with the session's other mask work

The defect-C sibling implements the **AVM2** half from
`w2-gfx-masks-report.md §6.1`: an insertion in `avm2_render_node`
(`avm2_display.c` ~15448-15580, beside `pushed_mask`/`saved_clip_ref`) plus the
`ext->has_scroll_rect` reads. This design touches
**`tag.c`, `action.c`, `action.h`** and *no* AVM2 file; it adds no renderer
function (it only *calls* `renderer_clip_ref` / `renderer_restore_clip`, already
exported in both `renderer.h` arms at lines 30-34 / 87-91). Zero textual
overlap. The only *semantic* coupling is the shared flat-stencil limitation
(nesting replaces instead of intersecting) that both walks live with.

---

## 4. Wave-2 brief

### 4.1 Change list

**Phase 1 — pairing + AVM1 render hooks (the mechanism).**

| file | function / site | change |
|---|---|---|
| `SWFModernRuntime/include/actionmodern/action.h` | `MovieClip` (~l.65 region) | add `void* maskee_mc;` |
| `action.c:70653` | `setMask` branch | maintain `maskee_mc` both ways; clear the previous pair; retire `clip_depth = 0` on both entries via `mc->display_obj` when non-NULL; maintain `g_avm1_mask_pair_count` |
| `action.c` (new, near `28529`) | `actionAvm1MaskPairs(...)` accessor + `actionAvm1MaskPairCount()` | expose the live pairs to `tag.c` without exporting `child_mc_cache` semantics |
| `action.c:26778` | `actionIterateTextFieldGlyphs` loop head | skip live maskers; add a `only_mc` filter (a file-static set by a new `actionIterateTextFieldGlyphsForMC`) — ~6 lines, no refactor of the 300-line body |
| `action.c:28598` | `actionIterateAttachedBitmaps` | skip live maskers |
| `tag.c` (new statics near `3135`) | `avm1_masker_for_entry`, `entry_is_live_masker`, `draw_mc_mask_geometry` | §3.4 / §3.6 |
| `tag.c:3374-3572` | `render_display_list` | masker skip + push/restore hooks; `end_clip` → `restore_clip(pre_clip_ref)` (§3.7) |
| `tag.c:5645-5720` | `tagRerenderFrame` loop | same hooks |
| `tag.c:6563-6694` | `tagShowFrame` loop | same hooks |
| `tag.c:4873-4878` | `textfield_glyph_render_cb` field clip | gate the rect draw on `!g_clip_mask_capture` |
| `tag.c:6702+` | root-attached pass / `render_attached_child` | masker skip + push/restore |

**Phase 2 (optional, needed for `scroll_rect_mask`) — AVM1 `scrollRect`
translate.** `action.c:15726`'s `extra_props[]` stub becomes a real
getter/setter storing `sr_*` on the MovieClip; the composed transform for that
MC's subtree gets `(-x, -y)`; the crop rect is pushed as a mask **only when
`g_clip_mask_capture == 0`**. This is defect C's AVM1 half and is **not** owned
by this session's sibling (which has the AVM2 half). Also unblocks
`visual/cache_as_bitmap/scroll_rect` (18378) and `scroll_rect_scaled` (41902),
which are AVM1 and use no `setMask` — i.e. Phase 2 is worth more on its own than
as a rider here.

**Phase 3 (optional) — masked EditText**: push the masker stencil around a field
that is itself a maskee. No corpus comparison needs it; symmetry only.

### 4.2 Canary set

Standing set (`ruffle-tests/render_canary_tests.txt`, 20 tests / 37 cmps —
already carries `avm1/mask_with_drawing`, `avm1/movieclip_setmask`,
`visual/simple_shapes/masks`, `regression/mask_sibling_union`) **plus**:

```
# must-not-break, in risk order
avm1/mask_reapply                       ** HIGHEST RISK ** — clipDepth+setMask, passes at tol 1;
                                        this patch CHANGES its code path (§3.5)
from_shumway/acid/acid-clip-2           2881/3000 outliers — most fragile pass in the corpus
from_shumway/invalidClipDepth           257 clip ranges
from_shumway/clipping, MaskTest-3       (MaskTest-3: check TRACE stays `ruffle_matched`)
avm2/{mask_reapply, displayobject_mask, blend_scroll}   s12's flips must hold
regression/mask_sibling_union           the one locally-gradeable mask golden (tol 0)

# EditText blast radius of the field-clip gate (tag.c:4873)
avm1/edittext_tag_indent (tier 1)
visual/cache_as_bitmap/edittext_scroll, edittext_hscroll
visual/edittext/edittext_border_transform
from_shumway/acid/acid-textfield-scroll (552/600 outliers — tight)

# expected-to-move ledger
visual/simple_shapes/{text_field_mask, scroll_rect_mask}
```

Plus the §3.7 `restore_clip` change means every nested-clip test is exposed:
`visual/simple_shapes/masks` + `masks_equal_clipdepth` (both must stay at
**exactly 1686** — that residual is rasteriser edge drift, *not* a mask defect;
s12 report §4), `from_shumway/acid/*`.

New regression test worth adding with the patch: an AVM1 SWF where a
timeline-placed sprite is `setMask`ed by another timeline-placed sprite
(axis-aligned rectangles only, so it is golden-stable), companion to the
existing `regression/mask_sibling_union`. Golden must come from an oracle
outside SWFRecomp (playbook §7) or ship with `skip/no_expected_image`.

### 4.3 Expected-flip ledger (honest version)

| comparison | HEAD | after Phase 1 | after Phase 1+2 | verdict |
|---|---:|---:|---:|---|
| `visual/simple_shapes/text_field_mask` | 431740 | **~90 ch (~30 px)** | same | near-pass, −99.98 % |
| `visual/simple_shapes/scroll_rect_mask` | 434284 | ~17 000 (circle off by 10 px) | ~small circle-edge tie | band move −96 %, then near-pass |
| `avm1/mask_reapply` | pass | pass **(must verify)** | pass | regression risk |
| `avm1/{movieclip_setmask, mask_with_drawing}` | pass | byte-identical (Drawing-API path untouched) | ditto | control |

**Predicted flips: 0–1** (only if lavapipe's 1-sample glyph/circle edge ties
land on Ruffle's side). Predicted band moves: 2, both large. Predicted
regressions: 0, contingent on §3.5.

---

## 5. The measurement behind the refutation

`text_field_mask` renders its masker today as ordinary grey text, so the actual
PNG contains our glyph raster *of the same field at the same transform* that the
fix would use as the stencil. Comparing that silhouette with the golden's
non-white silhouette, restricted to the columns our field-bounds clip lets
through (`x < 193`):

```
ours 3010 px   golden 3008 px   XOR 10 px
rows identical:      125..169 both
column runs identical: (3,59) (62,119) (122,178)   ours then truncated at 192
golden continues:      (181,238) (241,297) ... (538,549)     [11 W's]
```

The 10 mismatches are isolated single pixels on the `W` diagonals, five in each
direction — sample-point ties at `MSAA_SAMPLES = 1`, not a systematic offset.
Scaling 10 px / 3.2 glyphs to 11 glyphs gives **~34 px ≈ ~90 excess channels**
against `tolerance = 0, max_outliers = 0`.

Two conclusions:

1. Our glyph rasterisation and placement are **already Ruffle-exact to within a
   handful of tie pixels** — the mask fix will make this comparison structurally
   correct.
2. The comparison will nevertheless most likely still **fail**, in the same way
   the s12 mask-edge family (`displayobject_mask` 8, `MaskTest` 17,
   `mouse_pick_*_dobj_mask` 24) fails. Those are the honest neighbours of this
   number, and s12's own advice applies: read them off an `images=true` run
   before spending a session on them.

Same story for `scroll_rect_mask`: with Phase 1 the mask is the right *shape* in
the wrong *place* (10 px), and Phase 2 puts it in the right place modulo a
circle-edge tie over a 628 px circumference.

---

## 6. Traps for the wave-2 agent

1. **Verify `setMask` even accepts the TextField argument.** `action.c:70670`
   rejects `OBJECT`/`FUNCTION`/`ARRAY` args outright. `txt` resolves through the
   lazy EditText **MovieClip wrapper** (`MC_IS_TEXTFIELD`,
   `action.c:26338`), so it *should* arrive as `ACTION_STACK_VALUE_MOVIECLIP` —
   but this is 5 minutes to confirm and the whole test depends on it. Recipe:
   `SWF_KEEP_BUILD_DIR=<dir> verify_output.py …` then run `<dir>/test_run`
   directly (`verify_output.py` swallows the binary's stderr, and `--verbose`
   does not surface it — s12 report §8).
2. **`grep 'setMask' *.swf` misses 3909 of 4949 corpus SWFs** — they are
   CWS/ZWS compressed. Decompress before scanning (§1.3).
3. **AVM1 pushes call arguments in reverse.** `scroll_rect_mask`'s rectangle is
   `(10,10,100,100)`, not `(100,100,10,10)`. Reading it wrong makes the golden's
   `(-10,-10)` shift look inexplicable.
4. **`avm1/mask_reapply` is the canary that matters**, not `movieclip_setmask`.
   The s10 report named the wrong one: `movieclip_setmask` is pure Drawing-API
   and this patch cannot touch it, while `mask_reapply` is timeline `clipDepth`
   + `setMask` and this patch *changes its rendering route* (§3.5).
5. **Never store a `DisplayObject*`.** If a later iteration feels like it needs
   one, that is the s10 design coming back; re-read §2 and `swf.h:138-155`.
6. `visual/simple_shapes/masks` / `masks_equal_clipdepth` (1686) are **not** in
   this slice and must not move — they are rasteriser edge drift (s12 §4).
