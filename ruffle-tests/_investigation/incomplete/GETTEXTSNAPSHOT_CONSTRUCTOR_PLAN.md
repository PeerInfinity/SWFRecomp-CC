# getTextSnapshot User Constructor Plan
<!-- TESTS: movieclip_gettextsnapshot -->

Last updated: 2026-03-06

## Status: ACTIONABLE — not blocked

### Overview

`getTextSnapshot()` should invoke the user-defined `_global.TextSnapshot` constructor (if overridden) instead of returning a built-in TextSnapshot object. The existing TEXTSNAPSHOT_PLAN implemented the built-in TextSnapshot functionality (getCount, getText, findText), but didn't handle the case where user code overrides `_global.TextSnapshot`.

**Test**: `movieclip_gettextsnapshot` — 6/112 (5%). The test replaces `_global.TextSnapshot` with a custom constructor, then verifies that `getTextSnapshot()` instantiates through it.

### Observed Failures

```
Expected:                                  Actual:
TextSnapshot instantiated:                 this.getTextSnapshot()=[object Object]
  a=_level0                                is _global.TextSnapshot: false
  b=undefined                              is oldTextSnapshot: false
  c=undefined
  typeof a=movieclip
  typeof b=undefined
  typeof c=undefined
this.getTextSnapshot()=[object Object]
is _global.TextSnapshot: true
```

The test's custom constructor traces its arguments and sets properties. Our built-in `getTextSnapshot()` creates a native TextSnapshot object directly, bypassing the user's constructor entirely. The `is _global.TextSnapshot: false` confirms the returned object's `__proto__` doesn't point to the user's constructor prototype.

### Flash Semantics

In Flash Player:
1. `mc.getTextSnapshot()` looks up `_global.TextSnapshot`
2. If it's a function, calls `new _global.TextSnapshot(mc)` — invoking the constructor with the MovieClip as the first argument
3. The returned object is an instance of whatever `_global.TextSnapshot` points to
4. If `_global.TextSnapshot` is missing or not a function, behavior varies (likely returns undefined or a default object)

### Fix

**Phase 1: Invoke user constructor** (~30 lines)

In the `getTextSnapshot` handler (likely in actionCallMethod's MC builtin dispatch), instead of creating a built-in TextSnapshot:

```c
// Look up _global.TextSnapshot
ensureGlobalInit(app_context);
ASObject* global = getActiveGlobal();
ActionVar* ts_ctor_var = getPropertyWithPrototype(global, "TextSnapshot", 12);

if (ts_ctor_var != NULL && ts_ctor_var->type == ACTION_STACK_VALUE_FUNCTION) {
    ASFunction* ts_ctor = (ASFunction*)(uintptr_t)ts_ctor_var->data.numeric_value;
    // Create new object with prototype
    ASObject* new_obj = allocObject(app_context, 4);
    retainObject(new_obj);
    if (ts_ctor->prototype_obj) {
        setObjectProtoObj(new_obj, ts_ctor->prototype_obj);
    }
    // Call constructor with mc as argument
    ActionVar mc_arg;
    mc_arg.type = ACTION_STACK_VALUE_MOVIECLIP;
    mc_arg.data.numeric_value = (u64)mc;
    // ... invoke ts_ctor with mc_arg, this=new_obj
    PUSH(ACTION_STACK_VALUE_OBJECT, (u64)new_obj);
} else {
    // Fall back to built-in TextSnapshot
    // (existing implementation)
}
```

**Phase 2: Dynamically created MC support** (lines 35-37 in diff)

The test also calls `getTextSnapshot()` on dynamically created MCs (`clip1`, `clip2`). The diff shows `clip1.getTextSnapshot=undefined` — meaning `getTextSnapshot` isn't registered as a method on dynamically created empty movie clips. Need to ensure all MCs have `getTextSnapshot` in their method dispatch.

**Phase 3: Child MC context** (lines 22-34)

The test calls `getTextSnapshot()` from within a child MC's script. The constructor should receive the child MC, not root. Verify that `g_current_context` or the method receiver is correctly passed.

### Expected Outcome

| Phase | Lines Gained | Test Result |
|-------|-------------|-------------|
| Phase 1 | +40-50 | ~50/112 |
| Phase 2 | +20-30 | ~80/112 |
| Phase 3 | +20-30 | ~100-112/112 |

### Dependencies

None — built-in TextSnapshot infrastructure already exists (TEXTSNAPSHOT_PLAN complete). This is about invoking the user's override constructor, not implementing TextSnapshot methods.

### Risks

- The test exercises `_global.TextSnapshot` override extensively across multiple contexts (root, child, dynamically created). Each context needs the same constructor invocation logic.
- Must not break existing TextSnapshot tests that use the built-in constructor (textsnapshot_gettext, textsnapshot_findtext, etc.).
- The constructor receives exactly 1 argument (the MovieClip). If the user's constructor expects different args, it should still work.
