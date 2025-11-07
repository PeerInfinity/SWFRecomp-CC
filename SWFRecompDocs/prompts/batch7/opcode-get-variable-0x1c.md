# Opcode Implementation Prompt: ActionGetVariable (0x1C)

## Opcode Specification

**Opcode Name**: ActionGetVariable
**Hex Value**: 0x1C
**Category**: Variables
**Estimated Complexity**: MEDIUM
**SWF Version**: 4+

## Description

Gets the value of a variable. Pops a variable name from the stack, looks up the variable, and pushes its value onto the stack.

## Stack Operation

**Before**: `[... variableName]`
**After**: `[... variableValue]`

## Expected Behavior

1. Pop the variable name (string) from the stack
2. Look up the variable in the variable store
3. If found, push its value onto the stack
4. If not found, push `undefined` (or empty string in SWF 4)

**Variable Lookup**:
- Search local scope first
- Then search parent scopes
- Finally search global scope
- If not found, return undefined

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_GET_VARIABLE` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionGetVariable()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Get Existing Variable
```actionscript
var x = 42;
trace(x);
```
**Expected output**: `42`

### Test Case 2: Get String Variable
```actionscript
var name = "hello";
trace(name);
```
**Expected output**: `hello`

### Test Case 3: Get Undefined Variable
```actionscript
trace(undefinedVar);
```
**Expected output**: `` (empty) or `undefined`

### Test Case 4: Get After Assignment
```actionscript
var x = 10;
var y = x;
trace(y);
```
**Expected output**: `10`

## Similar Opcodes

- `actionSetVariable` (0x1D) - Set variable value
- `actionPush` (0x96) - Push literal value

## Notes

- Variable name is a string popped from stack
- Uses hash map for variable storage
- Scope chain lookup may be required
- Variable values can be any type
