# AS2 Opcode Implementation Task: ActionGoToLabel

Please read the implementation guide at `SWFRecompDocs/parallel-opcode-implementation-guide.md`.

Your task is to implement support for the AS2 opcode: **ActionGoToLabel**

## Opcode Specification

**Opcode Name**: ActionGoToLabel
**Hex Value**: 0x8C
**Category**: Movie Control
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Instructs Flash Player to go to the frame associated with the specified label.

**Operation**: Jump to a frame identified by its label (embedded in action record).

**Expected Behavior** (from SWF Spec 19):
- Goes to the frame associated with the specified label
- Frame labels are attached to frames with the FrameLabel tag
- If label is not found, the action is ignored
- Does not start playing automatically (stops at the frame)
- Action record contains: ActionCode = 0x8C, Label (STRING)

**Action Record Format**:
```
Field          Type    Comment
ActionCode     UI8     0x8C
Length         UI16    Variable (length of string + 1)
Label          STRING  Frame label
```

## Your Task

Implement this opcode following the 7-step workflow:

1. **Define Enum** - Add `SWF_ACTION_GOTO_LABEL = 0x8C` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp` (parse Label)
3. **Declare API** - Add function to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create multi-frame SWF with labeled frames
6. **Setup Test Directory** - Create `SWFRecomp/tests/goto_label_swf_3/`
7. **Build and Verify** - Compile and verify output matches expected

## Test Cases

### Test Case 1: Go to labeled frame
```actionscript
// Frame 1:
trace("Frame 1");
gotoAndStop("scene2");

// Frame 2 (label: "scene2"):
trace("Scene 2");
```
Expected output:
```
Frame 1
Scene 2
```

### Test Case 2: Go to start label
```actionscript
// Frame 1 (label: "start"):
trace("Start");

// Frame 5:
gotoAndStop("start");  // Go back to start
```
Expected output:
```
Start
Start
```

### Test Case 3: Invalid label (ignored)
```actionscript
// Frame 1:
gotoAndStop("nonexistent");
trace("Continued");
```
Expected output: `Continued`

### Test Case 4: Multiple labels
```actionscript
// Frame 1 (label: "intro"):
trace("Intro");
gotoAndStop("menu");

// Frame 2 (label: "menu"):
trace("Menu");
gotoAndStop("game");

// Frame 3 (label: "game"):
trace("Game");
```
Expected output:
```
Intro
Menu
Game
```

## Implementation Hints

**Pattern**: This is a control flow operation that requires frame label lookup.

### Implementation Outline

**SWFRecomp Translation** (in action.cpp):
```cpp
case SWF_ACTION_GOTO_LABEL:
{
    // Read Label (null-terminated string)
    std::string label;
    char ch;
    while (in.read(&ch, 1) && ch != '\0') {
        label += ch;
    }

    out_script << "\t" << "// GoToLabel: \"" << label << "\"" << endl
               << "\t" << "actionGoToLabel(stack, sp, \"" << label << "\");" << endl;
    break;
}
```

**SWFModernRuntime API** (in action.h):
```c
void actionGoToLabel(char* stack, u32* sp, const char* label);
```

**SWFModernRuntime Implementation** (in action.c):
```c
void actionGoToLabel(char* stack, u32* sp, const char* label)
{
    // Get current movie clip context
    MovieClip* mc = getCurrentMovieClip();
    if (!mc) {
        return;
    }

    // Find frame with matching label
    int frame_index = findFrameByLabel(mc, label);

    if (frame_index >= 0) {
        // Set current frame (convert 0-based to 1-based)
        mc->currentframe = frame_index + 1;

        // Stop playback
        mc->playing = false;

        // Execute frame actions (if any)
        if (mc->frames[frame_index].action_func) {
            mc->frames[frame_index].action_func(stack, sp);
        }
    }
    // If label not found, do nothing
}

int findFrameByLabel(MovieClip* mc, const char* label)
{
    if (!mc || !label) {
        return -1;
    }

    // Search through frames for matching label
    for (int i = 0; i < mc->totalframes; i++) {
        if (mc->frames[i].label &&
            strcmp(mc->frames[i].label, label) == 0) {
            return i;  // Return 0-based index
        }
    }

    return -1;  // Label not found
}
```

### Frame Structure (Extended)

```c
typedef void (*ActionFunc)(char* stack, u32* sp);

