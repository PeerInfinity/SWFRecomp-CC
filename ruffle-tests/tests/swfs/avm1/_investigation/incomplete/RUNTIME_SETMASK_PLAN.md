# Runtime setMask() Rendering Plan
<!-- TESTS: mask_reapply, mask_with_drawing, movieclip_setmask -->

<!-- PLAN_META
id: RUNTIME_SETMASK
status: not_started
phases:
  - id: 1
    name: "Implement masked_drawing_render_cb"
    status: not_started
  - id: 2
    name: "Handle stencil clear"
    status: not_started
  - id: 3
    name: "Extend to tag-placed display objects"
    status: not_started
  - id: 4
    name: "Test and debug"
    status: not_started
dependencies:
  - plan: DRAWING_API_RENDERING
    type: complements
    reason: "mask_with_drawing and movieclip_setmask tests need both plans"
blockers: []
-->

Last updated: 2026-03-27

## Status: NOT STARTED — Tier 3/7 (stencil infrastructure exists, needs host-level integration)

### Problem

Dynamic masks set via `MovieClip.setMask()` at runtime aren't rendered in headless graphics mode. The mask relationship is tracked on the MovieClip struct (`mask_mc`, `is_mask` fields), and the display list iteration correctly separates masked from unmasked drawings. However, the host-level rendering callback that draws the mask to stencil buffer and then draws the masked content hasn't been fully implemented.

Note: **Static clip masks** from `PlaceObject2.clip_depth` are a separate mechanism and may already work (the renderer has `begin_clip_mask`/`end_clip_mask` stencil functions).

### Affected Image Tests

| Test | Tolerance | Notes |
|------|-----------|-------|
| mask_reapply | 1 | Multiple masks + runtime setMask |
| mask_with_drawing | 6 | Drawing API shapes + masking (also needs Drawing API rendering) |
| movieclip_setmask | 0 | Drawing API + setMask |

### Current Infrastructure

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

The iteration functions already separate masked from unmasked content:

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
        // Provide both masked content and mask geometry to callback
        cb(&masked_info, &mask_info, user_data);
}
```

#### Stencil Buffer Infrastructure (`render_webgpu.c`)

Full stencil-based clipping is already configured:

**Stencil Write Pipeline** (lines 1037-1055):
- Writes stencil value 1 without color output
- `stencilFront.compare = Always`, `passOp = Replace`
- Used for clip mask shapes

**Stencil Test Pipeline** (lines 1057-1068):
- Renders only where stencil == 1
- `stencilFront.compare = Equal`
- Normal color output

**Functions** (lines 1714-1735):
```c
void render_webgpu_begin_clip_mask(ctx);  // Switch to stencil write pipeline
void render_webgpu_end_clip_mask(ctx);    // Switch to stencil test pipeline
void render_webgpu_end_clip(ctx);         // Switch back to normal pipeline
```

**Depth-Stencil Texture** (lines 868-884):
- Format: Depth24PlusStencil8
- MSAA 4x
- Same dimensions as framebuffer

#### Hit Testing Integration (`action.c:47281-47283`)

setMask masking is already respected in hit testing — point must hit both the MC and its mask geometry.

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
| Masked drawing callback (tag.c) | `tag.c` | ~2333-2334 |

### What's Missing

#### Gap 1: Host-Level Masked Drawing Callback

The `masked_drawing_render_cb` in `tag.c` needs to:
1. Clear stencil buffer (or relevant region)
2. Switch to stencil write pipeline
3. Render mask MC's geometry (write to stencil)
4. Switch to stencil test pipeline
5. Render masked MC's content (only passes where stencil == 1)
6. Switch back to normal pipeline

```c
static void masked_drawing_render_cb(const DrawingMCInfo* masked,
                                      const DrawingMCInfo* mask,
                                      void* user_data) {
    // 1. Begin clip mask (stencil write)
    renderer_begin_clip_mask(context);

    // 2. Draw mask geometry (writes to stencil, no color)
    for (int i = 0; i < mask->path_count; i++)
        render_drawing_path(&mask->paths[i]);

    // 3. End clip mask (switch to stencil test)
    renderer_end_clip_mask(context);

    // 4. Draw masked content (only where stencil passes)
    for (int i = 0; i < masked->path_count; i++)
        render_drawing_path(&masked->paths[i]);

    // 5. End clip (back to normal pipeline)
    renderer_end_clip(context);
}
```

#### Gap 2: Stencil Clear Between Masks

If multiple MCs have different masks, the stencil buffer needs to be cleared between each masked group. Options:
- Full stencil clear between groups (expensive but simple)
- Use different stencil reference values per mask group
- Clear only the relevant stencil region

#### Gap 3: Mask MC Shape Rendering

The mask MC's shapes (not just Drawing API paths) need to be renderable to the stencil buffer. This includes:
- Static shapes from the mask MC's children
- Drawing API shapes on the mask MC
- Text field shapes on the mask MC

#### Gap 4: Non-Drawing-API Masked Content

`actionIterateMaskedDrawings()` currently only handles Drawing API content. If a timeline-placed sprite has `setMask()` applied, its static shapes also need to render through the stencil test pipeline. This requires extending the display list walk to detect `mask_mc` on tag-placed display objects too.

### Implementation Plan

#### Step 1: Implement masked_drawing_render_cb

Write the callback that renders mask geometry to stencil, then renders masked content through stencil test. Use the existing `begin_clip_mask`/`end_clip_mask`/`end_clip` functions.

#### Step 2: Handle Stencil Clear

Add stencil clear before each masked group. Simplest approach: use `wgpuRenderPassEncoderSetStencilReference(pass, 0)` + draw full-screen quad to stencil write pipeline, then set reference back to 1 for the actual mask.

Alternative: use the load operation on the render pass to clear stencil to 0 at frame start, and increment stencil ref per mask group.

#### Step 3: Extend to Tag-Placed Display Objects

In the display list render walk (tag.c), check each display object's associated MC for `mask_mc != NULL`. If set:
1. Skip normal rendering
2. After the normal pass, do a masked pass: stencil-write the mask MC's children, then stencil-test-render this object's children

#### Step 4: Test

```bash
python3 ruffle-tests/verify_output.py --test=mask_reapply --headless --diff --verbose
python3 ruffle-tests/verify_output.py --test=movieclip_setmask --headless --diff --verbose
```

`mask_with_drawing` also needs the Drawing API rendering to work first.

### Design Considerations

1. **Nested masks**: If a masked MC contains children that are also masked, the stencil logic needs to handle nesting. Could use incrementing stencil reference values (depth 1 = ref 1, depth 2 = ref 2, etc.).

2. **Mask removal**: `setMask(null)` clears the mask. Need to ensure the mask MC becomes visible again (`is_mask = 0`) and the masked MC renders normally.

3. **Mask shape vs mask bounds**: Flash uses the mask's actual shape for clipping, not its bounding box. The stencil approach correctly handles this since it renders the mask's geometry.

4. **Performance**: Stencil rendering requires pipeline switches. For a small number of masks (typical in tests), this is fine.

### Dependencies

- `mask_with_drawing` and `movieclip_setmask` also need DRAWING_API_RENDERING_PLAN.md
- `mask_reapply` may need runtime transform updates for mask repositioning

### Estimated Complexity

Medium. The stencil infrastructure exists. Main work is:
1. Masked drawing callback (~40 lines)
2. Stencil clear logic (~20 lines)
3. Tag display list extension (~50 lines)
4. Testing and debugging (~3 hours)
