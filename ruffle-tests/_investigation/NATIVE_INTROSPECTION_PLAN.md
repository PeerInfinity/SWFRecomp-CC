# Native Object/Function Introspection Implementation Plan

Last updated: 2026-02-14

## Overview

This category covers 5 tests that probe the internal "native-ness" of built-in Flash objects, test subclassing of native types, and verify double-construction behavior. These are meta-tests — they don't test a single feature but rather the overall fidelity of the built-in class system.

**Current state**: All 5 tests produce 0% matching lines. The `native_objects_swfN` tests produce no output at all (the `getNativeStatus` function crashes or silently fails early). The `native_subclasses` test runs but `super()` calls don't work ("Unsupported number of args: undefined"). The `native_double_construct` test runs partially but `BlurFilter` constructor doesn't initialize properties.

**Key insight**: These tests have enormous dependency surfaces. The `native_objects` tests call `new ClassName()` on 50+ classes and the `native_subclasses` test subclasses 27 classes. Rather than trying to implement every class just for these tests, the plan focuses on the **infrastructure** that makes native introspection work, with stub class registrations to get tests running now and full implementations coming incrementally from other feature categories.

## Tests

| Test | Lines | Current | Description |
|------|-------|---------|-------------|
| native_objects_swf6 | 84 | 0/84 (0%) | Check native status of every built-in class (SWF6) |
| native_objects_swf7 | 84 | 0/84 (0%) | Same for SWF7 (adds `new TextField(): native`) |
| native_objects_swf8 | 84 | 0/84 (0%) | Same for SWF8 (adds flash.* packages with native filters) |
| native_subclasses | 192 | 0/192 (0%) | Subclass 27 built-in classes and verify behavior |
| native_double_construct | 12 | 4/12 (33%) | Call super() twice on BlurFilter — second call is no-op |

**Note**: The `native_objects_swfN` tests have `known_failure = true` in their test.toml, but our `verify_output.py` runner does not check this flag, so they count as regular failures.

---

## Test Mechanics

### native_objects_swfN — The getNativeStatus Algorithm

The test defines two functions: `getNativeStatus(obj)` and `check(label, obj)`. For each built-in class, it calls `check("new ClassName()", new ClassName())` which traces `label + ": " + getNativeStatus(obj)`.

The `getNativeStatus` function (from decompiled bytecode):

1. If `typeof(obj) !== "object"`, return `"non-object: " + typeof(obj)`
2. Set `obj.__initializeNative = <anonymous function>` — the anonymous function does:
   - Set `this.__proto__ = { __constructor__: Date, __proto__: Date.prototype }` (swap prototype to Date chain)
   - Sanity-check `typeof(this.getDate) === "function"` (should be true from Date.prototype)
   - Call `this.getDate()` — if `typeof(result) !== "undefined"`, that's an ERROR
   - Call `_root[undefined]()` (no-op call, probably a Flash Player internal hook)
3. Call `obj.__initializeNative()` — executes the anonymous function above
4. Check `typeof(obj.getDate) === "function"` — should be true after prototype swap to Date
5. Call `obj.getDate()` and check `typeof(result)`
6. Based on whether `getDate()` returns undefined or a real value, return `"native"` or `"non-native"`

The core detection mechanism: after swapping `__proto__` to Date and calling `__initializeNative()`:
- **Native objects** (Array, String wrapper, etc.): The native backing prevents Date re-initialization. `getDate()` returns undefined. Result: **"native"**
- **Non-native objects** ({}, Error, ContextMenu, etc.): No native backing, so Date re-initialization takes effect. But since there's no actual Date time data, `getDate()` also returns undefined... unless Flash Player's `__initializeNative` has special behavior that we need to replicate exactly.

**Implementation approach**: Rather than trying to exactly replicate the `__initializeNative` detection algorithm (which depends on Flash Player internals), we can take a simpler approach — hardcode the native/non-native classification for each constructor and make `__initializeNative()` behave accordingly. The test is checking a fixed set of classes and the expected output is deterministic.

### Expected Native/Non-Native Classification

