# Current Ruffle Test Status

Last updated: 2026-02-16, commit b815da5 (latest CI: 480bce0)

## Quick Summary

- **Pass rate**: 213/619 (34.4%), filtered 211/481 (43.9%) — up from 205/619 (33.1%) at last update
- **Main failure type**: output_mismatch (402), timeout (2), compile_fail (1), segfault (1)
- **Crash improvements**: Previous 7 segfaults reduced to 1 (goto_methods). try_catch_finally now runs (was segfault, now output_mismatch with only 11 diff lines after exception handler stack implementation)
- **New regression**: `movieclip_hittest_shapeflag` changed from output_mismatch (180/338) to compile_fail — needs investigation
- **Recent gains**: Date class implementation (+8 tests passing), try/catch/finally exception handler stack, 1592 fewer mismatched lines overall

## Major Features Implemented Since Last Update

| Feature | Commits | Impact | Key Tests |
|---------|---------|--------|-----------|
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

The `date` test (6335 lines) matches 5049 lines on CI (79.7%). Remaining 1286 diffs fall into:

1. **Timezone mismatch (~1240 diffs)**: CI runs in UTC, expected output was generated with Nepal (+5:45). All toString and local getters (Hours, Date, Day) differ. Fix: set `TZ=Asia/Kathmandu` in CI environment or implement timezone mocking.
2. **Extreme date edge cases (~46 diffs)**: Unfixable — Flash-specific int32 overflow UB for Infinity/NaN setters, internally inconsistent expected output for dates near -8.64e15.

## Top Near-Passing Tests (best ROI to fix)

### Tier 1: 1-2 lines off

| Test | Match | Issue |
|------|-------|-------|
| `textfield_props_swf6` | 208/210 (99%) | 2 lines off — likely method or property enumeration edge case |
| `textfield_props_swf7` | 208/210 (99%) | Same as swf6 |
| `textfield_props_swf8` | 208/210 (99%) | Same |
| `xml_child_nodes_edge_cases` | 3/4 (75%) | 1 line off — likely toString or childNodes mutation |
| `swf4_function_calls` | 6/7 (86%) | 1 line off — SWF4 calling convention edge case |

### Tier 2: 3-15 lines off

| Test | Match | Issue |
|------|-------|-------|
| `try_catch_finally` | 107/118 (91%) | **NEW** — typed catch block matching (catches "other" instead of typed) |
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
| `date` | 5049/6335 (80%) | Timezone mismatch (CI=UTC, expected=Nepal +5:45) |
| `target_clip_removed` | 4/5 (80%) | tellTarget with removed clip |

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
| DATE_PLAN | **COMPLETE** | 8+ tests passing | Timezone mocking for CI, ~46 unfixable extreme-date diffs |
| TRY_CATCH_PLAN | **Phase 1 DONE** | 0 pass (91% match) | Typed catch block matching (String/Object/etc.) |
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
1. **Fix `date` test timezone** — set TZ=Asia/Kathmandu in CI, could flip 80% → ~99% (1 test)
2. **Fix `try_catch_finally` typed catch** — 11 lines off, add instanceof-style type matching for catch blocks
3. **Fix textfield_props_swf6/7/8** — 2 lines off each, 3 tests at 99%
4. **Fix xml_to_string** — 2 lines off, 85% passing
5. **Fix xml_child_nodes_edge_cases** — 1 line off
6. **Investigate movieclip_hittest_shapeflag compile_fail** — regression from previous run

### Medium ROI (new feature phases)
7. **GLOBALS_PLAN Phase 6** — Number.prototype.toString(radix), improves primitive_type_globals (320/557)
8. **TEXTFIELD_PLAN Phase 3** — variable binding + width/height (edittext_width_height at 94%)
9. **TEXTFIELD_PLAN Phase 5** — HTML text (edittext_html_* tests, several at 81-87%)
10. **Fix `arguments` object** — unblocks parse_int (0/64) and improves arguments test (83%)

### Lower ROI (new features)
11. **COLOR_OBJECT_PLAN** — 4 tests, requires Color constructor + flash.geom.Transform
12. **MOVIECLIP_PLAN Phases 2-3** — depth methods, createEmptyMovieClip
13. **OOP_SUPER_EXTENDS_PLAN** — super keyword, 8 tests
14. **PROTOTYPE_OBJECT_PLAN** — addProperty, __resolve, property flags, 12 tests
