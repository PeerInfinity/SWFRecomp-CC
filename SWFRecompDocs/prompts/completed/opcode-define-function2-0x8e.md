# Opcode Implementation Task: DEFINE_FUNCTION2 (0x8E)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **DEFINE_FUNCTION2**

## Opcode Specification

**Opcode Name**: DEFINE_FUNCTION2
**Hex Value**: 0x8E
**Category**: Advanced Control Flow
**Estimated Complexity**: VERY COMPLEX (12-20 hours)

**Description**: Enhanced version of DEFINE_FUNCTION with support for registers, preloading of 'this', 'arguments', 'super', etc. This is the SWF 7+ preferred way to define functions.

**Operation**:
- Read function name, parameters, and flags from bytecode
- Read register allocation information
- Read function body bytecode
- Create function object with register support
- Store in variable or push to stack

**Expected Behavior** (from SWF spec):
ActionDefineFunction2 is an enhanced version of ActionDefineFunction that supports:
- Register parameters (faster than variable lookup)
- Automatic preloading of 'this', 'arguments', 'super', etc.
- Function flags (suppress 'this', suppress 'arguments', etc.)
- More efficient execution

**Bytecode Format**:
```
0x8E (opcode)
UI16 length
STRING FunctionName
UI16 NumParams
UI8 RegisterCount
UI16 Flags
  Bit 0: PreloadThis
  Bit 1: PreloadArguments
  Bit 2: PreloadSuper
  Bit 3: PreloadRoot
  Bit 4: PreloadParent
  Bit 5: PreloadGlobal
  Bit 7: SuppressThis
  Bit 8: SuppressArguments
  Bit 9: SuppressSuper
PARAMETER Parameters[NumParams]
  UI8 Register (0 = variable, 1-254 = register)
  STRING ParamName
UI16 CodeSize
ACTIONRECORD FunctionBody[CodeSize]
```

**Important Notes**:
- Much more complex than DEFINE_FUNCTION (0x9B)
- Register allocation improves performance
- Preloading reduces lookup overhead
- Suppression flags control automatic bindings
- **Recommendation**: Implement DEFINE_FUNCTION first

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_DEFINE_FUNCTION2 = 0x8E` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (VERY COMPLEX!)
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test with function using registers
6. **Setup Test Directory** - Create `SWFRecomp/tests/define_function2_swf_7/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Function with register parameters
```actionscript
function add(a, b) {
    return a + b;
}
trace(add(10, 20));
```
Expected output: `30`

### Test Case 2: Function using 'this'
```actionscript
var obj = {
    value: 42,
    getValue: function() {
        return this.value;
    }
};
trace(obj.getValue());
```
Expected output: `42`

### Test Case 3: Function using 'arguments'
```actionscript
function sum() {
    var total = 0;
    for (var i = 0; i < arguments.length; i++) {
        total += arguments[i];
    }
    return total;
}
trace(sum(1, 2, 3, 4));
```
Expected output: `10`

## Implementation Hints

**Pattern**: Enhanced DEFINE_FUNCTION with registers and preloading.

**Critical Dependencies**:
- DEFINE_FUNCTION (0x9B) must be implemented first
- STORE_REGISTER (0x87) for register support
- Understanding of register allocation

**Approach**: Extend DEFINE_FUNCTION implementation with:
1. Register allocation for parameters
2. Preloading of special variables
3. Flag handling for suppressions

**Recompiler Translation** (extends DEFINE_FUNCTION):
```cpp
case SWF_ACTION_DEFINE_FUNCTION2:
{
    // Read metadata
    string func_name = readString(action_buffer);
    u16 num_params = readU16(action_buffer);
    u8 register_count = readU8(action_buffer);
    u16 flags = readU16(action_buffer);

    // Parse flags
    bool preload_this = (flags & 0x0001);
    bool preload_arguments = (flags & 0x0002);
    bool suppress_this = (flags & 0x0080);
    bool suppress_arguments = (flags & 0x0100);
    // ... more flags

    // Read parameters with register assignments
    vector<pair<u8, string>> params;
    for (u16 i = 0; i < num_params; i++) {
        u8 reg = readU8(action_buffer);
        string name = readString(action_buffer);
        params.push_back({reg, name});
    }

    u16 code_size = readU16(action_buffer);

    // Generate function with register support
    string func_id = "func2_" + func_name + "_" + to_string(func_counter++);

    // Generate function body
    function_definitions << "ActionVar " << func_id
                        << "(char* stack, u32* sp, ActionVar* args, u32 arg_count, "
                        << "ActionVar* registers, ASObject* this_obj) {" << endl;

    // Initialize registers
    function_definitions << "\tActionVar regs[" << (int)register_count << "];" << endl;

    // Preload special variables
    if (preload_this && !suppress_this) {
        function_definitions << "\tregs[1].type = ACTION_STACK_VALUE_OBJECT;" << endl;
        function_definitions << "\tregs[1].value.u64 = (u64)this_obj;" << endl;
    }

    // Bind parameters to registers or variables
    for (size_t i = 0; i < params.size(); i++) {
        if (params[i].first == 0) {
            // Variable parameter
            function_definitions << "\tsetVariable(\"" << params[i].second
                               << "\", &args[" << i << "]);" << endl;
        } else {
            // Register parameter
            function_definitions << "\tregs[" << (int)params[i].first
                               << "] = args[" << i << "];" << endl;
        }
    }

    // Translate function body
    parseActions(action_buffer, code_size, function_definitions);

    function_definitions << "\tActionVar ret;" << endl;
    function_definitions << "\tret.type = ACTION_STACK_VALUE_UNDEFINED;" << endl;
    function_definitions << "\treturn ret;" << endl;
    function_definitions << "}" << endl;

    // Store function
    out_script << "\tactionDefineFunction2(stack, sp, \"" << func_name
               << "\", " << func_id << ", " << num_params << ", "
               << (int)register_count << ", " << flags << ");" << endl;

    action_buffer += code_size;
    break;
}
```

**Runtime Implementation**:
```c
typedef ActionVar (*Function2Ptr)(char* stack, u32* sp, ActionVar* args,
                                  u32 arg_count, ActionVar* registers,
                                  ASObject* this_obj);

typedef struct {
    char name[64];
    Function2Ptr func;
    u32 param_count;
    u8 register_count;
    u16 flags;
} ASFunction2;

void actionDefineFunction2(char* stack, u32* sp, const char* name,
                          Function2Ptr func, u32 param_count,
                          u8 register_count, u16 flags)
{
    // Similar to actionDefineFunction but with register support
    ASFunction2* as_func = malloc(sizeof(ASFunction2));
    strncpy(as_func->name, name, 63);
    as_func->func = func;
    as_func->param_count = param_count;
    as_func->register_count = register_count;
    as_func->flags = flags;

    // Store and register function
    // ... (similar to DEFINE_FUNCTION)
}
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Functions with register parameters work
- [ ] Preloading of 'this' works
- [ ] Preloading of 'arguments' works
- [ ] Suppression flags respected
- [ ] No build errors or warnings
- [ ] Full test suite still passes
- [ ] Documentation created

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/define_function2_swf_7/README.md`
- Document register allocation strategy
- Note differences from DEFINE_FUNCTION
- Explain preloading mechanism

**WARNING**: This is extremely complex. Implement DEFINE_FUNCTION (0x9B) first, then extend it. Consider implementing a simplified version initially (ignore some flags).

**Coordination**: Work with DEFINE_FUNCTION implementer. Share function infrastructure.
