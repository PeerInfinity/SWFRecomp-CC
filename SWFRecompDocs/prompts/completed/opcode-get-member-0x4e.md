# Opcode Implementation Task: GET_MEMBER

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **GET_MEMBER**

## Opcode Specification

**Opcode Name**: GET_MEMBER
**Hex Value**: 0x4E
**Category**: Object Operations
**Estimated Complexity**: COMPLEX (4-6 hours)

**Description**: Gets a property value from an object.

**Operation**: Pop property name, pop object, push property value.

**Expected Behavior** (from SWF Spec 19):
- Pop the property name from the stack
- Pop the object from the stack
- Look up the property in the object
- Push the property value to the stack
- If property doesn't exist, push `undefined`
- Primitive types (number, boolean, string) are auto-converted to wrapper objects

**Stack Operations**:
```
Before: [... object, property_name]
After:  [... property_value]
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_GET_MEMBER = 0x4E` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test that accesses object properties
6. **Setup Test Directory** - Create `SWFRecomp/tests/get_member_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic property access
```actionscript
var obj = {x: 10};
trace(obj.x);
```
Expected output: `10`

### Test Case 2: Array element access
```actionscript
var arr = [1, 2, 3];
trace(arr[0]);
trace(arr[1]);
trace(arr.length);
```
Expected output:
```
1
2
3
```

### Test Case 3: Undefined property
```actionscript
var obj = {x: 10};
trace(obj.y);
```
Expected output: `undefined`

### Test Case 4: String length property
```actionscript
var x = "Hello";
trace(x.length);
```
Expected output: `5`

## Implementation Hints

**Pattern**: This is a property lookup operation.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_GET_MEMBER:
{
    out_script << "\t" << "// GetMember" << endl
               << "\t" << "actionGetMember(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionGetMember(char* stack, u32* sp)
{
    // 1. Pop property name
    convertString(stack, sp);
    const char* prop_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 2. Pop object
    ActionVar obj_var;
    popVar(stack, sp, &obj_var);

    // 3. Handle different object types
    if (obj_var.type == ACTION_STACK_VALUE_OBJECT) {
        ASObject* obj = (ASObject*) obj_var.value.u64;
        ActionVar* prop = findProperty(obj, prop_name);
        if (prop) {
            pushVar(stack, sp, prop);
        } else {
            pushUndefined(stack, sp);
        }
    }
    else if (obj_var.type == ACTION_STACK_VALUE_ARRAY) {
        ASArray* arr = (ASArray*) obj_var.value.u64;

        // Handle numeric indices
        int index = atoi(prop_name);
        if (index >= 0 && index < arr->length) {
            pushVar(stack, sp, &arr->elements[index]);
        }
        // Handle "length" property
        else if (strcmp(prop_name, "length") == 0) {
            float len = (float) arr->length;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &len));
        }
        else {
            pushUndefined(stack, sp);
        }
    }
    else if (obj_var.type == ACTION_STACK_VALUE_STRING) {
        // Handle string properties like "length"
        if (strcmp(prop_name, "length") == 0) {
            const char* str = (const char*) obj_var.value.u64;
            float len = (float) strlen(str);
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &len));
        }
        else {
            pushUndefined(stack, sp);
        }
    }
    else {
        // Other primitive types - push undefined
        pushUndefined(stack, sp);
    }
}
```

### Helper Functions Needed

```c
// Push undefined value
void pushUndefined(char* stack, u32* sp) {
    PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
}

// Find property in object (linear search for now)
ActionVar* findProperty(ASObject* obj, const char* name) {
    for (u32 i = 0; i < obj->num_properties; i++) {
        if (strcmp(obj->properties[i].name, name) == 0) {
            return &obj->properties[i].value;
        }
    }
    return NULL;
}

// Push a variable to stack
void pushVar(char* stack, u32* sp, ActionVar* var) {
    // Handle different types appropriately
    if (var->type == ACTION_STACK_VALUE_F32) {
        PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &var->value.f32));
    }
    else if (var->type == ACTION_STACK_VALUE_STRING) {
        PUSH_STR(var->value.string, strlen(var->value.string));
    }
    // ... handle other types
}
```

### Stack Type for Undefined

Add to `action.h`:
```c
#define ACTION_STACK_VALUE_UNDEFINED 5
```

### Similar Opcodes

- `actionGetVariable` - similar lookup pattern
- `actionInitObject` / `actionInitArray` - object structure reference

### Edge Cases

- Property doesn't exist → undefined
- Null/undefined object → undefined
- Numeric property names (array indices)
- Special properties (length)
- Nested property access
- Property name is number string vs actual property

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/get_member_swf_4/README.md` - Test description and expected output

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Handles objects, arrays, and primitive types
- [ ] Returns undefined for missing properties
- [ ] Array indexing works
- [ ] Special properties (length) work
- [ ] Documentation created

## Important Notes

**Dependencies**: This opcode requires:
- `INIT_OBJECT` (0x43) - to create objects for testing
- `INIT_ARRAY` (0x42) - to create arrays for testing
- Object model infrastructure (ASObject, ASArray structures)

**Type System**: Add `ACTION_STACK_VALUE_UNDEFINED` type if not already present.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 4-6 hours
**Priority**: HIGH - required for object/array usage
