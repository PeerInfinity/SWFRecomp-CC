# AS2 Opcode Implementation: NEXT_FRAME

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **NEXT_FRAME**

## Opcode Specification

**Opcode Name**: NEXT_FRAME
**Hex Value**: 0x04
**Category**: MovieClip Control
**Estimated Complexity**: MEDIUM

**Description**: Instructs Flash Player to go to the next frame in the current timeline.

**Operation**: Advance the current timeline to the next frame.

**Expected Behavior**:
- Advances the playhead to the next frame
- Does not change play/pause state
- Affects the current timeline (or SetTarget-modified timeline)
- No stack operations

**SWF Spec Reference** (swf-spec-19.txt:4310-4331):
```
ActionNextFrame instructs Flash Player to go to the next frame in the current file.

Field               Type                    Comment
ActionNextFrame     ACTIONRECORDHEADER      ActionCode = 0x04

ActionNextFrame does the following:
1. Instructs Flash Player to go to the next frame.
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that demonstrates frame advancement
6. **Setup Test Directory** - Create `SWFRecomp/tests/next_frame_swf_4/`
7. **Build and Verify** - Compile and verify behavior

## Test Cases

**Note**: Testing frame control requires a multi-frame SWF. The test should verify frame changes.

Test Case 1: Basic next frame
```actionscript
// Frame 1
trace("Frame 1");
nextFrame();

// Frame 2
trace("Frame 2");

// Frame 3
trace("Frame 3");
```
Expected output:
```
Frame 1
Frame 2
```

Test Case 2: Next frame at end of timeline
```actionscript
// Frame 1
trace("Start");
gotoAndStop(3);

// Frame 2
trace("Frame 2");

// Frame 3
trace("Frame 3");
nextFrame();  // Should do nothing (already at last frame)
trace("Still Frame 3");
```
Expected output:
```
Start
Frame 3
Still Frame 3
```

## Implementation Hints

**Pattern**: This is a timeline control operation with no stack interaction.

**Implementation approach**:
```c
void actionNextFrame(SWFAppContext* ctx)
{
    // Increment current frame index
    if (ctx->current_frame < ctx->total_frames - 1) {
        ctx->current_frame++;
        ctx->needs_render = 1;  // Mark that display needs update
    }
    // Note: Does not change play state
}
```

**Important Considerations**:
- This opcode requires access to the SWFAppContext structure
- Need to track: current_frame, total_frames
- Does NOT affect play/pause state (use ActionPlay/ActionStop for that)
- SetTarget can redirect which timeline is affected
- May need to execute frame actions after frame change

Reference similar operations:
- Frame control infrastructure from main runtime loop
- ActionStop, ActionPlay (for play state management)

## MovieClip Context

For NO_GRAPHICS mode testing, the implementation should:
1. Track current frame number
2. Output frame changes via trace
3. Not attempt actual rendering

For full graphics mode, the implementation would:
1. Update display list
2. Trigger rendering
3. Execute frame scripts

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] Frame advances correctly
- [ ] No build errors or warnings
- [ ] Edge cases handled (last frame, etc.)
- [ ] Documentation created
- [ ] Full test suite still passes

## Notes

- This is a frame control opcode, different from arithmetic/stack operations
- May require extending SWFAppContext structure to track frame state
- Coordinate with other frame control opcodes (PREV_FRAME, GOTO_FRAME)
- Consider SetTarget interaction (which timeline is affected)

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
