# AS2 Opcode Implementation: EXTENDS

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **EXTENDS**

## Opcode Specification

**Opcode Name**: EXTENDS
**Hex Value**: 0x69
**Category**: Inheritance
**Estimated Complexity**: COMPLEX

**Description**: Implements the ActionScript extends keyword to create inheritance relationship between classes.

**Operation**: Pop superclass and subclass constructors, set up prototype chain.

**Expected Behavior**:
- Pop superclass constructor from stack
- Pop subclass constructor from stack
- Create prototype chain for inheritance
- Set constructor property
- Does not call superclass constructor (avoids spurious calls)

**SWF Spec Reference** (swf-spec-19.txt:7104-7140):
```
ActionExtends implements the ActionScript extends keyword. ActionExtends creates
an inheritance relationship between two classes, called the subclass and the superclass.

Field          Type                    Comment
ActionExtends  ACTIONRECORDHEADER      ActionCode = 0x69

ActionExtends does the following:
1. Pops the ScriptObject superclass constructor off the stack.
2. Pops the ScriptObject subclass constructor off the stack.
3. Creates a new ScriptObject.
4. Sets the new ScriptObject's proto property to the superclass' prototype property.
5. Sets the new ScriptObject's constructor property to the superclass.
6. Sets the subclass' prototype property to the new ScriptObject.

These steps are the equivalent to the following ActionScript:
    Subclass.prototype = new Object();
    Subclass.prototype.__proto__ = Superclass.prototype;
    Subclass.prototype.constructor = Superclass;
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test demonstrating class inheritance
6. **Setup Test Directory** - Create `SWFRecomp/tests/extends_swf_7/` (SWF 7+ for extends)
7. **Build and Verify** - Compile and verify behavior

## Test Cases

Test Case 1: Basic class inheritance
```actionscript
// Define Animal class
function Animal(name) {
    this.name = name;
}
Animal.prototype.speak = function() {
    trace(this.name + " makes a sound");
};

// Define Dog class
function Dog(name) {
    this.name = name;
}

// Set up inheritance
Dog extends Animal;

// Test
var myDog = new Dog("Rex");
myDog.speak();
```
Expected output:
```
Rex makes a sound
```

Test Case 2: Method override
```actionscript
function Animal(name) {
    this.name = name;
}
Animal.prototype.speak = function() {
    trace("Animal sound");
};

function Cat(name) {
    this.name = name;
}
Cat extends Animal;

Cat.prototype.speak = function() {
    trace(this.name + " meows");
};

var myCat = new Cat("Whiskers");
myCat.speak();
```
Expected output:
```
Whiskers meows
```

Test Case 3: Check inheritance chain
```actionscript
function Base() {}
function Derived() {}
Derived extends Base;

var obj = new Derived();
trace(obj instanceof Derived);
trace(obj instanceof Base);
```
Expected output:
```
true
true
```

## Implementation Hints

**Pattern**: This is an object-oriented programming infrastructure operation.

**Implementation approach**:
```c
void actionExtends(char* stack, u32* sp)
{
    // Pop superclass constructor
    ActionVar superclass;
    popVar(stack, sp, &superclass);

    // Pop subclass constructor
    ActionVar subclass;
    popVar(stack, sp, &subclass);

    // Get constructor objects
    ASObject* super_func = (ASObject*) superclass.value.u64;
    ASObject* sub_func = (ASObject*) subclass.value.u64;

    // Create new prototype object
    ASObject* new_proto = allocObject(0);
    new_proto->refcount = 1;

    // Get superclass prototype
    ASObject* super_proto = getProperty(super_func, "prototype");

    // Set __proto__ of new prototype to superclass prototype
    setProperty(new_proto, "__proto__", super_proto);

    // Set constructor property
    setProperty(new_proto, "constructor", superclass);

    // Set subclass prototype to new object
    setProperty(sub_func, "prototype", new_proto);

    // Note: No values pushed back on stack
}
```

**Important Considerations**:
- Requires object model with property support
- Needs __proto__ (prototype chain) support
- Must handle constructor property correctly
- Does NOT call superclass constructor (key difference from old approach)
- Reference counting: retain objects as needed

Reference similar operations:
- InitObject (0x43) - object creation
- SetMember (0x4F) - property setting
- Object model infrastructure

## Infrastructure Requirements

**Object model must support**:
- `__proto__` property (prototype chain)
- `prototype` property on functions
- `constructor` property
- Property lookup through prototype chain

**ASObject additions** (if not already present):
```c
// In object.c/object.h
ASObject* getPrototype(ASObject* func);
void setPrototype(ASObject* func, ASObject* proto);
ASObject* getProtoProperty(ASObject* obj);  // Get __proto__
void setProtoProperty(ASObject* obj, ASObject* proto);  // Set __proto__
```

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct inheritance behavior
- [ ] Prototype chain is correctly established
- [ ] No build errors or warnings
- [ ] instanceof works correctly with inherited classes
- [ ] Documentation created
- [ ] Full test suite still passes

## Notes

- This is a complex OOP infrastructure opcode
- Requires mature object model with prototype support
- SWF 7+ feature (ActionScript 2.0)
- Coordinate with object model team if working in parallel
- Critical for class-based OOP in Flash

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
