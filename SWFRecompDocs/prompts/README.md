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

### Batch 4: Advanced/Complex (11 opcodes, 70-120 hours total) - MOVED TO COMPLETED ✅

#### Remaining Object Operations (4 prompts)
- **opcode-enumerate-0x46.md** - ENUMERATE - Enumerate object properties (for..in, variable name)
- **opcode-enumerate2-0x55.md** - ENUMERATE2 - Enumerate properties (direct object reference)
- **opcode-delete-0x5a.md** - DELETE - Delete property by name (old version)
- **opcode-delete2-0x5b.md** - DELETE2 - Delete property (direct reference)

#### Function Operations (3 prompts)
- **opcode-call-function-0x3d.md** - CALL_FUNCTION - Call function by name with arguments
- **opcode-call-method-0x9f.md** - CALL_METHOD - Call method on object with 'this' binding
- **opcode-new-method-0x53.md** - NEW_METHOD - Create object using method as constructor

#### Advanced Control Flow (4 prompts)
- **opcode-define-function-0x9b.md** - DEFINE_FUNCTION - Define function with parameters and body
- **opcode-define-function2-0x8e.md** - DEFINE_FUNCTION2 - Enhanced function with registers
- **opcode-with-0x94.md** - WITH - Execute block with modified scope chain
- **opcode-declare-local-0x41.md** - DECLARE_LOCAL - Declare local variable in function scope

**Total Batch 4 Prompts**: 11 prompts created ✅
**Status**: ✅ COMPLETE - All 11 prompts created and moved to completed/ directory (2025-11-05)

**Complexity Note**: These are the most complex opcodes yet. Many require significant infrastructure:
- Function definition and invocation system
- Call stack management
- Local scope and variable shadowing
- Register allocation (DEFINE_FUNCTION2)
- Scope chain manipulation (WITH)

**Recommended Implementation Order**:
1. **First Wave** (foundational): ENUMERATE, ENUMERATE2, DELETE, DELETE2, DECLARE_LOCAL
2. **Second Wave** (function basics): CALL_FUNCTION, NEW_METHOD, DEFINE_FUNCTION
3. **Third Wave** (advanced): CALL_METHOD, WITH, DEFINE_FUNCTION2

### Batch 5: MovieClip, Exception Handling & Type System (14 opcodes, 56-112 hours total) - READY FOR IMPLEMENTATION ✅

#### Frame & MovieClip Control Operations (6 prompts)
- **opcode-next-frame-0x04.md** - NEXT_FRAME - Advance to next frame
- **opcode-prev-frame-0x05.md** - PREV_FRAME - Go to previous frame
- **opcode-play-0x06.md** - PLAY - Start playing timeline
- **opcode-stop-0x07.md** - STOP - Stop playing (already implemented, reference doc)
- **opcode-toggle-quality-0x08.md** - TOGGLE_QUALITY - Toggle rendering quality
- **opcode-stop-sounds-0x09.md** - STOP_SOUNDS - Stop all audio

#### Sprite Manipulation Operations (4 prompts)
- **opcode-clone-sprite-0x24.md** - CLONE_SPRITE - Duplicate a sprite/MovieClip
- **opcode-remove-sprite-0x25.md** - REMOVE_SPRITE - Remove sprite from display list
- **opcode-start-drag-0x27.md** - START_DRAG - Make sprite draggable
- **opcode-end-drag-0x28.md** - END_DRAG - Stop dragging sprite

#### Exception Handling (1 prompt)
- **opcode-throw-0x2a.md** - THROW - Throw exception (works with TRY)

#### Type System & Inheritance (3 prompts)
- **opcode-cast-op-0x2b.md** - CAST_OP - Cast object to type (returns object or null)
- **opcode-implements-op-0x2c.md** - IMPLEMENTS_OP - Declare interface implementation
- **opcode-extends-0x69.md** - EXTENDS - Set up class inheritance

**Total Batch 5 Prompts**: 14 prompts created ✅
**Status**: ✅ COMPLETE - All 14 prompts created (2025-11-05), ready for parallel implementation

**Complexity Distribution**:
- **Simple** (4 opcodes, 4-8 hours): STOP_SOUNDS, TOGGLE_QUALITY, END_DRAG, REMOVE_SPRITE
- **Medium** (4 opcodes, 8-16 hours): NEXT_FRAME, PREV_FRAME, PLAY, CLONE_SPRITE
- **Complex** (6 opcodes, 44-88 hours): START_DRAG, THROW, CAST_OP, IMPLEMENTS_OP, EXTENDS

**Implementation Notes**:
- Frame control opcodes require timeline management
- Sprite operations are stubs in NO_GRAPHICS mode
- Exception handling requires TRY opcode (0x8F) for full functionality
- Type system opcodes require prototype chain support
- Coordinate EXTENDS, CAST_OP, IMPLEMENTS_OP together (shared infrastructure)

**Recommended Implementation Order**:
1. **First Wave** (simple control): STOP_SOUNDS, TOGGLE_QUALITY, END_DRAG
2. **Second Wave** (frame control): NEXT_FRAME, PREV_FRAME, PLAY
3. **Third Wave** (sprite ops): REMOVE_SPRITE, CLONE_SPRITE
4. **Fourth Wave** (type system foundation): EXTENDS, IMPLEMENTS_OP
5. **Fifth Wave** (advanced): CAST_OP, START_DRAG, THROW

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
3. ~~**Create Batch 3 prompts**~~ ✅ DONE - All 10 prompts created and moved to completed/
4. ~~**Create Batch 4 prompts**~~ ✅ DONE - All 11 prompts created and moved to completed/
5. ~~**Create Batch 5 prompts**~~ ✅ DONE - All 14 prompts created (2025-11-05)
6. **Begin parallel implementation of Batch 5** - Assign prompts to multiple Claude Code instances
7. **Monitor and merge** - Sequential merge as implementations complete
8. **Create Batch 6 prompts** - Remaining MovieClip operations, ActionTry, etc.
9. **Continue expansion** - Iterative batches until all opcodes implemented

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

**Status**: Batch 5 complete (14 prompts), ready for parallel implementation
**Created**: 2025-11-05
**Last Updated**: 2025-11-05
**Batch 1 Completed**: 2025-11-05 (moved to completed/)
**Batch 2 Completed**: 2025-11-05 (moved to completed/)
**Batch 3 Completed**: 2025-11-05 (moved to completed/)
**Batch 4 Completed**: 2025-11-05 (moved to completed/)
**Batch 5 Completed**: 2025-11-05

**Total Prompts Created**: 61 prompts (13 + 13 + 10 + 11 + 14)
**Prompts in Active Directory**: 14 (Batch 5)
**Prompts in Completed Directory**: 47 (Batches 1-4)
