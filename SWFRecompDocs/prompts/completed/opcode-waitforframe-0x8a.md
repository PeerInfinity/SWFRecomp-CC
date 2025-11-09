# AS2 Opcode Implementation Task: ActionWaitForFrame

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionWaitForFrame**

## Opcode Specification

**Opcode Name**: ActionWaitForFrame
**Hex Value**: 0x8A
**Category**: Movie Control / Streaming
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Waits for a frame to be loaded before executing subsequent actions. Used for preloading in streaming SWF files.

**Operation**: Check if specified frame is loaded; if not, skip the next N actions.

**Expected Behavior** (from SWF Spec 19):
- Instructs Flash Player to wait until the specified frame is loaded
- If frame is not yet loaded, skips the specified number of actions
- Used to create preloaders and handle streaming content
- Action record contains: ActionCode = 0x8A, Length = 3, Frame (UI16), SkipCount (UI8)

**Action Record Format**:
```
Field          Type    Comment
ActionCode     UI8     0x8A
Length         UI16    Always 3
Frame          UI16    Frame to wait for
SkipCount      UI8     Number of actions to skip if frame not loaded
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_WAIT_FOR_FRAME = 0x8A` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (parse Frame and SkipCount)
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create ActionScript test with frame waiting
6. **Setup Test Directory** - Create `SWFRecomp/tests/wait_for_frame_swf_3/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Frame already loaded
```actionscript
// Frame 1:
ifFrameLoaded(5) {
    trace("Frame 5 loaded");
} else {
    trace("Frame 5 not loaded");
}
// Assuming frame 5 is loaded
```
Expected output: `Frame 5 loaded`

### Test Case 2: Frame not loaded (skip actions)
```actionscript
// Frame 1:
ifFrameLoaded(100) {  // Frame 100 doesn't exist
    trace("This won't print");
}
trace("Continued");
```
Expected output: `Continued`

### Test Case 3: Preloader pattern
```actionscript
// Frame 1:
ifFrameLoaded(_totalframes) {
    gotoAndPlay(2);  // All frames loaded, continue
} else {
    gotoAndPlay(1);  // Wait, loop back
}

// Frame 2:
trace("All frames loaded!");
```
Expected output (eventually): `All frames loaded!`

## Implementation Hints

**Pattern**: This is a conditional control flow operation for streaming content.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_WAIT_FOR_FRAME:
{
    // Read frame number (UI16)
    u16 frame;
    in.read((char*)&frame, sizeof(u16));

    // Read skip count (UI8)
    u8 skip_count;
    in.read((char*)&skip_count, sizeof(u8));

    out_script << "\t" << "// WaitForFrame: frame=" << frame
               << ", skip=" << (int)skip_count << endl
               << "\t" << "if (!actionWaitForFrame(stack, sp, " << frame << ")) {" << endl
               << "\t\t" << "// Skip next " << (int)skip_count << " actions" << endl
               << "\t\t" << "goto skip_label_" << label_counter << ";" << endl
               << "\t" << "}" << endl;

    // Generate code for the next skip_count actions with a skip label
    // This is complex - may need special handling in translation

    break;
}
```

**SWFModernRuntime API** (in action.h):
```c
bool actionWaitForFrame(char* stack, u32* sp, u16 frame);
```

**SWFModernRuntime Implementation** (in action.c):
```c
bool actionWaitForFrame(char* stack, u32* sp, u16 frame)
{
    // Get current movie clip
    MovieClip* mc = getCurrentMovieClip();
    if (!mc) {
        return false;
    }

    // Check if frame is loaded
    // In a streaming context, not all frames may be available yet
    bool is_loaded = isFrameLoaded(mc, frame);

    return is_loaded;
}

bool isFrameLoaded(MovieClip* mc, u16 frame)
{
    // Check if frame is within loaded range
    if (frame >= mc->totalframes) {
        return false;  // Frame doesn't exist
    }

    // Check if frame data is loaded
    // In streaming SWF, frames are loaded progressively
    // For now, assume all frames are loaded (non-streaming)
    if (frame < mc->frames_loaded) {
        return true;
    }

    return false;
}
```

### MovieClip Structure (Extended)

```c
typedef struct {
    const char* name;
    int currentframe;        // Current frame (1-based)
    int totalframes;         // Total number of frames
    int frames_loaded;       // Number of frames loaded so far
    bool playing;            // Is timeline playing?
    Frame* frames;           // Array of frames
    // ... other properties
} MovieClip;
```

### Simplified Implementation

For initial implementation, you can simplify:

