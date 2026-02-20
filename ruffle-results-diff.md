# Ruffle Test Results Diff

**Previous:** `7d128ba10acf` (2026-02-20T02:35:19.470359+00:00)
**Current:** `a58b421c18f8` (2026-02-20T03:24:27.968549+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 226 | 226 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 36.5% | 36.5% | 0% |
| Mismatched lines | 39605 | 39585 | -20 |
|   Decreased | | | -23 |
|   Increased | | | +3 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `mouse_listeners` | output_mismatch | 45/67 | 67/67 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `as_broadcaster_initialize` | output_mismatch | 10/10 | 7/10 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls` | output_mismatch | 8/4497 | 9/4497 | -1 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
