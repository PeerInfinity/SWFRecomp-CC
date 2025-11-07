# Opcode Implementation Prompt: ActionAdd (0x0A)

## Opcode Specification

**Opcode Name**: ActionAdd
**Hex Value**: 0x0A
**Category**: Arithmetic
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Performs addition of two values. Pops two values from the stack, adds them, and pushes the result back onto the stack.

## Stack Operation

**Before**: `[... value2 value1]`
**After**: `[... result]`

Where `result = value2 + value1`

## Expected Behavior

1. Pop the first operand (value1) from the stack
2. Pop the second operand (value2) from the stack
3. Convert both values to numbers if needed
4. Compute `result = value2 + value1`
5. Push the result onto the stack as a float

**Type Conversion Rules**:
- Strings are converted to numbers (parseFloat)
- Empty string converts to 0
- Non-numeric strings convert to NaN
- Boolean true converts to 1, false to 0
- Null/undefined convert to 0

## Implementation Status

✅ **Already Implemented** - This opcode is fully implemented in the codebase.

- **Enum**: `SWF_ACTION_ADD` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionAdd()` in `SWFModernRuntime/src/actionmodern/action.c`

## Your Task

Since this opcode is already implemented, your task is to:

1. **Review the existing implementation** to understand how it works
2. **Create comprehensive tests** in `SWFRecomp/tests/add_swf_4/` (or similar)
3. **Add validation files**:
   - `test_info.json` - Test metadata
   - `validate.py` - Validation script
4. **Document edge cases** and ensure they are tested

## Test Cases

### Test Case 1: Basic Addition
```actionscript
trace(5 + 3);
```
**Expected output**: `8`

### Test Case 2: Floating Point Addition
```actionscript
trace(2.5 + 1.5);
```
**Expected output**: `4`

### Test Case 3: String to Number Conversion
```actionscript
trace("10" + 5);
```
**Expected output**: `15`

### Test Case 4: Addition with Zero
```actionscript
trace(0 + 42);
```
**Expected output**: `42`

### Test Case 5: Negative Numbers
```actionscript
trace(-5 + 10);
```
**Expected output**: `5`

### Test Case 6: Edge Case - NaN
```actionscript
trace("hello" + 5);
```
**Expected output**: `NaN`

## Implementation Reference

The existing implementation follows this pattern:

```c
void actionAdd(char* stack, u32* sp)
{
    // Convert and pop first operand
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert and pop second operand
    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Perform addition
    float result = b.value.f32 + a.value.f32;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

## Similar Opcodes

Reference these similar arithmetic opcodes:
- `actionSubtract` (0x0B) - Subtraction
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
- Stack order matters: `value2 + value1` (not `value1 + value2`)
- Both operands are converted to float before addition
- Result is always a float, even if both operands are integers
- NaN + anything = NaN
- Infinity + Infinity = Infinity
