# Migration Plan: Adopt Upstream app_context Convention

**Date:** December 4, 2025

**Status:** Planning

**Goal:** Migrate SWFRecomp-CC to pass `SWFAppContext* app_context` through all function calls, matching upstream convention.

---

## Executive Summary

This plan outlines the steps to refactor both SWFRecomp (compiler) and SWFModernRuntime to use the upstream API convention where `SWFAppContext* app_context` is passed to frame functions, script functions, tag functions, and action functions.

**Benefits:**
- Direct compatibility with upstream - future merges become trivial
- Thread-safe design (could run multiple SWF contexts simultaneously)
- Cleaner data flow (no hidden globals)
- HALLOC/FREE macros work without modification

**Estimated scope:**
- ~8000+ lines of code changes
- Both compiler and runtime must change together
- All 159 tests will need recompilation (automatic)

---

## Phase 1: Preparation

### 1.1 Create Migration Branch

```bash
git checkout -b feature/app-context-migration
```

### 1.2 Update SWFAppContext Structure

**File:** `SWFModernRuntime/include/libswf/swf.h`

Add missing fields from upstream while keeping local additions:

```c
typedef void (*frame_func)(SWFAppContext* app_context);  // Change signature

typedef struct SWFAppContext
{
    frame_func* frame_funcs;
    size_t frame_count;  // Keep local addition

    int width;
    int height;
    const float* stage_to_ndc;

    // Heap management (upstream style)
    O1HeapInstance* heap_instance;
    char* heap;
    size_t heap_size;  // Change from heap_current_size/heap_full_size

    size_t max_string_id;  // Add from upstream

    // Graphics data
    size_t bitmap_count;
    size_t bitmap_highest_w;
    size_t bitmap_highest_h;

    char* shape_data;
    size_t shape_data_size;
    char* transform_data;
    size_t transform_data_size;
    char* color_data;
    size_t color_data_size;
    char* uninv_mat_data;
    size_t uninv_mat_data_size;
    char* gradient_data;
    size_t gradient_data_size;
    char* bitmap_data;
    size_t bitmap_data_size;

    // Text/font data (add from upstream)
    u32* glyph_data;
    size_t glyph_data_size;
    u32* text_data;
    size_t text_data_size;
    char* cxform_data;
    size_t cxform_data_size;
} SWFAppContext;
```

### 1.3 Update Character Structure

**File:** `SWFModernRuntime/include/libswf/swf.h`

Change from simple struct to union (upstream style):

```c
typedef enum {
    CHAR_TYPE_SHAPE,
    CHAR_TYPE_TEXT,
} CharacterType;

typedef struct Character {
    CharacterType type;
    union {
        // DefineShape
        struct {
            size_t shape_offset;
            size_t size;
        };
        // DefineText
        struct {
            size_t text_start;
            size_t text_size;
            u32 transform_start;
            u32 cxform_id;
        };
    };
} Character;
```

---

## Phase 2: Runtime Function Signatures

### 2.1 Action Functions

**File:** `SWFModernRuntime/include/actionmodern/action.h`

Change all declarations from:
```c
void actionAdd(char* stack, u32* sp);
```
To:
```c
void actionAdd(SWFAppContext* app_context, char* stack, u32* sp);
```

**Complete list of functions to change (~100 functions):**

| Category | Functions |
|----------|-----------|
| Arithmetic | actionAdd, actionSubtract, actionMultiply, actionDivide, actionModulo, actionAdd2 |
| Comparison | actionEquals, actionLess, actionLess2, actionGreater, actionEquals2, actionStrictEquals |
| Logic | actionAnd, actionOr, actionNot |
| Bitwise | actionBitAnd, actionBitOr, actionBitXor, actionBitLShift, actionBitRShift, actionBitURShift |
| String | actionStringEquals, actionStringLength, actionStringAdd, actionStringExtract, actionStringLess, actionStringGreater, actionMbStringLength, actionMbStringExtract, actionCharToAscii, actionAsciiToChar, actionMbCharToAscii, actionMbAsciiToChar |
| Type | actionTypeof, actionToInteger, actionToNumber, actionToString, actionCastOp, actionInstanceOf |
| Stack | actionPush*, actionPop, actionDuplicate, actionStackSwap |
| Variables | actionGetVariable, actionSetVariable, actionGetProperty, actionSetProperty, actionDelete, actionDelete2 |
| Objects | actionNewObject, actionNewMethod, actionInitObject, actionInitArray, actionGetMember, actionSetMember |
| Functions | actionDefineFunction, actionDefineFunction2, actionCallFunction, actionCallMethod, actionReturn |
| Control | actionGotoFrame, actionGotoFrame2, actionGoToLabel, actionNextFrame, actionPrevFrame, actionPlay, actionStop, actionWaitForFrame, actionWaitForFrame2, actionCall |
| Exceptions | actionThrow, actionTry* |
| MovieClip | actionCloneSprite, actionRemoveSprite, actionSetTarget, actionSetTarget2, actionTargetPath, actionGetURL, actionGetURL2, actionStartDrag, actionEndDrag |
| Enumeration | actionEnumerate, actionEnumerate2 |
| Misc | actionTrace, actionGetTime, actionRandom, actionToggleQuality, actionStoreRegister, actionPushRegister, actionExtends, actionImplementsOp |

