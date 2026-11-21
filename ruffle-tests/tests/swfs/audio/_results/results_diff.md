# Ruffle Test Results Diff

**Previous:** `344c85a166c3` (2026-11-15T08:31:27.885877+00:00)
**Current:** `08709f65842a` (2026-11-21T17:00:08.544342+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 3 | +3 |
| Total | 5 | 5 | 0 |
| Pass rate | 0.0% | 60.0% | +60.0% |
| Mismatched lines | 0 | 19 | +19 |
|   Increased | | | +19 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `g711_event_alaw` | compile_fail | - | 0/0 |
| `g711_event_mulaw` | compile_fail | - | 0/0 |
| `stream_incomplete_loop` | compile_fail | - | 0/0 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `aac` | compile_fail | output_mismatch | - | 3/18 |
| `g711` | compile_fail | output_mismatch | - | 2/6 |
