# OOP / Super / Extends / Interfaces Implementation Plan
<!-- TESTS: as2_oop, as2_super_and_this_v6, as2_super_and_this_v8, as2_super_via_manual_prototype, extends_chain, extends_native_type, super_edge_cases, interface_implements_op -->

Last updated: 2026-02-14

## Overview

OOP (super/extends/interfaces) affects 8 Ruffle tests totaling 473 expected output lines. Most of the foundational infrastructure exists (actionExtends, actionInstanceOf, actionImplementsOp, actionNewObject) but has bugs and missing pieces. The critical gap is that `super` is completely non-functional — the recompiler creates an empty stub object instead of a real super reference.

**Current state**: `actionExtends` correctly sets up prototype chains. `actionInstanceOf` and `actionImplementsOp` exist but have type-handling bugs (reject ASFunction types). `super` in constructors and methods does nothing — the preload_super register is filled with an empty ASObject that has no prototype chain or constructor reference.

**Key insight**: Flash's `super` is a context-sensitive reference that depends on *where in the prototype chain* the current function was found. It's not a simple object — each level of constructor/method call shifts `super` one level up the chain. Implementing this requires runtime tracking of the "super depth" across nested calls.

## SWF Spec Reference

From SWF spec v19 (`SWFRecompDocs/specs/swf-spec-19.txt`):

- **ActionExtends (0x69)**: Pop superclass, pop subclass. Create prototype chain: `sub.prototype = new Object()`, `sub.prototype.__proto__ = super.prototype`, `sub.prototype.__constructor__ = super`
- **ActionImplementsOp (0x2C)**: Pop constructor, pop count, pop N interface ctors. Register interfaces for instanceof checks.
- **DefineFunction2 (0x8E) flags**: Bit 4 = PreloadSuper, Bit 2 = PreloadArguments. When PreloadSuper is set, `super` is loaded into a register.
- **super() calling convention**: Two patterns depending on compiler and SWF version.

## Test Inventory (8 tests)

| Test | Lines | SWF Ver | Key Features Needed |
|------|-------|---------|-------------------|
| as2_oop | 14 | 8 | ImplementsOp fix, InstanceOf fix, CastOp |
| as2_super_and_this_v6 | 97 | 6 | GetVariable("super"), CallFunction("super"), addProperty, SWF6 this |
| as2_super_and_this_v8 | 85 | 8 | Same as v6, SWF8 this binding |
| as2_super_via_manual_prototype | 42 | 6 | Manual proto chains, MovieClip ctor, super via GetVariable |
| extends_chain | 135 | 7 | CallMethod(arguments, undefined) super(), super.method(), ImplementsOp |
| extends_native_type | 12 | 8 | flash.geom.ColorTransform native, extends native type |
| super_edge_cases | 40 | 7 | __constructor__ lookup, __resolve exclusion, addProperty on __constructor__ |
| interface_implements_op | 48 | 8 | Complex ImplementsOp, lazy interfaces, NoisyString, MovieClipLoader |

## How Super Works in Flash AVM1

### The super object

When a function is called as a constructor or method, a `super` reference is computed for that call context:

```
super = currentClass.prototype.__proto__
```

Where `currentClass` is the constructor function whose code is executing. This means:

- In `Base` constructor: `super` = `Base.prototype.__proto__` (typically `Object.prototype`)
  - `super.__proto__` = `Object.prototype.__proto__` = `undefined`
- In `Extended` constructor (extends Base): `super` = `Extended.prototype.__proto__` (= `Base.prototype`, set by Extends)
  - `super.__proto__` = `Base.prototype.__proto__` = `Object.prototype`
- In `ExtendedFurther` constructor (extends Extended): `super` = `EF.prototype.__proto__` (= `Extended.prototype`)
  - `super.__proto__` = `Extended.prototype.__proto__` = `Base.prototype`

### super() constructor call

When `super()` is called inside a constructor, it:
1. Looks up `__constructor__` on the current `super` object
2. Calls that constructor with `this` = the same `this` as the current call
3. Sets the new `super` for the parent constructor = `super.__proto__`

### super.method() call

When `super.method()` is called:
1. Looks up `method` on the current `super` object (with prototype chain walk)
2. Calls that method with `this` = the same `this` as the current call
3. Sets the new `super` for the parent method = `super.__proto__`

### Two calling patterns in bytecode

