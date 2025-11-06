# Opcode Implementation Task: STORE_REGISTER

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **STORE_REGISTER**

## Opcode Specification

**Opcode Name**: STORE_REGISTER
**Hex Value**: 0x87
**Category**: Stack Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Stores the top stack value in a register without popping it.

**Operation**: Peek stack top, store in register.

**Expected Behavior** (from SWF Spec 19):
- Read the next object from the stack (without popping it)
- Store it in one of the registers
- In SWF 4 and earlier, up to 4 registers are available
- In SWF 5+ (with ActionDefineFunction2), up to 256 registers are available
- The register number is specified in the bytecode (not on the stack)
- The value remains on the stack after storage

**Stack Operations**:
```
Before: [... value]
After:  [... value]  (value unchanged, but now also in register)
```

**Bytecode Format**:
```
ActionStoreRegister:
  - ActionCode: 0x87
  - RegisterNumber: UI8 (0-255)
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_STORE_REGISTER = 0x87` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test using registers
6. **Setup Test Directory** - Create `SWFRecomp/tests/store_register_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Store and retrieve value
```actionscript
// Push value, store in register, pop and push from register
var x = 42;
// Internally: StoreRegister(0), then use register 0
trace(x);
```
Expected output: `42`

### Test Case 2: Reuse register value
```actionscript
function add(a, b) {
    // Parameters may be stored in registers
    return a + b;
}
trace(add(10, 20));
```
Expected output: `30`

### Test Case 3: Multiple registers
```actionscript
// Store multiple values in different registers
var a = 1;
var b = 2;
var c = 3;
trace(a + b + c);
```
Expected output: `6`

### Test Case 4: Register preserves value
```actionscript
var x = "hello";
var y = x;  // May use register
trace(x);
trace(y);
```
Expected output:
```
hello
hello
```

## Implementation Hints

**Pattern**: This is a stack operation that provides temporary storage.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):

The STORE_REGISTER opcode has a parameter (register number) that must be read from the bytecode:

```cpp
case SWF_ACTION_STORE_REGISTER:
{
    // Read register number from bytecode
    u8 register_num = code[pc++];  // Read next byte

    out_script << "\t" << "// StoreRegister " << (int)register_num << endl
               << "\t" << "actionStoreRegister(stack, sp, " << (int)register_num << ");" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):

```c
// Register storage (global or per-execution-context)
// Support up to 256 registers (SWF 5+ max)
#define MAX_REGISTERS 256
static ActionVar g_registers[MAX_REGISTERS];

void actionStoreRegister(char* stack, u32* sp, u8 register_num)
{
    // Validate register number
    if (register_num >= MAX_REGISTERS) {
        // Invalid register - ignore or error
        return;
    }

    // Peek the top of stack (don't pop!)
    ActionVar value;
    peekVar(stack, sp, &value);

    // Release old register value if needed
    if (g_registers[register_num].type == ACTION_STACK_VALUE_OBJECT ||
        g_registers[register_num].type == ACTION_STACK_VALUE_ARRAY) {
        releaseObject((void*) g_registers[register_num].value.u64);
    }

    // Store value in register
    g_registers[register_num] = value;

    // Retain new value if it's an object/array
    if (value.type == ACTION_STACK_VALUE_OBJECT ||
        value.type == ACTION_STACK_VALUE_ARRAY) {
        retainObject((void*) value.value.u64);
    }
}
```

### Helper Functions

