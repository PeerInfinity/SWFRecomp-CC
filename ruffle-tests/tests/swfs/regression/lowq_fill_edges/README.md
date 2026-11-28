# lowq_fill_edges (s28 w2-lowq-sample-point)

20 filled 16x10 px rects (DefineShape, timeline, no stroke) at x/y + 0..19 twips, rendered at quality=low.
`test.swf` is `SWFRecomp-CC-history:SWFRecompDocs/plans/n-stroke-snap-captures/fill_edges/gen.py` output (that dir's `probe.py` helpers); the golden
`output.expected.png` is that dir's `flash_low.png` (Flash Player 32 LNX, coordinator capture, quality LOW).

Pins the Flash LOW axis-aligned fill rule: an edge at fractional offset e covers the pixel iff e <= x + 0.5
(pixel-centre sampling, an exact .5 tie included), in x AND y.
