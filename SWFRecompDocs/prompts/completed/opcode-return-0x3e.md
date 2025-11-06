# Opcode Implementation Task: RETURN

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **RETURN**

## Opcode Specification

**Opcode Name**: RETURN
**Hex Value**: 0x3E
**Category**: Control Flow
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Returns a value from a function.

**Operation**: Pop return value, return from function.

**Expected Behavior** (from SWF Spec 19):
- Pop a value off the stack
- If a return is appropriate (inside a function), the value is returned to the caller
- If a return is not appropriate (not in a function context), the value is discarded
- Execution returns to the instruction after the function call
- The return value is pushed onto the caller's stack

**Stack Operations**:
```
Before: [... return_value]
After:  [... ] (in callee context)
        [... return_value] (in caller context)
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_RETURN = 0x3E` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with functions that return values
6. **Setup Test Directory** - Create `SWFRecomp/tests/return_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Simple return value
```actionscript
function add(a, b) {
    return a + b;
}
trace(add(5, 3));
```
Expected output: `8`

### Test Case 2: Return string
```actionscript
function greet(name) {
    return "Hello, " + name;
}
trace(greet("World"));
```
Expected output: `Hello, World`

### Test Case 3: Early return
```actionscript
function check(x) {
    if (x > 10) {
        return "big";
    }
    return "small";
}
trace(check(15));
trace(check(5));
```
Expected output:
```
big
small
```

### Test Case 4: Return without value
```actionscript
function noReturn() {
    // No explicit return
}
var x = noReturn();
trace(x);
```
Expected output: `undefined`

## Implementation Hints

**Pattern**: This is a control flow operation that transfers execution back to the caller.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_RETURN:
{
    out_script << "\t" << "// Return" << endl
               << "\t" << "actionReturn(stack, sp);" << endl
               << "\t" << "return;" << endl;  // Exit current function
    break;
}
```

**Important**: The RETURN opcode needs to generate both a runtime call AND a C return statement to exit the generated function.

**SWFModernRuntime Implementation** (in action.c):
```c
void actionReturn(char* stack, u32* sp)
{
    // Pop the return value from the stack
    // The value stays on the stack for the caller to access
    // This opcode primarily serves as a marker

    // In a simple implementation, the return value is already
    // on the stack, and the generated C code will handle
    // the actual return via "return;" statement

    // For more complex implementations with a call stack:
    // - Pop return value
    // - Restore caller's stack frame
    // - Push return value onto caller's stack
    // - Restore instruction pointer
}
```

### Simplified Implementation

For the initial implementation, RETURN can be very simple:

```c
void actionReturn(char* stack, u32* sp)
{
    // The return value is already at the top of the stack.
    // The generated C code will include a "return;" statement
    // that exits the function, leaving the value on the stack
    // for the caller.

    // No operation needed here - the translation layer
    // handles the actual return via C return statement.
}
```

### Integration with Function Calls

The RETURN opcode works in conjunction with function call opcodes:

1. **CALL_FUNCTION** (0x3D) - calls a function
2. **CALL_METHOD** (0x52) - calls a method
3. **NEW_OBJECT** (0x40) - calls a constructor
4. **RETURN** (0x3E) - returns from function

**Call sequence**:
```
Caller:
    push arguments
    call function
    [return value is now on stack]

Callee:
    [function body]
    push return_value
    actionReturn()
    return;  // C return
```

### Alternative: Exception-Based Return

Some implementations use a return flag or setjmp/longjmp:

```c
// Global or thread-local return flag
bool g_return_triggered = false;
ActionVar g_return_value;

void actionReturn(char* stack, u32* sp)
{
    // Pop return value
    popVar(stack, sp, &g_return_value);

    // Set return flag
    g_return_triggered = true;

    // The bytecode interpreter checks this flag after each opcode
}
```

### Similar Opcodes

Reference these opcodes:
- `actionCallFunction` (0x3D) - function calling mechanism
- `actionDefineFunction` - function definition (if implemented)
- `actionJump` - control flow reference

### Edge Cases to Handle

- Return outside of function context (top-level script)
- Return without explicit value (undefined)
- Return in nested function calls
- Return with object/array (reference counting)
- Multiple return statements in one function
- Return in try/catch blocks (future)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/return_swf_4/README.md` - Test description and expected output

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Return values are correctly propagated to caller
- [ ] Works with different value types (numbers, strings, objects)
- [ ] Early returns work correctly
- [ ] No memory leaks when returning objects
- [ ] Documentation created

## Important Notes

**Simplified Implementation**: For the initial pass:
- Use the C `return;` statement in generated code
- Assume single-level function calls (no deep recursion)
- Return value is left on stack for caller
- Skip complex call stack management

**Translation Layer Coordination**: The RETURN opcode requires special handling in the SWFRecomp translation layer:
- Must generate both `actionReturn(stack, sp);` call
- Must generate `return;` statement to exit C function
- May need to handle cleanup code before return

**Future Enhancements**:
- Call stack with frame pointers
- Proper stack frame restoration
- Support for nested returns
- Exception handling integration
- Return value type checking

**Function Definition**: This opcode is typically used with:
- `ActionDefineFunction` (0x9B)
- `ActionDefineFunction2` (0x8E)

You may need to implement simplified function support, or test with pre-compiled SWF files that contain function definitions.

**Testing Strategy**: Since RETURN requires functions to test:
- Use ActionScript 2 to compile test functions to SWF
- Or implement a minimal CALL_FUNCTION opcode stub for testing
- Focus on verifying the return value appears on caller's stack

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 2-4 hours
**Priority**: MEDIUM - required for function support
