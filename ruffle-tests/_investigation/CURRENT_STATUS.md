# Current Ruffle Test Status

Last updated: 2026-02-15, commit 5a5d440 (latest CI: b4d13aa)

## Quick Summary

- **Pass rate**: 205/619 (33.1%) — up from 112/616 (18.2%) at last update
- **Main failure type**: output_mismatch (406), segfault (7), timeout (1)
- **Regressions**: 4 new segfaults (init_object_order, register_and_init_order, register_class, function_base_clip_removed); try_catch_finally changed from timeout to segfault
- **Resolved crashes**: device_font_spacing, duplicate_movie_clip_drawing, path_string, swf4_actions_coercion_order no longer segfault; parse_float no longer times out (43/74 now)
- **Recent gains**: string_methods (285/285) and string_ops_swf6 (95/95) now fully pass after Unicode case mapping + SWF4/6 string op fixes in commit b4d13aa

## Major Features Implemented Since Last Update

| Feature | Commits | Tests Now Passing | Key Tests |
|---------|---------|------------------|-----------|
| **XML/XMLNode** (Phases 1-7) | c8c38b1, 73a7b45, 733a70e, 0778863 | 24 XML tests | xml_namespaces (203 lines), xml_inspect_parsexml (62 lines) |
| **TextField Phase 1-2** | 8811360, bce37d6, 7532231, bceacde, 711e25a | 17 TF tests | text_format (1146 lines), text_format_rounding (840 lines each) |
| **flash.geom** | cd84b0f | 3 tests | point (175), matrix (171), rectangle (745) |
| **Global constructors** | 3048065, 06244c7 | 3 globals tests | globals_swf6/7/8 (304 lines each) |
| **Math object** | c5804d0 | 1 test | math_min_max (101 lines) |
| **String methods** (Phases 1-4) | 3fb6a61, 17b33b9, 12e36a9, b4d13aa | 4 string tests | string_methods (285), string_methods_negative_args (240), string_methods_swfv5 (275), string_ops_swf6 (95) |
| **MovieClip Phase 1** | c616aeb | 2 MC tests | movieclip_default_state, movieclip_blend_mode_property |
| **Various bug fixes** | Multiple | ~10 tests | set_variable_scope, array_length, object_constructor, define_function2, etc. |

## Top Near-Passing Tests (best ROI to fix)

### Tier 1: 1-2 lines off

| Test | Match | Issue |
|------|-------|-------|
| `textfield_props_swf6` | 208/210 (99%) | 2 lines off — likely method or property enumeration edge case |
| `textfield_props_swf7` | 208/210 (99%) | Same as swf6 |
| `textfield_props_swf8` | 208/210 (99%) | Same |
| `string_methods` | 285/285 (100%) | **NOW PASSING** — fixed by commit b4d13aa (Unicode case mapping) |
| `xml_child_nodes_edge_cases` | 3/4 (75%) | 1 line off — likely toString or childNodes mutation |
| `swf4_function_calls` | 6/7 (86%) | 1 line off — SWF4 calling convention edge case |

### Tier 2: 3-5 lines off

| Test | Match | Issue |
|------|-------|-------|
| `edittext_width_height` | 97/103 (94%) | Width/height calculation edge cases |
| `get_variable_in_scope` | 27/29 (93%) | 2 lines — global/root path resolution |
| `swf7_case_sensitive` | 40/44 (91%) | Case-sensitive property lookup edge cases |
| `divide_swf4` | 95/107 (89%) | SWF4 division edge cases |
| `edittext_html_align_swf8` | 45/52 (87%) | HTML align attribute handling |
| `function_suppress_and_preload` | 24/28 (86%) | DefineFunction2 register preload flags |
| `xml_to_string` | 11/13 (85%) | XML serialization edge case |
| `object_prototypes` | 62/74 (84%) | Prototype chain traversal edge case |
| `arguments` | 106/127 (83%) | arguments.callee, arguments.caller, Array prototype |

### Tier 3: 80-82% match

| Test | Match | Issue |
|------|-------|-------|
| `local_to_global` | 40/49 (82%) | MovieClip.localToGlobal/globalToLocal |
| `edittext_html_align_swf7` | 42/52 (81%) | HTML align |
| `stage_object_children` | 67/83 (81%) | Child clip enumeration |
| `target_clip_removed` | 4/5 (80%) | tellTarget with removed clip |

## Crashes and Timeouts (8 tests)

