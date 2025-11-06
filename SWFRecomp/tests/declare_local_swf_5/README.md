# DECLARE_LOCAL (0x41) Test

This test verifies the implementation of the AS2 DECLARE_LOCAL opcode (0x41).

## Opcode Information

- **Name**: DECLARE_LOCAL
- **Hex Value**: 0x41
- **Category**: Advanced Control Flow (Scope Management)
- **SWF Version**: 5+

## Description

The DECLARE_LOCAL opcode creates a local variable in the current function scope. Unlike SET_VARIABLE which creates global variables, DECLARE_LOCAL creates variables that are local to the function.

## Operation

1. Pop variable name (string) from stack
2. Declare variable in local scope (initially undefined)
3. Variable exists only in current function scope

## Implementation Details

### Local Scope Infrastructure

The implementation adds a call stack system with local variable storage:

```c
#define MAX_LOCAL_VARS 64
#define MAX_CALL_DEPTH 32

typedef struct {
    char name[64];
    ActionVar value;
} LocalVar;

typedef struct {
    LocalVar vars[MAX_LOCAL_VARS];
    u32 var_count;
} LocalScope;

static LocalScope call_stack[MAX_CALL_DEPTH];
static u32 call_depth = 0;
```

### Function Lifecycle

- `functionEnter()` - Called when entering a function (initializes new local scope)
- `functionExit()` - Called when exiting a function (cleans up local scope)

### Variable Lookup Changes

Both `actionGetVariable` and `actionSetVariable` were modified to check local scope first before checking global variables. This implements the shadowing behavior where local variables shadow globals of the same name.

### Key Features

1. **Local Scope**: Variables are function-scoped, not block-scoped
2. **Shadowing**: Local variables shadow global variables of the same name
3. **Undefined Initialization**: Variables are initialized to undefined
4. **Redeclaration Safe**: Redeclaring the same variable does nothing

## Test Case

The current test demonstrates basic opcode recognition:

```actionscript
// Note: Called outside function for testing purposes
trace("Testing DECLARE_LOCAL opcode");
var x;  // DECLARE_LOCAL
trace("DECLARE_LOCAL completed (warning expected)");
```

### Expected Output

```
Testing DECLARE_LOCAL opcode
Warning: DECLARE_LOCAL outside function for variable 'x'
DECLARE_LOCAL completed (warning expected)
```

### Test Notes

This test verifies that:
1. The opcode is recognized and doesn't crash
2. A warning is shown when called outside a function
3. The basic plumbing works correctly

**Full functionality requires DEFINE_FUNCTION opcode** which manages the call stack depth. Once DEFINE_FUNCTION and RETURN are implemented, this opcode will support true local variable scoping.

## Integration Points

This opcode integrates with:

- **DEFINE_FUNCTION** (future) - Calls `functionEnter()` to initialize local scope
- **RETURN** (implemented) - Should call `functionExit()` to clean up local scope
- **GET_VARIABLE** - Modified to check local scope first
- **SET_VARIABLE** - Modified to check local scope first

## Files Modified

### SWFRecomp (Recompiler)
- `include/action/action.hpp` - Added `SWF_ACTION_DECLARE_LOCAL = 0x41` enum
- `src/action/action.cpp` - Added translation case for DECLARE_LOCAL

### SWFModernRuntime (Runtime)
- `include/actionmodern/action.h` - Added `actionDeclareLocal` declaration
- `src/actionmodern/action.c` - Implemented:
  - Local scope infrastructure (call stack with local variables)
  - `actionDeclareLocal()` function
  - `functionEnter()` and `functionExit()` helpers
  - `getLocalVariable()` helper
  - `declareLocalVariable()` helper
  - Modified `actionGetVariable()` to check local scope first
  - Modified `actionSetVariable()` to check local scope first

## Test Files

- `create_test_swf.py` - Python script to generate test.swf
- `config.toml` - SWFRecomp configuration
- `test.swf` - Generated test file (121 bytes)

## Design Decisions

1. **Static Call Stack**: Used a static array for the call stack (MAX_CALL_DEPTH=32) for simplicity and performance
2. **String Storage**: Local variable names are stored in fixed-size char arrays (64 bytes)
3. **Lookup Order**: Local scope is checked before global scope, implementing proper shadowing
4. **Memory Management**: Local variables are cleaned up in `functionExit()` including heap-allocated strings
5. **Error Handling**: Gracefully handles edge cases like too many local variables or calling outside functions

## Future Enhancements

Once DEFINE_FUNCTION is implemented:
- Add test cases for local variables inside functions
- Test local variable shadowing of globals
- Test multiple local declarations
- Test variable lifetime across function calls
- Test nested function scopes

## Build and Run

```bash
cd SWFRecomp
./scripts/build_test.sh declare_local_swf_5 native
./tests/declare_local_swf_5/build/native/declare_local_swf_5
```

## References

- SWF File Format Specification v19 - ActionDeclareLocal (0x41)
- Implementation follows the pattern established by other variable opcodes
- Local scope design based on AS2 specification for function-level scoping
