# Current Ruffle Test Status

Last updated: 2026-04-07

## Quick Summary

- **Pass rate (CI, last run)**: 575/620 (92.7%) raw, 563/569 (98.9%) filtered (6 filtered failures)
- **Image test baseline**: **14/31 strict image match** (+2: bitmap_data_colortransform, bitmap_data_copypixels). **10/31 tolerance pass** (within test.toml limits).
- **Main failure types**: output_mismatch (45), runtime_segfault (0), timeout (1)
- **Known regressions**: `native_objects_swf6` regressed to segfault (was output_mismatch). `global_instance_decls` 40→14 (unclear root cause, test at 2% pass rate).
- **Latest fixes (2026-04-07, session 4)**:
  - **native_objects_swf7 PASS (115/115)** — Upstream tests expanded from 84→115 lines with new readonly proto detection and flash.* namespace classes. Fixed: makeProtoReadOnly on 8 singletons (Accessibility, Key, Math, Mouse, Selection, Color, System.Product), PROPERTY_FLAG_PERM_READONLY for NetConnection (survives ASSetPropFlags), Function() without new returns proper object, StyleSheet constructor sets NATIVE_STYLESHEET, FileReference NATIVE_FILEREF in actionNewMethod, ExternalInterface type 2 constructor.
  - **native_objects_swf8 PASS (115/115)** — Same fixes plus ExternalInterface `new` returns object, FileReference native backing.
  - **native_objects_swf6 114/115** — Same fixes. 1 remaining diff is pre-existing accepted (SWF6 TextField).
- **Latest fixes (2026-04-07, session 3)**:
  - **swf5_xml_event_handler_context PASS (2/2)** — XML.load() implementation using embedded data file registry (findDataFile). Fires onLoad callback synchronously via soundFireCallback pattern. Child SWF (SWF7) loads into _level2 via existing getURL2 infrastructure. Removed from ignored_tests.txt. SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN moved from blocked/ to complete/.
  - **xml_load PASS (2/2)** — Same XML.load() implementation. Loads whataload.xml from embedded data, parses XML, fires onLoad(true). Removed from ignored_tests.txt.
- **Latest fixes (2026-04-07, session 2)**:
  - **sound_id3 PASS (633/633)** — Full ID3v2.3 tag parser: frame headers, Latin1/UTF-16/UTF-8 text encoding, COMM frame array collection, friendly-name aliases (genre, artist, album, etc.). valueOf override returns undefined for Flash ID3 object semantics (id3==undefined true, typeof=="object"). soundFireCallback updated to pass success=true arg. id3 property getter with Place 0 pattern support. SOUND_ID3_PLAN moved to complete/.
  - **sound_id3_prop PASS (138/138)** — Same ID3 implementation. Tests id3 property access lifecycle across Place 0/1/2 patterns (pre-set, during onID3, during onLoad).
- **Latest fixes (2026-04-07)**:
  - **localconnection improved (74→433/579, 12.8%→74.8%)** — Full LocalConnection protocol implementation: channel registry, connect/send/close/domain with real semantics, message queue with Ruffle-compatible snapshot delivery (send-time vs delivery-time checks), onStatus callback dispatch, method invocation on receivers. Remaining 146 lines require child SWF communication (avm1child/avm2child). LOCALCONNECTION_PLAN moved from blocked/ to incomplete/.
  - **Array index function call fix** — `actionCallMethod` on ARRAY with numeric method name (e.g., `arr[1]()`) now correctly looks up the array element and calls it as a function. Previously fell through to pushUndefined. General runtime fix affecting any test using `arr[N]()` patterns.
