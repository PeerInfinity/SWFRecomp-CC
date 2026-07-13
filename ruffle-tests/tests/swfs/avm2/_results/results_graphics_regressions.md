# Graphics vs Trace Mode Differences

Trace: 824/1204 passing | Graphics: 819/1204 passing

## Graphics Regressions (5 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `loaderinfo_properties` | Output Mismatch | 1/18 lines match |
| 2 | `loaderinfo_root` | Output Mismatch | 3/10 lines match |
| 3 | `loaderinfo_root_allows` | Output Mismatch | 0/2 lines match |
| 4 | `sandbox_type_local_file` | Output Mismatch | 0/1 lines match |
| 5 | `urlrequest` | Output Mismatch | 0/18 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
