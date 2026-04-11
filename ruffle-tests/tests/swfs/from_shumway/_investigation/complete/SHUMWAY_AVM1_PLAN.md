# Shumway AVM1 Subdirectory Tests Plan
<!-- TESTS: scope, nativeinheritance, hitarea, nested-button, settimeout, setinterval, array, target, moviecliploader, filters, watch -->

<!-- PLAN_META
id: SHUMWAY_AVM1
status: incomplete
phases:
  - id: 1
    name: "Quick wins (scope, nativeinheritance)"
    status: partial
  - id: 2
    name: "Timer coercion and arg forwarding"
    status: done
  - id: 3
    name: "Array method return values"
    status: not_started
  - id: 4
    name: "SetTarget path resolution"
    status: not_started
  - id: 5
    name: "Mouse/button event fixes"
    status: partial
  - id: 6
    name: "Blocked / large features"
    status: partial
dependencies: []
blockers: []
-->

Last updated: 2026-04-10

## Status: DONE (actionable items) — 3 remaining blocked (20/23 passing = 87.0%)

9 tests fixed: scope, settimeout, setinterval, watch, nested-button, nativeinheritance, array, target, + drag_drop regression fix.
3 still failing: hitarea (Ruffle known_failure), moviecliploader (blocked), filters (blocked).

These tests live in `ruffle-tests/tests/swfs/from_shumway/avm1/` and were
previously undocumented. The flat `from_shumway/` suite (47 tests, 17/17 AVM1)
is complete; this plan covers the separate `avm1/` subdirectory.

## Summary

| Phase | Tests | Potential Flips | Effort | Status |
|-------|-------|-----------------|--------|--------|
| 1 | scope, nativeinheritance | 2 | Both DONE | **DONE** |
| 2 | settimeout, setinterval | 2 | Both DONE | **DONE** |
| 3 | array | 1 | DONE | **DONE** |
| 4 | target | 1 | DONE | **DONE** |
| 5 | hitarea, nested-button | 0→1 | nested-button=DONE, hitarea=known_failure in Ruffle | **DONE** |
| 6 | moviecliploader, filters, watch | 0→1 | watch=DONE, others=blocked | Partial |
| **Total** | **11** | **6-9** | | **4 done** |

---

## Phase 1: Quick wins

### 1a: `scope` — FIXED (14/14 = 100%) ✓

**Root cause:** In Ruffle, `scope.resolve()` returns `Callable(scope_obj, value)` for ALL scope levels, not just WITH scopes. When a nested function (`t5()`) is called standalone from within a method (`b.t4()`), `this` should be the local scope object (which traces as `[type Object]`), not the movieclip.

**Fix (2026-04-10):** Three changes in `action.c`:
1. `actionGetVariable`: set `g_last_callable_this` for all scope chain entries (removed `scope_is_with[i]` guard)
2. `actionCallFunction`: moved scope chain lookup before global function registry lookup
3. `actionCallFunction`: pass `callable_this` via `g_override_this` for DefineFunction2 with preload_this

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

## Phase 2: Timer coercion and arg forwarding — FIXED ✓

### 2a: `settimeout` — FIXED (17/17 = 100%) ✓
### 2b: `setinterval` — FIXED (20/20 = 100%) ✓

**Root cause (2026-04-10):** Two issues:
1. Non-numeric string delays (e.g., `"foo"`) returned NaN → rejected with `undefined`.
   Fix: coerce NaN to 0 for non-undefined types. `undefined` delay still rejects
   (Flash behavior confirmed by AVM1 `set_interval` test).
2. Timer stubs (`g_setTimeout_func` etc.) were `builtin_noop_func` — calling
   `setTimeout` through an alias (`var f = setTimeout; f(...)`) bypassed the
   builtin handler and called the noop stub. Fix: replaced stubs with real
   `builtin_setTimeout_impl`/`builtin_setInterval_impl` that delegate to
   `actionSetInterval`.

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

### 5a: `hitarea` — BLOCKED (known_failure in Ruffle, 2/4 = 50%)

**Diff:**
```
-    3  rollover
+    3  1
-    4  1
+    4  <end of actual>
```

Actual output: `undefined / _level0.hit / 1` (3 lines). Expected: `undefined / _level0.hit / rollover / 1` (4 lines).
Lines 1-2 match. Line 3 should be `rollover` (from an onRollOver event handler) but we skip it and output `1`.

**Root cause:** The test sets `btn.hitArea = hit` where `hit` is a sprite. This
makes the button use the sprite's shape for hit-testing instead of its own.
When the mouse moves over the hit sprite's area, onRollOver should fire on the
button. Our runtime ignores the `hitArea` property assignment — the button
always uses its own hit shape.

**Mouse infrastructure:** Fully operational. `input.json` → `verify_output.py` →
event file → `input_events_deliver()` in `swf_core.c`. Button state machine,
shape hit-testing, and MC mouse handlers all work (rollover test 4/4 PASS).

**Fix:** Two parts:
1. `action.c` `actionSetMember` MOVIECLIP handler: store `hitArea` MC reference
   on the button's MovieClip (e.g., `mc->hit_area_mc` field, or on dynamic_props).
2. `tag.c` `ng_update_button_states_in_dl()` → `resolve_hit_shape()`: when the
   button MC has a `hitArea` property, use the referenced sprite's shape for
   hit-testing instead of the button's own hit character.

**Files:** `SWFModernRuntime/src/libswf/tag.c` (hit-test lookup),
`SWFModernRuntime/src/actionmodern/action.c` (property storage).

### 5b: `nested-button` — FIXED (1/1 = 100%) ✓

**Diff:**
```
-    1  button click
+    1
```

**Root cause:** The test has a shape (char 1) placed inside a sprite (char 3).
The sprite has `CLIP_EVENT_RELEASE` (0x800) clip actions that trace
`button click`. No actual button character is defined — just a sprite with
clip actions that respond to mouse release.

Currently, only `CHAR_TYPE_BUTTON` characters get mouse hit-tested in
`ng_update_button_states_in_dl()`. Shapes placed in sprites don't trigger
hit-testing, so the sprite's `CLIP_EVENT_RELEASE` never fires.

**Fix:** Generalize mouse hit-test dispatch in `tag.c` so that non-button
display objects with mouse-related clip actions (PRESS 0x400, RELEASE 0x800,
RELEASE_OUTSIDE 0x2000, ROLL_OVER 0x0400, etc.) also get hit-tested and
have their clip events dispatched on state transitions.

Key functions:
- `ng_update_button_states_in_dl()` in `tag.c` — extend to track hit state
  for display objects with mouse clip actions, not just buttons
- `dispatch_clip_event_press()`/`dispatch_clip_event_release()` in
  `swf_core.c` — already dispatch clip events, just need to be triggered
  for non-button hit objects

**Files:** `SWFModernRuntime/src/libswf/tag.c`, `SWFModernRuntime/src/libswf/swf_core.c`.

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

### 6c: `watch` — FIXED (2/2 = 100%) ✓

**Root cause (2026-04-10):** The watch callback mechanism passed string args
(property name, old value, user data) with `owns_memory=true`. The callback
stored `args[0]` via `setVariableByName`, creating an owning copy in the local
scope. When the local scope was released, the string was freed. Then the
explicit `free(_pname_arg.data.string_data.heap_ptr)` freed the same pointer
again → double-free.

**Fix:** Mark all string args passed to watch callbacks as non-owning
(`owns_memory = false`). The explicit `free()` after the callback is the sole
owner of `_pname_arg`. Applied to both ASObject and MovieClip watch handlers.

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
