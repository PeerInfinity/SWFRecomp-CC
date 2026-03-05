# Clone/Duplicate MovieClip Implementation Plan
<!-- TESTS: duplicate_movie_clip, clone_sprite_types, clone_sprite_edittext, clone_sprite_edittext_dynamic, duplicate_movie_clip_drawing, clip_events, clip_event_propagation_order, on_construct -->

Last updated: 2026-02-27

## Overview

Clone/Duplicate MovieClip covers 5 failing Ruffle tests. The core feature is `ActionCloneSprite` (opcode 0x24), which duplicates an existing display list object, giving the copy a new name and depth. The AS2 method wrapper is `MovieClip.duplicateMovieClip(name, depth, initObj)`.

**Current state (as of 2026-03-04)**:
- `duplicate_movie_clip` (21/21) ✅ — DONE
- `clone_sprite_types` (25/25) ✅ — DONE
- `clone_sprite_edittext` (MISMATCH ~15-20/95) — BLOCKED: TextField clone init + position reading
- `clone_sprite_edittext_dynamic` (MISMATCH ~15-20/87) — BLOCKED: same
- `duplicate_movie_clip_drawing` (2 lines off) — DEFERRED: needs Drawing API _width/_height from drawn content
- `clip_events` ✅ — PASS (fixed by prior commits)
- `clip_event_propagation_order` (0/17) — BLOCKED: needs mouse events (MOUSE_EVENTS_PLAN) + recursive clip event dispatch
- `on_construct` (25/25) ✅ — DONE (RegisterClass prototype setup + on(construct) event dispatch)

**4/8 PASS.** Phase 1 is fully complete. Phase 2 is blocked on TextField clone infrastructure. `on_construct` now PASS (25/25) — RegisterClass prototype setup + on(construct) event dispatch implemented. `clip_event_propagation_order` still blocked on mouse events.

**Key implementation notes discovered during Phase 1**:
- `duplicateMovieClip` registers clones via `setVariableByName` so `GetVariable("clip")` works
- A `clone_depth_table` tracks which variable name occupies each SWF depth. When a new clone takes an occupied SWF depth, the old variable is cleared to undefined. This is needed because `duplicateMovieClip(name, 0)` uses SWF depth `0+16384=16384`, and a subsequent `CloneSprite(src, clip1, 16384)` at the same SWF depth must evict "clip" → undefined.
- `tagPlaceObject2WithClipActions` is implemented in `tag.c` (already done, forwards to `tagPlaceObject2` and stores clip_actions)
- onLoad fires for CloneSprite clones via the pending load queue, not for duplicateMovieClip clones

**Key insight**: This is entirely a runtime problem — the recompiler already emits the correct code. The core implementation is in `tag_stubs.c` (NO_GRAPHICS display list) and `action.c` (CloneSprite + duplicateMovieClip method).

## SWF Spec Reference

From `SWFRecompDocs/specs/swf-spec-19.txt` lines 5575-5599:

> **ActionCloneSprite (0x24)**:
> 1. Pops a depth off the stack.
> 2. Pops a target off the stack.
> 3. Pops a source off the stack.
> 4. Duplicates the movie clip source, giving the new instance the name target, at z-order depth.

> **ActionRemoveSprite (0x25)**:
> 1. Pops a target off the stack.
> 2. Removes the clone movie clip that the target path identifies.

The AS2 method: `movieClip.duplicateMovieClip(newName: String, depth: Number, initObject?: Object) → MovieClip`

---

## Test Inventory (5 tests)

### Phase 1 Tests — Prerequisites + Core CloneSprite (~2 tests)

- **duplicate_movie_clip** (0/21): Tests `mc.duplicateMovieClip()` method, property copying, initObject, valueOf/toString coercion on args, and onLoad clip events. Currently produces zero output because `tagPlaceObject2WithClipActions` is a no-op.
- **clone_sprite_types** (12/25): Clones 8 timeline-placed types + 2 script-created objects. Tests which types produce accessible clones vs `undefined`.

### Phase 2 Tests — EditText Clones (~2 tests, depends on TextField plan)

- **clone_sprite_edittext** (~0/95): Clones timeline-placed EditTexts. Compares original vs clone properties (position, formatting, TextFormat). Heavily depends on TextField/TextFormat implementation (Phases 1+2 of TEXTFIELD_PLAN.md).
- **clone_sprite_edittext_dynamic** (~0/87): Same but with dynamically-created (createTextField) EditTexts.

