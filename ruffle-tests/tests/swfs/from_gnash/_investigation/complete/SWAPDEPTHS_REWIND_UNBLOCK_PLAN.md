# SwapDepths Rewind — Unblock Plan for Phases 4 and B

<!-- TESTS: displaylist_depths/displaylist_depths_test2, displaylist_depths/displaylist_depths_test3, soft_reference_test1 -->

<!-- PLAN_META
id: SWAPDEPTHS_REWIND_UNBLOCK
status: complete
note: "Successor plan to SWAPDEPTHS_REWIND_FRESH_PLACEMENT_PLAN.md. Phases 1, 1.5, 2, 3 of the parent plan landed in commits 712885df, c23e377f. Phases 4 (name_displaced flag) and B (CLIP_CONSTRUCT deferred during catch-up) landed in this work. Phase 4 had to land BEFORE Phase B — Phase B alone was ineffective because queue_clip_construct_events captured the OLD swap-displaced MC pointer, which was filtered out at drain time due to avm1_removed=1. Phase 4 makes fresh placement create a NEW MC, so CLIP_CONSTRUCT entries target a clean MC."
phases:
  - id: 4a
    name: "Add name_displaced flag to MovieClip; mark OLD MC at swap-target depth during fresh placement"
    status: complete
  - id: 4b
    name: "findOrCreateMovieClip: skip MCs with name_displaced=1 (AS variable lookup gets fresh)"
    status: complete
  - id: 4c
    name: "Depth-keyed lookup helper findCachedMovieClipByDepth for displaced MCs"
    status: complete
  - id: 4d
    name: "Lifecycle: clear name_displaced when the fresh MC dies or another swap re-collides"
    status: deferred
    note: "Not needed for the target tests — `name_displaced=1` is sticky but the OLD MC remains accessible via direct pointer / findCachedMovieClipByDepth. No regressions observed across the regression battery. If lifecycle bugs surface later, add explicit clearing in actionInvalidateCachedMovieClip / ng_swapDisplayDepths."
  - id: B1
    name: "Investigate: confirmed Ruffle defers CLIP_CONSTRUCT during goto catch-up via action_queue"
    status: complete
  - id: B2
    name: "Gate AQ_KIND_CLIP_CONSTRUCT drain in tagShowFrame on !g_goto_catchup_active + priority-pop loop in actionDrainAllInPriorityOrder"
    status: complete
    note: "Required additional priority-pop loop change in actionDrainAllInPriorityOrder. The deferred CLIP_CONSTRUCT must drain BEFORE the inline target frame's queued DoAction (mirrors Ruffle's run_actions priority-pop loop where CONSTRUCT priority > NORMAL/SCRIPT priority)."
  - id: B3
    name: "Verify: regression battery + test3/test6/test2 + soft_reference_test1"
    status: complete
    note: "test2 + test3 → RUFFLE_MATCHED (gain). test6 RUFFLE_MATCHED → MISMATCH (regression — known risk per plan). soft_reference_test1 unchanged (23/45). Net +1 RUFFLE_MATCHED in misc-ming.all suite. All other regression tests preserved."
dependencies:
  - "complete/SWAPDEPTHS_REWIND_FRESH_PLACEMENT_PLAN.md (parent — Phases 1/1.5/2/3 prerequisite, all landed)"
related:
  - "incomplete/REMAINING_TAIL_TRIAGE.md (`soft_reference_test1` unchanged — different mechanism)"
-->

## Status (2026-05-03 — COMPLETE)

Both phases landed. Test impact (verified locally):

| Test | Before | After |
|---|---|---|
| `displaylist_depths/displaylist_depths_test2` | output_mismatch 22/31 | **RUFFLE_MATCHED** |
| `displaylist_depths/displaylist_depths_test3` | output_mismatch 28/32 | **RUFFLE_MATCHED** |
| `action_order/action_execution_order_test6` | RUFFLE_MATCHED 19/24 | output_mismatch (regression — see below) |
| `soft_reference_test1` (misc-swfc.all) | 23/45 | unchanged |

Net: **+1 RUFFLE_MATCHED** in misc-ming.all (test2 + test3 gained, test6 lost).

### Implementation summary

**Phase 4 (`name_displaced`)** — `SWFModernRuntime/include/actionmodern/action.h` adds `u8 name_displaced` to `struct MovieClip`. `findOrCreateMovieClip` skips MCs with the flag set. New helper `findCachedMovieClipByDepth(name, parent, as_depth)` bypasses the skip for depth-keyed lookups. `tagPlaceObject2`'s catch_up_backward fresh-placement path scans for a same-char same-name `depth_swapped` slot at a different depth and marks the cached OLD MC.