- **Latest fixes (2026-04-06, session 4)**:
  - **movieclip_methods_with_loaded_image PASS (4/4)** — `actionDelete2` now checks current MovieClip's `dynamic_props` (mirroring Ruffle's Target scope), with fall-through to global var_map cleanup for root MC. Fixed `delete onEnterFrame` in onEnterFrame handlers. Removed from ignored_tests.txt.
  - **movieclip_state_values removed from ACCEPTED_DIFFS** — now fully passing (114/114). Removed from ignored_tests.txt. LOADMOVIE_REMAINING_PLAN moved from blocked/ to complete/.
- **Latest fixes (2026-04-06, session 3)**:
  - **movieclip_state_values PASS (114/114)** — Image loading via loadMovie. PNG/JPEG children detected by magic bytes in verify_output.py, synthetic MovieEntry with swf_version=0 generated. Runtime: image dims stored on MovieClip, _width/_height/getBounds/getRect/pixelBounds return image dimensions, getSWFVersion returns -1. LOADMOVIE_MULTI_SWF_PLAN moved to complete/.
- **Latest fixes (2026-04-06, session 2)**:
  - **netstream_play_flv_screen PASS (0/0)** — FLVPlayback component crash fix: safety checks in object.c `getProperty`/`getPropertyWithPrototype`/`findPropertyRaw` reject corrupt ASObjects (num_used > 16384). Root cause: FLVPlayback's `createVideoPlayer` called with NULL this, leading to corrupt pointer dereference in addProperty setter chain.
  - **ScreenVideo decoder** — `screenvideo_decode_frame()` decodes FLV Screen Video codec (block-based zlib-compressed BGR). `flv_decode_first_frame()` extracts first video keyframe from FLV container. Decoded RGBA stored in `g_video_frames[]` for future headless rendering.
  - **VIDEO_PLAYBACK_PLAN created** — 3/5 phases complete. Remaining: Video display object integration + headless rendering.
