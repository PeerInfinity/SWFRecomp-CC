# Strict Equals Test (SWF 4)

## Opcode

- **Name**: STRICT_EQUALS
- **Hex Value**: 0x66
- **Category**: Comparison
- **Description**: Compares two values for strict equality (both type and value must match). Implements the `===` operator from ActionScript.

## Test Description

This test validates the implementation of the ActionStrictEquals opcode (0x66), which performs strict equality comparison without type coercion. Unlike regular equals (0x0E), strict equals requires both the type AND value to match.

## Test Cases

### Test 1: Same numeric values
```actionscript
trace(5 === 5);
```
**Expected output**: `1` (true - same type and value)

### Test 2: Different numeric values
```actionscript
trace(5 === 3);
```
**Expected output**: `0` (false - different values)

## Expected Complete Output

```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
1
0
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

## Implementation Notes

### Key Differences from Regular Equals

1. **No Type Coercion**: The opcode does NOT call `convertFloat()` or `convertString()` before comparison
2. **Type Check First**: Must check that `a.type == b.type` before comparing values
3. **Type-Specific Comparison**: Different types use different comparison logic:
   - `ACTION_STACK_VALUE_F32`: Compare float values directly
   - `ACTION_STACK_VALUE_F64`: Compare double values directly
   - `ACTION_STACK_VALUE_STRING`: Use `strcmp()` for string comparison
   - Other types: Compare raw numeric values

### Runtime Implementation

The implementation requires declaring `u32 oldSP` because the `PUSH` macro uses it internally:

```c
void actionStrictEquals(char* stack, u32* sp)
{
    u32 oldSP;  // REQUIRED by PUSH macro - do not omit!

    // Pop arguments WITHOUT type conversion
    ActionVar a, b;
    popVar(stack, sp, &a);
    popVar(stack, sp, &b);

    float result = 0.0f;

    // Types must match
    if (a.type == b.type) {
        // Compare values based on type
        switch (a.type) {
            case ACTION_STACK_VALUE_F32:
                result = (VAL(float, &a.data.numeric_value) ==
                         VAL(float, &b.data.numeric_value)) ? 1.0f : 0.0f;
                break;
            case ACTION_STACK_VALUE_STRING:
                // With NULL checks
                if (str_a && str_b)
                    result = (strcmp(str_a, str_b) == 0) ? 1.0f : 0.0f;
                break;
            // ... other types
        }
    }

    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Critical**: The `oldSP` variable is essential. Without it, the code compiles but crashes at runtime.

## Build Instructions

```bash
# From SWFRecomp directory
cd /home/user/SWFRecomp-CC/SWFRecomp

# Build the test (auto-generates test.swf from create_test_swf.py)
./scripts/build_test.sh strict_equals_swf_4 native

# Run the test
./tests/strict_equals_swf_4/build/native/strict_equals_swf_4
```

## Files

- `test.swf` - Generated SWF test file (created by build script)
- `create_test_swf.py` - Python script that generates test.swf
- `config.toml` - SWFRecomp configuration
- `README.md` - This file

## Status

✅ Implementation complete
- Enum defined in `SWFRecomp/include/action/action.hpp`
- Translation added in `SWFRecomp/src/action/action.cpp`
- Function declared in `SWFModernRuntime/include/actionmodern/action.h`
- Function implemented in `SWFModernRuntime/src/actionmodern/action.c`
- Test cases created and validated
