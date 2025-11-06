# MB_ASCII_TO_CHAR (0x36) Test

## Opcode Information

- **Opcode**: 0x36
- **Name**: MB_ASCII_TO_CHAR (Multibyte ASCII to Character)
- **Category**: String Operations
- **SWF Version**: 5+ (requires multibyte support)

## Description

Converts a Unicode code point value to its corresponding UTF-8 character string.

## Operation

1. Pop a numeric value from the stack
2. Convert to integer code point
3. Encode the code point as a UTF-8 character sequence
4. Push the resulting string onto the stack

## UTF-8 Encoding Ranges

The implementation correctly handles all UTF-8 encoding ranges:
- **1-byte**: 0x00 - 0x7F (standard ASCII)
- **2-byte**: 0x80 - 0x7FF
- **3-byte**: 0x800 - 0xFFFF
- **4-byte**: 0x10000 - 0x10FFFF

## Test Cases

This test file verifies the following cases:

### Test Case 1: Basic ASCII
```actionscript
mbchr(65)
```
**Expected Output**: `A`
**Result**: ✓ Pass

### Test Case 2: 2-byte UTF-8 Character
```actionscript
mbchr(233)
```
**Expected Output**: `é` (U+00E9 - Latin small letter e with acute)
**Result**: ✓ Pass

### Test Case 3: 3-byte UTF-8 Character
```actionscript
mbchr(8364)
```
**Expected Output**: `€` (U+20AC - Euro sign)
**Result**: ✓ Pass

### Test Case 4: CJK Character (3-byte UTF-8)
```actionscript
mbchr(20013)
```
**Expected Output**: `中` (U+4E2D - Chinese character meaning "middle/center")
**Result**: ✓ Pass

### Test Case 5: Out of Range
```actionscript
mbchr(9999999)
```
**Expected Output**: Empty string (code point exceeds valid Unicode range 0x10FFFF)
**Result**: ✓ Pass

## Expected Complete Output

```
A
é
€
中

```

Note: The fifth test case produces an empty line (empty string) as the code point is out of range.

## Implementation Details

### Files Modified

1. **SWFRecomp/include/action/action.hpp** - Added `SWF_ACTION_MB_ASCII_TO_CHAR = 0x36` enum
2. **SWFRecomp/src/action/action.cpp** - Added translation case for opcode 0x36
3. **SWFModernRuntime/include/actionmodern/action.h** - Declared `actionMbAsciiToChar()` function
4. **SWFModernRuntime/src/actionmodern/action.c** - Implemented UTF-8 encoding logic

### Runtime Function Signature

```c
void actionMbAsciiToChar(char* stack, u32* sp, char* str_buffer)
```

### Edge Case Handling

- **Out of range values** (> 0x10FFFF): Returns empty string
- **Negative numbers**: Converted to large unsigned values, caught by range check
- **NaN**: Converted to 0 by float-to-int conversion
- **Infinity**: Handled by unsigned conversion

## Building and Running

```bash
# Build the test
cd SWFRecomp
./scripts/build_test.sh mb_ascii_to_char_swf_5 native

# Run the test
./tests/mb_ascii_to_char_swf_5/build/native/mb_ascii_to_char_swf_5
```

## ActionScript Equivalent

In ActionScript 2.0, this operation corresponds to:
```actionscript
String.fromCharCode(codepoint)  // In multibyte-aware environments
mbchr(codepoint)                // Alternative function name
```

## References

- [UTF-8 Specification](https://en.wikipedia.org/wiki/UTF-8)
- [Unicode Code Points](https://en.wikipedia.org/wiki/Unicode)
- SWF File Format Specification v19
