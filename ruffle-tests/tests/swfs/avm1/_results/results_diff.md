# Ruffle Test Results Diff

**Previous:** `ec66bc3379da` (2026-04-21T03:00:09.809157+00:00)
**Current:** `06feeaca161c` (2026-04-21T05:44:07.599562+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 597 | 591 | -6 |
| Total | 641 | 641 | 0 |
| Pass rate | 93.1% | 92.2% | -0.9% |
| Mismatched lines | 9104 | 9172 | +68 |
|   Increased | | | +68 |

## Newly Failing (6)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `call` | output_mismatch | 63/63 | 36/63 |
| `default_names` | output_mismatch | 52/52 | 43/52 |
| `issue_9885` | output_mismatch | 2/2 | 2/2 |
| `register_and_init_order` | output_mismatch | 231/231 | 212/231 |
| `removed_clip_halts_script` | output_mismatch | 15/15 | 3/15 |
| `target_clip_removed` | output_mismatch | 5/5 | 4/5 |
