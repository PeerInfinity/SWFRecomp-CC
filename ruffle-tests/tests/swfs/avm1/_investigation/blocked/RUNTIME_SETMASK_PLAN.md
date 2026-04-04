# Runtime setMask() Rendering Plan
<!-- TESTS: mask_reapply, mask_with_drawing, movieclip_setmask -->

<!-- PLAN_META
id: RUNTIME_SETMASK
status: blocked
phases:
  - id: 1
    name: "Implement masked_drawing_render_cb"
    status: complete
  - id: 2
    name: "Handle stencil clear"
    status: complete
  - id: 3
    name: "Extend to tag-placed display objects"
    status: complete
  - id: 4
    name: "Test and debug"
    status: blocked
dependencies:
  - plan: DRAWING_API_RENDERING
    type: complements
    reason: "movieclip_setmask image test needs Drawing API anti-aliasing fix"
blockers:
  - "movieclip_setmask image test blocked on Drawing API line anti-aliasing precision (DRAWING_API_RENDERING plan)"
-->

Last updated: 2026-04-04

## Status: BLOCKED — 2/3 tests PASS, movieclip_setmask image blocked on Drawing API anti-aliasing

### Test Results (2026-04-04)

| Test | Trace | Image | Status |
|------|-------|-------|--------|
| mask_reapply | N/A (empty) | PASS (0 outliers, max diff 1, tolerance 1) | **PASS** |
| mask_with_drawing | N/A (empty) | PASS (0 outliers, max diff 0, tolerance 0) | **PASS** |
| movieclip_setmask | PASS (14/14) | FAIL (3594 outliers, max diff 255, tolerance 0) | **BLOCKED** |

### Masking Infrastructure: COMPLETE

All masking functionality is implemented and working:
- `setMask()` / mask removal / mask re-application
- Stencil write pipeline (mask geometry → stencil buffer)
- Stencil test pipeline (masked content → render where stencil passes)
- `begin_clip_mask` / `end_clip_mask` / `end_clip` functions
- Static clip masks (PlaceObject2.clip_depth)
- Runtime setMask() for both timeline-placed and Drawing API content
- Hit testing respects mask geometry

### Blocker: movieclip_setmask Image Test

The `movieclip_setmask` image failure is **NOT a masking issue**. The test draws colored squares using the Drawing API (`lineStyle(2, 0x000000)`, `beginFill`, `moveTo`, `lineTo`, `endFill`). The image diff shows:
- 3594 outlier pixels at square border positions (rows 9, 110, 119, 220, 229, 330)
- Expected: white pixels at border edges; Actual: black pixels (off-by-one border position)
- Same Drawing API line anti-aliasing issue as DRAWING_API_RENDERING plan

This is blocked until the Drawing API anti-aliasing precision issue is resolved (see `RENDERING_PIPELINE_COMPARISON.md`).

### Problem (Original)

Dynamic masks set via `MovieClip.setMask()` at runtime weren't rendered in headless graphics mode. The mask relationship was tracked on the MovieClip struct (`mask_mc`, `is_mask` fields), and the display list iteration correctly separated masked from unmasked drawings, but the host-level rendering callback wasn't wired up.

### Implementation (Complete)

#### setMask() Implementation (`action.c:47922-48002`)

```c
// mc.setMask(mask)
// Sets mask_mc on this MC, sets is_mask=1 on the mask MC
mc->mask_mc = mask_mc;
mask_mc->is_mask = 1;
```

- Clears previous mask relationship when re-masking
- Resolves mask target by direct object, string path, or property lookup
- Returns boolean (true if applied, false if invalid)

#### MovieClip Mask Fields (`action.h:62-63`)

```c
void* mask_mc;  // MovieClip* that masks this MC, NULL if none
u8 is_mask;     // 1 if this MC is used as a mask (skip normal rendering)
```

#### Display List Iteration Separation (`action.c:17290-17336`)

```c
// Normal rendering: skips masked MCs and mask MCs
actionIterateDrawings() {
    for each mc in child_mc_cache:
        if (mc->is_mask) continue;       // masks rendered separately
        if (mc->mask_mc != NULL) continue; // masked MCs rendered separately
        // ... normal rendering callback ...
}

// Masked rendering: only MCs with active masks
actionIterateMaskedDrawings() {
    for each mc where mc->mask_mc != NULL:
        cb(&masked_info, &mask_info, user_data);
}
```

#### Stencil Buffer Infrastructure (`render_webgpu.c`)

Full stencil-based clipping is configured and working:
- Stencil Write Pipeline (lines 1037-1055): writes stencil value 1 without color output
- Stencil Test Pipeline (lines 1057-1068): renders only where stencil == 1
- `render_webgpu_begin_clip_mask(ctx)` / `render_webgpu_end_clip_mask(ctx)` / `render_webgpu_end_clip(ctx)`
- Depth-Stencil Texture: Depth24PlusStencil8, MSAA 4x

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| setMask() implementation | `action.c` | 47922-48002 |
| mask_mc / is_mask fields | `action.h` | 62-63 |
| Normal drawing iteration | `action.c` | 17290-17313 |
| Masked drawing iteration | `action.c` | 17315-17336 |
| Stencil write pipeline | `render_webgpu.c` | 1037-1055 |
| Stencil test pipeline | `render_webgpu.c` | 1057-1068 |
| begin/end_clip_mask | `render_webgpu.c` | 1714-1735 |
| Depth-stencil texture | `render_webgpu.c` | 868-884 |
