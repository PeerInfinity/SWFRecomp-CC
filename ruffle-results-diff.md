# Ruffle Test Results Diff

**Previous:** `2a88307e7980` (2026-02-14T00:37:32.353611+00:00)
**Current:** `03e795d08e7a` (2026-02-14T01:20:26.847876+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 144 | 145 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 23.3% | 23.4% | +0.1% |
| Mismatched lines | 57238 | 57227 | -11 |
|   Decreased | | | -13 |
|   Increased | | | +2 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `display_object_properties` | output_mismatch | 1/2 | 2/2 |
| `goto_advance1` | output_mismatch | 4/6 | 6/6 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `issue_1906` | output_mismatch | 4/4 | 2/4 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `frame_size_translated_positive` | output_mismatch | 6/21 | 10/21 | -4 |
| `conflicting_instance_names` | output_mismatch | 18/23 | 21/23 | -3 |
| `frame_size_translated_negative` | output_mismatch | 7/21 | 10/21 | -3 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
