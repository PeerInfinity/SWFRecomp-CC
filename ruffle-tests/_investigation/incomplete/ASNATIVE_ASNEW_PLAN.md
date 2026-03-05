# ASnative / ASNew Implementation Plan
<!-- TESTS: asnative, asnew -->

Last updated: 2026-03-04

## Status: BLOCKED — needs native function dispatch table

### Overview

`ASnative(class_id, method_id)` resolves Flash Player's internal native function table, returning a reference to a built-in function by its class/method index pair. `ASNew` is `ASnative(2, 0)` — the internal constructor function. These are low-level introspection APIs used by some SWFs to bypass the normal global scope chain.

### Tests

| Test | Lines | Current | Description |
|------|-------|---------|-------------|
| asnative | 34 | ~19/34 (56%) | Tests ASnative resolution with various class/method pairs, string coercion, invalid args |
| asnew | 34 | ~10/34 (29%) | Tests ASNew (ASnative(2,0)) as a constructor, apply/call/property/resolve contexts |

### What the Tests Expect

#### asnative test
```
ASnative(100, 0)  → [type Function]    // Object.prototype methods start at 100
ASnative(100, "string") → [type Function]  // String arg coerced to number
ASnative(100, 0, 0) → undefined        // 3+ args → undefined
ASnative("100", "0") → [type Function] // String args coerced
ASnative(100.5, 0) → undefined         // Float class_id → undefined (or truncated?)
```

Key native function class IDs (from Flash Player documentation):
- 100: Object.prototype (0=addProperty, 2=valueOf, etc.)
- 101: Object constructor methods
- 200: Math methods
- 250: Array methods
- 251: String methods
- 252: Boolean methods
- 253: Number methods
- 300: MovieClip methods

#### asnew test
```
ASnew = ASnative(2, 0)  → [type Function]
ASnew()                  → false (creates empty object, typeof == "object", not a boolean)
ASnew.apply(null, [])    → false
ASnew.call(null)         → false
```
The returned value from `ASnew()` is a newly created Object (like `new Object()`), which traces as "false" because `toString()` on a plain object returns... actually it might be returning a Boolean false. Need to investigate.

### Implementation

#### Phase 1: ASnative Dispatch Table (~80 lines)

Create a lookup table mapping (class_id, method_id) → function pointer:

```c
typedef struct {
    int class_id;
    int method_id;
    const char* name;
    void* func_ptr;   // SimpleFunctionPtr or Function2Ptr
    u8 func_type;     // 1 or 2
} NativeFunctionEntry;

static NativeFunctionEntry g_native_functions[] = {
    // Object.prototype (class 100)
    {100, 0, "addProperty", ...},
    {100, 2, "valueOf", ...},
    {100, 4, "toString", ...},
    {100, 6, "hasOwnProperty", ...},
    // ... etc
    // Math (class 200)
    {200, 0, "abs", ...},
    {200, 1, "min", ...},
    // ...
};
```

`actionGetVariable("ASnative")` returns a built-in function. When called:
1. Pop 2 args (class_id, method_id), coerce to integers
2. If 3+ args or non-integer class_id → return undefined
3. Look up in dispatch table
4. Return an ASFunction wrapping the native function, or undefined if not found

#### Phase 2: ASNew (ASnative(2, 0)) (~20 lines)

`ASnative(2, 0)` returns the internal `new Object()` constructor:
- When called with no args, creates and returns a new empty Object
- When called with args, creates an Object wrapping the first argument

### Blockers

**Difficulty**: MEDIUM. The main challenge is populating the dispatch table with the correct class/method mappings. Flash Player's internal function table has hundreds of entries. We only need to implement the ones tested:
- Class 2, method 0: ASNew (object constructor)
- Class 100: Object.prototype methods
- A few others depending on what the test checks

The full native function table is documented in various Flash Player reverse-engineering resources. We can start with a minimal table covering just the tested indices.

**Self-contained**: No external dependencies beyond existing built-in function implementations.

### Estimated Impact

~100 lines of code. Should bring:
- asnative: 19/34 → ~30-34/34
- asnew: 10/34 → ~25-34/34

### Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Add `actionASnative()` function, native dispatch table, register "ASnative" as global |

### Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=asnative --diff --verbose
python3 ruffle-tests/verify_output.py --test=asnew --diff --verbose
```
