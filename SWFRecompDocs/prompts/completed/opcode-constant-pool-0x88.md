# Opcode Implementation Prompt: ActionConstantPool (0x88)

## Opcode Specification

**Opcode Name**: ActionConstantPool
**Hex Value**: 0x88
**Category**: Special
**Estimated Complexity**: MEDIUM
**SWF Version**: 5+

## Description

Defines a constant pool of strings that can be referenced by subsequent Push actions. This is an optimization to reduce file size when the same strings are used multiple times.

## Operation

**Stack**: No stack operation
**Effect**: Stores constant strings for later reference

## Expected Behavior

1. Read count of strings (16-bit)
2. For each string:
   - Read null-terminated string
   - Store in constant pool array
3. Pool persists for rest of frame/script
4. Push actions can reference by index

**Constant Pool Structure**:
- Array of strings
- Indexed from 0
- Pool is cleared at frame boundary (or script boundary)
- Push type 8 (8-bit index) or type 9 (16-bit index) reference pool

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_CONSTANT_POOL` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Implementation**: Stores strings for Push actions

## Test Cases

### Test Case 1: Basic Constant Pool
```
constantPool ["hello", "world"]
push 0  // Push constant pool index 0
trace
push 1  // Push constant pool index 1
trace
```
**Expected output**:
```
hello
world
```

### Test Case 2: Repeated Strings
```
constantPool ["message"]
push 0
trace
push 0  // Reference same string again
trace
```
**Expected output**:
```
message
message
```

### Test Case 3: Large Pool
```
constantPool ["a", "b", "c", "d", "e"]
push 2  // "c"
trace
push 4  // "e"
trace
push 0  // "a"
trace
```
**Expected output**:
```
c
e
a
```

## Similar Opcodes

- `actionPush` (0x96) - Push values (can reference constant pool)

## Notes

- **Optimization** opcode - reduces SWF file size
- Recompiler translates to string constants array
- Push type 8: 1-byte pool index (0-255)
- Push type 9: 2-byte pool index (0-65535)
- Pool lifetime: Current script/frame
- Common in compiler-generated SWF files
- Not used in hand-written bytecode typically
