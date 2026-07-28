# Ruffle Test Results Diff

**Previous:** `b279092977b5` (2026-07-28T19:19:07.864374+00:00)
**Current:** `bbefcf37694e` (2026-07-28T21:16:22.811567+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 894 | 900 | +6 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 73.2% | 73.7% | +0.5% |
| Mismatched lines | 45392 | 44390 | -1002 |
|   Decreased | | | -1002 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_ime_focus_lost` | output_mismatch | 0/9 | 9/9 |
| `focus_events_key_navigation` | output_mismatch | 12/53 | 53/53 |
| `focus_events_mouse_basic` | output_mismatch | 30/260 | 260/260 |
| `focus_events_mouse_focusable` | output_mismatch | 110/112 | 112/112 |
| `ime_linux_dead_keys` | output_mismatch | 0/10 | 10/10 |
| `textfield_event` | output_mismatch | 0/66 | 66/66 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `tab_ordering_arrows` | output_mismatch | 1/998 | 645/998 | -644 |
| `focus_events_mixed_avm_edittext` | output_mismatch | 1/49 | 1/49 | 0 |
