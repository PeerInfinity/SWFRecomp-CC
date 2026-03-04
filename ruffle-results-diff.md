# Ruffle Test Results Diff

**Previous:** `ff133f9dde75` (2026-03-04T19:17:10.708070+00:00)
**Current:** `a50d38f8e84b` (2026-03-04T21:19:14.827281+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 446 | 445 | -1 |
| Total | 619 | 619 | 0 |
| Pass rate | 72.1% | 71.9% | -0.2% |
| Mismatched lines | 22327 | 21694 | -633 |
|   Decreased | | | -648 |
|   Increased | | | +15 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `stylesheet` | output_mismatch | 15/283 | 283/283 |
| `stylesheet_transform` | output_mismatch | 375/750 | 750/750 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `printjob_props_swf5` | output_mismatch | 45/45 | 40/45 |
| `printjob_props_swf6` | output_mismatch | 45/45 | 40/45 |
| `printjob_props_swf7` | output_mismatch | 45/45 | 40/45 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_stylesheet` | output_mismatch | 298/325 | 301/325 | -3 |
| `clone_sprite_edittext` | output_mismatch | 25/94 | 26/94 | -1 |
| `clone_sprite_edittext_dynamic` | output_mismatch | 51/86 | 52/86 | -1 |
