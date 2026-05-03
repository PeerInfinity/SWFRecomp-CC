# Clone Clip-Event Dispatch Plan

<!-- TESTS: displaylist_depths/displaylist_depths_test2, displaylist_depths/displaylist_depths_test3, displaylist_depths/displaylist_depths_test9, duplicate_movie_clip_test -->

<!-- PLAN_META
id: CLONE_CLIP_EVENT_DISPATCH
status: incomplete
phases:
  - id: 1
    name: "Audit: trace existing clone paths vs Ruffle's instantiate_by_id + replace_at_depth + post_instantiation pipeline"
    status: completed
  - id: 2
    name: "Inherit clip_actions on clone slot (share static pointer with source)"
    status: completed
  - id: 3
    name: "Drive cloned slot through the standard sprite_needs_init lifecycle so sprite_initialized reaches >= 2 next tick"
    status: completed
  - id: 4
    name: "Queue CLIP_INIT / CLIP_CONSTRUCT / CLIP_LOAD on the clone via the existing queue_clip_*_events helpers (instead of bespoke ng_queue_pending_load)"
    status: completed
  - id: 5
    name: "Clear the clone's slot clip_actions on removeMovieClip / RemoveObject2 so dispatch_enterframe doesn't re-fire forever"
    status: completed
  - id: 6
    name: "Backward goto: re-fire CONSTRUCT for static MCs re-placed during catch-up rewind (displaylist_depths_test2/3/9)"
    status: partial — clone-replaced slots fixed (test9 now PASS); test2/3 still fail on a separate swapDepths-rewind issue (depth_swapped block re-uses MC instead of fresh-placing)
  - id: 7
    name: "Verify on full guardrail battery + target tests; expect cascade of unload-ordering / register_class regressions, fix one-by-one"
    status: pending
dependencies:
  - "complete/CLONESPRITE_DEPTH_BIAS_PLAN.md (Phase 2c giving clones a real display_list slot is the prerequisite for ENTER_FRAME / UNLOAD dispatch)"
  - "complete/DEFERRED_CLIP_UNLOAD_PLAN.md (UNLOAD queue infrastructure)"
  - "complete/CLIP_EVENT_ROUND_DISPATCH_PLAN.md (INIT/CONSTRUCT round dispatch infrastructure)"
parent_plan: "complete/CLONESPRITE_DEPTH_BIAS_PLAN.md (this is the explicit follow-up — depth-bias unblocked clone slots, this plan fills in the dispatch)"
-->

## Problem statement

After the CloneSprite depth-bias unification (CI 25269609961, all 8 suites
zero-diff), four target tests still fail on missing clip-event lines, not
on depth values. Cloned MCs are structurally placed in `display_list` at
biased SWF depths, but they don't fire `CLIP_EVENT_INITIALIZE`,
`CLIP_EVENT_CONSTRUCT`, `CLIP_EVENT_ENTER_FRAME`, or `CLIP_EVENT_UNLOAD`
clip-event handlers — and on backward goto, re-placed static MCs don't
re-fire `CLIP_EVENT_CONSTRUCT`.

Reference: Ruffle's `clone_sprite` (`core/src/avm1/globals/movie_clip.rs:952`)
treats the clone like any fresh placement:

```rust
library.instantiate_by_id(sprite.id(), context.gc())              // fresh instance
cloned_sprite.set_name(context.gc(), target);
parent.replace_at_depth(context, cloned_sprite, depth);           // standard placement
// ...
cloned_sprite.init_clip_event_handlers(sprite.clip_actions().into());
// ...
cloned_sprite.post_instantiation(context, init_object, Instantiator::Avm1, true);
```

Three things matter:

1. **The clone is a real display object placed at depth** — `replace_at_depth`
   wires it into the parent's render list and exec list.
2. **Clip event handlers are explicitly transplanted** — `init_clip_event_handlers`
   takes a copy of the source's `clip_actions` slice.
3. **`post_instantiation` runs the same lifecycle as a fresh placement** —
   which queues `CLIP_INIT`/`CLIP_CONSTRUCT`/`CLIP_LOAD` and runs frame_0.

