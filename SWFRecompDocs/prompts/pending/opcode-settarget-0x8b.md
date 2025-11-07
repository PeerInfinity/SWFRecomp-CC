# AS2 Opcode Implementation Task: ActionSetTarget

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionSetTarget**

## Opcode Specification

**Opcode Name**: ActionSetTarget
**Hex Value**: 0x8B
**Category**: Movie Control
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Changes the execution context so subsequent actions apply to a named movie clip rather than the current timeline.

**Operation**: Set the target context to the specified target name (embedded in action record).

**Expected Behavior** (from SWF Spec 19):
- Changes context of subsequent actions to apply to a named object (TargetName) rather than current file
- Can be used to control Timeline of a sprite object
- Empty string ("") returns context to main timeline
- All actions following SetTarget apply to the target until changed
- Action record contains: ActionCode = 0x8B, TargetName (STRING)

**Action Record Format**:
```
Field          Type    Comment
ActionCode     UI8     0x8B
Length         UI16    Variable (length of string + 1)
TargetName     STRING  Target object name
```

**Example Usage**:
```
1. SetTarget "spinner"
2. GotoFrame 0
3. SetTarget ""  (empty string - return to main)
4. End of actions
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_SET_TARGET = 0x8B` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (parse TargetName)
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with target setting
6. **Setup Test Directory** - Create `SWFRecomp/tests/set_target_swf_3/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Set target to sprite
```actionscript
setTarget("mySprite");
trace("In mySprite context");
setTarget("");  // Return to main
trace("In main context");
```
Expected output:
```
In mySprite context
In main context
```

### Test Case 2: Control sprite timeline
```actionscript
setTarget("spinner");
gotoAndStop(1);
setTarget("");
trace("Spinner reset");
```
Expected output: `Spinner reset`

### Test Case 3: Nested targets
```actionscript
setTarget("/movieclip/sprite");
trace("Nested context");
setTarget("");
```
Expected output: `Nested context`

## Implementation Hints

**Pattern**: This is a context-switching operation similar to SetTarget2, but with target embedded in action record.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_SET_TARGET:
{
    // Read TargetName (null-terminated string)
    std::string target_name;
    char ch;
    while (in.read(&ch, 1) && ch != '\0') {
        target_name += ch;
    }

    out_script << "\t" << "// SetTarget: \"" << target_name << "\"" << endl
               << "\t" << "actionSetTarget(stack, sp, \"" << target_name << "\");" << endl;
    break;
}
```

**SWFModernRuntime API** (in action.h):
```c
void actionSetTarget(char* stack, u32* sp, const char* target_name);
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionSetTarget(char* stack, u32* sp, const char* target_name)
{
    // Empty string means return to main timeline
    if (!target_name || strlen(target_name) == 0) {
        setCurrentContext(getRootMovieClip());
        return;
    }

    // Resolve target path to movie clip
    MovieClip* target_mc = resolveTargetPath(target_name);

    if (target_mc) {
        setCurrentContext(target_mc);
    }
    // If target not found, context remains unchanged
}
```

### Helper Functions

```c
// Global variable to track current context
static MovieClip* g_current_context = NULL;

// Set the current execution context
void setCurrentContext(MovieClip* mc) {
    g_current_context = mc;
}

// Get the current execution context
MovieClip* getCurrentContext() {
    return g_current_context ? g_current_context : getRootMovieClip();
}

// Resolve a target path string to a MovieClip
MovieClip* resolveTargetPath(const char* path) {
    // Handle absolute paths starting with /
    if (path[0] == '/') {
        return getMovieClipByAbsolutePath(path);
    }

    // Handle relative paths
    MovieClip* current = getCurrentContext();
    return getMovieClipByRelativePath(current, path);
}
```

### Simplified Implementation

For initial implementation, you can simplify:

```c
void actionSetTarget(char* stack, u32* sp, const char* target_name)
{
    // Simplified: just log the target change
    if (!target_name || strlen(target_name) == 0) {
        printf("// SetTarget: (main)\n");
    } else {
        printf("// SetTarget: %s\n", target_name);
    }

    // TODO: Actually change execution context
    // This requires MovieClip infrastructure
}
```

### Similar Opcodes

Reference these opcodes:
- `actionSetTarget2` (0x20) - Stack-based version
- `actionGetProperty` (0x22) - Works with target paths
- `actionSetProperty` (0x23) - Works with target paths

### Edge Cases to Handle

- Empty string (return to main timeline)
- NULL target name
- Nonexistent sprite/movieclip
- Nested paths (slash syntax)
- Special targets (_root, _parent, etc.)
- Invalid path syntax

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/set_target_swf_3/README.md` - Test description and expected output
- Document difference from ActionSetTarget2 (0x20)
- Explain target path syntax

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Target parameter correctly parsed from action record
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Context switching works correctly
- [ ] Empty string returns to main timeline
- [ ] Invalid targets handled gracefully
- [ ] Documentation created

## Important Notes

**Difference from ActionSetTarget2 (0x20)**:
- ActionSetTarget (0x8B): Target name embedded in action record (static)
- ActionSetTarget2 (0x20): Target name from stack (dynamic, expression-based)

**Context Persistence**: The context remains set until:
- Another SetTarget/SetTarget2 action changes it
- SetTarget with empty string is called
- The current action sequence completes

**Flash Version**: Available in SWF 3+

**Target Path Syntax**:
- Simple name: `"sprite1"`
- Absolute path: `"/sprite1/sprite2"`
- Empty string: `""` (return to main)
- Special: `"_root"`, `"_parent"` (though these are more common in later SWF versions)

**Usage Pattern**:
```actionscript
setTarget("mySprite");
  // All actions here apply to mySprite
  gotoAndStop(5);
  x = 100;
  y = 200;
setTarget("");
  // Back to main timeline
```

**Target Types**:
- Movie clips (sprite instances)
- Named frames (in some contexts)
- Nested clips (using path notation)

**Testing Strategy**:
- Start with simplified implementation (log only)
- Add context tracking infrastructure
- Test with single-level targets
- Test with empty string (return to main)
- Test with nested paths
- Test with nonexistent targets

**Coordination**: This opcode relates to:
- MovieClip structure and hierarchy
- Target path resolution
- Execution context tracking
- All subsequent actions use this context
- Display list management

**Legacy Note**: SetTarget is an older opcode from SWF 3. Later versions of ActionScript prefer dot notation and with statements:
```actionscript
// Old style (SWF 3):
setTarget("sprite");
gotoAndStop(1);
setTarget("");

// New style (SWF 5+):
sprite.gotoAndStop(1);

// Or with statement:
with (sprite) {
    gotoAndStop(1);
}
```

**Action Record Parsing**: This opcode has a null-terminated string:
```cpp
// In action.cpp translation:
case SWF_ACTION_SET_TARGET:
{
    std::string target_name;
    char ch;
    while (in.read(&ch, 1) && ch != '\0') {
        target_name += ch;
    }
    // Use target_name...
}
```

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
