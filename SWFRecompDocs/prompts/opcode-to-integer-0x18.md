# Opcode Implementation Task: TO_INTEGER (0x18)

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **TO_INTEGER**

## Opcode Specification

**Opcode Name**: TO_INTEGER
**Hex Value**: 0x18
**Category**: Type Conversion
**Estimated Complexity**: SIMPLE (1-2 hours)
**SWF Version**: 4+

**Description**: Converts the top stack value to a 32-bit signed integer.

**Operation**:
- Pop value from stack
- Convert to 32-bit signed integer
- Push integer result (as float type)

**Expected Behavior**:
- Floating point values are truncated (toward zero)
- Strings are parsed as numbers first, then converted to integer
- Boolean true → 1, false → 0
- null/undefined → 0
- NaN → 0
- Infinity → 0 (or INT32_MAX/MIN depending on implementation)
- Result pushed as ActionScript number (float storage)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_TO_INTEGER = 0x18` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add `void actionToInteger(char* stack, u32* sp);` to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create Python script to generate test.swf
6. **Setup Test Directory** - Create `SWFRecomp/tests/to_integer_swf_4/`
7. **Build and Verify** - Run `./scripts/build_test.sh to_integer_swf_4 native`

## Test Cases

### Test Case 1: Truncate positive float
```actionscript
trace(toInteger(12.7));
```
Expected output: `12`

### Test Case 2: Truncate negative float
```actionscript
trace(toInteger(-12.7));
```
Expected output: `-12`

### Test Case 3: Already an integer
```actionscript
trace(toInteger(42));
```
Expected output: `42`

### Test Case 4: Zero
```actionscript
trace(toInteger(0.5));
```
Expected output: `0`

### Test Case 5: Large number within int32 range
```actionscript
trace(toInteger(2147483647));  // INT32_MAX
```
Expected output: `2147483647`

## Implementation Hints

**Pattern**: This is a unary type conversion operation.

Reference these utility functions:
- `convertFloat` in `SWFModernRuntime/src/actionmodern/action.c` - Conversion utilities
- `actionNot` in `SWFModernRuntime/src/actionmodern/action.c` - Unary operation pattern

**Implementation outline**:
```c
void actionToInteger(char* stack, u32* sp)
{
    // Convert to float first (handles string to number conversion)
    convertFloat(stack, sp);

    // Pop the value
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert to 32-bit signed integer (truncate toward zero)
    int32_t int_value = (int32_t)a.value.f32;

    // Convert back to float for pushing (ActionScript stores numbers as float)
    float result = (float)int_value;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Key Points**:
- Truncate toward zero: `12.7` → `12`, `-12.7` → `-12`
- Don't use `round()`, use simple cast to `int32_t`
- Handle special values: NaN → 0, Infinity → 0
- Result is pushed as float (ActionScript number type)

## Type Conversion Rules

**Numbers to Integer**:
- Positive: `12.7` → `12` (truncate decimal)
- Negative: `-12.7` → `-12` (truncate toward zero)
- Zero: `0.5` → `0`, `-0.5` → `0`

**Special Values**:
- NaN → `0`
- +Infinity → `0` (or INT32_MAX)
- -Infinity → `0` (or INT32_MIN)

**Range**:
- 32-bit signed integer: -2,147,483,648 to 2,147,483,647
- Values outside range wrap (two's complement)

## Creating the Test SWF

Create `SWFRecomp/tests/to_integer_swf_4/create_test_swf.py`:

```python
#!/usr/bin/env python3
import struct

# Test: toInteger(12.7) = 12
# Push 12.7
# ToInteger (0x18)
# Trace (0x26)

# See trace_swf_4/create_test_swf.py for complete SWF structure
```

## ActionScript Note

**Note**: In ActionScript 1/2, there isn't a built-in `toInteger()` function. This opcode is used internally by the VM. To test it in ActionScript, you would write:
```actionscript
var x = 12.7;
var y = int(x);  // This compiles to ToInteger opcode
trace(y);
```

Or directly push and use the opcode in your test SWF generator.

## Documentation

Create files:
- `SWFRecomp/tests/to_integer_swf_4/README.md` - Explain conversion rules and test cases
- `SWFRecomp/tests/to_integer_swf_4/config.toml` - Standard config
- `SWFRecomp/tests/to_integer_swf_4/create_test_swf.py` - SWF generator

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output: `12` for input `12.7`
- [ ] No build errors or warnings
- [ ] Truncation works correctly (toward zero)
- [ ] Negative numbers handled correctly
- [ ] Special values (NaN, Infinity) converted to 0
- [ ] Result is proper ActionScript number (float storage)

## Build and Test Commands

```bash
# Build test
cd SWFRecomp
./scripts/build_test.sh to_integer_swf_4 native

# Run test
./tests/to_integer_swf_4/build/native/to_integer_swf_4

# Expected output:
# [Frame 0]
# 12
# [Tag] ShowFrame()
```

## Edge Cases to Consider

After basic implementation:
- Very large floats that exceed int32 range
- Very small floats close to zero
- Negative zero
- Positive and negative infinity
- NaN values
- String-to-number-to-integer conversion chain

## Related Opcodes

- **TO_NUMBER (0x4A)**: Converts to number (float)
- **TO_STRING (0x4B)**: Converts to string
- **TYPEOF (0x3C)**: Returns type as string

These follow similar patterns but with different conversion logic.

---

**Time Estimate**: 1-2 hours
**Difficulty**: Simple
**Dependencies**: None (convertFloat utility already exists)
**Reference Opcodes**: convertFloat utility, actionNot (unary pattern)
**Category**: Type Conversion
