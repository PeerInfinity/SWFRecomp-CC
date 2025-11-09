# AS2 Opcode Implementation Task: ActionMBCharToAscii (CORRECTED)

## ⚠️ IMPORTANT: Incorrect Implementation Exists

**This is a corrected version of the original 0x36 prompt.** The original prompt in `completed/opcode-mb-ascii-to-char-0x36.md` had the operation backwards, and **an incorrect implementation may already exist in the codebase**.

### Before You Begin

**You MUST first check if 0x36 has already been implemented incorrectly:**

1. **Check the enum definition** in `SWFRecomp/include/action/action.hpp`:
   ```bash
   grep "0x36" SWFRecomp/include/action/action.hpp
   ```
   - Current incorrect enum: `SWF_ACTION_MB_ASCII_TO_CHAR = 0x36`
   - Correct enum should be: `SWF_ACTION_MB_CHAR_TO_ASCII = 0x36`

2. **Check if implementation exists** in `SWFModernRuntime/src/actionmodern/action.c`:
   ```bash
   grep -n "actionMbAsciiToChar\|actionMbCharToAscii" SWFModernRuntime/src/actionmodern/action.c
   ```

3. **Check the implementation branch**:
   - Branch: `origin/claude/opcode-mb-ascii-to-char-011CUqjGDDuJtLXjWDS2jnrB`
   - This branch likely contains the backwards implementation

### If Incorrect Implementation Exists

You have two options:

**Option A: Remove and Re-implement (Recommended)**
1. Remove the incorrect enum `SWF_ACTION_MB_ASCII_TO_CHAR` from `action.hpp`
2. Remove the incorrect function from `action.h` and `action.c`
3. Remove the incorrect case from `action.cpp`
4. Follow the 7-step workflow below with the correct implementation
5. The incorrect implementation can be moved to 0x37 if needed

**Option B: Verify and Correct**
1. If the existing implementation actually does char→code conversion (despite wrong naming):
   - Rename the enum to `SWF_ACTION_MB_CHAR_TO_ASCII`
   - Rename the function to `actionMbCharToAscii`
   - Update all references
   - Verify tests match the correct behavior
2. Then implement 0x37 separately with code→char conversion

### Implementation Priority

After reviewing the existing code:
1. **First**: Implement/verify 0x36 correctly (char → code) - THIS PROMPT
2. **Second**: Implement 0x37 correctly (code → char) - use `prompts/pending/opcode-mbasciitochar-0x37.md`

---

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionMBCharToAscii**

## Opcode Specification

**Opcode Name**: ActionMBCharToAscii (Multibyte Character to ASCII)
**Hex Value**: 0x36
**Category**: String Operations / Type Conversion
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Converts the first character of a string to its numeric Unicode code point value.

**Operation**: Pop string from stack, extract first character, convert to code point, push result as number.

**Expected Behavior** (from SWF Spec 19):
- Pops a value off the stack
- Converts the first character of the value to a numeric character code
- If the first character is a double-byte character, a 16-bit value is constructed with:
  - First byte as the high-order byte
  - Second byte as the low-order byte
- For multi-byte UTF-8 characters, decodes to Unicode code point
- Pushes the resulting character code (as a number) to the stack

**Stack Operations**:
```
Before: [... string_value]
After:  [... code_point_number]
```

**Important**: This is the OPPOSITE direction from ActionMBAsciiToChar (0x37):
- **0x36 (MBCharToAscii)**: string → number (this prompt)
- **0x37 (MBAsciiToChar)**: number → string

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_MB_CHAR_TO_ASCII = 0x36` to `SWFRecomp/include/action/action.hpp`
   - **Note**: Check if this is already defined; if so, verify it's mapped to 0x36
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test with character-to-code conversions
6. **Setup Test Directory** - Create `SWFRecomp/tests/mb_char_to_ascii_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic ASCII characters
```actionscript
trace(mbord("A"));
trace(mbord("a"));
trace(mbord("Z"));
```
Expected output:
```
65
97
90
```

