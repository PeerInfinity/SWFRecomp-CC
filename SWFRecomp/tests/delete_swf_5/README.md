# DELETE Opcode (0x5A) Test

This test validates the DELETE opcode implementation for ActionScript 2.

## Opcode Details

- **Opcode**: 0x5A (DELETE)
- **Category**: Object Operations
- **SWF Version**: 5+

## Operation

The DELETE opcode removes a property from an object:

1. Pop property name (string) from stack
2. Pop object name (string) from stack
3. Look up object by variable name
4. Delete the specified property
5. Push success boolean (1.0 if deleted, 0.0 if not)

## Test Cases

### Test Case 1: Delete Existing Property

```actionscript
var obj = {a: 1, b: 2, c: 3};
var result = delete obj.b;
trace(result); // Expected: 1
```

Creates an object with three properties and deletes the middle one.

### Test Case 2: Delete Non-Existent Property

```actionscript
var obj2 = {a: 1};
var result2 = delete obj2.xyz;
trace(result2); // Expected: 1
```

Per AS2 specification, DELETE returns true (1.0) even if the property doesn't exist.

### Test Case 3: Delete from Non-Existent Object

```actionscript
var result3 = delete noobj.prop;
trace(result3); // Expected: 1
```

Per AS2 specification, DELETE returns true (1.0) even if the object doesn't exist.

## Expected Output

```
1
1
1
DELETE tests complete
```

## Implementation Notes

### Key Features

- Works with object variable names (not direct object references)
- Uses `getVariable`/`getVariableById` for variable lookup
- Calls `deleteProperty` from object.c to perform deletion
- Handles reference counting properly for deleted object properties
- Returns true for most cases (AS2 spec behavior)

### Memory Management

The `deleteProperty` function:
- Frees the property name string
- Releases object references (decrements refcount)
- Frees owned string memory
- Shifts remaining properties to fill the gap
- Updates the object's `num_used` count

### Stack Behavior

DELETE expects this stack layout:
- Top: property name (string)
- Second: object name (string)

After execution:
- Pops both strings
- Pushes result (1.0 or 0.0 as float)

## Files Modified

1. `SWFRecomp/include/action/action.hpp` - Added SWF_ACTION_DELETE enum
2. `SWFRecomp/src/action/action.cpp` - Added translation case
3. `SWFModernRuntime/include/actionmodern/action.h` - Added actionDelete declaration
4. `SWFModernRuntime/include/actionmodern/object.h` - Added deleteProperty declaration
5. `SWFModernRuntime/src/actionmodern/action.c` - Implemented actionDelete
6. `SWFModernRuntime/src/actionmodern/object.c` - Implemented deleteProperty

## Build and Run

```bash
cd SWFRecomp
./scripts/build_test.sh delete_swf_5 native
./tests/delete_swf_5/build/native/delete_swf_5
```

## Comparison with Related Opcodes

- **DELETE (0x5A)**: Deletes property by name, uses variable lookup
- **DELETE2 (0x5B)**: Modern variant, pops object reference directly
- **SET_MEMBER (0x4F)**: Sets property, pops object reference
- **GET_MEMBER (0x4E)**: Gets property, pops object reference

DELETE is unique in that it works with string names for both object and property, requiring variable system integration.
