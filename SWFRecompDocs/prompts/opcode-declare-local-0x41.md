# Opcode Implementation Task: DECLARE_LOCAL (0x41)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **DECLARE_LOCAL**

## Opcode Specification

**Opcode Name**: DECLARE_LOCAL
**Hex Value**: 0x41
**Category**: Advanced Control Flow (Scope Management)
**Estimated Complexity**: MEDIUM (4-6 hours)

**Description**: Declares a local variable in the current function scope. Unlike SET_VARIABLE which creates globals, DECLARE_LOCAL creates variables that are local to the function.

**Operation**:
- Pop variable name (string) from stack
- Declare variable in local scope (initially undefined)
- Variable exists only in current function scope

**Expected Behavior** (from SWF spec):
ActionDeclareLocal creates a local variable in the current function scope. The variable is initialized to undefined and exists only within the function's execution context.

Stack behavior:
1. Pop variable name from stack
2. Create local variable with value undefined
3. Variable is accessible only in current function scope

**Important Notes**:
- Local variables shadow global variables of the same name
- Variable is initialized to undefined
- Scope is function-level, not block-level
- Different from SET_VARIABLE (which creates/updates global or scoped variables)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_DECLARE_LOCAL = 0x41` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test with local variable declarations
6. **Setup Test Directory** - Create `SWFRecomp/tests/declare_local_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic local declaration
```actionscript
function test() {
    var x; // DECLARE_LOCAL
    trace(typeof(x));
    x = 42;
    trace(x);
}
test();
```
Expected output:
```
undefined
42
```

### Test Case 2: Local shadows global
```actionscript
var x = 100; // global
function test() {
    var x; // local, shadows global
    x = 42;
    trace(x); // local x
}
test();
trace(x); // global x, unchanged
```
Expected output:
```
42
100
```

### Test Case 3: Multiple local declarations
```actionscript
function test() {
    var a;
    var b;
    var c;
    a = 1;
    b = 2;
    c = 3;
    trace(a + b + c);
}
test();
```
Expected output: `6`

## Implementation Hints

**Pattern**: Local variable declaration with scope management.

**Reference Implementation**:
- `actionSetVariable` - for comparison with global variables
- `actionGetVariable` - needs to check local scope first

**Critical Infrastructure Needed**:
- Local scope storage per function call
- Modified variable lookup to check local scope before global

**Recompiler Translation**:
```cpp
case SWF_ACTION_DECLARE_LOCAL:
{
    out_script << "\t// DeclareLocal" << endl;
    out_script << "\tactionDeclareLocal(stack, sp);" << endl;
    break;
}
```

**Runtime Implementation**:

**Local Scope Structure**:
```c
// Local variable storage (per function call)
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

// Call stack with local scopes
LocalScope call_stack[MAX_CALL_DEPTH];
u32 call_depth = 0;

void actionDeclareLocal(char* stack, u32* sp)
{
    // Pop variable name
    const char* var_name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    if (call_depth == 0) {
        // Not in a function: treat as global (or error)
        printf("Warning: DECLARE_LOCAL outside function\n");
        return;
    }

    LocalScope* scope = &call_stack[call_depth - 1];

    // Check if variable already exists in local scope
    for (u32 i = 0; i < scope->var_count; i++) {
        if (strcmp(scope->vars[i].name, var_name) == 0) {
            // Already declared, do nothing
            return;
        }
    }

    // Add to local scope
    if (scope->var_count < MAX_LOCAL_VARS) {
        strncpy(scope->vars[scope->var_count].name, var_name, 63);
        scope->vars[scope->var_count].name[63] = '\0';
        scope->vars[scope->var_count].value.type = ACTION_STACK_VALUE_UNDEFINED;
        scope->var_count++;
    } else {
        printf("Error: Too many local variables\n");
    }
}
```

**Modified Variable Lookup**:
```c
ActionVar* getVariable(const char* name)
{
    // Check local scope first (if in function)
    if (call_depth > 0) {
        LocalScope* scope = &call_stack[call_depth - 1];
        for (u32 i = 0; i < scope->var_count; i++) {
            if (strcmp(scope->vars[i].name, name) == 0) {
                return &scope->vars[i].value;
            }
        }
    }

    // Check with scope chain (if WITH is active)
    // ... (see WITH opcode implementation)

    // Check global variables
    return getGlobalVariable(name);
}

void setVariable(const char* name, ActionVar* value)
{
    // Check local scope first
    if (call_depth > 0) {
        LocalScope* scope = &call_stack[call_depth - 1];
        for (u32 i = 0; i < scope->var_count; i++) {
            if (strcmp(scope->vars[i].name, name) == 0) {
                scope->vars[i].value = *value;
                return;
            }
        }
    }

    // Not in local scope: set global
    setGlobalVariable(name, value);
}
```

**Function Entry/Exit**:
```c
void functionEnter()
{
    if (call_depth < MAX_CALL_DEPTH) {
        call_stack[call_depth].var_count = 0; // Clear local vars
        call_depth++;
    }
}

void functionExit()
{
    if (call_depth > 0) {
        call_depth--;
    }
}
```

**Important Considerations**:
- Call stack must be managed by CALL_FUNCTION and RETURN
- Variable is initialized to undefined (not null)
- Local scope is function-level, not block-level
- Redeclaring same variable does nothing
- Must integrate with existing variable system

**Integration Changes**:
- `actionGetVariable` must check local scope first
- `actionSetVariable` must set local if it exists
- CALL_FUNCTION must call `functionEnter()`
- RETURN must call `functionExit()`

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Local variables declared correctly
- [ ] Locals shadow globals correctly
- [ ] Variable lookup checks local scope first
- [ ] No build errors or warnings
- [ ] Full test suite still passes
- [ ] Documentation created

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/declare_local_swf_5/README.md`
- Document local scope design
- Note call stack management
- Explain shadowing behavior

**Coordination**: This opcode requires integration with:
- DEFINE_FUNCTION (function entry)
- RETURN (function exit)
- GET_VARIABLE (variable lookup)
- SET_VARIABLE (variable assignment)

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