### Deferred Tests — Drawing API (~1 test)

- **duplicate_movie_clip_drawing** (SEGFAULT): Needs Drawing API (beginFill/moveTo/lineTo) and `_width`/`_height` from drawn content. Not implementable without Drawing API.

---

## Phase 1: Prerequisites, Core CloneSprite, duplicateMovieClip

**Goal**: Fix `tagPlaceObject2WithClipActions` (a prerequisite blocker), implement clip action dispatch, implement `actionCloneSprite` cloning logic in NO_GRAPHICS mode, implement `duplicateMovieClip` as a CallMethod handler, and fix non-scriptable type discrimination.

### 1a. Fix tagPlaceObject2WithClipActions (prerequisite)

**Problem**: `tagPlaceObject2WithClipActions()` in `tag_stubs.c` is a complete no-op. It doesn't forward to `tagPlaceObject2` and doesn't store clip actions. This means any sprite placed with clip actions (onLoad, onEnterFrame, etc.) never enters the display list.

The `duplicate_movie_clip` test places its source sprite via `tagPlaceObject2WithClipActions(app_context, 1, 3, 2, 0, 0, clip_actions_12, 1)`. Since this is a no-op, the sprite "src" never exists and the test outputs nothing.

**Fix**:

1. Add clip action fields to the `ng_display` struct:
```c
static struct {
    // ... existing fields ...
    ClipAction* clip_actions;   // pointer to clip_actions array (from tagMain.c)
    size_t clip_action_count;   // number of clip actions
} ng_display[MAX_DISPLAY_NG];
```

2. Implement `tagPlaceObject2WithClipActions` to forward to `tagPlaceObject2` and store clip actions:
```c
void tagPlaceObject2WithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, ClipAction* clip_actions, size_t clip_action_count)
{
    tagPlaceObject2(app_context, depth, char_id, transform_id, cxform_id, clip_depth);
    // Find the ng_display entry we just placed and store clip actions
    for (size_t i = 0; i < ng_display_count; i++) {
        if (ng_display[i].depth == depth) {
            ng_display[i].clip_actions = clip_actions;
            ng_display[i].clip_action_count = clip_action_count;
            break;
        }
    }
}
```

3. Initialize `clip_actions = NULL` and `clip_action_count = 0` for all new ng_display entries in `tagPlaceObject2`.

### 1b. Implement clip action dispatch (onLoad)

**Problem**: Even after placing sprites with clip actions, the actions never fire.

The `duplicate_movie_clip` test expects onLoad to fire for sprites (the clip_action has `event_flags = 0x1` = onLoad). The `clip_action_2` function traces `"load: " + this._name`.

**ClipAction event flag bitmask** (from SWF spec):
- `0x00000001` — onLoad
- `0x00000002` — onEnterFrame
- `0x00000004` — onUnload
- `0x00000008` — onMouseMove
- `0x00000010` — onMouseDown
- `0x00000020` — onMouseUp
- `0x00000040` — onKeyDown
- `0x00000080` — onKeyUp
- `0x00000100` — onData
- `0x00000200` — onInitialize (SWF6+)
- `0x00000400` — onConstruct (SWF7+)

**Implementation**: After executing frame 0 of a newly-placed sprite (in `tagShowFrame` or `ng_exec_sprite_frame`), fire any onLoad clip actions. The pattern:

```c
// In tagShowFrame, after executing needs_init sprites:
for (size_t i = 0; i < ng_display_count; i++) {
    if (!ng_display[i].needs_init) continue;
    ng_display[i].needs_init = 0;
    ng_exec_sprite_frame(app_context, i, 0);
    // Fire onLoad clip actions
    if (ng_display[i].clip_actions) {
        for (size_t j = 0; j < ng_display[i].clip_action_count; j++) {
            if (ng_display[i].clip_actions[j].event_flags & 0x1) { // onLoad
                // Execute in the sprite's context
                MovieClip* saved_ctx = g_current_context;
                const char* inst_name = ng_display[i].instance_name;
                MovieClip* sprite_mc = actionFindOrCreateMovieClip(app_context, inst_name, &root_movieclip);
                actionSetCurrentContext(sprite_mc);
                ng_display[i].clip_actions[j].action(app_context);
                actionSetCurrentContext(saved_ctx);
            }
        }
    }
}
```

