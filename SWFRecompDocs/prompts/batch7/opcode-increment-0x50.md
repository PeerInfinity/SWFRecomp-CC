# Opcode Implementation Prompt: ActionIncrement (0x50)

## Opcode Specification

**Opcode Name**: ActionIncrement
**Hex Value**: 0x50
**Category**: Arithmetic
**Estimated Complexity**: SIMPLE
**SWF Version**: 5+

## Description

Increments a value by 1. Pops a value from the stack, adds 1 to it, and pushes the result back onto the stack. This is the implementation of the `++` operator (post-increment).

## Stack Operation

**Before**: `[... value]`
**After**: `[... value+1]`

## Expected Behavior

1. Pop the value from the stack
2. Convert to number if needed
3. Add 1 to the value
4. Push the result back onto the stack

**Type Conversion**:
- Numbers: Direct increment
- Strings: Parse as number, then increment
- Non-numeric: Results in `NaN + 1 = NaN`
- Null/undefined: Treated as 0, result is 1

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_INCREMENT` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionIncrement()` in `SWFModernRuntime/src/actionmodern/action.c`
- **Tests**: Has test directory `increment_swf_4/` ✅

## Test Cases

### Test Case 1: Increment Integer
```actionscript
var x = 5;
x++;
trace(x);
```
**Expected output**: `6`

### Test Case 2: Increment Float
```actionscript
var x = 3.5;
x++;
trace(x);
```
**Expected output**: `4.5`

### Test Case 3: Increment Zero
```actionscript
var x = 0;
x++;
trace(x);
```
**Expected output**: `1`

### Test Case 4: Increment Negative
```actionscript
var x = -1;
x++;
trace(x);
```
**Expected output**: `0`

### Test Case 5: Increment String Number
```actionscript
var x = "10";
x++;
trace(x);
```
**Expected output**: `11`

### Test Case 6: Increment Non-Numeric
```actionscript
var x = "hello";
x++;
trace(x);
```
**Expected output**: `NaN`

## Implementation Reference

This is a unary operation:

```c
void actionIncrement(char* stack, u32* sp)
{
    // Convert to float
    convertFloat(stack, sp);

    // Pop value
    ActionVar a;
    popVar(stack, sp, &a);

    // Increment
    float result = a.value.f32 + 1.0f;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

## Similar Opcodes

- `actionDecrement` (0x51) - Decrement by 1
- `actionAdd` (0x0A) - General addition

## Notes

- This is a **unary operation** (single operand)
- Always adds exactly 1
- Result is always a float
- Commonly used in loops: `for (i = 0; i < 10; i++)`
- **Post-increment**: Returns original value, then increments (if used in expression)
- In ActionScript bytecode, increment is separate from variable update
