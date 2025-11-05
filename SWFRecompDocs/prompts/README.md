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

### Batch 1: Simple Opcodes (1-2 hours each)

#### Comparison Operations
- **opcode-greater-0x48.md** - GREATER comparison operator

#### Bitwise Operations
- **opcode-bit-and-0x60.md** - Bitwise AND operation

#### Type Conversion
- **opcode-to-integer-0x18.md** - Convert value to 32-bit integer

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

### Batch 1: Simple (13 opcodes, 15-25 hours total)
- **Comparison**: GREATER, GREATER_EQUALS, LESS_EQUALS, STRICT_EQUALS
- **Bitwise**: BIT_AND, BIT_OR, BIT_XOR, BIT_LSHIFT, BIT_RSHIFT, BIT_URSHIFT
- **Type Conversion**: TO_INTEGER, TO_NUMBER, TO_STRING

**Status**: 3 prompts created (samples), 10 more to create

### Batch 2: Medium (14 opcodes, 30-55 hours total)
- **String Operations**: 7 opcodes
- **Stack Operations**: 3 opcodes
- **Utility**: 3 opcodes

**Status**: To be created

### Batch 3: Complex (25+ opcodes, 100-200 hours total)
- **Object Operations**: 10 opcodes (requires object model)
- **Function Operations**: 6 opcodes
- **Control Flow**: 5 opcodes
- **Advanced**: 25+ opcodes

**Status**: To be created (after Batch 1 and 2)

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

1. **Complete Batch 1 prompts** - Create remaining 10 prompts for simple opcodes
2. **Begin parallel implementation** - Assign prompts to multiple Claude Code instances
3. **Monitor and merge** - Sequential merge as implementations complete
4. **Create Batch 2 prompts** - After Batch 1 success
5. **Continue expansion** - Iterative batches until all opcodes implemented

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

**Status**: Ready for parallel opcode implementation
**Created**: 2025-11-05
**Last Updated**: 2025-11-05
