# Adding Graphics Tests

This document explains how to add new graphics tests to the SWFRecomp test suite.

## Overview

Graphics tests live in `SWFRecomp/tests/graphics/<test_name>/`. Each test directory contains:

- `create_test_swf.py` - Python script that generates `test.swf`
- `test_info.json` - Metadata including which SWF features the test exercises
- `test.swf` - Generated SWF file (gitignored, created by the script)

The SWF files are generated using **swfmill**, an open-source XML-to-SWF compiler. A shared Python helper module (`swfmill_helpers.py`) provides a high-level API over the swfmill XML format.

## Prerequisites

Install swfmill:

```bash
apt install swfmill
```

Verify it works:

```bash
swfmill --version
```

## Step-by-Step: Creating a New Test

### 1. Create the Test Directory

```bash
mkdir SWFRecomp/tests/graphics/my_test_name
```

### 2. Create `create_test_swf.py`

Every test script follows this pattern:

```python
#!/usr/bin/env python3
"""Generate test.swf for my_test_name graphics test.

Brief description of what this test exercises.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
)

# Create the SWF
swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

# Define a shape
shape = swf.define_shape(object_id=1, bounds=(left, right, top, bottom))
shape.add_fill(SolidFill(255, 0, 0))         # fill index 1
shape.add_line_style(LineStyle(20, 0, 0, 0))  # line index 1

# Add edges
shape.add_edges([
    ShapeSetup(x=..., y=..., fillStyle1=1, lineStyle=1),
    LineTo(dx, dy),
    LineTo(dx, dy),
    ...
])

# Place and render
swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
```

### 3. Create `test_info.json`

```json
{
  "metadata": {
    "name": "my_test_name",
    "description": "WebGPU rendering test with ...",
    "swf_version": 4,
    "fully_implemented": true
  },
  "opcodes": {
    "tested": [],
    "supporting": []
  },
  "execution": {
    "type": "deterministic"
  },
  "graphics": {
    "tested": [
      "DEFINE_SHAPE",
      "SOLID_FILL",
      "LINE_STYLE",
      "STRAIGHT_EDGE"
    ]
  }
}
```

The `graphics.tested` array lists the SWF features this test exercises. See the "Feature IDs" section below for the full list.

### 4. Generate and Verify

```bash
cd SWFRecomp/tests/graphics/my_test_name
python3 create_test_swf.py
```

To verify the generated SWF is correct, use the swfmill round-trip test:

```bash
# Convert your generated SWF to XML
swfmill swf2xml test.swf generated.xml

# Inspect the XML to verify the structure
less generated.xml
```

If you have a reference SWF to compare against:

```bash
swfmill swf2xml reference.swf reference.xml
diff reference.xml generated.xml
```

