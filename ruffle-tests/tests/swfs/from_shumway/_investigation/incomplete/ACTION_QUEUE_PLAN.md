# ActionQueue Rework — Cross-Suite Architectural Plan
<!-- TESTS: trace-as2/root_onload, avm1/doactionorder/doactionorder, avm1/stage_object_enumerate, timeline/timeline_as2_1, timeline/timeline_as2_5 -->

This is an architectural plan, not a per-test plan. Implementing it would unblock
multiple individual test plans across all four suites and unify ~10 ad-hoc
deferral mechanisms into one queue. Last updated 2026-04-19.

## Status

- **Phase 0 — landed 2026-04-19** — `SWFModernRuntime/include/actionmodern/action_queue.h`
  + `SWFModernRuntime/src/actionmodern/action_queue.c` provide the queue API
  (`actionQueueCallback`, `actionDrainActionQueue`, `actionResetActionQueue`,
  `actionActionQueuePending`) with priority + FIFO + `is_unload` gating. No
  callsites yet. Wired into `CMakeLists.txt` and the two source lists in
  `ruffle-tests/verify_output.py` (native + emcc paths). Canary run locally
  (14 tests including all execution_order[1-4], clip_events,
  register_and_init_order, stage_object_enumerate, goto_rewind3): 14/14 PASS.
- **Phases 1–9** — not started.

The Phase 0 API intentionally provides only the generic `actionQueueCallback`
kind. The typed wrappers sketched in §Data structure (queueScript,
queueClipEvent, queueMethod, queueConstructor) will be added as each
migration phase needs them — avoids unused-dispatch code churning before
it has a caller.

## Why this matters

Several blocked/incomplete plans share a single root cause: our runtime fires AVM1
event handlers and DoAction scripts **synchronously** at the moment they're
encountered, while Flash and Ruffle drain them from a **3-priority FIFO queue**
after a whole frame's tags have been processed. Without that queue, event
ordering is locked to tag-iteration order, and we cannot make
`Initialize > Construct > Normal` always hold while also making
`DoAction-A → PlaceObject(sprite) → DoAction-B` produce the
A → sprite-script → B order Flash and Ruffle do.

Plans currently blocked or partially blocked on this:

| Plan | Tests blocked / improved by ActionQueue |
|------|----------------------------------------|
| `from_gnash/blocked/ROOT_ONLOAD_PLAN.md` | `trace-as2/root_onload` (50% → 100% or `ruffle_matched`) |
| `from_shumway/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` Part A | `avm1/doactionorder/doactionorder` (3/7 → 7/7 expected) |
| `from_shumway/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md` | `timeline/timeline_as2_1`, `timeline/timeline_as2_5` |
| `from_gnash/blocked/MISC_MING_SWFC_PLAN.md` (deferred-DoAction subset) | `action_execution_order_test8-v5/v6`, `ActionOrderTest3/4`, similar |
| `from_gnash/blocked/MISC_SWFMILL_PLAN.md` | `dict_event` (interleaved DoAction/PlaceObject) |
| `avm1/RUFFLE_VS_FLASH_DIFFERENCES.md` (stage_object_enumerate entry) | `stage_object_enumerate` (would flip to passing) |

Estimated total impact: roughly 5–10 newly passing or `ruffle_matched`-promoted
tests, plus simplification of ~10 ad-hoc deferral queues.

## Ruffle's model in one paragraph

`ActionQueue` (`~/CC/ruffle/core/src/context.rs:488–540`) is three `VecDeque`s
indexed by priority: `Initialize=2`, `Construct=1`, everything else (`Normal`,
`Method`, `NotifyListeners`) `=0`. `pop_action` iterates priorities highest-first
and pops FIFO from each. `Player::run_actions`
(`~/CC/ruffle/core/src/player.rs:2144`) drains the queue completely, **once per
trigger** (frame tick, input event, context-menu selection, audio callback).
Inside `MovieClip::run_frame_internal`
(`~/CC/ruffle/core/src/display_object/movie_clip.rs:1282`) the tag stream is
walked: `do_action` (`:4117`) calls `queue_action(Normal)` and never executes;
`place_object` calls `instantiate_child` (`:1410`) which synchronously calls
`post_instantiation` → `queue_action(Initialize)` + `queue_action(Construct)`,
then `enter_frame` (queues `Load` as `Normal`), then `run_frame_avm1` which
recursively walks the placed child's frame_0 tags (queueing more actions). After
all clips have queued their actions for the tick, `run_actions` drains in
priority + FIFO order. Per-action `is_unload` flag (default `false`) skips the
action if the clip was removed before drain — except for unload events
themselves, which run despite removal.

