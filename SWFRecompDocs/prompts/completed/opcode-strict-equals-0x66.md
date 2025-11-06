# Opcode Implementation Task: STRICT_EQUALS (0x66)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **STRICT_EQUALS**

## Opcode Specification

**Opcode Name**: STRICT_EQUALS
**Spec Name**: ActionStrictEquals
**Hex Value**: 0x66
**Category**: Comparison
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionStrictEquals is similar to ActionEquals2, but the two arguments must be of the same type in order to be considered equal. Implements the '===' operator from the ActionScript language.

**Operation**: Pops two values from stack, compares if they are strictly equal (same type and value), pushes boolean result.

**Expected Behavior**:
- Pop value `arg1` from stack
- Pop value `arg2` from stack
- Compare if `arg2 === arg1` (strict equality)
- Push boolean result (1.0 for true, 0.0 for false) onto stack
- Both TYPE and VALUE must match for equality
- No type coercion is performed (unlike regular equals)
- Available in SWF 6 and later

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_STRICT_EQUALS = 0x66` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionStrictEquals(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/strict_equals_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh strict_equals_swf_4 native` and verify output

## Test Cases

### Test Case 1: Strict equality with same type and value (true)
```actionscript
trace(5 === 5);
```
Expected output: `1` (true)

### Test Case 2: Strict equality with same value but potentially different representation
```actionscript
trace(5.0 === 5);
```
Expected output: `1` (true, both are numbers)

### Test Case 3: Type mismatch (number vs string)
```actionscript
trace(5 === "5");
```
Expected output: `0` (false, different types - NOTE: may require SWF 6+ features)

### Test Case 4: Different values
```actionscript
trace(5 === 3);
```
Expected output: `0` (false)

### Test Case 5: String strict equality
```actionscript
trace("hello" === "hello");
```
Expected output: `1` (true)

## Implementation Hints

**Category**: This is a comparison operation with type checking, similar to EQUALS but stricter.

**Pattern**: Binary comparison operation with type checking
```
pop → pop → compare type AND value → push boolean
```

**Reference these similar opcodes**:
- `actionEquals` in `SWFModernRuntime/src/actionmodern/action.c`
- `actionStringEquals` in `SWFModernRuntime/src/actionmodern/action.c`

**Implementation outline**:
```c
void actionStrictEquals(char* stack, u32* sp)
{
    // Pop first argument
    ActionVar a;
    popVar(stack, sp, &a);

    // Pop second argument
    ActionVar b;
    popVar(stack, sp, &b);

    float result = 0.0f;

    // First check: types must match
    if (a.type == b.type)
    {
        // Second check: values must match
        switch (a.type)
        {
            case ACTION_STACK_VALUE_F32:
                result = (a.value.f32 == b.value.f32) ? 1.0f : 0.0f;
                break;

            case ACTION_STACK_VALUE_STRING:
            {
                const char* str_a = (const char*) a.value.u64;
                const char* str_b = (const char*) b.value.u64;
                result = (strcmp(str_a, str_b) == 0) ? 1.0f : 0.0f;
                break;
            }

            // Add other types as needed (OBJECT, etc.)
            default:
                // For other types, compare raw values
                result = (a.value.u64 == b.value.u64) ? 1.0f : 0.0f;
                break;
        }
    }
    // else: different types, result remains 0.0f (false)

    // Push boolean result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_STRICT_EQUALS:
{
    out_script << "\t" << "// StrictEquals" << endl
               << "\t" << "actionStrictEquals(stack, sp);" << endl;
    break;
}
```

**Note**:
- No type conversion is performed (unlike actionEquals)
- Must check BOTH type and value
- Use ActionVar.type to check types
- Different comparison logic for different types (float, string, etc.)

## Documentation

Create these files as you work:
- `SWFRecomp/tests/strict_equals_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x66)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Type checking works correctly (rejects type mismatches)
- [ ] Value checking works correctly (compares values when types match)
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Result must be exactly 1.0 for true or 0.0 for false
- Unlike regular equals, NO type coercion is performed
- Type field must match AND value field must match
- For SWF 6+ feature, but should work in our SWF 4 runtime (just compare what we have)
- Handle at least F32 and STRING types in the switch statement

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
