# Vector-Path Hit Testing Plan
<!-- TESTS: movieclip_hittest_shapeflag -->

<!-- PLAN_META
id: VECTOR_PATH_HITTEST
status: incomplete
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
    status: blocked
dependencies:
  - HIT_TESTING (phases 1-7 complete)
blockers:
  - blocker: 4
    reason: "Morph path style state ordering: initial MOVE captures line_style=0 before first StyleChange"
-->

Last updated: 2026-03-31

## Status: 3/4 PHASES COMPLETE — 325/338 (was 312/338)

---

## Current Results

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| movieclip_hittest_shapeflag | 338 | 325/338 (13 diff) | +13 lines from start of plan |

### Remaining 13 diff lines

| Category | Lines | Status |
|----------|-------|--------|
| Text glyph shapes | 6 (71, 163, 165, 171, 175, 177) | Noto Sans vs Flash font metric differences at curve boundaries |
| Text regression | 1 (167) | Noto Sans glyph outline covers different area than Flash expectation |
| Morph stroke-only | 4 (292, 294, 296, 304) | **BLOCKED** — Phase 4 style state ordering issue |
| Drawing API curves | 2 (117, 137) | Deferred — needs DrawingState path integration |

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

## Phase 4: Morph Interpolated Paths — BLOCKED

### Approach: Interleaved format

Each geometric command stores both start and end coordinates as paired entries:
```
{cmd, start_x, start_y}, {0, end_x, end_y}
```

Style entries also paired (end entry is placeholder). Runtime interpolates per-entry:
```c
x = start_x * (1 - ratio/65535) + end_x * (ratio/65535)
```

This guarantees 1:1 alignment by construction — no separate start/end streams to synchronize.

### Implementation status

Recompiler side (partially implemented, not committed):
- Morph command tracking via `MCM` struct during start edge parsing
- End-edge curve capture via `MEC` struct
- Post-processing: morph_end_positions[morph_idx] provides end coords for LINE/MOVE; mend_curves provides end coords for CURVE
- Interleaved emission to path_data after both edge loops complete

Runtime side (partially implemented, not committed):
- `ng_record_morph_path(char_id, offset, size)` stores interleaved path offset
- Morph hit test walks interleaved pairs, interpolates coords, runs fill winding + stroke distance

### Blocker: Style state ordering

**Problem**: The initial MOVE command for stroke-only morph shapes captures `line_style=0` because it's recorded before the first StyleChange sets the line style.

**Code flow**:
1. Edge loop starts with `last_line_style = 0`
2. First iteration may be an edge (not a StyleChange) for some morph shapes
3. Initial MOVE is recorded at the first edge encounter with `last_line_style = 0`
4. First StyleChange (with actual line_style) comes later
5. All stroke distance tests fail because `line_width = 0`

**Effect**: Morph 27 loses 2 correct lines (189, 195). Morph 41 loses all correct lines (300-338).

**Fix needed**: Defer the initial MOVE recording until the first StyleChange with non-zero line_style has been processed. Options:
1. Two-pass: first pass records StyleChanges, second pass records edges
2. Record MOVE lazily: emit MOVE at the first edge AFTER the first StyleChange
3. Post-process: update the first MOVE's style info after the edge loop completes

Option 3 is simplest: after the edge loop, scan `mcmds` and patch the first MOVE's fill/line fields with the actual style values from the first StyleChange.

### Files to modify
- `SWFRecomp/src/swf.cpp`: Morph command tracking + interleaved emission + MOVE style patching
- `SWFModernRuntime/src/libswf/tag_stubs.c`: Morph path storage + interpolated fill/stroke test
- `SWFModernRuntime/include/libswf/tag.h`: `ng_record_morph_path` declaration

---

## Drawing API Integration (Deferred)

Lines 117, 137 need DrawingState in `action.c` to record path commands. Separate effort from DefineShape path testing.

---

## Implementation History

| Date | Commit | Change | Result |
|------|--------|--------|--------|
| 2026-03-30 | `90b9f96f` | pit() fill rule + stroke non-zero winding | 312→318 |
| 2026-03-31 | `e3b47145` | Phase 1: path_data emission infrastructure | (no change) |
| 2026-03-31 | `44c59165` | Phase 2: y-monotonic curve winding | 318→323 |
| 2026-03-31 | `f7b350ab` | Per-glyph path-based hit testing | 323→324 |
| 2026-03-31 | `aa4c108d` | Phase 3: stroke distance-to-path | 324→325 |

---

## Files Summary

### Recompiler (SWFRecomp/)
| File | Changes |
|------|---------|
| `src/swf.cpp` | path_data emission, stroke marker (0x80000000), glyph path emission, morph deferred emission (not yet committed) |

### Runtime (SWFModernRuntime/)
| File | Changes |
|------|---------|
| `src/libswf/tag_stubs.c` | pit() fill rule, fill/stroke split winding, winding_number_line/curve (y-monotonic), dist_sq_point_to_segment/curve, ng_hitTestPathFill/Stroke, per-glyph path winding, ng_record_char_path |
| `src/libswf/tag.c` | glyph_data 2→4 values per glyph indexing |
| `include/libswf/tag.h` | ng_record_char_path declaration |
