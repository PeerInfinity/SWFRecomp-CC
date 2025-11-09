# Opcode Implementation Prompt: ActionDivide (0x0D)

## Opcode Specification

**Opcode Name**: ActionDivide
**Hex Value**: 0x0D
**Category**: Arithmetic
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs division of two values. Pops two values from the stack, divides the second by the first, and pushes the result back onto the stack.

## Stack Operation

**Before**: `[... dividend divisor]`
**After**: `[... result]`

Where `result = dividend / divisor`

## Expected Behavior

1. Pop the first operand (divisor) from the stack
2. Pop the second operand (dividend) from the stack
3. Convert both values to numbers if needed
4. Compute `result = dividend / divisor`
5. Push the result onto the stack as a float

**Special Cases**:
- Division by zero: Results in `Infinity` (positive) or `-Infinity` (negative)
- `0 / 0` = `NaN`

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_DIVIDE` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionDivide()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Basic Division
```actionscript
trace(15 / 3);
```
**Expected output**: `5`

### Test Case 2: Floating Point Result
```actionscript
trace(10 / 4);
```
**Expected output**: `2.5`

### Test Case 3: Division by Zero
```actionscript
trace(5 / 0);
```
**Expected output**: `Infinity`

### Test Case 4: Negative Division by Zero
```actionscript
trace(-5 / 0);
```
**Expected output**: `-Infinity`

### Test Case 5: Zero Divided by Zero
```actionscript
trace(0 / 0);
```
**Expected output**: `NaN`

### Test Case 6: Fractional Division
```actionscript
trace(1 / 3);
```
**Expected output**: `0.3333333` (or similar)

## Similar Opcodes

- `actionAdd` (0x0A), `actionSubtract` (0x0B), `actionMultiply` (0x0C), `actionModulo` (0x3F)

## Notes

- **Division by zero is NOT an error** - it produces `Infinity` or `NaN`
- Stack order: `dividend / divisor` (second popped / first popped)
