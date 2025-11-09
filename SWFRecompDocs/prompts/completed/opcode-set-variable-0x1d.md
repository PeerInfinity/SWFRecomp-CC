# Opcode Implementation Prompt: ActionSetVariable (0x1D)

## Opcode Specification

**Opcode Name**: ActionSetVariable
**Hex Value**: 0x1D
**Category**: Variables
**Estimated Complexity**: MEDIUM
**SWF Version**: 4+

## Description

Sets the value of a variable. Pops a value and a variable name from the stack, then stores the value in the variable.

## Stack Operation

**Before**: `[... value variableName]`
**After**: `[...]`

## Expected Behavior

1. Pop the variable name (string) from the stack
2. Pop the value to assign from the stack
3. Store the value in the variable store under that name
4. If variable exists, update it; if not, create it

**Variable Storage**:
- Creates variable if it doesn't exist
- Updates variable if it does exist
- Stores in current scope (or global if no local scope)

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_SET_VARIABLE` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionSetVariable()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Set Number Variable
```actionscript
var x = 42;
trace(x);
```
**Expected output**: `42`

### Test Case 2: Set String Variable
```actionscript
var name = "Alice";
trace(name);
```
**Expected output**: `Alice`

### Test Case 3: Update Variable
```actionscript
var x = 10;
x = 20;
trace(x);
```
**Expected output**: `20`

### Test Case 4: Set from Expression
```actionscript
var x = 5 + 3;
trace(x);
```
**Expected output**: `8`

## Similar Opcodes

- `actionGetVariable` (0x1C) - Get variable value
- `actionDeclareLocal` (0x41) - Declare local variable

## Notes

- Variable name is popped first, then value
- Creates new variable if doesn't exist
- Uses hash map for variable storage
- Stack order: `[value, name]` → pop name, pop value