**Native** (objects with native C backing):
- Array, String, Number, Boolean (wrapper objects)
- Button, LoadVars, LocalConnection, MovieClipLoader, PrintJob, Sound
- TextField (SWF7+), TextFormat
- TextSnapshot (only with MovieClip arg: `new TextSnapshot(_root)`)
- XML, XMLNode (with 2+ args: `new XMLNode(1, "name")`)
- flash.display.BitmapData (with valid args)
- flash.filters.* (all except BitmapFilter base class)
- flash.geom.ColorTransform, Transform (with MovieClip arg)

**Non-native** (pure AS objects, no native backing):
- Object, Error, Camera, ContextMenu, ContextMenuItem, Function, Microphone
- MovieClip (constructor), NetStream, TextSnapshot (without MovieClip arg), Video, XMLSocket
- XMLNode (with 0-1 args), flash.filters.BitmapFilter (base class)
- flash.geom.Matrix, Point, Rectangle

**Non-object** (typeof !== "object"):
- Primitives: string, number, boolean, null, undefined
- MovieClip variables (typeof = "movieclip")
- SharedObject (typeof = "function" — it's a static class)
- flash.display.BitmapData() without args, flash.geom.Transform() without args, flash.text.TextRenderer() (return undefined)
- In SWF6: `new TextField()` returns undefined

### SWF Version Differences

| Class | SWF6 | SWF7 | SWF8 |
|-------|------|------|------|
| `new TextField()` | `non-object: undefined` | `native` | `native` |
| `flash.display.BitmapData(1,1)` | `non-object: undefined` | `non-object: undefined` | `native` |
| All `flash.filters.*` | `non-object: undefined` | `non-object: undefined` | `native` (except BitmapFilter: `non-native`) |
| `flash.geom.ColorTransform()` | `non-object: undefined` | `non-object: undefined` | `native` |
| `flash.geom.Matrix/Point/Rectangle` | `non-object: undefined` | `non-object: undefined` | `non-native` |
| `flash.geom.Transform(_root)` | `non-object: undefined` | `non-object: undefined` | `native` |

In SWF6/7, `flash.*` package doesn't exist, so `new flash.filters.BlurFilter()` → constructor not found → returns undefined → `non-object: undefined`.

### native_subclasses — Subclass + super() Pattern

The test defines a `Test` constructor and for each of 27 built-in classes:
1. Creates `new Test()`
2. Sets `obj.__proto__` to the target class's prototype
3. Sets `obj.__constructor__` to the target class constructor
4. Sets `obj.isSubclass = true`
5. Calls `super(args...)` — invokes the target class's constructor on `this`
6. Traces `super(args): <result>` showing the return value
7. Checks `obj.isSubclass === true` (should persist)
8. Checks `obj instanceof TargetClass === true`
9. For some classes, checks class-specific properties (e.g., `obj.blurX` for BlurFilter)

**Current failure**: The `super()` call doesn't work. The recompiled script calls `_root[undefined]()` which is how MTASC compiles `super()` — it resolves `__constructor__` from the prototype chain and calls it. Our runtime doesn't handle this pattern, producing "Unsupported number of args: undefined" and the super constructor never runs.

### native_double_construct — Double Init Protection

Uses `actionExtends` to subclass `flash.filters.BlurFilter`. Constructor calls `super(10, 20, 4)`, verifies `blurX=10, blurY=20, quality=4`, then calls `super(20, 10, noisyFive)` again. The second super call:
- DOES execute side effects (noisyFive.valueOf traces "valueOf called!")
- Does NOT re-initialize the native backing (blurX/blurY/quality remain 10/20/4)

---

## Dependencies and Prerequisites

### Infrastructure (must be built)

| Feature | Current State | Needed For | Cross-cutting benefit |
|---------|--------------|------------|----------------------|
| `super()` call mechanism | Not working — `_root[undefined]()` pattern not handled | native_subclasses, native_double_construct | OOP/Super/Extends tests (7 tests) |
| `__proto__` assignment via SetMember | Probably broken — causes zero output | native_objects_swfN | Many tests that manipulate prototypes |
| `__constructor__` property | Not tracked on objects | native_objects_swfN, native_subclasses | Prototype chain correctness |
| `__initializeNative()` method | Not implemented | native_objects_swfN | Only these tests |
| Native backing flag on objects | Not implemented | native_objects, native_double_construct | Only these tests |
| Double-construct protection | Not implemented | native_double_construct | Only this test |
| Stub constructors for missing classes | ~20 classes missing | native_objects_swfN | Global registration tests (12 tests) |

### Currently Registered Constructors

Already implemented as globals:
- **g_ctors array** (init-time): Object, Array, String, Number, Boolean, Function
- **Lazy-init** (on first access): MovieClip, TextField, TextFormat, Error, XML, XMLNode
- **Objects** (non-constructor): System, flash (with display.BitmapData, geom.Point/Matrix/Rectangle/ColorTransform)

Missing constructors needed:
- Button, Camera, ContextMenu, ContextMenuItem, LoadVars, LocalConnection
- Microphone, MovieClipLoader, NetStream, NetConnection, PrintJob, SharedObject
- Sound, TextSnapshot, Video, XMLSocket, Date (constructor exists but no methods)
- flash.filters.* (10 filter classes), flash.geom.Transform, flash.text.TextRenderer
- TextField.StyleSheet, flash.net.FileReference

---

## Implementation Plan

### Phase 0: Fix Zero-Output Crash in native_objects Tests

**Goal**: Get the `native_objects` tests to run to completion and produce 84 lines of output.

The tests currently produce zero output. The `getNativeStatus({})` call on the very first test case fails silently. The most likely causes:
1. Setting `obj.__initializeNative = function() { ... }` via SetMember on a plain object fails
2. Inside the anonymous function, setting `this.__proto__` via SetMember fails or corrupts memory
3. Looking up `Date` via GetVariable fails (Date constructor is a stub, prototype may be missing)
4. `Date.prototype` is undefined/missing, causing crash when used as `__proto__`

**Tasks**:
1. Debug why `getNativeStatus({})` produces no output — add DEBUG traces or run under valgrind
2. Ensure `__proto__` assignment works via `actionSetMember` on any ASObject
3. Ensure Date constructor exists as a global with a valid `.prototype` object
4. Ensure method calls on objects with swapped `__proto__` don't crash

**Expected result**: Tests produce 84 lines. The "non-object" lines (typeof checks) should mostly match. The "native"/"non-native" lines will all be wrong (probably all "non-native" since __initializeNative is a no-op).

**Tests impacted**: native_objects_swf6/7/8 (0% → ~25-30% — the ~20 "non-object" lines should match)

### Phase 1: Register Missing Stub Constructors

**Goal**: Make `new ClassName()` return a proper object for all classes the tests check.

For native_objects tests, many lines fail simply because the constructor doesn't exist (so `new ClassName()` returns undefined → `"non-object: undefined"`). We need stub constructors that:
1. Return an object (not undefined)
2. Set `__proto__` to the constructor's `.prototype`
3. Set the correct `typeof` (always "object" for constructors)

**Classes to add as stubs** (constructors that just create an empty object with correct prototype):

| Class | Expected Result | Notes |
|-------|----------------|-------|
| Button | native | Constructor exists in globals |
| Camera | non-native | |
| ContextMenu | non-native | |
| ContextMenuItem | non-native | With optional args |
| LoadVars | native | |
| LocalConnection | native | |
| Microphone | non-native | |
| MovieClipLoader | native | |
| NetStream | non-native | |
| NetConnection | non-native (not constructed directly) | Used as arg to NetStream |
| PrintJob | native | |
| Sound | native | With optional target arg |
| TextSnapshot | varies | native only with MovieClip arg |
| Video | non-native | |
| XMLSocket | non-native | |

**flash.* package stubs** (SWF8 only):

| Class | Expected Result | Notes |
|-------|----------------|-------|
| flash.filters.BevelFilter | native | |
| flash.filters.BitmapFilter | non-native | Base class |
| flash.filters.BlurFilter | native | Also needed for native_double_construct |
| flash.filters.ColorMatrixFilter | native | With optional matrix arg |
| flash.filters.ConvolutionFilter | native | With optional args |
| flash.filters.DisplacementMapFilter | native | With optional args |
| flash.filters.DropShadowFilter | native | |
| flash.filters.GlowFilter | native | |
| flash.filters.GradientBevelFilter | native | |
| flash.filters.GradientGlowFilter | native | |
| flash.geom.Transform | native (with MovieClip arg) | Returns undefined without arg |
| flash.text.TextRenderer | non-object: undefined | |
| flash.net.FileReference | (native_subclasses only) | |
| TextField.StyleSheet | (native_subclasses only) | |

**Implementation approach**: Add these to the lazy-init block in `actionGetVariable` / `actionNewObject` in `action.c`. Each stub:
```c
case "LoadVars":
    obj = allocObject(app_context, 0);
    // Set __proto__ to LoadVars.prototype
    // Mark as native_type = NATIVE_LOADVARS (for Phase 2)
    break;
```

**Expected result**: The `non-object: undefined` lines for SWF8 flash.* classes now become correct `native`/`non-native` results (once Phase 2 implements the detection). For SWF6/7, these lines already match (`non-object: undefined`) since flash.* doesn't exist.

**Tests impacted**:
- native_objects_swf6/7: Improved (stubs for non-flash classes)
- native_objects_swf8: Significantly improved (flash.* stubs)
- native_subclasses: Can now create instances of all 27 classes
- Also helps: globals_swf5/6/7/8 tests (12 tests in "Global Built-in Functions" category), bitmap_filters test, sound_props tests

### Phase 2: Native Backing + __initializeNative Detection

**Goal**: Implement the native/non-native detection that `getNativeStatus` probes.

**Design**: Add a `native_type` enum field to `ASObject`:

```c
// Native type enum (0 = none/pure-AS)
enum NativeType {
    NATIVE_NONE = 0,
    NATIVE_ARRAY = 1,
    NATIVE_STRING = 2,
    NATIVE_NUMBER = 3,
    NATIVE_BOOLEAN = 4,
    NATIVE_DATE = 5,
    NATIVE_SOUND = 6,
    NATIVE_XML = 7,
    NATIVE_XMLNODE = 8,
    NATIVE_TEXTFIELD = 9,
    NATIVE_TEXTFORMAT = 10,
    NATIVE_BITMAPDATA = 11,
    NATIVE_LOADVARS = 12,
    NATIVE_LOCALCONNECTION = 13,
    NATIVE_MOVIECLIPLOADER = 14,
    NATIVE_PRINTJOB = 15,
    NATIVE_BUTTON = 16,
    NATIVE_TEXTSNAPSHOT = 17,
    NATIVE_COLORTRANSFORM = 18,
    NATIVE_TRANSFORM = 19,
    NATIVE_BLUR_FILTER = 20,
    NATIVE_BEVEL_FILTER = 21,
    // ... etc for all native-backed types
};
```

When `actionNewObject` creates an instance of a native-backed class, it sets `obj->native_type` to the appropriate enum value.

**`__initializeNative()` behavior**: The exact semantics depend on how the `getNativeStatus` algorithm works. Two possible approaches:

**Approach A — Faithful simulation**: `__initializeNative()` on a native object re-runs the native initialization based on `__constructor__`. If the object already has native backing and the target constructor is different, the re-initialization fails (double-construct protection). This matches how Flash Player works but requires understanding the exact detection algorithm.

**Approach B — Pragmatic shortcut**: Since the test checks a fixed set of classes with deterministic output, we can make `__initializeNative()` simply report whether the object has native backing. The `getNativeStatus` function's proto-swap-to-Date trick is the detection mechanism — we just need `obj.getDate()` to return undefined for native objects (because their native type isn't Date) and... also undefined for non-native objects. The distinction must come from somewhere else.

