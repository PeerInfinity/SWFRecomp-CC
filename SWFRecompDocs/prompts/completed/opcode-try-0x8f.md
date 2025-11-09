# AS2 Opcode Implementation Task: ActionTry

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionTry**

## Opcode Specification

**Opcode Name**: ActionTry
**Hex Value**: 0x8F
**Category**: Control Flow / Exception Handling
**Estimated Complexity**: COMPLEX (6-12 hours)

**Description**: Defines handlers for exceptional conditions, implementing ActionScript try, catch, and finally keywords.

**Operation**: Set up exception handling with try, catch, and finally blocks.

**Expected Behavior** (from SWF Spec 19):
- Implements try, catch, and finally exception handling
- If code within try block throws an object, control passes to catch block (if exists), then finally block (if exists)
- Finally block always executes, regardless of whether an error was thrown
- If exception occurs in function without catch handler, function exits and exception propagates up call stack
- Any ActionScript data type can be thrown (typically objects)
- Exception can be caught in named variable or in register

**Action Record Format**:
```
Field                   Type            Comment
ActionCode              UI8             0x8F
Length                  UI16            Variable
Reserved                UB[5]           Always 0
CatchInRegisterFlag     UB[1]           0=named variable, 1=register
FinallyBlockFlag        UB[1]           0=no finally, 1=has finally
CatchBlockFlag          UB[1]           0=no catch, 1=has catch
TrySize                 UI16            Length of try block
CatchSize               UI16            Length of catch block
FinallySize             UI16            Length of finally block
CatchName               STRING          Name of catch variable (if CatchInRegisterFlag=0)
CatchRegister           UI8             Register number (if CatchInRegisterFlag=1)
TryBody                 UI8[TrySize]    Body of try block
CatchBody               UI8[CatchSize]  Body of catch block (if any)
FinallyBody             UI8[FinallySize] Body of finally block (if any)
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_TRY = 0x8F` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (parse all try/catch/finally blocks)
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with exception handling
6. **Setup Test Directory** - Create `SWFRecomp/tests/try_swf_7/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic try-catch
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
Expected output:
```
In try
Caught: Error!
After try-catch
```

### Test Case 2: Try-finally (no exception)
```actionscript
try {
    trace("Try block");
} finally {
    trace("Finally block");
}
trace("After");
```
Expected output:
```
Try block
Finally block
After
```

### Test Case 3: Try-catch-finally
```actionscript
try {
    trace("Try");
    throw "Error";
} catch (e) {
    trace("Catch: " + e);
} finally {
    trace("Finally");
}
trace("Done");
```
Expected output:
```
Try
Catch: Error
Finally
Done
```

### Test Case 4: No exception thrown
```actionscript
try {
    trace("Try block");
    trace("No error");
} catch (e) {
    trace("This won't print");
}
trace("Continued");
```
Expected output:
```
Try block
No error
Continued
```

### Test Case 5: Exception propagation
```actionscript
function test() {
    throw "Error from function";
}
try {
    test();
} catch (e) {
    trace("Caught: " + e);
}
```
Expected output: `Caught: Error from function`

## Implementation Hints

**Pattern**: This is a complex control flow operation requiring exception handling infrastructure.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_TRY:
{
    // Read flags byte
    u8 flags;
    in.read((char*)&flags, 1);

    bool catch_in_register = (flags & 0x04) != 0;
    bool has_finally = (flags & 0x02) != 0;
    bool has_catch = (flags & 0x01) != 0;

    // Read block sizes
    u16 try_size, catch_size, finally_size;
    in.read((char*)&try_size, sizeof(u16));
    in.read((char*)&catch_size, sizeof(u16));
    in.read((char*)&finally_size, sizeof(u16));

    // Read catch name or register
    std::string catch_name;
    u8 catch_register = 0;
    if (has_catch) {
        if (catch_in_register) {
            in.read((char*)&catch_register, 1);
        } else {
            char ch;
            while (in.read(&ch, 1) && ch != '\0') {
                catch_name += ch;
            }
        }
    }

    // Read try block
    std::vector<u8> try_body(try_size);
    in.read((char*)try_body.data(), try_size);

    // Read catch block
    std::vector<u8> catch_body(catch_size);
    if (has_catch) {
        in.read((char*)catch_body.data(), catch_size);
    }

    // Read finally block
    std::vector<u8> finally_body(finally_size);
    if (has_finally) {
        in.read((char*)finally_body.data(), finally_size);
    }

    // Generate C code with exception handling structure
    out_script << "\t" << "// Try-Catch-Finally" << endl
               << "\t" << "actionTryBegin(stack, sp);" << endl
               << "\t" << "if (actionTryExecute(stack, sp)) {" << endl;

    // Translate try block
    translateActionBlock(try_body, out_script);

    if (has_catch) {
        out_script << "\t" << "} else {" << endl
                   << "\t\t" << "// Catch block" << endl;
        if (catch_in_register) {
            out_script << "\t\t" << "actionCatchToRegister(stack, sp, " << (int)catch_register << ");" << endl;
        } else {
            out_script << "\t\t" << "actionCatchToVariable(stack, sp, \"" << catch_name << "\");" << endl;
        }
        // Translate catch block
        translateActionBlock(catch_body, out_script);
    }

    out_script << "\t" << "}" << endl;

    if (has_finally) {
        out_script << "\t" << "// Finally block" << endl;
        // Translate finally block
        translateActionBlock(finally_body, out_script);
    }

    out_script << "\t" << "actionTryEnd(stack, sp);" << endl;

    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
// Exception handling state
typedef struct {
    bool exception_thrown;
    ActionVar exception_value;
    int handler_depth;
} ExceptionState;

static ExceptionState g_exception_state = {false, {0}, 0};

void actionTryBegin(char* stack, u32* sp)
{
    // Push exception handler onto handler stack
    g_exception_state.handler_depth++;
}

bool actionTryExecute(char* stack, u32* sp)
{
    // Returns true if try block should execute normally
    // Returns false if exception was thrown (jump to catch)
    return !g_exception_state.exception_thrown;
}

void actionCatchToVariable(char* stack, u32* sp, const char* var_name)
{
    // Store caught exception in named variable
    if (g_exception_state.exception_thrown) {
        setVariable(var_name, g_exception_state.exception_value);
        g_exception_state.exception_thrown = false;
    }
}

void actionCatchToRegister(char* stack, u32* sp, u8 reg_num)
{
    // Store caught exception in register
    if (g_exception_state.exception_thrown) {
        setRegister(reg_num, g_exception_state.exception_value);
        g_exception_state.exception_thrown = false;
    }
}

void actionTryEnd(char* stack, u32* sp)
{
    // Pop exception handler from handler stack
    g_exception_state.handler_depth--;
    if (g_exception_state.handler_depth == 0) {
        // Clear exception if at top level
        g_exception_state.exception_thrown = false;
    }
}

// Throw action (0x2A) - works with Try
void actionThrow(char* stack, u32* sp)
{
    // Pop value to throw
    ActionVar throw_value;
    popVar(stack, sp, &throw_value);

    // Set exception state
    g_exception_state.exception_thrown = true;
    g_exception_state.exception_value = throw_value;

    // Control flow will jump to catch or finally block
}
```

