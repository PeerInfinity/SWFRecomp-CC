# Opcode Implementation Prompts

This directory contains prompt documents for implementing AS2 opcodes in parallel using Claude Code instances.

## Overview

Each prompt file provides complete instructions for implementing a specific opcode, following the validated 7-step workflow from the parallel opcode implementation guide.

## Directory Structure

```
prompts/
├── README.md (this file)
├── opcode-{name}-0x{hex}.md (individual opcode prompts)
└── [more prompts to be added]
```

## Current Prompts

### Batch 2: Medium Opcodes (2-4 hours each) - READY ✅

#### String Operations (7 prompts)
- **opcode-char-to-ascii-0x31.md** - CHAR_TO_ASCII - Convert first character to ASCII code
- **opcode-ascii-to-char-0x32.md** - ASCII_TO_CHAR - Convert ASCII code to character
- **opcode-mb-char-to-ascii-0x33.md** - MB_CHAR_TO_ASCII - Multibyte character to Unicode code point
- **opcode-mb-ascii-to-char-0x36.md** - MB_ASCII_TO_CHAR - Unicode code point to UTF-8 character
- **opcode-mb-string-length-0x35.md** - MB_STRING_LENGTH - Character count (not byte count)
- **opcode-string-extract-0x15.md** - STRING_EXTRACT - Extract substring
- **opcode-string-less-0x29.md** - STRING_LESS - Lexicographic string comparison

#### Stack Operations (3 prompts)
- **opcode-duplicate-0x3d.md** - DUPLICATE - Duplicate top stack value
- **opcode-stack-swap-0x4c.md** - STACK_SWAP - Swap top two stack values
- **opcode-random-number-0x30.md** - RANDOM_NUMBER - Generate random integer in range

#### Utility Operations (3 prompts)
- **opcode-typeof-0x3c.md** - TYPEOF - Return type of value as string
- **opcode-target-path-0x45.md** - TARGET_PATH - Get MovieClip target path
- **opcode-add2-0x47.md** - ADD2 - Type-aware addition (ECMA-262)

**Total Batch 2 Prompts**: 13 prompts created ✅

## How to Use These Prompts

### For Parallel Development (Recommended)

