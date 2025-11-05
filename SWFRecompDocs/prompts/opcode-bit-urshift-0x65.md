# Opcode Implementation Task: BIT_URSHIFT (0x65)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **BIT_URSHIFT**

## Opcode Specification

**Opcode Name**: BIT_URSHIFT
**Spec Name**: ActionBitURShift
**Hex Value**: 0x65
**Category**: Bitwise Logic
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionBitURShift pops the value and shift count arguments from the stack. The value argument is converted to 32-bit signed integer and only the least significant 5 bits are used as the shift count. The bits in the arg value are shifted to the right by the shift count. ActionBitURShift pushes a UI32 number to the stack. This is a LOGICAL right shift (zero-filling).

**Operation**: Pops shift count, pops value, shifts value right (logical/unsigned), pushes result.

**Expected Behavior**:
- Pop `shift_count` from stack (first pop)
- Pop `value` from stack (second pop)
- Convert value to 32-bit integer
- Use only least significant 5 bits of shift_count (0-31 range)
- Shift value right (logical): `result = value >>> shift_count`
- **Logical shift**: always fills with zeros from left (no sign extension)
- Push result as UNSIGNED 32-bit integer onto stack
- Unlike arithmetic shift, sign bit is NOT extended

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_BIT_URSHIFT = 0x65` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionBitURShift(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/bit_urshift_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh bit_urshift_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic unsigned right shift
```actionscript
trace(8 >>> 2);  // 1000 >>> 2 = 0010 = 2
```
Expected output: `2`

### Test Case 2: Shift negative number (no sign extension)
```actionscript
trace(-8 >>> 2);  // Treats as unsigned, shifts with zeros
```
Expected output: `1073741822` (large positive number, not negative)

### Test Case 3: Zero shift
```actionscript
trace(42 >>> 0);  // No shift
```
Expected output: `42`

### Test Case 4: Shift all bits out
```actionscript
trace(255 >>> 8);  // Shift byte right
```
Expected output: `0`

### Test Case 5: Shift count wrapping
```actionscript
trace(16 >>> 33);  // 33 & 0x1F = 1, so 16 >>> 1 = 8
```
Expected output: `8`

## Implementation Hints

**Category**: This is a bitwise logical (unsigned) shift operation.

**Pattern**: Binary bitwise unsigned shift operation
```
pop shift_count → pop value → convert to uint32 → mask shift count → logical shift right → push result
```

**Reference these similar opcodes**:
- `actionBitRShift` - arithmetic version (sign-extending)
- `actionBitLShift` - left shift version

**Implementation outline**:
```c
void actionBitURShift(char* stack, u32* sp)
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

    // IMPORTANT: Use UNSIGNED for logical shift
    uint32_t value = (uint32_t) ((int32_t) value_var.value.f32);

    // Mask shift count to 5 bits (0-31 range)
    shift_count = shift_count & 0x1F;

    // Perform logical (unsigned) right shift
    // In C, >> on unsigned int is logical shift (zero-fill)
    uint32_t result = value >> shift_count;

    // Convert result back to float for stack
    // Cast through double to preserve full 32-bit unsigned value
    float result_float = (float) ((double) result);

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_float));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_BIT_URSHIFT:
{
    out_script << "\t" << "// BitURShift" << endl
               << "\t" << "actionBitURShift(stack, sp);" << endl;
    break;
}
```

**Note**:
- **Critical**: Use `uint32_t` for value to get logical shift
- In C, >> on unsigned types is logical shift (zero-fill)
- In C, >> on signed types is arithmetic shift (sign-extend)
- Mask shift_count to 5 bits: `shift_count & 0x1F`
- Pop order: shift_count first, then value
- Result is unsigned but stored as float

## Documentation

Create these files as you work:
- `SWFRecomp/tests/bit_urshift_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x65)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Shift count masking implemented (& 0x1F)
- [ ] UNSIGNED conversion used (uint32_t)
- [ ] Logical shift verified (zero-fill, no sign extension)
- [ ] Pop order correct (shift_count first, value second)
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Only least significant 5 bits of shift_count are used (0-31)
- Value is converted to 32-bit UNSIGNED integer (critical!)
- **Logical shift**: always fills with zeros (no sign extension)
- Different from arithmetic shift (which extends sign bit)
- Use `uint32_t` type to ensure logical shift behavior in C
- Negative numbers become large positive when treated as unsigned
- **Pop order**: shift_count FIRST, then value

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
