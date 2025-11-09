# AS2 Opcode Implementation Task: MB_STRING_LENGTH

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **MB_STRING_LENGTH**

## Opcode Specification

**Opcode Name**: MB_STRING_LENGTH (Multibyte String Length)
**Hex Value**: 0x31
**Category**: String Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Returns the length of a string in characters (not bytes), correctly handling multibyte UTF-8 sequences.

**Operation**: Pop string from stack, count UTF-8 characters, push result as number.

**Expected Behavior**:
- Pop value from stack and convert to string
- Count the number of UTF-8 characters (not bytes)
- Each UTF-8 sequence (1-4 bytes) counts as one character
- Push the character count onto the stack
- Empty string returns 0

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/mb_string_length_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic ASCII string
```actionscript
trace(mblength("Hello"));
```
Expected output: `5`

### Test Case 2: String with 2-byte UTF-8 characters
```actionscript
trace(mblength("café"));
```
Expected output: `4` (not 5, because 'é' is one character)

### Test Case 3: String with 3-byte UTF-8 characters
```actionscript
trace(mblength("€100"));
```
Expected output: `4` (€ is one character, not 3 bytes)

### Test Case 4: CJK characters
```actionscript
trace(mblength("中文"));
```
Expected output: `2`

### Test Case 5: Empty string
```actionscript
trace(mblength(""));
```
Expected output: `0`

### Test Case 6: Mixed ASCII and multibyte
```actionscript
trace(mblength("Hello世界"));
```
Expected output: `7` (5 ASCII + 2 CJK)

## Implementation Hints

**Pattern**: This is a string property query operation with UTF-8 awareness.

**Reference these similar opcodes**:
- `actionStringLength` (0x14) - Similar but counts bytes, not characters
- `actionMbCharToAscii` (0x33) - UTF-8 decoding reference

**Implementation outline**:
```c
void actionMbStringLength(char* stack, u32* sp)
{
    // Convert top of stack to string
    char str_buffer[17];
    convertString(stack, sp, str_buffer);

    // Pop the string value
    POP();

    // Get string pointer
    const unsigned char* str = (const unsigned char*)str_buffer;

    // Count UTF-8 characters
    int count = 0;
    while (*str != '\0') {
        // Check UTF-8 sequence length
        if ((*str & 0x80) == 0) {
            // 1-byte sequence (0xxxxxxx)
            str += 1;
        } else if ((*str & 0xE0) == 0xC0) {
            // 2-byte sequence (110xxxxx)
            str += 2;
        } else if ((*str & 0xF0) == 0xE0) {
            // 3-byte sequence (1110xxxx)
            str += 3;
        } else if ((*str & 0xF8) == 0xF0) {
            // 4-byte sequence (11110xxx)
            str += 4;
        } else {
            // Invalid UTF-8, skip one byte
            str += 1;
        }
        count++;
    }

    // Push result
    float result = (float)count;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Note**:
- Must distinguish between byte length and character length
- UTF-8 character boundaries are determined by the first byte:
  - 0xxxxxxx: 1-byte character
  - 110xxxxx: 2-byte character
  - 1110xxxx: 3-byte character
  - 11110xxx: 4-byte character
- Invalid UTF-8 sequences should be handled gracefully

**Important Considerations**:
- Difference from STRING_LENGTH (0x14): That counts bytes, this counts characters
- Need to traverse the entire string
- Must not count continuation bytes (10xxxxxx) as separate characters
- Edge cases: empty string, null, invalid UTF-8

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/mb_string_length_swf_5/README.md` - Test description and expected output
- Document the difference between byte length and character length

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Edge cases handled correctly (empty string, invalid UTF-8)
- [ ] Character counting works correctly for all UTF-8 sequence lengths
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is typically `mblength(str)` or `String.length` property in multibyte-aware mode.

**Flash Version**: Available in SWF 5+ (multibyte support)

**Comparison**:
- `STRING_LENGTH` (0x14): Counts bytes (e.g., "café" → 5)
- `MB_STRING_LENGTH` (0x35): Counts characters (e.g., "café" → 4)

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