Our `ng_cloneSprite` does (1) (Phase 2c gave it a real slot), (2) is missing
(slot's `clip_actions` is explicitly cleared at `tag_stubs.c:2815-2816, 3050-3051`),
and (3) is bypassed entirely (no `queue_clip_*_events` calls; LOAD has a
side-channel via `ng_queue_pending_load`; INIT/CONSTRUCT have no path).

## Failure shape per test

CI 25284302806 (`e06c67e4`) confirms these are unchanged from the prior CI.

### `duplicate_movie_clip_test` (3/33 lines)

Source SWF: `gnash/testsuite/misc-ming.all/duplicate_movie_clip_test.c`.
mc2 placed with `SWFACTION_ONLOAD` / `SWFACTION_ENTERFRAME` / `SWFACTION_UNLOAD`
clip events. `duplicateMovieClip('mc2', 'dup2', 2)` clones mc2.

| Expected line | Actual line | Diagnosis |
|---|---|---|
| `onClipEnterFrame triggered` (2nd occurrence) | (missing) | dup2 doesn't fire ENTER_FRAME |
| `onClipUnload triggered` (2nd occurrence) | (missing) | dup2 doesn't fire UNLOAD |
| `_root.x2 == 3` | `_root.x2 == 1` | x2 increments only when ENTER_FRAME fires; dup2's two ticks worth never fire |
| `_root.x3 == 2` | `_root.x3 == 1` | x3 increments only on UNLOAD; dup2's UNLOAD never fires |

LOAD fires correctly for dup2 (rescued via `ng_queue_pending_load`).

### `displaylist_depths/displaylist_depths_test9` (3/23 lines)

Source: `displaylist_depths_test9.c`. static4 placed with `SWFACTION_CONSTRUCT`.
`duplicateMovieClip('/static4', 'dup0', -16380)` clones static4. Later
`gotoAndStop(5)` rewinds, re-placing static4.

| Expected line | Actual line | Diagnosis |
|---|---|---|
| `_level0.dup0 constructed` | (missing) | dup0 doesn't fire CONSTRUCT |
| `_level0.static4 constructed` (2nd occurrence) | (missing) | rewind re-place doesn't re-fire CONSTRUCT |
| `mc4Constructed == 2` (line 153) | `mc4Constructed == 1` | dup0's CONSTRUCT never ran |
| `mc4Constructed == 3` (line 158) | `mc4Constructed == 1` | rewind static4's CONSTRUCT never ran either |

### `displaylist_depths/displaylist_depths_test{2,3}` (15/31 and 17/32 lines)

Source: `displaylist_depths_test{2,3}.c`. static3 placed with `SWFACTION_CONSTRUCT`
that increments `_root.depth3Constructed`. Later `gotoAndStop(4)` rewinds,
re-placing static3.

| Expected line | Actual line | Diagnosis |
|---|---|---|
| `_level0.static3 onClipConstruct` (2nd occurrence) | (missing) | rewind re-place doesn't re-fire CONSTRUCT |
| `_root.depth3Constructed set to 2` | (missing) | side-effect of the missing CONSTRUCT |
| `depth3Constructed == 2` | `depth3Constructed == 1` | counter stays at 1 |

Both tests also emit `ERROR: heap_alloc() called before heap_init()` to
stderr — pre-existing, unrelated to the depth-bias plan, listed in the
parent plan as a separate tail-end issue.

## Root cause analysis

### Why clones don't fire INIT / CONSTRUCT / ENTER_FRAME / UNLOAD

`tag_stubs.c:2807-2816` (in `ng_cloneSprite`):

```c
display_list[target_swf_depth] = display_list[src_depth];  // full slot copy
display_list[target_swf_depth].instance_name = strdup(target_name);
display_list[target_swf_depth].instance_name_owned = 1;
display_list[target_swf_depth].sprite_display_list = NULL;
display_list[target_swf_depth].sprite_max_depth = 0;
display_list[target_swf_depth].sprite_dl_capacity = 0;
display_list[target_swf_depth].sprite_needs_init = 0;
display_list[target_swf_depth].clip_actions = NULL;        // breaks dispatch
display_list[target_swf_depth].clip_action_count = 0;       // breaks dispatch
```

The same shape exists in `ng_cloneSpriteFromMC` at `tag_stubs.c:3043-3051`.

Three load-bearing decisions in the pre-Phase-2c era when this code was
written:

1. **`sprite_needs_init = 0`** — clones don't get the standard frame_0
   replay because `ng_cloneSprite` runs frame_0 manually further down (lines
   2940+ for the children-population loop). That manual replay populates
   the clone's *child* display list but doesn't drive the clone's own
   `sprite_initialized` lifecycle to `>= 2`.

2. **`clip_actions = NULL`** — clones used to live at SWF depths above
   `INITIAL_DISPLAYLIST_CAPACITY=1024`, so they had no slot to dispatch
   clip events from. Pre-Phase-2c, dispatch was handled via the side-channel
   `ng_queue_pending_load` for LOAD, and ENTER_FRAME / UNLOAD simply didn't
   fire (no test exercised them through CI). Phase 2c gave clones a real
   slot but didn't update this clear.

3. **No `queue_clip_init_events` / `queue_clip_construct_events` calls** —
   tagPlaceObject2 queues INIT/CONSTRUCT for fresh placements (`tag.c:4463-4464`).
   `ng_cloneSprite` bypasses tagPlaceObject2 entirely, so neither queue is
   touched.

### Why the naive "share the pointer" fix fails

Attempted in the 2026-05-03 close-out session: removed the two
`clip_actions = NULL; clip_action_count = 0` lines so the slot copy
preserves the source's pointer (the clip_actions array is recompiler-emitted
static data, never freed per-instance). Result: massive ENTER_FRAME firing
regression — dup2 fires `onClipEnterFrame triggered` ~30+ times past EOF.

