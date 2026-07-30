# Graphics vs Trace Mode Differences

Trace: 929/1221 passing | Graphics: 932/1221 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `netconnection_send_remote` | Output Mismatch | 2/50 lines match |
| 2 | `netconnection_serialize_arrays` | Output Mismatch | 1/6 lines match |
| 3 | `urlstream_basic` | Output Mismatch | 0/5 lines match |
