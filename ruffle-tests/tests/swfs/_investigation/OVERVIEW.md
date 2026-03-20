# Test Suite Overview

Cross-suite summary of all Ruffle-derived test suites. Each suite has its own `_investigation/` directory with detailed status docs.

Last updated: 2026-03-19

## Suite Summary

| Suite | Tests | Passing | Rate | Filtered Rate | Notes |
|-------|-------|---------|------|---------------|-------|
| [avm1](../avm1/_investigation/CURRENT_STATUS.md) | 619 | 559 | 90.3% | **97.5%** (549/563) | Mature. Near-ceiling. |
| [from_gnash/actionscript.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 190 | 44 | **23.2%** | TBD (no ignore list yet) | 2 segfaults, 5 runtime errors, 139 output mismatch. |
| [from_gnash/misc-swfmill.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 14 | 8 | **57.1%** | TBD | 6 output mismatch. |
| [from_shumway](../from_shumway/_investigation/CURRENT_STATUS.md) | 47 | 15 | 31.9% | **88.2%** (15/17) | 30 of 32 failures are AVM2/AS3 (not applicable). |
| **SWFRecomp/tests** (old suite) | 158+59 | all trace pass | **100%** | — | Hand-written opcode tests. CI only. |

## Progress Since 2026-03-18

### Gnash: Phase 1 complete — 42 → 52 tests passing (+24%)

All Phase 1 fixes applied:
1. ~~s16 label overflow~~ — DONE (28 compile failures fixed)
2. ~~Object.prototype SWF5 guard~~ — DONE (hasOwnProperty always installed)
3. ~~Transform buffer overflow~~ — DONE (11 segfaults fixed, 2 remaining in Inheritance)
4. ~~WITH block duplicate labels~~ — DONE (4 compile failures fixed)
5. ~~ASnative class 101~~ — DONE (Object.prototype methods via ASnative)
6. ~~Color prototype unification~~ — DONE (instanceof Color works)

Line-level match improved from 60.3% → 65.0% for actionscript.all.

### Gnash: Next highest-ROI fixes identified

8 tests are >95% match (near-passing): Math-v5/v6/v7/v8 (97.8%), ops-v8 (95.8%), NetStream-v6/v7/v8 (95.0%). These need small, targeted fixes. See `from_gnash/_investigation/FAILING_TESTS_BY_FEATURE.md` for the full prioritized list.

### Shumway: Status unchanged

Still 15/17 effective AVM1 pass rate. 2 fixable AVM1 tests remain: `targetPath1` (MC toString) and `doubleAndRegister` (registerClass char_id lookup). Ignore list for 30 AVM2 tests not yet created.

## Per-Suite Docs

### avm1 (Ruffle)
- `avm1/_investigation/CURRENT_STATUS.md` — Current pass rates, plan status, remaining work
- `avm1/_investigation/SESSION_NOTES.md` — Historical session-by-session fix notes
- `avm1/_investigation/FAILING_TESTS_BY_FEATURE.md` — Failures by feature category
- `avm1/_investigation/REMAINING_FAILURES_ANALYSIS.md` — Detailed remaining failure analysis
- `avm1/_investigation/BLOCKER_SUMMARY.md` — Active and resolved blockers
- `avm1/_investigation/ACCEPTED_DIFFS.md` — Tests with permanently unfixable diffs
- `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` — Where we match Flash but not Ruffle

### from_gnash
- `from_gnash/_investigation/CURRENT_STATUS.md` — Pass rates, Phase 1/2/3 work order
- `from_gnash/_investigation/FAILING_TESTS_BY_FEATURE.md` — All 152 failures by root cause / feature
- `from_gnash/_investigation/REMAINING_FAILURES_ANALYSIS.md` — Tiered analysis with effort estimates
- `from_gnash/_investigation/BLOCKER_SUMMARY.md` — Active and resolved blockers

### from_shumway
- `from_shumway/_investigation/CURRENT_STATUS.md` — AVM1 vs AVM2 classification, pass rates
- `from_shumway/_investigation/FAILING_TESTS_BY_FEATURE.md` — 30 AVM2 tests + 2 AVM1 failures
- `from_shumway/_investigation/REMAINING_FAILURES_ANALYSIS.md` — Analysis of 2 fixable AVM1 tests + ignore list

## Where to Focus

1. **Gnash Tier 1 fixes** (Math edge cases, equality coercion, NetStream properties) — 8 near-passing tests that need trivial fixes.
2. **Shumway ignore list** — creating `ignored_tests.txt` for 30 AVM2 tests immediately shows 88.2% effective pass rate.
3. **Gnash Tier 2 fixes** (Color, Selection/Stage, Inheritance, Error) — ~25 tests at 80-95% match rate.
4. **AVM1 suite** is at 97.5% filtered and remaining failures are blocked or diminishing-returns.