Note: Binary comparison of SWF files may show small differences (swfmill's bit-packing can differ by 1 byte), but the XML round-trip output should be identical.

### 5. Update the Coverage Chart

After adding your test, regenerate the coverage data:

```bash
python3 scripts/build_opcode_index.py
python3 scripts/generate_opcode_markdown.py
```

This will pick up the new test's `test_info.json` and update `opcode-index.json`, `opcode-index.md`, and `opcode-index-plain.md`.

## swfmill_helpers.py API Reference

The helper module is at `SWFRecomp/tests/graphics/swfmill_helpers.py`.

### SWFMLBuilder

Main class that builds a complete SWF file.

```python
swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
```

- `width`, `height`: Stage size in pixels (converted to twips internally; 1 pixel = 20 twips)
- `fps`: Frame rate
- `version`: SWF version number

**Methods:**

| Method | Description |
|--------|-------------|
| `set_background(r, g, b)` | Set background color (RGB 0-255) |
| `define_shape(object_id, bounds, shape_version=1)` | Create a shape definition. Returns a `ShapeDefinition` |
| `place_object(object_id, depth, trans_x=0, trans_y=0, scale_x=None, scale_y=None, skew_x=None, skew_y=None)` | Place object on display list with optional transform |
| `show_frame()` | Render current frame |
| `add_trace(text)` | Add DoAction with trace (for ActionScript tests) |
| `define_bits_jpeg(object_id, jpeg_data_base64)` | Add DefineBits JPEG image tag |
| `add_jpeg_tables(tables_base64)` | Add JPEGTables tag |
| `save(output_path)` | Generate the SWF file via swfmill |

The `bounds` parameter is a tuple of `(left, right, top, bottom)` in twips.

The `shape_version` parameter controls which tag is emitted: `1` for DefineShape, `2` for DefineShape2.

### Fill Styles

```python
# Solid color fill
SolidFill(r, g, b)

# Linear gradient fill
LinearGradientFill(matrix, stops)
# matrix: {"scaleX": ..., "scaleY": ..., "skewX": ..., "skewY": ..., "transX": ..., "transY": ...}
# stops: [(position, r, g, b), ...]  where position is 0-255

# Radial gradient fill
RadialGradientFill(matrix, stops)
# Same parameters as LinearGradientFill

# Clipped bitmap fill
ClippedBitmapFill(object_id, matrix)
# object_id: references a DefineBits tag
# matrix: same format as gradient matrices
```

For gradient matrices, if the scale is zero, you must still include `"scaleX": 0.0, "scaleY": 0.0` explicitly; omitting them defaults to 1.0 (identity) in the SWF spec.

### Line Styles

```python
LineStyle(width, r, g, b)
# width: stroke width in twips (20 twips = 1 pixel)
```

### Edge Records

```python
# Move to / style change
ShapeSetup(x=None, y=None, fillStyle0=None, fillStyle1=None,
           lineStyle=None, new_styles=None)

# Straight line (delta coordinates in twips)
LineTo(dx, dy)

# Quadratic bezier curve (control point delta, anchor point delta)
CurveTo(cx, cy, ax, ay)
```

**ShapeSetup details:**

- `x, y`: Absolute move-to position (in twips, relative to shape origin)
- `fillStyle0, fillStyle1`: 1-based fill style indices (0 = no fill)
- `lineStyle`: 1-based line style index (0 = no line)
- `new_styles`: Tuple of `([fills], [lines])` for mid-shape style changes. Requires `shape_version=2` (DefineShape2). After a new_styles record, fill/line indices reset to 1-based within the new style list.

### ShapeDefinition

Returned by `swf.define_shape()`.

```python
shape = swf.define_shape(object_id=1, bounds=(0, 11000, 0, 8000))
shape.add_fill(fill)         # Returns 1-based fill index
shape.add_line_style(style)  # Returns 1-based line index
shape.add_edge(edge)         # Add single edge record
shape.add_edges([...])       # Add multiple edge records
```

## Coordinate System

All coordinates in the SWF format use **twips** (1 pixel = 20 twips).

- Stage dimensions: `width=550, height=400` pixels = `11000 x 8000` twips
- Shape bounds: `(left, right, top, bottom)` in twips
- Edge coordinates: Delta values (relative to current pen position) in twips
- ShapeSetup coordinates: Absolute positions within the shape's coordinate space

## Examples by Feature

### Simple Solid Shape

See `two_squares/create_test_swf.py`: Two filled squares with solid colors and a line style.

### Curved Edges

See `coicle/create_test_swf.py`: Circle approximated with 8 quadratic Bezier curves using `CurveTo`.

### Gradient Fills

See `awful_gradient/create_test_swf.py`: Multiple linear gradient fills with transform matrices.

See `awful_radial_gradient/create_test_swf.py`: Combines linear and radial gradient fills.

### Bitmap Fills

See `mess/create_test_swf.py`: JPEG bitmap fill using `ClippedBitmapFill`, `define_bits_jpeg()`, and `add_jpeg_tables()`.

### Mid-Shape Style Changes (NewStyles)

See `new_styles/create_test_swf.py`: DefineShape2 with `new_styles` parameter to define different styles for different parts of the same shape.

### PlaceObject2 Transforms

See `wild_shadow/create_test_swf.py`: Uses `scale_x`, `scale_y`, `skew_x`, `skew_y` in `place_object()`.

## Feature IDs for test_info.json

When filling in `graphics.tested` in `test_info.json`, use these feature IDs. Only list features that the test *distinctively* exercises (e.g., don't list `PLACE_OBJECT2` for every test since all tests place objects).

### Shape Tags
| ID | Description |
|----|-------------|
| `DEFINE_SHAPE` | DefineShape (tag 2) |
| `DEFINE_SHAPE2` | DefineShape2 with >255 styles (tag 22) |
| `DEFINE_SHAPE3` | DefineShape3 with RGBA (tag 32) |
| `DEFINE_SHAPE4` | DefineShape4 with LINESTYLE2 (tag 83) |

### Fill Types
| ID | Description |
|----|-------------|
| `SOLID_FILL` | Solid color fill |
| `LINEAR_GRADIENT` | Linear gradient fill |
| `RADIAL_GRADIENT` | Radial gradient fill |
| `FOCAL_RADIAL_GRADIENT` | Focal radial gradient (SWF 8+) |
| `REPEATING_BITMAP` | Tiled bitmap fill |
| `CLIPPED_BITMAP` | Clipped bitmap fill |
| `NON_SMOOTHED_REPEATING_BITMAP` | Tiled bitmap without anti-aliasing |
| `NON_SMOOTHED_CLIPPED_BITMAP` | Clipped bitmap without anti-aliasing |

### Edge Types
| ID | Description |
|----|-------------|
| `STRAIGHT_EDGE` | Straight edges (LineTo) |
| `CURVED_EDGE` | Quadratic Bezier curves (CurveTo) |

### Style Features
| ID | Description |
|----|-------------|
| `LINE_STYLE` | Basic line style (LINESTYLE) |
| `LINE_STYLE2` | Advanced line style with caps/joins (LINESTYLE2) |
| `NEW_STYLES` | Mid-shape style changes (StateNewStyles) |

### Image/Bitmap Tags
| ID | Description |
|----|-------------|
| `DEFINE_BITS` | JPEG bitmap requiring JPEGTables (tag 6) |
| `JPEG_TABLES` | Shared JPEG encoding tables (tag 8) |
| `DEFINE_BITS_JPEG2` | Self-contained JPEG (tag 21) |
| `DEFINE_BITS_JPEG3` | JPEG with alpha channel (tag 35) |
| `DEFINE_BITS_JPEG4` | JPEG with embedded alpha (tag 90) |
| `DEFINE_BITS_LOSSLESS` | Lossless RGB bitmap (tag 20) |
| `DEFINE_BITS_LOSSLESS2` | Lossless RGBA bitmap (tag 36) |

### Display List Tags
| ID | Description |
|----|-------------|
| `PLACE_OBJECT` | PlaceObject (tag 4) |
| `PLACE_OBJECT2` | PlaceObject2 (tag 26) |
| `PLACE_OBJECT3` | PlaceObject3 with filters/blend (tag 70) |
| `REMOVE_OBJECT` | RemoveObject by ID (tag 5) |
| `REMOVE_OBJECT2` | RemoveObject2 by depth (tag 28) |

### Transform Features
| ID | Description |
|----|-------------|
| `PLACE_SCALE` | Scale transform in PlaceObject2 |
| `PLACE_SKEW` | Skew transform in PlaceObject2 |
| `COLOR_TRANSFORM` | Color transform (CXFORM) |
| `CLIP_DEPTH` | Clipping mask via ClipDepth |

### Morph Shape Tags
| ID | Description |
|----|-------------|
| `DEFINE_MORPH_SHAPE` | Shape morphing (tag 46) |
| `DEFINE_MORPH_SHAPE2` | Enhanced morphing (tag 84) |

### Text Tags
| ID | Description |
|----|-------------|
| `DEFINE_FONT` | Basic font (tag 10) |
| `DEFINE_FONT2` | Font with metrics (tag 48) |
| `DEFINE_FONT3` | Enhanced font (tag 75) |
| `DEFINE_FONT4` | CFF font (tag 91) |
| `DEFINE_TEXT` | Static text (tag 11) |
| `DEFINE_TEXT2` | Static text with RGBA (tag 33) |
| `DEFINE_EDIT_TEXT` | Dynamic/editable text (tag 37) |

### Sprite Tags
| ID | Description |
|----|-------------|
| `DEFINE_SPRITE` | Movie clip with own timeline (tag 39) |

### Button Tags
| ID | Description |
|----|-------------|
| `DEFINE_BUTTON` | Basic button (tag 7) |
| `DEFINE_BUTTON2` | Enhanced button (tag 34) |

### Sound Tags
| ID | Description |
|----|-------------|
| `DEFINE_SOUND` | Event sound (tag 14) |
| `START_SOUND` | Play/stop sound (tag 15) |
| `SOUND_STREAM_HEAD` | Streaming sound header (tag 18) |
| `SOUND_STREAM_HEAD2` | Enhanced streaming header (tag 45) |
| `SOUND_STREAM_BLOCK` | Streaming audio data (tag 19) |

### Video Tags
| ID | Description |
|----|-------------|
| `DEFINE_VIDEO_STREAM` | Video stream (tag 60) |
| `VIDEO_FRAME` | Video frame data (tag 61) |

### Filter Types
| ID | Description |
|----|-------------|
| `DROP_SHADOW_FILTER` | Drop shadow effect |
| `BLUR_FILTER` | Gaussian blur |
| `GLOW_FILTER` | Glow/halo effect |
| `BEVEL_FILTER` | Beveled edge effect |
| `GRADIENT_GLOW_FILTER` | Gradient glow |
| `CONVOLUTION_FILTER` | Convolution matrix |
| `COLOR_MATRIX_FILTER` | Color matrix transform |
| `GRADIENT_BEVEL_FILTER` | Gradient bevel |

## Using swfmill Directly

The `swfmill_helpers.py` module handles swfmill invocation automatically, but you can also use swfmill directly for debugging.

### Convert SWF to XML (for inspection)

```bash
swfmill swf2xml test.swf test.xml
```

### Convert XML to SWF

```bash
swfmill xml2swf test.xml test.swf
```

### Reverse-Engineer an Existing SWF

If you have an existing SWF and want to recreate it as a Python script:

1. Convert to XML: `swfmill swf2xml original.swf original.xml`
2. Study the XML structure to identify tags, fills, edges, and transforms
3. Write the equivalent Python script using `swfmill_helpers.py`
4. Generate and verify: compare `swfmill swf2xml generated.swf` output against the original XML

## Adding New Features to swfmill_helpers.py

If you need to test a SWF feature not yet supported by `swfmill_helpers.py`, you'll need to extend the module. The general approach:

1. Study the swfmill XML format for the feature: convert a reference SWF with `swfmill swf2xml` and examine the XML
2. Add a new class or method to `swfmill_helpers.py` that generates the corresponding XML elements
3. Add the feature ID to `GRAPHICS_FEATURES` in `scripts/build_opcode_index.py` if it's a new feature not already in the list

Features that currently need to be added to `swfmill_helpers.py`:

- DefineShape3/DefineShape4 support (RGBA colors, LINESTYLE2)
- Lossless bitmap tags (DefineBitsLossless, DefineBitsLossless2)
- Additional bitmap fill types (RepeatingBitmap, non-smoothed variants)
- FocalRadialGradient fills
- PlaceObject3 (filters, blend modes)
- Color transforms (CXFORM)
- Clipping masks (ClipDepth)
- Morph shapes, text, sprites, buttons (more complex features)

## Building and Deploying a Single Test

After creating a new graphics test (or merging one from a branch), follow these steps to build it as WASM and deploy it to the docs site.

### Prerequisites

Make sure the build environment is set up:

```bash
# One-time setup (installs emsdk, swfmill, builds SWFRecomp)
source scripts/setup_build_env.sh

# Or if emsdk is already installed, just activate it:
source emsdk/emsdk_env.sh
```

### Step 1: Generate the SWF

```bash
cd SWFRecomp/tests/graphics/my_test_name
python3 create_test_swf.py
cd -
```

### Step 2: Rebuild SWFRecomp (if recompiler/runtime code changed)

If the merge included changes to `SWFRecomp/src/` or `SWFModernRuntime/`, rebuild:

```bash
cd SWFRecomp/build
cmake .. && make -j$(nproc)
cd -
```

### Step 3: Build WASM

```bash
SWFRecomp/scripts/build_test.sh graphics/my_test_name wasm --graphics
```

This runs SWFRecomp on the test SWF, generates C code, and compiles it to WASM with the graphics runtime (WebGPU).

### Step 4: Deploy to docs

```bash
SWFRecomp/scripts/deploy_example.sh graphics/my_test_name --graphics
```

This copies the WASM build to `docs/examples/graphics/my_test_name/` and regenerates the examples index page.

### All-in-one

For a quick copy-paste workflow (replace `my_test_name`):

```bash
# Generate SWF, rebuild recompiler, build WASM, deploy
cd SWFRecomp/tests/graphics/my_test_name && python3 create_test_swf.py && cd -
cd SWFRecomp/build && cmake .. && make -j$(nproc) && cd -
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh graphics/my_test_name wasm --graphics
SWFRecomp/scripts/deploy_example.sh graphics/my_test_name --graphics
```

### Rebuilding all examples

To rebuild every test (trace and graphics) and regenerate the full docs site:

```bash
SWFRecomp/scripts/build_all_examples.sh
```

This is also what the CI workflow does. It handles SWF generation, recompilation, WASM builds, deployment, and index regeneration for all tests.

## Build System Integration

The build system (`SWFRecomp/scripts/build_test.sh`) automatically runs `create_test_swf.py` when `test.swf` is missing. You don't need to commit generated SWF files -- they are gitignored.

The full documentation pipeline:

```bash
# Run everything: tests, build opcode index, generate markdown
python3 scripts/test-and-document.py --build
```

Or run individual steps:

```bash
# Just rebuild the coverage chart
python3 scripts/build_opcode_index.py
python3 scripts/generate_opcode_markdown.py
```
