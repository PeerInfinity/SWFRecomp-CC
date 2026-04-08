# Shumway AVM1 Subdirectory Tests Plan
<!-- TESTS: scope, nativeinheritance, hitarea, nested-button, settimeout, setinterval, array, target, moviecliploader, filters, watch -->

<!-- PLAN_META
id: SHUMWAY_AVM1
status: incomplete
phases:
  - id: 1
    name: "Quick wins (scope, nativeinheritance)"
    status: not_started
  - id: 2
    name: "Timer coercion and arg forwarding"
    status: not_started
  - id: 3
    name: "Array method return values"
    status: not_started
  - id: 4
    name: "SetTarget path resolution"
    status: not_started
  - id: 5
    name: "Mouse/button event fixes"
    status: not_started
  - id: 6
    name: "Blocked / large features"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-04-07

## Status: NOT STARTED — 11 failing tests (12/23 passing = 52.2%)

These tests live in `ruffle-tests/tests/swfs/from_shumway/avm1/` and were
previously undocumented. The flat `from_shumway/` suite (47 tests, 17/17 AVM1)
is complete; this plan covers the separate `avm1/` subdirectory.

## Summary

| Phase | Tests | Potential Flips | Effort |
|-------|-------|-----------------|--------|
| 1 | scope, nativeinheritance | 2 | Trivial |
| 2 | settimeout, setinterval | 2 | Low |
| 3 | array | 1 | Medium |
| 4 | target | 1 | Medium |
| 5 | hitarea, nested-button | 0-2 | Medium (mouse input) |
| 6 | moviecliploader, filters, watch | 0-1 | High / blocked |
| **Total** | **11** | **6-9** | |

---

## Phase 1: Quick wins

### 1a: `scope` — this binding in method call (1 diff, 11/12 = 93%)

**Diff:**
```
-   12  [type Object]
+   12  _level0
```

`b.t4()` calls a method on an object where `this` should be the object itself.
We return `_level0` (the root movieclip) instead. The trace format `[type Object]`
is Shumway's representation of a plain AS object.

**Root cause:** The method call is binding `this` to the base clip (root MC)
instead of the receiver object `b`. Likely a scope resolution issue in
`actionCallMethod` where the OBJECT method dispatch path falls through to the
movieclip context.

