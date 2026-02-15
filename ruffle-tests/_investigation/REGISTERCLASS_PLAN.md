# RegisterClass and Export/Registration Implementation Plan

Last updated: 2026-02-14

## Overview

This plan covers implementing `Object.registerClass()`, the ExportAssets tag (tag 56), and the `attachMovie()` method — the three interconnected features that form Flash's "library symbol instantiation" system. Together they enable defining a class, associating it with a library symbol, and creating instances at runtime.

**Current state**: None of these features are implemented. The recompiler recognizes the ExportAssets tag but discards its data. The runtime has `attachMovie` registered as a stub method name on `MovieClip.prototype` but no handler. `Object.registerClass` is not defined anywhere.

**Note on test names**: Two tests in the "register_*" group are actually about the ActionScript VM register file, not `Object.registerClass()`:
- `register_underflow` — DefineFunction2 register count scoping (69% passing, needs register fix)
- `register_globals_across_frames` — VM register persistence across frames (needs register reset)

These are addressed in Phase 0 as quick wins before the main RegisterClass work.

## Test Inventory (7 named tests + 5 dependent tests)

### RegisterClass Tests (7 tests)

| Test | Lines | Current | Description |
|------|-------|---------|-------------|
| register_class_return_value | 12 | 0/12 | Object.registerClass() return values |
| register_class | 68 | 0/68 | Full registerClass + attachMovie pipeline |
| register_class_swf6 | ~68 | 0/? | SWF6 case-insensitive registerClass |
| register_class_with_sound | 10 | 0/10 | RegisterClass with Sound (known_failure in Ruffle) |
| register_and_init_order | 233 | 0/233 | DoInitAction + registerClass execution ordering |
| register_globals_across_frames | 12 | 0/12 | VM register reset between frames |
| register_underflow | 26 | 18/26 (69%) | DefineFunction2 register count underflow |

### Dependent Tests (benefit from this work)

| Test | Lines | Current | Why |
|------|-------|---------|-----|
| attach_movie | 59 | 43/59 (73%) | Needs ExportAssets + attachMovie |
| attach_movie_stop | 3 | 1/3 | Needs attachMovie |
| export_assets | 3 | 2/3 | Needs ExportAssets + attachMovie |
| clip_constructors | 8 | 0/8 | Needs registerClass + constructor invocation |
| on_construct | 25 | 0/25 | Needs onConstruct event + registerClass |
| movieclip_init_object | 5 | 0/5 | Needs attachMovie initObject |
| empty_movieclip_can_attach_movies | 11 | 8/11 | Needs attachMovie |

---

## Dependency Chain

```
Phase 0: VM Register Fixes (independent, quick wins)
    ↓
Phase 1: ExportAssets Parsing (recompiler)
    ↓
Phase 2: attachMovie Implementation (runtime)
    ↓
Phase 3: Object.registerClass (runtime)
    ↓
Phase 4: Constructor Invocation on Placement (runtime)
    ↓
Phase 5: DoInitAction Ordering + on(construct) Event (runtime/recompiler)
```

---

## Phase 0: VM Register Fixes (Quick Wins)

**Goal**: Fix two tests that are about the VM register file, not RegisterClass.

### 0a. register_globals_across_frames (0/12)

**Problem**: VM registers (r:0 through r:3) persist across frames when they should be reset.

**Expected behavior**: Each frame script gets a fresh set of registers. Setting r:0=42 in frame 1 should not make r:0=42 in frame 2.

**Fix**: In the runtime, reset the register file (registers 0-3) at the start of each frame's script execution. Currently registers are global state in `action.c`. They need to be saved/restored or reset when a new frame's DoAction script begins.

Looking at `register_globals_across_frames/RecompiledTags/tagMain.c`:
- `frame_0` calls `script_0` — script reads r:0-r:3 (should be undefined), sets to 42, reads again (42)
- `frame_1` calls `script_1` — script reads r:0-r:3 (should be undefined again)

