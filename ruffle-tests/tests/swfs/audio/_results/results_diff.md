# Ruffle Test Results Diff

**Previous:** `f55511379655` (2026-10-18T08:49:49.731708+00:00)
**Current:** `344c85a166c3` (2026-10-25T08:41:41.576786+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 3 | 0 | -3 |
| Total | 5 | 5 | 0 |
| Pass rate | 60.0% | 0.0% | -60.0% |
| Mismatched lines | 19 | 0 | -19 |
|   Decreased | | | -19 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `g711_event_alaw` | compile_fail | 0/0 | - |
| `g711_event_mulaw` | compile_fail | 0/0 | - |
| `stream_incomplete_loop` | compile_fail | 0/0 | - |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `aac` | output_mismatch | compile_fail | 3/18 | - |
| `g711` | output_mismatch | compile_fail | 2/6 | - |
