# Opcode Implementation Task: GREATER (0x48)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **GREATER**

## Opcode Specification

**Opcode Name**: GREATER
**Hex Value**: 0x48
**Category**: Comparison
**Estimated Complexity**: SIMPLE (1-2 hours)
**SWF Version**: 5+

**Description**: Compares two numbers and returns true if the second popped value is greater than the first popped value.

**Operation**:
- Pop value `a` from stack
- Pop value `b` from stack
- Compare: is `b > a`?
- Push result as boolean (1.0 for true, 0.0 for false)

**Expected Behavior**:
- Both operands are converted to numbers if needed
- Result is pushed as a float: 1.0 (true) or 0.0 (false)
- Follows ActionScript comparison semantics
- NaN comparisons return false
- String-to-number conversion follows AS2 rules

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_GREATER = 0x48` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionGreater(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create Python script to generate test.swf
6. **Setup Test Directory** - Create `SWFRecomp/tests/greater_swf_4/` with config.toml and create_test_swf.py
7. **Build and Verify** - Run `./scripts/build_test.sh greater_swf_4 native` and verify output

## Test Cases

### Test Case 1: Basic greater than (true)
```actionscript
trace(5 > 3);
```
Expected output: `1`

### Test Case 2: Basic greater than (false)
```actionscript
trace(3 > 5);
```
Expected output: `0`

### Test Case 3: Equal values
```actionscript
trace(5 > 5);
```
Expected output: `0`

### Test Case 4: Floating point comparison
```actionscript
trace(5.5 > 3.2);
```
Expected output: `1`

### Test Case 5: Edge case - zero comparison
```actionscript
trace(1 > 0);
```
Expected output: `1`

## Implementation Hints

**Pattern**: This is a binary comparison operation, similar to LESS and EQUALS.

Reference these implemented opcodes:
- `actionLess` in `SWFModernRuntime/src/actionmodern/action.c` - Very similar pattern
- `actionEquals` in `SWFModernRuntime/src/actionmodern/action.c` - Comparison structure

**Implementation outline**:
```c
void actionGreater(char* stack, u32* sp)
{
    // Convert and pop second operand (a)
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert and pop first operand (b)
    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Perform comparison: b > a
    float result = (b.value.f32 > a.value.f32) ? 1.0f : 0.0f;

    // Push boolean result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Key Points**:
- Use `convertFloat()` to ensure numeric comparison
- Stack order: first pop gets `a`, second pop gets `b`, result is `b > a`
- Boolean result must be 1.0 or 0.0 (float)
- Handle NaN: Any comparison with NaN returns false

## Creating the Test SWF

Create `SWFRecomp/tests/greater_swf_4/create_test_swf.py`:

```python
#!/usr/bin/env python3
import struct

# SWF Header (uncompressed, version 4)
header = bytes([
    0x46, 0x57, 0x53, 0x04,  # FWS + version 4
    0x00, 0x00, 0x00, 0x00,  # File length (placeholder)
])

# Frame size: 0x8000 twips = 400 pixels (minimal)
# ... (see trace_swf_4/create_test_swf.py for full structure)

# DoAction tag with:
# - Push 5.0
# - Push 3.0
# - Greater (0x48)
# - Trace (0x26)

# Build and write test.swf
# (See existing create_test_swf.py examples for complete implementation)
```

**Important**: Remember stack order! For `5 > 3`:
- Push 5.0 first (becomes `b`, second pop)
- Push 3.0 second (becomes `a`, first pop)
- Result: `5.0 > 3.0 = 1`

## Documentation

Create these files as you work:
- `SWFRecomp/tests/greater_swf_4/README.md` - Test description and expected output
- `SWFRecomp/tests/greater_swf_4/config.toml` - Copy from trace_swf_4
- `SWFRecomp/tests/greater_swf_4/create_test_swf.py` - SWF generation script

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Edge cases handled correctly
- [ ] Code follows pattern of actionLess (same structure, opposite comparison)
- [ ] NaN handling correct (NaN > x returns false, x > NaN returns false)

## Build and Test Commands

```bash
# Build SWFRecomp (if not already built)
cd SWFRecomp && mkdir -p build && cd build && cmake .. && make && cd ../..

# Build test
cd SWFRecomp
./scripts/build_test.sh greater_swf_4 native

# Run test
./tests/greater_swf_4/build/native/greater_swf_4

# Expected output:
# ==> SWF Execution Started (NO_GRAPHICS mode) ===
# [Frame 0]
# 1
# [Tag] ShowFrame()
# === SWF Execution Completed ===
```

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Time Estimate**: 1-2 hours
**Difficulty**: Simple
**Dependencies**: None (all prerequisites implemented)
**Reference Opcodes**: actionLess (0x0F), actionEquals (0x0E)
