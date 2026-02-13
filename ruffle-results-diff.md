# Ruffle Test Results Diff

**Previous:** `48407dff585d` (2026-02-13T00:53:24.475880+00:00)
**Current:** `28a85fbf831e` (2026-02-13T01:01:02.041564+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 102 | 105 | +3 |
| Total | 616 | 616 | 0 |
| Pass rate | 16.6% | 17.0% | +0.4% |
| Mismatched lines | 56963 | 57088 | +125 |
|   Decreased | | | -27 |
|   Increased | | | +152 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `init_array_invalid` | output_mismatch | 0/4 | 4/4 |
| `init_object_invalid` | output_mismatch | 0/4 | 4/4 |
| `netstream_play_flv_screen` | segfault | - | 0/0 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `as2_oop` | segfault | output_mismatch | - | 0/13 |
| `extends_chain` | segfault | output_mismatch | - | 0/134 |
| `issue_2166` | segfault | output_mismatch | - | 4/9 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_html_roundtrip` | output_mismatch | 0/17 | 11/17 | -11 |
| `named_shapes` | output_mismatch | 0/14 | 5/14 | -5 |
| `watch_textfield` | output_mismatch | 0/12 | 2/12 | -2 |
| `new_object_wrap` | output_mismatch | 0/4 | 1/4 | -1 |
| `new_method_wrap` | output_mismatch | 0/4 | 0/4 | 0 |
