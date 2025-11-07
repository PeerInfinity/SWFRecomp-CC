# AS2 Opcode Implementation: THROW

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **THROW**

## Opcode Specification

**Opcode Name**: THROW
**Hex Value**: 0x2A
**Category**: Exception Handling
**Estimated Complexity**: COMPLEX

**Description**: Throws an exception with the value from the stack.

**Operation**: Pop value from stack and throw as exception.

**Expected Behavior**:
- Pops value from stack (the exception object/value)
- Unwinds stack to nearest catch block
- If no catch block, terminates script execution
- Works with ActionTry (0x8F) for try-catch-finally

**SWF Spec Reference**: ActionThrow (0x2A)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that demonstrates exception throwing
6. **Setup Test Directory** - Create `SWFRecomp/tests/throw_swf_7/` (SWF 7+ for exceptions)
7. **Build and Verify** - Compile and verify behavior

## Test Cases

**Note**: Full exception handling requires ActionTry (0x8F). Basic implementation can handle uncaught exceptions.

Test Case 1: Simple throw (uncaught)
```actionscript
trace("Before throw");
throw "Error message";
trace("After throw");  // Should not execute
```
Expected output:
```
Before throw
[Uncaught exception: Error message]
```

Test Case 2: Throw with try-catch (requires ActionTry)
```actionscript
try {
    trace("In try block");
    throw "Something went wrong";
    trace("After throw");  // Should not execute
} catch (e) {
    trace("Caught: " + e);
}
trace("After catch");
```
Expected output:
```
In try block
Caught: Something went wrong
After catch
```

Test Case 3: Throw number
```actionscript
trace("Throwing number");
throw 404;
```
Expected output:
```
Throwing number
[Uncaught exception: 404]
```

## Implementation Hints

**Pattern**: This is an exception control flow operation.

**Implementation approach**:
```c
void actionThrow(char* stack, u32* sp, SWFAppContext* ctx)
{
    // Pop exception value from stack
    ActionVar exception;
    popVar(stack, sp, &exception);

    // Store exception in context
    ctx->exception_thrown = 1;
    ctx->exception_value = exception;

    // Find nearest catch block
    // For now, just terminate with error message
    #ifdef NO_GRAPHICS
    printf("[Uncaught exception: ");
    if (exception.type == ACTION_STACK_VALUE_STRING) {
        printf("%s", (char*)exception.value.u64);
    } else if (exception.type == ACTION_STACK_VALUE_F32) {
        printf("%g", exception.value.f32);
    } else {
        printf("(unknown type)");
    }
    printf("]\n");
    #endif

    // Signal script should stop
    ctx->should_stop = 1;
}
```

**Advanced Implementation** (with ActionTry support):
```c
void actionThrow(char* stack, u32* sp, SWFAppContext* ctx)
{
    // Pop exception value
    ActionVar exception;
    popVar(stack, sp, &exception);

    // Store in context
    ctx->exception_thrown = 1;
    ctx->exception_value = exception;

    // Unwind to nearest catch block
    TryBlock* try_block = findNearestTryBlock(ctx);
    if (try_block && try_block->has_catch) {
        // Jump to catch block
        ctx->instruction_pointer = try_block->catch_offset;
        // Push exception onto stack for catch variable
        pushVar(stack, sp, &exception);
    } else {
        // No catch block, terminate
        reportUncaughtException(ctx, &exception);
        ctx->should_stop = 1;
    }

    // Execute finally blocks during unwind
    executeFinallyBlocks(ctx, try_block);
}
```

**Important Considerations**:
- Requires exception context in SWFAppContext
- Stack unwinding to catch block
- Finally blocks must execute during unwind
- Works with ActionTry (0x8F) - coordinate implementation
- Can throw any value (string, number, object)

Reference similar operations:
- ActionReturn (control flow that exits function)
- ActionTry (0x8F) - defines catch/finally blocks

## Infrastructure Requirements

**SWFAppContext additions**:
```c
typedef struct TryBlock {
    u32 try_offset;
    u32 catch_offset;
    u32 finally_offset;
    int has_catch;
    int has_finally;
    struct TryBlock* parent;  // For nested try blocks
} TryBlock;

// Add to SWFAppContext:
int exception_thrown;
ActionVar exception_value;
TryBlock* current_try_block;
int should_stop;
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for uncaught exceptions
- [ ] Exception value is properly extracted from stack
- [ ] No build errors or warnings
- [ ] Documentation created
- [ ] Full test suite still passes
- [ ] Coordinate with ActionTry implementation for catch/finally

## Notes

- This is a complex control flow opcode
- Basic implementation: handle uncaught exceptions
- Advanced implementation: integrate with ActionTry for try-catch-finally
- May want to implement ActionTry (0x8F) first or in parallel
- Exception handling requires careful stack management

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
