# SWFRecomp: Objects and Functions PR (v2 - Minimized)

## Branch: feature/objects-and-functions

## Summary

This PR adds compiler support for ActionScript 2.0 object and function operations. **Version 2 is minimized** to match the reduced runtime - opcodes not supported by the runtime now throw compile-time errors.

## Changes from v1

In v2, the following opcodes are **marked as unsupported** and will throw an error if encountered:
- Comparison Operations (Equals2, Less2, Greater, StrictEquals)
- Arithmetic Operations (Add2, Modulo, Increment, Decrement)
- Type Conversion (ToNumber, ToString)

This ensures SWF files using these opcodes fail at compile time rather than at runtime.

## Files Changed

| File | Insertions | Deletions | Description |
|------|------------|-----------|-------------|
| include/action/action.hpp | +36 | 0 | Added opcode enum values and class members |
| include/context.hpp | +2 | 0 | Added inside_function2 tracking flag |
| src/action/action.cpp | +143 | -298 | Opcode implementations (minimized) |

**Total: +181 insertions, -298 deletions**

## Detailed Changes

### include/action/action.hpp

**Added includes:**
- `#include <vector>` - for constant_pool member

**New enum values (SWFActionType):**

| Opcode | Value | Description |
|--------|-------|-------------|
| SWF_ACTION_DELETE | 0x3A | Delete object property |
| SWF_ACTION_DELETE2 | 0x3B | Delete variable |
| SWF_ACTION_DEFINE_LOCAL | 0x3C | Define local variable with value |
| SWF_ACTION_CALL_FUNCTION | 0x3D | Call a function |
| SWF_ACTION_RETURN | 0x3E | Return from function |
| SWF_ACTION_MODULO | 0x3F | Modulo operation (unsupported) |
| SWF_ACTION_NEW_OBJECT | 0x40 | Create new object |
| SWF_ACTION_DECLARE_LOCAL | 0x41 | Declare local variable |
| SWF_ACTION_INIT_ARRAY | 0x42 | Initialize array literal |
| SWF_ACTION_INIT_OBJECT | 0x43 | Initialize object literal |
| SWF_ACTION_TYPEOF | 0x44 | Get type of value |
| SWF_ACTION_ENUMERATE | 0x46 | Enumerate object properties |
| SWF_ACTION_ADD2 | 0x47 | Add (unsupported) |
| SWF_ACTION_LESS2 | 0x48 | Less than (unsupported) |
| SWF_ACTION_EQUALS2 | 0x49 | Equals (unsupported) |
| SWF_ACTION_TO_NUMBER | 0x4A | Convert to number (unsupported) |
| SWF_ACTION_TO_STRING | 0x4B | Convert to string (unsupported) |
| SWF_ACTION_DUPLICATE | 0x4C | Duplicate stack top |
| SWF_ACTION_STACK_SWAP | 0x4D | Swap top two stack values |
| SWF_ACTION_GET_MEMBER | 0x4E | Get object member |
| SWF_ACTION_SET_MEMBER | 0x4F | Set object member |
| SWF_ACTION_INCREMENT | 0x50 | Increment value (unsupported) |
| SWF_ACTION_DECREMENT | 0x51 | Decrement value (unsupported) |
| SWF_ACTION_CALL_METHOD | 0x52 | Call object method |
| SWF_ACTION_NEW_METHOD | 0x53 | Call constructor as method |
| SWF_ACTION_INSTANCEOF | 0x54 | Check instance of class |
| SWF_ACTION_ENUMERATE2 | 0x55 | Enumerate (AS2 style) |
| SWF_ACTION_STRICT_EQUALS | 0x66 | Strict equality (unsupported) |
| SWF_ACTION_GREATER | 0x67 | Greater than (unsupported) |
| SWF_ACTION_EXTENDS | 0x69 | Class extends |
| SWF_ACTION_STORE_REGISTER | 0x87 | Store to register |
| SWF_ACTION_DEFINE_FUNCTION2 | 0x8E | Define function (AS2) |
| SWF_ACTION_DEFINE_FUNCTION | 0x9B | Define function (AS1) |

**New class members (SWFAction):**
- `size_t func_counter` - Counter for generating unique function names
- `std::vector<size_t> constant_pool` - Maps constant pool index to string ID

### include/context.hpp

**New struct member (Context):**
- `bool inside_function2 = false` - Tracks if parser is inside a DefineFunction2 body (for register handling)

### src/action/action.cpp

**Constructor update:**
- Added `func_counter(0)` to initializer list

**Supported opcode implementations:**
The following opcodes generate runtime function calls:

