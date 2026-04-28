# Transformed-By-Script + Natural Wrap-Back Display Preservation Plan (Phase 7 of GOTO_CATCHUP_HYGIENE)

<!-- TESTS: place_and_remove_object_insane_test -->

<!-- PLAN_META
id: TRANSFORMED_BY_SCRIPT_WRAP_BACK
status: complete
phases:
  - id: 1
    name: "Add transformed_by_script flag to DisplayObject"
    status: complete
  - id: 2
    name: "Set the flag from AS property setters (_x, _y, _xscale, _yscale, _rotation, _alpha, _visible, _width, _height, transform.matrix)"
    status: complete
  - id: 3
    name: "Gate transform/cxform application in tagPlaceObject2 catch_up_backward survives branch on !transformed_by_script"
    status: complete
  - id: 4
    name: "Route end-of-movie natural wrap-back through goto-style catch-up (Ruffle's run_goto(1, is_implicit=true))"
    status: complete
  - id: 5
    name: "Preserve renamed-by-modify instance names across wrap-back (handled by existing g_pending_instance_name discard in catch-up survives branch)"
    status: complete
  - id: 6
    name: "Regression battery (goto/rewind/wrap-back, plus place_and_remove tests)"
    status: complete
dependencies:
  - "Independent of GOTO_FIFO_UNIFICATION_PLAN.md (Phase 6, shipped via complete/GOTO_FIFO_UNIFICATION_INCREMENTAL_PLAN.md); both are spin-offs of the now-superseded GOTO_CATCHUP_HYGIENE_PLAN.md"
-->

## Implementation summary (shipped)

`place_and_remove_object_insane_test` 17/22 → **22/22 (PASS)**.

**Key changes:**

1. **`DisplayObject.transformed_by_script` + `name_overridden` flags** in
   `swf.h:165-166`. The flag is set by the new
   `markTransformedByScript()` helper at the top of `action.c` whenever
   AS code writes a transform attribute (matrix component or
   `_visible`).
2. **Wired into all major property setter sites** in `action.c`:
   - `setMatrixProperty` (`mc.transform.matrix = ...`).
   - `mcSetEffectiveWidth` / `mcSetEffectiveHeight`.
   - `actionSetMember` for `_x` / `_y` / `_xscale` / `_yscale` /
     `_rotation` / `_visible` / `_width` / `_height` / `transform`.
   - `setMCBuiltinProperty` (initObject path).
   - `actionSetProperty` (opcode dispatch by property index).
3. **Phase 3 gate** in `tagPlaceObject2`'s catch_up_backward survives
   branch (`tag.c:3917+`): skip `transform_id`/`cxform_id`/`init_cx_fields`
   updates when `transformed_by_script || cx_overridden`. Mirrors
   Ruffle's `apply_place_object`'s `if !self.transformed_by_script()`
   gate (`core/src/display_object.rs:2494`).
4. **Phase 4 dispatch** in `swf_core.c`'s catch-up retry loop: when
   `manual_next_frame && !goto_from_action && next_frame < current_frame
   && current_frame + 1 == g_frame_count`, set `goto_from_action = 1`
   and `g_natural_wrap_cleanup_pending = 1` to route the
   recompiler-emitted end-of-movie wrap through the existing backward
   catch-up path. The `current_frame + 1 == g_frame_count` guard avoids
   firing when an in-frame script-driven goto already advanced
   `current_frame` away from the last frame (e.g.
   from_shumway/avm1/duplicateMovieClip/dontremove's `script_2`
   `GotoFrame(1)`).
5. **Two-step ordering** of unsurvivor cleanup vs. target frame
   scripts. `actionDrainOnloadAndScript` calls
   `ng_display_cleanup_unplaced_after(catch_up_target)` once at the
   start when `g_natural_wrap_cleanup_pending` is set, BEFORE scripts
   drain, so AS lookups like `_root.mc_green` see the cleaned-up
   display list. Mirrors Ruffle's `run_goto` order: `remove_child` for
   unsurvivors runs BEFORE `apply_place_object` and target frame's
   `run_frame_internal`.
