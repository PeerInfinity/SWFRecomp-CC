# Ruffle Test Results Diff

**Previous:** `9a27fcd10360` (2026-02-16T00:33:55.134395+00:00)
**Current:** `90261a10974c` (2026-02-16T00:57:20.370951+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 209 | 209 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 33.8% | 33.8% | 0% |
| Mismatched lines | 45849 | 45845 | -4 |
|   Decreased | | | -6 |
|   Increased | | | +2 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `xml_namespaces` | output_mismatch | 197/203 | 203/203 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `xml_attributes_read` | output_mismatch | 4/4 | 2/4 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
