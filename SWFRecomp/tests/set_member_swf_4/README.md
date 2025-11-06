# SET_MEMBER Opcode Test (0x4F)

## Test Description

This test verifies the SET_MEMBER opcode (0x4F) which sets a property value on an object.

## Test Code (Equivalent ActionScript)

```actionscript
var obj = {x: 10};
obj.x = 20;
trace(obj.x);
```

## Expected Output

```
20
```

## Opcodes Used

- **PUSH (0x96)**: Push values onto the stack
- **INIT_OBJECT (0x43)**: Create an object with initial properties
- **DUPLICATE (0x3D)**: Duplicate the top stack value
- **SET_MEMBER (0x4F)**: Set a property on an object
- **GET_MEMBER (0x4E)**: Get a property from an object
- **TRACE (0x26)**: Output a value to the console

## Test Breakdown

1. **Create object**: Initialize object with property `x = 10`
2. **Duplicate object**: Keep a reference for later operations
3. **Set property**: Change `x` to `20` using SET_MEMBER
4. **Get property**: Read `x` using GET_MEMBER
5. **Trace**: Output the value (should be `20`)

## Implementation Notes

- SET_MEMBER pops three values from the stack: value, property name, and object
- The property is created if it doesn't exist, or updated if it does
- Reference counting is handled by the setProperty() helper function
- Works with objects created by INIT_OBJECT

## Related Opcodes

- **GET_MEMBER (0x4E)**: Complement operation for reading properties
- **INIT_OBJECT (0x43)**: Creates objects for testing
- **INIT_ARRAY (0x42)**: Creates arrays (SET_MEMBER also works with arrays)
