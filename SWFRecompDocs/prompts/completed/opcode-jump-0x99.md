# Opcode Implementation Prompt: ActionJump (0x99)

## Opcode Specification

**Opcode Name**: ActionJump
**Hex Value**: 0x99
**Category**: Control Flow
**Estimated Complexity**: MEDIUM
**SWF Version**: 4+

## Description

Unconditional jump to a different location in the bytecode. Changes the instruction pointer by a specified offset. This is used for implementing loops, unconditional branches, and control flow.

## Operation

**Stack**: No stack operation
**Control Flow**: Jump by specified offset

## Expected Behavior

1. Read the 16-bit signed offset from the action data
2. Add offset to the current instruction pointer
3. Continue execution at the new location

**Offset Calculation**:
- Offset is signed 16-bit integer
- Measured in bytes from current position
- Positive offset: jump forward
- Negative offset: jump backward (loops)
- Offset is relative to the byte AFTER this instruction

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_JUMP` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Tests**: Has test directory with conditional tests

## Test Cases

### Test Case 1: Jump Forward
```
push 1
trace
jump +5  // Skip next instruction
push 2   // This is skipped
trace
push 3
trace
```
**Expected output**:
```
1
3
```

### Test Case 2: Infinite Loop (with exit)
```
:loop
push counter
trace
increment counter
jump loop  // Jump back
```

### Test Case 3: Skip Code Block
```
push "before"
trace
jump +10
push "skipped"  // Not executed
trace           // Not executed
push "after"
trace
```
**Expected output**:
```
before
after
```

## Similar Opcodes

- `actionIf` (0x9D) - Conditional jump
- `actionCall` (0x9E) - Function call (different kind of jump)

## Notes

- **Critical for control flow**
- Recompiler translates to C `goto` statements
- Must calculate jump targets correctly
- Negative offsets create loops
- Used in: loops, if/else, switch statements
- No stack manipulation
- **Caution**: Infinite loops possible if not careful
