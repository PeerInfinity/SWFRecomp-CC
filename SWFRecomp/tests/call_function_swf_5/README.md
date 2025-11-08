# CALL_FUNCTION Opcode Test (0x3D)

## Test Description

This test verifies the implementation of the CALL_FUNCTION opcode (0x3D), which is used to call functions with arguments in ActionScript 2.

## Test Case

**ActionScript equivalent:**
```actionscript
trace(parseInt("42"));
```

**Expected output:**
```
42
```

## What This Tests

1. **Function name handling**: Popping the function name string from the stack
2. **Argument count**: Popping and interpreting the argument count
3. **Argument passing**: Popping arguments in the correct order
4. **Function lookup**: Finding the built-in parseInt function
5. **Function execution**: Calling parseInt with the string "42"
6. **Return value**: Pushing the result (42) back onto the stack
7. **Integration**: The result is traced correctly

## Built-in Functions Implemented

The CALL_FUNCTION implementation includes these built-in global functions:

- `parseInt(string)` - Parses a string to an integer
  - Returns NaN if the string cannot be parsed
  - Returns NaN if no argument is provided
- `parseFloat(string)` - Parses a string to a floating-point number
  - Returns NaN if the string cannot be parsed
  - Returns NaN if no argument is provided
- `isNaN(value)` - Checks if a value is NaN
  - Returns 1.0 (true) if value is NaN
  - Returns 0.0 (false) otherwise
- `isFinite(value)` - Checks if a value is finite
  - Returns 1.0 (true) if value is not NaN and not Infinity
  - Returns 0.0 (false) otherwise

## Opcode Details

**Opcode**: 0x3D
**Name**: ActionCallFunction
**SWF Version**: 5+
**Stack Effect**: Pops function name, argument count, and N arguments; pushes return value

**Stack behavior:**
```
Before:  ... | "parseInt" | 1 | "42" |
After:   ... | 42 |
```

## Implementation Notes

- Arguments are pushed onto the stack in order (first to last), but the opcode pops them in reverse order (last to first)
- Built-in global functions (parseInt, parseFloat, isNaN, isFinite) are checked first
- User-defined functions from DEFINE_FUNCTION2 are supported
- User-defined functions from DEFINE_FUNCTION (simple version) are not yet fully supported for invocation
- If a function is not found, `undefined` is pushed onto the stack

## Build and Run

```bash
# From SWFRecomp directory
./scripts/build_test.sh call_function_swf_5 native

# Run the test
./tests/call_function_swf_5/build/native/call_function_swf_5
```

## Opcode Correction Note

This implementation corrects an earlier error where opcode 0x3D was incorrectly assigned to DUPLICATE. According to the official SWF specification (version 19), opcode 0x3D is ActionCallFunction, not ActionDuplicate. The correct opcode for ActionPushDuplicate is 0x4C.
