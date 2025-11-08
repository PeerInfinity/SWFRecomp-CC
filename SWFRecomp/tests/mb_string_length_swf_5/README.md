# MB_STRING_LENGTH Opcode Test (0x31)

## Overview

This test validates the implementation of the `MB_STRING_LENGTH` (Multibyte String Length) opcode for ActionScript 2.

**Opcode**: 0x31
**Category**: String Operations
**SWF Version**: 5+ (requires multibyte support)

## Description

The `MB_STRING_LENGTH` opcode returns the length of a string in **characters** (not bytes), correctly handling multibyte UTF-8 sequences. This is different from the `STRING_LENGTH` opcode (0x14), which counts bytes.

## Operation

1. Pop a value from the stack
2. Convert it to a string (if necessary)
3. Count the number of UTF-8 characters (each 1-4 byte sequence counts as one character)
4. Push the character count as a number onto the stack

## UTF-8 Character Handling

UTF-8 characters can be 1-4 bytes long:
- **1-byte**: ASCII characters (0xxxxxxx) - e.g., "Hello"
- **2-byte**: Latin extended, Cyrillic, etc. (110xxxxx 10xxxxxx) - e.g., "café"
- **3-byte**: Most other scripts including CJK (1110xxxx 10xxxxxx 10xxxxxx) - e.g., "中文", "€"
- **4-byte**: Emoji and rare characters (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)

## Test Cases

This test includes 6 test cases covering various UTF-8 scenarios:

### Test Case 1: Basic ASCII String
```actionscript
mblength("Hello")
```
**Expected Output**: `5`
**Explanation**: 5 single-byte ASCII characters

### Test Case 2: String with 2-byte UTF-8 Characters
```actionscript
mblength("café")
```
**Expected Output**: `4`
**Explanation**: "c", "a", "f", "é" (é is 2 bytes but counts as 1 character)
**Note**: `STRING_LENGTH` would return `5` (byte count)

### Test Case 3: String with 3-byte UTF-8 Characters
```actionscript
mblength("€100")
```
**Expected Output**: `4`
**Explanation**: "€" (3 bytes), "1", "0", "0" = 4 characters
**Note**: `STRING_LENGTH` would return `6` (byte count)

### Test Case 4: CJK Characters
```actionscript
mblength("中文")
```
**Expected Output**: `2`
**Explanation**: Two Chinese characters (each is 3 bytes in UTF-8)
**Note**: `STRING_LENGTH` would return `6` (byte count)

### Test Case 5: Empty String
```actionscript
mblength("")
```
**Expected Output**: `0`
**Explanation**: Empty string has no characters

### Test Case 6: Mixed ASCII and Multibyte
```actionscript
mblength("Hello世界")
```
**Expected Output**: `7`
**Explanation**: "Hello" (5 ASCII) + "世界" (2 CJK) = 7 characters
**Note**: `STRING_LENGTH` would return `11` (5 + 6 bytes)

## Expected Test Output

```
5
4
4
2
0
7
```

## Implementation Details

### Files Modified

1. **SWFRecomp/include/action/action.hpp**
   - Added `SWF_ACTION_MB_STRING_LENGTH = 0x31` to enum

2. **SWFRecomp/src/action/action.cpp**
   - Added translation case for MB_STRING_LENGTH opcode

3. **SWFModernRuntime/include/actionmodern/action.h**
   - Added `actionMbStringLength()` function declaration

4. **SWFModernRuntime/src/actionmodern/action.c**
   - Implemented `actionMbStringLength()` with UTF-8 character counting

### Implementation Algorithm

```c
void actionMbStringLength(char* stack, u32* sp, char* v_str)
{
    // Convert stack value to string (handles numeric conversions)
    convertString(stack, sp, v_str);

    // Get string pointer from stack
    const unsigned char* str = (const unsigned char*) VAL(u64, &STACK_TOP_VALUE);

    // Pop the string
    POP();

    // Count UTF-8 characters
    int count = 0;
    while (*str != '\0') {
        if ((*str & 0x80) == 0) {
            str += 1;  // 1-byte character
        } else if ((*str & 0xE0) == 0xC0) {
            str += 2;  // 2-byte character
        } else if ((*str & 0xF0) == 0xE0) {
            str += 3;  // 3-byte character
        } else if ((*str & 0xF8) == 0xF0) {
            str += 4;  // 4-byte character
        } else {
            str += 1;  // Invalid UTF-8, skip byte
        }
        count++;
    }

    // Push result
    float result = (float)count;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

### Key Differences from STRING_LENGTH (0x14)

| Aspect | STRING_LENGTH (0x14) | MB_STRING_LENGTH (0x31) |
|--------|---------------------|------------------------|
| **Counts** | Bytes | Characters |
| **UTF-8 Aware** | No | Yes |
| **"café"** | 5 | 4 |
| **"€100"** | 6 | 4 |
| **"中文"** | 6 | 2 |
| **"Hello世界"** | 11 | 7 |

## Building and Running

```bash
# Build the test
cd SWFRecomp
./scripts/build_test.sh mb_string_length_swf_5 native

# Run the test
./tests/mb_string_length_swf_5/build/native/mb_string_length_swf_5
```

## Edge Cases Handled

1. **Empty strings**: Return 0
2. **ASCII-only strings**: Each byte is one character
3. **Mixed multibyte**: Correctly counts each character regardless of byte length
4. **Invalid UTF-8**: Skips invalid bytes and continues (graceful degradation)

## Flash Compatibility

This opcode is available in SWF version 5 and later, which introduced multibyte string support. In ActionScript 2, this operation corresponds to:
- `String.length` property (in multibyte mode)
- `mblength(str)` function

## References

- SWF File Format Specification v19
- UTF-8 encoding standard (RFC 3629)
- ActionScript 2.0 Language Reference
