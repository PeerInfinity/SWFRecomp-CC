# Opcode Implementation Task: DELETE2 (0x5B)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **DELETE2**

## Opcode Specification

**Opcode Name**: DELETE2
**Hex Value**: 0x5B
**Category**: Object Operations
**Estimated Complexity**: COMPLEX (4-6 hours)

**Description**: Modern version of DELETE that takes the object reference directly from the stack instead of looking it up by name. This is the SWF 5+ preferred version.

**Operation**:
- Pop property name (string) from stack
- Pop object reference from stack
- Delete the specified property
- Push success boolean (1.0 if deleted, 0.0 if not)

**Expected Behavior** (from SWF spec):
ActionDelete2 is similar to ActionDelete but uses a direct object reference from the stack rather than looking up an object by name. This is the preferred deletion method for SWF 5+.

Stack behavior:
1. Pop property name (string)
2. Pop object reference
3. Delete the property from the object
4. Push 1.0 if property was deleted, 0.0 otherwise

**Differences from DELETE (0x5A)**:
- Takes object DIRECTLY from stack (not object name)
- Simpler implementation (no variable lookup)
- SWF 5+ preferred version

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_DELETE2 = 0x5B` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that deletes object properties
6. **Setup Test Directory** - Create `SWFRecomp/tests/delete2_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Delete existing property
```actionscript
var obj = {x: 10, y: 20, z: 30};
var result = delete obj.y;
trace(result); // true
trace(obj.y);  // undefined
trace(obj.x);  // 10
```
Expected output:
```
1
undefined
10
```

### Test Case 2: Delete non-existent property
```actionscript
var obj = {a: 1};
var result = delete obj.missing;
trace(result);
```
Expected output: `1` (returns true even for non-existent)

### Test Case 3: Delete from array
```actionscript
var arr = [100, 200, 300];
delete arr[1];
trace(arr.length); // still 3
trace(arr[0]);     // 100
trace(arr[1]);     // undefined
trace(arr[2]);     // 300
```
Expected output:
```
3
100
undefined
300
```

## Implementation Hints

**Pattern**: Similar to DELETE (0x5A) but simpler—no variable lookup needed.

**Reference Implementation**:
- DELETE (0x5A) implementation
- Object model from `SWFModernRuntime/src/actionmodern/object.c`
- Stack operations: `PUSH`, `POP`, `popVar`

**Implementation Outline**:
```c
void actionDelete2(char* stack, u32* sp, char* str_buffer)
{
    // 1. Pop property name
    const char* prop_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 2. Pop object reference
    ActionVar obj_var;
    popVar(stack, sp, &obj_var);

    float result = 1.0; // Default to success

    if (obj_var.type == ACTION_STACK_VALUE_OBJECT) {
        ASObject* obj = (ASObject*) obj_var.value.u64;

        // 3. Delete the property
        bool deleted = deleteProperty(obj, prop_name);
        result = deleted ? 1.0 : 0.0;
    }

    // 4. Push success result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Important Considerations**:
- This opcode takes object DIRECTLY from stack (not name)
- Simpler than DELETE (0x5A) - no variable lookup
- Should return true (1.0) for most cases
- Cannot delete protected/built-in properties (return false in those cases)
- For arrays, set element to undefined but don't change length
- Reference counting: decrement refcount if deleting object reference

**Helper Function** (shared with DELETE):
```c
bool deleteProperty(ASObject* obj, const char* prop_name)
{
    // Find property in object
    // If found:
    //   - Decrement refcount if value is an object
    //   - Remove from property list
    //   - Return true
    // If not found or protected:
    //   - Return true (Flash behavior: delete non-existent returns true)
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
- [ ] Works with direct object references
- [ ] Documentation created in test directory

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/delete2_swf_5/README.md` - Test description and expected output
- Document any differences from DELETE (0x5A)
- Note memory management approach

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
