# Ruffle Test Results Diff

**Previous:** `c146dc66ef9a` (2026-07-31T05:17:45.983134+00:00)
**Current:** `a28b3e2cbb40` (2026-07-31T14:52:54.908152+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1039 | 1046 | +7 |
| Total | 1222 | 1222 | 0 |
| Pass rate | 85.0% | 85.6% | +0.6% |
| Mismatched lines | 33529 | 33505 | -24 |
|   Decreased | | | -24 |

## Newly Passing (7)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `applicationdomain_getqualifieddefinitionnames` | output_mismatch | 0/9 | 9/9 |
| `applicationdomain_hasdefinition_null` | output_mismatch | 1/2 | 2/2 |
| `constructprop_method` | output_mismatch | 0/2 | 2/2 |
| `displayobject_opaque_background` | output_mismatch | 5/6 | 6/6 |
| `property_is_enumerable_reset` | output_mismatch | 22/23 | 23/23 |
| `property_priority_definition_names_order` | output_mismatch | 0/2 | 2/2 |
| `stage_domain_getQualifiedDefinitionNames` | output_mismatch | 1/5 | 5/5 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `core_exceptions` | output_mismatch | 41/47 | 45/47 | -4 |
