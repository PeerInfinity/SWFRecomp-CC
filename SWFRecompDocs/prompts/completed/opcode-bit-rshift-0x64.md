# Opcode Implementation Task: BIT_RSHIFT (0x64)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **BIT_RSHIFT**

## Opcode Specification

**Opcode Name**: BIT_RSHIFT
**Spec Name**: ActionBitRShift
**Hex Value**: 0x64
**Category**: Bitwise Logic
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionBitRShift pops the shift count from the stack. Pops the value from the stack. The value argument is converted to a 32-bit signed integer and only the least significant 5 bits are used as the shift count. The bits in the arg value are shifted to the right by the shift count. ActionBitRShift pushes an S32 number to the stack. This is an ARITHMETIC right shift (sign-extending).

**Operation**: Pops shift count, pops value, shifts value right (arithmetic), pushes result.

**Expected Behavior**:
- Pop `shift_count` from stack (first pop)
- Pop `value` from stack (second pop)
- Convert value to 32-bit signed integer
- Use only least significant 5 bits of shift_count (0-31 range)
- Shift value right (arithmetic): `result = value >> shift_count`
- **Arithmetic shift**: sign bit is preserved (extended)
- Push result as SIGNED 32-bit integer onto stack
- For positive numbers, zeros fill from left
- For negative numbers, ones fill from left (sign extension)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_BIT_RSHIFT = 0x64` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionBitRShift(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/bit_rshift_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh bit_rshift_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic right shift (positive)
```actionscript
trace(8 >> 2);  // 1000 >> 2 = 0010 = 2
```
Expected output: `2`

### Test Case 2: Divide by power of 2
```actionscript
trace(20 >> 2);  // 20 / 4 = 5 (shifting right by n divides by 2^n)
```
Expected output: `5`

### Test Case 3: Shift negative number (sign extension)
```actionscript
trace(-8 >> 2);  // Negative: sign bit extends
```
Expected output: `-2` (sign extended)

### Test Case 4: Zero shift
```actionscript
trace(42 >> 0);  // No shift
```
Expected output: `42`

### Test Case 5: Shift count wrapping
```actionscript
trace(16 >> 33);  // 33 & 0x1F = 1, so 16 >> 1 = 8
```
Expected output: `8`

## Implementation Hints

**Category**: This is a bitwise arithmetic shift operation requiring integer conversion.

**Pattern**: Binary bitwise shift operation
```
pop shift_count → pop value → convert to int32 → mask shift count → arithmetic shift right → push result
```

**Reference these similar opcodes**:
- `actionBitLShift` - same pattern, opposite direction
- `actionBitAnd` - for integer conversion pattern

**Implementation outline**:
```c
void actionBitRShift(char* stack, u32* sp)
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

    // Perform arithmetic right shift (sign-extending)
    // In C, >> on signed int is arithmetic shift
    int32_t result = value >> shift_count;

    // Convert result back to float for stack
    float result_float = (float) result;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_float));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_BIT_RSHIFT:
{
    out_script << "\t" << "// BitRShift" << endl
               << "\t" << "actionBitRShift(stack, sp);" << endl;
    break;
}
```

**Note**:
- Pop order matters: shift_count first, then value
- Mask shift_count to 5 bits: `shift_count & 0x1F`
- Use `int32_t` for SIGNED integer (arithmetic shift)
- In C, >> on signed integers performs arithmetic shift (sign-extending)
- Right shift by n divides by 2^n (rounding toward negative infinity)
- Negative numbers stay negative when shifted right

## Documentation

Create these files as you work:
- `SWFRecomp/tests/bit_rshift_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x64)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Shift count masking implemented (& 0x1F)
- [ ] Arithmetic shift verified (sign extension for negative numbers)
- [ ] Pop order correct (shift_count first, value second)
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Only least significant 5 bits of shift_count are used (0-31)
- Value is converted to 32-bit SIGNED integer
- **Arithmetic shift**: preserves sign (extends sign bit)
- Different from logical shift (which fills with zeros)
- In C, >> on `int32_t` performs arithmetic shift automatically
- Right shift by n divides by 2^n for positive numbers
- **Pop order**: shift_count FIRST, then value

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
