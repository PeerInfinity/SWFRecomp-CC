# Ruffle Test Results Diff

**Previous:** `c489b84d9946` (2026-11-21T19:32:37.118123+00:00)
**Current:** `9a970370e096` (2026-11-21T20:48:06.948454+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1253 | 1273 | +20 |
| Total | 1335 | 1335 | 0 |
| Pass rate | 93.9% | 95.4% | +1.5% |
| Mismatched lines | 5744 | 2705 | -3039 |
|   Decreased | | | -3039 |

## Newly Passing (20)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `amf_xmllist` | output_mismatch | 4/12 | 12/12 |
| `array_constructor` | output_mismatch | 21/234 | 234/234 |
| `array_join_reentrant` | output_mismatch | 58/68 | 68/68 |
| `array_sort_arguments` | output_mismatch | 42/442 | 442/442 |
| `context3d_draw_to_bitmap_data` | output_mismatch | 2/15 | 15/15 |
| `displayobjectcontainer_remove_reentrant` | output_mismatch | 2/257 | 257/257 |
| `displayobjectcontainer_remove_reparent` | output_mismatch | 59/189 | 189/189 |
| `displayobjectcontainer_removechildren_events` | output_mismatch | 21/56 | 56/56 |
| `edittext_set_text_same` | output_mismatch | 92/115 | 115/115 |
| `error_stack_trace_class_names` | output_mismatch | 127/135 | 135/135 |
| `error_stack_trace_limit` | output_mismatch | 600/674 | 674/674 |
| `hit_test_scroll_rect` | output_mismatch | 69/99 | 99/99 |
| `loaderinfo_root_progress` | output_mismatch | 3/7 | 7/7 |
| `loaderinfo_root_progress_goto` | output_mismatch | 4/10 | 10/10 |
| `shared_object_get_local_error` | output_mismatch | 1/21 | 21/21 |
| `stage3d_missing_vertex_stream` | output_mismatch | 13/37 | 37/37 |
| `textfield_get_text_format_args` | output_mismatch | 50/567 | 567/567 |
| `textfield_set_text_format_args` | output_mismatch | 81/904 | 904/904 |
| `vector_join_reentrant` | output_mismatch | 10/96 | 96/96 |
| `vector_sort_arguments` | output_mismatch | 1/355 | 355/355 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `edittext_set_text_same_after_edits` | output_mismatch | ruffle_matched | 84/138 | 90/138 |
