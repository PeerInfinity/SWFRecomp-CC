# SWFModernRuntime: Objects and Functions PR

## Branch: feature/objects-and-functions

## Summary

This PR adds runtime support for ActionScript 2.0 object and function operations. It's a comprehensive change that includes:

1. **Object System**: New ASObject and ASArray types with reference counting
2. **Function Support**: Function registry and call mechanisms
3. **Heap Refactoring**: All heap functions now require app_context parameter
4. **ActionScript Opcodes**: 50+ new opcode implementations

## Files Changed

| File | Insertions | Deletions | Description |
|------|------------|-----------|-------------|
| CMakeLists.txt | +1 | 0 | Added object.c to build |
| include/actionmodern/action.h | +160 | -12 | New macros and function declarations |
| include/actionmodern/object.h | +180 | 0 | **NEW** Object/Array types |
| include/actionmodern/stackvalue.h | +11 | -5 | New stack value types |
| include/actionmodern/variables.h | +30 | -5 | ActionVar enhancements |
| include/flashbang/flashbang.h | +19 | -5 | app_context parameter |
| include/libswf/swf.h | +62 | -25 | SWFAppContext extensions |
| include/libswf/tag.h | +6 | -3 | NO_GRAPHICS guards |
| include/memory/heap.h | +93 | -8 | app_context API + HALLOC/FREE macros |
| src/actionmodern/action.c | +6326 | -70 | Opcode implementations |
| src/actionmodern/object.c | +845 | 0 | **NEW** Object/Array implementation |
| src/actionmodern/variables.c | +277 | -35 | Variable handling |
| src/flashbang/flashbang.c | +159 | -20 | Heap integration |
| src/libswf/swf.c | +102 | -15 | Initialization order |
| src/libswf/swf_core.c | +93 | -15 | NO_GRAPHICS mode |
| src/libswf/tag.c | +36 | -15 | NO_GRAPHICS guards |
| src/libswf/tag_stubs.c | +12 | -10 | Stub updates |
| src/memory/heap.c | +198 | -25 | Virtual memory heap |

**Total: +8,081 insertions, -529 deletions**

---

## Detailed Changes

### New Files

#### include/actionmodern/object.h
Defines the core object system:
- `ASObject` struct with reference counting
- `ASProperty` for named properties with ECMA-262 attribute flags
- `ASArray` for indexed arrays
- Object lifecycle: `allocObject`, `retainObject`, `releaseObject`
- Property management: `getProperty`, `setProperty`, `deleteProperty`
- Array operations: `allocArray`, `getArrayElement`, `setArrayElement`
- Interface support for AS2 `implements` keyword

#### src/actionmodern/object.c
Implements the object system:
- Reference counting with automatic cleanup
- Property lookup with prototype chain traversal
- Dynamic property arrays with growth
- Interface implementation checking

---

### Heap Refactoring

#### include/memory/heap.h
- All functions now require `SWFAppContext* app_context`
- New convenience macros:
  - `HALLOC(s)` - allocate s bytes
  - `HCALLOC(n, s)` - allocate n*s bytes, zero-initialized
  - `FREE(p)` - free pointer p

#### src/memory/heap.c
- Virtual memory-based allocation (1 GB reserved)
- Lazy physical memory allocation by OS
- Proper bounds checking on free

---

### SWFAppContext Extensions

#### include/libswf/swf.h

**New fields added:**
```c
// Heap management
size_t heap_full_size;
size_t heap_current_size;
int heap_inited;

// Frame management
size_t frame_count;

// Playback state
int is_playing;
size_t current_frame;

// Drag state
int is_dragging;
char* dragged_target;
```

**New globals:**
- `g_frame_funcs`, `g_frame_count` - for ActionCall opcode

---

### ActionScript Opcodes Implemented

#### Object Operations
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

#### Array Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x42 | actionInitArray | Initialize array literal |

