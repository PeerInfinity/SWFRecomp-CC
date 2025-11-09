# ActionEnumerate (0x46) Test

## Overview

This test validates the `ENUMERATE` opcode (0x46) which implements object property enumeration for ActionScript's `for..in` loops.

## Test Description

The test creates an object with three properties (`a`, `b`, `c`) and enumerates them using the ENUMERATE opcode. The test verifies that all property names are correctly pushed onto the stack.

## Expected Behavior

According to the SWF specification:
1. Pop variable name from stack
2. Look up the variable and get its object value
3. Push `null` (undefined) as a terminator
4. Push each property name as a string
5. Property order is undefined (implementation-specific)

## Test Output

```
c
b
a
Enumeration test complete
```

Property names may appear in any order.

## Implementation Status

### ✅ Working Features:
- Basic object property enumeration
- Variable name lookup
- Null terminator handling
- Empty object handling
- Non-object type handling
- Proper stack ordering (reverse order push)

### ❌ Missing Features:

#### 1. Prototype Chain Enumeration
**Impact**: HIGH - Required for full ActionScript compliance

Properties inherited from an object's prototype are not enumerated because the `ASObject` structure lacks a `prototype` field.

**Example that would fail**:
```actionscript
function MyClass() {
    this.instanceProp = 1;
}
MyClass.prototype.protoProp = 2;

var obj = new MyClass();
for (var key in obj) {
    trace(key);  // Would only trace "instanceProp", missing "protoProp"
}
```

**Fix Required**: Add prototype support to the object model infrastructure.

#### 2. DontEnum Property Filtering
**Impact**: MEDIUM - Required for ECMA-262 compliance

All properties are currently enumerated. Built-in properties (like `toString`, `valueOf`, etc.) should be marked with the `DontEnum` attribute and excluded from enumeration.

**Example**:
```actionscript
var obj = {a: 1, b: 2};
// Should NOT enumerate built-in properties
// Currently no filtering is applied
```

**Fix Required**: Add property attribute flags to `ASProperty` structure.

#### 3. Slash-Path/Dot-Path Resolution
**Impact**: LOW - Edge case support

The specification mentions variable names can include slash-path (`/path/to/obj`) or dot-path (`obj.prop`) syntax. This is untested in current implementation.

**Fix Required**: Verify and test path resolution in variable lookup.

## Test Cases

### Current Coverage:
- ✅ Basic object with multiple properties
- ✅ Property names in any order

### Missing Coverage:
- ❌ Empty object
- ❌ Single property object
- ❌ Non-existent variable
- ❌ Non-object types (string, number, etc.)
- ❌ Object with many properties
- ❌ Dynamically added properties
- ❌ Properties with special characters
- ❌ Prototype chain inheritance
- ❌ Array enumeration

See `create_edge_case_test.py` for additional test scenarios.

## Related Opcodes

- **ENUMERATE2 (0x55)**: Similar to ENUMERATE but takes object directly from stack instead of variable name. Supports both objects and arrays.
- **INIT_OBJECT (0x43)**: Creates objects that can be enumerated
- **GET_MEMBER/SET_MEMBER**: Property access opcodes that should also support prototype chain

## Implementation Notes

### Current Implementation
File: `SWFModernRuntime/src/actionmodern/action.c:913`

The implementation:
1. Pops variable name string from stack
2. Looks up variable using `getVariable()` or `getVariableById()`
3. Validates variable is an object type
4. Pushes undefined as null terminator
5. Iterates through `obj->properties` array in reverse order
6. Pushes each property name string

### Infrastructure Requirements

To complete this opcode:

1. **Add Prototype Support** (affects multiple opcodes):
   ```c
   typedef struct ASObject {
       u32 refcount;
       u32 num_properties;
       u32 num_used;
       ASProperty* properties;
       ASObject* prototype;  // ADD THIS
       ...
   } ASObject;
   ```

2. **Add Property Attributes** (affects property system):
   ```c
   typedef struct ASProperty {
       char* name;
       u32 name_length;
       ActionVar value;
       u32 flags;  // ADD THIS (enumerable, writable, configurable)
   } ASProperty;
   ```

3. **Update Enumeration Loop**:
   ```c
   // Walk prototype chain
   ASObject* current = obj;
   while (current != NULL) {
       for (int i = current->num_used - 1; i >= 0; i--) {
           if (current->properties[i].flags & PROP_ENUMERABLE) {
               PUSH_STR(current->properties[i].name,
                       current->properties[i].name_length);
           }
       }
       current = current->prototype;
   }
   ```

## Validation

The test passes validation when:
- All three property names (`a`, `b`, `c`) are present in output (in any order)
- Completion message is displayed
- No duplicate property names
- No errors or crashes

Run validation:
```bash
./build/native/enumerate_swf_4 2>&1 | \
  grep -v "SWF Runtime" | grep -v "===" | grep -v "\[Frame" | \
  grep -v "\[Tag\]" | grep -v "^$" | ./validate.py
```

## References

- SWF File Format Specification v19, ActionEnumerate (0x46)
- ECMA-262 Standard (DontEnum attribute)
- `test_analysis.md` - Detailed implementation analysis
