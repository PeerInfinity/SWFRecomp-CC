# Graphics vs Trace Mode Differences

Trace: 1253/1335 passing | Graphics: 1273/1335 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (20 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `amf_xmllist` | Output Mismatch | 4/12 lines match |
| 2 | `array_constructor` | Output Mismatch | 21/234 lines match |
| 3 | `array_join_reentrant` | Output Mismatch | 58/68 lines match |
| 4 | `array_sort_arguments` | Output Mismatch | 42/442 lines match |
| 5 | `context3d_draw_to_bitmap_data` | Output Mismatch | 2/15 lines match |
| 6 | `displayobjectcontainer_remove_reentrant` | Output Mismatch | 2/27942 lines match |
| 7 | `displayobjectcontainer_remove_reparent` | Output Mismatch | 59/189 lines match |
| 8 | `displayobjectcontainer_removechildren_events` | Output Mismatch | 21/58 lines match |
| 9 | `edittext_set_text_same` | Output Mismatch | 92/115 lines match |
| 10 | `error_stack_trace_class_names` | Output Mismatch | 127/135 lines match |
| 11 | `error_stack_trace_limit` | Output Mismatch | 600/868 lines match |
| 12 | `hit_test_scroll_rect` | Output Mismatch | 69/99 lines match |
| 13 | `loaderinfo_root_progress` | Output Mismatch | 3/7 lines match |
| 14 | `loaderinfo_root_progress_goto` | Output Mismatch | 4/10 lines match |
| 15 | `shared_object_get_local_error` | Output Mismatch | 1/21 lines match |
| 16 | `stage3d_missing_vertex_stream` | Output Mismatch | 13/37 lines match |
| 17 | `textfield_get_text_format_args` | Output Mismatch | 50/567 lines match |
| 18 | `textfield_set_text_format_args` | Output Mismatch | 81/904 lines match |
| 19 | `vector_join_reentrant` | Output Mismatch | 10/96 lines match |
| 20 | `vector_sort_arguments` | Output Mismatch | 1/355 lines match |