6. **`actionRewindCleanup` skip-dead-MC fix** in
   `action.c:19367+`: timeline-MC cache entries that were already
   `avm1_removed` or `depth == INT_MIN` (e.g. invalidated by a prior
   `RemoveObject2`) are no longer resurrected by the depth reset.
   Without this guard, `findOrCreateMovieClip`'s first-match returns
   the stale (script-modified) MC instead of the freshly-placed one,
   producing wrong `_x` reads after `mc.depth` was reset to a valid
   value during catch-up.
7. **`tagPlaceObject2` !survives stale-replace branch** in
   `tag.c:3955+` extended to fire on
   `(catch_up_mode || g_natural_wrap_cleanup_pending) &&
   placed_at_frame > current_frame`. When a non-surviving entry
   (different char_id or different ratio) was placed at a later
   frame, the catch-up replay must clear it (and invalidate the
   cached MC if no UNLOAD handler) so frame 0's PlaceObject2 takes
   the fresh-placement path and resets the MC's `_x`/`_y` to the
   transform-derived values.
8. **`ng_display_cleanup_unplaced_after`** in `tag.c:6071+` now
   invalidates the cached MovieClip via
   `actionInvalidateCachedMovieClip()` in addition to clearing the
   display-list slot. Mirrors the equivalent invalidation in
   Ruffle's `remove_child`.

**Regression battery (all pass):**

- AVM1 goto/rewind/lifecycle: 33-test battery
  (goto_rewind1/2/3, execution_order1/2/3, goto_execution_order/2,
  goto_both_ways1/2, rewind_depth, goto_frame, goto_frame2,
  goto_label, goto_methods, conflicting_instance_names, default_names,
  movieclip_name_from_timeline, place_and_lookup, clip_events,
  on_construct, attach_movie, init_object_order,
  register_and_init_order, movieclip_state_values,
  movieclip_library_state_values, set_interval, unload,
  unload_clip_event, unload_nested_child, unloadmovie, mcl_unloadclip,
  button_children) — **33/33 effective**.
- Misc-ming: loop_test/loop_test2/3/4/5/7/8/9 (8/8 effective);
  place_and_remove_object_test, place_and_remove_object_insane_test
  (now 22/22), instanceNameTest, attachMovieTest, ResolveEventsTest,
  reverse_execute_PlaceObject2_test1/2, DefineEditTextTest,
  DefineEditTextVariableNameTest2, static_vs_dynamic1/2, shape_test,
  get_frame_number_test, new_child_in_unload_test,
  event_handler_scope_test (15/15 pass).
- Misc-swfc: stackscope, submoviegetvar, edittext_test1 pass;
  movieclip_destruction_test2 unchanged at 50/52 (pre-existing
  failure, see complete/MOVIECLIP_DESTRUCTION_TEST2 work).
- Shumway duplicateMovieClip: dontremove, samedepth, name-coercion
  (3/3).
- AVM1 broader: super/this/string/object/text battery — 14/14.

## Problem statement

`place_and_remove_object_insane_test` (17/22 matching lines) is a
3-frame movie that loops 10× (30 ticks):

| Frame | Tags |
|-------|------|
| 0 | PlaceObject2: mc_red (depth 5), mc_blue (depth 7, char_id=30), mc_black (depth 10) |
| 1 | RemoveObject2 of all three |
| 2 | PlaceObject2: mc_red (modify, ratio=65535), mc_blue (modify, char_id=30 same as frame 0), mc_black_name_changed (replace at depth 10), mc_green (new at depth 6); script_13 then adds 60 to `mc_red._x` and `mc_blue._x` |

After the natural backward wrap from frame 2 → frame 0 the test
expects:

```
PASSED: 60 == 60                         ← mc_blue._x preserved across wrap
PASSED: undefined == undefined           ← _root.mc_black does NOT resolve
PASSED: movieclip == movieclip           ← _root.mc_black_name_changed DOES resolve
```

Our actual output for those three lines:

```
FAILED: expected: 60, obtained: 0
FAILED: expected: undefined, obtained: movieclip
FAILED: expected: movieclip, obtained: undefined
```

The natural wrap-back **discards** the script-applied `_x = 60` and
the rename to `mc_black_name_changed`, so frame 0's PlaceObject2
re-applies transform 27 (identity at 0,0) and the original instance
names (mc_black, not mc_black_name_changed).

