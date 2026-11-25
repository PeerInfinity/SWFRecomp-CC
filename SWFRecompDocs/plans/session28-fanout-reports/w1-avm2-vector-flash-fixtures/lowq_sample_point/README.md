# lowq_sample_point (s28 w1-avm2-vector-flash) — FLASH image request fixture

No SWF is shipped: the cloud box has no AS3 compiler. Build locally with the Flex SDK the oracle uses, e.g.
`mxmlc -static-link-runtime-shared-libraries -omit-trace-statements=false -output test.swf Test.as`.

Capture (`tools/flash-oracle/run_image.py`, wrapper/draw mode; the document class does not touch `stage`):
1. `--quality low --ticks 1` → `output.low.png`
2. `--quality high --ticks 1` → `output.high.png`
3. optionally `--screen` at low, to confirm draw() == screen for the scrollRect/cacheAsBitmap cells.

What the capture settles (see the report §2):
- row 0: the LOW coverage sample point, measured at (x+0.5, y) on drawPath; is it (x+0.5, y) for every fill, or
  only for the Drawing API?
- row 1: the LOW stroke rule (width rounding and offset); the sprite_with_frames border and the graphics_gradients
  strokes need it.
- row 2: the gradient paint point, measured at (x, y+0.5) from a horizontal ramp. The vertical ramp pins y.
- row 3: bitmap texel choice at x.5, cacheAsBitmap snap at LOW vs HIGH, and scrollRect clip edges at .5.
