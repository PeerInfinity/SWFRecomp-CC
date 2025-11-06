# TYPEOF Opcode Test (0x3C)

This test validates the implementation of the TYPEOF opcode (0x3C) in SWF version 5+.

## Opcode Specification

- **Opcode**: 0x3C
- **Name**: TYPEOF
- **Operation**: Pop value from stack, determine its type, push type name as string
- **SWF Version**: 5+

## Test Cases

### Test Case 1: Number type
```actionscript
trace(typeof(42));
```
Expected output: `number`

### Test Case 2: String type
```actionscript
trace(typeof("hello"));
```
Expected output: `string`

### Test Case 3: Number type (float)
```actionscript
trace(typeof(3.14));
```
Expected output: `number`

### Test Case 4: Empty string type
```actionscript
trace(typeof(""));
```
Expected output: `string`

## Expected Output

```
number
string
number
string
```

## Implementation Details

The `actionTypeof` function:
1. Peeks at the type of the value on the stack
2. Pops the value from the stack
3. Determines the type string based on the stack value type:
   - `ACTION_STACK_VALUE_F32` or `ACTION_STACK_VALUE_F64` → "number"
   - `ACTION_STACK_VALUE_STRING` or `ACTION_STACK_VALUE_STR_LIST` → "string"
   - `ACTION_STACK_VALUE_OBJECT` → "object"
   - Default → "undefined"
4. Copies the type string to the string buffer
5. Pushes the result string onto the stack

## Type String Mappings

| Stack Value Type | typeof Result |
|------------------|---------------|
| F32 / F64        | "number"      |
| STRING / STR_LIST| "string"      |
| OBJECT           | "object"      |
| Unknown          | "undefined"   |

## Building and Running

```bash
# Build the test
./scripts/build_test.sh typeof_swf_5 native

# Run the test
./tests/typeof_swf_5/build/native/typeof_swf_5
```

## Files Modified

- `SWFRecomp/include/action/action.hpp` - Added `SWF_ACTION_TYPEOF = 0x3C` enum
- `SWFRecomp/src/action/action.cpp` - Added translation case for TYPEOF
- `SWFModernRuntime/include/actionmodern/action.h` - Added `actionTypeof` declaration
- `SWFModernRuntime/src/actionmodern/action.c` - Implemented `actionTypeof` function

## Notes

- The typeof operator in ActionScript 2.0 is similar to JavaScript's typeof operator
- Unlike JavaScript, ActionScript 2.0's `typeof null` returns "null" (not "object")
- The implementation currently supports the basic types available in the stack value type system
- Future extensions may include support for additional types like "function", "movieclip", "boolean", "null" when those stack types are implemented
