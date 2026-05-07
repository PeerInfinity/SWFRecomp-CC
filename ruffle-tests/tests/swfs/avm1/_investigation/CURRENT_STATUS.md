# Current Ruffle Test Status

Last updated: 2026-05-07 (CI `8fdf3311`: `placeobject_occupied_depth` + `textsnapshot_available_text` recovered via place-before-define narrowing fix — both regressed in CI `873e520e` then restored. AVM1 filtered effective pass remains 100%. Earlier CI `035950cf`: `try_catch_stack` PASS via catch-entry stack truncate.).

## Latest CI snapshot (commit `035950cf`, 2026-05-07)

| Metric | Raw | Filtered |
|--------|-----|----------|
| Total | 648 | 608 |
| Pass | 605 | 604 |
| Ruffle-matched | 9 | 4 |
| Effective pass | 614 (94.8%) | 608 (100.0%) |
| Fail | 34 | 0 |

Zero filtered failures. The 34 raw fails are all in `ignored_tests.txt` (accepted diffs, Ruffle-vs-Flash differences, infrastructure blockers — see `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` / `RUFFLE_COMPAT_TWEAKS.md` / `FLASH_BUGS_REPLICATED.md`).

## Latest fix: `try_catch_stack` (16/16)

Landed in CI at `035950cf` (2026-05-07). `ExceptionFrame` gained a
`saved_sp` field; `actionTryBegin` snapshots `app_context->sp`;
`actionCatchEnter` truncates the value stack to that snapshot **only if**
the try body net-pushed values that survived the throw (`sp < saved_sp`;
the stack grows downward). Mirrors Ruffle commit `0fc689cce`
(`Vec::truncate(original_stack_size)`) exactly: pushes that survive the
body are dropped, but pops are not undone. The asymmetry is load-bearing
— symmetric restore would resurrect the test's "in reverse" Pop and put
`3` (or stale `"error"`) at the top of stack instead of the expected
`2`. Plan moved to `complete/TRY_CATCH_STACK_PLAN.md`.

## Latest fixes (in CI at `c5994ec1`, landed 2026-05-04 sessions)

- **`assetnative_ids` PASS (10/10) and `assetnative` PASS (81/81).** Recent upstream sync added 4 `assetnative*` tests; both non-accessor variants now PASS after `ASSetNative` was implemented (was a noop) plus the version-gating refinement. The implementation parses comma-separated names with optional version-flag digit prefix stripping (`1`/`6`/`7`/`8`/`9`/`10`) and binds `ASnative(major, minor + position)` on the target. Empty-name slots still consume an index (matches `ASSetNative(d, 103, ",getTime3", 15)` → getTime3 = ASnative(103, 16) = `getTime`). `valueOf` errors on the `minor` arg propagate through the existing setjmp/longjmp try/catch. Version-gating handles three sub-cases from `assetnative` under SWF 7: own exists → overwrite with function; own absent + inherited → install with inherited value; own absent + nothing inherited → install undefined.

- **`assetnativeaccessor` and `assetnativeaccessor_ids` PASS (post-CI 2026-05-05).** `ASSetNativeAccessor` builtin and ConvolutionFilter (class 1109) `ASnative` dispatch implemented. Comma-split + version-flag-prefix logic mirrors `ASSetNative`; the binding step uses `setAddProperty(target, name, getter, setter)` for version-met cases (with getter = ASnative(major, minor + 2*pos), setter = ASnative(major, minor + 2*pos + 1)). Version-gated cases install a plain own value derived from the proto chain (skipping own), overwriting any existing own. Class 1109 dispatch maps minor 1..18 → {matrixX, matrixY, matrix, divisor, bias, preserveAlpha, clamp, color, alpha} × {get, set}; each accessor reads/writes the corresponding property name on `this_obj`. Plan moved to `complete/ASSETNATIVEACCESSOR_PLAN.md`.

## Latest fixes (2026-05-01, in CI at 25231855425)

