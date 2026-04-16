# Current Ruffle Test Status

Last updated: 2026-04-16 (CI run at 82a6ea07)

## Quick Summary

- **Pass rate (CI, latest)**: 579/641 (90.3%) raw, 584/641 (91.1%) effective (raw + 5 ruffle_matched), **578/601 (96.2%) filtered** (22 output mismatches + 1 compile_fail)
- **Test count grew 620 → 641** — primarily from splitting `bitmap_data_thorough` into 20 sub-tests (`bitmap_data_thorough/colorTransform`, `/compare`, `/constructor`, etc.), plus `depth_replacement_audio_unloading`.
- **Image test baseline**: **14/31 strict image match** (+2: bitmap_data_colortransform, bitmap_data_copypixels). **10/31 tolerance pass** (within test.toml limits).
- **Main failure types**: output_mismatch (22 filtered / 56 raw), compile_fail (1), runtime_segfault (0), timeout (0)
- **Filtered failure breakdown**:
  - **`bitmap_data_thorough/*` sub-tests (20)** — mostly 2-6% match, need systematic BitmapData thoroughness work. Only `getColorBoundsRect` (83.5%), `getPixel` / `getPixel32` (78.7%), `hitTest` (54.9%), `compare` (42.0%) above 40%.
  - **`depth_replacement_audio_unloading`** (compile_fail) — needs recompiler investigation. Test involves child.swf + sound.mp3.
  - **`function_as_function`** (2 diffs) — `Function()` without `new` return value format + `__proto__` behavior.
  - **`coerce_to_object_monkeypatch`** (1 diff) — regressed by primitive auto-boxing fix in cffa1dd8, **fix committed in 998e879a** (post-CI). Should revert to pass on next CI run.
- **Latest fixes (2026-04-16)**:
  - **Primitive auto-boxing in GetMember / convertFloat** (cffa1dd8) — Number/Boolean primitives now resolve properties via Number.prototype / Boolean.prototype. Gnash: Number-v5..v8 improved; Color-v6 now PASS.
  - **`coerce_to_object_monkeypatch` regression fix** (998e879a, post-CI) — primitive `getPropertyWithPrototype` path needed a guard.
- **Latest fixes (2026-04-08)**: +5 new passes (is_finite, is_finite_swf6, swf5/6/7_global_funcs). native_objects_swf7/swf8 now PASS. string_relational_compare correctly fails (1 diff, Flash-correct behavior restored). timeout now passes (0 expected lines).
- **Latest fixes (2026-04-07, session 5)**:
  - **CONSTRUCT/constructor ordering investigation** — Investigated whether FLVPlayback component video rendering could work with correct CONSTRUCT-before-constructor ordering. Confirmed Flash/Ruffle ordering (CONSTRUCT first) via Ruffle source (`core/src/player.rs:2174-2188`). FLVPlayback's contentPath setter stores value when `_vp` doesn't exist but never triggers `play()` post-constructor. Component does NOT use V2 lifecycle (`callLater`/`invalidate`). Created `CONSTRUCT_PARAMETER_REPLAY_PLAN.md` in `incomplete/` for future fix.
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

No crashes or segfaults remain. All previous crashes have been fixed.

## Remaining Filtered Failures (22 output_mismatch + 1 compile_fail)

### Near-passing (< 5 diff lines)

| Test | Match Rate | Matching | Total | Diff | Notes |
|------|------------|----------|-------|------|-------|
| `coerce_to_object_monkeypatch` | 99.2% | 128 | 129 | 1 | **Fix already committed in 998e879a**. Regression from primitive auto-boxing (cffa1dd8). Will revert to PASS on next CI. |
| `function_as_function` | 94.3% | 33 | 35 | 2 | `Function()` without `new`: return value format + `__proto__` behavior. Covered by completed FUNCTION_EDGE_CASES_PLAN. |

### New `bitmap_data_thorough/*` sub-test cluster (20 tests)

Created by splitting the monolithic `bitmap_data_thorough` test into per-method sub-tests. Most have very low match rates — this is a systematic thoroughness suite that stresses many BitmapData edge cases at once.

