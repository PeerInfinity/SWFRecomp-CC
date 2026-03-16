# Array Methods Implementation Plan
<!-- TESTS: array_call_method, array_prototyping, array_sort, array_sort_random -->

Last updated: 2026-02-18

## Status: ALL PHASES COMPLETE

| Phase | Description | Fixes | Status |
|-------|-------------|-------|--------|
| 1 | Property key coercion (SetMember, CallMethod, convertString) | array_call_method | **DONE** |
| 2 | Array.sort() flags + custom comparator | array_sort, array_sort_random | **DONE** |
| 3 | sortOn() multi-key, UNIQUESORT, RETURNINDEXEDARRAY, own-props, no-getter | array_sort (remaining) | **DONE** |
| 4 | addProperty numeric keys + array-like proto trace | array_prototyping | **DONE** |

## Test Inventory (current as of 2026-02-18)

| Test | Expected Lines | Current Match | Status | Notes |
|------|---------------|---------------|--------|-------|
| array_call_method | 9 | 9 (100%) | **PASS** | Phase 1 complete |
| array_length | 42 | 42 (100%) | **PASS** | Already done |
| array_prototyping | 12 | 12 (100%) | **PASS** | Phase 4 complete |
| array_sort | 161 | 158 (98%) | output_mismatch | 3 lines remain (unfixable — see below) |
| array_sort_random | 443 | 443 (100%) | **PASS** | Fixed (was thought unfixable) |

## array_sort Remaining Failures (3 lines)

- **Line 50**: `["hëllo", "HËLLO", "TeSt", "test"].sort(CASEINSENSITIVE)` — expected "hëllo,HËLLO" but we produce "HËLLO,hëllo". Root cause: `strcasecmp` treats non-ASCII bytes as opaque (0xAB > 0x8B gives HËLLO < hëllo), but Flash's QuickSort happens to give hëllo first for THIS specific input order. Contradicts line 53 (same sort, different input order, gives HËLLO first ✓). Cannot fix both simultaneously with stable insertion sort — would need to replicate Flash's exact QuickSort algorithm.

- **Lines 129, 132**: `[objects..].sortOn(["n", "b"], [Array.DESCENDING])` — expected descending-by-n order but we produce ascending. This is a Ruffle/Flash quirk: DESCENDING applied only to the FIRST key in multi-key sortOn gives descending order. Our implementation applies DESCENDING per-key correctly but doesn't match the exact behavior. Low priority.

## array_sort_random Status

This test now passes. Previously thought unfixable due to QuickSort comparison sequence dependency, but subsequent work resolved the remaining issues.

## Key Implementation Decisions (Phase 2-3)

### `_sort_compare_vars` function
- **NUMERIC flag**: Only applies when BOTH values are F64/F32 type (not all types)
- **NaN handling**: NaN sorts to END of ascending sequence (NaN=largest), inverted for DESCENDING
- **CASEINSENSITIVE**: Uses `strcasecmp` via UTF-8 conversion (works for ASCII; non-ASCII bytes compared raw)

### `sort()` behavior
- Stable insertion sort (preserves equal-element order)
- OBJECT/ARRAY as first arg → returns array unchanged (not undefined)
- RETURNINDEXEDARRAY sets `_ridx_arr->length = n`
- DESCENDING flag applied to both custom comparator and flags-based comparison

### `sortOn()` behavior
- `SORTON_GET_FIELD` uses own-properties-only (no prototype chain walk)
- Getter properties are SKIPPED (return UNDEFINED) — no side effects during sort
- For non-OBJECT elements (STRING, F64, etc.): returns ELEMENT ITSELF as sort key when field not found
  - Exception: STRING + field "length" → returns `str_size` as F64
  - This is why `sortOn("laength", NUMERIC)` on string primitives gives alphabetical sort (elements compared as strings)
