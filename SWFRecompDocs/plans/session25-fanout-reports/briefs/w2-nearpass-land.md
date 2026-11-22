**Land the pixel near-pass prototype (+6 priced flips) cleanly, and push hunk B to a flip.** From `w1-pixel-nearpass` (report + `w1-pixel-nearpass-prototype.patch` on master). All verdicts were CI-grade (fidelity proven).

Hunks (independent; land all five, ranked cheapest first):
- **D** rotated `BitmapData.draw` coverage (`avm2_bitmap.c`): +1 `avm2/bitmapdata_draw_rotation`.
- **A** focal clamp moved into the gradient shader (`render_webgpu.c` + `action.c` `applyGradientFillToMC`/`applyLineGradientStyleToMC`): +1 `visual/drawing_api/gradient_focal_point`.
- **C** Ruffle `Matrix * Matrix` translation rounding in `tag.c` `compose_children`: +1 `from_shumway/acid/acid-gc`.
- **S** lyon stroke join model (`SWFRecomp/src/swf.cpp` `SWF::drawLinesLyon`): +3 `doubleAndRegister`, `acid-scale`, `acid-gradient-2`. **Drop the `SWFRECOMP_OLD_STROKE` env hook.** Needs `--recompile`.
- **B** AVM1 Drawing-API gradient matrix as Fixed16 a–d + truncated twip tx/ty (`action.c` `drawingBuildGradientBoxMatrix`/`drawingBuildGradientAbcdMatrix`): `avm1/movieclip_begin_gradient_fill` 132 → 6 at tol 6. **Try to finish it to a flip** (§2.5 of the w1 report), with a measured answer either way.

**Master has moved since the w1 base (`ca14fe02`).** `tag.c` got `ee9ea8738` (layer groups) and `0f35012bd` (runtime Drawing-API z-order / transforms); `action.c` got `5b50cd4a0` and `0f35012bd` (stroke joins, `drawingBuildStroke`). Rebase every hunk onto origin/master, re-measure every headline row on the rebased code, and re-run the full render canary (106+ tests, now including the s25 appends). The zero-headroom rows (`bevel_*`, `glow_with_alpha_strength` 18/18, `fills_and_lines`, `layer_alpha`/`layer_erase` max == tol) must stay passing. Append `from_shumway/acid/acid-scale` (quality=low curved stroke, tol 0) to the canary at EOF.

Siblings: `w2-dynclip-cxform` and `w2-avm1-filters` also touch `tag.c` (`compose_children`'s dynamic-clip arm, the cxform helpers). Keep hunk C to its one block after `hit_test_mat4_multiply(composed, …)`, and name it in the report. EXPECTED LEDGER: px +6 (+1 if B flips), trace 0.
