# Ruffle Test Results (Filtered)

**Date**: 2026-03-16 18:30 UTC

**Git SHA**: `fafa62eabb`

**Run Duration**: 6m 14s

**Filtered**: 0 tests ignored out of 23 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **11** (47.8%) |
| Failing | 12 |
| Total expected lines | 311 |
| Matching lines | 113 (36.3%) |
| Mismatched lines | 198 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 11 | 91.7% |
| Runtime Error | 1 | 8.3% |

## Passing Tests

**11 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `callee` | 2 | 15.3s |  |
| 2 | `depth` | 6 | 15.4s |  |
| 3 | `externalinterface` | 4 | 15.9s |  |
| 4 | `label` | 4 | 16.5s |  |
| 5 | `levels` | 9 | 16.6s |  |
| 6 | `lookup` | 3 | 16.5s |  |
| 7 | `mouse-transparency` | 1 | 16.2s |  |
| 8 | `operations` | 13 | 16.7s |  |
| 9 | `rollover` | 4 | 17.9s |  |
| 10 | `super` | 11 | 15.6s |  |
| 11 | `text-bind` | 0 | 16.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `scope` | 92.9% | 13 | 14 | 1 |  |
| 2 | `nativeinheritance` | 83.3% | 5 | 6 | 1 |  |
| 3 | `loadevent` | 77.8% | 7 | 9 | 2 |  |
| 4 | `settimeout` | 64.7% | 11 | 17 | 6 |  |
| 5 | `setinterval` | 55.0% | 11 | 20 | 9 |  |
| 6 | `hitarea` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `watch` | exit code -6 | 17.7s | [43](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) |

## Timeouts

No timeouts.

## All Output Mismatches

