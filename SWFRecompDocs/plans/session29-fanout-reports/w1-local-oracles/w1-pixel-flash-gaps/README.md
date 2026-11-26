# w1-pixel-flash-gaps local oracle results (s29 coordinator, 2026-11-26, FP32, new stub)

| request | result |
|---|---|
| 1. `visual/simple_shapes/text_field_mask` LOW | `text_field_mask.low.png` (LNX) == `text_field_mask.win.low.png` (WIN), 0 ch at tol 0. **Golden ≠ Flash: 1189 px (2378 ch) at tol 0, max 255.** ⇒ flash_fixes candidate (platform-stable). |
| 2. `lowq_sample_point` HIGH `--screen` | screen == draw() == s28 `lowq_sample_point.high.png`, 0 px ⇒ Flash HIGH does NOT snap an unfiltered cacheAsBitmap rect: prototype C confirmed. |
| 3. `from_shumway/gradientTransform` | HIGH capture == golden **exactly** (0 px at tol 3); LOW capture vs golden 3 px / 9 ch over tol 3 (max 15); WIN LOW == LNX LOW (0). ⇒ golden is Flash HIGH but the row runs at LOW: flash_fixes candidate → `gradientTransform.low.png`. |
| 4. (lead 4) `visual/drawing_api/fills_and_lines` WIN LOW | vs LNX LOW: 78 884 ch ⇒ WIN ≠ LNX (class c confirmed) ⇒ NO swap (host-dependent). |
