# Ruffle Test Results Diff

**Previous:** `45a5281eefde` (2026-02-18T16:07:08.365240+00:00)
**Current:** `10a57582eb0f` (2026-02-18T16:25:46.003654+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 226 | 229 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 36.5% | 37.0% | +0.5% |
| Mismatched lines | 42652 | 41386 | -1266 |
|   Decreased | | | -1266 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `arguments` | output_mismatch | 106/127 | 127/127 |
| `edittext_width_height` | output_mismatch | 97/103 | 103/103 |
| `function_suppress_and_preload` | output_mismatch | 24/28 | 28/28 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `date` | output_mismatch | 5049/6335 | 6284/6335 | -1235 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