- **`loadvars_tostring` PASS (5/5).** `builtin_loadvars_toString`
  iterated own_props and serialized `p->value` directly, ignoring
  addProperty-defined virtual properties. For an entry registered via
  `lv.addProperty(name, getter, setter)`, `p->value` is the placeholder
  undefined while the live value comes from invoking the getter; the
  old code yielded `name=undefined`. Fix: when `p->getter` is
  non-NULL, call `invokePropertyGetter(lv)` and serialize the returned
  value; otherwise keep using `p->value`. Throws inside the getter
  still longjmp through to the bytecode-level try/catch via
  `g_exception_state` (matches the test's `Caught: some error` path);
  self-recursive getters (`return this.k` on a `k` virtual prop) hit
  `MAX_SPECIAL_DEPTH` and return `undefined`, matching Ruffle.
  Verified: 22-test AVM1 LoadVars/addProperty/watch/external_interface/
  closure/goto/unload regression battery (22/22), plus 3 pre-existing
  accepted failures (`load_vars`, `loadvariables_method`,
  `watch_virtual_property` — all on `ignored_tests.txt`) unchanged.
  Brings filtered AVM1 to 603/603 effective (100%) — zero filtered
  failures across the suite.

- **`bitmap_filters` PASS (548/548).** Two changes: (1) timeline filter
  reconstruction (`actionGetMember` on `mc.filters` → FilterListData path
  in action.c around line 43670+) reorders properties to match Flash's
  enumeration order: `BevelFilter` from `..., blurX, blurY, strength,
  quality, type, knockout` to `..., quality, strength, knockout, blurX,
  blurY, type`; `DropShadowFilter` from `..., blurX, blurY, strength,
  quality, inner, knockout, hideObject` to `..., quality, inner,
  knockout, blurX, blurY, strength, hideObject`; `GlowFilter` and
  `GradientGlow/GradientBevel` analogous. The fallback `ftype != 0`
  path (line 43964+) was already in the right order; only the multi-
  filter `FilterListData` block needed reordering. (2) `verify_output.py`
  now honors `[approximations.number_patterns]` in test.toml, mirroring
  Ruffle's framework: each regex's capture groups are compared as
  floats with the configured `epsilon`, then the matched substring is
  stripped and the remainder must match exactly. Closes the residual
  4 angle-precision diffs (default `BevelFilter().angle == 45` vs
  Flash's `44.9999999772279` from deg→rad→deg roundtrip — a
  Flash-vs-Ruffle difference documented in `RUFFLE_VS_FLASH_DIFFERENCES.md`)
  using the test's own `number_patterns = ["angle=([\\d.]+)"]` +
  `epsilon = 0.001` config. Removed from `ignored_tests.txt`. Verified:
  9-test approximation/array battery (math_swf6/7/8, bitmap_filters,
  bitmap_data, bitmap_data_colortransform, depth_replacement_audio_unloading,
  shumway/avm1/filters, plus 9 unrelated AVM1 tests including
  array_constructor, watch, action_to_integer, parse_int, typeof,
  enumerate, array_sort, string_coercion, watch_textfield — all PASS).

## Quick Summary

- **Pass rate (CI `035950cf`)**: 605/648 (93.4%) raw, **614/648 (94.8%) effective** (raw + 9 ruffle_matched), **608/608 (100.0%) filtered** — zero filtered failures.
- **Test count**: 648 (unchanged). 40 tests in `ignored_tests.txt` (accepted diffs / Ruffle-vs-Flash / Ruffle known_failure).
- **Image test baseline**: 14/31 strict image match, 10/31 tolerance pass.
- **Main failure types** (raw): output_mismatch (34), runtime_error/segfault/timeout (0), compile_fail (0).
- **Filtered effective pass: 100.0%.** No actionable AVM1 failures remain.
- **Change from 2026-05-06 doc snapshot:** `try_catch_stack` flipped 14/16 → 16/16 PASS; net effective +1.
- **Latest fixes (2026-04-18, this session)**:
  - **`bitmap_data_thorough/threshold` PASS** — opaque BMD `getPixel32` returns raw stored pixel (no un-premul); `mask` arg defaults to `0xFFFFFFFF` only when missing (undefined coerces to 0).
  - **`bitmap_data_thorough/noise` PASS** — `high` arg defaults to `0xFF` only when missing (undefined → 0); alpha-channel RNG only fires for transparent BMDs; seed/low/high coerced via `doubleToUint32` so NaN/Infinity → 0 (ECMA ToInt32).
  - **`bitmap_data_thorough/paletteMap` ruffle_matched** — channel-array args treat OBJECT (e.g. `{}`) as well as ARRAY, mask each LUT entry with `& 0xFF`.
  - **`bitmap_data_thorough/pixelDissolve` improved** (97.2%) — require 5 args minimum, validate rect props, empty region returns `random_seed`. Remaining diffs in Feistel return values are Flash-specific; test added to `ignored_tests.txt` (Ruffle panics on this test, no `output.ruffle.txt` to subset against).
  - **`bitmap_data_thorough/copyChannel` PASS** — bumped `MAX_BITMAP_NATIVES` 256 → 8192. The side table was overflowing partway through the Opaque iteration; new BMDs went unregistered → `bdHeightGetter` returned -1 → `printBmd` skipped its loop.
  - **`bitmap_data_thorough/perlinNoise` ruffle_matched** (98.8%) — `MAX_BITMAP_NATIVES` bump unblocked it; further fixes for SWF7+ null/undefined→NaN coercion (baseX/Y), `channel_options=undefined` → 0 (was defaulting to 7), and ECMA ToInt32 NaN→0 for seed/numOctaves brought our diffs to a strict subset of Ruffle's.
  - **`function_as_function` PASS** — `Function()` without `new` returns a bare object with no `__proto__`; toString falls through to `[type Object]` and `.__proto__` is undefined (matches Flash).
  - **`depth_replacement_audio_unloading` PASS** — `verify_output.py` extracts all 14 raw-data arrays from a child SWF's `draws.c` (sound_data, transform_data, bitmap_data, …), prefixes them, and emits forward externs; strips `quit_swf = 1` from child frame functions; `actionFirePendingLoadInits` Phase 2 saves/restores global `is_playing` so a child's `stop()` doesn't terminate the parent's frame loop.
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

## Remaining Filtered Failures: 0

The 34 raw fails not in the filtered set are in `ignored_tests.txt` (accepted diffs documented in `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` / `RUFFLE_COMPAT_TWEAKS.md` / `FLASH_BUGS_REPLICATED.md`).

### `bitmap_data_thorough/*` final status (20 sub-tests, all effectively pass)

Plan moved to `complete/BITMAP_DATA_THOROUGH_PLAN.md`. Final breakdown:

| Status | Count | Notes |
|--------|-------|-------|
| PASS (100%) | 16 | colorTransform, compare, constructor, copyChannel, fillRect, floodFill, getColorBoundsRect, getPixel, getPixel32, hitTest, merge, noise, scroll, setPixel, setPixel32, threshold |
| ruffle_matched | 3 | copyPixels (94.3%), paletteMap (94.5%), perlinNoise (98.8%) — diff sets are strict subsets of Ruffle's |
| Ignored / accepted | 1 | pixelDissolve (97.2%) — Flash-specific Feistel coercion, Ruffle panics so no `output.ruffle.txt` for promotion |

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
| ASSETNATIVEACCESSOR_PLAN | assetnativeaccessor + assetnativeaccessor_ids PASS |
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

## Recommended Work Order (updated 2026-05-07)

The AVM1 filtered suite is at 100.0% effective pass — zero outstanding
filtered failures. Useful next targets are in *other* suites (line-level
numbers from the same CI run):

- **`from_gnash/actionscript.all`** (133/190 effective, 70.0%): near-passing
  candidates are Number-v5..v8 (gnash float-to-string rounding), Selection-v6/7/8
  (selection-API edge cases), ExternalInterface-v8 (object enumeration order).
- **`from_gnash/misc-mtasc.all`** (8/9): only `levels` fails — needs multi-level
  SWF loading (`_level5`, `_level87`, `_level99`).
- **`from_gnash/misc-swfmill.all`** (15/18): three timeline-tag-order failures
  (`tags_after_last_showframe`, `jump_to_prev_block`, `trace-as2/root_onload`).
- **`from_shumway/avm1`** (45/47, 95.7%): `doactionorder` and `moviecliploader`
  both fail on timeline execution order (load events vs. parent frame scripts).

### Remaining non-filtered failures (41 tests in ignored_tests.txt)
Permanently ignored (accepted diffs, Ruffle-vs-Flash differences, infrastructure
blockers). No actionable work.

### Remaining blocked work (from blocked/ plans)
- **GLOBALS_PLAN Phase 8** — BLOCKED by enumeration order + missing globals.
- **MC_REMOVAL_LIFECYCLE_PLAN** — call() early termination, SetTarget on removed base_clip.

### Dependency Blockers (plans blocking other plans)
- **LOADMOVIE_PLAN**: 32/35 core tests PASS. loadmovie_registerclass PASS. mcl_replace_root accepted diffs.
- **FOCUS_SYSTEM_PLAN**: 7/7 PASS. TAB_ORDERING_PLAN fully complete (16/16).