**Research needed**: Before implementing this phase, we need to trace the exact `getNativeStatus` algorithm step-by-step to understand how it distinguishes native from non-native. The decompiled bytecode is complex. Options:
1. Run the test in Ruffle with debug output to see the detection flow
2. Read Ruffle's `__initializeNative` implementation
3. Build a simple test case and trace through manually

**Tests impacted**: native_objects_swf6/7/8 (→ ~80-90% once detection works correctly)

### Phase 3: super() Call Mechanism

**Goal**: Make `super(args...)` work for subclassing built-in types.

The `native_subclasses` test uses MTASC-compiled `super()` calls. In the recompiled bytecode, `super()` compiles to a `CallMethod` on `_root[undefined]`, which in Flash Player resolves to calling the parent constructor via `__constructor__`. The specific pattern:

```c
// native_subclasses' makeSubclassOf function:
// Based on args.length, calls super() with 0, 1, 2, or 3 args
// The call is: _root[undefined](...args) which Flash Player interprets as super(...)
```

**Current behavior**: `_root[undefined]` resolves to undefined, and calling undefined as a method does nothing → "Unsupported number of args: undefined" warning, super never runs.

**Implementation**: The `super()` mechanism needs to:
1. Resolve `__constructor__` from the current `this` object's prototype chain
2. Call that constructor function with `this` as the target
3. Pass the provided arguments through

