# With Statement Scope Implementation Plan
<!-- TESTS: with, with_variable_scopes, define_local, this_scoping, closure_scope -->

Last updated: 2026-02-22

## Status: ALL PHASES (1-5) COMPLETE

### Results
- **`with_variable_scopes`**: 24/43 → **43/43 (PASS)** ✅
- **`with`**: 30/49 → **49/49 (PASS)** ✅
- **`closure_scope`**: **PASS** ✅ (closure scope chain capture working)
- **`define_local`**: output_mismatch (DefineLocal with virtual property setters — separate issue)
- **`this_scoping`**: output_mismatch (partial — `this` binding in some call contexts still differs)

### Implementation Summary
All 5 phases have been implemented:
- **Phase 1**: Function vs WITH scope distinction (`scope_is_with[]` array) ✅
- **Phase 2**: MovieClip identity in scope chain (`scope_mc[]` array, MC builtin property lookup) ✅
- **Phase 3**: with(undefined/null) skip (returns 0, recompiler wraps body in conditional) ✅
- **Phase 4**: addProperty getters/setters in scope chain (virtual property checking via `findPropertyStructWithPrototype`) ✅
- **Phase 5**: Primitive wrapping (string wrapping creates temporary ASObject with length/valueOf) ✅
- **Bonus**: Closure scope capture (`captured_scope[]`, `captured_scope_mc[]`, `captured_scope_is_with[]` on ASFunction) ✅

## Overview

The `with` statement pushes an object onto the scope chain for variable lookup within a block. Two Ruffle tests cover this feature:

1. **`with`** — was 30/49 lines passing (61%). Tests basic `with(clip)`, `with(string)`, `with(object)`, `this` resolution, addProperty getters, and `with(undefined/null)` error handling.
2. **`with_variable_scopes`** — was 24/43 (56%), now **PASSING**.

**Root cause**: 6 distinct bugs in the runtime, the most critical being that `DefineLocal` writes to the `with` object instead of the function's local scope. All bugs are in `SWFModernRuntime/src/actionmodern/action.c` (with one recompiler change needed for the null/undefined skip).

## Current Architecture

The scope chain is a global static array:

```c
#define MAX_SCOPE_DEPTH 32
static ASObject* scope_chain[MAX_SCOPE_DEPTH];
static u32 scope_depth = 0;
```

Both function calls and `with` blocks push entries onto the same chain:
- `actionCallFunction` creates a local `ASObject*` and pushes it
- `actionWithStart` pops the `with` argument and pushes it (or NULL for non-objects)
- `actionWithEnd` decrements `scope_depth`

Variable lookup walks the chain top-to-bottom:
- `actionGetVariable`: checks each `scope_chain[i]` for the property, returns first match
- `actionSetVariable`: checks each `scope_chain[i]` for the property, sets on first match, else falls through to global
- `actionDefineLocal`: **BUG** — always writes to `scope_chain[scope_depth - 1]` (the innermost scope, which may be a `with` scope instead of a function scope)

---

## Bug Analysis

### Bug 1 (HIGH): `DefineLocal` targets `with` scope instead of function scope

**File**: `action.c` lines 9718-9732 (`actionDefineLocal`) and 9806-9809 (`actionDeclareLocal`)

**Current code**:
```c
if (scope_depth > 0 && scope_chain[scope_depth - 1] != NULL)
{
    ASObject* local_scope = scope_chain[scope_depth - 1];
    setProperty(app_context, local_scope, var_name, var_name_len, &value_var);
}
```

**Problem**: When inside `with(o)` inside a function, the scope chain is:
```
scope_chain[0] = function local scope
scope_chain[1] = o (with object)     <-- scope_depth-1
```

`DefineLocal` writes to `scope_chain[1]` (the with object), but Flash requires `DefineLocal` to always target the nearest **function** scope, skipping any `with` entries.

**Impact**: 14+ lines in `with_variable_scopes` — all `DefineLocal` calls inside `with` blocks put variables on the wrong scope.

### Bug 2 (HIGH): `with(movieclip)` doesn't expose built-in MC properties

**File**: `action.c` lines 14848-14860 (`actionWithStart`)

