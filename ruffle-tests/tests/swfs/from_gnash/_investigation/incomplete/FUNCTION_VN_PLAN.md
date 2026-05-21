# Function-vN Investigation Plan
<!-- TESTS: Function-v5, Function-v6, Function-v7, Function-v8 -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproductions at the current `master` SHA; no fixes
landed yet)

<!-- PLAN_META
id: FUNCTION_VN_PLAN
status: pending
phases:
  - id: 1
    name: "Function class identity / Function global constructor"
    status: complete
  - id: 2
    name: "Function.prototype.call / .apply with non-MC this"
    status: complete
  - id: 3
    name: "typeof on auto-bound this in path-call / SetTarget contexts"
    status: complete
  - id: 4
    name: "Custom toString on user-defined functions (SWF5 vs SWF6+)"
    status: pending
  - id: 5
    name: "arguments object enumeration via Object.addProperty propRecorder"
    status: pending
  - id: 6
    name: "Closure scope: eval-stack survival across function call (case1bis @ Function.as:905)"
    status: pending
  - id: 7
    name: "Primitive auto-boxing __constructor__ chain (Number/String/Boolean)"
    status: pending
  - id: 8
    name: "super-binding property assignments not landing on this (myMail.subject == 'greetings')"
    status: pending
  - id: 9
    name: "Function.__proto__ identity / Function.prototype mutation"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac). Function-v5..v8 became visible at that point."
related:
  - id: GETVARIABLE_VN_PLAN
    reason: "Phase 6 (eval-stack survival) overlaps with getvariable-v5..v8 case at getvariable.as:624 — share the diagnosis."
  - id: OBJECT_VN_PLAN
    reason: "Phase 1 (Function class identity) appears in Object-v6 line 22 (Object.prototype.toString.constructor == Function)."
blockers: []
status_note: |
  All four version variants share the same Gnash test source
  (Function.as); diffs differ by version-gate `#if OUTPUT_VERSION > N`
  but the failure clusters are the same modulo version-conditional
  assertions. Recommend driving Phase 1-9 against Function-v6 as the
  representative test, then re-running v5/v7/v8 to confirm each phase's
  delta. Promotion to ruffle_matched per version is gated on
  per-version `known_failure = true` + `output.fpN.ruffle.txt` (Function-v5
  has output.fp9-14.ruffle.txt and output.fp13-18.ruffle.txt; subset-match
  is in place via SUBTESTS_HARNESS).
-->

## Status

### 2026-05-21 — Phase 7 investigation (no fix landed): two-constructor identity blocker

Investigated cluster G (primitive `a.constructor` / `a.__constructor__`).
Root-caused but did **not** land a fix — the clean fix is a refactor, not
a localized patch. Findings, so the next session can go straight to it:

1. **`Number.prototype.constructor` / `Boolean.prototype.constructor`
   are never set.** `String.prototype.constructor` *is* set (in the lazy
   `g_string_constructor` block in `actionGetVariable`, on a prototype
   shared with `g_ctors[2]`). Number's and Boolean's lazy blocks
   allocate a *fresh* `prototype_obj` and never set `constructor`, so a
   primitive's `n.constructor` walks past the wrapper prototype to
   `Object.prototype.constructor` → resolves to the **Object**
   constructor. (Confirmed via `actionEquals2` instrumentation: the
   `a.constructor == Number` compare is `Number` vs `Object`.)

2. **Two distinct constructor objects per built-in type.** `_global.Number`
   is `&g_ctors[3]` (bound by `REG_FUNC` in `ensureGlobalInit`, a
   function-local `static ASFunction g_ctors[6]`). `actionGetVariable("Number")`
   instead returns `&g_number_constructor` (a *different* function-local
   `static` in `actionGetVariable`, built lazily with `NaN`/`MAX_VALUE`/…).
   `getPrimitiveWrapperProto` resolves the wrapper prototype via
   `_global.Number` → `g_ctors[3].prototype_obj`. So even after setting
   `constructor` on a prototype, `a.constructor` (whatever
   `g_ctors[3].prototype_obj.constructor` points at) and `Number`
   (`g_number_constructor`) are **different pointers** → `==` fails.
   String happens to work only because its lazy block *shares*
   `prototype_obj` with `g_ctors[2]` and sets `constructor` =
   `g_string_constructor` — but that still only works if
   `actionGetVariable("String")` also returns `g_string_constructor`
   (it does; the builtin `_CMP_BUILTIN_NAME` block is reached because
   `getVariable()` checks `var_map`, not `_global`, and misses).

