# Opcode Implementation Task: SET_PROPERTY

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **SET_PROPERTY**

## Opcode Specification

**Opcode Name**: SET_PROPERTY
**Hex Value**: 0x23
**Category**: MovieClip Properties
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Sets a MovieClip property by numeric index.

**Operation**: Pop value, pop property index, pop target, set property.

**Expected Behavior** (from SWF Spec 19):
- Pop `value` off the stack (new property value)
- Pop `index` off the stack (numeric property ID)
- Pop `target` off the stack (target path string)
- Set the property enumerated as `index` in the movie clip with target path `target` to the value `value`
- Properties are identified by numeric indices (0-21)

**Stack Operations**:
```
Before: [... target_path, property_index, value]
After:  [... ]
```

## Property Index Table

The following properties can be set by numeric index:

| Property       | Index | Type   | Settable |
|----------------|-------|--------|----------|
| _x             | 0     | Number | Yes      |
| _y             | 1     | Number | Yes      |
| _xscale        | 2     | Number | Yes      |
| _yscale        | 3     | Number | Yes      |
| _currentframe  | 4     | Number | No       |
| _totalframes   | 5     | Number | No       |
| _alpha         | 6     | Number | Yes      |
| _visible       | 7     | Number | Yes      |
| _width         | 8     | Number | Yes      |
| _height        | 9     | Number | Yes      |
| _rotation      | 10    | Number | Yes      |
| _target        | 11    | String | No       |
| _framesloaded  | 12    | Number | No       |
| _name          | 13    | String | Yes      |
| _droptarget    | 14    | String | No       |
| _url           | 15    | String | No       |
| _highquality   | 16    | Number | Yes      |
| _focusrect     | 17    | Number | Yes      |
| _soundbuftime  | 18    | Number | Yes      |
| _quality       | 19    | String | Yes      |
| _xmouse        | 20    | Number | No       |
| _ymouse        | 21    | Number | No       |

**Note**: Some properties are read-only (currentframe, totalframes, target, framesloaded, droptarget, url, xmouse, ymouse).

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_SET_PROPERTY = 0x23` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test that sets MovieClip properties
6. **Setup Test Directory** - Create `SWFRecomp/tests/set_property_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Set position properties
```actionscript
_root._x = 100;
_root._y = 200;
trace(_root._x);
trace(_root._y);
```
Expected output:
```
100
200
```

### Test Case 2: Set scale properties
```actionscript
_root._xscale = 50;
_root._yscale = 150;
trace(_root._xscale);
trace(_root._yscale);
```
Expected output:
```
50
150
```

### Test Case 3: Set visibility and alpha
```actionscript
_root._alpha = 50;
_root._visible = 0;
trace(_root._alpha);
trace(_root._visible);
```
Expected output:
```
50
0
```

### Test Case 4: Set rotation
```actionscript
_root._rotation = 45;
trace(_root._rotation);
```
Expected output: `45`

## Implementation Hints

**Pattern**: This is a MovieClip property assignment operation, the complement of GET_PROPERTY.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_SET_PROPERTY:
{
    out_script << "\t" << "// SetProperty" << endl
               << "\t" << "actionSetProperty(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionSetProperty(char* stack, u32* sp)
{
    // 1. Pop value
    ActionVar value_var;
    popVar(stack, sp, &value_var);

    // 2. Pop property index
    convertFloat(stack, sp);
    ActionVar index_var;
    popVar(stack, sp, &index_var);
    int prop_index = (int) index_var.value.f32;

    // 3. Pop target path
    convertString(stack, sp);
    const char* target = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 4. Get the MovieClip object
    MovieClip* mc = getMovieClipByTarget(target);
    if (!mc) return; // Invalid target

    // 5. Set property value based on index
    // Convert value to float for numeric properties
    float num_value = 0.0f;
    const char* str_value = NULL;

    if (value_var.type == ACTION_STACK_VALUE_F32) {
        num_value = value_var.value.f32;
    } else if (value_var.type == ACTION_STACK_VALUE_STRING) {
        str_value = (const char*) value_var.value.u64;
        num_value = atof(str_value);
    }

    switch (prop_index) {
        case 0:  // _x
            mc->x = num_value;
            break;
        case 1:  // _y
            mc->y = num_value;
            break;
        case 2:  // _xscale
            mc->xscale = num_value;
            break;
        case 3:  // _yscale
            mc->yscale = num_value;
            break;
        case 6:  // _alpha
            mc->alpha = num_value;
            break;
        case 7:  // _visible
            mc->visible = (num_value != 0.0f);
            break;
        case 8:  // _width
            mc->width = num_value;
            break;
        case 9:  // _height
            mc->height = num_value;
            break;
        case 10: // _rotation
            mc->rotation = num_value;
            break;
        case 13: // _name
            if (str_value) {
                // Update name (may need to free old name)
                mc->name = strdup(str_value);
            }
            break;
        // Read-only properties - ignore
        case 4:  // _currentframe
        case 5:  // _totalframes
        case 11: // _target
        case 12: // _framesloaded
        case 14: // _droptarget
        case 15: // _url
        case 20: // _xmouse
        case 21: // _ymouse
            // Do nothing - these are read-only
            break;
        default:
            // Unknown property - ignore
            break;
    }
}
```

### MovieClip Structure

Use the same MovieClip structure as GET_PROPERTY:

```c
typedef struct {
    float x, y;
    float xscale, yscale;
    float rotation;
    float alpha;
    float width, height;
    int visible;
    int currentframe;
    int totalframes;
    const char* name;
    const char* target;
} MovieClip;
```

### Similar Opcodes

Reference these opcodes:
- `actionGetProperty` (0x22) - complement operation for getting
- `actionSetMember` (0x4F) - similar property assignment pattern
- `actionSetVariable` - similar assignment pattern

### Edge Cases to Handle

- Invalid property index (out of range 0-21)
- Invalid target path (MovieClip not found)
- Empty target path (refers to current MovieClip)
- Read-only properties (should be ignored, not error)
- Type conversion (string to number, number to boolean)
- Setting _name property (may need string duplication)
- Negative values for _alpha, scales
- Out-of-range rotation values (> 360 degrees)

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/set_property_swf_4/README.md` - Test description and expected output

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Handles numeric property indices correctly
- [ ] Sets writable properties correctly (_x, _y, _rotation, _alpha, _visible, etc.)
- [ ] Ignores read-only properties gracefully
- [ ] Type conversion works (string to number)
- [ ] Invalid indices handled gracefully
- [ ] Documentation created

## Important Notes

**Simplified Implementation**: For the initial pass:
- Implement only the most common writable properties (0-3, 6-10, 13)
- Silently ignore read-only properties
- Use a static _root MovieClip
- Defer full target path resolution
- Skip SWF 5+ properties (_highquality, _focusrect, _soundbuftime, _quality)

**Read-Only Properties**: The following properties should NOT be modified:
- _currentframe (4)
- _totalframes (5)
- _target (11)
- _framesloaded (12)
- _droptarget (14)
- _url (15)
- _xmouse (20)
- _ymouse (21)

**Future Enhancements**:
- Full target path parsing and MovieClip lookup
- All 22 properties implemented
- Validation of property values (ranges, types)
- Error reporting for invalid operations
- Memory management for string properties

**Coordination**: This opcode works with GET_PROPERTY (0x22):
- Both use the same numeric property indices
- Same MovieClip structure
- Consistent property value types

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 2-4 hours
**Priority**: MEDIUM - MovieClip-specific functionality
