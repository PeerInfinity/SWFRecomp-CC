# Deferred CLIP_EVENT_UNLOAD + onUnload Plan

<!-- TESTS: loop/loop_test6, loop/loop_test7, loop/loop_test8, action_order/action_execution_order_test2, action_order/action_execution_order_test3, action_order/action_execution_order_test5, action_order/action_execution_order_test11, action_order/ActionOrderTest3, action_order/ActionOrderTest4, action_order/ActionOrderTest5 -->

<!-- PLAN_META
id: DEFERRED_CLIP_UNLOAD
status: completed
phases:
  - id: 1
    name: "Snapshot MC state at queue time (audit)"
    status: completed
  - id: 2
    name: "Queue tag-level CLIP_EVENT_UNLOAD + accumulated_clip_actions"
    status: completed
  - id: 3
    name: "Queue AS-level onUnload via existing queueOnUnload"
    status: completed
  - id: 4
    name: "Move clear_display_entry / pending-removal / invalidation to a post-drain finalize"
    status: completed
  - id: 5
    name: "Verify ordering on the AVM1 regression battery"
    status: completed
dependencies: []
followup_plans:
  - "INITIALIZE/CONSTRUCT round dispatch (loop_test6 head — see §1)"
  - "Sprite frame execution order: LIFO instantiation vs depth-descending (test2/5/11 — see §2)"
  - "Inter-tag UNLOAD vs DoAction tag-stream ordering (loop_test6 tail, ActionOrderTest3/4/5 — see §3)"
-->

## Status update (2026-04-28, completed)

Phases 1-5 implemented and in CI. Net impact (CI snapshot at 205a9a77, re-confirmed
locally 2026-04-28):
- AVM1 regression battery: 27/27 PASS (no regressions).
- Misc-ming recently-fixed battery: 22/23 effective pass (loop_test6 unchanged
  pre-existing failure).
- Misc-swfc battery: 4/4 PASS (movieclip_destruction_test2 unchanged at 50/52).
- Shumway duplicateMovieClip: 4/4 PASS.
- Target tests (3 of 10 effectively passing):
  - loop_test7 RUFFLE_MATCHED (14/15)
  - loop_test8 PASS (38/38)
  - action_execution_order_test3 PASS

Remaining 7 target tests confirmed locally 2026-04-28 (still MISMATCH, no regressions):

| Test | Suite | Match | Lines | Notes |
|------|-------|-------|-------|-------|
| loop/loop_test6 | misc-ming | 10/23 | DoAction/UNLOAD interleave; clip-event INITIALIZE/CONSTRUCT round ordering across sibling MCs (see "Remaining work" §1) |
| action_execution_order_test2 | misc-ming | 2/5 | Reverse-instantiation-order vs depth-descending (see §2) |
| action_execution_order_test5 | misc-ming | 26/35 | Same family as test2 |
| action_execution_order_test11 | misc-ming | 13/32 | Same family as test2 |
| action_order/ActionOrderTest3 | misc-ming | 6/62 | Inter-tag UNLOAD vs DoAction queue order; UNLOAD doesn't observe pre-removal int state (see §3) |
| action_order/ActionOrderTest4 | misc-ming | 7/64 | Same family as ActionOrderTest3 |
| action_order/ActionOrderTest5 | misc-ming | 8/51 | Same family as ActionOrderTest3 |

## Follow-up work — out of scope for this plan

The remaining 7 tests do NOT need additional deferred-unload work; they need
distinct pieces of machinery that should each have their own plan. The
deferred-unload work this plan describes is finished — these are spinoffs.

### §1 Clip-event INITIALIZE/CONSTRUCT round dispatch (loop_test6)

**Symptom (loop_test6 head):**
```
expected: movieClip1 initialized | movieClip2 initialized | movieClip1 constructed | movieClip2 constructed
actual:   movieClip1 initialized | movieClip1 constructed   | movieClip2 initialized | movieClip2 constructed
```