The registers are `app_context->registers[]` or similar global state. The fix is to zero them at the start of each frame script call.

**Impact**: 12/12 lines → full pass.

### 0b. register_underflow (18/26, 69%)

**Problem**: When DefineFunction2 declares `RegisterCount=N`, registers 0..N-1 are local to the function. Registers N..3 should "bleed through" to the caller's registers (i.e., they share the same storage). Currently, the function likely gets its own copy of all 4 registers.

**Expected behavior** from the test:
```
Function f: RegisterCount=3, param 'a' → register 2
  - r:0 = undefined (local, fresh)
  - r:1 = undefined (local, fresh)
  - r:2 = 66 (param 'a', local)
  - r:3 = 3 (bleeds through from caller's r:3)
  - Writing r:3 = 9 persists to caller
```

```
Function g: RegisterCount=1
  - r:0 = undefined (local, fresh)
  - r:1 = 1 (bleeds through from caller's r:1)
  - r:2 = 2 (bleeds through from caller's r:2)
  - r:3 = 9 (bleeds through from caller's r:3, from f's write)
  - Writing r:1,r:2,r:3 = 8 persists to caller
```

**Fix**: In the recompiler's DefineFunction2 handling, only save/restore registers 0..RegisterCount-1 (the function-local ones). Registers RegisterCount..3 should directly reference the caller's registers.

Currently in `action.cpp`, DefineFunction2 likely saves all registers on entry and restores on exit. Change this to only save/restore up to `RegisterCount` registers.

**Impact**: 26/26 lines → full pass.

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=register_globals_across_frames --diff --verbose
python3 ruffle-tests/verify_output.py --test=register_underflow --diff --verbose
```

---

## Phase 1: ExportAssets Tag Parsing

**Goal**: Parse the ExportAssets tag (tag 56) in the recompiler and emit a symbol table that the runtime can use.

### SWF Spec Reference

From `SWFRecompDocs/specs/swf-spec-19.txt`:
```
Tag 56 (ExportAssets):
  Count     UI16           Number of assets to export
  Tag1      UI16           First character ID to export
  Name1     STRING         Identifier for first exported character
  ... repeated Count times ...
```

### 1a. Recompiler Changes (swf.cpp)

Replace the current skip:
```cpp
case SWF_TAG_EXPORT_ASSETS:
{
    cur_pos += tag.length;  // Currently: data discarded
    break;
}
```

With actual parsing:
```cpp
case SWF_TAG_EXPORT_ASSETS:
{
    tag.setFieldCount(1);
    tag.configureNextField(SWF_FIELD_UI16);  // Count
    tag.parseFields(cur_pos);
    u16 count = (u16)tag.fields[0].value;

    for (u16 i = 0; i < count; i++) {
        tag.setFieldCount(2);
        tag.configureNextField(SWF_FIELD_UI16);   // CharacterID
        tag.configureNextField(SWF_FIELD_STRING);  // Name
        tag.parseFields(cur_pos);

        u16 char_id = (u16)tag.fields[0].value;
        const char* name = tag.fields[1].string_value.c_str();

        // Emit into tagInit() in tagMain.c:
        tag_init << "\n\ttagRegisterExport(app_context, \"" << name << "\", " << char_id << ");";
    }
    break;
}
```

### 1b. Runtime Symbol Table (tag_stubs.c + tag.h)

Add to `tag.h`:
```c
void tagRegisterExport(SWFAppContext* app_context, const char* name, size_t char_id);
size_t tagLookupExport(SWFAppContext* app_context, const char* name);
```

Add to `tag_stubs.c`:
```c
#define MAX_EXPORTS_NG 128

typedef struct {
    char name[128];
    size_t char_id;
} NgExport;

static NgExport ng_exports[MAX_EXPORTS_NG];
static size_t ng_export_count = 0;

