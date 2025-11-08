# AS2 Opcode Complete Implementation Guide

This guide explains how to complete the implementation of ActionScript 2 (AS2) opcodes in the SWFRecomp project to achieve the **fully_implemented** status.

## Overview

This workflow is specifically for **completing partially implemented opcodes** to meet the criteria for the `fully_implemented: true` tag. If you're implementing a new opcode from scratch, use the `parallel-opcode-implementation-guide.md` instead. If you're fixing a failing test, use the `failing-test-fix-guide.md`.

**Status**: ✅ Build pipeline validated (Experiment #1: Hello World Smoke Test - 2025-11-05)
- Build time: ~2 seconds per test
- Uses NO_GRAPHICS mode (console-only, no SDL3/Vulkan dependencies)
- Automated build script: `./scripts/build_test.sh <test_name> native`

## Understanding "Fully Implemented"

The `fully_implemented` field in `test_info.json` indicates whether an opcode is **completely implemented** and **thoroughly tested**. This field is used to track implementation progress and appears in the opcode index.

### Criteria for `fully_implemented: true`

Set `fully_implemented` to **`true`** only when ALL of the following conditions are met AND **all features of the opcode are fully functional**:

1. **Complete implementation**: The opcode itself is fully implemented with all required functionality
2. **All dependencies working**: All supporting functionality required by the opcode is fully implemented
3. **Comprehensive testing**: The test covers all relevant cases for the opcode
4. **No known issues**: There are no TODO comments, FIXME notes, or documentation indicating missing/incomplete functionality
5. **All tests passing**: All primary tests for the opcode pass validation
6. **Edge cases handled**: Common edge cases are tested and handled correctly
7. **Documentation complete**: The opcode's behavior is properly documented
8. **All features functional**: Every feature of the opcode works correctly, including graphics-related features if applicable

### Criteria for `fully_implemented_no_graphics: true`

Set `fully_implemented_no_graphics` to **`true`** when the opcode is as fully functional as it can be specifically in NO_GRAPHICS mode, but would require graphics support to be fully functional:

1. **All non-graphics features working**: All features that don't require graphics are fully implemented
2. **NO_GRAPHICS mode complete**: The opcode works correctly in console-only mode
3. **Graphics-only limitations**: The only missing functionality requires graphics rendering (SDL3/Vulkan)
4. **Would be fully_implemented with graphics**: If graphics support were added, the opcode would meet all `fully_implemented` criteria

**Note**: If an opcode doesn't require graphics at all, only set `fully_implemented` (not `fully_implemented_no_graphics`).

### Tracking Missing Features with `missing_features`

For opcodes that don't qualify as `fully_implemented`, add a `missing_features` field to `test_info.json` with a point-form list of what features are still missing:

```json
{
  "metadata": {
    "name": "opcode_name_swf_N",
    "fully_implemented": false,
    "fully_implemented_no_graphics": false,
    "missing_features": [
      "Prototype chain support not implemented",
      "Property enumeration incomplete",
      "Edge case: NaN handling in string conversion",
      "Test coverage: missing boundary value tests"
    ]
  }
}
```

This list should include **all** missing features, even trivial ones like missing edge cases in tests. Be comprehensive and specific.

### Why an Opcode Might Be Incomplete

Common reasons an opcode is marked `fully_implemented: false`:

- **Missing supporting features**: The opcode requires object properties, array support, or other features not yet implemented
- **Partial implementation**: Core functionality works but edge cases or advanced features are missing
- **Test coverage gaps**: Tests exist but don't cover all relevant scenarios
- **Known bugs**: Implementation has documented issues or TODOs
- **Dependency issues**: Related opcodes or runtime features are incomplete
- **Incomplete validation**: Tests pass but validation doesn't verify all behavior

## Quick Start: Assessing What's Missing

Before implementing anything, you need to understand what's incomplete:

```bash
# 1. Navigate to the test directory
cd SWFRecomp/tests/<test_name>

# 2. Check the test_info.json to see why it's marked incomplete
cat test_info.json | grep -A 5 "fully_implemented"

# 3. Look for TODO/FIXME comments in the implementation
grep -r "TODO\|FIXME" ../../SWFModernRuntime/src/actionmodern/action.c | grep -i <opcode>

# 4. Check if all tests are passing
cd ..
./all_tests.sh <test_name>

# 5. Review the opcode specification
grep -A 30 "Action<OpcodeName>" ../SWFRecompDocs/specs/swf-spec-19.txt
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

## Common Completion Categories

### Category 1: Missing Supporting Features

**Symptom**: Core opcode works but depends on unimplemented features.

**Example**:
- `InitObject` works for simple cases but doesn't support nested objects
- `GetMember` works but property inheritance isn't implemented
- `Enumerate` works but doesn't handle prototype chain

**Completion Steps**:

1. **Identify required features**:
   ```bash
   # Check the specification for all capabilities
   grep -A 50 "Action<OpcodeName>" SWFRecompDocs/specs/swf-spec-19.txt
   ```

2. **List missing features**:
   - Create a checklist of all features mentioned in the spec
   - Mark which ones are implemented
   - Identify dependencies on other opcodes/features

3. **Implement missing features systematically**:
   - Start with the most fundamental missing feature
   - Test after each addition
   - Update tests to cover new functionality

4. **Verify against specification**:
   - Ensure all specified behavior is implemented
   - Test edge cases mentioned in spec
   - Verify interaction with related opcodes

**Example - Completing Object Support**:

```c
// Before: Basic object creation only
ASObject* allocObject(u32 num_properties) {
    ASObject* obj = malloc(sizeof(ASObject));
    obj->refcount = 1;
    obj->num_properties = num_properties;
    // TODO: Add prototype support
    // TODO: Add property enumeration
    return obj;
}

// After: Full object support
ASObject* allocObject(u32 num_properties) {
    ASObject* obj = malloc(sizeof(ASObject) + num_properties * sizeof(ASProperty));
    obj->refcount = 1;
    obj->num_properties = num_properties;
    obj->prototype = NULL;  // Now supports prototypes
    obj->properties = (ASProperty*)(obj + 1);  // Properties array

    // Initialize properties
    for (u32 i = 0; i < num_properties; i++) {
        obj->properties[i].name = NULL;
        obj->properties[i].value.type = ACTION_STACK_VALUE_UNDEFINED;
    }

    return obj;
}
```

### Category 2: Incomplete Test Coverage

**Symptom**: Tests pass but don't cover all scenarios.

**Completion Steps**:

1. **Review specification for all cases**:
   - What types can the opcode accept?
   - What edge cases are mentioned?
   - What error conditions exist?

2. **Identify missing test cases**:
   - Type conversions (string to number, number to string, etc.)
   - Null/undefined handling
   - Empty values (empty strings, zero, etc.)
   - Boundary conditions (max/min values, overflow, etc.)
   - Special values (NaN, Infinity, etc.)

3. **Create comprehensive tests**:
   ```bash
   cd SWFRecomp/tests/<test_name>

   # Create additional test files for edge cases
   # Option 1: Extend existing test
   nano create_test_swf.py  # Add more test cases

   # Option 2: Create new test directory for edge cases
   cd ..
   mkdir <test_name>_edge_cases_swf_N
   # Follow test creation process
   ```

4. **Update validation**:
   ```python
   # In validate.py - test all cases
   def validate_output(output):
       lines = parse_output(output)
       results = []

       # Basic case
       results.append(make_result("basic", lines[0] == "42", "42", lines[0]))

       # Type conversion
       results.append(make_result("string_to_num", lines[1] == "123", "123", lines[1]))

       # Null handling
       results.append(make_result("null_case", lines[2] == "0", "0", lines[2]))

       # Edge case
       results.append(make_result("max_value", lines[3] == "inf", "inf", lines[3]))

       return make_validation_result(results)
   ```

**Test Case Checklist**:

- [ ] Basic functionality (happy path)
- [ ] Type conversions (all relevant type combinations)
- [ ] Null and undefined values
- [ ] Empty values (empty string, zero, etc.)
- [ ] Boundary values (max/min integers, very large/small floats)
- [ ] Special float values (NaN, Infinity, -Infinity)
- [ ] String edge cases (very long strings, special characters, empty string)
- [ ] Array edge cases (empty array, single element, many elements)
- [ ] Object edge cases (no properties, many properties, nested objects)
- [ ] Error conditions (division by zero, invalid operations, etc.)

### Category 3: Unhandled Edge Cases

**Symptom**: Implementation exists but crashes or produces wrong results for edge cases.

**Completion Steps**:

1. **Identify common edge cases from specification**:
   ```bash
   grep -A 30 "Action<OpcodeName>" SWFRecompDocs/specs/swf-spec-19.txt
   ```

2. **Test edge cases manually**:
   ```actionscript
   // Create test ActionScript with edge cases
   trace(yourOperation(null));
   trace(yourOperation(undefined));
   trace(yourOperation(""));
   trace(yourOperation(0));
   trace(yourOperation(NaN));
   trace(yourOperation(Infinity));
   ```

3. **Add edge case handling**:

**Division by Zero**:
```c
void actionDivide(char* stack, u32* sp) {
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    float result;
    if (a.value.f32 == 0.0f) {
        // Flash returns Infinity for division by zero
        result = (b.value.f32 >= 0) ? INFINITY : -INFINITY;
    } else {
        result = b.value.f32 / a.value.f32;
    }

    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

**Null/Undefined Handling**:
```c
void actionStringLength(char* stack, u32* sp) {
    ActionVar a;
    peekVar(stack, sp, &a);

    float length;
    if (a.type == ACTION_STACK_VALUE_UNDEFINED || a.type == ACTION_STACK_VALUE_NULL) {
        // Null/undefined has length 0 in Flash
        length = 0.0f;
    } else {
        const char* str = (const char*) VAL(u64, &STACK_TOP_VALUE);
        if (str == NULL) {
            length = 0.0f;
        } else {
            length = (float)strlen(str);
        }
    }

    POP();
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &length));
}
```

**String Buffer Safety**:
```c
void actionStringOperation(char* stack, u32* sp, char* str_buffer) {
    const char* input = (const char*) VAL(u64, &STACK_TOP_VALUE);

    // Always check for null
    if (input == NULL) {
        input = "";
    }

    // Use safe string functions with size limits
    size_t buffer_size = 256;  // Or whatever your buffer size is
    snprintf(str_buffer, buffer_size, "%s", processed_string);

    // Ensure null termination
    str_buffer[buffer_size - 1] = '\0';

    POP();
    PUSH_STR(str_buffer, strlen(str_buffer));
}
```

### Category 4: Missing Documentation

**Symptom**: Code works but behavior isn't documented.

**Completion Steps**:

1. **Add function-level documentation**:
```c
/**
 * ActionModulo - Computes modulo (remainder) of two numbers
 *
 * Stack: [ value1, value2 ] -> [ value1 % value2 ]
 *
 * Pops two values from stack, converts both to numbers, computes
 * value1 % value2, and pushes the result.
 *
 * Edge cases:
 * - Division by zero: Returns NaN (following JavaScript behavior)
 * - Negative operands: Follows C fmod() semantics
 * - String operands: Converted to numbers before operation
 * - Null/undefined: Treated as 0
 *
 * SWF version: 4+
 * Opcode: 0x3F
 */
void actionModulo(char* stack, u32* sp) {
    // Implementation...
}
```

2. **Update test_info.json with comprehensive metadata**:
```json
{
  "metadata": {
    "name": "modulo_swf_4",
    "description": "Tests MODULO opcode (0x3F) - computes remainder of division with proper handling of edge cases including division by zero, negative numbers, and type conversions",
    "swf_version": 4,
    "fully_implemented": true
  },
  "opcodes": {
    "tested": ["MODULO"],
    "supporting": ["PUSH", "TRACE"]
  },
  "execution": {
    "type": "deterministic"
  },
  "edge_cases_tested": [
    "basic_modulo",
    "division_by_zero",
    "negative_operands",
    "string_to_number_conversion",
    "null_and_undefined"
  ]
}
```

3. **Add inline comments for non-obvious behavior**:
```c
void actionModulo(char* stack, u32* sp) {
    // Pop operands in reverse order (stack: [b, a] -> compute b % a)
    convertFloat(stack, sp);
    ActionVar a;
    popVar(stack, sp, &a);

    convertFloat(stack, sp);
    ActionVar b;
    popVar(stack, sp, &b);

    // Use fmodf for float modulo (NOT integer %)
    // This matches ActionScript behavior for fractional values
    float result = fmodf(b.value.f32, a.value.f32);

    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

### Category 5: TODO/FIXME Items

**Symptom**: Code contains TODO or FIXME comments indicating incomplete work.

**Completion Steps**:

1. **Find all TODOs**:
```bash
# Search runtime implementation
grep -n "TODO\|FIXME" SWFModernRuntime/src/actionmodern/action.c | grep -i <opcode>

# Search recompiler translation
grep -n "TODO\|FIXME" SWFRecomp/src/action/action.cpp | grep -i <opcode>

# Search headers
grep -n "TODO\|FIXME" SWFModernRuntime/include/actionmodern/action.h | grep -i <opcode>
```

2. **Categorize each TODO**:
- **Critical**: Must be fixed for basic functionality
- **Enhancement**: Needed for full spec compliance
- **Optimization**: Can be addressed later
- **Documentation**: Needs clarification

3. **Resolve each TODO systematically**:

**Example - Completing a TODO**:

```c
// Before - with TODO
void actionGetMember(char* stack, u32* sp) {
    // Get property name
    const char* name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // Get object
    ASObject* obj = (ASObject*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // TODO: Add prototype chain lookup
    // TODO: Handle undefined property

    // Simple property lookup
    ASProperty* prop = findProperty(obj, name);
    pushVar(stack, sp, &prop->value);
}

// After - TODO resolved
void actionGetMember(char* stack, u32* sp) {
    // Get property name
    const char* name = (const char*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // Get object
    ASObject* obj = (ASObject*) VAL(u64, &STACK_TOP_VALUE);
    POP();

    // Look up property with prototype chain support
    ActionVar result;
    if (!getPropertyWithPrototype(obj, name, &result)) {
        // Property not found - push undefined
        result.type = ACTION_STACK_VALUE_UNDEFINED;
        result.value.u64 = 0;
    }

    pushVar(stack, sp, &result);
}
```

## The Complete-Implementation Workflow

### Step 1: Assess Current State

Document what's implemented and what's missing:

```bash
cd SWFRecomp/tests/<test_name>

# Check test status
cat test_info.json

# Run test to see if it passes
../../scripts/build_test.sh <test_name> native
./build/native/<test_name>

# Run validation
./build/native/<test_name> 2>&1 | \
  grep -v "SWF Runtime" | grep -v "===" | grep -v "\[Frame" | grep -v "\[Tag\]" | grep -v "^$" | \
  ./validate.py
```

**Create a checklist**:
- [ ] Core functionality implemented?
- [ ] All tests passing?
- [ ] Edge cases handled?
- [ ] TODO/FIXME items resolved?
- [ ] Supporting features available?
- [ ] Comprehensive test coverage?
- [ ] Documentation complete?

### Step 2: Review the Specification

Understand the complete expected behavior:

```bash
# Find the opcode in the specification
grep -A 50 "Action<OpcodeName>" SWFRecompDocs/specs/swf-spec-19.txt

# Note all mentioned behaviors:
# - Input types accepted
# - Output type produced
# - Stack effects
# - Edge cases
# - Version requirements
# - Related opcodes
```

**Create a specification checklist**:
- [ ] All input types handled
- [ ] Correct output type
- [ ] Stack properly balanced
- [ ] All edge cases from spec
- [ ] Version-specific behavior (if any)
- [ ] Interactions with related opcodes

### Step 3: Implement Missing Features

Work through missing features systematically:

1. **Prioritize by dependency**:
   - Core features first (others may depend on them)
   - Supporting infrastructure next
   - Edge cases and refinements last

2. **Implement incrementally**:
   - Add one feature at a time
   - Test after each addition
   - Don't move on until current feature works

3. **Follow existing patterns**:
   ```bash
   # Find similar opcodes that have the feature you need
   grep -A 30 "similar_opcode" SWFModernRuntime/src/actionmodern/action.c
   ```

**Implementation Patterns**:

**Type Handling**:
```c
void actionCompleteOp(char* stack, u32* sp) {
    ActionVar a;
    peekVar(stack, sp, &a);

    // Handle all types appropriately
    switch (a.type) {
        case ACTION_STACK_VALUE_F32:
            // Handle float
            break;
        case ACTION_STACK_VALUE_STRING:
            // Handle string
            break;
        case ACTION_STACK_VALUE_UNDEFINED:
        case ACTION_STACK_VALUE_NULL:
            // Handle null/undefined
            break;
        case ACTION_STACK_VALUE_OBJECT:
            // Handle object
            break;
        default:
            // Unknown type - handle gracefully
            break;
    }
}
```

**Error Handling**:
```c
void actionSafeOperation(char* stack, u32* sp) {
    // Check for valid input
    if (*sp == 0 || stack == NULL) {
        // Stack underflow - push safe default
        float zero = 0.0f;
        PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &zero));
        return;
    }

    // Proceed with operation...
}
```

### Step 4: Add Comprehensive Tests

Ensure all functionality is tested:

1. **Review existing tests**:
   ```bash
   cat create_test_swf.py  # or check test.swf
   cat validate.py
   ```

2. **Identify gaps in coverage**:
   - What scenarios aren't tested?
   - What types aren't tested?
   - What edge cases aren't tested?

3. **Add missing tests**:

**Option A: Extend existing test**:
```python
# In create_test_swf.py - add more cases
def create_test_swf():
    # Existing tests...

    # Add new test cases
    # Test null handling
    action_push_null = ...
    action_your_opcode = ...
    action_trace = ...

    # Test undefined
    action_push_undefined = ...
    action_your_opcode = ...
    action_trace = ...

    # Test edge case
    action_push_edge = ...
    action_your_opcode = ...
    action_trace = ...
```

**Option B: Create additional test directory**:
```bash
cd SWFRecomp/tests
mkdir <opcode>_comprehensive_swf_N
# Copy templates and create comprehensive test suite
```

4. **Update validation to check all cases**:
```python
def validate_output(output):
    lines = parse_output(output)
    results = []

    # Test each case
    test_cases = [
        ("basic_operation", "42", 0),
        ("null_handling", "0", 1),
        ("undefined_handling", "NaN", 2),
        ("edge_case", "Infinity", 3),
        ("type_conversion", "123", 4),
    ]

    for name, expected, line_idx in test_cases:
        actual = lines[line_idx] if line_idx < len(lines) else ""
        results.append(make_result(name, actual == expected, expected, actual))

    return make_validation_result(results)
```

### Step 5: Resolve All TODOs

Clean up all incomplete work markers:

1. **List all TODOs**:
   ```bash
   grep -rn "TODO\|FIXME" SWFModernRuntime/src/actionmodern/action.c | grep -i <opcode>
   ```

2. **For each TODO**:
   - Understand what's needed
   - Implement the missing functionality
   - Test the implementation
   - Remove the TODO comment
   - Add documentation if needed

3. **Verify no TODOs remain**:
   ```bash
   # Should return nothing
   grep -i "TODO\|FIXME" SWFModernRuntime/src/actionmodern/action.c | grep -i <opcode>
   ```

### Step 6: Add Documentation

Document the complete implementation:

1. **Function-level documentation**:
```c
/**
 * Action<OpcodeName> - <Brief description>
 *
 * Stack effects: <What it pops and pushes>
 *
 * <Detailed description of behavior>
 *
 * Edge cases handled:
 * - <Edge case 1>
 * - <Edge case 2>
 *
 * Type conversions:
 * - <Conversion 1>
 * - <Conversion 2>
 *
 * SWF version: <Version>
 * Opcode: <Hex value>
 *
 * @param stack Pointer to the runtime stack
 * @param sp Pointer to stack pointer
 */
```

2. **Update test_info.json**:
```json
{
  "metadata": {
    "name": "opcode_name_swf_N",
    "description": "Comprehensive description including all tested features and edge cases",
    "swf_version": N,
    "fully_implemented": true
  },
  "opcodes": {
    "tested": ["OPCODE_NAME"],
    "supporting": ["SUPPORTING_OP1", "SUPPORTING_OP2"]
  },
  "execution": {
    "type": "deterministic"
  },
  "edge_cases_tested": [
    "list_of_all",
    "edge_cases",
    "covered_by_tests"
  ]
}
```

3. **Add inline comments for complex logic**:
```c
// Use fmodf instead of % operator to handle floating point correctly
// This matches Flash's behavior for fractional modulo operations
float result = fmodf(b.value.f32, a.value.f32);
```

### Step 7: Verify Full Test Suite

Ensure your changes don't break anything:

```bash
# Run all tests
cd SWFRecomp/tests
./all_tests.sh

# Look for any failures
# All tests should pass before marking fully_implemented: true
```

### Step 8: Mark as Fully Implemented

Once everything is complete:

1. **Final checklist**:
- [ ] All core functionality implemented
- [ ] All supporting features available
- [ ] All tests passing
- [ ] Comprehensive test coverage
- [ ] All edge cases handled
- [ ] No TODO/FIXME comments
- [ ] Complete documentation
- [ ] Full test suite still passes

2. **Update test_info.json**:
```json
{
  "metadata": {
    "fully_implemented": true
  }
}
```

   If the opcode is complete in NO_GRAPHICS mode but would need graphics for full functionality:
```json
{
  "metadata": {
    "fully_implemented": false,
    "fully_implemented_no_graphics": true,
    "missing_features": [
      "Graphics rendering not implemented (requires SDL3/Vulkan)"
    ]
  }
}
```

3. **Rebuild opcode index**:
```bash
# If there's a script to rebuild the index
python3 scripts/update-opcode-index.py
```

## Stack-Based Execution Model

Understanding the stack model is critical for complete implementations:

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

## Common Implementation Patterns

### Complete Type Conversion

```c
void actionWithCompleteTypeHandling(char* stack, u32* sp) {
    ActionVar a;
    peekVar(stack, sp, &a);

    float num_value;
    switch (a.type) {
        case ACTION_STACK_VALUE_F32:
            num_value = a.value.f32;
            break;

        case ACTION_STACK_VALUE_I32:
            num_value = (float)a.value.i32;
            break;

        case ACTION_STACK_VALUE_STRING: {
            const char* str = (const char*)a.value.u64;
            if (str == NULL || *str == '\0') {
                num_value = 0.0f;  // Empty string -> 0
            } else {
                num_value = (float)atof(str);  // Parse number
            }
            break;
        }

        case ACTION_STACK_VALUE_UNDEFINED:
        case ACTION_STACK_VALUE_NULL:
            num_value = 0.0f;  // null/undefined -> 0
            break;

        case ACTION_STACK_VALUE_BOOLEAN:
            num_value = a.value.boolean ? 1.0f : 0.0f;
            break;

        default:
            num_value = 0.0f;  // Unknown -> 0
            break;
    }

    // Use num_value...
}
```

### Complete Error Handling

```c
void actionWithCompleteErrorHandling(char* stack, u32* sp) {
    // Check for stack underflow
    if (*sp == 0) {
        // Push safe default
        float zero = 0.0f;
        PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &zero));
        return;
    }

    // Check for null stack
    if (stack == NULL) {
        return;  // Fail silently or log error
    }

    // Get value safely
    ActionVar a;
    popVar(stack, sp, &a);

    // Check for null pointers if using strings/objects
    if (a.type == ACTION_STACK_VALUE_STRING) {
        const char* str = (const char*)a.value.u64;
        if (str == NULL) {
            str = "";  // Use empty string instead
        }
        // Proceed with str...
    }

    // Handle division by zero
    if (operation_is_division && divisor == 0.0f) {
        result = (dividend >= 0) ? INFINITY : -INFINITY;
    }

    // Handle NaN propagation
    if (isnan(operand)) {
        result = NAN;
    }

    // Ensure result is pushed even on error path
    PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &result));
}
```

### Complete Object Implementation

```c
/**
 * Complete object implementation with all features:
 * - Reference counting
 * - Property storage
 * - Prototype chain
 * - Property enumeration
 */