Two interacting reasons:

1. **`sprite_initialized` stays at 0 for the clone.** At clone time inside
   the DoAction (frame 2), source mc2's `sprite_initialized` is still 0
   (process_sprite_needs_init has not run yet — it runs later in
   tagShowFrame). The full slot copy gives the clone the same 0. After
   tagShowFrame, mc2 gets bumped to 1 via `process_sprite_needs_init`;
   `upgrade_sprite_initialized` then bumps mc2 to 2. The clone is at 0 —
   nothing bumps it. So the clone is invisible to
   `dispatch_enterframe_clip_actions` (which gates on `>= 2`).

   But: when a *different* code path eventually walks the slot during a
   later frame after some unrelated initialization state-bump, the clone
   *can* qualify for dispatch — and once it qualifies, it never stops,
   because…

2. **Removal doesn't clear the slot's `clip_actions`.** When
   `dup2.removeMovieClip()` runs, the slot's `char_id` gets cleared but the
   `clip_actions` pointer stays pointed at mc2's static data. If any
   downstream walk skips the `char_id` check (or the check fails to gate
   dispatch — the dispatch function gates on `char_id != 0`, so this is
   actually fine *as long as `char_id` is properly cleared*), ENTER_FRAME
   would re-fire. The repro showed it does fire forever after removal,
   which means `char_id` is *not* getting cleared on this path either — or
   the dispatch's gate is bypassed by some other lifecycle event.

This is the kind of issue where "fix one thing" cascades into "fix three
things interlocked": you can't share `clip_actions` without driving the
init lifecycle and clearing the slot on removal, and you can't drive the
init lifecycle without first sharing `clip_actions`. Bundle them.

### Why backward goto re-placement of static MCs misses CONSTRUCT

`displaylist_depths_test{2,3,9}` rewind via `gotoAndStop(N)`. Per Ruffle,
when a static MC is removed and re-placed during catch-up (because its
`PlaceObject2` tag is part of the target frame's tag stream and the
backward catch-up reset the timeline), the new instance fires CONSTRUCT
just like a fresh placement.

Our `tagPlaceObject2` (`tag.c:4463-4465`) queues `CLIP_EVENT_CONSTRUCT`
unconditionally on every successful placement. So the queue should fill.
But — per `_target after failed SetTarget` notes in the parent plan, our
backward-goto display protection (`tagPlaceObject2`/`tagPlaceObject2Ratio`:
"if `catch_up_backward && catch_up_mode` and depth already has entry from
later frame, skip placement") suppresses placement entirely on rewind.
That suppression skips the `queue_clip_construct_events` call along with
the placement, and the re-placed MC's CONSTRUCT never queues.

A correct fix needs to distinguish "this depth already had this same
character_id placed at an earlier frame, no work needed" (the legitimate
backward-goto guard) from "the rewind brought the timeline back to a frame
where this MC's CONSTRUCT *should* re-fire as a fresh placement"
(displaylist_depths semantics). Ruffle's run_goto handles this by
*removing* the previous instance during the catch-up sweep and *re-creating*
a new one on the target frame's PlaceObject — fresh INSTANCE = fresh
CONSTRUCT.

