# Zero-Output Tests Triage Plan

<!-- TESTS: BeginBitmapFill, Version4Loader, frame_label_test, replace_buttons1test, replace_shapes1test, action_order/action_execution_order_test6, loading/LoadVarsTest, submoviegetvar, opcode_guard_test2 -->

<!-- PLAN_META
id: ZERO_OUTPUT_TRIAGE
status: pending
phases:
  - id: 1
    name: "Verifier: empty data-file array generates invalid C (LoadVarsTest compile_fail)"
    status: completed
  - id: 2
    name: "Gate clip CONSTRUCT/LOAD events out of buttons (replace_buttons1test, replace_shapes1test)"
    status: completed
  - id: 3
    name: "Version4Loader: child SWF loadMovie of Version5Loaded.swf"
    status: completed
  - id: 4
    name: "frame_label_test: nested-sprite frame label resolution"
    status: completed
  - id: 5
    name: "BeginBitmapFill: _width=804 instead of 150 on a bitmap-filled MC"
    status: completed
  - id: 6
    name: "opcode_guard_test2: testvar off-by-one + getDepth on -32969 clone"
    status: completed
dependencies: []
blockers:
  - reason: "None — the legacy 'DoInitAction-for-unplaced-library-exports' blocker hypothesis (per complete/DEJAGNU_FRAMEWORK_PLAN.md) is wrong. None of the affected tests have DoInitAction tags; they fail for distinct, unrelated reasons. Each phase is independent."
-->

## Correction to legacy plan

`complete/DEJAGNU_FRAMEWORK_PLAN.md` and `MISC_MING_SWFC_PLAN.md` Phase 3
both list 7+ tests as blocked on **"DoInitAction-for-unplaced-library-exports"**
— the hypothesis being that the inlined Dejagnu functions are defined in
DoInitAction tags on library-export sprites that we never run because we
only run DoInitAction for placed sprites.

**That's wrong.** Direct SWF tag inspection of all the listed tests
(parsed with a 90-line Python tag scanner — see investigation log)
shows **zero DoInitAction tags** in any of them:

| Test | DefineSprite | DoAction | DoInitAction | ExportAssets | ImportAssets |
|------|-------------|----------|--------------|--------------|--------------|
| BeginBitmapFill | 1 | 7 | **0** | 0 | 0 |
| Version4Loader | 0 | 1 | **0** | 0 | 0 |
| frame_label_test | 3 | 18 | **0** | 0 | 0 |
| replace_buttons1test | 1 | 11 | **0** | 0 | 0 |
| replace_shapes1test | 1 | 13 | **0** | 0 | 0 |
| action_execution_order_test6 | 4 | 6 | **0** | 0 | 0 |
| (compare passing PlaceObject2Test) | 3 | 7 | 0 | 0 | 0 |

The Dejagnu check functions are defined inside ordinary `DoAction` tags,
not `DoInitAction`. The blocker hypothesis was based on a structural
inference that turned out not to match the actual SWF contents. The
DEJAGNU_FRAMEWORK_PLAN's "Remaining Blocker" section should be marked
inaccurate (the misc-ming/misc-swfc tests aren't blocked on that
mechanism).

## Current status of the "zero-output" tests (CI 205a9a77 → local 2026-05-02)

The CI snapshot's `matching_lines: 0` was misread as "zero output." Many
of these tests **do produce output** — just none of it matches expected.
Five of the nine listed tests now PASS or RM locally:

| Test | Suite | actual / expected / match | Real status |
|------|-------|--------------------------|--------------|
| `BeginBitmapFill` | misc-ming | 1 / 1 / 1 | **NOW PASS** (CI baseline at 7afe70f8). `mc9._width` returns 150 as expected. Phase 5 no longer needed. |
| `Version4Loader` | misc-ming | 11 / 11 / 11 | **NOW PASS locally** (2026-05-07 fix; per-tick level frame advancement). Will flip in next CI run. |
| `frame_label_test` | misc-ming | 0 / 17 / 0 | **TRUE zero output.** Frame-label-driven `_root.x1` etc. variables never get set. |
| `replace_buttons1test` | misc-ming | (was 24 / 18 / 0) | **NOW `ruffle_matched` locally** (2026-05-02 verification). Will flip in next CI run. |
| `replace_shapes1test` | misc-ming | (was 32 / 23 / 0) | **NOW PASS locally** (2026-05-02 verification). Will flip in next CI run. |
| `action_execution_order_test6` | misc-ming | (was 0/24) | **NOW `ruffle_matched` locally.** Ordering progress since CI; will flip in next CI run. |
| `submoviegetvar` | misc-swfc | (was 0/4) | **NOW PASS locally.** Will flip in next CI run. |
| `loading/LoadVarsTest` | misc-ming | (was compile_fail) | **NOW PASS locally** (2026-05-02 verification). Phase 1 fix already in `verify_output.py:1280-1281` (verified). Will flip in next CI run. |
| `opcode_guard_test2` | misc-swfc | (was runtime_error) | Now `output_mismatch`, 11/20 passing. testvar off-by-one + dynamic-clone getDepth issue. |

**Phases 1, 2, 4, and the two free flips have all landed.** `BeginBitmapFill`
flipped to PASS in a later CI baseline (Phase 5 no longer needed —
`mc9._width` now returns 150 as expected). Remaining actionable phases:
- Phase 3 (Version4Loader child SWF loadMovie — true blocker, see below),
- Phase 6 (opcode_guard_test2 testvar off-by-one + getDepth).

### Phase 3 update (2026-05-04 investigation)

Confirmed `Version4Loader` is still 0/11. Root cause traced: the test SWF
calls `loadMovieNum("Version5Loaded.swf", 4)` (encoded as
`Push str + StringAdd + GetURL2(method=NONE, target=0, vars=0)`). Our
runtime path is `actionGetURL2` → `actionGetURL` (delegates for `_level<N>`
target) → `getOrCreateLevel` + `findMovieEntry` → enqueue
`PendingDirectLoad{is_level=1}`. The pending queue is drained at end of
tick by `actionFirePendingDirectLoads` (action.c ~19533), which runs
`entry->init_func` + `entry->frame_funcs[0]` for the loaded child.

**Blocker.** `actionFirePendingDirectLoads` only runs frame 0 of the
child SWF. The Dejagnu setup is in frame 0 (defines the `xtrace_win`
prototype + check functions); the actual test assertions are in frame 1
(the `_root.note('[ debug-...]')` + `check_equals(typeof(unescape), ...)`
lines). For the child to advance past frame 0, the level MC needs to be
wired into the per-tick `advance_sprite_frames` mechanism — same
multi-frame child advance issue documented in
`from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md`
Part C (for MCL `entry->frame_funcs[1..N-1]`).

The level MC currently has `display_obj=NULL` initially; the swap-to-
sprite-display-list path in `actionFirePendingDirectLoads` is a no-op
because of that. A fix would need to: (a) allocate a `DisplayObject` for
the level MC, (b) populate `sprite_frame_funcs` / `sprite_frame_count` /
`sprite_is_playing=1` so `advance_sprite_frames` ticks frames 1..N-1, or
(c) take a synthetic-root approach similar to how `_level0` (root SWF)
runs.

**Risk.** Same risk pattern as the Shumway moviecliploader Part B
attempt (commits `1a1bf852` / revert `59533be3`): deferring/extending
multi-tick lifecycle exposes latent use-after-free in `getBounds` and
`setInterval` chained-from-onLoadComplete timing. Recommend coupling
this fix with the Shumway Part C investigation rather than landing
standalone.

## Phase 1 — Verifier: empty data-file array generates invalid C

**Bug.** `ruffle-tests/verify_output.py:1207` emits:

```python
hex_bytes = ", ".join(f"0x{b:02x}" for b in content)
lines.append(f"static const char {var_name}[] = {{ {hex_bytes}, 0x00 }};")
```

When `content` is empty (`empty.txt` for LoadVarsTest), `hex_bytes` is
`""` and the generated C is:

```c
static const char data_empty_txt[] = { , 0x00 };
```

— invalid (leading comma after `{`). gcc errors:
`data_registry.c:5:40: error: expected expression before ','`.

