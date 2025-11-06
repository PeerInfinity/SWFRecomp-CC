# CharToAscii (0x31) Test

This test verifies the implementation of the AS2 `CharToAscii` (0x31) opcode.

## Opcode Details

- **Opcode**: 0x31
- **Name**: CHAR_TO_ASCII
- **Category**: String Operations
- **Description**: Converts the first character of a string to its ASCII/Unicode code value

## Operation

1. Pop value from stack and convert to string
2. Get the first character of the string
3. Get the ASCII code (Unicode code point) of that character
4. Push the numeric code value onto the stack

## Test Cases

### Test 1: Single character 'A'
```actionscript
trace(ord("A"));
```
**Expected**: `65`

### Test 2: Multiple characters 'Hello'
```actionscript
trace(ord("Hello"));
```
**Expected**: `72` (ASCII code of 'H', the first character)

### Test 3: Special character '!'
```actionscript
trace(ord("!"));
```
**Expected**: `33`

### Test 4: Empty string
```actionscript
trace(ord(""));
```
**Expected**: `NaN` (displayed as `-nan`)

### Test 5: Unicode character 'é' (Latin-1)
```actionscript
trace(ord("é"));
```
**Expected**: `233` (0xE9 in Latin-1)

## Building and Running

### Build the test:
```bash
cd /home/user/SWFRecomp-CC/SWFRecomp
./scripts/build_test.sh char_to_ascii_swf_4 native
```

### Run the test:
```bash
./tests/char_to_ascii_swf_4/build/native/char_to_ascii_swf_4
```

### Expected Output:
```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
65
72
33
-nan
233
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

## Implementation Files

- **Enum**: `SWFRecomp/include/action/action.hpp` - `SWF_ACTION_CHAR_TO_ASCII = 0x31`
- **Translation**: `SWFRecomp/src/action/action.cpp` - Translation to C function call
- **Declaration**: `SWFModernRuntime/include/actionmodern/action.h` - `actionCharToAscii()`
- **Implementation**: `SWFModernRuntime/src/actionmodern/action.c` - Runtime opcode handler

## Implementation Notes

- Uses `unsigned char` cast to ensure values 128-255 are handled correctly
- Returns NaN for empty string (Flash behavior)
- Only considers the first character of multi-character strings
- Handles both ASCII and Latin-1 encoded characters
