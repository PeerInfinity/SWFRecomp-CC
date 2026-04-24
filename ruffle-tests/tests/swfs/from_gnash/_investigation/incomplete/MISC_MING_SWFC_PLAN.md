# misc-ming / misc-swfc Failure Plan
<!-- TESTS: BeginBitmapFill, ButtonEventsTest, ButtonPropertiesTest, DefineEditTextTest, DefineEditTextVariableNameTest, DefineEditTextVariableNameTest2, DefineTextTest, DepthLimitsTest, DragDropTest, DrawingApiTest, EmbeddedFontTest, NetStream-SquareTest, ResolveEventsTest, RollOverOutTest, Version4Loader, action_order/ActionOrderTest3, action_order/ActionOrderTest4, action_order/ActionOrderTest5, action_order/action_execution_order_test11, action_order/action_execution_order_test2, action_order/action_execution_order_test3, action_order/action_execution_order_test5, action_order/action_execution_order_test6, action_order/action_execution_order_test8-v5, action_order/action_execution_order_test8-v6, attachImported, attachMovieLoopingTest, attachMovieTest, consecutive_goto_frame_test, displaylist_depths/displaylist_depths_test, displaylist_depths/displaylist_depths_test11, displaylist_depths/displaylist_depths_test2, displaylist_depths/displaylist_depths_test3, displaylist_depths/displaylist_depths_test8, displaylist_depths/displaylist_depths_test9, duplicate_movie_clip_test, duplicate_movie_clip_test2, event_handler_scope_test, frame_label_test, get_frame_number_test, goto_frame_test, instanceNameTest, key_event_test, loading/LoadVarsTest, loading/loadMovieTest, loop/loop_test, loop/loop_test10, loop/loop_test2, loop/loop_test3, loop/loop_test4, loop/loop_test5, loop/loop_test6, loop/loop_test7, loop/loop_test8, loop/loop_test9, masks_test, matrix_test, new_child_in_unload_test, opcode_guard_test, place_and_remove_object_insane_test, place_and_remove_object_test, register_class/RegisterClassTest3, register_class/RegisterClassTest4, register_class/registerClassTest, register_class/registerClassTest2, replace_buttons1test, replace_shapes1test, replace_sprites1test, reverse_execute_PlaceObject2_test1, reverse_execute_PlaceObject2_test2, shape_test, static_vs_dynamic1, static_vs_dynamic2, timeline_var_test, button_test1, edittext_test1, mouse_drag_test, movieclip_destruction_test2, movieclip_destruction_test4, opcode_guard_test2, soft_reference_test1, sound, stackscope, submoviegetvar, swf4opcode -->

<!-- PLAN_META
id: MISC_MING_SWFC
status: in_progress
phases:
  - id: 1
    name: "Near-passing (>=80%) attack — low risk, broad win"
    status: pending
  - id: 2
    name: "Mid-rate (10-80%) cluster fixes"
    status: pending
  - id: 3
    name: "Zero-output tests — DoInitAction architectural fix"
    status: blocked
dependencies: [DEJAGNU_FRAMEWORK]
blockers:
  - reason: "Phase 3 only: 7 zero-output tests blocked on DoInitAction-for-unplaced-library-exports; see complete/DEJAGNU_FRAMEWORK_PLAN.md. Phases 1 and 2 are actionable and cover ~76 of the ~83 failing tests."
-->

Covers **misc-ming.all** (74 failing / 102 total) and **misc-swfc.all** (11 failing / 16 total). Both suites use the inlined-Dejagnu harness described in `complete/DEJAGNU_FRAMEWORK_PLAN.md`.

Status (CI at 82a6ea07): **Phase 3 blocked for ~7 tests; Phases 1–2 actionable and cover the remaining ~76 tests.**

## Key finding: the blocker is not universal

`complete/DEJAGNU_FRAMEWORK_PLAN.md` describes a DoInitAction blocker that prevents the inlined Dejagnu check functions from being defined. That plan claims "Most failing tests produce zero PASSED/FAILED output despite executing."

That's no longer accurate. At the 82a6ea07 CI snapshot, of the 85 combined failures across misc-ming and misc-swfc, **only 7 produce zero output**:

| Test | Suite | Status | Lines |
|------|-------|--------|-------|
| BeginBitmapFill | misc-ming | output_mismatch | 0/1 |
| Version4Loader | misc-ming | output_mismatch | 0/11 |
| frame_label_test | misc-ming | output_mismatch | 0/17 |
| replace_buttons1test | misc-ming | output_mismatch | 0/24 |
| replace_shapes1test | misc-ming | output_mismatch | 0/26 |
| action_order/action_execution_order_test6 | misc-ming | output_mismatch | 0/24 |
| loading/LoadVarsTest | misc-ming | compile_fail | — |
| submoviegetvar | misc-swfc | output_mismatch | 0/4 |
| opcode_guard_test2 | misc-swfc | runtime_error | — |

The other ~76 tests produce *some* output — they're running, their Dejagnu check functions *are* being defined, and they're emitting PASSED/FAILED lines. The DoInitAction blocker either doesn't apply to them, or applies only partially. This changes the plan substantially.

## Phase 1 — Near-passing attack (7 tests, >=80% match)