void tagRegisterExport(SWFAppContext* app_context, const char* name, size_t char_id) {
    (void)app_context;
    if (ng_export_count < MAX_EXPORTS_NG) {
        strncpy(ng_exports[ng_export_count].name, name, 127);
        ng_exports[ng_export_count].name[127] = '\0';
        ng_exports[ng_export_count].char_id = char_id;
        ng_export_count++;
    }
}

// Returns char_id or (size_t)-1 if not found
// Case-insensitive for SWF6, case-sensitive for SWF7+
size_t tagLookupExport(SWFAppContext* app_context, const char* name) {
    for (size_t i = 0; i < ng_export_count; i++) {
        if (app_context->swf_version < 7) {
            if (strcasecmp(ng_exports[i].name, name) == 0)
                return ng_exports[i].char_id;
        } else {
            if (strcmp(ng_exports[i].name, name) == 0)
                return ng_exports[i].char_id;
        }
    }
    return (size_t)-1;
}
```

### Tests affected by Phase 1

Phase 1 alone doesn't pass any tests — it provides the data infrastructure that Phase 2 (attachMovie) consumes. But it unblocks everything else.

### Verification

Check that `tagMain.c` for export_assets and attach_movie tests now contain `tagRegisterExport` calls:
```bash
cd SWFRecomp/build && cmake .. && make -j$(nproc) && cd ../..
python3 ruffle-tests/verify_output.py --test=export_assets --recompile-only
grep tagRegisterExport ruffle-tests/export_assets/RecompiledTags/tagMain.c
```

---

## Phase 2: attachMovie Implementation

**Goal**: Implement `MovieClip.attachMovie(linkageId, newName, depth, initObj)` to instantiate library symbols at runtime.

### What the tests expect

**attach_movie** (43/59):
```
mc = _root.attachMovie("Clip", "clip", 0)
// Returns reference to new clip
// clip.toString() → "_level0.clip"
// Bogus name → undefined
// initObj applies: {_x: 100, _y: 50, foo: "foo"}
// Negative depths allowed (-1)
// Max depth 2130690044 allowed; 2130690045 rejected
// Case-insensitive lookup for SWF6, case-sensitive for SWF7+
// Attached clips run their frame 1 script after current script
```

**export_assets** (2/3):
```
attachMovie("test", "mc", 1);
trace(mc._width);
// Expected: 141
```

### 2a. attachMovie Dispatch in action.c

In the `callMethod` handler for MovieClip methods, add an `attachMovie` case:

```c
else if (method_name_len == 11 && strncmp(method_name, "attachMovie", 11) == 0)
{
    // Args: linkageId (string), newName (string), depth (number), [initObj (object)]
    if (num_args < 3) {
        if (args != NULL) FREE(args);
        PUSH(ACTION_STACK_VALUE_UNDEFINED, 0ULL);
        return;
    }

    // 1. Get linkageId string, look up in export table
    char* linkage_id = toString(app_context, &args[0]);
    size_t char_id = tagLookupExport(app_context, linkage_id);

    if (char_id == (size_t)-1) {
        // Symbol not found → push undefined
        if (args != NULL) FREE(args);
        PUSH(ACTION_STACK_VALUE_UNDEFINED, 0ULL);
        return;
    }

    // 2. Get newName and depth
    char* new_name = toString(app_context, &args[1]);
    int depth = (int)toNumber(app_context, &args[2]);

    // 3. Validate depth (max 2130690044)
    if (depth > 2130690044) {
        if (args != NULL) FREE(args);
        PUSH(ACTION_STACK_VALUE_UNDEFINED, 0ULL);
        return;
    }

    // 4. Create MovieClip child with given name + depth
    // (reuse createEmptyMovieClip infrastructure, then populate from sprite data)
    MovieClip* new_mc = createMovieClip(app_context, new_name, /*parent=*/target_mc);
    tagPlaceMovieClipAtDepth(app_context, target_mc, new_mc, depth);

    // 5. Execute sprite's frame 0 function (places children, runs sub-scripts)
    tagExecuteSpriteFrame(app_context, new_mc, char_id, 0);

    // 6. Apply initObj properties (4th arg, if present)
    if (num_args >= 4 && args[3].type == ACTION_STACK_VALUE_OBJECT) {
        applyInitObject(app_context, new_mc, &args[3]);
    }

    // 7. Fire registered class constructor (Phase 3)
    // tagFireConstructor(app_context, new_mc, linkage_id);

    // 8. Push reference to new clip
    PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)new_mc);
    if (args != NULL) FREE(args);
    return;
}
```

### 2b. tagExecuteSpriteFrame helper (tag_stubs.c)

This function executes a sprite's frame function by character ID, in the context of a target MovieClip:

```c
void tagExecuteSpriteFrame(SWFAppContext* app_context, /* MovieClip target, */ size_t char_id, size_t frame) {
    size_t si = ng_find_sprite(char_id);
    if (si == (size_t)-1) return;
    if (frame >= ng_sprites[si].frame_count) return;

    // Save current display list context
    // Set context to target MovieClip's display list
    // Execute the sprite's frame function
    ng_sprites[si].funcs[frame](app_context);
    // Restore context
}
```

This mirrors the existing `tagPlaceObject2` context-swap pattern for sprites.

### 2c. Deferred frame scripts for attached clips

The `attach_movie` test shows that attached clips' frame scripts run *after* the current script completes:
```
// Frame scripts of all attached clips run at end:
/// Frame 1 of clip
/// Frame 1 of clip2
/// Frame 1 of clip4
```

This means we need a "deferred script queue" — when `attachMovie` places a sprite whose frame 0 has a DoAction script, that script should be queued and run after the current script finishes (at ShowFrame time). This is the same pattern as normal timeline sprite frame scripts.

### Tests fixed by Phase 2

- **export_assets**: 2/3 → 3/3 (attachMovie + _width access)
- **attach_movie**: 43/59 → ~50-55/59 (basic attachMovie works; some edge cases need Phase 3)
- **attach_movie_stop**: 1/3 → ~2-3/3
- **empty_movieclip_can_attach_movies**: 8/11 → ~10-11/11
- **movieclip_init_object**: 0/5 → ~3-5/5

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=export_assets --diff --verbose
python3 ruffle-tests/verify_output.py --test=attach_movie --diff --verbose
python3 ruffle-tests/verify_output.py --test=movieclip_init_object --diff --verbose
```