## Investigation findings (2026-05-03 close-out session)

Local instrumentation confirmed:

```
DEBUG ng_cloneSprite src_depth=10 src_init=0 src_clip=0 |
                     tgt_slot=16385 tgt_clip_actions=(nil) count=0 tgt_init=0
DEBUG ng_cloneSprite src_depth=20 src_init=0 src_clip=3 |
                     tgt_slot=16386 tgt_clip_actions=0x... count=3 tgt_init=0
```

dup1 (no clip events on source) gets 0 actions — fine. dup2 (3 clip events
on source) gets 3 actions when `clip_actions` is shared, but `sprite_initialized=0`
on both source and clone at clone time — confirming the timing analysis above.

Verified with `git show` that the depth-bias infrastructure (commits
`06991d472ec7` and `e06c67e45668`) gives clones their slot at SWF depth
`as_depth + 16384` cleanly. Slot allocation and `clone_depth_register`
work correctly; `max_depth` is bumped; the slot is reachable via display
list traversal. The infrastructure side is solid.

## Proposed phases

### Phase 1 — Audit: trace existing clone paths vs Ruffle pipeline

**Goal:** map our `ng_cloneSprite` / `ng_cloneSpriteFromMC` to Ruffle's
`instantiate_by_id` → `replace_at_depth` → `init_clip_event_handlers` →
`post_instantiation` pipeline. Identify every gap. Document call graph
in this plan as a Phase 1 deliverable.

Specific items to audit:

- `tag_stubs.c:2735+` (`ng_cloneSprite`) — what runs, what doesn't, vs.
  `tag.c:3985+` (`tagPlaceObject2`).
- `tag_stubs.c:3003+` (`ng_cloneSpriteFromMC`) — same, but for the
  script-created-MC source path.
- `dispatch_enterframe_clip_actions` (`tag.c:1799`) — confirm it walks
  the clone's slot once `sprite_initialized >= 2` and `clip_action_count > 0`.
- The unload paths — `ng_on_remove_object` (`tag_stubs.c:780`),
  `actionFireOnUnload` (action.c) — confirm they clear `clip_actions` on
  the slot post-fire so subsequent dispatches stop.
- Backward goto guard in `tagPlaceObject2` — locate the
  `catch_up_backward && catch_up_mode` skip and trace its interaction with
  `displaylist_depths_test{2,3}`.

**Deliverable:** Phase 1 audit notes appended to this plan, with line-number
references and a flowchart of correct vs current behavior. **No code
changes** in Phase 1 — it's a read-only investigation that the subsequent
phases depend on.

### Phase 2 — Inherit `clip_actions` on the clone slot

Remove the `clip_actions = NULL; clip_action_count = 0` lines at
`tag_stubs.c:2815-2816` and `:3050-3051`. The slot copy preserves the
source's pointer to recompiler-emitted static data — never freed
per-instance, so sharing is safe.

This *alone* is unsafe (see "Why the naive share fails" above) — must be
bundled with Phases 3 + 5 in a single commit.

### Phase 3 — Drive cloned slot through `sprite_needs_init` lifecycle

Two options to investigate during Phase 1:

**Option A: set `sprite_needs_init = 1` on the clone.** Let
`process_sprite_needs_init` handle it during the next tagShowFrame. This
gives the clone the full standard init: frame_0 replay, registered-class
constructor, `sprite_initialized = 1` → upgrade to 2 next tick. Correctly
deferred to "init tick fires LOAD, not EnterFrame" (Ruffle model).

**Concern:** ng_cloneSprite already runs frame_0 manually for the clone's
*children* (lines 2940+). Setting `sprite_needs_init = 1` would re-run
frame_0 a second time, which would double-place children. Need to either
remove the manual replay (preferred, restores symmetry with `tagPlaceObject2`)
or add a flag to skip it inside `process_sprite_needs_init`.

**Option B: directly set `sprite_initialized = 1`** (mimicking the
post-init state) and skip the standard init path. Simpler but bypasses
the construct/registerClass machinery, which would still need separate
hooks.

Phase 1 audit determines which option is structurally cleaner. Option A
is closer to the Ruffle model.

