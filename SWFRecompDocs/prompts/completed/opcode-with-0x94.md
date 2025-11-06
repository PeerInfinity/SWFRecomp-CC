# Opcode Implementation Task: WITH (0x94)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **WITH**

## Opcode Specification

**Opcode Name**: WITH
**Hex Value**: 0x94
**Category**: Advanced Control Flow
**Estimated Complexity**: COMPLEX (6-10 hours)

**Description**: Executes a block of code with an object added to the scope chain. This allows unqualified property access to resolve to the object's properties.

**Operation**:
- Pop object reference from stack
- Read block size from bytecode
- Push object onto scope chain
- Execute block of code
- Pop object from scope chain

**Expected Behavior** (from SWF spec):
ActionWith modifies the scope chain for a block of code. Property lookups within the with block first check the with object before checking variables.

**Bytecode Format**:
```
0x94 (opcode)
UI16 Size (bytes to skip if with object is invalid)
ACTIONRECORD Actions[Size]
```

Stack behavior:
1. Pop object from stack
2. If object is valid, add to scope chain
3. Execute actions in block
4. Remove object from scope chain

**Important Notes**:
- Changes variable/property lookup order temporarily
- With object checked before global variables
- Size field indicates code block size
- Can be nested (multiple with blocks)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_WITH = 0x94` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declarations to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test using with statement
6. **Setup Test Directory** - Create `SWFRecomp/tests/with_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Basic with statement
```actionscript
var obj = {x: 10, y: 20};
with (obj) {
    trace(x); // Looks up obj.x
    trace(y); // Looks up obj.y
}
```
Expected output:
```
10
20
```

### Test Case 2: With statement shadowing
```actionscript
var x = 100;
var obj = {x: 42};
with (obj) {
    trace(x); // obj.x, not global x
}
trace(x); // global x
```
Expected output:
```
42
100
```

### Test Case 3: Nested with
```actionscript
var obj1 = {a: 1};
var obj2 = {b: 2};
with (obj1) {
    with (obj2) {
        trace(b); // obj2.b
        trace(a); // obj1.a (outer with)
    }
}
```
Expected output:
```
2
1
```

## Implementation Hints

**Pattern**: Scope chain manipulation for block execution.

**Reference Implementation**:
- Variable lookup: `actionGetVariable`, `actionSetVariable`
- Control flow: `actionJump`, `actionIf`

**Critical Infrastructure Needed**:
- Scope chain (stack of objects)
- Modified variable lookup to check scope chain

**Recompiler Translation**:
```cpp
case SWF_ACTION_WITH:
{
    u16 size = readU16(action_buffer);

    out_script << "\t// With block" << endl;
    out_script << "\tactionWithStart(stack, sp);" << endl;

    // Generate code for block
    // Note: The block actions are inline, not a separate bytecode section
    // We need to track nesting level

    // For now, simple approach: emit actionWithStart and actionWithEnd
    // The actual block code is between them

    out_script << "\t{" << endl; // C scope for clarity

    // Parse the actions within the with block
    // This is tricky because we need to know where the block ends
    // Size tells us how many bytes of bytecode to parse

    const char* block_start = action_buffer;
    parseActions(action_buffer, size, out_script);

    out_script << "\t}" << endl;
    out_script << "\tactionWithEnd(stack, sp);" << endl;

    action_buffer = block_start + size;
    break;
}
```

**Runtime Implementation**:

**Scope Chain Structure**:
```c
// Global scope chain (stack of objects)
#define MAX_SCOPE_DEPTH 32
ASObject* scope_chain[MAX_SCOPE_DEPTH];
u32 scope_depth = 0;

void actionWithStart(char* stack, u32* sp)
{
    // Pop object from stack
    ActionVar obj_var;
    popVar(stack, sp, &obj_var);

    if (obj_var.type == ACTION_STACK_VALUE_OBJECT) {
        ASObject* obj = (ASObject*) obj_var.value.u64;

        // Push onto scope chain
        if (scope_depth < MAX_SCOPE_DEPTH) {
            scope_chain[scope_depth++] = obj;
        } else {
            // Error: scope chain overflow
            printf("Error: Scope chain overflow\n");
        }
    } else {
        // Invalid object: push null marker
        scope_chain[scope_depth++] = NULL;
    }
}

void actionWithEnd(char* stack, u32* sp)
{
    // Pop from scope chain
    if (scope_depth > 0) {
        scope_depth--;
    }
}
```

**Modified Variable Lookup**:
```c
ActionVar* getVariableWithScope(const char* name)
{
    // First check scope chain (innermost to outermost)
    for (int i = scope_depth - 1; i >= 0; i--) {
        if (scope_chain[i] != NULL) {
            ActionVar* prop = getProperty(scope_chain[i], name);
            if (prop != NULL) {
                return prop; // Found in with object
            }
        }
    }

    // Not found in scope chain: check global variables
    return getGlobalVariable(name);
}
```

**Important Considerations**:
- Scope chain must be thread-local or instance-specific
- Variable lookups throughout runtime need to use `getVariableWithScope`
- Proper cleanup on exceptions/early returns
- Nested with statements increase scope depth
- Size field is in bytes, not instructions

**Integration Changes**:
- All variable lookups must check scope chain first
- `actionGetVariable` needs modification
- `actionSetVariable` may need changes (set in scope or global?)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] With statements work correctly
- [ ] Property lookup respects scope chain
- [ ] Nested with statements work
- [ ] No build errors or warnings
- [ ] Full test suite still passes
- [ ] Scope chain properly managed
- [ ] Documentation created

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/with_swf_5/README.md`
- Document scope chain design
- Note changes to variable lookup
- Explain nesting behavior

**IMPORTANT**: This opcode requires modifying the variable lookup infrastructure used by GET_VARIABLE and SET_VARIABLE. Coordinate with those implementers or ensure you understand the existing implementation.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
