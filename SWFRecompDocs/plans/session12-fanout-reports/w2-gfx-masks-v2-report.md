# w2-gfx-masks **v2** — merge reconciliation with `w2-gfx-bitmapmax`

Supersedes `w2-gfx-masks-report.md` / `w2-gfx-masks.patch` (v1). Same worktree
(`.claude/worktrees/agent-a8c00c876e87e1966`), branch
`worktree-agent-a8c00c876e87e1966`. No commits to `master`, no pushes, no full
suites, `-P 2` throughout.

**Deliverables** (in the worktree; the isolation guard blocks the shared
checkout, please copy out):

```
SWFRecompDocs/plans/session12-fanout-reports/w2-gfx-masks-v2.patch        (303 lines, 4 files, +169/-27)
SWFRecompDocs/plans/session12-fanout-reports/w2-gfx-masks-v2-report.md    (this file)
```

**Apply order, verified:** bare `f166e424e` → `w2-gfx-bitmapmax.patch` →
`w2-gfx-masks-v2.patch`. I reset the worktree to a clean `f166e424e`, applied
the sibling's patch, committed it locally (`29b3b0604`), rebuilt my delta on
top, and then re-verified that the v2 patch `git apply --check`s cleanly against
exactly that base.

---

## 1. Which clip-depth implementation survived, and why

**Mine, extended to keep everything the sibling's version did.** The two loops
turned out to be the *same* loop — Ruffle's `render_children` reduced to
`tag.c`'s single-active-range form — so this was a superset merge, not a choice
between rivals.

| behaviour | `w2-gfx-bitmapmax` | v1 `w2-gfx-masks` | **merged v2** |
|---|:--:|:--:|:--:|
| single-active-range clip loop, range closed *before* the child is considered | ✅ | ✅ | ✅ |
| `visible` ignored inside a mask capture | ✅ | ✅ | ✅ |
| masker never painted as content (`clip_depth` child) | ✅ | ✅ | ✅ |
| masker never painted as content (`maskee`, i.e. AS `.mask`) | ✗ | ✅ | ✅ |
| `DisplayObject.mask` clips the node + subtree, under the *masker's* world matrix | ✗ | ✅ | ✅ |
| `do_set_mask` retires `clip_depth` on both objects (Ruffle `set_mask`) | ✗ | ✅ | ✅ |
| nested clip range restores the ENCLOSING stencil reference | ✗ (documented as a known limitation, explicitly deferred to me) | ✅ | ✅ |
| dynamic bitmap cap → `bitmap_highest` (`avm2_render_init`) | ✅ | — | ✅ **untouched** |

Concretely, in the merged `avm2_render_node` child loop:

* the sibling's `int32_t active_clip_depth` scalar and its "end the range BEFORE
  the child is considered" ordering are **kept verbatim** — that ordering is
  what makes the acid nose correct;
* `renderer_end_clip(context)` is replaced by
  `renderer_restore_clip(context, pre_clip_ref)`, which is the *only*
  behavioural change to the sibling's range logic. `end_clip` zeroes `mask_ref`
  unconditionally; `restore_clip` puts back whatever clip was active when the
  range opened. At the top level `pre_clip_ref == 0` and the two are identical
  — which is why every acid comparison is byte-identical between the two legs
  (§3) — but it closes the sibling's own §2.6 *"Known limitation: a clip range
  active when the walk recurses into a child container that opens its own clip
  range loses the outer stencil test… Fixing it needs the renderer to expose a
  save/restore of `mask_ref`, which is `w2-gfx-masks`'s territory."* The two new
  renderer entry points (`render_webgpu_clip_ref` / `_restore_clip`) are exactly
  that;
* the counter keeps the **sibling's** name `g_avm2_mask_capture` (v1 called it
  `g_avm2_drawing_mask`) to minimise the diff against the committed base. Any
  reference to `g_avm2_drawing_mask` in the v1 report means this variable.

### The acid nose, traced through the merged loop

`Place d=185 char=22 clip=187` then `Place d=186 char=8` (the ellipse):

