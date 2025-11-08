# AS2 Opcode Implementation Task: MB_STRING_EXTRACT

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **MB_STRING_EXTRACT**

## Opcode Specification

**Opcode Name**: MB_STRING_EXTRACT (Multibyte String Extract)
**Hex Value**: 0x35
**Category**: String Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Extracts a substring from a string, correctly handling multibyte UTF-8 characters. This is the multibyte-aware version of STRING_EXTRACT.

**Operation**: Pop count, pop index, pop string, push substring (index and count are in characters, not bytes).

**Expected Behavior**:
- Pop `count` (number of characters to extract) from stack
- Pop `index` (starting character position, 0-based) from stack
- Pop `string` from stack
- Extract `count` characters starting at character position `index`
- Push the extracted substring onto the stack
- Index and count are treated as character positions (not byte positions)
- If index or count are not integers, return empty string
- If index is out of bounds, return empty string
- If count extends beyond string end, return characters from index to end

## Your Task

Implement this opcode following the 8-step workflow (includes validation files):

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/mb_string_extract_swf_5/` with test_info.json and validate.py
7. **Build and Verify** - Compile and verify output matches expected
8. **Run Test Suite** - Verify with `./all_tests.sh`

## Test Cases

### Test Case 1: Basic ASCII extraction
```actionscript
trace(mbsubstring("Hello World", 0, 5));
```
Expected output: `Hello`

### Test Case 2: Extract from middle
```actionscript
trace(mbsubstring("Hello World", 6, 5));
```
Expected output: `World`

### Test Case 3: Multibyte characters (UTF-8)
```actionscript
trace(mbsubstring("café", 0, 3));
```
Expected output: `caf` (3 characters, not 3 bytes)

### Test Case 4: CJK characters
```actionscript
trace(mbsubstring("你好世界", 0, 2));
```
Expected output: `你好` (2 characters, each is 3 bytes in UTF-8)

### Test Case 5: Mixed ASCII and multibyte
```actionscript
trace(mbsubstring("Hello世界", 5, 2));
```
Expected output: `世界`

### Test Case 6: Count extends beyond end
```actionscript
trace(mbsubstring("Hello", 2, 100));
```
Expected output: `llo` (from index to end)

### Test Case 7: Index out of bounds
```actionscript
trace(mbsubstring("Hello", 10, 5));
```
Expected output: `` (empty string)

### Test Case 8: Zero count
```actionscript
trace(mbsubstring("Hello", 2, 0));
```
Expected output: `` (empty string)

## Implementation Hints

**Pattern**: This is a string manipulation operation with UTF-8 character awareness.

**Reference these similar opcodes**:
- `actionStringExtract` (0x15) - Similar but uses byte positions, not character positions
- `actionMbStringLength` (0x31) - UTF-8 character counting reference

**Implementation outline**:
```c
void actionMbStringExtract(char* stack, u32* sp, char* str_buffer)
{
    // Pop count (number of characters to extract)
    convertFloat(stack, sp);
    ActionVar count_var;
    popVar(stack, sp, &count_var);
    int count = (int)count_var.value.f32;

    // Pop index (starting character position)
    convertFloat(stack, sp);
    ActionVar index_var;
    popVar(stack, sp, &index_var);
    int index = (int)index_var.value.f32;

    // Pop string
    char input_buffer[17];
    convertString(stack, sp, input_buffer);
    POP();

    // If index or count are invalid, return empty string
    if (index < 0 || count < 0) {
        str_buffer[0] = '\0';
        PUSH_STR(str_buffer, 0);
        return;
    }

    // Navigate to starting character position (UTF-8 aware)
    const unsigned char* str = (const unsigned char*)input_buffer;
    int current_char = 0;

    // Skip to index'th character
    while (*str != '\0' && current_char < index) {
        // Advance by one UTF-8 character
        if ((*str & 0x80) == 0) {
            str += 1;  // 1-byte character
        } else if ((*str & 0xE0) == 0xC0) {
            str += 2;  // 2-byte character
        } else if ((*str & 0xF0) == 0xE0) {
            str += 3;  // 3-byte character
        } else if ((*str & 0xF8) == 0xF0) {
            str += 4;  // 4-byte character
        } else {
            str += 1;  // Invalid, skip one byte
        }
        current_char++;
    }

    // If we reached end of string before index, return empty
    if (*str == '\0') {
        str_buffer[0] = '\0';
        PUSH_STR(str_buffer, 0);
        return;
    }

    // Extract count characters
    const unsigned char* start = str;
    current_char = 0;

    while (*str != '\0' && current_char < count) {
        // Advance by one UTF-8 character
        if ((*str & 0x80) == 0) {
            str += 1;
        } else if ((*str & 0xE0) == 0xC0) {
            str += 2;
        } else if ((*str & 0xF0) == 0xE0) {
            str += 3;
        } else if ((*str & 0xF8) == 0xF0) {
            str += 4;
        } else {
            str += 1;
        }
        current_char++;
    }

    // Copy substring to buffer
    int length = str - start;
    if (length > 16) length = 16;  // Buffer size limit
    memcpy(str_buffer, start, length);
    str_buffer[length] = '\0';

    // Push result
    PUSH_STR(str_buffer, length);
}
```

**Note**:
- Must use character positions, not byte positions
- UTF-8 character boundaries determined by first byte:
  - 0xxxxxxx: 1-byte character
  - 110xxxxx: 2-byte character
  - 1110xxxx: 3-byte character
  - 11110xxx: 4-byte character
- Must handle multibyte characters correctly
- Need to include `<string.h>` for `memcpy()`

**Important Considerations**:
- Difference from STRING_EXTRACT (0x15): That uses byte positions, this uses character positions
- Must navigate UTF-8 sequences correctly
- Must not split multibyte characters
- Edge cases: negative index/count, out of bounds, empty string
- Buffer size limitation (16 bytes) may truncate long multibyte strings

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/mb_string_extract_swf_5/test_info.json` - Test metadata with opcode info
- `SWFRecomp/tests/mb_string_extract_swf_5/validate.py` - Validation script for test output
- Document the difference between byte-based and character-based extraction

## Success Criteria

Your implementation is complete when:
- [ ] All 8 steps completed (including validation files)
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && ./all_tests.sh`
- [ ] Edge cases handled correctly (out of bounds, zero count, negative values)
- [ ] Substring extraction works correctly for all UTF-8 character sizes
- [ ] Validation script (validate.py) passes
- [ ] Documentation created

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is typically `mbsubstring(str, index, count)` or `String.substr()` in multibyte-aware mode.

**Flash Version**: Available in SWF 5+ (multibyte support)

**Comparison**:
- `STRING_EXTRACT` (0x15): Uses byte positions (e.g., extracting from "café" uses byte offsets)
- `MB_STRING_EXTRACT` (0x35): Uses character positions (e.g., extracting from "café" uses character offsets)

**Stack Order** (important for testing):
When creating test SWFs manually, remember the stack order:
1. Push string first
2. Push index second
3. Push count third
4. Execute MB_STRING_EXTRACT

The opcode pops in reverse order: count, index, string.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