| Test | Status | Notes |
|------|--------|-------|
| enumerate | segfault | actionEnumerate reads stack as string without type check (3/64) |
| function_base_clip_removed | segfault | **NEW** — needs investigation (1/25) |
| goto_methods | segfault | MovieClip.gotoAndStop/gotoAndPlay with extreme values (8/40) |
| init_object_order | segfault | **NEW** — likely related to setter invocation during InitObject (1/15) |
| register_and_init_order | segfault | **NEW** — DoInitAction + registerClass ordering (27/231) |
| register_class | segfault | **NEW** — Object.registerClass() crash |
| try_catch_finally | segfault | Exception handling (was timeout, now segfaults) (49/118) |
| timeout | timeout | setTimeout/clearTimeout not implemented |

## Plan Implementation Status

| Plan | Status | Tests Passing | Key Remaining |
|------|--------|--------------|---------------|
| MATH_PLAN | **COMPLETE** | 1/4 pass, 3 at 98.5% | ASnative(200,50), throwing valueOf |
| STRING_PLAN | **Phases 1-4 COMPLETE** | 4/4 method tests + string_ops_swf6 pass | String paths blocked by MC infra |
| GLOBALS_PLAN | **Phases 1-5 DONE** | globals_swf6/7/8 PASS | Phase 6 (Number.toString(radix)), Phase 7-8 (prototype methods) |
| XML_PLAN | **ALL PHASES COMPLETE** | 24/26 active tests pass | xml_to_string (11/13), xml_child_nodes_edge_cases (3/4) |
| TEXTFIELD_PLAN | **Phases 1-2 DONE** | 17/66 tests pass | Phase 3 (variable binding, width/height), Phase 5 (HTML) |
| MOVIECLIP_PLAN | **Phase 1 DONE** | 2 MC tests pass | Phase 2 (depth), Phase 3 (createEmptyMC) |
| PARSING_FUNCTIONS_PLAN | **Partially done** | 0/2 pass | parse_int blocked by `arguments` object |
| COLOR_OBJECT_PLAN | Not started | 0/4 | - |
| OOP_SUPER_EXTENDS_PLAN | Not started | 0/8 | - |
| REGISTERCLASS_PLAN | Not started | 0/7 | - |
| PROTOTYPE_OBJECT_PLAN | Not started | 0/12 | - |
| ENUMERATION_PLAN | Not started | 0/5 | Segfault fix, enum order, DontEnum flags |
| WITH_SCOPE_PLAN | Not started | 0/2 | DefineLocal scoping, MC identity, null skip |
| TIMER_PLAN | Not started | 0/3 | setInterval, setTimeout |
| STAGE_PLAN | Not started | 0/7 | Stage object, MC precision, child enum |
| SELECTION_PLAN | Not started | 0/2 | Focus tracking, replaceSel |
| OBJECT_WATCH_PLAN | Not started | 0/4 | watch/unwatch property callbacks |
| NATIVE_INTROSPECTION_PLAN | Not started | 0/2 | ASnative, ASSetPropFlags |
| TELLTARGET_PLAN | Not started | 0/3 | tellTarget scope |
| CLONE_DUPLICATE_PLAN | Not started | 0/5 | duplicateMovieClip, attachMovie |
| UNLOAD_PLAN | Not started | 0/3 | unloadMovie, onUnload |
| All others | Not started | - | - |

## Recommended Work Order

### High ROI (fix existing near-passing tests)
1. **Fix textfield_props_swf6/7/8** — 2 lines off each, 3 tests at 99%
2. **Fix xml_to_string** — 2 lines off, 85% passing
3. **Fix xml_child_nodes_edge_cases** — 1 line off
4. **Investigate new segfaults** — init_object_order, register_class, register_and_init_order, function_base_clip_removed

### Medium ROI (new feature phases)
5. **GLOBALS_PLAN Phase 6** — Number.prototype.toString(radix), improves primitive_type_globals (320/557)
6. **TEXTFIELD_PLAN Phase 3** — variable binding + width/height (edittext_width_height at 94%)
7. **TEXTFIELD_PLAN Phase 5** — HTML text (edittext_html_* tests, several at 81-87%)
8. **Fix `arguments` object** — unblocks parse_int (0/64) and improves arguments test (83%)

### Lower ROI (new features)
9. **COLOR_OBJECT_PLAN** — 4 tests, requires Color constructor + flash.geom.Transform
10. **MOVIECLIP_PLAN Phases 2-3** — depth methods, createEmptyMovieClip
11. **OOP_SUPER_EXTENDS_PLAN** — super keyword, 8 tests
12. **PROTOTYPE_OBJECT_PLAN** — addProperty, __resolve, property flags, 12 tests