```
child depth 185: active_clip_depth == 0, so no range to close.
                 cext->clip_depth (187) > 0 and no capture is open
                 -> pre_clip_ref = clip_ref() = 0
                 -> push mask (stencil = the diamond), active_clip_depth = 187,
                    continue  (the diamond is never painted)
child depth 186: 186 > 187 ? no  -> rendered against the stencil = ellipse ∩ diamond
end of list:     active_clip_depth > 0 -> restore_clip(0)
```

Identical to the sibling's trace. Verified empirically: all 16 `acid`
comparisons are byte-identical between the sibling-only tree and the merged
tree, including the tight `output.01` at **8669 / 9100 outliers — the same 431
channels of headroom** the sibling measured.

### One nuance where the two implementations are *not* independent

The sibling's loop paints `mask2` (a `clipDepth` child) as a mask and paints
`maskee2` as clipped content. My masker suppression (`ext->maskee != NULL →
return`) removes `maskee2` from the paint pass, which is correct Ruffle
behaviour — **but only once `do_set_mask` has also cleared `clip_depth`**, or
`avm2/mask_reapply`'s second (deliberately backwards) pair loses a patch
entirely. That is why the two v1 hunks have to travel together, and it is a
correction to the v1 report:

> **v1 said** the `do_set_mask` `clip_depth` retirement is what *flips*
> `avm2/mask_reapply` (36156 → 0).
> **v2 measures** that the sibling's clip-depth loop *alone* already flips it
> (`sibonly` = `pass 0`). The retirement is not what wins the flip — it is what
> **keeps** the flip once masker suppression is added. Both trees land on the
> same pixels by different routes; the merged one is the Ruffle-faithful route
> (`display_object.rs::set_mask` really does `set_clip_depth(0)` on both sides).

Nothing else in the v1 report's numbers moved. Every other v1 result is
reproduced below against the new baseline.

---

## 2. Union verification — 52 tests / 96 comparisons

Both legs captured in this worktree with `--recompile`, `-P 2`, local Dawn.
`sibonly` = `f166e424e` + `w2-gfx-bitmapmax` (my delta stashed);
`merged` = the same tree + `w2-gfx-masks-v2`. So every DIFFERS below is **my
delta's effect alone**, on top of the sibling's patch.

