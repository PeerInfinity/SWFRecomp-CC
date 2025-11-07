# AS2 Opcode Implementation Task: ActionGotoFrame

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionGotoFrame**

## Opcode Specification

**Opcode Name**: ActionGotoFrame
**Hex Value**: 0x81
**Category**: Movie Control
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Instructs Flash Player to go to the specified frame in the current movie clip.

**Operation**: Jump to a specific frame number (frame index embedded in action record).

**Expected Behavior** (from SWF Spec 19):
- Goes to the specified frame in the current file
- Frame is specified as a UI16 frame index (0-based)
- Does not start playing automatically (stops at the frame)
- Action record contains: ActionCode = 0x81, Length = 2, Frame = UI16

**Action Record Format**:
```
Field          Type    Comment
ActionCode     UI8     0x81
Length         UI16    Always 2
Frame          UI16    Frame index (0-based)
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_GOTO_FRAME = 0x81` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (parse Frame parameter)
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create multi-frame SWF with gotoFrame calls
6. **Setup Test Directory** - Create `SWFRecomp/tests/goto_frame_swf_3/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Go to specific frame
```actionscript
// Frame 1:
trace("Frame 1");
gotoAndStop(3);  // Go to frame 3 (index 2)

// Frame 2:
trace("Frame 2 (skipped)");

// Frame 3:
trace("Frame 3");
```
Expected output:
```
Frame 1
Frame 3
```

### Test Case 2: Go to first frame
```actionscript
// Frame 1:
trace("Frame 1");

// Frame 2:
gotoAndStop(1);  // Go back to frame 1
```
Expected output:
```
Frame 1
Frame 1
```

### Test Case 3: Multiple frames
```actionscript
// Frame 1:
trace("Start");
gotoAndStop(5);

// Frame 5:
trace("Frame 5");
stop();
```
Expected output:
```
Start
Frame 5
```

## Implementation Hints

**Pattern**: This is a control flow operation that affects timeline navigation.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_GOTO_FRAME:
{
    // Read the frame index from the action record
    u16 frame_index;
    in.read((char*)&frame_index, sizeof(u16));

    out_script << "\t" << "// GotoFrame: " << frame_index << endl
               << "\t" << "actionGotoFrame(stack, sp, " << frame_index << ");" << endl;
    break;
}
```

**SWFModernRuntime API** (in action.h):
```c
void actionGotoFrame(char* stack, u32* sp, u16 frame);
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionGotoFrame(char* stack, u32* sp, u16 frame)
{
    // Get current movie clip context
    MovieClip* mc = getCurrentMovieClip();
    if (!mc) {
        return;
    }

    // Validate frame index
    if (frame >= mc->totalframes) {
        // Invalid frame, ignore
        return;
    }

    // Set current frame (0-based index)
    mc->currentframe = frame + 1;  // Convert to 1-based

    // Stop playback
    mc->playing = false;

    // Execute frame actions (if any)
    if (mc->frames[frame].action_func) {
        mc->frames[frame].action_func(stack, sp);
    }
}
```

### MovieClip Structure

```c
typedef void (*ActionFunc)(char* stack, u32* sp);

typedef struct {
    int number;              // Frame number (1-based)
    const char* label;       // Frame label (optional)
    ActionFunc action_func;  // Generated function for frame actions
} Frame;

typedef struct {
    const char* name;
    int currentframe;        // Current frame (1-based)
    int totalframes;         // Total number of frames
    bool playing;            // Is timeline playing?
    Frame* frames;           // Array of frames
    // ... other properties
} MovieClip;
```

### Simplified Implementation

For initial implementation, you can simplify:

```c
void actionGotoFrame(char* stack, u32* sp, u16 frame)
{
    // Simplified: just log the frame change
    printf("// GotoFrame: %d\n", frame);

    // TODO: Implement actual frame navigation
    // This requires:
    // - MovieClip structure
    // - Frame management
    // - Timeline playback control
}
```

### Similar Opcodes

Reference these opcodes:
- `actionGotoFrame2` (0x9F) - Stack-based version with play flag
- `actionGoToLabel` (0x8C) - Go to labeled frame
- `actionPlay` (0x06) - Start playing
- `actionStop` (0x07) - Stop playing
- `actionNextFrame` (0x04) - Go to next frame
- `actionPreviousFrame` (0x05) - Go to previous frame

### Edge Cases to Handle

- Frame index out of range (negative or >= totalframes)
- Current frame same as target frame
- Frame with no actions
- Null or invalid movie clip context
- Going to frame while already on that frame

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/goto_frame_swf_3/README.md` - Test description and expected output
- Document frame indexing (0-based in action vs 1-based in Flash)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Frame parameter correctly parsed from action record
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Frame navigation works correctly
- [ ] Out-of-range frames handled gracefully
- [ ] Playback stops at target frame
- [ ] Documentation created

## Important Notes

**Frame Indexing**: Important distinction:
- SWF action record: 0-based frame index (frame 1 = index 0)
- Flash UI: 1-based frame numbers (first frame is frame 1)
- Ensure proper conversion in your implementation

**Difference from GotoFrame2 (0x9F)**:
- GotoFrame (0x81): Frame index embedded in action record
- GotoFrame2 (0x9F): Frame from stack, supports labels, has play flag

**Behavior**: GotoFrame stops playback at the target frame. To go to a frame and continue playing, use GotoFrame2 with the play flag set.

**Flash Version**: Available in SWF 3+

**ActionScript Equivalents**:
```actionscript
gotoAndStop(5);     // Goes to frame 5, stops
gotoAndPlay(5);     // Goes to frame 5, plays (use GotoFrame2)
```

**Frame Actions**: When jumping to a frame, the frame's actions should be executed. This means calling the generated action function for that frame.

**Testing Strategy**:
- Start with simplified implementation (log only)
- Add frame navigation (change currentframe)
- Add frame action execution
- Test with multi-frame SWFs
- Test edge cases (out of range, etc.)

**Coordination**: This opcode relates to:
- Timeline management
- MovieClip structure
- Frame generation in SWFRecomp
- Playback control opcodes (Play, Stop)

**Action Record Parsing**: Unlike stack-based opcodes, this opcode has data embedded in the action record:
```cpp
// In action.cpp translation:
case SWF_ACTION_GOTO_FRAME:
{
    u16 frame_index;
    in.read((char*)&frame_index, sizeof(u16));
    // Use frame_index...
}
```

**Frame Management**: Considerations for implementation:
- Update currentframe property
- Set playing flag to false
- Execute frame actions
- Handle display list updates (if needed)
- Reset timeline state as needed

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
