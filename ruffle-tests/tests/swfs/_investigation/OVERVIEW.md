# Test Suite Overview

Cross-suite summary of all Ruffle-derived test suites. Each suite has its own `_investigation/` directory with detailed status docs.

Last updated: 2026-03-18

## Suite Summary

| Suite | Tests | Passing | Rate | Filtered Rate | Notes |
|-------|-------|---------|------|---------------|-------|
| [avm1](../avm1/_investigation/CURRENT_STATUS.md) | 619 | 559 | 90.3% | **97.5%** (549/563) | Mature. Near-ceiling. |
| [from_gnash/actionscript.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 190 | 38 | **20.0%** | TBD (no ignore list yet) | 13 segfaults, 31 compile failures. Root causes identified. |
| [from_gnash/misc-swfmill.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 14 | 4 | **28.6%** | TBD | 4 compile failures. |
| [from_shumway](../from_shumway/_investigation/CURRENT_STATUS.md) | 47 | 15 | 31.9% | **88.2%** (15/17) | 30 of 32 failures are AVM2/AS3 (not applicable). |
| **SWFRecomp/tests** (old suite) | 158+59 | all trace pass | **100%** | — | Hand-written opcode tests. CI only. |

## Key Findings (2026-03-18 Investigation)

### Shumway: 88.2% effective pass rate
30 of 47 Shumway tests are AVM2/AS3 — our AVM1 recompiler cannot execute them. After filtering, only 2 AVM1 tests fail: `targetPath1` (6/8 lines, needs default MC toString) and `doubleAndRegister` (0/2, needs registerClass char_id lookup).

### Gnash: Three high-ROI fixes would dramatically improve results
1. **s16 label overflow** in recompiler — trivial type cast fix, unblocks **28 compile failures**
2. **Object.prototype SWF5 poison** — Dejagnu.swf (SWF5) init prevents hasOwnProperty installation. Single guard removal fixes **20+ tests**
3. **Child movie transform buffer overflow** — causes all **13 segfaults**

These three fixes together could push gnash from 42 passing to 80+ tests.

### Gnash tests have a version-multiplier structure
Each ActionScript class is tested across SWF versions 5-8, so a single underlying fix often resolves 3-4 tests at once. The effective number of distinct bugs is much smaller than the raw failure count.

## Per-Suite Docs

### avm1 (Ruffle)
- `avm1/_investigation/CURRENT_STATUS.md` — Current pass rates, plan status, remaining work
- `avm1/_investigation/SESSION_NOTES.md` — Historical session-by-session fix notes
- `avm1/_investigation/SESSION_START_GUIDE.md` — Architecture overview, how to run tests
- `avm1/_investigation/ACCEPTED_DIFFS.md` — Tests with permanently unfixable diffs
- `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` — Where we match Flash but not Ruffle

### from_gnash
- `from_gnash/_investigation/CURRENT_STATUS.md` — Full triage: segfault root causes, compile failure categories, near-passing diffs, recommended fix order

### from_shumway
- `from_shumway/_investigation/CURRENT_STATUS.md` — AVM1 vs AVM2 classification, 2 fixable AVM1 failures, 30 tests to ignore

## Where to Focus

1. **Gnash Phase 1 fixes** (s16 overflow + Object.prototype + transform buffer) are the highest ROI across all suites — three targeted fixes for ~40+ test improvements.
2. **Shumway ignore list** is a quick win — creating it immediately shows 88.2% effective pass rate with zero code changes.
3. **AVM1 suite** is at 97.5% filtered and remaining failures are blocked or diminishing-returns. Best to focus effort on gnash/shumway until they stabilize.
