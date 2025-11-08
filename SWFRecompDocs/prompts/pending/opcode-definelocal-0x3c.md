# AS2 Opcode Implementation Task: DEFINE_LOCAL

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **DEFINE_LOCAL**

## Opcode Specification

**Opcode Name**: DEFINE_LOCAL
**Hex Value**: 0x3C
**Category**: Variables / Scope Management
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Defines a local variable in the current function scope and sets its value.

**Operation**: Pop value, pop name, create/update local variable.

**Expected Behavior**:
- Pop a value off the stack (the value to assign)
- Pop a name off the stack (the variable name as a string)
- Create a local variable with that name in the current function scope
- Set the variable's value to the popped value
- If the variable already exists in the local scope, update its value
- Local variables shadow global variables of the same name

## Your Task

Implement this opcode following the 8-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/definelocal_swf_5/` with validation files
7. **Build and Verify** - Compile and verify output matches expected
8. **Run Test Suite** - Verify with `./all_tests.sh`

## Test Cases

### Test Case 1: Basic local variable definition
```actionscript
function test() {
    var x = 42;
    trace(x);
}
test();
```
Expected output: `42`

### Test Case 2: Local shadowing global
```actionscript
var x = 10;
function test() {
    var x = 20;
    trace(x);
}
test();
trace(x);
```
Expected output:
```
20
10
```

### Test Case 3: Multiple local variables
```actionscript
function test() {
    var a = 1;
    var b = 2;
    var c = 3;
    trace(a);
    trace(b);
    trace(c);
}
test();
```
Expected output:
```
1
2
3
```

### Test Case 4: Reassigning local variable
```actionscript
function test() {
    var x = 5;
    trace(x);
    x = 10;
    trace(x);
}
test();
```
Expected output:
```
5
10
```

### Test Case 5: String local variables
```actionscript
function test() {
    var name = "Alice";
    trace(name);
}
test();
```
Expected output: `Alice`

## Implementation Hints

**Pattern**: This is a variable definition operation with scope management.

**Reference these similar opcodes**:
- `actionSetVariable` in `SWFModernRuntime/src/actionmodern/action.c` - Similar variable storage
- `actionGetVariable` in `SWFModernRuntime/src/actionmodern/action.c` - Variable lookup

**Implementation outline**:
```c
void actionDefineLocal(char* stack, u32* sp, hashmap* local_variables)
{
    // Pop the value to assign
    ActionVar value;
    popVar(stack, sp, &value);

    // Pop the variable name
    const char* name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // Store in local variable scope
    // Note: This requires a local variable storage mechanism
    // The local_variables parameter should be the current function's local scope

    // For now, a simplified implementation might use a local hashmap
    // In a full implementation, this would interact with the call stack

    // Example (simplified):
    // hashmap_put(local_variables, name, strlen(name), &value, sizeof(ActionVar));
}
```

**Important Considerations**:
- **Scope Management**: Local variables must be stored separately from global variables
- **Function Context**: This requires a call stack or function context to maintain local scopes
- **Variable Shadowing**: Local variables with the same name as globals must shadow the global
- **Lifetime**: Local variables should be cleaned up when the function returns

**Infrastructure Requirements**:

This opcode requires local variable scope infrastructure:

1. **Function Call Stack**: A stack of function contexts
2. **Local Variable Storage**: Each function context needs its own variable hashmap
3. **Scope Chain**: Variable lookup must check local scope first, then global scope
4. **Cleanup**: Local variables must be freed when function exits

**Simplified Implementation Strategy**:

For initial implementation without full function infrastructure, you could:

1. Use a separate `local_variables` hashmap that shadows the global one
2. Modify `actionGetVariable` to check local scope first
3. Modify `actionSetVariable` to update local scope if variable exists there
4. Add cleanup at end of script execution

**Full Implementation Strategy**:

For complete implementation with function support:

1. Maintain a call stack with function contexts
2. Each context has its own local variable hashmap
3. Variable lookup walks the scope chain (local → parent → ... → global)
4. Function return pops context and frees local variables

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/definelocal_swf_5/test_info.json` - Test metadata
- `SWFRecomp/tests/definelocal_swf_5/validate.py` - Validation script
- `SWFRecomp/tests/definelocal_swf_5/README.md` - Test description and expected output
- Document scope management approach

## Success Criteria

Your implementation is complete when:
- [ ] All 8 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && ./all_tests.sh`
- [ ] Local variables shadow globals correctly
- [ ] Multiple local variables in same scope work
- [ ] Variable reassignment works
- [ ] test_info.json created with correct metadata
- [ ] validate.py passes all test cases
- [ ] Documentation created

## Additional Notes

**ActionScript Context**: In AS2, the `var` keyword inside a function creates a local variable using the DEFINE_LOCAL opcode.

**Flash Version**: Available in SWF 5+

**Related Opcodes**:
- **ActionDefineLocal2** (0x41) - Defines a local variable without setting its value (initializes to `undefined`)
- **ActionSetVariable** (0x1D) - Sets a variable (checks local scope first if it exists)
- **ActionGetVariable** (0x1C) - Gets a variable value (checks local scope first)

**Scope Rules**:
1. Local variables are only accessible within the function they're defined in
2. Local variables shadow global variables with the same name
3. Local variables are destroyed when the function returns
4. Nested functions have access to parent function's local variables (closure)

**Implementation Priority**: This opcode is essential for function support. Consider implementing alongside:
- DEFINE_FUNCTION (0x9B) or DEFINE_FUNCTION2 (0x8E)
- RETURN (0x3E)
- CALL_FUNCTION (0x9E)

**Testing Notes**:

Since full function support may not be available yet, you can test with a simplified approach:
- Create a global "local scope" hashmap that lives for the duration of the script
- Test basic variable definition and retrieval
- Verify shadowing behavior if possible
- Document limitations for future enhancement

Example simplified test (without actual functions):
```python
# create_test_swf.py
# This creates a SWF that tests local variable definition
# without requiring full function infrastructure
# (Uses DefineLocal but in global context for testing)
```

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

**Note**: If full local scope infrastructure doesn't exist yet, coordinate with the team or implement a simplified version that can be enhanced when function support is added.
