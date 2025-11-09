# Opcode Implementation Prompt: ActionNot (0x12)

## Opcode Specification

**Opcode Name**: ActionNot
**Hex Value**: 0x12
**Category**: Logic
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs logical NOT operation on a value. Pops one value from the stack, evaluates it as a boolean, negates it, and pushes the result (1.0 or 0.0) back onto the stack.

## Stack Operation

**Before**: `[... value]`
**After**: `[... result]`

Where `result = 1.0` if value is falsy, else `result = 0.0`

## Expected Behavior

1. Pop the operand (value) from the stack
2. Convert to boolean
3. Compute `result = NOT (value is truthy)`
4. Push 1.0 if value is falsy, 0.0 if value is truthy

**Truthy Values**: Non-zero numbers, non-empty strings, objects
**Falsy Values**: 0, empty string "", null, undefined, NaN

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_NOT` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionNot()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Not True
```actionscript
trace(!1);
```
**Expected output**: `0`

### Test Case 2: Not False
```actionscript
trace(!0);
```
**Expected output**: `1`

### Test Case 3: Double Negation
```actionscript
trace(!!5);
```
**Expected output**: `1`

### Test Case 4: Not Empty String
```actionscript
trace(!"");
```
**Expected output**: `1`

## Similar Opcodes

- `actionAnd` (0x10) - Logical AND
- `actionOr` (0x11) - Logical OR

## Notes

- This is a **unary operation** (single operand)
- Result is always 1.0 or 0.0
- This is **logical NOT**, not bitwise
