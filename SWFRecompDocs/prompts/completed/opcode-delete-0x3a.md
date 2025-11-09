# Opcode Implementation Prompt: ActionDelete (0x3A)

## Opcode Specification

**Opcode Name**: ActionDelete
**Hex Value**: 0x3A
**Category**: Object/Property
**Estimated Complexity**: MEDIUM
**SWF Version**: 5+

## Description

Deletes a property from an object. Pops a property name and an object reference from the stack, deletes the property, and pushes a success boolean onto the stack.

## Stack Operation

**Before**: `[... object propertyName]`
**After**: `[... success]`

Where `success = 1.0` if property was deleted, else `0.0`

## Expected Behavior

1. Pop the property name (string) from the stack
2. Pop the object reference from the stack
3. Delete the property from the object
4. Push 1.0 if successful, 0.0 if failed (property doesn't exist or can't be deleted)

**Delete Semantics**:
- Only deletes own properties (not inherited)
- Returns true if property existed and was deleted
- Returns true if property didn't exist
- Returns false if property cannot be deleted (read-only)

## Implementation Status

✅ **Already Implemented**

- **Function**: `actionDelete()` in `SWFModernRuntime/src/actionmodern/action.c`
- **Tests**: Has test directory `delete_swf_5/`

## Test Cases

### Test Case 1: Delete Existing Property
```actionscript
var obj = {x: 10, y: 20};
trace(delete obj.x);  // true
trace(obj.x);         // undefined
```
**Expected output**:
```
1
undefined
```

### Test Case 2: Delete Non-Existent Property
```actionscript
var obj = {x: 10};
trace(delete obj.y);  // true (already doesn't exist)
```
**Expected output**: `1`

### Test Case 3: Delete from Array
```actionscript
var arr = [1, 2, 3];
trace(delete arr[1]);
trace(arr.length);    // Still 3
trace(arr[1]);        // undefined
```
**Expected output**:
```
1
3
undefined
```

### Test Case 4: Cannot Delete Variables
```actionscript
var x = 10;
trace(delete x);  // false (can't delete var)
```
**Expected output**: `0`

## Implementation Reference

This opcode works with the object model and requires:
- Object property lookup
- Property deletion from hash map/object
- Checking if property is deletable

## Similar Opcodes

- `actionDelete2` (0x3B) - Delete with variable name lookup
- `actionSetMember` (0x4F) - Set object property
- `actionGetMember` (0x4E) - Get object property

## Notes

- This is the **SWF 5** version (pops property name from stack)
- Returns boolean success indicator
- Does NOT delete inherited properties
- Does NOT delete variable declarations
- Property name is a string
- Object is a reference (not object path string)
