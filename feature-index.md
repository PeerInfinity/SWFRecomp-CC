# SWF Graphics Feature Index

**Generated**: 2026-02-24

See also: [AS2 Opcode Index](opcode-index.md)

## Feature Statistics

**Total SWF Features**: 62

**Features With Tests**: 61/62

**Features Without Tests**: 1

**Total Feature Tests**: 219

**Fully Implemented**: 61/62

## Summary Tables

### Shape Tags
(4/4 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [DefineShape](#define-shape) | Basic shape definition (SWF tag 2) | 2 | 25 | Yes |
| [DefineShape2](#define-shape2) | Extended shape with >255 styles (SWF tag 22) | 22 | 2 | Yes |
| [DefineShape3](#define-shape3) | Shape with full RGBA support (SWF tag 32) | 32 | 2 | Yes |
| [DefineShape4](#define-shape4) | Shape with LINESTYLE2 and edge bounds (SWF tag 83) | 83 | 1 | Yes |

### Fill Types
(8/8 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [SolidFill](#solid-fill) | Solid color fill (type 0x00) | - | 40 | Yes |
| [LinearGradient](#linear-gradient) | Linear gradient fill (type 0x10) | - | 3 | Yes |
| [RadialGradient](#radial-gradient) | Radial gradient fill (type 0x12) | - | 1 | Yes |
| [FocalRadialGradient](#focal-radial-gradient) | Focal radial gradient fill (type 0x13, SWF 8+) | - | 1 | Yes |
| [RepeatingBitmap](#repeating-bitmap) | Tiled bitmap fill (type 0x40) | - | 1 | Yes |
| [ClippedBitmap](#clipped-bitmap) | Clipped bitmap fill (type 0x41) | - | 6 | Yes |
| [NonSmoothedRepeatingBitmap](#non-smoothed-repeating-bitmap) | Tiled bitmap without anti-aliasing (type 0x42) | - | 1 | Yes |
| [NonSmoothedClippedBitmap](#non-smoothed-clipped-bitmap) | Clipped bitmap without anti-aliasing (type 0x43) | - | 1 | Yes |

### Edge Types
(2/2 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [StraightEdge](#straight-edge) | Straight edge records (LineTo) | - | 55 | Yes |
| [CurvedEdge](#curved-edge) | Curved edge records (CurveTo) | - | 3 | Yes |

### Gradient Features
(1/1 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [GradientSpread](#gradient-spread) | Gradient spread modes (pad, reflect, repeat) | - | 1 | Yes |

### Style Features
(3/3 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [LineStyle](#line-style) | Basic stroke line style (LINESTYLE) | - | 12 | Yes |
| [LineStyle2](#line-style2) | Advanced line style with caps/joins (LINESTYLE2, DefineShape4) | - | 1 | Yes |
| [NewStyles](#new-styles) | Mid-shape style changes (StateNewStyles) | - | 2 | Yes |

### Image/Bitmap Tags
(7/7 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [DefineBits](#define-bits) | JPEG bitmap requiring JPEGTables (SWF tag 6) | 6 | 1 | Yes |
| [JPEGTables](#jpeg-tables) | Shared JPEG encoding tables (SWF tag 8) | 8 | 1 | Yes |
| [DefineBitsJPEG2](#define-bits-jpeg2) | Self-contained JPEG image (SWF tag 21) | 21 | 1 | Yes |
| [DefineBitsJPEG3](#define-bits-jpeg3) | JPEG image with alpha channel (SWF tag 35) | 35 | 1 | Yes |
| [DefineBitsJPEG4](#define-bits-jpeg4) | JPEG with embedded alpha (SWF tag 90, SWF 10+) | 90 | 1 | Yes |
| [DefineBitsLossless](#define-bits-lossless) | Lossless RGB bitmap (SWF tag 20) | 20 | 4 | Yes |
| [DefineBitsLossless2](#define-bits-lossless2) | Lossless RGBA bitmap (SWF tag 36) | 36 | 1 | Yes |

### Display List Tags
(5/5 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [PlaceObject](#place-object) | Basic object placement (SWF tag 4) | 4 | 1 | Yes |
| [PlaceObject2](#place-object2) | Enhanced object placement (SWF tag 26) | 26 | 1 | Yes |
| [PlaceObject3](#place-object3) | Object placement with filters/blend (SWF tag 70) | 70 | 5 | Yes |
| [RemoveObject](#remove-object) | Remove object by ID (SWF tag 5) | 5 | 1 | Yes |
| [RemoveObject2](#remove-object2) | Remove object by depth (SWF tag 28) | 28 | 1 | Yes |

### Transform Features
(5/5 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [PlaceObject2 Scale](#place-scale) | Scale transform in PlaceObject2 | - | 1 | Yes |
| [PlaceObject2 Skew](#place-skew) | Skew transform in PlaceObject2 | - | 1 | Yes |
| [ColorTransform](#color-transform) | Color transform (CXFORM/CXFORMWITHALPHA) | - | 2 | Yes |
| [ClipDepth](#clip-depth) | Clipping mask via PlaceObject2 ClipDepth | - | 1 | Yes |
| [ClipActions](#clip-actions) | CLIPACTIONS event handlers on PlaceObject2 | - | 1 | Yes |

### Morph Shape Tags
(2/2 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [DefineMorphShape](#define-morph-shape) | Shape morphing/tweening (SWF tag 46) | 46 | 1 | Yes |
| [DefineMorphShape2](#define-morph-shape2) | Enhanced morphing with LINESTYLE2 (SWF tag 84) | 84 | 1 | Yes |

### Text Tags
(6/7 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [DefineFont](#define-font) | Basic font with glyph shapes (SWF tag 10) | 10 | 2 | Yes |
| [DefineFont2](#define-font2) | Font with layout metrics (SWF tag 48) | 48 | 2 | Yes |
| [DefineFont3](#define-font3) | Enhanced font definition (SWF tag 75) | 75 | 1 | Yes |
| [DefineFont4](#define-font4) | CFF font for Flash Text Engine (SWF tag 91) | 91 | **0** | No |
| [DefineText](#define-text) | Static text with glyph indices (SWF tag 11) | 11 | 4 | Yes |
| [DefineText2](#define-text2) | Static text with RGBA colors (SWF tag 33) | 33 | 1 | Yes |
| [DefineEditText](#define-edit-text) | Dynamic/editable text field (SWF tag 37) | 37 | 1 | Yes |

### Sprite Tags
(1/1 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [DefineSprite](#define-sprite) | Embedded movie clip with own timeline (SWF tag 39) | 39 | 5 | Yes |

### Button Tags
(2/2 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [DefineButton](#define-button) | Basic button with state shapes (SWF tag 7) | 7 | 1 | Yes |
| [DefineButton2](#define-button2) | Enhanced button with actions (SWF tag 34) | 34 | 1 | Yes |

### Sound Tags
(5/5 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [DefineSound](#define-sound) | Event sound definition (SWF tag 14) | 14 | 1 | Yes |
| [StartSound](#start-sound) | Play/stop event sound (SWF tag 15) | 15 | 1 | Yes |
| [SoundStreamHead](#sound-stream-head) | Streaming sound header (SWF tag 18) | 18 | 1 | Yes |
| [SoundStreamHead2](#sound-stream-head2) | Enhanced streaming sound header (SWF tag 45) | 45 | 1 | Yes |
| [SoundStreamBlock](#sound-stream-block) | Streaming audio frame data (SWF tag 19) | 19 | 2 | Yes |

### Video Tags
(2/2 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [DefineVideoStream](#define-video-stream) | Video stream definition (SWF tag 60) | 60 | 1 | Yes |
| [VideoFrame](#video-frame) | Video frame data (SWF tag 61) | 61 | 1 | Yes |

### Filter Types
(8/8 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| [DropShadowFilter](#drop-shadow-filter) | Drop shadow effect (filter ID 0) | - | 1 | Yes |
| [BlurFilter](#blur-filter) | Gaussian blur effect (filter ID 1) | - | 1 | Yes |
| [GlowFilter](#glow-filter) | Glow/halo effect (filter ID 2) | - | 1 | Yes |
| [BevelFilter](#bevel-filter) | Beveled edge effect (filter ID 3) | - | 1 | Yes |
| [GradientGlowFilter](#gradient-glow-filter) | Gradient-based glow (filter ID 4) | - | 1 | Yes |
| [ConvolutionFilter](#convolution-filter) | Convolution matrix filter (filter ID 5) | - | 1 | Yes |
| [ColorMatrixFilter](#color-matrix-filter) | 4x5 color matrix transform (filter ID 6) | - | 1 | Yes |
| [GradientBevelFilter](#gradient-bevel-filter) | Gradient-based bevel (filter ID 7) | - | 1 | Yes |

## Implementation Status

### Fully Implemented
(61 features)

| Feature | Category | Tag ID | Tests |
|---------|----------|--------|-------|
| [DefineShape](#define-shape) | Shape Tags | 2 | 25 |
| [DefineShape2](#define-shape2) | Shape Tags | 22 | 2 |
| [DefineShape3](#define-shape3) | Shape Tags | 32 | 2 |
| [DefineShape4](#define-shape4) | Shape Tags | 83 | 1 |
| [SolidFill](#solid-fill) | Fill Types | - | 40 |
| [LinearGradient](#linear-gradient) | Fill Types | - | 3 |
| [RadialGradient](#radial-gradient) | Fill Types | - | 1 |
| [FocalRadialGradient](#focal-radial-gradient) | Fill Types | - | 1 |
| [RepeatingBitmap](#repeating-bitmap) | Fill Types | - | 1 |
| [ClippedBitmap](#clipped-bitmap) | Fill Types | - | 6 |
| [NonSmoothedRepeatingBitmap](#non-smoothed-repeating-bitmap) | Fill Types | - | 1 |
| [NonSmoothedClippedBitmap](#non-smoothed-clipped-bitmap) | Fill Types | - | 1 |
| [StraightEdge](#straight-edge) | Edge Types | - | 55 |
| [CurvedEdge](#curved-edge) | Edge Types | - | 3 |
| [GradientSpread](#gradient-spread) | Gradient Features | - | 1 |
| [LineStyle](#line-style) | Style Features | - | 12 |
| [LineStyle2](#line-style2) | Style Features | - | 1 |
| [NewStyles](#new-styles) | Style Features | - | 2 |
| [DefineBits](#define-bits) | Image/Bitmap Tags | 6 | 1 |
| [JPEGTables](#jpeg-tables) | Image/Bitmap Tags | 8 | 1 |
| [DefineBitsJPEG2](#define-bits-jpeg2) | Image/Bitmap Tags | 21 | 1 |
| [DefineBitsJPEG3](#define-bits-jpeg3) | Image/Bitmap Tags | 35 | 1 |
| [DefineBitsJPEG4](#define-bits-jpeg4) | Image/Bitmap Tags | 90 | 1 |
| [DefineBitsLossless](#define-bits-lossless) | Image/Bitmap Tags | 20 | 4 |
| [DefineBitsLossless2](#define-bits-lossless2) | Image/Bitmap Tags | 36 | 1 |
| [PlaceObject](#place-object) | Display List Tags | 4 | 1 |
| [PlaceObject2](#place-object2) | Display List Tags | 26 | 1 |
| [PlaceObject3](#place-object3) | Display List Tags | 70 | 5 |
| [RemoveObject](#remove-object) | Display List Tags | 5 | 1 |
| [RemoveObject2](#remove-object2) | Display List Tags | 28 | 1 |
| [PlaceObject2 Scale](#place-scale) | Transform Features | - | 1 |
| [PlaceObject2 Skew](#place-skew) | Transform Features | - | 1 |
| [ColorTransform](#color-transform) | Transform Features | - | 2 |
| [ClipDepth](#clip-depth) | Transform Features | - | 1 |
| [ClipActions](#clip-actions) | Transform Features | - | 1 |
| [DefineMorphShape](#define-morph-shape) | Morph Shape Tags | 46 | 1 |
| [DefineMorphShape2](#define-morph-shape2) | Morph Shape Tags | 84 | 1 |
| [DefineFont](#define-font) | Text Tags | 10 | 2 |
| [DefineFont2](#define-font2) | Text Tags | 48 | 2 |
| [DefineFont3](#define-font3) | Text Tags | 75 | 1 |
| [DefineText](#define-text) | Text Tags | 11 | 4 |
| [DefineText2](#define-text2) | Text Tags | 33 | 1 |
| [DefineEditText](#define-edit-text) | Text Tags | 37 | 1 |
| [DefineSprite](#define-sprite) | Sprite Tags | 39 | 5 |
| [DefineButton](#define-button) | Button Tags | 7 | 1 |
| [DefineButton2](#define-button2) | Button Tags | 34 | 1 |
| [DefineSound](#define-sound) | Sound Tags | 14 | 1 |
| [StartSound](#start-sound) | Sound Tags | 15 | 1 |
| [SoundStreamHead](#sound-stream-head) | Sound Tags | 18 | 1 |
| [SoundStreamHead2](#sound-stream-head2) | Sound Tags | 45 | 1 |
| [SoundStreamBlock](#sound-stream-block) | Sound Tags | 19 | 2 |
| [DefineVideoStream](#define-video-stream) | Video Tags | 60 | 1 |
| [VideoFrame](#video-frame) | Video Tags | 61 | 1 |
| [DropShadowFilter](#drop-shadow-filter) | Filter Types | - | 1 |
| [BlurFilter](#blur-filter) | Filter Types | - | 1 |
| [GlowFilter](#glow-filter) | Filter Types | - | 1 |
| [BevelFilter](#bevel-filter) | Filter Types | - | 1 |
| [GradientGlowFilter](#gradient-glow-filter) | Filter Types | - | 1 |
| [ConvolutionFilter](#convolution-filter) | Filter Types | - | 1 |
| [ColorMatrixFilter](#color-matrix-filter) | Filter Types | - | 1 |
| [GradientBevelFilter](#gradient-bevel-filter) | Filter Types | - | 1 |

### Partially Tested
(Has tests but not marked as fully implemented)

**No partially tested features.**

### Not Tested
(No tests at all)

| Feature | Category | Tag ID |
|---------|----------|--------|
| [DefineFont4](#define-font4) | Text Tags | 91 |

## Detailed Information

### DefineShape

**ID**: `DEFINE_SHAPE`

**Description**: Basic shape definition (SWF tag 2)

**Category**: Shape Tags

**Tag ID**: 2

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/awful_gradient`
- `SWFRecomp/tests/graphics/awful_radial_gradient`
- `SWFRecomp/tests/graphics/awful_shape_swf_4`
- `SWFRecomp/tests/graphics/clip_mask`
- `SWFRecomp/tests/graphics/coicle`
- `SWFRecomp/tests/graphics/color_transform`
- `SWFRecomp/tests/graphics/focal_radial_gradient`
- `SWFRecomp/tests/graphics/jpeg2_bitmap`
- `SWFRecomp/tests/graphics/jpeg3_bitmap`
- `SWFRecomp/tests/graphics/jpeg4_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap_rgba`
- `SWFRecomp/tests/graphics/mess`
- `SWFRecomp/tests/graphics/nonsmoothed_clipped_bitmap`
- `SWFRecomp/tests/graphics/nonsmoothed_repeating_bitmap`
- `SWFRecomp/tests/graphics/remove_object`
- `SWFRecomp/tests/graphics/remove_object2`
- `SWFRecomp/tests/graphics/repeating_bitmap`
- `SWFRecomp/tests/graphics/ssquare`
- `SWFRecomp/tests/graphics/sssquare`
- `SWFRecomp/tests/graphics/thiccie`
- `SWFRecomp/tests/graphics/three_boxes`
- `SWFRecomp/tests/graphics/three_boxes_hole`
- `SWFRecomp/tests/graphics/three_boxes_holes`
- `SWFRecomp/tests/graphics/two_squares`

---

### DefineShape2

**ID**: `DEFINE_SHAPE2`

**Description**: Extended shape with >255 styles (SWF tag 22)

**Category**: Shape Tags

**Tag ID**: 22

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/new_styles`
- `SWFRecomp/tests/graphics/wild_shadow`

---

### DefineShape3

**ID**: `DEFINE_SHAPE3`

**Description**: Shape with full RGBA support (SWF tag 32)

**Category**: Shape Tags

**Tag ID**: 32

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/gradient_spread`
- `SWFRecomp/tests/graphics/rgba_shape`

---

### DefineShape4

**ID**: `DEFINE_SHAPE4`

**Description**: Shape with LINESTYLE2 and edge bounds (SWF tag 83)

**Category**: Shape Tags

**Tag ID**: 83

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_shape4`

---

### SolidFill

**ID**: `SOLID_FILL`

**Description**: Solid color fill (type 0x00)

**Category**: Fill Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/awful_shape_swf_4`
- `SWFRecomp/tests/graphics/bevel_filter`
- `SWFRecomp/tests/graphics/blur_filter`
- `SWFRecomp/tests/graphics/clip_actions`
- `SWFRecomp/tests/graphics/clip_mask`
- `SWFRecomp/tests/graphics/coicle`
- `SWFRecomp/tests/graphics/color_matrix_filter`
- `SWFRecomp/tests/graphics/color_transform`
- `SWFRecomp/tests/graphics/convolution_filter`
- `SWFRecomp/tests/graphics/define_button`
- `SWFRecomp/tests/graphics/define_button2`
- `SWFRecomp/tests/graphics/define_edit_text`
- `SWFRecomp/tests/graphics/define_font2`
- `SWFRecomp/tests/graphics/define_morph_shape`
- `SWFRecomp/tests/graphics/define_morph_shape2`
- `SWFRecomp/tests/graphics/define_shape4`
- `SWFRecomp/tests/graphics/define_sound`
- `SWFRecomp/tests/graphics/define_text2`
- `SWFRecomp/tests/graphics/drop_shadow_filter`
- `SWFRecomp/tests/graphics/glow_filter`
- `SWFRecomp/tests/graphics/gradient_bevel_filter`
- `SWFRecomp/tests/graphics/gradient_glow_filter`
- `SWFRecomp/tests/graphics/movieclip_control`
- `SWFRecomp/tests/graphics/new_styles`
- `SWFRecomp/tests/graphics/place_object`
- `SWFRecomp/tests/graphics/place_object3`
- `SWFRecomp/tests/graphics/remove_object`
- `SWFRecomp/tests/graphics/remove_object2`
- `SWFRecomp/tests/graphics/rgba_shape`
- `SWFRecomp/tests/graphics/sound_stream`
- `SWFRecomp/tests/graphics/sound_stream_head2`
- `SWFRecomp/tests/graphics/sprite_multiframe`
- `SWFRecomp/tests/graphics/sprite_nested`
- `SWFRecomp/tests/graphics/ssquare`
- `SWFRecomp/tests/graphics/sssquare`
- `SWFRecomp/tests/graphics/three_boxes`
- `SWFRecomp/tests/graphics/three_boxes_hole`
- `SWFRecomp/tests/graphics/three_boxes_holes`
- `SWFRecomp/tests/graphics/two_squares`
- `SWFRecomp/tests/graphics/wild_shadow`

---

### LinearGradient

**ID**: `LINEAR_GRADIENT`

**Description**: Linear gradient fill (type 0x10)

**Category**: Fill Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/awful_gradient`
- `SWFRecomp/tests/graphics/awful_radial_gradient`
- `SWFRecomp/tests/graphics/gradient_spread`

---

### RadialGradient

**ID**: `RADIAL_GRADIENT`

**Description**: Radial gradient fill (type 0x12)

**Category**: Fill Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/awful_radial_gradient`

---

### FocalRadialGradient

**ID**: `FOCAL_RADIAL_GRADIENT`

**Description**: Focal radial gradient fill (type 0x13, SWF 8+)

**Category**: Fill Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/focal_radial_gradient`

---

### RepeatingBitmap

**ID**: `REPEATING_BITMAP`

**Description**: Tiled bitmap fill (type 0x40)

**Category**: Fill Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/repeating_bitmap`

---

### ClippedBitmap

**ID**: `CLIPPED_BITMAP`

**Description**: Clipped bitmap fill (type 0x41)

**Category**: Fill Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/jpeg2_bitmap`
- `SWFRecomp/tests/graphics/jpeg3_bitmap`
- `SWFRecomp/tests/graphics/jpeg4_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap_rgba`
- `SWFRecomp/tests/graphics/mess`

---

### NonSmoothedRepeatingBitmap

**ID**: `NON_SMOOTHED_REPEATING_BITMAP`

**Description**: Tiled bitmap without anti-aliasing (type 0x42)

**Category**: Fill Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/nonsmoothed_repeating_bitmap`

---

### NonSmoothedClippedBitmap

**ID**: `NON_SMOOTHED_CLIPPED_BITMAP`

**Description**: Clipped bitmap without anti-aliasing (type 0x43)

**Category**: Fill Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/nonsmoothed_clipped_bitmap`

---

### StraightEdge

**ID**: `STRAIGHT_EDGE`

**Description**: Straight edge records (LineTo)

**Category**: Edge Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/awful_gradient`
- `SWFRecomp/tests/graphics/awful_radial_gradient`
- `SWFRecomp/tests/graphics/awful_shape_swf_4`
- `SWFRecomp/tests/graphics/bevel_filter`
- `SWFRecomp/tests/graphics/blur_filter`
- `SWFRecomp/tests/graphics/clip_actions`
- `SWFRecomp/tests/graphics/clip_mask`
- `SWFRecomp/tests/graphics/color_matrix_filter`
- `SWFRecomp/tests/graphics/color_transform`
- `SWFRecomp/tests/graphics/convolution_filter`
- `SWFRecomp/tests/graphics/define_button`
- `SWFRecomp/tests/graphics/define_button2`
- `SWFRecomp/tests/graphics/define_edit_text`
- `SWFRecomp/tests/graphics/define_font2`
- `SWFRecomp/tests/graphics/define_font3`
- `SWFRecomp/tests/graphics/define_morph_shape`
- `SWFRecomp/tests/graphics/define_morph_shape2`
- `SWFRecomp/tests/graphics/define_shape4`
- `SWFRecomp/tests/graphics/define_sound`
- `SWFRecomp/tests/graphics/define_text2`
- `SWFRecomp/tests/graphics/drop_shadow_filter`
- `SWFRecomp/tests/graphics/focal_radial_gradient`
- `SWFRecomp/tests/graphics/glow_filter`
- `SWFRecomp/tests/graphics/gradient_bevel_filter`
- `SWFRecomp/tests/graphics/gradient_glow_filter`
- `SWFRecomp/tests/graphics/gradient_spread`
- `SWFRecomp/tests/graphics/jpeg2_bitmap`
- `SWFRecomp/tests/graphics/jpeg3_bitmap`
- `SWFRecomp/tests/graphics/jpeg4_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap_rgba`
- `SWFRecomp/tests/graphics/mess`
- `SWFRecomp/tests/graphics/movieclip_control`
- `SWFRecomp/tests/graphics/new_styles`
- `SWFRecomp/tests/graphics/nonsmoothed_clipped_bitmap`
- `SWFRecomp/tests/graphics/nonsmoothed_repeating_bitmap`
- `SWFRecomp/tests/graphics/place_object`
- `SWFRecomp/tests/graphics/place_object3`
- `SWFRecomp/tests/graphics/remove_object`
- `SWFRecomp/tests/graphics/remove_object2`
- `SWFRecomp/tests/graphics/repeating_bitmap`
- `SWFRecomp/tests/graphics/rgba_shape`
- `SWFRecomp/tests/graphics/sound_stream`
- `SWFRecomp/tests/graphics/sound_stream_head2`
- `SWFRecomp/tests/graphics/sprite_multiframe`
- `SWFRecomp/tests/graphics/sprite_nested`
- `SWFRecomp/tests/graphics/ssquare`
- `SWFRecomp/tests/graphics/sssquare`
- `SWFRecomp/tests/graphics/static_text`
- `SWFRecomp/tests/graphics/thiccie`
- `SWFRecomp/tests/graphics/three_boxes`
- `SWFRecomp/tests/graphics/three_boxes_hole`
- `SWFRecomp/tests/graphics/three_boxes_holes`
- `SWFRecomp/tests/graphics/two_squares`
- `SWFRecomp/tests/graphics/wild_shadow`

---

### CurvedEdge

**ID**: `CURVED_EDGE`

**Description**: Curved edge records (CurveTo)

**Category**: Edge Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/clip_mask`
- `SWFRecomp/tests/graphics/coicle`
- `SWFRecomp/tests/graphics/wild_shadow`

---

### GradientSpread

**ID**: `GRADIENT_SPREAD`

**Description**: Gradient spread modes (pad, reflect, repeat)

**Category**: Gradient Features

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/gradient_spread`

---

### LineStyle

**ID**: `LINE_STYLE`

**Description**: Basic stroke line style (LINESTYLE)

**Category**: Style Features

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/awful_gradient`
- `SWFRecomp/tests/graphics/awful_radial_gradient`
- `SWFRecomp/tests/graphics/clip_mask`
- `SWFRecomp/tests/graphics/color_transform`
- `SWFRecomp/tests/graphics/focal_radial_gradient`
- `SWFRecomp/tests/graphics/new_styles`
- `SWFRecomp/tests/graphics/rgba_shape`
- `SWFRecomp/tests/graphics/thiccie`
- `SWFRecomp/tests/graphics/three_boxes`
- `SWFRecomp/tests/graphics/three_boxes_hole`
- `SWFRecomp/tests/graphics/three_boxes_holes`
- `SWFRecomp/tests/graphics/two_squares`

---

### LineStyle2

**ID**: `LINE_STYLE2`

**Description**: Advanced line style with caps/joins (LINESTYLE2, DefineShape4)

**Category**: Style Features

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_shape4`

---

### NewStyles

**ID**: `NEW_STYLES`

**Description**: Mid-shape style changes (StateNewStyles)

**Category**: Style Features

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/new_styles`
- `SWFRecomp/tests/graphics/wild_shadow`

---

### DefineBits

**ID**: `DEFINE_BITS`

**Description**: JPEG bitmap requiring JPEGTables (SWF tag 6)

**Category**: Image/Bitmap Tags

**Tag ID**: 6

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/mess`

---

### JPEGTables

**ID**: `JPEG_TABLES`

**Description**: Shared JPEG encoding tables (SWF tag 8)

**Category**: Image/Bitmap Tags

**Tag ID**: 8

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/mess`

---

### DefineBitsJPEG2

**ID**: `DEFINE_BITS_JPEG2`

**Description**: Self-contained JPEG image (SWF tag 21)

**Category**: Image/Bitmap Tags

**Tag ID**: 21

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/jpeg2_bitmap`

---

### DefineBitsJPEG3

**ID**: `DEFINE_BITS_JPEG3`

**Description**: JPEG image with alpha channel (SWF tag 35)

**Category**: Image/Bitmap Tags

**Tag ID**: 35

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/jpeg3_bitmap`

---

### DefineBitsJPEG4

**ID**: `DEFINE_BITS_JPEG4`

**Description**: JPEG with embedded alpha (SWF tag 90, SWF 10+)

**Category**: Image/Bitmap Tags

**Tag ID**: 90

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/jpeg4_bitmap`

---

### DefineBitsLossless

**ID**: `DEFINE_BITS_LOSSLESS`

**Description**: Lossless RGB bitmap (SWF tag 20)

**Category**: Image/Bitmap Tags

**Tag ID**: 20

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/lossless_bitmap`
- `SWFRecomp/tests/graphics/nonsmoothed_clipped_bitmap`
- `SWFRecomp/tests/graphics/nonsmoothed_repeating_bitmap`
- `SWFRecomp/tests/graphics/repeating_bitmap`

---

### DefineBitsLossless2

**ID**: `DEFINE_BITS_LOSSLESS2`

**Description**: Lossless RGBA bitmap (SWF tag 36)

**Category**: Image/Bitmap Tags

**Tag ID**: 36

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/lossless_bitmap_rgba`

---

### PlaceObject

**ID**: `PLACE_OBJECT`

**Description**: Basic object placement (SWF tag 4)

**Category**: Display List Tags

**Tag ID**: 4

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/place_object`

---

### PlaceObject2

**ID**: `PLACE_OBJECT2`

**Description**: Enhanced object placement (SWF tag 26)

**Category**: Display List Tags

**Tag ID**: 26

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/movieclip_control`

---

### PlaceObject3

**ID**: `PLACE_OBJECT3`

**Description**: Object placement with filters/blend (SWF tag 70)

**Category**: Display List Tags

**Tag ID**: 70

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/blur_filter`
- `SWFRecomp/tests/graphics/color_matrix_filter`
- `SWFRecomp/tests/graphics/drop_shadow_filter`
- `SWFRecomp/tests/graphics/glow_filter`
- `SWFRecomp/tests/graphics/place_object3`

---

### RemoveObject

**ID**: `REMOVE_OBJECT`

**Description**: Remove object by ID (SWF tag 5)

**Category**: Display List Tags

**Tag ID**: 5

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/remove_object`

---

### RemoveObject2

**ID**: `REMOVE_OBJECT2`

**Description**: Remove object by depth (SWF tag 28)

**Category**: Display List Tags

**Tag ID**: 28

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/remove_object2`

---

### PlaceObject2 Scale

**ID**: `PLACE_SCALE`

**Description**: Scale transform in PlaceObject2

**Category**: Transform Features

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/wild_shadow`

---

### PlaceObject2 Skew

**ID**: `PLACE_SKEW`

**Description**: Skew transform in PlaceObject2

**Category**: Transform Features

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/wild_shadow`

---

### ColorTransform

**ID**: `COLOR_TRANSFORM`

**Description**: Color transform (CXFORM/CXFORMWITHALPHA)

**Category**: Transform Features

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/color_transform`
- `SWFRecomp/tests/graphics/place_object`

---

### ClipDepth

**ID**: `CLIP_DEPTH`

**Description**: Clipping mask via PlaceObject2 ClipDepth

**Category**: Transform Features

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/clip_mask`

---

### ClipActions

**ID**: `CLIP_ACTIONS`

**Description**: CLIPACTIONS event handlers on PlaceObject2

**Category**: Transform Features

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/clip_actions`

---

### DefineMorphShape

**ID**: `DEFINE_MORPH_SHAPE`

**Description**: Shape morphing/tweening (SWF tag 46)

**Category**: Morph Shape Tags

**Tag ID**: 46

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_morph_shape`

---

### DefineMorphShape2

**ID**: `DEFINE_MORPH_SHAPE2`

**Description**: Enhanced morphing with LINESTYLE2 (SWF tag 84)

**Category**: Morph Shape Tags

**Tag ID**: 84

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_morph_shape2`

---

### DefineFont

**ID**: `DEFINE_FONT`

**Description**: Basic font with glyph shapes (SWF tag 10)

**Category**: Text Tags

**Tag ID**: 10

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_text2`
- `SWFRecomp/tests/graphics/static_text`

---

### DefineFont2

**ID**: `DEFINE_FONT2`

**Description**: Font with layout metrics (SWF tag 48)

**Category**: Text Tags

**Tag ID**: 48

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_edit_text`
- `SWFRecomp/tests/graphics/define_font2`

---

### DefineFont3

**ID**: `DEFINE_FONT3`

**Description**: Enhanced font definition (SWF tag 75)

**Category**: Text Tags

**Tag ID**: 75

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_font3`

---

### DefineFont4

**ID**: `DEFINE_FONT4`

**Description**: CFF font for Flash Text Engine (SWF tag 91)

**Category**: Text Tags

**Tag ID**: 91

**Fully Implemented**: No

**Tests:** None

---

### DefineText

**ID**: `DEFINE_TEXT`

**Description**: Static text with glyph indices (SWF tag 11)

**Category**: Text Tags

**Tag ID**: 11

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_font2`
- `SWFRecomp/tests/graphics/define_font3`
- `SWFRecomp/tests/graphics/sprite_nested`
- `SWFRecomp/tests/graphics/static_text`

---

### DefineText2

**ID**: `DEFINE_TEXT2`

**Description**: Static text with RGBA colors (SWF tag 33)

**Category**: Text Tags

**Tag ID**: 33

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_text2`

---

### DefineEditText

**ID**: `DEFINE_EDIT_TEXT`

**Description**: Dynamic/editable text field (SWF tag 37)

**Category**: Text Tags

**Tag ID**: 37

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_edit_text`

---

### DefineSprite

**ID**: `DEFINE_SPRITE`

**Description**: Embedded movie clip with own timeline (SWF tag 39)

**Category**: Sprite Tags

**Tag ID**: 39

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/clip_actions`
- `SWFRecomp/tests/graphics/movieclip_control`
- `SWFRecomp/tests/graphics/sprite_basic`
- `SWFRecomp/tests/graphics/sprite_multiframe`
- `SWFRecomp/tests/graphics/sprite_nested`

---

### DefineButton

**ID**: `DEFINE_BUTTON`

**Description**: Basic button with state shapes (SWF tag 7)

**Category**: Button Tags

**Tag ID**: 7

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_button`

---

### DefineButton2

**ID**: `DEFINE_BUTTON2`

**Description**: Enhanced button with actions (SWF tag 34)

**Category**: Button Tags

**Tag ID**: 34

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_button2`

---

### DefineSound

**ID**: `DEFINE_SOUND`

**Description**: Event sound definition (SWF tag 14)

**Category**: Sound Tags

**Tag ID**: 14

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_sound`

---

### StartSound

**ID**: `START_SOUND`

**Description**: Play/stop event sound (SWF tag 15)

**Category**: Sound Tags

**Tag ID**: 15

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_sound`

---

### SoundStreamHead

**ID**: `SOUND_STREAM_HEAD`

**Description**: Streaming sound header (SWF tag 18)

**Category**: Sound Tags

**Tag ID**: 18

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/sound_stream`

---

### SoundStreamHead2

**ID**: `SOUND_STREAM_HEAD2`

**Description**: Enhanced streaming sound header (SWF tag 45)

**Category**: Sound Tags

**Tag ID**: 45

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/sound_stream_head2`

---

### SoundStreamBlock

**ID**: `SOUND_STREAM_BLOCK`

**Description**: Streaming audio frame data (SWF tag 19)

**Category**: Sound Tags

**Tag ID**: 19

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/sound_stream`
- `SWFRecomp/tests/graphics/sound_stream_head2`

---

### DefineVideoStream

**ID**: `DEFINE_VIDEO_STREAM`

**Description**: Video stream definition (SWF tag 60)

**Category**: Video Tags

**Tag ID**: 60

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_video_stream`

---

### VideoFrame

**ID**: `VIDEO_FRAME`

**Description**: Video frame data (SWF tag 61)

**Category**: Video Tags

**Tag ID**: 61

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/define_video_stream`

---

### DropShadowFilter

**ID**: `DROP_SHADOW_FILTER`

**Description**: Drop shadow effect (filter ID 0)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/drop_shadow_filter`

---

### BlurFilter

**ID**: `BLUR_FILTER`

**Description**: Gaussian blur effect (filter ID 1)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/blur_filter`

---

### GlowFilter

**ID**: `GLOW_FILTER`

**Description**: Glow/halo effect (filter ID 2)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/glow_filter`

---

### BevelFilter

**ID**: `BEVEL_FILTER`

**Description**: Beveled edge effect (filter ID 3)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/bevel_filter`

---

### GradientGlowFilter

**ID**: `GRADIENT_GLOW_FILTER`

**Description**: Gradient-based glow (filter ID 4)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/gradient_glow_filter`

---

### ConvolutionFilter

**ID**: `CONVOLUTION_FILTER`

**Description**: Convolution matrix filter (filter ID 5)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/convolution_filter`

---

### ColorMatrixFilter

**ID**: `COLOR_MATRIX_FILTER`

**Description**: 4x5 color matrix transform (filter ID 6)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/color_matrix_filter`

---

### GradientBevelFilter

**ID**: `GRADIENT_BEVEL_FILTER`

**Description**: Gradient-based bevel (filter ID 7)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/gradient_bevel_filter`

---
