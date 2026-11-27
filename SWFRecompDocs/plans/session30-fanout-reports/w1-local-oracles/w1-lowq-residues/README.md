# w1-lowq-residues LOCAL ORACLE REQUEST 1 (s30 coordinator, 2026-11-27)

`df2/` = the slot's `lowq_glyph_probe/test.swf` (DefineFont2), `df3/` = `test_df3.swf` (DefineFont3); `test.toml`
quality low, 1 tick. Captures: `fp32.lnx.low.png` (wrapper draw(), `--quality low`), `fp32.lnx.low.screen.png`,
`fp32.win.low.png`.
- Pixel compare (RGB, t0): LNX vs WIN 27 (df2) / 24 (df3) channels; draw vs screen 45 / 24. Near-identical, not exact:
  grade with a small tolerance or against the LNX draw() capture.
- **Coordinator read (df2 vs the slot's PNGs):** FP32 text sits **+2 px right** of all four of the slot's images
  (best whole-px alignment dx=+2, dy=0). Aligned, pixels differing by >2 (grey): ours_s30_master_plus_tie_eps 13 429,
  pred_fine16_halfup 14 048, pred_chord_rint 14 851, pred_chord_halfup 14 947. So on this probe the CURRENT GPU render
  is closest, and the chord model is NOT better, contrary to the fit on the corpus rows. Find the +2 px first (text
  field gutter / probe layout in the predictor?), then re-score per row and per x phase.
