# AS2 Opcode Failing Test Fix Guide

This guide explains how to debug and fix failing tests for ActionScript 2 (AS2) opcodes in the SWFRecomp project using Claude Code.

## Overview

This workflow is specifically for **fixing tests that are currently failing**. If you're implementing a new opcode from scratch, use the `parallel-opcode-implementation-guide.md` instead.

**Status**: ✅ Build pipeline validated (Experiment #1: Hello World Smoke Test - 2025-11-05)
- Build time: ~2 seconds per test
- Uses NO_GRAPHICS mode (console-only, no SDL3/Vulkan dependencies)
- Automated build script: `./scripts/build_test.sh <test_name> native`

## Quick Start: Understanding the Test Failure

Before fixing anything, you need to understand what's failing:

```bash
# 1. Navigate to the specific test directory
cd SWFRecomp/tests/<test_name>

# 2. Build and run the test manually to see what's happening
../../scripts/build_test.sh <test_name> native
./build/native/<test_name>

# 3. Compare actual output with expected output
# Check the validate.py file to see what's expected
cat validate.py

# 4. Run through validation to see detailed failure info
./build/native/<test_name> 2>&1 | \
  grep -v "SWF Runtime" | grep -v "===" | grep -v "\[Frame" | grep -v "\[Tag\]" | grep -v "^$" | \
  ./validate.py
```

## Project Structure

### The Three Repositories

**SWFRecomp** (C++ Recompiler)
- Translates SWF bytecode to C code at compile-time
- Location: `/SWFRecomp/`
- Key files:
  - `include/action/action.hpp` - Opcode enums
  - `src/action/action.cpp` - Translation logic

**SWFModernRuntime** (C Runtime Library)
- Executes the generated C code with GPU acceleration
- Location: `/SWFModernRuntime/`
- Key files:
  - `include/actionmodern/action.h` - API declarations
  - `src/actionmodern/action.c` - Opcode implementations

**SWFRecompDocs** (Documentation)
- Specifications and implementation guides
- Location: `/SWFRecompDocs/`
- Key files:
  - `specs/swf-spec-19.txt` - SWF specification with opcode values
  - `reference/trace-swf4-wasm-generation.md` - Architecture guide

### Repository Organization

All three repositories are combined into a single workspace:
- `SWFRecomp/` - Recompiler code
- `SWFModernRuntime/` - Runtime code
- `SWFRecompDocs/` - Documentation

## Common Failure Categories

### Category 1: Wrong Output

**Symptom**: Test runs successfully but produces incorrect output.

**Example**:
```json
{
  "passed": false,
  "sub_tests": [
    {
      "name": "basic_operation",
      "passed": false,
      "expected": "8",
      "actual": "12"
    }
  ]
}
```

**Debug Steps**:

1. **Check the expected behavior** from the specification:
   ```bash
   # Look up the opcode in the SWF spec
   grep -A 20 "0xXX" SWFRecompDocs/specs/swf-spec-19.txt
   ```

2. **Examine the generated C code** to see what SWFRecomp produced:
   ```bash
   cat tests/<test_name>/RecompiledScripts/script_0.c
   ```

3. **Check the runtime implementation** in SWFModernRuntime:
   ```bash
   # Find the implementation
   grep -A 30 "void action<OpcodeName>" SWFModernRuntime/src/actionmodern/action.c
   ```

4. **Verify the test SWF is correct**:
   - Check if there's a `create_test_swf.py` script
   - Manually verify the ActionScript logic
   - Ensure the test SWF matches the documented behavior

5. **Add debug output** to narrow down the issue:
   ```c
   // Temporary debugging in action.c
   void actionYourOpcode(char* stack, u32* sp)
   {
       printf("DEBUG: Stack top value before: %d\n", STACK_TOP_VALUE);
       // ... your implementation ...
       printf("DEBUG: Result after operation: %d\n", result);
   }
   ```

6. **Rebuild and test**:
   ```bash
   ../../scripts/build_test.sh <test_name> native
   ./build/native/<test_name>
   ```

**Common Causes**:
- Incorrect operator precedence
- Wrong stack pop order (remember: for `a OP b`, push b first, then a)
- Type conversion issues (float vs int)
- Off-by-one errors in string operations
- Incorrect handling of edge cases (division by zero, null values, etc.)

### Category 2: Crash or Segmentation Fault

**Symptom**: Test crashes during execution.

**Debug Steps**:

1. **Run with GDB** for detailed crash info:
   ```bash
   cd tests/<test_name>
   gdb ./build/native/<test_name>
   (gdb) run
   (gdb) bt  # Get backtrace when it crashes
   ```

2. **Check stack pointer corruption**:
   - Every POP must have a matching PUSH
   - Ensure stack balance is maintained
   - Verify `sp` is not null or invalid

3. **Check string/pointer validity**:
   ```c
   // Common issue: using freed or invalid pointer
   const char* str = (const char*) VAL(u64, &STACK_TOP_VALUE);
   if (str == NULL) {
       // Handle null case!
   }
   ```

4. **Verify buffer sizes**:
   - String buffers must be large enough
   - Array bounds must be checked
   - Stack has 8MB limit but can still overflow

**Common Causes**:
- Dereferencing null pointers
- Stack underflow (too many POPs)
- Buffer overflow in string operations
- Using freed memory
- Incorrect macro usage (VAL, PUSH, POP)

### Category 3: Build Failure

**Symptom**: Test fails to compile.

**Debug Steps**:

1. **Check for missing declarations**:
   ```bash
   # Verify function is declared
   grep "actionYourOpcode" SWFModernRuntime/include/actionmodern/action.h
   ```

2. **Check for implementation**:
   ```bash
   # Verify function is implemented
   grep "void actionYourOpcode" SWFModernRuntime/src/actionmodern/action.c
   ```

3. **Verify enum exists**:
   ```bash
   grep "SWF_ACTION_YOUR_OPCODE" SWFRecomp/include/action/action.hpp
   ```

4. **Check translation case**:
   ```bash
   grep "SWF_ACTION_YOUR_OPCODE" SWFRecomp/src/action/action.cpp
   ```

**Common Causes**:
- Missing function declaration in header
- Missing function implementation
- Typo in function name
- Missing enum value
- Missing translation case

### Category 4: Validation Script Issues

**Symptom**: Test produces correct output but validation fails.

**Debug Steps**:

1. **Run test manually and check raw output**:
   ```bash
   ./build/native/<test_name> 2>&1
   ```

2. **Check what validate.py receives** (after filtering):
   ```bash
   ./build/native/<test_name> 2>&1 | \
     grep -v "SWF Runtime" | grep -v "===" | grep -v "\[Frame" | grep -v "\[Tag\]" | grep -v "^$"
   ```

3. **Add debug output to validate.py**:
   ```python
   def validate_output(output):
       lines = parse_output(output)
       print(f"DEBUG: Received {len(lines)} lines", file=sys.stderr)
       for i, line in enumerate(lines):
           print(f"DEBUG: Line {i}: '{line}'", file=sys.stderr)
       # ... validation logic ...
   ```

4. **Check for whitespace issues**:
   - Extra spaces or tabs
   - Different line endings
   - Trailing newlines

**Common Causes**:
- Expected value doesn't match actual formatting
- Float precision differences (use approximate comparison)
- Incorrect line parsing
- Wrong test expectations

## The Debug-Fix-Test Workflow

### Step 1: Reproduce the Failure

Always start by confirming the failure locally:

```bash
cd SWFRecomp/tests/<test_name>
../../scripts/build_test.sh <test_name> native
./build/native/<test_name> 2>&1 | \
  grep -v "SWF Runtime" | grep -v "===" | grep -v "\[Frame" | grep -v "\[Tag\]" | grep -v "^$" | \
  ./validate.py
```

**Document**:
- Exact error message
- Expected vs actual output
- Any crash information

### Step 2: Identify the Root Cause

Use the failure category above to narrow down the issue:

1. **Is it a runtime implementation bug?**
   - Wrong calculation
   - Incorrect stack operations
   - Bad type conversion

2. **Is it a translation bug?**
   - SWFRecomp generating wrong C code
   - Missing or incorrect parameters

3. **Is it a test issue?**
   - Wrong expected output
   - Incorrect test SWF
   - Bad validation logic

4. **Is it a specification misunderstanding?**
   - Opcode behavior not as documented
   - Edge case handling unclear

### Step 3: Examine the Generated Code

**Always check what SWFRecomp generated**:

```bash
# Look at the generated script
cat tests/<test_name>/RecompiledScripts/script_0.c

# Expected structure:
# - Variable declarations
# - Stack operations (PUSH, POP)
# - Action function calls
# - Proper cleanup
```

**Red flags**:
- Missing action function calls
- Wrong number of parameters
- Incorrect stack operations before/after action

### Step 4: Review the Runtime Implementation

**Check the actual opcode implementation**:

```bash
# Find your opcode's implementation
grep -A 50 "void action<YourOpcode>" SWFModernRuntime/src/actionmodern/action.c
```

**Common implementation issues**:

**Stack order (CRITICAL)**:
```c
// For binary operations: a OP b
// Stack has: [... b, a] (a on top)
// You must pop in reverse order!

ActionVar a;
popVar(stack, sp, &a);  // Pop 'a' first (top of stack)

ActionVar b;
popVar(stack, sp, &b);  // Pop 'b' second

// Now compute: b OP a (NOT a OP b!)
float result = b.value.f32 OP a.value.f32;
```

**Type conversions**:
```c
// ALWAYS convert types before operations
convertFloat(stack, sp);  // Convert top to float
ActionVar a;
popVar(stack, sp, &a);
// Now a.value.f32 is valid
```

**String handling**:
```c
// Strings need proper buffer management
char str_buffer[256];  // Ensure adequate size
const char* input = (const char*) VAL(u64, &STACK_TOP_VALUE);

// Check for null!
if (input == NULL) {
    input = "";  // Or handle appropriately
}

// Use safe string functions
snprintf(str_buffer, sizeof(str_buffer), "%s", processed);
```

### Step 5: Make the Fix

Based on the root cause, make the appropriate fix:

**For runtime bugs** (most common):
```bash
# Edit the implementation
nano SWFModernRuntime/src/actionmodern/action.c

# Make your changes
# Save and exit
```

**For translation bugs**:
```bash
# Edit the translation case
nano SWFRecomp/src/action/action.cpp

# Make your changes
# Rebuild SWFRecomp
cd SWFRecomp/build
make
cd ../..
```

**For test bugs**:
```bash
# Fix the test SWF generation or expected values
nano tests/<test_name>/create_test_swf.py
# OR
nano tests/<test_name>/validate.py
```

### Step 6: Rebuild and Verify

**Critical**: Always rebuild from scratch after changes:

```bash
# Clean build directory
rm -rf tests/<test_name>/build/

# If you changed SWFRecomp, also clean generated code
rm -rf tests/<test_name>/RecompiledScripts/
rm -rf tests/<test_name>/RecompiledTags/

# Rebuild and test
cd tests/<test_name>
../../scripts/build_test.sh <test_name> native
./build/native/<test_name>

# Run validation
./build/native/<test_name> 2>&1 | \
  grep -v "SWF Runtime" | grep -v "===" | grep -v "\[Frame" | grep -v "\[Tag\]" | grep -v "^$" | \
  ./validate.py
```

### Step 7: Run Full Test Suite

**Never skip this step!** Your fix might break other tests:

```bash
cd SWFRecomp/tests
./all_tests.sh

# Or just run related tests
./all_tests.sh | grep -E "(PASS|FAIL)"
```

### Step 8: Document the Fix

Update any relevant documentation:

1. **If it was a spec misunderstanding**: Add a comment explaining the correct behavior
2. **If it was an edge case**: Add a comment about the edge case handling
3. **If it required a workaround**: Document why and what the proper fix would be

## Stack-Based Execution Model

Understanding the stack model is **critical** for debugging:

**Stack Structure** (8MB array, grows downward):
```
Each stack entry (24 bytes):
├─ Offset +0:  u8 type (ACTION_STACK_VALUE_F32, ACTION_STACK_VALUE_STRING, etc.)
├─ Offset +4:  u32 previous_sp (link to previous entry)
├─ Offset +8:  u32 length (for strings)
├─ Offset +16: u64 value (float, pointer, etc.)
```

**Key Macros**:
- `PUSH(type, value)` - Allocate new stack entry
- `POP()` - Move to previous entry
- `STACK_TOP_TYPE` - Read top entry type
- `STACK_TOP_VALUE` - Read top entry value
- `convertFloat(stack, sp)` - Convert top entry to float
- `convertString(stack, sp, buffer)` - Convert top entry to string

**Critical Stack Rules**:

1. **Binary operation order** (most common bug source):
   ```
   To compute: 7 % 3

   Push order:
   1. PUSH 7  (becomes 'b' after two pops)
   2. PUSH 3  (becomes 'a' after first pop)

   Pop order:
   1. POP → a = 3
   2. POP → b = 7

   Compute: b % a = 7 % 3 = 1
   ```

2. **Stack balance**: Every function must leave stack balanced
   - Binary ops: 2 pops, 1 push (net -1)
   - Unary ops: 1 pop, 1 push (net 0)
   - Trace: 1 pop, 0 push (net -1)

3. **Type consistency**: Type field must match value
   - `ACTION_STACK_VALUE_F32` → value is float
   - `ACTION_STACK_VALUE_STRING` → value is pointer
   - `ACTION_STACK_VALUE_I32` → value is int

## Common Bug Patterns and Fixes

### Bug Pattern 1: Wrong Operand Order

**Symptom**: `7 % 3` returns `3` instead of `1`

**Cause**: Popping in wrong order

**Wrong**:
```c
ActionVar b;
popVar(stack, sp, &b);  // Gets 'a' (top)

ActionVar a;
popVar(stack, sp, &a);  // Gets 'b' (second)

float result = a.value.f32 % b.value.f32;  // Actually b % a, not a % b!
```

**Correct**:
```c
ActionVar a;
popVar(stack, sp, &a);  // Pop top first (this is 'a')

ActionVar b;
popVar(stack, sp, &b);  // Pop second (this is 'b')

float result = b.value.f32 % a.value.f32;  // Compute b % a
```

### Bug Pattern 2: Missing Type Conversion

**Symptom**: Crash or wrong result with mixed types

**Cause**: Not converting before operation

**Wrong**:
```c
ActionVar a;
popVar(stack, sp, &a);
// If 'a' is a string, a.value.f32 is garbage!
float result = a.value.f32 * 2;
```

**Correct**:
```c
convertFloat(stack, sp);  // Convert to float first
ActionVar a;
popVar(stack, sp, &a);
float result = a.value.f32 * 2;  // Now safe
```

### Bug Pattern 3: String Buffer Overflow

**Symptom**: Crash or corrupted output

**Cause**: String longer than buffer

**Wrong**:
```c
char buffer[10];
snprintf(buffer, sizeof(buffer), "Very long string that exceeds buffer");
// Only "Very long " fits, rest is truncated
```

**Correct**:
```c
char buffer[256];  // Adequate size
snprintf(buffer, sizeof(buffer), "Very long string that exceeds buffer");
// Or calculate required size dynamically
```

### Bug Pattern 4: Null Pointer Dereference

**Symptom**: Crash when operating on null/undefined values

**Cause**: Not checking for null

**Wrong**:
```c
const char* str = (const char*) VAL(u64, &STACK_TOP_VALUE);
int len = strlen(str);  // Crash if str is NULL!
```

**Correct**:
```c
const char* str = (const char*) VAL(u64, &STACK_TOP_VALUE);
if (str == NULL) {
    str = "";  // Treat null as empty string
}
int len = strlen(str);  // Safe
```

### Bug Pattern 5: Stack Imbalance

**Symptom**: Later operations fail mysteriously

**Cause**: Not matching PUSHes with POPs

**Wrong**:
```c
void actionBrokenOp(char* stack, u32* sp)
{
    // Pop two values
    POP();
    POP();

    // Oops, forgot to push result!
    // Stack is now 2 shorter than it should be
}
```

**Correct**:
```c
void actionFixedOp(char* stack, u32* sp)
{
    ActionVar a, b;
    popVar(stack, sp, &a);
    popVar(stack, sp, &b);

    float result = b.value.f32 + a.value.f32;
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
    // Stack net change: -2 + 1 = -1 (correct for binary op)
}
```

## Debugging Tools

### Adding Debug Output

**In runtime code** (action.c):
```c
void actionYourOpcode(char* stack, u32* sp)
{
    #ifdef DEBUG_OPCODE
    printf("DEBUG: Entering actionYourOpcode\n");
    printf("DEBUG: Stack pointer: %p\n", (void*)sp);
    printf("DEBUG: Top value: %lu\n", STACK_TOP_VALUE);
    #endif

    // ... your implementation ...

    #ifdef DEBUG_OPCODE
    printf("DEBUG: Result: %f\n", result);
    #endif
}
```

**Compile with debug flag**:
```bash
# Edit build_test.sh temporarily to add -DDEBUG_OPCODE
gcc -DNO_GRAPHICS -D_GNU_SOURCE -DDEBUG_OPCODE ...
```

### Using GDB

```bash
cd tests/<test_name>
gdb ./build/native/<test_name>

# Set breakpoint
(gdb) break actionYourOpcode

# Run
(gdb) run

# When it hits breakpoint
(gdb) print *(float*)&result
(gdb) print (char*)VAL(u64, &STACK_TOP_VALUE)
(gdb) backtrace

# Continue
(gdb) continue
```

### Examining Generated Code

```bash
# See what SWFRecomp generated
cat tests/<test_name>/RecompiledScripts/script_0.c

# Look for your opcode call
grep "action<YourOpcode>" tests/<test_name>/RecompiledScripts/script_0.c
```

## Test Validation System

### Understanding Output Filtering

The test runner automatically removes these lines before validation:
- Lines starting with "SWF Runtime"
- Lines starting with "==="
- Lines starting with "[Frame"
- Lines starting with "[Tag]"
- Empty lines

**Example**:

Raw output:
```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
[Tag] SetBackgroundColor(255, 255, 255)
42
100
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

Filtered output (what validate.py sees):
```
42
100
```

### Fixing Validation Scripts

**Common validation issues**:

1. **Wrong expected value**:
```python
# Wrong
expected = "42.0"
actual = lines[0]  # Actual is "42"

# Fixed - match actual output format
expected = "42"
```

2. **Float precision**:
```python
# Wrong - exact comparison
expected = 3.14159
actual = float(lines[0])  # Might be 3.141590118

# Fixed - approximate comparison
import math
expected = 3.14159
actual = float(lines[0])
passed = math.isclose(actual, expected, rel_tol=1e-5)
```

3. **Multiple outputs**:
```python
# Check all outputs
results = []
results.append(make_result("first", lines[0] == "42", "42", lines[0]))
results.append(make_result("second", lines[1] == "100", "100", lines[1]))
return make_validation_result(results)
```

## Specification Reference

Always verify behavior against the official specification:

```bash
# Look up opcode details
grep -A 30 "ActionYourOpcode" SWFRecompDocs/specs/swf-spec-19.txt

# Check opcode hex value
grep "0xXX" SWFRecompDocs/specs/swf-spec-19.txt
```

**Key specification details**:
- Opcode hex value
- Number of operands
- Stack effects (what it pops/pushes)
- Type handling (what types are accepted)
- Edge case behavior

## Success Criteria

A test fix is complete when:

1. ✅ Test builds without errors or warnings
2. ✅ Test produces correct output for all cases
3. ✅ Validation script passes
4. ✅ Edge cases handled correctly
5. ✅ No crashes or undefined behavior
6. ✅ All other tests in suite still pass
7. ✅ Fix documented with comments if non-obvious

## Summary Checklist

When fixing a failing test, follow this checklist:

- [ ] Reproduced the failure locally
- [ ] Identified the root cause (runtime/translation/test/spec)
- [ ] Examined generated C code from SWFRecomp
- [ ] Checked runtime implementation in action.c
- [ ] Verified stack operation order is correct
- [ ] Confirmed type conversions are in place
- [ ] Made the fix in the appropriate location
- [ ] Rebuilt from scratch (clean build)
- [ ] Verified fix with manual test run
- [ ] Confirmed validation script passes
- [ ] Ran full test suite to check for regressions
- [ ] Added comments documenting the fix if needed
- [ ] Removed any debug output before committing

## Getting Help

If you're stuck:

1. **Check similar opcodes** - Look at working implementations of similar operations
2. **Read the spec carefully** - The behavior might be subtly different than expected
3. **Add debug output** - Print intermediate values to understand what's happening
4. **Test incrementally** - Make small changes and test after each one
5. **Check git history** - See if this test passed before and what changed

## Key Resources

**Specifications**:
- `SWFRecompDocs/specs/swf-spec-19.txt` - Complete SWF v4+ specification

**Implementation Examples**:
- `SWFRecomp/tests/trace_swf_4/` - Simple working example
- `SWFRecomp/tests/modulo_swf_4/` - Arithmetic operation example
- `SWFRecomp/tests/string_equals_swf_4/` - String operation example

**Build and Test**:
- `SWFRecomp/scripts/build_test.sh` - Automated build script
- `SWFRecomp/tests/all_tests.sh` - Full test suite runner
- `SWFModernRuntime/src/actionmodern/action.c` - Runtime implementations

**For new implementations**, use `parallel-opcode-implementation-guide.md` instead.
