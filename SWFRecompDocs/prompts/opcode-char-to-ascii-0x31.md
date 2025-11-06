# AS2 Opcode Implementation Task: CHAR_TO_ASCII

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **CHAR_TO_ASCII**

## Opcode Specification

**Opcode Name**: CHAR_TO_ASCII
**Hex Value**: 0x31
**Category**: String Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Converts the first character of a string to its ASCII code value.

**Operation**: Pop string from stack, get ASCII code of first character, push result as number.

**Expected Behavior**:
- Pop value from stack and convert to string
- Get the first character of the string
- Get the ASCII code (Unicode code point) of that character
- Push the numeric code value onto the stack
- If string is empty, behavior may be undefined or return NaN/0 (check Flash specification)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/char_to_ascii_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Single character
```actionscript
trace(ord("A"));
```
Expected output: `65`

### Test Case 2: Multiple characters (only first counts)
```actionscript
trace(ord("Hello"));
```
Expected output: `72`

### Test Case 3: Special character
```actionscript
trace(ord("!"));
```
Expected output: `33`

### Test Case 4: Empty string (edge case)
```actionscript
trace(ord(""));
```
Expected output: `NaN` or `0` (verify against Flash specification)

### Test Case 5: Unicode character
```actionscript
trace(ord("é"));
```
Expected output: `233` (code point for é)

## Implementation Hints

**Pattern**: This is a string-to-number conversion operation.

**Reference these similar opcodes**:
- `actionStringLength` in `SWFModernRuntime/src/actionmodern/action.c` (string input handling)
- `convertString` utility (for type conversion to string)

**Implementation outline**:
```c
void actionCharToAscii(char* stack, u32* sp)
{
    // Convert top of stack to string
    char str_buffer[17];
    convertString(stack, sp, str_buffer);

    // Pop the string value
    POP();

    // Get first character
    const char* str = (const char*) str_buffer;  // Adjust based on actual string location

    // Handle empty string edge case
    if (str == NULL || str[0] == '\0') {
        // Push NaN or 0 depending on spec
        float result = 0.0f;  // or NaN
        PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
        return;
    }

    // Get ASCII/Unicode code of first character
    float code = (float)(unsigned char)str[0];

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &code));
}
```

**Note**:
- Use `(unsigned char)` cast to ensure values 128-255 are handled correctly
- For multibyte UTF-8 sequences, you may need special handling (but CHAR_TO_ASCII typically uses single-byte encoding)
- Check if Flash AS2 uses UTF-8 or Latin-1 encoding for character codes

**Important Considerations**:
- String may be on stack as a pointer or in constant pool
- Need to handle string lifetime correctly
- Edge cases: empty string, null, non-string types

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/char_to_ascii_swf_4/README.md` - Test description and expected output
- Document any Flash-specific behavior you discover

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Edge cases handled correctly (empty string, Unicode)
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is typically `ord(str)` or accessed via `String.charCodeAt(0)`.

**Flash Version**: Available in SWF 4+

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
