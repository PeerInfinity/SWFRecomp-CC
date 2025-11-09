# Opcode Implementation Prompt: ActionPop (0x17)

## Opcode Specification

**Opcode Name**: ActionPop
**Hex Value**: 0x17
**Category**: Stack
**Estimated Complexity**: SIMPLE
**SWF Version**: 4+

## Description

Removes the top value from the stack and discards it. This is used to clean up unwanted values.

## Stack Operation

**Before**: `[... value]`
**After**: `[...]`

The top value is removed and discarded.

## Expected Behavior

1. Pop the top value from the stack
2. Discard it (no result pushed)

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_POP` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Implementation**: Uses the `POP()` macro directly

## Test Cases

### Test Case 1: Pop Single Value
```actionscript
// Push a value then pop it
push 42
pop
// Stack should be empty after pop
```

### Test Case 2: Pop After Expression
```actionscript
5 + 3;  // Result (8) pushed
pop;    // Remove result
// Stack should be empty
```

### Test Case 3: Multiple Pops
```actionscript
push 1
push 2
push 3
pop  // Stack: [1, 2]
pop  // Stack: [1]
pop  // Stack: []
```

## Similar Opcodes

- `actionPush` (0x96) - Push values onto stack
- `actionDuplicate` (0x3D) - Duplicate top value
- `actionStackSwap` (0x4C) - Swap top two values

## Notes

- This is a **stack manipulation** operation
- Value is discarded, not stored
- Common use: Remove unused expression results
- **Critical**: Never pop from an empty stack!
