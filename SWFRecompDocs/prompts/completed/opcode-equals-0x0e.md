# Opcode Implementation Prompt: ActionEquals (0x0E)

## Opcode Specification

**Opcode Name**: ActionEquals
**Hex Value**: 0x0E
**Category**: Comparison
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs equality comparison of two values with type coercion. Pops two values from the stack, compares them for equality, and pushes 1.0 (true) or 0.0 (false) onto the stack.

## Stack Operation

**Before**: `[... value2 value1]`
**After**: `[... result]`

Where `result = 1.0` if `value2 == value1`, else `result = 0.0`

## Expected Behavior

1. Pop the first operand (value1) from the stack
2. Pop the second operand (value2) from the stack
3. Compare values with type coercion
4. Push 1.0 if equal, 0.0 if not equal

**Type Coercion Rules** (SWF 4):
- Numbers are converted to floats for comparison
- Strings are compared lexicographically
- If types differ, convert both to numbers
- `null == undefined` is true
- `NaN == anything` is false (even `NaN == NaN`)

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_EQUALS` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionEquals()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Equal Numbers
```actionscript
trace(5 == 5);
```
**Expected output**: `1`

### Test Case 2: Unequal Numbers
```actionscript
trace(5 == 3);
```
**Expected output**: `0`

### Test Case 3: String Equality
```actionscript
trace("hello" == "hello");
```
**Expected output**: `1`

### Test Case 4: Type Coercion
```actionscript
trace("5" == 5);
```
**Expected output**: `1` (string coerced to number)

### Test Case 5: NaN Comparison
```actionscript
var x = 0/0; // NaN
trace(x == x);
```
**Expected output**: `0` (NaN never equals itself)

## Similar Opcodes

- `actionLess` (0x0F) - Less than comparison
- `actionStrictEquals` (0x66) - Strict equality (no coercion)
- `actionStringEquals` (0x13) - String equality

## Notes

- Result is always 1.0 or 0.0 (float representation of boolean)
- This is **loose equality** with type coercion
- For strict equality without coercion, use `actionStrictEquals` (0x66)
