# Ruffle Test Results Diff

**Previous:** `797d44c3533e` (2026-07-28T02:06:13.184132+00:00)
**Current:** `1617724ebe03` (2026-07-28T04:05:52.938102+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 871 | 875 | +4 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 71.3% | 71.7% | +0.4% |
| Mismatched lines | 45696 | 45662 | -34 |
|   Decreased | | | -43 |
|   Increased | | | +9 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `cross_api_version_call_older` | output_mismatch | 0/12 | 12/12 |
| `loader_duplicate_coerce` | output_mismatch | 1/3 | 3/3 |
| `loader_duplicate_coerce_new_domain` | output_mismatch | 1/4 | 4/4 |
| `loader_loadbytes_url` | output_mismatch | 3/12 | 12/12 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `cross_api_version_call_newer` | output_mismatch | 0/12 | 11/12 | -11 |
| `instantiate_root_character` | output_mismatch | 0/4 | 3/4 | -3 |
| `loader_child_getdefinition` | output_mismatch | 2/5 | 4/5 | -2 |
| `loader_duplicate_class` | output_mismatch | 2/48 | 3/48 | -1 |
| `localconnection` | output_mismatch | 76/890 | 67/890 | +9 |
