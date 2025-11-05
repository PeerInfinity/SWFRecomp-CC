# Parallel Opcode Implementation Plan: Validation Experiments

This document outlines experiments to verify the viability of the parallel opcode implementation plan described in `parallel-opcode-implementation-guide.md`.

## Experiment Goals

Before committing to large-scale parallel opcode implementation, these experiments validate:
- The build pipeline works correctly
- Time estimates are accurate
- Parallel development is truly conflict-free
- Foundational infrastructure (especially object model) is sound
- The workflow is clear enough for autonomous work

## Experiments

### 1. "Hello World" Smoke Test ⭐ CRITICAL

**Goal**: Verify the basic build pipeline works end-to-end

**Steps**:
1. Build SWFRecomp from scratch
2. Use an existing test (like `trace_swf_4`)
3. Verify it produces correct output
4. Time how long the build takes

**Success Criteria**:
- ✅ SWFRecomp builds without errors
- ✅ Test runs and produces expected output
- ✅ Build time is reasonable (< 5 minutes)

**Why**: Confirms basic infrastructure works before anyone starts implementing

**Estimated Time**: 15-30 minutes

---

### 2. Minimal New Opcode Test ⭐ CRITICAL

**Goal**: Implement the simplest possible new opcode to validate workflow

**Suggested Opcode**: `Modulo (0x3F)` - simple arithmetic operation

**Steps**:
1. Follow all 7 steps from the implementation guide
2. Measure actual time from start to finish
3. Document any steps that were unclear or problematic
4. Note where you got stuck or confused

**Success Criteria**:
- ✅ Opcode implemented following all 7 steps
- ✅ Test produces correct output
- ✅ Actual time matches estimate (1-2 hours for simple opcode)
- ✅ Documentation was sufficient for autonomous work

**Why**: Validates the workflow time estimates and identifies documentation gaps

**Estimated Time**: 1-3 hours (intentionally measuring this)

---

### 3. Stack Corruption Detection Test

**Goal**: Verify whether stack bugs are easy to debug

**Steps**:
1. Create a deliberately broken opcode implementation with stack issues:
   - Test A: Missing POP before PUSH
   - Test B: Mismatched type/value pairs
   - Test C: Incorrect sp manipulation
2. Try to build and run each broken version
3. Observe error messages and debugging difficulty

**Success Criteria**:
- ✅ Errors are detectable (not silent corruption)
- ✅ Error messages point to the problem area
- ✅ Can identify and fix bugs in < 30 minutes each

**Why**: Stack corruption is listed as a "common mistake" - verifies it's debuggable

**Estimated Time**: 1-2 hours

---

### 4. Reference Counting Proof of Concept ⭐ CRITICAL

**Goal**: Build minimal object infrastructure before object opcodes are implemented

**Steps**:
1. Define `ASObject` structure in SWFModernRuntime
2. Implement `allocObject()`, `retainObject()`, `releaseObject()`
3. Create a simple test that:
   - Allocates an object (refcount = 1)
   - Retains it twice (refcount = 3)
   - Releases it three times (refcount = 0, freed)
4. Add debug assertions to verify refcounts
5. Test with valgrind/AddressSanitizer for leaks

**Success Criteria**:
- ✅ Objects allocate with refcount = 1
- ✅ Retain increments refcount correctly
- ✅ Release decrements and frees at 0
- ✅ No memory leaks detected
- ✅ No crashes or double-frees

**Why**: The object model is complex and shared by many opcodes (~30% according to the guide). Validating it early prevents downstream problems.

**Estimated Time**: 2-4 hours

---

### 5. Parallel Work Merge Test ⭐ CRITICAL

**Goal**: Verify parallel development minimizes conflicts as claimed

**Steps**:
1. Create 2 branches from main
2. Branch A: Implement Modulo (0x3F)
3. Branch B: Implement Increment (0x40 - if available)
4. Try to merge both into main
5. Document all conflicts
6. Analyze whether conflicts could be avoided with better process

