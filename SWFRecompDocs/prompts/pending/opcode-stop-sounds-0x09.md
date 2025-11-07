# AS2 Opcode Implementation: STOP_SOUNDS

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **STOP_SOUNDS**

## Opcode Specification

**Opcode Name**: STOP_SOUNDS
**Hex Value**: 0x09
**Category**: Audio Control
**Estimated Complexity**: SIMPLE

**Description**: Instructs Flash Player to stop playing all sounds.

**Operation**: Stops all currently playing audio.

**Expected Behavior**:
- Stops all sounds currently playing
- Does not affect future sounds
- No stack operations
- Global effect (all timelines)

**SWF Spec Reference** (swf-spec-19.txt:4379-4392):
```
ActionStopSounds instructs Flash Player to stop playing all sounds.

Field            Type                    Comment
ActionStopSounds ACTIONRECORDHEADER      ActionCode = 0x09

ActionStopSounds does the following:
1. Instructs Flash Player to stop playing all sounds.
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test that demonstrates sound stopping
6. **Setup Test Directory** - Create `SWFRecomp/tests/stop_sounds_swf_4/`
7. **Build and Verify** - Compile and verify behavior

## Test Cases

**Note**: In NO_GRAPHICS mode, sound operations are no-ops. Tests verify the opcode executes without error.

Test Case 1: Basic stop sounds
```actionscript
trace("Before stopAllSounds");
stopAllSounds();
trace("After stopAllSounds");
```
Expected output:
```
Before stopAllSounds
After stopAllSounds
```

Test Case 2: Stop sounds with other operations
```actionscript
trace("Start");
play();
stopAllSounds();
trace("Sounds stopped");
stop();
```
Expected output:
```
Start
Sounds stopped
```

## Implementation Hints

**Pattern**: This is a simple control operation with no stack interaction.

**Implementation approach**:
```c
void actionStopSounds(SWFAppContext* ctx)
{
    // In NO_GRAPHICS mode, this is a no-op
    #ifndef NO_GRAPHICS
    // In full graphics mode, stop all audio channels
    if (ctx->audio_context) {
        stopAllAudioChannels(ctx->audio_context);
    }
    #endif

    // For testing, just log the operation
    #ifdef DEBUG
    printf("[ActionStopSounds] Stopped all sounds\n");
    #endif
}
```

**Important Considerations**:
- NO_GRAPHICS mode: no-op (no audio system)
- Full graphics mode: would interface with audio subsystem
- Global effect (not affected by SetTarget)
- Does not prevent new sounds from playing

Reference similar operations:
- ActionStop, ActionPlay (control flow operations)
- Frame control infrastructure

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output
- [ ] Builds in NO_GRAPHICS mode without errors
- [ ] No build errors or warnings
- [ ] Documentation created
- [ ] Full test suite still passes

## Notes

- This opcode has no effect in NO_GRAPHICS mode (testing only)
- In full implementation, would interface with audio subsystem
- Simple implementation: just stub for now
- Global effect (all sounds, all timelines)

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
