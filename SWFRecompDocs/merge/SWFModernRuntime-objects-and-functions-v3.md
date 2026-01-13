# SWFModernRuntime: Objects and Functions PR (v3 - Extended)

## Branch: feature/objects-and-functions

## Summary

This PR adds runtime support for ActionScript 2.0 object and function operations needed by SWFRecomp. **Version 3 extends v2** by adding back arithmetic, comparison, string, and variable operations from upstream.

1. **Object System**: New ASObject, ASArray, and ASFunction types with reference counting
2. **Function Support**: Function registry and call mechanisms
3. **ActionScript Opcodes**: Object/function operations plus arithmetic, comparison, string, and variable ops
4. **Heap Extension**: Added `heap_calloc` for zeroed memory allocation

## Changes from v2

The following opcode categories were **added back** in v3:
- Arithmetic Operations (actionAdd, actionSubtract, actionMultiply, actionDivide)
- Comparison Operations (actionEquals, actionLess, actionAnd, actionOr, actionNot)
- String Operations (actionStringEquals, actionStringLength, actionStringAdd)
- Variable Operations (actionGetVariable, actionSetVariable)
- Utility Operations (actionTrace, actionGetTime)

## Files Changed

| File | Insertions | Deletions | Description |
|------|------------|-----------|-------------|
| CMakeLists.txt | +1 | 0 | Added object.c to build |
| include/actionmodern/action.h | +65 | -1 | Function declarations (extended) |
| include/actionmodern/object.h | +180 | 0 | **NEW** Object/Array/Function types |
| include/actionmodern/stackvalue.h | +10 | -1 | New stack value types |
| include/libswf/tag.h | +6 | -2 | NO_GRAPHICS guards, tagInit signature |
| include/memory/heap.h | +11 | 0 | Added HCALLOC macro and heap_calloc |
| src/actionmodern/action.c | +774 | -3065 | Opcode implementations (extended) |
| src/actionmodern/object.c | +845 | 0 | **NEW** Object/Array implementation |
| src/libswf/swf_core.c | +4 | -1 | initVarArray call, freeMap signature |
| src/libswf/tag.c | +36 | -13 | NO_GRAPHICS guards, loop variable fix |
| src/libswf/tag_stubs.c | +12 | -3 | NO_GRAPHICS guards, tagShowFrame signature |
| src/memory/heap.c | +11 | 0 | heap_calloc implementation |

**Total: ~3,900 insertions** (extended from ~3,300 in v2)

### Files NOT Changed (reverted to upstream)
- `include/actionmodern/variables.h` - Uses upstream anonymous union API
- `include/flashbang/flashbang.h` - Unchanged from upstream
- `include/libswf/swf.h` - Reverted whitespace-only changes
- `src/actionmodern/variables.c` - Uses upstream HALLOC/app_context pattern
- `src/flashbang/flashbang.c` - Unchanged from upstream
- `src/libswf/swf.c` - Unchanged from upstream

---

## New Files

### include/actionmodern/object.h
Defines the core object system:
- `ASObject` struct with reference counting and prototype chain
- `ASProperty` for named properties with ECMA-262 attribute flags
- `ASArray` for indexed arrays
- `ASFunction` for function objects (simple and advanced types)
- Object lifecycle: `allocObject`, `retainObject`, `releaseObject`
- Property management: `getProperty`, `setProperty`, `deleteProperty`
- Array operations: `allocArray`, `getArrayElement`, `setArrayElement`

### src/actionmodern/object.c
Implements the object system:
- Reference counting with automatic cleanup
- Property lookup with prototype chain traversal
- Dynamic property arrays with growth
- Constructor and prototype support

---

## Heap Extension

### include/memory/heap.h
Added `heap_calloc` for zeroed memory allocation:
```c
#define HCALLOC(n, s) heap_calloc(app_context, n, s)
void* heap_calloc(SWFAppContext* app_context, size_t count, size_t size);
```

### src/memory/heap.c
Simple implementation using o1heap + memset.

---

## ActionScript Opcodes (v3 - Extended Set)

### Arithmetic Operations (added in v3)
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x0A | actionAdd | Add two values |
| 0x0B | actionSubtract | Subtract two values |
| 0x0C | actionMultiply | Multiply two values |
| 0x0D | actionDivide | Divide two values |

### Comparison Operations (added in v3)
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x0E | actionEquals | Equality comparison |
| 0x0F | actionLess | Less-than comparison |
| 0x10 | actionAnd | Logical AND |
| 0x11 | actionOr | Logical OR |
| 0x12 | actionNot | Logical NOT |

