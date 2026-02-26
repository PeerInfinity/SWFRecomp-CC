# Current Ruffle Test Status

Last updated: 2026-02-25

## Quick Summary

- **Pass rate (CI, last run)**: 364/619 (58.8%) — local estimate with new fixes: ~372/619
- **Main failure types**: output_mismatch (~255), segfault (5), runtime_error (4), compile_fail (many due to FrameLabelEntry typedef conflict), timeout (1)
- **Recent gains**: Mouse events complete (mouse_pos, mouse_pos_with_scale_factor, mouse_events_visible_enabled, click_block all PASS). Frame navigation complete. Timer system. Button _visible/_enabled gating. Middle mouse button support.

## Crashes and Errors (8 tests)

| Test | Status | Match | Notes |
|------|--------|-------|-------|
| funky_function_calls | segfault | 9/56 | Function call edge cases |
| goto_methods | ~~segfault~~ PASS | 41/41 ✅ | Fixed: MC dispatch, ECMAScript ToInt32, sprite labels |
| native_objects_swf6 | segfault | 0/84 | Crashes constructing native Flash classes (filters, geom, etc.) |
| native_objects_swf7 | segfault | 0/84 | Same root cause as swf6 |
| native_objects_swf8 | segfault | 0/84 | Same root cause as swf6 |
| movieclip_invalid_get_bounds_6 | runtime_error | 0/0 | FrameLabelEntry typedef fixed; now hits runtime error |
| movieclip_invalid_get_bounds_7 | runtime_error | 0/0 | Same as _6 |
| timeout | timeout | 0/0 | Infinite loop — needs script execution timeout mechanism |

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
| `stage_object_properties` | 241/241 ✅ | Was already passing in CI |
| `stage_object_properties_swf6` | 231/231 ✅ | _visible undefined/null no-op fix |
| `mcl_mislabeled_target` | 6/6 ✅ | instanceof MovieClip for MOVIECLIP type |
| `loadmovie_flashvars` | 4/4 ✅ | FlashVars URL query parsing + child context switch |
| `moviecliploader_flashvars` | 4/4 ✅ | FlashVars URL query parsing + MCL child context switch |
| `mcl_as_broadcaster` | 12/12 ✅ | this binding fix in broadcastMessage type 1 callbacks |
| `textfield_props_swf5` | 175/175 ✅ | SWF5 TextField toString → [type Object] |
| `textfield_variable` | 81/81 ✅ | TextField variable binding |
| `clip_events` | ✅ | Was SEGFAULT, now passing |
| `slash_syntax` | 14/14 ✅ | Slash-path colon syntax |
| `string_paths_basic` | 4/4 ✅ | Basic path resolution |
| `attach_movie` | ✅ | Deferred init dedup + sprite child persistence |
| `empty_movieclip_can_attach_movies` | ✅ | Sprite display list persistence |
| `define_function2_preload` | 13/13 ✅ | DefineFunction2 preload flags |
| `function_suppress_and_preload` | 28/28 ✅ | DefineFunction2 suppress+preload |
| `define_function2_preload_order` | 4/4 ✅ | Reverse function registry lookup |
| `swf5_no_closure` | 19/19 ✅ | SWF5 context switch for MC user-methods |
| `execution_order2` | 7/7 ✅ | Deferred sprite init ordering |
| `execution_order3` | 4/4 ✅ | 3-phase goto sprite init ordering |
| `goto_execution_order2` | 2/2 ✅ | Placement-ordered sprite init |
| `as_set_prop_flags_version` | 31/31 ✅ | ASSetPropFlags version gating |
| `as_set_prop_flags_version_swf5-9` | 1/1 each ✅ | Version-specific variants |
| `set_interval` | 27/27 ✅ | Timer system (setInterval/setTimeout/clearInterval) |
| `register_class_return_value` | 16/16 ✅ | Object.registerClass string coercion |
| `movieclip_default_state` | 69/69 ✅ | createEmptyMovieClip totalframes, getBytesLoaded, _url format |
| `add_property` | 15/15 ✅ | addProperty on Arrays (getter/setter for length and indexed props) |
| `as_set_prop_flags` | 79/79 ✅ | ASSetPropFlags valueOf/toString coercion on arguments |
| `init_object_order` | 15/15 ✅ | attachMovie initObject addProperty setter invocation |
| `goto_frame` | 12/12 ✅ | _currentframe sync during natural frame advance |
| `goto_frame2` | 44/44 ✅ | GotoFrame2 rewrite: wrapping arithmetic, label lookup, scene_bias fix, deferred script queue |
| `goto_label` | 13/13 ✅ | Frame label support (recompiler already had it, needed --recompile) |
| `mouse_pos` | 666/666 ✅ | Ruffle-compatible matrix composition + double precision + frame loop fix |
| `mouse_pos_with_scale_factor` | 261/261 ✅ | pixel_ratio support (VIEWPORT_WIDTH/FRAME_WIDTH) |
| `mouse_events_visible_enabled` | 12/12 ✅ | Button _visible/_enabled gating + middle mouse button |
| `click_block` | 5/5 ✅ | Sprite display list bounds computation for hit testing |

