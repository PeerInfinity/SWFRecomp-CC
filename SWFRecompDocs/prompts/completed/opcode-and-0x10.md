# Opcode Implementation Prompt: ActionAnd (0x10)

## Opcode Specification

**Opcode Name**: ActionAnd
**Hex Value**: 0x10
**Category**: Logic
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs logical AND operation on two values. Pops two values from the stack, evaluates them as booleans, performs logical AND, and pushes the result (1.0 or 0.0) back onto the stack.

## Stack Operation

**Before**: `[... value2 value1]`
**After**: `[... result]`

Where `result = 1.0` if both values are truthy, else `result = 0.0`

## Expected Behavior

1. Pop the first operand (value1) from the stack
2. Pop the second operand (value2) from the stack
3. Convert both to boolean values
4. Compute `result = (value2 is truthy) AND (value1 is truthy)`
5. Push 1.0 if both truthy, 0.0 otherwise

**Truthy Values**:
- Non-zero numbers
- Non-empty strings
- Objects

**Falsy Values**:
- 0, 0.0
- Empty string ""
- null, undefined
- NaN

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_AND` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionAnd()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Both True
```actionscript
trace(1 && 1);
```
**Expected output**: `1`

### Test Case 2: First False
```actionscript
trace(0 && 1);
```
**Expected output**: `0`

### Test Case 3: Second False
```actionscript
trace(1 && 0);
```
**Expected output**: `0`

### Test Case 4: Both False
```actionscript
trace(0 && 0);
```
**Expected output**: `0`

### Test Case 5: Non-zero Numbers
```actionscript
trace(5 && 3);
```
**Expected output**: `1`

## Similar Opcodes

- `actionOr` (0x11) - Logical OR
- `actionNot` (0x12) - Logical NOT

## Notes

- Result is always 1.0 or 0.0 (float representation of boolean)
- This is **logical AND**, not bitwise (use BIT_AND 0x60 for bitwise)
- Short-circuit evaluation does NOT apply (both operands always evaluated)