```c
// Peek top of stack without popping
void peekVar(char* stack, u32* sp, ActionVar* var) {
    // Read type and value from stack top
    u8 type = STACK_TOP_TYPE;
    var->type = type;

    switch (type) {
        case ACTION_STACK_VALUE_F32:
            var->value.f32 = STACK_TOP_VALUE_F32;
            break;
        case ACTION_STACK_VALUE_STRING:
            var->value.u64 = STACK_TOP_VALUE_U64;
            break;
        case ACTION_STACK_VALUE_OBJECT:
        case ACTION_STACK_VALUE_ARRAY:
            var->value.u64 = STACK_TOP_VALUE_U64;
            break;
        default:
            var->value.u64 = 0;
            break;
    }
}

// Push register value to stack
void actionPushRegister(char* stack, u32* sp, u8 register_num) {
    if (register_num >= MAX_REGISTERS) {
        return;
    }

    ActionVar* reg = &g_registers[register_num];

    // Push register value to stack
    if (reg->type == ACTION_STACK_VALUE_F32) {
        PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &reg->value.f32));
    } else if (reg->type == ACTION_STACK_VALUE_STRING) {
        const char* str = (const char*) reg->value.u64;
        PUSH_STR(str, strlen(str));
    } else if (reg->type == ACTION_STACK_VALUE_OBJECT ||
               reg->type == ACTION_STACK_VALUE_ARRAY) {
        // Retain when pushing to stack
        retainObject((void*) reg->value.u64);
        PUSH(reg->type, VAL(u64, &reg->value.u64));
    }
}
```

### Register Initialization

```c
// Initialize registers (call at startup)
void initRegisters() {
    for (int i = 0; i < MAX_REGISTERS; i++) {
        g_registers[i].type = ACTION_STACK_VALUE_UNDEFINED;
        g_registers[i].value.u64 = 0;
    }
}
```

### Integration with PUSH Opcode

The PUSH opcode (0x96) also supports pushing register values. You may need to extend the PUSH implementation:

```cpp
// In PUSH opcode handling:
case PUSH_TYPE_REGISTER:
{
    u8 register_num = read_u8();
    out_script << "\t" << "actionPushRegister(stack, sp, " << (int)register_num << ");" << endl;
    break;
}
```

### Register Scope

**Design Decision**: Should registers be:
1. **Global** - shared across all execution contexts (simpler)
2. **Per-function** - each function has its own register set (more correct)
3. **Per-frame** - each frame has its own registers

For initial implementation, use **global** registers. Later, integrate with function call stack.

### Similar Opcodes

Reference these opcodes:
- `actionPush` (0x96) - can push register values
- `actionPop` (0x17) - pops but doesn't store
- `actionSetVariable` - similar storage concept

### Edge Cases to Handle

- Invalid register number (>= 256)
- Storing undefined value
- Storing object/array (reference counting)
- Register used before initialization (undefined)
- Overwriting existing register value
- Register persistence across function calls
- Thread safety (if multi-threaded)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/store_register_swf_4/README.md` - Test description and expected output

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Register number read from bytecode correctly
- [ ] Value stored without popping from stack
- [ ] Register values can be retrieved (via PUSH)
- [ ] Multiple registers work independently
- [ ] Proper reference counting for objects
- [ ] No memory leaks
- [ ] Documentation created

## Important Notes

**Simplified Implementation**: For the initial pass:
- Use global register array (256 elements)
- Support basic types (number, string, object, array)
- Defer per-function register scoping
- Use simple reference counting

**Bytecode Reading**: This opcode has a parameter:
- The register number is in the bytecode, not on the stack
- Must read 1 byte after the opcode byte
- Translation layer must parse and pass this parameter

**Register Usage Patterns**:
- Function parameters often stored in registers
- Local variables may use registers for optimization
- Temporary values in complex expressions
- Loop counters and iterators

**Coordination**: This opcode works with:
- `PUSH` (0x96) - pushes register value to stack
- `DEFINE_FUNCTION2` (0x8E) - specifies register allocation
- Function call opcodes - may pass params in registers

**Future Enhancements**:
- Per-function register scopes
- Register allocation optimization
- Register spilling to stack
- Debug register inspection
- Register usage statistics

**Testing Strategy**: Since registers are often compiler-generated:
- Create SWF with functions (compiler uses registers)
- Test with ActionScript that triggers register usage
- Verify register values persist correctly
- Test register independence (r0 ≠ r1)

**Performance**: Registers are faster than variables:
- Direct access vs. hash table lookup
- No string comparison needed
- Compiler optimization target

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 2-4 hours
**Priority**: MEDIUM - optimization feature, less critical than core operations
