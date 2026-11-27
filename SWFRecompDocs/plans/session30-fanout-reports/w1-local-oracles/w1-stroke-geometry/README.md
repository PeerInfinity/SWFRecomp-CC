# w1-stroke-geometry LOCAL ORACLE REQUESTS (s30 coordinator, 2026-11-27; FP32 HIGH, wrapper draw(), normal blend)

Built with mxmlc (`-target-player=11.1 -omit-trace-statements=false -static-link-runtime-shared-libraries`); each dir
holds `Test.as`, `test.swf`, `test.toml` (1 tick), `flash_trace.txt` (cell placements), `fp32.{lnx,win}.high.png`.
**WIN == LNX byte for byte on every capture.**

1. Curved-stroke scale probe (request 1), split so ×16 fits on stage:
   - `curve_scale_s1s4/` (900×700): widths {4,16} × scales {1,4} × the two acid-shapes squiggles × translation {0, .3}.
   - `curve_scale_s16_w{4,16}_k{0,1}/` (800×800/900): one squiggle at ×16, integer translation.
   Colour 0x49D0D7 on black.
2. `translucent_round/` (300×200, white): `lineStyle(10, 0xFF0000, .5)` drawRect + drawCircle, `lineStyle(10, 0x0000FF,
   .5)` drawRoundRect, `lineStyle(20, 0x00AA00, .5)` drawEllipse (request 2: is the AVM2 seam twin visible at HIGH?).
