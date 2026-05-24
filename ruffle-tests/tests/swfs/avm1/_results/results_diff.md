# Ruffle Test Results Diff

**Previous:** `aa5b2b51e8bb` (2026-05-24T04:10:51.492288+00:00)
**Current:** `5cf301c4e41c` (2026-05-24T18:26:23.948013+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 611 | 613 | +2 |
| Total | 662 | 671 | +9 |
| Pass rate | 92.3% | 91.4% | -0.9% |
| Mismatched lines | 9096 | 9565 | +469 |
|   Increased | | | +3 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_restrict` | output_mismatch | 191/191 | 190/191 |
| `with` | output_mismatch | 49/49 | 44/46 |

## Added Tests (9)

| Test | Status | Lines |
|------|--------|-------|
| `geturl_opcode_target_normalize` | output_mismatch | 0/45 |
| `geturl_target_normalize` | output_mismatch | 4/89 |
| `looping_child_swf32` | output_mismatch | 29/141 |
| `looping_child_swf5` | output_mismatch | 29/141 |
| `looping_child_swf9` | output_mismatch | 29/141 |
| `looping_real_1_declared_1` | pass | 1/1 |
| `looping_real_1_declared_2` | pass | 1/1 |
| `looping_real_2_declared_1` | pass | 5/5 |
| `looping_real_2_declared_2` | pass | 5/5 |
