# Current Ruffle Test Status

Last updated: 2026-02-21 (uncommitted, pending commit + CI)

## Quick Summary

- **Pass rate (CI, last run)**: 263/619 (42.5%) unfiltered, **259/479 (54.1%) filtered**
- **Estimated after current changes**: ~265/479 filtered (+6 since last CI: transform, goto_rewind3, with, edittext_html_entity, target_path, root_onload)
- **Main failure types**: output_mismatch (~207), segfault (5), runtime_error (1), timeout (1)
- **Recent gains**: `edittext_html_entity` (3→4/4), `target_path` (11→14/14), `root_onload` (0→1/1), `transform` (69→70/70), `goto_rewind3` (2→2/2), `with` (46→49/49)

## Crashes and Errors (7 tests)

| Test | Status | Match | Notes |
|------|--------|-------|-------|
| goto_methods | segfault | 8/40 | MovieClip.gotoAndStop/gotoAndPlay with extreme values |
| native_objects_swf6 | segfault | 0/84 | Crashes constructing native Flash classes (filters, geom, etc.) |
| native_objects_swf7 | segfault | 0/84 | Same root cause as swf6 |
| native_objects_swf8 | segfault | 0/84 | Same root cause as swf6 |
| placeobject_occupied_depth | segfault | 0/0 | PlaceObject at occupied depth causes crash |
| movieclip_state_values | runtime_error | 1/114 | exit code -6 (abort) |
| timeout | timeout | 0/0 | setTimeout/clearTimeout not implemented |

### Resolved crashes (from previous updates)
- `enumerate`, `function_base_clip_removed`, `init_object_order`, `register_and_init_order`, `register_class` — no longer segfault
- `try_catch_finally` — **now fully passing** (118/118) on CI
- `movieclip_hittest_shapeflag` — no longer compile_fail, back to output_mismatch

## Top Near-Passing Tests (best ROI to fix)

### Recently fixed (commit 7b56f94)
| Test | Result | Fix |
|------|--------|-----|
| `transform` | 70/70 ✅ | pixelBounds for level-1 nested sprites |
| `goto_rewind3` | 2/2 ✅ | Backward catch-up intermediate frames no longer overwrite preserved display entries |
| `with` | 49/49 ✅ | AVM1 closure scope chain capture (WITH scopes captured at definition time) |

### 1 extra line (frame count bug)
| Test | Match | Issue |
|------|-------|-------|
| `issue_1104` | 2/2 (100% match, 1 extra line) | Outputs 3 lines instead of 2 — enterFrame fires one extra time (3 frames produces 3 events, expected 2) |

### 1 line diff
| Test | Match | Issue |
|------|-------|-------|
| `movieclip_depth_methods` | 97/98 (99.0%) | `_x` returns 0 instead of 75 after swapDepths — property not preserved |
| `boxed_primitives` | 23/24 (95.8%) | `delete str.length` on boxed String — should preserve virtual `.length` property |
| `extends_native_type` | 10/11 (90.9%) | `mc.transform.colorTransform.redOffset` returns 0 — flash.geom.Transform not wired to MC |
| `frame_size_translated_negative` | 20/21 (95.2%) | Stage bounds precision |
| `frame_size_translated_positive` | 20/21 (95.2%) | Stage bounds precision |

### 3-6 lines diff
| Test | Match | Issue |
|------|-------|-------|
| `rewind_depth` | 26/30 (86.7%) | Backward goto depth handling |

### 80-93% match
| Test | Match | Issue |
|------|-------|-------|
| `stage_object_properties` | 223/241 (92.5%) | _width/_height with scaled children, _yscale precision |
| `stage_object_properties_swf6` | 210/231 (90.9%) | Same issues as above, SWF6 variant |
| `local_to_global` | 41/49 (83.7%) | localToGlobal/globalToLocal coordinate transforms |
| `movieclip_focusenabled` | 82/99 (82.8%) | Focus system not implemented |
| `stage_object_children` | 68/83 (81.9%) | Child clip enumeration order |
| `function_base_clip_readded` | 9/11 (81.8%) | Base clip re-addition after removal |
| `this_scoping` | 42/52 (80.8%) | `this` binding in various call contexts |

## Plan Implementation Status

