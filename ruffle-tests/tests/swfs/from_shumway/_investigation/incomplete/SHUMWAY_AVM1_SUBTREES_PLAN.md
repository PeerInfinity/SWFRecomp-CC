# Shumway avm1/ Remaining Failures — Fix Plan
<!-- TESTS: moviecliploader, avm1/moviecliploader -->

One test remaining in the `from_shumway/avm1/` sub-tree (also surfaces in the flat `from_shumway/` suite). Originally this plan tracked two — Part A (`doactionorder/doactionorder`) was resolved by Phase 6 of the ActionQueue rework (commit `a427f5fc`). Part A's content is preserved below as historical context. Active work is **Part B only** (moviecliploader, MCL one-tick deferral).

- ~~**Part A** — `doactionorder/doactionorder` (3/7). FIFO queueing of DoAction across root and sprite tags.~~ — **RESOLVED** via Phase 6 of `complete/ACTION_QUEUE_PLAN.md`. The approach this section originally proposed (A3) effectively became that plan.
- **Part B** — `moviecliploader` (1/7). Deferring MovieClipLoader events one frame tick so they fire after the next frame's DoAction.

Commands:

```bash
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_shumway \
  --test=avm1/moviecliploader --diff --verbose
```

---

## Part A — `doactionorder/doactionorder` (RESOLVED 2026-04-XX via ActionQueue Phase 6)

The analysis below was the basis for the unified ActionQueue work; it landed
via that plan and `doactionorder` now PASSES (7/7). Kept here for historical
context and as background for anyone tracing the FIFO-DoAction lineage.

### Diff (baseline 2026-04-17)

### Diff (baseline 2026-04-17)

```
expected:                        actual:
root1                            root1
sym1: _level0.sym1               sym1: _level0.sym1
test1: undefined                 test1: undefined
sym1                             root2         <-- root DoAction #2 too early
root2                            sym1: _level0.sym1
sym1: _level0.sym1               test2: undefined   <-- sym1.test not set yet
test2: hello                     sym1          <-- sprite DoAction runs last
```

### Test SWF tag stream (from `test.xml`)

```
SetBackgroundColor
DoAction            (root script A — "root1")
DefineShape 1
DefineSprite 2
  DoAction          (sprite script — SetLocal test="hello"; trace "sym1"; append log.text)
  PlaceObject2
  ShowFrame
PlaceObject2 sym1 depth=1 objectID=2
DefineFont3, DefineFontAlignZones, DefineEditText
PlaceObject2 log
DoAction            (root script B — "root2" / reads sym1.test)
ShowFrame
```

Ruffle order: queue root-A, then sprite-PlaceObject2 triggers child's `run_frame_internal` which queues sprite-script, then queue root-B → FIFO drain: A, sprite, B.

### Current architecture (batch-at-ShowFrame)

Recompiler (`SWFRecomp/src/swf.cpp`):
- Root DoAction case (`SWF_TAG_DO_ACTION`, line 2527): writes `script_<N>.c`, advances `next_script_i`, but emits **no call** inline in `context.tag_main`.
- Three flush sites (**lines 548–556, 807–815, 861–868**) emit the accumulated `script_N(app_context);` calls in a loop, gated on `!catch_up_mode || g_tag_skip_mode`, skipping entries in `non_timeline_scripts` (DoInitAction, clip/button actions, sprite DoActions). All three flushes happen at `END_TAG`/`SHOW_FRAME` boundaries — never between PlaceObject2 and ShowFrame.
- Sprite DoAction (line 4914) appends the call to a per-sprite `sprite_frame_scripts` buffer which is emitted into the sprite frame body **after all placement tags** (lines 4081, 4114–4123), with `if (!catch_up_mode) script_N(app_context);` guard.

Runtime (`SWFModernRuntime/src/libswf/tag.c`):
- `tagPlaceObject2` eager-init block (lines 3401–3432): calls `sp_ch->sprite_frame_funcs[0]` under `catch_up_mode=1`, so placement tags execute but scripts are gated off. Sets `sprite_needs_init = 2` (= "Phase 1 done, Phase 2 pending").
- `process_sprite_init_at_depth` (lines 256–489): called from `tagShowFrame` → `process_sprite_needs_init`. When it sees `sprite_needs_init == 2` (`was_eager`), runs `frame_funcs[0]` with `g_script_only_mode=1` — placement tags become no-ops, scripts run.

Net: root scripts run before `tagShowFrame`, sprite scripts run during `tagShowFrame`. Order A→B→sprite.

### Ruffle's model (from `~/CC/ruffle/core/src/`)

- `ActionQueue` (`context.rs:491`) — three priority buckets; within a bucket, FIFO.
- `MovieClip::run_frame_internal` (`display_object/movie_clip.rs:1282`) walks the frame's tag stream; `do_action` (`:4117`) just **queues** `ActionType::Normal { bytecode }`, never runs it. `place_object` (`:4329`) calls `instantiate_child` (`:1410`), which synchronously calls `child.run_frame_avm1(context)` (`:1474`) — the child's `run_frame_internal` then walks the sprite's tag stream and queues the sprite's DoAction.
- The queue is drained exactly once per `Player::update` tick via `Player::run_actions` (`player.rs:2144`) after *all* clips on `clip_exec_list` have finished queueing (`Avm1::run_frame`, `runtime.rs:479`).

