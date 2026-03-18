# Ruffle Test Results Diff

**Previous:** `70988e2fb2c2` (2026-03-17T21:00:39.492066+00:00)
**Current:** `ef1e80b3a44d` (2026-03-18T04:04:37.073700+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 562 | 553 | -9 |
| Total | 619 | 619 | 0 |
| Pass rate | 90.8% | 89.3% | -1.5% |
| Mismatched lines | 12910 | 12996 | +86 |
|   Decreased | | | -1 |
|   Increased | | | +87 |

## Newly Failing (9)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `bad_placeobject_clipaction` | output_mismatch | 2/2 | 0/2 |
| `clip_events` | output_mismatch | 19/19 | 1/19 |
| `drag_drop` | output_mismatch | 10/10 | 0/10 |
| `duplicate_movie_clip` | output_mismatch | 20/20 | 16/20 |
| `issue_1104` | output_mismatch | 2/2 | 0/2 |
| `issue_2870` | output_mismatch | 3/3 | 0/3 |
| `on_construct` | output_mismatch | 25/25 | 8/25 |
| `unload` | output_mismatch | 52/52 | 25/52 |
| `unload_clip_event` | output_mismatch | 4/4 | 0/4 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_hittest_shapeflag` | output_mismatch | 311/338 | 312/338 | -1 |
