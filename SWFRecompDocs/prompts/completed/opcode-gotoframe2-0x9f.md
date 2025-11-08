# Opcode Implementation Task: GOTO_FRAME2 (0x9F)

Please read the implementation guide at SWFRecompDocs/parallel-opcode-implementation-guide.md.

Your task is to implement support for the AS2 opcode: **GOTO_FRAME2**

## Opcode Specification

**Opcode Name**: GOTO_FRAME2
**Hex Value**: 0x9F
**Category**: Frame Control
**Estimated Complexity**: MEDIUM (2-4 hours)

**Description**: Stack-based frame navigation opcode that goes to a specific frame (by number or label) and optionally starts or stops playback.

**Operation**:
- Pop frame identifier from stack (number or string)
- If frame is a number: jump to that frame index (0-based)
- If frame is a string: jump to frame with that label
- If Play flag is set: start playing from that frame
- If Play flag is not set: go to frame and stop

**Expected Behavior** (from SWF spec):

ActionGotoFrame2 is stack-based and supports both numeric frame indices and frame labels.

1. Pops a frame off the stack:
   - If the frame is a number `n`, the next frame to be displayed is the nth frame in the current movie clip
   - If the frame is a string, it's treated as a frame label. If the label exists in the current movie clip, that frame becomes current. Otherwise, the action is ignored.

2. Either a frame number or label can be prefixed by a target path, for example: `/MovieClip:3` or `/MovieClip:FrameLabel`

3. If the Play flag is set, the action goes to the specified frame and begins playing the enclosing movie clip. Otherwise, it goes to the frame and stops.

**Opcode Data Fields**:
- Reserved: 6 bits (always 0)
- SceneBiasFlag: 1 bit (scene bias flag)
- PlayFlag: 1 bit (0 = go to frame and stop, 1 = go to frame and play)
- SceneBias: UI16 (optional, only if SceneBiasFlag = 1) - number to add to frame determined by stack argument

**Stack Behavior**:
```
Before: [..., frame_identifier]
After:  [...]
Side effect: Changes current frame position and play state
```

## Your Task

Implement this opcode following the 8-step workflow:

1. **Define Enum** - Add `SWF_ACTION_GOTO_FRAME2 = 0x9F` to `SWFRecomp/include/action/action.hpp`
2. **Add Translation** - Add case to `SWFRecomp/src/action/action.cpp`
3. **Declare API** - Add declaration to `SWFModernRuntime/include/actionmodern/action.h`
4. **Implement Runtime** - Implement in `SWFModernRuntime/src/actionmodern/action.c`
5. **Create Test SWF** - Create test with frame navigation
6. **Setup Test Directory** - Create `SWFRecomp/tests/gotoframe2_swf_5/` with validation files
7. **Build and Verify** - Use `./scripts/build_test.sh gotoframe2_swf_5 native`
8. **Run Test Suite** - Verify with `cd tests && ./all_tests.sh gotoframe2_swf_5`

## Test Cases

### Test Case 1: Numeric frame (basic)
```actionscript
// Frame 1
gotoAndStop(2);  // Uses ActionGotoFrame2 with numeric argument
```
Expected output: Jump to frame 2 and stop

### Test Case 2: Frame label
```actionscript
// Frame 1
gotoAndStop("scene2");  // Uses ActionGotoFrame2 with string label
```
Expected output: Jump to frame labeled "scene2" and stop

### Test Case 3: Go and play
```actionscript
// Frame 1
gotoAndPlay(3);  // Uses ActionGotoFrame2 with Play flag set
```
Expected output: Jump to frame 3 and start playing

### Test Case 4: Invalid label (edge case)
```actionscript
// Frame 1
gotoAndStop("nonexistent");  // Label doesn't exist
```
Expected output: Action ignored, stay on current frame

**Note**: For NO_GRAPHICS mode testing, the implementation should track the current frame number and play state. Use trace() to output the target frame for validation.

## Implementation Hints

**Pattern**: This is a frame control operation with complex parameter handling.

Reference these similar opcodes:
- `actionJump` in `SWFModernRuntime/src/actionmodern/action.c` (control flow)
- ActionGotoFrame (0x81) in pending prompts (simpler version)
- `actionIf` for conditional control flow pattern

**Key Considerations**:

1. **Opcode has variable-length data**:
   - Always has Reserved (6 bits), SceneBiasFlag (1 bit), PlayFlag (1 bit)
   - Conditionally has SceneBias (UI16) if SceneBiasFlag = 1
   - Must parse the opcode data to extract flags

2. **Frame identifier can be number OR string**:
   - Check stack top type
   - If number: convert to integer frame index
   - If string: treat as frame label (requires label lookup)

3. **Target path support**:
   - Frame can be prefixed with path like `/MovieClip:3`
   - Must parse target path if present
   - In NO_GRAPHICS mode, can simplify to current clip only

4. **Play state management**:
   - PlayFlag = 0: go to frame and stop
   - PlayFlag = 1: go to frame and continue playing
   - Must update both frame position AND play state

**Implementation Outline** (for runtime):

