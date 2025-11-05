# AS2 Opcode Implementation Categorization

**Date Created**: 2025-11-05
**Status**: Ready for Parallel Implementation
**Total Implemented**: 27 opcodes
**Remaining**: ~60+ opcodes

This document categorizes all AS2 opcodes by implementation complexity to facilitate parallel opcode implementation.

## Currently Implemented Opcodes (27 total)

| Hex | Name | Category | Status |
|-----|------|----------|--------|
| 0x00 | END_OF_ACTIONS | Control | ✅ Implemented |
| 0x07 | STOP | Control | ✅ Implemented |
| 0x0A | ADD | Arithmetic | ✅ Implemented |
| 0x0B | SUBTRACT | Arithmetic | ✅ Implemented |
| 0x0C | MULTIPLY | Arithmetic | ✅ Implemented |
| 0x0D | DIVIDE | Arithmetic | ✅ Implemented |
| 0x0E | EQUALS | Comparison | ✅ Implemented |
| 0x0F | LESS | Comparison | ✅ Implemented |
| 0x10 | AND | Logic | ✅ Implemented |
| 0x11 | OR | Logic | ✅ Implemented |
| 0x12 | NOT | Logic | ✅ Implemented |
| 0x13 | STRING_EQUALS | String | ✅ Implemented |
| 0x14 | STRING_LENGTH | String | ✅ Implemented |
| 0x17 | POP | Stack | ✅ Implemented |
| 0x1C | GET_VARIABLE | Variables | ✅ Implemented |
| 0x1D | SET_VARIABLE | Variables | ✅ Implemented |
| 0x21 | STRING_ADD | String | ✅ Implemented |
| 0x26 | TRACE | Debug | ✅ Implemented |
| 0x34 | GET_TIME | Special | ✅ Implemented |
| 0x3F | MODULO | Arithmetic | ✅ Implemented (Exp #2) |
| 0x50 | INCREMENT | Arithmetic | ✅ Implemented (Exp #5) |
| 0x51 | DECREMENT | Arithmetic | ✅ Implemented (Exp #5) |
| 0x88 | CONSTANT_POOL | Special | ✅ Implemented |
| 0x96 | PUSH | Stack | ✅ Implemented |
| 0x99 | JUMP | Control | ✅ Implemented |
| 0x9D | IF | Control | ✅ Implemented |

---

## Simple Opcodes (1-2 hours each)

### Priority 1: Comparison Operations
These are binary comparisons that return boolean values (0.0 or 1.0).

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x48 | GREATER | Greater than comparison (SWF 5+) | Binary comparison |
| 0x67 | GREATER_EQUALS | Greater than or equal (SWF 6+) | Binary comparison |
| 0x68 | LESS_EQUALS | Less than or equal (SWF 6+) | Binary comparison |
| 0x66 | STRICT_EQUALS | Strict equality (no type coercion) | Binary comparison |

**Estimated Time**: 1-2 hours each
**Reference**: `actionEquals`, `actionLess` in `action.c`
**Test Cases**: Basic comparisons, edge cases with different types
**Complexity Factors**:
- Simple stack operations (pop, compare, push)
- Type conversion handling
- Boolean result (0.0 or 1.0)

---

### Priority 2: Bitwise Operations
These perform bitwise operations on integers.

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x60 | BIT_AND | Bitwise AND | Binary bitwise |
| 0x61 | BIT_OR | Bitwise OR | Binary bitwise |
| 0x62 | BIT_XOR | Bitwise XOR | Binary bitwise |
| 0x63 | BIT_LSHIFT | Bitwise left shift | Binary bitwise |
| 0x64 | BIT_RSHIFT | Bitwise right shift (signed) | Binary bitwise |
| 0x65 | BIT_URSHIFT | Bitwise unsigned right shift | Binary bitwise |

**Estimated Time**: 1-2 hours each
**Reference**: `actionAnd`, `actionOr` in `action.c` (but need integer conversion)
**Test Cases**: Basic bitwise ops, shift operations, edge cases
**Complexity Factors**:
- Convert to 32-bit integer
- Perform bitwise operation
- Push integer result

---

### Priority 3: Type Conversion Operations
These convert values between types.

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x18 | TO_INTEGER | Convert to integer | Unary conversion |
| 0x4A | TO_NUMBER | Convert to number | Unary conversion |
| 0x4B | TO_STRING | Convert to string | Unary conversion |

**Estimated Time**: 1-2 hours each
**Reference**: `convertFloat`, `convertString` utilities in `action.c`
**Test Cases**: Various type conversions, null/undefined handling
**Complexity Factors**:
- Type detection
- Conversion logic
- Result formatting

---

## Medium Opcodes (2-4 hours each)

### Priority 4: String Manipulation
These perform more complex string operations.

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x31 | CHAR_TO_ASCII | Convert character to ASCII code | String to number |
| 0x32 | ASCII_TO_CHAR | Convert ASCII code to character | Number to string |
| 0x33 | MB_CHAR_TO_ASCII | Multibyte char to ASCII | String to number |
| 0x34 | MB_ASCII_TO_CHAR | ASCII to multibyte char | Number to string |
| 0x35 | MB_STRING_LENGTH | Multibyte string length | String property |
| 0x15 | STRING_EXTRACT | Extract substring | String operation |
| 0x29 | STRING_LESS | String comparison | Binary comparison |

**Estimated Time**: 2-4 hours each
**Reference**: `actionStringLength`, `actionStringAdd` in `action.c`
**Test Cases**: ASCII range, Unicode, empty strings, bounds checking
**Complexity Factors**:
- Character encoding handling
- String buffer management
- Multibyte character support

---

### Priority 5: Stack Manipulation
These perform non-trivial stack operations.

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x3D | DUPLICATE | Duplicate top stack value | Stack copy |
| 0x4C | STACK_SWAP | Swap top two stack values | Stack reorder |
| 0x4D | RANDOM_NUMBER | Generate random number | Special |

**Estimated Time**: 2-4 hours each
**Reference**: `PUSH`, `POP` macros in `action.h`
**Test Cases**: Stack state verification, edge cases
**Complexity Factors**:
- Careful stack pointer management
- Type preservation
- Memory management for objects

---

### Priority 6: Utility Operations
These provide useful functionality with moderate complexity.

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x3C | TYPEOF | Get type of value | Type query |
| 0x30 | RANDOM_NUMBER | Random number (old version) | Special |
| 0x45 | TARGET_PATH | Get target path | Special |

**Estimated Time**: 2-4 hours each
**Reference**: Various utilities in `action.c`
**Test Cases**: Different types, null/undefined handling
**Complexity Factors**:
- Type system interaction
- String formatting
- Special cases

---

## Complex Opcodes (4-8 hours each)

### Priority 7: Object Operations (Requires Object Model)
These work with ActionScript objects using the validated object model from Experiment #4.

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x42 | INIT_ARRAY | Create new array | Object creation |
| 0x43 | INIT_OBJECT | Create new object | Object creation |
| 0x4E | GET_MEMBER | Get object property | Property access |
| 0x4F | SET_MEMBER | Set object property | Property mutation |
| 0x22 | GET_PROPERTY | Get property by index | Property access |
| 0x23 | SET_PROPERTY | Set property by index | Property mutation |
| 0x55 | ENUMERATE | Enumerate properties | Iterator |
| 0x46 | ENUMERATE2 | Enumerate properties (v2) | Iterator |
| 0x5A | DELETE | Delete property | Property mutation |
| 0x5B | DELETE2 | Delete property (v2) | Property mutation |

**Estimated Time**: 4-8 hours each
**Reference**: Object model from Experiment #4 (in `object.c`, `object.h`)
**Test Cases**: Object creation, property access, nested objects, deletion
**Complexity Factors**:
- Object allocation and reference counting
- Property storage and lookup
- Memory management
- Iterator state management (for ENUMERATE)

**Note**: Object model is production-ready (validated in Experiment #4, 0 memory leaks).

---

### Priority 8: Function Operations
These handle function calls and returns.

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x3E | RETURN | Return from function | Control flow |
| 0x9E | CALL_FUNCTION | Call a function | Function invocation |
| 0x9F | CALL_METHOD | Call a method | Method invocation |
| 0x52 | CALL | Call function (old) | Function invocation |
| 0x40 | NEW_OBJECT | Create object via constructor | Constructor |
| 0x53 | NEW_METHOD | Create via method constructor | Constructor |

**Estimated Time**: 4-8 hours each
**Reference**: Control flow opcodes in `action.cpp`, `action.c`
**Test Cases**: Simple calls, nested calls, return values, this binding
**Complexity Factors**:
- Call stack management
- Scope handling
- Argument passing
- Return value handling

---

### Priority 9: Control Flow (Advanced)
These handle more complex control flow patterns.

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x9B | DEFINE_FUNCTION | Define a function | Function definition |
| 0x8E | DEFINE_FUNCTION2 | Define function (enhanced) | Function definition |
| 0x94 | WITH | With block | Scope management |
| 0x87 | STORE_REGISTER | Store value in register | Register ops |
| 0x41 | DECLARE_LOCAL | Declare local variable | Scope management |

**Estimated Time**: 4-8 hours each
**Reference**: Control flow opcodes, variable storage
**Test Cases**: Function definition, scope chain, register usage
**Complexity Factors**:
- Function object creation
- Scope chain management
- Register allocation
- Closure support

---

### Priority 10: Advanced/Unsorted
These opcodes require special handling or are less commonly used.

| Hex | Name | Description | Pattern |
|-----|------|-------------|---------|
| 0x04 | NEXT_FRAME | Advance to next frame | Special |
| 0x05 | PREVIOUS_FRAME | Go to previous frame | Special |
| 0x06 | PLAY | Start playing | Special |
| 0x08 | TOGGLE_QUALITY | Toggle rendering quality | Special |
| 0x09 | STOP_SOUNDS | Stop all sounds | Special |
| 0x8A | WAIT_FOR_FRAME | Wait for frame to load | Special |
| 0x8B | SET_TARGET | Set action target | Special |
| 0x8C | GO_TO_LABEL | Go to labeled frame | Special |
| 0x8D | WAIT_FOR_FRAME2 | Wait for frame (v2) | Special |
| 0x20 | SET_TARGET2 | Set action target (v2) | Special |
| 0x24 | CLONE_SPRITE | Clone sprite | Special |
| 0x25 | REMOVE_SPRITE | Remove sprite | Special |
| 0x27 | START_DRAG | Start dragging | Special |
| 0x28 | END_DRAG | End dragging | Special |
| 0x8F | TRY | Try-catch-finally | Exception handling |
| 0x2A | THROW | Throw exception | Exception handling |
| 0x2B | CAST_OP | Cast operation | Type system |
| 0x2C | IMPLEMENTS_OP | Implements check | Type system |
| 0x36 | PUSH_DUPLICATE | Push duplicate | Stack |
| 0x37 | SWAP | Swap values | Stack |
| 0x3A | DELETE | Delete (old) | Property mutation |
| 0x3B | DELETE2 | Delete (old v2) | Property mutation |
| 0x44 | TO_OBJECT | Convert to object | Type conversion |
| 0x47 | ADD2 | Add (type-aware) | Arithmetic |
| 0x49 | LESS2 | Less than (type-aware) | Comparison |
| 0x54 | EXTENDS | Extends operation | Inheritance |
| 0x69 | STRICT_MODE | Enable strict mode | Special |

**Estimated Time**: 4-12 hours each (varies widely)
**Reference**: Various, depends on opcode
**Test Cases**: Highly dependent on specific opcode
**Complexity Factors**: Varies widely by opcode

---

## Implementation Priority Summary

### Immediate Implementation (Simple - Batch 1)
**Total**: 13 opcodes
**Estimated Time**: 15-25 hours with 10+ parallel agents

1. **Comparison** (4 opcodes): GREATER, GREATER_EQUALS, LESS_EQUALS, STRICT_EQUALS
2. **Bitwise** (6 opcodes): BIT_AND, BIT_OR, BIT_XOR, BIT_LSHIFT, BIT_RSHIFT, BIT_URSHIFT
3. **Type Conversion** (3 opcodes): TO_INTEGER, TO_NUMBER, TO_STRING

**Rationale**: Simple patterns, clear test cases, minimal dependencies

---

### Next Phase (Medium - Batch 2)
**Total**: 14 opcodes
**Estimated Time**: 30-55 hours with 10+ parallel agents

1. **String Operations** (7 opcodes): CHAR_TO_ASCII, ASCII_TO_CHAR, MB_* variants, STRING_EXTRACT, STRING_LESS
2. **Stack Operations** (3 opcodes): DUPLICATE, STACK_SWAP, RANDOM_NUMBER
3. **Utility** (3 opcodes): TYPEOF, RANDOM_NUMBER (old), TARGET_PATH

**Rationale**: Moderate complexity, some string handling, well-defined behavior

---

### Final Phase (Complex - Batch 3)
**Total**: 25+ opcodes
**Estimated Time**: 100-200 hours with multiple agents

1. **Object Operations** (10 opcodes): INIT_ARRAY, INIT_OBJECT, GET_MEMBER, SET_MEMBER, etc.
2. **Function Operations** (6 opcodes): RETURN, CALL_FUNCTION, CALL_METHOD, etc.
3. **Control Flow** (5 opcodes): DEFINE_FUNCTION, WITH, STORE_REGISTER, etc.
4. **Advanced** (25+ opcodes): Frame control, exception handling, etc.

**Rationale**: Complex dependencies, requires infrastructure (object model, call stack, etc.)

---

## Recommendations for Parallel Implementation

### Batch 1 Strategy (Immediate Start)
- **Target**: 13 simple opcodes
- **Agents**: 10-13 parallel instances
- **Coordination**: Minimal (independent implementations)
- **Timeline**: 1-2 days with proper coordination
- **Merge Strategy**: Sequential merges, 2 minutes per merge = ~25 minutes total

### Batch 2 Strategy (After Batch 1)
- **Target**: 14 medium opcodes
- **Agents**: 10-14 parallel instances
- **Coordination**: String buffer management conventions
- **Timeline**: 2-4 days
- **Dependencies**: Batch 1 complete, string utilities documented

### Batch 3 Strategy (Advanced)
- **Target**: 25+ complex opcodes
- **Agents**: Multiple waves, coordinated by category
- **Coordination**: High (shared infrastructure)
- **Timeline**: 1-2 weeks
- **Dependencies**: Object model validated, function infrastructure designed

---

## Quality Metrics

Each opcode implementation should meet these criteria:
- ✅ All 7 steps completed
- ✅ Test produces correct output
- ✅ No build errors or warnings
- ✅ Edge cases handled
- ✅ Documentation created
- ✅ Passes existing test suite

---

## Notes

- **Validated Infrastructure**: Object model validated in Experiment #4 (0 memory leaks)
- **Proven Workflow**: 7-step process validated in Experiment #2 (45 minutes for simple opcodes)
- **Merge Strategy**: Validated in Experiment #5 (2 minutes for 4 conflicts)
- **Build System**: Automated with auto-generation (2 seconds per build)

**Status**: Ready for large-scale parallel opcode implementation
**Confidence**: VERY HIGH based on successful validation experiments
