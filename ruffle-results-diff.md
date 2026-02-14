# Ruffle Test Results Diff

**Previous:** `2a39d1c32901` (2026-02-14T01:29:43.731335+00:00)
**Current:** `25cbff52640b` (2026-02-14T01:57:09.550297+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 149 | 152 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 24.1% | 24.6% | +0.5% |
| Mismatched lines | 57210 | 57204 | -6 |
|   Decreased | | | -6 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `target_path` | output_mismatch | 11/14 | 14/14 |
| `uncaught_exception` | runtime_error | 0/1 | 1/1 |
| `uncaught_exception_bubbled` | runtime_error | 0/1 | 1/1 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_object_children` | output_mismatch | 67/83 | 68/83 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
