# Ruffle Test Results Diff

**Previous:** `b4cdea61de2f` (2026-02-18T05:24:27.658883+00:00)
**Current:** `229cb534e3fe` (2026-02-18T06:34:26.692377+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 221 | 225 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 35.7% | 36.3% | +0.6% |
| Mismatched lines | 42941 | 42714 | -227 |
|   Decreased | | | -227 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `globals_swf5` | output_mismatch | 290/304 | 304/304 |
| `textfield_props_swf6` | output_mismatch | 142/210 | 210/210 |
| `textfield_props_swf7` | output_mismatch | 142/210 | 210/210 |
| `textfield_props_swf8` | output_mismatch | 142/210 | 210/210 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `this_swf5` | output_mismatch | 19/41 | 25/41 | -6 |
| `textfield_props_swf5` | output_mismatch | 41/175 | 43/175 | -2 |
| `focusrect_property_swf5` | output_mismatch | 238/1237 | 239/1237 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
