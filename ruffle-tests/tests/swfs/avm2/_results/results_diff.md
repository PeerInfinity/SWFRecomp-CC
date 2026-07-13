# Ruffle Test Results Diff

**Previous:** `8c4e8518e97f` (2026-07-13T02:28:38.890548+00:00)
**Current:** `b4db40f98904` (2026-07-13T04:25:24.239077+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 819 | 809 | -10 |
| Total | 1204 | 1204 | 0 |
| Pass rate | 68.0% | 67.2% | -0.8% |
| Mismatched lines | 47838 | 47865 | +27 |
|   Increased | | | +27 |

## Newly Failing (10)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `callee_in_initializer` | output_mismatch | 6/6 | 5/6 |
| `movieclip_currentlabels` | output_mismatch | 17/17 | 16/17 |
| `movieclip_currentlabels_dupes1` | output_mismatch | 46/46 | 45/46 |
| `movieclip_currentlabels_dupes2` | output_mismatch | 30/30 | 28/30 |
| `movieclip_currentlabels_dupes3` | output_mismatch | 67/67 | 54/67 |
| `movieclip_currentscene` | output_mismatch | 12/12 | 8/12 |
| `movieclip_goto_scene_last_frame_int` | output_mismatch | 1/1 | 0/1 |
| `movieclip_goto_scene_last_frame_label` | output_mismatch | 1/1 | 0/1 |
| `movieclip_prev_scene` | output_mismatch | 7/7 | 4/7 |
| `supercall_two_classobjects` | segfault | 2/2 | - |
