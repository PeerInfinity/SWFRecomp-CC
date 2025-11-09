# AS2 Opcode Implementation Task: ActionInstanceOf

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionInstanceOf**

## Opcode Specification

**Opcode Name**: ActionInstanceOf
**Hex Value**: 0x54
**Category**: Type Operations / Object Model
**Estimated Complexity**: COMPLEX (4-8 hours)

**Description**: Implements the ActionScript instanceof operator, checking if an object is an instance of a constructor function.

**Operation**: Pop constructor function and object from stack, check instance relationship, push boolean result.

**Expected Behavior** (from SWF Spec 19):
- Implements the ActionScript `instanceof` operator
- Boolean operator that indicates whether the left operand (object) is an instance of the class represented by the right operand (constructor function)
- In SWF 7+, also supports interfaces - if the constructor is a reference to an interface object and the left operand implements this interface, returns true
- Pops `constr` (constructor) from stack
- Pops `obj` (object) from stack
- Determines if `obj` is an instance of `constr`
- Pushes boolean result (1.0 for true, 0.0 for false) onto stack

**Stack Operations**:
```
Before: [... obj, constr]
After:  [... result]  // 1.0 for true, 0.0 for false
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_INSTANCEOF = 0x54` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with instanceof checks
6. **Setup Test Directory** - Create `SWFRecomp/tests/instanceof_swf_6/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Object instanceof Object
```actionscript
var obj = new Object();
trace(obj instanceof Object);
```
Expected output: `true`

### Test Case 2: Array instanceof Array
```actionscript
var arr = new Array(1, 2, 3);
trace(arr instanceof Array);
trace(arr instanceof Object);  // Array inherits from Object
```
Expected output:
```
true
true
```

### Test Case 3: Custom class instance
```actionscript
function MyClass() {
    this.value = 42;
}
var instance = new MyClass();
trace(instance instanceof MyClass);
trace(instance instanceof Object);
```
Expected output:
```
true
true
```

### Test Case 4: Not an instance
```actionscript
var obj = new Object();
trace(obj instanceof Array);
```
Expected output: `false`

### Test Case 5: Primitive values
```actionscript
var num = 5;
var str = "hello";
trace(num instanceof Number);
trace(str instanceof String);
```
Expected output:
```
false
false
```
(Primitives are not object instances)

## Implementation Hints

**Pattern**: This requires object model infrastructure including prototypes and constructor functions.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_INSTANCEOF:
{
    out_script << "\t" << "// InstanceOf" << endl
               << "\t" << "actionInstanceOf(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionInstanceOf(char* stack, u32* sp)
{
    // 1. Pop constructor function
    ActionVar constr_var;
    popVar(stack, sp, &constr_var);

    // 2. Pop object
    ActionVar obj_var;
    popVar(stack, sp, &obj_var);

    bool result = false;

    // 3. Check if obj is an instance of constr
    if (obj_var.type == ACTION_STACK_VALUE_OBJECT &&
        constr_var.type == ACTION_STACK_VALUE_OBJECT) {

        ScriptObject* obj = (ScriptObject*) obj_var.value.u64;
        ScriptObject* constr = (ScriptObject*) constr_var.value.u64;

        result = isInstanceOf(obj, constr);
    }
    // Primitives (number, string, boolean) are not instances

    // 4. Push result
    float result_val = result ? 1.0f : 0.0f;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_val));
}
```

### Instance Check Algorithm

```c
bool isInstanceOf(ScriptObject* obj, ScriptObject* constr)
{
    if (!obj || !constr) {
        return false;
    }

    // Get the prototype property of the constructor
    ScriptObject* constr_prototype = getObjectProperty(constr, "prototype");
    if (!constr_prototype) {
        return false;
    }

    // Walk up the prototype chain of obj
    ScriptObject* current = obj->prototype;
    while (current != NULL) {
        // Check if current matches constructor's prototype
        if (current == constr_prototype) {
            return true;
        }

        // Move up the prototype chain
        current = current->prototype;
    }

    // Not found in prototype chain
    return false;
}
```

### Object Model Structure

```c
typedef struct ScriptObject {
    // Object properties (hash table or array)
    Property* properties;
    int property_count;

    // Prototype pointer (for prototype chain)
    struct ScriptObject* prototype;

    // Constructor reference
    struct ScriptObject* constructor;

    // Additional fields...
} ScriptObject;

typedef struct {
    const char* name;
    ActionVar value;
} Property;
```

### Simplified Implementation

For initial implementation, you can simplify:

```c
void actionInstanceOf(char* stack, u32* sp)
{
    // Pop constructor
    ActionVar constr_var;
    popVar(stack, sp, &constr_var);

    // Pop object
    ActionVar obj_var;
    popVar(stack, sp, &obj_var);

    // Simplified: Always return false (or check basic types)
    bool result = false;

    // Check for known built-in types
    if (obj_var.type == ACTION_STACK_VALUE_OBJECT) {
        // TODO: Implement proper prototype chain traversal
        // For now, just check if it's an object
        result = false;  // Placeholder
    }

    // Push result
    float result_val = result ? 1.0f : 0.0f;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result_val));

    printf("// InstanceOf check (simplified)\n");
}
```

### Similar Opcodes

Reference these opcodes:
- `actionTypeOf` (0x44) - Get type of value as string
- `actionNewObject` (0x40) - Create object instance
- `actionNewMethod` (0x53) - Create instance via method
- `actionGetMember` (0x4E) - Access object properties

### Edge Cases to Handle

- Non-object left operand (primitives)
- Non-function right operand
- Constructor without prototype property
- Circular prototype chains
- null or undefined operands
- Built-in types (Object, Array, Function, etc.)
- Custom classes
- Multiple inheritance (if supported)
- Interface implementation (SWF 7+)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/instanceof_swf_6/README.md` - Test description and expected output
- Document prototype chain traversal algorithm
- Explain instanceof semantics

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Prototype chain traversal works correctly
- [ ] Built-in types handled correctly
- [ ] Custom classes supported
- [ ] Primitives return false correctly
- [ ] null/undefined handled gracefully
- [ ] Documentation created

## Important Notes

**Object Model Requirements**: This opcode requires:
- ScriptObject structure with prototype pointer
- Property storage and lookup
- Constructor function tracking
- Prototype chain traversal

**Prototype Chain**: JavaScript/ActionScript uses prototype-based inheritance:
```
obj.__proto__ -> Constructor.prototype -> Object.prototype -> null
```

**Flash Version**: Available in SWF 6+

**Instanceof Algorithm**:
1. Get constructor's prototype property
2. Walk up object's prototype chain
3. If any prototype matches constructor's prototype, return true
4. If chain ends without match, return false

**Common Use Cases**:
```actionscript
obj instanceof Object      // Check if obj is an object
arr instanceof Array       // Check if arr is an array
func instanceof Function   // Check if func is a function
```

**Interface Support (SWF 7+)**: In SWF 7 and later, instanceof also checks if an object implements an interface. This requires additional interface metadata.

**Testing Strategy**:
- Start with simplified implementation (return false)
- Add ScriptObject structure
- Implement prototype chain traversal
- Test with built-in types
- Test with custom classes
- Test edge cases

**Coordination**: This opcode relates to:
- Object creation opcodes (NewObject, NewMethod)
- Object property opcodes (GetMember, SetMember)
- Function definition opcodes (DefineFunction)
- Type checking opcodes (TypeOf)

**Performance Note**: Prototype chain traversal can be slow for deep hierarchies. Consider caching or optimization for frequently-used checks.

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
