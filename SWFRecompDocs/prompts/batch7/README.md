# Batch 7: Already-Implemented Opcodes (Documentation Prompts)

**Created**: 2025-11-06
**Updated**: 2025-11-06
**Status**: Ready for Documentation
**Total Prompts**: 28

## Overview

This batch focuses on creating comprehensive documentation and test coverage for opcodes that are **already implemented** in the codebase but lack full documentation and validation. These opcodes have working enum definitions, translation cases, and runtime functions, but need:

- Test directories with `test_info.json` and `validate.py`
- Comprehensive test cases covering edge cases
- Documentation of expected behavior
- Integration with the automated test suite

## Why Batch 7?

Most other batches focus on implementing new opcodes. Batch 7 is different:
- ✅ Implementation already exists and works
- ❌ Tests and validation are incomplete or missing
- 🎯 Goal: Document and validate existing implementations

This makes Batch 7 **ideal for**:
- Understanding how the system works by studying working code
- Learning the test framework
- Documenting edge cases and behavior
- Creating validation infrastructure

## Opcode Categories

### Basic Arithmetic (6 opcodes)
- **opcode-add-0x0a.md** - ActionAdd - Addition of two numbers
- **opcode-subtract-0x0b.md** - ActionSubtract - Subtraction
- **opcode-multiply-0x0c.md** - ActionMultiply - Multiplication
- **opcode-divide-0x0d.md** - ActionDivide - Division (handles div by zero)
- **opcode-modulo-0x3f.md** - ActionModulo - Modulo/remainder operation (has tests!)
- **opcode-increment-0x50.md** - ActionIncrement - Increment by 1 (has tests!)
- **opcode-decrement-0x51.md** - ActionDecrement - Decrement by 1 (has tests!)

### Comparison Operators (2 opcodes)
- **opcode-equals-0x0e.md** - ActionEquals - Equality with type coercion
- **opcode-less-0x0f.md** - ActionLess - Less-than comparison

### Logic Operators (3 opcodes)
- **opcode-and-0x10.md** - ActionAnd - Logical AND
- **opcode-or-0x11.md** - ActionOr - Logical OR
- **opcode-not-0x12.md** - ActionNot - Logical NOT (unary)

### String Operations (3 opcodes)
- **opcode-string-equals-0x13.md** - ActionStringEquals - String equality
- **opcode-string-length-0x14.md** - ActionStringLength - String byte length
- **opcode-string-add-0x21.md** - ActionStringAdd - String concatenation

### Variable Operations (2 opcodes)
- **opcode-get-variable-0x1c.md** - ActionGetVariable - Read variable value
- **opcode-set-variable-0x1d.md** - ActionSetVariable - Write variable value

### Object/Property Operations (2 opcodes)
- **opcode-delete-0x3a.md** - ActionDelete - Delete object property (has tests!)
- **opcode-delete2-0x3b.md** - ActionDelete2 - Delete by name (has tests!)

### Stack Operations (3 opcodes)
- **opcode-pop-0x17.md** - ActionPop - Remove top value from stack
- **opcode-push-0x96.md** - ActionPush - Push literal values (complex encoding)
- **opcode-stack-swap-0x4d.md** - ActionStackSwap - Swap top two values (has tests!)

### Control Flow (2 opcodes)
- **opcode-jump-0x99.md** - ActionJump - Unconditional jump
- **opcode-if-0x9d.md** - ActionIf - Conditional jump

### Special/Debug (2 opcodes)
- **opcode-trace-0x26.md** - ActionTrace - Debug output (already has tests!)
- **opcode-get-time-0x34.md** - ActionGetTime - Unix timestamp in milliseconds

### Function/Method Operations (1 opcode)
- **opcode-call-method-0x52.md** - ActionCallMethod - Call method with this binding

### Infrastructure (1 opcode)
- **opcode-constant-pool-0x88.md** - ActionConstantPool - String constant pool

## Complexity Distribution

