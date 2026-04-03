# Feature Scope and Implementation Decisions

This document explains which Flash/AVM1 features the SWFRecomp project implements,
which it does not yet, and the reasoning behind those decisions.

Last updated: 2026-04-03

---

## Project Goal

SWFRecomp is a **SWF-to-C recompiler** that converts SWF bytecode into native C code
and executes it against a custom runtime. The goal is faithful AVM1 (ActionScript
1/2) execution — matching Flash Player's behavior for the scripting language, object
model, timeline control, rendering, and media playback.

The project is validated against three external test suites (Ruffle AVM1, Gnash, Shumway)
plus an internal hand-written test suite. Current pass rates:

| Suite | Filtered Pass Rate |
|-------|-------------------|
| AVM1 (Ruffle) trace | 99.6% (564/566) |
| AVM1 (Ruffle) image | 14/31 strict match (10/31 tolerance pass) |
| Shumway AVM1 | 100% (17/17) |
| Gnash | ~34% (61/181) |
| Internal tests | 100% (158/158 trace + 59/59 graphics) |

---

## Execution Modes

The runtime supports three execution modes:

### 1. NO_GRAPHICS (trace-only)

Compiles and runs natively (gcc, no browser). No rendering, no audio, no network.
All validation is against `trace()` output. This is the most mature mode and the
primary CI target for the Ruffle/Gnash/Shumway test suites.

```bash
python3 ruffle-tests/verify_output.py --test=TEST_NAME --diff --verbose
```

### 2. Headless Graphics

Compiles and runs natively with full rendering via Dawn (headless WebGPU) and
lavapipe (software Vulkan). Produces PNG frame captures for pixel-level image
comparison against Ruffle's expected output. Also validates trace output. No
browser required.

```bash
python3 ruffle-tests/verify_output.py --test=TEST_NAME --headless --diff --verbose
python3 ruffle-tests/run_image_tests.py              # all image tests
python3 ruffle-tests/run_image_tests.py --test=color  # single image test
```

This mode supports the same rendering pipeline as WASM/WebGPU graphics mode
(shapes, sprites, transforms, color transforms, clip masking) but runs entirely
on CPU via software rasterization. Tests with `[image_comparisons]` in their
`test.toml` are validated by comparing rendered PNGs against expected PNGs from
the Ruffle test suite.

Currently 14/31 image tests pass with strict pixel match (10/31 within tolerance). See
`avm1/_investigation/IMAGE_COMPARISON_TESTS.md` for detailed status and tier
breakdown of remaining work (Drawing API anti-aliasing, createTextField text layout,
focus rect outline rendering, dynamic mask rendering, external media loading).

### 3. Graphics mode (WASM/WebGPU)

Full rendering via Emscripten + WebGPU. Supports shapes, text, sprites, buttons,
morph shapes, blend modes, drawing API, bitmap rendering, audio playback via Web
Audio. Used for demos and the web-hosted examples. Runs in a browser.

---

## What Is Implemented

### Core AVM1 Language (fully implemented)

These features are the backbone of ActionScript execution. All are mature and
well-tested across hundreds of test cases.

- **Bytecode execution**: All AVM1 opcodes (ActionPush, ActionGetVariable, ActionAdd2,
  ActionCallFunction, ActionDefineFunction2, etc.)
- **Type system**: 15 value types (string, f32, f64, null, undefined, boolean, object,
  array, function, movieclip, etc.) with full coercion rules
- **Object system**: ASObject (property bags with prototype chains), ASFunction (closures
  with captured scopes), ASArray, property flags (DONT_ENUM, DONT_DELETE, READ_ONLY)
- **Scope chain**: WITH scope, function scoping, closure capture of WITH scopes,
  base_clip context for SWF6+ closures
- **Control flow**: try/catch/finally, throw, function calls (type 1 and type 2),
  method dispatch, constructor invocation, super keyword (depth-based)
- **String operations**: Full Unicode support (UTF-16 internal, UTF-8 I/O), SWF version-
  dependent string ops (SWF4 chr/ord, SWF6 mbchr/mbord), case mapping tables