This is fundamentally the same mechanism needed for the `OOP/Super/Extends` test category (7 tests: as2_oop, as2_super_and_this_v6/v8, etc.). Implementing `super()` here benefits both categories.

**Approach**: In `actionCallMethod`, when the method name resolves to undefined on `_root`, check if this is a `super()` call context. If the current function was called as a constructor (or `this` has `__constructor__`), resolve the parent constructor and call it.

Actually, the MTASC pattern `_root[undefined]()` might not be the right way to detect super. Let me look at how the recompiled `native_subclasses` test invokes super:

In `func2_anonymous_3` (makeSubclassOf), the super call compiles as:
- Push args
- Push arg_count
- Push `_root` (or undefined?)
- Push undefined (method name)
- CallMethod

The ActionCallMethod with an undefined method name on _root should trigger the `super()` behavior. This is an MTASC quirk — it encodes `super()` as `_root[undefined]()`.

**Alternative**: A cleaner approach might be to look at the `__constructor__` property chain. When a function is called as a method with undefined name, look up `this.__constructor__.__constructor__` (the parent constructor) and call it.

**Tests impacted**:
- native_subclasses (0% → ~60-70% — super calls work, but some class-specific properties may still be wrong)
- native_double_construct (33% → ~80% — super calls now initialize BlurFilter)
- Also helps: as2_oop, as2_super_and_this_v6/v8, extends_chain, extends_native_type, super_edge_cases (7 OOP tests)

