# CALL Opcode Test (0x9E)

This test demonstrates the ActionScript 2.0 CALL opcode implementation.

## Opcode Details

- **Opcode**: 0x9E (CALL)
- **Name**: Call
- **Category**: Control Flow (Legacy)
- **SWF Version**: 4+
- **Has Length Field**: Yes (length = 0)

## Description

The CALL opcode is a legacy feature from SWF 4 that calls frame actions (subroutines). It pops a frame identifier from the stack and executes the actions in that frame. After the frame's actions complete, execution resumes at the instruction following the CALL.

**Note**: This opcode is different from CALL_FUNCTION (0x3D) which calls ActionScript functions. CALL is for calling frame scripts, while CALL_FUNCTION is for modern function calls.

## Test Case

The test performs the following operations:

1. **PUSH** frame identifier "2" (as a string)
2. **CALL** - calls frame 2 (simplified: logs the call instead of executing)
3. **PUSH** string "continued"
4. **TRACE** - outputs "continued" to show execution resumed

### Expected Output

```
// Call frame 2
continued
```

### Actual Output

```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
// Call frame 2
continued
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

## Implementation Details

### Simplified Implementation

The current implementation is simplified:
- Pops the frame identifier from the stack
- Parses it as a frame number or label
- Logs the call to stdout
- Does NOT actually execute frame actions

### Full Implementation (Future)

A complete implementation would require:
- MovieClip structure with frame information
- Frame label mapping
- Frame action execution infrastructure
- Target path parsing (e.g., "/movieclip:2")
- Call stack management
- Recursion detection

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
