# BIT_XOR Opcode Test (0x62)

## Overview

This test validates the implementation of the BIT_XOR (ActionBitXor) opcode in SWFRecomp and SWFModernRuntime.

**Opcode**: 0x62
**Name**: BIT_XOR (ActionBitXor)
**Category**: Bitwise Logic
**Complexity**: SIMPLE

## Description

The BIT_XOR opcode pops two numbers off the stack, converts them to 32-bit unsigned integers, performs a bitwise XOR operation, and pushes the result as a signed 32-bit integer back onto the stack.

### Operation

1. Pop value `arg1` from stack
2. Pop value `arg2` from stack
3. Convert both to 32-bit unsigned integers (truncate floats)
4. Perform bitwise XOR: `result = arg2 ^ arg1`
5. Push result as signed 32-bit integer (stored as float) onto stack

### XOR Properties

- **Returns 1 when bits differ, 0 when bits match**
- **Identity**: `x ^ 0 = x`
- **Self-cancellation**: `x ^ x = 0`
- **Commutative**: `a ^ b = b ^ a`
- **Associative**: `(a ^ b) ^ c = a ^ (b ^ c)`
- **Self-inverse**: `(a ^ b) ^ b = a`

## Test Cases

### Test Case 1: Basic bitwise XOR
```actionscript
trace(12 ^ 10);  // 1100 ^ 1010 = 0110
```
**Expected output**: `6`

### Test Case 2: XOR with zero (identity property)
```actionscript
trace(42 ^ 0);  // Any value ^ 0 = value
```
**Expected output**: `42`

### Test Case 3: XOR with itself (self-cancellation)
```actionscript
trace(15 ^ 15);  // Any value ^ itself = 0
```
**Expected output**: `0`

### Test Case 4: Bit flipping
```actionscript
trace(170 ^ 85);  // 10101010 ^ 01010101 = 11111111
```
**Expected output**: `255`

### Test Case 5: Double XOR (self-inverse property)
```actionscript
trace((42 ^ 17) ^ 17);  // XOR same value twice returns original
```
**Expected output**: `42`

## Implementation

### Files Modified

1. **SWFRecomp/include/action/action.hpp:42** - Added enum `SWF_ACTION_BIT_XOR = 0x62`
2. **SWFRecomp/src/action/action.cpp:293-299** - Added translation case for BIT_XOR
3. **SWFModernRuntime/include/actionmodern/action.h:91** - Declared `actionBitXor` function
4. **SWFModernRuntime/src/actionmodern/action.c:1002-1026** - Implemented `actionBitXor` function

### Runtime Implementation

```c
void actionBitXor(char* stack, u32* sp)
{
    // Convert and pop second operand (a)
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert and pop first operand (b)
    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Convert to 32-bit signed integers (truncate, don't round)
    int32_t a_int = (int32_t)VAL(float, &a.data.numeric_value);
    int32_t b_int = (int32_t)VAL(float, &b.data.numeric_value);

    // Perform bitwise XOR
    int32_t result = b_int ^ a_int;

    // Push result as float (ActionScript stores all numbers as float)
    float result_f = (float)result;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_f));
}
```

## Building and Running

### Build the test
```bash
cd SWFRecomp
./scripts/build_test.sh bit_xor_swf_4 native
```

### Run the test
```bash
./tests/bit_xor_swf_4/build/native/bit_xor_swf_4
```

### Expected Output
```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
6
42
0
255
42
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

## Test Results

✅ All test cases passed:
- ✅ Basic XOR: `12 ^ 10 = 6`
- ✅ Identity: `42 ^ 0 = 42`
- ✅ Self-cancellation: `15 ^ 15 = 0`
- ✅ Bit flipping: `170 ^ 85 = 255`
- ✅ Self-inverse: `(42 ^ 17) ^ 17 = 42`

## Notes

- The opcode has no length field (it's a simple stack operation)
- Arguments are converted to 32-bit signed integers for the operation
- Result is stored as a float (ActionScript's internal number format)
- The C `^` operator performs bitwise XOR
- Very similar to BIT_AND (0x60) and BIT_OR (0x61) implementations

## References

- SWF File Format Specification v19
- ActionScript 2.0 Language Reference
- Implementation guide: `SWFRecompDocs/parallel-opcode-implementation-guide.md`
- Opcode specification: `SWFRecompDocs/prompts/opcode-bit-xor-0x62.md`