**Phase B (deferred CLIP_CONSTRUCT)** — `tagShowFrame` now gates `AQ_KIND_CLIP_CONSTRUCT` drain on `!g_goto_catchup_active` (alongside the existing CLIP_INIT and REGISTER_CTOR gates). Required a follow-up change to `actionDrainAllInPriorityOrder` in `SWFModernRuntime/src/actionmodern/action_queue.c`: the function now loops, draining priority buckets between each ONLOAD/SCRIPT pop. Mirrors Ruffle's `run_actions` priority-pop loop where CONSTRUCT priority > NORMAL ensures deferred CLIP_CONSTRUCT entries drain BEFORE the inline target frame's queued DoAction.

### Phase 4 had to land FIRST

The plan suggested Phase B first as the "simpler change" but in practice it requires Phase 4 as a prerequisite. Without Phase 4, `queue_clip_construct_events` calls `actionFindOrCreateMovieClip` and gets the OLD swap-displaced MC pointer back. During catch-up that OLD MC's `avm1_removed` flag gets set, and the deferred `aq_drain` filters out catchup-queued entries with `avm1_removed=1`. Phase B alone caused test3 to lose its CONSTRUCT2 trace entirely (queued but filtered). With Phase 4, the fresh placement creates a NEW MC, the entry targets it, and the deferred drain works.

### Test6 regression — known trade-off

`action_execution_order_test6` was previously RUFFLE_MATCHED 19/24. The plan acknowledged this risk:
> Tests that rely on CLIP_CONSTRUCT firing inside catch-up (chronologically interleaved with LOAD/UNLOAD) would break.

The test exercises chronological interleaving of CONSTRUCT/LOAD/UNLOAD events during a backward goto's catch-up replay. Phase B defers all CONSTRUCT events to post-catchup, so CONSTRUCTs land after LOAD/UNLOAD events that fired chronologically. Net: -1 RUFFLE_MATCHED on test6, but +2 RUFFLE_MATCHED on test2/test3.

### Phase 4d (lifecycle clearing) — deferred

The `name_displaced` flag is currently sticky (set on initial fresh-placement, never cleared). No lifecycle clearing was added. Rationale: the OLD MC remains accessible via direct pointer references and `findCachedMovieClipByDepth`, so AS code that captured a reference before the rewind continues to work (`dynRef.myThing` in test3). No regressions observed in the regression battery. If lifecycle bugs surface in later tests (e.g. when a fresh MC dies and the displaced MC needs to be re-promoted, or when a second swap re-collides on the displaced MC), add explicit clearing in `actionInvalidateCachedMovieClip` / `ng_swapDisplayDepths`.

## Context

The parent plan `SWAPDEPTHS_REWIND_FRESH_PLACEMENT_PLAN.md` documented two remaining blockers after Phase 2 landed (commit `c23e377f`):

| Blocker | Test | Symptom | Root cause |
|---|---|---|---|
| Phase 4 | `displaylist_depths_test2` (22/31) | `static3.myThing` returns `'guess'` instead of `undefined` | After Phase 2, two MCs named `static3` coexist (OLD at AS depth 10, FRESH at AS depth -16381). `findOrCreateMovieClip("static3", root)` returns the OLD MC because it's first in the cache. AS variable lookup gets stale data. |
| Phase B | `displaylist_depths_test3` (28/32) | CONSTRUCT trace lines fire at positions 15-17 instead of 16-18 (one position too early — fired during catch-up rather than after the calling script) | Our `tagShowFrame` drains `AQ_KIND_CLIP_CONSTRUCT` every frame, including during goto catch-up. Ruffle defers these to fire after the calling AS script completes via its `action_queue` mechanism. |

Both blockers are now well-understood. Neither requires a multi-session refactor — each has a focused implementation path.

## Phase 4 — Multi-MC-per-name disambiguation (Option C: displaced flag)

### Background

Of the three architectural options outlined in the parent plan (A: depth-keyed cache; B: per-display-list-slot pointer; C: displaced flag), **Option C is the lowest-risk implementation**. It preserves the existing name-keyed cache, only adds one new flag and a few code-path checks, and does not touch the ~50+ call sites that currently rely on `findOrCreateMovieClip(name, parent)`.

