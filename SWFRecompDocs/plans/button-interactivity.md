# Button Interactivity - Implementation Plan

**Created:** February 8, 2026

**Status:** Planning

---

## Table of Contents

1. [Overview](#overview)
2. [Current State](#current-state)
3. [Phase 1: Input System](#phase-1-input-system)
4. [Phase 2: Hit Testing](#phase-2-hit-testing)
5. [Phase 3: Button State Machine](#phase-3-button-state-machine)
6. [Phase 4: DefineButton Visual State Switching](#phase-4-definebutton-visual-state-switching)
7. [Phase 5: DefineButton2 (Tag 34)](#phase-5-definebutton2-tag-34)
8. [Phase 6: Button Actions](#phase-6-button-actions)
9. [Data Structure Changes](#data-structure-changes)
10. [Open Questions](#open-questions)

---

## Overview

DefineButton (tag 7) is currently implemented as a static sprite — only the "up" state is displayed, with no mouse interaction. This plan covers the full path from zero interactivity to complete button support including state transitions, hit testing, visual feedback, DefineButton2, and action execution.

Each phase is self-contained and provides incremental value.

---

## Current State

### What Exists

**Recompiler (SWFRecomp/src/swf.cpp):**
- DefineButton (tag 7) parser at line 2428
- Reads ButtonId, loops BUTTONRECORD entries (flags + CharacterId + PlaceDepth + MATRIX)
- Only emits up-state records (flags bit 0); other states parsed but skipped
- Registers button as `CHAR_TYPE_SPRITE` via `tagDefineSprite()` with 1 frame
- Skips ActionRecords entirely (`cur_pos = tag_body_start + button_tag_length`)

**Runtime (SWFModernRuntime):**
- `Character` struct (swf.h:31): union with shape/morph/text/sprite variants. No button variant.
- `DisplayObject` struct (swf.h:68): has char_id, transform_id, cxform_id, clip_depth, ratio. No button state fields.
- `tagShowFrame` (tag.c): renders sprites by executing `sprite_frame_funcs[0]` into temp display list. Always frame 0.
- `flashbang_poll` (flashbang.c:639): SDL3 event loop, only handles `SDL_EVENT_QUIT` and `SDL_EVENT_WINDOW_CLOSE_REQUESTED`.
- `render_webgpu_poll` (render_webgpu.c): returns 0 on WASM (browser handles events), polls SDL on native.
- WASM HTML template: canvas element with no mouse event listeners.
- ActionScript VM (action.c): ~6800 lines, 100+ opcodes, stack-based. Runs during `DoAction` tags only — no event-driven invocation.
- `is_dragging` / `dragged_target` globals exist (swf.h:154-155) but are only stubs.

**Not implemented:**
- DefineButton2 (tag 34) — not in tag enum, no parser case
- Mouse event handling (neither SDL nor emscripten)
- Hit testing (point-in-shape)
- Button state tracking
- Event-driven action execution

---

## Phase 1: Input System

**Goal:** Track mouse position and button state in both native and WASM builds.

### 1.1 Mouse State Struct

Add to `swf.h`:

```c
typedef struct MouseState {
    float stage_x;    // Mouse position in SWF stage coordinates (twips)
    float stage_y;
    int button_down;  // 1 if primary mouse button is held
    int moved;        // 1 if mouse moved this frame (dirty flag)
    int clicked;      // 1 if button was pressed this frame (edge trigger)
    int released;     // 1 if button was released this frame (edge trigger)
} MouseState;
```

Add `MouseState mouse;` to `SWFAppContext`.

### 1.2 Native Input (SDL3)

**File:** `SWFModernRuntime/src/flashbang/flashbang.c` — `flashbang_poll()`

Add cases to the existing `SDL_PollEvent` switch:

```c
case SDL_EVENT_MOUSE_MOTION:
    // Convert window coords to stage coords
    // stage_x = evt.motion.x * (stage_width / window_width) * 20.0f
    // (×20 for twips)
    break;

case SDL_EVENT_MOUSE_BUTTON_DOWN:
    if (evt.button.button == SDL_BUTTON_LEFT)
        // set button_down = 1, clicked = 1
    break;

case SDL_EVENT_MOUSE_BUTTON_UP:
    if (evt.button.button == SDL_BUTTON_LEFT)
        // set button_down = 0, released = 1
    break;
```

**Coordinate transform:** The SDL window size may not match the SWF stage size. Need to scale from window pixels to stage twips. `flashbang_poll` needs access to `SWFAppContext*` (currently takes no args — signature change required, or pass through `RenderContext`).

**Change `renderer_poll` to accept `SWFAppContext*`:**
- `renderer.h`: `#define renderer_poll(app) flashbang_poll(app)` / `render_webgpu_poll(app)`
- `swf.c` tagMain loop: `bad_poll |= renderer_poll(app_context);`
- Both backends update their signatures

### 1.3 WASM Input (Emscripten)

**File:** `SWFModernRuntime/src/rendering/render_webgpu.c` — `render_webgpu_init()`

Register emscripten callbacks during init:

```c
#ifdef __EMSCRIPTEN__
#include <emscripten/html5.h>

static SWFAppContext* g_app_context; // set during init

EM_BOOL on_mousemove(int type, const EmscriptenMouseEvent* evt, void* ud) {
    // evt->targetX, evt->targetY are canvas-relative
    // Convert to stage twips
    g_app_context->mouse.stage_x = evt->targetX * 20.0f;  // assumes 1:1 canvas:stage
    g_app_context->mouse.stage_y = evt->targetY * 20.0f;
    g_app_context->mouse.moved = 1;
    return EM_TRUE;
}

// Similar for mousedown, mouseup
```

Register in `render_webgpu_init`:

```c
emscripten_set_mousemove_callback("#canvas", NULL, 0, on_mousemove);
emscripten_set_mousedown_callback("#canvas", NULL, 0, on_mousedown);
emscripten_set_mouseup_callback("#canvas", NULL, 0, on_mouseup);
```

### 1.4 Frame Reset

At the start of each frame in `tagMain` (swf.c), clear edge-triggered flags:

```c
app_context->mouse.moved = 0;
app_context->mouse.clicked = 0;
app_context->mouse.released = 0;
```

### 1.5 Canvas Scaling Considerations

The WASM HTML template has a fixed `<canvas width="550" height="400">`. If the SWF stage size differs, the coordinate transform needs the ratio. Store `canvas_to_stage_x` and `canvas_to_stage_y` scale factors, computed during init from `app_context->width / canvas_width`.

### Files Changed
- `SWFModernRuntime/include/libswf/swf.h` — MouseState struct, add to SWFAppContext
- `SWFModernRuntime/include/rendering/renderer.h` — update `renderer_poll` macro signature
- `SWFModernRuntime/include/rendering/render_webgpu.h` — update poll signature
- `SWFModernRuntime/include/flashbang/flashbang.h` — update poll signature
- `SWFModernRuntime/src/flashbang/flashbang.c` — mouse event handling
- `SWFModernRuntime/src/rendering/render_webgpu.c` — emscripten callbacks
- `SWFModernRuntime/src/libswf/swf.c` — `tagMain` frame reset, pass app_context to poll

---

## Phase 2: Hit Testing

**Goal:** Determine whether a point (mouse position) is inside a shape's filled area.

### 2.1 Approach: Even-Odd Ray Casting

SWF shapes are defined as triangulated vertex data (post-earcut). Each shape is a list of triangles (3 vertices each, stored as `shape_data[offset..offset+size]`). Hit testing can operate directly on this triangulated data:

```
For each triangle in the shape:
    if point_in_triangle(mouse_x, mouse_y, v0, v1, v2):
        return true
return false
```

This is simpler than ray casting against the original edges because we already have triangulated data.

### 2.2 Coordinate Transform

Mouse coordinates are in stage space (twips). Shape vertices are also in stage space but need the shape's transform applied in reverse:

```
local_point = inverse(transform) * stage_point
```

The transform is a 4x4 column-major matrix stored in `transform_data`. We need `mat4_invert()` — a 4x4 matrix inverse function. Since transforms are 2D affine (the z/w rows are identity), this simplifies to a 2D affine inverse:

```c
// For a 2D affine transform [a b tx; c d ty; 0 0 1]:
// det = a*d - b*c
// inv = [d/det  -b/det  (b*ty-d*tx)/det]
//       [-c/det  a/det  (c*tx-a*ty)/det]
```

### 2.3 Point-in-Triangle Test

Barycentric coordinate method:

```c
bool point_in_triangle(float px, float py,
                       float ax, float ay, float bx, float by, float cx, float cy)
{
    float d1 = (px - bx) * (ay - by) - (ax - bx) * (py - by);
    float d2 = (px - cx) * (by - cy) - (bx - cx) * (py - cy);
    float d3 = (px - ax) * (cy - ay) - (cx - ax) * (py - ay);
    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(has_neg && has_pos);
}
```

### 2.4 Hit Test Function

```c
bool hit_test_shape(SWFAppContext* app_context, size_t shape_offset, size_t shape_size,
                    u32 transform_id, float stage_x, float stage_y)
{
    // 1. Get transform, compute inverse
    // 2. Transform (stage_x, stage_y) to local space
    // 3. Iterate triangles (every 3 vertices starting at shape_offset)
    // 4. Return true if point is inside any triangle
}
```

### 2.5 Hit Test for Buttons

A button's hit-test area uses specific BUTTONRECORD entries (flags bit 3). The hit shape may be different from the visible shape. In the parser, we'll need to emit the hit-test shape reference alongside the up/over/down shapes.

### 2.6 Performance Notes

- Only test buttons that are on screen (clip_depth check)
- Test in reverse depth order (front to back) — first hit wins
- For complex shapes with many triangles, consider bounding box pre-check
- Hit testing runs once per frame at most (on mouse move), so O(triangles) per button is fine

### Files Changed
- New: `SWFModernRuntime/src/libswf/hit_test.c` — hit test functions
- New: `SWFModernRuntime/include/libswf/hit_test.h` — declarations
- `SWFModernRuntime/src/libswf/tag.c` — call hit test during frame processing

---

## Phase 3: Button State Machine

**Goal:** Track per-button instance state and drive transitions based on mouse input.

### 3.1 Button States

SWF buttons have 4 states:
- **Up** — mouse is not over the button
- **Over** — mouse is over the button, no click
- **Down** — mouse is over the button, clicked
- **Hit** — invisible hit-test area (not a visual state)

State transitions follow this graph:

```
             mouse enters           mouse press
    Up  ──────────────────→  Over  ───────────────→  Down
    ↑                          ↑                       |
    │   mouse leaves           │   mouse release       │
    ←──────────────────────────←───────────────────────←
```

Additional transitions (mouse leaves while pressed, etc.) follow the SWF spec's BUTTONCONDACTION conditions.

### 3.2 CHAR_TYPE_BUTTON

Replace the `CHAR_TYPE_SPRITE` hack with a proper button character type:

```c
typedef enum {
    CHAR_TYPE_SHAPE,
    CHAR_TYPE_MORPH_SHAPE,
    CHAR_TYPE_TEXT,
    CHAR_TYPE_SPRITE,
    CHAR_TYPE_BUTTON,     // NEW
} CharacterType;
```

### 3.3 Button Character Data

Add a button variant to the `Character` union:

```c
// DefineButton
struct {
    frame_func* button_state_funcs;  // [up, over, down] frame functions
    size_t button_hit_shape_offset;  // hit-test shape offset in shape_data
    size_t button_hit_shape_size;    // hit-test shape vertex count
    u32 button_hit_transform_id;     // transform for hit-test shape
    // Action data (Phase 6)
};
```

Each state function (up/over/down) builds a display list for that state, same pattern as sprite frame functions.

### 3.4 Button State in DisplayObject

Add button-specific fields:

```c
typedef struct DisplayObject {
    size_t char_id;
    u32 transform_id;
    u32 cxform_id;
    u32 has_cxform;
    u16 clip_depth;
    u16 ratio;
    u8 button_state;      // NEW: 0=up, 1=over, 2=down
    u8 button_prev_state; // NEW: for edge detection (idle→overUp, etc.)
} DisplayObject;
```

### 3.5 Frame Processing Flow

In `tagShowFrame`, before rendering:

```
1. Clear per-frame edge triggers
2. For each display_list entry (back to front):
     if char type == CHAR_TYPE_BUTTON:
       hit = hit_test(hit_shape, mouse_x, mouse_y)
       old_state = obj->button_state
       new_state = compute_state(hit, mouse.button_down)
       if new_state != old_state:
         obj->button_state = new_state
         // (Phase 6: fire transition actions)
3. Render using current state's display list
```

### 3.6 Rendering

When rendering a button, select the frame function based on `button_state`:

```c
case CHAR_TYPE_BUTTON:
{
    size_t state = obj->button_state;  // 0, 1, or 2
    if (ch->button_state_funcs[state] != NULL)
        ch->button_state_funcs[state](app_context);
    // Then render the temp display list (same as sprite rendering)
    break;
}
```

### Files Changed
- `SWFModernRuntime/include/libswf/swf.h` — CHAR_TYPE_BUTTON, Character union, DisplayObject fields
- `SWFModernRuntime/src/libswf/tag.c` — `tagShowFrame` button state machine + rendering, new `tagDefineButton` function
- `SWFRecomp/src/swf.cpp` — parser emits per-state frame functions + hit shape data

---

## Phase 4: DefineButton Visual State Switching

**Goal:** Parse all button states and render the correct one based on mouse interaction.

### 4.1 Parser Changes (swf.cpp)

Currently the parser only emits up-state records. Change to emit 3 frame functions:

```cpp
case SWF_TAG_DEFINE_BUTTON:
{
    // ... read ButtonId ...

    std::string bp = "button_" + to_string(button_id);

    // Collect records by state
    struct ButtonRecord { u16 char_id; u16 depth; MATRIX matrix; };
    std::vector<ButtonRecord> up_records, over_records, down_records;
    int hit_char_id = -1;
    u16 hit_depth = 0;
    MATRIX hit_matrix;

    while (true)
    {
        // read flags, char_id, depth, matrix
        if (flags == 0) break;

        ButtonRecord rec = { char_id, depth, matrix };
        if (flags & 0x01) up_records.push_back(rec);
        if (flags & 0x02) over_records.push_back(rec);
        if (flags & 0x04) down_records.push_back(rec);
        if (flags & 0x08) { hit_char_id = char_id; hit_depth = depth; hit_matrix = matrix; }
    }

    // Generate 3 frame functions: button_N_frame_up, _over, _down
    for (auto& [name, records] : {
        make_pair("up", up_records),
        make_pair("over", over_records),
        make_pair("down", down_records)
    })
    {
        sprite_definitions << "void " << bp << "_frame_" << name
                           << "(SWFAppContext* app_context) {" << endl;
        for (auto& rec : records)
        {
            size_t tid = current_transform;
            recompileMatrix(rec.matrix, transform_data);
            current_transform++;
            sprite_definitions << "\ttagPlaceObject2(app_context, "
                               << rec.depth << ", " << rec.char_id << ", "
                               << tid << ", 0, 0);" << endl;
        }
        sprite_definitions << "}" << endl;
    }

    // Generate button_state_funcs array: [up, over, down]
    sprite_definitions << "frame_func " << bp << "_state_funcs[] = {"
                       << bp << "_frame_up, "
                       << bp << "_frame_over, "
                       << bp << "_frame_down};" << endl;

    // Emit tagDefineButton call (new runtime function)
    context.tag_main << "\ttagDefineButton(app_context, " << button_id
                     << ", " << bp << "_state_funcs"
                     << ", hit_shape_offset, hit_shape_size, hit_transform_id);"
                     << endl;

    // Skip ActionRecords
    cur_pos = tag_body_start + button_tag_length;
    break;
}
```

### 4.2 Hit Shape

The hit-test shape is an existing character (referenced by CharacterId in the hit-test BUTTONRECORD). Its shape data is already in `shape_data` from an earlier DefineShape tag. The parser just needs to record which character ID to use for hit testing — the runtime looks it up in the dictionary.

Alternative: store the character ID in the button's Character entry and look up shape_offset/size at hit-test time.

### 4.3 Fallback States

SWF spec says: if a state has no records, fall back to the up state. The parser should detect empty state lists and point them to the up-state function:

```cpp
if (over_records.empty()) over_func = up_func;
if (down_records.empty()) down_func = up_func;  // or over_func
```

### 4.4 Cursor Changes

When the button state transitions to "over", the cursor should change to a hand pointer:

**Native (SDL3):**
```c
SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_POINTER));
```

**WASM:**
```c
EM_ASM({ document.getElementById('canvas').style.cursor = 'pointer'; });
```

Reset to default cursor when no button is hovered.

### Files Changed
- `SWFRecomp/src/swf.cpp` — DefineButton parser rewrite (multi-state)
- `SWFModernRuntime/src/libswf/tag.c` — `tagDefineButton`, rendering with state selection
- `SWFModernRuntime/include/libswf/swf.h` — Character union button variant

---

## Phase 5: DefineButton2 (Tag 34)

**Goal:** Support the more flexible button format used by Flash MX and later.

### 5.1 Differences from DefineButton

| Feature | DefineButton (tag 7) | DefineButton2 (tag 34) |
|---------|---------------------|----------------------|
| Record format | flags(1) + charId(2) + depth(2) + matrix | flags(1) + charId(2) + depth(2) + matrix + cxform + filterList + blendMode |
| Action format | Simple ActionRecord list | BUTTONCONDACTION with explicit condition flags |
| Menu mode | No | Yes (TrackAsMenu flag) |
| Blend modes | No | Yes (SWF 8+) |
| Filters | No | Yes (SWF 8+) |

### 5.2 Parser

```
SWF_TAG_DEFINE_BUTTON_2 = 34

Format:
  ButtonId         UI16
  TrackAsMenu      UI8 (bit 0)
  ActionOffset     UI16  (byte offset to first BUTTONCONDACTION, 0 = none)
  BUTTONRECORD[]   (terminated by 0 byte)
  BUTTONCONDACTION[] (chain of condition+action blocks)
```

BUTTONRECORD2 extends BUTTONRECORD with:
- ColorTransform (CXFORMWITHALPHA) if present
- FilterList (if HasFilterList flag, SWF 8+)
- BlendMode (UI8 if HasBlendMode flag, SWF 8+)

### 5.3 BUTTONCONDACTION

Each condition block has:
```
  CondActionSize   UI16  (0 = last block)
  Condition        UI16  (bitmask of transition events)
  Actions[]        (ActionRecord sequence ending in ActionEndFlag)
```

Condition bits:
```
Bit 0:  IdleToOverDown      (press while over)
Bit 1:  OutDownToIdle        (release outside)
Bit 2:  OutDownToOverDown    (drag back in)
Bit 3:  OverDownToOutDown    (drag out)
Bit 4:  OverDownToOverUp     (release while over = "click")
Bit 5:  OverUpToOverDown     (press while over)
Bit 6:  OverUpToIdle         (mouse leave)
Bit 7:  IdleToOverUp         (mouse enter)
Bit 8:  OverDownToIdle       (release outside, alternate)
```

### 5.4 Phased Approach

- **5a:** Parse BUTTONRECORD2 (ignore filters/blendmode), register as button character
- **5b:** Parse BUTTONCONDACTION, store condition→action mappings
- **5c:** Execute actions on matching transitions (requires Phase 6)
- **5d:** Support filters and blend modes (much later, requires shader changes)

### 5.5 Tag Enum

Add to `tag.hpp`:
```cpp
SWF_TAG_DEFINE_BUTTON_2 = 34,
```

### Files Changed
- `SWFRecomp/include/tag.hpp` — tag enum
- `SWFRecomp/src/swf.cpp` — DefineButton2 parser
- `SWFModernRuntime/include/libswf/swf.h` — Character union extension for button action data

---

## Phase 6: Button Actions

**Goal:** Execute ActionScript in response to button state transitions.

### 6.1 Action Storage

The recompiler generates action bytecode as C arrays. For buttons, each condition→action pair becomes a function:

```c
void button_3_action_overdown_to_overup(SWFAppContext* app_context)
{
    // ActionScript bytecode calls (same pattern as DoAction)
    actionGotoFrame(app_context, 5);
    actionPlay(app_context);
}
```

### 6.2 Condition Dispatch Table

Store a mapping from condition bitmask to action function:

```c
typedef struct ButtonAction {
    u16 condition;        // bitmask of triggering transitions
    frame_func action;    // function to call
} ButtonAction;
```

Add to Character union:
```c
struct {
    frame_func* button_state_funcs;
    size_t button_hit_char_id;
    ButtonAction* button_actions;
    size_t button_action_count;
};
```

### 6.3 Transition Detection

In `tagShowFrame`, when a button state changes:

```c
u16 transition = encode_transition(old_state, new_state);
for (size_t a = 0; a < ch->button_action_count; a++) {
    if (ch->button_actions[a].condition & transition)
        ch->button_actions[a].action(app_context);
}
```

### 6.4 DefineButton (tag 7) Actions

DefineButton's action records are simpler — they fire on `OverDownToOverUp` (basic click/release). The parser can wrap them in a single action function with condition = `OverDownToOverUp`.

### 6.5 Recompiler Integration

The action bytecode in button tags uses the same opcodes as `DoAction`. The existing `interpretAction()` function in swf.cpp should be reusable — call it with the button's action data range.

### Files Changed
- `SWFRecomp/src/swf.cpp` — parse and emit button actions
- `SWFModernRuntime/include/libswf/swf.h` — ButtonAction struct, Character extension
- `SWFModernRuntime/src/libswf/tag.c` — transition detection and action dispatch

---

## Data Structure Changes Summary

### swf.h — Character Union (Final State)

```c
typedef struct Character {
    CharacterType type;
    union {
        // CHAR_TYPE_SHAPE
        struct { size_t shape_offset; size_t size; };

        // CHAR_TYPE_MORPH_SHAPE
        struct { size_t morph_start_offset; ... };

        // CHAR_TYPE_TEXT
        struct { size_t text_start; ... };

        // CHAR_TYPE_SPRITE
        struct { frame_func* sprite_frame_funcs; size_t sprite_frame_count; };

        // CHAR_TYPE_BUTTON (NEW)
        struct {
            frame_func* button_state_funcs;      // [up, over, down]
            size_t button_hit_char_id;            // character to use for hit testing
            ButtonAction* button_actions;         // condition→action pairs
            size_t button_action_count;
        };
    };
} Character;
```

### swf.h — DisplayObject (Final State)

```c
typedef struct DisplayObject {
    size_t char_id;
    u32 transform_id;
    u32 cxform_id;
    u32 has_cxform;
    u16 clip_depth;
    u16 ratio;
    u8 button_state;       // NEW: 0=up, 1=over, 2=down
    u8 button_prev_state;  // NEW: previous frame's state
} DisplayObject;
```

### swf.h — SWFAppContext Addition

```c
typedef struct SWFAppContext {
    // ... existing fields ...
    MouseState mouse;  // NEW
};
```

---

## Resolved Questions

1. **Hit testing granularity:** Start with bounding-box approximation for early phases. Upgrade to triangle-level hit testing later for full correctness.

2. **Sprite nesting recursion:** No explicit recursion depth limit needed. Ruffle has no limit for display list traversal during hit testing — it recurses naturally through `mouse_pick_avm1` calls on child objects. The only recursion limit in Ruffle (255) applies to ActionScript function calls, not display list traversal. Our implementation should follow the same approach: recurse freely, rely on practical stack depth. (Reference: `ruffle/core/src/avm1/runtime.rs` lines 81-83.)

3. **Multiple overlapping buttons:** Iterate back-to-front (highest depth first) and stop at the first hit. This matches Ruffle's behavior: `iter_render_list().rev()` with early return on first match. Mouse events go high→low depth; key events go low→high. (Reference: `ruffle/core/src/display_object/interactive.rs` lines 240-246, `ruffle/core/src/player.rs` lines 3173-3200.)

4. **TrackAsMenu (DefineButton2):** Deferred — implement later after basic button interactivity is working.

5. **Action compatibility:** No special graceful degradation needed. We plan to implement the remaining ActionScript opcodes as soon as possible. Unknown opcodes can use the existing default/warning behavior.

6. **Focus / keyboard:** Out of scope for this plan. Keyboard handling will be a separate future effort.

7. **renderer_poll signature change:** Use the clean solution — change the signature to accept `SWFAppContext*` in both backends rather than relying on a global pointer.
