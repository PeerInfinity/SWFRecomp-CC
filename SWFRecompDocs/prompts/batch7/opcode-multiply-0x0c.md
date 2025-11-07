# Opcode Implementation Prompt: ActionMultiply (0x0C)

## Opcode Specification

**Opcode Name**: ActionMultiply
**Hex Value**: 0x0C
**Category**: Arithmetic
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs multiplication of two values. Pops two values from the stack, multiplies them, and pushes the result back onto the stack.

## Stack Operation

**Before**: `[... value2 value1]`
**After**: `[... result]`

Where `result = value2 * value1`

## Expected Behavior

1. Pop the first operand (value1) from the stack
2. Pop the second operand (value2) from the stack
3. Convert both values to numbers if needed
4. Compute `result = value2 * value1`
5. Push the result onto the stack as a float

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_MULTIPLY` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionMultiply()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Basic Multiplication
```actionscript
trace(5 * 3);
```
**Expected output**: `15`

### Test Case 2: Floating Point
```actionscript
trace(2.5 * 4);
```
**Expected output**: `10`

### Test Case 3: Multiply by Zero
```actionscript
trace(42 * 0);
```
**Expected output**: `0`

### Test Case 4: Negative Numbers
```actionscript
trace(-3 * 7);
```
**Expected output**: `-21`

### Test Case 5: Edge Case - Infinity
```actionscript
// Very large number
trace(1e200 * 1e200);
```
**Expected output**: `Infinity`

## Similar Opcodes

- `actionAdd` (0x0A), `actionSubtract` (0x0B), `actionDivide` (0x0D), `actionModulo` (0x3F)
