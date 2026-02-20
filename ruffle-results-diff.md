# Ruffle Test Results Diff

**Previous:** `0183209fc353` (2026-02-20T05:33:22.843016+00:00)
**Current:** `be4d767bd7f8` (2026-02-20T16:29:07.347401+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 227 | 231 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 36.7% | 37.3% | +0.6% |
| Mismatched lines | 39575 | 39878 | +303 |
|   Decreased | | | -215 |
|   Increased | | | +518 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_default_format_font_style` | output_mismatch | 315/335 | 335/335 |
| `edittext_html_align_swf7` | output_mismatch | 42/52 | 52/52 |
| `edittext_html_align_swf8` | output_mismatch | 45/52 | 52/52 |
| `edittext_newline_stripping` | output_mismatch | 23/64 | 64/64 |
| `textfield_props_swf5` | output_mismatch | 43/175 | 175/175 |
| `textfield_variable` | output_mismatch | 78/81 | 81/81 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `enumerate` | output_mismatch | 64/64 | 31/64 |
| `globals_swf5` | output_mismatch | 304/304 | 293/304 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `target_path` | output_mismatch | segfault | 11/14 | 3/14 |

## Line Count Changed (10)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `printjob_props_swf5` | output_mismatch | 5/45 | 7/45 | -2 |
| `this_swf5` | output_mismatch | 25/41 | 24/41 | +1 |
| `sound_props_swf5` | output_mismatch | 50/68 | 48/68 | +2 |
| `textsnapshot_props_swf5` | output_mismatch | 14/56 | 12/56 | +2 |
| `focusrect_property_swf5` | output_mismatch | 269/1237 | 259/1237 | +10 |
| `edittext_html_condensewhite_swf7` | output_mismatch | 174/311 | 145/311 | +29 |
| `edittext_html_condensewhite_swf8` | output_mismatch | 171/311 | 142/311 | +29 |
| `edittext_html_swf8` | output_mismatch | 2316/5377 | 2247/5377 | +69 |
| `edittext_html_swf6` | output_mismatch | 2838/5377 | 2718/5377 | +120 |
| `edittext_html_swf7` | output_mismatch | 2466/5377 | 2262/5377 | +204 |
