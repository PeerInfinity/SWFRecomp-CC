# Current Ruffle Test Status

Last updated: 2026-02-20 (TextField Phase 3+5: textfield_props_swf5, edittext_newline_stripping, edittext_html_align_swf7/swf8)

Previous CI baseline: 227/619 (36.7%), commit d71ead7

## Quick Summary

- **Pass rate (CI)**: 227/619 (36.7%) — pending CI run for TextField phase (no regressions expected)
- **Main failure type**: output_mismatch, timeout (2), segfault (1)
- **Recent gains**: `textfield_props_swf5`, `edittext_newline_stripping`, `edittext_html_align_swf7`, `edittext_html_align_swf8` now pass
- **Active plans**: input-event-injection.md Phases 0–7 COMPLETE; Phases 8+9 are now separate plans:
  - **MOUSE_EVENTS_PLAN.md** — `_xmouse`/`_ymouse`, clip mouse event dispatch (5 tests)
  - **FOCUS_SYSTEM_PLAN.md** — mouse-triggered focus, onSetFocus/onKillFocus (6 tests)
  - **TAB_ORDERING_PLAN.md** — Tab key focus navigation, tabIndex/tabEnabled (16 tests)
  - **DRAG_DROP_PLAN.md** — startDrag/stopDrag, _droptarget (4 tests)

## Major Features Implemented Since Last Update

| Feature | Commits | Impact | Key Tests |
|---------|---------|--------|-----------|
| **Phase 7: Key Events + frame-first loop** | 0183209 | Key object (isDown/getCode/getAscii/isToggled), broadcastMessage impl, Key AsBroadcaster, button key conditions, frame-first event ordering, quit_swf loop continuation | `button_goto` ✅, `key_isToggled` ✅ |
| **Input event injection (Phases 0.3-5)** | a58b421, d71ead7 | shape_data/hit_test in NO_GRAPHICS; event pump; Mouse AsBroadcaster; AsBroadcaster regression fix | `mouse_listeners` ✅, `as_broadcaster_initialize` ✅ |
| **Object.prototype.watch/unwatch** | 0a9e034, 85c676f | Property change callbacks; watcher fires before addProperty setter; static buffer reentrancy fix | `watch` ✅, `watch_virtual_property_proto` ✅, `object_prototypes` ✅, `parse_int` ✅ |
| **Number.prototype.toString(NaN, radix)** | 743325f | NaN encoded as INT32_MIN via x86 CVTTSD2SI, then inverted digit encoding char(48-N); \r→\n normalization | `primitive_type_globals` ✅ (557/557) |
| **edittext _width/_height transform fix** | 337c212 | Width/height properties now account for _xscale/_yscale/_rotation transforms | edittext_width_height (103/103 ✅) |
| **arguments object: DefineFunction2 preload path** | 2f007dd | swf_setup_arguments_props() now called from recompiler-generated preload block; fixes callee/caller/__proto__/instanceof for preloaded-arguments functions; ARRAY valueOf/toString fixed to use own-property lookup only (fixes [object Object] bug) | arguments (127/127 ✅) |
| **arguments object: callee/caller/__proto__** | b9cfc9d | arguments.callee, arguments.caller (null or calling function), arguments instanceof Array, arguments.__proto__ === Array.prototype — all now implemented; also fixes Array.prototype initialization and checkInstanceOf for arrays | arguments |
| **DefineFunction2 preload/suppress fix** | eff1f85 | `function_suppress_and_preload` now passes; correct register numbering when both preload + suppress bits are set; scope vars (this/super/arguments) set via local_scope in method calls | function_suppress_and_preload |
| **TextField enumeration + condenseWhite fix** | 229cb53 | textfield_props_swf6/7/8 now pass, xml_to_string, xml_child_nodes_edge_cases, swf4_function_calls pass | textfield_props_swf6/7/8 (+3), xml_to_string (+1), xml_child_nodes_edge_cases (+1) |
| **SWF5 undefined variable + stub ctors** | 1851972 | try_catch_finally, get_variable_in_scope, swf7_case_sensitive, divide_swf4 now pass | +4 tests |
| **Date class** | 480bce0 | 8 new passing tests, +1432 matching lines in `date` test (5049/6335 on CI) | date (80% match — remaining diffs are timezone-dependent) |
| **Try/catch/finally** | b815da5 | Exception handler stack with typed catch blocks, finally support | try_catch_finally (107/118, 91% match — was segfault) |
| **XML/XMLNode** (Phases 1-7) | c8c38b1, 73a7b45, 733a70e, 0778863 | 24 XML tests passing | xml_namespaces (203 lines), xml_inspect_parsexml (62 lines) |
| **TextField Phase 1-2** | 8811360, bce37d6, 7532231, bceacde, 711e25a | 17 TF tests passing | text_format (1146 lines), text_format_rounding (840 lines each) |
| **flash.geom** | cd84b0f | 3 tests passing | point (175), matrix (171), rectangle (745) |
| **Global constructors** | 3048065, 06244c7 | 3 tests passing | globals_swf6/7/8 (304 lines each) |
| **Math object** | c5804d0 | 1 test passing | math_min_max (101 lines) |
| **String methods** (Phases 1-4) | 3fb6a61, 17b33b9, 12e36a9, b4d13aa | 4 string tests + string_ops_swf6 pass | string_methods (285), string_ops_swf6 (95) |
| **MovieClip Phase 1** | c616aeb | 2 MC tests passing | movieclip_default_state, movieclip_blend_mode_property |

