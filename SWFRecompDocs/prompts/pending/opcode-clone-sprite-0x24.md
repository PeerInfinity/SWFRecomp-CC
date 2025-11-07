# AS2 Opcode Implementation: CLONE_SPRITE

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **CLONE_SPRITE**

## Opcode Specification

**Opcode Name**: CLONE_SPRITE
**Hex Value**: 0x24
**Category**: MovieClip Control
**Estimated Complexity**: COMPLEX

**Description**: Clones a sprite/MovieClip to create a duplicate instance.

**Operation**: Pop target, source, and depth from stack, create clone.

**Expected Behavior**:
- Pop target name (string) - name for the clone
- Pop source (string) - path to sprite to clone
- Pop depth (number) - z-order depth for clone
- Creates a duplicate of the source sprite
- Places clone at specified depth with new name

**SWF Spec Reference**: ActionCloneSprite (0x24)

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test demonstrating sprite cloning
6. **Setup Test Directory** - Create `SWFRecomp/tests/clone_sprite_swf_4/`
7. **Build and Verify** - Compile and verify behavior

## Test Cases

**Note**: In NO_GRAPHICS mode, sprite operations are simplified. Focus on correct parameter handling.

Test Case 1: Basic clone
```actionscript
duplicateMovieClip("originalSprite", "clonedSprite", 1);
trace("Sprite cloned");
```
Expected output:
```
Sprite cloned
```

Test Case 2: Clone with depth
```actionscript
trace("Before clone");
duplicateMovieClip("sprite1", "sprite2", 10);
trace("After clone");
```
Expected output:
```
Before clone
After clone
```

## Implementation Hints

**Pattern**: This is a MovieClip manipulation operation.

**Implementation approach**:
```c
void actionCloneSprite(char* stack, u32* sp)
{
    // Pop depth
    convertFloat(stack, sp);
    ActionVar depth;
    popVar(stack, sp, &depth);

    // Pop source sprite name
    ActionVar source;
    popVar(stack, sp, &source);
    const char* source_name = (const char*) source.value.u64;

    // Pop target sprite name
    ActionVar target;
    popVar(stack, sp, &target);
    const char* target_name = (const char*) target.value.u64;

    #ifndef NO_GRAPHICS
    // Full implementation would:
    // 1. Find source MovieClip in display list
    // 2. Create deep copy of sprite and its children
    // 3. Add to display list at specified depth
    // 4. Assign new name
    cloneMovieClip(source_name, target_name, (int)depth.value.f32);
    #else
    // NO_GRAPHICS mode: just log the operation
    #ifdef DEBUG
    printf("[CloneSprite] %s -> %s (depth %d)\n",
           source_name, target_name, (int)depth.value.f32);
    #endif
    #endif
}
```

**Important Considerations**:
- NO_GRAPHICS mode: simplified (no actual cloning)
- Full mode: requires display list management
- Must duplicate sprite state (properties, children)
- Depth determines z-order
- Target name must be unique

Reference similar operations:
- RemoveSprite (0x25) - opposite operation
- NewObject (0x40) - object creation pattern

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output
- [ ] Parameters are correctly popped
- [ ] No build errors or warnings
- [ ] Documentation created
- [ ] Full test suite still passes

## Notes

- This opcode requires display list management in full implementation
- NO_GRAPHICS mode: stub with parameter validation
- Used for dynamic sprite creation in Flash games
- Clones include all child sprites and properties

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
