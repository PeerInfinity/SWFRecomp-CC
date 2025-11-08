# AS2 Opcode Implementation Guide: Parallel Development with Claude Code

This guide explains how to implement ActionScript 2 (AS2) opcodes in the SWFRecomp project using Claude Code's web interface for parallel execution.

## Overview

This workflow enables autonomous implementation of individual AS2 opcodes across multiple Claude Code instances. Each instance implements a specific opcode from specification through testing, working independently until completion.

**Status**: ✅ Build pipeline validated (Experiment #1: Hello World Smoke Test - 2025-11-05)
- Build time: ~2 seconds per test
- Uses NO_GRAPHICS mode (console-only, no SDL3/Vulkan dependencies)
- Automated build script: `./scripts/build_test.sh <test_name> native`

## Quick Start

Before implementing opcodes, verify your environment is set up:

```bash
# 1. Build SWFRecomp (one-time setup, ~27 seconds)
cd SWFRecomp
mkdir -p build && cd build
cmake ..
make
cd ../..

# 2. Build and run a test
cd SWFRecomp
./scripts/build_test.sh trace_swf_4 native
./tests/trace_swf_4/build/native/trace_swf_4
```

**Expected output:**
```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
[Tag] SetBackgroundColor(255, 255, 255)
sup from SWF 4
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

**Note**: When tests are run through the test suite (`all_tests.sh`), the runtime messages (lines starting with "SWF Runtime", "===", "[Frame", "[Tag]", and empty lines) are automatically filtered out, leaving only the actual test output (in this case, "sup from SWF 4").

If this works, your environment is ready for opcode implementation!

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

### Repository Organization for Parallel Work

For Claude Code parallel execution, all three repositories are combined into a single workspace:
- `SWFRecomp/` - Recompiler code
- `SWFModernRuntime/` - Runtime code
- `SWFRecompDocs/` - Documentation

This eliminates the need to manage separate repositories and simplifies the build process.

## The Implementation Process

### Architecture Overview

```
SWF File (Flash bytecode)
    ↓
[SWFRecomp - Compile-time translation]
    ├─ Parse SWF and bytecode
    ├─ Translate opcodes to C function calls
    └─ Generate C source code
    ↓
Generated C Code
    ↓
[C Compiler - gcc/emcc]
    ├─ Compile generated code
    ├─ Link with SWFModernRuntime
    └─ Create executable
    ↓
[SWFModernRuntime - Execution]
    ├─ Stack-based execution
    ├─ Opcode implementations
    └─ Display output
```

### Stack-Based Execution Model

All AS2 operations use a runtime stack:

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

### The 8-Step Implementation Workflow

**Note**: Many opcodes may already be partially or fully implemented. Before starting, check:
- `SWFRecomp/include/action/action.hpp` - Check if enum exists
- `SWFRecomp/src/action/action.cpp` - Check if translation case exists
- `SWFModernRuntime/include/actionmodern/action.h` - Check if API is declared
- `SWFModernRuntime/src/actionmodern/action.c` - Check if runtime is implemented
- `SWFRecomp/tests/<opcode>_swf_N/` - Check if test directory exists

If the opcode is fully implemented but missing validation files, **skip to Step 6** to add test validation.

#### Step 1: Define Enum (SWFRecomp)

Add opcode to `SWFRecomp/include/action/action.hpp`:

```cpp
enum SWFActionType
{
    // ... existing opcodes ...
    SWF_ACTION_YOUR_OPCODE = 0xXX,  // Use hex value from specification
};
```

#### Step 2: Add Translation (SWFRecomp)

Add case to `SWFRecomp/src/action/action.cpp` in the `parseActions()` switch statement:

```cpp
case SWF_ACTION_YOUR_OPCODE:
{
    out_script << "\t" << "// Your Opcode Name" << endl
               << "\t" << "actionYourOpcode(stack, sp);" << endl;

    // If opcode has a length field (high bit 0x80 set):
    // action_buffer += length;

    break;
}
```

#### Step 3: Declare API (SWFModernRuntime)

Add function declaration to `SWFModernRuntime/include/actionmodern/action.h`:

```c
void actionYourOpcode(char* stack, u32* sp);
```

#### Step 4: Implement Runtime (SWFModernRuntime)

Implement function in `SWFModernRuntime/src/actionmodern/action.c`:

**Binary Operation Pattern**:
```c
void actionYourOpcode(char* stack, u32* sp)
{
    // Convert and pop second operand
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Convert and pop first operand
    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Perform operation
    float result = b.value.f32 OP a.value.f32;

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Unary Operation Pattern**:
```c
void actionYourOpcode(char* stack, u32* sp)
{
    // Convert and pop operand
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    // Perform operation
    float result = OPERATION(a.value.f32);

    // Push result
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**String Operation Pattern**:
```c
void actionYourOpcode(char* stack, u32* sp, char* str_buffer)
{
    // Get string from stack
    ActionVar a;
    peekVar(stack, sp, &a);
    const char* str = (const char*) VAL(u64, &STACK_TOP_VALUE);

    // Process string
    // ... operation logic ...

    // Generate result
    snprintf(str_buffer, 17, "result");

    // Pop input and push result
    POP();
    PUSH_STR(str_buffer, strlen(str_buffer));
}
```

#### Step 5: Create Test SWF

Create an ActionScript test file that uses the opcode:

**Example test.as**:
```actionscript
// For arithmetic operation
trace(5 OPERATION 3);  // Replace OPERATION with your opcode's operator
```

Compile to SWF using Flex SDK or MTASC compiler. Verify the expected output manually.

**IMPORTANT - Stack Operation Order**:

When creating test SWFs manually (using Python scripts), remember that SWF uses a **stack-based execution model**:

For binary operations `(a OP b)`:
- **Push b first** (becomes second operand after two pops)
- **Push a second** (becomes first operand after first pop)
- **Result**: `b OP a`

**Example for 7 % 3**:
```python
action_push_7 = ...  # Push 7 first (second operand 'b')
action_push_3 = ...  # Push 3 second (first operand 'a')
action_modulo = bytes([0x3F])  # Computes: 7 % 3 = 1
```

If you push in the wrong order, you'll compute `3 % 7 = 3` instead of `7 % 3 = 1`!

#### Step 6: Setup Test Directory and Validation

**If test directory already exists** (many opcodes are already implemented):
- Check if `test_info.json` and `validate.py` exist
- If missing, create them following the templates below
- Skip to Step 8 to verify

**If creating new test directory**:

```bash
# Create test directory
cd SWFRecomp/tests
mkdir your_opcode_swf_4

# Copy templates
cp templates/test_info_deterministic.json your_opcode_swf_4/test_info.json
cp templates/validate.py.template your_opcode_swf_4/validate.py
chmod +x your_opcode_swf_4/validate.py

# Copy config template
cp trace_swf_4/config.toml your_opcode_swf_4/

# Option A: Place your test.swf in the directory
cp /path/to/your/test.swf your_opcode_swf_4/test.swf

# Option B: Create a Python script to generate test.swf (recommended)
# The build script will automatically run it if test.swf is missing
cat > your_opcode_swf_4/create_test_swf.py << 'EOF'
#!/usr/bin/env python3
# Script to generate test.swf
# (See existing tests for examples: random_number_swf_4/create_test_swf.py)
EOF
```

**config.toml structure**:
```toml
[input]
path_to_swf = "test.swf"
output_tags_folder = "RecompiledTags"
output_scripts_folder = "RecompiledScripts"

[output]
do_recompile = true
```

**test_info.json** - Update with your opcode details:
```json
{
  "metadata": {
    "name": "your_opcode_swf_4",
    "description": "Tests YOUR_OPCODE opcode (operation description)",
    "swf_version": 4,
    "fully_implemented": false
  },
  "opcodes": {
    "tested": ["YOUR_OPCODE"],
    "supporting": ["PUSH", "TRACE"]
  },
  "execution": {
    "type": "deterministic"
  }
}
```

For non-deterministic tests (like random number generation), use `"type": "range_validation"` instead.

**Important: `fully_implemented` field**

The `fully_implemented` field in the metadata section indicates whether the opcode is **completely implemented** and **thoroughly tested**. This field is used to track implementation progress and appears in the opcode index.

Set `fully_implemented` to **`true`** only when ALL of the following conditions are met:

1. **Complete implementation**: The opcode itself is fully implemented with all required functionality
2. **All dependencies working**: All supporting functionality required by the opcode is fully implemented
3. **Comprehensive testing**: The test covers all relevant cases for the opcode
4. **No known issues**: There are no TODO comments, FIXME notes, or documentation indicating missing/incomplete functionality

Set `fully_implemented` to **`false`** (or omit it) if ANY of the following apply:

- The opcode implementation is missing any functionality
- Any required supporting functionality is incomplete or missing
- The test doesn't cover all relevant edge cases
- There are comments or documentation indicating something is incomplete
- There are known bugs or issues with the implementation

**Examples:**

✅ **Set to `true`**:
```json
{
  "metadata": {
    "name": "add_swf_4",
    "description": "Tests ADD opcode - adds two numbers",
    "swf_version": 4,
    "fully_implemented": true
  }
}
```
The ADD opcode is simple, fully implemented, and the test covers basic cases and edge cases.

❌ **Set to `false`**:
```json
{
  "metadata": {
    "name": "init_object_swf_5",
    "description": "Tests INIT_OBJECT opcode - creates objects",
    "swf_version": 5,
    "fully_implemented": false
  }
}
```
The INIT_OBJECT opcode requires object property support which may not be fully implemented yet.

**When in doubt, set to `false`**. It's better to be conservative - you can always update it to `true` later once everything is confirmed working.

**validate.py** - Implement validation logic:

```python
#!/usr/bin/env python3
"""
Validation script for your_opcode_swf_4

Tests the YOUR_OPCODE opcode.
Expected output: (describe expected behavior)
"""
import sys
import json
import os

# Import common utilities
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(script_dir, '..'))
from test_utils import parse_output, make_result, make_validation_result


def validate_output(output):
    """
    Validate test output.

    Expected: (describe what the test should output)
    """
    lines = parse_output(output)

    # Simple single-output validation
    expected = "42"  # Replace with your expected output
    actual = lines[0] if lines else ""

    return make_validation_result([
        make_result(
            "test_name",  # Descriptive name for this test case
            actual == expected,
            expected,
            actual
        )
    ])


if __name__ == "__main__":
    output = sys.stdin.read()
    result = validate_output(output)
    print(json.dumps(result, indent=2))
```

**Validation patterns**:

For **simple single output**:
```python
expected = "42"
actual = lines[0] if lines else ""
return make_validation_result([
    make_result("test_case", actual == expected, expected, actual)
])
```

For **multiple outputs**:
```python
results = []
results.append(make_result("output_1", lines[0] == "42", "42", lines[0]))
results.append(make_result("output_2", lines[1] == "100", "100", lines[1]))
return make_validation_result(results)
```

For **range validation** (non-deterministic):
```python
try:
    value = int(lines[0])
    passed = 0 <= value < 10
    return make_validation_result([
        make_result("range_check", passed, "[0, 10)", str(value))
    ])
except ValueError:
    return make_validation_result([
        make_result("range_check", False, "[0, 10)", lines[0],
                   "Could not parse as integer")
    ])
```

**Helper utilities** (`test_utils.py` provides):
- `parse_output(output)` - Clean and split output lines
- `make_result(name, passed, expected, actual, message=None)` - Create test result
- `make_validation_result(sub_tests)` - Create complete validation output
- `validate_single_output(output, expected, test_name)` - Quick single-value check
- `validate_multiple_outputs(output, expected_values, test_names)` - Quick multi-value check
- `validate_integer_range(output, min_val, max_val, test_name)` - Range validation

See `tests/templates/README.md` for detailed validation patterns and examples.

**Note**: You do NOT need to copy runtime files, Makefiles, or build scripts. The automated build script (`scripts/build_test.sh`) handles all of this for you.

**Auto-generation feature** (added 2025-11-05): The build script now automatically detects when `test.swf` is missing and looks for generation scripts (`create_test_swf.py`, `generate_swf.py`, `make_test.py`, `create_swf.py`). If found, it runs the script automatically before compilation. This eliminates the manual step of generating test files.

#### Step 7: Build and Test

Build your test to verify the implementation works:

```bash
# From SWFRecomp directory
cd SWFRecomp

# Build test using automated script (~2 seconds)
./scripts/build_test.sh your_opcode_swf_4 native

# Run test manually (to see raw output)
./tests/your_opcode_swf_4/build/native/your_opcode_swf_4

# Verify output matches expected result
```

**What the build script does automatically:**
1. Generates test.swf if missing (runs create_test_swf.py or similar)
2. Runs SWFRecomp if RecompiledScripts/ doesn't exist
3. Copies SWFModernRuntime sources (action.c, variables.c, etc.)
4. Copies generated files (script_*.c, tagMain.c, etc.)
5. Compiles with NO_GRAPHICS mode (console-only)
6. Links everything into a single executable

**Build output location:**
- Native: `tests/your_opcode_swf_4/build/native/your_opcode_swf_4`
- WASM: `tests/your_opcode_swf_4/build/wasm/your_opcode_swf_4.wasm` (if you have Emscripten)

**Understanding test output:**

When you run a test directly, you'll see runtime messages along with the actual output:
```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
[Tag] SetBackgroundColor(255, 255, 255)
42
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

In this example, the actual test output is just `42`. The test validation system automatically filters out:
- Lines starting with "SWF Runtime"
- Lines starting with "==="
- Lines starting with "[Frame"
- Lines starting with "[Tag]"
- Empty lines

So your `validate.py` script will receive only the clean output: `42`

#### Step 8: Verify with Test Runner

Run the automated test suite to verify your implementation:

```bash
# Run all tests
cd SWFRecomp/tests
./all_tests.sh

# Or run just your test
cd SWFRecomp/tests
./all_tests.sh your_opcode_swf_4

# Or manually test validation script (for debugging)
cd SWFRecomp/tests/your_opcode_swf_4
../../scripts/build_test.sh your_opcode_swf_4 native
./build/native/your_opcode_swf_4 2>&1 | \
  grep -v "SWF Runtime" | grep -v "===" | grep -v "\[Frame" | grep -v "\[Tag\]" | grep -v "^$" | \
  ./validate.py
```

**Expected validation output** (JSON):
```json
{
  "passed": true,
  "sub_tests": [
    {
      "name": "test_case",
      "passed": true,
      "expected": "42",
      "actual": "42"
    }
  ]
}
```

**Test suite output:**

When running `./all_tests.sh`, you'll see a summary like:
```
========================================
SWFRecomp Test Suite Results
========================================
Timestamp: 2025-11-06 12:34:56

Tests:     95 / 95 passed (0 failed, 0 skipped)
Sub-tests: 150 / 150 passed
Time:      45.2s total (build: 32.1s, run: 13.1s)

Results saved to: tests/test_results.json
========================================
```

**If validation fails**:
- Check that expected values in validate.py match test specification
- Verify test output matches what you expect (run test manually first)
- Add debug output to validate.py to see what's being compared
- Check test_utils.py is being imported correctly (use `sys.path.insert(0, '..')`)
- Verify the output filtering is working correctly

**Detailed results:**
- JSON results are saved to `tests/test_results.json`
- Contains build times, execution times, and detailed failure messages
- Includes all sub-test results for debugging

## Build System Details

### Building SWFRecomp (One-Time Setup)

```bash
cd SWFRecomp
mkdir -p build && cd build
cmake ..
make
cd ../..
```

**Build time**: ~27 seconds (CMake: 19s, Make: 8s)
**Output**: `SWFRecomp/build/SWFRecomp` executable

### Using the Automated Build Script

The `scripts/build_test.sh` script automates the entire build process:

```bash
# Build native executable
./scripts/build_test.sh <test_name> native

# Build WASM (requires Emscripten and emsdk activation)
source ~/tools/emsdk/emsdk_env.sh  # Activate Emscripten first
./scripts/build_test.sh <test_name> wasm
```

**Features:**
- Automatically runs SWFRecomp if needed
- Copies all required SWFModernRuntime sources
- Uses NO_GRAPHICS mode (no SDL3/Vulkan dependencies)
- Compiles with proper flags (-DNO_GRAPHICS, -D_GNU_SOURCE)
- Links with c-hashmap for variable storage
- Creates clean build directory structure

**Build time**: ~2 seconds per test (native), ~4 seconds per test (WASM)

**For detailed WASM build instructions**, see `SWFRecompDocs/reference/wasm-build-process.md`

### Test Directory Structure

**Minimal setup** (what you create):
```
your_opcode_swf_4/
├── test.swf ..................... Input Flash file
└── config.toml .................. Recompiler configuration
```

**After running SWFRecomp**:
```
your_opcode_swf_4/
├── test.swf
├── config.toml
├── RecompiledScripts/ ........... Generated by SWFRecomp
│   ├── script_0.c ............... Translated ActionScript
│   ├── script_defs.c ............ String constants
│   ├── script_decls.h
│   └── out.h
└── RecompiledTags/ .............. Generated by SWFRecomp
    ├── tagMain.c ................ Frame execution
    ├── constants.c/h ............ Graphics constants
    └── draws.c/h ................ Shape data
```

**After running build script**:
```
your_opcode_swf_4/
├── test.swf
├── config.toml
├── RecompiledScripts/
├── RecompiledTags/
└── build/
    └── native/ .................. Build directory
        ├── your_opcode_swf_4 .... Executable
        └── *.c .................. All source files (for debugging)
```

**Note**: You do NOT need to manually create runtime/, Makefile, or other build files. The build script handles everything.

### Test Validation System

The test system uses Python validation scripts to determine pass/fail status for each test.

**How it works:**

1. **Build**: Test is compiled using `build_test.sh`
2. **Execute**: Test binary runs and produces output to stdout
3. **Filter**: Runtime messages are filtered out (see "Understanding test output" in Step 7)
4. **Validate**: Filtered output is piped to `validate.py` for evaluation
5. **Report**: Results are saved to JSON and summarized

**Output filtering:**

The test runner automatically removes these lines from test output before validation:
- Lines starting with "SWF Runtime"
- Lines starting with "==="
- Lines starting with "[Frame"
- Lines starting with "[Tag]"
- Empty lines

This is done using the `filter_output()` function in `all_tests.sh`:
```bash
filter_output() {
    grep -v "SWF Runtime Loaded" | \
    grep -v "=== SWF" | \
    grep -v "\[Frame" | \
    grep -v "\[Tag\]" | \
    grep -v "^$" || true
}
```

**Example:**

Raw test output:
```
SWF Runtime Loaded (Native Build)

=== SWF Execution Started (NO_GRAPHICS mode) ===

[Frame 0]
42
[Tag] ShowFrame()

=== SWF Execution Completed ===
```

Filtered output (what `validate.py` receives):
```
42
```

**Running tests:**

```bash
# Run all tests
cd SWFRecomp/tests
./all_tests.sh

# Run specific test
cd SWFRecomp/tests
./all_tests.sh trace_swf_4

# Manual validation (for debugging)
cd SWFRecomp/tests/trace_swf_4
./build/native/trace_swf_4 2>&1 | \
  grep -v "SWF Runtime" | grep -v "===" | grep -v "\[Frame" | grep -v "\[Tag\]" | grep -v "^$" | \
  ./validate.py
```

**For detailed information about the test system design**, see `SWFRecompDocs/plans/test-system-redesign-plan.md`

## Opcode Categories and Complexity

### Simple (1-2 hours)

**Arithmetic**: Modulo, Increment, Decrement
- Binary operations on two floats
- Simple math operations
- Pattern: convert → pop → pop → compute → push

**Comparison**: Greater, GreaterEquals, LessEquals
- Compare two values
- Return boolean (0.0 or 1.0)
- Pattern: convert → pop → pop → compare → push bool

### Medium (2-4 hours)

**String Operations**: Substring, CharAt, ToUpperCase, ToLowerCase
- String manipulation
- May require character iteration
- Pattern: peek/pop string → process → push result

**Logic**: XOR, ShiftLeft, ShiftRight
- Bitwise or boolean operations
- Type conversion considerations
- Pattern: convert to int → operate → push result

**Stack Operations**: Duplicate, Swap
- Stack manipulation without computation
- Careful with stack pointer management
- Pattern: peek/copy → rearrange → push

### Complex (4-8 hours)

**Control Flow**: Switch, Call, Return
- May require additional infrastructure
- Jump table management
- Call stack considerations

**Object/Array**: GetProperty, SetProperty, GetMember, SetMember
- Requires object model implementation
- Hash table or property storage
- Type system integration
- **IMPORTANT**: See "Object Allocation Model" section below

**Advanced**: InitArray, InitObject, Enumerate
- Complex data structure creation
- Memory management with reference counting
- Iterator patterns
- **IMPORTANT**: See "Object Allocation Model" section below

## Currently Implemented Opcodes (25 total)

| Opcode | Hex  | Name | Category |
|--------|------|------|----------|
| 0x00 | 0x00 | END_OF_ACTIONS | Control |
| 0x07 | 0x07 | STOP | Control |
| 0x0A | 0x0A | ADD | Arithmetic |
| 0x0B | 0x0B | SUBTRACT | Arithmetic |
| 0x0C | 0x0C | MULTIPLY | Arithmetic |
| 0x0D | 0x0D | DIVIDE | Arithmetic |
| 0x0E | 0x0E | EQUALS | Comparison |
| 0x0F | 0x0F | LESS | Comparison |
| 0x10 | 0x10 | AND | Logic |
| 0x11 | 0x11 | OR | Logic |
| 0x12 | 0x12 | NOT | Logic |
| 0x13 | 0x13 | STRING_EQUALS | String |
| 0x14 | 0x14 | STRING_LENGTH | String |
| 0x17 | 0x17 | POP | Stack |
| 0x1C | 0x1C | GET_VARIABLE | Variables |
| 0x1D | 0x1D | SET_VARIABLE | Variables |
| 0x21 | 0x21 | STRING_ADD | String |
| 0x26 | 0x26 | TRACE | Debug |
| 0x34 | 0x34 | GET_TIME | Special |
| 0x3F | 0x3F | MODULO | Arithmetic |
| 0x88 | 0x88 | CONSTANT_POOL | Special |
| 0x96 | 0x96 | PUSH | Stack |
| 0x99 | 0x99 | JUMP | Control |
| 0x9D | 0x9D | IF | Control |

## Object Allocation Model

### Overview

**IMPORTANT**: For opcodes that create or manipulate objects/arrays (InitObject, InitArray, GetMember, SetMember, etc.), the system uses **compile-time inlined reference counting** instead of runtime garbage collection.

### Design Philosophy

**Reference Counting at Recompiler Level**:
- SWFRecomp emits inline refcount increment/decrement operations
- Deterministic memory management (no GC pauses)
- Compiler can optimize refcount operations
- Runtime only provides allocation/deallocation primitives

**NOT using Runtime GC**:
- No garbage collector in SWFModernRuntime
- No stop-the-world pauses
- Predictable performance
- Lower memory overhead

### Implementation Strategy

When implementing object/array opcodes, follow this pattern:

#### 1. Runtime Provides Primitives (SWFModernRuntime)

```c
// Object allocation/deallocation primitives
typedef struct {
    u32 refcount;
    // ... object properties ...
} ASObject;

ASObject* allocObject();
void retainObject(ASObject* obj);  // Increment refcount
void releaseObject(ASObject* obj); // Decrement refcount, free if zero
```

#### 2. Recompiler Emits Inline Refcount Operations (SWFRecomp)

When translating object operations, emit refcount management:

```cpp
// Example: InitObject translation in SWFRecomp/src/action/action.cpp
case SWF_ACTION_INIT_OBJECT:
{
    out_script << "\t" << "// InitObject" << endl
               << "\t" << "ASObject* obj = allocObject();" << endl
               << "\t" << "obj->refcount = 1;  // Initial reference" << endl
               << "\t" << "PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, obj));" << endl;
    break;
}

// Example: Setting a property (increments refcount)
case SWF_ACTION_SET_MEMBER:
{
    out_script << "\t" << "// SetMember - inline refcount management" << endl
               << "\t" << "actionSetMember(stack, sp);" << endl
               << "\t" << "// retainObject() called within actionSetMember" << endl;
    break;
}
```

#### 3. Reference Counting Rules

**When to Increment (`retainObject`)**:
- Storing object reference in a variable
- Adding object to an array/container
- Assigning object to a property
- Returning object from a function

**When to Decrement (`releaseObject`)**:
- Popping object from stack (if not stored elsewhere)
- Overwriting a variable that held an object
- Removing object from array
- Function/scope cleanup

**Compiler Optimizations**:
- Elide refcount operations when object lifetime is obvious
- Combine increment/decrement pairs that cancel out
- Use move semantics where possible

#### 4. Stack Interaction

Objects on the stack maintain refcounts:

```c
// Pushing object to stack
PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, obj));
// obj->refcount already = 1 from allocation

// Popping object from stack
ASObject* obj = (ASObject*) VAL(u64, &STACK_TOP_VALUE);
POP();
// Don't release if transferring to variable/property
// Do release if discarding
```

#### 5. Example: InitObject Implementation

**SWFRecomp Translation** (action.cpp):
```cpp
case SWF_ACTION_INIT_OBJECT:
{
    // Number of properties is on stack
    out_script << "\t" << "u32 num_props;" << endl
               << "\t" << "popU32(stack, sp, &num_props);" << endl
               << "\t" << "ASObject* obj = allocObject(num_props);" << endl
               << "\t" << "for (u32 i = 0; i < num_props; i++) {" << endl
               << "\t" << "    initObjectProperty(stack, sp, obj);" << endl
               << "\t" << "}" << endl
               << "\t" << "PUSH(ACTION_STACK_VALUE_OBJECT, VAL(u64, obj));" << endl;
    break;
}
```

**SWFModernRuntime Implementation** (action.c):
```c
ASObject* allocObject(u32 num_properties)
{
    ASObject* obj = malloc(sizeof(ASObject) + num_properties * sizeof(ASProperty));
    obj->refcount = 1;  // Initial reference
    obj->num_properties = num_properties;
    return obj;
}

void initObjectProperty(char* stack, u32* sp, ASObject* obj)
{
    // Pop value
    ActionVar val;
    popVar(stack, sp, &val);

    // Pop property name
    const char* name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // Store property (with refcount management if val is object)
    setProperty(obj, name, &val);
    if (val.type == ACTION_STACK_VALUE_OBJECT) {
        retainObject((ASObject*) val.value.u64);  // Retain when storing
    }
}

void releaseObject(ASObject* obj)
{
    if (obj == NULL) return;

    obj->refcount--;
    if (obj->refcount == 0) {
        // Release all property values
        for (u32 i = 0; i < obj->num_properties; i++) {
            if (obj->properties[i].value.type == ACTION_STACK_VALUE_OBJECT) {
                releaseObject((ASObject*) obj->properties[i].value.value.u64);
            }
        }
        free(obj);
    }
}
```

### Design Considerations

**Why Inline at Compile Time?**
- Compiler can see object lifetimes across multiple opcodes
- Can optimize away temporary references
- No runtime overhead for reference tracking
- Deterministic cleanup (no GC heuristics)

**Trade-offs**:
- ✅ Deterministic performance (no GC pauses)
- ✅ Simpler runtime (no GC implementation)
- ✅ Optimization opportunities (compiler sees full picture)
- ⚠️ Slightly larger generated code (refcount ops inlined)
- ⚠️ Must handle circular references (use weak references or explicit breaking)

### Circular Reference Handling

For circular references (rare in Flash AS2), use:
- **Weak references** for parent pointers
- **Explicit cleanup** in frame/scope exit
- **Cycle detection** for complex structures (optional, usually not needed)

### Testing Object Refcounts

Add assertions in debug builds:

```c
#ifdef DEBUG
void assertRefcount(ASObject* obj, u32 expected) {
    assert(obj->refcount == expected);
}
#endif
```

**IMPORTANT**: Before implementing any object/array opcodes, coordinate with the team to establish the base object model (ASObject structure, property storage, refcount primitives). These are shared infrastructure that multiple opcodes will use.

## Re-implementing Existing Opcodes (Adding Validation)

**Many opcodes are already implemented** but lack validation files. To add validation to an existing test:

1. **Check test directory** - Navigate to `SWFRecomp/tests/<opcode>_swf_N/`
2. **Verify test works** - Run `../../scripts/build_test.sh <opcode>_swf_N native` and verify output
3. **Create test_info.json** - Copy from `templates/test_info_deterministic.json` and update
4. **Create validate.py** - Copy from `templates/validate.py.template` and implement validation
5. **Test validation** - Run `cd .. && ./all_tests.sh` to verify

**Prompt-based approach**: For each prompt in `SWFRecompDocs/prompts/completed/`:
- The prompt contains test cases and expected outputs
- Create `test_info.json` based on opcode metadata in prompt
- Create `validate.py` based on expected outputs in prompt
- Test can be verified immediately with `./all_tests.sh`

This is ideal for parallel work - each AI instance can work on a different existing test.

### Example: Adding Validation to bit_and_swf_4

```bash
# 1. Navigate to test directory
cd SWFRecomp/tests/bit_and_swf_4

# 2. Verify test works
../../scripts/build_test.sh bit_and_swf_4 native
./build/native/bit_and_swf_4
# Output: 8

# 3. Create test_info.json
cp ../templates/test_info_deterministic.json test_info.json
# Edit to add: "tested": ["BIT_AND"], "description": "Tests BIT_AND opcode..."

# 4. Create validate.py
cp ../templates/validate.py.template validate.py
chmod +x validate.py
# Edit to check: expected = "8", actual = lines[0]

# 5. Test validation
cd ..
./all_tests.sh
# Should show: [PASS] bit_and_swf_4
```

## Common Implementation Patterns

### Type Conversions

Flash has implicit type conversions that must be respected:

**String to Number**:
- Empty string → 0
- Numeric string → parsed value
- Non-numeric → NaN

**Number to String**:
- Format as decimal
- NaN → "NaN"
- Infinity → "Infinity"

**Boolean Context**:
- 0, NaN, null, undefined, "" → false
- Everything else → true

### Error Handling

Most opcodes should handle edge cases gracefully:
- Division by zero → Infinity or NaN
- Array out of bounds → undefined
- Null/undefined operations → type-specific defaults

### Stack Discipline

**Critical Rules**:
1. Every POP must have a matching previous PUSH
2. Every operation should leave the stack balanced
3. Type field must match value field
4. String pointers must remain valid

**Common Mistakes**:
- Forgetting to POP before PUSH in replacement operations
- Incorrect type in PUSH macro
- Not handling string buffer lifetime
- Stack pointer corruption from incorrect sp manipulation

## Testing Strategies

### Unit Testing

Each test should focus on one operation:
```actionscript
// Test basic case
trace(5 OP 3);

// Test edge cases
trace(0 OP 0);
trace(-1 OP 5);
trace(1.5 OP 2.5);
```

### Integration Testing

Test interactions between opcodes:
```actionscript
// Test compound expressions
trace((5 OP1 3) OP2 (8 OP3 2));

// Test with variables
var x = 5;
var y = 3;
trace(x OP y);
```

### Expected Output

Document expected output for verification:
```
Expected output:
8
0
4
3.75
```

## Debugging Tips

### Common Build Errors

**"Unimplemented action 0xXX"**
- Opcode not in enum (Step 1)
- Check `SWFRecomp/include/action/action.hpp`

**"undefined reference to actionXxx"**
- Missing declaration or implementation (Steps 3-4)
- Check `action.h` has declaration AND `action.c` has implementation

**"fatal error: flashbang.h: No such file or directory"** ✅ FIXED
- ~~Old issue: Build script tried to use full graphics mode~~
- Fixed in build_test.sh (2025-11-05)
- Now uses NO_GRAPHICS mode for all builds

**"undefined reference to PUSH_STR_ID"** ✅ FIXED
- PUSH_STR_ID is defined in `SWFModernRuntime/include/actionmodern/action.h`
- Build script automatically includes this header
- If you see this error, verify build script is being used correctly

**"CLOCK_MONOTONIC_RAW undeclared"** ✅ FIXED
- Fixed by adding `-D_GNU_SOURCE` flag in build script
- Build script now includes this automatically

**"undefined reference to fmod/fmodf/sin/cos/etc."** ✅ FIXED
- Math library not linked (needed for math.h functions)
- Fixed by adding `-lm` flag in build_test.sh (2025-11-05)
- Applies to all native builds automatically
- Emscripten (WASM builds) handles this automatically
- If implementing opcodes using `<math.h>`, this is already handled

**"Type mismatch" errors**
- Incorrect stack macro usage
- Check PUSH/POP types match

### Runtime Debugging

**Segmentation Fault on Startup** ✅ FIXED
- Old issue: Using wrong main.c that called `swfStart(frame_funcs)` directly
- Fixed: Build script now uses `wasm_wrappers/main.c` which properly creates `SWFAppContext`
- Do NOT use old test-specific main.c files

**Wrong Output**:
1. Check ActionScript test produces expected SWF bytecode
2. Verify SWFRecomp generates correct C code:
   ```bash
   # Check generated code
   cat tests/your_opcode_swf_4/RecompiledScripts/script_0.c
   ```
3. Add printf debugging in runtime implementation
4. Verify stack state before and after operation

**Crashes/Segfaults**:
1. Check stack pointer not corrupted
2. Verify string pointers are valid
3. Ensure proper POP/PUSH balance
4. Check array/buffer bounds
5. Ensure you're using the build script (not manual compilation)

### Build Script Troubleshooting

**Build script fails to find SWFModernRuntime**:
```
Error: SWFModernRuntime not found at: /path/to/SWFModernRuntime
```
- Check directory structure: SWFRecomp and SWFModernRuntime must be siblings
- Correct structure:
  ```
  /home/user/SWFRecomp-CC/
  ├── SWFRecomp/
  ├── SWFModernRuntime/
  └── SWFRecompDocs/
  ```

**Test runs but produces no output**:
- Check that test.swf contains trace() calls
- Verify SWFRecomp generated script_0.c with actionTrace() call
- Run with output redirect to see all messages:
  ```bash
  ./tests/your_opcode_swf_4/build/native/your_opcode_swf_4 2>&1
  ```

## Progress Tracking

As you implement each opcode, document:

**Implementation Checklist**:
- [ ] Opcode hex value confirmed from specification
- [ ] Enum added to action.hpp (or verified if exists)
- [ ] Translation case added to action.cpp (or verified if exists)
- [ ] Function declared in action.h (or verified if exists)
- [ ] Function implemented in action.c (or verified if exists)
- [ ] Test SWF created with known expected output (or verified if exists)
- [ ] Test directory created with all required files (or verified if exists)
- [ ] **test_info.json created with opcode metadata**
- [ ] **fully_implemented field set appropriately (true only if fully complete)**
- [ ] **validate.py created with test validation logic**
- [ ] SWFRecomp builds successfully
- [ ] Test compiles successfully
- [ ] Test produces correct output
- [ ] **Validation script passes (./all_tests.sh)**
- [ ] Edge cases tested
- [ ] Integration with other opcodes verified

**Documentation**:
- Opcode name and hex value
- Expected behavior (from specification)
- Implementation notes
- Test cases and expected outputs
- Any edge cases or special considerations
- Integration points with other opcodes

## Autonomous Work Guidelines

When working autonomously on an opcode:

1. **Read the specification** to understand expected behavior
2. **Examine similar opcodes** already implemented
3. **Follow the 7-step workflow** systematically
4. **Test incrementally** after each major step
5. **Document issues** and solutions as you encounter them
6. **Verify edge cases** before marking complete
7. **Run the full test suite** to ensure no regressions

**Don't**:
- Skip steps in the workflow
- Assume behavior without checking specification
- Leave test failures unresolved
- Commit untested code
- Make changes to unrelated files

## Key Resources

**Specifications**:
- `SWFRecompDocs/specs/swf-spec-19.txt` - Complete SWF v4+ specification
- Official ActionScript 2.0 Language Reference

**Implementation Examples**:
- `SWFRecomp/tests/trace_swf_4/` - Simple working example
- `SWFRecomp/tests/add_floats_swf_4/` - Arithmetic operation example
- `SWFRecomp/tests/string_equals_swf_4/` - String operation example

**Build and Test**:
- `SWFRecomp/scripts/build_test.sh` - Automated build script
- `SWFRecomp/CMakeLists.txt` - SWFRecomp build configuration
- `SWFModernRuntime/src/actionmodern/` - Runtime implementation examples
- `SWFRecomp/wasm_wrappers/main.c` - Proper entry point for NO_GRAPHICS mode

**Performance Metrics** (validated 2025-11-05):
- SWFRecomp build: ~27 seconds (one-time)
- Test compilation: ~2 seconds per test
- Executable size: ~36 KB (with full ActionScript VM)
- Pipeline latency: SWF → executable in ~2 seconds

## Success Criteria

An opcode implementation is complete when:

1. ✅ Builds without errors or warnings
2. ✅ Test produces correct output for basic cases
3. ✅ **Validation files created (test_info.json, validate.py)**
4. ✅ **Test passes in ./all_tests.sh**
5. ✅ Edge cases handled correctly
6. ✅ No crashes or undefined behavior
7. ✅ All tests in test suite still pass
8. ✅ Code follows existing patterns and style
9. ✅ Documentation updated

## Working in Parallel

### Coordination Points

**Phase 1** (Serial - coordination required):
- Enum definitions in action.hpp
- Function declarations in action.h

**Phase 2** (Parallel - independent work):
- Translation cases in action.cpp
- Runtime implementations in action.c
- Test creation and verification

**Phase 3** (Serial - integration):
- Full test suite execution
- Regression testing
- Final verification

### Minimizing Conflicts

- Each worker implements different opcodes
- Enum additions are append-only
- Switch cases are independent
- Runtime functions are independent
- Tests are in separate directories

### Suggested Work Distribution

**Team 1 - Arithmetic**: 0x18 (StringExtract), 0x31 (Modulo), etc.

**Team 2 - Comparison**: Greater (0x67), StrictEquals (0x66)

**Team 3 - String Ops**: Substring (0x35), CharToAscii (0x32), AsciiToChar (0x33)

**Team 4 - Logic**: ToInteger (0x18), BitAnd (0x60), BitOr (0x61), BitXor (0x62)

**Team 5 - Stack Ops**: Duplicate, Swap, StackSwap (0x4B)

**Team 6 - Control Flow**: Call (0x9E), Return (0x3E)

## Conclusion

### Validation Status

✅ **Build Pipeline Validated** (2025-11-05 - Experiment #1)
- SWFRecomp builds successfully in ~27 seconds
- Test compilation works reliably in ~2 seconds
- NO_GRAPHICS mode eliminates SDL3/Vulkan dependencies
- Automated build script handles all complexity
- trace_swf_4 test passes with expected output

✅ **7-Step Workflow Validated** (2025-11-05 - Experiment #2)
- Implemented Modulo opcode (0x3F) following all 7 steps
- Actual time: 45 minutes (well within 1-2 hour estimate for simple opcodes)
- Documentation sufficient for autonomous implementation
- Pattern-based development highly effective
- Math library linking fixed for all future builds
- Test: `7 % 3 = 1` passes correctly

🟢 **Status**: PRODUCTION READY for parallel opcode implementation
- Build system: ✅ Validated
- Workflow: ✅ Validated
- Documentation: ✅ Sufficient
- Time estimates: ✅ Accurate

### Summary

This systematic approach enables autonomous, parallel implementation of AS2 opcodes. Follow the 8-step workflow, test incrementally, and document thoroughly. Each opcode implementation should take 1-8 hours depending on complexity, with most simple operations completing in 1-3 hours.

**For existing opcodes**: Adding validation files (test_info.json and validate.py) takes 15-30 minutes per test and can be done in parallel across multiple AI instances.

**Key Advantages:**
1. **Fast iteration**: ~2 second build times enable rapid testing
2. **No dependencies**: NO_GRAPHICS mode works without graphics libraries
3. **Automated workflow**: Build script eliminates manual setup
4. **Clean separation**: Each opcode gets its own test directory
5. **Proven approach**: Successfully validated with real builds

The combined repository structure eliminates integration complexity, and the well-defined patterns make implementation straightforward. With proper testing and documentation, multiple teams can work simultaneously to rapidly expand opcode coverage.

### Next Steps

**For new opcode implementations**:
1. Choose an unimplemented opcode from the specification
2. Follow the 8-step workflow
3. Use `./scripts/build_test.sh` for all builds
4. Create validation files (test_info.json, validate.py)
5. Run `./all_tests.sh` to verify
6. Document any edge cases encountered

**For adding validation to existing tests**:
1. Check `SWFRecompDocs/prompts/completed/` for test specifications
2. Navigate to existing test directory
3. Create test_info.json from template
4. Create validate.py based on expected outputs in prompt
5. Run `./all_tests.sh` to verify
6. Repeat for next test (ideal for parallel work)

**Ready to begin?** Start with a simple arithmetic opcode (like Increment, Decrement, or comparison operators) to familiarize yourself with the workflow. See the "Opcode Categories and Complexity" section for suggestions.

**Reference implementations:**
- Simple arithmetic: See Modulo (0x3F) in `tests/modulo_swf_4/`
- String operations: See trace_swf_4, string_equals_swf_4
- Variables: See get_variable, set_variable tests