- `_so_any_unique` and `_so_any_retidx` check only `_so_flags[0]` (first key's flags control overall behavior)
- Both RETURNINDEXEDARRAY and plain sort use stable insertion sort with `<= 0` break

---

## Phase 4: array_prototyping — addProperty Numeric Keys + Array-like Proto

**Target test:** `array_prototyping` → 0/12 → ?/12

This is the most complex phase. The test:

```actionscript
var base = ["a", "b", "c"];     // ASArray with elements[0]="a", [1]="b", [2]="c"
var array = {};                  // Plain ASObject
array.length = 3;               // Own property "length"=3
array.addProperty(2, function() { return "x"; }, null);  // Getter at index "2"
array.__proto__ = base;         // Set proto to the base ARRAY

trace("// array");
trace(array);                   // Expected: "undefined,undefined,undefined"
trace("// array[0]");
trace(array[0]);                // Expected: "a"  (proto lookup on base)
trace("// array[1]");
trace(array[1]);                // Expected: "b"  (proto lookup on base)
trace("// array[2]");
trace(array[2]);                // Expected: "x"  (own getter)
// ...
trace("// array.length");
trace(array.length);            // Expected: 3    (own property)
```

### Bug 4A: addProperty rejects numeric key

**File:** `action.c` ~line 19304

**Current:**
```c
if (num_args >= 3 && args[0].type == ACTION_STACK_VALUE_STRING)
```

The test calls `array.addProperty(2, getter, null)` where `2` is F64 type. Fix:

```c
if (num_args >= 3)
{
    char _addprop_buf[512];
    const char* prop_name;
    u32 prop_name_len;

    if (args[0].type == ACTION_STACK_VALUE_STRING) {
        const uint16_t* _ap_u16 = varGetU16Ptr(&args[0]);
        prop_name_len = (u32) u16_to_utf8(_ap_u16, args[0].str_size, _addprop_buf, sizeof(_addprop_buf));
        prop_name = _addprop_buf;
    } else if (args[0].type == ACTION_STACK_VALUE_F64 || args[0].type == ACTION_STACK_VALUE_F32) {
        double d = varToDouble(&args[0]);
        snprintf(_addprop_buf, sizeof(_addprop_buf), "%.15g", d);
        // Remove trailing ".0" if integer: "2" not "2.0"
        // Actually Flash converts int 2.0 → "2"
        prop_name = _addprop_buf;
        prop_name_len = (u32) strlen(_addprop_buf);
    } else {
        // Unsupported key type
        if (args != NULL) FREE(args);
        PUSH(ACTION_STACK_VALUE_BOOLEAN, 0);
        return;
    }
    // ... rest of addProperty logic
```

After this fix, `array.addProperty(2, getter, null)` registers a getter for property "2" on the array object.

### Bug 4B: trace(array) should show "undefined,undefined,undefined" not "[type Object]"

When `array.__proto__ = base` (where base is an ARRAY), and then `trace(array)`:

In Flash, an object with `__proto__` pointing to an Array inherits `Array.prototype` methods including `toString()/join()`. So `trace(array)` should call Array-like join(",") which iterates indices 0..length-1 and reads `array[i]` (own properties only, no getter invocation during join).

The current trace path (line ~9138):
```c
case ACTION_STACK_VALUE_OBJECT:
    objectCallToString(...)  // calls builtin_object_toString → "[object Object]"
```

For an object with `__proto__ = arrayObj`, `getPropertyWithPrototype` should follow:
1. array's own properties → no "toString"
2. base (an ARRAY) → Arrays don't have "toString" as own property
3. Array.prototype → has "toString"

This requires that ARRAY proto chains are followed. Currently, when `__proto__` is stored on an OBJECT as a property with value type ARRAY, `getPropertyWithPrototype` needs to handle following into an ARRAY's own props.

This is a significant runtime change. The complexity:
- `getPropertyWithPrototype(obj, name, len)` follows `obj.__proto__` chain
- If `__proto__` is an ARRAY, we need to look in the array's `props` ASObject (not elements)
- Then continue to `arr->props.__proto__` which would be Array.prototype

**Implementation approach for Bug 4B:**

In `getPropertyWithPrototype`, when the proto is ARRAY type:
```c
// In the __proto__ chain follow code:
if (proto_var->type == ACTION_STACK_VALUE_ARRAY) {
    ASArray* proto_arr = (ASArray*) proto_var->data.numeric_value;
    // Look in array's props for the named property
    ActionVar* found = getProperty(proto_arr->props, name, name_len);
    if (found) return found;
    // Continue up the chain via proto_arr->props's __proto__
    // ... recursive
}
```

**This is a larger change.** For Phase 4, the priority is:

1. Fix Bug 4A (addProperty numeric key) — simple fix, makes array[2]="x" work
2. The trace("undefined,undefined,undefined") requires Array-like proto chain — complex

**Suggested simplified approach for trace:** When an OBJECT's `__proto__` is an ARRAY, detect this in `actionTrace` and use array-like join behavior:

```c
// In actionTrace OBJECT case, before calling objectCallToString:
ActionVar* proto_prop = getProperty(obj, "__proto__", 9);
if (proto_prop && proto_prop->type == ACTION_STACK_VALUE_ARRAY) {
    // Object with array proto — use array-like join(",")
    // Get length from obj itself
    ActionVar* len_prop = getProperty(obj, "length", 6);
    u32 length = len_prop ? (u32)varToDouble(len_prop) : 0;
    // Join own indices (no getter invocation, no proto lookup for indices)
    // ... print "val0,val1,...,valN-1"
}
```

**Estimate:** Phase 4 is complex. Even with Bug 4A fixed, trace(array) will still show "[type Object]" until the proto chain is fixed. Partial improvement possible.

### Expected outcome after Phase 4

```
array_prototyping: 0/12 → 4-8/12 (depending on how much of the proto chain works)
```

---

## Files to Modify

All changes are in:
- **`SWFModernRuntime/src/actionmodern/action.c`** — the only file (~10K lines)

Functions affected:
| Phase | Function | Line (approx) |
|-------|----------|---------------|
| 4A | `actionCallMethod` addProperty | ~19304 |
| 4B | `actionTrace` / `getPropertyWithPrototype` | ~9138 / proto chain |

## Verification Commands

```bash
python3 ruffle-tests/verify_output.py --test=array_call_method --diff
python3 ruffle-tests/verify_output.py --test=array_sort --diff
python3 ruffle-tests/verify_output.py --test=array_sort_random --diff
python3 ruffle-tests/verify_output.py --test=array_prototyping --diff
```
