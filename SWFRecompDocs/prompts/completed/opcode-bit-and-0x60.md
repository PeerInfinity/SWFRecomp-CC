# Opcode Implementation Task: BIT_AND (0x60)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **BIT_AND**

## Opcode Specification

**Opcode Name**: BIT_AND
**Hex Value**: 0x60
**Category**: Logic/Bitwise
**Estimated Complexity**: SIMPLE (1-2 hours)
**SWF Version**: 5+

**Description**: Performs bitwise AND operation on two 32-bit integers.

**Operation**:
- Pop value `a` from stack
- Pop value `b` from stack
- Convert both to 32-bit signed integers
- Compute bitwise AND: `result = b & a`
- Push result as integer

**Expected Behavior**:
- Both operands converted to 32-bit signed integers
- Floating point values truncated (not rounded)
- Result is a 32-bit signed integer
- Bitwise AND operation performed

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_BIT_AND = 0x60` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionBitAnd(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create Python script to generate test.swf
6. **Setup Test Directory** - Create `SWFRecomp/tests/bit_and_swf_4/`
7. **Build and Verify** - Run `./scripts/build_test.sh bit_and_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic bitwise AND
```actionscript
trace(12 & 10);  // Binary: 1100 & 1010 = 1000
```
Expected output: `8`

### Test Case 2: All bits set
```actionscript
trace(15 & 7);  // Binary: 1111 & 0111 = 0111
```
Expected output: `7`

### Test Case 3: No common bits
```actionscript
trace(8 & 4);  // Binary: 1000 & 0100 = 0000
```
Expected output: `0`

### Test Case 4: Negative numbers (two's complement)
```actionscript
trace(-1 & 255);  // All bits set & 0xFF
```
Expected output: `255`

### Test Case 5: Floating point truncation
```actionscript
trace(12.7 & 10.3);  // Truncates to 12 & 10
```
Expected output: `8`

## Implementation Hints

**Pattern**: This is a binary bitwise operation. Similar structure to arithmetic operations but with integer conversion.

Reference these implemented opcodes:
- `actionAnd` in `SWFModernRuntime/src/actionmodern/action.c` - Logical AND (but this needs bitwise)
- `actionMultiply` in `SWFModernRuntime/src/actionmodern/action.c` - Binary operation pattern

**Implementation outline**:
```c
void actionBitAnd(char* stack, u32* sp)
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
    int32_t a_int = (int32_t)a.value.f32;
    int32_t b_int = (int32_t)b.value.f32;

    // Perform bitwise AND
    int32_t result = b_int & a_int;

    // Push result as float (ActionScript stores all numbers as float)
    float result_f = (float)result;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_f));
}
```

**Key Points**:
- Convert to `int32_t` for proper sign handling
- Truncate floating point values (cast to int, don't use round())
- Result should be pushed as float (ActionScript number type)
- Handle negative numbers with two's complement

## Type Conversion Notes

**Float to Integer Conversion**:
- Truncate (toward zero), don't round
- `12.7` → `12`
- `-12.7` → `-12`
- NaN → 0
- Infinity → 0 (or max/min int)

**Integer Range**:
- 32-bit signed integer: -2,147,483,648 to 2,147,483,647
- Values outside this range wrap around (two's complement)

## Creating the Test SWF

Create `SWFRecomp/tests/bit_and_swf_4/create_test_swf.py`:

```python
#!/usr/bin/env python3
import struct

# Test: 12 & 10 = 8
# Push 12.0
# Push 10.0
# BitAnd (0x60)
# Trace (0x26)

# See trace_swf_4/create_test_swf.py for SWF structure template
```

**Stack Order**: For `12 & 10`:
- Push 12.0 first (becomes `b`)
- Push 10.0 second (becomes `a`)
- Result: `12 & 10 = 8`

## Documentation

Create files:
- `SWFRecomp/tests/bit_and_swf_4/README.md` - Document test cases and expected output
- `SWFRecomp/tests/bit_and_swf_4/config.toml` - Copy from existing test
- `SWFRecomp/tests/bit_and_swf_4/create_test_swf.py` - SWF generator

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output: `8` for `12 & 10`
- [ ] No build errors or warnings
- [ ] Edge cases handled (negative numbers, floating point truncation)
- [ ] Bitwise operation correct (not logical AND)
- [ ] Integer conversion proper (truncate, not round)

## Build and Test Commands

```bash
# Build test
cd SWFRecomp
./scripts/build_test.sh bit_and_swf_4 native

# Run test
./tests/bit_and_swf_4/build/native/bit_and_swf_4

# Expected output:
# [Frame 0]
# 8
# [Tag] ShowFrame()
```

## Additional Test Ideas

After basic implementation works, consider testing:
- Bitwise AND with powers of 2 (masks)
- Large numbers close to INT32_MAX
- Negative numbers with different bit patterns
- Zero with various values

---

**Time Estimate**: 1-2 hours
**Difficulty**: Simple
**Dependencies**: None
**Reference Opcodes**: actionMultiply (0x0C), actionAnd (0x10) - structure reference only
**Note**: This is bitwise AND, not logical AND. Result is integer bitwise operation.