### 2.2 Action Function Implementations

**File:** `SWFModernRuntime/src/actionmodern/action.c`

For each function, change signature and update any heap allocations:

**Before:**
```c
void actionAdd(char* stack, u32* sp)
{
    // ... implementation
}
```

**After:**
```c
void actionAdd(SWFAppContext* app_context, char* stack, u32* sp)
{
    // ... implementation (may use HALLOC/FREE which need app_context)
}
```

**Functions that will use app_context for heap:**
- actionNewObject (allocates objects)
- actionInitArray (allocates arrays)
- actionInitObject (allocates objects)
- actionStringAdd (may allocate strings)
- actionAdd2 (string concatenation)
- Any function using HALLOC/FREE

### 2.3 Variable Functions

**File:** `SWFModernRuntime/include/actionmodern/variables.h`

```c
// Change declarations
void initVarArray(SWFAppContext* app_context, size_t max_string_id);
ActionVar* getVariableById(SWFAppContext* app_context, u32 string_id);
ActionVar* getVariable(SWFAppContext* app_context, char* var_name, size_t key_size);
void setVariableWithValue(SWFAppContext* app_context, ActionVar* var, char* stack, u32* sp);
char* materializeStringList(SWFAppContext* app_context, char* stack, u32* sp);
void freeMap(SWFAppContext* app_context);
```

**File:** `SWFModernRuntime/src/actionmodern/variables.c`

Update all implementations to match.

### 2.4 Tag Functions

**File:** `SWFModernRuntime/include/libswf/tag.h`

```c
void tagShowFrame(SWFAppContext* app_context);
void tagDefineShape(SWFAppContext* app_context, CharacterType type, size_t char_id, size_t shape_offset, size_t shape_size);
void tagDefineText(SWFAppContext* app_context, size_t char_id, size_t text_start, size_t text_size, u32 transform_start, u32 cxform_id);
void tagPlaceObject2(SWFAppContext* app_context, size_t depth, size_t char_id, u32 transform_id);
void tagRemoveObject2(SWFAppContext* app_context, size_t depth);
```

**File:** `SWFModernRuntime/src/libswf/tag.c`

Update implementations, including text rendering loop.

### 2.5 Utility Functions

**File:** `SWFModernRuntime/include/utils.h`

```c
#define ENSURE_SIZE(ptr, id, capac, elem_size) \
    if (id >= capac) \
        grow_ptr(app_context, (char**) &ptr, &capac, elem_size);

void grow_ptr(SWFAppContext* app_context, char** ptr, size_t* capacity_ptr, size_t elem_size);
```

### 2.6 Heap Functions

**File:** `SWFModernRuntime/include/memory/heap.h`

```c
#define HALLOC(s) heap_alloc(app_context, s)
#define FREE(p) heap_free(app_context, p)

void heap_init(SWFAppContext* app_context, size_t size);
void* heap_alloc(SWFAppContext* app_context, size_t size);
void heap_free(SWFAppContext* app_context, void* ptr);
void heap_shutdown(SWFAppContext* app_context);
```

### 2.7 Flashbang Functions

**File:** `SWFModernRuntime/include/flashbang/flashbang.h`

```c
void flashbang_init(FlashbangContext* context, SWFAppContext* app_context);
void flashbang_release(FlashbangContext* context, SWFAppContext* app_context);
```

### 2.8 Main Loop

**File:** `SWFModernRuntime/src/libswf/swf.c`

```c
void tagMain(SWFAppContext* app_context)
{
    frame_func* frame_funcs = app_context->frame_funcs;

    while (!quit_swf)
    {
        frame_funcs[next_frame](app_context);  // Pass app_context
        // ...
    }
}
```

---

## Phase 3: Compiler Changes

### 3.1 Frame Function Generation

