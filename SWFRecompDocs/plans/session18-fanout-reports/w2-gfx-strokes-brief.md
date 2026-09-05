# w2-gfx-strokes — wave 2: round joins/caps in the RUNTIME stroke builders + drawing-API twip truncation (+4 pixel flips priced)

Read `BRIEFS_COMMON.md` (incl. wave-2 rules; graphics canary rules) and `SIBLING_FILE_MAP.md`,
then the diagnosis of record: `w1-gfx-smalls-report.md` §2 (mechanism A, incl. "where present
but does not flip") and §3 B. Isolated worktree; no commits. Graphics work: local Dawn at
`~/CC/dawn-install`; `MSAA_SAMPLES` never literal 4.

## Scope
**A. Round joins + round caps** in the two runtime stroke builders — AVM1 `action.c`
`drawing_emit_stroke_join` (~:29516) / `drawingBuildStroke` (~:29578) and AVM2 `avm2_display.c`
`gfx_stroke_join` (~:8176) / `gfx_build_stroke` (~:8209) — both are miter/bevel + butt today;
Ruffle defaults to round for AS3 `Graphics`, AVM1 `lineStyle` and classic LINESTYLE1 (the
recompiler already emits round for DefineShape: `swf.cpp:11389/11447` — reuse its arithmetic).
Honour explicit `joints`/`caps` args where the API passes them. Targets: `avm2/graphics_bitmap_fill`
64 → ≤60 outliers (all 28 residual px are rect corners) and `visual/drawing_api/fills_and_lines`
104 → 0.
**B. Twip truncation** of runtime drawing-API coordinates: Ruffle's `Twips::from_pixels` is
`(px*20.0) as i32` (truncate toward zero); quantize drawing-API points (moveTo/lineTo/curveTo/
drawCircle/drawRect… control + anchor points) the same way. Targets: `avm2/mouse_pick_dobj_mask`
and `avm2/mouse_pick_non_interactive_dobj_mask` (2 px each). Check whether AVM1's drawing API
shares the path.

## Verification (pixel A/B; local Dawn is byte-deterministic)
Headline: the 4 targets, `--mode=graphics --images --image-out-dir <your scratch>` before/after
(local outlier counts are advisory vs CI lavapipe, but the DIRECTION and the "identical on both
sides" verdicts are valid). Canary: `ruffle-tests/render_canary.py` capture/compare over
`render_canary_tests.txt` (`--timeout 5400`) — md5 identity except for tests that use runtime
strokes/drawing APIs, which you must list with their before/after outliers. Extra graded canaries
(`--mode=graphics --images`): `avm2/graphics_*` passing tests (all — ~15), `avm1/movieclip_*draw*`/
`avm1/drawing*` passing, `visual/drawing_api/*` (all), `from_shumway/acid/acid-shapes*`,
`avm2/displayobject_getbounds_shape` (stroke bounds!), and trace-mode `--diff` on the same set
(hit-test tests read the geometry: `avm2/mouse_pick_*`, `avm1/*hittest*` — byte-identical trace).
`regression` suite: all render fixtures. `-P 2`, compile timeout 2400, `--recompile` on first use.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-strokes.patch` + `w2-gfx-strokes-report.md`
(NEW files first; per-comparison before/after outliers; canary md5 ledger; trace canary ledger;
refutations; unclaimed leads incl. the LINESTYLE2 join/cap parse-and-discard and the ±π wrap
guard the report names). Copy to the main tree if allowed. Runtime-only → copying
`SWFRecomp/build` is valid.
