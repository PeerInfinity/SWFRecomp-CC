# Uncovered Small/Miscellaneous Tests Catalog
<!-- TESTS: define_local_with_paths, device_font_spacing, gettextextent, get_bytes_total, geturl, issue_2030, issue_2084, issue_3169, resolve_different_root, root_global_parent, root_onload, sandbox_type_remote, string_paths_keyevents, string_paths_timer, displacementmapfilter_mappoint_throw_error, localconnection -->

Last updated: 2026-03-14

## Status: 13/19 PASS — 0 actionable, 6 blocked

All actionable fixes have been implemented. The remaining 6 tests are blocked on larger features (loadMovie, BitmapData, LocalConnection, navigator infrastructure, throw-from-native).

---

### Results Summary

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| root_onload | 2 | **PASS** | |
| issue_3169 | 2 | **PASS** | |
| get_bytes_total | 4 | **PASS** | |
| gettextextent | 56 | **PASS** | |
| define_local_with_paths | 55 | **PASS** | |
| device_font_spacing | 91 | **PASS** | |
| movieclip_setmask | 14 | **PASS** | |
| selection_handlers | 27 | **PASS** | |
| define_local | 27 | **PASS** | |
| resolve_different_root | 2 | **PASS** | |
| root_global_parent | 6 | **PASS** | |
| string_paths_keyevents | 0 | **PASS** | Fixed: skip dead MCs in broadcastMessage dispatch |
| string_paths_timer | 0 | **PASS** | Fixed: deactivate timers on removed MCs in processTimers |
| issue_2030 | 4 | FAIL | Blocked: needs attachBitmap + BitmapData pixel buffer |
| displacementmapfilter_mappoint_throw_error | 13 | FAIL | Blocked: Point.toString() + Error throw from native ctor |
| sandbox_type_remote | 3 | FAIL | Blocked: loadMovie multi-SWF |
| issue_2084 | 16 | FAIL | Blocked: loadMovie + onLoad positioning |
| geturl | 7 | FAIL | Blocked: navigator/network trace infrastructure |
| localconnection | 579 | FAIL | Blocked: full LocalConnection protocol |

---

## Completed: Removed MC Listener/Timer Cleanup (2026-03-14)

### What was fixed

**Fix A — broadcastMessage**: In `builtin_broadcaster_broadcastMessage` (action.c), when iterating the `_listeners` array, added a check to skip MovieClip listeners with `depth == INT_MIN` (dead/removed). This prevents removed MCs from receiving Key/Mouse/Stage broadcast events.

**Fix B — processTimers**: In `processTimers` (action.c), before firing each timer, added a check for method-form timers whose target MC has `depth == INT_MIN`. Such timers are permanently deactivated (`active = 0`).

### Tests fixed
- `string_paths_keyevents` (0 expected lines) — PASS
- `string_paths_timer` (0 expected lines) — PASS

### Regression checks passed
- `set_interval` (27/27), `selection_handlers` (27/27), `mouse_listeners`, `timer_run_actions`, `unload` (52/52) — all still passing.

---

## Blocked Tests

### issue_2030 (4 lines) — Blocked on BITMAP_DATA_PLAN Phase 1

Creates an empty MC, creates a 10x10 BitmapData, calls `mc.attachBitmap(bitmap, 0)`, then checks `mc._width` and `mc._height`. Expects 10/10 from the attached bitmap dimensions. Requires:
1. BitmapData pixel buffer (BITMAP_DATA_PLAN Phase 1)
2. `MovieClip.attachBitmap()` method that sets MC dimensions from bitmap

### displacementmapfilter_mappoint_throw_error (13 lines) — Partially blocked

Two issues:
1. **Point.toString()** returns `[object Object]` instead of `(x=1, y=2)`. The Point class exists but its toString is not implemented. This is fixable independently.
2. **Error throw from native constructor** — the test expects `DisplacementMapFilter` constructor to throw an Error when `mapPoint` is invalid. Our try/catch infrastructure exists but native constructors don't throw. Requires throw-from-native support.

### sandbox_type_remote (3 lines) — Blocked on loadMovie

Line 1 passes (`localTrusted` for root SWF). Lines 2-3 need a loaded child SWF with `remote` sandbox type.

### issue_2084 (16 lines) — Blocked on loadMovie

Tests onLoad + attachMovie positioning in loaded child clips. Needs multi-SWF execution.

### geturl (7 lines) — Blocked on navigator infrastructure

Tests `getURL()` with POST parameters. Expected output traces the URL, target, method, and POST parameters. Would need a navigator/network logging hook in the test harness.

### localconnection (579 lines) — Low priority

Full LocalConnection protocol with domain management, send/receive, connect/close. Very complex, 579 expected lines. Consider adding to ignored_tests.txt if effort exceeds ROI.
