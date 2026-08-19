# Ruffle Test Results Diff

**Previous:** `aeebf9ede383` (2026-08-15T10:09:49.264760+00:00)
**Current:** `9d038c750eaf` (2026-08-19T13:54:51.753776+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1515 | 1485 | -30 |
| Total | 1574 | 1522 | -52 |
| Pass rate | 96.3% | 97.6% | +1.3% |
| Mismatched lines | 578 | 320 | -258 |
|   Decreased | | | -16 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/Expressions/asOperator/asOper` | ruffle_matched | 332/334 | 334/334 |
| `ecma3/Array/e15_4_4_5` | ruffle_matched | 14/15 | 15/15 |
| `ecma3/Array/toLocaleString` | ruffle_matched | 13/14 | 14/14 |
| `ecma3/Number/e15_7_1` | ruffle_matched | 45/46 | 46/46 |
| `ecma3/Number/e15_7_2` | ruffle_matched | 86/87 | 87/87 |
| `ecma3/Number/e15_7_4_2_4` | ruffle_matched | 50/51 | 51/51 |
| `ecma3/Number/toLocaleString_rt` | ruffle_matched | 47/48 | 48/48 |
| `ecma3/Number/tostring_001` | ruffle_matched | 1/3 | 3/3 |
| `ecma3/String/e15_5_1` | ruffle_matched | 48/49 | 49/49 |
| `ecma3/String/e15_5_2` | ruffle_matched | 74/75 | 75/75 |
| `ecma3/TypeConversion/e9_8_1` | ruffle_matched | 38/39 | 39/39 |
| `ecma3/Types/e8_5` | ruffle_matched | 19/22 | 22/22 |

## Missing Tests — Shard Failure (52)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 42 were previously passing
- 10 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `ecma3/Date/e15_9_5_1` | pass | 1/1 |
| `ecma3/Date/e15_9_5_10` | ruffle_matched | 118/121 |
| `ecma3/Date/e15_9_5_10_1` | ruffle_matched | 0/33 |
| `ecma3/Date/e15_9_5_10_10` | ruffle_matched | 2/33 |
| `ecma3/Date/e15_9_5_10_11` | ruffle_matched | 2/95 |
| `ecma3/Date/e15_9_5_10_12` | pass | 64/64 |
| `ecma3/Date/e15_9_5_10_13` | pass | 33/33 |
| `ecma3/Date/e15_9_5_10_3` | pass | 31/31 |
| `ecma3/Date/e15_9_5_10_4` | pass | 31/31 |
| `ecma3/Date/e15_9_5_10_5` | pass | 31/31 |
| `ecma3/Date/e15_9_5_10_6` | pass | 32/32 |
| `ecma3/Date/e15_9_5_10_7` | pass | 31/31 |
| `ecma3/Date/e15_9_5_10_8` | pass | 33/33 |
| `ecma3/Date/e15_9_5_10_9` | pass | 33/33 |
| `ecma3/Date/e15_9_5_11` | ruffle_matched | 30/33 |
| `ecma3/Date/e15_9_5_11_1` | pass | 55/55 |
| `ecma3/Date/e15_9_5_11_3` | pass | 55/55 |
| `ecma3/Date/e15_9_5_11_4` | pass | 55/55 |
| `ecma3/Date/e15_9_5_11_5` | pass | 55/55 |
| `ecma3/Date/e15_9_5_11_6` | pass | 55/55 |
| `ecma3/Date/e15_9_5_11_7` | pass | 55/55 |
| `ecma3/Date/e15_9_5_12` | ruffle_matched | 30/33 |
| `ecma3/Date/e15_9_5_12_1` | ruffle_matched | 0/67 |
| `ecma3/Date/e15_9_5_12_3` | pass | 67/67 |
| `ecma3/Date/e15_9_5_12_4` | pass | 67/67 |
| `ecma3/Date/e15_9_5_12_5` | pass | 67/67 |
| `ecma3/Date/e15_9_5_12_6` | pass | 55/55 |
| `ecma3/Date/e15_9_5_12_7` | pass | 67/67 |
| `ecma3/Date/e15_9_5_12_8` | pass | 2/2 |
| `ecma3/Date/e15_9_5_13` | ruffle_matched | 30/33 |
| `ecma3/Date/e15_9_5_13_1` | pass | 36/36 |
| `ecma3/Date/e15_9_5_13_2` | pass | 36/36 |
| `ecma3/Date/e15_9_5_13_3` | pass | 36/36 |
| `ecma3/Date/e15_9_5_13_4` | pass | 36/36 |
| `ecma3/Date/e15_9_5_13_5` | pass | 36/36 |
| `ecma3/Date/e15_9_5_13_6` | pass | 60/60 |
| `ecma3/Date/e15_9_5_13_7` | pass | 60/60 |
| `ecma3/Date/e15_9_5_13_8` | pass | 2/2 |
| `ecma3/Date/e15_9_5_14` | pass | 44/44 |
| `ecma3/Date/e15_9_5_15` | pass | 58/58 |
| `ecma3/Date/e15_9_5_15_1` | ruffle_matched | 30/33 |
| `ecma3/Date/e15_9_5_16` | pass | 51/51 |
| `ecma3/Date/e15_9_5_17` | pass | 51/51 |
| `ecma3/Date/e15_9_5_17_1` | ruffle_matched | 30/33 |
| `ecma3/Date/e15_9_5_18` | pass | 51/51 |
| `ecma3/Date/e15_9_5_19` | pass | 51/51 |
| `ecma3/Date/e15_9_5_2` | pass | 15/15 |
| `ecma3/Date/e15_9_5_20` | pass | 79/79 |
| `ecma3/Date/e15_9_5_21_1` | pass | 9/9 |
| `ecma3/Date/e15_9_5_21_2` | pass | 1/1 |
| `ecma3/Date/e15_9_5_21_3` | pass | 1/1 |
| `ecma3/Date/e15_9_5_21_4` | pass | 1/1 |

</details>
