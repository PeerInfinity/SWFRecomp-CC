# registerClass Lifecycle Plan

<!-- TESTS: register_class/registerClassTest, register_class/registerClassTest2, register_class/RegisterClassTest3, register_class/RegisterClassTest4 -->

<!-- PLAN_META
id: REGISTERCLASS_LIFECYCLE
status: pending
phases:
  - id: 1
    name: "prototype.onLoad firing for registered-class MCs (registerClassTest)"
    status: pending
  - id: 2
    name: "constructor proto-chain fallthrough to MovieClip when prototype.constructor is unset"
    status: pending
  - id: 3
    name: "Constructor frame-timing — defer until placement frame, not eager at PlaceObject2"
    status: pending
  - id: 4
    name: "Construct/load/unload cycle ordering on remove+replace (RegisterClassTest4)"
    status: pending
  - id: 5
    name: "Multi-clip onLoad / frame0 ordering (registerClassTest2 frame interleave)"
    status: pending
dependencies: []
blockers:
  - reason: "None — Object.registerClass infrastructure is already complete (AVM1 REGISTERCLASS_PLAN.md, 14/15 AVM1 tests pass). The Gnash misc-ming tests exercise edges the AVM1 tests don't cover: prototype.onLoad firing, constructor proto-chain fallthrough, frame-timing precision, and remove+replace cycling. Each phase is a narrow extension to the existing infrastructure."
-->

## Background

The AVM1 `REGISTERCLASS_PLAN.md` (in `complete/`) covered the core
`Object.registerClass` infrastructure: ExportAssets parsing, attachMovie
dispatch, prototype setup, constructor invocation, DoInitAction
ordering, and `on(construct)`. **14 of 15 AVM1 registerClass tests pass**
(only `register_class` itself fails, blocked on button MC typeof + child
SWF loading — covered separately by `BUTTON_INFRASTRUCTURE_PLAN.md`).

The 4 Gnash misc-ming registerClass tests cover edges the AVM1 suite
doesn't:

| Test | Match | Edge tested |
|------|-------|------------|
| `register_class/registerClassTest` | 2/51 (3.9%) | `prototype.onLoad` firing as a clip-event-style handler |
| `register_class/registerClassTest2` | 9/44 (20.5%) | `constructor` proto-chain fallthrough; multi-clip frame0/onLoad interleave |
| `register_class/RegisterClassTest3` | 2/12 (16.7%) | Frame-timing precision of constructor invocation |
| `register_class/RegisterClassTest4` | 8/42 (19.0%) | Construct → load → unload cycle on remove+replace |

**Estimated impact:** All four tests pass primarily on per-line-shift
issues caused by 1–2 missing or out-of-order events. After Phases 1–4,
all four should reach high match rates with possible full PASS for
registerClassTest and RegisterClassTest3 (small expected outputs); 2 and
4 are larger and may need Phase 5 mop-up.

## Phase 1 — `prototype.onLoad` for registered-class MCs

**Problem.** registerClassTest is missing exactly one expected line:

```
  1  PASSED: typeof(registerClassRet) == 'boolean'
  2  PASSED: registerClassRet == true
- 3  _level0.square2.onLoad called   ← missing in actual
  ... (rest of expected lines all match, just shifted by 1)
```

The test does:

```as
function MyClass() { ... }
MyClass.prototype.onLoad = function() { trace(this + ".onLoad called"); };
Object.registerClass("square", MyClass);
// (square is a placed MC; when it loads, prototype.onLoad should fire)
```

Flash fires `prototype.onLoad` on the registered-class MC when the MC's
LOAD clip event would normally fire (just after construction, on the
first frame the MC is on stage). Our runtime fires the constructor
(via `actionInvokeRegisteredClassConstructor`,
`registered_class.c:237`) but doesn't dispatch
`mc.dynamic_props.__proto__.onLoad` afterward.

