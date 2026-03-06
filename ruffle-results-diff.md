# Ruffle Test Results Diff

**Previous:** `378a0f9dd092` (2026-03-06T17:44:15.712416+00:00)
**Current:** `7d19cf5299a5` (2026-03-06T18:24:27.933442+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 480 | 480 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 77.5% | 77.5% | 0% |
| Mismatched lines | 20196 | 20054 | -142 |
|   Decreased | | | -195 |
|   Increased | | | +53 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `native_subclasses` | output_mismatch | 9/191 | 191/191 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `interface_implements_op` | output_mismatch | 47/47 | 46/47 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | compile_fail | output_mismatch | - | 286/338 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `coerce_to_object_monkeypatch` | output_mismatch | 64/129 | 77/129 | -13 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 6/9 | 6/9 | 0 |
