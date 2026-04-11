# Shumway Test Suite Status

Last updated: 2026-04-10

## Quick Summary

### Flat suite (`from_shumway/`)

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **17** (36.2%) |
| AVM2/AS3 (ignored) | **30** |
| AVM1 failing | **0** |
| **Filtered AVM1 pass rate** | **17/17 (100.0%)** |

**Status**: All flat-suite AVM1 tests pass. 30 AVM2 tests ignored.

### AVM1 subdirectory (`from_shumway/avm1/`)

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **16** (69.6%) |
| Failing | **7** (7 output_mismatch) |
| No ignore list | — |

**Status**: 4 tests fixed (2026-04-10): scope, settimeout, setinterval, watch. 7 remaining failures. See `incomplete/SHUMWAY_AVM1_PLAN.md` for details.

## Related Documents

| Document | Purpose |
|----------|---------|
| `FAILING_TESTS_BY_FEATURE.md` | Flat-suite failures categorized (30 AVM2 + 2 AVM1, both fixed) |
| `REMAINING_FAILURES_ANALYSIS.md` | Analysis of the 2 fixed flat-suite AVM1 tests + AVM2 ignore list |
| `incomplete/SHUMWAY_AVM1_PLAN.md` | **NEW** — Plan for 11 failing `avm1/` subdirectory tests |

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

**Flat suite is at 100%. See `incomplete/SHUMWAY_AVM1_PLAN.md` for the 11 remaining avm1/ subdirectory failures.**