**Note**: The test expects onLoad to fire for the SOURCE clip too (it was placed with clip actions), and also for all CLONES of that clip. When we clone a sprite, we should copy the clip_actions pointer to the clone's display entry so onLoad fires on the clone too.

### 1c. Implement actionCloneSprite in NO_GRAPHICS mode

Replace the debug-logging stub with actual cloning logic.

**Stack handling fix**: The current code reads source as a raw char* pointer. But the source is typically pushed via `GetVariable` which produces a MOVIECLIP-typed stack value. We need to handle both string and MovieClip types:

```c
void actionCloneSprite(SWFAppContext* app_context)
{
    // Pop depth
    convertFloat(app_context);
    ActionVar depth_var;
    popVar(app_context, &depth_var);
    int depth = (int)VAL(float, &depth_var.data.numeric_value);

    // Pop target name (new clone's name)
    toString(app_context);  // ensure string
    ActionVar target_var;
    popVar(app_context, &target_var);
    const char* target_name = (const char*) target_var.data.numeric_value;
    if (!target_name) target_name = "";

    // Pop source — could be string path or MovieClip reference
    ActionVar source_var;
    popVar(app_context, &source_var);
    const char* source_name = NULL;
    if (source_var.type == ACTION_STACK_VALUE_MOVIECLIP) {
        MovieClip* src_mc = (MovieClip*) VAL(u64, &source_var.data.numeric_value);
        if (src_mc) source_name = src_mc->name;
    } else {
        // Convert to string for path lookup
        source_name = (const char*) source_var.data.numeric_value;
    }
    if (!source_name) source_name = "";

    // Call shared implementation
    ng_cloneSprite(app_context, source_name, target_name, depth);
}
```

**Core cloning logic** (new function in `tag_stubs.c`, exposed via `tag.h`):

```c
void ng_cloneSprite(SWFAppContext* app_context, const char* source_name,
                    const char* target_name, int depth)
{
    // 1. Find source in ng_display by instance_name
    size_t src_idx = SIZE_MAX;
    for (size_t i = 0; i < ng_display_count; i++) {
        if (ng_display[i].instance_name[0] != '\0' &&
            strcmp(ng_display[i].instance_name, source_name) == 0) {
            src_idx = i;
            break;
        }
    }
    // If not found, try extracting last path component (e.g. "_level0.clip" → "clip")
    if (src_idx == SIZE_MAX) {
        const char* dot = strrchr(source_name, '.');
        if (dot) { /* retry with dot+1 */ }
    }
    if (src_idx == SIZE_MAX) return; // source not found, no-op

    // 2. Check if target depth already occupied — remove existing
    for (size_t i = 0; i < ng_display_count; i++) {
        if (ng_display[i].depth == (size_t)depth) {
            // Remove existing entry at this depth
            for (size_t j = i; j + 1 < ng_display_count; j++)
                ng_display[j] = ng_display[j + 1];
            ng_display_count--;
            if (src_idx > i) src_idx--;  // adjust if source shifted
            break;
        }
    }

    // 3. Create new ng_display entry
    if (ng_display_count >= MAX_DISPLAY_NG) return;
    size_t clone_idx = ng_display_count++;
    ng_display[clone_idx] = ng_display[src_idx]; // copy all flags
    ng_display[clone_idx].depth = (size_t)depth;
    strncpy(ng_display[clone_idx].instance_name, target_name, 63);
    ng_display[clone_idx].instance_name[63] = '\0';
    ng_display[clone_idx].current_frame = 0;
    ng_display[clone_idx].is_playing = ng_display[src_idx].is_playing;
    // Copy clip actions from source
    ng_display[clone_idx].clip_actions = ng_display[src_idx].clip_actions;
    ng_display[clone_idx].clip_action_count = ng_display[src_idx].clip_action_count;
    // Mark for frame 0 execution if it's a sprite
    ng_display[clone_idx].needs_init = (ng_display[src_idx].sprite_idx != (size_t)-1) ? 1 : 0;

    // 4. Create MovieClip object for the clone (only for scriptable types)
    int is_scriptable = (ng_display[src_idx].sprite_idx != (size_t)-1) ||
                        ng_display[src_idx].is_button ||
                        ng_display[src_idx].is_textfield;
    // Note: "video" type needs separate handling if we add it

    if (is_scriptable) {
        MovieClip* src_mc = NULL;
        // Find source MovieClip by name
        // ... look up in child_mc_cache ...

        MovieClip* clone_mc = createMovieClip(target_name, &root_movieclip);
        if (src_mc) {
            // Copy positional properties
            clone_mc->x = src_mc->x;
            clone_mc->y = src_mc->y;
            clone_mc->xscale = src_mc->xscale;
            clone_mc->yscale = src_mc->yscale;
            clone_mc->rotation = src_mc->rotation;
            clone_mc->alpha = src_mc->alpha;
            clone_mc->visible = src_mc->visible;
        }
        // Copy transform-based position from source's transform_id
        clone_mc->last_transform_id = ng_display[src_idx].transform_id;
        // Do NOT copy dynamic_props (custom properties start fresh)
        clone_mc->currentframe = 1;
        clone_mc->totalframes = 1;
        if (ng_display[src_idx].sprite_idx != (size_t)-1) {
            clone_mc->totalframes = ng_sprites[ng_display[src_idx].sprite_idx].frame_count;
            clone_mc->framesloaded = clone_mc->totalframes;
        }
        // Add to child cache
    }
}
```

