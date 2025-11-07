# Opcode Implementation Prompt: ActionCallMethod (0x52)

## Opcode Specification

**Opcode Name**: ActionCallMethod
**Hex Value**: 0x52
**Category**: Function/Method
**Estimated Complexity**: COMPLEX
**SWF Version**: 5+

## Description

Calls a method on an object with a specific `this` context. Pops the method name, object, argument count, and arguments from the stack, invokes the method, and pushes the return value back onto the stack.

## Stack Operation

**Before**: `[... object methodName numArgs arg1 arg2 ... argN]`
**After**: `[... returnValue]`

## Expected Behavior

1. Pop the method name (string) from the stack
2. Pop the object (target) from the stack
3. Pop the number of arguments (integer)
4. Pop N arguments from the stack
5. Look up the method on the object
6. Invoke the method with the object as `this` context
7. Push the return value onto the stack

**Method Invocation**:
- Method is called with object as `this`
- Arguments passed in order
- If method doesn't exist, push `undefined`
- Method can access object properties via `this`

## Implementation Status

✅ **Already Implemented**

- **Function**: `actionCallMethod()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Call Simple Method
```actionscript
var obj = {
    value: 10,
    getValue: function() {
        return this.value;
    }
};
trace(obj.getValue());
```
**Expected output**: `10`

### Test Case 2: Call Method with Arguments
```actionscript
var obj = {
    add: function(a, b) {
        return a + b;
    }
};
trace(obj.add(5, 3));
```
**Expected output**: `8`

### Test Case 3: Method Accessing This
```actionscript
var obj = {
    x: 5,
    y: 10,
    sum: function() {
        return this.x + this.y;
    }
};
trace(obj.sum());
```
**Expected output**: `15`

### Test Case 4: Call Non-Existent Method
```actionscript
var obj = {};
trace(obj.nonExistent());
```
**Expected output**: `undefined`

## Implementation Reference

This opcode requires:
- Method lookup on object
- Setting `this` context
- Argument passing
- Function invocation
- Return value handling

**Stack Layout**:
```
[... object, methodName, numArgs, arg1, arg2, ..., argN]
     ↑         ↑           ↑        ↑     ↑        ↑
  receiver   name       count    arguments (in order)
```

## Similar Opcodes

- `actionCallFunction` (0x3D) - Call function by name (no this binding)
- `actionCall` (0x9E) - Call frame actions
- `actionNewMethod` (0x53) - Call method as constructor

## Notes

- This is a **method call** with `this` binding
- Different from `actionCallFunction` which doesn't bind `this`
- Method name is a string (property name)
- Object becomes `this` inside the method
- Essential for object-oriented programming in AS2
- Arguments are in reverse order on stack (last arg on top)
- Return value replaces all the call parameters on stack
- **Complex** due to:
  - This binding
  - Method lookup
  - Scope management
  - Argument handling
