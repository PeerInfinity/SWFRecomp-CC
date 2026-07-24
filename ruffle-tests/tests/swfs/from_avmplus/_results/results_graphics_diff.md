# Ruffle Test Results Diff

**Previous:** `e6f33267e7f3` (2026-07-24T18:56:22.059041+00:00)
**Current:** `d36c8da2b2bd` (2026-07-24T20:26:59.066115+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 847 | 974 | +127 |
| Total | 1574 | 1522 | -52 |
| Pass rate | 53.8% | 64.0% | +10.2% |
| Mismatched lines | 18826 | 17269 | -1557 |
|   Decreased | | | -168 |

## Newly Passing (156)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/Vector/concat` | output_mismatch | 9/10 | 10/10 |
| `e4x/Expressions/e11_1_3` | output_mismatch | 7/8 | 8/8 |
| `e4x/Expressions/e11_1_5` | output_mismatch | 16/17 | 17/17 |
| `e4x/Expressions/e11_2_1` | output_mismatch | 39/40 | 40/40 |
| `e4x/Expressions/e11_2_2` | output_mismatch | 23/24 | 24/24 |
| `e4x/Expressions/e11_2_3` | output_mismatch | 9/10 | 10/10 |
| `e4x/Expressions/e11_2_4` | output_mismatch | 14/15 | 15/15 |
| `e4x/Expressions/e11_3_2` | output_mismatch | 6/7 | 7/7 |
| `e4x/Expressions/e11_4_1` | output_mismatch | 17/18 | 18/18 |
| `e4x/Expressions/e11_5_1` | output_mismatch | 65/66 | 66/66 |
| `e4x/Expressions/e11_6_1` | output_mismatch | 18/19 | 19/19 |
| `e4x/Expressions/e11_6_2` | output_mismatch | 14/15 | 15/15 |
| `e4x/Expressions/e11_6_3` | output_mismatch | 5/6 | 6/6 |
| `e4x/Expressions/kXMLBadQNameErr` | output_mismatch | 4/5 | 5/5 |
| `e4x/Namespace/e13_2_1` | output_mismatch | 18/19 | 19/19 |
| `e4x/Namespace/e13_2_2` | output_mismatch | 21/22 | 22/22 |
| `e4x/Namespace/e13_2_3_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/Namespace/e13_2_4_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/Namespace/e13_2_4_2` | output_mismatch | 3/4 | 4/4 |
| `e4x/QName/e13_3_1` | output_mismatch | 21/22 | 22/22 |
| `e4x/QName/e13_3_3_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/QName/e13_3_4_1` | output_mismatch | 1/2 | 2/2 |
| `e4x/QName/e13_3_4_2` | output_mismatch | 3/4 | 4/4 |
| `e4x/QName/e13_3_5` | output_mismatch | 12/13 | 13/13 |
| `e4x/Regress/b121219` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/error1085` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-257679` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-263934` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-263936` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-264369` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-271545` | output_mismatch | 5/6 | 6/6 |
| `e4x/Regress/regress-277650` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-277664` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-277683` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-277779` | output_mismatch | 1/2 | 2/2 |
| `e4x/Regress/regress-278112` | output_mismatch | 3/4 | 4/4 |
| `e4x/Statements/e12_2` | output_mismatch | 13/14 | 14/14 |
| `e4x/Statements/e12_3` | output_mismatch | 4/5 | 5/5 |
| `e4x/TypeConversion/bug153363` | output_mismatch | 2/3 | 3/3 |
| `e4x/TypeConversion/bug153363_2` | output_mismatch | 2/3 | 3/3 |
| `e4x/TypeConversion/e10_1_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/TypeConversion/e10_1_2` | output_mismatch | 4/5 | 5/5 |
| `e4x/TypeConversion/e10_2_1` | output_mismatch | 4/5 | 5/5 |
| `e4x/TypeConversion/e10_2_1_1` | output_mismatch | 4/5 | 5/5 |
| `e4x/TypeConversion/e10_2_1_2` | output_mismatch | 12/13 | 13/13 |
| `e4x/TypeConversion/e10_2_2` | output_mismatch | 1/2 | 2/2 |
| `e4x/TypeConversion/e10_3` | output_mismatch | 6/7 | 7/7 |
| `e4x/TypeConversion/e10_3_1` | output_mismatch | 1/2 | 2/2 |
| `e4x/TypeConversion/e10_4` | output_mismatch | 8/9 | 9/9 |
| `e4x/TypeConversion/e10_4_1` | output_mismatch | 7/8 | 8/8 |
| `e4x/Types/e9_1_1_1` | output_mismatch | 31/32 | 32/32 |
| `e4x/Types/e9_1_1_10` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_11` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_12` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_13` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_2` | output_mismatch | 5/6 | 6/6 |
| `e4x/Types/e9_1_1_3` | output_mismatch | 4/5 | 5/5 |
| `e4x/Types/e9_1_1_4` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_5` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_6` | output_mismatch | 10/11 | 11/11 |
| `e4x/Types/e9_1_1_7` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_8` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_1_1_9` | output_mismatch | 19/20 | 20/20 |
| `e4x/Types/e9_2_1_1` | output_mismatch | 10/11 | 11/11 |
| `e4x/Types/e9_2_1_10` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_2` | output_mismatch | 18/19 | 19/19 |
| `e4x/Types/e9_2_1_3` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_4` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_5` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_6` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_7` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_8` | output_mismatch | 1/2 | 2/2 |
| `e4x/Types/e9_2_1_9` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/bug157597` | output_mismatch | 1/2 | 2/2 |
| `e4x/XML/bug157597_2` | output_mismatch | 1/2 | 2/2 |
| `e4x/XML/bug157735` | output_mismatch | 1/2 | 2/2 |
| `e4x/XML/bug158506` | output_mismatch | 1/2 | 2/2 |
| `e4x/XML/e13_4_1` | output_mismatch | 17/18 | 18/18 |
| `e4x/XML/e13_4_2` | output_mismatch | 35/36 | 36/36 |
| `e4x/XML/e13_4_3` | output_mismatch | 34/35 | 35/35 |
| `e4x/XML/e13_4_3_1` | output_mismatch | 4/5 | 5/5 |
| `e4x/XML/e13_4_3_2` | output_mismatch | 7/8 | 8/8 |
| `e4x/XML/e13_4_3_3` | output_mismatch | 7/8 | 8/8 |
| `e4x/XML/e13_4_3_4` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/e13_4_3_5` | output_mismatch | 4/5 | 5/5 |
| `e4x/XML/e13_4_3_6` | output_mismatch | 9/10 | 10/10 |
| `e4x/XML/e13_4_3_7` | output_mismatch | 30/31 | 31/31 |
| `e4x/XML/e13_4_3_8` | output_mismatch | 40/41 | 41/41 |
| `e4x/XML/e13_4_3_9` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/e13_4_4_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/XML/e13_4_4_10` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/e13_4_4_11` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_12` | output_mismatch | 14/15 | 15/15 |
| `e4x/XML/e13_4_4_13` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/e13_4_4_14` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_15` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_16` | output_mismatch | 24/25 | 25/25 |
| `e4x/XML/e13_4_4_18` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_19` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_20` | output_mismatch | 10/11 | 11/11 |
| `e4x/XML/e13_4_4_21` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_22` | output_mismatch | 14/15 | 15/15 |
| `e4x/XML/e13_4_4_23` | output_mismatch | 16/17 | 17/17 |
| `e4x/XML/e13_4_4_24` | output_mismatch | 21/22 | 22/22 |
| `e4x/XML/e13_4_4_25` | output_mismatch | 14/15 | 15/15 |
| `e4x/XML/e13_4_4_26` | output_mismatch | 5/6 | 6/6 |
| `e4x/XML/e13_4_4_27` | output_mismatch | 20/21 | 21/21 |
| `e4x/XML/e13_4_4_29/v10` | output_mismatch | 18/19 | 19/19 |
| `e4x/XML/e13_4_4_29/v9` | output_mismatch | 18/19 | 19/19 |
| `e4x/XML/e13_4_4_3/v10` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_3/v21` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_3/v9` | output_mismatch | 15/16 | 16/16 |
| `e4x/XML/e13_4_4_31` | output_mismatch | 18/19 | 19/19 |
| `e4x/XML/e13_4_4_32/v10` | output_mismatch | 8/9 | 9/9 |
| `e4x/XML/e13_4_4_33` | output_mismatch | 5/6 | 6/6 |
| `e4x/XML/e13_4_4_34` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_35` | output_mismatch | 16/17 | 17/17 |
| `e4x/XML/e13_4_4_37` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_38` | output_mismatch | 16/17 | 17/17 |
| `e4x/XML/e13_4_4_39` | output_mismatch | 19/20 | 20/20 |
| `e4x/XML/e13_4_4_4` | output_mismatch | 18/19 | 19/19 |
| `e4x/XML/e13_4_4_40` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/e13_4_4_5` | output_mismatch | 11/12 | 12/12 |
| `e4x/XML/e13_4_4_6` | output_mismatch | 30/31 | 31/31 |
| `e4x/XML/e13_4_4_7` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/e13_4_4_8` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/e13_4_4_9` | output_mismatch | 13/14 | 14/14 |
| `e4x/XML/kXMLAssignmentToIndexedXMLNotAllowedErr` | output_mismatch | 2/3 | 3/3 |
| `e4x/XML/kXMLMarkupMustBeWellFormedErr` | output_mismatch | 2/3 | 3/3 |
| `e4x/XML/kXMLPrefixNotBoundErr` | output_mismatch | 6/7 | 7/7 |
| `e4x/XML/kXMLUnterminatedElementTagErr` | output_mismatch | 4/5 | 5/5 |
| `e4x/XMLList/bug157735` | output_mismatch | 1/2 | 2/2 |
| `e4x/XMLList/e13_5_1` | output_mismatch | 25/26 | 26/26 |
| `e4x/XMLList/e13_5_2` | output_mismatch | 36/37 | 37/37 |
| `e4x/XMLList/e13_5_3_1` | output_mismatch | 4/5 | 5/5 |
| `e4x/XMLList/e13_5_4_1` | output_mismatch | 2/3 | 3/3 |
| `e4x/XMLList/e13_5_4_10` | output_mismatch | 6/7 | 7/7 |
| `e4x/XMLList/e13_5_4_11` | output_mismatch | 12/13 | 13/13 |
| `e4x/XMLList/e13_5_4_12` | output_mismatch | 18/19 | 19/19 |
| `e4x/XMLList/e13_5_4_13` | output_mismatch | 27/28 | 28/28 |
| `e4x/XMLList/e13_5_4_14` | output_mismatch | 10/11 | 11/11 |
| `e4x/XMLList/e13_5_4_15` | output_mismatch | 2/3 | 3/3 |
| `e4x/XMLList/e13_5_4_16` | output_mismatch | 23/24 | 24/24 |
| `e4x/XMLList/e13_5_4_19` | output_mismatch | 4/5 | 5/5 |
| `e4x/XMLList/e13_5_4_2` | output_mismatch | 27/28 | 28/28 |
| `e4x/XMLList/e13_5_4_20` | output_mismatch | 11/12 | 12/12 |
| `e4x/XMLList/e13_5_4_21` | output_mismatch | 11/12 | 12/12 |
| `e4x/XMLList/e13_5_4_22` | output_mismatch | 4/5 | 5/5 |
| `e4x/XMLList/e13_5_4_3` | output_mismatch | 15/16 | 16/16 |
| `e4x/XMLList/e13_5_4_4` | output_mismatch | 38/39 | 39/39 |
| `e4x/XMLList/e13_5_4_5` | output_mismatch | 10/11 | 11/11 |
| `e4x/XMLList/e13_5_4_6` | output_mismatch | 5/6 | 6/6 |
| `e4x/XMLList/e13_5_4_7` | output_mismatch | 5/6 | 6/6 |
| `e4x/XMLList/e13_5_4_8` | output_mismatch | 10/11 | 11/11 |
| `e4x/XMLList/e13_5_4_9` | output_mismatch | 9/10 | 10/10 |
| `e4x/XMLList/kXMLOnlyWorksWithOneItemListsErr` | output_mismatch | 28/29 | 29/29 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `e4x/XML/e13_4_4_30` | output_mismatch | ruffle_matched | 7/11 | 8/11 |
| `e4x/XML/misc_errors` | output_mismatch | ruffle_matched | 30/33 | 31/33 |
| `e4x/XMLList/e13_5_4_18` | output_mismatch | ruffle_matched | 2/5 | 3/5 |

## Missing Tests — Shard Failure (52)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 29 were previously passing
- 23 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `ecma3/Statements/etry_008` | pass | 6/6 |
| `ecma3/Statements/etry_009` | pass | 2/2 |
| `ecma3/Statements/etry_010` | pass | 4/4 |
| `ecma3/Statements/etry_012` | pass | 9/9 |
| `ecma3/Statements/ewhile_001` | pass | 1/1 |
| `ecma3/Statements/ewhile_002` | pass | 8/8 |
| `ecma3/Statements/ewhile_003` | pass | 10/10 |
| `ecma3/Statements/ewhile_004` | pass | 13/13 |
| `ecma3/Statements/expression` | pass | 1/1 |
| `ecma3/Statements/throw` | pass | 2/2 |
| `ecma3/String/Split` | pass | 19/19 |
| `ecma3/String/concat` | output_mismatch | 0/21 |
| `ecma3/String/e15_5_1` | ruffle_matched | 48/49 |
| `ecma3/String/e15_5_2` | output_mismatch | 69/75 |
| `ecma3/String/e15_5_3` | output_mismatch | 1/2 |
| `ecma3/String/e15_5_3_1_1` | pass | 2/2 |
| `ecma3/String/e15_5_3_1_2` | pass | 1/1 |
| `ecma3/String/e15_5_3_1_3` | output_mismatch | 0/1 |
| `ecma3/String/e15_5_3_1_4` | pass | 1/1 |
| `ecma3/String/e15_5_3_2_1` | pass | 116/116 |
| `ecma3/String/e15_5_3_2_2` | pass | 2/2 |
| `ecma3/String/e15_5_3_2_3` | output_mismatch | 474/481 |
| `ecma3/String/e15_5_4` | output_mismatch | 3/6 |
| `ecma3/String/e15_5_4_10_1_rt` | output_mismatch | 0/24 |
| `ecma3/String/e15_5_4_11_1` | output_mismatch | 0/387 |
| `ecma3/String/e15_5_4_11_2` | pass | 96/96 |
| `ecma3/String/e15_5_4_11_3` | pass | 240/240 |
| `ecma3/String/e15_5_4_11_4` | pass | 96/96 |
| `ecma3/String/e15_5_4_11_5` | output_mismatch | 0/131 |
| `ecma3/String/e15_5_4_11_6` | pass | 96/96 |
| `ecma3/String/e15_5_4_12_1` | output_mismatch | 0/387 |
| `ecma3/String/e15_5_4_12_2` | pass | 1/1 |
| `ecma3/String/e15_5_4_12_3` | pass | 864/864 |
| `ecma3/String/e15_5_4_12_4` | pass | 128/128 |
| `ecma3/String/e15_5_4_12_5` | pass | 96/96 |
| `ecma3/String/e15_5_4_13` | output_mismatch | 0/17 |
| `ecma3/String/e15_5_4_1_rt` | pass | 2/2 |
| `ecma3/String/e15_5_4_2_1` | output_mismatch | 5/6 |
| `ecma3/String/e15_5_4_2_3` | pass | 4/4 |
| `ecma3/String/e15_5_4_2_rt` | output_mismatch | 7/8 |
| `ecma3/String/e15_5_4_3_1` | output_mismatch | 6/7 |
| `ecma3/String/e15_5_4_3_2` | pass | 4/4 |
| `ecma3/String/e15_5_4_3_3_rt` | pass | 1/1 |
| `ecma3/String/e15_5_4_4_1` | output_mismatch | 188/189 |
| `ecma3/String/e15_5_4_4_2` | output_mismatch | 6/33 |
| `ecma3/String/e15_5_4_4_3` | output_mismatch | 0/18 |
| `ecma3/String/e15_5_4_4_4_rt` | output_mismatch | 28/52 |
| `ecma3/String/e15_5_4_5_1` | pass | 95/95 |
| `ecma3/String/e15_5_4_5_2` | output_mismatch | 0/31 |
| `ecma3/String/e15_5_4_5_3` | output_mismatch | 0/28 |
| `ecma3/String/e15_5_4_5_4` | output_mismatch | 321/323 |
| `ecma3/String/e15_5_4_5_5` | output_mismatch | 0/269 |

</details>

## Line Count Changed (16)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `as3/Vector/initializer_expressions` | output_mismatch | 39/41 | 40/41 | -1 |
| `e4x/Expressions/e11_1_1` | output_mismatch | 34/39 | 35/39 | -1 |
| `e4x/QName/e13_3_2` | output_mismatch | 47/49 | 48/49 | -1 |
| `e4x/Statements/e12_1` | output_mismatch | 10/17 | 11/17 | -1 |
| `e4x/XML/e13_4_4_17` | output_mismatch | 17/19 | 18/19 | -1 |
| `e4x/XML/e13_4_4_28` | output_mismatch | 11/13 | 12/13 | -1 |
| `e4x/XML/e13_4_4_32/v9` | output_mismatch | 7/9 | 8/9 | -1 |
| `e4x/XML/e13_4_4_36` | output_mismatch | 12/16 | 13/16 | -1 |
| `e4x/XMLList/e13_5_4_17` | output_mismatch | 8/10 | 9/10 | -1 |
| `e4x/Expressions/e11_1_2` | output_mismatch | 12/20 | 12/20 | 0 |
| `e4x/Expressions/e11_1_4` | output_mismatch | 14/34 | 14/34 | 0 |
| `e4x/Expressions/e11_3_1` | output_mismatch | 10/20 | 10/20 | 0 |
| `e4x/Global/isXMLNameTypeErr` | output_mismatch | 0/5 | 0/5 | 0 |
| `e4x/Regress/regress-263935` | output_mismatch | 0/2 | 0/2 | 0 |
| `e4x/XML/e13_4_4_2` | output_mismatch | 4/15 | 4/15 | 0 |
| `e4x/XML/setNotification` | ruffle_matched | 6/19 | 6/19 | 0 |
