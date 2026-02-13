# Ruffle Test Results Diff

**Previous:** `688277072b98` (2026-02-13T04:26:18.252614+00:00)
**Current:** `e145c7e84966` (2026-02-13T05:32:44.570225+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 122 | 127 | +5 |
| Total | 616 | 616 | 0 |
| Pass rate | 19.8% | 20.6% | +0.8% |
| Mismatched lines | 56397 | 56384 | -13 |
|   Decreased | | | -14 |
|   Increased | | | +1 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `get_variable_in_scope` | output_mismatch | 26/29 | 29/29 |
| `issue_710` | output_mismatch | 1/4 | 4/4 |
| `new_object_wrap` | output_mismatch | 1/4 | 4/4 |
| `recursive_prototypes` | output_mismatch | 0/0 | 0/0 |
| `stage_object_properties_get_var` | output_mismatch | 3/5 | 5/5 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `new_method_wrap` | output_mismatch | 0/4 | 3/4 | -3 |
| `with` | output_mismatch | 31/49 | 30/49 | +1 |
