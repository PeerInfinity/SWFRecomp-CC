# Opcode Implementation Prompt: ActionPush (0x96)

## Opcode Specification

**Opcode Name**: ActionPush
**Hex Value**: 0x96
**Category**: Stack
**Estimated Complexity**: MEDIUM
**SWF Version**: 4+

## Description

Pushes one or more literal values onto the stack. This is the most fundamental opcode for getting data onto the stack. It has a variable-length encoding with type tags.

## Stack Operation

**Before**: `[...]`
**After**: `[... value1 value2 ... valueN]`

## Expected Behavior

The Push opcode has a complex format:
1. Read the action length field
2. Read type byte
3. Read value based on type:
   - **Type 0**: String (null-terminated)
   - **Type 1**: Float (32-bit)
   - **Type 2**: null
   - **Type 3**: undefined
   - **Type 4**: Register number
   - **Type 5**: Boolean (0 or 1)
   - **Type 6**: Double (64-bit, not commonly used)
   - **Type 7**: Integer (32-bit)
   - **Type 8**: Constant pool index (8-bit)
   - **Type 9**: Constant pool index (16-bit)
4. Push value onto stack with appropriate type
5. Repeat for each value in the action

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_PUSH` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Implementation**: Handled specially in recompiler

## Test Cases

### Test Case 1: Push Integer
```
push 42
trace
```
**Expected output**: `42`

### Test Case 2: Push String
```
push "Hello"
trace
```
**Expected output**: `Hello`

### Test Case 3: Push Float
```
push 3.14
trace
```
**Expected output**: `3.14`

### Test Case 4: Push Multiple Values
```
push 1
push 2
add
trace
```
**Expected output**: `3`

### Test Case 5: Push Boolean
```
push true
trace
```
**Expected output**: `1` or `true`

## Similar Opcodes

- `actionPop` (0x17) - Remove value from stack
- `actionConstantPool` (0x88) - Define constant pool for push

## Notes

- **Most complex** opcode due to variable encoding
- Multiple type codes (0-9)
- Can push multiple values in one action
- Used extensively in every SWF
- Recompiler translates to direct C push calls
- Type tags determine how to interpret data
- Constant pool references resolve to string constants