**Success Criteria**:
- ✅ Enum additions don't conflict (append-only)
- ✅ Switch statement conflicts are minimal or auto-resolvable
- ✅ Runtime function implementations don't conflict
- ✅ Tests in separate directories don't conflict
- ✅ Total merge conflict resolution time < 15 minutes

**Why**: The guide claims "minimizing conflicts" - this validates the claim empirically

**Estimated Time**: 2-3 hours (including implementing 2 opcodes)

---

### 6. Edge Case Coverage Test

**Goal**: Verify existing opcodes handle edge cases properly

**Steps**:
1. Test existing arithmetic opcodes:
   - Division by zero (should produce Infinity or NaN)
   - Very large numbers (overflow behavior)
   - Negative numbers
2. Test string operations:
   - Empty strings
   - Very long strings
   - Null/undefined strings
3. Test type conversions:
   - String to number conversions
   - Number to string conversions
   - Boolean context conversions

**Success Criteria**:
- ✅ Edge cases match Flash/ActionScript behavior
- ✅ No crashes on edge cases
- ✅ Behavior is documented

**Why**: If existing opcodes don't handle edge cases well, new implementations won't either. Sets baseline quality expectations.

**Estimated Time**: 2-3 hours

---

### 7. Test Template Validation

**Goal**: Verify the test directory setup process works smoothly

**Steps**:
1. Follow Step 6 (Setup Test Directory) exactly
2. Copy from `trace_swf_4` to a new test directory
3. Try to build without any modifications
4. Try building both native and WASM versions
5. Document any missing files or broken references

**Success Criteria**:
- ✅ All required files copy successfully
- ✅ Makefile works without modifications
- ✅ config.toml is clear and easy to edit
- ✅ Native build succeeds
- ✅ WASM build succeeds (if applicable)

**Why**: The guide relies heavily on copying templates. Ensures the template approach is foolproof.

**Estimated Time**: 30 minutes - 1 hour

---

### 8. Complex Opcode Estimate Test

**Goal**: Validate complexity time estimates for medium-difficulty opcodes

**Suggested Opcode**: String operation (e.g., `StringExtract`, `CharToAscii`, `AsciiToChar`)

**Steps**:
1. Implement one "medium complexity" opcode
2. Track time spent on each of the 7 steps
3. Compare actual time to estimate (2-4 hours)
4. Note which steps took longer than expected

**Success Criteria**:
- ✅ Opcode implemented correctly
- ✅ Actual time is within 50% of estimate
- ✅ Existing patterns covered most scenarios
- ✅ Identified any missing patterns/documentation

**Why**: Validates complexity estimates aren't overly optimistic

**Estimated Time**: 2-5 hours (intentionally measuring this)

---

### 9. Generated Code Inspection

**Goal**: Verify the generated C code is maintainable and efficient

**Steps**:
1. Run SWFRecomp on a simple test SWF
2. Examine the generated C code:
   - Is it readable and well-formatted?
   - Are variable names clear?
   - How large is it compared to original SWF?
   - Are there redundant operations?
3. Look for obvious optimization opportunities
4. Check if debugging would be feasible

**Success Criteria**:
- ✅ Generated code is human-readable
- ✅ Code size is reasonable (< 10x bytecode size)
- ✅ No obviously broken patterns
- ✅ Could debug if necessary

**Why**: Ensures the compile-time approach produces maintainable/performant output

**Estimated Time**: 30 minutes - 1 hour

---

### 10. Documentation Completeness Test

**Goal**: Test if the guide enables truly autonomous development

**Steps**:
1. Give the guide to someone unfamiliar with the codebase
   - Or simulate this by implementing without referring to existing code
2. Have them implement a simple opcode (e.g., Increment)
3. Track questions asked and blockers encountered
4. Document missing information or unclear steps

**Success Criteria**:
- ✅ Can complete implementation with only guide as reference
- ✅ Fewer than 3 clarifying questions needed
- ✅ No critical information missing
- ✅ Steps are in correct order

**Why**: The guide is designed for "autonomous" work. Tests if it truly enables independent development.

