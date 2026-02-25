# Ruffle Test Results Diff

**Previous:** `cf619be6dc4a` (2026-02-25T03:39:58.161087+00:00)
**Current:** `70d9bc1d0396` (2026-02-25T05:32:38.934887+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 351 | 347 | -4 |
| Total | 619 | 619 | 0 |
| Pass rate | 56.7% | 56.1% | -0.6% |
| Mismatched lines | 33351 | 32952 | -399 |
|   Decreased | | | -417 |
|   Increased | | | +18 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as2_super_and_this_v6` | output_mismatch | 7/97 | 97/97 |
| `as2_super_and_this_v8` | output_mismatch | 4/85 | 85/85 |
| `as2_super_via_manual_prototype` | output_mismatch | 11/40 | 40/40 |
| `extends_chain` | output_mismatch | 12/134 | 134/134 |

## Newly Failing (8)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `as_set_prop_flags_version` | output_mismatch | 31/31 | 24/31 |
| `as_set_prop_flags_version_swf5` | output_mismatch | 1/1 | 0/1 |
| `as_set_prop_flags_version_swf6` | output_mismatch | 1/1 | 0/1 |
| `as_set_prop_flags_version_swf7` | output_mismatch | 1/1 | 0/1 |
| `as_set_prop_flags_version_swf8` | output_mismatch | 1/1 | 0/1 |
| `as_set_prop_flags_version_swf9` | output_mismatch | 1/1 | 0/1 |
| `define_function2_preload` | output_mismatch | 13/13 | 12/13 |
| `function_suppress_and_preload` | output_mismatch | 28/28 | 23/28 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 266/338 | - |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `super_edge_cases` | output_mismatch | 7/39 | 28/39 | -21 |
| `global_instance_decls` | output_mismatch | 1/758 | 3/758 | -2 |
