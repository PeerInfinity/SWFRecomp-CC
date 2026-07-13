# Ruffle Test Results Diff

**Previous:** `b4db40f98904` (2026-07-13T04:25:24.239077+00:00)
**Current:** `b5695059b2cd` (2026-07-13T05:09:06.996464+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 809 | 819 | +10 |
| Total | 1204 | 1204 | 0 |
| Pass rate | 67.2% | 68.0% | +0.8% |
| Mismatched lines | 47865 | 47838 | -27 |
|   Decreased | | | -27 |

## Newly Passing (10)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `callee_in_initializer` | output_mismatch | 5/6 | 6/6 |
| `movieclip_currentlabels` | output_mismatch | 16/17 | 17/17 |
| `movieclip_currentlabels_dupes1` | output_mismatch | 45/46 | 46/46 |
| `movieclip_currentlabels_dupes2` | output_mismatch | 28/30 | 30/30 |
| `movieclip_currentlabels_dupes3` | output_mismatch | 54/67 | 67/67 |
| `movieclip_currentscene` | output_mismatch | 8/12 | 12/12 |
| `movieclip_goto_scene_last_frame_int` | output_mismatch | 0/1 | 1/1 |
| `movieclip_goto_scene_last_frame_label` | output_mismatch | 0/1 | 1/1 |
| `movieclip_prev_scene` | output_mismatch | 4/7 | 7/7 |
| `supercall_two_classobjects` | segfault | - | 2/2 |
