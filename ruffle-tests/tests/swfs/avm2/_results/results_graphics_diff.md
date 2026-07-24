# Ruffle Test Results Diff

**Previous:** `2cf4014fd672` (2026-07-24T22:06:49.298471+00:00)
**Current:** `17c19040c9cd` (2026-07-24T23:01:01.235807+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 833 | 805 | -28 |
| Total | 1217 | 1177 | -40 |
| Pass rate | 68.4% | 68.4% | 0% |
| Mismatched lines | 46941 | 47442 | +501 |
|   Increased | | | +532 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `primitive_toString` | segfault | output_mismatch | - | 16/277 |
| `primitive_valueOf` | segfault | output_mismatch | - | 14/285 |

## Missing Tests — Shard Failure (40)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 28 were previously passing
- 12 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `vector_reborrow_bug` | pass | 10/10 |
| `vector_removeat` | pass | 172/172 |
| `vector_reverse` | pass | 232/232 |
| `vector_shiftunshift` | pass | 252/252 |
| `vector_slice` | pass | 331/331 |
| `vector_sort` | pass | 905/905 |
| `vector_splice` | pass | 693/693 |
| `vector_splice_fixed_bug_compat` | pass | 4/4 |
| `vector_tostring` | pass | 79/79 |
| `verification` | output_mismatch | 5/8 |
| `verify_abnormal_loop` | pass | 1/1 |
| `verify_dxns_without_flag` | output_mismatch | 1/3 |
| `verify_exception_target_two_jumps` | output_mismatch | 0/1 |
| `verify_exception_targets_edge_case` | pass | 1/1 |
| `verify_illegal_opcode` | output_mismatch | 0/1 |
| `verify_jump_to_middle_of_op` | output_mismatch | 0/1 |
| `verify_lookup_switch_edge_case` | pass | 1/1 |
| `verify_method_info_duplicate` | output_mismatch | 0/2 |
| `verify_method_info_oob` | output_mismatch | 0/1 |
| `verify_stack` | output_mismatch | 2/5 |
| `verify_typecheck` | runtime_error | 0/4 |
| `verify_unreachable_exception` | pass | 2/2 |
| `versioned_isplaying` | pass | 2/2 |
| `virtual_properties` | pass | 16/16 |
| `weird_superinterface_properties` | ruffle_matched | 1/2 |
| `with` | pass | 4/4 |
| `wrong_arg_count` | output_mismatch | 1/7 |
| `xml_abstract_equality` | pass | 36/36 |
| `xml_advanced` | pass | 52/52 |
| `xml_appendchild` | pass | 10/10 |
| `xml_appendchild_swf_v21` | output_mismatch | 7/13 |
| `xml_as_attribute` | pass | 9/9 |
| `xml_attribute` | pass | 35/35 |
| `xml_attribute_name` | pass | 40/40 |
| `xml_basic` | pass | 33/33 |
| `xml_child` | pass | 25/25 |
| `xml_childindex` | pass | 7/7 |
| `xml_children` | pass | 43/43 |
| `xml_class_call` | pass | 9/9 |
| `xml_contains` | pass | 197/197 |

</details>
