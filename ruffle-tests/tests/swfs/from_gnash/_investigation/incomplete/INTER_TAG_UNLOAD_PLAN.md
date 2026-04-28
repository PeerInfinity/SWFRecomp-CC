# Inter-Tag UNLOAD Ordering Plan (sprite-internal Remove+Replace, sprite loop-back)

<!-- TESTS: action_order/ActionOrderTest3, action_order/ActionOrderTest4, action_order/ActionOrderTest5, loop/loop_test6 -->

<!-- PLAN_META
id: INTER_TAG_UNLOAD
status: pending
phases:
  - id: 1
    name: "Buffer sprite-level RemoveObject2 (recompiler symmetry)"
    status: pending
  - id: 2
    name: "Fire UNLOAD on sprite loop-back display-list clear"
    status: pending
  - id: 3
    name: "Audit `this`/`this.c` access in deferred clip-action UNLOAD"
    status: pending
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

## Problem statement

The DEFERRED_CLIP_UNLOAD plan landed deferred firing of `RemoveObject2`'s
clip-event UNLOAD and AS-level `onUnload` handlers — but only for
**root-level** removals. Three structural gaps remain for **sprite-internal**
removals and looping:

1. **Recompiler emits sprite-level `tagRemoveObject2` inline**, even when
   followed by a same-depth `PlaceObject2` (the buffering+lookahead heuristic
   runs only at root level). Same-frame `[Remove(d), Place(d)]` patterns
   inside a sprite frame fire UNLOAD at tag-stream position rather than
   end-of-frame.
2. **Sprite loop-back silently clears the display list** without firing
   UNLOAD events. When a sprite advances from its last frame back to frame 0,
   `advance_sprite_frames` (`tag.c:870-883`) frees `sprite_display_list`
   entries inline.
3. **AS-level `this.c` inside a clip-action UNLOAD reads `undefined`** when
   the value should still be the pre-removal property. Either the `this`
   binding doesn't resolve to the (still-alive) pending-removal MC, or
   property access is gated by `avm1_removed=1` somewhere in the resolution
   chain. Ruffle reads the pre-removal value; our code reads `undefined`.
4. **AS-level `onUnload` set by a registered-class constructor doesn't fire**
   when the MC is replaced by a sprite-internal Remove+Place. The
   replacement code path skips queueing the dynamic handler.

## Affected tests (CI 91a39c2c)

| Test | Suite | Match | Lines | Notes |
|------|-------|-------|-------|-------|
| action_order/ActionOrderTest3 | misc-ming | 6/62 | All four root causes hit. Diff shows missing `static unload: 0`/`dynamic unload: 0` and `this.c==undefined` for the static UNLOAD lines. |
| action_order/ActionOrderTest4 | misc-ming | 7/64 | Same family as ActionOrderTest3. |
| action_order/ActionOrderTest5 | misc-ming | 8/51 | Same family as ActionOrderTest3. |
| loop/loop_test6 | misc-ming | 10/23 | Tail (lines 12-23) requires this plan. Head needs `CLIP_EVENT_ROUND_DISPATCH_PLAN`. |

The three `ActionOrderTest*` cases share a single test pattern: a 2-frame
sprite that places a different child at the same depth in each frame
(`mc3.frame_0: place(d=1, char=mc2)`, `mc3.frame_1: remove(d=1); place(d=1,
char=mc1)`). Looping the sprite across N main-timeline ticks produces an
N-iteration sequence of Remove+Place events. Every iteration boundary is a
case of one of the four issues above, so the line count delta should be
substantial — ActionOrderTest3 alone is +56 lines if all four issues land.

## Existing infrastructure

DEFERRED_CLIP_UNLOAD landed:
- `actionQueueClipActionUnload` / `actionQueueClipActionUnloadDeferred`
  (queues clip-event UNLOAD callbacks at `AQ_KIND_ONLOAD` /
  `AQ_KIND_SCRIPT` respectively).
- `actionFireOnUnload` (queues AS-level `onUnload` via
  `aq_dispatch_timeline_unload`).
- `actionMarkMCPendingRemoval` / `actionFinalizePendingRemovals`
  (depth-shift + post-drain finalize).
- `aq_dispatch_timeline_unload` shifts depth and sets `avm1_removed=1`
  BEFORE invoking the handler (Flash semantics for `getDepth()` inside
  `onUnload`).
