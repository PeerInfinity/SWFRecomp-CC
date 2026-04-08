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

## Flat Suite — Recommended Work (ALL COMPLETE)

1. ~~Create ignored_tests.txt~~ — DONE (30 AVM2 tests ignored)
2. ~~Fix targetPath1~~ — DONE (MC toString fallback)
3. ~~Fix doubleAndRegister~~ — DONE (registerClass char_id lookup)

**Flat suite at 17/17 (100%) effective AVM1 pass rate.**

---

## 4. AVM1 Subdirectory Failures (11 tests, 12/23 = 52.2%)

The `from_shumway/avm1/` subdirectory contains 23 additional AVM1 tests, 11 of
which fail. These were not documented previously. See
`incomplete/SHUMWAY_AVM1_PLAN.md` for the full investigation plan.

| Test | Match | Root Cause |
|------|-------|-----------|
| scope | 11/12 (93%) | `this` binding — method returns root MC instead of receiver |
| nativeinheritance | 5/6 (83%) | Missing native prototype property |
| settimeout | 11/17 (65%) | Non-numeric delay rejected instead of coerced to 0 |
| setinterval | 11/20 (55%) | Same as settimeout + object-method arg forwarding |
| hitarea | 2/4 (50%) | hitArea mouse event interaction |
| array | 0/7 (0%) | Array method return values wrong |
| moviecliploader | 1/7 (14%) | External SWF loading not implemented |
| target | 1/18 (6%) | SetTarget dot-path resolution fails |
| filters | 3/149 (2%) | Filter reading from display objects not implemented |
| nested-button | 0/1 (0%) | Nested button click handler not firing |
| watch | crash | Double-free in Object.prototype.watch() |