These are one or two small fixes away from passing. Tackle these first for broad gains.

| Test | Match | Matching | Total | Status |
|------|-------|----------|-------|--------|
| DefineEditTextTest (misc-ming) | 95.4% | 146 | 153 | **PASS** (2026-04-21) — hasOwnProperty hides TextField native props on instance |
| matrix_test (misc-ming) | 83.6% | 908 | 1086 | Incomplete — matrix-after-negative-_yscale diffs (`d` sign/value mismatch), `getBounds` after scale-with-rotation, and `sin(90°)` `6e-17` residuals. Not a single fix. |
| get_frame_number_test (misc-ming) | 87.1% | 27 | 31 | **PASS** (2026-04-22) — `actionGotoFrame2` now handles non-integer Number args by coercing to string, trying frame label lookup, then strict integer parse. Mirrors Flash's observable behavior (Ruffle panics on this test, `known_failure.panic`). |
| shape_test (misc-ming) | 71.4% | 15 | 21 | **PASS** (2026-04-22) — three-part fix for Flash's shape-alias quirk: (1) `getInstanceAtDepth` no longer returns the parent MC for `_found_type == 1` (shape/morph/static-text) placements — falls through to undefined. (2) In the scan-child-mc-cache loop, cached shape MCs are skipped so shapes with their own MC entry also return undefined. (3) `actionGetVariable` / `resolveSlashPathToMC` now set `g_shape_alias_resolution = 1` whenever a shape's instance name resolves to its parent MC (via the existing `ng_isScriptableAtDepth == false` branches). The `getDepth` method handler in `actionCallMethod` consumes the flag: on a shape-aliased receiver it pushes undefined, matching Flash's `typeof(sh.getDepth()) == 'undefined'`. Property access like `sh.var = 10` / `sh._x` still lands on the parent MC unchanged. |
| RollOverOutTest (misc-ming) | 80.0% | 4 | 5 | Skipped — requires mouse input simulation via `input.json`; our runner doesn't drive input. |
| displaylist_depths_test11 (misc-ming) | 60.0% | 9 | 15 | **PASS** (2026-04-22) — MovieClip survives-rewind implementation: during backward goto catch-up, initialized sprites placed at later frames whose char_id + ratio match the target frame's placement are preserved (name, constructor state) instead of being cleared and re-created. Mirrors Ruffle `MovieClip::survives_rewind` + `apply_place_object` comment ("name... can not be modified by subsequent PlaceObject tags"). Four-part fix across `libswf/tag.c` and `libswf/swf_core.c`/`swf_headless.c`: (1) `ng_display_clear_after` now preserves entries with `sprite_display_list != NULL` (initialized MovieClips). (2) `tagPlaceObject2`/`tagPlaceObject2Ratio` backward catch-up branch checks `(char_id == existing) && (ratio == existing)` — if matches, modify path (preserves instance_name, clears `g_pending_instance_name` BEFORE `ng_on_place_object2` so it doesn't consume the pending name). If not matches AND existing `placed_at_frame > catch_up_target` (truly stale from pre-rewind state), clear and fall through to full placement. If not matches but within `[0, target]` (earlier catch-up replay), skip (preserves previous behavior). (3) `tagSetInstanceName` during `catch_up_backward` with `placed_at_frame > current_frame` pends the name but doesn't rename in-place (Ruffle doesn't update name on surviving children). Also gated on `g_tag_skip_mode` so the deferred target-frame replay doesn't re-rename. (4) Post-catch-up cleanup `ng_display_cleanup_unplaced_after` clears sprites whose depth wasn't re-placed (effectively failed survives_rewind). No regressions on a 44-test AVM1 rewind/unload/placement/MC-lifecycle battery + Shumway duplicateMovieClip. |
| edittext_test1 (misc-swfc) | 76.6% | 36 | 47 | **PASS** (2026-04-22) — Three-part TextField binding fix: (1) `actionSetMember` on root now calls `ng_syncVarToTextFields` so `_root.varName = X` propagates to bound textfields; (2) `.variable = "newName"` rebind creates the new var as an own property on root.dynamic_props so `hasOwnProperty(newName)` is true; (3) `ng_syncTextToVar` simple-name path now mirrors into root.dynamic_props so `_root.varName` always reads the current textfield text. |
| attachMovieTest (misc-ming) | 75.0% | 9 | 12 | **PASS** (2026-04-22) — `attachMovie` now skips the init-object property loop when the attached symbol is a Button (`attached->is_button_mc`). Flash behavior: the init object is not used for Buttons (test comment: "init object is not used for Buttons"). Both the CallFunction (`attachMovie` global) and CallMethod (`mc.attachMovie`) paths updated in `action.c`. No regressions on AVM1 `attach_movie` / `attach_movie_stop` / `empty_movieclip_can_attach_movies` / `init_object_invalid` / `init_object_order` / `movieclip_init_object` / `button_children` / `clip_events`. |
| place_and_remove_object_test (misc-ming) | 76.9% | 10 | 13 | **PASS** (2026-04-22) — `tagSetInstanceName` now also sets `g_pending_instance_name` in the path where the display entry already exists, so a subsequent `tagPlaceObject2` that replaces the old character with a different `char_id` preserves the just-assigned name. Without this, the full-placement path in `tagPlaceObject2` wiped `instance_name` to NULL when `g_pending_instance_name` was NULL — losing `sh1` on loopback when frame 0 replaced frame 2's sh2 at depth 3. Verified no regressions on AVM1 `access_unnamed_shape`, `conflicting_instance_names`, `default_names`, `depth_replacement_audio_unloading`, `movieclip_depth_methods`, `movieclip_get_instance_at_depth`, `movieclip_name_from_timeline`, `named_shapes`, `place_and_lookup`, `bad_placeobject_clipaction`, `clip_events`, `register_and_init_order`, `goto_rewind3`, `execution_order3`, `goto_execution_order2`, `movieclip_in_removed_button`, `unload`, `on_construct`, `movieclip_state_values`. |
| static_vs_dynamic1 (misc-ming) | 82.4% | 14 | 17 | **PASS** (2026-04-23) — `actionRewindCleanup` now keys the survives_rewind decision for display-list-less clones off the clone's *registered* SWF depth (via new `ng_clone_get_swf_depth` lookup into `g_clone_depth_table`), not `ch->depth`. `swapDepths` (all three dispatch paths) calls new `ng_clone_update_swf_depth` to keep the table in sync when a clone is moved. See "survives_rewind via clone_depth_table" below. |