**Fix.** One-line: emit `{ 0x00 }` (no leading comma) when content is
empty:

```python
if not content:
    lines.append(f"static const char {var_name}[] = {{ 0x00 }};")
else:
    hex_bytes = ", ".join(f"0x{b:02x}" for b in content)
    lines.append(f"static const char {var_name}[] = {{ {hex_bytes}, 0x00 }};")
```

Or equivalently `f"{{ {hex_bytes}{',' if hex_bytes else ''} 0x00 }}"`.

**Risk.** None — strictly additive, only affects tests with empty
sidecar files. Verify by recompiling LoadVarsTest after the fix.

## Phase 2 — Gate clip CONSTRUCT events out of buttons

**Symptom.** `replace_buttons1test` and `replace_shapes1test` produce
extra trace lines that aren't in expected:

```
+ 1  _level0.static1 onClipConstruct       ← from a CONSTRUCT clip handler
+ 2  PASSED: movieclip == movieclip        ← assertion inside that handler
+ 3  _root.depth3Constructed set to 1      ← side effect of that handler
- 1  PASSED: typeof(static1) == 'object'   ← expected to start here
```

These extra lines come from the test's `onClipConstruct` clip-action
handler, which expected output skips. The expected behavior: Flash does
NOT dispatch `CLIP_EVENT_CONSTRUCT` (and likely `CLIP_EVENT_LOAD`) for
**Button** characters — only for sprites. Buttons have a different
event lifecycle (`onPress`/`onRelease`/etc., no construct/load).

**Investigation steps:**

1. Confirm the ordering of events. The test's CONSTRUCT handler is
   bundled into the static1 button's `clip_actions`. Our runtime fires
   them via `tagPlaceObject2WithClipActions`'s CONSTRUCT-dispatch path.
2. Locate the CONSTRUCT clip-event firing site. Likely in
   `SWFModernRuntime/src/libswf/tag.c` — search for
   `CLIP_EVENT_CONSTRUCT` (or `0x400` raw flag value). Multiple sites
   may dispatch.
3. Check if the placement target is a Button character (via
   `dictionary[char_id].type == CHAR_TYPE_BUTTON` or the `is_button`
   variable already in scope at placement time).
4. Skip CONSTRUCT (and LOAD) dispatch when target is a Button.

**Fix sketch.**

```c
// Before dispatching CLIP_EVENT_CONSTRUCT clip actions on a freshly placed display object:
if (is_button_target) {
    // Buttons don't fire CONSTRUCT/LOAD clip events — Flash semantics.
    // (Buttons fire onPress/onRelease/onRollOver/etc. instead, but those
    // are handled separately by the input dispatch path.)
} else {
    // existing CONSTRUCT dispatch
}
```

Same for `CLIP_EVENT_LOAD` if it leaks the same way.

**Risk.** Low-medium. Need to verify the AVM1 button tests
(`button_children`, `bad_placeobject_clipaction`,
`movieclip_in_removed_button`) still pass — they may rely on some
button-on-load behavior. The `BUTTON_INFRASTRUCTURE_PLAN.md` has
related work; this phase is an early step in that direction.

## Phase 3 — Version4Loader: child SWF loadMovie (PASS — 2026-05-07)

**Status.** Now PASSES 11/11.

**Root cause.** `actionGetURL`/`actionGetURL2` queued the loaded child
SWF as a `PendingDirectLoad` and `actionFirePendingDirectLoads` ran the
child's `init_func` and `frame_funcs[0]`, but no mechanism advanced
frames 1..N-1 of a `_levelN` load. Level MCs are stored in `g_levels[]`
not in the root `display_list[]`, so `advance_sprite_frames` never
reached them. The Dejagnu test assertions (`PASSED:
typeof(unescape) == "function"` etc.) live in frame 1 of
`Version5Loaded.swf`, so they never ran — producing zero matching
lines.

**Fix (`SWFModernRuntime/src/actionmodern/action.c`,
`SWFModernRuntime/src/libswf/swf_core.c`,
`SWFModernRuntime/src/libswf/swf_headless.c`).** Added a per-tick level
advancement registry:

