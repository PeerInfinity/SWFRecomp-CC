# Ruffle Test Results Diff

**Previous:** `7e14f54dd961` (2026-11-23T22:39:55.370091+00:00)
**Current:** `005bea42a286` (2026-11-23T23:56:28.981208+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1533 | 1483 | -50 |
| Total | 1574 | 1521 | -53 |
| Pass rate | 97.4% | 97.5% | +0.1% |
| Mismatched lines | 428 | 406 | -22 |

## Missing Tests — Shard Failure (53)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 50 were previously passing
- 3 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatch` | pass | 2/2 |
| `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatchWithoutMatchingCatch` | pass | 1/1 |
| `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTry` | pass | 1/1 |
| `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTryWithoutMatchingCatch` | pass | 1/1 |
| `as3/Statements/Exceptions/TryCatchBlockPackage` | pass | 1/1 |
| `as3/Statements/Exceptions/TryCatchBlockPackage2` | pass | 1/1 |
| `as3/Statements/Exceptions/TryCatchBlockPackage3` | pass | 1/1 |
| `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions` | pass | 7/7 |
| `as3/Statements/Exceptions/UserDefinedErrorsInPackage` | pass | 1/1 |
| `as3/Statements/Exceptions/UserDefinedErrorsPackage` | pass | 1/1 |
| `as3/Statements/Exceptions/UserDefinedErrorsPackage2` | pass | 1/1 |
| `as3/Statements/Exceptions/UserDefinedErrorsPackage3` | pass | 1/1 |
| `as3/Statements/Exceptions/UserDefinedErrorsPackageWithoutMatchingCatch` | pass | 1/1 |
| `as3/Statements/e12_6_3_12` | pass | 1/1 |
| `as3/Statements/for-each-in/eforeachin_001` | pass | 8/8 |
| `as3/Statements/for-each-in/eforeachin_001_500476` | pass | 2/2 |
| `as3/Statements/for-each-in/eforeachin_002` | pass | 2/2 |
| `as3/Statements/switch/switch_000` | pass | 3/3 |
| `as3/Statements/switch/switch_001` | pass | 6/6 |
| `as3/Statements/switch/switch_002` | pass | 5/5 |
| `as3/Statements/switch/switch_003` | pass | 6/6 |
| `as3/String/localeCompare_585791/v12` | pass | 8/8 |
| `as3/String/localeCompare_585791/v9` | pass | 8/8 |
| `as3/Types/Conversions/ExplicitConversions` | pass | 54/54 |
| `as3/Types/Conversions/ImplicitConversions1_23` | pass | 6/6 |
| `as3/Types/Conversions/ImplicitConversionsFalse` | pass | 10/10 |
| `as3/Types/Conversions/ImplicitConversionsNaN` | pass | 6/6 |
| `as3/Types/Conversions/ImplicitConversionsNeg1_23` | pass | 10/10 |
| `as3/Types/Conversions/ImplicitConversionsNull` | pass | 10/10 |
| `as3/Types/Conversions/ImplicitConversionsString` | pass | 20/20 |
| `as3/Types/Conversions/ImplicitConversionsTrue` | pass | 10/10 |
| `as3/Types/Conversions/ImplicitConversionsUndefined` | pass | 11/11 |
| `as3/Types/Int/intConstructor` | pass | 12/12 |
| `as3/Types/Int/intIs` | pass | 12/12 |
| `as3/Types/Int/intMaxValue` | pass | 4/4 |
| `as3/Types/Int/intMinValue` | pass | 4/4 |
| `as3/Types/Int/intType` | pass | 2/2 |
| `as3/Types/Int/signed_unsigned` | pass | 6/6 |
| `as3/Types/Int/wraparound` | pass | 16/16 |
| `as3/Types/Number/abs` | pass | 41/41 |
| `as3/Types/Number/acos` | pass | 29/29 |
| `as3/Types/Number/asin` | pass | 34/34 |
| `as3/Types/Number/atan` | pass | 33/33 |
| `as3/Types/Number/atan2` | pass | 72/72 |
| `as3/Types/Number/ceil` | pass | 49/49 |
| `as3/Types/Number/cos` | ruffle_matched | 28/29 |
| `as3/Types/Number/e` | pass | 8/8 |
| `as3/Types/Number/e15_7_4_6_1/swf14` | ruffle_matched | 11/29 |
| `as3/Types/Number/e15_7_4_6_1/swf15` | ruffle_matched | 26/29 |
| `as3/Types/Number/exp` | pass | 30/30 |
| `as3/Types/Number/floor` | pass | 46/46 |
| `as3/Types/Number/ln10` | pass | 8/8 |
| `as3/Types/Number/ln2` | pass | 8/8 |

</details>
