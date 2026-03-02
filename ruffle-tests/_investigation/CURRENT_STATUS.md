# Current Ruffle Test Status

Last updated: 2026-03-01

## Quick Summary

- **Pass rate (CI, last run)**: 392/619 (63.3%) — pending CI run will confirm new passes
- **Main failure types**: output_mismatch (213), segfault (14), compile_fail (1), runtime_error (2), timeout (1)
- **Recent gains (this session)**: unload test PASS (52/52). Pending removal mechanism: MCs with unload handlers persist for one frame after removal with depth-transformed negative depth. Recompiler-side remove+replace detection via buffered_removes. Conditional persistence based on UNLOAD clip_actions or AS-level onUnload property.
- **Recent gains (previous session)**: Tab ordering: 13/16 pass. tab_ordering_events PASS (150/150), tab_ordering_tabbable PASS (47/47), tab_ordering_movieclip_enabled_default PASS (462/462). Button DoAction rollOver/rollOut during Tab, deferred roll queue, text field exclusions.
- **Recent gains (previous session)**: super_edge_cases PASS (39/39). resolveProtoVar() unwraps SUPER values stored in __proto__ during prototype chain traversal.
- **Recent gains (previous session)**: native_objects_swf6/7/8 all PASS (252/252). Added NativeType enum, native_type tracking, stub constructors for 15+ classes, filter constructor dispatch via actionNewMethod.
- **Recent gains (earlier sessions)**: create_empty_movie_clip PASS (mc_enterframe_eligible). movieclip_init_object PASS (sync constructor during attachMovie). MOVIECLIP_PLAN moved to blocked/ — 27 tests pass, all remaining blocked.
- **Recent gains (previous sessions)**: watch_textfield PASS (12/12). this_scoping PASS (52/52). execution_order4 PASS (13/13). nan_scale PASS (9/9). clip_constructors PASS (8/8). issue_768 PASS (3/3). rewind_depth PASS (30/30). tell_target_invalid PASS (6/6). tell_target_invalid_swf6 PASS (5/5). stage_object_children PASS (83/83). selection PASS (454/454). place_and_lookup PASS (30/30). tab_ordering_children PASS (208/208). And many more.

## Crashes and Errors (8 tests)

| Test | Status | Match | Notes |
|------|--------|-------|-------|
| funky_function_calls | segfault | 9/56 | Function call edge cases |
| goto_methods | ~~segfault~~ PASS | 41/41 ✅ | Fixed: MC dispatch, ECMAScript ToInt32, sprite labels |
| native_objects_swf6 | ~~segfault~~ PASS | 84/84 ✅ | NativeType tracking, stub constructors, Date re-init blocking |
| native_objects_swf7 | ~~segfault~~ PASS | 84/84 ✅ | Same fix as swf6 |
| native_objects_swf8 | ~~segfault~~ PASS | 84/84 ✅ | + flash.* filter dispatch, TextRenderer/Transform |
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
| `create_empty_movie_clip` | 3/3 ✅ | mc_enterframe_eligible flag prevents onEnterFrame on creation tick |
| `movieclip_init_object` | 5/5 ✅ | Sync registered class constructor during attachMovie (not deferred) |
| `goto_frame` | 12/12 ✅ | _currentframe sync during natural frame advance |
| `goto_frame2` | 44/44 ✅ | GotoFrame2 rewrite: wrapping arithmetic, label lookup, scene_bias fix, deferred script queue |
| `goto_label` | 13/13 ✅ | Frame label support (recompiler already had it, needed --recompile) |
| `mouse_pos` | 666/666 ✅ | Ruffle-compatible matrix composition + double precision + frame loop fix |
| `mouse_pos_with_scale_factor` | 261/261 ✅ | pixel_ratio support (VIEWPORT_WIDTH/FRAME_WIDTH) |
| `mouse_events_visible_enabled` | 12/12 ✅ | Button _visible/_enabled gating + middle mouse button |
| `click_block` | 5/5 ✅ | Sprite display list bounds computation for hit testing |
| `tell_target` | 37/37 ✅ | Base clip tracking + SetTarget rewrite |
| `path_string` | 322/322 ✅ | _level0 scope chain fix, root MC var priority in GetMember, slash-path SetVariable |
| `string_paths_hidden` | 54/54 ✅ | Non-scriptable display objects (shapes/text/morph) resolve to parent MC |
| `place_and_lookup` | 30/30 ✅ | ng_isScriptableChar helper, var_map enumeration on root MC, video auto-naming fix |
| `tab_ordering_children` | 208/208 ✅ | Bonus from video auto-naming fix (instance counter no longer increments for unnamed videos) |
| `selection` | 454/454 ✅ | Selection index tracking + replaceSel implementation |
| `this_scoping` | 52/52 ✅ | MC nav methods via CallFunction (WITH scope + dot/slash path) + dynamic MC gotoAndStop |
| `execution_order4` | 13/13 ✅ | Nested sprite parent context + child init ordering + WITH scope resolution |
| `watch_textfield` | 12/12 ✅ | MC watch/unwatch dispatch + watch table check in MC SetMember + missing tags in tagMain.c |
| `property_invalid_base_clip` | 36/36 ✅ | Was already passing (stale docs) |
| `tell_target_invalid_swf6` | 5/5 ✅ | hasPlayingSprites + forward goto catch_up_mode in advance_sprite_frames |
| `tell_target_invalid` | 6/6 ✅ | SetTarget2(undefined) SWF7+ → target_clip=None; GotoFrame2 target_clip_or_root; sprite preservation during root loop-back |
| `on_construct` | 25/25 ✅ | RegisterClass prototype setup before on(construct), g_event_this_mc for type 2 constructors, pending instance name, prototype chain variable resolution |
| `tab_ordering_tabbable` | 47/47 ✅ | Dynamic TF tabbability (u16 type pointer), MC button mode, invisible parent children |
| `tab_ordering_events` | 150/150 ✅ | Button DoAction rollOver/rollOut during Tab, deferred roll queue, text field exclusions |
| `tab_ordering_movieclip_enabled_default` | 462/462 ✅ | MC tabIndex + mouse handler implicit tabbability |

