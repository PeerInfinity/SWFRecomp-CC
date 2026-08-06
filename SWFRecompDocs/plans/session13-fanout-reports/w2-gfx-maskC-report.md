# w2-gfx-maskC — mask defect C, the AVM2 `scrollRect` half

Session 13, wave 2. Implemented in an ISOLATED worktree
(`.claude/worktrees/agent-aaa81e42252eac45a`, base `10931d62e` = session-12
closeout). **No commits, no pushes, no full suites.** Deliverables copied to the
scratchpad:

```
w2-gfx-maskC.patch          git diff — 1 file, +61 / −0  (SWFModernRuntime only)
w2-gfx-maskC-report.md      this file
```

`SWFRecomp/build` was copied from the main tree (the patch does not touch the
recompiler — verified: the diff is one runtime file). Test dirs were `cp -r`'d
into the worktree's canonical suite paths and both canary legs ran with
`--recompile`. Machine shared with ~7 agents (load 15–20) throughout; `-P 2`.

---

## 1. Headline

| | |
|---|---|
| shape | one new 17-line static helper + a 20-line block in `avm2_render_node`, both in `SWFModernRuntime/src/avm2/avm2_display.c` |
| canary | **43 IDENTICAL / 2 DIFFERS / 0 APPEARED / 0 VANISHED / 0 NO_RENDER**, 31 tests / 45 comparisons; **zero trace status changes** |
| the 2 movers | `visual/avm2_button_scroll_rect` **34083 → 12** (4 px, near-pass), `avm2/displayobject_scrollrect` **202388 → 12382** (−94 %) |
| regressions | **none, on either axis.** Nothing outside the two scrollRect tests moved a single byte. |
| residual, diagnosed | 100 % of `displayobject_scrollrect`'s remaining 12382 is the **flat-stencil nesting limitation** (masks Replace instead of intersect), i.e. the s11 §6 / s12 §6.2 renderer lead — *not* a scrollRect modelling error (§4) |

The design in `w2-gfx-masks-report.md` §6.1 was **essentially accurate and still
applies at HEAD**; three small adaptations were needed (§3).

---

## 2. What changed

### 2.1 `avm2_push_scroll_rect_mask()` — new static helper (17 lines)

Writes the crop rectangle into the stencil. Ruffle
(`display_object.rs::apply_standard_mask_and_scroll`, lines 1174–1231) builds it
as `cur_transform.matrix * Matrix::scale(w_px, h_px)` — a unit rect scaled to the
rect's size, under the node's world matrix, with **the scroll translation
deliberately not applied to it**. Ruffle's renderer space is pixels; ours is
twips, so the quad is `(0,0)-(w,h)` twips written straight through
`renderer_draw_rect` between `renderer_begin_clip_mask` / `_end_clip_mask`.

It consumes one xform slot (same bump-allocator pattern as `avm2_render_shape`,
identity fallback at slot 0 when slots run out) and **no cxform slot** — colour
writes are off inside a stencil capture, so cxform id 0 (identity) is passed and
`g_avm2_cur_cx` is neither read nor published.

A degenerate rect (`w == 0` or `h == 0`, which `displayobject_scrollrect`
deliberately produces via its rounding cases) writes no stencil texels and
therefore hides the subtree. That is Ruffle's and Flash's behaviour, and it is
called out in the comment so it does not read as a bug later.

### 2.2 `avm2_render_node()` — the crop + the scroll (20 lines)

Placed **after** the `DisplayObject.mask` block and before the node draws its own
content:

```c
uint32_t saved_sr_ref = 0;
int pushed_scroll_rect = 0;
if (ext->has_scroll_rect && g_avm2_mask_capture == 0)
{
        saved_sr_ref = renderer_clip_ref(context);
        avm2_push_scroll_rect_mask(&world, ext);   // crop, PRE-translate world
        pushed_scroll_rect = 1;
        Mat sr_tr = { 1,0,0,1, -(double) ext->sr_xmin, -(double) ext->sr_ymin };
        world = mat_mul(&world, &sr_tr);           // scroll, content + subtree
}
```

with a matching `renderer_restore_clip(context, saved_sr_ref)` at the end of the
function, ordered LIFO **before** the existing `pushed_mask` restore.

Four things this gets from the s12 machinery for free:

* `renderer_clip_ref` / `renderer_restore_clip` (the two entry points
  `w2-gfx-masks-v2` added) make the crop nestable — a scrollRect inside a
  clipDepth range or inside a `DisplayObject.mask` restores the enclosing
  reference instead of dropping the clip, which `renderer_end_clip` would have
  done;
* the crop stays live across the node's own content, its `SimpleButton` state
  child, and the whole `render_list` walk, because the child loop's own
  `pre_clip_ref` save/restore nests correctly inside it;
* `g_avm2_mask_capture == 0` keeps the crop out of a mask capture, where
  `begin_clip_mask` is a no-op and the rect would otherwise be added to the
  *masker's silhouette*;