**Properties that ARE copied from source to clone**:
- `_x`, `_y` (position from transform)
- `_xscale`, `_yscale` (scale)
- `_rotation`, `_alpha`, `_visible`
- `_currentframe` resets to 1 (NOT copied)
- Sprite frame functions (shared via `sprite_idx`)
- Clip actions (shared pointer)

**Properties that are NOT copied**:
- Dynamic properties (custom props like `foo` — `dynamic_props` starts as NULL)
- `_currentframe` (resets to 1)

### 1d. Implement duplicateMovieClip method (CallMethod handler)

Add handler in the MovieClip method dispatch in `actionCallMethod`:

```c
else if (method_name_len == 18 && strncmp(method_name, "duplicateMovieClip", 18) == 0)
{
#ifdef NO_GRAPHICS
    if (num_args >= 2) {
        const char* new_name = "";
        if (args[0].type == ACTION_STACK_VALUE_STRING)
            new_name = (const char*) args[0].data.numeric_value;
        int depth_val = (int) varToDouble(&args[1]);

        // Call shared clone implementation
        ng_cloneSprite(app_context, mc->name, new_name, depth_val);

        // Apply initObject (optional third argument)
        if (num_args >= 3 && args[2].type == ACTION_STACK_VALUE_OBJECT) {
            MovieClip* clone = actionFindOrCreateMovieClip(app_context, new_name, &root_movieclip);
            if (clone) {
                ASObject* init_obj = (ASObject*) VAL(u64, &args[2].data.numeric_value);
                // Copy all properties from initObject to clone's dynamic_props
                // ... enumerate init_obj properties and set on clone ...
            }
        }

        // Return reference to the clone
        MovieClip* result_mc = actionFindOrCreateMovieClip(app_context, new_name, &root_movieclip);
        if (result_mc) {
            if (args) FREE(args);
            ActionVar result = {0};
            result.type = ACTION_STACK_VALUE_MOVIECLIP;
            VAL(u64, &result.data.numeric_value) = (u64)result_mc;
            pushVar(app_context, &result);
            return;
        }
    }
    if (args) FREE(args);
    pushUndefined(app_context);
#else
    if (args) FREE(args);
    pushUndefined(app_context);
#endif
    return;
}
```

### 1e. Fix non-scriptable type discrimination

**Problem**: Currently, `findOrCreateMovieClip` creates a MovieClip for ANY instance name found in `ng_display`, regardless of type. This makes shapes, static text, morph shapes, and images appear as scriptable MovieClips when they should resolve to their parent (`_level0`).

**Expected behavior** (from `clone_sprite_types`):
- Buttons, EditTexts, Sprites, Videos → scriptable, resolve to `_level0.<name>`
- Shapes, StaticText, MorphShapes, Images → NOT scriptable, resolve to `_level0` (parent)

**Fix**: In `findOrCreateMovieClip` (action.c), when looking up an instance name via `ng_findDisplayEntryByName`, check if the entry at that depth is a scriptable type before creating a MovieClip:

```c
// In findOrCreateMovieClip:
size_t depth = ng_findDisplayEntryByName(instance_name);
if (depth != SIZE_MAX) {
    // Check if this is a scriptable type
    if (!ng_isScriptableAtDepth(depth)) {
        return NULL; // Not scriptable, don't create MC
    }
}
```

