# Opcode Implementation Task: BIT_LSHIFT (0x63)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **BIT_LSHIFT**

## Opcode Specification

**Opcode Name**: BIT_LSHIFT
**Spec Name**: ActionBitLShift
**Hex Value**: 0x63
**Category**: Bitwise Logic
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionBitLShift pops the shift count arg and then value off of the stack. The value argument is converted to 32-bit signed integer and only the least significant 5 bits are used as the shift count. The bits in the value arg are shifted to the left by the shift count. ActionBitLShift pushes an S32 number to the stack.

**Operation**: Pops shift count, pops value, shifts value left by count, pushes result.

**Expected Behavior**:
- Pop `shift_count` from stack (first pop)
- Pop `value` from stack (second pop)
- Convert value to 32-bit signed integer
- Use only least significant 5 bits of shift_count (0-31 range)
- Shift value left: `result = value << shift_count`
- Push result as SIGNED 32-bit integer onto stack
- Bits shifted off the left are lost, zeros fill from right

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_BIT_LSHIFT = 0x63` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionBitLShift(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/bit_lshift_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh bit_lshift_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic left shift
```actionscript
trace(1 << 3);  // 0001 << 3 = 1000 = 8
```
Expected output: `8`

### Test Case 2: Multiply by power of 2
```actionscript
trace(5 << 2);  // 5 * 4 = 20 (shifting left by n multiplies by 2^n)
```
Expected output: `20`

### Test Case 3: Shift count wrapping (5 bits)
```actionscript
trace(1 << 33);  // 33 & 0x1F = 1, so 1 << 1 = 2
```
Expected output: `2`

### Test Case 4: Zero shift
```actionscript
trace(42 << 0);  // No shift
```
Expected output: `42`

### Test Case 5: Maximum shift
```actionscript
trace(1 << 31);  // Shift into sign bit
```
Expected output: `-2147483648` (or large negative number due to sign bit)

## Implementation Hints

**Category**: This is a bitwise shift operation requiring integer conversion.

**Pattern**: Binary bitwise shift operation
```
pop shift_count → pop value → convert to int32 → mask shift count → shift left → push result
```

**Reference these similar opcodes**:
- `actionBitAnd` - for integer conversion pattern
- `actionMultiply` - for binary operation pattern

**Implementation outline**:
```c
void actionBitLShift(char* stack, u32* sp)
{
    // Pop shift count (first argument)
    convertFloat(stack, sp);
    ActionVar shift_count_var;
    popVar(stack, sp, &shift_count_var);

    // Pop value to shift (second argument)
    convertFloat(stack, sp);
    ActionVar value_var;
    popVar(stack, sp, &value_var);

    // Convert to integers
    int32_t shift_count = (int32_t) shift_count_var.value.f32;
    int32_t value = (int32_t) value_var.value.f32;

    // Mask shift count to 5 bits (0-31 range)
    shift_count = shift_count & 0x1F;

    // Perform left shift
    int32_t result = value << shift_count;

    // Convert result back to float for stack
    float result_float = (float) result;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_float));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_BIT_LSHIFT:
{
    out_script << "\t" << "// BitLShift" << endl
               << "\t" << "actionBitLShift(stack, sp);" << endl;
    break;
}
```

**Note**:
- Pop order matters: shift_count first, then value
- Mask shift_count to 5 bits: `shift_count & 0x1F`
- Left shift fills with zeros from the right
- Left shift by n is equivalent to multiplying by 2^n
- The << operator in C performs left shift

## Documentation

Create these files as you work:
- `SWFRecomp/tests/bit_lshift_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x63)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Shift count masking implemented (& 0x1F)
- [ ] Pop order correct (shift_count first, value second)
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Only least significant 5 bits of shift_count are used (0-31)
- Value is converted to 32-bit SIGNED integer
- Result is SIGNED 32-bit integer (can become negative)
- Shifting left by n multiplies by 2^n (for values that don't overflow)
- **Pop order**: shift_count FIRST, then value

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
