# Ruffle Test Results Diff

**Previous:** `127a5f4d39dc` (2026-07-24T21:33:55.044873+00:00)
**Current:** `2cf4014fd672` (2026-07-24T22:06:49.333028+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1104 | 1135 | +31 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 70.1% | 72.1% | +2.0% |
| Mismatched lines | 17149 | 13173 | -3976 |
|   Decreased | | | -3976 |

## Newly Passing (31)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `ecma3/Array/e15_4_4_10` | output_mismatch | 5/6 | 6/6 |
| `ecma3/Array/e15_4_4_13` | output_mismatch | 0/7 | 7/7 |
| `ecma3/Array/e15_4_4_4_1` | output_mismatch | 0/1046 | 1046/1046 |
| `ecma3/Array/e15_4_4_4_2` | output_mismatch | 0/4 | 4/4 |
| `ecma3/GlobalObject/e15_1_2_2_1` | output_mismatch | 274/276 | 276/276 |
| `ecma3/GlobalObject/e15_1_2_3_1` | output_mismatch | 184/186 | 186/186 |
| `ecma3/GlobalObject/e15_1_2_6` | output_mismatch | 60/62 | 62/62 |
| `ecma3/GlobalObject/e15_1_2_7` | output_mismatch | 53/55 | 55/55 |
| `ecma3/Number/e15_7_4_6_1` | output_mismatch | 1/26 | 26/26 |
| `ecma3/String/concat` | output_mismatch | 0/21 | 21/21 |
| `ecma3/String/e15_5_4_10_1_rt` | output_mismatch | 0/24 | 24/24 |
| `ecma3/String/e15_5_4_11_1` | output_mismatch | 0/387 | 387/387 |
| `ecma3/String/e15_5_4_11_5` | output_mismatch | 0/131 | 131/131 |
| `ecma3/String/e15_5_4_12_1` | output_mismatch | 0/387 | 387/387 |
| `ecma3/String/e15_5_4_13` | output_mismatch | 0/17 | 17/17 |
| `ecma3/String/e15_5_4_4_1` | output_mismatch | 188/189 | 189/189 |
| `ecma3/String/e15_5_4_4_2` | output_mismatch | 6/33 | 33/33 |
| `ecma3/String/e15_5_4_4_3` | output_mismatch | 0/18 | 18/18 |
| `ecma3/String/e15_5_4_4_4_rt` | output_mismatch | 28/52 | 52/52 |
| `ecma3/String/e15_5_4_5_2` | output_mismatch | 0/31 | 31/31 |
| `ecma3/String/e15_5_4_5_3` | output_mismatch | 0/28 | 28/28 |
| `ecma3/String/e15_5_4_5_5` | output_mismatch | 0/269 | 269/269 |
| `ecma3/String/e15_5_4_5_6_rt` | output_mismatch | 10/11 | 11/11 |
| `ecma3/String/e15_5_4_7_2` | output_mismatch | 0/72 | 72/72 |
| `ecma3/String/e15_5_4_8_1_rt` | output_mismatch | 0/30 | 30/30 |
| `ecma3/String/ematch_004` | output_mismatch | 0/8 | 8/8 |
| `ecma3/String/esplit_002` | output_mismatch | 30/94 | 94/94 |
| `ecma3/String/substr` | output_mismatch | 0/24 | 24/24 |
| `ecma3/String/toLocaleLowerCase` | output_mismatch | 0/387 | 387/387 |
| `ecma3/String/toLocaleLowerCase5` | output_mismatch | 0/131 | 131/131 |
| `ecma3/String/toLocaleUpperCase5` | output_mismatch | 0/387 | 387/387 |

## Status Changed (17)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `as3/Types/Number/e15_7_4_6_1/swf14` | output_mismatch | ruffle_matched | 1/29 | 11/29 |
| `as3/Types/Number/e15_7_4_6_1/swf15` | output_mismatch | ruffle_matched | 1/29 | 26/29 |
| `ecma3/Array/e15_4_4_5` | output_mismatch | ruffle_matched | 0/15 | 14/15 |
| `ecma3/Exceptions/number_001_rt` | output_mismatch | segfault | 0/1 | - |
| `ecma3/Exceptions/string_001_rt` | output_mismatch | segfault | 0/1 | - |
| `ecma3/Number/e15_7_4_2_1_rt` | output_mismatch | segfault | 8/9 | - |
| `ecma3/Number/e15_7_4_2_2_rt` | output_mismatch | segfault | 0/2 | - |
| `ecma3/Number/e15_7_4_3_1_rt` | output_mismatch | segfault | 6/7 | - |
| `ecma3/Number/e15_7_4__1_rt` | output_mismatch | segfault | 2/3 | - |
| `ecma3/Number/eregress_121952` | output_mismatch | ruffle_matched | 0/12 | 11/12 |
| `ecma3/Number/toLocaleString_rt` | output_mismatch | segfault | 43/48 | - |
| `ecma3/String/e15_5_2` | output_mismatch | ruffle_matched | 69/75 | 74/75 |
| `ecma3/String/e15_5_4` | output_mismatch | segfault | 3/6 | - |
| `ecma3/String/e15_5_4_2_1` | output_mismatch | segfault | 5/6 | - |
| `ecma3/String/e15_5_4_2_rt` | output_mismatch | segfault | 7/8 | - |
| `ecma3/String/e15_5_4_3_1` | output_mismatch | segfault | 6/7 | - |
| `ecma3/String/localeCompare_rt` | output_mismatch | segfault | 3/4 | - |

## Line Count Changed (11)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `ecma3/String/e15_5_4_6_2_rt` | output_mismatch | 1/232 | 229/232 | -228 |
| `as3/ByteArray/ByteArray` | output_mismatch | 382/425 | 424/425 | -42 |
| `ecma3/Expressions/e11_2_1_1` | output_mismatch | 161/254 | 183/254 | -22 |
| `ecma3/String/e15_5_4_9_1_rt` | output_mismatch | 0/22 | 21/22 | -21 |
| `ecma3/Number/e15_7_4_7_1` | ruffle_matched | 2/11 | 8/11 | -6 |
| `ecma3/JSON/adhoc` | output_mismatch | 26/40 | 30/40 | -4 |
| `ecma3/ObjectObjects/hasOwnProperty` | output_mismatch | 5/10 | 8/10 | -3 |
| `ecma3/GlobalObject/e15_1_2_4` | output_mismatch | 48/983 | 50/983 | -2 |
| `ecma3/GlobalObject/e15_1_2_5_1` | output_mismatch | 528/531 | 530/531 | -2 |
| `ecma3/JSON/e15_12_2` | output_mismatch | 10/12 | 11/12 | -1 |
| `ecma3/NativeObjects/e15_2_rt` | output_mismatch | 2/9 | 3/9 | -1 |
