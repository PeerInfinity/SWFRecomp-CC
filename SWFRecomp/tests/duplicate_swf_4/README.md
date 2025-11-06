# DUPLICATE Opcode Test (0x3D)

## Test Description

This test verifies the implementation of the DUPLICATE opcode (0x3D), which duplicates the top value on the stack.

## Operation

**Opcode**: 0x3D (DUPLICATE)
**Category**: Stack Operations
**Flash Version**: SWF 4+

**Behavior**:
- Reads the top value from the stack (without popping)
- Pushes a duplicate copy of that value onto the stack
- Preserves both the type and value exactly

**Stack Diagram**:
```
Before:  ... | value |
After:   ... | value | value |
```

## Test Case

The test performs the following operations:
1. Push 42.0 to the stack
2. Call DUPLICATE (0x3D) to duplicate the value
3. Call ADD (0x0A) to add the two values
4. Call TRACE (0x26) to output the result

**Expected Output**: `84` (42 + 42)

## ActionScript Bytecode

```
PUSH 42.0        (0x96)
DUPLICATE        (0x3D)
ADD              (0x0A)
TRACE            (0x26)
END              (0x00)
```

## Implementation Notes

The `actionDuplicate` function:
- Handles all stack value types (numbers, strings, etc.)
- For strings, performs a shallow copy (both entries point to the same string data)
- Preserves the type, value, and (for strings) length and ID fields
- Does not modify the original value on the stack

## Build and Run

```bash
# Build the test
cd SWFRecomp
./scripts/build_test.sh duplicate_swf_4 native

# Run the test
./tests/duplicate_swf_4/build/native/duplicate_swf_4
```

## Success Criteria

- ✅ Output shows "84" (correct result)
- ✅ No crashes or segmentation faults
- ✅ Stack remains properly balanced
- ✅ Works with both numeric and string types
