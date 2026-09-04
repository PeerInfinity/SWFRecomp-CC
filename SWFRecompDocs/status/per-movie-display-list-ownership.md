# A loaded movie now loops, because its display children carry its name

**Date:** 2026-09-03 · **Arc:** Multi-SWF (loaded children), slice 6
**Baseline:** `1f1cade12` · **Brief:** `SWFRecompDocs/prompts/per-movie-display-list-prompt.md`
**Predecessor:** `SWFRecompDocs/status/child-timeline-advance.md`

**Landed:** a loaded movie wraps from its last frame back to its frame 1, takes
its own display children off the list on the way, and leaves everybody else's
alone. Ownership is one field on the display entry —
`DisplayObject::placed_by_holder` — not a per-movie display list.

**The brief's Route 1 fact was obtained first, and it changes the arc's map in
two places.** §1 has it. §2 has the ruling. §7 says why "looping and the
renderer are the same missing abstraction" is not true.

## 1. The Route 1 fact

**What `movieclip_invalid_get_bounds_1..8` read from `display_obj` is the
onEnterFrame eligibility gate, and nothing else.**

`action.c:37058`, in `actionDispatchEnterFrameHandlers`:

```c
if (mc->display_obj != NULL && !actionIsLoadedLevelRootMC(mc)) {
    DisplayObject* dobj = (DisplayObject*)mc->display_obj;
    if (!dobj->enterframe_eligible) continue;   // <- armed by a DISPLAY-LIST walk
    dobj->enterframe_eligible = 0;
} else if (mc->display_obj != NULL) {
    // _levelN root: in no display list, so the walk never arms it. Use the
    // dynamic-MC gate instead.
    if (!mc->mc_enterframe_eligible) continue;
}
```

`enterframe_eligible` is armed each tick by `set_enterframe_eligible_recursive`,
which walks display lists. A loaded movie's root — a `createEmptyMovieClip`
holder — is in no display list, so handing it a `display_obj` moves it into the
first arm and its `onEnterFrame` is never armed again. Every line those eight
tests lost is an `onEnterFrame` handler installed on a loaded movie's own root:
`Child7.as`'s `this.onEnterFrame` and `Parent7L7.as`'s.

Measured, not inferred. With the holder given a `DisplayObject` (no list swap),
`movieclip_invalid_get_bounds_1` loses exactly:

```
     1  Test file 1
     2  Child (7) loaded
-    3  Child (7) 6710886.35        <- Child7.swf's own this.onEnterFrame
...
-    9  Child (7) 6710886.35
-   10  Parent (7) 6710886.35       <- Parent7L7.swf's own this.onEnterFrame
```

**The decisive part: the runtime already had the escape hatch.**
`actionIsLoadedLevelRootMC` exists for `_levelN` roots, which have exactly this
shape — a synthetic `DisplayObject` in no display list. Widening that one
predicate from "is a level root" to "is a loaded movie's root" is two lines, and
it recovers **6 of the 8** tests:

```
gate widened -> movieclip_invalid_get_bounds_{1,2,3,4,5,8} pass, {6,7} still fail
```

So the brief's worry — that the 48 `display_obj != NULL` sites need a different
predicate — is **not what the corpus was saying.** 47 of them were never the
problem; one was, and it already had a hatch for the identical case.

### 1.1 What `_6` and `_7` read is a different thing, and it is an artifact

They read `getBounds`. `action.c`'s bounds path takes
`mc->display_obj->sprite_display_list` when it is non-NULL, and its
"Fallback for loaded child SWFs: content is on root display_list" branch is
gated on `mc_dl == NULL`. Give the holder a display list and never put anything
in it, and the fallback is skipped in favour of an empty list.

That is not a Route 1 blocker. It is a statement that **the predecessor's
bisect half A is not a subset of half B** — "allocate a list but never fill it"
is an incoherent state that neither route ever ships. Under half B (list
allocated *and* swapped) `_6` moves on to a different, real failure:

```
-    2  Child (8) 550.45          +    2  Child (8) 6710886.4
-    3  Parent (7) 6710886.4      +    3  Parent (7) 0.45
```

Line 3 is `unloadMovie(mc)` failing to empty the holder's private list — a
genuine Route 1 work item (the loaded-child bounds fallback becomes dead code
and must go; `unloadMovie` must clear the list it now owns).

### 1.2 `swf{5_to_6,6_to_5}_cross_call` is the display-list swap, and it is
### structural

Bisected to the **direct-`loadMovie`** swap alone; the MCL-path swap is
innocent (`SWF_PROBE_DIRECT_SWAP` / `SWF_PROBE_MCL_SWAP`, one binary, four
runs). Then instrumented with SWAP-IN / SWAP-OUT markers around the swap:

```
[PROBE] SWAP-IN
child f():          <- the CHILD's own traces, correct
 this: _level0.clip
...
clip.f():           <- the PARENT's test block, bodies GONE
_root f():
root obj toString:
[PROBE] SWAP-OUT
```

The parent's entire test block runs **inside** the swap. `child.swf` calls back
into `_root.onLoaded()` during its own frame 1, so the parent's name resolution
runs against the child's display list.

**That is the finding.** The swap is scoped to a *call*, not to a *movie*. Any
parent code re-entered during a child's frame — a load callback, a shared
function, a listener — inherits the wrong list, and there is nothing about
where the swap is placed that can fix it, because a single global `display_list`
pointer cannot express "these entries belong to that movie" while two movies'
code is on the stack at once. `_levelN` has carried the same hazard all along;
it is simply not graded.

## 2. The ruling

**Route 1 is viable and is a sub-arc, not a slice. Route 2 shipped, in the
shape Route 1 has to converge on anyway.**

- The `display_obj` half of Route 1 is cheap and correct (§1) and should be
  taken *as part of* the display-list work, not before it — on its own it
  changes no behaviour.
- The display-list half has at least three distinct owners already measured:
  the loaded-child bounds fallback, `unloadMovie`'s failure to clear a list it
  owns, and the call-scoped-swap re-entrancy above. The third is the expensive
  one and it is a design problem, not a bug.
- §1.2 is also the argument *for* Route 2 being more than a cheap probe:
  ownership that lives **on the entry** is exactly what survives two movies'
  code being on the stack at once. A future per-movie list still wants this
  field; nothing here has to be unpicked.

**Deviation from the brief, deliberate: the field records the HOLDER, not
`g_current_movie_id`.** The brief proposed `u8 placed_by_movie`. The two
disagree for one shape — the same child file loaded into two different holders,
which is one `MovieEntry` and one movie id but two independent playheads, so a
movie-id-keyed clear would empty both. Per the arc's signature
defining-vs-placing trap: this is the **placing** movie either way, and the
question it answers is "what did *this load* put on screen", which is a
per-load question and `movie_id` is per-file. The holder costs a pointer
instead of a byte and is the identity that survives Route 1.

## 3. What shipped

Three changes, all runtime.

**`DisplayObject::placed_by_holder`** (`swf.h`) — the loaded-movie holder whose
frame tag created this entry, NULL for every ordinary main-movie placement.
Written at the two new-entry placement sites in `tag.c`
(`tagPlaceObject2`, `tagPlaceObject2Ratio`) from `actionCurrentChildMovieMC()`,
alongside `placed_at_tick`. The *Modify* path deliberately does not write it:
a parent Modifying a child's entry does not take it over, and a parent *placing*
over that depth goes through the new-entry path and correctly clears it to NULL.

**The wrap** (`actionAdvancePlayingLevels`) — the `current_frame >=
frame_count` arm no longer parks. It sets `current_frame = 0` and falls into
the normal frame call, which runs `frame_funcs[0]` and increments back to 1.
Ruffle's `determine_next_frame` answers `NextFrame::First` for any clip with
more than one loaded frame and an End tag, which every SWF file has.

**The clear** (`actionClearChildMoviePlacements`) — walks a display list
descending and `tagRemoveObject2`s every entry whose `placed_by_holder` is this
holder. Run under the movie's own context swap, so an `onUnload` sees the
movie's SWF version, globals and transform table. Top level only, deliberately:
a sprite the movie placed owns its own children and goes with it; a placement
the movie aimed at somebody else's clip is that clip's child by every other
rule in the runtime.

## 4. Defects this slice's own tests and audit found

### 4.1 The clear has to look in two lists, because the loader and the driver disagree

Pre-existing and invisible until now. For a **timeline-clip** holder (one that
already has a `DisplayObject` with a sprite list), the *driver* swaps to that
private list before calling a frame, but neither *loader* does — so that
movie's frame 1 places into the global list and its frames 2..N into the
private one. A wrap that cleared only the active list would leave frame 1's
children behind forever.

The clear therefore runs against the active list and, when the driver swapped,
against the global list too. For a `_levelN` target the second pass is a no-op
(nothing of the level's is in the parent's list); for a dynamic
`createEmptyMovieClip` holder there is no swap and the first pass is the global
list. Every shape is covered without depending on which of the two the loader
happened to use.

### 4.2 The driver's copy-out could resurrect an unregistered playhead

Same class as the predecessor's §3.2, one step further out. The loop copies
each entry into a local, calls a frame, and compacts the local back. The
predecessor fixed a `stop()` during the frame being overwritten by the
write-back. But `unloadMovie` during the frame calls
`actionUnregisterLevelAdvance`, which NULLs the live slot — and the write-back
then **resurrected the entry the movie had just unregistered**. Reachable
before this slice; looping makes last frames run often, and a movie whose last
frame unloads itself is an ordinary shape.