For each, run `--diff --verbose` and cluster the diff lines by type. Many will resolve with a single targeted fix that's shared across a handful of near-passing tests.

### loop_test7 — deferred CLIP_EVENT_UNLOAD clip actions (2026-04-23, attempted and reverted)

- **loop/loop_test7 (misc-ming) — attempted fix reverted.** Flash (and
  Ruffle, per `core/src/display_object/movie_clip.rs:2849`) queues
  tag-level `CLIP_EVENT_UNLOAD` clip actions on the action queue with
  `is_unload=true` rather than firing them inline when `RemoveObject2`
  runs. The test's gnash source calls this out explicitly:
  *"RemoveObject2 tag is after the DoAction tag which contains the
  following check. So it's not surprise that we can still access
  movieClip1 here when considering the global ActionQueue model!"*.
  Our `tagRemoveObject2` fires the unload inline, so the
  "_level0.movieClip1 unloaded" trace prints **between** the two
  already-queued DoAction scripts instead of after them.
- **Attempted fix (reverted in this session):** added
  `actionQueueClipUnload(fn, mc)` helper and routed the primary
  `clip_action_count` loop in `tagRemoveObject2` through it
  (deferred via `AQ_KIND_ONLOAD` / `is_unload=1`, drained at
  `actionFirePendingUnloads` during `tagShowFrame`). `loop_test7`
  flipped `output_mismatch` → `ruffle_matched` in isolation.
- **Why reverted:** deferring only the tag-level clip-action inverted
  the order on `avm1/unload_clip_event` and `avm1/clip_events`. Both
  tests expect the tag-level `UNLOAD` ("clipEvent" / "clip unload")
  trace *before* the AS-level `onUnload` ("handler" / "clip onUnload")
  trace. `actionFireOnUnload` (invoked from `ng_on_remove_object`)
  still fires the AS-level handler inline, so the inline handler
  prints before the deferred clip-action. Additionally deferring
  `actionFireOnUnload` (via a `queueOnUnload` call) fixed those two
  tests but regressed `avm1/unload`: `Unload clip5` slipped from
  end-of-frame-1 to end-of-frame-2, suggesting the deferred AS-level
  handler's target MC state is being cleared by
  `actionMarkMCPendingRemoval` / `clear_display_entry` between
  queue-time and frame-1 drain-time in a way that prevents the
  handler from firing at the intended `tagShowFrame`.