```c
bool actionWaitForFrame(char* stack, u32* sp, u16 frame)
{
    // Simplified: assume all frames are loaded
    MovieClip* mc = getCurrentMovieClip();

    if (!mc || frame >= mc->totalframes) {
        return false;  // Frame doesn't exist
    }

    // For non-streaming SWF, all frames are loaded
    printf("// WaitForFrame: %d (loaded)\n", frame);
    return true;
}
```

### Action Skip Logic

The tricky part is skipping actions. In the translator:

```cpp
case SWF_ACTION_WAIT_FOR_FRAME:
{
    u16 frame;
    in.read((char*)&frame, sizeof(u16));
    u8 skip_count;
    in.read((char*)&skip_count, sizeof(u8));

    // Parse the next skip_count actions to know how much to skip
    long current_pos = in.tellg();
    long skip_target_pos = current_pos;

    for (int i = 0; i < skip_count && !in.eof(); i++) {
        u8 action_code;
        in.read((char*)&action_code, 1);

        if (action_code >= 0x80) {
            // Has length field
            u16 length;
            in.read((char*)&length, sizeof(u16));
            skip_target_pos = in.tellg() + length;
            in.seekg(skip_target_pos);
        } else {
            // No length field
            skip_target_pos = in.tellg();
        }
    }

    // Go back to current position
    in.seekg(current_pos);

    // Generate conditional jump
    out_script << "\t" << "if (!actionWaitForFrame(stack, sp, " << frame << ")) {" << endl
               << "\t\t" << "// Skip to byte offset: " << skip_target_pos << endl
               << "\t\t" << "goto skip_" << label_counter++ << ";" << endl
               << "\t" << "}" << endl;

    // Continue translating actions normally
    // Mark skip label after skip_count actions
}
```

### Similar Opcodes

Reference these opcodes:
- `actionWaitForFrame2` (0x8D) - Stack-based version
- `actionIf` (0x9D) - Conditional branching
- `actionJump` (0x99) - Unconditional jump
- `actionGotoFrame` (0x81) - Frame navigation

### Edge Cases to Handle

- Frame number out of range
- Skip count of 0 (no skip)
- Skip count larger than remaining actions
- Frame already loaded
- Frame never loads (streaming timeout)
- Nested WaitForFrame calls

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/wait_for_frame_swf_3/README.md` - Test description and expected output
- Document streaming vs non-streaming behavior
- Explain preloader patterns

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Frame and SkipCount parameters correctly parsed from action record
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Frame loaded check works correctly
- [ ] Action skipping implemented correctly
- [ ] Edge cases handled gracefully
- [ ] Documentation created

## Important Notes

**Streaming Context**: This opcode was designed for streaming SWF files over slow connections:
- SWF files load progressively (frame by frame)
- Early frames can execute while later frames are still downloading
- WaitForFrame checks if a frame is available yet

**Modern Context**: In modern usage:
- Most SWF files load instantly (fast connections)
- Can simplify by assuming all frames are loaded
- Still useful for understanding SWF structure

**Action Skipping**: The skip mechanism is complex:
- Need to calculate byte offset of actions to skip
- Or generate conditional jump in translated code
- Requires parsing action stream to know sizes

**Difference from WaitForFrame2 (0x8D)**:
- WaitForFrame (0x8A): Frame number embedded in action record
- WaitForFrame2 (0x8D): Frame number from stack

**Flash Version**: Available in SWF 3+

**ActionScript Equivalent**:
```actionscript
ifFrameLoaded(frame_number) {
    // Frame is loaded
} else {
    // Frame not loaded, skip this block
}

// Or:
if (_framesloaded >= frame_number) {
    // Frame loaded
}
```

**Preloader Pattern**:
```actionscript
// Frame 1 (Preloader):
if (_framesloaded < _totalframes) {
    // Show loading bar
    loadingBar._xscale = (_framesloaded / _totalframes) * 100;
    gotoAndPlay(1);  // Loop
} else {
    gotoAndPlay(2);  // Start movie
}
```

**Testing Strategy**:
- Start with simplified implementation (always loaded)
- Implement frame check logic
- Test with various frame numbers
- Add action skip logic
- Test preloader patterns
- Test edge cases

**Coordination**: This opcode relates to:
- Frame loading infrastructure
- Streaming SWF support
- Control flow (jump/skip logic)
- MovieClip frame management

**Translation Complexity**: This is one of the more complex opcodes to translate because:
- Need to parse ahead to calculate skip offset
- Need to generate conditional jump in output
- Need to handle action stream parsing

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