Subtle but important: gotos do **not** queue a tick. `run_goto` (`:1546`)
processes PlaceObjects inline (which queue actions via `instantiate_child`) but
does not call `run_actions`. Gotos invoked mid-script just add to the same queue
the outer drain is already iterating.

## Our model today

Synchronous firing sites ((file, callsite, what fires) — the rework would
replace each with a queue insert):

### PlaceObject2 path (`SWFModernRuntime/src/libswf/tag.c`)

| Line | Fires | Notes |
|------|-------|-------|
| 3391–3392 | `CLIP_EVENT_INITIALIZE` handlers | clip_actions on the placed sprite |
| 3420 | `sprite_frame_funcs[0]` (Phase 1, `catch_up_mode=1`) | Recursively places nested children, scripts gated off |
| 3452–3453 | `CLIP_EVENT_CONSTRUCT` handlers + `fire_deferred_construct` recursion | Fires after Phase 1 |
| 3490 | `actionInvokeRegisteredClassConstructor` | RegisterClass ctor, before DoAction |
| Lines 3667 / 3727 / 3729 | Same triple — `tagPlaceObject2Ratio` parallel path | |

### Sprite Phase 2 (`tag.c:256–489`, `process_sprite_init_at_depth`)

| Line | Fires | Notes |
|------|-------|-------|
| 350–362 | `CLIP_EVENT_LOAD` handlers | Before sprite frame_0 scripts |
| 386 / 391 | `sprite_frame_funcs[0]` Phase 2 (`g_script_only_mode=1`) | Re-runs frame_0 with placements as no-ops |
| 407 | Recursive `process_sprite_needs_init` for children | Drives the deepest-first ordering question root_onload exposes |
| 432–433 | `actionInvokeRegisteredClassConstructor` (legacy attachMovie path) | |
| 437–438 | `actionQueueMCOnLoad` (AS-level `onLoad`) | Already queues into `g_pending_onloads` |

### ShowFrame / EnterFrame (`tag.c`)

| Line | Fires | Notes |
|------|-------|-------|
| 2077 | `process_sprite_needs_init(root)` (Phase 2 driver) | The current "drain point" for sprite scripts |
| 1576–1577 | `dispatch_enterframe_clip_actions` (CLIP_EVENT_ENTER_FRAME) | Per-frame; gated on `sprite_initialized >= 2` |
| 2493 | `actionDispatchRootOnLoad` | Once after first frame |

### Recompiler-emitted DoAction calls (`SWFRecomp/src/swf.cpp`)

The recompiler currently buffers `script_N(app_context)` calls and emits them as
a batch at `END_TAG` / `SHOW_FRAME` (lines 548–556, 807–815, 861–868). Sprite
DoActions are buffered into `sprite_frame_scripts` and emitted after all
placements (lines 4078–4081, 4117). This batching is the proximate cause of the
"DoAction-A before PlaceObject before DoAction-B" reordering bug.

### Removal / Unload (`tag.c:3854+`)

`ng_removeMovieClip` synchronously fires `CLIP_EVENT_UNLOAD` and recurses
depth-first. AS-level `onUnload` is already queued via `g_pending_unloads` →
`actionFirePendingUnloads` (`action.c:18646–18687`). Mixed model today.

## Existing deferral queues (candidates for unification)

A unified ActionQueue could subsume most of these:

| Queue | Defined | Currently consumed at | Replaceable by ActionQueue? |
|-------|---------|----------------------|-----------------------------|
| `g_pending_attach_inits` | `tag_stubs.c:162` | `tag.c:2084` | Yes — Normal priority |
| `g_pending_loads` | `tag_stubs.c:488` | `tag.c:2081` | Yes — Normal priority |
| `g_pending_onloads` | `action.c:26680` | `tag.c:2090` (`actionFlushPendingOnLoads`) | Yes — Normal priority |
| `g_pending_unloads` | `action.c:18646` | `tag.c:2055` (`actionFirePendingUnloads`) | Yes — Normal priority, `is_unload=true` |
| `g_deferred_unload_mcs` | `action.c:18400` | `swf_core.c:792` (top-of-tick) | Probably keep (cleanup, not script) |
| `g_deferred_failed_loads` | `action.c:18434` | `swf_core.c:1052` | Yes — Normal priority |
| `g_pending_direct_loads` | `action.c:18481` | `swf_core.c:1059` | Yes — Normal priority |
| `g_pending_mcl_loads` | `action.c:25493` | `tag.c:2093` (`actionFirePendingLoadInits`) | Partly — see SHUMWAY Part B |
| `g_deferred_roll_queue` | `action.c:26941` | `action.c:57933` | Yes — Normal priority |
| `g_deferred_goto_queue[16]` | `swf_core.c:73` | `swf_core.c:1005` | **Keep** — gotos are special; queue interaction needs care |
| `g_defer_sprite_init` | `tag.c:123` | `tag.c:2065` | Yes — flag becomes implicit when scripts are queued |

