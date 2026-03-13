# Uncovered Small/Miscellaneous Tests Catalog
<!-- TESTS: define_local_with_paths, device_font_spacing, gettextextent, get_bytes_total, geturl, issue_2030, issue_2084, issue_3169, resolve_different_root, root_global_parent, root_onload, sandbox_type_remote, string_paths_keyevents, string_paths_timer, displacementmapfilter_mappoint_throw_error, localconnection -->

Last updated: 2026-03-13

## Status: BLOCKED — catalog of individual uncovered tests, grouped by blocker

### Overview

This document catalogs 16 failing tests that don't fit into any existing plan's scope. Each is small (2-91 expected lines) and either blocked by a larger feature or a quick standalone fix. Tests are grouped by the root cause/blocker.

---

### Group A: Could Be Fixed Independently (best ROI)

| Test | Lines | Current | Issue | Effort |
|------|-------|---------|-------|--------|
| root_onload | 2 | **PASS** ✅ | Was compile_fail, now passes | DONE |
| issue_3169 | 2 | **PASS** ✅ | Was 0/2, now passes in CI | DONE |
| get_bytes_total | 4 | **PASS** ✅ | getBytesLoaded/getBytesTotal implemented | DONE |
| gettextextent | 56 | **PASS** ✅ | TextFormat.getTextExtent() implemented | DONE |
| define_local_with_paths | 55 | **PASS** ✅ | Was 53/54, now fully passing | DONE |
| sandbox_type_remote | 3 | 1/3 | Lines 2-3 need loadMovie infra (multi-SWF) | BLOCKED |
| device_font_spacing | 91 | **91/91 PASS** ✅ | Fixed: conditional pixel rounding based on embedFonts | DONE |

#### define_local_with_paths (55 lines) — 53/54 PASS

DefineLocal (ActionDefineLocal, `var x`) with slash-path syntax:
- `var /:abc = 'ABC'` → sets variable `abc` on `_root` (slash `/` = root, colon `:` = variable separator)
- `var /ruffle/:def = 'DEF'` → sets variable `def` on `_root.ruffle` MC
- Uses Flash's SWF4 slash-path variable convention

**Fixed** (commit c4b7c440):
- DefineLocal slash-path: converts `/ruffle/` → `_root.ruffle` dot-path for GetVariable resolution
- Stores literal slash-path key on MC's dynamic_props for GetMember access
- Syncs var_array changes to dynamic_props at top-level
- GetVariable colon-path: object fallback for non-MC targets (e.g., `/ruffle/:def` where `ruffle` is an Object)

**Remaining (line 54)**: `this['/:pqr']` inside a function — requires DefineLocal inside a function with slash-path key to store on root MC in a way that `GetMember(this, '/:pqr')` can find. Complex scoping interaction between function scope and slash-path MC property storage. BLOCKED.

#### issue_3169 (2 lines)

addProperty setter not invoked when setting `this.foo = val` inside a function where `foo` has an addProperty setter on the prototype chain.

**Root cause**: `actionSetVariable` or the SetMember path doesn't check addProperty setters when setting via `this.foo` in certain scopes.

**Fix**: Ensure SetMember on `this` walks the prototype chain for addProperty setters before storing as a plain property.

#### get_bytes_total (4 lines)

Root MC `getBytesLoaded()` and `getBytesTotal()` return `undefined` instead of the SWF file size.

**Fix**: Return a plausible value (e.g., the compiled binary size or a fixed value). For child MCs, currently returns 0 which is also wrong — should return the character's data size.

#### sandbox_type_remote (3 lines)

`System.security.sandboxType` property needs to be registered. Expected value: `"localTrusted"` for local SWFs.

**Fix**: Add `sandboxType` property to the `System.security` object (currently a stub). Return `"localTrusted"`.

#### gettextextent (56 lines)

`TextFormat.getTextExtent(text)` returns an object with `{ascent, descent, width, height, textFieldHeight, textFieldWidth}`. Uses font metrics to compute text dimensions without needing a TextField.

**Fix**: Implement `getTextExtent` on `TextFormat.prototype` using the existing font metrics pipeline (`ng_compute_text_width`, `ng_compute_text_height`).

**Related to**: TEXTFIELD_PLAN (shares font metrics infrastructure)

#### device_font_spacing (91 lines) — RESOLVED

~~Tests text formatting with device fonts and letter spacing.~~ **91/91 PASS.** Fixed by making pixel rounding conditional on `embedFonts` property (commit 0f010c5b).

---

### Group B: Blocked by LoadMovie / Multi-SWF Infrastructure

