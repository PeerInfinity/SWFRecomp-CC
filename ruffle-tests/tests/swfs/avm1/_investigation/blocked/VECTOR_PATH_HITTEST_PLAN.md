# Vector-Path Hit Testing Plan
<!-- TESTS: movieclip_hittest_shapeflag -->

<!-- PLAN_META
id: VECTOR_PATH_HITTEST
status: blocked
phases:
  - id: 1
    name: "Path data emission (recompiler)"
    status: complete
  - id: 2
    name: "Fill winding number algorithm (runtime)"
    status: complete
  - id: 3
    name: "Stroke distance testing (runtime)"
    status: complete
  - id: 4
    name: "Morph shape interpolated paths"
    status: complete
dependencies:
  - HIT_TESTING (phases 1-7 complete)
blockers: []
-->

Last updated: 2026-04-04

## Status: 4/4 PHASES COMPLETE — 329/338 (was 325/338)

---

## Current Results

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| movieclip_hittest_shapeflag | 338 | 329/338 (9 diff) | +4 lines from Phase 4 morph implementation |

### Remaining 9 diff lines

| Category | Lines | Status |
|----------|-------|--------|
| Text glyph shapes | 6 (71, 163, 165, 171, 175, 177) | Noto Sans vs Flash font metric differences at curve boundaries |
| Text regression | 1 (167) | Noto Sans glyph outline covers different area than Flash expectation |
| Morph fill boundary | 1 (296) | Fill winding precision at boundary point — morph 41 fill0=1 at (400,300) |
| Drawing API curves | 1 (137) | Deferred — needs DrawingState path integration |

---

## Phase 1: Path Data Emission — COMPLETE

Recompiler emits `float path_data[][3]` alongside `shape_data[]`:
- StyleChange: `{1.0, fill0, fill1}` + `{1.5, line_style, line_width}`
- MoveTo: `{5.0, x, y}`
- LineTo: `{2.0, x, y}`
- CurveTo: `{3.0, ctrl_x, ctrl_y}` + `{4.0, anchor_x, anchor_y}`
- End: `{0.0, 0, 0}`

Per-character path offset/size stored via `ng_record_char_path()`.
Emitted for non-font, non-morph shapes. Font glyphs use per-glyph path data in `glyph_data[]`.

**Commit**: `e3b47145`

---

## Phase 2: Fill Winding Number — COMPLETE

Port of Ruffle's `shape_utils.rs` winding_number_curve with y-monotonic splitting:
- Translate curve to origin (test at y=0)
- Solve quadratic with Citardauq root ordering (t0=ascending, t1=descending)
- Split at y-extremum into monotonic subcurves
- Check ray y against subcurve y-range (not t-range) — avoids precision issues at extrema
- Winding from subcurve direction (+1 upward, -1 downward)

Fill0 reversal: negate forward winding (NOT reverse arguments — reversing shifts endpoints between t=0/t=1, breaking half-open interval).

Path testing is authoritative when path_data available — fills use winding, strokes use distance, triangle fallback skipped.

Per-glyph path testing also implemented: glyph_data extended to 4 values per glyph (tri_offset, tri_size, path_offset, path_size). Font glyph paths emitted from Noto Sans TTF outlines for all glyphs.

**Commits**: `44c59165` (winding), `f7b350ab` (glyph paths)

---

## Phase 3: Stroke Distance Testing — COMPLETE

