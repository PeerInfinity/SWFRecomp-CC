# AS2 Opcode Implementation: END_DRAG

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **END_DRAG**

## Opcode Specification

**Opcode Name**: END_DRAG
**Hex Value**: 0x28
**Category**: MovieClip Interaction
**Estimated Complexity**: SIMPLE

**Description**: Stops dragging the currently dragged sprite/MovieClip.

**Operation**: Stop dragging (no parameters).

**Expected Behavior**:
- Stops dragging the currently dragged sprite
- No stack operations
- No effect if nothing is being dragged

**SWF Spec Reference**: ActionEndDrag (0x28)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test demonstrating drag stopping
6. **Setup Test Directory** - Create `SWFRecomp/tests/end_drag_swf_4/`
7. **Build and Verify** - Compile and verify behavior

## Test Cases

Test Case 1: Basic end drag
```actionscript
startDrag("mySprite", false);
trace("Dragging");
stopDrag();
trace("Stopped");
```
Expected output:
```
Dragging
Stopped
```

Test Case 2: End drag when nothing dragging
```actionscript
trace("Before stopDrag");
stopDrag();
trace("After stopDrag");
```
Expected output:
```
Before stopDrag
After stopDrag
```

## Implementation Hints

**Pattern**: This is a simple state change operation.

**Implementation approach**:
```c
void actionEndDrag(SWFAppContext* ctx)
{
    #ifndef NO_GRAPHICS
    // Full implementation would:
    // 1. Clear dragging state
    // 2. Stop updating sprite position with mouse
    if (ctx->dragged_sprite) {
        ctx->dragged_sprite = NULL;
    }
    #else
    // NO_GRAPHICS mode: just log
    #ifdef DEBUG
    printf("[EndDrag]\n");
    #endif
    #endif
}
```

**Important Considerations**:
- No stack operations
- No parameters
- Safe to call when nothing is dragging
- Clears drag state set by StartDrag

Reference similar operations:
- StartDrag (0x27) - begins dragging
- ActionStop - simple state change pattern

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output
- [ ] No build errors or warnings
- [ ] Handles case when nothing is dragging
- [ ] Documentation created
- [ ] Full test suite still passes

## Notes

- This is a simple opcode (opposite of StartDrag)
- NO_GRAPHICS mode: stub implementation
- Used to release dragged sprites
- Commonly used in drag-and-drop interfaces

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