- **Type coercion**: SWF version-aware rules for string concatenation, equality,
  comparison, arithmetic, valueOf/toString invocation

### Built-in Objects and Classes (fully or substantially implemented)

- **Object**: prototype chain, hasOwnProperty, toString, valueOf, addProperty, watch/unwatch,
  isPrototypeOf, isPropertyEnumerable, registerClass, ASSetPropFlags
- **Function**: apply, call, prototype, constructor
- **Array**: Full method set (push, pop, shift, unshift, splice, slice, concat, join,
  sort, sortOn, reverse, toString), hole semantics
- **String**: Full method set (charAt, charCodeAt, indexOf, lastIndexOf, slice, substring,
  substr, split, toLowerCase, toUpperCase, concat, fromCharCode)
- **Number/Boolean**: Constructors, prototype methods, constants (MAX_VALUE, MIN_VALUE, etc.)
- **Math**: All 17 methods + random, 8 constants
- **Date**: Full implementation (constructor, UTC methods, getters/setters, toString variants)
- **XML/XMLNode**: DOM-style API (createElement, appendChild, attributes, childNodes, etc.),
  parseXML, toString serialization
- **TextField/TextFormat**: Property access, HTML text parsing/serialization, text metrics,
  formatting, scroll properties, restrict, StyleSheet CSS parsing, autoSize,
  condenseWhite, TextSnapshot
- **MovieClip**: Timeline control (gotoAndPlay, gotoAndStop, nextFrame, prevFrame),
  createEmptyMovieClip, duplicateMovieClip, attachMovie, swapDepths, getDepth,
  getBounds, hitTest (bounding box and shape-flag), localToGlobal/globalToLocal,
  drawing API (moveTo, lineTo, curveTo, beginFill, endFill, lineStyle, clear)
- **MovieClipLoader**: loadClip (for registered child SWFs), onLoadInit/onLoadStart/
  onLoadComplete/onLoadError callbacks, getProgress
- **BitmapData**: Constructor, getPixel/setPixel/getPixel32/setPixel32, fillRect,
  copyPixels (with mergeAlpha), draw (with matrix and clipRect), clone, dispose,
  noise, perlinNoise, floodFill, threshold, colorTransform, applyFilter (blur),
  compare, hitTest
- **Color/ColorTransform**: setRGB/getRGB, setTransform/getTransform
- **Point/Matrix/Rectangle/Transform**: Geometry classes with full method sets
- **Key/Mouse**: Event listeners, isDown, getCode, addListener/removeListener
- **Stage**: Properties (width, height, scaleMode, align, showMenu, displayState),
  onResize callback
- **Selection**: setFocus, getFocus, setSelection, getBeginIndex/getCaretIndex/getEndIndex
- **Sound**: Constructor, attachSound, loadSound (embedded MP3 via minimp3), start, stop,
  setVolume/getVolume, setPan/getPan, setTransform/getTransform, getDuration/getPosition,
  duration/position native getters, onLoad/onSoundComplete/onID3 callback lifecycle
- **SharedObject**: getLocal with data object (in-memory only, no persistence)
- **ExternalInterface**: available, addCallback, call (via test harness mock)
- **AsBroadcaster**: initialize, addListener, removeListener, broadcastMessage
- **System.capabilities**: Stub properties (os, playerType, version, etc.)
- **Accessibility**: Stub (isActive returns false)

### Timeline and Display List (fully implemented)

- **Frame execution**: Multi-frame playback, frame labels, scene support, goto with
  catch-up (forward and backward), deferred script queues
- **Sprite lifecycle**: PlaceObject2/3 placement, RemoveObject2, depth management,
  clip depth masking, sprite initialization ordering, registered class constructors
- **Clip events**: onLoad, onEnterFrame, onUnload, onMouseDown/Up/Move, onKeyDown/Up,
  onData, button state events (onPress, onRelease, onRollOver, etc.)
