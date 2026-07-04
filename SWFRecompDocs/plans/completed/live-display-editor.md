> **AUDIT OUTCOME (2026-07-04):** Built — demos/runtime-swf/display_editor.

# Live Display List Editor

## Goal

Build a web-based tool that shows a recompiled Flash SWF running with WebGPU
graphics, with a JSON editor alongside that displays the display list data
(positions, colors, scales, rotations). The user can edit the JSON and click
a button to push changes back to the running SWF, seeing the shapes update
in real time.

This is ultimately intended as a module in `~/CC/Archipelago-CC/frontend`,
using its existing module system and JSON editor infrastructure.

## Milestones

### Milestone 1: Graphics demo with trace output showing shape data

A WASM graphics demo with visible shapes. After each frame, a C function
traces the display list as structured text (position, color, size for each
visible object).

**What's needed:**
- A test SWF with visible shapes (can reuse existing graphics test SWFs)
- Add `g_after_tick_handler` invocation to `swf.c`'s frame loop (one-line fix)
- A `test_harness.c` that dumps display list data after tick 1
- Graphics WASM build support in `verify_output.py` (new `compile_wasm_graphics`)

**New emcc flags for graphics mode:**
```
-DUSE_WEBGPU
--use-port=emdawnwebgpu
-sASYNCIFY
-sASYNCIFY_STACK_SIZE=65536
-sINITIAL_MEMORY=64MB
```
Plus `swf.c` instead of `swf_core.c`, and `render_webgpu.c`.

**HTML changes:** Canvas element + async `ccall('runSWF', ..., {async:true})`.

### Milestone 2: JS-callable C functions to get/set display list data

Export C functions via `EMSCRIPTEN_KEEPALIVE` that JavaScript can call:

```c
// Returns JSON string with display list data (caller must free)
EMSCRIPTEN_KEEPALIVE
const char* getDisplayListJSON(void);

// Set transform properties for a display object by depth
EMSCRIPTEN_KEEPALIVE
void setObjectTransform(int depth, float x, float y,
                        float xscale, float yscale, float rotation);

// Set color transform for a display object by depth
EMSCRIPTEN_KEEPALIVE
void setObjectColor(int depth, float ra, float ga, float ba, float aa,
                    float rb, float gb, float bb, float ab);

// Set alpha for a display object by depth
EMSCRIPTEN_KEEPALIVE
void setObjectAlpha(int depth, float alpha);
```

**getDisplayListJSON output format:**
```json
{
  "displayList": [
    {
      "depth": 1,
      "charId": 3,
      "charType": "shape",
      "name": "box1",
      "transformId": 1,
      "x": 100.0,
      "y": 50.0,
      "xscale": 100.0,
      "yscale": 100.0,
      "rotation": 0.0,
      "alpha": 100.0,
      "color": {
        "ra": 100, "ga": 100, "ba": 100, "aa": 100,
        "rb": 0, "gb": 0, "bb": 0, "ab": 0
      }
    }
  ]
}
```

**Data flow for reads:**
```
JS calls ccall('getDisplayListJSON') →
  C iterates display_list[] →
  For each depth: read transform_data[transform_id*16] →
  Decompose matrix to x, y, xscale, yscale, rotation →
  Read cxform data → Format as JSON string → return pointer
```

**Data flow for writes:**
```
JS calls ccall('setObjectTransform', ..., [depth, x, y, ...]) →
  C finds MovieClip by display_list[depth].instance_name →
  Sets mc->x, mc->y, mc->xscale, etc. →
  Sets mc->as_set_flags bitmask →
  Next tagShowFrame() calls apply_as_transform() →
  renderer_write_transform() syncs to GPU →
  Shape appears at new position
```

**For shapes without MovieClips** (plain shapes at a depth, no instance name):
Modify `transform_data` directly and call `renderer_write_transform()`.
This bypasses the MovieClip property system but works for static shapes.

### Milestone 3: Standalone HTML page with textarea JSON editor

A self-contained HTML page (in `docs/injector/`) with:
- WebGPU canvas showing the SWF
- A `<textarea>` showing the JSON from `getDisplayListJSON()`
- A "Refresh" button that re-reads the display list into the textarea
- An "Apply" button that parses the edited JSON and calls `setObjectTransform`
  for each modified entry
- Auto-refresh option (poll every N ms)

**HTML layout:**
```
┌─────────────────────────────────────┐
│  SWF Display Editor                 │
├──────────────┬──────────────────────┤
│              │ {                    │
│   WebGPU     │   "displayList": [  │
│   Canvas     │     { "depth": 1,   │
│              │       "x": 100,     │
│              │       ...           │
│              │     }               │
│              │   ]                 │
│              │ }                   │
├──────────────┴──────────────────────┤
│  [Refresh]  [Apply]  [Auto-refresh]│
└─────────────────────────────────────┘
```

**JavaScript bridge:**
```javascript
function refreshData() {
    var ptr = Module.ccall('getDisplayListJSON', 'string', [], []);
    document.getElementById('json-editor').value = ptr;
}

function applyData() {
    var data = JSON.parse(document.getElementById('json-editor').value);
    data.displayList.forEach(function(obj) {
        Module.ccall('setObjectTransform', null,
            ['number','number','number','number','number','number'],
            [obj.depth, obj.x, obj.y, obj.xscale, obj.yscale, obj.rotation]);
    });
}
```

### Milestone 4: Archipelago-CC module integration

