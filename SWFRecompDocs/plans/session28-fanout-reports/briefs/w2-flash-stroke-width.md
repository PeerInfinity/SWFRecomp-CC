**Flash's device-space isotropic stroke-width model (P2 of w1-acid-flash) (M).**

Inputs: `w1-acid-flash-report.md` §1 P2 (on master), `w1-acid-flash-prototype-stroke-only.patch` (`swf.hpp`
`LineStyle`, `swf.cpp` LINESTYLE2 flags into `stroke_run_data[][3]` bits 30/31, `render_webgpu.c` `hairline_restage`),
and the coordinator's Flash 32 captures in `w1-local-oracles/w1-acid-flash/` (README): `acid-stroke-0` at LOW (==
golden) and at HIGH (≠: check the widths), `blur_scales_with_screen` (Flash stage 200×200 vs the 400×400 golden).
Rule (from the w1): Flash scales a stroke isotropically in device space by a scalar from v = M·(1,1): NORMAL →
|v|/√2, NoVScale → |v.x|, NoHScale → |v.y|, both flags → 1, then a 1-device-px minimum.

Task:
1. Confirm the rule is quality-independent from the HIGH capture (stroke widths per cell), and grade
   `blur_scales_with_screen` ours-before/after vs the Flash capture (scale to match). If it's Flash-ward, it's a priced
   RvF loss; if not, refine.
2. Complete the model: device-space round joins/caps (the w1's 115×50 vs 111×49 bulge), and extend it to morph strokes,
   glyph strokes and AVM1/AVM2 Drawing-API strokes (each with a Flash-golden row or a FLASH request + built SWF).
3. Gate with `--recompile`: s22's 63-row stroke set + render canary + `regression`. Ledger: `acid-stroke-0`,
   `visual/simple_shapes/strokes/scale` (flash_fixes golden), `acid-scale` (priced Flash-ward loss: draft its RvF entry).
4. The local session `n-stroke-snap` is implementing Flash thin-stroke PIXEL SNAPPING in the same area
   (`render_webgpu.c` stroke pipeline / `hairline_restage` possibly); read `SWFRecompDocs/plans/n-stroke-snap-report.md`
   if it exists and keep your hunks separable (wrapper functions, a clearly bounded block in `hairline_restage`); the
   coordinator merges.
5. Oracle caveat (found 2026-11-25 by the local `flash-oracle-harness` session): until its fix, PINNED direct-mode
   captures of AVM1 rows ignored `test.toml` quality=low (they rendered HIGH). `draw()`-wrapper captures were not
   affected. Re-check any s27 "direct-pinned" root capture you rely on at quality low.