**File:** `SWFRecomp/src/swf.cpp`

**Before (local):**
```cpp
<< "void frame_" << to_string(next_frame_i) << "()" << endl
```

**After (upstream):**
```cpp
<< "void frame_" << to_string(next_frame_i) << "(SWFAppContext* app_context)" << endl
```

**Locations to change:**
- Line ~358: Frame function definition
- Line ~434: frame_func typedef
- Line ~550: Frame function definition (alternate path)

### 3.2 Script Function Generation

**File:** `SWFRecomp/src/swf.cpp`

**Before:**
```cpp
<< "void script_" << to_string(next_script_i) << "(char* stack, u32* sp);"
<< "void script_" << next_script_i << "(char* stack, u32* sp)" << endl
```

**After:**
```cpp
<< "void script_" << to_string(next_script_i) << "(SWFAppContext* app_context, char* stack, u32* sp);"
<< "void script_" << next_script_i << "(SWFAppContext* app_context, char* stack, u32* sp)" << endl
```

### 3.3 Script Call Generation

**File:** `SWFRecomp/src/swf.cpp`

**Before:**
```cpp
context.tag_main << "\t" << "script_" << to_string(last_queued_script) << "(stack, &sp);" << endl;
```

**After:**
```cpp
context.tag_main << "\t" << "script_" << to_string(last_queued_script) << "(app_context, stack, &sp);" << endl;
```

### 3.4 Tag Function Calls

**File:** `SWFRecomp/src/swf.cpp`

**tagShowFrame:**
```cpp
// Before:
context.tag_main << "\t" << "tagShowFrame();" << endl;
// After:
context.tag_main << "\t" << "tagShowFrame(app_context);" << endl;
```

**tagDefineShape:**
```cpp
// Before:
context.tag_main << "\t" << "tagDefineShape(" << shape_id << ", " << offset << ", " << size << ");" << endl;
// After:
context.tag_main << "\t" << "tagDefineShape(app_context, CHAR_TYPE_SHAPE, " << shape_id << ", " << offset << ", " << size << ");" << endl;
```

**tagPlaceObject2:**
```cpp
// Before:
context.tag_main << "\t" << "tagPlaceObject2(" << depth << ", " << char_id << ", " << transform_id << ");" << endl;
// After:
context.tag_main << "\t" << "tagPlaceObject2(app_context, " << depth << ", " << char_id << ", " << transform_id << ");" << endl;
```

### 3.5 Action Function Calls

**File:** `SWFRecomp/src/action/action.cpp`

Every action call needs `app_context` added as first parameter.

**Before:**
```cpp
<< "\t" << "actionAdd(stack, sp);" << endl;
<< "\t" << "actionSubtract(stack, sp);" << endl;
<< "\t" << "actionGetVariable(stack, sp);" << endl;
// ... (~100 more)
```

**After:**
```cpp
<< "\t" << "actionAdd(app_context, stack, sp);" << endl;
<< "\t" << "actionSubtract(app_context, stack, sp);" << endl;
<< "\t" << "actionGetVariable(app_context, stack, sp);" << endl;
// ... (~100 more)
```

**Search pattern for bulk replacement:**
```
actionAdd(stack, sp)  →  actionAdd(app_context, stack, sp)
```

### 3.6 frame_func Typedef

**File:** `SWFRecomp/src/swf.cpp`

**Before:**
```cpp
<< "typedef void (*frame_func)();" << endl
```

**After:**
```cpp
<< "typedef void (*frame_func)(SWFAppContext* app_context);" << endl
```

---

## Phase 4: Remove Globals

### 4.1 Globals to Remove/Replace

**File:** `SWFModernRuntime/src/libswf/swf.c`

Remove these globals (data now accessed via app_context):
```c
// REMOVE:
frame_func* g_frame_funcs = NULL;
size_t g_frame_count = 0;

// KEEP (runtime state, not context data):
int quit_swf;
int bad_poll;
size_t next_frame;
int manual_next_frame;
int is_dragging;
char* dragged_target;
```

### 4.2 Update ActionCall Opcode

**File:** `SWFModernRuntime/src/actionmodern/action.c`

The `actionCall` function currently uses `g_frame_funcs` and `g_frame_count`. Change to use `app_context->frame_funcs` and `app_context->frame_count`.

**Before:**
```c
extern frame_func* g_frame_funcs;
extern size_t g_frame_count;
// ...
if (g_frame_funcs && (size_t)frame_num < g_frame_count) {
    g_frame_funcs[frame_num]();
}
```

