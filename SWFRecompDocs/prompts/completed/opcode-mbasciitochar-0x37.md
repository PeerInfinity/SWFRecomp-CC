# AS2 Opcode Implementation Task: ActionMBAsciiToChar

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionMBAsciiToChar**

## Opcode Specification

**Opcode Name**: ActionMBAsciiToChar
**Hex Value**: 0x37
**Category**: String Operations / Type Conversion
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Converts a numeric code point to its corresponding multibyte character string (UTF-8).

**Operation**: Pop number from stack, convert to UTF-8 character, push result as string.

**Expected Behavior** (from SWF Spec 19):
- Pops a value off the stack
- Converts the value from a number to the corresponding character
- If the character is a 16-bit value (>= 256), a double-byte character is constructed with:
  - First byte containing the high-order byte
  - Second byte containing the low-order byte
- Pushes the resulting character string to the stack

**Stack Operations**:
```
Before: [... codepoint_number]
After:  [... character_string]
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_MB_ASCII_TO_CHAR = 0x37` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test with code point conversions
6. **Setup Test Directory** - Create `SWFRecomp/tests/mb_ascii_to_char_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic ASCII character
```actionscript
trace(mbchr(65));
trace(mbchr(97));
```
Expected output:
```
A
a
```

### Test Case 2: 2-byte character (Latin Extended)
```actionscript
trace(mbchr(233));    // é (U+00E9)
trace(mbchr(241));    // ñ (U+00F1)
```
Expected output:
```
é
ñ
```

### Test Case 3: 3-byte UTF-8 character (CJK)
```actionscript
trace(mbchr(20013));  // 中 (U+4E2D)
trace(mbchr(26085));  // 日 (U+65E5)
```
Expected output:
```
中
日
```

### Test Case 4: Special symbol
```actionscript
trace(mbchr(8364));   // € (U+20AC)
```
Expected output:
```
€
```

### Test Case 5: Out of range (edge case)
```actionscript
trace(mbchr(-1));
trace(mbchr(0));
trace(mbchr(9999999));
```
Expected output:
```
(empty or error for -1)
(null character or empty for 0)
(empty or error for out-of-range)
```

## Implementation Hints

**Pattern**: This is a number-to-string conversion with UTF-8 encoding.

**Reference these similar opcodes**:
- `actionAsciiToChar` (0x32) - Similar but for single-byte ASCII only
- `actionMbCharToAscii` (0x36) - Opposite direction (char → code)
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
    int codepoint = (int)a.value.f32;

    // Validate code point range
    if (codepoint < 0 || codepoint > 0x10FFFF) {
        // Push empty string for invalid code points
        str_buffer[0] = '\0';
        PUSH_STR(str_buffer, 0);
        return;
    }

    // Encode as UTF-8
    int len = 0;
    if (codepoint <= 0x7F) {
        // 1-byte sequence (ASCII)
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
        // 4-byte sequence (for code points > 0xFFFF)
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

**Translation (action.cpp)**:
```cpp
case SWF_ACTION_MB_ASCII_TO_CHAR:
{
    out_script << "\t" << "// MBAsciiToChar - convert code point to UTF-8 char" << endl
               << "\t" << "actionMbAsciiToChar(stack, sp, str_buffer);" << endl;
    break;
}
```

**Important Notes**:
- **UTF-8 encoding**: Must properly encode multi-byte characters
- **SWF 4+ support**: This opcode is available in SWF version 4 and later
- **String buffer**: Requires `str_buffer` parameter for result string
- **Error handling**: Invalid code points should produce empty strings
- **Unicode range**: Valid Unicode range is 0x0000 to 0x10FFFF

## Edge Cases

1. **Negative values**: Should handle gracefully (empty string or error)
2. **Zero**: Null character - may need special handling
3. **Out of range** (> 0x10FFFF): Push empty string
4. **Surrogate pairs**: Code points in range 0xD800-0xDFFF are invalid in UTF-8
5. **Non-integer values**: Convert float to integer (truncate)

## Testing Strategy

**Unit tests**:
- Test each UTF-8 byte length (1-byte, 2-byte, 3-byte, 4-byte)
- Test boundary values (0x7F, 0x7FF, 0xFFFF, 0x10FFFF)
- Test common characters (ASCII, Latin, CJK, symbols)

**Integration tests**:
- Chain with `actionTrace` to verify output
- Use with `actionMbCharToAscii` for round-trip conversion
- Test with string concatenation operations

**Validation**:
```bash
# Build and run test
cd SWFRecomp
./scripts/build_test.sh mb_ascii_to_char_swf_4 native
./tests/mb_ascii_to_char_swf_4/build/native/mb_ascii_to_char_swf_4

# Expected: Character outputs matching test cases
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to action.hpp
- [ ] Translation case added to action.cpp
- [ ] Function declared in action.h
- [ ] Runtime implemented in action.c with proper UTF-8 encoding
- [ ] Test produces correct UTF-8 characters for all test cases
- [ ] Handles edge cases (negative, zero, out-of-range) correctly
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && ./all_tests.sh`
- [ ] Documentation created

## Documentation

Create or update:
- `SWFRecomp/tests/mb_ascii_to_char_swf_4/README.md` - Test description and expected output
- Note any UTF-8 encoding issues or platform-specific behavior

## Related Opcodes

- **ActionAsciiToChar (0x32)**: Single-byte version (ASCII only)
- **ActionMBCharToAscii (0x36)**: Inverse operation (char → code point)
- **ActionMBStringLength (0x35)**: Character count (not byte count)
- **ActionStringAdd (0x21)**: String concatenation

---

**Estimated Time**: 2-4 hours
**Category**: String Operations / Type Conversion
**Complexity**: MEDIUM
**SWF Version**: 4+
