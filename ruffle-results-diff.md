# Ruffle Test Results Diff

**Previous:** `733a70e9c5f3` (2026-02-14T20:44:57.230326+00:00)
**Current:** `077886357d3a` (2026-02-14T23:41:30.829664+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 186 | 190 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 30.0% | 30.7% | +0.7% |
| Mismatched lines | 52553 | 51117 | -1436 |
|   Decreased | | | -1439 |
|   Increased | | | +3 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `xml_namespaces` | output_mismatch | 187/203 | 203/203 |
| `xml_reparenting` | output_mismatch | 0/14 | 14/14 |
| `xml_unescaping` | output_mismatch | 0/23 | 23/23 |
| `xmlnode_proto` | output_mismatch | 0/1 | 1/1 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_data_pixeldissolve` | output_mismatch | timeout | 0/1075 | - |

## Line Count Changed (34)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `string_methods_negative_args` | output_mismatch | 0/240 | 127/240 | -127 |
| `function_suppress_and_preload` | output_mismatch | 0/28 | 24/28 | -24 |
| `movieclip_blend_mode_property` | output_mismatch | 0/35 | 24/35 | -24 |
| `boxed_primitives` | output_mismatch | 0/24 | 14/24 | -14 |
| `math_swf6` | output_mismatch | 0/530 | 10/530 | -10 |
| `math_swf7` | output_mismatch | 0/530 | 10/530 | -10 |
| `math_swf8` | output_mismatch | 0/530 | 10/530 | -10 |
| `coerce_to_object_monkeypatch` | output_mismatch | 0/129 | 9/129 | -9 |
| `native_subclasses` | output_mismatch | 0/191 | 9/191 | -9 |
| `extends_native_type` | output_mismatch | 0/11 | 8/11 | -8 |
| `coerce_to_primitive_resolve` | output_mismatch | 0/17 | 7/17 | -7 |
| `instanceof_coercions` | output_mismatch | 0/88 | 7/88 | -7 |
| `super_edge_cases` | output_mismatch | 0/39 | 7/39 | -7 |
| `as2_super_and_this_v6` | output_mismatch | 0/97 | 6/97 | -6 |
| `hittest_winding_rule` | output_mismatch | 0/12 | 6/12 | -6 |
| `register_class_return_value` | output_mismatch | 0/16 | 6/16 | -6 |
| `as2_oop` | output_mismatch | 5/13 | 10/13 | -5 |
| `as2_super_via_manual_prototype` | output_mismatch | 6/40 | 11/40 | -5 |
| `native_double_construct` | output_mismatch | 0/12 | 5/12 | -5 |
| `bitmap_data_copypixels` | output_mismatch | 0/17 | 3/17 | -3 |
| `as2_super_and_this_v8` | output_mismatch | 0/85 | 2/85 | -2 |
| `asnew` | output_mismatch | 0/34 | 1/34 | -1 |
| `hittest_lockroot` | output_mismatch | 0/15 | 1/15 | -1 |
| `loadmovie_fail` | output_mismatch | 0/2 | 1/2 | -1 |
| `loadmovienum_cross_version_prototype` | output_mismatch | 0/9 | 1/9 | -1 |
| `register_class_with_sound` | output_mismatch | 0/11 | 1/11 | -1 |
| `xml_socket` | output_mismatch | 0/8 | 1/8 | -1 |
| `array_sort_random` | output_mismatch | 0/443 | 0/443 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `issue_3169` | output_mismatch | 0/2 | 0/2 | 0 |
| `issue_9327` | output_mismatch | 0/2 | 0/2 | 0 |
| `object_resolve` | output_mismatch | 0/38 | 0/38 | 0 |
| `watch` | output_mismatch | 18/117 | 18/117 | 0 |
| `extends_chain` | output_mismatch | 15/134 | 12/134 | +3 |
