# Graphics vs Trace Mode Differences

Trace: 1109/1227 passing | Graphics: 1143/1240 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (24 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `accessibilityimplementation` | Output Mismatch | 0/18 lines match |
| 2 | `all_classes/accessibility/swf10` | Output Mismatch | 5/88 lines match |
| 3 | `all_classes/accessibility/swf30` | Output Mismatch | 5/88 lines match |
| 4 | `all_classes/accessibility/swf9` | Output Mismatch | 5/73 lines match |
| 5 | `all_classes/display3D/swf12` | Output Mismatch | 1/321 lines match |
| 6 | `all_classes/display3D/swf13` | Output Mismatch | 3/326 lines match |
| 7 | `all_classes/display3D/swf30` | Output Mismatch | 12/412 lines match |
| 8 | `all_classes/errors/swf10` | Output Mismatch | 6/140 lines match |
| 9 | `all_classes/errors/swf30` | Output Mismatch | 6/140 lines match |
| 10 | `all_classes/errors/swf9` | Output Mismatch | 1/126 lines match |
| 11 | `all_classes/security/swf12` | Output Mismatch | 0/19 lines match |
| 12 | `all_classes/security/swf13` | Output Mismatch | 0/53 lines match |
| 13 | `all_classes/security/swf30` | Output Mismatch | 0/53 lines match |
| 14 | `all_classes/xml/swf30` | Output Mismatch | 9/116 lines match |
| 15 | `all_classes/xml/swf9` | Output Mismatch | 9/116 lines match |
| 16 | `describe_type_metadata` | Output Mismatch | 5/125 lines match |
| 17 | `describe_type_native` | Output Mismatch | 1/23 lines match |
| 18 | `int_toprecision` | Ruffle Matched | 684/1125 lines match |
| 19 | `netstream_flv_date` | Output Mismatch | 2/4 lines match |
| 20 | `number_convert_edge_cases` | Output Mismatch | 148/180 lines match |
| 21 | `sound_constructor_with_args` | Output Mismatch | 2/6 lines match |
| 22 | `sound_rootless` | Output Mismatch | 5/7 lines match |
| 23 | `sub_super_same_field` | Output Mismatch | 6/12 lines match |
| 24 | `uint_toprecision` | Ruffle Matched | 692/1125 lines match |
