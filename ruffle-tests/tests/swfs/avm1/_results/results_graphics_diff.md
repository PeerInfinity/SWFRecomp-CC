# Ruffle Test Results Diff

**Previous:** `be9aafd78ec0` (2026-05-16T21:06:43.832733+00:00)
**Current:** `6fe6fb1a2f62` (2026-05-24T23:52:34.184519+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 604 | 614 | +10 |
| Total | 655 | 671 | +16 |
| Pass rate | 92.2% | 91.5% | -0.7% |
| Mismatched lines | 9284 | 9598 | +314 |
|   Decreased | | | -188 |
|   Increased | | | +2 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `sound_gettransform_props` | output_mismatch | 2/4 | 4/4 |
| `swf5_xml_event_handler_context` | output_mismatch | 0/2 | 2/2 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `with` | output_mismatch | 49/49 | 44/46 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `native_objects_swf6` | segfault | output_mismatch | 9/115 | 114/115 |

## Added Tests (16)

| Test | Status | Lines |
|------|--------|-------|
| `geturl_opcode_target_normalize` | output_mismatch | 0/45 |
| `geturl_target_normalize` | output_mismatch | 4/89 |
| `looping_child_swf32` | output_mismatch | 29/141 |
| `looping_child_swf5` | output_mismatch | 29/141 |
| `looping_child_swf9` | output_mismatch | 29/141 |
| `looping_real_1_declared_1` | pass | 1/1 |
| `looping_real_1_declared_2` | pass | 1/1 |
| `looping_real_2_declared_1` | pass | 5/5 |
| `looping_real_2_declared_2` | pass | 5/5 |
| `shared_stack` | output_mismatch | 11/16 |
| `sound_getters` | pass | 99/99 |
| `sound_nested_clips` | pass | 10/10 |
| `sound_owner_reference` | pass | 12/12 |
| `sound_owner_tostring_fail` | pass | 9/9 |
| `sound_setters` | output_mismatch | 14/43 |
| `sound_start_stop` | pass | 44/44 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls_delete` | output_mismatch | 386/4158 | 461/4158 | -75 |
| `global_instance_decls` | output_mismatch | 23/758 | 26/758 | -3 |
| `xml_getbytes` | output_mismatch | 8/17 | 9/17 | -1 |
