# SWFRecomp: Objects and Functions PR

## Branch: feature/objects-and-functions

## Summary

This PR adds compiler support for ActionScript 2.0 object and function operations, enabling recompilation of SWF files that use object literals, arrays, and user-defined functions.

## Files Changed

| File | Insertions | Deletions | Description |
|------|------------|-----------|-------------|
| include/action/action.hpp | +36 | 0 | Added opcode enum values and class members |
| include/context.hpp | +2 | 0 | Added inside_function2 tracking flag |
| src/action/action.cpp | +553 | -7 | Added opcode implementations |

**Total: +584 insertions, -7 deletions**

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
| SWF_ACTION_MODULO | 0x3F | Modulo operation |
| SWF_ACTION_NEW_OBJECT | 0x40 | Create new object |
| SWF_ACTION_DECLARE_LOCAL | 0x41 | Declare local variable |
| SWF_ACTION_INIT_ARRAY | 0x42 | Initialize array literal |
| SWF_ACTION_INIT_OBJECT | 0x43 | Initialize object literal |
| SWF_ACTION_TYPEOF | 0x44 | Get type of value |
| SWF_ACTION_ENUMERATE | 0x46 | Enumerate object properties |
| SWF_ACTION_ADD2 | 0x47 | Add (type-aware) |
| SWF_ACTION_LESS2 | 0x48 | Less than (type-aware) |
| SWF_ACTION_EQUALS2 | 0x49 | Equals (type-aware) |
| SWF_ACTION_TO_NUMBER | 0x4A | Convert to number |
| SWF_ACTION_TO_STRING | 0x4B | Convert to string |
| SWF_ACTION_DUPLICATE | 0x4C | Duplicate stack top |
| SWF_ACTION_STACK_SWAP | 0x4D | Swap top two stack values |
| SWF_ACTION_GET_MEMBER | 0x4E | Get object member |
| SWF_ACTION_SET_MEMBER | 0x4F | Set object member |
| SWF_ACTION_INCREMENT | 0x50 | Increment value |
| SWF_ACTION_DECREMENT | 0x51 | Decrement value |
| SWF_ACTION_CALL_METHOD | 0x52 | Call object method |
| SWF_ACTION_NEW_METHOD | 0x53 | Call constructor as method |
| SWF_ACTION_INSTANCEOF | 0x54 | Check instance of class |
| SWF_ACTION_ENUMERATE2 | 0x55 | Enumerate (AS2 style) |
| SWF_ACTION_STRICT_EQUALS | 0x66 | Strict equality |
| SWF_ACTION_GREATER | 0x67 | Greater than |
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

**New case implementations:**
All 33 new opcodes have corresponding case statements in the parseActions switch. Key implementations:

- **DefineFunction/DefineFunction2**: Parse function metadata, parameters, and recursively parse function body
- **CallFunction/CallMethod**: Generate runtime function/method call code
- **NewObject/NewMethod**: Generate object instantiation code
- **InitArray/InitObject**: Generate array/object literal initialization
- **GetMember/SetMember**: Generate property access code
- **Return**: Generate early return with optional value

## Opcodes NOT Included

The following opcodes were intentionally excluded to keep the PR minimal:

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

The implementation has been verified to compile successfully. Runtime testing requires corresponding runtime support in SWFModernRuntime.

## Dependencies

This PR requires the corresponding SWFModernRuntime PR that implements:
- Object allocation and property management (ASObject, ASArray)
- Function call runtime support
- Type conversion runtime functions
