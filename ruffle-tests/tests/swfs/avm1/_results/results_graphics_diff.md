# Ruffle Test Results Diff

**Previous:** `b232f7e6facb` (2026-05-11T04:19:19.354544+00:00)
**Current:** `e0568fe7e53f` (2026-05-11T17:30:43.916699+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 578 | 587 | +9 |
| Total | 651 | 651 | 0 |
| Pass rate | 88.8% | 90.2% | +1.4% |
| Mismatched lines | 9368 | 9143 | -225 |
|   Decreased | | | -225 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `clone_sprite_edittext` | output_mismatch | 3/94 | 94/94 |
| `clone_sprite_edittext_dynamic` | output_mismatch | 3/86 | 86/86 |
| `clone_sprite_types` | output_mismatch | 18/24 | 24/24 |
| `duplicate_movie_clip` | output_mismatch | 12/20 | 20/20 |
| `duplicate_movie_clip_drawing` | output_mismatch | 1/2 | 2/2 |
| `remove_movie_clip` | output_mismatch | 26/29 | 29/29 |
| `removed_target_clip_scope` | output_mismatch | 12/35 | 35/35 |
| `string_paths_variable_scopes` | output_mismatch | 3/5 | 5/5 |
| `textsnapshot_available_text` | output_mismatch | 13/20 | 20/20 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `string_paths_reference_launder` | output_mismatch | 0/2 | 1/2 | -1 |
