# Opcode Implementation Task: STRING_GREATER (0x68)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **STRING_GREATER**

## Opcode Specification

**Opcode Name**: STRING_GREATER
**Spec Name**: ActionStringGreater
**Hex Value**: 0x68
**Category**: String / Comparison
**Estimated Complexity**: SIMPLE (1-2 hours)

**Description**: ActionStringGreater is the exact opposite of ActionStringLess. This action code was added for the same reasons as ActionGreater - to avoid argument evaluation order issues when emulating with ActionStringLess + ActionNot.

**Operation**: Pops two strings from stack, compares if first > second (lexicographically), pushes boolean result.

**Expected Behavior**:
- Pop value `arg1` from stack
- Pop value `arg2` from stack
- Compare if `arg2 > arg1` using byte-by-byte string comparison
- Push boolean result (1.0 for true, 0.0 for false) onto stack
- Uses lexicographic (dictionary) ordering, not numeric comparison
- Case-sensitive comparison

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_STRING_GREATER = 0x68` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionStringGreater(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/string_greater_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh string_greater_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic string comparison (true)
```actionscript
trace("zebra" > "apple");
```
Expected output: `1` (true, "zebra" comes after "apple")

### Test Case 2: Basic string comparison (false)
```actionscript
trace("apple" > "zebra");
```
Expected output: `0` (false)

### Test Case 3: Equal strings
```actionscript
trace("hello" > "hello");
```
Expected output: `0` (false, not greater)

### Test Case 4: Case sensitivity
```actionscript
trace("Z" > "a");
```
Expected output: `0` (false, uppercase 'Z' = 90, lowercase 'a' = 97)

### Test Case 5: Prefix comparison
```actionscript
trace("hello world" > "hello");
```
Expected output: `1` (true, longer string is greater when prefix matches)

## Implementation Hints

**Category**: This is a string comparison operation, similar to STRING_EQUALS.

**Pattern**: Binary string comparison operation
```
peek string → pop → peek string → pop → strcmp → push boolean
```

**Reference these similar opcodes**:
- `actionStringEquals` in `SWFModernRuntime/src/actionmodern/action.c`
- `actionGreater` (numeric version)

**Implementation outline**:
```c
void actionStringGreater(char* stack, u32* sp)
{
    // Get first string (arg1)
    ActionVar a;
    peekVar(stack, sp, &a);
    const char* str_a = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // Get second string (arg2)
    ActionVar b;
    peekVar(stack, sp, &b);
    const char* str_b = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // Compare: b > a (using strcmp)
    // strcmp returns positive if str_b > str_a
    float result = (strcmp(str_b, str_a) > 0) ? 1.0f : 0.0f;

    // Push boolean result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_STRING_GREATER:
{
    out_script << "\t" << "// StringGreater" << endl
               << "\t" << "actionStringGreater(stack, sp);" << endl;
    break;
}
```

**Note**:
- Uses `strcmp()` from `<string.h>` for byte-by-byte comparison
- strcmp returns:
  - Positive value if str1 > str2
  - Negative value if str1 < str2
  - 0 if str1 == str2
- This is lexicographic ordering, NOT numeric

## Documentation

Create these files as you work:
- `SWFRecomp/tests/string_greater_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x68)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h`
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Edge cases handled correctly (case sensitivity, equal strings, prefixes)
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- Result must be exactly 1.0 for true or 0.0 for false
- Use standard C `strcmp()` for comparison
- Case-sensitive comparison (ASCII byte values)
- This compares strings lexicographically, not numerically ("10" < "2" in string comparison)

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
