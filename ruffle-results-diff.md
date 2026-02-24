# Ruffle Test Results Diff

**Previous:** `a3b4b418e473` (2026-02-24T00:26:58.483514+00:00)
**Current:** `4624ca77849c` (2026-02-24T01:29:50.916552+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 319 | 319 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 51.5% | 51.5% | 0% |
| Mismatched lines | 34646 | 34646 | 0 |
|   Decreased | | | -4 |
|   Increased | | | +4 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `button_properties_special_cases` | output_mismatch | 19/22 | 22/22 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `stage_object_enumerate` | output_mismatch | 4/4 | 0/4 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_library_state_values` | runtime_error | output_mismatch | 68/78 | 68/78 |
| `movieclip_state_values` | runtime_error | output_mismatch | 3/114 | 3/114 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_in_removed_button` | output_mismatch | 1/4 | 2/4 | -1 |
| `global_proto_decls` | output_mismatch | 13/4497 | 13/4497 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
