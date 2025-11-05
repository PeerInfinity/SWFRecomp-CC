# LESS2 Opcode Test (0x48) - Originally labeled "GREATER"

**IMPORTANT NOTE**: This test was originally created to test the "GREATER" operation, but opcode 0x48 is actually **ActionLess2** according to the official SWF specification. The test has been updated to reflect the correct semantics.

## Opcode Details

- **Opcode**: 0x48
- **Official Name**: ActionLess2 (not ActionGreater!)
- **Category**: Comparison
- **SWF Version**: 5+

## Background

There was confusion because:
- Opcode 0x48 is officially called **ActionLess2** in the SWF spec
- It computes `arg2 < arg1` which is semantically equivalent to `arg1 > arg2`
- This led to it being informally called "GREATER" in some documentation
- The real **ActionGreater** opcode is **0x67** (different opcode!)

## Current Test Behavior

This test uses opcode 0x48 (ActionLess2) with the values:
- Push 5.0
- Push 3.0
- Execute 0x48 (ActionLess2)

### Execution:
- Pop arg1 = 3.0 (top of stack)
- Pop arg2 = 5.0 (second from top)
- Compute: arg2 < arg1 = 5.0 < 3.0 = **false (0)**

**Expected Output**: `0` (false)

## Recommended Action

This test should be updated to test the correct semantics:

### Option 1: Test as "Less Than"
Rename to reflect that it tests `5 > 3` viewed as "NOT (5 < 3)":
```python
# Current bytecode tests: 5 < 3 = false
# To test 5 > 3, we would need to use opcode 0x67 (ActionGreater)
```

### Option 2: Use Correct Opcode
Update the test to use opcode 0x67 (ActionGreater) instead of 0x48.

## For Correct "Greater Than" Testing

To properly test `5 > 3 = true`, the ActionScript compiler would generate:
- Push 5.0 (left operand)
- Push 3.0 (right operand)
- Execute **0x67** (ActionGreater - not implemented yet)
  - Pop arg1 = 3.0
  - Pop arg2 = 5.0
  - Compute: arg2 > arg1 = 5.0 > 3.0 = true (1)

## See Also

- `less2_swf_4/` - Proper test for ActionLess2 (0x48) demonstrating `3 < 5 = true`
- SWF Spec Section on ActionLess2 (0x48) and ActionGreater (0x67)

## Implementation Files

- **Enum**: `SWFRecomp/include/action/action.hpp` - `SWF_ACTION_LESS2 = 0x48`
- **Translation**: `SWFRecomp/src/action/action.cpp` - case `SWF_ACTION_LESS2`
- **Declaration**: `SWFModernRuntime/include/actionmodern/action.h` - `void actionLess2(char* stack, u32* sp)`
- **Implementation**: `SWFModernRuntime/src/actionmodern/action.c` - `actionLess2()` function
