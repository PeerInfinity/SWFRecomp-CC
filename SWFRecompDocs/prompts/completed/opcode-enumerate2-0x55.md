# Opcode Implementation Task: ENUMERATE2 (0x55)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **ENUMERATE2**

## Opcode Specification

**Opcode Name**: ENUMERATE2
**Hex Value**: 0x55
**Category**: Object Operations
**Estimated Complexity**: COMPLEX (6-8 hours)

**Description**: Similar to ENUMERATE (0x46) but takes the object directly from the stack instead of a variable name. This is the SWF 6+ version used in modern ActionScript.

**Operation**:
- Pop object reference from stack
- Enumerate all property names
- Push null (terminator)
- Push each property name (in reverse order)

**Expected Behavior** (from SWF spec):
ActionEnumerate2 is similar to ActionEnumerate, but uses a stack argument of object type rather than using a variable name. This is the preferred enumeration method for SWF 6+.

Stack behavior:
1. Pop the object reference from stack
2. Push null as a terminator
3. Push each property name onto the stack (in reverse order of enumeration)

The null value signals the end of the enumeration. The property names are pushed in reverse so they can be popped in the correct order.

**Differences from ENUMERATE (0x46)**:
- Takes object directly from stack (not variable name)
- Simpler implementation (no variable lookup)
- SWF 6+ preferred version

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_ENUMERATE2 = 0x55` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test with for..in loop over object
6. **Setup Test Directory** - Create `SWFRecomp/tests/enumerate2_swf_6/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic enumeration
```actionscript
var obj = {a: 1, b: 2, c: 3};
var props = [];
for (var key in obj) {
    props.push(key);
}
trace(props.join(", "));
```
Expected output: `a, b, c` (or any consistent ordering)

### Test Case 2: Empty object
```actionscript
var empty = {};
var count = 0;
for (var key in empty) {
    count++;
}
trace(count);
```
Expected output: `0`

### Test Case 3: Array enumeration
```actionscript
var arr = [10, 20, 30];
var indices = [];
for (var i in arr) {
    indices.push(i);
}
trace(indices.join(", "));
```
Expected output: `0, 1, 2`

## Implementation Hints

**Pattern**: Similar to ENUMERATE (0x46) but simpler—no variable lookup needed.

**Reference Implementation**:
- ENUMERATE (0x46) implementation
- Object model from `SWFModernRuntime/src/actionmodern/object.c`
- Stack operations: `PUSH`, `POP`, `PUSH_STR`

**Implementation Outline**:
```c
void actionEnumerate2(char* stack, u32* sp, char* str_buffer)
{
    // 1. Pop object reference from stack
    ActionVar obj_var;
    popVar(stack, sp, &obj_var);

    if (obj_var.type != ACTION_STACK_VALUE_OBJECT) {
        // Push null terminator for non-objects
        PUSH(ACTION_STACK_VALUE_NULL, 0);
        return;
    }

    ASObject* obj = (ASObject*) obj_var.value.u64;

    // 2. Push null as terminator
    PUSH(ACTION_STACK_VALUE_NULL, 0);

    // 3. Enumerate and push property names (reverse order)
    for (int i = obj->num_properties - 1; i >= 0; i--) {
        const char* prop_name = obj->properties[i].name;
        PUSH_STR(prop_name, strlen(prop_name));
    }
}
```

**Important Considerations**:
- This opcode takes the object DIRECTLY from stack (not variable name)
- Simpler than ENUMERATE (0x46) - no variable lookup
- Should work with both objects and arrays
- For arrays, enumerate indices as strings ("0", "1", "2", etc.)
- Properties should be enumerable properties only
- Order doesn't matter but should be deterministic

**Data Structures Needed**:
- Object property enumeration (from object.c)
- Array handling (indices as properties)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct enumeration of properties
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Empty object case handled (pushes only null)
- [ ] Array enumeration works (indices as strings)
- [ ] Null terminator is pushed before property names
- [ ] Documentation created in test directory

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/enumerate2_swf_6/README.md` - Test description and expected output
- Document any design decisions about enumeration order
- Note any differences in behavior between objects and arrays

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
