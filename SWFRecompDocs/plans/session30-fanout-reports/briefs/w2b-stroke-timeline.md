**The timeline-shape twin of the HIGH 0.01 px curve flattening (M): `swf.cpp` `addCurvedEdgeLevien`.**

Base: master `a18a0e033` or newer (w2-stroke-geometry-land LANDED: AVM2 + AVM1 drawing-API flatten at HIGH).
Read `w2-stroke-geometry-land-report.md` §2.2 and its `timeline-knob-probe-not-for-landing.patch` +
`timeline_knob_compare.txt`.

The knob probe moved 30/155 HIGH canary comparisons: 24 toward the golden, 1 away, 5 mixed. It was HELD for three
reasons, each of which you must close:
(a) **one FP32-golden row moved away**: `regression/avm1_stroke_pixel_snap_matrix` 11 730 → 11 856. Find why (is
  this row's geometry better served by the coarser tolerance, or does its snap rule depend on chord ends?) and fix it
  or scope the rule;
(b) **the canary covers only 117 of 238 non-LOW image rows**: run every non-LOW image row in the corpus, before/after,
  with `--recompile` (cloud box, `-P` as BRIEFS_COMMON allows). Name every move;
(c) **the recompiler does not know a test's quality**: LOW must keep the current tolerance. Plumb the quality into
  the emitted shape data, or emit both tolerances and select at runtime by `MSAA_SAMPLES` (cheaper; mind the size).
  Choose by measurement (emitted-C size, build time).
Also re-check the morph-shape and device-font-glyph flatten paths (`swf.cpp` ~3265 and the morph stepping): same
rule or not, by FP32 (`w1-local-oracles/w1-stroke-geometry/` captures).
Ledger: pixel axis by name; trace axis must be unchanged (hit tests read the recompiled paths: run the 35-row
hitTest family). Recompiler change: rebuild + `--recompile` on every leg.