- **Simple** (20 opcodes, 20-40 hours): All arithmetic (including Modulo, Increment, Decrement), comparison, logic, string ops, Pop, StackSwap, Trace, GetTime
- **Medium** (7 opcodes, 14-28 hours): GetVariable, SetVariable, StringAdd, Delete, Delete2, Push, Jump, If, ConstantPool
- **Complex** (1 opcode, 4-8 hours): CallMethod

**Total Estimated Time**: 38-76 hours (with 1 developer) or **4-8 hours** (with 10+ parallel instances)

## Implementation Status

All 28 opcodes in this batch are **fully or partially implemented**:

| Component | Status | Location |
|-----------|--------|----------|
| Enum Definition | ✅ | `SWFRecomp/include/action/action.hpp` |
| Translation Case | ✅ | `SWFRecomp/src/action/action.cpp` |
| Function Declaration | ✅ | `SWFModernRuntime/include/actionmodern/action.h` |
| Runtime Implementation | ✅ | `SWFModernRuntime/src/actionmodern/action.c` |
| Test Directory | ⚠️ | Some exist, many incomplete |
| `test_info.json` | ❌ | Missing for most |
| `validate.py` | ❌ | Missing for most |

## Your Task for Each Opcode

Since the opcodes are already implemented, your task is to:

1. **Study the existing implementation**
   - Read the enum in `action.hpp`
   - Review translation in `action.cpp`
   - Examine runtime function in `action.c`

2. **Create or enhance test directory**
   - Location: `SWFRecomp/tests/<opcode>_swf_4/`
   - May already exist - check first!

3. **Create validation files**
   - `test_info.json` - Opcode metadata
   - `validate.py` - Test validation script

4. **Test comprehensively**
   - Basic functionality
   - Edge cases (NaN, infinity, empty strings, etc.)
   - Type conversions
   - Integration with other opcodes

5. **Verify with test suite**
   - Run `./all_tests.sh` in `SWFRecomp/tests/`
   - Ensure all validations pass

## Success Criteria

For each opcode, you're done when:
- [ ] Existing implementation reviewed and understood
- [ ] Test directory exists with all required files
- [ ] `test_info.json` created with accurate metadata
- [ ] `validate.py` created with comprehensive checks
- [ ] All test cases pass (basic + edge cases)
- [ ] Test passes in `./all_tests.sh`
- [ ] Edge cases documented and tested

## Getting Started

### Example: ActionAdd (0x0A)

1. **Read the prompt**: `opcode-add-0x0a.md`
2. **Study implementation**:
   ```bash
   # View the enum
   grep -A 5 "SWF_ACTION_ADD" SWFRecomp/include/action/action.hpp

   # View the translation
   grep -A 10 "SWF_ACTION_ADD" SWFRecomp/src/action/action.cpp

   # View the runtime
   grep -A 20 "actionAdd" SWFModernRuntime/src/actionmodern/action.c
   ```

3. **Check for existing test**:
   ```bash
   ls -la SWFRecomp/tests/add*
   ```

4. **Create test if needed**:
   ```bash
   cd SWFRecomp/tests
   mkdir -p add_swf_4
   cd add_swf_4

   # Copy templates
   cp ../templates/test_info_deterministic.json test_info.json
   cp ../templates/validate.py.template validate.py
   chmod +x validate.py

   # Edit files with your test cases
   ```

5. **Build and test**:
   ```bash
   cd ../..  # Back to SWFRecomp directory
   ./scripts/build_test.sh add_swf_4 native
   ./tests/add_swf_4/build/native/add_swf_4

   # Run validation
   cd tests
   ./all_tests.sh
   ```

## Recommended Implementation Order

### Phase 1: Simplest Opcodes (Start Here!)
**Goal**: Learn the system with minimal complexity

1. **ActionTrace** (0x26) - Already has tests! Study this first
2. **ActionPop** (0x17) - Simplest stack operation
3. **ActionNot** (0x12) - Simple unary operation

**Why start here?**
- ActionTrace already works perfectly - learn from it
- Pop and Not are very simple operations
- You'll understand the test framework quickly

