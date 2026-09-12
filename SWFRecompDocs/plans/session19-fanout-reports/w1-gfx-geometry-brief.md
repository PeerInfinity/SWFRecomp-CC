# w1-gfx-geometry: wave-1 pixel diagnosis of curves, strokes, fills and bitmaps

Read `BRIEFS_COMMON.md` and `SWFRecompDocs/plans/graphics-fanout-playbook.md` (§1-7 and §17) first.
This is read-only work with no source edits. Deliverable:
`SWFRecompDocs/plans/session19-fanout-reports/w1-gfx-geometry-report.md`. Scratch dir: `<scratchpad>/w1-gfx-geometry/`.

Local graphics renders go through `--mode=graphics --images` on single tests. Local Dawn is not
CI's lavapipe, so use the CI PNGs under `<scratchpad>/image-results/` for absolute verdicts, and
local renders only for "does X move the pixels" A/Bs. If you need an A/B that edits source,
prototype in a throwaway `git worktree` under your scratch dir, never the main tree.

## Your board (playbook §17 leads; re-verify each against the fresh board)
- **`blend_modes` ×12 residual.** The claim is integer-twip truncation of flattened curve vertices
  in `addCurvedEdgeLevien` (`SWFRecomp::Vertex` is s32), and that it is the completion mechanism
  for the whole family, sign-dependent. It is a recompiler change, so it needs a full-corpus
  recompiler A/B plan. NOTE that `recompiler_ab_sweep.sh` is broken three ways (§19.3 of the arc
  doc), and the recompiler has 7 SWFs of non-determinism (uninitialised words in `draws.c`).
  Price both, and say whether the A/B tool must be fixed first.
- **`avm2/graphics_gradients` 299 → 469**, a side effect of s18's round joins on gradient strokes.
- **LINESTYLE2 join/cap styles** are parsed and discarded by the recompiler, and join fans are a
  fixed 5 midpoints. Which comparisons would honouring them flip?
- **AVM2 `lineStyle` alpha** is truncated like the solid-fill bug s18 fixed (open).
- **`bitmapbuttons` (618 042)**: four `0x43` clipped-bitmap fill characters render nothing.
- **`Bitmap.pixelSnapping`** is unimplemented (`avm2/bitmap_pixelsnapping`, 3 831, row_banded).
- `avm2/bitmapdata_draw` (row_banded), `from_shumway/acid/acid-bitmapData-copyPixels` (53 760),
  `acid-shapes` (41 577), `acid-stroke-0` (KF), `avm2/graphics_simple_shapes` (230),
  `from_shumway/acid/acid-morph` (1 711), `avm2/displayobject_getbounds_shape` (content_displaced),
  `from_gnash/misc-ming.all/place_object_test`.
- `morph_test1` ×6 is the "- xtrace enabled" status-bar TEXT, not morph geometry (s18). Confirm
  it, and hand it to text if so.

Deliver a ranked GO list with priced flips per comparison and the canary gaps each slice needs
(s18 listed: no `drawPath` member, no nested-Bitmap `BitmapData.draw`, and others).

Siblings: w1-gfx-text-filters (text, fonts, filters, colour transforms, blend shaders),
w1-gfx-stage3d (Stage3D/AGAL, video), w1-drift (owns `geom_transform`, `displayobject_z`,
`bitmapdata_draw_cab_quality`, and the new copypixels tests on both axes), trace agents.
