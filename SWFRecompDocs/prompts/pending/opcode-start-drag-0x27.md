# AS2 Opcode Implementation: START_DRAG

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **START_DRAG**

## Opcode Specification

**Opcode Name**: START_DRAG
**Hex Value**: 0x27
**Category**: MovieClip Interaction
**Estimated Complexity**: COMPLEX

**Description**: Makes a sprite/MovieClip draggable with the mouse cursor.

**Operation**: Pop target and constraint parameters from stack, enable dragging.

**Expected Behavior**:
- Pop target (string) - sprite to make draggable
- Pop lock center flag (boolean) - lock to mouse center or drag from click point
- Pop constrain flag (boolean) - whether to constrain to rectangle
- If constrain: pop y2, x2, y1, x1 (constraint rectangle)
- Makes sprite follow mouse cursor
- Only one sprite can be dragged at a time

**SWF Spec Reference**: ActionStartDrag (0x27)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test demonstrating drag setup
6. **Setup Test Directory** - Create `SWFRecomp/tests/start_drag_swf_4/`
7. **Build and Verify** - Compile and verify behavior

## Test Cases

Test Case 1: Basic drag (no constraints)
```actionscript
startDrag("mySprite", false);
trace("Drag started");
```
Expected output:
```
Drag started
```

Test Case 2: Drag with lock center
```actionscript
trace("Before drag");
startDrag("mySprite", true);
trace("After drag");
```
Expected output:
```
Before drag
After drag
```

Test Case 3: Drag with constraints
```actionscript
// Constrain to rectangle (0,0) to (100,100)
startDrag("mySprite", false, 0, 0, 100, 100);
trace("Constrained drag started");
```
Expected output:
```
Constrained drag started
```

## Implementation Hints

**Pattern**: This is a mouse interaction operation with complex parameters.

**Implementation approach**:
```c
void actionStartDrag(char* stack, u32* sp)
{
    // Pop target sprite name
    ActionVar target;
    popVar(stack, sp, &target);
    const char* target_name = (const char*) target.value.u64;

    // Pop lock center flag
    ActionVar lock_center;
    popVar(stack, sp, &lock_center);

    // Pop constrain flag
    ActionVar constrain;
    popVar(stack, sp, &constrain);

    float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    if ((int)constrain.value.f32 != 0) {
        // Pop constraint rectangle
        ActionVar y2_var, x2_var, y1_var, x1_var;
        popVar(stack, sp, &y2_var);
        popVar(stack, sp, &x2_var);
        popVar(stack, sp, &y1_var);
        popVar(stack, sp, &x1_var);

        x1 = x1_var.value.f32;
        y1 = y1_var.value.f32;
        x2 = x2_var.value.f32;
        y2 = y2_var.value.f32;
    }

    #ifndef NO_GRAPHICS
    // Full implementation would:
    // 1. Find target MovieClip
    // 2. Set dragging state
    // 3. Store drag parameters
    // 4. Update position each frame based on mouse
    startDragMovieClip(target_name, (int)lock_center.value.f32,
                       (int)constrain.value.f32, x1, y1, x2, y2);
    #else
    // NO_GRAPHICS mode: just log
    #ifdef DEBUG
    printf("[StartDrag] %s (lock:%d, constrain:%d)\n",
           target_name, (int)lock_center.value.f32, (int)constrain.value.f32);
    if ((int)constrain.value.f32) {
        printf("  Bounds: (%.1f,%.1f)-(%.1f,%.1f)\n", x1, y1, x2, y2);
    }
    #endif
    #endif
}
```

**Important Considerations**:
- Complex parameter handling (variable number of pops)
- Constrain flag determines if bounds are on stack
- Lock center vs drag from click point
- Only one sprite can be dragged at a time
- Requires mouse position tracking

Reference similar operations:
- EndDrag (0x28) - stops dragging
- Mouse interaction infrastructure

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output
- [ ] All parameters correctly popped (with/without constraints)
- [ ] No build errors or warnings
- [ ] Handles both constrained and unconstrained modes
- [ ] Documentation created
- [ ] Full test suite still passes

## Notes

- NO_GRAPHICS mode: stub with parameter validation
- Full mode: requires mouse tracking and sprite position updates
- Used extensively in Flash games and interactive content
- Pair with EndDrag (0x28) to stop dragging

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
