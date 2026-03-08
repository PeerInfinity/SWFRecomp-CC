# Test Harness Comparison: Ruffle vs SWFRecomp-CC

## 1. Ruffle Test Harness

### Architecture

Ruffle's test framework is a Rust library (`ruffle_test_framework`) that uses `libtest_mimic` for test discovery and execution. Key source files:

| File | Purpose |
|------|---------|
| `tests/framework/src/runner.rs` | Main test execution loop (`TestRunner`) |
| `tests/framework/src/runner/image_test.rs` | Image capture and pixel comparison |
| `tests/framework/src/runner/trace.rs` | Trace output comparison |
| `tests/framework/src/options.rs` | `test.toml` configuration parsing |
| `tests/framework/src/image_trigger.rs` | Image trigger enum (last_frame, frame N, fscommand) |
| `tests/tests/regression_tests.rs` | Test discovery entry point |

### Test Pipeline

1. Discover tests by scanning `tests/tests/swfs/` for `test.toml` files
2. Parse `test.toml` to get configuration (frames, image checks, approximations)
3. Create a Ruffle `Player` instance with optional renderer
4. Run N frames/ticks, collecting trace output and capturing images at trigger points
5. Compare trace output against `output.txt`
6. Compare captured images against `*.expected.png` reference files
7. Report pass/fail with detailed diff information

### Test Configuration (`test.toml`)

```toml
num_frames = 5              # Run 5 frames (run_frame + update_timers)
num_ticks = 10              # Alternative: run 10 ticks (tick(frame_time))
tick_rate = 16.666           # ms per tick (default: SWF frame rate)
output_path = "output.txt"  # Expected trace output
known_failure = false        # Expect trace mismatch

[player_options]
viewport_dimensions = { width = 550, height = 400, scale_factor = 1 }
max_execution_duration = { secs = 15, nanos = 0 }
with_renderer = { optional = false, quality = "medium" }

[approximations]
number_patterns = ["/regex/"]  # Float lines matched with epsilon tolerance
epsilon = 0.001

# Image comparisons (can have multiple)
[image_comparisons.output]
tolerance = 0                # Per-channel pixel tolerance (0-255)
max_outliers = 0             # Max pixels exceeding tolerance
trigger = "last_frame"       # When to capture

# Multiple checks per comparison (test passes if ANY check passes)
[[image_comparisons.output.checks]]
tolerance = 0
max_outliers = 5200

[[image_comparisons.output.checks]]
tolerance = 64
max_outliers = 1500
```

### Trace Output Testing

- Trace calls collected via a custom log backend into a `Vec<String>`
- After all frames complete, compared line-by-line against `output.txt`
- `[approximations]` section enables regex-based fuzzy matching for floating-point lines
- `known_failure = true` inverts the pass/fail expectation

### Image Comparison Testing

**Trigger types:**
- `"last_frame"` — capture after final frame/tick
- `N` (integer, 1-based) — capture at specific frame/tick number
- `"fs_command"` — capture when SWF calls `fscommand("captureImage", "name")`

**Reference images:** `{comparison_name}.expected.png` in the test directory (RGBA PNG)

**Comparison algorithm:**
1. Render the stage to an RGBA8 `ImageBuffer`
2. Verify dimensions match reference image exactly
3. For each pixel, compute per-channel absolute difference
4. Count outlier channels (any channel difference > tolerance)
5. If outlier count ≤ `max_outliers`, the check passes
6. Multiple `[[checks]]` entries: test passes if ANY check passes
7. On failure, generates difference images (`*.difference-color-*.png`, `*.difference-alpha-*.png`)

**Key detail:** Tests can have BOTH trace output comparison AND image comparison simultaneously. They are independent checks — both must pass for the test to pass.

### Frame Execution Modes

| Mode | API | Use Case |
|------|-----|----------|
| `num_frames` | `player.run_frame()` + `player.update_timers()` | Standard frame-by-frame |
| `num_ticks` | `player.tick(frame_time)` | Real-time simulation with timers |

### Input Events

Tests can specify input events via `input.json`:
- Mouse movements, clicks, releases
- Keyboard presses
- Events tied to specific frames with sub-frame timing

### FSCommand Support

- `fscommand("quit")` — ends test immediately
- `fscommand("captureImage", "name")` — triggers image capture matching `[image_comparisons.name]`

---

## 2. SWFRecomp-CC Test Harness

### Architecture

The test runner is a single Python script (`verify_output.py`, ~1300 lines) that orchestrates recompilation, compilation, execution, and output comparison. There is no image comparison infrastructure.

