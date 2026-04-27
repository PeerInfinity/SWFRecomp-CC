# Uncovered Small/Miscellaneous Tests Catalog
<!-- TESTS: define_local_with_paths, device_font_spacing, gettextextent, get_bytes_total, geturl, issue_2030, issue_2084, issue_3169, resolve_different_root, root_global_parent, root_onload, sandbox_type_remote, string_paths_keyevents, string_paths_timer, displacementmapfilter_mappoint_throw_error, localconnection -->

Last updated: 2026-04-27

## Status: 16/19 PASS — COMPLETE (0 actionable remaining)

All actionable fixes have been implemented (moved to `complete/` 2026-04-27, originally landed by 2026-04-07). The remaining 3 tests (`geturl`, `sandbox_type_remote`, `localconnection`) are infrastructure-blocked — they live in `ignored_tests.txt` and don't affect the filtered pass rate. `localconnection` has its own plan (`blocked/LOCALCONNECTION_PLAN.md`) tracking the child-SWF-fixture work needed to reach Phase 5 there.

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
| issue_2030 | 4 | **PASS** | Fixed post-plan: attachBitmap + BitmapData pixel buffer implemented |
| displacementmapfilter_mappoint_throw_error | 13 | **PASS** | Fixed post-plan: Point.toString() + valueOf throw propagation |
| issue_2084 | 16 | **PASS** | Fixed post-plan: loadMovie + onLoad + attachMovie positioning |
| geturl | 7 | FAIL (0/7) | Blocked: navigator trace infrastructure + POST variable enumeration |
| sandbox_type_remote | 3 | FAIL (1/3) | Blocked: child SWF loading from HTTP URLs |
| localconnection | 579 | FAIL (433/579) | Blocked: child SWF communication — has own plan (LOCALCONNECTION_PLAN) |

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

## Post-Plan Fixes (resolved since 2026-03-14)

### issue_2030 (4 lines) — NOW PASS
BitmapData pixel buffer and `mc.attachBitmap()` were implemented as part of the BITMAPDATA_RENDERING_PLAN. The test now passes with 4/4 lines.

### displacementmapfilter_mappoint_throw_error (13 lines) — NOW PASS
Point.toString() was implemented, and valueOf throw propagation from native constructors was added (local setjmp exception handlers around tsArgToDouble_ctx coercion). Has its own completed plan (DISPLACEMENTMAPFILTER_PLAN). Now passes with 13/13 lines.

### issue_2084 (16 lines) — NOW PASS
loadMovie multi-SWF infrastructure, onLoad callbacks, and attachMovie positioning in loaded child clips were all implemented. Now passes with 16/16 lines.

---

## Remaining Blocked Tests

### geturl (7 lines) — Blocked on navigator trace infrastructure

The test has `log_fetch = true` in test.toml, which tells Ruffle to log navigation events. Expected output:
```
Navigator::navigate_to_url:
  URL: http://www.example.com
  Target: _blank
  Method: POST
  Param: value2=2
  Param: value1=string
  Param: $version=LNX 32,0,0,0
```

Would require:
1. `log_fetch` flag parsed from test.toml and passed to runtime (not currently supported by verify_output.py)
2. Navigator trace logging in `actionGetURL2` for browser navigation targets
3. POST variable enumeration — when `send_vars_method=POST`, all scope variables are sent as params

The test is in `ignored_tests.txt`. Effort outweighs the 7-line gain.

### sandbox_type_remote (3 lines) — Blocked on child SWF HTTP loading

Line 1 passes (`localWithNetwork` for root SWF). Lines 2-3 require child SWFs loaded from `http://localhost:8000/` with different sandbox types. No child SWFs exist in the test directory — they would need to be served from a test HTTP server. Fundamentally blocked by same infrastructure gap as other multi-SWF-from-URL tests.

### localconnection (433/579 lines) — Has own dedicated plan

433/579 lines match (74.8%). Remaining 146 lines blocked on child SWF cross-movie communication (avm1child/avm2child). See `incomplete/LOCALCONNECTION_PLAN.md` for full details. This test is in `ignored_tests.txt`.

---

## Investigation Notes (2026-04-07 update)

Reviewed all 6 previously-blocked tests against current codebase state:
- 3 of 6 blockers were resolved by work done on other plans (BITMAPDATA_RENDERING, DISPLACEMENTMAPFILTER, LOADMOVIE)
- The remaining 3 blockers are infrastructure-level gaps (HTTP child SWF loading, navigator trace, cross-movie LC) that are unlikely to be resolved without significant new infrastructure
- All 3 remaining failing tests are already in `ignored_tests.txt`
- No alternative approaches were identified that could bypass the blockers
