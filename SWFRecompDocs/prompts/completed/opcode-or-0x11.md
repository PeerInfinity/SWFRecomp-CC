# Opcode Implementation Prompt: ActionOr (0x11)

## Opcode Specification

**Opcode Name**: ActionOr
**Hex Value**: 0x11
**Category**: Logic
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs logical OR operation on two values. Pops two values from the stack, evaluates them as booleans, performs logical OR, and pushes the result (1.0 or 0.0) back onto the stack.

## Stack Operation

**Before**: `[... value2 value1]`
**After**: `[... result]`

Where `result = 1.0` if either value is truthy, else `result = 0.0`

## Expected Behavior

1. Pop the first operand (value1) from the stack
2. Pop the second operand (value2) from the stack
3. Convert both to boolean values
4. Compute `result = (value2 is truthy) OR (value1 is truthy)`
5. Push 1.0 if either truthy, 0.0 if both falsy

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_OR` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionOr()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Both True
```actionscript
trace(1 || 1);
```
**Expected output**: `1`

### Test Case 2: First True, Second False
```actionscript
trace(1 || 0);
```
**Expected output**: `1`

### Test Case 3: First False, Second True
```actionscript
trace(0 || 1);
```
**Expected output**: `1`

### Test Case 4: Both False
```actionscript
trace(0 || 0);
```
**Expected output**: `0`

## Similar Opcodes

- `actionAnd` (0x10) - Logical AND
- `actionNot` (0x12) - Logical NOT

## Notes

- Result is always 1.0 or 0.0
- This is **logical OR**, not bitwise (use BIT_OR 0x61 for bitwise)
- Short-circuit evaluation does NOT apply