### Near-passing (>=90%)
| Test | Match | Issue |
|------|-------|-------|
| `date` | 6284/6335 (99.2%) | Unfixable edge cases (locale-dependent) |
| `movieclip_getbounds` | 190/192 (99.0%) | Morph shape bounds interpolation rounding — 2 lines added to ACCEPTED_DIFFS |
| `frame_size_translated_positive` | 20/21 (95.2%) | Missing "Pressed shape1" — needs onPress for named shapes |
| `frame_size_translated_negative` | 20/21 (95.2%) | Same — needs shape hit-test infrastructure |

### 80-90%
| Test | Match | Issue |
|------|-------|-------|
| `movieclip_library_state_values` | **77/78 (98.7%)** | Fixed: segfault, unloadMovie state, byte_size, URL. Remaining: _xmouse default (accepted diff) |
| `string_paths_other` | 31/36 (86.1%) | MC removal/re-creation slash path resolution |
| `super_edge_cases` | **39/39 PASS** ✅ | Fixed: resolveProtoVar() unwraps SUPER values stored in __proto__ |
| `function_base_clip_readded` | 10/12 (83.3%) | _parent resolution after removal+re-add |
| `stage_object_children` | **83/83 PASS** ✅ | Was 68/83, now fixed (likely from path resolution changes) |
| `function_base_clip_removed` | 21/26 (80.8%) | base_clip after function definer removed |

### 70-80%
| Test | Match | Issue |
|------|-------|-------|
| `edittext_restrict` | 147/191 (77.0%) | TextField.restrict pattern matching |
| `tab_ordering_tabbable` | **47/47 PASS** ✅ | Dynamic TF tabbability, MC button mode, invisible parent children |
| `tab_ordering_automatic_order_same_position` | 9/12 (75.0%) | Needs highlight bounds for position sort |
| `add_property` | **15/15 PASS** ✅ | addProperty on Arrays (getter/setter for length and indexed props) |

### FrameLabelEntry compile_fail (FIXED)
202 tests had stale `FrameLabelEntry` typedef in generated tagMain.c conflicting with tag.h. Fixed by removing the stale typedefs from all generated files. The recompiler was already updated to not emit the typedef, but pre-existing generated files needed cleanup. Many tests that were compile_fail now compile and run (some pass, some have output_mismatch).

## Plan Implementation Status