### Near-passing (>=90%)
| Test | Match | Issue |
|------|-------|-------|
| `date` | 6284/6335 (99.2%) | Unfixable edge cases (locale-dependent) |
| `movieclip_getbounds` | 189/191 (99.0%) | Morph shape bounds interpolation rounding |
| `selection` | 435/455 (95.6%) | getBeginIndex/getCaretIndex/getEndIndex need actual selection tracking |
| `hittest_morph` | 67/70 (95.7%) | Morph shape bounds interpolation |
| `frame_size_translated_positive` | 20/21 (95.2%) | Missing "Pressed shape1" — needs onPress for named shapes |
| `frame_size_translated_negative` | 20/21 (95.2%) | Same — needs shape hit-test infrastructure |
| `property_invalid_base_clip` | 34/36 (94.4%) | getProperty path resolution without leading _root |

### 80-90%
| Test | Match | Issue |
|------|-------|-------|
| `movieclip_library_state_values` | 69/78 (88.5%) | Library sprite default state values; segfaults after line 73 |
| `string_paths_other` | 31/36 (86.1%) | MC removal/re-creation slash path resolution |
| `super_edge_cases` | 33/39 (84.6%) | makeSuperWith: SUPER value as __proto__ (3 lines), addProperty virtual __constructor__ (3 lines) |
| `function_base_clip_readded` | 10/12 (83.3%) | _parent resolution after removal+re-add |
| `stage_object_children` | 68/83 (81.9%) | _level addressing, child vs property priority |
| `function_base_clip_removed` | 21/26 (80.8%) | base_clip after function definer removed |

### 70-80%
| Test | Match | Issue |
|------|-------|-------|
| `edittext_restrict` | 147/191 (77.0%) | TextField.restrict pattern matching |
| `tab_ordering_tabbable` | 36/47 (76.6%) | Tab navigation |
| `tab_ordering_automatic_order_same_position` | 9/12 (75.0%) | Tab navigation |
| `rewind_depth` | 22/30 (73.3%) | Backward goto depth handling |
| `add_property` | 11/15 (73.3%) | Object.addProperty prototype chain getter invocation |

