# Opcode Implementation Task: LESS2 (0x48)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **LESS2**

## Opcode Specification

**Opcode Name**: LESS2
**Spec Name**: ActionLess2
**Hex Value**: 0x48
**Category**: Comparison
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionLess2 calculates whether arg1 is less than arg2 and pushes a Boolean return value to the stack. This action is similar to ActionLess (0x0F), but performs the comparison differently according to the data types of the arguments. The abstract relational comparison algorithm in ECMA-262 Section 11.8.5 is used.

**Operation**: Pops two values from stack, compares if first < second (using ECMA-262 rules), pushes boolean result.

**Expected Behavior**:
- Pop value `arg1` from stack
- Pop value `arg2` from stack
- Compare if `arg2 < arg1` using ECMA-262 comparison rules
- Push boolean result (1.0 for true, 0.0 for false) onto stack
- Both operands are converted according to ECMA-262 type coercion rules
- Handles various data types (numbers, strings, objects, undefined, null)

**Note**: This is categorized as "GREATER" in some docs because when you pop in the order (arg1, arg2), you're effectively computing arg2 < arg1, which is equivalent to arg1 > arg2. However, the official SWF spec calls this ActionLess2.

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_LESS2 = 0x48` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionLess2(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/less2_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh less2_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic less than (true)
```actionscript
trace(3 < 5);
```
Expected output: `1` (true)

### Test Case 2: Basic less than (false)
```actionscript
trace(5 < 3);
```
Expected output: `0` (false)

### Test Case 3: Equal values
```actionscript
trace(5 < 5);
```
Expected output: `0` (false, not less than)

### Test Case 4: Floating point comparison
```actionscript
trace(2.5 < 3.5);
```
Expected output: `1` (true)

### Test Case 5: Negative numbers
```actionscript
trace(-5 < -1);
```
Expected output: `1` (true)

## Implementation Hints

**Category**: This is a comparison operation using ECMA-262 rules, an improved version of ActionLess (0x0F).

**Pattern**: Binary comparison operation
```
convertFloat → pop → convertFloat → pop → compare → push boolean
```

**Reference these similar opcodes**:
- `actionLess` (0x0F) in `SWFModernRuntime/src/actionmodern/action.c`
- `actionEquals` in `SWFModernRuntime/src/actionmodern/action.c`

**Implementation outline**:
```c
void actionLess2(char* stack, u32* sp)
{
    // Convert and pop first argument
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert and pop second argument
    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Perform comparison: b < a
    // (Remember stack order: push arg2, push arg1, so pop gets arg1 first)
    float result = (b.value.f32 < a.value.f32) ? 1.0f : 0.0f;

    // Push boolean result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_LESS2:
{
    out_script << "\t" << "// Less2" << endl
               << "\t" << "actionLess2(stack, sp);" << endl;
    break;
}
```

**Note**:
- This is similar to ActionLess (0x0F) but uses ECMA-262 comparison rules
- For simple numeric comparisons, the behavior is the same as ActionLess
- The difference matters for edge cases like comparing different types
- Since we're converting to float anyway, this is a straightforward comparison

## Documentation

Create these files as you work:
- `SWFRecomp/tests/less2_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x48)
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
- Very similar to ActionLess (0x0F) - use ECMA-262 comparison algorithm
- The ECMA-262 algorithm handles NaN, Infinity, and special values
- For our numeric-focused runtime, this is essentially the same as ActionLess

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
