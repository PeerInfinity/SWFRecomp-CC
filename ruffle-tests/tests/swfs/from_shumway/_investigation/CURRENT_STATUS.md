# Shumway Test Suite Status

Last updated: 2026-04-16 (CI run at 82a6ea07)

## Quick Summary

### Flat suite (`from_shumway/`)

| Metric | Value |
|--------|-------|
| Total tests | 92 |
| Passing | **48** (52.2%) |
| Ruffle-matched | 1 |
| Effective pass | **49** (53.3%) |
| Failing | 43 |

**Breakdown by sub-tree** (flat suite now recurses into subdirs):

| Sub-tree | Total | Pass | RM | Fail |
|----------|-------|------|----|------|
| Flat root (no subdir) | 10 | 10 | 0 | 0 |
| `avm1/` | 47 | 32 | 1 | 14 |
| `fuzz/` | 30 | 3 | 0 | 27 |
| `timeline/` | 5 | 3 | 0 | 2 |

The original 30 AVM2/AS3 tests (listed in `ignored_tests.txt`) are no longer in the test pool — they were removed from the checkout, not merely ignored. Current `ignored_tests.txt` is present but has 0 matches (none of its entries appear in results). Flat root dropped from 17 → 10 visible tests for the same reason (visual-only tests like MaskTest/bitmapbuttons/clipping/flash_geom_ColorTransform/flash_text_TextField/gradient are no longer present).

**Flat root is still 100% passing**: all 10 remaining tests (add, avm1timeline1, avm1timeline2, button3, doubleAndRegister, fscommand1, gradientTransform, invalidClipDepth, movieinfo1, targetPath1) pass.

**New failing clusters** come from `fuzz/` (27 fail — fuzzer-generated SWFs, likely useful for finding edge cases in runtime/recompiler), `avm1/` sub-tree (14 fail — see below), and `timeline/` (2 fail).

### AVM1 subdirectory (`from_shumway/avm1/`)

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **32** (68.1%) |
| Ruffle-matched | 1 |
| Effective pass | **33** (70.2%) |
| Ignored | 2 |
| **Filtered pass rate** | **33/45 (73.3%)** |
| Failing (filtered) | 12 |

**Growth**: avm1/ subdirectory expanded 23 → 47 tests via new category sub-trees:
- `duplicateMovieClip/` (4 tests)
- `propertycase/` (3 tests)
- `xml/` (3 tests)
- `bitmapdata/`, `doactionorder/`, `haxe/`, `loadvariables/`, `property-paths/`, `textfield/`, `undefined/` (2 tests each)

**Status from earlier**: 9 original tests fixed (2026-04-10/11): scope, settimeout, setinterval, watch, nested-button, nativeinheritance, array, target, + drag_drop AVM1 regression fix. Original 3 remaining: hitarea (Ruffle known_failure), moviecliploader (blocked on multi-SWF loading), filters (blocked on mc.filters getter). See `complete/SHUMWAY_AVM1_PLAN.md`.

**New work**: 12 filtered failures come from the newly-added category sub-trees. Needs fresh triage — no investigation docs yet for `duplicateMovieClip/`, `propertycase/`, `xml/`, `bitmapdata/`, `doactionorder/`, `haxe/`, `loadvariables/`, `property-paths/`, `textfield/`, `undefined/`.

## Related Documents

| Document | Purpose |
|----------|---------|
| `FAILING_TESTS_BY_FEATURE.md` | Flat-suite failures categorized (30 AVM2 + 2 AVM1, both fixed) |
| `REMAINING_FAILURES_ANALYSIS.md` | Analysis of the 2 fixed flat-suite AVM1 tests + AVM2 ignore list |
| `complete/SHUMWAY_AVM1_PLAN.md` | **NEW** — Plan for 11 failing `avm1/` subdirectory tests |

## Passing Tests (17)

| Test | Lines | Type | Notes |
|------|-------|------|-------|
| add | 11 | AVM1 | Arithmetic operations |
| avm1timeline1 | 3 | AVM1 | Timeline control |
| avm1timeline2 | 6 | AVM1 | Timeline control |
| button3 | 1 | AVM1 | Button events |
| doubleAndRegister | 2 | AVM1 | registerClass + attachMovie with multi-export char_id |
| fscommand1 | 1 | AVM1 | fscommand |
| movieinfo1 | 3 | AVM1 | Movie properties |
| targetPath1 | 8 | AVM1 | MC targetPath + toString |
| MaskTest | 0 | AVM1 | Visual only (zero-output) |
| MaskTest-2 | 0 | AVM1 | Visual only (zero-output) |
| bitmapbuttons | 0 | AVM1 | Visual only (zero-output) |
| clipping | 0 | AVM1 | Visual only (zero-output) |
| flash_geom_ColorTransform | 0 | AVM1 | Visual only (zero-output) |
| flash_text_TextField | 0 | AVM1 | Visual only (zero-output) |
| gradient | 0 | AVM1 | Visual only (zero-output) |
| gradientTransform | 0 | AVM1 | Visual only (zero-output) |
| invalidClipDepth | 0 | AVM1 | Visual only (zero-output) |

