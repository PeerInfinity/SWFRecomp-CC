# Opcode Implementation Task: GET_PROPERTY

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **GET_PROPERTY**

## Opcode Specification

**Opcode Name**: GET_PROPERTY
**Hex Value**: 0x22
**Category**: MovieClip Properties
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Gets a MovieClip property by numeric index.

**Operation**: Pop property index, pop target, push property value.

**Expected Behavior** (from SWF Spec 19):
- Pop `index` off the stack (numeric property ID)
- Pop `target` off the stack (target path string)
- Retrieve the value of the property enumerated as `index` from the movie clip with target path `target`
- Push the property value to the stack
- Properties are identified by numeric indices (0-21)

**Stack Operations**:
```
Before: [... target_path, property_index]
After:  [... property_value]
```

## Property Index Table

The following properties are accessed by numeric index:

| Property       | Index | Property       | Index |
|----------------|-------|----------------|-------|
| _x             | 0     | _target        | 11    |
| _y             | 1     | _framesloaded  | 12    |
| _xscale        | 2     | _name          | 13    |
| _yscale        | 3     | _droptarget    | 14    |
| _currentframe  | 4     | _url           | 15    |
| _totalframes   | 5     | _highquality   | 16    |
| _alpha         | 6     | _focusrect     | 17    |
| _visible       | 7     | _soundbuftime  | 18    |
| _width         | 8     | _quality       | 19    |
| _height        | 9     | _xmouse        | 20    |
| _rotation      | 10    | _ymouse        | 21    |

**Note**: _quality, _xmouse, and _ymouse are available in SWF 5 and later.

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_GET_PROPERTY = 0x22` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test that gets MovieClip properties
6. **Setup Test Directory** - Create `SWFRecomp/tests/get_property_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Get position properties
```actionscript
// Assuming _root exists as a MovieClip
trace(_root._x);
trace(_root._y);
```
Expected output (example):
```
0
0
```

### Test Case 2: Get scale properties
```actionscript
trace(_root._xscale);
trace(_root._yscale);
```
Expected output:
```
100
100
```

### Test Case 3: Get visibility and alpha
```actionscript
trace(_root._visible);
trace(_root._alpha);
```
Expected output:
```
1
100
```

### Test Case 4: Get name property
```actionscript
trace(_root._name);
```
Expected output: `_root` or empty string

## Implementation Hints

**Pattern**: This is a MovieClip property access operation using numeric indices.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_GET_PROPERTY:
{
    out_script << "\t" << "// GetProperty" << endl
               << "\t" << "actionGetProperty(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionGetProperty(char* stack, u32* sp)
{
    // 1. Pop property index
    convertFloat(stack, sp);
    ActionVar index_var;
    popVar(stack, sp, &index_var);
    int prop_index = (int) index_var.value.f32;

    // 2. Pop target path
    convertString(stack, sp);
    const char* target = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // 3. Get the MovieClip object (for now, assume _root)
    // In a full implementation, you'd resolve the target path
    MovieClip* mc = getMovieClipByTarget(target);

    // 4. Get property value based on index
    float value = 0.0f;
    const char* str_value = NULL;

    switch (prop_index) {
        case 0:  // _x
            value = mc ? mc->x : 0.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 1:  // _y
            value = mc ? mc->y : 0.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 2:  // _xscale
            value = mc ? mc->xscale : 100.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 3:  // _yscale
            value = mc ? mc->yscale : 100.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 4:  // _currentframe
            value = mc ? (float)mc->currentframe : 1.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 5:  // _totalframes
            value = mc ? (float)mc->totalframes : 1.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 6:  // _alpha
            value = mc ? mc->alpha : 100.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 7:  // _visible
            value = mc ? (mc->visible ? 1.0f : 0.0f) : 1.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 8:  // _width
            value = mc ? mc->width : 0.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 9:  // _height
            value = mc ? mc->height : 0.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 10: // _rotation
            value = mc ? mc->rotation : 0.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
        case 11: // _target
            str_value = mc ? mc->target : "";
            PUSH_STR(str_value, strlen(str_value));
            break;
        case 13: // _name
            str_value = mc ? mc->name : "";
            PUSH_STR(str_value, strlen(str_value));
            break;
        // Add other properties as needed
        default:
            // Unknown property - push undefined or 0
            value = 0.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &value));
            break;
    }
}
```

### MovieClip Structure

You'll need to define or extend a MovieClip structure:

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
    // Add other properties as needed
} MovieClip;

// Simplified implementation - returns a default MovieClip
MovieClip* getMovieClipByTarget(const char* target) {
    // For initial implementation, return a default _root MovieClip
    static MovieClip root = {
        .x = 0.0f,
        .y = 0.0f,
        .xscale = 100.0f,
        .yscale = 100.0f,
        .rotation = 0.0f,
        .alpha = 100.0f,
        .width = 550.0f,
        .height = 400.0f,
        .visible = 1,
        .currentframe = 1,
        .totalframes = 1,
        .name = "_root",
        .target = "_root"
    };

    if (strcmp(target, "_root") == 0 || strcmp(target, "") == 0) {
        return &root;
    }
    return NULL;
}
```

### Similar Opcodes

Reference these opcodes:
- `actionSetProperty` (0x23) - complement operation for setting
- `actionGetMember` (0x4E) - similar property access pattern
- `actionGetVariable` - similar lookup pattern

### Edge Cases to Handle

- Invalid property index (out of range 0-21)
- Invalid target path (MovieClip not found)
- Empty target path (refers to current MovieClip)
- Properties that return strings vs numbers
- Unimplemented properties (12, 14-21)
- Properties not available in SWF 4

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/get_property_swf_4/README.md` - Test description and expected output

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Handles numeric property indices correctly
- [ ] Returns appropriate values for common properties (_x, _y, _visible, _alpha, etc.)
- [ ] String properties work correctly (_name, _target)
- [ ] Invalid indices handled gracefully
- [ ] Documentation created

## Important Notes

**Simplified Implementation**: For the initial pass:
- Implement only the most common properties (0-11, 13)
- Use a static _root MovieClip with default values
- Defer full target path resolution
- Skip SWF 5+ properties (_quality, _xmouse, _ymouse)

**Future Enhancements**:
- Full target path parsing and MovieClip lookup
- All 22 properties implemented
- Dynamic MovieClip values
- Mouse position tracking (_xmouse, _ymouse)
- Quality settings

**Coordination**: This opcode is the numeric-indexed counterpart to GET_MEMBER. They serve different purposes:
- GET_PROPERTY: Numeric indices, MovieClip-specific properties
- GET_MEMBER: String property names, general objects

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 2-4 hours
**Priority**: MEDIUM - MovieClip-specific functionality
