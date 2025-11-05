# Opcode Implementation Task: BIT_OR (0x61)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **BIT_OR**

## Opcode Specification

**Opcode Name**: BIT_OR
**Spec Name**: ActionBitOr
**Hex Value**: 0x61
**Category**: Bitwise Logic
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionBitOr pops two numbers off of the stack, performs a bitwise OR, and pushes an S32 number to the stack. The arguments are converted to 32-bit unsigned integers before performing the bitwise operation. The result is a SIGNED 32-bit integer.

**Operation**: Pops two values, converts to 32-bit integers, performs bitwise OR, pushes result.

**Expected Behavior**:
- Pop value `arg1` from stack
- Pop value `arg2` from stack
- Convert both to 32-bit unsigned integers
- Perform bitwise OR: `result = arg2 | arg1`
- Push result as SIGNED 32-bit integer onto stack

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_BIT_OR = 0x61` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionBitOr(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/bit_or_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh bit_or_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic bitwise OR
```actionscript
trace(12 | 10);  // 1100 | 1010 = 1110 = 14
```
Expected output: `14`

### Test Case 2: OR with zero (identity)
```actionscript
trace(42 | 0);  // Any value | 0 = value
```
Expected output: `42`

### Test Case 3: OR with all bits set
```actionscript
trace(10 | 15);  // 1010 | 1111 = 1111 = 15
```
Expected output: `15`

### Test Case 4: Combining bit flags
```actionscript
trace(1 | 2 | 4);  // 001 | 010 | 100 = 111 = 7
```
Expected output: `7`

### Test Case 5: Large numbers
```actionscript
trace(0xFF00 | 0x00FF);  // Combine high and low bytes
```
Expected output: `65535` (0xFFFF)

## Implementation Hints

**Category**: This is a bitwise operation requiring integer conversion.

**Pattern**: Binary bitwise operation
```
convertFloat → convert to int32 → pop → convertFloat → convert to int32 → pop → bitwise OR → push result
```

**Reference these similar opcodes**:
- `actionBitAnd` (bitwise AND) - same pattern, different operator
- `actionOr` (logical OR) in `SWFModernRuntime/src/actionmodern/action.c`

**Implementation outline**:
```c
void actionBitOr(char* stack, u32* sp)
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

    // Perform bitwise OR
    int32_t result = int_b | int_a;

    // Convert result back to float for stack
    float result_float = (float) result;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_float));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_BIT_OR:
{
    out_script << "\t" << "// BitOr" << endl
               << "\t" << "actionBitOr(stack, sp);" << endl;
    break;
}
```

**Note**:
- Very similar to BIT_AND, just use `|` instead of `&`
- Convert floats to 32-bit integers before operation
- Use `int32_t` for signed integer type
- Result is signed but stored as float on stack

## Documentation

Create these files as you work:
- `SWFRecomp/tests/bit_or_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x61)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Integer conversion handled correctly
- [ ] Result is correct for bitwise OR operation
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Arguments are converted to UNSIGNED 32-bit for operation
- Result is a SIGNED 32-bit integer (but stored as float)
- The | operator in C performs bitwise OR
- Useful for combining bit flags and masks
- OR with 0 is identity operation (returns original value)

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
