# WITH Statement Test (Opcode 0x94)

## Test Overview

This test verifies the implementation of the ActionScript 2 WITH statement (opcode 0x94), which temporarily modifies the scope chain for variable lookups.

## Implementation Summary

### Core Components

1. **Opcode Enum** (`SWFRecomp/include/action/action.hpp:75`)
   - Added `SWF_ACTION_WITH = 0x94`

2. **Recompiler Translation** (`SWFRecomp/src/action/action.cpp:580-605`)
   - Parses WITH bytecode format: opcode + UI16 length + UI16 block_size + actions
   - Recursively parses actions within the WITH block
   - Emits `actionWithStart()` before block and `actionWithEnd()` after

3. **Runtime Functions** (`SWFModernRuntime/src/actionmodern/action.c`)
   - **Scope Chain**: Global array `scope_chain[32]` with depth counter
   - **actionWithStart**: Pops object from stack, pushes onto scope chain
   - **actionWithEnd**: Pops object from scope chain

4. **Modified Variable Lookup** (`SWFModernRuntime/src/actionmodern/action.c:1253-1274`)
   - `actionGetVariable`: Checks scope chain (innermost to outermost) before globals
   - `actionSetVariable`: Updates properties in scope objects if found

### Scope Chain Design

- **Max Depth**: 32 levels (supports nested WITH statements)
- **Lookup Order**: Innermost scope → Outermost scope → Global variables
- **Null Handling**: Gracefully handles null/invalid objects with markers

## Test Cases

### Test Case 1: Basic WITH Statement
```actionscript
var obj = {x: 10, y: 20};
with (obj) {
    trace(x); // Should output: 10
    trace(y); // Should output: 20
}
```

**Expected Output:**
```
10
20
```

### Test Case 2: Variable Shadowing
```actionscript
var x = 100;
var obj = {x: 42};
with (obj) {
    trace(x); // obj.x = 42 (shadows global)
}
trace(x); // global x = 100
```

**Expected Output:**
```
42
100
```

### Test Case 3: Nested WITH
```actionscript
var obj1 = {a: 1};
var obj2 = {b: 2};
with (obj1) {
    with (obj2) {
        trace(b); // obj2.b
        trace(a); // obj1.a (outer scope)
    }
}
```

**Expected Output:**
```
2
1
```

## Known Issues

### Object Reference Preservation

**Issue**: Objects are not correctly preserved through the DUPLICATE→SET_VARIABLE→GET_VARIABLE cycle.

**Symptoms**:
- When an object is stored in a variable and retrieved, it returns as type=0 (STRING) instead of type=11 (OBJECT)
- This prevents WITH from receiving the correct object reference

**Root Cause**: The issue appears to be in how `actionDuplicate` or the variable storage system handles object types. This is a broader infrastructure issue affecting multiple opcodes, not specific to WITH.

**Debug Evidence**:
```
[DEBUG SET_VAR] Setting variable, value type=0  // Should be 11 (OBJECT)
[DEBUG] actionWithStart: popped type=0  // Receives STRING instead of OBJECT
```

**Workaround**: Direct object usage (without storing in variables) works correctly:
```c
// This works:
INIT_OBJECT -> WITH -> ...

// This doesn't work yet:
INIT_OBJECT -> DUPLICATE -> SET_VARIABLE -> GET_VARIABLE -> WITH -> ...
```

### Related Opcodes Affected

This issue likely affects:
- `DUPLICATE` (0x3D) - May not preserve object type
- Variable storage infrastructure
- Any opcode that stores/retrieves object references

## Future Work

1. **Fix Object Reference Preservation**
   - Investigate `actionDuplicate` implementation
   - Verify variable storage handles all types correctly
   - Add type preservation tests

2. **Enhanced Test Cases**
   - Test WITH with nested objects
   - Test WITH with array properties
   - Test WITH error cases (null object, invalid types)

3. **Performance Optimization**
   - Consider hash-based property lookup for large objects
   - Profile scope chain lookup performance

4. **Edge Cases**
   - WITH with null/undefined object
   - WITH block size validation
   - Scope chain overflow handling

## Architecture Notes

### Bytecode Format

```
0x94 (WITH opcode)
UI16 length         // Total bytes: 2 + block_size
UI16 block_size     // Size of action block in bytes
ACTIONRECORD[...]   // Actions to execute with modified scope
```

### Memory Management

- Scope chain uses static array (no dynamic allocation)
- Objects remain managed by existing refcount system
- No additional memory overhead per WITH block

### Integration Points

**Modified Functions**:
- `actionGetVariable`: Added scope chain check (SWFModernRuntime/src/actionmodern/action.c:1253)
- `actionSetVariable`: Added scope chain update (SWFModernRuntime/src/actionmodern/action.c:1313)

**New Functions**:
- `actionWithStart`: Scope chain push (SWFModernRuntime/src/actionmodern/action.c:2509)
- `actionWithEnd`: Scope chain pop (SWFModernRuntime/src/actionmodern/action.c:2569)

## Build Instructions

```bash
cd SWFRecomp
./scripts/build_test.sh with_swf_5 native
./tests/with_swf_5/build/native/with_swf_5
```

## References

- **SWF Specification**: Section on ActionWith (0x94)
- **Implementation Guide**: `SWFRecompDocs/parallel-opcode-implementation-guide.md`
- **Opcode Prompt**: `SWFRecompDocs/prompts/opcode-with-0x94.md`
