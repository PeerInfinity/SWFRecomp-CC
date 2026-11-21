# Ruffle Test Results Diff

**Previous:** `bc91565cea8e` (2026-11-21T19:30:16.414972+00:00)
**Current:** `c489b84d9946` (2026-11-21T19:49:24.040284+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1480 | 1533 | +53 |
| Total | 1521 | 1574 | +53 |
| Pass rate | 97.3% | 97.4% | +0.1% |
| Mismatched lines | 424 | 428 | +4 |
|   Decreased | | | -3 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl` | output_mismatch | 0/1 | 1/1 |
| `regress/bug_478501` | output_mismatch | 0/1 | 1/1 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `e4x/XML/misc_errors` | output_mismatch | ruffle_matched | 31/33 | 32/33 |

## Added Tests (53)

| Test | Status | Lines |
|------|--------|-------|
| `e4x/Types/e9_2_1_10` | pass | 2/2 |
| `e4x/Types/e9_2_1_2` | pass | 19/19 |
| `e4x/Types/e9_2_1_3` | pass | 2/2 |
| `e4x/Types/e9_2_1_4` | pass | 2/2 |
| `e4x/Types/e9_2_1_5` | pass | 2/2 |
| `e4x/Types/e9_2_1_6` | pass | 2/2 |
| `e4x/Types/e9_2_1_7` | pass | 2/2 |
| `e4x/Types/e9_2_1_8` | pass | 2/2 |
| `e4x/Types/e9_2_1_9` | pass | 11/11 |
| `e4x/XML/bug157597` | pass | 2/2 |
| `e4x/XML/bug157597_2` | pass | 2/2 |
| `e4x/XML/bug157735` | pass | 2/2 |
| `e4x/XML/bug158506` | pass | 2/2 |
| `e4x/XML/bug_564468` | ruffle_matched | 6/10 |
| `e4x/XML/e13_4_1` | pass | 18/18 |
| `e4x/XML/e13_4_2` | pass | 36/36 |
| `e4x/XML/e13_4_3` | pass | 35/35 |
| `e4x/XML/e13_4_3_1` | pass | 5/5 |
| `e4x/XML/e13_4_3_2` | pass | 8/8 |
| `e4x/XML/e13_4_3_3` | pass | 8/8 |
| `e4x/XML/e13_4_3_4` | pass | 11/11 |
| `e4x/XML/e13_4_3_5` | pass | 5/5 |
| `e4x/XML/e13_4_3_6` | pass | 10/10 |
| `e4x/XML/e13_4_3_7` | pass | 31/31 |
| `e4x/XML/e13_4_3_8` | pass | 41/41 |
| `e4x/XML/e13_4_3_9` | pass | 11/11 |
| `e4x/XML/e13_4_4_1` | pass | 3/3 |
| `e4x/XML/e13_4_4_10` | pass | 11/11 |
| `e4x/XML/e13_4_4_11` | pass | 12/12 |
| `e4x/XML/e13_4_4_12` | pass | 15/15 |
| `e4x/XML/e13_4_4_13` | pass | 7/7 |
| `e4x/XML/e13_4_4_14` | pass | 12/12 |
| `e4x/XML/e13_4_4_15` | pass | 16/16 |
| `e4x/XML/e13_4_4_16` | pass | 25/25 |
| `e4x/XML/e13_4_4_17` | pass | 19/19 |
| `e4x/XML/e13_4_4_18` | pass | 16/16 |
| `e4x/XML/e13_4_4_19` | pass | 16/16 |
| `e4x/XML/e13_4_4_2` | pass | 15/15 |
| `e4x/XML/e13_4_4_20` | pass | 11/11 |
| `e4x/XML/e13_4_4_21` | pass | 16/16 |
| `e4x/XML/e13_4_4_22` | pass | 15/15 |
| `e4x/XML/e13_4_4_23` | pass | 17/17 |
| `e4x/XML/e13_4_4_24` | pass | 22/22 |
| `e4x/XML/e13_4_4_25` | pass | 15/15 |
| `e4x/XML/e13_4_4_26` | pass | 6/6 |
| `e4x/XML/e13_4_4_27` | pass | 21/21 |
| `e4x/XML/e13_4_4_28` | pass | 13/13 |
| `e4x/XML/e13_4_4_29/v10` | pass | 19/19 |
| `e4x/XML/e13_4_4_29/v9` | pass | 19/19 |
| `e4x/XML/e13_4_4_3/v10` | pass | 16/16 |
| `e4x/XML/e13_4_4_3/v21` | pass | 16/16 |
| `e4x/XML/e13_4_4_3/v9` | pass | 16/16 |
| `e4x/XML/e13_4_4_30` | ruffle_matched | 8/11 |
