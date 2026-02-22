# Ruffle Test Results Diff

**Previous:** `4d432e56f8e7` (2026-02-21T22:19:01.983226+00:00)
**Current:** `7b56f94b8a75` (2026-02-22T00:23:17.600104+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 267 | 269 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 43.1% | 43.5% | +0.4% |
| Mismatched lines | 39009 | 38998 | -11 |
|   Decreased | | | -20 |
|   Increased | | | +9 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `goto_rewind3` | output_mismatch | 2/2 | 2/2 |
| `transform` | output_mismatch | 69/70 | 70/70 |
| `with` | output_mismatch | 47/49 | 49/49 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `placeobject_occupied_depth` | output_mismatch | 6/6 | 0/6 |

## Line Count Changed (30)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_label` | output_mismatch | 2/17 | 8/17 | -6 |
| `unloadmovienum` | output_mismatch | 3/13 | 6/13 | -3 |
| `loading_avm2` | output_mismatch | 1/7 | 3/7 | -2 |
| `movieclip_library_state_values` | output_mismatch | 13/78 | 15/78 | -2 |
| `movieclip_state_values` | runtime_error | 1/114 | 3/114 | -2 |
| `call` | output_mismatch | 4/63 | 5/63 | -1 |
| `loadvariables2` | output_mismatch | 1/8 | 2/8 | -1 |
| `cross_movie_root` | output_mismatch | 0/10 | 0/10 | 0 |
| `form_loader_encoding_1` | output_mismatch | 0/1 | 0/1 | 0 |
| `form_loader_encoding_2` | output_mismatch | 0/3 | 0/3 | 0 |
| `form_loader_encoding_3` | output_mismatch | 0/3 | 0/3 | 0 |
| `form_loader_encoding_4` | output_mismatch | 0/3 | 0/3 | 0 |
| `geturl` | output_mismatch | 0/7 | 0/7 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `loadmovie` | output_mismatch | 1/2 | 1/2 | 0 |
| `loadmovie_flashvars` | output_mismatch | 1/4 | 1/4 | 0 |
| `loadmovie_registerclass` | output_mismatch | 0/30 | 0/30 | 0 |
| `loadmovie_replace_root` | output_mismatch | 0/5 | 0/5 | 0 |
| `loadmovienum` | output_mismatch | 1/3 | 1/3 | 0 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 1/9 | 1/9 | 0 |
| `loadvariables` | output_mismatch | 0/2 | 0/2 | 0 |
| `loadvariablesnum` | output_mismatch | 0/2 | 0/2 | 0 |
| `localconnection` | output_mismatch | 0/579 | 0/579 | 0 |
| `register_globals_across_frames` | output_mismatch | 7/15 | 7/15 | 0 |
| `root_button_mode` | output_mismatch | 0/10 | 0/10 | 0 |
| `swf5_to_6_cross_call` | output_mismatch | 0/29 | 0/29 | 0 |
| `swf5_xml_event_handler_context` | output_mismatch | 0/2 | 0/2 | 0 |
| `swf6_to_5_cross_call` | output_mismatch | 0/29 | 0/29 | 0 |
| `unloadmovie` | output_mismatch | 2/4 | 1/4 | +1 |
| `swf4_actions_coercion_order` | output_mismatch | 11/158 | 9/158 | +2 |