typedef struct ASProperty {
    char* name;
    ActionVar value;
    struct ASProperty* next;  // For hash collision chain
} ASProperty;

typedef struct ASObject {
    u32 refcount;
    struct ASObject* prototype;
    u32 property_count;
    u32 property_capacity;
    ASProperty** property_table;  // Hash table
} ASObject;

// Allocate object with hash table
ASObject* allocObject() {
    ASObject* obj = malloc(sizeof(ASObject));
    obj->refcount = 1;
    obj->prototype = NULL;
    obj->property_count = 0;
    obj->property_capacity = 16;  // Initial capacity
    obj->property_table = calloc(16, sizeof(ASProperty*));
    return obj;
}

// Set property with hash table
void setProperty(ASObject* obj, const char* name, ActionVar* value) {
    u32 hash = hashString(name) % obj->property_capacity;

    // Look for existing property
    ASProperty* prop = obj->property_table[hash];
    while (prop != NULL) {
        if (strcmp(prop->name, name) == 0) {
            // Update existing
            releaseValue(&prop->value);
            prop->value = *value;
            retainValue(value);
            return;
        }
        prop = prop->next;
    }

    // Create new property
    ASProperty* new_prop = malloc(sizeof(ASProperty));
    new_prop->name = strdup(name);
    new_prop->value = *value;
    retainValue(value);
    new_prop->next = obj->property_table[hash];
    obj->property_table[hash] = new_prop;
    obj->property_count++;

    // Resize if needed
    if (obj->property_count > obj->property_capacity * 0.75) {
        resizePropertyTable(obj);
    }
}

