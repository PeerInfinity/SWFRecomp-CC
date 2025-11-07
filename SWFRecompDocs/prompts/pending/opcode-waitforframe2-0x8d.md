# AS2 Opcode Implementation Task: ActionWaitForFrame2

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionWaitForFrame2**

## Opcode Specification

**Opcode Name**: ActionWaitForFrame2
**Hex Value**: 0x8D
**Category**: Movie Control / Streaming
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Stack-based version of WaitForFrame. Waits for a frame to be loaded before executing subsequent actions.

**Operation**: Pop frame from stack, check if loaded; if not, skip the next N actions.

**Expected Behavior** (from SWF Spec 19):
- Stack-based version of ActionWaitForFrame (0x8A)
- Pops a frame off the stack
- If the frame is loaded, skip the next n actions (where n = SkipCount)
- Frame is evaluated the same way as ActionGotoFrame2 (can be number or label)
- Action record contains: ActionCode = 0x8D, Length = 1, SkipCount (UI8)

**Stack Operations**:
```
Before: [... frame]
After:  [... ]
```

**Action Record Format**:
```
Field          Type    Comment
ActionCode     UI8     0x8D
Length         UI16    Always 1
SkipCount      UI8     Number of actions to skip if frame not loaded
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_WAIT_FOR_FRAME2 = 0x8D` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (parse SkipCount)
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with frame waiting
6. **Setup Test Directory** - Create `SWFRecomp/tests/wait_for_frame2_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Frame number already loaded
```actionscript
// Frame 1:
var frame = 5;
ifFrameLoaded(frame) {
    trace("Frame 5 loaded");
} else {
    trace("Frame 5 not loaded");
}
```
Expected output: `Frame 5 loaded`

### Test Case 2: Frame label loaded
```actionscript
// Frame 1:
var label = "scene2";
ifFrameLoaded(label) {
    trace("Scene2 loaded");
}
trace("Continued");
```
Expected output:
```
Scene2 loaded
Continued
```

### Test Case 3: Dynamic frame check
```actionscript
// Frame 1:
var totalFrames = _totalframes;
ifFrameLoaded(totalFrames) {
    gotoAndPlay(2);
} else {
    gotoAndPlay(1);  // Loop until loaded
}
```
Expected behavior: Advances when all frames loaded

### Test Case 4: Frame not loaded
```actionscript
var frame = 1000;  // Doesn't exist
ifFrameLoaded(frame) {
    trace("This won't print");
}
trace("Continued");
```
Expected output: `Continued`

## Implementation Hints

**Pattern**: This is a stack-based conditional control flow operation for streaming content.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_WAIT_FOR_FRAME2:
{
    // Read skip count (UI8)
    u8 skip_count;
    in.read((char*)&skip_count, sizeof(u8));

    out_script << "\t" << "// WaitForFrame2: skip=" << (int)skip_count << endl
               << "\t" << "if (!actionWaitForFrame2(stack, sp)) {" << endl
               << "\t\t" << "// Skip next " << (int)skip_count << " actions" << endl
               << "\t\t" << "goto skip_label_" << label_counter << ";" << endl
               << "\t" << "}" << endl;

    // Generate code for the next skip_count actions with a skip label
    // Similar complexity to WaitForFrame (0x8A)

    break;
}
```

**SWFModernRuntime API** (in action.h):
```c
bool actionWaitForFrame2(char* stack, u32* sp);
```

**SWFModernRuntime Implementation** (in action.c):
```c
bool actionWaitForFrame2(char* stack, u32* sp)
{
    // Pop frame identifier from stack
    ActionVar frame_var;
    popVar(stack, sp, &frame_var);

    // Get current movie clip
    MovieClip* mc = getCurrentMovieClip();
    if (!mc) {
        return false;
    }

    int frame_index = -1;

    // Parse frame identifier (number or label)
    if (frame_var.type == ACTION_STACK_VALUE_F32) {
        // Frame number (1-based)
        frame_index = (int)frame_var.value.f32 - 1;  // Convert to 0-based
    }
    else if (frame_var.type == ACTION_STACK_VALUE_STRING) {
        const char* frame_str = (const char*)frame_var.value.u64;

        // Try to parse as number
        char* endptr;
        long frame_num = strtol(frame_str, &endptr, 10);
        if (*endptr == '\0' && frame_num > 0) {
            // It's a numeric string
            frame_index = (int)frame_num - 1;  // Convert to 0-based
        } else {
            // It's a label
            frame_index = findFrameByLabel(mc, frame_str);
        }
    }

    // Check if frame is loaded
    if (frame_index >= 0 && frame_index < mc->totalframes) {
        return isFrameLoaded(mc, frame_index);
    }

    return false;  // Frame doesn't exist
}

bool isFrameLoaded(MovieClip* mc, int frame_index)
{
    // Check if frame is within loaded range
    if (frame_index < 0 || frame_index >= mc->totalframes) {
        return false;
    }

    // In streaming SWF, frames are loaded progressively
    // For now, assume all frames are loaded (non-streaming)
    if (frame_index < mc->frames_loaded) {
        return true;
    }

    return false;
}
```

