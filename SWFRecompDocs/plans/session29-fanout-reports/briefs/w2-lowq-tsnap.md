**Flash LOW translation snap (TSNAP): fit its scope and the 45° stroke width from the FP32 tie probe, then land if the gate holds (M).**

Read `session29-fanout-reports/w1-lowq-next-report.md` (§2–§4) and `w1-lowq-next-prototype.patch`. FP32 results:
`w1-local-oracles/w1-lowq-next/README.md`. The probe capture `tie_probe.lnx.png` (WIN == LNX, screen == draw) is the golden.
1. **Scope (row 3, nesting):** TSNAP is exact on rows 0–2 but leaves 234 px on row 3. Fit world vs per-level vs
   root-only snapping on the row-3 cells (`cells.json`) and pick the rule that makes row 3 exact. Then re-run the s28
   gate that killed the world-snap prototype (`cache_as_bitmap/scroll_rect` Flash golden must stay pass; the 14
   `blend_modes/*`, `simple_shapes/layers`, `opaque_background`, `cache_as_bitmap/drawing_api` and 11 `filters/*` rows
   must not move away from their FP32 goldens). If no scope passes the gate, deliver the HOLD with numbers.
2. **45° stroke width at LOW (rows 4–5):** fit Flash's LOW width/coverage for static 45° strokes (widths 1–10), the
   drawing_order 3-px rect, the acid-stroke-0 matrices and the Drawing-API `lineStyle(5)` line against the probe.
   Use `drawing_order.high.png` vs the s28 LOW capture to say whether the rect-band inset is LOW-only (else it belongs to
   the N ladder's HIGH snap rule: report, don't implement). Prototype only what fits all cells.
3. Add `regression/lowq_tsnap_tie_probe` with the FP32 golden (tolerance 0 + measured `max_outliers`) if we land.
4. Gates (non-negotiable): the 114-test Flash-golden LOW gate (`w1-lowq-next-fixtures/ledger/flash_golden_low_gate.txt`)
   0 losses; HIGH render canary md5-identical; by-name ledger of every LOW move with golden provenance; kill switches.
Siblings: w2-pixel-gaps-land (`tf_glyph_quarter_snap` LOW arm, `render_webgpu_stroke_snap` drawing-API centres,
cacheAsBitmap LOW snap — coordinate: TSNAP must not double-snap cacheAsBitmap entries), w2-text-coverage-land
(HIGH text), local n-seam-caps (stroke builders). Leave text out of TSNAP (report lead). Name every function you touch.
