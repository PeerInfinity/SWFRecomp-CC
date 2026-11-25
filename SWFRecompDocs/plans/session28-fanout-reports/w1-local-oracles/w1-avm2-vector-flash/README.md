# w1-avm2-vector-flash local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX)

`lowq_sample_point.test.swf`: built locally from the slot's `lowq_sample_point/Test.as` with
`mxmlc -target-player=11.1 -swf-version=13 -compress=false -omit-trace-statements=false -static-link-runtime-shared-libraries=true`.

| capture | file | note |
|---|---|---|
| draw(), quality low, tick 1 | `lowq_sample_point.low.png` | |
| draw(), quality high, tick 1 | `lowq_sample_point.high.png` | |
| screen, quality low | `lowq_sample_point.low.s.screen.png` | == draw() (0 / 0): the low draw() capture is the real screen |
| `avm2/graphics_draw_triangles` draw(), quality low | `graphics_draw_triangles.low.png` | optional request 2 (second fit of the LOW sample point on triangles) |
