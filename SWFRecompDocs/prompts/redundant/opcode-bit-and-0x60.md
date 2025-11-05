# Opcode Implementation Task: BIT_AND (0x60)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **BIT_AND**

## Opcode Specification

**Opcode Name**: BIT_AND
**Spec Name**: ActionBitAnd
**Hex Value**: 0x60
**Category**: Bitwise Logic
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionBitAnd pops two numbers off of the stack, performs a bitwise AND, and pushes an S32 number to the stack. The arguments are converted to 32-bit unsigned integers before performing the bitwise operation. The result is a SIGNED 32-bit integer.

**Operation**: Pops two values, converts to 32-bit integers, performs bitwise AND, pushes result.

**Expected Behavior**:
- Pop value `arg1` from stack
- Pop value `arg2` from stack
- Convert both to 32-bit unsigned integers
- Perform bitwise AND: `result = arg2 & arg1`
- Push result as SIGNED 32-bit integer onto stack
- Result is treated as a signed integer in ActionScript

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_BIT_AND = 0x60` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionBitAnd(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/bit_and_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh bit_and_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic bitwise AND
```actionscript
trace(12 & 10);  // 1100 & 1010 = 1000 = 8
```
Expected output: `8`

### Test Case 2: All bits set
```actionscript
trace(15 & 15);  // 1111 & 1111 = 1111 = 15
```
Expected output: `15`

### Test Case 3: AND with zero
```actionscript
trace(255 & 0);  // Any value & 0 = 0
```
Expected output: `0`

### Test Case 4: Bit masking
```actionscript
trace(255 & 15);  // 11111111 & 00001111 = 00001111 = 15
```
Expected output: `15`

### Test Case 5: Large numbers (test 32-bit conversion)
```actionscript
trace(0xFFFFFFFF & 0x0000FFFF);
```
Expected output: `65535` (0xFFFF)

## Implementation Hints

**Category**: This is a bitwise operation requiring integer conversion.

**Pattern**: Binary bitwise operation
```
convertFloat → convert to int32 → pop → convertFloat → convert to int32 → pop → bitwise AND → push result
```

**Reference these similar opcodes**:
- `actionAnd` (logical AND) in `SWFModernRuntime/src/actionmodern/action.c`
- `actionMultiply`, `actionDivide` for binary operation patterns

**Implementation outline**:
```c
void actionBitAnd(char* stack, u32* sp)
{
    // Convert and pop first argument
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert and pop second argument
    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Convert to 32-bit integers (truncate floats)
    int32_t int_a = (int32_t) a.value.f32;
    int32_t int_b = (int32_t) b.value.f32;

    // Perform bitwise AND
    int32_t result = int_b & int_a;

    // Convert result back to float for stack
    float result_float = (float) result;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_float));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_BIT_AND:
{
    out_script << "\t" << "// BitAnd" << endl
               << "\t" << "actionBitAnd(stack, sp);" << endl;
    break;
}
```

**Note**:
- Convert floats to 32-bit integers before operation
- Use `int32_t` for signed integer type (from `<stdint.h>`)
- Result is signed but stored as float on stack (ActionScript convention)
- The bitwise operation works on the binary representation

## Documentation

Create these files as you work:
- `SWFRecomp/tests/bit_and_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x60)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Integer conversion handled correctly
- [ ] Result is correct for bitwise AND operation
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Arguments are converted to UNSIGNED 32-bit for operation
- Result is a SIGNED 32-bit integer (but stored as float)
- Use `(int32_t)` cast to convert float to integer
- The & operator in C performs bitwise AND
- Floats are truncated (not rounded) when converting to integer

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