#### Function Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x3C | actionDefineLocal | Define local with value |
| 0x41 | actionDeclareLocal | Declare local (undefined) |
| 0x3D | actionCallFunction | Call named function |
| 0x52 | actionCallMethod | Call object method |
| 0x3E | actionReturn | Return from function |
| 0x53 | actionNewMethod | Construct with method |

#### Stack Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x4C | actionDuplicate | Duplicate top of stack |
| 0x4D | actionStackSwap | Swap top two values |
| 0x87 | actionStoreRegister | Store to register |
| 0x96 | actionPushRegister | Push register value |

#### Comparison Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x49 | actionEquals2 | Type-aware equality |
| 0x48 | actionLess2 | Type-aware less-than |
| 0x67 | actionGreater | Greater-than |
| 0x66 | actionStrictEquals | Strict equality |
| 0x54 | actionInstanceOf | Instance check |

#### Arithmetic Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x47 | actionAdd2 | Type-aware addition |
| 0x3F | actionModulo | Modulo operation |
| 0x50 | actionIncrement | Increment value |
| 0x51 | actionDecrement | Decrement value |

#### Type Conversion
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x4A | actionToNumber | Convert to number |
| 0x4B | actionToString | Convert to string |
| 0x18 | actionToInteger | Convert to integer |

#### String Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x21 | actionStringAdd | Concatenate strings |
| 0x14 | actionStringLength | Get string length |
| 0x15 | actionStringExtract | Extract substring |
| 0x31 | actionMBStringLength | Multibyte string length |

#### Display/Playback Control
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x04 | actionNextFrame | Advance to next frame |
| 0x05 | actionPrevFrame | Go to previous frame |
| 0x06 | actionPlay | Start playback |
| 0x07 | actionStop | Stop playback |
| 0x08 | actionToggleQuality | Toggle quality |
| 0x09 | actionStopSounds | Stop all sounds |

#### Drag Operations
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x27 | actionStartDrag | Start dragging |
| 0x28 | actionEndDrag | End dragging |

#### Property Access
| Opcode | Function | Description |
|--------|----------|-------------|
| 0x22 | actionGetProperty | Get movie clip property |
| 0x23 | actionSetProperty | Set movie clip property |

#### Built-in Functions
| Function | Description |
|----------|-------------|
| trace | Output debug message |
| getTimer | Get elapsed time |
| random | Generate random number |

---

### Flashbang Integration

#### include/flashbang/flashbang.h
- `flashbang_init(SWFAppContext*, FlashbangContext*)` - now takes app_context
- `flashbang_free(SWFAppContext*, FlashbangContext*)` - for proper cleanup

#### src/flashbang/flashbang.c
- Uses HALLOC for `bitmap_sizes` allocation
- Uses FREE in `flashbang_free` - **fixes memory leak**

---

### Initialization Order

#### src/libswf/swf.c

**Before:**
```
flashbang_init → ... → heap_init → ... → heap_shutdown → flashbang_free
```

**After:**
```
heap_init → flashbang_init → ... → flashbang_free → heap_shutdown
```

This ensures the heap is ready before flashbang allocates memory.

---

## Potential Concerns

### Size of Change
This is a large PR (+8,081 lines). Consider splitting into:
1. Heap refactoring (app_context parameter)
2. Object system (object.h, object.c)
3. Core opcodes (objects, functions, stack operations)
4. Display control opcodes (play, stop, drag, etc.)

### Opcodes Included That May Not Be Needed
The following could potentially be deferred:
- Display control: nextFrame, prevFrame, play, toggleQuality, stopSounds
- Drag operations: startDrag, endDrag
- Property access: getProperty, setProperty (movie clip properties)
- Random number: random

### Global State
Some global state is used:
- `scope_chain[]` - for WITH statement
- `function_registry[]` - function storage
- `global_object` - ActionScript _global

---

## Testing

The implementation compiles in both graphics and NO_GRAPHICS modes. Full testing requires test SWF files that exercise the new opcodes.

## Dependencies

Requires corresponding SWFRecomp compiler support for generating code that uses these runtime functions.