**After:**
```c
if (app_context->frame_funcs && (size_t)frame_num < app_context->frame_count) {
    app_context->frame_funcs[frame_num](app_context);
}
```

---

## Phase 5: Testing

### 5.1 Build and Run Tests

```bash
# Clean build
cd SWFRecomp && rm -rf build && mkdir build && cd build
cmake .. && make

# Run test suite
cd ../../tests
./all_tests.sh
```

### 5.2 Expected Test Behavior

- All 159 tests should recompile automatically (main.c unchanged)
- Generated recomp.c files will have new signatures
- Runtime behavior should be identical

### 5.3 Manual Verification

Test a few key scenarios:
1. Simple arithmetic (add_floats_swf_4)
2. Variables (get_variable_swf_4, set_variable_swf_4)
3. Functions (call_function_swf_5, define_function2_swf_7)
4. Objects (new_object_swf_4, get_member_swf_4)
5. Control flow (goto_frame_swf_4)

---

## Phase 6: Font/Text Integration

After the app_context migration is complete, merging font support becomes straightforward:

### 6.1 Copy Upstream Files

```bash
# Shaders
cp upstream/SWFModernRuntime/src/flashbang/shaders/vertex.glsl SWFModernRuntime/src/flashbang/shaders/
cp upstream/SWFModernRuntime/src/flashbang/shaders/fragment.glsl SWFModernRuntime/src/flashbang/shaders/

# Already have swf.h with Character union from Phase 1
```

### 6.2 Merge flashbang.c Changes

Add cxform support from upstream - now compatible since we use app_context.

### 6.3 Merge tag.c Changes

Copy text rendering loop - now compatible since we use app_context.

### 6.4 Add tagDefineText to Compiler

**File:** `SWFRecomp/src/swf.cpp`

Add code generation for DefineText tags.

---

## Implementation Order

### Step 1: Create branch and update headers
- [ ] Create feature/app-context-migration branch
- [ ] Update swf.h (SWFAppContext, Character, frame_func)
- [ ] Update action.h (all declarations)
- [ ] Update variables.h
- [ ] Update tag.h
- [ ] Update utils.h
- [ ] Update heap.h
- [ ] Update flashbang.h

### Step 2: Update runtime implementations
- [ ] Update action.c (~100 functions)
- [ ] Update variables.c
- [ ] Update tag.c
- [ ] Update swf.c
- [ ] Update flashbang.c
- [ ] Update heap.c
- [ ] Update utils.c

### Step 3: Update compiler
- [ ] Update swf.cpp (frame/script generation)
- [ ] Update swf.cpp (tag calls)
- [ ] Update action/action.cpp (~100 call sites)

### Step 4: Remove globals
- [ ] Remove g_frame_funcs, g_frame_count
- [ ] Update actionCall to use app_context

### Step 5: Test
- [ ] Build compiler
- [ ] Build runtime
- [ ] Run full test suite
- [ ] Fix any failures

### Step 6: Merge font support
- [ ] Copy shaders
- [ ] Merge flashbang.c cxform code
- [ ] Merge tag.c text rendering
- [ ] Add DefineText to compiler
- [ ] Test with font test case

---

## Rollback Plan

If issues are encountered:

1. The migration branch keeps master clean
2. Each phase can be tested independently
3. Tests provide regression detection
4. Can abandon branch and use Option 3 (hybrid) instead

---

## Estimated Effort

| Phase | Files | Lines Changed | Complexity |
|-------|-------|---------------|------------|
| 1. Headers | 7 | ~200 | Low |
| 2. Runtime | 7 | ~7000 | Medium (repetitive) |
| 3. Compiler | 2 | ~200 | Low |
| 4. Globals | 2 | ~50 | Low |
| 5. Testing | - | - | Medium |
| 6. Fonts | 5 | ~300 | Low |
| **Total** | ~23 | ~7750 | Medium |

Most changes are mechanical (adding `app_context` parameter), so while the line count is high, the complexity is manageable with careful find-and-replace.

---

## Automation Opportunities

### Sed Scripts for Bulk Changes

**action.c function signatures:**
```bash
# In action.c, change function definitions
sed -i 's/^void action\([A-Za-z0-9]*\)(char\* stack, u32\* sp)/void action\1(SWFAppContext* app_context, char* stack, u32* sp)/g' action.c
```

**action.cpp call sites:**
```bash
# In action.cpp, change function calls
sed -i 's/action\([A-Za-z0-9]*\)(stack, sp)/action\1(app_context, stack, sp)/g' action.cpp
```

These can speed up the mechanical changes significantly.