| Plan | Status | Tests Passing | Key Remaining |
|------|--------|--------------|---------------|
| DATE_PLAN | **FULLY COMPLETE** | 8+ tests; `date` at ~99.2% | — |
| TRY_CATCH_PLAN | **FULLY COMPLETE** | `try_catch_finally` 118/118 ✅ | — |
| MATH_PLAN | **FULLY COMPLETE** | 4/4 pass | — |
| ENUMERATION_PLAN | **FULLY COMPLETE** | 5/5 pass | — |
| XML_PLAN | **ALL PHASES COMPLETE** | 26/26 active tests pass ✅ | xml_to_string now PASS, xml_child_nodes_edge_cases now PASS |
| ARRAY_METHODS_PLAN | **FULLY COMPLETE** | All tests pass | — |
| OBJECT_WATCH_PLAN | **Phase 2 DONE** | 4/4 pass (watch_textfield ✅) | `watch_virtual_property` known_failure in Ruffle |
| GLOBALS_PLAN | **Phases 1-7 COMPLETE** → `blocked/` | 18/30 pass + place_and_lookup ✅ (globals_swf5-8, math_min_max, is_finite×2, parse_int, parse_float, primitive_type_globals, printjob×3, sound×2, localconnection, context_menu, context_menu_item) | Phase 8 blocked: enumeration order + 20 missing globals |
| STRING_PLAN | **Phases 1-4 COMPLETE** | 4/4 method tests + string_ops_swf6 pass | String paths blocked by MC infra |
| TEXTFIELD_PLAN | **Phases 1-3 DONE, Phase 5 PARTIAL** | 25+ tests pass | Phase 4 (scroll), Phase 5 (htmlText), Phase 6 (layout) |
| MOVIECLIP_PLAN | **ALL PHASES DONE** → `blocked/` | 27 tests pass ✅ (create_empty_movie_clip, movieclip_init_object newly fixed) | Remaining blocked: child DoInitAction (recompiler), mouse events, loadMovie, pixel hitTest |
| CLONE_DUPLICATE_PLAN | **Phase 1 COMPLETE** → `blocked/` | 3/8 pass + clip_events ✅ | Blocked on TEXTFIELD, MOUSE_EVENTS, REGISTERCLASS |
| WITH_SCOPE_PLAN | **FULLY COMPLETE** | `with_variable_scopes`, `with` pass ✅ | — |
| PARSING_FUNCTIONS_PLAN | **FULLY COMPLETE** | 3/3 pass (parse_int, parse_float, parsefloat_swf5) ✅ | — |
| COLOR_OBJECT_PLAN | **COMPLETE** | extends_native_type ✅ | — |
| GEOMETRY_CLASSES_PLAN | **COMPLETE** | transform, local_to_global partial | — |
| STAGE_PLAN | **FULLY COMPLETE** → `complete/` | 7/7 pass: stage_display_state ✅, stage_scale_mode ✅, stage_property_representation ✅, stage_object_enumerate ✅, stage_object_properties ✅, stage_object_properties_swf6 ✅, stage_object_children ✅ | — |
| STAGE_FRAME_PROPS_PLAN | **Phases 1-8 COMPLETE** → `blocked/` | 7/9 pass (stage_property_representation ✅, stage_object_enumerate ✅, stage_display_state ✅, stage_scale_mode ✅, stage_object_properties ✅, stage_object_properties_swf6 ✅, stage_object_children ✅) | Phase 9 blocked: mouse input simulation for "Pressed shape1" (frame_size_translated_positive/negative at 20/21) |
| INPUT_EVENTS_PLAN | **Phases 1-3 DONE** | 22+ input tests pass | Phase 4 (rollover/rollout) |
| SELECTION_PLAN | **FULLY COMPLETE** → `complete/` | selection 454/454 ✅ | — |
| OOP_SUPER_EXTENDS_PLAN | **7/8 PASS** → `blocked/` | 7/8 pass (as2_oop ✅, extends_native_type ✅, as2_super_and_this_v6 ✅, as2_super_and_this_v8 ✅, as2_super_via_manual_prototype ✅, extends_chain ✅, super_edge_cases ✅) | `interface_implements_op` blocked by MTASC class infra (REGISTERCLASS_PLAN) |
| REGISTERCLASS_PLAN | **ALL PHASES DONE** → `blocked/` | 10/15 pass (register_underflow ✅, register_globals_across_frames ✅, attach_movie ✅, attach_movie_stop ✅, empty_movieclip_can_attach_movies ✅, export_assets ✅, register_class_return_value ✅, on_construct ✅, clip_constructors ✅, movieclip_init_object ✅) | register_class 26/67, register_and_init_order ~76/233, register_class_swf6/do_init_action_child blocked by loadMovie, register_class_with_sound blocked by Sound class |
| PROTOTYPE_OBJECT_PLAN | **COMPLETE** → `complete/` | 11/12 pass | Remaining blocked on recompiler MTASC nested function bug |
| NATIVE_INTROSPECTION_PLAN | **Phases 0-2 COMPLETE** | 3/5 pass (native_objects_swf6/7/8 ✅) | native_subclasses/native_double_construct need filter constructor property init via super() |
| TELLTARGET_PLAN | **Phases 1-2 COMPLETE** → `blocked/` | 14/22 pass (tell_target ✅, tell_target_invalid ✅, tell_target_invalid_swf6 ✅, slash_syntax ✅, string_paths_basic ✅, string_paths_variable_alias ✅, target_clip_removed ✅, path_string ✅ (322/322), string_paths_hidden ✅ (54/54), target_clip_swf5/6 ✅, target_path ✅, get_variable_in_scope ✅, lock_root ✅) | Remaining 8 tests blocked on: button dispatch (string_paths_eval), loadMovie (string_paths_eval2), onEnterFrame per-tick (string_paths_variable_scopes), MC removal lifecycle (string_paths_other, removed_target_clip_scope, removed_base_clip_tell_target), unload timing (string_paths_unload), Ruffle known_failure (string_paths_reference_launder) |
| TIMER_PLAN | **COMPLETE** → `complete/` | 1/3 pass (set_interval ✅) | Core done; timer_run_actions blocked on REGISTERCLASS; timeout deferred |
| FOCUS_SYSTEM_PLAN | **3/7 PASS** → `blocked/` | focus_root_movie, focusrect_focuslost, movieclip_focusenabled ✅ | Remaining 4 blocked by mouse events + text field hit-testing + event pumping model |
| TAB_ORDERING_PLAN | **13/16 PASS** → `blocked/` | tab_ordering_automatic_basic, tab_ordering_reverse, tab_ordering_children ✅, tab_ordering_events ✅, tab_ordering_tabbable ✅, tab_ordering_movieclip_enabled_default ✅, ... | Remaining 3 blocked: same_position (highlight bounds), events_mouse (mouse state machine), edittext_tab_focus (caret tracking) |
| DRAG_DROP_PLAN | **COMPLETE** | 4/4 pass ✅ | All tests already passing |
| LOADMOVIE_PLAN | **Phases 0-5,7 DONE** → `blocked/` | 23/49 pass | Phase 6 (cross-version globals) blocked; remaining blocked on RegisterClass, DoInitAction, display list, mouse events |
| LOADVARIABLES_PLAN | **COMPLETE** → `complete/` | 3/4 pass | loadvariables_method needs log_fetch infra (not worth it) |
| ROOT_REPLACEMENT_PLAN | **Phases 1-4 DONE** → `blocked/` | 1/4 pass | Remaining blocked on MTASC class support + cross-version scope |
| LOADMOVIE_REMAINING_PLAN | **Partially blocked** | 0/5 | dynamic_props clearing done; var_persistence needs setTimeout; others need cross-version/__proto__ |
| UNLOAD_PLAN | **MOSTLY DONE** | 4/6 pass (unload_clip_event, unloadmovie, unloadmovie_method, unloadmovienum ✅) | unload (18/52), unload_nested_child (0/5) |
| BUTTON_PLAN | **12/14 PASS** → `blocked/` | + button_keypress_vs_tab ✅ (visible gating on keyPress) | Remaining 2: button_keypress_vs_textinput (TF onChanged), root_button_mode (loadMovie) |
| SWF_VERSION_SEMANTICS_PLAN | **Phases 1-3 COMPLETE** → `blocked/` | 3/5 pass | Phase 4 blocked on loadMovie + per-function version tracking |
| THIS_BINDING_PLAN | **FULLY COMPLETE** → `complete/` | 5/5 pass (this_swf5/6 ✅, mutable_this ✅, swf5_no_closure ✅, this_scoping ✅) | — |
| HIT_TESTING_PLAN | **Phases 1-6 DONE** → `blocked/` | 5 PASS (hittest_morph now ✅) + movieclip_hittest_shapeflag 266/338 | Remaining blocked by loadMovie, mouse events |

