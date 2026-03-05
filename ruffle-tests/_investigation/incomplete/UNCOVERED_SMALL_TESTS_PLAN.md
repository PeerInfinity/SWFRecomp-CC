# Uncovered Small/Miscellaneous Tests Catalog
<!-- TESTS: define_local_with_paths, device_font_spacing, gettextextent, get_bytes_total, geturl, issue_2030, issue_2084, issue_3169, resolve_different_root, root_global_parent, root_onload, sandbox_type_remote, string_paths_keyevents, string_paths_timer, displacementmapfilter_mappoint_throw_error, localconnection -->

Last updated: 2026-03-04

## Status: BLOCKED — catalog of individual uncovered tests, grouped by blocker

### Overview

This document catalogs 16 failing tests that don't fit into any existing plan's scope. Each is small (2-91 expected lines) and either blocked by a larger feature or a quick standalone fix. Tests are grouped by the root cause/blocker.

---

### Group A: Could Be Fixed Independently (best ROI)

| Test | Lines | Current | Issue | Effort |
|------|-------|---------|-------|--------|
| root_onload | 2 | **PASS** ✅ | Was compile_fail, now passes | DONE |
| define_local_with_paths | 55 | ~21/55 (38%) | Slash-path `var /:abc` DefineLocal to root variables | ~20 lines |
| issue_3169 | 2 | 0/2 | addProperty setter not invoked during `this.foo = val` inside function | ~10 lines |
| get_bytes_total | 4 | 0/4 | getBytesLoaded/getBytesTotal return undefined on root MC | ~10 lines |
| sandbox_type_remote | 3 | 1/3 | flash.system.Security.sandboxType property missing | ~5 lines |
| gettextextent | 56 | ~31/56 (55%) | TextFormat.getTextExtent() method not implemented | ~40 lines |
| device_font_spacing | 91 | ~46/91 (51%) | Text metrics accuracy with device fonts + letter spacing | TEXTFIELD blocker |

#### define_local_with_paths (55 lines)

DefineLocal (ActionDefineLocal, `var x`) with slash-path syntax:
- `var /:abc = 'ABC'` → sets variable `abc` on `_root` (slash `/` = root, colon `:` = variable separator)
- `var /ruffle/:def = 'DEF'` → sets variable `def` on `_root.ruffle` MC
- Uses Flash's SWF4 slash-path variable convention

**Root cause**: `actionDeclareLocal` doesn't handle slash-path variable names. When the variable name contains `/` or `:`, it should resolve the path and set the variable on the target MC.

**Fix**: In `actionDeclareLocal`, check if variable name contains `:` (slash-path separator). If so, parse the path portion before `:` as a MC path, resolve it, and set the variable on that MC's dynamic_props.

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

#### device_font_spacing (91 lines)

Tests text formatting with device fonts and letter spacing. Currently ~51% match — remaining failures are font metrics accuracy issues (letter spacing computation, word wrap with spacing).

**Related to**: TEXTFIELD_PLAN Phase 6 (text layout formatting). Blocked by the same font metrics accuracy issues.

---

### Group B: Blocked by LoadMovie / Multi-SWF Infrastructure

| Test | Lines | Current | Blocker |
|------|-------|---------|---------|
| resolve_different_root | 2 | 0/2 (segfault) | __resolve on loaded child MC; segfault from var_map access in loaded context |
| root_global_parent | 6 | 2/6 | _root._parent chain with loaded movies |
| issue_2084 | 16 | 0/16 | onLoad + attachMovie positioning in child clips |
| issue_2030 | 4 | 0/4 | MC _width/_height from shape content (needs graphics bounds) |

These tests involve multi-SWF loading (`loadMovie`), display list bounds from shape content, or parent chain traversal across loaded movies. All blocked by LOADMOVIE_PLAN infrastructure.

---

### Group C: Blocked by Input Simulation / Other Infrastructure

| Test | Lines | Current | Blocker |
|------|-------|---------|---------|
| string_paths_keyevents | 0 | 0/0 (empty) | 0 expected output lines — likely needs keyboard input.json simulation |
| string_paths_timer | ? | segfault | Timer + string path interaction causes crash; needs debugging |
| localconnection | 579 | ~74/579 (13%) | Full LocalConnection protocol (send/receive/domain management) |
| displacementmapfilter_mappoint_throw_error | 13 | 0/13 | Error/throw from DisplacementMapFilter constructor |
| geturl | 7 | 0/7 | getURL with POST parameters — needs network trace infrastructure |

#### string_paths_keyevents (0 lines expected)

Empty expected output — test likely needs keyboard input simulation to produce output. Effectively a no-op test.

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

### Priority Summary

| Priority | Test | Effort | Lines Gained |
|----------|------|--------|-------------|
| **Quick wins** | issue_3169, get_bytes_total, sandbox_type_remote | ~25 lines | 9 |
| **Medium** | define_local_with_paths | ~20 lines | 34 |
| **Medium** | gettextextent | ~40 lines | 25 |
| **Investigate** | string_paths_timer (segfault) | ? | ? |
| **Blocked** | resolve_different_root, root_global_parent, issue_2030, issue_2084 | blocked by loadMovie | 28 |
| **Low priority** | localconnection, geturl, string_paths_keyevents | complex/blocked | 586 |
