# Ruffle Test Results Diff

**Previous:** `7e3a3a01481a` (2026-07-11T13:16:27.773564+00:00)
**Current:** `9a21db62588e` (2026-07-11T13:35:09.837402+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 353 | 354 | +1 |
| Total | 1199 | 1200 | +1 |
| Pass rate | 29.4% | 29.5% | +0.1% |
| Mismatched lines | 105103 | 105203 | +100 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `negative_volume_panned` | runtime_error | 0/0 | 0/0 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmapdata_constructor_from_timeline` | runtime_error | output_mismatch | 0/1 | 0/1 |
| `goto_nested_construct_sibling` | output_mismatch | runtime_error | 1/18 | 1/18 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `error_throwerror` | output_mismatch | 3/103 |