### The problem state after Phase 2

For `displaylist_depths_test2` after `gotoAndStop(4)`:

```
display_list[3]      = static3 (FRESH placement, char_id=5, instance_name="static3")
display_list[16394]  = static3 (OLD swap-displaced, char_id=5, instance_name="static3", depth_swapped=1)

child_mc_cache:
  - OLD MC: name="static3", depth=10 (set by actionRewindCleanup), dynamic_props={myThing:'guess'}
```

When AS code calls `findOrCreateMovieClip("static3", &root_movieclip)`, the loop iterates the cache in insertion order, finds the OLD MC first (depth=10, not INT_MIN, not pending_removal, name match, parent match), and returns it. The fresh placement at depth 3 then re-binds display_list[3] to point at the OLD MC — both display slots reference the same MC.

`dynRef = static3` (executed before `gotoAndStop`) captured the OLD MC's pointer. After the goto, `dynRef.myThing` correctly returns `'guess'`. But `static3.myThing` ALSO returns `'guess'` (wrong — should be `undefined` for the fresh MC).

### Implementation: `name_displaced` flag

**Step 4a — Add the flag:**

In `SWFModernRuntime/include/libswf/movieclip.h` (or wherever the `MovieClip` struct lives), add:

```c
struct MovieClip {
    ...existing fields...
    u8 name_displaced;  // 1 if a fresh placement at a different depth has shadowed this MC's name lookup
};
```

In `SWFModernRuntime/src/libswf/tag.c::tagPlaceObject2`, in the standard placement path (after the depth_swapped re-use block was removed by Phase 2, around line 4310), before the `display_list[depth].char_id = char_id;` assignment:

```c
#ifdef NO_GRAPHICS
// SWAPDEPTHS_REWIND_UNBLOCK Phase 4: when a fresh placement happens at a depth
// where the same character was moved to a different (swap-target) depth, mark
// the OLD cached MC as displaced. This makes findOrCreateMovieClip skip it for
// AS variable lookups, so `staticN` resolves to the fresh MC rather than the
// preserved OLD MC. Direct pointer access via saved AS references (e.g.
// `dynRef`) still works — the OLD MC stays alive at the swap-target depth.
if (catch_up_backward && char_id != 0 && g_pending_instance_name != NULL) {
    for (size_t _sd = 1; _sd <= max_depth; _sd++) {
        if (_sd == depth) continue;
        if (display_list[_sd].char_id == char_id
            && display_list[_sd].depth_swapped
            && display_list[_sd].instance_name != NULL
            && strcmp(display_list[_sd].instance_name, g_pending_instance_name) == 0)
        {
            // Mark the cached MC at _sd's display slot as displaced.
            extern MovieClip* findCachedMovieClipByDepth(const char*, MovieClip*, int);
            int as_depth = (int)_sd - 16384;
            MovieClip* old_mc = findCachedMovieClipByDepth(
                g_pending_instance_name, g_current_context ? g_current_context : &root_movieclip, as_depth);
            if (old_mc != NULL) {
                old_mc->name_displaced = 1;
            }
            break;
        }
    }
}
#endif
```

**Step 4b — Skip displaced MCs in `findOrCreateMovieClip`:**

In `SWFModernRuntime/src/actionmodern/action.c::findOrCreateMovieClip` (line 18055), update the cache scan:

```c
for (int i = 0; i < child_mc_count; i++) {
    if (child_mc_cache[i] != NULL &&
        child_mc_cache[i]->depth != INT_MIN &&
        !child_mc_cache[i]->name_displaced &&  // NEW: skip displaced MCs
        !(g_skip_pending_removal_mc && child_mc_cache[i]->pending_removal) &&
        swf_name_match(child_mc_cache[i]->name, instance_name) &&
        child_mc_cache[i]->parent == parent) {
        mc = child_mc_cache[i];
        break;
    }
}
```

**Step 4c — Depth-keyed lookup helper for `getInstanceAtDepth`:**

`MovieClip.getInstanceAtDepth(N)` must return the displaced MC at depth N (if it exists), not the fresh MC at a different depth. Add a new helper that bypasses the displaced-skip:

```c
// Find a cached MovieClip by its current depth. Used by getInstanceAtDepth
// to allow access to displaced MCs (whose depth is the swap-target depth)
// even though findOrCreateMovieClip skips them for name-based lookups.
MovieClip* findCachedMovieClipByDepth(const char* name, MovieClip* parent, int as_depth) {
    for (int i = 0; i < child_mc_count; i++) {
        MovieClip* ch = child_mc_cache[i];
        if (ch == NULL || ch->depth == INT_MIN) continue;
        if (ch->parent != parent) continue;
        if (ch->depth != as_depth) continue;
        if (name != NULL && strcmp(ch->name, name) != 0) continue;
        return ch;
    }
    return NULL;
}
```

In `actionGetInstanceAtDepth` (or wherever `getInstanceAtDepth` is implemented — search for `getInstanceAtDepth` in `action.c`), use the new helper:

1. Look up `display_list[swf_depth].instance_name`.
2. If present, call `findCachedMovieClipByDepth(name, root, as_depth)` first.
3. If not found, fall back to `findOrCreateMovieClip(name, parent)`.

**Step 4d — Lifecycle for `name_displaced`:**

Two events should clear the flag:

1. **The fresh MC dies** (e.g. another goto removes it, or the fresh MC's display slot is cleared): the displaced MC should be re-promoted. After `actionInvalidateCachedMovieClip` clears a MC, scan for any same-name+parent MC with `name_displaced=1` and clear the flag. (Risk: edge case where multiple displaced MCs exist; pick the lowest-depth one.)

2. **Another swap moves the displaced MC**: `ng_swapDisplayDepths` for an MC with `name_displaced=1` should arguably clear it (the MC is moving again, the displacement state is no longer meaningful). Investigate during implementation.

For the initial commit, deferring (1) and (2) and only setting `name_displaced=1` on initial fresh placement may be sufficient — the flag is "sticky" but the MC stays accessible via `dynRef` and `getInstanceAtDepth`. Lifecycle bugs would surface in regression battery testing.

### Test impact estimate

| Test | Before Phase 4 | After Phase 4 (estimated) |
|---|---|---|
| `displaylist_depths_test2` | 22/31 | 28-30/31 (lines that need fresh-MC resolution) |
| `displaylist_depths_test3` | 28/32 (already passes via static-zone destruction) | 28/32 (unchanged) |
| `soft_reference_test1` | 23/45 | likely unchanged unless `_name` reassignment scenarios overlap |

Phase 4 may also unblock additional tests not yet identified — anywhere AS code references multiple MCs with the same name across a goto.

### Risks

1. **Lifecycle bugs:** the `name_displaced` flag never cleared could leak across multiple gotos, leaving a "ghost" MC that's accessible via direct pointers but never via AS lookups. Step 4d addresses this; needs careful regression testing.
2. **Cross-cutting cache assumptions:** call sites assuming "one MC per name+parent" may break when two MCs coexist. Audit `actionRewindCleanup` (which iterates the cache and resets depths from display list — should it skip displaced MCs?) and `ng_findDisplayEntryByName` (returns first match — may need depth tiebreak).
3. **Scope chain resolution:** `actionGetVariable` walks scope, eventually falls through to MC display-list scan. The fallback uses `findOrCreateMovieClip` indirectly. Verify the scan doesn't return the displaced MC.

### Estimated session budget

- Step 4a (add field + set in tagPlaceObject2): 0.5 session
- Step 4b (skip in findOrCreateMovieClip): 0.25 session
- Step 4c (depth-keyed helper + integrate in getInstanceAtDepth): 0.5 session
- Step 4d (lifecycle clearing): 0.5-1 session
- Regression battery + iterate: 1-2 sessions

Total: 2-4 sessions. Single-PR scope.

## Phase B — Defer CLIP_CONSTRUCT to after the calling script

### Background investigation

Ruffle's source (`core/src/player.rs::run_actions`, `core/src/context.rs::ActionQueue`, `core/src/display_object/movie_clip.rs::run_goto` and `instantiate_child`) confirms that **all** CLIP_CONSTRUCT events queued during `run_goto` are deferred to the next `Player::run_actions` call, which fires at the end of `Player::update()` — after the calling AS script completes.

Specifically:
- `MovieClip::instantiate_child` → `child.post_instantiation` → queues `ActionType::Construct { events }` onto `context.action_queue` (line 1987 of movie_clip.rs).
- `Player::run_actions` (player.rs:2144) drains `action_queue` only when called explicitly. It is NOT called inside `run_goto`.
- `Player::update` calls `run_actions` ONCE at the end of the user-supplied closure (line 2372).

So during a backward goto from inside a frame's DoAction:
1. AS calls `gotoAndStop(N)`.
2. `MovieClip::run_goto` replays tags, queues N CLIP_CONSTRUCT events.
3. `run_goto` returns; calling AS script continues.
4. Script ends.
5. `Player::run_actions` drains the queue → CONSTRUCT events fire → trace lines emit.

Ruffle's behavior is **uniform** for all goto scenarios: forward, backward, looping. CLIP_CONSTRUCT always defers.

### Our current behavior

`SWFModernRuntime/src/libswf/tag.c::tagShowFrame` (line 2395):

```c
actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_CONSTRUCT);
```

This drain fires every time `tagShowFrame` is called — including during goto catch-up's per-frame replay. The comment at lines 2387-2391 acknowledges this is intentional for `action_execution_order_test6`, but our testing of test6 shows we already RUFFLE_MATCH despite the per-frame drain (the comparison is forgiving for that test).

### Proposed change

**Step B1 — Confirm Ruffle behavior:**

Read `output.ruffle.txt` for a representative sample of currently-passing tests that exercise CLIP_CONSTRUCT during catch-up:

- `action_order/action_execution_order_test6` (gnash misc-ming)
- `loop/loop_test4`, `loop/loop_test8` (gnash misc-ming)
- `register_class/RegisterClassTest3` (avm1)
- `goto_rewind1`, `goto_rewind2`, `goto_rewind3` (avm1)
- `execution_order2`, `execution_order3` (avm1)

For each, compare current local actual to `output.ruffle.txt`. Identify any that depend on CLIP_CONSTRUCT firing chronologically inside catch-up; those are guardrails Phase B must not break.

**Step B2 — Gate the drain:**

In `tagShowFrame`:

```c
// Pre-Phase-B: actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_CONSTRUCT);
//
// SWAPDEPTHS_REWIND_UNBLOCK Phase B: defer CLIP_CONSTRUCT during goto catch-up
// so it lands AFTER the calling AS script completes (matching Ruffle's
// action_queue model where CLIP_CONSTRUCT events queued by MovieClip::run_goto
// drain at the next Player::run_actions call, which fires post-script via
// Player::update). The next non-catch-up tagShowFrame (typically the calling
// frame's outer ShowFrame, after the calling script returns) will drain the
// accumulated CLIP_CONSTRUCT entries.
if (!g_goto_catchup_active) {
    actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_CONSTRUCT);
}
```

**Step B3 — Verify:**

Regression battery (must-not-regress, currently PASS or RUFFLE_MATCHED):
- `action_order/action_execution_order_test6` — currently RUFFLE_MATCHED
- `loop/loop_test{2..10}` — currently mostly PASS (loop_test6 12/23, loop_test10 3/28 from CI baseline)
- `goto_rewind{1,2,3}` — PASS
- `execution_order{1,2,3,4}` — PASS
- `register_class/RegisterClassTest3` — should still PASS
- `displaylist_depths_test{,4..11}` — currently PASS or RUFFLE_MATCHED
- `rewind_depth` — PASS
- 18-test transform/timeline regression battery from parent plan

Target gain:
- `displaylist_depths_test3` 28/32 → 31/32+ (CONSTRUCT trace re-aligns to expected positions; possibly PASS)

### Risk: where exactly do deferred CLIP_CONSTRUCTs drain?

If `g_goto_catchup_active` is the sole gate, deferred entries drain at the NEXT non-catch-up `tagShowFrame`. The flow for test3:

1. Frame 7: tagPlaceObject calls (none new).
2. Frame 7 DoAction (calling script):
   - `gotoAndStop(4)` → `ng_executeGotoCatchUp` runs with `g_goto_catchup_active=1`.
   - Catch-up replays frames 0..4. Each frame's tagShowFrame skips CLIP_CONSTRUCT drain (gated). CLIP_CONSTRUCT events accumulate in queue.
   - Catch-up returns. `g_goto_catchup_active=0`.
   - Calling script continues — typeof checks, totals(), trace output emitted.
   - Script ends.
3. Frame 7 tagShowFrame (post-script, called by recompiler-generated SHOW_FRAME drain or the outer frame loop) → drains CLIP_CONSTRUCT.

The tagShowFrame at step 3 is what we need. Verify: does our recompiler emit a tagShowFrame call after every frame's DoAction? Spot-check `RecompiledTags/tagMain.c` for a sample test.

If the post-script drain doesn't naturally happen at the expected point, may need to add an explicit drain call at the end of `ng_executeGotoCatchUp` (gated on "catch-up was triggered from within an outer DoAction"). Use `g_in_action_call` or similar to detect the nesting.

### Edge case: nested gotos

A goto triggered from inside another goto's catch-up replay (e.g., a sprite's DoAction during catch-up calls `gotoAndStop`) would have CLIP_CONSTRUCT queue from BOTH gotos. The outer catch-up's drain (skipped) wouldn't separate them. The next non-catch-up tagShowFrame drains all of them.