- **Blocker for future session:** a clean fix needs to defer *both*
  tag-level clip-action `UNLOAD` *and* AS-level `onUnload` to the
  action queue (ordered clip-action first, `onUnload` second) **and**
  ensure the `MovieClip`'s state survives until the deferred drain.
  The latter is non-trivial — `actionMarkMCPendingRemoval` +
  `clear_display_entry` run immediately after `actionFireOnUnload`
  inside `tagRemoveObject2`, and anything the deferred handler
  touches (dynamic_props, display children, etc.) must still be
  reachable at drain time. Likely requires restructuring so the
  "queue unloads" step leaves the MC live and everything past it
  (pending_removal, `clear_display_entry`, child invalidation)
  moves to a new deferred-finalize step that runs after
  `actionFirePendingUnloads`. Alternatively, attach the MC state the
  AS-level handler needs to the queued payload itself (copy the
  handler + any bindings at queue time, don't rely on live MC state).

### instanceNameTest — empty-name preservation (2026-04-22, not yet in CI)

- **instanceNameTest (misc-ming) → PASS (+1).** SWF's `PlaceObject2` distinguishes "name is present but empty" (HasName bit set, name=`""`) from "no name at all" (HasName bit unset). Ming's `SWFDisplayItem_setName(it, "")` produces the former, and Flash preserves that as `this._target == "/"` (not `/instanceN`). The recompiler's emission sites used `!instance_name_str.empty()` to decide whether to emit `tagSetInstanceName`, which collapses "empty name" and "no name" into the same branch — so the empty-named MC fell through to the runtime's auto-naming path and got `instance2`, shifting every subsequent auto-index by one. Fix: seven emission sites in `SWFRecomp/src/swf.cpp` (four in `tag_main`, three in `sprite_definitions`) now gate on `has_name` — which reflects the PlaceObject2 HasName flag — so an explicit empty name produces `tagSetInstanceName(app_context, depth, "")`. The runtime's `tagSetInstanceName` already stores the empty string as a non-NULL pointer, so `ng_on_place_object2` sees `g_pending_instance_name != NULL` and skips auto-naming. No regressions on an 18-test AVM1 placement/name-resolution battery (`access_unnamed_shape`, `conflicting_instance_names`, `default_names`, `named_shapes`, `movieclip_depth_methods`, `movieclip_get_instance_at_depth`, `movieclip_name_from_timeline`, `place_and_lookup`, `bad_placeobject_clipaction`, `clip_events`, `register_and_init_order`, `goto_rewind3`, `execution_order3`, `goto_execution_order2`, `movieclip_in_removed_button`, `unload`, `on_construct`, `movieclip_state_values`) or a cross-check of previously-landed misc-ming fixes (`displaylist_depths_test11`, `place_and_remove_object_test`, `attachMovieTest`, `shape_test`, `get_frame_number_test`, `loop_test5`, `loop_test9`, `static_vs_dynamic2`) or the Shumway duplicateMovieClip suite.

### Sound.position default after attachSound (2026-04-22, not yet in CI)

- **sound (misc-swfc) — partial (+1 line, position==0 check now passes).** `builtin_sound_attachSound` now sets `__loaded__ = true` on the Sound object, mirroring Ruffle's `attach_sound` which calls `sound.load_sound(...)` + `sound.set_position(0)` (`core/src/avm1/globals/sound.rs:395-404`). Without this, `snd.position` returned `undefined` between `attachSound()` and `start()` because the property getter required `__loaded__` to be set (otherwise it fell through to the "own property or undefined" path). With the flag set, the getter reaches `soundGetElapsedForObject(obj)` which returns 0 for inactive sounds. The test still fails overall because it depends on timing-based `gotoAndPlay(8)` logic where we're reaching frame 8 too early (likely an `elapsed_ms` accumulation divergence from gnash), but the `check_equals(snd.position, 0)` assertion now passes. No regressions on the 10-test AVM1 sound suite (`sound`, `sound_duration_position_props`, `sound_id3`, `sound_id3_prop`, `sound_load_start`, `sound_multiple_load`, `sound_props_swf5`, `sound_props_swf6`, `sound_start_load`, `register_class_with_sound`).

### Empty-DL-slot RemoveObject2 fallback (2026-04-22, not yet in CI)

- **static_vs_dynamic2 (misc-ming) → PASS (+1).** Added
  `actionInvalidateMCAtASDepth` helper in
  `SWFModernRuntime/src/actionmodern/action.c`, invoked from
  `tagRemoveObject2` (`SWFModernRuntime/src/libswf/tag.c`) when the
  target display-list slot is empty. The test's sequence
  (`duplicateMovieClip('mc1', 'dup', 1)` → `mc1.swapDepths(dup)` →
  `RemoveObject2` at SWF depth 2) leaves dup at AS depth -16382 but
  without a DL entry (ng_cloneSprite's INITIAL_DISPLAYLIST_CAPACITY
  gate skips placement). The fallback scans `child_mc_cache` for a
  root-level MC whose `depth` matches the tag's AS depth and marks it
  `avm1_removed` + `depth = INT_MIN`. Also clears the global `var_map`
  entry (via `setVariableByName(name, undefined)`), because CloneSprite
  registers the clone's name there and `_root.dup` resolves through
  var_map bypassing the normal display-list/child_mc_cache path — so
  without clearing var_map, `typeof(dup)` still returned `'movieclip'`.
  No regressions on a 47-test AVM1 battery.

### Backward-goto dynamic-depth preservation (2026-04-22, not yet in CI)

- **loop/loop_test9 (misc-ming) → PASS (+1).** Added dynamic-range gate to
  `ng_display_clear_after` in `SWFModernRuntime/src/libswf/tag.c`: the loop
  now `break`s at `i >= 16384`, so display entries at SWF depth >=
  `AVM_DEPTH_BIAS` are preserved across backward jumps. This matches
  Ruffle's `survives_rewind` rule (`core/src/display_object/
  movie_clip.rs:1824`): for AVM1, `old_object.depth() < AVM_DEPTH_BIAS`
  is the precondition for considering an object for removal during
  rewind. Previously we cleared every entry placed after the target
  frame regardless of depth, which killed `movieClip2` (placed at SWF
  depth 30000 = AS 13616) on `gotoAndStop(1)` even though it lives in
  the dynamic range. No regressions on a 45-test battery covering
  AVM1 rewind/unload (`goto_rewind1/2/3`, `execution_order1..4`,
  `goto_execution_order`, `goto_execution_order2`, `unload`,
  `unload_clip_event`, `unload_nested_child`, `unloadmovie`,
  `mcl_unloadclip`, `rewind_depth`, `goto_both_ways1/2`,
  `depth_replacement_audio_unloading`, `textsnapshot_available_text`)
  nor on placement/cache/construct tests
  (`access_unnamed_shape`, `conflicting_instance_names`, `default_names`,
  `movieclip_depth_methods`, `movieclip_get_instance_at_depth`,
  `movieclip_name_from_timeline`, `named_shapes`, `place_and_lookup`,
  `bad_placeobject_clipaction`, `clip_events`,
  `register_and_init_order`, `movieclip_state_values`,
  `movieclip_library_state_values`, `on_construct`,
  `register_class_return_value`, `attach_movie`, `attach_movie_stop`,
  `empty_movieclip_can_attach_movies`, `init_object_invalid`,
  `init_object_order`, `movieclip_init_object`, `button_children`,
  `array_enumerate`, `enumerate`, `swf5_to_6_cross_call`,
  `swf6_to_5_cross_call`, `duplicateMovieClip/dontremove`,
  `duplicateMovieClip/duplicateMovieClip`,
  `duplicateMovieClip/samedepth`, `duplicateMovieClip/name-coercion`).
- **Partial progress on static_vs_dynamic1/2 and loop_test4**:
  - `static_vs_dynamic1` → **PASS** (2026-04-23, see "survives_rewind via
    clone_depth_table" below). The remaining `typeof(dup2)` diff is
    resolved by keying survives_rewind off the clone's *registered* SWF
    depth (stored in `g_clone_depth_table` at CloneSprite time) rather
    than the MC's cached `depth` field, which is a mix of AS-depth and
    SWF-depth conventions depending on the bias heuristic.
  - `loop_test4` still fails (`typeof(movieClip1/2) == undefined` after
    `gotoAndStop(3)`) despite the CONSTRUCT events firing — separate
    from this change; likely a distinct backward-catch-up replacement
    ordering issue (movieClip3 at depth 3 placed frame 5 is cleared;
    movieClip1 replacement's _root name resolution may be the issue).

### survives_rewind via clone_depth_table (2026-04-23, not yet in CI)

- **static_vs_dynamic1 (misc-ming) → PASS (+1).** `actionRewindCleanup` in
  `SWFModernRuntime/src/actionmodern/action.c` now looks up the clone's
  registered SWF depth from `g_clone_depth_table` (via new
  `ng_clone_get_swf_depth` helper exported from `libswf/tag_stubs.c`)
  rather than checking `ch->depth >= 16384`. The table holds the raw
  SWF depth produced by bytecode — whether Ming-style biased (`Push(N)
  Push(16384) Add`) or Shumway-style already-biased (`Push(16385)`) — so
  the >= 16384 test correctly distinguishes dynamic-range clones that
  survive rewind from static-range clones that don't, without the
  Ming-vs-Shumway heuristic ambiguity that the "CloneSprite depth-bias
  trade-off" section below describes. To keep the table in sync when a
  clone is moved post-create, `swapDepths` (both numeric, MC-ref, and
  path-string paths) now calls new `ng_clone_update_swf_depth` after
  updating `mc->depth`. Verified:
    - `static_vs_dynamic1` final `typeof(dup2)` check matches (dup2 at
      SWF 16386 survives, as expected).
    - `from_shumway/avm1/duplicateMovieClip/dontremove` (`test2` at SWF
      16379) still passes (16379 < 16384 → removed, correct).
    - `static_vs_dynamic1`'s `dup1.swapDepths(-10)` updates the table to
      SWF 16374 so dup1 is removed on rewind (was previously 16385 and
      would have regressed).
  No regressions on a 45-test battery covering AVM1 rewind/unload
  (`goto_rewind1/2/3`, `execution_order1/2/3`, `goto_execution_order/2`,
  `goto_both_ways1/2`, `rewind_depth`, `unload`, `unload_clip_event`,
  `unload_nested_child`, `unloadmovie`, `mcl_unloadclip`,
  `depth_replacement_audio_unloading`, `textsnapshot_available_text`,
  `set_interval`, `swf5_to_6_cross_call`, `swf5_no_closure`,
  `swf6_to_5_cross_call`), MC placement/name
  (`movieclip_depth_methods`, `movieclip_get_instance_at_depth`,
  `movieclip_name_from_timeline`, `movieclip_state_values`,
  `movieclip_library_state_values`, `placeobject_occupied_depth`,
  `bad_placeobject_clipaction`, `conflicting_instance_names`,
  `default_names`, `access_unnamed_shape`, `named_shapes`,
  `place_and_lookup`, `button_children`, `movieclip_in_removed_button`,
  `register_and_init_order`, `on_construct`, `init_object_order`,
  `init_object_invalid`, `movieclip_init_object`,
  `coerce_to_object_monkeypatch`, `attach_movie`, `attach_movie_stop`,
  `empty_movieclip_can_attach_movies`, `clip_events`), the Shumway
  duplicateMovieClip suite (`dontremove`, `duplicateMovieClip`,
  `samedepth`, `name-coercion`), and the previously-landed misc-ming
  near-passing tests (`displaylist_depths_test11`,
  `place_and_remove_object_test`, `loop_test5`, `loop_test9`,
  `static_vs_dynamic2`, `shape_test`, `attachMovieTest`,
  `get_frame_number_test`, `instanceNameTest`). The pre-existing
  `duplicate_movie_clip_test2` dup6/dup7/dup8 diffs (nested-path
  `duplicateMovieClip` refusing to fail) are unchanged — those are a
  separate path-resolution bug.

### CloneSprite depth-bias trade-off (open)

Partial fix landed 2026-04-22 (`a232eaf4`, replacing the initial always-unbias
attempt in `8efcb774`). `static_vs_dynamic1`/`static_vs_dynamic2` pick up
the trivial `dup.getDepth() == 1` / `== 2` lines; `displaylist_depths/
displaylist_depths_test`, `DepthLimitsTest`, and other tests that bias
*negative* AS depths (e.g. `Push(-2001) Push(16384) Add → 14383`) are still
off because the gate only strips the bias when the stack value is
`>= AVM_DEPTH_BIAS` (16384).

Why the gate exists: always-unbias (`clone_mc->depth = depth - 16384`)
correctly matches Ruffle's `core/src/avm1/globals/movie_clip.rs::clone_sprite`
semantics, but some SWFs pass `getNextHighestDepth()` directly to
`CloneSprite` without biasing (e.g. the avm1 `textsnapshot_available_text`
test produces a stack value of 0). With always-unbias, those clones end up
at AS depth `-16384`, which collides with `root_movieclip.depth` and causes
downstream lookups to misidentify the clone. Result: the textsnapshot test
regresses by 1 line whenever we try to fully match Ruffle.

**Real fix (punted):** make `actionCloneSprite` responsible for biasing
so `ng_cloneSprite` / `ng_cloneSpriteFromMC` always receive AS depth.
This requires distinguishing the two caller conventions at the bytecode
site (SWF-biased vs. unbiased). Options:

1. Always treat the stack value as SWF-biased — matches Ruffle but
   requires fixing whatever breaks when clones live at `mc->depth ==
   -16384` (likely the `ch == &root_movieclip` identity checks elsewhere
   that currently conflate "root" with "AS depth -16384"). That's the
   architecturally correct path.
2. Detect bias via a version / compiler hint — fragile; nothing in the
   bytecode distinguishes Ming's `Push(N) Push(16384) Add` from a direct
   `Push(N+16384)` or from an already-unbiased depth.

Pursuing (1) means auditing runtime identity checks to stop using
`mc->depth == -16384` as a proxy for "is root" (use the pointer identity
`mc == &root_movieclip` instead) and confirming `clone_depth_register` /
`actionInvalidateCachedMovieClip` tolerate negative AS depths.

## Phase 2 — Mid-rate cluster fixes

Failures at 10-80% match, grouped by apparent feature cluster. The cluster shape suggests which existing subsystem is being stressed:

### Cluster: `action_order/*` (10 tests, 0-73%)

Deferred-DoAction / sprite-init execution order. Similar to the AVM1 `execution_order*` fixes in `avm1/_investigation/complete/SESSION_NOTES.md`. The long tail (ActionOrderTest3 at 5.7%, ActionOrderTest4 at 7.4%) likely combines multiple ordering bugs.

- **action_execution_order_test8-v5/v6 (misc-ming) → PASS (+2, 2026-04-23, not yet in CI).** Tightened the Phase 3 filter in `process_sprite_needs_init` (tag.c) from `placed_at_frame >= target_frame` to `placed_at_frame == target_frame`. The `>=` semantics was wrong under nested gotos: when frame 2's DoAction calls `gotoAndPlay(4)` from inside the outer goto's Phase 2 (target=2), `ng_executeGotoCatchUp` for the inner goto runs frames 3–4 immediately and places mc1 at frame 4. With `>=`, the outer Phase 3 (filter `>= 2`) then fires mc1 before the inner goto's Phase 2 runs the target frame's root script — producing mc1's `_root.gotoAndStop(6)` trace *before* the expected "root frame 4" / `typeof(_root.x)=='undefined'` lines. `==` restricts Phase 3 to sprites placed at exactly the goto's own target, leaving mc1 to fire during the inner goto's Phase 3 (target=4). No regressions on a 54-test AVM1 execution-order/rewind/clip-event battery, the Gnash action_order cluster (7 pre-existing failures unchanged — line counts identical), the Shumway duplicateMovieClip suite, or a 12-test misc-ming battery (`displaylist_depths_test11`, `place_and_remove_object_test`, `loop_test5/9`, `static_vs_dynamic1/2`, `shape_test`, `attachMovieTest`, `get_frame_number_test`, `instanceNameTest`, `test8-v5/v6`).

### Cluster: `displaylist_depths/*` (6 tests, 13-80%)

Display list depth transformations, clip_depth, swap_depths, level vs timeline depth math. Overlaps the `movieclip_methods_with_loaded_image` / `attachMovie` / `duplicateMovieClip` surfaces. Near-passing (`test11` at 80%) suggests a single small edge.

### Cluster: `loop/*` (10 tests, 3-73%)

`while` / `for` / `do-while` opcode handling. `loop_test9` at 73% and `loop_test3` at 69% are attack points. `loop_test10` at 3.6% suggests a feature not implemented yet (probably `for-in` or iterator-style).

- **loop_test5 (misc-ming) → PASS (2026-04-22).** After the survives-rewind
  landing boosted it from 13/24 to 21/24, the remaining diff was
  `typeof(movieClip1) == 'movieclip'` returning undefined after the rewind
  re-created movieClip1 at depth 3 (different ratio forced a full replace).
  Root cause was in `actionRewindCleanup` (action.c): for each child MC not
  in the current display list, the code unconditionally set
  `root_movieclip.dynamic_props[name] = UNDEFINED`. For CloneSprite /
  duplicateMovieClip clones that's correct (they live in dynamic_props).
  For timeline-placed MCs it's wrong — the entry later shadows the
  display-list fallback in `actionGetVariable` (a plain UNDEFINED own-prop
  is hit before the `check_special_vars` block that scans
  `ng_findDisplayEntryByName`). Fix: narrow the clear to only happen when
  `dynamic_props[name]` currently points to THIS MC (a MOVIECLIP value
  identifying `ch`), which distinguishes clone registrations from
  incidental entries. No regressions on a 32-test AVM1 rewind/placement/
  attachMovie/register-class/coerce-to-object battery or the 7-test
  misc-ming cluster (displaylist_depths_test11, place_and_remove_object,
  static_vs_dynamic2, loop_test9, loop_test5, shape_test, attachMovieTest)
  or the Shumway duplicateMovieClip suite.

### Cluster: `register_class/*` (4 tests, 4-21%)

`Object.registerClass` combined with attachMovie / frame scripting. Overlaps AVM1's `complete/REGISTERCLASS_PLAN.md`. Low rates suggest the tests exercise edges not covered by AVM1 tests.

### Cluster: `loading/*` (2 tests)

- `loadMovieTest` — 6.2%. Overlaps AVM1 `complete/LOADMOVIE_PLAN.md` (32/35 AVM1 loadMovie tests pass).
- `LoadVarsTest` — compile_fail. Needs recompiler triage separately.

### Cluster: movieclip/timeline (flat) — ~25 tests at 10-80%

Various tests exercising `attachMovie`, `duplicateMovieClip`, `goto`, `unload`. Candidates for near-passing attack:

- `new_child_in_unload_test` (72.7%)
- `timeline_var_test` (72.7%)
- `static_vs_dynamic2` (72.2%) — **PASS** (2026-04-22, see "Empty-DL-slot RemoveObject2 fallback" above)
- `attachMovieLoopingTest` (70.7%)
- `reverse_execute_PlaceObject2_test2` (70.0%)

Also `movieclip_destruction_test2` (73.2%) from misc-swfc.

### Cluster: text / edittext

- `DefineTextTest` (68.8%), `DefineEditTextVariableNameTest*` (60-74%), `EmbeddedFontTest` (57.5%).
- `edittext_test1` (76.6% — near-passing).
Text field property coverage; may overlap AVM1's `TEXTFIELD_PLAN`.

- **DefineEditTextVariableNameTest2 (misc-ming) — partial (+7 lines, 28/36 → 35/36, 2026-04-23 not yet in CI).**
  `ng_syncVarToTextFields` in `SWFModernRuntime/src/actionmodern/action.c` was
  skipping OBJECT/ARRAY/FUNCTION values with a "no side effects" comment, so
  `edit_text_var = new Object()` never propagated to bound textfields — the
  textfield kept its previous string value instead of coercing the object to
  `'[object Object]'` (or the user's Object.prototype.toString result). Ruffle's
  `notify_property_change` (`core/src/avm1/object/stage_object.rs:87`) calls
  `value.coerce_to_string(activation)` on every value type, so the side-effect
  concern is actually part of the observable Flash/Ruffle behavior. Fix: route
  all non-STRING/non-UNDEFINED values (including OBJECT/ARRAY/FUNCTION) through
  `varToStringBuf`, which already invokes `objectCallToString` for OBJECT via
  the type-11 handler at action.c:49049. No regressions on a 12-test AVM1
  edittext/textfield battery (`edittext_html_align_swf7/8`,
  `edittext_html_color`, `edittext_html_swf6/7/8`, `edittext_stylesheet`,
  `clone_sprite_edittext`, `clone_sprite_edittext_dynamic`, `text_format`,
  `text_format_display`, `textsnapshot_available_text`) nor on a
  5-test misc-ming battery (`DefineEditTextVariableNameTest`,
  `DefineEditTextTest`, `DefineTextTest`, `matrix_test`,
  `place_and_remove_object_test` — 2 passing / 3 pre-existing failures unchanged).
  The one remaining failing line in v2 is `typeof(dtext4.text.toString) == 'function'`,
  which fails because string-primitive-to-String.prototype auto-boxing is not
  implemented for GetMember on STRING values (pre-existing limitation, line
  41167 returns undefined for everything except "length" on STRING type).

### Cluster: events / input

- `event_handler_scope_test` (62.5%)
- `ResolveEventsTest` (53.3%)
- `DragDropTest` (40.0%)
- `key_event_test` (13.6%)
- `ButtonEventsTest` (2.4%)
- `mouse_drag_test` (50.0%) — misc-swfc

### Cluster: misc-swfc remainder

- `stackscope` — **PASS** (2026-04-23) — Flash clears the AVM1 action stack at each frame boundary; within a frame, DoAction blocks share a stack and later blocks see leftover pushes from earlier blocks (hence `_root.var1 = val1` propagating from `script_0`'s trailing pushes through `script_1`'s `SetVariable`, same for `var2` flowing cross-sprite from `script_1` to `mc1`'s `script_2`). Between frames the stack must reset, otherwise `_root.var3 / val3` leaked into frame 1's `script_3` and set `_root.var3 = "val3"` — the test's whole point is checking that var3 stays undefined. Our runtime never reset the stack; Ruffle clears it per DoAction (stricter — matches neither our behavior nor Flash, see `output.ruffle.txt` which shows var1/var2 failing as `""`). Fix: add `app_context->sp = INITIAL_SP; app_context->oldSP = 0;` at the top of each tick in `SWFModernRuntime/src/libswf/swf_core.c` (NO_GRAPHICS), `swf_headless.c` (HEADLESS), and `swf.c` (GRAPHICS) — matches Flash exactly. No regressions on a 48-test AVM1 battery (add/this_scoping/enumerate/execution_order1/2/3/goto_rewind1/2/3/goto_frame/goto_label/unload/unload_nested_child/unloadmovie/set_interval/attach_movie/attach_movie_stop/empty_movieclip_can_attach_movies/clip_events/swf5_to_6_cross_call/swf6_to_5_cross_call/swf5_no_closure/init_object_order/init_object_invalid/movieclip_init_object/button_children/mutable_this/register_class_return_value/array_enumerate/coerce_to_object_monkeypatch/register_and_init_order/on_construct/on_construct), on a 9-test misc-ming battery covering recently-fixed tests (displaylist_depths_test11/place_and_remove_object_test/loop_test5/loop_test9/static_vs_dynamic2/shape_test/attachMovieTest/get_frame_number_test/instanceNameTest), or on misc-mtasc `function_test`/`hello`/`enum`/`levels` (levels was already failing pre-change with 23 FAILs; same 23 FAILs after — no regression).
- `swf4opcode` (63.2%)
- `sound` (41.7%)
- `soft_reference_test1` (37.8%)
- `button_test1` (25.8%)
- `movieclip_destruction_test4` (20.0%)
- `opcode_guard_test2` — runtime_error (investigate separately)

## Phase 3 — Blocked zero-output tests (7 tests)

These produce 0 lines of output. They are the tests that *actually* match the DoInitAction blocker description in `complete/DEJAGNU_FRAMEWORK_PLAN.md`:

| Test | Suite | Expected | Status |
|------|-------|----------|--------|
| BeginBitmapFill | misc-ming | 1 | output_mismatch |
| Version4Loader | misc-ming | 11 | output_mismatch |
| frame_label_test | misc-ming | 17 | output_mismatch |
| action_order/action_execution_order_test6 | misc-ming | 24 | output_mismatch |
| replace_buttons1test | misc-ming | 24 | output_mismatch |
| replace_shapes1test | misc-ming | 26 | output_mismatch |
| submoviegetvar | misc-swfc | 4 | output_mismatch |
| loading/LoadVarsTest | misc-ming | — | compile_fail |
| opcode_guard_test2 | misc-swfc | — | runtime_error |

Fix requires the architectural change described in the DEJAGNU_FRAMEWORK_PLAN: run DoInitAction for *all* library exports at SWF load time, not just for placed sprites. This is noted as Phase 3 blocked.

`LoadVarsTest` compile_fail and `opcode_guard_test2` runtime_error need separate triage — they may not be Dejagnu-blocker related.

## Suggested order of operations

1. **Phase 1 (Near-passing, 7 tests)** — highest yield per hour. May also reveal shared fixes that help mid-rate tests.
2. **Phase 2 cluster-by-cluster** — start with `action_order/*` near-passing entries (test8-v5/-v6 at 72.7%), then `loop/*` near-passing, then movieclip cluster near-passing.
3. **Phase 3 DoInitAction architectural fix** — larger, can be scheduled when Phase 1+2 land. Unblocks 7 tests.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `complete/DEJAGNU_FRAMEWORK_PLAN.md` | Describes the original blocker. This plan refines that finding — the blocker turned out to affect fewer tests than originally estimated. |
| `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md` | Check each test for `known_failure=true` + `output.ruffle.txt` — any near-passing test where our diffs ⊆ Ruffle's diffs would auto-promote to `ruffle_matched`. |
| AVM1 `complete/LOADMOVIE_PLAN.md`, `REGISTERCLASS_PLAN.md`, `TEXTFIELD_PLAN.md`, `FRAME_NAVIGATION_PLAN.md` | Overlap with several mid-rate clusters. Corner cases here may be fixable with small extensions to those plans. |

## Open questions

1. Which of the 76 producing-output tests carry `known_failure=true`? For any where our diffs ⊆ Ruffle's, we qualify for `ruffle_matched` promotion without runtime fixes. Worth checking each near-passing test's test.toml first.
2. Is the "produces zero output" test list stable across CI runs, or does the DoInitAction blocker intermittently affect more tests? If unstable, the blocker may be timing-sensitive rather than categorical.
3. For cluster fixes, should each cluster get a separate sub-plan doc, or is this aggregate plan adequate? (Probably aggregate for now; split off if one cluster grows substantially.)