1. **Review categorization**: Check `SWFRecompDocs/opcode-categorization.md` for all available opcodes
2. **Select opcode batch**: Choose a batch of opcodes to implement in parallel
3. **Assign prompts**: Give each Claude Code instance a different prompt file
4. **Monitor progress**: Each instance works autonomously following the 7-step workflow
5. **Merge results**: Use the validated merge strategy (Experiment #5: 2 min per merge)

### For Single Developer

1. **Pick a prompt**: Choose an opcode matching your desired complexity
2. **Open the prompt**: Read through the entire prompt before starting
3. **Follow the steps**: Complete all 7 steps in order
4. **Test incrementally**: Build and test after each major step
5. **Document issues**: Note any problems or design decisions

### For Creating New Prompts

Use the template at `SWFRecompDocs/opcode-instance-prompt-template.md`:

1. Look up opcode in `SWFRecompDocs/specs/swf-spec-19.txt`
2. Fill in template variables (name, hex, category, complexity)
3. Create 3-5 test cases (basic, edge cases)
4. Reference similar implemented opcodes
5. Add category-specific hints
6. Save as `opcode-{name}-0x{hex}.md`

## Prompt Structure

Each prompt contains:

1. **Specification** - Opcode details, hex value, complexity estimate
2. **Operation** - Stack operations and expected behavior
3. **Task Steps** - Complete 7-step workflow with file paths
4. **Test Cases** - 3-5 test cases with expected output
5. **Implementation Hints** - Code patterns and similar opcodes
6. **Success Criteria** - Checklist for completion

## Batch Organization

Prompts are organized by implementation priority:

### Batch 1: Simple (13 opcodes, 15-25 hours total) - MOVED TO COMPLETED ✅
- **Comparison**: GREATER (0x67), STRING_GREATER (0x68), STRICT_EQUALS (0x66), LESS2 (0x48)
- **Bitwise**: BIT_AND (0x60), BIT_OR (0x61), BIT_XOR (0x62), BIT_LSHIFT (0x63), BIT_RSHIFT (0x64), BIT_URSHIFT (0x65)
- **Type Conversion**: TO_INTEGER (0x18), TO_NUMBER (0x4A), TO_STRING (0x4B)

**Status**: ✅ COMPLETE - All 13 prompts created and moved to completed/ directory (2025-11-05)

### Batch 2: Medium (13 opcodes, 28-52 hours total) - READY FOR IMPLEMENTATION ✅

#### String Operations (7 prompts)
- **opcode-char-to-ascii-0x31.md** - CHAR_TO_ASCII - Convert first character to ASCII code
- **opcode-ascii-to-char-0x32.md** - ASCII_TO_CHAR - Convert ASCII code to character
- **opcode-mb-char-to-ascii-0x33.md** - MB_CHAR_TO_ASCII - Multibyte character to Unicode code point
- **opcode-mb-ascii-to-char-0x36.md** - MB_ASCII_TO_CHAR - Unicode code point to UTF-8 character
- **opcode-mb-string-length-0x35.md** - MB_STRING_LENGTH - Character count (not byte count)
- **opcode-string-extract-0x15.md** - STRING_EXTRACT - Extract substring
- **opcode-string-less-0x29.md** - STRING_LESS - Lexicographic string comparison

#### Stack Operations (3 prompts)
- **opcode-duplicate-0x3d.md** - DUPLICATE - Duplicate top stack value
- **opcode-stack-swap-0x4c.md** - STACK_SWAP - Swap top two stack values
- **opcode-random-number-0x30.md** - RANDOM_NUMBER - Generate random integer in range

#### Utility Operations (3 prompts)
- **opcode-typeof-0x3c.md** - TYPEOF - Return type of value as string
- **opcode-target-path-0x45.md** - TARGET_PATH - Get MovieClip target path
- **opcode-add2-0x47.md** - ADD2 - Type-aware addition (ECMA-262)

**Total Batch 2 Prompts**: 13 prompts created ✅
**Status**: ✅ COMPLETE - All 13 prompts created (2025-11-05), ready for parallel implementation

### Batch 3: Complex (10 opcodes, 30-60 hours total) - READY FOR IMPLEMENTATION ✅

#### Object Operations (6 prompts)
- **opcode-init-array-0x42.md** - INIT_ARRAY - Create new array with elements
- **opcode-init-object-0x43.md** - INIT_OBJECT - Create new object with properties
- **opcode-get-member-0x4e.md** - GET_MEMBER - Get object/array property or element
- **opcode-set-member-0x4f.md** - SET_MEMBER - Set object/array property or element
- **opcode-get-property-0x22.md** - GET_PROPERTY - Get MovieClip property by index
- **opcode-set-property-0x23.md** - SET_PROPERTY - Set MovieClip property by index

#### Function & Control Flow Operations (4 prompts)
- **opcode-new-object-0x40.md** - NEW_OBJECT - Create object via constructor
- **opcode-return-0x3e.md** - RETURN - Return value from function
- **opcode-call-0x9e.md** - CALL - Call frame actions
- **opcode-store-register-0x87.md** - STORE_REGISTER - Store value in register

**Total Batch 3 Prompts**: 10 prompts created ✅
**Status**: ✅ COMPLETE - All 10 prompts created (2025-11-05), ready for parallel implementation

### Batch 4: Advanced (20+ opcodes, 80-160+ hours total)
- **Remaining Object Operations**: ENUMERATE (0x55), DELETE (0x5A), etc.
- **Function Operations**: CALL_FUNCTION (0x3D), CALL_METHOD (0x9F), DEFINE_FUNCTION (0x9B), etc.
- **Advanced Control Flow**: WITH (0x94), TRY (0x8F), THROW (0x2A), etc.
- **Frame & MovieClip Operations**: NEXT_FRAME, PLAY, STOP_SOUNDS, etc.

**Status**: To be created (after Batch 3)

## Validation Status

**Infrastructure Validated**:
- ✅ Build pipeline (Experiment #1: 45 min)
- ✅ 7-step workflow (Experiment #2: 45 min for simple opcode)
- ✅ Object model (Experiment #4: 0 memory leaks)
- ✅ Parallel merge strategy (Experiment #5: 2 min for 4 conflicts)

**Ready for parallel implementation**: YES

## Time Estimates

Based on validated experiments:

| Complexity | Time Estimate | Example Opcodes |
|------------|---------------|-----------------|
| Simple | 1-2 hours | GREATER, BIT_AND, TO_INTEGER |
| Medium | 2-4 hours | STRING_EXTRACT, DUPLICATE, TYPEOF |
| Complex | 4-8 hours | INIT_OBJECT, CALL_FUNCTION, ENUMERATE |

**Note**: These are individual opcode estimates. With 10 parallel agents, 10 simple opcodes can be completed in 1-2 hours of wall-clock time (plus ~20 min for sequential merging).

## Success Metrics

Each implemented opcode should:
- ✅ Pass all test cases
- ✅ Build without errors/warnings
- ✅ Handle edge cases correctly
- ✅ Follow existing code patterns
- ✅ Include complete documentation
- ✅ Pass full test suite

## Next Steps

1. ~~**Complete Batch 1 prompts**~~ ✅ DONE - All 13 prompts created and moved to completed/
2. ~~**Create Batch 2 prompts**~~ ✅ DONE - All 13 prompts created and moved to completed/
3. ~~**Create Batch 3 prompts**~~ ✅ DONE - All 10 prompts created (2025-11-05)
4. **Begin parallel implementation of Batch 3** - Assign prompts to multiple Claude Code instances
5. **Monitor and merge** - Sequential merge as implementations complete
6. **Create Batch 4 prompts** - Advanced opcodes, function definitions, exception handling
7. **Continue expansion** - Iterative batches until all opcodes implemented

## Resources

- **Implementation Guide**: `SWFRecompDocs/parallel-opcode-implementation-guide.md`
- **Categorization**: `SWFRecompDocs/opcode-categorization.md`
- **Template**: `SWFRecompDocs/opcode-instance-prompt-template.md`
- **Experiments**: `SWFRecompDocs/parallel-opcode-experiments.md`
- **SWF Spec**: `SWFRecompDocs/specs/swf-spec-19.txt`

## Questions or Issues?

- Check the implementation guide first
- Review experiment results for validation data
- Examine existing implemented opcodes for patterns
- Document any blockers or unexpected issues

---

**Status**: Batch 3 complete (10 prompts), ready for parallel implementation
**Created**: 2025-11-05
**Last Updated**: 2025-11-05
**Batch 1 Completed**: 2025-11-05 (moved to completed/)
**Batch 2 Completed**: 2025-11-05 (moved to completed/)
**Batch 3 Completed**: 2025-11-05
