# GET_PROPERTY Opcode Test (0x22)

This test verifies the GET_PROPERTY opcode implementation, which gets MovieClip properties by numeric index.

## Test Description

The test retrieves all 22 properties (indices 0-21) from the _root MovieClip using numeric indices.

## Property Index Table (Complete)

| Index | Property       | Type   | Default Value | Description                          |
|-------|----------------|--------|---------------|--------------------------------------|
| 0     | _x             | Number | 0             | X position in pixels                 |
| 1     | _y             | Number | 0             | Y position in pixels                 |
| 2     | _xscale        | Number | 100           | Horizontal scale percentage          |
| 3     | _yscale        | Number | 100           | Vertical scale percentage            |
| 4     | _currentframe  | Number | 1             | Current frame number (1-based)       |
| 5     | _totalframes   | Number | 1             | Total number of frames               |
| 6     | _alpha         | Number | 100           | Opacity percentage                   |
| 7     | _visible       | Number | 1             | Visibility (0=hidden, 1=visible)     |
| 8     | _width         | Number | 550           | Width in pixels                      |
| 9     | _height        | Number | 400           | Height in pixels                     |
| 10    | _rotation      | Number | 0             | Rotation in degrees                  |
| 11    | _target        | String | "_root"       | Target path                          |
| 12    | _framesloaded  | Number | 1             | Number of frames loaded (streaming)  |
| 13    | _name          | String | "_root"       | Instance name                        |
| 14    | _droptarget    | String | ""            | Drop target path (drag and drop)     |
| 15    | _url           | String | ""            | URL of the SWF file                  |
| 16    | _highquality   | Number | 1             | Quality setting (deprecated)         |
| 17    | _focusrect     | Number | 1             | Focus rectangle visibility           |
| 18    | _soundbuftime  | Number | 5             | Sound buffer time in seconds         |
| 19    | _quality       | Number | 2             | Quality setting (0=low, 1=high, 2=best) - SWF 5+ |
| 20    | _xmouse        | Number | 0             | Mouse X position - SWF 5+            |
| 21    | _ymouse        | Number | 0             | Mouse Y position - SWF 5+            |

## Expected Output

```
WASM SWF Runtime Loaded!
=== SWF Execution Started (NO_GRAPHICS mode) ===
[Frame 0]
0
0
100
100
1
1
100
1
550
400
0
_root
1
_root


1
1
5
2
0
0
[Tag] ShowFrame()
=== SWF Execution Completed ===
```

## Implementation Notes

- The implementation uses a static _root MovieClip with default property values
- Empty target path ("") refers to _root
- All 22 properties are now fully implemented
- Properties 19-21 (_quality, _xmouse, _ymouse) are SWF 5+ but work in SWF 4 mode with default values
- In NO_GRAPHICS mode:
  - Mouse properties (_xmouse, _ymouse) return 0
  - _droptarget and _url return empty strings
  - _framesloaded equals _totalframes (all frames loaded)

## Test Coverage

This test verifies:
- ✅ All 22 numeric property indices (0-21)
- ✅ Numeric properties return correct float values
- ✅ String properties (_target, _name, _droptarget, _url) return correct strings
- ✅ Empty string target path correctly refers to _root
- ✅ Default values for properties in NO_GRAPHICS mode

## Edge Cases Covered

- Empty string properties (_droptarget, _url)
- Boolean-like properties (_visible, _highquality, _focusrect)
- Frame-based properties (_currentframe, _totalframes, _framesloaded)
- Position and transform properties
- Quality and performance settings
- Mouse position (NO_GRAPHICS mode)