3. **Lazy-init ordering.** Even sharing Number's `prototype_obj` with
   `g_ctors[3]` and setting `constructor` there is too late: `a.constructor`
   (a `GetMember`) is evaluated *before* `Number` (a `GetVariable`) on
   the same line, so on first use the lazy `g_number_constructor` block
   hasn't run yet and the `constructor` own-prop isn't present.

**Recommended fix (next session): unify the per-type constructor.**
Either (a) make `actionGetVariable` for `Number`/`Boolean`/`String`
return the same `g_ctors[N]` object that `_global` and
`getPrimitiveWrapperProto` use (move the `NaN`/`MAX_VALUE`/… statics
onto `g_ctors[3]`, delete the lazy `g_number_constructor`), or (b) hoist
`g_ctors[]` to file scope and have the lazy blocks reuse it. Then set
`constructor` on `g_ctors[N].prototype_obj` **eagerly** in
`ensureGlobalInit`. Once the two objects are one, cluster G's
`a.constructor == Number` line passes; `a.__constructor__` and
`a.hasOwnProperty('constructor'/'__constructor__')` still need the
primitive-box own-property synthesis described below.

Phase 7 also needs, separately: a synthesized `__constructor__` on the
primitive passthrough path (`actionGetMember`, the `_autobox_result == -1`
branch for F32/F64/BOOLEAN and the STRING branch), plus `hasOwnProperty`
returning true for `constructor`/`__constructor__` on a primitive
receiver.

### 2026-05-21 — Phases 2 + 3 landed (apply/call this-binding for type-1 functions)

The whole `Function.prototype.call` / `.apply` cluster (Function.as lines
79–214 on v6) now passes. `Function-v6` went 175 → 205 `#passed`. Three
fixes in `SWFModernRuntime/src/actionmodern/action.c`, in the FUNCTION-receiver
`call`/`apply` handlers of `actionCallMethod`:

1. **Type-1 simple functions now bind `this` via `g_this_stack`.** The
   `function_type == 1` sub-branches of both the `call` and `apply`
   handlers created a local scope and `arguments` object but never bound
   `this`. A type-1 body resolves `this` through `GetVariable("this")`,
   which reads `g_this_stack` (not the `this_obj` pointer arg), so the
   callee saw the *caller's* `this` (the root MovieClip) instead of the
   `thisArg`. Now each path pushes a correctly-typed `this` ActionVar
   (MOVIECLIP via `g_override_this`, else OBJECT via `this_obj`, else
   the boxed primitive) onto `g_this_stack` before invoking
   `simple_func` and restores `g_this_depth` after.

2. **Parameter padding to `param_count`.** A type-1 body unconditionally
   pops `param_count` values off the value stack to bind its named
   parameters. The handlers pushed only the supplied args; when fewer
   args than params were given (`apply()`, `apply(this_ref)`,
   `apply(this_ref, "8")`) the body popped stale values left by a
   previous call. Both handlers now pad with `PUSH(UNDEFINED)` up to
   `param_count` — **with braces**, because `PUSH` is a multi-statement
   macro and a brace-less `for` body only repeats its first statement.

3. **No-thisArg → global object.** `Function.apply()` / `.call()` invoked
   with zero args now resolve `this` to the global object (Flash
   semantics), matching the existing `undefined`/`null` thisArg branch.

No regressions: 34-test AVM1 function/call/scope/closure/super/timer
battery all pass; gnash actionscript.all Object/Inheritance/String/
toString_valueOf/Global-vN all stay `ruffle_matched`; v5/v7/v8 Function
`#passed` unchanged (their residual failures are Phases 4/5/7/8/9).

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| Function-v5 | 135/158 | 85.4% | output_mismatch |
| Function-v6 | 181/271 | 66.8% | output_mismatch |
| Function-v7 | 205/272 | 75.4% | output_mismatch |
| Function-v8 | 205/272 | 75.4% | output_mismatch |