### Target architecture

Two approaches. We recommend **Approach A2** (minimal delta, same FIFO behaviour for the cases our tests exercise).

#### Approach A1 — Runtime ActionQueue (Ruffle-equivalent)

- Add `actionQueueScript(app_context, script_fn)` and `actionDrainActionQueue(app_context)` to the runtime.
- Recompiler emits `actionQueueScript(app_context, script_<N>);` at every DoAction site (root and sprite) — no batching, no inline calls.
- Recompiler emits `actionDrainActionQueue(app_context);` once per frame_func, just before `tagShowFrame`. (Or put the drain inside `tagShowFrame` itself, before `process_sprite_needs_init` — but then Phase 2 scripts also need to funnel through the queue.)
- Sprite `PlaceObject2` runs Phase 1 (placement tags only). Scripts get queued by their own frame-body `actionQueueScript` calls.

Trade-offs: maximally faithful to Ruffle, one drain point, but touches every DoAction emission site in the recompiler and every script-invocation site in the runtime. Larger diff, higher regression surface area.

#### Approach A2 — Inline root + eager sprite Phase 2 (recommended)

Two coupled changes. **No new queue data structure.**

1. **Recompiler (`SWFRecomp/src/swf.cpp`)**
   - In the `SWF_TAG_DO_ACTION` case (line 2527), after writing `script_<N>.c`, emit the call inline in `context.tag_main`:
     ```
     if (!catch_up_mode || g_tag_skip_mode) script_<N>(app_context);
     ```
   - Remove the "flush queued scripts" loops at lines 548–556, 807–815, 861–868. (Keep `non_timeline_scripts` for its existing use — tracking which indices are owned by clip/button handlers so they're never double-invoked.)
   - Sprite DoAction path stays as-is.

2. **Runtime (`SWFModernRuntime/src/libswf/tag.c` `tagPlaceObject2`)**
   - After the existing Phase 1 eager-init block (lines 3401–3432) runs `catch_up_mode=1` + frame_funcs[0], add Phase 2 inline: call `frame_funcs[0]` a second time under `g_script_only_mode=1` with `catch_up_mode=0` to execute just the scripts. Then clear `sprite_needs_init = 0` so `tagShowFrame`'s `process_sprite_needs_init` won't process this entry again.
   - **Important**: also fire the other side-effects currently done in `process_sprite_init_at_depth` (lines 256–489) at the same point: `CLIP_EVENT_LOAD` handlers (351–362), registered-class constructor (428–433), `actionQueueMCOnLoad` (437–438), `sprite_initialized = 1` (444). Recurse into children via `process_sprite_needs_init(child_mc)` (407).
   - The cleanest way: factor lines 256–489 into `static void finalize_sprite_at_depth(app_context, parent_mc, depth_idx)` that takes `was_eager` and a "scripts already ran?" flag. Call it from both `tagPlaceObject2` (scripts-pending path) and `process_sprite_init_at_depth` (legacy path for attachMovie etc.).
   - `tagPlaceObject3` and `tagPlaceObject2Ratio` have parallel eager-init logic (lines 3651–3749) — apply the same change there.

After this, Ruffle FIFO semantics drop out naturally: a DoAction before a PlaceObject2 runs inline; the PlaceObject2 then runs Phase 1 + Phase 2 inline (sprite's own DoAction fires); the next root DoAction runs inline. Order A→sprite→B.

### Interaction with goto catch-up

Goto catch-up machinery (`swf_core.c:80–238, 910–1048`; `tag.c:4730–4805`):
- `ng_executeGotoCatchUp` sets `g_defer_sprite_init = 1` and `catch_up_mode = 1`, runs intermediate frame_funcs, queues target. `tagShowFrame` skips `process_sprite_needs_init` when `g_defer_sprite_init=1`.
- Main loop's deferred-goto processing (swf_core.c:998–1042):
  ```
  Phase 0: ng_fire_deferred_constructors
  Phase 1: ng_run_deferred_sprite_init_before(target)
  Phase 2: g_tag_skip_mode=1; funcs[target](app_context); g_tag_skip_mode=0;
  Phase 3: ng_run_deferred_sprite_init_on_or_after(target)
  ```

With inline root DoActions under A2:
- Intermediate frame replay: `catch_up_mode=1` is active → inline `if (!catch_up_mode || g_tag_skip_mode)` guard suppresses root DoAction calls. Sprite scripts also gated off. ✓
- Target frame re-run under `g_tag_skip_mode=1`: tags short-circuit via `if (g_tag_skip_mode) return;` at tagPlaceObject2's top (`tag.c:3145`). So target-frame PlaceObject2 is a no-op → no Phase 1 or Phase 2 runs. Target-frame root DoAction calls DO run (gated by `g_tag_skip_mode`). Sprite Phase 2 still needs to run for target-frame sprites — this is what `ng_run_deferred_sprite_init_on_or_after` does today by walking `sprite_needs_init` directly. ✓
- Key invariant to preserve: when `tagPlaceObject2` runs Phase 1+Phase 2 eagerly, it must still set `sprite_needs_init = 0` (not 2) so the deferred-goto machinery doesn't double-fire. Sprites placed during `catch_up_mode=1` intermediate replays should keep the current behaviour: Phase 1 runs, Phase 2 is deferred via `sprite_needs_init = 2`, and `ng_run_deferred_sprite_init_*` picks them up.
- Concretely: gate the "new eager Phase 2" block on `!catch_up_mode`. Inside goto replay the old `sprite_needs_init=2` path stays.

### Risk / canary tests

`RUFFLE_VS_FLASH_DIFFERENCES.md:17–27` explicitly documents that the Phase 1/Phase 2 split was chosen to protect these four tests (they are said to "break under eager execution"):

| Test | What it checks | Why it might break under A2 |
|---|---|---|
| `avm1/execution_order1` | `root 1, child 1, child 2, root 2, root 3` | Sprite script fires between two root scripts. Ruffle FIFO model — should still pass. |
| `avm1/execution_order2` | Parent-child ordering across gotoAndPlay | Goto path: relies on `ng_run_deferred_sprite_init_*` staying intact. |
| `avm1/variable_args` | Function `arguments` semantics in sprite DoAction | If the sprite body runs at a different global state, args may resolve differently. |
| `avm1/define_function2_preload_order` | Preload register ordering in sprite DoAction | Same as above — sprite state at DoAction time must match Ruffle. |

Additional high-sensitivity tests:

| Test | Why |
|---|---|
| `avm1/execution_order3` | Goto 3-phase path. |
| `avm1/execution_order4` | Nested `clip1.child` — depends on Phase 1 eager so child exists at parent DoAction. |
| `avm1/goto_execution_order2` | 3-phase deferred sprite init. |
| `avm1/clip_events` | Canonical clip-event ordering spec (19 lines). |
| `avm1/issue_1104` | Per-tick `enterframe` eligibility. |
| `avm1/register_and_init_order` (233 lines) | Constructor + DoInitAction ordering — explicit `SESSION_NOTES.md:89–93` rationale. |
| `avm1/on_construct` | CONSTRUCT clip event ordering. |
| `avm1/stage_object_enumerate` | **Currently failing**; same `RUFFLE_VS_FLASH_DIFFERENCES.md` block documents this is the test that *would be fixed* by eager execution. A2 may flip this to pass. |

The four canary tests in `RUFFLE_VS_FLASH_DIFFERENCES.md:17–27` are the blocker. The rationale there was written when sprite scripts had no `!catch_up_mode` guard — that's no longer true (added at `swf.cpp:4938`). It's worth re-running each canary under A2 before assuming any of them break.

### Implementation order for Part A

1. Read each canary test's `output.txt` + `test.xml` to understand its exact tag stream. Predict the FIFO-order output.
2. Factor `finalize_sprite_at_depth` out of `process_sprite_init_at_depth`. Verify no behaviour change with the full AVM1 canary set (local runs).
3. Add the new eager-Phase-2 block to `tagPlaceObject2` (and `tagPlaceObject3`/`tagPlaceObject2Ratio`). Keep existing deferred-goto path intact via `!catch_up_mode` gate.
4. Run canaries locally. Expect `stage_object_enumerate` to flip to pass, others to stay green. If any canary fails, stop and diagnose before Step 5.
5. Change recompiler to emit root DoAction calls inline. Run canaries again. Then run `doactionorder/doactionorder` — expected to pass (A→sprite→B).
6. Commit. Push. Trigger CI. Verify no net regressions across all four suites.

### Bonus: likely fix for `avm1/stage_object_enumerate`

`RUFFLE_VS_FLASH_DIFFERENCES.md:17–27` documents this test is the reverse of the four canaries: it *fails today because of* the Phase 1/Phase 2 split. Under A2 it should flip to pass.

---

## Part B — `moviecliploader`

### Diff (baseline 2026-04-17)

```
expected:                              actual:
loading started                        loading started
loader frame 2                         onLoadStart _level0.content    <-- too early
onLoadStart _level0.content            onLoadComplete _level0.content
onLoadComplete _level0.content         loadee frame 1
loadee frame 1                         onLoadInit _level0.content
onLoadInit _level0.content             loader frame 2                 <-- trailing
loadee frame 2                         <end>
```

Loader is the root, a 2-frame MC. Frame 1 calls `mcl.loadClip(url, target)`, traces "loading started". Frame 2 traces "loader frame 2".

### Current architecture

`SWFModernRuntime/src/actionmodern/action.c`:
- `builtin_mcl_loadClip` (**lines 24367–24461**) enqueues into `g_pending_mcl_loads[]` (line 24247). Returns synchronously; nothing fires.
- `actionFirePendingLoadInits` (**lines 24617–24831**) snapshots + zeros the queue, then runs in one call:
  - Phase 1 (FIFO, 24659–24725): `onLoadStart`, `onLoadProgress`, `onLoadComplete` per-load.
  - Phase 2 (FIFO, 24727–24793): switch context to child SWF; call `entry->init_func` then `frame_funcs[0]`; restore context. (This is where "loadee frame 1" traces come from.)
  - Phase 3 (LIFO, 24795–24830): `onLoadInit`/`onLoadError` per-load.

`SWFModernRuntime/src/libswf/tag.c` `tagShowFrame` NO_GRAPHICS branch (**lines 2048–2111**):
```
actionFirePendingUnloads
ng_sync_root_display_obj
process_sprite_needs_init(root)
ng_fire_pending_loads
ng_fire_pending_attach_inits
actionFlushPendingOnLoads
actionFirePendingLoadInits        <-- drains MCL queue
tagFlushPendingEnterFrame
upgrade_sprite_initialized
g_root_enterframe_eligible = 1
```

So `actionFirePendingLoadInits` drains at the end of the SAME frame's `tagShowFrame` that saw `loadClip`. Need to defer one tick.

### Flash vs Ruffle semantics

Ruffle's own behaviour (`~/CC/ruffle/core/src/loader.rs`):
- `loadClip` spawns an async future. Future body (`:636–706`) runs `movie_loader_start` (fires `onLoadStart` synchronously, `:683–686`) **before** awaiting fetch. Then `fetch.await` → `on_success` → `movie_loader_data` → `preload_tick` → `movie_loader_progress` + `movie_loader_complete`.
- Test harness (`tests/framework/src/runner.rs:210–232`) polls executor AFTER `run_frame` returns → so all MCL events fire on the tick AFTER the one that called `loadClip`.
- But `onLoadStart` fires **before** the next tick's `run_frame` (because `preload_tick` runs at start of frame) → Ruffle's own output is `onLoadStart, onLoadComplete, loadee frame 1, loader frame 2, onLoadInit, loadee frame 2`. Different from Flash's expected `loader frame 2, onLoadStart, onLoadComplete, loadee frame 1, onLoadInit, loadee frame 2`.
- Upstream Ruffle marks this test `known_failure = true` in `test.toml` with a cross-ref to Ruffle issue 12273.

So **Flash's semantics go even further** than Ruffle: MCL events drain *after* the loader's next-frame DoAction, not before. We need to match Flash, not Ruffle.

### Target architecture — two-bucket queue with end-of-tick firing

Two changes in `action.c` + one in `swf_core.c` + one in `tag.c`.

1. **Split `g_pending_mcl_loads` into two buckets**
   - `g_pending_mcl_loads_next_tick[]` — freshly queued (what `loadClip` writes to).
   - `g_pending_mcl_loads_this_tick[]` — ready to fire (what `actionFirePendingLoadInits` drains).
   - Both use the existing `PendingMCLLoad` struct.

2. **`builtin_mcl_loadClip`** (action.c:24443)
   - Enqueue into `_next_tick` instead of the single queue.

3. **Promote at top of tick**
   - New function `actionPromotePendingMCLLoads(app_context)` in action.c: move all `_next_tick` entries into `_this_tick`, zero `_next_tick`.
   - Call from `SWFModernRuntime/src/libswf/swf_core.c` at top of the frame loop, right after `actionFinalizePendingRemovals` (**line 792**) and before sprite-frame advance / root frame_func execution. This is the existing top-of-tick hook that `g_deferred_root_goto`, `actionProcessDeferredUnloads`, and pending-removal already use.

4. **Move `actionFirePendingLoadInits` call in tagShowFrame**
   - Currently at `tag.c:2093`. The drain position inside `tagShowFrame` is actually fine — `tagShowFrame` runs at the end of the frame tick, after root/sprite DoActions. The only thing to change is the queue source: drain `_this_tick`, not the combined queue.
   - Under the two-bucket model: on tick N loading → `_next_tick` holds the load. End of tick N: `_this_tick` is empty, nothing fires. Start of tick N+1: `_next_tick` → `_this_tick`. Tick N+1 root frame_func runs (traces `loader frame 2`). End of tick N+1: `actionFirePendingLoadInits` drains `_this_tick` → `onLoadStart, onLoadComplete, loadee frame 1, onLoadInit`. Tick N+2: loadee's frame 2 advances naturally → `loadee frame 2`. ✓

Also keep the secondary drain in `swf_core.c:1093–1097` (the timer-chained safety net) — it should also drain `_this_tick`.

### Edge cases

- **Multiple loadClips in one tick** — all go into `_next_tick`, all promoted together at the top of N+1. FIFO preserved.
- **loadClip from inside onLoadInit (chained loads)** — onLoadInit fires during `actionFirePendingLoadInits` at end of tick N+1. New load enqueues into `_next_tick` → fires on tick N+2. Matches the existing "secondary drain in swf_core.c" behaviour; no functional change for chained cases.
- **loadMovie (non-MCL)** — uses a separate queue `g_pending_direct_loads`/`actionFirePendingDirectLoads` (action.c:17295, swf_core.c:1059). Not affected by this change unless we also need to defer it. We don't — see regression candidates below.
- **Initial root load** — the root's own loadMovie is driven by a different path (startup), not the MCL queue. Unaffected.
- **Goto / catch-up mode** — `actionFirePendingLoadInits` is also called from `ng_run_deferred_sprite_init_impl` (tag.c:4753). Under catch-up, `_this_tick` should ideally be empty — but if a load arrives via timer or script during a catch-up replay, the behaviour should match Flash. Conservatively: keep the drain-point call here too, but promote-at-top-of-tick only happens in swf_core.c's top-of-tick hook. That means loads queued during catch-up just sit in `_next_tick` until the next tick — same as loads queued during a DoAction. ✓

### Risk / regression candidates

Searched passing tests across all four suites. 25 tests exercise MCL/loadMovie, all currently passing:

| Suite | Tests |
|---|---|
| `avm1/` | `loadmovie`, `loadmovie_fail`, `loadmovie_flashvars`, `loadmovie_method`, `loadmovie_registerclass`, `loadmovie_replace_root`, `loadmovie_var_persistence`, `loadmovienum`, `loadmovienum_cross_version_prototype`, `mcl_as_broadcaster`, `mcl_events_swf_version`, `mcl_getprogress`, `mcl_loadclip`, `mcl_loadclip_properties`, `mcl_loadclip_replace_root`, `mcl_mislabeled_target`, `mcl_target_gif87a`, `mcl_target_gif89a`, `mcl_target_jpg`, `mcl_target_png`, `mcl_unloadclip`, `moviecliploader_flashvars`, `unloadmovie`, `unloadmovie_method`, `unloadmovienum` |
| `from_gnash/actionscript.all/` | `MovieClipLoader-v5` (pass), `MovieClipLoader-v6` (pass), `MovieClipLoader-v7`/`v8` (pre-existing mismatch, unrelated) |

Spot-checking their `output.txt`: **none** interleave a loader-MC's next-frame DoAction with the MCL event sequence the way this test does. All either trace just event lines, or trace loadClip-return-values only, or have root-only loaders (no loader frame-2 trace). Risk of regression is low. That said, full CI verification is mandatory.

### Implementation order for Part B

1. Split the queue into two buckets (`action.c` globals + struct accessors).
2. Update `builtin_mcl_loadClip` to enqueue into `_next_tick`.
3. Add `actionPromotePendingMCLLoads`. Call from `swf_core.c` at top-of-tick.
4. Update `actionFirePendingLoadInits` to drain `_this_tick` (no other logic change).
5. Run `avm1/moviecliploader` locally — expect pass.
6. Run the 25 MCL/loadMovie canaries locally — expect all still pass.
7. Commit. Push. Trigger CI. Verify no net regressions.

### Update 2026-05-08 — conditional deferral landed (gates on loader having more frames)

After the failed uniform-deferral attempt below, a refinement gating the
deferral on `is_playing && (current_frame + 1 < g_frame_count)` makes
both target tests work side-by-side:

- `from_shumway/avm1/moviecliploader`: 1/7 → 6/7 lines. The 2-frame loader
  defers MCL events from tick 1 to tick 2's tagShowFrame, so the order
  becomes `loading started, loader frame 2, onLoadStart, onLoadComplete,
  loadee frame 1, onLoadInit`. Still missing `loadee frame 2` (a separate
  Phase 2 bug — `actionFirePendingLoadInits` runs the loadee's
  `frame_funcs[0]` once but doesn't wire the loadee MC into the per-tick
  `advance_sprite_frames` walk that would call `frame_funcs[1]` next tick).
  No ruffle_matched promotion: our diff `{line 7}` is not a subset of
  Ruffle's `{line 2 missing, line 5 extra}`.
- `avm1/loadmovie_var_persistence`: still PASS. 1-frame loader →
  `should_defer = false` → enqueues into `_this_tick` → fires same-tick via
  the existing tagShowFrame drain, exactly matching pre-deferral behaviour.

**Implementation summary** (all in `SWFModernRuntime/`):

- `src/actionmodern/action.c`:
  - Split `g_pending_mcl_loads` into `g_pending_mcl_loads_this_tick` and
    `g_pending_mcl_loads_next_tick` arrays with separate counts; the
    public `g_pending_mcl_load_count` is the sum (for exit-condition
    checks).
  - `builtin_mcl_loadClip` decides bucket via
    `is_playing && (current_frame + 1 < g_frame_count)` and writes to
    the matching array.
  - New `actionPromotePendingMCLLoads(app_context)` moves all
    `_next_tick` entries into `_this_tick` (FIFO preserved).
  - `actionFirePendingLoadInits` drains `_this_tick`.
- `src/libswf/swf_core.c` and `src/libswf/swf_headless.c`:
  - Call `actionPromotePendingMCLLoads` at top-of-tick (after
    `actionFinalizePendingRemovals`).
  - Updated the chained-drain loop to check `_this_tick` only.
  - Added a "last-tick drain" (promote+drain when
    `tick_count >= max_ticks` and `_next_tick` non-empty) so deferred
    loads still fire if a test would otherwise exit before the next tick.
  - Added `g_pending_mcl_load_count == 0` (and
    `g_pending_direct_load_count == 0` in `swf_core.c`) to the
    past-last-frame `quit_swf` exit-condition guard so a tick with
    pending deferred MCL events doesn't break out before the safety-net
    drain runs.

**Regression batteries.** All green:

- 25-test AVM1 MCL/loadMovie battery (loadmovie, loadmovienum, mcl_*,
  unloadmovie* — 25/25 PASS, including loadmovie_var_persistence and
  loadmovie_fail with `num_frames=1`).
- 4-test Gnash actionscript.all `MovieClipLoader-v5..v8` battery (4/4
  effective: 2 PASS + 2 ruffle_matched, unchanged).
- 19-test AVM1 lifecycle/scope/timeline battery (on_construct,
  execution_order2/3, goto_rewind3, as2_super_and_this_v6,
  register_class_return_value, watch, movieclip_state_values/default_state,
  swf5_to_6_cross_call, set_interval, clone_sprite_edittext, tell_target,
  path_string, function_base_clip, goto_methods, movieclip_setmask,
  textsnapshot_available_text, placeobject_occupied_depth — 19/19 PASS).

**Followup.** `loadee frame 2` (line 7 of `moviecliploader` expected
output) requires a separate fix: when `actionFirePendingLoadInits`
Phase 2 runs `entry->frame_funcs[0]`, the target MC needs to be
registered for per-tick frame advancement so `frame_funcs[1]`
(`loadee frame 2`) fires on the next tick. Likely needs a path
analogous to the `actionRegisterLevelAdvance` pattern that already
exists for multi-frame `_levelN` loads. Not in scope for this plan.

### Investigation 2026-05-08 — full one-tick deferral regresses chained-timer tests, REVERTED

Implemented the two-bucket queue exactly as the plan describes (`g_pending_mcl_loads_next_tick` ↔ `g_pending_mcl_loads_this_tick`, `actionPromotePendingMCLLoads` at top-of-tick, `actionFirePendingLoadInits` drains `_this_tick`). Two additional fixes were needed for the deferral to even drain:

- The `quit_swf` exit check in `swf_core.c`'s past-last-frame `else` branch (and the matching one in `swf_headless.c`) didn't include `g_pending_mcl_load_count > 0`, so a 1-frame loader (`quit_swf=1` set at end of frame 1) would `break` out before tick 2's promote+drain ever ran.
- Tests with `num_frames=1` (e.g. `loadmovie_fail`) have only one tick to begin with, so a "last-tick" drain (promote+fire if `tick_count >= max_ticks` and `_next_tick` non-empty) was added to `swf_core.c` and `swf_headless.c` after the safety-net.

**Local result** on the deferral attempt:

- `from_shumway/avm1/moviecliploader`: 1/7 → 6/7 lines (+5). Order now `loading started, loader frame 2, onLoadStart, onLoadComplete, loadee frame 1, onLoadInit, <missing loadee frame 2>`. The trailing `loadee frame 2` is a separate bug — Phase 2 of `actionFirePendingLoadInits` only runs `entry->frame_funcs[0]` once; the loadee MC isn't wired into the per-tick `advance_sprite_frames` walk that would fire `frame_funcs[1]` next tick. **Even with the deferral correct, `moviecliploader` still won't reach 7/7 without separate loadee-timeline-advancement work.**

- `avm1/loadmovie_var_persistence` REGRESSED from PASS (8/8) to MISMATCH (6/8). Test pattern is `frame 1: loadClip(clip1)` → `onLoadComplete listener: setTimeout(t1, 100)` → `t1: traces, loadClip(clip2)` → `clip2's onLoadComplete listener: setTimeout(t2, 100)` → `t2: traces`. With `num_ticks=6`, the deferral adds one tick per chain step; the cumulative `setTimeout(100ms) + 1-tick deferral` push pushes `t2` past tick 6. Lines 7-8 (from `t2`) never trace. Pre-fix produces all 8 lines because MCL events fire same-tick, so the chain only consumes ~5 ticks.

- 24 of 25 MCL/loadMovie canaries still PASS post-deferral (the one regression is `loadmovie_var_persistence`).

**Why this is harder than the plan suggested.** The plan's "spot-check" missed `loadmovie_var_persistence` because the test source isn't in the test directory (only the compiled `.swf` files), and the `output.txt` doesn't superficially look "interleave-sensitive." But the test's expected output (`Loading clip1.swf` → clip1 frame trace → listener trace via timer → `Loading clip2.swf` → clip2 frame trace → listener trace via timer) implicitly relies on:

  (a) MCL events firing same-tick as `loadClip` (so `onLoadComplete` listener can schedule `setTimeout` early enough for `t1` to fire within `num_ticks`), AND
  (b) Phase 2 (loadee `frame_funcs[0]`) firing AFTER Phase 1 (`onLoadComplete` listener) — actually our impl has the right order for THIS test's listener sequencing because the listener only schedules a timer (no traces) and Phase 2 is what traces "Set exampleVariable".

So the constraints are mutually exclusive within a single uniform-deferral strategy:

- **moviecliploader**: needs MCL events deferred by 1 tick so loader's frame 2 DoAction runs first.
- **loadmovie_var_persistence**: needs MCL events same-tick so chained `setTimeout`-driven loadClips fit within `num_ticks=6`.

**Possible refinement (not yet attempted).** Defer only when the loader has more frames left to play (`current_frame + 1 < g_frame_count`), else fire same-tick. This would preserve same-tick semantics for 1-frame loaders (loadmovie_var_persistence) while deferring for multi-frame (moviecliploader). Implementation: at `tagShowFrame`'s `actionFirePendingLoadInits` call, pass a flag indicating whether to drain everything or only previous-tick entries; or split the drain by load entry's enqueue-tick. Risk: tests with 2-frame roots that DON'T expect deferral would break. Needs more spot-checking before attempting.

**Reverted.** All changes backed out via `git checkout`. State is back to baseline. Effective pass rate unchanged.

---

## Sequencing

Recommend **Part B first**, Part A second.

Rationale: Part B is self-contained to the MCL subsystem, has low regression surface (25 tests, none observed to interleave), and yields a clean +1 on both sub-trees. Part A is a larger architectural change with documented historical sensitivity (4 canaries) and a non-trivial goto-interaction story — safer to land when Part B is already green so any regression is unambiguously attributable.

Both parts together: +2 tests in `from_shumway/avm1/` (to 46/47 = 97.9% filtered) and +1 likely in `avm1/` (`stage_object_enumerate` flip).

## Handoff

This plan is actionable in `incomplete/` — a future session can pick up either part independently. Each part has a baseline-verified root cause, a specific file:line change list, a named canary test set, and a sequencing order.

---

## Implementation progress — 2026-04-17 session

### Part B — landed, then reverted (commits `1a1bf852` + revert `59533be3`)

Two-bucket MCL queue + top-of-tick promotion + final drain + soft tick cap. All 25 MCL/loadMovie canaries passed locally. `from_shumway/avm1/moviecliploader` improved from 1/7 to 6/7 matching lines.

**However, CI revealed 3 AVM1 suite regressions** not caught by the 25-test local canary:
- `movieclip_invalid_get_bounds_1` (75/75 → 8/75, runtime_error: `free(): unaligned chunk detected`)
- `movieclip_invalid_get_bounds_2` (75/75 → 8/75, same heap corruption)
- `string_paths_eval2` (7/7 → 2/7, output mismatch — `setInterval` chained off `onLoadComplete` no longer fires in time)

Local reproduction confirmed: reverting only the `_next` → `_this` enqueue split (keeping everything else) makes all 3 pass again. The regressions are not heap bugs in Part B per se — they are latent interactions that the one-tick deferral exposes:
- `movieclip_invalid_get_bounds_1/2` do repeated `loadClip`s across 150 frames, hitting a use-after-free pattern when events fire one tick after the load was queued rather than same-tick.
- `string_paths_eval2` uses `setInterval(300ms)` inside `onLoadComplete`; `num_frames=5` at FPS=12 (~83ms/tick) means the timer needs ticks 0-4 under the old same-tick model but tick 5+ under deferred model. Soft tick cap (MCL pending only) doesn't extend because MCL queue is empty by then.

**Decision**: revert Part B. The net change (−3 AVM1 tests passing, +0 shumway tests passing since moviecliploader is still 6/7 not 7/7) is negative. A future attempt needs either (a) fixing the latent use-after-free in getBounds handling so deferred events don't trigger it, (b) a wider tick cap (full `hasActiveTimers()` gate) coupled with fixing the long-run lifecycle bugs that such a cap exposes, or (c) Approach A3 (full ActionQueue) which may obviate the two-bucket queue entirely since the new queue itself would handle the ordering.

### Part A — attempted A2, reverted

Implemented:
1. Recompiler emitted each root `SWF_TAG_DO_ACTION` call inline at tag position (advancing `last_queued_script` to keep the three flush loops as no-ops).
2. Runtime added an eager Phase 2 block at the end of `tagPlaceObject2` / `tagPlaceObject2Ratio` that called `process_sprite_init_at_depth` for `sprite_needs_init==2` at top level + `!catch_up_mode` + `!g_defer_sprite_init`.

Outcome: `from_shumway/avm1/doactionorder/doactionorder` improved from 3/7 to 6/7, but the single remaining diff revealed the **fundamental incompatibility of Approach A2 with Ruffle's model**. 6 tests from the RUFFLE_VS_FLASH_DIFFERENCES.md:17–27 canary list regressed:

| Test | Why |
|---|---|
| `execution_order1` | Root DoAction B reads sprite property set by nested DoAction — A2 runs sprite Phase 2 too early |
| `execution_order4` | Same class of ordering — parent/nested-child visibility |
| `clip_events` | CLIP_EVENT_LOAD fires at a different point relative to root DoAction |
| `register_and_init_order` | RegisterClass constructor ordering interacts with Phase 2 |
| `variable_args` | `arguments` object visibility in sprite DoAction depends on Phase 2 position |
| `define_function2_preload_order` | Preload register layout depends on script execution relative to placements |

**Key insight from `doactionorder` diff**: even the target test isn't fully fixed by A2. The expected output has `sym1: _level0.sym1` on line 2 — root1's first access to `sym1` sees the sprite already placed. Under Ruffle's model (`~/CC/ruffle/core/src/display_object/movie_clip.rs:1282–1492`) ALL tags are processed (placements immediate, DoActions queued) BEFORE the queue drains. So by the time root1 runs, sym1 has been placed. A2's inline-execution of root DoAction runs it BEFORE the subsequent `PlaceObject2`, so sym1 isn't placed yet → `sym1: undefined`.

A2 changes reverted. Current state matches Part B only.

### Part A — revised plan: **Approach A3 (true ActionQueue)**

The only implementation that actually matches Ruffle's semantics is a unified FIFO ActionQueue. Concretely:

1. **Runtime** (`SWFModernRuntime/src/actionmodern/action.c` or a new `action_queue.c`):
   ```c
   typedef void (*ScriptFunc)(SWFAppContext*);
   void actionQueueScript(ScriptFunc fn);   // push onto FIFO
   void actionDrainActionQueue(SWFAppContext*);  // pop & run until empty
   ```
   Static array-backed queue (MAX ~64). Drain processes re-queued scripts too.

2. **Recompiler** (`SWFRecomp/src/swf.cpp`):
   - In `SWF_TAG_DO_ACTION` (line 2527), emit `actionQueueScript(script_<N>);` inline at tag position (NOT a direct call).
   - In sprite `SWF_TAG_DO_ACTION` inside `SWF_TAG_DEFINE_SPRITE` (line 4914), also emit `actionQueueScript(script_<N>);` — and REMOVE the current `if (!catch_up_mode) script_<N>(app_context);` pattern. The queue itself becomes the gate: queueing happens during Phase 1, and scripts run only when the drain is invoked.
   - At `SWF_TAG_SHOW_FRAME` (line 850), emit `actionDrainActionQueue(app_context);` BEFORE `tagShowFrame`.
   - Also drain at `SWF_TAG_END_TAG` / early-exit.
   - Remove the three flush loops at lines 548–556, 807–815, 861–868.

3. **Runtime — sprite Phase 2 removal**:
   - `process_sprite_init_at_depth` currently re-runs sprite frame_0 with `g_script_only_mode=1` to execute scripts. Under A3, scripts queue themselves during Phase 1 so there's no need for Phase 2 frame_funcs[0] re-run. But the other Phase 2 side effects (CLIP_EVENT_LOAD, `actionQueueMCOnLoad`, `sprite_initialized=1`, `process_sprite_needs_init` child recurse) still need to happen.
   - Factor them into a separate `finalize_sprite_after_placement` helper called from `tagPlaceObject2` (once, at top level) AND keep `process_sprite_init_at_depth` callable from the goto 3-phase paths.

4. **Goto catch-up interaction**:
   - During `catch_up_mode`, `actionQueueScript` should queue BUT never drain inside the catch-up. Intermediate frames' scripts go into the queue, but before draining, they should be discarded? Or: gate queueing itself on `!catch_up_mode`. This is probably the right move since the existing `!catch_up_mode` gate in sprite frame bodies protects against catch-up script execution. Preserve that: emit `if (!catch_up_mode || g_tag_skip_mode) actionQueueScript(script_<N>);` for root DoActions, and `if (!catch_up_mode) actionQueueScript(script_<N>);` for sprite DoActions.
   - `g_tag_skip_mode` = target-frame-replay mode. Scripts need to queue there (and drain at that frame's ShowFrame). Current recompiler already uses this gate correctly.

5. **`tagShowFrame` changes**:
   - Between `actionFirePendingUnloads` and `process_sprite_needs_init`, add `actionDrainActionQueue(app_context)` as a safety drain for any queued scripts from within tag processing. (Or move the drain to a single call site in the recompiler-emitted frame function right before `tagShowFrame`.)
   - `process_sprite_needs_init` still runs to handle onLoad / queueMCOnLoad / sprite_initialized upgrades for sprites placed during this frame.

### Recommended next session sequence

1. Implement Runtime queue API (~50 lines).
2. Implement Recompiler changes (~30 lines of edits to swf.cpp).
3. Run the 6-test canary set (`execution_order{1,4}`, `clip_events`, `register_and_init_order`, `variable_args`, `define_function2_preload_order`) to verify A3 matches their expectations.
4. Run `from_shumway/avm1/doactionorder/doactionorder` — expect 7/7.
5. Run `from_shumway/avm1/moviecliploader` — still 6/7 (Part C addresses the last line).
6. Run the rest of the AVM1 canary set. Expect `stage_object_enumerate` to flip to pass.
7. Commit. Trigger full CI. Verify no net regressions.

### Part C (new) — child-SWF multi-frame advance

Blocker for `from_shumway/avm1/moviecliploader` line 7 (`loadee frame 2`). After Phase 2 of `actionFirePendingLoadInits` runs `entry->init_func` + `entry->frame_funcs[0]` in the target MC's context, there's no mechanism for `entry->frame_funcs[1..N-1]` to run on subsequent ticks. The target MC needs its `sprite_frame_funcs` + `sprite_frame_count` bound to `entry`'s frame functions, and `sprite_is_playing` set, so `advance_sprite_frames` picks it up.

Rough sketch: in `actionFirePendingLoadInits` Phase 2, after running `frame_funcs[0]`, also set:
- `target_mc->sprite_frame_funcs = entry->frame_funcs`
- `target_mc->sprite_frame_count = entry->frame_count`
- `target_mc->sprite_current_frame = 1` (next tick runs frame_funcs[1])
- `target_mc->sprite_is_playing = 1`

Or equivalently — pre-create a synthetic DisplayObject in parent's DL that points at `entry`'s frame functions. Verify against `loadmovie_replace_root` and `loadmovie_var_persistence` which work today without multi-frame advance because their tests don't poke at it.