**Fix:** Investigate what type `b` is and which dispatch path
`actionCallMethod` takes. If `b` is an ASObject, the OBJECT handler should set
`this` = `b`, not the current movieclip. May be related to SWF version
semantics (this test's SWF version should be checked).

### 1b: `nativeinheritance` — missing prototype property (1 diff, 5/6 = 83%)

**Diff:**
```
-    6  true
+    6  undefined
```

A constructor `A` creates an instance, and line 6 checks a property that should
be `true`. We return `undefined`. The test exercises native inheritance — likely
checking that an instance of a custom class that extends a native class (e.g.,
Array or MovieClip) inherits a specific property.

**Fix:** Run the test with `--verbose` and inspect the SWF bytecode to
determine which property is being checked. Then ensure the relevant native
prototype has that property registered.

---

## Phase 2: Timer coercion and arg forwarding

### 2a: `settimeout` — non-numeric delay + extra args (6 diffs, 11/17 = 65%)

**Diffs:**
```
# Non-numeric delay should coerce to 0, not reject:
-   12  non-numeric interval is treated as 0: 2
+   12  non-numeric interval is treated as 0: undefined

# Callback never fires (timer not created), so remaining lines missing:
-   13  non-numeric interval triggered
-   14  setTimeout forwards rest arguments: 3
-   15  function callback called
-   16  arg1: arg 1
-   17  arg2: 2
```

Two issues:
1. `setTimeout(func, nonNumericDelay)` returns `undefined` (timer not created)
   instead of a timer ID. Non-numeric delays should coerce to 0.
2. Extra arguments to `setTimeout(func, delay, arg1, arg2)` are not forwarded
   to the callback function.

**Cross-reference:** The AVM1 `set_interval` test (27/27 PASS) already handles
extra args in function-form and method-form timers. The missing piece is
non-numeric delay coercion.

### 2b: `setinterval` — same issues (9 diffs, 11/20 = 55%)

**Diffs:** Same pattern as settimeout plus 3 additional lines for object-method
callback arg forwarding:
```
-   18  object-callback called
-   19  arg1: arg 1
-   20  arg2: 2
```

**Fix (both tests):** In `actionSetInterval`/`actionSetTimeout`:
1. When delay argument is non-numeric (string, undefined, etc.), coerce to 0
   instead of returning undefined. Use `varToDouble` and treat NaN as 0.
2. Verify extra arguments are forwarded to callbacks. The AVM1 timer system
   already stores extra args (`timer->args[]`), so this may already work for
   function-form — check if the Shumway test uses a different calling
   convention.

**File:** `SWFModernRuntime/src/actionmodern/action.c` — `actionSetInterval` /
`actionSetTimeout` delay validation.

---

## Phase 3: Array method return values

### `array` — 7 diffs, 0/7 = 0%

**Diffs:**
```
- concat: a,1,b,[object Object]
+ concat: undefined

- pop: b undefined
+ pop: undefined b

- push: 2 c 2
+ push: undefined undefined 1

- shift: a b
+ shift: undefined a

- slice: b true
+ slice: undefined false

- splice1: b true 2 c
+ splice1: undefined false 3 b

- splice2:  true 4 d c
+ splice2: undefined false 3 b undefined
```

Multiple issues:
1. **concat** returns `undefined` instead of the concatenated string. The
   result of `Array.concat()` is not being captured or traced correctly.
2. **pop/shift** return values are in wrong order or returning undefined for
   the popped/shifted element.
3. **push** returns `undefined` instead of the new length.
4. **slice/splice** return `false` for what should be `instanceof Array`
   checks (results of slice/splice are not recognized as arrays).
5. **splice** element values are wrong.

**Root cause:** Needs investigation. The AVM1 array tests pass, so these
failures likely come from a specific invocation pattern in the Shumway test
(e.g., calling array methods on non-array objects, or checking return types).
Run the test with `--verbose` and inspect the generated C to understand the
calling pattern.

**Fix:** Investigate the specific SWF bytecode. The `instanceof Array` failures
suggest the return values from `concat`/`slice`/`splice` are not being wrapped
as ASArray (type 12) objects.

---

## Phase 4: SetTarget path resolution

### `target` — 17 diffs, 1/18 = 6%

**Key diffs:**
```
# Dot-path targets not resolving:
+ Target not found: Target="a" Base="_level0"
+ Target not found: Target="a.b" Base="_level0"
+ Target not found: Target="a/b" Base="_level0"

# Properties on child MCs returning undefined:
+ a._x = undefined
+ b._x = undefined

# _level0.xx = empty instead of undefined:
- _level0.xx = undefined
+ _level0.xx = 
```

**Root cause:** `SetTarget` with dot-path arguments (`"a"`, `"a.b"`) fails to
resolve child movieclips. The test creates nested MCs and then uses SetTarget to
switch context to them. Our `actionSetTarget` likely only handles single-name
targets, not dot-separated paths.

Additionally, `_level0.xx` property access produces empty string instead of
`undefined` for a non-existent property.

**Fix:** Extend `actionSetTarget` (or the underlying
`findDisplayObjectByName`) to handle dot-separated paths by splitting on `.`
and walking the display list hierarchy. Also handle `/` separator (Flash
supports both `a.b` and `a/b` path formats).

**Cross-reference:** The AVM1 `tell_target_invalid` tests (PASS) exercise
SetTarget but only with single-level names and invalid targets. Dot-path
resolution is a separate code path.

---

## Phase 5: Mouse/button event fixes

### 5a: `hitarea` — hitArea event interaction (2 diffs, 2/4 = 50%)

**Diffs:**
```
-    3  rollover
+    3  1
-    4  1
+    4  <end of actual>
```

Line 3 expects `rollover` (an event label or state string) but we output `1`.
Line 4 expects `1` but we produce no more output.

**Root cause:** The test involves a MovieClip's `hitArea` property and mouse
rollover events. The `rollover` value likely comes from an onRollOver event
handler. Our event dispatch may be firing the wrong handler or the hitArea
delegation is not working.

**Note:** Requires mouse input simulation infrastructure (already present in
verify_output.py for other mouse tests).

### 5b: `nested-button` — nested button click (1 diff, 0/1 = 0%)

**Diff:**
```
-    1  button click
+    1
```

A button nested inside another display object should fire a click handler
tracing `button click`. We output an empty line.

**Root cause:** The nested button's click event handler is not being dispatched.
This may be a button event propagation issue for buttons inside sprites, or the
button's event handler is not registered correctly.

**Note:** Requires mouse input simulation. The AVM1 button tests (BUTTON_PLAN,
14/14 PASS) work for top-level buttons; this tests nesting.

---

## Phase 6: Blocked / large features

### 6a: `moviecliploader` — external SWF loading (6 diffs, 1/7 = 14%)

**Diffs:**
```
-    2  loader frame 2
+    2  onLoadError _level0.content
```

`MovieClipLoader.loadClip()` fires `onLoadError` immediately instead of
successfully loading an external SWF. This requires functional multi-SWF loading
infrastructure.

**Status:** Blocked on loadMovie/loadClip multi-SWF support. Same blocker as
AVM1 LOADMOVIE_PLAN.

### 6b: `filters` — filter reading and construction (146 diffs, 3/149 = 2%)

The test reads pre-existing filters from a display object (`mc.filters`) and
constructs new filters with specific arguments. Our implementation outputs
`Filters (0)` for the read (no filter reading from display objects) and
constructor defaults/values differ.

**Status:** Blocked on `mc.filters` getter returning actual filter objects from
the display list. The AVM1 `bitmap_filters` test (in ignore list) exercises
similar infrastructure from the construction side.

### 6c: `watch` — double-free crash (1 diff + crash, 1/2)

**Error:** `free(): double free detected in tcache 2`

The test calls `Object.prototype.watch()` which triggers a double-free. Only 1
line produced before crash.

**Root cause:** Memory management bug in the watch/unwatch mechanism. A string
or ActionVar is being freed twice — likely the watched property's old value is
freed during the watch callback invocation, then freed again in the normal
property setter path.

**Fix:** Investigate `actionWatchCallback` and `setVariableWithValue` for
double-free paths. The watched property setter probably needs to copy or retain
the old value before invoking the callback, then free only once afterward.

**Note:** The AVM1 `watch_virtual_property` test is in accepted diffs (not
crash). This is a different bug.

---

## Verification

```bash
# Run all Shumway avm1 tests
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_shumway/avm1 \
  --test=scope --test=nativeinheritance --test=hitarea --test=nested-button \
  --test=settimeout --test=setinterval --test=array --test=target \
  --test=moviecliploader --test=filters --test=watch \
  --diff --verbose

# Or run entire subdirectory
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_shumway/avm1 \
  --diff --verbose
```

Always run the AVM1 suite via CI after fixes — timer and array changes have
broad blast radius.
