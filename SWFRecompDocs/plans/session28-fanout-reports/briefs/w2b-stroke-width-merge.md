**Rebase the timeline half of w2-flash-stroke-width onto n-stroke-snap and land-ready it (M).**

Inputs: `w2-flash-stroke-width-report.md` + `w2-flash-stroke-width-timeline-only.patch` (on master; the slot's
branch is `fanout/w2-flash-stroke-width`), and `SWFRecompDocs/plans/n-stroke-snap-report.md` (code `09b2c9130`, on
master): n-stroke-snap rebuilt `hairline_restage` for Flash thin-stroke pixel SNAPPING and added a separate weak table
`stroke_run_flags[]` (bit0 pixelHinting, bit1 noH, bit2 noV) + `stroke_snap_data`, keeping width scale |M·(1,1)|/√2.
The timeline-only patch was built BEFORE that commit and no longer applies (`render_webgpu.c` `hairline_restage`,
`swf.hpp` `LineStyle`, `swf.cpp` LINESTYLE2 parse + `stroke_run_data` emit).

Task:
1. Port the width model (NoVScale |v.x|, NoHScale |v.y|, both-flags 1, 1-device-px min) and the device-space
   round-join/cap offset (`hairline_flash_offset`) onto master. Use n-stroke-snap's `stroke_run_flags[]` for noH/noV
   (do NOT also pack bits 30/31 into `stroke_run_data`); the snap must apply AFTER your device offset. Kill switches
   stay (`SWF_STROKE_SNAP=0`).
2. Re-measure (with `--recompile`) the w2 ledger on top of the snap: `acid-stroke-0`, `visual/simple_shapes/strokes/scale`
   (flash_fixes golden), `acid-scale` (its golden is NOT Flash: coordinator capture
   `w1-local-oracles/w2-flash-stroke-width/acid-scale.png`; give ours vs that capture → flash_fixes candidate),
   `blur_scales_with_screen` (Flash-ward loss; RvF draft in the w2 report §7), n-stroke-snap's Flash-golden ledger
   (button3, avm1_imports_avm1, `regression/avm1_stroke_pixel_snap{,_matrix}`) — none may move away from Flash.
3. Gate: s22's stroke set + the w2's 274-test A/B list + render canary (md5 identity outside the ledger).
4. The Drawing-API half is NOT yours (Flash capture shows it moves away; the local `n-drawapi-stroke-snap` owns that path).
