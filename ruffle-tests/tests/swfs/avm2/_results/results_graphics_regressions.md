# Graphics vs Trace Mode Differences

Trace: 1109/1227 passing | Graphics: 1155/1243 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (36 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `accessibilityimplementation` | Output Mismatch | 0/18 lines match |
| 2 | `all_classes/accessibility/swf10` | Output Mismatch | 5/88 lines match |
| 3 | `all_classes/accessibility/swf30` | Output Mismatch | 5/88 lines match |
| 4 | `all_classes/accessibility/swf9` | Output Mismatch | 5/73 lines match |
| 5 | `all_classes/display/swf10` | Output Mismatch | 12/2569 lines match |
| 6 | `all_classes/display/swf11` | Output Mismatch | 15/2593 lines match |
| 7 | `all_classes/display/swf12` | Output Mismatch | 15/2593 lines match |
| 8 | `all_classes/display/swf13` | Output Mismatch | 12/2671 lines match |
| 9 | `all_classes/display/swf30` | Output Mismatch | 7/2936 lines match |
| 10 | `all_classes/display/swf9` | Output Mismatch | 7/1959 lines match |
| 11 | `all_classes/display3D/swf12` | Output Mismatch | 1/321 lines match |
| 12 | `all_classes/display3D/swf13` | Output Mismatch | 3/326 lines match |
| 13 | `all_classes/display3D/swf30` | Output Mismatch | 12/412 lines match |
| 14 | `all_classes/errors/swf10` | Output Mismatch | 6/140 lines match |
| 15 | `all_classes/errors/swf30` | Output Mismatch | 6/140 lines match |
| 16 | `all_classes/errors/swf9` | Output Mismatch | 1/126 lines match |
| 17 | `all_classes/security/swf12` | Output Mismatch | 0/19 lines match |
| 18 | `all_classes/security/swf13` | Output Mismatch | 0/53 lines match |
| 19 | `all_classes/security/swf30` | Output Mismatch | 0/53 lines match |
| 20 | `all_classes/xml/swf30` | Output Mismatch | 9/116 lines match |
| 21 | `all_classes/xml/swf9` | Output Mismatch | 9/116 lines match |
| 22 | `bitmapdata_draw_alpha_erase` | Output Mismatch | 6/8 lines match |
| 23 | `delayed_symbolclass` | Output Mismatch | 20/28 lines match |
| 24 | `describe_type_metadata` | Output Mismatch | 5/125 lines match |
| 25 | `describe_type_native` | Output Mismatch | 1/23 lines match |
| 26 | `edittext_tag_indent` | Output Mismatch | 38/50 lines match |
| 27 | `geom_transform` | Output Mismatch | 21/74 lines match |
| 28 | `int_toprecision` | Ruffle Matched | 684/1125 lines match |
| 29 | `localconnection` | Output Mismatch | 589/890 lines match |
| 30 | `matrix` | Output Mismatch | 282/338 lines match |
| 31 | `netstream_flv_date` | Output Mismatch | 2/4 lines match |
| 32 | `number_convert_edge_cases` | Output Mismatch | 148/180 lines match |
| 33 | `sound_constructor_with_args` | Output Mismatch | 2/6 lines match |
| 34 | `sound_rootless` | Output Mismatch | 5/7 lines match |
| 35 | `sub_super_same_field` | Output Mismatch | 6/12 lines match |
| 36 | `uint_toprecision` | Ruffle Matched | 692/1125 lines match |