| Test | Lines | Current | Blocker |
|------|-------|---------|---------|
| resolve_different_root | 2 | **2/2 PASS** ✅ | Was segfault, now fixed |
| root_global_parent | 6 | **6/6 PASS** ✅ | Fixed: _global as MOVIECLIP builtin in GetMember |
| issue_2084 | 16 | 0/16 | onLoad + attachMovie positioning in child clips |
| issue_2030 | 4 | 0/4 | MC _width/_height from shape content (needs graphics bounds) |

These tests involve multi-SWF loading (`loadMovie`), display list bounds from shape content, or parent chain traversal across loaded movies. All blocked by LOADMOVIE_PLAN infrastructure.

---

### Group C: Other Infrastructure Blockers

| Test | Lines | Current | Blocker |
|------|-------|---------|---------|
| string_paths_keyevents | 0 | 0/0 (empty) | 0 expected output lines — test produces no trace output even with input events |
| string_paths_timer | ? | segfault | Timer + string path interaction causes crash; needs debugging |
| localconnection | 579 | ~74/579 (13%) | Full LocalConnection protocol (send/receive/domain management) |
| displacementmapfilter_mappoint_throw_error | 13 | 0/13 | Error/throw from DisplacementMapFilter constructor |
| geturl | 7 | 0/7 | getURL with POST parameters — needs network trace infrastructure |

#### string_paths_keyevents (0 lines expected)

Empty expected output — keyboard input simulation is now implemented, but this test has 0 expected lines so it produces no trace output regardless. Effectively a no-op test.

#### string_paths_timer (segfault)

Timer callback with string-based target paths causes a segfault. Needs investigation:
- Could be null pointer in timer callback when target MC is removed
- Could be string path resolution during timer dispatch

**Priority**: MEDIUM — segfaults should be investigated.

#### localconnection (579 lines, 13%)

Full `LocalConnection` class implementation with domain management, send/receive across movie clips. Very complex protocol — 579 expected lines.

**Decision**: LOW PRIORITY. Consider adding to ignored_tests.txt if effort exceeds ROI.

#### displacementmapfilter_mappoint_throw_error (13 lines)

Tests that `DisplacementMapFilter` throws an Error when `mapPoint` is invalid. Needs Error throw mechanism from native constructor validation.

#### geturl (7 lines)

Tests `getURL()` with POST parameters and traces the request. Needs network request tracing infrastructure (log_fetch pattern).

---

### Group D: Small Fixes (potentially quick wins)

| Test | Lines | Current | Issue | Effort |
|------|-------|---------|-------|--------|
| movieclip_setmask | 14 | **14/14 PASS** ✅ | Fixed: path resolution, dynamic_props lookup, type handling | DONE |
| selection_handlers | 27 | **27/27 PASS** ✅ | Was 21/27, now fully passing | DONE |
| define_local | 27 | **27/27 PASS** ✅ | Confirmed passing | DONE |

#### movieclip_setmask (14 lines) — RESOLVED

~~setMask returns false for certain arg types.~~ **14/14 PASS.** Fixed (commit c4b7c440):
- OBJECT/FUNCTION/ARRAY args return false immediately (no valueOf coercion)
- Non-string types converted via `convertString` for path lookup
- Added `_root`/`_level0`/`_parent` special segment handling in `getMovieClipByTarget`
- Added dynamic_props lookup fallback for variable-based MC references (e.g., number `1234` stored as variable pointing to MC)

#### selection_handlers (27 lines)

Focus-change rollOver/rollOut dispatch is incomplete. Lines 1-21 pass (Selection.setFocus, onSetFocus, onKillFocus, first pair of button rollOver/rollOut). Lines 22-27 fail: button's second rollOver/rollOut pair is missing, and clip rollOver/rollOut appears in wrong position.

**Root cause**: The deferred roll event queue may not be dispatching events for buttons on the second cycle, or the roll state machine isn't tracking button hover state correctly across focus changes.

**Related to**: MOUSE_EVENTS_ADVANCED_PLAN (roll dispatch). Fixing this requires understanding the roll dispatch ordering during programmatic focus changes.

---

### Priority Summary

| Priority | Test | Status | Lines Gained |
|----------|------|--------|-------------|
| **DONE** | root_onload, issue_3169, get_bytes_total, gettextextent, device_font_spacing, movieclip_setmask, define_local_with_paths, selection_handlers, define_local, resolve_different_root, root_global_parent | PASS | ~300 |
| **Medium** | selection_handlers | 21/27 (roll dispatch) | 6 |
| **Blocked (loadMovie)** | sandbox_type_remote, resolve_different_root, root_global_parent, issue_2030, issue_2084 | blocked by loadMovie | 0 |
| **Investigate** | string_paths_timer (segfault) | ? | ? |
| **Low priority** | localconnection, geturl, string_paths_keyevents, displacementmapfilter_mappoint_throw_error | complex/blocked | 0 |
