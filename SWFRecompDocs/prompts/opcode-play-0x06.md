# AS2 Opcode Implementation: PLAY

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **PLAY**

## Opcode Specification

**Opcode Name**: PLAY
**Hex Value**: 0x06
**Category**: MovieClip Control
**Estimated Complexity**: MEDIUM

**Description**: Instructs Flash Player to start playing at the current frame.

**Operation**: Sets the playback state to playing.

**Expected Behavior**:
- Starts playback from current frame
- Timeline will advance automatically on each frame tick
- Affects the current timeline (or SetTarget-modified timeline)
- No stack operations

**SWF Spec Reference** (swf-spec-19.txt:4338-4352):
```
ActionPlay instructs Flash Player to start playing at the current frame.

Field       Type                    Comment
ActionPlay  ACTIONRECORDHEADER      ActionCode = 0x06

ActionPlay does the following:
1. Instructs Flash Player to start playing the file at the current frame.
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that demonstrates playback control
6. **Setup Test Directory** - Create `SWFRecomp/tests/play_swf_4/`
7. **Build and Verify** - Compile and verify behavior

## Test Cases

Test Case 1: Basic play
```actionscript
// Frame 1
trace("Frame 1");
stop();
trace("Stopped");
play();
trace("Playing");

// Frame 2
trace("Frame 2");
stop();
```
Expected output:
```
Frame 1
Stopped
Playing
Frame 2
```

Test Case 2: Play when already playing
```actionscript
// Frame 1
trace("Frame 1");
play();
play();  // Should be no-op (already playing)

// Frame 2
trace("Frame 2");
stop();
```
Expected output:
```
Frame 1
Frame 2
```

## Implementation Hints

**Pattern**: This is a playback control operation with no stack interaction.

**Implementation approach**:
```c
void actionPlay(SWFAppContext* ctx)
{
    // Set playing state to true
    ctx->is_playing = 1;

    // In NO_GRAPHICS mode, this flag will be checked by frame loop
    // In full graphics mode, this affects the frame timer
}
```

**Important Considerations**:
- Sets playback state flag
- Does NOT immediately advance frame (that happens on next frame tick)
- Opposite of ActionStop
- SetTarget can redirect which timeline is affected

Reference similar operations:
- ActionStop (opposite operation)
- Frame loop in main runtime

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] Playback state changes correctly
- [ ] No build errors or warnings
- [ ] Edge cases handled
- [ ] Documentation created
- [ ] Full test suite still passes

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
