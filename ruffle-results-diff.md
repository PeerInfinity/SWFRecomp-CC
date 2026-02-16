# Ruffle Test Results Diff

**Previous:** `90261a10974c` (2026-02-16T00:57:20.370951+00:00)
**Current:** `95429be6ac85` (2026-02-16T02:19:31.745234+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 209 | 210 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 33.8% | 33.9% | +0.1% |
| Mismatched lines | 45845 | 48544 | +2699 |
|   Decreased | | | -1452 |
|   Increased | | | +4151 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_set_prop_flags_version` | output_mismatch | 21/31 | 31/31 |
| `get_variable_in_scope` | output_mismatch | 27/29 | 29/29 |
| `is_prototype_of` | output_mismatch | 59/89 | 89/89 |
| `object_properties` | output_mismatch | 0/31 | 31/31 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `infinite_recursion_function_in_setter` | output_mismatch | 131/131 | 0/131 |
| `infinite_recursion_virtual_property` | output_mismatch | 67/67 | 0/67 |
| `primitive_instanceof` | segfault | 37/37 | 33/37 |

## Status Changed (4)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `date` | output_mismatch | segfault | 3617/6335 | 1/6335 |
| `function_as_function` | output_mismatch | segfault | 13/35 | 1/35 |
| `get_bytes_total` | output_mismatch | segfault | 0/4 | 0/4 |
| `primitive_type_globals` | output_mismatch | segfault | 320/557 | 4/557 |

## Line Count Changed (30)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `focusrect_property_swf6` | output_mismatch | 168/1237 | 717/1237 | -549 |
| `focusrect_property_swf7` | output_mismatch | 169/1237 | 718/1237 | -549 |
| `focusrect_property_swf5` | output_mismatch | 43/1237 | 238/1237 | -195 |
| `this_scoping` | output_mismatch | 2/52 | 32/52 | -30 |
| `with` | output_mismatch | 37/49 | 46/49 | -9 |
| `add_property` | output_mismatch | 3/15 | 11/15 | -8 |
| `as_set_prop_flags` | output_mismatch | 54/79 | 62/79 | -8 |
| `swf5_no_closure` | output_mismatch | 1/19 | 8/19 | -7 |
| `instanceof_coercions` | output_mismatch | 7/88 | 13/88 | -6 |
| `global_proto_decls` | output_mismatch | 1/4497 | 6/4497 | -5 |
| `as2_super_and_this_v8` | output_mismatch | 2/85 | 4/85 | -2 |
| `clone_sprite_edittext_dynamic` | output_mismatch | 0/86 | 2/86 | -2 |
| `enumerate` | output_mismatch | 17/64 | 19/64 | -2 |
| `as2_super_and_this_v6` | output_mismatch | 6/97 | 7/97 | -1 |
| `clone_sprite_types` | output_mismatch | 13/24 | 14/24 | -1 |
| `local_to_global` | output_mismatch | 40/49 | 41/49 | -1 |
| `object_prototypes` | output_mismatch | 62/74 | 63/74 | -1 |
| `parse_int` | output_mismatch | 0/64 | 1/64 | -1 |
| `prototype_properties` | output_mismatch | 14/17 | 15/17 | -1 |
| `stage_object_children` | output_mismatch | 67/83 | 68/83 | -1 |
| `closure_scope` | output_mismatch | 0/7 | 0/7 | 0 |
| `global_instance_decls` | output_mismatch | 1/758 | 1/758 | 0 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `place_and_lookup` | output_mismatch | 0/30 | 0/30 | 0 |
| `watch_virtual_property_proto` | output_mismatch | 0/2 | 0/2 | 0 |
| `define_local` | output_mismatch | 3/27 | 2/27 | +1 |
| `super_edge_cases` | output_mismatch | 8/39 | 7/39 | +1 |
| `watch_virtual_property` | output_mismatch | 8/60 | 7/60 | +1 |
| `root_global_parent` | output_mismatch | 3/6 | 1/6 | +2 |