`MAX_DEFERRED_GOTO_QUEUE=16` is a known fragility (silent overflow) — a unified
queue with dynamic growth would fix it as a side effect.

## Proposed architecture (Approach A3)

This builds directly on the Approach A3 sketch in
`from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` (lines
327–367), refined with the synchronous-site map above.

### Data structure

```c
typedef enum {
    AQ_PRIORITY_NORMAL    = 0,
    AQ_PRIORITY_CONSTRUCT = 1,
    AQ_PRIORITY_INITIALIZE = 2,
    AQ_PRIORITY_COUNT      = 3,
} ActionQueuePriority;

typedef enum {
    AQ_KIND_SCRIPT,           // generated script_N function
    AQ_KIND_CLIP_EVENT,       // clip_action handler bound to a MC
    AQ_KIND_METHOD,           // AS object method (e.g. mc.onEnterFrame)
    AQ_KIND_CONSTRUCTOR,      // registered class ctor + setup
    AQ_KIND_CALLBACK,         // generic C callback (for builtin paths)
} ActionQueueKind;

typedef struct {
    ActionQueueKind kind;
    ActionQueuePriority priority;
    MovieClip* clip;          // for is_unload check; NULL if not bound
    int is_unload;            // run even if clip removed
    union {
        struct { void (*fn)(SWFAppContext*); }                       script;
        struct { ClipAction action; MovieClip* this_mc; }            clip_event;
        struct { ASObject* obj; const char* name; ActionVar args[8]; size_t nargs; } method;
        struct { const char* export_name; MovieClip* mc; }           ctor;
        struct { void (*fn)(SWFAppContext*, void*); void* user; }    callback;
    } u;
} ActionQueueEntry;
```

A single dynamic-growth array (`actionq[]`, `actionq_count`, `actionq_cap`) is
simplest; pop scans for highest priority. For tens-of-entries scale this is
fine. If profiling shows it matters, three separate ring buffers indexed by
priority work.

### API (new file `SWFModernRuntime/src/actionmodern/action_queue.c`)

```c
void actionQueueScript(SWFAppContext*, void (*fn)(SWFAppContext*));
void actionQueueClipEvent(SWFAppContext*, MovieClip* mc, const ClipAction* ca,
                          ActionQueuePriority pri, int is_unload);
void actionQueueMethod(SWFAppContext*, ASObject* obj, const char* name,
                       const ActionVar* args, size_t nargs, int is_unload);
void actionQueueConstructor(SWFAppContext*, const char* export_name, MovieClip*);
void actionQueueCallback(SWFAppContext*, void (*fn)(SWFAppContext*, void*), void* user);

void actionDrainActionQueue(SWFAppContext*);   // pop until empty
void actionResetActionQueue(SWFAppContext*);   // discard all (for catch-up etc.)
size_t actionActionQueuePending(void);         // for loop-exit conditions
```

Drain loop pattern matches Ruffle: scan for highest-priority non-empty bucket,
pop front, dispatch, repeat. Re-queues during dispatch are picked up by the
next iteration.

### Recompiler changes (`SWFRecomp/src/swf.cpp`)

1. `SWF_TAG_DO_ACTION` (line 2527, root): emit
   `if (!catch_up_mode || g_tag_skip_mode) actionQueueScript(app_context, script_<N>);`
   inline at the tag's position.
2. `SWF_TAG_DO_ACTION` inside `SWF_TAG_DEFINE_SPRITE` (line 4914, sprite):
   emit `if (!catch_up_mode) actionQueueScript(app_context, script_<N>);`
   inline. Drop the `sprite_frame_scripts` deferral.
