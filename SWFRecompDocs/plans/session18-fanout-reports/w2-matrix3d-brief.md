# w2-matrix3d — wave 2 implementation: Matrix3D + Vector3D trace flips (+5 priced)

Read `BRIEFS_COMMON.md` (all sections incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the
diagnosis of record: `w1-trace-new-report.md` §2 (Matrix3D cluster #1–#4) and §3 (#5
vector3d_near_equals). You work in an ISOLATED WORKTREE (already created for you); edits only
there; no commits to master; deliver a patch + report.

## Scope (all suite `avm2`)
1. `matrix3d_append_prepend_scale` 0/86 → pass: `appendScale`/`prependScale` throw `#2183` on a zero
   argument (the 38 value lines already match; only the 8 exception blocks are missing).
2. `matrix3d_copy_from` 15/19, `matrix3d_copy_to_matrix3d` 15/19 → pass: null-arg guard via the
   existing `s3d_arg_object_non_null` helper.
3. `matrix3d_interpolate` 0/21 → pass: port `Matrix3D.interpolate` / `interpolateTo` (~95 LOC) per
   the report's algorithm (from Ruffle `core/src/avm2/globals/flash/geom/Matrix3D.as` / rs — check
   `~/CC/ruffle`).
4. `vector3d_near_equals` 67/80 → pass: the Flash bug is half-replicated — add the
   `this.w = toCompare.w` assignment; update
   `ruffle-tests/tests/swfs/avm1/_investigation/FLASH_BUGS_REPLICATED.md` with the entry.
Rider (report §13): `matrix3d_append_rotation` is `ruffle_matched` 22/23 and inside slice 1's
blast radius — run it before AND after; it must not regress; if your change moves it to `pass`,
say so.

Files: `SWFModernRuntime/src/avm2/avm2_stage3d.c` (all Matrix3D work), ONE line in
`avm2_display.c` (Vector3D region). Sibling w2-avm2-new-smalls edits `avm2_display.c` in the
MovieClip and flash.ui regions — do not touch those.

## Verification (state per-test before/after in the report)
Headline: the 5 tests above + `matrix3d_append_rotation`. Canaries (already passing, same code):
every `avm2/matrix3d_*`, `avm2/vector3d_*`, `avm2/perspective_projection_*`, `avm2/utils3d*`
test (list them with `ls ruffle-tests/tests/swfs/avm2 | grep -E 'matrix3d|vector3d|utils3d|perspective'`)
and `regression` suite tests mentioning Matrix3D/Vector3D (grep). Copy test dirs into your
worktree's canonical paths, `--recompile` on first use, `-P 2` max, compile timeout 2400.
Run at least one canary in `--mode=graphics` too (CI mode).

Deliverables in `SWFRecompDocs/plans/session18-fanout-reports/`: `w2-matrix3d.patch`
(`git diff` from your worktree, incl. the doc edit) and `w2-matrix3d-report.md` (new files at the
top; per-test ledger; refutations of the wave-1 pricing; new unclaimed leads). Copy both to the
main tree path as well if the guard allows.
