# Opcode Implementation Task: SET_MEMBER

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **SET_MEMBER**

## Opcode Specification

**Opcode Name**: SET_MEMBER
**Hex Value**: 0x4F
**Category**: Object Operations
**Estimated Complexity**: COMPLEX (4-6 hours)

**Description**: Sets a property value on an object.

**Operation**: Pop value, pop property name, pop object, set property.

**Expected Behavior** (from SWF Spec 19):
- Pop the new value off the stack
- Pop the object name (property name) off the stack
- Pop the object off the stack
- Set the property on the object to the new value
- If the property does not already exist, it is created
- Any existing value in the property is overwritten
- Arrays should support numeric indices for element assignment
- Primitive types may need special handling

**Stack Operations**:
```
Before: [... object, property_name, value]
After:  [... ]
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_SET_MEMBER = 0x4F` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test that sets object properties
6. **Setup Test Directory** - Create `SWFRecomp/tests/set_member_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic property assignment
```actionscript
var obj = {x: 10};
obj.x = 20;
trace(obj.x);
```
Expected output: `20`

### Test Case 2: Creating new property
```actionscript
var obj = {};
obj.name = "test";
obj.value = 42;
trace(obj.name);
trace(obj.value);
```
Expected output:
```
test
42
```

### Test Case 3: Array element assignment
```actionscript
var arr = [1, 2, 3];
arr[0] = 10;
arr[1] = 20;
trace(arr[0]);
trace(arr[1]);
trace(arr[2]);
```
Expected output:
```
10
20
3
```

### Test Case 4: Overwriting existing property
```actionscript
var obj = {x: 10, y: 20};
obj.x = 100;
trace(obj.x);
trace(obj.y);
```
Expected output:
```
100
20
```

## Implementation Hints

**Pattern**: This is a property assignment operation, the complement of GET_MEMBER.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_SET_MEMBER:
{
    out_script << "\t" << "// SetMember" << endl
               << "\t" << "actionSetMember(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionSetMember(char* stack, u32* sp)
{
    // 1. Pop the value to assign
    ActionVar value_var;
    popVar(stack, sp, &value_var);

    // 2. Pop the property name
    convertString(stack, sp);
    const char* prop_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 3. Pop the object
    ActionVar obj_var;
    popVar(stack, sp, &obj_var);

    // 4. Set property based on object type
    if (obj_var.type == ACTION_STACK_VALUE_OBJECT) {
        ASObject* obj = (ASObject*) obj_var.value.u64;
        setProperty(obj, prop_name, &value_var);
    }
    else if (obj_var.type == ACTION_STACK_VALUE_ARRAY) {
        ASArray* arr = (ASArray*) obj_var.value.u64;

        // Handle numeric indices
        int index = atoi(prop_name);
        if (index >= 0 && index < arr->length) {
            // Release old value if it's an object/array
            if (arr->elements[index].type == ACTION_STACK_VALUE_OBJECT ||
                arr->elements[index].type == ACTION_STACK_VALUE_ARRAY) {
                releaseObject((void*) arr->elements[index].value.u64);
            }

            // Store new value
            arr->elements[index] = value_var;

            // Retain new value if it's an object/array
            if (value_var.type == ACTION_STACK_VALUE_OBJECT ||
                value_var.type == ACTION_STACK_VALUE_ARRAY) {
                retainObject((void*) value_var.value.u64);
            }
        }
        // Handle "length" property (special case - may resize array)
        else if (strcmp(prop_name, "length") == 0) {
            // Optional: implement array resize
        }
    }
}
```

### Helper Functions Needed

```c
// Set or create property in object
void setProperty(ASObject* obj, const char* name, ActionVar* value) {
    // Find existing property
    for (u32 i = 0; i < obj->num_properties; i++) {
        if (strcmp(obj->properties[i].name, name) == 0) {
            // Release old value if needed
            if (obj->properties[i].value.type == ACTION_STACK_VALUE_OBJECT ||
                obj->properties[i].value.type == ACTION_STACK_VALUE_ARRAY) {
                releaseObject((void*) obj->properties[i].value.value.u64);
            }

            // Set new value
            obj->properties[i].value = *value;

            // Retain new value if needed
            if (value->type == ACTION_STACK_VALUE_OBJECT ||
                value->type == ACTION_STACK_VALUE_ARRAY) {
                retainObject((void*) value->value.u64);
            }
            return;
        }
    }

    // Property doesn't exist - create it
    if (obj->num_properties < obj->capacity) {
        obj->properties[obj->num_properties].name = strdup(name);
        obj->properties[obj->num_properties].value = *value;

        // Retain new value if needed
        if (value->type == ACTION_STACK_VALUE_OBJECT ||
            value->type == ACTION_STACK_VALUE_ARRAY) {
            retainObject((void*) value->value.u64);
        }

        obj->num_properties++;
    }
    // TODO: Handle capacity expansion
}
```

### Memory Management

**Critical**: This opcode must properly manage reference counts:
1. **Release old values** when overwriting properties
2. **Retain new values** when storing objects/arrays
3. **Duplicate strings** when used as property names
4. Handle cases where value is stored but object is later released

### Similar Opcodes

Reference these implemented opcodes:
- `actionGetMember` (0x4E) - complement operation for reading
- `actionInitObject` (0x43) - object structure reference
- `actionSetVariable` - similar assignment pattern

### Edge Cases to Handle

- Setting property on undefined/null object (should error or ignore)
- Numeric property names on objects
- Non-numeric property names on arrays
- Array index out of bounds (expand array or ignore?)
- Setting length property on arrays
- Property name collisions
- Memory management for string property names
- Circular references (object contains itself)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/set_member_swf_4/README.md` - Test description and expected output

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Handles objects and arrays correctly
- [ ] Creates new properties when needed
- [ ] Overwrites existing properties correctly
- [ ] Proper reference counting (no memory leaks)
- [ ] Array element assignment works
- [ ] Documentation created

## Important Notes

**Dependencies**: This opcode requires:
- `INIT_OBJECT` (0x43) - to create objects for testing
- `INIT_ARRAY` (0x42) - to create arrays for testing
- `GET_MEMBER` (0x4E) - to verify property values in tests
- Object model infrastructure (ASObject, ASArray structures)

**Coordination**: This opcode works closely with GET_MEMBER. Ensure consistent behavior:
- Property lookup uses same logic
- Array indexing uses same conversion
- Special properties handled consistently

**Simplified Initial Implementation**: For the first pass, you may:
- Limit maximum properties per object
- Defer array resizing support
- Use simple linear property search
- Skip prototype chain lookup

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 4-6 hours
**Priority**: HIGH - required for object manipulation
