# Milestone 2: Display Bridge — JS↔C functions for live display list editing

## Context

We have a working graphics WASM demo (`docs/injector/display_editor.html`) that
renders 3 colored rectangles via WebGPU and dumps the display list via a C test
harness. The next step is to add exported C functions that JavaScript can call to
read and modify the display list in real time.

**Key docs to read:**
- `SWFRecompDocs/plans/live-display-editor.md` — full plan with milestones and technical details
- `demos/runtime-swf/display_editor/test_harness.c` — existing C code that reads the display list
- `SWFRecomp/wasm_wrappers/main.c` — WASM entry point with `runSWF()` export
- `SWFModernRuntime/include/libswf/swf.h` — `DisplayObject` struct, `SWFAppContext`
- `SWFModernRuntime/src/libswf/tag.c` — `apply_as_transform()`, `renderer_write_transform()`

## What to build

### 1. `display_bridge.c` (new file in `SWFRecomp/wasm_wrappers/`)

A C file compiled when `-DHAS_DISPLAY_BRIDGE` is defined. Contains exported
functions callable from JavaScript via `Module.ccall()`:

```c
#include <emscripten.h>

// Returns a JSON string describing the display list.
// Uses a static buffer (no caller-side free needed).
EMSCRIPTEN_KEEPALIVE
const char* getDisplayListJSON(void);

// Modify the transform for a display object at the given depth.
// x, y in pixels. xscale, yscale as percentages (100 = normal).
// rotation in degrees.
EMSCRIPTEN_KEEPALIVE
void setObjectTransform(int depth, float x, float y,
                        float xscale, float yscale, float rotation);
```

**getDisplayListJSON output format:**
```json
{
  "displayList": [
    {
      "depth": 1,
      "charId": 1,
      "charType": "shape",
      "transformId": 1,
      "x": 50.0,
      "y": 50.0,
      "xscale": 100.0,
      "yscale": 100.0,
      "rotation": 0.0
    }
  ]
}
```

**Implementation notes for getDisplayListJSON:**
- Iterate `display_list[1..max_depth]` (extern from swf.h)
- For each entry with `char_id != 0`, read the transform matrix:
  ```c
  float* slot = (float*)app_context->transform_data + obj->transform_id * 16;
  float x = slot[12] / 20.0f;  // twips to pixels
  float y = slot[13] / 20.0f;
  float xscale = sqrtf(slot[0]*slot[0] + slot[1]*slot[1]) * 100.0f;
  float yscale = sqrtf(slot[4]*slot[4] + slot[5]*slot[5]) * 100.0f;
  float rotation = atan2f(slot[1], slot[0]) * 180.0f / M_PI;
  ```
- Format into a static `char` buffer (8KB should be plenty for v1)
- Return pointer to the static buffer

**Implementation notes for setObjectTransform:**
- These shapes have no MovieClip (no instance names), so modify `transform_data` directly:
  ```c
  float* slot = (float*)app_context->transform_data + obj->transform_id * 16;
  float sx = xscale / 100.0f;
  float sy = yscale / 100.0f;
  float rad = rotation * M_PI / 180.0f;
  float c = cosf(rad), s = sinf(rad);
  slot[0] = sx * c;   slot[1] = sx * s;
  slot[4] = -sy * s;  slot[5] = sy * c;
  slot[12] = roundf(x * 20.0f);  // pixels to twips
  slot[13] = roundf(y * 20.0f);
  ```
- Then sync to GPU: `renderer_write_transform(context, transform_id, slot)`
- The `context` (RenderContext*) is a static variable in `swf.c`. You'll need to
  either expose it via an accessor function, or store it in a global that
  `display_bridge.c` can access.
- Changes take effect on the next render frame (driven by `emscripten_sleep` in
  the ASYNCIFY frame loop)

**Accessing app_context from display_bridge.c:**
- `app_context` is a global in `main.c`. Declare as `extern SWFAppContext app_context;`
- `display_list`, `max_depth`, `dictionary` are externs from swf.h
- `renderer_write_transform` is declared in `renderer.h`

### 2. Update `build_test.sh`

- Detect `display_bridge.c` in the test directory OR in `wasm_wrappers/`
- Add `-DHAS_DISPLAY_BRIDGE` when present
- Add `_getDisplayListJSON` and `_setObjectTransform` to `-s EXPORTED_FUNCTIONS`

### 3. Update the HTML page (`docs/injector/display_editor.html`)

Add a textarea and buttons alongside the canvas:

```
┌─────────────────────────────────────┐
│  display_editor                     │
├──────────────┬──────────────────────┤
│              │ <textarea>           │
│   WebGPU     │   JSON content       │
│   Canvas     │   from               │
│              │   getDisplayListJSON  │
│              │ </textarea>          │
├──────────────┴──────────────────────┤
│  [Run SWF]  [Refresh]  [Apply]     │
└─────────────────────────────────────┘
```

JavaScript:
```javascript
function refreshData() {
    var json = Module.ccall('getDisplayListJSON', 'string', [], []);
    document.getElementById('json-editor').value = json;
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

### 4. Test

Build with build_test.sh:
```bash
source emsdk/emsdk_env.sh
cd SWFRecomp/tests
bash ../scripts/build_test.sh graphics/display_editor wasm --graphics
```

Deploy to docs/injector/:
```bash
cp SWFRecomp/tests/graphics/display_editor/build/wasm/display_editor.js docs/injector/display_editor/
cp SWFRecomp/tests/graphics/display_editor/build/wasm/display_editor.wasm docs/injector/display_editor/
```

Verify in browser:
1. Click "Run SWF" — three rectangles appear
2. Click "Refresh" — JSON appears in textarea showing 3 objects at their positions
3. Edit x/y values in the JSON
4. Click "Apply" — rectangles move to new positions on screen

## Important notes

- **Do NOT use verify_output.py for graphics WASM builds.** It produces broken
  WASM (traps on WebGPU init). Use `build_test.sh` instead. The root cause is
  unknown — same source files but different emcc invocation.
- **Do NOT run the full test suite.** Only run individual tests.
- The `display_bridge.c` file should be in `SWFRecomp/wasm_wrappers/` (shared
  infrastructure) but also needs to be copied to the test's build directory by
  `build_test.sh`.
- The `RenderContext*` from `swf.c` is static. You may need to add a small
  accessor: `RenderContext* getRendererContext(void)` in `swf.c` and declare it
  in a header.
- `#ifndef M_PI` / `#define M_PI 3.14159...` is needed for math constants.
