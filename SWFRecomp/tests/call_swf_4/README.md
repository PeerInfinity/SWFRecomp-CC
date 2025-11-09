# CALL Opcode Test (0x9E)

This test demonstrates the comprehensive ActionScript 2.0 CALL opcode implementation.

## Opcode Details

- **Opcode**: 0x9E (CALL)
- **Name**: Call
- **Category**: Control Flow (Legacy)
- **SWF Version**: 4+
- **Has Length Field**: Yes (length = 0)

## Description

The CALL opcode is a legacy feature from SWF 4 that calls frame actions (subroutines). It pops a frame identifier from the stack and executes the actions in that frame. After the frame's actions complete, execution resumes at the instruction following the CALL.

**Note**: This opcode is different from CALL_FUNCTION (0x3D) which calls ActionScript functions. CALL is for calling frame scripts, while CALL_FUNCTION is for modern function calls.

## Test Cases

### Basic Test (test.swf)

Simple single-frame test:
1. **PUSH** frame identifier "2" (as a string)
2. **CALL** - attempts to call frame 2 (does nothing since frame doesn't exist)
3. **PUSH** string "continued"
4. **TRACE** - outputs "continued" to show execution resumed

Expected output: `continued`

### Comprehensive Test (test_comprehensive.swf)

Multi-frame test covering all features:

**Frame 0**:
- Traces "Frame 0 starting"
- Calls frame 1 by number (float)
- Frame 1 executes and traces "Frame 1 executed"
- Traces "Frame 0 done"

**Frame 1**:
- Traces "Frame 1 executed"

**Frame 2**:
- Test 1: Call frame 1 with string number "1" → executes frame 1
- Test 2: Call with frame label "myLabel" → logs as not implemented
- Test 3: Call with target path "/movieclip:1" → parses and logs
- Test 4: Call with negative frame -1 → ignored
- Test 5: Call with out of range frame 99 → ignored
- Traces "All tests complete"

## Implementation Details

### Fully Implemented Features (NO_GRAPHICS mode)

✓ **Frame calling by number** (float or integer)
✓ **Frame calling by string number** (numeric strings parsed correctly)
✓ **Target path parsing** (format: "target:frame" or "/target:frame")
✓ **Frame label parsing** (distinguishes labels from numbers)
✓ **Frame execution** (for numeric frames on main timeline)
✓ **quit_swf state management** (saved/restored to prevent premature termination)
✓ **Edge case handling**:
  - Negative frames (ignored with log)
  - Out of range frames (ignored with log)
  - Null frame identifiers (ignored with log)
  - Undefined frame identifiers (ignored with log)
  - Invalid frame types (ignored with warning)
✓ **Comprehensive logging** for all scenarios

### Features Requiring Graphics Infrastructure

The following features are parsed and logged but cannot be executed in NO_GRAPHICS mode:
- **Frame label execution** (requires SWFRecomp to parse FrameLabel tag 43 and generate label→frame mapping)
- **Target path execution** (requires MovieClip tree infrastructure)
- **Multi-MovieClip support** (requires MovieClip context switching)

These are marked as "graphics-only" because they require the full MovieClip/timeline infrastructure that's only available in graphics mode.

## Frame Identifier Format

The frame identifier can be:
- Frame number: `2` or `"2"`
- Frame label: `"start"`
- With target path: `"/movieclip:2"` or `"/movieclip:start"`

## Build and Run

```bash
# Build the test
cd SWFRecomp
./scripts/build_test.sh call_swf_4 native

# Run the test
./tests/call_swf_4/build/native/call_swf_4
```

## Files

- `create_test_swf.py` - Generates the test SWF file
- `config.toml` - SWFRecomp configuration
- `test.swf` - Generated test file (56 bytes)

## Implementation Status

- [x] Enum definition in action.hpp
- [x] Translation case in action.cpp
- [x] API declaration in action.h
- [x] Runtime implementation in action.c
- [x] Test SWF creation
- [x] Test passes with expected output

## Notes

- The CALL opcode (0x9E) has the high bit set, so it includes a length field (set to 0)
- This is a legacy opcode, rarely used in modern Flash content
- Modern ActionScript uses CALL_FUNCTION (0x3D) instead
- The test demonstrates that execution continues after the call

## Related Opcodes

- **0x3D** (CALL_FUNCTION) - Calls ActionScript functions (SWF 5+)
- **0x3E** (RETURN) - Returns from a function or frame call
- **0x99** (JUMP) - Jumps to a different location in bytecode
- **0x9D** (IF) - Conditional branching
