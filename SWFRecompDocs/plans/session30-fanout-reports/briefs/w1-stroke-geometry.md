**Pixels: stroke geometry — `acid-shapes` curved thick strokes, `acid-stroke-0`, the AVM2 seam-join twin, translucent
union slivers (M; diagnosis + measured prototypes).**

1. **`from_shumway/acid/acid-shapes` (HIGH, 1 tick; golden == FP32 exactly, LNX == WIN).** Pre-launch README §3 +
   `pre-launch-oracles/acid-shapes-diffmap-t32.png`, `acid-shapes-residue-band.png`: by tolerance 3/16/32/64/128/200 ours
   → FP32 is 112 728 / 61 385 / 25 688 / 5 575 / 175 / 0 vs budgets 113 000 / 61 300 / 25 600 / 5 600 / 180 / 0, so it
   fails only t16 (+85) and t32 (+88), both EDGE-ONLY AA. The t128 residue is 146 px, almost all on the thick curved
   "squiggle" strokes' OUTER edges (y ≈ 260–420), where FP32 paints stroke colour and we leave background (e.g.
   (360,267) ours 0,0,0 vs FP32 47,133,138). **Fix the curved-stroke edge geometry first** (thick quadratic-curve
   offsetting / flattening tolerance / join on curves: find which, in the recompiler stroke builders `swf.cpp` or lyon, or
   `render_webgpu.c`). Then grade with s29 w1-aa-sizing's harness (`session29-fanout-reports/w1-aa-sizing/scan_run.py`,
   `-DSSAA_PROBE -DSSAA_VSNAP` leg; read its report): under the faithful HIGH AA rule the row was 210/180 at t128, so
   the geometry fix is what decides whether the AA NO-GO's reopen criterion (register §1b) is now met. Report that
   verdict explicitly: would AA + your geometry flip the row, and what does AA still cost elsewhere (w1-aa-sizing: −7
   Flash-golden −4 regression passes)?
2. **`from_shumway/acid/acid-stroke-0`** (LOW, 3413 after the LOW stroke raster; golden FP32-provenance): what owns the
   rest (TSNAP priced +369 in s29; caps/joins at LOW?).
3. **AVM2 twin of the w3 seam-join gate**: `avm2_display.c` `gfx_build_stroke` / `gfx_stroke_seam_caps_on` still
   emits seam caps for wide translucent strokes (s29 `w3-interim3-residuals-report.md` §"Not changed"); it needs the
   on-screen scale at build time. Find a corpus row that shows it (or build a fixture + FLASH request); price it.
4. **Translucent-union slivers in `drawingUnionTris`** (libtess2 non-zero): a vertex weld before `tessAddContour`
   (w3 report §New leads). Price it on the render canary (`ruffle-tests/render_canary.py`, md5 identity outside your
   ledger) and on the translucent stroke rows.
Deliver `w1-stroke-geometry-prototype.patch` + per-row channel tables vs FP32 (prove CI fidelity on one row first).
Siblings: w1-lowq-residues (LOW rules in `render_webgpu.c`, LOW glyphs). The N ladder is PARKED; do not tune for N.
Name every function you touch.
