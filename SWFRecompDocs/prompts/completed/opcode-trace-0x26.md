# Opcode Implementation Prompt: ActionTrace (0x26)

## Opcode Specification

**Opcode Name**: ActionTrace
**Hex Value**: 0x26
**Category**: Debug
**Estimated Complexity**: SIMPLE
**SWF Version**: 5+

## Description

Outputs a value to the debug console. Pops one value from the stack, converts it to a string, and prints it. This is the implementation of ActionScript's `trace()` function.

## Stack Operation

**Before**: `[... value]`
**After**: `[...]`

The value is consumed and printed.

## Expected Behavior

1. Pop the value from the stack
2. Convert to string if needed
3. Print to stdout/console
4. Include newline after output

**Conversion Rules**:
- Numbers: Convert to decimal string
- Strings: Print as-is
- Undefined: Print "undefined"
- Null: Print "null"
- Objects: Print "[object Object]" or similar

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_TRACE` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionTrace()` in `SWFModernRuntime/src/actionmodern/action.c`
- **Tests**: Has test directory `trace_swf_4/`

## Test Cases

### Test Case 1: Trace Number
```actionscript
trace(42);
```
**Expected output**: `42`

### Test Case 2: Trace String
```actionscript
trace("Hello World");
```
**Expected output**: `Hello World`

### Test Case 3: Trace Expression
```actionscript
trace(5 + 3);
```
**Expected output**: `8`

### Test Case 4: Multiple Traces
```actionscript
trace("Line 1");
trace("Line 2");
```
**Expected output**:
```
Line 1
Line 2
```

## Similar Opcodes

- None directly similar (unique debug opcode)
- Related to output/logging functionality

## Notes

- This is the **most commonly used** opcode for testing
- Essential for debugging
- Already has comprehensive tests
- Output goes to stdout in NO_GRAPHICS mode
- **Reference implementation** for test validation
