# SWF Graphics Feature Index

**Generated**: 2026-02-08

See also: [AS2 Opcode Index](opcode-index-plain.md)

## Feature Statistics

**Total SWF Features**: 60

**Features With Tests**: 27/60

**Features Without Tests**: 33

**Total Feature Tests**: 104

**Fully Implemented**: 27/60

## Summary Tables

### Shape Tags
(3/4 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| DefineShape | Basic shape definition (SWF tag 2) | 2 | 21 | Yes |
| DefineShape2 | Extended shape with >255 styles (SWF tag 22) | 22 | 2 | Yes |
| DefineShape3 | Shape with full RGBA support (SWF tag 32) | 32 | 1 | Yes |
| DefineShape4 | Shape with LINESTYLE2 and edge bounds (SWF tag 83) | 83 | **0** | No |

### Fill Types
(7/8 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| SolidFill | Solid color fill (type 0x00) | - | 13 | Yes |
| LinearGradient | Linear gradient fill (type 0x10) | - | 2 | Yes |
| RadialGradient | Radial gradient fill (type 0x12) | - | 1 | Yes |
| FocalRadialGradient | Focal radial gradient fill (type 0x13, SWF 8+) | - | **0** | No |
| RepeatingBitmap | Tiled bitmap fill (type 0x40) | - | 1 | Yes |
| ClippedBitmap | Clipped bitmap fill (type 0x41) | - | 5 | Yes |
| NonSmoothedRepeatingBitmap | Tiled bitmap without anti-aliasing (type 0x42) | - | 1 | Yes |
| NonSmoothedClippedBitmap | Clipped bitmap without anti-aliasing (type 0x43) | - | 1 | Yes |

### Edge Types
(2/2 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| StraightEdge | Straight edge records (LineTo) | - | 24 | Yes |
| CurvedEdge | Curved edge records (CurveTo) | - | 3 | Yes |

### Style Features
(2/3 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| LineStyle | Basic stroke line style (LINESTYLE) | - | 11 | Yes |
| LineStyle2 | Advanced line style with caps/joins (LINESTYLE2, DefineShape4) | - | **0** | No |
| NewStyles | Mid-shape style changes (StateNewStyles) | - | 2 | Yes |

### Image/Bitmap Tags
(6/7 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| DefineBits | JPEG bitmap requiring JPEGTables (SWF tag 6) | 6 | 1 | Yes |
| JPEGTables | Shared JPEG encoding tables (SWF tag 8) | 8 | 1 | Yes |
| DefineBitsJPEG2 | Self-contained JPEG image (SWF tag 21) | 21 | 1 | Yes |
| DefineBitsJPEG3 | JPEG image with alpha channel (SWF tag 35) | 35 | 1 | Yes |
| DefineBitsJPEG4 | JPEG with embedded alpha (SWF tag 90, SWF 10+) | 90 | **0** | No |
| DefineBitsLossless | Lossless RGB bitmap (SWF tag 20) | 20 | 4 | Yes |
| DefineBitsLossless2 | Lossless RGBA bitmap (SWF tag 36) | 36 | 1 | Yes |

### Display List Tags
(0/5 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| PlaceObject | Basic object placement (SWF tag 4) | 4 | **0** | No |
| PlaceObject2 | Enhanced object placement (SWF tag 26) | 26 | **0** | No |
| PlaceObject3 | Object placement with filters/blend (SWF tag 70) | 70 | **0** | No |
| RemoveObject | Remove object by ID (SWF tag 5) | 5 | **0** | No |
| RemoveObject2 | Remove object by depth (SWF tag 28) | 28 | **0** | No |

### Transform Features
(4/4 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| PlaceObject2 Scale | Scale transform in PlaceObject2 | - | 1 | Yes |
| PlaceObject2 Skew | Skew transform in PlaceObject2 | - | 1 | Yes |
| ColorTransform | Color transform (CXFORM/CXFORMWITHALPHA) | - | 1 | Yes |
| ClipDepth | Clipping mask via PlaceObject2 ClipDepth | - | 1 | Yes |

### Morph Shape Tags
(0/2 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| DefineMorphShape | Shape morphing/tweening (SWF tag 46) | 46 | **0** | No |
| DefineMorphShape2 | Enhanced morphing with LINESTYLE2 (SWF tag 84) | 84 | **0** | No |

### Text Tags
(2/7 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| DefineFont | Basic font with glyph shapes (SWF tag 10) | 10 | 1 | Yes |
| DefineFont2 | Font with layout metrics (SWF tag 48) | 48 | **0** | No |
| DefineFont3 | Enhanced font definition (SWF tag 75) | 75 | **0** | No |
| DefineFont4 | CFF font for Flash Text Engine (SWF tag 91) | 91 | **0** | No |
| DefineText | Static text with glyph indices (SWF tag 11) | 11 | 1 | Yes |
| DefineText2 | Static text with RGBA colors (SWF tag 33) | 33 | **0** | No |
| DefineEditText | Dynamic/editable text field (SWF tag 37) | 37 | **0** | No |

### Sprite Tags
(1/1 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| DefineSprite | Embedded movie clip with own timeline (SWF tag 39) | 39 | 1 | Yes |

### Button Tags
(0/2 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| DefineButton | Basic button with state shapes (SWF tag 7) | 7 | **0** | No |
| DefineButton2 | Enhanced button with actions (SWF tag 34) | 34 | **0** | No |

### Sound Tags
(0/5 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| DefineSound | Event sound definition (SWF tag 14) | 14 | **0** | No |
| StartSound | Play/stop event sound (SWF tag 15) | 15 | **0** | No |
| SoundStreamHead | Streaming sound header (SWF tag 18) | 18 | **0** | No |
| SoundStreamHead2 | Enhanced streaming sound header (SWF tag 45) | 45 | **0** | No |
| SoundStreamBlock | Streaming audio frame data (SWF tag 19) | 19 | **0** | No |

### Video Tags
(0/2 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| DefineVideoStream | Video stream definition (SWF tag 60) | 60 | **0** | No |
| VideoFrame | Video frame data (SWF tag 61) | 61 | **0** | No |

### Filter Types
(0/8 with tests)

| Feature | Description | Tag ID | Tests | Implemented |
|---------|-------------|--------|-------|-------------|
| DropShadowFilter | Drop shadow effect (filter ID 0) | - | **0** | No |
| BlurFilter | Gaussian blur effect (filter ID 1) | - | **0** | No |
| GlowFilter | Glow/halo effect (filter ID 2) | - | **0** | No |
| BevelFilter | Beveled edge effect (filter ID 3) | - | **0** | No |
| GradientGlowFilter | Gradient-based glow (filter ID 4) | - | **0** | No |
| ConvolutionFilter | Convolution matrix filter (filter ID 5) | - | **0** | No |
| ColorMatrixFilter | 4x5 color matrix transform (filter ID 6) | - | **0** | No |
| GradientBevelFilter | Gradient-based bevel (filter ID 7) | - | **0** | No |

## Implementation Status

### Fully Implemented
(27 features)

| Feature | Category | Tag ID | Tests |
|---------|----------|--------|-------|
| DefineShape | Shape Tags | 2 | 21 |
| DefineShape2 | Shape Tags | 22 | 2 |
| DefineShape3 | Shape Tags | 32 | 1 |
| SolidFill | Fill Types | - | 13 |
| LinearGradient | Fill Types | - | 2 |
| RadialGradient | Fill Types | - | 1 |
| RepeatingBitmap | Fill Types | - | 1 |
| ClippedBitmap | Fill Types | - | 5 |
| NonSmoothedRepeatingBitmap | Fill Types | - | 1 |
| NonSmoothedClippedBitmap | Fill Types | - | 1 |
| StraightEdge | Edge Types | - | 24 |
| CurvedEdge | Edge Types | - | 3 |
| LineStyle | Style Features | - | 11 |
| NewStyles | Style Features | - | 2 |
| DefineBits | Image/Bitmap Tags | 6 | 1 |
| JPEGTables | Image/Bitmap Tags | 8 | 1 |
| DefineBitsJPEG2 | Image/Bitmap Tags | 21 | 1 |
| DefineBitsJPEG3 | Image/Bitmap Tags | 35 | 1 |
| DefineBitsLossless | Image/Bitmap Tags | 20 | 4 |
| DefineBitsLossless2 | Image/Bitmap Tags | 36 | 1 |
| PlaceObject2 Scale | Transform Features | - | 1 |
| PlaceObject2 Skew | Transform Features | - | 1 |
| ColorTransform | Transform Features | - | 1 |
| ClipDepth | Transform Features | - | 1 |
| DefineFont | Text Tags | 10 | 1 |
| DefineText | Text Tags | 11 | 1 |
| DefineSprite | Sprite Tags | 39 | 1 |

### Partially Tested
(Has tests but not marked as fully implemented)

**No partially tested features.**

### Not Tested
(No tests at all)

| Feature | Category | Tag ID |
|---------|----------|--------|
| DefineShape4 | Shape Tags | 83 |
| FocalRadialGradient | Fill Types | - |
| LineStyle2 | Style Features | - |
| DefineBitsJPEG4 | Image/Bitmap Tags | 90 |
| PlaceObject | Display List Tags | 4 |
| PlaceObject2 | Display List Tags | 26 |
| PlaceObject3 | Display List Tags | 70 |
| RemoveObject | Display List Tags | 5 |
| RemoveObject2 | Display List Tags | 28 |
| DefineMorphShape | Morph Shape Tags | 46 |
| DefineMorphShape2 | Morph Shape Tags | 84 |
| DefineFont2 | Text Tags | 48 |
| DefineFont3 | Text Tags | 75 |
| DefineFont4 | Text Tags | 91 |
| DefineText2 | Text Tags | 33 |
| DefineEditText | Text Tags | 37 |
| DefineButton | Button Tags | 7 |
| DefineButton2 | Button Tags | 34 |
| DefineSound | Sound Tags | 14 |
| StartSound | Sound Tags | 15 |
| SoundStreamHead | Sound Tags | 18 |
| SoundStreamHead2 | Sound Tags | 45 |
| SoundStreamBlock | Sound Tags | 19 |
| DefineVideoStream | Video Tags | 60 |
| VideoFrame | Video Tags | 61 |
| DropShadowFilter | Filter Types | - |
| BlurFilter | Filter Types | - |
| GlowFilter | Filter Types | - |
| BevelFilter | Filter Types | - |
| GradientGlowFilter | Filter Types | - |
| ConvolutionFilter | Filter Types | - |
| ColorMatrixFilter | Filter Types | - |
| GradientBevelFilter | Filter Types | - |

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
- `SWFRecomp/tests/graphics/jpeg2_bitmap`
- `SWFRecomp/tests/graphics/jpeg3_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap_rgba`
- `SWFRecomp/tests/graphics/mess`
- `SWFRecomp/tests/graphics/nonsmoothed_clipped_bitmap`
- `SWFRecomp/tests/graphics/nonsmoothed_repeating_bitmap`
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
- `SWFRecomp/tests/graphics/rgba_shape`

---

### DefineShape4

**ID**: `DEFINE_SHAPE4`

**Description**: Shape with LINESTYLE2 and edge bounds (SWF tag 83)

**Category**: Shape Tags

**Tag ID**: 83

**Fully Implemented**: No

**Tests:** None

---

### SolidFill

**ID**: `SOLID_FILL`

**Description**: Solid color fill (type 0x00)

**Category**: Fill Types

**Tag ID**: N/A

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/awful_shape_swf_4`
- `SWFRecomp/tests/graphics/clip_mask`
- `SWFRecomp/tests/graphics/coicle`
- `SWFRecomp/tests/graphics/color_transform`
- `SWFRecomp/tests/graphics/new_styles`
- `SWFRecomp/tests/graphics/rgba_shape`
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

**Fully Implemented**: No

**Tests:** None

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
- `SWFRecomp/tests/graphics/clip_mask`
- `SWFRecomp/tests/graphics/color_transform`
- `SWFRecomp/tests/graphics/jpeg2_bitmap`
- `SWFRecomp/tests/graphics/jpeg3_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap`
- `SWFRecomp/tests/graphics/lossless_bitmap_rgba`
- `SWFRecomp/tests/graphics/mess`
- `SWFRecomp/tests/graphics/new_styles`
- `SWFRecomp/tests/graphics/nonsmoothed_clipped_bitmap`
- `SWFRecomp/tests/graphics/nonsmoothed_repeating_bitmap`
- `SWFRecomp/tests/graphics/repeating_bitmap`
- `SWFRecomp/tests/graphics/rgba_shape`
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

**Fully Implemented**: No

**Tests:** None

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

**Fully Implemented**: No

**Tests:** None

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

**Fully Implemented**: No

**Tests:** None

---

### PlaceObject2

**ID**: `PLACE_OBJECT2`

**Description**: Enhanced object placement (SWF tag 26)

**Category**: Display List Tags

**Tag ID**: 26

**Fully Implemented**: No

**Tests:** None

---

### PlaceObject3

**ID**: `PLACE_OBJECT3`

**Description**: Object placement with filters/blend (SWF tag 70)

**Category**: Display List Tags

**Tag ID**: 70

**Fully Implemented**: No

**Tests:** None

---

### RemoveObject

**ID**: `REMOVE_OBJECT`

**Description**: Remove object by ID (SWF tag 5)

**Category**: Display List Tags

**Tag ID**: 5

**Fully Implemented**: No

**Tests:** None

---

### RemoveObject2

**ID**: `REMOVE_OBJECT2`

**Description**: Remove object by depth (SWF tag 28)

**Category**: Display List Tags

**Tag ID**: 28

**Fully Implemented**: No

**Tests:** None

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

### DefineMorphShape

**ID**: `DEFINE_MORPH_SHAPE`

**Description**: Shape morphing/tweening (SWF tag 46)

**Category**: Morph Shape Tags

**Tag ID**: 46

**Fully Implemented**: No

**Tests:** None

---

### DefineMorphShape2

**ID**: `DEFINE_MORPH_SHAPE2`

**Description**: Enhanced morphing with LINESTYLE2 (SWF tag 84)

**Category**: Morph Shape Tags

**Tag ID**: 84

**Fully Implemented**: No

**Tests:** None

---

### DefineFont

**ID**: `DEFINE_FONT`

**Description**: Basic font with glyph shapes (SWF tag 10)

**Category**: Text Tags

**Tag ID**: 10

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/static_text`

---

### DefineFont2

**ID**: `DEFINE_FONT2`

**Description**: Font with layout metrics (SWF tag 48)

**Category**: Text Tags

**Tag ID**: 48

**Fully Implemented**: No

**Tests:** None

---

### DefineFont3

**ID**: `DEFINE_FONT3`

**Description**: Enhanced font definition (SWF tag 75)

**Category**: Text Tags

**Tag ID**: 75

**Fully Implemented**: No

**Tests:** None

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
- `SWFRecomp/tests/graphics/static_text`

---

### DefineText2

**ID**: `DEFINE_TEXT2`

**Description**: Static text with RGBA colors (SWF tag 33)

**Category**: Text Tags

**Tag ID**: 33

**Fully Implemented**: No

**Tests:** None

---

### DefineEditText

**ID**: `DEFINE_EDIT_TEXT`

**Description**: Dynamic/editable text field (SWF tag 37)

**Category**: Text Tags

**Tag ID**: 37

**Fully Implemented**: No

**Tests:** None

---

### DefineSprite

**ID**: `DEFINE_SPRITE`

**Description**: Embedded movie clip with own timeline (SWF tag 39)

**Category**: Sprite Tags

**Tag ID**: 39

**Fully Implemented**: Yes

**Tests:**
- `SWFRecomp/tests/graphics/sprite_basic`

---

### DefineButton

**ID**: `DEFINE_BUTTON`

**Description**: Basic button with state shapes (SWF tag 7)

**Category**: Button Tags

**Tag ID**: 7

**Fully Implemented**: No

**Tests:** None

---

### DefineButton2

**ID**: `DEFINE_BUTTON2`

**Description**: Enhanced button with actions (SWF tag 34)

**Category**: Button Tags

**Tag ID**: 34

**Fully Implemented**: No

**Tests:** None

---

### DefineSound

**ID**: `DEFINE_SOUND`

**Description**: Event sound definition (SWF tag 14)

**Category**: Sound Tags

**Tag ID**: 14

**Fully Implemented**: No

**Tests:** None

---

### StartSound

**ID**: `START_SOUND`

**Description**: Play/stop event sound (SWF tag 15)

**Category**: Sound Tags

**Tag ID**: 15

**Fully Implemented**: No

**Tests:** None

---

### SoundStreamHead

**ID**: `SOUND_STREAM_HEAD`

**Description**: Streaming sound header (SWF tag 18)

**Category**: Sound Tags

**Tag ID**: 18

**Fully Implemented**: No

**Tests:** None

---

### SoundStreamHead2

**ID**: `SOUND_STREAM_HEAD2`

**Description**: Enhanced streaming sound header (SWF tag 45)

**Category**: Sound Tags

**Tag ID**: 45

**Fully Implemented**: No

**Tests:** None

---

### SoundStreamBlock

**ID**: `SOUND_STREAM_BLOCK`

**Description**: Streaming audio frame data (SWF tag 19)

**Category**: Sound Tags

**Tag ID**: 19

**Fully Implemented**: No

**Tests:** None

---

### DefineVideoStream

**ID**: `DEFINE_VIDEO_STREAM`

**Description**: Video stream definition (SWF tag 60)

**Category**: Video Tags

**Tag ID**: 60

**Fully Implemented**: No

**Tests:** None

---

### VideoFrame

**ID**: `VIDEO_FRAME`

**Description**: Video frame data (SWF tag 61)

**Category**: Video Tags

**Tag ID**: 61

**Fully Implemented**: No

**Tests:** None

---

### DropShadowFilter

**ID**: `DROP_SHADOW_FILTER`

**Description**: Drop shadow effect (filter ID 0)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: No

**Tests:** None

---

### BlurFilter

**ID**: `BLUR_FILTER`

**Description**: Gaussian blur effect (filter ID 1)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: No

**Tests:** None

---

### GlowFilter

**ID**: `GLOW_FILTER`

**Description**: Glow/halo effect (filter ID 2)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: No

**Tests:** None

---

### BevelFilter

**ID**: `BEVEL_FILTER`

**Description**: Beveled edge effect (filter ID 3)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: No

**Tests:** None

---

### GradientGlowFilter

**ID**: `GRADIENT_GLOW_FILTER`

**Description**: Gradient-based glow (filter ID 4)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: No

**Tests:** None

---

### ConvolutionFilter

**ID**: `CONVOLUTION_FILTER`

**Description**: Convolution matrix filter (filter ID 5)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: No

**Tests:** None

---

### ColorMatrixFilter

**ID**: `COLOR_MATRIX_FILTER`

**Description**: 4x5 color matrix transform (filter ID 6)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: No

**Tests:** None

---

### GradientBevelFilter

**ID**: `GRADIENT_BEVEL_FILTER`

**Description**: Gradient-based bevel (filter ID 7)

**Category**: Filter Types

**Tag ID**: N/A

**Fully Implemented**: No

**Tests:** None

---
