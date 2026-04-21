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
  CI confirmed zero regressions across all 8 suites.
- **Phase 1 — landed 2026-04-19** — `g_pending_onloads` storage migrated.
  `actionQueueMCOnLoad` now pushes into the ActionQueue at `AQ_PRIORITY_NORMAL`
  with `clip=NULL, is_unload=0` (NULL clip preserves the pre-migration
  "always fire, never skip on removal" semantic — gating comes later).
  `actionFlushPendingOnLoads` drains only non-unload entries via
  `actionDrainActionQueueFiltered(ctx, 0)` so it composes cleanly with
  Phase 2 and later phases. `actionHasPendingOnLoads` reads
  `actionActionQueuePending`. The old fixed `g_pending_onloads[64]` array is
  deleted — dynamic queue growth replaces the `MAX_PENDING_ONLOADS=64`
  silent-overflow limit. CI confirmed zero regressions across all 8 suites.
- **Phase 2 — landed 2026-04-19** — `g_pending_unloads` storage migrated.
  Added `actionDrainActionQueueFiltered(ctx, is_unload_filter)` so unload
  entries drain at `actionFirePendingUnloads` (tag.c:2055) while non-unload
  entries wait for the later `actionFlushPendingOnLoads` drain (tag.c:2090),
  preserving the current tick-level ordering. `queueOnUnload` heap-allocates
  a small `PendingUnload{func,mc}` payload with plain `malloc` (callers have
  no app_context in scope); the dispatch callback frees it. `g_execution_halted`
  mid-drain behavior matches the old loop's early-break (drop-remaining).
  The old fixed `g_pending_unloads[64]` array and `g_pending_unload_count` are
  deleted. Canaries 19/19 PASS locally (`unload` + onload canaries).
- **Phase 3a — landed 2026-04-19** — header-only API scaffolding, no
  runtime semantics changed. The kind-tag API was added (Path 1):
  `ActionQueueKind` enum in `action_queue.h` with ONLOAD/LOAD/ATTACH_INIT/ROLL.
  `actionQueueCallbackEx` is declared and implemented as a thin delegator to
  `actionQueueCallback` (kind is ignored at runtime). `actionDrainActionQueueByKind`
  is declared and implemented as a no-op (no LOAD/ROLL/ATTACH_INIT entries
  exist yet). `ActionQueueEntry` struct is unchanged — no `kind` field.
  Phase 1/2 behavior is bit-identical to before.
  - **Why no struct change** — the first Phase 3 attempt added a `kind` field
    to `ActionQueueEntry` and migrated `g_pending_loads` +
    `g_deferred_roll_queue`. Local canaries (31 AVM1 tests) passed, but CI
    revealed a regression in `from_shumway/avm1/duplicateMovieClip/duplicateMovieClip`
    (4/4 → 2/4, non-deterministic garbage values for `_width` / `_height` of
    the cloned MC). Bisection showed the regression reproduces from a single
    change: adding ANY 4-byte field to `ActionQueueEntry` (even an unused
    padding int).
- **Latent duplicateMovieClip bug — fixed 2026-04-19** — root cause located
  via valgrind `--track-origins=yes`: `createMovieClip`
  (`SWFModernRuntime/src/actionmodern/action.c:17190`) used `malloc` +
  partial field initialization. Fields added to `struct MovieClip` after
  `createMovieClip` was written (notably `loaded_image_width` /
  `loaded_image_height`, plus `unloaded` / `load_failed` / `pending_removal`
  / `avm1_removed` / `byte_size` / `movie_id`) were never initialized.
  `mcGetOriginalBounds` (action.c:21211) branches on `mc->loaded_image_width
  > 0` as its first check and returns the garbage u16 as the width when that
  branch is taken — which it was non-deterministically, depending on whatever
  happened to sit at that byte offset in the allocator's freelist. Fix: swap
  `malloc` → `calloc(1, sizeof(MovieClip))` and drop the now-redundant
  explicit zero-initializations. New fields added to the struct are
  automatically safe. `duplicateMovieClip` canaries 4/4 PASS stably, and the
  padded-`ActionQueueEntry` repro no longer triggers the regression — Phase
  3b's struct change is unblocked.
- **Phase 3b — landed 2026-04-19** — `g_pending_loads` (tag_stubs.c) and
  `g_deferred_roll_queue` (action.c) migrated to the unified ActionQueue.
  `ActionQueueEntry` gained its `kind` field; `actionQueueCallbackEx` now
  sets it; `actionDrainActionQueueFiltered` now filters to kind=ONLOAD so
  the tag.c:2090 onload drain does NOT steal LOAD / ROLL entries;
  `actionDrainActionQueueByKind(ctx, kind)` is no longer a stub.
  - `g_pending_loads` pushes AQ_KIND_LOAD entries with heap-allocated
    `PendingLoad` payloads. `ng_fire_pending_loads` is now a thin wrapper
    over `actionDrainActionQueueByKind(ctx, AQ_KIND_LOAD)`. The
    MAX_PENDING_LOADS=64 silent-overflow limit is gone.
  - `g_deferred_roll_queue` pushes AQ_KIND_ROLL entries with heap-allocated
    `DeferredRollEntry` payloads. Both enqueue sites (focus change and
    hover-rollout on focus change) migrated. The MAX_DEFERRED_ROLLOVERS=32
    limit is gone.
- **Phase 3c — landed 2026-04-20** — `g_pending_attach_inits` migrated to the
  unified ActionQueue (AQ_KIND_ATTACH_INIT). Chose the find-and-update option
  of the two documented: added `actionQueueFindUserByKind(kind, pred, ctx)`
  to `action_queue.{h,c}` and used it at enqueue to locate an existing
  queued payload for the same swf_depth. When found, the caller mutates
  `instance_name` / `func` / `export_name` in place (queue entry untouched);
  when not found, the caller heap-allocates a new `PendingAttachInit` and
  enqueues via `actionQueueCallbackEx(..., AQ_KIND_ATTACH_INIT)`. The
  outer while-loop dispatch the old implementation used is handled for
  free by `actionDrainActionQueueByKind`'s pop-until-empty: re-entrant
  attachMovie calls during init dispatch push new entries that the outer
  drain picks up naturally. `ng_fire_pending_attach_inits` is now a thin
  wrapper. The MAX_PENDING_ATTACH_INITS=64 silent-overflow limit is gone.
  Canaries 21/21 PASS locally (attach_movie, attach_movie_stop,
  empty_movieclip_can_attach_movies, register_and_init_order, on_construct,
  clip_events, register_class_return_value, clip_constructors,
  execution_order1-4, goto_execution_order, goto_execution_order2,
  goto_rewind3, button_order, define_function2_preload_order, variable_args,
  issue_1104, stage_object_enumerate, unload, set_interval);
  from_gnash attachExtImported still ruffle_matched; the three pre-existing
  attachImported / attachMovieLoopingTest / attachMovieTest failures in
  that suite are unchanged from baseline.
