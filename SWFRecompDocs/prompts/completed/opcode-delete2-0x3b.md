# Opcode Implementation Prompt: ActionDelete2 (0x3B)

## Opcode Specification

**Opcode Name**: ActionDelete2
**Hex Value**: 0x3B
**Category**: Variables
**Estimated Complexity**: MEDIUM
**SWF Version**: 5+

## Description

Deletes a variable or property by name. Pops a name from the stack, resolves it (could be variable, property, or member), deletes it, and pushes a success boolean onto the stack.

## Stack Operation

**Before**: `[... name]`
**After**: `[... success]`

Where `success = 1.0` if deleted, else `0.0`

## Expected Behavior

1. Pop the name (string) from the stack
2. Resolve the name in the current scope:
   - Could be a variable
   - Could be a property path (e.g., "obj.prop")
   - Could be an array element reference
3. Delete the resolved reference
4. Push 1.0 if successful, 0.0 if failed

**Delete Semantics**:
- Can delete object properties
- Can delete array elements
- Cannot delete variable declarations (returns false)
- Returns true if already doesn't exist

## Implementation Status

✅ **Already Implemented**

- **Function**: `actionDelete2()` in `SWFModernRuntime/src/actionmodern/action.c`
- **Tests**: Has test directory `delete2_swf_5/`

## Test Cases

### Test Case 1: Delete Object Property
```actionscript
var obj = {x: 10, y: 20};
delete2 "obj.x";
trace(obj.x);  // undefined
```
**Expected output**: `undefined`

### Test Case 2: Delete Variable (Should Fail)
```actionscript
var x = 10;
trace(delete2 "x");  // false
trace(x);            // 10 (still exists)
```
**Expected output**:
```
0
10
```

### Test Case 3: Delete Array Element
```actionscript
var arr = [1, 2, 3];
delete2 "arr[1]";
trace(arr[1]);  // undefined
```
**Expected output**: `undefined`

### Test Case 4: Delete Non-Existent
```actionscript
delete2 "nonexistent";
// Returns true (nothing to delete)
```
**Expected output**: `1`

## Implementation Reference

This opcode requires:
- Variable name resolution
- Property path parsing (e.g., "obj.prop" or "arr[0]")
- Scope chain traversal
- Property deletion

## Similar Opcodes

- `actionDelete` (0x3A) - Delete with object reference on stack
- `actionGetVariable` (0x1C) - Get variable by name
- `actionSetVariable` (0x1D) - Set variable by name

## Notes

- This is **Delete2** - takes name as string, resolves it
- Can parse property paths ("obj.prop")
- Cannot delete `var` declarations
- Returns boolean success indicator
- More flexible than ActionDelete (0x3A)
- Commonly used for dynamic property removal
