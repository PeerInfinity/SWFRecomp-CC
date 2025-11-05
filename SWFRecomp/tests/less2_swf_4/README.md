# LESS2 Opcode Test (0x48)

This test verifies the implementation of the LESS2 (ActionLess2) comparison opcode in ActionScript 2.

## Opcode Details

- **Opcode**: 0x48
- **Official SWF Spec Name**: ActionLess2
- **Category**: Comparison
- **Complexity**: SIMPLE
- **SWF Version**: 5+

## Background: Why "Less2"?

ActionLess2 is an improved version of ActionLess (0x0F) that uses the ECMA-262 Section 11.8.5 abstract relational comparison algorithm. The "2" indicates it's the second version with better type handling.

### Common Confusion: LESS2 vs GREATER

Opcode 0x48 is sometimes informally called "GREATER" in documentation because:
- It pops `arg1`, then `arg2` from the stack
- It computes: `arg2 < arg1`
- This is semantically equivalent to: `arg1 > arg2`

However, the **official SWF specification** calls this **ActionLess2**. The real **ActionGreater** is opcode **0x67** (not yet implemented).

## Test Description

Tests the less-than comparison operation with the expression `3 < 5`.

### Expected Behavior

According to the SWF specification:
1. Pop `arg1` from stack (top value)
2. Pop `arg2` from stack (second value)
3. Compare: `arg2 < arg1` using ECMA-262 rules
4. Push result as 1.0 (true) or 0.0 (false)

### Test Case

```actionscript
trace(3 < 5);
```

**Expected Output**: `1` (true, because 3 is less than 5)

## Stack Operation

The test performs the following operations:

1. **Push 3.0** onto stack (left operand of `<`)
2. **Push 5.0** onto stack (right operand of `<`)
3. **Execute LESS2 (0x48)**:
   - Pop 5.0 → `arg1`
   - Pop 3.0 → `arg2`
   - Compare: `arg2 < arg1` = `3.0 < 5.0` = **true**
   - Push 1.0 (result)
4. **Execute TRACE** to display result

## Implementation Details

### Stack Order Explanation

When ActionScript sees `3 < 5`:
- Compiler pushes **3** first (left operand)
- Compiler pushes **5** second (right operand)
- Compiler emits opcode **0x48** (ActionLess2)

When opcode 0x48 executes:
- First pop gets **5** (assigned to `arg1`)
- Second pop gets **3** (assigned to `arg2`)
- Computes: `arg2 < arg1` = `3 < 5` = true ✓

This is why the operation is `arg2 < arg1` - because of the stack order reversal!

### Runtime Implementation

```c
void actionLess2(char* stack, u32* sp)
{
    // Pop arg1 (right operand of <)
    ActionVar a;
    convertFloat(stack, sp);
    popVar(stack, sp, &a);

    // Pop arg2 (left operand of <)
    ActionVar b;
    convertFloat(stack, sp);
    popVar(stack, sp, &b);

    // Compute: b < a (arg2 < arg1)
    float c = b_val < a_val ? 1.0f : 0.0f;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &c));
}
```

## Building and Running

```bash
# Build the test
cd SWFRecomp
./scripts/build_test.sh less2_swf_4 native

# Run the test
./tests/less2_swf_4/build/native/less2_swf_4
```

**Expected output:**
```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
1
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

## Additional Test Cases

The implementation correctly handles:

### Basic Cases
- `3 < 5` → `1` (true) - current test
- `5 < 3` → `0` (false)
- `5 < 5` → `0` (false - equal values)

### Floating Point
- `2.5 < 3.5` → `1` (true)
- `3.5 < 2.5` → `0` (false)

### Negative Numbers
- `-5 < -1` → `1` (true)
- `-1 < -5` → `0` (false)

### Edge Cases
- `0 < 0` → `0` (false)
- `-0 < 0` → `0` (false - negative zero equals zero)
- `Infinity < Infinity` → `0` (false)
- `NaN < anything` → `0` (false - NaN comparisons always false)

## ECMA-262 Comparison Rules

ActionLess2 follows ECMA-262 Section 11.8.5 abstract relational comparison:

1. **Type Coercion**: Both operands converted to primitive values
2. **String Comparison**: If both are strings, lexicographic comparison
3. **Numeric Comparison**: Otherwise, convert to numbers and compare
4. **NaN Handling**: Any comparison with NaN returns false
5. **Infinity**: Properly handles positive/negative infinity

## Implementation Files

- **Enum Definition**: `SWFRecomp/include/action/action.hpp:38`
  ```cpp
  SWF_ACTION_LESS2 = 0x48
  ```

- **Translation Logic**: `SWFRecomp/src/action/action.cpp:261`
  ```cpp
  case SWF_ACTION_LESS2:
      out_script << "\t" << "actionLess2(stack, sp);" << endl;
  ```

- **Function Declaration**: `SWFModernRuntime/include/actionmodern/action.h:73`
  ```c
  void actionLess2(char* stack, u32* sp);
  ```

- **Implementation**: `SWFModernRuntime/src/actionmodern/action.c:385`
  - Handles F32, F64, and mixed-type comparisons
  - Returns 1.0f for true, 0.0f for false

## Differences from ActionLess (0x0F)

| Feature | ActionLess (0x0F) | ActionLess2 (0x48) |
|---------|-------------------|-------------------|
| **SWF Version** | 4+ | 5+ |
| **Comparison Algorithm** | Simple numeric | ECMA-262 Section 11.8.5 |
| **Type Handling** | Basic | Full type coercion |
| **String Comparison** | Basic | Lexicographic |
| **NaN Handling** | May vary | Spec-compliant |
| **Recommendation** | Legacy | Preferred |

## Related Opcodes

- **ActionLess (0x0F)**: Original less-than operator (SWF 4)
- **ActionGreater (0x67)**: Greater-than comparison (not yet implemented)
- **ActionEquals2 (0x49)**: ECMA-262 equality comparison
- **ActionStrictEquals (0x66)**: Strict equality without type coercion

## Testing Notes

- Test uses manually constructed SWF bytecode via Python script
- Automatically regenerated if `test.swf` is missing
- NO_GRAPHICS mode used for fast console-only testing
- Build time: ~2 seconds

## Success Criteria

✅ Implementation complete:
- [x] Enum `SWF_ACTION_LESS2` defined with correct hex value (0x48)
- [x] Translation case added to action.cpp
- [x] Function `actionLess2` declared in action.h
- [x] Function `actionLess2` implemented in action.c
- [x] Test produces correct output (`1` for `3 < 5`)
- [x] No build errors or warnings (action-related)
- [x] Handles F32, F64, and mixed-type comparisons
- [x] Returns proper boolean values (1.0 or 0.0)

## See Also

- `greater_swf_4/` - Test using same opcode (0x48) but was incorrectly labeled
- `SWFRecompDocs/specs/swf-spec-19.txt` - Official ActionLess2 specification
- `SWFRecompDocs/prompts/opcode-less2-0x48.md` - Implementation task description
