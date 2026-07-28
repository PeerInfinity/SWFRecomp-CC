# Graphics vs Trace Mode Differences

Trace: 160/229 passing | Graphics: 166/229 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (6 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `as3-interfaces` | Output Mismatch | 1/6 lines match |
| 2 | `as3-loader/LoaderLoadBytesTest2` | Output Mismatch | 0/3 lines match |
| 3 | `as3-loader/bug1093712/loader` | Output Mismatch | 0/1 lines match |
| 4 | `flash_net_URLRequest` | Output Mismatch | 0/6 lines match |
| 5 | `flash_net_classes` | Ruffle Matched | 18/22 lines match |
| 6 | `image-loading` | Output Mismatch | 0/4 lines match |