- Recompiler buffering at `swf.cpp:3939-3979` (root-level
  `SWF_TAG_REMOVE_OBJECT_2` only).

What's missing:
- Symmetric buffering at sprite level (`swf.cpp:5008-5019` —
  `SWF_TAG_REMOVE_OBJECT_2` inside a sprite, currently emits inline).
- A "loop-back unload" hook in `advance_sprite_frames` to route the
  display-list clear through the same deferred-UNLOAD machinery.
- Verification of property access semantics on a `pending_removal`
  / `avm1_removed=1` MC.
- Dynamic-onUnload queueing in the sprite-internal Remove+Place path.

## Plan

### Phase 1 — Buffer sprite-level RemoveObject2 (recompiler symmetry)

Mirror the root-level lookahead at `SWFRecomp/src/swf.cpp:3953-3977` into
the sprite-level branch at `SWFRecomp/src/swf.cpp:5008-5019`.

Pseudocode (existing root logic, applied to sprite emission):
```cpp
case SWF_TAG_REMOVE_OBJECT_2:
{
    sub_tag.parseFields(cur_pos);
    u16 depth = (u16) sub_tag.fields[0].value;
    bool should_buffer = false;
    if (sprite_depth_clip_actions.count(depth)) {  // NEW: per-sprite tracker
        // peek next sub-tag, check for same-depth PlaceObject2/3
        ...
        if (next_depth == depth) should_buffer = true;
    }
    if (should_buffer) {
        sprite_buffered_removes.insert(depth);  // NEW: per-sprite tracker
    } else {
        sprite_definitions << "\t" << "tagRemoveObject2(...)" << endl;
    }
    break;
}
```

