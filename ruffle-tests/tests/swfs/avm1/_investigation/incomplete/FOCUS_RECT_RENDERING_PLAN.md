# Focus Rect Rendering Plan
<!-- TESTS: focusrect_focuslost, focusrect_mouse_swf8, focusrect_mouse_swf9, focusrect_swf5, focusrect_swf6 -->

<!-- PLAN_META
id: FOCUS_RECT_RENDERING
status: mostly_complete
phases:
  - id: 1
    name: "Investigate expected appearance from test images"
    status: complete
  - id: 2
    name: "Implement focus rect drawing function"
    status: complete
  - id: 3
    name: "Integrate into render pass"
    status: complete
  - id: 4
    name: "Handle SWF version differences"
    status: complete
  - id: 5
    name: "Fix headless trace output pollution"
    status: complete
  - id: 6
    name: "Verify headless image results via CI re-run"
    status: pending
dependencies: []
blockers:
  - "Headless CI re-run needed to confirm image test status"
-->

Last updated: 2026-03-28

## Status: MOSTLY COMPLETE — Awaiting CI re-run for headless image confirmation

### Summary

Focus rect rendering IS fully implemented and integrated. All 8 trace tests pass (including the 3 focusrect_property tests with 1237 lines each). The rendering code, focus state tracking, and SWF version-dependent behavior are all in place.

A debug `printf("[FR_CHECK]...")` in `actionGetFocusRectInfo` was polluting headless trace output, causing output_mismatch in headless mode. **This has been fixed** (removed in this session).

### What's Implemented

1. **Focus rect drawing function** (`tag.c:1996-2003` and `tag.c:2439-2446`): Draws 4 yellow (1,1,0) rectangles as a 3-pixel border inside the focused element's world AABB in twips. Present in both `tagRerenderFrame` (HEADLESS_GRAPHICS) and `tagShowFrame` (NO_GRAPHICS).

2. **Focus rect info calculation** (`action.c:50331-50382`): `actionGetFocusRectInfo()` walks the `focusrect` property chain from the focused MC up through parents to root. Computes world-space AABB via `getConcatMatrixForMC()` with 4-corner transform. Returns bounds in twips.

3. **Highlight state tracking** (`action.c:50285-50327`): Three states: INACTIVE(0), ACTIVE_HIDDEN(1), ACTIVE_VISIBLE(2). Tab activates, mouse events reset (version-dependent: SWF<9 all mouse events reset, SWF>=9 only left-down resets).

4. **Per-object _focusrect property** (`action.c:31631-31677`): SetMember handler for MOVIECLIP objects. Stage/root uses stage setter (null/undefined = no-op). Per-object: null = -1.0 sentinel, false = 0.0, true = 1.0. Parent chain inheritance with root fallback.

5. **Headless capture integration** (`swf_headless.c:1142-1158`): `tagRerenderFrame()` is called AFTER input events are delivered, so captures reflect post-event focus state.

### Trace Test Results (ALL PASS)

| Test | Lines | Status |
|------|-------|--------|
| focusrect_focuslost | 4/4 | PASS |
| focusrect_mouse_swf8 | 0/0 | PASS |
| focusrect_mouse_swf9 | 0/0 | PASS |
| focusrect_property_swf5 | 1237/1237 | PASS |
| focusrect_property_swf6 | 1237/1237 | PASS |
| focusrect_property_swf7 | 1237/1237 | PASS |
| focusrect_swf5 | 6/6 | PASS |
| focusrect_swf6 | 42/42 | PASS |

### Image Test Status (from stale March 18 headless CI)

The last headless CI run (results_headless.json, sha fe5f3072, March 18) showed:

| Test | Image Status | Trace Status |
|------|-------------|-------------|
| focusrect_focuslost | 1/1 PASS | PASS |
| focusrect_mouse_swf8 | 8/8 PASS | output_mismatch (3 actual vs 0 expected) |
| focusrect_mouse_swf9 | 8/8 PASS | output_mismatch (7 actual vs 0 expected) |
| focusrect_swf5 | 12/12 PASS (0-diff) | output_mismatch (28 actual vs 6 expected) |
| focusrect_swf6 | 9/12 PASS, 3 FAIL | output_mismatch (24 actual vs 42 expected) |

The 3 failing images (output.03a, 04a, 05a) in focusrect_swf6 showed focus rect drawn on wrong clip (204-744 outlier pixels, max_diff=204). However:
- These results are **10 days stale** (March 18)
- The `[FR_CHECK]` debug printf was causing extra trace lines, which may have disrupted event processing or output matching
- Local image files in `_image-test-output/` show 0-diff for ALL images (from a separate local run)
- Code analysis of the focus rect logic shows correct behavior for all stages

### What Was Fixed This Session

1. **Removed debug printf** (`action.c:50348-50352`): The `printf("[FR_CHECK] fr=%g root_fr=%g focused_fr=%g hl=%d\n", ...)` in `actionGetFocusRectInfo()` was outputting to trace in headless mode. This caused headless trace output mismatches (extra lines) for focusrect_mouse_swf8/swf9 (which expect 0 lines) and focusrect_swf5/swf6 (which got extra lines mixed in).

### Remaining Work

1. **CI headless re-run needed**: Run the headless CI workflow to get fresh image comparison results. The March 18 results are stale and the debug printf fix likely resolves the trace mismatches.

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| Focus rect drawing (headless) | `tag.c` | 1996-2003 |
| Focus rect drawing (NO_GRAPHICS) | `tag.c` | 2439-2446 |
| Focus rect info + bounds | `action.c` | 50331-50382 |
| Highlight state tracking | `action.c` | 50283-50327 |
| _focusrect property setter (SetMember) | `action.c` | 31631-31677 |
| _focusrect property setter (SetVariable) | `action.c` | 27075-27094 |
| _focusrect property setter (SetProperty) | `action.c` | 28045, 37087 |
| MovieClip.focusrect field | `action.h` | 36 |
| FocusRectInfo struct | `action.h` | 567-570 |
| Headless capture re-render | `swf_headless.c` | 1142-1158 |
| swf.c stub (graphics mode only) | `swf.c` | 255-259 |
