# Ruffle Test Results Diff

**Previous:** `b7cdae1c5bdc` (2026-07-17T19:21:52.024506+00:00)
**Current:** `adec1e505eb9` (2026-07-18T18:50:12.973922+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 822 | 822 | 0 |
| Total | 1210 | 1215 | +5 |
| Pass rate | 67.9% | 67.7% | -0.2% |
| Mismatched lines | 47044 | 47962 | +918 |
|   Increased | | | +1 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `displayobject_rotation` | output_mismatch | 1275/1275 | 1283/1284 |

## Added Tests (5)

| Test | Status | Lines |
|------|--------|-------|
| `json_stringify_function` | output_mismatch | 0/12 |
| `number_convert_edge_cases` | output_mismatch | 148/180 |
| `number_convert_errors` | output_mismatch | 27/871 |
| `set_local_0` | pass | 31/31 |
| `timer_invalid_delay` | output_mismatch | 1/30 |
