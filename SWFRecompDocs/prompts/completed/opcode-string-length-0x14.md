# Opcode Implementation Prompt: ActionStringLength (0x14)

## Opcode Specification

**Opcode Name**: ActionStringLength
**Hex Value**: 0x14
**Category**: String
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Returns the length of a string. Pops one string from the stack, calculates its length in bytes, and pushes the length as a number onto the stack.

## Stack Operation

**Before**: `[... string]`
**After**: `[... length]`

Where `length` is the number of bytes in the string

## Expected Behavior

1. Pop the string from the stack
2. Calculate the byte length (strlen)
3. Push the length as a float onto the stack

**Length Calculation**:
- Counts bytes, not characters (for multibyte encodings)
- Empty string has length 0
- Null-terminated, so null byte not counted

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_STRING_LENGTH` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionStringLength()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Basic String
```actionscript
trace(length("hello"));
```
**Expected output**: `5`

### Test Case 2: Empty String
```actionscript
trace(length(""));
```
**Expected output**: `0`

### Test Case 3: String with Spaces
```actionscript
trace(length("hello world"));
```
**Expected output**: `11`

## Similar Opcodes

- `actionMBStringLength` (0x35) - Multibyte string length (character count)
- `actionStringExtract` (0x15) - Extract substring

## Notes

- This is a **unary operation**
- Returns byte count, not character count
- For UTF-8 strings, multibyte characters count as multiple bytes