Port the standalone page into an Archipelago-CC frontend module:
- Module ID: `swfDisplayEditor` (or similar)
- Uses the existing module system (`~/CC/Archipelago-CC/frontend/modules/`)
- JSON editor panel using existing `json` module infrastructure or CodeMirror6
- Canvas panel using `iframe-base` or direct WebGPU integration
- Event bus for cross-module communication (e.g., editor changes → SWF updates)

This milestone is out of scope for the SWFRecomp-CC repo — it lives in
Archipelago-CC and imports the WASM build from here.

## Implementation Plan

### Phase 1: Infrastructure (in SWFRecomp-CC)

1. **Add tick handler to graphics frame loop** (`swf.c`)
   - Add `g_after_tick_handler` call after `renderer_poll()` in the main loop
   - Small change, same pattern as `swf_core.c`

2. **Add graphics WASM build to verify_output.py**
   - New `compile_wasm_graphics()` function
   - Uses `swf.c` instead of `swf_core.c`, adds `render_webgpu.c`
   - Adds ASYNCIFY, USE_WEBGPU, emdawnwebgpu flags
   - Canvas-enabled HTML template

3. **Create bridge functions** (`display_bridge.c`)
   - `getDisplayListJSON()` — reads display_list + transform_data + cxform
   - `setObjectTransform()` — writes to MovieClip or direct transform_data
   - `setObjectColor()` — writes to DisplayObject cx_* fields
   - Lives in `SWFRecomp/wasm_wrappers/` alongside `main.c`
   - Compiled into WASM when `-DHAS_DISPLAY_BRIDGE` is defined

4. **Create a graphics test SWF** with visible shapes
   - A simple SWF with 3-4 colored rectangles at different positions
   - Named instances so MovieClip properties work
   - Multi-frame so shapes persist and can be edited live

### Phase 2: Standalone demo (in SWFRecomp-CC)

5. **Build and deploy graphics WASM demo**
   - `demos/runtime-swf/display_editor/`
   - Test SWF + display_bridge.c
   - Deploy to `docs/injector/display_editor.html`

6. **Create editor HTML page**
   - Canvas + textarea + buttons
   - JavaScript bridge calling getDisplayListJSON/setObjectTransform
   - Deployed as a standalone page in `docs/injector/`

### Phase 3: Archipelago integration (in Archipelago-CC)

7. **Create module in Archipelago-CC**
   - Import WASM artifacts from SWFRecomp-CC build
   - Use module system for panel layout
   - Event bus integration for editor↔canvas communication

## Key Technical Details

### Transform matrix layout (per slot, 16 floats)

```
Index:  [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]  ...  [12] [13] [14] [15]
Field:   a    b    0    0    c    d    0    0    ...   tx   ty   0    1

a = scaleX * cos(rotation)
b = scaleX * sin(rotation)
c = -scaleY * sin(rotation)
d = scaleY * cos(rotation)
tx = x position in twips (divide by 20 for pixels)
ty = y position in twips (divide by 20 for pixels)
```

### Decomposition (matrix → properties)

```c
float x = slot[12] / 20.0f;              // twips to pixels
float y = slot[13] / 20.0f;
float xscale = sqrtf(slot[0]*slot[0] + slot[1]*slot[1]) * 100.0f;
float yscale = sqrtf(slot[4]*slot[4] + slot[5]*slot[5]) * 100.0f;
float rotation = atan2f(slot[1], slot[0]) * 180.0f / M_PI;
```

### Recomposition (properties → matrix)

```c
float sx = xscale / 100.0f;
float sy = yscale / 100.0f;
float rad = rotation * M_PI / 180.0f;
float c = cosf(rad), s = sinf(rad);
slot[0] = sx * c;   slot[1] = sx * s;
slot[4] = -sy * s;  slot[5] = sy * c;
slot[12] = roundf(x * 20.0f);  // pixels to twips
slot[13] = roundf(y * 20.0f);
```

### GPU sync after external modification

For objects with a MovieClip (named instances):
- Set `mc->x`, `mc->y`, etc. + `mc->as_set_flags`
- `tagShowFrame()` automatically calls `apply_as_transform()` + GPU sync

For plain shapes (no MovieClip):
- Modify `transform_data` directly
- Call `renderer_write_transform(context, transform_id, slot)` manually
- Need access to `RenderContext*` — stored in `swf.c`'s static `context` variable

### Limitations

- **Shape bounds:** Getting _width/_height requires `mcGetEffectiveSize()` which
  needs the shape's bounding box from the dictionary. Available for MovieClips
  but harder for plain shapes.
- **Nested sprites:** Child sprites have composed transforms. Editing a child's
  position requires decomposing the parent-relative transform, not the global one.
- **Frame advancement:** If the SWF's frame scripts set properties every frame,
  user edits get overwritten. May need a "pause scripts" mode.
- **Thread safety:** ASYNCIFY means JS and C interleave but don't run concurrently.
  Bridge calls are safe as long as they happen between frames (e.g., during
  `emscripten_sleep`).

## Decisions

- **Bridge functions** live in a separate `display_bridge.c` in
  `SWFRecomp/wasm_wrappers/`, compiled when `-DHAS_DISPLAY_BRIDGE` is defined.
- **`getDisplayListJSON`** uses a static buffer (simpler for v1, no caller-side
  free needed).
- **Archipelago module** loads the WASM in an iframe, using the frontend's
  existing iframe infrastructure.
