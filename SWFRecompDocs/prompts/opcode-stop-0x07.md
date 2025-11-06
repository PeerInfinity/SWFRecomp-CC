# AS2 Opcode Implementation: STOP (Enhanced Documentation)

**Note**: STOP (0x07) is already implemented, but this document provides complete reference for consistency.

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

## Opcode Specification

**Opcode Name**: STOP
**Hex Value**: 0x07
**Category**: MovieClip Control
**Status**: ✅ ALREADY IMPLEMENTED

**Description**: Instructs Flash Player to stop playing the file at the current frame.

**Operation**: Sets the playback state to stopped.

**Expected Behavior**:
- Stops automatic frame advancement
- Timeline remains at current frame
- Does not affect current frame position
- No stack operations

**SWF Spec Reference** (swf-spec-19.txt:4354-4367):
```
ActionStop instructs Flash Player to stop playing the file at the current frame.

Field       Type                    Comment
ActionStop  ACTIONRECORDHEADER      ActionCode = 0x07

ActionStop does the following:
1. Instructs Flash Player to stop playing the file at the current frame.
```

## Current Implementation

Already implemented in:
- ✅ `SWFRecomp/include/action/action.hpp` - SWF_ACTION_STOP = 0x07
- ✅ `SWFRecomp/src/action/action.cpp` - Translation case
- ✅ `SWFModernRuntime/include/actionmodern/action.h` - Function declaration
- ✅ `SWFModernRuntime/src/actionmodern/action.c` - Implementation

**Reference Implementation**:
```c
void actionStop(SWFAppContext* ctx)
{
    ctx->is_playing = 0;
}
```

## Usage Example

```actionscript
// Frame 1
trace("Frame 1");
play();

// Frame 2
trace("Frame 2");
stop();

// Frame 3 - will not execute automatically
trace("Frame 3");
```

## Notes

- This is the opposite of ActionPlay (0x06)
- Commonly used at the end of animations
- Can be used with gotoAndStop() for navigation
- SetTarget can redirect which timeline is affected

**Status**: No action needed - already complete