// Get property with prototype chain
bool getPropertyWithPrototype(ASObject* obj, const char* name, ActionVar* out) {
    ASObject* current = obj;

    // Walk prototype chain
    while (current != NULL) {
        u32 hash = hashString(name) % current->property_capacity;
        ASProperty* prop = current->property_table[hash];

        while (prop != NULL) {
            if (strcmp(prop->name, name) == 0) {
                *out = prop->value;
                return true;
            }
            prop = prop->next;
        }

        current = current->prototype;
    }

    return false;  // Not found
}
```

## Specification Reference

Always implement according to the official specification:

```bash
# Look up opcode details
grep -A 50 "Action<OpcodeName>" SWFRecompDocs/specs/swf-spec-19.txt

# Check version requirements
grep -B 5 "Action<OpcodeName>" SWFRecompDocs/specs/swf-spec-19.txt | grep "since"
```

**Key specification sections**:
- Opcode description and purpose
- Stack effects (before/after)
- Type handling and conversions
- Edge cases and error conditions
- SWF version introduced
- Related opcodes

## Success Criteria

An opcode implementation is fully complete when:

1. ✅ All functionality from specification implemented
2. ✅ All supporting features available
3. ✅ All tests passing (100% pass rate)
4. ✅ Comprehensive test coverage (all types, edge cases)
5. ✅ All TODOs resolved
6. ✅ Complete documentation
7. ✅ Edge cases handled correctly
8. ✅ Full test suite still passes (no regressions)
9. ✅ test_info.json updated with fully_implemented: true
10. ✅ Code review checklist complete

## Summary Checklist

When completing an opcode implementation, follow this checklist:

**Implementation**:
- [ ] All specification requirements implemented
- [ ] All supporting features available
- [ ] All TODO/FIXME items resolved
- [ ] Edge cases handled (null, undefined, NaN, Infinity, etc.)
- [ ] Type conversions complete (all types supported)
- [ ] Error handling robust (no crashes on invalid input)
- [ ] Stack operations correct and balanced

**Testing**:
- [ ] All existing tests passing
- [ ] Basic functionality tested
- [ ] All input types tested
- [ ] Edge cases tested
- [ ] Boundary conditions tested
- [ ] Error conditions tested
- [ ] Integration with related opcodes tested
- [ ] Validation scripts comprehensive

**Documentation**:
- [ ] Function-level documentation complete
- [ ] Inline comments for complex logic
- [ ] test_info.json updated with full description
- [ ] edge_cases_tested list complete
- [ ] fully_implemented set to true

**Quality**:
- [ ] No compiler warnings
- [ ] No memory leaks (if using dynamic allocation)
- [ ] Follows existing code patterns
- [ ] Full test suite passes (no regressions)
- [ ] Code reviewed against specification

## Getting Help

If you're stuck:

1. **Check similar opcodes** - Look at fully implemented opcodes of similar complexity
2. **Read the spec carefully** - The answer is usually there
3. **Test incrementally** - Add features one at a time
4. **Check git history** - See how other opcodes were completed
5. **Review related opcodes** - They may share infrastructure

## Key Resources

**Specifications**:
- `SWFRecompDocs/specs/swf-spec-19.txt` - Complete SWF v4+ specification

**Implementation Examples** (Fully Implemented):
- Look for tests with `"fully_implemented": true` in test_info.json
- `SWFRecomp/tests/modulo_swf_4/` - Complete arithmetic operation
- `SWFRecomp/tests/trace_swf_4/` - Complete simple operation

**Build and Test**:
- `SWFRecomp/scripts/build_test.sh` - Automated build script
- `SWFRecomp/tests/all_tests.sh` - Full test suite runner
- `SWFModernRuntime/src/actionmodern/action.c` - Runtime implementations

**For new implementations**, use `parallel-opcode-implementation-guide.md` instead.
**For fixing failing tests**, use `failing-test-fix-guide.md` instead.
