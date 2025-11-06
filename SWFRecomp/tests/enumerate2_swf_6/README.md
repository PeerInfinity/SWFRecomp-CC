# ENUMERATE2 Opcode Test (SWF 6)

## Description

This test verifies the ENUMERATE2 (0x55) opcode implementation.

ENUMERATE2 is the SWF 6+ version of property enumeration that takes the object directly from the stack (instead of a variable name like ENUMERATE 0x46).

## Test Case

The test creates an object with three properties:
```actionscript
{a: 1, b: 2, c: 3}
```

Then calls ENUMERATE2 on it, which should:
1. Pop the object from stack
2. Push null as terminator
3. Push each property name onto the stack (in reverse order)

## Expected Output

The test traces each enumerated property name. The expected output is the three property names (order may vary):
```
a
b
c
```

Followed by a null value (may appear as empty line or "null"), and finally:
```
Done
```

## Implementation Notes

- ENUMERATE2 enumerates properties in the order they were added to the object
- The null terminator is pushed before the property names so it ends up at the bottom
- Property names are pushed in reverse order so they can be popped in the correct order
- For arrays, ENUMERATE2 should enumerate indices as strings ("0", "1", "2", etc.)

## Opcode Details

- **Opcode**: 0x55
- **Name**: ENUMERATE2
- **SWF Version**: 6+
- **Stack Effect**: Pops object, pushes null + property names
