# Graphics vs Trace Mode Differences

Trace: 160/229 passing | Graphics: 163/229 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (3 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `flash_net_URLRequest` | Output Mismatch | 0/6 lines match |
| 2 | `flash_net_classes` | Ruffle Matched | 18/22 lines match |
| 3 | `image-loading` | Output Mismatch | 0/4 lines match |
