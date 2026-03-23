# Test Suite Overview

Cross-suite summary of all Ruffle-derived test suites. Each suite has its own `_investigation/` directory with detailed status docs.

Last updated: 2026-03-23 (CI run on 3b075cff)

## Suite Summary

| Suite | Tests | Passing | Rate | Filtered Rate | Notes |
|-------|-------|---------|------|---------------|-------|
| [avm1](../avm1/_investigation/CURRENT_STATUS.md) | 619 | 558 | 90.1% | **97.2%** (558/574) | Mature. Near-ceiling. |
| [from_gnash/actionscript.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 190 | 51 | 26.8% | **28.2%** (51/181) | 9 accepted-diff tests ignored. Line match 69.1%. |
| [from_gnash/misc-swfmill.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 14 | 11 | **78.6%** | — | 3 blocked on architecture. |
| [from_shumway](../from_shumway/_investigation/CURRENT_STATUS.md) | 47 | 17 | 36.2% | **100.0%** (17/17) | **Complete.** All AVM1 tests pass. 30 AVM2 ignored. |
| **SWFRecomp/tests** (old suite) | 158+59 | all trace pass | **100%** | — | Hand-written opcode tests. CI only. |

## Progress Since 2026-03-19

### Shumway: Complete — 15/17 → 17/17 (100% AVM1)

Two fixes (commit 3b075cff):
1. **targetPath1** — MC `toString()` fallback to `MovieClip.prototype` → `Object.prototype` chain
2. **doubleAndRegister** — `registerClass` char_id-based lookup for multi-export sprites

Ignore list created for 30 AVM2/AS3 tests. Suite is complete.

### Gnash: Phase 1b complete, ignore list created

Phase 1b fixes (Math, ops, Error edge cases) applied. 9 tests with all-accepted diffs (Gnash bugs) added to ignore list. Line-level match improved from 65.0% → 69.1% (unfiltered) / 66.3% (filtered).

### Gnash: Phase 2 in progress

Remaining Phase 2 items:
- **Color.getTransform() on invalid target** — should return undefined, not object (Color-v5/v6/v7/v8)
- **ASArray/ASObject cast in convertFloat** — toString_valueOf tests
- **Object.prototype.constructor** — Inheritance tests
- **Stage/Selection non-constructable** — SWF5 version gating

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
- `from_shumway/_investigation/CURRENT_STATUS.md` — **Complete** (17/17 AVM1, 30 AVM2 ignored)

## Where to Focus

1. **Gnash Phase 2 fixes** (Color, Inheritance, toString_valueOf) — targeted fixes for near-passing tests at 80-95% match rate.
2. **AVM1 suite** is at 97.2% filtered and remaining failures are blocked or diminishing-returns.
3. **Shumway** is complete (100% AVM1).
