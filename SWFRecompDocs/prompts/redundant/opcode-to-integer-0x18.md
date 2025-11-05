# Opcode Implementation Task: TO_INTEGER (0x18)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **TO_INTEGER**

## Opcode Specification

**Opcode Name**: TO_INTEGER
**Spec Name**: ActionToInteger
**Hex Value**: 0x18
**Category**: Type Conversion
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionToInteger converts a value to an integer by truncating (not rounding) the decimal portion.

**Operation**: Pops value, converts to integer (truncate), pushes result.

**Expected Behavior**:
- Pop a value from stack
- Convert the value to a number (if not already)
- Discard any digits after the decimal point (truncate, don't round)
- Push the resulting integer to the stack
- For strings: parse as number first, then truncate
- For booleans: true→1, false→0
- For null/undefined: 0
- Available in SWF 4 and later

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_TO_INTEGER = 0x18` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionToInteger(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/to_integer_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh to_integer_swf_4 native` and verify output

## Test Cases

### Test Case 1: Truncate positive float
```actionscript
trace(int(3.7));  // Truncate, not round
```
Expected output: `3`

### Test Case 2: Truncate negative float
```actionscript
trace(int(-3.7));  // Truncate toward zero
```
Expected output: `-3`

### Test Case 3: Integer input (no change)
```actionscript
trace(int(42));
```
Expected output: `42`

### Test Case 4: Zero
```actionscript
trace(int(0.5));
```
Expected output: `0`

### Test Case 5: Large number
```actionscript
trace(int(1234.5678));
```
Expected output: `1234`

## Implementation Hints

**Category**: This is a type conversion operation (unary).

**Pattern**: Unary type conversion
```
pop value → convert to float → truncate → push result
```

**Reference these similar opcodes**:
- `actionNot` - unary operation pattern
- `convertFloat` - type conversion utility
- Bitwise operations - integer conversion examples

**Implementation outline**:
```c
void actionToInteger(char* stack, u32* sp)
{
    // Convert to float first (handles various types)
    convertFloat(stack, sp);

    // Pop the float value
    ActionVar a;
    popVar(stack, sp, &a);

    // Truncate to integer (toward zero)
    // C cast from float to int truncates automatically
    int32_t int_value = (int32_t) a.value.f32;

    // Convert back to float for stack
    float result = (float) int_value;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_TO_INTEGER:
{
    out_script << "\t" << "// ToInteger" << endl
               << "\t" << "actionToInteger(stack, sp);" << endl;
    break;
}
```

**Note**:
- Use `convertFloat()` to handle type conversions (string→number, etc.)
- Cast `(int32_t)` automatically truncates (doesn't round)
- Truncation is toward zero: 3.7→3, -3.7→-3
- Result is stored as float on stack (ActionScript convention)

## Documentation

Create these files as you work:
- `SWFRecomp/tests/to_integer_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x18)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Truncation works correctly (toward zero, not rounding)
- [ ] Positive and negative numbers handled correctly
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- **Truncate**, don't round: 3.9 becomes 3, not 4
- C cast from float to int truncates automatically
- Result is stored as float on stack
- `convertFloat()` handles string→number conversion automatically
- For SWF 4+, this is a basic type conversion opcode

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
