# Interim #6 (`45867407140`, results `945d2df5d`): unlisted LOW band moves graded against Flash 32

These rows got worse against their goldens but still fail, and they are not named in `lowq-corner-rule-report.md`'s
tables. For each one, the interim-#6 CI actual (`ruffle-image-results`) is compared with a Flash 32 LOW capture,
counting channels above the test's tolerance. "before" is the snap-pixel-audit's ours→Flash number at the old model.

| row | golden | ours→FL before | **ours→FL now** | golden→FL | verdict |
|---|---|---:|---:|---:|---|
| `from_shumway/doubleAndRegister` | not Flash | 804 | **630** | 772 | toward Flash (D1 row) |
| `from_shumway/acid/acid-gradient-2` | not Flash | 3 030 | **285** | 3 002 | toward Flash (D1 row, mostly recovered) |
| `regression/avm2_layer_group_alpha` | upstream Ruffle | 12 322 | **11 067** | 13 763 | toward Flash |
| `regression/avm2_layer_group_erase` | upstream Ruffle | 9 786 | **9 032** | 11 579 | toward Flash |
| `visual/drawing_api/fills_and_lines` | Ruffle | 36 424 | **5 704** | 36 155 | toward Flash |
| `from_shumway/acid/acid-color-0` | Ruffle | — | **8 683** | 26 477 | far closer to Flash than the golden (captured here) |
| `visual/fonts/font_lookup_as3` | Ruffle | — | **53 424** | 65 163 | closer to Flash than the golden (captured here) |
| `visual/drawing_api/drawing_order` | Ruffle | 11 850 | 12 784 | 11 831 | **away**: class c, priced in the lowq report §3/§4 (stroke y rule, s29) |
| `visual/simple_shapes/masks{,_equal_clipdepth}` | Ruffle | 4 119 | 4 398 | 4 119 | **away**: class c, priced (w2's numbers) |

The other worsened rows are swapped-golden rows: blend_modes ×14, filters color_matrix, `simple_shapes/layers`,
bevel*/glow*/drop_shadow*/displacement/blur_size_grows. Their new excess is against the FP32 golden and equals the
report's final→FL column, or they are class b with lower distance to Flash. Captures: `*.low.png` in this directory.
