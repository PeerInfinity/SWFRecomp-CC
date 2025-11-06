# Opcode Implementation Task: CALL_METHOD (0x9F)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **CALL_METHOD**

## Opcode Specification

**Opcode Name**: CALL_METHOD
**Hex Value**: 0x9F
**Category**: Function Operations
**Estimated Complexity**: COMPLEX (6-10 hours)

**Description**: Calls a method on an object. Similar to CALL_FUNCTION but operates on an object's method with proper 'this' binding.

**Operation**:
- Pop method name (string, or empty for anonymous) from stack
- Pop object reference from stack
- Pop argument count (number) from stack
- Pop N arguments from stack (in reverse order)
- Call the method on the object with arguments
- Push return value onto stack

**Expected Behavior** (from SWF spec):
ActionCallMethod calls a method on an object. It pops the method name (or empty string for anonymous function), the object (or null), and number of arguments, then pops the arguments themselves. The method is called with the object as 'this', and the return value is pushed onto the stack.

Stack behavior (example for `obj.foo(arg1, arg2)`):
1. Push "foo" (method name, or "" for anonymous)
2. Push obj (object reference, or undefined for global)
3. Push 2 (argument count)
4. Push arg1
5. Push arg2
6. Execute CALL_METHOD
7. Result: pops all arguments; pushes return value

**Important Notes**:
- Method name can be empty string for calling object itself (if object is a function)
- Object can be undefined/null for global scope
- 'this' is bound to the object
- Arguments are pushed in order but popped in reverse
- Returns undefined if method doesn't exist or has no return

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_CALL_METHOD = 0x9F` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that calls object methods
6. **Setup Test Directory** - Create `SWFRecomp/tests/call_method_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Call string method
```actionscript
var str = "hello";
var result = str.toUpperCase();
trace(result);
```
Expected output: `HELLO`

### Test Case 2: Call array method
```actionscript
var arr = [1, 2, 3];
var result = arr.length;
trace(result);
```
Expected output: `3`

### Test Case 3: Call with arguments
```actionscript
var arr = [10, 20, 30];
arr.push(40);
trace(arr.length);
```
Expected output: `4`

## Implementation Hints

**Pattern**: Method call with object context and argument handling.

**Reference Implementation**:
- CALL_FUNCTION (0x3D) implementation
- GET_MEMBER (0x4E) for property access
- Object model from `object.c`

**Implementation Outline**:
```c
void actionCallMethod(char* stack, u32* sp, char* str_buffer)
{
    // 1. Pop method name (can be empty)
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

    // 5. Call method on object
    ActionVar result;
    if (strlen(method_name) == 0) {
        // Anonymous call: object itself is the function
        if (callFunction(obj_var, args, arg_count, &result)) {
            pushVar(stack, sp, &result);
        } else {
            PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
        }
    } else {
        // Named method call
        if (callMethod(obj_var, method_name, args, arg_count, &result)) {
            pushVar(stack, sp, &result);
        } else {
            PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
        }
    }

    free(args);
}
```

**Important Considerations**:
- Must bind 'this' to the object
- Empty method name means call object as function
- Null/undefined object means global scope
- Need built-in methods for String, Array, Object, etc.
- Arguments must be in correct order
- Return value or undefined

**Built-in Methods Needed**:
```c
// String methods
ActionVar string_toUpperCase(ASObject* this, ActionVar* args, u32 count);
ActionVar string_toLowerCase(ASObject* this, ActionVar* args, u32 count);
ActionVar string_substring(ASObject* this, ActionVar* args, u32 count);

// Array methods
ActionVar array_push(ASObject* this, ActionVar* args, u32 count);
ActionVar array_pop(ASObject* this, ActionVar* args, u32 count);
ActionVar array_length(ASObject* this, ActionVar* args, u32 count);

// Object methods
ActionVar object_toString(ASObject* this, ActionVar* args, u32 count);
```

**Method Registry**:
```c
typedef ActionVar (*MethodFunc)(ASObject* this, ActionVar* args, u32 count);

typedef struct {
    u8 type;  // ACTION_STACK_VALUE_STRING, etc.
    const char* method_name;
    MethodFunc func;
} MethodEntry;

// Registry of built-in methods per type
MethodEntry builtin_methods[] = {
    {ACTION_STACK_VALUE_STRING, "toUpperCase", string_toUpperCase},
    {ACTION_STACK_VALUE_STRING, "toLowerCase", string_toLowerCase},
    // ... more methods
};
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Can call built-in methods successfully
- [ ] 'this' binding works correctly
- [ ] Arguments passed in correct order
- [ ] Return value pushed correctly
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Empty method name handled (anonymous calls)
- [ ] Non-existent methods return undefined
- [ ] Documentation created in test directory

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/call_method_swf_5/README.md` - Test description and expected output
- Document which built-in methods are implemented
- Note 'this' binding mechanism
- Explain method lookup design

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

**Note**: Start with a few essential built-in methods (String.toUpperCase, Array.push, etc.) and expand as needed. Coordinate with CALL_FUNCTION implementer for shared infrastructure.
