# Opcode Implementation Task: BIT_XOR (0x62)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **BIT_XOR**

## Opcode Specification

**Opcode Name**: BIT_XOR
**Spec Name**: ActionBitXor
**Hex Value**: 0x62
**Category**: Bitwise Logic
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionBitXor pops two numbers off of the stack, performs a bitwise XOR (exclusive OR), and pushes an S32 number to the stack. The arguments are converted to 32-bit unsigned integers before performing the bitwise operation. The result is a SIGNED 32-bit integer.

**Operation**: Pops two values, converts to 32-bit integers, performs bitwise XOR, pushes result.

**Expected Behavior**:
- Pop value `arg1` from stack
- Pop value `arg2` from stack
- Convert both to 32-bit unsigned integers
- Perform bitwise XOR: `result = arg2 ^ arg1`
- Push result as SIGNED 32-bit integer onto stack
- XOR returns 1 when bits differ, 0 when bits are the same

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_BIT_XOR = 0x62` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionBitXor(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/bit_xor_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh bit_xor_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic bitwise XOR
```actionscript
trace(12 ^ 10);  // 1100 ^ 1010 = 0110 = 6
```
Expected output: `6`

### Test Case 2: XOR with zero (identity)
```actionscript
trace(42 ^ 0);  // Any value ^ 0 = value
```
Expected output: `42`

### Test Case 3: XOR with itself (always zero)
```actionscript
trace(15 ^ 15);  // Any value ^ itself = 0
```
Expected output: `0`

### Test Case 4: Bit flipping
```actionscript
trace(170 ^ 85);  // 10101010 ^ 01010101 = 11111111 = 255
```
Expected output: `255`

### Test Case 5: Double XOR (self-inverse property)
```actionscript
// XOR same value twice returns original
trace((42 ^ 17) ^ 17);  // Should equal 42
```
Expected output: `42`

## Implementation Hints

**Category**: This is a bitwise operation requiring integer conversion.

**Pattern**: Binary bitwise operation
```
convertFloat → convert to int32 → pop → convertFloat → convert to int32 → pop → bitwise XOR → push result
```

**Reference these similar opcodes**:
- `actionBitAnd` (bitwise AND) - same pattern, different operator
- `actionBitOr` (bitwise OR) - same pattern, different operator

**Implementation outline**:
```c
void actionBitXor(char* stack, u32* sp)
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

    // Perform bitwise XOR
    int32_t result = int_b ^ int_a;

    // Convert result back to float for stack
    float result_float = (float) result;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_float));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_BIT_XOR:
{
    out_script << "\t" << "// BitXor" << endl
               << "\t" << "actionBitXor(stack, sp);" << endl;
    break;
}
```

**Note**:
- Very similar to BIT_AND and BIT_OR, just use `^` instead
- XOR has special properties: a ^ a = 0, a ^ 0 = a
- Useful for toggling bits and simple encryption
- XOR is its own inverse: (a ^ b) ^ b = a

## Documentation

Create these files as you work:
- `SWFRecomp/tests/bit_xor_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x62)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Integer conversion handled correctly
- [ ] Result is correct for bitwise XOR operation
- [ ] XOR properties verified (x^x=0, x^0=x)
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Arguments are converted to UNSIGNED 32-bit for operation
- Result is a SIGNED 32-bit integer (but stored as float)
- The ^ operator in C performs bitwise XOR
- XOR properties: commutative, associative, self-inverse
- Useful for bit masking, toggling, and simple obfuscation

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
