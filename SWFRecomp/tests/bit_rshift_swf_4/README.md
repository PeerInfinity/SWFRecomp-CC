# BIT_RSHIFT Opcode Test (0x64)

## Overview

This test verifies the implementation of the **ActionBitRShift** opcode (0x64) for ActionScript 2. This opcode performs an **arithmetic right shift** (sign-extending) on a 32-bit signed integer.

## Opcode Specification

- **Opcode**: 0x64
- **Name**: ActionBitRShift
- **Category**: Bitwise Logic
- **Operation**: Pops shift count, pops value, shifts value right (arithmetic), pushes result

### Behavior

1. Pop `shift_count` from stack (top)
2. Pop `value` from stack (second)
3. Convert both to 32-bit signed integers
4. Mask `shift_count` to 5 bits (0-31 range): `shift_count & 0x1F`
5. Perform arithmetic right shift: `result = value >> shift_count`
6. Push `result` as signed 32-bit integer (stored as float)

### Key Properties

- **Arithmetic Shift**: The sign bit is preserved (extended)
  - Positive numbers: zeros fill from the left
  - Negative numbers: ones fill from the left (sign extension)
- **Shift Count Masking**: Only the least significant 5 bits of shift count are used (0-31)
- **Division by Power of 2**: Right shift by n divides by 2^n (for positive numbers)

## Test Cases

### Test 1: Basic Right Shift
```actionscript
trace(8 >> 2);  // 1000 >> 2 = 0010 = 2
```
**Expected Output**: `2`

### Test 2: Divide by Power of 2
```actionscript
trace(20 >> 2);  // 20 / 4 = 5
```
**Expected Output**: `5`

### Test 3: Sign Extension (Negative Number)
```actionscript
trace(-8 >> 2);  // Sign bit extends: 11111000 >> 2 = 11111110 = -2
```
**Expected Output**: `-2`

This test verifies that negative numbers remain negative when shifted right (arithmetic shift behavior).

### Test 4: Zero Shift
```actionscript
trace(42 >> 0);  // No shift
```
**Expected Output**: `42`

### Test 5: Shift Count Wrapping
```actionscript
trace(16 >> 33);  // 33 & 0x1F = 1, so 16 >> 1 = 8
```
**Expected Output**: `8`

This test verifies that shift counts greater than 31 wrap around using only the lower 5 bits.

## Expected Output

```
2
5
-2
42
8
```

## Test Results

All test cases pass successfully:
- ✅ Basic right shift works correctly
- ✅ Division by power of 2 works correctly
- ✅ Sign extension preserves negative sign
- ✅ Zero shift returns original value
- ✅ Shift count masking works correctly

## Implementation Details

### Files Modified

1. **SWFRecomp/include/action/action.hpp**
   - Added `SWF_ACTION_BIT_RSHIFT = 0x64` enum

2. **SWFRecomp/src/action/action.cpp**
   - Added translation case for BIT_RSHIFT opcode

3. **SWFModernRuntime/include/actionmodern/action.h**
   - Added `void actionBitRShift(char* stack, u32* sp);` declaration

4. **SWFModernRuntime/src/actionmodern/action.c**
   - Implemented `actionBitRShift()` function

### Stack Order

For the operation `value >> shift_count`:
1. Push `value` first (bottom)
2. Push `shift_count` second (top)
3. Pop `shift_count` (from top)
4. Pop `value` (from below)
5. Compute `value >> shift_count`

### Key Implementation Points

- Uses `int32_t` for signed integer arithmetic
- Shift count is masked with `& 0x1F` to ensure 0-31 range
- In C, the `>>` operator on signed integers performs arithmetic shift automatically
- Result is converted back to float for pushing onto the ActionScript stack

## Comparison with Other Shift Operations

| Opcode | Name | Type | Sign Extension |
|--------|------|------|----------------|
| 0x64 | BIT_RSHIFT | Arithmetic Right | Yes (preserves sign) |
| 0x63 | BIT_LSHIFT | Left Shift | N/A |
| 0x65 | BIT_URSHIFT | Logical Right | No (fills with zeros) |

The key difference from logical right shift (if implemented) is that arithmetic right shift extends the sign bit, keeping negative numbers negative.

## Build and Run

```bash
cd SWFRecomp
./scripts/build_test.sh bit_rshift_swf_4 native
./tests/bit_rshift_swf_4/build/native/bit_rshift_swf_4
```

## Implementation Date

2025-11-05

## Notes

- This is a simple bitwise operation opcode (estimated 1-2 hours)
- Arithmetic right shift is important for maintaining sign in integer arithmetic
- The opcode has no length field (it's a simple stack operation)
- All numeric values in ActionScript are stored as floats, even when treated as integers