**Current code**:
```c
else if (obj_var.type == ACTION_STACK_VALUE_MOVIECLIP)
{
    MovieClip* mc = (MovieClip*) obj_var.data.numeric_value;
    if (mc != NULL && scope_depth < MAX_SCOPE_DEPTH)
    {
        if (mc->dynamic_props == NULL)
            mc->dynamic_props = (void*) allocObject(app_context, 8);
        scope_chain[scope_depth++] = (ASObject*) mc->dynamic_props;
    }
}
```

**Problem**: Only `mc->dynamic_props` is pushed, so built-in MC properties (`_x`, `_y`, `_name`, etc.) are invisible in the scope chain. `with(clip) { _x }` reads root's `_x` instead of clip's.

**Impact**: Lines 3, 9, 15 of `with` test.

### Bug 3 (HIGH): `with(undefined/null)` executes the body instead of skipping

**File**: `action.c` line 14867-14873 (`actionWithStart`) + `action.cpp` lines 1521-1558

**Problem**: When the `with` argument is `undefined` or `null`, Flash should:
1. Print error: `Error: A 'with' action failed because the specified object did not exist.\n`
2. **Skip the entire body** (do not execute any code inside the block)

Currently, a NULL marker is pushed and the body always executes.

**Impact**: Lines 45, 49 of `with` test — "unreachable" is printed when it shouldn't be.

### Bug 4 (MEDIUM): addProperty getters not checked during scope chain lookup

**File**: `action.c` lines 8883-8897 (`actionGetVariable` scope chain loop)

**Problem**: `getProperty()` finds regular properties but does NOT check the `VirtualProperty` table (addProperty getters/setters). When `o.addProperty("prop", getter, null)` is set up, `with(o) { prop }` should invoke the getter, but `getProperty` doesn't see it.

**Impact**: Lines 32, 35 of `with` test.

### Bug 5 (MEDIUM): `this` inside function called from `with` block resolves incorrectly

**File**: `action.c` — `this` resolution in function calls from within `with` blocks

**Problem**: When `f()` is called inside `with(o)`, the `this` binding should be `o` (the with object), not the root movieclip. The test expects:
```
with(o) { trace(typeof this); trace(this._name); }  // "object", undefined (or "root")
```
Actually re-reading the expected output more carefully: `typeof this` = `object` and `this._name` = `root`. The `this` should resolve to `_root` but `typeof this` should be `movieclip`. Let me re-check — the expected output line 41 is `object` and line 42 is `root`. Currently getting `root` and blank. The issue may be that `this` inside the with block resolves differently.

**Impact**: Lines 41-42 of `with` test.

### Bug 6 (LOW): `with(string)` doesn't wrap primitive in String object

**File**: `action.c` lines 14867-14873 (`actionWithStart`)

**Problem**: For non-object types (string, number, boolean), Flash wraps the primitive in the corresponding wrapper object (String, Number, Boolean) before pushing to scope chain. Currently a NULL is pushed.

**Impact**: Line 13 of `with` test — `with('STRING') { length }` returns `undefined` instead of `6`.

---

## Implementation Plan

### Phase 1: Distinguish function scopes from with scopes

**Goal**: Fix Bug 1 — `DefineLocal`/`DeclareLocal` must target the function scope, not the `with` scope.

**Approach**: Add a parallel boolean array to track which scope chain entries are `with` scopes vs function scopes:

```c
static ASObject* scope_chain[MAX_SCOPE_DEPTH];
static u8 scope_is_with[MAX_SCOPE_DEPTH];  // NEW: 1 = with scope, 0 = function scope
static u32 scope_depth = 0;
```

**Changes**:

1. In `actionWithStart`: set `scope_is_with[scope_depth] = 1` before `scope_depth++`
2. In `actionCallFunction` (and `actionCallMethod`, `actionDefineFunction2`, etc.): set `scope_is_with[scope_depth] = 0` before `scope_depth++`
3. In `actionDefineLocal`: walk DOWN the scope chain to find the first entry where `scope_is_with[i] == 0`, then define the variable there:

