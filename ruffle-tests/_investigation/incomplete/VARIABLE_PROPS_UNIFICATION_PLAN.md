# Variable/Props Unification Plan

## Overview

The runtime has two separate storage mechanisms for MovieClip properties that are out of sync:

1. **Timeline variables (`var_map`/`var_array`)** — Global hashtable + indexed array, used by `SetVariable`/`GetVariable`
2. **Dynamic properties (`dynamic_props`)** — Per-object ASObject property storage, used by `SetMember`/`GetMember`

When `SetVariable("onEnterFrame", func)` is called on root MC, the handler goes into `var_map`. But `actionDispatchEnterFrameHandlers()` only checks `dynamic_props`, so the handler is never found.

**Blocks:**
- TELLTARGET_PLAN: `string_paths_variable_scopes` (0/5)
- Potentially other tests that set AS2 handlers via SetVariable instead of SetMember

**Test directly unblocked:**
| Test | Current | Expected |
|------|---------|----------|
| `string_paths_variable_scopes` | 0/5 | 5/5 |

---

## Root Cause Analysis

### SetVariable Path (stores to var_map)

`actionSetVariable()` (action.c ~line 18654):
- Pops name and value from stack
- At timeline level (no function scope): stores in global `var_map` or `var_array`
- Inside `tellTarget` on non-root MC: stores in `g_current_context->dynamic_props`
- Does NOT propagate to `dynamic_props` for root MC

### SetMember Path (stores to dynamic_props)

`actionSetMember()` (action.c ~line 21746):
- Pops object, name, value from stack
- For MOVIECLIP type: stores in MC's `dynamic_props`
- For root MC: ALSO propagates to global `var_map` via `setVariableByName()` (lines 23291-23293)

### The Asymmetry

SetMember → dynamic_props (primary) + var_map (root MC only)
SetVariable → var_map (primary) + dynamic_props (**MISSING**)

### Dispatch Paths

`actionDispatchEnterFrameHandlers()` (action.c ~line 15925):
- Iterates `child_mc_cache` checking each MC's `dynamic_props`
- Uses `getProperty(props, "onEnterFrame", 12)` to find handler
- Works when handler set via SetMember

`actionDispatchRootVarMapEnterFrame()` (action.c ~line 16025):
- Checks global `var_map` for "onEnterFrame"
- Has double-fire protection: skips if dynamic_props also has onEnterFrame
- **NOT called from Ruffle test framework** — only called from old test suite's `swf_core.c` path

### The Test

`string_paths_variable_scopes/script_0.c` does:
```c
// SetVariable("onEnterFrame", <anonymous function>)
actionSetVariable(app_context, str_1, str_1_len, &func_var);
```

This stores the function in `var_map`. The enterFrame dispatcher checks `dynamic_props` → finds nothing → handler never fires.

---

## Solution Options

### Option A: Propagate SetVariable to dynamic_props for handler names (Targeted)

In `actionSetVariable()`, after storing in var_map, also store in root MC's `dynamic_props` when the property name is a known handler:

```c
// After var_map storage for root MC context:
if (is_root_mc_context) {
    setProperty(app_context, root_mc->dynamic_props, prop_name, prop_name_len, &value_var);
}
```

**Pros:** Surgical, matches SetMember's existing bidirectional behavior
**Cons:** Only covers root MC; child MCs with SetVariable still break

### Option B: Always propagate SetVariable to dynamic_props (Broader)

In `actionSetVariable()`, for any MC-scoped variable, also store in MC's `dynamic_props`:

```c
// After var_map storage, if current context is a known MC:
if (g_current_context != NULL) {
    ASObject* props = g_current_context->dynamic_props;
    if (props) {
        setProperty(app_context, props, prop_name, prop_name_len, &value_var);
    }
}
```

**Pros:** Handles all MCs, not just root
**Cons:** May cause unexpected double-storage; needs careful testing

### Option C: Unify dispatch to check both (Safest)

Modify `actionDispatchEnterFrameHandlers()` to also check `var_map` for each MC:

```c
// After checking dynamic_props:
if (!found_handler) {
    // Check var_map for this MC's onEnterFrame
    ActionVar var_map_handler = getVariable("onEnterFrame", 12);
    if (var_map_handler.type == ACTION_STACK_VALUE_FUNCTION) {
        found_handler = 1;
        // invoke it
    }
}
```

**Pros:** No storage changes, dispatch finds handlers regardless of storage path
**Cons:** Performance cost of extra lookup per MC per frame; complex scoping for non-root MCs

### Option D: Propagate SetVariable to dynamic_props for root MC (Recommended)

Mirror the SetMember behavior: SetMember on root MC propagates to var_map; SetVariable on root MC should propagate to dynamic_props.

In `actionSetVariable()`, at the point where root MC timeline vars are stored (~line 18948):

```c
// Store in var_map (existing)
setVariableByName(var_name, var_name_len, &value_var);

// NEW: Also store in root MC dynamic_props (mirrors SetMember bidirectional)
if (g_current_context == &root_movieclip || g_current_context == NULL) {
    ASObject* props = root_movieclip.dynamic_props;
    if (props) {
        setProperty(app_context, props, var_name, var_name_len, &value_var);
    }
}
```

**Pros:** Simple, consistent with existing SetMember behavior, fixes the exact disconnect
**Cons:** Only fixes root MC (but that's where most timeline SetVariable calls target)

---

## Recommended Approach: Option D

Option D is the simplest and most consistent fix. It mirrors the existing bidirectional propagation that SetMember already does for root MC.

### Implementation Steps

1. **Locate the SetVariable root MC storage path** in `actionSetVariable()` (~line 18948)
2. **Add dynamic_props propagation** after var_map storage
3. **Test** with `string_paths_variable_scopes`
4. **Regression test** existing passing tests

### Additional Consideration

The test also involves `attachMovie` and path resolution (`this`, `_root`, slash paths). The 5 expected output lines are:

```
10              // timer value
[object Object] // this reference
[object Object] // _root reference
true            // this == _root
[object Object] // path resolution
```

The onEnterFrame handler prints these values. If the handler never fires, all 5 lines are missing. Fixing the propagation should make the handler fire, and the output should match if path resolution is correct.

---

## Files to Modify

- `action.c`: `actionSetVariable()` — add dynamic_props propagation for root MC context

---

## Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=string_paths_variable_scopes --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_paths_basic --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_paths_hidden --diff --verbose
python3 ruffle-tests/verify_output.py --test=path_string --diff --verbose
python3 ruffle-tests/verify_output.py --test=this_scoping --diff --verbose
python3 ruffle-tests/verify_output.py --test=execution_order4 --diff --verbose
python3 ruffle-tests/verify_output.py --test=clip_events --diff --verbose
python3 ruffle-tests/verify_output.py --test=create_empty_movie_clip --diff --verbose
```

---

## Estimated Effort

**Small** — ~15 lines of code change. The fix is well-understood and mirrors existing behavior. Main risk is ensuring no regressions from double-storage.
