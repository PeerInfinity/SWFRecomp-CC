# Opcode Implementation Prompt: ActionSubtract (0x0B)

## Opcode Specification

**Opcode Name**: ActionSubtract
**Hex Value**: 0x0B
**Category**: Arithmetic
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs subtraction of two values. Pops two values from the stack, subtracts the first from the second, and pushes the result back onto the stack.

## Stack Operation

**Before**: `[... value2 value1]`
**After**: `[... result]`

Where `result = value2 - value1`

## Expected Behavior

1. Pop the first operand (value1) from the stack
2. Pop the second operand (value2) from the stack
3. Convert both values to numbers if needed
4. Compute `result = value2 - value1`
5. Push the result onto the stack as a float

**Type Conversion Rules**:
- Strings are converted to numbers (parseFloat)
- Empty string converts to 0
- Non-numeric strings convert to NaN
- Boolean true converts to 1, false to 0
- Null/undefined convert to 0

## Implementation Status

✅ **Already Implemented** - This opcode is fully implemented in the codebase.

- **Enum**: `SWF_ACTION_SUBTRACT` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionSubtract()` in `SWFModernRuntime/src/actionmodern/action.c`

## Your Task

Since this opcode is already implemented, your task is to:

1. **Review the existing implementation** to understand how it works
2. **Create comprehensive tests** in `SWFRecomp/tests/subtract_swf_4/` (or similar)
3. **Add validation files**:
   - `test_info.json` - Test metadata
   - `validate.py` - Validation script
4. **Document edge cases** and ensure they are tested

## Test Cases

### Test Case 1: Basic Subtraction
```actionscript
trace(10 - 3);
```
**Expected output**: `7`

### Test Case 2: Floating Point Subtraction
```actionscript
trace(5.5 - 2.5);
```
**Expected output**: `3`

### Test Case 3: String to Number Conversion
```actionscript
trace("20" - 5);
```
**Expected output**: `15`

### Test Case 4: Subtracting Zero
```actionscript
trace(42 - 0);
```
**Expected output**: `42`

### Test Case 5: Negative Result
```actionscript
trace(5 - 10);
```
**Expected output**: `-5`

### Test Case 6: Edge Case - NaN
```actionscript
trace("hello" - 5);
```
**Expected output**: `NaN`

## Implementation Reference

The existing implementation follows this pattern:

```c
void actionSubtract(char* stack, u32* sp)
{
    // Convert and pop first operand (subtrahend)
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert and pop second operand (minuend)
    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Perform subtraction: b - a
    float result = b.value.f32 - a.value.f32;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

## Similar Opcodes

Reference these similar arithmetic opcodes:
- `actionAdd` (0x0A) - Addition
- `actionMultiply` (0x0C) - Multiplication
- `actionDivide` (0x0D) - Division
- `actionModulo` (0x3F) - Modulo

## Success Criteria

Your implementation documentation is complete when:
- [ ] Test directory created with all required files
- [ ] `test_info.json` created with opcode metadata
- [ ] `validate.py` created with comprehensive validation
- [ ] All test cases pass (basic, floating point, type conversion, edge cases)
- [ ] Test passes in `./all_tests.sh`
- [ ] Edge cases documented (NaN, infinity, type conversions)

## Notes

- This is a **binary arithmetic operation**
- Stack order matters: `value2 - value1` (not `value1 - value2`)
- Both operands are converted to float before subtraction
- Result is always a float, even if both operands are integers
- NaN - anything = NaN
- Infinity - Infinity = NaN (special case!)
- Infinity - finite = Infinity