Fixed by re-reading the live slot after the frame call and dropping the entry
when it is gone, rather than writing the stale copy back. A *fresh load* into
the same holder during the frame is carried through as the live registration
instead, so the new playhead is not clobbered by the old one either.

## 5. Evidence

### `regression/avm1_child_timeline_loop` (new)

Two loaded movies with different cycle lengths (3 and 2) at disjoint depth
ranges, loaded into two holders in the same tick. They fall out of phase
immediately, so from t3 on every tick is one movie wrapping while the other is
mid-pass — which makes the other one's children a live negative control for
over-clearing on every single wrap.

Rows carry `f1/a/b/c/ax` for the 3-frame movie, `f2/p/q` for the 2-frame one,
and `rf` + the monotonic `t` for the parent-rewind guard. What each row
discriminates is in the generator's docstring.

### `regression/avm1_child_timeline_advance` (flipped, deliberately)

The predecessor wrote its `t9..t12` rows as an explicit **lock on
known-incomplete behaviour**: "when looping lands they must flip to
`cf:1 ax:10`, deliberately." They did, first try:

```
     t8 cf:5 tf:5 ax:30 b:undefined z:movieclip
-    t9  cf:5 ... z:movieclip          +    c1
-    t10 cf:5 ... z:movieclip          +    t9  cf:1 tf:5 ax:10 b:undefined z:undefined
-    t11 cf:5 ... z:movieclip          +    c2
-    t12 cf:5 ... z:movieclip          +    t10 cf:2 tf:5 ax:20 b:movieclip z:undefined
                                       +    c3 / t11 cf:3 ... / c4 / t12 cf:4 ...
```

`z:undefined` on the wrap tick is the clear; `ax:10` is frame 1's re-place;
`c4` at t12 is the movie's own `stop()` firing again on the second pass.

### `regression/avm1_child_timeline_holder_stop` (flipped, deliberately)

Same lock, same flip: `cf` 1..6 then 1,2 instead of pinning at 6.

### The rest of the multi-SWF fixtures

`avm1_child_timeline_frame1_stop`, `avm1_parent_child_modify_place`,
`avm1_parent_child_bitmap`, `avm1_parent_child_sprite_meta`,
`avm2_parent_child_symbol_stride` — all unchanged and passing. The three
1-frame-child fixtures have nothing to wrap;
`avm1_parent_child_modify_place`'s same-frame constraint is historical (the
predecessor's §6) and its README row already says so.

### Negative controls, all run