| File | Purpose |
|------|---------|
| `ruffle-tests/verify_output.py` | Main test runner (recompile → compile → run → diff) |
| `ruffle-tests/run_tests.py` | Quick recompiler-only check (no runtime execution) |
| `ruffle-tests/filter_results.py` | Removes ignored tests from results |
| `ruffle-tests/download_tests.sh` | Downloads Ruffle test SWFs via sparse git checkout |
| `scripts/diff_ruffle_results.py` | Compares two result JSON files |
| `scripts/generate_ruffle_results_markdown.py` | Generates markdown reports |

### Test Pipeline

1. Run SWFRecomp on `test.swf` → generates `RecompiledScripts/*.c` and `RecompiledTags/*.c`
2. Copy runtime source files into a temp directory
3. Compile everything with `gcc -DNO_GRAPHICS -O2`
4. Run the native binary, capture stdout (with timeout)
5. Filter boilerplate lines from output (runtime startup messages, frame markers, etc.)
6. Compare filtered output line-by-line against `output.txt`
7. Record results to `results.json`

### Test Configuration (`test.toml`)

```toml
num_frames = 1               # Frame count (required, default 1)
epsilon = 0.0001             # Numeric tolerance for float comparisons
mock_date_time = 1234567890  # Mock Date.getTime() return value
viewport_width = 550         # VIEWPORT_WIDTH define
viewport_height = 400        # VIEWPORT_HEIGHT define
scale_factor = 2.0           # Scales input.json coordinates

[approximations]
epsilon = 0.0001             # Alternate syntax
```

### Trace Output Testing

- Trace calls go through `actionTrace()` in `action.c` → `printf()` to stdout
- The test runner captures the process's stdout
- Boilerplate lines (frame markers, heap messages, startup banners) are filtered via regex
- Line-by-line comparison against `output.txt`
- Optional epsilon-based float comparison

### NO_GRAPHICS Mode

The entire test suite runs in NO_GRAPHICS mode:
- Uses `swf_core.c` (headless frame loop) instead of `swf.c` (windowed rendering loop)
- Uses `tag_stubs.c` (no-op rendering stubs) instead of real rendering calls
- No WebGPU/SDL3 dependency — pure C with libc only
- `SWFAppContext` omits graphics fields (`width`, `height`, render context, etc.)
- `tag.c` has ~50 `#ifdef NO_GRAPHICS` conditionals controlling rendering vs stub behavior

### Build Modes

| Mode | Compiler | Flags | Use |
|------|----------|-------|-----|
| NO_GRAPHICS native | gcc | `-DNO_GRAPHICS -O2` | Ruffle trace tests |
| Graphics native | gcc/cmake | `-DUSE_WEBGPU` + SDL3 + Dawn | Old graphics tests, demos |
| Graphics WASM | emcc | `-DUSE_WEBGPU --use-port=emdawnwebgpu` | Web deployment |

### Input Events

`input.json` support exists in `verify_output.py`:
- Mouse events: `MouseMove`, `MouseDown`, `MouseUp`
- Keyboard events: `KeyDown`, `KeyUp`
- Events injected at specific frames via `SET_MOUSE_*`/`SET_KEY_*` runtime functions
- Currently limited to tests already in `ignored_tests.txt` (interactive tests)

---

## 3. Feature Comparison

| Feature | Ruffle | SWFRecomp-CC | Gap |
|---------|--------|--------------|-----|
| **Trace output comparison** | Yes | Yes | Parity |
| **Float approximations** | Regex-based per-line | Epsilon-based global | Minor |
| **Image comparison** | Yes (RGBA pixel diff) | **No** | **Major gap** |
| **Multiple image triggers** | Yes (per-frame, fscommand) | No | Major gap |
| **Image tolerance/outliers** | Multi-level checks | No | Major gap |
| **Trace + image combined** | Yes (both in one test) | No | Major gap |
| **Trace in graphics mode** | N/A (always has trace) | **No** (NO_GRAPHICS only) | **Major gap** |
| **Frame count config** | `num_frames` / `num_ticks` | `num_frames` only | Minor |
| **Input event injection** | Full (mouse, keyboard, per-frame) | Partial (exists but limited) | Minor |
| **FSCommand quit** | Yes | Yes | Parity |
| **FSCommand captureImage** | Yes | No | Major gap |
| **Known failure marking** | Yes | No | Minor |
| **Viewport dimensions** | Yes | Yes | Parity |
| **Test parallelism** | Rust thread pool | Python subprocess, CI sharding | Different approach |
| **CI integration** | `cargo test` | GitHub Actions + `verify_output.py` | Both work |

---

## 4. Priority Investigation: Trace Output in Graphics Mode

### Current Problem

`actionTrace()` in `action.c` uses `printf()` — this works regardless of NO_GRAPHICS. The function itself has no `#ifdef NO_GRAPHICS` guard. **Trace output is always available at the runtime level.**