1. New `LevelAdvanceEntry { mc, entry, current_frame }` array
   `g_level_advance[128]` in `action.c`. `actionRegisterLevelAdvance(mc,
   entry)` is called from `actionFirePendingDirectLoads` for level loads
   with `frame_count > 1`. `actionAdvancePlayingLevels(app_context)`
   runs the level's `frame_funcs[current_frame]` on each tick (with
   display_list / global / context save+restore), increments
   `current_frame`, and drops the entry once `current_frame >=
   frame_count`.
2. `swf_core.c` and `swf_headless.c` call `actionAdvancePlayingLevels`
   after `actionFirePendingDirectLoads` each tick, and
   `hasPlayingLevels()` is added to the past-end-of-frames continuation
   conditions so a single-frame parent (like `Version4Loader`'s)
   doesn't break the loop before the level finishes its timeline.

**Why the existing `unloadmovienum` (avm1) test isn't disturbed.** Its
parent has 4 frames + `stop()`; the loop exits via the Root-stopped
branch (which doesn't keep running for levels) before target.swf's
frame 9 (`TEST FAILURE: I should be unloaded by now!`) is reached.

**Verification.** AVM1 21-test loadMovie/MCL battery (`loadmovie`,
`loadmovie_method`, `loadmovie_replace_root`, `loadmovienum`,
`loadmovienum_cross_version_prototype`, `loadmovie_var_persistence`,
`mcl_loadclip`, `mcl_loadclip_replace_root`, `unloadmovie`,
`unloadmovie_method`, `unloadmovienum`, `loadmovie_fail`,
`loadmovie_flashvars`, `loadmovie_registerclass`, `mcl_target_jpg`,
`mcl_target_png`, `mcl_target_gif87a`, `mcl_target_gif89a`,
`movieclip_state_values`, `depth_replacement_audio_unloading`,
`netconnection_close`) — 21/21 PASS. AVM1 22-test extended battery
(XML/MCL/EI/loadvariables/sound/closure/super/goto) — 21 PASS, 1
pre-existing accepted failure (`loadvariables_method`, infrastructure:
log_fetch). Gnash misc-mtasc.all `levels` unchanged ruffle_matched
(49/68). Gnash misc-ming.all 9-test goto/loop/timeline battery — 9/9
effective pass.

## Phase 4 — frame_label_test: target-path GotoFrame2 + nested-sprite navigation (PASS — 2026-05-04)

**Status (2026-05-04, second pass).** Now PASSES 17/17. Three earlier
fixes (described below) brought the test from zero output to 12/17
matching with timeline-loop noise; the final fix isolates `actionCall`'s
drain from the outer drain so `CALLFRAME('/:1')`'s `actionStop()` and
the parent frame's pending check_equals scripts no longer reorder.

**Root cause #1 (FIXED).** The test's `gotoAndPlay('/mc1/mc11/:frame4')`
encodes as `Push("/mc1/mc11/:frame4") + GotoFrame2(play=1)`. Our
`actionGotoFrame2` STRING branch was stripping the colon-path and applying
the resulting frame number to the **root timeline**, not to the target
sprite. With `:5` (numeric), this clamped to root's last frame (frame 3
of a 4-frame timeline) and triggered `was_clamped → g_skip_inline_target_script
→ ng_executeGotoCatchUp clears goto/manual_next_frame without inlining
the target script`, so the assertion frame's scripts never queued. Net
effect: zero output despite all 14 assertion DoActions being recompiled.

Fix: extended the STRING branch in `actionGotoFrame2`
(`SWFModernRuntime/src/actionmodern/action.c`) to mirror `actionCall`'s
target-path resolution. When a `target:frame` path is present, it now
resolves the target via `resolveSlashPathToMC`; if the target is a
sprite, the frame is resolved against the target sprite's frame labels
(via `ng_findSpriteLabelFrame`) and navigation is applied via
`ng_gotoFrameByMC` instead of perturbing the root timeline.

**Root cause #2 (FIXED).** `ng_gotoFrameByMC` looked up the target MC via
`ng_findDisplayEntryByName(mc->name)`, which only searches the root
display list. For nested MCs (e.g., `mc11` inside `mc1`) the search
returned `SIZE_MAX` and we fell through to the dynamic-MC short-path
(updates `currentframe` but skips frame scripts). The sprite's frame
DoAction (where `_root.x1 = 'mc11_frame4'` lives) never ran.

Fix: when the name search misses, fall back to `mc->display_obj` (set
during `tagPlaceObject2` for any nested sprite) before declaring the
MC dynamic-only. `SWFModernRuntime/src/libswf/tag_stubs.c
ng_gotoFrameByMC`.

**Root cause #3 (FIXED).** SWF<7 case-insensitive label matching:
sprite `mc1` has both `small_first`@frame8 and `Small_first`@frame9.
Looking up `Small_first` should return the FIRST defined under that
case-insensitive key (= `small_first`@8) per Flash<7 semantics. Our
`ng_findSpriteLabelFrame` did exact match first then case-insensitive
fallback — picked `Small_first`@9 instead. Fix: in SWF<=6, do a single
case-insensitive scan that returns the LOWEST frame index among
matches. SWF7+ keeps exact-only matching. `SWFModernRuntime/src/libswf/tag.c
ng_findSpriteLabelFrame`.

**Root cause #4 (FIXED — landed 2026-05-04 second pass).**
Both prior open issues collapsed into a single bug: `actionCall`'s
`CALL_FRAME_FUNC` was invoking the called frame's recompiler-emitted
`actionDrainOnloadAndScript` while the parent frame's drain was still
in progress. The inner drain happily processed the parent's pending
queue entries — running `script_31`/`32`/`33` (the `_root.x1==0`
checks) **before** the called frame's `script_0` (which sets
`x1=0; x2=0; ...`), and running `script_34` (`_root.totals(); stop()`)
inside the call's `is_playing` save/restore window so the `stop()`
got overwritten on call return. Net effect: the assertion checks ran
against the pre-call values (so x1/x2/x3 still said `mc11_frame4`/...),
and `is_playing` stayed true so the timeline kept looping (7+ cycles).

