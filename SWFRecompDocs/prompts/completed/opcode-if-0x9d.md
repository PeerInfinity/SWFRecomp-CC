# Opcode Implementation Prompt: ActionIf (0x9D)

## Opcode Specification

**Opcode Name**: ActionIf
**Hex Value**: 0x9D
**Category**: Control Flow
**Estimated Complexity**: MEDIUM
**SWF Version**: 4+

## Description

Conditional jump based on a boolean value. Pops a value from the stack, evaluates it as a boolean, and jumps if true.

## Operation

**Stack**: `[... condition] → [...]`
**Control Flow**: Jump by offset if condition is truthy

## Expected Behavior

1. Pop the condition value from the stack
2. Convert to boolean (truthy/falsy)
3. If truthy: Jump by the specified offset
4. If falsy: Continue to next instruction
5. Offset is 16-bit signed integer

**Truthy Values**:
- Non-zero numbers
- Non-empty strings
- Objects

**Falsy Values**:
- 0, 0.0
- Empty string ""
- null, undefined
- NaN

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_IF` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Tests**: Has test directory

## Test Cases

### Test Case 1: True Condition
```actionscript
push 1
if +5
push "skipped"
trace
:after
push "after"
trace
```
**Expected output**: `after`

### Test Case 2: False Condition
```actionscript
push 0
if +5
push "not skipped"
trace
push "after"
trace
```
**Expected output**:
```
not skipped
after
```

### Test Case 3: If-Else Pattern
```actionscript
var x = 5;
push x > 3
if +7
push "greater"
jump +5
:else
push "not greater"
:end
trace
```
**Expected output**: `greater`

### Test Case 4: Loop with If
```actionscript
var i = 0;
:loop
push i
trace
increment i
push i < 3
if loop  // Jump back if true
```
**Expected output**:
```
0
1
2
```

## Similar Opcodes

- `actionJump` (0x99) - Unconditional jump
- `actionEquals` (0x0E) - Comparison for condition
- `actionLess` (0x0F) - Comparison for condition

## Notes

- **Core control flow** opcode
- Consumes one stack value
- Offset is relative to position after instruction
- Recompiler translates to C `if (condition) goto label`
- Essential for if/else, while, for loops
- Positive offset: forward jump
- Negative offset: backward jump (loops)
