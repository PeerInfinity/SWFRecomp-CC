# Bitwise AND Test (BIT_AND - 0x60)

This test verifies the implementation of the BIT_AND opcode (0x60) for ActionScript 2.

## Test Case

**Operation**: `12 & 10`

**Binary representation**:
- 12 = `1100`
- 10 = `1010`
- Result = `1000` = 8

**Expected output**: `8`

## Implementation Details

- **Opcode**: 0x60
- **Category**: Logic/Bitwise
- **Operation**: Performs bitwise AND on two 32-bit signed integers

## Stack Behavior

1. Push 12.0 onto stack
2. Push 10.0 onto stack
3. BIT_AND pops both values, converts to int32, performs `12 & 10`, pushes result (8.0)
4. TRACE pops and prints the result

## Expected Output

```
[Frame 0]
8
[Tag] ShowFrame()
```

## Building and Running

```bash
# From SWFRecomp directory
./scripts/build_test.sh bit_and_swf_4 native

# Run the test
./tests/bit_and_swf_4/build/native/bit_and_swf_4
```

## Additional Test Cases Covered by Implementation

The implementation should also handle:
- All bits set: `15 & 7 = 7`
- No common bits: `8 & 4 = 0`
- Negative numbers: `-1 & 255 = 255`
- Floating point truncation: `12.7 & 10.3 = 8` (truncates to 12 & 10)
