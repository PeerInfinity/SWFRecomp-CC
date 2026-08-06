# Graphics vs Trace Mode Differences

Trace: 1084/1225 passing | Graphics: 1088/1226 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (6 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `constructsuper_null` | Output Mismatch | 0/2 lines match |
| 2 | `cross_api_version_call_newer` | Output Mismatch | 11/12 lines match |
| 3 | `doabc_and_symbolclass_script_init_goto` | Output Mismatch | 1/8 lines match |
| 4 | `doabc_and_symbolclass_script_init_normal` | Output Mismatch | 1/6 lines match |
| 5 | `graphic_linkage` | Output Mismatch | 7/9 lines match |
| 6 | `system_exit` | Output Mismatch | 0/3 lines match |
