# Ruffle Test Results Diff

**Previous:** `fa4caf2efd89` (2026-09-27T08:50:10.814581+00:00)
**Current:** `7755698f8329` (2026-09-29T02:24:03.638829+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1218 | 1222 | +4 |
| Total | 1279 | 1280 | +1 |
| Pass rate | 95.2% | 95.5% | +0.3% |
| Mismatched lines | 2865 | 2541 | -324 |
|   Decreased | | | -336 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `casi32` | output_mismatch | 9/166 | 166/166 |
| `sound_load_multiple` | output_mismatch | 3/19 | 19/19 |
| `textjustifier_locale` | output_mismatch | 8/132 | 132/132 |
| `textline_has_tabs` | output_mismatch | 42/47 | 47/47 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `simplebutton_childevents_multichild` | output_mismatch | ruffle_matched | 33/152 | 51/152 |
| `textline_atom_index_at_char_index` | output_mismatch | ruffle_matched | 21/40 | 37/40 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `gradient_values_readback` | ruffle_matched | 200/212 |