## Root cause: natural wrap-back ≠ Ruffle's implicit goto

Ruffle's natural loop wrap-back is `run_goto(target,
is_implicit=true)`, which in turn calls `run_frame_internal(...,
run_display_actions=false, ...)`
(`core/src/display_object/movie_clip.rs:1546+`). With
`run_display_actions=false`:

1. PlaceObject2 / RemoveObject2 tags from frame 0 are **not**
   re-executed during the wrap-back goto. The display list state
   from iter N's last-executed frame (frame 2 in this test) persists.
2. The next normal tick re-runs frame 0's tags through the regular
   tag path. PlaceObject2 hits the modify branch (slot already
   populated) and Ruffle's `apply_place_object` gates updates on
   `!self.transformed_by_script()`:

   ```rust
   if !self.transformed_by_script() {
       // Apply matrix, color_transform, ratio, bitmap_cached, blend_mode, visible, bg_color, filters
   }
   ```

   `transformed_by_script` is a `DisplayObjectFlags` bit
   (`core/src/display_object.rs:777-783`) set by AVM1 / AVM2 property
   setters when script writes `_x`, `_y`, etc. — the bit signals
   "the timeline is no longer authoritative for transform; preserve
   the script's writes."

Our model does the **opposite** in `swf_core.c:1220-1236`: when
`!goto_from_action && next_frame < current_frame` (recompiler-emitted
natural wrap), it calls

```c
ng_display_clear_after(app_context, next_frame);
ng_display_cleanup_unplaced_after(app_context, next_frame);
```

…which clears every display entry placed at frames `> next_frame` — i.e.,
**erases iter N frame 2's placements before iter N+1 frame 0 runs**.
Then frame 0's PlaceObject2 of mc_blue (transform 27, identity at
0,0) creates a fresh entry, blowing away script's `_x = 60`. And
frame 0 places mc_black (not mc_black_name_changed), so the rename
from frame 2 of iter N is gone.

This is the wrong shape. We need to:

1. Preserve iter N's display state across the wrap-back (don't
   `clear_after`).
2. Add a `transformed_by_script` flag to DisplayObject so iter N+1's
   PlaceObject2 modify branches know not to overwrite script-modified
   transforms.
3. Preserve renamed instance names so frame 2's rename persists.

## Concrete diff symptoms

### place_and_remove_object_insane_test (17/22 matching)

Three failing assertions, all in script_3 during iter 2's frame_0
drain (counter==1):

| Line | Expected | Actual | Why |
|------|----------|--------|-----|
| 10 | `60 == 60` | `60 == 0` | mc_blue._x reset to transform 27's tx=0 |
| 11 | `undefined == undefined` | `obtained: movieclip` | `_root.mc_black` still resolves |
| 12 | `movieclip == movieclip` | `obtained: undefined` | `_root.mc_black_name_changed` lost |

Lines 11 and 12 look mirrored: mc_black is the original frame 0 name;
mc_black_name_changed is the rename applied by frame 2's
PlaceObject2 (replacement at depth 10). After the natural wrap, our
model places mc_black fresh (so the original name resolves) and
loses the rename (so the new name doesn't). The expected behavior is
the inverse: the rename persists, the original name doesn't.

## Phase 1 — Add `transformed_by_script` flag

**Site.** `SWFModernRuntime/include/libswf/swf.h:111-177`
(`DisplayObject` struct).

**Fix.** Add a `u8 transformed_by_script` field next to the existing
`depth_swapped` (line 165) and `cx_overridden` (line 162) flags,
mirroring Ruffle's `DisplayObjectFlags::TRANSFORMED_BY_SCRIPT`.

```c
u8 transformed_by_script;  // 1 if any AS property setter wrote a transform attribute
```

**Risk.** Low — additive struct field. Zero-initialized at placement
time; preserved across modify operations.

## Phase 2 — Set the flag from AS property setters

**Sites.** `SWFModernRuntime/src/actionmodern/action.c`:

- `actionSetVariable` (`:33739-33810`) — handles `_x`, `_y`, `_xscale`,
  `_yscale`, `_rotation`, `_alpha`, `_visible`, `_width`, `_height`,
  `_quality`, `_highquality`, `_focusrect`, `_soundbuftime`. Already
  sets `as_set_flags` bits (1=x, 2=y, 4=xscale, 8=yscale,
  16=rotation).
- `actionSetProperty` (`:45080-45276`) — property index dispatcher:
  index 0 = `_x`, 1 = `_y`, 2 = `_xscale`, 3 = `_yscale`, 6 = `_alpha`,
  7 = `_visible`, 10 = `_rotation`, etc.
- `actionSetMember` (`:37737`) — generic property setter for
  ASObject/MovieClip members.
- Color object methods that change `cxform` (`Color.setRGB`,
  `Color.setTransform`).
- `swapDepths` writes to depth_swapped — orthogonal but adjacent;
  audit whether swapDepths should also set transformed_by_script.

**Fix.** At each site that writes a transform attribute, set
`mc->disp->transformed_by_script = 1`. Mirror Ruffle's coverage:
matrix component, color transform, ratio (probably not — Flash
treats ratio differently?), `_visible`, blend mode, bitmap_cached,
filters.

**Risk.** Medium. Mis-coverage either direction is wrong: setting
the flag too eagerly (e.g., for read-only property reads) makes
modify-branch updates silently no-op for tests that depend on
timeline modify; setting it too narrowly (e.g., missing color
transforms) leaves the symptom in a Color-related test.

## Phase 3 — Gate `tagPlaceObject2` modify branch

**Sites.** `SWFModernRuntime/src/libswf/tag.c:3664-4002`. Two
relevant branches:

- **Modify branch (char_id==0, lines 3685-3711).** Today:

  ```c
  // Updates transform_id, cxform_id, clip_depth UNCONDITIONALLY
  // Calls ng_cache_transform() at line 3696 unconditionally
  // (placed_at_frame is NOT updated — that's intentional)
  // Existing guards: depth_swapped, cx_overridden
  ```

- **Root timeline loop-back preservation (lines 3895-3913).** Today:
  same character re-placed at depth across frame boundaries. Treats
  as modify, calls `ng_cache_transform()` unconditionally,
  updates `placed_at_frame = current_frame`.

**Fix.** Add a `transformed_by_script` guard mirroring the existing
`depth_swapped` / `cx_overridden` guards:

```c
if (!disp->transformed_by_script && !disp->depth_swapped) {
    // Apply transform_id update + ng_cache_transform()
}
if (!disp->transformed_by_script && !disp->cx_overridden) {
    // Apply cxform_id update
}
```

The flag survives modify-tag application (don't clear it). It
clears on RemoveObject2 (the slot is freshly placed next time → flag
zero on the new entry).

**Risk.** Medium-high. Tests that explicitly rely on timeline modify
overriding script writes (e.g., a test where script writes `_x = 50`
in frame 1 and frame 2's PlaceObject2 contains a Modify with a new
matrix) would shift behavior. Need a careful audit of the goto/rewind
battery for these patterns.

## Phase 4 — Preserve display state across natural wrap-back

**Site.** `SWFModernRuntime/src/libswf/swf_core.c:1220-1236`.

**Today.** Natural backward wrap (recompiler-emitted, not action-script
goto):

```c
if (!goto_from_action && next_frame < current_frame) {
    ng_display_clear_after(app_context, next_frame);
    ng_display_cleanup_unplaced_after(app_context, next_frame);
}
```

This clears entries placed at frames `> next_frame`, erasing iter N
frame 2's placements before iter N+1 frame 0 runs. Wrong direction.

**Fix.** Replace with **implicit-goto semantics** (Ruffle's
`run_goto(implicit=true, run_display_actions=false)`):

1. Do **not** clear display entries based on `placed_at_frame`.
   Instead, keep iter N's last-state slot population intact.
2. Run `funcs[0]` (or `funcs[next_frame]`) with `g_tag_skip_mode=1`
   so its DoAction queues into `AQ_KIND_SCRIPT` — but skip its
   PlaceObject2/RemoveObject2 tags. This is the
   `run_display_actions=false` half.
3. The next normal tick re-runs frame 0's tags through the regular
   path. PlaceObject2 hits the existing modify branch (Phase 3), which
   leaves script-transformed slots alone.

The `goto_from_action` gate stays as today — script-initiated gotos
go through `ng_executeGotoCatchUp`, which already has its own
clearing semantics tuned to that path.

**Subtlety.** Tests that legitimately expect frame 2's placement to
NOT survive wrap-back (e.g., a sprite placed at depth 10 in frame 2
that should not exist at frame 0 of the next iter because frame 0
doesn't place there) will see the stale entry. The fix is that frame
0's tags re-place the depth and our modify branch overwrites — so
the slot ends up populated by the NEW char_id with frame 2's
transform if `transformed_by_script` is 0, or with frame 2's stale
char_id if no frame-0 tag touches the slot. Need to verify Flash's
behavior for this case (probably: stale entry persists if no frame
re-places it).

**Risk.** High. This is the core of the change; nearly every
goto/rewind/loop test exercises this code path.

## Phase 5 — Preserve renamed instance names across wrap

**Site.** `SWFModernRuntime/src/libswf/tag.c` — `tagSetInstanceName`
and the modify branches of `tagPlaceObject2`.

**Today.** When PlaceObject2 with `has_name=1` runs as a modify
(same depth, same char_id), the instance name overwrites the
existing slot's name. On natural wrap-back, frame 0's PlaceObject2
of mc_black overwrites the wrap-preserved mc_black_name_changed
back to mc_black. (Currently moot because Phase 4's clear_after
nukes the entry first; but post-Phase-4, the rename overwrite
remains.)

**Fix.** Treat instance-name change from a same-char_id modify as
preserved across wrap if the original placement was a script-driven
rename or a frame-2 modify rename. Two options:

1. **Per-name flag.** Add a `name_overridden` flag to DisplayObject,
   set by AS-level rename (`mc._name = "x"`) and by modify-branch
   rename. Frame 0's PlaceObject2 modify branch skips name update
   when the flag is set.
2. **Treat all modify-branch renames as sticky.** Once renamed, the
   slot keeps the new name across wrap and across frame 0
   re-placement, unless explicitly cleared.

Option 1 mirrors `transformed_by_script` semantics and is
consistent. Option 2 is simpler but may over-stick.

**Risk.** Low-medium. Name-resolution tests (`instanceNameTest`,
`conflicting_instance_names`, `default_names`,
`movieclip_name_from_timeline`) need to keep passing.

## Phase 6 — Regression battery

**Required-pass guardrail (must not regress):**

- **Goto/rewind:** `goto_rewind1/2/3`, `execution_order1/2/3`,
  `goto_execution_order/2`, `goto_both_ways1/2`, `rewind_depth`,
  `goto_frame`, `goto_frame_test` (currently PASS in CI),
  `goto_frame2`, `goto_label`, `goto_methods`. All exercise
  display-list rebuilding under various goto patterns.
- **Loop:** `simple_loop_test`, `loop/loop_test2-9`,
  `place_and_remove_object_test`,
  `reverse_execute_PlaceObject2_test1/2`. These exercise natural
  wrap-back and re-placement.
- **Naming:** `conflicting_instance_names`, `default_names`,
  `movieclip_name_from_timeline`, `place_and_lookup`,
  `instanceNameTest`, `attachMovieTest`. Phase 5 risk surface.
- **Property setters:** Any AVM1 test that uses `_x`/`_y`/etc.
  with a subsequent timeline modify. Search for tests that touch
  `_x`/`_y`/`_xscale`/`_yscale` and have multiple frames:
  `movieclip_state_values`, `movieclip_library_state_values`,
  `set_interval`, `clip_events`, `on_construct`, `attach_movie`,
  `init_object_order`, `register_and_init_order`. Phase 2/3 risk.
- **Misc-ming guardrail:** `displaylist_depths_test11`,
  `static_vs_dynamic1/2`, `shape_test`, `get_frame_number_test`,
  `new_child_in_unload_test`, `event_handler_scope_test`,
  `action_execution_order_test8-v5/v6`,
  `DefineEditTextVariableNameTest2`. The recently-fixed battery
  from the predecessor plan.
- **Shumway:** `duplicateMovieClip/dontremove`, `samedepth`,
  `name-coercion`.
- **Misc-swfc:** `movieclip_destruction_test2` (50/52 baseline);
  `stackscope`, `submoviegetvar`, `edittext_test1`.

**Target test:** `place_and_remove_object_insane_test` 17/22 →
potentially full PASS (22/22).

**Indirect signal:** `consecutive_goto_frame_test` (4/12) shares
no architectural pieces with this plan but does share modify-branch
machinery. Spot-check; substantive fix is in
GOTO_FIFO_UNIFICATION_PLAN.md.

## Open questions

1. **Should ratio updates be gated by `transformed_by_script`?**
   Ruffle's `apply_place_object` includes ratio in the gated
   block. But ratio is also a timeline-driven attribute (motion
   tweens use ratio); a script-set `_x` shouldn't pin ratio.
   Investigate Ruffle's exact gate set and what attributes Flash
   actually preserves vs overwrites.

2. **Color transforms.** Today our `cx_overridden` flag covers
   script-set color transforms. Should `transformed_by_script` be
   strictly orthogonal (matrix-only) or supersede `cx_overridden`?
   Cleaner to consolidate, but `cx_overridden` is already wired
   into multiple call sites.

3. **What to do about `placed_at_frame` post-Phase-4.** Today's
   `placed_at_frame` tracks the placement frame for `clear_after`
   semantics. Post-Phase-4, `clear_after` is gone for natural wrap,
   so the field's role narrows. Audit all readers of
   `placed_at_frame` (it's also used by sprite-init filtering and
   the survives_rewind logic in `tagPlaceObject2`'s backward
   catch-up branch).

4. **Frame-2 rename-then-natural-wrap-then-frame-0 re-place behavior
   in Flash.** Verify with the Flash Player IDE or a test SWF that
   our expected behavior (rename persists across wrap; frame 0's
   re-place doesn't undo it) matches Flash. The test's
   `output.txt` is from gnash; might not be authoritative for this
   edge case.

5. **Interaction with PlaceObject2's "modify but char_id present"
   path.** Phase 3 gates the modify branch. But PlaceObject2 with a
   different char_id at the same depth (replacement) is a different
   path — it's NEW. Should `transformed_by_script` clear on
   replacement? Yes (the new placement is unrelated to the script's
   prior writes). Audit the placement vs modify decision.

## Estimated session budget

- Phase 1: 30 min (struct field add).
- Phase 2: 1-2 hours (audit + edit ~10-15 sites; test coverage).
- Phase 3: 1 hour (apply guard at 3 sites; verify).
- Phase 4: 3-4 hours (touchy interaction with existing
  goto_from_action / catch-up paths; high churn risk).
- Phase 5: 1-2 hours (naming preservation logic + audit).
- Phase 6: 3-4 hours (gated regression battery; expect 2-3 rounds
  of triage on the goto/rewind cluster).

Total: 9-13 hours, weighted toward Phases 4 and 6.

## Why this is the right shape

The natural wrap-back's `clear_after` is a remnant of a model where
display-list state was rebuilt from scratch each tick. Ruffle's model
is the opposite: display state is sticky, and tags only transition
the slot when the script hasn't asserted its own opinion via
`transformed_by_script`. Adopting that model end-to-end (struct
flag + setter coverage + modify-branch gate + sticky wrap-back)
converges three failing assertions onto a single coherent change.

`place_and_remove_object_insane_test` happens to exercise all three
arms simultaneously (transform preservation, name preservation,
display-state preservation), making it a strong indicator test for
the change. Other tests exercise these arms partially.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `superseded/GOTO_CATCHUP_HYGIENE_PLAN.md` | Predecessor plan. This is its Phase 7 split out. |
| `complete/GOTO_FIFO_UNIFICATION_INCREMENTAL_PLAN.md` | Sibling spin-off (Phase 6, shipped via the incremental rewrite). Independent code paths but shared catch-up machinery; spot-check no cross-regression. |
| Existing `cx_overridden` (Color setRGB / setTransform path) | Phase 2/3 pattern is identical; `transformed_by_script` is the matrix-side equivalent. |
| Existing `depth_swapped` (`tagPlaceObject2` modify guard) | Phase 3's new guard sits alongside this; they compose. |
| `ACCEPTED_DIFFS.md` (avm1) | If after Phases 1-6 some pre-existing test's behavior is now divergent from Flash for documented reasons, document there. |
