# AS2 Opcode Implementation Task: STACK_SWAP

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **STACK_SWAP**

## Opcode Specification

**Opcode Name**: STACK_SWAP (Swap Top Two Stack Values)
**Hex Value**: 0x4C
**Category**: Stack Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Swaps the top two values on the stack.

**Operation**: Exchange positions of top two stack entries.

**Expected Behavior**:
- Pop the top value (value1)
- Pop the second value (value2)
- Push value1 (was on top)
- Push value2 (was second)
- Result: values are swapped
- Preserve types and values exactly

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/stack_swap_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Swap numbers for subtraction
```actionscript
// Push 3, push 7, swap, subtract
// Stack: 3, 7 → after swap: 7, 3 → after subtract: 7-3 = 4
trace(3 - 7);  // Would normally be -4, but with swap: 4
```
Expected output: `4` (using swap to reverse operands)

### Test Case 2: Swap number and string
```actionscript
// Push "hello", push 42, swap
// Stack: "hello", 42 → after swap: 42, "hello"
// Then concatenate or other operation
```
Expected output: Verify swapped order

### Test Case 3: Swap for division
```actionscript
// Push 2, push 10, swap, divide
// Stack: 2, 10 → after swap: 10, 2 → after divide: 10/2 = 5
trace(2 / 10);  // Would normally be 0.2, but with swap: 5
```
Expected output: `5`

## Implementation Hints

**Pattern**: This is a stack manipulation operation requiring temporary storage.

**Reference these similar opcodes**:
- `actionDuplicate` (0x3D) - Stack manipulation reference
- `actionPop` (0x17) - Stack operations

**Implementation outline**:
```c
void actionStackSwap(char* stack, u32* sp)
{
    // Pop top value (value1)
    ActionVar val1;
    popVar(stack, sp, &val1);

    // Pop second value (value2)
    ActionVar val2;
    popVar(stack, sp, &val2);

    // Push value1 (was on top, now goes to bottom)
    switch (val1.type) {
        case ACTION_STACK_VALUE_F32:
        {
            float v = val1.value.f32;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v));
            break;
        }
        case ACTION_STACK_VALUE_STRING:
        {
            const char* str = (const char*)val1.value.u64;
            PUSH_STR(str, val1.length);  // Assuming length is stored in ActionVar
            break;
        }
        // ... handle other types
        default:
            PUSH(val1.type, val1.value.u64);
            break;
    }

    // Push value2 (was second, now on top)
    switch (val2.type) {
        case ACTION_STACK_VALUE_F32:
        {
            float v = val2.value.f32;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &v));
            break;
        }
        case ACTION_STACK_VALUE_STRING:
        {
            const char* str = (const char*)val2.value.u64;
            PUSH_STR(str, val2.length);
            break;
        }
        // ... handle other types
        default:
            PUSH(val2.type, val2.value.u64);
            break;
    }
}
```

**Note**:
- Must preserve both types and values
- String lifetime must be maintained through the swap
- Ensure stack pointer management is correct
- Both values must be popped before pushing

**Important Considerations**:
- Type preservation for both values
- String and object pointer validity
- Stack balance (2 pops, 2 pushes)
- Temporary storage for values

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/stack_swap_swf_4/README.md` - Test description and expected output
- Document swap behavior for different type combinations

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] All type combinations handled correctly
- [ ] No stack corruption
- [ ] Documentation created

## Additional Notes

**ActionScript Usage**: While AS2 doesn't expose a `swap()` function directly, this opcode is used internally by the compiler to rearrange stack values for operations.

**Flash Version**: Available in SWF 4+

**Stack Diagram**:
```
Before:  ... | value2 | value1 |
After:   ... | value1 | value2 |
```

**Use Case**: Commonly used to reverse operand order for non-commutative operations (subtraction, division, comparison).

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