All four ship `output.fpN.ruffle.txt` sidecars with `known_failure = true`
in `test.toml`, so `verify_output.py` will auto-promote to
`ruffle_matched` once our diff is a subset of Ruffle's diff against
the expected output.

## Test source

Gnash testsuite/actionscript.all/Function.as (~1100 lines). The test
exercises ~150 assertions covering:

- Function class identity (`Function`, `Function.prototype`, `Function.__proto__`)
- `Function.prototype.call`, `.apply` with various `this` args
- Custom `toString` override on a function
- `arguments` object (callee, caller, length, enumeration order)
- Inheritance + `super()` in user constructors
- `__constructor__` / `constructor` lookup on instances
- Local-variable scope edges (eval-stack survival across calls;
  closure visibility through paths)
- Per-version differences (SWF5 has no Function class; SWF6 introduces
  `apply`/`call` etc.)

Each version expects a different `#passed/#failed/#total` summary,
gated by `#if OUTPUT_VERSION > N` in the source.

## Failure clusters

Tagged so phase ordering can reference them. Lines below are
zero-based source-line numbers in `Function.as`.

### A. Function class identity (Phase 1) — DONE 2026-05-20

`TestClass.constructor == Function` (Function.as:292) already passed
on Function-v6/v7/v8 — user-class `.constructor` resolves through the
virtual Function.prototype chain. The shared root cause surfaced in
Object-v6 line 71 (`Object.prototype.toString.constructor ==
Function`): `setupNativeFuncOwnProps` stored a self-reference for the
`constructor` slot on native functions' `own_props`. Fixed — see
[[OBJECT_VN_PLAN]] "2026-05-20 #2" status note. Lines 689/713 below
are *not* class identity (they are constructor-on-prototype /
inheritance bugs) and remain open.

Lines: 292, 689, 713 (and similar).

```
- PASSED: TestClass.constructor == Function [./Function.as:292]
+ FAILED: expected: Function obtained: [type Function]
```

`Function` (the global Function constructor reference) must be a
value that prints as `Function` when traced — both upstream tests
explicitly check `TestClass.constructor == Function` and expect that
comparison to PASS. We currently store the global Function constructor
as an `ASFunction` whose `toString()` returns `[type Function]`. Need
to either give it a custom toString, or change the trace formatter
for the singleton `g_function_constructor` so it identifies as
`Function` instead of `[type Function]`.

Affects: Function-v5/v6/v7/v8, also Object-v6 line 22.

### B. Function.prototype.call / .apply with non-MC this (Phase 2)

Lines: 84, 92, 96, 101, 108, 122, 129, 136, 137, 138, 140, 142, 144,
145, 163, 209, 211, 213, 214, 180.

```
- PASSED: getThisName.apply(this_ref) == "extname" [./Function.as:79]
+ FAILED: 0expected: "extname" obtained:
- PASSED: ret == "extname123" [./Function.as:84]
+ FAILED: ret == "extname123"
```

`getThisName` is a function that does `this.name + arguments.join('')`.
When invoked via `getThisName.apply(this_ref)` we are not setting up
`this` correctly — the function body sees `undefined` or `_level0`
instead of `this_ref`. The `isThisGlobal.apply()` cluster (lines
136-145) verifies that `apply()` / `apply(undefined)` / `apply(null)`
all set `this` to `_global` — we are failing all three. Note the
"0expected" leading character in line 11's diff suggests we are
emitting an extra `0` to stdout, probably from a misordered argument
push in the `apply()` invocation path.

### C. typeof on auto-bound this in path-call contexts (Phase 3)

Lines: 184, 185, 188, 191, 192, 195, 198, 199, 202, 802.

```
- PASSED: typeof(ret) == 'object' [./Function.as:184]
+ FAILED: expected: 'object' obtained: movieclip
- PASSED: ret == undefined [./Function.as:185]
+ FAILED: expected: undefined obtained: _level0
```

After certain Function.prototype.call/apply invocations the test
inspects `ret = this` from inside the callee, and expects `typeof(ret)
== 'object'` for the SWF7+ branches but `'movieclip'` for some SWF6
branches. We are returning `movieclip` where `object` is expected and
`_level0` where `undefined` is expected. Likely the same fix as Phase
2 — once `this` is correctly bound to `_global` for the
no-arg-apply/null-this cases, the typeof checks will follow.