The fix isolates the called frame's drain from the outer queue:

1. `CALL_FRAME_FUNC` snapshots `g_aq_count` before invoking the frame.
2. Brackets the frame call with `actionDrainSuppressEnter()` /
   `actionDrainSuppressLeave()` so the frame's inline
   `actionDrainOnloadAndScript` no-ops.
3. After the frame returns, calls a new `actionDrainOnloadScriptAbove`
   helper that drains only entries with index ≥ snapshot — i.e.
   only the entries the called frame itself queued. Outer pending
   entries stay in the queue for the outer drain loop to process
   in correct FIFO order.

This mirrors Ruffle's per-call action stack, where each `call()` runs
its own private action layer.

**Files touched (final fix):**
- `SWFModernRuntime/include/actionmodern/action_queue.h` — declared
  `actionAQCount` and `actionDrainOnloadScriptAbove`.
- `SWFModernRuntime/src/actionmodern/action_queue.c` — implemented
  the new helpers.
- `SWFModernRuntime/src/actionmodern/action.c` — replaced the
  `actionDrainActionQueueByKind(SCRIPT)` trailing call in
  `CALL_FRAME_FUNC` with the snapshot+suppress+above pattern.

**Sanity battery (verified no regressions, second pass):**
- 25 AVM1 call/scope/super/goto tests (call, closure_scope,
  set_variable_scope, goto_methods, local_to_global,
  string_paths_variable_scopes, get_variable_in_scope,
  function_as_function, function_base_clip, funky_function_calls,
  swf4_function_calls, watch, watch_textfield, on_construct,
  as2_super_and_this_v6/v8, swf5_to_6_cross_call, execution_order2/3,
  goto_rewind1/3, set_interval, tell_target, path_string, target_path):
  25/25 PASS.
- 14 misc-ming.all goto/loop/action-order tests: 10 PASS + 2
  ruffle_matched + 2 pre-existing failures (`ActionOrderTest3/4`)
  unchanged from CI baseline.

**Files touched (first-pass partial fix):**
- `SWFModernRuntime/src/actionmodern/action.c` — `actionGotoFrame2`
  STRING branch: added target-path resolution mirroring `actionCall`
  (lines around 26310–26370).