Two new per-sprite trackers:
- `sprite_depth_clip_actions` — set of depths in this sprite that have ever
  carried clip_actions (mirrors root's `depth_clip_actions`).
- `sprite_buffered_removes` — depths whose `RemoveObject2` was buffered in
  this sprite frame (mirrors root's `buffered_removes`).

Reset both at sprite-frame boundary. Flush `sprite_buffered_removes` (emit
`tagRemoveObject2` per depth) at sprite SHOW_FRAME just like root does at
`swf.cpp:944-949`.

The existing `tagReplaceObject2RatioWithClipActions` machinery already
handles the buffered case at runtime — it's just never reached for
sprite-internal removes today.

**Risk:** Tests that depend on the inline-emit behavior at sprite level
might shift. Run the full action_order battery first.

### Phase 2 — Fire UNLOAD on sprite loop-back display-list clear

`advance_sprite_frames` (`SWFModernRuntime/src/libswf/tag.c:870-883`) clears
the sprite's display list silently when looping back to frame 0:
```c
if (frame == 0 && max_depth > 0)
{
    for (size_t j = 1; j <= max_depth; ++j)
    {
        if (display_list[j].sprite_display_list != NULL)
            FREE(display_list[j].sprite_display_list);
        display_list[j].char_id = 0;
    }
    max_depth = 0;
}
```

Replace with a deferred-UNLOAD path. For each non-empty depth:
1. If the entry has clip_actions with `CLIP_EVENT_UNLOAD`: call
   `actionQueueClipActionUnloadDeferred` (the version that rides the
   outer drain, not `actionQueueClipActionUnload` which fires inline).
2. If the entry's MC has an AS-level `onUnload` property: call
   `actionFireOnUnload` (queues `PendingTimelineUnload`).
3. Mark the depth for finalize via `actionMarkMCPendingRemoval` (the
   shifted-depth zone) so subsequent `display_list[d].char_id = 0` is
   safe.
4. Clear `char_id`/`sprite_display_list` etc. as before.

This mirrors Ruffle's `MovieClip::run_goto`'s `survives_rewind=false`
path (`core/src/display_object/movie_clip.rs:1685-1694`). When a sprite
loops, it's effectively a backward goto from frame N back to frame 0;
children at depths not re-placed by frame_0's tag stream are removed
with full UNLOAD lifecycle.

Subtlety: the loop-back happens INSIDE `advance_sprite_frames`, with
`display_list` swapped to the sprite's internal list. The deferred-UNLOAD
helpers walk `child_mc_cache` for AS-level lookup — verify that lookup
works when the parent's display_list is swapped. Likely safe since
`child_mc_cache` is parent-relative, but spot-check with
`movieclip_destruction_test2` (50/52 — must remain green).

### Phase 3 — Audit `this`/`this.c` access in deferred clip-action UNLOAD

Symptom: ActionOrderTest3 expects `'static unload: 0'` (mc1.c was set to 0
by the registerClass ctor); we emit `'static unload: undefined'`.

The clip-action UNLOAD handler is a recompiler-emitted `frame_func`
(`clip_action_5` in the loop_test6 example). Inside this handler:
`_global.ch('static unload: ' + this.c)`. The `this.c` operand resolves
through:
1. `g_current_context` set by `aq_dispatch_clip_action`
   (`tag.c:3596-3605`).
2. The bytecode's `this` reference — which path resolves it depends on
   the SWF version and `actionPushSpecial(THIS)` opcode emission.

Two hypotheses to verify:
- **(a) `this` resolves to the wrong MC.** `aq_dispatch_clip_action` sets
  `g_current_context = pu->mc`, but `this` in pushed-via-special-opcode
  semantics may resolve differently. If the dispatch sets
  `g_event_this_mc` instead of (or in addition to) `g_current_context`,
  the bytecode's `THIS` push could land the right object.
  Reference: `actionDispatchEnterFrameHandlers` sets BOTH
  `g_current_context` and `g_event_this_mc` (`action.c:27392-27394`)
  before invoking — the clip-action UNLOAD dispatcher does not.

- **(b) `dynamic_props` is cleared between queue and dispatch.**
  `aq_dispatch_timeline_unload` sets `avm1_removed=1` BEFORE the handler;
  if `getMember` checks `avm1_removed` and short-circuits to `undefined`,
  property access fails. The post-drain finalize in
  `actionFirePendingUnloads` runs `run_pending_finalize` AFTER the drain
  (good), so dynamic_props should still be live during dispatch.

  But the `aq_dispatch_clip_action` (separate dispatcher for clip-event
  handlers — different from `aq_dispatch_timeline_unload`) does NOT set
  `avm1_removed=1` before invocation. So this hypothesis is less likely
  for the clip-action UNLOAD specifically. Still worth verifying.

Phase 3 work:
1. Add `g_event_this_mc = pu->mc` in `aq_dispatch_clip_action` (mirroring
   `actionDispatchEnterFrameHandlers`).
2. Verify that `getMember` does NOT gate on `mc->avm1_removed` for
   `dynamic_props` lookups in the AS-level fall-through. `grep -n
   'avm1_removed' SWFModernRuntime/src/actionmodern/action.c` → confirm
   no early-`undefined` returns inside `actionGetMember`.
3. If both pass and `'static unload: 0'` still doesn't appear, write a
   minimal repro test (mc with `c=0` set, deferred-UNLOAD handler reads
   `this.c`) under `SWFRecomp/tests/` to isolate.

### Phase 4 — Queue dynamic onUnload for sprite-internal replacements

ActionOrderTest3 expects `'dynamic unload: 0'` (the AS-level `onUnload`
set by Bug ctor on `this`). Our trace shows it missing entirely.

The flow:
1. `mc3.frame_1` runs `tagRemoveObject2(d=1)` — should call
   `actionFireOnUnload(name="Segments", swf_depth=...)`.
2. `actionFireOnUnload` looks up the MC in `child_mc_cache` by
   `name+as_depth`, then reads `mc->dynamic_props['onUnload']`, then
   queues a `PendingTimelineUnload`.

The likely failure point: `child_mc_cache` lookup. mc1 was placed inside
mc3 at depth 1, with name `"Segments"`. The MC was registered in the
cache with `parent=mc3`. When `actionFireOnUnload` runs, it does:
```c
for (int i = 0; i < child_mc_count; i++) {
    if (child_mc_cache[i] != NULL &&
        ... &&
        child_mc_cache[i]->depth == as_depth &&
        strcmp(child_mc_cache[i]->name, instance_name) == 0)
```

Two issues:
- Depth check: the lookup uses `as_depth = swf_depth - 16384`, but
  sprite-internal placements use depth values that may not be in
  the root's `[16384, ...]` range. Verify `swf_depth` passed in.
- Name collision: there might be another MC named "Segments" elsewhere
  in `child_mc_cache` that shadows the lookup. Add a `parent` filter to
  match the right one.

Phase 4 work:
1. Verify `actionFireOnUnload`'s call site in `tagRemoveObject2` /
   `ng_on_remove_object` passes the correct `swf_depth` for sprite-internal
   placements.
2. Add `parent_mc` filter to the `child_mc_cache` scan in
   `actionFireOnUnload` (require `mc->parent == g_current_context` or
   the caller's parent).
3. If still missing: walk `mc->dynamic_props` chain to find `onUnload`
   (it might be set on `__proto__` via `Bug.prototype.onUnload`, not
   directly on the instance).

   Actually the test sets `this.onUnload` inside the ctor body, so it's
   on the instance's `dynamic_props`. ✓

### Phase 5 — Regression battery

After each phase, not just the end.

**Required-pass tests (must remain green):**

AVM1:
- `unload`, `unload_clip_event`, `unload_nested_child`, `unloadmovie`,
  `mcl_unloadclip` — full unload battery.
- `goto_rewind1/2/3`, `execution_order1/2/3`,
  `goto_execution_order/2`, `goto_both_ways1/2`, `rewind_depth`,
  `depth_replacement_audio_unloading`, `clip_events`,
  `bad_placeobject_clipaction`, `movieclip_in_removed_button`,
  `on_construct`, `register_and_init_order`, `set_interval`.
- `reverse_execute_PlaceObject2_test1/2` (parallel risk — these test
  re-place behavior).

Gnash misc-ming recently-fixed:
- `loop_test2/3/4/5/8/9` (multi-iteration sprite tests — Phase 2's
  loop-back UNLOAD will exercise these heavily).
- `instanceNameTest`, `attachMovieTest`,
  `static_vs_dynamic1/2`, `displaylist_depths_test11`,
  `place_and_remove_object_test`, `event_handler_scope_test`,
  `ResolveEventsTest`, `new_child_in_unload_test`,
  `action_execution_order_test8-v5/v6`.

Gnash misc-swfc:
- `stackscope`, `edittext_test1`, `submoviegetvar`,
  `movieclip_destruction_test2` (50/52 — must not regress).

Shumway:
- `duplicateMovieClip/dontremove`,
  `duplicateMovieClip/duplicateMovieClip`,
  `duplicateMovieClip/samedepth`,
  `duplicateMovieClip/name-coercion`.

**Target tests (expected to gain lines or flip):**
- `loop_test6` (10/23 → ~22/23 after Phase 1+2; full PASS needs Phase 3+4
  for the `_root.mc1Constructed` count and combined with
  `CLIP_EVENT_ROUND_DISPATCH_PLAN` for the head).
- `ActionOrderTest3` (6/62 → ~50/62, full pass after Phase 1-4).
- `ActionOrderTest4` (7/64 → ~52/64).
- `ActionOrderTest5` (8/51 → ~40/51).

**Net expected delta:** +3 PASS in misc-ming (full ActionOrderTest3/4/5)
plus partial loop_test6 progress; combined with CLIP_EVENT_ROUND_DISPATCH
and SPRITE_EXEC_LIST_LIFO, the §1/§2/§3 trio could land 4 full PASS flips
on the DEFERRED_CLIP_UNLOAD tail.

## Open questions

1. **Phase 2 — sprite advance ordering.** With `SPRITE_EXEC_LIST_LIFO_PLAN`
   pending, the sprite loop-back UNLOAD events fire in some order. Which?
   Reverse-instantiation order (LIFO) matches Ruffle and is the same
   ordering SPRITE_EXEC_LIST_LIFO would impose. Either land
   SPRITE_EXEC_LIST_LIFO first, or use it as a forcing function — choose
   based on which test battery tolerates the intermediate state better.

2. **Phase 1 — `tagReplaceObject2RatioWithClipActions` robustness.**
   When sprite-level `Remove+Place` is buffered, the runtime calls
   `tagReplaceObject2RatioWithClipActions` to accumulate the old
   clip_actions onto the new placement. This function currently runs
   only at root level (1 call site at `swf.cpp:3732`). Verify it works
   when `display_list` is swapped to a sprite's internal list — the
   accumulated_clip_actions storage is per-DisplayObject so should be
   safe, but the actionFire* helpers may walk the wrong cache.

3. **Phase 3 — `this` binding in clip-event vs AS-level handlers.** Are
   they bound the same way in Ruffle? Reference: Ruffle's
   `core/src/display_object/movie_clip.rs::run_clip_event` sets
   `Activation::this` to the clip — uniformly for all clip events. Our
   `aq_dispatch_clip_action` only sets `g_current_context`, not
   `g_event_this_mc`. `aq_dispatch_timeline_unload` (AS-level) similarly
   only sets `g_current_context`. If both should set `g_event_this_mc`,
   Phase 3 fixes both paths.

4. **Phase 4 — `_root.mc.Segments` evaluation timing.** The
   `'Frame N actions: ' + mc.Segments.c` trace reads `mc.Segments.c`
   AT trace time. After mc3 advances and replaces Segments=mc2 → mc1,
   what does `mc.Segments` resolve to? Display list (current
   placement) → mc1, dynamic_props (might still hold reference to
   old mc2)? Verify the `getMember(mc3, "Segments")` path returns
   the live display-list child, not a stale dynamic_props entry.

5. **DoInitAction relative ordering.** ActionOrderTest3's frame 1 has
   `[DoInitAction(4), DoInitAction(1), DoAction]`. Ruffle drains
   DoInitActions BEFORE the frame's DoAction at Normal priority FIFO,
   which our `actionDrainOnloadAndScript` should also do (queue order
   is FIFO within priority). Verify by reading the recompiled output:
   `actionQueueScript(s_doInit_4); actionQueueScript(s_doInit_1);
   actionQueueScript(s_3_doAction);` — drains in that order. ✓
   should be correct.

## Risk

- **Medium-high.** Phase 1 (recompiler symmetry) is mechanical but
  changes tag-stream ordering for all sprites with same-depth
  Remove+Place patterns — broad impact. Run a pre-merge check on the
  AVM1 lifecycle battery first.
- Phase 2 (loop-back UNLOAD) is high-risk for `loop_test*` family —
  these tests already pass and rely on the silent clear behavior.
  Need to verify Ruffle's exact loop-back semantics: does it fire
  UNLOAD only when survives_rewind=false, or for every loop-back
  regardless? Ruffle's behavior is `run_goto`-based, which checks
  `survives_rewind` per-depth. Our display-list clear is not
  survives_rewind-aware — so a naive Phase 2 would over-fire UNLOAD
  for depths that ARE re-placed by frame_0's tag stream.
- Phase 3+4 are scoped to specific dispatch sites — lower risk.

## Why this is the right shape

This plan finishes the DEFERRED_CLIP_UNLOAD work for the cases that
landed at root-level only. The four phases each address one concrete
divergence from Ruffle:
- Phase 1: tag-stream ordering symmetry.
- Phase 2: loop-back UNLOAD parity with `survives_rewind` model.
- Phase 3: `this` binding parity in clip-event handlers.
- Phase 4: dynamic-onUnload queueing parity for replacement paths.

Each phase has a clear test signal in the ActionOrderTest3/4/5 diffs;
the regression risk is bounded by the `loop_test*` and
`reverse_execute_PlaceObject2_test*` batteries which already covered the
root-level work. The §1/§2 plans in this DEFERRED_CLIP_UNLOAD trio are
independent, so this plan can land before, after, or alongside them.

## Estimated session budget

- Phase 1 (recompiler buffering symmetry): 1-2 hours including spot
  tests against ActionOrderTest3.
- Phase 2 (loop-back UNLOAD): 2-3 hours — the `survives_rewind`
  parity check is tricky to get right without regressing
  `loop_test2/3/5/8/9`.
- Phase 3 (clip-event `this` audit): 1 hour.
- Phase 4 (dynamic-onUnload queueing): 1-2 hours including a name
  collision repro under `SWFRecomp/tests/`.
- Phase 5 (battery): 30 min per re-run, plan for 3 re-runs.

A single 6-8 hour session is realistic for Phases 1+2+3, with Phase 4 as
a follow-up if time runs out.

## Related plans

| Doc | Relationship |
|-----|--------------|
| `complete/DEFERRED_CLIP_UNLOAD_PLAN.md` | Parent plan; §3 of its "Follow-up work" section. This plan covers that §3. |
| `incomplete/CLIP_EVENT_ROUND_DISPATCH_PLAN.md` | Sibling — same parent. Independent. loop_test6's full PASS needs both this plan and CLIP_EVENT_ROUND_DISPATCH. |
| `incomplete/SPRITE_EXEC_LIST_LIFO_PLAN.md` | Sibling — same parent. Phase 2's loop-back UNLOAD ordering interacts with sprite advance ordering — see Open Question 1. |
| Ruffle source: `core/src/display_object/movie_clip.rs::run_goto` (1685-1694, survives_rewind), `run_clip_event` (set this binding). | Reference implementation. |