```c
// Find the nearest function scope (skip with scopes)
for (int i = scope_depth - 1; i >= 0; i--)
{
    if (!scope_is_with[i] && scope_chain[i] != NULL)
    {
        setProperty(app_context, scope_chain[i], var_name, var_name_len, &value_var);
        POP_2();
        return;
    }
}
// Fall through to global if no function scope found
```

4. Same change in `actionDeclareLocal` (DefineLocal2 — declares without value).

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=with_variable_scopes --diff --verbose
```

### Phase 2: MovieClip identity in scope chain

**Goal**: Fix Bug 2 — `with(movieclip)` must expose built-in properties like `_x`, `_y`.

**Approach**: Store the original MovieClip pointer alongside the scope chain entry so that variable lookup can check MC built-in properties. Add a parallel array:

```c
static MovieClip* scope_mc[MAX_SCOPE_DEPTH];  // NEW: non-NULL if scope entry is a MovieClip
```

**Changes**:

1. In `actionWithStart` for MOVIECLIP type: set `scope_mc[scope_depth] = mc` and still push `mc->dynamic_props` to `scope_chain[scope_depth]`
2. For all other types: set `scope_mc[scope_depth] = NULL`
3. In `actionGetVariable` scope chain loop: if `scope_mc[i] != NULL`, also check MC built-in properties (reuse existing MC property lookup logic). Check dynamic_props first, then MC built-ins.
4. In `actionSetVariable` scope chain loop: same — if `scope_mc[i] != NULL` and the property is a built-in MC property (`_x`, `_y`, etc.), set it on the MovieClip.

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=with --diff --verbose
```

### Phase 3: with(undefined/null) skip

**Goal**: Fix Bug 3 — `with(undefined)` and `with(null)` skip the body and print error.

**Approach**: Change `actionWithStart` to return a boolean, and change the recompiler to emit conditional execution.

**Recompiler change** in `action.cpp`:
```cpp
// Before:
out_script << "\t" << "actionWithStart(app_context);" << endl;
out_script << "\t" << "{" << endl;
// ... body ...
out_script << "\t" << "}" << endl;
out_script << "\t" << "actionWithEnd(app_context);" << endl;

// After:
out_script << "\t" << "if (actionWithStart(app_context)) {" << endl;
// ... body ...
out_script << "\t" << "}" << endl;
out_script << "\t" << "actionWithEnd(app_context);" << endl;
```

**Runtime change**: Change `actionWithStart` return type from `void` to `int`:
- Return `1` (true) if the with scope was successfully pushed (body should execute)
- Return `0` (false) if the argument was null/undefined (body should be skipped)
- When returning 0, still increment `scope_depth` with a NULL marker (so `actionWithEnd` can decrement properly), but print the error message

