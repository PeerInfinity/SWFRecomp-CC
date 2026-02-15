# Object.watch / Object.unwatch Implementation Plan

Last updated: 2026-02-15

## Overview

`Object.prototype.watch()` and `Object.prototype.unwatch()` allow registering callbacks that fire when a property value changes. The callback can modify or reject the new value. This is a Flash-native feature (not standard ECMAScript) available in all SWF versions.

**Tests affected**: 4 tests
- `watch` (119 lines) — comprehensive: validation, clamping, exceptions, unwatch, method context
- `watch_textfield` (13 lines) — watch on built-in TextField property (`text`)
- `watch_virtual_property` (62 lines, `known_failure = true`) — interaction with addProperty
- `watch_virtual_property_proto` (3 lines) — watch on prototype chain properties

**Estimated difficulty**: Medium — the core mechanism is simple, but it touches multiple property-set code paths and must interact correctly with the existing virtual property (addProperty) system.

---

## Behavioral Specification (from test analysis)

### `watch(property, callback, userData?)`

- **Returns**: `true` if watch was successfully registered, `false` otherwise
- **Validation**: Returns `false` if:
  - No arguments
  - No callback argument (1 arg only)
  - Callback is not a function (e.g. `true`, number)
- **Replacement**: Calling `watch()` on an already-watched property replaces the previous watcher (callback + userData)
- **Persistence through delete**: Deleting the watched property does NOT remove the watcher — subsequent assignments still trigger the callback (with `oldVal = undefined`)
- **Per-object**: The watcher is stored on the specific object, not globally

### Callback signature

```
function callback(property, oldVal, newVal, userData) → returnValue
```

- `property`: string name of the property being set
- `oldVal`: previous value of the property (undefined if not set)
- `newVal`: the value being assigned
- `userData`: the third argument passed to `watch()`, or `undefined` if none
- **Return value**: becomes the actual value stored on the property
- **`this` context**: the object being watched (e.g. `_level0.text_field` for TextField)

### Callback behavior details

1. The callback fires **before** the property value changes
2. The callback's return value is what actually gets stored
3. If the callback throws an exception, the property becomes `undefined`
4. The callback fires for every `SetMember`/`SetVariable` assignment, including via `=` operator and internal property sets

### `unwatch(property)`

- **Returns**: `true` if a watcher existed and was removed, `false` otherwise
- Returns `false` if called with no arguments
- Returns `false` if no watcher exists for the property
- After unwatch, assignments bypass the callback completely

### Interaction with addProperty (virtual properties)

From `watch_virtual_property` test (known_failure):

1. `watch("x", cb)` then `addProperty("x", getter, setter)` → the watch callback fires during addProperty registration with `oldVal=undefined, newVal=undefined`
2. When setting a virtual property: watch callback fires **first**, then the addProperty setter receives the watch callback's return value
3. When reading: the addProperty getter is used (watch has no effect on reads)
4. `oldVal` in the watch callback comes from the **setter's last stored value** (not the getter's return), except for the first call where it's the getter's return or undefined
5. `unwatch("x")` returns `false` when the property has a virtual setter — the watcher cannot be removed (this is the known_failure behavior)
6. Re-calling `watch("x", cb)` succeeds even when unwatch fails

**Note**: The `watch_virtual_property` test is marked `known_failure = true` in Ruffle itself, meaning even Ruffle doesn't fully pass this. We should implement the straightforward behavior first and not worry about this edge case.

### Interaction with TextField properties

From `watch_textfield` test:

1. `textField.watch("text", callback)` returns `true`
2. Setting `textField.text = "hello"` triggers the callback
3. `this` in the callback is the TextField object itself (`_level0.text_field`)
4. `oldVal` for first assignment is `undefined`
5. Currently TextField property sets happen in `actionSetMember` → MovieClip built-in property handling. Watch must fire in this code path too.

---

## Implementation Design

### Data Structure: Per-Object Watch Table

Add watch entries directly to `ASObject`. Since most objects will never have watches, use a pointer to an optional watch array (NULL by default = zero overhead for unwatched objects).