- `SWFModernRuntime/src/libswf/tag_stubs.c` — `ng_gotoFrameByMC`
  fallback to `mc->display_obj` when the root display-list name search
  misses.
- `SWFModernRuntime/src/libswf/tag.c` — `ng_findSpriteLabelFrame` SWF<=6
  branch: case-insensitive scan picking lowest-frame ties.

**Sanity battery (verified no regressions, first pass):**
- 25 AVM1 goto/call/case tests (goto_frame, goto_frame2, goto_label,
  goto_methods, goto_advance1/2, goto_both_ways1/2, button_goto,
  goto_execution_order/2, define_function_case_sensitive, goto_rewind3,
  execution_order2/3, tell_target/_invalid/_invalid_swf6, path_string,
  property_invalid_base_clip, swf4_actions_coercion_order,
  goto_frame_number, action_to_integer, call, set_interval): 25/25 pass.
- 19 misc-ming.all goto/loop/action-order tests: 14 pass + 1
  ruffle_matched (= effective 15) — unchanged from baseline.
- 8 misc-swfc.all clone/destroy tests: 5 pass + 2 ruffle_matched — only
  `button_test1` still fails (known blocker, unrelated).

## Phase 5 — BeginBitmapFill: _width returns 804 instead of 150 (RESOLVED)

**Status (2026-05-04).** The test now PASSES in the CI baseline at
`7afe70f8`. `mc9._width` returns 150 as expected. No work needed —
`mcGetEffectiveSize` / `_width` getter already walks the drawing-API
geometry correctly via `drawingUpdateBounds`, which records corner
points from `moveTo`/`lineTo` calls. The 804 value seen in earlier
snapshots no longer reproduces.

There's also a stderr warning during this test:

```
ERROR: heap_alloc() called before heap_init()
ERROR: Failed to allocate property name
```

Triage that separately — it may be unrelated to the `_width` issue
or it may be the cause (a property name allocation failure could
corrupt state).

## Phase 6 — opcode_guard_test2 → ruffle_matched (RESOLVED 2026-05-07)

**Status.** Now `ruffle_matched` 24/24 (effective pass). Three fixes in
`SWFModernRuntime/src/actionmodern/action.c`:

1. **`actionSetTarget` var_map MOVIECLIP fallback.** AS-created clips
   (`duplicateMovieClip` / `CloneSprite` / `createEmptyMovieClip`)
   register their clones in `var_map` (via `setVariableByName`) but
   not in the parent's `display_list` or `dynamic_props`. The
   `resolveSlashPathToMC` walks therefore failed to resolve them and
   `actionSetTarget` fell through to the "Target not found" emission
   even though `_root.<name>` GetMember resolved them via its existing
   var_map check (action.c:44801-44819). Mirroring that lookup as the
   final fallback before the warning emission lets `setTarget('dup1')`
   / `setTarget('dup3')` succeed and matches Ruffle's "look up via the
   active scope's stage object" semantics for AS-created MCs.

2. **`actionRemoveSprite` / `mc.removeMovieClip()` deferred path for
   AS-level `onUnload`.** Previously both call sites set
   `mc->depth = INT_MIN` and cleared `var_map` / `parent.dynamic_props`
   immediately, regardless of whether the MC had an AS-level onUnload
   handler. Mirroring the tag-level `RemoveObject2` pattern
   (`actionMarkMCPendingRemoval`), a clip with onUnload now parks at
   the shifted depth `-(swf_depth) - 1 - 16384` with `pending_removal=1`,
   keeps `dynamic_props` intact, and leaves `var_map` /
   `parent.dynamic_props` bindings alone for same-frame reads. The
   "no-onUnload" path is unchanged. Also extends the "removed-MC was
   the active SetTarget context" reset to fire when `g_base_clip` is
   NULL but `g_settarget_context_changed` is set, so subsequent variable
   reads in the now-dead clip's setTarget block fall back to root via
   `g_settarget_invalid` / `g_settarget_none` (same Ruffle
   `target_clip_or_root()` semantics that gate `_target` lookups).

