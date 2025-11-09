# Opcode Implementation Prompt: ActionStackSwap (0x4D)

## Opcode Specification

**Opcode Name**: ActionStackSwap
**Hex Value**: 0x4D
**Category**: Stack
**Estimated Complexity**: SIMPLE
**SWF Version**: 5+

## Description

Swaps the top two values on the stack. This is a pure stack manipulation operation with no computation.

## Stack Operation

**Before**: `[... value2 value1]`
**After**: `[... value1 value2]`

The top two stack values are swapped in place.

## Expected Behavior

1. Get reference to top value (value1)
2. Get reference to second value (value2)
3. Swap their positions
4. Stack now has them in reversed order

**Stack Manipulation**:
- Does not pop values (they stay on stack)
- Does not create new values (just reorders)
- Preserves types and values exactly
- Useful for fixing operand order

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_STACK_SWAP` in `SWFRecomp/include/action/action.hpp`
- **Function**: `actionStackSwap()` in `SWFModernRuntime/src/actionmodern/action.c`
- **Tests**: Has test directory `stack_swap_swf_4/` ✅

## Test Cases

### Test Case 1: Swap Numbers
```actionscript
push 5
push 3
stackswap
// Stack now: [5, 3] instead of [3, 5]
trace  // Should output 5
trace  // Should output 3
```
**Expected output**:
```
5
3
```

### Test Case 2: Swap Different Types
```actionscript
push "hello"
push 42
stackswap
trace  // Should output "hello"
trace  // Should output 42
```
**Expected output**:
```
hello
42
```

### Test Case 3: Swap Then Operate
```actionscript
push 10
push 3
stackswap
subtract  // Now computes 3 - 10 = -7
trace
```
**Expected output**: `-7`

### Test Case 4: Multiple Swaps
```actionscript
push 1
push 2
stackswap  // [2, 1]
stackswap  // [1, 2] (back to original)
trace
trace
```
**Expected output**:
```
1
2
```

## Implementation Reference

This operation requires careful stack pointer manipulation:
- Must preserve exact values and types
- Must not corrupt memory
- Can be implemented by swapping stack entry structures
- Alternative: pop both, push in reversed order

## Similar Opcodes

- `actionDuplicate` (0x3D) - Duplicate top stack value
- `actionPop` (0x17) - Remove top value
- `actionPush` (0x96) - Push values onto stack

## Notes

- This is a **pure stack manipulation** opcode
- No type conversion
- No computation
- Useful for:
  - Fixing operand order for operations
  - Preparing stack for specific operation sequences
  - Implementing complex expressions
- Common in compiler-generated code
- **Critical**: Must preserve value types exactly
