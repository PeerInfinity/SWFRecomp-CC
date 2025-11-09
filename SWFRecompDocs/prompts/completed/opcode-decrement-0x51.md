# Opcode Implementation Prompt: ActionDecrement (0x51)

## Opcode Specification

**Opcode Name**: ActionDecrement
**Hex Value**: 0x51
**Category**: Arithmetic
**Estimated Complexity**: SIMPLE
**SWF Version**: 5+

## Description

Decrements a value by 1. Pops a value from the stack, subtracts 1 from it, and pushes the result back onto the stack. This is the implementation of the `--` operator (post-decrement).

## Stack Operation

**Before**: `[... value]`
**After**: `[... value-1]`

## Expected Behavior

1. Pop the value from the stack
2. Convert to number if needed
3. Subtract 1 from the value
4. Push the result back onto the stack

**Type Conversion**:
- Numbers: Direct decrement
- Strings: Parse as number, then decrement
- Non-numeric: Results in `NaN - 1 = NaN`
- Null/undefined: Treated as 0, result is -1

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_DECREMENT` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionDecrement()` in `SWFModernRuntime/src/actionmodern/action.c`
- **Tests**: Has test directory `decrement_swf_4/` ✅

## Test Cases

### Test Case 1: Decrement Integer
```actionscript
var x = 5;
x--;
trace(x);
```
**Expected output**: `4`

### Test Case 2: Decrement Float
```actionscript
var x = 3.5;
x--;
trace(x);
```
**Expected output**: `2.5`

### Test Case 3: Decrement Zero
```actionscript
var x = 0;
x--;
trace(x);
```
**Expected output**: `-1`

### Test Case 4: Decrement Positive to Zero
```actionscript
var x = 1;
x--;
trace(x);
```
**Expected output**: `0`

### Test Case 5: Decrement String Number
```actionscript
var x = "10";
x--;
trace(x);
```
**Expected output**: `9`

### Test Case 6: Decrement Non-Numeric
```actionscript
var x = "hello";
x--;
trace(x);
```
**Expected output**: `NaN`

## Implementation Reference

This is a unary operation:

```c
void actionDecrement(char* stack, u32* sp)
{
    // Convert to float
    convertFloat(stack, sp);

    // Pop value
    ActionVar a;
    popVar(stack, sp, &a);

    // Decrement
    float result = a.value.f32 - 1.0f;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

## Similar Opcodes

- `actionIncrement` (0x50) - Increment by 1
- `actionSubtract` (0x0B) - General subtraction

## Notes

- This is a **unary operation** (single operand)
- Always subtracts exactly 1
- Result is always a float
- Commonly used in countdown loops: `for (i = 10; i > 0; i--)`
- **Post-decrement**: Returns original value, then decrements (if used in expression)
- In ActionScript bytecode, decrement is separate from variable update
- Mirror operation to ActionIncrement (0x50)
