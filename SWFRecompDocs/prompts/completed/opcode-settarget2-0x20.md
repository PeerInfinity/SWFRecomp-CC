# AS2 Opcode Implementation Task: ActionSetTarget2

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionSetTarget2**

## Opcode Specification

**Opcode Name**: ActionSetTarget2
**Hex Value**: 0x20
**Category**: Movie Control
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Sets the current execution context to a named movie clip or sprite, stack-based version.

**Operation**: Pop target path from stack, set it as the current context for subsequent actions.

**Expected Behavior** (from SWF Spec 19):
- Pops the target path off the stack
- Makes the target the current active context
- All subsequent actions apply to this context until changed
- This is the stack-based version of ActionSetTarget (0x8B)
- Enables the target path to be the result of expression evaluation
- Empty string returns context to the main timeline

**Stack Operations**:
```
Before: [... target_path]
After:  [... ]
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_SET_TARGET2 = 0x20` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with target setting
6. **Setup Test Directory** - Create `SWFRecomp/tests/set_target2_swf_4/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Set target to sprite
```actionscript
// Assume sprite "mySprite" exists
setTarget("mySprite");
trace("Context changed to mySprite");
setTarget("");  // Return to main timeline
```
Expected output: `Context changed to mySprite`

### Test Case 2: Set target from expression
```actionscript
var spriteName = "sprite1";
setTarget(spriteName);  // Target from variable
trace("Dynamic target set");
setTarget("");
```
Expected output: `Dynamic target set`

### Test Case 3: Nested target path
```actionscript
setTarget("/movieclip/sprite");
trace("Nested target");
setTarget("");
```
Expected output: `Nested target`

### Test Case 4: Empty string (return to root)
```actionscript
setTarget("mySprite");
setTarget("");  // Return to main timeline
trace("Back to main");
```
Expected output: `Back to main`

## Implementation Hints

**Pattern**: This is a context-switching operation that affects the execution environment.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_SET_TARGET2:
{
    out_script << "\t" << "// SetTarget2" << endl
               << "\t" << "actionSetTarget2(stack, sp);" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionSetTarget2(char* stack, u32* sp)
{
    // 1. Pop target path from stack
    ActionVar target_var;
    convertString(stack, sp);  // Convert to string if needed
    popVar(stack, sp, &target_var);

    const char* target_path = NULL;
    if (target_var.type == ACTION_STACK_VALUE_STRING) {
        target_path = (const char*) target_var.value.u64;
    }

    // 2. Set the current execution context
    // Empty string means return to main timeline
    if (target_path == NULL || strlen(target_path) == 0) {
        setCurrentContext(getRootMovieClip());
    } else {
        // Resolve target path to movie clip
        MovieClip* target_mc = resolveTargetPath(target_path);
        if (target_mc) {
            setCurrentContext(target_mc);
        }
        // If target not found, context remains unchanged
    }
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
void actionSetTarget2(char* stack, u32* sp)
{
    // Pop target path
    ActionVar target_var;
    convertString(stack, sp);
    popVar(stack, sp, &target_var);

    const char* target_path = "";
    if (target_var.type == ACTION_STACK_VALUE_STRING) {
        target_path = (const char*) target_var.value.u64;
    }

    // For simplified implementation: just log the target change
    printf("// SetTarget2: %s\n",
           (target_path && strlen(target_path) > 0) ? target_path : "(main)");

    // TODO: Actually change execution context
    // This requires MovieClip infrastructure
}
```

### Similar Opcodes

Reference these opcodes:
- `actionSetTarget` (0x8B) - String-based version (not stack-based)
- `actionGetProperty` (0x22) - Also works with target paths
- `actionSetProperty` (0x23) - Also works with target paths

### Edge Cases to Handle

- Empty string (return to main timeline)
- NULL or invalid target path
- Nonexistent sprite/movieclip
- Nested paths (slash vs dot syntax)
- Special targets (_root, _parent, etc.)
- Circular references

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/set_target2_swf_4/README.md` - Test description and expected output
- Document difference from ActionSetTarget (0x8B)

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Context switching works correctly
- [ ] Empty string returns to main timeline
- [ ] Invalid targets handled gracefully
- [ ] Documentation created

## Important Notes

**Difference from ActionSetTarget (0x8B)**:
- ActionSetTarget (0x8B): Target path embedded in the action record as STRING
- ActionSetTarget2 (0x20): Target path popped from stack (enables dynamic targets)

**Context Persistence**: The context remains set until:
- Another SetTarget/SetTarget2 action changes it
- SetTarget with empty string is called
- The current action sequence completes

**Flash Version**: Available in SWF 4+

**Target Path Syntax**:
- Absolute paths: `/sprite1/sprite2`
- Relative paths: `sprite1` or `../sprite2`
- Dot syntax: `sprite1.sprite2` (SWF 5+)
- Special targets: `_root`, `_parent`, `this`

**Testing Strategy**:
- Start with simplified implementation (log only)
- Add context tracking infrastructure
- Test with single-level targets
- Test with nested paths
- Test with special targets

**Coordination**: This opcode relates to:
- MovieClip structure and hierarchy
- Target path resolution
- Execution context tracking
- All subsequent actions use this context

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