- **Latest fixes (2026-04-06)**:
  - **netstream_play_flv PASS (21/21)** — FLV playback via onStatus event dispatch. FLV container demuxer (header + AMF script tag parsing), NetStream state machine (play/seek/pause), frame-based event scheduling. Frame loop exit condition fix (past-end-of-frames check).
  - **netstream_seek_flv PASS (25/25)** — seek() fires Seek.Notify synchronously, pause() returns undefined, onMetaData dispatched from FLV script tag.
  - **FLV_PLAYBACK_PLAN moved to incomplete/** — 2/3 tests pass (netstream_play_flv_screen now also PASS).
- **Latest fixes (2026-04-03, session 2)**:
  - **asfunction PASS (11/11)** — Hyperlink click handler for `<a href="asfunction:...">` in text fields. Nested sprite text field initialization fix (`findDisplayEntryInParent`). Function resolution with correct `this` binding (MC vs _global).
  - **edittext_ime_focus_lost PASS (7/7)** — IME preedit/commit event pipeline (verify_output.py → swf_core.c → action.c). Composition state tracking. Deferred onChanged from replaceSel.
  - **PIXEL_TEXT_LAYOUT_PLAN complete** — all 4 phases done (char layout, asfunction, drag select, IME)
- **Latest fixes (2026-04-03)**:
  - **Drawing API gradient rendering fixes** — Three bugs fixed in beginGradientFill/lineGradientStyle: (1) focal type upgrade applied to linear gradients, (2) varToDouble garbage for string args, (3) linearRGB ramp stored in sRGB instead of linear color space. Image outliers: movieclip_begin_gradient_fill 77089→10943 (86% reduction), movieclip_line_gradient_style 32510→6053 (81% reduction). See `_investigation/RENDERING_PIPELINE_COMPARISON.md`.
  - **libtess2 tessellation** — Replaced Drawing API fan triangulation with constrained Delaunay (libtess2 library). Added adaptive bezier flattening (1/4/8/16 segments based on curvature).
  - **Gradient coordinate normalization** — Inverse gradient matrix now outputs [0,1] UVs matching Ruffle's conventions.
  - **displacementmapfilter_mappoint_throw_error PASS (13/13)** — valueOf throw propagation in mapPoint setter. Local setjmp exception handlers around tsArgToDouble_ctx coercion; state commits before re-throw. Moved ExceptionState types earlier in action.c.
- **Latest fixes (2026-04-02)**:
  - **bitmap_data_colortransform image PASS** (0 outliers, max diff 4) — Flash bug: colorTransform with only aMult > 1 has no effect. Added early-return check.
  - **bitmap_data_copypixels image PASS** (0 outliers, pixel-perfect) — Three fixes:
    1. MAX_DYNAMIC_BITMAPS 32→64 (test needs ~48 texture layers)
    2. copyPixels restructured with two-path logic: transparent alpha bitmap (OOB skip, modulation, blend when mergeAlpha||!dest_transparent) vs no-alpha/opaque-alpha (blend when src_transparent&&!dest_transparent || mergeAlpha)
    3. Non-transparent alpha bitmaps ignored for alpha computation (matching Ruffle)
  - **BITMAPDATA_RENDERING_PLAN completed** — all 6/6 image tests now passing
- **Latest fixes (2026-04-01, session 4)**:
  - **global_proto_decls blocker reclassified** — "constructor/__proto__ DONT_ENUM conflict" is a Ruffle vs Flash difference: Ruffle makes Object.prototype methods ENUMERABLE by default and sets constructor as own property on all objects, while Flash uses DONT_ENUM and inherits constructor. See RUFFLE_VS_FLASH_DIFFERENCES.md.
  - **AsBroadcaster function own_props** — g_ab_addListener/removeListener/broadcastMessage now have own_props (constructor + __proto__) + selective prototype creation (addListener/removeListener get prototypes, broadcastMessage does not)
  - **global_proto_decls improved (742→742)** — no net line change from session 3 total, but blocker understanding clarified
- **Latest fixes (2026-04-01, session 3)**:
  - **global_proto_decls improved (551→742)** — System.IME method own_props + no_lazy_prototype, System.security (PolicyFileResolver + 5 method stubs + sandboxType READ_ONLY + __constructor__), System.capabilities (27 new properties), Object.prototype reordering + toLocaleString, Object constructor own_props flags, function enumeration __proto__ chain walking, constructor inheritance filtering
  - **global_proto_decls_delete improved (283→287)** — IME method own_props alignment
- **Latest fixes (2026-04-01, session 2)**:
  - **global_proto_decls improved (276→551)** — ColorTransform/Point/Rectangle virtual properties, flash.filters (order + 75 virtual props + clone inheritance + __constructor__), BitmapData (own_props order + prototype reorder + 4 virtual props), TextRenderer own_props, System (6 new props + rewrite), System.IME (6 methods + 8 constants + flag fixes)
  - **global_proto_decls_delete improved (255→283)** — filter order alignment, clone on BitmapFilter.prototype (CONFIGURABLE), constructor deleted from subclass prototypes
  - **Gnash misc-mtasc: 4/9 passing** — hello, enum, exception, implementsOpTest all PASS
- **Latest fixes (2026-04-01)**:
  - **color image test PASS** — alpha blend state fix (SrcAlpha→One for alpha channel), max diff 48→1
  - **Stage.width/height initialized to FRAME_WIDTH/FRAME_HEIGHT** — was 0, causing Drawing API layout bugs (movieclip_setmask 202400→10096 outliers)
  - **_global plain property resolution** — actionGetVariable now finds plain properties on _global in root context (enables Gnash misc-mtasc AS2 class resolution)
  - display_object_properties, mask_reapply, frame_size_*, movieclip_create_text_field image tests confirmed passing
  - focusrect_swf5: 9/12 captures pass (3 fail due to focus rect rendering as solid fill instead of outline)
- **Latest fixes (2026-03-31, session 2)**:
  - global_proto_decls improved (250→276) — Point/Matrix/Rectangle/ColorTransform prototype enumeration order, geometry constructor own_props UNDEFINED placeholder fix
  - ensureBuiltinPrototypeProps + ensureCtorOwnProps now handle UNDEFINED placeholders correctly
  - Investigated near-miss tests: native_objects_swf6 (Flash vs Ruffle difference), tab_ordering_properties_tab_index_edge_case (conflicting expectations), movieclip_library_state_values (already accepted diffs)
- **Latest fixes (2026-03-31)**:
  - netconnection_close PASS (39/39) — NetConnection connect/close state machine + onStatus dispatch
  - sound_load_start PASS (3/3) — loadSound with embedded MP3 data registry lookup
  - sound_multiple_load PASS (1/1) — loadSound replaces previous load
  - sound_duration_position_props PASS (290/290) — getPosition, duration/position native getters, onID3/onLoad/onSoundComplete lifecycle
  - global_proto_decls improved (237→250) — Transform.prototype 5 READ_ONLY properties
  - global_proto_decls_delete (255→255) — Transform.prototype CONFIGURABLE flag fix
  - sound_id3_prop improved (1→8), sound_id3 improved (11→17) — bonus from onID3 dispatch
  - Sound playback simulation: processSoundPlayback in frame loop, hasPlayingSounds exit condition
- **Latest fixes (2026-03-29, session 2)**:
  - bitmap_data_fillrect image PASS (0 outliers) — fillRect negative dimensions + removed bare Rectangle global
  - BitmapData.loadBitmap(exportName) — full implementation with defineBitmap char_id metadata, R/B byte swap
  - bitmap_data_colortransform image: 78561→726 outliers — loadBitmap working, remaining 2× precision issue
  - copyPixels alpha bitmap path (6-arg form), merge() method implementation
  - bitmap_data_copypixels: 190726→188581 outliers (partial progress)
- **Latest fixes (2026-03-29, session 1)**:
  - bitmap_data_pixeldissolve PASS (1075/1075) — Feistel network PRNG implementation
  - bitmap_data_perlinnoise image PASS (0 outliers) — W3C SVG feTurbulence port
  - bitmap_data_pixeldissolve_image image PASS (0 outliers) — same Feistel implementation
  - bitmapdata_applyfilter_colormatrix image PASS (0 outliers, max diff 1) — ColorMatrixFilter constructor fix
  - bitmap_filters SEGFAULT→MISMATCH (~496/548) — filter clone, property validation, mc.filters, NULL stub fix
  - Added --asan flag to verify_output.py for crash debugging
- **Latest fixes (2026-03-28)**:
  - movieclip_create_text_field image PASS (0 outliers) — fixed createTextField negative dimension rendering
  - Headless glyph rendering pipeline — device font tessellation via bundled Noto Sans TTF + stb_truetype
  - edittext_tag_indent/edittext_stylesheet: glyphs now render (still fail on text layout/color)
- **Latest fixes (2026-03-26)**:
  - array_constructor PASS (Array.join HOLE→"undefined" fix)
  - array_properties PASS (same fix)
  - external_interface_toxml_basic PASS (same fix)
  - global_array PASS (same fix)
  - tab_ordering_properties PASS (tabIndex coercion, previous fix now confirmed)
  - string_relational_compare: runtime_error→output_mismatch (verify_output.py UTF-8 error handling)
- **Latest fixes (2026-03-15)**:
  - text_blocks_clicks PASS (DefineText bounds for _droptarget)
  - issue_2030 PASS (MC.attachBitmap stub)
  - unload_nested_child PASS (nested MC click fix, recursive child unload detection, deferred UNLOAD in catch_up_mode)
  - target_clip_removed PASS (char_id guard in upgrade_sprite_initialized)
  - issue_2084 PASS (nested attachMovie with registerClass — onLoad queue, initObject ordering)
  - coerce_to_object_monkeypatch PASS (primitive auto-boxing, addProperty getter lookup, this fallback to _global)
  - clone_sprite_edittext_dynamic PASS (TF clone property copy, rotated bounding box)
  - bitmap_data_draw_cliprect PASS (BitmapData.draw() with inverse matrix transform + clipRect)
  - bitmap_data_copypixels PASS (alpha compositing in copyPixels mergeAlpha=true)

## Crashes and Errors

| Test | Status | Notes |
|------|--------|-------|
| timeout | timeout | Infinite loop — needs script execution timeout mechanism |
| native_objects_swf6 | 114/115 | 1 accepted diff (SWF6 TextField) — was segfault, recovered |

netstream_play_flv_screen crash fixed (was segfault, now PASS with 0/0 trace lines).

Most previous crashes/segfaults/runtime_errors have been fixed (funky_function_calls, goto_methods, native_objects_swf7/8, movieclip_invalid_get_bounds_6/7, bitmap_filters).

## Near-Passing Tests

All previously near-passing tests have been fixed. 146 tests were tracked through the near-passing pipeline and are now fully passing — see `SESSION_NOTES.md` and git history for details.

## FrameLabelEntry compile_fail (FIXED)
202 tests had stale `FrameLabelEntry` typedef in generated tagMain.c conflicting with tag.h. Fixed by removing the stale typedefs from all generated files.

## Plan Implementation Status

### Completed plans
| Plan | Tests Passing |
|------|--------------|
| IMAGE_PLAN_01 | display_object_properties, color (trace); 2/31 image tests |
| BITMAPDATA_RENDERING | 6/6 image tests pixel-perfect (colortransform, copypixels, fillrect, perlinnoise, pixeldissolve, colormatrix) |
| DATE_PLAN | 8+ tests; `date` at ~99.2% |
| TRY_CATCH_PLAN | `try_catch_finally` 118/118 |
| MATH_PLAN | 4/4 |
| ENUMERATION_PLAN | 5/5 |
| XML_PLAN | 26/26 active tests |
| ARRAY_METHODS_PLAN | All tests |
| OBJECT_WATCH_PLAN | 4/4 |
| STRING_PLAN (Phases 1-4) | 4/4 method tests + string_ops_swf6 |
| TEXTFIELD_PLAN | 62/62 |
| WITH_SCOPE_PLAN | 2/2 |
| PARSING_FUNCTIONS_PLAN | 3/3 |
| COLOR_OBJECT_PLAN | extends_native_type |
| GEOMETRY_CLASSES_PLAN | transform, local_to_global partial |
| STAGE_PLAN | 7/7 |
| STAGE_FRAME_PROPS_PLAN | 9/9 |
| INPUT_EVENTS_PLAN | 40+ tests |
| SELECTION_PLAN | 454/454 |
| OOP_SUPER_EXTENDS_PLAN | 9/9 |
| REGISTERCLASS_PLAN | 16/16 |
| PROTOTYPE_OBJECT_PLAN | 11/12 (remaining: recompiler MTASC nested function bug) |
| NATIVE_INTROSPECTION_PLAN | 4/5 (remaining: ignored diffs) |
| TIMER_PLAN | 2/3 (timeout deferred) |
| FOCUS_SYSTEM_PLAN | 7/7 |
| TAB_ORDERING_PLAN | 16/16 |
| DRAG_DROP_PLAN | 4/4 |
| LOADVARIABLES_PLAN | 3/4 (remaining: log_fetch infra) |
| ASNATIVE_ASNEW_PLAN | 34/34 + 34/34 |
| BUTTON_PLAN | 14/14 |
| SWF_VERSION_SEMANTICS_PLAN | 5/5 |
| THIS_BINDING_PLAN | 5/5 |
| EXTERNAL_INTERFACE_PLAN (Phases 1-3) | 6/7 (Phase 4 blocked: no JS env) |
| MOUSE_EVENTS_ADVANCED_PLAN | 7 tests |
| LOCKROOT_PLAN | 29/29 |
| PRIMITIVE_COERCION_ADDPROPERTY_PLAN | 17/17 |
| DEFAULT_NAMES_PLAN | 52/52 |
| SCRIPT_HALTING_PLAN | 15/15 + 5/5 + 29/29 |
| CUSTOM_CLIP_METHODS_PLAN | 4/4 |
| GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN | 112/112 |
| FOCUS_FOCUSRECT_PLAN | 4/4 (1237 lines each) |
| SOUND_CLASS_PLAN (Phase 0) | register_class_with_sound, sound |
| SOUND_ID3_PLAN | 633/633 + 138/138 |
| NATIVE_OBJECTS_UPDATED_PLAN | swf7 115/115, swf8 115/115 (swf6 114/115 accepted) |
| UNLOAD_PLAN | 5/6 (unload_nested_child now PASS) |
| DISPLACEMENTMAPFILTER_PLAN | 13/13 |
| TELLTARGET_PLAN | 20/22 (2 accepted/ignored) |
| DRAWING_API_RENDERING | mask_with_drawing IMAGE PASS; gradient outliers reduced 80-86% |
| PIXEL_TEXT_LAYOUT_PLAN | 3/3 (asfunction, edittext_drag_select, edittext_ime_focus_lost) |
| SWF5_XML_EVENT_HANDLER_CONTEXT_PLAN | 2/2 + xml_load 2/2 |
| VECTOR_PATH_HITTEST_PLAN | 329/338 (9 accepted diffs) |

### Blocked plans
| Plan | Status | Blocker |
|------|--------|---------|
| GLOBALS_PLAN (Phase 8) | 23/30 pass | Enumeration order + 20 missing globals |
| MOVIECLIP_PLAN | 27 tests pass | loadMovie, pixel hitTest |
| CLONE_DUPLICATE_PLAN | 4/8 pass | Textfield mouse events |
| LOADMOVIE_PLAN | 32/35 pass | mcl_replace_root accepted diffs |
| ROOT_REPLACEMENT_PLAN | 1/4 pass | MTASC class support + cross-version scope |
| HIT_TESTING_PLAN | 5+ pass | movieclip_hittest_shapeflag now accepted diffs |
| LOADMOVIE_REMAINING_PLAN | **4/5 COMPLETE** | Moved to complete/ (1 accepted diffs) |
| DRAWING_API_RENDERING | 3 tests improved | Focal radial precision, edge anti-aliasing (see RENDERING_PIPELINE_COMPARISON.md) |
| RUNTIME_SETMASK | **COMPLETE** | Moved to complete/ (masking infra done; image diff is Drawing API edge AA) |

## Recommended Work Order (updated 2026-03-15)

### Actionable — Quick wins (all exhausted)
All previous quick wins have been fixed. See `SESSION_NOTES.md` for details.

### Remaining failing tests (filtered: 5 tests, after movieclip_hittest_shapeflag accepted)
Remaining failures require:
- **Global enumeration order**: global_proto_decls, global_instance_decls, global_proto_decls_delete (GLOBALS_PLAN Phase 8 blocked)
- **Missing features**: localconnection, sandbox_type_remote

### Remaining blocked work (from blocked/ plans)
- **GLOBALS_PLAN Phase 8** — BLOCKED by enumeration order + missing globals.
- **MC_REMOVAL_LIFECYCLE_PLAN** — call() early termination, SetTarget on removed base_clip.
- **TYPE_COERCION_ADVANCED_PLAN** — **COMPLETE** (2/2 PASS). Moved to complete/. Blocker resolved: closure capture + tri-state auto-boxing.

### Dependency Blockers (plans blocking other plans)
- **LOADMOVIE_PLAN**: 32/35 core tests PASS. loadmovie_registerclass PASS. mcl_replace_root accepted diffs.
- **FOCUS_SYSTEM_PLAN**: 7/7 PASS. TAB_ORDERING_PLAN fully complete (16/16).
