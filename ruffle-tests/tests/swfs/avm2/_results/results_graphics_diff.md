# Ruffle Test Results Diff

**Previous:** `16343c6e1b7a` (2026-07-31T20:48:45.110707+00:00)
**Current:** `569a215e4199` (2026-07-31T23:03:09.622963+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1048 | 1051 | +3 |
| Total | 1222 | 1224 | +2 |
| Pass rate | 85.8% | 85.9% | +0.1% |
| Mismatched lines | 33499 | 33576 | +77 |
|   Decreased | | | -16 |
|   Increased | | | +2 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `method_without_body` | runtime_error | 0/3 | 3/3 |
| `property_priority_chained` | output_mismatch | 1/4 | 4/4 |
| `scopes_dont_cache/order-1` | output_mismatch | 0/1 | 1/1 |
| `scopes_dont_cache/order-2` | output_mismatch | 0/1 | 1/1 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `getter_different_namespace_setter` | ruffle_matched | 2/2 | 0/2 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `rtqname_not_namespace` | runtime_error | output_mismatch | 1/12 | 9/12 |

## Added Tests (2)

| Test | Status | Lines |
|------|--------|-------|
| `textblock_line_changes` | output_mismatch | 125/158 |
| `textblock_recreateline` | output_mismatch | 40/98 |
