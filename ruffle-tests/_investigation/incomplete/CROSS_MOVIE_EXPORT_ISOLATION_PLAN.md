# Cross-Movie Export Table Isolation Plan
<!-- TESTS: loadmovie_registerclass -->

Last updated: 2026-03-11

## Status: **COMPLETE** — loadmovie_registerclass 31/31 PASS

### Implementation Summary (2026-03-11)

Two-part fix: compile-time char_id offsetting + runtime per-movie export isolation.

**Part A — Char_id Offsetting** (`verify_output.py`):
- Each child SWF gets char_ids offset by `movie_id * 1000` (child 1 → +1000, child 2 → +2000, etc.)
- Applied to all tag definition/placement calls in generated tagMain.c via regex
- `INITIAL_DICTIONARY_CAPACITY` increased from 1024 to 8192 to accommodate offsets

**Part B — Per-Movie Export Table** (runtime):
- Added `movie_id` field to `ng_exported_symbols[]` entries, `MovieEntry`, and `MovieClip` structs
- `tagRegisterExport` stores `g_current_movie_id` with each export
- `ng_lookupExportForMovie(name, movie_id)` searches only within that movie's exports
- Both `attachMovie` call sites (CallFunction + CallMethod) use `mc->movie_id` for scoped lookup
- All 6 child loading paths save/restore `g_current_movie_id` and set `mc->movie_id = entry->movie_id`

**Files changed**: `swf.h` (MovieEntry.movie_id, INITIAL_DICTIONARY_CAPACITY), `action.h` (MovieClip.movie_id), `tag.h` (new function decls), `tag_stubs.c` (export registry + movie_id), `action.c` (6 child load paths + 2 attachMovie paths), `verify_output.py` (char_id offsetting + movie_id in MovieEntry)

**Regression tests**: 20+ tests verified passing including all multi-SWF tests.

## Problem Statement

When a child SWF is loaded into a MovieClip, its character definitions (sprites, shapes)
and export table entries **overwrite** the parent movie's definitions because both share a
single global `dictionary[]` array and `ng_exported_symbols[]` registry.

This causes `attachMovie` to fail when trying to use exports from the **parent** movie
after a child has been loaded, because the parent's char_ids have been overwritten by the
child's character definitions.

### Concrete Failing Test: `loadmovie_registerclass` (27/31)

**Test structure:**
- **Parent (test.swf)**: Defines `original_movie_clip` (char 1, sprite) and
  `__Packages.CustomClip` (char 2, sprite). Stores `registerOriginal` and `testOriginal`
  functions on `_global`. Loads `target.swf` into a child MC.
- **Child (target.swf)**: Defines its own shapes/sprites (char 1=shape, 2=sprite,
  3=sprite "clip", 4=sprite `__Packages.CustomClip`). The child's `frame_0` calls
  `registerOriginal()` (parent's function) and then `testOriginal()` (parent's function).

**What happens:**
1. Parent's `tagInit` runs: `dictionary[1]` = SPRITE, `dictionary[2]` = SPRITE.
   Exports: `"original_movie_clip"` → char 1, `"__Packages.CustomClip"` → char 2.
2. Child loads. Child's `tagInit` runs:
   - `tagDefineSprite(2, ...)` → **overwrites** parent's `dictionary[2]`
   - `tagDefineSprite(3, ...)` → new char_id (no conflict)
   - `tagRegisterExport("__Packages.CustomClip", 4)` → **overwrites** parent's export
   - `tagDefineSprite(4, ...)` → new char_id
3. Child's `frame_0` runs:
   - `tagDefineShape(1, ...)` → **overwrites** parent's `dictionary[1]` (was SPRITE, now SHAPE)
4. Parent's `testOriginal()` calls `attachMovie("original_movie_clip", ...)`:
   - `ng_lookupExport("original_movie_clip")` → char_id 1 (correct lookup)
   - `dictionary[1]` is now SHAPE (overwritten by child) → `ng_attachMovie` fails
   - Result: `undefined` instead of `_level0.original_movie_custom_clip`

