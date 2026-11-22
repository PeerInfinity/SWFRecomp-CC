# Graphics vs Trace Mode Differences

Trace: 734/780 passing | Graphics: 742/780 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (8 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `amf0_array_matrix` | Output Mismatch | 49/50 lines match |
| 2 | `lazy_prototype_shared` | Output Mismatch | 6/8 lines match |
| 3 | `load_vars` | Output Mismatch | 29/35 lines match |
| 4 | `localconnection_serialize_sparse_array_getters` | Output Mismatch | 25/26 lines match |
| 5 | `localconnection_xml_unavailable` | Output Mismatch | 9/29 lines match |
| 6 | `stylesheet_load` | Output Mismatch | 1/49 lines match |
| 7 | `text_format_get_text_extent_own` | Output Mismatch | 10/19 lines match |
| 8 | `video_prototype_lazy` | Output Mismatch | 20/21 lines match |