Add new helper in `tag_stubs.c`:
```c
int ng_isScriptableAtDepth(size_t depth)
{
    for (size_t i = 0; i < ng_display_count; i++) {
        if (ng_display[i].depth == depth) {
            return ng_display[i].is_button ||
                   ng_display[i].is_textfield ||
                   ng_display[i].sprite_idx != (size_t)-1;
            // Note: video type needs separate flag if added
        }
    }
    return 0;
}
```

**Caveat**: This may break some tests that currently work because they assume all named objects are scriptable. Need to test carefully. The key issue is that `clone_sprite_types` expects:
- `trace(timeline_statictext)` → `_level0` (resolves to root because statictext isn't a MC)
- `trace(timeline_shape)` → `_level0` (same)

But currently it outputs `_level0.timeline_statictext` because we create a MC for it.

### 1f. Position copying from transform_data

In NO_GRAPHICS mode, `_x` and `_y` are derived from `transform_data[transform_id]` in the display list. When a clone is created, it should inherit the source's transform values.

The `duplicate_movie_clip` test expects `clip1._x = 50` after cloning `src` which had its `_x` set to 50 before cloning. Dynamic `_x` changes are stored on the MovieClip struct (mc->x), not in transform_data. So we need to copy `mc->x/y` from the source MC to the clone MC.

For the position from the initial tag placement (transform_data), the clone shares the same `transform_id` as the source, which gives it the same initial position. But if `_x` was dynamically changed on the source, the clone should pick up that changed value.

### Tests fixed by Phase 1

- **duplicate_movie_clip**: From 0/21 → ~16-18/21 (remaining issues: valueOf/toString coercion ordering edge cases, detailed onLoad ordering)
- **clone_sprite_types**: From 12/25 → ~22-24/25 (remaining: video type handling if not yet implemented)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=duplicate_movie_clip --diff --verbose
python3 ruffle-tests/verify_output.py --test=clone_sprite_types --diff --verbose
```

### Other tests potentially affected

The `tagPlaceObject2WithClipActions` fix and clip action dispatch (1a + 1b) may fix or improve other tests that use clip events:
- **clip_events** (1/19): Uses onLoad, onEnterFrame, onUnload clip events
- **clip_event_propagation_order** (0/17): Parent-child clip event ordering
- **on_construct** (0/25): onConstruct clip event

These tests are in the "Clip Events" category but share the same prerequisite.

---

## Phase 2: EditText Clones (depends on TEXTFIELD_PLAN.md Phases 1+2)

**Goal**: Make CloneSprite work correctly for EditText/TextField objects, cloning their properties with the correct "reset to defaults" behavior.

### What the tests expect

When an EditText is cloned, the clone gets a **fresh default state** — most properties reset to defaults rather than copying from the source. From the test expected outputs:

**Properties that ARE preserved from source** (clone_sprite_edittext):
- `_x`, `_y` — position (from transform)
- `multiline` — sometimes preserved (see below)
- `textColor` — preserved for timeline-placed fields
- `_alpha` — preserved
- `embedFonts` — preserved
- `type` — preserved ("input" stays "input")
- TextFormat layout properties (leftMargin, rightMargin, indent, leading) — preserved

**Properties that RESET to defaults** (clone differs from source):
- `_width` → resets to small default (5 for timeline, 0 for dynamic)
- `autoSize` → resets to "none" or "left" (differs from source "right")
- `backgroundColor` → resets to 16777215 (white)
- `borderColor` → resets to 0 (black)
- `condenseWhite` → resets to false
- `antiAliasType` → resets to "normal"
- `gridFitType` → resets to "pixel"
- `maxChars` → resets to null
- `_name` → gets the clone's new name
- `styleSheet` → resets to undefined
- `filters` → resets to empty
- `text` → resets to "" (empty)
- `restrict` → resets to null
- `sharpness`, `thickness` → reset to 0
- `tabEnabled`, `tabIndex` → reset to undefined
- `html` → behavior varies (timeline: true→true, dynamic: true→false)

**Key behavior**: The clone is essentially a NEW EditText with the same character ID — it reinitializes from the DefineEditText tag data (base properties) but does NOT copy dynamic changes made to the source instance. The exceptions are positional properties (_x, _y, _alpha, _rotation, _xscale, _yscale) and some character-level properties (type, textColor from tag).

### Implementation

When cloning a textfield:
1. Create a new `ng_display` entry with `is_textfield = 1` and the same `textfield_idx` as the source
2. The clone's MovieClip gets properties from the `ng_textfields[textfield_idx]` definition (reinitialize from tag data)
3. Positional properties come from the source MC
4. Dynamic properties (restrict, tabIndex, filters, styleSheet, sharpness, thickness, condenseWhite, maxChars if changed) are NOT copied — they use defaults

This phase depends on TEXTFIELD_PLAN.md Phase 1 (TextField prototype + property storage) being complete, since the tests check `getNewTextFormat()` return values which require the TextFormat class.

### Tests fixed by Phase 2

- **clone_sprite_edittext**: From ~0/95 → ~70-85/95 (depends on TextField/TextFormat completeness)
- **clone_sprite_edittext_dynamic**: From ~0/87 → ~65-80/87

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=clone_sprite_edittext --diff --verbose
python3 ruffle-tests/verify_output.py --test=clone_sprite_edittext_dynamic --diff --verbose
```

---

## Implementation Priority and Dependencies

```
tagPlaceObject2WithClipActions fix (1a)
        │
        ▼
Clip action dispatch: onLoad (1b) ──→ [unlocks clip_events, clip_event_propagation_order, on_construct]
        │
        ▼
actionCloneSprite implementation (1c)
        │
        ├──→ duplicateMovieClip method (1d)
        │
        └──→ Non-scriptable type fix (1e) [independent]

TEXTFIELD_PLAN.md Phase 1+2 ──→ Phase 2: EditText clones
```

**Phase 1 is independent of the TextField plan** and can be implemented first. Phase 2 depends on TextField/TextFormat being implemented.

## Estimated Test Impact

| Phase | Tests Fixed | Cumulative | Notes |
|-------|-----------|------------|-------|
| 1 (core) | ~2 (duplicate_movie_clip, clone_sprite_types) | 2 | Also unblocks clip_events category (~2-3 more) |
| 2 (edittext) | ~2 (clone_sprite_edittext, clone_sprite_edittext_dynamic) | 4 | Depends on TextField plan |
| Deferred | duplicate_movie_clip_drawing | N/A | Needs Drawing API |

**Bonus impact of Phase 1 prerequisites**: The `tagPlaceObject2WithClipActions` fix (1a) and clip action dispatch (1b) are prerequisites that may also improve:
- clip_events (1/19)
- clip_event_propagation_order (0/17)
- on_construct (0/25)
- Any other test that uses clip events with onLoad/onEnterFrame

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/libswf/tag_stubs.c` | Fix `tagPlaceObject2WithClipActions`, add clip_actions to ng_display struct, add `ng_cloneSprite()`, add `ng_isScriptableAtDepth()`, fire onLoad clip actions in `tagShowFrame` |
| `include/libswf/tag.h` | Declare `ng_cloneSprite()`, `ng_isScriptableAtDepth()` |
| `src/actionmodern/action.c` | Update `actionCloneSprite` NO_GRAPHICS branch to call `ng_cloneSprite`, add `duplicateMovieClip` handler in CallMethod, fix `findOrCreateMovieClip` for non-scriptable types |

### No recompiler changes needed

The recompiler already correctly emits `actionCloneSprite()` calls and generates the proper clip action arrays in tagMain.c.

---

## Design Decisions

1. **Shared sprite_idx**: Clones share the source's `sprite_idx` (index into `ng_sprites[]`). This means they share the same frame functions — which is correct. Flash clones inherit the character definition, including all frame scripts.

2. **Clip action copying**: Clones copy the clip_actions pointer from the source ng_display entry. This means clones share the same clip action function pointers as the source, so onLoad fires on clones too. This matches Flash behavior where clones inherit their placement's clip actions.

3. **No deep clone of dynamic_props**: Flash's duplicateMovieClip creates a "fresh" instance — custom properties set on the source do NOT transfer to the clone. Only positional/transform properties and the character definition are inherited.

4. **Depth semantics**: We use raw Flash depths (as received from the stack) stored directly in `ng_display[].depth`. If a depth is already occupied, the existing entry is replaced. This matches Flash behavior.

5. **Non-scriptable discrimination**: Only buttons, textfields, sprites, and videos are scriptable (create MovieClip identity). Shapes, static text, morph shapes, and images are not — they resolve to their parent scope. This is implemented by checking `ng_display` flags before creating MovieClip objects in `findOrCreateMovieClip`.
