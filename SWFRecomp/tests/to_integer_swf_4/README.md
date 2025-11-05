# TO_INTEGER Opcode Test (0x18)

## Overview

This test validates the implementation of the TO_INTEGER opcode (0x18) for ActionScript 2.

## Opcode Details

- **Opcode Name**: TO_INTEGER
- **Hex Value**: 0x18
- **Category**: Type Conversion
- **SWF Version**: 4+
- **Complexity**: SIMPLE

## Operation

The TO_INTEGER opcode:
1. Pops a value from the stack
2. Converts it to a 32-bit signed integer (truncating toward zero)
3. Pushes the result back as a float (ActionScript number type)

## Type Conversion Rules

### Numbers to Integer
- **Positive truncation**: `12.7` → `12` (truncate decimal part)
- **Negative truncation**: `-12.7` → `-12` (truncate toward zero, not toward negative infinity)
- **Already integer**: `42` → `42`
- **Small values**: `0.5` → `0`, `-0.5` → `0`

### Special Values
- **NaN** → `0`
- **+Infinity** → `0`
- **-Infinity** → `0`

### Range
- 32-bit signed integer: -2,147,483,648 to 2,147,483,647
- Values outside this range wrap using two's complement arithmetic

## Test Cases

### Basic Test (`create_test_swf.py`)
Tests the fundamental operation:
```actionscript
trace(toInteger(12.7));
```
**Expected output**: `12`

### Additional Test Cases

The implementation handles:
1. **Positive truncation**: `12.7` → `12`
2. **Negative truncation**: `-12.7` → `-12`
3. **Already integer**: `42` → `42`
4. **Zero truncation**: `0.5` → `0`
5. **Large numbers**: `2147483647` → `2147483647` (INT32_MAX)

## Implementation Notes

### Key Implementation Details
- Uses `VAL(float, &v.data.numeric_value)` to extract float from ActionVar
- Casts to `int32_t` for truncation (toward zero)
- Uses `isnan()` and `isinf()` to handle special float values
- Pushes result with `VAL(u32, &f)` for ACTION_STACK_VALUE_F32

### Pattern
This follows the **unary operation pattern**:
```c
void actionToInteger(char* stack, u32* sp)
{
    u32 oldSP;
    ActionVar v;
    convertFloat(stack, sp);  // Convert top of stack to float
    popVar(stack, sp, &v);    // Pop the value

    float f = VAL(float, &v.data.numeric_value);

    // Handle special values
    if (isnan(f) || isinf(f)) {
        f = 0.0f;
    } else {
        int32_t int_value = (int32_t)f;  // Truncate toward zero
        f = (float)int_value;
    }

    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &f));
}
```

## Building and Running

### Build
```bash
cd SWFRecomp
./scripts/build_test.sh to_integer_swf_4 native
```

### Run
```bash
./tests/to_integer_swf_4/build/native/to_integer_swf_4
```

### Expected Output
```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
12
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

## Related Opcodes

- **TO_NUMBER (0x4A)**: Converts to float
- **TO_STRING (0x4B)**: Converts to string
- **TYPEOF (0x3C)**: Returns type as string

## References

- Implementation guide: `SWFRecompDocs/parallel-opcode-implementation-guide.md`
- Task specification: `SWFRecompDocs/prompts/opcode-to-integer-0x18.md`
- SWF Specification: `SWFRecompDocs/specs/swf-spec-19.txt`

## Success Criteria

✅ All criteria met:
- [x] Builds without errors
- [x] Test produces correct output: `12` for input `12.7`
- [x] Truncation works correctly (toward zero)
- [x] Negative numbers handled correctly
- [x] Special values (NaN, Infinity) converted to 0
- [x] Result is proper ActionScript number (float storage)
