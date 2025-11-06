# Opcode Implementation Task: DELETE (0x5A)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **DELETE**

## Opcode Specification

**Opcode Name**: DELETE
**Hex Value**: 0x5A
**Category**: Object Operations
**Estimated Complexity**: COMPLEX (4-6 hours)

**Description**: Deletes a property from an object. Takes property name and object name from the stack.

**Operation**:
- Pop property name (string) from stack
- Pop object name (string) from stack
- Look up object by name
- Delete the specified property
- Push success boolean (1.0 if deleted, 0.0 if not)

**Expected Behavior** (from SWF spec):
ActionDelete deletes a property from an object. It pops the property name and object name from the stack, looks up the object, deletes the property, and pushes a boolean indicating success.

Stack behavior:
1. Pop property name (string)
2. Pop object name (string or object path)
3. Resolve object from name
4. Delete the property from the object
5. Push 1.0 if property was deleted, 0.0 otherwise

**Important Notes**:
- Returns true (1.0) even if property didn't exist
- Cannot delete built-in properties or protected properties
- For arrays, deleting an element leaves undefined (doesn't shift indices)
- This is the old version; DELETE2 (0x5B) is the modern variant

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_DELETE = 0x5A` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that deletes object properties
6. **Setup Test Directory** - Create `SWFRecomp/tests/delete_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Delete existing property
```actionscript
var obj = {a: 1, b: 2, c: 3};
var result = delete obj.b;
trace(result); // true
trace(obj.b);  // undefined
```
Expected output:
```
1
undefined
```

### Test Case 2: Delete non-existent property
```actionscript
var obj = {a: 1};
var result = delete obj.xyz;
trace(result);
```
Expected output: `1` (returns true even for non-existent)

### Test Case 3: Delete from array
```actionscript
var arr = [10, 20, 30];
delete arr[1];
trace(arr.length); // still 3
trace(arr[1]);     // undefined
```
Expected output:
```
3
undefined
```

## Implementation Hints

**Pattern**: Object property deletion with variable lookup.

**Reference Implementation**:
- Object model from `SWFModernRuntime/src/actionmodern/object.c`
- Variable lookup: `actionGetVariable`
- Property access: `actionGetMember`, `actionSetMember`

**Implementation Outline**:
```c
void actionDelete(char* stack, u32* sp, char* str_buffer)
{
    // 1. Pop property name
    const char* prop_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 2. Pop object name
    const char* obj_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 3. Look up the object
    ASObject* obj = getVariable(obj_name);

    float result = 1.0; // Default to success

    if (obj != NULL && obj->type == ACTION_STACK_VALUE_OBJECT) {
        // 4. Delete the property
        bool deleted = deleteProperty(obj, prop_name);
        result = deleted ? 1.0 : 0.0;
    }

    // 5. Push success result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Important Considerations**:
- This opcode uses NAMES (strings) for both object and property
- Must integrate with variable storage system
- Should return true (1.0) for most cases
- Cannot delete protected/built-in properties (return false in those cases)
- For arrays, set element to undefined but don't change length
- Reference counting: decrement refcount if deleting object reference

**Helper Function Needed**:
```c
bool deleteProperty(ASObject* obj, const char* prop_name)
{
    // Find property in object
    // Remove from property list
    // Decrement refcount if property value is an object
    // Return true if deleted, false if protected/not found
}
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test successfully deletes properties
- [ ] Returns correct boolean result
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Non-existent properties return true
- [ ] Array deletion works correctly (leaves undefined)
- [ ] Memory properly managed (refcounts decremented)
- [ ] Documentation created in test directory

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/delete_swf_5/README.md` - Test description and expected output
- Document any edge cases for protected properties
- Note memory management approach

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