3. **`actionFinalizePendingRemovals` cleanup of var_map /
   parent.dynamic_props.** When a deferred-removal MC finalizes at
   start of next frame, its `var_map` and `parent.dynamic_props`
   entries are now cleared (only when they still reference THIS MC,
   to avoid clobbering same-name re-placements). Without this step
   the AVM1 `unload` test sees `_root.clip4` still resolving to a
   MOVIECLIP value with `depth=INT_MIN` (printed as the empty target
   path), instead of the expected `undefined`.

**Test deltas (effective).**

- `from_gnash/misc-swfc.all/opcode_guard_test2`: output_mismatch
  (2/24) → `ruffle_matched` (24/24, diffs `{4,7}` ⊆ Ruffle's
  `{12,13,18}`).

**No regressions.** Verified locally on:

- 44 AVM1 lifecycle/clone/unload/movieclip-state tests (`unload`,
  `unload_clip_event`, `unload_nested_child`, `unloadmovie`,
  `unloadmovie_method`, `mcl_unloadclip`, `clip_events`,
  `clip_constructors`, `goto_rewind1/2/3`, `execution_order2`,
  `on_construct`, `register_and_init_order`, `set_interval`,
  `attach_movie`, `attach_movie_stop`, `bad_placeobject_clipaction`,
  `tell_target`, `tell_target_invalid`, `tell_target_invalid_swf6`,
  `path_string`, `swf5_no_closure`, `duplicate_movie_clip`,
  `duplicate_movie_clip_drawing`, `clone_sprite_edittext`,
  `clone_sprite_types`, `create_empty_movie_clip`,
  `conflicting_instance_names`, `default_names`, `init_object_order`,
  `movieclip_depth_methods`, `movieclip_get_instance_at_depth`,
  `movieclip_init_object`, `textsnapshot_available_text`,
  `swf5_to_6_cross_call`, `swf6_to_5_cross_call`,
  `goto_execution_order`, `goto_execution_order2`, `goto_methods`,
  `empty_movieclip_can_attach_movies`, `movieclip_state_values`,
  `movieclip_in_removed_button`, `movieclip_library_state_values` —
  44/44 effective pass).
- 32 misc-ming.all goto/loop/lifecycle tests — 26 PASS + 5 RM + 1
  pre-existing MISMATCH (`opcode_guard_test`, ignored — unrelated).
- 34 AVM1 watch/goto/load/closure/super tests — 33 PASS + 1
  pre-existing MISMATCH (`loadvariables_method`, infrastructure
  blocker — unrelated).
- 10 misc-swfc.all tests — 6 PASS + 3 RM + 1 unchanged MISMATCH
  (`movieclip_destruction_test4`, 8/40 same as baseline).
- 4 Shumway duplicateMovieClip tests + `doactionorder` — all 5 PASS
  (`doactionorder/symbolclass` is a pre-existing local MISMATCH on
  master with no change either way; unrelated to this fix).

## Phases that no longer need work

- **`submoviegetvar`** — RESOLVED (now PASS in CI at `c5994ec1`). Removed
  from the "blocker" list.

## Predictions that didn't pan out

- **`action_execution_order_test6`** — predicted in earlier session to
  flip to `ruffle_matched` via subset-of-Ruffle promotion. Investigated
  2026-05-07 (local): test has `known_failure = true` and ships
  `output.ruffle.txt`, so promotion path is in place. Diagnosis is
  candidate (b) **with a concrete root cause**: our Construct/Load
  ordering on initial frame placement is wrong (we fire Load before
  Construct for mc1/mc2), placing line indices 0 and 1 in our diff that
  are NOT in Ruffle's diff. See `REMAINING_TAIL_TRIAGE.md` entry for
  details. No longer just a triage prediction — it is a real ordering
  bug that needs a clip-event Phase 1/Phase 2 ordering plan if active
  work begins.

## Verification battery

**Required-pass guardrail:**

- AVM1: `loadvariables_method`, `loadvariables`, `loadvars` (LoadVars
  tests with non-empty sidecars). Phase 1 must not regress these.