### Phase 2: Basic Operations
**Goal**: Core arithmetic and comparison

4. **ActionAdd** (0x0A)
5. **ActionSubtract** (0x0B)
6. **ActionMultiply** (0x0C)
7. **ActionDivide** (0x0D)
8. **ActionEquals** (0x0E)
9. **ActionLess** (0x0F)

### Phase 3: Logic Operations

10. **ActionAnd** (0x10)
11. **ActionOr** (0x11)

### Phase 4: String Operations

12. **ActionStringEquals** (0x13)
13. **ActionStringLength** (0x14)
14. **ActionStringAdd** (0x21)

### Phase 5: Variables & Stack

15. **ActionGetVariable** (0x1C)
16. **ActionSetVariable** (0x1D)
17. **ActionPush** (0x96) - Most complex!

### Phase 6: Control Flow

18. **ActionJump** (0x99)
19. **ActionIf** (0x9D)

### Phase 7: Special Operations

20. **ActionGetTime** (0x34) - Non-deterministic testing
21. **ActionConstantPool** (0x88) - Infrastructure

## Key Resources

- **Implementation Guide**: `SWFRecompDocs/parallel-opcode-implementation-guide.md`
- **Test Templates**: `SWFRecomp/tests/templates/`
- **Test Utils**: `SWFRecomp/tests/test_utils.py`
- **Working Example**: `SWFRecomp/tests/trace_swf_4/` (reference implementation)

## Testing Patterns

### Deterministic Tests
Most opcodes produce predictable output:
```python
# In validate.py
expected = "42"
actual = lines[0] if lines else ""
return make_validation_result([
    make_result("basic_test", actual == expected, expected, actual)
])
```

### Non-Deterministic Tests
For opcodes like GetTime that vary:
```python
# In validate.py
try:
    value = int(lines[0])
    # Check reasonable range
    passed = 1000000000000 < value < 2000000000000
    return make_validation_result([
        make_result("timestamp_range", passed,
                   "timestamp in valid range", str(value))
    ])
except ValueError:
    return make_validation_result([
        make_result("timestamp_range", False,
                   "valid timestamp", lines[0])
    ])
```

## Common Edge Cases to Test

### For Arithmetic Opcodes
- Division by zero → `Infinity` or `NaN`
- Very large numbers → `Infinity`
- NaN propagation
- Negative numbers
- Zero

### For Comparison Opcodes
- Equal values
- NaN comparisons (always false)
- Type coercion
- String vs number

### For String Opcodes
- Empty strings
- Long strings
- Special characters
- UTF-8/multibyte characters

### For Variable Opcodes
- Undefined variables
- Overwriting variables
- Different types

## Parallel Work Strategy

This batch is **ideal for parallel work**:
- Each opcode is independent
- No shared infrastructure needed (already implemented)
- Test directories are separate
- Low merge conflicts

**Suggested Distribution** (10 developers):
- Developer 1-4: Arithmetic & Comparison (6 opcodes)
- Developer 5-7: Logic & String (6 opcodes)
- Developer 8-9: Variables & Stack (5 opcodes)
- Developer 10: Control Flow & Special (4 opcodes)

## Questions or Issues?

- Check existing implementation in source code
- Review working test: `SWFRecomp/tests/trace_swf_4/`
- Consult implementation guide for general patterns
- Look at test templates for validation examples

## Summary

**Batch 7 Characteristics**:
- ✅ All opcodes already implemented
- 🎯 Focus: Documentation and testing
- 📚 Learning: Study working code
- 🧪 Testing: Create comprehensive validation
- 👥 Parallel-friendly: Independent opcodes
- ⏱️ Time: 3-6 hours with 10+ parallel instances

**Perfect for**:
- Learning the SWFRecomp system
- Understanding the test framework
- Contributing to code quality
- Validating existing implementations

---

**Status**: Ready for documentation work
**Created**: 2025-11-06
**Total Prompts**: 21 opcodes
**Estimated Time**: 28-56 hours sequential, 3-6 hours parallel (10+ instances)
