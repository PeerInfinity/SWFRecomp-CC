# Ruffle Test Results Diff

**Previous:** `2cf4014fd672` (2026-07-24T22:06:49.333028+00:00)
**Current:** `17c19040c9cd` (2026-07-24T23:01:01.270534+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1135 | 1111 | -24 |
| Total | 1574 | 1522 | -52 |
| Pass rate | 72.1% | 73.0% | +0.9% |
| Mismatched lines | 13173 | 12815 | -358 |
|   Decreased | | | -1 |
|   Increased | | | +10 |

## Newly Passing (7)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `ecma3/Number/e15_7_4_2_1_rt` | segfault | - | 9/9 |
| `ecma3/Number/e15_7_4_3_1_rt` | segfault | - | 7/7 |
| `ecma3/Number/e15_7_4__1_rt` | segfault | - | 3/3 |
| `ecma3/Number/e15_7_4_rt` | output_mismatch | 2/3 | 3/3 |
| `ecma3/String/e15_5_4_2_1` | segfault | - | 6/6 |
| `ecma3/String/e15_5_4_2_rt` | segfault | - | 8/8 |
| `ecma3/String/e15_5_4_3_1` | segfault | - | 7/7 |

## Status Changed (6)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ecma3/Exceptions/number_001_rt` | segfault | output_mismatch | - | 0/1 |
| `ecma3/Exceptions/string_001_rt` | segfault | output_mismatch | - | 0/1 |
| `ecma3/Number/e15_7_4_2_2_rt` | segfault | output_mismatch | - | 0/2 |
| `ecma3/Number/toLocaleString_rt` | segfault | output_mismatch | - | 44/48 |
| `ecma3/String/e15_5_4` | segfault | output_mismatch | - | 5/6 |
| `ecma3/String/localeCompare_rt` | segfault | output_mismatch | - | 3/4 |

## Missing Tests — Shard Failure (52)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 31 were previously passing
- 21 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `ecma3/Unicode/uFE30_CJKCompatibilityForms` | pass | 21/21 |
| `ecma3/Unicode/uFE50_SmallFormVariants` | pass | 21/21 |
| `ecma3/Unicode/uFE70_ArabicPresentationForms_B` | pass | 21/21 |
| `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms` | pass | 21/21 |
| `ecma3/Unicode/uFFF0_Specials` | pass | 21/21 |
| `ecma3/Unicode/uc_001` | pass | 4/4 |
| `ecma3/Unicode/uc_003` | pass | 6/6 |
| `ecma3/Unicode/uc_004` | pass | 8/8 |
| `ecma3/Unicode/uc_005` | pass | 10/10 |
| `ecma3/Unicode/uc_006` | pass | 56/56 |
| `ecma3/Unicode/ucs4_bug_515947` | pass | 3/3 |
| `ecma3/Unicode/utf8count` | output_mismatch | 2/3 |
| `ecma3/instanceof/instanceof_001` | pass | 2/2 |
| `ecma3/instanceof/instanceof_002` | pass | 5/5 |
| `ecma3/instanceof/instanceof_003_rt` | pass | 2/2 |
| `ecma3/instanceof/regress_7635_rt` | pass | 3/3 |
| `misc/addNull` | pass | 40/40 |
| `misc/bug_490371` | pass | 2/2 |
| `misc/bug_508617` | runtime_error | 0/5 |
| `misc/bug_521353` | pass | 6/6 |
| `misc/bug_532806` | pass | 1/1 |
| `misc/bug_534074` | pass | 1/1 |
| `misc/bug_547583` | pass | 8/8 |
| `misc/bug_598322` | pass | 120/120 |
| `misc/denseArrayDelete` | pass | 1/1 |
| `misc/getlex_anyname` | pass | 1/1 |
| `misc/md5_t` | pass | 7/7 |
| `misc/nsunbox` | pass | 3/3 |
| `misc/superInit` | pass | 1/1 |
| `misc/unchecked` | pass | 1/1 |
| `mops/lf32` | runtime_error | 0/20 |
| `mops/lf64` | runtime_error | 0/21 |
| `mops/li16` | runtime_error | 0/26 |
| `mops/li32` | runtime_error | 0/20 |
| `mops/li8` | runtime_error | 0/46 |
| `mops/lix16` | runtime_error | 0/17 |
| `mops/lix8` | runtime_error | 0/21 |
| `mops/mops_basics` | timeout | - |
| `mops/sf32` | runtime_error | 0/26 |
| `mops/sf64` | runtime_error | 0/51 |
| `mops/si16` | runtime_error | 0/28 |
| `mops/si32` | runtime_error | 0/33 |
| `mops/si8` | runtime_error | 0/28 |
| `recursion/pcre_could_be_empty_branch` | output_mismatch | 0/1 |
| `recursion/pcre_find_firstassertedchar` | output_mismatch | 1/2 |
| `recursion/pcre_find_fixedlength` | output_mismatch | 10/20 |
| `recursion/pcre_is_anchored` | output_mismatch | 1/2 |
| `recursion/pcre_is_startline` | output_mismatch | 1/2 |
| `recursion/xml_functions` | pass | 3/3 |
| `regress/bug_415080` | pass | 1/1 |
| `regress/bug_420755` | output_mismatch | 17/27 |
| `regress/bug_424341` | pass | 1/1 |

</details>
