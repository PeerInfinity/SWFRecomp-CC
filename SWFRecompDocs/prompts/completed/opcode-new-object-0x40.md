# Opcode Implementation Task: NEW_OBJECT

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **NEW_OBJECT**

## Opcode Specification

**Opcode Name**: NEW_OBJECT
**Hex Value**: 0x40
**Category**: Object Operations
**Estimated Complexity**: COMPLEX (4-8 hours)

**Description**: Creates an object by invoking a constructor function.

**Operation**: Pop constructor name, pop argument count, pop arguments, create object, call constructor, push object.

**Expected Behavior** (from SWF Spec 19):
1. Pop the object name (STRING) from the stack (constructor name)
2. Pop numArgs (int) from the stack
3. Pop the arguments off the stack
4. Invoke the named object as a constructor function, passing it the specified arguments and a newly constructed object as the `this` keyword
5. The return value of the constructor function is discarded
6. The newly constructed object is pushed to the stack

**Stack Operations**:
```
Before: [... argN, argN-1, ..., arg1, numArgs, constructor_name]
After:  [... new_object]
```

**Note**: Arguments are pushed in reverse order (rightmost first, leftmost last) and popped in order (first to last).

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_NEW_OBJECT = 0x40` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test that uses constructors
6. **Setup Test Directory** - Create `SWFRecomp/tests/new_object_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Built-in Array constructor
```actionscript
var arr = new Array(3);
trace(arr.length);
```
Expected output: `3`

### Test Case 2: Built-in Date constructor (if supported)
```actionscript
var d = new Date();
trace(typeof(d));
```
Expected output: `object`

### Test Case 3: Built-in Object constructor
```actionscript
var obj = new Object();
obj.x = 10;
trace(obj.x);
```
Expected output: `10`

### Test Case 4: Constructor with arguments
```actionscript
var arr = new Array(1, 2, 3);
trace(arr.length);
trace(arr[0]);
```
Expected output:
```
3
1
```

## Implementation Hints