### Phase 4: Double-Construct Protection

**Goal**: Ensure native constructors only initialize once per object.

When `super()` is called on an object that already has native backing, the second call should:
- Still evaluate argument expressions (side effects like `valueOf` run)
- NOT re-initialize the native backing (properties keep their first-initialization values)

**Implementation**: In the native constructor dispatch, check `obj->native_type != NATIVE_NONE`. If already initialized, skip the constructor body but still pop/evaluate the arguments.

**Tests impacted**: native_double_construct (→ 12/12, 100%)

### Phase 5: Class-Specific Constructor Properties

**Goal**: Make native constructors actually set class-specific properties so `native_subclasses` property checks pass.

The `native_subclasses` test checks properties after calling `super()`. For example:
- `BlurFilter(10, 20)` → `obj.blurX === 10`, `obj.blurY === 20`
- `Array("foo", "bar")` → `obj.length === 2`, `obj.shift() === "foo"`
- `Date(123456)` → `obj.getTime() === 123456`
- `Sound(_root)` → `obj.getVolume() === 100`

Many of these constructors need real argument handling:

| Class | Args | Properties Checked |
|-------|------|--------------------|
| Boolean | (true) | traces as "true" |
| Number | (123.4) | traces as "123.4" |
| String | ("hello") | `.length === 5` |
| Array | ("foo", "bar") | `.length`, `.shift()` |
| Function | (myFunc) | traces as "myFunc" |
| Date | (123456) | `.getTime() === 123456` |
| BlurFilter | (10, 20) | `.blurX`, `.blurY` |
| BevelFilter | (5, 60) | `.distance`, `.angle` |
| GlowFilter | (65280, 1) | `.color`, `.alpha` |
| DropShadowFilter | (5, 60) | `.distance`, `.angle` |
| ColorMatrixFilter | (array20) | `.matrix` |
| DisplacementMapFilter | (null, null) | `.mapBitmap`, `.mapPoint` |
| ConvolutionFilter | (2,3,array6) | `.matrixX`, `.matrixY`, `.matrix` |
| GradientBevelFilter | (5, 60) | `.distance`, `.angle` |
| GradientGlowFilter | (5, 60) | `.distance`, `.angle` |
| ColorTransform | () | `.toString()` with 8 multiplier/offset values |
| Transform | (_root) | (no property checks) |
| TextFormat | ("Arial", 12) | `.font`, `.size` |
| BitmapData | (20, 30) | `.width`, `.height` |
| XML | ("<node />") | `.status === 0` |
| XMLNode | (1, "node") | `.nodeType`, `.nodeName` |
| LocalConnection | () | (no property checks) |
| Sound | (_root) | `.getVolume() === 100` |
| TextField.StyleSheet | () | (no property checks) |
| NetConnection | () | `.isConnected === false` |
| NetStream | (netconn) | (no property checks) |
| XMLSocket | () | (no property checks) |
| SharedObject | () | (no property checks) |
| FileReference | () | (no property checks) |
| MovieClip | () | (no property checks) |