3. `SWF_TAG_SHOW_FRAME` (line 850, root): emit
   `actionDrainActionQueue(app_context);` before `tagShowFrame`.
4. `SWF_TAG_END_TAG` (line 805, root): emit `actionDrainActionQueue` before
   the existing footer.
5. Inside sprite frames at `SWF_TAG_SHOW_FRAME` / `SWF_TAG_END_TAG`: NOT here.
   The drain happens at the outermost frame boundary, not inside nested sprite
   frames — recursive PlaceObject calls are part of building the queue, not
   draining it.
6. Remove the three flush loops (lines 548–556, 807–815, 861–868). Keep
   `non_timeline_scripts` for its existing tracking purpose.

### Runtime changes

**`tag.c:tagPlaceObject2`** (and `tagPlaceObject2Ratio`, `tagPlaceObject3`):
- Replace synchronous INITIALIZE firing (3391–3392) with
  `actionQueueClipEvent(..., AQ_PRIORITY_INITIALIZE, false)`.
- Replace synchronous CONSTRUCT firing (3452–3453) with
  `actionQueueClipEvent(..., AQ_PRIORITY_CONSTRUCT, false)`. Recurse for
  nested children at queue time, not drain time.
- Replace synchronous registered class ctor (3490) with
  `actionQueueConstructor(...)` at `AQ_PRIORITY_CONSTRUCT` (matches Ruffle's
  `ActionType::Construct { constructor, events }` bundling).
- Phase 1 frame_0 invocation (3420) stays — it's the "place children eagerly"
  step that builds the queue depth-first via recursive PlaceObject.

**`tag.c:process_sprite_init_at_depth`** (Phase 2):
- The Phase 2 frame_0 re-run (386/391) goes away. Sprite frame DoActions are
  queued by the recompiler-emitted `actionQueueScript` calls during Phase 1
  (which now run regardless of `catch_up_mode` because the queue itself gates
  drain).

  Wait — Phase 1 runs with `catch_up_mode=1` and the recompiler-emitted
  `actionQueueScript` is gated `if (!catch_up_mode)`. So Phase 1 doesn't queue.
  We need a different gate. Two options:
    (a) Set a separate `g_in_phase1_eager_init` flag, gate sprite scripts on
        that being false; Phase 1 stays in `catch_up_mode=1` for placement
        suppression but scripts queue.
    (b) Drop `catch_up_mode=1` in Phase 1; scripts queue inline; tag handlers
        remain idempotent under multiple replays via existing `place_gen`
        tracking.
  Option (a) is safer (smaller delta). Option (b) is closer to Ruffle but needs
  audit of every tag handler for re-entry safety.
- LOAD events (350–362) → `actionQueueClipEvent(..., AQ_PRIORITY_NORMAL, false)`.
- registered class ctor (432–433) → `actionQueueConstructor(...)`.
- `actionQueueMCOnLoad` (437–438) — already queues, leave alone or migrate
  to unified queue.
- `sprite_initialized = 1` and the recursive `process_sprite_needs_init`
  (407) stay as-is — they're bookkeeping, not script firing.

**`tag.c:tagShowFrame`**:
- Final `actionDrainActionQueue` after all per-frame bookkeeping. Most existing
  `g_pending_*` flushes (loads, attach inits, onLoads, onUnloads, etc.) get
  migrated to queue inserts so the unified drain handles them.

**`swf_core.c` frame loop**:
- Keep the goto deferred queue (`g_deferred_goto_queue`). Goto-target frame
  scripts get queued via the same `actionQueueScript` mechanism inside the
  3-phase deferred-goto loop. The 3-phase loop still drives ordering (Phase 1
  before-target inits → Phase 2 target script → Phase 3 at/after-target inits)
  but each "phase" now ends with a `actionDrainActionQueue`.

### Goto interaction (the hard part)

`catch_up_mode=1` paths today suppress script execution. Under A3, we want
intermediate-frame scripts *not* to queue at all. Concretely:

- Recompiler emits `if (!catch_up_mode || g_tag_skip_mode) actionQueueScript(...)`.
  During catch-up replay (`catch_up_mode=1`, `g_tag_skip_mode=0`), no queueing.
- Target-frame script-only replay (`g_tag_skip_mode=1`, `catch_up_mode=0`):
  `actionQueueScript` runs; tag handlers no-op via the existing `g_tag_skip_mode`
  early-return. Drain happens after the script-only replay.