- **DefineFunction/DefineFunction2**: Parse function metadata, parameters, and recursively parse function body
- **CallFunction/CallMethod**: Generate runtime function/method call code
- **NewObject/NewMethod**: Generate object instantiation code
- **InitArray/InitObject**: Generate array/object literal initialization
- **GetMember/SetMember**: Generate property access code
- **Return**: Generate early return with optional value
- **Delete/Delete2**: Generate property/variable deletion
- **Typeof**: Generate type query
- **Enumerate/Enumerate2**: Generate property enumeration
- **Extends/InstanceOf**: Generate inheritance operations
- **DefineLocal/DeclareLocal**: Generate local variable declarations
- **Duplicate/StackSwap**: Generate stack manipulation
- **StoreRegister**: Generate register store operations

**Unsupported opcodes (throw compile error):**
The following opcodes will cause compilation to fail with an error message:

```cpp
// REMOVED OPCODE: Add2 - not supported in minimal build
case SWF_ACTION_ADD2:
// REMOVED OPCODE: Less2 - not supported in minimal build
case SWF_ACTION_LESS2:
// ... etc
{
    EXC_ARG("Opcode 0x%02X not supported in minimal build (objects/functions only)\n", code);
    break;
}
```

## Supported Opcodes (v2)

### Object Operations
| Opcode | Value | Status |
|--------|-------|--------|
| NEW_OBJECT | 0x40 | Supported |
| INIT_OBJECT | 0x43 | Supported |
| GET_MEMBER | 0x4E | Supported |
| SET_MEMBER | 0x4F | Supported |
| DELETE | 0x3A | Supported |
| DELETE2 | 0x3B | Supported |
| TYPEOF | 0x44 | Supported |
| ENUMERATE | 0x46 | Supported |
| ENUMERATE2 | 0x55 | Supported |
| EXTENDS | 0x69 | Supported |
| INSTANCEOF | 0x54 | Supported |

### Array Operations
| Opcode | Value | Status |
|--------|-------|--------|
| INIT_ARRAY | 0x42 | Supported |

### Function Operations
| Opcode | Value | Status |
|--------|-------|--------|
| DEFINE_LOCAL | 0x3C | Supported |
| DECLARE_LOCAL | 0x41 | Supported |
| CALL_FUNCTION | 0x3D | Supported |
| CALL_METHOD | 0x52 | Supported |
| RETURN | 0x3E | Supported |
| NEW_METHOD | 0x53 | Supported |
| DEFINE_FUNCTION | 0x9B | Supported |
| DEFINE_FUNCTION2 | 0x8E | Supported |

### Stack/Register Operations
| Opcode | Value | Status |
|--------|-------|--------|
| DUPLICATE | 0x4C | Supported |
| STACK_SWAP | 0x4D | Supported |
| STORE_REGISTER | 0x87 | Supported |

## Unsupported Opcodes (v2 - Compile Error)

### Comparison Operations
| Opcode | Value | Status |
|--------|-------|--------|
| EQUALS2 | 0x49 | Unsupported |
| LESS2 | 0x48 | Unsupported |
| GREATER | 0x67 | Unsupported |
| STRICT_EQUALS | 0x66 | Unsupported |

### Arithmetic Operations
| Opcode | Value | Status |
|--------|-------|--------|
| ADD2 | 0x47 | Unsupported |
| MODULO | 0x3F | Unsupported |
| INCREMENT | 0x50 | Unsupported |
| DECREMENT | 0x51 | Unsupported |

### Type Conversion
| Opcode | Value | Status |
|--------|-------|--------|
| TO_NUMBER | 0x4A | Unsupported |
| TO_STRING | 0x4B | Unsupported |

## Opcodes NOT Included (Never Implemented)

The following opcodes were never part of this PR:

- Timeline control: NEXT_FRAME, PREV_FRAME, PLAY, TOGGLE_QUALITY, STOP_SOUNDS
- Drag operations: START_DRAG, END_DRAG
- Sprite manipulation: CLONE_SPRITE, REMOVE_SPRITE
- Property access: GET_PROPERTY, SET_PROPERTY
- Target navigation: SET_TARGET, SET_TARGET2, TARGET_PATH
- Random number: RANDOM_NUMBER
- Exception handling: THROW, TRY
- Interface operations: CAST_OP, IMPLEMENTS_OP
- URL/frame navigation: GOTO_FRAME, GOTO_LABEL, GET_URL, GET_URL2, WAIT_FOR_FRAME, WAIT_FOR_FRAME2, GOTO_FRAME2
- String operations: STRING_EXTRACT, STRING_LESS, STRING_GREATER, MB_STRING_LENGTH, MB_STRING_EXTRACT
- Character operations: CHAR_TO_ASCII, ASCII_TO_CHAR, MB_CHAR_TO_ASCII, MB_ASCII_TO_CHAR
- Other: TO_INTEGER, WITH, CALL

## Testing

The implementation compiles successfully. SWF files using unsupported opcodes will fail at compile time with a clear error message indicating which opcode is not supported.

## Commit

```
37192d3 Mark unsupported opcodes in minimal build
```

## Dependencies

This PR requires the corresponding SWFModernRuntime PR (v2) that implements:
- Object allocation and property management (ASObject, ASArray)
- Function call runtime support
- Only the minimal set of opcodes listed above