**4 missing/wrong output lines:**
```diff
  // original_clip_from_target instanceof CustomClip
  false

+ // this.box                               ← missing (constructor didn't run)
+ undefined                                 ← missing
+
  // original_clip_from_original
- undefined                                 ← should be _level0.original_movie_custom_clip
+ _level0.original_movie_custom_clip

  // original_clip_from_original instanceof CustomClip
- false                                     ← should be true
+ true
```

## Root Cause Analysis

Two global data structures lack movie-level scoping:

### 1. Character Dictionary (`dictionary[]` in tag.c)

```c
// tag.c:34
size_t dictionary_capacity = INITIAL_DICTIONARY_CAPACITY;
// Used everywhere as: dictionary[char_id].type, .sprite_frame_funcs, etc.
```

A single flat array indexed by char_id. Both parent and child write to the same slots.
Char_ids are assigned per-SWF by the SWF compiler (Flash IDE), so different SWFs routinely
reuse char_ids 1, 2, 3, etc.

### 2. Export Symbol Registry (`ng_exported_symbols[]` in tag_stubs.c)

```c
// tag_stubs.c:190-196
static struct {
    char name[128];
    size_t char_id;
    u8 swf_version;
} ng_exported_symbols[MAX_EXPORTED_SYMBOLS];
```

Last-write-wins for duplicate export names. When child registers `"__Packages.CustomClip"`,
it shadows the parent's registration of the same name.

### How Ruffle Solves This

In Ruffle, each loaded SWF movie gets its own `MovieLibrary` (in `core/src/library.rs`):
- Each library has its own `characters: HashMap<CharacterId, Character>` (char definitions)
- Each library has its own `export_characters: PropertyMap<CharacterId>` (exports)
- `attachMovie` calls `library_for_movie(movie_clip.movie())` — looks up exports in the
  **MovieClip's own movie's library**, not a global table
- `movie_clip.movie()` returns the SWF that *defines* the MovieClip
- `registerClass` is global (not per-movie) — just case-sensitive vs case-insensitive registries

## Solution Design

### Approach: Compile-Time Char_ID Offsetting + Per-Movie Export Tables

Since our architecture pre-compiles SWFs to C, we can solve this at two levels:

#### Part A: Char_ID Offsetting (verify_output.py)

Offset child SWF char_ids at compile time to avoid dictionary collisions.

1. Parse the parent SWF's max char_id from its `tagMain.c` (find highest char_id in
   tagDefineSprite/tagDefineShape/etc. calls)
2. For each child SWF, offset all char_ids by `parent_max_char_id + 1` (or a large fixed
   offset like 1000 per movie)
3. Apply offset to: `tagDefineSprite(char_id, ...)`, `tagDefineShape(char_id, ...)`,
   `tagDefineMorphShape(char_id, ...)`, `tagDefineEditText(char_id, ...)`,
   `tagDefineButton(char_id, ...)`, `tagRegisterExport(name, char_id)`,
   `tagPlaceObject2(depth, char_id, ...)` and all placement variants
4. Store the offset in `MovieEntry` so runtime can map back if needed

**Implementation in `generate_child_movie_file()`:**
```python
# After reading child's tagMain.c, apply char_id offset
# Find all integer literal char_id arguments in tag function calls
# Replace with offset values
```

**Affected tag calls (char_id is always the 2nd argument after app_context):**
- `tagDefineSprite(app_context, CHAR_ID, ...)`
- `tagDefineShape(app_context, CHAR_TYPE_*, CHAR_ID, ...)` — 3rd arg
- `tagDefineMorphShape(app_context, CHAR_ID, ...)`
- `tagDefineEditText(app_context, CHAR_ID, ...)`
- `tagDefineButton(app_context, CHAR_ID, ...)`
- `tagRegisterExport(app_context, "name", CHAR_ID)`
- `tagPlaceObject2(app_context, DEPTH, CHAR_ID, ...)` — 3rd arg
- `tagPlaceObject2Ratio(app_context, DEPTH, CHAR_ID, ...)` — 3rd arg
- Various PlaceObject2 variants with clip actions, transforms, etc.

**Risk:** Char_id appears as a positional integer literal in generated C code. A regex-based
approach needs to correctly identify which argument is the char_id for each function
signature. The safest approach is probably to add a `#define CHAR_ID_OFFSET N` to the
child wrapper and use arithmetic: `tagDefineSprite(app_context, 2 + CHAR_ID_OFFSET, ...)`.

