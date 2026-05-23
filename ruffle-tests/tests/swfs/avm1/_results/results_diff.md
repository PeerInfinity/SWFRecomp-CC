# Ruffle Test Results Diff

**Previous:** `d2da911ca124` (2026-05-23T16:59:19.018003+00:00)
**Current:** `42774a946a7e` (2026-05-23T18:44:49.269464+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 604 | 608 | +4 |
| Total | 661 | 661 | 0 |
| Pass rate | 91.4% | 92.0% | +0.6% |
| Mismatched lines | 9120 | 9102 | -18 |
|   Decreased | | | -37 |
|   Increased | | | +19 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `sound_getters` | output_mismatch | 92/99 | 99/99 |
| `sound_nested_clips` | output_mismatch | 6/10 | 10/10 |
| `sound_owner_reference` | output_mismatch | 1/12 | 12/12 |
| `sound_start_stop` | output_mismatch | 30/44 | 44/44 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `sound_owner_tostring_fail` | output_mismatch | 3/9 | 4/9 | -1 |
| `sound_setters` | output_mismatch | 31/43 | 12/43 | +19 |
