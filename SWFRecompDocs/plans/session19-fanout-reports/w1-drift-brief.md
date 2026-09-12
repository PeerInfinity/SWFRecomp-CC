# w1-drift: wave-1 diagnosis of upstream drift, new tests, and fresh small targets (both axes)

Read `BRIEFS_COMMON.md` first. This is read-only work with no source edits. Deliverable:
`SWFRecompDocs/plans/session19-fanout-reports/w1-drift-report.md`. Scratch dir: `<scratchpad>/w1-drift/`.

## Your board
**A. Verify the corpus against upstream.** The coordinator's own drift lists were wrong twice in s18,
so this is yours to verify. `~/CC/ruffle` is at upstream `0631814db`; the local tree
`ruffle-tests/tests/swfs/` was synced today without `--clean`. Produce:
- local test dirs with no upstream counterpart (stale residue from old non-clean syncs). LIST them;
  do not delete anything. Say which ones still grade in CI (CI downloads fresh, so a local-only
  dir is invisible there) and which have a `_results` row;
- local `output.ruffle.txt` files that upstream no longer has (s18 pruned 39; one was a live
  `ruffle_matched` trap). List them with the test's current status;
- tests whose `output.txt` / `test.toml` changed upstream since CI's baseline download
  (`git -C ~/CC/ruffle log --since=2026-09-04 --stat -- tests/tests/swfs` is a good start), and
  the Ruffle commit that moved each.

**B. Price the named drift and new tests**. For each one give GO/NO-GO, mechanism, files, LOC, and
pixel-side effect where it has an `[image_comparisons]` block:
- `avm2/geom_transform`: trace 71/74 (fresh output.txt is 75 lines), pixels pass→fail (excess
  8746). Ruffle `45be8d536` "Implement DisplayObject z" changed it.
- `avm2/displayobject_z`: new, 6/38 (fresh 40 lines), plus a new pixel fail.
- `from_avmplus/ecma3/JSON/adhoc`: 33/40, KF, with a new `output.ruffle.txt` from `af88e41a58`.
  Is the reachable target `pass`, or `ruffle_matched`?
- `avm1/bitmapdata_custom_rectangle`: 15/42, KF, RTXT; `352718de29` grew it 34→42.
- on disk but not yet graded: `avm1/bitmapdata_copypixels_self`, `avm2/bitmapdata_copypixels_blend`,
  `avm2/bitmapdata_copypixels_self`. Run them.
- `avm2/bitmapdata_draw_cab_quality`: new pixel fail.
- anything else part A turns up that arrived since the baseline.

`DisplayObject.z` could be a small shared mechanism (geom_transform + displayobject_z, both
axes). If so, scope it as ONE wave-2 slice: what Ruffle stores, how `transform.matrix3D` and
`z` interact, and which of our structs carry it.

Sibling wave-1 agents are w1-avm1-display, w1-avm1-builtins, w1-avm2, w1-loaders, w1-gfx-geometry,
w1-gfx-text-filters and w1-gfx-stage3d. The tests listed above are yours on both axes.
