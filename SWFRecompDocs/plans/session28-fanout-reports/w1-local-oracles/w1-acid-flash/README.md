# w1-acid-flash local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX, draw() wrapper at the test's quality)

| request | file | result vs the corpus golden |
|---|---|---|
| 1 `acid-big` tick 300 (low) | `acid-big.t300.png` | 0 outliers at tol 50, max 49: **golden = Flash (in tol)**. P1 failing it 43/20 must be graded ours-vs-this-capture |
| 2 `visual/filters/blur_scales_with_screen` tick 1 | `visual_filters_blur_scales_with_screen.png` + `.s.screen.png` (== draw()) | Flash stage is 200×200, the golden 400×400 (the test scales the stage/window; compare after a 2× scale or crop) |
| 3 `drop_shadow`, `glow`, `bevel`, `bevel_inner`, `acid-blend` | `visual_filters_*.png`, `from_shumway_acid_acid-blend.png` | captured for the P1-moved-row grading (s27 marked most filter rows untestable: check sizes before trusting) |
| 4 `acid-stroke-0` low | `acid-stroke-0.low.png` | == golden exactly (0 / 0) |
| 4 `acid-stroke-0` HIGH | `acid-stroke-0.high.png` | 29 553 outliers vs the (LOW) golden: Flash HIGH renders it differently — compare stroke WIDTHS between the two captures to tell whether the isotropic width rule is quality-independent |