| Sub-test | Match Rate | Matching | Total | Likely root cause |
|----------|------------|----------|-------|-------------------|
| `getColorBoundsRect` | 83.5% | 238 | 285 | Rect bounds / findColor edge cases |
| `getPixel` / `getPixel32` | 78.7% | 111 | 141 | Out-of-bounds / coercion |
| `hitTest` | 54.9% | 285 | 519 | Hit-test vectors vs rects |
| `compare` | 42.0% | 29 | 69 | Compare return type / value format |
| `constructor` | 6.7% | 21 | 313 | Constructor argument coercion |
| `perlinNoise` | 5.1% | 435 | 8481 | RNG / seeded output |
| `colorTransform` | 2.9% | 8 | 279 | Per-pixel transform correctness |
| `fillRect` | 2.6% | 9 | 342 | |
| `scroll` | 2.6% | 10 | 384 | |
| `threshold` | 2.4% | 31 | 1308 | |
| `setPixel` / `setPixel32` | 2.3% | 12 | 531 | |
| `floodFill` | 2.1% | 18 | 867 | |
| `pixelDissolve` | 2.0% | 28 | 1371 | |
| `copyPixels` | 1.9% | 23 | 1203 | |
| `merge` | 1.9% | 23 | 1203 | |
| `noise` | 1.9% | 29 | 1518 | |
| `paletteMap` | 1.9% | 18 | 951 | |
| `copyChannel` | 1.8% | 49 | 2715 | |

The low match rates (most under 5%) suggest a systematic issue rather than per-method bugs — likely output format, trace harness, or a shared BitmapData init path. Worth investigating one (e.g., `fillRect`) to find the common blocker.

### Compile failure

| Test | Notes |
|------|-------|
| `depth_replacement_audio_unloading` | Recompiler rejects SWF. Test has `child.swf` + `sound.mp3`. Needs investigation in `SWFRecomp/src/action/action.cpp`. |

## Near-Passing Tests (previously)

All previously near-passing tests (146 tracked through the pipeline) are now fully passing — see `SESSION_NOTES.md` and git history for details. The new near-passing list above is a different set, dominated by the `bitmap_data_thorough` split.

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
| FLV_PLAYBACK_PLAN | 3/3 trace + headless image pixel-perfect |

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

## Recommended Work Order (updated 2026-04-16)

### Immediate (already fixed, awaiting CI)
- **`coerce_to_object_monkeypatch`** (1 diff) — fix already committed in 998e879a. Will reflect on next CI run.

### Near-term
- **`function_as_function`** (2 diffs) — `Function()` without `new`: return value format + `__proto__` behavior.
- **`depth_replacement_audio_unloading`** (compile_fail) — triage recompiler rejection.

### `bitmap_data_thorough/*` sub-tests (20)
- Pick one low-match sub-test (e.g., `fillRect` or `setPixel`) to find the shared blocker. Most are < 5% match, suggesting either (a) a shared init / harness problem, or (b) expected output contains large dumps where a single early divergence cascades through most lines.
- `getColorBoundsRect` / `getPixel` / `hitTest` / `compare` are the nearest (40-84% match) and likely yield the clearest per-method bugs.

### Remaining non-filtered failures (40 tests in ignored_tests.txt)
Permanently ignored (accepted diffs, Ruffle-vs-Flash differences, infrastructure blockers). No actionable work.

### Remaining blocked work (from blocked/ plans)
- **GLOBALS_PLAN Phase 8** — BLOCKED by enumeration order + missing globals.
- **MC_REMOVAL_LIFECYCLE_PLAN** — call() early termination, SetTarget on removed base_clip.

### Dependency Blockers (plans blocking other plans)
- **LOADMOVIE_PLAN**: 32/35 core tests PASS. loadmovie_registerclass PASS. mcl_replace_root accepted diffs.
- **FOCUS_SYSTEM_PLAN**: 7/7 PASS. TAB_ORDERING_PLAN fully complete (16/16).