Actually, simpler: when returning 0, do NOT push anything to the scope chain (don't increment scope_depth), and have the `actionWithEnd` call conditional on the same flag. OR: always push/pop, but use the return value to skip the body.

Cleanest approach: always push (NULL marker for invalid), always pop. Return 0 for skip. The recompiler wraps the body in `if (actionWithStart(...)) { ... }`. `actionWithEnd` always pops.

**Also update** `action.h` signature: `int actionWithStart(SWFAppContext* app_context);`

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=with --diff --verbose
```

### Phase 4: addProperty getters in scope chain lookup

**Goal**: Fix Bug 4 — scope chain lookup should check virtual properties (addProperty).

**Approach**: In the scope chain loop within `actionGetVariable` and `actionSetVariable`, after checking `getProperty()`, also check the virtual property table.

The existing `getPropertyVirtual()` or equivalent function needs to be called. Look at how `actionGetMember` handles addProperty — it likely checks a `VirtualProperty*` list on the ASObject. The scope chain lookup should do the same.

**Changes**:

1. In `actionGetVariable` scope chain loop: after `getProperty()` returns NULL, check `findVirtualProperty(scope_chain[i], var_name)`. If found, call the getter function and push the result.
2. In `actionSetVariable` scope chain loop: same — check virtual properties. If a virtual setter exists, call it.

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=with --diff --verbose
```

### Phase 5: Primitive wrapping (string/number/boolean)

**Goal**: Fix Bug 6 — `with("STRING")` wraps the string in a String object.

**Approach**: In `actionWithStart`, for string/number/boolean types, create a wrapper object with the appropriate prototype and push it onto the scope chain.

For strings:
- Create a new ASObject
- Set `__proto__` to `String.prototype`
- Set `length` property to string length
- Push onto scope chain

For numbers and booleans: similar wrapping with Number.prototype / Boolean.prototype. These are less commonly used with `with` but should be correct.

**Note**: This is lower priority since `with(string)` is an unusual pattern. The test has only 1 line affected.

**Verification**:
```bash
python3 ruffle-tests/verify_output.py --test=with --diff --verbose
```

---

## Phase Dependencies

```
Phase 1 (DefineLocal scoping) ──→ standalone, highest impact
Phase 2 (MC identity) ──→ standalone
Phase 3 (null/undefined skip) ──→ standalone, requires recompiler + runtime
Phase 4 (addProperty in scope) ──→ standalone
Phase 5 (primitive wrapping) ──→ standalone, lowest priority
```

All phases are independent of each other. Phase 1 has the highest impact on `with_variable_scopes`. Phases 2+3 have the highest impact on `with`.

---

## Expected Test Impact

### `with` test (49 lines)

| Phase | Lines Fixed | Details |
|-------|-----------|---------|
| Current | 30/49 (61%) | Baseline |
| Phase 2 | +3 | `_x` read/write inside `with(clip)` |
| Phase 3 | +4 | `with(undefined/null)` skip + error messages |
| Phase 4 | +2 | addProperty getter in scope chain |
| Phase 5 | +1 | `with('STRING') { length }` |
| **Total** | **~40/49 (82%)** | Remaining failures likely `this` resolution edge cases |

### `with_variable_scopes` test (44 lines)

| Phase | Lines Fixed | Details |
|-------|-----------|---------|
| Current | 25/44 (56%) | Baseline |
| Phase 1 | +10-14 | DefineLocal targets function scope correctly |
| **Total** | **~35-39/44 (80-89%)** | Remaining may need `this` scoping fixes |

### Combined: ~75-89% across both tests (up from ~59%)

---

## Files to Modify

### Runtime (`SWFModernRuntime/`)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | All 5 phases — scope chain infrastructure, variable lookup, `actionWithStart`/`actionWithEnd`, `actionDefineLocal`/`actionDeclareLocal` |
| `include/actionmodern/action.h` | Change `actionWithStart` return type from `void` to `int` |

### Recompiler (`SWFRecomp/`)

| File | Changes |
|------|---------|
| `src/action/action.cpp` | Phase 3 — wrap `with` body in `if (actionWithStart(...))` conditional |

### Side effects to verify

The scope chain changes (Phase 1 especially) affect ALL code that uses `scope_chain`/`scope_depth`, not just `with` blocks. Must verify:
- Function calls still work (scope pushed/popped correctly)
- Nested function calls with `with` blocks
- `closure_scope` test (if it uses `with`)
- `define_local` test
- `this_scoping` test

```bash
# Run broader regression check
python3 ruffle-tests/verify_output.py --test=with --test=with_variable_scopes --test=define_local --test=this_scoping --test=closure_scope --diff --verbose
```

---

## Design Decisions

1. **Parallel arrays vs struct**: Using parallel arrays (`scope_is_with[]`, `scope_mc[]`) alongside `scope_chain[]` rather than a struct. This keeps the change minimal and avoids touching every place that accesses `scope_chain[i]`.

2. **Always push/pop for null/undefined with**: Even when `with(undefined)` should skip the body, we push a NULL marker and pop it in `actionWithEnd`. This keeps the push/pop balanced and avoids needing to track whether the body was skipped for the `actionWithEnd` call.

3. **MC property lookup order**: For `with(movieclip)`, check `dynamic_props` first, then MC built-in properties. This matches Flash behavior where dynamically-set properties shadow built-in ones.

4. **No changes to `actionGetVariable`/`actionSetVariable` core logic**: The existing scope chain walk in these functions (check each scope, first match wins) is correct for `with` semantics. Only `actionDefineLocal`/`actionDeclareLocal` need the function-scope distinction.
