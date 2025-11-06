# NEW_OBJECT Opcode Test (0x40)

This test validates the implementation of the NEW_OBJECT opcode (0x40) for ActionScript 2.

## Opcode Details

**Opcode**: NEW_OBJECT (0x40)
**Category**: Object Operations
**Complexity**: COMPLEX

## Description

The NEW_OBJECT opcode creates an object by invoking a constructor function. It pops the constructor name, number of arguments, and arguments from the stack, then creates a new object and pushes it back onto the stack.

## Stack Operations

```
Before: [... argN, argN-1, ..., arg1, numArgs, constructor_name]
After:  [... new_object]
```

## Test Cases

This test exercises three different scenarios:

### Test 1: Array with Length
```actionscript
new Array(3)
```
Creates an array with length 3 (empty slots).

### Test 2: Empty Object
```actionscript
new Object()
```
Creates an empty object with no properties.

### Test 3: Array with Elements
```actionscript
new Array(1, 2, 3)
```
Creates an array with elements [1, 2, 3].

## Expected Output

```
NEW_OBJECT tests completed
```

## Implementation Details

### Files Modified

1. **SWFRecomp/include/action/action.hpp**
   - Added `SWF_ACTION_NEW_OBJECT = 0x40` enum

2. **SWFRecomp/src/action/action.cpp**
   - Added translation case for NEW_OBJECT

3. **SWFModernRuntime/include/actionmodern/action.h**
   - Added `actionNewObject()` function declaration

4. **SWFModernRuntime/include/actionmodern/stackvalue.h**
   - Added `ACTION_STACK_VALUE_ARRAY = 12` type

5. **SWFModernRuntime/include/actionmodern/object.h**
   - Added `ASArray` structure
   - Added array lifecycle functions (allocArray, retainArray, releaseArray)

6. **SWFModernRuntime/src/actionmodern/object.c**
   - Implemented array allocation and management functions
   - Added array element access functions

7. **SWFModernRuntime/src/actionmodern/action.c**
   - Implemented `actionNewObject()` function
   - Support for Array, Object, and Date constructors

8. **SWFRecomp/scripts/build_test.sh**
   - Added object.c to the list of copied source files

## Constructor Support

### Implemented:
- **Array()** - Empty array
- **Array(length)** - Array with specified length
- **Array(elem1, elem2, ...)** - Array with elements
- **Object()** - Empty object
- **Date()** - Date object (simplified, creates empty object)

### Future Enhancements:
- User-defined constructors
- Prototype chain initialization
- Additional built-in constructors (String, Number, Boolean, etc.)
- Full Date implementation with argument parsing

## Memory Management

This implementation uses reference counting for memory management:
- New objects start with refcount = 1
- Objects/arrays stored in properties/elements are retained
- Objects are freed when refcount reaches 0
- Recursive release of nested objects/arrays

## Building and Running

```bash
# Build the test
cd SWFRecomp
./scripts/build_test.sh new_object_swf_4 native

# Run the test
./tests/new_object_swf_4/build/native/new_object_swf_4
```

## Verification

The test passes if it outputs:
```
NEW_OBJECT tests completed
```

The test creates three different objects/arrays and pops them off the stack. If any constructor fails or causes a crash, the trace message will not appear.

## Notes

- This test only verifies that objects can be created without crashing
- Full property access requires GET_MEMBER/SET_MEMBER opcodes
- Array element access requires GET_MEMBER or array indexing opcodes
- The test uses POP to discard created objects since we can't yet access their properties

## Related Opcodes

- **INIT_ARRAY (0x42)** - Literal array syntax `[]`
- **INIT_OBJECT (0x43)** - Literal object syntax `{}`
- **CALL_FUNCTION (0x3D)** - Calls constructor function
- **GET_MEMBER/SET_MEMBER** - Access object properties (future implementation)