- `dist_sq_point_to_segment()`: closest-point projection with clamped t
- `dist_sq_point_to_curve()`: perpendicular intersection via cubic polynomial solve (Cardano's formula with depressed cubic, trigonometric solution for 3 real roots)
- `ng_hitTestPathStroke()`: walks path_data, tests distance to each stroke edge against half-width

**Commit**: `aa4c108d`

---

## Phase 4: Morph Interpolated Paths — COMPLETE

### Approach: Interleaved format

Each geometric command stores both start and end coordinates as paired entries:
```
{cmd, start_x, start_y}, {9.0, end_x, end_y}
```

Style entries: STYLE_LINE is followed by `{9.0, 0, end_width}` for morph end line width.
Runtime interpolates per-entry: `x = start_x * (1 - ratio/65535) + end_x * (ratio/65535)`

### Implementation

**Recompiler (SWFRecomp/src/swf.cpp)**:
- `path_recording = !is_font` (enabled for morphs, was `!is_font && !is_morph`)
- `LineStyle::end_width` field captures morph end line width in `parseMorphLineStyles`
- `morph_start_buf` buffers start path commands during edge parsing (instead of direct emission)
- `morph_end_geo_buf` captures raw end-edge geometric commands (MOVE/LINE/CURVE) during end-edge parsing
- `morph_end_widths_buf` captures end line widths for each STYLE_LINE
- After both edge loops, interleaved path data is emitted to `path_data` stream
- `ng_record_morph_path(shape_id, offset, size)` emitted instead of `ng_record_char_path`

**Runtime (SWFModernRuntime/src/libswf/tag_stubs.c)**:
- `ng_morph_paths[MAX_MORPH_PATHS_NG]` stores morph path offset/size per char_id
- `ng_record_morph_path()` + `ng_find_morph_path()` for morph path storage/lookup
- `ng_hitTestMorphPath()`: walks interleaved data, interpolates coordinates, performs combined fill winding + stroke distance test
- Morph hit test section tries path-based test first, falls back to bounds-based

**Result**: 325→329 lines passing (+4). 3 of 4 morph diff lines fixed (292, 294, 304).

### Remaining: Line 296 (fill boundary precision)

Morph 41 at (400, 300): fill winding detects the point as inside fill 1, but expected `false`. The point is at the exact fill boundary. Ruffle uses the same even-odd winding approach, but slight differences in interpolation precision or coordinate rounding cause a different result at this specific boundary point.

**Commits**: (see below)

### Files modified
- `SWFRecomp/include/swf.hpp`: `end_width` field in LineStyle
- `SWFRecomp/src/swf.cpp`: Morph path emission (buffered + interleaved), end line width capture
- `SWFModernRuntime/src/libswf/tag_stubs.c`: Morph path storage, `ng_hitTestMorphPath()`
- `SWFModernRuntime/include/libswf/tag.h`: `ng_record_morph_path` declaration

---

## Drawing API Integration (Deferred)

Line 137 needs DrawingState in `action.c` to record path commands. Separate effort from DefineShape path testing. (Line 117 was fixed previously.)

---

## Implementation History

| Date | Commit | Change | Result |
|------|--------|--------|--------|
| 2026-03-30 | `90b9f96f` | pit() fill rule + stroke non-zero winding | 312→318 |
| 2026-03-31 | `e3b47145` | Phase 1: path_data emission infrastructure | (no change) |
| 2026-03-31 | `44c59165` | Phase 2: y-monotonic curve winding | 318→323 |
| 2026-03-31 | `f7b350ab` | Per-glyph path-based hit testing | 323→324 |
| 2026-03-31 | `aa4c108d` | Phase 3: stroke distance-to-path | 324→325 |
| 2026-04-04 | — | Phase 4: morph interleaved path emission + interpolated hit test | 325→329 |

---

## Files Summary

### Recompiler (SWFRecomp/)
| File | Changes |
|------|---------|
| `include/swf.hpp` | LineStyle::end_width field for morph end line width |
| `src/swf.cpp` | path_data emission, stroke marker (0x80000000), glyph path emission, morph buffered interleaved emission, end line width capture |

### Runtime (SWFModernRuntime/)
| File | Changes |
|------|---------|
| `src/libswf/tag_stubs.c` | pit() fill rule, fill/stroke split winding, winding_number_line/curve (y-monotonic), dist_sq_point_to_segment/curve, ng_hitTestPathFill/Stroke, per-glyph path winding, ng_record_char_path, ng_record_morph_path, ng_hitTestMorphPath |
| `src/libswf/tag.c` | glyph_data 2→4 values per glyph indexing |
| `include/libswf/tag.h` | ng_record_char_path, ng_record_morph_path declarations |
