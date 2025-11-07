# ActionTry (0x8F) Test - try_swf_7

## Test Description

This test validates the implementation of the ActionTry (0x8F) and ActionThrow (0x2A) opcodes for exception handling in ActionScript 2.

## Opcodes Tested

- **ActionTry (0x8F)** - Try-catch-finally exception handling
- **ActionThrow (0x2A)** - Throw exceptions

## Test Case

```actionscript
try {
    trace("In try");
    throw "Error!";
    trace("This won't print");
} catch (e) {
    trace("Caught: " + e);
}
trace("After try-catch");
```

## Expected Output

```
In try
Caught: Error!
After try-catch
```

## Implementation Status

### ✅ Completed
- Opcode parsing and bytecode translation
- Exception state management infrastructure
- Try-catch-finally block structure
- ActionThrow implementation
- Catch variable binding

### ⚠️ Known Limitations

**Control Flow Issue**: The current implementation does NOT properly halt execution when an exception is thrown within the try block. This is because:

1. C does not have built-in exception handling
2. The generated C code uses if-else statements, which don't provide the necessary control flow
3. Proper implementation requires either:
   - `setjmp`/`longjmp` for non-local jumps
   - Checking exception flags after every statement (performance overhead)
   - A more sophisticated code generation strategy

### Current Behavior

The test currently produces:
```
In try
This won't print      <-- Should NOT appear (execution should stop at throw)
After try-catch
```

Missing:
```
Caught: Error!        <-- Should appear (catch block should execute)
```

### Required for Full Implementation

To make exception handling work correctly, we need to:

1. **Use setjmp/longjmp**: Implement proper non-local jumps in C
   - Add `jmp_buf` to exception state
   - Call `setjmp` at try block start
   - Call `longjmp` in `actionThrow`

2. **Thread Safety**: Make exception state thread-local

3. **Stack Unwinding**: Properly clean up the stack when exceptions propagate

4. **Nested Handlers**: Support multiple levels of try-catch nesting

## Code Locations

- **Enum**: `SWFRecomp/include/action/action.hpp:82` (SWF_ACTION_TRY)
- **Translation**: `SWFRecomp/src/action/action.cpp:726-837`
- **API Declarations**: `SWFModernRuntime/include/actionmodern/action.h:152-158`
- **Runtime Implementation**: `SWFModernRuntime/src/actionmodern/action.c:2626-2702`

## Next Steps

To complete this implementation:

1. Implement `setjmp`/`longjmp` based exception handling
2. Modify `actionThrow` to call `longjmp` when an exception handler is active
3. Modify the code generator to wrap try blocks with `setjmp`
4. Add proper stack unwinding
5. Test with all test cases from the specification

## Test Cases from Specification

The prompt includes 5 test cases:
1. ✅ Basic try-catch (current test)
2. Try-finally (no exception)
3. Try-catch-finally
4. No exception thrown
5. Exception propagation through functions

Currently only test case 1 is implemented, and it requires the setjmp/longjmp work to pass correctly.