## Date Test Details

The `date` test (6335 lines). With `TZ=Asia/Kathmandu` set in CI (fixed 2026-02-18), expected to match ~6,284 lines (~99.2%). Only ~103 diff lines remain, all unfixable:

1. **Timezone mismatch**: **FIXED** — `TZ: Asia/Kathmandu` added to both "Verify runtime output" steps in `.github/workflows/ruffle-tests.yml`.
2. **Extreme date edge cases (~103 diff lines)**: Unfixable — Flash-specific int32 overflow UB for Infinity/NaN setters, internally inconsistent expected output for dates near -8.64e15.

## Top Near-Passing Tests (best ROI to fix)

Tests marked ✅ have started passing since last CI run and are expected to pass in the next CI run.

### Tier 1: Now Passing ✅

These tests were near-passing in the previous update and now pass locally:
- `textfield_props_swf6`, `textfield_props_swf7`, `textfield_props_swf8` — fixed by 229cb53
- `xml_to_string`, `xml_child_nodes_edge_cases`, `swf4_function_calls` — fixed by 229cb53
- `try_catch_finally`, `get_variable_in_scope`, `swf7_case_sensitive`, `divide_swf4` — fixed by 1851972
- `function_suppress_and_preload` — fixed by eff1f85 + 2f007dd (DefineFunction2 preload/suppress + ARRAY toString fix)
- `edittext_width_height` (103/103) — fixed by 337c212 (_xscale/_yscale/_rotation transform accounting)
- `arguments` (127/127) — fixed by b9cfc9d + 2f007dd (callee/caller/__proto__/instanceof Array; preload path fix)
- `duplicate_movie_clip` (21/21) ✅ — clone/duplicate plan (this branch): as_set_flags copy, ng_duplicateMovieClip, toString/valueOf for object args, depth+16384 semantic
- `clone_sprite_types` (25/25) ✅ — clone/duplicate plan (this branch): ng_isScriptableAtDepth for non-scriptable types (shape/statictext/morphshape/image return parent MC), tagDefineVideoStream for video scriptability
- `textfield_props_swf5` (87/87) ✅ — d649861: SWF5 TextField properties 0-29 now non-writable (setPropertyWithFlags)
- `edittext_newline_stripping` (46/46) ✅ — 51acce6: multiline text fields without variable bindings get trailing '\n' appended to initial text
- `edittext_html_align_swf7` (52/52) ✅ — 235fd38: HTML-aware alignment in getNewTextFormat/getTextFormat
- `edittext_html_align_swf8` (52/52) ✅ — 235fd38: HTML-aware alignment (SWF8: left when tag-HTML but script set html=false)

### Tier 2: 3-15 lines off

| Test | Match | Issue |
|------|-------|-------|
| ~~`object_prototypes`~~ | 74/74 ✅ | watch/unwatch implemented + case-insensitive __proto__ lookup |

### Tier 3: 80-82% match

| Test | Match | Issue |
|------|-------|-------|
| `local_to_global` | 40/49 (82%) | MovieClip.localToGlobal/globalToLocal coordinate transforms |
| `edittext_html_align_swf7` | 42/52 (81%) | HTML align attribute handling |
| `stage_object_children` | 67/83 (81%) | Child clip enumeration order |
| `date` | ~6284/6335 (99.2%) | CI TZ fix applied; ~103 diff lines remain (all unfixable Flash int32 edge cases) |
| `target_clip_removed` | 4/5 (80%) | GotoFrame inline execution not triggering root frame 2 |

## Crashes and Timeouts (4 tests)

| Test | Status | Notes |
|------|--------|-------|
| goto_methods | segfault | MovieClip.gotoAndStop/gotoAndPlay with extreme values (8/40) |
| movieclip_hittest_shapeflag | compile_fail | **NEW REGRESSION** — was output_mismatch (180/338), now fails to compile |
| timeout | timeout | setTimeout/clearTimeout not implemented |
| try_catch_finally | timeout | On CI only (runs fine locally; may need longer timeout) |

### Resolved crashes (from previous update)
- `enumerate` — no longer segfaults
- `function_base_clip_removed` — no longer segfaults
- `init_object_order` — no longer segfaults
- `register_and_init_order` — no longer segfaults
- `register_class` — no longer segfaults
- `try_catch_finally` — no longer segfaults (now runs, 91% match locally)

## Plan Implementation Status