typedef struct {
    int number;              // Frame number (1-based)
    const char* label;       // Frame label (optional, can be NULL)
    ActionFunc action_func;  // Generated function for frame actions
} Frame;

typedef struct {
    const char* name;
    int currentframe;        // Current frame (1-based)
    int totalframes;         // Total number of frames
    bool playing;            // Is timeline playing?
    Frame* frames;           // Array of frames
    // ... other properties
} MovieClip;
```

### Simplified Implementation

For initial implementation, you can simplify:

```c
void actionGoToLabel(char* stack, u32* sp, const char* label)
{
    // Simplified: just log the label
    printf("// GoToLabel: %s\n", label ? label : "(null)");

    // TODO: Implement actual frame label lookup
    // This requires:
    // - MovieClip structure with labeled frames
    // - Frame label mapping
    // - Timeline navigation
}
```

### Similar Opcodes

Reference these opcodes:
- `actionGotoFrame` (0x81) - Go to frame by number
- `actionGotoFrame2` (0x9F) - Stack-based version with labels
- `actionPlay` (0x06) - Start playing
- `actionStop` (0x07) - Stop playing

### Edge Cases to Handle

- Empty label string
- NULL label
- Label not found (ignore action)
- Multiple frames with same label (use first match)
- Case sensitivity of labels
- Current frame has the target label

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/goto_label_swf_3/README.md` - Test description and expected output
- Document frame label system
- Explain difference from GotoFrame

## Success Criteria

Your implementation is complete when:
- [ ] All 7 steps completed
- [ ] Label parameter correctly parsed from action record
- [ ] Test produces correct output for all test cases
- [ ] No build errors or warnings
- [ ] Frame label lookup works correctly
- [ ] Invalid labels handled gracefully (ignored)
- [ ] Playback stops at target frame
- [ ] Frame actions executed on arrival
- [ ] Documentation created

## Important Notes

**Frame Labels**: Frame labels are defined in the SWF file using FrameLabel tags:
- FrameLabel tag specifies a name for a frame
- Labels enable semantic navigation (e.g., "intro", "menu", "game")
- More maintainable than frame numbers

**Difference from GotoFrame (0x81)**:
- GotoFrame (0x81): Uses numeric frame index
- GoToLabel (0x8C): Uses frame label string
- Both stop at target frame (don't play)

**Difference from GotoFrame2 (0x9F)**:
- GoToLabel (0x8C): Label embedded in action record
- GotoFrame2 (0x9F): Frame/label from stack, supports play flag

**Flash Version**: Available in SWF 3+

**ActionScript Equivalents**:
```actionscript
gotoAndStop("label");     // This opcode
gotoAndPlay("label");     // Use GotoFrame2 with play flag
```

**Label Lookup**: Frame labels must be stored during SWF parsing:
- FrameLabel tags define labels
- Store in Frame structure during parsing
- Lookup by string comparison at runtime

**Case Sensitivity**: Frame labels are case-sensitive:
- "Start" != "start"
- Exact match required

**Testing Strategy**:
- Start with simplified implementation (log only)
- Add frame label storage during parsing
- Implement label lookup
- Add frame navigation
- Test with various labels
- Test edge cases (not found, etc.)

**Coordination**: This opcode relates to:
- FrameLabel tag parsing
- Frame structure with label field
- Timeline navigation
- MovieClip management
- Frame action execution

**FrameLabel Tag**: In SWF parsing:
```cpp
// When parsing FrameLabel tag:
case TAG_FRAME_LABEL:
{
    std::string label = readString();  // Read label from tag
    current_frame->label = strdup(label.c_str());
    break;
}
```

**Action Record Parsing**: This opcode has a null-terminated string:
```cpp
// In action.cpp translation:
case SWF_ACTION_GOTO_LABEL:
{
    std::string label;
    char ch;
    while (in.read(&ch, 1) && ch != '\0') {
        label += ch;
    }
    // Use label...
}
```

**Anchor Labels**: In SWF 6+, there's a special kind of frame label called "anchor":
- Enables deep linking (URL fragments)
- Normal labels work for navigation
- Anchor labels also work with browser back/forward

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