```c
void actionGotoFrame2(char* stack, u32* sp, u8 play_flag, u16 scene_bias)
{
    // Pop frame identifier from stack
    ActionVar frame_var;
    popVar(stack, sp, &frame_var);

    if (frame_var.type == ACTION_STACK_VALUE_F32) {
        // Numeric frame
        u32 frame_num = (u32)frame_var.value.f32;
        frame_num += scene_bias;  // Apply bias if present

        // TODO: Set current frame to frame_num
        // TODO: Set play state based on play_flag

        printf("[GotoFrame2] Jump to frame %u (play=%d)\n", frame_num, play_flag);
    }
    else if (frame_var.type == ACTION_STACK_VALUE_STRING) {
        // Frame label
        const char* label = (const char*)VAL(u64, &frame_var.value);

        // Parse target path if present (format: "path:label")
        // TODO: Look up frame by label
        // TODO: If found, jump to that frame with play_flag
        // TODO: If not found, ignore action

        printf("[GotoFrame2] Jump to label '%s' (play=%d)\n", label, play_flag);
    }
}
```

**Translation Outline** (for SWFRecomp):

```cpp
case SWF_ACTION_GOTO_FRAME2:
{
    // Parse opcode data byte
    u8 flags = *action_buffer;
    action_buffer++;

    u8 play_flag = flags & 0x01;
    u8 scene_bias_flag = (flags >> 1) & 0x01;

    u16 scene_bias = 0;
    if (scene_bias_flag) {
        scene_bias = *(u16*)action_buffer;
        action_buffer += 2;
    }

    out_script << "\t// GotoFrame2 (play=" << (int)play_flag
               << ", bias=" << scene_bias << ")" << endl
               << "\tactionGotoFrame2(stack, sp, "
               << (int)play_flag << ", " << scene_bias << ");" << endl;

    // Skip length bytes (already processed)
    action_buffer += length;
    break;
}
```

## Test Setup

**Directory**: `SWFRecomp/tests/gotoframe2_swf_5/`

**test_info.json**:
```json
{
  "metadata": {
    "name": "gotoframe2_swf_5",
    "description": "Tests GOTO_FRAME2 opcode - stack-based frame navigation",
    "swf_version": 5,
    "fully_implemented": false
  },
  "opcodes": {
    "tested": ["GOTO_FRAME2"],
    "supporting": ["PUSH", "TRACE"]
  },
  "execution": {
    "type": "deterministic"
  }
}
```

**validate.py**:
```python
#!/usr/bin/env python3
"""
Validation script for gotoframe2_swf_5

Tests the GOTO_FRAME2 opcode (stack-based frame navigation).
Expected: Frame navigation messages
"""
import sys
import json
import os

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.

    Expected: Messages showing frame navigation
    """
    lines = parse_output(output)

    results = []

    # Test 1: Numeric frame jump
    if len(lines) > 0:
        results.append(make_result(
            "numeric_frame",
            "frame 2" in lines[0].lower() or "frame: 2" in lines[0],
            "Jump to frame 2",
            lines[0] if lines else ""
        ))

    # Test 2: Play flag handling
    if len(lines) > 1:
        results.append(make_result(
            "play_flag",
            "play" in lines[1].lower() or "playing" in lines[1].lower(),
            "Play flag acknowledged",
            lines[1] if len(lines) > 1 else ""
        ))

    return make_validation_result(results)


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
```

**Note**: In NO_GRAPHICS mode, frame navigation is simulated. The implementation should track the current frame number and output it via trace or debug output for testing purposes.

## Frame Label Support

Frame labels are typically stored in the SWF file structure (in DefineLabel tags). For the initial implementation:

1. **Simple approach**: Store labels in a global hash table during SWF parsing
2. **Lookup**: `getFrameByLabel(const char* label)` returns frame number or -1
3. **NO_GRAPHICS mode**: Can use a simple test with known labels or just trace the label name

**Example label storage**:
```c
// In SWFModernRuntime
typedef struct {
    const char* label;
    u32 frame_number;
} FrameLabel;

static FrameLabel frame_labels[MAX_LABELS];
static u32 num_labels = 0;

void registerFrameLabel(const char* label, u32 frame) {
    // Store label->frame mapping
}

s32 getFrameByLabel(const char* label) {
    // Look up frame by label, return -1 if not found
}
```

## Documentation

Create or update these files as you work:
- `SWFRecomp/tests/gotoframe2_swf_5/test_info.json` - Test metadata
- `SWFRecomp/tests/gotoframe2_swf_5/validate.py` - Validation script
- Document any issues with frame label support or target paths

## Success Criteria

Your implementation is complete when:
- [ ] Enum added (or verified to exist)
- [ ] Translation case handles opcode data parsing (PlayFlag, SceneBiasFlag, SceneBias)
- [ ] Runtime function handles both numeric and string frame identifiers
- [ ] Test demonstrates frame navigation (at least numeric frames)
- [ ] Validation script passes
- [ ] No build errors or warnings
- [ ] Full test suite still passes: `cd SWFRecomp/tests && ./all_tests.sh`
- [ ] Edge cases handled (invalid labels, out-of-range frames)
- [ ] Documentation created

## Advanced Features (Optional)

These can be deferred to a later iteration:

1. **Full target path support**: Parse `/MovieClip:frame` syntax
2. **Scene bias**: Implement scene offset calculation
3. **Frame label registry**: Complete label->frame mapping system
4. **Graphics mode integration**: Actual frame rendering in full graphics mode

For the initial implementation, focus on:
- Parsing opcode data correctly
- Handling numeric frame navigation
- Supporting the Play flag
- Basic label support (even if just tracing the label name)

## Notes

- This opcode is SWF version 4+ (introduced in Flash Player 4)
- SceneBias is rarely used in practice (Flash MX+ feature for multi-scene movies)
- Most common usage is simple numeric frame navigation
- In NO_GRAPHICS mode, frame navigation is purely state tracking

Please work autonomously to complete this implementation. Test incrementally and document any issues or design decisions you encounter.
