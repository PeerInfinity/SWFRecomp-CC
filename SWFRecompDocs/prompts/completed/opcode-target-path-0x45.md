# AS2 Opcode Implementation Task: TARGET_PATH

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **TARGET_PATH**

## Opcode Specification

**Opcode Name**: TARGET_PATH
**Hex Value**: 0x45
**Category**: Utility Operations
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Returns the target path string for a MovieClip or object.

**Operation**: Pop object/movieclip reference, return its path as string, push result.

**Expected Behavior**:
- Pop value from stack (typically a MovieClip or object reference)
- Determine the target path of the object
- Push the path string onto the stack
- Path format: slash notation (e.g., "/_root/mc1/mc2") or dot notation
- Return empty string or special value if not a valid target

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test and compile to SWF (or use Python script)
6. **Setup Test Directory** - Create `SWFRecomp/tests/target_path_swf_5/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Root path
```actionscript
trace(targetPath(_root));
```
Expected output: `_root` or `/_root`

### Test Case 2: MovieClip path
```actionscript
// Assuming mc1 is a child of _root
trace(targetPath(_root.mc1));
```
Expected output: `_root.mc1` or `/_root/mc1`

### Test Case 3: Non-MovieClip value
```actionscript
trace(targetPath(42));
```
Expected output: `` (empty string) or undefined behavior

### Test Case 4: Nested MovieClip
```actionscript
// Assuming mc1 contains mc2
trace(targetPath(_root.mc1.mc2));
```
Expected output: `_root.mc1.mc2` or `/_root/mc1/mc2`

### Test Case 5: String value (edge case)
```actionscript
trace(targetPath("test"));
```
Expected output: `` (empty string)

## Implementation Hints

**Pattern**: This is a utility operation for Flash display list introspection.

**Reference these similar opcodes**:
- `actionTypeof` (0x3C) - Similar type introspection pattern
- String result handling

**Implementation outline**:
```c
void actionTargetPath(char* stack, u32* sp, char* str_buffer)
{
    // Pop value from stack
    u8 type = STACK_TOP_TYPE;
    ActionVar val;
    popVar(stack, sp, &val);

    // Check if value is a MovieClip or Object with path
    if (type == ACTION_STACK_VALUE_MOVIECLIP) {
        // For MovieClip, retrieve target path
        // This requires MovieClip infrastructure (may not be implemented yet)
        // Placeholder: return a simple path
        const char* path = "_root";  // Replace with actual path lookup
        int len = strlen(path);
        strncpy(str_buffer, path, 16);
        str_buffer[len] = '\0';
        PUSH_STR(str_buffer, len);
    } else if (type == ACTION_STACK_VALUE_OBJECT) {
        // For objects, may have a _target property
        // Placeholder: return empty or object path
        str_buffer[0] = '\0';
        PUSH_STR(str_buffer, 0);
    } else {
        // Not a valid target, return empty string
        str_buffer[0] = '\0';
        PUSH_STR(str_buffer, 0);
    }
}
```

**Note**:
- This opcode requires MovieClip infrastructure to be fully functional
- May need to store path information in MovieClip objects
- Path format can be slash notation (/_root/mc1) or dot notation (_root.mc1)
- Flash AS2 typically uses dot notation

**Important Considerations**:
- MovieClip infrastructure may not be fully implemented yet
- May need to design path storage system
- Edge cases: non-MovieClip values, null, undefined
- Path string length limitations (buffer size)

**IMPORTANT**: This opcode may require MovieClip display list infrastructure that doesn't exist yet. If MovieClip support is not implemented:
1. Implement a simplified version that returns "_root" for any MovieClip
2. Return empty string for non-MovieClip values
3. Document the limitation
4. Mark for future enhancement when MovieClip system is implemented

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/target_path_swf_5/README.md` - Test description and expected output
- Document any limitations or simplifications made
- Note dependencies on MovieClip infrastructure

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces expected output (even if simplified)
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && bash all_tests.sh`
- [ ] Non-MovieClip values handled gracefully
- [ ] Documentation created with any limitations noted

## Additional Notes

**ActionScript Function Name**: In AS2, this operation is the `targetPath()` function.

**Flash Version**: Available in SWF 5+

**Path Formats**:
- Slash notation: `/_root/mc1/mc2`
- Dot notation: `_root.mc1.mc2`

**Dependencies**: Full functionality requires:
- MovieClip object model
- Display list hierarchy
- Path tracking system

**Simplified Implementation**: If MovieClip infrastructure is incomplete, implement a basic version that:
- Returns "_root" for MOVIECLIP type
- Returns empty string for other types
- Documents the limitation for future enhancement

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter. If you encounter missing infrastructure (MovieClip system), implement a simplified version and document it clearly.
