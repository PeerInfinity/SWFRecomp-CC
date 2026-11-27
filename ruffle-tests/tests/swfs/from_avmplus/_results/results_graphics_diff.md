# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:35:22.743474+00:00)
**Current:** `2d40d37996b8` (2026-11-27T06:45:05.567875+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1564 | 1511 | -53 |
| Total | 1574 | 1521 | -53 |
| Pass rate | 99.4% | 99.3% | -0.1% |
| Mismatched lines | 43 | 43 | 0 |

## Missing Tests — Shard Failure (53)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 53 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `as3/Vector/join_initializers` | pass | 4/4 |
| `as3/Vector/lastindexof` | pass | 5/5 |
| `as3/Vector/lastindexof_initializers` | pass | 7/7 |
| `as3/Vector/length` | pass | 9/9 |
| `as3/Vector/length_initializers` | pass | 3/3 |
| `as3/Vector/map` | pass | 12/12 |
| `as3/Vector/map_initializers` | pass | 7/7 |
| `as3/Vector/nested` | pass | 8/8 |
| `as3/Vector/nested_initializers` | pass | 5/5 |
| `as3/Vector/nonindexproperty/v10` | pass | 51/51 |
| `as3/Vector/nonindexproperty/v11` | pass | 55/55 |
| `as3/Vector/optimization_tests` | pass | 14/14 |
| `as3/Vector/pop` | pass | 12/12 |
| `as3/Vector/push` | pass | 12/12 |
| `as3/Vector/put` | pass | 8/8 |
| `as3/Vector/reverse` | pass | 5/5 |
| `as3/Vector/reverse_initializers` | pass | 4/4 |
| `as3/Vector/shift` | pass | 12/12 |
| `as3/Vector/slice` | pass | 1/1 |
| `as3/Vector/slice_initializers` | pass | 5/5 |
| `as3/Vector/some` | pass | 13/13 |
| `as3/Vector/some_initializers` | pass | 6/6 |
| `as3/Vector/sort` | pass | 9/9 |
| `as3/Vector/sort_initializers` | pass | 1/1 |
| `as3/Vector/specialized_at_runtime` | pass | 3/3 |
| `as3/Vector/splice` | pass | 4/4 |
| `as3/Vector/static_initializer` | pass | 4/4 |
| `as3/Vector/tostring` | pass | 7/7 |
| `as3/Vector/tostring_initializer` | pass | 5/5 |
| `as3/Vector/typechecking` | pass | 10/10 |
| `as3/Vector/unshift` | pass | 7/7 |
| `as3/Vector/vectorIndexRangeExceptions` | pass | 1270/1270 |
| `e4x/Expressions/e11_1_1` | pass | 39/39 |
| `e4x/Expressions/e11_1_2` | pass | 20/20 |
| `e4x/Expressions/e11_1_3` | pass | 8/8 |
| `e4x/Expressions/e11_1_4` | pass | 34/34 |
| `e4x/Expressions/e11_1_5` | pass | 17/17 |
| `e4x/Expressions/e11_2_1` | pass | 40/40 |
| `e4x/Expressions/e11_2_2` | pass | 24/24 |
| `e4x/Expressions/e11_2_3` | pass | 10/10 |
| `e4x/Expressions/e11_2_4` | pass | 15/15 |
| `e4x/Expressions/e11_3_1` | pass | 20/20 |
| `e4x/Expressions/e11_3_2` | pass | 7/7 |
| `e4x/Expressions/e11_4_1` | pass | 18/18 |
| `e4x/Expressions/e11_5_1` | pass | 66/66 |
| `e4x/Expressions/e11_6_1` | pass | 19/19 |
| `e4x/Expressions/e11_6_2` | pass | 15/15 |
| `e4x/Expressions/e11_6_3` | pass | 6/6 |
| `e4x/Expressions/kXMLBadQNameErr` | pass | 5/5 |
| `e4x/Global/e13_1_2_1` | pass | 10/10 |
| `e4x/Global/isXMLNameTypeErr` | pass | 5/5 |
| `e4x/Namespace/e13_2_1` | pass | 19/19 |
| `e4x/Namespace/e13_2_2` | pass | 22/22 |

</details>
