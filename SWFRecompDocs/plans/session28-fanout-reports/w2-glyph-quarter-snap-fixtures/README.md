# s28 w2-glyph-quarter-snap FLASH-request fixtures (not landed; see ../w2-glyph-quarter-snap-report.md, LOCAL ORACLE REQUESTS)

| dir | request | build (from the repo root) |
|---|---|---|
| `avm1_edittext_glyph_snap_matrix/` | F2 | `python3 SWFRecompDocs/plans/session28-fanout-reports/w2-glyph-quarter-snap-fixtures/avm1_edittext_glyph_snap_matrix/create_test_swf.py` |
| `avm2_edittext_glyph_snap_matrix/` | F2 (AVM2) | `python3 ruffle-tests/tests/swfs/regression/avm2_edittext_placed_cxform/create_test_swf.py $PWD/SWFRecompDocs/plans/session28-fanout-reports/w2-glyph-quarter-snap-fixtures/avm1_edittext_glyph_snap_matrix $PWD/SWFRecompDocs/plans/session28-fanout-reports/w2-glyph-quarter-snap-fixtures/avm2_edittext_glyph_snap_matrix/test.swf` |
| `avm2_edittext_rotated_borders/` | F1 | `python3 ruffle-tests/tests/swfs/regression/avm2_edittext_placed_cxform/create_test_swf.py avm1_edittext_rotated_borders $PWD/SWFRecompDocs/plans/session28-fanout-reports/w2-glyph-quarter-snap-fixtures/avm2_edittext_rotated_borders/test.swf` |

The AVM2 twins are the AVM1 SWF with FileAttributes' AS3 bit and a minimal DoABC (the `avm2_edittext_placed_cxform`
recipe), so the same display list reaches the AVM2 timeline. `ours-after.png` = our graphics render with the patch.