### Test Case 2: Extended ASCII / 2-byte characters
```actionscript
trace(mbord("é"));    // U+00E9
trace(mbord("ñ"));    // U+00F1
trace(mbord("©"));    // U+00A9
```
Expected output:
```
233
241
169
```

### Test Case 3: Multi-byte UTF-8 characters (CJK)
```actionscript
trace(mbord("中"));   // U+4E2D
trace(mbord("日"));   // U+65E5
trace(mbord("本"));   // U+672C
```
Expected output:
```
20013
26085
26412
```

### Test Case 4: Special symbols
```actionscript
trace(mbord("€"));    // U+20AC (Euro sign)
trace(mbord("♠"));    // U+2660 (Spade suit)
```
Expected output:
```
8364
9824
```

### Test Case 5: String with multiple characters (only first character)
```actionscript
trace(mbord("Hello"));
trace(mbord("中国"));
```
Expected output:
```
72
20013
```

### Test Case 6: Empty string (edge case)
```actionscript
trace(mbord(""));
```
Expected output:
```
0
(or NaN, depending on ActionScript behavior)
```

## Implementation Hints

**Pattern**: This is a string-to-number conversion with UTF-8 decoding.

**Reference these similar opcodes**:
- `actionCharToAscii` (0x31) - Similar but for single-byte ASCII only
- `actionMbAsciiToChar` (0x37) - Opposite direction (code → char)
- `actionStringLength` for string handling

**Implementation outline**:
```c
void actionMbCharToAscii(char* stack, u32* sp)
{
    // Peek at the string (convert to string if needed)
    convertString(stack, sp, str_buffer);

    // Pop the string value
    ActionVar a;
    popVar(stack, sp, &a);

    // Get the string pointer
    const char* str;
    if (a.type == ACTION_STACK_VALUE_STRING) {
        str = (const char*)a.value.u64;
    } else {
        // Already converted to str_buffer
        str = str_buffer;
    }

    // Check for empty string
    if (str == NULL || str[0] == '\0') {
        float result = 0.0f;  // or NaN
        PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
        return;
    }

    // Decode first UTF-8 character to code point
    unsigned char byte1 = (unsigned char)str[0];
    unsigned int codepoint;

    if (byte1 <= 0x7F) {
        // 1-byte sequence (ASCII)
        codepoint = byte1;
    } else if ((byte1 & 0xE0) == 0xC0) {
        // 2-byte sequence
        unsigned char byte2 = (unsigned char)str[1];
        codepoint = ((byte1 & 0x1F) << 6) | (byte2 & 0x3F);
    } else if ((byte1 & 0xF0) == 0xE0) {
        // 3-byte sequence
        unsigned char byte2 = (unsigned char)str[1];
        unsigned char byte3 = (unsigned char)str[2];
        codepoint = ((byte1 & 0x0F) << 12) |
                    ((byte2 & 0x3F) << 6) |
                    (byte3 & 0x3F);
    } else if ((byte1 & 0xF8) == 0xF0) {
        // 4-byte sequence
        unsigned char byte2 = (unsigned char)str[1];
        unsigned char byte3 = (unsigned char)str[2];
        unsigned char byte4 = (unsigned char)str[3];
        codepoint = ((byte1 & 0x07) << 18) |
                    ((byte2 & 0x3F) << 12) |
                    ((byte3 & 0x3F) << 6) |
                    (byte4 & 0x3F);
    } else {
        // Invalid UTF-8
        codepoint = byte1;  // Fallback to raw byte value
    }

    // Push result as float
    float result = (float)codepoint;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Translation (action.cpp)**:
```cpp
case SWF_ACTION_MB_CHAR_TO_ASCII:
{
    out_script << "\t" << "// MBCharToAscii - convert first UTF-8 char to code point" << endl
               << "\t" << "actionMbCharToAscii(stack, sp, str_buffer);" << endl;
    break;
}
```

**Important Notes**:
- **UTF-8 decoding**: Must properly decode multi-byte UTF-8 sequences
- **First character only**: Only the first character of the string is converted
- **Double-byte construction**: For 2-byte characters, combines high and low bytes
- **SWF 4+ support**: This opcode is available in SWF version 4 and later
- **String buffer**: May need `str_buffer` parameter for type conversion

## Edge Cases

1. **Empty string**: Should return 0 or NaN
2. **Null/undefined**: Convert to string first, then extract code
3. **Invalid UTF-8**: Handle gracefully (return raw byte value or error)
4. **String with multiple characters**: Only convert the first character
5. **Non-string input**: Convert to string first using `convertString`

## UTF-8 Decoding Reference

**UTF-8 Byte Sequences**:
```
1-byte: 0xxxxxxx                           (0x00-0x7F)
2-byte: 110xxxxx 10xxxxxx                  (0x80-0x7FF)
3-byte: 1110xxxx 10xxxxxx 10xxxxxx         (0x800-0xFFFF)
4-byte: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx (0x10000-0x10FFFF)
```

**Decoding Algorithm**:
1. Read first byte
2. Determine sequence length from high bits
3. Read continuation bytes (starting with `10`)
4. Combine bits to form code point
5. Return code point as number

## Testing Strategy

**Unit tests**:
- Test each UTF-8 byte length (1-byte, 2-byte, 3-byte, 4-byte)
- Test boundary values (0x7F, 0x7FF, 0xFFFF, 0x10FFFF)
- Test common characters (ASCII, Latin Extended, CJK, symbols)
- Test multi-character strings (only first character converted)

**Integration tests**:
- Chain with `actionTrace` to verify output
- Use with `actionMbAsciiToChar` for round-trip conversion
- Test with string operations and concatenation

**Round-trip validation**:
```actionscript
// Should produce original character
var code = mbord("中");    // 20013
var char = mbchr(code);    // "中"
trace(char);
```

**Validation**:
```bash
# Build and run test
cd SWFRecomp
./scripts/build_test.sh mb_char_to_ascii_swf_4 native
./tests/mb_char_to_ascii_swf_4/build/native/mb_char_to_ascii_swf_4

