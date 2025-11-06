# Opcode Implementation Task: DEFINE_FUNCTION (0x9B)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **DEFINE_FUNCTION**

## Opcode Specification

**Opcode Name**: DEFINE_FUNCTION
**Hex Value**: 0x9B
**Category**: Advanced Control Flow
**Estimated Complexity**: VERY COMPLEX (10-16 hours)

**Description**: Defines a function object with parameters and a function body. This creates a callable function that can be stored in variables or object properties.

**Operation**:
- Read function name (string) from bytecode
- Read parameter count from bytecode
- Read parameter names from bytecode
- Read code size from bytecode
- Read function body bytecode
- Create function object
- Store in variable or push to stack

**Expected Behavior** (from SWF spec):
ActionDefineFunction creates a new function object with the specified name, parameters, and code body. The function can be called later using CALL_FUNCTION or CALL_METHOD.

**Bytecode Format**:
```
0x9B (opcode)
UI16 length (total length of action record)
STRING FunctionName (can be empty for anonymous)
UI16 NumParams
STRING Params[NumParams]
UI16 CodeSize
ACTIONRECORD FunctionBody[CodeSize]
```

**Important Notes**:
- This is a **compile-time and runtime hybrid** opcode
- Function body contains ActionScript bytecode (not C code)
- Need to store function body for later execution
- Parameters define function signature
- Anonymous functions (empty name) are supported
- Function creates new scope when called

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_DEFINE_FUNCTION = 0x9B` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (COMPLEX!)
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test with function definition and call
6. **Setup Test Directory** - Create `SWFRecomp/tests/define_function_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Simple function
```actionscript
function add(a, b) {
    return a + b;
}
var result = add(3, 5);
trace(result);
```
Expected output: `8`

### Test Case 2: Function with no parameters
```actionscript
function getMessage() {
    return "Hello";
}
trace(getMessage());
```
Expected output: `Hello`

### Test Case 3: Anonymous function
```actionscript
var multiply = function(x, y) {
    return x * y;
};
trace(multiply(4, 7));
```
Expected output: `28`

## Implementation Hints

**Pattern**: This is one of the most complex opcodes. It requires storing function bytecode for later execution.

**Critical Challenge**: The recompiler translates SWF bytecode to C code, but function bodies need to remain as bytecode (or be translated into callable C functions). This requires special handling.

**Approach 1: Store Bytecode (Simpler)**
- Store function body as bytecode
- Interpret bytecode when function is called
- Requires bytecode interpreter at runtime

**Approach 2: Compile Function to C (Complex)**
- SWFRecomp generates separate C function for each AS function
- Store function pointer in function object
- Call C function directly when invoked

**Recommended Approach**: Start with Approach 2 (compile to C) since SWFRecomp already translates bytecode.

**Recompiler Translation** (SWFRecomp/src/action/action.cpp):
```cpp
case SWF_ACTION_DEFINE_FUNCTION:
{
    // Read function metadata from bytecode
    string func_name = readString(action_buffer);
    u16 num_params = readU16(action_buffer);
    vector<string> params;
    for (u16 i = 0; i < num_params; i++) {
        params.push_back(readString(action_buffer));
    }
    u16 code_size = readU16(action_buffer);

    // Generate C function
    out_script << "\t// DefineFunction: " << func_name << endl;

    // Create function declaration
    string func_id = "func_" + func_name + "_" + to_string(func_counter++);

    // Generate function signature
    function_declarations << "ActionVar " << func_id
                         << "(char* stack, u32* sp, ActionVar* args, u32 arg_count);" << endl;

    // Generate function body in separate file
    function_definitions << "ActionVar " << func_id
                        << "(char* stack, u32* sp, ActionVar* args, u32 arg_count) {" << endl;

    // Bind parameters
    for (size_t i = 0; i < params.size(); i++) {
        function_definitions << "\tsetVariable(\"" << params[i]
                           << "\", &args[" << i << "]);" << endl;
    }

    // Translate function body bytecode
    parseActions(action_buffer, code_size, function_definitions);

    function_definitions << "\tActionVar ret;" << endl;
    function_definitions << "\tret.type = ACTION_STACK_VALUE_UNDEFINED;" << endl;
    function_definitions << "\treturn ret;" << endl;
    function_definitions << "}" << endl;

    // Store function in runtime
    out_script << "\tactionDefineFunction(stack, sp, \"" << func_name
               << "\", " << func_id << ", " << num_params << ");" << endl;

    action_buffer += code_size;
    break;
}
```

**Runtime Implementation**:
```c
typedef ActionVar (*FunctionPtr)(char* stack, u32* sp, ActionVar* args, u32 arg_count);

typedef struct {
    char name[64];
    FunctionPtr func;
    u32 param_count;
} ASFunction;

// Function storage (hash map or array)
ASFunction* function_registry[256];
u32 function_count = 0;

void actionDefineFunction(char* stack, u32* sp, const char* name,
                         FunctionPtr func, u32 param_count)
{
    // Store function in registry
    ASFunction* as_func = malloc(sizeof(ASFunction));
    strncpy(as_func->name, name, 63);
    as_func->name[63] = '\0';
    as_func->func = func;
    as_func->param_count = param_count;

    function_registry[function_count++] = as_func;

    // If named, store in variable
    if (strlen(name) > 0) {
        ActionVar func_var;
        func_var.type = ACTION_STACK_VALUE_FUNCTION;
        func_var.value.u64 = (u64) as_func;
        setVariable(name, &func_var);
    } else {
        // Anonymous function: push to stack
        PUSH(ACTION_STACK_VALUE_FUNCTION, VAL(u64, as_func));
    }
}
```

**Integration with CALL_FUNCTION**:
```c
// In actionCallFunction:
ASFunction* func = lookupFunction(func_name);
if (func != NULL) {
    ActionVar result = func->func(stack, sp, args, arg_count);
    pushVar(stack, sp, &result);
}
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Can define functions with parameters
- [ ] Can call defined functions
- [ ] Parameters bound correctly
- [ ] Return values work
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Anonymous functions supported
- [ ] Nested function calls work
- [ ] Documentation created in test directory

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/define_function_swf_5/README.md` - Test description and expected output
- Document function compilation approach
- Note parameter binding mechanism
- Explain function storage design
- Document integration with CALL_FUNCTION

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

**WARNING**: This is the most complex opcode so far. It requires significant changes to both SWFRecomp (compile-time) and SWFModernRuntime. Consider starting with a simple version (no parameters, no return) and expanding incrementally.

**Coordination**: Work closely with CALL_FUNCTION and RETURN implementers. Function definition, invocation, and return are tightly coupled.