**Fix.** After `actionInvokeRegisteredClassConstructor` returns, look up
`onLoad` on the MC's prototype chain (i.e. the registered-class
prototype). If it's a function, invoke it with `this = mc` and no
arguments. This mirrors the existing AS-level `onLoad` clip-event
dispatch path. The lookup should walk:

1. `mc->dynamic_props` own properties (instance-level override).
2. `mc->dynamic_props.__proto__` (the registered class's prototype).
3. `MovieClip.prototype` (fallback).

The dispatch should happen at the same point in the lifecycle as the
"clip onLoad event" — between the constructor and the first frame's
DoAction. Per `register_and_init_order`'s passing semantics
(233/233), this point is well-defined; the new dispatch slots in
beside it.

**Site.** Either inside
`actionInvokeRegisteredClassConstructor` (fire after constructor
returns) or as a separate call site at the same drain point. Spec
says these fire as part of LOAD event dispatch — see
`SWFModernRuntime/src/libswf/swf_core.c` for clip-event LOAD dispatch
(search `CLIP_EVENT_LOAD`). The registered-class `prototype.onLoad`
should fire alongside.

**Risk.** Low. New dispatch is purely additive. Required-pass
guardrail must keep the 14 passing AVM1 registerClass tests green —
`register_class_return_value`, `attach_movie`, `on_construct`,
`register_and_init_order` (the long test), `clip_constructors`,
`movieclip_init_object`, `do_init_action_child`, etc.

### 2026-04-27 investigation: dispatch already wired, but trace lost

`actionQueueMCOnLoad(child_mc)` is already called for timeline-placed
RegisterClass sprites at `tag.c:570-571` (no code change needed there).
`actionDispatchMCOnLoad` runs for square2 in registerClassTest, finds
`prototype.onLoad` via `getPropertyWithPrototype` (type=13 FUNCTION),
and invokes `simple_func`. Body runs (we know because line 4 expected
`_root.onLoadCalled.length == 1` PASSES — i.e. `_root.onLoadCalled.push(this)`
inside the handler ran). But the `note(this+'.onLoad called')` trace
never appears in the output.

The body is:
```js
CustomClass.prototype.onLoad = function() {
  note(this+'.onLoad called');           // <— trace lost
  _root.onLoadCalled.push(this);          // <— this ran
};
```

`this` inside the handler is correctly the MC (we know because `push(this)`
ended up storing a reference whose toString resolves to `_level0.square2`).
So the failure is *not* `this`. Two hypotheses, neither verified yet:

1. **`note` lookup fails silently.** The handler is type 1 (DefineFunction
   with no registers / preload flags). `actionDispatchMCOnLoad`'s type-1
   branch invokes `simple_func` directly without pushing a local activation
   ASObject onto `scope_chain` and without restoring `func->captured_scope[]`.
   For a closure-captured `note` reference (mtasc/Ming may compile `note(...)`
   as a free-variable lookup that walks captured scopes), the captured
   `_root.note` binding goes missing.
2. **Trace timing race vs. close-of-output.** Less likely — `_root.note`
   uses `_root.xtrace` + `trace`, both of which feed stdout, and other
   `note` calls *do* show up in this same test (the `s == 'onLoad,onRollOver,'`
   line at 27, etc., is a check_equals which goes through note/fail path).

Hypothesis 1 is the one to pursue. The fix is to mirror the type-1 setup
that `actionCallFunction` does: allocate a fresh local activation, push it
onto `scope_chain` (with `scope_is_with[i] = 0`, `scope_mc[i] = mc`),
restore `func->captured_scope_count` captured WITH scopes, push `this`
onto `g_this_stack`, and tear it all down on return. The shape is identical
to `actionInvokeRegisteredClassConstructor`'s type-1 branch
(`registered_class.c:263-311`) — that path is known to work.

After Phase 1 is shipped, expect:
- `registerClassTest`: 2/51 → ~40+/51 (the missing line 3 plus the
  cascading off-by-one diffs collapse).
- Other tests largely unaffected (Phase 1 is timeline-RC-specific).

## Phase 2 — `mc.constructor` proto-chain fallthrough

**Problem.** registerClassTest2 line 7:

```
  expected: PASSED: clip1.constructor == MovieClip
  actual:   FAILED: expected: MovieClip obtained: [type Function]
```

The test sets up two registered classes:

```as
function theClass1() {}
// theClass1.prototype intentionally NOT given a `constructor` property
function theClass2() {}
theClass2.prototype.constructor = theClass2;  // explicit
```

Expected: `clip1.constructor == MovieClip` (falls through past
`theClass1.prototype.constructor` since it's unset, lands on
`MovieClip.prototype.constructor` which is `MovieClip`).
`clip2.constructor == theClass2` (explicit).

Our actual: `clip1.constructor` returns "[type Function]" (the
ASFunction toString). Some Function — likely `theClass1` itself —
got returned via the wrong fallback path.

**Hypothesis.** When resolving `mc.constructor`:

- Step 1: walk `mc.dynamic_props` for own `constructor`. Not found.
- Step 2: walk `mc.dynamic_props.__proto__` (which is
  `theClass1.prototype`). Look for `constructor`. **Bug here:** we
  may be returning `theClass1` itself (because
  `actionSetupRegisteredClassPrototype` in `registered_class.c:219`
  installs `constructor → ctor_func` on the **prototype object**:
  ```c
  setProperty(app_context, ctor_func->prototype_obj, "constructor", 11, &ctor_var);
  ```
  This is unconditional — even when the test user DIDN'T set
  `theClass1.prototype.constructor` — so subsequent lookups find the
  installed reference and never reach `MovieClip.prototype`.

**Fix.** `actionSetupRegisteredClassPrototype` should NOT install
`constructor` on the prototype if the user-supplied function's
`prototype_obj` already exists with its own props (or, more
specifically, only install when the user didn't already configure the
prototype). Better: install with a marker flag (e.g.
`PROPERTY_FLAGS_DEFAULT_INSTALLED`) that the lookup chain treats as
"keep walking" so user-explicit `constructor` props win and unset
ones fall through.

Or simpler: don't auto-install `constructor` on the user's prototype
at all. Let the user decide. The Flash semantics: a function's
`prototype.constructor` is unset by default; users who want it set
do so explicitly.

```c
// registered_class.c:215-220 — REMOVE the auto-install of
// `prototype.constructor` since Flash doesn't do it for user functions:
- ActionVar ctor_var;
- ctor_var.type = ACTION_STACK_VALUE_FUNCTION;
- ctor_var.str_size = 0;
- ctor_var.data.numeric_value = (u64) ctor_func;
- setProperty(app_context, ctor_func->prototype_obj, "constructor", 11, &ctor_var);
```

Audit: confirm no other test relies on the auto-install. Cross-check
`register_class_return_value`, `register_and_init_order`,
`movieclip_init_object`, `clip_constructors` — these all pass; if
any reads `prototype.constructor` they may regress.

**Risk.** Medium. `prototype.constructor` is a load-bearing
convention in many AS2 codebases. Need to verify the actual Flash
behavior — does `new MyClass().constructor` return MyClass or
undefined when `MyClass.prototype.constructor` is unset?

Per ECMAScript-3 (which AS2 follows): `Function.prototype.constructor`
**is** auto-installed when a function is declared. So the issue isn't
whether to install — it's that registered-class proto installation is
overwriting what the user already had (or installing onto the
function's `prototype` object even when the user had set a different
prototype).

Re-read the failing diff: clip2 (which DID `theClass2.prototype.constructor =
theClass2`) gets `theClass2` correctly. clip1 (which DIDN'T) returns
"[type Function]" — that's `theClass1`. So our auto-install at
`registered_class.c:219` is overriding the implicit ECMAScript-3
default that **would** be `theClass1` (which is what we have). Wait,
that means our value IS what ECMA would produce — but the test
expects `MovieClip` instead.

**Re-hypothesis:** The Flash behavior here may be: when a registered
class's prototype object is the *new* fresh ASObject we create (line
212 — `ctor->prototype_obj = allocObject(...)`), the user doesn't
have a `theClass1.prototype.constructor` because they never touched
the freshly-allocated proto — so `clip1.constructor` walks past
the empty proto into MovieClip's. We should NOT initialize
`ctor->prototype_obj` ourselves — the user creates it (typically by
declaring the function, which auto-creates a prototype). Our line
210 `if (ctor_func->prototype_obj == NULL)` only fires when the
user-defined function has no prototype, which would be unusual.

**Investigation step:** Print `ctor_func->prototype_obj` at the
registerClass entry in registerClassTest2 to confirm whether
theClass1's prototype already exists (allocated by `function
theClass1()` declaration) or whether our code is creating a fresh one.
The answer determines the fix.

## Phase 3 — Constructor frame-timing

**Problem.** RegisterClassTest3 expected:

```
  Registered class
  frame 1
  frame 3              ← frame 3 reached BEFORE constructor fires
  PASSED: c == 0       ← counter still 0
  PASSED: i == 0
  PASSED: _root.mc2 == undefined  ← mc2 NOT yet placed
  onInitialize         ← NOW the constructor fires (mc2 placed at frame ≥ 3)
  Object ID 2 is constructed
  frame 5
  PASSED: c == 1       ← counter incremented once
  ...
```

Our actual:

```
  Registered class
  frame 1
  onInitialize          ← WRONG: fires at frame 1
  Object ID 2 is constructed
  frame 3
  PASSED: c == 0        ← passes (we report c==0, but actually ours just resets between frames?)
  FAILED: i obtained 1  ← i was incremented by the early ctor
  PASSED: _root.mc2 == undefined
  onInitialize          ← extra second invocation
  Object ID 2 is constructed
  frame 5
  FAILED: c expected 1 obtained 0
  FAILED: i expected 1 obtained 2
```

**Hypothesis.** The registered-class constructor for `mc2` fires at
PLACEMENT time (when the SWF parses the PlaceObject2 tag for mc2 in
frame 1), not when mc2 should actually become live (frame 3 or
later — wherever its placement frame is).

This contradicts the constructor-firing path in
`fire_eager_constructors` (`tag.c:3208`), which is supposed to fire
at the right moment per the Phase 5 ActionQueue migration (per
the comment "constructors now queue through the ActionQueue at
placement time"). But "placement time" might be parsing time, not
display-frame time.

**Fix.** Defer the registered-class constructor invocation until the
PlaceObject2 tag's frame is the current frame. If the test's mc2 is
placed at frame 3 (via PlaceObject2 inside frame 3's tag stream), the
constructor should fire when the runtime reaches frame 3 — not when
the recompiled `tagPlaceObject2(...)` call runs (which may be
out-of-order due to catch-up replay).

Read the existing
`actionInvokeRegisteredClassConstructor` queueing setup
(`tag.c:3267+` and the AQ_KIND_REGISTER_CTOR drain points) and
confirm whether the queue dispatch fires within the correct frame
context. This may be a catch-up-mode interaction: during catch-up
replay, registered-class constructors should NOT fire (they fire
naturally when the live frame is processed).

**Risk.** Medium-high. Constructor firing is heavily overloaded:
fires on placement, on attachMovie, on duplicateMovieClip, on
sprite-init replays, etc. Changing the frame-timing requires careful
audit. Required-pass guardrail: `register_and_init_order` (233/233).

## Phase 4 — Construct/load/unload cycle ordering

**Problem.** RegisterClassTest4 cycles a registered-class MC through
construct → load → unload → re-construct → load → ... and tracks via
counter. Our diff shows:

```
  expected:                        actual:
- 4  load _level0.mc.Segments c: 0  + 4  1 0
- 5  1 0                            + 5  load _level0.mc.Segments c: 0
                                          ↑ load fires AFTER our DoAction "1 0"
                                            (Flash fires it before)
- 11  load c: 1                     + 11  1 undefined  ← counter lost
- 12  1 0                           + 12  2 undefined  ← counter lost
- 13  2 1                           + 13  1 undefined  ← counter lost
```

Two issues:

1. **Load event fires too late.** Expected: load → DoAction "1 0".
   Actual: DoAction "1 0" → load. Same family as
   `DEFERRED_CLIP_UNLOAD_PLAN` but for LOAD instead of UNLOAD.
2. **Counter lost across cycle boundary.** `_global.real` (or
   wherever the counter is stored) reads as `undefined` after the
   first construct/load/unload pass, suggesting either:
   - The MC is destroyed and recreated in a way that resets `_global`
     references — unlikely, `_global` is process-scope.
   - The DoAction reading `_global.real` happens BEFORE
     `_global.real` is initialized by the constructor — i.e. an
     ordering bug between constructor and DoAction firing.

**Fix.**

- Sub-issue 4a (load timing): integrate registered-class load events
  into the same ActionQueue pass that currently handles
  CLIP_EVENT_LOAD. Confirm
  `actionInvokeRegisteredClassConstructor` runs BEFORE the first
  DoAction for the placed MC.
- Sub-issue 4b (counter): trace through the 8/42 line counts to
  identify the exact `_global` write that's missed. Likely overlaps
  the DEFERRED_CLIP_UNLOAD ordering (the unload handler writes a
  value, our pre-deferred ordering means the value is written too
  late — DoAction reads it before write).

**Risk.** High. This test exercises the entire registered-class
lifecycle in a tight loop; any single ordering change has many
downstream consequences. Tackle after Phase 1–3 land.

## Phase 5 — Multi-clip onLoad / frame0 ordering (registerClassTest2)

**Problem.** registerClassTest2 actual emits:

```
+ 1  _level0.clip3.frame0 actions      ← fires BEFORE the assertion block
+ 2  _level0.clip3.onLoad (theClass3 proto)
   3  PASSED: typeof(clip1) == 'movieclip'  ← assertion block starts here in expected, line 1
   ...
```

Three clips (clipevs, clip3, noclipevs) are placed at depths
1, 2, 3 with the same registered class theClass3. Expected onLoad
ordering: clipevs → clip3 → noclipevs (depth ascending).
Frame0-actions ordering: clipevs → noclipevs → clip3 (different —
matches DoAction tag order).

Our test has clip3.frame0 firing FIRST, before any of the
assertions. This suggests the frame0 DoAction for clip3 (a sprite)
fires during sprite-eager-init, before the root's main DoAction
that contains the assertions.

**Hypothesis.** Sprite-eager-init currently fires the sprite's frame0
DoAction at `PlaceObject2` parse time, but Flash defers it (queues
via the Phase 7b AQ_KIND_SCRIPT path). Our impl might be missing
the queuing for THIS specific test's sprite structure — possibly
because the registered-class CONSTRUCTOR is intercepting the
sprite's normal flow.

**Fix.** Audit how registered-class clips integrate with the existing
sprite frame0 DoAction queueing
(`actionEagerInitActive`,
`actionDeferredSpriteInitActive` —
`SWFModernRuntime/include/actionmodern/action_queue.h:142-159`).
Confirm registered-class MCs follow the same eager-init pathway as
non-registered sprites.

**Risk.** Medium. Adjacent to existing ActionQueue work.

## Verification battery

**Required-pass guardrail (all phases):**

- AVM1: `register_class_return_value`, `register_globals_across_frames`,
  `register_underflow`, `attach_movie`, `attach_movie_stop`,
  `export_assets`, `clip_constructors`, `on_construct`,
  `movieclip_init_object`, `empty_movieclip_can_attach_movies`,
  `do_init_action_child`, `register_class_with_sound`,
  `register_and_init_order` (233/233 — most fragile).
- Gnash misc-ming recently-fixed: `attachMovieTest`, `attach_movie`,
  `init_object_order`, `init_object_invalid`,
  `attach_movie_stop`, `bad_placeobject_clipaction`,
  `movieclip_in_removed_button`, `clip_events`, `loop_test3`,
  `loop_test5` — must remain green.
- Shumway: `from_shumway/avm1/register_and_init_order`-style tests
  if any.

**Target tests:**

- Phase 1: registerClassTest +1 line, full diff shift recovered →
  potentially full PASS (depends on residual line-by-line content
  after the shift).
- Phase 2: registerClassTest2 line 7 PASS (the constructor
  fall-through line).
- Phase 3: RegisterClassTest3 from 2/12 to potentially 12/12 (small
  test, all blocked on the same frame-timing issue).
- Phase 4: RegisterClassTest4 from 8/42 to higher; full PASS unlikely
  on first attempt.
- Phase 5: registerClassTest2 ordering recovers, lines 1–2 shift to
  the right position; remaining diff narrows substantially.

## Open questions

1. **Phase 2 hypothesis is uncertain.** Need to confirm Flash's
   actual behavior on `function MyClass() {}; new MyClass().constructor`.
   ECMA-3 spec says it returns `MyClass`, but Flash may differ when
   the class is registered via `Object.registerClass` (which does
   prototype manipulation). Run a test SWF locally or consult the
   Flash AS2 reference.
2. **Phase 3 vs `register_and_init_order` (the AVM1 233/233 test).**
   That test passes perfectly — so the existing constructor-timing
   is correct for that scenario. RegisterClassTest3's failure must
   be about a different timing axis. Possibly the difference is
   PlaceObject2 in a goto-target frame vs the main timeline.
3. **Phase 4 overlap with `DEFERRED_CLIP_UNLOAD_PLAN`.** The load
   timing issue in 4a is dual to the unload deferral problem. May
   be cleaner to solve both together in a single ActionQueue audit
   pass — or land the unload plan first then revisit 4a.

## Estimated session budget

- Phase 1: 1–2 hours (locate dispatch site, add prototype.onLoad
  invocation, run battery).
- Phase 2: 2–3 hours (investigate prototype.constructor, confirm
  Flash semantics, fix and validate against AVM1 tests).
- Phase 3: 3–4 hours (constructor frame-timing audit; high
  cross-test risk).
- Phase 4: 4+ hours (cycle ordering; depend on
  DEFERRED_CLIP_UNLOAD_PLAN status).
- Phase 5: 2 hours (sprite frame0 ordering audit).

Phase 1 is the cheapest and most isolated; Phase 3 has the highest
test impact (RegisterClassTest3 is small and could fully pass).
Tackle in order 1 → 2 → 3 → 5 → 4.

## Why this is the right shape

The AVM1 REGISTERCLASS plan completed the **happy path**:
register a class, attach a movie, fire the constructor, set up the
prototype chain, propagate clip events. The Gnash misc-ming
registerClass tests probe **lifecycle edges** that the AVM1 suite
doesn't:

- `prototype.onLoad` as an event handler (Phase 1).
- `constructor` proto-chain semantics (Phase 2).
- Construct timing relative to PlaceObject2 frames (Phase 3).
- Construct/load/unload cycling (Phase 4).
- Multi-instance ordering (Phase 5).

Each phase is a narrow extension. Phases 1–2 are unrelated to the
existing unload/depth-bias/button blockers. Phases 3–5 share
ordering DNA with `DEFERRED_CLIP_UNLOAD_PLAN.md` — once that lands,
Phases 3–5 may simplify or reveal as duplicates.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `complete/REGISTERCLASS_PLAN.md` | Predecessor plan that built the core infrastructure. This plan extends it for lifecycle edges. |
| `MISC_MING_SWFC_PLAN.md` "Cluster: register_class/* (4 tests, 4-21%)" | Listed these tests as "exercise edges not covered by AVM1 tests"; this plan is the concrete triage. |
| `DEFERRED_CLIP_UNLOAD_PLAN.md` | Phase 4 of this plan likely overlaps. Land that plan first if attacking Phase 4. |
| `BUTTON_INFRASTRUCTURE_PLAN.md` | Independent. The 1 remaining AVM1 register_class test is blocked there, not here. |
