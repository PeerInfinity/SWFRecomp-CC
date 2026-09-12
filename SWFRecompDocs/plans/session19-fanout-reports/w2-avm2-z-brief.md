# w2-avm2-z: `DisplayObject.z` (slice Z from `w1-drift-report.md`)

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-drift-report.md` slice Z. Worktree
agent: nothing commits, you deliver a patch. Branch from current master (it moves as sibling
patches land; say which commit you used).

## Scope (+2 effective, ~30 LOC, `avm2_display.c` only)
Ruffle implemented `DisplayObject.z` in `45be8d536` (2026-09-09) and rewrote two tests around it.
Store `tz` as a dyn-prop in the style of the existing `__pp*` slots.

- `avm2/displayobject_z`: 6/38 → pass (this test is new upstream).
- `avm2/geom_transform`: 71/74 → pass.

## Explicitly out of scope
The PIXEL side of both tests. Matching those needs a real perspective pipeline — Ruffle carries
`tz` through the transform stack plus a `projection × view` global matrix, fov 55°, with near-plane
culling. That is renderer-wide and is NOT this slice. `avm2/geom_transform`'s image comparison is
expected to keep failing, and that is not a regression — it began failing from this same upstream
test rewrite, before any change of ours.

## Required checks
- Headlines both ways: `avm2/displayobject_z`, `avm2/geom_transform`.
- `z` sits on DisplayObject, so sweep the transform/geometry families: `avm2/*transform*`,
  `avm2/matrix3d*`, `avm2/displayobject_*`, plus the `regression` suite.
- Confirm you did NOT move the pixel verdict of either headline (run them with
  `--mode=graphics --images` and report the excess before and after).

Sibling note: **w2-loaders** and **w2-gfx-geometry** have both already landed changes in
`avm2_display.c` on master — branch fresh, and self-localize.
