# Ruffle Test Results Diff

**Previous:** `8fb3a99ec4dd` (2026-04-27T02:49:17.007852+00:00)
**Current:** `7360935a6acf` (2026-04-27T03:40:32.977845+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 593 | 596 | +3 |
| Total | 641 | 641 | 0 |
| Pass rate | 92.5% | 93.0% | +0.5% |
| Mismatched lines | 8939 | 8910 | -29 |
|   Decreased | | | -41 |
|   Increased | | | +12 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `attach_movie` | output_mismatch | 55/59 | 59/59 |
| `default_names` | output_mismatch | 42/52 | 52/52 |
| `removed_target_clip_scope` | output_mismatch | 8/35 | 35/35 |
| `tell_target_invalid_swf6` | output_mismatch | 5/5 | 5/5 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `removed_clip_halts_script` | output_mismatch | 15/15 | 3/15 |