### Phase 4 — Queue CLIP_INIT / CLIP_CONSTRUCT / CLIP_LOAD on the clone

Replace `ng_queue_pending_load`'s side-channel with the standard
`queue_clip_load_events(app_context, target_swf_depth)` call from
`tag.c:3933`. Add `queue_clip_init_events` and `queue_clip_construct_events`
calls to `ng_cloneSprite` — symmetric with `tagPlaceObject2:4463-4464`.

This requires the clone's slot to have `clip_actions` populated *before*
the queue calls fire — i.e., Phase 2 must land first.

The existing `ng_queue_pending_load` mechanism stays as-is for the
`mc.duplicateMovieClip` AS-method path that explicitly does NOT fire LOAD
per the comment at `tag_stubs.c:3163` ("`duplicateMovieClip` does NOT
fire onLoad for the clone (unlike CloneSprite)"). Need to re-verify this
asymmetry against Ruffle source — it's likely an artifact of our pre-Phase-2c
implementation, not a real semantic difference. If it's an artifact, this
becomes a single uniform path.

### Phase 5 — Clear slot `clip_actions` on clone removal

Audit `removeMovieClip` and `RemoveObject2` for clones. After Phase 2's
shared-pointer change, removal must:

1. Clear `clip_actions = NULL; clip_action_count = 0` on the slot before
   marking it removed (so dispatch_enterframe doesn't re-fire on a removed
   slot due to bug or race).
2. Confirm `char_id = 0` is set (this gates dispatch_enterframe at
   `tag.c:1837`).

Both are belt-and-suspenders — `char_id = 0` should be sufficient if the
dispatch gate is robust, but the close-out attempt showed dispatch *did*
re-fire after removal, suggesting at least one gate is currently bypassed.
Phase 1 audit identifies which one.

### Phase 6 — Backward goto: re-fire CONSTRUCT for re-placed static MCs

This phase only affects `displaylist_depths_test{2,3,9}`, not
`duplicate_movie_clip_test`. It's the rewind half of the failure.

Specific work:

- Trace the `catch_up_backward && catch_up_mode` placement-skip in
  `tagPlaceObject2`/`tagPlaceObject2Ratio`.
- Determine when the skip is correct (re-applying the same PlaceObject2
  for an already-extant entry = no-op) vs. incorrect (rewind that should
  produce a fresh instance).
- Mirror Ruffle's `run_goto` behavior: explicit remove during catch-up
  sweep, fresh re-place at target frame.
- Likely involves the goto sweep building a `goto_commands` aggregation
  that knows which depths get fresh re-placements.

Risk: this touches `tag.c:tagPlaceObject2`'s catch-up branch, which is
exercised by every backward goto test. Existing tests that depend on the
skip behavior (`goto_rewind1/2/3`, `execution_order2/3`) are guardrails.

### Phase 7 — Verify on full guardrail battery

Battery (run with `rm -rf RecompiledScripts RecompiledTags` first to
defeat stale cache — see CLONESPRITE_DEPTH_BIAS_PLAN's Phase 2a lesson):

**AVM1 lifecycle (16 tests):**
- `clip_events`, `unload`, `clip_events_with`, `bad_placeobject_clipaction`
- `attach_movie`, `clone_sprite_edittext`, `clone_sprite_edittext_dynamic`,
  `clone_sprite_types`, `duplicate_movie_clip`, `duplicate_movie_clip_drawing`
- `goto_rewind1`, `goto_rewind2`, `goto_rewind3`, `execution_order1`,
  `execution_order2`, `execution_order3`

**Gnash misc-ming clone-adjacent (12 tests):**
- `static_vs_dynamic1`, `static_vs_dynamic2`, `loop/loop_test3`, `_test5`,
  `_test9`, `attachMovieTest`, `place_and_remove_object_test`,
  `displaylist_depths_test11`, `displaylist_depths_test8`, `DepthLimitsTest`,
  `duplicate_movie_clip_test2`, `displaylist_depths_test`

**Gnash misc-ming target tests (4 tests — expected to flip):**
- `displaylist_depths_test2`, `_test3`, `_test9`, `duplicate_movie_clip_test`

**Shumway clones (4 tests):**
- `from_shumway/avm1/duplicateMovieClip/dontremove`, `duplicateMovieClip`,
  `name-coercion`, `samedepth`

**Register class (4 tests — interaction with constructor dispatch):**
- `register_class`, `register_and_init_order`, `register_class_return_value`,
  `registerClassTest2`

Verify locally with `--clean` semantics, then push for full CI verification.
Phase 7 includes the iterative regression-fix stage if anything in the
battery breaks. Budget: 1-2 sessions for the iterative cycle.

## Risks and guardrails

**High-risk areas:**

1. **`sprite_initialized` lifecycle changes** are touchy — getting them
   wrong has cascading effects on every sprite-init-dependent test
   (essentially every misc-ming test). Phase 1 audit must identify all
   sites that read `sprite_initialized` and confirm they tolerate Phase 3's
   change.

2. **`clip_actions` sharing between source and clone** could surface
   double-free or use-after-free bugs if anyone *does* free the array
   per-instance. Confirmed in close-out: nothing currently frees, but
   future code might. Add a lifetime invariant comment.

3. **Backward goto Phase 6** is the most likely place to break unrelated
   tests. The catch-up branch is load-bearing for `goto_rewind*`,
   `execution_order*`, `init_action`, etc. Treat Phase 6 as a separate
   sub-deliverable that can land independently of 2-5.

**Lower-risk:**

4. Phase 4's queue-event additions are additive — they fill a gap rather
   than change existing behavior. The risk is missing edge cases (e.g.,
   `mc.duplicateMovieClip` should *not* fire LOAD per current comment;
   audit confirms this against Ruffle).

**Ordering invariant:** Phases 2 + 3 + 5 must land in a single commit
(see "naive share fails" above). Phase 4 follows. Phase 6 is independent.

## Affected tests (target gains)

| Test | Suite | Before | After Phases 2-5 | After Phase 6 |
|------|-------|--------|------------------|----------------|
| `duplicate_movie_clip_test` | misc-ming | 3/33 | RUFFLE_MATCHED (effective pass) | unchanged |
| `displaylist_depths/displaylist_depths_test9` | misc-ming | 3/23 | ~20/23 (dup0 CONSTRUCT done) | **PASS (23/23)** |
| `displaylist_depths/displaylist_depths_test2` | misc-ming | 15/31 | unchanged | unchanged — blocked on swapDepths-rewind issue (depth_swapped block) |
| `displaylist_depths/displaylist_depths_test3` | misc-ming | 17/32 | unchanged | unchanged — same blocker as test2 |

## Status (2026-05-03 implementation session)

Phases 1-5 + Phase 6 (clone-replaced sub-issue) implemented:

**`duplicate_movie_clip_test`**: 3/33 → RUFFLE_MATCHED (effective pass).
**`displaylist_depths/displaylist_depths_test9`**: 3/23 → PASS (23/23).

**Implementation summary:**
- `tag_stubs.c::ng_cloneSprite` / `ng_cloneSpriteFromMC`: removed
  `clip_actions = NULL` clearing (Phase 2); set `sprite_initialized = 2`
  directly on clone slot since manual frame_0 already populates children
  (Phase 3 — Option B); set new `clone_replaced = 1` flag (Phase 6);
  call `ng_queue_placement_clip_events` for in-cap clones (Phase 4).
  Kept `ng_queue_pending_load` for LOAD ordering (insertion-order queue
  shared between in-cap and out-of-cap clones — `avm1/duplicate_movie_clip`
  mixes both depth ranges).
- `tag.c::ng_queue_placement_clip_events` (new public helper): queues +
  drains INIT and CONSTRUCT inline (synchronous behavior matching Ruffle's
  `post_instantiation`).
- `tag.c::ng_queue_slot_unload_events` (new public helper): queues UNLOAD
  callbacks for a slot. Used by AS removeMovieClip path.
- `action.c::actionRemoveSprite` and the `removeMovieClip` MC method:
  call `ng_queue_slot_unload_events` and clear the display_list slot
  before marking the MC removed (Phase 5).
- `swf.h::DisplayObject`: new `clone_replaced` u8 field — Ruffle's
  `avm1_clone_target.is_some()` analog.
- `tag.c::tagPlaceObject2` / `tagPlaceObject2Ratio`: survives_rewind check
  returns false when `clone_replaced=1`; non-survives branch also clears
  on `clone_replaced` (Phase 6).
- `tag.c::clear_display_entry`: resets `clone_replaced`.

**Remaining blocker (test2/3):** these fail on a *separate* swapDepths-rewind
issue, not the clone clip-event dispatch path. The flow is:
1. PlaceObject2 places `static3` at depth 3 with CONSTRUCT clip event.
2. `static3.swapDepths(10)` moves it to depth 10. Slot 3 becomes empty.
3. `gotoAndStop(4)` rewinds. Frame 4's PlaceObject2 for static3 at depth 3
   replays.
4. `tagPlaceObject2`'s "depth_swapped re-place" block (tag.c:4271+) finds
   the MC at depth 10 (depth_swapped=1), re-uses it at depth 3 with
   `sprite_needs_init = 0` (suppressing CONSTRUCT). Per Ruffle, this
   should freshly place a *new* MC at depth 3 (re-firing CONSTRUCT) and
   leave the depth-10 MC alone.
5. The fix is risky: changing the depth_swapped block to allow fresh
   placement would likely regress other swapDepths tests (notably
   `avm1/rewind_depth` which depends on the re-use semantic). Tracked
   separately in `blocked/SWAPDEPTHS_REWIND_FRESH_PLACEMENT_PLAN.md`
   (blocked 2026-05-03 on architectural name-keyed MovieClip identity —
   see plan's Phase 1 Audit Findings).

Bonus expected gains in adjacent tests where clip-event dispatch on clones
was incidentally exercised: TBD per Phase 7 audit.

**Estimated effective-pass impact:** +2 to +4 misc-ming tests flipping to
PASS or `ruffle_matched`. The largest single chunk in the parent
CLONESPRITE_DEPTH_BIAS plan that didn't flip — this finishes the cluster.

## Estimated session budget

- Phase 1 (audit, no code): 1 session.
- Phases 2 + 3 + 5 (bundled commit): 1-2 sessions including local battery
  + iterative fix.
- Phase 4 (queue events): 0.5-1 session.
- Phase 6 (backward goto): 1-2 sessions, separate commit.
- Phase 7 (CI verification + regression fixes): 1-2 sessions.

Total: 4-7 sessions, multi-commit. Sized similarly to the parent
CLONESPRITE_DEPTH_BIAS effort.

## Why this is the right shape

The parent plan unblocked the structural side of clone placement
(Phase 2c gave clones a real `display_list` slot at `as_depth + 16384`).
This plan fills in the dispatch side that the structural change exposed:
once a clone has a slot, the standard tag-stream lifecycle hooks should
just work — but `ng_cloneSprite` predates the slot machinery and bypasses
those hooks. The fix is to align the clone path with the
`tagPlaceObject2` path: shared infrastructure, shared lifecycle, shared
clip-event queue. Anything else means maintaining two parallel placement
paths forever.

The 2026-05-03 close-out attempt to "just share the clip_actions pointer"
was structurally correct but missed the lifecycle interlock — it would
have worked if `sprite_initialized` were correctly bumped and removal
correctly cleared the slot. The plan above does both, in a single
commit, with Phase 1 audit as the prerequisite to identify any other
interlocks the close-out missed.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `complete/CLONESPRITE_DEPTH_BIAS_PLAN.md` | Parent plan — unblocked the slot allocation that this plan's dispatch hooks need. The 2026-05-03 close-out section in that plan documents the dead-end that motivated this followup. |
| `complete/DEFERRED_CLIP_UNLOAD_PLAN.md` | UNLOAD queueing infrastructure — Phase 5 needs to extend its slot-clearing logic to clones. |
| `complete/CLIP_EVENT_ROUND_DISPATCH_PLAN.md` | INIT/CONSTRUCT round-dispatch ordering — Phase 4's `queue_clip_init_events`/`queue_clip_construct_events` calls feed the same `ActionQueue` priority lanes set up here. |
| `complete/REGISTERCLASS_LIFECYCLE_PLAN.md` | If the source MC has a registered class, the clone should also fire the registered constructor. Phase 4 must include `queue_register_ctor` for parity with `tagPlaceObject2:4465`. |
| Ruffle source: `core/src/avm1/globals/movie_clip.rs::clone_sprite` | Reference implementation — `init_clip_event_handlers` + `post_instantiation` is the model. |
| Ruffle source: `core/src/display_object/movie_clip.rs::post_instantiation` | What `post_instantiation` does — `set_default_instance_name`, `add_to_exec_list`, `construct_as_avm1_object`. |
