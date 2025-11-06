# AS2 Opcode Implementation Task: DUPLICATE

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **DUPLICATE**

## Opcode Specification

**Opcode Name**: DUPLICATE (Stack Duplicate)
**Hex Value**: 0x3D
**Category**: Stack Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Duplicates the top value on the stack.

**Operation**: Peek at top of stack, push a copy of it.

**Expected Behavior**:
- Read the top value from the stack (without popping)
- Push a duplicate copy of that value onto the stack
- Preserve the type and value exactly
- After operation, stack has two identical values at the top

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/duplicate_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Duplicate number
```actionscript
// Push 42, duplicate it, add them
// Stack: 42
// After duplicate: 42, 42
// After add: 84
trace(42 + 42);  // But using duplicate instead of pushing 42 twice
```
Expected output: `84`

### Test Case 2: Duplicate string
```actionscript
// Push "hello", duplicate it, concatenate
// Result: "hellohello"
trace("hello" + "hello");  // Using duplicate
```
Expected output: `hellohello`

### Test Case 3: Duplicate and pop
```actionscript
// Push value, duplicate, pop one copy, original remains
var x = 5;
// Push x (5), duplicate (5, 5), pop (5), set to variable
trace(x);
```
Expected output: `5`

## Implementation Hints

**Pattern**: This is a stack manipulation operation requiring careful pointer management.

**Reference these similar opcodes**:
- `actionPop` (0x17) - Stack manipulation reference
- `PUSH` and `POP` macros in `action.h`

**Implementation outline**:
```c
void actionDuplicate(char* stack, u32* sp)
{
    // Peek at top value without popping
    ActionVar top;
    peekVar(stack, sp, &top);

    // Push a copy of the value
    // Need to handle different types appropriately
    switch (top.type) {
        case ACTION_STACK_VALUE_F32:
        {
            float val = top.value.f32;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &val));
            break;
        }
        case ACTION_STACK_VALUE_STRING:
        {
            // For strings, need to copy the string pointer/data
            // May need special handling depending on string storage
            const char* str = (const char*)top.value.u64;
            u32 len = STACK_TOP_LENGTH;  // Get length from stack entry
            PUSH_STR(str, len);
            break;
        }
        case ACTION_STACK_VALUE_U32:
        {
            u32 val = top.value.u32;
            PUSH(ACTION_STACK_VALUE_U32, VAL(u32, &val));
            break;
        }
        // Add other types as needed
        default:
            // Generic copy
            PUSH(top.type, top.value.u64);
            break;
    }
}
```

**Note**:
- Must preserve both type and value
- String duplication may require special handling (shallow vs deep copy)
- Ensure stack pointer management is correct
- Don't pop the original value

**Important Considerations**:
- Type preservation is critical
- String lifetime management (ensure duplicated strings remain valid)
- Stack overflow protection
- For object types, consider reference counting implications

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/duplicate_swf_4/README.md` - Test description and expected output
- Document any type-specific handling

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] All types handled correctly (numbers, strings, etc.)
- [ ] No stack corruption
- [ ] Documentation created

## Additional Notes

**ActionScript Usage**: While AS2 doesn't have a direct `duplicate()` function, this opcode is used internally by the compiler for operations that need the same value multiple times.

**Flash Version**: Available in SWF 4+

**Stack Diagram**:
```
Before:  ... | value |
After:   ... | value | value |
```

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