**Pattern A — SWF6 and below (DefineFunction, ASC/MTASC compiler)**:
```
// super()
Push 0              // arg count
Push "super"        // function name
CallFunction        // calls super as function

// super.method()
Push 0              // arg count
GetVariable "super" // gets super object
Push "method"       // method name
CallMethod          // calls method on super
```

**Pattern B — SWF7+ (DefineFunction2, ASC compiler)**:
```
// super() — arguments array stands in for super
Push 0              // arg count
Push Register 1     // arguments array (preloaded)
Push undefined      // method name = undefined → constructor call
CallMethod

// super.method()
Push 0              // arg count
Push Register 1     // arguments array
Push "method"       // method name
CallMethod
```

In Pattern B, the arguments array is used as a proxy. The AVM1 runtime recognizes `CallMethod(arguments, undefined)` as `super()` and `CallMethod(arguments, "method")` as `super.method()`.

**Pattern C — SWF7+ with PreloadSuper (MTASC compiler)**:
```
// super.method()
Push 0              // arg count
Push Register N     // super register (preloaded)
Push "method"       // method name
CallMethod
```

Here the super object is directly in a register, accessed via `CallMethod(super_reg, "method")`.

---

## Phase 1: Fix ImplementsOp and InstanceOf for ASFunction Types

**Goal**: Fix the type-handling bugs that prevent interfaces from working when constructors are ASFunction (which they almost always are in AS2).

### Bug 1: actionImplementsOp rejects ASFunction constructors

**File**: `SWFModernRuntime/src/actionmodern/action.c`, line 9869

Current code:
```c
if (constructor_var.type != ACTION_STACK_VALUE_OBJECT)
{
    fprintf(stderr, "ERROR: actionImplementsOp - constructor is not an object\n");
    return;
}
```

Fix: Also accept `ACTION_STACK_VALUE_FUNCTION`. When constructor is ASFunction, use its `own_props` or `prototype_obj` ASObject to store interfaces. Since `setInterfaceList` takes `ASObject*`, we need the ASFunction's associated object.

**Approach**: When the constructor is an ASFunction, lazily create its `own_props` (if NULL) and store interfaces on that. Similarly, interface constructors can be ASFunction — store the ASFunction pointer cast as ASObject pointer in the interfaces array, and compare using pointer equality in `implementsInterface`.

Actually, the cleaner approach: change the interfaces array to store `void*` pointers (tagged by the original type). Or simpler: store the `ActionVar` directly so we keep the type tag.

**Simplest approach**: Change `ASObject.interfaces` from `ASObject**` to `void**` (or keep as-is and store raw pointers). In `implementsInterface`, compare against both the ASObject* and the contained ASFunction*. In `setInterfaceList`, accept both types.

### Bug 2: actionImplementsOp rejects ASFunction interfaces

**File**: `SWFModernRuntime/src/actionmodern/action.c`, line 9915

Same pattern: `if (iface_var.type != ACTION_STACK_VALUE_OBJECT)` rejects ASFunction.

