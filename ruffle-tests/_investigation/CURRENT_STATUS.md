# Current Ruffle Test Status

Last updated: 2026-02-23

## Quick Summary

- **Pass rate (CI, last run)**: 330/619 (53.3%)
- **Main failure types**: output_mismatch (279), segfault (5), runtime_error (4), timeout (1)
- **Recent gains**: MovieClipLoader class (+5 MCL tests), _level management (+2 loadmovienum tests), actionGetURL loadMovie (+1 loadmovie_fail), initVarArray child SWF protection, loadMovie multi-SWF infrastructure, input event dispatch (+18 tests), Stage.scaleMode onResize

## Crashes and Errors (8 tests)

| Test | Status | Match | Notes |
|------|--------|-------|-------|
| funky_function_calls | segfault | 9/56 | Function call edge cases |
| goto_methods | segfault | 8/40 | MovieClip.gotoAndStop/gotoAndPlay with extreme values |
| native_objects_swf6 | segfault | 0/84 | Crashes constructing native Flash classes (filters, geom, etc.) |
| native_objects_swf7 | segfault | 0/84 | Same root cause as swf6 |
| native_objects_swf8 | segfault | 0/84 | Same root cause as swf6 |
| movieclip_invalid_get_bounds_6 | compile_fail | 0/? | Needs button/clip_actions symbol renaming (fixed locally, not in CI yet) |
| movieclip_invalid_get_bounds_7 | compile_fail | 0/? | Same fix as _6 (fixed locally, not in CI yet) |
| timeout | timeout | 0/0 | setTimeout/clearTimeout not implemented |

## Top Near-Passing Tests (best ROI to fix)

### Already fixed (passing in CI)
| Test | Result | Fix |
|------|--------|-----|
| `movieclip_depth_methods` | 98/98 ✅ | Fixed in previous commits |
| `boxed_primitives` | 24/24 ✅ | Fixed in previous commits |
| `issue_1104` | 2/2 ✅ | Fixed in previous commits |
| `extends_native_type` | 11/11 ✅ | Fixed in previous commits |
| `stage_property_representation` | 586/586 ✅ | F64 bug in actionSetProperty |
| `stage_object_enumerate` | 4/4 ✅ | Stage child enumeration |
| `stage_display_state` | 16/16 ✅ | displayState property + onFullScreen |
| `stage_scale_mode` | 39/39 ✅ | onResize broadcast + viewport dims + broadcastMessage MC variable fallback |

### Near-passing (>=90%)
| Test | Match | Issue |
|------|-------|-------|
| `date` | 6284/6335 (99.2%) | Unfixable edge cases (locale-dependent) |
| `selection` | 434/454 (95.6%) | getBeginIndex/getCaretIndex/getEndIndex need actual selection tracking |
| `frame_size_translated_positive` | 20/21 (95.2%) | Missing "Pressed shape1" — needs onPress for named shapes |
| `frame_size_translated_negative` | 20/21 (95.2%) | Same — needs shape hit-test infrastructure |
| `stage_object_properties` | 226/241 (93.8%) | _width/_height↔scale coupling, rotation, original bounds |
| `stage_object_properties_swf6` | 214/231 (92.6%) | Same as above, SWF6 variant |

### 80-90%
| Test | Match | Issue |
|------|-------|-------|
| `movieclip_focusenabled` | **PASS** ✅ | Fixed: dot-path resolution in getMovieClipByTarget |
| `stage_object_children` | 68/83 (81.9%) | _level addressing, child vs property priority |
| `function_base_clip_readded` | 9/11 (81.8%) | _parent resolution after removal+re-add |
| `this_scoping` | 42/52 (80.8%) | `this` binding in various call contexts |

### 70-80%
| Test | Match | Issue |
|------|-------|-------|
| `as_set_prop_flags` | 62/79 (78.5%) | ASSetPropFlags with valueOf/toString coercion |
| `movieclip_hittest` | **PASS** ✅ | hitTest point + clip, coordinate transforms |
| `edittext_restrict` | 147/191 (77.0%) | TextField.restrict pattern matching |
| `tab_ordering_tabbable` | 36/47 (76.6%) | Tab navigation |
| `tab_ordering_automatic_order_same_position` | 9/12 (75.0%) | Tab navigation |
| `rewind_depth` | 22/30 (73.3%) | Backward goto depth handling |
| `add_property` | 11/15 (73.3%) | Object.addProperty |
| `attach_movie` | **PASS** ✅ | Fixed: deferred init dedup + sprite child persistence |
| `empty_movieclip_can_attach_movies` | **PASS** ✅ | Fixed: sprite display list persistence for child lookup |

## Plan Implementation Status