### Simplified Implementation

For initial implementation, you can simplify:

```c
bool actionWaitForFrame2(char* stack, u32* sp)
{
    // Pop frame identifier
    ActionVar frame_var;
    popVar(stack, sp, &frame_var);

    // Simplified: assume all frames are loaded
    MovieClip* mc = getCurrentMovieClip();

    if (!mc) {
        return false;
    }

    // For non-streaming SWF, all frames are loaded
    printf("// WaitForFrame2 (frame from stack, loaded)\n");
    return true;
}
```

### Similar Opcodes

Reference these opcodes:
- `actionWaitForFrame` (0x8A) - Frame number embedded in action record
- `actionGotoFrame2` (0x9F) - Also pops frame from stack
- `actionIf` (0x9D) - Conditional branching
- `actionJump` (0x99) - Unconditional jump

### Edge Cases to Handle

- Frame number out of range
- Frame label not found
- String that looks like number ("5")
- Empty string
- NULL value
- Skip count of 0
- Negative frame numbers

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/wait_for_frame2_swf_4/README.md` - Test description and expected output
- Document difference from WaitForFrame (0x8A)
- Explain frame evaluation (number vs label)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] SkipCount parameter correctly parsed from action record
- [ ] Frame popped from stack correctly
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Frame number evaluation works
- [ ] Frame label evaluation works
- [ ] Action skipping implemented correctly
- [ ] Edge cases handled gracefully
- [ ] Documentation created

## Important Notes

**Difference from WaitForFrame (0x8A)**:
- WaitForFrame (0x8A): Frame number embedded in action record (static)
- WaitForFrame2 (0x8D): Frame from stack (dynamic, expression-based)

**Frame Evaluation**: Like GotoFrame2, this opcode evaluates the frame:
- If number: Frame index (1-based)
- If string that's numeric: Parse as frame number
- If string that's not numeric: Treat as frame label

**Streaming Context**: Designed for streaming SWF files:
- Check if frame data has been downloaded yet
- Skip actions if not loaded (e.g., show loading screen)
- Modern context: most files load instantly

**Flash Version**: Available in SWF 4+

**ActionScript Equivalent**:
```actionscript
var frame = 10;
ifFrameLoaded(frame) {
    // Frame is loaded
} else {
    // Frame not loaded, skip this block
}

// Or check _framesloaded property:
if (_framesloaded >= frame) {
    // Frame loaded
}
```

**Preloader Pattern** (Dynamic):
```actionscript
// Frame 1 (Preloader):
var target = _totalframes;
if (_framesloaded < target) {
    // Show loading bar
    loadingBar._xscale = (_framesloaded / target) * 100;
    gotoAndPlay(1);  // Loop
} else {
    gotoAndPlay(2);  // Start movie
}
```

**Skip Logic**: The skip mechanism is the same as WaitForFrame:
- If frame not loaded, skip next N actions
- Need to calculate byte offset or generate conditional jump
- Requires parsing action stream to know sizes

**Testing Strategy**:
- Start with simplified implementation (always loaded)
- Add frame popping from stack
- Implement frame number evaluation
- Add frame label evaluation
- Test with various frame types
- Add action skip logic
- Test edge cases

**Coordination**: This opcode relates to:
- Frame loading infrastructure
- Streaming SWF support
- Control flow (jump/skip logic)
- MovieClip frame management
- Frame label lookup
- Stack operations

**Translation Complexity**: Similar to WaitForFrame (0x8A):
- Need to parse ahead to calculate skip offset
- Need to generate conditional jump in output
- Need to handle action stream parsing

**Frame Number vs Label**: Similar to GotoFrame2:
```c
// Check if it's a number or label
if (is_numeric(frame_var)) {
    // Use as frame number
} else {
    // Look up frame label
}
```

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
