# Ruffle Test Results Diff

**Previous:** `38aa0a3009e5` (2026-07-28T04:41:17.073494+00:00)
**Current:** `9263f71a0bfa` (2026-07-28T17:38:01.727650+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 876 | 886 | +10 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 71.7% | 72.6% | +0.9% |
| Mismatched lines | 45660 | 45483 | -177 |
|   Decreased | | | -177 |

## Newly Passing (10)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `focus_events_key_basic` | output_mismatch | 33/132 | 132/132 |
| `focusrect_focuslost` | output_mismatch | 7/9 | 9/9 |
| `focusrect_property` | output_mismatch | 104/110 | 110/110 |
| `mouse_wheel_events` | output_mismatch | 33/36 | 36/36 |
| `mouseevent_constr` | output_mismatch | 62/66 | 66/66 |
| `mouseevent_stagexy` | output_mismatch | 1/35 | 35/35 |
| `mouseevent_valueof_tostring` | output_mismatch | 24/28 | 28/28 |
| `tab_ordering_stage_tab_children` | output_mismatch | 15/32 | 32/32 |
| `tab_ordering_stage_tab_children_remove_root` | output_mismatch | 3/5 | 5/5 |
| `tab_ordering_tabbable` | output_mismatch | 45/47 | 47/47 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `mouse_pick_masking` | output_mismatch | 0/7 | 2/7 | -2 |
| `tab_ordering_properties` | output_mismatch | 559/732 | 561/732 | -2 |
