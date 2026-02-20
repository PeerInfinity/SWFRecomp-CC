# Ruffle Test Results Diff

**Previous:** `0ef9a5195e56` (2026-02-20T17:28:25.116258+00:00)
**Current:** `d1fa478f0551` (2026-02-20T17:34:58.147738+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 231 | 231 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 37.3% | 37.3% | 0% |
| Mismatched lines | 39853 | 39845 | -8 |
|   Decreased | | | -8 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `target_path` | segfault | output_mismatch | 3/14 | 11/14 |

## Line Count Changed (11)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `asnew` | output_mismatch | 10/34 | 10/34 | 0 |
| `coerce_to_object_monkeypatch` | output_mismatch | 9/129 | 9/129 | 0 |
| `coerce_to_primitive_resolve` | output_mismatch | 7/17 | 7/17 | 0 |
| `instanceof_coercions` | output_mismatch | 13/88 | 13/88 | 0 |
| `math_swf6` | output_mismatch | 522/530 | 522/530 | 0 |
| `math_swf7` | output_mismatch | 522/530 | 522/530 | 0 |
| `math_swf8` | output_mismatch | 522/530 | 522/530 | 0 |
| `native_objects_swf6` | segfault | 0/84 | 0/84 | 0 |
| `native_objects_swf7` | segfault | 0/84 | 0/84 | 0 |
| `native_objects_swf8` | segfault | 0/84 | 0/84 | 0 |
| `super_edge_cases` | output_mismatch | 7/39 | 7/39 | 0 |