**Pattern**: This is an object creation and initialization operation.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_NEW_OBJECT:
{
    out_script << "\t" << "// NewObject" << endl
               << "\t" << "actionNewObject(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionNewObject(char* stack, u32* sp)
{
    // 1. Pop constructor name
    convertString(stack, sp);
    const char* ctor_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 2. Pop number of arguments
    convertFloat(stack, sp);
    ActionVar numArgs_var;
    popVar(stack, sp, &numArgs_var);
    u32 num_args = (u32) numArgs_var.value.f32;

    // 3. Pop arguments (store them temporarily)
    ActionVar args[16];  // Limit to 16 args for simplicity
    if (num_args > 16) num_args = 16;

    for (int i = num_args - 1; i >= 0; i--) {
        popVar(stack, sp, &args[i]);
    }

    // 4. Create new object based on constructor name
    void* new_obj = NULL;

    if (strcmp(ctor_name, "Array") == 0) {
        // Handle Array constructor
        if (num_args == 0) {
            // new Array() - empty array
            new_obj = allocArray(0);
        } else if (num_args == 1 && args[0].type == ACTION_STACK_VALUE_F32) {
            // new Array(length) - array with specified length
            u32 length = (u32) args[0].value.f32;
            ASArray* arr = allocArray(length);
            arr->length = length;
            new_obj = arr;
        } else {
            // new Array(elem1, elem2, ...) - array with elements
            ASArray* arr = allocArray(num_args);
            arr->length = num_args;
            for (u32 i = 0; i < num_args; i++) {
                arr->elements[i] = args[i];
                // Retain if object/array
                if (args[i].type == ACTION_STACK_VALUE_OBJECT ||
                    args[i].type == ACTION_STACK_VALUE_ARRAY) {
                    retainObject((void*) args[i].value.u64);
                }
            }
            new_obj = arr;
        }
        PUSH(ACTION_STACK_VALUE_ARRAY, VAL(u64, new_obj));
    }
    else if (strcmp(ctor_name, "Object") == 0) {
        // Handle Object constructor
        ASObject* obj = allocObject(8);  // Initial capacity
        new_obj = obj;
        PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
    }
    else if (strcmp(ctor_name, "Date") == 0) {
        // Handle Date constructor (simplified)
        ASObject* date = allocObject(4);
        // TODO: Initialize date properties
        new_obj = date;
        PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
    }
    else {
        // Unknown constructor - try to call user-defined function
        // For now, create generic object
        ASObject* obj = allocObject(8);
        new_obj = obj;
        PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
    }
}
```

### Helper Functions

```c
// Allocate a new array
ASArray* allocArray(u32 initial_capacity) {
    u32 capacity = initial_capacity > 0 ? initial_capacity : 4;
    ASArray* arr = malloc(sizeof(ASArray) + capacity * sizeof(ActionVar));
    arr->refcount = 1;
    arr->length = 0;
    arr->capacity = capacity;
    return arr;
}

// Allocate a new object
ASObject* allocObject(u32 initial_capacity) {
    ASObject* obj = malloc(sizeof(ASObject) + initial_capacity * sizeof(ASProperty));
    obj->refcount = 1;
    obj->num_properties = 0;
    obj->capacity = initial_capacity;
    return obj;
}

// Retain object (increment refcount)
void retainObject(void* obj) {
    if (obj) {
        ASObject* o = (ASObject*) obj;
        o->refcount++;
    }
}

// Release object (decrement refcount, free if 0)
void releaseObject(void* obj) {
    if (obj) {
        ASObject* o = (ASObject*) obj;
        if (--o->refcount == 0) {
            // Free object and its properties
            // TODO: Release nested objects/arrays
            free(o);
        }
    }
}
```

### Object Model Structures

```c
typedef struct {
    u32 refcount;
    u32 length;
    u32 capacity;
    ActionVar elements[];
} ASArray;

typedef struct {
    const char* name;
    ActionVar value;
} ASProperty;

typedef struct {
    u32 refcount;
    u32 num_properties;
    u32 capacity;
    ASProperty properties[];
} ASObject;
```

### Built-in Constructors to Support

**Essential**:
- `Object` - generic object
- `Array` - array with optional size or elements

**Common**:
- `Date` - date/time object
- `String` - string wrapper
- `Number` - number wrapper
- `Boolean` - boolean wrapper

**Optional** (defer to later):
- `Function`
- `RegExp`
- User-defined constructors

### Similar Opcodes

Reference these opcodes:
- `actionInitArray` (0x42) - similar array creation
- `actionInitObject` (0x43) - similar object creation
- `actionCallFunction` (0x3D) - function calling pattern

### Edge Cases to Handle

- Unknown constructor name (create generic object or error)
- Constructor with 0 arguments
- Array constructor with single number (size) vs multiple args (elements)
- Constructor that throws error
- User-defined constructors (may need CALL_FUNCTION integration)
- Memory allocation failure
- Reference counting for arguments
- Constructor return value (should be discarded)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/new_object_swf_4/README.md` - Test description and expected output

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] `new Array()` works with different argument patterns
- [ ] `new Object()` creates empty object
- [ ] Objects are properly reference counted
- [ ] No memory leaks
- [ ] Arguments are correctly popped in order
- [ ] Documentation created

## Important Notes

**Simplified Implementation**: For the initial pass:
- Support only `Object` and `Array` constructors
- Limit arguments to 16
- Skip user-defined constructors
- Use simple memory allocation
- Defer prototype chain setup

**Constructor Behavior**:
- `new Array()` → empty array
- `new Array(5)` → array of length 5
- `new Array(1, 2, 3)` → array with elements [1, 2, 3]
- `new Object()` → empty object

**Memory Management**: Critical for this opcode:
- New object starts with refcount = 1
- Arguments may contain objects that need retaining
- Constructor return value is discarded (don't leak)
- Object pushed to stack needs proper lifecycle

**Coordination**: This opcode relates to:
- `INIT_ARRAY` (0x42) - literal array syntax `[]`
- `INIT_OBJECT` (0x43) - literal object syntax `{}`
- `NEW_OBJECT` (0x40) - constructor syntax `new Ctor()`
- `CALL_FUNCTION` (0x3D) - calls constructor function

**Future Enhancements**:
- User-defined constructor support
- Prototype chain initialization
- All built-in constructors (Date, String, Number, Boolean, etc.)
- Constructor error handling
- this binding in constructor

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 4-8 hours
**Priority**: HIGH - foundational for object-oriented programming
