# Ruffle Test Results Diff

**Previous:** `a28b3e2cbb40` (2026-07-31T14:52:54.940098+00:00)
**Current:** `b4d4457f16e2` (2026-07-31T20:03:56.688394+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1481 | 1490 | +9 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 94.1% | 94.7% | +0.6% |
| Mismatched lines | 726 | 696 | -30 |
|   Decreased | | | -30 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/Definitions/Classes/ClassDef/Bug118272Package` | output_mismatch | 0/6 | 6/6 |
| `as3/Definitions/Classes/Ext/ExtPublicClassPriv` | output_mismatch | 1/6 | 6/6 |
| `as3/Definitions/Super/SuperRuntimeError` | output_mismatch | 2/3 | 3/3 |
| `as3/Definitions/Variable/AccessPrivateClassVariable_rt` | output_mismatch | 0/1 | 1/1 |
| `as3/Expressions/QualifiedReferences/WildcardOperator` | output_mismatch | 1/3 | 3/3 |
| `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp` | output_mismatch | 0/1 | 1/1 |
| `e4x/Expressions/e11_1_1` | output_mismatch | 35/39 | 39/39 |
| `e4x/Namespace/e13_2_5` | output_mismatch | 34/36 | 36/36 |
| `e4x/QName/e13_3_2` | output_mismatch | 48/49 | 49/49 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `e4x/Expressions/e11_1_2` | output_mismatch | 12/20 | 17/20 | -5 |
| `e4x/Statements/e12_1` | output_mismatch | 11/17 | 13/17 | -2 |
| `e4x/Regress/regress-263935` | output_mismatch | 0/2 | 0/2 | 0 |
