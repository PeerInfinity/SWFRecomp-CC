# Offscreen Graphics Mode Setup

This document explains how to set up and run the offscreen graphics pipeline
(`--mode=graphics`), which renders SWFs offscreen and compares the output
against expected PNG images from the Ruffle test suite.

> **2026-07-23:** the old `graphics-headless-legacy` mode (`swf_headless.c` +
> `HEADLESS_GRAPHICS`) was deleted. `--headless` now errors with a pointer to
> `--mode=graphics`; the Dawn / lavapipe / Pillow setup below is unchanged.

## Overview

The offscreen pipeline works like this:

1. **SWFRecomp** recompiles `test.swf` into C code
2. The C code is compiled with the runtime, Dawn WebGPU library, and
   the graphics-mode sources (`swf.c`, `render_webgpu.c`, `capture.c`)
3. The binary runs with software Vulkan (lavapipe), rendering frames offscreen
4. At specific ticks, rendered frames are captured as PNGs
5. The PNGs are compared pixel-by-pixel against Ruffle's expected images

## Prerequisites

You need everything from `ENVIRONMENT_SETUP.md` (gcc, cmake, python3, the
recompiler build), plus:

### 1. Dawn (WebGPU library)

Dawn provides the WebGPU implementation used for offscreen rendering. The static
library must be installed at `~/CC/dawn-install/`.

**Build from source:**

```bash
# Clone Dawn (outside the project repo)
cd ~/CC
git clone https://dawn.googlesource.com/dawn
cd dawn

# Bootstrap dependencies (fetches third-party libs)
python3 tools/fetch_dawn_dependencies.py

# Build with CMake
mkdir -p out/Release && cd out/Release
cmake ../.. \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=$HOME/CC/dawn-install \
  -DDAWN_BUILD_SAMPLES=OFF \
  -DDAWN_BUILD_TESTS=OFF \
  -DDAWN_ENABLE_VULKAN=ON
make -j$(nproc)
make install
cd ~/CC
```

After installation you should have:

```
~/CC/dawn-install/
  include/
    dawn/
    webgpu/
  lib/
    libwebgpu_dawn.a    # ~300 MB static library
    cmake/
```

### 2. Lavapipe (software Vulkan driver)

Lavapipe is a CPU-based Vulkan driver from Mesa. It lets the renderer work
without a physical GPU, which is essential in WSL2 and CI.

```bash
sudo apt-get install -y mesa-vulkan-drivers libvulkan1
```

Verify the ICD file exists:

```bash
ls /usr/share/vulkan/icd.d/lvp_icd.json
```

`verify_output.py` sets `VK_ICD_FILENAMES` and `VK_DRIVER_FILES` to this path
automatically, forcing lavapipe even when hardware drivers are present.

### 3. Pillow (Python image library)

Required for PNG comparison:

```bash
pip3 install Pillow
```

Verify:

```bash
python3 -c "from PIL import Image; print('OK')"
```

### 4. Ruffle upstream test data

Expected PNGs live in the Ruffle source repo:

```bash
# If not already cloned
cd ~/CC
git clone https://github.com/nickelc/ruffle ~/CC/ruffle   # or the official repo
```

`verify_output.py` looks for expected images at
`~/CC/ruffle/tests/tests/swfs/avm1/{test}/output.*.expected.png`.

## Running Image Tests

### Single test

```bash
python3 ruffle-tests/verify_output.py --test=TEST_NAME --mode=graphics --diff --verbose
```

Example output:

```
[1/1] focusrect_swf6...
    [image:output.01a] PASS - Image check passed: 0 outliers (limit 0), max difference 0
    [image:output.01b] PASS - Image check passed: 0 outliers (limit 0), max difference 0
    ...
PASS
```

### Multiple tests

```bash
python3 ruffle-tests/verify_output.py --test=color --test=focusrect_swf6 --mode=graphics --diff --verbose
```

### All image tests (dedicated runner)

```bash
python3 ruffle-tests/run_image_tests.py              # all 32 image tests
python3 ruffle-tests/run_image_tests.py --test=color  # single test
```

`run_image_tests.py` auto-discovers tests with `[image_comparisons]` in their
`test.toml`, runs each via `verify_output.py --mode=graphics`, collects results, and
generates reports. Output PNGs are saved to
`ruffle-tests/tests/swfs/avm1/_image-test-output/{test}/`.

## How It Works

### Compilation

When `--mode=graphics` is passed, `verify_output.py` compiles with these
differences from trace-only mode:

| Aspect | Trace-only (`no-graphics`) | `graphics` |
|--------|-----------|----------|
| Defines | `-DNO_GRAPHICS` | `-DUSE_WEBGPU -DOFFSCREEN_RENDER -DNDEBUG` |
| Frame loop | `swf_core.c` | `swf.c` (the same loop browsers run) |
| Renderer | none | `render_webgpu.c` |
| Extra includes | none | `rendering/`, `stb/`, Dawn headers |
| Extra libs | none | `libwebgpu_dawn.a`, `-lstdc++`, `-lpthread`, `-ldl` |

If the test has `[image_comparisons]` in its `test.toml`, the define
`-DHEADLESS_RENDER_ENABLED` is also added. Without it, the binary runs the
graphics frame loop but skips all rendering (useful for trace-only tests that
need the offscreen event pump but not GPU rendering).

### Frame loop (`swf.c`)

The offscreen frame loop runs for `MAX_FRAMES` ticks. Each tick:

1. Request capture if this tick matches a `CAPTURE_TRIGGERS` entry
2. Run frame scripts (same as trace-only mode)
3. Deliver input events from `input_events.txt`
4. Process goto catch-up and deferred scripts
5. Process timers
6. **Re-render** via `tagRerenderFrame()` if a capture is pending for this tick
7. Save captured PNG if ready

The re-render after events (step 6) ensures captures reflect post-event state
changes (e.g., focus rect appearing after a Tab keypress).

### Capture triggers

Tests specify when to capture frames in `test.toml`:

```toml
num_ticks = 12

# Capture at specific tick numbers (1-based)
image_comparisons."output.01a".trigger = 1
image_comparisons."output.01b".trigger = 2

# Or capture the last frame
image_comparisons."output".trigger = "last_frame"

# Or capture on fscommand("capture")
image_comparisons."output".trigger = "fs_command"
```

`verify_output.py` converts these to the `CAPTURE_TRIGGERS` environment
variable (e.g., `output.01a:iteration:1,output.01b:iteration:2`). The runtime
reads this at startup and saves PNGs to `CAPTURE_OUTPUT_DIR`.

### Image comparison

After the binary exits, `verify_output.py` compares each captured PNG against
the expected PNG:

1. Load both images, convert to RGBA
2. Check dimensions match exactly
3. Compute per-pixel, per-channel absolute difference
4. Count "outlier" channels exceeding the tolerance threshold
5. Test passes if outliers <= max_outliers

Tests can specify tolerance in `test.toml`:

```toml
[image_comparisons."output"]
trigger = "last_frame"
tolerance = 5          # per-channel difference threshold (0-255)
max_outliers = 100     # max channels allowed to exceed tolerance
```

Multiple check configs can be provided; the test passes if ANY check passes.

### Expected images

`verify_output.py` searches in order:

1. Test directory: `ruffle-tests/tests/swfs/avm1/{test}/output.*.expected.png`
2. Ruffle upstream: `~/CC/ruffle/tests/tests/swfs/avm1/{test}/output.*.expected.png`

When `--verbose` is passed, actual and difference PNGs are saved to the test
directory as `output.*.actual.png` and `output.*.difference.png`.

## Troubleshooting

| Symptom | Cause | Fix |
|---------|-------|-----|
| `Dawn install not found` | Missing `~/CC/dawn-install/` | Build and install Dawn (see above) |
| `lvp_icd.json not found` | No lavapipe driver | `apt install mesa-vulkan-drivers` |
| `No module named 'PIL'` | Pillow not installed | `pip3 install Pillow` |
| `Image comparisons skipped` | PIL missing or test has no `[image_comparisons]` | Install Pillow; check `test.toml` |
| `maxDynamicUniformBuffers warning` | Normal Dawn/lavapipe warning | Harmless, ignore |
| Non-deterministic image diffs | Software Vulkan timing | Re-run; results may vary slightly |
| `expected.png not found` | Missing Ruffle upstream repo | Clone Ruffle to `~/CC/ruffle` |

## Architecture Notes

- `swf.c` replaces `swf_core.c` in graphics mode. It is the same frame loop
  the browser-WASM build runs; under `OFFSCREEN_RENDER` it adds renderer
  initialization, capture scheduling (`capture.c`), and re-render hooks.
- `render_webgpu.c` is the WebGPU backend. It handles shape rendering, sprite
  composition, color transforms, clip masking, text fields, drawing API shapes,
  BitmapData quads, and focus rect rendering.
- `tag.c` has rendering code under `#ifdef NO_GRAPHICS` (CPU-side rendering)
  and `tagRerenderFrame()` under `#ifdef OFFSCREEN_RENDER`.
- The `swf.c` stub for `actionGetFocusRectInfo()` (always returns 0) is only
  compiled in browser-WASM graphics (`!NO_GRAPHICS && !OFFSCREEN_RENDER`). In
  `--mode=graphics`, the real implementation in `action.c` is used.
