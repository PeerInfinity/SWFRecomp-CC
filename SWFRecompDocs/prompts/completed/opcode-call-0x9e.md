# Opcode Implementation Task: CALL

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **CALL**

## Opcode Specification

**Opcode Name**: CALL
**Hex Value**: 0x9E
**Category**: Control Flow
**Estimated Complexity**: COMPLEX (4-6 hours)

**Description**: Calls a subroutine (frame actions).

**Operation**: Pop frame identifier, execute frame actions, return.

**Expected Behavior** (from SWF Spec 19):
1. Pop a value off the stack. This value should be either:
   - A string that matches a frame label, OR
   - A number that indicates a frame number
2. The value can be prefixed by a target string that identifies the movie clip that contains the frame being called (e.g., "/clip:5" or "/clip:label")
3. If the frame is successfully located, the actions in the target frame are executed
4. After the actions in the target frame are executed, execution resumes at the instruction after the ActionCall instruction
5. If the frame cannot be found, nothing happens

**Stack Operations**:
```
Before: [... frame_identifier]
After:  [... ]
```

**Frame Identifier Format**:
- Frame number: `5` or `"5"`
- Frame label: `"start"`
- With target path: `"/movieclip:5"` or `"/movieclip:start"`

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_CALL = 0x9E` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with frame calls
6. **Setup Test Directory** - Create `SWFRecomp/tests/call_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Call frame by number
```actionscript
// Frame 1:
function setup() {
    trace("setup called");
}
call(2);  // Call frame 2

// Frame 2:
setup();
```
Expected output: `setup called`

### Test Case 2: Call frame by label
```actionscript
// Frame 1 (label: "init"):
trace("init frame");

// Frame 2:
call("init");
```
Expected output: `init frame`

### Test Case 3: Call with target path
```actionscript
// Main timeline frame 1:
call("/movieclip:2");
```
Expected output: (executes frame 2 of /movieclip)

### Test Case 4: Invalid frame (no error)
```actionscript
call("nonexistent");
trace("continued");
```
Expected output: `continued`

## Implementation Hints

