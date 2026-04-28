# Sprite Execution Order: LIFO Instantiation Plan

<!-- TESTS: action_order/action_execution_order_test2, action_order/action_execution_order_test5, action_order/action_execution_order_test11 -->

<!-- PLAN_META
id: SPRITE_EXEC_LIST_LIFO
status: pending
phases:
  - id: 1
    name: "Add per-placement sequence counter"
    status: pending
  - id: 2
    name: "Sort advance_sprite_frames iteration by reverse-placement-order"
    status: pending
  - id: 3
    name: "Apply same ordering to advance_nested_sprite_frames"
    status: pending
  - id: 4
    name: "Audit child_mc_cache + actionDispatchEnterFrameHandlers ordering"
    status: pending
  - id: 5
    name: "Regression battery"
    status: pending
dependencies: []
parent_plan: "complete/DEFERRED_CLIP_UNLOAD_PLAN.md (§2)"
-->

## Problem statement

Sprite frame functions are dispatched in **depth-descending** order during
`advance_sprite_frames` (`SWFModernRuntime/src/libswf/tag.c:671-953`):

```c
for (size_t i = max_depth + 1; i > 0; --i)
{
    DisplayObject* obj = &display_list[i - 1];
    ...
}
```

Flash and Ruffle dispatch sprite frame functions in **reverse-instantiation
order** (most-recently-placed first) — implemented in Ruffle as a
LIFO-prepended linked list (`clip_exec_list`) traversed forward at frame
boundaries. The two orders coincide whenever placement order matches depth
order, which is why most of our regression suite passes; they diverge as
soon as a SWF places sprites in non-monotonic depth order or swaps depths
without re-placing.

Reference: `core/src/avm1/runtime.rs:519-525` (push at head):
```rust
pub fn add_to_exec_list(&mut self, ..., clip: MovieClip<'gc>) {
    if clip.next_avm1_clip().is_none() {
        clip.set_next_avm1_clip(gc_context, self.clip_exec_list);
        self.clip_exec_list = Some(clip);
    }
}
```
and `core/src/avm1/runtime.rs:489-505` (forward traversal in `Avm1::run_frame`).

## Affected tests (CI 91a39c2c)

| Test | Suite | Match | Lines | Diff snippet |
|------|-------|-------|-------|---|
| action_order/action_execution_order_test2 | misc-ming | 2/5 | expected `depth11+depth12+depth10+depth9+depth13+`, got `depth12+depth11+depth10+depth9+depth13+` |
| action_order/action_execution_order_test5 | misc-ming | 26/35 | expected `'1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+'`, got `'1+2+3+4+5+6+7+8+9+10+4+5+2+3+4+5+11+12+13+14+15+'` (parent-child interleave wrong) |
| action_order/action_execution_order_test11 | misc-ming | 13/32 | expected `enterFrameOrder = '0+2+1+3+2+1+4+3+2+1+5+4+3+2+1+'`, got `'0+1+2+3+1+2+3+1+4+2+3+5+1+4+2+'` |

### Why these three and not the rest

The three tests deliberately place sprites in non-monotonic depth order:
- test2: places mc_red1@10, mc_red2@12, mc_red3@11 — third placement at
  depth 11 sits **between** the prior two depths.
- test5/test11: nest sprites and capture an `enterFrameOrder` / x2 trace
  that records exact dispatch sequence; depth-descending vs. reverse-placement
  diverge once the parent frame re-orders children.

The other 4 originally-DEFERRED_CLIP_UNLOAD_PLAN target tests (loop_test6,
ActionOrderTest3/4/5) place sprites in depth-ascending order, so the
depth-descending iteration coincidentally matches reverse-placement and
their failures are caused by §1/§3 — not this plan.

## Existing infrastructure

`DisplayObject` already carries:
- `placed_at_frame` (size_t, frame index when placed) — too coarse, all
  same-frame placements share it.
- `place_gen` (size_t, frame-level monotonic counter) — bumped once per
  frame in `tagShowFrame`, also too coarse.