The real issue is the **frame loop and build pipeline**:

1. **`swf_core.c` (NO_GRAPHICS):** Runs frames in a simple `for` loop, then exits. `printf()` output goes to stdout and the test runner captures it. This is what `verify_output.py` uses.

2. **`swf.c` (graphics mode):** Runs frames in an event-driven loop (`renderer_poll`), renders to a WebGPU surface via SDL3 window, and blocks until the window is closed. stdout is still available, but the process never exits on its own (it waits for the user to close the window).

### Solution: Headless Graphics Mode

To get trace output AND rendering output simultaneously, we need a **headless graphics mode** — a build that:
- Initializes WebGPU with an offscreen surface (no SDL window)
- Runs N frames like `swf_core.c` does (deterministic, no event loop)
- Calls `actionTrace()` → stdout as usual (already works)
- After each frame's render pass, reads back the framebuffer to a CPU buffer
- Writes the framebuffer to a PNG file at configured trigger points
- Exits after N frames

### Feasibility: High

**What already works:**
- `actionTrace()` → `printf()` is completely independent of NO_GRAPHICS. No changes needed.
- The rendering pipeline (WebGPU) already renders to an MSAA texture resolved to a surface texture. The render output is fully computed.
- `tag.c` already has all the display list management, transform composition, and draw calls working in graphics mode.

**What needs to be built:**

1. **Offscreen WebGPU initialization:** Instead of creating an SDL window + surface, create a headless `WGPUDevice` and render to an offscreen `WGPUTexture` (render target). Dawn supports this natively — no window needed.

2. **Framebuffer readback:** After `render_webgpu_close_pass()`, use `wgpuCommandEncoderCopyTextureToBuffer()` to copy the resolved surface texture to a mappable buffer, then `wgpuBufferMapAsync()` to read the pixels.

3. **PNG writing:** Use a minimal PNG encoder (e.g., `stb_image_write.h`, single-header, public domain) to write RGBA pixel data to a PNG file.

4. **Headless frame loop:** A new `swf_headless.c` (or a mode in `swf_core.c`) that:
   - Initializes WebGPU headlessly (no SDL)
   - Runs the same frame loop as `swf_core.c`
   - Calls `renderer_open_pass()` / display list rendering / `renderer_close_pass()` each frame
   - Reads back and saves PNG at trigger frames
   - Prints trace output to stdout normally

5. **Test runner updates:** `verify_output.py` would need:
   - A new build mode (headless graphics) with appropriate compiler flags
   - Image comparison logic (pixel diff with tolerance)
   - Support for `[image_comparisons]` in `test.toml`

### Alternative: Software Rasterizer

Instead of headless WebGPU (which requires Dawn/wgpu-native as a native dependency), a software rasterizer could be used:
- Render to a CPU-side RGBA buffer directly
- No GPU dependency — works in CI without GPU access
- Much simpler to implement for basic shapes
- But: would need to reimplement the entire rendering pipeline (shapes, gradients, masks, blend modes, filters)