#### Part B: Per-Movie Export Table (Runtime)

Make `ng_lookupExport` context-aware so `attachMovie` looks up exports in the correct
movie's export table.

**Option B1: Movie ID tagging (simplest)**

Add a `movie_id` field to export entries and filter by movie_id during lookup:

```c
static struct {
    char name[128];
    size_t char_id;
    u8 swf_version;
    u8 movie_id;       // 0 = main, 1+ = child movies
} ng_exported_symbols[MAX_EXPORTED_SYMBOLS];

// Global tracking which movie is currently initializing
static u8 g_current_movie_id = 0;

// Lookup: search exports matching the given movie_id first,
// fall back to movie_id 0 (main) if not found
size_t ng_lookupExportForMovie(const char* name, u8 movie_id);
```

The `attachMovie` call sites need to know which movie's exports to search. This comes from
the MovieClip that `attachMovie` is called on — specifically, which movie *defined* that
MovieClip's character.

**Key question:** How does the runtime know which movie a MovieClip belongs to?

In Ruffle, each MovieClip stores a reference to its `SwfMovie`. In our runtime, MovieClips
don't currently track which movie they came from. We'd need to add a `movie_id` field to
`MovieClip` (or `DisplayObject`) and set it during placement.

**Option B2: Simpler — caller-context based lookup**

Since `attachMovie` is always called from ActionScript, and ActionScript closures track
`base_clip`, we can use `g_current_context->movie_id` (or a global
`g_current_movie_id` set during child init) to determine which export table to search.

However, this doesn't work for the `testOriginal()` case: `testOriginal` was defined in the
parent movie (movie_id=0), its `base_clip` is the root MC (movie_id=0), but it's called from
the child movie's script. Since `base_clip` is parent's MC, `g_current_context` would be
the parent's context → correct movie_id=0 → would find parent's exports. **This actually
works!**

Wait — re-examining: when `testOriginal()` is called, `g_current_context` switches to
`func->base_clip` (the root MC). The root MC's movie_id would be 0 (main movie). So
`ng_lookupExportForMovie("original_movie_clip", 0)` would find the parent's export. This
is correct.

And when child's script does `attachMovie("clip", ...)` directly, `g_current_context` is the
child MC (loaded into "target"). The child MC's movie_id would be 1. So
`ng_lookupExportForMovie("clip", 1)` would find the child's export. Also correct.

**Option B2 is viable and simpler.** The movie_id is determined by `g_current_context`
at the time of `attachMovie` call.

#### Part C: MovieClip movie_id Tracking

