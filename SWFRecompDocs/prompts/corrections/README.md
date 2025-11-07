# Opcode Prompt Corrections

This directory contains corrected versions of opcode prompts that had errors in their original versions.

## Purpose

During the creation of 74+ opcode implementation prompts, some errors were discovered after prompts were moved to the `completed/` directory. Rather than modifying the original prompts (which may have already been used for implementation), corrected versions are placed here for reference.

## Corrections

### opcode-mb-char-to-ascii-0x36-CORRECTED.md

**Original Prompt**: `completed/opcode-mb-ascii-to-char-0x36.md`

**Issue**: The original prompt had the operation backwards. It described converting numeric code points to characters, which is actually the behavior of opcode 0x37, not 0x36.

**Correct Behavior**:
- **0x36 = ActionMBCharToAscii**: Converts string character → numeric code point
  - Pop string from stack
  - Extract first character
  - Decode UTF-8 to get code point
  - Push code point as number

**Incorrect Behavior** (in original prompt):
- Described: numeric code point → string character (this is 0x37)

**Impact**:
- If 0x36 was implemented using the incorrect prompt, it may have been implemented with the wrong behavior
- The implementation might actually be correct for 0x37 instead

**Resolution Options**:
1. If 0x36 is not yet implemented: Use the corrected prompt
2. If 0x36 was implemented with wrong behavior and 0x37 is not implemented: Consider moving the implementation to 0x37 and re-implementing 0x36 correctly
3. If both are implemented: Verify each opcode does the correct operation and swap if needed

## Verification

To verify if the issue affects existing implementations:

```bash
# Check if 0x36 implementation exists
grep -r "SWF_ACTION_MB.*0x36" SWFRecomp/include/action/action.hpp
grep -r "actionMb.*ToAscii\|actionMb.*ToChar" SWFModernRuntime/src/actionmodern/action.c

# Check test directories
ls -la SWFRecomp/tests/ | grep -i "mb.*ascii\|mb.*char"
```

Look for:
- Which enum value maps to which hex code
- Which function implements which behavior
- Whether tests validate char→code or code→char conversion

## Related Opcodes

For reference, here are the related multibyte character opcodes:

| Hex  | Name | Correct Behavior |
|------|------|------------------|
| 0x31 | ActionCharToAscii | Single-byte char → code (ASCII only) |
| 0x32 | ActionAsciiToChar | Single-byte code → char (ASCII only) |
| 0x33 | ActionMBCharToAscii | First multibyte char → code (should be 0x33, but spec shows 0x36) |
| 0x35 | ActionMBStringLength | Multibyte string length (character count) |
| 0x36 | ActionMBCharToAscii | **String → code point** (CORRECTED) |
| 0x37 | ActionMBAsciiToChar | Code point → string |

**Note**: There appears to be some inconsistency in the SWF spec numbering for the MB opcodes. The corrections here follow the authoritative opcode values from the SWF spec's action code tables.

## How to Use Corrected Prompts

1. **Before Implementation**: Use the corrected prompt instead of the original
2. **After Implementation**: Compare implementation against corrected prompt to verify correctness
3. **If Issue Found**: Follow resolution options above

## Future Corrections

If additional prompt errors are discovered, add them to this directory with:
- Filename: `opcode-{name}-0x{hex}-CORRECTED.md`
- Clear explanation of the error
- Corrected specification
- Impact assessment
- Resolution guidance

---

**Created**: 2025-11-06
**Corrections**: 1 (opcode 0x36)