# Expected: Numeric code points matching test cases
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Enum added to action.hpp (or verified if already exists)
- [ ] Translation case added to action.cpp
- [ ] Function declared in action.h
- [ ] Runtime implemented in action.c with proper UTF-8 decoding
- [ ] Test produces correct code points for all test cases
- [ ] Handles edge cases (empty string, invalid UTF-8) correctly
- [ ] Only extracts first character from multi-character strings
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && ./all_tests.sh`
- [ ] Documentation created

## Documentation

Create or update:
- `SWFRecomp/tests/mb_char_to_ascii_swf_4/README.md` - Test description and expected output
- Note any UTF-8 decoding issues or platform-specific behavior
- Document difference from the incorrect 0x36 prompt

## Related Opcodes

- **ActionCharToAscii (0x31)**: Single-byte version (ASCII only)
- **ActionMBAsciiToChar (0x37)**: Inverse operation (code point → char)
- **ActionMBStringLength (0x35)**: Character count (not byte count)
- **ActionStringExtract (0x15)**: Extract substring

## Correction Notes

**Original Error**: The original prompt `opcode-mb-ascii-to-char-0x36.md` in the completed directory incorrectly described this opcode as converting code points to characters (which is actually 0x37).

**Correct Behavior**:
- **0x36 = ActionMBCharToAscii**: string character → numeric code point (THIS PROMPT)
- **0x37 = ActionMBAsciiToChar**: numeric code point → string character

If 0x36 has already been implemented using the incorrect prompt, the implementation may need to be:
1. Moved to 0x37 (if 0x37 is not yet implemented)
2. Re-implemented correctly for 0x36

**Verification**: Check if existing implementation at 0x36 converts char→code or code→char to determine if correction is needed.

---

## Appendix: Step-by-Step Removal of Incorrect Implementation

If you need to remove the incorrect implementation before implementing the correct version, follow these steps:

### Step 1: Identify What Needs to be Removed

```bash
# Find the incorrect enum
grep -n "SWF_ACTION_MB_ASCII_TO_CHAR.*0x36" SWFRecomp/include/action/action.hpp

