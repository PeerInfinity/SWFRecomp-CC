# Ruffle Test Results Diff

**Previous:** `a946ee183838` (2026-08-19T16:36:38.727874+00:00)
**Current:** `0a56091cfce2` (2026-09-02T18:22:57.333426+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1180 | 1180 | 0 |
| Total | 1251 | 1261 | +10 |
| Pass rate | 94.3% | 93.6% | -0.7% |
| Mismatched lines | 3486 | 3615 | +129 |

## Added Tests (11)

| Test | Status | Lines |
|------|--------|-------|
| `bitmapdata_applyfilter_identity` | output_mismatch | 2/4 |
| `bitmapdata_copypixels_alpha_combine` | output_mismatch | 2/13 |
| `bitmapdata_copypixels_alpha_merge` | output_mismatch | 3/9 |
| `displayobjectcontainer_stopallmovieclips_nonconstructed` | ruffle_matched | 19/19 |
| `flash_ui_mouse_cursor` | output_mismatch | 1/22 |
| `init_callee_cached` | pass | 24/24 |
| `loader_events_2` | output_mismatch | 2/35 |
| `movieclip_addframescript_error` | output_mismatch | 0/9 |
| `primitive_keys` | output_mismatch | 33/54 |
| `textline_atom_index_at_char_index` | output_mismatch | 21/40 |
| `xml_duplicate_attribute` | output_mismatch | 7/14 |

## Removed Tests (1)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `dictionary_primitive_keys` | pass | 29/29 |