Fix: Also accept ASFunction. Store the pointer as-is (it's just used for identity comparison in `implementsInterface`).

### Bug 3: checkInstanceOf skips interface check when ctor is ASFunction

**File**: `SWFModernRuntime/src/actionmodern/action.c`, lines 8799-8800

Current code:
```c
if (obj_var->type != ACTION_STACK_VALUE_FUNCTION &&
    ctor_var->type != ACTION_STACK_VALUE_FUNCTION)
{
    if (implementsInterface(obj, (ASObject*) ctor_var->data.numeric_value))
```

Fix: Remove this guard. The interface check should run regardless of whether ctor is ASFunction or ASObject. Need to also update `implementsInterface` to handle the case where the interface_ctor pointer is actually an ASFunction* (pointer comparison still works since we're comparing against the same pointer stored in `setInterfaceList`).

### Bug 4: implementsInterface only compares ASObject pointers

**File**: `SWFModernRuntime/src/actionmodern/object.c`, line 557

```c
if (obj_ctor->interfaces[i] == interface_ctor)
```

This only works if both pointers are the same type. If we store ASFunction* in the interfaces array and compare against ASObject*, it won't match. Fix: store and compare `void*` pointers (the raw pointer value from the ActionVar).

### Bug 5: getConstructor only checks for ASObject type

**File**: `SWFModernRuntime/src/actionmodern/object.c`, line 590

```c
if (constructor_var != NULL && constructor_var->type == ACTION_STACK_VALUE_OBJECT)
```

Should also accept `ACTION_STACK_VALUE_FUNCTION`.

### Implementation approach

The cleanest fix is to change the interface storage to use `ActionVar` instead of `ASObject*`:

1. Change `ASObject.interfaces` from `ASObject**` to `u64*` (raw pointer storage)
2. In `setInterfaceList`, store `(u64)iface_var.data.numeric_value` regardless of type
3. In `implementsInterface`, compare raw pointer values: `interfaces[i] == (u64)interface_ctor_ptr`
4. In `checkInstanceOf`, always run the interface check (remove ASFunction guard)
5. In `actionImplementsOp`, accept both ASObject and ASFunction for constructor and interfaces

Alternatively, keep `ASObject**` but treat it as `void**` — since we only ever do pointer comparison, the actual type doesn't matter. We just need to store and compare the same pointer.

### Tests fixed by Phase 1

- **as2_oop** (14 lines): Should fully pass — tests ImplementsOp, InstanceOf, CastOp with function constructors
- Partial improvement for **extends_chain** and **interface_implements_op** (instanceof checks will start working)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=as2_oop --diff --verbose
```

---

## Phase 2: Add __constructor__ in actionExtends

**Goal**: When `actionExtends` creates the new prototype, set `__constructor__` = superclass (in addition to `constructor`). This is needed by `super()` to find the parent constructor.

### What's missing

Current `actionExtends` (line 9718):
```c
setProperty(app_context, new_proto, "constructor", 11, &superclass);
```

Need to add:
```c
setProperty(app_context, new_proto, "__constructor__", 15, &superclass);
```

The `__constructor__` property is how `super()` finds the parent constructor. When called inside a constructor for class C:
1. Get `this.__proto__` (= C.prototype, set by `new`)
2. C.prototype was created by `Extends` → has `__constructor__` = parent class ctor
3. Call `__constructor__` with `this`

Note: `__constructor__` should be set as DontEnum (not enumerable), so it doesn't appear in for-in loops.

### Tests affected

Foundation for Phases 3-5. No tests pass from this alone, but it's a prerequisite.

---

## Phase 3: Super Context Tracking Infrastructure

**Goal**: Add runtime infrastructure to track the current `super` reference and `this` binding across nested constructor/method calls.

### Why this is needed

Flash's `super` is context-dependent. When `ChildA` calls `super()` which invokes `Super`'s constructor, the `super` inside `Super`'s constructor is different from the `super` inside `ChildA`'s constructor. Since constructors are compiled as C functions and call each other via `actionCallMethod`, we need a stack to track the super context.

### Implementation

Add to `action.c`:

```c
// Super context stack — tracks the 'super' object for each call level
#define MAX_SUPER_DEPTH 64
static void* super_proto_stack[MAX_SUPER_DEPTH];  // ASObject* for each super level
static u32 super_depth = 0;

// This binding stack — tracks 'this' for super calls
static void* this_binding_stack[MAX_SUPER_DEPTH];
static u32 this_depth = 0;

static void pushSuperContext(void* super_proto, void* this_obj) {
    if (super_depth < MAX_SUPER_DEPTH) {
        super_proto_stack[super_depth++] = super_proto;
    }
    if (this_depth < MAX_SUPER_DEPTH) {
        this_binding_stack[this_depth++] = this_obj;
    }
}

static void popSuperContext(void) {
    if (super_depth > 0) super_depth--;
    if (this_depth > 0) this_depth--;
}

static void* getCurrentSuper(void) {
    return super_depth > 0 ? super_proto_stack[super_depth - 1] : NULL;
}

static void* getCurrentThis(void) {
    return this_depth > 0 ? this_binding_stack[this_depth - 1] : NULL;
}
```

### Set super context when calling constructors

In `actionNewObject` (line ~12100) and `actionNewMethod` (constructor path), before calling the constructor:

```c
// Compute super for this constructor call
// super = ctor.prototype.__proto__ (the parent class's prototype)
ASObject* super_obj = NULL;
if (ctor_func->prototype_obj != NULL) {
    ActionVar* proto_proto = getProperty(ctor_func->prototype_obj, "__proto__", 9);
    if (proto_proto && proto_proto->type == ACTION_STACK_VALUE_OBJECT)
        super_obj = (ASObject*) proto_proto->data.numeric_value;
}
pushSuperContext(super_obj, obj);  // obj = the newly created 'this'

// ... call constructor ...

popSuperContext();
```

### Export as runtime functions

Declare in `action.h`:
```c
void* actionGetCurrentSuper(void);
void* actionGetCurrentThis(void);
```

These will be called from generated code (preload_super) and from runtime functions (GetVariable("super")).

---

## Phase 4: Super for DefineFunction2 (Preload Super + Arguments Pattern)

**Goal**: Fix super() and super.method() for SWF7+ DefineFunction2 functions.

### 4a. Fix preload_super in the recompiler

**File**: `SWFRecomp/src/action/action.cpp`, lines 1333-1340

Current (broken):
```cpp
context.out_script_defs << "\tASObject* super_obj_" << next_reg << " = allocObject(app_context, 0);" << endl;
context.out_script_defs << "\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_OBJECT;" << endl;
context.out_script_defs << "\tregs[" << next_reg << "].data.numeric_value = (u64)super_obj_" << next_reg << ";" << endl;
```

Fixed:
```cpp
context.out_script_defs << "\t// Preload 'super' into register " << next_reg << endl;
context.out_script_defs << "\t{" << endl;
context.out_script_defs << "\t\tvoid* _super = actionGetCurrentSuper();" << endl;
context.out_script_defs << "\t\tif (_super) {" << endl;
context.out_script_defs << "\t\t\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_OBJECT;" << endl;
context.out_script_defs << "\t\t\tregs[" << next_reg << "].data.numeric_value = (u64)_super;" << endl;
context.out_script_defs << "\t\t} else {" << endl;
context.out_script_defs << "\t\t\tregs[" << next_reg << "].type = ACTION_STACK_VALUE_UNDEFINED;" << endl;
context.out_script_defs << "\t\t\tregs[" << next_reg << "].data.numeric_value = 0;" << endl;
context.out_script_defs << "\t\t}" << endl;
context.out_script_defs << "\t}" << endl;
```

### 4b. Handle CallMethod(arguments, undefined) as super()

**File**: `SWFModernRuntime/src/actionmodern/action.c`, in `actionCallMethod`

When the target is an ASArray and the method name is undefined/empty, this is the `super()` calling pattern:

```c
// In actionCallMethod, when target is ASArray and method is undefined:
if (target_type == ACTION_STACK_VALUE_ARRAY && method_is_undefined) {
    // super() constructor call
    ASObject* super_obj = (ASObject*) getCurrentSuper();
    if (super_obj != NULL) {
        // Look up __constructor__ on super
        ActionVar* ctor_var = getProperty(super_obj, "__constructor__", 15);
        if (ctor_var == NULL)
            ctor_var = getProperty(super_obj, "constructor", 11);

        if (ctor_var != NULL && ctor_var->type == ACTION_STACK_VALUE_FUNCTION) {
            ASFunction* parent_ctor = (ASFunction*) ctor_var->data.numeric_value;

            // New super = super.__proto__ (one level up)
            ASObject* new_super = NULL;
            ActionVar* super_proto = getProperty(super_obj, "__proto__", 9);
            if (super_proto && super_proto->type == ACTION_STACK_VALUE_OBJECT)
                new_super = (ASObject*) super_proto->data.numeric_value;

            void* current_this = getCurrentThis();
            pushSuperContext(new_super, current_this);

            // Call parent constructor with same this
            if (parent_ctor->function_type == 2 && parent_ctor->advanced_func) {
                parent_ctor->advanced_func(app_context, args, num_args, registers, current_this);
            } else if (parent_ctor->function_type == 1 && parent_ctor->simple_func) {
                // Set 'this' variable and call
                ActionVar this_var = {0};
                this_var.type = ACTION_STACK_VALUE_OBJECT;
                this_var.data.numeric_value = (u64)current_this;
                setVariableByName("this", &this_var);
                parent_ctor->simple_func(app_context);
            }

            popSuperContext();
            // Push undefined as return value (constructors don't return)
            PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
            return;
        }
    }
    // Fallback: push undefined
    PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
    return;
}
```

### 4c. Handle CallMethod(arguments, "methodName") as super.method()

When the target is an ASArray and the method name is a non-empty string:

```c
if (target_type == ACTION_STACK_VALUE_ARRAY && method_is_string && !method_is_empty) {
    // super.method() call
    ASObject* super_obj = (ASObject*) getCurrentSuper();
    if (super_obj != NULL) {
        // Look up method on super's prototype chain
        ActionVar* method_var = getPropertyWithPrototype(super_obj, method_name, method_name_len);

        if (method_var != NULL && method_var->type == ACTION_STACK_VALUE_FUNCTION) {
            ASFunction* method_func = (ASFunction*) method_var->data.numeric_value;

            // New super = super.__proto__ (one level up)
            ASObject* new_super = NULL;
            ActionVar* super_proto = getProperty(super_obj, "__proto__", 9);
            if (super_proto && super_proto->type == ACTION_STACK_VALUE_OBJECT)
                new_super = (ASObject*) super_proto->data.numeric_value;

            void* current_this = getCurrentThis();
            pushSuperContext(new_super, current_this);

            // Call method with same this
            if (method_func->function_type == 2 && method_func->advanced_func) {
                ActionVar ret = method_func->advanced_func(app_context, args, num_args, registers, current_this);
                pushVar(app_context, &ret);
            } else if (method_func->function_type == 1 && method_func->simple_func) {
                ActionVar this_var = {0};
                this_var.type = ACTION_STACK_VALUE_OBJECT;
                this_var.data.numeric_value = (u64)current_this;
                setVariableByName("this", &this_var);
                for (int i = (int)num_args - 1; i >= 0; i--)
                    pushVar(app_context, &args[i]);
                ActionVar ret = method_func->simple_func(app_context);
                pushVar(app_context, &ret);
            }

            popSuperContext();
            return;
        }
    }
    // Fallback: push undefined
    PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
    return;
}
```

### 4d. Handle CallMethod(super_register, ...) for Pattern C

When the target is an ASObject that came from the preload_super register, CallMethod already handles method dispatch normally (looks up method on the object's prototype chain). But we need to ensure:
1. The `this` for the called method is the current `this`, not the super object
2. The super for the called method is one level up

This requires detecting that the target is a "super" object. Options:
- Tag the super object (add a flag)
- Always use `getCurrentThis()` when calling methods on any object (breaks normal method calls)
- In the generated code, when calling a method on the super register, emit a special `actionCallSuperMethod` instead of `actionCallMethod`

**Simplest approach for now**: The existing CallMethod dispatch already calls methods with `this` = the target object. For super, we need `this` = the original `this`. Since Pattern C (preload_super register) is used by MTASC, and Pattern B (arguments array) is used by ASC, and most test SWFs use Pattern B, we can defer Pattern C refinement and focus on Pattern B first.

Actually, looking at the test scripts: `as2_super_and_this_v6/v8` use SWF6 DefineFunction (Pattern A), `extends_chain` uses DefineFunction2 with arguments (Pattern B), and none of the current tests use Pattern C (preload_super). So Pattern C can be deferred.

### Tests fixed by Phase 4

- **extends_chain** (135 lines): Should mostly pass — tests super(), super.method(), constructor chaining
- Partial improvement for **as2_super_and_this_v8** (if the test also uses Pattern B)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=extends_chain --diff --verbose
```

---

## Phase 5: Super for DefineFunction / SWF6 (Pattern A)

**Goal**: Handle `super` accessed via `GetVariable("super")` and `CallFunction("super")` for SWF5/6 DefineFunction code.

### 5a. GetVariable("super")

**File**: `SWFModernRuntime/src/actionmodern/action.c`, in `actionGetVariable`

Add special handling alongside existing `"this"`, `"_root"`, `"_global"` checks:

```c
if (strcmp(name, "super") == 0 || strcasecmp(name, "super") == 0) {
    void* super_obj = getCurrentSuper();
    if (super_obj != NULL) {
        ActionVar super_var;
        super_var.type = ACTION_STACK_VALUE_OBJECT;
        super_var.str_size = 0;
        super_var.data.numeric_value = (u64)super_obj;
        pushVar(app_context, &super_var);
    } else {
        PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
    }
    return;
}
```

This enables `super.__proto__` access (used by all super_and_this tests).

### 5b. CallFunction("super")

**File**: `SWFModernRuntime/src/actionmodern/action.c`, in `actionCallFunction`

When function name is "super":

```c
if (strcmp(func_name, "super") == 0) {
    // super() constructor call
    ASObject* super_obj = (ASObject*) getCurrentSuper();
    if (super_obj != NULL) {
        // Look up __constructor__ on super
        ActionVar* ctor_var = getProperty(super_obj, "__constructor__", 15);
        if (ctor_var == NULL)
            ctor_var = getProperty(super_obj, "constructor", 11);

        if (ctor_var && ctor_var->type == ACTION_STACK_VALUE_FUNCTION) {
            ASFunction* parent_ctor = (ASFunction*) ctor_var->data.numeric_value;

            // New super = super.__proto__
            ASObject* new_super = NULL;
            ActionVar* proto = getProperty(super_obj, "__proto__", 9);
            if (proto && proto->type == ACTION_STACK_VALUE_OBJECT)
                new_super = (ASObject*) proto->data.numeric_value;

            void* current_this = getCurrentThis();
            pushSuperContext(new_super, current_this);

            // Call parent constructor with same this
            // ... (same dispatch logic as Phase 4b) ...

            popSuperContext();
        }
    }
    PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
    return;
}
```

### 5c. CallMethod(super_obj, "method") for SWF6

When `GetVariable("super")` returns the super object and it's used in `CallMethod(super, "method")`, the existing CallMethod dispatch will look up the method on the super object. But it needs:
1. `this` = the original `this` (not the super object)
2. `super` for the called method = `super.__proto__`

This is the same issue as Pattern C in Phase 4d. For SWF6 DefineFunction, the approach is:

When `actionCallMethod` is dispatching a call on an ASObject target, check if that ASObject is the current super. If so, use `getCurrentThis()` instead of the target as `this`, and push a new super context.

**Detection**: We can compare the target pointer against `getCurrentSuper()`. If they match, it's a super method call.

```c
// In actionCallMethod, after resolving the method on an ASObject target:
if ((void*)target_obj == getCurrentSuper()) {
    // This is super.method() — use original 'this' and advance super
    void* current_this = getCurrentThis();
    ASObject* new_super = NULL;
    ActionVar* sp = getProperty(target_obj, "__proto__", 9);
    if (sp && sp->type == ACTION_STACK_VALUE_OBJECT)
        new_super = (ASObject*) sp->data.numeric_value;

    pushSuperContext(new_super, current_this);
    // Call method with current_this instead of target_obj
    // ...
    popSuperContext();
}
```

### Tests fixed by Phase 5

- **as2_super_and_this_v6** (97 lines): Should mostly pass
- **as2_super_and_this_v8** (85 lines): Should mostly pass
- **as2_super_via_manual_prototype** (42 lines): Partially — needs MovieClip constructor too

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=as2_super_and_this_v6 --diff --verbose
python3 ruffle-tests/verify_output.py --test=as2_super_and_this_v8 --diff --verbose
```

---

## Phase 6: Edge Cases and Remaining Tests

### 6a. super_edge_cases (40 lines)

This MTASC-compiled test exercises:

1. **super.method() with primitive __proto__**: When `obj.__proto__` is set to `_root`, `new String('hello')`, or a raw string, `super.foobar()` should NOT do primitive-to-object coercion. Only the boxed String case should find `String.prototype.foobar`.

2. **super() and __constructor__**: Tests that `super()` looks up `__constructor__` on `this.__proto__.__proto__` (NOT on `this.__proto__` directly). Also tests that `__resolve` is never called during super() resolution.

**Requires**: `__resolve` handler (currently not implemented), `addProperty` (partially implemented), correct __constructor__ chain traversal.

**Dependency**: Requires MTASC `main()` entry point pattern (InitObject → set on _root → call main).

### 6b. as2_super_via_manual_prototype (42 lines)

Tests manual prototype chain setup:
```actionscript
Base.prototype = new MovieClip();
Extended.prototype = new Base();
ExtendedFurther.prototype = new Extended();
```

**Requires**: `MovieClip` constructor (`new MovieClip()` returning an object). Currently, `actionNewObject("MovieClip")` likely creates a generic object. Need to verify.

Also requires: super to work correctly when the prototype chain is set up manually (without actionExtends). Since `__constructor__` is set by actionExtends, manual chains might not have it. The test uses `CallFunction("super")` (SWF6), so the runtime needs to fall back to `constructor` property when `__constructor__` is not found.

### 6c. extends_native_type (12 lines)

Tests extending `flash.geom.ColorTransform`:
```actionscript
class MyColorTransform extends flash.geom.ColorTransform { ... }
```

**Requires**: `flash.geom.ColorTransform` constructor registered as a global. This is a separate feature (geometry classes) that has partial support (Point/Matrix/Rectangle tests are 69-72% passing). Likely blocked until ColorTransform is implemented.

### 6d. interface_implements_op (48 lines)

The most complex test. Key blockers beyond Phase 1:
- `MovieClipLoader.loadClip()` — needs external SWF loading (likely can't pass the cross-version part)
- `NoisyString extends String` — needs extending native String type
- Lazy interface registration via callbacks
- Complex interface chain walking

Phase 1 fixes will help, but full pass likely requires additional work.

---

## Implementation Priority and Dependencies

```
Phase 1 (ImplementsOp/InstanceOf fix) ──→ Phase 2 (__constructor__)
                                              │
                                              ├──→ Phase 3 (Super infrastructure)
                                              │         │
                                              │         ├──→ Phase 4 (DefineFunction2 super)
                                              │         │
                                              │         └──→ Phase 5 (SWF6 super)
                                              │
                                              └──→ Phase 6 (Edge cases)
```

### Estimated test impact

| Phase | Tests Fixed | Lines Gained | Cumulative |
|-------|-----------|-------------|------------|
| 1 | as2_oop | ~14 | ~14 |
| 2 | (foundation) | 0 | ~14 |
| 3 | (foundation) | 0 | ~14 |
| 4 | extends_chain | ~100-135 | ~114-149 |
| 5 | as2_super_and_this_v6, v8 | ~100-182 | ~214-331 |
| 6a | super_edge_cases | ~20-40 | ~234-371 |
| 6b | as2_super_via_manual_prototype | ~20-42 | ~254-413 |
| 6c | extends_native_type | blocked | - |
| 6d | interface_implements_op | ~24-48 | ~278-461 |

**Quick win**: Phases 1+2+3+4 fix `as2_oop` (14 lines) and `extends_chain` (~135 lines) for ~149 new passing lines. Phase 5 adds another ~182 lines for the super_and_this tests.

---

## Files to Modify

### Recompiler (SWFRecomp/)

| File | Changes |
|------|---------|
| `src/action/action.cpp` | Fix preload_super to use `actionGetCurrentSuper()` instead of empty object |

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Super context stack (push/pop/get), fix actionCallMethod for super patterns, fix actionCallFunction for "super", fix actionGetVariable for "super", fix actionImplementsOp for ASFunction, fix checkInstanceOf interface guard, set super context in actionNewObject/actionNewMethod |
| `include/actionmodern/action.h` | Declare actionGetCurrentSuper(), actionGetCurrentThis() |
| `src/actionmodern/object.c` | Fix implementsInterface for void* comparison, fix getConstructor for ASFunction type, add __constructor__ support |
| `include/actionmodern/object.h` | Change interfaces storage if needed |

### No new files needed

All changes are modifications to existing files.

---

## Design Decisions

1. **Super as a runtime stack vs. per-function parameter**: We use a runtime stack (`super_proto_stack`) because super is accessed by runtime functions (`actionGetVariable`, `actionCallMethod`) that don't receive function parameters. The C call stack naturally handles nesting through pushSuperContext/popSuperContext around each constructor/method invocation.

2. **Detecting super calls in CallMethod**: For Pattern B (`CallMethod(arguments, undefined)`), we check if the target is an ASArray and the method name is undefined. For Pattern A (SWF6 `CallMethod(super_obj, method)`), we check if the target pointer equals `getCurrentSuper()`. Both patterns are well-defined and don't conflict with normal CallMethod usage.

3. **Interface storage simplification**: Rather than changing the `ASObject.interfaces` type, we can cast ASFunction* to ASObject* for storage since we only ever do pointer comparison. This avoids touching the struct definition and all existing code that uses it.

4. **__constructor__ vs constructor**: Flash sets both. `__constructor__` is the canonical property for super() resolution. `constructor` is the ECMAScript standard property. Both point to the parent class constructor. `__constructor__` should be DontEnum.

5. **Deferred items**: Pattern C (preload_super register used by MTASC) is deferred since no current tests use it. `extends_native_type` is deferred until geometry classes are implemented. Full `interface_implements_op` is partially blocked by MovieClipLoader/network.
