# ADD2 Opcode Test (0x47)

## Overview

This test verifies the implementation of the **ADD2** (Type-Aware Addition) opcode.

**Opcode**: 0x47
**Name**: ADD2
**SWF Version**: 5+
**Category**: Utility Operations / Arithmetic

## Description

ADD2 performs type-aware addition following ECMA-262 specification rules:
- If either operand is a string → performs string concatenation
- Otherwise → converts both operands to numbers and performs numeric addition

This is different from the basic ADD (0x0A) opcode, which may not have the same type awareness.

## Test Cases

### Test 1: Number + Number
```actionscript
trace(5 + 3);
```
**Expected Output**: `8`

### Test 2: String + Number
```actionscript
trace("Total: " + 42);
```
**Expected Output**: `Total: 42`

### Test 3: Number + String
```actionscript
trace(5 + " items");
```
**Expected Output**: `5 items`

## Implementation Details

### Type Coercion Rules (ECMA-262)

1. **If either operand is a string**:
   - Convert both operands to strings
   - Concatenate left + right
   - Result is a string

2. **If both operands are numeric**:
   - Convert both to numbers (if needed)
   - Perform numeric addition
   - Result is a number

### Type Conversion

**To String**:
- String → String (no conversion)
- Number → String (formatted as decimal, e.g., "42")
- Boolean → String ("true" or "false") or Number (1 or 0)
- null → String ("null") or Number (0)
- undefined → String ("undefined") or Number (NaN)

**To Number**:
- Number → Number (no conversion)
- String → Number (parsed, empty string → 0, invalid → NaN)
- Boolean → Number (true → 1, false → 0)
- null → Number (0)
- undefined → Number (NaN)

## Differences from ADD (0x0A)

| Feature | ADD (0x0A) | ADD2 (0x47) |
|---------|------------|-------------|
| Type Awareness | Basic/None | Full ECMA-262 |
| String Concatenation | No | Yes |
| SWF Version | 4+ | 5+ |
| Use Case | Simple numeric addition | General-purpose + operator |

## Bug Fixes

During implementation, a bug was discovered in the `convertString` function where it was reading from `STACK_TOP_VALUE` after overwriting it. The fix saves the float value before modifying the stack:

```c
// Before (buggy):
VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
snprintf(var_str, 17, "%.15g", VAL(float, &STACK_TOP_VALUE));  // Wrong!

// After (fixed):
float temp_val = VAL(float, &STACK_TOP_VALUE);  // Save first
VAL(u64, &STACK_TOP_VALUE) = (u64) var_str;
snprintf(var_str, 17, "%.15g", temp_val);  // Correct!
```

## Build and Run

```bash
# Build the test
cd SWFRecomp
./scripts/build_test.sh add2_swf_5 native

# Run the test
./tests/add2_swf_5/build/native/add2_swf_5
```

## Expected Console Output

```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
8
Total: 42
5 items
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

## Implementation Files

- **Enum Definition**: `SWFRecomp/include/action/action.hpp:38`
- **Translation**: `SWFRecomp/src/action/action.cpp:261-270`
- **Runtime Declaration**: `SWFModernRuntime/include/actionmodern/action.h:74`
- **Runtime Implementation**: `SWFModernRuntime/src/actionmodern/action.c:139-207`

## Related Opcodes

- **ADD (0x0A)**: Basic numeric addition
- **STRING_ADD (0x21)**: String concatenation (may not have type checking)
- **TO_STRING (0x4B)**: Explicit string conversion
- **TO_NUMBER (0x4A)**: Explicit numeric conversion