```
RENDER CANARY  before=sibonly  after=merged   52 tests / 96 comparisons
  IDENTICAL    83
  DIFFERS      11
  APPEARED      0   VANISHED 0   NO_RENDER 2   (acid output.17/.18, pre-existing)
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**All 11 movers improved. Nothing worsened. Zero trace-status changes across all
52 tests, including the three trace-only clipDepth tests.**

### 2.1 What my delta adds on top of the sibling's patch

| comparison | sibonly | merged | note |
|---|---:|---:|---|
| `avm2/displayobject_mask [output]` | 12984 | **8** | `DisplayObject.mask`; 4 px left (§4) |
| `avm2/mouse_pick_non_interactive_dobj_mask [output]` | 13118 | **24** | ditto |
| `avm2/mouse_pick_dobj_mask [output]` | 5403 | **24** | ditto |
| `from_shumway/MaskTest [output]` | 3341 | **17** | ditto |
| `visual/cache_as_bitmap/masks [output.01]` | 59137 | 6869 | −88 % |
| `visual/cache_as_bitmap/masks [output.02]` | 69060 | 14557 | −79 % |
| `visual/cache_as_bitmap/masks [output.03]` | 72114 | 20234 | −72 % |
| `visual/cache_as_bitmap/masks [output.04]` | 68228 | 26177 | −62 % |
| `visual/cache_as_bitmap/masks [output.05]` | 65102 | 20906 | −68 % |
| `visual/cache_as_bitmap/masks [output.06]` | 66730 | 15581 | −77 % |
| `visual/cache_as_bitmap/masks [output.07]` | 65967 | 16491 | −75 % |

### 2.2 The sibling's results, preserved byte-for-byte

| comparison(s) | sibonly | merged |
|---|---|---|
| `from_shumway/acid/acid [output.01–.16]` (16) | `pass 0` | **`pass 0`, byte-identical**; `output.01` 8669/9100 in both |
| `from_shumway/acid/acid [output.17/.18]` | NO_RENDER | NO_RENDER (pre-existing, untouched) |
| `from_shumway/acid/acid-clip-3 [output]`, `[frame3]` | `pass 0` | `pass 0` |
| `from_shumway/acid/acid-color [output]`, `[frame1]` | `pass 0` | `pass 0` |
| `from_shumway/acid/acid-image [output]` | `pass 0` | `pass 0` |
| `from_shumway/acid/acid-big [output]` | `pass 0` | `pass 0` |
| `from_shumway/3_joystick [output]` | `fail 7483` | **`fail 7483` — did not worsen** |
| `avm2/{graphics_bitmaps, graphics_bitmap_fill, bitmap_subclass_properties, bitmapdata_copychannel, pixelbender_images}` | unchanged | unchanged (the anchor's bitmap control group) |
| `avm2/mask_reapply [output]` | `pass 0` | `pass 0` (see §1's nuance) |

### 2.3 My v1 targets and traps, re-confirmed on the merged tree

| comparison | merged | note |
|---|---|---|
| `regression/mask_sibling_union [output]` | **`pass 0`** | the one locally-gradeable mask golden — still byte-exact at `tol 0 / max_out 0` |
| `from_shumway/acid/acid-clip-2 [output]` | `pass 0` | trap (the corpus's most fragile pass), byte-identical |
| `from_shumway/invalidClipDepth [output]` | `pass 0` | trap (257 invalid clip ranges), byte-identical |
| `from_shumway/MaskTest-3` | `pass 0`, trace `ruffle_matched` | unchanged on both axes |
| `avm2/blend_scroll [output]` | `pass 0` | byte-identical |
| `avm2/displayobject_scrollrect [output]` | `fail 202388` | **control** — scrollRect deliberately untouched |
| AVM1 path: `avm1/{color, bitmap_data_fillrect, mask_with_drawing, movieclip_setmask, mask_reapply, edittext_tag_indent, focusrect_swf5 ×12, bitmapdata_applyfilter_colormatrix}` | all `pass 0` | 20 comparisons, byte-identical |
| `visual/simple_shapes/masks [output]` | `fail 1686` | byte-identical — and **not a mask defect** (§4) |
| text `visual/edittext/edittext_border_transform ×6` | unchanged (incl. the 31 / 24 non-zero) | |
| `regression/` suite ×6 | unchanged | |
| `avm2/mouse_pick_masking`, `from_shumway/hittesting/hittesting`, `from_shumway/timeline/nav/clipDepth` | trace-only, **no status change** | the three no-image clipDepth tests from the sibling's blast-radius scan |

---

## 3. Combined effect vs bare `f166e424e` (what CI should show)

Merging the two ledgers — the sibling's `before` (its own report §1/§2.4/§2.5)
and mine (v1 report §2) — against the merged tree's measured values:

| owner | comparison(s) | HEAD | merged | verdict |
|---|---|---:|---:|---|
| bitmapmax | `acid-color [output]`, `[frame1]`, `acid-image`, `acid-big` | 590200 / 564945 / 44715 / 786432 | 0 | **4 flips** |
| bitmapmax | `from_shumway/acid/acid [output.01–.16]` | fail ×16 | pass ×16 | **16 flips** |
| shared | `acid-clip-3 [output]`, `[frame3]` | 76460 / 78880 | 0 / 0 | **2 flips** |
| masks | `avm2/mask_reapply [output]` | 36156 | 0 | **1 flip** |
| masks | `avm2/displayobject_mask [output]` | 12984 | 8 | near-pass |
| masks | `from_shumway/MaskTest [output]` | 3341 | 17 | near-pass |
| masks | `avm2/mouse_pick_dobj_mask [output]` | 5403 | 24 | near-pass |
| masks | `avm2/mouse_pick_non_interactive_dobj_mask [output]` | 13118 | 24 | near-pass |
| masks | `avm2/mouse_pick_non_interactive_bitmap_mask [output]` | 2500 | 625 | band move |
| masks | `avm2/bitmapdata_draw_masks [output]` | 12150 | 5850 | band move (CPU-raster half remains) |
| masks | `visual/cache_as_bitmap/masks [.01–.07]` | 59137–72114 | 6869–26177 | 7 band moves |
| bitmapmax | `from_shumway/3_joystick [output]` | 70634 | 7483 | band move |
| — | `cab_mask_{triangle,alpha,transform,filters}` | 5080/4644/2340/4968 | unchanged | **negative result** (§5) |

**Predicted CI comparison flips for the pair: +23** (16 acid + 4 bitmap-cap +
2 acid-clip-3 + 1 mask_reapply), 4 near-passes at 8–24 excess channels, 11
further band moves, **zero regressions on either axis**.

`avm2/mask_reapply`'s local `before` of 36156 reproduces CI's published number
exactly, and s11 verified that test's local PNG byte-identical to the CI actual,
so its flip is CI-credible. The near-passes at 8–24 channels are stencil-edge
sample-point ties and **may already score 0 on lavapipe** — read them off the
next `images=true` run rather than treating them as known failures.

---

## 4. Findings carried over from v1 (unchanged by the merge)

* **`avm2/mask_reapply` and `acid/acid-clip-3` are NOT `tag.c`-path tests.**
  s11's `wave1-gfx-masks.md` filed them as "a third, unowned `tag.c` mechanism"
  because their checked-out test dirs had no `RecompiledABC/`. That directory is
  **generated by the recompiler at test time** (`SWFRecomp/src/swf.cpp:284`), so
  its absence proves nothing. Both SWFs carry a `DoABC`/`DoABC2` tag; both are
  plain AVM2-walk tests. Read the SWF tag list, never the checked-out dir.
* **`visual/simple_shapes/masks` (1686) is not a mask defect and cannot be
  reached by B, C or D.** No `DoABC`, no `setMask`, no `scrollRect`. Its 1686
  outlier channels are 776 one-pixel slivers spread over the whole stage
  (`bbox (17,8)-(544,388)`), every diff between two *saturated* palette colours
  with no intermediate values — i.e. rasteriser edge drift at `MSAA_SAMPLES = 1`
  (`quality = "low"`, s11). It belongs in `hairline_edge_drift`, not the mask
  cluster; no future mask session should book it.
* **Defect B (AVM1 `setMask` on display-list content) — CONFIRMED, not shipped.**
  Zero `mask_mc` / `is_mask` references in `tag.c` at HEAD. Two reasons it is not
  here: (a) the s10 fix design stores a `DisplayObject*` into a **realloc'd,
  depth-indexed array** (`sprite-dl-realloc-rebase`) — a use-after-free; it must
  be a depth plus an owning-list discriminator, or resolved at render time from
  `mc->display_obj`; (b) its one booked flip (`text_field_mask`) re-prices to
  *uncertain* — it is `quality = "low"` so no longer AA-blocked, but its content
  is glyph outlines and the `masks` measurement above shows two rasterisers at
  1 sample still disagree by hundreds of edge pixels on curves.
* **Defect C (`scrollRect`) — CONFIRMED, owned by the `scrollRect` sibling.**
  The AVM2 half is ~20 lines now that `clip_ref` / `restore_clip` exist; the
  exact code, and Ruffle's ordering caveat (the scroll translate is pushed
  *before* the mask transform, so a scrolled-and-masked object conjugates its
  mask by the translate), are in v1 report §6.1. `avm2/displayobject_scrollrect`
  sat at `fail 202388` in both legs, which is the control proving it is untouched.

---

## 5. Leftovers, re-ranked after the merge

1. **Nesting intersection** — now the single largest semantic gap in the mask
   model, and it is the *shared* one. `begin_clip_mask` is `Always/Replace` at a
   fresh reference, so a mask inside a mask replaces its parent instead of
   intersecting; `restore_clip` recovers the enclosing reference but not the
   overwritten overlap. `regression/mask_nested_intersect` (built and validated
   by s11, generator at
   `session11-fanout-reports/w2-masks-r2-mask_nested_intersect.py`, deliberately
   not in the suite) is the pin test, still failing at 10800. Fix = s11 §6's
   `Equal/IncrementClamp` write + `Equal/DecrementClamp` clear with a
   full-screen decrement draw — **one renderer change that now fixes both
   walks**, and it makes `restore_clip` exact instead of approximate.
2. **`avm2/bitmapdata_draw_masks` (5850).** `BitmapData.draw` runs the CPU
   rasteriser (`avm2_cpu_raster.c`, "the CPU twin of `avm2_render_node`"), which
   has no mask code. Needs the same four rules ported into the twin.
3. **`visual/cache_as_bitmap/masks [.01–.07]`.** Moved 62–88 %, first movement in
   three sessions, still failing — now gated by the missing bitmap-cache path,
   not by masks. The s11 KEEP disposition ("mask-blocked") should be re-worded.
4. **`cab_mask_{triangle,alpha,transform,filters}` — byte-identical under a patch
   that moved their `cache_as_bitmap/masks` sibling by 62–88 %.** They are a
   different mechanism; s10 §4's "treat `cab_mask_*` as one block with
   `cache_as_bitmap/masks`" is wrong and should be un-bundled.
5. **The mask-edge tie family (8 / 17 / 24 / 24).** `avm2/displayobject_mask` is
   literally 4 pixels — `(43,10) (56,10) (10,43) (10,56)`, symmetric about the
   diagonal, where we keep the maskee's red and the golden has white. Both sides
   MSAA-4 a stencil boundary. Check CI before spending a session.
6. **Defect B**, with the pointer-safety correction in §4.

---

## 6. Merge / risk notes for the coordinator

* **Apply order is load-bearing**: `w2-gfx-bitmapmax.patch` first, then
  `w2-gfx-masks-v2.patch`. v2 does **not** contain the bitmap-cap hunk, and it
  does not stand alone on bare `f166e424e`.
* **v1 is superseded** — `w2-gfx-masks.patch` and `w2-gfx-masks-report.md` should
  not be applied alongside v2; they conflict with the sibling by construction.
  The v1 report remains useful for the `mask_reapply` ABC decompilation, the
  `masks` 1686 pixel analysis and the defect-B/C write-ups, all of which v2
  carries forward in condensed form (§4).
* **`render_webgpu.c`**: my only edit is a 27-line insertion immediately after
  `render_webgpu_end_clip` (~2655) — two new functions, nothing existing
  touched. No overlap with `w2-gfx-bitmapmax` (which does not touch the file at
  all), `w2-gfx-filters` (blur kernels) or `w2-gfx-bitmapmax`'s texture-init
  region. **Standing invariant: I added no pipeline, so there is no new
  `multisample.count`; the file still has no literal `4` sample count.**
* **`avm2_display.c`**: two regions — `do_set_mask` (~4195, +11/−1) and
  `avm2_render_node` (~15095-15290, +147/−26, which rewrites the child loop the
  sibling's patch introduced). `avm2_render_init`'s bitmap-cap hunk is
  **untouched** (verified: `git diff` of v2 contains zero `bitmap_highest`
  lines).
* **`tag.c` untouched**; `w2-gfx-autosize`'s read-only reference at `tag.c:4741`
  is unaffected.
* **Semantic risk introduced by masker suppression**: a masker whose geometry
  does not rasterise (empty Sprite, un-tessellated Graphics) now clips its
  maskee *away* rather than leaving it unclipped. That is Ruffle's behaviour but
  it converts "wrong but visible" into "blank" where our geometry coverage is
  incomplete. Nothing in the 52-test union regressed that way; the wider AVM2
  pixel surface is only sampled here, so an `images=true` run is the real check.
* **CI**: runtime-only, cannot move a trace (52-test union confirms: zero trace
  status changes). `graphics`, `categories=all`, `images=false` per policy — but
  the 23 flips are invisible without an `images=true` baseline run.
* **Local commit** `29b3b0604` on `worktree-agent-a8c00c876e87e1966` holds the
  sibling's patch as the rebase base. It exists only in this worktree's branch;
  `master` is untouched.