**Pattern**: This is a frame-based subroutine call, different from function calls.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_CALL:
{
    out_script << "\t" << "// Call" << endl
               << "\t" << "actionCall(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionCall(char* stack, u32* sp)
{
    // 1. Pop frame identifier (string or number)
    ActionVar frame_var;
    convertString(stack, sp);  // Try to convert to string
    popVar(stack, sp, &frame_var);

    const char* frame_id = NULL;
    int frame_num = -1;
    const char* target_path = NULL;

    if (frame_var.type == ACTION_STACK_VALUE_STRING) {
        frame_id = (const char*) frame_var.value.u64;
    } else if (frame_var.type == ACTION_STACK_VALUE_F32) {
        frame_num = (int) frame_var.value.f32;
    }

    // 2. Parse target path if present (format: "/path:frame")
    if (frame_id && strchr(frame_id, ':')) {
        char* colon = strchr(frame_id, ':');
        target_path = strndup(frame_id, colon - frame_id);
        frame_id = colon + 1;

        // Try to parse as number
        char* endptr;
        long num = strtol(frame_id, &endptr, 10);
        if (*endptr == '\0') {
            frame_num = (int) num;
            frame_id = NULL;
        }
    }

    // 3. Locate and execute the frame
    MovieClip* target_mc = target_path ?
        getMovieClipByTarget(target_path) : getCurrentMovieClip();

    if (target_mc) {
        Frame* frame = NULL;

        if (frame_num >= 0) {
            // Lookup by frame number
            frame = getFrameByNumber(target_mc, frame_num);
        } else if (frame_id) {
            // Lookup by frame label
            frame = getFrameByLabel(target_mc, frame_id);
        }

        if (frame) {
            // Execute frame actions
            executeFrameActions(frame, stack, sp);
        }
        // If frame not found, do nothing (no error)
    }

    // 4. Continue execution after the frame's actions complete
}
```

### Helper Functions

```c
// Get current movie clip (simplified - return _root)
MovieClip* getCurrentMovieClip() {
    // TODO: Track current execution context
    return getRootMovieClip();
}

// Get movie clip by target path
MovieClip* getMovieClipByTarget(const char* path) {
    // Simplified: only support _root
    if (strcmp(path, "") == 0 || strcmp(path, "/") == 0 ||
        strcmp(path, "_root") == 0) {
        return getRootMovieClip();
    }
    // TODO: Parse complex paths like /clip1/clip2
    return NULL;
}

// Get frame by number
Frame* getFrameByNumber(MovieClip* mc, int frame_num) {
    if (frame_num >= 1 && frame_num <= mc->totalframes) {
        return &mc->frames[frame_num - 1];  // 1-based indexing
    }
    return NULL;
}

// Get frame by label
Frame* getFrameByLabel(MovieClip* mc, const char* label) {
    for (int i = 0; i < mc->totalframes; i++) {
        if (mc->frames[i].label && strcmp(mc->frames[i].label, label) == 0) {
            return &mc->frames[i];
        }
    }
    return NULL;
}

// Execute frame actions
void executeFrameActions(Frame* frame, char* stack, u32* sp) {
    if (frame->action_func) {
        // Call the generated action function for this frame
        frame->action_func(stack, sp);
    }
}
```

### Frame and MovieClip Structures

```c
typedef void (*ActionFunc)(char* stack, u32* sp);

typedef struct {
    int number;              // Frame number (1-based)
    const char* label;       // Frame label (optional)
    ActionFunc action_func;  // Generated function for frame actions
} Frame;

typedef struct {
    const char* name;
    const char* target;
    int currentframe;
    int totalframes;
    Frame* frames;
    // ... other properties
} MovieClip;
```

### Simplified Implementation

For initial implementation, you can simplify by:

```c
void actionCall(char* stack, u32* sp)
{
    // Pop frame identifier
    ActionVar frame_var;
    popVar(stack, sp, &frame_var);

    // For simplified implementation:
    // - Assume single timeline
    // - Support frame number only
    // - Log the call for debugging

    int frame_num = -1;
    if (frame_var.type == ACTION_STACK_VALUE_F32) {
        frame_num = (int) frame_var.value.f32;
    } else if (frame_var.type == ACTION_STACK_VALUE_STRING) {
        const char* str = (const char*) frame_var.value.u64;
        frame_num = atoi(str);
    }

    // TODO: Actually call the frame
    // For now, just acknowledge the call
    printf("// Call frame %d\n", frame_num);
}
```

### Similar Opcodes

Reference these opcodes:
- `actionGotoFrame` - frame navigation
- `actionCallFunction` (0x3D) - function calls (different from frame calls)
- `actionReturn` (0x3E) - returning from calls

### Edge Cases to Handle

- Invalid frame number (out of range)
- Invalid frame label (not found)
- Invalid target path
- Null or empty frame identifier
- Numeric string vs string label disambiguation
- Target path parsing errors
- Recursive calls (frame calling itself)
- Stack overflow from deep frame calls

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/call_swf_4/README.md` - Test description and expected output

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Frame number calls work
- [ ] Frame label calls work (if supported)
- [ ] Invalid frames handled gracefully (no crash)
- [ ] Execution resumes after frame actions
- [ ] Documentation created

## Important Notes

**Simplified Implementation**: For the initial pass:
- Support only frame number (not labels)
- Support only current MovieClip (not target paths)
- Log the call instead of executing frame actions
- Skip frame action execution infrastructure

**Frame vs Function Calls**: Important distinction:
- `CALL` (0x9E) - Calls frame actions (legacy, SWF 4)
- `CALL_FUNCTION` (0x3D) - Calls ActionScript functions (SWF 5+)

The CALL opcode is a legacy feature for calling frame scripts. Modern ActionScript uses CALL_FUNCTION instead.

**Frame Action Infrastructure**: This opcode requires:
- MovieClip structure with frames
- Frame labels mapping
- Frame action functions (generated by SWFRecomp)
- Target path resolution

**Testing Strategy**: Since this is a complex opcode:
- Start with simplified implementation (log only)
- Add frame number support
- Add frame label support
- Add target path support
- Test with multi-frame SWF files

**Future Enhancements**:
- Full target path parsing
- Frame label resolution
- Multiple MovieClip support
- Call stack tracking
- Recursion detection and limits

**Coordination**: This opcode relates to:
- Frame generation in SWFRecomp
- MovieClip structure definition
- Timeline management

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.

---

**Estimated Time**: 4-6 hours
**Priority**: MEDIUM - legacy feature, less common in modern SWF
