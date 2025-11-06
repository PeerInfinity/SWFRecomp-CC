# AS2 Opcode Implementation Task: MB_ASCII_TO_CHAR

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **MB_ASCII_TO_CHAR**

## Opcode Specification

**Opcode Name**: MB_ASCII_TO_CHAR (Multibyte ASCII to Character)
**Hex Value**: 0x36
**Category**: String Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Converts a Unicode code point value to its corresponding multibyte UTF-8 character string.

**Operation**: Pop number from stack, convert to UTF-8 character, push result as string.

**Expected Behavior**:
- Pop value from stack and convert to number
- Convert number to integer code point
- Encode the code point as a UTF-8 character sequence
- Push the resulting string onto the stack
- Handle out-of-range values (> 0x10FFFF) gracefully

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/mb_ascii_to_char_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic ASCII
```actionscript
trace(mbchr(65));
```
Expected output: `A`

### Test Case 2: 2-byte UTF-8 character
```actionscript
trace(mbchr(233));
```
Expected output: `é` (U+00E9)

### Test Case 3: 3-byte UTF-8 character
```actionscript
trace(mbchr(8364));
```
Expected output: `€` (U+20AC)

### Test Case 4: CJK character
```actionscript
trace(mbchr(20013));
```
Expected output: `中` (U+4E2D)

### Test Case 5: Out of range (edge case)
```actionscript
trace(mbchr(9999999));
```
Expected output: Empty string or error (code point > valid Unicode range)

## Implementation Hints

**Pattern**: This is a number-to-string conversion operation with UTF-8 encoding.

**Reference these similar opcodes**:
- `actionAsciiToChar` (0x32) - Similar but for single-byte encoding
- `actionStringAdd` for string result handling

**Implementation outline**:
```c
void actionMbAsciiToChar(char* stack, u32* sp, char* str_buffer)
{
    // Convert top of stack to number
    convertFloat(stack, sp);

    // Pop the numeric value
    ActionVar a;
    popVar(stack, sp, &a);

    // Get integer code point
    unsigned int codepoint = (unsigned int)a.value.f32;

    // Validate code point range (0 to 0x10FFFF for valid Unicode)
    if (codepoint > 0x10FFFF) {
        // Push empty string or handle error
        str_buffer[0] = '\0';
        PUSH_STR(str_buffer, 0);
        return;
    }

    // Encode as UTF-8
    int len = 0;
    if (codepoint <= 0x7F) {
        // 1-byte sequence
        str_buffer[len++] = (char)codepoint;
    } else if (codepoint <= 0x7FF) {
        // 2-byte sequence
        str_buffer[len++] = (char)(0xC0 | (codepoint >> 6));
        str_buffer[len++] = (char)(0x80 | (codepoint & 0x3F));
    } else if (codepoint <= 0xFFFF) {
        // 3-byte sequence
        str_buffer[len++] = (char)(0xE0 | (codepoint >> 12));
        str_buffer[len++] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
        str_buffer[len++] = (char)(0x80 | (codepoint & 0x3F));
    } else {
        // 4-byte sequence
        str_buffer[len++] = (char)(0xF0 | (codepoint >> 18));
        str_buffer[len++] = (char)(0x80 | ((codepoint >> 12) & 0x3F));
        str_buffer[len++] = (char)(0x80 | ((codepoint >> 6) & 0x3F));
        str_buffer[len++] = (char)(0x80 | (codepoint & 0x3F));
    }
    str_buffer[len] = '\0';

    // Push result string
    PUSH_STR(str_buffer, len);
}
```

**Note**:
- UTF-8 encoding must be correct for different code point ranges
- 1-byte: 0x00 - 0x7F
- 2-byte: 0x80 - 0x7FF
- 3-byte: 0x800 - 0xFFFF
- 4-byte: 0x10000 - 0x10FFFF
- Invalid code points (surrogates 0xD800-0xDFFF, > 0x10FFFF) should be handled

**Important Considerations**:
- Result is a UTF-8 encoded string
- Need str_buffer with enough space (max 5 bytes: 4 for UTF-8 + 1 for null)
- Ensure null termination
- Handle edge cases: negative numbers, out-of-range, NaN

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/mb_ascii_to_char_swf_5/README.md` - Test description and expected output
- Document UTF-8 encoding behavior

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Edge cases handled correctly (out of range, negative)
- [ ] UTF-8 encoding works for all code point ranges
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is typically `mbchr(code)` or `String.fromCharCode(code)` for multibyte-aware environments.

**Flash Version**: Available in SWF 5+ (multibyte support)

**UTF-8 Reference**: See [UTF-8 Wikipedia](https://en.wikipedia.org/wiki/UTF-8) for encoding details.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