- Phase 1 eager-init inside `tagPlaceObject2` during `catch_up_mode=1`: the
  child's recursive frame_0 also runs in `catch_up_mode=1`. We want its DoActions
  to queue *for the parent's drain*, not be discarded. This is the crux of
  option (a)/(b) above.

A reasonable answer: introduce `g_action_queue_active` (set at the outermost
PlaceObject2 entry, cleared after corresponding drain or at end of frame).
While set, `actionQueueScript` queues regardless of `catch_up_mode`. Outside it,
the existing gate applies. This decouples script gating from the goto
catch-up's `catch_up_mode` semantics.

## Phased migration

Lessons from the failed Approach A2 attempt
(`SHUMWAY_AVM1_SUBTREES_PLAN.md:306–325`) and Part B revert (lines 289–304):
**land the queue infrastructure first, migrate one event class at a time, run
the full canary set after each step.** Big-bang rewrites blew up.

Suggested order:

| Phase | Change | Validation gate |
|-------|--------|-----------------|
| 0 | Add `action_queue.{c,h}` with API + tests but no callsites. CI green. | Unit tests for queue invariants (priority order, FIFO within priority, `is_unload` semantics, dynamic growth past 16). |
| 1 | Migrate `g_pending_onloads` → `actionQueueMethod` at NORMAL. Keep both queues in parallel until proven equivalent, then delete the old one. | Full AVM1 + gnash + shumway CI no regressions. |
| 2 | Migrate `g_pending_unloads` → `actionQueueMethod` at NORMAL with `is_unload=true`. | Same. |
| 3 | Migrate `g_pending_attach_inits`, `g_pending_loads`, `g_deferred_roll_queue`. | Same. |
| 4 | Migrate INITIALIZE clip events: switch `tagPlaceObject2:3391–3392` to `actionQueueClipEvent(..., INITIALIZE)`. Add drain at frame end. | Full CI. Watch `clip_events`, `register_and_init_order`, `on_construct`. |
| 5 | Migrate CONSTRUCT clip events + RegisterClass constructor. | Same canaries. Add `clip_constructors`, `register_class_return_value`. |
| 6 | Migrate root DoAction emission (recompiler change 1, 3, 6 above) + tagPlaceObject2 Phase 2 re-runs become queue inserts. **This is the breaking-point step that fixes root_onload, doactionorder, etc.** | Full canary set including `execution_order1-4`, `clip_events`, `goto_execution_order2`, `variable_args`, `define_function2_preload_order`, `stage_object_enumerate`, `register_and_init_order`. Expect targets to flip green. |
| 7 | Migrate sprite DoAction emission (recompiler change 2). Drop `sprite_frame_scripts` buffer. | Same canary set. |
| 8 | Cleanup: remove `g_defer_sprite_init`, `g_pending_*` queues that were migrated, `non_timeline_scripts` if no longer needed. | Full CI. |
| 9 | (Optional) Replace `MAX_DEFERRED_GOTO_QUEUE=16` static array with the unified queue. | `goto_*` tests + the misc-ming/swfc deeply-recursive goto cases. |

Each phase is committable independently. Stop at a phase boundary if the next
step's risk is unclear.

## Canary tests

Tests previously documented as sensitive to ordering changes (from
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `SHUMWAY_AVM1_SUBTREES_PLAN.md`, and the
2026-04-19 root_onload investigation):

- `avm1/execution_order1` — root, sprite-script, root ordering
- `avm1/execution_order2` — through `gotoAndPlay` catch-up
- `avm1/execution_order3` — 3-phase goto
- `avm1/execution_order4` — nested clip1.child visibility
- `avm1/clip_events` — canonical INITIALIZE > CONSTRUCT > Normal sequence (19 lines)
- `avm1/register_and_init_order` — RegisterClass + DoInitAction (233 lines, very strict)
- `avm1/clip_constructors` — clip ctor ordering
- `avm1/clip_event_propagation_order` — multi-clip event order
- `avm1/on_construct` — CONSTRUCT clip event ordering
- `avm1/variable_args` — `arguments` semantics in sprite DoAction
- `avm1/define_function2_preload_order` — preload register ordering
- `avm1/goto_execution_order` / `goto_execution_order2` — 3-phase deferred init
- `avm1/issue_1104` — per-tick enterframe eligibility
- `avm1/button_order` — button event ordering
- `avm1/goto_rewind3` — backward goto display-list protection