| control | fixture | result |
|---|---|---|
| whole slice reverted (`1f1cade12`) | `loop` | both movies park: `f1:3` and `f2:2` on every row from t3, `c`/`q` never leave |
| whole slice reverted | `advance` | `t8..t12` back to `cf:5 z:movieclip` (the predecessor's expected output verbatim) |
| whole slice reverted | `holder_stop` | `t9..t11` back to `cf:6 ax:60` |
| **clear ignores `placed_by_holder`** (walks the same list, removes everything) | `loop` | caught on the FIRST wrap, both directions: `t3 f1:3 a:undefined b:undefined c:undefined ax:undefined` (child2's wrap wiped child1) and `t4 ... p:undefined` (child1's wrap wiped child2) |

The last row is what makes the `p`/`q` columns load-bearing rather than
decorative, and it is the control the ownership field exists for.

## 6. Verification

1. **Four fixtures**, one new and two deliberately flipped, four measured
   states (§5).
2. **Local canary sweep**: 80 tests, one at a time (`-P 5`), every corpus test
   with a sibling SWF plus every test whose child SWF has more than one frame
   (18 of them, enumerated by parsing frame counts out of every non-`test.swf`
   in the corpus — `avm1/unloadmovie{,_method,num}`, `mcl_unloadclip`,
   `focusrect_property_swf{5,6,7}`, `swf5_xml_event_handler_context`,
   `avm2/loader_loadbytes_events`, gnash `attachImported` /
   `attachExtImported` / `Version4Loader`, `from_shumway/avm1/moviecliploader`,
   `mixed_avm/avm2_loads_avm1_doabc`, `timeline/{scene_count_oom,
   frame_label_count_oom,clip_action_no_key_code}`,
   `swf/swf_length_too_short_no_second_frame`).

   ```
   80 canary tests : 10 failures, ALL of them in the predecessor's standing
                     non-pass list. New failures: 0.
   ```

   Every multi-frame-child test passes, including
   `from_shumway/avm1/moviecliploader` — the one the predecessor flagged as
   surviving only because of the load-tick double step.
3. **`gcc -fsyntax-only -std=gnu17 -Wall -Werror=return-type -DNO_GRAPHICS`**
   over `action.c` and `tag.c` with the full include set: no errors and no new
   warnings on any changed line. (`verify_output.py` compiles with `-w`.) The
   recompiler is untouched, so no generated C changed.
4. **CI, both modes**: §8.

## 7. The brief's §1 is wrong, and this matters for what comes next

The brief opens by saying looping and the renderer "are the same missing
abstraction: a movie does not own the things it put on screen", and that both
remaining large items are blocked on it. **They are not the same abstraction,
and the render item was not blocked on this one.**

- **Looping needed per-entry ownership IDENTITY** — "which load put this entry
  here" — because a clip target's children are interleaved with the parent's in
  one list. One field on `DisplayObject`, and §1.2 says a swapped global
  pointer could not have answered it anyway.
- **The renderer needs per-movie INDEX BASES on `MovieEntry`** — shape, colour,
  gradient, uninv and the bitmap range — plus per-movie bases applied at draw
  time and a growable static slot table with a re-entrant finalize. The
  BACKLOG entry spells this out. None of it is a display-list question:
  `renderer_draw_shape(ctx, ch->shape_offset, ..., obj->transform_id,
  obj->cxform_id)` passes movie-LOCAL indices into a vertex buffer uploaded
  once from the ROOT's `shape_data`, and that is just as broken for a `_levelN`
  child that already HAS a private display list as for a clip target that does
  not.

They share the phrase "per-movie", and they were both reached from "a loaded
child is second-class". They do not share a mechanism, and **this slice does
not unblock the render item** — that item was already unblocked by the
predecessor (which was the timeline gate) and is exactly as far along now as it
was this morning.

The honest common cause is narrower and less useful as a plan: *nothing in the
runtime is keyed by movie except where somebody has gone and keyed it.* Four
slices have now each added one such key — `place_transform_data` (slice 3),
the embedded-asset table fall-throughs (slice 4), the advance-table entry
(slice 5), `placed_by_holder` (this one). That is a pattern worth naming, but
it predicts a sequence of small per-site fixes, not one big abstraction that
unlocks several items at once.

## 8. CI


## 9. What is left of the arc

- **Per-movie render tables — a loaded child movie does not render at all.**
  Unchanged, and **not** unblocked by this slice (§7). It is per-movie index
  bases on `MovieEntry` plus a growable, re-entrant static slot table, and it
  has no display-list component.
- **Per-movie display-list ownership (Route 1) is a sub-arc, and here is its
  shape.** Three measured work items, in dependency order:
  1. Widen `actionIsLoadedLevelRootMC` to "loaded movie root" so a holder can
     carry a `display_obj` at all (§1 — two lines, six of the eight tests).
  2. Make the two loaders swap for clip targets the way the driver already
     does, and fix what falls out: `getBounds`'s loaded-child fallback becomes
     dead code, `unloadMovie` must clear a list it now owns, and this slice's
     §4.1 two-list clear collapses back to one list.
  3. **The hard one: the swap is call-scoped, not movie-scoped** (§1.2). A
     child that calls back into its parent mid-frame makes the parent resolve
     names against the child's list. A global `display_list` pointer cannot
     express ownership while two movies' code is on the stack; either name
     resolution has to take the list from the clip it is resolving against, or
     the swap has to be pushed down to the placement/lookup sites.
  Only (3) actually needs the depth-collision bug fixed with it, and (3) is
  what makes a second load into the same holder cheap.
- **`holder.gotoAndStop(n)` does not target the loaded movie's frames.**
  Unchanged. The advance-table entry is where a `goto` would land — it already
  owns the cursor, and now the wrap proves the cursor can be moved backwards.
- **A second load into the same holder does not clear the first movie's
  children.** Unchanged, and now cheap to fix: `actionRegisterChildMovieAdvance`
  replacing an entry is the exact moment, and `actionClearChildMoviePlacements`
  is the exact call. Deliberately NOT taken here — it is a behaviour change on
  the `mcl_replace_root_*` / `load_cancel_*` cluster with no fixture demanding
  it, and this slice's corpus budget belongs to looping.
- **Our MCL load completes a tick later than Flash's.** Unchanged.
- **Browser-WASM never advances a loaded movie**, so it never loops either
  (`swf.c`'s driver call is inside `#ifdef OFFSCREEN_RENDER`). Unchanged.
- **Four copies of the per-movie context swap.** Unchanged, and this slice
  touched two of them again — the count of reasons to consolidate is now five.
- **`flashbang_upload_bitmap`'s fix is unverified.** Unchanged.
- **The constant-vs-`dictionary_capacity` divergence.** Unchanged.