### Simplified Implementation

For initial implementation, you can simplify:

```c
void actionTry(char* stack, u32* sp,
               bool has_catch, bool has_finally,
               const char* catch_name)
{
    // Simplified: just log the try-catch-finally structure
    printf("// Try");
    if (has_catch) {
        printf("-Catch(%s)", catch_name ? catch_name : "register");
    }
    if (has_finally) {
        printf("-Finally");
    }
    printf("\n");

    // TODO: Implement proper exception handling
    // This is complex and requires:
    // - Exception state tracking
    // - Control flow jumps
    // - Stack unwinding
    // - Finally block guarantees
}
```

### Similar Opcodes

Reference these opcodes:
- `actionThrow` (0x2A) - Throw exception
- `actionIf` (0x9D) - Conditional branching
- `actionJump` (0x99) - Unconditional jump
- `actionReturn` (0x3E) - Return from function (with exception propagation)

### Edge Cases to Handle

- Exception thrown in try block
- No exception thrown
- Exception in catch block (propagates)
- Exception in finally block (replaces previous)
- Multiple nested try-catch blocks
- Exception propagation through call stack
- Finally block execution on return
- Finally block execution on exception

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/try_swf_7/README.md` - Test description and expected output
- Document exception handling semantics
- Explain try-catch-finally execution flow

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] All parameters correctly parsed from action record
- [ ] Try, catch, finally blocks correctly identified
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Exception throwing and catching works
- [ ] Finally block always executes
- [ ] Exception propagation works
- [ ] Nested try-catch works
- [ ] Documentation created

## Important Notes

**Flash Version**: Available in SWF 7+

**ActionScript Syntax**:
```actionscript
try {
    // Code that might throw
    throw "error message";
} catch (e) {
    // Handle exception
    trace("Error: " + e);
} finally {
    // Always executes
    cleanup();
}
```

**Execution Flow**:
1. Try block executes
2. If exception thrown → jump to catch (if exists)
3. Catch block executes (if exists and exception thrown)
4. Finally block executes (always, even if exception or return)
5. If exception not caught → propagate to outer try-catch

**Finally Guarantees**:
- Finally block ALWAYS executes
- Even if try block returns
- Even if catch block throws
- Even if exception propagates

**Catch Variable**:
- Can be stored in named variable (`catch (e)`)
- Or in register (for optimization)
- Variable/register contains the thrown value

**Exception Types**: Any ActionScript value can be thrown:
- Strings: `throw "Error"`
- Numbers: `throw 404`
- Objects: `throw new Error("message")`
- null, undefined, etc.

**Translation Complexity**: This is one of the most complex opcodes:
- Three separate code blocks (try, catch, finally)
- Need to translate each block separately
- Need to generate proper control flow
- Need to handle exception state

**Implementation Challenges**:
1. **Control Flow**: Need to jump to catch/finally blocks
2. **State Management**: Track whether exception is thrown
3. **Stack Unwinding**: Clean up stack on exception
4. **Finally Guarantee**: Ensure finally always runs
5. **Propagation**: Pass exceptions up call stack
6. **Nested Handlers**: Support nested try-catch blocks

**Testing Strategy**:
- Start with simplified implementation (log only)
- Implement basic try-catch (no finally)
- Add exception throwing (actionThrow)
- Add finally support
- Test exception propagation
- Test nested try-catch
- Test edge cases

**Coordination**: This opcode relates to:
- ActionThrow (0x2A) opcode
- Call stack management
- Variable/register storage
- Function return handling
- Control flow infrastructure

**C Implementation Challenges**:
- C doesn't have built-in exception handling
- Need to use setjmp/longjmp or state tracking
- Or generate C code with explicit control flow

**Alternative Approach** (using setjmp/longjmp):
```c
#include <setjmp.h>

jmp_buf exception_handler;

void actionTry() {
    if (setjmp(exception_handler) == 0) {
        // Try block
    } else {
        // Catch block
    }
    // Finally block
}

void actionThrow() {
    longjmp(exception_handler, 1);
}
```

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

**Note**: This is the most complex opcode in this set. Consider implementing other opcodes first to build up the necessary infrastructure.