### FrameLabelEntry compile_fail (FIXED)
202 tests had stale `FrameLabelEntry` typedef in generated tagMain.c conflicting with tag.h. Fixed by removing the stale typedefs from all generated files. The recompiler was already updated to not emit the typedef, but pre-existing generated files needed cleanup. Many tests that were compile_fail now compile and run (some pass, some have output_mismatch).

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
| CLONE_DUPLICATE_PLAN | **Phase 1 COMPLETE** | 3/5 pass + clip_events ✅ | clone_sprite_edittext* needs TF clone |
| WITH_SCOPE_PLAN | **FULLY COMPLETE** | `with_variable_scopes`, `with` pass ✅ | — |
| PARSING_FUNCTIONS_PLAN | **parse_int DONE** | parse_int passes | parseFloat edge cases remain |
| COLOR_OBJECT_PLAN | **COMPLETE** | extends_native_type ✅ | — |
| GEOMETRY_CLASSES_PLAN | **COMPLETE** | transform, local_to_global partial | — |
| STAGE_PLAN | **Phases 1,2,5,7 DONE** | stage_display_state ✅, stage_scale_mode ✅, stage_property_representation ✅, stage_object_enumerate ✅, stage_object_properties ✅, stage_object_properties_swf6 ✅ | Phase 4 (_level addressing), Phase 8 (children) |
| STAGE_FRAME_PROPS_PLAN | **Phases 1,5 DONE** | Several stages pass | Phase 2 (shape bounds), Phase 3 (content bounds) |
| INPUT_EVENTS_PLAN | **Phases 1-3 DONE** | 22+ input tests pass | Phase 4 (rollover/rollout) |
| SELECTION_PLAN | **Partial** | selection at 434/454 | getBeginIndex/getCaretIndex/getEndIndex need actual selection tracking |
| OOP_SUPER_EXTENDS_PLAN | **Core complete** | 6/8 pass (as2_oop ✅, extends_native_type ✅, as2_super_and_this_v6 ✅, as2_super_and_this_v8 ✅, as2_super_via_manual_prototype ✅, extends_chain ✅) | `super_edge_cases` 33/39 — remaining 6 lines = makeSuperWith (SUPER as __proto__) + addProperty virtual __constructor__; `funky_function_calls` segfaults |
| REGISTERCLASS_PLAN | **Phases 0-3 DONE** | register_underflow ✅, register_globals_across_frames ✅, attach_movie ✅, empty_movieclip_can_attach_movies ✅, register_class_return_value ✅ | Phases 4-5: constructor dispatch timing, per-call vs end-of-frame |
| PROTOTYPE_OBJECT_PLAN | **Substantially implemented** | 10/12 pass | Remaining: `__resolve` hook, InitObject setters; add_property ✅, as_set_prop_flags ✅ |
| NATIVE_INTROSPECTION_PLAN | Not started | 0/5 | native_objects_swf6/7/8 segfault |
| TELLTARGET_PLAN | **PARTIAL** | slash_syntax ✅, string_paths_basic ✅ | tellTarget scope, path resolution, eval() |
| TIMER_PLAN | **Phases 1-2 DONE** | 1/3 pass (set_interval ✅) | timer_run_actions blocked on REGISTERCLASS_PLAN (attachMovie); timeout needs script timeout mechanism |
| FOCUS_SYSTEM_PLAN | **3/6 PASS** → `blocked/` | focus_root_movie, focusrect_focuslost, movieclip_focusenabled ✅ | Remaining blocked by mouse events + key dispatch ordering (closure bug resolved) |
| TAB_ORDERING_PLAN | Not started | 0/16 | Tab key focus navigation |
| DRAG_DROP_PLAN | **COMPLETE** | 4/4 pass ✅ | All tests already passing |
| LOADMOVIE_PLAN | **Phases 0-5 + FlashVars DONE** | 18/49 pass | Phase 6 (globals) NOT FEASIBLE, Phase 7 (loadVariables) → LOADVARIABLES_PLAN |
| LOADVARIABLES_PLAN | **Phases 1-2 DONE** | 2/4 pass | loadvariables + loadvariablesnum ✅; loadvariables2 needs TIMER_PLAN; loadvariables_method needs log_fetch |
| ROOT_REPLACEMENT_PLAN | **Phases 1-4 DONE** | 1/4 pass | loadmovie_replace_root ✅; mcl_loadclip_replace_root blocked by MTASC class support; swf7→5/6 deferred |
| LOADMOVIE_REMAINING_PLAN | **Partially blocked** | 0/5 | dynamic_props clearing done; var_persistence needs setTimeout; others need cross-version/__proto__ |
| UNLOAD_PLAN | **DONE** (via LOADMOVIE_PLAN) | 3/3 pass (unloadmovie, unloadmovie_method, unloadmovienum) | — |
| BUTTON_PLAN | **6/14 PASS** → `blocked/` | button_children, button_goto, button_order, button_properties_special_cases, button_v5, button_v6 ✅ | Remaining 8 blocked on key dispatch, enterFrame ordering, loadMovie |
| SWF_VERSION_SEMANTICS_PLAN | **Phases 1-3 COMPLETE** | swf6_case_insensitive ✅, swf6_string_as_bool ✅, swf4_actions_coercion_order ✅ | Phase 4 (cross-version calls) blocked on loadMovie + per-function version tracking |
| THIS_BINDING_PLAN | **FULLY COMPLETE** | this_swf6 ✅, mutable_this ✅ | — |
| HIT_TESTING_PLAN | **Phases 1-6 DONE** → `blocked/` | 4 PASS + movieclip_hittest_shapeflag 266/338 | Remaining blocked by loadMovie, mouse events, morph interp |

## Recommended Work Order