* the s12 AVM2 EditText glyph clip already self-disables when
  `context->mask_ref != 0` (`avm2_display.c:15337`), so a TextField inside a
  scrollRect subtree falls back to unclipped glyphs rather than punching a hole
  in the crop. That interaction is pre-existing and correct; noted in §6.

---

## 3. Adaptation notes vs the s12 §6.1 design

The design was written against v1 of the masks patch; the **v2 superset** is what
merged. Three deltas, all small:

1. **Names.** §6.1 spells the guard `g_avm2_drawing_mask`; at HEAD the merged
   variable is `g_avm2_mask_capture` (v2 §1 records the rename). Used the HEAD
   name.
2. **Placement.** §6.1 puts the block "right after `world` is computed", i.e.
   *before* the `DisplayObject.mask` push. Ruffle pushes the scroll-rect stencil
   **after** the mask stencil ("this mask is applied *in addition to* a mask
   defined with `DisplayObject.mask`"). With our flat Replace stencil the two
   cannot intersect, so whichever is pushed last wins — putting it in Ruffle's
   order makes scrollRect the winner, which is what Ruffle's own command order
   produces in the degenerate case. The crop geometry is unaffected either way
   because it is built from the pre-translate `world`.
3. **Helper instead of inline.** §6.1 sketches the stencil write inline. It needs
   an xform slot write, so it became a small static function — keeps the diff
   inside `avm2_render_node` to 20 lines and avoids touching the wide shared
   walk any more than necessary (per the "prefer new small functions" brief).

Everything else in §6.1 — the pre-translate crop matrix, the `(-x_min, -y_min)`
content translate, `clip_ref`/`restore_clip`, and the *caveat that a
scrolled-and-masked object conjugates its mask by the translate in Ruffle but not
here* — carried over unchanged. The conjugation is still **not** modelled
(documented in the code comment); no corpus test in the canary exercises
scrollRect + `DisplayObject.mask` on the same object.

---

## 4. Results

Local Dawn A/B inside the worktree, `before` = HEAD with the patch stashed,
`after` = patched, both `--recompile`, `-P 2`. Numbers are **excess outlier
channels** vs the repo golden; the local *absolute* verdict is never a grade
(CI is lavapipe), only the A/B delta is.

```
RENDER CANARY  before=maskC_before  after=maskC_after   31 tests / 45 comparisons
  IDENTICAL    43
  DIFFERS       2
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

| comparison | before | after | verdict |
|---|---:|---:|---|
| `visual/avm2_button_scroll_rect [output]` | 34083 | **12** | **near-pass — 4 pixels** |
| `avm2/displayobject_scrollrect [output]` | 202388 | **12382** | −94 % band move |

Everything else — all 43 other comparisons — is **md5-identical**, including the
whole standing `render_canary_tests.txt` set and the mask traps carried over from
s12:

| group | cmps | status |
|---|---:|---|
| standing canary tier 1 + tier 2 (`avm1/*`, `visual/*`, `from_shumway/*`, `regression/*`) | 40 | md5-identical, incl. `regression/mask_sibling_union` still `pass 0` |
| s12 mask flips/near-passes `avm2/mask_reapply`, `avm2/displayobject_mask` | 2 | held: `pass 0` and `fail 8`, byte-identical |
| traps `from_shumway/acid/acid-clip-2`, `from_shumway/invalidClipDepth` | 2 | `pass 0`, byte-identical |
| control `avm2/blend_scroll` | 1 | `pass 0`, byte-identical |

**Trace-side canary (5 mask/clip/scroll trace tests, run inside the worktree as
part of the same sweep):** `regression/mask_sibling_union` pass,
`avm2/mouse_pick_masking` pass, `from_shumway/timeline/nav/clipDepth`
`ruffle_matched`, `avm2/edittext_scrollh` pass, `avm2/displayobject_scrollrect`
`output_mismatch` — **every one identical to its before leg**. (The last one's
trace already failed at HEAD: CI has it at 19/33 lines, 57.6 %. It is a
localToGlobal/hitTest trace issue, untouched and untouchable by a render patch.)

### 4.1 The two movers, structurally

**`visual/avm2_button_scroll_rect`** — `button.scrollRect = Rectangle(10,10,100,100)`
on a `SimpleButton`. Before: the full circle. After: the render is
**structurally identical to the golden** — the shape's rounded top-left corner
kept, hard right and bottom edges from the crop, content shifted by (−10,−10).
The 12 residual channels are exactly **4 pixels**, at `(48,24) (40,30) (30,40)
(24,48)` — symmetric about the diagonal, on the rounded-corner curve, white where
the golden has the fill. `quality = "low"` ⇒ `MSAA_SAMPLES = 1`, so this is the
same one-sample rasteriser edge tie as the s12 mask near-passes
(`w2-gfx-masks-v2` §4). **It may already score 0 on lavapipe** — read it off the
next `images=true` run rather than pricing it as a failure.

**`avm2/displayobject_scrollrect`** — before: two full ellipses, no cropping at
all. After: the magenta parent is correctly cropped to the transformed 50×100
parallelogram and its content is scrolled by (−50,−60). The residual **6191
mismatching pixels are 100 % one mechanism**:

```
5672 px  actual (0,0,255)  expected (255,255,255)   blue child painted outside the PARENT crop
 519 px  actual (0,0,255)  expected (0,255,0)       green sibling punched out, blue shows through
bbox (92,80)-(182,196)                              entirely the region of the CHILD's crop rect
```

That is the **nested-mask non-intersection limitation**, not a scrollRect bug:
`scrollChild` has its own `scrollRect(100,100,60,70)` inside the parent's, and
`begin_clip_mask` is `Always/Replace` at a fresh reference, so the child's rect
overwrites the parent's stencil value in the overlap. `restore_clip` puts the
parent's *reference* back but cannot repair the texels the child overwrote —
which is precisely what `w2-gfx-masks-v2` §5 item 1 predicted and deferred. The
fix is the shared s11 §6 `Equal/IncrementClamp` write + `Equal/DecrementClamp`
clear; it would close this test's remaining 12382 **and** `mask_nested_intersect`
**and** make `restore_clip` exact, in one renderer change that serves both walks.

---

## 5. Expected CI movement

Runtime-only, AVM2 render walk only; **cannot move a trace** (the canary's zero
trace-status changes across 31 tests, including three trace-only clip tests, is
the check).

* **Pixel axis:** `visual/avm2_button_scroll_rect` is a **credible flip**
  (CI had it at 28851; local before 34083, after 12 = 4 edge-tie pixels).
  `avm2/displayobject_scrollrect` is a large band move (202388 → ~12382), still
  failing, now blocked only by nested-mask intersection.
  Expect **+1 comparison flip, 1 band move, 0 regressions**; both are invisible
  without an `images=true` baseline run.
* **Trace axis:** no change expected anywhere.
* Recommended CI: `mode=graphics`, `categories=all`, `images=false` per standing
  policy; dispatch `images=true` only if the coordinator wants the flip counted
  this session.

---

## 6. Merge risks / notes for the coordinator

* **One file, one region.** `SWFModernRuntime/src/avm2/avm2_display.c`, +61/−0:
  a new static function inserted immediately above `avm2_render_node`'s comment
  block (~15433), a 20-line block inside `avm2_render_node` after the
  `pushed_mask` push (~15530), and 4 lines at the function's tail restore. **No
  existing line was modified** except the tail restore, which gains two lines
  above it. Anyone else editing the AVM2 render walk this session (defect B is
  design-only this wave) will meet it at those two points.
* **`render_webgpu.c` untouched.** No new pipeline, therefore no new
  `multisample.count`; the standing `MSAA_SAMPLES`-never-literal-4 invariant is
  honoured trivially. Zero interaction with the blend/composite shader work.
* **`tag.c` untouched** — the AVM1 half of defect C (`scrollRect` as an inert
  `extra_props[]` entry in `action.c`) is unchanged and still open.
* **Composes with defect B**: B's design will add a `mask_mc` read to the
  `tag.c` display loops; this patch never enters `tag.c` and never changes the
  renderer's clip API, so the two are independent.
* **Semantic risk introduced:** any AVM2 object with a `scrollRect` now clips
  its subtree. Where our geometry coverage is incomplete this converts "wrong but
  visible" into "cropped away", and a zero-sized `scrollRect` now hides content
  (correctly). Nothing in the 31-test canary regressed that way, but scrollRect
  users outside the canary are only sampled here — an `images=true` run is the
  real check.
* **Side effect worth knowing:** setting a scrollRect makes `mask_ref != 0` for
  the subtree, which disables the s12 AVM2 EditText glyph stencil clip inside it
  (that clip self-disables under an outer mask by design). The scrollRect crop is
  the tighter clip in the common case; no corpus test exercises the difference.
* **Not modelled, deliberately:** Ruffle pushes the scroll translate *before*
  composing the `DisplayObject.mask` matrix, so in Ruffle a scrolled-and-masked
  object conjugates its mask by the translate. We render the masker under its own
  world matrix in both cases. Documented in the code comment; no corpus test hits
  it.
* **CPU-raster twin still blind.** `avm2_cpu_raster.c` (`BitmapData.draw`) has no
  mask *or* scroll-rect code (`grep` returns zero hits for both), so a scrolled
  object drawn into a BitmapData is still uncropped — same standing gap as
  `avm2/bitmapdata_draw_masks`.

## 7. Next step this unblocks

`displayobject_scrollrect` is now a **clean, isolated pin test for nested-mask
intersection**: its entire residual is that one mechanism, measured, with the
before/after PNGs in
`.render_canary/_compare/maskC_before__maskC_after/`. Together with
`regression/mask_nested_intersect` (built by s11, still out of the suite) and the
`cache_as_bitmap/masks` family, the `Equal/IncrementClamp` renderer change now
has three named beneficiaries and is the single highest-value remaining mask lead.
