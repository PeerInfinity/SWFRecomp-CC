# Inter-Tag UNLOAD Ordering Plan (sprite-internal Remove+Replace, sprite loop-back)

<!-- TESTS: action_order/ActionOrderTest3, action_order/ActionOrderTest4, action_order/ActionOrderTest5, loop/loop_test6 -->

<!-- PLAN_META
id: INTER_TAG_UNLOAD
status: pending
phases:
  - id: 1
    name: "Buffer sprite-level RemoveObject2 (recompiler symmetry)"
    status: dropped
  - id: 2
    name: "Fire UNLOAD on sprite loop-back display-list clear"
    status: pending
  - id: 3
    name: "Audit `this`/`this.c` access in deferred clip-action UNLOAD"
    status: dropped
  - id: 4
    name: "Queue dynamic onUnload for sprite-internal replacements"
    status: pending
  - id: 5
    name: "Regression battery"
    status: pending
dependencies:
  - "complete/DEFERRED_CLIP_UNLOAD_PLAN.md"
parent_plan: "complete/DEFERRED_CLIP_UNLOAD_PLAN.md (§3)"
-->

## Status (2026-04-29, post `run_pending_finalize` cross-context attempt)

- **Attempted: gate `run_pending_finalize`'s `clear_display_entry` call
  on slot-name == MC-name match. Reverted (no commit).**
  Diagnosis was correct but the resulting trade-off was the same family
  as Approach A — net regression on the matching-line metric.

  The actual reset site for mc3's `sprite_current_frame` (the user's
  open question this session) is **not** in `advance_sprite_frames` or
  the eager-init re-run paths the plan listed as candidates. Instead:

  1. Instrumented every `sprite_current_frame` write in `tag.c`, plus
     `tagPlaceObject2`'s entry state, plus `ng_display_clear_after` /
     `ng_display_cleanup_unplaced_after`. Output to `/tmp/mc_frame.log`.
  2. The log showed mc3 hits `tagPlaceObject2` line 4212 (FRESH
     placement path) on every gotoAndPlay(2) iteration with
     `existing_char=0 existing_dl=(nil) existing_name=(null)` — i.e.,
     mc3's slot was already wiped by the time the catch-up replay
     reached `tagPlaceObject2`. But `existing_paf=1 existing_pg=N`
     (placed_at_frame and place_gen survive). That field-preservation
     pattern uniquely matches `clear_display_entry` (in tag.c around
     line 4995) — it zeros char_id / instance_name / sprite_display_list
     but doesn't touch placed_at_frame / place_gen.
  3. Tracing `clear_display_entry` callers: it's invoked by
     `run_pending_finalize` (tag.c:4977) for every queued
     `PendingFinalizeEntry`. The queue is populated by sprite-internal
     `tagRemoveObject2` calls (tag.c:5320) with the **current
     display_list's `depth`** stored as a plain `size_t`.
  4. When `sprite_2_frame_1` (inside mc3) calls `tagRemoveObject2(1)`,
     `display_list` is mc3's `sprite_display_list`, and `depth=1`
     refers to mc3's "Segments" slot. `queue_pending_finalize_mc(_ro2_mc,
     1, 1)` queues that depth.
  5. Later, when `actionDrainOnloadAndScript` finishes draining unload
     entries, `run_pending_finalize` fires (`action_queue.c:286`).
     `display_list` is now ROOT. The queued `e->depth=1` is interpreted
     as **root depth 1** — which is mc3 itself. `clear_display_entry`
     wipes mc3's slot, frees mc3's `sprite_display_list` (containing
     mc1!), and orphans the children. That is why mc3 had to be
     freshly re-placed every iteration (and why eager-init's
     `(1 % count) = 1` write reset `sprite_current_frame` to 1 each
     time).

- **Attempted fix and outcome.** Gated the `clear_display_entry` in
  `run_pending_finalize` with a name-match check:
  ```c
  if (e->depth <= max_depth
      && e->mc != NULL
      && e->mc->name[0] != '\0'
      && display_list[e->depth].instance_name != NULL
      && strcmp(display_list[e->depth].instance_name, e->mc->name) == 0)
  {
      clear_display_entry(app_context, e->depth);
  }
  ```
  Result (matching-line metric, local baseline; CI numbers may differ
  but trend is the same):
  - Test3: 7 → 8 (+1)
  - Test4: 7 → 8 (+1)
  - Test5: 8 → 9 (+1)
  - loop_test6: 5 → 5 (0)
  - **RegisterClassTest4: 22 → 9 (-13)**
  - All AVM1 lifecycle (`unload`, `unload_clip_event`,
    `unload_nested_child`, `clip_events`, `goto_rewind*`,
    `goto_frame*`, `set_interval`, `bad_placeobject_clipaction`,
    `button_order`, `issue_1104`, `movieclip_in_removed_button`,
    `on_construct`, `register_and_init_order`) — all 100% PASS.
  - misc-ming `loop_test2/4/5/8`,
    `reverse_execute_PlaceObject2_test1/2` — all 100% PASS.

  Net: -10 matching lines. Same trade family as Approach A (which was
  -14 with 0 gain). Reverted under the user's standing instruction.

- **Why the fix regresses RegisterClassTest4 internally.** Functionally
  the test's own dejagnu count went **up** with the fix (11 → 15
  PASSED of 16 internal checks). The verify_output `matching_lines`
  metric is harsh on early misalignment: a single missing trace line
  early in the output (here, a missing `dynamic load: 0`) shifts every
  subsequent matched line into the "differs" bucket. So while the
  diagnosis is right, the fix exposes a downstream gap (suppressing
  the wrong-context clear leaves mc3's old "Segments" mc1 in place,
  which then collides with the next iteration's `sprite_2_frame_0`
  attempting to place mc2 at the same depth — `Warning: Failed to
  place object at depth 1.` warnings appear in test wind-down). The
  ordering-cascade of missing/extra trace lines (`dynamic load`,
  `static unload: 0` vs. `static unload: undefined`,
  `dynamic unload: N` vs. `N-1`) means the per-line diff dives even
  while the dejagnu pass count rises.

- **Path forward (next attempt).** The cross-context `run_pending_finalize`
  bug is real and the fix direction is right, but it needs to be paired
  with the original Phase 2 (silent-clear UNLOAD queueing): once mc3
  is preserved across iterations, mc3's natural advance now reaches
  `sprite_current_frame == 0` and the silent-clear branch fires for
  real. Approach A's UNLOAD queueing must land at that newly-active
  silent-clear site, **and** the dejagnu-pass-vs-matching-lines tension
  on RegisterClassTest4 needs to be resolved (likely by also making
  the `Bug ctor: N` / `dynamic load: N` / `static unload: N-1`
  ordering match Flash's drain order at the silent-clear site, not
  just queueing UNLOADs). Likely needs a careful look at Ruffle's
  `MovieClip::run_goto` rewind path for the same test pattern to
  understand the expected drain ordering.

- **Architectural fix worth considering separately:**
  `queue_pending_finalize_mc` should remember the display_list pointer
  (or a parent-MC handle) at queue time, not just a bare `depth`.
  Then `run_pending_finalize` can either swap to that context before
  clearing, or skip the clear if the original context is gone. The
  name-match heuristic worked for the bad case but was too coarse —
  it suppresses clears that ought to happen in same-context cases too.

## Status (2026-04-28, post-Approach A attempt)

- **Phase 2 Approach A — TRIED AND REVERTED (commit 4d97fa92).**
  Implemented exactly as the plan sketched: queue clip-action UNLOAD,
  recursive child UNLOAD, AS-level onUnload (deferred-finalize) for
  every non-empty depth at sprite-internal `frame == 0 && max_depth > 0`
  loop-back. CI showed:
  - **`register_class/RegisterClassTest4` regressed -14 lines** (17/42 →
    3/42). The test fires `unload _level0.mc.Segments c: N` events, but
    Approach A queues them at the wrong lifecycle point relative to the
    `Bug ctor: N` line and inserts spurious `2 undefined` / `1 undefined`
    rows — same family of ordering miss as ActionOrderTest5.
  - **Plan-target tests (Test3/4/5, loop_test6) all unchanged** in CI
    matched-line counts. The silent-clear path is genuinely not where
    mc3 loops back in those tests — debug logging during the attempt
    confirmed mc3's `sprite_current_frame` is always `1` at the silent
    clear, never `0`. Root `gotoAndPlay(2)` routes through
    `ng_executeGotoCatchUp`, whose backward path takes the
    `survives_rewind` branch in `tagPlaceObject2` and preserves mc3 with
    the existing frame counter — so the natural-advance loop-back never
    fires for mc3.
  - **Loop_test2/3/4/5/8, reverse_execute_PlaceObject2_*, all the avm1
    UNLOAD/clip_events/goto/register_and_init_order tests** stayed
    100% PASS (no regression on the named "must-not-regress" set).
  - Net: -14 lines, 0 gain → reverted.

  Lesson: the plan's premise ("silent clear at advance_sprite_frames is
  where mc3 loops back") is wrong for this test family. mc3's
  per-iteration "loop-back" is actually buried inside the root-goto
  catch-up machinery, not the natural sprite advance.

- **Phase 1 — DROPPED.** Was a misdiagnosis. Without buffering the
  deferred-drain sequence already produces `ctor:NEW → UNLOAD:OLD →
  LOAD:NEW`, which is what ActionOrderTest3 expects. The buffering would
  invoke `tagReplaceObject2RatioWithClipActions`, whose semantics defer
  OLD's UNLOAD to fire when NEW is later removed (not this frame) — fits
  `avm1/unload`'s test pattern but breaks ActionOrderTest3's. Don't
  collapse Remove+Place at sprite level. See "Diagnostic notes" below.

- **Phase 3 — DROPPED as a standalone phase.** The plan's suggested
  `g_event_this_mc = pca->mc` in `aq_dispatch_clip_action` is a no-op:
  `actionGetVariable("this")` resolves via `g_this_stack` → `g_base_clip`
  → `g_current_context`, never `g_event_this_mc`, and the dispatcher
  already sets `g_current_context = pca->mc`. The actual `this.c ==
  undefined` symptom is downstream of Phase 2 and goes away if Phase 2
  fires UNLOAD with deferred-finalize timing.

- **Phase 2 + Phase 4 — STILL PENDING and merge into a single fix.**
  Approach A was tried this session and reverted (see top status block).
  Next attempt needs to find where mc3 actually transitions back to
  `sprite_current_frame == 0` between iterations — which is NOT
  `advance_sprite_frames`'s loop-back branch. Likely candidates: somewhere
  inside `ng_executeGotoCatchUp`'s backward replay (between the catch-up
  loop and the inline target-script call), or the eager-init re-run
  during catch-up's tagPlaceObject2 survives path. Instrument
  `sprite_current_frame` mutations on the `mc` instance during a single
  ActionOrderTest3 run to pinpoint.

  ActionOrderTest3 still 6/62 lines (no progress this session — including
  Approach A which left it unchanged).

## Affected tests (CI 6ea78421)

| Test | Suite | Match | Notes |
|------|-------|-------|-------|
| action_order/ActionOrderTest3 | misc-ming | 6/62 | All 4 root causes hit |
| action_order/ActionOrderTest4 | misc-ming | 7/64 | Same family |
| action_order/ActionOrderTest5 | misc-ming | 8/51 | Same family |
| loop/loop_test6 | misc-ming | 12/23 | Tail (lines 12-23) needs this plan |

## Test pattern (ActionOrderTest3)

`mc3` is a 2-frame sprite on the main timeline:
- `mc3.frame_0`: PlaceObject(d=1, char=mc2, name="Segments", clip-action UNLOAD = `_global.ch('static unload: ' + this.c);`)
- `mc3.frame_1`: RemoveObject(d=1) → PlaceObject(d=1, char=mc1, name="Segments", same clip-action UNLOAD)

`mc1` is exported as `Segments_Name` and registered with class `Bug`,
whose constructor sets `this.c = _global.c++`, `this.onUnload = function() { _global.ch('dynamic unload: ' + this.c); }`,
and `this.onLoad = function() { _global.ch('dynamic load: ' + this.c); }`.
`mc2` has no class registration.

The main timeline does `gotoAndPlay(2)` 5 times, so `mc3` plays through
frames 0,1,0,1,0,1,…. Each loop-back at `mc3.frame_0` should remove the
mc1 placed by the previous iteration's `mc3.frame_1`. The expected trace
for that loop-back boundary is:

```
ctor:N             ← Bug ctor for the new mc1 (immediate, fires at Place)
static unload:N-1  ← OLD mc1's clip-action UNLOAD (this.c=N-1 from prev iter)
dynamic unload:N-1 ← OLD mc1's AS-level onUnload (this.c=N-1)
dynamic load:N     ← NEW mc1's onLoad
```

The `ctor:N` line interleaves between the loop-back UNLOADs and the new
LOAD because Bug's ctor fires synchronously at `mc3.frame_1`'s Place,
while UNLOAD/LOAD are queued and drain at the end of the main frame.

## Root cause: silent loop-back clear

`advance_sprite_frames` in `SWFModernRuntime/src/libswf/tag.c:872-885`:

```c
// When looping back to frame 0, reset the display list (Flash behavior)
if (frame == 0 && max_depth > 0)
{
    for (size_t j = 1; j <= max_depth; ++j)
    {
        if (display_list[j].sprite_display_list != NULL)
        {
            FREE(display_list[j].sprite_display_list);
            display_list[j].sprite_display_list = NULL;
        }
        display_list[j].char_id = 0;
    }
    max_depth = 0;
}
```

Silently zeros `char_id` and frees nested display lists with no UNLOAD
firing. Mismatches Ruffle's `MovieClip::run_goto` rewind path
(`core/src/display_object/movie_clip.rs:1546-1696`), which:
1. Replays tags from frame 0 to the target frame, building a final
   `final_placements: HashMap<Depth, &GotoPlaceObject>`.
2. Iterates current children, filters by `survives_rewind(child,
   final_placements, frame)`.
3. For non-survivors, calls `remove_child` — full UNLOAD lifecycle.

`survives_rewind` (line 1812) returns true only if the final placement
at this depth has the same `char_id` (and matching ratio/clip_depth/
color_transform). Different char or absence at the depth → the child
is removed with proper UNLOAD events.

Result: in ActionOrderTest3, mc1 (placed by `mc3.frame_1`) is replaced
by mc2 (placed by `mc3.frame_0`) on loop-back — different char_id,
`survives_rewind` returns false, mc1 is removed with UNLOAD. We don't
do this; mc1 silently disappears.

## Diagnostic notes (this session)

Spent the session attempting Phases 1 + 3 from the original plan. Both
were misdiagnoses; neither addresses the loop-back gap.

**Phase 1 attempt (sprite RemoveObject2 buffering, recompiler).**
Implemented per-sprite `sprite_depth_clip_actions` /
`sprite_buffered_removes` trackers in `SWFRecomp/src/swf.cpp`, plus a
file-scope `ClipAction[]` pool emission (since function-local statics
can't be referenced across sprite frames). Recompiler emitted
`tagReplaceObject2RatioWithClipActions` correctly. But that runtime
function defers OLD's UNLOAD via `accumulated_clip_actions` — which fires
when NEW is later removed, not this frame. Result: ActionOrderTest3 went
from 6/62 → 4/62. Reverted.

The original plan's claim that `tagRemoveObject2` fires UNLOAD "at
tag-stream position" is incorrect — `actionQueueClipActionUnload` queues
the callback for end-of-frame drain, just like the buffered Replace
would. The two differ only in *which* UNLOAD events fire on a Remove vs
a Replace:
- `tagRemoveObject2` queues OLD's clip-action UNLOAD now, AS-level
  onUnload now (deferred-finalize), invalidates cached MC immediately
  (no-AS-onUnload path) or defers it (AS-onUnload path).
- `tagReplaceObject2RatioWithClipActions` accumulates OLD's clip_actions
  onto the new entry, doesn't queue UNLOAD or invalidate the cached MC,
  marks pending_removal only.

`avm1/unload` (currently 38/38 PASS) is the only test using Replace
today and depends on its specific deferred semantics. **Don't change the
Replace runtime function** unless willing to rewrite `unload`.

**Phase 3 attempt (`g_event_this_mc = pca->mc` in
`aq_dispatch_clip_action`).** No effect. Inserted a debug printf instead;
each iteration's `pca->mc` had a different pointer with `props=(nil)`:

```
mc=0x...A name=Segments parent=0x...mc3 props=(nil)
mc=0x...B name=Segments parent=0x...mc3 props=(nil)
```

`pca->mc` is set at queue time in `tag.c:5172` via
`actionFindOrCreateMovieClip(name, &root_movieclip)`. Since "Segments"
is parented to mc3, that lookup creates a fresh empty MC. Tried
switching to `g_current_context` as the parent hint — still got fresh
MCs each iteration, because the `static unload` events we currently see
are all from `tagRemoveObject2` firing for **mc2** (which has no
`Bug.c`, so `this.c == undefined` is *correct* for those events). The
mc1 UNLOAD events with `this.c = N-1` never fire at all because of the
silent loop-back clear.

The current baseline output:
```
ctor:0, static unload:undefined, dynamic load:0,        ← iter 0: mc2 UNLOAD (correct)
ctor:1, static unload:undefined, dynamic load:1,        ← iter 1: mc2 UNLOAD again (correct relative to mc2)
                              ↑ MISSING: mc1 UNLOAD lines from loop-back
