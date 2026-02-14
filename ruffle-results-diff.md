# Ruffle Test Results Diff

**Previous:** `bceacde4cc39` (2026-02-14T06:42:49.553796+00:00)
**Current:** `cfa68f7f7604` (2026-02-14T07:48:18.018513+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 164 | 166 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 26.5% | 26.8% | +0.3% |
| Mismatched lines | 53294 | 53028 | -266 |
|   Decreased | | | -267 |
|   Increased | | | +1 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_password` | output_mismatch | 0/5 | 5/5 |
| `textfield_variable` | output_mismatch | 63/81 | 81/81 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_hittest_shapeflag` | output_mismatch | 48/338 | 180/338 | -132 |
| `edittext_antialiastype` | output_mismatch | 164/296 | 275/296 | -111 |
| `transform` | output_mismatch | 47/70 | 48/70 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `path_string` | segfault | 45/322 | 44/322 | +1 |
