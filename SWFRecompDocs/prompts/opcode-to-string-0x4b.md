# Opcode Implementation Task: TO_STRING (0x4B)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **TO_STRING**

## Opcode Specification

**Opcode Name**: TO_STRING
**Spec Name**: ActionToString
**Hex Value**: 0x4B
**Category**: Type Conversion / String
**Estimated Complexity**: SIMPLE to MEDIUM (1-2 hours)

**Description**: ActionToString converts the object on the top of the stack into a String, and pushes the string back to the stack. For the Object type, the ActionScript toString() method is invoked to convert the object to the String type for ActionToString.

**Operation**: Pops value, converts to string, pushes result.

**Expected Behavior**:
- Pop a value from stack
- Convert to string based on type:
  - String: return as-is
  - Number: format as decimal string
  - Boolean: "true" or "false"
  - Null: "null"
  - Undefined: "undefined"
  - Object: call toString() (not needed for basic implementation)
- Push the resulting string to the stack
- Available in SWF 5 and later

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_TO_STRING = 0x4B` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionToString(char* stack, u32* sp, char* str_buffer);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/to_string_swf_4/`
7. **Build and Verify** - Use `./scripts/build_test.sh to_string_swf_4 native` and verify output

## Test Cases

### Test Case 1: Number to string
```actionscript
trace(String(42));
```
Expected output: `42`

### Test Case 2: Float to string
```actionscript
trace(String(3.14));
```
Expected output: `3.14` (or `3.140000` depending on formatting)

### Test Case 3: String input (no change)
```actionscript
trace(String("hello"));
```
Expected output: `hello`

### Test Case 4: Zero
```actionscript
trace(String(0));
```
Expected output: `0`

### Test Case 5: Negative number
```actionscript
trace(String(-123.45));
```
Expected output: `-123.45` (or with more decimals)

## Implementation Hints

**Category**: This is a type conversion operation (unary) that may produce strings.

**Pattern**: Unary type conversion with string output
```
peek type → check type → convert to string → pop → push string
```

**Reference these similar opcodes**:
- `convertString` utility function - may already handle this!
- `actionStringAdd` - string handling example
- `actionToNumber` - opposite conversion

**Implementation outline**:
```c
void actionToString(char* stack, u32* sp, char* str_buffer)
{
    // Check if already a string
    ActionVar a;
    peekVar(stack, sp, &a);

    if (a.type == ACTION_STACK_VALUE_STRING)
    {
        // Already a string, nothing to do
        return;
    }

    // Convert to float first (if needed)
    if (a.type != ACTION_STACK_VALUE_F32)
    {
        convertFloat(stack, sp);
        peekVar(stack, sp, &a);
    }

    // Format float as string
    snprintf(str_buffer, 256, "%g", a.value.f32);

    // Pop the number
    POP();

    // Push the string
    PUSH_STR(str_buffer, strlen(str_buffer));
}
```

**Alternative using convertString**:
```c
void actionToString(char* stack, u32* sp, char* str_buffer)
{
    // The convertString() utility may already do this
    // Check action.c for convertString implementation
    convertString(stack, sp, str_buffer);
}
```

**Translation code** (for `SWFRecomp/src/action/action.cpp`):
```cpp
case SWF_ACTION_TO_STRING:
{
    out_script << "\t" << "// ToString" << endl
               << "\t" << "actionToString(stack, sp, str_buffer);" << endl;
    break;
}
```

**Note**:
- Check if `convertString()` utility already exists and does this
- Use `snprintf()` with `%g` format for clean float→string conversion
- `%g` automatically chooses between decimal and scientific notation
- May need str_buffer parameter for string result
- PUSH_STR macro handles pushing strings to stack

## Documentation

Create these files as you work:
- `SWFRecomp/tests/to_string_swf_4/README.md` - Test description and expected output
- Document any implementation notes or issues encountered

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to `action.hpp` with correct hex value (0x4B)
- [ ] Translation case added to `action.cpp`
- [ ] Function declared in `action.h` (with str_buffer parameter)
- [ ] Function implemented in `action.c`
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Test directory contains `config.toml` and test SWF (or generation script)
- [ ] Number to string conversion works
- [ ] String input passes through unchanged
- [ ] Float formatting is reasonable (%g is acceptable)
- [ ] README documentation created

## Additional Notes

- The opcode has no length field (it's a simple stack operation)
- May need `str_buffer` parameter for string result
- Check if `convertString()` utility already exists in action.c
- Use `snprintf()` with `%g` for float formatting
- `%g` removes trailing zeros: 3.000000 → 3
- String is pushed using PUSH_STR macro
- For SWF 5+, but works in our SWF 4 runtime
- Result is string stored on stack

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