- AVM1: `button_children`, `bad_placeobject_clipaction`,
  `movieclip_in_removed_button`, `clip_events`, `on_construct`,
  `register_and_init_order`. Phase 2 must not regress these (CONSTRUCT
  gating risk).
- AVM1: `loadmovie`, `loadmovie_unloadmovie`, `loadmovie_*` (~30
  tests). Phase 3 must not regress these.

**Target tests:**

- Phase 1: `loading/LoadVarsTest` flips from compile_fail to
  output_mismatch (or pass, if the underlying loadVariables test logic
  also works).
- Phase 2: `replace_buttons1test`, `replace_shapes1test` partial
  improvement (ordering shifts from extra-leading to expected-leading).
- Phase 3: `Version4Loader` produces some output instead of none.
- Phase 4: `frame_label_test` produces some output instead of none.
- Phase 5: `BeginBitmapFill` PASS.
- Phase 6: `opcode_guard_test2` partial improvement.

## Open questions

1. **The `heap_alloc() called before heap_init()` stderr warning in
   BeginBitmapFill.** Does it also appear in other tests? Tracing back
   to the call site might reveal a runtime initialization-order bug that
   affects more than just BeginBitmapFill.
2. **Why are `submoviegetvar` and `action_execution_order_test6` now
   passing locally?** No matching commit message claims to fix them
   — they may have flipped via incidental changes in nearby
   commits. Worth confirming via `git log` since CI snapshot.
3. **Phase 2 overlap with `BUTTON_INFRASTRUCTURE_PLAN.md`.** That plan
   covers other Button issues (typeof, instance naming, prototype
   enumeration). Phase 2 here is "buttons don't fire
   CLIP_EVENT_CONSTRUCT/LOAD" — adjacent but distinct. Should land
   independently.

## Estimated session budget

- Phase 1: 15 min (1-line verifier fix + LoadVarsTest re-run).
- Phase 2: 1–2 hours (locate CONSTRUCT/LOAD dispatch sites, gate on
  is_button, run battery).
- Phase 3: 2–3 hours (loadMovie cross-version investigation).
- Phase 4: 2–3 hours (frame label resolution; may surface recompiler
  emission issue).
- Phase 5: 1–2 hours (decompile + _width getter audit).
- Phase 6: 1–2 hours (testvar off-by-one + depth math).

Phases 1 + 2 are the cheapest (~2 hours combined) for 3 test flips.

## Why this is the right shape

The legacy "DoInitAction-for-unplaced-library-exports" hypothesis was a
plausible-sounding inference that turned out not to match the actual
SWF contents. Like the prior "input drivers" misclassification (see
`BUTTON_INFRASTRUCTURE_PLAN.md`'s correction), running the actual tests
and inspecting their actual output reveals 6 distinct, unrelated
issues — none of which require an architectural DoInitAction change.
The plan replaces a single architectural blocker with 6 narrow,
independent fixes, most of which are 1–3 hour tasks.

Once landed, removes the "Phase 3 — Blocked zero-output tests"
section from `MISC_MING_SWFC_PLAN.md` and supersedes the legacy
`complete/DEJAGNU_FRAMEWORK_PLAN.md` "Remaining Blocker: misc-ming /
misc-swfc Inlined Dejagnu" claim.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `MISC_MING_SWFC_PLAN.md` "Phase 3 — Blocked zero-output tests" | This plan supersedes that section. The 9 tests listed there have 6 distinct causes, none architectural. |
| `complete/DEJAGNU_FRAMEWORK_PLAN.md` "Remaining Blocker" | Misframed. The misc-ming/misc-swfc tests aren't blocked on DoInitAction-for-library-exports. Mark that section inaccurate or update on the next pass. |
| `BUTTON_INFRASTRUCTURE_PLAN.md` | Phase 2 (button CONSTRUCT/LOAD gating) is adjacent. Both plans can land independently; pick whichever is cheaper to verify first. |
| `CLONESPRITE_DEPTH_BIAS_PLAN.md` | Phase 6 (opcode_guard_test2 getDepth) likely overlaps. Land that plan first if attempting Phase 6. |
| `DEFERRED_CLIP_UNLOAD_PLAN.md` | Independent. |