Plus the target tests this rework would unblock:
- `from_gnash/misc-swfmill.all/trace-as2/root_onload` (50% → 100% or `ruffle_matched`)
- `from_shumway/avm1/doactionorder/doactionorder` (3/7 → 7/7)
- `avm1/stage_object_enumerate` (per `RUFFLE_VS_FLASH_DIFFERENCES.md`, would
  flip from documented permanent-diff to passing)
- `from_shumway/timeline/timeline_as2_1` and `timeline_as2_5`
- Subset of `from_gnash/misc-ming.all` `action_execution_order_test*` family
- `from_gnash/misc-swfmill.all/dict_event`

## Known latent bugs the rework may expose

The Part B (MCL one-tick deferral) revert exposed three latent bugs that any
deferred-execution change risks re-triggering:

1. **`movieclip_invalid_get_bounds_1/2` heap corruption** when MCL events fire
   one tick later than today. Use-after-free in getBounds handling. Fix the
   underlying lifecycle bug before Phase 6.
2. **`string_paths_eval2` setInterval timing** — `setInterval(300ms)` chained
   from `onLoadComplete` no longer fires within `num_frames` budget under
   deferred MCL events. The fix is probably independent of A3 (a tick-cap
   based on `hasActiveTimers()` rather than MCL pending status), but worth
   verifying.

Address (1) and (2) before Phase 4 if possible, or accept them as scope of the
ActionQueue rework.

## Effort estimate

Rough order-of-magnitude based on the SHUMWAY plan and the synchronous-site map:

- Phase 0 (queue infra + tests): ~1 session
- Phases 1–3 (low-risk queue migrations): ~1 session each = 3 sessions
- Phase 4 (INITIALIZE migration): ~2 sessions (canary debugging likely)
- Phase 5 (CONSTRUCT migration): ~2 sessions
- Phase 6 (root DoAction inline + Phase 2 removal): ~2 sessions, highest risk
- Phase 7 (sprite DoAction inline): ~1 session
- Phase 8 (cleanup): ~1 session
- Phase 9 (optional goto-queue unification): ~1 session

Total: ~13 focused sessions, assuming full CI runs between phases. Could be
compressed to 6–8 sessions by skipping the parallel-queue step in Phases 1–3.

## Open questions

1. **Drain inside catch-up?** When a deferred goto's target-frame script
   itself triggers another goto (re-entrant goto), Ruffle's queue absorbs it
   naturally. Our 3-phase loop in `swf_core.c` re-iterates if more entries
   were added (`goto_retry_limit=16`). Migration must preserve this safety
   limit.
2. **Drain inside `actionCall` / `Function.call`?** Calling a function that
   contains `actionQueueScript` (e.g. a closure that gotos) — does the inner
   call drain or not? Ruffle: not, only the outer per-tick `run_actions`
   drains. We should match.
3. **Timer fires.** Today timers fire mid-frame via `processTimers`
   (`action.c`). Under A3, the timer callback should queue a script (or
   method) and drain immediately, OR queue and let the outer drain handle it.
   The latter is more Ruffle-like but changes timer semantics observably.
4. **EnterFrame and Load relationship.** Ruffle dispatches EnterFrame from
   `event_dispatch` (queues `Method`) but only when the clip is past its
   init tick. Our `dispatch_enterframe_clip_actions` in
   `tagFlushPendingEnterFrame` already does the right gating; should it
   queue instead of run synchronously? Probably yes for ordering with
   other queued events on the same tick, but verify with `issue_1104`.

## Related documents

- `from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md`
  (Approach A3 sketch + Part B revert post-mortem — the most detailed prior art)
- `from_gnash/_investigation/blocked/ROOT_ONLOAD_PLAN.md` (test-level analysis
  of the simplest case this rework fixes)
- `from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md`
- `from_gnash/_investigation/blocked/MISC_MING_SWFC_PLAN.md`
- `from_gnash/_investigation/blocked/MISC_SWFMILL_PLAN.md`
- `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (stage_object_enumerate
  entry — same root cause from the opposite direction)
- Ruffle source: `~/CC/ruffle/core/src/context.rs:488–540`,
  `~/CC/ruffle/core/src/player.rs:2144–2223`,
  `~/CC/ruffle/core/src/display_object/movie_clip.rs:1282–1492` (run_frame_internal
  + instantiate_child), `1970–1994` (Initialize/Construct queueing).