Many of these constructors are simple — just store the arguments as properties. The more complex ones (Date, Array, XML) already have partial implementations.

**Tests impacted**: native_subclasses (→ ~90-95%)

---

## Implementation Priority and Dependencies

```
Phase 0 ──→ Phase 1 ──→ Phase 2
                │
                └──→ Phase 3 ──→ Phase 4
                         │
                         └──→ Phase 5
```

Phase 0 and Phase 1 are independent of Phase 3.
Phase 2 depends on Phase 0+1 (constructors must exist for detection to work).
Phase 3 is independent of Phase 2 (super() is a separate mechanism).
Phase 4 depends on Phase 3 (need super() working before testing double-construct).
Phase 5 depends on Phase 3 (need super() working before checking properties).

### Estimated Test Impact

| Phase | Tests Fixed | Cumulative Pass Rate |
|-------|-----------|---------------------|
| 0 | native_objects partially run | ~20 lines per test |
| 1 | Stubs enable more lines | ~35-40 lines per test |
| 2 | Native detection works | native_objects ~80-90% each |
| 3 | super() works | native_subclasses ~60%, native_double_construct ~80% |
| 4 | Double-construct protection | native_double_construct 100% |
| 5 | Constructor properties | native_subclasses ~95% |

### Cross-cutting Benefits

| Phase | Other Tests Helped |
|-------|-------------------|
| Phase 1 (stub constructors) | globals_swf5/6/7/8 (12 tests), bitmap_filters (2 tests), sound_props (2 tests) |
| Phase 3 (super() mechanism) | OOP/Super/Extends (7 tests): as2_oop, as2_super_and_this_v6/v8, extends_chain, extends_native_type, super_edge_cases, as2_super_via_manual_prototype |
| Phase 5 (filter constructors) | bitmap_filters (548-line test) |

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Stub constructors in actionNewObject/actionGetVariable, `__initializeNative` method, super() in actionCallMethod, native_type tracking, double-construct check |
| `include/actionmodern/variables.h` | Add `native_type` field to ASObject struct |
| `include/actionmodern/action.h` | New function declarations for stub constructors |

### Recompiler (SWFRecomp/)

| File | Changes |
|------|---------|
| `src/action/action.cpp` | May need changes for how super() calls are emitted (if the current _root[undefined] pattern is wrong) |

---

## Design Decisions

1. **Stub-first approach**: Register all missing constructors as stubs immediately (Phase 1), rather than waiting for full implementations. This unblocks native_objects tests and benefits the globals tests. Stubs can be enhanced later when individual feature categories are implemented.

2. **native_type on ASObject vs separate tracking**: Adding a `u8 native_type` field to ASObject is the simplest approach. It costs 1 byte per object but avoids a separate lookup table. Since ASObject already has padding, this likely has zero memory overhead.

3. **super() via __constructor__ chain**: Implement super() by walking the `__constructor__` prototype chain, not by special-casing `_root[undefined]()`. The `__constructor__` approach is how Flash Player works and benefits all super() call patterns, not just the MTASC one.

4. **SWF version gating for flash.* package**: The flash.* constructors should only be accessible in SWF8+. SWF6/7 correctly return `undefined` for these, producing the expected `"non-object: undefined"` output. Use the existing `swf_version` field on `SWFAppContext` to gate access.

5. **__initializeNative research**: Phase 2 requires understanding the exact semantics of `__initializeNative` in Flash Player. Rather than guessing, we should run a focused debug session with the `native_objects_swf7` test to trace the exact code flow and determine what makes the detection algorithm return "native" vs "non-native". This may reveal that we need a simpler or different approach than the native_type enum.
