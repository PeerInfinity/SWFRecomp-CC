# TARGET_PATH Opcode Test (0x45)

## Description

This test verifies the implementation of the AS2 `TARGET_PATH` opcode (0x45), which returns the target path string for a MovieClip or object.

## Opcode Details

- **Opcode**: 0x45
- **Name**: TARGET_PATH
- **Category**: Utility Operations
- **SWF Version**: 5+

## Test Cases

### Test Case 1: Non-MovieClip Value
```actionscript
targetPath(42)
```

**Expected Output**: Empty string `""`

Since the value `42` is not a MovieClip or Object, the opcode should return an empty string.

## Implementation Notes

This is a **simplified implementation** because full MovieClip infrastructure is not yet available in the runtime. The current implementation:

1. Checks if the value is of type `ACTION_STACK_VALUE_OBJECT`
2. Returns `"_root"` for Object types (as a placeholder)
3. Returns empty string `""` for all other types

## Future Enhancements

When MovieClip infrastructure is fully implemented:
- Store actual path information in MovieClip objects
- Support nested MovieClip hierarchy (e.g., `_root.mc1.mc2`)
- Support both slash notation (`/_root/mc1`) and dot notation (`_root.mc1`)
- Properly handle the `_root` reference

## Expected Test Output

```
[Frame 0]

Test: targetPath(42)
[Tag] ShowFrame()
```

The first trace should output an empty string (nothing), and the second trace outputs the test label.

## Build and Run

```bash
cd SWFRecomp
./scripts/build_test.sh target_path_swf_5 native
./tests/target_path_swf_5/build/native/target_path_swf_5
```

## References

- Implementation guide: `SWFRecompDocs/parallel-opcode-implementation-guide.md`
- Opcode specification: `SWFRecompDocs/prompts/opcode-target-path-0x45.md`