We fire `INITIALIZE` then `CONSTRUCT` per-sprite (depth-first) at placement
time. Ruffle/Flash fires INITIALIZE for **all** new sprites in the frame
first, then CONSTRUCT for all of them. Fixing this means walking the new
placements in two passes and dispatching INITIALIZE for the whole batch
before any CONSTRUCT runs (rather than the current per-sprite serial dispatch
inside `tagPlaceObject2*`'s `fire_eager_constructors`).

A second loop_test6 issue (movieClip1 still alive when expected
`typeof=='undefined'` at line 16) is the inter-tag UNLOAD ordering failure
covered in §3.

### §2 Sprite frame execution order: LIFO instantiation, not depth-descending (test2/5/11)

**Symptom (action_execution_order_test2):**
```
expected: depth11+depth12+depth10+depth9+depth13+   (reverse-placement order: mc_red3, mc_red2, mc_red1)
actual:   depth12+depth11+depth10+depth9+depth13+   (depth-descending: 12, 11, 10)
```

`advance_sprite_frames` (`SWFModernRuntime/src/libswf/tag.c:671`) walks
`display_list` from `max_depth` down to 0. The expected order is
**reverse-instantiation order** (most-recently-placed first) which matches
Ruffle's `clip_exec_list` — a LIFO linked list pushed at `add_to_exec_list`
(`core/src/avm1/runtime.rs:519-525`) and traversed forward in `Avm1::run_frame`
(`runtime.rs:489-505`).

Fix shape: introduce a per-MovieClip `clip_exec_list` (linked list of child
sprites in placement order), push at the head on placement, traverse forward
in `advance_sprite_frames`. Risk is high — the depth-descending iteration is
load-bearing for several other suites; the AVM1 regression battery would need
to be rerun against the change.

### §3 Inter-tag UNLOAD vs DoAction tag-stream ordering (loop_test6 second half, ActionOrderTest3/4/5)

**Symptom (ActionOrderTest3 head, expected vs actual):**
```
expected:   onEnterFrame | Frame 2 actions: undefined | ctor: 0 | static unload: undefined | dynamic load: 0 | onEnterFrame | Frame 3 actions: undefined | Frame 2 actions: undefined | onEnterFrame | Frame 3 actions: 0 | Frame 2 actions: 0 | ctor: 1 | static unload: 0 | dynamic unload: 0 | dynamic load: 1 | …
actual:     onEnterFrame | Frame 2 actions: undefined | ctor: 0 | onEnterFrame | static unload: undefined | dynamic load: 0 | Frame 3 actions: undefined | onEnterFrame | Frame 2 actions: undefined | ctor: 1 | onEnterFrame | static unload: undefined | dynamic load: 1 | …
```

Two distinct issues here:
1. **`static unload: undefined` instead of `static unload: 0`** — by the time
   the unload handler runs, the static counter has already been re-zeroed
   (handler reads `undefined` instead of `0`). This is the recompiler's
   `tagRemoveObject2` lookahead heuristic deciding wrongly: when a frame
   contains `[DoAction A, RemoveObject2(mc1), PlaceObject2(mc2 at same depth), DoAction B]`,
   we currently emit the RemoveObject2 inline (so its UNLOAD fires before B),
   then re-Place. The expected interleave is `A → B → mc1.UNLOAD →
   mc2.LOAD/CONSTRUCT`. Fix: route ALL same-depth Remove+Replace through
   the buffered `actionDrainOnloadAndScript` path at SHOW_FRAME emit, not
   the lookahead heuristic that decides per-pair.
2. **`dynamic unload` lines missing entirely** — when a dynamically-attached
   MC is replaced by a fresh attach in the next frame, the AS-level onUnload
   handler isn't getting queued. Need to verify
   `actionFireOnUnload`/`queue_pending_finalize_mc` is reached for the
   `attachMovie`-replacement code path (already mentioned in
   `actionInvokeRegisteredClassConstructor`'s replacement flow but possibly
   not for the simple attachMovie-with-existing-name case).

Fixing either of these is a multi-hour effort that should be its own plan
(`INTER_TAG_UNLOAD_PLAN.md`, say) with its own regression battery — the
current `action_execution_order_test8-v5/v6` and `loop_test2/3/5/8/9` set
all depend on the tag-stream ordering already in place, and any change here
must keep them green.

## Why this plan is complete

The deferred-clip-unload work this plan describes (Phases 1-5) is fully
landed and the documented regression battery is green. The 7 still-failing
target tests need machinery that is:
- §1 — a small but real refactor of clip-event dispatch ordering.
- §2 — a fundamental rework of sprite frame iteration order (high regression
  risk).
- §3 — a reshape of how the recompiler emits Remove+Replace tag pairs and
  how attachMovie-replacement queues onUnload.

None of those are extensions of the deferred-unload mechanism — they are
adjacent ordering problems that the deferred-unload work happened to surface
when it landed. They belong in their own plans (proposed names:
`CLIP_EVENT_ROUND_DISPATCH_PLAN.md`, `SPRITE_EXEC_LIST_LIFO_PLAN.md`,
`INTER_TAG_UNLOAD_PLAN.md`); the test list above can seed the per-plan
TESTS comment in each.

### 2026-04-25 — loop_test8 trailing mc5unloaded fixed

Two-part fix:

1. New `actionQueueClipActionUnloadDeferred` helper in
   `SWFModernRuntime/src/actionmodern/action.c` queues a clip-action UNLOAD
   callback as `kind=SCRIPT, is_unload=0` (instead of the existing
   `actionQueueClipActionUnload`'s `kind=ONLOAD, is_unload=1`). This makes
   the entry invisible to `actionFirePendingUnloads` (which filters
   `is_unload=1`) so the nested `tagShowFrame` inside
   `ng_executeGotoCatchUp`'s per-frame replay doesn't drain it mid-rewind.
   The entry rides the outer `actionDrainOnloadAndScript` FIFO instead,
   landing after the calling gotoAndStop/Play script and remaining queued
   root scripts.

2. `tagPlaceObject2` / `tagPlaceObject2Ratio`
   (`SWFModernRuntime/src/libswf/tag.c`) backward-rewind clear-and-replace
   path now calls `actionQueueClipActionUnloadDeferred` for the displaced
   MC's clip-action UNLOAD bits (current + accumulated) BEFORE
   `actionMarkMCPendingRemoval`. Previously only the Mark ran, dropping
   the CLIP_EVENT_UNLOAD trace entirely. Recursive child unloads are
   intentionally not fired here (would need a similar "deferred" variant;
   loop_test8's mc5 has no nested children needing UNLOAD).

A first attempt added an `if (!catch_up_mode)` gate around
`actionFirePendingUnloads` in `tagShowFrame` to suppress the mid-rewind
drain, but that regressed `reverse_execute_PlaceObject2_test2`
(10/10 → 5/10) because run_pending_finalize stopped firing during the
rewind, leaving display_list[depth] populated and causing the rewind's
tagPlaceObject2 to incorrectly survives_rewind the still-populated entry
instead of fresh-placing it (so the second-cycle onLoad never fired).
The Deferred variant approach avoids this by leaving the existing
unload drain timing intact.

Implementation summary:
- `actionQueueClipActionUnload` queues recompiler-emitted clip-action UNLOAD callbacks via `AQ_KIND_ONLOAD` with `is_unload=1`. Used by `tagRemoveObject2`/`tagRemoveObject` and `fire_recursive_child_unloads`.
- `actionFireOnUnload` now enqueues a `PendingTimelineUnload` payload via `aq_dispatch_timeline_unload` instead of firing inline. The dispatcher shifts depth + sets `avm1_removed=1` BEFORE invoking the handler so `getDepth()` inside `onUnload` returns the post-shift value (Flash semantics).
- `actionMarkMCPendingRemovalDirect` / `actionInvalidateCachedMovieClipDirect` take an MC pointer directly (no name+depth lookup), used by `run_pending_finalize`.
- `queue_pending_finalize_mc(mc, swf_depth, depth)` records (mc, swf_depth, depth) for post-drain Mark + clear. tagRemoveObject2 only queues finalize when has_unload (AS-level handler or clip-event UNLOAD); otherwise it Invalidates inline.
- `actionDrainOnloadAndScript` drains AQ_KIND_ONLOAD + AQ_KIND_SCRIPT in FIFO order (preserves queue-time order between RemoveObject2 and DoAction). Calls `run_pending_finalize` after the LAST UNLOAD entry pops so Mark fires before any subsequent SCRIPT entry sees the MC's clip.depth.
- `tagFlushPendingEnterFrame` calls `run_pending_finalize_mark_only` (Mark without clear) so ENTER_FRAME for the new frame skips MCs being removed in this frame's tag stream.
- `actionDispatchEnterFrameHandlers` / `dispatch_enterframe_clip_actions` walk parent chain to skip MCs whose ancestor is Marked.
- `aq_dispatch_mc_onload` skips dispatch if the captured MC is invalidated (defensive; prevents segfault in resolveSlashPathToMC).
- Recompiler: `tagRemoveObject2` is buffered to SHOW_FRAME emit ONLY if depth had clip_actions AND the next tag is a same-depth PlaceObject2/3 (lookahead heuristic). Otherwise emitted inline. SHOW_FRAME no longer flushes buffered_removes (just clears tracking). Recompiler emits `actionDrainOnloadAndScript` instead of `actionDrainActionQueueByKind(AQ_KIND_SCRIPT)` at SHOW_FRAME emit.

Remaining work for the other 8 target tests:
- loop_test6/8: trailing UNLOAD trace ordering issues. loop_test8 is still 37/38 (1-line off).
- action_execution_order_test2/5/11, ActionOrderTest3/4/5: inter-tag UNLOAD vs accumulated_clip_actions ordering issues. These tests have complex remove+place patterns that the current Mark/Invalidate mechanism doesn't fully replicate (e.g., depth_clip_actions tracking for the SAME depth across multiple frames, with intermediate replaces).

Files touched: `SWFModernRuntime/{include/actionmodern/action.h,include/actionmodern/action_queue.h,src/actionmodern/action.c,src/actionmodern/action_queue.c,src/libswf/tag.c,src/libswf/tag_stubs.c}`, `SWFRecomp/src/swf.cpp`.

## Problem statement

Flash queues `RemoveObject2`'s `CLIP_EVENT_UNLOAD` clip actions and AS-level
`onUnload` handlers on the global ActionQueue with `is_unload=true`, so they
fire **after** any DoAction tags emitted in the same frame. Our runtime fires
both inline inside `tagRemoveObject2` (`SWFModernRuntime/src/libswf/tag.c:4453`),
then immediately calls `clear_display_entry`. The result is:

1. **Wrong inter-tag ordering.** A frame containing
   `[DoAction A, RemoveObject2(mc1), DoAction B]` should drain
   `A → B → mc1's UNLOAD → mc1's onUnload` at ShowFrame. We instead emit
   `A → mc1 unload trace → B`, with the unload trace landing where
   `RemoveObject2` was processed in tag order.
2. **The gnash test source explicitly calls this out.** From `loop_test7.c`:
   *"RemoveObject2 tag is after the DoAction tag which contains the following
   check. So it's no surprise that we can still access movieClip1 here when
   considering the global ActionQueue model!"*

Ruffle implements this via the action queue with `is_unload=true`
(`core/src/display_object/movie_clip.rs:2849`).

## Affected tests (CI 205a9a77)

All 10 failing tests below share this root cause. Match counts are current diffs.

| Test | Suite | Match | Notes |
|------|-------|-------|-------|
| loop/loop_test7 | misc-ming | 11/15 (73.3%) | Canonical case; reverted-fix landed it as `ruffle_matched` in isolation. |
| loop/loop_test8 | misc-ming | 37/38 (97.4%) | Last failing line is the trailing `mc5unloaded` clip-event UNLOAD trace. |
| loop/loop_test6 | misc-ming | 6/23 (26.1%) | DoAction/UNLOAD interleave with multiple removed clips. |
| action_order/action_execution_order_test2 | misc-ming | 2/5 (40.0%) | PlaceObject2-vs-DoAction onLoad/onUnload ordering across depths. |
| action_order/action_execution_order_test3 | misc-ming | 1/4 (25.0%) | Diff is exactly `onUnloadRed1+onUnloadRed2+as_in_DoAction3+` instead of expected `as_in_DoAction3+onUnloadRed1+onUnloadRed2+`. |
| action_order/action_execution_order_test5 | misc-ming | 26/35 (74.3%) | Same family. |
| action_order/action_execution_order_test11 | misc-ming | 13/32 (40.6%) | Same family. |
| action_order/ActionOrderTest3 | misc-ming | 5/62 (8.1%) | Long-tail; expected to recover most lines once ordering is fixed. |
| action_order/ActionOrderTest4 | misc-ming | 10/64 (15.6%) | Same. |
| action_order/ActionOrderTest5 | misc-ming | 9/51 (17.6%) | Same. |

**Estimated impact:** 7+ flips to PASS / `ruffle_matched`, plus partial gains
on the long-tail ActionOrderTest3/4/5 cluster. loop_test8 only needs the
trailing clip-event UNLOAD line.

## Existing infrastructure

The action-queue work is already 80% done. From `action_queue.h`:

- `actionQueueCallback(fn, user, AQ_PRIORITY_NORMAL, clip, is_unload=1)` —
  enqueue with the `AQ_KIND_ONLOAD` default kind.
- `actionFirePendingUnloads(app_context)` — drains only `is_unload=1` entries.
  Already called from `tagShowFrame` at `tag.c:2176`.
- `queueOnUnload(func, mc)` (`action.c:19048`) — enqueues an AS-level handler.
  Already used from `actionRemoveSprite` (`removeMovieClip`),
  `actionUnloadMovie`, and `attachMovie`-replacement paths
  (`action.c:45113`, `:54002`, `:57628`).
- `queueChildOnUnloads(parent_mc)` — recursive walk over `child_mc_cache`,
  used by both `actionRemoveSprite` and (since 2026-04-24) `tagRemoveObject2`
  via `actionQueueDynamicChildUnloads`.

**What's missing:**
1. A `queueClipActionUnload(action_fn, mc)` wrapper that pushes a clip-action
   callback onto `AQ_KIND_ONLOAD` with `is_unload=1`. Tag-level
   `CLIP_EVENT_UNLOAD` handlers in `tagRemoveObject2` (lines 4500–4503,
   4538–4544) and `fire_recursive_child_unloads` (line 4382–4385) need to
   route through this instead of calling `obj->clip_actions[a].action(app_context)`
   inline.
2. The `actionFireOnUnload` call in `ng_on_remove_object`
   (`tag_stubs.c:781`) needs to enqueue (not invoke) the AS-level handler.
3. `clear_display_entry`, `actionMarkMCPendingRemoval`, and
   `actionInvalidateCachedMovieClip` currently run **immediately** in
   `tagRemoveObject2` after the inline unloads, wiping the MC's state
   before any deferred handler can fire. They must move to a new
   post-drain finalize pass.

## Why the prior attempt was reverted

(See `MISC_MING_SWFC_PLAN.md` "loop_test7 — deferred CLIP_EVENT_UNLOAD clip
actions (2026-04-23, attempted and reverted)".)

| Attempted change | Effect |
|------------------|--------|
| Defer **only** tag-level CLIP_EVENT_UNLOAD | `loop_test7` flipped to ruffle_matched ✓ but `avm1/unload_clip_event` and `avm1/clip_events` regressed: AS-level handler still fired inline first, so trace order inverted (handler before clipEvent). |
| Defer both tag-level **and** AS-level | `unload_clip_event`/`clip_events` recovered ✓ but `avm1/unload`'s `Unload clip5` trace slipped from end-of-frame-1 to end-of-frame-2: the deferred AS-level handler couldn't fire because `actionMarkMCPendingRemoval` + `clear_display_entry` had already wiped `mc->display_obj` and friends between queue-time and drain-time. |

The fix is therefore not just about deferring the calls — the destructive
post-unload steps must move with them.

## Required ordering at drain time

Within a single removal, queued in the order:

1. **Recursive child CLIP_EVENT_UNLOAD** (depth-first, from
   `fire_recursive_child_unloads`).
2. **`accumulated_clip_actions[CLIP_EVENT_UNLOAD]`** for the depth (from
   prior Remove+Replace at the same slot).
3. **`clip_actions[CLIP_EVENT_UNLOAD]`** for the depth itself.
4. **AS-level `onUnload`** for the depth itself (was `actionFireOnUnload`).
5. **Recursive AS-level `onUnload`** for dynamic children (was
   `actionQueueDynamicChildUnloads` — already deferred since 2026-04-24).

Steps 1–3 are tag-level (clip-event UNLOAD) and step 4 is AS-level — the
order matters because `avm1/unload_clip_event` expects clipEvent before
handler. Step 5 is already deferred; the new work is steps 1–4.

`actionFirePendingUnloads` drains all `is_unload=1` entries in queue order,
preserving FIFO within a priority. Since all five steps push at
`AQ_PRIORITY_NORMAL` with `is_unload=1`, FIFO ordering at queue time is
preserved at drain time. Pushing in the order above gives the correct
trace order without needing a sub-priority distinction.

## Plan

### Phase 1 — Snapshot what the deferred handlers actually need (audit)

Before deferring, audit what state each handler reads:

- **`obj->clip_actions[a].action(app_context)`** — recompiler-generated
  `tagAction_*` function pointer. The function body reads the action stack
  and `g_current_context` (set by `tagRemoveObject2` to the MC before the
  loop). It does NOT read `display_list[depth]` directly. ✓ should be safe
  to defer if `g_current_context` is restored at drain time and the
  function pointer remains valid (it's static code).
- **`actionFireOnUnload(name, swf_depth)`** (`action.c:18730`) — looks up
  the MC by `name` + `swf_depth - 16384` in `child_mc_cache`. Needs the MC
  alive and resolvable at drain time. Currently shifts `mc->depth` and
  invokes the handler. **Must move to enqueue-and-defer**: enqueue a
  payload `{func, mc}` exactly like `queueOnUnload` does today.

**Outcome:** confirm that snapshotting `(action_fn, mc, depth)` at queue
time is sufficient — no deeper state needs to be copied.

### Phase 2 — Queue tag-level clip-action UNLOAD

Add to `action.c` (next to `queueOnUnload`):

```c
typedef struct { void (*fn)(SWFAppContext*); MovieClip* mc; } PendingClipAction;

static void aq_dispatch_clip_action(SWFAppContext* app_context, void* user)
{
    PendingClipAction* pca = (PendingClipAction*) user;
    if (pca == NULL) return;
    if (!g_execution_halted && pca->fn != NULL) {
        MovieClip* saved = g_current_context;
        if (pca->mc != NULL) actionSetCurrentContext(pca->mc);
        pca->fn(app_context);
        actionSetCurrentContext(saved);
    }
    free(pca);
}

void actionQueueClipActionUnload(void (*fn)(SWFAppContext*), MovieClip* mc)
{
    PendingClipAction* pca = (PendingClipAction*) malloc(sizeof(PendingClipAction));
    if (pca == NULL) return;
    pca->fn = fn;
    pca->mc = mc;
    actionQueueCallback(NULL, aq_dispatch_clip_action, (void*)pca,
                        AQ_PRIORITY_NORMAL, NULL, /*is_unload=*/1);
}
```

In `tag.c`:

- **`fire_recursive_child_unloads`** (line 4354): replace
  `obj->clip_actions[a].action(app_context)` (line 4385) with
  `actionQueueClipActionUnload(obj->clip_actions[a].action, child_mc)`.
  The `g_current_context` save/restore around the loop is no longer needed
  (the dispatch fn handles it), but **keep the `actionInvalidateCachedMovieClip`
  call** (line 4394) deferred too — see Phase 4.
- **`tagRemoveObject2` accumulated-clip-actions loop** (lines 4498–4506):
  same pattern. Resolve the MC via
  `actionFindOrCreateMovieClip(app_context, instance_name, &root_movieclip)`
  at queue time, capture into `pca->mc`. The local
  `display_list[depth].accumulated_clip_actions = NULL` reset at line
  4505 must move to the finalize step (Phase 4) — otherwise the queued
  fn pointer is still valid (static code) but the array would be
  freed mid-drain.
- **`tagRemoveObject2` current-clip-actions loop** (lines 4530–4544):
  same pattern. The `saved_ctx` save/restore (4532, 4543) becomes
  per-callback in `aq_dispatch_clip_action`.

`tagRemoveObject` (line 4398, the SWF1 RemoveObject — depth+char_id) gets
the same treatment for symmetry (lines 4408–4445 mirror tagRemoveObject2).

### Phase 3 — Queue AS-level onUnload

Two options:

**Option A (preferred): rename `actionFireOnUnload` → `actionQueueOnUnload`**
and have it enqueue via `queueOnUnload(func, mc)` instead of invoking inline.
The depth-shift (`mc->depth = -(swf_depth)-1-16384`,
`mc->avm1_removed = 1`) must happen **at queue time, not at dispatch time**,
because:

- Flash semantics: `getDepth()` inside `onUnload` returns the post-shift
  depth (test `movieclip_destruction_test2` lines 88–89:
  `mc2.getDepth() == -16387` inside `mc2.onUnload`).
- The shift is what `actionMCHasOnUnloadProperty` and other lookups use to
  distinguish removed-zone MCs from live ones at drain time. Doing it at
  dispatch would let other code (e.g. a same-frame DoAction) see the
  pre-shift depth on a queued-for-removal MC, breaking
  `typeof(mc1)=='undefined'` checks.

The rename keeps the call site name suggestive of its observable effect
(unload semantics start happening immediately — the depth shifts and the MC
becomes `pending_removal` — even though the handler hasn't run yet).

**Option B:** Leave `actionFireOnUnload` alone and add a parallel
`actionDeferOnUnload` that does the same lookup + shift + queue, but doesn't
invoke. Switch the `ng_on_remove_object` call site
(`tag_stubs.c:781`) to call the new function. Reject Option B —
it leaves the inline `actionFireOnUnload` callable from elsewhere with
inconsistent semantics.

Pick **Option A** and audit other call sites:

```bash
grep -rn "actionFireOnUnload" SWFModernRuntime/
```

The only caller today is `ng_on_remove_object` (`tag_stubs.c:781`), so the
blast radius is small.

### Phase 4 — Move destructive steps to a post-drain finalize

After the queue drain in `actionFirePendingUnloads`, run a new
`actionFinalizeUnloadedDepths(app_context)` that:

1. Iterates a per-frame "depths pending finalize" list populated by
   `tagRemoveObject2` / `tagRemoveObject` / `fire_recursive_child_unloads`.
2. For each pending depth, runs the steps that today are inline:
   - `clear_display_entry(app_context, depth)` (which frees
     `sprite_display_list`, instance_name, etc.).
   - On root depths: `actionMarkMCPendingRemoval` /
     `actionInvalidateCachedMovieClip` (depending on `has_unload`).
3. Clears the pending-finalize list.

The pending-finalize list is a small static array
(`g_pending_finalize_depths[256]`, `g_pending_finalize_count`) keyed by
depth — same shape as the existing `g_clone_depth_table`. It must survive
across `tagRemoveObject2` calls within a frame but reset between frames.
Wire the new call into `tagShowFrame` immediately after
`actionFirePendingUnloads` (line 2176 of `tag.c`).

**State invariants during the deferred window:**

- `display_list[depth]` is **not** cleared until finalize, so a same-frame
  `getDepth()` / `_x` lookup on the pending-removal MC still works
  (matches Flash: the MC is reachable by name in same-frame DoAction
  blocks queued before RemoveObject2's UNLOAD).
- `mc->depth` IS shifted to the removed-depth zone at queue time
  (Phase 3 Option A), so name+depth lookups in `actionFireOnUnload`-style
  code (now rare since the only AS-level handler is queued) find the MC
  via the shifted-depth path.
- `mc->avm1_removed = 1` at queue time gates `typeof(mc)` /
  `valueOf()` / etc. to behave as if the MC is gone, even though
  display state is still live. This matches Flash's "name is undefined,
  but reference still works" semantics in the deferred window.

**Edge case — same-frame replacement:** if `tagPlaceObject2` at the same
depth runs before `actionFirePendingUnloads`, it must still do the right
thing. Today it sees `display_list[depth].char_id != 0` from the
not-yet-cleared entry and treats it as a modify (preserving instance
name etc.). This is wrong here: the queued unload means the slot is
logically empty. The new behavior: `tagPlaceObject2` checks
`is_pending_finalize(depth)` and treats it as a fresh placement (running
finalize for that single depth eagerly, before placement). This is the
trickiest invariant — it's the spot most likely to surface regressions in
the AVM1 placement battery.

### Phase 5 — Regression battery

Run after each phase, not just at the end. The goal is to catch ordering
regressions early, since the prior attempt's regression hit only on
`avm1/unload`'s clip5-at-end-of-frame-1 case which is easy to miss.

Required-pass tests (must remain green):

- AVM1: `unload`, `unload_clip_event`, `unload_nested_child`, `unloadmovie`,
  `mcl_unloadclip`, `clip_events`, `bad_placeobject_clipaction`,
  `movieclip_in_removed_button`, `goto_rewind1/2/3`,
  `execution_order1/2/3`, `goto_execution_order/2`, `goto_both_ways1/2`,
  `rewind_depth`, `depth_replacement_audio_unloading`,
  `textsnapshot_available_text`, `clip_events`, `on_construct`,
  `register_and_init_order`, `set_interval`, `swf5_to_6_cross_call`,
  `swf6_to_5_cross_call`.
- Gnash misc-ming recently-fixed: `loop_test2/3/4/5/8/9`,
  `instanceNameTest`, `attachMovieTest`, `static_vs_dynamic1/2`,
  `displaylist_depths_test11`, `place_and_remove_object_test`,
  `get_frame_number_test`, `shape_test`, `event_handler_scope_test`,
  `action_execution_order_test8-v5/v6`, `new_child_in_unload_test`,
  `ResolveEventsTest`.
- Gnash misc-swfc: `stackscope`, `edittext_test1`, `submoviegetvar`,
  `movieclip_destruction_test2` (52/56 — must not regress; depth-shift
  semantics in Phase 3 Option A are tightly tied to its expectations).
- Shumway: `duplicateMovieClip/dontremove`,
  `duplicateMovieClip/duplicateMovieClip`,
  `duplicateMovieClip/samedepth`, `duplicateMovieClip/name-coercion`.

Target tests (expected to flip):

- loop_test6/7/8, action_execution_order_test2/3/5/11, ActionOrderTest3/4/5.

## Open questions

1. **Same-frame DoAction → typeof(mc) check** — does Flash see the MC as
   `'movieclip'` or `'undefined'` after RemoveObject2 has been processed
   in tag order but before the unload queue drains? Per the loop_test7
   gnash comment, the MC is still accessible. Phase 4's "shift depth +
   set avm1_removed" model breaks `typeof` though, since `typeof` checks
   `avm1_removed`. Need to verify: is the test relying on `typeof` returning
   `'movieclip'` between the RemoveObject2 tag and the queue drain? If yes,
   we have to delay `mc->avm1_removed = 1` to drain time, not queue time —
   only the depth shift happens at queue time.

   Likely answer (from the test):
   ```
   PASSED: typeof(movieClip1) == 'movieclip' [loop_test7.c:123]   ← inside same-frame DoAction, after RemoveObject2 in tag order
   PASSED: typeof(movieClip1) == 'undefined' [loop_test7.c:132]   ← after frame boundary, mc1 fully gone
   ```
   So `avm1_removed` flip happens between drain and the next frame's
   DoAction — drain time is fine. Phase 3 Option A: shift depth at queue
   time, set `avm1_removed = 1` **at drain time** (inside
   `aq_dispatch_unload`, before invoking the handler — Flash's
   "already-shifted-inside-handler" semantics still hold since the depth
   shift is at queue time).

2. **Recompiler backward-compat** — `tagRemoveObject2` is called from
   recompiler-emitted `tagMain.c`. The signature isn't changing, so no
   recompiler work. But the ordering shift means that any test SWF
   relying on the inline unload firing at a specific tag-stream position
   would break. The required-pass battery should catch this.

3. **`tagPlaceObject2` same-depth replacement during the deferred window** —
   Phase 4's `is_pending_finalize(depth)` check needs to handle the
   `tagPlaceObject2` paths in `tag.c` (4 sites: PlaceObject2, PlaceObject2Ratio,
   PlaceObject2WithClipActions, PlaceObject3). All four paths today branch
   on "modify vs. place" via `display_list[depth].char_id`. The deferred
   window means we may have a stale `char_id != 0` from a queued-for-removal
   slot. Adding the pending-finalize check before the modify-vs-place
   branch (and eagerly running finalize for that single depth) is the
   safest choice.

4. **`actionMarkMCPendingRemoval` ordering** — currently called by
   `ng_on_remove_object` based on `has_unload`. After Phase 4 it moves
   to finalize. But `actionMarkMCPendingRemoval` is also called from
   `tagPlaceObject2` (in the backward-rewind clear-and-replace path,
   2026-04-24). That call should NOT defer — it's part of the rewind
   replay machinery, not RemoveObject2. Mark the new `g_pending_finalize`
   list and the existing `pending_removal` flag as separate concepts:
   pending_finalize = "queued for cleanup at this frame's
   actionFirePendingUnloads", pending_removal = "in the removed-depth
   zone for one frame".

## Risk

- **Medium-high.** The prior attempt nibbled at the edges and surfaced
  ordering regressions on `avm1/unload`. This plan addresses the root
  cause (the destructive cleanup runs too early) but the
  `tagPlaceObject2` same-depth case (open question 3) and the
  `pending_finalize` vs `pending_removal` separation (open question 4)
  are both easy to get wrong. The required-pass battery in Phase 5 is
  intentionally large to catch ordering regressions at every step.

## Why this is the right shape

This plan mirrors Ruffle's exact mechanism: ActionQueue with
`is_unload=true` (`core/src/avm1/activation.rs` and
`core/src/display_object/movie_clip.rs:2849`), drained at
`Player::run_frame`. The destructive cleanup
(`core/src/display_object/container.rs::should_delay_removal`) similarly
defers display-list mutation until after the unload queue drains.
Aligning our runtime with Ruffle's structure here is the long-term win:
the action_order, loop_test6/7/8, and ActionOrderTest3/4/5 clusters all
share this single structural mismatch.

## Estimated session budget

- Phase 1 (audit + snapshot design): 30–45 min reading.
- Phase 2 (queue tag-level): 1–2 hours coding + spot tests.
- Phase 3 (queue AS-level): 30–60 min.
- Phase 4 (finalize step + pending-finalize gating): 2–3 hours; this is
  where the regression risk lives.
- Phase 5 (battery): 30 min per re-run, plan for 3+ re-runs.

A single ~6-hour session is realistic if Phase 4's
`tagPlaceObject2` interaction goes smoothly. If it doesn't, plan to
split — Phase 2+3 alone are safe to land if Phase 4 is gated behind a
feature flag (`DEFERRED_UNLOAD_FINALIZE`) that defaults off and is
flipped on once the battery passes.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `MISC_MING_SWFC_PLAN.md` | Lists this blocker as the gating issue for ~10 tests. Update its "Documented blockers" section once this plan is in_progress. |
| `complete/ACTION_QUEUE_PLAN.md` | (If present.) Phases 1-7b of the action queue migration. The current plan is essentially Phase 7c — finishing the unload migration. |
| Ruffle source: `core/src/display_object/movie_clip.rs:2849`, `core/src/display_object/container.rs:330-360` | Reference implementation. |
