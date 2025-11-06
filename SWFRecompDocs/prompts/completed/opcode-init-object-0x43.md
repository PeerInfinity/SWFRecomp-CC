# Opcode Implementation Task: INIT_OBJECT

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **INIT_OBJECT**

## Opcode Specification

**Opcode Name**: INIT_OBJECT
**Hex Value**: 0x43
**Category**: Object Operations
**Estimated Complexity**: COMPLEX (4-8 hours)

**Description**: Initializes a new object with specified properties.

**Operation**: Pop property count, pop property name/value pairs, create object, push object reference.

**Expected Behavior** (from SWF Spec 19):
- Pop `elems` (number of properties) from stack
- Pop `[value1, name1, ..., valueN, nameN]` from stack
- Create a new object as a ScriptObject
- Set object type to Object
- For each property: pop value, pop name (convert to string), store property
- Push the newly created object to the stack
- Properties are pushed in reverse order (rightmost first, leftmost last)

**Stack Operations**:
```
Before: [... valueN, nameN, ..., value1, name1, count]
After:  [... object_reference]
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_INIT_OBJECT = 0x43` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test that creates objects
6. **Setup Test Directory** - Create `SWFRecomp/tests/init_object_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Empty object
```actionscript
var obj = {};
trace(typeof(obj));
```
Expected output: `object`

### Test Case 2: Simple object
```actionscript
var obj = {x: 10, y: 20};
trace(obj.x);
trace(obj.y);
```
Expected output:
```
10
20
```

### Test Case 3: Mixed type properties
```actionscript
var obj = {name: "test", value: 42, flag: true};
trace(obj.name);
trace(obj.value);
trace(obj.flag);
```
Expected output:
```
test
42
true
```

### Test Case 4: Nested objects
```actionscript
var obj = {inner: {x: 5}};
trace(obj.inner.x);
```
Expected output: `5`

## Implementation Hints

**Pattern**: This is an object creation operation with property storage.

### Object Model Design

**Object Structure**: Define an `ASObject` structure with:
```c
typedef struct {
    u32 refcount;           // Reference counting
    u32 num_properties;     // Number of properties
    u32 capacity;           // Allocated capacity
    ASProperty properties[]; // Flexible array of properties
} ASObject;

typedef struct {
    char* name;             // Property name (null-terminated string)
    ActionVar value;        // Property value
} ASProperty;
```

### Memory Management

**Allocation Pattern**:
```c
ASObject* allocObject(u32 initial_capacity) {
    ASObject* obj = malloc(sizeof(ASObject) + initial_capacity * sizeof(ASProperty));
    obj->refcount = 1;  // Initial reference
    obj->num_properties = 0;
    obj->capacity = initial_capacity;
    return obj;
}
```

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_INIT_OBJECT:
{
    out_script << "\t" << "// InitObject" << endl
               << "\t" << "actionInitObject(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionInitObject(char* stack, u32* sp)
{
    // 1. Pop property count
    ActionVar count_var;
    convertFloat(stack, sp);
    popVar(stack, sp, &count_var);
    u32 num_props = (u32) count_var.value.f32;

    // 2. Allocate object
    ASObject* obj = allocObject(num_props);
    obj->num_properties = num_props;

    // 3. Pop property name/value pairs
    for (int i = num_props - 1; i >= 0; i--) {
        // Pop property value
        ActionVar value;
        popVar(stack, sp, &value);

        // Pop property name and convert to string
        convertString(stack, sp);
        const char* name = (const char*) VAL(u64, &STACK_TOP_VALUE);
        POP();

        // Store property
        obj->properties[i].name = strdup(name);
        obj->properties[i].value = value;

        // Retain object/array values
        if (value.type == ACTION_STACK_VALUE_OBJECT ||
            value.type == ACTION_STACK_VALUE_ARRAY) {
            retainObject((void*) value.value.u64);
        }
    }

    // 4. Push object reference to stack
    PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, obj));
}
```

### Reference Counting

**Release object when refcount reaches 0**:
```c
void releaseObject(void* ptr) {
    ASObject* obj = (ASObject*) ptr;
    if (--obj->refcount == 0) {
        // Release all property values
        for (u32 i = 0; i < obj->num_properties; i++) {
            free(obj->properties[i].name);
            if (obj->properties[i].value.type == ACTION_STACK_VALUE_OBJECT ||
                obj->properties[i].value.type == ACTION_STACK_VALUE_ARRAY) {
                releaseObject((void*) obj->properties[i].value.value.u64);
            }
        }
        free(obj);
    }
}
```

### Property Lookup (for GET_MEMBER)

```c
ActionVar* findProperty(ASObject* obj, const char* name) {
    for (u32 i = 0; i < obj->num_properties; i++) {
        if (strcmp(obj->properties[i].name, name) == 0) {
            return &obj->properties[i].value;
        }
    }
    return NULL;  // Property not found -> undefined
}
```

### Similar Opcodes

- `actionInitArray` (0x42) - similar creation pattern
- `actionGetVariable` / `actionSetVariable` - for storage patterns
- `actionPush` - for stack manipulation

### Edge Cases

- Empty objects (0 properties)
- Duplicate property names (last one wins)
- Property names that need string conversion
- Nested objects
- Objects with array properties
- Very large objects (>100 properties)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/init_object_swf_4/README.md` - Test description and expected output
- Document your object structure design decisions
- Note property lookup strategy (linear vs hash table)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] No memory leaks (test with valgrind if available)
- [ ] Edge cases handled correctly
- [ ] Documentation created
- [ ] Properties properly reference-counted
- [ ] Property lookup works (requires GET_MEMBER)

## Important Notes

**Object Model Coordination**: This opcode establishes the object model. Consider coordinating with:
- `INIT_ARRAY` (0x42) - similar creation pattern
- `GET_MEMBER` (0x4E) - for property access
- `SET_MEMBER` (0x4F) - for property modification

**Shared Infrastructure**: You may want to create shared files:
- `SWFModernRuntime/src/actionmodern/object.c`
- `SWFModernRuntime/include/actionmodern/object.h`

For object allocation, reference counting, and property management functions.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 4-6 hours for core functionality
**Priority**: HIGH - foundational for many other opcodes
