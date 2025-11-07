# Opcode Implementation Prompt: ActionModulo (0x3F)

## Opcode Specification

**Opcode Name**: ActionModulo
**Hex Value**: 0x3F
**Category**: Arithmetic
**Estimated Complexity**: SIMPLE
**SWF Version**: 5+

## Description

Computes the remainder of dividing two numbers (modulo operation). Pops two values from the stack, computes the modulo, and pushes the result back onto the stack.

## Stack Operation

**Before**: `[... dividend divisor]`
**After**: `[... result]`

Where `result = dividend % divisor`

## Expected Behavior

1. Pop the divisor from the stack
2. Pop the dividend from the stack
3. Convert both to numbers if needed
4. Compute `result = dividend % divisor` using floating-point modulo
5. Push the result onto the stack as a float

**Modulo Rules**:
- Uses `fmod()` function for floating-point modulo
- `x % 0` = `NaN`
- `0 % x` = `0`
- Sign of result follows dividend (first operand)
- Works with negative numbers

## Implementation Status

✅ **Already Implemented** - This is a reference implementation!

- **Enum**: `SWF_ACTION_MODULO` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionModulo()` in `SWFModernRuntime/src/actionmodern/action.c`
- **Tests**: Has test directory `modulo_swf_4/` ✅

## Test Cases

### Test Case 1: Basic Modulo
```actionscript
trace(7 % 3);
```
**Expected output**: `1`

### Test Case 2: Floating Point Modulo
```actionscript
trace(7.5 % 2.0);
```
**Expected output**: `1.5`

### Test Case 3: Modulo by Zero
```actionscript
trace(5 % 0);
```
**Expected output**: `NaN`

### Test Case 4: Zero Modulo
```actionscript
trace(0 % 5);
```
**Expected output**: `0`

### Test Case 5: Negative Numbers
```actionscript
trace(-7 % 3);
```
**Expected output**: `-1` (sign follows dividend)

### Test Case 6: Large Numbers
```actionscript
trace(100 % 7);
```
**Expected output**: `2`

## Implementation Reference

The existing implementation (validated in Experiment #2):

```c
void actionModulo(char* stack, u32* sp)
{
    // Convert and pop divisor
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert and pop dividend
    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Compute modulo using fmod
    float result = fmod(b.value.f32, a.value.f32);

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

## Similar Opcodes

- `actionAdd` (0x0A) - Addition
- `actionSubtract` (0x0B) - Subtraction
- `actionMultiply` (0x0C) - Multiplication
- `actionDivide` (0x0D) - Division

## Notes

- This is a **binary arithmetic operation**
- Stack order: `dividend % divisor` (second popped % first popped)
- Uses `fmod()` from `<math.h>` for floating-point modulo
- Result sign follows dividend (not divisor)
- **Reference implementation** - this was the validation test for Experiment #2
- Build time: ~45 minutes (validated)
- Works correctly with all edge cases