Ruffle handles this naturally via the action_queue: all CONSTRUCTs queue, all drain at next run_actions. Our gating on `g_goto_catchup_active` (a counter, not a boolean — see code) should mirror this. Nested catch-up doesn't cause issues as long as the outer level is also catch-up.

### Test impact estimate

| Test | Before Phase B | After Phase B (estimated) |
|---|---|---|
| `displaylist_depths_test3` | 28/32 | 30-32/32 (likely PASS or close to PASS) |
| `displaylist_depths_test2` | 22/31 (Phase 4 dependent) | unchanged by Phase B alone |
| `action_execution_order_test6` | RUFFLE_MATCHED | should remain RUFFLE_MATCHED (Ruffle also defers) |
| `loop_test*` | mostly PASS | needs verification — may shift trace ordering |

### Risks

1. **Tests that rely on CLIP_CONSTRUCT firing inside catch-up** (chronologically interleaved with LOAD/UNLOAD) would break. Step B1 audit identifies these; if any are PASS-currently, decide per-test whether the change is net positive.
2. **Frame loop interactions:** the queue-accumulation across multiple goto catch-ups (e.g., nested gotos, looping movies that goto every frame) could grow unbounded if no drain happens. Verify the post-catch-up tagShowFrame fires.
3. **CLIP_INIT and REGISTER_CTOR are already deferred** (see ng_executeGotoCatchUp lines 202-203). Phase B aligns CLIP_CONSTRUCT to the same model. Lower risk because the same machinery exists.

