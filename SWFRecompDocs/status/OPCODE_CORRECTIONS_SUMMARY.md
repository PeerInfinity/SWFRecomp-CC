# Opcode Corrections Summary

## Date: 2025-11-07

## Overview
This document summarizes the corrections made to align the SWF opcode mappings with the official SWF File Format Specification (Version 19).

## Source of Truth
All corrections are based on `SWFRecompDocs/specs/swf-spec-19.txt`

## Changes Made

### Enum Definitions (SWFRecomp/include/action/action.hpp)

| Opcode | OLD Enum Name | NEW Enum Name | Correct Action |
|--------|---------------|---------------|----------------|
| 0x31 | SWF_ACTION_CHAR_TO_ASCII | SWF_ACTION_MB_STRING_LENGTH | ActionMBStringLength |
| 0x32 | SWF_ACTION_ASCII_TO_CHAR | SWF_ACTION_CHAR_TO_ASCII | ActionCharToAscii |
| 0x33 | SWF_ACTION_MB_CHAR_TO_ASCII | SWF_ACTION_ASCII_TO_CHAR | ActionAsciiToChar |
| 0x35 | SWF_ACTION_MB_STRING_LENGTH | SWF_ACTION_MB_STRING_EXTRACT | ActionMBStringExtract |
| 0x36 | SWF_ACTION_MB_CHAR_TO_ASCII_0x36 (or MB_ASCII_TO_CHAR) | SWF_ACTION_MB_CHAR_TO_ASCII | ActionMBCharToAscii |
| 0x37 | (not defined) | SWF_ACTION_MB_ASCII_TO_CHAR | ActionMBAsciiToChar |

### Function Mappings

The implementation functions were already correct - they just needed to be mapped to the correct opcodes:

**Per SWF Spec 19:**

- **0x31 = ActionMBStringLength**
  - Calculates the length of a multi-byte string (character count, not byte count)
  - Function: `actionMbStringLength(char* stack, u32* sp, char* v_str)`

- **0x32 = ActionCharToAscii**
  - Converts first character of string to ASCII code (single-byte)
  - Function: `actionCharToAscii(char* stack, u32* sp)`

- **0x33 = ActionAsciiToChar**
  - Converts ASCII code to character (single-byte)
  - Function: `actionAsciiToChar(char* stack, u32* sp, char* str_buffer)`

- **0x35 = ActionMBStringExtract**
  - Extracts substring from multi-byte string
  - Function: NOT YET IMPLEMENTED (out of scope)

- **0x36 = ActionMBCharToAscii**
  - Converts first character of multi-byte string to numeric code point
  - Function: `actionMbCharToAscii(char* stack, u32* sp, char* str_buffer)`

- **0x37 = ActionMBAsciiToChar**
  - Converts numeric code point to multi-byte character string (UTF-8)
  - Function: `actionMbAsciiToChar(char* stack, u32* sp, char* str_buffer)`

### Action.cpp Cases

No changes were needed to the case statements in `SWFRecomp/src/action/action.cpp` because:
1. Cases reference enum names (not hex values)
2. Cases already called the correct implementation functions
3. Enum name changes automatically remapped the cases to the correct opcodes

### Build Status

✅ SWFRecomp builds successfully
✅ SWFModernRuntime builds successfully
✅ All test creation scripts updated with correct opcodes
✅ All test SWF files regenerated

## Test Files Updated

✅ **All test files have been updated and regenerated to match the SWF specification.**

### Tests Updated:

- `SWFRecomp/tests/char_to_ascii_swf_4/` - ✅ Updated from 0x31 → 0x32
- `SWFRecomp/tests/ascii_to_char_swf_4/` - ✅ Updated from 0x32 → 0x33
- `SWFRecomp/tests/mb_char_to_ascii_swf_5/` - ✅ Updated from 0x33 → 0x36
- `SWFRecomp/tests/mb_ascii_to_char_swf_5/` - ✅ Updated from 0x36 → 0x37
- `SWFRecomp/tests/mb_string_length_swf_5/` - ✅ Updated from 0x35 → 0x31

All test SWF files have been regenerated with the correct opcodes.

## Single-Byte vs Multi-Byte Operations

### Single-Byte (ASCII-only):
- **0x32 CharToAscii**: Extracts ASCII code from first byte of string (0-255)
- **0x33 AsciiToChar**: Converts ASCII code to single-byte character

### Multi-Byte (UTF-8 aware):
- **0x36 MBCharToAscii**: Decodes UTF-8 character to Unicode code point
- **0x37 MBAsciiToChar**: Encodes Unicode code point to UTF-8 character(s)

## Related Opcodes

For reference, other string-related opcodes:
- **0x14 (0x14)**: ActionStringLength - single-byte string length
- **0x15 (0x15)**: ActionStringExtract - single-byte substring extraction
- **0x31 (0x31)**: ActionMBStringLength - multi-byte string length
- **0x35 (0x35)**: ActionMBStringExtract - multi-byte substring extraction (not yet implemented)

## Completion Status

1. ✅ Enum definitions corrected (action.hpp)
2. ✅ Build verification completed (both projects build successfully)
3. ✅ Test files updated with correct opcodes
4. ✅ Test SWF files regenerated
5. ✅ Documentation updated
6. ⚠️ MB_STRING_EXTRACT (0x35) implementation pending (separate task)
7. ⚠️ Test execution verification pending (noted UTF-8 parsing issue in SWFRecomp, unrelated to these changes)

## References

- SWF File Format Specification Version 19: `SWFRecompDocs/specs/swf-spec-19.txt`
- Correction prompt: `SWFRecompDocs/prompts/corrections/opcode-mb-char-to-ascii-0x36-CORRECTED.md`