We need a **per-placement** counter that increments at every PlaceObject2/
PlaceObject2Ratio/PlaceObject2WithClipActions/PlaceObject3 call. Reusing
`place_gen` would break its existing same-frame-detection role
(`tag.c:4112,4131`); add a separate `place_seq` field + `g_place_seq`
counter.

## Plan

### Phase 1 — Add per-placement sequence counter

**`SWFModernRuntime/include/libswf/swf.h`** — add to `DisplayObject`:
```c
size_t place_seq;  // monotonic per-placement counter (NOT per-frame).
                   // Reverse order = most-recently-placed first =
                   // reverse-instantiation iteration order.
```

**`SWFModernRuntime/src/libswf/tag.c`** — add a global counter alongside
`g_place_gen`:
```c
size_t g_place_seq = 0;
```

Set `display_list[depth].place_seq = ++g_place_seq;` at every full-placement
site (NOT at modify-only sites — those preserve identity, including order):
- `tagPlaceObject2` placement branch (`tag.c:4207`)
- `tagPlaceObject2Ratio` placement branch (`tag.c:4441`)
- `tagPlaceObject2WithClipActions` placement branch (`tag.c:4610`)
- `tagPlaceObject3` placement branch (find via grep)
- `actionDuplicateMovieClip` (cloned MCs get a new place_seq, since they
  are new instantiations — Ruffle's `add_to_exec_list` is called from
  `MovieClip::instantiate` which fires for clones)
- `actionAttachMovie` placement (same reasoning)
- attachMovie-replacement path that buffers RemoveObject2 (decided at
  Phase 4 audit time — does the replacement re-instantiate or rebind?)

### Phase 2 — Reverse-placement iteration in `advance_sprite_frames`

**`SWFModernRuntime/src/libswf/tag.c:671-953`** — replace the
depth-descending loop with a sort by `place_seq` descending.

Strategy A (low-risk, copy-and-sort):
```c
// Collect eligible depths with place_seq, sort descending.
size_t eligible[MAX_DISPLAYLIST_DEPTH];
size_t eligible_seq[MAX_DISPLAYLIST_DEPTH];
size_t n_elig = 0;
for (size_t i = 1; i <= max_depth; i++) {
    if (display_list[i].char_id == 0) continue;
    eligible[n_elig] = i;
    eligible_seq[n_elig] = display_list[i].place_seq;
    n_elig++;
}
// Insertion sort by place_seq DESC (largest first = most-recently-placed first)
for (size_t k = 1; k < n_elig; k++) {
    size_t key = eligible[k]; size_t key_seq = eligible_seq[k];
    long b = (long)k - 1;
    while (b >= 0 && eligible_seq[b] < key_seq) {
        eligible[b+1] = eligible[b]; eligible_seq[b+1] = eligible_seq[b]; b--;
    }
    eligible[b+1] = key; eligible_seq[b+1] = key_seq;
}
for (size_t e = 0; e < n_elig; e++) {
    DisplayObject* obj = &display_list[eligible[e]];
    /* same body as before */
}
```

Insertion sort is fine — typical display lists are 1-30 entries. No
heap allocation needed, the eligible array is on the stack with a
`MAX_DISPLAYLIST_DEPTH` upper bound (already a constant elsewhere in the
file).

**Backward goto rewind paths** (`tag.c:740-788, 800-845`) — the
catch-up loops re-execute `display_list[j]` at depth indices 1..max_depth.
These already preserve `place_seq` via `display_list[j].char_id = 0` clear
+ subsequent re-place by tag stream, so no Phase 2 work needed here.

### Phase 3 — Apply ordering to `advance_nested_sprite_frames`

The deferred-recursion pass `advance_nested_sprite_frames`
(`tag.c:959-1015`) also iterates `max_depth..0` descending. Apply the same
sort.

### Phase 4 — Audit `child_mc_cache` + `actionDispatchEnterFrameHandlers`

`actionDispatchEnterFrameHandlers` (`action.c:27348`) already iterates
`child_mc_cache` in reverse insertion order:
```c
for (int i = child_mc_count - 1; i >= 0; i--) { ... }
```

