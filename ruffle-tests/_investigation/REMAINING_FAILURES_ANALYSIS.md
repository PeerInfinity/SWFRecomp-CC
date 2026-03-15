# Remaining Filtered Failures Analysis

Date: 2026-03-15
CI run: 86ba0864 (555/619 total, 545/565 filtered = 96.5%)

18 filtered tests still failing (2 fixed, 1 moved to ignored). This document analyzes each one with local test output, root cause, and fix feasibility.

## Summary Table

| Test | Match | Total | Rate | Difficulty | Category |
|------|-------|-------|------|------------|----------|
| unload_nested_child | 4 | 5 | 80% | Hard | deferred unload timing (nextFrame inline) |
| clone_sprite_edittext_dynamic | 78 | 86 | 91% | Medium | TF clone bounds |
| edittext_drag_select | 6 | 9 | 67% | Medium | selection markers |
| issue_2084 | 4 | 16 | 25% | Medium | nested sprite init |
| ~~issue_2030~~ | ~~2~~ | ~~4~~ | ~~100%~~ | ~~Fixed~~ | ~~attachBitmap stub~~ |
| movieclip_hittest_shapeflag | 307 | 339 | 91% | Hard | shape hit accuracy |
| coerce_to_object_monkeypatch | 71 | 129 | 55% | Hard | primitive coercion |
| watch_virtual_property | 11 | 61 | 18% | Hard | watch+addProperty |
| asfunction | 2 | 12 | 17% | Medium | asfunction: URL |
| displacementmapfilter_mappoint_throw_error | 0 | 13 | 0% | Medium | Point toString + filter errors |
| ~~geturl~~ | ~~0~~ | ~~7~~ | ~~N/A~~ | ~~Ignored~~ | ~~Ruffle-internal navigator tracing~~ |
| edittext_ime_focus_lost | 0 | 7 | 0% | Very Hard | IME infrastructure |
| localconnection | 127 | 580 | 22% | Very Hard | full IPC system |
| global_proto_decls | 92 | 4497 | 2% | Very Hard | property flags + stubs |
| global_instance_decls | 17 | 758 | 2% | Very Hard | property flags + stubs |
| global_proto_decls_delete | 90 | 4158 | 2% | Very Hard | property flags + stubs |
| swf5_xml_event_handler_context | 0 | 2 | 0% | Very Hard | XML.load() |
| movieclip_methods_with_loaded_image | 0 | 4 | 0% | Very Hard | external PNG loading |
| sandbox_type_remote | 0 | 3 | 0% | Very Hard | multi-SWF sandbox |

## Tier 1: Quick Wins (0 tests)

*All quick wins resolved:*
- ~~text_blocks_clicks~~ — **FIXED** (df1f69a2): DefineText bounds now registered via `ng_record_char_bounds`, enabling sprite content bounds for `_droptarget`.
- ~~tab_ordering_properties_tab_index_edge_case~~ — Already in `ignored_tests.txt` (Ruffle `known_failure`, contradicts `tab_ordering_properties` coercion semantics).

### unload_nested_child (4/5 lines)

**Previous**: 0/5 → 2/5 (nested MC click fix) → **4/5** (recursive child unload detection).

Remaining 1 wrong line:
1. **Ordering**: "unload" fires before "go completed" — should be after. In Flash, `nextFrame()` does NOT execute the target frame inline; the unload and DoAction scripts are deferred until the frame loop processes the frame. Our `ng_executeGotoTagsOnly` runs tags inline during nextFrame.

Root cause: `fire_recursive_child_unloads` fires inline during `tagRemoveObject2`, but Flash defers child unload execution to the start of the next frame. Fixing this would require changing how `nextFrame()` dispatches — using deferred frame processing instead of `ng_executeGotoTagsOnly`.

## Tier 2: Medium Effort (4 tests, +4 pass)

### clone_sprite_edittext_dynamic (78/86 = 91%)

8 mismatched lines. Two issues:
1. Cloned text field bounds wrong: `_x` is -237.6 vs expected 19, `_width` 19 vs 4, `_height` 20.3 vs 4 for text2.
2. `htmlText` wrapping differs: our output breaks into multiple `<P>` tags vs expected single line.
3. One `_height` rounding issue (21.55 vs 21.5).

Root cause is duplicateMovieClip text field cloning — transform/bounds not copied correctly.

### edittext_drag_select (6/9 = 67%)

3 lines wrong. The `<selection>` markers in text output are at wrong character positions — placed at start instead of correct offset within the text. Requires proper character-level selection tracking for mouse drag-select.

### issue_2084 (4/16 = 25%)

Two issues:
1. `icon_1` and `icon_3` y-coordinates are 1 instead of 20 — child sprite placement/transform bug.
2. Second "Column onLoad" block (lines 9-13) and final onEnterFrame block (lines 14-16) missing entirely — second loadMovie or duplicate sprite init not firing.