```c
// In object.h, add to ASObject:
typedef struct WatchEntry {
    char* name;           // property name (heap-allocated)
    u32 name_length;
    ASFunction* callback; // the watch callback function
    ActionVar userData;   // optional userData argument
} WatchEntry;

typedef struct ASObject {
    u32 refcount;
    u32 num_properties;
    u32 num_used;
    ASProperty* properties;
    u32 interface_count;
    struct ASObject** interfaces;
    // NEW:
    WatchEntry* watches;     // NULL if no watches registered
    u32 watch_count;
    u32 watch_capacity;
} ASObject;
```

**Why per-object, not a global table?**: The tests show watch is per-object (calling `watch` on one object doesn't affect others). The current `addProperty` uses a global table which is a simplification bug — watch needs to be correct from the start.

### Helper Functions (object.c)

```c
// Find a watch entry on an object (does NOT walk prototype chain)
WatchEntry* findWatch(ASObject* obj, const char* name, u32 name_length);

// Register or replace a watch on an object
int addWatch(SWFAppContext* app_context, ASObject* obj,
             const char* name, u32 name_length,
             ASFunction* callback, ActionVar* userData);

// Remove a watch from an object. Returns 1 if found & removed, 0 otherwise.
int removeWatch(ASObject* obj, const char* name, u32 name_length);

// Invoke a watch callback. Returns the value to actually store.
// Called from setProperty and other property-set code paths.
ActionVar invokeWatch(SWFAppContext* app_context, ASObject* obj,
                      WatchEntry* watch,
                      const char* name, u32 name_length,
                      ActionVar* oldVal, ActionVar* newVal);
```

### Interception Points

Watch callbacks must fire at every code path that sets a property. The key interception points are:

#### 1. `setProperty()` in object.c (lines 293-399)

This is the central property-set function for ASObject. Insert watch check:

```c
void setProperty(SWFAppContext* app_context, ASObject* obj,
                 const char* name, u32 name_length, ActionVar* value)
{
    // NEW: Check for watch callback
    WatchEntry* watch = (obj->watches != NULL) ? findWatch(obj, name, name_length) : NULL;
    if (watch != NULL)
    {
        // Get old value (may be undefined if property doesn't exist)
        ActionVar* existing = getProperty(obj, name, name_length);
        ActionVar old_val;
        if (existing != NULL)
            old_val = *existing;
        else
            old_val = (ActionVar){ .type = ACTION_STACK_VALUE_UNDEFINED };

        // Invoke callback — return value replaces the assigned value
        ActionVar actual = invokeWatch(app_context, obj, watch,
                                       name, name_length, &old_val, value);
        value = &actual;  // use callback's return value
    }

    // ... existing setProperty logic (update or create property) ...
}
```

#### 2. `actionSetMember()` in action.c — MovieClip path (line ~10570+)

When setting properties on MovieClip objects (type MOVIECLIP), the code currently writes to built-in properties (`_x`, `_y`, etc.) or `dynamic_props` directly, bypassing `setProperty()`. For watched MovieClip properties, we need to check the watch table on the MovieClip's `dynamic_props` ASObject.

Specifically for `watch_textfield`, when `text_field.text = "hello"` is assigned, the code currently goes through the MovieClip property-set path. We need to add watch checking there.

#### 3. `actionSetVariable()` in action.c — virtual property setter path (line ~8139)

When setting a variable that has both a watch AND a virtual property (addProperty), the watch must fire first, then the virtual property setter. The existing virtual property check is at line 8139.

### Registration: Object.prototype.watch / Object.prototype.unwatch

Register `watch` and `unwatch` as built-in functions on `g_object_prototype` in `getObjectPrototype()` (action.c, ~line 965), alongside the existing `toString`, `valueOf`, `hasOwnProperty`.

Both are type-2 functions (DefineFunction2) because they need access to `this_obj` (the object being watched).

```c
// In getObjectPrototype():
static ASFunction g_object_watch_func;
static ASFunction g_object_unwatch_func;

// watch(property, callback, userData?)
memset(&g_object_watch_func, 0, sizeof(ASFunction));
strcpy(g_object_watch_func.name, "watch");
g_object_watch_func.function_type = 2;
g_object_watch_func.advanced_func = builtinObjectWatch;
// ... register on g_object_prototype ...

// unwatch(property)
memset(&g_object_unwatch_func, 0, sizeof(ASFunction));
strcpy(g_object_unwatch_func.name, "unwatch");
g_object_unwatch_func.function_type = 2;
g_object_unwatch_func.advanced_func = builtinObjectUnwatch;
// ... register on g_object_prototype ...
```

### Built-in Function Implementations

```c
// Object.prototype.watch(property, callback, userData?)
ActionVar builtinObjectWatch(SWFAppContext* app_context,
                             ActionVar* args, u32 arg_count,
                             ActionVar* registers, ASObject* this_obj)
{
    ActionVar result = { .type = ACTION_STACK_VALUE_BOOLEAN };
    result.data.numeric_value = 0; // false

    if (this_obj == NULL || arg_count < 2)
        return result;

    // arg[0] = property name (string)
    // arg[1] = callback (must be function)
    // arg[2] = userData (optional)

    // Get property name
    char name_buf[256];
    u32 name_len = varToUtf8(&args[0], name_buf, sizeof(name_buf));
    if (name_len == 0) return result;

    // Validate callback is a function
    if (args[1].type != ACTION_STACK_VALUE_FUNCTION)
        return result;

    ASFunction* callback = lookupFunctionFromVar(&args[1]);
    if (callback == NULL) return result;

    // Get userData (optional, defaults to undefined)
    ActionVar userData = { .type = ACTION_STACK_VALUE_UNDEFINED };
    if (arg_count >= 3)
        userData = args[2];

    // Register watch
    addWatch(app_context, this_obj, name_buf, name_len, callback, &userData);

    result.data.numeric_value = VAL_ENCODE(float, 1.0f); // true
    return result;
}

// Object.prototype.unwatch(property)
ActionVar builtinObjectUnwatch(SWFAppContext* app_context,
                               ActionVar* args, u32 arg_count,
                               ActionVar* registers, ASObject* this_obj)
{
    ActionVar result = { .type = ACTION_STACK_VALUE_BOOLEAN };
    result.data.numeric_value = 0; // false

    if (this_obj == NULL || arg_count < 1)
        return result;

    char name_buf[256];
    u32 name_len = varToUtf8(&args[0], name_buf, sizeof(name_buf));
    if (name_len == 0) return result;

    if (removeWatch(this_obj, name_buf, name_len))
    {
        result.data.numeric_value = VAL_ENCODE(float, 1.0f); // true
    }
    return result;
}
```

### Watch Callback Invocation

```c
ActionVar invokeWatch(SWFAppContext* app_context, ASObject* obj,
                      WatchEntry* watch,
                      const char* name, u32 name_length,
                      ActionVar* oldVal, ActionVar* newVal)
{
    // Build arguments: (property, oldVal, newVal, userData)
    ActionVar args[4];
    args[0] = makeStringVar(name, name_length);  // property name
    args[1] = *oldVal;
    args[2] = *newVal;
    args[3] = watch->userData;

    // Invoke the callback with 'this' = the watched object
    ActionVar result = invokeSpecialFunction(app_context, watch->callback, obj);
    // Note: invokeSpecialFunction needs to be extended to pass args+argcount

    return result;
}
```

**Important**: `invokeSpecialFunction` currently only passes a single setter argument. We need to either:
- Extend it to accept an args array + count, OR
- Push args onto the stack before calling (for DefineFunction type 1), or pass via registers (for type 2)

The cleanest approach is to create a new `invokeWatchCallback()` that handles the 4-argument call directly, similar to how `actionCallMethod` dispatches function calls.

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/include/actionmodern/object.h` | Add `WatchEntry` struct, `watches`/`watch_count`/`watch_capacity` fields to `ASObject` |
| `SWFModernRuntime/src/actionmodern/object.c` | `findWatch`, `addWatch`, `removeWatch` helpers; watch check in `setProperty()`; cleanup watches in `freeObject()` |
| `SWFModernRuntime/src/actionmodern/action.c` | Register `watch`/`unwatch` on `g_object_prototype`; `builtinObjectWatch`/`builtinObjectUnwatch`; watch check in MovieClip property-set path in `actionSetMember` |

No recompiler changes needed — `watch()` and `unwatch()` are called via `actionCallMethod` which looks up the method on the prototype chain. Since we register them on `Object.prototype`, they'll be found automatically.

---

## Implementation Order

### Step 1: Data structures (object.h)

Add `WatchEntry` typedef and the 3 new fields to `ASObject`. Initialize them to 0/NULL in `allocObject()`.

### Step 2: Watch management functions (object.c)

Implement `findWatch`, `addWatch`, `removeWatch`. Add watch cleanup to `freeObject()` (free names, release callback refcounts, free userData objects, free watches array).

### Step 3: Register watch/unwatch on Object.prototype (action.c)

Add `g_object_watch_func` and `g_object_unwatch_func` static ASFunction instances. Register them in `getObjectPrototype()`. Implement `builtinObjectWatch` and `builtinObjectUnwatch`. Mark both as DontEnum via `ASSetPropFlags`.

### Step 4: Watch invocation in setProperty (object.c)

Add the watch callback check at the top of `setProperty()`. This handles the common case of setting properties on ASObject instances. The callback is invoked with 4 arguments and its return value replaces the assigned value. If the callback throws, the value becomes undefined.

### Step 5: Watch invocation in MovieClip property paths (action.c)

Add watch checking in `actionSetMember()` for MovieClip objects, specifically for `dynamic_props` property sets. This is needed for `watch_textfield` (watching `text` on a TextField MovieClip).

### Step 6: Test and verify

```bash
python3 ruffle-tests/verify_output.py --test=watch --diff --verbose
python3 ruffle-tests/verify_output.py --test=watch_textfield --diff --verbose
python3 ruffle-tests/verify_output.py --test=watch_virtual_property --diff --verbose
python3 ruffle-tests/verify_output.py --test=watch_virtual_property_proto --diff --verbose
```

---

## Edge Cases and Gotchas

### 1. Recursive watch prevention
If the watch callback itself assigns to the watched property, it should NOT re-trigger the watch (infinite recursion). Flash prevents this — we need a `watch_firing` flag or depth guard.

### 2. Exception handling in callback
From the `watch` test lines 63-81: if the callback throws, the property value becomes `undefined`. We need try/catch around the callback invocation. The current `invokeSpecialFunction` doesn't handle exceptions — we may need to check `g_try_catch_depth` or similar.

### 3. `this` context for watch callbacks
The `watch_textfield` test shows `this` is the watched object (`_level0.text_field`). The `watch` test's LoggingWatcher shows `this` is the LoggingWatcher instance. So `this_obj` in the callback must be the object that `watch()` was called on.

### 4. Boolean return encoding
`watch()` and `unwatch()` return boolean `true`/`false`. Flash booleans need specific encoding — check how other builtins (hasOwnProperty) return booleans.

### 5. Watch survives `delete`
The `watch` test (lines 38-43) shows that `delete variable` removes the value but the watcher persists. After delete, `oldVal` becomes `undefined` for the next assignment. This means `deleteProperty()` in object.c must NOT remove watch entries.

### 6. Property name case sensitivity
Watch property names should follow the same case sensitivity rules as the SWF version (case-insensitive in SWF6, case-sensitive in SWF7+). Use the same comparison as `setProperty`/`getProperty`.

### 7. Virtual property interaction (low priority)
The `watch_virtual_property` test is `known_failure` even in Ruffle. The interaction between watch and addProperty is complex. For v1, don't worry about this — focus on getting the other 3 tests passing.

---

## Expected Results

| Test | Before | After (expected) |
|------|--------|-------------------|
| `watch` | 0/119 (0%) | ~115/119 (~97%) |
| `watch_textfield` | 0/13 (0%) | 13/13 (100%) |
| `watch_virtual_property` | 0/62 (0%) | Partial — known_failure even in Ruffle |
| `watch_virtual_property_proto` | 0/3 (0%) | 3/3 (100%) |

**Net new tests passing**: ~3 tests (watch, watch_textfield, watch_virtual_property_proto). The watch_virtual_property test won't count against us since it's a known_failure.

---

## Risks

1. **invokeSpecialFunction limitations**: The current helper only supports 0 or 1 arguments. Watch callbacks need 4 arguments. We'll need to extend the invocation mechanism or write a dedicated `invokeWatchCallback` that pushes args onto the stack / passes via registers properly.

2. **MovieClip property interception**: MovieClip built-in properties (_x, _y, _name, etc.) are set directly on the C struct, not through `setProperty()`. Watching these may require additional hooks in the MovieClip property-set path. The `watch_textfield` test only watches `text` which goes through `dynamic_props`, so this may not be needed for the initial 4 tests.

3. **Refcounting**: Watch entries hold references to callback functions and userData values. Must properly retain/release these on add, replace, remove, and object destruction.