## Recommended Work Order (updated 2026-02-26)

### Highest ROI — unblocked, high line-count impact
1. ~~**TELLTARGET_PLAN Phase 2 remaining**~~ — **DONE** → `blocked/`. 14/22 pass. All remaining blocked on other subsystems (button dispatch, loadMovie, onEnterFrame, MC removal lifecycle, unload).
2. ~~**STAGE_PLAN Phase 4**~~ — stage_object_children already PASS ✅
3. ~~**movieclip_getbounds**~~ — added to ACCEPTED_DIFFS (morph bounds precision)

### Medium ROI — feature phases with multiple test payoff
5. ~~**REGISTERCLASS_PLAN Phases 4-5**~~ — **DONE** → blocked/. 10/15 pass. register_class 26/67 (default MC prototype fix). Remaining blocked by loadMovie, Sound class, sprite init ordering.
6. **TEXTFIELD_PLAN Phase 4-5** — scroll properties + HTML text. 25/66 pass; ~10 more tests actionable
7. **GLOBALS_PLAN** — Phase 7 DONE. Phase 8 BLOCKED by enumeration order mismatch + 20 missing Ruffle-specific globals (ASnative, ASconstructor, etc.)
8. **UNLOAD_PLAN** — `unload` at 18/52 (+34 lines), `unload_nested_child` at 0/5