| Plan | Status | Tests Passing | Key Remaining |
|------|--------|--------------|---------------|
| DATE_PLAN | **FULLY COMPLETE** (moved to complete/) | 8+ tests passing; `date` at ~99.2% (103 diff lines, all unfixable edge cases) | TZ=Asia/Kathmandu added to CI workflow |
| TRY_CATCH_PLAN | **Phase 1 DONE** | 0 pass (91% match) | Typed catch block matching (String/Object/etc.) |
| MATH_PLAN | **COMPLETE** | 1/4 pass, 3 at 98.5% | ASnative(200,50), throwing valueOf |
| STRING_PLAN | **Phases 1-4 COMPLETE** | 4/4 method tests + string_ops_swf6 pass | String paths blocked by MC infra |
| GLOBALS_PLAN | **Phase 6 DONE** | globals_swf6/7/8, primitive_type_globals PASS | Phase 7-8 (prototype methods, property flags) |
| XML_PLAN | **ALL PHASES COMPLETE** | 24/26 active tests pass | xml_to_string (11/13), xml_child_nodes_edge_cases (3/4) |
| TEXTFIELD_PLAN | **Phases 1-3 DONE, Phase 5 PARTIAL** | 25/66 tests pass | Phase 4 (scroll), Phase 5 (htmlText roundtrip, color, condenseWhite), Phase 6 (layout) |
| MOVIECLIP_PLAN | **Phase 1 DONE** | 2 MC tests pass | Phase 2 (depth), Phase 3 (createEmptyMC) |
| PARSING_FUNCTIONS_PLAN | **Partially done** | 0/2 pass | parse_int may now be unblocked (arguments fixed) |
| COLOR_OBJECT_PLAN | Not started | 0/4 | - |
| OOP_SUPER_EXTENDS_PLAN | Not started | 0/8 | - |
| REGISTERCLASS_PLAN | Not started | 0/7 | - |
| PROTOTYPE_OBJECT_PLAN | Not started | 0/12 | - |
| ENUMERATION_PLAN | **FULLY COMPLETE** (moved to complete/) | 5/5 pass | All done: colon-path, dot-path, MC dynamic props lookup |
| WITH_SCOPE_PLAN | Not started | 0/2 | DefineLocal scoping, MC identity, null skip |
| TIMER_PLAN | Not started | 0/3 | setInterval, setTimeout |
| STAGE_PLAN | Not started | 0/7 | Stage object, MC precision, child enum |
| SELECTION_PLAN | Not started | 0/2 | Focus tracking, replaceSel |
| OBJECT_WATCH_PLAN | **Phase 1 DONE** | 3/4 pass (`watch`, `watch_virtual_property_proto`, `object_prototypes`) | `watch_textfield` — MC dispatch + MC watcher in SetMember needed |
| NATIVE_INTROSPECTION_PLAN | Not started | 0/2 | ASnative, ASSetPropFlags |
| TELLTARGET_PLAN | Not started | 0/3 | tellTarget scope |
| CLONE_DUPLICATE_PLAN | **Phase 1 DONE** | 2/5 pass | clone_sprite_edittext (needs TF clone), clone_sprite_edittext_dynamic (needs TF clone) |
| UNLOAD_PLAN | Not started | 0/3 | unloadMovie, onUnload |
| **MOUSE_EVENTS_PLAN** | **Not started** | 0/5 | `_xmouse`/`_ymouse`, clip mouse event dispatch |
| **FOCUS_SYSTEM_PLAN** | **Not started** | 0/6 | Mouse-triggered focus, onSetFocus/onKillFocus, key-to-focused dispatch |
| **TAB_ORDERING_PLAN** | **Not started** | 0/16 | Tab key focus navigation, tabIndex/tabEnabled/tabChildren |
| **DRAG_DROP_PLAN** | **Not started** | 0/4 | startDrag/stopDrag, _droptarget |
| All others | Not started | - | - |

## Recommended Work Order

### High ROI (fix existing near-passing tests)
1. ~~**Fix `date` test timezone**~~ — **DONE**: TZ=Asia/Kathmandu added to CI workflow (2026-02-18); date now at ~99.2%
2. ~~**Implement watch()/unwatch()**~~ — **DONE**: `watch`, `watch_virtual_property_proto`, `object_prototypes` now pass
3. ~~**Investigate movieclip_hittest_shapeflag compile_fail**~~ — **FIXED**: now back to MISMATCH (180/338)
4. ~~**Try parse_int**~~ — **DONE**: passes now

### Medium ROI (new feature phases)
5. ~~**GLOBALS_PLAN Phase 6**~~ — **DONE**: Number.prototype.toString(NaN,radix) implemented; primitive_type_globals now 557/557
6. **TEXTFIELD_PLAN Phase 3** — variable binding + width/height
7. **TEXTFIELD_PLAN Phase 5** — HTML text (edittext_html_* tests, several at 81-87%)
8. **Fix GotoFrame inline execution** — needed for target_clip_removed (4/5, 80%)

### Lower ROI (new features)
9. **COLOR_OBJECT_PLAN** — 4 tests, requires Color constructor + flash.geom.Transform
10. **MOVIECLIP_PLAN Phases 2-3** — depth methods, createEmptyMovieClip
11. **OOP_SUPER_EXTENDS_PLAN** — super keyword, 8 tests
12. **PROTOTYPE_OBJECT_PLAN** — addProperty, __resolve, property flags, 12 tests
