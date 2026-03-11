# Input Event Injection - Implementation Plan

**Created:** February 19, 2026

**Status:** Complete (all phases implemented)

---

## Table of Contents

1. [Overview](#overview)
2. [Current State](#current-state)
3. [Tests Affected](#tests-affected)
4. [Key Design Decisions](#key-design-decisions)
5. [Phase 0: Unify NO_GRAPHICS and GRAPHICS Structs](#phase-0-unify-no_graphics-and-graphics-structs)
6. [Phase 1: verify_output.py Changes](#phase-1-verify_outputpy-changes)
7. [Phase 2: Event File Format](#phase-2-event-file-format)
8. [Phase 3: C Event Pump](#phase-3-c-event-pump)
9. [Phase 4: Mouse and Key State](#phase-4-mouse-and-key-state)
10. [Phase 5: Global Mouse Event Dispatch](#phase-5-global-mouse-event-dispatch)
11. [Phase 6: Per-Clip Hit Testing and Event Dispatch](#phase-6-per-clip-hit-testing-and-event-dispatch)
12. [Phase 7: Key Events](#phase-7-key-events)
13. [Phase 8: Focus System](#phase-8-focus-system)
14. [Phase 9: Tab Ordering](#phase-9-tab-ordering)
15. [Files Changed Summary](#files-changed-summary)
16. [Open Questions](#open-questions)

---

## Overview

62 of 619 Ruffle AVM1 tests include an `input.json` file that injects synthetic mouse and keyboard events during execution. These cover several large test categories that are currently failing at near 0%:

- **Button Behavior and Events** (14 failing)
- **Mouse/Focus/Input Events** (18 failing)
- **Tab Ordering and Focus Navigation** (14 failing)
- **Key/Input Events** (2 failing)
- **Drag and Drop** (3 failing)
- Plus scattered tests in other categories

This plan describes how to add input event support to the trace-mode test pipeline without replacing the existing `verify_output.py` infrastructure.

---

## Current State

### verify_output.py

The runner:
1. Recompiles the SWF to C
2. Compiles the C with `gcc -DNO_GRAPHICS -DMAX_FRAMES=N`
3. Runs the binary, captures stdout
4. Compares against `output.txt`

It reads `test.toml` for `num_frames`/`num_ticks` but ignores `input.json` entirely.

### swf_core.c — the NO_GRAPHICS main loop

`swfStart()` in `swf_core.c` runs a tick loop:

```c
while (!quit_swf && tick_count < max_ticks) {
    tick_count++;
    ng_advanceSprites(app_context);
    if (is_playing || manual_next_frame) {
        funcs[current_frame](app_context);  // runs DoAction/PlaceObject/etc.
    }
    // goto catch-up ...
    // advance current_frame
}
```

There is no concept of input events, mouse state, or key state in this path.

### The two-world problem

The NO_GRAPHICS and GRAPHICS builds currently use completely different runtime data structures:

**GRAPHICS mode** (`tag.c`, guarded by `#ifndef NO_GRAPHICS` in `swf.h`):
- `Character` struct with a rich union: shape offsets, morph data, text data, sprite frame funcs, button state funcs + actions
- `DisplayObject` struct with full fields: button state, sprite display list, clip actions, filters, instance name, etc.
- `CLIP_EVENT_*` defines for all clip event types
- `MouseState` in `SWFAppContext`
- Hit testing via `hit_test.c` using triangulated `shape_data` + `transform_data` from `draws.h`
- Button state machine and event dispatch in `tag.c`

**NO_GRAPHICS mode** (`tag_stubs.c`, `swf_core.c`):
- Parallel flat arrays: `ng_sprites[]`, `ng_display[]`, `ng_buttons[]`, `ng_textfields[]`
- Simple `ng_display` struct with: `char_id`, `depth`, `placed_at_frame`, `is_playing`, `instance_name`, `sprite_idx`
- No `Character` type enum, no button struct, no clip actions
- No `MouseState`, no hit testing
- No shape/transform data

This divergence is the root cause of why mouse events, button dispatch, and hit testing are absent in trace mode. **Phase 0 unifies the two worlds** by moving the shared structs out of the `#ifndef NO_GRAPHICS` guard and migrating `tag_stubs.c` to use them.

---

## Tests Affected

62 tests have `input.json`. Of these:

| Category | Test count | Input event types used |
|---|---|---|
| Button Behavior | 14 | MouseDown/Up/Move, KeyDown, Wait |
| Mouse/Focus Events | 18 | MouseDown/Up/Move, Wait |
| Tab Ordering | 14 | KeyDown(Tab), MouseDown/Up, Wait |
| Key/Input Events | 2 | KeyDown, TextInput |
| Drag and Drop | 3 | MouseDown/Up/Move, Wait |
| EditText input | 8 | MouseDown/Up, TextInput, TextControl, Wait |
| Other | 3 | MouseDown/Up/Move, Wait |

Two tests in the list (`focusrect_mouse_swf8`, `focusrect_mouse_swf9`) are already **passing** without input events — they use `input.json` but apparently don't need the events to produce the expected trace output.

Two tests (`frame_size_translated_negative`, `frame_size_translated_positive`) use `input.json` but have only `MouseMove` events and are in the "stage frame properties" category — they may be achievable without full hit testing.

---

## Key Design Decisions

### Decision 1: Event file format — pre-process in Python, not parse JSON in C

**Options considered:**
- Pass `input.json` directly to the binary and parse JSON in C
- Pre-process in `verify_output.py` to a simple line-based format

**Decision: Pre-process in Python.**

Writing a JSON parser in C is significant complexity for no benefit. Python converts `input.json` to a simple text format that C can parse with `fgets`/`sscanf`. The text file is written to the temp build dir alongside the compiled binary.

### Decision 2: Wait token maps to frame tick boundary

In Ruffle, `Wait` means "advance one tick before processing more events." In our system, one tick = one iteration of the `swfStart` main loop (one call to `funcs[current_frame]`).

**Mapping:**
```
Events before Wait 0 → injected before tick 0 (frame 0)
Wait 0
Events before Wait 1 → injected before tick 1 (frame 1)
Wait 1
...
```

Events with no preceding Wait (before the first Wait) are injected before tick 0. This matches Ruffle's behavior.

### Decision 3: Frame count must cover all Wait tokens

`num_frames`/`num_ticks` in `test.toml` tells Ruffle how many ticks to run. If there are N Wait tokens, at minimum N+1 ticks are needed. The runner:

1. Parses `input.json` and counts Wait tokens → `wait_count`
2. Reads `num_frames`/`num_ticks` from `test.toml` → `declared_frames`
3. Passes `MAX_FRAMES = max(declared_frames, wait_count + 1)` to gcc

In practice `declared_frames` already covers all waits for Ruffle's tests, so this is a safety measure.

### Decision 4: NO_GRAPHICS uses the same infrastructure as GRAPHICS — no simplified parallel path

There is no reason to maintain a separate, simplified NO_GRAPHICS event pipeline. The `Character`, `DisplayObject`, `MouseState`, `ButtonAction`, `ClipAction`, and `CLIP_EVENT_*` infrastructure currently guarded by `#ifndef NO_GRAPHICS` in `swf.h` should be moved out of that guard and made unconditionally available.

Similarly, `shape_data`/`transform_data` from `draws.h` (currently only loaded in the GRAPHICS `main.c`) should also be included in the NO_GRAPHICS trace test builds (via changes to `main.c` and `verify_output.py`'s compile step) so that `hit_test.c` can be compiled in and used without modification.

This eliminates all bounding-box approximations and ensures all new event/button/hit-testing code is written once and works identically in both modes. **Phase 0** covers this unification as a prerequisite.

### Decision 5: Event pump lives in a new swf_core.c helper, not a separate file

The event pump is tightly coupled to the `swfStart` tick loop. Rather than a new compilation unit, add the pump as a static helper within `swf_core.c`. This keeps the NO_GRAPHICS build self-contained.

Optionally: add a new `trace_input.c`/`.h` compiled alongside `swf_core.c` for cleanliness. Either approach works.

### Decision 6: Key state is a 256-entry bitset

Flash key codes are 0–255. A `uint8_t keys_down[256]` bitset (32 bytes) is sufficient for `Key.isDown(code)`. Toggled keys (Caps Lock, Num Lock, Scroll Lock) get a separate 3-entry array.

### Decision 7: Phase the work — struct unification first, then global dispatch, then hit testing

Phase 0 (struct unification) is a prerequisite for everything else. Within event delivery, global mouse dispatch (Phase 5) unlocks more tests with less complexity than per-clip hit testing (Phase 6), so it comes first.

---

## Phase 0: Unify NO_GRAPHICS and GRAPHICS Structs

**Goal:** Remove the `#ifndef NO_GRAPHICS` guards from the shared data structures in `swf.h` and `tag_stubs.c` so that both modes use identical `Character`, `DisplayObject`, `ClipAction`, `ButtonAction`, and `MouseState` types. Include shape and transform data in trace builds so `hit_test.c` can be compiled in unconditionally.

This is a prerequisite for all subsequent phases. It is largely mechanical — no new logic is introduced, only guard removal and `tag_stubs.c` migration.

### 0.1 Unconditional structs in swf.h

Remove the `#ifndef NO_GRAPHICS` / `#endif` guards that currently wrap:
- `INITIAL_DICTIONARY_CAPACITY`, `INITIAL_DISPLAYLIST_CAPACITY` defines
- `CLIP_EVENT_*` defines
- `Character` struct (with full union: shape, morph, text, sprite, button variants)
- `DisplayObject` struct (with all fields: button state, sprite display list, clip actions, filters, instance name, etc.)
- The `dictionary` extern declaration

Also remove the `#ifndef NO_GRAPHICS` guard from `MouseState` and the `mouse` field in `SWFAppContext`.

Add `KeyState` to `swf.h` unconditionally (new struct — see Phase 4).

### 0.2 Merge tag_stubs.c into tag.c

`tag_stubs.c` is deleted. `tag.c` becomes the single implementation for both modes.

**Structure of `tagShowFrame` after the merge** (the most complex function): the research revealed that `tagShowFrame` has a clean internal structure that maps well to this split:

- **Steps 1–3 (lines 429–532): unconditional** — sprite frame advancement, `CLIP_EVENT_ENTER_FRAME` dispatch, button hit-test state machine, action dispatch. Zero renderer calls. These run in both modes.
- **Step 4 (lines 539–625): `#ifndef NO_GRAPHICS`** — pre-render GPU buffer writes (`renderer_write_transform`, `renderer_update_vertices`, `renderer_update_colors`, `renderer_compose_text_transforms`). No-op in NO_GRAPHICS — no GPU buffers exist.
- **Steps 5–7 (lines 627–750): `#ifndef NO_GRAPHICS`** — open render pass, render loop, close render pass. Entirely skipped in NO_GRAPHICS.

Other functions follow the same pattern: `tagDefineShape`, `tagPlaceObject2`, `tagDefineButton`, `tagDefineSprite`, etc. contain no renderer calls and are unconditional. `compose_children`, `render_single_object`, `render_display_list`, `defineBitmap`, `finalizeBitmaps`, `tagSetBackgroundColor` are entirely renderer-dependent and wrapped in `#ifndef NO_GRAPHICS`.

The parallel flat arrays in `tag_stubs.c` (`ng_sprites[]`, `ng_display[]`, `ng_buttons[]`, `ng_textfields[]`, `ng_video[]`, `ng_fonts[]`) are removed entirely; `tag.c`'s `dictionary[]` and `display_list[]` serve both modes. The `ng_advanceSprites()` / `ng_hasPlayingSprites()` helpers in `swf_core.c` are updated to call `advance_sprite_frames()` from `tag.c` directly. Build system: `tag_stubs.c` is removed from the `verify_output.py` compile step; `tag.c` is added in its place.

### 0.3 Include shape data in NO_GRAPHICS trace builds

In `main.c`, remove the `#ifndef NO_GRAPHICS` guard around `#include "draws.h"` and the `app_context.shape_data` / `app_context.transform_data` (etc.) assignments. The rendering backends are still excluded by `NO_GRAPHICS`; this only makes the data available for hit testing.

In `verify_output.py`'s `compile_native()`, add `hit_test.c` and `hit_test.h` to the files copied into the build directory.

### 0.4 Compile hit_test.c in verify_output.py

```python
# In compile_native(), add to the list of copied sources:
shutil.copy2(SWFMODERN / "src/libswf/hit_test.c", build_dir)
shutil.copy2(SWFMODERN / "include/libswf/hit_test.h", build_dir)
```

No changes to `hit_test.c` itself — it only uses `SWFAppContext.shape_data`, `transform_data`, and the `Character`/`DisplayObject` structs, all of which are now unconditional.

### Files Changed
- `SWFModernRuntime/include/libswf/swf.h` — remove `#ifndef NO_GRAPHICS` guards from structs, add `KeyState`
- `SWFModernRuntime/src/libswf/tag_stubs.c` — migrate from parallel arrays to `Character`/`DisplayObject`
- `SWFModernRuntime/src/libswf/swf_core.c` — update sprite-advance helpers to use `display_list[]`
- `SWFRecomp/wasm_wrappers/main.c` — remove `#ifndef NO_GRAPHICS` guard from `draws.h` include and data assignments
- `ruffle-tests/verify_output.py` — copy `hit_test.c`/`.h` in `compile_native()`

---

## Phase 1: verify_output.py Changes

**Goal:** Detect `input.json`, pre-process it, pass the event file path to the binary.

### 1.1 Detect input.json

In the test loop, after determining `num_frames`:

```python
input_json = test_dir / "input.json"
has_input = input_json.exists()
```

### 1.2 Pre-process to simple event file

Write a `preprocess_input_json(input_json_path, output_path)` function:

```python
def preprocess_input_json(src, dst):
    with open(src) as f:
        events = json.load(f)
    lines = []
    for evt in events:
        t = evt["type"]
        if t == "Wait":
            lines.append("WAIT")
        elif t == "MouseMove":
            x, y = evt["pos"]
            lines.append(f"MOUSE_MOVE {x} {y}")
        elif t == "MouseDown":
            x, y = evt["pos"]
            btn = evt.get("btn", "Left")
            lines.append(f"MOUSE_DOWN_{btn.upper()} {x} {y}")
        elif t == "MouseUp":
            x, y = evt["pos"]
            btn = evt.get("btn", "Left")
            lines.append(f"MOUSE_UP_{btn.upper()} {x} {y}")
        elif t == "MouseWheel":
            lines.append(f"MOUSE_WHEEL {evt['lines']}")
        elif t == "KeyDown":
            code = ruffle_key_to_flash_code(evt["key"])
            lines.append(f"KEY_DOWN {code}")
        elif t == "KeyUp":
            code = ruffle_key_to_flash_code(evt["key"])
            lines.append(f"KEY_UP {code}")
        elif t == "TextInput":
            cp = ord(evt["codepoint"]) if len(evt["codepoint"]) == 1 else ord(evt["codepoint"][0])
            lines.append(f"TEXT_INPUT {cp}")
        elif t == "TextControl":
            lines.append(f"TEXT_CONTROL {evt['code']}")
        elif t in ("FocusGained", "FocusLost"):
            lines.append(t.upper())  # FOCUSGAINED / FOCUSLOST
        # ImePreedit/ImeCommit: skip for now
    with open(dst, "w") as f:
        f.write("\n".join(lines) + "\n")
    # Return wait_count for frame count calculation
    return sum(1 for l in lines if l == "WAIT")
```

### 1.3 Key name mapping

Ruffle key format: `{ "key": "Tab" }` or `{ "key": { "Char": "a" } }`.

```python
RUFFLE_KEY_TO_FLASH = {
    "Backspace": 8, "Tab": 9, "Return": 13, "Shift": 16,
    "Control": 17, "Alt": 18, "Escape": 27, "Space": 32,
    "Left": 37, "Up": 38, "Right": 39, "Down": 40,
    "Delete": 46, "CapsLock": 20, "NumLock": 144, "ScrollLock": 145,
    "F1": 112, "F2": 113, # ... F1-F12
}

def ruffle_key_to_flash_code(key):
    if isinstance(key, str):
        return RUFFLE_KEY_TO_FLASH.get(key, 0)
    elif isinstance(key, dict) and "Char" in key:
        c = key["Char"]
        return ord(c.upper()) if c.isalpha() else ord(c)
    return 0
```

### 1.4 Integrate into compile_native

Pass the event file path as a define:

```python
def compile_native(test_dir, num_frames, build_dir, event_file=None):
    ...
    extra_defines = []
    if event_file:
        # Copy event file into build dir
        dst = build_dir / "input_events.txt"
        shutil.copy2(event_file, dst)
        extra_defines.append('-DHAS_INPUT_EVENTS')
        # Also add trace_input.c to the compilation
    ...
```

Alternatively: always compile `trace_input.c` into the build, and pass the event file path as `argv[1]` at runtime.

**Decision: pass as argv[1].** Simpler than a compile-time define — the binary checks if `argc > 1` and opens the file.

### 1.5 Integrate into run_binary

```python
def run_binary(build_dir, event_file=None):
    cmd = [str(build_dir / "test_run")]
    if event_file:
        cmd.append(str(build_dir / "input_events.txt"))
    result = subprocess.run(cmd, capture_output=True, timeout=10)
    ...
```

### 1.6 Read scale_factor from test.toml

```python
def get_scale_factor(test_dir):
    """Parse scale_factor from test.toml viewport_dimensions, default 1.0."""
    toml_path = test_dir / "test.toml"
    if toml_path.exists():
        text = toml_path.read_text()
        m = re.search(r"scale_factor\s*=\s*([\d.]+)", text)
        if m:
            return float(m.group(1))
    return 1.0
```

Pass `scale_factor` to `preprocess_input_json()` so it can apply the division before writing the event file. Of the 62 input tests, only `mouse_pos_with_scale_factor` has `scale_factor = 2.0`; all others use 1.0. The formula applied during pre-processing is: `stage_px = input_px / scale_factor` (yielding logical Flash stage pixels).

### 1.7 Update get_num_frames to account for waits

```python
def get_num_frames(test_dir, wait_count=0):
    declared = ...  # existing logic
    return max(declared, wait_count + 1)
```

### Files Changed
- `ruffle-tests/verify_output.py` — `preprocess_input_json()`, `get_scale_factor()`, `ruffle_key_to_flash_code()`, update `compile_native()` and `run_binary()`, update `get_num_frames()`

---

## Phase 2: Event File Format

The pre-processed file written to the temp build dir. One event per line.

```
MOUSE_MOVE 270.0 182.0
MOUSE_DOWN_LEFT 270.0 182.0
WAIT
MOUSE_MOVE 275.0 183.0
MOUSE_UP_LEFT 275.0 183.0
WAIT
KEY_DOWN 9
KEY_UP 9
WAIT
TEXT_INPUT 65
TEXT_CONTROL Backspace
FOCUSGAINED
FOCUSLOST
```

**Token reference:**

| Token | Fields | Meaning |
|---|---|---|
| `WAIT` | — | Advance one frame tick before processing more events |
| `MOUSE_MOVE` | x y | Mouse moved to (x, y) in stage pixels (not twips) |
| `MOUSE_DOWN_LEFT` | x y | Left button pressed at (x, y) |
| `MOUSE_UP_LEFT` | x y | Left button released at (x, y) |
| `MOUSE_DOWN_RIGHT` | x y | Right button pressed |
| `MOUSE_UP_RIGHT` | x y | Right button released |
| `MOUSE_WHEEL` | delta | Scroll wheel (positive = down) |
| `KEY_DOWN` | code | Key pressed (Flash key code 0–255) |
| `KEY_UP` | code | Key released |
| `TEXT_INPUT` | codepoint | Unicode character input (for text fields) |
| `TEXT_CONTROL` | name | Control action: Backspace, Delete, SelectAll, etc. |
| `FOCUSGAINED` | — | Application gained focus |
| `FOCUSLOST` | — | Application lost focus |

**Coordinate system:** Ruffle's `input.json` positions are in viewport pixel coordinates. `preprocess_input_json()` divides by `scale_factor` (from `test.toml`, default 1.0) to produce logical Flash stage pixel coordinates, which are what the event file stores. The C event pump then multiplies by 20 to convert to twips before storing in `MouseState.stage_x/y`, since `hit_test.c` and all transform geometry use twips. `_xmouse`/`_ymouse` return `stage_x / 20.0f` (pixels) to ActionScript. The two-step conversion (`/ scale_factor` in Python, `* 20` in C) keeps each layer doing one job.

---

## Phase 3: C Event Pump

**Goal:** Load the event file at startup, deliver events to the runtime at the correct tick boundaries.

### 3.1 Data structures

In `swf_core.c` (or new `trace_input.c`):

```c
typedef enum {
    EV_WAIT,
    EV_MOUSE_MOVE,
    EV_MOUSE_DOWN_LEFT,  EV_MOUSE_UP_LEFT,
    EV_MOUSE_DOWN_RIGHT, EV_MOUSE_UP_RIGHT,
    EV_MOUSE_WHEEL,
    EV_KEY_DOWN, EV_KEY_UP,
    EV_TEXT_INPUT,
    EV_TEXT_CONTROL_BACKSPACE, EV_TEXT_CONTROL_DELETE,
    EV_TEXT_CONTROL_SELECT_ALL,
    EV_FOCUS_GAINED, EV_FOCUS_LOST,
} EventType;

typedef struct {
    EventType type;
    float x, y;      // for mouse events
    int code;        // for key events, text input codepoint
} InputEvent;

static InputEvent* g_events = NULL;
static size_t g_event_count = 0;
static size_t g_event_pos = 0;   // cursor: next event to deliver
```

### 3.2 Loading

```c
void input_events_load(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) return;
    // Count lines for allocation
    char line[128];
    size_t count = 0;
    while (fgets(line, sizeof(line), f)) count++;
    rewind(f);
    g_events = malloc(count * sizeof(InputEvent));
    g_event_count = 0;
    while (fgets(line, sizeof(line), f)) {
        InputEvent ev = {0};
        if (strncmp(line, "WAIT", 4) == 0)         ev.type = EV_WAIT;
        else if (strncmp(line, "MOUSE_MOVE", 10) == 0)
            { sscanf(line, "MOUSE_MOVE %f %f", &ev.x, &ev.y); ev.type = EV_MOUSE_MOVE; }
        // ... etc
        g_events[g_event_count++] = ev;
    }
    fclose(f);
}
```

### 3.3 Delivery — per-tick pump

Called at the start of each tick, before `ng_advanceSprites` and `funcs[current_frame]`:

```c
void input_events_pump_tick(SWFAppContext* app_context) {
    // Deliver all events up to (but not including) the next WAIT
    while (g_event_pos < g_event_count) {
        InputEvent* ev = &g_events[g_event_pos];
        if (ev->type == EV_WAIT) {
            g_event_pos++;  // consume the WAIT
            return;
        }
        input_events_deliver(app_context, ev);
        g_event_pos++;
    }
    // No more events — no-op on subsequent ticks
}
```

### 3.4 Integration into swfStart

```c
// In main():
if (argc > 1) {
    input_events_load(argv[1]);
}

// In swfStart() tick loop, just before ng_advanceSprites:
if (g_events) {
    input_events_pump_tick(app_context);
}
ng_advanceSprites(app_context);
if (is_playing || manual_next_frame) {
    funcs[current_frame](app_context);
}
```

### 3.5 Delivery — individual event dispatch

```c
void input_events_deliver(SWFAppContext* app_context, InputEvent* ev) {
    MouseState* ms = &app_context->mouse;
    switch (ev->type) {
    case EV_MOUSE_MOVE:
        // ev->x/y are already in logical Flash stage pixels (scale_factor applied in Python).
        // mouse.stage_x/y are stored in twips (×20) to match hit_test.c expectations.
        // _xmouse/_ymouse return stage_x/20 (pixels) to ActionScript.
        ms->stage_x = ev->x * 20.0f;
        ms->stage_y = ev->y * 20.0f;
        ms->moved = 1;
        // TODO Phase 5: dispatch onMouseMove to listeners
        break;
    case EV_MOUSE_DOWN_LEFT:
        ms->stage_x = ev->x * 20.0f;
        ms->stage_y = ev->y * 20.0f;
        ms->button_down = 1;
        ms->clicked = 1;
        // TODO Phase 5: dispatch onMouseDown to listeners + hit-test for onPress
        break;
    case EV_MOUSE_UP_LEFT:
        ms->stage_x = ev->x * 20.0f;
        ms->stage_y = ev->y * 20.0f;
        ms->button_down = 0;
        ms->released = 1;
        // TODO Phase 5: dispatch onMouseUp to listeners + hit-test for onRelease
        break;
    case EV_MOUSE_WHEEL:
        // TODO: Mouse wheel support
        break;
    case EV_KEY_DOWN:
        if (ev->code >= 0 && ev->code < 256)
            app_context->keys.down[ev->code] = 1;
        app_context->keys.last_key_down = ev->code;
        // TODO Phase 7: dispatch onKeyDown to listeners
        break;
    case EV_KEY_UP:
        if (ev->code >= 0 && ev->code < 256)
            app_context->keys.down[ev->code] = 0;
        // TODO Phase 7: dispatch onKeyUp
        break;
    case EV_TEXT_INPUT:
        // TODO Phase 8: deliver to focused text field
        break;
    case EV_TEXT_CONTROL_BACKSPACE:
        // TODO Phase 8
        break;
    default:
        break;
    }
}
```

### Files Changed
- `SWFModernRuntime/src/libswf/swf_core.c` — `input_events_load()`, `input_events_pump_tick()`, `input_events_deliver()`, integrate into tick loop and `main()`

---

## Phase 4: Mouse and Key State

**Goal:** Add `KeyState` to `SWFAppContext` (Phase 0 already handles `MouseState`), and expose both to `action.c` for built-in property access.

### 4.1 KeyState struct (in swf.h, unconditional)

```c
typedef struct KeyState {
    uint8_t down[256];    // Flash key code → 1 if currently pressed
    uint8_t toggled[3];   // [0]=CapsLock, [1]=NumLock, [2]=ScrollLock
    int last_key_down;    // most recent keydown code (-1 = none)
} KeyState;
```

Add `KeyState keys;` to `SWFAppContext`. This was already planned in Phase 0 (§0.1) — this phase documents how `action.c` uses it.

### 4.2 Expose to action.c

Mouse and key state are needed in `action.c` for:
- `_xmouse`, `_ymouse` built-in properties → read from `app_context->mouse.stage_x / 20.0f`
- `Key.isDown(code)` → read from `app_context->keys.down[code]`
- `Key.isToggled(code)` → read from `app_context->keys.toggled[]`
- `Key.getCode()` → `app_context->keys.last_key_down`

These accessors already receive `SWFAppContext*` as their first argument, so no signature changes are needed.

### 4.3 Reset per-frame edge flags

At the start of each tick, before event injection, clear the one-shot flags:

```c
app_context->mouse.moved   = 0;
app_context->mouse.clicked = 0;
app_context->mouse.released = 0;
app_context->keys.last_key_down = -1;
```

### Files Changed
- `SWFModernRuntime/include/libswf/swf.h` — `KeyState` struct, `keys` field in `SWFAppContext` (done in Phase 0)
- `SWFModernRuntime/src/libswf/swf_core.c` — per-tick flag reset
- `SWFModernRuntime/src/actionmodern/action.c` — `_xmouse`/`_ymouse` property read, `Key` object skeleton

---

## Phase 5: Global Mouse Event Dispatch

**Goal:** Implement `Mouse.addListener()` and `onClipEvent(mouseDown/Up/Move)` dispatch. No hit testing needed for this phase — events go to all registered listeners.

This phase unlocks **Mouse/Focus event tests that use global listeners** (`mouse_listeners`, `mouse_pos`, `mouse_pos_with_scale_factor`, `mouse_events` partially).

### 5.1 Mouse.addListener mechanism

Flash's `Mouse` object is a special global with static methods. `Mouse.addListener(obj)` registers an object; when a mouse event fires, the runtime calls `obj.onMouseDown()`, `obj.onMouseUp()`, `obj.onMouseMove()` if those methods exist.

This is the same AsBroadcaster pattern used by `Key`, `Stage`, `TextField`, etc.

**Implementation in action.c:**
- Add `g_mouse_listeners` — an `ASObject*` or a linked list of `ActionVar` objects registered via `Mouse.addListener()`
- In the event pump (or in a new `dispatch_mouse_event()` function called from the pump), iterate `g_mouse_listeners` and call the appropriate method on each

```c
// Called by input_events_deliver for EV_MOUSE_DOWN_LEFT:
void dispatch_onMouseDown(SWFAppContext* app_context) {
    // Iterate Mouse listeners, call obj.onMouseDown() on each
    for (size_t i = 0; i < g_mouse_listener_count; i++) {
        ActionVar* obj = &g_mouse_listeners[i];
        call_method_on_object(app_context, obj, "onMouseDown", 0);
    }
}
```

### 5.2 _xmouse / _ymouse properties

These built-in MovieClip properties return the mouse position in pixels (not twips). The implementation reads `app_context->mouse.stage_x / 20.0f`. They are accessed via `ActionGetProperty` with property indices or via path-based variable access; the existing `actionGetProperty` handler needs cases added.

### 5.3 onClipEvent(mouseDown/Up/Move/keyDown/keyUp) — runtime-only change

**The recompiler already emits all `onClipEvent` handler bodies.** Research confirmed that `action.cpp` compiles every `onClipEvent` type (including mouseDown, mouseUp, mouseMove, keyDown, keyUp, press, release, etc.) into `clip_action_N()` functions and stores them in `ClipAction` structs with the full SWF event_flags bitmask via `tagPlaceObject2WithClipActions`. No recompiler changes are needed.

The runtime currently dispatches only `CLIP_EVENT_LOAD`, `CLIP_EVENT_ENTER_FRAME`, and `CLIP_EVENT_UNLOAD`. Adding mouse/key dispatch is purely a runtime addition: in the event pump's `input_events_deliver()`, after updating mouse state, iterate `display_list[]` and call any `clip_actions[i].action(app_context)` where `clip_actions[i].event_flags & CLIP_EVENT_MOUSE_DOWN` (or the appropriate flag) is set.

```c
// Example: dispatch CLIP_EVENT_MOUSE_DOWN to all clips
void dispatch_clip_event(SWFAppContext* app_context, uint32_t event_flag) {
    for (size_t d = 0; d < max_depth; d++) {
        DisplayObject* obj = &display_list[d];
        for (size_t a = 0; a < obj->clip_action_count; a++) {
            if (obj->clip_actions[a].event_flags & event_flag)
                obj->clip_actions[a].action(app_context);
        }
    }
}
```

### Files Changed
- `SWFModernRuntime/src/actionmodern/action.c` — `Mouse.addListener()`, `Mouse.removeListener()`, `Mouse.broadcastMessage()`, `_xmouse`/`_ymouse` property access
- `SWFModernRuntime/src/libswf/tag.c` — `dispatch_clip_event()` helper; call from event pump for MOUSE_DOWN/UP/MOVE flags

---

## Phase 6: Per-Clip Hit Testing and Event Dispatch

**Goal:** Dispatch `onPress`, `onRelease`, `onRollOver`, `onRollOut` to the specific clip the mouse is over, using the same triangle-level `hit_test.c` infrastructure as the graphics mode.

This phase unlocks **button_goto**, **button_v5/v6**, **button_properties_special_cases**, **root_button_mode**, and tests that use `MovieClip.onPress`.

### 6.1 Hit testing — same code as graphics mode

After Phase 0, `hit_test.c` is compiled into trace builds and `shape_data`/`transform_data` are available in `SWFAppContext`. The existing `hit_test_shape()` and related functions work unchanged. No new hit testing code is needed.

The button state machine already implemented in `tag.c` for graphics mode (hit-test → state transition → `onPress`/`onRelease`/etc. dispatch) likewise becomes available in the trace build after Phase 0, because the function logic is not guarded by `#ifndef NO_GRAPHICS` — only the render calls are.

### 6.2 Event dispatch — same logic as graphics mode

On `EV_MOUSE_DOWN_LEFT`:
1. Update `app_context->mouse` state (stage_x/y, button_down, clicked)
2. The existing `tagShowFrame` button-state-machine loop (already in `tag.c`) runs at the top of each tick — it performs hit testing and fires `onPress` / state transition actions automatically

On `EV_MOUSE_UP_LEFT` / `EV_MOUSE_MOVE`:
- Same: mouse state is updated by the event pump; `tag.c`'s per-frame button/clip-event dispatch reads it

### 6.3 Verify tagShowFrame runs in NO_GRAPHICS builds

After Phase 0, confirm that `tagShowFrame` in `tag.c` (not `tag_stubs.c`) runs the button state machine and clip-event dispatch in trace builds. If `tag_stubs.c` still overrides `tagShowFrame` with a simplified stub, migrate the stub to call the shared logic.

### Files Changed
- No new files — this is fully enabled by Phase 0. After Phase 0, `tag.c`'s button state machine runs in trace builds and `hit_test.c` is compiled in; Phase 6 has no additional code changes beyond confirming correct behaviour.
- `SWFModernRuntime/src/libswf/swf_core.c` — event pump sets mouse state; `tag.c` logic handles the rest

---

## Phase 7: Key Events

**Goal:** Implement `Key.isDown()`, `Key.getCode()`, `Key.addListener()`, `onKeyDown`/`onKeyUp` dispatch.

This phase unlocks **key_isToggled**, **button_key_events**, **button_key_events_special**, **button_keypress** variants, and parts of **tab ordering**.

### 7.1 Key object in action.c

The `Key` object is a global singleton similar to `Mouse`. Required methods/properties:
- `Key.isDown(code)` → `app_context->keys.down[code]`
- `Key.getCode()` → `app_context->keys.last_key_down`
- `Key.getAscii()` → ASCII value of last key (for printable keys)
- `Key.isToggled(keyCode)` → `app_context->keys.toggled[...]`
- `Key.addListener(obj)` / `Key.removeListener(obj)` — AsBroadcaster pattern

### 7.2 onKeyDown/onKeyUp dispatch

On `EV_KEY_DOWN`:
1. Update `keys.down[code]` and `keys.last_key_down`
2. Broadcast `onKeyDown()` to all Key listeners
3. Check for button key handlers (button_keypress tests use buttons triggered by key presses)

### 7.3 Button key events

DefineButton2 BUTTONCONDACTION has a key-press condition (bits 9–15 = key code). When a key is pressed, check all button instances in the display list for matching key conditions and fire their actions.

This requires the button action data to be available in NO_GRAPHICS mode — currently only stored in the graphics-mode `Character` struct.

### Files Changed
- `SWFModernRuntime/src/actionmodern/action.c` — `Key` object implementation
- `SWFModernRuntime/src/libswf/swf_core.c` — key event dispatch, button key handlers
- `SWFModernRuntime/include/libswf/swf.h` — `KeyState` struct in `SWFAppContext`

---

## Phase 8: Focus System

**Goal:** Implement `Selection.setFocus()`, focus tracking, and TextInput delivery to focused text fields.

This phase unlocks **edittext_input**, **edittext_restrict**, **edittext_input_newlines**, **edittext_password_copy**, **focus_mouse**, and focus-related tests.

### 8.1 Focus state

```c
// In SWFAppContext (or global in swf_core.c):
size_t focused_depth;      // depth of the focused object, -1 = none
int focused_is_textfield;  // 1 if focused object is a text field
```

### 8.2 Focus acquisition

On `EV_MOUSE_DOWN_LEFT`: after determining which clip was clicked, check if it's a text field. If so, set it as focused. Fire `onSetFocus` on the newly focused clip and `onKillFocus` on the previously focused clip.

### 8.3 Selection object

`Selection.setFocus(target)` — sets focused object programmatically.
`Selection.getFocus()` — returns path of focused object.
`Selection.setSelection(start, end)` — sets caret/selection in focused text field.

### 8.4 TextInput delivery

On `EV_TEXT_INPUT`:
1. Check `focused_is_textfield`
2. If focused: append character to the text field's content, respecting `restrict` and `maxChars`
3. Dispatch `onChanged` event

TextControl (Backspace, Delete, etc.) follows similar logic against the focused text field.

### Files Changed
- `SWFModernRuntime/src/actionmodern/action.c` — `Selection` object, `TextField` text editing methods
- `SWFModernRuntime/src/libswf/swf_core.c` — focus tracking, text input dispatch

---

## Phase 9: Tab Ordering

**Goal:** Implement focus navigation via Tab key and the associated `tabIndex`/`tabEnabled`/`tabChildren` properties.

This phase unlocks the 14 **tab_ordering_*** tests.

### 9.1 Tab order computation

When Tab is pressed:
1. Collect all focusable objects (MovieClips with `tabEnabled != false`, buttons, text fields)
2. Sort by: objects with explicit `tabIndex` first (sorted numerically), then automatic order (top-to-bottom, left-to-right by position)
3. Find the currently focused object in the sorted list
4. Move focus to the next (or previous, for Shift+Tab) entry

### 9.2 tabEnabled / tabIndex / tabChildren properties

These are MovieClip/Button properties stored in the display object or AS object's property bag. `tabEnabled` defaults to `undefined` (treated as `true` for buttons/text fields, `false` for movie clips). `tabIndex` defaults to `undefined`.

### 9.3 Focus events

`onSetFocus(old)` / `onKillFocus(new)` fire on the MovieClip when focus changes. `Selection.broadcastMessage("onSetFocus", old)` notifies Selection listeners.

### Files Changed
- `SWFModernRuntime/src/actionmodern/action.c` — tab order computation, `tabEnabled`/`tabIndex`/`tabChildren` property handling
- `SWFModernRuntime/src/libswf/swf_core.c` — Tab key handling, focus navigation

---

## Files Changed Summary

| Phase | File | Changes |
|---|---|---|
| 0 | `SWFModernRuntime/include/libswf/swf.h` | Remove `#ifndef NO_GRAPHICS` guards from structs; add `KeyState` |
| 0 | `SWFModernRuntime/src/libswf/tag_stubs.c` | **Deleted** — logic merged into `tag.c` |
| 0 | `SWFModernRuntime/src/libswf/tag.c` | Add `#ifndef NO_GRAPHICS` guards around render calls only; all tag logic unconditional |
| 0 | `SWFModernRuntime/src/libswf/swf_core.c` | Update sprite-advance helpers to use `display_list[]` |
| 0 | `SWFRecomp/wasm_wrappers/main.c` | Remove `#ifndef NO_GRAPHICS` guard from `draws.h` include and data assignments |
| 0 | `ruffle-tests/verify_output.py` | Copy `hit_test.c`/`.h` in `compile_native()` |
| 1 | `ruffle-tests/verify_output.py` | `preprocess_input_json()`, key mapping, pass event file to binary |
| 3 | `SWFModernRuntime/src/libswf/swf_core.c` | Event pump: load, tick pump, deliver |
| 4 | `SWFModernRuntime/src/libswf/swf_core.c` | Per-tick edge-flag reset |
| 4 | `SWFModernRuntime/src/actionmodern/action.c` | `_xmouse`/`_ymouse` property, `Key` object skeleton |
| 5 | `SWFModernRuntime/src/actionmodern/action.c` | `Mouse` object, `onClipEvent` registration + global dispatch |
| 5 | `SWFRecomp/src/action/action.cpp` | Emit clip event registrations for mouse/key clip events |
| 6 | `SWFModernRuntime/src/libswf/tag_stubs.c` | Remove any `tagShowFrame` stub bypassing button state machine |
| 7 | `SWFModernRuntime/src/actionmodern/action.c` | `Key` object full implementation, key listener dispatch |
| 7 | `SWFModernRuntime/src/libswf/swf_core.c` | Button key-press dispatch |
| 8 | `SWFModernRuntime/src/actionmodern/action.c` | `Selection` object, text field editing methods |
| 8 | `SWFModernRuntime/src/libswf/swf_core.c` | Focus tracking, text input dispatch |
| 9 | `SWFModernRuntime/src/actionmodern/action.c` | Tab order computation, `tabEnabled`/`tabIndex`/`tabChildren` |
| 9 | `SWFModernRuntime/src/libswf/swf_core.c` | Tab key handling, focus navigation |

---

## Open Questions

1. **[RESOLVED] Bounding box source in NO_GRAPHICS mode:** Not needed. Phase 0 includes `shape_data`/`transform_data` in trace builds so `hit_test.c` can do full triangle-level hit testing, identical to graphics mode.

2. **[RESOLVED] Button character data in NO_GRAPHICS mode:** Not needed as a separate concern. Phase 0 migrates `tag_stubs.c` to use the same `Character` struct (with `CHAR_TYPE_BUTTON`, `button_state_funcs`, `button_actions`, etc.) as `tag.c`. The runtime already has all the data it needs.

3. **[RESOLVED] Mouse position coordinate system:** Verified against `mouse_pos` and `mouse_pos_with_scale_factor`. Ruffle's `input.json` positions are in viewport pixels. `_xmouse`/`_ymouse` return logical Flash stage pixel values (viewport pixels divided by scale_factor). `mouse.stage_x/y` are stored in twips (stage pixels × 20) to match `hit_test.c`'s geometry. The two-step conversion: Python divides by scale_factor, C multiplies by 20. Only one test (`mouse_pos_with_scale_factor`) uses a non-1.0 scale factor; all 64 others omit `viewport_dimensions` entirely (defaults to scale 1.0). See Phase 1.6 and Phase 3.5.

4. **[RESOLVED] `onClipEvent` emission in the recompiler:** The recompiler already fully compiles all `onClipEvent` types — including mouseDown, mouseUp, mouseMove, keyDown, keyUp, press, release, etc. — into `clip_action_N()` functions with correct event_flags bitmasks, stored via `tagPlaceObject2WithClipActions`. No recompiler changes needed for Phase 5. Only runtime dispatch needs to be added for the currently-unhandled flag bits.

5. **TextInput for SWF version < 6:** Still unverified. Defer to Phase 8 implementation — check SWF version of `edittext_input` at that time.

6. **[RESOLVED] Phase 0 scope — full tag.c unification:** Phase 0 will merge `tag_stubs.c` and `tag.c` into a single implementation where only the render calls (wgpuDevice, draw commands, renderer_* macros) are guarded by `#ifndef NO_GRAPHICS`. All tag logic — display list management, button state machine, sprite advancement, clip event dispatch, hit testing — lives once in `tag.c`. `tag_stubs.c` is deleted.
