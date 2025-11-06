# AS2 Opcode Implementation: REMOVE_SPRITE

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **REMOVE_SPRITE**

## Opcode Specification

**Opcode Name**: REMOVE_SPRITE
**Hex Value**: 0x25
**Category**: MovieClip Control
**Estimated Complexity**: MEDIUM

**Description**: Removes a sprite/MovieClip from the display list.

**Operation**: Pop target sprite name from stack, remove sprite.

**Expected Behavior**:
- Pop target name (string) - name of sprite to remove
- Removes sprite from display list
- Frees sprite resources
- No effect if sprite doesn't exist

**SWF Spec Reference**: ActionRemoveSprite (0x25)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test demonstrating sprite removal
6. **Setup Test Directory** - Create `SWFRecomp/tests/remove_sprite_swf_4/`
7. **Build and Verify** - Compile and verify behavior

## Test Cases

Test Case 1: Basic remove
```actionscript
removeMovieClip("mySprite");
trace("Sprite removed");
```
Expected output:
```
Sprite removed
```

Test Case 2: Remove non-existent sprite
```actionscript
trace("Before remove");
removeMovieClip("nonExistent");
trace("After remove");
```
Expected output:
```
Before remove
After remove
```

## Implementation Hints

**Pattern**: This is a MovieClip manipulation operation.

**Implementation approach**:
```c
void actionRemoveSprite(char* stack, u32* sp)
{
    // Pop target sprite name
    ActionVar target;
    popVar(stack, sp, &target);
    const char* target_name = (const char*) target.value.u64;

    #ifndef NO_GRAPHICS
    // Full implementation would:
    // 1. Find MovieClip in display list
    // 2. Remove from display list
    // 3. Release resources (with reference counting)
    removeMovieClip(target_name);
    #else
    // NO_GRAPHICS mode: just log the operation
    #ifdef DEBUG
    printf("[RemoveSprite] %s\n", target_name);
    #endif
    #endif
}
```

**Important Considerations**:
- NO_GRAPHICS mode: simplified (no actual removal)
- Full mode: requires display list management
- Must handle non-existent sprites gracefully
- Reference counting: release sprite object

Reference similar operations:
- CloneSprite (0x24) - opposite of removal
- Object cleanup patterns

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output
- [ ] Parameters are correctly popped
- [ ] No build errors or warnings
- [ ] Handles non-existent sprites gracefully
- [ ] Documentation created
- [ ] Full test suite still passes

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