Likely involves attachMovie or duplicateMovieClip ordering with nested sprites.

### asfunction (2/12 = 17%)

`asfunction:` URL protocol not implemented. Test uses `getURL("asfunction:callback,arg")` in text fields to call AS functions. Requires parsing `asfunction:functionName,arg` URLs and dispatching to the named function. Focused feature addition.

## Tier 3: Hard / Diminishing Returns (4 tests)

### movieclip_hittest_shapeflag (307/339 = 91%)

32 lines wrong. Shape-flag hitTest (`hitTest(x, y, true)`) returns wrong results for various coordinates across fills, strokes, layers, bg art, text/dynamic text, and morph shapes. Requires more accurate shape geometry — curves, stroke width, masking. Incremental improvements possible but full accuracy needs shape rasterization.

### coerce_to_object_monkeypatch (71/129 = 55%)

Two categories:
1. `new "callme"()` should trigger a String getter on `_global` — missing getter invocation (2 lines, offset cascade).
2. Number-to-object coercion when Number constructor is deleted/replaced: expected `coerced: undefined` + `is _global!` but we produce `coerced: _level0`. Falls back to MC instead of global.

Core issue is primitive-to-object coercion logic when built-in constructors are monkeypatched. Previously identified as blocked by closure variable capture.

### ~~issue_2030~~ (4/4 = PASS ✅)

**FIXED** (2c900777): Added `MC.attachBitmap` stub that copies BitmapData width/height to the MC and sets draw bounds. `_width`/`_height` now report correctly after `attachBitmap`.

### watch_virtual_property (11/61 = 18%)

`watch()` callback does not fire when an `addProperty` virtual property is set. The watch handler should intercept and modify the value before it reaches the addProperty setter. Also `unwatch()` returns false instead of true. Note: this is a Ruffle `known_failure` — even Ruffle may not handle this correctly.

## Tier 4: Not Feasible / Major Infrastructure (10 tests)

### displacementmapfilter_mappoint_throw_error (0/13)

`DisplacementMapFilter.mapPoint` returns `[object Object]` instead of `(x=1, y=2)` Point toString format. Also missing: try/catch error handling for invalid Point property values (valueOf throwing), and integer overflow clamping. Requires Point toString `(x=N, y=N)` format + filter setter validation.

### ~~geturl~~ (0/7) — IGNORED

Added to `ignored_tests.txt`. Test traces Ruffle's internal `Navigator::navigate_to_url` dispatch output (URL, target, method, params), not standard Flash `trace()` output. Cannot be replicated without Ruffle's navigator backend.

### edittext_ime_focus_lost (0/7)

Complete mismatch. Requires IME (Input Method Editor) simulation — text input via IME composing, focus changes, onChanged callbacks. IME infrastructure doesn't exist.

### localconnection (127/580 = 22%)

Full `LocalConnection` IPC system not implemented. Only structural framework markers match. Requires connect/send/close methods, onStatus callbacks, receiver method dispatch. Massive standalone feature.

### global_proto_decls (92/4497 = 2%)

Two issues: (a) `constructor` properties show `DONT_ENUM` flag when they shouldn't, (b) output truncates early — many classes/prototypes missing entirely. Requires enumerating property flags and adding hundreds of missing global class stubs. Enormous surface area.

### global_instance_decls (17/758 = 2%)

Instance creation mostly works but: missing `DONT_DELETE` on `__proto__`, many instance properties missing (PrintJob, FileReference, etc.), property ordering mismatches. Same class of problem as global_proto_decls.

### global_proto_decls_delete (90/4158 = 2%)

Property ordering wrong for many classes, many class prototype methods missing entirely, output truncated early. Same root cause as global_proto_decls.

### swf5_xml_event_handler_context (0/2)

Requires `XML.load()` with onLoad callback in SWF5 context. XML loading infrastructure not implemented.

### movieclip_methods_with_loaded_image (0/4)

Requires `loadMovie` to load an external PNG image, then check `getBytesTotal()`, `getBytesLoaded()`, `getSWFVersion()`, `_url` on the loaded clip. External asset loading not implemented.

### sandbox_type_remote (0/3)

Requires multi-SWF loading with different sandbox type configurations (`[network]` and `[no network]` child contexts). Deep infrastructure.

## Recommended Priority Order

1. **unload_nested_child** — 3 remaining lines, needs deferred unload timing + recursive child unload detection
2. **clone_sprite_edittext_dynamic** — 91% match, 8 lines of TF clone fixes
3. **edittext_drag_select** — 3 lines, selection marker positioning
4. **issue_2084** — nested sprite init ordering
5. **asfunction** — focused feature (asfunction: URL protocol)

Tests 6-19 are either blocked by missing infrastructure, have diminishing returns, or require architectural changes not worth the effort at 96.5% filtered pass rate.