```

Expected output:
```
ctor:0, static unload:undefined, dynamic load:0,                          ← iter 0
ctor:1, static unload:0, dynamic unload:0, dynamic load:1,                ← iter 1: mc1 OLD UNLOAD + mc2 UNLOAD merged
                  ↑ mc2 UNLOAD with this.c=0 (cached MC from iter 0's mc1)
```

Subtle: Flash sees `static unload: 0` not `static unload: undefined` in
iter 1+ because the cached "Segments" MC under mc3 carries over from
iter 0's mc1 (which set `this.c = 0` in its Bug ctor). When iter 1
frame_0 places mc2 at the same name+depth, `findOrCreateMovieClip`
returns the existing MC. mc2 has no ctor to overwrite `c`. So at
mc3.frame_1's Remove(mc2), the cached MC still has `c = 0`. mc2's
UNLOAD reads it correctly. The "two iter 1+ UNLOADs collapse into one
(`static unload: 0`)" is the loop-back UNLOAD plus the mc2 UNLOAD
landing on the same cached state.

So the missing piece is just: **fire UNLOAD on sprite loop-back**.
When that happens via the deferred-finalize path, the cached MC stays
alive long enough for the UNLOAD handler to read its `this.c`.

## Path forward

### Phase 2 (now: the sole remaining work)

Replace the silent clear at `tag.c:872-885` with a proper rewind path
that fires UNLOAD lifecycle events. Two approaches:

**Approach A (simple, may regress):** Unconditionally queue UNLOAD
events for any non-empty depth before clearing. Mirror the queueing
logic in `tagRemoveObject2` (`tag.c:5172-5267`):

```c
if (frame == 0 && max_depth > 0)
{
    extern MovieClip* g_current_context;
    MovieClip* sprite_mc = g_current_context;  // sprite executing this frame
    for (size_t j = 1; j <= max_depth; ++j)
    {
        DisplayObject* entry = &display_list[j];
        if (entry->char_id == 0) continue;
        if (entry->instance_name == NULL) {
            // No name → no AS-level handler, no cached MC. Just clear.
            if (entry->sprite_display_list != NULL) {
                FREE(entry->sprite_display_list);
                entry->sprite_display_list = NULL;
            }
            entry->char_id = 0;
            continue;
        }

        // Look up the cached MC for this child (parent = sprite_mc).
        MovieClip* child_mc = actionFindOrCreateMovieClip(
            app_context, entry->instance_name, sprite_mc);

        // Queue accumulated + current clip-action UNLOAD.
        for (size_t a = 0; a < entry->accumulated_clip_action_count; a++) {
            if (entry->accumulated_clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
                actionQueueClipActionUnload(entry->accumulated_clip_actions[a].action, child_mc);
        }
        for (size_t a = 0; a < entry->clip_action_count; a++) {
            if (entry->clip_actions[a].event_flags & CLIP_EVENT_UNLOAD)
                actionQueueClipActionUnload(entry->clip_actions[a].action, child_mc);
        }

        // Recursive child unloads (nested sprites).
        if (entry->sprite_display_list != NULL && entry->sprite_max_depth > 0) {
            extern void fire_recursive_child_unloads(SWFAppContext*,
                DisplayObject*, size_t, MovieClip*);
            fire_recursive_child_unloads(app_context,
                entry->sprite_display_list, entry->sprite_max_depth, child_mc);
        }

        // AS-level onUnload via the deferred-finalize path so the cached
        // MC's dynamic_props stays alive until drain.
        extern int ng_compute_has_unload(size_t depth);
        int has_unload = ng_compute_has_unload(j);
        if (has_unload) {
            actionFireOnUnload(app_context, entry->instance_name, (int)j);
            extern void queue_pending_finalize_mc(MovieClip*, int, size_t);
            queue_pending_finalize_mc(child_mc, (int)j, j);
        } else {
            extern void actionInvalidateCachedMovieClip(SWFAppContext*, const char*, int);
            actionInvalidateCachedMovieClip(app_context, entry->instance_name, (int)j);
        }

        if (entry->sprite_display_list != NULL) {
            FREE(entry->sprite_display_list);
            entry->sprite_display_list = NULL;
        }
        entry->char_id = 0;
    }
    max_depth = 0;
}
```

This unconditionally fires UNLOAD for every loop-back removal —
including cases where Ruffle's `survives_rewind` would have kept the
child. That's the regression risk: tests where mc3.frame_0 re-places the
same char at the same depth as frame_1 (Ruffle would survive; we'd fire
UNLOAD).

**Approach B (Ruffle-faithful, needs more recompiler/runtime
plumbing):** Compile-time, the recompiler emits a per-sprite
`final_placements_for_frame_0` table:
`{ depth, char_id, ratio, clip_depth, has_clip_actions }[]`. Runtime
iterates this table to compute per-depth `survives_rewind` before
clearing.

Approach A is simpler and matches what Ruffle does *for ActionOrderTest3
specifically* (different char_ids, no survival). Validate on the
sprite-loop tests below before deciding whether B is required.

### Phase 4 (subsumed)

Phase 4 ("queue dynamic onUnload for sprite-internal replacements") is
the AS-level onUnload portion of Approach A above (`actionFireOnUnload`
call in the Phase 2 loop). It's no longer a separate phase — landing
Phase 2 with the deferred-finalize queue handles both the clip-action
UNLOAD and the AS-level onUnload uniformly.

### Phase 5 (regression battery)

After Phase 2 lands, validate against this set in addition to the AVM1
lifecycle battery and gnash misc-ming recently-fixed battery from the
original plan:

- **Sprite loop-back tests where survives_rewind=true is critical:**
  `loop/loop_test2` (15/15 PASS today, 1-frame sprites looping with same
  char_id), `loop/loop_test3/4/5` (similar — ALL must remain green).
  These are where Approach A could regress.
- **Sprite Remove+Place inside frame:** `loop_test8` (38/38 PASS today),
  `reverse_execute_PlaceObject2_test1/2`. Different code path from
  loop-back (these go through tagRemoveObject2, not advance_sprite_frames),
  but worth checking that nothing leaks.
- **`avm1/unload`** (38/38 PASS today). Not exercised by Phase 2 (no
  sprite loop-back), but the only test using
  `tagReplaceObject2RatioWithClipActions` so any accidental change to
  drain ordering shows up here first.

## Estimated effort

Approach A: 2-3 hours including the regression battery. The runtime
infrastructure (`actionQueueClipActionUnload`, `actionFireOnUnload`,
`queue_pending_finalize_mc`, `actionInvalidateCachedMovieClip`,
`ng_compute_has_unload`, `fire_recursive_child_unloads`) is all in
place — Phase 2 is mostly re-using it at a new call site.

Approach B: 6-8 hours including recompiler-side `final_placements`
table, plus runtime iterator and `survives_rewind` checks against
ratio/clip_depth/transform.

If Approach A's regression battery comes out clean, it's the right
landing. If it regresses any `loop_test*` that depends on same-char
survival, fall back to Approach B.

## Open questions

1. **Sprite advance ordering.** `SPRITE_EXEC_LIST_LIFO_PLAN` is still
   pending. Does Phase 2's UNLOAD queueing interact with sprite advance
   ordering? The UNLOAD queue is the global ActionQueue (FIFO within
   priority), so the order in which sprites get their loop-back UNLOAD
   queued is the order in which their parent frame advances them.

2. **Implicit replace at frame_0 (no explicit Remove).** The
   `mc3.frame_0: place(d=1, mc2)` call hits an existing entry from
   iter (N-1)'s frame_1. With Phase 2 firing UNLOAD on loop-back, the
   display_list is empty by the time frame_0's tag stream runs, so the
   Place becomes a fresh placement. No implicit-replace path is hit. ✓

3. **Cached MC reuse across iterations.** `findOrCreateMovieClip`
   returns the same MC for the same name+parent. Phase 2's
   deferred-finalize keeps it alive through drain; after drain,
   `actionFinalizePendingRemovals` invalidates it (`depth = INT_MIN,
   dynamic_props = NULL`). The next iter's Place creates a fresh MC
   (since the dead one is filtered by `depth != INT_MIN`). New mc2's
   placement gets a fresh MC. New mc1's placement reuses the fresh
   mc2-MC (same name, same parent, alive). Bug ctor sets `c = N`. ✓

4. **`Frame N actions: VAL` traces.** Even with Phase 2 fixed, the
   `Frame N actions: VAL` line ordering depends on when the main
   timeline DoAction runs vs when mc3 advances. Out of scope for this
   plan unless it turns out the trace lines are also blocked on
   loop-back UNLOAD timing.

## Related plans

| Doc | Relationship |
|-----|--------------|
| `complete/DEFERRED_CLIP_UNLOAD_PLAN.md` | Parent plan; §3 of its "Follow-up work" section. This plan covers that §3. |
| `incomplete/CLIP_EVENT_ROUND_DISPATCH_PLAN.md` | Sibling — same parent. Independent. |
| `incomplete/SPRITE_EXEC_LIST_LIFO_PLAN.md` | Sibling — Phase 2's UNLOAD ordering interacts with sprite advance ordering — see Open Question 1. |
| Ruffle source: `core/src/display_object/movie_clip.rs::run_goto` (1546-1696, with `survives_rewind` at 1812). | Reference implementation. |
