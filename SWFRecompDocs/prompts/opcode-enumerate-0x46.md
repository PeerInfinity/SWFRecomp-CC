# Opcode Implementation Task: ENUMERATE (0x46)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **ENUMERATE**

## Opcode Specification

**Opcode Name**: ENUMERATE
**Hex Value**: 0x46
**Category**: Object Operations
**Estimated Complexity**: COMPLEX (6-8 hours)

**Description**: Enumerates all enumerable property names of an object and pushes them onto the stack for use in for..in loops.

**Operation**:
- Pop variable name (string) from stack
- Resolve variable to object
- Enumerate all property names
- Push null (terminator)
- Push each property name (in reverse order)

**Expected Behavior** (from SWF spec):
ActionEnumerate obtains the names of all "slots" in use in an ActionScript object—that is, for an object obj, all names X that could be retrieved with the syntax obj.X. ActionEnumerate is used to implement the for..in statement.

Stack behavior:
1. Pop the name of the variable (string)
2. Get the object from the variable
3. Push null as a terminator
4. Push each property name onto the stack (in reverse order of enumeration)

The null value signals the end of the enumeration. The property names are pushed in reverse so they can be popped in the correct order.

**Important Notes**:
- This opcode uses the **variable name**, not the object directly
- Must push null as terminator FIRST, then property names
- Property names should be enumerable properties only (not built-in methods)
- Order of enumeration is implementation-defined but should be consistent

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_ENUMERATE = 0x46` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test with for..in loop or manual enumeration
6. **Setup Test Directory** - Create `SWFRecomp/tests/enumerate_swf_4/`
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

### Test Case 3: Nested properties
```actionscript
var obj = {x: 10, y: 20};
obj.z = 30;
var names = [];
for (var prop in obj) {
    names.push(prop);
}
trace(names.length);
```
Expected output: `3`

## Implementation Hints

**Pattern**: This is a complex object operation requiring iteration over object properties.

**Reference Implementation**:
- Object model from `SWFModernRuntime/src/actionmodern/object.c` (Experiment #4)
- Variable lookup: `actionGetVariable`, `actionSetVariable`
- Stack operations: `PUSH`, `POP`, `PUSH_STR`

**Implementation Outline**:
```c
void actionEnumerate(char* stack, u32* sp, char* str_buffer)
{
    // 1. Pop variable name from stack
    const char* var_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 2. Look up the variable to get the object
    ASObject* obj = getVariable(var_name);

    if (obj == NULL || obj->type != ACTION_STACK_VALUE_OBJECT) {
        // Push null terminator for non-objects
        PUSH(ACTION_STACK_VALUE_NULL, 0);
        return;
    }

    // 3. Push null as terminator
    PUSH(ACTION_STACK_VALUE_NULL, 0);

    // 4. Enumerate and push property names (reverse order)
    for (int i = obj->num_properties - 1; i >= 0; i--) {
        const char* prop_name = obj->properties[i].name;
        PUSH_STR(prop_name, strlen(prop_name));
    }
}
```

**Important Considerations**:
- This opcode takes variable NAME, not the object itself
- You'll need to integrate with the variable storage system (from GET_VARIABLE/SET_VARIABLE)
- The object model should already be implemented (Batch 3)
- Properties should be enumerable properties only
- Order doesn't matter but should be deterministic

**Data Structures Needed**:
- Object property enumeration (likely already in object.c from Batch 3)
- Variable lookup function (from variables.c)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct enumeration of properties
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Empty object case handled (pushes only null)
- [ ] Null terminator is pushed before property names
- [ ] Documentation created in test directory

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/enumerate_swf_4/README.md` - Test description and expected output
- Document any design decisions about enumeration order
- Note any integration points with object model

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