# Find the incorrect function declaration
grep -n "actionMbAsciiToChar" SWFModernRuntime/include/actionmodern/action.h

# Find the incorrect function implementation
grep -n "void actionMbAsciiToChar" SWFModernRuntime/src/actionmodern/action.c

# Find the incorrect translation case
grep -n "SWF_ACTION_MB_ASCII_TO_CHAR" SWFRecomp/src/action/action.cpp
```

### Step 2: Remove from action.hpp

In `SWFRecomp/include/action/action.hpp`, remove or rename:
```cpp
// REMOVE THIS:
SWF_ACTION_MB_ASCII_TO_CHAR = 0x36,

// REPLACE WITH (or add if renaming):
SWF_ACTION_MB_CHAR_TO_ASCII = 0x36,
```

### Step 3: Remove from action.h

In `SWFModernRuntime/include/actionmodern/action.h`, remove:
```c
// REMOVE THIS:
void actionMbAsciiToChar(char* stack, u32* sp, char* str_buffer);

// REPLACE WITH (or add separately):
void actionMbCharToAscii(char* stack, u32* sp);
```

### Step 4: Remove from action.c

In `SWFModernRuntime/src/actionmodern/action.c`, remove the entire function:
```c
// REMOVE THE ENTIRE FUNCTION IMPLEMENTATION
void actionMbAsciiToChar(char* stack, u32* sp, char* str_buffer)
{
    // ... remove all implementation code ...
}
```

**Note**: If the implementation actually does char→code conversion (despite the wrong name), consider saving it to use as reference or moving it to 0x37.

### Step 5: Remove from action.cpp

In `SWFRecomp/src/action/action.cpp`, remove the case:
```cpp
// REMOVE THIS CASE:
case SWF_ACTION_MB_ASCII_TO_CHAR:
{
    out_script << "\t" << "// MB_ASCII_TO_CHAR" << endl
               << "\t" << "actionMbAsciiToChar(stack, sp, str_buffer);" << endl;
    break;
}
```

### Step 6: Check for Test Directory

```bash
# Check if test directory exists
ls -la SWFRecomp/tests/mb_ascii_to_char_swf_*
```

If a test directory exists:
- **Option A**: Rename it to match the correct operation (e.g., `mb_char_to_ascii_swf_4`)
- **Option B**: Keep it for 0x37 if the implementation is actually for code→char
- **Option C**: Remove it and create a new one with correct tests

### Step 7: Rebuild and Verify

```bash
# Rebuild SWFRecomp
cd SWFRecomp/build
make clean
make

# Verify the incorrect references are gone
grep -r "actionMbAsciiToChar" SWFRecomp/ SWFModernRuntime/
# Should return no results (or only comments)

grep -r "SWF_ACTION_MB_ASCII_TO_CHAR.*0x36" SWFRecomp/
# Should return no results
```

### Step 8: Proceed with Correct Implementation

After removal is complete, follow the 7-step workflow in this document to implement the correct version.

### Alternative: Rename Instead of Remove

If you determine the implementation is actually correct (just misnamed), you can rename instead:

```bash
# Use sed to rename throughout the codebase
# BE CAREFUL: Review changes before applying

# Rename enum
sed -i 's/SWF_ACTION_MB_ASCII_TO_CHAR = 0x36/SWF_ACTION_MB_CHAR_TO_ASCII = 0x36/' \
    SWFRecomp/include/action/action.hpp

# Rename function
sed -i 's/actionMbAsciiToChar/actionMbCharToAscii/g' \
    SWFModernRuntime/include/actionmodern/action.h \
    SWFModernRuntime/src/actionmodern/action.c \
    SWFRecomp/src/action/action.cpp
```

Then verify the implementation logic matches char→code conversion.

---

**Estimated Time**: 2-4 hours (implementation) + 1 hour (removal/correction if needed)
**Category**: String Operations / Type Conversion
**Complexity**: MEDIUM
**SWF Version**: 4+
**Status**: CORRECTED PROMPT
