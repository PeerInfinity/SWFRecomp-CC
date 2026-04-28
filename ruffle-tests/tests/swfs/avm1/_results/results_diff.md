# Ruffle Test Results Diff

**Previous:** `ccf8ac97313d` (2026-04-28T01:13:38.554525+00:00)
**Current:** `abf1b163b420` (2026-04-28T02:14:37.094102+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 597 | 594 | -3 |
| Total | 641 | 641 | 0 |
| Pass rate | 93.1% | 92.7% | -0.4% |
| Mismatched lines | 8897 | 9111 | +214 |
|   Increased | | | +214 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `on_construct` | output_mismatch | 25/25 | 11/25 |
| `register_and_init_order` | output_mismatch | 231/231 | 41/231 |
| `resolve_different_root` | output_mismatch | 2/2 | 0/2 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_instance_decls` | output_mismatch | 23/758 | 15/758 | +8 |