### String Operations (added in v3)
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x13 | actionStringEquals | String equality |
| 0x14 | actionStringLength | Get string length |
| 0x21 | actionStringAdd | Concatenate strings |

### Variable Operations (added in v3)
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x1C | actionGetVariable | Get variable value |
| 0x1D | actionSetVariable | Set variable value |

### Utility Operations (added in v3)
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x26 | actionTrace | Output debug message |
| 0x34 | actionGetTime | Get elapsed time in ms |

### Object Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x40 | actionNewObject | Create object from constructor |
| 0x43 | actionInitObject | Initialize object literal |
| 0x4E | actionGetMember | Get object property |
| 0x4F | actionSetMember | Set object property |
| 0x3A | actionDelete | Delete object property |
| 0x3B | actionDelete2 | Delete variable |
| 0x44 | actionTypeOf | Get type string |
| 0x46 | actionEnumerate | Enumerate properties (AS1) |
| 0x55 | actionEnumerate2 | Enumerate properties (AS2) |
| 0x69 | actionExtends | Set up inheritance |
| 0x54 | actionInstanceOf | Instance check |

### Array Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x42 | actionInitArray | Initialize array literal |

### Function Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x3C | actionDefineLocal | Define local with value |
| 0x41 | actionDeclareLocal | Declare local (undefined) |
| 0x3D | actionCallFunction | Call named function |
| 0x52 | actionCallMethod | Call object method |
| 0x3E | actionReturn | Return from function |
| 0x53 | actionNewMethod | Construct with method |
| 0x9B | actionDefineFunction | Define simple function |
| 0x8E | actionDefineFunction2 | Define advanced function |

### Stack/Register Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x87 | actionStoreRegister | Store to register |
| (push) | actionPushRegister | Push register value |

---

## Opcodes Still Unsupported in v3

The following opcodes remain unsupported to keep the PR focused:

### AS2-style Operations (unsupported)
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x47 | actionAdd2 | Type-aware addition |
| 0x48 | actionLess2 | Type-aware less-than |
| 0x49 | actionEquals2 | Type-aware equality |
| 0x66 | actionStrictEquals | Strict equality |
| 0x67 | actionGreater | Greater-than |
| 0x3F | actionModulo | Modulo operation |
| 0x50 | actionIncrement | Increment value |
| 0x51 | actionDecrement | Decrement value |
| 0x4A | actionToNumber | Convert to number |
| 0x4B | actionToString | Convert to string |
| 0x4C | actionDuplicate | Duplicate stack top |
| 0x4D | actionStackSwap | Swap top two values |

### Other opcodes never included
- Timeline control: NEXT_FRAME, PREV_FRAME, PLAY, STOP, TOGGLE_QUALITY, STOP_SOUNDS
- Drag operations: START_DRAG, END_DRAG
- Sprite manipulation: CLONE_SPRITE, REMOVE_SPRITE
- Property access: GET_PROPERTY, SET_PROPERTY
- Target navigation: SET_TARGET, SET_TARGET2, TARGET_PATH
- Frame navigation: GOTO_FRAME, GOTO_LABEL, GOTO_FRAME2, WAIT_FOR_FRAME, WAIT_FOR_FRAME2
- URL operations: GET_URL, GET_URL2
- String operations: All MB_* string operations
- Exception handling: THROW, TRY
- Other: RANDOM_NUMBER, TO_INTEGER, WITH, CALL, CAST_OP, IMPLEMENTS_OP

---

## NO_GRAPHICS Mode Support

### src/libswf/tag.c
- Wrapped entire file in `#ifndef NO_GRAPHICS`
- Added empty `tagInit()` function
- Fixed loop variable shadowing (`i` -> `j`)

### src/libswf/tag_stubs.c
- Wrapped in `#ifdef NO_GRAPHICS`
- Updated `tagShowFrame` signature to take `app_context`

---

## Testing

The implementation compiles in both graphics and NO_GRAPHICS modes:
```bash
cd build && cmake .. && make  # Graphics mode
cd build_no_graphics && cmake .. -DNO_GRAPHICS=ON && make  # Console mode
```

## Commits

```
e7c4d57 Minimize opcodes to object/function operations only
164bba9 Add back arithmetic, comparison, string, and variable opcodes
```

## Dependencies

Requires corresponding SWFRecomp compiler support (v3) that generates code using these runtime functions.