### D. Custom toString on user-defined functions (Phase 4)

Lines: 99, 157, 589.

```
- PASSED: typeof(textOutFunc.toString) == 'undefined' [./Function.as:589]
+ FAILED: expected: 'undefined' obtained: function
- custom text rep
+ [type Function]
```

In SWF5 the test sets `textOutFunc.toString = function() { return
'custom text rep'; }` then traces `textOutFunc` and expects `custom
text rep`. We are emitting `[type Function]` — i.e. the global
Function tostring is winning over the per-instance override. In SWF6+
the `typeof(textOutFunc.toString) == 'undefined'` check expects the
default to be undefined (no inherited `toString` on Function
instances) — we report `function`.

### E. arguments object enumeration via Object.addProperty propRecorder (Phase 5)

Lines: 495, 496, 497, 498, 499, 500 (consistent across all four
versions).

```
- FAILED: expected: 5 obtained: 0 [./Function.as:495]
+ FAILED: expected: 5 obtained: 2
- FAILED: expected: '__proto__' obtained:  [./Function.as:496]
+ FAILED: expected: '__proto__' obtained: callee
- FAILED: expected: 'callee' obtained:  [./Function.as:497]
+ FAILED: expected: 'callee' obtained: caller
```

The test installs a `propRecorder.length = 0` counter then walks
`arguments` via `addProperty` getters that increment a counter. Both
expected and actual FAIL at these lines (Gnash itself diverges from
Flash here), but our output produces a different specific failure
pattern. Our `arguments` enumeration order is `callee, caller, ...`
while Gnash's diff captures `__proto__, callee, caller, ...`. Both
diverge from Flash; the cluster likely belongs in
RUFFLE_VS_FLASH_DIFFERENCES.md once we confirm Ruffle's
`output.fpN.ruffle.txt` matches our output and can promote to
`ruffle_matched`.

### F. Eval-stack survival across function call (Phase 6) — shared

Lines: 905, 906, 907 (case1bis), 960, 961, 962 (case2bis).

```
- PASSED: testvar1 == 1 [./Function.as:905]
+ FAILED: expected: 1 obtained: 0
```

Test source pattern (Function.as:883-907):

```
testvar1 = 0; testvar2 = 0; testvar3 = 0;
asm {
    push 'testvar1' push 1
    push 'testvar2' push 2
    push 'testvar3' push 3
};
function stack_test1() { asm { setvariable setvariable setvariable }; }
stack_test1(4, 5, 6);
check_equals(testvar1, 1);   // we get 0
```

The 6 pre-pushed eval-stack values must still be present (underneath
the 3 call arguments) when `stack_test1` enters, so its 3 `setvariable`
ops can consume them. Our implementation appears to truncate the eval
stack to the callee's start-of-frame, dropping the 6 pre-pushed
values. Need to verify whether `actionCallFunction` / `actionDefineFunction2`
saves+restores the entire eval stack or only the call args.

Same pattern appears in `getvariable-vN`'s line `xx == 1` failure
(getvariable.as:624), where a `setvariable '/:xx'` inside a constructor
should write to `_root.xx` while leaving the local `xx` untouched.
That case is **probably a different root cause** (variable-scope
resolution, not eval-stack), but verify in tandem.

Cross-link: [[GETVARIABLE_VN_PLAN]].

### G. Primitive auto-boxing __constructor__ chain (Phase 7)

Lines: 616, 618, 622, 623, 624, 625, 626, 632, 634, 638, 640, 642,
648, 650, 654, 655, 656, 658.

```
- PASSED: typeof(a.__constructor__) == 'function' [./Function.as:616]
+ FAILED: expected: 'function' obtained: undefined
- PASSED: a.constructor == Number [./Function.as:623]
+ FAILED: expected: Number obtained: [type Function]
- PASSED: a.__constructor__ == Number [./Function.as:624]
+ FAILED: expected: Number obtained:
```

`a` is a primitive Number/String/Boolean. Property access on a
primitive auto-boxes (we do this via `getPropertyWithPrototype` in the
primitive path, fix landed 2026-04-16). Currently:

- `a.constructor` returns the global constructor function, which still
  prints as `[type Function]` (Phase A leak).
- `a.__constructor__` returns `undefined` — we don't replicate the
  Flash quirk where primitives synthesize an `__constructor__` property
  that resolves to the same value as `constructor`.
- `a.hasOwnProperty('constructor')` / `'__constructor__'` returns
  false — we don't claim ownership on the primitive box.

Likely needs primitive-specific handling in `hasOwnProperty` plus a
new `__constructor__` synthesis path mirroring the existing
`constructor` lookup.

### H. super property assignment not landing on this (Phase 8)

Lines: 723, 726, 727, 743, 745, 746.

```
- PASSED: myMail.subject == 'greetings' [./Function.as:723]
+ FAILED: expected: 'greetings' obtained: hello
- PASSED: myMail.to == 'you' [./Function.as:726]
+ FAILED: expected: 'you' obtained:
```

Inheritance test: `function Mail(subject) { this.subject = subject; }`
followed by `function Email() { super('greetings'); this.to = ...; ... }`
where `myMail = new Email()`. We are picking up the wrong `subject`
("hello", presumably an earlier instance) and the `to`/`message`
assignments don't land on `myMail` at all. Likely related to the
super-depth bookkeeping (OOP_SUPER_EXTENDS_PLAN) — verify whether the
`super()` call inside `Email` correctly binds `this` to the
prospective Email instance, or whether it creates a new dummy and
discards.

### I. Function.__proto__ identity / Function.prototype mutation (Phase 9)

Lines: 1043, 1049, 1053, 1054, 1076.

```
- PASSED: f.__proto__ === _global.Function.prototype [./Function.as:1043]
+ FAILED: f.__proto__ === _global.Function.prototype
- PASSED: f.__proto__ === backup [./Function.as:1049]
+ FAILED: f.__proto__ === backup
```

The test mutates `Function.prototype` then verifies that pre-existing
function instances see the change via their `__proto__` chain. We
fail every variation. Likely the per-function `__proto__` is
snapshot-captured at definition time rather than chained to a live
`g_function_prototype` singleton.

## Recommended fix order

1. **Phase 1 (Function class identity)** — global, cheap, also unblocks
   one line in Object-v6 and likely a few in Function-v6/v7/v8 fallback
   identity checks. Estimate: 1-2 hours.
2. **Phase 2 (Function.prototype.call/apply this binding)** — unblocks
   the largest chunk of Function-v6/v7/v8 (≈40+ lines each). Phase 3
   probably falls out automatically. Estimate: 3-4 hours.
3. **Phase 7 (primitive __constructor__)** — 18+ lines in Function-v6.
   Estimate: 1-2 hours.
4. **Phase 8 (super property assignment)** — 6 lines per version, but
   touches the super-depth machinery; coordinate with the existing
   OOP_SUPER_EXTENDS work in `avm1/_investigation/complete/`. Estimate:
   2-3 hours.
5. **Phase 6 (eval-stack survival)** — diagnostic-first; if this is
   actually `actionCallFunction` truncating the eval stack on entry
   the fix is small but high-risk for regressions. Coordinate with
   [[GETVARIABLE_VN_PLAN]]. Estimate: 2-3 hours.
6. **Phase 4 (custom toString)** — version-gated (SWF5 vs SWF6+
   behave differently). Estimate: 1-2 hours.
7. **Phase 9 (Function.__proto__ identity)** — requires plumbing
   Function.prototype as a live chain target. Estimate: 2-3 hours.
8. **Phase 5 (arguments enumeration)** — last; probably ACCEPTED_DIFFS
   candidate (both expected and actual already FAIL, just diverging
   on which keys are visible). Estimate: 1 hour decision + maybe 1
   hour fix if achievable.

Total estimate: 14-21 hours of focused work, spread across 4-6
sessions.

## Promotion plumbing

All four tests have `known_failure = true` + sidecar
`output.fpN.ruffle.txt` files, so the test will auto-promote to
`ruffle_matched` once our diffs are a subset of Ruffle's diffs.
Before declaring a phase complete, run the local test and confirm
either a PASS or that our `diff_count` is ≤ Ruffle's `diff_count` AND
all our diff line indices are within Ruffle's diff index set.
