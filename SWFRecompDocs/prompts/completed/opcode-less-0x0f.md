# Opcode Implementation Prompt: ActionLess (0x0F)

## Opcode Specification

**Opcode Name**: ActionLess
**Hex Value**: 0x0F
**Category**: Comparison
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs less-than comparison of two values. Pops two values from the stack, compares them, and pushes 1.0 (true) or 0.0 (false) onto the stack.

## Stack Operation

**Before**: `[... value2 value1]`
**After**: `[... result]`

Where `result = 1.0` if `value2 < value1`, else `result = 0.0`

## Expected Behavior

1. Pop the first operand (value1) from the stack
2. Pop the second operand (value2) from the stack
3. Compare: is value2 < value1?
4. Push 1.0 if true, 0.0 if false

**Type Coercion Rules**:
- Both values converted to numbers for comparison
- Strings are parsed as numbers
- `NaN < anything` is always false

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_LESS` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionLess()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Less Than True
```actionscript
trace(3 < 5);
```
**Expected output**: `1`

### Test Case 2: Less Than False
```actionscript
trace(5 < 3);
```
**Expected output**: `0`

### Test Case 3: Equal Values
```actionscript
trace(5 < 5);
```
**Expected output**: `0` (not less than, equal)

### Test Case 4: Negative Numbers
```actionscript
trace(-10 < -5);
```
**Expected output**: `1`

### Test Case 5: String to Number
```actionscript
trace("3" < 5);
```
**Expected output**: `1`

## Similar Opcodes

- `actionEquals` (0x0E) - Equality comparison
- `actionGreater` (0x67) - Greater than comparison
- `actionStringLess` (0x29) - String less-than

## Notes

- Result is always 1.0 or 0.0 (float representation of boolean)
- Stack order: `value2 < value1` (second popped < first popped)
- Type coercion to numbers before comparison
