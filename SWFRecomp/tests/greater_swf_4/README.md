# GREATER Opcode Test (0x48)

This test verifies the implementation of the GREATER comparison opcode in ActionScript 2.

## Opcode Details

- **Opcode**: 0x48
- **Name**: GREATER
- **Category**: Comparison
- **SWF Version**: 5+

## Test Description

Tests the greater than comparison operation with the expression `5 > 3`.

### Expected Behavior

- Pop two numeric values from the stack
- Compare: second popped value > first popped value
- Push result as 1.0 (true) or 0.0 (false)

### Test Case

```actionscript
trace(5 > 3);
```

**Expected Output**: `1` (true, because 5 is greater than 3)

## Stack Operation

The test performs the following operations:

1. Push 5.0 onto stack
2. Push 3.0 onto stack
3. Execute GREATER opcode:
   - Pop 3.0 (operand `a`)
   - Pop 5.0 (operand `b`)
   - Compare: `b > a` = `5.0 > 3.0` = true
   - Push 1.0 (result)
4. Execute TRACE opcode to display result

## Building and Running

```bash
# Build the test
cd SWFRecomp
./scripts/build_test.sh greater_swf_4 native

# Run the test
./tests/greater_swf_4/build/native/greater_swf_4
```

## Implementation Files

- **Enum**: `SWFRecomp/include/action/action.hpp` - `SWF_ACTION_GREATER = 0x48`
- **Translation**: `SWFRecomp/src/action/action.cpp` - case `SWF_ACTION_GREATER`
- **Declaration**: `SWFModernRuntime/include/actionmodern/action.h` - `void actionGreater(char* stack, u32* sp)`
- **Implementation**: `SWFModernRuntime/src/actionmodern/action.c` - `actionGreater()` function

## Additional Test Cases

The implementation also handles:

- Equal values: `5 > 5` = 0 (false)
- Reverse comparison: `3 > 5` = 0 (false)
- Floating point: `5.5 > 3.2` = 1 (true)
- Zero comparison: `1 > 0` = 1 (true)
- NaN handling: NaN comparisons return false

## Notes

- The comparison follows ActionScript 2 semantics
- Operands are automatically converted to numbers if needed
- Result is always a float (1.0 or 0.0)
- Handles both F32 and F64 numeric types correctly