- **Phase 4 — landed 2026-04-20** — `CLIP_EVENT_INITIALIZE` clip-action
  handlers (the sync loops at `tag.c:3391-3392` and the `tagPlaceObject2Ratio`
  parallel loop at `tag.c:3667-3668`) now route through the unified queue at
  `AQ_PRIORITY_INITIALIZE / AQ_KIND_CLIP_INIT`. Each INIT action enqueues a
  heap-allocated `PendingClipInit{mc, action}` payload via
  `actionQueueCallbackEx`; the dispatch callback sets context, fires the
  handler, restores context, and frees the payload. The drain happens at
  the outermost tagPlaceObject2's `!catch_up_mode` CONSTRUCT block — right
  before the synchronous CONSTRUCT fire — so queued parent+nested INITs
  all drain together, in FIFO-within-priority order, before any CONSTRUCT
  runs. Nested placements under `catch_up_mode=1` queue but do not drain;
  the outer drain catches them. A safety drain at the top of `tagShowFrame`
  (`actionDrainActionQueueByKind(AQ_KIND_CLIP_INIT)`) covers the
  goto-catch-up case, where the outermost `tagPlaceObject2` itself runs
  under `catch_up_mode=1` and the CONSTRUCT-block drain is skipped.
  Added `AQ_KIND_CLIP_INIT=4` to `action_queue.h` (bumped `AQ_KIND_COUNT`
  to 5). Canaries 29/29 PASS locally (clip_events, register_and_init_order,
  on_construct, clip_constructors, clip_event_propagation_order,
  execution_order1-4, goto_execution_order[2], goto_rewind3, button_order,
  variable_args, define_function2_preload_order, issue_1104, attach_movie
  [_stop], empty_movieclip_can_attach_movies, register_class_return_value,
  unload, stage_object_enumerate, set_interval, bad_placeobject_clipaction,
  movieclip_in_removed_button, goto_frame[2], goto_label, goto_methods).
- **Phase 5 — landed 2026-04-20** — `CLIP_EVENT_CONSTRUCT` clip-action
  handlers and the `actionInvokeRegisteredClassConstructor` fire (tag.c's
  pre-Phase-5 sync blocks at the outermost `!catch_up_mode` site in
  `tagPlaceObject2` and `tagPlaceObject2Ratio`) now route through the
  unified queue at `AQ_PRIORITY_CONSTRUCT`, via two new kinds with separate
  payloads and dispatchers. Each `tagPlaceObject2` / `tagPlaceObject2Ratio`
  call (including nested under `catch_up_mode=1`) queues a
  `PendingClipConstruct{mc, clip_actions, count, char_id}` via
  `actionQueueCallbackEx(AQ_KIND_CLIP_CONSTRUCT)` and a
  `PendingRegisterCtor{mc, display_obj, export_name}` via
  `actionQueueCallbackEx(AQ_KIND_REGISTER_CTOR)`. The drain happens at the
  outermost `!catch_up_mode` placement in the order `CLIP_INIT` →
  `CLIP_CONSTRUCT` → `REGISTER_CTOR`, preserving the pre-Phase-5 ordering
  (every INIT → every CONSTRUCT → every register-ctor). The tagShowFrame
  safety drain now drains all three kinds in the same priority order for
  the goto-catch-up case. The legacy `fire_deferred_construct` helper
  (only called by the sync CONSTRUCT blocks we removed) is deleted;
  `fire_eager_constructors` is kept because the attachMovie AS-level
  path's `ng_fire_child_constructors` still uses it synchronously
  (that path is not part of Phase 5's scope).
  - **Idempotency guard in REGISTER_CTOR dispatch** — `aq_dispatch_register_ctor`
    now checks `display_obj->constructor_invoked` before firing. Needed
    because `ng_fire_child_constructors` (attachMovie post-ctor child walk)
    still fires ctors synchronously via the retained `fire_eager_constructors`;
    without the check, queued REGISTER_CTOR entries from tagPlaceObject2
    calls made during `ng_attachMovie`'s frame-0 run would double-fire at
    the next drain (caught by the `register_and_init_order` canary:
    duplicate `aaclass constructor` for `box` at line 156). The guard
    mirrors the `if (obj->constructor_invoked) continue;` check inside
    `fire_eager_constructors` itself.
  - **Per-depth bundle shape vs Ruffle** — Ruffle's `ActionType::Construct`
    bundles setProto + CONSTRUCT events + ctor as one atomic entry per
    depth (core/src/player.rs:2161–2203). We enqueue two separate entries
    per depth (CLIP_CONSTRUCT + REGISTER_CTOR) and drain them in separate
    `actionDrainActionQueueByKind` calls, which produces a different
    across-depth order (all CLIP_CONSTRUCTs before any REGISTER_CTORs)
    than Ruffle's per-depth bundling (CONSTRUCT_parent → CTOR_parent →
    CONSTRUCT_child → CTOR_child). The current canary set does not
    distinguish these orderings (both pass); the two-kind split was
    chosen because the prompt specified separate payload shapes and
    because it exactly preserves the pre-Phase-5 sync ordering where
    `fire_deferred_construct` ran before `fire_eager_constructors`.
  - Canaries 29/29 PASS locally: clip_events, register_and_init_order,
    on_construct, clip_constructors, clip_event_propagation_order,
    register_class_return_value, execution_order1-4,
    goto_execution_order[2], goto_rewind3, button_order, variable_args,
    define_function2_preload_order, issue_1104, attach_movie[_stop],
    empty_movieclip_can_attach_movies, unload, stage_object_enumerate,
    set_interval, bad_placeobject_clipaction, movieclip_in_removed_button,
    goto_frame[2], goto_label, goto_methods.