This is **almost** LIFO — but `child_mc_cache` insertion order may not
strictly match placement order, since cache entries are added at first
*lookup* (`actionFindOrCreateMovieClip`), not at placement. A sprite
placed before another might be looked up later (e.g. via `_root.foo`
referenced from a script that runs after the second placement's
constructor).

Audit task: trace one of the failing tests through the cache. If
`child_mc_cache` order matches `place_seq` order, no work needed. If not,
either:
1. Pre-populate the cache at placement time (tagPlaceObject2 calls
   `actionFindOrCreateMovieClip` early → fixes order automatically), or
2. Sort by `mc->display_obj->place_seq` descending in the dispatcher.

For root-only / dynamic MCs without `display_obj` (createEmptyMovieClip),
`mc_enterframe_eligible` already gates them in. They don't have a depth
or place_seq; relative ordering between root-only MCs and display-list
MCs falls out of `child_mc_cache` insertion order — likely correct since
`createEmptyMovieClip` *also* triggers cache insertion at create time.

### Phase 5 — Regression battery

Run after each phase, not just at the end.

**Required-pass tests (must remain green):**

AVM1 lifecycle / event-order battery (28 tests, all pass today):
- `goto_rewind1/2/3`, `execution_order1/2/3`, `goto_execution_order/2`,
  `goto_both_ways1/2`, `rewind_depth`, `unload`, `unload_clip_event`,
  `unload_nested_child`, `unloadmovie`, `mcl_unloadclip`,
  `clip_events`, `bad_placeobject_clipaction`,
  `movieclip_in_removed_button`, `on_construct`,
  `register_and_init_order`, `set_interval`,
  `swf5_to_6_cross_call`, `swf6_to_5_cross_call`,
  `attach_movie`, `init_object_order`, `movieclip_state_values`,
  `movieclip_library_state_values`, `button_children`,
  `depth_replacement_audio_unloading`.

Gnash misc-ming recently-fixed (must not regress):
- `loop_test2/3/4/5/8/9`, `instanceNameTest`, `attachMovieTest`,
  `static_vs_dynamic1/2`, `displaylist_depths_test11`,
  `place_and_remove_object_test`, `get_frame_number_test`,
  `shape_test`, `event_handler_scope_test`,
  `action_execution_order_test8-v5/v6`, `new_child_in_unload_test`,
  `ResolveEventsTest`,
  **`reverse_execute_PlaceObject2_test1/2`** (highest risk: these
  explicitly test re-place ordering; if any regression hits, it lands
  here first).

Gnash misc-swfc (must not regress):
- `stackscope`, `edittext_test1`, `submoviegetvar`,
  `movieclip_destruction_test2` (50/52 — must not drop).

Shumway:
- `duplicateMovieClip/dontremove`,
  `duplicateMovieClip/duplicateMovieClip`,
  `duplicateMovieClip/samedepth`,
  `duplicateMovieClip/name-coercion`.

**Target tests (expected to flip):**
- `action_execution_order_test2` (2/5 → 5/5 PASS)
- `action_execution_order_test5` (26/35 → 35/35 PASS)
- `action_execution_order_test11` (13/32 → 32/32 PASS)

**Net expected delta:** +3 PASS in misc-ming.

## Open questions

1. **swapDepths and place_seq.** When `mc.swapDepths(otherMc)` runs, do
   both display objects keep their original `place_seq`, or does swapDepths
   bump both? Ruffle: swapDepths in
   `core/src/display_object/movie_clip.rs::swap_at_depth` does NOT touch
   the exec list — depth changes, instantiation order is preserved.
   So `place_seq` should NOT bump on swapDepths.

   This is the right semantics for AS3 too: `swapDepths` is a render-order
   change, not a re-instantiation. The `depth_swapped` flag we already set
   confirms we treat it the same way.

