# w2-flash-stroke-width local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX draw() wrapper)

| request | file | result |
|---|---|---|
| 1 `avm1_drawing_stroke_scale` HIGH | `avm1_drawing_stroke_scale.high.png` | vs `ours.after.png` 12 940 px (>2) / vs `ours.before.png` 11 176 px: **the Drawing-API half moves AWAY from Flash** → not landed; handed to local `n-drawapi-stroke-snap` |
| 2 same, LOW | `avm1_drawing_stroke_scale.low.png` | captured |
| 3 `from_shumway/acid/acid-scale` | `acid-scale.png` | vs the corpus golden 5 620 px: golden ≠ Flash (flash_fixes candidate; the w2 after render is 2 299 px off Flash) |
