# Opcode Implementation Prompt: ActionStringEquals (0x13)

## Opcode Specification

**Opcode Name**: ActionStringEquals
**Hex Value**: 0x13
**Category**: String
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs string equality comparison. Pops two strings from the stack, compares them lexicographically, and pushes 1.0 (true) or 0.0 (false) onto the stack.

## Stack Operation

**Before**: `[... string2 string1]`
**After**: `[... result]`

Where `result = 1.0` if strings are equal, else `result = 0.0`

## Expected Behavior

1. Pop the first string from the stack
2. Pop the second string from the stack
3. Compare strings for exact equality
4. Push 1.0 if equal, 0.0 if not equal

**Comparison Rules**:
- Case-sensitive comparison
- Byte-by-byte comparison
- Empty strings are equal to each other
- No type coercion (both must be strings)

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_STRING_EQUALS` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionStringEquals()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Equal Strings
```actionscript
trace("hello" eq "hello");
```
**Expected output**: `1`

### Test Case 2: Unequal Strings
```actionscript
trace("hello" eq "world");
```
**Expected output**: `0`

### Test Case 3: Case Sensitivity
```actionscript
trace("Hello" eq "hello");
```
**Expected output**: `0`

### Test Case 4: Empty Strings
```actionscript
trace("" eq "");
```
**Expected output**: `1`

## Similar Opcodes

- `actionEquals` (0x0E) - General equality with type coercion
- `actionStringLess` (0x29) - String less-than comparison

## Notes

- This is **string-specific** comparison
- No type coercion (unlike actionEquals)
- Case-sensitive