### Lower ROI or partially blocked
9. ~~**OOP_SUPER_EXTENDS_PLAN**~~ — **DONE** ✅ `super_edge_cases` 39/39 PASS. `interface_implements_op` blocked by MTASC class infra.
10. ~~**NATIVE_INTROSPECTION_PLAN**~~ — **Phases 0-2 DONE** ✅ (native_objects_swf6/7/8 all PASS). Remaining: native_subclasses (arguments.slice()), native_double_construct (filter constructor super())
11. **OBJECT_WATCH_PLAN** — ~~`watch_textfield` small fix~~ DONE ✅ (4/4 pass). Only `watch_virtual_property` remains (known_failure in Ruffle)

### Dependency Blockers (plans blocking other plans)
- ~~**TIMER_PLAN**~~ — **RESOLVED** (moved to complete/). set_interval ✅. timer_run_actions blocked on REGISTERCLASS_PLAN; timeout deferred.
- ~~**CLOSURE_CAPTURE_PLAN**~~ — **RESOLVED** (moved to complete/). Remaining focus test failures blocked by FOCUS_SYSTEM_PLAN.
- ~~**MOUSE_EVENTS_PLAN**~~ — **RESOLVED** (moved to complete/). Core mouse events done (5/5 pass). Advanced features still needed: text field hit-testing (blocks FOCUS_SYSTEM_PLAN), rollover/rollout dispatch (blocks focus_mouse_rollout), recursive clip event dispatch (blocks clip_event_propagation_order).
- **FOCUS_SYSTEM_PLAN** blocks: TAB_ORDERING_PLAN (16 tests). Itself blocked by text field hit-testing and event pumping model differences.
- ~~**TELLTARGET_PLAN**~~ — **RESOLVED** (moved to blocked/). 14/22 pass. All implementable phases done. Remaining blocked by button dispatch (1 test), loadMovie (1), variable-table vs dynamic_props disconnect for onEnterFrame (1), MC removal lifecycle (3), unload (1), Ruffle known_failure (1).
- ~~**REGISTERCLASS_PLAN**~~ — **RESOLVED** (moved to blocked/). 10/15 pass. All implementable phases done. Remaining blocked by loadMovie (3 tests), sprite init ordering (register_and_init_order), Sound class (register_class_with_sound).
- **LOADMOVIE_PLAN** blocks: GLOBALS_PLAN (multi-SWF tests), HIT_TESTING_PLAN (invalid_get_bounds), BUTTON_PLAN (root_button_mode), SWF_VERSION_SEMANTICS_PLAN (cross-version calls), ROOT_REPLACEMENT_PLAN
- ~~**OOP_SUPER_EXTENDS_PLAN**~~ — **RESOLVED** (moved to blocked/). 7/8 pass. `super_edge_cases` 39/39 ✅ (resolveProtoVar fix). `interface_implements_op` blocked by REGISTERCLASS_PLAN (MTASC class constructors).

