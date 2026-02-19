# Ruffle Test Results Diff

**Previous:** `668f34f1223f` (2026-02-18T23:28:25.934822+00:00)
**Current:** `64db84cffa42` (2026-02-18T23:38:13.406288+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 234 | 236 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 37.8% | 38.1% | +0.3% |
| Mismatched lines | 40169 | 40065 | -104 |
|   Decreased | | | -104 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `clone_sprite_types` | output_mismatch | 14/24 | 24/24 |
| `duplicate_movie_clip` | output_mismatch | 4/20 | 20/20 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `clip_events` | output_mismatch | segfault | 1/19 | 1/19 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `clone_sprite_edittext_dynamic` | output_mismatch | 2/86 | 50/86 | -48 |
| `clone_sprite_edittext` | output_mismatch | 2/94 | 24/94 | -22 |
| `unload` | output_mismatch | 11/52 | 14/52 | -3 |
| `remove_movie_clip` | output_mismatch | 19/29 | 21/29 | -2 |
| `string_paths_hidden` | output_mismatch | 34/54 | 36/54 | -2 |
| `issue_2870` | output_mismatch | 0/3 | 1/3 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
