# Ruffle Test Results Diff

**Previous:** `c1fa89bc20be` (2026-10-19T20:20:55.487396+00:00)
**Current:** `08709f65842a` (2026-11-21T17:28:09.814558+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1234 | 1240 | +6 |
| Total | 1300 | 1334 | +34 |
| Pass rate | 94.9% | 93.0% | -1.9% |
| Mismatched lines | 3412 | 5920 | +2508 |
|   Increased | | | +2 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `filereference_browse_select` | output_mismatch | 9/9 | 7/9 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `event_handler_exception` | ruffle_matched | output_mismatch | 7/11 | 7/11 |

## Added Tests (34)

| Test | Status | Lines |
|------|--------|-------|
| `amf_sealed_class_dynamic_properties` | pass | 16/16 |
| `amf_xmllist` | output_mismatch | 4/12 |
| `array_sort_arguments` | output_mismatch | 42/442 |
| `bitmapdata_encode` | output_mismatch | 1/147 |
| `bitmapdata_encode_jpeg_visual` | output_mismatch | 0/0 |
| `bitmapdata_encode_png_roundtrip` | output_mismatch | 1/33 |
| `bitmapdata_encode_png_visual` | output_mismatch | 0/0 |
| `bytearray_amf3_shared_references` | pass | 4/4 |
| `bytearray_insertion_reborrow` | pass | 5/5 |
| `context3d_clear_mask` | pass | 4/4 |
| `displayobjectcontainer_remove_reentrant` | output_mismatch | 2/257 |
| `displayobjectcontainer_remove_reparent` | output_mismatch | 59/189 |
| `displayobjectcontainer_removechildren_events` | output_mismatch | 21/56 |
| `edittext_event_link_case_insensitive` | output_mismatch | 0/1 |
| `edittext_set_text_same` | output_mismatch | 92/115 |
| `edittext_set_text_same_after_edits` | output_mismatch | 84/138 |
| `error_stack_trace_class_names` | output_mismatch | 127/135 |
| `error_stack_trace_limit` | output_mismatch | 600/674 |
| `loader_unloadandstop_subclass` | pass | 1/1 |
| `loaderinfo_child_progress` | pass | 9/9 |
| `loaderinfo_root_progress` | output_mismatch | 3/7 |
| `loaderinfo_root_progress_goto` | output_mismatch | 4/10 |
| `netconnection_call_with_responder` | pass | 6/6 |
| `perspective_projection_center` | output_mismatch | 6/34 |
| `primitive_bound_methods` | output_mismatch | 5/11 |
| `shared_object_get_local_error` | output_mismatch | 1/21 |
| `stage3d_missing_vertex_stream` | output_mismatch | 13/37 |
| `textfield_set_text_format_args` | output_mismatch | 81/904 |
| `vector_indexing_cutoffs` | ruffle_matched | 17/18 |
| `vector_sort_arguments` | output_mismatch | 1/355 |
| `weird_number_bound_methods` | output_mismatch | 9/12 |
| `worker_terminate` | output_mismatch | 1/56 |
| `xml_many_namespace_declarations` | output_mismatch | 1/2 |
| `xml_unescaping_nul_char_ref` | output_mismatch | 4/19 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `xml_mismatched_tag` | pass | 37/37 | 45/45 | 0 |