Add `u8 movie_id` to `MovieClip` struct. Set it:
- During `tagPlaceObject2` (inherit from parent or set to `g_current_movie_id`)
- During `ng_attachMovie` (inherit from parent MC)
- During child movie init (set `g_current_movie_id` before running child's tagInit/frames)

Then in `attachMovie`:
```c
u8 mc_movie_id = mc->movie_id;  // mc is the MovieClip attachMovie is called on
size_t char_id = ng_lookupExportForMovie(export_name, mc_movie_id);
```

Wait, but the test shows that the **parent's** `testOriginal()` function calls
`this.attachMovie(...)` where `this` is the parent's root MC (movie_id=0), and it should
find exports from movie_id=0. Meanwhile, the child's direct call to
`this.attachMovie("clip", ...)` has `this` = child MC (movie_id=1), finding child exports.
This would work correctly.

BUT: What about the case where child's script calls `attachMovie("original_movie_clip", ...)`
on itself? Expected: `undefined` (child doesn't have that export). With movie_id scoping:
child MC has movie_id=1, lookup in movie_id=1 → not found → returns undefined. Correct!

### Implementation Steps

#### Step 1: Compile-Time Char_ID Offsetting

In `verify_output.py`'s `generate_child_movie_file()`:

1. Parse parent's max char_id from parent's `tagMain.c`
2. Calculate offset: `child_char_id_offset = parent_max_char_id + 1`
3. In the child's tagMain.c content, regex-replace char_id arguments in all tag calls:
   - For `tagDefineSprite(app_context, N, ...)` → replace N with N+offset
   - For `tagDefineShape(app_context, TYPE, N, ...)` → replace N with N+offset
   - For `tagRegisterExport(app_context, "name", N)` → replace N with N+offset
   - For `tagPlaceObject2(app_context, DEPTH, N, ...)` → replace N with N+offset
   - (and all other placement/definition variants)
4. Store offset in MovieEntry: `.char_id_offset = offset`

**Alternative (simpler):** Instead of regex parsing positional args, emit a
`#define CHILD_CHAR_OFFSET N` and change the generated child code to use
`(original_id + CHILD_CHAR_OFFSET)` expressions. This is safer than regex but requires
modifying the child's tagMain content more invasively.

**Simplest alternative:** Use a large fixed offset per child (1000 for child 1, 2000 for
child 2, etc.). This avoids needing to parse the parent's max char_id and is safe as long
as no single SWF has >1000 characters (extremely unlikely in practice).

#### Step 2: Movie ID in Export Registry

In `tag_stubs.c`:

1. Add `u8 movie_id` field to `ng_exported_symbols` entries
2. Add `u8 g_current_movie_id` global (set by runtime during movie init)
3. `tagRegisterExport` stores `g_current_movie_id` alongside the export
4. Add `ng_lookupExportForMovie(name, movie_id)`: searches exports with matching movie_id
   first, does NOT fall back to other movies (each movie's exports are isolated)
5. Existing `ng_lookupExport(name)` can remain as a fallback that returns any match
   (or be removed if not needed)

In `action.c` (movie init path):

6. Before child movie init: `g_current_movie_id = child_movie_id`
7. After child movie init: restore `g_current_movie_id`

#### Step 3: Movie ID on MovieClip

In `swf.h`:

1. Add `u8 movie_id` to `MovieClip` struct

In `tag.c`:

2. `tagPlaceObject2` and variants: `new_mc->movie_id = g_current_movie_id`

In `action.c`:

3. `ng_attachMovie`: `attached_mc->movie_id = parent_mc->movie_id`
   (attached clips belong to same movie as their parent)
4. `attachMovie` handler: use `mc->movie_id` for `ng_lookupExportForMovie`

#### Step 4: Movie ID in MovieEntry

In `swf.h`:

1. Add `u8 movie_id` to `MovieEntry` struct

In `verify_output.py`:

2. Assign sequential movie_ids: main = 0, first child = 1, second child = 2, etc.
3. Emit `.movie_id = N` in generated MovieEntry structs

In `action.c` (child load path):

4. When loading child movie: `g_current_movie_id = entry->movie_id`

### Testing

After implementation:
- `loadmovie_registerclass` should go from 27/31 → 31/31
- All existing passing multi-SWF tests must remain passing (regression check)
- Key tests to verify: `loadmovie`, `register_class`, `register_class_swf6`,
  `do_init_action_child`, `global_swf5_6_7_8_9`, `global_swf6_7_8`

### Risk Assessment

**Low risk:**
- Char_id offsetting is purely compile-time in verify_output.py
- movie_id is a new field, doesn't affect existing single-SWF tests (movie_id=0 everywhere)
- Existing `ng_lookupExport` callers outside of `attachMovie` continue to work

**Medium risk:**
- The regex-based char_id replacement in generated tagMain.c needs to handle all placement
  tag variants correctly. Missing a variant would cause display issues.
- Multiple child SWFs (e.g., `global_swf5_6_7_8_9` with 5 children) need unique offsets.

**Key insight from Ruffle:**
- `registerClass` is NOT per-movie (it's global, just split by case-sensitivity). Our
  existing implementation is already correct here.
- Only the export→char_id mapping and char_id→definition mapping need movie scoping.

### Files to Modify

| File | Changes |
|------|---------|
| `ruffle-tests/verify_output.py` | Char_id offsetting in `generate_child_movie_file()`, movie_id in MovieEntry |
| `SWFModernRuntime/include/libswf/swf.h` | Add `movie_id` to MovieClip and MovieEntry structs |
| `SWFModernRuntime/src/libswf/tag_stubs.c` | Movie ID in export registry, `ng_lookupExportForMovie()` |
| `SWFModernRuntime/src/libswf/tag.c` | Set movie_id on placed MovieClips |
| `SWFModernRuntime/src/actionmodern/action.c` | Set `g_current_movie_id` during child init, use movie_id in `attachMovie` |
