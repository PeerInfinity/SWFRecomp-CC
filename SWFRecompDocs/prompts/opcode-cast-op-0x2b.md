# AS2 Opcode Implementation: CAST_OP

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **CAST_OP**

## Opcode Specification

**Opcode Name**: CAST_OP
**Hex Value**: 0x2B
**Category**: Type System
**Estimated Complexity**: COMPLEX

**Description**: Implements the ActionScript cast operator for type conversion.

**Operation**: Pop object and constructor, check if object is instance of constructor, push result or null.

**Expected Behavior**:
- Pop object to cast from stack
- Pop constructor function from stack
- Check if object is instance of constructor (like instanceof)
- If yes, push the object
- If no, push null

**SWF Spec Reference** (swf-spec-19.txt:7141-7163):
```
ActionCastOp implements the ActionScript cast operator, which allows the casting
from one data type to another. ActionCastOp pops an object off the stack and
attempts to convert the object to an instance of the class or to the interface
represented by the constructor function.

Field        Type                    Comment
ActionCastOp ACTIONRECORDHEADER      ActionCode = 0x2B

ActionCastOp does the following:
1. Pops the ScriptObject to cast off the stack.
2. Pops the constructor function off the stack.
3. Determines if object is an instance of constructor (doing the same comparison
   as ActionInstanceOf).
4. If the object is an instance of constructor, the popped ScriptObject is pushed
   onto the stack.
   If the object is not an instance of constructor, a null value is pushed onto
   the stack.
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test demonstrating type casting
6. **Setup Test Directory** - Create `SWFRecomp/tests/cast_op_swf_7/` (SWF 7+ for cast)
7. **Build and Verify** - Compile and verify behavior

## Test Cases

Test Case 1: Successful cast
```actionscript
function Animal() {}
function Dog() {}
Dog extends Animal;

var myDog = new Dog();
var asDog = Dog(myDog);  // Cast to Dog
trace(asDog != null);
```
Expected output:
```
true
```

Test Case 2: Failed cast (returns null)
```actionscript
function Animal() {}
function Dog() {}
function Cat() {}
Dog extends Animal;
Cat extends Animal;

var myCat = new Cat();
var asDog = Dog(myCat);  // Cast Cat to Dog (should fail)
trace(asDog == null);
```
Expected output:
```
true
```

Test Case 3: Cast with interface (if ImplementsOp is available)
```actionscript
interface IFlyable {
    function fly();
}

class Bird implements IFlyable {
    function fly() { trace("Flying"); }
}

var myBird = new Bird();
var asFlyable = IFlyable(myBird);
trace(asFlyable != null);
```
Expected output:
```
true
```

## Implementation Hints

**Pattern**: This is a type-checking operation with conditional result.

**Implementation approach**:
```c
void actionCastOp(char* stack, u32* sp)
{
    // Pop object to cast
    ActionVar obj;
    popVar(stack, sp, &obj);

    // Pop constructor function
    ActionVar constructor;
    popVar(stack, sp, &constructor);

    // Check if object is instance of constructor
    // Use same logic as instanceof
    int is_instance = checkInstanceOf(&obj, &constructor);

    if (is_instance) {
        // Push original object back
        pushVar(stack, sp, &obj);
    } else {
        // Push null
        ActionVar null_var;
        null_var.type = ACTION_STACK_VALUE_NULL;
        null_var.value.u64 = 0;
        pushVar(stack, sp, &null_var);
    }
}
```

**Helper function** (shared with instanceof):
```c
int checkInstanceOf(ActionVar* obj, ActionVar* constructor)
{
    if (obj->type != ACTION_STACK_VALUE_OBJECT) {
        return 0;  // Primitives are not instances
    }

    ASObject* object = (ASObject*) obj->value.u64;
    ASObject* ctor = (ASObject*) constructor->value.u64;

    // Get constructor's prototype
    ASObject* ctor_proto = getProperty(ctor, "prototype");

    // Walk object's prototype chain
    ASObject* current_proto = getProtoProperty(object);
    while (current_proto != NULL) {
        if (current_proto == ctor_proto) {
            return 1;  // Found match
        }
        current_proto = getProtoProperty(current_proto);
    }

    // Check implements list (for interfaces)
    if (hasInterface(ctor, object)) {
        return 1;
    }

    return 0;  // Not an instance
}
```

**Important Considerations**:
- Same logic as instanceof operator
- Must handle primitive types (always fail)
- Must walk prototype chain
- Must check interface implementations (if ImplementsOp is supported)
- Returns object on success, null on failure (not boolean)

Reference similar operations:
- instanceof operator (if implemented)
- ActionImplementsOp (0x2C) - for interface checking
- ActionExtends (0x69) - for inheritance

## Infrastructure Requirements

**Shared with instanceof**:
- Prototype chain walking
- Interface implementation checking
- Object type checking

**ASObject support**:
```c
ASObject* getProtoProperty(ASObject* obj);  // Get __proto__
int hasInterface(ASObject* ctor, ASObject* obj);  // Check implements
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct cast behavior
- [ ] Returns object for valid casts
- [ ] Returns null for invalid casts
- [ ] No build errors or warnings
- [ ] Prototype chain is correctly traversed
- [ ] Documentation created
- [ ] Full test suite still passes

## Notes

- This is a type system opcode
- SWF 7+ feature (ActionScript 2.0)
- Similar to instanceof but returns object/null instead of boolean
- Requires object model with prototype chain
- Used for type-safe downcasting in AS2

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
