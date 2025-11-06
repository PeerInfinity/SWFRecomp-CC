# DEFINE_FUNCTION (0x9B) Test

## Test Description

This test verifies the implementation of the DEFINE_FUNCTION opcode (0x9B), which creates user-defined functions in ActionScript 2.

## Opcode Details

- **Opcode**: 0x9B
- **Name**: DEFINE_FUNCTION
- **Category**: Advanced Control Flow
- **SWF Version**: 5+

## Implementation Approach

The implementation uses **compile-time function compilation**:
- SWFRecomp translates function bodies from ActionScript bytecode to C functions
- Each defined function becomes a separate C function with signature `void func_name_N(char* stack, u32* sp)`
- Functions are registered at runtime in a function registry
- CALL opcode looks up functions by name and invokes them

## Test Case

### Simple Test (Working)
```actionscript
function testFunc() {
    return 42;
}
trace("Function defined");
```

**Expected Output**: `Function defined`

### Advanced Test (Parameter Passing - Future Work)
```actionscript
function add(a, b) {
    return a + b;
}
trace(add(3, 5));
```

**Expected Output**: `8`

## Current Status

✅ Function definition works correctly
✅ Functions are stored in the runtime registry
✅ Function bodies are compiled to C
✅ Parameter binding is implemented
⚠️  Function calling with parameters needs more testing (CALL opcode integration)

## Implementation Files Modified

### SWFRecomp (Compiler)
- `include/action/action.hpp` - Added `SWF_ACTION_DEFINE_FUNCTION` enum and `func_counter` member
- `src/action/action.cpp` - Added DEFINE_FUNCTION translation case with recursive bytecode parsing
- `src/swf.cpp` - Added ActionVar and action.h includes to generated script headers

### SWFModernRuntime (Runtime)
- `include/actionmodern/action.h` - Added function declarations for `actionDefineFunction`, `popVar`, `setVariableByName`
- `include/actionmodern/stackvalue.h` - Added `ACTION_STACK_VALUE_FUNCTION` type
- `src/actionmodern/action.c` - Implemented:
  - Function storage infrastructure (ASFunction struct, function registry)
  - `actionDefineFunction` - Registers functions and stores them in variables
  - `setVariableByName` - Helper for parameter binding
  - Updated `actionCall` to call user-defined functions
  - Removed duplicate ASArray definition (moved to object.h)

## Design Notes

### Function Compilation Strategy

Functions are compiled to C at build time rather than interpreted at runtime:
1. SWFRecomp encounters DEFINE_FUNCTION bytecode
2. Reads function metadata (name, parameters, body size)
3. Generates a unique C function identifier
4. Recursively parses function body bytecode into C code
5. Generates function declaration and definition
6. Emits runtime call to register the function

### Parameter Binding

Parameters are passed on the stack when a function is called:
1. Caller pushes arguments in order
2. Caller pushes function name
3. CALL opcode pops function name and looks it up
4. Generated function pops parameters from stack and binds them to variable names
5. Function body executes with parameters as variables

### Function Storage

Functions are stored in two ways:
1. **Global registry**: Array of function pointers indexed by registration order
2. **Variable system**: Named functions are also stored as variables of type `ACTION_STACK_VALUE_FUNCTION`

## Known Issues

1. TRACE opcode after CALL is being parsed incorrectly (appears as NEW_OBJECT) - this is a separate parser issue, not related to DEFINE_FUNCTION
2. Function calling with parameters needs integration testing

## Future Enhancements

- Anonymous functions (empty name)
- Nested functions
- Closures and scope management
- Function return value handling improvements
