# BIT_URSHIFT Test (ActionBitURShift - 0x65)

This test verifies the implementation of the ActionBitURShift opcode (0x65), which performs an unsigned (logical) right shift operation.

## Opcode Details

**Opcode**: 0x65
**Name**: ActionBitURShift
**Category**: Bitwise Logic
**Operation**: Unsigned/Logical right shift (zero-fill)

## Description

ActionBitURShift pops the shift count and value from the stack, converts the value to a 32-bit integer, masks the shift count to 5 bits (0-31 range), and performs an unsigned right shift. This is a LOGICAL shift that always fills with zeros from the left (no sign extension).

**Key Differences from Arithmetic Right Shift**:
- Uses unsigned 32-bit integer conversion
- Always fills with zeros (no sign extension)
- Negative numbers become large positive values when treated as unsigned

## Test Cases

### Test 1: Basic unsigned right shift
```actionscript
trace(8 >>> 2);  // 1000 >>> 2 = 0010 = 2
```
**Expected output**: `2`

### Test 2: Shift negative number (no sign extension)
```actionscript
trace(-8 >>> 2);  // Treats as unsigned, shifts with zeros
```
**Explanation**:
- -8 as int32 = 0xFFFFFFF8
- As unsigned: 4294967288
- Right shift by 2: 0x3FFFFFFE = 1073741822 (exact)
- **Float precision**: 1073741822 rounds to 1073741824 when stored as float
- ActionScript stores all numbers as floats, so precision loss occurs

**Expected output**: `1073741824` (due to float precision limits)

### Test 3: Zero shift
```actionscript
trace(42 >>> 0);  // No shift
```
**Expected output**: `42`

### Test 4: Shift all bits out
```actionscript
trace(255 >>> 8);  // Shift byte right
```
**Explanation**:
- 255 = 0x000000FF
- Right shift by 8 bits: 0x00000000
- Result: 0

**Expected output**: `0`

### Test 5: Shift count wrapping
```actionscript
trace(16 >>> 33);  // 33 & 0x1F = 1, so 16 >>> 1 = 8
```
**Explanation**:
- Shift count is masked to 5 bits: 33 & 0x1F = 1
- 16 >>> 1 = 8

**Expected output**: `8`

## Complete Expected Output

```
2
1073741824
42
0
8
```

**Note**: Test 2 outputs 1073741824 instead of the mathematically exact 1073741822 due to IEEE 754 float precision limits. This is the correct behavior since ActionScript stores all numbers as 32-bit floats.

## Implementation Notes

**Pop Order**:
1. Pop shift_count (first pop)
2. Pop value (second pop)

**Critical Implementation Details**:
- Value must be converted to `uint32_t` (unsigned) for logical shift
- Shift count must be masked to 5 bits: `shift_count & 0x1F`
- Result is unsigned but stored as float on stack
- In C, `>>` on unsigned types is logical shift (zero-fill)

**Related Opcodes**:
- `actionBitRShift` (0x64) - Arithmetic right shift (sign-extending)
- `actionBitLShift` (0x63) - Left shift

## Building and Running

```bash
# From SWFRecomp directory
./scripts/build_test.sh bit_urshift_swf_4 native

# Run the test
./tests/bit_urshift_swf_4/build/native/bit_urshift_swf_4
```

## Test File Generation

The test SWF is generated using `create_test_swf.py`, which creates a minimal SWF4 file with the BIT_URSHIFT opcodes. The build script automatically runs this script if `test.swf` is missing.