**11 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `scope` | 92.9% | 13/14 | 14 | 14 |  |
| 2 | `nativeinheritance` | 83.3% | 5/6 | 6 | 6 |  |
| 3 | `loadevent` | 77.8% | 7/9 | 9 | 9 |  |
| 4 | `settimeout` | 64.7% | 11/17 | 12 | 17 |  |
| 5 | `setinterval` | 55.0% | 11/20 | 12 | 20 |  |
| 6 | `hitarea` | 50.0% | 2/4 | 3 | 4 |  |
| 7 | `target` | 22.7% | 5/22 | 22 | 18 |  |
| 8 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 9 | `array` | 0.0% | 0/7 | 7 | 7 |  |
| 10 | `filters` | 0.0% | 0/149 | 85 | 149 |  |
| 11 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [add2.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/add2.md) | 0 | 0 | 0 |
| 2 | [ARRAY_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ARRAY_METHODS_PLAN.md) | 0 | 0 | 0 |
| 3 | [ASBROADCASTER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASBROADCASTER_PLAN.md) | 0 | 0 | 0 |
| 4 | [ASNATIVE_ASNEW_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ASNATIVE_ASNEW_PLAN.md) | 0 | 0 | 0 |
| 5 | [BITMAP_DATA_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/BITMAP_DATA_PLAN.md) | 0 | 0 | 0 |
| 6 | [BUTTON_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/BUTTON_PLAN.md) | 0 | 0 | 0 |
| 7 | [CALL_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CALL_SEMANTICS_PLAN.md) | 0 | 0 | 0 |
| 8 | [CLONE_DUPLICATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLONE_DUPLICATE_PLAN.md) | 0 | 0 | 0 |
| 9 | [CLOSURE_CAPTURE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CLOSURE_CAPTURE_PLAN.md) | 0 | 0 | 0 |
| 10 | [COLOR_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/COLOR_OBJECT_PLAN.md) | 0 | 0 | 0 |
| 11 | [CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CROSS_MOVIE_EXPORT_ISOLATION_PLAN.md) | 0 | 0 | 0 |
| 12 | [CUSTOM_CLIP_METHODS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/CUSTOM_CLIP_METHODS_PLAN.md) | 0 | 0 | 0 |
| 13 | [DATE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DATE_PLAN.md) | 0 | 0 | 0 |
| 14 | [DEFAULT_NAMES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DEFAULT_NAMES_PLAN.md) | 0 | 0 | 0 |
| 15 | [DRAG_DROP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/DRAG_DROP_PLAN.md) | 0 | 0 | 0 |
| 16 | [ENTERFRAME_DISPATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENTERFRAME_DISPATCH_PLAN.md) | 0 | 0 | 0 |
| 17 | [ENUMERATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ENUMERATION_PLAN.md) | 0 | 0 | 0 |
| 18 | [EXTERNAL_INTERFACE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/EXTERNAL_INTERFACE_PLAN.md) | 0 | 0 | 0 |
| 19 | [FOCUS_FOCUSRECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_FOCUSRECT_PLAN.md) | 0 | 0 | 0 |
| 20 | [FOCUS_SYSTEM_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FOCUS_SYSTEM_PLAN.md) | 0 | 0 | 0 |
| 21 | [FRAME_NAVIGATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FRAME_NAVIGATION_PLAN.md) | 0 | 0 | 0 |
| 22 | [FUNCTION_EDGE_CASES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/FUNCTION_EDGE_CASES_PLAN.md) | 0 | 0 | 0 |
| 23 | [GEOMETRY_CLASSES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GEOMETRY_CLASSES_PLAN.md) | 0 | 0 | 0 |
| 24 | [GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/GETTEXTSNAPSHOT_CONSTRUCTOR_PLAN.md) | 0 | 0 | 0 |
| 25 | [GLOBALS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/GLOBALS_PLAN.md) | 0 | 0 | 0 |
| 26 | [HIT_TESTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/HIT_TESTING_PLAN.md) | 0 | 0 | 0 |
| 27 | [IGNORED_INFRASTRUCTURE_TESTS.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/IGNORED_INFRASTRUCTURE_TESTS.md) | 0 | 0 | 0 |
| 28 | [infinite_recursion_function.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/infinite_recursion_function.md) | 0 | 0 | 0 |
| 29 | [INPUT_DEAD_KEYS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/INPUT_DEAD_KEYS_PLAN.md) | 0 | 0 | 0 |
| 30 | [issue_768.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/issue_768.md) | 0 | 0 | 0 |
| 31 | [LOADMOVIE_MULTI_SWF_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_MULTI_SWF_PLAN.md) | 0 | 0 | 0 |
| 32 | [LOADMOVIE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADMOVIE_PLAN.md) | 0 | 0 | 0 |
| 33 | [LOADMOVIE_REMAINING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/LOADMOVIE_REMAINING_PLAN.md) | 0 | 0 | 0 |
| 34 | [LOADVARIABLES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOADVARIABLES_PLAN.md) | 0 | 0 | 0 |
| 35 | [LOCKROOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/LOCKROOT_PLAN.md) | 0 | 0 | 0 |
| 36 | [MATH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MATH_PLAN.md) | 0 | 0 | 0 |
| 37 | [MORPH_INTERPOLATION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MORPH_INTERPOLATION_PLAN.md) | 0 | 0 | 0 |
| 38 | [MOUSE_EVENTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOUSE_EVENTS_PLAN.md) | 0 | 0 | 0 |
| 39 | [MOVIECLIP_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIP_PLAN.md) | 0 | 0 | 0 |
| 40 | [MOVIECLIPLOADER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/MOVIECLIPLOADER_PLAN.md) | 0 | 0 | 0 |
| 41 | [NATIVE_INTROSPECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/NATIVE_INTROSPECTION_PLAN.md) | 0 | 0 | 0 |
| 42 | [object_string_coerce.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/object_string_coerce.md) | 0 | 0 | 0 |
| 43 | [OBJECT_WATCH_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OBJECT_WATCH_PLAN.md) | 1 | 0 | 1 |
| 44 | [OOP_SUPER_EXTENDS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/OOP_SUPER_EXTENDS_PLAN.md) | 0 | 0 | 0 |
| 45 | [PARSING_FUNCTIONS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PARSING_FUNCTIONS_PLAN.md) | 0 | 0 | 0 |
| 46 | [PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PRIMITIVE_COERCION_ADDPROPERTY_PLAN.md) | 0 | 0 | 0 |
| 47 | [PROTOTYPE_OBJECT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/PROTOTYPE_OBJECT_PLAN.md) | 0 | 0 | 0 |
| 48 | [REGISTERCLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/REGISTERCLASS_PLAN.md) | 0 | 0 | 0 |
| 49 | [ROOT_REPLACEMENT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/ROOT_REPLACEMENT_PLAN.md) | 0 | 0 | 0 |
| 50 | [SCRIPT_HALTING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SCRIPT_HALTING_PLAN.md) | 0 | 0 | 0 |
| 51 | [SELECTION_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SELECTION_PLAN.md) | 0 | 0 | 0 |
| 52 | [SOUND_CLASS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SOUND_CLASS_PLAN.md) | 0 | 0 | 0 |
| 53 | [STAGE_FRAME_PROPS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_FRAME_PROPS_PLAN.md) | 0 | 0 | 0 |
| 54 | [STAGE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STAGE_PLAN.md) | 0 | 0 | 0 |
| 55 | [string_coercion.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/string_coercion.md) | 0 | 0 | 0 |
| 56 | [STRING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STRING_PLAN.md) | 0 | 0 | 0 |
| 57 | [STYLESHEET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/STYLESHEET_PLAN.md) | 0 | 0 | 0 |
| 58 | [SWF_VERSION_SEMANTICS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/SWF_VERSION_SEMANTICS_PLAN.md) | 0 | 0 | 0 |
| 59 | [TAB_ORDERING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PLAN.md) | 0 | 0 | 0 |
| 60 | [TAB_ORDERING_PROPERTIES_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TAB_ORDERING_PROPERTIES_PLAN.md) | 0 | 0 | 0 |
| 61 | [TELLTARGET_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TELLTARGET_PLAN.md) | 0 | 0 | 0 |
| 62 | [TEXTFIELD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTFIELD_PLAN.md) | 0 | 0 | 0 |
| 63 | [TEXTSNAPSHOT_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TEXTSNAPSHOT_PLAN.md) | 0 | 0 | 0 |
| 64 | [THIS_BINDING_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/THIS_BINDING_PLAN.md) | 0 | 0 | 0 |
| 65 | [this_swf7.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/this_swf7.md) | 0 | 0 | 0 |
| 66 | [TIMER_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TIMER_PLAN.md) | 0 | 0 | 0 |
| 67 | [TRY_CATCH_FINALLY_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/TRY_CATCH_FINALLY_PLAN.md) | 0 | 0 | 0 |
| 68 | [TYPE_COERCION_ADVANCED_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/TYPE_COERCION_ADVANCED_PLAN.md) | 0 | 0 | 0 |
| 69 | [UNCOVERED_SMALL_TESTS_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/blocked/UNCOVERED_SMALL_TESTS_PLAN.md) | 0 | 0 | 0 |
| 70 | [UNLOAD_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/UNLOAD_PLAN.md) | 0 | 0 | 0 |
| 71 | [WITH_SCOPE_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/WITH_SCOPE_PLAN.md) | 0 | 0 | 0 |
| 72 | [XML_PLAN.md](ruffle-tests/tests/swfs/avm1/_investigation/complete/XML_PLAN.md) | 0 | 0 | 0 |
| | *(tests not in any document)* | 22 | 11 | 11 |
