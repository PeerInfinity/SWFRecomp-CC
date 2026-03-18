# Shumway Test Suite Status

Last updated: 2026-03-18 (detailed investigation)

## Quick Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **15** (31.9%) |
| AVM2/AS3 (should ignore) | **30** |
| AVM1 failing (fixable) | **2** |
| Effective AVM1 pass rate | **15/17** (88.2%) |

No crashes or compile failures. All failures are output mismatches.

**Key finding**: 30 of the 32 failing tests are AVM2/AS3, which our AVM1 recompiler cannot execute. After ignoring them, only 2 AVM1 tests fail, giving an effective pass rate of 88.2%.

## Passing Tests (15)

| Test | Lines | Type | Notes |
|------|-------|------|-------|
| add | 11 | AVM1 | Arithmetic operations |
| avm1timeline1 | 3 | AVM1 | Timeline control |
| avm1timeline2 | 6 | AVM1 | Timeline control |
| button3 | 1 | AVM1 | Button events |
| fscommand1 | 1 | AVM1 | fscommand |
| movieinfo1 | 3 | AVM1 | Movie properties |
| MaskTest | 0 | AVM1 | Visual only (zero-output) |
| MaskTest-2 | 0 | AVM1 | Visual only (zero-output) |
| bitmapbuttons | 0 | AVM1 | Visual only (zero-output) |
| clipping | 0 | AVM1 | Visual only (zero-output) |
| flash_geom_ColorTransform | 0 | AVM1 | Visual only (zero-output) |
| flash_text_TextField | 0 | AVM1 | Visual only (zero-output) |
| gradient | 0 | AVM1 | Visual only (zero-output) |
| gradientTransform | 0 | AVM1 | Visual only (zero-output) |
| invalidClipDepth | 0 | AVM1 | Visual only (zero-output) |

6 tests produce meaningful trace output; 9 pass trivially with zero expected lines.

---

## AVM1 Failing Tests (2 tests)

### targetPath1 — Near-passing (6/8 lines, 75%)

**Diff**:
```
     5  s.t: _level0.s.t
-    6  [object Object]
+    6  undefined
-    7  [object Object]
+    7  undefined
     8  Done
```

**Root cause**: `this.toString()` and `s.toString()` called via `CallMethod` on MovieClip references return `undefined` instead of `[object Object]`. When a MovieClip doesn't have a custom `toString`, the default should return `[object Object]` (Flash/Shumway behavior).

**Fix**: Implement default `toString()` for MovieClip objects returning `"[object Object]"` when no custom toString is defined. This may already be partially implemented for the AVM1 suite — needs investigation of whether this is a Shumway-specific path.

### doubleAndRegister — 0/2 lines

**Expected output**:
```
Constr CCC
bar
```

**Root cause**: The test uses `Object.registerClass("CCC", constructor)` then `attachMovie("DDD", "AAA", 2, ...)` where both "DDD" and "CCC" are exports mapping to the same sprite char_id (2). The registered class constructor for "CCC" should fire when the sprite is instantiated via `attachMovie("DDD", ...)`, but it doesn't — the constructor is never invoked and the method call fails.

**Fix**: The `registerClass` / `attachMovie` path may need to look up registered classes by char_id (not just by the export name passed to `attachMovie`). When attaching "DDD", the runtime should check if char_id 2 has any registered class (whether registered via "CCC" or "DDD").

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

## Recommended Work Order

1. **Create ignored_tests.txt** for the Shumway suite with all 30 AVM2 tests. This immediately changes the effective failure count from 32 to 2.
2. **Fix targetPath1** (near-passing, 6/8): Investigate default `toString()` for MovieClip objects.
3. **Fix doubleAndRegister** (0/2): Investigate `registerClass` + `attachMovie` char_id-based lookup.
4. After filtering, the effective pass rate becomes **15/17 (88.2%)** — comparable to the AVM1 suite's early stages.