2. **duplicateMovieClip vs. modify-on-existing.** When a recompiler-emitted
   tag stream hits `[RemoveObject2(d), PlaceObject2(d, char=X, name=N)]`
   in two consecutive frames, the second placement's `char_id != 0`
   branch in `tagPlaceObject2` (full-placement, `tag.c:4207`) bumps
   `place_seq` — this is correct: a fresh instantiation, new
   exec-list entry.

   But the same depth re-Place via the
   `actionMarkMCPendingRemoval`-then-replace path during backward goto
   `survives_rewind` (`tag.c:3917-3947`) is a modify, not a re-place
   (preserves identity, instance_name, etc.) — so it must NOT bump
   `place_seq`. The Phase 1 site list explicitly excludes the modify
   branches; verify during implementation.

3. **Buttons.** Buttons have their own internal display list
   (`obj->sprite_display_list` when `ch->type == CHAR_TYPE_BUTTON` at
   `tag.c:684-703`). `advance_sprite_frames` recurses into the button's
   list — those button-children also need place_seq + sort. They get it
   for free if the recursive call uses the same Phase 2 sort logic
   (button children are placed via the same `tagPlaceObject2*` path
   when the button state is constructed).

4. **process_sprite_needs_init / Phase 1 eager init ordering.**
   `process_sprite_needs_init` at `tag.c:331` already sorts a separate
   eligible array by `placed_at_frame` for the goto-catchup case (the
   §3-frame execution ordering work). That sort key is independent —
   `placed_at_frame` is correct for "which frame did init queue this for"
   but `place_seq` is the right key for "in what order did they all
   place during a single tick." Don't conflate them.

## Risk

- **Medium.** The fundamental change is single-file (sort instead of
  walk-by-depth in `advance_sprite_frames` + `advance_nested_sprite_frames`).
  But the regression surface is the entire AVM1+gnash+shumway suite, and
  silent ordering regressions are the kind of thing the line-level
  diff captures but no compile-time check would.
- **Highest-risk regression:** `reverse_execute_PlaceObject2_test1/2` —
  these were added precisely to nail down correct re-place behavior.
  Run them first after Phase 2.
- **Lower-risk regression:** the `depth_swapped` family
  (`movieclip_destruction_test2` lines 175-183, swapDepths edge cases) —
  if Phase 1 accidentally bumps `place_seq` on swapDepths, the swap'd
  MC fires earlier than expected next tick.

## Why this is the right shape

This mirrors Ruffle's exact mechanism with minimal scope: a per-placement
counter + sort, vs. a true linked-list rewrite. The linked-list version
would be slightly faster in theory but the sort version:
- Touches fewer files (one tag.c function + the struct field).
- Doesn't require careful list-maintenance during destroy / reparent /
  swapDepths.
- Costs O(n log n) per frame on a typical n=10-30 display list (sub-microsecond).

If this plan lands cleanly and a future session wants to optimize, the
sort can be replaced with a true exec-list linked list without changing
the visible ordering — this plan establishes the *semantics* first.

## Estimated session budget

- Phase 1 (struct field + bump sites): 30-45 min.
- Phase 2 (sort in advance_sprite_frames): 30 min coding + 30 min
  spot-test against test2.
- Phase 3 (advance_nested_sprite_frames): 15 min (same change).
- Phase 4 (cache audit): 30-60 min — depends whether fixup is needed.
- Phase 5 (battery): 30 min per re-run, plan for 2-3 re-runs.

A single 3-4 hour session is realistic. If Phase 4 surfaces a deeper
`child_mc_cache` issue, split: land Phase 1-3 (fixes test2/5/11 IF
their dispatch goes through advance_sprite_frames only, not
actionDispatchEnterFrameHandlers) and put Phase 4 in a follow-up.

## Related plans

| Doc | Relationship |
|-----|--------------|
| `complete/DEFERRED_CLIP_UNLOAD_PLAN.md` | Parent plan that originally listed test2/5/11 — see §2 of its "Follow-up work" section. This plan covers that §2. |
| `incomplete/MISC_MING_SWFC_PLAN.md` | Umbrella plan; references DEFERRED_CLIP_UNLOAD_PLAN for the action_order family. Add a one-line note pointing here when this plan lands. |
| Ruffle source: `core/src/avm1/runtime.rs:489-525`, `core/src/display_object/movie_clip.rs::instantiate` | Reference implementation — clip_exec_list LIFO insertion + forward traversal. |
