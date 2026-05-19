# Object-vN Investigation Plan
<!-- TESTS: Object-v6, Object-v7, Object-v8 -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproductions at the current `master` SHA; no fixes
landed yet)

<!-- PLAN_META
id: OBJECT_VN_PLAN
status: pending
phases:
  - id: 1
    name: "Function class identity (shared with FUNCTION_VN_PLAN Phase 1)"
    status: pending
  - id: 2
    name: "obj.hasOwnProperty('constructor') — constructor as own vs inherited"
    status: pending
  - id: 3
    name: "addProperty getter/setter call counters returning 65 instead of expected 1"
    status: pending
  - id: 4
    name: "addProperty getter return value lost in trace ('v == 5 obtained:')"
    status: pending
  - id: 5
    name: "watch() callback parameter binding (_root.info.nam/.nv/.d/.tv empty)"
    status: pending
  - id: 6
    name: "Object._target should be undefined, not '/_levelN/...' string"
    status: pending
  - id: 7
    name: "watch return value (r expected true, got false / vice versa)"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac); Object-v6/v7/v8 became visible at that point. Object-v5 already passes."
related:
  - id: FUNCTION_VN_PLAN
    reason: "Phase 1 (Function class identity) is the same fix as FUNCTION_VN_PLAN Phase 1; do it once and verify both families."
blockers: []
status_note: |
  Object-v5 is already at ruffle_matched; v6/v7/v8 share most of the
  same failure structure with progressively more SWF-version-specific
  assertions. Drive Phase 1-7 against Object-v6 then re-run v7/v8 to
  confirm parity. Promotion plumbing: all three ship
  `output.fpN.ruffle.txt` with `known_failure = true` per upstream
  test.toml.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| Object-v5 | 142/145 | 97.9% | ruffle_matched (already eff-pass) |
| Object-v6 | 286/333 | 85.9% | output_mismatch |
| Object-v7 | 299/333 | 89.8% | output_mismatch |
| Object-v8 | 299/333 | 89.8% | output_mismatch |

## Test source

Gnash testsuite/actionscript.all/Object.as (~1100 lines). Exercises
~325 assertions covering:

- Object class / prototype identity
- `hasOwnProperty`, `isPrototypeOf`, `propertyIsEnumerable`
- `addProperty(name, getter, setter)` virtual-property dispatch
- `watch` / `unwatch` change-notification callbacks
- Object.prototype methods (`toString`, `valueOf`, `__proto__`)
- Implicit `valueOf` / `toString` coercion (`"string + " + obj`)

## Failure clusters

### A. Function class identity (Phase 1) — shared

Lines: 71.

```
- PASSED: Object.prototype.toString.constructor == Function [./Object.as:71]
+ FAILED: expected: Function obtained: [type Function]
```

Same root cause as [[FUNCTION_VN_PLAN]] Phase 1: the global `Function`
constructor traces as `[type Function]` instead of `Function`. Fixing
it once unblocks this line plus the larger Function-vN cluster.

### B. obj.hasOwnProperty('constructor') (Phase 2)

Lines: 170 (and similar).

```
- PASSED: obj.hasOwnProperty('constructor') [./Object.as:170]
+ FAILED: obj.hasOwnProperty('constructor')
```

`obj` here is a fresh `new Object()`. Flash makes `constructor` an
own property of every Object instance; we treat it as inherited from
`Object.prototype` so `hasOwnProperty('constructor')` returns false.
Symmetric to the existing `obj.hasOwnProperty('__constructor__')`
check at line 176 which we PASS — so the fix is targeted at the
constructor-vs-__constructor__ own-vs-inherited distinction in
`actionNewObject`.

### C. addProperty call-counter returns 65 (Phase 3)

Lines: 313, 322, 337, 443, 496, 497, 509, 510, 835.

```
- PASSED: test_get_calls == 1 [./Object.as:313]
+ FAILED: expected: 1 obtained: 65
```

```
- PASSED: o1.setterCalls == 1 [./Object.as:496]
+ FAILED: expected: 1 obtained: 3
```

```
- PASSED: c == 7 [./Object.as:443]
+ FAILED: expected: 7 obtained: false
```

The counter increments inside an addProperty setter/getter are wildly
wrong. `65` is the ASCII codepoint for `'A'` — suggests the counter
is being initialized from or compared against a string character
somewhere. `c == 7 obtained: false` is more revealing: the test
expects `c` to be an integer counter; we are returning the boolean
result of an upstream comparison. Likely the addProperty dispatch
path is reading the *return value* of the setter as the counter
rather than the value the setter assigned via a closure-captured
local.

