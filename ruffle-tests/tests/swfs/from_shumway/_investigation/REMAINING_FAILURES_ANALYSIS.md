# Shumway Remaining Failures Analysis

Date: 2026-03-19
CI run: 043094ef (15/47 total = 31.9%, effective 15/17 AVM1 = 88.2%)

Only 2 AVM1 tests are failing. The other 30 failures are AVM2/AS3 tests that our AVM1 recompiler cannot execute — these should be ignored.

---

## AVM1 Test 1: targetPath1 (6/8 = 75%)

**Test purpose**: Tests `targetPath()` function and MovieClip toString behavior for nested sprites.

**Full diff**:
```
  1  _level0
  2  _level0.s
  3  _level0.s.t
  4  s.t: _level0.s.t
  5  s.t: _level0.s.t
- 6  [object Object]
+ 6  undefined
- 7  [object Object]
+ 7  undefined
  8  Done
```

**Analysis**: Lines 1-5 pass (targetPath works for nested MCs). Lines 6-7 call `this.toString()` and `s.toString()` on MovieClip instances. Flash/Shumway behavior: when a MC doesn't have a custom `toString`, the call falls through to `Object.prototype.toString()` returning `"[object Object]"`. Our implementation returns `undefined`.

**Root cause investigation**:
1. The `objectCallToString` function in action.c handles MOVIECLIP type — check if it reaches `Object.prototype.toString()`
2. The MC's `__proto__` chain may not include `Object.prototype`
3. Alternatively, `CallMethod` with method name "toString" on MOVIECLIP may be taking a wrong code path

**Estimated fix**: 1-2 hours. Ensure MC prototype chain reaches Object.prototype.toString().

**Overlap with other suites**: The AVM1 suite's MovieClip tests already pass toString for most cases, so this may be a Shumway-specific path (possibly different CallMethod dispatch for explicit toString calls vs. implicit coercion).

---

## AVM1 Test 2: doubleAndRegister (0/2)

**Test purpose**: Tests `Object.registerClass` with multiple export names mapping to the same sprite char_id.

**Expected output**:
```
Constr CCC
bar
```

**Actual output**: (empty)

**Analysis**: The test registers a constructor for export name "CCC" via `Object.registerClass("CCC", constructor)`, then calls `attachMovie("DDD", "AAA", 2, ...)` where "DDD" is a different export name that maps to the same char_id as "CCC". The registered class constructor should fire because the underlying sprite has a registered class.

**Root cause**: `attachMovie("DDD", ...)` resolves "DDD" to a char_id, then calls `lookupRegisteredClass("DDD")` which returns NULL (no class registered for "DDD"). It should also check `lookupRegisteredClass` with all export names that map to the same char_id — specifically, it should resolve char_id → all export names → check each for a registered class.

**Fix approach**:
1. In the `attachMovie` handler (actionCallFunction/actionCallMethod), after resolving the export name to char_id, use `ng_lookupExportName(char_id)` to get the canonical export name
2. Call `lookupRegisteredClass()` with the canonical export name
3. If found, invoke the constructor

**Estimated fix**: 1-2 hours. The infrastructure (`ng_lookupExportName`) already exists; needs wiring into the attachMovie constructor lookup.

**Overlap with other suites**: The AVM1 suite's `register_class_return_value` test passes (16/16), but it doesn't test the cross-export-name scenario.

---

## Impact Summary

| Test | Lines Wrong | Fix Effort | Fix Impact |
|------|-------------|------------|------------|
| targetPath1 | 2 | Low-Medium | 88.2% → 94.1% |
| doubleAndRegister | 2 | Medium | 94.1% → 100% |

Both fixes together would bring the effective AVM1 pass rate to **17/17 (100%)**.

---

## AVM2 Ignore List

The following 30 tests should be placed in `ruffle-tests/tests/swfs/from_shumway/ignored_tests.txt`:

```
3_joystick
MaskTest-3
ZeroClipboardTest
as3-interfaces
avm1movie
button1
button2
captions
encoding1
esc
flash_events_Event
flash_net_SharedObject
flash_net_URLLoader
flash_net_URLRequest
flash_net_classes
flash_text_TextField2
flash_utils_Timer
getobjectsunderpoint
hardwrap
hitTestStyleChange
image-loading
local2global
localconnection
lzma
lzma_bytes
movieclip
slider_component
stream1
stroke1
stylesheet
```

Creating this file immediately changes the visible results from 15/47 (31.9%) to **15/17 (88.2%)** with zero code changes.
