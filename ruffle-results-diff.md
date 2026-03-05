# Ruffle Test Results Diff

**Previous:** `f9c99c392d9a` (2026-03-05T21:14:01.149533+00:00)
**Current:** `c170d74f701f` (2026-03-05T22:31:12.711282+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 461 | 463 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 74.5% | 74.8% | +0.3% |
| Mismatched lines | 21422 | 21310 | -112 |
|   Decreased | | | -112 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `get_bytes_total` | output_mismatch | 0/4 | 4/4 |
| `gettextextent` | output_mismatch | 31/56 | 56/56 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 286/338 | - |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `define_local_with_paths` | output_mismatch | 22/54 | 51/54 | -29 |
| `global_proto_decls` | output_mismatch | 11/4497 | 13/4497 | -2 |
