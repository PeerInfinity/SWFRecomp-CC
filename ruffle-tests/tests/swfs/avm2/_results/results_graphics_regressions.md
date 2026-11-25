# Graphics vs Trace Mode Differences

Trace: 1298/1346 passing | Graphics: 1304/1347 passing

## Graphics Regressions (1 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `mouse_pick_avm1_root` | Output Mismatch | 1/2 lines match |

## Graphics Improvements (6 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `audio_computespectrum` | Output Mismatch | 0/118 lines match |
| 2 | `int_toexponential` | Ruffle Matched | 1139/1215 lines match |
| 3 | `json_parse_numbers` | Ruffle Matched | 127/131 lines match |
| 4 | `number_to_string` | Ruffle Matched | 249/353 lines match |
| 5 | `number_tostring` | Output Mismatch | 882/1050 lines match |
| 6 | `uint_toexponential` | Ruffle Matched | 1115/1215 lines match |
