# Graphics vs Trace Mode Differences

Trace: 638/717 passing | Graphics: 646/717 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (8 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `geturl_opcode_target_normalize` | Output Mismatch | 0/45 lines match |
| 2 | `geturl_target_normalize` | Output Mismatch | 4/89 lines match |
| 3 | `localconnection` | Output Mismatch | 433/579 lines match |
| 4 | `xml_socket` | Output Mismatch | 1/8 lines match |
| 5 | `xml_socket_close_in_handler` | Output Mismatch | 0/6 lines match |
| 6 | `xml_socket_connect_null` | Output Mismatch | 1/12 lines match |
| 7 | `xml_socket_on_data` | Output Mismatch | 0/7 lines match |
| 8 | `xml_socket_segmented` | Output Mismatch | 0/29 lines match |
