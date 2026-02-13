# Ruffle Test Results Diff

**Previous:** `98b84df5264b` (2026-02-12T22:25:15.901840+00:00)
**Current:** `bf6dde7673da` (2026-02-12T23:53:08.116464+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 101 | 101 | 0 |
| Total | 616 | 616 | 0 |
| Pass rate | 16.4% | 16.4% | 0% |
| Mismatched lines | 56406 | 57003 | +597 |
|   Increased | | | +597 |

## Status Changed (7)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `clip_constructors` | segfault | output_mismatch | - | 0/8 |
| `init_object_order` | segfault | output_mismatch | - | 0/15 |
| `loadmovie_registerclass` | segfault | output_mismatch | - | 0/30 |
| `movieclip_hittest_shapeflag` | compile_fail | output_mismatch | - | 10/338 |
| `register_and_init_order` | segfault | output_mismatch | - | 35/231 |
| `resolve_different_root` | segfault | output_mismatch | - | 0/2 |
| `timer_run_actions` | segfault | output_mismatch | - | 0/18 |