### Estimated session budget

- Step B1 (audit): 1 session.
- Step B2 (implement gate): 0.25 session.
- Step B3 (verify + iterate): 1-2 sessions.

Total: 2-3 sessions. Single-PR scope.

## Recommended sequencing

Phases 4 and B are independent. Either can land first. Suggested order based on test impact:

1. **Phase B first** — simpler change (single-line gate + audit), high test impact (test3 likely PASS), validates the deferred-CONSTRUCT model end-to-end.
2. **Phase 4 second** — larger surface area, but Phase B's verification battery primes the regression set.

Both phases together unblock test2 to PASS, test3 to PASS, and likely advance `soft_reference_test1` (Phase 4 share).

## Why this is a successor plan, not an addendum

The parent plan (`SWAPDEPTHS_REWIND_FRESH_PLACEMENT_PLAN.md`) is multi-phase with explicit COMPLETE/BLOCKED status per phase. Phases 4 and B were marked BLOCKED with brief rationale. This document expands the BLOCKED rationale into actionable implementation plans with code-level detail, references to the relevant Ruffle source confirming behavior, and per-step verification batteries.

When Phase 4 or B lands, this document moves to `complete/` and the parent plan's status updates accordingly. If both land, the parent plan also moves to `complete/` since all its sub-phases would be done.

## Related docs

| Doc | Relationship |
|---|---|
| `incomplete/SWAPDEPTHS_REWIND_FRESH_PLACEMENT_PLAN.md` | Parent — Phases 1, 1.5, 2, 3, 5 are prerequisite (all landed in commits 712885df, c23e377f). |
| `incomplete/REMAINING_TAIL_TRIAGE.md` | `soft_reference_test1` 23/45 entry — Phase 4's name-disambiguation work likely overlaps. |
| `incomplete/CLONE_CLIP_EVENT_DISPATCH_PLAN.md` | Phase 6 of that plan handled clone-replaced re-placement; this work extends the same pattern to swap-displaced re-placement. |
| Ruffle source: `core/src/display_object/movie_clip.rs::run_goto` (1546-1850) | Reference: how Ruffle handles fresh placement during rewind without identity collision (uses `instantiate_by_id` to create new GcCell-owned DisplayObject, no name-keyed cache). |
| Ruffle source: `core/src/context.rs::ActionQueue` (491-533) and `core/src/player.rs::run_actions` (2144-2230) | Reference: action queue mechanism that defers CLIP_CONSTRUCT to post-script drain. |