- **Button support**: DefineButton2, button state tracking, hit testing, event dispatch
- **MC pending removal**: Unload handler persistence, transformed depth, one-frame delay
- **Multi-SWF loading**: loadMovie/loadMovieNum via registered MovieEntry table,
  _level loading, root replacement, cross-movie variable isolation, _lockroot

### Rendering (graphics and headless graphics modes)

- **Shape rendering**: Solid-color filled shapes, correct geometry and positions
- **Sprite rendering**: Nested sprite composition with unique composed transforms
- **Transform pipeline**: Static timeline transforms uploaded to GPU; dynamic slot
  allocation for composed sprite transforms; runtime _x/_y/_xscale/_rotation updates
  propagated to GPU buffer each frame
- **Color transforms**: Static cxform from timeline + runtime Color.setRGB()/setTransform()
  updates via dynamic cxform slots
- **Clip masking**: Static clip masks from PlaceObject2 clip_depth
- **Text rendering**: Embedded font glyph tessellation + device font rendering via
  bundled Noto Sans TTF (stb_truetype); text field background/border rects
- **BitmapData rendering**: attachBitmap GPU pipeline, all BitmapData pixel operations
  rendered to texture (fillRect, copyPixels, perlinNoise, pixelDissolve, colorTransform,
  applyFilter ColorMatrixFilter)
- **Drawing API rendering**: Runtime shapes tessellated via libtess2 with adaptive
  bezier flattening; solid fills, gradient fills (linear/radial/focal radial)
- **Stage origin**: Correct viewport for SWFs with non-zero stage origin
- **Frame capture**: PNG output at configurable frame triggers for image comparison

### Input Event Simulation (implemented for trace testing)

The test harness simulates mouse clicks, key presses, focus changes, and drag
operations via injected event sequences. This allows testing interactive behaviors
without a real UI.

---

## What Is Not Yet Implemented

Features below are not yet working but are on the roadmap. They are grouped by the
execution mode that enables testing them.

### Headless Graphics — Rendering Gaps

These features need to work in headless graphics mode to pass the image comparison
tests. See `avm1/_investigation/IMAGE_COMPARISON_TESTS.md` for detailed tier
breakdown.

| Feature | Status | Tests Affected | Notes |
|---------|--------|---------------|-------|
| Runtime transform GPU updates | **Complete** | display_object_properties, color | Per-frame rebuild from MC properties when as_set_flags != 0 |
| Runtime cxform GPU updates | **Complete** | color, display_object_properties | Dynamic cxform slots + alpha blend state fix |
| createTextField rendering | **Partial** | frame_size_translated_*, edittext_*, movieclip_create_text_field | Background/border + glyph rendering working; text layout/anti-aliasing differences remain |
| Drawing API rendering | **Partial** | movieclip_begin_gradient_fill, mask_with_drawing, movieclip_setmask | libtess2 tessellation + gradient rendering working; anti-aliasing precision gaps remain |
| BitmapData rendering | **Complete** | 6 bitmap_data_* image tests | All 6 image tests pixel-perfect via attachBitmap GPU pipeline |
| Focus rect rendering | **Partial** | 5 focusrect_* tests | 9/12 focusrect_swf5 captures pass; outline vs solid fill issue remains |
| Runtime setMask() | Not started | mask_reapply, mask_with_drawing | Dynamic masks (vs static clip_depth) |

### Audio and Video

These features need implementation in both graphics and headless modes. Audio
playback exists in WASM/WebGPU mode via Web Audio but is not yet tested
systematically. Video playback is not implemented in any mode.

| Feature | Status | Tests Affected | Notes |
|---------|--------|---------------|-------|
| Sound.loadSound() | **Implemented** | sound_load_start (PASS), sound_multiple_load (PASS) | Loads embedded MP3 via data registry + minimp3 decoder |
| Sound duration/position | **Implemented** | sound_duration_position_props (PASS) | getPosition/getDuration, duration/position getters, onID3/onLoad/onSoundComplete lifecycle |
| ID3 tag parsing | Not started | sound_id3, sound_id3_prop | Needs MP3 header + ID3v1/v2 parser (onID3 dispatch exists, but no tag parsing) |
| FLV playback | Not started | netstream_play_flv, netstream_play_flv_screen, netstream_seek_flv | Needs FLV demuxer + video codec |
| NetConnection | **Partial** | netconnection_close (PASS), netconnection_send_remote | connect(null)/close + onStatus dispatch implemented; remote AMF calls not implemented |

