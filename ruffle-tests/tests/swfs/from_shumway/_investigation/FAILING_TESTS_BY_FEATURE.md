# Shumway Failing Tests by Feature Category

Last updated: 2026-03-19 (based on CI run 043094ef)

- **Total tests**: 47
- **Passing**: 15 (31.9%)
- **Failing**: 32 (all output mismatch, no crashes)
- **AVM2/AS3 (should ignore)**: 30
- **AVM1 failing (fixable)**: 2
- **Effective AVM1 pass rate**: 15/17 (88.2%)
- **Line-level match**: 31/256 (12.1%) — low because AVM2 tests produce 0 output vs. expected

---

## 1. AVM2/AS3 Tests — Not Applicable (30 tests)

These SWFs use the AVM2 flag and DoABC tags for AS3 bytecode. Our AVM1 recompiler cannot execute them. They all produce zero trace output and should be added to an `ignored_tests.txt` file.

### With Expected Trace Output (25 tests)

| Test | SWF Ver | Expected Lines | Type |
|------|---------|----------------|------|
| as3-interfaces | 10 | 6 | AS3 interface/class |
| avm1movie | 10 | 13 | AS3 loading AVM1 child |
| button1 | 15 | 1 | AS3 + mouse input |
| button2 | 15 | 1 | AS3 + mouse input |
| captions | 25 | 8 | AS3 text styling |
| encoding1 | 17 | 31 | AS3 AMF serialization |
| esc | 9 | 2 | AS3 compression |
| flash_events_Event | 10 | 3 | AS3 event dispatch |
| flash_net_SharedObject | 10 | 4 | AS3 SharedObject |
| flash_net_URLLoader | 10 | 7 | AS3 URL loading |
| flash_net_URLRequest | 10 | 6 | AS3 URL request |
| flash_net_classes | 10 | 22 | AS3 AMF classes |
| flash_text_TextField2 | 27 | 18 | AS3 text field |
| flash_utils_Timer | 10 | 2 | AS3 Timer |
| getobjectsunderpoint | 17 | 34 | AS3 hit testing |
| hardwrap | 27 | 1 | AS3 text wrapping |
| hitTestStyleChange | 21 | 1 | AS3 hit test |
| image-loading | 21 | 4 | AS3 image loading |
| local2global | 15 | 1 | AS3 coordinates |
| localconnection | 12 | 12 | AS3 LocalConnection |
| lzma_bytes | 10 | 2 | AS3 ByteArray |
| MaskTest-3 | 27 | 4 | AS3 masking |
| movieclip | 27 | 9 | AS3 MovieClip |
| stroke1 | 17 | 1 | AS3 graphics API |
| lzma | 17 | 0 (graphics) | LZMA-compressed SWF |

### Without Trace Output / Mouse Input Required (5 tests)

| Test | SWF Ver | Notes |
|------|---------|-------|
| 3_joystick | 9 | AS3 + mouse input |
| ZeroClipboardTest | 10 | AS3 + mouse input |
| slider_component | 17 | AS3 + mouse input |
| stream1 | 17 | AS3 ByteArray stream |
| stylesheet | 25 | AS3 CSS parsing |

---

## 2. AVM1 Failing: targetPath1 — Near-Passing (6/8, 75%)

**Diff**:
```
     5  s.t: _level0.s.t
-    6  [object Object]
+    6  undefined
-    7  [object Object]
+    7  undefined
     8  Done
```

**Root cause**: `this.toString()` and `s.toString()` called via `CallMethod` on MovieClip references return `undefined` instead of `[object Object]`. When a MovieClip doesn't have a custom `toString`, the default should fall through to `Object.prototype.toString()` returning `"[object Object]"`.

**Fix approach**: Ensure MovieClip objects' prototype chain includes `Object.prototype.toString()`. The `objectCallToString` path may not handle the MOVIECLIP type correctly, or the MC's `__proto__` chain doesn't reach Object.prototype.

**Fix complexity**: Low-Medium.

---

## 3. AVM1 Failing: doubleAndRegister — 0/2 lines

**Expected output**:
```
Constr CCC
bar
```

**Root cause**: The test uses `Object.registerClass("CCC", constructor)` then `attachMovie("DDD", "AAA", 2, ...)` where both "DDD" and "CCC" are exports mapping to the same sprite char_id. The registered class constructor for "CCC" should fire when the sprite is instantiated via `attachMovie("DDD", ...)`, but it doesn't.

**Fix approach**: The `registerClass` / `attachMovie` path needs to look up registered classes by **char_id** (not just by the export name passed to `attachMovie`). When attaching "DDD", resolve it to char_id 2, then check if any registered class is associated with char_id 2 (which "CCC" is).

**Fix complexity**: Medium — requires `ng_lookupExportName` reverse lookup integration into the attachMovie constructor path.

---

## Recommended Work Order

### Step 1: Create ignored_tests.txt (immediate, no code changes)

Create `ruffle-tests/tests/swfs/from_shumway/ignored_tests.txt` with all 30 AVM2 tests. This immediately changes the visible pass rate from 31.9% to **88.2%** (15/17).

### Step 2: Fix targetPath1 (Low-Medium effort)

Investigate why `toString()` on MovieClip returns `undefined` in this context. Likely a prototype chain gap — MC `__proto__` should reach `Object.prototype`.

### Step 3: Fix doubleAndRegister (Medium effort)

Add char_id-based `registerClass` lookup to the `attachMovie` path. The `ng_lookupExportName` helper already exists — needs integration into the constructor lookup in `actionCallFunction`/`actionCallMethod` attachMovie paths.

### After all fixes: 17/17 (100%) effective AVM1 pass rate
