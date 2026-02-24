# Ruffle Test Results Diff

**Previous:** `c410d8301de2` (2026-02-24T20:46:59.328601+00:00)
**Current:** `80a4e85274a7` (2026-02-24T21:29:53.188144+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 342 | 342 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 55.3% | 55.3% | 0% |
| Mismatched lines | 33459 | 33529 | +70 |
|   Decreased | | | -3 |
|   Increased | | | +73 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loadmovie_replace_root` | output_mismatch | 2/5 | 5/5 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `loadmovie_flashvars` | output_mismatch | 4/4 | 3/4 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | compile_fail | output_mismatch | - | 266/338 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
