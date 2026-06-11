# Ruffle Test Results Diff

**Previous:** `eb280b751d6b` (2026-06-11T16:10:17.999347+00:00)
**Current:** `db8c78080cb1` (2026-06-11T16:40:26.811100+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 609 | 616 | +7 |
| Total | 678 | 678 | 0 |
| Pass rate | 89.8% | 90.9% | +1.1% |
| Mismatched lines | 11981 | 11125 | -856 |
|   Decreased | | | -856 |

## Newly Passing (7)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `call` | output_mismatch | 42/62 | 62/62 |
| `path_string` | output_mismatch | 56/301 | 301/301 |
| `property_invalid_base_clip` | output_mismatch | 19/35 | 35/35 |
| `swf4_actions_coercion_order` | output_mismatch | 106/157 | 157/157 |
| `tell_target` | output_mismatch | 4/34 | 34/34 |
| `tell_target_invalid` | output_mismatch | 0/5 | 5/5 |
| `tell_target_invalid_swf6` | output_mismatch | 0/4 | 4/4 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `target_paths/swf4` | output_mismatch | 171/818 | 642/818 | -471 |
| `target_paths/swf5` | output_mismatch | 171/854 | 178/854 | -7 |
| `target_paths/swf6` | output_mismatch | 171/854 | 178/854 | -7 |
