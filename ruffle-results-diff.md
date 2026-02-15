# Ruffle Test Results Diff

**Previous:** `742bdce60155` (2026-02-15T20:33:25.139535+00:00)
**Current:** `06244c7b7de8` (2026-02-15T20:56:56.320180+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 196 | 200 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 31.7% | 32.3% | +0.6% |
| Mismatched lines | 46948 | 46270 | -678 |
|   Decreased | | | -678 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_constructor` | output_mismatch | 29/30 | 30/30 |
| `globals_swf6` | output_mismatch | 293/304 | 304/304 |
| `globals_swf7` | output_mismatch | 293/304 | 304/304 |
| `globals_swf8` | output_mismatch | 286/304 | 304/304 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_html_swf6` | output_mismatch | 2640/5377 | 2838/5377 | -198 |
| `edittext_html_swf7` | output_mismatch | 2268/5377 | 2466/5377 | -198 |
| `edittext_html_swf8` | output_mismatch | 2118/5377 | 2316/5377 | -198 |
| `edittext_stylesheet` | output_mismatch | 79/325 | 107/325 | -28 |
| `globals_swf5` | output_mismatch | 279/304 | 290/304 | -11 |
| `array_sort` | output_mismatch | 114/161 | 117/161 | -3 |
| `external_interface_toxml_basic` | output_mismatch | 34/179 | 35/179 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
