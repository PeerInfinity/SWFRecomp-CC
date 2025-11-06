# GET_PROPERTY Opcode Test (0x22)

This test verifies the GET_PROPERTY opcode implementation, which gets MovieClip properties by numeric index.

## Test Description

The test retrieves several properties from the _root MovieClip using numeric indices:

1. **Property 2 (_xscale)**: Should return 100
2. **Property 3 (_yscale)**: Should return 100
3. **Property 7 (_visible)**: Should return 1
4. **Property 6 (_alpha)**: Should return 100
5. **Property 0 (_x)**: Should return 0
6. **Property 1 (_y)**: Should return 0

## Property Index Table

| Property       | Index | Default Value |
|----------------|-------|---------------|
| _x             | 0     | 0             |
| _y             | 1     | 0             |
| _xscale        | 2     | 100           |
| _yscale        | 3     | 100           |
| _currentframe  | 4     | 1             |
| _totalframes   | 5     | 1             |
| _alpha         | 6     | 100           |
| _visible       | 7     | 1             |
| _width         | 8     | 550           |
| _height        | 9     | 400           |
| _rotation      | 10    | 0             |
| _target        | 11    | ""            |
| _name          | 13    | ""            |

## Expected Output

```
WASM SWF Runtime Loaded!
=== SWF Execution Started (NO_GRAPHICS mode) ===
[Frame 0]
100
100
1
100
0
0
[Tag] ShowFrame()
=== SWF Execution Completed ===
```

## Implementation Notes

- The simplified implementation uses a static _root MovieClip with default property values
- Empty target path ("") refers to _root
- Future enhancements will support dynamic MovieClip lookup and full target path parsing