---

## Phase 3: Object.registerClass

**Goal**: Implement `Object.registerClass(symbolName, constructorFunc)` as a static method on the Object constructor.

### What the tests expect

**register_class_return_value** (0/12):
```
Object.registerClass()         → false   (0 args)
Object.registerClass(a,b,c)    → true    (extra args ignored, just need ≥2)
Object.registerClass("sym", F) → true    (register constructor F for "sym")
Object.registerClass("sym", null) → true (unregister)
Object.registerClass("weird!@#", F) → true (any string name works)
Object.registerClass(null, F)  → false   (non-string first arg)
Object.registerClass(12, F)    → false   (non-string first arg)
Object.registerClass("sym", {})→ false   (non-function second arg, unless null)
```

**Return value rules**:
- Returns `false` if < 2 args
- Returns `false` if first arg is not a string
- Returns `false` if second arg is not a function AND not null
- Returns `true` otherwise (registration or unregistration succeeded)

### 3a. RegisterClass Registry

```c
#define MAX_REGISTERED_CLASSES 128

typedef struct {
    char symbol_name[128];
    ASFunction* constructor;  // NULL = unregistered
} RegisteredClass;

static RegisteredClass registered_classes[MAX_REGISTERED_CLASSES];
static size_t registered_class_count = 0;
```

### 3b. Object.registerClass Static Method

