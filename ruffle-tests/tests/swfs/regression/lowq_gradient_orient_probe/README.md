# lowq_gradient_orient_probe (s28 lowq-corner-rule)

Where Flash Player's quality=LOW rasteriser evaluates gradient paint, by gradient type, orientation and spread.
71 cells of 40x40 on a 320x360 white stage (AVM1 SWF 8, static DefineShape3/4 rects; generator
`create_test_swf.py`, cell list + matrices in `cells.json`). Golden `output.expected.png` = Flash Player 32 LNX
`draw()` capture at quality LOW, tick 1 (`tools/flash-oracle/run_image.py --quality low`; two captures
byte-identical).

Rows: 0 smooth 32-px linear ramps at 0/30/45/60/90/135/180/315 deg; 1 hard-step ramps at the same angles;
2 mirrored / anisotropic / long ramps and rotated / scaled / mirrored placements; 3 fractional shape offsets;
4 radial and focal controls plus 3 more step angles; 5 step ramps at 10..290 deg; 6-7 reflect / repeat spreads and
skewed matrices (including `visual/simple_shapes/gradients/gradients`' reflect matrix); 8 that matrix at its real
stage translation.

The rule it pins (fit with `fit_paint_point.py output.expected.png`; full write-up
`SWFRecompDocs/plans/session28-fanout-reports/lowq-corner-rule-report.md`):

- paint is evaluated at the pixel's TOP-LEFT corner, every orientation, mirror, skew and placement;
- linear ramps read entry floor(256 t), radial and focal ones round(256 t);
- reflect / repeat spreads use the gradient matrix translation scaled by 255/256;
- the object's device-pixel translation is rounded half-down (ceil(T - 0.5)) for the paint.

Known residual (ours vs this golden): exact-integer ties on non-dyadic slopes (Flash's fixed-point error takes
them one entry down), radial centre pixels (Flash's sqrt is coarse near r = 0), and the trailing edge of the two
4.5..35.5 rects, which Flash includes.
