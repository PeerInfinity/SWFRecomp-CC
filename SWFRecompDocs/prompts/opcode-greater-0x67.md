# Opcode Implementation Task: GREATER (0x67)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **GREATER**

## Opcode Specification

**Opcode Name**: GREATER
**Spec Name**: ActionGreater
**Hex Value**: 0x67
**Category**: Comparison
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionGreater is the exact opposite of ActionLess2. Originally there was no ActionGreater, because it can be emulated by reversing the order of argument pushing, then performing an ActionLess followed by an ActionNot. However, this argument reversal resulted in a reversal of the usual order of evaluation of arguments, which in a few cases led to surprises. ActionGreater was added to avoid these argument evaluation order issues.

**Operation**: Pops two values from stack, compares if first > second, pushes boolean result.

**Expected Behavior**:
- Pop value `arg1` from stack
- Pop value `arg2` from stack
- Compare if `arg2 > arg1`
- Push boolean result (1.0 for true, 0.0 for false) onto stack
- Both operands are converted to numbers if needed
- Uses ECMA-262 comparison rules (similar to ActionLess2)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_GREATER = 0x67` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionGreater(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/greater_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh greater_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic greater than (true)
```actionscript
trace(5 > 3);
```
Expected output: `1` (true)

### Test Case 2: Basic greater than (false)
```actionscript
trace(3 > 5);
```
Expected output: `0` (false)

### Test Case 3: Equal values
```actionscript
trace(5 > 5);
```
Expected output: `0` (false, not greater or equal)

### Test Case 4: Floating point comparison
```actionscript
trace(3.5 > 2.5);
```
Expected output: `1` (true)

### Test Case 5: Negative numbers
```actionscript
trace(-1 > -5);
```
Expected output: `1` (true)

## Implementation Hints

**Category**: This is a comparison operation, similar to EQUALS and LESS.

**Pattern**: Binary comparison operation
```
convertFloat → pop → convertFloat → pop → compare → push boolean
```

**Reference these similar opcodes**:
- `actionEquals` in `SWFModernRuntime/src/actionmodern/action.c`
- `actionLess` in `SWFModernRuntime/src/actionmodern/action.c`

**Implementation outline**:
```c
void actionGreater(char* stack, u32* sp)
{
    // Convert and pop first argument
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert and pop second argument
    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Perform comparison: b > a
    float result = (b.value.f32 > a.value.f32) ? 1.0f : 0.0f;

    // Push boolean result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_GREATER:
{
    out_script << "\t" << "// Greater" << endl
               << "\t" << "actionGreater(stack, sp);" << endl;
    break;
}
```

**Note**: This is a simple opcode with no length field, so you don't need to adjust `action_buffer`.

## Documentation

Create these files as you work:
- `SWFRecomp/tests/greater_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x67)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Edge cases handled correctly
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Result must be exactly 1.0 for true or 0.0 for false
- Follow the same pattern as `actionLess` but with reversed comparison
- The ECMA-262 comparison algorithm handles NaN, Infinity, and type conversions

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