8 tests produce meaningful trace output; 9 pass trivially with zero expected lines.

---

## Recently Fixed AVM1 Tests (2026-03-23)

### targetPath1 — FIXED (8/8 lines)

**Root cause**: `mc.toString()` called explicitly via `CallMethod` on a MovieClip returned `undefined` instead of `[object Object]`. The MC user-method dispatch searched `dynamic_props` but couldn't reach `Object.prototype.toString` because `dynamic_props` lacks `__proto__` linkage to `MovieClip.prototype`.

**Fix**: Added fallback in `actionCallMethod` MC handler to check `MovieClip.prototype` → `Object.prototype` chain when method not found on `dynamic_props` or function registry.

### doubleAndRegister — FIXED (2/2 lines)

**Root cause**: `Object.registerClass("CCC", ctor)` + `attachMovie("DDD", ...)` where both "CCC" and "DDD" export the same char_id. `attachMovie` only looked up registered classes by the linkage ID "DDD", missing the "CCC" registration.

**Fix**: Added `lookupRegisteredClassByCharId()` fallback that iterates all export names for a char_id and checks each for a registered class. Applied to both `actionCallFunction` and `actionCallMethod` attachMovie paths.

---

## AVM2/AS3 Tests — Should Be Ignored (30 tests)

These SWFs have the AVM2 flag set and use DoABC tags for AS3 bytecode. Our AVM1 recompiler cannot execute them. They all produce zero trace output.

| Test | SWF Ver | Expected Lines | Notes |
|------|---------|----------------|-------|
| as3-interfaces | 10 | 6 | AS3 interface/class test |
| avm1movie | 10 | 13 | AS3 wrapper loading AVM1 child (`known_failure=true` in Ruffle) |
| button1 | 15 | 1 | AS3 + mouse input |
| button2 | 15 | 1 | AS3 + mouse input |
| captions | 25 | 8 | AS3 text styling |
| encoding1 | 17 | 31 | AS3 AMF0/AMF3 serialization |
| esc | 9 | 2 | AS3 compression/decompression |
| flash_events_Event | 10 | 3 | AS3 event dispatch |
| flash_net_SharedObject | 10 | 4 | AS3 SharedObject API |
| flash_net_URLLoader | 10 | 7 | AS3 network loading |
| flash_net_URLRequest | 10 | 6 | AS3 URL request API |
| flash_net_classes | 10 | 22 | AS3 AMF class registration |
| flash_text_TextField2 | 27 | 18 | AS3 text field |
| flash_utils_Timer | 10 | 2 | AS3 Timer |
| getobjectsunderpoint | 17 | 34 | AS3 hit testing |
| hardwrap | 27 | 1 | AS3 text wrapping |
| hitTestStyleChange | 21 | 1 | AS3 hit test |
| image-loading | 21 | 4 | AS3 image loading |
| local2global | 15 | 1 | AS3 coordinate transforms |
| localconnection | 12 | 12 | AS3 LocalConnection |
| lzma_bytes | 10 | 2 | AS3 ByteArray/LZMA |
| MaskTest-3 | 27 | 4 | AS3 masking (Shape/Sprite) |
| movieclip | 27 | 9 | AS3 MovieClip properties |
| stroke1 | 17 | 1 | AS3 graphics API |
| 3_joystick | 9 | — | AS3 + mouse input |
| ZeroClipboardTest | 10 | — | AS3 + mouse input |
| slider_component | 17 | — | AS3 + mouse input |
| stream1 | 17 | — | AS3 ByteArray stream |
| stylesheet | 25 | — | AS3 CSS parsing |
| lzma | 17 | — | Graphics-only, no AS (LZMA-compressed SWF, expects rendered text) |

---

## Flat Suite Status

All flat-suite work items are complete:
1. ~~Create ignored_tests.txt~~ — DONE (30 AVM2 tests ignored)
2. ~~Fix targetPath1~~ — DONE (MC toString fallback to MovieClip.prototype chain)
3. ~~Fix doubleAndRegister~~ — DONE (registerClass char_id-based lookup)

**Flat suite is at 100%. See `complete/SHUMWAY_AVM1_PLAN.md` for the 11 remaining avm1/ subdirectory failures.**