Investigation priority: instrument addProperty getter/setter dispatch
to log the actual stack values at each step, identify whether the
issue is a stack-slot read (return value vs. captured local).

### D. addProperty getter return lost in trace (Phase 4)

Lines: 317, 335, 460, 503, 504, 516, 517, 535, 554, 558, 570, 573,
624, 656, 640.

```
- PASSED: v == 5 [./Object.as:317]
+ FAILED: expected: 5 obtained:
- PASSED: o.mem == 3 [./Object.as:460]
+ FAILED: expected: 3 obtained:
- PASSED: o1.mem1 == 3 [./Object.as:503]
+ FAILED: expected: 3 obtained:
```

Pattern: a getter that returns a value is invoked, we trace the
result, and the trace shows an empty string instead of the expected
number. The getter is firing (Phase 3 shows the call counter
increments — even if wrong), but the return value isn't surviving
back to the caller. Likely a stack/return-handling bug in the
`invokePropertyGetter` path when the getter is reached via
prototype chain.

May be the same root cause as Phase 3 — both look like the dispatch
path's return-value plumbing is confused.

### E. watch() callback parameter binding (Phase 5)

Lines: 777, 779, 780, 781, 800, 803, 804, 818, 823, 830, 831, 832, 833.

```
- PASSED: _root.info.nam == 'l' [./Object.as:777]
+ FAILED: expected: 'l' obtained:
- PASSED: _root.info.tv == o [./Object.as:781]
+ FAILED: expected: o obtained: _level0
- PASSED: r == 'return from watch' [./Object.as:818]
+ FAILED: expected: 'return from watch' obtained:
```

The test installs a `watch` callback that receives
`(name, oldVal, newVal, userData)` and stores them on `_root.info`.
We are storing nothing on `_root.info` (object becomes `undefined`
implicitly) for some lines, and storing `_level0` instead of `o`
(the original object reference) for others. Two sub-issues:

- The callback args aren't being forwarded to the watcher function.
- When the watcher receives `tv = o`, our `_root.info.tv` gets
  `_level0` (the root MC's name) rather than the object reference.
  This suggests the `o` value is being coerced through a
  MovieClip-like path (toString → "_level0") instead of stored
  as-is.

May share root cause with [[FUNCTION_VN_PLAN]] Phase 2 (call/apply
this-binding) if the watch dispatch uses the same call-setup
machinery.

### F. Object._target returns string (Phase 6)

Lines: 366.

```
- PASSED: typeof(o._target) == "undefined" [./Object.as:366]
+ FAILED: expected: "undefined" obtained: string
```

`o` is a plain `new Object()`. Flash returns `undefined` for
`o._target` (Object instances are not MovieClips and have no
target path); we return a string. Likely the `_target` getter is
unconditionally returning the current target path without checking
the receiver type.

### G. watch return value (Phase 7)

Lines: 373, 376, 385, 525, 527, 541, 543, 846, 846, 849.

```
- PASSED: ret == false [./Object.as:373]
+ FAILED: expected: false obtained: true
- PASSED: !r [./Object.as:525]
+ FAILED: !r
```

`watch` returns true on success, false on failure (per ECMAScript-262
extension Adobe documented). The test exercises invalid-arg cases
(`watch()` with too few args, `watch` on a property that doesn't
exist as a slot, etc.) and expects `false`. We return `true` in
those cases. Likely the argument validation is missing.

May be cheap — a focused arg-count check in `builtin_object_watch`.

## Recommended fix order

1. **Phase 1 (Function class identity)** — already at the top of
   [[FUNCTION_VN_PLAN]]. Defer; do not duplicate work here.
2. **Phase 6 (_target on Object)** — single-line fix, fastest win.
   Estimate: 30 min.
3. **Phase 7 (watch return value)** — small, validation-only.
   Estimate: 1 hour.
4. **Phases 3 + 4 (addProperty getter/setter dispatch)** — likely
   same root cause; investigate together. Estimate: 3-4 hours.
5. **Phase 5 (watch callback args)** — depends on Phase 3/4 if they
   share the call-setup machinery. Estimate: 2-3 hours.
6. **Phase 2 (constructor own vs inherited)** — small but touches
   widely-used Object instantiation; do last to avoid regression
   thrash. Estimate: 1-2 hours.

Total estimate: 8-11 hours, 2-4 sessions.

## Promotion plumbing

All three tests have `known_failure = true` + `output.fpN.ruffle.txt`
sidecars; subset-match auto-promotes to `ruffle_matched` once our
diff is within Ruffle's.
