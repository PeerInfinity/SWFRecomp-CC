# AS2 Opcode Implementation: PREV_FRAME

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **PREV_FRAME**

## Opcode Specification

**Opcode Name**: PREV_FRAME
**Hex Value**: 0x05
**Category**: MovieClip Control
**Estimated Complexity**: MEDIUM

**Description**: Instructs Flash Player to go to the previous frame in the current timeline.

**Operation**: Move the current timeline to the previous frame.

**Expected Behavior**:
- Moves the playhead to the previous frame
- Does not change play/pause state
- Affects the current timeline (or SetTarget-modified timeline)
- No stack operations

**SWF Spec Reference** (swf-spec-19.txt:4332):
```
ActionPrevFrame (0x05) - Go to previous frame
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that demonstrates frame movement
6. **Setup Test Directory** - Create `SWFRecomp/tests/prev_frame_swf_4/`
7. **Build and Verify** - Compile and verify behavior

## Test Cases

Test Case 1: Basic previous frame
```actionscript
// Frame 1
trace("Frame 1");
gotoAndStop(3);

// Frame 2
trace("Frame 2");

// Frame 3
trace("Frame 3");
prevFrame();
```
Expected output:
```
Frame 1
Frame 3
Frame 2
```

Test Case 2: Previous frame at beginning of timeline
```actionscript
// Frame 1
trace("Frame 1");
prevFrame();  // Should do nothing (already at first frame)
trace("Still Frame 1");
```
Expected output:
```
Frame 1
Still Frame 1
```

## Implementation Hints

**Pattern**: This is a timeline control operation with no stack interaction.

**Implementation approach**:
```c
void actionPrevFrame(SWFAppContext* ctx)
{
    // Decrement current frame index
    if (ctx->current_frame > 0) {
        ctx->current_frame--;
        ctx->needs_render = 1;  // Mark that display needs update
    }
    // Note: Does not change play state
}
```

Reference similar operations:
- actionNextFrame (this is the reverse operation)
- Frame control infrastructure

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] Frame moves backward correctly
- [ ] No build errors or warnings
- [ ] Edge cases handled (first frame)
- [ ] Documentation created
- [ ] Full test suite still passes

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
