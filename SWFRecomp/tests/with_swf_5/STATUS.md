# WITH Opcode (0x94) - Implementation Status

## Current Status: PARTIAL - Implementation Complete, Test Failing

### What's Implemented

✅ **Recompiler Translation** (`SWFRecomp/src/action/action.cpp:1212-1237`)
- WITH opcode recognized and translated
- Generates `actionWithStart()` and `actionWithEnd()` calls
- Correctly handles block size and nested parsing

✅ **Runtime Implementation** (`SWFModernRuntime/src/actionmodern/action.c:3456-3520`)
- Scope chain infrastructure (`scope_chain[]`, `scope_depth`)
- `actionWithStart()` - pops object and adds to scope chain
- `actionWithEnd()` - pops object from scope chain
- NULL marker support for invalid objects

✅ **Variable Lookup Integration** (`action.c:1469-1483`)
- `actionGetVariable()` checks scope chain before global variables
- Searches innermost to outermost
- Property lookup via `getProperty()`

✅ **Test Infrastructure**
- Test directory created (`tests/with_swf_5/`)
- Test SWF generator (`create_test_swf.py`)
- Validation files (`test_info.json`, `validate.py`)
- Expected output: `10` and `20` (properties x and y)

### Known Issues

❌ **Test Execution Fails**
- Test builds successfully but segfaults at runtime
- Likely issue in object/property interaction
- Needs GDB debugging to locate exact failure point

### Bugs Fixed During Implementation

1. **`actionDuplicate` not declared** - Added declaration to `action.h:143`
2. **Wrong opcode in test scripts**:
   - DUPLICATE was `0x3D` (CALL_FUNCTION) - corrected to `0x4C`
   - TYPEOF was `0x3C` (DEFINE_LOCAL) - corrected to `0x44`
3. **Fixed `init_object_swf_4` test** - Now passes with correct opcodes

### Next Steps

1. **Debug segfault** using GDB or additional logging
2. **Simplify test** - Try minimal WITH test without complex object operations
3. **Verify object system** - Ensure `getProperty()` handles all edge cases
4. **Test nested WITH** - Once basic test works, test nested scopes

### Files Modified

**SWFRecomp:**
- ✅ `include/action/action.hpp:108` - Enum already defined
- ✅ `src/action/action.cpp:1212-1237` - Translation already implemented

**SWFModernRuntime:**
- ✅ `include/actionmodern/action.h:143` - Added `actionDuplicate` declaration
- ✅ `include/actionmodern/action.h:173-174` - WITH functions already declared
- ✅ `src/actionmodern/action.c:18-20` - Scope chain globals already defined
- ✅ `src/actionmodern/action.c:1469-1483` - Variable lookup already integrated
- ✅ `src/actionmodern/action.c:3456-3520` - WITH implementation already complete

**Tests:**
- ✅ `tests/with_swf_5/create_test_swf.py` - Fixed DUPLICATE opcode (0x3D → 0x4C)
- ✅ `tests/with_swf_5/test_info.json` - Created with metadata
- ✅ `tests/with_swf_5/validate.py` - Created with validation logic
- ✅ `tests/init_object_swf_4/create_test_swf.py` - Fixed DUPLICATE and TYPEOF opcodes

### Test Case

```actionscript
var obj = {x: 10, y: 20};
with (obj) {
    trace(x); // Expected: 10
    trace(y); // Expected: 20
}
```

### References

- SWF Spec: ActionWith (0x94) modifies scope chain for property lookups
- Implementation guide: `SWFRecompDocs/parallel-opcode-implementation-guide.md`
- Task description: `SWFRecompDocs/prompts/completed/opcode-with-0x94.md`