**Estimated Time**: 2-3 hours (for the implementer)

---

## Priority Ranking

### Must-Run Before Parallel Implementation (Top 3)

1. **Experiment #4 - Reference Counting PoC**
   - Foundation for ~30% of opcodes
   - Shared infrastructure must be solid
   - Complexity: HIGH
   - Impact: CRITICAL

2. **Experiment #2 - Minimal New Opcode**
   - Validates the core workflow
   - Tests time estimates
   - Complexity: LOW
   - Impact: CRITICAL

3. **Experiment #5 - Parallel Merge Test**
   - Critical for the "parallel" aspect
   - Validates conflict minimization claims
   - Complexity: MEDIUM
   - Impact: CRITICAL

### Should-Run for Confidence (Next 4)

4. **Experiment #1 - Hello World Smoke Test**
   - Quick sanity check
   - Catches environment issues early

5. **Experiment #7 - Test Template Validation**
   - Templates are core to workflow
   - Quick to validate

6. **Experiment #8 - Complex Opcode Estimate**
   - Validates time estimates for harder work
   - Tests pattern completeness

7. **Experiment #6 - Edge Case Coverage**
   - Sets quality baseline
   - Prevents regression

### Nice-to-Have (Remaining)

8. **Experiment #3 - Stack Corruption Detection**
   - Debugging experience validation

9. **Experiment #9 - Generated Code Inspection**
   - Code quality validation

10. **Experiment #10 - Documentation Completeness**
    - Best done with fresh eyes (different person)

---

## Experiment Results Template

For each experiment, document:

```markdown
## Experiment #X: [Name]

**Date**: YYYY-MM-DD
**Duration**: [actual time]
**Status**: ✅ PASS / ⚠️ PARTIAL / ❌ FAIL

### What Worked
- [bullet points]

### What Failed
- [bullet points]

### Unexpected Issues
- [bullet points]

### Recommendations
- [changes to workflow]
- [documentation updates needed]
- [infrastructure improvements]

### Conclusion
[Should we proceed? What needs to change?]
```

---

## Go/No-Go Decision Criteria

After completing experiments #1, #2, #4, and #5, evaluate:

### GREEN LIGHT (Proceed with Parallel Implementation)
- ✅ All critical experiments pass
- ✅ Time estimates accurate within 50%
- ✅ Merge conflicts minimal (< 15 min resolution)
- ✅ Object model works correctly
- ✅ Build pipeline reliable

### YELLOW LIGHT (Proceed with Modifications)
- ⚠️ Most experiments pass but some issues found
- ⚠️ Time estimates need adjustment
- ⚠️ Merge strategy needs refinement
- ⚠️ Documentation needs updates

### RED LIGHT (Rework Needed)
- ❌ Critical experiments fail
- ❌ Time estimates off by > 100%
- ❌ Merge conflicts unmanageable
- ❌ Object model fundamentally flawed
- ❌ Build pipeline unreliable

---

## Next Steps After Validation

If experiments pass:

1. **Finalize Object Model** (if needed for experiment #4)
2. **Update Documentation** based on experiment findings
3. **Create Opcode Assignment Sheet** for parallel teams
4. **Set Up Coordination Process** for enum/declaration phase
5. **Begin Parallel Implementation** with clear team assignments

If experiments reveal issues:

1. **Document Problems** in detail
2. **Propose Solutions** to architectural issues
3. **Update Implementation Guide** with lessons learned
4. **Re-run Failed Experiments** after fixes
5. **Re-evaluate Timeline** based on actual data

---

## Conclusion

These experiments validate the parallel opcode implementation plan before committing significant resources. The critical path is:

1. Smoke test (#1) - 15 min
2. Minimal opcode (#2) - 2 hours
3. Object model (#4) - 3 hours
4. Parallel merge (#5) - 3 hours

**Total critical validation time: ~8-10 hours**

This upfront investment prevents wasting dozens of hours on a flawed approach and gives confidence that parallel development will succeed.
