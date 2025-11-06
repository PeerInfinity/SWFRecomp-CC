# AS2 Opcode Implementation Task: MB_CHAR_TO_ASCII

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **MB_CHAR_TO_ASCII**

## Opcode Specification

**Opcode Name**: MB_CHAR_TO_ASCII (Multibyte Character to ASCII)
**Hex Value**: 0x33
**Category**: String Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Converts the first character of a multibyte (UTF-8) string to its Unicode code point value.

**Operation**: Pop string from stack, get Unicode code point of first character, push result as number.

**Expected Behavior**:
- Pop value from stack and convert to string
- Get the first character of the string (handling multibyte UTF-8 sequences)
- Get the Unicode code point of that character
- Push the numeric code point value onto the stack
- If string is empty, behavior may be undefined or return NaN/0

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/mb_char_to_ascii_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic ASCII
```actionscript
trace(mbord("A"));
```
Expected output: `65`

### Test Case 2: Multibyte character (2-byte UTF-8)
```actionscript
trace(mbord("é"));
```
Expected output: `233` (U+00E9)

### Test Case 3: Multibyte character (3-byte UTF-8)
```actionscript
trace(mbord("€"));
```
Expected output: `8364` (U+20AC)

### Test Case 4: CJK character (3-byte UTF-8)
```actionscript
trace(mbord("中"));
```
Expected output: `20013` (U+4E2D)

### Test Case 5: Empty string (edge case)
```actionscript
trace(mbord(""));
```
Expected output: `NaN` or `0`

## Implementation Hints

**Pattern**: This is a string-to-number conversion operation with UTF-8 decoding.

**Reference these similar opcodes**:
- `actionCharToAscii` (0x31) - Similar but for single-byte encoding
- `actionStringLength` in `SWFModernRuntime/src/actionmodern/action.c` (string handling)

**Implementation outline**:
```c
void actionMbCharToAscii(char* stack, u32* sp)
{
    // Convert top of stack to string
    char str_buffer[17];
    convertString(stack, sp, str_buffer);

    // Pop the string value
    POP();

    // Get string pointer
    const char* str = str_buffer;  // Adjust based on actual string location

    // Handle empty string edge case
    if (str == NULL || str[0] == '\0') {
        float result = 0.0f;  // or NaN
        PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
        return;
    }

    // Decode UTF-8 first character
    unsigned int codepoint = 0;
    unsigned char c = (unsigned char)str[0];

    if ((c & 0x80) == 0) {
        // 1-byte sequence (0xxxxxxx)
        codepoint = c;
    } else if ((c & 0xE0) == 0xC0) {
        // 2-byte sequence (110xxxxx 10xxxxxx)
        codepoint = ((c & 0x1F) << 6) | (str[1] & 0x3F);
    } else if ((c & 0xF0) == 0xE0) {
        // 3-byte sequence (1110xxxx 10xxxxxx 10xxxxxx)
        codepoint = ((c & 0x0F) << 12) | ((str[1] & 0x3F) << 6) | (str[2] & 0x3F);
    } else if ((c & 0xF8) == 0xF0) {
        // 4-byte sequence (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)
        codepoint = ((c & 0x07) << 18) | ((str[1] & 0x3F) << 12) |
                    ((str[2] & 0x3F) << 6) | (str[3] & 0x3F);
    }

    // Push result
    float result = (float)codepoint;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Note**:
- UTF-8 decoding is critical for this opcode
- Need to handle 1-byte (ASCII), 2-byte, 3-byte, and 4-byte UTF-8 sequences
- Ensure proper bounds checking when reading multibyte sequences
- Invalid UTF-8 sequences should be handled gracefully

**Important Considerations**:
- Flash AS2 uses UTF-8 encoding for multibyte strings
- Difference from CHAR_TO_ASCII (0x31): This handles full Unicode, not just Latin-1
- Need validation of UTF-8 sequence structure
- Edge cases: empty string, null, invalid UTF-8, truncated sequences

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/mb_char_to_ascii_swf_5/README.md` - Test description and expected output
- Document UTF-8 handling behavior

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Edge cases handled correctly (empty, invalid UTF-8)
- [ ] UTF-8 decoding works for all sequence lengths
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is typically `mbord(str)` or `String.charCodeAt(0)` for multibyte-aware environments.

**Flash Version**: Available in SWF 5+ (multibyte support introduced in SWF 5)

**UTF-8 Reference**: See [UTF-8 Wikipedia](https://en.wikipedia.org/wiki/UTF-8) for encoding details.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