| Plan | Status | Tests Passing | Key Remaining |
|------|--------|--------------|---------------|
| DATE_PLAN | **FULLY COMPLETE** | 8+ tests; `date` at ~99.2% (unfixable edge cases) | — |
| TRY_CATCH_PLAN | **FULLY COMPLETE** | `try_catch_finally` 118/118 ✅ | — |
| MATH_PLAN | **FULLY COMPLETE** | 4/4 pass | — |
| ENUMERATION_PLAN | **FULLY COMPLETE** | 5/5 pass | — |
| XML_PLAN | **ALL PHASES COMPLETE** | 24/26 active tests pass | xml_to_string (11/13), xml_child_nodes_edge_cases (3/4) |
| ARRAY_METHODS_PLAN | **FULLY COMPLETE** | All tests pass | — |
| OBJECT_WATCH_PLAN | **Phase 1 DONE** | 3/4 pass | `watch_textfield` needs MC watcher in SetMember |
| GLOBALS_PLAN | **Phases 1-7 COMPLETE** | globals_swf6/7/8, primitive_type_globals PASS | Phase 8 (property flags) |
| STRING_PLAN | **Phases 1-4 COMPLETE** | 4/4 method tests + string_ops_swf6 pass | String paths blocked by MC infra |
| TEXTFIELD_PLAN | **Phases 1-3 DONE, Phase 5 PARTIAL** | 25+ tests pass | Phase 4 (scroll), Phase 5 (htmlText), Phase 6 (layout) |
| MOVIECLIP_PLAN | **Phase 1 DONE** | Several MC tests pass | Phase 2 (depth methods nearly done — 97/98), Phase 3 (createEmptyMC) |
| CLONE_DUPLICATE_PLAN | **Phase 1 COMPLETE** | 2/5 pass | clone_sprite_edittext* needs TF clone |
| WITH_SCOPE_PLAN | **FULLY COMPLETE** | `with_variable_scopes`, `with` pass ✅ | — |
| PARSING_FUNCTIONS_PLAN | **parse_int DONE** | parse_int passes | parseFloat edge cases remain |
| COLOR_OBJECT_PLAN | Stub only | 0/4 | Color constructor + flash.geom.Transform |
| OOP_SUPER_EXTENDS_PLAN | Not started | 0/8 | `super` keyword non-functional |
| REGISTERCLASS_PLAN | Not started | 0/7 | Object.registerClass, attachMovie |
| PROTOTYPE_OBJECT_PLAN | Not started | 0/12 | addProperty, __resolve, property flags |
| NATIVE_INTROSPECTION_PLAN | Not started | 0/5 | native_objects_swf6/7/8 segfault |
| TELLTARGET_PLAN | Not started | 0/3+ | tellTarget scope, path resolution |
| TIMER_PLAN | Not started | 0/3 | setInterval, setTimeout |
| STAGE_PLAN | Not started | 0/7 | Stage object properties |
| SELECTION_PLAN | Not started | 0/2 | Focus tracking |
| FRAME_NAVIGATION_PLAN | Not started | 0/4 | Frame execution ordering bugs |
| MOUSE_EVENTS_PLAN | Not started | 0/5 | _xmouse/_ymouse, clip mouse events |
| FOCUS_SYSTEM_PLAN | Not started | 0/6 | Mouse-triggered focus |
| TAB_ORDERING_PLAN | Not started | 0/16 | Tab key focus navigation |
| DRAG_DROP_PLAN | Not started | 0/4 | startDrag/stopDrag |
| UNLOAD_PLAN | Not started | 0/3 | unloadMovie, onUnload |
| BUTTON_PLAN | Not started | 0/14 | Button actions, states |
| HIT_TESTING_PLAN | Not started | 0/17 | Coordinate transforms, bounds |

## Recommended Work Order

### Highest ROI — near-passing tests with 1-line fixes
1. **`movieclip_depth_methods`** (97/98) — fix `_x` property preservation across swapDepths
2. **`boxed_primitives`** (23/24) — protect virtual `.length` from delete on boxed String
3. **`issue_1104`** (2/2 + 1 extra) — fix enterFrame firing one extra time
4. **`extends_native_type`** (10/11) — wire flash.geom.Transform to MC

### Medium ROI — feature phases with multiple test payoff
5. **STAGE_PLAN** — stage_object_properties (92.5%), stage_object_properties_swf6 (90.9%), stage_object_children (81.9%)
6. **MOVIECLIP_PLAN Phase 2+** — depth methods, createEmptyMovieClip, more MC tests
7. **OOP_SUPER_EXTENDS_PLAN** — `super` keyword, 8 tests
8. **PROTOTYPE_OBJECT_PLAN** — addProperty, __resolve, 12 tests

### Lower ROI — new features
10. **COLOR_OBJECT_PLAN** — 4 tests, flash.geom.Transform wiring
11. **REGISTERCLASS_PLAN** — 7 tests, registerClass + attachMovie
12. **NATIVE_INTROSPECTION_PLAN** — fix 3 segfaults (native_objects_swf6/7/8)
13. **TIMER_PLAN** — setInterval/setTimeout, 3 tests
14. **TELLTARGET_PLAN** — tellTarget scope, 3+ tests
