# Ruffle Test Results Diff

**Previous:** `95429be6ac85` (2026-02-16T02:19:31.745234+00:00)
**Current:** `0be4e54a5801` (2026-02-16T19:03:42.904390+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 210 | 213 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 33.9% | 34.4% | +0.5% |
| Mismatched lines | 48544 | 44458 | -4086 |
|   Decreased | | | -4150 |
|   Increased | | | +64 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `infinite_recursion_function_in_setter` | output_mismatch | 0/131 | 131/131 |
| `infinite_recursion_virtual_property` | output_mismatch | 0/67 | 67/67 |
| `primitive_instanceof` | segfault | 33/37 | 37/37 |

## Status Changed (8)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `date` | segfault | output_mismatch | 1/6335 | 3617/6335 |
| `function_as_function` | segfault | output_mismatch | 1/35 | 13/35 |
| `function_base_clip_removed` | segfault | output_mismatch | 1/25 | 1/25 |
| `get_bytes_total` | segfault | output_mismatch | 0/4 | 0/4 |
| `init_object_order` | segfault | output_mismatch | 5/15 | 5/15 |
| `primitive_type_globals` | segfault | output_mismatch | 4/557 | 320/557 |
| `register_and_init_order` | segfault | output_mismatch | 27/231 | 30/231 |
| `register_class` | segfault | output_mismatch | - | 2/66 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `watch_virtual_property` | output_mismatch | 7/60 | 8/60 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