### Network and External I/O

These features require loading resources from files or network. Some may be
implementable via mock/local file loading in the test harness; others need
real network infrastructure.

| Feature | Status | Complexity | Tests Affected | Notes |
|---------|--------|-----------|---------------|-------|
| XML.load() | Not started | Medium | swf5_xml_event_handler_context, xml_load | XML parsing works; resource loading does not |
| LoadVars.load/send | Not started | Medium | load_vars, loadvariables_method | URL encoding/decoding works; HTTP does not |
| StyleSheet.load() | Not started | Medium | stylesheet_load | CSS parsing works; loading does not |
| Image loading (loadMovie) | Not started | Medium | mcl_target_png/jpg/gif*, movieclip_methods_with_loaded_image | Needs stb_image or similar |
| HTTP form POST | Not started | Medium | form_loader_encoding_2/3/4 | Needs HTTP client or mock |
| XMLSocket | Not started | Hard | xml_socket, xml_socket_* | Needs TCP socket abstraction |
| FileReference | Not started | Hard | 8 file_reference_* tests | Needs OS file dialogs + HTTP upload/download |
| LocalConnection | Stub only | Hard | localconnection | Full IPC protocol; also needs AVM2 child for some sub-tests |

### Pixel-Level Text Layout

These features require mapping pixel coordinates to character positions, which
depends on per-character glyph width data. Text field *properties* are fully
implemented (62+ tests pass); what's missing is the coordinate-to-character bridge.

| Feature | Status | Tests Affected | Notes |
|---------|--------|---------------|-------|
| Character-level selection from pixel coords | **Implemented** | edittext_drag_select (PASS) | Mouse drag → character index via glyph advance tables |
| TextField hyperlink hit testing | Not started | asfunction | Maps mouse (x,y) → which `<a>` link; needs asfunction: protocol handler |
| IME composition | Not started | edittext_ime_focus_lost | Input Method Editor event injection + composition state tracking |

Character-level selection was implemented using glyph advance tables from the font
metrics infrastructure. The remaining two features (hyperlink hit testing and IME)
can reuse the same character-index-from-pixel-coords infrastructure.

### Bitmap/Filter Edge Cases

BitmapData is fully implemented (17/17 trace tests pass). All bitmap/filter edge
cases have been resolved:

| Feature | Status | Tests Affected | Notes |
|---------|--------|---------------|-------|
| DisplacementMapFilter.mapPoint setter | **Complete** | displacementmapfilter_mappoint_throw_error (13/13 PASS) | setjmp-based valueOf throw propagation in native setter |
| BitmapData.pixelDissolve PRNG | **Complete** | bitmap_data_pixeldissolve (1075/1075 PASS) | Feistel network PRNG matching Flash's dissolution pattern |
| Filter clone/complex chains | **Complete** | bitmap_filters (548/548 PASS) | filter.clone(), mc.filters round-trip, property coercion/clamping, gradient array sync |

### Multi-SWF Sandbox Security

| Feature | Status | Tests Affected | Notes |
|---------|--------|---------------|-------|
| Remote sandbox type | Not started | sandbox_type_remote | Needs cross-domain SWF loading simulation |
| allowDomain / cross-domain policy | Not started | (none currently) | Security policy infrastructure |

### Global Constructor Enumeration

| Feature | Status | Tests Affected | Notes |
|---------|--------|---------------|-------|
| constructor DONT_ENUM reconciliation | **Reclassified** | global_proto_decls (809/4497), global_instance_decls (14/758), global_proto_decls_delete (297/4158) | Ruffle vs Flash difference: Ruffle makes constructor ENUMERABLE, Flash uses DONT_ENUM. Tests moved to ignored list. |
| Missing flash.* stubs and constants | **Substantially done** | Same 3 tests | Key constants, IME methods, System.security, System.capabilities added. Remaining gap is property enumeration order. |

