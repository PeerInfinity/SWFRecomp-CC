# Opcode Implementation Task: CALL_FUNCTION (0x3D)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **CALL_FUNCTION**

## Opcode Specification

**Opcode Name**: CALL_FUNCTION
**Hex Value**: 0x3D
**Category**: Function Operations
**Estimated Complexity**: COMPLEX (6-10 hours)

**Description**: Calls a function with arguments. This is a core opcode for ActionScript function invocation.

**Operation**:
- Pop function name (string) from stack
- Pop argument count (number) from stack
- Pop N arguments from stack (in reverse order)
- Call the function with arguments
- Push return value onto stack

**Expected Behavior** (from SWF spec):
ActionCallFunction calls a function. It pops the function name and number of arguments from the stack, then pops the arguments themselves. The function is called with these arguments, and the return value (or undefined) is pushed onto the stack.

Stack behavior (example for `foo(arg1, arg2)`):
1. Push "foo" (function name)
2. Push 2 (argument count)
3. Push arg1
4. Push arg2
5. Execute CALL_FUNCTION
6. Result: pops function name, count, arg1, arg2; pushes return value

**Important Notes**:
- Arguments are pushed in order but popped in reverse (last arg is on top)
- If function doesn't exist, pushes undefined
- If function has no return statement, pushes undefined
- Built-in functions (trace, etc.) should be callable
- User-defined functions require DEFINE_FUNCTION support

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_CALL_FUNCTION = 0x3D` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that calls functions
6. **Setup Test Directory** - Create `SWFRecomp/tests/call_function_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Call built-in function
```actionscript
// Since trace is built-in, test with a simple math function
var result = parseInt("42");
trace(result);
```
Expected output: `42`

### Test Case 2: Call with multiple arguments
```actionscript
// Test with String.substring or similar
var str = "Hello";
var sub = str.substring(0, 3);
trace(sub);
```
Expected output: `Hel`

### Test Case 3: Call non-existent function
```actionscript
var result = nonExistentFunction(1, 2, 3);
trace(typeof(result));
```
Expected output: `undefined`

## Implementation Hints

**Pattern**: Function call with argument handling and return value.

**Reference Implementation**:
- Control flow from `actionJump`, `actionIf`
- Built-in functions: `actionTrace` (for reference)
- Variable lookup: `actionGetVariable`

**Implementation Outline**:
```c
void actionCallFunction(char* stack, u32* sp, char* str_buffer)
{
    // 1. Pop function name
    const char* func_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 2. Pop argument count
    ActionVar count_var;
    popVar(stack, sp, &count_var);
    convertFloat(stack, sp); // Ensure it's a number
    u32 arg_count = (u32) count_var.value.f32;

    // 3. Pop arguments into array (reverse order)
    ActionVar* args = malloc(sizeof(ActionVar) * arg_count);
    for (int i = arg_count - 1; i >= 0; i--) {
        popVar(stack, sp, &args[i]);
    }

    // 4. Look up and call function
    ActionVar result;
    if (callFunction(func_name, args, arg_count, &result)) {
        // Function executed successfully
        pushVar(stack, sp, &result);
    } else {
        // Function not found or error
        PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
    }

    free(args);
}
```

**Important Considerations**:
- Need a function registry for built-in functions
- User-defined functions need to be stored (from DEFINE_FUNCTION)
- Arguments must be collected in correct order
- Return value must be pushed (undefined if no return)
- Call stack management for nested calls
- This scope handling for methods

**Function Registry Needed**:
```c
// Map of function name -> function pointer
typedef ActionVar (*BuiltinFunc)(ActionVar* args, u32 arg_count);

typedef struct {
    const char* name;
    BuiltinFunc func;
} FunctionEntry;

// Registry of built-in functions
FunctionEntry builtin_functions[] = {
    {"parseInt", builtin_parseInt},
    {"parseFloat", builtin_parseFloat},
    {"isNaN", builtin_isNaN},
    // ... more built-ins
};
```

**Coordination Note**:
- This opcode requires infrastructure that may not exist yet:
  - Function registry for built-ins
  - Function storage for user-defined functions (from DEFINE_FUNCTION)
  - Call stack for nested calls
- Consider implementing basic version first (built-ins only)
- Extend to user-defined functions when DEFINE_FUNCTION is implemented

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Can call built-in functions successfully
- [ ] Arguments passed in correct order
- [ ] Return value pushed correctly
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Non-existent functions return undefined
- [ ] Multiple arguments handled correctly
- [ ] Documentation created in test directory

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/call_function_swf_5/README.md` - Test description and expected output
- Document which built-in functions are implemented
- Note any limitations for user-defined functions
- Explain call stack design if implemented

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

**Note**: This is a foundational opcode. Start with built-in functions (parseInt, parseFloat, etc.) and coordinate with DEFINE_FUNCTION implementer for user-defined function support.