Add `registerClass` as a property on the Object constructor function (NOT on Object.prototype — it's a static method):

```c
// During Object constructor registration in actionInit():
// After creating Object constructor function...
ASFunction* register_class_fn = createNativeFunction(app_context, "registerClass",
    actionRegisterClass);
ActionVar rc_var = { .type = ACTION_STACK_VALUE_FUNCTION };
rc_var.value.function_value = register_class_fn;
setProperty(app_context, object_ctor->own_props, "registerClass", 13, &rc_var);
```

The implementation:
```c
void actionRegisterClass(SWFAppContext* app_context) {
    // Pop args (called as Object.registerClass(symbolName, constructor))
    // Validate: need string arg0, function-or-null arg1
    // Store in registered_classes table
    // Push true/false return value
}
```

### 3c. Lookup function

```c
ASFunction* tagLookupRegisteredClass(const char* symbol_name) {
    for (size_t i = 0; i < registered_class_count; i++) {
        if (strcmp(registered_classes[i].symbol_name, symbol_name) == 0)
            return registered_classes[i].constructor;
    }
    return NULL;
}
```

### Tests fixed by Phase 3

- **register_class_return_value**: 0/12 → 12/12 (just the return value logic)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=register_class_return_value --diff --verbose
```

---

## Phase 4: Constructor Invocation on Placement

**Goal**: When a MovieClip with a registered class is instantiated (via `attachMovie` or timeline placement), invoke the registered constructor with `this` = the clip instance.

### What the tests expect

**clip_constructors** (0/8):
```
Foo:                          ← constructor traces
[object Object]               ← typeof this
_level0.parInst               ← this._parent
end foo
Foo2:
[object Object]
_level0.parInst
end foo2
```

The constructor is called with `this` being the new MovieClip. Inside the constructor, `this` behaves as an object (for `typeof`), but the clip is still a movieclip.

**register_class** (0/68):
After `Object.registerClass("SymbolName", CustomClass)`:
- `attachMovie("SymbolName", "mc", depth)` creates a clip
- `typeof mc` → `"movieclip"` (the clip, not the class)
- The constructor runs: traces "In CustomClass constructor"
- Prototype chain: `mc.__proto__ == CustomClass.prototype`

### 4a. Constructor invocation flow

In `attachMovie` (Phase 2), after placing the sprite and applying initObj:

```c
// Look up registered class for this linkage name
ASFunction* ctor = tagLookupRegisteredClass(linkage_id);
if (ctor) {
    // Set new_mc's __proto__ to constructor's prototype
    new_mc->dynamic_props->__proto__ = ctor->prototype_obj;

    // Call constructor with this = new_mc
    callFunction(app_context, ctor, new_mc, 0, NULL);
}
```

### 4b. Constructor invocation on timeline placement

For clips placed by PlaceObject2 that have a registered class (via ExportAssets linkage):

The challenge is knowing *which export name* a character ID has. When the timeline places sprite char_id=5 and "Clip" was exported as char_id=5, we need to find the registered class for "Clip".

Solution: Build a reverse lookup from char_id → export_name, then look up the registered class:

```c
// In tagPlaceObject2 (tag_stubs.c), after placing a sprite:
const char* export_name = tagLookupExportName(app_context, char_id);
if (export_name) {
    ASFunction* ctor = tagLookupRegisteredClass(export_name);
    if (ctor) {
        // Set __proto__ and call constructor
    }
}
```

Add reverse lookup:
```c
const char* tagLookupExportName(SWFAppContext* app_context, size_t char_id) {
    for (size_t i = 0; i < ng_export_count; i++) {
        if (ng_exports[i].char_id == char_id)
            return ng_exports[i].name;
    }
    return NULL;
}
```

### 4c. Prototype chain setup

When a class is registered for a symbol, clips of that symbol should have their `__proto__` set to the class's prototype. This means:
- `mc.__proto__` = `CustomClass.prototype`
- `mc.__proto__.__proto__` = `MovieClip.prototype` (if the class extends MovieClip)
- `mc instanceof CustomClass` → true (if instanceof is implemented)

The `actionExtends` opcode in the recompiler already sets up `subclass.prototype.__proto__ = superclass.prototype`. So if the AS2 code does `class CustomClass extends MovieClip`, the prototype chain is already correct.

### Tests fixed by Phase 4

- **clip_constructors**: 0/8 → ~6-8/8
- **register_class**: 0/68 → partial (needs child SWF loading for full pass)
- **register_class_return_value**: Already fixed in Phase 3

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=clip_constructors --diff --verbose
```

---

## Phase 5: DoInitAction Ordering + on(construct) Event

**Goal**: Ensure DoInitAction runs at the correct time and the on(construct) clip event fires before the registered class constructor.

### 5a. DoInitAction execution context

Currently, DoInitAction scripts are emitted into `tagInit()` which runs unconditionally at startup. This is *mostly correct* for the common case but:

1. **`this` binding**: During DoInitAction, `this` should reference the clip being initialized. The current implementation runs init scripts with `this` = `_root` (the global context).

2. **Once-per-character**: The spec says DoInitAction runs "only the first time that frame is encountered." Since the recompiler statically places them in `tagInit()`, they already run exactly once. This is correct.

3. **Ordering**: DoInitAction runs before the frame's normal DoAction scripts. The current `tagInit()` → `frame_0()` ordering satisfies this.

The `register_and_init_order` test (233 lines) is the most demanding test here. It expects:
```
b #initclip          ← DoInitAction for sprite "b" runs first
b #endinitclip
aa #initclip         ← DoInitAction for sprite "aa"
aa #endinitclip
a #initclip          ← DoInitAction for sprite "a"
a #endinitclip
c #initclip          ← DoInitAction for sprite "c"
c #endinitclip
a constructor()      ← Timeline places "a", constructor fires
aaclass constructor  ← "aa" (child of "a") gets its constructor
b constructor()      ← Timeline places "b", constructor fires
root first frame     ← Frame 1 DoAction script
```

The ordering shows:
1. All DoInitAction blocks run first (in character definition order)
2. Constructor invocation happens when clips are placed on the timeline
3. Frame scripts run after all placements

### 5b. on(construct) clip event

From the `on_construct` test (0/25):
```
on(construct) start      ← Fires first
  this._name = custom_clip
  customProperty = Custom property from CustomClass  ← prototype is already set
  child = _level0.custom_clip.child                  ← children already exist
on(construct) end
CustomClass() constructor start   ← Fires second
  this._name = custom_clip
  this.customProperty = Custom property from on(construct)  ← modified by on(construct)
CustomClass() constructor end
```

**Execution order for placing a clip**:
1. Place the sprite on the display list (children instantiated)
2. Set `__proto__` to registered class prototype (so prototype properties are accessible)
3. Fire `on(construct)` clip event (ClipAction event 0x40000)
4. Fire registered class constructor
5. Fire `on(load)` clip event

The `on(construct)` event is a ClipAction (from PlaceObject2's ClipActions). The recompiler already parses ClipActions and emits them as script functions. The runtime needs to recognize the construct event flag (0x40000 in AllEventFlags) and call the script before the class constructor.

### 5c. Recompiler changes for construct event

Check if the recompiler already handles the 0x40000 construct event flag in ClipAction parsing. If not:
- Add `CLIP_EVENT_CONSTRUCT = 0x40000` to the event flag definitions
- Emit a `tagPlaceObject2WithClipActions` call that includes the construct handler
- At runtime, store the construct handler function alongside the clip

### Tests fixed by Phase 5

- **register_and_init_order**: 0/233 → ~100-180/233 (partial: some lines depend on child SWF loading)
- **on_construct**: 0/25 → ~20-25/25
- **clip_constructors**: Improved further if not already full from Phase 4
- **do_init_action_child**: 3/12 → still ~3/12 (needs loadMovie for child SWFs)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=register_and_init_order --diff --verbose
python3 ruffle-tests/verify_output.py --test=on_construct --diff --verbose
python3 ruffle-tests/verify_output.py --test=clip_constructors --diff --verbose
```

---

## Files to Modify

### Recompiler (SWFRecomp/)

| File | Changes |
|------|---------|
| `src/swf.cpp` | Parse ExportAssets tag 56 (emit `tagRegisterExport` calls); preserve DoInitAction sprite_id for future use |
| `src/action/action.cpp` | Fix register scoping in DefineFunction2 (only save/restore up to RegisterCount registers); fix register reset across frames |

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | `Object.registerClass()` static method; `attachMovie()` dispatch handler; constructor invocation on placement; register reset per-frame |
| `include/actionmodern/action.h` | New function declarations: `actionRegisterClass`, `tagLookupRegisteredClass`, `tagLookupExportName` |
| `src/libswf/tag_stubs.c` | Export symbol table (`tagRegisterExport`, `tagLookupExport`, `tagLookupExportName`); `tagExecuteSpriteFrame` helper; constructor invocation in `tagPlaceObject2` |
| `include/libswf/tag.h` | New tag function signatures |

---

## Estimated Test Impact

| Phase | Tests Addressed | Est. New Full Passes | Notes |
|-------|----------------|---------------------|-------|
| 0 (Register fixes) | 2 | 2 | register_underflow, register_globals_across_frames |
| 1 (ExportAssets) | 0 | 0 | Infrastructure only |
| 2 (attachMovie) | 5 | 2-3 | export_assets, attach_movie improvements |
| 3 (registerClass) | 1 | 1 | register_class_return_value |
| 4 (Constructors) | 2 | 1-2 | clip_constructors, register_class partial |
| 5 (DoInit/Construct) | 3 | 1-2 | register_and_init_order, on_construct |
| **Total** | **13** | **~7-10** | |

Tests that won't fully pass due to external dependencies:
- `register_class` and `register_class_swf6` — need child SWF loading (`child.swf`, `child_swf6.swf`)
- `register_class_with_sound` — known_failure in Ruffle itself + needs Sound class
- `register_and_init_order` — large test, some parts need attachMovie from frame scripts
- `do_init_action_child` — needs MovieClipLoader for child SWF loading

---

## Design Decisions

1. **Export symbol table location**: In `tag_stubs.c` alongside existing `ng_sprites[]`, `ng_textfields[]` arrays. Same pattern — static array with linear scan lookup. 128 entries is sufficient (real SWFs rarely export more than 50 symbols).

2. **RegisterClass registry location**: In `action.c` alongside other runtime global state. The registry maps string names to `ASFunction*` pointers. Since constructor functions are GC-managed (reference counted), storing pointers directly is safe as long as the registered class holds a reference.

3. **Constructor invocation timing**: The SWF spec and Ruffle's behavior specify a precise ordering: place children → set prototype → on(construct) → constructor → on(load). Getting this exactly right is important for `register_and_init_order` but the basic flow works even if the exact ordering between nested constructors has minor deviations.

4. **Case sensitivity**: ExportAssets lookups follow SWF version semantics — case-insensitive for SWF6 and below, case-sensitive for SWF7+. The `register_class_swf6` test specifically checks this. The `tagLookupExport` function needs the SWF version to choose comparison mode.

5. **Relationship to MOVIECLIP_PLAN.md**: This plan overlaps with Phases 4 and 6 of the MovieClip plan. The ExportAssets + attachMovie work here is the same as MovieClip Phase 4. The registerClass + constructor work here is the same as MovieClip Phase 6. This plan provides more detailed implementation notes specific to the register_class tests, while MOVIECLIP_PLAN.md has broader context for all MovieClip features.

---

## Quick Win Estimate

**Phase 0 alone** (VM register fixes) fixes 2 tests with minimal code changes — just register scoping in DefineFunction2 and register reset per frame. These are isolated bugs unrelated to the RegisterClass feature.

**Phases 0-3** (register fixes + ExportAssets + attachMovie + registerClass return values) would fix ~5-6 tests and significantly improve match rates on several more. This is the minimum viable set to demonstrate the export/register/attach pipeline working.