---

## Out of Scope

### AVM2 / ActionScript 3

AVM2 (ActionScript 3) is a different virtual machine with a different bytecode
format, class-based object model, and verification system. Supporting it would be
a separate project.

| Feature | Tests Affected | Notes |
|---------|---------------|-------|
| AVM2 bytecode execution | 30 Shumway AVM2 tests | Cannot parse or execute AS3 |
| AVM1↔AVM2 communication | localconnection (partial) | AVM2 child in localconnection test |
| loading_avm2 | loading_avm2 | Cross-VM loading |

---

## Decision Framework

When evaluating whether to implement a feature, we apply these criteria:

### 1. Is it testable?

Features must be testable in at least one execution mode. Trace-only mode covers
the most ground, but headless graphics mode enables image comparison tests, and
will also enable testing of audio, video, and resource loading features.

### 2. How many tests does it unlock?

Features that fix multiple tests or unlock large line counts are prioritized over
features that fix a single test. The 100+ completed plans each fixed between 1 and
5000+ lines of test output.

### 3. Is it core AVM1 behavior?

Faithfully implementing the ActionScript execution model (type coercion, scope
chains, prototype chains, event dispatch, timeline control) is prioritized over
peripheral platform APIs. But rendering, audio, and media playback are also
important — they are what makes SWFs actually run.

### 4. Does Flash behavior have an authoritative specification?

When Flash's behavior is well-documented (SWF spec, ECMAScript-derived semantics),
we follow Flash. When behavior is undocumented or ambiguous, we use Ruffle's
implementation as a reference but prefer Flash-correct behavior over Ruffle-compatible
behavior when the two conflict (see `RUFFLE_VS_FLASH_DIFFERENCES.md`).

### 5. What is the implementation cost relative to value?

Some features require massive infrastructure for limited test coverage. These are
deprioritized but not permanently ruled out. The project's trajectory has been to
exhaust high-value fixes first, then expand the test infrastructure to enable new
categories of work.

---

## Ignore List Policy

Tests are added to `ignored_tests.txt` (excluded from filtered pass rate) when they
meet one or more of these criteria:

1. **Infrastructure not yet available**: The test needs capabilities (network, file I/O,
   audio loading) not yet available in any test execution mode. Tests may be removed
   from the ignore list as new capabilities are added.
2. **Ruffle-specific behavior**: The expected output reflects Ruffle's implementation
   rather than Flash Player's behavior, and our output matches Flash. Documented in
   `RUFFLE_VS_FLASH_DIFFERENCES.md`.
3. **Platform-dependent undefined behavior**: The expected output depends on C UB,
   timezone, or machine-specific results that cannot be portably reproduced.
   Documented in `ACCEPTED_DIFFS.md`.
4. **Zero expected trace lines**: The test validates non-trace behavior (image
   comparison, timeout detection) that has no trace-based validation path. Image
   comparison tests are validated separately via `run_image_tests.py`.

Tests are **not** ignored simply because they fail. A test remains in the filtered
results if there is any reasonable prospect of improving it through runtime fixes,
even if it currently has a low match rate.

---

## Related Documents

| Document | Purpose |
|----------|---------|
| `avm1/_investigation/IMAGE_COMPARISON_TESTS.md` | Headless image test status, tier breakdown, rendering gaps |
| `avm1/_investigation/ACCEPTED_DIFFS.md` | Tests with permanently unfixable diffs |
| `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` | Where we match Flash but not Ruffle |
| `avm1/_investigation/RUFFLE_COMPAT_TWEAKS.md` | Arbitrary choices made to match Ruffle |
| `avm1/_investigation/FLASH_BUGS_REPLICATED.md` | Known Flash Player bugs we deliberately replicate |
| `avm1/_investigation/BLOCKER_SUMMARY.md` | Active and resolved blockers |
| `avm1/_investigation/REMAINING_FAILURES_ANALYSIS.md` | Per-test failure analysis |
| `avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md` | Details on ignored network/external tests |
