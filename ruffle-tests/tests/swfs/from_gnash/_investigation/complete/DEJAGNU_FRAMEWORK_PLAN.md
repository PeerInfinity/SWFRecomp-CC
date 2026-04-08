# Dejagnu Test Framework Plan
<!-- TESTS: -->

<!-- PLAN_META
id: DEJAGNU_FRAMEWORK
status: complete
phases:
  - id: 1
    name: "actionscript.all Dejagnu framework"
    status: complete
  - id: 2
    name: "misc-mtasc Dejagnu class"
    status: complete
dependencies: []
blockers:
  - reason: "misc-ming/misc-swfc blocked on DoInitAction ordering for inlined Dejagnu"
-->

Last updated: 2026-04-08

## Status: COMPLETE — actionscript.all and misc-mtasc frameworks working

This plan covered getting the Dejagnu test harness working for the Gnash test
suite. The primary goal (actionscript.all running with correct PASSED/FAILED
output) is complete. misc-mtasc is also working. misc-ming/misc-swfc remain
blocked on an architectural limitation.

**Moved from:** `avm1/_investigation/incomplete/FROM_GNASH_DEJAGNU_PLAN.md`
(original location was in the AVM1 investigation directory; moved here since
the content is about Gnash tests).

---

## Dejagnu Test Harness Reference

### How Dejagnu Works

Three patterns are used across the Gnash test sub-suites:

**External pattern (actionscript.all — 190 tests):**
1. Test SWF frame 1: `loadMovie("Dejagnu.swf", "__shared_assets")`
2. Test SWF uses `setInterval` to poll `_root.dejagnu_module_initialized`
3. Dejagnu.swf (SWF5, 10,574 bytes) defines `check_equals`, `xcheck_equals`,
   `pass`, `fail`, `note`, `printtotals` as global functions on `_root`
4. Once initialized, test assertions run via `check_equals(a, b)` → traces
   "PASSED: ..." or "FAILED: ..."
5. Final frame calls `printtotals()` → traces "#passed: N / #failed: N"

All 190 copies of Dejagnu.swf are identical (md5: `b1fec5ab5f6e19bee63e4064d0e89090`).

**MTASC class pattern (misc-mtasc — 9 tests):**
- Dejagnu is an AS2 class (`__Packages.Dejagnu`) compiled into the SWF
- Creates a TextField for visual output + uses `trace()` for console output
- Works fully: 7/9 tests pass

**Inline pattern (misc-ming — 58 tests, misc-swfc — 16 tests):**
- Dejagnu functions compiled directly into the test SWF's constant pool
- Defined via DoInitAction on a library symbol
- **BLOCKED** — see below

### Dejagnu.swf String Constants

Key strings in Dejagnu.swf's constant pool:
```
check_equals, xcheck_equals, check, xcheck
pass, fail, xpass, xfail
note, info, quit
printtotals
PASSED:, FAILED:
#passed:, #failed:, #total tests run:
dejagnu_module_initialized
```

---

## Completed Work

### actionscript.all (Phase 1) — DONE

Four fixes to get the external Dejagnu pattern working:

1. **ImportAssets char_id remapping** — `tagImportCharacter` implemented; the
   recompiler emits char_id→export_name mappings so the runtime can remap
   imported character definitions into the parent's dictionary.

2. **Infinite re-entry from onEnterFrame goto** — The Dejagnu checker callback
   called `gotoAndPlay(0)`, triggering synchronous catch-up which re-dispatched
   enterFrame, creating an infinite loop. Fixed via `g_inside_enterframe_dispatch`
   flag that defers gotos from enterFrame handlers.

3. **Dejagnu SWF5 init poisons Object.prototype** — Dejagnu.swf (SWF5) import
   caused `getObjectPrototype()` to run under SWF5 version, skipping
   `hasOwnProperty` and related methods. Fixed by always installing these
   methods regardless of SWF version.

4. **Transform buffer overflow** — Child movie (Dejagnu.swf) had 24 transforms
   but parent had only 4. Fixed by setting `g_active_transform_data` to the
   child's array in `exec_sprite_frame`.

### misc-mtasc (Phase 2) — DONE

- `typeof(Dejagnu)` fix via `_global` plain property resolution
- Array.prototype constructor property + objectCallToString fixes
- 7/9 tests now pass

---

## Remaining Blocker: misc-ming / misc-swfc Inlined Dejagnu

**58 + 16 = 74 tests, 11 passing total (14.9%)**

Most failing tests produce zero PASSED/FAILED output despite executing. The
inlined Dejagnu functions (`check_equals`, `pass`, `fail`, `printtotals`) are
defined via DoInitAction on library symbols.

**Root cause:** Our runtime only runs DoInitAction for sprites that are actually
placed on the timeline. Flash runs DoInitAction for all library exports,
regardless of whether they're placed. If the Dejagnu symbol's sprite isn't
placed, the DoInitAction never fires and the check functions are never defined.

**Investigation steps (not yet attempted):**
1. Pick one misc-ming test (e.g., `PlaceObject2Test`) and examine its
   recompiled C to see if Dejagnu-related DoInitActions are being emitted
2. Check if the test SWF has a sprite with an associated DoInitAction that
   defines the check functions
3. Compare with what Flash/Ruffle would execute — specifically, when does
   DoInitAction fire relative to timeline execution?

**Fix approach:** The recompiler or runtime needs to support "eager"
DoInitAction — running init actions for library exports at SWF load time, not
at first placement time. This is a significant architectural change.
