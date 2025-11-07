# AS2 Opcode Implementation: IMPLEMENTS_OP

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **IMPLEMENTS_OP**

## Opcode Specification

**Opcode Name**: IMPLEMENTS_OP
**Hex Value**: 0x2C
**Category**: Type System
**Estimated Complexity**: COMPLEX

**Description**: Implements the ActionScript implements keyword to specify interfaces a class implements.

**Operation**: Pop constructor and interface list, store interface relationships.

**Expected Behavior**:
- Pop constructor function (the class) from stack
- Pop count of interfaces from stack
- Pop each interface constructor from stack
- Store list of implemented interfaces on constructor
- Used by CastOp and instanceof for type checking

**SWF Spec Reference** (swf-spec-19.txt:7164-7190):
```
ActionImplementsOp implements the ActionScript implements keyword. The
ActionImplementsOp action specifies the interfaces that a class implements,
for use by ActionCastOp. ActionImplementsOp can also specify the interfaces
that an interface implements, as interfaces can extend other interfaces.

Field              Type                    Comment
ActionImplementsOp ACTIONRECORDHEADER      ActionCode = 0x2C

ActionImplementsOp does the following:
1. Pops the constructor function off the stack. The constructor function
   represents the class that will implement the interfaces. The constructor
   function must have a prototype property.
2. Pops the count of implemented interfaces off the stack.
3. For each interface count, pops a constructor function off of the stack.
   The constructor function represents an interface.
4. Sets the constructor function's list of interfaces to the array collected
   in the previous step, and sets the count of interfaces to the count popped
   in step 2.
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test demonstrating interface implementation
6. **Setup Test Directory** - Create `SWFRecomp/tests/implements_op_swf_7/` (SWF 7+)
7. **Build and Verify** - Compile and verify behavior

## Test Cases

Test Case 1: Single interface
```actionscript
interface IFlyable {
    function fly();
}

class Bird implements IFlyable {
    function fly() {
        trace("Flying");
    }
}

var bird = new Bird();
bird.fly();
trace(bird instanceof IFlyable);
```
Expected output:
```
Flying
true
```

Test Case 2: Multiple interfaces
```actionscript
interface IFlyable {
    function fly();
}

interface ISwimable {
    function swim();
}

class Duck implements IFlyable, ISwimable {
    function fly() { trace("Duck flying"); }
    function swim() { trace("Duck swimming"); }
}

var duck = new Duck();
duck.fly();
duck.swim();
trace(duck instanceof IFlyable);
trace(duck instanceof ISwimable);
```
Expected output:
```
Duck flying
Duck swimming
true
true
```

Test Case 3: Interface inheritance
```actionscript
interface IAnimal {
    function breathe();
}

interface IMammal extends IAnimal {
    function nurse();
}

class Dog implements IMammal {
    function breathe() { trace("Breathing"); }
    function nurse() { trace("Nursing"); }
}

var dog = new Dog();
trace(dog instanceof IMammal);
trace(dog instanceof IAnimal);
```
Expected output:
```
true
true
```

## Implementation Hints

**Pattern**: This is a metadata storage operation for type system.

**Implementation approach**:
```c
void actionImplementsOp(char* stack, u32* sp)
{
    // Pop constructor function
    ActionVar constructor;
    popVar(stack, sp, &constructor);
    ASObject* ctor = (ASObject*) constructor.value.u64;

    // Pop interface count
    ActionVar count_var;
    popVar(stack, sp, &count_var);
    convertFloat(stack, sp);  // Ensure it's a number
    u32 interface_count = (u32) count_var.value.f32;

    // Allocate interface array
    ASObject** interfaces = malloc(sizeof(ASObject*) * interface_count);

    // Pop each interface constructor
    for (u32 i = 0; i < interface_count; i++) {
        ActionVar iface;
        popVar(stack, sp, &iface);
        interfaces[interface_count - 1 - i] = (ASObject*) iface.value.u64;
    }

    // Store on constructor object
    setInterfaceList(ctor, interfaces, interface_count);

    // Note: No values pushed back on stack
}
```

**Supporting infrastructure**:
```c
// In object.c
void setInterfaceList(ASObject* constructor, ASObject** interfaces, u32 count)
{
    // Store interface metadata on constructor
    constructor->interface_count = count;
    constructor->interfaces = interfaces;
}

int implementsInterface(ASObject* obj, ASObject* interface_ctor)
{
    // Check if object's constructor implements interface
    ASObject* obj_ctor = getConstructor(obj);
    if (!obj_ctor) return 0;

    for (u32 i = 0; i < obj_ctor->interface_count; i++) {
        if (obj_ctor->interfaces[i] == interface_ctor) {
            return 1;
        }
        // Recursive check for interface inheritance
        if (implementsInterface(obj_ctor->interfaces[i], interface_ctor)) {
            return 1;
        }
    }
    return 0;
}
```

**Important Considerations**:
- Must store interface metadata on constructor
- Used by instanceof and CastOp for type checking
- Interfaces can extend other interfaces (recursive check)
- Memory management: retain interface objects

Reference similar operations:
- ActionExtends (0x69) - for class inheritance
- ActionCastOp (0x2B) - uses this metadata
- instanceof operator - uses this metadata

## Infrastructure Requirements

**ASObject additions**:
```c
typedef struct ASObject {
    // ... existing fields ...
    u32 interface_count;
    struct ASObject** interfaces;  // Array of interface constructors
} ASObject;
```

**Object model functions**:
```c
void setInterfaceList(ASObject* ctor, ASObject** interfaces, u32 count);
int implementsInterface(ASObject* obj, ASObject* interface_ctor);
ASObject* getConstructor(ASObject* obj);  // Get object's constructor
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct interface behavior
- [ ] instanceof works with interfaces
- [ ] Multiple interfaces are supported
- [ ] Interface inheritance works (transitive)
- [ ] No build errors or warnings
- [ ] No memory leaks
- [ ] Documentation created
- [ ] Full test suite still passes

## Notes

- This is a type system metadata opcode
- SWF 7+ feature (ActionScript 2.0)
- Critical for interface-based polymorphism
- Coordinate with CastOp and instanceof implementations
- Requires object model with metadata storage

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
