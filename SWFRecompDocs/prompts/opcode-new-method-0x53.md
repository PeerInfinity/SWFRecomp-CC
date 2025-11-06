# Opcode Implementation Task: NEW_METHOD (0x53)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **NEW_METHOD**

## Opcode Specification

**Opcode Name**: NEW_METHOD
**Hex Value**: 0x53
**Category**: Function Operations
**Estimated Complexity**: COMPLEX (6-10 hours)

**Description**: Creates a new object by calling a method on an object as a constructor. This is the "new obj.MethodName(args)" operation in ActionScript.

**Operation**:
- Pop method name (string) from stack
- Pop object reference from stack
- Pop argument count (number) from stack
- Pop N arguments from stack (in reverse order)
- Call the method as a constructor
- Push new object onto stack

**Expected Behavior** (from SWF spec):
ActionNewMethod invokes a method on an object as a constructor to create a new object. It pops the method name, object, and arguments from the stack, calls the method as a constructor, and pushes the newly created object.

Stack behavior (example for `new obj.MyClass(arg1, arg2)`):
1. Push "MyClass" (method name)
2. Push obj (object containing the constructor)
3. Push 2 (argument count)
4. Push arg1
5. Push arg2
6. Execute NEW_METHOD
7. Result: pops all arguments; pushes new object

**Important Notes**:
- Method is called as a constructor (creates new object)
- The method must be a constructor function
- New object has prototype chain from constructor
- Arguments passed to constructor
- Returns the newly created object

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_NEW_METHOD = 0x53` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that uses constructor methods
6. **Setup Test Directory** - Create `SWFRecomp/tests/new_method_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Create Date object
```actionscript
var now = new Date();
trace(typeof(now));
```
Expected output: `object`

### Test Case 2: Create Array with size
```actionscript
var arr = new Array(5);
trace(arr.length);
```
Expected output: `5`

### Test Case 3: Create String object
```actionscript
var str = new String("hello");
trace(str.toString());
```
Expected output: `hello`

## Implementation Hints

**Pattern**: Constructor invocation with object context.

**Reference Implementation**:
- NEW_OBJECT (0x40) implementation (from Batch 3)
- CALL_METHOD (0x9F) implementation
- Object model from `object.c`

**Implementation Outline**:
```c
void actionNewMethod(char* stack, u32* sp, char* str_buffer)
{
    // 1. Pop method name
    const char* method_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 2. Pop object reference
    ActionVar obj_var;
    popVar(stack, sp, &obj_var);

    // 3. Pop argument count
    ActionVar count_var;
    popVar(stack, sp, &count_var);
    convertFloat(stack, sp);
    u32 arg_count = (u32) count_var.value.f32;

    // 4. Pop arguments into array
    ActionVar* args = malloc(sizeof(ActionVar) * arg_count);
    for (int i = arg_count - 1; i >= 0; i--) {
        popVar(stack, sp, &args[i]);
    }

    // 5. Get constructor method from object
    ASObject* constructor = getMethod(obj_var, method_name);

    // 6. Create new object using constructor
    ASObject* new_obj = NULL;
    if (constructor != NULL) {
        new_obj = invokeConstructor(constructor, args, arg_count);
    }

    // 7. Push new object (or undefined if failed)
    if (new_obj != NULL) {
        PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, new_obj));
    } else {
        PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
    }

    free(args);
}
```

**Important Considerations**:
- Constructor method must exist on the object
- New object starts with empty properties
- Constructor function initializes the object
- Prototype chain should be set (advanced)
- Built-in constructors: Array, String, Date, Object, etc.

**Built-in Constructors Needed**:
```c
// Array constructor
ASObject* constructor_Array(ActionVar* args, u32 count);

// String constructor
ASObject* constructor_String(ActionVar* args, u32 count);

// Object constructor
ASObject* constructor_Object(ActionVar* args, u32 count);

// Date constructor (simplified)
ASObject* constructor_Date(ActionVar* args, u32 count);
```

**Constructor Registry**:
```c
typedef ASObject* (*ConstructorFunc)(ActionVar* args, u32 count);

typedef struct {
    const char* name;
    ConstructorFunc func;
} ConstructorEntry;

ConstructorEntry builtin_constructors[] = {
    {"Array", constructor_Array},
    {"String", constructor_String},
    {"Object", constructor_Object},
    {"Date", constructor_Date},
    // ... more constructors
};
```

**Example Array Constructor**:
```c
ASObject* constructor_Array(ActionVar* args, u32 count)
{
    ASObject* arr = allocObject(0); // Start with no properties
    arr->is_array = true;

    if (count == 1 && args[0].type == ACTION_STACK_VALUE_F32) {
        // new Array(size) - create array with length
        u32 size = (u32) args[0].value.f32;
        arr->array_length = size;
    } else {
        // new Array(elem1, elem2, ...) - create with elements
        arr->array_length = count;
        for (u32 i = 0; i < count; i++) {
            // Add elements as properties
            char index_str[16];
            snprintf(index_str, 16, "%u", i);
            setProperty(arr, index_str, &args[i]);
        }
    }

    return arr;
}
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Can create objects using constructors
- [ ] Arguments passed to constructor correctly
- [ ] New object pushed onto stack
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Built-in constructors work (Array, String, Object)
- [ ] Non-existent constructors handled gracefully
- [ ] Documentation created in test directory

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/new_method_swf_5/README.md` - Test description and expected output
- Document which built-in constructors are implemented
- Note constructor lookup mechanism
- Explain prototype chain if implemented

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

**Note**: Start with essential constructors (Array, Object, String) and expand as needed. Coordinate with NEW_OBJECT implementer for shared constructor infrastructure.
