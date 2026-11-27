**Land HIGH curve flattening (acid-shapes fail → pass), extend it to the timeline/AVM1 flatteners, and fit the
remaining convex-side stroke bias against new FP32 probes (M).** Source: `session30-fanout-reports/w1-stroke-geometry-report.md`
+ `w1-stroke-geometry-prototype.patch` (+ `w1-stroke-geometry/` scripts).

1. **Land the prototype** (`avm2_display.c`: `gfx_curve_tol_scale`, `gfx_flatten_cmds` 0.01 px at HIGH only, LOW
   unchanged; kill switch `SWF_AVM2_CURVE_FINE=0`). Ledger: `from_shumway/acid/acid-shapes` fail → PASS; the HIGH
   Flash-golden rows toward Flash; `displayobject_hittestpoint_boundary` +4 priced. Run the **render canary**
   (`ruffle-tests/render_canary.py`, md5 identity outside the ledger; the w1 slot did not run it) and the suites the w1
   slot did not download (from_gnash, timeline, text, swf, misc). Measure the chord-count cost (frame time on the
   heaviest HIGH drawing-API row, in-process timer, not frame-rate A/B).
2. **Timeline + AVM1 twins at HIGH** (w1 §5/leads): `swf.cpp` `addCurvedEdgeLevien` (`LEVIEN_TOL_TWIPS` = 2 tw) and the
   AVM1 drawing-API flattener (`action.c` `curve_flatten_init` call, ~`:35438`). Price each on the canary + every HIGH
   image row with curves (HIGH only, LOW stays). Land only the ones whose ledger is Flash-ward with 0 Flash-golden losses;
   recompiler change → rebuild + `--recompile`; that is CI-wide, so the ledger must name every moved row.
3. **The residual convex-only stroke deficit** (~0.11–0.18 px at 1:1 after the prototype, w1 §1.2/§5). FP32 HIGH captures
   now exist (`session30-fanout-reports/w1-local-oracles/w1-stroke-geometry/README.md`, WIN == LNX): the acid-shapes
   squiggles at widths {4, 16} × scales {1, 4, 16} × translation {0, .3}. Decide whether the excess is a fixed device-px
   bias or geometry-proportional, and fit `gfx_build_stroke`'s convex offset if it is a clean rule. Add the probes as
   `regression/` image fixtures with the FP32 PNG as golden (budget = our measured outliers after your change, so they
   guard the rule; say so in the regression README).
4. **AVM2 seam twin at HIGH** (`translucent_round/` capture: translucent wide drawRect / drawCircle / drawRoundRect /
   drawEllipse): compare ours vs FP32 with and without a `gfx_build_stroke` width gate; land the gate only if Flash-ward.
Siblings: w1-lowq-residues (LOW rules; you stay HIGH-only), w2-native-* (AVM1 `action.c` native tables, not the
drawing API). Name every function you touch.