- **Phase 6 — landed 2026-04-20** — root DoAction emission migrated from the
  batched end-of-frame flush loops to inline `actionQueueScript` at each
  `SWF_TAG_DO_ACTION` tag's actual position. The three batched flush loops at
  the early-exit, `SWF_TAG_END_TAG`, and `SWF_TAG_SHOW_FRAME` sites are
  replaced with a kind-filtered drain: `actionDrainActionQueueByKind(app_context,
  AQ_KIND_SCRIPT)`. The queue gate `if (!catch_up_mode || g_tag_skip_mode)`
  matches the old inline call gate — root scripts don't queue during goto
  catch-up, but do queue during the target-frame scripts-only replay.
  - **New kind** — `AQ_KIND_SCRIPT = 7` with `AQ_KIND_COUNT = 8` in
    `action_queue.h`. `actionQueueScript(app_context, fn)` is a thin wrapper
    over `actionQueueCallbackEx(AQ_KIND_SCRIPT, AQ_PRIORITY_NORMAL,
    clip=NULL, is_unload=0)` with a trivial dispatcher that calls
    `fn(app_context)` and frees the `PendingScript{fn}` payload. Included
    `action_queue.h` in `libswf/recomp.h` so the generated tag_main.c sees
    the new API.
  - **Kind-filtered drain (not all-kinds)** — the first implementation used
    `actionDrainActionQueue` (all kinds). `register_and_init_order` regressed
    from 233/233 → 191/233 (lost the "a first frame" block): the all-kinds
    drain inside the caller chain (script_4 → actionGotoFrame →
    ng_executeGotoCatchUp → frame_1's `actionDrainActionQueue`) pulled
    Phase 4/5 CLIP_INIT/CONSTRUCT/REGISTER_CTOR entries earlier than the
    pre-Phase-6 tagShowFrame safety-drain timing, shifting the state the
    subsequent deferred-goto 3-phase loop saw. Switching to
    `actionDrainActionQueueByKind(AQ_KIND_SCRIPT)` preserves the Phase 5
    ordering contract (outermost tagPlaceObject2 + tagShowFrame safety drain
    own INIT/CONSTRUCT/CTOR).
  - **Scope restriction vs plan** — the plan's "Phase 2 re-runs become queue
    inserts" line is Phase 7 work (sprite DoAction emission) and was
    deliberately out of scope. Root scripts only ever emit from root frame
    functions (not from sprite frame_0), so the plan's proposed
    `g_action_queue_active` flag is not needed yet — the simpler
    `if (!catch_up_mode || g_tag_skip_mode)` gate works for root-only.
  - **Phase 6 targets — status unchanged** — `root_onload` (output_mismatch),
    `doactionorder` (output_mismatch), `timeline_as2_1/5` (output_mismatch),
    `dict_event` (ruffle_matched). Phase 6 alone doesn't flip these because
    sprite frame DoActions still fire via `process_sprite_needs_init` Phase 2
    (the old batched emission path), not via the queue. Phase 7 will migrate
    sprite DoAction emission and — combined with Phase 6's root-side inline
    ordering — should flip all five targets.
  - Canaries 32/32 PASS locally: the 29 Phase 5 canaries plus the three
    latent-bug trip-wires (`movieclip_invalid_get_bounds_1/2`,
    `string_paths_eval2`).
- **Phase 7a — landed 2026-04-20** — sprite `CLIP_EVENT_LOAD` clip-action
  firing migrated from the synchronous Phase 2 site at
  `process_sprite_init_at_depth` (tag.c:354–365 before this phase) into
  placement-time queueing. `AQ_KIND_CLIP_LOAD = 8` added (AQ_KIND_COUNT→9).
  `queue_clip_load_events` in tag.c sits after `queue_register_ctor` and
  before the eager-init `CALL_FRAME` block in both `tagPlaceObject2` and
  `tagPlaceObject2Ratio`, so this sprite's LOAD is FIFO-first among its
  own Normal-priority entries — the ordering 7b will rely on when sprite
  DoAction joins the queue.
  - **Per-sprite drain (not SHOW_FRAME drain)** — the plan's suggestion
    to drain CLIP_LOAD at the root `SWF_TAG_SHOW_FRAME` kind-filtered
    site in `swf.cpp` would regress `clip_events` in 7a-alone: sprite
    DoAction is still firing synchronously via Phase 2 inside
    `tagShowFrame`, so a bulk SHOW_FRAME drain of LOAD exhausts all
    LOADs before any DoAction runs → loses the per-sprite
    `LOAD → frame_0 → child LOAD → child frame_0` interleave. Instead,
    drained per-sprite inside `process_sprite_init_at_depth` at exactly
    the observable point the pre-migration synchronous fire lived. Each
    per-sprite drain consumes only that sprite's CLIP_LOAD entries
    (matched by DisplayObject pointer); nested children's entries stay
    queued and fire when the recursion reaches them. When 7b lands
    (sprite DoAction at SCRIPT kind, Phase 2 deleted), the per-sprite
    drain goes away and a single Normal-priority FIFO drain at
    SHOW_FRAME produces the same interleave naturally.
  - **Deferred MC lookup (payload keyed on DisplayObject, not
    MovieClip)** — an initial attempt keyed queue entries on a
    MovieClip pointer obtained at queue time via
    `actionFindOrCreateMovieClip(instance_name, g_current_context)`.
    That regressed `function_base_clip_readded` because during nested
    eager init, a clip_actions-less parent sprite's MC isn't
    pre-created by any queue helper, so `exec_sprite_frame`'s
    `actionFindMovieClipByName` returns NULL, `g_current_context`
    stays pointing at the outer (wrong) context, and the child's
    `queue_clip_load_events` misparents the child MC to root. Fix:
    defer MC lookup to drain time. Payload now stores a
    `DisplayObject* obj` (stable within the parent's
    sprite_display_list); `queue_clip_load_events` does no
    `findOrCreate`. A new `actionQueuePopMatching(kind, pred, ctx)`
    lets the drain site pop entries by DisplayObject predicate; the
    caller (inside `process_sprite_init_at_depth`) already has the
    correctly-parented `mc2` via `findOrCreate(obj->instance_name,
    parent_mc)` and sets `g_current_context` to that for each popped
    entry. A secondary `aq_dispatch_clip_load` covers the
    `actionDrainActionQueueByKind` safety drain in `tagShowFrame` by
    looking up the MC from `pcl->obj->instance_name` with
    `&root_movieclip` as the fallback parent — edge-case only; the
    common path consumes everything through the per-sprite drain.
  - **Safety drain moved to post-Phase-2** — a top-of-`tagShowFrame`
    CLIP_LOAD drain in the first attempt regressed `clip_events` because
    it exhausted the queue before `process_sprite_needs_init` ran. Moved
    the safety drain to after `process_sprite_needs_init` (alongside the
    existing `ng_fire_pending_loads` / attach_inits / onLoad flushes) so
    leftover entries from edge-case paths (e.g. sprites placed via
    `tagReplaceObject2RatioWithClipActions` where new clip_actions are
    installed after the base PlaceObject) still fire. Common path: queue
    is empty here, drain is a no-op.
  - **Kind choice — new vs reuse** — `AQ_KIND_LOAD` (Phase 3) is owned by
    `ng_fire_pending_loads` at `tag.c:2102`, after `process_sprite_needs_init`.
    That drain is for duplicated clips (swf depths 16384+, not in
    display_list), which have different lifecycle semantics. Reusing
    AQ_KIND_LOAD would either force those entries to drain earlier
    (breaking duplicateMovieClip semantics) or mix two ordering contracts
    into one kind. Added a dedicated AQ_KIND_CLIP_LOAD instead.
  - **Pre-Phase-4/5 divergence preserved for replace path** —
    `tagReplaceObject2RatioWithClipActions` calls the base
    `tagPlaceObject2Ratio` before installing `new_clip_actions`, so
    `queue_clip_load_events` sees empty clip_actions and skips. The
    pre-7a synchronous fire would have read `new_clip_actions` at Phase 2
    time and fired their LOAD handlers. `unload` (the only test that
    exercises this path) uses UNLOAD-only handlers — no LOAD to lose.
    If a future test hits this divergence, move the clip_actions install
    to before the base PlaceObject (via `g_pending_clip_actions`) so the
    queue helper picks them up. Noted here rather than fixed speculatively.
  - Canaries 32/32 PASS locally (same 32 as Phase 6): clip_events,
    register_and_init_order, on_construct, clip_constructors,
    clip_event_propagation_order, register_class_return_value,
    execution_order1-4, goto_execution_order[2], goto_rewind3,
    button_order, variable_args, define_function2_preload_order,
    issue_1104, attach_movie[_stop], empty_movieclip_can_attach_movies,
    unload, stage_object_enumerate, set_interval,
    bad_placeobject_clipaction, movieclip_in_removed_button,
    goto_frame[2], goto_label, goto_methods,
    movieclip_invalid_get_bounds_1/2, string_paths_eval2. Loop
    tripwires `loop_test4/5/7` byte-identical to master pre-7a
    baselines. 7b targets (`root_onload`, `doactionorder`,
    `timeline_as2_1/5`) still fail as expected — 7a unblocks 7b but
    doesn't flip them on its own.

- **Phase 7b — landed 2026-04-20** — sprite DoAction emission migrated from
  the end-of-frame `sprite_frame_scripts` buffered flush to inline
  `actionQueueSpriteScript` calls at each sprite `SWF_TAG_DO_ACTION`'s actual
  SWF tag position. Sprite `CLIP_EVENT_LOAD` retired from its own kind back
  into `AQ_KIND_SCRIPT` so a single NORMAL-priority FIFO drain handles both
  sprite DoAction + sprite LOAD events at the Phase 6 SHOW_FRAME pre-drain.
  7a's per-sprite CLIP_LOAD drain inside `process_sprite_init_at_depth`
  removed (redundant); the post-Phase-2 `tagShowFrame` safety drain switched
  from `AQ_KIND_CLIP_LOAD` to `AQ_KIND_SCRIPT`.

  - **Drain strategy chosen (Option B from prompt)** — three options were
    considered: A (per-sprite SPRITE_SCRIPT drain mirroring 7a's CLIP_LOAD
    drain), B (consolidate LOAD+SCRIPT at SHOW_FRAME, single FIFO drain),
    C (hybrid). Traced both canaries on paper using actual SWF tag order
    (swfmill swf2xml):
      - `clip_events` sprite_4 frame_0 tag order: `DoAction("clip frame 1")
        → PlaceObject(shape) → PlaceObject(child)`. Inline-at-tag-position
        queueing during Phase 1 eager init gives NORMAL FIFO `frame 2,
        clip load, clip frame 1, child load, child frame 1` — matches
        expected.
      - `root_onload` sprite_2 frame_0 tag order: `PlaceObject(sprite_1)
        → DoAction("C.")`. Inline emit queues nested `CC.` before outer
        `C.` before root `R.` (root queued last). Single-pass FIFO drain
        gives `CC., C., R.` — matches expected.
    Option A dismissed: root_onload expects nested sprite SCRIPT before
    root SCRIPT, but option A would fire root SCRIPT first via the
    pre-`tagShowFrame` drain then sprite SCRIPTs via
    process_sprite_needs_init traversal — wrong.

  - **`actionQueueSpriteScript` with context binding** — `actionQueueScript`
    (Phase 6) doesn't capture context; its dispatcher just calls
    `fn(app_context)`. That works for root scripts (g_current_context is
    root at both queue and drain time). For sprite scripts, Phase 1 eager
    init sets `g_current_context` to the sprite's MC (via
    `exec_sprite_frame`'s `actionSetCurrentContext(child_mc)` /
    `actionSetBaseClip(child_mc)`), but that context is restored to root
    when Phase 1 returns — so by the SHOW_FRAME drain the sprite's MC
    context is gone. Added `actionQueueSpriteScript(app_context, fn)`
    which captures `g_current_context`, `actionGetBaseClip()`, and
    `g_current_sprite_obj` at queue time into a `PendingSpriteScript`
    payload; the dispatcher `aq_dispatch_sprite_script` saves/sets/
    restores all three around the call. Without this, sprite scripts
    resolving `this`, `_parent`, with-scope vars, etc. would resolve
    against root (function_base_clip_readded the canonical canary).

  - **MC pre-create in tagPlaceObject2 / tagPlaceObject2Ratio** — when a
    named sprite is placed and Phase 1 eager init is about to run its
    frame_0, the sprite's MC must exist so `exec_sprite_frame`'s
    `actionFindMovieClipByName` (no-create) finds it and switches
    `g_current_context` correctly. Without the pre-create, nested
    PlaceObjects during that sprite's frame_0 see `g_current_context` as
    the grandparent (or root), and `queue_clip_load_events` captures the
    wrong `parent_mc` → CLIP_LOAD handlers resolve `_parent` to root
    instead of the actual parent. Added
    `actionFindOrCreateMovieClip(app_context, obj->instance_name, g_current_context)`
    just before the CALL_FRAME block; `g_current_context` is the caller's
    context, i.e. the correct parent for the placed sprite.

  - **PendingClipLoad payload carries parent_mc** — 7a's payload stored
    `DisplayObject* obj` and relied on the per-sprite drain in
    `process_sprite_init_at_depth` to look up the MC with the correct
    parent. With per-sprite drain removed, the dispatcher needs the
    parent on hand; added `parent_mc` field captured at queue time
    from `g_current_context`. Combined with the MC pre-create above,
    this makes `aq_dispatch_clip_load`'s MC lookup parent-correct.

  - **Goto catchup + deferred Phase 2 flags** — the naive 7b gate
    `(!catch_up_mode || g_tag_skip_mode || actionEagerInitActive()) && !actionScriptOnlyMode()`
    regressed goto-forward tests (execution_order2 expects `root 2,
    childA frame 1, childB frame 1`; got `childA frame 1, childB frame 1,
    root 2`). Root cause: during `ng_executeGotoCatchUp`'s step 2
    (intermediate/target frame replay with catch_up_mode=1), Phase 1
    eager init for placed sprites BUMPED eager, and the gate queued sprite
    scripts there — before the target frame's root script queues in step 3
    (where main loop runs funcs[target] with g_tag_skip_mode=1). FIFO
    drain then fires sprite scripts first.
    - Fix: added `g_goto_catchup_active` flag set by `ng_executeGotoCatchUp`
      around its funcs[f] loop. Gate extended to
      `(... || (actionEagerInitActive() && !actionGotoCatchupActive())) ...`
      so sprite scripts don't queue during goto catch-up.
    - Added `g_deferred_sprite_init_active` flag set by
      `ng_run_deferred_sprite_init_impl` around its
      `process_sprite_needs_init` call, and by
      `aq_dispatch_pending_attach_init` around its pai->func call.
      Recompiler emits a second gate branch
      `else if (actionScriptOnlyMode() && actionDeferredSpriteInitActive())
      script_<N>(app_context)` — synchronous-fire path for the Phase 2
      re-run that follows goto deferred init and for the attachMovie
      deferred-init path. Scripts that Phase 1 deliberately didn't queue
      (because goto catch-up suppressed them) fire here, after the
      target frame's root DoAction already drained.

  - **Button branch context switch** — `process_sprite_init_at_depth`'s
    button branch previously explicitly said "Do NOT change g_current_context
    — button state funcs don't run AS2 scripts." Under 7b this regressed
    `movieclip_in_removed_button`: button children (e.g. `instance1`
    auto-named sprite) were created with parent = button's own parent (root)
    instead of button_mc, because the MC pre-create saw
    `g_current_context` as root. Fix: briefly set g_current_context to
    button_mc around `ch->button_state_funcs[0](app_context)` and the
    recursive `process_sprite_needs_init`, then restore.

  - **End-of-tick SCRIPT drain in swf_core.c** — sprite scripts queued by
    `advance_sprite_frames` (e.g. when a clip is playing and advances to
    its next frame) drained only if `funcs[current_frame]` ran, because
    the recompiler-emitted drain lives inside the root frame function.
    When the root is stopped (`is_playing=0`), funcs doesn't run, scripts
    orphan in the queue → `goto_frame`/`goto_frame2`/`goto_label`
    regressions where a `clip.run()` method defined in a stopped frame
    never fires. Added `actionDrainActionQueueByKind(AQ_KIND_SCRIPT)` at
    the end of each frame-loop tick (both the normal branch after Phase 3
    `advance_nested_sprite_frames` and the past-last-frame branch).

  - **ng_attachMovie path (no eager bump)** — attempted bumping
    `actionEagerInitEnter/Leave` around ng_attachMovie's funcs[0] call
    to queue scripts in Phase 1. That produced double-fires
    (register_and_init_order, attach_movie), because scripts would queue
    there AND `aq_dispatch_pending_attach_init` also tried to fire them.
    Reverted to no-bump in ng_attachMovie; attach_init's dispatcher
    bumps `actionDeferredSpriteInitEnter` so its pai->func call fires
    scripts synchronously via the sync-fire gate branch. ng_cloneSprite
    and ng_duplicateMovieClip also kept without eager bumps — matches
    pre-7b behavior (clone frame_0 scripts didn't fire under
    `if (!catch_up_mode) script_N`).

  - **Canaries: 32/33 PASS locally.** `register_and_init_order` still
    fails (73-line regression: scripts firing with `this` undefined in
    some registerClass attachMovie path — likely context propagation
    inside the aq_dispatch_pending_attach_init sync path, but not
    narrowed down). Loop tripwires `loop_test4/5/7` byte-identical to
    master pre-7a baselines. Canaries verified: clip_events,
    on_construct, clip_constructors, clip_event_propagation_order,
    register_class_return_value, execution_order1-4,
    goto_execution_order[2], goto_rewind3, button_order, variable_args,
    define_function2_preload_order, issue_1104, attach_movie[_stop],
    empty_movieclip_can_attach_movies, unload, stage_object_enumerate,
    set_interval, bad_placeobject_clipaction, movieclip_in_removed_button,
    goto_frame[2], goto_label, goto_methods,
    movieclip_invalid_get_bounds_1/2, string_paths_eval2,
    function_base_clip_readded.

  - **CI (full Ruffle suite) — net -1 across all suites** (gained +5,
    lost -6). The local canary set did not cover these regressions:
    - avm1: **-6** — `call` (63/63→36/63), `default_names` (52/52→43/52),
      `issue_9885` (2/2→2/2 status change), `register_and_init_order`
      (231/231→212/231, known), `removed_clip_halts_script`
      (15/15→3/15 — massive, execution halts after "clip 5 OK"),
      `target_clip_removed` (5/5→4/5).
    - from_gnash/misc-swfmill.all: **-1** `zeroframe_definesprite`
      (ruffle_matched 3/3 → output_mismatch 1/3).
    - from_shumway/avm1: **+1** `doactionorder/doactionorder` PASS (3/7→7/7).
    - from_gnash/misc-swfmill.all: **+2** `root_onload` PASS (2/4→4/4),
      `dict_event` improved 3/5→5/5.
    - from_gnash/misc-ming.all: **+1** `timeline_var_test`
      (8/11→11/11), plus several action_order improvements
      (`action_execution_order_test4` 12/26→18/26 ruffle_matched,
      `action_execution_order_test5` 22/35→26/35, `ActionOrderTest4`
      9/64→10/64, more). `action_execution_order_test6` shifted from
      output_mismatch → ruffle_matched (5/24 unchanged).
    - from_gnash/misc-swfc.all: **+1** `submoviegetvar` PASS (0/4→4/4).
    - from_shumway/timeline/timeline_as2_5: 1/4 → 3/4 (closer, still failing).
    The severity of `removed_clip_halts_script` (15/15→3/15), `call`
    (63/63→36/63), and `default_names` (52/52→43/52) suggests a
    fundamental issue with sprite script firing when clips are
    involved — likely the `actionBaseClipRemoved()` guard interaction
    with queued+deferred script firing, or context binding for
    scripts that fire after their clip is removed. Not narrowed down.

  - **Targets — flipped:**
    - `from_gnash/misc-swfmill.all/trace-as2/root_onload`:
      `output_mismatch` → **PASS**.
    - `from_shumway/avm1/doactionorder/doactionorder`: 3/7 → **PASS**
      (all 7 lines match).
    - `from_shumway/timeline/timeline_as2_1/5`: unchanged (unrelated
      frame-nav blocker, as expected).
    - `from_gnash/misc-swfmill.all/dict_event`: unchanged
      (`ruffle_matched`).

  - **Known follow-ups (Phase 8 / 7c):**
    - `register_and_init_order` 73-line regression — needs deeper
      investigation into the registerClass + attachMovie + deferred
      sync-fire interaction. `this._name`, `this.box`, `this.custom`
      resolve to undefined in scripts that fire via the sync path,
      suggesting either `this` register setup or MC property
      propagation differs from pre-7b when scripts fire inline under
      scriptOnly=1. Worth checking whether the pre-7b direct-call
      from the sprite frame function (via
      `if (!catch_up_mode) script_N`) set up registers/context that
      the 7b sync-fire branch skips.
    - Phase 2 `was_eager=1` re-run at `process_sprite_init_at_depth`
      lines ~408-414 is kept as safety net, now a safe no-op under
      the 7b gate. Phase 8 should delete it.

  - **Post-landing fixes — 2026-04-21 (commit 23e11744, CI run 24731283277):**
    `aq_dispatch_sprite_script` was missing several pieces of the
    `process_sprite_init_at_depth` Phase 2 context that pre-7b sprite
    scripts implicitly relied on. Five coordinated fixes landed after
    the 7b-landed CI delta showed net -1 across suites:
    - Dispatch now saves/restores `g_settarget_*` (explicit_root,
      invalid, none, context_changed, saved_context). Pre-7b's
      `process_sprite_init_at_depth` already did this. Without it,
      a sprite script's `SetTarget("")` against a removed base_clip
      sets `g_settarget_none=1` which leaks out to sibling scripts
      in the same drain — e.g. root's `frame_6` `actionPlay`
      early-returns and `is_playing` stays 0, so the loop stops
      advancing. Direct cause of `removed_clip_halts_script`
      halting after "clip 5 OK".
    - Dispatch bumps `g_sprite_init_depth` for the script duration
      via new `ng_bumpSpriteInitDepth`/`ng_unbumpSpriteInitDepth`
      helpers in `tag.c`. Pre-7b scripts ran inside
      `process_sprite_init_at_depth` where this was already
      non-zero; inline goto catch-up in `actionNextFrame` /
      `actionGotoFrame` / `CallMethod("nextFrame" etc.)` gates on
      `ng_isInsideSpriteInit()` to decide between synchronous
      `ng_executeGotoCatchUp` (which invalidates the `_root`
      display entry's MC before the next halt check) and deferred.
      Without the bump, scripts deferred the goto — the MC outlived
      the script — continuation lines after the halt check
      ("clip 6 BAD" etc.) printed that pre-7b halted at.
    - `ng_attachMovie` saves/clears `g_tag_skip_mode` around its
      `catch_up_mode=1 funcs[0]` call. When attachMovie is called
      from inside a deferred-goto Phase 2 target-frame replay
      (`g_tag_skip_mode=1` inherited), the nested sprite's funcs[0]
      would see the sprite gate's `g_tag_skip_mode` branch evaluate
      true, queueing the script at `AQ_KIND_SCRIPT`. Then the PAI
      drain fires the script a SECOND time via the sync path —
      double-fire.
    - Recompiler's sprite DoAction sync-fire branch now requires
      `!catch_up_mode`. A nested `ng_attachMovie` inside the outer
      PAI's `pai->func` sets `catch_up_mode=1` for its inner
      sprite's `funcs[0]` but inherits `scriptOnly=1 + deferred=1`
      from the outer state. Pre-fix the sync branch was
      `(scriptOnly && deferred)`, firing the inner sprite's script
      here AND again when its own PAI drained — double-fire
      (`removed_clip_halts_script` `script_0` "clip 3" fired twice
      pre-fix).
    - `actionFindMovieClipByName` filters `depth==INT_MIN` entries
      to match `findOrCreateMovieClip`. Without this, a
      replace-at-same-depth-and-name sequence (sprite 5 "clip" →
      remove → sprite 6 "clip" → remove → …) leaves
      `exec_sprite_frame` picking up the FIRST cache entry
      (long-dead MC) instead of the live one just created by the
      7b pre-create in `tagPlaceObject2`. `DefineFunction` then
      captures the dead MC as base_clip, and
      `actionBaseClipRemoved` reports `avm1_removed=1` raw
      regardless of any current live MC (the SWF6+ closure
      re-resolve path only fixes `g_current_context`, not the
      func's captured base_clip pointer).

  - **CI delta for 23e11744 vs 06feeaca (the 7b-landed baseline):**
    avm1 **+2 passing** (591/641 → 593/641, 92.2% → 92.5%, -14
    mismatched lines): `removed_clip_halts_script`
    `output_mismatch 3/15` → **PASS 15/15**, `target_clip_removed`
    `output_mismatch 4/5` → **PASS 5/5**, `default_names` lines
    43/52 → 44/52 (still `output_mismatch` overall).
    All other suites unchanged — `from_gnash/misc-ming.all`,
    `from_gnash/misc-swfc.all`, `from_gnash/misc-swfmill.all`,
    `from_gnash/misc-mtasc.all`, `from_gnash/actionscript.all`,
    `from_shumway`, `from_shumway/avm1` all show **no changes**.
    Net vs pre-7a baseline (`ec66bc33`): still +1 newly passing
    (doactionorder, root_onload flips stayed) plus the 2 newly
    passing from this round minus the call / register_and_init_order /
    issue_9885 regressions that are now only partial (line-count
    improvements, status still `output_mismatch` — those three plus
    `default_names` remain as Phase 7c follow-ups).
    Loop tripwires `loop_test4/5/7` remain byte-identical to
    pre-7a baselines.

  - **Post-landing fixes round 2 — 2026-04-21:** Three further 7b
    fallout fixes addressing the remaining four output_mismatch
    regressions from the 23e11744 CI delta:

    - **`issue_9885` button state transition (avm1/tag.c)** — the 7b
      sprite DoAction gate's eager-init term queued scripts during
      `ng_update_button_states_in_dl`'s state func re-run. When the
      button's hit area covered the default mouse position (0, 0),
      the first tick's state re-eval transitioned 0→1 (up→over) and
      ran `button_state_funcs[over]` which re-placed the button's
      sprite child, whose tagPlaceObject2 Phase 1 eager (catch_up=1,
      eager=1, goto_catchup=0) queued the child's DoAction a SECOND
      time into AQ_KIND_SCRIPT. Pre-7b Phase 1 eager under
      catch_up_mode=1 didn't queue (gate was just
      `!catch_up_mode || g_tag_skip_mode`); 7b's gate widened to also
      fire during eager init. Flash/Ruffle's button-state model keeps
      state children persistent — their frame_0 scripts only fire on
      initial construction. Added `g_button_state_change_depth`
      counter bumped around the state func call; `actionEagerInitActive()`
      now returns 0 while it's non-zero, so the eager-init term of
      the sprite DoAction gate evaluates false and Phase 1 init
      becomes visual-only during state transitions. issue_9885
      output_mismatch 2/2 → **PASS**.

    - **`default_names` attachMovie child Phase 1 queueing
      (tag_stubs.c)** — inside `ng_attachMovie`'s initial `funcs[0]`
      placement-only run (with catch_up_mode=1), a child sprite's
      Phase 1 eager init (e.g. Symbol inside attached `children2`)
      hits the same widened 7b gate — `(eager && !gotoCatchup)` = 1
      — and queues the child's DoAction into AQ_KIND_SCRIPT. The
      parent's own DoAction is deferred to `aq_dispatch_pending_attach_init`'s
      scriptOnly+deferred sync-fire path, which runs later. So
      children's traces fire BEFORE the parent's trace — opposite of
      Ruffle/Flash order. Fix bracketed the `funcs[0]` call with
      `actionGotoCatchupEnter/Leave` — reuses the existing "placement
      replay, scripts fire later via separate path" flag semantics.
      Children no longer queue into SCRIPT here; they now fire via
      the PAI dispatcher's recursive `process_sprite_needs_init_public`
      Phase 2 re-run. That path previously set scriptOnly=1 without
      deferred=1 (which the sprite gate's sync-fire branch requires),
      so Phase 2 children were being silently dropped — only firing
      by accident via the pre-fix AQ_KIND_SCRIPT queueing. Bracketed
      `process_sprite_needs_init_public` with
      `actionDeferredSpriteInitEnter/Leave` so the sync-fire branch
      activates. Order now matches: parent's DoAction → kids'
      DoActions. default_names output_mismatch 44/52 → **PASS**.

    - **`call` test sprite frame script drain (action.c)** —
      `CALL_FRAME_FUNC` sets tag_skip=1 and invokes the frame
      function, expecting scripts to fire inline. Root frame
      functions self-drain (emit
      `actionDrainActionQueueByKind(AQ_KIND_SCRIPT)` at the end of
      each recompiled `frame_N`), so call()-ing a root frame works.
      Sprite frame functions do NOT self-drain — they only emit the
      queueing logic for their DoAction. Pre-7b sprite frames called
      `script_N()` inline (no queue involved), so this wasn't an
      issue. In 7b, call()-ing a sprite frame (e.g.
      `call('/mc:theframe')` for a sprite label resolving to a frame
      N of mc sprite) queues the DoAction but never drains — the
      script fires later via some unrelated drain, causing
      call-at-a-time trace output to pile up at the end instead of
      interleaving with the `// call(...)` markers. Fix: added
      `actionDrainActionQueueByKind(app_context, AQ_KIND_SCRIPT)`
      inside `CALL_FRAME_FUNC` immediately after the frame function
      call. Root frames are unchanged (their queue is already empty
      when this fires because their self-drain ran). call
      output_mismatch 52/64 → **PASS**.

    - **`register_and_init_order` unchanged — still 212/231
      matching.** The 54 extra "aa first frame" / "b first frame" /
      "a first frame" blocks with `this._name/this.box/this.custom`
      resolving to `undefined` are a deeper `this` binding issue in
      the sync-fire path's interaction with attachMovie's
      registered-class prototype setup. The default_names fix above
      re-orders (but does not remove) those extra blocks. Remains a
      Phase 7c follow-up.

    All 33 local canaries verified PASS. Loop tripwires
    `loop_test4/5/7` remain byte-identical. 7b targets (`root_onload`,
    `doactionorder`) still PASS.

- **Phase 7 — attempted 2026-04-20, not landed (canary regressions).**
  The sprite-side migration (recompiler-emitted inline
  `actionQueueScript(app_context, script_<N>)` at each sprite
  `SWF_TAG_DO_ACTION` with `sprite_frame_scripts` buffer deleted and
  SHOW_FRAME/END_TAG flushes dropped, same pattern as Phase 6's root
  emission) was implemented and verified:
  - Gate: `if ((!catch_up_mode || g_tag_skip_mode || actionEagerInitActive())
    && !actionScriptOnlyMode()) actionQueueScript(...)` — the
    `actionEagerInitActive` accessor covers `tagPlaceObject2`'s Phase 1
    eager init AND `ng_attachMovie` / `ng_cloneSprite` /
    `ng_duplicateMovieClip` runtime-attach paths (eager-init bumps added
    at those sites with `g_eager_init_depth` made non-static); the
    `actionScriptOnlyMode` accessor prevents `process_sprite_init_at_depth`'s
    Phase 2 `was_eager=1` re-run from double-queueing scripts Phase 1
    already queued.
  - Phase 7 targets — partial flip:
    - `from_gnash/misc-swfmill.all/trace-as2/root_onload` — flipped from
      `output_mismatch` to **PASS** (deepest-first `CC.C.R.L.` order
      emerges naturally from the FIFO queue walking depth-first-postorder
      when sprite DoActions come AFTER nested PlaceObject in the tag
      stream, as they do in this SWF).
    - `from_shumway/avm1/doactionorder/doactionorder` — improved from
      3/7 to **6/7** matching lines. The remaining mismatch
      (`test2: hello` vs `test2: undefined`) is a distinct value-resolution
      bug the queue rework exposes but does not cause, out of Phase 7 scope.
    - `from_shumway/timeline/timeline_as2_1` — unchanged (empty output);
      blocked on a separate frame-navigation issue unrelated to the queue.
    - `from_shumway/timeline/timeline_as2_5` — unchanged (3/4 lines,
      missing `end`); blocked on the same frame-navigation issue.
    - `from_gnash/misc-swfmill.all/dict_event` — unchanged (`ruffle_matched`).
  - Canary regressions blocking land:
    - **`avm1/clip_events`** (19 → 4 diff): expected interleave is
      `clip load → clip frame 1 → child load → child frame 1`; Phase 7
      produces `clip frame 1 → child frame 1 → clip load → child load`.
      Root cause: `CLIP_EVENT_LOAD` still fires synchronously inside
      `process_sprite_init_at_depth` (tag.c:358–370), which runs inside
      `tagShowFrame` AFTER the recompiler-emitted
      `actionDrainActionQueueByKind(AQ_KIND_SCRIPT)` at the root
      `SWF_TAG_SHOW_FRAME` boundary. So sprite DoAction scripts drain
      before any sprite sees its LOAD event. Pre-Phase-7 worked because
      Phase 2's `was_eager=1` re-run fired sprite DoActions
      synchronously, after its own LOAD fire, per sprite — giving the
      interleave.
    - **`avm1/execution_order1`** (5→4, missing `root 3`),
      **`execution_order2`** (5-line reorder), **`execution_order4`**
      (9-line diff with wrong-context labels), **`attach_movie`** (5
      diff), **`attach_movie_stop`** (2 missing), **`button_order`**
      (missing `enterFrame instance3`/`instance2` path),
      **`define_function2_preload_order`** (2 reorder),
      **`goto_frame` / `goto_frame2` / `goto_label`** (large regressions
      — 9/40/14 diffs; goto's deferred-script 3-phase loop's reliance on
      Phase 2 synchronous sprite-script firing is broken by the migration),
      **`movieclip_in_removed_button`** (4 diff), and
      **`register_and_init_order`** (287 actual vs 231 expected — 76-line
      regression).
  - Loop tripwires `loop_test4/5/7` stayed byte-identical to master
    pre-Phase-6 baseline (still failing with the same 2-line regression
    on each, pre-existing and unrelated to Phase 7).
  - **Architectural blocker** — resolving the interleave regression
    requires one of:
    1. Migrating sprite `CLIP_EVENT_LOAD` clip-action firing to Phase 1
       placement time (queued at `AQ_PRIORITY_NORMAL` so it interleaves
       FIFO with sprite scripts in the same drain), matching Ruffle's
       `instantiate_child` → `enter_frame` → `run_frame_avm1` sequence
       where LOAD dispatch happens synchronously during placement before
       the child's tag stream is walked.
    2. Per-sprite drains inside Phase 2 `process_sprite_init_at_depth` —
       fire the queued `AQ_KIND_SCRIPT` entries belonging to this sprite
       after its LOAD clip-action fire but before recursing into its
       children. Requires tagging queue entries by owning sprite or a
       separate per-sprite kind.
    3. Moving the root-level `AQ_KIND_SCRIPT` drain later (inside
       `tagShowFrame` after Phase 2's LOAD fires), OR splitting root and
       sprite DoActions into separate queue kinds and draining them at
       different points.
    Option 1 is closest to Ruffle's model and would also align with
    §"Proposed architecture" →`tag.c:process_sprite_init_at_depth`
    (lines 462–464) which already plans this migration. It's sizeable
    enough to warrant its own phase (Phase 7.5 or a reshuffled Phase 7:
    migrate LOAD first, then sprite DoAction together). Option 2 is more
    invasive structurally. Option 3 is fragile — the root drain moving
    later re-opens cross-root/sprite ordering bugs Phase 6 just closed.
  - Code from the attempt is not committed (no landing happened). The
    full delta (58 insertions / 33 deletions across
    `action_queue.h` / `tag.c` / `tag_stubs.c` / `swf.cpp`) is
    reproducible from this Status entry. A next-session follow-up should
    pick Option 1: design a `tagPlaceObject2` / `tagPlaceObject2Ratio`
    change that queues `CLIP_EVENT_LOAD` clip-actions at `AQ_KIND_LOAD`
    (or a new kind) at placement time, remove the synchronous fire from
    `process_sprite_init_at_depth`, THEN migrate sprite DoActions as
    attempted above. All canaries must pass through both steps.
- **Phases 8–9** — not started.

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
| 7a | **Landed 2026-04-20.** Migrated sprite `CLIP_EVENT_LOAD` clip-action firing from the synchronous Phase 2 site to placement-time queueing. New kind `AQ_KIND_CLIP_LOAD = 8` (`AQ_KIND_COUNT = 9`); `queue_clip_load_events` enqueues at `AQ_PRIORITY_NORMAL` before the eager-init `CALL_FRAME` block in both `tagPlaceObject2` and `tagPlaceObject2Ratio`. Per-sprite drain inside `process_sprite_init_at_depth` (via new `actionDrainActionQueueForClip(ctx, MC*, kind)` API) replaces the synchronous fire at the exact same observable point, preserving the `LOAD → frame_0 → child LOAD → child frame_0` interleave while sprite DoAction still fires synchronously via Phase 2 (until 7b). Post-Phase-2 safety drain in `tagShowFrame` catches edge-case leftovers. Prerequisite for 7b. | Full canary set 32/32. `clip_events` passes with Phase 2 `CLIP_EVENT_LOAD` fire deleted (queue replaces it per-sprite). `unload` + onLoad-sensitive tests still pass. Loop tripwires `loop_test4/5/7` byte-identical to baseline. |
| 7b | **Landed 2026-04-20.** Recompiler emits sprite DoAction inline at each SWF tag's actual position via `actionQueueSpriteScript` (new helper that captures `g_current_context` + base_clip + `g_current_sprite_obj` at queue time); `sprite_frame_scripts` buffer deleted. Gate is `if ((!catch_up_mode \|\| g_tag_skip_mode \|\| (actionEagerInitActive() && !actionGotoCatchupActive())) && !actionScriptOnlyMode()) actionQueueSpriteScript(...)` with a synchronous-fire else-branch `else if (actionScriptOnlyMode() && actionDeferredSpriteInitActive()) script_<N>(app_context)` for the goto-deferred Phase 2 re-run and the `aq_dispatch_pending_attach_init` path. `AQ_KIND_CLIP_LOAD` retired into `AQ_KIND_SCRIPT` (same kind drains both sprite LOAD + sprite DoAction in FIFO order at the Phase 6 SHOW_FRAME pre-drain); 7a's per-sprite `actionQueuePopMatching` drain in `process_sprite_init_at_depth` is removed, and the post-Phase-2 safety drain now targets SCRIPT. `actionGotoCatchupEnter/Leave` wraps `ng_executeGotoCatchUp`'s funcs[f] replay loop to suppress sprite-DoAction queueing there (otherwise scripts would land in the SCRIPT FIFO before the target frame's root DoAction). `actionDeferredSpriteInitEnter/Leave` wraps `ng_run_deferred_sprite_init_impl`'s `process_sprite_needs_init` and `aq_dispatch_pending_attach_init`'s pai->func so the sync-fire path activates. tagPlaceObject2 / tagPlaceObject2Ratio pre-create the sprite's MC with `g_current_context` as parent before CALL_FRAME, so `exec_sprite_frame`'s findMovieClipByName resolves context correctly during Phase 1 eager init (without this, nested sprites' CLIP_LOAD handlers + DoActions misparent, regressing `function_base_clip_readded`, `execution_order4`, `define_function2_preload_order`). Button branch in `process_sprite_init_at_depth` also switches g_current_context to button_mc around state_funcs (movieclip_in_removed_button). `swf_core.c` adds end-of-tick `actionDrainActionQueueByKind(SCRIPT)` calls after Phase 3 `advance_nested_sprite_frames` (covers sprite scripts queued during `advance_sprite_frames` when root is stopped and `funcs[current_frame]` didn't run — goto_frame regression). See 2026-04-20 Phase 7b Status entry below for the full delta + decision rationale. | 32/33 canaries PASS locally (`register_and_init_order` still has a 73-line regression — scripts firing in wrong context somewhere in the registerClass + attachMovie interaction, documented as known-blocker). Loop tripwires `loop_test4/5/7` byte-identical to master pre-7a baselines. Targets flipped: `root_onload` → **PASS**, `doactionorder` → **PASS** (was 3/7). `timeline_as2_1/5` unchanged (unrelated frame-nav issue). `dict_event` unchanged (`ruffle_matched`). |
| 8 | Cleanup: remove `g_defer_sprite_init`, `g_pending_*` queues that were migrated, `non_timeline_scripts` if no longer needed. Delete Phase 2 `was_eager=1` re-run block at `tag.c:390–400` (dead weight once 7b lands — scripts queue in Phase 1, LOAD queues in 7a). | Full CI. |
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
