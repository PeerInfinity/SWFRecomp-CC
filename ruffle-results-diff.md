# Ruffle Test Results Diff

**Previous:** `d3e8a731e0b0` (2026-02-27T23:41:58.651983+00:00)
**Current:** `4964c8e432fa` (2026-02-28T00:29:40.117396+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 397 | 397 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 64.1% | 64.1% | 0% |
| Mismatched lines | 31507 | 31503 | -4 |
|   Decreased | | | -12 |
|   Increased | | | +8 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `on_construct` | segfault | 13/25 | 25/25 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `clip_events` | output_mismatch | 19/19 | 13/19 |

## Status Changed (4)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_init_object` | segfault | output_mismatch | 1/5 | 1/5 |
| `register_and_init_order` | segfault | output_mismatch | 31/231 | 31/231 |
| `register_class_with_sound` | segfault | output_mismatch | 1/11 | 1/11 |
| `resolve_different_root` | segfault | output_mismatch | - | 0/2 |