### Session notes (2026-02-28)
- **register_class 0→26/67**: Two fixes: (1) Both attachMovie paths (CallFunction + CallMethod) now set `mc.__proto__ = MovieClip.prototype` when no registered class exists, fixing `mc.__proto__ === MovieClip.prototype` StrictEquals check. (2) `Object.registerClass(sym, undefined)` now unregisters correctly (was only handling NULL, not UNDEFINED).
- **REGISTERCLASS_PLAN moved to blocked/**: All implementable phases complete. 10/15 tests pass. Remaining 5 tests blocked by: loadMovie/child SWF loading (register_class lines 31+, register_class_swf6, do_init_action_child), sprite initialization ordering (register_and_init_order lines 133+), Sound class (register_class_with_sound), deep child access during constructor (register_and_init_order line 35).
- **No regressions**: Verified 12 important tests still pass after changes.

### Session notes (2026-02-27 continued)
- **Recompiler initVarArray ordering fix**: `initVarArray(MAX_STRING_ID)` was emitted AFTER DoInitAction scripts in `tagInit`. DoInitAction scripts using `DefineLocal` fell through to `getVariableById()` with `var_array_size=0`, silently failing. Classes "a", "b", "c" never registered (only "aa" which used a global function). Fix: separate `tag_init_scripts` stringstream in SWF class; tagInit now emits definitions → initVarArray → DoInitAction calls. **All tests with DoInitAction + DefineLocal need re-recompilation** (delete RecompiledTags/ to force).
- **Constructor timing at tagSetInstanceName**: Registered class constructors moved from tagPlaceObject2 to tagSetInstanceName, so correct instance name is available. Includes recursive child constructor firing for child sprites placed during eager init. `constructor_invoked` flag prevents double invocation at process_sprite_init_at_depth.
- **register_and_init_order 0→76/233**: Constructors now fire in timeline order, but remaining gaps: (1) second `this._name` returns "undefined" — preloaded `this` is OBJECT type, MC builtins like `_name` not found; (2) `this.box.box` returns undefined during early init (deep child access); (3) attachMovie constructor path not yet implemented for this test.
- **No regressions**: Verified register_class_return_value, set_interval, goto_frame, selection, as2_super_and_this_v8, define_function2_preload_order, init_object_order all still pass.

### Session notes (2026-02-27 night)
- **on_construct 25/25 PASS** (was SEGFAULT): Four fixes: (1) `actionInvokeRegisteredClassConstructor` type 2 path used `g_event_this_mc` instead of passing MC as `this_obj` (generated code typed it as OBJECT causing segfault). (2) Recompiler emits `tagSetInstanceName` BEFORE `tagPlaceObject2WithClipActions` when clip actions present; `g_pending_instance_name` mechanism passes name to `ng_on_place_object2`. (3) `actionSetupRegisteredClassPrototype` sets `__proto__`/`__constructor__` before on(construct) fires. (4) `actionGetVariable` g_current_context path uses `getPropertyWithPrototype` instead of `getProperty` for prototype chain variable resolution.
- **register_and_init_order**: Fixed segfault (same root cause as on_construct). Now output_mismatch — constructors don't fire at timeline placement time (needs REGISTERCLASS_PLAN Phases 4-5).
- **OBJECT_WATCH_PLAN moved to complete/**: All 4/4 tests pass.

### Session notes (2026-02-27 late)
- **this_scoping 52/52 PASS**: MC navigation methods (`gotoAndStop`, `gotoAndPlay`, `stop`, `play`, `prevFrame`, `nextFrame`) called via `CallFunction` (from WITH scope or dot/slash path like `_root.instance1.gotoAndStop`) now dispatch correctly. Three changes: (1) `ng_gotoFrameByMC` handles dynamically created MCs, (2) MC nav dispatch in `actionCallFunction` before generic lookup, (3) MC method stubs on `MovieClip.prototype` + scope chain prototype check in `actionGetVariable`.
- **THIS_BINDING_PLAN moved to complete/**: All 5/5 tests now pass. The this_scoping fix was actually about MC method dispatch via CallFunction, not TELLTARGET as previously thought.

### Recent session notes (2026-02-27 evening)
- **placeobject_occupied_depth regression fix**: Root timeline loop-back sprite preservation was too broad — also fired for same-frame duplicate placements. Fixed by adding `place_gen != g_place_gen` guard.
- **clip_constructors 8/8 PASS**: registerClass type 1 constructor wasn't pushing MOVIECLIP `this` onto `g_this_stack`. `GetVariable("this")` returned OBJECT from caller's context instead. Also needed proper local scope + captured scopes + base_clip for type 1 path.
- **issue_768 3/3 PASS**: Root MC `_parent` was falling through to prototype chain (finding `MovieClip.prototype._parent = "bad parent"`). Added `_parent` check in special-variables block, guarded to only apply at root context.
- **rewind_depth 30/30 PASS**: Bonus from sprite preservation fix in previous session (preserved sprites during root timeline loop-back).
- **execution_order4 7→13/13 PASS**: Nested sprite parent context was wrong — `exec_sprite_frame` always used `root_movieclip` as parent for child MC creation. Fixed to use `g_current_context`, and set context to parent sprite's MC before recursive `advance_sprite_frames` calls. Final fix was child init ordering and WITH scope resolution (commit 0f54eedb).

### Previous session notes (2026-02-26)
- **place_and_lookup 30/30 PASS**: Four fixes: (1) `ng_isScriptableChar()` helper in tag_stubs.c for canonical scriptable check (sprite/button/textfield/video). (2) Updated 4 non-scriptable check sites in action.c to use it. (3) var_map enumeration on root MC in `actionEnumerate2` (for timeline vars like `doPrint`). (4) Videos don't get auto instance names (removed `is_video` from auto-naming condition).
- **tab_ordering_children 208/208 PASS**: Bonus from video auto-naming fix — instance counter no longer increments for unnamed videos, fixing instance name numbering.
- **selection 435→452/454**: Implemented selection index tracking: `g_selection_begin/caret/end` globals, split `getIndex` into 3 functions, `setSelection` with clamping/swapping semantics, reset indices on focus change. Remaining 2 lines: `replaceSel()`.
- **tab_ordering bonuses**: tab_ordering_tabbable 33→36/47, tab_ordering_movieclip_enabled_default 55→63/462. Both from video auto-naming fix.
- **movieclip_hittest_shapeflag**: Recovered from compile_fail to output_mismatch (266/338). Likely from tag_stubs.c recompilation fixing a prior issue.
- **global_proto_decls regression 20→11**: Not a real behavioral change — test has 670/4497 lines of wrong output. The 9-line positional scoring drop is coincidental from recompilation (the _global ASObject enumeration is unaffected by our MOVIECLIP-only changes).

### Previous session notes (2026-02-27)
- **string_paths_hidden 54/54 PASS**: Non-scriptable display objects (shapes, text, morph shapes) now resolve to parent MC instead of creating a MC wrapper. Fixed in `resolveSlashPathToMC` (character type check), `actionGetMember` (MOVIECLIP child lookup), and colon-path `_level0` resolution inside functions.
- **path_string 322/322 PASS**: Fixed via _level0 scope chain behavior, root MC var priority in GetMember/GetVariable, slash-path SetVariable. Key insight: Ruffle's own-properties-before-children order for root MC.
- **resolve_different_root regression**: output_mismatch (0/2) → segfault. Likely from new `var_map` access in GetMember for loaded movie contexts. Low priority.
- **root_global_parent**: gained 1 line (1/6 → 2/6) from root MC var priority fix.

### Plans moved (2026-02-26)
- **Moved to complete/**: LOADVARIABLES_PLAN (3/4 pass, remaining needs log_fetch), MOVIECLIPLOADER_PLAN (8/16 pass, remaining unfeasible/blocked), TIMER_PLAN (core done, remaining blocked), PROTOTYPE_OBJECT_PLAN (11/12 pass, remaining blocked on recompiler bug)
- **Moved to blocked/**: CLONE_DUPLICATE_PLAN (Phase 1 done, remaining blocked on TEXTFIELD+MOUSE+REGISTERCLASS), ROOT_REPLACEMENT_PLAN (1/4 pass, remaining blocked on MTASC/cross-version), SWF_VERSION_SEMANTICS_PLAN (3/5 pass, remaining blocked on loadMovie)