### Highest ROI — near-passing tests
1. **STAGE_PLAN Phase 4** (_level addressing) — `stage_object_children` 68→~78/83
2. **movieclip_getbounds** — 189/191, morph shape bounds rounding issue (2 lines)

### Medium ROI — feature phases with multiple test payoff
3. **OOP_SUPER_EXTENDS_PLAN** — core super done (6/8 pass); `super_edge_cases` 36/39 — remaining 3 lines blocked by SUPER value stored as __proto__ in makeSuperWith pattern
4. **REGISTERCLASS_PLAN Phases 1-2** — ExportAssets parsing + attachMovie handler (Phase 0 register fixes already passing)
5. **FRAME_NAVIGATION_PLAN Phase 1-2** — frame labels + execution ordering, 4 tests (goto_frame, goto_frame2, goto_label, goto_methods)
6. **PROTOTYPE_OBJECT_PLAN** — addProperty, __resolve, 4 remaining tests
7. **TELLTARGET_PLAN Phase 1** — core path resolution, ~212 lines across 8+ tests (slash_syntax + string_paths_basic already passing)

### Lower ROI — new features
8. ~~**TIMER_PLAN**~~ — **DONE** (Phases 1-2 complete, set_interval PASS). timer_run_actions blocked on REGISTERCLASS_PLAN.
9. **NATIVE_INTROSPECTION_PLAN** — fix 3 segfaults (native_objects_swf6/7/8)
10. **REGISTERCLASS_PLAN Phases 1-5** — full ExportAssets + registerClass + constructor invocation, ~7-10 tests

### super_edge_cases Blockers (33/39 — 6 lines remaining)

Lines 1-33 match. Lines 34-39 fail (shifted output). Remaining failures:

**Lines 34-36: `makeSuperWith` pattern — SUPER value as `__proto__`**
- `makeSuperWith(obj.__proto__)` creates a helper with `getSuper: function() { return super; }`, calls it, and stores the returned SUPER value as `obj.__proto__`
- When super() runs, `walkProtoChain(this, depth)` calls `getProperty(current, "__proto__")` which returns an `ACTION_STACK_VALUE_SUPER` (type 16) instead of an OBJECT — so the chain walk returns NULL
- Fix requires: `walkProtoChain` (or `findPropertyStructWithPrototype`) to resolve SUPER values stored as `__proto__` into actual prototype chain objects
- Impact: 3 lines (34-36)

**Fixed (previously blocking)**:
- ~~Lines 27-31: addProperty-based virtual `__constructor__`~~ — **FIXED**: replaced `getPropertyWithPrototype` with `findPropertyStructWithPrototype` + getter invocation at all 3 super() `__constructor__` lookup sites
- ~~Lines 37-39: `_root` as `__proto__`~~ — **Now passes** (these lines output correctly once prior addProperty lines were fixed)

### Dependency Blockers (plans blocking other plans)
- ~~**TIMER_PLAN**~~ — **RESOLVED** (Phases 1-2 done, set_interval ✅). loadvariables2 still blocked on compile issues; timer_run_actions blocked on REGISTERCLASS_PLAN
- **OOP_SUPER_EXTENDS_PLAN** — core super() done; addProperty getters now invoked in super() paths; remaining 3 lines in `super_edge_cases` blocked by SUPER-as-__proto__ resolution (makeSuperWith pattern)
- **MOUSE_EVENTS_PLAN** blocks: FOCUS_SYSTEM_PLAN, BUTTON_PLAN (8 tests), DRAG_DROP_PLAN, CLONE_DUPLICATE_PLAN (clip_event_propagation_order)
- **FOCUS_SYSTEM_PLAN** blocks: TAB_ORDERING_PLAN (16 tests)
- **TELLTARGET_PLAN** blocks: THIS_BINDING_PLAN Phase 6 (this_scoping remaining 10 lines)
- **REGISTERCLASS_PLAN** blocks: MOVIECLIP_PLAN Phase 6 (clip_constructors), CLONE_DUPLICATE_PLAN (on_construct), TIMER_PLAN (timer_run_actions partially)
- ~~**CLOSURE_CAPTURE_PLAN**~~ — **RESOLVED** (moved to completed/). Remaining test failures in focus_keyboard_press, focus_mouse, focus_mouse_rollout now blocked by FOCUS_SYSTEM_PLAN + MOUSE_EVENTS_PLAN
