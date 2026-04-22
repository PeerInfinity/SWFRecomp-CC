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
| get_frame_number_test (misc-ming) | 87.1% | 27 | 31 | Incomplete — `gotoAndStop(4.8)` / `gotoAndStop(6.1)` should land on frame 5. Our `actionGotoFrame2` is Ruffle-style (non-integer → no-op); Flash/Gnash rounds. |
| shape_test (misc-ming) | 71.4% | 15 | 21 | Incomplete — shapes promoted to movieclip should have `getDepth() == undefined` and should not appear via `getInstanceAtDepth`. Needs a "shape MC is not scriptable for depth-enumeration" branch. |
| RollOverOutTest (misc-ming) | 80.0% | 4 | 5 | Skipped — requires mouse input simulation via `input.json`; our runner doesn't drive input. |
| displaylist_depths_test11 (misc-ming) | 60.0% | 9 | 15 | Incomplete — ordering mismatch around `onClipConstruct` vs assigning `_root.depth3Constructed` (registerClass constructor vs parent script ordering). |
| edittext_test1 (misc-swfc) | 76.6% | 36 | 47 | Incomplete — TextField variable binding: (a) re-binding `edtext1.variable` to new name should create that variable on the container, (b) switching variable back should preserve the prior value. |

For each, run `--diff --verbose` and cluster the diff lines by type. Many will resolve with a single targeted fix that's shared across a handful of near-passing tests.

## Phase 2 — Mid-rate cluster fixes

Failures at 10-80% match, grouped by apparent feature cluster. The cluster shape suggests which existing subsystem is being stressed:

### Cluster: `action_order/*` (10 tests, 0-73%)

Deferred-DoAction / sprite-init execution order. Similar to the AVM1 `execution_order*` fixes in `avm1/_investigation/complete/SESSION_NOTES.md`. The two near-passing tests (`action_execution_order_test8-v5` and `-v6`, both at 72.7%) are prime investigation candidates. The long tail (ActionOrderTest3 at 5.7%, ActionOrderTest4 at 7.4%) likely combines multiple ordering bugs.

### Cluster: `displaylist_depths/*` (6 tests, 13-80%)

Display list depth transformations, clip_depth, swap_depths, level vs timeline depth math. Overlaps the `movieclip_methods_with_loaded_image` / `attachMovie` / `duplicateMovieClip` surfaces. Near-passing (`test11` at 80%) suggests a single small edge.

### Cluster: `loop/*` (10 tests, 3-73%)

`while` / `for` / `do-while` opcode handling. `loop_test9` at 73% and `loop_test3` at 69% are attack points. `loop_test10` at 3.6% suggests a feature not implemented yet (probably `for-in` or iterator-style).

### Cluster: `register_class/*` (4 tests, 4-21%)

`Object.registerClass` combined with attachMovie / frame scripting. Overlaps AVM1's `complete/REGISTERCLASS_PLAN.md`. Low rates suggest the tests exercise edges not covered by AVM1 tests.

### Cluster: `loading/*` (2 tests)

- `loadMovieTest` — 6.2%. Overlaps AVM1 `complete/LOADMOVIE_PLAN.md` (32/35 AVM1 loadMovie tests pass).
- `LoadVarsTest` — compile_fail. Needs recompiler triage separately.

### Cluster: movieclip/timeline (flat) — ~25 tests at 10-80%

Various tests exercising `attachMovie`, `duplicateMovieClip`, `goto`, `unload`. Candidates for near-passing attack:

- `place_and_remove_object_test` (76.9%)
- `attachMovieTest` (75.0%)
- `new_child_in_unload_test` (72.7%)
- `timeline_var_test` (72.7%)
- `static_vs_dynamic2` (72.2%)
- `attachMovieLoopingTest` (70.7%)
- `reverse_execute_PlaceObject2_test2` (70.0%)

Also `movieclip_destruction_test2` (73.2%) from misc-swfc.

### Cluster: text / edittext

- `DefineTextTest` (68.8%), `DefineEditTextVariableNameTest*` (60-74%), `EmbeddedFontTest` (57.5%).
- `edittext_test1` (76.6% — near-passing).
Text field property coverage; may overlap AVM1's `TEXTFIELD_PLAN`.

### Cluster: events / input

- `event_handler_scope_test` (62.5%)
- `ResolveEventsTest` (53.3%)
- `DragDropTest` (40.0%)
- `key_event_test` (13.6%)
- `ButtonEventsTest` (2.4%)
- `mouse_drag_test` (50.0%) — misc-swfc

### Cluster: misc-swfc remainder

- `stackscope` (72.7%)
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