| Plan | Status | Tests Passing | Key Remaining |
|------|--------|--------------|---------------|
| DATE_PLAN | **FULLY COMPLETE** | 8+ tests; `date` at ~99.2% | — |
| TRY_CATCH_PLAN | **FULLY COMPLETE** | `try_catch_finally` 118/118 ✅ | — |
| MATH_PLAN | **FULLY COMPLETE** | 4/4 pass | — |
| ENUMERATION_PLAN | **FULLY COMPLETE** | 5/5 pass | — |
| XML_PLAN | **ALL PHASES COMPLETE** | 24/26 active tests pass | xml_to_string (11/13), xml_child_nodes_edge_cases (3/4) |
| ARRAY_METHODS_PLAN | **FULLY COMPLETE** | All tests pass | — |
| OBJECT_WATCH_PLAN | **Phase 1 DONE** | 3/4 pass | `watch_textfield` needs MC watcher in SetMember |
| GLOBALS_PLAN | **Phases 1-7 COMPLETE** | globals_swf6/7/8, primitive_type_globals PASS | Phase 8 (property flags) |
| STRING_PLAN | **Phases 1-4 COMPLETE** | 4/4 method tests + string_ops_swf6 pass | String paths blocked by MC infra |
| TEXTFIELD_PLAN | **Phases 1-3 DONE, Phase 5 PARTIAL** | 25+ tests pass | Phase 4 (scroll), Phase 5 (htmlText), Phase 6 (layout) |
| MOVIECLIP_PLAN | **Phases 1-5, 7-9 DONE** | 17 tests pass ✅ | Phase 6 (events) |
| CLONE_DUPLICATE_PLAN | **Phase 1 COMPLETE** | 2/5 pass | clone_sprite_edittext* needs TF clone |
| WITH_SCOPE_PLAN | **FULLY COMPLETE** | `with_variable_scopes`, `with` pass ✅ | — |
| PARSING_FUNCTIONS_PLAN | **parse_int DONE** | parse_int passes | parseFloat edge cases remain |
| COLOR_OBJECT_PLAN | **COMPLETE** | extends_native_type ✅ | — |
| GEOMETRY_CLASSES_PLAN | **COMPLETE** | transform, local_to_global partial | — |
| STAGE_PLAN | **Phases 1,5,7 DONE** | stage_display_state ✅, stage_scale_mode ✅, stage_property_representation ✅, stage_object_enumerate ✅ | Phase 2 (width↔scale), Phase 4 (_level), Phase 8 (children) |
| STAGE_FRAME_PROPS_PLAN | **Phases 1,5 DONE** | Several stages pass | Phase 2 (shape bounds), Phase 3 (content bounds) |
| INPUT_EVENTS_PLAN | **Phases 1-3 DONE** | 22+ input tests pass | Phase 4 (rollover/rollout) |
| SELECTION_PLAN | **Partial** | selection at 434/454 | getBeginIndex/getCaretIndex/getEndIndex need actual selection tracking |
| OOP_SUPER_EXTENDS_PLAN | Not started | 0/8 | `super` keyword non-functional |
| REGISTERCLASS_PLAN | Not started | 0/7 | Object.registerClass, attachMovie |
| PROTOTYPE_OBJECT_PLAN | Not started | 0/12 | addProperty, __resolve, property flags |
| NATIVE_INTROSPECTION_PLAN | Not started | 0/5 | native_objects_swf6/7/8 segfault |
| TELLTARGET_PLAN | Not started | 0/3+ | tellTarget scope, path resolution |
| TIMER_PLAN | Not started | 0/3 | setInterval, setTimeout |
| FOCUS_SYSTEM_PLAN | **3/6 PASS** → `blocked/` | focus_root_movie, focusrect_focuslost, movieclip_focusenabled ✅ | Remaining blocked by closure capture bug |
| TAB_ORDERING_PLAN | Not started | 0/16 | Tab key focus navigation |
| DRAG_DROP_PLAN | Not started | 0/4 | startDrag/stopDrag |
| LOADMOVIE_PLAN | **Phases 0-5 DONE** | 12/49 pass | Phase 6 (globals), Phase 7 (loadVariables) |
| UNLOAD_PLAN | **DONE** (via LOADMOVIE_PLAN) | 3/3 pass (unloadmovie, unloadmovie_method, unloadmovienum) | — |
| BUTTON_PLAN | **6/14 PASS** → `blocked/` | button_children, button_goto, button_order, button_properties_special_cases, button_v5, button_v6 ✅ | Remaining 8 blocked on key dispatch, enterFrame ordering, loadMovie |
| HIT_TESTING_PLAN | **Phases 1-6 DONE** → `blocked/` | 4 PASS + partial gains | Remaining blocked by loadMovie (compile failures now fixed), mouse events, morph interp |

## Recommended Work Order

### Highest ROI — near-passing tests
1. **STAGE_PLAN Phase 2** (width↔scale coupling) — `stage_object_properties` 226→~235/241, `stage_object_properties_swf6` 214→~225/231
2. **STAGE_PLAN Phase 4** (_level addressing) — `stage_object_children` 68→~78/83

### Medium ROI — feature phases with multiple test payoff
3. **OOP_SUPER_EXTENDS_PLAN** — `super` keyword, 8 tests
4. **PROTOTYPE_OBJECT_PLAN** — addProperty, __resolve, 12 tests
5. **REGISTERCLASS_PLAN** — registerClass + attachMovie, 7 tests (also fixes `attach_movie`, `empty_movieclip_can_attach_movies`)

### Lower ROI — new features
6. **NATIVE_INTROSPECTION_PLAN** — fix 3 segfaults (native_objects_swf6/7/8), would prevent 252 expected lines from crashing
7. **TIMER_PLAN** — setInterval/setTimeout, 3 tests
8. **TELLTARGET_PLAN** — tellTarget scope, 3+ tests
