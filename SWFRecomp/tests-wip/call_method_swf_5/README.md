# ActionCallMethod (0x52) Test

## Overview
This test validates the ActionCallMethod opcode (0x52), which calls a method on an object with a specific `this` context.

**Opcode**: 0x52
**Category**: Function/Method
**Complexity**: COMPLEX
**SWF Version**: 5+

## Opcode Description
ActionCallMethod pops the method name, object, argument count, and arguments from the stack, invokes the method with the object as `this` context, and pushes the return value back onto the stack.

### Stack Operation
**Before**: `[... object methodName numArgs arg1 arg2 ... argN]`
**After**: `[... returnValue]`

### Expected Behavior
1. Pop the method name (string) from the stack
2. Pop the object (target) from the stack
3. Pop the number of arguments (integer)
4. Pop N arguments from the stack
5. Look up the method on the object
6. Invoke the method with the object as `this` context
7. Push the return value onto the stack

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

## Implementation Status

### Runtime Implementation
✅ **Implemented** in `SWFModernRuntime/src/actionmodern/action.c`
- Function: `actionCallMethod(char* stack, u32* sp, char* str_buffer)`
- Location: action.c:2579

**Current Limitations**:
- Function invocation is stubbed (returns `undefined`)
- Requires complete function/object system implementation
- `this` binding mechanism needs to be fully implemented
- Function storage in ActionVar needs completion

### Test Status
⚠️ **Partial** - Test structure created but awaiting full runtime support

**Blockers**:
1. `ACTION_STACK_VALUE_FUNCTION` type needs full implementation
2. Function invocation mechanism required
3. `this` context binding needs completion
4. DefineFunction/DefineFunction2 opcodes needed

## Dependencies

This opcode requires the following supporting opcodes to be fully functional:
- **InitObject** (0x43) - Create objects
- **SetMember** (0x4F) - Set object properties
- **DefineFunction** (0x9B) - Define functions (SWF5+)
- **DefineFunction2** (0x8E) - Define functions with advanced features (SWF7+)

## Related Opcodes

- **actionCallFunction** (0x3D) - Call function by name (no this binding)
- **actionCall** (0x9E) - Call frame actions
- **actionNewMethod** (0x53) - Call method as constructor

## Notes

- This is a **method call** with `this` binding, different from `actionCallFunction`
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

## Running This Test

```bash
cd SWFRecomp/tests/call_method_swf_5
mkdir -p build && cd build
cmake ..
make
./call_method_swf_5 > output.txt
cd ..
./validate.py build/output.txt
```

## Implementation Reference

The implementation in action.c:2579 follows this structure:

1. **Pop method name**: Convert to string and pop from stack
2. **Pop object**: Get the receiver object
3. **Pop arg count**: Get number of arguments to pass
4. **Pop arguments**: Collect arguments in reverse order
5. **Lookup method**: Find method property on object
6. **Invoke function**: Call with `this` binding (currently stubbed)
7. **Push result**: Push return value or `undefined`

## Future Enhancements

Once the function/object system is complete:
1. Update test to use actual function definitions
2. Create SWF bytecode generator (`create_test_swf.py`)
3. Test actual method invocation and return values
4. Add edge cases (null objects, invalid method names, etc.)