**Recommendation:** Headless WebGPU via Dawn is the better path. Dawn already supports headless mode, the rendering pipeline already works, and CI runners can use software Mesa for GPU emulation (or Dawn's null backend for basic functionality).

---

## 5. Priority Investigation: Image Comparison

### Feasibility: High

The Ruffle image comparison algorithm is straightforward to implement in Python:

```python
from PIL import Image
import numpy as np

def compare_images(actual_path, expected_path, tolerance=0, max_outliers=0):
    actual = np.array(Image.open(actual_path).convert('RGBA'))
    expected = np.array(Image.open(expected_path).convert('RGBA'))

    if actual.shape != expected.shape:
        return False, f"Size mismatch: {actual.shape} vs {expected.shape}"

    diff = np.abs(actual.astype(int) - expected.astype(int))
    outliers = np.sum(diff > tolerance)  # Per-channel count

    if outliers <= max_outliers:
        return True, f"{outliers} outliers (max {max_outliers})"
    else:
        return False, f"{outliers} outliers exceed max {max_outliers}"
```

The harder part is **generating** the actual image (see headless rendering above).

### Where Reference Images Come From

For Ruffle tests, the `*.expected.png` files are checked into the Ruffle repository alongside each test. Our `download_tests.sh` would need to be updated to also download these PNG files (currently it only downloads `test.swf`, `output.txt`, `test.toml`, and `input.json`).

---

## 6. Implementable Features (Ordered by Effort)

### Low Effort (days)

| Feature | Description | Effort |
|---------|-------------|--------|
| **Known failure marking** | Add `known_failure` support to `verify_output.py` | Trivial |
| **Regex approximations** | Match Ruffle's `number_patterns` regex approach | Small |
| **FSCommand captureImage** | Parse the command in `actionGetURL2`, set a flag | Small |
| **Download reference PNGs** | Update `download_tests.sh` to fetch `*.expected.png` | Small |
| **Image comparison in Python** | PIL/numpy pixel diff with tolerance (once images exist) | Small |

### Medium Effort (weeks)

| Feature | Description | Effort |
|---------|-------------|--------|
| **Trace in graphics builds** | Create a headless main loop (`swf_headless.c`) that runs N frames with rendering + stdout trace, but no SDL window | Medium |
| **Framebuffer readback** | Add `CopyTextureToBuffer` + `BufferMapAsync` to `render_webgpu.c` for reading pixels back to CPU | Medium |
| **PNG output** | Integrate `stb_image_write.h` for writing RGBA→PNG | Small (but depends on readback) |
| **Headless WebGPU init** | Initialize Dawn without SDL surface (offscreen render target) | Medium |
| **verify_output.py graphics mode** | New build+run path using headless graphics binary | Medium |

### High Effort (months) or Incompatible

| Feature | Description | Notes |
|---------|-------------|-------|
| **`num_ticks` mode** | Separate frame advance from timer processing | Requires refactoring frame loop |
| **Software rasterizer** | CPU-only rendering (no GPU dependency) | Entire rendering pipeline reimplemented |
| **Rust test framework** | Match Ruffle's `libtest_mimic` approach | Not useful — our runner is Python |
| **Multi-check tolerance** | Multiple tolerance/outlier thresholds per image | Easy once basic image comparison works |

### Incompatible Features

| Feature | Reason |
|---------|--------|
| **Ruffle's Player API** | We don't have a Player abstraction — we compile to native C |
| **Ruffle's renderer backends** | We use WebGPU exclusively; Ruffle has wgpu, softbuffer, etc. |
| **Ruffle's font system** | We handle fonts at the SWF tag level, not via a font database |
| **Ruffle's ActionScript VM** | We recompile to C; Ruffle interprets — fundamentally different |

---

## 7. Recommended Implementation Order

### Phase 1: Trace in Graphics Mode
1. Create `swf_headless.c` — a frame loop that initializes WebGPU headlessly, runs N frames with full rendering, and exits
2. Ensure `actionTrace()` output goes to stdout (already works, just needs the headless loop)
3. Add a `--graphics` mode to `verify_output.py` that builds with the headless graphics pipeline

### Phase 2: Framebuffer Capture
1. Add `render_webgpu_readback()` function — copies MSAA resolve target to a mappable buffer
2. Integrate `stb_image_write.h` for PNG output
3. Support FSCommand captureImage trigger + last-frame capture
4. Output PNG files to the test directory

### Phase 3: Image Comparison
1. Update `download_tests.sh` to fetch `*.expected.png` from Ruffle repo
2. Add PIL/numpy-based image comparison to `verify_output.py`
3. Support `[image_comparisons]` config in `test.toml`
4. Generate difference images on failure

### Phase 4: CI Integration
1. Ensure CI runners have GPU access (Mesa software renderer or Dawn null backend)
2. Add image test results to `results.json`
3. Update markdown report generation

---

## 8. Key Technical Challenges

### Headless WebGPU Without SDL

Dawn (the WebGPU implementation used in Emscripten and available natively) supports headless operation:
- Create `WGPUInstance` → `WGPUAdapter` → `WGPUDevice` without any surface
- Render to a standalone `WGPUTexture` (format RGBA8Unorm) instead of a surface texture
- The current code gets its render target from `wgpuSurfaceGetCurrentTexture()` — this would need to use a pre-created offscreen texture instead

The main change in `render_webgpu.c`:
- Skip `wgpuInstanceCreateSurface()` and `wgpuSurfaceConfigure()`
- Create a standalone `WGPUTexture` as the render target
- In `open_pass()`, use this texture instead of `wgpuSurfaceGetCurrentTexture()`
- In `close_pass()`, skip `wgpuSurfacePresent()`
- Add a readback path after close_pass

### Dawn as a Native Library

Currently, the native graphics build uses either Flashbang (SDL3 GPU) or WebGPU. For headless testing:
- Dawn can be built as a static library (`libdawn.a`)
- Alternative: use `wgpu-native` (Rust-based, provides `libwgpu_native.so`)
- Both support headless operation
- CI needs one of these available — this is a build system concern

### MSAA Resolve

The current pipeline renders to a 4x MSAA texture and resolves to the surface texture. For readback:
- The resolve target (non-MSAA) is what we want to read back
- In headless mode, the resolve target would be our offscreen texture
- Readback from this texture gives us the final anti-aliased image
