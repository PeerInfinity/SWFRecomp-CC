# Opcode Implementation Prompt: ActionStringAdd (0x21)

## Opcode Specification

**Opcode Name**: ActionStringAdd
**Hex Value**: 0x21
**Category**: String
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Concatenates two strings. Pops two strings from the stack, concatenates them, and pushes the result back onto the stack.

## Stack Operation

**Before**: `[... string2 string1]`
**After**: `[... result]`

Where `result = string2 + string1` (concatenation)

## Expected Behavior

1. Pop the first string from the stack
2. Pop the second string from the stack
3. Concatenate: `result = string2 + string1`
4. Push the result string onto the stack

**String Concatenation**:
- Both operands converted to strings if needed
- Numbers converted to string representation
- Result is new string

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_STRING_ADD` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionStringAdd()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Basic Concatenation
```actionscript
trace("Hello" add " World");
```
**Expected output**: `Hello World`

### Test Case 2: Empty String
```actionscript
trace("Hello" add "");
```
**Expected output**: `Hello`

### Test Case 3: Number to String
```actionscript
trace("Count: " add 42);
```
**Expected output**: `Count: 42`

### Test Case 4: Multiple Concatenation
```actionscript
trace("A" add "B" add "C");
```
**Expected output**: `ABC`

## Similar Opcodes

- `actionAdd` (0x0A) - Numeric addition
- `actionStringEquals` (0x13) - String equality
- `actionStringLength` (0x14) - String length

## Notes

- This is **string concatenation**, not addition
- Order matters: `string2 + string1`
- May require str_buffer for result
- SWF 4 uses `add` operator for strings
